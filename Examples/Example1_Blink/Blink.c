/*Example Program to  Toggle an LED
    Steps:
        Enable clock for GPIO
        Set output mode for GPIOA pin
        Continuously toggle the state of GPIOA pin
 */
#include <stm32f103.h>

int main(int argc, char *argv[]) {
    // Enable clock for GPIOA
    RCC_GPIO_CLK_EN(GPIOA);

    // Set mode for GPIOA pin 12 to output mode, 10MHz speed, open-drain
    GPIO_SetMode(GPIOA, 12, GPIO_OUTPUT_MODE_10M_OD);

    while (1)
    {
        // Toggle the state of GPIOA pin 12
        GPIO_TogglePin(GPIOA, 12);
    }

    return 0;
}
