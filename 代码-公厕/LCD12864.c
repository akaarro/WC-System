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
	write_com(0x30);//����ָ�����
	delay_100us(50);
	write_com(0x0c);//��������ʾ
	delay_100us(50);
//	write_com(0x34);//����ָ�����
//	delay_100us(50);
//	write_com(0x06);//����
//	delay_100us(50);
//	write_com(0x30);//����ָ�����
//	delay_100us(50);

}
void hzkdis(unsigned char code *s)//��ʾ�ַ���
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
	write_com(0x80);//λ�ã��Ժ���
	hzkdis("��ӭʹ��!");
	write_com(0x90);
	hzkdis("������Դ����ϵͳ");
	write_com(0x88);
	hzkdis("��ӭ��ϵ");
	write_com(0x98);
	hzkdis("TEL:15922861093");
}
void women_display_num(uchar num)
{
	write_com(0x01);
	delay_100us(50);	
	write_com(0x03);
	delay_100us(50);    
	write_com(0x80);//λ�ã��Ժ���
	hzkdis("��ӭʹ�ã�Ůʿ��");
	write_com(0x90);
	hzkdis("��ǰ����");
	write_com(0x88);
	write_data(num);
	delay_100us(50);
	write_com(0x89);
	hzkdis("��λ ");
	write_com(0x98);
	hzkdis("ף���������~");	
}
void men_display_num(uchar num)
{
	write_com(0x01);
	delay_100us(50);	
	write_com(0x03);
	delay_100us(50);    
	write_com(0x80);//λ�ã��Ժ���
	hzkdis("��ӭʹ�ã�������");
	write_com(0x90);
	hzkdis("��ǰ����");
	write_com(0x88);
	write_data(num);
	delay_100us(50);
	write_com(0x89);
	hzkdis("��λ ");
	write_com(0x98);
	hzkdis("ף���������~");	
}
void women_full()
{
	write_com(0x01);
	delay_100us(50);
	write_com(0x03);
	delay_100us(50);    
	write_com(0x80);//λ�ã��Ժ���
	hzkdis("�ǳ���Ǹ��Ůʿ��");
	write_com(0x90);
	hzkdis("������Ŀǰ�޶���");
	write_com(0x88);
	hzkdis("�Ķ�λ��");
	write_com(0x98);
	hzkdis("�����ĵȴ�");			
}
void men_full()
{
	write_com(0x01);
	delay_100us(50);
	write_com(0x03);
	delay_100us(50);    
	write_com(0x80);//λ�ã��Ժ���
	hzkdis("�ǳ���Ǹ��������");
	write_com(0x90);
	hzkdis("������Ŀǰ�޶���");
	write_com(0x88);
	hzkdis("�Ķ�λ��");
	write_com(0x98);
	hzkdis("�����ĵȴ�");			
}