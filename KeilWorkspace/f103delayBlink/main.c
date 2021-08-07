#include "stm32f10x.h"
unsigned int delay=0;
void delayMillis(unsigned int x);

int main(void)
{
	RCC->APB2ENR |= 1<<4;  
	GPIOC->CRL = 0XFFFF8833;
	GPIOC->ODR |= 1<<2 | 1<<3; // PC2 PC3 PULL UP
	
	SysTick->LOAD = 72000; // 1000 us
	SysTick->CTRL = 1<<2 | 1<<1 | 1;
	
	while(1)
	{
		GPIOC->BSRR |= 1;
		delayMillis(1000);
		GPIOC->BSRR |= 1<<16;
		delayMillis(1000);
		
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
