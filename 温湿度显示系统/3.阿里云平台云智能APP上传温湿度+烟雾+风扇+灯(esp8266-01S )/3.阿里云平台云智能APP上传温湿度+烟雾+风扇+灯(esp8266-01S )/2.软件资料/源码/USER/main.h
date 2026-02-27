#ifndef __MAIN_H
#define __MAIN_H

extern unsigned int SystemTimer;        //变量声明
extern unsigned int TEHUTimer;        //变量声明

#define  PRODUCTKEY           "a1T1fI62kZW"                                        //产品ID
#define  DEVICENAME           "ZKYGQ"                                               //设备名  
#define  DEVICESECRE          "92bf7601338c313ccf255ac232c8e96d"                   //设备秘钥   
#define  S_TOPIC_NAME         "/sys/a1T1fI62kZW/ZKYGQ/thing/service/property/set"   //需要订阅的主题  
#define  P_TOPIC_NAME         "/sys/a1T1fI62kZW/ZKYGQ/thing/event/property/post"    //需要发布的主题  

//#define SSID   "CMCC-42DF"              //路由器SSID名称   2.4G   
//#define PASS   "96eas8eu"                 //路由器密码  ****WIFI6****
#define SSID   "yang"              //路由器SSID名称   2.4G   
#define PASS   "00000000"                 //路由器密码  ****WIFI6****



#endif











