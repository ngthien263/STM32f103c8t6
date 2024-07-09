#include<stm32f103.h>
#define ADC1_BASEADDR (ABP2_BASEADDR | 0x2400)
#define ADC2_BASEADDR (ABP2_BASEADDR | 0x2800)
#define ADC3_BASEADDR (ABP2_BASEADDR | 0x3C00)

typedef struct{
    union {
        volatile uint32_t REG;
        struct{
            volatile uint32_t SQ7_0        : 1;
            volatile uint32_t SQ7_1        : 1;
            volatile uint32_t SQ7_2        : 1;
            volatile uint32_t SQ7_3        : 1;
            volatile uint32_t SQ7_4        : 1;
            volatile uint32_t SQ8_0        : 1;
            volatile uint32_t SQ8_1        : 1;
            volatile uint32_t SQ8_2        : 1;
            volatile uint32_t SQ8_3        : 1;
            volatile uint32_t SQ8_4        : 1;
            volatile uint32_t SQ9_0        : 1;
            volatile uint32_t SQ9_1        : 1;
            volatile uint32_t SQ9_2        : 1;
            volatile uint32_t SQ9_3        : 1;
            volatile uint32_t SQ9_4        : 1;
            volatile uint32_t SQ10_0       : 1;
            volatile uint32_t SQ10_1       : 1;
            volatile uint32_t SQ10_2       : 1;
            volatile uint32_t SQ10_3       : 1;
            volatile uint32_t SQ10_4       : 1;
            volatile uint32_t SQ11_0       : 1;
            volatile uint32_t SQ11_1       : 1;
            volatile uint32_t SQ11_2       : 1;
            volatile uint32_t SQ11_3       : 1;
            volatile uint32_t SQ11_4       : 1;
            volatile uint32_t SQ12_0       : 1;
            volatile uint32_t SQ12_1       : 1;
            volatile uint32_t SQ12_2       : 1;
            volatile uint32_t SQ12_3       : 1;
            volatile uint32_t SQ12_4       : 1;
            volatile uint32_t _reserved    : 2;
        }BITS;
    }ADC_SQR2;
    union {
        volatile uint32_t REG;
        struct{
            volatile uint32_t SQ1_0       : 1;
            volatile uint32_t SQ1_1       : 1;
            volatile uint32_t SQ1_2       : 1;
            volatile uint32_t SQ1_3       : 1;
            volatile uint32_t SQ1_4       : 1;
            volatile uint32_t SQ2_0       : 1;
            volatile uint32_t SQ2_1       : 1;
            volatile uint32_t SQ2_2       : 1;
            volatile uint32_t SQ2_3       : 1;
            volatile uint32_t SQ2_4       : 1;
            volatile uint32_t SQ3_0       : 1;
            volatile uint32_t SQ3_1       : 1;
            volatile uint32_t SQ3_2       : 1;
            volatile uint32_t SQ3_3       : 1;
            volatile uint32_t SQ3_4       : 1;
            volatile uint32_t SQ4_0       : 1;
            volatile uint32_t SQ4_1       : 1;
            volatile uint32_t SQ4_2       : 1;
            volatile uint32_t SQ4_3       : 1;
            volatile uint32_t SQ4_4       : 1;
            volatile uint32_t SQ5_0       : 1;
            volatile uint32_t SQ5_1       : 1;
            volatile uint32_t SQ5_2       : 1;
            volatile uint32_t SQ5_3       : 1;
            volatile uint32_t SQ5_4       : 1;
            volatile uint32_t SQ6_0       : 1;
            volatile uint32_t SQ6_1       : 1;
            volatile uint32_t SQ6_2       : 1;
            volatile uint32_t SQ6_3       : 1;
            volatile uint32_t SQ6_4       : 1;
            volatile uint32_t _reserved   : 2;
        }BITS;
    }ADC_SQR3;
    union {
        volatile uint32_t REG;
        struct{
            volatile uint32_t JSQ1_0       : 1;
            volatile uint32_t JSQ1_1       : 1;
            volatile uint32_t JSQ1_2       : 1;
            volatile uint32_t JSQ1_3       : 1;
            volatile uint32_t JSQ1_4       : 1;
            volatile uint32_t JSQ2_0       : 1;
            volatile uint32_t JSQ2_1       : 1;
            volatile uint32_t JSQ2_2       : 1;
            volatile uint32_t JSQ2_3       : 1;
            volatile uint32_t JSQ2_4       : 1;
            volatile uint32_t JSQ3_0       : 1;
            volatile uint32_t JSQ3_1       : 1;
            volatile uint32_t JSQ3_2       : 1;
            volatile uint32_t JSQ3_3       : 1;
            volatile uint32_t JSQ3_4       : 1;
            volatile uint32_t JSQ4_0       : 1;
            volatile uint32_t JSQ4_1       : 1;
            volatile uint32_t JSQ4_2       : 1;
            volatile uint32_t JSQ4_3       : 1;
            volatile uint32_t JSQ4_4       : 1;
            volatile uint32_t JL1          : 1;
            volatile uint32_t JL2          : 1;
            volatile uint32_t _reserved    : 10;
        }BITS;
    } ADC_SJQR;
    union {
        volatile uint32_t REG;
        struct{
            volatile uint32_t JDATA1       : 1;
            volatile uint32_t JDATA2       : 1;
            volatile uint32_t JDATA3       : 1;
            volatile uint32_t JDATA4       : 1;
            volatile uint32_t JDATA5       : 1;
            volatile uint32_t JDATA6       : 1;
            volatile uint32_t JDATA7       : 1;
            volatile uint32_t JDATA8       : 1;
            volatile uint32_t JDATA9       : 1;
            volatile uint32_t JDATA10      : 1;
            volatile uint32_t JDATA11      : 1;
            volatile uint32_t JDATA12      : 1;
            volatile uint32_t JDATA13      : 1;
            volatile uint32_t JDATA14      : 1;
            volatile uint32_t JDATA15      : 1;
            volatile uint32_t _reserved    : 16;
        }BITS;
    } ADC_JDR1;
    union {
        volatile uint32_t REG;
        struct{
            volatile uint32_t JDATA1       : 1;
            volatile uint32_t JDATA2       : 1;
            volatile uint32_t JDATA3       : 1;
            volatile uint32_t JDATA4       : 1;
            volatile uint32_t JDATA5       : 1;
            volatile uint32_t JDATA6       : 1;
            volatile uint32_t JDATA7       : 1;
            volatile uint32_t JDATA8       : 1;
            volatile uint32_t JDATA9       : 1;
            volatile uint32_t JDATA10      : 1;
            volatile uint32_t JDATA11      : 1;
            volatile uint32_t JDATA12      : 1;
            volatile uint32_t JDATA13      : 1;
            volatile uint32_t JDATA14      : 1;
            volatile uint32_t JDATA15      : 1;
            volatile uint32_t _reserved    : 16;
        }BITS;
    } ADC_JDR2;
    union {
        volatile uint32_t REG;
        struct{
            volatile uint32_t JDATA1       : 1;
            volatile uint32_t JDATA2       : 1;
            volatile uint32_t JDATA3       : 1;
            volatile uint32_t JDATA4       : 1;
            volatile uint32_t JDATA5       : 1;
            volatile uint32_t JDATA6       : 1;
            volatile uint32_t JDATA7       : 1;
            volatile uint32_t JDATA8       : 1;
            volatile uint32_t JDATA9       : 1;
            volatile uint32_t JDATA10      : 1;
            volatile uint32_t JDATA11      : 1;
            volatile uint32_t JDATA12      : 1;
            volatile uint32_t JDATA13      : 1;
            volatile uint32_t JDATA14      : 1;
            volatile uint32_t JDATA15      : 1;
            volatile uint32_t _reserved    : 16;
        }BITS;
    } ADC_JDR3;
    union {
        volatile uint32_t REG;
        struct{
            volatile uint32_t JDATA1       : 1;
            volatile uint32_t JDATA2       : 1;
            volatile uint32_t JDATA3       : 1;
            volatile uint32_t JDATA4       : 1;
            volatile uint32_t JDATA5       : 1;
            volatile uint32_t JDATA6       : 1;
            volatile uint32_t JDATA7       : 1;
            volatile uint32_t JDATA8       : 1;
            volatile uint32_t JDATA9       : 1;
            volatile uint32_t JDATA10      : 1;
            volatile uint32_t JDATA11      : 1;
            volatile uint32_t JDATA12      : 1;
            volatile uint32_t JDATA13      : 1;
            volatile uint32_t JDATA14      : 1;
            volatile uint32_t JDATA15      : 1;
            volatile uint32_t _reserved    : 16;
        }BITS;
    } ADC_JDR4;
    union{
        volatile uint32_t REG;
        struct{
            volatile uint32_t RDATA1       : 1;
            volatile uint32_t RDATA2       : 1;
            volatile uint32_t RDATA3       : 1;
            volatile uint32_t RDATA4       : 1;
            volatile uint32_t RDATA5       : 1;
            volatile uint32_t RDATA6       : 1;
            volatile uint32_t RDATA7       : 1;
            volatile uint32_t RDATA8       : 1;
            volatile uint32_t RDATA9       : 1;
            volatile uint32_t RDATA10      : 1;
            volatile uint32_t RDATA11      : 1;
            volatile uint32_t RDATA12      : 1;
            volatile uint32_t RDATA13      : 1;
            volatile uint32_t RDATA14      : 1;
            volatile uint32_t RDATA15      : 1;
            volatile uint32_t ADC2DATA1    : 1;
            volatile uint32_t ADC2DATA2    : 1;
            volatile uint32_t ADC2DATA3    : 1;
            volatile uint32_t ADC2DATA4    : 1;
            volatile uint32_t ADC2DATA5    : 1;
            volatile uint32_t ADC2DATA6    : 1;
            volatile uint32_t ADC2DATA7    : 1;
            volatile uint32_t ADC2DATA8    : 1;
            volatile uint32_t ADC2DATA9    : 1;
            volatile uint32_t ADC2DATA10   : 1;
            volatile uint32_t ADC2DATA11   : 1;
            volatile uint32_t ADC2DATA12   : 1;
            volatile uint32_t ADC2DATA13   : 1;
            volatile uint32_t ADC2DATA14   : 1;
            volatile uint32_t ADC2DATA15   : 1;
        }BITS;
    }ADC_DR;
} ADC_map;
