#include <reg52.h>
#include <delay.h>
#include <LCD12864.h>

void sendbyte(unsigned char zdata)
{
	unsigned int i;
	for(i=0; i<8; i++)
	{
		if((zdata << i) & 0x80)
		{
			SID = 1;
		}
		else 
		{
			SID = 0;
		}
		_SCLK = 0;
		_SCLK = 1;
	}
}
void write_com(unsigned char cmdcode)
{
	CS = 1;
	sendbyte(0xf8);
	sendbyte(cmdcode & 0xf0);
	sendbyte((cmdcode << 4) & 0xf0);
	delay_100us(2);
}
void write_data(unsigned char Dispdata)
{
	CS = 1;
	sendbyte(0xfa);
	sendbyte(Dispdata & 0xf0);
	sendbyte((Dispdata << 4) & 0xf0);
	delay_100us(2);
}
void lcdinit()
{  
	RST = 0;
	delay_100us(100);
	RST = 1;
	delay_100us(20000);
	write_com(0x30);//基本指令集动作
	delay_100us(50);
	write_com(0x0c);//不整体显示
	delay_100us(50);
//	write_com(0x34);//扩充指令集动作
//	delay_100us(50);
//	write_com(0x06);//反白
//	delay_100us(50);
//	write_com(0x30);//基本指令集动作
//	delay_100us(50);

}
void hzkdis(unsigned char code *s)//显示字符串
{  
	while(*s > 0)
    { 
			write_data(*s);
			s++;
			delay_100us(50);
    }
}
void welcome()
{
	write_com(0x01);
	delay_100us(50);
	write_com(0x03);
	delay_100us(50);    
	write_com(0x80);//位置，以后都是
	hzkdis("欢迎使用!");
	write_com(0x90);
	hzkdis("公厕资源调配系统");
	write_com(0x88);
	hzkdis("欢迎联系");
	write_com(0x98);
	hzkdis("TEL:15922861093");
}
void women_display_num(uchar num)
{
	write_com(0x01);
	delay_100us(50);	
	write_com(0x03);
	delay_100us(50);    
	write_com(0x80);//位置，以后都是
	hzkdis("欢迎使用，女士！");
	write_com(0x90);
	hzkdis("请前往：");
	write_com(0x88);
	write_data(num);
	delay_100us(50);
	write_com(0x89);
	hzkdis("号位 ");
	write_com(0x98);
	hzkdis("祝您今日愉快~");	
}
void men_display_num(uchar num)
{
	write_com(0x01);
	delay_100us(50);	
	write_com(0x03);
	delay_100us(50);    
	write_com(0x80);//位置，以后都是
	hzkdis("欢迎使用，先生！");
	write_com(0x90);
	hzkdis("请前往：");
	write_com(0x88);
	write_data(num);
	delay_100us(50);
	write_com(0x89);
	hzkdis("号位 ");
	write_com(0x98);
	hzkdis("祝您今日愉快~");	
}
void women_full()
{
	write_com(0x01);
	delay_100us(50);
	write_com(0x03);
	delay_100us(50);    
	write_com(0x80);//位置，以后都是
	hzkdis("非常抱歉，女士！");
	write_com(0x90);
	hzkdis("本公厕目前无多余");
	write_com(0x88);
	hzkdis("的蹲位！");
	write_com(0x98);
	hzkdis("请耐心等待");			
}
void men_full()
{
	write_com(0x01);
	delay_100us(50);
	write_com(0x03);
	delay_100us(50);    
	write_com(0x80);//位置，以后都是
	hzkdis("非常抱歉，先生！");
	write_com(0x90);
	hzkdis("本公厕目前无多余");
	write_com(0x88);
	hzkdis("的蹲位！");
	write_com(0x98);
	hzkdis("请耐心等待");			
}