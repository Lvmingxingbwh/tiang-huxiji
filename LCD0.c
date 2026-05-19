#include "LCD0.h"
#include "NuMicro.h"
#include <stdio.h>
#include "math.h"
#include <stdlib.h>

uint8_t CCLK;    // LT768的内核时钟频率    
uint8_t MCLK;    // SDRAM的时钟频率
uint8_t SCLK;    // LCD的扫描时钟频率
/********************* COPYRIGHT  **********************
* File Name        : if_port.c
* Author           : Levetop Electronics
* Version          : V1.0
* Date             : 2017-9-11
* Description      : 不同的驱动接口
********************************************************/

void LCD_CmdWrite(uint8_t cmd)
{	
	*(volatile uint16_t*) (LCD_BASE0)= (cmd);
}

void LCD_DataWrite(uint8_t data)
{
	*(volatile uint16_t*) (LCD_BASE1)= (data);
}

void LCD_DataWrite_Pixel(uint16_t data)
{
	*(volatile uint16_t*) (LCD_BASE1)= (data);
}


uint8_t LCD_StatusRead(void)
{
	uint8_t temp = 0;
	temp = *(volatile uint16_t*)(LCD_BASE0);
	return temp;
}

uint16_t LCD_DataRead(void)
{
	uint16_t temp = 0;	
	temp =  *(volatile uint16_t*)(LCD_BASE1);
	return temp;
}
void Delay_us(uint16_t time)
{    
   uint16_t i=0;  
   while(time--)
   {
      i=12;        //自己定义
      while(i--) ;    
   }
}

void Delay_ms(uint16_t time)
{    
   uint16_t i=0;  
   while(time--)
   {
      i=12000;    //自己定义
      while(i--) ;    
   }
}


//---------------------------------------------------------------------------------------------------------------------------------

//复位LT768
void LT768_HW_Reset(void)
{	
	
	PD14=0;
	Delay_ms(100);				   
  PD14=1;		 	 
  Delay_ms(100);	
}

//检查LT768系统
void System_Check_Temp(void)
{
	uint8_t i=0;
	uint8_t temp=0;
	uint8_t system_ok=0;
	do
	{
		if((LCD_StatusRead()&0x02)==0x00)    
		{
			Delay_ms(1);                  //若MCU 速度太快，必要時使用
			LCD_CmdWrite(0x01);
			Delay_ms(1);                  //若MCU 速度太快，必要時使用
			temp =LCD_DataRead();
			if((temp & 0x80)==0x80)       //检测CCR寄存器PLL是否准备好
			{
				system_ok=1;
				i=0;
			}
			else
			{
				Delay_ms(1); //若MCU 速度太快，必要時使用
				LCD_CmdWrite(0x01);
				Delay_ms(1); //若MCU 速度太快，必要時使用
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
			LT768_HW_Reset(); //note1
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
	
	temp = (LCD_HBPD + LCD_HFPD + LCD_HSPW + LCD_XSIZE_TFT) * (LCD_VBPD + LCD_VFPD + LCD_VSPW+LCD_YSIZE_TFT) * 60;   
	
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

	Delay_ms(1);	//单PLL铆
}


void LT768_SDRAM_initail(uint8_t mclk)
{
	uint16_t sdram_itv;
	
	LCD_RegisterWrite(0xe0,0x29);      
	LCD_RegisterWrite(0xe1,0x03);	//CAS:2=0x02CAS:3=0x03
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
	//**[01h]**//   
	TFT_16bit();	
	//TFT_18bit();
	//TFT_24bit(); 
	
	Host_Bus_16bit();	//主机总线16bit
      
	//**[02h]**//
	RGB_16b_16bpp();
	//RGB_16b_24bpp_mode1();
	MemWrite_Left_Right_Top_Down();	
	//MemWrite_Down_Top_Left_Right();
      
	//**[03h]**//
	Graphic_Mode();
	Memory_Select_SDRAM();
     
	PCLK_Falling();	       	//REG[12h]:下降沿 
	//PCLK_Rising();
	
	VSCAN_T_to_B();	        //REG[12h]:从上到下
	//VSCAN_B_to_T();				//从下到上
	
	PDATA_Set_RGB();        //REG[12h]:Select RGB output
	//PDATA_Set_RBG();
	//PDATA_Set_GRB();
	//PDATA_Set_GBR();
	//PDATA_Set_BRG();
	//PDATA_Set_BGR();

	HSYNC_Low_Active();     //REG[13h]:		  
	//HSYNC_High_Active();
	
	VSYNC_Low_Active();     //REG[13h]:			
	//VSYNC_High_Active();
	
	DE_High_Active();       //REG[13h]:	
	//DE_Low_Active();
 
	LCD_HorizontalWidth_VerticalHeight(LCD_XSIZE_TFT ,LCD_YSIZE_TFT);	
	LCD_Horizontal_Non_Display(LCD_HBPD);	                            
	LCD_HSYNC_Start_Position(LCD_HFPD);	                              
	LCD_HSYNC_Pulse_Width(LCD_HSPW);		                            	
	LCD_Vertical_Non_Display(LCD_VBPD);	                                
	LCD_VSYNC_Start_Position(LCD_VFPD);	                              
	LCD_VSYNC_Pulse_Width(LCD_VSPW);		                            	

	Memory_XY_Mode();	//Block mode (X-Y coordination addressing);块模式
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
	Delay_ms(100);                    //delay for LT768 power on
	LT768_HW_Reset();                 //LT768复位
	System_Check_Temp();	            //检测复位是否成功
	Delay_ms(100);
	while(LCD_StatusRead()&0x02);	    //Initial_Display_test	and  set SW2 pin2 = 1
	LT768_initial();
}

//----------------------------------------------------------------------------------------------------------------------------------

void LT768_PWM0_Init
(
 uint8_t on_off                       // 0：禁止PWM0    1：使能PWM0
,uint8_t Clock_Divided                // PWM时钟分频  取值范围 0~3(1,1/2,1/4,1/8)
,uint8_t Prescalar                    // 时钟分频     取值范围 1~256
,uint16_t Count_Buffer                // 设置PWM的输出周期
,uint16_t Compare_Buffer              // 设置占空比
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
 uint8_t on_off                       // 0：禁止PWM0    1：使能PWM0
,uint8_t Clock_Divided                // PWM时钟分频  取值范围 0~3(1,1/2,1/4,1/8)
,uint8_t Prescalar                    // 时钟分频     取值范围 1~256
,uint16_t Count_Buffer                // 设置PWM的输出周期
,uint16_t Compare_Buffer              // 设置占空比
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


/********************* COPYRIGHT  ***********************
* File Name       : LT768.c
* Author          : Levetop Electronics
* Version         : V1.0
* Date            : 2017-8-25
* Description     : 操作LT768的寄存器函数
				            具体操作哪个寄存器请看LT768.h文件
*********************************************************/
void LCD_RegisterWrite(uint8_t Cmd,uint8_t Data)
{
	LCD_CmdWrite(Cmd);
	LCD_DataWrite(Data);
}  
//---------------------//
uint8_t LCD_RegisterRead(uint8_t Cmd)
{
	uint8_t temp;
	
	LCD_CmdWrite(Cmd);
	temp=LCD_DataRead();
	return temp;
}

/******************************************************************************/
/*Sub program area		  													  */
/******************************************************************************/

void Check_Mem_WR_FIFO_not_Full(void)
{
/*	0: Memory Write FIFO is not full.
	1: Memory Write FIFO is full.		*/
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
/*	0: SDRAM is not ready for access
	1: SDRAM is ready for access		*/	
	uint8_t temp; 	
	do
	{
		temp=LCD_StatusRead();
	}
	while( (temp&0x04) == 0x00 );
}
void Check_Mem_WR_FIFO_Empty(void)
{
/*	0: Memory Write FIFO is not empty.
	1: Memory Write FIFO is empty.		*/	
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

//[00h]=========================================================================

void LT768_SW_Reset(void)//IC Reset
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

//[01h][01h][01h][01h][01h][01h][01h][01h][01h][01h][01h][01h][01h][01h][01h][01h]

void TFT_16bit(void)
{
/*  00b: 24-bits output.
    01b: 18-bits output, unused pins are set as GPIO.
    10b: 16-bits output, unused pins are set as GPIO.
    11b: LVDS, all 24-bits unused output pins are set as GPIO.*/
	uint8_t temp;
	LCD_CmdWrite(0x01);
	temp = LCD_DataRead();
	temp |= cSetb4;
    temp &= cClrb3;
	LCD_DataWrite(temp);  
}


void Enable_SFlash_SPI(void)
{
/*  Serial Flash SPI Interface Enable/Disable
    0: Disable
    1: Enable*/
	uint8_t temp;
	LCD_CmdWrite(0x01);
	temp = LCD_DataRead();
	temp |= cSetb1;
	LCD_DataWrite(temp);     
}

void Disable_SFlash_SPI(void)
{
/*  Serial Flash SPI Interface Enable/Disable
    0: Disable
    1: Enable*/
	uint8_t temp;
	LCD_CmdWrite(0x01);
	temp = LCD_DataRead();
	temp &= cClrb1;
	LCD_DataWrite(temp);     
}
void Host_Bus_16bit(void)
{
/*  Parallel Host Data Bus Width Selection
    0: 8-bit Parallel Host Data Bus.
    1: 16-bit Parallel Host Data Bus.*/
	uint8_t temp;
	LCD_CmdWrite(0x01);
	temp = LCD_DataRead();
	temp |= cSetb0;
	LCD_DataWrite(temp);
}

//[02h][02h][02h][02h][02h][02h][02h][02h][02h][02h][02h][02h][02h][02h][02h][02h]

void RGB_16b_16bpp(void)
{
	uint8_t temp;
	LCD_CmdWrite(0x02);
	temp = LCD_DataRead();
	temp &= cClrb7;
	temp |= cSetb6;
	LCD_DataWrite(temp);
}

void MemWrite_Left_Right_Top_Down(void)
{
	uint8_t temp;
	LCD_CmdWrite(0x02);
	temp = LCD_DataRead();
	temp &= cClrb2;
	temp &= cClrb1;
	LCD_DataWrite(temp);
}
//[03h][03h][03h][03h][03h][03h][03h][03h][03h][03h][03h][03h][03h][03h][03h][03h]
void Graphic_Mode(void)
{
	uint8_t temp;
	LCD_CmdWrite(0x03);
	temp = LCD_DataRead();
    temp &= cClrb2;
	LCD_DataWrite(temp);
}
void Text_Mode(void)
{
	uint8_t temp;
	LCD_CmdWrite(0x03);
	temp = LCD_DataRead();
    temp |= cSetb2;
	LCD_DataWrite(temp);
}
void Memory_Select_SDRAM(void)
{
	uint8_t temp;
	LCD_CmdWrite(0x03);
	temp = LCD_DataRead();
    temp &= cClrb1;
    temp &= cClrb0;	// B
	LCD_DataWrite(temp);
}
void Memory_Select_Graphic_Cursor_RAM(void)
{
	unsigned char temp;
	LCD_CmdWrite(0x03);
	temp = LCD_DataRead();
    temp |= cSetb1;
    temp &= cClrb0;
	LCD_DataWrite(temp);
}

//[05h]=========================================================================
//[06h]=========================================================================
//[07h]=========================================================================
//[08h]=========================================================================
//[09h]=========================================================================
//[0Ah]=========================================================================
//[0Bh]=========================================================================
//[0Ch]=========================================================================
//[0Eh]=========================================================================

void Select_Main_Window_16bpp(void)
{
/*
Main Window Color Depth Setting
00b: 8-bpp generic TFT, i.e. 256 colors.
01b: 16-bpp generic TFT, i.e. 65K colors.
1xb: 24-bpp generic TFT, i.e. 1.67M colors.
*/
	uint8_t temp;
	LCD_CmdWrite(0x10);
	temp = LCD_DataRead();
    temp &= cClrb3;
    temp |= cSetb2;
	LCD_DataWrite(temp);
}
//[10h]=========================================================================
void Enable_PIP1(void)
{
/*
PIP 1 window Enable/Disable
0 : PIP 1 window disable.
1 : PIP 1 window enable
PIP 1 window always on top of PIP 2 window.
*/
	unsigned char temp;
	LCD_CmdWrite(0x10);
	temp = LCD_DataRead();
    temp |= cSetb7;
	LCD_DataWrite(temp);
}
void Disable_PIP1(void)
{
/*
PIP 1 window Enable/Disable
0 : PIP 1 window disable.
1 : PIP 1 window enable
PIP 1 window always on top of PIP 2 window.
*/
	unsigned char temp;
	LCD_CmdWrite(0x10);
	temp = LCD_DataRead();
    temp &= cClrb7;
	LCD_DataWrite(temp);
}
void Enable_PIP2(void)
{
/*
PIP 2 window Enable/Disable
0 : PIP 2 window disable.
1 : PIP 2 window enable
PIP 1 window always on top of PIP 2 window.
*/
	unsigned char temp;
	LCD_CmdWrite(0x10);
	temp = LCD_DataRead();
    temp |= cSetb6;
	LCD_DataWrite(temp);
}
void Disable_PIP2(void)
{
/*
PIP 2 window Enable/Disable
0 : PIP 2 window disable.
1 : PIP 2 window enable
PIP 1 window always on top of PIP 2 window.
*/
	unsigned char temp;
	LCD_CmdWrite(0x10);
	temp = LCD_DataRead();
    temp &= cClrb6;
	LCD_DataWrite(temp);
}
void Select_PIP1_Parameter(void)
{
/*
0: To configure PIP 1ˇs parameters.
1: To configure PIP 2ˇs parameters..
*/
	unsigned char temp;
	LCD_CmdWrite(0x10);
	temp = LCD_DataRead();
    temp &= cClrb4;
	LCD_DataWrite(temp);
}
void Select_PIP2_Parameter(void)
{
/*
0: To configure PIP 1ˇs parameters.
1: To configure PIP 2ˇs parameters..
*/
	unsigned char temp;
	LCD_CmdWrite(0x10);
	temp = LCD_DataRead();
    temp |= cSetb4;
	LCD_DataWrite(temp);
}
//[11h]=========================================================================
void Select_PIP2_Window_8bpp(void)
{
/*
PIP 1 Window Color Depth Setting
00b: 8-bpp generic TFT, i.e. 256 colors.
01b: 16-bpp generic TFT, i.e. 65K colors.
1xb: 24-bpp generic TFT, i.e. 1.67M colors.
*/
	unsigned char temp;
	LCD_CmdWrite(0x11);
	temp = LCD_DataRead();
    temp &= cClrb1;
    temp &= cClrb0;
	LCD_DataWrite(temp);
}
void Select_PIP2_Window_16bpp(void)
{
/*
PIP 1 Window Color Depth Setting
00b: 8-bpp generic TFT, i.e. 256 colors.
01b: 16-bpp generic TFT, i.e. 65K colors.
1xb: 24-bpp generic TFT, i.e. 1.67M colors.
*/
	unsigned char temp;
	LCD_CmdWrite(0x11);
	temp = LCD_DataRead();
    temp &= cClrb1;
    temp |= cSetb0;
	LCD_DataWrite(temp);
}
void Select_PIP2_Window_24bpp(void)
{
/*
PIP 1 Window Color Depth Setting
00b: 8-bpp generic TFT, i.e. 256 colors.
01b: 16-bpp generic TFT, i.e. 65K colors.
1xb: 24-bpp generic TFT, i.e. 1.67M colors.
*/
	unsigned char temp;
	LCD_CmdWrite(0x11);
	temp = LCD_DataRead();
    temp |= cSetb1;
    temp &= cClrb0;
	LCD_DataWrite(temp);
}
void Select_PIP1_Window_8bpp(void)
{
/*
PIP 2 Window Color Depth Setting
00b: 8-bpp generic TFT, i.e. 256 colors.
01b: 16-bpp generic TFT, i.e. 65K colors.
1xb: 24-bpp generic TFT, i.e. 1.67M colors.
*/
	unsigned char temp;
	LCD_CmdWrite(0x11);
	temp = LCD_DataRead();
    temp &= cClrb3;
    temp &= cClrb2;
	LCD_DataWrite(temp);
}
void Select_PIP1_Window_16bpp(void)
{
/*
PIP 2 Window Color Depth Setting
00b: 8-bpp generic TFT, i.e. 256 colors.
01b: 16-bpp generic TFT, i.e. 65K colors.
1xb: 24-bpp generic TFT, i.e. 1.67M colors.
*/
	unsigned char temp;
	LCD_CmdWrite(0x11);
	temp = LCD_DataRead();
    temp &= cClrb3;
    temp |= cSetb2;
	LCD_DataWrite(temp);
}
void Select_PIP1_Window_24bpp(void)
{
/*
PIP 2 Window Color Depth Setting
00b: 8-bpp generic TFT, i.e. 256 colors.
01b: 16-bpp generic TFT, i.e. 65K colors.
1xb: 24-bpp generic TFT, i.e. 1.67M colors.
*/
	unsigned char temp;
	LCD_CmdWrite(0x11);
	temp = LCD_DataRead();
    temp |= cSetb3;
    temp &= cClrb2;
	LCD_DataWrite(temp);
}

//[12h]=========================================================================

void PCLK_Falling(void)
{
/*
PCLK Inversion
0: PDAT, DE, HSYNC etc. Drive(/ change) at PCLK falling edge.
1: PDAT, DE, HSYNC etc. Drive(/ change) at PCLK rising edge.
*/
	uint8_t temp;
	LCD_CmdWrite(0x12);
	temp = LCD_DataRead();
    temp |= cSetb7;
	LCD_DataWrite(temp);
}
void Display_ON(void)
{
/*	
Display ON/OFF
0b: Display Off.
1b: Display On.
*/
	uint8_t temp;
	
	LCD_CmdWrite(0x12);
	temp = LCD_DataRead();
	temp |= cSetb6;
	LCD_DataWrite(temp);
}
void Display_OFF(void)
{
/*	
Display ON/OFF
0b: Display Off.
1b: Display On.
*/
	unsigned char temp;
	
	LCD_CmdWrite(0x12);
	temp = LCD_DataRead();
	temp &= cClrb6;
	LCD_DataWrite(temp);
}
void Color_Bar_ON(void)
{
/*	
Display Test Color Bar
0b: Disable.
1b: Enable.
*/
	unsigned char temp;
	
	LCD_CmdWrite(0x12);
	temp = LCD_DataRead();
	temp |= cSetb5;
	LCD_DataWrite(temp);
}
void Color_Bar_OFF(void)
{
/*	
Display Test Color Bar
0b: Disable.
1b: Enable.
*/
	unsigned char temp;
	
	LCD_CmdWrite(0x12);
	temp = LCD_DataRead();
	temp &= cClrb5;
	LCD_DataWrite(temp);
}
void VSCAN_T_to_B(void)
{
/*	
Vertical Scan direction
0 : From Top to Bottom
1 : From bottom to Top
PIP window will be disabled when VDIR set as 1.
*/
	uint8_t temp;
	
	LCD_CmdWrite(0x12);
	temp = LCD_DataRead();
	temp &= cClrb3;
	LCD_DataWrite(temp);
}
void PDATA_Set_RGB(void)
{
/*	
parallel PDATA[23:0] Output Sequence
000b : RGB.
001b : RBG.
010b : GRB.
011b : GBR.
100b : BRG.
101b : BGR.
*/
	uint8_t temp;
	
	LCD_CmdWrite(0x12);
	temp = LCD_DataRead();
  temp &=0xf8;
	temp |=0x05;
	LCD_DataWrite(temp);
}

////[13h]=========================================================================
void HSYNC_Low_Active(void)
{
/*	
HSYNC Polarity
0 : Low active.
1 : High active.
*/
	uint8_t temp;
	
	LCD_CmdWrite(0x13);
	temp = LCD_DataRead();
	temp &= cClrb7;
	LCD_DataWrite(temp);
}

void VSYNC_Low_Active(void)
{
/*	
VSYNC Polarity
0 : Low active.
1 : High active.
*/
	uint8_t temp;
	
	LCD_CmdWrite(0x13);
	temp = LCD_DataRead();
	temp &= cClrb6;	
	LCD_DataWrite(temp);
}

void DE_High_Active(void)
{
/*	
DE Polarity
0 : High active.
1 : Low active.
*/
	uint8_t temp;
	
	LCD_CmdWrite(0x13);
	temp = LCD_DataRead();
	temp &= cClrb5;
	LCD_DataWrite(temp);
}

//[14h][15h][1Ah][1Bh]=========================================================================

void LCD_HorizontalWidth_VerticalHeight(uint16_t WX,uint16_t HY)
{
/*
[14h] Horizontal Display Width Setting Bit[7:0]
[15h] Horizontal Display Width Fine Tuning (HDWFT) [3:0]
The register specifies the LCD panel horizontal display width in
the unit of 8 pixels resolution.
Horizontal display width(pixels) = (HDWR + 1) * 8 + HDWFTR

[1Ah] Vertical Display Height Bit[7:0]
Vertical Display Height(Line) = VDHR + 1
[1Bh] Vertical Display Height Bit[10:8]
Vertical Display Height(Line) = VDHR + 1
*/
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
////[16h][17h]=========================================================================
void LCD_Horizontal_Non_Display(uint16_t WX)
{
/*
[16h] Horizontal Non-Display Period(HNDR) Bit[4:0]
This register specifies the horizontal non-display period. Also
called back porch.
Horizontal non-display period(pixels) = (HNDR + 1) * 8 + HNDFTR

[17h] Horizontal Non-Display Period Fine Tuning(HNDFT) [3:0]
This register specifies the fine tuning for horizontal non-display
period; it is used to support the SYNC mode panel. Each level of
this modulation is 1-pixel.
Horizontal non-display period(pixels) = (HNDR + 1) * 8 + HNDFTR
*/
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
//[18h]=========================================================================
void LCD_HSYNC_Start_Position(uint16_t WX)
{
/*
[18h] HSYNC Start Position[4:0]
The starting position from the end of display area to the
beginning of HSYNC. Each level of this modulation is 8-pixel.
Also called front porch.
HSYNC Start Position(pixels) = (HSTR + 1)x8
*/
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
//[19h]=========================================================================
void LCD_HSYNC_Pulse_Width(uint16_t WX)
{
/*
[19h] HSYNC Pulse Width(HPW) [4:0]
The period width of HSYNC.
HSYNC Pulse Width(pixels) = (HPW + 1)x8
*/
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
//[1Ch][1Dh]=========================================================================
void LCD_Vertical_Non_Display(uint16_t HY)
{
/*
[1Ch] Vertical Non-Display Period Bit[7:0]
Vertical Non-Display Period(Line) = (VNDR + 1)

[1Dh] Vertical Non-Display Period Bit[9:8]
Vertical Non-Display Period(Line) = (VNDR + 1)
*/
	uint8_t temp;
    temp=HY-1;
	LCD_CmdWrite(0x1C);
	LCD_DataWrite(temp);

	LCD_CmdWrite(0x1D);
	LCD_DataWrite(temp>>8);
}
//[1Eh]=========================================================================
void LCD_VSYNC_Start_Position(uint16_t HY)
{
/*
[1Eh] VSYNC Start Position[7:0]
The starting position from the end of display area to the beginning of VSYNC.
VSYNC Start Position(Line) = (VSTR + 1)
*/
	uint8_t temp;
    temp=HY-1;
	LCD_CmdWrite(0x1E);
	LCD_DataWrite(temp);
}
//[1Fh]=========================================================================
void LCD_VSYNC_Pulse_Width(uint16_t HY)
{
/*
[1Fh] VSYNC Pulse Width[5:0]
The pulse width of VSYNC in lines.
VSYNC Pulse Width(Line) = (VPWR + 1)
*/
	uint8_t temp;
    temp=HY-1;
	LCD_CmdWrite(0x1F);
	LCD_DataWrite(temp);
}
//[20h][21h][22h][23h]=========================================================================
void Main_Image_Start_Address(unsigned long Addr)	
{
/*
[20h] Main Image Start Address[7:2]
[21h] Main Image Start Address[15:8]
[22h] Main Image Start Address [23:16]
[23h] Main Image Start Address [31:24]
*/
	LCD_RegisterWrite(0x20,Addr);
	LCD_RegisterWrite(0x21,Addr>>8);
	LCD_RegisterWrite(0x22,Addr>>16);
	LCD_RegisterWrite(0x23,Addr>>24);
}
//[24h][25h]=========================================================================
void Main_Image_Width(uint16_t WX)	
{
/*
[24h] Main Image Width [7:0]
[25h] Main Image Width [12:8]
Unit: Pixel.
It must be divisible by 4. MIW Bit [1:0] tie to ¨0〃 internally.
The value is physical pixel number. Maximum value is 8188 pixels
*/
	LCD_RegisterWrite(0x24,WX);
	LCD_RegisterWrite(0x25,WX>>8);
}
//[26h][27h][28h][29h]=========================================================================
void Main_Window_Start_XY(uint16_t WX,uint16_t HY)	
{
/*
[26h] Main Window Upper-Left corner X-coordination [7:0]
[27h] Main Window Upper-Left corner X-coordination [12:8]
Reference Main Image coordination.
Unit: Pixel
It must be divisible by 4. MWULX Bit [1:0] tie to ¨0〃 internally.
X-axis coordination plus Horizontal display width cannot large than 8188.

[28h] Main Window Upper-Left corner Y-coordination [7:0]
[29h] Main Window Upper-Left corner Y-coordination [12:8]
Reference Main Image coordination.
Unit: Pixel
Range is between 0 and 8191.
*/
	LCD_RegisterWrite(0x26,WX);
	LCD_RegisterWrite(0x27,WX>>8);

	LCD_RegisterWrite(0x28,HY);
	LCD_RegisterWrite(0x29,HY>>8);
}
//[2Ah][2Bh][2Ch][2Dh]=========================================================================
void PIP_Display_Start_XY(unsigned short WX,unsigned short HY)	
{
/*
[2Ah] PIP Window Display Upper-Left corner X-coordination [7:0]
[2Bh] PIP Window Display Upper-Left corner X-coordination [12:8]
Reference Main Window coordination.
Unit: Pixel
It must be divisible by 4. PWDULX Bit [1:0] tie to ¨0〃 internally.
X-axis coordination should less than horizontal display width.
According to bit of Select Configure PIP 1 or 2 Windowˇs parameters. 
Function bit will be configured for relative PIP window.

[2Ch] PIP Window Display Upper-Left corner Y-coordination [7:0]
[2Dh] PIP Window Display Upper-Left corner Y-coordination [12:8]
Reference Main Window coordination.
Unit: Pixel
Y-axis coordination should less than vertical display height.
According to bit of Select Configure PIP 1 or 2 Windowˇs parameters.
Function bit will be configured for relative PIP window.
*/
	LCD_RegisterWrite(0x2A,WX);
	LCD_RegisterWrite(0x2B,WX>>8);
	
	LCD_RegisterWrite(0x2C,HY);
	LCD_RegisterWrite(0x2D,HY>>8);
}
//[2Eh][2Fh][30h][31h]=========================================================================
void PIP_Image_Start_Address(unsigned long Addr)	
{
/*
[2Eh] PIP Image Start Address[7:2]
[2Fh] PIP Image Start Address[15:8]
[30h] PIP Image Start Address [23:16]
[31h] PIP Image Start Address [31:24]
*/
	LCD_RegisterWrite(0x2E,Addr);
	LCD_RegisterWrite(0x2F,Addr>>8);
	LCD_RegisterWrite(0x30,Addr>>16);
	LCD_RegisterWrite(0x31,Addr>>24);
}
//[32h][33h]=========================================================================
void PIP_Image_Width(unsigned short WX)	
{
/*
[32h] PIP Image Width [7:0]
[33h] PIP Image Width [12:8]
Unit: Pixel.
It must be divisible by 4. PIW Bit [1:0] tie to ¨0〃 internally.
The value is physical pixel number.
This width should less than horizontal display width.
According to bit of Select Configure PIP 1 or 2 Windowˇs parameters.
Function bit will be configured for relative PIP window.
*/
	LCD_RegisterWrite(0x32,WX);
	LCD_RegisterWrite(0x33,WX>>8);
}
//[34h][35h][36h][37h]=========================================================================
void PIP_Window_Image_Start_XY(unsigned short WX,unsigned short HY)	
{
/*
[34h] PIP 1 or 2 Window Image Upper-Left corner X-coordination [7:0]
[35h] PIP Window Image Upper-Left corner X-coordination [12:8]
Reference PIP Image coordination.
Unit: Pixel
It must be divisible by 4. PWIULX Bit [1:0] tie to ¨0〃 internally.
X-axis coordination plus PIP image width cannot large than 8188.
According to bit of Select Configure PIP 1 or 2 Windowˇs parameters. 
Function bit will be configured for relative PIP window.

[36h] PIP Windows Display Upper-Left corner Y-coordination [7:0]
[37h] PIP Windows Image Upper-Left corner Y-coordination [12:8]
Reference PIP Image coordination.
Unit: Pixel
Y-axis coordination plus PIP window height should less than 8191.
According to bit of Select Configure PIP 1 or 2 Windowˇs parameters. 
Function bit will be configured for relative PIP window.
*/
	LCD_RegisterWrite(0x34,WX);
	LCD_RegisterWrite(0x35,WX>>8);
	
	LCD_RegisterWrite(0x36,HY);
	LCD_RegisterWrite(0x37,HY>>8);
}
//[38h][39h][3Ah][3Bh]=========================================================================
void PIP_Window_Width_Height(unsigned short WX,unsigned short HY)	
{
/*
[38h] PIP Window Width [7:0]
[39h] PIP Window Width [10:8]
Unit: Pixel.
It must be divisible by 4. The value is physical pixel number.
Maximum value is 8188 pixels.
According to bit of Select Configure PIP 1 or 2 Windowˇs parameters. 
Function bit will be configured for relative PIP window.

[3Ah] PIP Window Height [7:0]
[3Bh] PIP Window Height [10:8]
Unit: Pixel
The value is physical pixel number. Maximum value is 8191 pixels.
According to bit of Select Configure PIP 1 or 2 Windowˇs parameters. 
Function bit will be configured for relative PIP window.
*/
	LCD_RegisterWrite(0x38,WX);
	LCD_RegisterWrite(0x39,WX>>8);
	
	LCD_RegisterWrite(0x3A,HY);
	LCD_RegisterWrite(0x3B,HY>>8);
}

//[3Ch]=========================================================================
void Enable_Graphic_Cursor(void)	
{
/*
Graphic Cursor Enable
0 : Graphic Cursor disable.
1 : Graphic Cursor enable.
*/
	unsigned char temp;
	
	LCD_CmdWrite(0x3C);
	temp = LCD_DataRead();
	temp |= cSetb4;
	LCD_DataWrite(temp);
}
void Disable_Graphic_Cursor(void)	
{
/*
Graphic Cursor Enable
0 : Graphic Cursor disable.
1 : Graphic Cursor enable.
*/
	unsigned char temp;
	
	LCD_CmdWrite(0x3C);
	temp = LCD_DataRead();
	temp &= cClrb4;
	LCD_DataWrite(temp);
}
//
void Select_Graphic_Cursor_1(void)	
{
/*
Graphic Cursor Selection Bit
Select one from four graphic cursor types. (00b to 11b)
00b : Graphic Cursor Set 1.
01b : Graphic Cursor Set 2.
10b : Graphic Cursor Set 3.
11b : Graphic Cursor Set 4.
*/
	unsigned char temp;
	
	LCD_CmdWrite(0x3C);
	temp = LCD_DataRead();
	temp &= cClrb3;
	temp &= cClrb2;
	LCD_DataWrite(temp);
}
void Select_Graphic_Cursor_2(void)	
{
/*
Graphic Cursor Selection Bit
Select one from four graphic cursor types. (00b to 11b)
00b : Graphic Cursor Set 1.
01b : Graphic Cursor Set 2.
10b : Graphic Cursor Set 3.
11b : Graphic Cursor Set 4.
*/
	unsigned char temp;
	
	LCD_CmdWrite(0x3C);
	temp = LCD_DataRead();
	temp &= cClrb3;
	temp |= cSetb2;
	LCD_DataWrite(temp);
}
void Select_Graphic_Cursor_3(void)	
{
/*
Graphic Cursor Selection Bit
Select one from four graphic cursor types. (00b to 11b)
00b : Graphic Cursor Set 1.
01b : Graphic Cursor Set 2.
10b : Graphic Cursor Set 3.
11b : Graphic Cursor Set 4.
*/
	unsigned char temp;
	
	LCD_CmdWrite(0x3C);
	temp = LCD_DataRead();
	temp |= cSetb3;
	temp &= cClrb2;
	LCD_DataWrite(temp);
}
void Select_Graphic_Cursor_4(void)	
{
/*
Graphic Cursor Selection Bit
Select one from four graphic cursor types. (00b to 11b)
00b : Graphic Cursor Set 1.
01b : Graphic Cursor Set 2.
10b : Graphic Cursor Set 3.
11b : Graphic Cursor Set 4.
*/
	unsigned char temp;
	
	LCD_CmdWrite(0x3C);
	temp = LCD_DataRead();
	temp |= cSetb3;
	temp |= cSetb2;
	LCD_DataWrite(temp);
}
//
void Enable_Text_Cursor(void)	
{
/*
Text Cursor Enable
0 : Disable.
1 : Enable.
Text cursor & Graphic cursor cannot enable simultaneously.
Graphic cursor has higher priority then Text cursor if enabled simultaneously.
*/
	unsigned char temp;
	
	LCD_CmdWrite(0x3C);
	temp = LCD_DataRead();
	temp |= cSetb1;
	LCD_DataWrite(temp);
}
void Disable_Text_Cursor(void)	
{
/*
Text Cursor Enable
0 : Disable.
1 : Enable.
Text cursor & Graphic cursor cannot enable simultaneously.
Graphic cursor has higher priority then Text cursor if enabled simultaneously.
*/
	unsigned char temp;
	
	LCD_CmdWrite(0x3C);
	temp = LCD_DataRead();
	temp &= cClrb1;
	LCD_DataWrite(temp);
}
//
void Enable_Text_Cursor_Blinking(void)	
{
/*
Text Cursor Blinking Enable
0 : Disable.
1 : Enable.
*/
	unsigned char temp;
	
	LCD_CmdWrite(0x3C);
	temp = LCD_DataRead();
	temp |= cSetb0;
	LCD_DataWrite(temp);
}
void Disable_Text_Cursor_Blinking(void)	
{
/*
Text Cursor Blinking Enable
0 : Disable.
1 : Enable.
*/
	unsigned char temp;
	
	LCD_CmdWrite(0x3C);
	temp = LCD_DataRead();
	temp &= cClrb0;
	LCD_DataWrite(temp);
}
//[3Dh]=========================================================================
void Blinking_Time_Frames(unsigned char temp)	
{
/*
Text Cursor Blink Time Setting (Unit: Frame)
00h : 1 frame time.
01h : 2 frames time.
02h : 3 frames time.
:
FFh : 256 frames time.
*/
	LCD_CmdWrite(0x3D);
	LCD_DataWrite(temp);
}
//[3Eh]=========================================================================
void Text_Cursor_H_V(unsigned short WX,unsigned short HY)
{
/*
[3Eh]
Text Cursor Horizontal Size Setting[4:0]
Unit : Pixel
Zero-based number. Value ¨0〃 means 1 pixel.
Note : When font is enlarged, the cursor setting will multiply the
same times as the font enlargement.
[3Fh]
Text Cursor Vertical Size Setting[4:0]
Unit : Pixel
Zero-based number. Value ¨0〃 means 1 pixel.
Note : When font is enlarged, the cursor setting will multiply the
same times as the font enlargement.
*/
	LCD_CmdWrite(0x3E);
	LCD_DataWrite(WX);
	LCD_CmdWrite(0x3F);
	LCD_DataWrite(HY);
}
//[40h][41h][42h][43h]=========================================================================
void Graphic_Cursor_XY(unsigned short WX,unsigned short HY)
{
/*
[40h] Graphic Cursor Horizontal Location[7:0]
[41h] Graphic Cursor Horizontal Location[12:8]
[42h] Graphic Cursor Vertical Location[7:0]
[43h] Graphic Cursor Vertical Location[12:8]
Reference main Window coordination.
*/	
	LCD_RegisterWrite(0x40,WX);
	LCD_RegisterWrite(0x41,WX>>8);

	LCD_RegisterWrite(0x42,HY);
	LCD_RegisterWrite(0x43,HY>>8);
}
//[44h]=========================================================================
void Set_Graphic_Cursor_Color_1(unsigned char temp)
{
/*
[44h] Graphic Cursor Color 0 with 256 Colors
RGB Format [7:0] = RRRGGGBB.
*/	
	LCD_RegisterWrite(0x44,temp);
}
//[45h]=========================================================================
void Set_Graphic_Cursor_Color_2(unsigned char temp)
{
/*
[45h] Graphic Cursor Color 1 with 256 Colors
RGB Format [7:0] = RRRGGGBB.
*/	
	LCD_RegisterWrite(0x45,temp);
}
//[50h][51h][52h][53h]=========================================================================
void Canvas_Image_Start_address(unsigned long Addr)	
{
/*
[50h] Start address of Canvas [7:0]
[51h] Start address of Canvas [15:8]
[52h] Start address of Canvas [23:16]
[53h] Start address of Canvas [31:24]
*/
	LCD_RegisterWrite(0x50,Addr);
	LCD_RegisterWrite(0x51,Addr>>8);
	LCD_RegisterWrite(0x52,Addr>>16);
	LCD_RegisterWrite(0x53,Addr>>24);
}
//[54h][55h]=========================================================================
void Canvas_image_width(uint16_t WX)	
{
/*
[54h] Canvas image width [7:2]
[55h] Canvas image width [12:8]
*/
	LCD_RegisterWrite(0x54,WX);
	LCD_RegisterWrite(0x55,WX>>8);
}
//[56h][57h][58h][59h]=========================================================================
void Active_Window_XY(uint16_t WX,uint16_t HY)	
{
/*
[56h] Active Window Upper-Left corner X-coordination [7:0]
[57h] Active Window Upper-Left corner X-coordination [12:8]
[58h] Active Window Upper-Left corner Y-coordination [7:0]
[59h] Active Window Upper-Left corner Y-coordination [12:8]
*/
	LCD_RegisterWrite(0x56,WX);
	LCD_RegisterWrite(0x57,WX>>8);
	
	LCD_RegisterWrite(0x58,HY);
	LCD_RegisterWrite(0x59,HY>>8);
}
////[5Ah][5Bh][5Ch][5Dh]=========================================================================
void Active_Window_WH(uint16_t WX,uint16_t HY)	
{
/*
[5Ah] Width of Active Window [7:0]
[5Bh] Width of Active Window [12:8]
[5Ch] Height of Active Window [7:0]
[5Dh] Height of Active Window [12:8]
*/
	LCD_RegisterWrite(0x5A,WX);
	LCD_RegisterWrite(0x5B,WX>>8);
 
 	LCD_RegisterWrite(0x5C,HY);
	LCD_RegisterWrite(0x5D,HY>>8);
}
//5Eh]=========================================================================
void Memory_XY_Mode(void)	
{
/*
Canvas addressing mode
0: Block mode (X-Y coordination addressing)
1: linear mode
*/
	uint8_t temp;

	LCD_CmdWrite(0x5E);
	temp = LCD_DataRead();
	temp &= cClrb2;
	LCD_DataWrite(temp);
}
void Memory_16bpp_Mode(void)	
{
/*
Canvas imageˇs color depth & memory R/W data width
In Block Mode:
00: 8bpp
01: 16bpp
1x: 24bpp
In Linear Mode:
X0: 8-bits memory data read/write.
X1: 16-bits memory data read/write
*/
	uint8_t temp;

	LCD_CmdWrite(0x5E);
	temp = LCD_DataRead();
	temp &= cClrb1;
	temp |= cSetb0;
	LCD_DataWrite(temp);
}
void Memory_Linear_Mode(void)	
{
/*
Canvas addressing mode
0: Block mode (X-Y coordination addressing)
1: linear mode
*/
	unsigned char temp;

	LCD_CmdWrite(0x5E);
	temp = LCD_DataRead();
	temp |= cSetb2;
	LCD_DataWrite(temp);
}
//[5Fh][60h][61h][62h]=========================================================================
void Goto_Pixel_XY(uint16_t WX,uint16_t HY)	
{
/*
[Write]: Set Graphic Read/Write position
[Read]: Current Graphic Read/Write position
Read back is Read position or Write position depends on
REG[5Eh] bit3, Select to read back Graphic Read/Write position.
When DPRAM Linear mode:Graphic Read/Write Position [31:24][23:16][15:8][7:0]
When DPRAM Active window mode:Graphic Read/Write 
Horizontal Position [12:8][7:0], 
Vertical Position [12:8][7:0].
Reference Canvas image coordination. Unit: Pixel
*/
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
//[63h][64h][65h][66h]=========================================================================
void Goto_Text_XY(unsigned short WX,unsigned short HY)	
{
/*
Write: Set Text Write position
Read: Current Text Write position
Text Write X-coordination [12:8][7:0]
Text Write Y-coordination [12:8][7:0]
Reference Canvas image coordination.
Unit: Pixel
*/
	LCD_RegisterWrite(0x63,WX);
	LCD_RegisterWrite(0x64,WX>>8);
	
	LCD_RegisterWrite(0x65,HY);
	LCD_RegisterWrite(0x66,HY>>8);
}

//[67h]=========================================================================
/*
[bit7]Draw Line / Triangle Start Signal
Write Function
0 : Stop the drawing function.
1 : Start the drawing function.
Read Function
0 : Drawing function complete.
1 : Drawing function is processing.
[bit5]Fill function for Triangle Signal
0 : Non fill.
1 : Fill.
[bit1]Draw Triangle or Line Select Signal
0 : Draw Line
1 : Draw Triangle
*/
void Start_Line(void)
{
	LCD_CmdWrite(0x67);
	LCD_DataWrite(0x80);
	Check_Busy_Draw();
}
void Start_Triangle(void)
{
	LCD_CmdWrite(0x67);
	LCD_DataWrite(0x82);//B1000_0010
	Check_Busy_Draw();
}
void Start_Triangle_Fill(void)
{

	LCD_CmdWrite(0x67);
	LCD_DataWrite(0xA2);//B1010_0010
	Check_Busy_Draw();
}
//[68h][69h][6Ah][6Bh]=========================================================================
//线起点
void Line_Start_XY(unsigned short WX,unsigned short HY)
{
/*
[68h] Draw Line/Square/Triangle Start X-coordination [7:0]
[69h] Draw Line/Square/Triangle Start X-coordination [12:8]
[6Ah] Draw Line/Square/Triangle Start Y-coordination [7:0]
[6Bh] Draw Line/Square/Triangle Start Y-coordination [12:8]
*/
	LCD_CmdWrite(0x68);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x69);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x6A);
	LCD_DataWrite(HY);

	LCD_CmdWrite(0x6B);
	LCD_DataWrite(HY>>8);
}
//[6Ch][6Dh][6Eh][6Fh]=========================================================================
//线终点
void Line_End_XY(unsigned short WX,unsigned short HY)
{
/*
[6Ch] Draw Line/Square/Triangle End X-coordination [7:0]
[6Dh] Draw Line/Square/Triangle End X-coordination [12:8]
[6Eh] Draw Line/Square/Triangle End Y-coordination [7:0]
[6Fh] Draw Line/Square/Triangle End Y-coordination [12:8]
*/
	LCD_CmdWrite(0x6C);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x6D);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x6E);
	LCD_DataWrite(HY);

	LCD_CmdWrite(0x6F);
	LCD_DataWrite(HY>>8);
}
//[68h]~[73h]=========================================================================
//à-翴1
void Triangle_Point1_XY(unsigned short WX,unsigned short HY)
{
/*
[68h] Draw Line/Square/Triangle Start X-coordination [7:0]
[69h] Draw Line/Square/Triangle Start X-coordination [12:8]
[6Ah] Draw Line/Square/Triangle Start Y-coordination [7:0]
[6Bh] Draw Line/Square/Triangle Start Y-coordination [12:8]
*/
	LCD_CmdWrite(0x68);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x69);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x6A);
	LCD_DataWrite(HY);

	LCD_CmdWrite(0x6B);
	LCD_DataWrite(HY>>8);
}
//à-翴2
void Triangle_Point2_XY(unsigned short WX,unsigned short HY)
{
/*
[6Ch] Draw Line/Square/Triangle End X-coordination [7:0]
[6Dh] Draw Line/Square/Triangle End X-coordination [12:8]
[6Eh] Draw Line/Square/Triangle End Y-coordination [7:0]
[6Fh] Draw Line/Square/Triangle End Y-coordination [12:8]
*/
	LCD_CmdWrite(0x6C);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x6D);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x6E);
	LCD_DataWrite(HY);

	LCD_CmdWrite(0x6F);
	LCD_DataWrite(HY>>8);
}
//à-翴3
void Triangle_Point3_XY (unsigned short WX,unsigned short HY)
{
/*
[70h] Draw Triangle Point 3 X-coordination [7:0]
[71h] Draw Triangle Point 3 X-coordination [12:8]
[72h] Draw Triangle Point 3 Y-coordination [7:0]
[73h] Draw Triangle Point 3 Y-coordination [12:8]
*/
	LCD_CmdWrite(0x70);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x71);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x72);
	LCD_DataWrite(HY);

	LCD_CmdWrite(0x73);
	LCD_DataWrite(HY>>8);
}
//よ癬翴
void Square_Start_XY(unsigned short WX,unsigned short HY)
{
/*
[68h] Draw Line/Square/Triangle Start X-coordination [7:0]
[69h] Draw Line/Square/Triangle Start X-coordination [12:8]
[6Ah] Draw Line/Square/Triangle Start Y-coordination [7:0]
[6Bh] Draw Line/Square/Triangle Start Y-coordination [12:8]
*/
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
/*
[6Ch] Draw Line/Square/Triangle End X-coordination [7:0]
[6Dh] Draw Line/Square/Triangle End X-coordination [12:8]
[6Eh] Draw Line/Square/Triangle End Y-coordination [7:0]
[6Fh] Draw Line/Square/Triangle End Y-coordination [12:8]
*/
	LCD_CmdWrite(0x6C);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x6D);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x6E);
	LCD_DataWrite(HY);

	LCD_CmdWrite(0x6F);
	LCD_DataWrite(HY>>8);
}

//-----------------------------------------------------
void Point(uint16_t x,uint16_t y,uint16_t color)
{ //x=799-x;
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
	//x1=799-x1,x2=799-x2;
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
	LCD_DataWrite(0x80);//B10000000
	Check_Busy_Draw();
	/*int x,y,dx,dy,Dx,Dy,e,i;
  Dx=x2-x1;
  Dy=y2-y1;
  dx=abs(x2-x1); //computes the absolute value of the floating-point number x2-x1.
  dy=abs(y2-y1);
  x=x1;
  y=y1;
  if(dy>dx)
  {
    e=-dy;
    for(i=0;i<dy;i++)
    {
      Point(x,y,color);
      if(Dy>=0) y++;  
      else y--;   
      e+=2*dx;
      if(e>=0)
      {
        if(Dx>=0) x++;
        else x--; 
        e-=2*dy;
      }
    }
  }
  else
  {
    e=-dx;
    for(i=0;i<dx;i++)
    {
      Point(x,y,color);
      if(Dx>=0) x++;
      else x--;
      e+=2*dy;
      if(e>=0)
      {
        if(Dy>=0) y++;
        else y--;
        e-=2*dx;
      }
    }
  }*/
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
/*---------------------------------------*/
void MPU_Memory_Write_Window_8bit  //???????????????
(
 uint16_t x            // x??
,uint16_t y            // y??
,const char g[]
,uint16_t number
,uint16_t color1
,uint16_t color2   // ??(8?)
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
	Active_Window_WH(LCD_XSIZE_TFT,LCD_YSIZE_TFT);
}
/*---------------------------------------*/
void Fills
(
 uint16_t X1                // X1位置
,uint16_t Y1                // Y1位置
,uint16_t X2                // X2位置
,uint16_t Y2                // Y2位置
,unsigned long ForegroundColor    // 背景颜色
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
	LCD_DataWrite(0x80);//B10000000
	
}	

//[76h]=========================================================================
/*
[bit7]
Draw Circle / Ellipse / Square /Circle Square Start Signal 
Write Function
0 : Stop the drawing function.
1 : Start the drawing function.
Read Function
0 : Drawing function complete.
1 : Drawing function is processing.
[bit6]
Fill the Circle / Ellipse / Square / Circle Square Signal
0 : Non fill.
1 : fill.
[bit5 bit4]
Draw Circle / Ellipse / Square / Ellipse Curve / Circle Square Select
00 : Draw Circle / Ellipse
01 : Draw Circle / Ellipse Curve
10 : Draw Square.
11 : Draw Circle Square.
[bit1 bit0]
Draw Circle / Ellipse Curve Part Select
00 : 
01 : 
10 : 
11 : 
*/
void Start_Circle_or_Ellipse(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0x80);//B1000_XXXX
	Check_Busy_Draw();	
}
void Start_Circle_or_Ellipse_Fill(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0xC0);//B1100_XXXX
	Check_Busy_Draw();	
}
//
void Start_Left_Down_Curve(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0x90);//B1001_XX00
	Check_Busy_Draw();	
}
void Start_Left_Up_Curve(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0x91);//B1001_XX01
	Check_Busy_Draw();	
}
void Start_Right_Up_Curve(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0x92);//B1001_XX10
	Check_Busy_Draw();	
}
void Start_Right_Down_Curve(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0x93);//B1001_XX11
	Check_Busy_Draw();	
}
//
void Start_Left_Down_Curve_Fill(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0xD0);//B1101_XX00
	Check_Busy_Draw();
}
void Start_Left_Up_Curve_Fill(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0xD1);//B1101_XX01
	Check_Busy_Draw();
}
void Start_Right_Up_Curve_Fill(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0xD2);//B1101_XX10
	Check_Busy_Draw();
}
void Start_Right_Down_Curve_Fill(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0xD3);//B1101_XX11
	Check_Busy_Draw();
}
//
void Start_Square(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0xA0);//B1010_XXXX
	Check_Busy_Draw();
}
void Start_Square_Fill(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0xE0);//B1110_XXXX
	Check_Busy_Draw();
}
void Start_Circle_Square(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0xB0);//B1011_XXXX
	Check_Busy_Draw();	
}
void Start_Circle_Square_Fill(void)
{
	LCD_CmdWrite(0x76);
	LCD_DataWrite(0xF0);//B1111_XXXX
	Check_Busy_Draw();	
}
//[77h]~[7Eh]=========================================================================
//蛾いみ
void Circle_Center_XY(unsigned short WX,unsigned short HY)
{
/*
[7Bh] Draw Circle/Ellipse/Circle Square Center X-coordination [7:0]
[7Ch] Draw Circle/Ellipse/Circle Square Center X-coordination [12:8]
[7Dh] Draw Circle/Ellipse/Circle Square Center Y-coordination [7:0]
[7Eh] Draw Circle/Ellipse/Circle Square Center Y-coordination [12:8]
*/
	LCD_CmdWrite(0x7B);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x7C);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x7D);
	LCD_DataWrite(HY);

	LCD_CmdWrite(0x7E);
	LCD_DataWrite(HY>>8);
}
//掘蛾いみ
void Ellipse_Center_XY(unsigned short WX,unsigned short HY)
{
/*
[7Bh] Draw Circle/Ellipse/Circle Square Center X-coordination [7:0]
[7Ch] Draw Circle/Ellipse/Circle Square Center X-coordination [12:8]
[7Dh] Draw Circle/Ellipse/Circle Square Center Y-coordination [7:0]
[7Eh] Draw Circle/Ellipse/Circle Square Center Y-coordination [12:8]
*/
	LCD_CmdWrite(0x7B);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x7C);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x7D);
	LCD_DataWrite(HY);

	LCD_CmdWrite(0x7E);
	LCD_DataWrite(HY>>8);
}
//蛾畖
void Circle_Radius_R(unsigned short WX)
{
/*
[77h] Draw Circle/Ellipse/Circle Square Major radius [7:0]
[78h] Draw Circle/Ellipse/Circle Square Major radius [12:8]
[79h] Draw Circle/Ellipse/Circle Square Minor radius [7:0]
[7Ah] Draw Circle/Ellipse/Circle Square Minor radius [12:8]
*/
	LCD_CmdWrite(0x77);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x78);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x79);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x7A);
	LCD_DataWrite(WX>>8);
}

//掘蛾畖
void Ellipse_Radius_RxRy(unsigned short WX,unsigned short HY)
{
/*
[77h] Draw Circle/Ellipse/Circle Square Major radius [7:0]
[78h] Draw Circle/Ellipse/Circle Square Major radius [12:8]
[79h] Draw Circle/Ellipse/Circle Square Minor radius [7:0]
[7Ah] Draw Circle/Ellipse/Circle Square Minor radius [12:8]
*/
	LCD_CmdWrite(0x77);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x78);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x79);
	LCD_DataWrite(HY);

	LCD_CmdWrite(0x7A);
	LCD_DataWrite(HY>>8);
}

//瑙温啜b畖
void Circle_Square_Radius_RxRy(unsigned short WX,unsigned short HY)
{
/*
[77h] Draw Circle/Ellipse/Circle Square Major radius [7:0]
[78h] Draw Circle/Ellipse/Circle Square Major radius [12:8]
[79h] Draw Circle/Ellipse/Circle Square Minor radius [7:0]
[7Ah] Draw Circle/Ellipse/Circle Square Minor radius [12:8]
*/
	LCD_CmdWrite(0x77);
	LCD_DataWrite(WX);

	LCD_CmdWrite(0x78);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0x79);
	LCD_DataWrite(HY);

	LCD_CmdWrite(0x7A);
	LCD_DataWrite(HY>>8);
}

//[84h]=========================================================================
void Set_PWM_Prescaler_1_to_256(uint16_t WX)
{
/*
PWM Prescaler Register
These 8 bits determine prescaler value for Timer 0 and 1.
Time base is ¨Core_Freq / (Prescaler + 1)〃
*/
	WX=WX-1;
	LCD_CmdWrite(0x84);
	LCD_DataWrite(WX);
}
//[85h]=========================================================================
void Select_PWM1_Clock_Divided_By_1(void)
{
/*
Select MUX input for PWM Timer 1.
00 = 1; 01 = 1/2; 10 = 1/4 ; 11 = 1/8;
*/
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp &= cClrb7;
	temp &= cClrb6;
	LCD_DataWrite(temp);
}
void Select_PWM1_Clock_Divided_By_2(void)
{
/*
Select MUX input for PWM Timer 1.
00 = 1; 01 = 1/2; 10 = 1/4 ; 11 = 1/8;
*/
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp &= cClrb7;
	temp |= cSetb6;
	LCD_DataWrite(temp);
}
void Select_PWM1_Clock_Divided_By_4(void)
{
/*
Select MUX input for PWM Timer 1.
00 = 1; 01 = 1/2; 10 = 1/4 ; 11 = 1/8;
*/
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp |= cSetb7;
	temp &= cClrb6;
	LCD_DataWrite(temp);
}
void Select_PWM1_Clock_Divided_By_8(void)
{
/*
Select MUX input for PWM Timer 1.
00 = 1; 01 = 1/2; 10 = 1/4 ; 11 = 1/8;
*/
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp |= cSetb7;
	temp |= cSetb6;
	LCD_DataWrite(temp);
}
void Select_PWM0_Clock_Divided_By_1(void)
{
/*
Select MUX input for PWM Timer 0.
00 = 1; 01 = 1/2; 10 = 1/4 ; 11 = 1/8;
*/
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp &= cClrb5;
	temp &= cClrb4;
	LCD_DataWrite(temp);
}
void Select_PWM0_Clock_Divided_By_2(void)
{
/*
Select MUX input for PWM Timer 0.
00 = 1; 01 = 1/2; 10 = 1/4 ; 11 = 1/8;
*/
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp &= cClrb5;
	temp |= cSetb4;
	LCD_DataWrite(temp);
}
void Select_PWM0_Clock_Divided_By_4(void)
{
/*
Select MUX input for PWM Timer 0.
00 = 1; 01 = 1/2; 10 = 1/4 ; 11 = 1/8;
*/
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp |= cSetb5;
	temp &= cClrb4;
	LCD_DataWrite(temp);
}
void Select_PWM0_Clock_Divided_By_8(void)
{
/*
Select MUX input for PWM Timer 0.
00 = 1; 01 = 1/2; 10 = 1/4 ; 11 = 1/8;
*/
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp |= cSetb5;
	temp |= cSetb4;
	LCD_DataWrite(temp);
}
//[85h].[bit3][bit2]=========================================================================
/*
XPWM[1] pin function control
0X:	XPWM[1] output system error flag (REG[00h] bit[1:0], Scan bandwidth insufficient + Memory access out of range)
10:	XPWM[1] enabled and controlled by PWM timer 1
11:	XPWM[1] output oscillator clock
//If XTEST[0] set high, then XPWM[1] will become panel scan clock input.
*/
void Select_PWM1_is_ErrorFlag(void)
{
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp &= cClrb3;
	LCD_DataWrite(temp);
}
void Select_PWM1(void)
{
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp |= cSetb3;
	temp &= cClrb2;
	LCD_DataWrite(temp);
}
//[85h].[bit1][bit0]=========================================================================
/*
XPWM[0] pin function control
0X: XPWM[0] becomes GPIO-C[7]
10: XPWM[0] enabled and controlled by PWM timer 0
11: XPWM[0] output core clock
*/

void Select_PWM0(void)
{
	uint8_t temp;
	
	LCD_CmdWrite(0x85);
	temp = LCD_DataRead();
	temp |= cSetb1;
	temp &= cClrb0;
	LCD_DataWrite(temp);
}
//[86h]=========================================================================
//[86h]PWM1
void Start_PWM1(void)
{
/*
PWM Timer 1 start/stop
Determine start/stop for Timer 1. 
0 = Stop 
1 = Start for Timer 1
*/
	uint8_t temp;
	LCD_CmdWrite(0x86);
	temp = LCD_DataRead();
	temp |= cSetb4;
	LCD_DataWrite(temp);
}
void Stop_PWM1(void)
{
/*
PWM Timer 1 start/stop
Determine start/stop for Timer 1. 
0 = Stop 
1 = Start for Timer 1
*/
	uint8_t temp;
	LCD_CmdWrite(0x86);
	temp = LCD_DataRead();
	temp &= cClrb4;
	LCD_DataWrite(temp);
}
//[86h]PWM0
void Start_PWM0(void)
{
/*
PWM Timer 0 start/stop
Determine start/stop for Timer 0. 
0 = Stop 
1 = Start for Timer 0
*/
	uint8_t temp;
	LCD_CmdWrite(0x86);
	temp = LCD_DataRead();
	temp |= cSetb0;
	LCD_DataWrite(temp);
}
void Stop_PWM0(void)
{
/*
PWM Timer 0 start/stop
Determine start/stop for Timer 0. 
0 = Stop 
1 = Start for Timer 0
*/
	uint8_t temp;
	LCD_CmdWrite(0x86);
	temp = LCD_DataRead();
	temp &= cClrb0;
	LCD_DataWrite(temp);
}
//[87h]=========================================================================
//[88h][89h]=========================================================================
void Set_Timer0_Compare_Buffer(uint16_t WX)
{
/*
Timer 0 compare buffer register
Compare buffer register total has 16 bits.
When timer counter equal or less than compare buffer register will cause PWM out
high level if inv_on bit is off.
*/
	LCD_CmdWrite(0x88);
	LCD_DataWrite(WX);
	LCD_CmdWrite(0x89);
	LCD_DataWrite(WX>>8);
}
//[8Ah][8Bh]=========================================================================
void Set_Timer0_Count_Buffer(uint16_t WX)
{
/*
Timer 0 count buffer register
Count buffer register total has 16 bits.
When timer counter equal to 0 will cause PWM timer reload Count buffer register if reload_en bit set as enable.
It may read back timer counterˇs real time value when PWM timer start.
*/
	LCD_CmdWrite(0x8A);
	LCD_DataWrite(WX);
	LCD_CmdWrite(0x8B);
	LCD_DataWrite(WX>>8);
}
//[8Ch][8Dh]=========================================================================
void Set_Timer1_Compare_Buffer(uint16_t WX)
{
/*
Timer 0 compare buffer register
Compare buffer register total has 16 bits.
When timer counter equal or less than compare buffer register will cause PWM out
high level if inv_on bit is off.
*/
	LCD_CmdWrite(0x8C);
	LCD_DataWrite(WX);
	LCD_CmdWrite(0x8D);
	LCD_DataWrite(WX>>8);
}
//[8Eh][8Fh]=========================================================================
void Set_Timer1_Count_Buffer(uint16_t WX)
{
/*
Timer 0 count buffer register
Count buffer register total has 16 bits.
When timer counter equal to 0 will cause PWM timer reload Count buffer register if reload_en bit set as enable.
It may read back timer counterˇs real time value when PWM timer start.
*/
	LCD_CmdWrite(0x8E);
	LCD_DataWrite(WX);
	LCD_CmdWrite(0x8F);
	LCD_DataWrite(WX>>8);
}
//[90h]=========================================================================
void BTE_Enable(void)
{	
/*
BTE Function Enable
0 : BTE Function disable.
1 : BTE Function enable.
*/
    unsigned char temp;
    LCD_CmdWrite(0x90);
    temp = LCD_DataRead();
    temp |= cSetb4 ;
	LCD_DataWrite(temp);  
}

//[90h]=========================================================================
void BTE_Disable(void)
{	
/*
BTE Function Enable
0 : BTE Function disable.
1 : BTE Function enable.
*/
    unsigned char temp;
    LCD_CmdWrite(0x90);
    temp = LCD_DataRead();
    temp &= cClrb4 ;
	LCD_DataWrite(temp);  
}

//[90h]=========================================================================
void Check_BTE_Busy(void)
{	
/*
BTE Function Status
0 : BTE Function is idle.
1 : BTE Function is busy.
*/
	unsigned char temp; 	
	do
	{
		temp=LCD_StatusRead();
	}while(temp&0x08);

}
//[90h]=========================================================================
void Pattern_Format_8X8(void)
{	
/*
Pattern Format
0 : 8X8
1 : 16X16
*/
    unsigned char temp;
    LCD_CmdWrite(0x90);
    temp = LCD_DataRead();
    temp &= cClrb0 ;
	LCD_DataWrite(temp);
}	
//[90h]=========================================================================
void Pattern_Format_16X16(void)
{	
/*
Pattern Format
0 : 8X8
1 : 16X16
*/
    unsigned char temp;
    LCD_CmdWrite(0x90);
    temp = LCD_DataRead();
    temp |= cSetb0 ;
	  LCD_DataWrite(temp);
}	

//[91h]=========================================================================
void BTE_Operation_Code(unsigned char setx)
{	
/*
BTE Operation Code[Bit3:0]
	
0000 : MPU Write BTE with ROP.
0001 : MPU Read BTE w/o ROP.
0010 : Memory copy (move) BTE in positive direction with ROP.
0011 : Memory copy (move) BTE in negative direction with ROP.
0100 : MPU Transparent Write BTE. (w/o ROP.)
0101 : Transparent Memory copy (move) BTE in positive direction (w/o ROP.)
0110 : Pattern Fill with ROP.
0111 : Pattern Fill with key-chroma
1000 : Color Expansion
1001 : Color Expansion with transparency
1010 : Move BTE in positive direction with Alpha blending
1011 : MPU Write BTE with Alpha blending
1100 : Solid Fill
1101 : Reserved
1110 : Reserved
1111 : Reserved
*/
    unsigned char temp;
    LCD_CmdWrite(0x91);
    temp = LCD_DataRead();
    temp &= 0xf0 ;
		temp |= setx ;
	  LCD_DataWrite(temp);

}
void BTE_ROP_Code(unsigned char setx)
{	
/*
BTE ROP Code[Bit7:4]
	
0000 : 0(Blackness)
0001 : ~S0.~S1 or ~ ( S0+S1 )
0010 : ~S0.S1
0011 : ~S0
0100 : S0.~S1
0101 : ~S1
0110 : S0^S1
0111 : ~S0+~S1 or ~ ( S0.S1 )
1000 : S0.S1
1001 : ~ ( S0^S1 )
1010 : S1
1011 : ~S0+S1
1100 : S0
1101 : S0+~S1
1110 : S0+S1
1111 : 1 ( Whiteness )
*/
    unsigned char temp;
    LCD_CmdWrite(0x91);
    temp = LCD_DataRead();
    temp &= 0x0f ;
		temp |= (setx<<4);
	  LCD_DataWrite(temp);
}
//[92h]=========================================================================
void BTE_S0_Color_16bpp(void)
{	
/*
S0 Color Depth
00 : 256 Color
01 : 64k Color
1x : 16M Color
*/	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp &= cClrb6 ;
		temp |= cSetb5 ;
	  LCD_DataWrite(temp);

}	
//[92h]=========================================================================
void BTE_S0_Color_24bpp(void)
{	
/*
S0 Color Depth
00 : 256 Color
01 : 64k Color
1x : 16M Color
*/	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp |= cSetb6 ;
		//temp |= cSetb5 ;
	  LCD_DataWrite(temp);
}
//[92h]=========================================================================
void BTE_S1_Color_8bpp(void)
{	
/*
S1 Color Depth
000 : 256 Color
001 : 64k Color
010 : 16M Color
011 : Constant Color
100 : 8 bit pixel alpha blending
101 : 16 bit pixel alpha blending
*/	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp &= cClrb4 ;
		temp &= cClrb3 ;
	  temp &= cClrb2 ;
	  LCD_DataWrite(temp);
}	
//[92h]=========================================================================
void BTE_S1_Color_16bpp(void)
{	
/*
S1 Color Depth
000 : 256 Color
001 : 64k Color
010 : 16M Color
011 : Constant Color
100 : 8 bit pixel alpha blending
101 : 16 bit pixel alpha blending
*/	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp &= cClrb4 ;
		temp &= cClrb3 ;
	  temp |= cSetb2 ;
	  LCD_DataWrite(temp);

}
//[92h]=========================================================================
void BTE_S1_Color_24bpp(void)
{	
/*
S1 Color Depth
000 : 256 Color
001 : 64k Color
010 : 16M Color
011 : Constant Color
100 : 8 bit pixel alpha blending
101 : 16 bit pixel alpha blending
*/	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp &= cClrb4 ;
		temp |= cSetb3 ;
	  temp &= cClrb2 ;
	  LCD_DataWrite(temp);
}

//[92h]=========================================================================
void BTE_S1_Color_Constant(void)
{	
/*
S1 Color Depth
000 : 256 Color
001 : 64k Color
010 : 16M Color
011 : Constant Color
100 : 8 bit pixel alpha blending
101 : 16 bit pixel alpha blending
*/	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp &= cClrb4 ;
		temp |= cSetb3 ;
	  temp |= cSetb2 ;
	  LCD_DataWrite(temp);
}



//[92h]=========================================================================
void BTE_S1_Color_8bit_Alpha(void)
{	
/*
S1 Color Depth
000 : 256 Color
001 : 64k Color
010 : 16M Color
011 : Constant Color
100 : 8 bit pixel alpha blending
101 : 16 bit pixel alpha blending
*/	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp |= cSetb4 ;
		temp &= cClrb3 ;
	  temp &= cClrb2 ;
	  LCD_DataWrite(temp);
}

//[92h]=========================================================================
void BTE_S1_Color_16bit_Alpha(void)
{	
/*
S1 Color Depth
000 : 256 Color
001 : 64k Color
010 : 16M Color
011 : Constant Color
100 : 8 bit pixel alpha blending
101 : 16 bit pixel alpha blending
*/	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp |= cSetb4 ;
		temp &= cClrb3 ;
	  temp |= cSetb2 ;
	  LCD_DataWrite(temp);
}

//[92h]=========================================================================
void BTE_Destination_Color_8bpp(void)
{	
/*
Destination Color Depth
00 : 256 Color
01 : 64k Color
1x : 16M Color
*/	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp &= cClrb1 ;
		temp &= cClrb0 ;
	  LCD_DataWrite(temp);
}	
//[92h]=========================================================================
void BTE_Destination_Color_16bpp(void)
{	
/*
Destination Color Depth
00 : 256 Color
01 : 64k Color
1x : 16M Color
*/	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp &= cClrb1 ;
		temp |= cSetb0 ;
	  LCD_DataWrite(temp);

}	
//[92h]=========================================================================
void BTE_Destination_Color_24bpp(void)
{	
/*
Destination Color Depth
00 : 256 Color
10 : 64k Color
1x : 16M Color
*/	
    unsigned char temp;
    LCD_CmdWrite(0x92);
    temp = LCD_DataRead();
    temp |= cSetb1 ;
		//temp |= cSetb0 ;
	  LCD_DataWrite(temp);
}

//[B6h]=========================================================================
void Start_SFI_DMA(void)
{
	uint8_t temp;
	LCD_CmdWrite(0xB6);
	temp = LCD_DataRead();
    temp |= cSetb0;
	LCD_DataWrite(temp);
}

void Check_Busy_SFI_DMA(void)
{
	LCD_CmdWrite(0xB6);
	do
	{		
	}while((LCD_DataRead()&0x01)==0x01);
}


//[B7h]=========================================================================
void Select_SFI_0(void)
{
/*[bit7]
Serial Flash/ROM I/F # Select
0: Serial Flash/ROM 0 I/F is selected.
1: Serial Flash/ROM 1 I/F is selected.
*/
	uint8_t temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
    temp &= cClrb7;
	LCD_DataWrite(temp);
}
void Select_SFI_1(void)
{
/*[bit7]
Serial Flash/ROM I/F # Select
0: Serial Flash/ROM 0 I/F is selected.
1: Serial Flash/ROM 1 I/F is selected.
*/
	uint8_t temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
    temp |= cSetb7;
	LCD_DataWrite(temp);
}

void Select_SFI_DMA_Mode(void)
{
/*[bit6]
Serial Flash /ROM Access Mode
0: Font mode  for external cgrom
1: DMA mode  for cgram , pattern , bootstart image or osd
*/
	uint8_t temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
    temp |= cSetb6;
	LCD_DataWrite(temp);
}

void Select_SFI_Dual_Mode0(void)
{
	uint8_t temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
	temp &= 0xFC;
    temp |= cSetb1;
	LCD_DataWrite(temp);
}

//REG[BB] SPI Clock period (SPIDIV) 
void SPI_Clock_Period(uint8_t temp)
{
   LCD_CmdWrite(0xBB);
   LCD_DataWrite(temp);
} 

//[BCh][BDh][BEh][BFh]=========================================================================
void SFI_DMA_Source_Start_Address(unsigned long Addr)
{
/*
DMA Source START ADDRESS
This bits index serial flash address [7:0][15:8][23:16][31:24]
*/
	LCD_CmdWrite(0xBC);
	LCD_DataWrite(Addr);
	LCD_CmdWrite(0xBD);
	LCD_DataWrite(Addr>>8);
	LCD_CmdWrite(0xBE);
	LCD_DataWrite(Addr>>16);
	LCD_CmdWrite(0xBF);
	LCD_DataWrite(Addr>>24);
}
//[C0h][C1h][C2h][C3h]=========================================================================

//[CAh][CBh]=========================================================================
void SFI_DMA_Source_Width(uint16_t WX)
{
/*
DMA Source Picture Width [7:0][12:8]
Unit: pixel
*/
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
//[93h][94h][95h][96h]=========================================================================
void BTE_S0_Memory_Start_Address(unsigned long Addr)	
{
/*
[93h] BTE S0 Memory Start Address [7:0]
[94h] BTE S0 Memory Start Address [15:8]
[95h] BTE S0 Memory Start Address [23:16]
[96h] BTE S0 Memory Start Address [31:24]
Bit [1:0] tie to ¨0〃 internally.
*/
	LCD_RegisterWrite(0x93,Addr);
	LCD_RegisterWrite(0x94,Addr>>8);
	LCD_RegisterWrite(0x95,Addr>>16);
	LCD_RegisterWrite(0x96,Addr>>24);
}


//[97h][98h]=========================================================================
void BTE_S0_Image_Width(unsigned short WX)	
{
/*
[97h] BTE S0 Image Width [7:0]
[98h] BTE S0 Image Width [12:8]
Unit: Pixel.
Bit [1:0] tie to ¨0〃 internally.
*/
	LCD_RegisterWrite(0x97,WX);
	LCD_RegisterWrite(0x98,WX>>8);
}


//[99h][9Ah][9Bh][9Ch]=========================================================================
void BTE_S0_Window_Start_XY(unsigned short WX,unsigned short HY)	
{
/*
[99h] BTE S0 Window Upper-Left corner X-coordination [7:0]
[9Ah] BTE S0 Window Upper-Left corner X-coordination [12:8]
[9Bh] BTE S0 Window Upper-Left corner Y-coordination [7:0]
[9Ch] BTE S0 Window Upper-Left corner Y-coordination [12:8]
*/
	LCD_RegisterWrite(0x99,WX);
	LCD_RegisterWrite(0x9A,WX>>8);

	LCD_RegisterWrite(0x9B,HY);
	LCD_RegisterWrite(0x9C,HY>>8);
}




//[9Dh][9Eh][9Fh][A0h]=========================================================================
void BTE_S1_Memory_Start_Address(unsigned long Addr)	
{
/*
[9Dh] BTE S1 Memory Start Address [7:0]
[9Eh] BTE S1 Memory Start Address [15:8]
[9Fh] BTE S1 Memory Start Address [23:16]
[A0h] BTE S1 Memory Start Address [31:24]
Bit [1:0] tie to ¨0〃 internally.
*/
	LCD_RegisterWrite(0x9D,Addr);
	LCD_RegisterWrite(0x9E,Addr>>8);
	LCD_RegisterWrite(0x9F,Addr>>16);
	LCD_RegisterWrite(0xA0,Addr>>24);
}


//Input data format:R3G3B2
void S1_Constant_color_256(unsigned char temp)
{
    LCD_CmdWrite(0x9D);
    LCD_DataWrite(temp);

    LCD_CmdWrite(0x9E);
    LCD_DataWrite(temp<<3);

    LCD_CmdWrite(0x9F);
    LCD_DataWrite(temp<<6);
}

//Input data format:R5G6B6
void S1_Constant_color_65k(unsigned short temp)
{
    LCD_CmdWrite(0x9D);
    LCD_DataWrite(temp>>8);

    LCD_CmdWrite(0x9E);
    LCD_DataWrite(temp>>3);

    LCD_CmdWrite(0x9F);
    LCD_DataWrite(temp<<3);
}

//Input data format:R8G8B8
void S1_Constant_color_16M(unsigned long temp)
{
    LCD_CmdWrite(0x9D);
    LCD_DataWrite(temp>>16);

    LCD_CmdWrite(0x9E);
    LCD_DataWrite(temp>>8);

    LCD_CmdWrite(0x9F);
    LCD_DataWrite(temp);
}




//[A1h][A2h]=========================================================================
void BTE_S1_Image_Width(unsigned short WX)	
{
/*
[A1h] BTE S1 Image Width [7:0]
[A2h] BTE S1 Image Width [12:8]
Unit: Pixel.
Bit [1:0] tie to ¨0〃 internally.
*/
	LCD_RegisterWrite(0xA1,WX);
	LCD_RegisterWrite(0xA2,WX>>8);
}


//[A3h][A4h][A5h][A6h]=========================================================================
void BTE_S1_Window_Start_XY(unsigned short WX,unsigned short HY)	
{
/*
[A3h] BTE S1 Window Upper-Left corner X-coordination [7:0]
[A4h] BTE S1 Window Upper-Left corner X-coordination [12:8]
[A5h] BTE S1 Window Upper-Left corner Y-coordination [7:0]
[A6h] BTE S1 Window Upper-Left corner Y-coordination [12:8]
*/
	LCD_RegisterWrite(0xA3,WX);
	LCD_RegisterWrite(0xA4,WX>>8);

	LCD_RegisterWrite(0xA5,HY);
	LCD_RegisterWrite(0xA6,HY>>8);
}




//[A7h][A8h][A9h][AAh]=========================================================================
void BTE_Destination_Memory_Start_Address(unsigned long Addr)	
{
/*
[A7h] BTE Destination Memory Start Address [7:0]
[A8h] BTE Destination Memory Start Address [15:8]
[A9h] BTE Destination Memory Start Address [23:16]
[AAh] BTE Destination Memory Start Address [31:24]
Bit [1:0] tie to ¨0〃 internally.
*/
	LCD_RegisterWrite(0xA7,Addr);
	LCD_RegisterWrite(0xA8,Addr>>8);
	LCD_RegisterWrite(0xA9,Addr>>16);
	LCD_RegisterWrite(0xAA,Addr>>24);
}


//[ABh][ACh]=========================================================================
void BTE_Destination_Image_Width(unsigned short WX)	
{
/*
[ABh] BTE Destination Image Width [7:0]
[ACh] BTE Destination Image Width [12:8]
Unit: Pixel.
Bit [1:0] tie to ¨0〃 internally.
*/
	LCD_RegisterWrite(0xAB,WX);
	LCD_RegisterWrite(0xAC,WX>>8);
}


//[ADh][AEh][AFh][B0h]=========================================================================
void BTE_Destination_Window_Start_XY(unsigned short WX,unsigned short HY)	
{
/*
[ADh] BTE Destination Window Upper-Left corner X-coordination [7:0]
[AEh] BTE Destination Window Upper-Left corner X-coordination [12:8]
[AFh] BTE Destination Window Upper-Left corner Y-coordination [7:0]
[B0h] BTE Destination Window Upper-Left corner Y-coordination [12:8]
*/
	LCD_RegisterWrite(0xAD,WX);
	LCD_RegisterWrite(0xAE,WX>>8);

	LCD_RegisterWrite(0xAF,HY);
	LCD_RegisterWrite(0xB0,HY>>8);
}


//[B1h][B2h][B3h][B4h]===============================================================

void BTE_Window_Size(unsigned short WX, unsigned short WY)

{
/*
[B1h] BTE Window Width [7:0]
[B2h] BTE Window Width [12:8]

[B3h] BTE Window Height [7:0]
[B4h] BTE Window Height [12:8]
*/
        LCD_RegisterWrite(0xB1,WX);
        LCD_RegisterWrite(0xB2,WX>>8);
	
	    LCD_RegisterWrite(0xB3,WY);
        LCD_RegisterWrite(0xB4,WY>>8);
}

//[B5h]=========================================================================
void BTE_Alpha_Blending_Effect(unsigned char temp)
{	
/*
Window Alpha Blending effect for S0 & S1
The value of alpha in the color code ranges from 0.0 to 1.0,
where 0.0 represents a fully transparent color, and 1.0
represents a fully opaque color.
00h: 0
01h: 1/32
02h: 2/32
:
1Eh: 30/32
1Fh: 31/32
2Xh: 1
Output Effect = (S0 image x (1 - alpha setting value)) + (S1 image x alpha setting value)
*/
    LCD_CmdWrite(0xB5);
	LCD_DataWrite(temp);  
}

void Select_SFI_Font_Mode(void)
{
/*[bit6]
Serial Flash /ROM Access Mode
0: Font mode  for external cgrom
1: DMA mode  for cgram , pattern , bootstart image or osd
*/
	unsigned char temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
    temp &= cClrb6;
	LCD_DataWrite(temp);
}

void Select_SFI_24bit_Address(void)
{
/*[bit5]
Serial Flash/ROM Address Mode
0: 24 bits address mode
1: 32 bits address mode
*/
	unsigned char temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
    temp &= cClrb5;
	LCD_DataWrite(temp);
}
void Select_SFI_32bit_Address(void)
{
/*[bit5]
Serial Flash/ROM Address Mode
0: 24 bits address mode
1: 32 bits address mode
*/
	unsigned char temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
    temp |= cSetb5;
	LCD_DataWrite(temp);
}
void Select_SFI_Waveform_Mode_0(void)
{
/*[bit4]
Serial Flash/ROM Waveform Mode
Mode 0.
Mode 3.
*/
	unsigned char temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
    temp &= cClrb4;
	LCD_DataWrite(temp);
}
void Select_SFI_Waveform_Mode_3(void)
{
/*[bit4]
Serial Flash/ROM Waveform Mode
Mode 0.
Mode 3.
*/
	unsigned char temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
    temp |= cSetb4;
	LCD_DataWrite(temp);
}
void Select_SFI_0_DummyRead(void)
{
/*[bit3][bit2]
Serial Flash /ROM Read Cycle 0 RW
00b: no dummy cycle mode
01b: 1 dummy cycle mode
10b: 2 dummy cycle mode
11b: 4 dummy cycle mode
*/
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
    temp |= cSetb2;
	LCD_DataWrite(temp);
}
void Select_SFI_16_DummyRead(void)
{

	unsigned char temp;
	LCD_CmdWrite(0xB7);
	temp = LCD_DataRead();
	temp &= 0xF3;
    temp |= cSetb3;
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
/*[bit1][bit0]
Serial Flash /ROM I/F Data Latch Mode Select
0Xb: Single Mode
10b: Dual Mode 0.
11b: Dual Mode 1.
*/
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

//REG[B8h] SPI master Tx /Rx FIFO Data Register (SPIDR) 
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
	//while(Rx_FIFO_full_flag());
   return temp;
}

//REG[B9h] SPI master Control Register (SPIMCR2) 
void Mask_SPI_Master_Interrupt_Flag(void)
{
  unsigned char temp;
  LCD_CmdWrite(0xB9);
  temp = LCD_DataRead();
  temp |= cSetb6;
  LCD_DataWrite(temp);

} 

void Select_nSS_drive_on_xnsfcs0(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB9);
	temp = LCD_DataRead();
	temp &= cClrb5;
	LCD_DataWrite(temp);

}

void Select_nSS_drive_on_xnsfcs1(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB9);
	temp = LCD_DataRead();
	temp |= cSetb5;
	LCD_DataWrite(temp);
}

//0: inactive (nSS port will goes high) 
void nSS_Inactive(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB9);
	temp = LCD_DataRead();
	temp &= cClrb4;
	LCD_DataWrite(temp);
}
//1: active (nSS port will goes low) 
void nSS_Active(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB9);
	temp = LCD_DataRead();
	temp |= cSetb4;
	LCD_DataWrite(temp);
}

//Interrupt enable for FIFO overflow error [OVFIRQEN] 
void OVFIRQEN_Enable(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB9);
	temp = LCD_DataRead();
	temp |= cSetb3;
	LCD_DataWrite(temp);
}
//Interrupt enable for while Tx FIFO empty & SPI engine/FSM idle
void EMTIRQEN_Enable(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB9);
	temp = LCD_DataRead();
	temp |= cSetb2;
	LCD_DataWrite(temp);
}


//At CPOL=0 the base value of the clock is zero   
//o  For CPHA=0, data are read on the clock's rising edge (low->high transition) and 
//data are changed on a falling edge (high->low clock transition). 
//o  For CPHA=1, data are read on the clock's falling edge and data are changed on a 
//rising edge. 

//At CPOL=1 the base value of the clock is one (inversion of CPOL=0)   
//o  For CPHA=0, data are read on clock's falling edge and data are changed on a 
//rising edge. 
//o  For CPHA=1, data are read on clock's rising edge and data are changed on a 
//falling edge.

void Reset_CPOL(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB9);
	temp = LCD_DataRead();
	temp &= cClrb1;
	LCD_DataWrite(temp);
}

void Set_CPOL(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB9);
	temp = LCD_DataRead();
	temp |= cSetb1;
	LCD_DataWrite(temp);
}


void Reset_CPHA(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB9);
	temp = LCD_DataRead();
	temp &= cClrb0;
	LCD_DataWrite(temp);
}

void Set_CPHA(void)
{
	unsigned char temp;
	LCD_CmdWrite(0xB9);
	temp = LCD_DataRead();
	temp |= cSetb0;
	LCD_DataWrite(temp);
}


//REG[BAh] SPI master Status Register (SPIMSR) 
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
   temp |= cSetb3;
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
   temp |= cSetb2;
   LCD_DataWrite(temp);
}

//[C0h][C1h][C2h][C3h]=========================================================================
void SFI_DMA_Destination_Start_Address(unsigned long Addr)
{
/*
DMA Destination START ADDRESS 
[1:0]Fix at 0
This bits index SDRAM address [7:0][15:8][23:16][31:24]
*/
	LCD_CmdWrite(0xC0);
	LCD_DataWrite(Addr);
	LCD_CmdWrite(0xC1);
	LCD_DataWrite(Addr>>8);
	LCD_CmdWrite(0xC2);
	LCD_DataWrite(Addr>>16);
	LCD_CmdWrite(0xC3);
	LCD_DataWrite(Addr>>24);
}
//[C0h][C1h][C2h][C3h]=========================================================================
void SFI_DMA_Destination_Upper_Left_Corner(unsigned short WX,unsigned short HY)
{
/*
C0h
This register defines DMA Destination Window Upper-Left corner 
X-coordination [7:0] on Canvas area. 
When REG DMACR bit 1 = 1 (Block Mode) 
This register defines Destination address [7:2] in SDRAM. 
C1h
When REG DMACR bit 1 = 0 (Linear Mode) 
This register defines DMA Destination Window Upper-Left corner 
X-coordination [12:8] on Canvas area. 
When REG DMACR bit 1 = 1 (Block Mode) 
This register defines Destination address [15:8] in SDRAM.
C2h
When REG DMACR bit 1 = 0 (Linear Mode) 
This register defines DMA Destination Window Upper-Left corner
Y-coordination [7:0] on Canvas area. 
When REG DMACR bit 1 = 1 (Block Mode) 
This register defines Destination address [23:16] in SDRAM. 
C3h
When REG DMACR bit 1 = 0 (Linear Mode) 
This register defines DMA Destination Window Upper-Left corner 
Y-coordination [12:8] on Canvas area. 
When REG DMACR bit 1 = 1 (Block Mode) 
This register defines Destination address [31:24] in SDRAM. 
*/
 
	LCD_CmdWrite(0xC0);
	LCD_DataWrite(WX);
	LCD_CmdWrite(0xC1);
	LCD_DataWrite(WX>>8);
 
	LCD_CmdWrite(0xC2);
	LCD_DataWrite(HY);
	LCD_CmdWrite(0xC3);
	LCD_DataWrite(HY>>8);
}

//[C6h][C7h][C8h][C9h]=========================================================================
void SFI_DMA_Transfer_Number(unsigned long Addr)
{
/*
Unit : Pixel
When REG DMACR bit 1 = 0 (Linear Mode)
DMA Transfer Number [7:0][15:8][23:16][31:24]

When REG DMACR bit 1 = 1 (Block Mode)
DMA Block Width [7:0][15:8]
DMA Block HIGH[7:0][15:8]
*/
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
/*
When REG DMACR bit 1 = 0 (Linear Mode)
DMA Transfer Number [7:0][15:8][23:16][31:24]

When REG DMACR bit 1 = 1 (Block Mode)
DMA Block Width [7:0][15:8]
DMA Block HIGH[7:0][15:8]
*/
	LCD_CmdWrite(0xC6);
	LCD_DataWrite(WX);
	LCD_CmdWrite(0xC7);
	LCD_DataWrite(WX>>8);

	LCD_CmdWrite(0xC8);
	LCD_DataWrite(HY);
	LCD_CmdWrite(0xC9);
	LCD_DataWrite(HY>>8);
}

//[CCh]=========================================================================

void Font_Select_UserDefine_Mode(void)
{
/*[bit7-6]
User-defined Font /CGROM Font Selection Bit in Text Mode
00 : Internal CGROM
01 : Genitop serial flash
10 : User-defined Font
*/
	unsigned char temp;
	LCD_CmdWrite(0xCC);
	temp = LCD_DataRead();
    temp |= cSetb7;
	temp &= cClrb6;
	LCD_DataWrite(temp);
}
void CGROM_Select_Internal_CGROM(void)
{
/*[bit7-6]
User-defined Font /CGROM Font Selection Bit in Text Mode
00 : Internal CGROM
01 : Genitop serial flash
10 : User-defined Font
*/
	unsigned char temp;
	LCD_CmdWrite(0xCC);
	temp = LCD_DataRead();
	temp &= cClrb7;
    temp &= cClrb6;
	LCD_DataWrite(temp);
}
void CGROM_Select_Genitop_FontROM(void)
{
/*[bit7-6]
User-defined Font /CGROM Font Selection Bit in Text Mode
00 : Internal CGROM
01 : Genitop serial flash
10 : User-defined Font
*/
	unsigned char temp;
	LCD_CmdWrite(0xCC);
	temp = LCD_DataRead();
	temp &= cClrb7;
    temp |= cSetb6;
	LCD_DataWrite(temp);
}
void Font_Select_8x16_16x16(void)
{
/*[bit5-4]
Font Height Setting
00b : 8x16 / 16x16.
01b : 12x24 / 24x24.
10b : 16x32 / 32x32.
*** User-defined Font width is decided by font code. Genitop
serial flashˇs font width is decided by font code or GT Font ROM
control register.
*/
	unsigned char temp;
	LCD_CmdWrite(0xCC);
	temp = LCD_DataRead();
    temp &= cClrb5;
    temp &= cClrb4;
	LCD_DataWrite(temp);
}
void Font_Select_12x24_24x24(void)
{
/*[bit5-4]
Font Height Setting
00b : 8x16 / 16x16.
01b : 12x24 / 24x24.
10b : 16x32 / 32x32.
*** User-defined Font width is decided by font code. Genitop
serial flashˇs font width is decided by font code or GT Font ROM
control register.
*/
	unsigned char temp;
	LCD_CmdWrite(0xCC);
	temp = LCD_DataRead();
    temp &= cClrb5;
    temp |= cSetb4;
	LCD_DataWrite(temp);
}
void Font_Select_16x32_32x32(void)
{
/*[bit5-4]
Font Height Setting
00b : 8x16 / 16x16.
01b : 12x24 / 24x24.
10b : 16x32 / 32x32.
*** User-defined Font width is decided by font code. Genitop
serial flashˇs font width is decided by font code or GT Font ROM
control register.
*/
	unsigned char temp;
	LCD_CmdWrite(0xCC);
	temp = LCD_DataRead();
    temp |= cSetb5;
    temp &= cClrb4;
	LCD_DataWrite(temp);
}
void Internal_CGROM_Select_ISOIEC8859_1(void)
{
/*
Font Selection for internal CGROM
When FNCR0 B7 = 0 and B5 = 0, Internal CGROM supports the
8x16 character sets with the standard coding of ISO/IEC 8859-1~4, 
which supports English and most of European country languages.
00b : ISO/IEC 8859-1.
01b : ISO/IEC 8859-2.
10b : ISO/IEC 8859-3.
11b : ISO/IEC 8859-4.
*/
	unsigned char temp;
	LCD_CmdWrite(0xCC);
	temp = LCD_DataRead();
    temp &= cClrb1;
    temp &= cClrb0;
	LCD_DataWrite(temp);
}
void Internal_CGROM_Select_ISOIEC8859_2(void)
{
/*
Font Selection for internal CGROM
When FNCR0 B7 = 0 and B5 = 0, Internal CGROM supports the
8x16 character sets with the standard coding of ISO/IEC 8859-1~4, 
which supports English and most of European country languages.
00b : ISO/IEC 8859-1.
01b : ISO/IEC 8859-2.
10b : ISO/IEC 8859-3.
11b : ISO/IEC 8859-4.
*/
	unsigned char temp;
	LCD_CmdWrite(0xCC);
	temp = LCD_DataRead();
    temp &= cClrb1;
    temp |= cSetb0;
	LCD_DataWrite(temp);
}
void Internal_CGROM_Select_ISOIEC8859_3(void)
{
/*
Font Selection for internal CGROM
When FNCR0 B7 = 0 and B5 = 0, Internal CGROM supports the
8x16 character sets with the standard coding of ISO/IEC 8859-1~4, 
which supports English and most of European country languages.
00b : ISO/IEC 8859-1.
01b : ISO/IEC 8859-2.
10b : ISO/IEC 8859-3.
11b : ISO/IEC 8859-4.
*/
	unsigned char temp;
	LCD_CmdWrite(0xCC);
	temp = LCD_DataRead();
    temp |= cSetb1;
    temp &= cClrb0;
	LCD_DataWrite(temp);
}
void Internal_CGROM_Select_ISOIEC8859_4(void)
{
/*
Font Selection for internal CGROM
When FNCR0 B7 = 0 and B5 = 0, Internal CGROM supports the
8x16 character sets with the standard coding of ISO/IEC 8859-1~4, 
which supports English and most of European country languages.
00b : ISO/IEC 8859-1.
01b : ISO/IEC 8859-2.
10b : ISO/IEC 8859-3.
11b : ISO/IEC 8859-4.
*/
	unsigned char temp;
	LCD_CmdWrite(0xCC);
	temp = LCD_DataRead();
    temp |= cSetb1;
    temp |= cSetb0;
	LCD_DataWrite(temp);
}
//[CDh]=========================================================================
void Enable_Font_Alignment(void)
{
/*
Full Alignment Selection Bit
0 : Full alignment disable.
1 : Full alignment enable.
*/
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp |= cSetb7;
	LCD_DataWrite(temp);
}
void Disable_Font_Alignment(void)
{
/*
Full Alignment Selection Bit
0 : Full alignment disable.
1 : Full alignment enable.
*/
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp &= cClrb7;
	LCD_DataWrite(temp);
}
void Font_Background_select_Transparency(void)
{
/*
Font Transparency
0 : Font with background color.
1 : Font with background transparency.
*/
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp |= cSetb6;
	LCD_DataWrite(temp);
}
void Font_Background_select_Color(void)
{
/*
Font Transparency
0 : Font with background color.
1 : Font with background transparency.
*/
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp &= cClrb6;
	LCD_DataWrite(temp);
}
void Font_0_degree(void)
{
/*
Font Rotation
0 : Normal
Text direction from left to right then from top to bottom
1 : Counterclockwise 90 degree & horizontal flip
Text direction from top to bottom then from left to right
(it should accommodate with set VDIR as 1)
This attribute can be changed only when previous font write
finished (core_busy = 0)
*/
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp &= cClrb4;
	LCD_DataWrite(temp);
}
void Font_90_degree(void)
{
/*
Font Rotation
0 : Normal
Text direction from left to right then from top to bottom
1 : Counterclockwise 90 degree & horizontal flip
Text direction from top to bottom then from left to right
(it should accommodate with set VDIR as 1)
This attribute can be changed only when previous font write
finished (core_busy = 0)
*/
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp |= cSetb4;
	LCD_DataWrite(temp);
}
void Font_Width_X1(void)
{
/*
Horizontal Font Enlargement
00b : X1.
01b : X2.
10b : X3.
11b : X4.
*/
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp &= cClrb3;
    temp &= cClrb2;
	LCD_DataWrite(temp);
}
void Font_Width_X2(void)
{
/*
Horizontal Font Enlargement
00b : X1.
01b : X2.
10b : X3.
11b : X4.
*/
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp &= cClrb3;
    temp |= cSetb2;
	LCD_DataWrite(temp);
}
void Font_Width_X3(void)
{
/*
Horizontal Font Enlargement
00b : X1.
01b : X2.
10b : X3.
11b : X4.
*/
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp |= cSetb3;
    temp &= cClrb2;
	LCD_DataWrite(temp);
}
void Font_Width_X4(void)
{
/*
Horizontal Font Enlargement
00b : X1.
01b : X2.
10b : X3.
11b : X4.
*/
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp |= cSetb3;
    temp |= cSetb2;
	LCD_DataWrite(temp);
}
void Font_Height_X1(void)
{
/*
Vertical Font Enlargement
00b : X1.
01b : X2.
10b : X3.
11b : X4.
*/
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp &= cClrb1;
    temp &= cClrb0;
	LCD_DataWrite(temp);
}
void Font_Height_X2(void)
{
/*
Vertical Font Enlargement
00b : X1.
01b : X2.
10b : X3.
11b : X4.
*/
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp &= cClrb1;
    temp |= cSetb0;
	LCD_DataWrite(temp);
}
void Font_Height_X3(void)
{
/*
Vertical Font Enlargement
00b : X1.
01b : X2.
10b : X3.
11b : X4.
*/
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp |= cSetb1;
    temp &= cClrb0;
	LCD_DataWrite(temp);
}
void Font_Height_X4(void)
{
/*
Vertical Font Enlargement
00b : X1.
01b : X2.
10b : X3.
11b : X4.
*/
	unsigned char temp;
	LCD_CmdWrite(0xCD);
	temp = LCD_DataRead();
    temp |= cSetb1;
    temp |= cSetb0;
	LCD_DataWrite(temp);
}

//[CEh]=========================================================================
void GTFont_Select_GT21L16TW_GT21H16T1W(void)
{
/*
GT Serial Font ROM Select
000b: GT21L16TW / GT21H16T1W
001b: GT23L16U2W
010b: GT23L24T3Y / GT23H24T3Y
011b: GT23L24M1Z
100b: GT23L32S4W / GT23H32S4W
101b: GT20L24F6Y
110b: GT21L24S1W
111b: GT22L16A1Y
*/
	unsigned char temp;
	LCD_CmdWrite(0xCE);
	temp = LCD_DataRead();
    temp &= cClrb7;
    temp &= cClrb6;
    temp &= cClrb5;
	LCD_DataWrite(temp);
}
void GTFont_Select_GT23L16U2W(void)
{
/*
GT Serial Font ROM Select
000b: GT21L16TW / GT21H16T1W
001b: GT23L16U2W
010b: GT23L24T3Y / GT23H24T3Y
011b: GT23L24M1Z
100b: GT23L32S4W / GT23H32S4W
101b: GT20L24F6Y
110b: GT21L24S1W
111b: GT22L16A1Y
*/
	unsigned char temp;
	LCD_CmdWrite(0xCE);
	temp = LCD_DataRead();
    temp &= cClrb7;
    temp &= cClrb6;
    temp |= cSetb5;
	LCD_DataWrite(temp);
}
void GTFont_Select_GT23L24T3Y_GT23H24T3Y(void)
{
/*
GT Serial Font ROM Select
000b: GT21L16TW / GT21H16T1W
001b: GT23L16U2W
010b: GT23L24T3Y / GT23H24T3Y
011b: GT23L24M1Z
100b: GT23L32S4W / GT23H32S4W
101b: GT20L24F6Y
110b: GT21L24S1W
111b: GT22L16A1Y
*/
	unsigned char temp;
	LCD_CmdWrite(0xCE);
	temp = LCD_DataRead();
    temp &= cClrb7;
    temp |= cSetb6;
    temp &= cClrb5;
	LCD_DataWrite(temp);
}
void GTFont_Select_GT23L24M1Z(void)
{
/*
GT Serial Font ROM Select
000b: GT21L16TW / GT21H16T1W
001b: GT23L16U2W
010b: GT23L24T3Y / GT23H24T3Y
011b: GT23L24M1Z
100b: GT23L32S4W / GT23H32S4W
101b: GT20L24F6Y
110b: GT21L24S1W
111b: GT22L16A1Y
*/
	unsigned char temp;
	LCD_CmdWrite(0xCE);
	temp = LCD_DataRead();
    temp &= cClrb7;
    temp |= cSetb6;
    temp |= cSetb5;
	LCD_DataWrite(temp);
}
void GTFont_Select_GT23L32S4W_GT23H32S4W(void)
{
/*
GT Serial Font ROM Select
000b: GT21L16TW / GT21H16T1W
001b: GT23L16U2W
010b: GT23L24T3Y / GT23H24T3Y
011b: GT23L24M1Z
100b: GT23L32S4W / GT23H32S4W
101b: GT20L24F6Y
110b: GT21L24S1W
111b: GT22L16A1Y
*/
	unsigned char temp;
	LCD_CmdWrite(0xCE);
	temp = LCD_DataRead();
    temp |= cSetb7;
    temp &= cClrb6;
    temp &= cClrb5;
	LCD_DataWrite(temp);
}
void GTFont_Select_GT20L24F6Y(void)
{
/*
GT Serial Font ROM Select
000b: GT21L16TW / GT21H16T1W
001b: GT23L16U2W
010b: GT23L24T3Y / GT23H24T3Y
011b: GT23L24M1Z
100b: GT23L32S4W / GT23H32S4W
101b: GT20L24F6Y
110b: GT21L24S1W
111b: GT22L16A1Y
*/
	unsigned char temp;
	LCD_CmdWrite(0xCE);
	temp = LCD_DataRead();
    temp |= cSetb7;
    temp &= cClrb6;
    temp |= cSetb5;
	LCD_DataWrite(temp);
}
void GTFont_Select_GT21L24S1W(void)
{
/*
GT Serial Font ROM Select
000b: GT21L16TW / GT21H16T1W
001b: GT23L16U2W
010b: GT23L24T3Y / GT23H24T3Y
011b: GT23L24M1Z
100b: GT23L32S4W / GT23H32S4W
101b: GT20L24F6Y
110b: GT21L24S1W
111b: GT22L16A1Y
*/
	unsigned char temp;
	LCD_CmdWrite(0xCE);
	temp = LCD_DataRead();
    temp |= cSetb7;
    temp |= cSetb6;
    temp &= cClrb5;
	LCD_DataWrite(temp);
}
void GTFont_Select_GT22L16A1Y(void)
{
/*
GT Serial Font ROM Select
000b: GT21L16TW / GT21H16T1W
001b: GT23L16U2W
010b: GT23L24T3Y / GT23H24T3Y
011b: GT23L24M1Z
100b: GT23L32S4W / GT23H32S4W
101b: GT20L24F6Y
110b: GT21L24S1W
111b: GT22L16A1Y
*/
	unsigned char temp;
	LCD_CmdWrite(0xCE);
	temp = LCD_DataRead();
    temp |= cSetb7;
    temp |= cSetb6;
    temp |= cSetb5;
	LCD_DataWrite(temp);
}

//[CFh]=========================================================================
void Set_GTFont_Decoder(unsigned char temp)
{
/*
[bit7-3]
FONT ROM Coding Setting
For specific GT serial Font ROM, the coding method must be set for decoding.
00000b: GB2312
00001b: GB12345/GB18030
00010b: BIG5
00011b: UNICODE
00100b: ASCII
00101b: UNI-Japanese
00110b: JIS0208
00111b: Latin/Greek/ Cyrillic / Arabic/Thai/Hebrew
01000b: Korea
10001b: ISO-8859-1
10010b: ISO-8859-2
10011b: ISO-8859-3
10100b: ISO-8859-4
10101b: ISO-8859-5
10110b: ISO-8859-6
10111b: ISO-8859-7
11000b: ISO-8859-8
11001b: ISO-8859-9
11010b: ISO-8859-10
11011b: ISO-8859-11
11100b: ISO-8859-12
11101b: ISO-8859-13
11110b: ISO-8859-14
11111b: ISO-8859-15

[bit1-0]
ASCII / Latin/Greek/ Cyrillic / Arabic
		(ASCII)		(Latin/Greek/Cyrillic)	(Arabic)
00b		Normal			Normal 					NA
01b		Arial 		Variable Width 			Presentation Forms-A
10b		Roman 			NA 					Presentation Forms-B
11b		Bold			NA 						NA
*/
	LCD_CmdWrite(0xCF);
	LCD_DataWrite(temp);
}
//[D0h]=========================================================================
void Font_Line_Distance(unsigned char temp)
{
/*[bit4-0]
Font Line Distance Setting
Setting the font character line distance when setting memory font
write cursor auto move. (Unit: pixel)
*/
	LCD_CmdWrite(0xD0);
	LCD_DataWrite(temp);
}
//[D1h]=========================================================================
void Set_Font_to_Font_Width(unsigned char temp)
{
/*[bit5-0]
Font to Font Width Setting (Unit: pixel)
*/
	LCD_CmdWrite(0xD1);
	LCD_DataWrite(temp);
}
//[D2h]~[D4h]=========================================================================
void Foreground_RGB(unsigned char RED,unsigned char GREEN,unsigned char BLUE)
{
/*
[D2h] Foreground Color - Red, for draw, text or color expansion
[D3h] Foreground Color - Green, for draw, text or color expansion
[D4h] Foreground Color - Blue, for draw, text or color expansion
*/  
    LCD_CmdWrite(0xD2);
	LCD_DataWrite(RED);
 
    LCD_CmdWrite(0xD3);
	LCD_DataWrite(GREEN);
  
    LCD_CmdWrite(0xD4);
	LCD_DataWrite(BLUE);
}

//Input data format:R3G3B2  
void Foreground_color_256(unsigned char temp) 
{
    LCD_CmdWrite(0xD2);
	LCD_DataWrite(temp);
 
    LCD_CmdWrite(0xD3);
	LCD_DataWrite(temp<<3);
  
    LCD_CmdWrite(0xD4);
	LCD_DataWrite(temp<<6);
}
 
//Input data format:R8G8B8 
void Foreground_color_16M(unsigned long temp)
{
    LCD_CmdWrite(0xD2);
 	LCD_DataWrite(temp>>16);
 
    LCD_CmdWrite(0xD3);
 	LCD_DataWrite(temp>>8);
  
    LCD_CmdWrite(0xD4);
 	LCD_DataWrite(temp);
}
 
//[D5h]~[D7h]=========================================================================
/*
[D5h] Background Color - Red, for Text or color expansion
[D6h] Background Color - Green, for Text or color expansion
[D7h] Background Color - Blue, for Text or color expansion
*/ 
void Background_RGB(unsigned char RED,unsigned char GREEN,unsigned char BLUE)
{
   
  LCD_CmdWrite(0xD5);
	LCD_DataWrite(RED);
  
  LCD_CmdWrite(0xD6);
	LCD_DataWrite(GREEN);
   
  LCD_CmdWrite(0xD7);
	LCD_DataWrite(BLUE);
}
 
//Input data format:R3G3B2
void Background_color_256(unsigned char temp)
{
    LCD_CmdWrite(0xD5);
 	LCD_DataWrite(temp);
  
    LCD_CmdWrite(0xD6);
 	LCD_DataWrite(temp<<3);
   
    LCD_CmdWrite(0xD7);
 	LCD_DataWrite(temp<<6);
}
 
//Input data format:R5G6B6
void Background_color_65k(unsigned short temp)
{
    LCD_CmdWrite(0xD5);
 	LCD_DataWrite(temp>>8);
  
    LCD_CmdWrite(0xD6);
 	LCD_DataWrite(temp>>3);
   
    LCD_CmdWrite(0xD7);
 	LCD_DataWrite(temp<<3);
}
 
//Input data format:R8G8B8
void Background_color_16M(unsigned long temp)
{
    LCD_CmdWrite(0xD5);
 	LCD_DataWrite(temp>>16);
  
    LCD_CmdWrite(0xD6);
 	LCD_DataWrite(temp>>8);
   
    LCD_CmdWrite(0xD7);
 	LCD_DataWrite(temp);
}

//[DBh]~[DEh]=========================================================================
void CGRAM_Start_address(unsigned long Addr)
{
/*
CGRAM START ADDRESS [31:0]
*/	 
    LCD_CmdWrite(0xDB);
	LCD_DataWrite(Addr);
    LCD_CmdWrite(0xDC);
	LCD_DataWrite(Addr>>8);
    LCD_CmdWrite(0xDD);
	LCD_DataWrite(Addr>>16);
    LCD_CmdWrite(0xDE);
	LCD_DataWrite(Addr>>24);
}

//[DFh]=========================================================================
/*
[bit7] Enter Power saving state
0: Normal state.
1: Enter power saving state.
[bit1][bit0] Power saving Mode definition
00: NA
01: Standby Mode
10: Suspend Mode
11: Sleep Mode
*/
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
//	LCD_DataWrite(0x02);
//	LCD_CmdWrite(0xDF);
	LCD_DataWrite(0x82);
}
void Power_Saving_Sleep_Mode(void)
{
	LCD_CmdWrite(0xDF);
//	LCD_DataWrite(0x03);
//	LCD_CmdWrite(0xDF);
	LCD_DataWrite(0x83);
}


//[E5h]~[E6h]=========================================================================
void LT768_I2CM_Clock_Prescale(unsigned short WX)
{
/*
I2C Master Clock Pre-scale [7:0]
I2C Master Clock Pre-scale [15:8]
*/  
    LCD_CmdWrite(0xE5);
	LCD_DataWrite(WX);
    LCD_CmdWrite(0xE6);
	LCD_DataWrite(WX>>8);
}
//[E7h]=========================================================================
void LT768_I2CM_Transmit_Data(unsigned char temp)
{
/*
I2C Master Transmit[7:0]
*/  
    LCD_CmdWrite(0xE7);
	LCD_DataWrite(temp);
}
//[E8h]=========================================================================
unsigned char LT768_I2CM_Receiver_Data(void)
{
/*
I2C Master Receiver [7:0]
*/  
	unsigned char temp;
    LCD_CmdWrite(0xE8);
	temp=LCD_DataRead();
	return temp;
}
//[E9h]=========================================================================
/*
[bit7] START
Generate (repeated) start condition and be cleared by hardware automatically
Note : This bit is always read as 0.
[bit6] STOP
Generate stop condition and be cleared by hardware automatically
Note : This bit is always read as 0.
[bit5]
READ(READ and WRITE canˇt be used simultaneously)
Read form slave and be cleared by hardware automatically
Note : This bit is always read as 0.
[bit4]
WRITE(READ and WRITE canˇt be used simultaneously)
Write to slave and be cleared by hardware automatically
Note : This bit is always read as 0.
[bit3] ACKNOWLEDGE
When as a I2C master receiver
0 : Sent ACK.
1 : Sent NACK.
Note : This bit is always read as 0.
[bit0] Noise Filter
0 : Enable.
1 : Disable.
*/

#define Disable_I2CM_Noise_Filter
 
void LT768_I2CM_Stop(void)
{
	LCD_CmdWrite(0xE9);
	#ifdef Disable_I2CM_Noise_Filter 
	LCD_DataWrite(0x40);
	#endif
 
	#ifdef Enable_I2CM_Noise_Filter 
	LCD_DataWrite(0x41);
	#endif
}
void LT768_I2CM_Read_With_Ack(void)
{
 
 LCD_CmdWrite(0xE9);
	#ifdef Disable_I2CM_Noise_Filter 
 LCD_DataWrite(0x20);
	#endif
	
	#ifdef Enable_I2CM_Noise_Filter 
 LCD_DataWrite(0x21);
	#endif
}
 
void LT768_I2CM_Read_With_Nack(void)
{
 
	LCD_CmdWrite(0xE9);
	#ifdef Disable_I2CM_Noise_Filter 
	LCD_DataWrite(0x68);
	#endif
	
	#ifdef Enable_I2CM_Noise_Filter 
	LCD_DataWrite(0x69);
	#endif
}
 
void LT768_I2CM_Write_With_Start(void)
{
	LCD_CmdWrite(0xE9);
	#ifdef Disable_I2CM_Noise_Filter 
	LCD_DataWrite(0x90);
	#endif
 
	#ifdef Enable_I2CM_Noise_Filter 
	LCD_DataWrite(0x91);
	#endif
}
 
void LT768_I2CM_Write(void)
{
	LCD_CmdWrite(0xE9);
	#ifdef Disable_I2CM_Noise_Filter 
	LCD_DataWrite(0x10);
	#endif
	
	#ifdef Enable_I2CM_Noise_Filter 
	LCD_DataWrite(0x11);
	#endif
}
 
 
 
//[EAh]=========================================================================
/*
 0=Ack
 1=Nack
*/
unsigned char LT768_I2CM_Check_Slave_ACK(void)
{ 
	unsigned char temp;
/*[bit7]
Received acknowledge from slave
0 : Acknowledge received.
1 : No Acknowledge received. 
*/ 
	LCD_CmdWrite(0xEA);
	temp=LCD_DataRead();
	if((temp&0x80)==0x80)
	return 1;
	else
	return 0; 
}
 

/*
 0=Idle
 1=Busy
*/
unsigned char LT768_I2CM_Bus_Busy(void)
{
	unsigned char temp; 
 
/*[bit6]
I2C Bus is Busy
0 : Idle.
1 : Busy.  
*/ 
	LCD_CmdWrite(0xEA);
	temp=LCD_DataRead();
	if((temp&0x40)==0x40)
	return 1;
	else
	return 0;    
}
 
/*
 0=Complete
 1=Transferring
*/
unsigned char LT768_I2CM_transmit_Progress(void)
{
	unsigned char temp; 
/*[bit6]
 0=Complete
 1=Transferring
*/ 
	LCD_CmdWrite(0xEA);
	temp=LCD_DataRead();
	if((temp&0x02)==0x02)
	return 1;
	else
	return 0;
}
 
 /*
 0= Arbitration win
 1= Arbitration lost
*/
unsigned char LT768_I2CM_Arbitration(void)
{
	unsigned char temp; 
/*[bit6]
I2C Bus is Busy
0 : Idle.
1 : Busy.  
*/ 
	LCD_CmdWrite(0xEA);
	temp=LCD_DataRead();
	temp&=0x01;
	return temp;
}


//[F0h]=========================================================================
void Set_GPIO_A_In_Out(unsigned char temp)
{
/*
GPO-A_dir[7:0] : General Purpose I/O direction control.
0: Output
1: Input
*/
	LCD_CmdWrite(0xF0);
	LCD_DataWrite(temp);
}
//[F1h]=========================================================================
void Write_GPIO_A_7_0(unsigned char temp)
{
/*
GPI-A[7:0] : General Purpose Input, share with DB[15:8]
GPO-A[7:0] : General Purpose Output, share with DB[15:8]
*/
	LCD_CmdWrite(0xF1);
	LCD_DataWrite(temp);
}
unsigned char Read_GPIO_A_7_0(void)
{
/*
GPI-A[7:0] : General Purpose Input, share with DB[15:8]
GPO-A[7:0] : General Purpose Output, share with DB[15:8]
*/
	unsigned char temp;
	LCD_CmdWrite(0xF1);
	temp=LCD_DataRead();
	return temp;
}
//[F2h]=========================================================================
void Write_GPIO_B_7_4(unsigned char temp)
{
/*
GPI-B[7:0] : General Purpose Input ; share with {XKIN[3:0], XA0, XnWR, XnRD, XnCS}
GPO-B[7:4] : General Purpose Output ; share with XKOUT[3:0] ;
*/
	LCD_CmdWrite(0xF2);
	LCD_DataWrite(temp);
}
unsigned char Read_GPIO_B_7_0(void)
{
/*
GPI-B[7:0] : General Purpose Input ; share with {XKIN[3:0], XA0, XnWR, XnRD, XnCS}
GPO-B[7:4] : General Purpose Output ; share with XKOUT[3:0] ;
*/
	unsigned char temp;
	LCD_CmdWrite(0xF2);
	temp=LCD_DataRead();
	return temp;
}

//[F3h]=========================================================================
void Set_GPIO_C_In_Out(unsigned char temp)
{
/*
GPIO-C_dir[7:0] : General Purpose I/O direction control.
0: Output
1: Input
*/
	LCD_CmdWrite(0xF3);
	LCD_DataWrite(temp);
}
//[F4h]=========================================================================
void Write_GPIO_C_7_0(unsigned char temp)
{
/*
GPIO-C[7:0] : General Purpose Input / Output
share with {XPWM0, XI2CSDA, XI2CSCL, XnSFCS1, XnSFCS0,XMISO, XMOSI, XSCLK}
*/
	LCD_CmdWrite(0xF4);
	LCD_DataWrite(temp);
}
unsigned char Read_GPIO_C_7_0(void)
{
/*
GPIO-C[7:0] : General Purpose Input / Output
share with {XPWM0, XI2CSDA, XI2CSCL, XnSFCS1, XnSFCS0,XMISO, XMOSI, XSCLK}
*/
	unsigned char temp;
	LCD_CmdWrite(0xF4);
	temp=LCD_DataRead();
	return temp;
}
//[F5h]=========================================================================
void Set_GPIO_D_In_Out(unsigned char temp)
{
/*
GPIO-D_dir[7:0] : General Purpose I/O direction control.
0: Output
1: Input
*/
	LCD_CmdWrite(0xF5);
	LCD_DataWrite(temp);
}
//[F6h]=========================================================================
void Write_GPIO_D_7_0(unsigned char temp)
{
/*
GPIO-D[7:0] : General Purpose Input/Output
*/
	LCD_CmdWrite(0xF6);
	LCD_DataWrite(temp);
}
unsigned char Read_GPIO_D_7_0(void)
{
/*
GPIO-D[7:0] : General Purpose Input/Output
*/
	unsigned char temp;
	LCD_CmdWrite(0xF6);
	temp=LCD_DataRead();
	return temp;
}
//[F7h]=========================================================================
void Set_GPIO_E_In_Out(unsigned char temp)
{
/*
GPIO-E_dir[7:0] : General Purpose I/O direction control.
0: Output
1: Input
*/
	LCD_CmdWrite(0xF7);
	LCD_DataWrite(temp);
}
//[F8h]=========================================================================
void Write_GPIO_E_7_0(unsigned char temp)
{
/*
GPIO-E[7:0] : General Purpose Input/Output.
share with {PDAT[23:19], PDAT[15:13]}
*/
	LCD_CmdWrite(0xF8);
	LCD_DataWrite(temp);
}
unsigned char Read_GPIO_E_7_0(void)
{
/*
GPIO-E[7:0] : General Purpose Input/Output.
share with {PDAT[23:19], PDAT[15:13]}
*/
	unsigned char temp;
	LCD_CmdWrite(0xF8);
	temp=LCD_DataRead();
	return temp;
}
//[F9h]=========================================================================
void Set_GPIO_F_In_Out(unsigned char temp)
{
/*
GPIO-F_dir[7:0] : General Purpose I/O direction control.
0: Output
1: Input
*/
	LCD_CmdWrite(0xF9);
	LCD_DataWrite(temp);
}
//[FAh]=========================================================================
void Write_GPIO_F_7_0(unsigned char temp)
{
/*
GPIO-F[7:0] : General Purpose Input/Output.
share with {XPDAT[12:10], XPDAT[7:3]}
*/
	LCD_CmdWrite(0xFA);
	LCD_DataWrite(temp);
}
unsigned char Read_GPIO_F_7_0(void)
{
/*
GPIO-F[7:0] : General Purpose Input/Output.
share with {XPDAT[12:10], XPDAT[7:3]}
*/
	unsigned char temp;
	LCD_CmdWrite(0xFA);
	temp=LCD_DataRead();
	return temp;
}

//[FBh]=========================================================================


void Long_Key_enable(void)
{
 /*
Key-Scan Control Register 1
[bit6]		LongKey Enable Bit
1 : Enable. Long key period is set by KSCR2 bit4-2.
0 : Disable.
*/
	unsigned char temp;
	LCD_CmdWrite(0xFB);
	temp=LCD_DataRead();
	temp |= cSetb6;
	LCD_DataWrite(temp);
}


void Key_Scan_Freg(unsigned char setx)
{
/*KF2-0: Key-Scan Frequency */ 
  unsigned char temp;
  LCD_CmdWrite(0xFB);
  temp = LCD_DataRead();
  temp &= 0xf0;
  temp|= (setx&0x07);
  LCD_DataWrite(temp);  
}


//[FCh]=========================================================================

void Key_Scan_Wakeup_Function_Enable(void)
{
/*
Key-Scan Controller Register 2
[bit7]	
Key-Scan Wakeup Function Enable Bit
0: Key-Scan Wakeup function is disabled.
1: Key-Scan Wakeup function is enabled.
*/
	unsigned char temp;
	LCD_CmdWrite(0xFC);
	temp=LCD_DataRead();
	temp |= cSetb7;
	LCD_DataWrite(temp);
}


void Long_Key_Timing_Adjustment(unsigned char setx)
{
 /*Long Key Timing Adjustment*/ 
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
   temp = LCD_DataRead();   //read key touch number
   temp = temp & 0x03;	 //
   return temp;
}

//[FDh][FEh][FFh]=========================================================================
unsigned char Read_Key_Strobe_Data_0(void)
{
/*
Key Strobe Data 0
The corresponding key code 0 that is pressed.
*/
	unsigned char temp;
	LCD_CmdWrite(0xFD);
	temp=LCD_DataRead();
	return temp;
}
unsigned char Read_Key_Strobe_Data_1(void)
{
/*
Key Strobe Data 1
The corresponding key code 1 that is pressed.
*/
	unsigned char temp;
	LCD_CmdWrite(0xFE);
	temp=LCD_DataRead();
	return temp;
}
unsigned char Read_Key_Strobe_Data_2(void)
{
/*
Key Strobe Data 2
The corresponding key code 2 that is pressed.
*/
	unsigned char temp;
	LCD_CmdWrite(0xFF);
	temp=LCD_DataRead();
	return temp;
}



void Show_String(char *str)
{   
  	Text_Mode();	   //文本模式
  	LCD_CmdWrite(0x04);
  	while(*str != '\0')
  	{
   		LCD_DataWrite(*str);
   		Check_Mem_WR_FIFO_not_Full();
  		++str;   
  	}
   	Check_2D_Busy();

   	Graphic_Mode(); //back to graphic mode;图形模式
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

//------------------------------------- 线段 -----------------------------------------
void LT768_DrawLine
(
 unsigned short X1        // X1坐标
,unsigned short Y1        // Y1坐标
,unsigned short X2        // X2坐标
,unsigned short Y2        // Y2坐标
,unsigned long  LineColor // 线段颜色
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
 unsigned short X1        // X1坐标
,unsigned short Y1        // Y1坐标
,unsigned short X2        // X2坐标
,unsigned short Y2        // Y2坐标
,unsigned long  LineColor // 线段颜色
,unsigned short Width     // 线段宽度
)
{
	unsigned short  i = 0;
	while(Width--)
	{
		LT768_DrawLine(X1,Y1+i,X2,Y2+i,LineColor);
		i++;
	}
}


//------------------------------------- 圆 -----------------------------------------
void LT768_DrawCircle
(
 unsigned short XCenter           // 圆心X位置
,unsigned short YCenter           // 圆心Y位置
,unsigned short R                 // 半径
,unsigned long CircleColor        // 画线颜色
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
 unsigned short XCenter           // 圆心X位置
,unsigned short YCenter           // 圆心Y位置
,unsigned short R                 // 半径
,unsigned long ForegroundColor    // 背景颜色
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
 unsigned short XCenter          // 圆心X位置
,unsigned short YCenter          // 圆心Y位置
,unsigned short R                // 半径
,unsigned long CircleColor       // 画线颜色
,unsigned long ForegroundColor   // 背景颜色
,unsigned short Width            // 线宽
)
{
	LT768_DrawCircle_Fill(XCenter,YCenter,R+Width,CircleColor);
	LT768_DrawCircle_Fill(XCenter,YCenter,R,ForegroundColor);
}


//------------------------------------- 椭圆 -----------------------------------------
void LT768_DrawEllipse
(
 unsigned short XCenter          // 椭圆心X位置
,unsigned short YCenter          // 椭圆心Y位置
,unsigned short X_R              // 宽半径
,unsigned short Y_R              // 长半径
,unsigned long EllipseColor      // 画线颜色
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
 unsigned short XCenter           // 椭圆心X位置
,unsigned short YCenter           // 椭圆心Y位置
,unsigned short X_R               // 宽半径
,unsigned short Y_R               // 长半径
,unsigned long ForegroundColor    // 背景颜色
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
 unsigned short XCenter           // 椭圆心X位置
,unsigned short YCenter           // 椭圆心Y位置
,unsigned short X_R               // 宽半径
,unsigned short Y_R               // 长半径
,unsigned long EllipseColor       // 画线颜色
,unsigned long ForegroundColor    // 背景颜色
,unsigned short Width             // 线宽
)
{
	LT768_DrawEllipse_Fill(XCenter,YCenter,X_R+Width,Y_R+Width,EllipseColor);
	LT768_DrawEllipse_Fill(XCenter,YCenter,X_R,Y_R,ForegroundColor);
}



//------------------------------------- 矩形 -----------------------------------------
void LT768_DrawSquare
(
 unsigned short X1                // X1位置
,unsigned short Y1                // Y1位置
,unsigned short X2                // X2位置
,unsigned short Y2                // Y2位置
,unsigned long SquareColor        // 画线颜色
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
 unsigned short X1                // X1位置
,unsigned short Y1                // Y1位置
,unsigned short X2                // X2位置
,unsigned short Y2                // Y2位置
,unsigned long ForegroundColor    // 背景颜色
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
 unsigned short X1                // X1位置
,unsigned short Y1                // Y1位置
,unsigned short X2                // X2位置
,unsigned short Y2                // Y2位置
,unsigned long SquareColor        // 画线颜色
,unsigned long ForegroundColor    // 背景颜色
,unsigned short Width             // 线宽
)
{
	LT768_DrawSquare_Fill(X1-Width,Y1-Width,X2+Width,Y2+Width,SquareColor);
	LT768_DrawSquare_Fill(X1,Y1,X2,Y2,ForegroundColor);
}


//------------------------------------- 圆角矩形 -----------------------------------------
void LT768_DrawCircleSquare
(
 unsigned short X1                // X1位置
,unsigned short Y1                // Y1位置
,unsigned short X2                // X2位置
,unsigned short Y2                // Y2位置
,unsigned short X_R               // 宽半径
,unsigned short Y_R               // 长半径
,unsigned long CircleSquareColor  // 画线颜色
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
 unsigned short X1                // X1位置
,unsigned short Y1                // Y1位置
,unsigned short X2                // X2位置
,unsigned short Y2                // Y2位置
,unsigned short X_R               // 宽半径
,unsigned short Y_R               // 长半径
,unsigned long ForegroundColor  // 画线颜色
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
 unsigned short X1                // X1位置
,unsigned short Y1                // Y1位置
,unsigned short X2                // X2位置
,unsigned short Y2                // Y2位置
,unsigned short X_R               // 宽半径
,unsigned short Y_R               // 长半径
,unsigned long CircleSquareColor  // 画线颜色
,unsigned long ForegroundColor    // 画线颜色
,unsigned short Width             // 宽度
)
{
	LT768_DrawCircleSquare_Fill(X1-Width,Y1-Width,X2+Width,Y2+Width,X_R,Y_R,CircleSquareColor);
	LT768_DrawCircleSquare_Fill(X1,Y1,X2,Y2,X_R,Y_R,ForegroundColor);
}


//------------------------------------- 三角形 -----------------------------------------
void LT768_DrawTriangle
(
 unsigned short X1              // X1位置
,unsigned short Y1              // Y1位置
,unsigned short X2              // X2位置
,unsigned short Y2              // Y2位置
,unsigned short X3              // X3位置
,unsigned short Y3              // Y3位置
,unsigned long TriangleColor    // 画线颜色
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
 unsigned short X1              // X1位置
,unsigned short Y1              // Y1位置
,unsigned short X2              // X2位置
,unsigned short Y2              // Y2位置
,unsigned short X3              // X3位置
,unsigned short Y3              // Y3位置
,unsigned long ForegroundColor  // 画线颜色
)
{
	Foreground_color_65k(ForegroundColor);
	Triangle_Point1_XY(X1,Y1);
  Triangle_Point2_XY(X2,Y2);
  Triangle_Point3_XY(X3,Y3);
  Start_Triangle_Fill();
  Check_2D_Busy();
}



//------------------------------------- 曲线 -----------------------------------------
void LT768_DrawLeftUpCurve
( 
 unsigned short XCenter           // 曲心X位置
,unsigned short YCenter           // 曲心Y位置
,unsigned short X_R               // 宽半径
,unsigned short Y_R               // 长半径
,unsigned long CurveColor         // 画线颜色
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
 unsigned short XCenter           // 曲心X位置
,unsigned short YCenter           // 曲心Y位置
,unsigned short X_R               // 宽半径
,unsigned short Y_R               // 长半径
,unsigned long CurveColor         // 画线颜色
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
 unsigned short XCenter           // 曲心X位置
,unsigned short YCenter           // 曲心Y位置
,unsigned short X_R               // 宽半径
,unsigned short Y_R               // 长半径
,unsigned long CurveColor         // 画线颜色
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
 unsigned short XCenter           // 曲心X位置
,unsigned short YCenter           // 曲心Y位置
,unsigned short X_R               // 宽半径
,unsigned short Y_R               // 长半径
,unsigned long CurveColor         // 画线颜色
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
 unsigned short XCenter           // 曲心X位置
,unsigned short YCenter           // 曲心Y位置
,unsigned short X_R               // 宽半径
,unsigned short Y_R               // 长半径
,unsigned long CurveColor         // 画线颜色
,unsigned short  Dir              // 方向
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


//------------------------------------- 1/4实心椭圆 -----------------------------------------
void LT768_DrawLeftUpCurve_Fill
(
 unsigned short XCenter           // 曲心X位置
,unsigned short YCenter           // 曲心Y位置
,unsigned short X_R               // 宽半径
,unsigned short Y_R               // 长半径
,unsigned long ForegroundColor    // 背景颜色
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
 unsigned short XCenter           // 曲心X位置
,unsigned short YCenter           // 曲心Y位置
,unsigned short X_R               // 宽半径
,unsigned short Y_R               // 长半径
,unsigned long ForegroundColor    // 背景颜色
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
 unsigned short XCenter           // 曲心X位置
,unsigned short YCenter           // 曲心Y位置
,unsigned short X_R               // 宽半径
,unsigned short Y_R               // 长半径
,unsigned long ForegroundColor    // 背景颜色
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
 unsigned short XCenter           // 曲心X位置
,unsigned short YCenter           // 曲心Y位置
,unsigned short X_R               // 宽半径
,unsigned short Y_R               // 长半径
,unsigned long ForegroundColor    // 背景颜色
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
 unsigned short XCenter           // 曲心X位置
,unsigned short YCenter           // 曲心Y位置
,unsigned short X_R               // 宽半径
,unsigned short Y_R               // 长半径
,unsigned long CurveColor         // 画线颜色
,unsigned short  Dir              // 方向
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



//------------------------------------- 四边形 -----------------------------------------

void LT768_DrawQuadrilateral
(
 unsigned short X1              // X1位置
,unsigned short Y1              // Y1位置
,unsigned short X2              // X2位置
,unsigned short Y2              // Y2位置
,unsigned short X3              // X3位置
,unsigned short Y3              // Y3位置
,unsigned short X4              // X4位置
,unsigned short Y4              // Y4位置
,unsigned long ForegroundColor  // 画线颜色
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
 unsigned short X1              // X1位置
,unsigned short Y1              // Y1位置
,unsigned short X2              // X2位置
,unsigned short Y2              // Y2位置
,unsigned short X3              // X3位置
,unsigned short Y3              // Y3位置
,unsigned short X4              // X4位置
,unsigned short Y4              // Y4位置
,unsigned long ForegroundColor  // 画线颜色
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



//------------------------------------- 五边形 -----------------------------------------

void LT768_DrawPentagon
(
 unsigned short X1              // X1位置
,unsigned short Y1              // Y1位置
,unsigned short X2              // X2位置
,unsigned short Y2              // Y2位置
,unsigned short X3              // X3位置
,unsigned short Y3              // Y3位置
,unsigned short X4              // X4位置
,unsigned short Y4              // Y4位置
,unsigned short X5              // X5位置
,unsigned short Y5              // Y5位置
,unsigned long ForegroundColor  // 画线颜色
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
 unsigned short X1              // X1位置
,unsigned short Y1              // Y1位置
,unsigned short X2              // X2位置
,unsigned short Y2              // Y2位置
,unsigned short X3              // X3位置
,unsigned short Y3              // Y3位置
,unsigned short X4              // X4位置
,unsigned short Y4              // Y4位置
,unsigned short X5              // X5位置
,unsigned short Y5              // Y5位置
,unsigned long ForegroundColor  // 画线颜色
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


//------------------------------------- 圆柱 -----------------------------------------
unsigned char LT768_DrawCylinder
(
 unsigned short XCenter           // 椭圆心X位置
,unsigned short YCenter           // 椭圆心Y位置
,unsigned short X_R               // 宽半径
,unsigned short Y_R               // 长半径
,unsigned short H                 // 高度
,unsigned long CylinderColor      // 画线颜色
,unsigned long ForegroundColor    // 背景颜色
)
{
	if(YCenter < H)	return 1;
	
	//底面椭圆
	LT768_DrawEllipse_Fill(XCenter,YCenter,X_R,Y_R,ForegroundColor);
	LT768_DrawEllipse(XCenter,YCenter,X_R,Y_R,CylinderColor);
	
	//中间矩形
	LT768_DrawSquare_Fill(XCenter-X_R,YCenter-H,XCenter+X_R,YCenter,ForegroundColor);
	
	//顶面椭圆
	LT768_DrawEllipse_Fill(XCenter,YCenter-H,X_R,Y_R,ForegroundColor);
	LT768_DrawEllipse(XCenter,YCenter-H,X_R,Y_R,CylinderColor);
	
	LT768_DrawLine(XCenter-X_R,YCenter,XCenter-X_R,YCenter-H,CylinderColor);
	LT768_DrawLine(XCenter+X_R,YCenter,XCenter+X_R,YCenter-H,CylinderColor);
	
	return 0;
}


//------------------------------------- 四棱柱 -----------------------------------------
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
,unsigned long QuadrangularColor   // 画线颜色
,unsigned long ForegroundColor     // 背景颜色
)
{
	LT768_DrawSquare_Fill(X1,Y1,X5,Y5,ForegroundColor);
	LT768_DrawSquare(X1,Y1,X5,Y5,QuadrangularColor);
	
	LT768_DrawQuadrilateral_Fill(X1,Y1,X2,Y2,X3,Y3,X4,Y4,ForegroundColor);
	LT768_DrawQuadrilateral(X1,Y1,X2,Y2,X3,Y3,X4,Y4,QuadrangularColor);
	
	LT768_DrawQuadrilateral_Fill(X3,Y3,X4,Y4,X5,Y5,X6,Y6,ForegroundColor);
	LT768_DrawQuadrilateral(X3,Y3,X4,Y4,X5,Y5,X6,Y6,QuadrangularColor);
}




//--------------------------------------------------------------------------------------------------------------------------------------------


void LT768_Color_Bar_ON(void)
{
	Color_Bar_ON();
}

void LT768_Color_Bar_OFF(void)
{
	Color_Bar_OFF();
}






//--------------------------------------------------------------------------------------------------------------------------------------------



void LT768_DMA_24bit_Linear
(
 unsigned char SCS              // 选择外挂的SPI   : SCS：0       SCS：1
,unsigned char Clk              // SPI时钟分频参数 : SPI Clock = System Clock /{(Clk+1)*2}
,unsigned long flash_addr       // 要从flash读取数据的起始地址   
,unsigned long memory_addr      // 数据要传输到SDRAM的起始地址
,unsigned long data_num         // 传输的数据量
)
{
	
	Enable_SFlash_SPI();									             // 使能SPI功能
  if(SCS == 0)		Select_SFI_0();										 // 选择外挂的SPI0
  if(SCS == 1)		Select_SFI_1();										 // 选择外挂的SPI1
	
	Memory_Linear_Mode();
	Select_SFI_DMA_Mode();								             // 设置SPI的DMA模式
	
	SPI_Clock_Period(Clk);                             // SPI速率 
	SFI_DMA_Destination_Start_Address(memory_addr);  	 // 指定的内存的开始地址
	SFI_DMA_Transfer_Number(data_num);                 // DMA传输的数量
	SFI_DMA_Source_Start_Address(flash_addr);          // flash地址
	Check_Busy_SFI_DMA(); 
	Start_SFI_DMA();
	Check_Busy_SFI_DMA();
	Memory_XY_Mode();
}



void LT768_DMA_32bit_Linear
(
 unsigned char SCS              // 选择外挂的SPI   : SCS：0       SCS：1
,unsigned char Clk              // SPI时钟分频参数 : SPI Clock = System Clock /{(Clk+1)*2}
,unsigned long flash_addr       // 要从flash读取数据的起始地址   
,unsigned long memory_addr      // 数据要传输到SDRAM的起始地址
,unsigned long data_num         // 传输的数据量
)
{
	Enable_SFlash_SPI();									             // 使能SPI功能
  if(SCS == 0)		Select_SFI_0();								     // 选择外挂的SPI0
  if(SCS == 1)		Select_SFI_1();										 // 选择外挂的SPI1
	
	Memory_Linear_Mode();
	Select_SFI_DMA_Mode();								            // 设置SPI的DMA模式
	Select_SFI_32bit_Address();
	
	SPI_Clock_Period(Clk);                             // SPI速率 
	SFI_DMA_Destination_Start_Address(memory_addr);  	 // 指定的内存的开始地址
	SFI_DMA_Transfer_Number(data_num);                 // DMA传输的数量
	SFI_DMA_Source_Start_Address(flash_addr);          // flash地址
	Check_Busy_SFI_DMA(); 
	Start_SFI_DMA();
	Check_Busy_SFI_DMA();
	Memory_XY_Mode();
}



void LT768_DMA_24bit_Block
(
 unsigned char SCS         // 选择外挂的SPI   : SCS：0       SCS：1
,unsigned char Clk         // SPI时钟分频参数 : SPI Clock = System Clock /{(Clk+1)*2}
,unsigned short X1         // 传输到内存X1的位置
,unsigned short Y1         // 传输到内存Y1的位置
,unsigned short X_W        // DMA传输数据的宽度
,unsigned short Y_H        // DMA传输数据的高度
,unsigned short P_W        // 图片的宽度
,unsigned long Addr        // Flash的地址
)
{  

  Enable_SFlash_SPI();									          // 使能SPI功能
  if(SCS == 0)	Select_SFI_0();										// 选择外挂的SPI0
  if(SCS == 1)	Select_SFI_1();									  // 选择外挂的SPI1
 
										   
  Select_SFI_DMA_Mode();								          // 设置SPI的DMA模式
  SPI_Clock_Period(Clk);                          // 设置SPI的分频系数

  Goto_Pixel_XY(X1,Y1);									          // 在图形模式中设置内存的位置
  SFI_DMA_Destination_Upper_Left_Corner(X1,Y1);		// DMA传输的目的地（内存的位置）
  SFI_DMA_Transfer_Width_Height(X_W,Y_H);				  // 设置块数据的宽度和高度
  SFI_DMA_Source_Width(P_W);							        // 设置源数据的宽度
  SFI_DMA_Source_Start_Address(Addr); 					  // 设置源数据在Flash的地址

  Start_SFI_DMA();									              // 开始DMA传输
  Check_Busy_SFI_DMA();								            // 检测DMA是否传输完成
}



void LT768_DMA_32bit_Block
(
 unsigned char SCS         // 选择外挂的SPI   : SCS：0       SCS：1
,unsigned char Clk         // SPI时钟分频参数 : SPI Clock = System Clock /{(Clk+1)*2}
,unsigned short X1         // 内存X1的位置
,unsigned short Y1         // 内存Y1的位置
,unsigned short X_W        // DMA传输数据的宽度
,unsigned short Y_H        // DMA传输数据的高度
,unsigned short P_W        // 图片的宽度
,unsigned long Addr        // Flash的地址
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






//--------------------------------------------------------------------------------------------------------------------------------------------
/* 选择内部集成字库初始化 */
void LT768_Select_Internal_Font_Init
(
 unsigned char Size         // 设置字体大小  16：16*16     24:24*24    32:32*32
,unsigned char XxN          // 字体的宽度放大倍数：1~4
,unsigned char YxN          // 字体的高度放大倍数：1~4
,unsigned char ChromaKey    // 0：字体背景色透明    1：可以设置字体的背景色
,unsigned char Alignment    // 0：不字体不对齐      1：字体对齐
)
{
	if(Size==16)	Font_Select_8x16_16x16();
	if(Size==24)	Font_Select_12x24_24x24();
	if(Size==32)	Font_Select_16x32_32x32();

	//(*)
	if(XxN==1)	Font_Width_X1();
	if(XxN==2)	Font_Width_X2();
	if(XxN==3)	Font_Width_X3();
	if(XxN==4)	Font_Width_X4();

	//(*)	
	if(YxN==1)	Font_Height_X1();
	if(YxN==2)	Font_Height_X2();
	if(YxN==3)	Font_Height_X3();
	if(YxN==4)	Font_Height_X4();

	//(*)
	if(ChromaKey==0)	Font_Background_select_Color();	
	if(ChromaKey==1)	Font_Background_select_Transparency();	

	//(*)
	if(Alignment==0)	Disable_Font_Alignment();
	if(Alignment==1)	Enable_Font_Alignment();
}


/* 显示内部集成字体 */
void LT768_Print_Internal_Font_String
(
 unsigned short x               // 字体开始显示的x位置
,unsigned short y               // 字体开始显示的y位置
,unsigned long FontColor        // 字体的颜色
,unsigned long BackGroundColor  // 字体的背景色（注意：当字体背景初始化成透明时，设置该值无效）
,char *c                        // 数据缓冲的首地址
)
{
  Text_Mode();
	CGROM_Select_Internal_CGROM();
  Foreground_color_65k(FontColor);
	Background_color_65k(BackGroundColor);
	Goto_Text_XY(x,y);
	Show_String(c);
}


/* 选择外部集成字库初始化 */
void LT768_Select_Outside_Font_Init
(
 unsigned char SCS           // 选择外挂的SPI   : SCS：0       SCS：1
,unsigned char Clk           // SPI时钟分频参数 : SPI Clock = System Clock /{(Clk+1)*2}
,unsigned long FlashAddr     // 源地址(Flash)
,unsigned long MemoryAddr    // 目的地址(SDRAM)
,unsigned long Num           // 字库的数据量大小
,unsigned char Size          // 设置字体大小  16：16*16     24:24*24    32:32*32
,unsigned char XxN           // 字体的宽度放大倍数：1~4
,unsigned char YxN           // 字体的高度放大倍数：1~4
,unsigned char ChromaKey     // 0：字体背景色透明    1：可以设置字体的背景色
,unsigned char Alignment     // 0：不字体不对齐      1：字体对齐
)
{
	if(Size==16)	Font_Select_8x16_16x16();
	if(Size==24)	Font_Select_12x24_24x24();
	if(Size==32)	Font_Select_16x32_32x32();

	//(*)
	if(XxN==1)	Font_Width_X1();
	if(XxN==2)	Font_Width_X2();
	if(XxN==3)	Font_Width_X3();
	if(XxN==4)	Font_Width_X4();

	//(*)	
	if(YxN==1)	Font_Height_X1();
	if(YxN==2)	Font_Height_X2();
	if(YxN==3)	Font_Height_X3();
	if(YxN==4)	Font_Height_X4();

	//(*)
	if(ChromaKey==0)	Font_Background_select_Color();	
	if(ChromaKey==1)	Font_Background_select_Transparency();	

	//(*)
	if(Alignment==0)	Disable_Font_Alignment();
	if(Alignment==1)	Enable_Font_Alignment();	
	
	LT768_DMA_24bit_Linear(SCS,Clk,FlashAddr,MemoryAddr,Num);
	CGRAM_Start_address(MemoryAddr);        
}



/* 显示外部及内部集成字体 */
void LT768_Print_Outside_Font_String
(
 unsigned short x               // 字体开始显示的x位置
,unsigned short y               // 字体开始显示的y位置
,unsigned long FontColor        // 字体的颜色
,unsigned long BackGroundColor  // 字体的背景色（注意：当字体背景初始化成透明时，设置该值无效）
,unsigned char *c               // 数据缓冲的首地址
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
			CGROM_Select_Internal_CGROM();   // 内部CGROM为字符来源
			LCD_CmdWrite(0x04);
			LCD_DataWrite(c[i]);
			Check_Mem_WR_FIFO_not_Full();  
			i += 1;
		}
		else
		{
			Font_Select_UserDefine_Mode();   // 自定义字库
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

  Graphic_Mode(); //back to graphic mode;图形模式
}




void LT768_Text_cursor_Init
(
 unsigned char On_Off_Blinking         // 0：禁止光标闪烁   1：使能光标闪烁
,unsigned short Blinking_Time          // 设置文字光标闪烁时间
,unsigned short X_W                    // 文字光标水平大小
,unsigned short Y_W                    // 文字光标垂直大小
)
{
	if(On_Off_Blinking == 0)	Disable_Text_Cursor_Blinking();
	if(On_Off_Blinking == 1)	Enable_Text_Cursor_Blinking();

  Blinking_Time_Frames(Blinking_Time); 
	
  //[3E][3Fh]
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
 unsigned char Cursor_N                  // 选择光标   1:光标1   2:光标2   3:光标3  4:光标4
,unsigned char Color1                    // 颜色1
,unsigned char Color2                    // 颜色2
,unsigned short X_Pos                    // 显示坐标X
,unsigned short Y_Pos                    // 显示坐标Y
,unsigned char *Cursor_Buf               // 光标数据的缓冲首地址
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
	
	Memory_Select_SDRAM();//写完后切回SDRAM
	Set_Graphic_Cursor_Color_1(Color1);
  Set_Graphic_Cursor_Color_2(Color2);
  Graphic_Cursor_XY(X_Pos,Y_Pos);
	
	Enable_Graphic_Cursor();
}


void LT768_Set_Graphic_cursor_Pos
(
 unsigned char Cursor_N                  // 选择光标   1:光标1   2:光标2   3:光标3  4:光标4
,unsigned short X_Pos                    // 显示坐标X
,unsigned short Y_Pos                    // 显示坐标Y
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


//-----------------------------------------------------------------------------------------------------------------------------

void LT768_PIP_Init
(
 unsigned char On_Off         // 0 : 禁止 PIP    1 : 使能 PIP    2 : 保持原来的状态
,unsigned char Select_PIP     // 1 : 使用 PIP1   2 : 使用 PIP2
,unsigned long PAddr          // PIP的开始地址
,unsigned short XP            // PIP窗口的X坐标,必须被4整除
,unsigned short YP            // PIP窗口的Y坐标,必须被4整除
,unsigned long ImageWidth     // 底图的宽度
,unsigned short X_Dis         // 显示窗口的X坐标
,unsigned short Y_Dis         // 显示窗口的Y坐标
,unsigned short X_W           // 显示窗口的宽度，必须被4整除
,unsigned short Y_H           // 显示窗口的长度，必须被4整除
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
 unsigned char On_Off         // 0 : 禁止 PIP, 1 : 使能 PIP, 2 : 保持原来的状态
,unsigned char Select_PIP     // 1 : 使用 PIP1 , 2 : 使用 PIP2
,unsigned short X_Dis         // 显示窗口的X坐标
,unsigned short Y_Dis         // 显示窗口的Y坐标
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




//-----------------------------------------------------------------------------------------------------------------------------



void BTE_Solid_Fill
(
 unsigned long Des_Addr           // 填充的目的地址 
,unsigned short Des_W             // 目的地址图片宽度
,unsigned short XDes              // x坐标 
,unsigned short YDes              // y坐标 
,unsigned short color             // 填充的颜色 
,unsigned short X_W               // 填充的长度 
,unsigned short Y_H               // 填充的宽度 
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

/*  结合光栅操作的BTE内存复制 */
void LT768_BTE_Memory_Copy
(
 unsigned long S0_Addr     // SO图像的内存起始地址
,unsigned short S0_W       // S0图像的宽度
,unsigned short XS0        // S0图像的左上方X坐标
,unsigned short YS0        // S0图像的左上方Y坐标
,unsigned long S1_Addr     // S1图像的内存起始地址
,unsigned short S1_W       // S1图像的宽度
,unsigned short XS1        // S1图像的左上方X坐标
,unsigned short YS1        // S1图像的左上方Y坐标
,unsigned long Des_Addr    // 目的图像的内存起始地址
,unsigned short Des_W      // 目的图像的宽度
,unsigned short XDes       // 目的图像的左上方X坐标
,unsigned short YDes       // 目的图像的左上方Y坐标
,unsigned int ROP_Code     // 光栅操作模式
/*ROP_Code :
   0000b		0(Blackness)
   0001b		~S0!E~S1 or ~(S0+S1)
   0010b		~S0!ES1
   0011b		~S0
   0100b		S0!E~S1
   0101b		~S1
   0110b		S0^S1
   0111b		~S0 + ~S1 or ~(S0 + S1)
   1000b		S0!ES1
   1001b		~(S0^S1)
   1010b		S1
   1011b		~S0+S1
   1100b		S0
   1101b		S0+~S1
   1110b		S0+S1
   1111b		1(whiteness)*/
,unsigned short X_W       // 活动窗口的宽度
,unsigned short Y_H       // 活动窗口的长度
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
  BTE_Operation_Code(0x02); //BTE Operation: Memory copy (move) with ROP.
  BTE_Window_Size(X_W,Y_H); 
  BTE_Enable();
  Check_BTE_Busy();
}


/*  结合 Chroma Key 的内存复制（不含 ROP） */
void LT768_BTE_Memory_Copy_Chroma_key
(
 unsigned long S0_Addr             // SO图像的内存起始地址
,unsigned short S0_W               // S0图像的宽度
,unsigned short XS0                // S0图像的左上方X坐标
,unsigned short YS0                // S0图像的左上方Y坐标
,unsigned long Des_Addr            // 目的图像的内存起始地址
,unsigned short Des_W              // 目的图像的宽度
,unsigned short XDes               // 目的图像的左上方X坐标
,unsigned short YDes               // 目的图像的左上方X坐标
,unsigned long Background_color    // 透明色
,unsigned short X_W                // 活动窗口的宽度
,unsigned short Y_H                // 活动窗口的长度
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
   
  BTE_Operation_Code(0x05);	//BTE Operation: Memory copy (move) with chroma keying (w/o ROP)
  BTE_Window_Size(X_W,Y_H); 
  BTE_Enable();
  Check_BTE_Busy();
}


void LT768_BTE_Pattern_Fill
(
 unsigned char P_8x8_or_16x16      // 0 : use 8x8 Icon , 1 : use 16x16 Icon.
,unsigned long S0_Addr             // SO图像的内存起始地址
,unsigned short S0_W               // S0图像的宽度
,unsigned short XS0                // S0图像的左上方X坐标
,unsigned short YS0                // S0图像的左上方Y坐标
,unsigned long Des_Addr            // 目的图像的内存起始地址
,unsigned short Des_W              // 目的图像的宽度
, unsigned short XDes              // 目的图像的左上方X坐标
,unsigned short YDes               // 目的图像的左上方X坐标
,unsigned int ROP_Code             // 光栅操作模式
/*ROP_Code :
   0000b		0(Blackness)
   0001b		~S0!E~S1 or ~(S0+S1)
   0010b		~S0!ES1
   0011b		~S0
   0100b		S0!E~S1
   0101b		~S1
   0110b		S0^S1
   0111b		~S0 + ~S1 or ~(S0 + S1)
   1000b		S0!ES1
   1001b		~(S0^S1)
   1010b		S1
   1011b		~S0+S1
   1100b		S0
   1101b		S0+~S1
   1110b		S0+S1
   1111b		1(whiteness)*/
,unsigned short X_W                // 活动窗口的宽度
,unsigned short Y_H                // 活动窗口的长度
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
  BTE_Operation_Code(0x06); //BTE Operation: Pattern Fill with ROP.
  BTE_Window_Size(X_W,Y_H); 
  BTE_Enable();
  Check_BTE_Busy();
}



void LT768_BTE_Pattern_Fill_With_Chroma_key
(
 unsigned char P_8x8_or_16x16      // 0 : use 8x8 Icon , 1 : use 16x16 Icon.
,unsigned long S0_Addr             // SO图像的内存起始地址
,unsigned short S0_W               // S0图像的宽度
,unsigned short XS0                // S0图像的左上方X坐标
,unsigned short YS0                // S0图像的左上方Y坐标
,unsigned long Des_Addr            // 目的图像的内存起始地址
,unsigned short Des_W              // 目的图像的宽度
,unsigned short XDes               // 目的图像的左上方X坐标
,unsigned short YDes               // 目的图像的左上方Y坐标
,unsigned int ROP_Code             // 光栅操作模式
/*ROP_Code :
   0000b		0(Blackness)
   0001b		~S0!E~S1 or ~(S0+S1)
   0010b		~S0!ES1
   0011b		~S0
   0100b		S0!E~S1
   0101b		~S1
   0110b		S0^S1
   0111b		~S0 + ~S1 or ~(S0 + S1)
   1000b		S0!ES1
   1001b		~(S0^S1)
   1010b		S1
   1011b		~S0+S1
   1100b		S0
   1101b		S0+~S1
   1110b		S0+S1
   1111b		1(whiteness)*/
,unsigned long Background_color   // 透明色
,unsigned short X_W               // 活动窗口的宽度
,unsigned short Y_H               // 活动窗口的长度
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
  BTE_Operation_Code(0x07); //BTE Operation: Pattern Fill with Chroma key.
  BTE_Window_Size(X_W,Y_H); 
  BTE_Enable();
  Check_BTE_Busy();
}

void LT768_BTE_MCU_Write_MCU_16bit
(
 unsigned long S1_Addr              // S1图像的内存起始地址
,unsigned short S1_W                // S1图像的宽度
,unsigned short XS1                 // S1图像的左上方X坐标
,unsigned short YS1                 // S1图像的左上方Y坐标
,unsigned long Des_Addr             // 目的图像的内存起始地址
,unsigned short Des_W               // 目的图像的宽度
,unsigned short XDes                // 目的图像的左上方X坐标
,unsigned short YDes                // 目的图像的左上方Y坐标
,unsigned int ROP_Code              // 光栅操作模式 
/*ROP_Code :
   0000b		0(Blackness)
   0001b		~S0!E~S1 or ~(S0+S1)
   0010b		~S0!ES1
   0011b		~S0
   0100b		S0!E~S1
   0101b		~S1
   0110b		S0^S1
   0111b		~S0 + ~S1 or ~(S0 + S1)
   1000b		S0!ES1
   1001b		~(S0^S1)
   1010b		S1
   1011b		~S0+S1
   1100b		S0
   1101b		S0+~S1
   1110b		S0+S1
   1111b		1(whiteness)*/
,unsigned short X_W                 // 活动窗口的宽度
,unsigned short Y_H                 // 活动窗口的长度
,const unsigned short *data         // S0的数据收地址
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
  BTE_Operation_Code(0x00);		//BTE Operation: MPU Write with ROP.
  BTE_Enable();
	
	BTE_S0_Color_16bpp();
	LCD_CmdWrite(0x04);				 		//Memory Data Read/Write Port
	
	//MCU_16bit_ColorDepth_16bpp
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
 unsigned long Des_Addr                 // 目的图像的内存起始地址
,unsigned short Des_W                   // 目的图像的宽度
,unsigned short XDes                    // 目的图像的左上方X坐标
,unsigned short YDes                    // 目的图像的左上方Y坐标
,unsigned long Background_color         // 透明色
,unsigned short X_W                     // 活动窗口的宽度
,unsigned short Y_H                     // 活动窗口的长度
,const unsigned short *data             // S0的数据收地址
)
{
	unsigned int i,j;
	
	Background_color_65k(Background_color);
	
	BTE_Destination_Color_16bpp();
	BTE_Destination_Memory_Start_Address(Des_Addr);
  BTE_Destination_Image_Width(Des_W);
  BTE_Destination_Window_Start_XY(XDes,YDes);
  
  BTE_Window_Size(X_W,Y_H);
  BTE_Operation_Code(0x04);		//BTE Operation: MPU Write with chroma keying (w/o ROP)
  BTE_Enable();
	
	BTE_S0_Color_16bpp();
  LCD_CmdWrite(0x04);			//Memory Data Read/Write Port
	
	//MCU_16bit_ColorDepth_16bpp
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



/* 结合扩展色彩的 MPU 寫入 */
void LT768_BTE_MCU_Write_ColorExpansion_MCU_16bit
(
 unsigned long Des_Addr               //start address of Destination
,unsigned short Des_W                 //image width of Destination (recommend = canvas image width)
,unsigned short XDes                  //coordinate X of Destination
,unsigned short YDes                  //coordinate Y of Destination
,unsigned short X_W                   //Width of BTE Window
,unsigned short Y_H                   //Length of BTE Window
,unsigned long Foreground_color 
/*Foreground_color : The source (1bit map picture) map data 1 translate to Foreground color by color expansion*/
,unsigned long Background_color 
/*Background_color : The source (1bit map picture) map data 0 translate to Background color by color expansion*/
,const unsigned short *data           //16-bit data
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
  BTE_Operation_Code(0x8);		//BTE Operation: MPU Write with Color Expansion (w/o ROP)
  BTE_Enable();
	
	LCD_CmdWrite(0x04);				 		//Memory Data Read/Write Port  
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



/* 结合扩展色彩与 Chroma key 的 MPU 寫入 */
void LT768_BTE_MCU_Write_ColorExpansion_Chroma_key_MCU_16bit
(
 unsigned long Des_Addr //start address of Destination
,unsigned short Des_W //image width of Destination (recommend = canvas image width)
,unsigned short XDes //coordinate X of Destination
,unsigned short YDes //coordinate Y of Destination
,unsigned short X_W //Width of BTE Window
,unsigned short Y_H //Length of BTE Window
,unsigned long Foreground_color
/*Foreground_color : The source (1bit map picture) map data 1 translate to Foreground color by color expansion*/
,const unsigned short *data //16-bit data
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
	BTE_Operation_Code(0x9);		//BTE Operation: MPU Write with Color Expansion and chroma keying (w/o ROP)
  BTE_Enable();
	
	LCD_CmdWrite(0x04);				 		//Memory Data Read/Write Port  
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

/*
S0_Addr : Source 0 Start address
S0_W : Source 0 image width(recommend = canvas image width) 
XS0 : Source 0 coordinate of X
YS0 : Source 0 coordinate of Y
S1_Addr : Source 1 Start address
S1_W : Source 1 image width(recommend = canvas image width) 
XS1 : Source 1 coordinate of X
YS1 : Source 1 coordinate of Y
Des_Addr : Destination start address
Des_W :	 Destination image width(recommend = canvas image width) 
XDes : Destination coordinate of X
YDes : Destination coordinate of Y
X_W : BTE Window Size of X
Y_H : BTE Window Size of Y
alpha : Alpha Blending effect 0 ~ 32, Destination data = (Source 0 * (1- alpha)) + (Source 1 * alpha)
*/
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
  BTE_Operation_Code(0x0A);		//BTE Operation: Memory write with opacity (w/o ROP)
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
#define Blue3          0x2108
#define name_to_str(name_31415926)  (#name_31415926)

void Show(void)
{
	uint16_t i,j;
	uint16_t yn;	
  
	Select_Main_Window_16bpp();
	
	Canvas_Image_Start_address(layer2_start_addr);
	Canvas_image_width(LCD_XSIZE_TFT);
  Active_Window_XY(0,0);
	Active_Window_WH(LCD_XSIZE_TFT,LCD_YSIZE_TFT);			
	LT768_DrawSquare_Fill(0,0,1023,599,Blue2);
	
	LT768_DrawCircleSquare_Fill( xs+100,ys,xs+250,ys+60,10,10,Red);//0x0806);
  LT768_DrawCircleSquare_Fill( xs,     ys+100, xs+100, ys+160,10,10,0x3f80);
  LT768_DrawCircleSquare_Fill( xs+160, ys+100, xs+260, ys+160,10,10,0x3f80);
	LT768_DrawCircleSquare_Fill( xs+320, ys+100, xs+420, ys+160,10,10,0x3f80);
	LT768_DrawCircleSquare_Fill( xs+320, ys+  0, xs+420, ys+ 60,10,10,0x3f80);
	LT768_Select_Internal_Font_Init(32,1,1,1,0);
	LT768_Print_Internal_Font_String(xs+5,ys+120,Red,Green," Hhgh ");
	LT768_Print_Internal_Font_String(xs+5+160,ys+120,Red,Green," Low ");
	LT768_Print_Internal_Font_String(xs+5+320,ys+120,Red,Green," quit ");
	LT768_Print_Internal_Font_String(xs+5+320,ys+20,Red,Green,"P/flow");
	LT768_DrawSquare_Fill( xs+30,ys+240,xs+380,ys+260,White);			
	/*-------------------------------------*/
	LT768_DrawSquare_Fill(  0, 400,799, 579,0x0f1f);		
	
	for (i=0;i<8;i++)
	    {
			 for (j=0;j<2;j++)
				   {
						 LT768_DrawCircleSquare_Fill( 20+i*100, 420+j*80, 89+i*100, 469+j*80,10,10,0x3f80);
					 } 
			}
	LT768_Select_Internal_Font_Init(32,1,1,1,0);
	LT768_Print_Internal_Font_String( 30,425,Red,Green,"P00");
  LT768_Print_Internal_Font_String( 30,505,Red,Green,"P20");
	LT768_Print_Internal_Font_String(125,425,Red,Green,"PI00");
  LT768_Print_Internal_Font_String(125,505,Red,Green,"PI20");
  LT768_Print_Internal_Font_String(230,425,Red,Green,"O21");
  LT768_Print_Internal_Font_String(225,505,Red,Green,"O100");
	LT768_Print_Internal_Font_String(325,425,Red,Green,"V198");
  LT768_Print_Internal_Font_String(325,505,Red,Green,"V242");
	LT768_Print_Internal_Font_String(425,425,Red,Green,"O280");
  LT768_Print_Internal_Font_String(425,505,Red,Green,"O600");
	LT768_Print_Internal_Font_String(525,425,Red,Green,"A280");
  LT768_Print_Internal_Font_String(525,505,Red,Green,"A600");
	LT768_Select_Internal_Font_Init(24,1,1,1,0);		
	LT768_Print_Internal_Font_String(620,430,Red,Green,"Vt0.3");
	LT768_Print_Internal_Font_String(620,510,Red,Green,"ClrWT");			
	LT768_Print_Internal_Font_String(725,430,Red,Green,"En/Ch");
	LT768_Select_Internal_Font_Init(24,2,2,1,0);	
	LT768_Print_Internal_Font_String(740,505,White,Green,"X");
			
	for (i=0;i<3;i++)
	    {
			 for (j=0;j<2;j++)
				   {
						 LT768_DrawCircleSquare_Fill(530+i*130, 220+j*100,610+i*130, 270+j*100,10,10,0x70f6);
					 } 
			}
	
	LT768_Select_Internal_Font_Init(24,1,1,1,0);
	LT768_Print_Internal_Font_String(530,10,Green,Green,"Year");
	LT768_Print_Internal_Font_String(660,10,Green,Green,"Month");
	LT768_Print_Internal_Font_String(790,10,Green,Green,"Day");
	LT768_Print_Internal_Font_String(530,70,Green,Green,"Hour");
	LT768_Print_Internal_Font_String(650,70,Green,Green,"Minute");
	LT768_Print_Internal_Font_String(780,70,Green,Green,"Second");
	LT768_Select_Internal_Font_Init(32,1,1,1,0);
	LT768_Print_Internal_Font_String(550,150,Green,Green,"+");
	LT768_Print_Internal_Font_String(680,150,Green,Green,"-");
	LT768_Print_Internal_Font_String(780,150,Green,Green,"enter");
	
	Canvas_Image_Start_address(layer3_start_addr);
	Canvas_image_width(LCD_XSIZE_TFT);
  Active_Window_XY(0,0);
	Active_Window_WH(LCD_XSIZE_TFT,LCD_YSIZE_TFT);			
	LT768_DrawSquare_Fill(0,0,LCD_XSIZE_TFT-1,LCD_YSIZE_TFT-1,Blue3);
	
	for (yn=dateRecord0_y; yn<301; yn+=35)
	{
		Lines(dateRecord0_x,yn,dateRecord0_x+484,yn,White);  
	}
    Lines( dateRecord0_x,dateRecord0_y, dateRecord0_x,dateRecord0_y+280,White);
    Lines( dateRecord0_x+40,dateRecord0_y, dateRecord0_x+40,dateRecord0_y+280,White); 
    Lines( dateRecord0_x+160,dateRecord0_y, dateRecord0_x+160,dateRecord0_y+280,White);
    Lines( dateRecord0_x+484,dateRecord0_y, dateRecord0_x+484,dateRecord0_y+280,White);
	
	LT768_DrawSquare_Fill(600,0,1020,320,Blue2);
	for (i=0;i<3;i++)
	    {
			 for (j=0;j<4;j++)
				   {
						 LT768_DrawCircleSquare_Fill( xs+j*100+600, ys+70+i*80,xs+670+j*100, ys+120+i*80,10,10,0x07f6);
					 } 
			}
	LT768_Select_Internal_Font_Init(24,2,2,1,0);
	LT768_Print_Internal_Font_String(xs+630,ys,Red,Green,"X");		
	LT768_DrawCircleSquare_Fill( xs+820,ys,xs+940,ys+50,10,10,0x0806);		
	LT768_Select_Internal_Font_Init(32,1,1,1,0);  		
  LT768_Print_Internal_Font_String(xs+630,ys+80,Red,Green,"1");
	LT768_Print_Internal_Font_String(xs+630+100,ys+80,Red,Green,"2");
  LT768_Print_Internal_Font_String(xs+630+100*2,ys+80,Red,Green,"3");	
	LT768_Print_Internal_Font_String(xs+630,ys+80+80,Red,Green,"4");
	LT768_Print_Internal_Font_String(xs+630+100,ys+80+80,Red,Green,"5");
  LT768_Print_Internal_Font_String(xs+630+100*2,ys+80+80,Red,Green,"6");
	LT768_Print_Internal_Font_String(xs+630,ys+80+80*2,Red,Green,"7");
	LT768_Print_Internal_Font_String(xs+630+100,ys+80+80*2,Red,Green,"8");
  LT768_Print_Internal_Font_String(xs+630+100*2,ys+80+80*2,Red,Green,"9");
	LT768_Print_Internal_Font_String(xs+630+100*3,ys+80+80*2,Red,Green,"0");
	LT768_Select_Internal_Font_Init(24,1,1,1,0);
	LT768_Print_Internal_Font_String(xs+605+100*3,ys+80+80,Red,Green,"Enter");
	LT768_Print_Internal_Font_String(xs+605+100*3,ys+75,Red,Green,"Back");
	LT768_Print_Internal_Font_String(xs+605+100*3,ys+95,Red,Green,"space");
			
	for (i=0;i<2;i++)
	    {
			 for (j=0;j<5;j++)
				   {
						 LT768_DrawCircleSquare_Fill(50+j*150,380+i*100,150+j*150, 440+i*100,10,10,0x07f6);
					 } 
			}	
			
	Canvas_Image_Start_address(layer4_start_addr);
	Canvas_image_width(LCD_XSIZE_TFT);
  Active_Window_XY(0,0);
	Active_Window_WH(LCD_XSIZE_TFT,LCD_YSIZE_TFT);			
	LT768_DrawSquare_Fill(0,0,1023,599,Blue3);
  Lines(OrgXset,OrgYset,OrgXset+500,OrgYset,White);  //H		
  Lines(OrgXset,OrgYset-500,OrgXset,OrgYset,White);  //V
	for(i=0;i<=500; i+=25)
    {
     Point(OrgXset+i,OrgYset+1,White);
     Point(OrgXset+i,OrgYset+2,White);
     if (i%50==0)	Point(OrgXset+i,OrgYset+3,White);		
    }	
	for(i=0;i<=500; i+=25)
    {
     Point(OrgXset-1,OrgYset-500+i,White);
     Point(OrgXset-2,OrgYset-500+i,White);	
    }
		
	Canvas_Image_Start_address(layer5_start_addr);
	Canvas_image_width(LCD_XSIZE_TFT);
  Active_Window_XY(0,0);
	Active_Window_WH(LCD_XSIZE_TFT,LCD_YSIZE_TFT);			
	LT768_DrawSquare_Fill(0,0,1023,599,Blue3);
  Lines(OrgXset,OrgYset,OrgXset+500,OrgYset,White);  //H		
  Lines(OrgXset,OrgYset-500,OrgXset,OrgYset,White);  //V
	for(i=0;i<=500; i+=25)
    {
     Point(OrgXset+i,OrgYset+1,White);
     Point(OrgXset+i,OrgYset+2,White);
     if (i%50==0)	Point(OrgXset+i,OrgYset+3,White);		
    }	
	for(i=0;i<=500; i+=25)
    {
     Point(OrgXset-1,OrgYset-500+i,White);
     Point(OrgXset-2,OrgYset-500+i,White);	
    }
			
  Canvas_Image_Start_address(layer1_start_addr);

	Main_Image_Start_Address(layer1_start_addr);				
	Main_Image_Width(LCD_XSIZE_TFT);
	Main_Window_Start_XY(0,0);
	Canvas_Image_Start_address(layer1_start_addr);
	Canvas_image_width(LCD_XSIZE_TFT);
  Active_Window_XY(0,0);
	Active_Window_WH(LCD_XSIZE_TFT,LCD_YSIZE_TFT);			
	LT768_DrawSquare_Fill(0,0,LCD_XSIZE_TFT-1,LCD_YSIZE_TFT-1,0);
}
