#include "common.h"

#define USART1_BASEADDR (ABP2_BASEADDR | 0x3800)
#define USART2_BASEADDR (ABP1_BASEADDR | 0x4400)
#define USART3_BASEADDR (ABP1_BASEADDR | 0x4800)
#define UART4_BASEADDR  (ABP1_BASEADDR | 0x4800)
#define UART5_BASEADDR  (ABP1_BASEADDR | 0x5000)

#define USART1 ((USART_map*)USART1_BASEADDR)
#define USART2 ((USART_map*)USART2_BASEADDR)
#define USART3 ((USART_map*)USART3_BASEADDR)
#define UART4  ((USART_map*)UART4_BASEADDR)
#define UART5  ((USART_map*)UART5_BASEADDR)

typedef enum {
    STOP_BITS_1,
    STOP_BITS_0_5,
    STOP_BITS_2,
    STOP_BITS_1_5
} stopBits_Typedef;

typedef struct 
{
    union 
    {
        volatile uint32_t REG;
        struct
        {
            volatile uint32_t PE;
            volatile uint32_t FE;
            volatile uint32_t NE;
            volatile uint32_t ORE;
            volatile uint32_t IDLE;
            volatile uint32_t RXNE;
            volatile uint32_t TC;
            volatile uint32_t TXE;
            volatile uint32_t LBD;
            volatile uint32_t CTS;
            volatile uint32_t _reserved;
        }BITS;
    } SR;
    
    union{
        volatile uint32_t REG;
        struct{
            volatile uint32_t DR                    : 9;
            volatile uint32_t _reserved            : 23;
        }BITS;
    } DR;

    union{
        volatile uint32_t REG;
        struct{
            volatile uint32_t DIV_FRACTION         : 3;
            volatile uint32_t DIV_MANTISSA         : 13;
            volatile uint32_t _reserved            : 16;
        } BITS;
    } BRR;

    union{
        volatile uint32_t REG;
        struct{         
            volatile uint32_t SBK                  : 1;
            volatile uint32_t RWU                  : 1;
            volatile uint32_t RE                   : 1;
            volatile uint32_t TE                   : 1;
            volatile uint32_t IDLEIE               : 1;
            volatile uint32_t RXNEIE               : 1;
            volatile uint32_t TCIE                 : 1;
            volatile uint32_t PEIE                 : 1;
            volatile uint32_t PS                   : 1;
            volatile uint32_t PCE                  : 1;
            volatile uint32_t WAKE                 : 1;
            volatile uint32_t M                    : 1;
            volatile uint32_t UE                   : 1;
            volatile uint32_t _reserved            : 18;
        } BITS;
    } CR1;
    union{
        volatile uint32_t REG;
        struct{         
            volatile uint32_t ADD0                  : 4;
            volatile uint32_t _reserved1            : 1;
            volatile uint32_t LBDL                  : 1;
            volatile uint32_t LBDIE                 : 1;
            volatile uint32_t _reserved2            : 1;
            volatile uint32_t LBCL                  : 1;
            volatile uint32_t CPHA                  : 1;
            volatile uint32_t CPOL                  : 1;
            volatile uint32_t CLKEN                 : 1;
            volatile uint32_t STOP                  : 2;
            volatile uint32_t LINEN                 : 1;
            volatile uint32_t _reserved3            : 16;
        } BITS;
    } CR2;
    union{
        volatile uint32_t REG;
        struct{         
            volatile uint32_t EIE                   : 1;
            volatile uint32_t IREN                  : 1;
            volatile uint32_t IRLP                  : 1;
            volatile uint32_t HDSEL                 : 1;
            volatile uint32_t NACK                  : 1;
            volatile uint32_t SCEN                  : 1;
            volatile uint32_t DMAR                  : 1;
            volatile uint32_t DMAT                  : 1;
            volatile uint32_t RTSE                  : 1;
            volatile uint32_t CTSE                  : 1;
            volatile uint32_t CTSIE                 : 1;
            volatile uint32_t _reserved             : 21;
        } BITS;
    } CR3;

    union{
        volatile uint32_t REG;
        struct{         
            volatile uint32_t PSC                   : 8;
            volatile uint32_t GT                    : 8;
            volatile uint32_t _reserved             : 16;
        } BITS;
    } USART_GTPR;

}USART_map;

void USART_Init(volatile USART_map*USARTx, uint32_t BAUD_RATE, unsigned char word_length,  stopBits_Typedef stopBits);