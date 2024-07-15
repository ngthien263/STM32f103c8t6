#ifndef RCC_H_
#define RCC_H_

#include<stm32f103.h>
#include "GPIO.h"
#define RCC_BASEADDR 0x40021000


typedef struct {
    union{
        volatile uint32_t REG;
        struct{
            volatile uint32_t HSION       : 1;
            volatile uint32_t HSIRDY      : 1;
            volatile uint32_t _reserved1  : 1;
            volatile uint32_t HSITRIM     : 5;
            volatile uint32_t HSICAL      : 8;
            volatile uint32_t HSEON       : 1;
            volatile uint32_t HSERDY      : 1;
            volatile uint32_t HSEBYP      : 1;
            volatile uint32_t CSSON       : 1;
            volatile uint32_t _reserved2  : 4;
            volatile uint32_t PLLON       : 1;
            volatile uint32_t PLLRDY      : 1;
            volatile uint32_t _reserved3  : 6;
        }BITS; 
    } CR; 
    union{ 
        volatile uint32_t REG; 
        struct{ 
            volatile uint32_t SW          : 2;
            volatile uint32_t SWS         : 2;
            volatile uint32_t HPRE        : 4;
            volatile uint32_t PPRE1       : 3;
            volatile uint32_t PPRE2       : 3;
            volatile uint32_t ADCPRE      : 2;
            volatile uint32_t PLLSRC      : 1;
            volatile uint32_t PLLXTPRE    : 1;
            volatile uint32_t PLLMUL      : 4;
            volatile uint32_t USBPRE      : 1;
            volatile uint32_t _reserved1  : 1;
            volatile uint32_t MCO         : 3; 
            volatile uint32_t _reserved2  : 5;
        }BITS;
    } CFGR;
    union{ 
        volatile uint32_t REG; 
        struct{  
            volatile uint32_t LSI_RDYF     : 1;
            volatile uint32_t LSE_RDYF     : 1;
            volatile uint32_t HSI_RDYF     : 1;
            volatile uint32_t HSE_RDYF     : 1;
            volatile uint32_t PLL_RDYF     : 1;
            volatile uint32_t PLL2_RDYF    : 1;
            volatile uint32_t PLL3_RDYF    : 1;
            volatile uint32_t CSSF         : 1;
            volatile uint32_t LSI_RDYIE    : 1;
            volatile uint32_t LSE_RDYIE    : 1;
            volatile uint32_t HSI_RDYIE    : 1;
            volatile uint32_t HSE_RDYIE    : 1;
            volatile uint32_t PLL_RDYIE    : 1;
            volatile uint32_t PLL2_RDYIE   : 1;
            volatile uint32_t PLL3_RDYIE   : 1;
            volatile uint32_t _reserved1   : 1;
            volatile uint32_t LSI_RDYC     : 1;
            volatile uint32_t LSE_RDYC     : 1;
            volatile uint32_t HSI_RDYC     : 1;
            volatile uint32_t HSE_RDYC     : 1;
            volatile uint32_t PLL_RDYC     : 1;
            volatile uint32_t PLL2_RDYC    : 1;
            volatile uint32_t PLL3_RDYC    : 1;
            volatile uint32_t CSSc         : 1;
            volatile uint32_t _reserved2   : 8;
        }BITS; 
    } CIR; 
 
    union{ 
        volatile uint32_t REG; 
        struct{ 
            volatile uint32_t AFIO_RST     : 1;
            volatile uint32_t _reserved1   : 1;
            volatile uint32_t IOPA_RST     : 1;
            volatile uint32_t IOPB_RST     : 1;
            volatile uint32_t IOPC_RST     : 1;
            volatile uint32_t IOPD_RST     : 1;
            volatile uint32_t IOPE_RST     : 1;
            volatile uint32_t _reserved2   : 2;
            volatile uint32_t ADC1_RST     : 1;
            volatile uint32_t ADC2_RST     : 1;
            volatile uint32_t TIM1_RST     : 1;
            volatile uint32_t SPI1_RST     : 1;
            volatile uint32_t _reserved3   : 1;
            volatile uint32_t USART1_RST   : 1;
            volatile uint32_t _reserved4   : 17;
        }BITS; 
    } APB2RSTR; 
 
    union{ 
        volatile uint32_t REG; 
        struct{ 
            volatile uint32_t TIM2_RST     : 1;
            volatile uint32_t TIM3_RST     : 1;
            volatile uint32_t TIM4_RST     : 1;
            volatile uint32_t TIM5_RST     : 1;
            volatile uint32_t TIM6_RST     : 1;
            volatile uint32_t TIM7_RST     : 1;
            volatile uint32_t _reserved1   : 5;
            volatile uint32_t WWDG_RST     : 1;
            volatile uint32_t _reserved2   : 2;
            volatile uint32_t SPI2_RST     : 1;
            volatile uint32_t SPI3_RST     : 1;
            volatile uint32_t _reserved3   : 1;
            volatile uint32_t USART2_RST   : 1;
            volatile uint32_t USART3_RST   : 1;
            volatile uint32_t USART4_RST   : 1;
            volatile uint32_t USART5_RST   : 1;
            volatile uint32_t I2C1_RST     : 1;
            volatile uint32_t I2C2_RST     : 1;
            volatile uint32_t _reserved4   : 2;
            volatile uint32_t CAN1_RST     : 1;
            volatile uint32_t CAN2_RST     : 1;
            volatile uint32_t BKP_RST      : 1;
            volatile uint32_t PWR_RST      : 1;
            volatile uint32_t DAC_RST      : 1;
            volatile uint32_t _reserved5   : 2;
        }BITS; 
    }APB1RSTR; 
    union{ 
        volatile uint32_t REG; 
        struct{ 
            volatile uint32_t DMA1_EN     : 1;
            volatile uint32_t DMA2_EN     : 1;
            volatile uint32_t SRAM_EN     : 1;
            volatile uint32_t _reserved1  : 1;
            volatile uint32_t FLITF_EN    : 1;
            volatile uint32_t _reserved2  : 1;
            volatile uint32_t CRC_EN      : 1;
            volatile uint32_t _reserved3  : 5;
            volatile uint32_t OTGFS_EN    : 1;
            volatile uint32_t _reserved4  : 1;
            volatile uint32_t ETHMAC_EN   : 1;
            volatile uint32_t ETHMACTX_EN : 1;
            volatile uint32_t ETHMACRX_EN : 1;
            volatile uint32_t _reserved5  : 15;
        }BITS; 
    }AHBENR; 
    union{ 
        volatile uint32_t REG; 
        struct{ 
            volatile uint32_t AFIOEN      : 1;
            volatile uint32_t _reserved1  : 1;
            volatile uint32_t IOPAEN      : 1;
            volatile uint32_t IOPBEN      : 1;
            volatile uint32_t IOPCEN      : 1;
            volatile uint32_t IOPDEN      : 1;
            volatile uint32_t IOPEEN      : 1;
            volatile uint32_t IOPFEN      : 1;
            volatile uint32_t IOPGEN      : 1;
            volatile uint32_t ADC1EN      : 1;
            volatile uint32_t ADC2EN      : 1;
            volatile uint32_t TIM1EN      : 1;
            volatile uint32_t SPI1EN      : 1;
            volatile uint32_t TIM8EN      : 1;
            volatile uint32_t USART1EN    : 1;
            volatile uint32_t ADC3EN      : 1;
            volatile uint32_t _reserved2  : 3;
            volatile uint32_t TIM9EN      : 1;
            volatile uint32_t TIM10EN     : 1;
            volatile uint32_t TIM11EN     : 1;
            volatile uint32_t _reserved3  : 10;
        }BITS;
    } APB2ENR;

    union{
        volatile uint32_t REG; 
        struct{ 
            volatile uint32_t TIM2_EN      : 1;
            volatile uint32_t TIM3_EN      : 1;
            volatile uint32_t TIM4_EN      : 1;
            volatile uint32_t TIM5_EN      : 1;
            volatile uint32_t TIM6_EN      : 1;
            volatile uint32_t TIM7_EN      : 1;
            volatile uint32_t _reserved1   : 5;
            volatile uint32_t WWDG_EN      : 1;
            volatile uint32_t _reserved2   : 2;
            volatile uint32_t SPI2_EN      : 1;
            volatile uint32_t SPI3_EN      : 1;
            volatile uint32_t _reserved3   : 1;
            volatile uint32_t USART2_EN    : 1;
            volatile uint32_t USART3_EN    : 1;
            volatile uint32_t USART4_EN    : 1;
            volatile uint32_t USART5_EN    : 1;
            volatile uint32_t I2C1_EN      : 1;
            volatile uint32_t I2C2_EN      : 1;
            volatile uint32_t _reserved4   : 2;
            volatile uint32_t CAN1_EN      : 1;
            volatile uint32_t CAN2_EN      : 1;
            volatile uint32_t BKP_EN       : 1;
            volatile uint32_t PWR_EN       : 1;
            volatile uint32_t DAC_EN       : 1;
            volatile uint32_t _reserved5   : 2;
        }BITS; 
    }APB1ENR;

    union{
        volatile uint32_t REG; 
        struct{ 
            volatile uint32_t LSE_ON       : 1;
            volatile uint32_t LSE_RDY      : 1;
            volatile uint32_t LSE_BYP      : 1;
            volatile uint32_t _reserved1   : 5;
            volatile uint32_t RTC_SEL      : 2;
            volatile uint32_t _reserved2   : 5;
            volatile uint32_t RTC_EN       : 1;
            volatile uint32_t BDRST        : 1;
            volatile uint32_t _reserved3   : 15;
        }BITS;
    } BDCR;

    union{
        volatile uint32_t REG; 
        struct{ 
            volatile uint32_t LSI_ON       : 1;
            volatile uint32_t LSI_RDY      : 1;
            volatile uint32_t _reserved1   : 20;
            volatile uint32_t RMVF         : 1;
            volatile uint32_t _reserved2   : 1;
            volatile uint32_t PIN_RSTF     : 1;
            volatile uint32_t POR_RSTF     : 1;
            volatile uint32_t SFT_RSTF     : 1;
            volatile uint32_t IWDG_RSTF    : 1;
            volatile uint32_t WWDG_RSTF    : 1;
            volatile uint32_t LPWR_RSTF    : 1;
        }BITS;
    } CSR;
} RCC_Typedef;

#define RCC ((RCC_Typedef*)RCC_BASEADDR)

void RCC_GPIO_CLK_EN(volatile GPIO_Typedef *GPIOx);

#endif /* RCC_H_ */
