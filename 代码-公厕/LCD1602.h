#ifndef __LCD1602_H__
#define __LCD1602_H__

sbit lcden=P1^2;
sbit rs=P1^0;
sbit rw=P1^1;
void write_com_1602(uchar);
void write_data_1602(uchar);
void init();

#endif