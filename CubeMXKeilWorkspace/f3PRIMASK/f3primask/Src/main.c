#include "stm32f3xx.h"
//#include "main.h"

void WWDG_IRQHandler(void)
{
	for(int i=0;i<500;i++);
}

void generate_interrupt()
{
	NVIC_EnableIRQ(WWDG_IRQn);
	NVIC_SetPendingIRQ(WWDG_IRQn);
}


int main(void)
{
	__set_PRIMASK(1);
	generate_interrupt();
  while (1)
  {
		
  }
  
}
