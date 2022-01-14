#include "stm32f10x.h"
//void delayMillis(unsigned int x);
#include "stdio.h"

int _write(int file, char *ptr, int len)
{
	int DataIdx;
	for (DataIdx = 0; DataIdx < len; DataIdx++)
	{
		ITM_SendChar(*ptr++);
	}
	return len;
}
int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	printf("Hello testing\n\r");

	
	while(1)
	{
		printf("Hello testing\n\r");
		// PC14
		GPIOC->BSRR |= 1<<14;
		//delayMillis(1000);
		GPIOC->BSRR |= 1<<30;
	}
}
