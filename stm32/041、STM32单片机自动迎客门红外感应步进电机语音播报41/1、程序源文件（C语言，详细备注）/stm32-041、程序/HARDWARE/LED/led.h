#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 


#define TONGA PAout(11)// 步进电机控制
#define TONGB PAout(10)//
#define TONGC PAout(9)//
#define TONGD PAout(8)//

#define yy_data PAout(0)
#define yy_rest PAout(1)

#define Coil_A1 {TONGA=1;TONGB=0;TONGC=1;TONGD=0;}//A相通电，其他相断电
#define Coil_B1 {TONGA=0;TONGB=1;TONGC=0;TONGD=1;}//B相通电，其他相断电
#define Coil_C1 {TONGA=0;TONGB=0;TONGC=1;TONGD=0;}//C相通电，其他相断电
#define Coil_D1 {TONGA=0;TONGB=0;TONGC=0;TONGD=1;}//D相通电，其他相断电
#define Coil_OFF {TONGA=0;TONGB=0;TONGC=0;TONGD=0;}//全部断电

void LED_Init(void);//初始化

		 				    
#endif
