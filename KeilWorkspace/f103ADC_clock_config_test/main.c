#include "stm32f10x.h"
void delayMillis(unsigned int x);
int main(void)
{
	RCC->APB2ENR |= 1<<4; //IOPCEN GPIOC CLOCK ENABLE
	GPIOC->CRL = 0XFFFFFF33;
	
	//RCC->APB2ENR |= 1<<4;
	GPIOC->CRH |= 0xf33fffff;
	
	while(1)
	{
	
		GPIOC->ODR = GPIOC->ODR ^ 0X00000003;
		delayMillis(1000);
	}
}
void delayMillis(unsigned int x){
	while(x--){
		for(int i=0;i<1111;i++);
	}
}
