#include "main.h"       //包含需要的头文件
#include "mqtt.h"       //包含需要的头文件
#include "dateup.h"      //包含需要的头文件
#include "delay.h"      //包含需要的头文件
#include "usart1.h"     //包含需要的头文件
#include "usart2.h"     //包含需要的头文件
#include "timer2.h"     //包含需要的头文件
#include "timer3.h"     //包含需要的头文件
#include "timer4.h"     //包含需要的头文件
#include "wifi.h"	      //包含需要的头文件
#include "mqtt.h"       //包含需要的头文件
#include "iwdg.h"       //包含需要的头文件
#include "adc.h"       //包含需要的头文件
#include "oled.h"       //包含需要的头文件
#include "dht11.h"      //包含所需的头文件
#include "switch.h"        //包含需要的头文件
#include "mq2.h"

/*-------------------------------------------------*/
/*函数名：定时上传各种数据的任务                   */
/*参  数：无                                       */
/*返回值：无                                       */
/*-------------------------------------------------*/
void Data_State(void)
{
	
	  u8 tempdata , humidata;	//用于保存温湿度的变量	
    int mq2;
    char temp[256];             //缓冲区
    if((SystemTimer - TEHUTimer)>=5) {                                    //全局时间 和 温湿度计时时间至少差30s，进入if
        TEHUTimer = SystemTimer;                                           //把当前的全局时间，记录到温湿度计时变量
				mq2 = MQ2_GetPPM(); //读取土壤湿度		
				DHT11_Read_Data(&tempdata, &humidata);	//读取温湿度值  
			
				u1_printf("烟雾MQ2:%d\r\n",  mq2);                         //串口土壤
			  u1_printf("温度：%d  湿度：%d\r\n",tempdata,humidata);         //串口温湿度输出数据
//	--------------------------
				OLED_Clear(); 
			  OLED_ShowCHinese(20,0,2);
				OLED_ShowCHinese(40,0,4);
				OLED_ShowNum(60,0,tempdata,2,16);		
        OLED_ShowCHinese(20,2,3);
				OLED_ShowCHinese(40,2,4);
				OLED_ShowNum(60,2,humidata,2,16);	
				OLED_ShowCHinese(20,4,0);//烟
				OLED_ShowCHinese(40,4,1);//雾
//				OLED_ShowString(26,4,"MQ2",16);
				OLED_ShowNum(60,4,mq2,3,16);

			
			
        sprintf(temp,"{\"method\":\"thing.event.property.post\",\"id\":\"203302322\",\"params\":{\"shidu\":%d,\"wendu\":%d,\"yanwu\":%d},\"version\":\"1.0.0\"}",humidata,tempdata,mq2);  //构建数据
        MQTT_PublishQs0(P_TOPIC_NAME,temp,strlen(temp));                  //添加数据到发送缓冲区

    }

}
