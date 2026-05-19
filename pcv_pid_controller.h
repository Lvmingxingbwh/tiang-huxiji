#ifndef PCV_PID_CONTROLLER_H
#define PCV_PID_CONTROLLER_H

#include <stdint.h>
#include "NuMicro.h"

extern volatile int16_t Vp;

// 呼吸相位
typedef enum {
    PHASE_EXHALATION = 0, // 呼气
    PHASE_INHALATION = 1, // 吸气
    PHASE_HOLD = 2        // 屏气平台
} BreathPhase_t;

// ============================================================================
// 可调参数配置
// ============================================================================
typedef struct {
    // 吸气相 PID（增量式：Ki=油门, Kp=刹车, Kd=减震）
    float Kp_Insp;
    float Ki_Insp;
    float Kd_Insp;

    // 呼气相 PID
    float Kp_Exp;
    float Ki_Exp;
    float Kd_Exp;

    // 死区补偿（PVQ33 启动电流 50%~65%，低于此值阀门不动）
    float Insp_Deadband;  // 吸气阀死区 (%)
    float Exp_Deadband;   // 呼气阀死区 (%)

    // 前馈增益（相位切换瞬间给一个预估起跳值，加速响应）
    float FF_Insp;        // 吸气前馈
    float FF_Exp;         // 呼气前馈

    // 滤波系数（一阶低通，0.2~0.8，越小越平滑但越迟钝）
    float Filter_Alpha;
} PCV_Config_t;

// ============================================================================
// 输入 / 输出 / 状态
// ============================================================================
typedef struct {
    float Target_PIP;       // 目标吸气峰压 (cmH2O)
    float Target_PEEP;      // 目标呼气末正压 (cmH2O)
    float RR_bpm;           // 呼吸频率 (次/分)
    float IE_Ratio_E;       // 吸呼比 1:E
    float Hold_Ratio;       // 屏气占吸气时间比例 (0~1)
    float Current_Pressure; // 实时压力 (cmH2O)
    float Current_Flow;     // 实时流量 (LPM)
    float dt;               // 中断周期 (秒)
} PCV_Input_t;

typedef struct {
    // 输出 0~100%，经过死区补偿后的电流指令百分比
    // 底层换算：PWM = output / 100.0 * PWM_MAX
    float Insp_Valve_Output;  // 吸气阀 (0~100%)
    float Exp_Valve_Output;   // 呼气阀 (0~100%)
} PCV_Output_t;

typedef struct {
    // 增量式 PID 历史
    float prev_error;
    float prev_error_2;
    float last_insp_output;   // 吸气阀逻辑开度（死区映射前）
    float last_exp_output;

    // 状态机
    BreathPhase_t current_phase;
    BreathPhase_t prev_phase;
    float phase_timer;        // 当前相位已持续时间 (秒)

    // 滤波器
    float filtered_pressure;
    float filtered_flow;
    uint8_t filter_initialized;
} PCV_PID_State_t;

// ============================================================================
// 底层函数（调试用）
// ============================================================================
PCV_Config_t PCV_Config_Default(void);
void PCV_PID_Init(PCV_PID_State_t *state);
void PCV_Filter_Apply(PCV_PID_State_t *state, const PCV_Config_t *config, PCV_Input_t *input);
void PCV_PID_Update(PCV_PID_State_t *state, const PCV_Config_t *config,
                    const PCV_Input_t *input, PCV_Output_t *output);

// ============================================================================
// 顶层 API — 中断里调用这三个就行
//
//   PCV_PrepareInput(&in);        // 读传感器 + 填设定值
//   PCV_Control(&in, &out);       // 算法计算
//   PCV_OutputToHardware(&out);   // 输出到PWM
// ============================================================================
void PCV_PrepareInput(PCV_Input_t *input);
void PCV_Control(PCV_Input_t *input, PCV_Output_t *output);
void PCV_OutputToHardware(const PCV_Output_t *output);
void PCV_Reset(void); // <--- 新增的重置函数

// 滤波开关：1=开, 0=关（默认关）
void PCV_SetFilterEnabled(uint8_t enable);

#endif // PCV_PID_CONTROLLER_H
