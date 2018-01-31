#ifndef __ISD4004_H__
#define __ISD4004_H__



////////定义放音命令,定义常量//////
#define ISDPOWERUP      0X20           //ISD4004上电
#define ISDSTOP         0X10           //ISD4004下电
#define OPERSTOP        0X30           //ISD4004停止当前操作
#define PLAYSET         0XE0           //ISD4004从指定地址开始放音
#define PLAYCUR         0XF0           //ISD4004从当前地址开始放音
#define RECSET          0XA0      	   //ISD4004从指定地址开始录音
#define RECCUR          0XB0		   //ISD4004从当前地址开始录音
							   
sbit   SS  =P1^7;            //LOW IS ACTIVELY
sbit   MOSI=P3^4;
//sbit   MISO=P1^7;
sbit   SCLK=P3^5; 
//sbit   K1  =P3^5;//录
//sbit   K2  =P3^6;//放
//sbit   K3  =P3^7;//停

void play(uint addr);




#endif