#include "stm32f10x.h"

#define osc 72e6
#define frequency 500

uint16_t Encoder_value=0;

int main(void)
{
	/*** PWM ***/
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
	
	TIM3->DIER |= 1<<9;		// TIM3 DMA ENABLE
	
	TIM3->CR1 |= 1; // timer counter enable
	/*** END PWM ***/
	
	/**************** encoder **********************/
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
	/**************** end encoder **********************/
	
	/************************************************************DMA********************************************************/
	RCC->AHBENR |= 1; // DMA1 Channel clock enable
	DMA1_Channel6->CPAR = (uint32_t) &TIM3->CCR1;
	DMA1_Channel6->CMAR = (uint32_t) &Encoder_value;
	DMA1_Channel6->CNDTR = 1;
	DMA1_Channel6->CCR |= 0<<14 | // memory to memory
												2<<12 | // high
												1<<10 | // memory size
												1<<8  | // peripheral size
												0<<7  | // memory increment
												0<<6 	| // disable
												1<<5	| // circular enable
												1<<4	| // data transfer direction ( read from memory )
												0<<3	| // disable transfer err interrupt
												0<<2	| // half disable
												0<<1	| // complete disable
												1; 			// channel Enable
	//TIM3->DIER |= 1<<9;		// TIM3 DMA ENABLE
	
	while(1)
	{
		Encoder_value = TIM3->CNT;
		TIM3->CCR1 = Encoder_value;
	}
	
}

