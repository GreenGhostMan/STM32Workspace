#include "stm32f10x.h"
uint16_t Encoder_value=0;
int main(void)
{
	RCC->APB2ENR |= 1<<3; // GPIOB CLOCK Enable
	GPIOB->CRL = 0x88ffffff;	// input pull up , if ec11 encoder (they include resistors) , gpio can use float
	//GPIOB->CRL = 0x44ffffff;
	
	RCC->APB1ENR |= 1<<2; // timer 4 clock
	TIM4->PSC = 0;
	TIM4->ARR = 65535;
	
	TIM4->CCMR1 |= 1<<8 | // cc2 channel
								 1;     // cc1 channel
	TIM4->SMCR |= 3;			// timer smcr encoder mode
	TIM4->CR1 |= 1;				// timer count enable CEN
	while(1)
	{
		Encoder_value = TIM4->CNT;
	}
}
