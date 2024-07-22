#include <stm32f103.h>
#include <cortex-m3.h>

// Structure to hold button state and event
typedef struct {
  unsigned char state;
  unsigned char index;
} PWM_Typedef;

PWM_Typedef PWM = {0x03, 0};
// SysTick interrupt handler
void Systick_Handler() {
  if(PWM.index == 0)
  {
    GPIOA->ODR.BITS.ODR12 = PWM.state & (1<<0);
    STK->LOAD = 8000;
    PWM.index = 1;
  }
  else if(PWM.index == 1)
  {
    GPIOA->ODR.BITS.ODR12 = PWM.state & (1<<1);
    STK->LOAD = 16000;
    PWM.index = 2;
  }
  else if(PWM.index == 2)
  {
    GPIOA->ODR.BITS.ODR12 = PWM.state & (1<<2);
    STK->LOAD = 32000;
    PWM.index = 0;
  }
  STK->CTRL.BITS.ENABLE = 1;  // Enable SysTick timer
  STK->CTRL.BITS.ENABLE = 0;  // Enable SysTick timer
}

// Main function
void main() {
  RCC_GPIO_CLK_EN(GPIOA);  // Enable clock for GPIOA
  // Configure SysTick timer
  STK->LOAD = 8000;  // Set reload value for 1ms interval
  STK->CTRL.BITS.TICK_INT = 1;  // Enable SysTick interrupt
  STK->CTRL.BITS.CLK_SOURCE = 1;  // Set SysTick clock source to AHB
  STK->CTRL.BITS.ENABLE = 1;  // Enable SysTick timer

  while (1) {

  }
}
