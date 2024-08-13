#include "USART.h"
#include "RCC.h"
void USART_Init(USART_Typedef *USARTx, uint32_t BAUD_RATE){
    uint32_t fclk = 0;
    //Enable AFIO RCC
    RCC->APB2ENR.BITS.AFIOEN = 1;
    //Set pin to USART Mode
    if(USARTx == USART1)
    {
        RCC->APB2ENR.BITS.USART1EN = 1;
        fclk = RCC_GetAbp2Clk();
    }
    else if(USARTx == USART2)
    {
        RCC->APB1ENR.BITS.USART2_EN = 1;
        fclk = RCC_GetAbp1Clk();
    }
    else if(USARTx == USART3)
    {
        RCC->APB1ENR.BITS.USART3_EN = 1;
        fclk = RCC_GetAbp1Clk();
    }
    //Calculate the BAUDRATE
	  double USART_DIV = 1.0 * fclk / (BAUD_RATE << 4) ;
    USARTx->BRR.BITS.DIV_MANTISSA = (uint32_t)USART_DIV;
    USARTx->BRR.BITS.DIV_FRACTION = (uint32_t)((USART_DIV - (uint32_t)USART_DIV) * 16);
}

void USART_send(USART_Typedef *USARTx, unsigned char c)
{
				while(!USARTx->SR.BITS.TXE){;}
        USARTx->DR.REG = c;
}

void USART_str(USART_Typedef *USARTx, unsigned char *str)
{
	for(int i = 0; str[i] != '\0'; i++)
	{
		USART_send(USARTx, str[i]);
	}
}

unsigned char USART_receive(USART_Typedef *USARTx)
{
    while(!USARTx->SR.BITS.RXNE){;}
    return (char)USARTx->DR.REG;
}
