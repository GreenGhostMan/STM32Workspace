#include "stm32f10x.h"
void delayMillis(unsigned int x);
int main(void)
{
	RCC->APB2ENR |= 1<<4; //IOPCEN GPIOC CLOCK ENABLE
	GPIOC->CRL = 0XFFFFFF33;
	
	while(1)
	{
		//GPIOC->ODR |= 1;
		//delayMillis(1000);
		//GPIOC->ODR &= 0;
		//delayMillis(1000);
		GPIOC->ODR = GPIOC->ODR ^ 0X00000003;
		delayMillis(1000);
	}
}
void delayMillis(unsigned int x){
	while(x--){
		for(int i=0;i<1111;i++);
	}
}
