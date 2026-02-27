#include "stm32f10x.h"  //包含需要的头文件
#include "switch.h"        //包含需要的头文件
#include "mqtt.h"       //包含需要的头文件
#include "main.h"       //包含需要的头文件
#include "usart1.h"     //包含需要的头文件

/*-------------------------------------------------*/
/*函数名：初始化SW函数                            */
/*参  数：无                                       */
/*返回值：无                                       */
/*-------------------------------------------------*/
void SW_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;                     //定义一个设置GPIO的变量

    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE);                                //使能GPIOA端口时钟
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE);                                //使能GPIOB端口时钟

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;                                             //准备设置PA5
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;                                     //IO速率50Mhz
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;   		                              //推免输出方式
    GPIO_Init(GPIOA, &GPIO_InitStructure);            		                              //设置PA5

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1  | GPIO_Pin_10 | GPIO_Pin_11;                //准备设置PB1 PB10 PB11
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;                                     //IO速率50Mhz
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   		                              //推免输出方式
    GPIO_Init(GPIOB, &GPIO_InitStructure);            		                              //设置PB1 PB10 PB11

 
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
/*-------------------------------------------------*/
/*函数名：判断开关1状态，并发布给服务器            */
/*参  数：无                                       */
/*返回值：无                                       */
/*-------------------------------------------------*/
void SW1_State(void)
{
    char temp[TBUFF_UNIT];   //定义一个临时缓冲区

    if(SW1_IN_STA) sprintf(temp,"{\"method\":\"thing.event.property.post\",\"id\":\"203302322\",\"params\":{\"SwitchSta1\":0,\"deng\":0},\"version\":\"1.0.0\"}");  //如果SW1是高电平，说明是关闭状态，需要回复关闭状态给服务器
    else            sprintf(temp,"{\"method\":\"thing.event.property.post\",\"id\":\"203302322\",\"params\":{\"SwitchSta1\":1,\"deng\":1},\"version\":\"1.0.0\"}");  //如果SW1是低电平，说明是打开状态，需要回复打开状态给服务器
    MQTT_PublishQs0(P_TOPIC_NAME,temp,strlen(temp));   //添加数据，发布给服务器
}
/*-------------------------------------------------*/
/*函数名：判断开关2状态，并发布给服务器            */
/*参  数：无                                       */
/*返回值：无                                       */
/*-------------------------------------------------*/
void SW2_State(void)
{
    char temp[TBUFF_UNIT];                   //定义一个临时缓冲区

    if(SW2_IN_STA) sprintf(temp,"{\"method\":\"thing.event.property.post\",\"id\":\"203302322\",\"params\":{\"SwitchSta2\":0,\"fengsan\":1},\"version\":\"1.0.0\"}");  //如果SW2是高电平，说明是关闭状态，需要回复关闭状态给服务器
    else            sprintf(temp,"{\"method\":\"thing.event.property.post\",\"id\":\"203302322\",\"params\":{\"SwitchSta2\":1,\"fengsan\":0},\"version\":\"1.0.0\"}");  //如果SW2是低电平，说明是打开状态，需要回复打开状态给服务器
    MQTT_PublishQs0(P_TOPIC_NAME,temp,strlen(temp));   //添加数据，发布给服务器
}
/*-------------------------------------------------*/
/*函数名：判断开关3状态，并发布给服务器            */
/*参  数：无                                       */
/*返回值：无                                       */
/*-------------------------------------------------*/
void SW3_State(void)
{
    char temp[TBUFF_UNIT];                   //定义一个临时缓冲区

    if(SW3_IN_STA) sprintf(temp,"{\"method\":\"thing.event.property.post\",\"id\":\"203302322\",\"params\":{\"SwitchSta3\":0,\"Switch3\":0},\"version\":\"1.0.0\"}");  //如果SW3是高电平，说明是关闭状态，需要回复关闭状态给服务器
    else            sprintf(temp,"{\"method\":\"thing.event.property.post\",\"id\":\"203302322\",\"params\":{\"SwitchSta3\":1,\"Switch3\":1},\"version\":\"1.0.0\"}");  //如果SW3是低电平，说明是打开状态，需要回复打开状态给服务器
    MQTT_PublishQs0(P_TOPIC_NAME,temp,strlen(temp));   //添加数据，发布给服务器
}
/*-------------------------------------------------*/
/*函数名：判断开关4状态，并发布给服务器            */
/*参  数：无                                       */
/*返回值：无                                       */
/*-------------------------------------------------*/
void SW4_State(void)
{
    char temp[TBUFF_UNIT];                   //定义一个临时缓冲区

    if(SW4_IN_STA) sprintf(temp,"{\"method\":\"thing.event.property.post\",\"id\":\"203302322\",\"params\":{\"SwitchSta4\":0,\"Switch4\":0},\"version\":\"1.0.0\"}");  //如果SW4是高电平，说明是关闭状态，需要回复关闭状态给服务器
    else            sprintf(temp,"{\"method\":\"thing.event.property.post\",\"id\":\"203302322\",\"params\":{\"SwitchSta4\":1,\"Switch4\":1},\"version\":\"1.0.0\"}");  //如果SW4是低电平，说明是打开状态，需要回复打开状态给服务器
    MQTT_PublishQs0(P_TOPIC_NAME,temp,strlen(temp));   //添加数据，发布给服务器
}

