#include "SPI.h"
#include "gpio.h"
#include "RCC.h"


void SPI_Init(SPI_TypeDef* SPIx, SPIInit_TypeDef* SPIInit)
{
    // Initialize SPI
    RCC->APB2ENR.BITS.AFIOEN = 1;
    if (SPIx == SPI1)
    {
        RCC->APB2ENR.BITS.SPI1EN = 1;
        RCC->APB2ENR.BITS.IOPAEN = 1;
        GPIO_SetMode(GPIOA, 4, GPIO_OUTPUT_MODE_50M_PP);
        GPIO_SetMode(GPIOA, 5, GPIO_ALT_MODE_50M_PP);
        GPIO_SetMode(GPIOA, 6, GPIO_INPUT_MODE_PuPd);
        GPIO_SetMode(GPIOA, 7, GPIO_ALT_MODE_50M_PP);
    }
    else if (SPIx == SPI2)
    {
        RCC->APB1ENR.BITS.SPI2_EN = 1;
        RCC->APB2ENR.BITS.IOPBEN = 1;
        GPIO_SetMode(GPIOB, 12, GPIO_OUTPUT_MODE_50M_PP);
        GPIO_SetMode(GPIOB, 13, GPIO_ALT_MODE_50M_PP);
        GPIO_SetMode(GPIOB, 14, GPIO_INPUT_MODE_PuPd);
        GPIO_SetMode(GPIOB, 15, GPIO_ALT_MODE_50M_PP);
    }
    
    // Default configuration 
    if (!SPIInit)
    {
        static SPIInit_TypeDef defaultSPIInit = {
            .Trans_Mode = SPI_FULL_DUPLEX,
            .Mode = SPI_MASTER,
            .CPha = SPI_FIRST_TRANS,
            .CPol = SPI_CLOCK_TO_0,
            .BRDiv = SPI_BR_DIV16,
            .BitOrder = SPI_MSB_FIRST,
            .NSSMode = SPI_NSS_SOFT,
            .DataWidth = SPI_DATAWIDTH_8BIT
        };
        SPIInit = &defaultSPIInit;
    }

    // Configure SPI
    SPIx->CR1.REG = SPIInit->Trans_Mode | SPIInit->Mode | SPIInit->CPha | SPIInit->CPol | SPIInit->BRDiv | SPIInit->BitOrder | SPIInit->NSSMode | SPIInit->DataWidth;
    
    // Enable SPI
    SPIx->CR1.BITS.SPE = 1;
}

void SPI_send(SPI_TypeDef* SPIx, unsigned char c)
{
	SPIx->DR = c;
	while(!SPIx->SR.BITS.TXE);
}

void SPI_str(SPI_TypeDef* SPIx, unsigned char* str)
{
	for(unsigned char i = 0; str[i] != '\0'; i++)
	{
		SPIx->DR = str[i];
		while(!SPIx->SR.BITS.TXE);
	}
}


