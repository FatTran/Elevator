#include<REGX52.H>
#include<stdio.h>
void delay_ms(unsigned int value){
	while(value > 0)
	{
		TMOD = 0x01;
		TH0 = 0xFC;
		TL0 = 0x18;
		TR0 = 1;
		while(!TF0);
		TF0 = 0;
		TR0 = 0;
		value--;
	}
}