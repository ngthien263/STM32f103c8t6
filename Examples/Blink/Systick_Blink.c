#include <stm32f103.h>
#include <cortex-m3.h>

// Structure to hold LED state
struct {
  unsigned char Blink;  // Blink state of the LED
} Led;

// Enumeration for button states
typedef enum {
  BUTTON_NONE,  // No button event
  BUTTON_DOWN,  // Button pressed
  BUTTON_UP     // Button released
} Button_state;

// Structure to hold button state and event
struct {
  unsigned char Logic;  /* Current logic state of the button */
  Button_state Event;   /* Current event state of the button */
} Button;

// SysTick interrupt handler
void Systick_Handler() {
  Int_Flags.SysTick.MsTick = 1;  // Set the millisecond tick flag
}

// Function to process base tasks
void BaseProcess() {
  if (Int_Flags.SysTick.MsTick) {
    Int_Flags.SysTick.MsTick = 0;  // Clear the millisecond tick flag
    static unsigned int count = 0;
    if (count++ > 10) {
      count = 0;  // Reset the count
      // Check if button logic state has changed
      if (Button.Logic != GPIOA->IDR.BITS.IDR5) {
        Button.Logic = GPIOA->IDR.BITS.IDR5;                    /* Update button logic state */
        Button.Event = Button.Logic ? BUTTON_DOWN : BUTTON_UP;  /* Update button event state */
      }
    }
    // Check if LED should blink
    if (Led.Blink) {
      if (count++ >= 1000) {
        count = 0;  // Reset the count
        GPIOA->ODR.BITS.ODR12 = !GPIOA->ODR.BITS.ODR12;  // Toggle the LED state
      }
    }
  }
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
    BaseProcess();  // Call base process function
    // Check if button event is BUTTON_DOWN
    if (Button.Event == BUTTON_DOWN) {
      Button.Event = BUTTON_NONE;  // Clear button event
      Led.Blink = !Led.Blink;  // Toggle LED blink state
    }
  }
}
