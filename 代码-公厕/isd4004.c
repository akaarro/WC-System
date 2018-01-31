#include <reg52.h>
#include "intrins.h"
#include <delay.h>
#include <isd4004.h>
bit playbit,recbit;	//定义两个位变量，放音和录音位
uchar playcout,reccout;	 //放音和录音次数。	
////////////////放音部分子程序，放音地址由ADDR决定////
void play(uint addr)
 { 	uint y;
	SS=0;
	MOSI=0;//发送开始
	SCLK=0;
	for(y=0;y<8;y++)
	{
		SCLK=0;
		if((0x20>>y)&0x01)MOSI=1;
		else MOSI=0;
		_nop_();
		_nop_();
		_nop_();
		SCLK=1;
		_nop_();
		_nop_();
		_nop_();
	}//发送结束
	SS=1;//上电结束
	delay_1ms(50);
	SS=0;
	MOSI=0;//发送地址
	SCLK=0;
	for(y=0;y<16;y++)
	{
		SCLK=0;
		if((addr>>y)&0x01)MOSI=1;
		else MOSI=0;
		_nop_();
		_nop_();
		_nop_();
		SCLK=1;
		_nop_();
		_nop_();
		_nop_();
	}//发送地址结束
	MOSI=0;//放音
	SCLK=0;
	for(y=0;y<8;y++)
	{
		SCLK=0;
		if((0xe0>>y)&0x01)MOSI=1;
		else MOSI=0;
		_nop_();
		_nop_();
		_nop_();
		SCLK=1;
		_nop_();
		_nop_();
		_nop_();
	}
	SS=1;
	SS=0;
	MOSI=0;//放音
	SCLK=0;
	for(y=0;y<8;y++)
	{
		SCLK=0;
		if((0xf0>>y)&0x01)MOSI=1;
		else MOSI=0;
		_nop_();
		_nop_();
		_nop_();
		SCLK=1;
		_nop_();
		_nop_();
		_nop_();
	}
	SS=1;	  }	