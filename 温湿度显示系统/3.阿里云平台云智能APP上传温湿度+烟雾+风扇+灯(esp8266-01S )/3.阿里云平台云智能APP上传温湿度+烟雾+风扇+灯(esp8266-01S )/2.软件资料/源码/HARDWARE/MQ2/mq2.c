#include "mq2.h"
#include "time.h"
#include "adc.h"
#include "stdio.h"
#include "math.h"
#include "delay.h"

#define CAL_PPM 	20  	// 校准环境中PPM值
#define RL			5		// RL阻值
static float R0 = 4.00; 	// 元件在洁净空气中的阻值 6.0
u16 times_mq2 = 1;



//得到ADC采样内部传感器的值
//取10次,然后平均
vu16 Get_ADCValue_MQ2(void)
{
	u32 val = 0;
	u8 times = 10;
	u8 count;
	for(count = 0; count < times; count++)
	{
		val += Get_Adc_Average(0,5);//获取DMA通道值
		Delay_Ms(5);
	}
	return val/times;
}


/********************************************
 * 1.651428	          200               *
 * 1.437143	          300               *
 * 1.257143	          400               *
 * 1.137143	          500               *
 * 1		              600               *
 * 0.928704	          700               *
 * 0.871296	          800               *
 * 0.816667	          900               *
 * 0.785714	          1000              *
 * 0.574393	          2000              *
 * 0.466047	          3000              *
 * 0.415581	          4000              *
 * 0.370478	          5000              *
 * 0.337031	          6000              *
 * 0.305119	          7000              *
 * 0.288169	          8000              *
 * 0.272727	          9000              *
 * 0.254795	          10000             *
 *                                      *
 * ppm = 613.9f * pow(RS/RL, -2.074f)   *
 ***************************************/
 
// 传感器校准函数
void MQ2_PPM_Calibration(float RS)
{
    R0 = RS / pow(CAL_PPM / 613.9f, 1 / -2.074f);
}
 
// MQ2传感器数据处理
float MQ2_GetPPM(void)
{	
    float Vrl ,RS ,ppm ;
		Vrl	= 3.3f * Get_ADCValue_MQ2() / 4096.f;
	  Vrl = ( (float)( (int)( (Vrl+0.005)*100 ) ) )/100;
		RS = (3.3f - Vrl) / Vrl * RL; 

	if(times_mq2 == 1) // 获取系统执行时间，300ms前进行校准
    {
		R0 = RS / pow(CAL_PPM / 613.9f, 1 / -2.074f);
		times_mq2 = 0;
    }
	 
		 
    ppm = 613.9f * pow(RS/R0, -2.074f);
	  //ppm = pow(11.5428 * 35.904 * Vrl/(25.5-5.1* Vrl),0.6549);
	//https://blog.csdn.net/qq_35952136/article/details/95589074
    return  ppm*10;
}
		 







