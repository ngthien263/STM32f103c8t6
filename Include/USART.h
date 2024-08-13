#include "stdint.h"
#include "base_adrr.h"
#define USART1 						((USART_Typedef*)USART1_BASEADDR)
#define USART2 						((USART_Typedef*)USART2_BASEADDR)
#define USART3 						((USART_Typedef*)USART3_BASEADDR)
#define UART4  						((USART_Typedef*)UART4_BASEADDR)
#define UART5  						((USART_Typedef*)UART5_BASEADDR)

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
            volatile uint32_t PE       						 : 1;
            volatile uint32_t FE       						 : 1;
            volatile uint32_t NE       						 : 1;
            volatile uint32_t ORE      						 : 1;
            volatile uint32_t IDLE     						 : 1;
            volatile uint32_t RXNE     						 : 1;
            volatile uint32_t TC       						 : 1;
            volatile uint32_t TXE      						 : 1;
            volatile uint32_t LBD      						 : 1;
            volatile uint32_t CTS      						 : 1;
            volatile uint32_t _reserved						 : 22;
        } BITS;
    } SR;
		
    union{
        volatile uint32_t REG;
        struct{
            volatile uint32_t DR                   : 9;
            volatile uint32_t _reserved            : 23;
        }BITS;
    } DR;

    union{
        volatile uint32_t REG;
        struct{
            volatile uint32_t DIV_FRACTION         : 4;
            volatile uint32_t DIV_MANTISSA         : 12;
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

}USART_Typedef;

void USART_Init(USART_Typedef *USARTx, uint32_t BAUD_RATE);
void USART_send(USART_Typedef *USARTx, unsigned char c);
void USART_str(USART_Typedef *USARTx, unsigned char* str);
unsigned char USART_receive(USART_Typedef *USARTx);