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

void generate_NMI_interrupt()
{
	SCB_Type *pSCB;
	pSCB = SCB;
	pSCB->ICSR |= SCB_ICSR_NMIPENDSET_Msk;
	
}

int main(void)
{
	__set_FAULTMASK(1);
	
	//void (*jump_address) (void) = (void*) 0x00000002;
	//jump_address();
	
	generate_NMI_interrupt();
	generate_interrupt();
  while (1)
  {
		
  }
  
}
