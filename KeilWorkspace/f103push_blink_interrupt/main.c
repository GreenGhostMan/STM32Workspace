#include "stm32f10x.h"


int main(void)
{
	RCC->APB2ENR |= 1<<4; // IOPCEN GPIOC CLOCK ENABLE
	GPIOC->CRL = 0xffff8833; // PC0 PC1 OUTPUT PUSH PULL , PC2 PC3 INPUT
	GPIOC->ODR |= 1<<2 | 1<<3; // PC2, PC3 PULL UP
	
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	AFIO->EXTICR[0] |= ( 0x2<<8 ) | (0x2<<12);
	
	EXTI->IMR |= (1<<2) | (1<<3);
	EXTI->FTSR |= (1<<2) | (1<<3);
	NVIC_EnableIRQ(EXTI2_IRQn);
	NVIC_EnableIRQ(EXTI3_IRQn);
	
	while(1)
	{
		//int idr = GPIOC->IDR & 0x000C;
	
	  //if(idr == 0x4) { GPIOC->BSRR = 1; }
		//if(idr == 0x8) { GPIOC->BSRR = 1<<16; }
		//GPIOC->BSRR |= 1;
		//GPIOC->BSRR |= 1<<16;
		//GPIOC->ODR ^= 1<<1;
		//for(int i=0;i<11111;i++);
	}
}

// lower btn
void EXTI2_IRQHandler(void)
{
	GPIOC->BSRR |= 1;
	EXTI->PR |= ( 1<<2 );
}

// upper btn
void EXTI3_IRQHandler(void) 
{
	GPIOC->BSRR |= 1<<16;
	EXTI->PR |= ( 1<<3 );
}


