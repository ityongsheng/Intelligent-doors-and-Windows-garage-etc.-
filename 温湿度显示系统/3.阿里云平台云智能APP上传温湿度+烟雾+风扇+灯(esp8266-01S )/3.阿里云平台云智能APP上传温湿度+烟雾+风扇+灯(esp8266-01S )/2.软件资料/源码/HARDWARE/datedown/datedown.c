#include "switch.h"        //包含需要的头文件
#include "mqtt.h"       //包含需要的头文件
#include "usart1.h"     //包含需要的头文件
#include "datedown.h"     //包含需要的头文件
#include "stm32f10x.h"  //包含需要的头文件
 #include "adc.h"
 #include "dht11.h"      //包含所需的头文件

void Data_Down(void) //数据下发处理函数
{
    if(MQTT_CMDOutPtr != MQTT_CMDInPtr) {                            //if成立的话，说明命令缓冲区有数据了
        u1_printf("命令:%s\r\n",&MQTT_CMDOutPtr[2]);                 //串口输出信息
        if(strstr((char *)MQTT_CMDOutPtr+2,"\"params\":{\"deng\":1}")) {	          //如果搜索到"params":{"PowerSwitch":1}说明服务器下发打开开关1
            SW1_ON;                                                                   //打开SW1
            SW1_State();                                                              //判断开关状态，并发布给服务器
        }
        else if(strstr((char *)MQTT_CMDOutPtr+2,"\"params\":{\"deng\":0}")) {      //如果搜索到"params":{"PowerSwitch":0}说明服务器下发关闭开关1
            SW1_OFF;                                                                  //关闭SW1
            SW1_State();                                                              //判断开关状态，并发布给服务器
        }
				else if(strstr((char *)MQTT_CMDOutPtr+2,"\"params\":{\"fengsan\":0}")) {	          //如果搜索到"params":{"PowerSwitch":1}说明服务器下发打开开关2
            SW2_ON;                                                                   //打开SW2
            SW2_State();                                                              //判断开关状态，并发布给服务器
        }
        else if(strstr((char *)MQTT_CMDOutPtr+2,"\"params\":{\"fengsan\":1}")) {      //如果搜索到"params":{"PowerSwitch":0}说明服务器下发关闭开关2
            SW2_OFF;                                                                  //关闭SW2
            SW2_State();                                                              //判断开关状态，并发布给服务器
        }	
        MQTT_CMDOutPtr += CBUFF_UNIT;                             	 //指针下移
        if(MQTT_CMDOutPtr==MQTT_CMDEndPtr)           	             //如果指针到缓冲区尾部了
            MQTT_CMDOutPtr = MQTT_CMDBuf[0];          	             //指针归位到缓冲区开头
    }
    Data_Down_set();
}

void Data_Down_set(void)  //温度自动处理程序，可按照需求进行开启，开启后按照设定温度高于20摄氏度自动开启风扇
{
//    u8 tempdata = 0, humidata = 0;	//用于保存温湿度的变量	
//  	int shidu;
//	DHT11_Read_Data(&tempdata, &humidata);	//读取温湿度值  
//    shidu = Get_Tu_Average(0, 10); //读取土壤湿度	
//    if(shidu>20)
//    {
//        SW1_ON;                                                                   //打开SW1
//        SW1_State();                                                              //判断开关状态，并发布给服务器
//    }
//    else
//    {
//        SW1_OFF;                                                                  //关闭SW1
//        SW1_State();                                                              //判断开关状态，并发布给服务器
//    }

//    if(tempdata>20)
//    {
//        SW2_ON;                                                                   //打开SW1
//        SW2_State();                                                              //判断开关状态，并发布给服务器
//    }
//    else
//    {
//        SW2_OFF;                                                                  //关闭SW1
//        SW2_State();                                                              //判断开关状态，并发布给服务器
//    }
}





