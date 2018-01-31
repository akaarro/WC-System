#include <reg52.h>
#include <delay.h>
#include <motor.h>
unsigned char code F_Rotation[4]={0x02,0x04,0x08,0x10};//正转
unsigned char code B_Rotation[4]={0x10,0x08,0x040,0x02};//反转
void motor_zz()
{
	uint i;
	for(i=0;i<4;i++)
		{
			P1=F_Rotation[i]; 
			delay_1ms(200);
		}
}
void motor_fz()
{
	uint i;
	for(i=0;i<4;i++)
		{
			P1=B_Rotation[i]; 
			delay_1ms(200);
		}
}