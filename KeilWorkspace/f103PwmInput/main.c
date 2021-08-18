#include "stm32f10x.h"
uint16_t period=0, width=0;
uint16_t frequency=0, rpm=0, ppr=1320;

int main(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;											// TIMER4 clock enable
	TIM4->PSC = 71;																					// 1 us
	TIM4->ARR = 65535;																			// TimerOverflow = ( 1us * ARR ) = 65.536 ms 
	
/*	
	TIM4->CCMR1 |= 2<<8 |																	  // CC2S ( CC2 channel is configured as input, IC2 is mapped on TI1 )
								 1;																				// CC1S ( CC1 channel is configured as input, IC1 is mapped on TI1 )
*/TIM4->CCMR1 |= TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC2S_1;		
			
	
/*	
	TIM4->SMCR |= 5<<4 |																		// TS ( trigger selection ->  5{filter timer input 1 TI1FP1} )
								4;																				// SMS ( slave mode selection -> 4{reset} ) 
*/TIM4->SMCR |= 5<<4 | TIM_SMCR_SMS_2;	
										
/*	
	TIM4->CCER |= 1<<4 |																		// CC2E ( capture enable )
								1<<5 | 																		// CC2P ( capture compare 2 output polarity -> active low [ inverse of CC1E ]
								1;																				// CC1E ( capture enable ) 
*/TIM4->CCER |= TIM_CCER_CC1E | TIM_CCER_CC2E | TIM_CCER_CC2P;
	
	TIM4->CR1 |= TIM_CR1_CEN;
	
/* IO */
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	GPIOB->CRL &= 0x00ffffff;
	GPIOB->CRL |= 0x88000000;																// PB6, BP7 input pull up
	GPIOB->ODR |= 1<<6 | 1<<7;															// pull up
	
	while(1)
	{
		period = TIM4->CCR1;
		width = TIM4->CCR2;
		frequency = (1e6)/period;
		rpm = (frequency/ppr)*60;
	}
}





/*
#include "stm32f10x.h"
uint16_t Period=0, width=0;
uint16_t frequency=0, rpm=0, ppr=1320;
int main(void)
{
	RCC->APB1ENR |= 1<<2; // TIMER4 CLOCK ENABLE
	TIM4->PSC=72; // t = 1us
	TIM4->ARR= 65535;
	TIM4->CCMR1 |= 2<<8 | 1;
	TIM4->SMCR  |= 5<<4 | 4; // Timer Reset Mode, 101 filter TI1P ( TIM4 CH1)
	TIM4->CCER  |= 1<<5 | 1<<4 | 1; // CC2P active, CC2E active, CC1E active
	TIM4->CR1   |= 1;  // CEN Counter Enable
	
	// GPIO
	RCC->APB2ENR |= 1<<3; // IOPBEN Clock Enable
	GPIOB->CRL    = 0x88ffffff; // PB6,PB7 input pullup
	GPIOB->ODR   |= 1<<7 | 1<<6; // pull up
	
	while(1)
	{
		Period = TIM4->CCR1;
		width  = TIM4->CCR2;
		frequency = (1e6)/Period;
		rpm = (frequency/ppr) * 60;
	}
}
*/
