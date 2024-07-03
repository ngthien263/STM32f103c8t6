#ifndef GPIO_H_
#define GPIO_H_
#include <C:\Users\Thien\Desktop\STM32f103c8t6\Include\stm32f103.h>

#define GPIOA_BASEADDR (ABP2_BASEADDR | 0x0800)
#define GPIOB_BASEADDR (ABP2_BASEADDR | 0x0C00)
#define GPIOC_BASEADDR (ABP2_BASEADDR | 0x1000)
#define GPIOD_BASEADDR (ABP2_BASEADDR | 0x1400)
#define GPIOE_BASEADDR (ABP2_BASEADDR | 0x1800)
#define GPIOF_BASEADDR (ABP2_BASEADDR | 0x1C00)
#define GPIOG_BASEADDR (ABP2_BASEADDR | 0x2000)

#define GPIOA ((GPIO_map*)GPIOA_BASEADDR)
#define GPIOB ((GPIO_map*)GPIOB_BASEADDR)
#define GPIOC ((GPIO_map*)GPIOC_BASEADDR)
#define GPIOD ((GPIO_map*)GPIOD_BASEADDR)
#define GPIOE ((GPIO_map*)GPIOE_BASEADDR)
#define GPIOF ((GPIO_map*)GPIOF_BASEADDR)
#define GPIOG ((GPIO_map*)GPIOG_BASEADDR)

typedef enum 
{                                                       
    GPIO_OUTPUT_MODE_10M_PP = 0x1,  // 0b0001
    GPIO_OUTPUT_MODE_10M_OD = 0x5,  // 0b0101
    GPIO_ALT_MODE_10M_PP    = 0x9,  // 0b1001
    GPIO_ALT_MODE_10M_OD    = 0xD,  // 0b1101
    GPIO_OUTPUT_MODE_2M_PP  = 0x2,  // 0b0010
    GPIO_OUTPUT_MODE_2M_OD  = 0x6,  // 0b0110
    GPIO_ALT_MODE_2M_PP     = 0xA,  // 0b1010
    GPIO_ALT_MODE_2M_OD     = 0xE,  // 0b1110
    GPIO_OUTPUT_MODE_50M_PP = 0x3,  // 0b0011
    GPIO_OUTPUT_MODE_50M_OD = 0x7,  // 0b0111
    GPIO_ALT_MODE_50M_PP    = 0xB,  // 0b1011
    GPIO_ALT_MODE_50M_OD    = 0xF,  // 0b1111
    GPIO_INPUT_MODE_ANALOG  = 0x0,  // 0b0000
    GPIO_INPUT_MODE_FLOAT   = 0x4,  // 0b0100
    GPIO_INPUT_MODE_PuPd    = 0x8,  // 0b1000
    GPIO_MODE_UNDEFINED     = -1
} GPIO_MODE;


typedef enum {
    PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7,
    PIN8, PIN9, PIN10, PIN11, PIN12, PIN13, PIN14, PIN15
} GPIO_PIN;

static inline void GPIO_SetMode(volatile GPIO_map *GPIOx, GPIO_PIN Pin, GPIO_MODE Mode);
static inline void GPIO_GetMode(volatile GPIO_map *GPIOx, GPIO_PIN Pin);

typedef struct {
    union {
        volatile uint32_t REG;  
        struct {
            volatile uint32_t MODE_0 : 2;
            volatile uint32_t CNF_0  : 2;
            volatile uint32_t MODE_1 : 2;
            volatile uint32_t CNF_1  : 2;
            volatile uint32_t MODE_2 : 2;
            volatile uint32_t CNF_2  : 2;
            volatile uint32_t MODE_3 : 2;
            volatile uint32_t CNF_3  : 2;
            volatile uint32_t MODE_4 : 2;
            volatile uint32_t CNF_4  : 2;
            volatile uint32_t MODE_5 : 2;
            volatile uint32_t CNF_5  : 2;
            volatile uint32_t MODE_6 : 2;
            volatile uint32_t CNF_6  : 2;
            volatile uint32_t MODE_7 : 2;
            volatile uint32_t CNF_7  : 2;
        } BITS;  
    } CRL;

    union {
        volatile uint32_t REG;  
        struct {
            volatile uint32_t MODE_8  : 2;                   
            volatile uint32_t CNF_8   : 2;
            volatile uint32_t MODE_9  : 2;
            volatile uint32_t CNF_9   : 2;
            volatile uint32_t MODE_10 : 2;
            volatile uint32_t CNF_10  : 2;
            volatile uint32_t MODE_11 : 2;
            volatile uint32_t CNF_11  : 2;
            volatile uint32_t MODE_12 : 2;
            volatile uint32_t CNF_12  : 2;
            volatile uint32_t MODE_13 : 2;
            volatile uint32_t CNF_13  : 2;
            volatile uint32_t MODE_14 : 2;
            volatile uint32_t CNF_14  : 2;
            volatile uint32_t MODE_15 : 2;
            volatile uint32_t CNF_15  : 2;
        } BITS;  
    } CRH;

    union{
        volatile uint32_t REG;  
        struct {
            volatile uint32_t IDR0      : 1;              
            volatile uint32_t IDR1      : 1;
            volatile uint32_t IDR2      : 1;
            volatile uint32_t IDR3      : 1;
            volatile uint32_t IDR4      : 1;
            volatile uint32_t IDR5      : 1;
            volatile uint32_t IDR6      : 1;
            volatile uint32_t IDR7      : 1;
            volatile uint32_t IDR8      : 1;
            volatile uint32_t IDR9      : 1;
            volatile uint32_t IDR10     : 1;
            volatile uint32_t IDR11     : 1;
            volatile uint32_t IDR12     : 1;
            volatile uint32_t IDR13     : 1;
            volatile uint32_t IDR14     : 1;
            volatile uint32_t IDR15     : 1;
            volatile uint32_t _reserved : 16;
        } BITS;  
    } IDR;

    union{
        volatile uint32_t REG;  
        struct {
            volatile uint32_t ODR0      : 1;              
            volatile uint32_t ODR1      : 1;
            volatile uint32_t ODR2      : 1;
            volatile uint32_t ODR3      : 1;
            volatile uint32_t ODR4      : 1;
            volatile uint32_t ODR5      : 1;
            volatile uint32_t ODR6      : 1;
            volatile uint32_t ODR7      : 1;
            volatile uint32_t ODR8      : 1;
            volatile uint32_t ODR9      : 1;
            volatile uint32_t ODR10     : 1;
            volatile uint32_t ODR11     : 1;
            volatile uint32_t ODR12     : 1;
            volatile uint32_t ODR13     : 1;
            volatile uint32_t ODR14     : 1;
            volatile uint32_t ODR15     : 1;
            volatile uint32_t _reserved : 16;
        } BITS;  
    } ODR;

    union {
        volatile uint32_t REG;
        struct {
            volatile uint32_t BS0  : 1;              
            volatile uint32_t BS1  : 1;
            volatile uint32_t BS2  : 1;
            volatile uint32_t BS3  : 1;
            volatile uint32_t BS4  : 1;
            volatile uint32_t BS5  : 1;
            volatile uint32_t BS6  : 1;
            volatile uint32_t BS7  : 1;
            volatile uint32_t BS8  : 1;
            volatile uint32_t BS9  : 1;
            volatile uint32_t BS10 : 1;
            volatile uint32_t BS11 : 1;
            volatile uint32_t BS12 : 1;
            volatile uint32_t BS13 : 1;
            volatile uint32_t BS14 : 1;
            volatile uint32_t BS15 : 1;
        }BS;
        struct {
            volatile uint32_t BR0  : 1;              
            volatile uint32_t BR1  : 1;
            volatile uint32_t BR2  : 1;
            volatile uint32_t BR3  : 1;
            volatile uint32_t BR4  : 1;
            volatile uint32_t BR5  : 1;
            volatile uint32_t BR6  : 1;
            volatile uint32_t BR7  : 1;
            volatile uint32_t BR8  : 1;
            volatile uint32_t BR9  : 1;
            volatile uint32_t BR10 : 1;
            volatile uint32_t BR11 : 1;
            volatile uint32_t BR12 : 1;
            volatile uint32_t BR13 : 1;
            volatile uint32_t BR14 : 1;
            volatile uint32_t BR15 : 1;
        }BR;
    } BSRR;

    union{
        volatile uint32_t REG;
        struct {
            volatile uint32_t BR0       : 1;              
            volatile uint32_t BR1       : 1;
            volatile uint32_t BR2       : 1;
            volatile uint32_t BR3       : 1;
            volatile uint32_t BR4       : 1;
            volatile uint32_t BR5       : 1;
            volatile uint32_t BR6       : 1;
            volatile uint32_t BR7       : 1;
            volatile uint32_t BR8       : 1;
            volatile uint32_t BR9       : 1;
            volatile uint32_t BR10      : 1;
            volatile uint32_t BR11      : 1;
            volatile uint32_t BR12      : 1;
            volatile uint32_t BR13      : 1;
            volatile uint32_t BR14      : 1;
            volatile uint32_t BR15      : 1;
            volatile uint32_t _reserved : 16;
        } BR;
    } BRR;

    union{
        volatile uint32_t REG;
        struct{
            volatile uint32_t LCK0      : 1;              
            volatile uint32_t LCK1      : 1;
            volatile uint32_t LCK2      : 1;
            volatile uint32_t LCK3      : 1;
            volatile uint32_t LCK4      : 1;
            volatile uint32_t LCK5      : 1;
            volatile uint32_t LCK6      : 1;
            volatile uint32_t LCK7      : 1;
            volatile uint32_t LCK8      : 1;
            volatile uint32_t LCK9      : 1;
            volatile uint32_t LCK10     : 1;
            volatile uint32_t LCK11     : 1;
            volatile uint32_t LCK12     : 1;
            volatile uint32_t LCK13     : 1;
            volatile uint32_t LCK14     : 1;
            volatile uint32_t LCK15     : 1;
            volatile uint32_t LCKK      : 1;
            volatile uint32_t _reserved : 15;
        } BITS;
    } LCKR;
} GPIO_map;

#endif /* GPIO_H_ */