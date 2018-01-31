#include <reg52.h>
#include "intrins.h"
#include <delay.h>
#include <LCD1602.h>
void write_com_1602(uchar com)
{
	rs=0;
	P0=com;
	delay_1ms(5);
	lcden=1;
	delay_1ms(5);
	lcden=0;
}
void write_data_1602(uchar data1)
{
	rs=1;
	P0=data1;
	delay_1ms(5);
	lcden=1;
	delay_1ms(5);
	lcden=0;
}
void init()
{
	lcden=0;
	write_com_1602(0x38);
	write_com_1602(0x0c);
	write_com_1602(0x06);
	write_com_1602(0x01);
	write_com_1602(0x80+0x10);//Œª÷√
}