#include <reg52.h>
#include <delay.h>
#include <led.h>
/*void color_change()
{
	  uchar fade_1,fade_2,fade_3,fade_4;
         fade_2=128;
         fade_4=127;
         while(fade_2!=0)
         {
                 for(fade_3=128;fade_3>fade_4;fade_3--)
                 {
                         LED_R=0;
                         LED_G=1;
                         delay_1ms(50);
                 }
                 fade_3=128;
                 fade_4--;
                 for(fade_1=0;fade_1<fade_2;fade_1++)
                 {
                         LED_R=1;
                         LED_G=0;
                         delay_1ms(50);	 
                 }
                 fade_1=0;
                 fade_2--;
         }

         fade_2=128;
         fade_4=127;
         while(fade_2!=0)
         {
                 for(fade_3=128;fade_3>fade_4;fade_3--)
                 {
                         LED_G=0;
                         LED_B=1;
                         delay_1ms(50);
                 
                 }
                 fade_3=128;
                 fade_4--;
                 
                 for(fade_1=0;fade_1<fade_2;fade_1++)
                 {
                         LED_G=1;
                         LED_B=0;
                         delay_1ms(50);
                 }
                 fade_1=0;
                 fade_2--;
         }
         fade_2=128;
         fade_4=127;

         while(fade_2!=0)
         {
                 for(fade_3=128;fade_3>fade_4;fade_3--)
                 {
                         LED_B=0;
                         LED_R=1;
                         delay_1ms(50);
                 }
                 fade_3=128;
                 fade_4--;
                 
                 for(fade_1=0;fade_1<fade_2;fade_1++)
                 {
                         LED_B=1;
                         LED_R=0;
                         delay_1ms(50);
                 }
                 fade_1=0;
                 fade_2--;                         
         }
 }
 */
 void color_welcome_women()  //想让哪个颜色亮就把它置0，另外的置1
  {
  	uchar fade;
  	for(fade=0;fade<3;fade++)
	{
		P0=0x00;      //
		delay_1ms(300);
		P0=0xff;      //
		delay_1ms(300);
	}
  }
 void color_welcome_men()  //想让哪个颜色亮就把它置0，另外的置1
  {

	P0=0xfd;	//11111101
	delay_1ms(150);
	P0=0xf7;	//11110111
	delay_1ms(150);
	P0=0xdf;	//11011111
	delay_1ms(150);
	P0=0x7f;	//01111111
	delay_1ms(150);

	P0=0xfe;	//11111110
	delay_1ms(150);
	P0=0xfb;	//11111011
	delay_1ms(150);
	P0=0xef;	//11101111
	delay_1ms(150);
	P0=0xbf;	//10111111
	delay_1ms(150);
	P0=0xff;

  }