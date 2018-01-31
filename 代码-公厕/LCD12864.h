#ifndef __LCD_H__
#define __LCD_H__

sbit CS   =P1^0;	  //片选
sbit SID  =P1^1;		//数据
sbit _SCLK=P1^2;		//时钟 
sbit CH   =P1^3;		//并行/串行选择
sbit RST  =P1^4;		//复位


void sendbyte(unsigned char zdata);
void write_com(unsigned char cmdcode);
void write_data(unsigned char Dispdata);
void lcdinit();
void hzkdis(unsigned char code *s);
void welcome();
void women_display_num(uchar num);
void men_display_num(uchar num);
void women_full();
void men_full();




#endif