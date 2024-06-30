#ifndef RCC_H_
#define RCC_H_

#include<common.h>

#define RCC_BASEADDR 0x40021000
#define RCC ((RCC_map*)RCC_BASEADDR)

typedef struct {
    volatile uint32_t CR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t APB1RSTR;
    volatile uint32_t AHBENR;
    union{
        volatile uint32_t REG;
        struct{
            volatile uint32_t AFIOEN    : 1;
            volatile uint32_t _reserved : 1;
            volatile uint32_t IOPAEN    : 1;
            volatile uint32_t IOPBEN    : 1;
            volatile uint32_t IOPCEN    : 1;
            volatile uint32_t IOPDEN    : 1;
            volatile uint32_t IOPEEN    : 1;
            volatile uint32_t IOPFEN    : 1;
            volatile uint32_t IOPGEN    : 1;
            volatile uint32_t ADC1EN    : 1;
            volatile uint32_t ADC2EN    : 1;
            volatile uint32_t TIM1EN    : 1;
            volatile uint32_t SPI1EN    : 1;
            volatile uint32_t TIM8EN    : 1;
            volatile uint32_t USART1EN  : 1;
            volatile uint32_t ADC3EN    : 1;
            volatile uint32_t _reserved : 3;
            volatile uint32_t TIM9EN    : 1;
            volatile uint32_t TIM10EN   : 1;
            volatile uint32_t TIM11EN   : 1;
            volatile uint32_t _reserved : 10;
        }BITS;
    } APB2ENR;
    volatile uint32_t APB1ENR;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
} RCC_map;

void RCC_GPIO_CLK_EN(uint32_t GPIO_BASEADDR);
#endif /* RCC_H_ */