#include <stdint.h>
#include "gpio.h"
#include "RCC.h"
#include "cm3.h"
#include "TIM.h"
#include "USART.h"
#include "SPI.h"
#include "ST7735.h"
uint32_t tesst;
void SystemInit()
{
	
}

int main(void)
{
	STK_Init();
	Delay_ms(50);
	SPI_Init(SPI1, NULL);
	while(1)
	{

	}
	return 0;
}
