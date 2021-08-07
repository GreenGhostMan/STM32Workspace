#include "stm32f10x.h"


int main(void)
{
	RCC->APB2ENR |= 1<<4; // IOPCEN GPIOC CLOCK ENABLE
	GPIOC->CRL = 0xffff8833; // PC0 PC1 OUTPUT PUSH PULL , PC2 PC3 INPUT
	GPIOC->ODR |= 1<<2 | 1<<3; // PC2, PC3 PULL UP
	
	while(1)
	{
		int idr = GPIOC->IDR & 0x000C;
	
	  if(idr == 0x4) { GPIOC->BSRR = 1; }
		if(idr == 0x8) { GPIOC->BSRR = 1<<16; }
			
		//GPIOC->ODR ^= 1<<1;
		for(int i=0;i<11111;i++);
	}
}
