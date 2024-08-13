#include "cm3.h"
#include "gpio.h"
#include "RCC.h"
volatile uint32_t msTime = 0;
void STK_Init() {
  STK->LOAD = RCC_GetSysClk()/1000 - 1;  // Set reload value for 1ms interval
  STK->CTRL.BITS.TICK_INT = 1;  // Enable SysTick interrupt
  STK->CTRL.BITS.CLK_SOURCE = 1;  // Set SysTick clock source to AHB
  STK->CTRL.BITS.ENABLE = 1;  // Enable SysTick timer
}

void SysTick_Handler()
{
	msTime++;
}

void Delay_ms(uint32_t time)
{
	uint32_t start = msTime;
	while(msTime - start < time);
	msTime = 0;
}