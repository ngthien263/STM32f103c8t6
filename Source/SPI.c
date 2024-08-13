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
            .Trans_Mode = SPI_TRANSFER_MODE_FULL_DUPLEX,
            .Mode 			= SPI_OPERATE_MODE_MASTER,
            .CPha 			= SPI_CPHA_FIRST_TRANS,
            .CPol 			= SPI_CPOL_LOW,
            .BRDiv 			= SPI_BR_DIV2,
            .BitOrder		= SPI_LSB_FIRST,
            .NSSMode 		= SPI_NSS_SOFT,
            .DataWidth  = SPI_DATAWIDTH_16BIT  ,
						.DMA        = 0,
						.Interrupt  = 0,
        };
        SPIInit = &defaultSPIInit;
    }

    // Configure SPI
    SPIx->CR1.REG = SPIInit->Trans_Mode | 
										SPIInit->Mode       | 
										SPIInit->CPha       | 
										SPIInit->CPol       | 
										SPIInit->BRDiv      | 
										SPIInit->BitOrder   | 
										SPIInit->NSSMode    | 	
										SPIInit->DataWidth;
    if(SPIInit->NSSMode == SPI_NSS_HARD_OUTPUT)
			SPIx->CR2.BITS.SSOE = 1;
		SPIx->CR2.REG = SPIInit->DMA | SPIInit->Interrupt;
    // Enable SPI
    SPIx->CR1.BITS.SPE = 1;
}

uint8_t SPI_Received8(SPI_TypeDef *SPIx)
{
	while(SPIx->SR.BITS.RXNE);
	return (uint8_t)SPIx->DR;
}

uint16_t SPI_Received16(SPI_TypeDef *SPIx)
{
	while(SPIx->SR.BITS.RXNE);
	return SPIx->DR;
}

void SPI_Transmit8(SPI_TypeDef* SPIx, uint8_t Data)
{
	*(uint8_t*)SPIx->DR = Data;
	while(!SPIx->SR.BITS.TXE);
}

void SPI_Transmit16(SPI_TypeDef* SPIx, uint8_t Data)
{
	SPIx->DR = Data;
	while(SPIx->SR.BITS.TXE);
}

