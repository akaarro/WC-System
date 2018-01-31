#include <reg52.h>
#include <delay.h>
void delay_1ms(uint z)
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);	
}
void delay_100us(uint t)
{
	uint i,j;
	for(i=0; i<t;  i++)
    for(j=0; j<10; j++);
}
