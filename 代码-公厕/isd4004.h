#ifndef __ISD4004_H__
#define __ISD4004_H__



////////�����������,���峣��//////
#define ISDPOWERUP      0X20           //ISD4004�ϵ�
#define ISDSTOP         0X10           //ISD4004�µ�
#define OPERSTOP        0X30           //ISD4004ֹͣ��ǰ����
#define PLAYSET         0XE0           //ISD4004��ָ����ַ��ʼ����
#define PLAYCUR         0XF0           //ISD4004�ӵ�ǰ��ַ��ʼ����
#define RECSET          0XA0      	   //ISD4004��ָ����ַ��ʼ¼��
#define RECCUR          0XB0		   //ISD4004�ӵ�ǰ��ַ��ʼ¼��
							   
sbit   SS  =P1^7;            //LOW IS ACTIVELY
sbit   MOSI=P3^4;
//sbit   MISO=P1^7;
sbit   SCLK=P3^5; 
//sbit   K1  =P3^5;//¼
//sbit   K2  =P3^6;//��
//sbit   K3  =P3^7;//ͣ

void play(uint addr);




#endif