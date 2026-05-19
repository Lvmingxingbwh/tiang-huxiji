/**************************************************************************//**
 * @file     main.c
 * @version  V3.00
 * $Revision: 9 $
 * $Date: 15/09/02 10:04a $
 * @brief    Configure EBI interface to access BS616LV4017 (SRAM) on EBI interface.
 * @note
 * Copyright (C) 2013~2015 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#include <stdio.h>
#include "NuMicro.h"
#include <string.h>
#include <stdlib.h>
#include "stdbool.h"
#include <math.h>
#include "pcv_pid_controller.h"
#define PLL_CLOCK           200000000
#define pwmx PG9
#define pwmo PG10
#define charge PC12
#define suppy  PC11
#define PDMA0_CH         2
#define PDMA1_CH         2
#define Timer0_CTL           ((uint32_t)0x40050000)
#define Timer1_CTL           ((uint32_t)0x40050100)
#define Timer2_CTL           ((uint32_t)0x40051000)
#define Timer3_CTL           ((uint32_t)0x40051100)
#define SET_Timer1_PERIOSEL   *((int32_t*)Timer1_CTL) |=TIMER_CTL_PERIOSEL_Msk
/* LCD color */
#define White          0xFFFF
#define Black          0x0000 
#define Grey           0xF7DE
#define Blue           0x001F
#define Blue1          0x0376
#define Blue2          0x051F
#define Blue3          0x2108
#define Red            0xF800
#define Navy           0x07FF
#define Magenta        0xF81F

#define Green          0x07E0
#define Green1         0x03c0
#define Cyan           0x7FFF

#define Yellow         0xFFE0

#define Grayscale1    2113
#define Grayscale2    2113*2
#define Grayscale3    2113*3
#define Grayscale4    2113*4
#define Grayscale5    2113*5
#define Grayscale6    2113*6
#define Grayscale7    2113*7
#define Grayscale8    2113*8
#define Grayscale9    2113*9
#define Grayscale10   2113*10
#define Grayscale11   2113*11
#define Grayscale12   2113*12
#define Grayscale13   2113*13
#define Grayscale14   2113*14
#define Grayscale15   2113*15
#define Grayscale16   2113*16
#define Grayscale17   2113*17
#define Grayscale18   2113*18
#define Grayscale19   2113*19
#define Grayscale20   2113*20
#define Grayscale21   2113*21
#define Grayscale22   2113*22
#define Grayscale23   2113*23
#define Grayscale24   2113*24
#define Grayscale25   2113*25
#define Grayscale26   2113*26
#define Grayscale27   2113*27
#define Grayscale28   2113*28
#define Grayscale29   2113*29
#define Grayscale30   2113*30

#define GT_CHECK_REG        0x80ff
#define GT_CTRL_REG         0x8040
#define GT_CFGS_REG         0x8047
#define GT_PID_REG          0x8140 

#define key1        PB1
#define key2        PB0
#define key3        PA11
#define key4        PA10

#define key5        PC6
#define key6        PC7
#define key7        PC8

#define  MA        PH4

#define g_pres_L         (0x000001)
#define Reset_g_pres_L   spk &= ~g_pres_L 
#define Set_g_pres_L     spk |= g_pres_L 

#define g_pres_H         (0x000002)
#define Reset_g_pres_H   spk &= ~g_pres_H
#define Set_g_pres_H     spk |= g_pres_H

#define g_VT_L          (0x000004)
#define Reset_g_VT_L     spk &= ~g_VT_L 
#define Set_g_VT_L       spk |= g_VT_L 

#define g_VT_H           (0x0008)
#define Reset_g_VT_H     spk &= ~g_VT_H 
#define Set_g_VT_H       spk |= g_VT_H 

#define g_O2_L           (0x0010)
#define Reset_g_O2_L     spk &= ~g_O2_L
#define Set_g_O2_L       spk |= g_O2_L

#define g_O2_H           (0x0020)
#define Reset_g_O2_H     spk &= ~g_O2_H 
#define Set_g_O2_H       spk |= g_O2_H 

#define g_Cpres_H         (0x0040)
#define Reset_g_Cpres_H  spk &= ~g_Cpres_H
#define Set_g_Cpres_H    spk |= g_Cpres_H

#define g_Ex_obst        (0x0080)
#define Reset_g_Ex_obst  spk &= ~g_Ex_obst
#define Set_g_EX_obst    spk |= g_Ex_obst

#define g_power_L         (0x0100)
#define Reset_g_power_L  spk & ~g_power_L
#define Set_g_power_L    spk | g_power_L

#define g_power_H         (0x0200)
#define Reset_g_power_H  spk &= ~g_power_H
#define Set_g_power_H    spk |= g_power_H

#define g_PO2_L           (0x0400)
#define Reset_g_PO2_L    spk &= ~g_PO2_L
#define Set_g_PO2_L      spk |= g_PO2_L
 
#define g_PO2_H           (0x0800)
#define Reset_g_PO2_H    spk &= ~g_PO2_H 
#define Set_g_PO2_H      spk |= g_PO2_H 

#define g_PAir_L           (0x1000)
#define Reset_g_PAir_L   spk &= ~g_PAir_L 
#define Set_g_PAir_L     spk |= g_PAir_L 

#define g_PAir_H           (0x2000)
#define Reset_g_PAir_H   spk &= ~g_PAir_H 
#define Set_g_PAir_H     spk |= g_PAir_H 

#define g_peep_H           (0x4000)
#define Reset_g_peep_H   spk &= ~g_peep_H
#define Set_g_peep_H     spk |= g_peep_H

#define g_choke            (0x8000)
#define Reset_g_choke    spk &= ~g_choke
#define Set_g_choke      spk |= g_choke

#define g_O2Err            (0x10000)
#define Reset_g_O2Err    spk &= ~g_O2Err
#define Set_g_O2Err      spk |= g_O2Err

#define g_O2a_LL           (0x020000)
#define Reset_g_O2a_LL   spk &= ~g_O2a_LL
#define Set_g_O2a_LL     spk |= g_O2a_LL

//�ֱ���
#define LCD_XSIZE_TFT    1024	
#define LCD_YSIZE_TFT    600
#define layer1_start_addr 0                                //  ͼ�����Դ��λ��
#define layer2_start_addr LCD_XSIZE_TFT*LCD_YSIZE_TFT*2    //
#define layer3_start_addr LCD_XSIZE_TFT*LCD_YSIZE_TFT*4    //
#define layer4_start_addr LCD_XSIZE_TFT*LCD_YSIZE_TFT*6    //
#define layer5_start_addr LCD_XSIZE_TFT*LCD_YSIZE_TFT*8    //
#define layer6_start_addr LCD_XSIZE_TFT*LCD_YSIZE_TFT*10    //
#define layer7_start_addr LCD_XSIZE_TFT*LCD_YSIZE_TFT*12    //

#define RTC_INIT             ((uint32_t)0x40041000)

#define PD_Schmidt      *(unsigned int*)(0x40004000+0x0E4)
#define SetPD11_Schmidt  PD_Schmidt  |= 0x00000800 
/*---------------------------------------------------------------------------------------------------------*/
/* Global Interface Variables Declarations                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
volatile uint8_t int0_ = 0,MMM,int_ror,kt,g_u8TimeoutFlag,g_u8MstRxAbortFlag,g_u8MstTxAbortFlag;
volatile uint8_t count,frist_,end_,tempX,begin,start0,start1,alarm,s,ts,s3,s4,s5,beg,sig,px,g_sys,power_s;
volatile uint16_t cx,cxbk,cy,cybk;
volatile uint32_t k,m,u32TimeOutCnt,uint32_temp;
volatile int32_t sumPair;
volatile uint8_t g_reg_H,g_reg_L,putg_reg_H,putg_reg_L,manuals,manual_fin,sigauto;
volatile uint8_t g_u8DataLen,g_u8TXLen,g_u8RXLen,year0,month0,day0,hour0,minute0,second0;
volatile uint8_t year,month,day,hour,minute,second,minutebk,adjsps,date_sps,longcon,pflash,WorkH_min;
volatile uint16_t WorkH;
volatile uint8_t g_u8DeviceAddr;
volatile uint8_t g_au8TxData[3];
volatile uint8_t g_u8EndFlag= 0,g_u8RxData;
volatile uint32_t g_u32RTCTickINT=0;
volatile uint32_t u32Sec,kc,longkey,pwmcnt,mvt,u32lq;
volatile uint8_t dateP,dateQ,spkL,spkH,spkG;
volatile uint16_t mvt0,mvt1,mvt2,mvt3,mvt4,mvt5,mvt6,kvt,uint16_temp,temp16;
volatile uint8_t data0,data1,data2,data3,data4,data5,data6,timehs,mloop,setdate,TR,sps_sy,spsd,id;
volatile uint8_t u8IsNewDateTime = 0;
volatile uint32_t g_u32AdcIntFlag,spk,spkbk,spkrom;
volatile uint32_t inspirtion_time,exspirtion_time,q,cq,ssss;
volatile uint16_t lq,lqs,pv0,pv20,pvI0,pvI20,ox21,ox100,baseV198,baseV242,baseO280,baseO600,baseA280,baseA600,printcnt,ibase,Pplatfrom10;
volatile uint16_t Vpower,Pairway,Pinsp,moxw,PSO2,PSair,pbk1,pbk2,VT_0,start_x,start_y,stop_x,stop_y,mq,nq,qout,xn,yn,yf,xr,yr,simvcp,simvst,mh;
volatile uint16_t mox,seco,count1,aseco,Color1,Color2,c3,simvcnt,base,base_s,O2_L,O2_H,O2_L_m,O2_H_m,eip,eip_m,PCVcount;
volatile uint16_t j,xxx,yyy,current,Vpd,Vpd_b,Vpd_c,Vpds_b,Vpds_bI,Vps,Vpsbk,Vps10,times,FrontPpeak,FrontPpeak1,Ppeak,peaks,peak_m,VT_L,VT_H,VT_H_m,VT_L_m,VTw,VT,VT1,VT_s; 	
volatile uint8_t tf,freq,freq_bk,freq_m,dutp,dutp_m,dut,VT_preset,VT_preset_m,O2s,keys,cn2,calipery,spker,bdut,bfreq;
volatile uint8_t ps_H,ps_H_m,ps_L,ps_L_m,seck,set0,set10,caliper,printout,minP,sample;
volatile uint8_t Pplatfrom,Paverage,peep,setpeep,setpeep_m,Pcontrol,Pcontrol_m,flow_tr,flow_tr_m,Trig_sel,fristdown;
volatile int32_t int32_temp,int32_Vp,int32_Vp10,MV,MV_L,MV_H,VTi,VTe,VTs,int32lqIns,int32lqEx,int32VtEx,int32VtIns,int32Volume,calFlow;
volatile uint8_t pwmStart,pwmEnd,pwmhl,trig,kn,modes,sig0,VMode,lsyn,intn,sps,spsbk,setb0,sighcnt,onesec,sec,setO2,Ms,psbk,ps_bk,intflg_T1,intflg_T2;
volatile uint8_t stk,g_u8Flag,clrspk,g_adct,sounda,test,Layer,keydown,chargeID,g_Batt_L,CHN_ENG,Rset0,Rset10,Rset100;
volatile uint8_t open_g,close_e,ps5,Start_,mount,mountb,pwmst,sflash,VTt,ks,kk,sighEN,sound_s,apt,cal,cal_adj,conflg,status,dateadj,frz;
volatile uint8_t freqadj,Touchcount,QC,plow,phigh,N,NegP,SYSTEM0,SYSTEM1,Lock,choke,scal_P,scal_F,scal_V,flowPos,km;
volatile int16_t M,P,bn,ix,pwmc,pwmO2Err0,pwmO2Err1,pwmO2Err2,pwmcc,max,min,PVnumber,Compliasnce,PeepErr0,PeepErr1,Err0Pcontrol,Err1Pcontrol,Err2Pcontrol;
volatile int16_t ps_tr,ps_tr_m,Vp,Vp_trough,add_sub,int16testpwmO2,int16testpeep,Err0Pplatfrom,Err1Pplatfrom,Err2Pplatfrom,Exponent,SumErr0Pplatfrom,dErr0Pplatfrom;
volatile int16_t bias,int16_temp,int16_flow,int16_flow_s,flow_trough,flows,flow_m,int16_flowDisp,int16_Volume,Volume_p,Volume_m,Volumes,int16_VolumeDisp;
volatile int16_t wave,Vp_m,Vp_mp;
volatile int16_t pwmO2,deltpwmO2, pwmAir, pwmPeep,pwmO2PCV,deltP;
S_RTC_TIME_DATA_T sWriteRTC, sReadRTC;

static uint8_t pbuf[20];
static int16_t standard[2000];
static  uint32_t g_au32DestArray[32];
typedef void (*I2C_FUNC)(uint32_t u32Status);
static I2C_FUNC s_I2C0HandlerFn = NULL;
/*---------------------------------------------------------------------------------------------------------*/
/* Define global variables and constants                                                                   */
/*---------------------------------------------------------------------------------------------------------*/

extern void LT768_Init(void); 
extern void Select_SFI_Dual_Mode0(void);
extern void LT768_PWM0_Init(uint8_t on_off,uint8_t Clock_Divided,uint8_t Prescalar,uint16_t Count_Buffer,uint16_t Compare_Buffer);
extern void LT768_PWM1_Init(uint8_t on_off,uint8_t Clock_Divided,uint8_t Prescalar,uint16_t Count_Buffer,uint16_t Compare_Buffer);
extern void Display_ON(void);
extern void Show(void);
extern void Point(uint16_t x,uint16_t y,uint16_t color);
extern void Lines(uint16_t x1 ,uint16_t y1 ,uint16_t x2,uint16_t y2,uint16_t color);
extern void Images(uint16_t x,uint16_t y,const char h[],uint16_t number,uint16_t color1,uint16_t color2); 
extern void MPU_Memory_Write_Window_8bit( uint16_t x,uint16_t y,const char g[],uint16_t number,uint16_t color1,uint16_t color2);
extern void Fills(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t color);
extern void LT768_DrawSquare(uint16_t X1,uint16_t Y1,uint16_t X2,uint16_t Y2,unsigned long ForegroundColor);
extern void LT768_DrawCircle
(
 unsigned short XCenter           // Բ��Xλ��
,unsigned short YCenter           // Բ��Yλ��
,unsigned short R                 // �뾶
,unsigned long CircleColor        // ������ɫ
);
extern void LT768_DrawCircleSquare
(
 unsigned short X1                // X1λ��
,unsigned short Y1                // Y1λ��
,unsigned short X2                // X2λ��
,unsigned short Y2                // Y2λ��
,unsigned short X_R               // ���뾶
,unsigned short Y_R               // ���뾶
,unsigned long CircleSquareColor  // ������ɫ
);
extern void LT768_DrawSquare_Fill
(
 uint16_t X1                // X1λ��
,uint16_t Y1                // Y1λ��
,uint16_t X2                // X2λ��
,uint16_t Y2                // Y2λ��
,unsigned long ForegroundColor    // ������ɫ
);
extern void LT768_DrawCircleSquare_Fill
(
 unsigned short X1                // X1λ��
,unsigned short Y1                // Y1λ��
,unsigned short X2                // X2λ��
,unsigned short Y2                // Y2λ��
,unsigned short X_R               // ���뾶
,unsigned short Y_R               // ���뾶
,unsigned long CircleSquareColor  // ������ɫ
);
extern void LT768_DrawEllipse_Fill
(
 unsigned short XCenter           // ��Բ��Xλ��
,unsigned short YCenter           // ��Բ��Yλ��
,unsigned short X_R               // ���뾶
,unsigned short Y_R               // ���뾶
,unsigned long ForegroundColor    // ������ɫ
);
extern void LT768_DrawTriangle_Fill
(
 unsigned short X1              // X1λ��
,unsigned short Y1              // Y1λ��
,unsigned short X2              // X2λ��
,unsigned short Y2              // Y2λ��
,unsigned short X3              // X3λ��
,unsigned short Y3              // Y3λ��
,unsigned long ForegroundColor  // ������ɫ
);
extern void LT768_PIP_Init
(
 unsigned char On_Off         // 0 : ��ֹ PIP    1 : ʹ�� PIP    2 : ����ԭ����״̬
,unsigned char Select_PIP     // 1 : ʹ�� PIP1   2 : ʹ�� PIP2
,unsigned long PAddr          // PIP�Ŀ�ʼ��ַ
,unsigned short XP            // PIP���ڵ�X����,���뱻4����
,unsigned short YP            // PIP���ڵ�Y����,���뱻4����
,unsigned long ImageWidth     // ��ͼ�Ŀ���
,unsigned short X_Dis         // ��ʾ���ڵ�X����
,unsigned short Y_Dis         // ��ʾ���ڵ�Y����
,unsigned short X_W           // ��ʾ���ڵĿ��ȣ����뱻4����
,unsigned short Y_H           // ��ʾ���ڵĳ��ȣ����뱻4����
);
extern void LT768_Select_Internal_Font_Init
(
 unsigned char Size         // ���������С  16��16*16     24:24*24    32:32*32
,unsigned char XxN          // ����Ŀ��ȷŴ�����1~4
,unsigned char YxN          // ����ĸ߶ȷŴ�����1~4
,unsigned char ChromaKey    // 0�����屳��ɫ͸��    1��������������ı���ɫ
,unsigned char Alignment    // 0�������岻����      1���������
);
extern void LT768_Print_Internal_Font_String
(
 unsigned short x               // ���忪ʼ��ʾ��xλ��
,unsigned short y               // ���忪ʼ��ʾ��yλ��
,unsigned long FontColor        // �������ɫ
,unsigned long BackGroundColor  // ����ı���ɫ��ע�⣺�����屳����ʼ����͸��ʱ�����ø�ֵ��Ч��
,char *c                        // ���ݻ�����׵�ַ
);
extern void LT768_PWM0_Init
(
 uint8_t on_off                       // 0����ֹPWM0    1��ʹ��PWM0
,uint8_t Clock_Divided                // PWMʱ�ӷ�Ƶ  ȡֵ��Χ 0~3(1,1/2,1/4,1/8)
,uint8_t Prescalar                    // ʱ�ӷ�Ƶ     ȡֵ��Χ 1~256
,uint16_t Count_Buffer                // ����PWM���������
,uint16_t Compare_Buffer              // ����ռ�ձ�
);
extern void LT768_DrawCircleSquare_Width
(
 unsigned short X1                // X1λ��
,unsigned short Y1                // Y1λ��
,unsigned short X2                // X2λ��
,unsigned short Y2                // Y2λ��
,unsigned short X_R               // ���뾶
,unsigned short Y_R               // ���뾶
,unsigned long CircleSquareColor  // ������ɫ
,unsigned long ForegroundColor    // ������ɫ
,unsigned short Width             // ����
);
extern void LT768_PWM0_Duty(uint16_t Compare_Buffer);
void DateRecord(void);
uint32_t uint_to_bcd(uint32_t m);
void print8(uint16_t x,uint16_t y,uint8_t *z,uint8_t len);
void prt8(uint16_t x,uint16_t y,uint8_t z);
void prt16D(uint16_t x,uint16_t y,uint16_t z);
void prt32D(uint16_t x,uint16_t y,uint32_t z);
void prt32(uint16_t x,uint16_t y,uint32_t z);
void dispdate_time(uint16_t x,uint16_t y);
void prt2D(uint16_t x,uint16_t y,uint8_t z);
void prthxd(uint16_t x,uint16_t y,uint16_t z);
void prtx(uint16_t x,uint16_t y,int16_t z);
void incr(void);
void decr(void);
void enter(void);
void show_set_VT(void);
void Silence(void);
void Manual(void);
void IPPV(void);
void a_c(void);
void sigh(void);
void simv(void);
void PCV(void);
void PSV(void);
void spont(void);
void BKV(void); 
void scale1(void);
void draw(void);
void flashes(void);
void o2a(void);
void det(void);
void alarms(uint8_t z);
void xy_(void);
void zx(void);
void init_p(void);
void Cpres_H(void);
void dispc(void);
void Plus(void);
void Record(void);
void KeyLock(void);
void Minus(void);
void Modek(void);
void SUBKset(void);
void Kenter(void);
void Compensate(void);
void srg(void);
void tgraph(uint8_t n,uint8_t adr);
void flashm(uint8_t num,uint8_t b);
void Number_enter(void);
void dispnumber(uint16_t k1,uint16_t k2,uint16_t yoffset);
void disp(uint8_t a,uint16_t x,uint16_t y);
void dispm(uint16_t a,uint16_t x,uint16_t y);
void dispdn(uint8_t a,uint16_t xn,uint16_t yn,uint8_t p);
void dispmw(uint16_t a,uint16_t x,uint16_t y);
void dispMV(uint32_t a,uint16_t xn,uint16_t yn);
void dispmword(uint8_t a,uint16_t x,uint16_t y);
void disp_limit(uint8_t a,uint16_t x,uint16_t y);
void dispVT_limit(uint16_t a,uint16_t x,uint16_t y);
void dispMV_limit(uint16_t a,uint16_t x,uint16_t y);
void dispPN(int8_t a,uint16_t x,uint16_t y);
void dispn(uint16_t x,uint16_t y,uint16_t z);
void dispVT(uint16_t a,uint16_t x,uint16_t y);
void showpra(uint8_t x);
void bbx(uint8_t x);
void eex(uint8_t x);
void compute(uint8_t freq,uint8_t dut);
bool ReadEEcon(uint16_t adr,uint16_t lenth,uint8_t *p);
uint8_t ReadEE(uint16_t adr);
void WriteEE(uint16_t adr,uint8_t dat);
void dispchar32(uint16_t k1,uint16_t k2);
void dispchar24(uint16_t k1,uint16_t k2);
void sou(void);
uint16_t Adc(uint8_t ch);
uint8_t hit(uint16_t x,uint16_t y,const uint16_t *cont);
extern void Canvas_Image_Start_address(unsigned long Addr);
extern void Disable_PIP1(void);
extern void Disable_PIP2(void);
void show_caliper(void);
int16_t calip10( uint16_t x);
void show_freq(void);
void show_ratio(void);
void show_tig_P(void);
void show_P_H(void);
void show_P_L(void);
void show_VT_H(void);
void show_VT_L(void);
void show_O2_H(void);
void show_O2_L(void);
void show_set_VT(void);
void show_setpeep(void);
void show_setO2(void);
void show_mode(void);
void frozen(void);
void Close_dut(void);
void mode1(void);
void mode2(void);
void mode3(void);
void mode4(void);
void mode5(void);
void mode6(void);
void show_date(void);
void show_set_date(void);
void dateplus(void);
void dateminus(void);
void show_hiter(void);
void show_sys(void);
void CaliplierZ(void);
void Delayus(uint16_t x);
void Delayms(uint16_t x);
void COMM(void);
void SelectErase(uint8_t layer,uint8_t loc);
bool AFM3020_RD_Reg(uint8_t *buf,uint8_t u8DataLen);
uint8_t SFM3300_WR_CMD(uint8_t u8DeviceAddr,uint16_t CMD);
uint8_t SFM3300_RD_Reg(uint8_t u8DeviceAddr,uint8_t data[],uint8_t u8DataLen);
char* Int2str(unsigned int values);
static char g[6]={0,0,0,0,0,0};
static char *Ptr=g;

const uint16_t kp=7;
const uint16_t ki=3;
const uint16_t kd=3;

const uint16_t dateRecord_x=20;
const uint16_t dateRecord_y=20;

const uint16_t datepost=580;
const uint16_t setO2_pos=510;

const uint16_t  alarm_x_pos=500;
const uint16_t  alarm_y_pos=10;

const uint16_t MODE_x_pos=10;
const uint16_t MODE_y_pos=10;

const uint16_t ps_tr_x_pos=980;
const uint16_t ps_tr_y_pos=550;

//////////////////////////////////////////
const uint16_t Ppeak_x_pos=730;
const uint16_t Ppeak_y_pos=100;
const uint16_t ps_H_x_pos=680;
const uint16_t ps_H_y_pos=90;
const uint16_t ps_L_x_pos=680;
const uint16_t ps_L_y_pos=120;

const uint16_t Pplatfrom_x_pos=930;
const uint16_t Pplatfrom_y_pos=100;

const uint16_t peep_x_pos=730;
const uint16_t peep_y_pos=190;

const uint16_t trough_x=930;
const uint16_t trough_y=550;

const uint16_t Paverage_x_pos=930;
const uint16_t Paverage_y_pos=190;

const uint16_t VTe_x_pos=715;
const uint16_t VTe_y_pos=280;

const uint16_t VTe_H_x_pos=648;
const uint16_t VTe_H_y_pos=270;
const uint16_t VTe_L_x_pos=648;
const uint16_t VTe_L_y_pos=300;

const uint16_t VTi_x_pos=900;
const uint16_t VTi_y_pos=280;

const uint16_t O2_x_pos=720;
const uint16_t O2_y_pos=370;

const uint16_t O2_H_x_pos=680;
const uint16_t O2_H_y_pos=360;
const uint16_t O2_L_x_pos=680;
const uint16_t O2_L_y_pos=390;

const uint16_t MV_x_pos=900;
const uint16_t MV_y_pos=370;

const uint16_t freq_x_pos=720;
const uint16_t freq_y_pos=460;

const uint16_t dut_x_pos=920;
const uint16_t dut_y_pos=460;

const uint16_t VTset_x_pos=700;
const uint16_t VTset_y_pos=550;

const uint16_t setpeep_x_pos=930;
const uint16_t setpeep_y_pos=550;

const uint16_t Pcontrol_x_pos=720;
const uint16_t Pcontrol_y_pos=550;

const uint16_t adj_x_pos=160;
const uint16_t adj_y_pos=30;

const uint16_t suppy_x_pos=860;
const uint16_t suppy_y_pos=10;

const uint16_t Batt_x_pos=930;
const uint16_t Batt_y_pos=10;

///////////////////////////////////////////////////////

const uint16_t  T_Lock[]= {780,0,850,80};
/* nnnnnnnnnnnnn          */

const uint16_t  T_sys[]    =  {10,440, 80,480};
const uint16_t  T_freeze[] =  {10,170, 80,210};
const uint16_t  T_Record[] =  {10,260, 80,300};

const uint16_t  T_sys_p00[]=     { 60,220,130,270};
const uint16_t  T_sys_p20[]=     { 60,300,130,370};
const uint16_t  T_sys_pI00[]=    {160,220,230,270};
const uint16_t  T_sys_pI20[]=    {160,300,230,370};
const uint16_t  T_sys_o21[]=     {260,220,330,270};
const uint16_t  T_sys_o100[]=    {260,300,330,370};

const uint16_t  T_sys_V198[]=    {360,220,430,270};
const uint16_t  T_sys_V242[]=    {360,300,430,370};
const uint16_t  T_sys_pO280[]=   {460,220,530,270};
const uint16_t  T_sys_pO600[]=   {460,300,530,370};
const uint16_t  T_sys_pA280[]=   {560,220,630,270};
const uint16_t  T_sys_pA600[]=   {560,300,630,370};

const uint16_t  T_sys_VT300[]=   {560,220,730,270};
const uint16_t  T_sys_ClrWT[]=   {560,300,730,370};
const uint16_t  T_sys_En_Ch[]=   {660,220,830,370};
const uint16_t  T_sys_quit[]=    {660,300,830,370};

/*----------------------------------------*/

const uint16_t  T_freq[]= { 20,500,148,599};
const uint16_t  T_ratio[]={180,500,276,599};
const uint16_t  T_tig_P[]={350,500,450,599};

const uint16_t  T_P_H[]={900,100,1020,124};
const uint16_t  T_P_L[]={900,140,1020,164};
	
const uint16_t  T_VT_H[]={900,210,1020,234};
const uint16_t  T_VT_L[]={900,250,1020,274};
	
const uint16_t  T_O2_H[]={900,400,1020,440};
const uint16_t  T_O2_L[]={900,450,1020,479};
	
const uint16_t  T_Preeslimit[]={680,145,799,225};
const uint16_t  T_VTset[]={230,470,330,550};

const uint16_t  T_peepset[]={380,470,480,550};
const uint16_t  T_O2set[]={490,470,590,550};

const uint16_t  T_mode[]= { 0,  0,  190, 70};	
const uint16_t  T_alarm[]={480, 0,  580, 70};

const uint16_t  T_mode1[]= { 30, 72,109,121};
const uint16_t  T_mode2[]= {160, 72,239,121};
const uint16_t  T_mode3[]= {290, 72,369,121};
const uint16_t  T_mode4[]= { 30,172,109,221};
const uint16_t  T_mode5[]= {160,172,239,221};
const uint16_t  T_mode6[]= {290,172,369,221};

const uint16_t  T_date[]=  {640,0,740,60};
const uint16_t  T_date_year[]=  {510, 90,570,130};
const uint16_t  T_date_month[]= {640, 90,700,130};
const uint16_t  T_date_day[]=   {770, 90,820,130};

const uint16_t  T_date_hour[]=  {510,150,570,190};
const uint16_t  T_date_min[]=   {640,150,700,190};
const uint16_t  T_date_sec[]=   {770,150,820,190};

const uint16_t  T_date_plus[]=  {510,230,570,270};
const uint16_t  T_date_minus[]= {640,230,700,270};
const uint16_t  T_date_enter[]= {770,230,820,270};

const uint16_t  kx=140+20,ky=68+20,tw=100,th=80,w=70,h=50;
const uint16_t  key_close[]={kx+tw*0,ky+th*0,kx+tw*0+w,ky+th*0+h};

const uint16_t  key_1[]=    {kx+tw*0,ky+th*1,kx+tw*0+w,ky+th*1+h};
const uint16_t  key_2[]=    {kx+tw*1,ky+th*1,kx+tw*1+w,ky+th*1+h};
const uint16_t  key_3[]=    {kx+tw*2,ky+th*1,kx+tw*2+w,ky+th*1+h};
const uint16_t  key_x[]=    {kx+tw*3,ky+th*1,kx+tw*3+w,ky+th*1+h};

const uint16_t  key_4[]=    {kx+tw*0,ky+th*2,kx+tw*0+w,ky+th*2+h};
const uint16_t  key_5[]=    {kx+tw*1,ky+th*2,kx+tw*1+w,ky+th*2+h};
const uint16_t  key_6[]=    {kx+tw*2,ky+th*2,kx+tw*2+w,ky+th*2+h};
const uint16_t  key_enter[]={kx+tw*3,ky+th*2,kx+tw*3+w,ky+th*2+h};

const uint16_t  key_7[]=    {kx+tw*0,ky+th*3,kx+tw*0+w,ky+th*3+h};
const uint16_t  key_8[]=    {kx+tw*1,ky+th*3,kx+tw*1+w,ky+th*3+h};
const uint16_t  key_9[]=    {kx+tw*2,ky+th*3,kx+tw*2+w,ky+th*3+h};
const uint16_t  key_0[]=    {kx+tw*3,ky+th*3,kx+90*3+w,ky+th*3+h};


const uint16_t  T_IdE_4P1[]={kx+tw*0,ky+70*0,kx+tw*0+w,ky+70*0+h};
const uint16_t  T_IdE_3P1[]={kx+tw*1,ky+70*0,kx+tw*1+w,ky+70*0+h};
const uint16_t  T_IdE_2P1[]={kx+tw*2,ky+70*0,kx+tw*2+w,ky+70*0+h};
const uint16_t  T_IdE_3P2[]={kx+tw*3,ky+70*0,kx+tw*3+w,ky+70*0+h};

const uint16_t  T_IdE_1P1[]={kx+tw*0,ky+th*1,kx+tw*0+w,ky+th*1+h};
const uint16_t  T_IdE_2P3[]={kx+tw*1,ky+th*1,kx+tw*1+w,ky+th*1+h};
const uint16_t  T_IdE_1P2[]={kx+tw*2,ky+th*1,kx+tw*2+w,ky+th*1+h};
const uint16_t  T_IdE_1P3[]={kx+tw*3,ky+th*1,kx+tw*3+w,ky+th*1+h};

const uint16_t  T_IdE_1P4[]={kx+tw*0,ky+th*2,kx+tw*0+w,ky+th*2+h};
const uint16_t  T_IdE_1P5[]={kx+tw*1,ky+th*2,kx+tw*1+w,ky+th*2+h};
const uint16_t  T_IdE_1P6[]={kx+tw*2,ky+th*2,kx+tw*2+w,ky+th*2+h};
const uint16_t  T_IdE_1P7[]={kx+tw*3,ky+th*2,kx+tw*3+w,ky+th*2+h};

const uint16_t  T_IdE_1P8[]={kx+tw*0,ky+th*3,kx+tw*0+w,ky+th*3+h};
const uint16_t  T_IdE_1P9[]={kx+tw*1,ky+th*3,kx+tw*1+w,ky+th*3+h};

const uint16_t  T_RecodPlus[]= {580,110,650,150};
const uint16_t  T_RecodMinus[]={580,300,650,380};

const uint16_t xs0=20;
const uint16_t ys0=20;

const char cur[]={2,1,0x7f,0xfe,};

const uint8_t adress_cur[]={0,0,3,6,9,12,15,};

const uint16_t pwmBaseO2=1200;
const uint16_t pwmBaseAir=1200;
const uint16_t pwmBasePeep=2000;

const uint16_t tabm[]={
      	0,  0,   
       20,420,     170,420,    330,420, 
       
      640,100, 
      640,136, 
      
      620,210,//  
      620,250,  
      
      640,415,   
      640,450,
      
      480,415,
      
      620,450,
      240,170,  370,170,
      
      
       40,374,   40,454,      //14
      130,374,  130,454,
      220,374,  220,454,
      310,374,  310,454,
      400,374,  400,454,
      490,374,  490,454,
      580,374,  580,454,
      
       40,374,   40,454,      //28
      130,374,  130,454,
      220,374,  220,454,
      310,374,  310,454,
      400,374,  400,454,
      490,374,  490,454,
      580,374,  580,454,
			
};

void pwmt(void)	
 { 	
	 if (alarm==1 && begin==0) begin=1,s4=1,s=1,start1=1;
	 if (alarm==2 && begin==0) begin=1,s4=2,s=1,start1=1;
	 if (alarm==0 && begin==0)  s4=0,s=0;
   wave=662;
}				 
/**
 * @brief       PWM0 IRQ Handler
 *
 * @param       None
 *
 * @return      None
 *
 * @details     ISR to handle PWM0 interrupt event
 */
void EPWM0P1_IRQHandler(void)
{      
	 pwmt();
    // Update PWMA channel 2 period and duty  
        EPWM_SET_CNR(EPWM0, 2, 1324);
        EPWM_SET_CMR(EPWM0, 2, wave);
   
     // Clear channel 2 period interrupt flag
        EPWM_ClearPeriodIntFlag(EPWM0, 2);
		    GPIO_TOGGLE(PA6); 
}

/**
 * @brief       External PA8,PA12
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The External PA8,PA12
 */

void GPA_IRQHandler(void)
{ //uint16_t delayk=2000;
  volatile uint32_t u32temp;  
  if(GPIO_GET_INT_FLAG(PA, BIT12)) /* To check if PA.12 interrupt occurred */
	  {
		  GPIO_CLR_INT_FLAG(PA, BIT12);   
		  int0_=1;
	  }
		
	else if(GPIO_GET_INT_FLAG(PA, BIT8))/* To check if PA.8 interrupt occurred */	
	   {
      GPIO_CLR_INT_FLAG(PA,BIT8);  /* For PA.8, clear the INT flag */
	    //while(delayk--);
			if (PA9) add_sub=1;
      else add_sub=-1;	    			
	    int_ror=1;
	  }	
  else 
	  {
        /* Un-expected interrupt. Just clear all PB interrupts */
        u32temp = PB->INTSRC;
        PB->INTSRC = u32temp;
    }	
}
/**
 * @brief       IRQ Handler for RTC Interrupt
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The RTC_IRQHandler is default IRQ of RTC, declared in startup_M451Series.s.
 */
void RTC_IRQHandler(void)
{
    /* To check if RTC tick interrupt occurred */
    if(RTC_GET_TICK_INT_FLAG() == 1)
    {
        /* Clear RTC tick interrupt flag */
        RTC_CLEAR_TICK_INT_FLAG();
        g_u32RTCTickINT=1;
    }
}

/**
 * @brief       Timer0 IRQ
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The Timer0 default IRQ, declared in startup_M0564.s.
 */
void TMR0_IRQHandler(void)
{ 
	PA6=1;
	if(TIMER_GetIntFlag(TIMER0) == 1)
		  {
        /* Clear Timer0 time-out interrupt flag */
        TIMER_ClearIntFlag(TIMER0);
				//intflg_T0=1;
	 	  }		
	stk++;
	id=1;
	if (stk>7) stk=0;//stk=stk & 0x07;     5ms*8=40ms  (200Hz,5ms)       	
  /* Get the conversion result of the sample module */		
	if (stk==0) Pairway = Adc(0);
	if (stk==1) Vpower  = Adc(1);
	if (stk==2) moxw    = Adc(2);
  if (stk==3) Pinsp   = Adc(3);
  if (stk==4) PSO2    = Adc(4);
  if (stk==5) PSair   = Adc(5);
  if (stk==6) pbk1    = Adc(6);
  if (stk==7) pbk2    = Adc(7);
	if (stk==0 ||stk==4)
     {
		  SFM3300_RD_Reg(0x40,pbuf,3);
			uint16_temp=pbuf[0]<<8 | pbuf[1]; 
	    int16_temp=uint16_temp-32768; 
	    int16_flow =int16_temp/10;
			int32Volume +=int16_flow;  
			 if (pwmhl)
		    {
					if (int16_flow>=0)  int32lqIns +=int16_flow;	 
				}
			else
			  {
				  if (int16_flow<=0)   int32lqEx +=int16_flow;
				}				
		 }		
  if (stk==0) 
     { PB2 ^=1;		 						    
			setb0++;
		  setb0 &= 0x03;
			if (setb0==0) km=1;
	    sound_s=1;       	
	    g_adct=1;
			 
	    if (seco<2420)  seco++;
	    if (onesec<250) onesec++;
	    sec++;
		  //AFM3020_RD_Reg(pbuf,3);
      if (sec>kn)
	       {
	        if (sflash==0) sflash=1;
	        else sflash=0;
          ks=1;
          sec=0;
         }
			if (seck>15)
	       {
		      if (pflash==0) pflash=1;
		      else pflash=0;
          kk=1;
          seck=0;
         }
      seck++;
      // 注意：原本的 PID 调用已被移到了 if(stk==0) 之外！
      if (VTt)  mvt0 += VT_s,VTt=0;
      if (pwmst) data0++,pwmst=0;
      if (timehs>249) 
		     {
		      timehs=0;
          data1=data2;
          data2=data3;
          data3=data4;
          data4=data5;
          data5=data6;
          data6=data0;
          data0=0;
          tf=data1+data2+data3+data4+data5+data6;
		  		if (tf>99) tf=99;
          mvt1=mvt2;
          mvt2=mvt3;
          mvt3=mvt4;
          mvt4=mvt5;
          mvt5=mvt6;
          mvt6=mvt0;
          mvt0=0;
          mvt=mvt1+mvt2+mvt3+mvt4+mvt5+mvt6;
          if (mvt>99900) mvt=99900;
		     }
			   timehs++;
         simvcnt++;
       sumPair +=Vp;    					
	  } // if (stk==0) 结束
	  
	  // ==========================================
	  // 新的 5ms PID 执行区 (每次 TMR0 中断都会执行)
	  // ==========================================
	  if (pwmhl)
	  {
          // 每次 5ms 实时采最新的真实压力，并换算为物理量 cmH2O
          uint16_t current_adc = Adc(0);
          int32_t temp_vp = (current_adc - pv0) * 100 / (pv20 - pv0);
          Vp = temp_vp / 5;

	      PCV_Input_t in;
	      PCV_Output_t out;
	      
	      PCV_PrepareInput(&in);
	      PCV_Control(&in, &out);
	      PCV_OutputToHardware(&out);
	  }

    PA6=0;		 
}
/*
 * @brief       Timer1 IRQ
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The Timer1 default IRQ, declared in startup_M0564.s.
 */
void TMR1_IRQHandler(void)
{
  uint32_t u32Value;
    if(TIMER_GetIntFlag(TIMER1) == 1)
		  {
        /* Clear Timer1 time-out interrupt flag */
        TIMER_ClearIntFlag(TIMER1);
        intflg_T1=1;				
	 	  }	
		if (pwmhl)			
		  {
       close_e=1;				
		   PG4=0,pwmhl=0;
       pwmEnd=1;				
		   u32Value=exspirtion_time;
       if (u32Value<2) u32Value=2;				
			 TIMER_SET_CMP_VALUE(TIMER1, u32Value);
			 EPWM_SET_CMR(EPWM0, 0, pwmPeep);
			 EPWM_SET_CMR(EPWM0, 1, pwmBaseAir); 
       EPWM_SET_CMR(EPWM0, 4, pwmBaseO2);	
			 Pplatfrom10=Vps10;
       Pplatfrom=(Pplatfrom10+5)/10;				
		  }
		else
		 { 
		  PG4=1,pwmhl=1;
		  sighcnt++;
		  pwmcnt=0;
			FrontPpeak1=0; 
			PVnumber=0; 
		  if (sighcnt>59) sighcnt=0;
		  if (sighEN && sighcnt==3) u32Value=inspirtion_time+inspirtion_time;
		  else u32Value=inspirtion_time;
			if (u32Value<2) u32Value=2; 
		  TIMER_SET_CMP_VALUE(TIMER1, u32Value);
			 
		  EPWM_SET_CMR(EPWM0, 0, pwmBasePeep);
          // 【核心修复】：彻底屏蔽开环的 Air 和 O2 阀门强制输出！
          // 防止水龙头B一直在漏气，导致 PID(水龙头A) 关死了压力还是狂飙
		  // EPWM_SET_CMR(EPWM0, 1, pwmAir); 
          // if (VMode != 5) {
          //     EPWM_SET_CMR(EPWM0, 4, pwmO2);
          // }
			EPWM_EnableOutput(EPWM0, EPWM_CH_0_MASK);
			EPWM_EnableOutput(EPWM0, EPWM_CH_4_MASK);	
							 	
      pwmStart=1; 				 		 
			int32VtIns=int32lqIns*5/18, int32lqIns=0;
			int32VtEx=int32lqEx*5/18, int32lqEx=0;	 
			open_g=1;
			pwmst=1;
      int32Volume=0;		 
			simvcnt=0;
			pwmO2Err1=0;
      peep=Vps;
      Paverage=sumPair*freq/1500,sumPair=0;
			PCV_Reset(); // 每次进入吸气相时重置PID误差，防止起跳过冲
      	 
		}    		 
}

/**
 * @brief       Timer2 IRQ
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The Timer2 default IRQ, declared in startup_M463.
 */
void TMR2_IRQHandler(void)
{
    if(TIMER_GetIntFlag(TIMER2) == 1)
    {
        /* Clear Timer2 time-out interrupt flag */
        TIMER_ClearIntFlag(TIMER2);
			  intflg_T2=1;
    }
}
/*---------------------------------------------------------------------------------------------------------*/
/* ISR to handle UART Channel 1 interrupt event                                                            */
/*---------------------------------------------------------------------------------------------------------*/
void UART1_IRQHandler(void)
{
    volatile uint32_t u32IntSts = UART1->INTSTS;

    /* Rx Ready */
    if(UART_GET_INT_FLAG(UART1, UART_INTSTS_RDAINT_Msk ))
    {
    /* Read data */        
    keys=UART_READ(UART1);
			
    }
}
/*---------------------------------------------------------------------------------------------------------*/
/*  I2C0 IRQ Handler                                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
void I2C0_IRQHandler(void)
{
    uint32_t u32Status;

    u32Status = I2C_GET_STATUS(I2C0);
    if(I2C_GET_TIMEOUT_FLAG(I2C0))
      {
        /* Clear I2C0 Timeout Flag */
        I2C_ClearTimeoutFlag(I2C0);
				g_u8TimeoutFlag = 1;
      }
    else
      {
        if(s_I2C0HandlerFn != NULL)
        s_I2C0HandlerFn(u32Status);
      }
}

/*---------------------------------------------------------------------------------------------------------*/
/*  I2C Rx Callback Function                                                                               */
/*---------------------------------------------------------------------------------------------------------*/
void I2C_MasterRx(uint32_t u32Status)
{  
    if(u32Status == 0x08)                       /* START has been transmitted and prepare SLA+W */
      {
        I2C_SET_DATA(I2C0, (g_u8DeviceAddr << 1));    /* Write SLA+W to Register I2CDAT */
        I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI);
      }
    else if(u32Status == 0x18)                  /* SLA+W has been transmitted and ACK has been received */
      {
        I2C_SET_DATA(I2C0, g_au8TxData[g_u8DataLen++]);
        I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI);
      }
    else if(u32Status == 0x20)                  /* SLA+W has been transmitted and NACK has been received */
      {
        I2C_STOP(I2C0);
        I2C_START(I2C0);
      }
    else if(u32Status == 0x28)                  /* DATA has been transmitted and ACK has been received */
      {
        if(g_u8DataLen != 2)
         {
            I2C_SET_DATA(I2C0, g_au8TxData[g_u8DataLen++]);
            I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI);
         }
        else
         {
            I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STA_SI);
         }
      }
    else if(u32Status == 0x10)                  /* Repeat START has been transmitted and prepare SLA+R */
      {
        I2C_SET_DATA(I2C0, ((g_u8DeviceAddr << 1) | 0x01));   /* Write SLA+R to Register I2CDAT */
        I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI);
      }
    else if(u32Status == 0x40)                  /* SLA+R has been transmitted and ACK has been received */
       {
        I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI);
       }
		
    else if(u32Status == 0x58)                  /* DATA has been received and NACK has been returned */
      {
        g_u8RxData = (unsigned char) I2C_GET_DATA(I2C0);
        I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STO_SI);
        g_u8EndFlag = 1;
      }
    
}

/*---------------------------------------------------------------------------------------------------------*/
/*  I2C Tx Callback Function                                                                               */
/*---------------------------------------------------------------------------------------------------------*/
void I2C_MasterTx(uint32_t u32Status)
{
    if(u32Status == 0x08)                       /* START has been transmitted */
    {
        I2C_SET_DATA(I2C0, g_u8DeviceAddr << 1);    /* Write SLA+W to Register I2CDAT */
        I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI);
    }
    else if(u32Status == 0x18)                  /* SLA+W has been transmitted and ACK has been received */
    {
        I2C_SET_DATA(I2C0, g_au8TxData[g_u8DataLen++]);
        I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI);
    }
    else if(u32Status == 0x20)                  /* SLA+W has been transmitted and NACK has been received */
    {
        I2C_STOP(I2C0);
        I2C_START(I2C0);
    }
    else if(u32Status == 0x28)                  /* DATA has been transmitted and ACK has been received */
    {
        if(g_u8DataLen != 3)
        {
            I2C_SET_DATA(I2C0, g_au8TxData[g_u8DataLen++]);
            I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI);
        }
        else
        {
            I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STO_SI);
            g_u8EndFlag = 1;
        }
    }
   
}
/*---------------------------------------------*/
bool ReadEEcon(uint16_t adr,uint16_t lenth,uint8_t *p)
{ 
	uint8_t j;
  g_u8DeviceAddr =0x50;
	g_au8TxData[0] = (uint8_t)((adr & 0xFF00) >> 8);
  g_au8TxData[1] = (uint8_t)(adr & 0x00FF);
	      /* I2C as master sends START signal */
     I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STA);
	   I2C_WAIT_READY(I2C0);
	   if (I2C_GET_STATUS(I2C0) != 0x08) return false;     /* START has been transmitted */     
     I2C_SET_DATA(I2C0, g_u8DeviceAddr);                 /* Write SLA+R to Register I2CDAT */
     I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI);
	   I2C_WAIT_READY(I2C0);	
     if (I2C_GET_STATUS(I2C0) != 0x18) return false;     /* SLA+R has been transmitted and ACK has been received */
     I2C_SET_DATA(I2C0, g_au8TxData[0]);                 /* Read Register I2CDAT */
     I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STA);
	   I2C_WAIT_READY(I2C0);
	   if (I2C_GET_STATUS(I2C0) != 0x20)  return false;               
     I2C_STOP(I2C0);
     I2C_START(I2C0);
		 I2C_WAIT_READY(I2C0);
	   if (I2C_GET_STATUS(I2C0) != 0x28)  return false;	   
     I2C_SET_DATA(I2C0, g_au8TxData[1]);
     I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI);
     I2C_WAIT_READY(I2C0);
	   if (I2C_GET_STATUS(I2C0) != 0x28)  return false;
     I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STA_SI);
     I2C_WAIT_READY(I2C0);
     if (I2C_GET_STATUS(I2C0) != 0x10) return false;     /* Repeat START has been transmitted */			 
		 //Delay_us(100);
     for (j=0; j<lenth;j++)
      {   
        if (j==lenth-1) 
				  { 
						I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI);         /*dummy read - we need Nack! */
						I2C_WAIT_READY(I2C0);
						if(I2C_GET_STATUS(I2C0) != 0x58) return false; /* DATA has been received and NACK has been returned */             
						*(p+j) =I2C_GET_DATA(I2C0);
					}	
        else  
				  { 
						I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI_AA);
				    I2C_WAIT_READY(I2C0);
				    if(I2C_GET_STATUS(I2C0) != 0x50) return false; /* DATA has been received and ACK has been returned */
             
            *(p+j) =I2C_GET_DATA(I2C0);
				  }
      }
     I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STO_SI);
     while (I2C_GET_STATUS(I2C0) !=0xF8);
		 return true;	
}
/*---------------------------------------------*/
uint8_t ReadEE(uint16_t adr)
{ 
	g_u8DataLen = 0;
	g_u8EndFlag = 0;
  g_u8DeviceAddr =0x50;
	g_au8TxData[0] = (uint8_t)((adr & 0xFF00) >> 8);
  g_au8TxData[1] = (uint8_t)(adr & 0x00FF);
	/* I2C function to read data from slave */
  s_I2C0HandlerFn = (I2C_FUNC)I2C_MasterRx;
	
  I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STA);

  /* Wait I2C Rx Finish */
  while(g_u8EndFlag == 0);
	g_u8RxData = (unsigned char) I2C_GET_DATA(I2C0);
	return(g_u8RxData);
}
/*---------------------------------------------*/
void WriteEE(uint16_t adr,uint8_t dat)	
{
	g_u8DataLen = 0;
  g_u8EndFlag = 0;
	g_u8DeviceAddr =0x50;
	g_au8TxData[0] = (uint8_t)((adr & 0xFF00) >> 8);
  g_au8TxData[1] = (uint8_t)( adr & 0x00FF);
  g_au8TxData[2] = dat;

  /* I2C function to write data to slave */
  s_I2C0HandlerFn = (I2C_FUNC)I2C_MasterTx;

  /* I2C as master sends START signal */
  I2C_SET_CONTROL_REG(I2C0, I2C_CTL_STA);

  /* Wait I2C Tx Finish */
   while(g_u8EndFlag == 0);
   g_u8EndFlag = 0;
	Delayus(500);
}	
/*---------------------------------------------------------------------------------------------------------*/
/* Global Interface Variables Declarations                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
#include "graph.c"

void Configure_EBI_16BIT_Pins(void)
{
    /* Set multi-function pin for EBI */
		/* AD0 ~ AD15*/
    SET_EBI_AD0_PC0();
    SET_EBI_AD1_PC1();
    SET_EBI_AD2_PC2();
    SET_EBI_AD3_PC3();
    SET_EBI_AD4_PC4();
    SET_EBI_AD5_PC5();
    SET_EBI_AD6_PD8();
    SET_EBI_AD7_PD9();
    SET_EBI_AD8_PE14();
    SET_EBI_AD9_PE15();
    SET_EBI_AD10_PE1();
    SET_EBI_AD11_PE0();
    SET_EBI_AD12_PH8();
    SET_EBI_AD13_PH9();
    SET_EBI_AD14_PH10();
    SET_EBI_AD15_PH11();

    /* ADDR1 */ 
    SET_EBI_ADR1_PH6();
    /* EBI nWR and nRD pins on PE.4 and PE.5*/
    SET_EBI_nWR_PE4();
    SET_EBI_nRD_PE5();

    /* EBI nCS0 pin on PF.3 */
    SET_EBI_nCS0_PF3();
}

/*---------------------------------------------------------------------------------------------------------*/
void Delayus(uint16_t x)
{
 while(x--)
 { 
	 CLK_SysTickDelay(1);
 }	 
}
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void Delayms(uint16_t x)
{
 while(x--)
 { 
	 CLK_SysTickDelay(1000);
 }	 
}
/*---------------------------------------------------------------------------------------------------------*/
/* EADC interrupt handler                                                                                  */
/*---------------------------------------------------------------------------------------------------------*/
void EADC00_IRQHandler(void)
{  g_u32AdcIntFlag = 1;
   EADC_CLR_INT_FLAG(EADC0, 0x1);      /* Clear the A/D ADINT0 interrupt flag */
	 //GPIO_TOGGLE(PD4);
}
/*-----------------------*/
uint16_t Adc(uint8_t ch)
{ 
	uint16_t x;
	EADC_START_CONV(EADC0,0x1<<(4+ch));
	/* Wait EADC interrupt (g_u32AdcIntFlag will be set at IRQ_Handler function) */
  while(EADC_GET_INT_FLAG(EADC0, 0x1) == 0);
	x=EADC_GET_CONV_DATA(EADC0, 4+ch);
  /* Reset the EADC interrupt indicator */
  EADC_CLR_INT_FLAG(EADC0, 0x1);
return x;	
}	
/*---------------------------------------------------------------------------------------------------------*/
void calip(void)
{
	
	
}

/*---------------------------------------------------------------------------------------------------------*/

void UART0_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Reset UART module */
    SYS_ResetModule(UART0_RST);

    /* Configure UART0 and set UART0 Baudrate */
    UART_Open(UART0, 38400);
}

void UART1_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART1                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Reset UART module */
    SYS_ResetModule(UART1_RST);

    /* Configure UART1 and set UART1 Baudrate */
    UART_Open(UART1, 38400);	  
}

void I2C0_Init(void)
{
    /* Open I2C0 module and set bus clock */
    I2C_Open(I2C0, 100000);
    
    /* Enable I2C interrupt */
    I2C_EnableInt(I2C0);
    NVIC_EnableIRQ(I2C0_IRQn);
}
void I2C1_Init(void)
{
	/* Open I2C1 module and set bus clock */
    I2C_Open(I2C1, 100000);
}	
void SPI_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init SPI                                                                                                */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Configure as a master, clock idle low, 32-bit transaction, drive output on falling clock edge and latch input on rising edge. */
    /* Set IP clock divider. SPI clock rate = 2MHz */
    SPI_Open(SPI0, SPI_MASTER, SPI_MODE_0, 32, 2000000);

    /* Enable the automatic hardware slave select function. Select the SS pin and configure as low-active. */
    SPI_EnableAutoSS(SPI0, SPI_SS, SPI_SS_ACTIVE_LOW);
}

/*---------------------------------------------------------------------------------------------------------*/
void EPWM_Init()
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init PWM0                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
		pwmPeep=80;
    EPWM_SET_PRESCALER(EPWM0, 0, 0);
    EPWM_SET_CMR(EPWM0, 0, pwmPeep);
    EPWM_SET_CNR(EPWM0, 0, 3000);
		/* Set output level at zero, compare up, period(center) and compare down of specified channel */
    EPWM_SET_OUTPUT_LEVEL(EPWM0, EPWM_CH_0_MASK, EPWM_OUTPUT_HIGH, EPWM_OUTPUT_LOW, EPWM_OUTPUT_NOTHING, EPWM_OUTPUT_NOTHING);
		//EPWM_EnableOutput(EPWM0, EPWM_CH_0_MASK);
	  pwmAir=800;
		EPWM_SET_PRESCALER(EPWM0, 1, 0);
    EPWM_SET_CMR(EPWM0, 1, pwmAir);
    EPWM_SET_CNR(EPWM0, 1, 3000);
		/* Set output level at zero, compare up, period(center) and compare down of specified channel */
    EPWM_SET_OUTPUT_LEVEL(EPWM0, EPWM_CH_1_MASK, EPWM_OUTPUT_HIGH, EPWM_OUTPUT_LOW, EPWM_OUTPUT_NOTHING, EPWM_OUTPUT_NOTHING);
		EPWM_EnableOutput(EPWM0, EPWM_CH_1_MASK);
    pwmO2=1300;
		EPWM_SET_PRESCALER(EPWM0, 4, 0);
    EPWM_SET_CMR(EPWM0, 4, pwmO2);
    EPWM_SET_CNR(EPWM0, 4, 3000);
		/* Set output level at zero, compare up, period(center) and compare down of specified channel */
    EPWM_SET_OUTPUT_LEVEL(EPWM0, EPWM_CH_4_MASK, EPWM_OUTPUT_HIGH, EPWM_OUTPUT_LOW, EPWM_OUTPUT_NOTHING, EPWM_OUTPUT_NOTHING);
		//EPWM_EnableOutput(EPWM0, EPWM_CH_4_MASK);
		
		EPWM_SET_PRESCALER(EPWM0, 5, 10);
    EPWM_SET_CMR(EPWM0, 5, pwmcc);
    EPWM_SET_CNR(EPWM0, 5, 2000);
		/* Set output level at zero, compare up, period(center) and compare down of specified channel */
    EPWM_SET_OUTPUT_LEVEL(EPWM0, EPWM_CH_5_MASK, EPWM_OUTPUT_HIGH, EPWM_OUTPUT_LOW, EPWM_OUTPUT_NOTHING, EPWM_OUTPUT_NOTHING);
		EPWM_EnableOutput(EPWM0, EPWM_CH_5_MASK);
		
		EPWM_ConfigOutputChannel(EPWM0, 2, 16000, 50),
		EPWM_SET_PRESCALER(EPWM0, 2, 3);
    EPWM_SET_CMR(EPWM0, 2, 662);
    EPWM_SET_CNR(EPWM0, 2, 1324);
		/* Set output level at zero, compare up, period(center) and compare down of specified channel */
    EPWM_SET_OUTPUT_LEVEL(EPWM0, EPWM_CH_2_MASK, EPWM_OUTPUT_HIGH, EPWM_OUTPUT_LOW, EPWM_OUTPUT_NOTHING, EPWM_OUTPUT_NOTHING);
		/* Enable output of PWM0 channel 2 */
    EPWM_EnableOutput(EPWM0, EPWM_CH_2_MASK);
}

//********************************************************** 
//????:Calc_CRC8 
//?? :CRC8 ??,??:0x00,???:0x131(x8 + x5 + x4 +1 ) 
//?? :u8 *data:CRC ??????;u8 Num:CRC ?????? 
//?? :crc:???? crc8 ?? 
//********************************************************** 
uint8_t Calc_CRC8(uint8_t *data, uint8_t Num,uint8_t intial) 
{ uint8_t bit,byte,crc;
	crc=intial;
	for(byte=0; byte<Num; byte++)
	{ 
		crc^=(data[byte]);
    for(bit=8;bit>0;--bit) 
       {
				 if (crc&0x80) crc=(crc<<1)^0x31;
	       else crc=(crc<<1);
       }
  }
  return crc;
}
//////////////////////////////////////////////////////////////////////
uint8_t SFM3300_WR_CMD(uint8_t u8DeviceAddr,uint16_t CMD) 	
{  uint8_t u8Xfering = 1u, u8Err = 0u, u8Ctrl = 0u,HL=0;
    uint32_t u32TimeOutCount = 0u;

    g_I2C_i32ErrCode = 0;

    I2C_START(I2C1);
    while(u8Xfering && (u8Err == 0u))
    {
        u32TimeOutCount = I2C_TIMEOUT;
        I2C_WAIT_READY(I2C1)
        {
            if(--u32TimeOutCount == 0)
            {
                g_I2C_i32ErrCode = I2C_ERR_TIMEOUT;
                u8Err = 1u;
                break;
            }
        }
        switch(I2C_GET_STATUS(I2C1))
        {
        case 0x08u:
            I2C_SET_DATA(I2C1, (uint8_t)(u8DeviceAddr << 1u | 0x00u));    /* Write SLA+W to Register I2CDAT */
            u8Ctrl = I2C_CTL_SI;                              /* Clear SI */
            break;
        case 0x18u:                                           /* Slave Address ACK */
            I2C_SET_DATA(I2C1, CMD>>8);                          /* Write data to I2CDAT */
				    
            break;
        case 0x20u:                                           /* Slave Address NACK */
        case 0x30u:                                           /* Master transmit data NACK */
            u8Ctrl = I2C_CTL_STO_SI;                          /* Clear SI and send STOP */
            u8Err = 1u;
            break;
        case 0x28u:
            if(HL==0)
						{
							I2C_SET_DATA(I2C1, CMD);
							HL=1;
              u8Xfering =0;							
						}							
            else I2C_SET_CONTROL_REG(I2C1, I2C_CTL_STO_SI);   /* Clear SI and send STOP */
            break;
        case 0x38u:                                           /* Arbitration Lost */
        default:                                              /* Unknow status */
            I2C_SET_CONTROL_REG(I2C1, I2C_CTL_STO_SI);      /* Clear SI and send STOP */
            u8Ctrl = I2C_CTL_SI;
            u8Err = 1u;
            break;
        }
        I2C_SET_CONTROL_REG(I2C1, u8Ctrl);                        /* Write controlbit to I2C_CTL register */
	   }
		return (u8Err | u8Xfering);                                  /* return (Success)/(Fail) status */ 
}
/*----------------------------------------------------------------*/
uint8_t SFM3300_RD_Reg(uint8_t u8DeviceAddr,uint8_t data[],uint8_t u8DataLen)  /* I2C function to read data from slave */
{   uint8_t u8Xfering = 1u, u8Err = 0u, u8Ctrl = 0u;
    uint32_t u32rxLen = 0u, u32TimeOutCount = 0u;

    I2C_START(I2C1);                                      /* Send START */
    while(u8Xfering && (u8Err == 0u))
    {
        u32TimeOutCount = I2C_TIMEOUT;
        I2C_WAIT_READY(I2C1)
          {
            if(--u32TimeOutCount == 0)
            {
                u8Err = 1u;
                break;
            }
          }
        switch(I2C_GET_STATUS(I2C1))
        {
        case 0x08u:
            I2C_SET_DATA(I2C1, (uint8_t)((u8DeviceAddr << 1u) | 0x01u));    /* Write SLA+R to Register I2CDAT */
            u8Ctrl = I2C_CTL_SI;                             /* Clear SI */
            break;
        case 0x40u:                                             /* Slave Address ACK */
            u8Ctrl = I2C_CTL_SI_AA;                          /* Clear SI and set ACK */
            break;
        case 0x48u:                                             /* Slave Address NACK */
            u8Ctrl = I2C_CTL_STO_SI;                         /* Clear SI and send STOP */
            u8Err = 1u;
            break;
        case 0x50u:
            data[u32rxLen++] = (unsigned char) I2C_GET_DATA(I2C1);    /* Receive Data */                         
						if(u32rxLen<(u8DataLen - 1u)) 
							 {
							  u8Ctrl = I2C_CTL_SI_AA;                          /* Clear SI and set ACK */
							 }
            else	u8Ctrl = I2C_CTL_SI;						 
            break;
        case 0x58u:
            data[u32rxLen++] = (unsigned char) I2C_GET_DATA(I2C1);    /* Receive Data */
				    u8Xfering =0;	
            u8Ctrl =I2C_CTL_STO_SI;               /* Clear SI and send STOP */			
            break;
        case 0x38u:                                                    /* Arbitration Lost */
        default:                                                      /* Unknow status */
            I2C_SET_CONTROL_REG(I2C1, I2C_CTL_STO_SI);               /* Clear SI and send STOP */
            u8Ctrl = I2C_CTL_SI;
            u8Err = 1u;
            break;
        }
        I2C_SET_CONTROL_REG(I2C1, u8Ctrl);                                 /* Write controlbit to I2C_CTL register */
      }
    return (u8Err | u8Xfering);		
}

/*---------------------------------------------------------------------------------------------------------*/
void PDMA_Init()
{
/*----- Initailize PDMA -----*/
    /* Reset PDMA0 module */
    SYS_ResetModule(PDMA0_RST);
    /* Open PDMA0 channel */
    PDMA_Open(PDMA0,BIT0 << PDMA0_CH);
    /* PDMA transfer width is one word (32 bit) and transfer count 8 */
    PDMA_SetTransferCnt(PDMA0,PDMA0_CH, PDMA_WIDTH_32, 8);
    /* PDMA transfer data from ADC to buffer g_au32DestArray */
    PDMA_SetTransferAddr(PDMA0,PDMA0_CH, (uint32_t) & (EADC0->CURDAT), PDMA_SAR_FIX, (uint32_t)g_au32DestArray, PDMA_DAR_INC);
    PDMA_SetTransferMode(PDMA0,PDMA0_CH, PDMA_EADC0_RX, FALSE, 0);

    PDMA_SetBurstType(PDMA0,PDMA0_CH, PDMA_REQ_SINGLE,PDMA_BURST_16);

    PDMA_EnableInt(PDMA0,PDMA0_CH, PDMA_INT_TRANS_DONE);
    NVIC_EnableIRQ(PDMA0_IRQn);

    PDMA_Trigger(PDMA0,PDMA0_CH);
    /* Enable PDMA transfer */
    EADC_ENABLE_SAMPLE_MODULE_PDMA(EADC0,0x0f);
	
	  SYS_ResetModule(PDMA1_RST);
    /* Open PDMA1 channel */
    PDMA_Open(PDMA1,BIT0 << PDMA1_CH);
    /* PDMA transfer width is one word (32 bit) and transfer count 8 */
    PDMA_SetTransferCnt(PDMA1,PDMA1_CH, PDMA_WIDTH_32, 8);
    /* PDMA transfer data from ADC to buffer g_au32DestArray */
    PDMA_SetTransferAddr(PDMA1,PDMA1_CH, (uint32_t) & (EADC0->CURDAT), PDMA_SAR_FIX, (uint32_t)g_au32DestArray, PDMA_DAR_INC);
    PDMA_SetTransferMode(PDMA1,PDMA1_CH, PDMA_EPWM0_CH2_TX, FALSE, 0);

    PDMA_SetBurstType(PDMA1,PDMA1_CH, PDMA_REQ_SINGLE,PDMA_BURST_128);

    PDMA_EnableInt(PDMA1,PDMA1_CH, PDMA_INT_TRANS_DONE);
    NVIC_EnableIRQ(PDMA1_IRQn);

    PDMA_Trigger(PDMA1,PDMA1_CH);
		/* Enable PDMA transfer */
    //EPWM_EnablePDMA(EADC0,0x0f);
}		
void DateRecord(void)
{   
	  Canvas_Image_Start_address(layer3_start_addr);
    //dateP=ReadEE(1)
    //If dateP>199) dateP=0; 
    //dateQ=dateP;
    //srg();
    MPU_Memory_Write_Window_8bit( 40,316,LCD16x16,44,White,Blue3);//��
    MPU_Memory_Write_Window_8bit( 56,316,LCD16x16,45,White,Blue3);//��
    MPU_Memory_Write_Window_8bit( 72,316,LCD16x16,46,White,Blue3);//ʱ
    MPU_Memory_Write_Window_8bit( 88,316,LCD16x16,47,White,Blue3);//��
    MPU_Memory_Write_Window_8bit(102,316,sdn,26,White,Blue3);//��
    MPU_Memory_Write_Window_8bit(200,316,sdn,31,Navy,Blue3);//H
    MPU_Memory_Write_Window_8bit(248,316,sdn,22,Navy,Blue3);//m
    MPU_Memory_Write_Window_8bit(256,316,sdn,23,Navy,Blue3);//i
    MPU_Memory_Write_Window_8bit(264,316,sdn,24,Navy,Blue3);//n
     
    MPU_Memory_Write_Window_8bit(290,316,LCD16x16,42,White,Blue3);//��
    MPU_Memory_Write_Window_8bit(306,316,LCD16x16,43,White,Blue3);//��
	MPU_Memory_Write_Window_8bit(320,316,sdn,26,White,Blue3);//:
    
    MPU_Memory_Write_Window_8bit(330,310,LCD16x24,10,White,Blue3); //HR3000A-V1.2
    MPU_Memory_Write_Window_8bit(346,310,LCD16x24,11,White,Blue3); //
    MPU_Memory_Write_Window_8bit(362,310,LCD16x24,3,White,Blue3);  //3
    MPU_Memory_Write_Window_8bit(378,310,LCD16x24,0,White,Blue3);  //0
    MPU_Memory_Write_Window_8bit(394,310,LCD16x24,0,White,Blue3);  //0
    MPU_Memory_Write_Window_8bit(410,310,LCD16x24,0,White,Blue3);  //0
    MPU_Memory_Write_Window_8bit(426,310,LCD16x24,12,White,Blue3); //A
    MPU_Memory_Write_Window_8bit(442,314,sdn,16,White,Blue3);      //-
    MPU_Memory_Write_Window_8bit(450,310,LCD16x24,13,White,Blue3); //V
    MPU_Memory_Write_Window_8bit(466,310,LCD16x24,1,White,Blue3);  //1
    MPU_Memory_Write_Window_8bit(482,314,sdn,35,White,Blue3) ;     //.
    MPU_Memory_Write_Window_8bit(490,310,LCD16x24,2,White,Blue3);  //2
		
		Color1=0xf365,Color2=0x07ff;
    dispchar24(99,138);
		Canvas_Image_Start_address(layer1_start_addr);
}
/*---------------------------------------------------------------------------------------------------------*/
void COMM(void)
{
if (id)
  {
		id=0; 
		if (printout==1)
	  { 
			/* Send 1 byte data */
      UART_WRITE(UART0,ReadEE(printcnt));
      printcnt++;	
      if (printcnt>1801)
			   {
				   printout=0;
			 	 }
		 }
   }
}	
/*---------------------------------------------------------------------------------------------------------*/
void SYS_Init(void)
{
      /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Enable HIRC clock */
    CLK_EnableXtalRC(CLK_PWRCTL_HIRCEN_Msk);

    /* Wait for HIRC clock ready */
    CLK_WaitClockReady(CLK_STATUS_HIRCSTB_Msk);
	  /* Set PCLK0 and PCLK1 to HCLK/2 */
    CLK->PCLKDIV = (CLK_PCLKDIV_APB0DIV_DIV2 | CLK_PCLKDIV_APB1DIV_DIV2);

    /* Set core clock to 200MHz */
    CLK_SetCoreClock(200000000);

    /* Enable all GPIO clock */
    CLK->AHBCLK0 |= CLK_AHBCLK0_GPACKEN_Msk | CLK_AHBCLK0_GPBCKEN_Msk | CLK_AHBCLK0_GPCCKEN_Msk | CLK_AHBCLK0_GPDCKEN_Msk |
                    CLK_AHBCLK0_GPECKEN_Msk | CLK_AHBCLK0_GPFCKEN_Msk | CLK_AHBCLK0_GPGCKEN_Msk | CLK_AHBCLK0_GPHCKEN_Msk;
    CLK->AHBCLK1 |= CLK_AHBCLK1_GPICKEN_Msk | CLK_AHBCLK1_GPJCKEN_Msk;

    /* Enable UART0 module clock */
    CLK_EnableModuleClock(UART0_MODULE);
    /* Select UART0 module clock source as HIRC and UART0 module clock divider as 1 */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART0SEL_HIRC, CLK_CLKDIV0_UART0(1));  
    /* Enable UART1 module clock */
    CLK_EnableModuleClock(UART1_MODULE);
    /* Select UART1 module clock source as HIRC and UART0 module clock divider as 1 */
    CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL1_UART1SEL_HIRC, CLK_CLKDIV0_UART1(1));
		
		CLK_EnableModuleClock(TMR0_MODULE);
    CLK_EnableModuleClock(TMR1_MODULE);
    CLK_EnableModuleClock(TMR2_MODULE);
    CLK_EnableModuleClock(TMR3_MODULE);
		CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0SEL_HIRC, 0);//12MHz
    CLK_SetModuleClock(TMR1_MODULE, CLK_CLKSEL1_TMR1SEL_HIRC, 0);//12MHz
    CLK_SetModuleClock(TMR2_MODULE, CLK_CLKSEL1_TMR2SEL_HIRC, 0);//12MHz
		CLK_SetModuleClock(TMR3_MODULE, CLK_CLKSEL1_TMR3SEL_PCLK1,0);
    /* Enable EBI module clock */
    CLK_EnableModuleClock(EBI_MODULE);
		/* Enable I2C clock */
    CLK_EnableModuleClock(I2C0_MODULE);
		CLK_EnableModuleClock(I2C1_MODULE);		
		
		/* Enable EPWM module clock */
    CLK_EnableModuleClock(EPWM0_MODULE);
    /* Select EPWM module clock source */
    CLK_SetModuleClock(EPWM0_MODULE, CLK_CLKSEL2_EPWM0SEL_PCLK0, 0);
		
		/* Enable EADC0 module clock */
    CLK_EnableModuleClock(EADC0_MODULE);
    /* Set EADC0 clock divider as 12 */
    CLK_SetModuleClock(EADC0_MODULE, CLK_CLKSEL0_EADC0SEL_PLL_DIV2, CLK_CLKDIV0_EADC0(12));
		
		/* Enable LXT and Waiting for clock ready */
    CLK_EnableXtalRC(CLK_PWRCTL_LXTEN_Msk);
    CLK_WaitClockReady(CLK_STATUS_LXTSTB_Msk);

    /* Enable RTC module clock */
    CLK_EnableModuleClock(RTC_MODULE);
		/* Set SysTick clock */
    CLK_SetSysTickClockSrc(CLK_CLKSEL0_STCLKSEL_HCLK_DIV2);
		
		CLK_SetModuleClock(KPI_MODULE, CLK_CLKSEL3_KPISEL_HIRC, CLK_CLKDIV2_KPI(0));
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Set multi-function pins for UART0 RXD and TXD */
    SET_UART0_RXD_PA0();
    SET_UART0_TXD_PA1();
    SET_UART0_nRTS_PA4();
		SET_UART0_nCTS_PA5();
		/* Set multi-function pins for UART1 RXD and TXD */
    SET_UART1_RXD_PA2();
    SET_UART1_TXD_PA3();
		
		/* Set I2C0 multi-function pins */
    SET_I2C0_SDA_PA15();
    SET_I2C0_SCL_PA14();
    /* Rotary Encoder PA8,PA9 and I2C pin enable schmitt trigger */
    PA->SMTEN |= GPIO_SMTEN_SMTEN8_Msk | GPIO_SMTEN_SMTEN9_Msk |GPIO_SMTEN_SMTEN14_Msk |GPIO_SMTEN_SMTEN15_Msk;
		SET_I2C1_SDA_PG3();
    SET_I2C1_SCL_PG2();
		/* I2C1 pin enable schmitt trigger */
    PG->SMTEN |= GPIO_SMTEN_SMTEN2_Msk | GPIO_SMTEN_SMTEN3_Msk;
		
		/* Set multi-function pin for BPWM */
    SET_EPWM0_CH0_PE7();
		SET_EPWM0_CH1_PE6();
		SET_EPWM0_CH4_PE3();
		SET_EPWM0_CH5_PE2();
		SET_EPWM0_CH2_PE10();
		
		/* Set multi-function pins for EADC0 channels. */
    SET_EADC0_CH2_PB2();
    SET_EADC0_CH3_PB3();
		SET_EADC0_CH4_PB4();
    SET_EADC0_CH5_PB5();
		SET_EADC0_CH6_PB6();
    SET_EADC0_CH7_PB7();
		SET_EADC0_CH8_PB8();
    SET_EADC0_CH9_PB9();
		SET_EADC0_CH10_PB10();
    SET_EADC0_CH11_PB11();
		SET_EADC0_CH12_PB12();
    SET_EADC0_CH13_PB13();
		SET_EADC0_CH14_PB14();
    SET_EADC0_CH15_PB15();
		/* Disable digital input path of EADC analog pin to prevent leakage */
    GPIO_DISABLE_DIGITAL_PATH(PB, BIT15|BIT14|BIT13|BIT12|BIT11|BIT10|BIT9|BIT8|BIT7|BIT6|BIT5|BIT4|BIT3|BIT2);	

    //SET_KPI_COL2_PC6();
    SET_KPI_COL3_PC7();
		SET_KPI_COL4_PC8();
    SET_KPI_COL5_PE13(); 
    SET_KPI_COL6_PE12();
		SET_KPI_COL7_PE11();
		
		//SET_KPI_ROW2_PB1();
		SET_KPI_ROW3_PB0();
		SET_KPI_ROW4_PA11();
		SET_KPI_ROW5_PA10(); 
		}

/*---------------------------------------------------------------------------------------------------------*/
/*  MAIN function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
int main(void)
{   
	  uint8_t a,b;
	  uint16_t i;
	  int32_t  u32;
	  uint32_t u32addr,u32data;
	  //S_RTC_TIME_DATA_T sWriteRTC;
	  KPI_KEY_T queue[32] = {0};
    KPI_KEY_T key;  
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Init System, peripheral clock and multi-function I/O */
    SYS_Init();

    /* Lock protected registers */
    SYS_LockReg();

    /* Init UART0 for printf */
    UART0_Init();
    UART1_Init();

	  EPWM_Init();
	  SPI_Init();
	  /* Open Timer0 in periodic mode, enable interrupt and 200 interrupt ticks per second */
    TIMER_Open(TIMER0, TIMER_PERIODIC_MODE, 200);
    TIMER_EnableInt(TIMER0);
		/* Enable Timer0 NVIC */
		NVIC_EnableIRQ(TMR0_IRQn);
		//TIMER_Start(TIMER0);
		
		/* Open Timer1 in periodic mode, enable interrupt and 100 interrupt tick per second */
    TIMER_Open(TIMER1, TIMER_PERIODIC_MODE, 400);
		/*prescaler settng TIMER1*/
		TIMER_SET_PRESCALE_VALUE(TIMER1, 120);
		TIMER1->CTL |=TIMER_CTL_PERIOSEL_Msk;
    //TIMER_EnableInt(TIMER1);
		/* Enable Timer1 NVIC */
		NVIC_EnableIRQ(TMR1_IRQn);
		
		
    /* Open Timer2 in TIMER_ONESHOT_MODE, enable interrupt */
    TIMER_Open(TIMER2, TIMER_ONESHOT_MODE, 30);
    TIMER_EnableInt(TIMER2);
    NVIC_EnableIRQ(TMR2_IRQn);
		
    /* Initial Timer3 default setting */
    TIMER_Open(TIMER3, TIMER_CONTINUOUS_MODE, 1);
    /* Configure Timer3 setting for external counter input function */
    TIMER_SET_PRESCALE_VALUE(TIMER3, 0);
    TIMER_SET_CMP_VALUE(TIMER3, 56789);
    TIMER_EnableEventCounter(TIMER3, TIMER_COUNTER_EVENT_RISING);
		TIMER_Start(TIMER3);
		
    /* Set Timeout time 0x3E bit-time and time-out counter enable 
    UART_SetTimeoutCnt(UART1, 0x3E);*/
    /* Enable RDA */
    UART_EnableInt(UART1, UART_INTEN_RDAIEN_Msk );
		
		/* Set the ADC internal sampling time, input mode as single-end and enable the A/D converter */
    EADC_Open(EADC0, EADC_CTL_DIFFEN_SINGLE_END);
    //EADC_SetInternalSampleTime(EADC0, 6);
    /* Configure the sample 4 module for analog input channel 11  */
    EADC_ConfigSampleModule(EADC0, 4, EADC_SOFTWARE_TRIGGER, 11);
    /* Configure the sample 5 module for analog input channel 1  */
    EADC_ConfigSampleModule(EADC0, 5, EADC_SOFTWARE_TRIGGER, 10);
    /* Configure the sample 6 module for analog input channel 9  */
    EADC_ConfigSampleModule(EADC0, 6, EADC_SOFTWARE_TRIGGER, 9);
    /* Configure the sample 7 module for analog input channel 8  */
    EADC_ConfigSampleModule(EADC0, 7, EADC_SOFTWARE_TRIGGER, 8);
		/* Configure the sample 8 module for analog input channel 7  */
    EADC_ConfigSampleModule(EADC0, 8, EADC_SOFTWARE_TRIGGER, 7);
    /* Configure the sample 9 module for analog input channel 6  */
    EADC_ConfigSampleModule(EADC0, 9, EADC_SOFTWARE_TRIGGER, 6);
    /* Configure the sample 10 module for analog input channel 5  */
    EADC_ConfigSampleModule(EADC0, 10,EADC_SOFTWARE_TRIGGER, 5);
    /* Configure the sample 11 module for analog input channel 4  */
    EADC_ConfigSampleModule(EADC0, 11, EADC_SOFTWARE_TRIGGER, 4);
    /* Clear the A/D ADINT0 interrupt flag for safe */
    EADC_CLR_INT_FLAG(EADC0, 0x1);
    /* Enable the sample module 4-11 interrupt */
    EADC_ENABLE_INT(EADC0, 0x1);//Enable sample module  A/D ADINT0 interrupt.
    EADC_ENABLE_SAMPLE_MODULE_INT(EADC0, 0, 0x0FF0);//Enable sample module 4-11 interrupt.
    //NVIC_EnableIRQ(ADC00_IRQn);
		
		/* Configure PE.5 */
    GPIO_SetMode(PE, BIT5, GPIO_MODE_INPUT);
		
		GPIO_SetMode(PH, BIT7, GPIO_MODE_INPUT);
    /* Configure multi-function pins for EBI 16-bit application */
    Configure_EBI_16BIT_Pins();

    /* Initialize EBI bank0 to access external SRAM */
    EBI_Open(EBI_BANK0, EBI_BUSWIDTH_16BIT, EBI_TIMING_NORMAL,EBI_OPMODE_ADSEPARATE, EBI_CS_ACTIVE_LOW);
		/* Init I2C0 to access EEPROM */
    I2C0_Init();
		I2C1_Init();
		/* Configure as a master, clock idle low, 8-bit transaction, drive output on falling clock edge and latch input on rising edge. */
    /* Set IP clock divider. SPI clock rate = 2MHz */
    SPI_Open(SPI0, SPI_MASTER, SPI_MODE_0, 16, 2000000);

    GPIO_SetMode(PD, BIT4, GPIO_MODE_OUTPUT);
		
		/* Enable RTC NVIC */
    NVIC_EnableIRQ(RTC_IRQn);
		/* Open RTC and start counting */
    sWriteRTC.u32Year       = 2026;
    sWriteRTC.u32Month      = 4;
    sWriteRTC.u32Day        = 9;
    sWriteRTC.u32DayOfWeek  = RTC_SATURDAY;
    sWriteRTC.u32Hour       = 19;
    sWriteRTC.u32Minute     = 30;
    sWriteRTC.u32Second     = 30;
    sWriteRTC.u32TimeScale  = RTC_CLOCK_24;
    u32=*((int32_t*)RTC_INIT);
		if ((u32 & 0x01)!=1) RTC_Open(&sWriteRTC);
		RTC_SetTickPeriod(RTC_TICK_1_SEC);
		while (RTC_GET_TICK_INT_FLAG() == 0);
		show_date();
		/* Enable RTC tick interrupt, one RTC tick is 1/4 second */
    RTC_EnableInt(RTC_INTEN_TICKIEN_Msk);
    
		GPIO_SetMode(PC, BIT11, GPIO_MODE_INPUT);   //power
		GPIO_SetMode(PC, BIT12, GPIO_MODE_INPUT);   //charge
		
		GPIO_SetMode(PC, BIT13, GPIO_MODE_OUTPUT);   //SWN
		GPIO_SetMode(PC, BIT14, GPIO_MODE_OUTPUT);   //MODE_S
	
		GPIO_SetMode(PA, BIT12,GPIO_MODE_OUTPUT);// int_ 
    GPIO_SetMode(PA, BIT13,GPIO_MODE_OUTPUT);// RES
		GPIO_SetMode(PA, BIT6,GPIO_MODE_OUTPUT);
		GPIO_SetMode(PA, BIT8,GPIO_MODE_INPUT);   // rol
		GPIO_SetMode(PA, BIT9,GPIO_MODE_INPUT);   // rol_
		
		GPIO_SetMode(PA, BIT10,GPIO_MODE_INPUT);// K_ 
    GPIO_SetMode(PA, BIT11,GPIO_MODE_INPUT);// K
		GPIO_SetMode(PB, BIT0, GPIO_MODE_INPUT);// K_ 
    GPIO_SetMode(PB, BIT1, GPIO_MODE_INPUT);// K
		GPIO_SetMode(PC, BIT6,GPIO_MODE_OUTPUT);//  
    GPIO_SetMode(PC, BIT7,GPIO_MODE_OUTPUT);//
		GPIO_SetMode(PC, BIT8,GPIO_MODE_OUTPUT);//
		GPIO_SetMode(PE, BIT11,GPIO_MODE_OUTPUT);// K_ 
    GPIO_SetMode(PE, BIT12,GPIO_MODE_OUTPUT);// K
		GPIO_SetMode(PE, BIT13,GPIO_MODE_OUTPUT);// K
		/*lt7683 reset_pin PD14 */
		GPIO_SetMode(PD, BIT14, GPIO_MODE_OUTPUT);  // LT7681_Reset
		PD14=1;
		GPIO_SetMode(PG,  BIT4, GPIO_MODE_OUTPUT);
		GPIO_SetMode(PG,  BIT9, GPIO_MODE_OUTPUT);
		GPIO_SetMode(PG, BIT10, GPIO_MODE_OUTPUT);
		GPIO_SetMode(PG, BIT11, GPIO_MODE_OUTPUT);
		GPIO_SetMode(PG, BIT12, GPIO_MODE_OUTPUT);
		
		GPIO_SetMode(PH, BIT4,GPIO_MODE_INPUT);// manual_
		GPIO_SetPullCtl(PH,  BIT4, GPIO_PUSEL_PULL_UP);
		
		GPIO_SetPullCtl(PG,  BIT2, GPIO_PUSEL_PULL_UP);
		GPIO_SetPullCtl(PG,  BIT3, GPIO_PUSEL_PULL_UP);
		
		GPIO_SetPullCtl(PB,  BIT0, GPIO_PUSEL_PULL_UP);
		GPIO_SetPullCtl(PB,  BIT1, GPIO_PUSEL_PULL_UP);
		GPIO_SetPullCtl(PA, BIT10, GPIO_PUSEL_PULL_UP);
		GPIO_SetPullCtl(PA, BIT11, GPIO_PUSEL_PULL_UP);
		/* Interal pull-up is weak and needs to slowdown the timing */
    LT768_Init();            // LT768��ʼ��
	  Select_SFI_Dual_Mode0(); // ʹ�ÿ��ٶ�FLASH���3Bh�����ο�W25Q128�Ķ�ȡ����ָ��3Bh
	  LT768_PWM0_Init( 1,0,200,200,100 );
   // 0����ֹPWM0    1��ʹ��PWM0 ;PWMʱ�ӷ�Ƶ  ȡֵ��Χ 0~3(1,1/2,1/4,1/8); ʱ�ӷ�Ƶ  ȡֵ��Χ 1~256; ����PWM���������; ����ռ�ձ�
	  //LT768_PWM1_Init(1,0,200,100,PwmControl);
    /* Init KPI */
    KPI_Open(4, 6, queue, 24);
    /* Key sampling time */
    KPI_SetSampleTime(10);
    
    KPI_EnableSlowScan();
		/* Clear status */
    KPI->STATUS = KPI->STATUS; 
Display_ON();
Show();
DateRecord();
/*Enable interrupt by rising edge trigger */
GPIO_EnableInt(PA, 8, GPIO_INT_FALLING);
NVIC_EnableIRQ(GPA_IRQn);
EPWM_Start(EPWM0, EPWM_CH_0_MASK); //EPWM0 channel 0 counter start running.
EPWM_Start(EPWM0, EPWM_CH_1_MASK); //EPWM0 channel 1 counter start running.	
EPWM_Start(EPWM0, EPWM_CH_4_MASK); //EPWM0 channel 4 counter start running.
EPWM_Start(EPWM0, EPWM_CH_5_MASK); //EPWM0 channel 4 counter start running.
EPWM_Start(EPWM0, EPWM_CH_2_MASK); //EPWM0 channel 2 counter start running
EPWM_EnablePeriodInt(EPWM0,2,0);
NVIC_EnableIRQ(EPWM0P1_IRQn);
sflash=0;		
ks=0;
sec=0;
end_=0;
frist_=1;
count=0;
stk=0;
a=ReadEE(1900),b=ReadEE(1901); //pv 0      1
pv0=b*256+a;
if (pv0>2095) pv0=2095;
//prt16D(524,420,pv0);
a=ReadEE(1902),b=ReadEE(1903);//pv 20      2
pv20=b*256+a;
if (pv20>2500) pv20=2500;
//prt16D(524,520,pv20);
a=ReadEE(1904),b=ReadEE(1905); //pvI0      3
pvI0=b*256+a;
if (pvI0>2000) pvI0=2000;
//prt16D(524,420,pvI0);
a=ReadEE(1906),b=ReadEE(1907);//pvI20      4
pvI20=b*256+a;
if (pvI20>4095) pvI20=4095;
//prt16D(524,520,pvI20);
a=ReadEE(1908),b=ReadEE(1909); //ox21      5
ox21=b*256+a;
//prt16D(524,500,ox21);
a=ReadEE(1910),b=ReadEE(1911); //ox100     6
ox100=b*256+a;  
//prt16D(524,520,ox100);

a=ReadEE(1912),b=ReadEE(1913); //kvt       7
kvt=b*256+a; 
if (kvt>1023) kvt=1023;
else if (kvt<100) kvt=100;
a=ReadEE(1914),b=ReadEE(1915); //VT_0      8
VT_0=b*256+a;
//prt16D(524,540,VT_0);

freq=ReadEE(2001);
if (freq>40 || freq<6)  freq=15;
dutp=ReadEE(2002);
if (dutp>13) dutp=6;
 //{0x41,0x31,0x21,0x32,0x11,0x23,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,}
dut=dut_tab[dutp];
	 
ps_tr=ReadEE(2003);	 
if (ps_tr<-20 || ps_tr>-1) ps_tr=-3;

ps_H =ReadEE(2004);
if (ps_H>80 || ps_H<10) ps_H=40;
ps_L =ReadEE(2005);
if (ps_L>40 || ps_L<6) ps_L=6;	 

VT_H=ReadEE(2006);
if (VT_H>150 || VT_H<40) VT_H=100;
VT_L=ReadEE(2007);
if (VT_L>40 || VT_L<2) VT_L=10;
	 
a=ReadEE(2008),b=ReadEE(2009);
MV_H=b*256+a;	 
if (MV_H>150 || MV_H<40) MV_H=100;
a=ReadEE(2010),b=ReadEE(2011);
MV_L=b*256+a;	 
if (MV_L>40 || MV_L<2) MV_L=10;	
	 
setpeep=ReadEE(2012);
if (setpeep>30) setpeep=5; 
pwmPeep=setpeep*10+80;
setO2=ReadEE(2014);
if (setO2>100 || setO2<21 ) setO2=21; 
VT_preset=ReadEE(2013);
if (VT_preset>150 || VT_preset<2) VT_preset=50;	 
O2s=ReadEE(2014);
if (O2s>99 || O2s<21) O2s=21;
O2_L=ReadEE(2015);
if (O2_L>30 || O2_L<15) O2_L=17;
O2_H=ReadEE(2016);
if (O2_H>99 || O2_H<50) O2_H=60;
Pcontrol=ReadEE(2017);
if (Pcontrol>40 || Pcontrol<5) Pcontrol=20;

a=ReadEE(2046),b=ReadEE(2047);
base_s=a+b*256;
base_s=408;
compute(freq,dut);
scale1();
 /* Start Timer1 counting */
//TIMER_Start(TIMER1);
Color1=White,Color2=Black,dispVT(VT_preset*10,VTset_x_pos,VTset_y_pos);
VT_preset_m=VT_preset;
sigauto=1;
MPU_Memory_Write_Window_8bit(MODE_x_pos,MODE_y_pos,mode,7,White,Blue1);
	
MPU_Memory_Write_Window_8bit(freq_x_pos,freq_y_pos,image,12,White,Black);
MPU_Memory_Write_Window_8bit(freq_x_pos+32,freq_y_pos,image,12,White,Black);
MPU_Memory_Write_Window_8bit(dut_x_pos,dut_y_pos,image,12,White,Black);
MPU_Memory_Write_Window_8bit(dut_x_pos+32,dut_y_pos,image,12,White,Black);//a_c();
apt=0;
xxx=0;
yyy=0;
clrspk=1;
spk=0;
spkbk=0;
tf=0;
minP=0;
Color1=White,Color2=Black;
Touchcount=0;
mloop=0;
alarm=2;
manuals=0;
manual_fin=0;
QC=0,cal_adj=0;
plow=0,phigh=0;
sps=0,dateadj=0,Ms=0,calipery=0;
M=0,N=0,NegP=0;
SYSTEM0=0,SYSTEM1=0;
cal_adj=0;
LT768_Select_Internal_Font_Init
(
 32         // ���������С  16��16*16     24:24*24    32:32*32
,1          // ����Ŀ��ȷŴ�����1~4
,1          // ����ĸ߶ȷŴ�����1~4
,0          // 0�����屳��ɫ͸��    1��������������ı���ɫ
,0          // 0�������岻����      1���������
);
g_u32RTCTickINT =0;
status=0;
frz=1;
PA6=0;
MPU_Memory_Write_Window_8bit(800,10,Pic32x32,0,0xf720,Blue1);
Lock=1;
pwmO2Err1=0,pwmO2Err2=0;
PeepErr1=0;
//LT768_PIP_Init( 1, 1, layer2_start_addr,    0,  0, 1024, 200, 100, 500, 350 );

//Fills(820,320,850,360,Blue3);		
SFM3300_WR_CMD(0x40,0x1000);		
TIMER_Start(TIMER0);		
//ReadEEcon(2001, 10,pbuf);
WriteEE(2000,0xaa);
//a=ReadEE(2000);
Color1=Red,Color2=Black;		
//prt16D(0,140,a);
test=0;
Layer=0,Rset0=0,Rset10=0,Rset100=0,keydown=0;
/*for (i=0;i<2000;i++)
  {
		WriteEE(2048+2*i,(uint8_t) (i&0xff));
	  WriteEE(2048+2*i+1,(uint8_t) (i>>8));
	}
Delayms(10);	*/
for (i=0;i<2000;i++)
    {
		 a=ReadEE(2048+i+i); 
	   b=ReadEE(2048+i+i+1);
     standard[i]=b*256+a;					
		}	
		
while(1)
 { 
	
  if(g_u8TimeoutFlag)
     {
      /* When I2C timeout, reset IP*/     
      SYS->IPRST1 |= SYS_IPRST1_I2C0RST_Msk;
      SYS->IPRST1 = 0;
      I2C0_Init();
		 } 
	Color1=Red,Color2=Black;	 
	__disable_irq();//��ȫ���ж�
	//SFM3300_WR_CMD(0x40,0x1000);		 
	//SFM3300_RD_Reg(0x40,pbuf,3);
	__enable_irq();//��ȫ���ж�  
	//uint16_temp=pbuf[0]<<8 | pbuf[1]; 
	//int16_temp=uint16_temp-32768; 
	//int16_flow =int16_temp/10;/*k=120  0.12L/digit/min=120mL/digit/60000ms=20mL/digit/(25*40)ms=4mL/digit/(5*40)ms */
  if (pwmhl)
	  {
			prtx(850,100,pwmO2Err0),prtx(850,180,int16testpeep),prtx(850,120,deltpwmO2),prtx(850,140,int16_flow);
	    prt16D(850,160,lq);	
	    prt16D(850,460,Vpsbk);
		}
	prt16D(850,500,pwmO2);	
	prt8(850,220,VMode);
  prt8(850,520,pwmhl);		
	/* Check if any key pressed */
  if(KPI_kbhit())
    {
     key = KPI_GetKey();
     if (key.x==0 && key.y==0) Manual();
		 if (key.x==0 && key.y==0) Manual();
	   if (key.x==0 && key.y==0) Manual();
		 if (key.x==0 && key.y==0) Manual();
		 if (key.x==0 && key.y==0) Manual();
		 if (key.x==0 && key.y==0) Manual();
		 if (key.x==0 && key.y==0) Manual();
    }
	PC6=0;
	if (PB1==0 &&  VMode==1)
	   {
			 Delayms(30);
			 if (PB1==0 && VMode==1) PCV(); 
		 }		
  //MPU_Memory_Write_Window_8bit(850,560,mdn,sigauto,White,Green1);	
	if (MA==1 && sigauto!=1)	
	   {
		  Manual();
		 }	
	if (MA==0 && sigauto==1)
	   {
		  IPPV();
		 }	 
	det();    		 
	flashes();	 
  show_date();	 	 
	Color1=White,Color2=Black;
	prtx(850,260,Err0Pplatfrom),prtx(850,280,Err1Pplatfrom),prtx(850,300,Err2Pplatfrom),prt16D(850,320,FrontPpeak);
	prtx(820,340,Exponent);//,prt32(820,360,abs(int32VtEx));
  Color1=Green,Color2=Black;
  prt16D(850,480,Compliasnce);		 
	prtx(840,360,Err0Pcontrol),prtx(840,380,Err1Pcontrol),prtx(840,400,Err2Pcontrol);//Color2=Black,	prt16D(850,580,pv20);	 	
	if (seco>2400) Fills(538,0,570,50,Green1),clrspk=1;

  		 
	if (sound_s)  sound_s=0,sou();
		 
	COMM();	
	 
  if (int_ror)	
	  {
			int_ror=0;
			if (Layer==1)
					{ 
					 Rset0+=add_sub;
					 add_sub=0;
					 if (Rset0==0) Rset0=7;
					 if (Rset0>7) Rset0=1;
					 SelectErase(1,0);
					 LT768_DrawCircleSquare(LocationTab[4*Rset0]-4,LocationTab[4*Rset0+1]-4,LocationTab[4*Rset0+2]+4,LocationTab[4*Rset0+3]+4,10,10,Red);						 					 
					}
      if (Layer==2) 
				 {
					switch (Rset0)
							  {
								 case 1:                  //VMode
								    Rset10+=add_sub;
					          add_sub=0;
								    if (Rset10==0) Rset10=6;
								    if (Rset10>6) Rset10=1;
								    SelectErase(2,1);
								    Canvas_Image_Start_address(layer2_start_addr);
								    LT768_DrawCircleSquare(LocationTab[4*Rset10+112]-4,LocationTab[4*Rset10+113]-4,LocationTab[4*Rset10+114]+4,LocationTab[4*Rset10+115]+4,10,10,Red); 
							      Canvas_Image_Start_address(layer1_start_addr);	
								    break;
							   case 2: 
								    
								    break;
							   case 3:                  //Record
								    if (add_sub==1)	 srg(); 													
										if (add_sub==-1) dateQ=(dateQ+16)%200,srg(); 
								    break;
							   case 4:                  //SET
									  Rset10+=add_sub;
					          add_sub=0;
								    if (Rset10==0) Rset10=10;
								   if (Rset10>10) Rset10=1;
								   SelectErase(2,4);
								   Canvas_Image_Start_address(layer3_start_addr);
								   LT768_DrawCircleSquare(LocationTab[4*Rset10+32]-4,LocationTab[4*Rset10+33]-4,LocationTab[4*Rset10+34]+4,LocationTab[4*Rset10+35]+4,10,10,Red); 
							     Canvas_Image_Start_address(layer1_start_addr);	
                   break;
			           case 5:                 //System
									 Rset10+=add_sub;
					         add_sub=0;
								   if (Rset10==0) Rset10=16;
								   if (Rset10>16) Rset10=1;
								   SelectErase(2,5);
								   Canvas_Image_Start_address(layer2_start_addr);
								   LT768_DrawCircleSquare(LocationTab[4*Rset10+184]-4,LocationTab[4*Rset10+185]-4,LocationTab[4*Rset10+186]+4,LocationTab[4*Rset10+187]+4,10,10,Red); 
							     Canvas_Image_Start_address(layer1_start_addr);			 
		               break;
			           case 6:	               //Silence 
									 										 
									 break;
								 case 7:                 //Layer=2  adjTime
									  if (fristdown==0)
											 {
												Rset10+=add_sub;
												add_sub=0;
												if (Rset10==0) Rset10=7;
												if (Rset10>7)  Rset10=1;
												SelectErase(2,7);
												Canvas_Image_Start_address(layer2_start_addr);
												LT768_DrawCircleSquare(LocationTab[4*Rset10+152]-4,LocationTab[4*Rset10+153]-4,LocationTab[4*Rset10+154]+4,LocationTab[4*Rset10+155]+4,10,10,Red); 
												Canvas_Image_Start_address(layer1_start_addr);
											 }
										else
										   {
											 switch (Rset10)
													{
														case 1 :
															if (add_sub==1)														
															 	 {
																	if (year0<40 )  year0++ ;
																 }
															else
																 {
																	if (year0>20 ) year0-- ; 
																 }
															Canvas_Image_Start_address(layer2_start_addr);	
															Color1=Red,Color2=Blue2;
															dispmword(year0,540,40);
															Canvas_Image_Start_address(layer1_start_addr);
															break;
														case 2:
															if (add_sub==1)														
																	{
																		if (month0<12)  month0++ ;
																	}
															else
																	{
																		if (month0>1)  month0-- ;
																	}
															Color1=Red,Color2=Blue2;
															Canvas_Image_Start_address(layer2_start_addr);
															dispmword(month0,670,40);
															Canvas_Image_Start_address(layer1_start_addr);
															break;
														case 3 :
															if (add_sub==1)														
																	{
																		if (day0<31)   day0++;
																	}
															else
																	{
																		if (day0>1)   day0--;
																	}
															Canvas_Image_Start_address(layer2_start_addr);
															Color1=Red,Color2=Blue2;
															dispmword(day0,800,40);	
															Canvas_Image_Start_address(layer1_start_addr);
															break;
														case 4:
															if (add_sub==1)														
																	{
																		if (hour0<23)  hour0++;
																	}
															else
																	{
																		if (hour0>1)  hour0--;
																	}
															Canvas_Image_Start_address(layer2_start_addr);
															Color1=Red,Color2=Blue2;
															dispmword(hour0,540,100);	
															Canvas_Image_Start_address(layer1_start_addr);
															break;
														case 5:
															if (add_sub==1)														
																	{
																		if (minute0<59)  minute0++;
																	}
															else
																	{
																		if (minute0>1) minute0--;
																	}
															Canvas_Image_Start_address(layer2_start_addr);
															Color1=Red,Color2=Blue2;
															dispmword(minute0,670,100);
															Canvas_Image_Start_address(layer1_start_addr);
															break; 
														case 6:
															if (add_sub==1)														
																	{
																		if (second0<59)  second0++;
																	}
															else
																	{
																		if (second0>1)  second0--;
																	}
															Canvas_Image_Start_address(layer2_start_addr);
															Color1=Red,Color2=Blue2;
															dispmword(second0,800,100);
															Canvas_Image_Start_address(layer1_start_addr);										 
													} 
											 }											
							  }
					}
       if (Layer==3)	
					{
					 switch (Rset0)
							  {
								 case 1:
								    
							   	 break;
							   case 2: 
								 
								    break;
							   case 3:
								   
								    break;
							   case 4:
								   switch (Rset10)
                       	{
		                      case 1:
                            if (add_sub==1)														
														  {
															 if (freq_m<60) freq_m++;
															}
														if (add_sub==-1)
														   {
															  if (freq_m>6) freq_m--;
															 }
													  Color1=White,Color2=Red;
													  Canvas_Image_Start_address(layer2_start_addr);									   
										        disp(freq_m,adj_x_pos,adj_y_pos);
										        Canvas_Image_Start_address(layer1_start_addr);
				                    break;	
	                        case 2:
                            if (add_sub==1)														
														  {
															 if (dutp_m<13)  dutp_m++;
															}
														if (add_sub==-1)
														   {
															  if (dutp_m>0)  dutp_m--;
															 } 														 
													  dut=dut_tab[dutp_m],Color1=White,Color2=Red;
                            xn=adj_x_pos,yn=adj_y_pos; 
											      Canvas_Image_Start_address(layer2_start_addr);									   
										        bbx(dut);
										        Canvas_Image_Start_address(layer1_start_addr);
		                        break; 
		                     case 3:
													  if (add_sub==1)														
														  {
															 if (VT_preset_m<150) VT_preset_m++;
															}
														if (add_sub==-1)
														   {
															   if (VT_preset_m>2) VT_preset_m--;
															 }
                            Color1=White,Color2=Red;
												    Canvas_Image_Start_address(layer2_start_addr);
                            dispVT(VT_preset_m*10,adj_x_pos,adj_y_pos);
												    Canvas_Image_Start_address(layer1_start_addr);
		                        break;
		                     case 4:
                            if (add_sub==1)														
														  {
															 if (setpeep_m<40) setpeep_m++;
															}
														if (add_sub==-1)
														   {
															   if (setpeep_m>0) setpeep_m--;
															 }													 
												    Color1=White,Color2=Red;						                	
												    Canvas_Image_Start_address(layer2_start_addr);
												    disp(setpeep_m,adj_x_pos,adj_y_pos);
													  Canvas_Image_Start_address(layer1_start_addr);
		                        break;
		                     case 5:
                            if (add_sub==1)														
														  {
															 if (Pcontrol_m<40) Pcontrol_m++;
															}
														if (add_sub==-1)
														   {
															   if (Pcontrol_m>5) Pcontrol_m--;
															 }
                            Color1=White,Color2=Red;
											      Canvas_Image_Start_address(layer2_start_addr);
						                disp(Pcontrol_m,adj_x_pos,adj_y_pos);
											      Canvas_Image_Start_address(layer1_start_addr);
					                  break;
		                     case 6:
													  if (fristdown==0)
														  {
																Rset100+=add_sub;
																add_sub=0; 
																if (Rset100==0) Rset100=4;
																if (Rset100>4) Rset100=1;
																SelectErase(3,0); 
																Canvas_Image_Start_address(layer2_start_addr);
																LT768_DrawCircleSquare(LocationTab[4*Rset100+88]-4,LocationTab[4*Rset100+89]-4,LocationTab[4*Rset100+90]+4,LocationTab[4*Rset100+91]+4,10,10,Red); 
																Canvas_Image_Start_address(layer1_start_addr);
														  }
														else
														  {
															  switch (Rset100)
											             {
													          case 1:
														           if (add_sub==1)														
														              {
															             if (ps_tr_m<-1) ps_tr_m++;
															            }
														            if (add_sub==-1)
														              {
															             if (ps_tr_m>-20) ps_tr_m--;
															            } 
											                  Color1=White,Color2=Red; 
													              Canvas_Image_Start_address(layer2_start_addr);									   
																				dispPN(ps_tr_m,adj_x_pos,adj_y_pos);
																				Canvas_Image_Start_address(layer1_start_addr);
																				break;
																		case 2:
														            if (add_sub==1)														
																					 {
															             if (flow_tr_m<20) flow_tr_m++;
															             }
														            if (add_sub==-1)
																				   {
																						if (flow_tr_m>1) flow_tr_m--;
																					 }
																				Color1=White,Color2=Red; 
																				Canvas_Image_Start_address(layer2_start_addr);									   
																				disp(flow_tr_m,adj_x_pos,adj_y_pos);
																				Canvas_Image_Start_address(layer1_start_addr);
																				break;
																		case 4:
																			  if (Trig_sel) Trig_sel=0;
																				else  Trig_sel=1;
																		}
																}
		                        break;
		                     case 7:
													  if (fristdown==0)
														  {
																Rset100+=add_sub;
																add_sub=0; 
																if (Rset100==0) Rset100=3;
																if (Rset100>3) Rset100=1;
																SelectErase(3,0); 
																Canvas_Image_Start_address(layer2_start_addr);
																LT768_DrawCircleSquare(LocationTab[4*Rset100+88]-4,LocationTab[4*Rset100+89]-4,LocationTab[4*Rset100+90]+4,LocationTab[4*Rset100+91]+4,10,10,Red); 
																Canvas_Image_Start_address(layer1_start_addr);
															}
														else
														  {
															 switch (Rset100)
																	{
																		case 1:
																				if (add_sub==1)														
																						{
																						if (ps_H_m<80) ps_H_m++;
																						}
																				if (add_sub==-1)
																						{
																						if (ps_H_m>(ps_L+1)) ps_H_m--;
																						} 			 
																				Color1=White,Color2=Red;  
																				Canvas_Image_Start_address(layer2_start_addr);
																				disp(ps_H_m,adj_x_pos,adj_y_pos);
																				Canvas_Image_Start_address(layer1_start_addr);
																				break;
																		case 2:
																				if (add_sub==1)														
																						{
																						if (ps_L_m<(ps_H-1)) ps_L_m++;
																						}
																				if (add_sub==-1)
																						{
																						if (ps_L_m>2) ps_L_m-- ;
																						}  
																				Color1=White,Color2=Red; 
																				Canvas_Image_Start_address(layer2_start_addr);									   
																				disp(ps_L_m,adj_x_pos,adj_y_pos);
																				Canvas_Image_Start_address(layer1_start_addr);
																		}	
																}
		                        break;
		                     case 8:
													  if (fristdown==0)
														  {
																Rset100+=add_sub;
																add_sub=0; 
																if (Rset100==0) Rset100=3;
																if (Rset100>3) Rset100=1;
																SelectErase(3,0); 
																Canvas_Image_Start_address(layer2_start_addr);
																LT768_DrawCircleSquare(LocationTab[4*Rset100+88]-4,LocationTab[4*Rset100+89]-4,LocationTab[4*Rset100+90]+4,LocationTab[4*Rset100+91]+4,10,10,Red);  
																Canvas_Image_Start_address(layer1_start_addr);
															}
														else
														  {
																switch (Rset100)
																	{
																		case 1:
																			if (add_sub==1)														
																					{
																						if (VT_H_m<150) VT_H_m++;
																					}
																			if (add_sub==-1)
																					{
																					if (VT_H_m>(VT_L+1)) VT_H_m--;
																					}
																			Color1=White,Color2=Red; 
																			Canvas_Image_Start_address(layer2_start_addr);									   
																			dispVT(VT_H_m*10,adj_x_pos,adj_y_pos);
																			Canvas_Image_Start_address(layer1_start_addr);
																			break;
																		case 2:
																			if (add_sub==1)														
																					{
																						if (VT_L_m<(VT_H-1))  VT_L_m++;
																					}
																			if (add_sub==-1)
																					{
																						if (VT_L_m>5) VT_L_m--;
																					}
														 
																			Color1=White,Color2=Red; 
																			Canvas_Image_Start_address(layer2_start_addr);									   
																			dispVT(VT_L_m*10,adj_x_pos,adj_y_pos);
																			Canvas_Image_Start_address(layer1_start_addr);
																	}
																}		
		                        break;
		                     case 9 : 
													  if (fristdown==0)
														   {
																Rset100+=add_sub;
																add_sub=0; 
																if (Rset100==0) Rset100=3;
																if (Rset100>3) Rset100=1;
																SelectErase(3,0); 
																Canvas_Image_Start_address(layer2_start_addr);
																LT768_DrawCircleSquare(LocationTab[4*Rset100+88]-4,LocationTab[4*Rset100+89]-4,LocationTab[4*Rset100+90]+4,LocationTab[4*Rset100+91]+4,10,10,Red);  
																Canvas_Image_Start_address(layer1_start_addr); 
																}
														else
																{	
																	switch (Rset100)
																		{
																		case 1:
																				if (add_sub==1)														
																						{
																							if (O2_H_m<99) O2_H_m++;
																						}
																				if (add_sub==-1)
																						{
																							if (O2_H_m>(O2_L+1)) O2_H_m--;
																						}
																				Color1=White,Color2=Red; 
																				Canvas_Image_Start_address(layer2_start_addr);									   
																				disp(O2_H_m,adj_x_pos,adj_y_pos);
																				Canvas_Image_Start_address(layer1_start_addr);
																				break;
																		case 2:
																				if (add_sub==1)														
																						{
																						if (O2_L_m<O2_H-1) O2_L_m++ ;
																						}
																				if (add_sub==-1)
																						{
																							if (O2_L_m>18) O2_L_m--;
																						} 
																				Color1=White,Color2=Red; 
																				Canvas_Image_Start_address(layer2_start_addr);									   
																				disp(O2_L_m,adj_x_pos,adj_y_pos);
																				Canvas_Image_Start_address(layer1_start_addr);
															 	   }
												    }
										}													
                 
					   }	 
		   }
	 }				
	Color1=White,Color2=Black;	
	//prt8(820,520,Layer),prt8(840,520,Rset0),prt8(860,520,Rset10),prt8(880,520,Rset100);
  //prt8(840,540,cal);
	if (PC13==0)	
	   {
			 Delayms(30);
		   if (PC13==0)
		      { 
						while(PC13==0)
						{
						 det();
						}
						keydown=1;
					}
		 }					
	if(Layer==0 && keydown==1)
		{
  		keydown=0;
			Layer=1;
			Rset0=1;
			Lock=0;
			LT768_DrawCircleSquare(LocationTab[4*Rset0]-4,LocationTab[4*Rset0+1]-4,LocationTab[4*Rset0+2]+4,LocationTab[4*Rset0+3]+4,10,10,Red);
		 }
	if(Layer==1 && keydown==1)
		 {
			keydown=0;
			switch (Rset0)
				{
				 case 1:
					  show_mode();
				    Rset10=1;
				    Canvas_Image_Start_address(layer2_start_addr);
				    LT768_DrawCircleSquare(LocationTab[4*Rset10+112]-4,LocationTab[4*Rset10+113]-4,LocationTab[4*Rset10+114]+4,LocationTab[4*Rset10+115]+4,10,10,Red); 
				    Canvas_Image_Start_address(layer1_start_addr);
				    Layer=2;
				    break;
				case 2:
					  frozen();
				    Layer=1;				
				    break;
				case 3:
					  Record();
				    Layer=2;				
				    break;
				case 4:
					 LT768_PIP_Init( 1, 2, layer3_start_addr,  0,350, 1024, 100,200, 780, 240 );
				   Rset10=1;
				   Canvas_Image_Start_address(layer3_start_addr);
				   LT768_DrawCircleSquare(LocationTab[4*Rset10+32]-4,LocationTab[4*Rset10+33]-4,LocationTab[4*Rset10+34]+4,LocationTab[4*Rset10+35]+4,10,10,Red); 
				   Canvas_Image_Start_address(layer1_start_addr);
				   Layer=2;
				   break;
				case 5:
					 if (cal==1)
					    {
								CaliplierZ(); //System
				        Rset10=1;
				        Canvas_Image_Start_address(layer2_start_addr);
				        LT768_DrawCircleSquare(LocationTab[4*Rset10+184]-4,LocationTab[4*Rset10+185]-4,LocationTab[4*Rset10+186]+4,LocationTab[4*Rset10+187]+4,10,10,Red); 
				        Canvas_Image_Start_address(layer1_start_addr);
					      Layer=2;
							}
					 minP=~minP;	
					 if (minP) LT768_PIP_Init( 1, 2, layer3_start_addr,  890,500, 1024, 890,140, 100, 100 );	
           else  Disable_PIP2();    						 
				   break;
				case 6:
					 Lock=0;
					 Silence();
           Layer=1;
				   break;	
        case 7:  //adjTime
					 show_set_date();
				   Rset10=1;
				   Canvas_Image_Start_address(layer2_start_addr);
				   LT768_DrawCircleSquare(LocationTab[4*Rset10+152]-4,LocationTab[4*Rset10+153]-4,LocationTab[4*Rset10+154]+4,LocationTab[4*Rset10+155]+4,10,10,Red); 
				   Canvas_Image_Start_address(layer1_start_addr);
					 Layer=2;
			
				} 
		}						 
  if (Layer==2 && keydown==1)	
		{
			keydown=0; 
			switch (Rset0)
		    {
			   case 1:  //Layer=2  VMode
						if (sigauto!=1)
						   {
								 switch (Rset10)
				           { 
										case 1:
											a_c();
											Disable_PIP1();
											Layer=1;
											break;
										case 2:
											sigh();
											Disable_PIP1();
											Layer=1;
											break;
										case 3:
											simv();
											Disable_PIP1();
											Layer=1;
											break;
										case 4:
											PCV();
											Disable_PIP1();
											Layer=1;
											break;
										case 5:
								
											Disable_PIP1();
											Layer=1;
											break;
										case 6:
								
											Disable_PIP1();
											Layer=1;
										}
								}
				   break;
			   case 2: 
					 			 
					 break;
			   case 3:  //Layer=2  Record
					 Record();  
           Layer=1; 				 
					 break;
			   case 4:  //Layer=2  SET
					 Canvas_Image_Start_address(layer2_start_addr);
           LT768_DrawCircleSquare_Fill( 20+100,20,20+250,20+60,10,10,Red);
				   Canvas_Image_Start_address(layer1_start_addr);
				   switch (Rset10)
				     { 
					    case 1:
						     LT768_PIP_Init( 1, 1, layer2_start_addr,  0,0, 1024, 100,100, 470, 350 );
							   freq_m=freq;
							   Color1=White,Color2=Red;
							   Canvas_Image_Start_address(layer2_start_addr);                 							
							   disp(freq_m,adj_x_pos,adj_y_pos);
							   Canvas_Image_Start_address(layer1_start_addr);
							   Layer=3;
					       break;
					    case 2: 
								 LT768_PIP_Init( 1, 1, layer2_start_addr,  0,0, 1024, 100,100, 470, 350 );
								 dutp_m=dutp,dut=dut_tab[dutp],Color1=White,Color2=Red;
                 xn=adj_x_pos,yn=adj_y_pos;
								 Canvas_Image_Start_address(layer2_start_addr);
							   bbx(dut);
							   Canvas_Image_Start_address(layer1_start_addr);
							   Layer=3;
					       break;
				      case 3:
							   LT768_PIP_Init( 1, 1, layer2_start_addr,  0,0, 1024, 100,100, 470, 350 );
								 VT_preset_m=VT_preset ,Color1=White,Color2=Red;
							   Canvas_Image_Start_address(layer2_start_addr);
                 dispVT(VT_preset_m*10,adj_x_pos,adj_y_pos);
                 Canvas_Image_Start_address(layer1_start_addr);							
							   Layer=3;
					       break;
				  		case 4:
								 LT768_PIP_Init( 1, 1, layer2_start_addr,  0,0, 1024, 100,100, 470, 350 );
								 setpeep_m=setpeep,Color1=White,Color2=Red;
							   Canvas_Image_Start_address(layer2_start_addr);
						     disp(setpeep_m,adj_x_pos,adj_y_pos);
                 Canvas_Image_Start_address(layer1_start_addr); 							
							   Layer=3;
					       break;
				      case 5: 
								 LT768_PIP_Init( 1, 1, layer2_start_addr,  0,0, 1024, 100,100, 470, 350 );
								 Pcontrol_m=Pcontrol,Color1=White,Color2=Red;
							   Canvas_Image_Start_address(layer2_start_addr);
						     disp(Pcontrol_m,adj_x_pos,adj_y_pos);	
                 Canvas_Image_Start_address(layer1_start_addr);						
								 Layer=3;
					       break;
						  case 6:
								 LT768_PIP_Init( 1, 1, layer2_start_addr,  0,0, 1024, 100,100, 470, 350 );
							   Rset100=1;
							   fristdown=0;
							   Canvas_Image_Start_address(layer2_start_addr);
							   LT768_DrawCircleSquare(LocationTab[4*Rset100+88]-4,LocationTab[4*Rset100+89]-4,LocationTab[4*Rset100+90]+4,LocationTab[4*Rset100+91]+4,10,10,Red);
                 Canvas_Image_Start_address(layer1_start_addr);							
								 Layer=3;
							   break;
						  case 7:
							   LT768_PIP_Init( 1, 1, layer2_start_addr,  0,0, 1024, 100,100, 470, 350 );
							   Rset100=1;
							   Canvas_Image_Start_address(layer2_start_addr);
                 LT768_DrawCircleSquare(LocationTab[4*Rset100+88]-4,LocationTab[4*Rset100+89]-4,LocationTab[4*Rset100+90]+4,LocationTab[4*Rset100+91]+4,10,10,Red);
                 Canvas_Image_Start_address(layer1_start_addr);		
								 Layer=3;
							   break;
						  case 8: 
								 LT768_PIP_Init( 1, 1, layer2_start_addr,  0,0, 1024, 100,100, 470, 350 );
							   Rset100=1;
								 Canvas_Image_Start_address(layer2_start_addr);
                 LT768_DrawCircleSquare(LocationTab[4*Rset100+88]-4,LocationTab[4*Rset100+89]-4,LocationTab[4*Rset100+90]+4,LocationTab[4*Rset100+91]+4,10,10,Red);
                 Canvas_Image_Start_address(layer1_start_addr);		
								 Layer=3;
						     break;
						  case 9:
								 LT768_PIP_Init( 1, 1, layer2_start_addr,  0,0, 1024, 100,100, 470, 350 );
							   Rset100=1;
								 Canvas_Image_Start_address(layer2_start_addr);
                 LT768_DrawCircleSquare(LocationTab[4*Rset100+88]-4,LocationTab[4*Rset100+89]-4,LocationTab[4*Rset100+90]+4,LocationTab[4*Rset100+91]+4,10,10,Red);
                 Canvas_Image_Start_address(layer1_start_addr);		
								 Layer=3;
					       break;
							case 10:            
								 SelectErase(Layer,Rset0);
								 Layer=1;
						     Disable_PIP2();
						 }
						break; 
					case 5: //Layer=2  system
						
					 	switch (Rset10)
				     { 
					    case 1:
								pv0=Pairway; //pv 0
			          WriteEE(1900,(uint8_t)(pv0 & 0x00ff));
                WriteEE(1901,(uint8_t)(pv0>>8));
			          Canvas_Image_Start_address(layer2_start_addr);
			          prt16D(740,560,pv0);
			          LT768_DrawCircleSquare( 20, 420, 89, 469,10,10,0xf00f);
			          Canvas_Image_Start_address(layer1_start_addr);	
					      break;
							case 2:	
								pv20=Pairway;
			          WriteEE(1902,(uint8_t)(pv20 & 0x00ff));
                WriteEE(1903,(uint8_t)(pv20>>8));
		           	Canvas_Image_Start_address(layer2_start_addr);
		          	prt16D(740,560,pv20);
			          LT768_DrawCircleSquare( 20, 500, 89, 549,10,10,0xf00f);
			          Canvas_Image_Start_address(layer1_start_addr);
					      break;
							case 3:	
								pvI0=Pinsp; //pvI 0
			          WriteEE(1904,(uint8_t)(pvI0 & 0x00ff));
                WriteEE(1905,(uint8_t)(pvI0>>8));
			          Canvas_Image_Start_address(layer2_start_addr);
			          prt16D(740,560,pv0);
		          	LT768_DrawCircleSquare(120, 420,189, 469,10,10,0xf00f);
			          Canvas_Image_Start_address(layer1_start_addr);
					      break;
							case 4:	
								pvI20=Pinsp;
			          WriteEE(1906,(uint8_t)(pvI20 & 0x00ff));
                WriteEE(1907,(uint8_t)(pvI20>>8));
		          	Canvas_Image_Start_address(layer2_start_addr);
		          	prt16D(740,560,pv0);
			          LT768_DrawCircleSquare(120, 500,189, 549,10,10,0xf00f);
			          Canvas_Image_Start_address(layer1_start_addr);	
					      break;
							case 5:	
								ox21=moxw;
			          WriteEE(1908,(uint8_t)(ox21 & 0x00ff));
                WriteEE(1909,(uint8_t)(ox21>>8));
			          Canvas_Image_Start_address(layer2_start_addr);
		            prt16D(740,560,pv0);
		          	LT768_DrawCircleSquare(220, 420,289, 469,10,10,0xf00f);
			          Canvas_Image_Start_address(layer1_start_addr);   
					      break;
							case 6:	 
								ox100=moxw;
			          WriteEE(1910,(uint8_t)(ox100 & 0x00ff));
                WriteEE(1911,(uint8_t)(ox100>>8));
		          	Canvas_Image_Start_address(layer2_start_addr);
		          	prt16D(740,560,pv0);
		          	LT768_DrawCircleSquare(220, 500,289, 549,10,10,0xf00f);
			          Canvas_Image_Start_address(layer1_start_addr);
					      break;
							case 7:	//V198 
			          baseV198=Vpower;
			          WriteEE(1912,(uint8_t)(ox21 & 0x00ff));
                WriteEE(1913,(uint8_t)(ox21>>8));
			          Canvas_Image_Start_address(layer2_start_addr);
			          prt16D(740,560,pv0);
			          LT768_DrawCircleSquare(320, 420,389, 469,10,10,0xf00f);
		          	Canvas_Image_Start_address(layer1_start_addr);
					      break;
							case 8:	
								baseV242=Vpower;
			          WriteEE(1914,(uint8_t)(ox100 & 0x00ff));
                WriteEE(1915,(uint8_t)(ox100>>8));
		          	Canvas_Image_Start_address(layer2_start_addr);
		          	prt16D(740,560,pv0);
		          	LT768_DrawCircleSquare(320, 500,389, 549,10,10,0xf00f);
		          	Canvas_Image_Start_address(layer1_start_addr);		
					      break;
							case 9:	 
								baseO280=PSO2;
			          WriteEE(1916,(uint8_t)(ox21 & 0x00ff));
                WriteEE(1917,(uint8_t)(ox21>>8));
			          Canvas_Image_Start_address(layer2_start_addr);
			          prt16D(740,560,pv0);
			          LT768_DrawCircleSquare(420, 420,489, 469,10,10,0xf00f);
			          Canvas_Image_Start_address(layer1_start_addr);
					      break;
							case 10:
								baseO600=PSO2;
			          WriteEE(1918,(uint8_t)(ox100 & 0x00ff));
                WriteEE(1919,(uint8_t)(ox100>>8));
			          Canvas_Image_Start_address(layer2_start_addr);
			          prt16D(740,560,pv0);
			          LT768_DrawCircleSquare(420, 500,489, 549,10,10,0xf00f);
			          Canvas_Image_Start_address(layer1_start_addr);		
					      break;
							case 11:	
								baseA280=PSair;
			          WriteEE(1920,(uint8_t)(ox21 & 0x00ff));
                WriteEE(1921,(uint8_t)(ox21>>8));
			          Canvas_Image_Start_address(layer2_start_addr);
		          	prt16D(740,560,pv0);
		            LT768_DrawCircleSquare(520, 420,589, 469,10,10,0xf00f);
			          Canvas_Image_Start_address(layer1_start_addr);
					      break;
							case 12:	
							  baseA600=PSair;
			          WriteEE(1922,(uint8_t)(ox100 & 0x00ff));
                WriteEE(1923,(uint8_t)(ox100>>8));
			          Canvas_Image_Start_address(layer2_start_addr);
			          prt16D(740,560,ox100);
			          LT768_DrawCircleSquare(520, 500,589, 549,10,10,0xf00f);
			          Canvas_Image_Start_address(layer1_start_addr);	
					      break;
							case 13:	
								kvt=VTw*1024/300;
			          WriteEE(1924,(uint8_t)(kvt & 0x00ff));
                WriteEE(1925,(uint8_t)(kvt>>8));
								Canvas_Image_Start_address(layer2_start_addr);
								LT768_DrawCircleSquare(620, 420,689, 469,10,10,0xf00f);
								Canvas_Image_Start_address(layer1_start_addr);  
					      break;
							case 14:	
								WriteEE(2040,0),WriteEE(2041,0),WriteEE(2042,0);
								Canvas_Image_Start_address(layer2_start_addr);
								LT768_DrawCircleSquare(620, 500,689, 549,10,10,0xf00f);
								Canvas_Image_Start_address(layer1_start_addr);							  
							  TIMER_DisableInt(TIMER1);
							  Disable_PIP1();
							  Layer=1;
							  LT768_PIP_Init( 1, 1, layer4_start_addr,    80,  60, 1024, 80, 60, 600, 540 );
							  Canvas_Image_Start_address(layer4_start_addr);
							  for (ibase=0;ibase<2000;ibase++)	standard[ibase]=0;
							  Color1=Yellow,Color2=Black;
							  for (ibase=1300;ibase<2900;ibase+=2)
								  {
						       EPWM_SET_CMR(EPWM0, 4, ibase);
									 for (i=0;i<16;i++ )
										{
											Delayms(50);
                      if (int16_flow>=0) uint32_temp+=int16_flow;
										}
                   uint32_temp=uint32_temp/16;
                   temp16=uint32_temp,prtx(630,440,temp16);
										prt16D(630,480,ibase);
                   standard[temp16]=ibase;										
                   Point(131+(ibase-1300)/4,569-temp16/3,Red);
									 Point(131+(ibase-1300)/4,569,Green);
										if (ibase>1600)
                       {
											   EPWM_SET_CMR(EPWM0, 4, 1300);
												 Delayms(800);
											 }
								  }
								EPWM_SET_CMR(EPWM0, 4, 1300);
									
								calip();				
								Canvas_Image_Start_address(layer1_start_addr);	
					      break;
							case 15:
                SYS_UnlockReg();		
								FMC_Open();		
								/* get Data Flash base address */
								u32addr = FMC_ReadDataFlashBaseAddr();	
								FMC_Erase(u32addr);  /*Supports 4 Kbytes page erase for all embedded Flash*/
								FMC_Erase(u32addr+4096);	
								for (i=0;i<1000;i++)
									{		
										u32data=standard[i*2]+standard[i*2]<<16;
										FMC_Write(u32addr, u32data);
									}
								FMC_Close();
								/* Lock protected registers */
								SYS_LockReg();								
								LT768_PIP_Init( 1, 1, layer5_start_addr,    80,  60, 1024, 80, 60, 600, 540 );
							  Canvas_Image_Start_address(layer5_start_addr);
							  
							  for (ibase=0;ibase<1500;ibase++)
								  {
						       
									 Point(131+ibase/3,569-(standard[ibase]-1300)/4,Red);	
								  }
								Canvas_Image_Start_address(layer1_start_addr);	
					      break;
							case 16:	 
					      Disable_PIP1();
							  Layer=1;
						 }
						 //cal=0;
						 break; 
					case 6:  ////Layer=2  Silence
					 		 
					   break;
					case 7:  ////Layer=2  adjTime
						 switch (Rset10)
				         { 
									case 1 :
											if (fristdown==0) fristdown=1;
											else fristdown=0;
											Canvas_Image_Start_address(layer2_start_addr);	
											Color1=Red,Color2=Blue2;
											dispmword(year0,540,40);
											Canvas_Image_Start_address(layer1_start_addr);
									    break;
									case 2:
											if (fristdown==0) fristdown=1;
											else fristdown=0;
											Color1=Red,Color2=Blue2;
											Canvas_Image_Start_address(layer2_start_addr);
											dispmword(month0,670,40);
											Canvas_Image_Start_address(layer1_start_addr);
											break;
									case 3 :
											if (fristdown==0) fristdown=1;
											else fristdown=0;
											Canvas_Image_Start_address(layer2_start_addr);
											Color1=Red,Color2=Blue2;
											dispmword(day0,800,40);	
											Canvas_Image_Start_address(layer1_start_addr);
											break;
									case 4:
											if (fristdown==0) fristdown=1;
											else fristdown=0;
											Canvas_Image_Start_address(layer2_start_addr);
											Color1=Red,Color2=Blue2;
											dispmword(hour0,540,100);	
											Canvas_Image_Start_address(layer1_start_addr);
											break;
									case 5:
											if (fristdown==0) fristdown=1;
											else fristdown=0;
											Canvas_Image_Start_address(layer2_start_addr);
											Color1=Red,Color2=Blue2;
											dispmword(minute0,670,100);
											Canvas_Image_Start_address(layer1_start_addr);
											break; 
									case 6:
											if (fristdown==0) fristdown=1;
											else fristdown=0;
											Canvas_Image_Start_address(layer2_start_addr);
											Color1=Red,Color2=Blue2;
											dispmword(second0,800,100);
											Canvas_Image_Start_address(layer1_start_addr);
											break;
									case 7:
											RTC_SetDate(2000+year0, month0, day0, RTC_SUNDAY);
											RTC_SetTime(hour0, minute0, second0, RTC_CLOCK_24, RTC_AM);
											Disable_PIP1();
											Layer=1;
										}
						 	 }		
				}	
     if (Layer==3 && keydown==1)	
		    {
				 keydown=0;
				 switch (Rset0)   
				   {
						case 4: //SET  Layer=3   Rset0 				
								Canvas_Image_Start_address(layer2_start_addr);
								LT768_DrawCircleSquare_Fill( 20+100,20,20+250,20+60,10,10,Red);
								Canvas_Image_Start_address(layer1_start_addr);
								switch (Rset10)
										{
											case 1:   //Rset10
												Color1=White;
												freq=freq_m;
												disp(freq,freq_x_pos,freq_y_pos); 
												freq_bk=freq;
												WriteEE(2001,freq_bk);
												compute(freq,dut); 
                        Disable_PIP1();
												Layer=2;									
												break;		 
											case 2:  //Rset10
												dutp=dutp_m,dut=dut_tab[dutp],Color1=White;
												xn=dut_x_pos,yn=dut_y_pos,bbx(dut);
												WriteEE(2002,dutp); 
												compute(freq,dut);
												Disable_PIP1();
												Layer=2;
												break;
											case 3:  //Rset10
												VT_preset=VT_preset_m ,Color1=White;
												if (VMode!=5)
														{
															dispVT(VT_preset*10,VTset_x_pos,VTset_y_pos);
														}
												WriteEE(2013,VT_preset);
												compute(freq,dut);		
												Disable_PIP1();
												Layer=2;		
												break;
											case 4:   //Rset10
												setpeep=setpeep_m,Color1=White;
												disp(setpeep,setpeep_x_pos,setpeep_y_pos);
												WriteEE(2012,setpeep);
												pwmPeep=setpeep*10+80;
												Disable_PIP1();
												Layer=2;
												break;
											case 5:  //Rset10
												Pcontrol=Pcontrol_m,Color1=White,Color2=Black;
												if (VMode==5)
													{
														disp(Pcontrol,Pcontrol_x_pos,Pcontrol_y_pos);
													}
												WriteEE(2017,Pcontrol);
												Disable_PIP1();
												Layer=2;	
												break;
											case 6:			//Rset10								
												switch (Rset100)
														{
															case 1:  //Rset100
																if (fristdown==0) 
														       {
															   		    fristdown=1;
																				ps_tr_m=ps_tr,Color1=White,Color2=Red;
																				Canvas_Image_Start_address(layer2_start_addr);
																				dispPN(ps_tr_m,adj_x_pos,adj_y_pos);
																				Canvas_Image_Start_address(layer1_start_addr);
																	  }
																	else
																	  {
																				fristdown=0;
																				ps_tr=ps_tr_m,Color1=White,Color2=Red;
																				Canvas_Image_Start_address(layer2_start_addr);
																				dispPN(ps_tr_m,adj_x_pos,adj_y_pos);
																				Canvas_Image_Start_address(layer1_start_addr);
																				WriteEE(2003,ps_tr);
																		}																			
																		break;
															case 2:   //Rset100
																		if (fristdown==0) 
														          {
																				fristdown=1;
																				flow_tr_m=flow_tr,Color1=White,Color2=Red;
																				Canvas_Image_Start_address(layer2_start_addr);
																				disp(flow_tr_m,adj_x_pos,adj_y_pos);
																				Canvas_Image_Start_address(layer1_start_addr);
														          }
																		else
																		  {
																				fristdown=0;
																				flow_tr=flow_tr_m,Color1=White,Color2=Red;
																				Canvas_Image_Start_address(layer2_start_addr);
																				disp(flow_tr_m,adj_x_pos,adj_y_pos);
																				Canvas_Image_Start_address(layer1_start_addr);
																				WriteEE(2018,flow_tr);
																			}
																			break;
															case 3:  //Rset100
																			SelectErase(Layer,Rset10);
																			Layer=2;
																			Disable_PIP1();
															case 4:
																			if (fristdown==0) 
														          {
																				fristdown=1;
																				if (Trig_sel) Trig_sel=0;
																				else  Trig_sel=1;
																	    }
																		else
																		  {
																				fristdown=0;
																				WriteEE(2019,Trig_sel);
																			}	
															 } 
													break;
											case 7:  //Rset10
													switch (Rset100)
															{
															 case 1: //Rset100
																	if (fristdown==0) 
														         {
																			fristdown=1;
																			ps_H_m=ps_H,Color1=White,Color2=Red;
																			Canvas_Image_Start_address(layer2_start_addr);
																			disp(ps_H_m,adj_x_pos,adj_y_pos);
																			Canvas_Image_Start_address(layer1_start_addr);
																			 }
																		else
																		  {
																				fristdown=0;
																				ps_H=ps_H_m,Color1=Red,Color2=Black;
																				disp_limit(ps_H,ps_H_x_pos,ps_H_y_pos);
																				WriteEE(2004,ps_H);
																			}
																			break;
															case 2:   //Rset100
																	if (fristdown==0) 
														         {
																			fristdown=1;
																			ps_L_m=ps_L,Color1=White,Color2=Red;
																			Canvas_Image_Start_address(layer2_start_addr);
																			disp(ps_L_m,adj_x_pos,adj_y_pos);
																			Canvas_Image_Start_address(layer1_start_addr);
																		 }
																		else
																		 {
																			fristdown=0;
																			ps_L=ps_L_m,Color1=Red,Color2=Black;
																			disp_limit(ps_L,ps_L_x_pos,ps_L_y_pos);
																			WriteEE(2005,ps_L);
																		 }
																		break;
																	case 3:  //Rset100
																			SelectErase(Layer,Rset10);
																			Layer=2;
																			Disable_PIP1();
														 }			
													break; 
											case 8:  //Rset10
													switch (Rset100)
															{
																case 1:  //Rset100
																	if (fristdown==0) 
														         {
																			fristdown=1;
																			VT_H_m=VT_H,Color1=White,Color2=Red;
																			Canvas_Image_Start_address(layer2_start_addr);
																			dispVT(VT_H_m*10,adj_x_pos,adj_y_pos);
																			Canvas_Image_Start_address(layer1_start_addr);
																	    }
																	else
																		 {
																			fristdown=0;
																			VT_H=VT_H_m,Color1=Red,Color2=Black;
																			dispVT_limit(VT_H*10,VTe_H_x_pos,VTe_H_y_pos);
																			WriteEE(2006,VT_H);
																		 }
																	break;
																case 2:  //Rset100
																	if (fristdown==0) 
														         {
																			fristdown=1;
																			VT_L_m=VT_L,Color1=White,Color2=Red;
																			Canvas_Image_Start_address(layer2_start_addr);
																			dispVT(VT_L_m*10,adj_x_pos,adj_y_pos);
																			Canvas_Image_Start_address(layer1_start_addr);
																	    }
																	else
																		 {
																			fristdown=0;
																			VT_L=VT_L_m,Color1=Red,Color2=Black;
																			dispVT_limit(VT_L*10,VTe_L_x_pos,VTe_L_y_pos);	
																			WriteEE(2007,VT_L);
																		 }
																			break;
																case 3: //Rset100
																			SelectErase(Layer,Rset10);
																			Layer=2;
																			Disable_PIP1();
														 }
													break; 
											case 9:		//Rset10	
													switch (Rset100)
															{  
																case 1:  //Rset100
																	if (fristdown==0) 
														         {
																			fristdown=1;
																			O2_H_m=O2_H,Color1=White,Color2=Red;
																			Canvas_Image_Start_address(layer2_start_addr);
																			disp(O2_H_m,ps_tr_x_pos,ps_tr_y_pos) ;
																			Canvas_Image_Start_address(layer1_start_addr);
																		 }
																else
																		 {
																			fristdown=0;
																			O2_H=O2_H_m,Color1=Red,Color2=Black;
															        disp_limit(O2_H,O2_H_x_pos,O2_H_y_pos);
															        WriteEE(2015,O2_H); 
																		 }
																	break;
																case 2:  //Rset100
																	if (fristdown==0) 
														         {
																			fristdown=1;
																			O2_L_m=O2_L,Color1=White,Color2=Red;
																			Canvas_Image_Start_address(layer2_start_addr);
																			disp(O2_L_m,ps_tr_x_pos,ps_tr_y_pos) ;
																			Canvas_Image_Start_address(layer1_start_addr);
																		 }
																	else
																		 {
																			fristdown=0;
																			O2_L=O2_L_m,Color1=Red,Color2=Black;
																			disp_limit(O2_L,O2_L_x_pos,O2_L_y_pos);					
																			WriteEE(2016,O2_L); 
																		 }
																	break;
															case 3:  //Rset100
																	SelectErase(Layer,Rset10);
																	Layer=2;
																	Disable_PIP1();
														}									
										if (Rset10<6)  					
												{ 
													Canvas_Image_Start_address(layer2_start_addr);
													LT768_DrawCircleSquare_Fill( 20+100,20,20+250,20+60,10,10,Red);
													Canvas_Image_Start_address(layer1_start_addr);						
													Layer=2;
													Disable_PIP1(); 
												}												
								}
					}			 
			}				
  PF3 ^=1;		
  if (onesec>150)	 Lock=1,MPU_Memory_Write_Window_8bit(800,10,Pic32x32,0,0xf720,Blue1);	
	}			 
}
/*---------------------------------------------*/
void SelectErase(uint8_t layer,uint8_t loc)
{
	uint8_t i;
if (layer==1)
   {
	    for ( i=1;i<8;i++) 
	       {
					 Color2=Black; 
					 if (i==7) Color2=0x0376;  
			     LT768_DrawCircleSquare(LocationTab[4*i+0]-4,LocationTab[4*i+1]-4,LocationTab[4*i+2]+4,LocationTab[4*i+3]+4,10,10,Color2);
			   }
	 }
else if (layer==2)
  {	
	 switch (loc)
		 {
			 case 1:  /*VMode */
					Canvas_Image_Start_address(layer2_start_addr);
	        for ( i=29;i<35;i++) 
	            {
			          LT768_DrawCircleSquare(LocationTab[4*i+0]-4,LocationTab[4*i+1]-4,LocationTab[4*i+2]+4,LocationTab[4*i+3]+4,10,10,Blue2);
			        }
					Canvas_Image_Start_address(layer1_start_addr);
					break;
			 case 2: /*Freeze */
								 
					break;
			 case 3: /*Record */
								 
					break;
			 case 4:
				  Canvas_Image_Start_address(layer3_start_addr);
	        for ( i=9;i<19;i++) 
	            {
			          LT768_DrawCircleSquare(LocationTab[4*i+0]-4,LocationTab[4*i+1]-4,LocationTab[4*i+2]+4,LocationTab[4*i+3]+4,10,10,Blue3);
			        }
					Canvas_Image_Start_address(layer1_start_addr);		
			    break;
			 case 5:
				  Canvas_Image_Start_address(layer2_start_addr);
	        for ( i=47;i<63;i++) 
	            {
			          LT768_DrawCircleSquare(LocationTab[4*i+0]-4,LocationTab[4*i+1]-4,LocationTab[4*i+2]+4,LocationTab[4*i+3]+4,10,10,0x0f1f);
			        }
					Canvas_Image_Start_address(layer1_start_addr);
				  break;
			 case 6: 
				  break;
			 case 7:
				Canvas_Image_Start_address(layer2_start_addr);
	        for ( i=39;i<47;i++) 
	            {
			          LT768_DrawCircleSquare(LocationTab[4*i+0]-4,LocationTab[4*i+1]-4,LocationTab[4*i+2]+4,LocationTab[4*i+3]+4,10,10,Blue2);
			        }
					Canvas_Image_Start_address(layer1_start_addr); 
		 }	
   }
else if (layer==3)
   {
	  Canvas_Image_Start_address(layer2_start_addr);
	  for ( i=23;i<29;i++) 
	       {
			    LT768_DrawCircleSquare(LocationTab[4*i+0]-4,LocationTab[4*i+1]-4,LocationTab[4*i+2]+4,LocationTab[4*i+3]+4,10,10,Blue2);
			   }
		Canvas_Image_Start_address(layer1_start_addr);
	 }	 
}

/*---------------------------------------------*/
void Record(void)   //��־
{ 

	Color1=White,Color2=Black;
	//prt8(0,100,3);

apt=0;
}
/*---------------------------------------------*/
void KeyLock(void)   //��
{
	Color1=White,Color2=Black;
	//Set_g_pres_L;//prt8(0,100,4);
	onesec=0;
	Lock=0; 
	MPU_Memory_Write_Window_8bit(800,10,Pic32x32,1,0xf720,Blue1);
}	
/*---------------------------------------------*/
void Plus(void)  // ��
{

}	

/*---------------------------------------------*/
void Minus(void)  //��
{

}
/*---------------------------------------------*/
void Kenter(void)    //ȷ��
{

}
/*---------------------------------------------*/
void SUBKset(void)	 //����
{
if (Lock==0)
  { 	
		onesec=0;	
		Color1=White,Color2=Black;
	  //prt8(0,100,7);
	  if (mloop==1) 
	    {
				Disable_PIP1();
			  show_set_date(),dateadj=1;  //date
	    }
    else
	    {
			spsd=0;
			set0=1;
      Color1=Black,Color2=Black;
      if (sps_sy!=0) flashm(sps_sy,0);
      if (sps_sy<10) sps_sy++;
      if (sps_sy>=10) sps_sy=1;
      Color1=Green,Color2=Black;
      flashm(sps_sy,0);
	    }
count1=0; 
	}		
apt=0; 	
}	
/*---------------------------------------------*/
void Modek(void)   //ģʽ
{
if (Lock==0)
  {
	onesec=0;		
	Color1=White,Color2=Black;
	//prt8(0,100,7);
	if (VMode==2)
	   {sigh();}
	else if (VMode==3)	
	   {simv();}	
  else if (VMode==4)	
	   {PCV();}	
  else if (VMode==5)	
	   {a_c();} 	 
  }	
apt=0; 	
}
/*---------------------------------------------*/
void Compensate(void)	   //���� 
{
	Color1=White,Color2=Black;
	//prt8(0,100,11);
}	
///////////////////////////////////////
void srg(void)
{ uint8_t is; 
	for (is=0;is<8;is++)
    {
			tgraph(is,dateQ);
      if (dateQ>0) dateQ--;
      else         dateQ=199;
   }
}
///////////////////////////////////////
void tgraph(uint8_t n,uint8_t adr)
{
	uint8_t mdate,temp,rw,mw,lw;
	Canvas_Image_Start_address(layer3_start_addr);				
if (dateP>=dateQ) mdate=dateP-dateQ;
else    mdate=200-dateQ+dateP;   
if (mdate>99)
   {
		lw=mdate/100;
    temp=mdate%100;
    }
else
   {
	  lw=0;
    temp=mdate;
   }
mw=temp/10;
rw=temp%10;
MPU_Memory_Write_Window_8bit(dateRecord_x+12,dateRecord_y+10+35*n,sdn,lw,White,Blue3);
MPU_Memory_Write_Window_8bit(dateRecord_x+20,dateRecord_y+10+35*n,sdn,mw,White,Blue3);
MPU_Memory_Write_Window_8bit(dateRecord_x+28,dateRecord_y+10+35*n,sdn,rw,White,Blue3);
			
}
/*---------------------------------------------*/	 
void Silence(void)
{	

}
/*--------------------------------------*/
void flashm(uint8_t num,uint8_t b)
{
  xn=tabm[2*num],	yn=tabm[2*num+1];  
  if (b==0)      MPU_Memory_Write_Window_8bit(xn,yn,LCD24,34,Color1,Color2);
  else if (b==1) MPU_Memory_Write_Window_8bit(xn,yn,LCD24,32,Color1,Color2);
  else           MPU_Memory_Write_Window_8bit(xn,yn,LCD24,35,Color1,Color2);	
}

/*---------------------------------------------*/
void show_hiter(void)
{ 
	
}
/*---------------------------------------------*/
void Number_enter(void)
{
	Canvas_Image_Start_address(layer1_start_addr);
 if (SYSTEM0==1)
    {
			if (P==1568) 
			   {
					 SYSTEM1=1;
					 CaliplierZ();
				 }
		}	 
}
/*---------------------------------------------*/
void CaliplierZ(void)
{	
	int8_t ia,ja;
  Canvas_Image_Start_address(layer2_start_addr);
	//LT768_DrawCircleSquare_Fill( 20+220,20,20+340,20+50,10,10,0x0806);
	for (ia=0;ia<7;ia++)
			{ 
				for (ja=0;ja<2;ja++)
			  LT768_DrawCircleSquare( 20+ia*100, 420+ja*80, 89+ia*100, 469+ja*80,10,10,0x3f80);
	    }
	Canvas_Image_Start_address(layer1_start_addr);
	LT768_PIP_Init
			(
				1,            // 0 : ��ֹ PIP    1 : ʹ�� PIP    2 : ����ԭ����״̬
				1,            // 1 : ʹ�� PIP1   2 : ʹ�� PIP2
				1024*600*2,    // PIP�Ŀ�ʼ��ַ
				0,            // PIP���ڵ�X����,���뱻4����
				400,            // PIP���ڵ�Y����,���뱻4����
				1024,          // ��ͼ�Ŀ��� 
				40,          // ��ʾ���ڵ�X����
				200,           // ��ʾ���ڵ�Y����
				800,          // ��ʾ���ڵĿ��ȣ����뱻4����
				180           // ��ʾ���ڵĸ߶ȣ����뱻4����
			);
							
}							
/*---------------------------------------------*/
void show_sys(void)
{
 Canvas_Image_Start_address(layer2_start_addr); 
 LT768_DrawSquare_Fill(840,20,960,70,Blue2);
 	
 Canvas_Image_Start_address(layer1_start_addr);
 LT768_PIP_Init( 1, 2, 1024*600*4,   600,  0, 1024, 140, 68, 420, 340 );
 SYSTEM0=1;
 	
}	
/*---------------------------------------------*/
void show_caliper(void)
{
	LT768_PIP_Init( 1, 1,  1024*600*2,  500,  200, 1024, 300, 200, 300, 160);
	longkey=0;
	calipery=1;
}	
/*---------------------------------------------*/
void show_date(void)
{	
   //S_RTC_TIME_DATA_T sWriteRTC, sReadRTC;
   if(g_u32RTCTickINT == 1)
        {
            g_u32RTCTickINT = 0;

            /* Read current RTC date/time */
            RTC_GetDateAndTime(&sReadRTC);
					  
            if(u8IsNewDateTime == 0)
              {  	
                dispdate_time(620,10);
              }
            
            /*if(u32Sec == sReadRTC.u32Second)
            {
                printf("\nRTC tick period time is incorrect.\n");
                while(1);
            }

            u32Sec = sReadRTC.u32Second; */

           /* if(u8IsNewDateTime == 0)
            {
                if(u32Sec == (sWriteRTC.u32Second + 5))
                {                  
                    u8IsNewDateTime = 1;
                    RTC_SetDate(2020, 5, 15, RTC_SUNDAY);
                    RTC_SetTime(15, 30, 30, RTC_CLOCK_24, RTC_AM);
                }
            } */
        }
}
void show_set_date(void)
{LT768_PIP_Init
  (
 1,            // 0 : ��ֹ PIP    1 : ʹ�� PIP    2 : ����ԭ����״̬
 1,            // 1 : ʹ�� PIP1   2 : ʹ�� PIP2
 1024*600*2,    // PIP�Ŀ�ʼ��ַ
 512,          // PIP���ڵ�X����,���뱻4����
 0,            // PIP���ڵ�Y����,���뱻4����
 1024,          // ��ͼ�Ŀ��� 
 492,          // ��ʾ���ڵ�X����
 80,           // ��ʾ���ڵ�Y����
 360,          // ��ʾ���ڵĿ��ȣ����뱻4����
 200           // ��ʾ���ڵĳ��ȣ����뱻4����
  );
 Canvas_Image_Start_address(layer2_start_addr);
	year0=sReadRTC.u32Year % 2000;
  month0=sReadRTC.u32Month;
	day0=sReadRTC.u32Day;
  hour0=sReadRTC.u32Hour;
  minute0=sReadRTC.u32Minute;
  second0=sReadRTC.u32Second;
	Color1=Red,Color2=Blue2;
	dispmword(year0,540,40);
	dispmword(month0,670,40);
	dispmword(day0,800,40);
	dispmword(hour0,540,100);
	dispmword(minute0,670,100);
	dispmword(second0,800,100);
 Canvas_Image_Start_address(layer1_start_addr);
}
/*---------------------------------------------*/
void show_freq(void)
{ 
 
}
/*---------------------------------------------*/
void show_ratio(void)
{
	
}
/*---------------------------------------------*/	
void show_tig_P(void)
{ 
 
}
/*---------------------------------------------*/
void show_P_H(void)
{ 
 
}
/*---------------------------------------------*/
void show_P_L(void)
{
}
/*---------------------------------------------*/
void show_VT_H(void)
{
	
}
/*---------------------------------------------*/
void show_VT_L(void)
{
	
}
	/*---------------------------------------------*/
void show_O2_H(void)
{
}
/*---------------------------------------------*/
void show_O2_L(void)
{
}	
/*---------------------------------------------*/	
void show_mode(void)	
{
	LT768_PIP_Init
  (
 1,            // 0 : ��ֹ PIP    1 : ʹ�� PIP    2 : ����ԭ����״̬
 1,            // 1 : ʹ�� PIP1   2 : ʹ�� PIP2
 1024*600*2,    // PIP�Ŀ�ʼ��ַ
 500,            // PIP���ڵ�X����,���뱻4����
 200,            // PIP���ڵ�Y����,���뱻4����
 1024,          // ��ͼ�Ŀ��� 
 200,           // ��ʾ���ڵ�X����
 64,          // ��ʾ���ڵ�Y����
 400,          // ��ʾ���ڵĿ��ȣ����뱻4����
 200           // ��ʾ���ڵĳ��ȣ����뱻4����
  );
}
/*---------------------------------------------*/
void frozen(void)
{
uint16_t ie;	
if (frz) frz=0;
else frz=1;
for (ie=0;ie<409;ie++)	
	  { Color1=White,Color2=Black;
			//prthxd(50+(ie%16)*36,60+ie/16*16,standard[ie]);
			//if (standard[ie]>base) Point(340+standard[ie]/10,ie,Red);
     // else 		Point(340+standard[ie]/10,ie,Green);
		} 
	//caliperX();
}
/*---------------------------------------------*/	
void mode1(void)
{
	Disable_PIP1();
	a_c();
}
/*---------------------------------------------*/	
void mode2(void)
{ 
	Disable_PIP1();
	sigh();
}
/*---------------------------------------------*/	
void mode3(void)
{
	Disable_PIP1();
	simv();
}
/*---------------------------------------------*/	
void mode4(void)
{ 
	Disable_PIP1();
	PCV();
}
/*---------------------------------------------*/	
void mode5(void)
{
	//MPU_Memory_Write_Window_8bit(MODE_pos,10,mode,5,White,0x0376);
	Disable_PIP1();
}
/*---------------------------------------------*/	
void mode6(void)
{ //MPU_Memory_Write_Window_8bit(MODE_pos,10,mode,3,White,0x0376);
	Disable_PIP1();
}
/*---------------------------------------------*/
uint8_t hit(uint16_t x,uint16_t y,const uint16_t *cont)
{   if (x>=cont[0] && x <cont[2] && y>=cont[1] && y<cont[3] ) return 1;
    else  return 0;
}
/*---------------------------------------------*/	 
void dateplus(void)
{
switch(date_sps) {
case 1 : 
  if (year0<40 )   year0++ ;
  Canvas_Image_Start_address(layer2_start_addr);	
	Color1=Red,Color2=Blue2;
	dispmword(year0,540,40);
  Canvas_Image_Start_address(layer1_start_addr);
  break;
case 2:
  if (month0<12)  month0++ ;
  Color1=Red,Color2=Blue2;
  Canvas_Image_Start_address(layer2_start_addr);
  dispmword(month0,670,40);
  Canvas_Image_Start_address(layer1_start_addr);
  break;
case 3 :
  if (day0<31)   day0++;
  Canvas_Image_Start_address(layer2_start_addr);
  Color1=Red,Color2=Blue2;
  dispmword(day0,800,40);	
  Canvas_Image_Start_address(layer1_start_addr);
  break;
case 4:
  if (hour0<23)  hour0++;
  Canvas_Image_Start_address(layer2_start_addr);
  Color1=Red,Color2=Blue2;
  dispmword(hour0,540,100);	
  Canvas_Image_Start_address(layer1_start_addr);
  break;
case 5:
	if (minute0<59)  minute0++;
  Canvas_Image_Start_address(layer2_start_addr);
  Color1=Red,Color2=Blue2;
  dispmword(minute0,670,100);
  Canvas_Image_Start_address(layer1_start_addr);
   break; 
case 6:
  if (second0<59)  second0++;
  Canvas_Image_Start_address(layer2_start_addr);
  Color1=Red,Color2=Blue2;
	dispmword(second0,800,100);
  Canvas_Image_Start_address(layer1_start_addr);
  }

}	
/*---------------------------------------------*/	 
void dateminus(void)
{
switch(date_sps) {
case 1 : 
  if (year0>20 ) year0-- ;
  Canvas_Image_Start_address(layer2_start_addr);	
	Color1=Red,Color2=Blue2;
	dispmword(year0,540,40);
  Canvas_Image_Start_address(layer1_start_addr);
  break;
case 2:
  if (month0>1)  month0-- ;
  Canvas_Image_Start_address(layer2_start_addr);
  Color1=Red,Color2=Blue2;
  dispmword(month0,670,40);
  Canvas_Image_Start_address(layer1_start_addr);
  break;
case 3 :
  if (day0>1)   day0--;
  Canvas_Image_Start_address(layer2_start_addr);
  Color1=Red,Color2=Blue2;
  dispmword(day0,800,40);	
  Canvas_Image_Start_address(layer1_start_addr);
  break;
case 4:
  if (hour0>1)  hour0--;
  Canvas_Image_Start_address(layer2_start_addr);
  Color1=Red,Color2=Blue2;
  dispmword(hour0,540,100);	
  Canvas_Image_Start_address(layer1_start_addr);
  break;
case 5:
	if (minute0>1) minute0--;
  Canvas_Image_Start_address(layer2_start_addr);
  Color1=Red,Color2=Blue2;
  dispmword(minute0,670,100);
  Canvas_Image_Start_address(layer1_start_addr);
   break; 
case 6:
  if (second0>1)  second0--;
  Canvas_Image_Start_address(layer2_start_addr);
  Color1=Red,Color2=Blue2;
	dispmword(second0,800,100);
  Canvas_Image_Start_address(layer1_start_addr);
  }
}	

/*---------------------------------------------*/
void Manual(void)                               
{      
   sigauto=1;   
	 pwmo=1,pwmx=1;
	 TIMER_DisableInt(TIMER1);
   //TIMER_Stop(TIMER1);
	 EPWM_DisableOutput(EPWM0, EPWM_CH_0_MASK); 
   EPWM_DisableOutput(EPWM0, EPWM_CH_4_MASK);
   MPU_Memory_Write_Window_8bit(MODE_x_pos,MODE_y_pos,mode,7,White,Blue1);
	
	 MPU_Memory_Write_Window_8bit(freq_x_pos,freq_y_pos,image,12,White,Black);
	 MPU_Memory_Write_Window_8bit(freq_x_pos+32,freq_y_pos,image,12,White,Black);
	 MPU_Memory_Write_Window_8bit(dut_x_pos,dut_y_pos,image,12,White,Black);
	 MPU_Memory_Write_Window_8bit(dut_x_pos+32,dut_y_pos,image,12,White,Black);
   aseco=0;
	 //ps=0;
	 set0=0;
	 sps=0;
	 Disable_PIP1();
	 //c1=White,c2=0,dispm(VT_preset,680,540);
}  
//****************************************************
void IPPV(void)
{  VMode=1;
	 sigauto=2;
	 TIMER_EnableInt(TIMER1);
   TIMER_Start(TIMER1);
	 EPWM_EnableOutput(EPWM0, EPWM_CH_0_MASK); 
   EPWM_EnableOutput(EPWM0, EPWM_CH_4_MASK);
	 LT768_DrawSquare_Fill(700,510,820,590,Black);
   Color1=White,Color2=Black;
   disp(freq,freq_x_pos,freq_y_pos);
	 Color1=White,Color2=Black;
	 xn=dut_x_pos,yn=dut_y_pos;
	 bbx(dut);
   
   dispVT(VT_preset*10,VTset_x_pos,VTset_y_pos);
   pwmo=0,pwmx=0;
   sighEN=0;   
   
   compute(freq,dut);
   MPU_Memory_Write_Window_8bit(MODE_x_pos,MODE_y_pos,mode,8,White,Blue1); 
   Color1=0xf365,Color2=0x07ff;
   dispchar24(92,94); 
	 Color1=0x07ff,Color2=Black;
   dispnumber(81,82,0);
   aseco=0;
 }  
//****************************************************
void a_c(void)
{  
   VMode=2;
   sigauto=3;
	 //TIMER_Start(TIMER1);
   pwmo=0,pwmx=0;
   aseco=0;
   sighEN=0;
   MPU_Memory_Write_Window_8bit(MODE_x_pos,MODE_y_pos,mode,0,White,0x0376);
   //init_p();
   ps5=0;
   compute(freq,dut);
	 LT768_DrawSquare_Fill(700,510,820,590,Black);
   Color1=0xf365,Color2=0x07ff;
   dispchar24(92,94);
   Color1=0x07ff,Color2=Black;
   dispnumber(81,82,0);
   Color1=White,Color2=Black;
	 dispVT(VT_preset*10,VTset_x_pos,VTset_y_pos);	
 // 
}   
//****************************************************
void sigh(void)
 { 
   VMode=3;
   sigauto=4;
   //TIMER_EnableInt(TIMER1);
	 //TIMER_Start(TIMER1);  
	 pwmo=0,pwmx=0;
   //init_p();
   //aseco=0;
   sighEN=1;
   sighcnt=0;
   MPU_Memory_Write_Window_8bit(MODE_x_pos,MODE_y_pos,mode,1,White,0x0376);
   ps5=0;
   compute(freq,dut);
	 LT768_DrawSquare_Fill(700,510,820,590,Black);
   Color1=0xf365,Color2=0x07ff;
   dispchar24(92,94); 
	 Color1=0x07ff,Color2=Black;
   dispnumber(81,82,0);
   Color1=White,Color2=Black;
	 dispVT(VT_preset*10,VTset_x_pos,VTset_y_pos);     
 } 
//****************************************************
void simv(void)
 { 
   VMode=4;
   sigauto=5;
   //init_p();
   //TIMER_EnableInt(TIMER1);
	 //TIMER_Start(TIMER1);
	 pwmo=0,pwmx=0 ;
   sighEN=0;
   MPU_Memory_Write_Window_8bit(MODE_x_pos,MODE_y_pos,mode,2,White,0x0376);
   ps5=0;
   compute(freq,dut);
	 LT768_DrawSquare_Fill(700,510,820,590,Black);
   Color1=0xf365,Color2=0x07ff;
   dispchar24(92,94);
	 Color1=0x07ff,Color2=Black;
   dispnumber(81,82,0);
   Color1=White,Color2=Black;
	 dispVT(VT_preset*10,VTset_x_pos,VTset_y_pos);	 
 }
//'****************************************************
void PCV(void)
{  
	 VMode=5;
   sigauto=6;
	 pwmo=0,pwmx=0;
   sighEN=0;
	 MPU_Memory_Write_Window_8bit(MODE_x_pos,MODE_y_pos,mode,6,White,0x0376);
	 LT768_DrawSquare_Fill(700,510,820,590,Black);
	 Color1=0xf365,Color2=0x07ff;
   dispchar24(143,146);
   Color1=0x07ff,Color2=Black;
   dispnumber(89,91,0);
	 Color1=White,Color2=Black;
   disp(Pcontrol,Pcontrol_x_pos,Pcontrol_y_pos);
	 Compliasnce=100;
	 SumErr0Pplatfrom=0;
}
//'****************************************************
void PSV(void)
{  VMode=6;
   sigauto=7;
	 pwmo=0,pwmx=0;
   sighEN=0;
	 LT768_DrawSquare_Fill(700,510,820,590,Black);
	 Color1=0xf365,Color2=0x07ff;
   dispchar24(143,146);
   Color1=0x07ff,Color2=Black;
   dispnumber(89,91,0);
	 Color1=White,Color2=Black;
   disp(Pcontrol,Pcontrol_x_pos,Pcontrol_y_pos);
	 Compliasnce=100;
}

//****************************************************
void spont(void)
 { 
   VMode=7;
	 sigauto=8;
	 //TIMER_DisableInt(TIMER1);
   //TIMER_Stop(TIMER1);
	 pwmo=0,pwmx=0 ;
   sighEN=0; 
   MPU_Memory_Write_Window_8bit(MODE_x_pos,MODE_y_pos,mode,4,White,0x0376);
   aseco=0;
 }
//****************************************************
void BKV(void) //bak
{
	ps_bk=1;
  psbk=VMode;
  bfreq=freq;
  bdut=dut;
  //TIMER_EnableInt(TIMER1);
	//TIMER_Start(TIMER1);//
  VMode=0;
  freq=12;
  dut=0x12;
  compute(freq,dut);
  Color1=White,Color2=Black;
  disp(freq,freq_x_pos,freq_y_pos);
  xn=dut_x_pos,yn=dut_y_pos;
  bbx(dut);
  sighEN=0;
  //pwmhl=0;
  MPU_Memory_Write_Window_8bit(MODE_x_pos,MODE_y_pos,mode,3,White,0x0376);  
}

/*---------------------------------------------*/
void sou(void)
{ 
 if	(clrspk)
    {
		  if (spk==0)
		   { 
        //alarm=0;
				PE12=0,PE13=0; 
       }
    else
	     { 
			 if (spk & g_pres_H) PE12=0,PE13=1;//alarm=2;
       else  PE12=1,PE13=0;//alarm=1;
		   }
		}
 else
   {	 
    PE12=0,PE13=0;//alarm=0;
	 } 
 if (seco>2400) 
  	{ 
	    Color1=Green1,xy_(); /* erse();*/
			clrspk=1;
    }
}
/*---------------------------------------------*/
void scale1(void)
{
uint16_t i;	
const uint16_t OrgX=130;	
const uint16_t OrgY=70;
const uint16_t offsetYa=150;
const uint16_t offsetYb=175;
const uint16_t offsetX=500;	
LT768_DrawSquare_Fill(0,0,159,50,0x0376);
LT768_DrawSquare_Fill(160,0,579,50,0x03c0);
LT768_DrawSquare_Fill(580,0,1023,50,0x0376);
	
Lines(OrgX,OrgY+offsetYb*0+offsetYa,OrgX+offsetX,OrgY+offsetYb*0+offsetYa,White); //H
Lines(OrgX,OrgY+offsetYb*1+offsetYa,OrgX+offsetX,OrgY+offsetYb*1+offsetYa,White); //H	
Lines(OrgX,OrgY+offsetYb*2+offsetYa,OrgX+offsetX,OrgY+offsetYb*2+offsetYa,White); //H
for(i=0;i<=500; i=i+50)
  {
   Point(OrgX+i,OrgY+offsetYb*0+offsetYa+1,White);
   Point(OrgX+i,OrgY+offsetYb*0+offsetYa+2,White);	

   Point(OrgX+i,OrgY+offsetYb*1+offsetYa+1,White);
   Point(OrgX+i,OrgY+offsetYb*1+offsetYa+2,White);
	
   Point(OrgX+i,OrgY+offsetYb*2+offsetYa+1,White);
   Point(OrgX+i,OrgY+offsetYb*2+offsetYa+2,White);	
  }

Lines(OrgX,OrgY+offsetYb*0,OrgX,OrgY+offsetYb*0+offsetYa,White);  //V
Lines(OrgX,OrgY+offsetYb*1,OrgX,OrgY+offsetYb*1+offsetYa,White);  //V
Lines(OrgX,OrgY+offsetYb*2,OrgX,OrgY+offsetYb*2+offsetYa,White);  //V
for(i=0;i<=150; i=i+25)
  {
   Point(OrgX-1,OrgY+offsetYb*0+i,White);
   Point(OrgX-2,OrgY+offsetYb*0+i,White);	

   Point(OrgX-1,OrgY+offsetYb*1+i,White);
   Point(OrgX-2,OrgY+offsetYb*1+i,White);

   Point(OrgX-1,OrgY+offsetYb*2+i,White);
   Point(OrgX-2,OrgY+offsetYb*2+i,White);	
  }	
Color1=0x07ff,Color2=Black;
dispnumber(0,17,0);
dispnumber(0,17,offsetYb);
dispnumber(0,17,offsetYb*2);
dispnumber(18,85,0);
Color1=0xf365,Color2=0x07ff;
dispchar24(51,98);
scal_P=3,scal_F=3,scal_V=3;
Color1=White,Color2=Black;
disp(Ppeak,Ppeak_x_pos,Ppeak_y_pos);
disp(Pplatfrom,Pplatfrom_x_pos,Pplatfrom_y_pos);
disp(Paverage,Paverage_x_pos,Paverage_y_pos);
disp(peep,peep_x_pos,peep_y_pos);
disp(setpeep,setpeep_x_pos,setpeep_y_pos);
Color1=White,Color2=Black;
//disp(freq,freq_x_pos,freq_y_pos);
Color1=White,Color2=Black;
xn=dut_x_pos,yn=dut_y_pos;
//bbx(dut);
Color1=Red,Color2=Black;
disp_limit(ps_H,ps_H_x_pos,ps_H_y_pos);					
disp_limit(ps_L,ps_L_x_pos,ps_L_y_pos);			
Color1=Red,Color2=Black;
dispVT_limit(VT_H*10,VTe_H_x_pos,VTe_H_y_pos);
dispVT_limit(VT_L*10,VTe_L_x_pos,VTe_L_y_pos);							
Color1=Red,Color2=Black;
disp_limit(O2_H,O2_H_x_pos,O2_H_y_pos);
disp_limit(O2_L,O2_L_x_pos,O2_L_y_pos);

LT768_DrawCircleSquare_Fill(LocationTab[4],LocationTab[5],LocationTab[6],LocationTab[7],10,10,0x70f6);
MPU_Memory_Write_Window_8bit(15,90,Bmp64x24,11,Green,0x70f6);

LT768_DrawCircleSquare_Fill(LocationTab[8],LocationTab[9],LocationTab[10],LocationTab[11],10,10,0x70f6);
MPU_Memory_Write_Window_8bit(15,180,Bmp64x24,8,Green,0x70f6);

LT768_DrawCircleSquare_Fill(LocationTab[12],LocationTab[13],LocationTab[14],LocationTab[15],10,10,0x70f6);
MPU_Memory_Write_Window_8bit(15,270,Bmp64x24,9,Green,0x70f6);

LT768_DrawCircleSquare_Fill(LocationTab[16],LocationTab[17],LocationTab[18],LocationTab[19],10,10,0x70f6);
MPU_Memory_Write_Window_8bit(15,360,Bmp64x24,10,Green,0x70f6);

LT768_DrawCircleSquare_Fill(LocationTab[20],LocationTab[21],LocationTab[22],LocationTab[23],10,10,0x70f6);
MPU_Memory_Write_Window_8bit(15,450,Bmp64x24,7,Yellow,0x70f6);

LT768_DrawCircleSquare_Fill(LocationTab[24],LocationTab[25],LocationTab[26],LocationTab[27],10,10,0x70f6);
MPU_Memory_Write_Window_8bit(15,540,Bmp64x24,12,Green,0x70f6);

Canvas_Image_Start_address(layer2_start_addr);
MPU_Memory_Write_Window_8bit(530, 230,mode,0,White,0x808f);
MPU_Memory_Write_Window_8bit(660, 230,mode,1,White,0x808f);
MPU_Memory_Write_Window_8bit(790, 230,mode,2,White,0x808f);
MPU_Memory_Write_Window_8bit(530, 330,mode,6,White,0x808f);
//MPU_Memory_Write_Window_8bit(660,330,mode,4,White,0x808f);
//MPU_Memory_Write_Window_8bit(790,330,mode,5,White,0x808f);
Canvas_Image_Start_address(layer3_start_addr);
LT768_DrawSquare_Fill(800,350,1023,599,Black);
Color1=0xf365,Color2=0x07ff;
dispchar24(139,142); /*��Сѹ��139-142*/
Color1=0x07ff,Color2=Black;
dispnumber(86,88,0);
Canvas_Image_Start_address(layer1_start_addr);
}	
/*--------------------------------------------------*/
void dispchar32(uint16_t k1,uint16_t k2)
{  uint16_t rz,rx,xp,yp;
   for (rz=k1; rz<=k2;rz++)
     { 
	    	xp=tab[3*rz],yp=tab[3*rz+1],rx=tab[3*rz+2];
        MPU_Memory_Write_Window_8bit(xp,yp,LCD32,rx,Color1,Color2);
     }
}
/*--------------------------------------------------*/
void dispchar24(uint16_t k1,uint16_t k2)
{  uint16_t rz,rx,xp,yp;
   for (rz=k1; rz<=k2;rz++)
     { 
	    	xp=tabs[3*rz],yp=tabs[3*rz+1],rx=tabs[3*rz+2];
        MPU_Memory_Write_Window_8bit(xp,yp,LCD24,rx,Color1,Color2);
     }
}
/*--------------------------------------------------*/
void dispnumber(uint16_t k1,uint16_t k2,uint16_t yoffset)
{  uint16_t rz,rx,xp,yp;
   for (rz=k1; rz<=k2;rz++)
     { 
	    	xp=tab[3*rz],yp=tab[3*rz+1],rx=tab[3*rz+2];
        MPU_Memory_Write_Window_8bit(xp,yp+yoffset,sdn,rx,Color1,Color2);
     }
}	
/*--------------------------------------------------*/
void det(void)
{	 
 if (g_adct)
    { 
			g_adct=0;
			
			int16_flow_s=int16_flow/12;
			int16_flowDisp=int16_flow/5/scal_F;
			
			int32_temp=int32Volume/36;
			int16_Volume=int32_temp;
			int16_VolumeDisp=int16_Volume/4/scal_V;
			
			/*switch(scal_P) {
        case 1 :
					int32_Vp=(Pairway-pv0)*100/(pv20-pv0);
				  Vp=int32_Vp/5;
				  break;
				case 2 :					
					int32_Vp=(Pairway-pv0)*50/(pv20-pv0);
				  Vp=int32_Vp*2/5;
				  break;
        case 3 :
					int32_Vp=(Pairway-pv0)*100/3/(pv20-pv0);
					Vp=int32_Vp*3/5;
				}  */
			int32_Vp10=(Pairway-pv0)*200/(pv20-pv0);
      if (int32_Vp10>0) Vps10=int32_Vp10;	
			else Vps10=0;			
			int32_Vp=(Pairway-pv0)*100/(scal_P*(pv20-pv0));
			Vp=int32_Vp*scal_P/5;
			if (Vp>0) Vps=Vp;	
			else Vps=0;
			
      Color1=Red,Color2=Black,prt16D(850,80,Pairway);				
			if (Vps>10) 
					{
					if (xxx<305)  xxx++;
					}
			else 
					{
						xxx=0;
						Reset_g_Cpres_H;
						Fills(358,4,422,20,Green1);
					} 
			if (xxx>300)  
				 {
					if ((spk & g_Cpres_H)==0 && clrspk==0) 
						 {
							Color1=0x1f,Color2=Green1;
							xy_();
						 }
					if ((spk & g_Cpres_H)==0) 
						 {
							 clrspk=1;
							 alarms(6);
					   }
					Set_g_Cpres_H;   
				 }
			 if (Vps>=max) max=Vps;
			 if (Vps<=min)  min=Vps;
			 if (max-min<2) 
					{
					if (yyy<305)  yyy++;
					}	 
			 else
					{
						yyy=0,min=10,max=0;
						Reset_g_choke,Fills(170,28,218,52,Green1);//
					}
			 if (yyy>300) 
					{
						if ((spk & g_choke)==0 && clrspk==0) 
								{
									Color1=0x1f,Color2=Green1;
									xy_();
								}
						if ((spk & g_choke)==0)
								{
									clrspk=1,Color1=White,Color2=Green1,alarms(15);
								}
						Set_g_choke;
					}
			 if (sigauto==1)		
					{
						mountb=mount,mount=0;
						if (Vps>2)  mount=1;
						if (mountb==1 && mount==0) 
								{
									open_g=1,pwmst=1;
								}
           
						if (open_g==1)
								{
									open_g=0,Ppeak=peak_m,peak_m=Vps;
									//VTw=TIMER_GetCounter(TIMER2);
									Color1=0xffff,Color2=Black;
									disp(Ppeak,Ppeak_x_pos,Ppeak_y_pos);			
									dispc();
								}
						else
								{
									if (Vps>peak_m)  peak_m=Vps;
								}
					 }	 
				else
					{
						if (open_g==1)
								{
									open_g=0;
									Ppeak=peak_m,peak_m=Vps;   //��ֵ
									Vp_trough=Vp_m,Vp_m=Vp;  //��ֵ
									flow_trough=flow_m,flow_m=int16_flow_s; //��ֵ
									Volume_p=Volume_m,Volume_m=int16_Volume; //��ֵ
									Color1=White,Color2=Black;
									Canvas_Image_Start_address(layer3_start_addr);
									dispPN(Vp_trough,trough_x,trough_y);   //��Сѹ��
									Canvas_Image_Start_address(layer1_start_addr);
									disp(peep,peep_x_pos,peep_y_pos);
									disp(Pplatfrom,Pplatfrom_x_pos,Pplatfrom_y_pos);
									disp(Paverage,Paverage_x_pos,Paverage_y_pos);
									disp(Ppeak,Ppeak_x_pos,Ppeak_y_pos);
									
									dispc();		
									  									
								}
						else
								{										
                  if (Vps>peak_m)  peak_m=Vps;//��ֵ
									
									if (Vp<Vp_m) Vp_m=Vp;  //��ֵ
									if (int16_flow_s<flow_m) flow_m=int16_flow_s;  //��ֵ
									
									if (int16_Volume>Volume_m) Volume_m=int16_Volume;//��ֵ
									//prthxd(840,200,Volume_m);
									if (Vps>ps_H)
									   {
										  pwmo=0,pwmx=0;
											EPWM_DisableOutput(EPWM0, EPWM_CH_0_MASK); 
                      EPWM_DisableOutput(EPWM0, EPWM_CH_4_MASK);
                      Pplatfrom10=Vps10;
                      Pplatfrom=(Pplatfrom10+5)/10;											 
										 }								
									
								}	 
					}     
	 //PD4=1;		
   draw();
	 //PD4=0;	
   o2a();

  		
	} 
}

// =======================================================================
// 画图专用参数：可以在外部其他地方（比如屏幕菜单）随时修改这两个变量
// =======================================================================
uint8_t g_graph_filter_en = 0;      // 画图滤波开关：1 = 开启，0 = 关闭
uint8_t g_graph_filter_alpha = 5;   // 滤波强度 (1~10)：数值越小波形越平滑，例如 3 代表新数据占 30%

/*-------------------------------------------*/
void draw(void)
{	
	int16_t xb,xe,yb,ye;
    static int32_t filtered_Vp = 0; // 仅用于绘图的滤波变量

	if (frz) j++;
  if (j>499) j=0;
	//int32_Vp=-50;
  if (int32_Vp>125) int32_Vp=125;
	if (int32_Vp<-24) int32_Vp=-24;

    // 根据开关决定是否滤波
    if (g_graph_filter_en) {
        // 限制参数防飞车
        uint8_t alpha = (g_graph_filter_alpha > 10) ? 10 : (g_graph_filter_alpha == 0 ? 1 : g_graph_filter_alpha);
        filtered_Vp = (int32_Vp * alpha + filtered_Vp * (10 - alpha)) / 10;
    } else {
        filtered_Vp = int32_Vp; // 关闭滤波则直接使用真实数据
    }

  xb=131+(2+j)%500,yb=70,xe=xb,ye=219;	 
  if (frz) Lines(xb,yb,xe,ye,Black+5);    
	 //if (pwmhl==1) int32_Vp=10;
	xb=131+j,yb=195-filtered_Vp,xe=xb,ye=195;
	if (frz) 
	   { 
			 if (filtered_Vp>0) Lines(xb,yb,xe,ye,Green);
       else if (filtered_Vp<0)	Lines(xb,yb,xe,ye,Magenta);
	     else Point(xb,yb,Yellow);
		 }
	if (j==0) peaks=0,flows=0,Volumes=0;
	if (peaks<Ppeak) peaks=Ppeak;
	if (flows>flow_trough) flows=flow_trough;//��ֵ
	if (Volumes<Volume_p) Volumes=Volume_p;
  		 
	xb=131+(2+j)%500,yb=245,xe=xb,ye=393;	 
  if (frz) Lines(xb,yb,xe,ye,Black+5); 
  if (int16_flowDisp>50) int16_flowDisp=50;
	if (int16_flowDisp<-99) int16_flowDisp=-99;		 
	xb=131+j,yb=295-int16_flowDisp,xe=xb,ye=295;
	if (frz) 
	   { 
			  if (int16_flowDisp>0) Lines(xb,yb,xe,ye,Green);
        else if (int16_flowDisp<0)	Lines(xb,yb,xe,ye,Magenta);
	      else Point(xb,yb,Yellow);
		 }

	xb=131+(2+j)%500,yb=420,xe=xb,ye=569;	 
  if (frz) Lines(xb,yb,xe,ye,Black+5);
	//Color1=White,prt32D(820,380,int16_Volume);	 
	if (int16_VolumeDisp>149) int16_VolumeDisp=149;
  if (int16_VolumeDisp<0) int16_VolumeDisp=0;		 
	xb=131+j,yb=569-int16_VolumeDisp,xe=xb,ye=569;
	//Color1=White,prt32D(820,400,int16_VolumeDisp);	 
	//             prt32D(820,420,yb);	 
	if (frz) Lines(xb,yb,xe,ye,Magenta);
		 
  if (j==499)
	   {
			//Color1=White,Color2=Black,prthxd(840,240,flows); 
      Color1=0x07ff,Color2=Black; 			 
		  if (peaks<25)
				{				
					dispnumber(103,112,0);//-5 -- +25
					scal_P=1;
				}
			else	if (peaks<50)	
				{   
					dispnumber(93,102,0);  //-10 -- +50			
					scal_P=2;
				}
			else	
				{   
					dispnumber(18,27,0);    //-15 -- +75		
					scal_P=3;
				}
				
			if (flows>-40)
				{
					dispnumber(123,132,0);   //20 -- -40 
					scal_F=1;
				}
			else if (flows>-80)
				{
		     dispnumber(113,122,0);	 //40 -- -80
					scal_F=2;
				}
			else
			  {
				 dispnumber(28,37,0);   //60 -- -120
					scal_F=3;
				}		
				
			if (Volumes<600)
				{
				 dispnumber(145,156,0);   //0 -- 600
	  	   scal_V=1;
				}
			else if (Volumes<800)
				{
		     dispnumber(133,144,0);   //0 -- 1200
			   scal_V=2;
				}
      else
        {
				 dispnumber(38,49,0);     //0 -- 1800
				 scal_V=3;
				}				
		}	
 }   
/*---------------------------------------------------*/   
void o2a(void)
{
uint8_t lw,mw,rw;
int32_t	int32_ox;
uint16_t hd;	
if (ox100>4000 || ox100<2000) ox100=4000;
if (ox21<300 || ox21>2000) ox21=300;
int32_ox=209+ (moxw-ox21)*791/(ox100-ox21);		
if (int32_ox>998) mox=999;
else if	(int32_ox<0) mox=0;	
else mox=int32_ox;	
hd=uint_to_bcd(mox);
rw= hd & 0x000f;
mw=(hd & 0x00f0)>>4;
lw=(hd & 0x0f00)>>8;	
xn=O2_x_pos,yn=O2_y_pos ,Color1=White,Color2=Black;
MPU_Memory_Write_Window_8bit(xn,   yn,image,lw,Color1,Color2);
MPU_Memory_Write_Window_8bit(xn+24,yn,image,mw,Color1,Color2);
MPU_Memory_Write_Window_8bit(xn+48,yn,dot8x40,0,Color1,Color2);		
MPU_Memory_Write_Window_8bit(xn+56,yn,image,rw,Color1,Color2);	
if (mox<O2_L*10)
	 {
   if ((spk & g_O2_L)==0 && clrspk==0) Color1=Green1,xy_();
   if ((spk & g_O2_L)==0) clrspk=1;
   Set_g_O2_L,alarms(4);
	 }
else
	 {
   if (mox<=O2_H*10)
		 {
      Reset_g_O2_L, Reset_g_O2_H;
      Fills(290,4,354,20,Green1);
		 }
   else
		 {
      if ((spk & g_O2_H)==0 && clrspk==0) Color1=Green1,xy_();
      if ((spk & g_O2_H)==0) clrspk=1;
      Set_g_O2_H,alarms(5);
	   }
   }  
 }
//777777777777777777777777777777777777777777777777777777777777777777777777
void alarms(uint8_t z)
{	
} 
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
void xy_(void)
{
	MPU_Memory_Write_Window_8bit(538,2,LCD32,40,Color1,Green1);
	Fills(538,35,570,50,Green1);
}	
//nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn
void compute(uint8_t freq,uint8_t dut)
{
uint8_t temp,dutl,duth;
uint16_t h_word;
uint32_t u32temp;	
temp=dut;
dutl=temp & 0x0f;
duth=temp>>4;   
h_word=freq*(dutl+duth);
inspirtion_time=6000000*duth/h_word ;  /*  60*f/prescal f=12000000 ,prescal=120 */
exspirtion_time=6000000*dutl/h_word ; 	
u32temp=h_word*VT_preset*3/(25*duth) ; /*'3*/	
lq=u32temp;
simvcp=1125/freq;  //60s*25 *75%  40ms
simvst=duth*1500/freq/(duth+dutl);
PCVcount=duth*1500/freq/(duth+dutl);	
}
/*-------------------------------------------------*/
void dispc(void)
{ 
	VTi=abs(int32VtIns)/10;	
	VTe=abs(int32VtEx)/10;
	VT_s=VTe;
  VTt=1;
	Color1=White,Color2=Black;
	dispVT(VTe,VTe_x_pos,VTe_y_pos);
  dispVT(VTi,VTi_x_pos,VTi_y_pos); 
  dispMV(mvt,MV_x_pos,MV_y_pos);
}	
/*------------------------------------  */  
void flashes(void)
{    
	 Color2=Black;
	if (pflash)  
	   {
		   Color1=White;
	     if (spsd==1)  disp(freq_m,freq_x_pos,freq_y_pos);     
       if (spsd==2)  xn=dut_x_pos,yn=dut_y_pos,bbx(dut_tab[dutp_m]); 
       //if (spsd==3)  dispPN(ps_tr_m,ps_tr_x_pos,ps_tr_y_pos);
		   Color1=Red; 
       if (spsd==4)  disp_limit(ps_H_m,ps_H_x_pos,ps_H_y_pos);
       if (spsd==5)  disp_limit(ps_L_m,ps_L_x_pos,ps_L_y_pos);
       if (spsd==6)  dispVT_limit(VT_H_m*10,VTe_H_x_pos,VTe_H_y_pos);
       if (spsd==7)  dispVT_limit(VT_L_m*10,VTe_L_x_pos,VTe_L_y_pos);
       if (spsd==8)  disp_limit(O2_H_m,O2_H_x_pos,O2_H_y_pos);
       if (spsd==9)  disp_limit(O2_L_m,O2_L_x_pos,O2_L_y_pos);          
       //if (sps==10) dispm(eip_x_pos,eip_y_pos,eip_m,0);
	   }
   else 
	   { 
		   Color1=Green;
	     if (spsd==1)  disp(freq_m,freq_x_pos,freq_y_pos);     
       if (spsd==2)  xn=dut_x_pos,yn=dut_y_pos,bbx(dut_tab[dutp_m]); 
       //if (spsd==3)  dispPN(ps_tr_m,ps_tr_x_pos,ps_tr_y_pos); 
       if (spsd==4)  disp_limit(ps_H_m,ps_H_x_pos,ps_H_y_pos);
       if (spsd==5)  disp_limit(ps_L_m,ps_L_x_pos,ps_L_y_pos);
       if (spsd==6)  dispVT_limit(VT_H_m*10,VTe_H_x_pos,VTe_H_y_pos);
       if (spsd==7)  dispVT_limit(VT_L_m*10,VTe_L_x_pos,VTe_L_y_pos);
       if (spsd==8)  disp_limit(O2_H_m,O2_H_x_pos,O2_H_y_pos);
       if (spsd==9)  disp_limit(O2_L_m,O2_L_x_pos,O2_L_y_pos);          
       //if (sps==10) dispm(eip_x_pos,eip_y_pos,eip_m,0);
	    }
	 
	 if  (sps==10)
		   { Color2=Black;
				 if (pflash==0) 
				    {
							Color1=Red,dispVT(VT_preset_m*10,VTset_x_pos,VTset_y_pos);
						}
				 else 
				   {
						  Color1=Green,dispVT(VT_preset_m*10,VTset_x_pos,VTset_y_pos);
					 }					 
			 }
	if (sigauto==1)
	   {
			MPU_Memory_Write_Window_8bit(freq_x_pos,freq_y_pos,image,12,White,Black);
			MPU_Memory_Write_Window_8bit(freq_x_pos+32,freq_y_pos,image,12,White,Black);
			MPU_Memory_Write_Window_8bit(dut_x_pos,dut_y_pos,image,12,White,Black);
			MPU_Memory_Write_Window_8bit(dut_x_pos+32,dut_y_pos,image,12,White,Black); 
		 }		
  if (spk)
	 {
	  if (sflash==0)
		 {
		  if ((spk & g_pres_H)==1)
			 {
				Color1=Red,kn=5;
				PE8=0;
			 }
		 else
			 {
               Color1=Yellow,kn=10;
			   PE9=0;	 
			 }
		 MPU_Memory_Write_Window_8bit(alarm_x_pos,alarm_y_pos,alrm,0,Color1,Green1);
		 }				 
	 else  
		 { 
		  PE8=1,PE9=1;
		  MPU_Memory_Write_Window_8bit(alarm_x_pos,alarm_y_pos,alrm,0,Green1,Green1);  
		 }
	 }					
  else
     {
      MPU_Memory_Write_Window_8bit(alarm_x_pos,alarm_y_pos,alrm,0,Green1,Green1); 
     }							 
}
 /*-----------------------------------------*/
void showpra(uint8_t x)
 {	
 switch(x) 
			{
				case 1:  
					Color2=Black;
					disp(freq,freq_x_pos,freq_y_pos);
					break;    
				case 2:	
					Color2=Black;
					xn=dut_x_pos,yn=dut_y_pos;
					bbx(dut);
					break;
				case 3:
					Color2=Black;
				   // dispPN(ps_tr,ps_tr_x_pos,ps_tr_y_pos);
					break;
				case 4:
					Color2=Black;
					disp_limit(ps_H,ps_H_x_pos,ps_H_y_pos);	
					break;
				case 5:
					Color2=Black;
					disp_limit(ps_L,ps_L_x_pos,ps_L_y_pos);
					break;
				case 6:
					Color2=Black;
					dispVT_limit(VT_H*10,VTe_H_x_pos,VTe_H_y_pos);
					break; 
				case 7:
					dispVT_limit(VT_L*10,VTe_L_x_pos,VTe_L_y_pos);
					break;
				case 8:
					Color2=Black;
					disp_limit(O2_H,O2_H_x_pos,O2_H_y_pos);
					break;
				case 9:
					Color2=Black;
					disp_limit(O2_L,O2_L_x_pos,O2_L_y_pos);
					break;
				}
}					
 /*-----------------------------------------*/ 
void bbx(uint8_t x)
{   //uint8_t temp;
	  uint8_t tempL,tempH;
	  //temp=dut_tab[x];
    tempL=x & 0x0f;
    tempH=x>>4;
    MPU_Memory_Write_Window_8bit(xn,yn,image,tempH,Color1,Color2);
	  MPU_Memory_Write_Window_8bit(xn+24,yn,dot8x40,1,Color1,Color2); 
    MPU_Memory_Write_Window_8bit(xn+32,yn,image,tempL,Color1,Color2); 
    
}

/*-----------------------------------------*/ 
void disp_limit(uint8_t a,uint16_t x,uint16_t y)
{
	uint16_t tempL,tempH;
	tempL=a%10;
  tempH=a/10;
  if (tempH==0) MPU_Memory_Write_Window_8bit(x,y,mdn,tempH,Color2,Color2);
  else MPU_Memory_Write_Window_8bit(x,y,mdn,tempH,Color1,Color2);
	MPU_Memory_Write_Window_8bit(x+16,y,mdn,tempL,Color1,Color2);
}	

/*-----------------------------------------*/
void dispmw(uint16_t a,uint16_t x,uint16_t y)
{ 
	uint16_t b,c3,c4;
	uint8_t rw,mw,lw;
	b=uint_to_bcd(a);
	rw=b & 0x000f;
	mw=(b & 0x00f0)>>4;
	lw=(b & 0x0f00)>>8;
	if (lw==0) c3=Color2;
	else c3=Color1;
	if (lw==0 && mw==0) c4=Color2;
	else c4=Color1;
	MPU_Memory_Write_Window_8bit(x,y,sdn,lw,c3,Color2);
	MPU_Memory_Write_Window_8bit(x+8,y,sdn,mw,c4,Color2);
	MPU_Memory_Write_Window_8bit(x+16,y,sdn,rw,Color1,Color2);
	MPU_Memory_Write_Window_8bit(x+24,y,sdn,0,Color1,Color2);
}	
/*-----------------------------------------*/ 
void dispmword(uint8_t a,uint16_t x,uint16_t y)
{
	uint16_t tempL,tempH;
	tempL=a%10;
  tempH=a/10;
  if (tempH==0) MPU_Memory_Write_Window_8bit(x,y,mdn,tempH,Color2,Color2);
  else MPU_Memory_Write_Window_8bit(x,y,mdn,tempH,Color1,Color2);
	MPU_Memory_Write_Window_8bit(x+16,y,mdn,tempL,Color1,Color2);
}
/*-----------------------------------------*/ 
void dispdate_time(uint16_t x,uint16_t y)
{ 
	Color1=White,Color2=Blue1;
	year=sReadRTC.u32Year%2000,prt16D(x,y,sReadRTC.u32Year);
	MPU_Memory_Write_Window_8bit(x+32,y,sdn,16,White,Blue1);
	month=sReadRTC.u32Month,prt2D(x+40,y,month);
	MPU_Memory_Write_Window_8bit(x+56,y,sdn,16,White,Blue1);
	day=sReadRTC.u32Day,prt2D(x+64,y,day);
	
	hour=sReadRTC.u32Hour,prt2D(x,y+16,hour);
	MPU_Memory_Write_Window_8bit(x+16,y+16,sdn,40,White,Blue1);
	minute=sReadRTC.u32Minute,prt2D(x+24,y+16,minute);
	MPU_Memory_Write_Window_8bit(x+40,y+16,sdn,40,White,Blue1);
	second=sReadRTC.u32Second,prt2D(x+48,y+16,second);
}
/*-----------------------------------------*/ 
void dispVT(uint16_t a,uint16_t x,uint16_t y)
{
	uint8_t rw,mw,lw,tw;
	uint16_t c1,c2,c3;
	uint32_t b;
	b=uint_to_bcd(a); 
	tw=b      & 0x0f;	 
	rw=(b>>4) & 0x0f;  
	mw=(b>>8) & 0x0f;
	lw=(b>>12)& 0x0f;
	c1=Color1,c2=Color1,c3=Color1;
	if (lw==0) c1=Color2;
	if (lw==0 && mw==0) c2=Color2;
	if (lw==0 && mw==0 && rw==0) c3=Color2;
  MPU_Memory_Write_Window_8bit(x,   y,image,lw,c1,Color2);
  MPU_Memory_Write_Window_8bit(x+24,y,image,mw,c2,Color2);
	MPU_Memory_Write_Window_8bit(x+48,y,image,rw,c3,Color2);	 
	MPU_Memory_Write_Window_8bit(x+72,y,image,tw,Color1,Color2);
}
/*----------------------------- ------------*/
void disp(uint8_t a,uint16_t x,uint16_t y)
{
	uint8_t tempL,tempH;
	tempL=a%10;
  tempH=a/10;
  if (tempH==0) MPU_Memory_Write_Window_8bit(x,y,image,tempH,Color2,Color2);
  else          MPU_Memory_Write_Window_8bit(x,y,image,tempH,Color1,Color2);
	MPU_Memory_Write_Window_8bit(x+32,y,image,tempL,Color1,Color2);
}
/*-----------------------------------------*/ 
void dispdn(uint8_t num,uint16_t x,uint16_t y,uint8_t p)
{ 
uint16_t tempL,tempH;	
if (num==100)
   MPU_Memory_Write_Window_8bit(x,y,hand,0,Color1,Color2);
else   
 { 
   tempL=num%10;
   tempH=num/10;
   MPU_Memory_Write_Window_8bit(x,y,image,tempH,Color1,Color2);
   if (p)
	    {
       x=x+16;    
       MPU_Memory_Write_Window_8bit(x,y,dot8x40,0,Color1,Color2);
       x=x+8;
	    }
   else x=x+16;
    MPU_Memory_Write_Window_8bit(x,y,image,tempL,Color1,Color2);
  } 
}
/*-----------------------------------------*/ 
void dispVT_limit(uint16_t a,uint16_t x,uint16_t y)
{ 
	uint16_t b,c1,c2;
	uint8_t tw,rw,mw,lw;
	
	    b=uint_to_bcd(a);
	    tw=b      & 0x0f;	 
	    rw=(b>>4) & 0x0f;  
	    mw=(b>>8) & 0x0f;
	    lw=(b>>12)& 0x0f;
	    c1=Color1,c2=Color1;
	    if (lw==0) c1=Color2;
	    if (lw==0 && mw==0) c2=Color2;
	    MPU_Memory_Write_Window_8bit(x,y,mdn,lw,c1,Color2);
	    MPU_Memory_Write_Window_8bit(x+16,y,mdn,mw,c2,Color2);
	    MPU_Memory_Write_Window_8bit(x+32,y,mdn,rw,Color1,Color2);
	    MPU_Memory_Write_Window_8bit(x+48,y,mdn,tw,Color1,Color2);
}	
/*-----------------------------------------*/
void dispMV_limit(uint16_t a,uint16_t x,uint16_t y)
{
	uint16_t b,c;
	uint8_t rw,mw,lw;

	    b=uint_to_bcd(a);
	    rw= b & 0x000f;
	    mw=(b & 0x00f0)>>4;
	    lw=(b & 0x0f00)>>8;	
	    c=Color1;
	    if (lw==0) c=Color2;
	    MPU_Memory_Write_Window_8bit(x,y,mdn,lw,c,Color2);      
	    MPU_Memory_Write_Window_8bit(x+16,y,mdn,mw,Color1,Color2);
			MPU_Memory_Write_Window_8bit(x+32,y,Dot8x24,0,Color1,Color2); 
	    MPU_Memory_Write_Window_8bit(x+40,y,mdn,rw,Color1,Color2);		 
}
/*-----------------------------------------*/
void dispPN(int8_t a,uint16_t x,uint16_t y)
{ 
	uint16_t b,tempL,tempH;
	if (a<0) 
	   {
			 b=-a;
			 tempL=b%10;
       tempH=b/10;
       
       if(tempH==0) 
			   { 
			     MPU_Memory_Write_Window_8bit(x,y,image,tempH,Color2,Color2);
					 MPU_Memory_Write_Window_8bit(x+24,y,dot8x40,2,Color1,Color2);
	         MPU_Memory_Write_Window_8bit(x+32,y,image,tempL,Color1,Color2);
			    }
			 else 
			    {
			      MPU_Memory_Write_Window_8bit(x,y,dot8x40,2,Color1,Color2);
			      MPU_Memory_Write_Window_8bit(x+8,y,image,tempH,Color1,Color2);
	          MPU_Memory_Write_Window_8bit(x+32,y,image,tempL,Color1,Color2);
					}
		 }
  else
	   {
			 tempL=a%10;
       tempH=a/10;
       if (tempH==0) MPU_Memory_Write_Window_8bit(x+8,y,image,tempH,Color2,Color2);
       else MPU_Memory_Write_Window_8bit(x+8,y,image,tempH,Color1,Color2);
	     MPU_Memory_Write_Window_8bit(x+32,y,image,tempL,Color1,Color2); 			 
		 }		
}	
/*-----------------------------------------*/
void dispMV(uint32_t a,uint16_t x,uint16_t y)	
{ uint16_t rw,mw,lw,lw0;
	uint32_t hd;	
	hd=uint_to_bcd(a);
	rw=(hd & 0x00f0)>>4;
	mw=(hd & 0x00f00)>>8;
	lw=(hd & 0x0f000)>>12;
	lw0=(hd & 0x0f0000)>>16;
	if (a>9999)
		 { if (lw0==0) c3=Color2;
			 else c3=Color1;
			 MPU_Memory_Write_Window_8bit(x,y,image,lw0,c3,Color2);
			 MPU_Memory_Write_Window_8bit(x+24,y,image,lw,Color1,Color2);
			 MPU_Memory_Write_Window_8bit(x+48,y,dot8x40,0,Color1,Color2);
			 MPU_Memory_Write_Window_8bit(x+56,y,image,mw,Color1,Color2);
		 }
  else
	   {
			 MPU_Memory_Write_Window_8bit(x,y,image,lw,Color1,Color2);
			 MPU_Memory_Write_Window_8bit(x+24,y,dot8x40,0,Color1,Color2);
			 MPU_Memory_Write_Window_8bit(x+32,y,image,mw,Color1,Color2);
			 MPU_Memory_Write_Window_8bit(x+56,y,image,rw,Color1,Color2);
		 }		
}	
/*-----------------------------------------*/ 
void dispm(uint16_t a,uint16_t x,uint16_t y)
{ 
	uint16_t rw,mw,lw;
	uint16_t hd; 
	if (a<1000)
	   { hd=uint_to_bcd(a);
			 rw=hd & 0x000f;
			 mw=(hd & 0x00f0)>>4;
			 lw=(hd & 0x0f00)>>8;
			 if (lw==0 && mw!=0)
			    {
					 MPU_Memory_Write_Window_8bit(x,y,image,lw,Color2,Color2);
					 MPU_Memory_Write_Window_8bit(x+24,y,image,mw,Color1,Color2);
			    }
			 else if (lw==0 && mw==0)
			    {
					 MPU_Memory_Write_Window_8bit(x,y,image,lw,Color2,Color2);				 
			     MPU_Memory_Write_Window_8bit(x+24,y,image,mw,Color2,Color2);
			    }
       else
			    {
						MPU_Memory_Write_Window_8bit(x,y,image,lw,Color1,Color2);				 
			      MPU_Memory_Write_Window_8bit(x+24,y,image,mw,Color1,Color2);
					}
			 MPU_Memory_Write_Window_8bit(x+48,y,image,rw,Color1,Color2);
			 MPU_Memory_Write_Window_8bit(x+72,y,dot8x40,4,0xff00,Color2);
			 MPU_Memory_Write_Window_8bit(x+80,y+20,sdn,17,0x07ff,Color2);
		 }
	else
	  {  hd=uint_to_bcd(a);
			 rw=(hd & 0x00f0)>>4;
			 mw=(hd & 0x0f00)>>8;
			 lw=(hd & 0xf000)>>12;
			 MPU_Memory_Write_Window_8bit(x,y,image,lw,Color1,Color2);
			 MPU_Memory_Write_Window_8bit(x+24,y,dot8x40,0,Color1,Color2);
			 MPU_Memory_Write_Window_8bit(x+32,y,image,mw,Color1,Color2);
			 MPU_Memory_Write_Window_8bit(x+56,y,image,rw,Color1,Color2);
			 MPU_Memory_Write_Window_8bit(x+80,y+20,sdn,17,0x07ff,Color2);
		}		
}
/*-----------------------------------------*/ 
void dispn(uint16_t x,uint16_t y,uint16_t z)
{ 
//	uint16_t c;
	uint8_t i;
	uint8_t k[4];
for (i=0;i<4;i++)	
  {
	 k[i]=z & 0x000f;		
   z=z>>4;
  }
  if (k[3]==0)                       MPU_Memory_Write_Window_8bit(x,   y,image,k[3],0x0806,0x0806);
	else                               MPU_Memory_Write_Window_8bit(x,   y,image,k[3],0xf609,0x0806);
  if (k[3]==0 && k[2]==0)            MPU_Memory_Write_Window_8bit(x+24,y,image,k[2],0x0809,0x0806);
	else                               MPU_Memory_Write_Window_8bit(x+24,y,image,k[2],0xf609,0x0806);
  if (k[3]==0 && k[2]==0 && k[1]==0) MPU_Memory_Write_Window_8bit(x+48,y,image,k[1],0x0806,0x0806);
	else                               MPU_Memory_Write_Window_8bit(x+48,y,image,k[1],0xf609,0x0806);
	
	MPU_Memory_Write_Window_8bit(x+72,y,image,k[0],0xf609,0x0806);
}
/*-----------------------------------------*/ 

void prthxd(uint16_t x,uint16_t y,uint16_t z)
{ 
	uint8_t temp0;
	uint8_t temp1;
	uint8_t temp2;
	uint8_t temp3;
  temp0= z & 0x000f;
  temp1=(z & 0x00f0)>>4;
  temp2=(z & 0x0f00)>>8;
  temp3=(z & 0xf000)>>12;
  MPU_Memory_Write_Window_8bit(x,   y,sdn,temp3,Color1,Color2);
  MPU_Memory_Write_Window_8bit(x+ 8,y,sdn,temp2,Color1,Color2);
  MPU_Memory_Write_Window_8bit(x+16,y,sdn,temp1,Color1,Color2);
  MPU_Memory_Write_Window_8bit(x+24,y,sdn,temp0,Color1,Color2);	
}
/*-------------------------------------------------*/
void prtx(uint16_t x,uint16_t y,int16_t z)
{ 
	uint8_t temp0,temp1,temp2,temp3;
	uint32_t temp32;
	if (z>=0) 
  {
		temp32=uint_to_bcd(z);
    temp0= temp32 & 0x0000000f;
    temp1=(temp32 & 0x000000f0)>>4;
    temp2=(temp32 & 0x00000f00)>>8;
    temp3=(temp32 & 0x0000f000)>>12;
  		
    MPU_Memory_Write_Window_8bit(x,   y,sdn,29,Color1,Color2);
    MPU_Memory_Write_Window_8bit(x+ 8,y,sdn,temp3,Color1,Color2);
    MPU_Memory_Write_Window_8bit(x+16,y,sdn,temp2,Color1,Color2);
    MPU_Memory_Write_Window_8bit(x+24,y,sdn,temp1,Color1,Color2);
    MPU_Memory_Write_Window_8bit(x+32,y,sdn,temp0,Color1,Color2);		
	}
	else
	 {
		temp32=uint_to_bcd(-z);
    temp0= temp32 & 0x0000000f;
    temp1=(temp32 & 0x000000f0)>>4;
    temp2=(temp32 & 0x00000f00)>>8;
    temp3=(temp32 & 0x0000f000)>>12;
		 
    MPU_Memory_Write_Window_8bit(x,   y,sdn,16,Color1,Color2);
    MPU_Memory_Write_Window_8bit(x+8, y,sdn,temp3,Color1,Color2);
    MPU_Memory_Write_Window_8bit(x+16,y,sdn,temp2,Color1,Color2);
    MPU_Memory_Write_Window_8bit(x+24,y,sdn,temp1,Color1,Color2);	
		MPU_Memory_Write_Window_8bit(x+32,y,sdn,temp0,Color1,Color2); 
	 }	
}
/*-------------------------------------------------*/
void prt16D(uint16_t x,uint16_t y,uint16_t z)
{ uint32_t temp32;
	uint8_t temp0,temp1,temp2,temp3;
  temp32=uint_to_bcd(z);
  temp0= temp32 & 0x0000000f;
  temp1=(temp32 & 0x000000f0)>>4;
  temp2=(temp32 & 0x00000f00)>>8;
  temp3=(temp32 & 0x0000f000)>>12;
	
  MPU_Memory_Write_Window_8bit(x,   y,sdn,temp3,Color1,Color2);
  MPU_Memory_Write_Window_8bit(x+ 8,y,sdn,temp2,Color1,Color2);
  MPU_Memory_Write_Window_8bit(x+16,y,sdn,temp1,Color1,Color2);
  MPU_Memory_Write_Window_8bit(x+24,y,sdn,temp0,Color1,Color2);	
}
/*-------------------------------------------------*/
void prt32D(uint16_t x,uint16_t y,uint32_t z)
{ uint32_t temp32;
	uint8_t temp0,temp1,temp2,temp3,temp4,temp5,temp6,temp7;
  temp32=uint_to_bcd(z);
  temp0= temp32 & 0x0000000f;
  temp1=(temp32 & 0x000000f0)>>4;
  temp2=(temp32 & 0x00000f00)>>8;
  temp3=(temp32 & 0x0000f000)>>12;
	temp4=(temp32 & 0x000f0000)>>16;
	temp5=(temp32 & 0x00f00000)>>20;
	temp6=(temp32 & 0x0f000000)>>24;
	temp7=(temp32 & 0xf000f000)>>28;
  MPU_Memory_Write_Window_8bit(x,   y,sdn,temp7,Color1,Color2);
  MPU_Memory_Write_Window_8bit(x+ 8,y,sdn,temp6,Color1,Color2);
  MPU_Memory_Write_Window_8bit(x+16,y,sdn,temp5,Color1,Color2);
  MPU_Memory_Write_Window_8bit(x+24,y,sdn,temp4,Color1,Color2);	
	MPU_Memory_Write_Window_8bit(x+32,y,sdn,temp3,Color1,Color2);	
	MPU_Memory_Write_Window_8bit(x+40,y,sdn,temp2,Color1,Color2);	
	MPU_Memory_Write_Window_8bit(x+48,y,sdn,temp1,Color1,Color2);	
	MPU_Memory_Write_Window_8bit(x+56,y,sdn,temp0,Color1,Color2);	
}
/*-------------------------------------------------*/
void prt32(uint16_t x,uint16_t y,uint32_t z)
{
	uint8_t temp0,temp1,temp2,temp3,temp4,temp5,temp6,temp7;
  temp0= z & 0x0000000f;
  temp1=(z & 0x000000f0)>>4;
  temp2=(z & 0x00000f00)>>8;
  temp3=(z & 0x0000f000)>>12;
	temp4=(z & 0x000f0000)>>16;
	temp5=(z & 0x00f00000)>>20;
	temp6=(z & 0x0f000000)>>24;
	temp7=(z & 0xf000f000)>>28;
  MPU_Memory_Write_Window_8bit(x,   y,sdn,temp7,Color1,Color2);
  MPU_Memory_Write_Window_8bit(x+ 8,y,sdn,temp6,Color1,Color2);
  MPU_Memory_Write_Window_8bit(x+16,y,sdn,temp5,Color1,Color2);
  MPU_Memory_Write_Window_8bit(x+24,y,sdn,temp4,Color1,Color2);	
	MPU_Memory_Write_Window_8bit(x+32,y,sdn,temp3,Color1,Color2);	
	MPU_Memory_Write_Window_8bit(x+40,y,sdn,temp2,Color1,Color2);	
	MPU_Memory_Write_Window_8bit(x+48,y,sdn,temp1,Color1,Color2);	
	MPU_Memory_Write_Window_8bit(x+56,y,sdn,temp0,Color1,Color2);	
}
/*-------------------------------------------------*/
void print8(uint16_t x,uint16_t y,uint8_t *z,uint8_t len)
{ uint8_t i,k,l;
	
	for (i=0;i<len;i++)
	{   
		k=i%32;
		l=i/32;
		prt8(x+k*20,y+16*l,z[i]);
	}
}	
/*-------------------------------------------------*/
void prt2D(uint16_t x,uint16_t y,uint8_t z)
{
	uint8_t temp0,temp1;
  temp0=z%10;
  temp1=z/10;
  MPU_Memory_Write_Window_8bit(x,y,sdn,temp1,Color1,Color2);
  MPU_Memory_Write_Window_8bit(x+8,y,sdn,temp0,Color1,Color2);
}	
/*-------------------------------------------------*/
void prt8(uint16_t x,uint16_t y,uint8_t z)
{
 uint8_t temp0,temp1;
 temp1=z>>4;
 temp0=z & 0x0f;
 MPU_Memory_Write_Window_8bit(x,y,sdn,temp1,Color1,Color2);
 MPU_Memory_Write_Window_8bit(x+8,y,sdn,temp0,Color1,Color2);
}	
/*---------------------------------------------*/
uint32_t uint_to_bcd(uint32_t m)
{
	uint32_t n=1;
	uint32_t r=0,a;
	while(m)
	{
		a=m % 10;
		m=m / 10;
		r=r+n*a;
		n=n<<4;
	}	
	return r;
}

/*---------------------------------------------*/
 char* Int2str(unsigned int values)
{
  unsigned int k,j,i = 0;	
	const char digits[11] = "0123456789";
	unsigned int value = values;
  for (j=0;j<6;j++) g[j]=0;
	do
	{ 
		g[i]=digits[value%10];
		value /= 10;
		i++;
	} while(value);
	
  for (j=0;j<=(i-1)/2;j++)
	  {
			k=g[j],g[j]=g[i-1-j],g[i-1-j]=k;
		} 		
	return Ptr;
}

/*** (C) COPYRIGHT 2013~2015 Nuvoton Technology Corp. ***/
