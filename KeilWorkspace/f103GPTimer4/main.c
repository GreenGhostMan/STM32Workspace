#include "stm32f10x.h"

int main(void)
{
	RCC->APB1ENR |=1<<2; // timer 4 clock enable
	TIM4->PSC = 71;
	TIM4->ARR = 100; // 100us
	TIM4->CNT=0;     // count flag 0
	TIM4->CR1 |= 1; // CEN enable
	TIM4->DIER |=1; // update interrupt enable
	NVIC_EnableIRQ(TIM4_IRQn);
	while(1)
	{
		
	}
}

void TIM4_IRQHandler(void)
{
	if(TIM4->SR & TIM_SR_UIF)
	{
		TIM4->SR &= ~ TIM_SR_UIF;
	}
}
