#include <stdint.h>
#include "base_adrr.h"
#define TIM1 ((AdvTim_Typedef*)TIM1_BASEADDR)
#define TIM8 ((AdvTim_Typedef*)TIM8_BASEADDR)
typedef struct 
{
    union
    {
       volatile uint32_t REG;
       struct
       {
         volatile uint32_t CEN           : 1;
         volatile uint32_t UDIS          : 1;
         volatile uint32_t URS           : 1;
         volatile uint32_t OPM           : 1;
         volatile uint32_t DIR           : 1;
         volatile uint32_t CMS           : 2;
         volatile uint32_t ARPE          : 1;
         volatile uint32_t CKD           : 2;
         volatile uint32_t _reserved     : 22;
       } BITS;  
    } CR1;

    union
    {
       volatile uint32_t REG;
       struct
       {
         volatile uint32_t CCPC          : 1;
         volatile uint32_t _reserved     : 1;
         volatile uint32_t CCUS          : 1;
         volatile uint32_t CCDS          : 1;
         volatile uint32_t MMS           : 3;
         volatile uint32_t TI1S          : 1;
         volatile uint32_t OIS1          : 1;
         volatile uint32_t OIS1N         : 1;
         volatile uint32_t OIS2          : 1;
         volatile uint32_t OIS2N         : 1;
         volatile uint32_t OIS3          : 1;
         volatile uint32_t OIS3N         : 1;
         volatile uint32_t OIS4          : 1;
         volatile uint32_t _reserved2    : 17;
       } BITS;  
    } CR2;
    
    union
    {
       volatile uint32_t REG;
       struct
       {
         volatile uint32_t SMS          : 3;
         volatile uint32_t _reserved    : 1;
         volatile uint32_t TS           : 3;
         volatile uint32_t MSM          : 1;
         volatile uint32_t ETF          : 4;
         volatile uint32_t ETPS         : 2;
         volatile uint32_t ECE          : 1;    
         volatile uint32_t ETP          : 1;
         volatile uint32_t _reserved2   : 16;
       } BITS;  
    } SMCR;

    union
    {
       volatile uint32_t REG;
       struct
       {
         volatile uint32_t UIE          : 1;
         volatile uint32_t CC1IE        : 1;
         volatile uint32_t CC2IE        : 1;
         volatile uint32_t CC3IE        : 1;
         volatile uint32_t CC4IE        : 1;
         volatile uint32_t COMIE        : 1;
         volatile uint32_t TIE          : 1;
         volatile uint32_t BIE          : 1;
         volatile uint32_t UDE          : 1;
         volatile uint32_t CC1DE        : 1;
         volatile uint32_t CC2DE        : 1;
         volatile uint32_t CC3DE        : 1;
         volatile uint32_t CC4DE        : 1;
         volatile uint32_t COM          : 1;
         volatile uint32_t TDE          : 1;
         volatile uint32_t _reserved    : 17;
       } BITS;  
    } DIER;

    union
    {
       volatile uint32_t REG;
       struct
       {
         volatile uint32_t UIF          : 1;
         volatile uint32_t CC1IF        : 1;
         volatile uint32_t CC2IF        : 1;
         volatile uint32_t CC3IF        : 1;
         volatile uint32_t CC4IF        : 1;
         volatile uint32_t COMIF        : 1;
         volatile uint32_t TIF          : 1;
         volatile uint32_t BIF          : 1;
         volatile uint32_t _reserved    : 1;
         volatile uint32_t CC1OF        : 1;
         volatile uint32_t CC2OF        : 1;
         volatile uint32_t CC3OF        : 1;
         volatile uint32_t CC4OF        : 1;
         volatile uint32_t _reserved2   : 19;
       } BITS;  
    } SR;

    union
    {
       volatile uint32_t REG;
       struct
       {
         volatile uint32_t UG          : 1;
         volatile uint32_t CC1G        : 1;
         volatile uint32_t CC2G        : 1;
         volatile uint32_t CC3G        : 1;
         volatile uint32_t CC4G        : 1;
         volatile uint32_t COMG        : 1;
         volatile uint32_t TG          : 1;
         volatile uint32_t BG          : 1;
         volatile uint32_t _reserved   : 24;
       } BITS;  
    } EGR;

    union
    {
        volatile uint32_t REG;
        struct
        {
            volatile uint32_t CC1S        : 2;
            volatile uint32_t IC1PSC      : 2;
            volatile uint32_t IC1F        : 4;
            volatile uint32_t CC2S        : 2;
            volatile uint32_t IC2PSC      : 2;
            volatile uint32_t IC2F        : 4;
            volatile uint32_t _reserved   : 16;
        } INPUT_BITS;

        struct
        {
            volatile uint32_t CC1S        : 2;
            volatile uint32_t OC1FE       : 1;
            volatile uint32_t OC1PE       : 1;
            volatile uint32_t OC1M        : 3;
            volatile uint32_t OC1CE       : 1;
            volatile uint32_t CC2S        : 2;
            volatile uint32_t OC2FE       : 1;
            volatile uint32_t OC2PE       : 1;
            volatile uint32_t OC2M        : 3;
            volatile uint32_t OC2CE       : 1;
            volatile uint32_t _reserved   : 16;
        } OUTPUT_BITS;
    } CCMR1;

    union
    {
        volatile uint32_t REG;
        struct
        {
            volatile uint32_t CC3S        : 2;
            volatile uint32_t IC3PSC      : 2;
            volatile uint32_t IC3F        : 4;
            volatile uint32_t CC4S        : 2;
            volatile uint32_t IC4PSC      : 2;
            volatile uint32_t IC4F        : 4;
            volatile uint32_t _reserved   : 16;
        } INPUT_BITS;

        struct
        {
            volatile uint32_t CC3S        : 2;
            volatile uint32_t OC3FE       : 1;
            volatile uint32_t OC3PE       : 1;
            volatile uint32_t OC3M        : 3;
            volatile uint32_t OC3CE       : 1;
            volatile uint32_t CC4S        : 2;
            volatile uint32_t OC4FE       : 1;
            volatile uint32_t OC4PE       : 1;
            volatile uint32_t OC4M        : 3;
            volatile uint32_t OC4CE       : 1;
            volatile uint32_t _reserved   : 16;
        } OUTPUT_BITS;
    }  CCMR2;

    union
    {
       volatile uint32_t REG;
       struct
       {
         volatile uint32_t CC1E        : 1;
         volatile uint32_t CC1P        : 1;
         volatile uint32_t CC1NE       : 1;
         volatile uint32_t CC1NP       : 1;
         volatile uint32_t CC2E        : 1;
         volatile uint32_t CC2P        : 1;
         volatile uint32_t CC2NE       : 1;
         volatile uint32_t CC2NP       : 1;
         volatile uint32_t CC3E        : 1;
         volatile uint32_t CC3P        : 1;
         volatile uint32_t CC3NE       : 1;
         volatile uint32_t CC3NP       : 1;
         volatile uint32_t CC4E        : 1;
         volatile uint32_t CC4P        : 1;
         volatile uint32_t _reserved   : 1;
         volatile uint32_t CC4NP       : 1;
         volatile uint32_t _reserved2  : 16;
       } BITS; 
    } CCER;

    volatile uint32_t CNT;
    volatile uint32_t PSC;
    volatile uint32_t ARR;
    volatile uint32_t RCR;
    volatile uint32_t CCR[4];

    union
    {
       volatile uint32_t REG;
       struct
       {
         volatile uint32_t DTG         : 8;
         volatile uint32_t LOCK        : 2;
         volatile uint32_t OSSI        : 1; 
         volatile uint32_t OSSR        : 1; 
         volatile uint32_t BKE         : 1;
         volatile uint32_t BKP         : 1;
         volatile uint32_t AOE         : 1;
         volatile uint32_t MOE         : 1;
         volatile uint32_t _reserved   : 16;
       } BITS; 
    } BDTR;

    union
    {
       volatile uint32_t REG;
       struct
       {
         volatile uint32_t DBA         : 5;
         volatile uint32_t _reserved   : 3;
         volatile uint32_t DBL         : 5;
         volatile uint32_t _reserved2  : 19;
       } BITS; 
    } DCR;

    volatile uint32_t DMAR;
} AdvTim_Typedef;
