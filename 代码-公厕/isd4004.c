#include <reg52.h>
#include "intrins.h"
#include <delay.h>
#include <isd4004.h>
bit playbit,recbit;	//��������λ������������¼��λ
uchar playcout,reccout;	 //������¼��������	
////////////////���������ӳ��򣬷�����ַ��ADDR����////
void play(uint addr)
 { 	uint y;
	SS=0;
	MOSI=0;//���Ϳ�ʼ
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
	}//���ͽ���
	SS=1;//�ϵ����
	delay_1ms(50);
	SS=0;
	MOSI=0;//���͵�ַ
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
	}//���͵�ַ����
	MOSI=0;//����
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
	MOSI=0;//����
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