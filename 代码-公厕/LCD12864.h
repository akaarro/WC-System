#ifndef __LCD_H__
#define __LCD_H__

sbit CS   =P1^0;	  //Ƭѡ
sbit SID  =P1^1;		//����
sbit _SCLK=P1^2;		//ʱ�� 
sbit CH   =P1^3;		//����/����ѡ��
sbit RST  =P1^4;		//��λ


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