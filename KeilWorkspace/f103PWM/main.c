#include "stm32f10x.h"
#define osc 72e6
#define frequency 500
int main(void)
{
	RCC->APB2ENR |= 1<<2; // IOPAEN
	GPIOA->CRL = 0XFBFFFFFF; // PA6 ALTERNATE PUSH PULL
	
	RCC->APB1ENR |= 1<<1; // TIM3 CLOCK ENABLE
	TIM3->CNT = 0;
	TIM3->PSC=72;
	
	//TIM3->ARR = 2000;  // frequency 500, 2milli sec
	TIM3->ARR = (osc/TIM3->PSC) / frequency;
	
	TIM3->CCMR1 |= 6<<4; // MODE1 (110)
	TIM3->CCER |= 1;     // CC1E Enable ( pwm ch1, tim3 ch1 )
	TIM3->CCR1 = TIM3->ARR/2;   // duty cycle
	
	TIM3->CR1 |= 1; // timer counter enable
	while(1)
	{
	}
	
}

