#ifndef GPIO_H_
#define GPIO_H_
#include<common.h>

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
    GPIO_OUTPUT_MODE_10M_PP = 0x0001,
    GPIO_OUTPUT_MODE_10M_OD = 0x0101,
    GPIO_ALT_MODE_10M_PP    = 0x1001,
    GPIO_ALT_MODE_10M_OD    = 0x1101,
    GPIO_OUTPUT_MODE_2M_PP  = 0x0010,
    GPIO_OUTPUT_MODE_2M_OD  = 0x0110,
    GPIO_ALT_MODE_2M_PP     = 0x1010,
    GPIO_ALT_MODE_2M_OD     = 0x1110,
    GPIO_OUTPUT_MODE_50M_PP = 0x0011,
    GPIO_OUTPUT_MODE_50M_OD = 0x0111,
    GPIO_ALT_MODE_50M_PP    = 0x1011,
    GPIO_ALT_MODE_50M_OD    = 0x1111,
    GPIO_INPUT_MODE_ANALOG  = 0x0000,
    GPIO_INPUT_MODE_FLOAT   = 0x0100,
    GPIO_INPUT_MODE_PuPd    = 0x1000
} GPIO_MODE;

typedef enum {
    PINA0 = 0x00, PINA1 = 0x04, PINA2 = 0x08, PINA3 = 0x0C, PINA4 = 0x10, PINA5 = 0x14, PINA6 = 0x18, PINA7 = 0x1C,
    PINA8 = 0x20, PINA9 = 0x24, PINA10 = 0x28, PINA11 = 0x2C, PINA12 = 0x30, PINA13 = 0x34, PINA14 = 0x38, PINA15 = 0x3C,
    PINB0 = 0x00, PINB1 = 0x04, PINB2 = 0x08, PINB3 = 0x0C, PINB4 = 0x10, PINB5 = 0x14, PINB6 = 0x18, PINB7 = 0x1C,
    PINB8 = 0x20, PINB9 = 0x24, PINB10 = 0x28, PINB11 = 0x2C, PINB12 = 0x30, PINB13 = 0x34, PINB14 = 0x38, PINB15 = 0x3C,
    PINC0 = 0x00, PINC1 = 0x04, PINC2 = 0x08, PINC3 = 0x0C, PINC4 = 0x10, PINC5 = 0x14, PINC6 = 0x18, PINC7 = 0x1C,
    PINC8 = 0x20, PINC9 = 0x24, PINC10 = 0x28, PINC11 = 0x2C, PINC12 = 0x30, PINC13 = 0x34, PINC14 = 0x38, PINC15 = 0x3C,
    PIND0 = 0x00, PIND1 = 0x04, PIND2 = 0x08, PIND3 = 0x0C, PIND4 = 0x10, PIND5 = 0x14, PIND6 = 0x18, PIND7 = 0x1C,
    PIND8 = 0x20, PIND9 = 0x24, PIND10 = 0x28, PIND11 = 0x2C, PIND12 = 0x30, PIND13 = 0x34, PIND14 = 0x38, PIND15 = 0x3C,
    PINE0 = 0x00, PINE1 = 0x04, PINE2 = 0x08, PINE3 = 0x0C, PINE4 = 0x10, PINE5 = 0x14, PINE6 = 0x18, PINE7 = 0x1C,
    PINE8 = 0x20, PINE9 = 0x24, PINE10 = 0x28, PINE11 = 0x2C, PINE12 = 0x30, PINE13 = 0x34, PINE14 = 0x38, PINE15 = 0x3C,
    PINF0 = 0x00, PINF1 = 0x04, PINF2 = 0x08, PINF3 = 0x0C, PINF4 = 0x10, PINF5 = 0x14, PINF6 = 0x18, PINF7 = 0x1C,
    PINF8 = 0x20, PINF9 = 0x24, PINF10 = 0x28, PINF11 = 0x2C, PINF12 = 0x30, PINF13 = 0x34, PINF14 = 0x38, PINF15 = 0x3C,
    PING0 = 0x00, PING1 = 0x04, PING2 = 0x08, PING3 = 0x0C, PING4 = 0x10, PING5 = 0x14, PING6 = 0x18, PING7 = 0x1C,
    PING8 = 0x20, PING9 = 0x24, PING10 = 0x28, PING11 = 0x2C, PING12 = 0x30, PING13 = 0x34, PING14 = 0x38, PING15 = 0x3C
} GPIO_PIN;

void GPIO_Init(volatile GPIO_map *GPIOx, GPIO_PIN Pin, GPIO_MODE Mode);


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