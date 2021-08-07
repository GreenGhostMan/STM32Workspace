#include "stm32f10x.h"
unsigned int delay=0;
void delayMillis(unsigned int x);

int main(void)
{
	SysTick->LOAD = 72000; // 1000 us
	SysTick->CTRL = 1<<2 | 1<<1 | 1;
	
	while(1)
	{
		int a=9;
		delayMillis(1000);
		int b=10;
		int c = a+b;
	}
}

void SysTick_Handler(void)
{
	if(SysTick->CTRL & SysTick_CTRL_COUNTFLAG)
	{
		SysTick->CTRL = ~ SysTick_CTRL_COUNTFLAG;
		if(delay)
			delay--;
		
	}
}

void delayMillis(unsigned int x)
{
	delay = x;
	while(delay);
}
