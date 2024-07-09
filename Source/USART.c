#include "GPIO.h"
#include "USART.h"
#include "RCC.h"

void USART_Init(volatile USART_map *USARTx, uint32_t BAUD_RATE, unsigned char word_length,  stopBits_Typedef stopBits){
    //Set pin to USART Mode
    if(USARTx == USART1)
    {
        GPIO_SetMode(GPIOA, 9,  GPIO_ALT_MODE_50M_OD);
        GPIO_SetMode(GPIOA, 10, GPIO_ALT_MODE_50M_OD);
        RCC->APB2ENR.BITS.USART1EN = 1;
    }
    else if(USARTx == USART2)
    {
        GPIO_SetMode(GPIOA, 2, GPIO_ALT_MODE_50M_OD);
        GPIO_SetMode(GPIOA, 3, GPIO_ALT_MODE_50M_OD);
    }
    else if(USARTx == USART3)
    {
        GPIO_SetMode(GPIOB, 10, GPIO_ALT_MODE_50M_OD);
        GPIO_SetMode(GPIOB, 11, GPIO_ALT_MODE_50M_OD);
    }
	
    //Calculate the BAUDRATE
		int fck = 8000000;
    double USART_DIV = 1.0 * BAUD_RATE * 16 / fck;
    USARTx->BRR.BITS.DIV_MANTISSA = (uint32_t)USART_DIV;
    USARTx->BRR.BITS.DIV_FRACTION = (uint32_t)(USART_DIV - (uint32_t)USART_DIV * 16);

    USARTx->CR1.BITS.M = word_length;
    USARTx->CR2.BITS.STOP |= (1<<stopBits);
}

void USART_TX(volatile USART_map*USARTx, char *str)
{
    for(unsigned char i = 0; str[i] != '\0'; i++)
    {
        USARTx->DR.REG = str[i];
    }
}