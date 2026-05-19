#include "stdint.h"
//分辨率
#define LCD_XSIZE_TFT    1024	
#define LCD_YSIZE_TFT    600
//参数
#define LCD_VBPD		 23  //9
#define LCD_VFPD	 	 12 //12
#define LCD_VSPW		 10 //15

#define LCD_HBPD		 160 //46
#define LCD_HFPD		 160 //210
#define LCD_HSPW	   120 //24

#define color256_black   0x00
#define color256_white   0xff
#define color256_red     0xe0
#define color256_green   0x1c
#define color256_blue    0x03
#define color256_yellow  color256_red|color256_green
#define color256_cyan    color256_green|color256_blue
#define color256_purple  color256_red|color256_blue
 
#define color65k_black   0x0000
#define color65k_white   0xffff
#define color65k_red     0xf800
#define color65k_green   0x07e0
#define color65k_blue    0x001f
#define color65k_yellow  color65k_red|color65k_green
#define color65k_cyan    color65k_green|color65k_blue
#define color65k_purple  color65k_red|color65k_blue

#define color65k_grayscale1    2113
#define color65k_grayscale2    2113*2
#define color65k_grayscale3    2113*3
#define color65k_grayscale4    2113*4
#define color65k_grayscale5    2113*5
#define color65k_grayscale6    2113*6
#define color65k_grayscale7    2113*7
#define color65k_grayscale8    2113*8
#define color65k_grayscale9    2113*9
#define color65k_grayscale10   2113*10
#define color65k_grayscale11   2113*11
#define color65k_grayscale12   2113*12
#define color65k_grayscale13   2113*13
#define color65k_grayscale14   2113*14
#define color65k_grayscale15   2113*15
#define color65k_grayscale16   2113*16
#define color65k_grayscale17   2113*17
#define color65k_grayscale18   2113*18
#define color65k_grayscale19   2113*19
#define color65k_grayscale20   2113*20
#define color65k_grayscale21   2113*21
#define color65k_grayscale22   2113*22
#define color65k_grayscale23   2113*23
#define color65k_grayscale24   2113*24
#define color65k_grayscale25   2113*25
#define color65k_grayscale26   2113*26
#define color65k_grayscale27   2113*27
#define color65k_grayscale28   2113*28
#define color65k_grayscale29   2113*29
#define color65k_grayscale30   2113*30

 
#define color16M_black   0x00000000
#define color16M_white   0x00ffffff
#define color16M_red     0x00ff0000
#define color16M_green   0x0000ff00
#define color16M_blue    0x000000ff
#define color16M_yellow  color16M_red|color16M_green
#define color16M_cyan    color16M_green|color16M_blue
#define color16M_purple  color16M_red|color16M_blue


/* LCD color */
#define White          0xFFFF
#define Black          0x0000
#define Grey           0xF7DE
#define Blue           0x001F
#define Blue2          0x051F
#define Red            0xF800
#define Magenta        0xF81F
#define Green          0x07E0
#define Cyan           0x7FFF
#define Yellow         0xFFE0

#define Line0          0
#define Line1          24
#define Line2          48
#define Line3          72
#define Line4          96
#define Line5          120
#define Line6          144
#define Line7          168
#define Line8          192
#define Line9          216
#define Line10         240
#define Line11         264
#define Line12         288
#define Line13         312
#define Line14         336
#define Line15         360
#define Line16         384
#define Line17         408
#define Line18         432
#define Line19         456
#define Line20         480

#define LCD_BASE0        	  ((uint32_t)0x60000000)
#define LCD_BASE1        	  ((uint32_t)0x60040004)
#define Picture_1_Addr	0                                  //图片1在FLASH的地址
#define Picture_2_Addr	(LCD_XSIZE_TFT*LCD_YSIZE_TFT*2)    //图片2在FLASH的地址
#define Picture_3_Addr	(LCD_XSIZE_TFT*LCD_YSIZE_TFT*4)    //图片3在FLASH的地址
#define Picture_4_Addr	(LCD_XSIZE_TFT*LCD_YSIZE_TFT*6)    //图片4在FLASH的地址
#define Picture_5_Addr	(LCD_XSIZE_TFT*LCD_YSIZE_TFT*8)    //图片5在FLASH的地址


#define layer1_start_addr 0                                //  图层在显存的位置
#define layer2_start_addr LCD_XSIZE_TFT*LCD_YSIZE_TFT*2    //  
#define layer3_start_addr LCD_XSIZE_TFT*LCD_YSIZE_TFT*2*2  //  
#define layer4_start_addr LCD_XSIZE_TFT*LCD_YSIZE_TFT*2*3  //  
#define layer5_start_addr LCD_XSIZE_TFT*LCD_YSIZE_TFT*2*4  //  
#define layer6_start_addr LCD_XSIZE_TFT*LCD_YSIZE_TFT*2*5  //  
#define layer7_start_addr LCD_XSIZE_TFT*LCD_YSIZE_TFT*2*6  //  

#define Resolution	(LCD_XSIZE_TFT*LCD_YSIZE_TFT)   //分辨率

void Show(void);
void LT768_Init(void);

void LT768_DrawSquare_Fill(uint16_t X1,uint16_t Y1,uint16_t X2,uint16_t Y2,unsigned long ForegroundColor);


void LT768_DMA_24bit_Block(uint8_t SCS,uint8_t Clk,uint16_t X1,uint16_t Y1 ,uint16_t X_W,uint16_t Y_H,uint16_t P_W,unsigned long Addr);

/*  PWM */
void LT768_PWM0_Init(uint8_t on_off,uint8_t Clock_Divided,uint8_t Prescalar,uint16_t Count_Buffer,uint16_t Compare_Buffer);
void LT768_PWM1_Init(uint8_t on_off,uint8_t Clock_Divided,uint8_t Prescalar,uint16_t Count_Buffer,uint16_t Compare_Buffer);
void LT768_PWM0_Duty(uint16_t Compare_Buffer);
void LT768_PWM1_Duty(uint16_t Compare_Buffer);

/******************** COPYRIGHT  ********************
* File Name       : LT738.h
* Author          : Levetop Electronics
* Version         : V1.0
* Date            : 2017-8-25
* Description     : 操作LT768的寄存器函数
****************************************************/

#define	cSetb0		0x01
#define	cSetb1		0x02
#define	cSetb2		0x04
#define	cSetb3		0x08
#define	cSetb4		0x10
#define	cSetb5		0x20
#define	cSetb6		0x40
#define	cSetb7		0x80

#define	cClrb0		0xfe
#define	cClrb1		0xfd
#define	cClrb2		0xfb
#define	cClrb3		0xf7
#define	cClrb4		0xef
#define	cClrb5		0xdf
#define	cClrb6		0xbf
#define	cClrb7		0x7f


void LCD_RegisterWrite(uint8_t Cmd,uint8_t Data);
uint8_t LCD_RegisterRead(uint8_t Cmd);


//void LT768_initial(void);
////Set PLL
//void LT768_PLL_Initial(void); 
////Set SDRAM 
//void LT768_SDRAM_initail(void);


/**Staus**/
void Check_Mem_WR_FIFO_not_Full(void);
void Check_2D_Busy(void);
void Check_SDRAM_Ready(void);
void Check_Mem_WR_FIFO_Empty(void);
void Check_Busy_Draw(void);

//**[00h]**//
void LT768_SW_Reset(void);
void TFT_16bit(void);

void Enable_SFlash_SPI(void);
void Disable_SFlash_SPI(void);
void Host_Bus_16bit(void);
//**[02h]**//


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


//**[13h]**//
void HSYNC_Low_Active(void);

void VSYNC_Low_Active(void);

void DE_High_Active(void);

void LCD_HorizontalWidth_VerticalHeight(uint16_t WX,uint16_t HY);
//**[16h][17h]**//
void LCD_Horizontal_Non_Display(uint16_t WX);
//**[18h]**//
void LCD_HSYNC_Start_Position(uint16_t WX);
//**[19h]**//
void LCD_HSYNC_Pulse_Width(uint16_t WX);
//**[1Ch][1Dh]**//
void LCD_Vertical_Non_Display(uint16_t HY);
//**[1Eh]**//
void LCD_VSYNC_Start_Position(uint16_t HY);
//**[1Fh]**//
void LCD_VSYNC_Pulse_Width(uint16_t HY);
//**[20h][21h][22h][23h]**//
void Main_Image_Start_Address(unsigned long Addr);
//**[24h][25h]**//					
void Main_Image_Width(uint16_t WX);							
//**[26h][27h][28h][29h]**//
void Main_Window_Start_XY(uint16_t WX,uint16_t HY);	
//**[2Ah][2Bh][2Ch][2Dh]**//
void PIP_Display_Start_XY(uint16_t WX,uint16_t HY);
//**[2Eh][2Fh][30h][31h]**//
void PIP_Image_Start_Address(unsigned long Addr);
//**[32h][33h]**//
void PIP_Image_Width(uint16_t WX);
//**[34h][35h][36h][37h]**//
void PIP_Window_Image_Start_XY(uint16_t WX,uint16_t HY);
//**[38h][39h][3Ah][3Bh]**//

void Canvas_Image_Start_address(unsigned long Addr);
//**[54h][55h]**//
void Canvas_image_width(uint16_t WX);
//**[56h][57h][58h][59h]**//
void Active_Window_XY(uint16_t WX,uint16_t HY);
//**[5Ah][5Bh][5Ch][5Dh]**//
void Active_Window_WH(uint16_t WX,uint16_t HY);
//**[5E]**//

void Memory_XY_Mode(void);
void Memory_16bpp_Mode(void);

void Goto_Pixel_XY(uint16_t WX,uint16_t HY);
	
void Square_Start_XY(uint16_t WX,uint16_t HY);		
void Square_End_XY(uint16_t WX,uint16_t HY);		
//**[76h]**//

void Start_Square_Fill(void);
void Point(uint16_t x,uint16_t y,uint16_t color);
void Lines(uint16_t x1 ,uint16_t y1 ,uint16_t x2,uint16_t y2,uint16_t color);
void Images(uint16_t x,uint16_t y,const char h[],uint16_t number,uint16_t color1,uint16_t color2); 

void ellipse(uint16_t x1 ,uint16_t y1 ,uint16_t r1,uint16_t r2,uint16_t color);
////////////////////////////////////////////////////////////////////////
////**** [ Function : PWM ] ****////
//**[84h]**//
void Set_PWM_Prescaler_1_to_256(uint16_t WX);
//**[85h]**//
void Select_PWM1_Clock_Divided_By_1(void);
void Select_PWM1_Clock_Divided_By_2(void);
void Select_PWM1_Clock_Divided_By_4(void);
void Select_PWM1_Clock_Divided_By_8(void);
void Select_PWM0_Clock_Divided_By_1(void);
void Select_PWM0_Clock_Divided_By_2(void);
void Select_PWM0_Clock_Divided_By_4(void);
void Select_PWM0_Clock_Divided_By_8(void);
//[85h].[bit3][bit2]
void Select_PWM1_is_ErrorFlag(void);
void Select_PWM1(void);
void Select_PWM0(void);

void Start_PWM1(void);
void Stop_PWM1(void);
//[86h]PWM0
void Start_PWM0(void);
void Stop_PWM0(void);
//**[87h]**//
void Set_Timer0_Compare_Buffer(uint16_t WX);
//**[8Ah][8Bh]**//
void Set_Timer0_Count_Buffer(uint16_t WX);
//**[8Ch][8Dh]**//
void Set_Timer1_Compare_Buffer(uint16_t WX);
//**[8Eh][8Fh]**//
void Set_Timer1_Count_Buffer(uint16_t WX);

//[91h]=========================================================================
void BTE_ROP_Code(unsigned char setx);
void BTE_Operation_Code(unsigned char setx);

////////////////////////////////////////////////////////////////////////
////**** [ Function : Serial Flash ] ****////


//REG[B6h] Serial flash DMA Controller REG (DMA_CTRL) 
void Start_SFI_DMA(void);
void Check_Busy_SFI_DMA(void);

//REG[B7h] Serial Flash/ROM Controller Register (SFL_CTRL) 
void Select_SFI_0(void);
void Select_SFI_1(void);
void Select_SFI_DMA_Mode(void);
void Select_SFI_Dual_Mode0(void);

//REG[B8h] SPI master Tx /Rx FIFO Data Register (SPIDR) 
unsigned char SPI_Master_FIFO_Data_Put(unsigned char Data);
unsigned char SPI_Master_FIFO_Data_Get(void);

//REG[BAh] SPI master Status Register (SPIMSR)
unsigned char Tx_FIFO_Empty_Flag(void);
unsigned char Tx_FIFO_Full_Flag(void);
unsigned char Rx_FIFO_Empty_Flag(void);
unsigned char Rx_FIFO_full_flag(void);
unsigned char OVFI_Flag(void);
void Clear_OVFI_Flag(void);
unsigned char EMTI_Flag(void);
void Clear_EMTI_Flag(void);

//REG[BB] SPI Clock period (SPIDIV) 
void SPI_Clock_Period(uint8_t temp);


//**[BCh][BDh][BEh][BFh]**//
void SFI_DMA_Source_Start_Address(unsigned long Addr);
//**[C0h][C1h][C2h][C3h]**//
void SFI_DMA_Destination_Upper_Left_Corner(uint16_t WX,uint16_t HY);
void SFI_DMA_Transfer_Width_Height(uint16_t WX,uint16_t HY);
//**[CAh][CBh]**//
void SFI_DMA_Source_Width(uint16_t WX);

void Foreground_color_65k(uint16_t temp);


/********************* COPYRIGHT  **********************
* File Name        : if_port.h
* Author           : Levetop Electronics
* Version          : V1.0
* Date             : 2017-9-11
* Description      : 选择不同的驱动接口
********************************************************/

void Parallel_Init(void);

void LCD_CmdWrite(uint8_t cmd);
void LCD_DataWrite(uint8_t data);
void LCD_DataWrite_Pixel(uint16_t data);
uint8_t LCD_StatusRead(void);
uint16_t LCD_DataRead(void);
	 
void Delay_us(uint16_t time);     // 延时函数us级
void Delay_ms(uint16_t time);     // 延时函数ms级

