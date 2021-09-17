#include "stm32f10x.h"
void delayMillis(unsigned int x);
int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	
	while(1)
	{
		
		// PC14
		GPIOC->BSRR |= 1<<14;
		delayMillis(1000);
		GPIOC->BSRR |= 1<<30;
	}
}
