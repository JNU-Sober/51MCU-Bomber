#include <STC89C5xRC.H>
#include "Delay.h"
#include "LCD1602.h"

unsigned int MetrixKey()
{
	unsigned int k=10;
	P1=0xFF;
	P13=0;
	if (P15==0){Delay(20);while(P15==0);Delay(20);k=9;}
	if (P16==0){Delay(20);while(P16==0);Delay(20);k=5;}
	if (P17==0){Delay(20);while(P17==0);Delay(20);k=1;}
	
	P1=0xFF;
	P12=0;
	if (P15==0){Delay(20);while(P15==0);Delay(20);k=0;}
	if (P16==0){Delay(20);while(P16==0);Delay(20);k=6;}
	if (P17==0){Delay(20);while(P17==0);Delay(20);k=2;}
	
	P1=0xFF;
	P11=0;
	if (P15==0){Delay(20);while(P15==0);Delay(20);k=11;}
	if (P16==0){Delay(20);while(P16==0);Delay(20);k=7;}
	if (P17==0){Delay(20);while(P17==0);Delay(20);k=3;}
	
	P1=0xFF;
	P10=0;
	if (P15==0){Delay(20);while(P15==0);Delay(20);k=12;}
	if (P16==0){Delay(20);while(P16==0);Delay(20);k=8;}
	if (P17==0){Delay(20);while(P17==0);Delay(20);k=4;}
	
	return k;
}