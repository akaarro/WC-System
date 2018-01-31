#include <reg52.h>
#include <delay.h>
#include <LCD12864.h>
#include <LCD1602.h>
#include <led.h>
#include <motor.h>
#include <isd4004.h>
#include <hcsr04.h>
 #include <STDIO.H>
uint location[4]=   //��λ����
{0,1,2,1};
extern uchar key;		//key.c�е��ⲿ����
extern bit 	 flag_hc;	//hcsr04.c�е��ⲿ����
#define PORT_1 P1	
bit   FLAG_ON;
uchar time_flag;
uchar R_DAT,G_DAT;B_DAT;
uchar key_return;
uchar PWM_HL,REPEAT;
float distance;
void Init_INT0()
{
 EX0=1;    //�����ⲿ�ж� 0
 IT0=1;          //���óɵ͵�ƽ������1Ϊ�½��ش���
 EX1=1;    //�����ⲿ�ж� 1
 IT1=1;          //���óɵ͵�ƽ������1Ϊ�½��ش���
 EA=1;     //�������ж�
 PX1=1;
 PX0=1;
}
void main()
{
	uint i;
	Init_INT0();  //�ⲿ�жϳ�ʼ��
	delay_1ms(500);
	init_hc();//��ʼ��hcsr04
	CH = 0;//12864ѡ����
	delay_100us(1);
	lcdinit();//12864Һ������ʼ��
	//init();//1602��ʼ��
	delay_1ms(1);
	welcome();//��ʾ����
				  	
	while(1)
	{
		P0=0XFF;
		for(i=0;i<4;i++)
		{
			if(location[i]!=0)
			{
				switch(i)
				{
					case 0:
						P0&=0xfd;
						break;
					case 1:
						P0&=0xf7;
						break;
					case 2:
						P0&=0xdf;
						break;
					case 3:
						P0&=0x7f;
						break;
				}
			}                     
		}
		i=0;
		if(key_return==2)	 //Ů��
			{
				while(location[i]!=0&&i<=3)
				{
					i++;	
				};   //�ȼ���λ
				if(i==4)
				{
					i=0;
					women_full();       //��λ����
					delay_1ms(2000);	
					welcome();
				}
				else
				{
					play(0x00);		   //����ģ�黶ӭŮ��
					location[i]=2;         //�ÿ�λ�����Ů��
					color_welcome_women();       //�ƹ�任��ʾ��ӭ
					women_display_num('1'+i);	 //��ʾ����ʾ��λ
					delay_1ms(2000);
					welcome();
					i=0;
				}		    
				
				key_return=0;
			}
		else if(key_return==1)	 //����
			{
				while(location[i]!=0&&i<=3)
				{
					i++;	
				};   //�ȼ���λ
				if(i==4)
				{
					i=0;
					men_full();       //��λ����
					delay_1ms(2000);	
					welcome();
				}
				else
				{
					
					play(0x100);		   //����ģ�黶ӭ����	
					location[i]=1;         //�ÿ�λ���������
					color_welcome_men();       //�ƹ�任��ʾ��ӭ
					men_display_num('1'+i);	 //��ʾ����ʾ��λ
					delay_1ms(2000);
					welcome();
					i=0;
				}		   		  
				key_return=0;
			}
		delay_1ms(300);
		time_flag++;
		if(time_flag==10) //3s
		{
			time_flag=0;
			distance=hcsr04_once();
			if(distance>=15&&location[0]!=0)						//�����������
			{
			 if(location[0]==2)	 //Ů��
			 {
			 	play(0x200);	       //������ʾ
			 	location[0]=0;        //��λ�ѿ�
			 }
			 else if(location[0]==1)
			 {
			 	play(0x300);		   //������ʾ
			 	location[0]=0;        //��λ�ѿ�
			 }

			}
			distance=0;
		}
	}
	
}  
void Interrupt0_handler() interrupt 0	//p3^2
{
    EA=0;   //���ȹر����жϣ��������������ֵĶ����������ĸ���
	delay_1ms(200); //ͬ����Ϊ�����������������µ��ж�
	key_return=2;  //Ů��
	EA=1;            //�ָ��ж�
}

void zd0() interrupt 1 		 //T0�ж��������������,������෶Χ
{
    flag_hc=1;							 //�ж������־
}
void Interrupt1_handler() interrupt 2	   //p3^3
{
    EA=0;   //���ȹر����жϣ��������������ֵĶ����������ĸ���
	delay_1ms(200); //ͬ����Ϊ�����������������µ��ж�
    key_return=1;     //����
 	EA=1;            //�ָ��ж�
} 