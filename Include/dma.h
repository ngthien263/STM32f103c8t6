#ifndef _DMA_H_
#define _DMA_H_
#include <stdint.h>
#define DMA1            ((DMA_TypeDef*)0x40020000)
typedef struct
{
  union
  {
    volatile uint32_t REG;
    struct
    {
      volatile uint32_t EN          : 1;
      volatile uint32_t TCIE        : 1;
      volatile uint32_t HTIE        : 1;
      volatile uint32_t TEIE        : 1;      
      volatile uint32_t DIR         : 1;      
      volatile uint32_t CIRC        : 1;      
      volatile uint32_t PINC        : 1;      
      volatile uint32_t MINC        : 1;      
      volatile uint32_t PSIZE       : 2;      
      volatile uint32_t MSIZE       : 2;
      volatile uint32_t PL          : 2;
      volatile uint32_t MEM2MEM     : 1;
      volatile uint32_t _reserved   : 17;
    } BITS;
  } CCR;
  volatile uint32_t CNDTR;                   //16 bit low is used
  volatile uint32_t CPAR;
  volatile uint32_t CMAR;
} DMAChannel_TypeDef;

typedef struct
{
  union
  {
    volatile uint32_t REG;
    struct
    {
      const volatile uint32_t  GIF1       : 1;
      const volatile uint32_t TCIF1       : 1;
      const volatile uint32_t HTIF1       : 1;
      const volatile uint32_t TEIF1       : 1;
      const volatile uint32_t  GIF2       : 1;
      const volatile uint32_t TCIF2       : 1;
      const volatile uint32_t HTIF2       : 1;
      const volatile uint32_t TEIF2       : 1;      
      const volatile uint32_t  GIF3       : 1;
      const volatile uint32_t TCIF3       : 1;
      const volatile uint32_t HTIF3       : 1;
      const volatile uint32_t TEIF3       : 1;      
      const volatile uint32_t  GIF4       : 1;
      const volatile uint32_t TCIF4       : 1;
      const volatile uint32_t HTIF4       : 1;
      const volatile uint32_t TEIF4       : 1;      
      const volatile uint32_t  GIF5       : 1;
      const volatile uint32_t TCIF5       : 1;
      const volatile uint32_t HTIF5       : 1;
      const volatile uint32_t TEIF5       : 1;      
      const volatile uint32_t  GIF6       : 1;
      const volatile uint32_t TCIF6       : 1;
      const volatile uint32_t HTIF6       : 1;
      const volatile uint32_t TEIF6       : 1;      
      const volatile uint32_t  GIF7       : 1;
      const volatile uint32_t TCIF7       : 1;
      const volatile uint32_t HTIF7       : 1;
      const volatile uint32_t TEIF7       : 1;
      const volatile uint32_t _reserved   : 4;
    } BITS;
  } ISR;
	union
  {
    volatile uint32_t REG;
    struct
    {
      volatile uint32_t CGIF1       : 1;
      volatile uint32_t CTCIF1      : 1;
      volatile uint32_t CHTIF1      : 1;
      volatile uint32_t CTEIF1      : 1;
      volatile uint32_t CGIF2       : 1;
      volatile uint32_t CTCIF2      : 1;
      volatile uint32_t CHTIF2      : 1;
      volatile uint32_t CTEIF2      : 1;      
      volatile uint32_t CGIF3       : 1;
      volatile uint32_t CTCIF3      : 1;
      volatile uint32_t CHTIF3      : 1;
      volatile uint32_t CTEIF3      : 1;      
      volatile uint32_t CGIF4       : 1;
      volatile uint32_t CTCIF4      : 1;
      volatile uint32_t CHTIF4      : 1;
      volatile uint32_t CTEIF4      : 1;      
      volatile uint32_t CGIF5       : 1;
      volatile uint32_t CTCIF5      : 1;
      volatile uint32_t CHTIF5      : 1;
      volatile uint32_t CTEIF5      : 1;      
      volatile uint32_t CGIF6       : 1;
      volatile uint32_t CTCIF6      : 1;
      volatile uint32_t CHTIF6      : 1;
      volatile uint32_t CTEIF6      : 1;      
      volatile uint32_t CGIF7       : 1;
      volatile uint32_t CTCIF7      : 1;
      volatile uint32_t CHTIF7      : 1;
      volatile uint32_t CTEIF7      : 1;
      volatile uint32_t _reserved   : 4;
    } BITS;
  } IFCR;
	
  DMAChannel_TypeDef Channel_1, Channel_2, Channel_3, Channel_4, Channel_5, Channel_6, Channel_7;
	
} DMA_TypeDef;



//#define DMA_ADC1        DMA1.Channel_1
//#define DMA_TIM2_CH3    DMA1.Channel_1
//#define DMA_TIM4_CH1    DMA1.Channel_1

//.....

#endif