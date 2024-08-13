#ifndef _CORTEX_M3_
#define _CORTEX_M3_
#include <stdint.h>
#include "base_adrr.h"
#define enable_irq()   __asm("cpsie i")
#define disable_irq()  __asm("cpsid i")

typedef enum      
{
    /* -------------------  Cortex-M3 Processor Exceptions Numbers  ------------------- */
    NonMaskableInt_IRQn           = -14,  /*  2 Non Maskable Interrupt */
    HardFault_IRQn                = -13,  /*  3 Hard Fault Interrupt */
    MemoryManagement_IRQn         = -12,  /*  4 Memory Management Interrupt */
    BusFault_IRQn                 = -11,  /*  5 Bus Fault Interrupt */
    UsageFault_IRQn               = -10,  /*  6 Usage Fault Interrupt */
    SVCall_IRQn                   =  -5,  /* 11 SV Call Interrupt */
    PendSV_IRQn                   =  -2,  /* 14 Pend SV Interrupt */
    SysTick_IRQn                  =  -1,  /* 15 System Tick Interrupt */

    /* ----------------------  ARMCM3 Specific Interrupt Numbers  --------------------- */
    WWDG_IRQn                          ,  /* Window Watchdog Interrupt */
    PVD_IRQn                           ,  /* PVD through EXTI Line detect Interrupt */
    TAMPER_IRQn                        ,  /* Tamper Interrupt */
    RTC_IRQn                           ,  /* RTC Interrupt */
    FLASH_IRQn                         ,  /* Flash Interrupt */
    RCC_IRQn                           ,  /* RCC Interrupt */
    EXTI0_IRQn                         ,  /* EXTI Line 0 Interrupt */
    EXTI1_IRQn                         ,  /* EXTI Line 1 Interrupt */
    EXTI2_IRQn                         ,  /* EXTI Line 2 Interrupt */
    EXTI3_IRQn                         ,  /* EXTI Line 3 Interrupt */
    EXTI4_IRQn                         ,  /* EXTI Line 4 Interrupt */
    DMA1_Channel1_IRQn                 ,  /* DMA1 Channel 1 Interrupt */
    DMA1_Channel2_IRQn                 ,  /* DMA1 Channel 2 Interrupt */
    DMA1_Channel3_IRQn                 ,  /* DMA1 Channel 3 Interrupt */
    DMA1_Channel4_IRQn                 ,  /* DMA1 Channel 4 Interrupt */
    DMA1_Channel5_IRQn                 ,  /* DMA1 Channel 5 Interrupt */
    DMA1_Channel6_IRQn                 ,  /* DMA1 Channel 6 Interrupt */
    DMA1_Channel7_IRQn                 ,  /* DMA1 Channel 7 Interrupt */
    ADC1_2_IRQn                        ,  /* ADC1_2 Interrupt */
    USB_HP_CAN1_TX_IRQn                ,  /* USB High Priority or CAN1 TX Interrupt */
    USB_LP_CAN1_RX0_IRQn               ,  /* USB Low Priority or CAN1 RX0 Interrupt */
    CAN1_RX1_IRQn                      ,  /* CAN1 RX1 Interrupt */
    CAN1_SCE_IRQn                      ,  /* CAN1 SCE Interrupt */
    EXTI9_5_IRQn                       ,  /* EXTI Line 9..5 Interrupt */
    TIM1_BRK_IRQn                      ,  /* TIM1 Break Interrupt */
    TIM1_UP_IRQn                       ,  /* TIM1 Update Interrupt */
    TIM1_TRG_COM_IRQn                  ,  /* TIM1 Trigger and Commutation Interrupt */
    TIM1_CC_IRQn                       ,  /* TIM1 Capture Compare Interrupt */
    TIM2_IRQn                          ,  /* TIM2 Interrupt */
    TIM3_IRQn                          ,  /* TIM3 Interrupt */
    TIM4_IRQn                          ,  /* TIM4 Interrupt */
    I2C1_EV_IRQn                       ,  /* I2C1 Event Interrupt */
    I2C1_ER_IRQn                       ,  /* I2C1 Error Interrupt */
    I2C2_EV_IRQn                       ,  /* I2C2 Event Interrupt */
    I2C2_ER_IRQn                       ,  /* I2C2 Error Interrupt */
    SPI1_IRQn                          ,  /* SPI1 Interrupt */
    SPI2_IRQn                          ,  /* SPI2 Interrupt */
    USART1_IRQn                        ,  /* USART1 Interrupt */
    USART2_IRQn                        ,  /* USART2 Interrupt */
    USART3_IRQn                        ,  /* USART3 Interrupt */
    EXTI15_10_IRQn                     ,  /* EXTI Line 15..10 Interrupt */
    RTCAlarm_IRQn                      ,  /* RTC Alarm through EXTI Line Interrupt */
    USBWakeUp_IRQn                     ,  /* USB Wakeup from suspend Interrupt */
} IRQn_Type;


#define NVIC             ((NVIC_TypeDef*)NVIC_BASEADDR)
#define NVIC_STIR        ((volatile uint32_t*)0xE000EF00)

typedef struct
{
    volatile uint32_t ISER[3];
    volatile uint32_t _reserved[29];
    volatile uint32_t ICER[3];
    volatile uint32_t _reserved1[29];
    volatile uint32_t ISPR[3];
    volatile uint32_t ICPR[3];
} NVIC_TypeDef;

static inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  NVIC->ISER[(uint32_t)IRQn >> 5ul] |= (1ul<<(IRQn & 0x1F));
}

static inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  NVIC->ICER[(uint32_t)IRQn >> 5ul] |= (1ul<<(IRQn & 0x1F));
}


typedef struct
{
  union
  {
    volatile uint32_t REG;
    struct
    {
      volatile uint32_t ENABLE              : 1;
      volatile uint32_t TICK_INT            : 1;
      volatile uint32_t CLK_SOURCE          : 1;
      volatile uint32_t _reserved           : 13;
      volatile uint32_t COUNT_FLAG          : 1;
      volatile uint32_t _reserved1          : 15;
    } BITS;
  } CTRL;
  volatile uint32_t LOAD;           /* Only 24 bits low are used */
  volatile uint32_t VAL;            /* Only 24 bits low are used */
  volatile uint32_t CALIB;          /* Only 24 bits low are used */
} STK_TypeDef;

#define STK     ((STK_TypeDef*)STK_BASEADDR)
extern volatile uint32_t msTime;
__attribute__((weak)) void STK_Init();
void Delay_ms(uint32_t time);
#endif