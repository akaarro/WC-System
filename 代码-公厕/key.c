#include <reg52.h>
#include <intrins.h>
#include <delay.h>
#include <key.h>


uchar key;
uchar key_input()//返回按得哪个键（0,1）
{
	if(key0==0)
	{
		delay_1ms(10);
		if(key0==0)
		{
			key=0;
			while(!key0);
		}
	}
	else if(key1==0)
	{
		delay_1ms(10);
		if(key1==0)
		{
			key=1;
			while(!key1);
		}
	}
		return key;
}
