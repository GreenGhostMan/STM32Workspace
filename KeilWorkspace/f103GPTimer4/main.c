#include "stm32f10x.h"

int main(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM6EN; // timer 4 clock enable
	TIM6->PSC = 71;
	TIM6->ARR = 50000; //  50 ms
	TIM6->CNT=0;     // count flag 0
	TIM6->CR1 |= 1; // CEN enable
	TIM6->DIER |=1; // update interrupt enable
	NVIC_EnableIRQ(TIM6_IRQn);
	

	while(1)
	{
		
	}
}

void TIM6_IRQHandler(void)
{
	if(TIM6->SR & TIM_SR_UIF)
	{
		TIM6->SR &= ~ TIM_SR_UIF;
	}
}
