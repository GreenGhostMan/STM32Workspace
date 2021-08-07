#include "stm32f10x.h"
unsigned int delay=0;
void delayMicros(unsigned int x);
uint32_t OntimePeriod=0,OfftimePeriod=0;
uint32_t ServoPeriod=100;
struct{
	unsigned systick:1;
	unsigned output_state:1;
}Flag;
int main(void)
{
	RCC->APB2ENR = 1<<4;
	GPIOC->CRL = 0XFFFF8833;
	GPIOC->ODR = 1<<3 | 1<<1 | 1;
	
	SysTick->LOAD = 720; // 1 us
	SysTick->CTRL = 1<<2 | 1<<1 | 1;
	
	while(1)
	{
		if(Flag.systick) // -----------------------------every 1 us
		{
			Flag.systick=0;
			if(++OntimePeriod==2000)//-------------------------------------------every 20 ms
			{
				OntimePeriod = 0;
				GPIOC->BSRR |=1;  // pc0 high
				Flag.output_state=1;
			}	// -----------------------------------------------------------------every 20 ms				
			if(Flag.output_state)
			{
				if(++OfftimePeriod==ServoPeriod) //---- 1ms from output_state
				{
					OfftimePeriod = 0;
					GPIOC->BSRR |= 1<<16;
					Flag.output_state=0;
				}
			}
		}//---------------------------------------------every 1 us
		
	}
}

void SysTick_Handler(void)
{
	if(SysTick->CTRL & SysTick_CTRL_COUNTFLAG)
	{
		SysTick->CTRL = ~ SysTick_CTRL_COUNTFLAG;
		if(delay)
			delay--;
		Flag.systick=1;
	}
}

void delayMillis(unsigned int x)
{
	delay = x;
	while(delay);
}
