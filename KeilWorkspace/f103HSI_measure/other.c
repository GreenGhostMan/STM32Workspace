#include <stdint.h>
#define RCC_BASE_ADDR			0x40021000UL
#define GPIOA_BASE_ADDR		0x40010800UL
int main(void)
{
	uint32_t *pRCC_CFGR = (uint32_t*) ( RCC_BASE_ADDR+ 0x04 );
	*pRCC_CFGR &= (0<<0) | (0<<1);

	uint32_t *pRCC_AHB2ENR = (uint32_t*)( RCC_BASE_ADDR+ 0x18 );
	*pRCC_AHB2ENR |= (1<<2);

	uint32_t *pGPIO_CRH = (uint32_t*) (GPIOA_BASE_ADDR +04);
	*pGPIO_CRH &= ~(0xb<<0);
	*pGPIO_CRH |= (0xB<<0);

	//uint32_t *pGPIO_AFRH = (uint32*t) (GPIOA_BASE_ADDR+0x24);
	//*pGPIO_AFRH &= ~(0xF << 0);
	
	
	*pRCC_CFGR &= ~(5<<24); // 5-HSI, 6-HSE, 4-SYSCLK
	*pRCC_CFGR |= (5<<24);

	for(;;);
}
