#include "stm32f10x.h"
#define osc 72e6
#define frequency 500

int main(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	GPIOC->CRH&=0xFFFFFF00;    
	GPIOC->CRH|=0x000000BB; 
	GPIOC->CRL&=0x00FFFFFF;    
	GPIOC->CRL|=0xBB000000;   // PC6, PC7, PC8, PC9 ( PWM ) alternate function output push pull
	
	RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;
	TIM8->CNT = 0;
	TIM8->PSC= 0;
	TIM8->ARR = 7199;
	
	
	
	// motor A  CHANNEL 4 *******************************************************************************************************************
	RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;
	GPIOC->CRH&=0xFFF0FFFF;    
	GPIOC->CRH|=0x00030000;
	GPIOD->CRL&=0xFFFFF0FF;    
	GPIOD->CRL|=0x00000300;   
	GPIOC->ODR |= 0<<12; GPIOD->ODR |= 1<<2;
	
	TIM8->CCMR2|=6<<12;        //CH4
	TIM8->CCMR2|=1<<11;        //CH4
	TIM8->CCER|=1<<12;         //CH4
	TIM8->CCR4=TIM8->ARR/2;
	
	
	/*
	// motor B  CHANNEL 3 *******************************************************************************************************************
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	GPIOB->CRL &= 0xFF00FFFF;
	GPIOB->CRL |= 0x00330000; GPIOB->ODR |= 1<<4 | 0<<5;
	
	TIM8->CCMR2|=6<<4;         //CH3
	TIM8->CCMR2|=1<<3;         //CH3	  
	TIM8->CCER|=1<<8;          //CH3	 
	TIM8->CCR3=TIM8->ARR/2;
	*/
	
	/*
	// motor C  CHANNEL 2 *******************************************************************************************************************
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	GPIOC->CRL&=0x0000FFFF;    
	GPIOC->CRL|=0xB0330000;    // PC7 ALTERNATE FUNCTION OUTPUT PUSH PULL 50MHz, PC4 PC5 GENERAL OUTPUT 50MHz
	
	GPIOC->ODR |= 1<<4 | 0<<5 ; // pwm- pc7 ( timer 8 channel 2)
	
	TIM8->CCMR1|=6<<12;        //CH2 OUTPUT COMPARE 2 MODE
	TIM8->CCMR1|=1<<11;        //CH2 OC2PE pre load enable 
	TIM8->CCER|=1<<4;          //CH2 CC2E	   
	TIM8->CCR2=TIM8->ARR/2;
	*/
	/*
	// motor D  CHANNEL 1 *******************************************************************************************************************
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	GPIOB->CRL &= 0xFFFFFF00;
	GPIOB->CRL |= 0x00000033; GPIOB->ODR |= 1<<1 | 0;
	
	TIM8->CCMR1|=6<<4;         //CH1
	TIM8->CCMR1|=1<<3;         //CH1	 
	TIM8->CCER|=1<<0;          //CH1	
	TIM8->CCR1 =TIM8->ARR/2;
	*/
	// end Motor  *******************************************************************************************************************
	
	TIM8->BDTR |= 1<<15;
	TIM8->CR1|=0x01;  
	
	while(1)
	{
	}
	
}


/*
int main(void)
{
	RCC->APB2ENR |= 1<<2; // IOPAEN
	GPIOA->CRL = 0XFBFFFFFF; // PA6 ALTERNATE PUSH PULL
	
	RCC->APB1ENR |= 1<<1; // TIM3 CLOCK ENABLE
	TIM3->CNT = 0;
	TIM3->PSC=71;
	
	TIM3->ARR = 1000;  
	//TIM3->ARR = (osc/TIM3->PSC) / frequency;
	
	TIM3->CCMR1 |= 6<<4; // OC1M
	TIM3->CCER |= 1;     // CC1E 
	TIM3->CCR1 = TIM3->ARR/2;   // duty cycle
	
	TIM3->CR1 |= 1; // timer counter enable
	while(1)
	{
	}
	
}
*/
