#ifndef __SW_H
#define __SW_H

#define SW1_OUT(x)   GPIO_WriteBit(GPIOA, GPIO_Pin_5,  (BitAction)x)  //设置PA5  的电平，可以打开关闭SW1
#define SW2_OUT(x)   GPIO_WriteBit(GPIOB, GPIO_Pin_1,  (BitAction)x)  //设置PB1  的电平，可以打开关闭SW2
#define SW3_OUT(x)   GPIO_WriteBit(GPIOB, GPIO_Pin_10, (BitAction)x)  //设置PB10 的电平，可以打开关闭SW3
#define SW4_OUT(x)   GPIO_WriteBit(GPIOB, GPIO_Pin_11, (BitAction)x)  //设置PB11 的电平，可以打开关闭SW4

#define SW1_IN_STA   GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_5)  //PA5  控制SW1,读取电平状态，可以判断SW1是打开还是关闭
#define SW2_IN_STA   GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_1)  //PB1  控制SW2,读取电平状态，可以判断SW2是打开还是关闭
#define SW3_IN_STA   GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_10) //PB10 控制SW3,读取电平状态，可以判断SW3是打开还是关闭
#define SW4_IN_STA   GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_11) //PB11 控制SW4,读取电平状态，可以判断SW4是打开还是关闭

#define SW1_ON       GPIO_ResetBits(GPIOA, GPIO_Pin_5)         //共阳极，拉低PA5电平，打开SW1
#define SW1_OFF      GPIO_SetBits(GPIOA, GPIO_Pin_5)           //共阳极，拉高PA5电平，关闭SW1

#define SW2_ON       GPIO_ResetBits(GPIOB, GPIO_Pin_1)         //共阳极，拉低PB1电平，打开SW2
#define SW2_OFF      GPIO_SetBits(GPIOB, GPIO_Pin_1)           //共阳极，拉高PB1电平，关闭SW2

#define SW3_ON       GPIO_ResetBits(GPIOB, GPIO_Pin_10)        //共阳极，拉低PB10电平，打开SW3
#define SW3_OFF      GPIO_SetBits(GPIOB, GPIO_Pin_10)          //共阳极，拉高PB10电平，关闭SW3

#define SW4_ON       GPIO_ResetBits(GPIOB, GPIO_Pin_11)        //共阳极，拉低PB11电平，打开SW4
#define SW4_OFF      GPIO_SetBits(GPIOB, GPIO_Pin_11)          //共阳极，拉高PB11电平，关闭SW4

void SW_Init(void);               //初始化	
void SW1_State(void);           //函数声明
void SW2_State(void);           //函数声明
void SW3_State(void);           //函数声明
void SW4_State(void);           //函数声明


#endif
