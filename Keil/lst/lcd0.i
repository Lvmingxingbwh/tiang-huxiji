#line 1 "..\\LCD0.c"
#line 1 "..\\LCD0.h"
#line 1 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
 
 





 









     
#line 27 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
     











#line 46 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"





 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     




typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;


     
typedef   signed     long long intmax_t;
typedef unsigned     long long uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     






     






     






     

     


     


     


     

     
#line 216 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     



     






     
    
 



#line 241 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     







     










     











#line 305 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"






 
#line 2 "..\\LCD0.h"












#line 22 "..\\LCD0.h"
 
#line 31 "..\\LCD0.h"

#line 62 "..\\LCD0.h"

 
#line 72 "..\\LCD0.h"


 
#line 85 "..\\LCD0.h"

#line 107 "..\\LCD0.h"

#line 115 "..\\LCD0.h"


#line 124 "..\\LCD0.h"



void Show(void);
void LT768_Init(void);

void LT768_DrawSquare_Fill(uint16_t X1,uint16_t Y1,uint16_t X2,uint16_t Y2,unsigned long ForegroundColor);


void LT768_DMA_24bit_Block(uint8_t SCS,uint8_t Clk,uint16_t X1,uint16_t Y1 ,uint16_t X_W,uint16_t Y_H,uint16_t P_W,unsigned long Addr);

 
void LT768_PWM0_Init(uint8_t on_off,uint8_t Clock_Divided,uint8_t Prescalar,uint16_t Count_Buffer,uint16_t Compare_Buffer);
void LT768_PWM1_Init(uint8_t on_off,uint8_t Clock_Divided,uint8_t Prescalar,uint16_t Count_Buffer,uint16_t Compare_Buffer);
void LT768_PWM0_Duty(uint16_t Compare_Buffer);
void LT768_PWM1_Duty(uint16_t Compare_Buffer);







 

#line 157 "..\\LCD0.h"

#line 166 "..\\LCD0.h"


void LCD_RegisterWrite(uint8_t Cmd,uint8_t Data);
uint8_t LCD_RegisterRead(uint8_t Cmd);









 
void Check_Mem_WR_FIFO_not_Full(void);
void Check_2D_Busy(void);
void Check_SDRAM_Ready(void);
void Check_Mem_WR_FIFO_Empty(void);
void Check_Busy_Draw(void);


void LT768_SW_Reset(void);
void TFT_16bit(void);

void Enable_SFlash_SPI(void);
void Disable_SFlash_SPI(void);
void Host_Bus_16bit(void);



void RGB_16b_16bpp(void);

void MemWrite_Left_Right_Top_Down(void);

void Graphic_Mode(void);
void Text_Mode(void);
void Memory_Select_SDRAM(void);


void Select_Main_Window_16bpp(void);

void PCLK_Falling(void);
void Display_ON(void);

void VSCAN_T_to_B(void);
void VSCAN_B_to_T(void);
void PDATA_Set_RGB(void);



void HSYNC_Low_Active(void);

void VSYNC_Low_Active(void);

void DE_High_Active(void);

void LCD_HorizontalWidth_VerticalHeight(uint16_t WX,uint16_t HY);

void LCD_Horizontal_Non_Display(uint16_t WX);

void LCD_HSYNC_Start_Position(uint16_t WX);

void LCD_HSYNC_Pulse_Width(uint16_t WX);

void LCD_Vertical_Non_Display(uint16_t HY);

void LCD_VSYNC_Start_Position(uint16_t HY);

void LCD_VSYNC_Pulse_Width(uint16_t HY);

void Main_Image_Start_Address(unsigned long Addr);

void Main_Image_Width(uint16_t WX);							

void Main_Window_Start_XY(uint16_t WX,uint16_t HY);	

void PIP_Display_Start_XY(uint16_t WX,uint16_t HY);

void PIP_Image_Start_Address(unsigned long Addr);

void PIP_Image_Width(uint16_t WX);

void PIP_Window_Image_Start_XY(uint16_t WX,uint16_t HY);


void Canvas_Image_Start_address(unsigned long Addr);

void Canvas_image_width(uint16_t WX);

void Active_Window_XY(uint16_t WX,uint16_t HY);

void Active_Window_WH(uint16_t WX,uint16_t HY);


void Memory_XY_Mode(void);
void Memory_16bpp_Mode(void);

void Goto_Pixel_XY(uint16_t WX,uint16_t HY);
	
void Square_Start_XY(uint16_t WX,uint16_t HY);		
void Square_End_XY(uint16_t WX,uint16_t HY);		


void Start_Square_Fill(void);
void Point(uint16_t x,uint16_t y,uint16_t color);
void Lines(uint16_t x1 ,uint16_t y1 ,uint16_t x2,uint16_t y2,uint16_t color);
void Images(uint16_t x,uint16_t y,const char h[],uint16_t number,uint16_t color1,uint16_t color2); 

void ellipse(uint16_t x1 ,uint16_t y1 ,uint16_t r1,uint16_t r2,uint16_t color);



void Set_PWM_Prescaler_1_to_256(uint16_t WX);

void Select_PWM1_Clock_Divided_By_1(void);
void Select_PWM1_Clock_Divided_By_2(void);
void Select_PWM1_Clock_Divided_By_4(void);
void Select_PWM1_Clock_Divided_By_8(void);
void Select_PWM0_Clock_Divided_By_1(void);
void Select_PWM0_Clock_Divided_By_2(void);
void Select_PWM0_Clock_Divided_By_4(void);
void Select_PWM0_Clock_Divided_By_8(void);

void Select_PWM1_is_ErrorFlag(void);
void Select_PWM1(void);
void Select_PWM0(void);

void Start_PWM1(void);
void Stop_PWM1(void);

void Start_PWM0(void);
void Stop_PWM0(void);

void Set_Timer0_Compare_Buffer(uint16_t WX);

void Set_Timer0_Count_Buffer(uint16_t WX);

void Set_Timer1_Compare_Buffer(uint16_t WX);

void Set_Timer1_Count_Buffer(uint16_t WX);


void BTE_ROP_Code(unsigned char setx);
void BTE_Operation_Code(unsigned char setx);






void Start_SFI_DMA(void);
void Check_Busy_SFI_DMA(void);


void Select_SFI_0(void);
void Select_SFI_1(void);
void Select_SFI_DMA_Mode(void);
void Select_SFI_Dual_Mode0(void);


unsigned char SPI_Master_FIFO_Data_Put(unsigned char Data);
unsigned char SPI_Master_FIFO_Data_Get(void);


unsigned char Tx_FIFO_Empty_Flag(void);
unsigned char Tx_FIFO_Full_Flag(void);
unsigned char Rx_FIFO_Empty_Flag(void);
unsigned char Rx_FIFO_full_flag(void);
unsigned char OVFI_Flag(void);
void Clear_OVFI_Flag(void);
unsigned char EMTI_Flag(void);
void Clear_EMTI_Flag(void);


void SPI_Clock_Period(uint8_t temp);



void SFI_DMA_Source_Start_Address(unsigned long Addr);

void SFI_DMA_Destination_Upper_Left_Corner(uint16_t WX,uint16_t HY);
void SFI_DMA_Transfer_Width_Height(uint16_t WX,uint16_t HY);

void SFI_DMA_Source_Width(uint16_t WX);

void Foreground_color_65k(uint16_t temp);








 

void Parallel_Init(void);

void LCD_CmdWrite(uint8_t cmd);
void LCD_DataWrite(uint8_t data);
void LCD_DataWrite_Pixel(uint16_t data);
uint8_t LCD_StatusRead(void);
uint16_t LCD_DataRead(void);
	 
void Delay_us(uint16_t time);     
void Delay_ms(uint16_t time);     

#line 2 "..\\LCD0.c"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\NuMicro.h"
 






 



#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
 








 






































 







 
 
 



 



 
typedef enum IRQn
{
     
    NonMaskableInt_IRQn           = -14,       
    MemoryManagement_IRQn         = -12,       
    BusFault_IRQn                 = -11,       
    UsageFault_IRQn               = -10,       
    SVCall_IRQn                   = -5,        
    DebugMonitor_IRQn             = -4,        
    PendSV_IRQn                   = -2,        
    SysTick_IRQn                  = -1,        

     

    BOD_IRQn                      = 0,         
    IRC_IRQn                      = 1,         
    PWRWU_IRQn                    = 2,         
    RAMPE_IRQn                    = 3,         
    CKFAIL_IRQn                   = 4,         
    ISP_IRQn                      = 5,         
    RTC_IRQn                      = 6,         
    TAMPER_IRQn                   = 7,         
    WDT_IRQn                      = 8,         
    WWDT_IRQn                     = 9,         
    EINT0_IRQn                    = 10,        
    EINT1_IRQn                    = 11,        
    EINT2_IRQn                    = 12,        
    EINT3_IRQn                    = 13,        
    EINT4_IRQn                    = 14,        
    EINT5_IRQn                    = 15,        
    GPA_IRQn                      = 16,        
    GPB_IRQn                      = 17,        
    GPC_IRQn                      = 18,        
    GPD_IRQn                      = 19,        
    GPE_IRQn                      = 20,        
    GPF_IRQn                      = 21,        
    QSPI0_IRQn                    = 22,        
    SPI0_IRQn                     = 23,        
    BRAKE0_IRQn                   = 24,        
    EPWM0P0_IRQn                  = 25,        
    EPWM0P1_IRQn                  = 26,        
    EPWM0P2_IRQn                  = 27,        
    BRAKE1_IRQn                   = 28,        
    EPWM1P0_IRQn                  = 29,        
    EPWM1P1_IRQn                  = 30,        
    EPWM1P2_IRQn                  = 31,        
    TMR0_IRQn                     = 32,        
    TMR1_IRQn                     = 33,        
    TMR2_IRQn                     = 34,        
    TMR3_IRQn                     = 35,        
    UART0_IRQn                    = 36,        
    UART1_IRQn                    = 37,        
    I2C0_IRQn                     = 38,        
    I2C1_IRQn                     = 39,        
    PDMA0_IRQn                    = 40,        
    DAC_IRQn                      = 41,        
    EADC00_IRQn                   = 42,        
    EADC01_IRQn                   = 43,        
    ACMP01_IRQn                   = 44,        
    ACMP23_IRQn                   = 45,        
    EADC02_IRQn                   = 46,        
    EADC03_IRQn                   = 47,        
    UART2_IRQn                    = 48,        
    UART3_IRQn                    = 49,        
    QSPI1_IRQn                    = 50,        
    SPI1_IRQn                     = 51,        
    SPI2_IRQn                     = 52,        
    USBD_IRQn                     = 53,        
    USBH_IRQn                     = 54,        
    USBOTG_IRQn                   = 55,        
    BMC_IRQn                      = 56,        
    SPI5_IRQn                     = 57,        
    SC0_IRQn                      = 58,        
    SC1_IRQn                      = 59,        
    SC2_IRQn                      = 60,        
    GPJ_IRQn                      = 61,        
    SPI3_IRQn                     = 62,        
    SPI4_IRQn                     = 63,        
    EMAC0_TXRX_IRQn               = 66,        
    SDH0_IRQn                     = 64,        
    USBD20_IRQn                   = 65,        
    I2S0_IRQn                     = 68,        
    I2S1_IRQn                     = 69,        
    SPI6_IRQn                     = 70,        
    CRPT_IRQn                     = 71,        
    GPG_IRQn                      = 72,        
    EINT6_IRQn                    = 73,        
    UART4_IRQn                    = 74,        
    UART5_IRQn                    = 75,        
    USCI0_IRQn                    = 76,        
    SPI7_IRQn                     = 77,        
    BPWM0_IRQn                    = 78,        
    BPWM1_IRQn                    = 79,        
    SPIM_IRQn                     = 80,        
    CCAP_IRQn                     = 81,        
    I2C2_IRQn                     = 82,        
    I2C3_IRQn                     = 83,        
    EQEI0_IRQn                    = 84,        
    EQEI1_IRQn                    = 85,        
    ECAP0_IRQn                    = 86,        
    ECAP1_IRQn                    = 87,        
    GPH_IRQn                      = 88,        
    EINT7_IRQn                    = 89,        
    SDH1_IRQn                     = 90,        
    PSIO_IRQn                     = 91,        
    HSUSBH_IRQn                   = 92,        
    USBOTG20_IRQn                 = 93,        
    ECAP2_IRQn                    = 94,        
    ECAP3_IRQn                    = 95,        
    KPI_IRQn                      = 96,        
    HBI_IRQn                      = 97,        
    PDMA1_IRQn                    = 98,        
    UART8_IRQn                    = 99,        
    UART9_IRQn                    = 100,       
    TRNG_IRQn                     = 101,       
    UART6_IRQn                    = 102,       
    UART7_IRQn                    = 103,       
    EADC10_IRQn                   = 104,       
    EADC11_IRQn                   = 105,       
    EADC12_IRQn                   = 106,       
    EADC13_IRQn                   = 107,       
    SPI8_IRQn                     = 108,       
    KS_IRQn                       = 109,       
    GPI_IRQn                      = 110,       
    SPI9_IRQn                     = 111,       
    CANFD00_IRQn                  = 112,       
    CANFD01_IRQn                  = 113,       
    CANFD10_IRQn                  = 114,       
    CANFD11_IRQn                  = 115,       
    EQEI2_IRQn                    = 116,       
    EQEI3_IRQn                    = 117,       
    I2C4_IRQn                     = 118,       
    SPI10_IRQn                    = 119,       
    CANFD20_IRQn                  = 120,       
    CANFD21_IRQn                  = 121,       
    CANFD30_IRQn                  = 122,       
    CANFD31_IRQn                  = 123,       
    EADC20_IRQn                   = 124,       
    EADC21_IRQn                   = 125,       
    EADC22_IRQn                   = 126,       
    EADC23_IRQn                   = 127,       
}
IRQn_Type;






 

 
#line 230 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"

   


#line 1 "..\\M463_Library\\CMSIS\\Include\\core_cm4.h"
 




 
















 










#line 35 "..\\M463_Library\\CMSIS\\Include\\core_cm4.h"

















 




 



 

#line 1 "..\\M463_Library\\CMSIS\\Include\\cmsis_version.h"
 




 
















 










 
#line 64 "..\\M463_Library\\CMSIS\\Include\\core_cm4.h"
 
 









 
#line 87 "..\\M463_Library\\CMSIS\\Include\\core_cm4.h"

#line 161 "..\\M463_Library\\CMSIS\\Include\\core_cm4.h"

#line 1 "..\\M463_Library\\CMSIS\\Include\\cmsis_compiler.h"
 




 
















 




#line 29 "..\\M463_Library\\CMSIS\\Include\\cmsis_compiler.h"



 
#line 1 "..\\M463_Library\\CMSIS\\Include\\cmsis_armcc.h"
 




 
















 









 













   
   


 
#line 100 "..\\M463_Library\\CMSIS\\Include\\cmsis_armcc.h"

 



 





 
 






 
 





 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}






 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}






 
static __inline uint32_t __get_IPSR(void)
{
  register uint32_t __regIPSR          __asm("ipsr");
  return(__regIPSR);
}






 
static __inline uint32_t __get_APSR(void)
{
  register uint32_t __regAPSR          __asm("apsr");
  return(__regAPSR);
}






 
static __inline uint32_t __get_xPSR(void)
{
  register uint32_t __regXPSR          __asm("xpsr");
  return(__regXPSR);
}






 
static __inline uint32_t __get_PSP(void)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  return(__regProcessStackPointer);
}






 
static __inline void __set_PSP(uint32_t topOfProcStack)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  __regProcessStackPointer = topOfProcStack;
}






 
static __inline uint32_t __get_MSP(void)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  return(__regMainStackPointer);
}






 
static __inline void __set_MSP(uint32_t topOfMainStack)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  __regMainStackPointer = topOfMainStack;
}






 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}






 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}









 







 







 
static __inline uint32_t  __get_BASEPRI(void)
{
  register uint32_t __regBasePri         __asm("basepri");
  return(__regBasePri);
}






 
static __inline void __set_BASEPRI(uint32_t basePri)
{
  register uint32_t __regBasePri         __asm("basepri");
  __regBasePri = (basePri & 0xFFU);
}







 
static __inline void __set_BASEPRI_MAX(uint32_t basePri)
{
  register uint32_t __regBasePriMax      __asm("basepri_max");
  __regBasePriMax = (basePri & 0xFFU);
}






 
static __inline uint32_t __get_FAULTMASK(void)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  return(__regFaultMask);
}






 
static __inline void __set_FAULTMASK(uint32_t faultMask)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  __regFaultMask = (faultMask & (uint32_t)1U);
}











 
static __inline uint32_t __get_FPSCR(void)
{


  register uint32_t __regfpscr         __asm("fpscr");
  return(__regfpscr);



}






 
static __inline void __set_FPSCR(uint32_t fpscr)
{


  register uint32_t __regfpscr         __asm("fpscr");
  __regfpscr = (fpscr);



}





 


 



 




 






 







 






 








 










 










 











 








 

__attribute__((section(".rev16_text"))) static __inline __asm uint32_t __REV16(uint32_t value)
{
  rev16 r0, r0
  bx lr
}








 

__attribute__((section(".revsh_text"))) static __inline __asm int32_t __REVSH(int32_t value)
{
  revsh r0, r0
  bx lr
}









 









 








 
#line 533 "..\\M463_Library\\CMSIS\\Include\\cmsis_armcc.h"







 











 












 












 














 














 














 










 









 









 









 

__attribute__((section(".rrx_text"))) static __inline __asm uint32_t __RRX(uint32_t value)
{
  rrx r0, r0
  bx lr
}








 








 








 








 








 








 





   


 



 



#line 800 "..\\M463_Library\\CMSIS\\Include\\cmsis_armcc.h"











 


#line 35 "..\\M463_Library\\CMSIS\\Include\\cmsis_compiler.h"




 
#line 350 "..\\M463_Library\\CMSIS\\Include\\cmsis_compiler.h"




#line 163 "..\\M463_Library\\CMSIS\\Include\\core_cm4.h"

















 
#line 207 "..\\M463_Library\\CMSIS\\Include\\core_cm4.h"

 






 
#line 223 "..\\M463_Library\\CMSIS\\Include\\core_cm4.h"

 




 













 



 






 



 
typedef union
{
  struct
  {
    uint32_t _reserved0:16;               
    uint32_t GE:4;                        
    uint32_t _reserved1:7;                
    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} APSR_Type;

 





















 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:23;               
  } b;                                    
  uint32_t w;                             
} IPSR_Type;

 






 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:1;                
    uint32_t ICI_IT_1:6;                  
    uint32_t GE:4;                        
    uint32_t _reserved1:4;                
    uint32_t T:1;                         
    uint32_t ICI_IT_2:2;                  
    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} xPSR_Type;

 

































 
typedef union
{
  struct
  {
    uint32_t nPRIV:1;                     
    uint32_t SPSEL:1;                     
    uint32_t FPCA:1;                      
    uint32_t _reserved0:29;               
  } b;                                    
  uint32_t w;                             
} CONTROL_Type;

 









 







 



 
typedef struct
{
  volatile uint32_t ISER[8U];                
        uint32_t RESERVED0[24U];
  volatile uint32_t ICER[8U];                
        uint32_t RSERVED1[24U];
  volatile uint32_t ISPR[8U];                
        uint32_t RESERVED2[24U];
  volatile uint32_t ICPR[8U];                
        uint32_t RESERVED3[24U];
  volatile uint32_t IABR[8U];                
        uint32_t RESERVED4[56U];
  volatile uint8_t  IP[240U];                
        uint32_t RESERVED5[644U];
  volatile  uint32_t STIR;                    
}  NVIC_Type;

 



 







 



 
typedef struct
{
  volatile const  uint32_t CPUID;                   
  volatile uint32_t ICSR;                    
  volatile uint32_t VTOR;                    
  volatile uint32_t AIRCR;                   
  volatile uint32_t SCR;                     
  volatile uint32_t CCR;                     
  volatile uint8_t  SHP[12U];                
  volatile uint32_t SHCSR;                   
  volatile uint32_t CFSR;                    
  volatile uint32_t HFSR;                    
  volatile uint32_t DFSR;                    
  volatile uint32_t MMFAR;                   
  volatile uint32_t BFAR;                    
  volatile uint32_t AFSR;                    
  volatile const  uint32_t PFR[2U];                 
  volatile const  uint32_t DFR;                     
  volatile const  uint32_t ADR;                     
  volatile const  uint32_t MMFR[4U];                
  volatile const  uint32_t ISAR[5U];                
        uint32_t RESERVED0[5U];
  volatile uint32_t CPACR;                   
} SCB_Type;

 















 






























 



 





















 









 


















 










































 









 


















 





















 


















 









 















 







 



 
typedef struct
{
        uint32_t RESERVED0[1U];
  volatile const  uint32_t ICTR;                    
  volatile uint32_t ACTLR;                   
} SCnSCB_Type;

 



 















 







 



 
typedef struct
{
  volatile uint32_t CTRL;                    
  volatile uint32_t LOAD;                    
  volatile uint32_t VAL;                     
  volatile const  uint32_t CALIB;                   
} SysTick_Type;

 












 



 



 









 







 



 
typedef struct
{
  volatile  union
  {
    volatile  uint8_t    u8;                  
    volatile  uint16_t   u16;                 
    volatile  uint32_t   u32;                 
  }  PORT [32U];                          
        uint32_t RESERVED0[864U];
  volatile uint32_t TER;                     
        uint32_t RESERVED1[15U];
  volatile uint32_t TPR;                     
        uint32_t RESERVED2[15U];
  volatile uint32_t TCR;                     
        uint32_t RESERVED3[29U];
  volatile  uint32_t IWR;                     
  volatile const  uint32_t IRR;                     
  volatile uint32_t IMCR;                    
        uint32_t RESERVED4[43U];
  volatile  uint32_t LAR;                     
  volatile const  uint32_t LSR;                     
        uint32_t RESERVED5[6U];
  volatile const  uint32_t PID4;                    
  volatile const  uint32_t PID5;                    
  volatile const  uint32_t PID6;                    
  volatile const  uint32_t PID7;                    
  volatile const  uint32_t PID0;                    
  volatile const  uint32_t PID1;                    
  volatile const  uint32_t PID2;                    
  volatile const  uint32_t PID3;                    
  volatile const  uint32_t CID0;                    
  volatile const  uint32_t CID1;                    
  volatile const  uint32_t CID2;                    
  volatile const  uint32_t CID3;                    
} ITM_Type;

 



 



























 



 



 



 









   







 



 
typedef struct
{
  volatile uint32_t CTRL;                    
  volatile uint32_t CYCCNT;                  
  volatile uint32_t CPICNT;                  
  volatile uint32_t EXCCNT;                  
  volatile uint32_t SLEEPCNT;                
  volatile uint32_t LSUCNT;                  
  volatile uint32_t FOLDCNT;                 
  volatile const  uint32_t PCSR;                    
  volatile uint32_t COMP0;                   
  volatile uint32_t MASK0;                   
  volatile uint32_t FUNCTION0;               
        uint32_t RESERVED0[1U];
  volatile uint32_t COMP1;                   
  volatile uint32_t MASK1;                   
  volatile uint32_t FUNCTION1;               
        uint32_t RESERVED1[1U];
  volatile uint32_t COMP2;                   
  volatile uint32_t MASK2;                   
  volatile uint32_t FUNCTION2;               
        uint32_t RESERVED2[1U];
  volatile uint32_t COMP3;                   
  volatile uint32_t MASK3;                   
  volatile uint32_t FUNCTION3;               
} DWT_Type;

 






















































 



 



 



 



 



 



 



























   







 



 
typedef struct
{
  volatile uint32_t SSPSR;                   
  volatile uint32_t CSPSR;                   
        uint32_t RESERVED0[2U];
  volatile uint32_t ACPR;                    
        uint32_t RESERVED1[55U];
  volatile uint32_t SPPR;                    
        uint32_t RESERVED2[131U];
  volatile const  uint32_t FFSR;                    
  volatile uint32_t FFCR;                    
  volatile const  uint32_t FSCR;                    
        uint32_t RESERVED3[759U];
  volatile const  uint32_t TRIGGER;                 
  volatile const  uint32_t FIFO0;                   
  volatile const  uint32_t ITATBCTR2;               
        uint32_t RESERVED4[1U];
  volatile const  uint32_t ITATBCTR0;               
  volatile const  uint32_t FIFO1;                   
  volatile uint32_t ITCTRL;                  
        uint32_t RESERVED5[39U];
  volatile uint32_t CLAIMSET;                
  volatile uint32_t CLAIMCLR;                
        uint32_t RESERVED7[8U];
  volatile const  uint32_t DEVID;                   
  volatile const  uint32_t DEVTYPE;                 
} TPI_Type;

 



 



 












 






 



 





















 



 





















 



 



 


















 






   








 



 
typedef struct
{
  volatile const  uint32_t TYPE;                    
  volatile uint32_t CTRL;                    
  volatile uint32_t RNR;                     
  volatile uint32_t RBAR;                    
  volatile uint32_t RASR;                    
  volatile uint32_t RBAR_A1;                 
  volatile uint32_t RASR_A1;                 
  volatile uint32_t RBAR_A2;                 
  volatile uint32_t RASR_A2;                 
  volatile uint32_t RBAR_A3;                 
  volatile uint32_t RASR_A3;                 
} MPU_Type;

 









 









 



 









 






























 








 



 
typedef struct
{
        uint32_t RESERVED0[1U];
  volatile uint32_t FPCCR;                   
  volatile uint32_t FPCAR;                   
  volatile uint32_t FPDSCR;                  
  volatile const  uint32_t MVFR0;                   
  volatile const  uint32_t MVFR1;                   
} FPU_Type;

 



























 



 












 
























 












 







 



 
typedef struct
{
  volatile uint32_t DHCSR;                   
  volatile  uint32_t DCRSR;                   
  volatile uint32_t DCRDR;                   
  volatile uint32_t DEMCR;                   
} CoreDebug_Type;

 




































 






 







































 







 






 







 


 







 

 
#line 1554 "..\\M463_Library\\CMSIS\\Include\\core_cm4.h"

#line 1563 "..\\M463_Library\\CMSIS\\Include\\core_cm4.h"









 










 


 



 





 

#line 1617 "..\\M463_Library\\CMSIS\\Include\\core_cm4.h"

#line 1627 "..\\M463_Library\\CMSIS\\Include\\core_cm4.h"













 
static __inline void __NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);              

  reg_value  =  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR;                                                    
  reg_value &= ~((uint32_t)((0xFFFFUL << 16U) | (7UL << 8U)));  
  reg_value  =  (reg_value                                   |
                ((uint32_t)0x5FAUL << 16U) |
                (PriorityGroupTmp << 8U)                      );               
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR =  reg_value;
}






 
static __inline uint32_t __NVIC_GetPriorityGrouping(void)
{
  return ((uint32_t)((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) >> 8U));
}







 
static __inline void __NVIC_EnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
  }
}









 
static __inline uint32_t __NVIC_GetEnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}







 
static __inline void __NVIC_DisableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);
  }
}









 
static __inline uint32_t __NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}







 
static __inline void __NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
  }
}







 
static __inline void __NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
  }
}









 
static __inline uint32_t __NVIC_GetActive(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IABR[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}










 
static __inline void __NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)(int32_t)IRQn)]               = (uint8_t)((priority << (8U - 4UL)) & (uint32_t)0xFFUL);
  }
  else
  {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)(int32_t)IRQn) & 0xFUL)-4UL] = (uint8_t)((priority << (8U - 4UL)) & (uint32_t)0xFFUL);
  }
}










 
static __inline uint32_t __NVIC_GetPriority(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) >= 0)
  {
    return(((uint32_t)((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)(int32_t)IRQn)]               >> (8U - 4UL)));
  }
  else
  {
    return(((uint32_t)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)(int32_t)IRQn) & 0xFUL)-4UL] >> (8U - 4UL)));
  }
}












 
static __inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);    
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(4UL)) ? (uint32_t)(4UL) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(4UL)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(4UL));

  return (
           ((PreemptPriority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
           ((SubPriority     & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL)))
         );
}












 
static __inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* const pPreemptPriority, uint32_t* const pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);    
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(4UL)) ? (uint32_t)(4UL) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(4UL)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(4UL));

  *pPreemptPriority = (Priority >> SubPriorityBits) & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL);
  *pSubPriority     = (Priority                   ) & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL);
}










 
static __inline void __NVIC_SetVector(IRQn_Type IRQn, uint32_t vector)
{
  uint32_t *vectors = (uint32_t *)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->VTOR;
  vectors[(int32_t)IRQn + 16] = vector;
}









 
static __inline uint32_t __NVIC_GetVector(IRQn_Type IRQn)
{
  uint32_t *vectors = (uint32_t *)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->VTOR;
  return vectors[(int32_t)IRQn + 16];
}





 
static __inline void __NVIC_SystemReset(void)
{
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                          
 
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR  = (uint32_t)((0x5FAUL << 16U)    |
                           (((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) |
                            (1UL << 2U)    );          
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                           

  for(;;)                                                            
  {
    __nop();
  }
}

 

 



#line 1 "..\\M463_Library\\CMSIS\\Include\\mpu_armv7.h"





 
















 
 



#line 56 "..\\M463_Library\\CMSIS\\Include\\mpu_armv7.h"

#line 63 "..\\M463_Library\\CMSIS\\Include\\mpu_armv7.h"





 













                          
#line 93 "..\\M463_Library\\CMSIS\\Include\\mpu_armv7.h"




 
typedef struct _ARM_MPU_Region_t {
  uint32_t RBAR; 
  uint32_t RASR; 
} ARM_MPU_Region_t;
    


 
static __inline void ARM_MPU_Enable(uint32_t MPU_Control)
{
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
  do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->CTRL = MPU_Control | (1UL );

  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHCSR |= (1UL << 16U);

}


 
static __inline void ARM_MPU_Disable()
{
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
  do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);

  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHCSR &= ~(1UL << 16U);

  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->CTRL  &= ~(1UL );
}



 
static __inline void ARM_MPU_ClrRegion(uint32_t rnr)
{
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RNR = rnr;
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RASR = 0u;
}




    
static __inline void ARM_MPU_SetRegion(uint32_t rbar, uint32_t rasr)
{
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RBAR = rbar;
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RASR = rasr;
}





    
static __inline void ARM_MPU_SetRegionEx(uint32_t rnr, uint32_t rbar, uint32_t rasr)
{
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RNR = rnr;
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RBAR = rbar;
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RASR = rasr;
}





 
static __inline void orderedCpy(volatile uint32_t* dst, const uint32_t* __restrict src, uint32_t len)
{
  uint32_t i;
  for (i = 0u; i < len; ++i) 
  {
    dst[i] = src[i];
  }
}




 
static __inline void ARM_MPU_Load(ARM_MPU_Region_t const* table, uint32_t cnt) 
{
  orderedCpy(&(((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RBAR), &(table->RBAR), cnt*sizeof(ARM_MPU_Region_t)/4u);
}

#line 1945 "..\\M463_Library\\CMSIS\\Include\\core_cm4.h"




 





 








 
static __inline uint32_t SCB_GetFPUType(void)
{
  uint32_t mvfr0;

  mvfr0 = ((FPU_Type *) ((0xE000E000UL) + 0x0F30UL) )->MVFR0;
  if      ((mvfr0 & ((0xFUL << 4U) | (0xFUL << 8U))) == 0x020U)
  {
    return 1U;            
  }
  else
  {
    return 0U;            
  }
}


 



 





 













 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > (0xFFFFFFUL ))
  {
    return (1UL);                                                    
  }

  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD  = (uint32_t)(ticks - 1UL);                          
  __NVIC_SetPriority (SysTick_IRQn, (1UL << 4UL) - 1UL);  
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL   = 0UL;                                              
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL  = (1UL << 2U) |
                   (1UL << 1U)   |
                   (1UL );                          
  return (0UL);                                                      
}



 



 





 

extern volatile int32_t ITM_RxBuffer;                               










 
static __inline uint32_t ITM_SendChar (uint32_t ch)
{
  if (((((ITM_Type *) (0xE0000000UL) )->TCR & (1UL )) != 0UL) &&       
      ((((ITM_Type *) (0xE0000000UL) )->TER & 1UL               ) != 0UL)   )      
  {
    while (((ITM_Type *) (0xE0000000UL) )->PORT[0U].u32 == 0UL)
    {
      __nop();
    }
    ((ITM_Type *) (0xE0000000UL) )->PORT[0U].u8 = (uint8_t)ch;
  }
  return (ch);
}







 
static __inline int32_t ITM_ReceiveChar (void)
{
  int32_t ch = -1;                            

  if (ITM_RxBuffer != ((int32_t)0x5AA55AA5U))
  {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = ((int32_t)0x5AA55AA5U);        
  }

  return (ch);
}







 
static __inline int32_t ITM_CheckChar (void)
{

  if (ITM_RxBuffer == ((int32_t)0x5AA55AA5U))
  {
    return (0);                               
  }
  else
  {
    return (1);                               
  }
}

 










#line 235 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\system_m460.h"
 






 








#line 18 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\system_m460.h"




 

























extern uint32_t SystemCoreClock;      
extern uint32_t CyclesPerUs;          
extern uint32_t PllClock;             










 
extern void SystemInit (void);









 
extern void SystemCoreClockUpdate (void);





#line 236 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 237 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"




#pragma anon_unions


 
 
 

#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\sys_reg.h"
 






 




#pragma anon_unions





 


 



 

typedef struct
{


    

























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 
    volatile const  uint32_t PDID;                   
    volatile uint32_t RSTSTS;                 
    volatile uint32_t IPRST0;                 
    volatile uint32_t IPRST1;                 
    volatile uint32_t IPRST2;                 
    volatile const  uint32_t RESERVE0[1];
    volatile uint32_t BODCTL;                 
    volatile uint32_t IVSCTL;                 
    volatile uint32_t IPRST3;                 
    volatile uint32_t PORCTL;                 
    volatile uint32_t VREFCTL;                
    volatile uint32_t USBPHY;                 
    volatile const  uint32_t RESERVE1[20];
    volatile uint32_t GPA_MFOS;               
    volatile uint32_t GPB_MFOS;               
    volatile uint32_t GPC_MFOS;               
    volatile uint32_t GPD_MFOS;               
    volatile uint32_t GPE_MFOS;               
    volatile uint32_t GPF_MFOS;               
    volatile uint32_t GPG_MFOS;               
    volatile uint32_t GPH_MFOS;               
    volatile uint32_t GPI_MFOS;               
    volatile uint32_t GPJ_MFOS;               
    volatile const  uint32_t RESERVE2[2];
    volatile const  uint32_t RESERVE3[4];
    volatile uint32_t SRAM_INTCTL;            
    volatile uint32_t SRAM_STATUS;            
    volatile const  uint32_t SRAM_ERRADDR;           
    volatile const  uint32_t RESERVE4[1];
    volatile uint32_t SRAM_BISTCTL;           
    volatile const  uint32_t SRAM_BISTSTS;           
    volatile const  uint32_t RESERVE5[3];
    volatile uint32_t HIRCTCTL;               
    volatile uint32_t HIRCTIEN;               
    volatile uint32_t HIRCTISTS;              
    volatile uint32_t IRCTCTL;                
    volatile uint32_t IRCTIEN;                
    volatile uint32_t IRCTISTS;               
    volatile const  uint32_t RESERVE6[1];
    volatile  uint32_t REGLCTL;                
    volatile const  uint32_t RESERVE7[58];
    volatile uint32_t PORDISAN;               
    volatile const  uint32_t RESERVE8[1];
    volatile const  uint32_t CSERVER;                
    volatile uint32_t PLCTL;                  
    volatile const  uint32_t PLSTS;                  
    volatile const  uint32_t RESERVE9[128];
    volatile uint32_t AHBMCTL;                
    volatile const  uint32_t RESERVE10[63];
    volatile uint32_t GPA_MFP0;               
    volatile uint32_t GPA_MFP1;               
    volatile uint32_t GPA_MFP2;               
    volatile uint32_t GPA_MFP3;               
    volatile uint32_t GPB_MFP0;               
    volatile uint32_t GPB_MFP1;               
    volatile uint32_t GPB_MFP2;               
    volatile uint32_t GPB_MFP3;               
    volatile uint32_t GPC_MFP0;               
    volatile uint32_t GPC_MFP1;               
    volatile uint32_t GPC_MFP2;               
    volatile uint32_t GPC_MFP3;               
    volatile uint32_t GPD_MFP0;               
    volatile uint32_t GPD_MFP1;               
    volatile uint32_t GPD_MFP2;               
    volatile uint32_t GPD_MFP3;               
    volatile uint32_t GPE_MFP0;               
    volatile uint32_t GPE_MFP1;               
    volatile uint32_t GPE_MFP2;               
    volatile uint32_t GPE_MFP3;               
    volatile uint32_t GPF_MFP0;               
    volatile uint32_t GPF_MFP1;               
    volatile uint32_t GPF_MFP2;               
    volatile uint32_t GPF_MFP3;               
    volatile uint32_t GPG_MFP0;               
    volatile uint32_t GPG_MFP1;               
    volatile uint32_t GPG_MFP2;               
    volatile uint32_t GPG_MFP3;               
    volatile uint32_t GPH_MFP0;               
    volatile uint32_t GPH_MFP1;               
    volatile uint32_t GPH_MFP2;               
    volatile uint32_t GPH_MFP3;               
    volatile uint32_t GPI_MFP0;               
    volatile uint32_t GPI_MFP1;               
    volatile uint32_t GPI_MFP2;               
    volatile uint32_t GPI_MFP3;               
    volatile uint32_t GPJ_MFP0;               
    volatile uint32_t GPJ_MFP1;               
    volatile uint32_t GPJ_MFP2;               
    volatile uint32_t GPJ_MFP3;               

} SYS_T;




 



















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































   
   




 

typedef struct
{


    



















































































































 
    volatile uint32_t NMIEN;                  
    volatile const  uint32_t NMISTS;                 

} NMI_T;




 



























































































   
   
   


#pragma no_anon_unions


#line 249 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\clk_reg.h"
 






 




#pragma anon_unions


 
 
 





 



 



 

typedef struct
{







































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 
    volatile uint32_t PWRCTL;                 
    volatile uint32_t AHBCLK0;                
    volatile uint32_t APBCLK0;                
    volatile uint32_t APBCLK1;                
    volatile uint32_t CLKSEL0;                
    volatile uint32_t CLKSEL1;                
    volatile uint32_t CLKSEL2;                
    volatile uint32_t CLKSEL3;                
    volatile uint32_t CLKDIV0;                
    volatile uint32_t CLKDIV1;                
    volatile uint32_t CLKDIV2;                
    volatile uint32_t CLKDIV3;                
    volatile uint32_t CLKDIV4;                
    volatile uint32_t PCLKDIV;                
    volatile uint32_t APBCLK2;                
    volatile uint32_t CLKDIV5;                
    volatile uint32_t PLLCTL;                 
    volatile const  uint32_t RESERVE0[1];
    volatile uint32_t PLLFNCTL0;              
    volatile uint32_t PLLFNCTL1;              
    volatile const  uint32_t STATUS;                 
    volatile const  uint32_t RESERVE1[1];
    volatile uint32_t AHBCLK1;                
    volatile uint32_t CLKSEL4;                
    volatile uint32_t CLKOCTL;                
    volatile const  uint32_t RESERVE3[3];
    volatile uint32_t CLKDCTL;                
    volatile uint32_t CLKDSTS;                
    volatile uint32_t CDUPB;                  
    volatile uint32_t CDLOWB;                 
    volatile uint32_t STOPREQ;                
    volatile const  uint32_t STOPACK;                
    volatile const  uint32_t RESERVE4[2];
    volatile uint32_t PMUCTL;                 
    volatile uint32_t PMUSTS;                 
    volatile const  uint32_t RESERVE5[1];
    volatile uint32_t SWKDBCTL;               
    volatile uint32_t PASWKCTL;               
    volatile uint32_t PBSWKCTL;               
    volatile uint32_t PCSWKCTL;               
    volatile uint32_t PDSWKCTL;               
    volatile uint32_t IOPDCTL;                

} CLK_T;




 












































































































































































































































































































































































































































































































































































































































































































































































































































































































































   
   
   


#pragma no_anon_unions


#line 250 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\fmc_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{
    









































































































































































































































































































































































 

    volatile uint32_t ISPCTL;                 
    volatile uint32_t ISPADDR;                
    volatile uint32_t ISPDAT;                 
    volatile uint32_t ISPCMD;                 
    volatile uint32_t ISPTRG;                 
    volatile const  uint32_t DFBA;                   
    
    volatile const  uint32_t RESERVE0[10];
    
    volatile uint32_t ISPSTS;                 
    
    volatile const  uint32_t RESERVE1[2];
    
    volatile uint32_t CYCCTL;                 
    
    volatile const  uint32_t RESERVE2[12];
    
    volatile uint32_t MPDAT0;                 
    volatile uint32_t MPDAT1;                 
    volatile uint32_t MPDAT2;                 
    volatile uint32_t MPDAT3;                 
    
    volatile const  uint32_t RESERVE3[12];
    
    volatile const  uint32_t MPSTS;                  
    volatile const  uint32_t MPADDR;                 
    
    volatile const  uint32_t RESERVE4[2];
    
    volatile const  uint32_t XOMR0STS;               
    volatile const  uint32_t XOMR1STS;               
    volatile const  uint32_t XOMR2STS;               
    volatile const  uint32_t XOMR3STS;               
    volatile const  uint32_t XOMSTS;                 
    volatile const  uint32_t RESERVE5[11];
    volatile uint32_t APPROT;                 

} FMC_T;




 




















































































































































































































































   
   
   


#pragma no_anon_unions


#line 251 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\gpio_reg.h"
 






 




#pragma anon_unions





 




 


typedef struct
{

    





































































































































































































































































 

    volatile uint32_t MODE;           
    volatile uint32_t DINOFF;         
    volatile uint32_t DOUT;           
    volatile uint32_t DATMSK;         
    volatile const  uint32_t PIN;            
    volatile uint32_t DBEN;           
    volatile uint32_t INTTYPE;        
    volatile uint32_t INTEN;          
    volatile uint32_t INTSRC;         
    volatile uint32_t SMTEN;          
    volatile uint32_t SLEWCTL;        
    
    volatile const  uint32_t RESERVE0[1];
    
    volatile uint32_t PUSEL;          
    volatile uint32_t DBCTL;          

} GPIO_T;

typedef struct
{

    














































 

    volatile uint32_t INT_INNF[8];    
    volatile const  uint32_t RESERVE1[8];
    volatile uint32_t INT_EDETCTL;    
    volatile const  uint32_t RESERVE2[1];
    volatile uint32_t INT_EDINTEN;    
    volatile uint32_t INT_EDSTS;      

} GPIO_INT_T;




 














































































































































































































































































































































































































































































































































































































































































































































   
   
   


#pragma no_anon_unions


#line 252 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\pdma_reg.h"
 






 




#pragma anon_unions





 




 


typedef struct
{

    





















































































 
    volatile uint32_t CTL;              
    volatile uint32_t SA;               
    volatile uint32_t DA;               
    volatile uint32_t NEXT;             
} DSCT_T;


typedef struct
{
    
















 
    volatile uint32_t STCR;            
    volatile uint32_t ASOCR;           
} STRIDE_T;

typedef struct
{
    
















 
    volatile uint32_t AICTL;          
    volatile uint32_t RCNT;           
} REPEAT_T;

typedef struct
{


    

































































































































































































































































































































































































































































































































































































































































































 
    DSCT_T DSCT[16];
    volatile const  uint32_t CURSCAT[16];            
    
    volatile const  uint32_t RESERVE1[176];
    
    volatile uint32_t CHCTL;                  
    volatile  uint32_t PAUSE;                  
    volatile  uint32_t SWREQ;                  
    volatile const  uint32_t TRGSTS;                 
    volatile uint32_t PRISET;                 
    volatile  uint32_t PRICLR;                 
    volatile uint32_t INTEN;                  
    volatile uint32_t INTSTS;                 
    volatile uint32_t ABTSTS;                 
    volatile uint32_t TDSTS;                  
    volatile uint32_t ALIGN;                  
    volatile const  uint32_t TACTSTS;                
    volatile uint32_t TOUTPSC0_7;             
    volatile uint32_t TOUTEN;                 
    volatile uint32_t TOUTIEN;                
    volatile uint32_t SCATBA;                 
    volatile uint32_t TOC0_1;                 
    volatile uint32_t TOC2_3;                 
    volatile uint32_t TOC4_5;                 
    volatile uint32_t TOC6_7;                 
    volatile uint32_t TOC8_9;                 
    volatile uint32_t TOC10_11;               
    volatile uint32_t TOC12_13;               
    volatile uint32_t TOC14_15;               
    volatile uint32_t CHRST;                  
    
    volatile const  uint32_t RESERVE2[1];
    
    volatile uint32_t TOUTPSC8_15;            
    
    volatile const  uint32_t RESERVE3[5];
    
    volatile uint32_t REQSEL0_3;              
    volatile uint32_t REQSEL4_7;              
    volatile uint32_t REQSEL8_11;             
    volatile uint32_t REQSEL12_15;            
    
    volatile const  uint32_t RESERVE4[28];
    
    STRIDE_T     STRIDE[6];
    
    volatile uint32_t RESERVE5[52];
    
    REPEAT_T    REPEAT[2];
} PDMA_T;




 













































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































   
   
   


#pragma no_anon_unions


#line 253 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\timer_reg.h"
 






 




#pragma anon_unions





 

 




 

typedef struct
{


    































































































































































































































































































































































































































































































































































































































































































































































































 
    volatile uint32_t CTL;                    
    volatile uint32_t CMP;                    
    volatile uint32_t INTSTS;                 
    volatile uint32_t CNT;                    
    volatile const  uint32_t CAP;                    
    volatile uint32_t EXTCTL;                 
    volatile uint32_t EINTSTS;                
    volatile uint32_t TRGCTL;                 
    volatile uint32_t ALTCTL;                 
    volatile uint32_t CAPNF;                  
     
    volatile const  uint32_t RESERVE0[6];
     
    volatile uint32_t PWMCTL;                 
    volatile uint32_t PWMCLKSRC;              
    volatile uint32_t PWMCLKPSC;              
    volatile uint32_t PWMCNTCLR;              
    volatile uint32_t PWMPERIOD;              
    volatile uint32_t PWMCMPDAT;              
    volatile uint32_t PWMDTCTL;               
    volatile const  uint32_t PWMCNT;                 
    volatile uint32_t PWMMSKEN;               
    volatile uint32_t PWMMSK;                 
    volatile uint32_t PWMBNF;                 
    volatile uint32_t PWMFAILBRK;             
    volatile uint32_t PWMBRKCTL;              
    volatile uint32_t PWMPOLCTL;              
    volatile uint32_t PWMPOEN;                
    volatile  uint32_t PWMSWBRK;               
    volatile uint32_t PWMINTEN0;              
    volatile uint32_t PWMINTEN1;              
    volatile uint32_t PWMINTSTS0;             
    volatile uint32_t PWMINTSTS1;             
    volatile uint32_t PWMTRGCTL;              
    volatile uint32_t PWMSCTL;                
    volatile  uint32_t PWMSTRG;                
    volatile uint32_t PWMSTATUS;              
    volatile const  uint32_t PWMPBUF;                
    volatile const  uint32_t PWMCMPBUF;              
    volatile uint32_t PWMIFA;                 
    volatile uint32_t PWMAINTSTS;             
    volatile uint32_t PWMAINTEN;              
    volatile uint32_t PWMAPDMACTL;            
    volatile uint32_t PWMEXTETCTL;            

} TIMER_T;




 



















































































































































































































































































































































































   
   
   


#pragma no_anon_unions


#line 254 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\wdt_reg.h"
 






 




#pragma anon_unions




 

 




 

typedef struct
{


    






















































































 
    volatile uint32_t CTL;                    
    volatile uint32_t ALTCTL;                 
    volatile  uint32_t RSTCNT;                 

} WDT_T;





 






































   
   
   


#pragma no_anon_unions


#line 255 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\wwdt_reg.h"
 






 




#pragma anon_unions




 

 




 

typedef struct
{


    





































































 
    volatile  uint32_t RLDCNT;                 
    volatile uint32_t CTL;                    
    volatile uint32_t STATUS;                 
    volatile const  uint32_t CNT;                    

} WWDT_T;






 





























   
   
   


#pragma no_anon_unions


#line 256 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\rtc_reg.h"
 






 




#pragma anon_unions




 

 




 

typedef struct
{


    























































































































































































































































































































































































































































































































































































































































































 
    volatile uint32_t INIT;                   
    volatile const uint32_t  RESERVE0[1];            
    volatile uint32_t FREQADJ;                
    volatile uint32_t TIME;                   
    volatile uint32_t CAL;                    
    volatile uint32_t CLKFMT;                 
    volatile uint32_t WEEKDAY;                
    volatile uint32_t TALM;                   
    volatile uint32_t CALM;                   
    volatile const  uint32_t LEAPYEAR;               
    volatile uint32_t INTEN;                  
    volatile uint32_t INTSTS;                 
    volatile uint32_t TICK;                   
    volatile uint32_t TAMSK;                  
    volatile uint32_t CAMSK;                  
    volatile uint32_t SPRCTL;                 
    volatile uint32_t SPR[20];                
    volatile const  uint32_t RESERVE1[28];           
    volatile uint32_t LXTCTL;                 
    volatile uint32_t GPIOCTL0;               
    volatile uint32_t GPIOCTL1;               
    volatile const  uint32_t RESERVE2[1];            
    volatile uint32_t DSTCTL;                 
    volatile const  uint32_t RESERVE3[3];            
    volatile uint32_t TAMPCTL;                
    volatile const  uint32_t RESERVE4[1];            
    volatile uint32_t TAMPSEED;               
    volatile const  uint32_t RESERVE5[1];            
    volatile const  uint32_t TAMPTIME;               
    volatile const  uint32_t TAMPCAL;                

} RTC_T;





 











































































































































































































































































































































































































































































































   
   
   


#pragma no_anon_unions


#line 257 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\epwm_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{
    














 
    volatile uint32_t RCAPDAT;  
    volatile uint32_t FCAPDAT;  
} ECAPDAT_T;

typedef struct
{


    









































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 
    volatile uint32_t CTL0;                   
    volatile uint32_t CTL1;                   
    volatile uint32_t SYNC;                   
    volatile uint32_t SWSYNC;                 
    volatile uint32_t CLKSRC;                 
    
    volatile const  uint32_t RESERVE0[3];
    
    volatile uint32_t CNTEN;                  
    volatile uint32_t CNTCLR;                 
    volatile uint32_t LOAD;                   
    
    volatile const  uint32_t RESERVE1[1];
    
    volatile uint32_t PERIOD[6];              
    
    volatile const  uint32_t RESERVE2[2];
    
    volatile uint32_t CMPDAT[6];              
    
    volatile const  uint32_t RESERVE3[6];
    
    volatile uint32_t PHS[3];                 
    
    volatile const  uint32_t RESERVE4[1];
    
    volatile const  uint32_t CNT[6];                 
    
    volatile const  uint32_t RESERVE5[2];
    
    volatile uint32_t WGCTL0;                 
    volatile uint32_t WGCTL1;                 
    volatile uint32_t MSKEN;                  
    volatile uint32_t MSK;                    
    volatile uint32_t BNF;                    
    volatile uint32_t FAILBRK;                
    volatile uint32_t BRKCTL[3];              
    volatile uint32_t POLCTL;                 
    volatile uint32_t POEN;                   
    volatile  uint32_t SWBRK;                  
    volatile uint32_t INTEN0;                 
    volatile uint32_t INTEN1;                 
    volatile uint32_t INTSTS0;                
    volatile uint32_t INTSTS1;                
    
    volatile const  uint32_t RESERVE6[1];
    
    volatile uint32_t DACTRGEN;               
    volatile uint32_t EADCTS0;                
    volatile uint32_t EADCTS1;                
    volatile uint32_t FTCMPDAT[3];            
    
    volatile const  uint32_t RESERVE7[1];
    
    volatile uint32_t SSCTL;                  
    volatile  uint32_t SSTRG;                  
    volatile uint32_t LEBCTL;                 
    volatile uint32_t LEBCNT;                 
    volatile uint32_t STATUS;                 
    
    volatile const  uint32_t RESERVE8[3];
    
    volatile uint32_t IFA[6];                 
    
    volatile const  uint32_t RESERVE9[2];
    
    volatile uint32_t AINTSTS;                
    volatile uint32_t AINTEN;                 
    volatile uint32_t APDMACTL;               
    
    volatile const  uint32_t RESERVE10[1];
    
    volatile uint32_t FDEN;                   
    volatile uint32_t FDCTL[6];               
    volatile uint32_t FDIEN;                  
    volatile uint32_t FDSTS;                  
    volatile uint32_t EADCPSCCTL;             
    volatile uint32_t EADCPSC0;               
    volatile uint32_t EADCPSC1;               
    volatile uint32_t EADCPSCNT0;             
    volatile uint32_t EADCPSCNT1;             
    
    volatile const  uint32_t RESERVE11[26];
    
    volatile uint32_t CAPINEN;                
    volatile uint32_t CAPCTL;                 
    volatile const  uint32_t CAPSTS;                 
    ECAPDAT_T CAPDAT[6];                  
    volatile uint32_t PDMACTL;                
    volatile const  uint32_t PDMACAP[3];             
    
    volatile const  uint32_t RESERVE12[1];
    
    volatile uint32_t CAPIEN;                 
    volatile uint32_t CAPIF;                  
	volatile uint32_t CAPNF[6];               
	volatile uint32_t EXTETCTL[6];            
	volatile uint32_t SWEOFCTL;           	  
	volatile uint32_t SWEOFTRG;           	  
	volatile uint32_t CLKPSC[6];              
	volatile uint32_t RDTCNT[3];              
	volatile uint32_t FDTCNT[3];              
	volatile uint32_t DTCTL;            	  
    
    volatile const  uint32_t RESERVE13[16];
    
    volatile const  uint32_t PBUF[6];                
    volatile const  uint32_t CMPBUF[6];              
    
    volatile const  uint32_t RESERVE14[3];
    
    volatile const  uint32_t FTCBUF[3];              
    volatile uint32_t FTCI;                   
    volatile const  uint32_t CPSCBUF[5];             
    volatile const  uint32_t IFACNT[5];              

} EPWM_T;




 









































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































   
   
   


#pragma no_anon_unions


#line 258 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\bpwm_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{
    














 
    volatile uint32_t RCAPDAT;  
    volatile uint32_t FCAPDAT;  
} BCAPDAT_T;

typedef struct
{


    


























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 
    volatile uint32_t CTL0;                   
    volatile uint32_t CTL1;                   
    
    volatile const  uint32_t RESERVE0[2];
    
    volatile uint32_t CLKSRC;                 
    volatile uint32_t CLKPSC;                 
    
    volatile const  uint32_t RESERVE1[2];
    
    volatile uint32_t CNTEN;                  
    volatile uint32_t CNTCLR;                 
    
    volatile const  uint32_t RESERVE2[2];
    
    volatile uint32_t PERIOD;                 
    
    volatile const  uint32_t RESERVE3[7];
    
    volatile uint32_t CMPDAT[6];              
    
    volatile const  uint32_t RESERVE4[10];
    
    volatile const  uint32_t CNT;                    
    
    volatile const  uint32_t RESERVE5[7];
    
    volatile uint32_t WGCTL0;                 
    volatile uint32_t WGCTL1;                 
    volatile uint32_t MSKEN;                  
    volatile uint32_t MSK;                    
    
    volatile const  uint32_t RESERVE6[5];
    
    volatile uint32_t POLCTL;                 
    volatile uint32_t POEN;                   
    
    volatile const  uint32_t RESERVE7[1];
    
    volatile uint32_t INTEN;                  
    
    volatile const  uint32_t RESERVE8[1];
    
    volatile uint32_t INTSTS;                 
    
    volatile const  uint32_t RESERVE9[3];
    
    volatile uint32_t EADCTS0;                
    volatile uint32_t EADCTS1;                
    
    volatile const  uint32_t RESERVE10[4];
    
    volatile uint32_t SSCTL;                  
    volatile  uint32_t SSTRG;                  
    
    volatile const  uint32_t RESERVE11[2];
    
    volatile uint32_t STATUS;                 
    
    volatile const  uint32_t RESERVE12[55];
    
    volatile uint32_t CAPINEN;                
    volatile uint32_t CAPCTL;                 
    volatile const  uint32_t CAPSTS;                 
    BCAPDAT_T CAPDAT[6];                   
    
    volatile const  uint32_t RESERVE13[5];
    
    volatile uint32_t CAPIEN;                 
    volatile uint32_t CAPIF;                  
    
    volatile const  uint32_t RESERVE14[43];
    
    volatile const  uint32_t PBUF;                   
    
    volatile const  uint32_t RESERVE15[5];
    
    volatile const  uint32_t CMPBUF[6];              

} BPWM_T;




 






























































































































































































































































































































































































































































































































































































































































































   
   
   


#pragma no_anon_unions


#line 259 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\eqei_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{


    












































































































































































































































 
    volatile uint32_t CNT;                    
    volatile uint32_t CNTHOLD;                
    volatile uint32_t CNTLATCH;               
    volatile uint32_t CNTCMP;                 
    
    volatile const  uint32_t RESERVE0[1];
    
    volatile uint32_t CNTMAX;                 
    volatile uint32_t CTL;                    
    volatile uint32_t CTL2;                   
    volatile uint32_t UTCNT;                  
    volatile uint32_t UTCMP;                  
    
    volatile const  uint32_t RESERVE1[1];
    
    volatile uint32_t STATUS;                 

} EQEI_T;




 


















































































































































   
   
   


#pragma no_anon_unions


#line 260 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\ecap_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{

    

















































































































































































































 
    volatile uint32_t CNT;                    
    volatile uint32_t HLD0;                   
    volatile uint32_t HLD1;                   
    volatile uint32_t HLD2;                   
    volatile uint32_t CNTCMP;                 
    volatile uint32_t CTL0;                   
    volatile uint32_t CTL1;                   
    volatile uint32_t STATUS;                 

} ECAP_T;




 































































































































   
   
   


#pragma no_anon_unions


#line 261 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\uart_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{


    




















































































































































































































































































































































































































































































































































































































































































































































































































































 
    volatile uint32_t DAT;                    
    volatile uint32_t INTEN;                  
    volatile uint32_t FIFO;                   
    volatile uint32_t LINE;                   
    volatile uint32_t MODEM;                  
    volatile uint32_t MODEMSTS;               
    volatile uint32_t FIFOSTS;                
    volatile uint32_t INTSTS;                 
    volatile uint32_t TOUT;                   
    volatile uint32_t BAUD;                   
    volatile uint32_t IRDA;                   
    volatile uint32_t ALTCTL;                 
    volatile uint32_t FUNCSEL;                
    volatile uint32_t LINCTL;                 
    volatile uint32_t LINSTS;                 
    volatile uint32_t BRCOMP;                 
    volatile uint32_t WKCTL;                  
    volatile uint32_t WKSTS;                  
    volatile uint32_t DWKCOMP;                
    volatile uint32_t RS485DD;                

} UART_T;




 














































































































































































































































































































































































































































   
   
   


#pragma no_anon_unions


#line 262 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\emac_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{

    












































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 
    volatile uint32_t CAMCTL;                 
    volatile uint32_t CAMEN;                  
    volatile uint32_t CAM0M;                  
    volatile uint32_t CAM0L;                  
    volatile uint32_t CAM1M;                  
    volatile uint32_t CAM1L;                  
    volatile uint32_t CAM2M;                  
    volatile uint32_t CAM2L;                  
    volatile uint32_t CAM3M;                  
    volatile uint32_t CAM3L;                  
    volatile uint32_t CAM4M;                  
    volatile uint32_t CAM4L;                  
    volatile uint32_t CAM5M;                  
    volatile uint32_t CAM5L;                  
    volatile uint32_t CAM6M;                  
    volatile uint32_t CAM6L;                  
    volatile uint32_t CAM7M;                  
    volatile uint32_t CAM7L;                  
    volatile uint32_t CAM8M;                  
    volatile uint32_t CAM8L;                  
    volatile uint32_t CAM9M;                  
    volatile uint32_t CAM9L;                  
    volatile uint32_t CAM10M;                 
    volatile uint32_t CAM10L;                 
    volatile uint32_t CAM11M;                 
    volatile uint32_t CAM11L;                 
    volatile uint32_t CAM12M;                 
    volatile uint32_t CAM12L;                 
    volatile uint32_t CAM13M;                 
    volatile uint32_t CAM13L;                 
    volatile uint32_t CAM14M;                 
    volatile uint32_t CAM14L;                 
    volatile uint32_t CAM15MSB;               
    volatile uint32_t CAM15LSB;               
    volatile uint32_t TXDSA;                  
    volatile uint32_t RXDSA;                  
    volatile uint32_t CTL;                    
    volatile uint32_t MIIMDAT;                
    volatile uint32_t MIIMCTL;                
    volatile uint32_t FIFOCTL;                
    volatile  uint32_t TXST;                   
    volatile  uint32_t RXST;                   
    volatile uint32_t MRFL;                   
    volatile uint32_t INTEN;                  
    volatile uint32_t INTSTS;                 
    volatile uint32_t GENSTS;                 
    volatile uint32_t MPCNT;                  
    volatile const  uint32_t RPCNT;                  
     
    volatile const  uint32_t RESERVE0[2];
     
    volatile uint32_t FRSTS;                  
    volatile const  uint32_t CTXDSA;                 
    volatile const  uint32_t CTXBSA;                 
    volatile const  uint32_t CRXDSA;                 
    volatile const  uint32_t CRXBSA;                 
     
    volatile const  uint32_t RESERVE1[9];
     
    volatile uint32_t TSCTL;                  
     
    volatile const  uint32_t RESERVE2[3];
     
    volatile const  uint32_t TSSEC;                  
    volatile const  uint32_t TSSUBSEC;               
    volatile uint32_t TSINC;                  
    volatile uint32_t TSADDEND;               
    volatile uint32_t UPDSEC;                 
    volatile uint32_t UPDSUBSEC;              
    volatile uint32_t ALMSEC;                 
    volatile uint32_t ALMSUBSEC;              

} EMAC_T;




 














































































































































































































































































































































































































































































































































































































































   
   
   


#pragma no_anon_unions


#line 263 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\sc_reg.h"
 






 




#pragma anon_unions




 

 




 

typedef struct
{


    













































































































































































































































































































































































































































































































































































































































































 
    volatile uint32_t DAT;                    
    volatile uint32_t CTL;                    
    volatile uint32_t ALTCTL;                 
    volatile uint32_t EGT;                    
    volatile uint32_t RXTOUT;                 
    volatile uint32_t ETUCTL;                 
    volatile uint32_t INTEN;                  
    volatile uint32_t INTSTS;                 
    volatile uint32_t STATUS;                 
    volatile uint32_t PINCTL;                 
    volatile uint32_t TMRCTL0;                
    volatile uint32_t TMRCTL1;                
    volatile uint32_t TMRCTL2;                
    volatile uint32_t UARTCTL;                
     
    volatile const  uint32_t RESERVE0[5];
     
    volatile uint32_t ACTCTL;                 

} SC_T;





 














































































































































































































































































































   
   
   


#pragma no_anon_unions


#line 264 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\i2s_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{


    













































































































































































































































































































































































































































 
    volatile uint32_t CTL0;                   
    volatile uint32_t CLKDIV;                 
    volatile uint32_t IEN;                    
    volatile uint32_t STATUS0;                
    volatile  uint32_t TXFIFO;                 
    volatile const  uint32_t RXFIFO;                 
    
    volatile const  uint32_t RESERVE0[2];
    
    volatile uint32_t CTL1;                   
    volatile uint32_t STATUS1;                

} I2S_T;




 




























































































































































































































   
   
   


#pragma no_anon_unions


#line 265 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\spi_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{


    


















































































































































































































































































































































































































































































































 
    volatile uint32_t CTL;                    
    volatile uint32_t CLKDIV;                 
    volatile uint32_t SSCTL;                  
    volatile uint32_t PDMACTL;                
    volatile uint32_t FIFOCTL;                
    volatile uint32_t STATUS;                 
    volatile const  uint32_t STATUS2;                
    
    volatile const  uint32_t RESERVE0[1];
    
    volatile  uint32_t TX;                     
    
    volatile const  uint32_t RESERVE1[3];
    
    volatile const  uint32_t RX;                     
    
    volatile const  uint32_t RESERVE2[11];
    
    volatile uint32_t I2SCTL;                 
    volatile uint32_t I2SCLK;                 
    volatile uint32_t I2SSTS;                 

} SPI_T;




 







































































































































































































































































































   
   
   


#pragma no_anon_unions


#line 266 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\qspi_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{


    




























































































































































































































































































































































 
    volatile uint32_t CTL;                    
    volatile uint32_t CLKDIV;                 
    volatile uint32_t SSCTL;                  
    volatile uint32_t PDMACTL;                
    volatile uint32_t FIFOCTL;                
    volatile uint32_t STATUS;                 
    volatile const  uint32_t STATUS2;                
    
    volatile const  uint32_t RESERVE0[1];
    
    volatile  uint32_t TX;                     
    
    volatile const  uint32_t RESERVE1[3];
    
    volatile const  uint32_t RX;                     

} QSPI_T;




 

















































































































































































































   
   
   


#pragma no_anon_unions


#line 267 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\spim_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{


    

























































































































































































































































































































































































 
    volatile uint32_t CTL0;                   
    volatile uint32_t CTL1;                   
    
    volatile const  uint32_t RESERVE0[1];
    
    volatile uint32_t RXCLKDLY;               
    volatile const  uint32_t RX[4];                  
    volatile uint32_t TX[4];                  
    volatile uint32_t SRAMADDR;               
    volatile uint32_t DMACNT;                 
    volatile uint32_t FADDR;                  
    volatile  uint32_t KEY1;                   
    volatile  uint32_t KEY2;                   
    volatile uint32_t DMMCTL;                 
    volatile uint32_t CTL2;                   

} SPIM_T;




 






















































































































   
   
   


#pragma no_anon_unions


#line 268 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\i2c_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{


    


































































































































































































































































































































































































































































































 
    volatile uint32_t CTL0;                   
    volatile uint32_t ADDR0;                  
    volatile uint32_t DAT;                    
    volatile const  uint32_t STATUS0;                
    volatile uint32_t CLKDIV;                 
    volatile uint32_t TOCTL;                  
    volatile uint32_t ADDR1;                  
    volatile uint32_t ADDR2;                  
    volatile uint32_t ADDR3;                  
    volatile uint32_t ADDRMSK0;               
    volatile uint32_t ADDRMSK1;               
    volatile uint32_t ADDRMSK2;               
    volatile uint32_t ADDRMSK3;               
    
    volatile const  uint32_t RESERVE0[2];
    
    volatile uint32_t WKCTL;                  
    volatile uint32_t WKSTS;                  
    volatile uint32_t CTL1;                   
    volatile uint32_t STATUS1;                
    volatile uint32_t TMCTL;                  
    volatile uint32_t BUSCTL;                 
    volatile uint32_t BUSTCTL;                
    volatile uint32_t BUSSTS;                 
    volatile uint32_t PKTSIZE;                
    volatile const  uint32_t PKTCRC;                 
    volatile uint32_t BUSTOUT;                
    volatile uint32_t CLKTOUT;                

} I2C_T;




 



































































































































































































































































   
   
   


#pragma no_anon_unions


#line 269 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\uuart_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{


    















































































































































































































































































































































































































 
    volatile uint32_t CTL;                    
    volatile uint32_t INTEN;                  
    volatile uint32_t BRGEN;                  
    
    volatile const  uint32_t RESERVE0[1];
    
    volatile uint32_t DATIN0;                 
    
    volatile const  uint32_t RESERVE1[3];
    
    volatile uint32_t CTLIN0;                 
    
    volatile const  uint32_t RESERVE2[1];
    
    volatile uint32_t CLKIN;                  
    volatile uint32_t LINECTL;                
    volatile uint32_t TXDAT;                  
    volatile uint32_t RXDAT;                  
    volatile uint32_t BUFCTL;                 
    volatile uint32_t BUFSTS;                 
    volatile uint32_t PDMACTL;                
    
    volatile const  uint32_t RESERVE3[4];
    
    volatile uint32_t WKCTL;                  
    volatile uint32_t WKSTS;                  
    volatile uint32_t PROTCTL;                
    volatile uint32_t PROTIEN;                
    volatile uint32_t PROTSTS;                

} UUART_T;




 






















































































































































































































   
   
   


#pragma no_anon_unions


#line 270 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\uspi_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{


    












































































































































































































































































































































































































 
    volatile uint32_t CTL;                    
    volatile uint32_t INTEN;                  
    volatile uint32_t BRGEN;                  
    
    volatile const  uint32_t RESERVE0[1];
    
    volatile uint32_t DATIN0;                 
    
    volatile const  uint32_t RESERVE1[3];
    
    volatile uint32_t CTLIN0;                 
    
    volatile const  uint32_t RESERVE2[1];
    
    volatile uint32_t CLKIN;                  
    volatile uint32_t LINECTL;                
    volatile  uint32_t TXDAT;                  
    volatile const  uint32_t RXDAT;                  
    volatile uint32_t BUFCTL;                 
    volatile uint32_t BUFSTS;                 
    volatile uint32_t PDMACTL;                
    
    volatile const  uint32_t RESERVE3[4];
    
    volatile uint32_t WKCTL;                  
    volatile uint32_t WKSTS;                  
    volatile uint32_t PROTCTL;                
    volatile uint32_t PROTIEN;                
    volatile uint32_t PROTSTS;                

} USPI_T;




 













































































































































































































   
   
   


#pragma no_anon_unions


#line 271 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\ui2c_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{


    






















































































































































































































































































































































 
    volatile uint32_t CTL;                    
    
    volatile const  uint32_t RESERVE0[1];
    
    volatile uint32_t BRGEN;                  
    
    volatile const  uint32_t RESERVE1[8];
    
    volatile uint32_t LINECTL;                
    volatile  uint32_t TXDAT;                  
    volatile const  uint32_t RXDAT;                  
    
    volatile const  uint32_t RESERVE2[3];
    
    volatile uint32_t DEVADDR0;               
    volatile uint32_t DEVADDR1;               
    volatile uint32_t ADDRMSK0;               
    volatile uint32_t ADDRMSK1;               
    volatile uint32_t WKCTL;                  
    volatile uint32_t WKSTS;                  
    volatile uint32_t PROTCTL;                
    volatile uint32_t PROTIEN;                
    volatile uint32_t PROTSTS;                
    
    volatile const  uint32_t RESERVE3[8];
    
    volatile uint32_t ADMAT;                  
    volatile uint32_t TMCTL;                  

} UI2C_T;




 






































































































































































   
   
   


#pragma no_anon_unions


#line 272 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\canfd_reg.h"
 






 





    #pragma anon_unions





 




 

typedef struct
{

    






























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 
    
    volatile const  uint32_t RESERVE0[3];
    
    volatile uint32_t DBTP;                  
    volatile uint32_t TEST;                  
    volatile uint32_t RWD;                   
    volatile uint32_t CCCR;                  
    volatile uint32_t NBTP;                  
    volatile uint32_t TSCC;                  
    volatile uint32_t TSCV;                  
    volatile uint32_t TOCC;                  
    volatile uint32_t TOCV;                  
    
    volatile const  uint32_t RESERVE1[4];
    
    volatile const  uint32_t ECR;                   
    volatile const  uint32_t PSR;                   
    volatile uint32_t TDCR;                  
    
    volatile const  uint32_t RESERVE2[1];
    
    volatile uint32_t IR;                    
    volatile uint32_t IE;                    
    volatile uint32_t ILS;                   
    volatile uint32_t ILE;                   
    
    volatile const  uint32_t RESERVE3[8];
    
    volatile uint32_t GFC;                   
    volatile uint32_t SIDFC;                 
    volatile uint32_t XIDFC;                 
    
    volatile const  uint32_t RESERVE4[1];
    
    volatile uint32_t XIDAM;                 
    volatile const  uint32_t HPMS;                  
    volatile uint32_t NDAT1;                 
    volatile uint32_t NDAT2;                 
    volatile uint32_t RXF0C;                 
    volatile uint32_t RXF0S;                 
    volatile uint32_t RXF0A;                 
    volatile uint32_t RXBC;                  
    volatile uint32_t RXF1C;                 
    volatile uint32_t RXF1S;                 
    volatile uint32_t RXF1A;                 
    volatile uint32_t RXESC;                 
    volatile uint32_t TXBC;                  
    volatile uint32_t TXFQS;                 
    volatile uint32_t TXESC;                 
    volatile uint32_t TXBRP;                 
    volatile uint32_t TXBAR;                 
    volatile uint32_t TXBCR;                 
    volatile uint32_t TXBTO;                 
    volatile uint32_t TXBCF;                 
    volatile uint32_t TXBTIE;                
    volatile uint32_t TXBCIE;                
    
    volatile const  uint32_t RESERVE5[2];
    
    volatile uint32_t TXEFC;                 
    volatile uint32_t TXEFS;                 
    volatile uint32_t TXEFA;                 

} CANFD_T;




 





































































































































































































































































































































































































































































































































































































































   
   
   


    #pragma no_anon_unions


#line 273 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\sdh_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{

    





















































































































































































































































































































 

    volatile uint32_t FB[32];                 
    
    volatile const  uint32_t RESERVE0[224];
    
    volatile uint32_t DMACTL;                 
    
    volatile const  uint32_t RESERVE1[1];
    
    volatile uint32_t DMASA;                  
    volatile const  uint32_t DMABCNT;                
    volatile uint32_t DMAINTEN;               
    volatile uint32_t DMAINTSTS;              
    
    volatile const  uint32_t RESERVE2[250];
    
    volatile uint32_t GCTL;                   
    volatile uint32_t GINTEN;                 
    volatile uint32_t GINTSTS;                
    
    volatile const  uint32_t RESERVE3[5];
    
    volatile uint32_t CTL;                    
    volatile uint32_t CMDARG;                 
    volatile uint32_t INTEN;                  
    volatile uint32_t INTSTS;                 
    volatile const  uint32_t RESP0;                  
    volatile const  uint32_t RESP1;                  
    volatile uint32_t BLEN;                   
    volatile uint32_t TOUT;                   

} SDH_T;





 


























































































































































   
   
   


#pragma no_anon_unions




#line 274 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\ebi_reg.h"
 






 




#pragma anon_unions




 

 




 

typedef struct
{


    



































































 
    volatile uint32_t CTL0;                   
    volatile uint32_t TCTL0;                  
    volatile const  uint32_t RESERVE0[2];
    volatile uint32_t CTL1;                   
    volatile uint32_t TCTL1;                  
    volatile const  uint32_t RESERVE1[2];
    volatile uint32_t CTL2;                   
    volatile uint32_t TCTL2;                  

} EBI_T;





 












































   
   
   


#pragma no_anon_unions


#line 275 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\usbd_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{

    































































 
    volatile uint32_t BUFSEG;                
    volatile uint32_t MXPLD;                 
    volatile uint32_t CFG;                   
    volatile uint32_t CFGP;                  

} USBD_EP_T;

typedef struct
{


    













































































































































































































































































































 

    volatile uint32_t INTEN;                  
    volatile uint32_t INTSTS;                 
    volatile uint32_t FADDR;                  
    volatile const  uint32_t EPSTS;                  
    volatile uint32_t ATTR;                   
    volatile const  uint32_t VBUSDET;                
    volatile uint32_t STBUFSEG;               
    
    volatile const  uint32_t RESERVE0[1];
    
    volatile const  uint32_t EPSTS0;                 
    volatile const  uint32_t EPSTS1;                 
    volatile const  uint32_t EPSTS2;                 
    volatile const  uint32_t EPSTS3;                 
    volatile uint32_t EPINTSTS;               
    
    volatile const  uint32_t RESERVE1[21];
    
    volatile const  uint32_t LPMATTR;                
    volatile const  uint32_t FN;                     
    volatile uint32_t SE0;                    
    
    volatile const  uint32_t RESERVE2[283];
    
    USBD_EP_T     EP[25];                 

} USBD_T;





 


































































































































































































































































































































   
   
   


#pragma no_anon_unions


#line 276 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\hsusbd_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{

    























































































































































































































































 

    union
    {
        volatile uint32_t EPDAT;
        volatile uint8_t  EPDAT_BYTE;

    };                                   

    volatile uint32_t EPINTSTS;              
    volatile uint32_t EPINTEN;               
    volatile const  uint32_t EPDATCNT;              
    volatile uint32_t EPRSPCTL;              
    volatile uint32_t EPMPS;                 
    volatile uint32_t EPTXCNT;               
    volatile uint32_t EPCFG;                 
    volatile uint32_t EPBUFST;               
    volatile uint32_t EPBUFEND;              

} HSUSBD_EP_T;

typedef struct
{

    




















































































































































































































































































































































































































































































































































































 

    volatile const  uint32_t GINTSTS;                
    
    volatile const  uint32_t RESERVE0[1];
    
    volatile uint32_t GINTEN;                 
    
    volatile const  uint32_t RESERVE1[1];
    
    volatile uint32_t BUSINTSTS;              
    volatile uint32_t BUSINTEN;               
    volatile uint32_t OPER;                   
    volatile const  uint32_t FRAMECNT;               
    volatile uint32_t FADDR;                  
    volatile uint32_t TEST;                   

    union
    {
        volatile uint32_t CEPDAT;
        volatile uint8_t  CEPDAT_BYTE;

    };                                    

    volatile uint32_t CEPCTL;                 
    volatile uint32_t CEPINTEN;               
    volatile uint32_t CEPINTSTS;              
    volatile uint32_t CEPTXCNT;               
    volatile const  uint32_t CEPRXCNT;               
    volatile const  uint32_t CEPDATCNT;              
    volatile const  uint32_t SETUP1_0;               
    volatile const  uint32_t SETUP3_2;               
    volatile const  uint32_t SETUP5_4;               
    volatile const  uint32_t SETUP7_6;               
    volatile uint32_t CEPBUFST;               
    volatile uint32_t CEPBUFEND;              
    volatile uint32_t DMACTL;                 
    volatile uint32_t DMACNT;                 

    HSUSBD_EP_T EP[12];

    
    volatile const  uint32_t RESERVE2[301];
    
    volatile uint32_t BCDC;                   
    volatile uint32_t LPMCSR;                 
    volatile uint32_t DMAADDR;                
    volatile uint32_t PHYCTL;                 

} HSUSBD_T;




 
















































































































































































































































































































































































































































































































   
   
   


#pragma no_anon_unions


#line 277 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\usbh_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{

    
























































































































































































































































































































































































































































































































 
    volatile const  uint32_t HcRevision;             
    volatile uint32_t HcControl;              
    volatile uint32_t HcCommandStatus;        
    volatile uint32_t HcInterruptStatus;      
    volatile uint32_t HcInterruptEnable;      
    volatile uint32_t HcInterruptDisable;     
    volatile uint32_t HcHCCA;                 
    volatile uint32_t HcPeriodCurrentED;      
    volatile uint32_t HcControlHeadED;        
    volatile uint32_t HcControlCurrentED;     
    volatile uint32_t HcBulkHeadED;           
    volatile uint32_t HcBulkCurrentED;        
    volatile uint32_t HcDoneHead;             
    volatile uint32_t HcFmInterval;           
    volatile const  uint32_t HcFmRemaining;          
    volatile const  uint32_t HcFmNumber;             
    volatile uint32_t HcPeriodicStart;        
    volatile uint32_t HcLSThreshold;          
    volatile uint32_t HcRhDescriptorA;        
    volatile uint32_t HcRhDescriptorB;        
    volatile uint32_t HcRhStatus;             
    volatile uint32_t HcRhPortStatus[2];      
    
    volatile const  uint32_t RESERVE0[105];
    
    volatile uint32_t HcPhyControl;           
    volatile uint32_t HcMiscControl;          

} USBH_T;




 




























































































































































































































   
   
   


#pragma no_anon_unions


#line 278 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\hsusbh_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{


    






























































































































































































































































































































































































































 
    volatile const  uint32_t EHCVNR;                 
    volatile const  uint32_t EHCSPR;                 
    volatile const  uint32_t EHCCPR;                 
    
    volatile const  uint32_t RESERVE0[5];
    
    volatile uint32_t UCMDR;                  
    volatile uint32_t USTSR;                  
    volatile uint32_t UIENR;                  
    volatile uint32_t UFINDR;                 
    
    volatile const  uint32_t RESERVE1[1];
    
    volatile uint32_t UPFLBAR;                
    volatile uint32_t UCALAR;                 
    volatile uint32_t UASSTR;                 
    
    volatile const  uint32_t RESERVE2[8];
    
    volatile uint32_t UCFGR;                  
    volatile uint32_t UPSCR[2];               
    
    volatile const  uint32_t RESERVE3[22];
    
    volatile uint32_t USBPCR0;                
    volatile uint32_t USBPCR1;                

} HSUSBH_T;




 






































































































































































   
   
   


#pragma no_anon_unions


#line 279 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\otg_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{


    
























































































































































































































 
    volatile uint32_t CTL;                    
    volatile uint32_t PHYCTL;                 
    volatile uint32_t INTEN;                  
    volatile uint32_t INTSTS;                 
    volatile const  uint32_t STATUS;                 

} OTG_T;





 


































































































































   
   
   


#pragma no_anon_unions


#line 280 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\hsotg_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{


    
























































































































































































































 
    volatile uint32_t CTL;                    
    volatile uint32_t PHYCTL;                 
    volatile uint32_t INTEN;                  
    volatile uint32_t INTSTS;                 
    volatile const  uint32_t STATUS;                 

} HSOTG_T;




 





































































































































   
   
   


#pragma no_anon_unions


#line 281 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\crc_reg.h"
 






 




#pragma anon_unions




 

 




 

typedef struct
{


    










































































 
    volatile uint32_t CTL;                    
    volatile uint32_t DAT;                    
    volatile uint32_t SEED;                   
    volatile const  uint32_t CHECKSUM;               
    volatile uint32_t POLYNOMIAL;             

} CRC_T;





 






































   
   
   


#pragma no_anon_unions


#line 282 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\crypto_reg.h"
 






 




#pragma anon_unions





 


 



 

typedef struct
{







































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 
    volatile uint32_t INTEN;                  
    volatile uint32_t INTSTS;                 
    volatile uint32_t PRNG_CTL;               
    volatile  uint32_t PRNG_SEED;              
    volatile const  uint32_t PRNG_KEY[8];            
    volatile const  uint32_t PRNG_STS;               
    volatile const  uint32_t RESERVE0[7];
    volatile const  uint32_t AES_FDBCK[4];           
    volatile const  uint32_t RESERVE1[8];
    volatile uint32_t AES_GCM_IVCNT[2];       
    volatile uint32_t AES_GCM_ACNT[2];          
    volatile uint32_t AES_GCM_PCNT[2];          
    volatile const  uint32_t RESERVE2[2];
    volatile uint32_t AES_FBADDR;             
    volatile const  uint32_t RESERVE3[23];
    volatile uint32_t AES_CTL;                
    volatile const  uint32_t AES_STS;                
    volatile uint32_t AES_DATIN;              
    volatile const  uint32_t AES_DATOUT;             
    volatile uint32_t AES_KEY[8];               
    volatile uint32_t AES_IV[4];                
    volatile uint32_t AES_SADDR;              
    volatile uint32_t AES_DADDR;              
    volatile uint32_t AES_CNT;                
    volatile const  uint32_t RESERVE4[109];
    volatile uint32_t HMAC_CTL;               
    volatile const  uint32_t HMAC_STS;               
    volatile const  uint32_t HMAC_DGST[16];             
    volatile uint32_t HMAC_KEYCNT;            
    volatile uint32_t HMAC_SADDR;             
    volatile uint32_t HMAC_DMACNT;            
    volatile uint32_t HMAC_DATIN;             
    volatile uint32_t HMAC_FDBCK[88];            
    volatile const  uint32_t RESERVE5[16];
    volatile uint32_t HMAC_SHA512T;           
    volatile uint32_t HMAC_FBADDR;            
    volatile const  uint32_t HMAC_SHAKEDGST[42];        
    volatile const  uint32_t RESERVE6[150];
    volatile uint32_t ECC_CTL;                
    volatile const  uint32_t ECC_STS;                
    volatile uint32_t ECC_X1[18];              
    volatile uint32_t ECC_Y1[18];              
    volatile uint32_t ECC_X2[18];              
    volatile uint32_t ECC_Y2[18];              
    volatile uint32_t ECC_A[18];               
    volatile uint32_t ECC_B[18];               
    volatile uint32_t ECC_N[18];               
    volatile  uint32_t ECC_K[18];               
    volatile uint32_t ECC_SADDR;              
    volatile uint32_t ECC_DADDR;              
    volatile uint32_t ECC_STARTREG;           
    volatile uint32_t ECC_WORDCNT;            
    volatile const  uint32_t RESERVE7[42];
    volatile uint32_t RSA_CTL;                
    volatile const  uint32_t RSA_STS;                
    volatile uint32_t RSA_SADDR[5];             
    volatile uint32_t RSA_DADDR;              
    volatile uint32_t RSA_MADDR[7];             
    volatile const  uint32_t RESERVE8[241];
    volatile  uint32_t PRNG_KSCTL;             
    volatile const  uint32_t PRNG_KSSTS;             
    volatile const  uint32_t RESERVE9[2];
    volatile  uint32_t AES_KSCTL;              
    volatile const  uint32_t RESERVE10[7];
    volatile  uint32_t HMAC_KSCTL;             
    volatile const  uint32_t RESERVE11[3];
    volatile  uint32_t ECC_KSCTL;              
    volatile const  uint32_t ECC_KSSTS;              
    volatile  uint32_t ECC_KSXY;               
    volatile const  uint32_t RESERVE12[1];
    volatile  uint32_t RSA_KSCTL;              
    volatile uint32_t RSA_KSSTS[2];             
    volatile const  uint32_t RESERVE13[40];
    volatile const  uint32_t VERSION;                

} CRPT_T;




 









































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































   
   
   


#pragma no_anon_unions


#line 283 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\trng_reg.h"
 






 







 

 



 

typedef struct
{


    






























































 
    volatile uint32_t CTL;                    
    volatile const  uint32_t DATA;                   
    
    volatile const  uint32_t RESERVE0[1];
    
    volatile uint32_t ACT;                    

} TRNG_T;




 




























   
   
   


#line 284 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\eadc_reg.h"
 






 




#pragma anon_unions





 

 



 

typedef struct
{


    


























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 
    volatile const  uint32_t DAT[19];                
    volatile const  uint32_t CURDAT;                 
    volatile uint32_t CTL;                    
    volatile  uint32_t SWTRG;                  
    volatile uint32_t PENDSTS;                
    volatile uint32_t OVSTS;                  
    volatile uint32_t CTL1;                   
    
    volatile const  uint32_t RESERVE0[7];
    
    volatile uint32_t SCTL[19];               
    
    volatile const  uint32_t RESERVE1[1];
    
    volatile uint32_t INTSRC[4];              
    volatile uint32_t CMP[4];                 
    volatile const  uint32_t STATUS0;                
    volatile const  uint32_t STATUS1;                
    volatile uint32_t STATUS2;                
    volatile const  uint32_t STATUS3;                
    volatile const  uint32_t DDAT[4];                
    
    volatile const  uint32_t RESERVE2[1];
    
    volatile uint32_t CALCTL;                 
    volatile uint32_t CALSR;                  
    
    volatile const  uint32_t RESERVE3[5];
    
    volatile uint32_t PDMACTL;                
    
    volatile const  uint32_t RESERVE4[3];
    
    volatile uint32_t MCTL1[15];             
} EADC_T;




 











































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































   
   
   


#pragma no_anon_unions


#line 285 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\dac_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{


    



























































































































 
    volatile uint32_t CTL;                    
    volatile uint32_t SWTRG;                  
    volatile uint32_t DAT;                    
    volatile const  uint32_t DATOUT;                 
    volatile uint32_t STATUS;                 
    volatile uint32_t TCTL;                   
    volatile const  uint32_t RESERVE0[6];
    volatile uint32_t GRPDAT;                 

} DAC_T;




 





























































   
   
   


#pragma no_anon_unions


#line 286 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\acmp_reg.h"
 






 




#pragma anon_unions



 
 
 





 


 



 

typedef struct
{








































































































































































































































































































































































































 
    volatile uint32_t CTL[2];                 
    volatile uint32_t STATUS;                 
    volatile uint32_t VREF;                   
    volatile uint32_t CALCTL;                 
    volatile uint32_t CALSTS;                 
    volatile const  uint32_t RESERVE0[1014];
    volatile uint32_t COFF;                   
    volatile const  uint32_t RESERVE1[1];
    volatile uint32_t TEST;                   
    volatile const  uint32_t VERSION;                

} ACMP_T;




 



































































































































































   
   
   


#pragma no_anon_unions


#line 287 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\ccap_reg.h"
 






 




#pragma anon_unions





 




 


typedef struct {


    























































































































































































































 
    volatile uint32_t CTL;                    
    volatile uint32_t PAR;                    
    volatile uint32_t INT;                    
    volatile const  uint32_t RESERVE0[5];
    volatile uint32_t CWSP;                   
    volatile uint32_t CWS;                    
    volatile uint32_t PKTSL;                  
    volatile uint32_t PLNSL;
    volatile uint32_t FRCTL;                  
    volatile uint32_t STRIDE;                 
    volatile const  uint32_t RESERVE1[1];
    volatile uint32_t FIFOTH;                 
    volatile uint32_t CMPADDR;                
    volatile uint32_t LUMA_Y1_THD;            
    volatile uint32_t PKTSM;                  
    volatile const  uint32_t RESERVE2[1];
    volatile uint32_t CURADDRP;               
    volatile const  uint32_t RESERVE3[3];
    volatile uint32_t PKTBA0;                 
} CCAP_T;




 





































































































































   
   
   


#pragma no_anon_unions


#line 288 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\keystore_reg.h"
 






 








 


 



 

typedef struct
{












































































































































































































































 
    volatile uint32_t CTL;                    
    volatile uint32_t METADATA;               
    volatile uint32_t STS;                    
    volatile const  uint32_t REMAIN;                 
    volatile const  uint32_t RESERVE0[4];
    volatile uint32_t KEY[8];                 
    volatile const  uint32_t OTPSTS;                 
    volatile const  uint32_t REMKCNT;                
    volatile const  uint32_t RESERVE1[1005];
    volatile const  uint32_t VERSION;                

} KS_T;




 
















































































































   
   
   

#line 289 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\kpi_reg.h"
 






 




#pragma anon_unions


 
 
 





 


 



 
 
typedef struct
{



















































































































































































































































 
    volatile uint32_t CTL;                    
    volatile uint32_t Reserved0;              
    volatile uint32_t STATUS;                 
    volatile uint32_t Reserved1;              
    volatile const  uint32_t KST[2];                 
    volatile uint32_t KPF[2];                 
    volatile uint32_t KRF[2];                 
    volatile uint32_t DLYCTL;                 

} KPI_T;




 



































































   
   


   

#pragma no_anon_unions


#line 290 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\psio_reg.h"
 






 





    #pragma anon_unions





 




 

typedef struct
{
    

















































































































 
    volatile uint32_t SCCTL;                  
    volatile uint32_t SCSLOT;                 

} SCCT_T;

typedef struct
{
    

























































































































































































































































































































































 
    volatile uint32_t GENCTL;                 
    volatile uint32_t DATCTL;                 
    volatile const  uint32_t INSTS;                  
    volatile const  uint32_t INDAT;                  
    volatile  uint32_t OUTDAT;                 
    volatile uint32_t CPCTL0;                 
    volatile uint32_t CPCTL1;                 
    volatile const  uint32_t RESERVE0[1];
} GNCT_T;

typedef struct
{
    


































































































































































































































































































































































































































































































 
    volatile uint32_t INTCTL;                 
    volatile uint32_t INTEN;                  
    volatile uint32_t INTSTS;                 
    volatile uint32_t TRANSTS;                
    volatile uint32_t ISSTS;                  
    volatile uint32_t PDMACTL;                
    volatile  uint32_t PODAT;                  
    volatile uint32_t PIDAT;                  
    SCCT_T        SCCT[4];                
    GNCT_T        GNCT[8];                
} PSIO_T;




 





































































































































































































































































































































































































































   
   
   


    #pragma no_anon_unions


#line 291 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\hbi_reg.h"
 






 




#pragma anon_unions





 




 
typedef struct
{


    









































































































































 
    volatile uint32_t CMD ;                
    volatile uint32_t CONFIG;              
    volatile uint32_t ADR;                 
    volatile uint32_t WDATA;               
    volatile uint32_t RDATA;               
    volatile uint32_t INTEN;               
    volatile uint32_t INTSTS;              
} HBI_T;




 












































   
   
   


#pragma no_anon_unions


#line 292 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\bmc_reg.h"
 






 




#pragma anon_unions





 




 

typedef struct
{


















































































































































































































































































































































































 
    volatile uint32_t CTL;                    
    volatile uint32_t DNUM0;                  
    volatile uint32_t DNUM1;                  
    volatile uint32_t INTEN;                  
    volatile uint32_t INTSTS;                 
    volatile uint32_t CHEMPTY;                
    volatile  uint32_t TXDATG0;                
    volatile  uint32_t TXDATG1;                
    volatile  uint32_t TXDATG2;                
    volatile  uint32_t TXDATG3;                
    volatile  uint32_t TXDATG4;                
    volatile  uint32_t TXDATG5;                
    volatile  uint32_t TXDATG6;                
    volatile  uint32_t TXDATG7;                

} BMC_T;




 








































































































































































































































































































   
   
   


#pragma no_anon_unions




#line 293 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"




 
 






 


#line 341 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"




 
#line 373 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"






 
#line 424 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"







   





 

#line 486 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"

#line 557 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"

   




 

typedef volatile unsigned char  vu8;        
typedef volatile unsigned short vu16;       
typedef volatile unsigned int   vu32;       





 







 







 








 







 








 







 







 






 








 







 








 







 







 






 



   

 
 
 



 











 
#line 744 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"

 










   


 
 
 
#line 1 "..\\M463_Library\\StdDriver\\inc\\sys.h"
 






 












 



 



 



 
 
 
#line 54 "..\\M463_Library\\StdDriver\\inc\\sys.h"

#line 83 "..\\M463_Library\\StdDriver\\inc\\sys.h"

#line 108 "..\\M463_Library\\StdDriver\\inc\\sys.h"

#line 120 "..\\M463_Library\\StdDriver\\inc\\sys.h"


 
 
 
#line 135 "..\\M463_Library\\StdDriver\\inc\\sys.h"


 
 
 







 
 
 
#line 158 "..\\M463_Library\\StdDriver\\inc\\sys.h"


 
 
 



 
 
 





 
 
 





 


 
#line 202 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 220 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 237 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 255 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 271 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 287 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 307 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 326 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 345 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 364 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 386 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 406 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 425 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 443 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 461 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 479 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 502 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 525 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 547 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 569 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 589 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 609 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 631 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 653 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 671 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 689 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 705 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 721 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 746 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 771 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 792 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 815 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 836 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 857 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 879 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 901 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 922 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 940 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 960 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 980 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 991 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1004 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1018 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1032 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1046 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1062 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1078 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1091 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1103 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1114 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1126 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1135 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1145 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1158 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1170 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1179 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1188 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1201 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1214 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1230 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1248 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1257 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1269 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1281 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1296 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1311 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1327 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1343 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1359 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1372 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1386 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1400 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1414 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1428 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1440 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1454 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1463 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1471 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1488 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1505 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1518 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1531 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1545 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1560 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1575 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1587 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1599 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1611 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1623 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1634 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1644 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1655 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1665 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1675 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 






 
#line 1691 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1700 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1709 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1718 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1732 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1746 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1761 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1775 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1786 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1796 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1804 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 





 





 
#line 1824 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1833 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 






 






 






 






 
#line 1874 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1887 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1898 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1907 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1916 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1925 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 






 






 
#line 1949 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1959 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1968 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1977 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 1986 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 





 
#line 2001 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 2010 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 2020 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 2030 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 2038 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 2046 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 2055 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 2064 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 2073 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 2082 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 2090 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 2098 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 2107 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 2116 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 2127 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 2138 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 2149 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
#line 2158 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
 
 

#line 3698 "..\\M463_Library\\StdDriver\\inc\\sys.h"

 
 
 

#line 5238 "..\\M463_Library\\StdDriver\\inc\\sys.h"


   

extern int32_t g_SYS_i32ErrCode;



 

 
 
 

#line 6947 "..\\M463_Library\\StdDriver\\inc\\sys.h"








 









 









 









 









 










 









 









 









 

















 









 









 









 









 









 









 









 









 









 









 









 

















 



 
 
 
 
static __inline void SYS_UnlockReg(void);
static __inline void SYS_LockReg(void);







 
static __inline void SYS_UnlockReg(void)
{
    uint32_t u32TimeOutCount = (12000000UL);

    do
    {
        ((SYS_T *) (((uint32_t)0x40000000) + 0x00000UL))->REGLCTL = 0x59UL;
        ((SYS_T *) (((uint32_t)0x40000000) + 0x00000UL))->REGLCTL = 0x16UL;
        ((SYS_T *) (((uint32_t)0x40000000) + 0x00000UL))->REGLCTL = 0x88UL;

        if(--u32TimeOutCount == 0) break;
    }
    while(((SYS_T *) (((uint32_t)0x40000000) + 0x00000UL))->REGLCTL == 0UL);
}







 
static __inline void SYS_LockReg(void)
{
    ((SYS_T *) (((uint32_t)0x40000000) + 0x00000UL))->REGLCTL = 0UL;
}


void SYS_ClearResetSrc(uint32_t u32Src);
uint32_t SYS_GetBODStatus(void);
uint32_t SYS_GetResetSrc(void);
uint32_t SYS_IsRegLocked(void);
uint32_t SYS_ReadPDID(void);
void SYS_ResetChip(void);
void SYS_ResetCPU(void);
void SYS_ResetModule(uint32_t u32ModuleIndex);
void SYS_EnableBOD(int32_t i32Mode, uint32_t u32BODLevel);
void SYS_DisableBOD(void);
int32_t SYS_SetPowerLevel(uint32_t u32PowerLevel);
void SYS_SetVRef(uint32_t u32VRefCTL);

   

   

   






#line 763 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\clk.h"
 






 











 



 



 


#line 45 "..\\M463_Library\\StdDriver\\inc\\clk.h"

 
 
 






#line 61 "..\\M463_Library\\StdDriver\\inc\\clk.h"




















































 
 
 




#line 127 "..\\M463_Library\\StdDriver\\inc\\clk.h"

#line 134 "..\\M463_Library\\StdDriver\\inc\\clk.h"

#line 141 "..\\M463_Library\\StdDriver\\inc\\clk.h"

#line 148 "..\\M463_Library\\StdDriver\\inc\\clk.h"

#line 155 "..\\M463_Library\\StdDriver\\inc\\clk.h"















 
 
 











#line 190 "..\\M463_Library\\StdDriver\\inc\\clk.h"












#line 208 "..\\M463_Library\\StdDriver\\inc\\clk.h"

#line 215 "..\\M463_Library\\StdDriver\\inc\\clk.h"














#line 235 "..\\M463_Library\\StdDriver\\inc\\clk.h"

 
 
 



















#line 264 "..\\M463_Library\\StdDriver\\inc\\clk.h"

#line 271 "..\\M463_Library\\StdDriver\\inc\\clk.h"

#line 278 "..\\M463_Library\\StdDriver\\inc\\clk.h"































 
 
 



































 
 
 



 
 
 
#line 362 "..\\M463_Library\\StdDriver\\inc\\clk.h"

 
 
 





 
 
 





 
 
 



 
 
 
#line 394 "..\\M463_Library\\StdDriver\\inc\\clk.h"

 
 
 
#line 405 "..\\M463_Library\\StdDriver\\inc\\clk.h"

 
 
 
#line 419 "..\\M463_Library\\StdDriver\\inc\\clk.h"

#line 430 "..\\M463_Library\\StdDriver\\inc\\clk.h"

 
 
 










#line 451 "..\\M463_Library\\StdDriver\\inc\\clk.h"

#line 460 "..\\M463_Library\\StdDriver\\inc\\clk.h"

 
 
 



 
 
 
 

#line 482 "..\\M463_Library\\StdDriver\\inc\\clk.h"

#line 491 "..\\M463_Library\\StdDriver\\inc\\clk.h"

 












































































































 




























 
























































































































 




































































































 













































 
 
 






 
 
 
#line 922 "..\\M463_Library\\StdDriver\\inc\\clk.h"

 
 
 
#line 942 "..\\M463_Library\\StdDriver\\inc\\clk.h"

 
 
 

























 
 
 






#line 986 "..\\M463_Library\\StdDriver\\inc\\clk.h"


   



 






 







 







 







 







 







 







 







 







 







 







 
























 




























 


 
 
 
 
static __inline void CLK_SysTickDelay(uint32_t us);
static __inline void CLK_SysTickLongDelay(uint32_t us);









 
static __inline void CLK_SysTickDelay(uint32_t us)
{
    ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD = us * CyclesPerUs;
    ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL  = 0x0UL;
    ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL = (1UL << 2U) | (1UL );

     
    while((((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL & (1UL << 16U)) == 0UL)
    {
    }

     
    ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL = 0UL;
}








 
static __inline void CLK_SysTickLongDelay(uint32_t us)
{
    uint32_t u32Delay;

     
    u32Delay = 65536UL;

    do
    {
        if(us > u32Delay)
        {
            us -= u32Delay;
        }
        else
        {
            u32Delay = us;
            us = 0UL;
        }

        ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD = u32Delay * CyclesPerUs;
        ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL  = (0x0UL);
        ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL = (1UL << 2U) | (1UL );

         
        while((((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL & (1UL << 16U)) == 0UL);

         
        ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL = 0UL;
    }while(us > 0UL);
}


void CLK_DisableCKO(void);
void CLK_EnableCKO(uint32_t u32ClkSrc, uint32_t u32ClkDiv, uint32_t u32ClkDivBy1En);
void CLK_PowerDown(void);
void CLK_Idle(void);
uint32_t CLK_GetHXTFreq(void);
uint32_t CLK_GetLXTFreq(void);
uint32_t CLK_GetHCLKFreq(void);
uint32_t CLK_GetPCLK0Freq(void);
uint32_t CLK_GetPCLK1Freq(void);
uint32_t CLK_GetCPUFreq(void);
uint32_t CLK_SetCoreClock(uint32_t u32Hclk);
void CLK_SetHCLK(uint32_t u32ClkSrc, uint32_t u32ClkDiv);
void CLK_SetModuleClock(uint32_t u32ModuleIdx, uint32_t u32ClkSrc, uint32_t u32ClkDiv);
void CLK_SetSysTickClockSrc(uint32_t u32ClkSrc);
void CLK_EnableXtalRC(uint32_t u32ClkMask);
void CLK_DisableXtalRC(uint32_t u32ClkMask);
void CLK_EnableModuleClock(uint32_t u32ModuleIdx);
void CLK_DisableModuleClock(uint32_t u32ModuleIdx);
uint32_t CLK_EnablePLL(uint32_t u32PllClkSrc, uint32_t u32PllFreq);
void CLK_DisablePLL(void);
uint32_t CLK_WaitClockReady(uint32_t u32ClkMask);
void CLK_EnableSysTick(uint32_t u32ClkSrc, uint32_t u32Count);
void CLK_DisableSysTick(void);
void CLK_SetPowerDownMode(uint32_t u32PDMode);
void CLK_EnableDPDWKPin(uint32_t u32TriggerType);
uint32_t CLK_GetPMUWKSrc(void);
void CLK_EnableSPDWKPin(uint32_t u32Port, uint32_t u32Pin, uint32_t u32TriggerType, uint32_t u32DebounceEn);
uint32_t CLK_GetPLLClockFreq(void);
uint32_t CLK_GetModuleClockSource(uint32_t u32ModuleIdx);
uint32_t CLK_GetModuleClockDivider(uint32_t u32ModuleIdx);
void CLK_DisablePLLFN(void);
uint32_t CLK_EnablePLLFN(uint32_t u32PllClkSrc, uint32_t u32PllFreq);
uint32_t CLK_GetPLLFNClockFreq(void);

   

   

   





#line 764 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"

#line 1 "..\\M463_Library\\StdDriver\\inc\\kpi.h"
 






 












 



 



 








typedef struct {
    uint8_t     x;
    uint8_t     y;
    uint16_t    st;
} KPI_KEY_T;

   




 

int32_t KPI_Open(uint32_t u32Rows, uint32_t u32Columns, KPI_KEY_T *pkeyQueue, uint32_t u32MaxKeyCnt);
void KPI_Close(void);
int32_t KPI_kbhit(void);
KPI_KEY_T KPI_GetKey(void);
void KPI_SetSampleTime(uint32_t ms);
void KPI_EnableSlowScan(void);
   

   

   







#line 766 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\rng.h"
 






 












 



 



 

   




 

int32_t RNG_Open(void);
int32_t RNG_Random(uint32_t *pu32Buf, int32_t nWords);

int32_t RNG_ECDSA_Init(uint32_t u32KeySize, uint32_t au32ECC_N[18]);
int32_t RNG_ECDSA(uint32_t u32KeySize);
int32_t RNG_ECDH_Init(uint32_t u32KeySize, uint32_t au32ECC_N[18]);
int32_t RNG_ECDH(uint32_t u32KeySize);
int32_t RNG_EntropyPoll(uint8_t* pu8Out, int32_t i32Len);

   

   

   







#line 767 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\keystore.h"
 






 











 



 



 




typedef enum KSMEM
{
    KS_SRAM  = 0,      
    KS_FLASH = 1,     
    KS_OTP   = 2      
} KS_MEM_Type;

#line 47 "..\\M463_Library\\StdDriver\\inc\\keystore.h"

#line 54 "..\\M463_Library\\StdDriver\\inc\\keystore.h"

#line 61 "..\\M463_Library\\StdDriver\\inc\\keystore.h"

#line 80 "..\\M463_Library\\StdDriver\\inc\\keystore.h"













#line 99 "..\\M463_Library\\StdDriver\\inc\\keystore.h"




 






   

extern int32_t g_KS_i32ErrCode;



 

int32_t KS_Open(void);
int32_t KS_Read(KS_MEM_Type type, int32_t i32KeyIdx, uint32_t au32Key[], uint32_t u32WordCnt);
int32_t KS_Write(KS_MEM_Type eType, uint32_t u32Meta, uint32_t au32Key[]);
int32_t KS_WriteOTP(int32_t i32KeyIdx, uint32_t u32Meta, uint32_t au32Key[]);
int32_t KS_EraseKey(int32_t i32KeyIdx);
int32_t KS_EraseOTPKey(int32_t i32KeyIdx);
int32_t KS_LockOTPKey(int32_t i32KeyIdx);
int32_t KS_EraseAll(KS_MEM_Type eType);
int32_t KS_RevokeKey(KS_MEM_Type eType, int32_t i32KeyIdx);
uint32_t KS_GetRemainSize(KS_MEM_Type eType);
int32_t KS_ToggleSRAM(void);
uint32_t KS_GetKeyWordCnt(uint32_t u32Meta);
uint32_t KS_GetRemainKeyCount(KS_MEM_Type mem);

   

   

   








#line 768 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\acmp.h"
 






 












 




 




 



 
 
 
#line 61 "..\\M463_Library\\StdDriver\\inc\\acmp.h"

 
 
 
#line 73 "..\\M463_Library\\StdDriver\\inc\\acmp.h"


   




 

 
 
 









 









 














 








 









 













 










 









 









 









 









 









 









 









 









 









 














 









 









 


















 












 











 




  





 


















 

















 












 









 
















 









 





 
void ACMP_Open(ACMP_T *acmp, uint32_t u32ChNum, uint32_t u32NegSrc, uint32_t u32HysSel);
void ACMP_Close(ACMP_T *acmp, uint32_t u32ChNum);



   

   

   








 
#line 769 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\dac.h"
 






 











 



 




 

 
 
 



#line 49 "..\\M463_Library\\StdDriver\\inc\\dac.h"





   




 







 








 








 








 








 









 









 








 








 








 








 











 









 










 










 









 









 








 









 








 


void DAC_Open(DAC_T *dac, uint32_t u32Ch, uint32_t u32TrgSrc);
void DAC_Close(DAC_T *dac, uint32_t u32Ch);
uint32_t DAC_SetDelayTime(DAC_T *dac, uint32_t u32Delay);

   

   

   







#line 770 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\uart.h"
 






 












 



 



 

 
 
 

#line 45 "..\\M463_Library\\StdDriver\\inc\\uart.h"

 
 
 











 
 
 
















 
 
 




 
 
 




 
 
 







 
 
 
#line 112 "..\\M463_Library\\StdDriver\\inc\\uart.h"


 
 
 




   




 












 













 













 












 













 













 














 












 













 













 













 













 













 












 























 
























 











































 












 













 


 
static __inline void UART_CLEAR_RTS(UART_T* uart);
static __inline void UART_SET_RTS(UART_T* uart);











 
static __inline void UART_CLEAR_RTS(UART_T* uart)
{
    uart->MODEM |= (0x1ul << (9));
    uart->MODEM &= ~(0x1ul << (1));
}











 
static __inline void UART_SET_RTS(UART_T* uart)
{
    uart->MODEM |= (0x1ul << (9)) | (0x1ul << (1));
}













 













 



void UART_ClearIntFlag(UART_T* uart, uint32_t u32InterruptFlag);
void UART_Close(UART_T* uart);
void UART_DisableFlowCtrl(UART_T* uart);
void UART_DisableInt(UART_T*  uart, uint32_t u32InterruptFlag);
void UART_EnableFlowCtrl(UART_T* uart);
void UART_EnableInt(UART_T*  uart, uint32_t u32InterruptFlag);
void UART_Open(UART_T* uart, uint32_t u32baudrate);
uint32_t UART_Read(UART_T* uart, uint8_t pu8RxBuf[], uint32_t u32ReadBytes);
void UART_SetLineConfig(UART_T* uart, uint32_t u32baudrate, uint32_t u32data_width, uint32_t u32parity, uint32_t  u32stop_bits);
void UART_SetTimeoutCnt(UART_T* uart, uint32_t u32TOC);
void UART_SelectIrDAMode(UART_T* uart, uint32_t u32Buadrate, uint32_t u32Direction);
void UART_SelectRS485Mode(UART_T* uart, uint32_t u32Mode, uint32_t u32Addr);
void UART_SelectLINMode(UART_T* uart, uint32_t u32Mode, uint32_t u32BreakLength);
uint32_t UART_Write(UART_T* uart, uint8_t pu8TxBuf[], uint32_t u32WriteBytes);
void UART_SelectSingleWireMode(UART_T *uart);



   

   

   





#line 771 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\usci_spi.h"
 






 











 



 



 













 
#line 53 "..\\M463_Library\\StdDriver\\inc\\usci_spi.h"

 
#line 61 "..\\M463_Library\\StdDriver\\inc\\usci_spi.h"

   




 






 







 









 









 









 







 








 








 












 












 







 







 








 
#line 198 "..\\M463_Library\\StdDriver\\inc\\usci_spi.h"








 









 







 







 
















 







 










 












 












 










 










 












 












 








 








 








 








 








 








 


uint32_t USPI_Open(USPI_T *uspi, uint32_t u32MasterSlave, uint32_t u32SPIMode,  uint32_t u32DataWidth, uint32_t u32BusClock);
void USPI_Close(USPI_T *uspi);
void USPI_ClearRxBuf(USPI_T *uspi);
void USPI_ClearTxBuf(USPI_T *uspi);
void USPI_DisableAutoSS(USPI_T *uspi);
void USPI_EnableAutoSS(USPI_T *uspi, uint32_t u32SSPinMask, uint32_t u32ActiveLevel);
uint32_t USPI_SetBusClock(USPI_T *uspi, uint32_t u32BusClock);
uint32_t USPI_GetBusClock(USPI_T *uspi);
void USPI_EnableInt(USPI_T *uspi, uint32_t u32Mask);
void USPI_DisableInt(USPI_T *uspi, uint32_t u32Mask);
uint32_t USPI_GetIntFlag(USPI_T *uspi, uint32_t u32Mask);
void USPI_ClearIntFlag(USPI_T *uspi, uint32_t u32Mask);
uint32_t USPI_GetStatus(USPI_T *uspi, uint32_t u32Mask);
void USPI_EnableWakeup(USPI_T *uspi);
void USPI_DisableWakeup(USPI_T *uspi);


   

   

   





#line 772 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\gpio.h"
 






 











 



 



 





 
 
 






 
 
 







 
 
 



 
 
 




 
 
 





 
 
 






#line 99 "..\\M463_Library\\StdDriver\\inc\\gpio.h"















 
#line 262 "..\\M463_Library\\StdDriver\\inc\\gpio.h"

   




 
















 

















 
















 

















 

















 

















 

















 


















 


































 







 







 











 












 











 
























 

















 



void GPIO_SetMode(GPIO_T *port, uint32_t u32PinMask, uint32_t u32Mode);
void GPIO_EnableInt(GPIO_T *port, uint32_t u32Pin, uint32_t u32IntAttribs);
void GPIO_DisableInt(GPIO_T *port, uint32_t u32Pin);
void GPIO_SetSlewCtl(GPIO_T *port, uint32_t u32PinMask, uint32_t u32Mode);
void GPIO_SetPullCtl(GPIO_T *port, uint32_t u32PinMask, uint32_t u32Mode);


   

   

   






#line 773 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\ccap.h"
 






 










 



 



 

 
 
 
#line 39 "..\\M463_Library\\StdDriver\\inc\\ccap.h"

 
 
 





















#line 70 "..\\M463_Library\\StdDriver\\inc\\ccap.h"

 
 
 




 
 
 





   



 











 















 











 



void CCAP_Open(uint32_t u32InFormat, uint32_t u32OutFormat);
void CCAP_SetCroppingWindow(uint32_t u32VStart, uint32_t u32HStart, uint32_t u32Height, uint32_t u32Width);
void CCAP_SetPacketBuf(uint32_t u32Address);
void CCAP_Close(void);
void CCAP_EnableInt(uint32_t u32IntMask);
void CCAP_DisableInt(uint32_t u32IntMask);
void CCAP_Start(void);
int32_t CCAP_Stop(uint32_t u32FrameComplete);
void CCAP_SetPacketScaling(uint32_t u32VNumerator, uint32_t u32VDenominator, uint32_t u32HNumerator, uint32_t u32HDenominator);
void CCAP_SetPacketStride(uint32_t u32Stride);
void CCAP_EnableMono(uint32_t u32Interface);
void CCAP_DisableMono(void);
void CCAP_EnableLumaYOne(uint32_t u32th);
void CCAP_DisableLumaYOne(void);

   

   

   





#line 774 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\ecap.h"
 






 











 



 



 





 
 
 
#line 43 "..\\M463_Library\\StdDriver\\inc\\ecap.h"







 
 
 




#line 65 "..\\M463_Library\\StdDriver\\inc\\ecap.h"






   



 














 








 















 












 












 















 












 












 








 








 








 








 








 








 















 
#line 261 "..\\M463_Library\\StdDriver\\inc\\ecap.h"







 








 








 








 
















 













 

















 













 








 














 














 









 








 












 









 


void ECAP_Open(ECAP_T* ecap, uint32_t u32FuncMask);
void ECAP_Close(ECAP_T* ecap);
void ECAP_EnableINT(ECAP_T* ecap, uint32_t u32Mask);
void ECAP_DisableINT(ECAP_T* ecap, uint32_t u32Mask);
   

   

   







 
#line 775 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\hbi.h"
 






 



 
 
 









 



 




 

 
 

 






 




 











 
 
#line 75 "..\\M463_Library\\StdDriver\\inc\\hbi.h"
 





 
 




 






 
 





 





 
 




 





 
 




 



 
 


 



 
 


 

 
 
 
extern int32_t g_HBI_i32ErrCode;







 
 
 










 













 












 









 












 










 










 









 








 








 










 


 
 
 
void HBI_ResetHyperRAM(void);
void HBI_ExitHSAndDPD(void);
int32_t HBI_ReadHyperRAMReg(uint32_t u32Addr);
int32_t HBI_WriteHyperRAMReg(uint32_t u32Addr, uint32_t u32Value);
uint32_t HBI_Read2Byte(uint32_t u32Addr);
uint32_t HBI_Read4Byte(uint32_t u32Addr);
void HBI_Write1Byte(uint32_t u32Addr, uint8_t u8Data);
void HBI_Write2Byte(uint32_t u32Addr, uint16_t u16Data);
void HBI_Write3Byte(uint32_t u32Addr, uint32_t u32Data);
void HBI_Write4Byte(uint32_t u32Addr, uint32_t u32Data);

   

   

   





#line 776 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\eqei.h"
 






 











 



 



 

 
 
 
#line 40 "..\\M463_Library\\StdDriver\\inc\\eqei.h"

 
 
 
#line 50 "..\\M463_Library\\StdDriver\\inc\\eqei.h"

 
 
 




 
 
 




   




 







 








 








 








 








 








 












 












 












 












 













 













 








 















 








 









 








 








 









 















 














 









 









 














 














 









 
















 












 












 




void EQEI_Close(EQEI_T* eqei);
void EQEI_DisableInt(EQEI_T* eqei, uint32_t u32IntSel);
void EQEI_EnableInt(EQEI_T* eqei, uint32_t u32IntSel);
void EQEI_Open(EQEI_T* eqei, uint32_t u32Mode, uint32_t u32Value);
void EQEI_Start(EQEI_T* eqei);
void EQEI_Stop(EQEI_T* eqei);


   

   

   







 
#line 777 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\timer.h"
 






 











 



 



 
 
 
 
#line 38 "..\\M463_Library\\StdDriver\\inc\\timer.h"






#line 50 "..\\M463_Library\\StdDriver\\inc\\timer.h"




#line 63 "..\\M463_Library\\StdDriver\\inc\\timer.h"

#line 70 "..\\M463_Library\\StdDriver\\inc\\timer.h"

#line 77 "..\\M463_Library\\StdDriver\\inc\\timer.h"

#line 86 "..\\M463_Library\\StdDriver\\inc\\timer.h"





   




 














 













 












 














 














 


 
static __inline void TIMER_Start(TIMER_T *timer);
static __inline void TIMER_Stop(TIMER_T *timer);
static __inline void TIMER_EnableWakeup(TIMER_T *timer);
static __inline void TIMER_DisableWakeup(TIMER_T *timer);
static __inline void TIMER_StartCapture(TIMER_T *timer);
static __inline void TIMER_StopCapture(TIMER_T *timer);
static __inline void TIMER_EnableCaptureDebounce(TIMER_T *timer);
static __inline void TIMER_DisableCaptureDebounce(TIMER_T *timer);
static __inline void TIMER_EnableEventCounterDebounce(TIMER_T *timer);
static __inline void TIMER_DisableEventCounterDebounce(TIMER_T *timer);
static __inline void TIMER_EnableInt(TIMER_T *timer);
static __inline void TIMER_DisableInt(TIMER_T *timer);
static __inline void TIMER_EnableCaptureInt(TIMER_T *timer);
static __inline void TIMER_DisableCaptureInt(TIMER_T *timer);
static __inline uint32_t TIMER_GetIntFlag(TIMER_T *timer);
static __inline void TIMER_ClearIntFlag(TIMER_T *timer);
static __inline uint32_t TIMER_GetCaptureIntFlag(TIMER_T *timer);
static __inline void TIMER_ClearCaptureIntFlag(TIMER_T *timer);
static __inline uint32_t TIMER_GetWakeupFlag(TIMER_T *timer);
static __inline void TIMER_ClearWakeupFlag(TIMER_T *timer);
static __inline uint32_t TIMER_GetCaptureData(TIMER_T *timer);
static __inline uint32_t TIMER_GetCounter(TIMER_T *timer);









 
static __inline void TIMER_Start(TIMER_T *timer)
{
    timer->CTL |= (0x1ul << (30));
}









 
static __inline void TIMER_Stop(TIMER_T *timer)
{
    timer->CTL &= ~(0x1ul << (30));
}











 
static __inline void TIMER_EnableWakeup(TIMER_T *timer)
{
    timer->CTL |= (0x1ul << (23));
}









 
static __inline void TIMER_DisableWakeup(TIMER_T *timer)
{
    timer->CTL &= ~(0x1ul << (23));
}









 
static __inline void TIMER_StartCapture(TIMER_T *timer)
{
    timer->EXTCTL |= (0x1ul << (3));
}









 
static __inline void TIMER_StopCapture(TIMER_T *timer)
{
    timer->EXTCTL &= ~(0x1ul << (3));
}









 
static __inline void TIMER_EnableCaptureDebounce(TIMER_T *timer)
{
    timer->EXTCTL |= (0x1ul << (6));
}









 
static __inline void TIMER_DisableCaptureDebounce(TIMER_T *timer)
{
    timer->EXTCTL &= ~(0x1ul << (6));
}









 
static __inline void TIMER_EnableEventCounterDebounce(TIMER_T *timer)
{
    timer->EXTCTL |= (0x1ul << (7));
}









 
static __inline void TIMER_DisableEventCounterDebounce(TIMER_T *timer)
{
    timer->EXTCTL &= ~(0x1ul << (7));
}









 
static __inline void TIMER_EnableInt(TIMER_T *timer)
{
    timer->CTL |= (0x1ul << (29));
}









 
static __inline void TIMER_DisableInt(TIMER_T *timer)
{
    timer->CTL &= ~(0x1ul << (29));
}









 
static __inline void TIMER_EnableCaptureInt(TIMER_T *timer)
{
    timer->EXTCTL |= (0x1ul << (5));
}









 
static __inline void TIMER_DisableCaptureInt(TIMER_T *timer)
{
    timer->EXTCTL &= ~(0x1ul << (5));
}










 
static __inline uint32_t TIMER_GetIntFlag(TIMER_T *timer)
{
    return ((timer->INTSTS & (0x1ul << (0))) ? 1UL : 0UL);
}









 
static __inline void TIMER_ClearIntFlag(TIMER_T *timer)
{
    timer->INTSTS = (0x1ul << (0));
}










 
static __inline uint32_t TIMER_GetCaptureIntFlag(TIMER_T *timer)
{
    return timer->EINTSTS;
}









 
static __inline void TIMER_ClearCaptureIntFlag(TIMER_T *timer)
{
    timer->EINTSTS = (0x1ul << (0));
}










 
static __inline uint32_t TIMER_GetWakeupFlag(TIMER_T *timer)
{
    return (timer->INTSTS & (0x1ul << (1)) ? 1UL : 0UL);
}









 
static __inline void TIMER_ClearWakeupFlag(TIMER_T *timer)
{
    timer->INTSTS = (0x1ul << (1));
}









 
static __inline uint32_t TIMER_GetCaptureData(TIMER_T *timer)
{
    return timer->CAP;
}









 
static __inline uint32_t TIMER_GetCounter(TIMER_T *timer)
{
    return timer->CNT;
}



uint32_t TIMER_Open(TIMER_T *timer, uint32_t u32Mode, uint32_t u32Freq);
void TIMER_Close(TIMER_T *timer);
int32_t TIMER_Delay(TIMER_T *timer, uint32_t u32Usec);
void TIMER_EnableCapture(TIMER_T *timer, uint32_t u32CapMode, uint32_t u32Edge);
void TIMER_DisableCapture(TIMER_T *timer);
void TIMER_EnableEventCounter(TIMER_T *timer, uint32_t u32Edge);
void TIMER_DisableEventCounter(TIMER_T *timer);
uint32_t TIMER_GetModuleClock(TIMER_T *timer);
void TIMER_EnableFreqCounter(TIMER_T *timer,
                             uint32_t u32DropCount,
                             uint32_t u32Timeout,
                             uint32_t u32EnableInt);
void TIMER_DisableFreqCounter(TIMER_T *timer);
void TIMER_SetTriggerSource(TIMER_T *timer, uint32_t u32Src);
void TIMER_SetTriggerTarget(TIMER_T *timer, uint32_t u32Mask);
int32_t TIMER_ResetCounter(TIMER_T *timer);
void TIMER_EnableCaptureInputNoiseFilter(TIMER_T *timer, uint32_t u32FilterCount, uint32_t u32ClkSrcSel);
void TIMER_DisableCaptureInputNoiseFilter(TIMER_T *timer);

   

   

   





#line 778 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\timer_pwm.h"
 






 











 


 



 
 
 
 



 
 
 




 
 
 



 
 
 





 
 
 






 
 
 
#line 74 "..\\M463_Library\\StdDriver\\inc\\timer_pwm.h"


#line 83 "..\\M463_Library\\StdDriver\\inc\\timer_pwm.h"




 
 
 




 
 
 
#line 105 "..\\M463_Library\\StdDriver\\inc\\timer_pwm.h"

 
 
 





 
 
 






 
 
 






 
 
 





 
 
 
#line 151 "..\\M463_Library\\StdDriver\\inc\\timer_pwm.h"

 
 
 




   




 











 












 











 











 















 











 











 














 











 













 











 













 











 











 















 
















 
















 


















 




















 













 











 











 












 











 











 











 












 











 











 











 












 











 











 











 












 











 












 











 












 











 












 











 
















 



void TPWM_SetCounterClockSource(TIMER_T *timer, uint32_t u32CntClkSrc);
uint32_t TPWM_ConfigOutputFreqAndDuty(TIMER_T *timer, uint32_t u32Frequency, uint32_t u32DutyCycle);
void TPWM_EnableDeadTime(TIMER_T *timer, uint32_t u32DTCount);
void TPWM_EnableDeadTimeWithPrescale(TIMER_T *timer, uint32_t u32DTCount);
void TPWM_DisableDeadTime(TIMER_T *timer);
void TPWM_EnableCounter(TIMER_T *timer);
void TPWM_DisableCounter(TIMER_T *timer);
void TPWM_EnableTriggerADC(TIMER_T *timer, uint32_t u32Condition);
void TPWM_DisableTriggerADC(TIMER_T *timer);
void TPWM_EnableFaultBrake(TIMER_T *timer, uint32_t u32CH0Level, uint32_t u32CH1Level, uint32_t u32BrakeSource);
void TPWM_EnableFaultBrakeInt(TIMER_T *timer, uint32_t u32IntSource);
void TPWM_DisableFaultBrakeInt(TIMER_T *timer, uint32_t u32IntSource);
uint32_t TPWM_GetFaultBrakeIntFlag(TIMER_T *timer, uint32_t u32IntSource);
void TPWM_ClearFaultBrakeIntFlag(TIMER_T *timer, uint32_t u32IntSource);
void TPWM_SetLoadMode(TIMER_T *timer, uint32_t u32LoadMode);
void TPWM_EnableBrakePinDebounce(TIMER_T *timer, uint32_t u32BrakePinSrc, uint32_t u32DebounceCnt, uint32_t u32ClkSrcSel);
void TPWM_DisableBrakePinDebounce(TIMER_T *timer);
void TPWM_EnableBrakePinInverse(TIMER_T *timer);
void TPWM_DisableBrakePinInverse(TIMER_T *timer);
void TPWM_SetBrakePinSource(TIMER_T *timer, uint32_t u32BrakePinNum);
void TPWM_EnableAcc(TIMER_T *timer, uint32_t u32IntFlagCnt, uint32_t u32IntAccSrc);
void TPWM_DisableAcc(TIMER_T *timer);
void TPWM_EnableAccInt(TIMER_T *timer);
void TPWM_DisableAccInt(TIMER_T *timer);
void TPWM_ClearAccInt(TIMER_T *timer);
uint32_t TPWM_GetAccInt(TIMER_T *timer);
void TPWM_EnableAccPDMA(TIMER_T *timer);
void TPWM_DisableAccPDMA(TIMER_T *timer);
void TPWM_EnableAccStopMode(TIMER_T *timer);
void TPWM_DisableAccStopMode(TIMER_T *timer);
void TPWM_EnableExtEventTrigger(TIMER_T *timer, uint32_t u32ExtEventSrc, uint32_t u32CounterAction);
void TPWM_DisableExtEventTrigger(TIMER_T *timer);

   

   

   





#line 779 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\pdma.h"
 






 











 



 



 


 
 
 




 
 
 




 
 
 





 
 
 



#line 67 "..\\M463_Library\\StdDriver\\inc\\pdma.h"

 
 
 



 
 
 
#line 191 "..\\M463_Library\\StdDriver\\inc\\pdma.h"

 
 
 






   



 










 











 













 











 













 











 












 












 













 













 













 













 













 












 











 











 


 
 
 
void PDMA_Open(PDMA_T * pdma,uint32_t u32Mask);
void PDMA_Close(PDMA_T * pdma);
void PDMA_SetTransferCnt(PDMA_T * pdma,uint32_t u32Ch, uint32_t u32Width, uint32_t u32TransCount);
void PDMA_SetTransferAddr(PDMA_T * pdma,uint32_t u32Ch, uint32_t u32SrcAddr, uint32_t u32SrcCtrl, uint32_t u32DstAddr, uint32_t u32DstCtrl);
void PDMA_SetTransferMode(PDMA_T * pdma,uint32_t u32Ch, uint32_t u32Peripheral, uint32_t u32ScatterEn, uint32_t u32DescAddr);
void PDMA_SetBurstType(PDMA_T * pdma,uint32_t u32Ch, uint32_t u32BurstType, uint32_t u32BurstSize);
void PDMA_EnableTimeout(PDMA_T * pdma,uint32_t u32Mask);
void PDMA_DisableTimeout(PDMA_T * pdma,uint32_t u32Mask);
void PDMA_SetTimeOut(PDMA_T * pdma, uint32_t u32Ch, uint32_t u32OnOff, uint32_t u32TimeOutCnt);
void PDMA_Trigger(PDMA_T * pdma,uint32_t u32Ch);
void PDMA_EnableInt(PDMA_T * pdma,uint32_t u32Ch, uint32_t u32Mask);
void PDMA_DisableInt(PDMA_T * pdma,uint32_t u32Ch, uint32_t u32Mask);
void PDMA_SetStride(PDMA_T * pdma,uint32_t u32Ch, uint32_t u32DestLen, uint32_t u32SrcLen, uint32_t u32TransCount);
void PDMA_SetRepeat(PDMA_T * pdma,uint32_t u32Ch, uint32_t u32DestInterval, uint32_t u32SrcInterval, uint32_t u32RepeatCount);


   

   

   







#line 780 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\crypto.h"
 






 










 



 




 


#line 43 "..\\M463_Library\\StdDriver\\inc\\crypto.h"












#line 66 "..\\M463_Library\\StdDriver\\inc\\crypto.h"

#line 78 "..\\M463_Library\\StdDriver\\inc\\crypto.h"













































typedef enum
{
     
    CURVE_P_192,                         
    CURVE_P_224,                         
    CURVE_P_256,                         
    CURVE_P_384,                         
    CURVE_P_521,                         
    CURVE_K_163,                         
    CURVE_K_233,                         
    CURVE_K_283,                         
    CURVE_K_409,                         
    CURVE_K_571,                         
    CURVE_B_163,                         
    CURVE_B_233,                         
    CURVE_B_283,                         
    CURVE_B_409,                         
    CURVE_B_571,                         
    CURVE_KO_192,                        
    CURVE_KO_224,                        
    CURVE_KO_256,                        
    CURVE_BP_256,                        
    CURVE_BP_384,                        
    CURVE_BP_512,                        
    CURVE_25519,                         
    CURVE_SM2_256,                       
    CURVE_UNDEF = -0x7fffffff,                         
}
E_ECC_CURVE;



typedef struct e_curve_t
{
    E_ECC_CURVE curve_id;
    int32_t     Echar;
    char        Ea[144];
    char        Eb[144];
    char        Px[144];
    char        Py[144];
    int32_t     Epl;
    char        Pp[176];
    int32_t     Eol;
    char        Eorder[176];
    int32_t     key_len;
    int32_t     irreducible_k1;
    int32_t     irreducible_k2;
    int32_t     irreducible_k3;
    int32_t     GF;
}  ECC_CURVE;


 
typedef struct
{
    uint32_t au32RsaOutput[128];  
    uint32_t au32RsaN[128];  
    uint32_t au32RsaM[128];  
    uint32_t au32RsaE[128];  
} RSA_BUF_NORMAL_T;

 
typedef struct
{
    uint32_t au32RsaOutput[128];  
    uint32_t au32RsaN[128];  
    uint32_t au32RsaM[128];  
    uint32_t au32RsaE[128];  
    uint32_t au32RsaP[128];  
    uint32_t au32RsaQ[128];  
    uint32_t au32RsaTmpCp[128];  
    uint32_t au32RsaTmpCq[128];  
    uint32_t au32RsaTmpDp[128];  
    uint32_t au32RsaTmpDq[128];  
    uint32_t au32RsaTmpRp[128];  
    uint32_t au32RsaTmpRq[128];  
} RSA_BUF_CRT_T;

 
typedef struct
{
    uint32_t au32RsaOutput[128];  
    uint32_t au32RsaN[128];  
    uint32_t au32RsaM[128];  
} RSA_BUF_KS_T;

   




 

 
 
 






 







 







 







 







 







 







 







 







 







 







 







 







 







 







 







 







 







 







 







 







 







 



   





 

 
 
 

void PRNG_Open(CRPT_T *crpt, uint32_t u32KeySize, uint32_t u32SeedReload, uint32_t u32Seed);
int32_t PRNG_Start(CRPT_T *crpt);
void PRNG_Read(CRPT_T *crpt, uint32_t u32RandKey[]);
void AES_Open(CRPT_T *crpt, uint32_t u32Channel, uint32_t u32EncDec, uint32_t u32OpMode, uint32_t u32KeySize, uint32_t u32SwapType);
void AES_Start(CRPT_T *crpt, int32_t u32Channel, uint32_t u32DMAMode);
void AES_SetKey(CRPT_T *crpt, uint32_t u32Channel, uint32_t au32Keys[], uint32_t u32KeySize);
void AES_SetKey_KS(CRPT_T *crpt, KS_MEM_Type mem, int32_t i32KeyIdx);
void AES_SetInitVect(CRPT_T *crpt, uint32_t u32Channel, uint32_t au32IV[]);
void AES_SetDMATransfer(CRPT_T *crpt, uint32_t u32Channel, uint32_t u32SrcAddr, uint32_t u32DstAddr, uint32_t u32TransCnt);
void SHA_Open(CRPT_T *crpt, uint32_t u32OpMode, uint32_t u32SwapType, uint32_t hmac_key_len);
void SHA_Start(CRPT_T *crpt, uint32_t u32DMAMode);
void SHA_SetDMATransfer(CRPT_T *crpt, uint32_t u32SrcAddr, uint32_t u32TransCnt);
void SHA_Read(CRPT_T *crpt, uint32_t u32Digest[]);
void ECC_DriverISR(CRPT_T *crpt);
int  ECC_IsPrivateKeyValid(CRPT_T *crpt, E_ECC_CURVE ecc_curve,  char private_k[]);
int32_t  ECC_GenerateSecretZ(CRPT_T *crpt, E_ECC_CURVE ecc_curve, char *private_k, char public_k1[], char public_k2[], char secret_z[]);
int32_t  ECC_GeneratePublicKey(CRPT_T *crpt, E_ECC_CURVE ecc_curve, char *private_k, char public_k1[], char public_k2[]);
int32_t  ECC_GenerateSignature(CRPT_T *crpt, E_ECC_CURVE ecc_curve, char *message, char *d, char *k, char *R, char *S);
int32_t  ECC_VerifySignature(CRPT_T *crpt, E_ECC_CURVE ecc_curve, char *message, char *public_k1, char *public_k2, char *R, char *S);


int32_t RSA_Open(CRPT_T *crpt, uint32_t u32OpMode, uint32_t u32KeySize, void *psRSA_Buf, uint32_t u32BufSize, uint32_t u32UseKS);
int32_t RSA_SetKey(CRPT_T *crpt, char *Key);
int32_t RSA_SetDMATransfer(CRPT_T *crpt, char *Src, char *n, char *P, char *Q);
void RSA_Start(CRPT_T *crpt);
int32_t RSA_Read(CRPT_T *crpt, char * Output);
int32_t RSA_SetKey_KS(CRPT_T *crpt, uint32_t u32KeyNum, uint32_t u32KSMemType, uint32_t u32BlindKeyNum);
int32_t RSA_SetDMATransfer_KS(CRPT_T *crpt, char *Src, char *n, uint32_t u32PNum,
                              uint32_t u32QNum, uint32_t u32CpNum, uint32_t u32CqNum, uint32_t u32DpNum,
                              uint32_t u32DqNum, uint32_t u32RpNum, uint32_t u32RqNum);
int32_t  ECC_GeneratePublicKey_KS(CRPT_T *crpt, E_ECC_CURVE ecc_curve, KS_MEM_Type mem, int32_t i32KeyIdx, char public_k1[], char public_k2[], uint32_t u32ExtraOp);
int32_t  ECC_GenerateSignature_KS(CRPT_T *crpt, E_ECC_CURVE ecc_curve, char *message, KS_MEM_Type mem_d, int32_t i32KeyIdx_d, KS_MEM_Type mem_k, int32_t i32KeyIdx_k, char *R, char *S);
int32_t  ECC_VerifySignature_KS(CRPT_T *crpt, E_ECC_CURVE ecc_curve, char *message, KS_MEM_Type mem_pk1, int32_t i32KeyIdx_pk1, KS_MEM_Type mem_pk2, int32_t i32KeyIdx_pk2, char *R, char *S);
int32_t  ECC_GenerateSecretZ_KS(CRPT_T *crpt, E_ECC_CURVE ecc_curve, KS_MEM_Type mem, int32_t i32KeyIdx, char public_k1[], char public_k2[]);

void CRPT_Reg2Hex(int32_t count, uint32_t volatile reg[], char output[]);
void CRPT_Hex2Reg(char input[], uint32_t volatile reg[]);
int32_t ECC_GetCurve(CRPT_T *crpt, E_ECC_CURVE ecc_curve, ECC_CURVE *curve);

   

   

   







#line 781 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\trng.h"
 






 










 



 




 

 
 
 


















 



   




 


 
 
 

int32_t TRNG_Open(void);
int32_t TRNG_GenWord(uint32_t *u32RndNum);
int32_t TRNG_GenBignum(uint8_t u8BigNum[], int32_t i32Len);
int32_t TRNG_GenBignumHex(char cBigNumHex[], int32_t i32Len);


   

   

   





#line 782 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\fmc.h"
 






 










 



 




 


 
 
 
#line 51 "..\\M463_Library\\StdDriver\\inc\\fmc.h"












 
 
 





 
 
 



 
 
 
#line 97 "..\\M463_Library\\StdDriver\\inc\\fmc.h"






 
 
 






   




 


 
 
 

#line 138 "..\\M463_Library\\StdDriver\\inc\\fmc.h"
   

 
 
 
extern int32_t  g_FMC_i32ErrCode;



 

 
 
 

static __inline uint32_t FMC_ReadCID(void);
static __inline uint32_t FMC_ReadPID(void);
static __inline uint32_t FMC_ReadUID(uint8_t u8Index);
static __inline uint32_t FMC_ReadUCID(uint32_t u32Index);
static __inline int32_t FMC_SetVectorPageAddr(uint32_t u32PageAddr);
static __inline uint32_t FMC_GetVECMAP(void);








 
static __inline uint32_t FMC_GetVECMAP(void)
{
    return (((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPSTS & (0x7ffful << (9)));
}









 
static __inline uint32_t FMC_ReadCID(void)
{
    int32_t i32TimeOutCnt = (SystemCoreClock>>3);

    g_FMC_i32ErrCode = 0;

    ((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPCMD = 0x0BUL;            
    ((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPADDR = 0x0u;                          
    ((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPTRG = (0x1ul << (0));           
    while(((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPTRG & (0x1ul << (0)))     
    {
        if( i32TimeOutCnt-- <= 0)
        {
            g_FMC_i32ErrCode = -1;
            return 0xFFFFFFFF;
        }
    }

    return ((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPDAT;
}









 
static __inline uint32_t FMC_ReadPID(void)
{
    int32_t i32TimeOutCnt = (SystemCoreClock>>3);

    g_FMC_i32ErrCode = 0;

    ((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPCMD = 0x0CUL;           
    ((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPADDR = 0x04u;                        
    ((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPTRG = (0x1ul << (0));          
    while(((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPTRG & (0x1ul << (0)))    
    {
        if( i32TimeOutCnt-- <= 0)
        {
            g_FMC_i32ErrCode = -1;
            return 0xFFFFFFFF;
        }
    }

    return ((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPDAT;
}









 
static __inline uint32_t FMC_ReadUID(uint8_t u8Index)
{
    int32_t i32TimeOutCnt = (SystemCoreClock>>3);

    g_FMC_i32ErrCode = 0;

    ((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPCMD = 0x04UL;
    ((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPADDR = ((uint32_t)u8Index << 2u);
    ((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPDAT = 0u;
    ((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPTRG = 0x1u;
    while(((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPTRG & (0x1ul << (0)))    
    {
        if( i32TimeOutCnt-- <= 0)
        {
            g_FMC_i32ErrCode = -1;
            return 0xFFFFFFFF;
        }
    }

    return ((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPDAT;
}









 
static __inline uint32_t FMC_ReadUCID(uint32_t u32Index)
{
    int32_t i32TimeOutCnt = (SystemCoreClock>>3);

    g_FMC_i32ErrCode = 0;

    ((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPCMD = 0x04UL;             
    ((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPADDR = (0x04u * u32Index) + 0x10u;     
    ((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPTRG = (0x1ul << (0));            
    while(((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPTRG & (0x1ul << (0)))      
    {
        if( i32TimeOutCnt-- <= 0)
        {
            g_FMC_i32ErrCode = -1;
            return 0xFFFFFFFF;
        }
    }

    return ((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPDAT;
}













 
static __inline int32_t FMC_SetVectorPageAddr(uint32_t u32PageAddr)
{
    int32_t i32TimeOutCnt = (SystemCoreClock>>3);

    g_FMC_i32ErrCode = 0;

    ((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPCMD = 0x2EUL;   
    ((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPADDR = u32PageAddr;        
    ((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPTRG = 0x1u;                
    while(((FMC_T *) (((uint32_t)0x40000000) + 0x0C000UL))->ISPTRG)                 
    {
        if( i32TimeOutCnt-- <= 0)
        {
            g_FMC_i32ErrCode = -1;
            return -1;
        }
    }

    return 0;
}


 
 
 

extern void     FMC_Close(void);
extern int32_t  FMC_ConfigXOM(uint32_t xom_num, uint32_t xom_base, uint8_t xom_page);
extern int32_t  FMC_Erase(uint32_t u32PageAddr);
extern int32_t  FMC_Erase_Bank(uint32_t u32BankAddr);
extern int32_t  FMC_EraseXOM(uint32_t xom_num);
extern int32_t  FMC_GetXOMState(uint32_t xom_num);
extern int32_t  FMC_GetBootSource(void);
extern void     FMC_Open(void);
extern uint32_t FMC_Read(uint32_t u32Addr);
extern int32_t  FMC_Read_64(uint32_t u32addr, uint32_t * u32data0, uint32_t * u32data1);
extern uint32_t FMC_ReadDataFlashBaseAddr(void);
extern void     FMC_SetBootSource(int32_t i32BootSrc);
extern int32_t  FMC_Write(uint32_t u32Addr, uint32_t u32Data);
extern int32_t  FMC_Write8Bytes(uint32_t u32addr, uint32_t u32data0, uint32_t u32data1);
extern int32_t  FMC_WriteMultiple(uint32_t u32Addr, uint32_t pu32Buf[], uint32_t u32Len);
extern int32_t  FMC_WriteOTP(uint32_t otp_num, uint32_t low_word, uint32_t high_word);
extern int32_t  FMC_ReadOTP(uint32_t otp_num, uint32_t *low_word, uint32_t *high_word);
extern int32_t  FMC_LockOTP(uint32_t otp_num);
extern int32_t  FMC_IsOTPLocked(uint32_t otp_num);
extern int32_t  FMC_ReadConfig(uint32_t u32Config[], uint32_t u32Count);
extern int32_t  FMC_WriteConfig(uint32_t u32Config[], uint32_t u32Count);
extern uint32_t FMC_GetChkSum(uint32_t u32addr, uint32_t u32count);
extern uint32_t FMC_CheckAllOne(uint32_t u32addr, uint32_t u32count);
extern int32_t  FMC_RemapBank(uint32_t u32Bank);


   

   

   





#line 783 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\spim.h"
 






 



 
 
 









 



 




 






 
 
 
#line 51 "..\\M463_Library\\StdDriver\\inc\\spim.h"







#line 66 "..\\M463_Library\\StdDriver\\inc\\spim.h"

 

typedef enum
{
    MFGID_UNKNOW    = 0x00U,
    MFGID_SPANSION  = 0x01U,
    MFGID_EON       = 0x1CU,
    MFGID_ISSI      = 0x7FU,
    MFGID_MXIC      = 0xC2U,
    MFGID_WINBOND   = 0xEFU
}
E_MFGID;

 
#line 101 "..\\M463_Library\\StdDriver\\inc\\spim.h"

 




 












 



 

 








 

 






   



 


 
 
 




 





 





 





 





 








 





 





 





 








 








 






 








 






 








 








 








 








 








 








 








 






 








 





 








 





 





 





 





 





 





 





 





 





 





 





 








 






 








 








 






 








 






 








 






 








 






 






 






 








 






 








 






 





 





 





 





 








 





 








 




 
 
 


int  SPIM_InitFlash(int clrWP);
uint32_t SPIM_GetSClkFreq(void);
void SPIM_ReadJedecId(uint8_t idBuf[], uint32_t u32NRx, uint32_t u32NBit);
int  SPIM_Enable_4Bytes_Mode(int isEn, uint32_t u32NBit);
int  SPIM_Is4ByteModeEnable(uint32_t u32NBit);

void SPIM_ChipErase(uint32_t u32NBit, int isSync);
void SPIM_EraseBlock(uint32_t u32Addr, int is4ByteAddr, uint8_t u8ErsCmd, uint32_t u32NBit, int isSync);

void SPIM_IO_Write(uint32_t u32Addr, int is4ByteAddr, uint32_t u32NTx, uint8_t pu8TxBuf[], uint8_t wrCmd, uint32_t u32NBitCmd, uint32_t u32NBitAddr, uint32_t u32NBitDat);
void SPIM_IO_Read(uint32_t u32Addr, int is4ByteAddr, uint32_t u32NRx, uint8_t pu8RxBuf[], uint8_t rdCmd, uint32_t u32NBitCmd, uint32_t u32NBitAddr, uint32_t u32NBitDat, int u32NDummy);

void SPIM_DMA_Write(uint32_t u32Addr, int is4ByteAddr, uint32_t u32NTx, uint8_t pu8TxBuf[], uint32_t wrCmd);
int32_t SPIM_DMA_Read(uint32_t u32Addr, int is4ByteAddr, uint32_t u32NRx, uint8_t pu8RxBuf[], uint32_t u32RdCmd, int isSync);

void SPIM_EnterDirectMapMode(int is4ByteAddr, uint32_t u32RdCmd, uint32_t u32IdleIntvl);
void SPIM_ExitDirectMapMode(void);

void SPIM_SetQuadEnable(int isEn, uint32_t u32NBit);

void SPIM_WinbondUnlock(uint32_t u32NBit);

   

   

   







 
#line 784 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\i2c.h"
 






 











 



 



 

 
 
 
#line 42 "..\\M463_Library\\StdDriver\\inc\\i2c.h"

 
 
 



 
 
 





 
 
 





   

extern int32_t g_I2C_i32ErrCode;



 










 











 











 











 












 











 












 












 











 












 











 












 












 












 












 












 











 












 











 











 











 











 











 











 








 








 








 








 








 








 








 


 
 
 

 
static __inline void I2C_STOP(I2C_T *i2c);









 
static __inline void I2C_STOP(I2C_T *i2c)
{
    uint32_t u32TimeOutCount = SystemCoreClock;

    (i2c)->CTL0 |= ((0x1ul << (3)) | (0x1ul << (4)));
    while(i2c->CTL0 & (0x1ul << (4)))
    {
        if(--u32TimeOutCount == 0) break;
    }
}

void I2C_ClearTimeoutFlag(I2C_T *i2c);
void I2C_Close(I2C_T *i2c);
void I2C_Trigger(I2C_T *i2c, uint8_t u8Start, uint8_t u8Stop, uint8_t u8Si, uint8_t u8Ack);
void I2C_DisableInt(I2C_T *i2c);
void I2C_EnableInt(I2C_T *i2c);
uint32_t I2C_GetBusClockFreq(I2C_T *i2c);
uint32_t I2C_GetIntFlag(I2C_T *i2c);
uint32_t I2C_GetStatus(I2C_T *i2c);
uint32_t I2C_Open(I2C_T *i2c, uint32_t u32BusClock);
uint8_t I2C_GetData(I2C_T *i2c);
void I2C_SetSlaveAddr(I2C_T *i2c, uint8_t u8SlaveNo, uint16_t u16SlaveAddr, uint8_t u8GCMode);
void I2C_SetSlaveAddrMask(I2C_T *i2c, uint8_t u8SlaveNo, uint16_t u16SlaveAddrMask);
uint32_t I2C_SetBusClockFreq(I2C_T *i2c, uint32_t u32BusClock);
void I2C_EnableTimeout(I2C_T *i2c, uint8_t u8LongTimeout);
void I2C_DisableTimeout(I2C_T *i2c);
void I2C_EnableWakeup(I2C_T *i2c);
void I2C_DisableWakeup(I2C_T *i2c);
void I2C_SetData(I2C_T *i2c, uint8_t u8Data);
void I2C_SMBusClearInterruptFlag(I2C_T *i2c, uint8_t u8SMBusIntFlag);
uint8_t I2C_WriteByte(I2C_T *i2c, uint8_t u8SlaveAddr, uint8_t data);
uint32_t I2C_WriteMultiBytes(I2C_T *i2c, uint8_t u8SlaveAddr, uint8_t data[], uint32_t u32wLen);
uint8_t I2C_WriteByteOneReg(I2C_T *i2c, uint8_t u8SlaveAddr, uint8_t u8DataAddr, uint8_t data);
uint32_t I2C_WriteMultiBytesOneReg(I2C_T *i2c, uint8_t u8SlaveAddr, uint8_t u8DataAddr, uint8_t data[], uint32_t u32wLen);
uint8_t I2C_WriteByteTwoRegs(I2C_T *i2c, uint8_t u8SlaveAddr, uint16_t u16DataAddr, uint8_t data);
uint32_t I2C_WriteMultiBytesTwoRegs(I2C_T *i2c, uint8_t u8SlaveAddr, uint16_t u16DataAddr, uint8_t data[], uint32_t u32wLen);
uint8_t I2C_ReadByte(I2C_T *i2c, uint8_t u8SlaveAddr);
uint32_t I2C_ReadMultiBytes(I2C_T *i2c, uint8_t u8SlaveAddr, uint8_t rdata[], uint32_t u32rLen);
uint8_t I2C_ReadByteOneReg(I2C_T *i2c, uint8_t u8SlaveAddr, uint8_t u8DataAddr);
uint32_t I2C_ReadMultiBytesOneReg(I2C_T *i2c, uint8_t u8SlaveAddr, uint8_t u8DataAddr, uint8_t rdata[], uint32_t u32rLen);
uint8_t I2C_ReadByteTwoRegs(I2C_T *i2c, uint8_t u8SlaveAddr, uint16_t u16DataAddr);
uint32_t I2C_ReadMultiBytesTwoRegs(I2C_T *i2c, uint8_t u8SlaveAddr, uint16_t u16DataAddr, uint8_t rdata[], uint32_t u32rLen);
uint32_t I2C_SMBusGetStatus(I2C_T *i2c);
void I2C_SMBusSetPacketByteCount(I2C_T *i2c, uint32_t u32PktSize);
void I2C_SMBusOpen(I2C_T *i2c, uint8_t u8HostDevice);
void I2C_SMBusClose(I2C_T *i2c);
void I2C_SMBusPECTxEnable(I2C_T *i2c, uint8_t u8PECTxEn);
uint8_t I2C_SMBusGetPECValue(I2C_T *i2c);
void I2C_SMBusIdleTimeout(I2C_T *i2c, uint32_t us, uint32_t u32Hclk);
void I2C_SMBusTimeout(I2C_T *i2c, uint32_t ms, uint32_t u32Pclk);
void I2C_SMBusClockLoTimeout(I2C_T *i2c, uint32_t ms, uint32_t u32Pclk);

   

   

   







 
#line 785 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\i2s.h"
 






 











 



 



 






 





 
#line 48 "..\\M463_Library\\StdDriver\\inc\\i2s.h"

 



 





 





 



 



 
#line 90 "..\\M463_Library\\StdDriver\\inc\\i2s.h"

#line 107 "..\\M463_Library\\StdDriver\\inc\\i2s.h"

 



 



   




 







 
static __inline void I2S_ENABLE_TX_ZCD(I2S_T *i2s, uint32_t u32ChMask)
{
    if((u32ChMask > 0U) && (u32ChMask < 9U))
    {
        i2s->CTL1 |= ((uint32_t)1U << (u32ChMask-1U));
    }
}







 
static __inline void I2S_DISABLE_TX_ZCD(I2S_T *i2s, uint32_t u32ChMask)
{
    if((u32ChMask > 0U) && (u32ChMask < 9U))
    {
        i2s->CTL1 &= ~((uint32_t)1U << (u32ChMask-1U));
    }
}






 







 







 







 







 







 







 







 







 







 







 







 










 
static __inline void I2S_SET_MONO_RX_CHANNEL(I2S_T *i2s, uint32_t u32Ch)
{
    u32Ch == (0x1ul << (23)) ?
    (i2s->CTL0 |= (0x1ul << (23))) :
    (i2s->CTL0 &= ~(0x1ul << (23)));
}







 







 








 








 








 








 







 







 


uint32_t I2S_Open(I2S_T *i2s, uint32_t u32MasterSlave, uint32_t u32SampleRate, uint32_t u32WordWidth, uint32_t u32MonoData, uint32_t u32DataFormat);
void I2S_Close(I2S_T *i2s);
void I2S_EnableInt(I2S_T *i2s, uint32_t u32Mask);
void I2S_DisableInt(I2S_T *i2s, uint32_t u32Mask);
uint32_t I2S_EnableMCLK(I2S_T *i2s, uint32_t u32BusClock);
void I2S_DisableMCLK(I2S_T *i2s);
void I2S_SetFIFO(I2S_T *i2s, uint32_t u32TxThreshold, uint32_t u32RxThreshold);
void I2S_ConfigureTDM(I2S_T *i2s, uint32_t u32ChannelWidth, uint32_t u32ChannelNum, uint32_t u32SyncWidth);


   

   

   





#line 786 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\epwm.h"
 






 











 



 



 
#line 36 "..\\M463_Library\\StdDriver\\inc\\epwm.h"

 
 
 




 
 
 



 
 
 





 
 
 





 
 
 
#line 87 "..\\M463_Library\\StdDriver\\inc\\epwm.h"






 
 
 
#line 109 "..\\M463_Library\\StdDriver\\inc\\epwm.h"

#line 123 "..\\M463_Library\\StdDriver\\inc\\epwm.h"




 
 
 
#line 140 "..\\M463_Library\\StdDriver\\inc\\epwm.h"

 
 
 







 
 
 



 
 
 





 
 
 




 
 
 
#line 181 "..\\M463_Library\\StdDriver\\inc\\epwm.h"

 
 
 
#line 193 "..\\M463_Library\\StdDriver\\inc\\epwm.h"

 
 
 






 
 
 






   




 







 








 








 








 















 










 
#line 288 "..\\M463_Library\\StdDriver\\inc\\epwm.h"








 










 









 









 












 















 










 











 









 











 












 









 













 
#line 447 "..\\M463_Library\\StdDriver\\inc\\epwm.h"









 










 










 






























 
#line 522 "..\\M463_Library\\StdDriver\\inc\\epwm.h"












 











 




 
 
 
uint32_t EPWM_ConfigCaptureChannel(EPWM_T *epwm, uint32_t u32ChannelNum, uint32_t u32UnitTimeNsec, uint32_t u32CaptureEdge);
uint32_t EPWM_ConfigOutputChannel(EPWM_T *epwm, uint32_t u32ChannelNum, uint32_t u32Frequency, uint32_t u32DutyCycle);
void EPWM_Start(EPWM_T *epwm, uint32_t u32ChannelMask);
void EPWM_Stop(EPWM_T *epwm, uint32_t u32ChannelMask);
void EPWM_ForceStop(EPWM_T *epwm, uint32_t u32ChannelMask);
void EPWM_EnableADCTrigger(EPWM_T *epwm, uint32_t u32ChannelNum, uint32_t u32Condition);
void EPWM_DisableADCTrigger(EPWM_T *epwm, uint32_t u32ChannelNum);
int32_t EPWM_EnableADCTriggerPrescale(EPWM_T *epwm, uint32_t u32ChannelNum, uint32_t u32Prescale, uint32_t u32PrescaleCnt);
void EPWM_DisableADCTriggerPrescale(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_ClearADCTriggerFlag(EPWM_T *epwm, uint32_t u32ChannelNum, uint32_t u32Condition);
uint32_t EPWM_GetADCTriggerFlag(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_EnableDACTrigger(EPWM_T *epwm, uint32_t u32ChannelNum, uint32_t u32Condition);
void EPWM_DisableDACTrigger(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_ClearDACTriggerFlag(EPWM_T *epwm, uint32_t u32ChannelNum, uint32_t u32Condition);
uint32_t EPWM_GetDACTriggerFlag(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_EnableFaultBrake(EPWM_T *epwm, uint32_t u32ChannelMask, uint32_t u32LevelMask, uint32_t u32BrakeSource);
void EPWM_EnableCapture(EPWM_T *epwm, uint32_t u32ChannelMask);
void EPWM_DisableCapture(EPWM_T *epwm, uint32_t u32ChannelMask);
void EPWM_EnableOutput(EPWM_T *epwm, uint32_t u32ChannelMask);
void EPWM_DisableOutput(EPWM_T *epwm, uint32_t u32ChannelMask);
void EPWM_EnablePDMA(EPWM_T *epwm, uint32_t u32ChannelNum, uint32_t u32RisingFirst, uint32_t u32Mode);
void EPWM_DisablePDMA(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_EnableDeadZone(EPWM_T *epwm, uint32_t u32ChannelNum, uint32_t u32Duration);
void EPWM_DisableDeadZone(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_EnableCaptureInt(EPWM_T *epwm, uint32_t u32ChannelNum, uint32_t u32Edge);
void EPWM_DisableCaptureInt(EPWM_T *epwm, uint32_t u32ChannelNum, uint32_t u32Edge);
void EPWM_ClearCaptureIntFlag(EPWM_T *epwm, uint32_t u32ChannelNum, uint32_t u32Edge);
uint32_t EPWM_GetCaptureIntFlag(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_EnableDutyInt(EPWM_T *epwm, uint32_t u32ChannelNum, uint32_t u32IntDutyType);
void EPWM_DisableDutyInt(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_ClearDutyIntFlag(EPWM_T *epwm, uint32_t u32ChannelNum);
uint32_t EPWM_GetDutyIntFlag(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_EnableFaultBrakeInt(EPWM_T *epwm, uint32_t u32BrakeSource);
void EPWM_DisableFaultBrakeInt(EPWM_T *epwm, uint32_t u32BrakeSource);
void EPWM_ClearFaultBrakeIntFlag(EPWM_T *epwm, uint32_t u32BrakeSource);
uint32_t EPWM_GetFaultBrakeIntFlag(EPWM_T *epwm, uint32_t u32BrakeSource);
void EPWM_EnablePeriodInt(EPWM_T *epwm, uint32_t u32ChannelNum,  uint32_t u32IntPeriodType);
void EPWM_DisablePeriodInt(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_ClearPeriodIntFlag(EPWM_T *epwm, uint32_t u32ChannelNum);
uint32_t EPWM_GetPeriodIntFlag(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_EnableZeroInt(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_DisableZeroInt(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_ClearZeroIntFlag(EPWM_T *epwm, uint32_t u32ChannelNum);
uint32_t EPWM_GetZeroIntFlag(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_EnableAcc(EPWM_T *epwm, uint32_t u32ChannelNum, uint32_t u32IntFlagCnt, uint32_t u32IntAccSrc);
void EPWM_DisableAcc(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_EnableAccInt(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_DisableAccInt(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_ClearAccInt(EPWM_T *epwm, uint32_t u32ChannelNum);
uint32_t EPWM_GetAccInt(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_EnableAccPDMA(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_DisableAccPDMA(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_EnableAccStopMode(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_DisableAccStopMode(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_ClearFTDutyIntFlag(EPWM_T *epwm, uint32_t u32ChannelNum);
uint32_t EPWM_GetFTDutyIntFlag(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_EnableLoadMode(EPWM_T *epwm, uint32_t u32ChannelNum, uint32_t u32LoadMode);
void EPWM_DisableLoadMode(EPWM_T *epwm, uint32_t u32ChannelNum, uint32_t u32LoadMode);
void EPWM_ConfigSyncPhase(EPWM_T *epwm, uint32_t u32ChannelNum, uint32_t u32SyncSrc, uint32_t u32Direction, uint32_t u32StartPhase);
void EPWM_EnableSyncPhase(EPWM_T *epwm, uint32_t u32ChannelMask);
void EPWM_DisableSyncPhase(EPWM_T *epwm, uint32_t u32ChannelMask);
void EPWM_EnableSyncNoiseFilter(EPWM_T *epwm, uint32_t u32ClkCnt, uint32_t u32ClkDivSel);
void EPWM_DisableSyncNoiseFilter(EPWM_T *epwm);
void EPWM_EnableSyncPinInverse(EPWM_T *epwm);
void EPWM_DisableSyncPinInverse(EPWM_T *epwm);
void EPWM_SetClockSource(EPWM_T *epwm, uint32_t u32ChannelNum, uint32_t u32ClkSrcSel);
void EPWM_EnableBrakeNoiseFilter(EPWM_T *epwm, uint32_t u32BrakePinNum, uint32_t u32ClkCnt, uint32_t u32ClkDivSel);
void EPWM_DisableBrakeNoiseFilter(EPWM_T *epwm, uint32_t u32BrakePinNum);
void EPWM_EnableBrakePinInverse(EPWM_T *epwm, uint32_t u32BrakePinNum);
void EPWM_DisableBrakePinInverse(EPWM_T *epwm, uint32_t u32BrakePinNum);
void EPWM_SetBrakePinSource(EPWM_T *epwm, uint32_t u32BrakePinNum, uint32_t u32SelAnotherModule);
void EPWM_SetLeadingEdgeBlanking(EPWM_T *epwm, uint32_t u32TrigSrcSel, uint32_t u32TrigType, uint32_t u32BlankingCnt, uint32_t u32BlankingEnable);
uint32_t EPWM_GetWrapAroundFlag(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_ClearWrapAroundFlag(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_EnableFaultDetect(EPWM_T *epwm, uint32_t u32ChannelNum, uint32_t u32AfterPrescaler, uint32_t u32ClkSel);
void EPWM_DisableFaultDetect(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_EnableFaultDetectOutput(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_DisableFaultDetectOutput(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_EnableFaultDetectDeglitch(EPWM_T *epwm, uint32_t u32ChannelNum, uint32_t u32DeglitchSmpCycle);
void EPWM_DisableFaultDetectDeglitch(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_EnableFaultDetectMask(EPWM_T *epwm, uint32_t u32ChannelNum, uint32_t u32MaskCnt);
void EPWM_DisableFaultDetectMask(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_EnableFaultDetectInt(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_DisableFaultDetectInt(EPWM_T *epwm, uint32_t u32ChannelNum);
void EPWM_ClearFaultDetectInt(EPWM_T *epwm, uint32_t u32ChannelNum);
uint32_t EPWM_GetFaultDetectInt(EPWM_T *epwm, uint32_t u32ChannelNum);

   

   

   







#line 787 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\eadc.h"
 






 











 



 



 

 
 
 






 
 
 




#line 70 "..\\M463_Library\\StdDriver\\inc\\eadc.h"







 
 
 
#line 86 "..\\M463_Library\\StdDriver\\inc\\eadc.h"

 
 
 
#line 99 "..\\M463_Library\\StdDriver\\inc\\eadc.h"

 
 
 




   



 
 
 
 







 











 










 










 









 









 









 











 










 











 











 











 











 











 









 









 









 









 









 











 









 











 










 









 









 









 









 









 
















 
#line 442 "..\\M463_Library\\StdDriver\\inc\\eadc.h"















 
#line 468 "..\\M463_Library\\StdDriver\\inc\\eadc.h"















 
#line 494 "..\\M463_Library\\StdDriver\\inc\\eadc.h"















 
#line 520 "..\\M463_Library\\StdDriver\\inc\\eadc.h"








 









 











 









 








 








 








 








 









 









 










 









 






















 











 











 










 









 



 
 
 
int32_t EADC_Open(EADC_T *eadc, uint32_t u32InputMode);
void EADC_Close(EADC_T *eadc);
void EADC_ConfigSampleModule(EADC_T *eadc, uint32_t u32ModuleNum, uint32_t u32TriggerSrc, uint32_t u32Channel);
void EADC_SetTriggerDelayTime(EADC_T *eadc, uint32_t u32ModuleNum, uint32_t u32TriggerDelayTime, uint32_t u32DelayClockDivider);
void EADC_SetExtendSampleTime(EADC_T *eadc, uint32_t u32ModuleNum, uint32_t u32ExtendSampleTime);

   

   

   





#line 788 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\bpwm.h"
 






 











 



 



 
#line 36 "..\\M463_Library\\StdDriver\\inc\\bpwm.h"

 
 
 




 
 
 



 
 
 





 
 
 





 
 
 
#line 76 "..\\M463_Library\\StdDriver\\inc\\bpwm.h"

 
 
 



 
 
 



 
 
 



 
 
 






   




 














 










 









 









 








 








 












 













 










 








 











 








 












 









 






























 
#line 308 "..\\M463_Library\\StdDriver\\inc\\bpwm.h"


 
 
 
uint32_t BPWM_ConfigCaptureChannel(BPWM_T *bpwm, uint32_t u32ChannelNum, uint32_t u32UnitTimeNsec, uint32_t u32CaptureEdge);
uint32_t BPWM_ConfigOutputChannel(BPWM_T *bpwm, uint32_t u32ChannelNum, uint32_t u32Frequency, uint32_t u32DutyCycle);
void BPWM_Start(BPWM_T *bpwm, uint32_t u32ChannelMask);
void BPWM_Stop(BPWM_T *bpwm, uint32_t u32ChannelMask);
void BPWM_ForceStop(BPWM_T *bpwm, uint32_t u32ChannelMask);
void BPWM_EnableADCTrigger(BPWM_T *bpwm, uint32_t u32ChannelNum, uint32_t u32Condition);
void BPWM_DisableADCTrigger(BPWM_T *bpwm, uint32_t u32ChannelNum);
void BPWM_ClearADCTriggerFlag(BPWM_T *bpwm, uint32_t u32ChannelNum, uint32_t u32Condition);
uint32_t BPWM_GetADCTriggerFlag(BPWM_T *bpwm, uint32_t u32ChannelNum);
void BPWM_EnableCapture(BPWM_T *bpwm, uint32_t u32ChannelMask);
void BPWM_DisableCapture(BPWM_T *bpwm, uint32_t u32ChannelMask);
void BPWM_EnableOutput(BPWM_T *bpwm, uint32_t u32ChannelMask);
void BPWM_DisableOutput(BPWM_T *bpwm, uint32_t u32ChannelMask);
void BPWM_EnableCaptureInt(BPWM_T *bpwm, uint32_t u32ChannelNum, uint32_t u32Edge);
void BPWM_DisableCaptureInt(BPWM_T *bpwm, uint32_t u32ChannelNum, uint32_t u32Edge);
void BPWM_ClearCaptureIntFlag(BPWM_T *bpwm, uint32_t u32ChannelNum, uint32_t u32Edge);
uint32_t BPWM_GetCaptureIntFlag(BPWM_T *bpwm, uint32_t u32ChannelNum);
void BPWM_EnableDutyInt(BPWM_T *bpwm, uint32_t u32ChannelNum, uint32_t u32IntDutyType);
void BPWM_DisableDutyInt(BPWM_T *bpwm, uint32_t u32ChannelNum);
void BPWM_ClearDutyIntFlag(BPWM_T *bpwm, uint32_t u32ChannelNum);
uint32_t BPWM_GetDutyIntFlag(BPWM_T *bpwm, uint32_t u32ChannelNum);
void BPWM_EnablePeriodInt(BPWM_T *bpwm, uint32_t u32ChannelNum,  uint32_t u32IntPeriodType);
void BPWM_DisablePeriodInt(BPWM_T *bpwm, uint32_t u32ChannelNum);
void BPWM_ClearPeriodIntFlag(BPWM_T *bpwm, uint32_t u32ChannelNum);
uint32_t BPWM_GetPeriodIntFlag(BPWM_T *bpwm, uint32_t u32ChannelNum);
void BPWM_EnableZeroInt(BPWM_T *bpwm, uint32_t u32ChannelNum);
void BPWM_DisableZeroInt(BPWM_T *bpwm, uint32_t u32ChannelNum);
void BPWM_ClearZeroIntFlag(BPWM_T *bpwm, uint32_t u32ChannelNum);
uint32_t BPWM_GetZeroIntFlag(BPWM_T *bpwm, uint32_t u32ChannelNum);
void BPWM_EnableLoadMode(BPWM_T *bpwm, uint32_t u32ChannelNum, uint32_t u32LoadMode);
void BPWM_DisableLoadMode(BPWM_T *bpwm, uint32_t u32ChannelNum, uint32_t u32LoadMode);
void BPWM_SetClockSource(BPWM_T *bpwm, uint32_t u32ChannelNum, uint32_t u32ClkSrcSel);
uint32_t BPWM_GetWrapAroundFlag(BPWM_T *bpwm, uint32_t u32ChannelNum);
void BPWM_ClearWrapAroundFlag(BPWM_T *bpwm, uint32_t u32ChannelNum);


   

   

   







#line 789 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\wdt.h"
 






 











 



 



 
 
 
 
#line 41 "..\\M463_Library\\StdDriver\\inc\\wdt.h"

 
 
 





 
 
 


 
 
 





   



 










 











 











 












 












 












 














 



 
 
 
 
static __inline void WDT_Close(void);
static __inline void WDT_EnableInt(void);
static __inline void WDT_DisableInt(void);









 
static __inline void WDT_Close(void)
{
    uint32_t u32TimeOutCnt = SystemCoreClock;

    ((WDT_T *) (((uint32_t)0x40000000) + 0x40000UL))->CTL = 0UL;
    while(((WDT_T *) (((uint32_t)0x40000000) + 0x40000UL))->CTL & (0x1ul << (30)))  
    {
        if(--u32TimeOutCnt == 0) break;
    }
}









 
static __inline void WDT_EnableInt(void)
{
    ((WDT_T *) (((uint32_t)0x40000000) + 0x40000UL))->CTL |= (0x1ul << (6));
}









 
static __inline void WDT_DisableInt(void)
{
     
    ((WDT_T *) (((uint32_t)0x40000000) + 0x40000UL))->CTL &= ~((0x1ul << (6)) | (0x1ul << (2)) | (0x1ul << (3)) | (0x1ul << (5)));
}

int32_t WDT_Open(uint32_t u32TimeoutInterval, uint32_t u32ResetDelay, uint32_t u32EnableReset, uint32_t u32EnableWakeup);

   

   

   





#line 790 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\wwdt.h"
 






 











 



 



 
 
 
 
#line 48 "..\\M463_Library\\StdDriver\\inc\\wwdt.h"

 
 
 


   




 










 











 












 












 











 














 


void WWDT_Open(uint32_t u32PreScale, uint32_t u32CmpValue, uint32_t u32EnableInt);

   

   

   





#line 791 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\crc.h"
 






 











 



 



 
 
 
 





 
 
 





 
 
 




   




 













 











 











 



void CRC_Open(uint32_t u32Mode, uint32_t u32Attribute, uint32_t u32Seed, uint32_t u32DataLen);
uint32_t CRC_GetChecksum(void);

   

   

   





#line 792 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\ebi.h"
 






 











 



 



 
 
 
 





 
 
 




 
 
 



 
 
 



 
 
 
#line 67 "..\\M463_Library\\StdDriver\\inc\\ebi.h"

#line 75 "..\\M463_Library\\StdDriver\\inc\\ebi.h"





   




 










 












 











 












 











 












 











 












 











 












 











 












 











 












 











 












 











 












 











 











 


void EBI_Open(uint32_t u32Bank, uint32_t u32DataWidth, uint32_t u32TimingClass, uint32_t u32BusMode, uint32_t u32CSActiveLevel);
void EBI_Close(uint32_t u32Bank);
void EBI_SetBusTiming(uint32_t u32Bank, uint32_t u32TimingConfig, uint32_t u32MclkDiv);

   

   

   





#line 793 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\usci_i2c.h"
 






 











 



 



 

 
 
 
enum UI2C_MASTER_EVENT
{
    MASTER_SEND_ADDRESS = 10,     
    MASTER_SEND_H_WR_ADDRESS,     
    MASTER_SEND_H_RD_ADDRESS,     
    MASTER_SEND_L_ADDRESS,        
    MASTER_SEND_DATA,             
    MASTER_SEND_REPEAT_START,     
    MASTER_READ_DATA,             
    MASTER_STOP,                  
    MASTER_SEND_START             
};

 
 
 
enum UI2C_SLAVE_EVENT
{
    SLAVE_ADDRESS_ACK = 100,       
    SLAVE_H_WR_ADDRESS_ACK,        
    SLAVE_L_WR_ADDRESS_ACK,        
    SLAVE_GET_DATA,                
    SLAVE_SEND_DATA,               
    SLAVE_H_RD_ADDRESS_ACK,        
    SLAVE_L_RD_ADDRESS_ACK         
};

 
 
 





 
 
 



 
 
 



 
 
 
#line 90 "..\\M463_Library\\StdDriver\\inc\\usci_i2c.h"

 
 
 





   

extern int32_t g_UI2C_i32ErrCode;



 











 











 











 











 












 












 












 











 











 











 











 

















 

















 

















 



uint32_t UI2C_Open(UI2C_T *ui2c, uint32_t u32BusClock);
void UI2C_Close(UI2C_T *ui2c);
void UI2C_ClearTimeoutFlag(UI2C_T *ui2c);
void UI2C_Trigger(UI2C_T *ui2c, uint8_t u8Start, uint8_t u8Stop, uint8_t u8Ptrg, uint8_t u8Ack);
void UI2C_DisableInt(UI2C_T *ui2c, uint32_t u32Mask);
void UI2C_EnableInt(UI2C_T *ui2c, uint32_t u32Mask);
uint32_t UI2C_GetBusClockFreq(UI2C_T *ui2c);
uint32_t UI2C_SetBusClockFreq(UI2C_T *ui2c, uint32_t u32BusClock);
uint32_t UI2C_GetIntFlag(UI2C_T *ui2c, uint32_t u32Mask);
void UI2C_ClearIntFlag(UI2C_T* ui2c, uint32_t u32Mask);
uint32_t UI2C_GetData(UI2C_T *ui2c);
void UI2C_SetData(UI2C_T *ui2c, uint8_t u8Data);
void UI2C_SetSlaveAddr(UI2C_T *ui2c, uint8_t u8SlaveNo, uint16_t u16SlaveAddr, uint8_t u8GCMode);
void UI2C_SetSlaveAddrMask(UI2C_T *ui2c, uint8_t u8SlaveNo, uint16_t u16SlaveAddrMask);
void UI2C_EnableTimeout(UI2C_T *ui2c, uint32_t u32TimeoutCnt);
void UI2C_DisableTimeout(UI2C_T *ui2c);
void UI2C_EnableWakeup(UI2C_T *ui2c, uint8_t u8WakeupMode);
void UI2C_DisableWakeup(UI2C_T *ui2c);
uint8_t UI2C_WriteByte(UI2C_T *ui2c, uint8_t u8SlaveAddr, uint8_t data);
uint32_t UI2C_WriteMultiBytes(UI2C_T *ui2c, uint8_t u8SlaveAddr, uint8_t *data, uint32_t u32wLen);
uint8_t UI2C_WriteByteOneReg(UI2C_T *ui2c, uint8_t u8SlaveAddr, uint8_t u8DataAddr, uint8_t data);
uint32_t UI2C_WriteMultiBytesOneReg(UI2C_T *ui2c, uint8_t u8SlaveAddr, uint8_t u8DataAddr, uint8_t *data, uint32_t u32wLen);
uint8_t UI2C_WriteByteTwoRegs(UI2C_T *ui2c, uint8_t u8SlaveAddr, uint16_t u16DataAddr, uint8_t data);
uint32_t UI2C_WriteMultiBytesTwoRegs(UI2C_T *ui2c, uint8_t u8SlaveAddr, uint16_t u16DataAddr, uint8_t *data, uint32_t u32wLen);
uint8_t UI2C_ReadByte(UI2C_T *ui2c, uint8_t u8SlaveAddr);
uint32_t UI2C_ReadMultiBytes(UI2C_T *ui2c, uint8_t u8SlaveAddr, uint8_t *rdata, uint32_t u32rLen);
uint8_t UI2C_ReadByteOneReg(UI2C_T *ui2c, uint8_t u8SlaveAddr, uint8_t u8DataAddr);
uint32_t UI2C_ReadMultiBytesOneReg(UI2C_T *ui2c, uint8_t u8SlaveAddr, uint8_t u8DataAddr, uint8_t *rdata, uint32_t u32rLen);
uint8_t UI2C_ReadByteTwoRegs(UI2C_T *ui2c, uint8_t u8SlaveAddr, uint16_t u16DataAddr);
uint32_t UI2C_ReadMultiBytesTwoRegs(UI2C_T *ui2c, uint8_t u8SlaveAddr, uint16_t u16DataAddr, uint8_t *rdata, uint32_t u32rLen);

   

   

   





#line 794 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\scuart.h"
 






 











 



 



 












   



 

 










 














 













 













 














 













 













 












 



 









 














 













 















 













 



 















 

















 



















 












 














 















 


void SCUART_Close(SC_T* sc);
uint32_t SCUART_Open(SC_T* sc, uint32_t u32Baudrate);
uint32_t SCUART_Read(SC_T* sc, uint8_t pu8RxBuf[], uint32_t u32ReadBytes);
uint32_t SCUART_SetLineConfig(SC_T* sc, uint32_t u32Baudrate, uint32_t u32DataWidth, uint32_t u32Parity, uint32_t u32StopBits);
void SCUART_SetTimeoutCnt(SC_T* sc, uint32_t u32TOC);
uint32_t SCUART_Write(SC_T* sc, uint8_t pu8TxBuf[], uint32_t u32WriteBytes);

   

   

   





#line 795 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\sc.h"
 






 











 



 



 
#line 35 "..\\M463_Library\\StdDriver\\inc\\sc.h"

#line 46 "..\\M463_Library\\StdDriver\\inc\\sc.h"



   




 
























 

























 












 
#line 129 "..\\M463_Library\\StdDriver\\inc\\sc.h"












 
#line 152 "..\\M463_Library\\StdDriver\\inc\\sc.h"











 
#line 174 "..\\M463_Library\\StdDriver\\inc\\sc.h"











 
#line 196 "..\\M463_Library\\StdDriver\\inc\\sc.h"










 












 












 



 
 
 
 
static __inline void SC_SetTxRetry(SC_T *sc, uint32_t u32Count);
static __inline void SC_SetRxRetry(SC_T *sc, uint32_t u32Count);











 
static __inline void SC_SetTxRetry(SC_T *sc, uint32_t u32Count)
{
    uint32_t u32TimeOutCount = 0;

    u32TimeOutCount = (SystemCoreClock);
    while(((sc)->CTL & (0x1ul << (30))) == (0x1ul << (30)))
    {
        if(--u32TimeOutCount == 0) break;
    }

     
    (sc)->CTL &= ~((0x7ul << (20)) | (0x1ul << (23)));

    if((u32Count) != 0UL)
    {
        u32TimeOutCount = (SystemCoreClock);
        while(((sc)->CTL & (0x1ul << (30))) == (0x1ul << (30)))
        {
            if(--u32TimeOutCount == 0) break;
        }
        (sc)->CTL |= (((u32Count) - 1UL) << (20)) | (0x1ul << (23));
    }
}










 
static __inline void SC_SetRxRetry(SC_T *sc, uint32_t u32Count)
{
    uint32_t u32TimeOutCount = 0;

    u32TimeOutCount = (SystemCoreClock);
    while(((sc)->CTL & (0x1ul << (30))) == (0x1ul << (30)))
    {
        if(--u32TimeOutCount == 0) break;
    }

     
    (sc)->CTL &= ~((0x7ul << (16)) | (0x1ul << (19)));

    if((u32Count) != 0UL)
    {
        u32TimeOutCount = (SystemCoreClock);
        while(((sc)->CTL & (0x1ul << (30))) == (0x1ul << (30)))
        {
            if(--u32TimeOutCount == 0) break;
        }
        (sc)->CTL |= (((u32Count) - 1UL) << (16)) | (0x1ul << (19));
    }
}


uint32_t SC_IsCardInserted(SC_T *sc);
void SC_ClearFIFO(SC_T *sc);
void SC_Close(SC_T *sc);
void SC_Open(SC_T *sc, uint32_t u32CardDet, uint32_t u32PWR);
void SC_ResetReader(SC_T *sc);
void SC_SetBlockGuardTime(SC_T *sc, uint32_t u32BGT);
void SC_SetCharGuardTime(SC_T *sc, uint32_t u32CGT);
void SC_StopAllTimer(SC_T *sc);
void SC_StartTimer(SC_T *sc, uint32_t u32TimerNum, uint32_t u32Mode, uint32_t u32ETUCount);
void SC_StopTimer(SC_T *sc, uint32_t u32TimerNum);
uint32_t SC_GetInterfaceClock(SC_T *sc);

   

   

   





#line 796 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\spi.h"
 






 











 



 



 













 
#line 53 "..\\M463_Library\\StdDriver\\inc\\spi.h"

 
#line 63 "..\\M463_Library\\StdDriver\\inc\\spi.h"

 



 





 



 





 



 



 



 
#line 105 "..\\M463_Library\\StdDriver\\inc\\spi.h"

   



 







 








 








 








 








 








 








 








 








 








 









 









 









 








 









 








 








 








 








 










 








 








 









 









 








 








 










 
static __inline void SPII2S_ENABLE_TX_ZCD(SPI_T *i2s, uint32_t u32ChMask)
{
    if(u32ChMask == (0U))
    {
        i2s->I2SCTL |= (0x1ul << (16));
    }
    else
    {
        i2s->I2SCTL |= (0x1ul << (17));
    }
}









 
static __inline void SPII2S_DISABLE_TX_ZCD(SPI_T *i2s, uint32_t u32ChMask)
{
    if(u32ChMask == (0U))
    {
        i2s->I2SCTL &= ~(0x1ul << (16));
    }
    else
    {
        i2s->I2SCTL &= ~(0x1ul << (17));
    }
}







 








 








 








 








 








 








 








 








 








 








 








 











 
static __inline void SPII2S_SET_MONO_RX_CHANNEL(SPI_T *i2s, uint32_t u32Ch)
{
    u32Ch == (0x1ul << (23)) ?
    (i2s->I2SCTL |= (0x1ul << (23))) :
    (i2s->I2SCTL &= ~(0x1ul << (23)));
}








 








 









 










 








 








 




 
uint32_t SPI_Open(SPI_T *spi, uint32_t u32MasterSlave, uint32_t u32SPIMode, uint32_t u32DataWidth, uint32_t u32BusClock);
void SPI_Close(SPI_T *spi);
void SPI_ClearRxFIFO(SPI_T *spi);
void SPI_ClearTxFIFO(SPI_T *spi);
void SPI_DisableAutoSS(SPI_T *spi);
void SPI_EnableAutoSS(SPI_T *spi, uint32_t u32SSPinMask, uint32_t u32ActiveLevel);
uint32_t SPI_SetBusClock(SPI_T *spi, uint32_t u32BusClock);
void SPI_SetFIFO(SPI_T *spi, uint32_t u32TxThreshold, uint32_t u32RxThreshold);
uint32_t SPI_GetBusClock(SPI_T *spi);
void SPI_EnableInt(SPI_T *spi, uint32_t u32Mask);
void SPI_DisableInt(SPI_T *spi, uint32_t u32Mask);
uint32_t SPI_GetIntFlag(SPI_T *spi, uint32_t u32Mask);
void SPI_ClearIntFlag(SPI_T *spi, uint32_t u32Mask);
uint32_t SPI_GetStatus(SPI_T *spi, uint32_t u32Mask);
uint32_t SPI_GetStatus2(SPI_T *spi, uint32_t u32Mask);

uint32_t SPII2S_Open(SPI_T *i2s, uint32_t u32MasterSlave, uint32_t u32SampleRate, uint32_t u32WordWidth, uint32_t u32Channels, uint32_t u32DataFormat);
void SPII2S_Close(SPI_T *i2s);
void SPII2S_EnableInt(SPI_T *i2s, uint32_t u32Mask);
void SPII2S_DisableInt(SPI_T *i2s, uint32_t u32Mask);
uint32_t SPII2S_EnableMCLK(SPI_T *i2s, uint32_t u32BusClock);
void SPII2S_DisableMCLK(SPI_T *i2s);
void SPII2S_SetFIFO(SPI_T *i2s, uint32_t u32TxThreshold, uint32_t u32RxThreshold);


   

   

   





#line 797 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\qspi.h"
 






 











 



 



 













 
#line 54 "..\\M463_Library\\StdDriver\\inc\\qspi.h"

 
#line 64 "..\\M463_Library\\StdDriver\\inc\\qspi.h"

 


   




 







 








 








 








 








 








 








 








 








 








 








 








 








 








 








 








 








 








 








 








 









 









 









 








 









 








 








 








 








 










 








 








 









 









 








 








 




 
uint32_t QSPI_Open(QSPI_T *qspi, uint32_t u32MasterSlave, uint32_t u32QSPIMode, uint32_t u32DataWidth, uint32_t u32BusClock);
void QSPI_Close(QSPI_T *qspi);
void QSPI_ClearRxFIFO(QSPI_T *qspi);
void QSPI_ClearTxFIFO(QSPI_T *qspi);
void QSPI_DisableAutoSS(QSPI_T *qspi);
void QSPI_EnableAutoSS(QSPI_T *qspi, uint32_t u32SSPinMask, uint32_t u32ActiveLevel);
uint32_t QSPI_SetBusClock(QSPI_T *qspi, uint32_t u32BusClock);
void QSPI_SetFIFO(QSPI_T *qspi, uint32_t u32TxThreshold, uint32_t u32RxThreshold);
uint32_t QSPI_GetBusClock(QSPI_T *qspi);
void QSPI_EnableInt(QSPI_T *qspi, uint32_t u32Mask);
void QSPI_DisableInt(QSPI_T *qspi, uint32_t u32Mask);
uint32_t QSPI_GetIntFlag(QSPI_T *qspi, uint32_t u32Mask);
void QSPI_ClearIntFlag(QSPI_T *qspi, uint32_t u32Mask);
uint32_t QSPI_GetStatus(QSPI_T *qspi, uint32_t u32Mask);
uint32_t QSPI_GetStatus2(QSPI_T *qspi, uint32_t u32Mask);


   

   

   





#line 798 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\canfd.h"







 





    #pragma anon_unions


#line 1 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\NuMicro.h"
 






 
#line 15 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\NuMicro.h"


#line 18 "..\\M463_Library\\StdDriver\\inc\\canfd.h"








 



 



 





 
#line 48 "..\\M463_Library\\StdDriver\\inc\\canfd.h"

 



 


 


 


 


 


 


 


 


 


 


 


 


 














 



 
typedef enum
{
    eCANFD_BYTE8  = 0,  
    eCANFD_BYTE12 = 1,  
    eCANFD_BYTE16 = 2,  
    eCANFD_BYTE20 = 3,  
    eCANFD_BYTE24 = 4,  
    eCANFD_BYTE32 = 5,  
    eCANFD_BYTE48 = 6,  
    eCANFD_BYTE64 = 7   
} E_CANFD_DATA_FIELD_SIZE;

 
typedef enum
{
    eCANFD_QUEUE_MODE = 0,  
    eCANFD_FIFO_MODE = 1    
} E_CANFD_MODE;

 
typedef struct
{
    E_CANFD_DATA_FIELD_SIZE eDataFieldSize;      
    E_CANFD_MODE            eModeSel;            
    uint32_t                u32ElemCnt;          
    uint32_t                u32DBufNumber;       
} CANFD_TX_BUF_CONFIG_T;


 
typedef struct
{
    uint32_t u32BitRate;           
    uint16_t u16TDCOffset;         
    uint16_t u16TDCFltrWin;        
    uint8_t  u8TDC;                
} CANFD_NBT_CONFIG_T;


 
typedef struct
{
    uint32_t u32BitRate;           
    uint16_t u16TDCOffset;         
    uint16_t u16TDCFltrWin;        
    uint8_t  u8TDC;                
} CANFD_DBT_CONFIG_T;

 
typedef struct
{
    uint8_t  u8PreDivider;         
    uint16_t u16NominalPrescaler;  
    uint8_t  u8NominalRJumpwidth;  
    uint8_t  u8NominalPhaseSeg1;   
    uint8_t  u8NominalPhaseSeg2;   
    uint8_t  u8NominalPropSeg;     
    uint8_t  u8DataPrescaler;      
    uint8_t  u8DataRJumpwidth;     
    uint8_t  u8DataPhaseSeg1;      
    uint8_t  u8DataPhaseSeg2;      
    uint8_t  u8DataPropSeg;        

} CANFD_TIMEING_CONFIG_T;

 
typedef struct
{
    CANFD_NBT_CONFIG_T sNormBitRate;        
    CANFD_DBT_CONFIG_T sDataBitRate;        
    CANFD_TIMEING_CONFIG_T sConfigBitTing;  
    uint8_t bFDEn;                          
    uint8_t bBitRateSwitch;                 
    uint8_t bEnableLoopBack;                
} CANFD_FD_BT_CONFIG_T;

 
typedef struct
{
    uint32_t u32SIDFC_FLSSA;  
    uint32_t u32XIDFC_FLESA;  
    uint32_t u32RXF0C_F0SA;   
    uint32_t u32RXF1C_F1SA;   
    uint32_t u32RXBC_RBSA;    
    uint32_t u32TXEFC_EFSA;   
    uint32_t u32TXBC_TBSA;    
} CANFD_RAM_PART_T;

 
typedef struct
{
    uint32_t  u32SIDFC;           
    uint32_t  u32XIDFC;           
    uint32_t  u32RxFifo0;         
    uint32_t  u32RxFifo1;         
    uint32_t  u32RxBuf;           
    uint32_t  u32TxBuf;           
    uint32_t  u32TxEventFifo;     
} CANFD_ELEM_SIZE_T;

 
typedef struct
{
    CANFD_FD_BT_CONFIG_T    sBtConfig;         
    CANFD_RAM_PART_T        sMRamStartAddr;    
    CANFD_ELEM_SIZE_T       sElemSize;         
    CANFD_TX_BUF_CONFIG_T   sTxConfig;         
    uint32_t                u32MRamSize;       
} CANFD_FD_T;

 
typedef enum
{
    eCANFD_SID = 0,   
    eCANFD_XID = 1    
} E_CANFD_ID_TYPE;

 
typedef enum
{
    eCANFD_RX_FIFO_0 = 0,
    eCANFD_RX_FIFO_1 = 1,
    eCANFD_RX_DBUF = 2
} E_CANFD_RX_BUF_TYPE;

 
typedef enum
{
    eCANFD_SYNC         = 0,
    eCANFD_IDLE         = 1,
    eCANFD_RECEIVER     = 2,
    eCANFD_TRANSMITTER  = 3
} E_CANFD_COMMUNICATION_STATE;

 
typedef struct
{
    E_CANFD_RX_BUF_TYPE  eRxBuf;          
    uint32_t            u32BufIdx;        
} CANFD_RX_INFO_T;

 
typedef enum
{
    eCANFD_DATA_FRM = 0,       
    eCANFD_REMOTE_FRM = 1      
} E_CANFD_FRM_TYPE;

 
typedef struct
{
    E_CANFD_ID_TYPE   eIdType;                          
    CANFD_RX_INFO_T   sRxInfo;                          
    E_CANFD_FRM_TYPE  eFrmType;                         
    uint32_t          u32Id;                            
    uint32_t          u32DLC;                           
    union
    {
        uint32_t au32Data[(64/4)];     
        uint8_t  au8Data[64];      
    };
    uint8_t           u8MsgMarker;                      
    uint8_t           bFDFormat;                        
    uint8_t           bBitRateSwitch;                   
    uint8_t           bErrStaInd;                       
    uint8_t           bEvntFifoCon;                     
} CANFD_FD_MSG_T;


 
typedef struct
{
    uint32_t u32Id;      
    uint32_t u32Config;  
    union
    {
        uint32_t au32Data[(64/4)];   
        uint8_t  au8Data[64];    
    };
} CANFD_BUF_T;

 
typedef struct
{
    union
    {
        struct
        {
            uint32_t SFID2     : 11;  
            uint32_t reserved1 : 5;
            uint32_t SFID1     : 11;  
            uint32_t SFEC      : 3;   
            uint32_t SFT       : 2;   
        };
        struct
        {
            uint32_t VALUE;  
        };
    };
} CANFD_STD_FILTER_T;

 
typedef struct
{
    union
    {
        struct
        {
            uint32_t EFID1     : 29;  
            uint32_t EFEC      : 3;   
            uint32_t EFID2     : 29;  
            uint32_t reserved1 : 1;
            uint32_t EFT       : 2;   
        };
        struct
        {
            uint32_t LOWVALUE;   
            uint32_t HIGHVALUE;  
        };
    };
} CANFD_EXT_FILTER_T;

 
typedef enum
{
    eCANFD_ACC_NON_MATCH_FRM_RX_FIFO0 = 0x0,   
    eCANFD_ACC_NON_MATCH_FRM_RX_FIFO1 = 0x1,   
    eCANFD_REJ_NON_MATCH_FRM   = 0x3           
} E_CANFD_ACC_NON_MATCH_FRM;


 
typedef enum
{
    eCANFD_SID_FLTR_TYPE_RANGE     = 0x0,  
    eCANFD_SID_FLTR_TYPE_DUAL      = 0x1,  
    eCANFD_SID_FLTR_TYPE_CLASSIC   = 0x2,  
    eCANFD_SID_FLTR_TYPE_DIS       = 0x3   
} E_CANFD_SID_FLTR_ELEM_TYPE;

 
typedef enum
{
    eCANFD_XID_FLTR_TYPE_RANGE      = 0x0,   
    eCANFD_XID_FLTR_TYPE_DUAL       = 0x1,   
    eCANFD_XID_FLTR_TYPE_CLASSIC    = 0x2,   
    eCANFD_XID_FLTR_TYPE_RANGE_XIDAM_NOT_APP     = 0x3    
}  E_CANFD_XID_FLTR_ELEM_TYPE;

 
typedef enum
{
    eCANFD_FLTR_ELEM_DIS         = 0x0,             
    eCANFD_FLTR_ELEM_STO_FIFO0   = 0x1,             
    eCANFD_FLTR_ELEM_STO_FIFO1   = 0x2,             
    eCANFD_FLTR_ELEM_REJ_ID      = 0x3,             
    eCANFD_FLTR_ELEM_SET_PRI     = 0x4,             
    eCANFD_FLTR_ELEM_SET_PRI_STO_FIFO0 = 0x5,       
    eCANFD_FLTR_ELEM_SET_PRI_STO_FIFO1 = 0x6,       
    eCANFD_FLTR_ELEM_STO_RX_BUF_OR_DBG_MSG = 0x7    
} E_CANFD_FLTR_CONFIG;

 
typedef struct
{
    E_CANFD_ID_TYPE     eIdType;          
    uint32_t            u32Id;            
    uint32_t            u32DLC;           
    uint32_t            u32TxTs;          
    uint32_t            u32MsgMarker;     
    uint8_t             bErrStaInd;       
    uint8_t             bRemote;          
    uint8_t             bFDFormat;        
    uint8_t             bBitRateSwitch;   
} CANFD_TX_EVNT_ELEM_T;








void CANFD_Open(CANFD_T *canfd, CANFD_FD_T *psCanfdStr);
void CANFD_Close(CANFD_T *canfd);
void CANFD_EnableInt(CANFD_T *canfd, uint32_t u32IntLine0, uint32_t u32IntLine1, uint32_t u32TXBTIE, uint32_t u32TXBCIE);
void CANFD_DisableInt(CANFD_T *canfd, uint32_t u32IntLine0, uint32_t u32IntLine1, uint32_t u32TXBTIE, uint32_t u32TXBCIE);
uint32_t CANFD_TransmitTxMsg(CANFD_T *canfd, uint32_t u32TxBufIdx, CANFD_FD_MSG_T *psTxMsg);
uint32_t CANFD_TransmitDMsg(CANFD_T *canfd, uint32_t u32TxBufIdx, CANFD_FD_MSG_T *psTxMsg);
void CANFD_SetGFC(CANFD_T *canfd, E_CANFD_ACC_NON_MATCH_FRM eNMStdFrm, E_CANFD_ACC_NON_MATCH_FRM eEMExtFrm, uint32_t u32RejRmtStdFrm, uint32_t u32RejRmtExtFrm);
void CANFD_SetSIDFltr(CANFD_T *canfd, uint32_t u32FltrIdx, uint32_t u32Filter);
void CANFD_SetXIDFltr(CANFD_T *canfd, uint32_t u32FltrIdx, uint32_t u32FilterLow, uint32_t u32FilterHigh);
uint32_t CANFD_ReadRxBufMsg(CANFD_T *canfd, uint8_t u8MbIdx, CANFD_FD_MSG_T *psMsgBuf);
uint32_t CANFD_ReadRxFifoMsg(CANFD_T *canfd, uint8_t u8FifoIdx, CANFD_FD_MSG_T *psMsgBuf);
void CANFD_CopyDBufToMsgBuf(CANFD_BUF_T *psRxBuffer, CANFD_FD_MSG_T *psMsgBuf);
void CANFD_CopyRxFifoToMsgBuf(CANFD_BUF_T *psRxBuf, CANFD_FD_MSG_T *psMsgBuf);
uint32_t CANFD_GetRxFifoWaterLvl(CANFD_T *canfd, uint32_t u32RxFifoNum);
void CANFD_TxBufCancelReq(CANFD_T *canfd, uint32_t u32TxBufIdx);
uint32_t CANFD_IsTxBufCancelFin(CANFD_T *canfd, uint32_t u32TxBufIdx);
uint32_t CANFD_IsTxBufTransmitOccur(CANFD_T *canfd, uint32_t u32TxBufIdx);
uint32_t CANFD_GetTxEvntFifoWaterLvl(CANFD_T *canfd);
void CANFD_CopyTxEvntFifoToUsrBuf(CANFD_T *canfd, uint32_t u32TxEvntNum, CANFD_TX_EVNT_ELEM_T *psTxEvntElem);
void CANFD_GetBusErrCount(CANFD_T *canfd, uint8_t *pu8TxErrBuf, uint8_t *pu8RxErrBuf);
int32_t CANFD_RunToNormal(CANFD_T *canfd, uint8_t u8Enable);
void CANFD_GetDefaultConfig(CANFD_FD_T *psConfig, uint8_t u8OpMode);
void CANFD_ClearStatusFlag(CANFD_T *canfd, uint32_t u32InterruptFlag);
uint32_t CANFD_GetStatusFlag(CANFD_T *canfd, uint32_t u32IntTypeFlag);
uint32_t CANFD_ReadReg(volatile const uint32_t* pu32RegAddr);

   

   

   






    #pragma no_anon_unions


#line 799 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\rtc.h"
 






 











 



 



 
 
 
 


 
 
 





 
 
 
#line 53 "..\\M463_Library\\StdDriver\\inc\\rtc.h"

 
 
 
#line 64 "..\\M463_Library\\StdDriver\\inc\\rtc.h"

 
 
 



 
 
 
#line 81 "..\\M463_Library\\StdDriver\\inc\\rtc.h"












#line 101 "..\\M463_Library\\StdDriver\\inc\\rtc.h"




 
 
 



 
 
 












 
 
 






   




 


 
typedef struct
{
    uint32_t u32Year;            
    uint32_t u32Month;           
    uint32_t u32Day;             
    uint32_t u32DayOfWeek;       
    uint32_t u32Hour;            
    uint32_t u32Minute;          
    uint32_t u32Second;          
    uint32_t u32TimeScale;       
    uint32_t u32AmPm;            
} S_RTC_TIME_DATA_T;

   

extern int32_t g_RTC_i32ErrCode;



 











 











 











 

















 












 












 











 











 












 












 
















 











 











 












 












 


int32_t RTC_Open(S_RTC_TIME_DATA_T *sPt);
void RTC_Close(void);
int32_t RTC_32KCalibration(int32_t i32FrequencyX10000);
void RTC_GetDateAndTime(S_RTC_TIME_DATA_T *sPt);
void RTC_GetAlarmDateAndTime(S_RTC_TIME_DATA_T *sPt);
void RTC_SetDateAndTime(S_RTC_TIME_DATA_T *sPt);
void RTC_SetAlarmDateAndTime(S_RTC_TIME_DATA_T *sPt);
void RTC_SetDate(uint32_t u32Year, uint32_t u32Month, uint32_t u32Day, uint32_t u32DayOfWeek);
void RTC_SetTime(uint32_t u32Hour, uint32_t u32Minute, uint32_t u32Second, uint32_t u32TimeMode, uint32_t u32AmPm);
void RTC_SetAlarmDate(uint32_t u32Year, uint32_t u32Month, uint32_t u32Day);
void RTC_SetAlarmTime(uint32_t u32Hour, uint32_t u32Minute, uint32_t u32Second, uint32_t u32TimeMode, uint32_t u32AmPm);
void RTC_SetAlarmDateMask(uint8_t u8IsTenYMsk, uint8_t u8IsYMsk, uint8_t u8IsTenMMsk, uint8_t u8IsMMsk, uint8_t u8IsTenDMsk, uint8_t u8IsDMsk);
void RTC_SetAlarmTimeMask(uint8_t u8IsTenHMsk, uint8_t u8IsHMsk, uint8_t u8IsTenMMsk, uint8_t u8IsMMsk, uint8_t u8IsTenSMsk, uint8_t u8IsSMsk);
uint32_t RTC_GetDayOfWeek(void);
void RTC_SetTickPeriod(uint32_t u32TickSelection);
void RTC_EnableInt(uint32_t u32IntFlagMask);
void RTC_DisableInt(uint32_t u32IntFlagMask);
void RTC_EnableSpareAccess(void);
void RTC_DisableSpareRegister(void);
void RTC_StaticTamperEnable(uint32_t u32TamperSelect, uint32_t u32DetecLevel, uint32_t u32DebounceEn);
void RTC_StaticTamperDisable(uint32_t u32TamperSelect);
void RTC_DynamicTamperEnable(uint32_t u32PairSel, uint32_t u32DebounceEn, uint32_t u32Pair1Source, uint32_t u32Pair2Source);
void RTC_DynamicTamperDisable(uint32_t u32PairSel);
void RTC_DynamicTamperConfig(uint32_t u32ChangeRate, uint32_t u32SeedReload, uint32_t u32RefPattern, uint32_t u32Seed);
uint32_t RTC_SetClockSource(uint32_t u32ClkSrc);
void RTC_SetGPIOMode(uint32_t u32PFPin, uint32_t u32Mode, uint32_t u32DigitalCtl, uint32_t u32PullCtl, uint32_t u32OutputLevel);
void RTC_SetGPIOLevel(uint32_t u32PFPin, uint32_t u32OutputLevel);

   

   

   





#line 800 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\usci_uart.h"
 






 












 



 



 

 
 
 





 
 
 







 
 
 
#line 59 "..\\M463_Library\\StdDriver\\inc\\usci_uart.h"


   




 












 












 













 













 














 














 












 













 













 













 













 















 















 














 














 

















 

















 












 






















 












 














 













 












 











 











 











 











 
















 














 





void UUART_ClearIntFlag(UUART_T* uuart, uint32_t u32Mask);
uint32_t UUART_GetIntFlag(UUART_T* uuart, uint32_t u32Mask);
void UUART_Close(UUART_T* uuart);
void UUART_DisableInt(UUART_T*  uuart, uint32_t u32Mask);
void UUART_EnableInt(UUART_T*  uuart, uint32_t u32Mask);
uint32_t UUART_Open(UUART_T* uuart, uint32_t u32baudrate);
uint32_t UUART_Read(UUART_T* uuart, uint8_t pu8RxBuf[], uint32_t u32ReadBytes);
uint32_t UUART_SetLine_Config(UUART_T* uuart, uint32_t u32baudrate, uint32_t u32data_width, uint32_t u32parity, uint32_t u32stop_bits);
uint32_t UUART_Write(UUART_T* uuart, uint8_t pu8TxBuf[], uint32_t u32WriteBytes);
void UUART_EnableWakeup(UUART_T* uuart, uint32_t u32WakeupMode);
void UUART_DisableWakeup(UUART_T* uuart);
void UUART_EnableFlowCtrl(UUART_T* uuart);
void UUART_DisableFlowCtrl(UUART_T* uuart);


   

   

   





#line 801 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\sdh.h"
 






 
#line 1 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"
 
 
 





 






 







 




  
 








#line 47 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"


  



    typedef unsigned int size_t;    









 
 

 



    typedef struct __va_list __va_list;






   




 




typedef struct __fpos_t_struct {
    unsigned __int64 __pos;
    



 
    struct {
        unsigned int __state1, __state2;
    } __mbstate;
} fpos_t;
   


 


   

 

typedef struct __FILE FILE;
   






 

#line 136 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"


extern FILE __stdin, __stdout, __stderr;
extern FILE *__aeabi_stdin, *__aeabi_stdout, *__aeabi_stderr;

#line 166 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"
    

    

    





     



   


 


   


 

   



 

   


 




   


 





    


 






extern __declspec(__nothrow) int remove(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int rename(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) FILE *tmpfile(void);
   




 
extern __declspec(__nothrow) char *tmpnam(char *  );
   











 

extern __declspec(__nothrow) int fclose(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) int fflush(FILE *  );
   







 
extern __declspec(__nothrow) FILE *fopen(const char * __restrict  ,
                           const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   








































 
extern __declspec(__nothrow) FILE *freopen(const char * __restrict  ,
                    const char * __restrict  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(2,3)));
   








 
extern __declspec(__nothrow) void setbuf(FILE * __restrict  ,
                    char * __restrict  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) int setvbuf(FILE * __restrict  ,
                   char * __restrict  ,
                   int  , size_t  ) __attribute__((__nonnull__(1)));
   















 
#pragma __printf_args
extern __declspec(__nothrow) int fprintf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   


















 
#pragma __printf_args
extern __declspec(__nothrow) int _fprintf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   




 
#pragma __printf_args
extern __declspec(__nothrow) int _printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






 
#pragma __printf_args
extern __declspec(__nothrow) int _sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int __ARM_snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));


#pragma __printf_args
extern __declspec(__nothrow) int snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   















 

#pragma __printf_args
extern __declspec(__nothrow) int _snprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int fscanf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






























 
#pragma __scanf_args
extern __declspec(__nothrow) int _fscanf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   






 
#pragma __scanf_args
extern __declspec(__nothrow) int _scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int sscanf(const char * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   








 
#pragma __scanf_args
extern __declspec(__nothrow) int _sscanf(const char * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

 
extern __declspec(__nothrow) int vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int _vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int _vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int _vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int __ARM_vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int _vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int vfprintf(FILE * __restrict  ,
                    const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int vsprintf(char * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int __ARM_vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));

extern __declspec(__nothrow) int vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   







 

extern __declspec(__nothrow) int _vsprintf(char * __restrict  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vfprintf(FILE * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vsnprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int asprintf(char **  , const char * __restrict  , ...) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) int vasprintf(char **  , const char * __restrict  , __va_list  ) __attribute__((__nonnull__(2)));

#pragma __printf_args
extern __declspec(__nothrow) int __ARM_asprintf(char **  , const char * __restrict  , ...) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) int __ARM_vasprintf(char **  , const char * __restrict  , __va_list  ) __attribute__((__nonnull__(2)));
   








 

extern __declspec(__nothrow) int fgetc(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) char *fgets(char * __restrict  , int  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   










 
extern __declspec(__nothrow) int fputc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   







 
extern __declspec(__nothrow) int fputs(const char * __restrict  , FILE * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int getc(FILE *  ) __attribute__((__nonnull__(1)));
   







 




    extern __declspec(__nothrow) int (getchar)(void);

   





 
extern __declspec(__nothrow) char *gets(char *  ) __attribute__((__nonnull__(1)));
   









 
extern __declspec(__nothrow) int putc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   





 




    extern __declspec(__nothrow) int (putchar)(int  );

   



 
extern __declspec(__nothrow) int puts(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int ungetc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   






















 

extern __declspec(__nothrow) size_t fread(void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   











 

extern __declspec(__nothrow) size_t __fread_bytes_avail(void * __restrict  ,
                    size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   











 

extern __declspec(__nothrow) size_t fwrite(const void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   







 

extern __declspec(__nothrow) int fgetpos(FILE * __restrict  , fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) int fseek(FILE *  , long int  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) int fsetpos(FILE * __restrict  , const fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   










 
extern __declspec(__nothrow) long int ftell(FILE *  ) __attribute__((__nonnull__(1)));
   











 
extern __declspec(__nothrow) void rewind(FILE *  ) __attribute__((__nonnull__(1)));
   





 

extern __declspec(__nothrow) void clearerr(FILE *  ) __attribute__((__nonnull__(1)));
   




 

extern __declspec(__nothrow) int feof(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) int ferror(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) void perror(const char *  );
   









 

extern __declspec(__nothrow) int _fisatty(FILE *   ) __attribute__((__nonnull__(1)));
    
 

extern __declspec(__nothrow) void __use_no_semihosting_swi(void);
extern __declspec(__nothrow) void __use_no_semihosting(void);
    





 











#line 1021 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"



 

#line 10 "..\\M463_Library\\StdDriver\\inc\\sdh.h"












 



 




 






 



 






 
#line 60 "..\\M463_Library\\StdDriver\\inc\\sdh.h"










 






   



 
typedef struct SDH_info_t
{
    unsigned char   IsCardInsert;    
    unsigned char   R3Flag;
    unsigned char   R7Flag;
    unsigned char volatile DataReadyFlag;
    unsigned int    CardType;        
    unsigned int    RCA;             
    unsigned int    totalSectorN;    
    unsigned int    diskSize;        
    int             sectorSize;      
    unsigned char   *dmabuf;
} SDH_INFO_T;                        

   

 
extern SDH_INFO_T SD0, SD1;
extern int32_t g_SDH_i32ErrCode;
 



 












 












 

















 














 











 









 



void SDH_Open(SDH_T *sdh, uint32_t u32CardDetSrc);
uint32_t SDH_Probe(SDH_T *sdh);
uint32_t SDH_Read(SDH_T *sdh, uint8_t *pu8BufAddr, uint32_t u32StartSec, uint32_t u32SecCount);
uint32_t SDH_Write(SDH_T *sdh, uint8_t *pu8BufAddr, uint32_t u32StartSec, uint32_t u32SecCount);

uint32_t SDH_CardDetection(SDH_T *sdh);
void SDH_Open_Disk(SDH_T *sdh, uint32_t u32CardDetSrc);
void SDH_Close_Disk(SDH_T *sdh);


   

   

   





#line 802 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\usbd.h"
 






 













 



 



 

typedef struct s_usbd_info
{
    uint8_t *gu8DevDesc;             
    uint8_t *gu8ConfigDesc;          
    uint8_t **gu8StringDesc;         
    uint8_t **gu8HidReportDesc;      
    uint8_t *gu8BosDesc;             
    uint32_t *gu32HidReportSize;     
    uint32_t *gu32ConfigHidDescIdx;  

} S_USBD_INFO_T;   

extern const S_USBD_INFO_T gsInfo;

   




 




#line 81 "..\\M463_Library\\StdDriver\\inc\\usbd.h"

 
 




 
#line 100 "..\\M463_Library\\StdDriver\\inc\\usbd.h"

 
#line 113 "..\\M463_Library\\StdDriver\\inc\\usbd.h"

 



 



 
#line 133 "..\\M463_Library\\StdDriver\\inc\\usbd.h"

 







 


 

 
 
 




#line 161 "..\\M463_Library\\StdDriver\\inc\\usbd.h"







#line 185 "..\\M463_Library\\StdDriver\\inc\\usbd.h"

#line 211 "..\\M463_Library\\StdDriver\\inc\\usbd.h"

#line 218 "..\\M463_Library\\StdDriver\\inc\\usbd.h"












   




 











 












 











 











 











 











 











 











 











 











 














 











 














 











 













 











 

















 












 











 












 












 













 











 













 













 











 











 











 












 











 











 












 











 











 















 
static __inline void USBD_MemCopy(uint8_t dest[], uint8_t src[], uint32_t size)
{
    uint32_t volatile i=0ul;

    while(size--)
    {
        dest[i] = src[i];
        i++;
    }
}










 
static __inline void USBD_SetStall(uint8_t epnum)
{
    uint32_t u32CfgAddr;
    uint32_t u32Cfg;
    uint32_t i;

    for(i = 0ul; i < 25ul; i++)
    {
        u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0xC0000UL))->EP[0].CFG;  
        u32Cfg = *((volatile uint32_t *)(u32CfgAddr));

        if((u32Cfg & 0xful) == epnum)
        {
            u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0xC0000UL))->EP[0].CFGP;  
            u32Cfg = *((volatile uint32_t *)(u32CfgAddr));

            *((volatile uint32_t *)(u32CfgAddr)) = (u32Cfg | (0x1ul << (1)));
            break;
        }
    }
}










 
static __inline void USBD_ClearStall(uint8_t epnum)
{
    uint32_t u32CfgAddr;
    uint32_t u32Cfg;
    uint32_t i;

    for(i = 0ul; i < 25ul; i++)
    {
        u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0xC0000UL))->EP[0].CFG;  
        u32Cfg = *((volatile uint32_t *)(u32CfgAddr));

        if((u32Cfg & 0xful) == epnum)
        {
            u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0xC0000UL))->EP[0].CFGP;  
            u32Cfg = *((volatile uint32_t *)(u32CfgAddr));

            *((volatile uint32_t *)(u32CfgAddr)) = (u32Cfg & ~(0x1ul << (1)));
            break;
        }
    }
}











 
static __inline uint32_t USBD_GetStall(uint8_t epnum)
{
    uint32_t u32CfgAddr;
    uint32_t u32Cfg;
    uint32_t i;

    for(i = 0ul; i < 25ul; i++)
    {
        u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0xC0000UL))->EP[0].CFG;  
        u32Cfg = *((volatile uint32_t *)(u32CfgAddr));

        if((u32Cfg & 0xful) == epnum)
        {
            u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) (((uint32_t)0x40000000) + 0xC0000UL))->EP[0].CFGP;  
            break;
        }
    }

    return ((*((volatile uint32_t *)(u32CfgAddr))) & (0x1ul << (1)));
}

extern uint8_t g_usbd_SetupPacket[8];
extern volatile uint8_t g_usbd_RemoteWakeupEn;


typedef void (*VENDOR_REQ)(void);            
typedef void (*CLASS_REQ)(void);             
typedef void (*SET_INTERFACE_REQ)(uint32_t u32AltInterface);     
typedef void (*SET_CONFIG_CB)(void);        


 
void USBD_Open(const S_USBD_INFO_T *param, CLASS_REQ pfnClassReq, SET_INTERFACE_REQ pfnSetInterface);
void USBD_Start(void);
void USBD_GetSetupPacket(uint8_t *buf);
void USBD_ProcessSetupPacket(void);
void USBD_GetDescriptor(void);
void USBD_StandardRequest(void);
void USBD_PrepareCtrlIn(uint8_t pu8Buf[], uint32_t u32Size);
void USBD_CtrlIn(void);
void USBD_PrepareCtrlOut(uint8_t *pu8Buf, uint32_t u32Size);
void USBD_CtrlOut(void);
void USBD_SwReset(void);
void USBD_SetVendorRequest(VENDOR_REQ pfnVendorReq);
void USBD_SetConfigCallback(SET_CONFIG_CB pfnSetConfigCallback);
void USBD_LockEpStall(uint32_t u32EpBitmap);


   

   

   





#line 803 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\hsusbd.h"
 






 











 



 



 
 






#line 49 "..\\M463_Library\\StdDriver\\inc\\hsusbd.h"

 
 





 
#line 68 "..\\M463_Library\\StdDriver\\inc\\hsusbd.h"

 
#line 77 "..\\M463_Library\\StdDriver\\inc\\hsusbd.h"

 
#line 92 "..\\M463_Library\\StdDriver\\inc\\hsusbd.h"

 
 
 





   



 


typedef struct HSUSBD_CMD_STRUCT
{
    uint8_t  bmRequestType;
    uint8_t  bRequest;
    uint16_t wValue;
    uint16_t wIndex;
    uint16_t wLength;

} S_HSUSBD_CMD_T;  




typedef struct s_hsusbd_info
{
    uint8_t *gu8DevDesc;             
    uint8_t *gu8ConfigDesc;          
    uint8_t **gu8StringDesc;         
    uint8_t *gu8QualDesc;            
    uint8_t *gu8FullConfigDesc;      
    uint8_t *gu8HSOtherConfigDesc;   
    uint8_t *gu8FSOtherConfigDesc;   
    uint8_t *gu8BosDesc;             
    uint8_t **gu8HidReportDesc;      
    uint32_t *gu32HidReportSize;     
    uint32_t *gu32ConfigHidDescIdx;  

} S_HSUSBD_INFO_T;  


   

 
extern uint32_t g_u32HsEpStallLock;
extern uint8_t volatile g_hsusbd_Configured;
extern uint8_t g_hsusbd_ShortPacket;
extern uint8_t g_hsusbd_CtrlZero;
extern uint8_t g_hsusbd_UsbAddr;
extern uint32_t volatile g_hsusbd_DmaDone;
extern uint32_t g_hsusbd_CtrlInSize;
extern S_HSUSBD_INFO_T gsHSInfo;
extern S_HSUSBD_CMD_T gUsbCmd;
extern volatile uint8_t g_hsusbd_RemoteWakeupEn;
 




 

#line 188 "..\\M463_Library\\StdDriver\\inc\\hsusbd.h"







 
static __inline void HSUSBD_MemCopy(uint8_t u8Dst[], uint8_t u8Src[], uint32_t u32Size)
{
    uint32_t i = 0ul;

    while (u32Size--)
    {
        u8Dst[i] = u8Src[i];
        i++;
    }
}





 
static __inline void HSUSBD_ResetDMA(void)
{
    ((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->DMACNT = 0ul;
    ((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->DMACTL = 0x80ul;
    ((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->DMACTL = 0x00ul;
}






 
static __inline void HSUSBD_SetEpBufAddr(uint32_t u32Ep, uint32_t u32Base, uint32_t u32Len)
{
    if (u32Ep == 0xfful)
    {
        ((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->CEPBUFST = u32Base;
        ((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->CEPBUFEND   = u32Base + u32Len - 1ul;
    }
    else
    {
        ((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->EP[u32Ep].EPBUFST = u32Base;
        ((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->EP[u32Ep].EPBUFEND = u32Base + u32Len - 1ul;
    }
}








 
static __inline void HSUSBD_ConfigEp(uint32_t u32Ep, uint32_t u32EpNum, uint32_t u32EpType, uint32_t u32EpDir)
{
    if (u32EpType == ((uint32_t)0x00000002ul))
    {
        ((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->EP[u32Ep].EPRSPCTL = (((uint32_t)0x00000001ul)|((uint32_t)0x00000000ul));
    }
    else if (u32EpType == ((uint32_t)0x00000004ul))
    {
        ((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->EP[u32Ep].EPRSPCTL = (((uint32_t)0x00000001ul)|((uint32_t)0x00000002ul));
    }
    else if (u32EpType == ((uint32_t)0x00000006ul))
    {
        ((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->EP[u32Ep].EPRSPCTL = (((uint32_t)0x00000001ul)|((uint32_t)0x00000004ul));
    }

    ((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->EP[u32Ep].EPCFG = (u32EpType|u32EpDir|((uint32_t)0x00000001ul)|(u32EpNum << 4));
}






 
static __inline void HSUSBD_SetEpStall(uint32_t u32Ep)
{
    if (u32Ep == 0xfful)
    {
        (((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->CEPCTL = (((uint32_t)0x00000002ul)));
    }
    else
    {
        ((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->EP[u32Ep].EPRSPCTL = (((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->EP[u32Ep].EPRSPCTL & 0xf7ul) | ((uint32_t)0x00000010ul);
    }
}








 
static __inline void HSUSBD_SetStall(uint32_t u32EpNum)
{
    uint32_t i;

    if (u32EpNum == 0ul)
    {
        (((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->CEPCTL = (((uint32_t)0x00000002ul)));
    }
    else
    {
        for (i=0ul; i<12ul; i++)
        {
            if (((((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->EP[i].EPCFG & 0xf0ul) >> 4) == u32EpNum)
            {
                ((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->EP[i].EPRSPCTL = (((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->EP[i].EPRSPCTL & 0xf7ul) | ((uint32_t)0x00000010ul);
            }
        }
    }
}






 
static __inline void  HSUSBD_ClearEpStall(uint32_t u32Ep)
{
    ((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->EP[u32Ep].EPRSPCTL = ((uint32_t)0x00000008ul);
}








 
static __inline void HSUSBD_ClearStall(uint32_t u32EpNum)
{
    uint32_t i;

    for (i=0ul; i<12ul; i++)
    {
        if (((((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->EP[i].EPCFG & 0xf0ul) >> 4) == u32EpNum)
        {
            ((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->EP[i].EPRSPCTL = ((uint32_t)0x00000008ul);
        }
    }
}







 
static __inline uint32_t HSUSBD_GetEpStall(uint32_t u32Ep)
{
    return (((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->EP[u32Ep].EPRSPCTL & ((uint32_t)0x00000010ul));
}









 
static __inline uint32_t HSUSBD_GetStall(uint32_t u32EpNum)
{
    uint32_t i;
    uint32_t val = 0ul;

    for (i=0ul; i<12ul; i++)
    {
        if (((((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->EP[i].EPCFG & 0xf0ul) >> 4) == u32EpNum)
        {
            val = (((HSUSBD_T *)(((uint32_t)0x40000000) + 0x19000UL))->EP[i].EPRSPCTL & ((uint32_t)0x00000010ul));
            break;
        }
    }
    return val;
}


 
typedef void (*HSUSBD_VENDOR_REQ)(void);  
typedef void (*HSUSBD_CLASS_REQ)(void);  
typedef void (*HSUSBD_SET_INTERFACE_REQ)(uint32_t u32AltInterface);  

int32_t HSUSBD_Open(S_HSUSBD_INFO_T *param, HSUSBD_CLASS_REQ pfnClassReq, HSUSBD_SET_INTERFACE_REQ pfnSetInterface);
void HSUSBD_Start(void);
void HSUSBD_ProcessSetupPacket(void);
void HSUSBD_StandardRequest(void);
void HSUSBD_UpdateDeviceState(void);
void HSUSBD_PrepareCtrlIn(uint8_t pu8Buf[], uint32_t u32Size);
void HSUSBD_CtrlIn(void);
int32_t HSUSBD_CtrlOut(uint8_t pu8Buf[], uint32_t u32Size);
void HSUSBD_SwReset(void);
void HSUSBD_SetVendorRequest(HSUSBD_VENDOR_REQ pfnVendorReq);



   

   

   





#line 804 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\otg.h"
 






 











 



 




 



 
 
 






   




 

 
 
 








 








 









 








 








 








 








 








 










 










 





















 





















 





















 





















 
















 




   

   

   





#line 805 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\hsotg.h"
 






 











 



 




 



 
 
 





#line 48 "..\\M463_Library\\StdDriver\\inc\\hsotg.h"


   




 

 
 
 








 








 









 








 








 








 








 








 










 










 





















 





















 





















 





















 
















 















 




   

   

   





#line 806 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\psio.h"
 






 













 



 



 

 
 
 








#line 52 "..\\M463_Library\\StdDriver\\inc\\psio.h"

#line 61 "..\\M463_Library\\StdDriver\\inc\\psio.h"

#line 70 "..\\M463_Library\\StdDriver\\inc\\psio.h"

































#line 111 "..\\M463_Library\\StdDriver\\inc\\psio.h"

   



 


 
typedef struct
{
    unsigned CKPT0SLT: 4;   
    unsigned CKPT1SLT: 4;   
    unsigned CKPT2SLT: 4;   
    unsigned CKPT3SLT: 4;   
    unsigned CKPT4SLT: 4;   
    unsigned CKPT5SLT: 4;   
    unsigned CKPT6SLT: 4;   
    unsigned CKPT7SLT: 4;   
    unsigned CKPT0ACT: 4;   
    unsigned CKPT1ACT: 4;   
    unsigned CKPT2ACT: 4;   
    unsigned CKPT3ACT: 4;   
    unsigned CKPT4ACT: 4;   
    unsigned CKPT5ACT: 4;   
    unsigned CKPT6ACT: 4;   
    unsigned CKPT7ACT: 4;   
} S_PSIO_CP_CONFIG;
   



 



















 




















 





















 




















 













































 




























 





























 




















 

























 





















 

























 





















 





















 
















 
















 

















 

















 
















 


























 


















 
























 





















 























 

























 


























 


























 





















 




















 





















 






































 































 






































 




 
 
 






















 
static __inline void PSIO_SET_INTCTL(PSIO_T *psio, uint32_t u32SC, uint32_t u32Int, uint32_t u32Slot)
{
    if (u32Int == 0x00000000UL)
    {
        (psio)->INTCTL = (((psio)->INTCTL & ~(0xful << (0)) & ~(0x3ul << (8)))
                          | ((u32SC) << (8))
                          | ((u32Slot) << (0)));
    }
    else if (u32Int == 0x00000001UL)
    {
        (psio)->INTCTL = (((psio)->INTCTL & ~(0xful << (4)) & ~(0x3ul << (12)))
                          | ((u32SC) << (12))
                          | ((u32Slot) << (4)));
    }
}













 
static __inline void PSIO_CLEAR_INTCTL(PSIO_T *psio, uint32_t u32Int)
{
    if (u32Int == 0x00000000UL)
    {
        (psio)->INTCTL = ((psio)->INTCTL & ~(0xful << (0)) & ~(0x3ul << (8)));
    }
    else if (u32Int == 0x00000001UL)
    {
        (psio)->INTCTL = ((psio)->INTCTL & ~(0xful << (4)) & ~(0x3ul << (12)));
    }
}




































 
static __inline void PSIO_SET_SCCTL(PSIO_T *psio, uint32_t u32SC, uint32_t u32InitSlot, uint32_t u32EndSlot, uint32_t u32LoopCnt, uint32_t u32Repeat)
{
    (psio)->SCCT[u32SC].SCCTL = ((psio)->SCCT[u32SC].SCCTL & ~(0xful << (0)) & ~(0xful << (4)) & ~(0x3ful << (8)))
                                | ((u32InitSlot) << (0))
                                | ((u32EndSlot) << (4))
                                | ((u32LoopCnt & 0x3F) << (8));

    if (u32Repeat == 0x00000001UL)
        (psio)->SCCT[u32SC].SCCTL |= (0x1ul << (17));
    else if (u32Repeat == 0x00000000UL)
        (psio)->SCCT[u32SC].SCCTL &= ~(0x1ul << (17));
}










































 
static __inline void PSIO_SET_GENCTL(PSIO_T *psio, uint32_t u32Pin, uint32_t u32PinEn, uint32_t u32SC, uint32_t u32IOMode, uint32_t u32PinInit, uint32_t u32PinInterval)
{
    (psio)->GNCT[u32Pin].GENCTL = ((psio)->GNCT[u32Pin].GENCTL & ~(0x3ul << (24)) & ~(0x3ul << (0))
                                   & ~(0x3ul << (2)) & ~(0x3ul << (4)))
                                  | ((u32SC) << (24)) | ((u32IOMode) << (0))
                                  | ((u32PinInit) << (2)) | ((u32PinInterval) << (4));

    if (u32PinEn == 0x00000001UL)
        (psio)->GNCT[u32Pin].GENCTL |= (0x1ul << (26));
    else if (u32PinEn == 0x00000000UL)
        (psio)->GNCT[u32Pin].GENCTL &= ~(0x1ul << (26));
}



































 
static __inline void PSIO_SWITCH_MODE(PSIO_T *psio, uint32_t u32Pin, uint32_t u32SwPoint, uint32_t u32SwMode, uint32_t u32SwCP)
{
    if (u32SwPoint == 0x00000000UL)
    {
        (psio)->GNCT[u32Pin].GENCTL = ((psio)->GNCT[u32Pin].GENCTL & ~(0x3ul << (16)) & ~(0xful << (8)))
                                      | ((u32SwMode) << (16)) | ((u32SwCP + 1) << (8));
    }
    else if (u32SwPoint == 0x00000001UL)
    {
        (psio)->GNCT[u32Pin].GENCTL = ((psio)->GNCT[u32Pin].GENCTL & ~(0x3ul << (18)) & ~(0xful << (12)))
                                      | ((u32SwMode) << (18)) | ((u32SwCP + 1) << (12));
    }
}




















 
static __inline void PSIO_SET_CP_CONFIG(PSIO_T *psio, uint32_t u32Pin, const S_PSIO_CP_CONFIG *sConfig)
{
    psio->GNCT[u32Pin].CPCTL0 = *(uint32_t *)sConfig;
    psio->GNCT[u32Pin].CPCTL1 = *((uint32_t *)sConfig + 1);
}

   

   

   





#line 807 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"
#line 1 "..\\M463_Library\\StdDriver\\inc\\bmc.h"
 






 











 



 



 









#line 46 "..\\M463_Library\\StdDriver\\inc\\bmc.h"






#line 60 "..\\M463_Library\\StdDriver\\inc\\bmc.h"


   




 






 







 










 










 










 







 







 







 







 







 







 







 







 







 







 







 



uint32_t BMC_SetBitClock(uint32_t u32BitClock);
uint32_t BMC_GetBitClock(void);
uint32_t BMC_SetDummyDelayPeriod(uint32_t u32ChGroup, uint32_t u32DumDelay);
void BMC_EnableInt(uint32_t u32Mask);
void BMC_DisableInt(uint32_t u32Mask);
uint32_t BMC_GetIntFlag(uint32_t u32Mask);
void BMC_ClearIntFlag(uint32_t u32Mask);
uint32_t BMC_GetStatus(uint32_t u32Mask);
void BMC_ClearStatus(uint32_t u32Mask);


   

   

   





#line 808 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\m460.h"








#line 13 "..\\M463_Library\\Device\\Nuvoton\\m460\\Include\\NuMicro.h"




#line 3 "..\\LCD0.c"
#line 4 "..\\LCD0.c"
#line 1 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"




 





 












 






   









 






#line 61 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"

#line 75 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"







   




 















 
#line 112 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"











 





extern __attribute__((__pcs__("aapcs"))) unsigned __ARM_dcmp4(double  , double  );
extern __attribute__((__pcs__("aapcs"))) unsigned __ARM_fcmp4(float  , float  );
    




 

extern __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_fpclassifyf(float  );
extern __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_fpclassify(double  );
     
     

static inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isfinitef(float __x)
{
    return (((*(unsigned *)&(__x)) >> 23) & 0xff) != 0xff;
}
static inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isfinite(double __x)
{
    return (((*(1 + (unsigned *)&(__x))) >> 20) & 0x7ff) != 0x7ff;
}
     
     

static inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isinff(float __x)
{
    return ((*(unsigned *)&(__x)) << 1) == 0xff000000;
}
static inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isinf(double __x)
{
    return (((*(1 + (unsigned *)&(__x))) << 1) == 0xffe00000) && ((*(unsigned *)&(__x)) == 0);
}
     
     

static inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_islessgreaterf(float __x, float __y)
{
    unsigned __f = __ARM_fcmp4(__x, __y) >> 28;
    return (__f == 8) || (__f == 2);  
}
static inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_islessgreater(double __x, double __y)
{
    unsigned __f = __ARM_dcmp4(__x, __y) >> 28;
    return (__f == 8) || (__f == 2);  
}
    


 

static inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isnanf(float __x)
{
    return (0x7f800000 - ((*(unsigned *)&(__x)) & 0x7fffffff)) >> 31;
}
static inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isnan(double __x)
{
    unsigned __xf = (*(1 + (unsigned *)&(__x))) | (((*(unsigned *)&(__x)) == 0) ? 0 : 1);
    return (0x7ff00000 - (__xf & 0x7fffffff)) >> 31;
}
     
     

static inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isnormalf(float __x)
{
    unsigned __xe = ((*(unsigned *)&(__x)) >> 23) & 0xff;
    return (__xe != 0xff) && (__xe != 0);
}
static inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_isnormal(double __x)
{
    unsigned __xe = ((*(1 + (unsigned *)&(__x))) >> 20) & 0x7ff;
    return (__xe != 0x7ff) && (__xe != 0);
}
     
     

static inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_signbitf(float __x)
{
    return (*(unsigned *)&(__x)) >> 31;
}
static inline __declspec(__nothrow) __attribute__((__pcs__("aapcs"))) int __ARM_signbit(double __x)
{
    return (*(1 + (unsigned *)&(__x))) >> 31;
}
     
     








#line 230 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"







   
  typedef float float_t;
  typedef double double_t;
#line 251 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"



extern const int math_errhandling;
#line 261 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"

extern __declspec(__nothrow) double acos(double  );
    
    
    
extern __declspec(__nothrow) double asin(double  );
    
    
    
    

extern __declspec(__nothrow) __attribute__((const)) double atan(double  );
    
    

extern __declspec(__nothrow) double atan2(double  , double  );
    
    
    
    

extern __declspec(__nothrow) double cos(double  );
    
    
    
    
extern __declspec(__nothrow) double sin(double  );
    
    
    
    

extern void __use_accurate_range_reduction(void);
    
    

extern __declspec(__nothrow) double tan(double  );
    
    
    
    

extern __declspec(__nothrow) double cosh(double  );
    
    
    
    
extern __declspec(__nothrow) double sinh(double  );
    
    
    
    
    

extern __declspec(__nothrow) __attribute__((const)) double tanh(double  );
    
    

extern __declspec(__nothrow) double exp(double  );
    
    
    
    
    

extern __declspec(__nothrow) double frexp(double  , int *  ) __attribute__((__nonnull__(2)));
    
    
    
    
    
    

extern __declspec(__nothrow) double ldexp(double  , int  );
    
    
    
    
extern __declspec(__nothrow) double log(double  );
    
    
    
    
    
extern __declspec(__nothrow) double log10(double  );
    
    
    
extern __declspec(__nothrow) double modf(double  , double *  ) __attribute__((__nonnull__(2)));
    
    
    
    

extern __declspec(__nothrow) double pow(double  , double  );
    
    
    
    
    
    
extern __declspec(__nothrow) double sqrt(double  );
    
    
    




    inline double _sqrt(double __x) { return sqrt(__x); }


    inline float _sqrtf(float __x) { return __sqrtf(__x); }



    



 

extern __declspec(__nothrow) __attribute__((const)) double ceil(double  );
    
    
extern __declspec(__nothrow) __attribute__((const)) double fabs(double  );
    
    

extern __declspec(__nothrow) __attribute__((const)) double floor(double  );
    
    

extern __declspec(__nothrow) double fmod(double  , double  );
    
    
    
    
    

    









 



extern __declspec(__nothrow) double acosh(double  );
    

 
extern __declspec(__nothrow) double asinh(double  );
    

 
extern __declspec(__nothrow) double atanh(double  );
    

 
extern __declspec(__nothrow) double cbrt(double  );
    

 
inline __declspec(__nothrow) __attribute__((const)) double copysign(double __x, double __y)
    

 
{
    (*(1 + (unsigned *)&(__x))) = ((*(1 + (unsigned *)&(__x))) & 0x7fffffff) | ((*(1 + (unsigned *)&(__y))) & 0x80000000);
    return __x;
}
inline __declspec(__nothrow) __attribute__((const)) float copysignf(float __x, float __y)
    

 
{
    (*(unsigned *)&(__x)) = ((*(unsigned *)&(__x)) & 0x7fffffff) | ((*(unsigned *)&(__y)) & 0x80000000);
    return __x;
}
extern __declspec(__nothrow) double erf(double  );
    

 
extern __declspec(__nothrow) double erfc(double  );
    

 
extern __declspec(__nothrow) double expm1(double  );
    

 



    

 






#line 479 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"


extern __declspec(__nothrow) double hypot(double  , double  );
    




 
extern __declspec(__nothrow) int ilogb(double  );
    

 
extern __declspec(__nothrow) int ilogbf(float  );
    

 
extern __declspec(__nothrow) int ilogbl(long double  );
    

 







    

 





    



 





    



 





    

 





    



 





    



 





    



 





    

 





    

 





    


 

extern __declspec(__nothrow) double lgamma (double  );
    


 
extern __declspec(__nothrow) double log1p(double  );
    

 
extern __declspec(__nothrow) double logb(double  );
    

 
extern __declspec(__nothrow) float logbf(float  );
    

 
extern __declspec(__nothrow) long double logbl(long double  );
    

 
extern __declspec(__nothrow) double nextafter(double  , double  );
    


 
extern __declspec(__nothrow) float nextafterf(float  , float  );
    


 
extern __declspec(__nothrow) long double nextafterl(long double  , long double  );
    


 
extern __declspec(__nothrow) double nexttoward(double  , long double  );
    


 
extern __declspec(__nothrow) float nexttowardf(float  , long double  );
    


 
extern __declspec(__nothrow) long double nexttowardl(long double  , long double  );
    


 
extern __declspec(__nothrow) double remainder(double  , double  );
    

 
extern __declspec(__nothrow) __attribute__((const)) double rint(double  );
    

 
extern __declspec(__nothrow) double scalbln(double  , long int  );
    

 
extern __declspec(__nothrow) float scalblnf(float  , long int  );
    

 
extern __declspec(__nothrow) long double scalblnl(long double  , long int  );
    

 
extern __declspec(__nothrow) double scalbn(double  , int  );
    

 
extern __declspec(__nothrow) float scalbnf(float  , int  );
    

 
extern __declspec(__nothrow) long double scalbnl(long double  , int  );
    

 




    

 



 
extern __declspec(__nothrow) __attribute__((const)) float _fabsf(float);  
inline __declspec(__nothrow) __attribute__((const)) float fabsf(float __f) { return _fabsf(__f); }
extern __declspec(__nothrow) float sinf(float  );
extern __declspec(__nothrow) float cosf(float  );
extern __declspec(__nothrow) float tanf(float  );
extern __declspec(__nothrow) float acosf(float  );
extern __declspec(__nothrow) float asinf(float  );
extern __declspec(__nothrow) float atanf(float  );
extern __declspec(__nothrow) float atan2f(float  , float  );
extern __declspec(__nothrow) float sinhf(float  );
extern __declspec(__nothrow) float coshf(float  );
extern __declspec(__nothrow) float tanhf(float  );
extern __declspec(__nothrow) float expf(float  );
extern __declspec(__nothrow) float logf(float  );
extern __declspec(__nothrow) float log10f(float  );
extern __declspec(__nothrow) float powf(float  , float  );
extern __declspec(__nothrow) float sqrtf(float  );
extern __declspec(__nothrow) float ldexpf(float  , int  );
extern __declspec(__nothrow) float frexpf(float  , int *  ) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) __attribute__((const)) float ceilf(float  );
extern __declspec(__nothrow) __attribute__((const)) float floorf(float  );
extern __declspec(__nothrow) float fmodf(float  , float  );
extern __declspec(__nothrow) float modff(float  , float *  ) __attribute__((__nonnull__(2)));

 
 













 
__declspec(__nothrow) long double acosl(long double );
__declspec(__nothrow) long double asinl(long double );
__declspec(__nothrow) long double atanl(long double );
__declspec(__nothrow) long double atan2l(long double , long double );
__declspec(__nothrow) long double ceill(long double );
__declspec(__nothrow) long double cosl(long double );
__declspec(__nothrow) long double coshl(long double );
__declspec(__nothrow) long double expl(long double );
__declspec(__nothrow) long double fabsl(long double );
__declspec(__nothrow) long double floorl(long double );
__declspec(__nothrow) long double fmodl(long double , long double );
__declspec(__nothrow) long double frexpl(long double , int* ) __attribute__((__nonnull__(2)));
__declspec(__nothrow) long double ldexpl(long double , int );
__declspec(__nothrow) long double logl(long double );
__declspec(__nothrow) long double log10l(long double );
__declspec(__nothrow) long double modfl(long double  , long double *  ) __attribute__((__nonnull__(2)));
__declspec(__nothrow) long double powl(long double , long double );
__declspec(__nothrow) long double sinl(long double );
__declspec(__nothrow) long double sinhl(long double );
__declspec(__nothrow) long double sqrtl(long double );
__declspec(__nothrow) long double tanl(long double );
__declspec(__nothrow) long double tanhl(long double );





 
extern __declspec(__nothrow) float acoshf(float  );
__declspec(__nothrow) long double acoshl(long double );
extern __declspec(__nothrow) float asinhf(float  );
__declspec(__nothrow) long double asinhl(long double );
extern __declspec(__nothrow) float atanhf(float  );
__declspec(__nothrow) long double atanhl(long double );
__declspec(__nothrow) long double copysignl(long double , long double );
extern __declspec(__nothrow) float cbrtf(float  );
__declspec(__nothrow) long double cbrtl(long double );
extern __declspec(__nothrow) float erff(float  );
__declspec(__nothrow) long double erfl(long double );
extern __declspec(__nothrow) float erfcf(float  );
__declspec(__nothrow) long double erfcl(long double );
extern __declspec(__nothrow) float expm1f(float  );
__declspec(__nothrow) long double expm1l(long double );
extern __declspec(__nothrow) float log1pf(float  );
__declspec(__nothrow) long double log1pl(long double );
extern __declspec(__nothrow) float hypotf(float  , float  );
__declspec(__nothrow) long double hypotl(long double , long double );
extern __declspec(__nothrow) float lgammaf(float  );
__declspec(__nothrow) long double lgammal(long double );
extern __declspec(__nothrow) float remainderf(float  , float  );
__declspec(__nothrow) long double remainderl(long double , long double );
extern __declspec(__nothrow) float rintf(float  );
__declspec(__nothrow) long double rintl(long double );






 
extern __declspec(__nothrow) double exp2(double  );  
extern __declspec(__nothrow) float exp2f(float  );
__declspec(__nothrow) long double exp2l(long double );
extern __declspec(__nothrow) double fdim(double  , double  );
extern __declspec(__nothrow) float fdimf(float  , float  );
__declspec(__nothrow) long double fdiml(long double , long double );
#line 803 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"
extern __declspec(__nothrow) double fma(double  , double  , double  );
extern __declspec(__nothrow) float fmaf(float  , float  , float  );

inline __declspec(__nothrow) long double fmal(long double __x, long double __y, long double __z)     { return (long double)fma((double)__x, (double)__y, (double)__z); }


extern __declspec(__nothrow) __attribute__((const)) double fmax(double  , double  );
extern __declspec(__nothrow) __attribute__((const)) float fmaxf(float  , float  );
__declspec(__nothrow) long double fmaxl(long double , long double );
extern __declspec(__nothrow) __attribute__((const)) double fmin(double  , double  );
extern __declspec(__nothrow) __attribute__((const)) float fminf(float  , float  );
__declspec(__nothrow) long double fminl(long double , long double );
extern __declspec(__nothrow) double log2(double  );  
extern __declspec(__nothrow) float log2f(float  );
__declspec(__nothrow) long double log2l(long double );
extern __declspec(__nothrow) long lrint(double  );
extern __declspec(__nothrow) long lrintf(float  );

inline __declspec(__nothrow) long lrintl(long double __x)     { return lrint((double)__x); }


extern __declspec(__nothrow) long long llrint(double  );
extern __declspec(__nothrow) long long llrintf(float  );

inline __declspec(__nothrow) long long llrintl(long double __x)     { return llrint((double)__x); }


extern __declspec(__nothrow) long lround(double  );
extern __declspec(__nothrow) long lroundf(float  );

inline __declspec(__nothrow) long lroundl(long double __x)     { return lround((double)__x); }


extern __declspec(__nothrow) long long llround(double  );
extern __declspec(__nothrow) long long llroundf(float  );

inline __declspec(__nothrow) long long llroundl(long double __x)     { return llround((double)__x); }


extern __declspec(__nothrow) __attribute__((const)) double nan(const char * );
extern __declspec(__nothrow) __attribute__((const)) float nanf(const char * );

inline __declspec(__nothrow) __attribute__((const)) long double nanl(const char *__t)     { return (long double)nan(__t); }
#line 856 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"
extern __declspec(__nothrow) __attribute__((const)) double nearbyint(double  );
extern __declspec(__nothrow) __attribute__((const)) float nearbyintf(float  );
__declspec(__nothrow) long double nearbyintl(long double );
extern  double remquo(double  , double  , int * );
extern  float remquof(float  , float  , int * );

inline long double remquol(long double __x, long double __y, int *__q)     { return (long double)remquo((double)__x, (double)__y, __q); }


extern __declspec(__nothrow) __attribute__((const)) double round(double  );
extern __declspec(__nothrow) __attribute__((const)) float roundf(float  );
__declspec(__nothrow) long double roundl(long double );
extern __declspec(__nothrow) double tgamma(double  );  
extern __declspec(__nothrow) float tgammaf(float  );
__declspec(__nothrow) long double tgammal(long double );
extern __declspec(__nothrow) __attribute__((const)) double trunc(double  );
extern __declspec(__nothrow) __attribute__((const)) float truncf(float  );
__declspec(__nothrow) long double truncl(long double );






#line 896 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"

#line 1087 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"











#line 1317 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\math.h"





 
#line 5 "..\\LCD0.c"
#line 1 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
 
 
 




 
 



 






   














  


 








#line 54 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"


  



    typedef unsigned int size_t;    
#line 70 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"






    



    typedef unsigned short wchar_t;  
#line 91 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"

typedef struct div_t { int quot, rem; } div_t;
    
typedef struct ldiv_t { long int quot, rem; } ldiv_t;
    

typedef struct lldiv_t { long long quot, rem; } lldiv_t;
    


#line 112 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
   



 

   




 
#line 131 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
   


 
extern __declspec(__nothrow) int __aeabi_MB_CUR_MAX(void);

   




 

   




 




extern __declspec(__nothrow) double atof(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int atoi(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) long int atol(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) long long atoll(const char *  ) __attribute__((__nonnull__(1)));
   



 


extern __declspec(__nothrow) double strtod(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

















 

extern __declspec(__nothrow) float strtof(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) long double strtold(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

 

extern __declspec(__nothrow) long int strtol(const char * __restrict  ,
                        char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   



























 
extern __declspec(__nothrow) unsigned long int strtoul(const char * __restrict  ,
                                       char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   


























 

 
extern __declspec(__nothrow) long long strtoll(const char * __restrict  ,
                                  char ** __restrict  , int  )
                          __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) unsigned long long strtoull(const char * __restrict  ,
                                            char ** __restrict  , int  )
                                   __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) int rand(void);
   







 
extern __declspec(__nothrow) void srand(unsigned int  );
   






 

struct _rand_state { int __x[57]; };
extern __declspec(__nothrow) int _rand_r(struct _rand_state *);
extern __declspec(__nothrow) void _srand_r(struct _rand_state *, unsigned int);
struct _ANSI_rand_state { int __x[1]; };
extern __declspec(__nothrow) int _ANSI_rand_r(struct _ANSI_rand_state *);
extern __declspec(__nothrow) void _ANSI_srand_r(struct _ANSI_rand_state *, unsigned int);
   


 

extern __declspec(__nothrow) void *calloc(size_t  , size_t  );
   



 
extern __declspec(__nothrow) void free(void *  );
   





 
extern __declspec(__nothrow) void *malloc(size_t  );
   



 
extern __declspec(__nothrow) void *realloc(void *  , size_t  );
   













 

extern __declspec(__nothrow) int posix_memalign(void **  , size_t  , size_t  );
   









 

typedef int (*__heapprt)(void *, char const *, ...);
extern __declspec(__nothrow) void __heapstats(int (*  )(void *  ,
                                           char const *  , ...),
                        void *  ) __attribute__((__nonnull__(1)));
   










 
extern __declspec(__nothrow) int __heapvalid(int (*  )(void *  ,
                                           char const *  , ...),
                       void *  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) __declspec(__noreturn) void abort(void);
   







 

extern __declspec(__nothrow) int atexit(void (*  )(void)) __attribute__((__nonnull__(1)));
   




 
#line 436 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"


extern __declspec(__nothrow) __declspec(__noreturn) void exit(int  );
   












 

extern __declspec(__nothrow) __declspec(__noreturn) void _Exit(int  );
   







      

extern __declspec(__nothrow) char *getenv(const char *  ) __attribute__((__nonnull__(1)));
   









 

extern __declspec(__nothrow) int  system(const char *  );
   









 

extern  void *bsearch(const void *  , const void *  ,
              size_t  , size_t  ,
              int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,2,5)));
   












 
#line 524 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"


extern  void qsort(void *  , size_t  , size_t  ,
           int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,4)));
   









 

#line 553 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"

extern __declspec(__nothrow) __attribute__((const)) int abs(int  );
   



 

extern __declspec(__nothrow) __attribute__((const)) div_t div(int  , int  );
   









 
extern __declspec(__nothrow) __attribute__((const)) long int labs(long int  );
   



 




extern __declspec(__nothrow) __attribute__((const)) ldiv_t ldiv(long int  , long int  );
   











 







extern __declspec(__nothrow) __attribute__((const)) long long llabs(long long  );
   



 




extern __declspec(__nothrow) __attribute__((const)) lldiv_t lldiv(long long  , long long  );
   











 
#line 634 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"




 
typedef struct __sdiv32by16 { int quot, rem; } __sdiv32by16;
typedef struct __udiv32by16 { unsigned int quot, rem; } __udiv32by16;
    
typedef struct __sdiv64by32 { int rem, quot; } __sdiv64by32;

__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __sdiv32by16 __rt_sdiv32by16(
     int  ,
     short int  );
   

 
__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __udiv32by16 __rt_udiv32by16(
     unsigned int  ,
     unsigned short  );
   

 
__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __sdiv64by32 __rt_sdiv64by32(
     int  , unsigned int  ,
     int  );
   

 




 
extern __declspec(__nothrow) unsigned int __fp_status(unsigned int  , unsigned int  );
   







 























 
extern __declspec(__nothrow) int mblen(const char *  , size_t  );
   












 
extern __declspec(__nothrow) int mbtowc(wchar_t * __restrict  ,
                   const char * __restrict  , size_t  );
   















 
extern __declspec(__nothrow) int wctomb(char *  , wchar_t  );
   













 





 
extern __declspec(__nothrow) size_t mbstowcs(wchar_t * __restrict  ,
                      const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 
extern __declspec(__nothrow) size_t wcstombs(char * __restrict  ,
                      const wchar_t * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 

extern __declspec(__nothrow) void __use_realtime_heap(void);
extern __declspec(__nothrow) void __use_realtime_division(void);
extern __declspec(__nothrow) void __use_two_region_memory(void);
extern __declspec(__nothrow) void __use_no_heap(void);
extern __declspec(__nothrow) void __use_no_heap_region(void);

extern __declspec(__nothrow) char const *__C_library_version_string(void);
extern __declspec(__nothrow) int __C_library_version_number(void);











#line 892 "D:\\MDK518\\keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"





 
#line 6 "..\\LCD0.c"

uint8_t CCLK;    
uint8_t MCLK;    
uint8_t SCLK;    






 

void LCD_CmdWrite(uint8_t cmd)
{	
	*(volatile uint16_t*) (((uint32_t)0x60000000))= (cmd);
}

void LCD_DataWrite(uint8_t data)
{
	*(volatile uint16_t*) (((uint32_t)0x60040004))= (data);
}

void LCD_DataWrite_Pixel(uint16_t data)
{
	*(volatile uint16_t*) (((uint32_t)0x60040004))= (data);
}


uint8_t LCD_StatusRead(void)
{
	uint8_t temp = 0;
	temp = *(volatile uint16_t*)(((uint32_t)0x60000000));
	return temp;
}

uint16_t LCD_DataRead(void)
{
	uint16_t temp = 0;	
	temp =  *(volatile uint16_t*)(((uint32_t)0x60040004));
	return temp;
}
void Delay_us(uint16_t time)
{    
   uint16_t i=0;  
   while(time--)
   {
      i=12;        
      while(i--) ;    
   }
}

void Delay_ms(uint16_t time)
{    
   uint16_t i=0;  
   while(time--)
   {
      i=12000;    
      while(i--) ;    
   }
}





void LT768_HW_Reset(void)
{	
	
	(*((volatile uint32_t *)(((((uint32_t)0x40000000) + 0x04800UL)+(0x40*(3))) + ((14)<<2))))=0;
	Delay_ms(100);				   
  (*((volatile uint32_t *)(((((uint32_t)0x40000000) + 0x04800UL)+(0x40*(3))) + ((14)<<2))))=1;		 	 
  Delay_ms(100);	
}


void System_Check_Temp(void)
{
	uint8_t i=0;
	uint8_t temp=0;
	uint8_t system_ok=0;
	do
	{
		if((LCD_StatusRead()&0x02)==0x00)    
		{
			Delay_ms(1);                  
			LCD_CmdWrite(0x01);
			Delay_ms(1);                  
			temp =LCD_DataRead();
			if((temp & 0x80)==0x80)       
			{
				system_ok=1;
				i=0;
			}
			else
			{
				Delay_ms(1); 
				LCD_CmdWrite(0x01);
				Delay_ms(1); 
				LCD_DataWrite(0x80);
			}
		}
		else
		{
			system_ok=0;
			i++;
		}
		if(system_ok==0 && i==5)
		{
			LT768_HW_Reset(); 
			i=0;
		}
	}while(system_ok==0);
}

void LT768_PLL_Initial(void) 
{    
	uint32_t  temp = 0,temp1 =0 ;
	
	uint16_t lpllOD_sclk, lpllOD_cclk, lpllOD_mclk;
	uint16_t lpllR_sclk, lpllR_cclk, lpllR_mclk;
	uint16_t lpllN_sclk, lpllN_cclk, lpllN_mclk;
	
	temp = (160 + 160 + 120 + 1024) * (23 + 12 + 10+600) * 60;   
	
	temp1=(temp%1000000)/100000;
	if(temp1>=5) 
		 temp = temp / 1000000 + 1;
	else temp = temp / 1000000;
	SCLK = temp;
	temp = temp * 3;
	MCLK = temp;
	CCLK = temp;
	
	if(CCLK > 100)	CCLK = 100;
	if(MCLK > 100)	MCLK = 100;
	if(SCLK > 65)		SCLK = 65;

	lpllOD_sclk = 3;
	lpllOD_cclk = 2;
	lpllOD_mclk = 2;
	lpllR_sclk  = 5;
	lpllR_cclk  = 5;
	lpllR_mclk  = 5;
	lpllN_mclk  = MCLK;      
	lpllN_cclk  = CCLK;    
	lpllN_sclk  = 2*SCLK;    
      
	LCD_CmdWrite(0x05);
	LCD_DataWrite((lpllOD_sclk<<6) | (lpllR_sclk<<1) | ((lpllN_sclk>>8)&0x1));
	LCD_CmdWrite(0x07);
	LCD_DataWrite((lpllOD_mclk<<6) | (lpllR_mclk<<1) | ((lpllN_mclk>>8)&0x1));
	LCD_CmdWrite(0x09);
	LCD_DataWrite((lpllOD_cclk<<6) | (lpllR_cclk<<1) | ((lpllN_cclk>>8)&0x1));

	LCD_CmdWrite(0x06);
	LCD_DataWrite(lpllN_sclk);
	LCD_CmdWrite(0x08);
	LCD_DataWrite(lpllN_mclk);
	LCD_CmdWrite(0x0a);
	LCD_DataWrite(lpllN_cclk);
      
	LCD_CmdWrite(0x00);
	Delay_us(1);
	LCD_DataWrite(0x80);

	Delay_ms(1);	
}


void LT768_SDRAM_initail(uint8_t mclk)
{
	uint16_t sdram_itv;
	
	LCD_RegisterWrite(0xe0,0x29);      
	LCD_RegisterWrite(0xe1,0x03);	
  sdram_itv = (64000000 / 8192) / (1000/mclk) ;
  sdram_itv-=2;

	LCD_RegisterWrite(0xe2,sdram_itv);
	LCD_RegisterWrite(0xe3,sdram_itv >>8);
	LCD_RegisterWrite(0xe4,0x01);
	Check_SDRAM_Ready();
	Delay_ms(1);
}


void Set_LCD_Panel(void)
{
	
	TFT_16bit();	
	
	
	
	Host_Bus_16bit();	
      
	
	RGB_16b_16bpp();
	
	MemWrite_Left_Right_Top_Down();	
	
      
	
	Graphic_Mode();
	Memory_Select_SDRAM();
     
	PCLK_Falling();	       	
	
	
	VSCAN_T_to_B();	        
	
	
	PDATA_Set_RGB();        
	
	
	
	
	

	HSYNC_Low_Active();     
	
	
	VSYNC_Low_Active();     
	
	
	DE_High_Active();       
	
 
	LCD_HorizontalWidth_VerticalHeight(1024 ,600);	
	LCD_Horizontal_Non_Display(160);	                            
	LCD_HSYNC_Start_Position(160);	                              
	LCD_HSYNC_Pulse_Width(120);		                            	
	LCD_Vertical_Non_Display(23);	                                
	LCD_VSYNC_Start_Position(12);	                              
	LCD_VSYNC_Pulse_Width(10);		                            	

	Memory_XY_Mode();	
	Memory_16bpp_Mode();	
}

void LT768_initial(void)
{
  LT768_PLL_Initial();
  LT768_SDRAM_initail(MCLK);
  Set_LCD_Panel();
}


void LT768_Init(void)
{
	Delay_ms(100);                    
	LT768_HW_Reset();                 
	System_Check_Temp();	            
	Delay_ms(100);
	while(LCD_StatusRead()&0x02);	    
	LT768_initial();
}



void LT768_PWM0_Init
(
 uint8_t on_off                       
,uint8_t Clock_Divided                
,uint8_t Prescalar                    
,uint16_t Count_Buffer                
,uint16_t Compare_Buffer              
)
{
	 Select_PWM0();
   Set_PWM_Prescaler_1_to_256(Prescalar);

	if(Clock_Divided ==0)	Select_PWM0_Clock_Divided_By_1();
	if(Clock_Divided ==1)	Select_PWM0_Clock_Divided_By_2();
	if(Clock_Divided ==2)	Select_PWM0_Clock_Divided_By_4();
	if(Clock_Divided ==3) Select_PWM0_Clock_Divided_By_8();

	Set_Timer0_Count_Buffer(Count_Buffer);  
	Set_Timer0_Compare_Buffer(Compare_Buffer);	
		
	if (on_off == 1)	Start_PWM0(); 
	if (on_off == 0)	Stop_PWM0();
}


void LT768_PWM0_Duty(uint16_t Compare_Buffer)
{
	Set_Timer0_Compare_Buffer(Compare_Buffer);
}



void LT768_PWM1_Init
(
 uint8_t on_off                       
,uint8_t Clock_Divided                
,uint8_t Prescalar                    
,uint16_t Count_Buffer                
,uint16_t Compare_Buffer              
)
{
	Select_PWM1();
	Set_PWM_Prescaler_1_to_256(Prescalar);
 
	if(Clock_Divided ==0)	Select_PWM1_Clock_Divided_By_1();
	if(Clock_Divided ==1)	Select_PWM1_Clock_Divided_By_2();
	if(Clock_Divided ==2) Select_PWM1_Clock_Divided_By_4();
	if(Clock_Divided ==3)	Select_PWM1_Clock_Divided_By_8();

	Set_Timer1_Count_Buffer(Count_Buffer); 
	Set_Timer1_Compare_Buffer(Compare_Buffer); 

	if (on_off == 1)	Start_PWM1(); 
	if (on_off == 0)	Stop_PWM1();
}


void LT768_PWM1_Duty(uint16_t Compare_Buffer)
{
	Set_Timer1_Compare_Buffer(Compare_Buffer);
}









 
void LCD_RegisterWrite(uint8_t Cmd,uint8_t Data)
{
	LCD_CmdWrite(Cmd);
	LCD_DataWrite(Data);
}  

uint8_t LCD_RegisterRead(uint8_t Cmd)
{
	uint8_t temp;
	
	LCD_CmdWrite(Cmd);
	temp=LCD_DataRead();
	return temp;
}

 
 
 

void Check_Mem_WR_FIFO_not_Full(void)
{

 
	do
	{
		
	}
	while( LCD_StatusRead()&0x80 );
}

void Check_2D_Busy(void)
{
	do
	{
		
	}
	while( LCD_StatusRead()&0x08 );
}
void Check_SDRAM_Ready(void)
{

 	
	uint8_t temp; 	
	do
	{
		temp=LCD_StatusRead();
	}
	while( (temp&0x04) == 0x00 );
}
void Check_Mem_WR_FIFO_Empty(void)
{

 	
	do
	{
		
	}
	while( (LCD_StatusRead()&0x40) == 0x00 );
}
void Check_Busy_Draw(void)
{
	uint8_t temp;
	do
	{
		temp=LCD_StatusRead();
	}
	while(temp&0x08);

}



void LT768_SW_Reset(void)
{
	uint8_t temp;

	LCD_CmdWrite(0x00);
	temp = LCD_DataRead();
	temp |= 0x01;
	LCD_DataWrite(temp);

    do
    {
	    temp = LCD_DataRead();
    }
    while( temp&0x01 );
}



void TFT_16bit(void)
{



 
	uint8_t temp;
	LCD_CmdWrite(0x01);
	temp = LCD_DataRead();
	temp |= 0x10;
    temp &= 0xf7;
	LCD_DataWrite(temp);  
}


void Enable_SFlash_SPI(void)
{


 
	uint8_t temp;
	LCD_CmdWrite(0x01);
	temp = LCD_DataRead();
	temp |= 0x02;
	LCD_DataWrite(temp);     
}

void Disable_SFlash_SPI(void)
{


 
	uint8_t temp;
	LCD_CmdWrite(0x01);
	temp = LCD_DataRead();
	temp &= 0xfd;
	LCD_DataWrite(temp);     
}
void Host_Bus_16bit(void)
{


 
	uint8_t temp;
	LCD_CmdWrite(0x01);
	temp = LCD_DataRead();
	temp |= 0x01;
	LCD_DataWrite(temp);
}



void RGB_16b_16bpp(void)
{
	uint8_t temp;
	LCD_CmdWrite(0x02);
	temp = LCD_DataRead();
	temp &= 0x7f;
	temp |= 0x40;
	LCD_DataWrite(temp);
}

void MemWrite_Left_Right_Top_Down(void)
{
	uint8_t temp;
	LCD_CmdWrite(0x02);
	temp = LCD_DataRead();
	temp &= 0xfb;
	temp &= 0xfd;
	LCD_DataWrite(temp);
}

void Graphic_Mode(void)
{
	uint8_t temp;
	LCD_CmdWrite(0x03);
	temp = LCD_DataRead();
    temp &= 0xfb;
	LCD_DataWrite(temp);
}
void Text_Mode(void)
{
	uint8_t temp;
	LCD_CmdWrite(0x03);
	temp = LCD_DataRead();
    temp |= 0x04;
	LCD_DataWrite(temp);
}
void Memory_Select_SDRAM(void)
{
	uint8_t temp;
	LCD_CmdWrite(0x03);
	temp = LCD_DataRead();
    temp &= 0xfd;
    temp &= 0xfe;	
	LCD_DataWrite(temp);
}
void Memory_Select_Graphic_Cursor_RAM(void)
{
	unsigned char temp;
	LCD_CmdWrite(0x03);
	temp = LCD_DataRead();
    temp |= 0x02;
    temp &= 0xfe;
	LCD_DataWrite(temp);
}











void Select_Main_Window_16bpp(void)
{





 
	uint8_t temp;
	LCD_CmdWrite(0x10);
	temp = LCD_DataRead();
    temp &= 0xf7;
    temp |= 0x04;
	LCD_DataWrite(temp);
}

void Enable_PIP1(void)
{





 
	unsigned char temp;
	LCD_CmdWrite(0x10);
	temp = LCD_DataRead();
    temp |= 0x80;
	LCD_DataWrite(temp);
}
void Disable_PIP1(void)
{





 
	unsigned char temp;
	LCD_CmdWrite(0x10);
	temp = LCD_DataRead();
    temp &= 0x7f;
	LCD_DataWrite(temp);
}
void Enable_PIP2(void)
{





 
	unsigned char temp;
	LCD_CmdWrite(0x10);
	temp = LCD_DataRead();
    temp |= 0x40;
	LCD_DataWrite(temp);
}
void Disable_PIP2(void)
{





 
	unsigned char temp;
	LCD_CmdWrite(0x10);
	temp = LCD_DataRead();
    temp &= 0xbf;
	LCD_DataWrite(temp);
}
void Select_PIP1_Parameter(void)
{



 
	unsigned char temp;
	LCD_CmdWrite(0x10);
	temp = LCD_DataRead();
    temp &= 0xef;
	LCD_DataWrite(temp);
}
void Select_PIP2_Parameter(void)
{



 
	unsigned char temp;
	LCD_CmdWrite(0x10);
	temp = LCD_DataRead();
    temp |= 0x10;
	LCD_DataWrite(temp);
}

void Select_PIP2_Window_8bpp(void)
{





 
	unsigned char temp;
	LCD_CmdWrite(0x11);
	temp = LCD_DataRead();
    temp &= 0xfd;
    temp &= 0xfe;
	LCD_DataWrite(temp);
}
void Select_PIP2_Window_16bpp(void)
{





 
	unsigned char temp;
	LCD_CmdWrite(0x11);
	temp = LCD_DataRead();
    temp &= 0xfd;
    temp |= 0x01;
	LCD_DataWrite(temp);
}
void Select_PIP2_Window_24bpp(void)
{





 
	unsigned char temp;
	LCD_CmdWrite(0x11);
	temp = LCD_DataRead();
    temp |= 0x02;
    temp &= 0xfe;
	LCD_DataWrite(temp);
}
void Select_PIP1_Window_8bpp(void)
{





 
	unsigned char temp;
	LCD_CmdWrite(0x11);
	temp = LCD_DataRead();
    temp &= 0xf7;
    temp &= 0xfb;
	LCD_DataWrite(temp);
}
void Select_PIP1_Window_16bpp(void)
{





 
	unsigned char temp;
	LCD_CmdWrite(0x11);
	temp = LCD_DataRead();
    temp &= 0xf7;
    temp |= 0x04;
	LCD_DataWrite(temp);
}
void Select_PIP1_Window_24bpp(void)
{





 
	unsigned char temp;
	LCD_CmdWrite(0x11);
	temp = LCD_DataRead();
    temp |= 0x08;
    temp &= 0xfb;
	LCD_DataWrite(temp);
}



void PCLK_Falling(void)
{




 
	uint8_t temp;
	LCD_CmdWrite(0x12);
	temp = LCD_DataRead();
    temp |= 0x80;
	LCD_DataWrite(temp);
}
void Display_ON(void)
{




 
	uint8_t temp;
	
	LCD_CmdWrite(0x12);
	temp = LCD_DataRead();
	temp |= 0x40;
	LCD_DataWrite(temp);
}
void Display_OFF(void)
{




 
	unsigned char temp;
	
	LCD_CmdWrite(0x12);
	temp = LCD_DataRead();
	temp &= 0xbf;
	LCD_DataWrite(temp);
}
void Color_Bar_ON(void)
{




 
	unsigned char temp;
	
	LCD_CmdWrite(0x12);
	temp = LCD_DataRead();
	temp |= 0x20;
	LCD_DataWrite(temp);
}
void Color_Bar_OFF(void)
{




 
	unsigned char temp;
	
	LCD_CmdWrite(0x12);
	temp = LCD_DataRead();
	temp &= 0xdf;
	LCD_DataWrite(temp);
}
void VSCAN_T_to_B(void)
{





 
	uint8_t temp;
	
	LCD_CmdWrite(0x12);
	temp = LCD_DataRead();
	temp &= 0xf7;
	LCD_DataWrite(temp);
}
void PDATA_Set_RGB(void)
{








 
	uint8_t temp;
	
	LCD_CmdWrite(0x12);
	temp = LCD_DataRead();
  temp &=0xf8;
	temp |=0x05;
	LCD_DataWrite(temp);
}


void HSYNC_Low_Active(void)
{




 
	uint8_t temp;
	
	LCD_CmdWrite(0x13);
	temp = LCD_DataRead();
	temp &= 0x7f;
	LCD_DataWrite(temp);
}

void VSYNC_Low_Active(void)
{




 
	uint8_t temp;
	
	LCD_CmdWrite(0x13);
	temp = LCD_DataRead();
	temp &= 0xbf;	
	LCD_DataWrite(temp);
}

void DE_High_Active(void)
{




 
	uint8_t temp;
	
	LCD_CmdWrite(0x13);
	temp = LCD_DataRead();
	temp &= 0xdf;
	LCD_DataWrite(temp);
}



void LCD_HorizontalWidth_VerticalHeight(uint16_t WX,uint16_t HY)
{











 
	uint8_t temp;
	if(WX<8)
    {
	LCD_CmdWrite(0x14);
	LCD_DataWrite(0x00);
    
	LCD_CmdWrite(0x15);
	LCD_DataWrite(WX);
    
    temp=HY-1;
	LCD_CmdWrite(0x1A);
	LCD_DataWrite(temp);
	    
	temp=(HY-1)>>8;
	LCD_CmdWrite(0x1B);
	LCD_DataWrite(temp);
	}
	else
	{
    temp=(WX/8)-1;
	LCD_CmdWrite(0x14);
	LCD_DataWrite(temp);
    
    temp=WX%8;
	LCD_CmdWrite(0x15);
	LCD_DataWrite(temp);
    
    temp=HY-1;
	LCD_CmdWrite(0x1A);
	LCD_DataWrite(temp);
	    
	temp=(HY-1)>>8;
	LCD_CmdWrite(0x1B);
	LCD_DataWrite(temp);
	}
}

void LCD_Horizontal_Non_Display(uint16_t WX)
{











 
	uint8_t temp;
	if(WX<8)
	{
	LCD_CmdWrite(0x16);
	LCD_DataWrite(0x00);
    
	LCD_CmdWrite(0x17);
	LCD_DataWrite(WX);
	}
	else
	{
    temp=(WX/8)-1;
	LCD_CmdWrite(0x16);
	LCD_DataWrite(temp);
    
    temp=WX%8;
	LCD_CmdWrite(0x17);
	LCD_DataWrite(temp);
	}	
}

void LCD_HSYNC_Start_Position(uint16_t WX)
{






 
	uint8_t temp;
	if(WX<8)
	{
	LCD_CmdWrite(0x18);
	LCD_DataWrite(0x00);
	}
	else
	{
    temp=(WX/8)-1;
	LCD_CmdWrite(0x18);
	LCD_DataWrite(temp);	
	}
}

void LCD_HSYNC_Pulse_Width(uint16_t WX)
{




 
	uint8_t temp;
	if(WX<8)
	{
	LCD_CmdWrite(0x19);
	LCD_DataWrite(0x00);
	}
	else
	{
    temp=(WX/8)-1;
	LCD_CmdWrite(0x19);
	LCD_DataWrite(temp);	
	}
}

void LCD_Vertical_Non_Display(uint16_t HY)
{






 
	uint8_t temp;
    temp=HY-1;
	LCD_CmdWrite(0x1C);
	LCD_DataWrite(temp);

	LCD_CmdWrite(0x1D);
	LCD_DataWrite(temp>>8);
}

void LCD_VSYNC_Start_Position(uint16_t HY)
{




 
	uint8_t temp;
    temp=HY-1;
	LCD_CmdWrite(0x1E);
	LCD_DataWrite(temp);
}

void LCD_VSYNC_Pulse_Width(uint16_t HY)
{




 
	uint8_t temp;
    temp=HY-1;
	LCD_CmdWrite(0x1F);
	LCD_DataWrite(temp);
}

void Main_Image_Start_Address(unsigned long Addr)	
{





 
	LCD_RegisterWrite(0x20,Addr);
	LCD_RegisterWrite(0x21,Addr>>8);
	LCD_RegisterWrite(0x22,Addr>>16);
	LCD_RegisterWrite(0x23,Addr>>24);
}

void Main_Image_Width(uint16_t WX)	
{






 
	LCD_RegisterWrite(0x24,WX);
	LCD_RegisterWrite(0x25,WX>>8);
}

void Main_Window_Start_XY(uint16_t WX,uint16_t HY)	
{













 
	LCD_RegisterWrite(0x26,WX);
	LCD_RegisterWrite(0x27,WX>>8);

	LCD_RegisterWrite(0x28,HY);
	LCD_RegisterWrite(0x29,HY>>8);
}

void PIP_Display_Start_XY(unsigned short WX,unsigned short HY)	
{

















 
	LCD_RegisterWrite(0x2A,WX);
	LCD_RegisterWrite(0x2B,WX>>8);
	
	LCD_RegisterWrite(0x2C,HY);
	LCD_RegisterWrite(0x2D,HY>>8);
}

void PIP_Image_Start_Address(unsigned long Addr)	
{





 
	LCD_RegisterWrite(0x2E,Addr);
	LCD_RegisterWrite(0x2F,Addr>>8);
	LCD_RegisterWrite(0x30,Addr>>16);
	LCD_RegisterWrite(0x31,Addr>>24);
}

void PIP_Image_Width(unsigned short WX)	
{









 
	LCD_RegisterWrite(0x32,WX);
	LCD_RegisterWrite(0x33,WX>>8);
}

void PIP_Window_Image_Start_XY(unsigned short WX,unsigned short HY)	
{

















 
	LCD_RegisterWrite(0x34,WX);
	LCD_RegisterWrite(0x35,WX>>8);
	
	LCD_RegisterWrite(0x36,HY);
	LCD_RegisterWrite(0x37,HY>>8);
}

void PIP_Window_Width_Height(unsigned short WX,unsigned short HY)	
{















 
	LCD_RegisterWrite(0x38,WX);
	LCD_RegisterWrite(0x39,WX>>8);
	
	LCD_RegisterWrite(0x3A,HY);
	LCD_RegisterWrite(0x3B,HY>>8);
}


void Enable_Graphic_Cursor(void)	
{




 
	unsigned char temp;
	
	LCD_CmdWrite(0x3C);
	temp = LCD_DataRead();
	temp |= 0x10;
	LCD_DataWrite(temp);
}
void Disable_Graphic_Cursor(void)	
{




 
	unsigned char temp;
	
	LCD_CmdWrite(0x3C);
	temp = LCD_DataRead();
	temp &= 0xef;
	LCD_DataWrite(temp);
}

void Select_Graphic_Cursor_1(void)	
{







 
	unsigned char temp;
	
	LCD_CmdWrite(0x3C);
	temp = LCD_DataRead();
	temp &= 0xf7;
	temp &= 0xfb;
	LCD_DataWrite(temp);
}
void Select_Graphic_Cursor_2(void)	
{







 
	unsigned char temp;
	
	LCD_CmdWrite(0x3C);
	temp = LCD_DataRead();
	temp &= 0xf7;
	temp |= 0x04;
	LCD_DataWrite(temp);
}
void Select_Graphic_Cursor_3(void)	
{







 
	unsigned char temp;
	
	LCD_CmdWrite(0x3C);
	temp = LCD_DataRead();
	temp |= 0x08;
	temp &= 0xfb;
	LCD_DataWrite(temp);
}
void Select_Graphic_Cursor_4(void)	
{







 
	unsigned char temp;
	
	LCD_CmdWrite(0x3C);
	temp = LCD_DataRead();
	temp |= 0x08;
	temp |= 0x04;
	LCD_DataWrite(temp);
}

void Enable_Text_Cursor(void)	
{






 
	unsigned char temp;
	
	LCD_CmdWrite(0x3C);
	temp = LCD_DataRead();
	temp |= 0x02;
	LCD_DataWrite(temp);
}
void Disable_Text_Cursor(void)	
{






 
	unsigned char temp;
	
	LCD_CmdWrite(0x3C);
	temp = LCD_DataRead();
	temp &= 0xfd;
	LCD_DataWrite(temp);
}

void Enable_Text_Cursor_Blinking(void)	
{




 
	unsigned char temp;
	
	LCD_CmdWrite(0x3C);
	temp = LCD_DataRead();
	temp |= 0x01;
	LCD_DataWrite(temp);
}
void Disable_Text_Cursor_Blinking(void)	
{




 
	unsigned char temp;
	
	LCD_CmdWrite(0x3C);
	temp = LCD_DataRead();
	temp &= 0xfe;
	LCD_DataWrite(temp);
}

void Blinking_Time_Frames(unsigned char temp)	
{







 
	LCD_CmdWrite(0x3D);
	LCD_DataWrite(temp);
}

void Text_Cursor_H_V(unsigned short WX,unsigned short HY)
{













 
	LCD_CmdWrite(0x3E);
	LCD_DataWrite(WX);
	LCD_CmdWrite(0x3F);
	LCD_DataWrite(HY);
}

void Graphic_Cursor_XY(unsigned short WX,unsigned short HY)
{






 	
	LCD_RegisterWrite(0x40,WX);
	LCD_RegisterWrite(0x41,WX>>8);

	LCD_RegisterWrite(0x42,HY);
	LCD_RegisterWrite(0x43,HY>>8);
}

void Set_Graphic_Cursor_Color_1(unsigned char temp)
{



 	
	LCD_RegisterWrite(0x44,temp);
}

void Set_Graphic_Cursor_Color_2(unsigned char temp)
{



 	
	LCD_RegisterWrite(0x45,temp);
}

void Canvas_Image_Start_address(unsigned long Addr)	
{





 
	LCD_RegisterWrite(0x50,Addr);
	LCD_RegisterWrite(0x51,Addr>>8);
	LCD_RegisterWrite(0x52,Addr>>16);
	LCD_RegisterWrite(0x53,Addr>>24);
}

void Canvas_image_width(uint16_t WX)	
{



 
	LCD_RegisterWrite(0x54,WX);
	LCD_RegisterWrite(0x55,WX>>8);
}

void Active_Window_XY(uint16_t WX,uint16_t HY)	
{





 
	LCD_RegisterWrite(0x56,WX);
	LCD_RegisterWrite(0x57,WX>>8);
	
	LCD_RegisterWrite(0x58,HY);
	LCD_RegisterWrite(0x59,HY>>8);
}

void Active_Window_WH(uint16_t WX,uint16_t HY)	
{





 
	LCD_RegisterWrite(0x5A,WX);
	LCD_RegisterWrite(0x5B,WX>>8);
 
 	LCD_RegisterWrite(0x5C,HY);
	LCD_RegisterWrite(0x5D,HY>>8);
}

void Memory_XY_Mode(void)	
{




 
	uint8_t temp;

	LCD_CmdWrite(0x5E);
	temp = LCD_DataRead();
	temp &= 0xfb;
	LCD_DataWrite(temp);
}
void Memory_16bpp_Mode(void)	
{









 
	uint8_t temp;

	LCD_CmdWrite(0x5E);
	temp = LCD_DataRead();
	temp &= 0xfd;
	temp |= 0x01;
	LCD_DataWrite(temp);
}
void Memory_Linear_Mode(void)	
{




 
	unsigned char temp;

	LCD_CmdWrite(0x5E);
	temp = LCD_DataRead();
	temp |= 0x04;
	LCD_DataWrite(temp);
}

void Goto_Pixel_XY(uint16_t WX,uint16_t HY)	
{










 
	LCD_RegisterWrite(0x5F,WX);
	LCD_RegisterWrite(0x60,WX>>8);
	
	LCD_RegisterWrite(0x61,HY);
	LCD_RegisterWrite(0x62,HY>>8);
}
void Goto_Linear_Addr(unsigned long Addr)
{
 LCD_RegisterWrite(0x5F,Addr);
 LCD_RegisterWrite(0x60,Addr>>8); 
 LCD_RegisterWrite(0x61,Addr>>16);
 LCD_RegisterWrite(0x62,Addr>>24);
}

void Goto_Text_XY(unsigned short WX,unsigned short HY)	
{







 
	LCD_RegisterWrite(0x63,WX);
	LCD_RegisterWrite(0x64,WX>>8);
	
	LCD_RegisterWrite(0x65,HY);
	LCD_RegisterWrite(0x66,HY>>8);
}
















 
void Start_Line(void)
{
	LCD_CmdWrite(0x67);
	LCD_DataWrite(0x80);
	Check_Busy_Draw();
}
void Start_Triangle(void)
{
	LCD_CmdWrite(0x67);
	LCD_DataWrite(0x82);
	Check_Busy_Draw();
}
void Start_Triangle_Fill(void)
{

	LCD_CmdWrite(0x67);
	LCD_DataWrite(0xA2);
	Check_Busy_Draw();
}


void Line_Start_XY(unsigned short WX,unsigned short HY)
{





 
	LCD_CmdWrite(0x68);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x69);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x6A);
	LCD_DataWrite(HY);

	LCD_CmdWrite(0x6B);
	LCD_DataWrite(HY>>8);
}


void Line_End_XY(unsigned short WX,unsigned short HY)
{





 
	LCD_CmdWrite(0x6C);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x6D);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x6E);
	LCD_DataWrite(HY);

	LCD_CmdWrite(0x6F);
	LCD_DataWrite(HY>>8);
}


void Triangle_Point1_XY(unsigned short WX,unsigned short HY)
{





 
	LCD_CmdWrite(0x68);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x69);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x6A);
	LCD_DataWrite(HY);

	LCD_CmdWrite(0x6B);
	LCD_DataWrite(HY>>8);
}

void Triangle_Point2_XY(unsigned short WX,unsigned short HY)
{





 
	LCD_CmdWrite(0x6C);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x6D);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x6E);
	LCD_DataWrite(HY);

	LCD_CmdWrite(0x6F);
	LCD_DataWrite(HY>>8);
}

void Triangle_Point3_XY (unsigned short WX,unsigned short HY)
{





 
	LCD_CmdWrite(0x70);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x71);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x72);
	LCD_DataWrite(HY);

	LCD_CmdWrite(0x73);
	LCD_DataWrite(HY>>8);
}

void Square_Start_XY(unsigned short WX,unsigned short HY)
{





 
	LCD_CmdWrite(0x68);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x69);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x6A);
	LCD_DataWrite(HY);

	LCD_CmdWrite(0x6B);
	LCD_DataWrite(HY>>8);
}

void Square_End_XY(uint16_t WX,uint16_t HY)
{





 
	LCD_CmdWrite(0x6C);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x6D);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x6E);
	LCD_DataWrite(HY);

	LCD_CmdWrite(0x6F);
	LCD_DataWrite(HY>>8);
}


void Point(uint16_t x,uint16_t y,uint16_t color)
{ 
	Check_Mem_WR_FIFO_not_Full();
	LCD_CmdWrite(0x5e);
	LCD_DataWrite(0x01);
	
	LCD_CmdWrite(0x5f);
	LCD_DataWrite(x);
	LCD_CmdWrite(0x60);
	LCD_DataWrite(x>>8);

	LCD_CmdWrite(0x61);
	LCD_DataWrite(y);
	LCD_CmdWrite(0x62);
	LCD_DataWrite(y>>8);
		
	LCD_CmdWrite(0x04);
	LCD_DataWrite_Pixel(color);
}

void Lines(uint16_t x1 ,uint16_t y1 ,uint16_t x2,uint16_t y2,uint16_t color)
{ 
	uint8_t temp;
	
	LCD_CmdWrite(0x68);
	LCD_DataWrite(x1);
	LCD_CmdWrite(0x69);
	LCD_DataWrite(x1>>8);

	LCD_CmdWrite(0x6A);
	LCD_DataWrite(y1);
	LCD_CmdWrite(0x6B);
	LCD_DataWrite(y1>>8);
	
	LCD_CmdWrite(0x6C);
	LCD_DataWrite(x2);
	LCD_CmdWrite(0x6D);
	LCD_DataWrite(x2>>8);

	LCD_CmdWrite(0x6E);
	LCD_DataWrite(y2);
	LCD_CmdWrite(0x6F);
	LCD_DataWrite(y2>>8);
	
	temp=color;
	temp=temp<<3;
	LCD_CmdWrite(0xD2);
	LCD_DataWrite(temp);
	temp=color>>3;
	temp=temp & 0xfc;
	LCD_CmdWrite(0xD3);
	LCD_DataWrite(temp);
	temp=color>>8;
	temp=temp & 0xf8;
	LCD_CmdWrite(0xD4);
	LCD_DataWrite(temp);
	
	LCD_CmdWrite(0x67);
	LCD_DataWrite(0x80);
	Check_Busy_Draw();
	







































 
}	
void Images(uint16_t x,uint16_t y,const char h[],uint16_t number,uint16_t color1,uint16_t color2) 
{
 int16_t dx,i,j,k,color;
 uint8_t a,b,c;
 a=h[0];
 b=h[1];
 dx=2+a*b*number;
 for (j=0;j<b;j++)
	{
			for ( i=0;i<a;i++)
      {   
				c=h[dx+j*a+i] ;
        for (k=0;k<8 ;k++)
         {    
					 if (c&0x80)  color=color1;
           else         color=color2;
					 Point(x+i*8+k,y+j,color);
           c=c<<1;
         }
		   }
		}	
}	
 
void MPU_Memory_Write_Window_8bit  
(
 uint16_t x            
,uint16_t y            
,const char g[]
,uint16_t number
,uint16_t color1
,uint16_t color2   
)
{ int16_t dx,i,j,k,color;
  uint8_t a,b,c;
  a=g[0];
  b=g[1];
  dx=2+a*b*number;
	Graphic_Mode();
  Active_Window_XY(x,y);
	Active_Window_WH(a*8,b);
	Goto_Pixel_XY(x,y);
	LCD_CmdWrite(0x04);
	for(j=0;j<b;j++)
	{
		for(i=0;i<a;i++)
		{ 
			c=g[dx+j*a+i] ;
			for (k=0;k<8 ;k++)
         {    
					 if (c&0x80)  color=color1;
           else         color=color2;
					 Check_Mem_WR_FIFO_not_Full();
					 LCD_DataWrite_Pixel(color);
           c=c<<1;
         } 
			
		}
	}
	Check_Mem_WR_FIFO_Empty();
	Active_Window_XY(0,0);
	Active_Window_WH(1024,600);
}
 
void Fills
(
 uint16_t X1                
,uint16_t Y1                
,uint16_t X2                
,uint16_t Y2                
,unsigned long ForegroundColor    
)
{
	Foreground_color_65k(ForegroundColor);
  Square_Start_XY(X1,Y1);
  Square_End_XY(X2,Y2);
  Start_Square_Fill();
  Check_2D_Busy();
}
void ellipse(uint16_t x1 ,uint16_t y1 ,uint16_t r1,uint16_t r2,uint16_t color)
{ uint8_t temp;
	LCD_CmdWrite(0x7b);
	LCD_DataWrite(x1);
	LCD_CmdWrite(0x7c);
	LCD_DataWrite(x1>>8);

	LCD_CmdWrite(0x7d);
	LCD_DataWrite(y1);
	LCD_CmdWrite(0x7e);
	LCD_DataWrite(y1>>8);
	
	LCD_CmdWrite(0x77);
	LCD_DataWrite(r1);
	LCD_CmdWrite(0x78);
	LCD_DataWrite(r1>>8);

	LCD_CmdWrite(0x79);
	LCD_DataWrite(r2);
	LCD_CmdWrite(0x7a);
	LCD_DataWrite(r2>>8);
	
	temp=color;
	temp=temp<<3;
	LCD_CmdWrite(0xD2);
	LCD_DataWrite(temp);
	temp=color>>3;
	temp=temp & 0xfc;
	LCD_CmdWrite(0xD3);
	LCD_DataWrite(temp);
	temp=color>>8;
	temp=temp & 0xf8;
	LCD_CmdWrite(0xD4);
	LCD_DataWrite(temp);
	
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0x80);
	
}	



























 
void Start_Circle_or_Ellipse(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0x80);
	Check_Busy_Draw();	
}
void Start_Circle_or_Ellipse_Fill(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0xC0);
	Check_Busy_Draw();	
}

void Start_Left_Down_Curve(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0x90);
	Check_Busy_Draw();	
}
void Start_Left_Up_Curve(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0x91);
	Check_Busy_Draw();	
}
void Start_Right_Up_Curve(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0x92);
	Check_Busy_Draw();	
}
void Start_Right_Down_Curve(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0x93);
	Check_Busy_Draw();	
}

void Start_Left_Down_Curve_Fill(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0xD0);
	Check_Busy_Draw();
}
void Start_Left_Up_Curve_Fill(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0xD1);
	Check_Busy_Draw();
}
void Start_Right_Up_Curve_Fill(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0xD2);
	Check_Busy_Draw();
}
void Start_Right_Down_Curve_Fill(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0xD3);
	Check_Busy_Draw();
}

void Start_Square(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0xA0);
	Check_Busy_Draw();
}
void Start_Square_Fill(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0xE0);
	Check_Busy_Draw();
}
void Start_Circle_Square(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0xB0);
	Check_Busy_Draw();	
}
void Start_Circle_Square_Fill(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0xF0);
	Check_Busy_Draw();	
}


void Circle_Center_XY(unsigned short WX,unsigned short HY)
{





 
	LCD_CmdWrite(0x7B);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x7C);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x7D);
	LCD_DataWrite(HY);

	LCD_CmdWrite(0x7E);
	LCD_DataWrite(HY>>8);
}

void Ellipse_Center_XY(unsigned short WX,unsigned short HY)
{





 
	LCD_CmdWrite(0x7B);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x7C);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x7D);
	LCD_DataWrite(HY);

	LCD_CmdWrite(0x7E);
	LCD_DataWrite(HY>>8);
}

void Circle_Radius_R(unsigned short WX)
{





 
	LCD_CmdWrite(0x77);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x78);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x79);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x7A);
	LCD_DataWrite(WX>>8);
}


void Ellipse_Radius_RxRy(unsigned short WX,unsigned short HY)
{





 
	LCD_CmdWrite(0x77);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x78);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x79);
	LCD_DataWrite(HY);

	LCD_CmdWrite(0x7A);
	LCD_DataWrite(HY>>8);
}


void Circle_Square_Radius_RxRy(unsigned short WX,unsigned short HY)
{





 
	LCD_CmdWrite(0x77);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x78);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x79);
	LCD_DataWrite(HY);

	LCD_CmdWrite(0x7A);
	LCD_DataWrite(HY>>8);
}


void Set_PWM_Prescaler_1_to_256(uint16_t WX)
{




 
	WX=WX-1;
	LCD_CmdWrite(0x84);
	LCD_DataWrite(WX);
}

void Select_PWM1_Clock_Divided_By_1(void)
{



 
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp &= 0x7f;
	temp &= 0xbf;
	LCD_DataWrite(temp);
}
void Select_PWM1_Clock_Divided_By_2(void)
{



 
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp &= 0x7f;
	temp |= 0x40;
	LCD_DataWrite(temp);
}
void Select_PWM1_Clock_Divided_By_4(void)
{



 
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp |= 0x80;
	temp &= 0xbf;
	LCD_DataWrite(temp);
}
void Select_PWM1_Clock_Divided_By_8(void)
{



 
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp |= 0x80;
	temp |= 0x40;
	LCD_DataWrite(temp);
}
void Select_PWM0_Clock_Divided_By_1(void)
{



 
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp &= 0xdf;
	temp &= 0xef;
	LCD_DataWrite(temp);
}
void Select_PWM0_Clock_Divided_By_2(void)
{



 
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp &= 0xdf;
	temp |= 0x10;
	LCD_DataWrite(temp);
}
void Select_PWM0_Clock_Divided_By_4(void)
{



 
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp |= 0x20;
	temp &= 0xef;
	LCD_DataWrite(temp);
}
void Select_PWM0_Clock_Divided_By_8(void)
{



 
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp |= 0x20;
	temp |= 0x10;
	LCD_DataWrite(temp);
}







 
void Select_PWM1_is_ErrorFlag(void)
{
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp &= 0xf7;
	LCD_DataWrite(temp);
}
void Select_PWM1(void)
{
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp |= 0x08;
	temp &= 0xfb;
	LCD_DataWrite(temp);
}






 

void Select_PWM0(void)
{
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp |= 0x02;
	temp &= 0xfe;
	LCD_DataWrite(temp);
}


void Start_PWM1(void)
{





 
	uint8_t temp;
	LCD_CmdWrite(0x86);
	temp = LCD_DataRead();
	temp |= 0x10;
	LCD_DataWrite(temp);
}
void Stop_PWM1(void)
{





 
	uint8_t temp;
	LCD_CmdWrite(0x86);
	temp = LCD_DataRead();
	temp &= 0xef;
	LCD_DataWrite(temp);
}

void Start_PWM0(void)
{





 
	uint8_t temp;
	LCD_CmdWrite(0x86);
	temp = LCD_DataRead();
	temp |= 0x01;
	LCD_DataWrite(temp);
}
void Stop_PWM0(void)
{





 
	uint8_t temp;
	LCD_CmdWrite(0x86);
	temp = LCD_DataRead();
	temp &= 0xfe;
	LCD_DataWrite(temp);
}


void Set_Timer0_Compare_Buffer(uint16_t WX)
{





 
	LCD_CmdWrite(0x88);
	LCD_DataWrite(WX);
	LCD_CmdWrite(0x89);
	LCD_DataWrite(WX>>8);
}

void Set_Timer0_Count_Buffer(uint16_t WX)
{





 
	LCD_CmdWrite(0x8A);
	LCD_DataWrite(WX);
	LCD_CmdWrite(0x8B);
	LCD_DataWrite(WX>>8);
}

void Set_Timer1_Compare_Buffer(uint16_t WX)
{





 
	LCD_CmdWrite(0x8C);
	LCD_DataWrite(WX);
	LCD_CmdWrite(0x8D);
	LCD_DataWrite(WX>>8);
}

void Set_Timer1_Count_Buffer(uint16_t WX)
{





 
	LCD_CmdWrite(0x8E);
	LCD_DataWrite(WX);
	LCD_CmdWrite(0x8F);
	LCD_DataWrite(WX>>8);
}

void BTE_Enable(void)
{	




 
    unsigned char temp;
    LCD_CmdWrite(0x90);
    temp = LCD_DataRead();
    temp |= 0x10 ;
	LCD_DataWrite(temp);  
}


void BTE_Disable(void)
{	




 
    unsigned char temp;
    LCD_CmdWrite(0x90);
    temp = LCD_DataRead();
    temp &= 0xef ;
	LCD_DataWrite(temp);  
}


void Check_BTE_Busy(void)
{	




 
	unsigned char temp; 	
	do
	{
		temp=LCD_StatusRead();
	}while(temp&0x08);

}

void Pattern_Format_8X8(void)
{	




 
    unsigned char temp;
    LCD_CmdWrite(0x90);
    temp = LCD_DataRead();
    temp &= 0xfe ;
	LCD_DataWrite(temp);
}	

void Pattern_Format_16X16(void)
{	




 
    unsigned char temp;
    LCD_CmdWrite(0x90);
    temp = LCD_DataRead();
    temp |= 0x01 ;
	  LCD_DataWrite(temp);
}	


void BTE_Operation_Code(unsigned char setx)
{	



















 
    unsigned char temp;
    LCD_CmdWrite(0x91);
    temp = LCD_DataRead();
    temp &= 0xf0 ;
		temp |= setx ;
	  LCD_DataWrite(temp);

}
void BTE_ROP_Code(unsigned char setx)
{	



















 
    unsigned char temp;
    LCD_CmdWrite(0x91);
    temp = LCD_DataRead();
    temp &= 0x0f ;
		temp |= (setx<<4);
	  LCD_DataWrite(temp);
}

void BTE_S0_Color_16bpp(void)
{	





 	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp &= 0xbf ;
		temp |= 0x20 ;
	  LCD_DataWrite(temp);

}	

void BTE_S0_Color_24bpp(void)
{	





 	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp |= 0x40 ;
		
	  LCD_DataWrite(temp);
}

void BTE_S1_Color_8bpp(void)
{	








 	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp &= 0xef ;
		temp &= 0xf7 ;
	  temp &= 0xfb ;
	  LCD_DataWrite(temp);
}	

void BTE_S1_Color_16bpp(void)
{	








 	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp &= 0xef ;
		temp &= 0xf7 ;
	  temp |= 0x04 ;
	  LCD_DataWrite(temp);

}

void BTE_S1_Color_24bpp(void)
{	








 	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp &= 0xef ;
		temp |= 0x08 ;
	  temp &= 0xfb ;
	  LCD_DataWrite(temp);
}


void BTE_S1_Color_Constant(void)
{	








 	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp &= 0xef ;
		temp |= 0x08 ;
	  temp |= 0x04 ;
	  LCD_DataWrite(temp);
}




void BTE_S1_Color_8bit_Alpha(void)
{	








 	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp |= 0x10 ;
		temp &= 0xf7 ;
	  temp &= 0xfb ;
	  LCD_DataWrite(temp);
}


void BTE_S1_Color_16bit_Alpha(void)
{	








 	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp |= 0x10 ;
		temp &= 0xf7 ;
	  temp |= 0x04 ;
	  LCD_DataWrite(temp);
}


void BTE_Destination_Color_8bpp(void)
{	





 	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp &= 0xfd ;
		temp &= 0xfe ;
	  LCD_DataWrite(temp);
}	

void BTE_Destination_Color_16bpp(void)
{	





 	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp &= 0xfd ;
		temp |= 0x01 ;
	  LCD_DataWrite(temp);

}	

void BTE_Destination_Color_24bpp(void)
{	





 	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp |= 0x02 ;
		
	  LCD_DataWrite(temp);
}


void Start_SFI_DMA(void)
{
	uint8_t temp;
	LCD_CmdWrite(0xB6);
	temp = LCD_DataRead();
    temp |= 0x01;
	LCD_DataWrite(temp);
}

void Check_Busy_SFI_DMA(void)
{
	LCD_CmdWrite(0xB6);
	do
	{		
	}while((LCD_DataRead()&0x01)==0x01);
}



void Select_SFI_0(void)
{




 
	uint8_t temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
    temp &= 0x7f;
	LCD_DataWrite(temp);
}
void Select_SFI_1(void)
{




 
	uint8_t temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
    temp |= 0x80;
	LCD_DataWrite(temp);
}

void Select_SFI_DMA_Mode(void)
{




 
	uint8_t temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
    temp |= 0x40;
	LCD_DataWrite(temp);
}

void Select_SFI_Dual_Mode0(void)
{
	uint8_t temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
	temp &= 0xFC;
    temp |= 0x02;
	LCD_DataWrite(temp);
}


void SPI_Clock_Period(uint8_t temp)
{
   LCD_CmdWrite(0xBB);
   LCD_DataWrite(temp);
} 


void SFI_DMA_Source_Start_Address(unsigned long Addr)
{



 
	LCD_CmdWrite(0xBC);
	LCD_DataWrite(Addr);
	LCD_CmdWrite(0xBD);
	LCD_DataWrite(Addr>>8);
	LCD_CmdWrite(0xBE);
	LCD_DataWrite(Addr>>16);
	LCD_CmdWrite(0xBF);
	LCD_DataWrite(Addr>>24);
}



void SFI_DMA_Source_Width(uint16_t WX)
{



 
	LCD_CmdWrite(0xCA);
	LCD_DataWrite(WX);
	LCD_CmdWrite(0xCB);
	LCD_DataWrite(WX>>8);
} 
void Foreground_color_65k(uint16_t temp)
{
    LCD_CmdWrite(0xD2);
 	LCD_DataWrite(temp>>8);
 
    LCD_CmdWrite(0xD3);
 	LCD_DataWrite(temp>>3);
  
    LCD_CmdWrite(0xD4);
 	LCD_DataWrite(temp<<3);
}

void BTE_S0_Memory_Start_Address(unsigned long Addr)	
{






 
	LCD_RegisterWrite(0x93,Addr);
	LCD_RegisterWrite(0x94,Addr>>8);
	LCD_RegisterWrite(0x95,Addr>>16);
	LCD_RegisterWrite(0x96,Addr>>24);
}



void BTE_S0_Image_Width(unsigned short WX)	
{





 
	LCD_RegisterWrite(0x97,WX);
	LCD_RegisterWrite(0x98,WX>>8);
}



void BTE_S0_Window_Start_XY(unsigned short WX,unsigned short HY)	
{





 
	LCD_RegisterWrite(0x99,WX);
	LCD_RegisterWrite(0x9A,WX>>8);

	LCD_RegisterWrite(0x9B,HY);
	LCD_RegisterWrite(0x9C,HY>>8);
}





void BTE_S1_Memory_Start_Address(unsigned long Addr)	
{






 
	LCD_RegisterWrite(0x9D,Addr);
	LCD_RegisterWrite(0x9E,Addr>>8);
	LCD_RegisterWrite(0x9F,Addr>>16);
	LCD_RegisterWrite(0xA0,Addr>>24);
}



void S1_Constant_color_256(unsigned char temp)
{
    LCD_CmdWrite(0x9D);
    LCD_DataWrite(temp);

    LCD_CmdWrite(0x9E);
    LCD_DataWrite(temp<<3);

    LCD_CmdWrite(0x9F);
    LCD_DataWrite(temp<<6);
}


void S1_Constant_color_65k(unsigned short temp)
{
    LCD_CmdWrite(0x9D);
    LCD_DataWrite(temp>>8);

    LCD_CmdWrite(0x9E);
    LCD_DataWrite(temp>>3);

    LCD_CmdWrite(0x9F);
    LCD_DataWrite(temp<<3);
}


void S1_Constant_color_16M(unsigned long temp)
{
    LCD_CmdWrite(0x9D);
    LCD_DataWrite(temp>>16);

    LCD_CmdWrite(0x9E);
    LCD_DataWrite(temp>>8);

    LCD_CmdWrite(0x9F);
    LCD_DataWrite(temp);
}





void BTE_S1_Image_Width(unsigned short WX)	
{





 
	LCD_RegisterWrite(0xA1,WX);
	LCD_RegisterWrite(0xA2,WX>>8);
}



void BTE_S1_Window_Start_XY(unsigned short WX,unsigned short HY)	
{





 
	LCD_RegisterWrite(0xA3,WX);
	LCD_RegisterWrite(0xA4,WX>>8);

	LCD_RegisterWrite(0xA5,HY);
	LCD_RegisterWrite(0xA6,HY>>8);
}





void BTE_Destination_Memory_Start_Address(unsigned long Addr)	
{






 
	LCD_RegisterWrite(0xA7,Addr);
	LCD_RegisterWrite(0xA8,Addr>>8);
	LCD_RegisterWrite(0xA9,Addr>>16);
	LCD_RegisterWrite(0xAA,Addr>>24);
}



void BTE_Destination_Image_Width(unsigned short WX)	
{





 
	LCD_RegisterWrite(0xAB,WX);
	LCD_RegisterWrite(0xAC,WX>>8);
}



void BTE_Destination_Window_Start_XY(unsigned short WX,unsigned short HY)	
{





 
	LCD_RegisterWrite(0xAD,WX);
	LCD_RegisterWrite(0xAE,WX>>8);

	LCD_RegisterWrite(0xAF,HY);
	LCD_RegisterWrite(0xB0,HY>>8);
}




void BTE_Window_Size(unsigned short WX, unsigned short WY)

{






 
        LCD_RegisterWrite(0xB1,WX);
        LCD_RegisterWrite(0xB2,WX>>8);
	
	    LCD_RegisterWrite(0xB3,WY);
        LCD_RegisterWrite(0xB4,WY>>8);
}


void BTE_Alpha_Blending_Effect(unsigned char temp)
{	













 
    LCD_CmdWrite(0xB5);
	LCD_DataWrite(temp);  
}

void Select_SFI_Font_Mode(void)
{




 
	unsigned char temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
    temp &= 0xbf;
	LCD_DataWrite(temp);
}

void Select_SFI_24bit_Address(void)
{




 
	unsigned char temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
    temp &= 0xdf;
	LCD_DataWrite(temp);
}
void Select_SFI_32bit_Address(void)
{




 
	unsigned char temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
    temp |= 0x20;
	LCD_DataWrite(temp);
}
void Select_SFI_Waveform_Mode_0(void)
{




 
	unsigned char temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
    temp &= 0xef;
	LCD_DataWrite(temp);
}
void Select_SFI_Waveform_Mode_3(void)
{




 
	unsigned char temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
    temp |= 0x10;
	LCD_DataWrite(temp);
}
void Select_SFI_0_DummyRead(void)
{






 
	unsigned char temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
	temp &= 0xF3;
	LCD_DataWrite(temp);
}
void Select_SFI_8_DummyRead(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
	temp &= 0xF3;
    temp |= 0x04;
	LCD_DataWrite(temp);
}
void Select_SFI_16_DummyRead(void)
{

	unsigned char temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
	temp &= 0xF3;
    temp |= 0x08;
	LCD_DataWrite(temp);
}
void Select_SFI_24_DummyRead(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
    temp |= 0x0c;
	LCD_DataWrite(temp);
}
void Select_SFI_Single_Mode(void)
{





 
	unsigned char temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
	temp &= 0xFC;
	LCD_DataWrite(temp);
}

void Select_SFI_Dual_Mode1(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
    temp |= 0x03;
	LCD_DataWrite(temp);
}


unsigned char SPI_Master_FIFO_Data_Put(unsigned char Data)
{
    unsigned char temp;
	LCD_CmdWrite(0xB8);
	LCD_DataWrite(Data);
	while(Tx_FIFO_Empty_Flag()==0);	
	temp = SPI_Master_FIFO_Data_Get();
	return temp;
}

unsigned char SPI_Master_FIFO_Data_Get(void)
{
   unsigned char temp;

	while(Rx_FIFO_Empty_Flag()==1);
	LCD_CmdWrite(0xB8);
	temp=LCD_DataRead();
	
   return temp;
}


void Mask_SPI_Master_Interrupt_Flag(void)
{
  unsigned char temp;
  LCD_CmdWrite(0xB9);
  temp = LCD_DataRead();
  temp |= 0x40;
  LCD_DataWrite(temp);

} 

void Select_nSS_drive_on_xnsfcs0(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB9);
	temp = LCD_DataRead();
	temp &= 0xdf;
	LCD_DataWrite(temp);

}

void Select_nSS_drive_on_xnsfcs1(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB9);
	temp = LCD_DataRead();
	temp |= 0x20;
	LCD_DataWrite(temp);
}


void nSS_Inactive(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB9);
	temp = LCD_DataRead();
	temp &= 0xef;
	LCD_DataWrite(temp);
}

void nSS_Active(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB9);
	temp = LCD_DataRead();
	temp |= 0x10;
	LCD_DataWrite(temp);
}


void OVFIRQEN_Enable(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB9);
	temp = LCD_DataRead();
	temp |= 0x08;
	LCD_DataWrite(temp);
}

void EMTIRQEN_Enable(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB9);
	temp = LCD_DataRead();
	temp |= 0x04;
	LCD_DataWrite(temp);
}














void Reset_CPOL(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB9);
	temp = LCD_DataRead();
	temp &= 0xfd;
	LCD_DataWrite(temp);
}

void Set_CPOL(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB9);
	temp = LCD_DataRead();
	temp |= 0x02;
	LCD_DataWrite(temp);
}


void Reset_CPHA(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB9);
	temp = LCD_DataRead();
	temp &= 0xfe;
	LCD_DataWrite(temp);
}

void Set_CPHA(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB9);
	temp = LCD_DataRead();
	temp |= 0x01;
	LCD_DataWrite(temp);
}



unsigned char Tx_FIFO_Empty_Flag(void)
{
	LCD_CmdWrite(0xBA);
	if((LCD_DataRead()&0x80)==0x80)
	return 1;
	else
	return 0;
}

unsigned char Tx_FIFO_Full_Flag(void)
{
	LCD_CmdWrite(0xBA);
	if((LCD_DataRead()&0x40)==0x40)
	return 1;
	else
	return 0;
} 

unsigned char Rx_FIFO_Empty_Flag(void)
{
	LCD_CmdWrite(0xBA);
	if((LCD_DataRead()&0x20)==0x20)
	return 1;
	else
	return 0;
} 

unsigned char Rx_FIFO_full_flag(void)
{
   LCD_CmdWrite(0xBA);
   if((LCD_DataRead()&0x10)==0x10)
   return 1;
   else
   return 0;
} 

unsigned char OVFI_Flag(void)
{
   LCD_CmdWrite(0xBA);
   if((LCD_DataRead()&0x08)==0x08)
   return 1;
   else
   return 0;
}

void Clear_OVFI_Flag(void)
{
   unsigned char temp;
   LCD_CmdWrite(0xBA);
   temp = LCD_DataRead();
   temp |= 0x08;
   LCD_DataWrite(temp);
}

unsigned char EMTI_Flag(void)
{
   LCD_CmdWrite(0xBA);
   if((LCD_DataRead()&0x04)==0x04)
   return 1;
   else
   return 0;
}

void Clear_EMTI_Flag(void)
{
   unsigned char temp;
   LCD_CmdWrite(0xBA);
   temp = LCD_DataRead();
   temp |= 0x04;
   LCD_DataWrite(temp);
}


void SFI_DMA_Destination_Start_Address(unsigned long Addr)
{




 
	LCD_CmdWrite(0xC0);
	LCD_DataWrite(Addr);
	LCD_CmdWrite(0xC1);
	LCD_DataWrite(Addr>>8);
	LCD_CmdWrite(0xC2);
	LCD_DataWrite(Addr>>16);
	LCD_CmdWrite(0xC3);
	LCD_DataWrite(Addr>>24);
}

void SFI_DMA_Destination_Upper_Left_Corner(unsigned short WX,unsigned short HY)
{
























 
 
	LCD_CmdWrite(0xC0);
	LCD_DataWrite(WX);
	LCD_CmdWrite(0xC1);
	LCD_DataWrite(WX>>8);
 
	LCD_CmdWrite(0xC2);
	LCD_DataWrite(HY);
	LCD_CmdWrite(0xC3);
	LCD_DataWrite(HY>>8);
}


void SFI_DMA_Transfer_Number(unsigned long Addr)
{








 
	LCD_CmdWrite(0xC6);
	LCD_DataWrite(Addr);
	LCD_CmdWrite(0xC7);
	LCD_DataWrite(Addr>>8);
	LCD_CmdWrite(0xC8);
	LCD_DataWrite(Addr>>16);
	LCD_CmdWrite(0xC9);
	LCD_DataWrite(Addr>>24);
}
void SFI_DMA_Transfer_Width_Height(unsigned short WX,unsigned short HY)
{







 
	LCD_CmdWrite(0xC6);
	LCD_DataWrite(WX);
	LCD_CmdWrite(0xC7);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0xC8);
	LCD_DataWrite(HY);
	LCD_CmdWrite(0xC9);
	LCD_DataWrite(HY>>8);
}



void Font_Select_UserDefine_Mode(void)
{





 
	unsigned char temp;
	LCD_CmdWrite(0xCC);
	temp = LCD_DataRead();
    temp |= 0x80;
	temp &= 0xbf;
	LCD_DataWrite(temp);
}
void CGROM_Select_Internal_CGROM(void)
{





 
	unsigned char temp;
	LCD_CmdWrite(0xCC);
	temp = LCD_DataRead();
	temp &= 0x7f;
    temp &= 0xbf;
	LCD_DataWrite(temp);
}
void CGROM_Select_Genitop_FontROM(void)
{





 
	unsigned char temp;
	LCD_CmdWrite(0xCC);
	temp = LCD_DataRead();
	temp &= 0x7f;
    temp |= 0x40;
	LCD_DataWrite(temp);
}
void Font_Select_8x16_16x16(void)
{








 
	unsigned char temp;
	LCD_CmdWrite(0xCC);
	temp = LCD_DataRead();
    temp &= 0xdf;
    temp &= 0xef;
	LCD_DataWrite(temp);
}
void Font_Select_12x24_24x24(void)
{








 
	unsigned char temp;
	LCD_CmdWrite(0xCC);
	temp = LCD_DataRead();
    temp &= 0xdf;
    temp |= 0x10;
	LCD_DataWrite(temp);
}
void Font_Select_16x32_32x32(void)
{








 
	unsigned char temp;
	LCD_CmdWrite(0xCC);
	temp = LCD_DataRead();
    temp |= 0x20;
    temp &= 0xef;
	LCD_DataWrite(temp);
}
void Internal_CGROM_Select_ISOIEC8859_1(void)
{









 
	unsigned char temp;
	LCD_CmdWrite(0xCC);
	temp = LCD_DataRead();
    temp &= 0xfd;
    temp &= 0xfe;
	LCD_DataWrite(temp);
}
void Internal_CGROM_Select_ISOIEC8859_2(void)
{









 
	unsigned char temp;
	LCD_CmdWrite(0xCC);
	temp = LCD_DataRead();
    temp &= 0xfd;
    temp |= 0x01;
	LCD_DataWrite(temp);
}
void Internal_CGROM_Select_ISOIEC8859_3(void)
{









 
	unsigned char temp;
	LCD_CmdWrite(0xCC);
	temp = LCD_DataRead();
    temp |= 0x02;
    temp &= 0xfe;
	LCD_DataWrite(temp);
}
void Internal_CGROM_Select_ISOIEC8859_4(void)
{









 
	unsigned char temp;
	LCD_CmdWrite(0xCC);
	temp = LCD_DataRead();
    temp |= 0x02;
    temp |= 0x01;
	LCD_DataWrite(temp);
}

void Enable_Font_Alignment(void)
{




 
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp |= 0x80;
	LCD_DataWrite(temp);
}
void Disable_Font_Alignment(void)
{




 
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp &= 0x7f;
	LCD_DataWrite(temp);
}
void Font_Background_select_Transparency(void)
{




 
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp |= 0x40;
	LCD_DataWrite(temp);
}
void Font_Background_select_Color(void)
{




 
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp &= 0xbf;
	LCD_DataWrite(temp);
}
void Font_0_degree(void)
{









 
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp &= 0xef;
	LCD_DataWrite(temp);
}
void Font_90_degree(void)
{









 
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp |= 0x10;
	LCD_DataWrite(temp);
}
void Font_Width_X1(void)
{






 
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp &= 0xf7;
    temp &= 0xfb;
	LCD_DataWrite(temp);
}
void Font_Width_X2(void)
{






 
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp &= 0xf7;
    temp |= 0x04;
	LCD_DataWrite(temp);
}
void Font_Width_X3(void)
{






 
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp |= 0x08;
    temp &= 0xfb;
	LCD_DataWrite(temp);
}
void Font_Width_X4(void)
{






 
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp |= 0x08;
    temp |= 0x04;
	LCD_DataWrite(temp);
}
void Font_Height_X1(void)
{






 
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp &= 0xfd;
    temp &= 0xfe;
	LCD_DataWrite(temp);
}
void Font_Height_X2(void)
{






 
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp &= 0xfd;
    temp |= 0x01;
	LCD_DataWrite(temp);
}
void Font_Height_X3(void)
{






 
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp |= 0x02;
    temp &= 0xfe;
	LCD_DataWrite(temp);
}
void Font_Height_X4(void)
{






 
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp |= 0x02;
    temp |= 0x01;
	LCD_DataWrite(temp);
}


void GTFont_Select_GT21L16TW_GT21H16T1W(void)
{










 
	unsigned char temp;
	LCD_CmdWrite(0xCE);
	temp = LCD_DataRead();
    temp &= 0x7f;
    temp &= 0xbf;
    temp &= 0xdf;
	LCD_DataWrite(temp);
}
void GTFont_Select_GT23L16U2W(void)
{










 
	unsigned char temp;
	LCD_CmdWrite(0xCE);
	temp = LCD_DataRead();
    temp &= 0x7f;
    temp &= 0xbf;
    temp |= 0x20;
	LCD_DataWrite(temp);
}
void GTFont_Select_GT23L24T3Y_GT23H24T3Y(void)
{










 
	unsigned char temp;
	LCD_CmdWrite(0xCE);
	temp = LCD_DataRead();
    temp &= 0x7f;
    temp |= 0x40;
    temp &= 0xdf;
	LCD_DataWrite(temp);
}
void GTFont_Select_GT23L24M1Z(void)
{










 
	unsigned char temp;
	LCD_CmdWrite(0xCE);
	temp = LCD_DataRead();
    temp &= 0x7f;
    temp |= 0x40;
    temp |= 0x20;
	LCD_DataWrite(temp);
}
void GTFont_Select_GT23L32S4W_GT23H32S4W(void)
{










 
	unsigned char temp;
	LCD_CmdWrite(0xCE);
	temp = LCD_DataRead();
    temp |= 0x80;
    temp &= 0xbf;
    temp &= 0xdf;
	LCD_DataWrite(temp);
}
void GTFont_Select_GT20L24F6Y(void)
{










 
	unsigned char temp;
	LCD_CmdWrite(0xCE);
	temp = LCD_DataRead();
    temp |= 0x80;
    temp &= 0xbf;
    temp |= 0x20;
	LCD_DataWrite(temp);
}
void GTFont_Select_GT21L24S1W(void)
{










 
	unsigned char temp;
	LCD_CmdWrite(0xCE);
	temp = LCD_DataRead();
    temp |= 0x80;
    temp |= 0x40;
    temp &= 0xdf;
	LCD_DataWrite(temp);
}
void GTFont_Select_GT22L16A1Y(void)
{










 
	unsigned char temp;
	LCD_CmdWrite(0xCE);
	temp = LCD_DataRead();
    temp |= 0x80;
    temp |= 0x40;
    temp |= 0x20;
	LCD_DataWrite(temp);
}


void Set_GTFont_Decoder(unsigned char temp)
{




































 
	LCD_CmdWrite(0xCF);
	LCD_DataWrite(temp);
}

void Font_Line_Distance(unsigned char temp)
{




 
	LCD_CmdWrite(0xD0);
	LCD_DataWrite(temp);
}

void Set_Font_to_Font_Width(unsigned char temp)
{


 
	LCD_CmdWrite(0xD1);
	LCD_DataWrite(temp);
}

void Foreground_RGB(unsigned char RED,unsigned char GREEN,unsigned char BLUE)
{




   
    LCD_CmdWrite(0xD2);
	LCD_DataWrite(RED);
 
    LCD_CmdWrite(0xD3);
	LCD_DataWrite(GREEN);
  
    LCD_CmdWrite(0xD4);
	LCD_DataWrite(BLUE);
}


void Foreground_color_256(unsigned char temp) 
{
    LCD_CmdWrite(0xD2);
	LCD_DataWrite(temp);
 
    LCD_CmdWrite(0xD3);
	LCD_DataWrite(temp<<3);
  
    LCD_CmdWrite(0xD4);
	LCD_DataWrite(temp<<6);
}
 

void Foreground_color_16M(unsigned long temp)
{
    LCD_CmdWrite(0xD2);
 	LCD_DataWrite(temp>>16);
 
    LCD_CmdWrite(0xD3);
 	LCD_DataWrite(temp>>8);
  
    LCD_CmdWrite(0xD4);
 	LCD_DataWrite(temp);
}
 





  
void Background_RGB(unsigned char RED,unsigned char GREEN,unsigned char BLUE)
{
   
  LCD_CmdWrite(0xD5);
	LCD_DataWrite(RED);
  
  LCD_CmdWrite(0xD6);
	LCD_DataWrite(GREEN);
   
  LCD_CmdWrite(0xD7);
	LCD_DataWrite(BLUE);
}
 

void Background_color_256(unsigned char temp)
{
    LCD_CmdWrite(0xD5);
 	LCD_DataWrite(temp);
  
    LCD_CmdWrite(0xD6);
 	LCD_DataWrite(temp<<3);
   
    LCD_CmdWrite(0xD7);
 	LCD_DataWrite(temp<<6);
}
 

void Background_color_65k(unsigned short temp)
{
    LCD_CmdWrite(0xD5);
 	LCD_DataWrite(temp>>8);
  
    LCD_CmdWrite(0xD6);
 	LCD_DataWrite(temp>>3);
   
    LCD_CmdWrite(0xD7);
 	LCD_DataWrite(temp<<3);
}
 

void Background_color_16M(unsigned long temp)
{
    LCD_CmdWrite(0xD5);
 	LCD_DataWrite(temp>>16);
  
    LCD_CmdWrite(0xD6);
 	LCD_DataWrite(temp>>8);
   
    LCD_CmdWrite(0xD7);
 	LCD_DataWrite(temp);
}


void CGRAM_Start_address(unsigned long Addr)
{


 	 
    LCD_CmdWrite(0xDB);
	LCD_DataWrite(Addr);
    LCD_CmdWrite(0xDC);
	LCD_DataWrite(Addr>>8);
    LCD_CmdWrite(0xDD);
	LCD_DataWrite(Addr>>16);
    LCD_CmdWrite(0xDE);
	LCD_DataWrite(Addr>>24);
}











 
void Power_Normal_Mode(void)
{
	LCD_CmdWrite(0xDF);
	LCD_DataWrite(0x00);
}
void Power_Saving_Standby_Mode(void)
{
	LCD_CmdWrite(0xDF);
	LCD_DataWrite(0x01);
	LCD_CmdWrite(0xDF);
	LCD_DataWrite(0x81);
}
void Power_Saving_Suspend_Mode(void)
{
	LCD_CmdWrite(0xDF);


	LCD_DataWrite(0x82);
}
void Power_Saving_Sleep_Mode(void)
{
	LCD_CmdWrite(0xDF);


	LCD_DataWrite(0x83);
}



void LT768_I2CM_Clock_Prescale(unsigned short WX)
{



   
    LCD_CmdWrite(0xE5);
	LCD_DataWrite(WX);
    LCD_CmdWrite(0xE6);
	LCD_DataWrite(WX>>8);
}

void LT768_I2CM_Transmit_Data(unsigned char temp)
{


   
    LCD_CmdWrite(0xE7);
	LCD_DataWrite(temp);
}

unsigned char LT768_I2CM_Receiver_Data(void)
{


   
	unsigned char temp;
    LCD_CmdWrite(0xE8);
	temp=LCD_DataRead();
	return temp;
}
























 


 
void LT768_I2CM_Stop(void)
{
	LCD_CmdWrite(0xE9);

	LCD_DataWrite(0x40);

 



}
void LT768_I2CM_Read_With_Ack(void)
{
 
 LCD_CmdWrite(0xE9);

 LCD_DataWrite(0x20);

	



}
 
void LT768_I2CM_Read_With_Nack(void)
{
 
	LCD_CmdWrite(0xE9);

	LCD_DataWrite(0x68);

	



}
 
void LT768_I2CM_Write_With_Start(void)
{
	LCD_CmdWrite(0xE9);

	LCD_DataWrite(0x90);

 



}
 
void LT768_I2CM_Write(void)
{
	LCD_CmdWrite(0xE9);

	LCD_DataWrite(0x10);

	



}
 
 
 




 
unsigned char LT768_I2CM_Check_Slave_ACK(void)
{ 
	unsigned char temp;




  
	LCD_CmdWrite(0xEA);
	temp=LCD_DataRead();
	if((temp&0x80)==0x80)
	return 1;
	else
	return 0; 
}
 




 
unsigned char LT768_I2CM_Bus_Busy(void)
{
	unsigned char temp; 
 




  
	LCD_CmdWrite(0xEA);
	temp=LCD_DataRead();
	if((temp&0x40)==0x40)
	return 1;
	else
	return 0;    
}
 



 
unsigned char LT768_I2CM_transmit_Progress(void)
{
	unsigned char temp; 



  
	LCD_CmdWrite(0xEA);
	temp=LCD_DataRead();
	if((temp&0x02)==0x02)
	return 1;
	else
	return 0;
}
 
 


 
unsigned char LT768_I2CM_Arbitration(void)
{
	unsigned char temp; 




  
	LCD_CmdWrite(0xEA);
	temp=LCD_DataRead();
	temp&=0x01;
	return temp;
}



void Set_GPIO_A_In_Out(unsigned char temp)
{




 
	LCD_CmdWrite(0xF0);
	LCD_DataWrite(temp);
}

void Write_GPIO_A_7_0(unsigned char temp)
{



 
	LCD_CmdWrite(0xF1);
	LCD_DataWrite(temp);
}
unsigned char Read_GPIO_A_7_0(void)
{



 
	unsigned char temp;
	LCD_CmdWrite(0xF1);
	temp=LCD_DataRead();
	return temp;
}

void Write_GPIO_B_7_4(unsigned char temp)
{



 
	LCD_CmdWrite(0xF2);
	LCD_DataWrite(temp);
}
unsigned char Read_GPIO_B_7_0(void)
{



 
	unsigned char temp;
	LCD_CmdWrite(0xF2);
	temp=LCD_DataRead();
	return temp;
}


void Set_GPIO_C_In_Out(unsigned char temp)
{




 
	LCD_CmdWrite(0xF3);
	LCD_DataWrite(temp);
}

void Write_GPIO_C_7_0(unsigned char temp)
{



 
	LCD_CmdWrite(0xF4);
	LCD_DataWrite(temp);
}
unsigned char Read_GPIO_C_7_0(void)
{



 
	unsigned char temp;
	LCD_CmdWrite(0xF4);
	temp=LCD_DataRead();
	return temp;
}

void Set_GPIO_D_In_Out(unsigned char temp)
{




 
	LCD_CmdWrite(0xF5);
	LCD_DataWrite(temp);
}

void Write_GPIO_D_7_0(unsigned char temp)
{


 
	LCD_CmdWrite(0xF6);
	LCD_DataWrite(temp);
}
unsigned char Read_GPIO_D_7_0(void)
{


 
	unsigned char temp;
	LCD_CmdWrite(0xF6);
	temp=LCD_DataRead();
	return temp;
}

void Set_GPIO_E_In_Out(unsigned char temp)
{




 
	LCD_CmdWrite(0xF7);
	LCD_DataWrite(temp);
}

void Write_GPIO_E_7_0(unsigned char temp)
{



 
	LCD_CmdWrite(0xF8);
	LCD_DataWrite(temp);
}
unsigned char Read_GPIO_E_7_0(void)
{



 
	unsigned char temp;
	LCD_CmdWrite(0xF8);
	temp=LCD_DataRead();
	return temp;
}

void Set_GPIO_F_In_Out(unsigned char temp)
{




 
	LCD_CmdWrite(0xF9);
	LCD_DataWrite(temp);
}

void Write_GPIO_F_7_0(unsigned char temp)
{



 
	LCD_CmdWrite(0xFA);
	LCD_DataWrite(temp);
}
unsigned char Read_GPIO_F_7_0(void)
{



 
	unsigned char temp;
	LCD_CmdWrite(0xFA);
	temp=LCD_DataRead();
	return temp;
}




void Long_Key_enable(void)
{
 




 
	unsigned char temp;
	LCD_CmdWrite(0xFB);
	temp=LCD_DataRead();
	temp |= 0x40;
	LCD_DataWrite(temp);
}


void Key_Scan_Freg(unsigned char setx)
{
  
  unsigned char temp;
  LCD_CmdWrite(0xFB);
  temp = LCD_DataRead();
  temp &= 0xf0;
  temp|= (setx&0x07);
  LCD_DataWrite(temp);  
}




void Key_Scan_Wakeup_Function_Enable(void)
{






 
	unsigned char temp;
	LCD_CmdWrite(0xFC);
	temp=LCD_DataRead();
	temp |= 0x80;
	LCD_DataWrite(temp);
}


void Long_Key_Timing_Adjustment(unsigned char setx)
{
   
	unsigned char temp,temp1;
	temp = setx & 0x1c;
	LCD_CmdWrite(0xFC);
	temp1 = LCD_DataRead();
	temp1|=temp;
	LCD_DataWrite(temp1);   
 
}

unsigned char Numbers_of_Key_Hit(void)
{  
   unsigned char temp;
   LCD_CmdWrite(0xFC);
   temp = LCD_DataRead();   
   temp = temp & 0x03;	 
   return temp;
}


unsigned char Read_Key_Strobe_Data_0(void)
{



 
	unsigned char temp;
	LCD_CmdWrite(0xFD);
	temp=LCD_DataRead();
	return temp;
}
unsigned char Read_Key_Strobe_Data_1(void)
{



 
	unsigned char temp;
	LCD_CmdWrite(0xFE);
	temp=LCD_DataRead();
	return temp;
}
unsigned char Read_Key_Strobe_Data_2(void)
{



 
	unsigned char temp;
	LCD_CmdWrite(0xFF);
	temp=LCD_DataRead();
	return temp;
}



void Show_String(char *str)
{   
  	Text_Mode();	   
  	LCD_CmdWrite(0x04);
  	while(*str != '\0')
  	{
   		LCD_DataWrite(*str);
   		Check_Mem_WR_FIFO_not_Full();
  		++str;   
  	}
   	Check_2D_Busy();

   	Graphic_Mode(); 
}


void Show_picture(unsigned long numbers,const unsigned short *datap)
{   
	unsigned long i;

	LCD_CmdWrite(0x04);  
	for(i=0;i<numbers;i++)
	{
		LCD_DataWrite(datap[i]);
		Check_Mem_WR_FIFO_not_Full();
	}

}


void LT768_DrawLine
(
 unsigned short X1        
,unsigned short Y1        
,unsigned short X2        
,unsigned short Y2        
,unsigned long  LineColor 
)
{
	Foreground_color_65k(LineColor);
	Line_Start_XY(X1,Y1);
	Line_End_XY(X2,Y2);
	Start_Line();
	Check_2D_Busy();
}



void LT768_DrawLine_Width
(
 unsigned short X1        
,unsigned short Y1        
,unsigned short X2        
,unsigned short Y2        
,unsigned long  LineColor 
,unsigned short Width     
)
{
	unsigned short  i = 0;
	while(Width--)
	{
		LT768_DrawLine(X1,Y1+i,X2,Y2+i,LineColor);
		i++;
	}
}



void LT768_DrawCircle
(
 unsigned short XCenter           
,unsigned short YCenter           
,unsigned short R                 
,unsigned long CircleColor        
)
{
	Foreground_color_65k(CircleColor);
	Circle_Center_XY(XCenter,YCenter);
  Circle_Radius_R(R);
  Start_Circle_or_Ellipse();
  Check_2D_Busy(); 
}



void LT768_DrawCircle_Fill
(
 unsigned short XCenter           
,unsigned short YCenter           
,unsigned short R                 
,unsigned long ForegroundColor    
)
{
	Foreground_color_65k(ForegroundColor);
	Circle_Center_XY(XCenter,YCenter);
  Circle_Radius_R(R);
  Start_Circle_or_Ellipse_Fill();
  Check_2D_Busy(); 
}



void LT768_DrawCircle_Width
(
 unsigned short XCenter          
,unsigned short YCenter          
,unsigned short R                
,unsigned long CircleColor       
,unsigned long ForegroundColor   
,unsigned short Width            
)
{
	LT768_DrawCircle_Fill(XCenter,YCenter,R+Width,CircleColor);
	LT768_DrawCircle_Fill(XCenter,YCenter,R,ForegroundColor);
}



void LT768_DrawEllipse
(
 unsigned short XCenter          
,unsigned short YCenter          
,unsigned short X_R              
,unsigned short Y_R              
,unsigned long EllipseColor      
)
{
	Foreground_color_65k(EllipseColor);
	Ellipse_Center_XY(XCenter,YCenter);
  Ellipse_Radius_RxRy(X_R,Y_R);
  Start_Circle_or_Ellipse();
  Check_2D_Busy(); 
}

void LT768_DrawEllipse_Fill
(
 unsigned short XCenter           
,unsigned short YCenter           
,unsigned short X_R               
,unsigned short Y_R               
,unsigned long ForegroundColor    
)
{
	Foreground_color_65k(ForegroundColor);
	Ellipse_Center_XY(XCenter,YCenter);
  Ellipse_Radius_RxRy(X_R,Y_R);
  Start_Circle_or_Ellipse_Fill();
  Check_2D_Busy(); 
}


void LT768_DrawEllipse_Width
(
 unsigned short XCenter           
,unsigned short YCenter           
,unsigned short X_R               
,unsigned short Y_R               
,unsigned long EllipseColor       
,unsigned long ForegroundColor    
,unsigned short Width             
)
{
	LT768_DrawEllipse_Fill(XCenter,YCenter,X_R+Width,Y_R+Width,EllipseColor);
	LT768_DrawEllipse_Fill(XCenter,YCenter,X_R,Y_R,ForegroundColor);
}




void LT768_DrawSquare
(
 unsigned short X1                
,unsigned short Y1                
,unsigned short X2                
,unsigned short Y2                
,unsigned long SquareColor        
)
{
	Foreground_color_65k(SquareColor);
	Square_Start_XY(X1,Y1);
  Square_End_XY(X2,Y2);
  Start_Square();
  Check_2D_Busy(); 
}


void LT768_DrawSquare_Fill
(
 unsigned short X1                
,unsigned short Y1                
,unsigned short X2                
,unsigned short Y2                
,unsigned long ForegroundColor    
)
{
	Foreground_color_65k(ForegroundColor);
  Square_Start_XY(X1,Y1);
  Square_End_XY(X2,Y2);
  Start_Square_Fill();
  Check_2D_Busy();
}


void LT768_DrawSquare_Width
(
 unsigned short X1                
,unsigned short Y1                
,unsigned short X2                
,unsigned short Y2                
,unsigned long SquareColor        
,unsigned long ForegroundColor    
,unsigned short Width             
)
{
	LT768_DrawSquare_Fill(X1-Width,Y1-Width,X2+Width,Y2+Width,SquareColor);
	LT768_DrawSquare_Fill(X1,Y1,X2,Y2,ForegroundColor);
}



void LT768_DrawCircleSquare
(
 unsigned short X1                
,unsigned short Y1                
,unsigned short X2                
,unsigned short Y2                
,unsigned short X_R               
,unsigned short Y_R               
,unsigned long CircleSquareColor  
)
{
	Foreground_color_65k(CircleSquareColor);
  Square_Start_XY(X1,Y1);
  Square_End_XY(X2,Y2); 
  Circle_Square_Radius_RxRy(X_R,Y_R);
  Start_Circle_Square();
  Check_2D_Busy();
}



void LT768_DrawCircleSquare_Fill
(
 unsigned short X1                
,unsigned short Y1                
,unsigned short X2                
,unsigned short Y2                
,unsigned short X_R               
,unsigned short Y_R               
,unsigned long ForegroundColor  
)
{
	Foreground_color_65k(ForegroundColor);
  Square_Start_XY(X1,Y1);
  Square_End_XY(X2,Y2); 
  Circle_Square_Radius_RxRy(X_R,Y_R);
  Start_Circle_Square_Fill();
  Check_2D_Busy(); 
}



void LT768_DrawCircleSquare_Width
(
 unsigned short X1                
,unsigned short Y1                
,unsigned short X2                
,unsigned short Y2                
,unsigned short X_R               
,unsigned short Y_R               
,unsigned long CircleSquareColor  
,unsigned long ForegroundColor    
,unsigned short Width             
)
{
	LT768_DrawCircleSquare_Fill(X1-Width,Y1-Width,X2+Width,Y2+Width,X_R,Y_R,CircleSquareColor);
	LT768_DrawCircleSquare_Fill(X1,Y1,X2,Y2,X_R,Y_R,ForegroundColor);
}



void LT768_DrawTriangle
(
 unsigned short X1              
,unsigned short Y1              
,unsigned short X2              
,unsigned short Y2              
,unsigned short X3              
,unsigned short Y3              
,unsigned long TriangleColor    
)
{
	Foreground_color_65k(TriangleColor);
	Triangle_Point1_XY(X1,Y1);
  Triangle_Point2_XY(X2,Y2);
  Triangle_Point3_XY(X3,Y3);
  Start_Triangle();
  Check_2D_Busy(); 
}



void LT768_DrawTriangle_Fill
(
 unsigned short X1              
,unsigned short Y1              
,unsigned short X2              
,unsigned short Y2              
,unsigned short X3              
,unsigned short Y3              
,unsigned long ForegroundColor  
)
{
	Foreground_color_65k(ForegroundColor);
	Triangle_Point1_XY(X1,Y1);
  Triangle_Point2_XY(X2,Y2);
  Triangle_Point3_XY(X3,Y3);
  Start_Triangle_Fill();
  Check_2D_Busy();
}




void LT768_DrawLeftUpCurve
( 
 unsigned short XCenter           
,unsigned short YCenter           
,unsigned short X_R               
,unsigned short Y_R               
,unsigned long CurveColor         
)
{
	Foreground_color_65k(CurveColor);
  Ellipse_Center_XY(XCenter,YCenter);
  Ellipse_Radius_RxRy(X_R,Y_R);
  Start_Left_Up_Curve();
  Check_2D_Busy(); 
}


void LT768_DrawLeftDownCurve
(
 unsigned short XCenter           
,unsigned short YCenter           
,unsigned short X_R               
,unsigned short Y_R               
,unsigned long CurveColor         
)
{
	Foreground_color_65k(CurveColor);
  Ellipse_Center_XY(XCenter,YCenter);
  Ellipse_Radius_RxRy(X_R,Y_R);
  Start_Left_Down_Curve();
  Check_2D_Busy(); 
}


void LT768_DrawRightUpCurve
(
 unsigned short XCenter           
,unsigned short YCenter           
,unsigned short X_R               
,unsigned short Y_R               
,unsigned long CurveColor         
)
{
	Foreground_color_65k(CurveColor);
  Ellipse_Center_XY(XCenter,YCenter);
  Ellipse_Radius_RxRy(X_R,Y_R);
  Start_Right_Up_Curve();
  Check_2D_Busy(); 
}


void LT768_DrawRightDownCurve
(
 unsigned short XCenter           
,unsigned short YCenter           
,unsigned short X_R               
,unsigned short Y_R               
,unsigned long CurveColor         
)
{
	Foreground_color_65k(CurveColor);
  Ellipse_Center_XY(XCenter,YCenter);
  Ellipse_Radius_RxRy(X_R,Y_R);
  Start_Right_Down_Curve();
  Check_2D_Busy(); 
}


void LT768_SelectDrawCurve
(
 unsigned short XCenter           
,unsigned short YCenter           
,unsigned short X_R               
,unsigned short Y_R               
,unsigned long CurveColor         
,unsigned short  Dir              
)
{
	switch(Dir)
	{
		case 0:LT768_DrawLeftDownCurve(XCenter,YCenter,X_R,Y_R,CurveColor);		break;
		case 1:LT768_DrawLeftUpCurve(XCenter,YCenter,X_R,Y_R,CurveColor);			break;
		case 2:LT768_DrawRightUpCurve(XCenter,YCenter,X_R,Y_R,CurveColor);		break;
		case 3:LT768_DrawRightDownCurve(XCenter,YCenter,X_R,Y_R,CurveColor);	break;
		default:																															break;
	}
}



void LT768_DrawLeftUpCurve_Fill
(
 unsigned short XCenter           
,unsigned short YCenter           
,unsigned short X_R               
,unsigned short Y_R               
,unsigned long ForegroundColor    
)
{
  Foreground_color_65k(ForegroundColor);
  Ellipse_Center_XY(XCenter,YCenter);
  Ellipse_Radius_RxRy(X_R,Y_R);
  Start_Left_Up_Curve_Fill();
  Check_2D_Busy(); 
}


void LT768_DrawLeftDownCurve_Fill
(
 unsigned short XCenter           
,unsigned short YCenter           
,unsigned short X_R               
,unsigned short Y_R               
,unsigned long ForegroundColor    
)
{
  Foreground_color_65k(ForegroundColor);
  Ellipse_Center_XY(XCenter,YCenter);
  Ellipse_Radius_RxRy(X_R,Y_R);
  Start_Left_Down_Curve_Fill();
  Check_2D_Busy(); 
}


void LT768_DrawRightUpCurve_Fill
(
 unsigned short XCenter           
,unsigned short YCenter           
,unsigned short X_R               
,unsigned short Y_R               
,unsigned long ForegroundColor    
)
{
  Foreground_color_65k(ForegroundColor);
  Ellipse_Center_XY(XCenter,YCenter);
  Ellipse_Radius_RxRy(X_R,Y_R);
  Start_Right_Up_Curve_Fill();
  Check_2D_Busy(); 
}


void LT768_DrawRightDownCurve_Fill
(
 unsigned short XCenter           
,unsigned short YCenter           
,unsigned short X_R               
,unsigned short Y_R               
,unsigned long ForegroundColor    
)
{
  Foreground_color_65k(ForegroundColor);
  Ellipse_Center_XY(XCenter,YCenter);
  Ellipse_Radius_RxRy(X_R,Y_R);
  Start_Right_Down_Curve_Fill();
  Check_2D_Busy(); 
}


void LT768_SelectDrawCurve_Fill
(
 unsigned short XCenter           
,unsigned short YCenter           
,unsigned short X_R               
,unsigned short Y_R               
,unsigned long CurveColor         
,unsigned short  Dir              
)
{
	switch(Dir)
	{
		case 0:LT768_DrawLeftDownCurve_Fill(XCenter,YCenter,X_R,Y_R,CurveColor);		break;
		case 1:LT768_DrawLeftUpCurve_Fill(XCenter,YCenter,X_R,Y_R,CurveColor);			break;
		case 2:LT768_DrawRightUpCurve_Fill(XCenter,YCenter,X_R,Y_R,CurveColor);			break;
		case 3:LT768_DrawRightDownCurve_Fill(XCenter,YCenter,X_R,Y_R,CurveColor);		break;
		default:																																		break;
	}
}





void LT768_DrawQuadrilateral
(
 unsigned short X1              
,unsigned short Y1              
,unsigned short X2              
,unsigned short Y2              
,unsigned short X3              
,unsigned short Y3              
,unsigned short X4              
,unsigned short Y4              
,unsigned long ForegroundColor  
)
{
	Foreground_color_65k(ForegroundColor);
	Triangle_Point1_XY(X1,Y1);
  Triangle_Point2_XY(X2,Y2);
  Triangle_Point3_XY(X3,Y3);
	Ellipse_Radius_RxRy(X4,Y4);
	
	LCD_CmdWrite(0x67);
	LCD_DataWrite(0x8d);
	Check_Busy_Draw();
	
	Check_2D_Busy(); 
}


void LT768_DrawQuadrilateral_Fill
(
 unsigned short X1              
,unsigned short Y1              
,unsigned short X2              
,unsigned short Y2              
,unsigned short X3              
,unsigned short Y3              
,unsigned short X4              
,unsigned short Y4              
,unsigned long ForegroundColor  
)
{
	Foreground_color_65k(ForegroundColor);
	Triangle_Point1_XY(X1,Y1);
  Triangle_Point2_XY(X2,Y2);
  Triangle_Point3_XY(X3,Y3);
	Ellipse_Radius_RxRy(X4,Y4);
	
	LCD_CmdWrite(0x67);
	LCD_DataWrite(0xa7);
	Check_Busy_Draw();
	
	Check_2D_Busy(); 
}





void LT768_DrawPentagon
(
 unsigned short X1              
,unsigned short Y1              
,unsigned short X2              
,unsigned short Y2              
,unsigned short X3              
,unsigned short Y3              
,unsigned short X4              
,unsigned short Y4              
,unsigned short X5              
,unsigned short Y5              
,unsigned long ForegroundColor  
)
{
	Foreground_color_65k(ForegroundColor);
	Triangle_Point1_XY(X1,Y1);
  Triangle_Point2_XY(X2,Y2);
  Triangle_Point3_XY(X3,Y3);
	Ellipse_Radius_RxRy(X4,Y4);
	Ellipse_Center_XY(X5,Y5);
	
	LCD_CmdWrite(0x67);
	LCD_DataWrite(0x8F);
	Check_Busy_Draw();
	
	Check_2D_Busy(); 
}


void LT768_DrawPentagon_Fill
(
 unsigned short X1              
,unsigned short Y1              
,unsigned short X2              
,unsigned short Y2              
,unsigned short X3              
,unsigned short Y3              
,unsigned short X4              
,unsigned short Y4              
,unsigned short X5              
,unsigned short Y5              
,unsigned long ForegroundColor  
)
{
	Foreground_color_65k(ForegroundColor);
	Triangle_Point1_XY(X1,Y1);
  Triangle_Point2_XY(X2,Y2);
  Triangle_Point3_XY(X3,Y3);
	Ellipse_Radius_RxRy(X4,Y4);
	Ellipse_Center_XY(X5,Y5);
	
	LCD_CmdWrite(0x67);
	LCD_DataWrite(0xa9);
	Check_Busy_Draw();
	
	Check_2D_Busy(); 
}



unsigned char LT768_DrawCylinder
(
 unsigned short XCenter           
,unsigned short YCenter           
,unsigned short X_R               
,unsigned short Y_R               
,unsigned short H                 
,unsigned long CylinderColor      
,unsigned long ForegroundColor    
)
{
	if(YCenter < H)	return 1;
	
	
	LT768_DrawEllipse_Fill(XCenter,YCenter,X_R,Y_R,ForegroundColor);
	LT768_DrawEllipse(XCenter,YCenter,X_R,Y_R,CylinderColor);
	
	
	LT768_DrawSquare_Fill(XCenter-X_R,YCenter-H,XCenter+X_R,YCenter,ForegroundColor);
	
	
	LT768_DrawEllipse_Fill(XCenter,YCenter-H,X_R,Y_R,ForegroundColor);
	LT768_DrawEllipse(XCenter,YCenter-H,X_R,Y_R,CylinderColor);
	
	LT768_DrawLine(XCenter-X_R,YCenter,XCenter-X_R,YCenter-H,CylinderColor);
	LT768_DrawLine(XCenter+X_R,YCenter,XCenter+X_R,YCenter-H,CylinderColor);
	
	return 0;
}



void LT768_DrawQuadrangular
(
 unsigned short X1
,unsigned short Y1
,unsigned short X2
,unsigned short Y2
,unsigned short X3
,unsigned short Y3
,unsigned short X4
,unsigned short Y4
,unsigned short X5
,unsigned short Y5
,unsigned short X6
,unsigned short Y6
,unsigned long QuadrangularColor   
,unsigned long ForegroundColor     
)
{
	LT768_DrawSquare_Fill(X1,Y1,X5,Y5,ForegroundColor);
	LT768_DrawSquare(X1,Y1,X5,Y5,QuadrangularColor);
	
	LT768_DrawQuadrilateral_Fill(X1,Y1,X2,Y2,X3,Y3,X4,Y4,ForegroundColor);
	LT768_DrawQuadrilateral(X1,Y1,X2,Y2,X3,Y3,X4,Y4,QuadrangularColor);
	
	LT768_DrawQuadrilateral_Fill(X3,Y3,X4,Y4,X5,Y5,X6,Y6,ForegroundColor);
	LT768_DrawQuadrilateral(X3,Y3,X4,Y4,X5,Y5,X6,Y6,QuadrangularColor);
}







void LT768_Color_Bar_ON(void)
{
	Color_Bar_ON();
}

void LT768_Color_Bar_OFF(void)
{
	Color_Bar_OFF();
}










void LT768_DMA_24bit_Linear
(
 unsigned char SCS              
,unsigned char Clk              
,unsigned long flash_addr       
,unsigned long memory_addr      
,unsigned long data_num         
)
{
	
	Enable_SFlash_SPI();									             
  if(SCS == 0)		Select_SFI_0();										 
  if(SCS == 1)		Select_SFI_1();										 
	
	Memory_Linear_Mode();
	Select_SFI_DMA_Mode();								             
	
	SPI_Clock_Period(Clk);                             
	SFI_DMA_Destination_Start_Address(memory_addr);  	 
	SFI_DMA_Transfer_Number(data_num);                 
	SFI_DMA_Source_Start_Address(flash_addr);          
	Check_Busy_SFI_DMA(); 
	Start_SFI_DMA();
	Check_Busy_SFI_DMA();
	Memory_XY_Mode();
}



void LT768_DMA_32bit_Linear
(
 unsigned char SCS              
,unsigned char Clk              
,unsigned long flash_addr       
,unsigned long memory_addr      
,unsigned long data_num         
)
{
	Enable_SFlash_SPI();									             
  if(SCS == 0)		Select_SFI_0();								     
  if(SCS == 1)		Select_SFI_1();										 
	
	Memory_Linear_Mode();
	Select_SFI_DMA_Mode();								            
	Select_SFI_32bit_Address();
	
	SPI_Clock_Period(Clk);                             
	SFI_DMA_Destination_Start_Address(memory_addr);  	 
	SFI_DMA_Transfer_Number(data_num);                 
	SFI_DMA_Source_Start_Address(flash_addr);          
	Check_Busy_SFI_DMA(); 
	Start_SFI_DMA();
	Check_Busy_SFI_DMA();
	Memory_XY_Mode();
}



void LT768_DMA_24bit_Block
(
 unsigned char SCS         
,unsigned char Clk         
,unsigned short X1         
,unsigned short Y1         
,unsigned short X_W        
,unsigned short Y_H        
,unsigned short P_W        
,unsigned long Addr        
)
{  

  Enable_SFlash_SPI();									          
  if(SCS == 0)	Select_SFI_0();										
  if(SCS == 1)	Select_SFI_1();									  
 
										   
  Select_SFI_DMA_Mode();								          
  SPI_Clock_Period(Clk);                          

  Goto_Pixel_XY(X1,Y1);									          
  SFI_DMA_Destination_Upper_Left_Corner(X1,Y1);		
  SFI_DMA_Transfer_Width_Height(X_W,Y_H);				  
  SFI_DMA_Source_Width(P_W);							        
  SFI_DMA_Source_Start_Address(Addr); 					  

  Start_SFI_DMA();									              
  Check_Busy_SFI_DMA();								            
}



void LT768_DMA_32bit_Block
(
 unsigned char SCS         
,unsigned char Clk         
,unsigned short X1         
,unsigned short Y1         
,unsigned short X_W        
,unsigned short Y_H        
,unsigned short P_W        
,unsigned long Addr        
)
{  

  Enable_SFlash_SPI();									
  if(SCS == 0)	Select_SFI_0();										       
  if(SCS == 1)	Select_SFI_1();										      
   
  Select_SFI_DMA_Mode();								  
  SPI_Clock_Period(Clk);

  Select_SFI_32bit_Address();							  

  Goto_Pixel_XY(X1,Y1);									  
  SFI_DMA_Destination_Upper_Left_Corner(X1,Y1);			
  SFI_DMA_Transfer_Width_Height(X_W,Y_H);				  
  SFI_DMA_Source_Width(P_W);							  
  SFI_DMA_Source_Start_Address(Addr); 						 

  Start_SFI_DMA();									  
  Check_Busy_SFI_DMA();								 
  Select_SFI_24bit_Address();
}







 
void LT768_Select_Internal_Font_Init
(
 unsigned char Size         
,unsigned char XxN          
,unsigned char YxN          
,unsigned char ChromaKey    
,unsigned char Alignment    
)
{
	if(Size==16)	Font_Select_8x16_16x16();
	if(Size==24)	Font_Select_12x24_24x24();
	if(Size==32)	Font_Select_16x32_32x32();

	
	if(XxN==1)	Font_Width_X1();
	if(XxN==2)	Font_Width_X2();
	if(XxN==3)	Font_Width_X3();
	if(XxN==4)	Font_Width_X4();

	
	if(YxN==1)	Font_Height_X1();
	if(YxN==2)	Font_Height_X2();
	if(YxN==3)	Font_Height_X3();
	if(YxN==4)	Font_Height_X4();

	
	if(ChromaKey==0)	Font_Background_select_Color();	
	if(ChromaKey==1)	Font_Background_select_Transparency();	

	
	if(Alignment==0)	Disable_Font_Alignment();
	if(Alignment==1)	Enable_Font_Alignment();
}


 
void LT768_Print_Internal_Font_String
(
 unsigned short x               
,unsigned short y               
,unsigned long FontColor        
,unsigned long BackGroundColor  
,char *c                        
)
{
  Text_Mode();
	CGROM_Select_Internal_CGROM();
  Foreground_color_65k(FontColor);
	Background_color_65k(BackGroundColor);
	Goto_Text_XY(x,y);
	Show_String(c);
}


 
void LT768_Select_Outside_Font_Init
(
 unsigned char SCS           
,unsigned char Clk           
,unsigned long FlashAddr     
,unsigned long MemoryAddr    
,unsigned long Num           
,unsigned char Size          
,unsigned char XxN           
,unsigned char YxN           
,unsigned char ChromaKey     
,unsigned char Alignment     
)
{
	if(Size==16)	Font_Select_8x16_16x16();
	if(Size==24)	Font_Select_12x24_24x24();
	if(Size==32)	Font_Select_16x32_32x32();

	
	if(XxN==1)	Font_Width_X1();
	if(XxN==2)	Font_Width_X2();
	if(XxN==3)	Font_Width_X3();
	if(XxN==4)	Font_Width_X4();

	
	if(YxN==1)	Font_Height_X1();
	if(YxN==2)	Font_Height_X2();
	if(YxN==3)	Font_Height_X3();
	if(YxN==4)	Font_Height_X4();

	
	if(ChromaKey==0)	Font_Background_select_Color();	
	if(ChromaKey==1)	Font_Background_select_Transparency();	

	
	if(Alignment==0)	Disable_Font_Alignment();
	if(Alignment==1)	Enable_Font_Alignment();	
	
	LT768_DMA_24bit_Linear(SCS,Clk,FlashAddr,MemoryAddr,Num);
	CGRAM_Start_address(MemoryAddr);        
}



 
void LT768_Print_Outside_Font_String
(
 unsigned short x               
,unsigned short y               
,unsigned long FontColor        
,unsigned long BackGroundColor  
,unsigned char *c               
)
{
	unsigned short temp_H = 0;
	unsigned short temp_L = 0;
	unsigned short temp = 0;
	unsigned long i = 0;
	
	Text_Mode();
	Font_Select_UserDefine_Mode();
  Foreground_color_65k(FontColor);
	Background_color_65k(BackGroundColor);
	Goto_Text_XY(x,y);
	
	while(c[i] != '\0')
  { 
		if(c[i] < 0xa1)
		{
			CGROM_Select_Internal_CGROM();   
			LCD_CmdWrite(0x04);
			LCD_DataWrite(c[i]);
			Check_Mem_WR_FIFO_not_Full();  
			i += 1;
		}
		else
		{
			Font_Select_UserDefine_Mode();   
			LCD_CmdWrite(0x04);
			temp_H = ((c[i] - 0xa1) & 0x00ff) * 94;
			temp_L = c[i+1] - 0xa1;
			temp = temp_H + temp_L + 0x8000;
			LCD_DataWrite((temp>>8)&0xff);
			Check_Mem_WR_FIFO_not_Full();
			LCD_DataWrite(temp&0xff);
			Check_Mem_WR_FIFO_not_Full();
			i += 2;		
		}
	}
	
  Check_2D_Busy();

  Graphic_Mode(); 
}




void LT768_Text_cursor_Init
(
 unsigned char On_Off_Blinking         
,unsigned short Blinking_Time          
,unsigned short X_W                    
,unsigned short Y_W                    
)
{
	if(On_Off_Blinking == 0)	Disable_Text_Cursor_Blinking();
	if(On_Off_Blinking == 1)	Enable_Text_Cursor_Blinking();

  Blinking_Time_Frames(Blinking_Time); 
	
  
  Text_Cursor_H_V(X_W,Y_W);
	
	Enable_Text_Cursor();
}


void LT768_Enable_Text_Cursor(void)
{
	Enable_Text_Cursor();
}


void LT768_Disable_Text_Cursor(void)
{
	Disable_Text_Cursor();
}


void LT768_Graphic_cursor_Init
(
 unsigned char Cursor_N                  
,unsigned char Color1                    
,unsigned char Color2                    
,unsigned short X_Pos                    
,unsigned short Y_Pos                    
,unsigned char *Cursor_Buf               
)
{
	unsigned int i ;
	
	Memory_Select_Graphic_Cursor_RAM(); 
	Graphic_Mode();
	
	switch(Cursor_N)
	{
		case 1:	Select_Graphic_Cursor_1();	break;
		case 2:	Select_Graphic_Cursor_2();	break;
		case 3:	Select_Graphic_Cursor_3();	break;
		case 4:	Select_Graphic_Cursor_4();	break;
		default:														break;
	}
	
	LCD_CmdWrite(0x04);
  for(i=0;i<256;i++)
  {					 
		LCD_DataWrite(Cursor_Buf[i]);
  }
	
	Memory_Select_SDRAM();
	Set_Graphic_Cursor_Color_1(Color1);
  Set_Graphic_Cursor_Color_2(Color2);
  Graphic_Cursor_XY(X_Pos,Y_Pos);
	
	Enable_Graphic_Cursor();
}


void LT768_Set_Graphic_cursor_Pos
(
 unsigned char Cursor_N                  
,unsigned short X_Pos                    
,unsigned short Y_Pos                    
)
{
	Graphic_Cursor_XY(X_Pos,Y_Pos);
	switch(Cursor_N)
	{
		case 1:	Select_Graphic_Cursor_1();	break;
		case 2:	Select_Graphic_Cursor_2();	break;
		case 3:	Select_Graphic_Cursor_3();	break;
		case 4:	Select_Graphic_Cursor_4();	break;
		default:														break;
	}
}


void LT768_Enable_Graphic_Cursor(void)
{
	Enable_Graphic_Cursor();
}


void LT768_Disable_Graphic_Cursor(void)
{
	Disable_Graphic_Cursor();
}




void LT768_PIP_Init
(
 unsigned char On_Off         
,unsigned char Select_PIP     
,unsigned long PAddr          
,unsigned short XP            
,unsigned short YP            
,unsigned long ImageWidth     
,unsigned short X_Dis         
,unsigned short Y_Dis         
,unsigned short X_W           
,unsigned short Y_H           
)
{
	if(Select_PIP == 1 )  
	{
		Select_PIP1_Window_16bpp();
		Select_PIP1_Parameter();
	}
	if(Select_PIP == 2 )  
	{
		Select_PIP2_Window_16bpp();
		Select_PIP2_Parameter();
	}
	
	PIP_Display_Start_XY(X_Dis,Y_Dis);
	PIP_Image_Start_Address(PAddr);
	PIP_Image_Width(ImageWidth);
	PIP_Window_Image_Start_XY(XP,YP);
	PIP_Window_Width_Height(X_W,Y_H);

	if(On_Off == 0)
  {
  	if(Select_PIP == 1 )  Disable_PIP1();	
		if(Select_PIP == 2 )  Disable_PIP2();
	}

  if(On_Off == 1)
  {
		if(Select_PIP == 1 )  Enable_PIP1();	
		if(Select_PIP == 2 )  Enable_PIP2();
	}
}


void LT768_Set_DisWindowPos
(
 unsigned char On_Off         
,unsigned char Select_PIP     
,unsigned short X_Dis         
,unsigned short Y_Dis         
)
{
	if(Select_PIP == 1 )  Select_PIP1_Parameter();
	if(Select_PIP == 2 )  Select_PIP2_Parameter();
	
	if(On_Off == 0)
  {
  	if(Select_PIP == 1 )  Disable_PIP1();	
		if(Select_PIP == 2 )  Disable_PIP2();
	}

  if(On_Off == 1)
  {
		if(Select_PIP == 1 )  Enable_PIP1();	
		if(Select_PIP == 2 )  Enable_PIP2();
	}
	
	PIP_Display_Start_XY(X_Dis,Y_Dis);
	
}








void BTE_Solid_Fill
(
 unsigned long Des_Addr           
,unsigned short Des_W             
,unsigned short XDes              
,unsigned short YDes              
,unsigned short color             
,unsigned short X_W               
,unsigned short Y_H               
)            
{
	
	BTE_Destination_Color_16bpp();
	
  BTE_Destination_Memory_Start_Address(Des_Addr);
    
  BTE_Destination_Image_Width(Des_W);
  BTE_Destination_Window_Start_XY(XDes,YDes);
  BTE_Window_Size(X_W,Y_H);
    
  Foreground_color_65k(color);
  BTE_Operation_Code(0x0c);
  BTE_Enable();
  Check_BTE_Busy();     
}

 
void LT768_BTE_Memory_Copy
(
 unsigned long S0_Addr     
,unsigned short S0_W       
,unsigned short XS0        
,unsigned short YS0        
,unsigned long S1_Addr     
,unsigned short S1_W       
,unsigned short XS1        
,unsigned short YS1        
,unsigned long Des_Addr    
,unsigned short Des_W      
,unsigned short XDes       
,unsigned short YDes       
,unsigned int ROP_Code     
















 
,unsigned short X_W       
,unsigned short Y_H       
)
{
	BTE_S0_Color_16bpp();
	BTE_S0_Memory_Start_Address(S0_Addr);
  BTE_S0_Image_Width(S0_W);
  BTE_S0_Window_Start_XY(XS0,YS0);

	BTE_S1_Color_16bpp();
  BTE_S1_Memory_Start_Address(S1_Addr);
  BTE_S1_Image_Width(S1_W); 
  BTE_S1_Window_Start_XY(XS1,YS1);

	BTE_Destination_Color_16bpp();
  BTE_Destination_Memory_Start_Address(Des_Addr);
  BTE_Destination_Image_Width(Des_W);
  BTE_Destination_Window_Start_XY(XDes,YDes);	
   
  BTE_ROP_Code(ROP_Code);	
  BTE_Operation_Code(0x02); 
  BTE_Window_Size(X_W,Y_H); 
  BTE_Enable();
  Check_BTE_Busy();
}


 
void LT768_BTE_Memory_Copy_Chroma_key
(
 unsigned long S0_Addr             
,unsigned short S0_W               
,unsigned short XS0                
,unsigned short YS0                
,unsigned long Des_Addr            
,unsigned short Des_W              
,unsigned short XDes               
,unsigned short YDes               
,unsigned long Background_color    
,unsigned short X_W                
,unsigned short Y_H                
)
{
	Background_color_65k(Background_color); 
	
	BTE_S0_Color_16bpp();
  BTE_S0_Memory_Start_Address(S0_Addr);
  BTE_S0_Image_Width(S0_W);
  BTE_S0_Window_Start_XY(XS0,YS0);	

	BTE_Destination_Color_16bpp();
  BTE_Destination_Memory_Start_Address(Des_Addr);
  BTE_Destination_Image_Width(Des_W);
  BTE_Destination_Window_Start_XY(XDes,YDes);
   
  BTE_Operation_Code(0x05);	
  BTE_Window_Size(X_W,Y_H); 
  BTE_Enable();
  Check_BTE_Busy();
}


void LT768_BTE_Pattern_Fill
(
 unsigned char P_8x8_or_16x16      
,unsigned long S0_Addr             
,unsigned short S0_W               
,unsigned short XS0                
,unsigned short YS0                
,unsigned long Des_Addr            
,unsigned short Des_W              
, unsigned short XDes              
,unsigned short YDes               
,unsigned int ROP_Code             
















 
,unsigned short X_W                
,unsigned short Y_H                
)
{
	if(P_8x8_or_16x16 == 0)
  {
		Pattern_Format_8X8();
  }
  if(P_8x8_or_16x16 == 1)
  {														    
		Pattern_Format_16X16();
  }	
	
	BTE_S0_Color_16bpp();
  BTE_S0_Memory_Start_Address(S0_Addr);
  BTE_S0_Image_Width(S0_W);
  BTE_S0_Window_Start_XY(XS0,YS0);

	BTE_Destination_Color_16bpp();
  BTE_Destination_Memory_Start_Address(Des_Addr);
  BTE_Destination_Image_Width(Des_W);
  BTE_Destination_Window_Start_XY(XDes,YDes);	
   
  BTE_ROP_Code(ROP_Code);	
  BTE_Operation_Code(0x06); 
  BTE_Window_Size(X_W,Y_H); 
  BTE_Enable();
  Check_BTE_Busy();
}



void LT768_BTE_Pattern_Fill_With_Chroma_key
(
 unsigned char P_8x8_or_16x16      
,unsigned long S0_Addr             
,unsigned short S0_W               
,unsigned short XS0                
,unsigned short YS0                
,unsigned long Des_Addr            
,unsigned short Des_W              
,unsigned short XDes               
,unsigned short YDes               
,unsigned int ROP_Code             
















 
,unsigned long Background_color   
,unsigned short X_W               
,unsigned short Y_H               
)
{
	Background_color_65k(Background_color);
	
	if(P_8x8_or_16x16 == 0)
  {
  Pattern_Format_8X8();
   }
  if(P_8x8_or_16x16 == 1)
  {														    
  Pattern_Format_16X16();
  }	  
	
	BTE_S0_Color_16bpp();
  BTE_S0_Memory_Start_Address(S0_Addr);
  BTE_S0_Image_Width(S0_W);
  BTE_S0_Window_Start_XY(XS0,YS0);

	BTE_Destination_Color_16bpp();
  BTE_Destination_Memory_Start_Address(Des_Addr);
  BTE_Destination_Image_Width(Des_W);
  BTE_Destination_Window_Start_XY(XDes,YDes);	
   
  BTE_ROP_Code(ROP_Code);	
  BTE_Operation_Code(0x07); 
  BTE_Window_Size(X_W,Y_H); 
  BTE_Enable();
  Check_BTE_Busy();
}

void LT768_BTE_MCU_Write_MCU_16bit
(
 unsigned long S1_Addr              
,unsigned short S1_W                
,unsigned short XS1                 
,unsigned short YS1                 
,unsigned long Des_Addr             
,unsigned short Des_W               
,unsigned short XDes                
,unsigned short YDes                
,unsigned int ROP_Code              
















 
,unsigned short X_W                 
,unsigned short Y_H                 
,const unsigned short *data         
)
{
	unsigned short i,j;

	BTE_S1_Color_16bpp();
  BTE_S1_Memory_Start_Address(S1_Addr);
  BTE_S1_Image_Width(S1_W); 
  BTE_S1_Window_Start_XY(XS1,YS1);

	BTE_Destination_Color_16bpp();
  BTE_Destination_Memory_Start_Address(Des_Addr);
  BTE_Destination_Image_Width(Des_W);
  BTE_Destination_Window_Start_XY(XDes,YDes);
  
  BTE_Window_Size(X_W,Y_H);
  BTE_ROP_Code(ROP_Code);
  BTE_Operation_Code(0x00);		
  BTE_Enable();
	
	BTE_S0_Color_16bpp();
	LCD_CmdWrite(0x04);				 		
	
	
	for(i=0;i< Y_H;i++)
	{	
		for(j=0;j< (X_W);j++)
 	  {
			Check_Mem_WR_FIFO_not_Full();
			LCD_DataWrite_Pixel((*data));
			data++;
	  }
  }
  Check_Mem_WR_FIFO_Empty();
	Check_BTE_Busy();
}



void LT768_BTE_MCU_Write_Chroma_key_MCU_16bit
(
 unsigned long Des_Addr                 
,unsigned short Des_W                   
,unsigned short XDes                    
,unsigned short YDes                    
,unsigned long Background_color         
,unsigned short X_W                     
,unsigned short Y_H                     
,const unsigned short *data             
)
{
	unsigned int i,j;
	
	Background_color_65k(Background_color);
	
	BTE_Destination_Color_16bpp();
	BTE_Destination_Memory_Start_Address(Des_Addr);
  BTE_Destination_Image_Width(Des_W);
  BTE_Destination_Window_Start_XY(XDes,YDes);
  
  BTE_Window_Size(X_W,Y_H);
  BTE_Operation_Code(0x04);		
  BTE_Enable();
	
	BTE_S0_Color_16bpp();
  LCD_CmdWrite(0x04);			
	
	
	for(i=0;i< Y_H;i++)
	{	
		for(j=0;j< (X_W);j++)
 	  {
			Check_Mem_WR_FIFO_not_Full();
			LCD_DataWrite_Pixel((*data));
			data++;
	  }
  }
  Check_Mem_WR_FIFO_Empty();
	Check_BTE_Busy();
}



 
void LT768_BTE_MCU_Write_ColorExpansion_MCU_16bit
(
 unsigned long Des_Addr               
,unsigned short Des_W                 
,unsigned short XDes                  
,unsigned short YDes                  
,unsigned short X_W                   
,unsigned short Y_H                   
,unsigned long Foreground_color 
 
,unsigned long Background_color 
 
,const unsigned short *data           
)
{
	unsigned short i,j;
	
	RGB_16b_16bpp();
  Foreground_color_65k(Foreground_color);
  Background_color_65k(Background_color);
	BTE_ROP_Code(15);
	
	BTE_Destination_Color_16bpp();
	BTE_Destination_Memory_Start_Address(Des_Addr);
  BTE_Destination_Image_Width(Des_W);
  BTE_Destination_Window_Start_XY(XDes,YDes);
	

  BTE_Window_Size(X_W,Y_H);
  BTE_Operation_Code(0x8);		
  BTE_Enable();
	
	LCD_CmdWrite(0x04);				 		
	for(i=0;i< Y_H;i++)
  {	
	  for(j=0;j< X_W/16;j++)
 	  {
	    Check_Mem_WR_FIFO_not_Full();
		  LCD_DataWrite_Pixel(*data);  
	    data++;
	  }
  }
  Check_Mem_WR_FIFO_Empty();
	Check_BTE_Busy();
}



 
void LT768_BTE_MCU_Write_ColorExpansion_Chroma_key_MCU_16bit
(
 unsigned long Des_Addr 
,unsigned short Des_W 
,unsigned short XDes 
,unsigned short YDes 
,unsigned short X_W 
,unsigned short Y_H 
,unsigned long Foreground_color
 
,const unsigned short *data 
)
{
	unsigned short i,j;
	
	RGB_16b_16bpp();
  Foreground_color_65k(Foreground_color);
	BTE_ROP_Code(15);
	
	BTE_Destination_Color_16bpp();
	BTE_Destination_Memory_Start_Address(Des_Addr);
  BTE_Destination_Image_Width(Des_W);
  BTE_Destination_Window_Start_XY(XDes,YDes);
	

  BTE_Window_Size(X_W,Y_H);
	BTE_Operation_Code(0x9);		
  BTE_Enable();
	
	LCD_CmdWrite(0x04);				 		
	for(i=0;i< Y_H;i++)
  {	
	  for(j=0;j< X_W/16;j++)
 	  {
	    Check_Mem_WR_FIFO_not_Full();
		  LCD_DataWrite_Pixel(*data);  
	    data++;
	  }
  }
  Check_Mem_WR_FIFO_Empty();
	Check_BTE_Busy();
}

















 
void BTE_Alpha_Blending
(
 unsigned long S0_Addr
 ,unsigned short S0_W
 ,unsigned short XS0
 ,unsigned short YS0
 ,unsigned long S1_Addr
 ,unsigned short S1_W
 ,unsigned short XS1
 ,unsigned short YS1
 ,unsigned long Des_Addr
 ,unsigned short Des_W
 ,unsigned short XDes
 ,unsigned short YDes
 ,unsigned short X_W
 ,unsigned short Y_H
 ,unsigned char alpha
)
{	
	BTE_S0_Color_16bpp();
  BTE_S0_Memory_Start_Address(S0_Addr);
  BTE_S0_Image_Width(S0_W);
  BTE_S0_Window_Start_XY(XS0,YS0);

	BTE_S1_Color_16bpp();
  BTE_S1_Memory_Start_Address(S1_Addr);
  BTE_S1_Image_Width(S1_W); 
  BTE_S1_Window_Start_XY(XS1,YS1);

	BTE_Destination_Color_16bpp();
  BTE_Destination_Memory_Start_Address(Des_Addr);
  BTE_Destination_Image_Width(Des_W);
  BTE_Destination_Window_Start_XY(XDes,YDes);

  BTE_Window_Size(X_W,Y_H);
  BTE_Operation_Code(0x0A);		
  BTE_Alpha_Blending_Effect(alpha);
  BTE_Enable();
  Check_BTE_Busy();
}
const int xs=20;
const int ys=20;
const uint16_t dateRecord0_x=20;
const uint16_t dateRecord0_y=20;
const uint16_t OrgXset=130;	
const uint16_t OrgYset=570;



void Show(void)
{
	uint16_t i,j;
	uint16_t yn;	
  
	Select_Main_Window_16bpp();
	
	Canvas_Image_Start_address(1024*600*2);
	Canvas_image_width(1024);
  Active_Window_XY(0,0);
	Active_Window_WH(1024,600);			
	LT768_DrawSquare_Fill(0,0,1023,599,0x051F);
	
	LT768_DrawCircleSquare_Fill( xs+100,ys,xs+250,ys+60,10,10,0xF800);
  LT768_DrawCircleSquare_Fill( xs,     ys+100, xs+100, ys+160,10,10,0x3f80);
  LT768_DrawCircleSquare_Fill( xs+160, ys+100, xs+260, ys+160,10,10,0x3f80);
	LT768_DrawCircleSquare_Fill( xs+320, ys+100, xs+420, ys+160,10,10,0x3f80);
	LT768_DrawCircleSquare_Fill( xs+320, ys+  0, xs+420, ys+ 60,10,10,0x3f80);
	LT768_Select_Internal_Font_Init(32,1,1,1,0);
	LT768_Print_Internal_Font_String(xs+5,ys+120,0xF800,0x07E0," Hhgh ");
	LT768_Print_Internal_Font_String(xs+5+160,ys+120,0xF800,0x07E0," Low ");
	LT768_Print_Internal_Font_String(xs+5+320,ys+120,0xF800,0x07E0," quit ");
	LT768_Print_Internal_Font_String(xs+5+320,ys+20,0xF800,0x07E0,"P/flow");
	LT768_DrawSquare_Fill( xs+30,ys+240,xs+380,ys+260,0xFFFF);			
	 
	LT768_DrawSquare_Fill(  0, 400,799, 579,0x0f1f);		
	
	for (i=0;i<8;i++)
	    {
			 for (j=0;j<2;j++)
				   {
						 LT768_DrawCircleSquare_Fill( 20+i*100, 420+j*80, 89+i*100, 469+j*80,10,10,0x3f80);
					 } 
			}
	LT768_Select_Internal_Font_Init(32,1,1,1,0);
	LT768_Print_Internal_Font_String( 30,425,0xF800,0x07E0,"P00");
  LT768_Print_Internal_Font_String( 30,505,0xF800,0x07E0,"P20");
	LT768_Print_Internal_Font_String(125,425,0xF800,0x07E0,"PI00");
  LT768_Print_Internal_Font_String(125,505,0xF800,0x07E0,"PI20");
  LT768_Print_Internal_Font_String(230,425,0xF800,0x07E0,"O21");
  LT768_Print_Internal_Font_String(225,505,0xF800,0x07E0,"O100");
	LT768_Print_Internal_Font_String(325,425,0xF800,0x07E0,"V198");
  LT768_Print_Internal_Font_String(325,505,0xF800,0x07E0,"V242");
	LT768_Print_Internal_Font_String(425,425,0xF800,0x07E0,"O280");
  LT768_Print_Internal_Font_String(425,505,0xF800,0x07E0,"O600");
	LT768_Print_Internal_Font_String(525,425,0xF800,0x07E0,"A280");
  LT768_Print_Internal_Font_String(525,505,0xF800,0x07E0,"A600");
	LT768_Select_Internal_Font_Init(24,1,1,1,0);		
	LT768_Print_Internal_Font_String(620,430,0xF800,0x07E0,"Vt0.3");
	LT768_Print_Internal_Font_String(620,510,0xF800,0x07E0,"ClrWT");			
	LT768_Print_Internal_Font_String(725,430,0xF800,0x07E0,"En/Ch");
	LT768_Select_Internal_Font_Init(24,2,2,1,0);	
	LT768_Print_Internal_Font_String(740,505,0xFFFF,0x07E0,"X");
			
	for (i=0;i<3;i++)
	    {
			 for (j=0;j<2;j++)
				   {
						 LT768_DrawCircleSquare_Fill(530+i*130, 220+j*100,610+i*130, 270+j*100,10,10,0x70f6);
					 } 
			}
	
	LT768_Select_Internal_Font_Init(24,1,1,1,0);
	LT768_Print_Internal_Font_String(530,10,0x07E0,0x07E0,"Year");
	LT768_Print_Internal_Font_String(660,10,0x07E0,0x07E0,"Month");
	LT768_Print_Internal_Font_String(790,10,0x07E0,0x07E0,"Day");
	LT768_Print_Internal_Font_String(530,70,0x07E0,0x07E0,"Hour");
	LT768_Print_Internal_Font_String(650,70,0x07E0,0x07E0,"Minute");
	LT768_Print_Internal_Font_String(780,70,0x07E0,0x07E0,"Second");
	LT768_Select_Internal_Font_Init(32,1,1,1,0);
	LT768_Print_Internal_Font_String(550,150,0x07E0,0x07E0,"+");
	LT768_Print_Internal_Font_String(680,150,0x07E0,0x07E0,"-");
	LT768_Print_Internal_Font_String(780,150,0x07E0,0x07E0,"enter");
	
	Canvas_Image_Start_address(1024*600*2*2);
	Canvas_image_width(1024);
  Active_Window_XY(0,0);
	Active_Window_WH(1024,600);			
	LT768_DrawSquare_Fill(0,0,1024-1,600-1,0x2108);
	
	for (yn=dateRecord0_y; yn<301; yn+=35)
	{
		Lines(dateRecord0_x,yn,dateRecord0_x+484,yn,0xFFFF);  
	}
    Lines( dateRecord0_x,dateRecord0_y, dateRecord0_x,dateRecord0_y+280,0xFFFF);
    Lines( dateRecord0_x+40,dateRecord0_y, dateRecord0_x+40,dateRecord0_y+280,0xFFFF); 
    Lines( dateRecord0_x+160,dateRecord0_y, dateRecord0_x+160,dateRecord0_y+280,0xFFFF);
    Lines( dateRecord0_x+484,dateRecord0_y, dateRecord0_x+484,dateRecord0_y+280,0xFFFF);
	
	LT768_DrawSquare_Fill(600,0,1020,320,0x051F);
	for (i=0;i<3;i++)
	    {
			 for (j=0;j<4;j++)
				   {
						 LT768_DrawCircleSquare_Fill( xs+j*100+600, ys+70+i*80,xs+670+j*100, ys+120+i*80,10,10,0x07f6);
					 } 
			}
	LT768_Select_Internal_Font_Init(24,2,2,1,0);
	LT768_Print_Internal_Font_String(xs+630,ys,0xF800,0x07E0,"X");		
	LT768_DrawCircleSquare_Fill( xs+820,ys,xs+940,ys+50,10,10,0x0806);		
	LT768_Select_Internal_Font_Init(32,1,1,1,0);  		
  LT768_Print_Internal_Font_String(xs+630,ys+80,0xF800,0x07E0,"1");
	LT768_Print_Internal_Font_String(xs+630+100,ys+80,0xF800,0x07E0,"2");
  LT768_Print_Internal_Font_String(xs+630+100*2,ys+80,0xF800,0x07E0,"3");	
	LT768_Print_Internal_Font_String(xs+630,ys+80+80,0xF800,0x07E0,"4");
	LT768_Print_Internal_Font_String(xs+630+100,ys+80+80,0xF800,0x07E0,"5");
  LT768_Print_Internal_Font_String(xs+630+100*2,ys+80+80,0xF800,0x07E0,"6");
	LT768_Print_Internal_Font_String(xs+630,ys+80+80*2,0xF800,0x07E0,"7");
	LT768_Print_Internal_Font_String(xs+630+100,ys+80+80*2,0xF800,0x07E0,"8");
  LT768_Print_Internal_Font_String(xs+630+100*2,ys+80+80*2,0xF800,0x07E0,"9");
	LT768_Print_Internal_Font_String(xs+630+100*3,ys+80+80*2,0xF800,0x07E0,"0");
	LT768_Select_Internal_Font_Init(24,1,1,1,0);
	LT768_Print_Internal_Font_String(xs+605+100*3,ys+80+80,0xF800,0x07E0,"Enter");
	LT768_Print_Internal_Font_String(xs+605+100*3,ys+75,0xF800,0x07E0,"Back");
	LT768_Print_Internal_Font_String(xs+605+100*3,ys+95,0xF800,0x07E0,"space");
			
	for (i=0;i<2;i++)
	    {
			 for (j=0;j<5;j++)
				   {
						 LT768_DrawCircleSquare_Fill(50+j*150,380+i*100,150+j*150, 440+i*100,10,10,0x07f6);
					 } 
			}	
			
	Canvas_Image_Start_address(1024*600*2*3);
	Canvas_image_width(1024);
  Active_Window_XY(0,0);
	Active_Window_WH(1024,600);			
	LT768_DrawSquare_Fill(0,0,1023,599,0x2108);
  Lines(OrgXset,OrgYset,OrgXset+500,OrgYset,0xFFFF);  
  Lines(OrgXset,OrgYset-500,OrgXset,OrgYset,0xFFFF);  
	for(i=0;i<=500; i+=25)
    {
     Point(OrgXset+i,OrgYset+1,0xFFFF);
     Point(OrgXset+i,OrgYset+2,0xFFFF);
     if (i%50==0)	Point(OrgXset+i,OrgYset+3,0xFFFF);		
    }	
	for(i=0;i<=500; i+=25)
    {
     Point(OrgXset-1,OrgYset-500+i,0xFFFF);
     Point(OrgXset-2,OrgYset-500+i,0xFFFF);	
    }
		
	Canvas_Image_Start_address(1024*600*2*4);
	Canvas_image_width(1024);
  Active_Window_XY(0,0);
	Active_Window_WH(1024,600);			
	LT768_DrawSquare_Fill(0,0,1023,599,0x2108);
  Lines(OrgXset,OrgYset,OrgXset+500,OrgYset,0xFFFF);  
  Lines(OrgXset,OrgYset-500,OrgXset,OrgYset,0xFFFF);  
	for(i=0;i<=500; i+=25)
    {
     Point(OrgXset+i,OrgYset+1,0xFFFF);
     Point(OrgXset+i,OrgYset+2,0xFFFF);
     if (i%50==0)	Point(OrgXset+i,OrgYset+3,0xFFFF);		
    }	
	for(i=0;i<=500; i+=25)
    {
     Point(OrgXset-1,OrgYset-500+i,0xFFFF);
     Point(OrgXset-2,OrgYset-500+i,0xFFFF);	
    }
			
  Canvas_Image_Start_address(0);

	Main_Image_Start_Address(0);				
	Main_Image_Width(1024);
	Main_Window_Start_XY(0,0);
	Canvas_Image_Start_address(0);
	Canvas_image_width(1024);
  Active_Window_XY(0,0);
	Active_Window_WH(1024,600);			
	LT768_DrawSquare_Fill(0,0,1024-1,600-1,0);
}
