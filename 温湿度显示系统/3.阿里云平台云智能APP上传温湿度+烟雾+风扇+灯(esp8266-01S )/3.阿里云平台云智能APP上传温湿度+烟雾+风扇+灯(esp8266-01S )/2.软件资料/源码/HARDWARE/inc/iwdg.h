#ifndef _IWDG_H
#define _IWDG_H

void IWDG_Init(unsigned char prer,unsigned int rlr); //看门狗初始化
void IWDG_Feed(void);                                //喂狗函数

#endif
