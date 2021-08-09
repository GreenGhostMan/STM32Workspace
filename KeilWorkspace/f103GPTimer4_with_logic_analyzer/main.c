#include "stm32f10x.h"

int main(void)
{
	RCC->APB2ENR |= 1<<4;
	GPIOC->CRL = 0XFFFFFFF3;
	RCC->APB1ENR |= 1<<2; // TIM4 CLOCK ENABLE
	TIM4->PSC = 7200; 
	TIM4->ARR = 10000; // 100us; if arr=1000 1 milli seconds;
	TIM4->CNT = 0;  // CLEAR COUNTER
	TIM4->CR1 |= // CEN COUTNER ENABLE
	TIM4->DIER |=1; // UIE UPDATE INTERRUPT ENABLE BIT
	NVIC_EnableIRQ(TIM4_IRQn);
	while("timer4")
	{
		
	}
}

void TIM4_IRQHandler(void)
{
	if(TIM4->SR & TIM_SR_UIF)
	{
		GPIOC->ODR ^= 1;
		TIM4->SR = ~ TIM_SR_UIF;
	}
}
