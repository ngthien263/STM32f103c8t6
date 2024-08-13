/* -------------------------------------------------CM3 BASE ADDRESS--------------------------------------------------*/
#define STK_BASEADDR	 		(0xE000E010)
#define NVIC_BASEADDR  		(0xE000E100)
/* ---------------------------------------------PERIPHERAL BASE ADDRESS-----------------------------------------------*/
#define ABP1_BASEADDR 0x40000000 
#define ABP2_BASEADDR 0x40010000
#define AHB_BASEADDR  0x40018000
/* -------------------------------------------------RCC BASE ADDRESS--------------------------------------------------*/
#define RCC_BASEADDR	 		(0x40021000)
/* -------------------------------------------------GPIO BASE ADDRESS-------------------------------------------------*/
#define GPIOA_BASEADDR 		(ABP2_BASEADDR | 0x0800)
#define GPIOB_BASEADDR 		(ABP2_BASEADDR | 0x0C00)
#define GPIOC_BASEADDR 		(ABP2_BASEADDR | 0x1000)
#define GPIOD_BASEADDR 		(ABP2_BASEADDR | 0x1400)
#define GPIOE_BASEADDR 		(ABP2_BASEADDR | 0x1800)
#define GPIOF_BASEADDR 		(ABP2_BASEADDR | 0x1C00)
#define GPIOG_BASEADDR 		(ABP2_BASEADDR | 0x2000)
#define GPIO_offset	   		(0x400u)
/* -------------------------------------------------TIMER BASE ADDRESS-------------------------------------------------*/
#define TIM1_BASEADDR 		(ABP2_BASEADDR | 0x2C00)
#define TIM8_BASEADDR 		(ABP2_BASEADDR | 0x3400)
/* -------------------------------------------------USART BASE ADDRESS-------------------------------------------------*/
#define USART1_BASEADDR 	(ABP2_BASEADDR | 0x3800)
#define USART2_BASEADDR 	(ABP1_BASEADDR | 0x4400)
#define USART3_BASEADDR 	(ABP1_BASEADDR | 0x4800)
#define UART4_BASEADDR  	(ABP1_BASEADDR | 0x4800)
#define UART5_BASEADDR  	(ABP1_BASEADDR | 0x5000)


/* --------------------------------------------------SPI BASE ADDRESS--------------------------------------------------*/
#define SPI1_BASEADDR			(ABP2_BASEADDR | 0x3000)
#define SPI2_BASEADDR			(ABP1_BASEADDR | 0x3800)
#define SPI3_BASEADDR			(ABP1_BASEADDR | 0x3C00)