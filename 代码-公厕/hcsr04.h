#ifndef __HCSR04_H__
#define _HCSR04_H__
sbit RX=P1^5;//echo
sbit TX=P1^6;//trig
void init_hc();
float Conut(void);
void StartModule();
float hcsr04_once();//≤‚¡ø“ª¥Œ


#endif