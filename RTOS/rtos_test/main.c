#include "stm32f10x.h"
#include "stdint.h"

#include "FreeRTOS.h"
#include "task.h"
//#include "timers.h"
#define TRACE_DEBUG

void user_printf(char *ptr);
void vTask1( void *pvParameters );
void vTask2( void *pvParameters );
extern void SystemCoreClockUpdate (void);

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	
	xTaskCreate(	vTask1, "Task 1", 240, NULL, 1, NULL );
	xTaskCreate( vTask2, "Task 2", 240, NULL, 1, NULL);
	
	vTaskStartScheduler();
	
	while(1)
	{
	}
	
}

void vTask1( void *pvParameters )
{
	volatile unsigned long ul;
	
	for(;;)
	{
		user_printf("Task 1 is running.\n");
		for(ul =0; ul < 10000; ul++);
	}
}

void vTask2( void *pvParameters )
{
	volatile unsigned long ul;
	
	for(;;)
	{
		user_printf("Task 2 is running.\n");
		for(ul =0; ul < 10000; ul++);
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

