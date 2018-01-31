#include <reg52.h>
#include "intrins.h"
#include <delay.h>
#include <hcsr04.h>
#include <STDIO.H>
unsigned int  time =0;
unsigned int  timer=0;
float            S =0;
bit        flag_hc =0;
void init_hc()
{
	TMOD=0x21;		   //��T0Ϊ��ʽ1��GATE=1��
	SCON=0x50;
	TH1=0xFD;
	TL1=0xFD;
	TH0=0;
	TL0=0; 
	TR0=1;  
	ET0=1;             //����T0�ж�
	TR1=1;			   //������ʱ��
	TI=1;
	//EA=1;			   //�������ж�
}
float Conut(void)
{
	 time=TH0*256+TL0;
	 TH0=0;
	 TL0=0;
	 S=(time*1.87)/100;     //�������CM�����ս����
	 if(flag_hc==1)		    //��������
	 {
	  flag_hc=0;
	  printf("-----\n"); 
	 }
	 //printf("S=%f\n",S); 
	 return S; 
}
	
void  StartModule() 		         //T1�ж�����ɨ������ܺͼ�800MS����ģ��
 {
	  TX=1;			                 //800MS  ����һ��ģ��
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_();
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_();
	  TX=0;
 }
float hcsr04_once()//����һ�ξ���
{
	 StartModule();
	 while(!RX);		//��RXΪ��ʱ�ȴ�
	 TR0=1;			    //��������
	 while(RX);			//��RXΪ1�������ȴ�
	 TR0=0;				//�رռ���
  	 return Conut();			//����
}