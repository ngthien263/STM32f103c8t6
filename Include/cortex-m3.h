#ifndef _CORTEX_M3_
#define _CORTEX_M3_
#include <stdint.h>

#define __disable_irq()  asm("cpsid i");
#define __enable_irq()   asm("cpsie i");

#define NVIC_BASEADDR    0xE000E100
#define NVIC             ((NVIC_Typedef*)NVIC_BASEADDR)
#define NVIC_STIR        ((volatile uint32_t*)0xE000EF00)
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
    WWDG_IRQHandler                    ,  /* Window Watchdog Interrupt */
    PVD_IRQHandler                     ,  /* PVD through EXTI Line detect Interrupt */
    TAMPER_IRQHandler                  ,  /* Tamper Interrupt */
    RTC_IRQHandler                     ,  /* RTC Interrupt */
    FLASH_IRQHandler                   ,  /* Flash Interrupt */
    RCC_IRQHandler                     ,  /* RCC Interrupt */
    EXTI0_IRQHandler                   ,  /* EXTI Line 0 Interrupt */
    EXTI1_IRQHandler                   ,  /* EXTI Line 1 Interrupt */
    EXTI2_IRQHandler                   ,  /* EXTI Line 2 Interrupt */
    EXTI3_IRQHandler                   ,  /* EXTI Line 3 Interrupt */
    EXTI4_IRQHandler                   ,  /* EXTI Line 4 Interrupt */
    DMA1_Channel1_IRQHandler           ,  /* DMA1 Channel 1 Interrupt */
    DMA1_Channel2_IRQHandler           ,  /* DMA1 Channel 2 Interrupt */
    DMA1_Channel3_IRQHandler           ,  /* DMA1 Channel 3 Interrupt */
    DMA1_Channel4_IRQHandler           ,  /* DMA1 Channel 4 Interrupt */
    DMA1_Channel5_IRQHandler           ,  /* DMA1 Channel 5 Interrupt */
    DMA1_Channel6_IRQHandler           ,  /* DMA1 Channel 6 Interrupt */
    DMA1_Channel7_IRQHandler           ,  /* DMA1 Channel 7 Interrupt */
    ADC1_2_IRQHandler                  ,  /* ADC1_2 Interrupt */
    USB_HP_CAN1_TX_IRQHandler          ,  /* USB High Priority or CAN1 TX Interrupt */
    USB_LP_CAN1_RX0_IRQHandler         ,  /* USB Low Priority or CAN1 RX0 Interrupt */
    CAN1_RX1_IRQHandler                ,  /* CAN1 RX1 Interrupt */
    CAN1_SCE_IRQHandler                ,  /* CAN1 SCE Interrupt */
    EXTI9_5_IRQHandler                 ,  /* EXTI Line 9..5 Interrupt */
    TIM1_BRK_IRQHandler                ,  /* TIM1 Break Interrupt */
    TIM1_UP_IRQHandler                 ,  /* TIM1 Update Interrupt */
    TIM1_TRG_COM_IRQHandler            ,  /* TIM1 Trigger and Commutation Interrupt */
    TIM1_CC_IRQHandler                 ,  /* TIM1 Capture Compare Interrupt */
    TIM2_IRQHandler                    ,  /* TIM2 Interrupt */
    TIM3_IRQHandler                    ,  /* TIM3 Interrupt */
    TIM4_IRQHandler                    ,  /* TIM4 Interrupt */
    I2C1_EV_IRQHandler                 ,  /* I2C1 Event Interrupt */
    I2C1_ER_IRQHandler                 ,  /* I2C1 Error Interrupt */
    I2C2_EV_IRQHandler                 ,  /* I2C2 Event Interrupt */
    I2C2_ER_IRQHandler                 ,  /* I2C2 Error Interrupt */
    SPI1_IRQHandler                    ,  /* SPI1 Interrupt */
    SPI2_IRQHandler                    ,  /* SPI2 Interrupt */
    USART1_IRQHandler                  ,  /* USART1 Interrupt */
    USART2_IRQHandler                  ,  /* USART2 Interrupt */
    USART3_IRQHandler                  ,  /* USART3 Interrupt */
    EXTI15_10_IRQHandler               ,  /* EXTI Line 15..10 Interrupt */
    RTCAlarm_IRQHandler                ,  /* RTC Alarm through EXTI Line Interrupt */
    USBWakeUp_IRQHandler               ,  /* USB Wakeup from suspend Interrupt */
} IRQn_Type;


typedef struct
{
    volatile uint32_t ISER[3];
    volatile uint32_t ICER[3];
    volatile uint32_t ISPR[3];
    volatile uint32_t ICPR[3];
} NVIC_Typedef;

#define STK_BASEADDR	0xE000E010
#define STK     ((STK_TypeDef*)STK_BASEADDR)
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
  volatile uint32_t LOAD;           //only 24 bits low are used
  volatile uint32_t VAL;            //...
  volatile uint32_t CALIB;          //...
} STK_TypeDef;

void NVIC_EnableIRQ(IRQn_Type IRQn);
void NVIC_DisableIRQ(IRQn_Type IRQn);
#endif