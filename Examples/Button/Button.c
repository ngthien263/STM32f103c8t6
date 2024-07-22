/* Example Program to Read Button State and Toggle an LED
   Steps:
    1. Include necessary header files.
    2. Enable clock for GPIOA.
    3. Configure GPIOA pin as input with pull-up(pull-down) resistor.
    4. Set GPIOA pin mode to input with pull-up/pull-down.
    5. Read the state of GPIOA pin.
 */
#include <stm32f103.h>

int main(int argc, char *argv[]) {
    // Enable clock for GPIOA
    RCC_GPIO_CLK_EN(GPIOA);

    // Set GPIOA pin 12 with a pull-up resistor
    GPIO_SetPin(GPIOA, 12);

    // Set GPIOA pin 12 as input with pull-up/pull-down mode
    GPIO_SetMode(GPIOA, 12, GPIO_INPUT_MODE_PuPd);

    while (1) {
        // Read the state of GPIOA pin 12
        unsigned char buttonState = GPIOA->IDR.BITS.IDR12;

        // If the button is pressed (assuming active low)
        if (!buttonState) {
            // Toggle the state of GPIOA pin 12
            GPIO_TogglePin(GPIOA, 12);
            // Wait until the button is released (debounce)
            while (!buttonState);
        }
    }

    return 0; 
}
