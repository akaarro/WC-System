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
	TMOD=0x21;		   //设T0为方式1，GATE=1；
	SCON=0x50;
	TH1=0xFD;
	TL1=0xFD;
	TH0=0;
	TL0=0; 
	TR0=1;  
	ET0=1;             //允许T0中断
	TR1=1;			   //开启定时器
	TI=1;
	//EA=1;			   //开启总中断
}
float Conut(void)
{
	 time=TH0*256+TL0;
	 TH0=0;
	 TL0=0;
	 S=(time*1.87)/100;     //算出来是CM（最终结果）
	 if(flag_hc==1)		    //超出测量
	 {
	  flag_hc=0;
	  printf("-----\n"); 
	 }
	 //printf("S=%f\n",S); 
	 return S; 
}
	
void  StartModule() 		         //T1中断用来扫描数码管和计800MS启动模块
 {
	  TX=1;			                 //800MS  启动一次模块
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
float hcsr04_once()//测量一次距离
{
	 StartModule();
	 while(!RX);		//当RX为零时等待
	 TR0=1;			    //开启计数
	 while(RX);			//当RX为1计数并等待
	 TR0=0;				//关闭计数
  	 return Conut();			//计算
}