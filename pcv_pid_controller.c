#include "pcv_pid_controller.h"

// 引入全局变量，用于读取屏幕设定的参数
extern volatile uint8_t Pcontrol;
extern volatile uint8_t setpeep;
extern volatile uint8_t freq;
// 限幅
static float clamp(float value, float min_val, float max_val) {
    if (value > max_val) return max_val;
    if (value < min_val) return min_val;
    return value;
}

// 死区跃迁映射：逻辑开度 0~100 → 跳过死区后的物理开度
// PID输出>0 时直接跳到死区以上的有效区间
static float apply_deadzone_comp(float logical_output, float deadband_pct) {
    if (logical_output < 0.5f) return 0.0f;
    return deadband_pct + (logical_output / 100.0f) * (100.0f - deadband_pct);
}

// 默认参数（基于 PVQ33-6G-23，上机后需实测微调）
PCV_Config_t PCV_Config_Default(void) {
    PCV_Config_t cfg;

    // 吸气相 PID（增量式：Ki=油门, Kp=刹车）
    cfg.Kp_Insp = 1.3f;   // 按照你的要求，改回 1.5
    cfg.Ki_Insp = 25.0f;
    cfg.Kd_Insp = 0.0f;

    // 呼气相 PID
    cfg.Kp_Exp = 5.0f;
    cfg.Ki_Exp = 1.0f;
    cfg.Kd_Exp = 0.1f;

    // 死区（恢复为 35.0f，保证起步不卡顿）
    cfg.Insp_Deadband = 35.0f;
    cfg.Exp_Deadband = 55.0f;

    // 前馈增益
    cfg.FF_Insp = 3.0f;
    cfg.FF_Exp = 2.0f;

    // 滤波（0.5 = 中等强度）
    cfg.Filter_Alpha = 0.8f;

    return cfg;
}

// 初始化
void PCV_PID_Init(PCV_PID_State_t *state) {
    state->prev_error = 0.0f;
    state->prev_error_2 = 0.0f;
    state->last_insp_output = 0.0f;
    state->last_exp_output = 0.0f;

    // 不再使用内部相位控制，保留结构体默认值
    state->current_phase = PHASE_INHALATION;
    state->prev_phase = PHASE_INHALATION;
    state->phase_timer = 0.0f;

    state->filtered_pressure = 0.0f;
    state->filtered_flow = 0.0f;
    state->filter_initialized = 0;
}

// 可选滤波（一阶低通，滤波后写回 input）
void PCV_Filter_Apply(PCV_PID_State_t *state, const PCV_Config_t *config, PCV_Input_t *input) {
    float alpha = config->Filter_Alpha;
    if (alpha < 0.05f) alpha = 0.05f;
    if (alpha > 1.0f) alpha = 1.0f;

    if (state->filter_initialized == 0) {
        state->filtered_pressure = input->Current_Pressure;
        state->filtered_flow = input->Current_Flow;
        state->filter_initialized = 1;
    } else {
        state->filtered_pressure = alpha * input->Current_Pressure + (1.0f - alpha) * state->filtered_pressure;
        state->filtered_flow = alpha * input->Current_Flow + (1.0f - alpha) * state->filtered_flow;
    }

    input->Current_Pressure = state->filtered_pressure;
    input->Current_Flow = state->filtered_flow;
}

// =============================================================================
// 核心算法（直接进行吸气相 PID 计算）
// =============================================================================
void PCV_PID_Update(PCV_PID_State_t *state, const PCV_Config_t *config,
                    const PCV_Input_t *input, PCV_Output_t *output) {
    float dt = input->dt;
    if (dt <= 0.0001f) dt = 0.005f;

    float pressure = input->Current_Pressure;
    
    // 同步应用目标偏移补偿，欺骗 PID 去追低一点的目标
    float internal_target = input->Target_PIP;
    if (internal_target > 5.0f) {
        internal_target -= 1.2f; // 按照你的要求，补偿量改为 1.2
    }
    float error = internal_target - pressure;
    float delta_u = 0.0f;

    // --- 增量式 PID + 条件积分抗饱和 ---
    float p_term = config->Kp_Insp * (error - state->prev_error);
    float i_term = config->Ki_Insp * error * dt;
    float d_term = config->Kd_Insp * (error - 2.0f * state->prev_error + state->prev_error_2) / dt;
    delta_u = p_term + i_term + d_term;

    // 抗饱和：输出饱和且误差同向时，砍掉积分项
    float new_output = state->last_insp_output + delta_u;
    if ((new_output > 100.0f && error > 0.0f) || (new_output < 0.0f && error < 0.0f)) {
        delta_u = p_term + d_term;
    }

    // 限制单步输出变化率 (Slew Rate Limiting)
    // 恢复严格的双向对称限幅，这就是保证进气“极其平滑、绝不顿挫”的定海神针！
    float max_delta = 10.0f; 

    if (delta_u > max_delta) delta_u = max_delta;
    if (delta_u < -max_delta) delta_u = -max_delta;

    // 更新内部逻辑开度
    state->last_insp_output = clamp(state->last_insp_output + delta_u, 0.0f, 100.0f);
    
    // 只计算吸气阀的最终物理开度（死区补偿后），呼气阀直接给0（由外部控制）
    output->Insp_Valve_Output = apply_deadzone_comp(state->last_insp_output, config->Insp_Deadband);
    output->Exp_Valve_Output = 0.0f;

    // 保存历史误差
    state->prev_error_2 = state->prev_error;
    state->prev_error = error;
}

// =============================================================================
// 顶层 API
// =============================================================================
static PCV_PID_State_t s_pcv_state;
static PCV_Config_t    s_pcv_config;
static uint8_t         s_initialized = 0;
static uint8_t         s_filter_on = 1;

// 一键调用（自动初始化 + 可选滤波 + PID）
void PCV_Control(PCV_Input_t *input, PCV_Output_t *output) {
    if (s_initialized == 0) {
        s_pcv_config = PCV_Config_Default();
        PCV_PID_Init(&s_pcv_state);
        s_initialized = 1;
    }
    if (s_filter_on) {
        PCV_Filter_Apply(&s_pcv_state, &s_pcv_config, input);
    }
    PCV_PID_Update(&s_pcv_state, &s_pcv_config, input, output);
}

// 滤波开关
void PCV_SetFilterEnabled(uint8_t enable) {
    s_filter_on = enable;
}

// 供外部在每次吸气开始时调用的重置函数，用于消除P项和D项的初始冲击
void PCV_Reset(void) {
    // 获取当前真实压力
    float current_pressure = (float)Vp;
    
    // 【终极黑科技：目标偏移补偿 (Target Offset)】
    // 因为气路存在不可消除的惯性，为了保留最平滑的充气波形，我们直接“欺骗”PID！
    float target = 20.0f; // 目标改为 20.0f
    float internal_target = target - 1.2f; // 同步修改为 1.2 补偿量，防止初始跳变
    
    float error = internal_target - current_pressure;
    
    // 把历史误差强行设为初始真实误差，这样第一拍进入PID计算时，
    // (error - prev_error) 就会是 0，从而避免爆发式的阀门瞬间拉满。
    s_pcv_state.prev_error = error;
    s_pcv_state.prev_error_2 = error;
    
    // 将吸气阀逻辑输出重置为0（如果你想加入一个初始的前馈跃迁，也可以在这里赋值为例如 30.0f）
    s_pcv_state.last_insp_output = 0.0f;
}

// 准备输入（← 替换为真实硬件函数）
void PCV_PrepareInput(PCV_Input_t *input) {
    input->Current_Pressure = (float)Vp;  // 从全局变量读取压力
    input->Current_Flow     = 0.0f;       // 流量传感器，如无使用保持0即可

    input->Target_PIP  = 20.0f; // 同步改为 20.0f
    input->Target_PEEP = 2.3f;  // 测试阶段，直接硬编码为 2.3f
    input->RR_bpm      = 12.0f;     // 从UI读取呼吸频率
    input->IE_Ratio_E  = 2.0f;
    input->Hold_Ratio  = 0.1f;
    input->dt          = 0.005f;          // 配合 5ms 周期，将 dt 改回 0.005秒 (5ms)
}

// 输出到硬件
#define PWM_MAX 3000  // 根据要求修改为 3000

// 此处无需定义 EPWM_SET_CMR，只要你包含了芯片库的头文件（如 NuMicro.h 等）即可编译通过
void PCV_OutputToHardware(const PCV_Output_t *output) {
    // 换算开度到 PWM 寄存器值
    uint32_t pwm_insp = (uint32_t)(output->Insp_Valve_Output / 100.0f * PWM_MAX);

    // 调用硬件外设控制，通道4，控制吸气阀
    EPWM_SET_CMR(EPWM0, 4, pwm_insp);
}
