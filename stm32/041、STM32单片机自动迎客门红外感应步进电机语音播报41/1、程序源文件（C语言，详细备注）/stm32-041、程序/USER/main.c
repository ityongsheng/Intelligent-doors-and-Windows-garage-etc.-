#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include <stdio.h>
#include "timer.h"
#include "key.h"
#include <stdio.h>
#include "adc.h"

#define TIMELATERNUM 2000		//步进电机旋转时间

unsigned char i ;	
char dis0[16];	 //暂存

unsigned char zfFlag = 0 ;		 //正反转标志
unsigned int  timeLater = 0;		 //时间延时
char rekey =0;//防止重复按下
char keyFlag = 0;//按键操作开门标志
void yyReportReadAdd(unsigned char yyAdd) ;
int main(void)
 { 		
	delay_init();	    	 //延时函数初始化	  
	uart_init(9600);	 	//串口初始化
	uart2_init(9600)	;
	 
  TIM3_Int_Init(29,7199);//3ms  	 
	
	LED_Init();		  		//初始化与LED连接的硬件接口 	 
	KEY_Init();
	 
	zfFlag = 1 ;		 //正反转标志
	timeLater = TIMELATERNUM;		 //时间延时	
	
	delay_ms(100);
	yyReportReadAdd(86);//播报地址语音 “欢迎使用”
	 while(1)
	{	
		if(key==0) //检测到按键按下
		{
		 	if(rekey == 0)//防止重复按下
			{
				delay_ms(20); 
				if(key==0)//确认按键按下
				{
					rekey =1;
					if(zfFlag != 2)	//门没有打开或者没在打开过程
					{
						zfFlag=2;		//驱动电机启动 正传开门
						timeLater = TIMELATERNUM; 	//旋转//**All notes can be deleted and modified**//
						keyFlag = 1;//按键操作开门标志						
					}			
					yyReportReadAdd(85);//播报地址语音		//欢迎再次光临			
				}			
			}
		}
		else
		{rekey =0 ;}	//防止重复按下
		
		if(keyFlag == 1)//按键操作标志
		{
			if(timeLater == 0 ){keyFlag = 0;}//按键开门操作完成
		}
		else
		{
			if(manhot == 0)
			{
				if(zfFlag != 2)	//门没有打开或者没在打开过程
				{
					zfFlag=2;		//驱动电机启动 正传开门
					timeLater = TIMELATERNUM; 	//旋转//**All notes can be deleted and modified**//
					yyReportReadAdd(84);//播报地址语音  //欢迎光临
				}
			}
			else
			{
				if(zfFlag != 1)	//门没有打开或者没在打开过程
				{
					zfFlag=1;		//驱动电机启动 正传开门
					timeLater = TIMELATERNUM; 	//旋转//**All notes can be deleted and modified**//
				}
			}			
		}					
	}											    
}
 
void ctrlBuJinDj(void)
{
	static unsigned char MotorNum=0;

	if(timeLater>0)
	{
		timeLater-- ;
		if(zfFlag==2)			  //电机转动时间不为零 设置了时间		正转
		{
			MotorNum++;
			if(MotorNum==1)//接通d相 其他关闭
			{Coil_D1;}
			else if(MotorNum==2)//接通c相 其他关闭
			{Coil_C1;}
			else if(MotorNum==3)//接通b相 其他关闭
			{Coil_B1;}
			else if(MotorNum==4)//接通a相 其他关闭
			{Coil_A1;MotorNum=0;}
		}
		else if(zfFlag==1)			  //电机转动时间不为零 设置了时间 反转
		{
			MotorNum++;
			if(MotorNum==1)		//接通a相 其他关闭
			{Coil_A1;}
			else if(MotorNum==2)   //接通b相 其他关闭
			{Coil_B1;}
			else if(MotorNum==3)//接通c相 其他关闭
			{Coil_C1;}
			else if(MotorNum==4)//接通d相 其他关闭
			{Coil_D1;MotorNum=0;}
		}	
	}
	else
	{
		{Coil_OFF;}	
	}
}

void yyReportReadAdd(unsigned char yyAdd) //语音播报地址
{
	yy_rest=0; 			//yyxp（语音芯片的简写，下同)的复位脚为高电平//
	delay_us(300); 	//持续 200us//
	yy_rest=1; 			//然后复位脚置零//
	delay_us(300); 
	yy_rest=0; 			//yyxp（语音芯片的简写，下同)的复位脚为高电平//
	delay_us(300); //持续 200us//
	yy_rest=1; 			//然后复位脚置零//
	delay_us(300); 
	while(yyAdd>0)				 //若  等于 0 则不工作，若大于 0 则继续自减//
	{
		yy_data=0; 			//data 脚位为高电平//
		delay_us(300); 		//持续 100us//
		yy_data=1; 			//然后置零//                          
		delay_us(300); //持续 100us 这三句的意思就是发从一个 100us 的脉冲（高低各 100us）//
		yyAdd--; 				//z 自减完成后开始播放对应的语音（因为 z 是几就播放第几段）//
	}
	delay_ms(5);
}









