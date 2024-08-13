#include <stdint.h>
#include <stddef.h>
#include "base_adrr.h"

#define SPI1	((SPI_TypeDef*)SPI1_BASEADDR)
#define SPI2	((SPI_TypeDef*)SPI2_BASEADDR)
#define SPI3	((SPI_TypeDef*)SPI3_BASEADDR)

typedef struct{
    union
    {
        volatile uint32_t REG;
        struct 
        {
            volatile uint32_t CPHA          : 1;
            volatile uint32_t CPOL          : 1;
            volatile uint32_t MSTR          : 1;
            volatile uint32_t BR            : 3;
            volatile uint32_t SPE           : 1;
            volatile uint32_t LSBFIRST      : 1;
            volatile uint32_t SSI           : 1;
            volatile uint32_t SSM           : 1;
            volatile uint32_t RXONLY        : 1;
            volatile uint32_t DFF           : 1;
            volatile uint32_t CRCNEXT       : 1;
            volatile uint32_t CRCEN         : 1;
            volatile uint32_t BIDIOE        : 1;
            volatile uint32_t BIDIMODE      : 1;
            volatile uint32_t _reserved     : 16;
        }BITS;
    }CR1;

    union
    {
         volatile uint32_t REG;
        struct 
        {
            volatile uint32_t  RXDMAEN      : 1;
            volatile uint32_t  TXDMAEN      : 1;
            volatile uint32_t  SSOE         : 1;
            volatile uint32_t  _reserved    : 2;
            volatile uint32_t  ERRIE        : 1;
            volatile uint32_t  RXNEIE       : 1;
            volatile uint32_t  TXEIE        : 1;
            volatile uint32_t _reserved1    : 24;
        }BITS;
    }CR2;
    
    union
    {
         volatile uint32_t REG;
        struct 
        {
            volatile const uint32_t RXNE          : 1;
            volatile const uint32_t TXE           : 1;
            volatile const uint32_t CHSIDE        : 1;
            volatile const uint32_t UDR           : 1;
            volatile 			 uint32_t CRCERR        : 1;
            volatile const uint32_t MODF          : 1;
            volatile const uint32_t OVR           : 1;
            volatile const uint32_t BSY           : 1;
            volatile const uint32_t _reserved     : 24;
        }BITS;
    }SR;

    volatile uint32_t DR;
    volatile uint32_t CRCPR;
    const		 uint32_t RXCRCR;
    const		 uint32_t TXCRCR;

    union
    {
         volatile uint32_t REG;
        struct 
        {
            volatile uint32_t CHLEN         : 1;
            volatile uint32_t DATLEN        : 1;
            volatile uint32_t CKPOL         : 1;
            volatile uint32_t I2SSTD        : 2;
            volatile uint32_t _reserved     : 1;
            volatile uint32_t PCMSYNC       : 1;
            volatile uint32_t I2SCFG        : 2;
            volatile uint32_t I2SE          : 1;
            volatile uint32_t I2SMOD        : 1;
            volatile uint32_t _reserved1    : 20;
        }BITS;
    }I2SCFGR;
    
		union
    {
         volatile uint32_t REG;
        struct 
        {
			volatile uint32_t I2SDIV        : 8;
            volatile uint32_t ODD           : 1;
            volatile uint32_t MCKOE         : 1;
            volatile uint32_t _reserved     : 22;
        }BITS;
    }I2SPR;
} SPI_TypeDef;


typedef enum {
    SPI_TRANSFER_MODE_FULL_DUPLEX       = (0x00000000U),
    SPI_TRANSFER_MODE_HALF_DUPLEX_TX    = (uint32_t)((1 << 15) | (1 << 14)),
    SPI_TRANSFER_MODE_HALF_DUPLEX_RX    = (uint32_t)(1 << 14),
    SPI_TRANSFER_MODE_RX_ONLY           = (uint32_t)(1 << 10)
} SPI_TransferMode;

typedef enum {
    SPI_OPERATE_MODE_MASTER             = (uint32_t)((1 << 8) | (1 << 2)),
    SPI_OPERATE_MODE_SLAVE              = (0x00000000U)
} SPI_OperateMode;

typedef enum {
    SPI_CPHA_FIRST_TRANS      					= (0x00000000U),
    SPI_CPHA_SECOND_TRANS     					= (0x00000001U)
} SPI_ClockPhase;

typedef enum {
    SPI_CPOL_LOW       			 						= (0x00000000U),
    SPI_CPOL_HIGH       			 					= (uint32_t)(1 << 1)
} SPI_ClockPolarity;

typedef enum {
    SPI_BR_DIV2          			 					= (0x00000000U),
    SPI_BR_DIV4          			 					= (uint32_t)(1 << 3),
    SPI_BR_DIV8          			 					= (uint32_t)(1 << 4),
    SPI_BR_DIV16         			 					= (uint32_t)((1 << 4) | (1 << 3)),
    SPI_BR_DIV32         			 					= (uint32_t)(1 << 5),
    SPI_BR_DIV64         			 					= (uint32_t)((1 << 5) | (1 << 3)),
    SPI_BR_DIV128        			 					= (uint32_t)((1 << 5) | (1 << 4)),
    SPI_BR_DIV256        			 					= (uint32_t)((1 << 5) | (1 << 4) | (1 << 3))
} SPI_BaudRateDiv;

typedef enum {
    SPI_LSB_FIRST     									= (uint32_t)(1 << 7),
    SPI_MSB_FIRST     									= (0x00000000U)
} SPI_BitOrder;

typedef enum {
    SPI_NSS_SOFT        		   					= (uint32_t)(1 << 9),
    SPI_NSS_HARD_INPUT  		   					= (0x00000000U),
    SPI_NSS_HARD_OUTPUT 		   					= (uint32_t)(1 << 31)
} SPI_NSSMode;					
					
typedef enum {					
    SPI_DATAWIDTH_8BIT         					= (0x00000000U),
    SPI_DATAWIDTH_16BIT        					= ((uint32_t)(1 << 11))
} SPI_DataWidth;         					
										     
typedef enum{            
    SPI_DMA_RX_ENABLE	          			  = (0x00000001U),
    SPI_DMA_TX_ENABLE	          			  = (0x00000002U)
} SPI_DMA;                
										     
typedef enum{            
    SPI_INTERRUPT_ERROR_EN      			  = ((uint32_t)(1<<5)),
    SPI_INTERRUPT_RXNE_EN       			  = ((uint32_t)(1<<6)),
    SPI_INTERRUPT_TXE_EN        			  = ((uint32_t)(1<<7)),
} SPI_Interrupt;

typedef struct {
    SPI_TransferMode  Trans_Mode;
    SPI_OperateMode   Mode;
    SPI_ClockPhase    CPha;
    SPI_ClockPolarity CPol;
    SPI_BaudRateDiv   BRDiv;
    SPI_BitOrder      BitOrder;
    SPI_NSSMode       NSSMode;
    SPI_DataWidth     DataWidth;
	  SPI_DMA						DMA;
		SPI_Interrupt			Interrupt;
} SPIInit_TypeDef;


void SPI_Init(SPI_TypeDef* SPIx, SPIInit_TypeDef* SPIInit);
uint8_t SPI_Received8(SPI_TypeDef *SPIx);
uint16_t SPI_Received16(SPI_TypeDef *SPIx);
void SPI_Transmit8(SPI_TypeDef* SPIx, uint8_t Data);
void SPI_Transmit16(SPI_TypeDef* SPIx, uint8_t Data);
