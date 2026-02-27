#include "stm32f10x.h"  //包含需要的头文件
#include "main.h"       //包含需要的头文件
#include "delay.h"      //包含需要的头文件
#include "usart1.h"     //包含需要的头文件
#include "usart2.h"     //包含需要的头文件
#include "timer2.h"     //包含需要的头文件
#include "timer3.h"     //包含需要的头文件
#include "timer4.h"     //包含需要的头文件
#include "wifi.h"	      //包含需要的头文件
#include "mqtt.h"       //包含需要的头文件
#include "iwdg.h"       //包含需要的头文件
#include "dateup.h"      //包含需要的头文件
#include "switch.h"      //包含需要的头文件
#include "datedown.h"     //包含需要的头文件
#include "oled.h"       //包含需要的头文件
#include "adc.h"
#include "dht11.h"      //包含所需的头文件
#include "mq2.h"

unsigned int TEHUTimer=0;     //用于温湿度采集的计时的变量   单位秒
unsigned int SystemTimer=0;   //变量声明全局时间变量


int main(void) 
{	
	IWDG_Init(5,625);               //独立看门狗 时间2s
	Delay_Init();                   //延时功能初始化              
	Usart1_Init(9600);              //串口1功能初始化，波特率9600
	WiFi_ResetIO_Init();            //初始化WiFi的复位IO
	AliIoT_Parameter_Init();	    //初始化连接阿里云IoT平台MQTT服务器的参数	
	Adc_Init();
  SW_Init();
	DHT11_Init();
	OLED_Init();
	SW1_OFF;
	while(1)                       //主循环
	{		
		/*--------------------------------------------------------------------*/
		/*            Connect_flag=1同服务器建立了连接                        */
		/*--------------------------------------------------------------------*/
		if(Connect_flag==1){     

      connet_on();         //程序连接成功接收处理程序
			Data_State();         //各种数据的任务
			Data_Down();           //下发控制函数
			Delay_Ms(1);          //延时1ms，必须有，里面有喂狗，不然看门狗会溢出，造成复位				
		}	
		/*--------------------------------------------------------------------*/
		/*                         准备连接服务器                             */
		/*--------------------------------------------------------------------*/
		else{ 
		connet_first();
		}
	}
}

