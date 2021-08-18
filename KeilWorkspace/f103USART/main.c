/**************************** USART TRANSMIT ***************************/

#include "stm32f10x.h"
const char string[]="rom robotics\r\n";
void user_printf(char *ptr);
int main(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // port A clock
	GPIOA->CRL =0x4444bb44; // alternate push pull
	
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	USART2->BRR = 36e6/9600; // baud register
	USART2->CR1 |= 1<<13 |   // uart enable
								 1<<3  |   // transmit enable
								 1<<2;     // receive enable
	
	while(1)
	{

			for(char x=0;x<sizeof(string);x++)
			{
				USART2->DR = string[x];
				while((USART2->SR & USART_SR_TC)==0);
				USART2->SR &= ~ USART_SR_TC;
			}
			user_printf("myanmar\r\n");
	}
}
void user_printf(char *ptr)
{
	while(*ptr)
	{
		USART2->DR = *ptr++;
		while( (USART2->SR & USART_SR_TC)==0);
		USART2->SR &= ~ USART_SR_TC;
	}
}
