#include <stdio.h>
#include <RCC.h>
#include <GPIO.h>
//Blink LED in PINC13
int main() {
    RCC->APB2ENR |= (1<<IOPCEN);
    GPIO_Init(GPIOC, PINC13, GPIO_OUTPUT_MODE_10M_PP);
    while (1)
    {
        
    }
    
    return 0;
}