#include <reg52.h>
#include <delay.h>
#include <LCD12864.h>
#include <LCD1602.h>
#include <led.h>
#include <motor.h>
#include <isd4004.h>
#include <hcsr04.h>
 #include <STDIO.H>
uint location[4]=   //蹲位数据
{0,1,2,1};
extern uchar key;		//key.c中的外部变量
extern bit 	 flag_hc;	//hcsr04.c中的外部变量
#define PORT_1 P1	
bit   FLAG_ON;
uchar time_flag;
uchar R_DAT,G_DAT;B_DAT;
uchar key_return;
uchar PWM_HL,REPEAT;
float distance;
void Init_INT0()
{
 EX0=1;    //开启外部中断 0
 IT0=1;          //设置成低电平触发，1为下降沿触发
 EX1=1;    //开启外部中断 1
 IT1=1;          //设置成低电平触发，1为下降沿触发
 EA=1;     //开启总中断
 PX1=1;
 PX0=1;
}
void main()
{
	uint i;
	Init_INT0();  //外部中断初始化
	delay_1ms(500);
	init_hc();//初始化hcsr04
	CH = 0;//12864选择串行
	delay_100us(1);
	lcdinit();//12864液晶屏初始化
	//init();//1602初始化
	delay_1ms(1);
	welcome();//显示汉字
				  	
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
		if(key_return==2)	 //女生
			{
				while(location[i]!=0&&i<=3)
				{
					i++;	
				};   //先检查坑位
				if(i==4)
				{
					i=0;
					women_full();       //坑位已满
					delay_1ms(2000);	
					welcome();
				}
				else
				{
					play(0x00);		   //语音模块欢迎女生
					location[i]=2;         //该坑位分配给女生
					color_welcome_women();       //灯光变换表示欢迎
					women_display_num('1'+i);	 //显示屏显示坑位
					delay_1ms(2000);
					welcome();
					i=0;
				}		    
				
				key_return=0;
			}
		else if(key_return==1)	 //男生
			{
				while(location[i]!=0&&i<=3)
				{
					i++;	
				};   //先检查坑位
				if(i==4)
				{
					i=0;
					men_full();       //坑位已满
					delay_1ms(2000);	
					welcome();
				}
				else
				{
					
					play(0x100);		   //语音模块欢迎男生	
					location[i]=1;         //该坑位分配给男生
					color_welcome_men();       //灯光变换表示欢迎
					men_display_num('1'+i);	 //显示屏显示坑位
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
			if(distance>=15&&location[0]!=0)						//如果超过距离
			{
			 if(location[0]==2)	 //女生
			 {
			 	play(0x200);	       //语音提示
			 	location[0]=0;        //此位已空
			 }
			 else if(location[0]==1)
			 {
			 	play(0x300);		   //语音提示
			 	location[0]=0;        //此位已空
			 }

			}
			distance=0;
		}
	}
	
}  
void Interrupt0_handler() interrupt 0	//p3^2
{
    EA=0;   //首先关闭总中断，以消除按键出现的抖动所产生的干扰
	delay_1ms(200); //同样是为了消除抖动而产生新的中断
	key_return=2;  //女生
	EA=1;            //恢复中断
}

void zd0() interrupt 1 		 //T0中断用来计数器溢出,超过测距范围
{
    flag_hc=1;							 //中断溢出标志
}
void Interrupt1_handler() interrupt 2	   //p3^3
{
    EA=0;   //首先关闭总中断，以消除按键出现的抖动所产生的干扰
	delay_1ms(200); //同样是为了消除抖动而产生新的中断
    key_return=1;     //男生
 	EA=1;            //恢复中断
} 