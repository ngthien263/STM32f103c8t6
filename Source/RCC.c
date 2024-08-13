#include "RCC.h"

static const uint16_t AHBpreFactorTable[16U] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};
static const uint8_t  APBpreFactorTable[8U] =  {1, 1, 1, 1, 2, 4, 8, 16};
uint32_t HSE_CLK __attribute__((weak)) = 12000000ul;
#define HSI_CLK  8000000ul
uint32_t RCC_GetSysClk()
{
    uint32_t freq ;
    if (RCC->CFGR.BITS.SWS == SWS_HSI) {
        freq = HSI_CLK;
    } 
    else if (RCC->CFGR.BITS.SWS == SWS_HSE &&  RCC->CR.BITS.HSEON == 1) {
        freq =  HSE_CLK;
    } 
    else if (RCC->CFGR.BITS.SWS == SWS_PLL && RCC->CR.BITS.PLLON == 1) {
				if(RCC->CFGR.BITS.PLLSRC){
						static const uint8_t  PLLMULFactorTable[16U] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 16};
						freq = (RCC->CFGR.BITS.PLLXTPRE) ? (HSE_CLK >> 1) : HSE_CLK;
						freq *= PLLMULFactorTable[(uint32_t)RCC->CFGR.BITS.PLLMUL];
				}
				else{
						freq = 4000000ul;
				}
    } 
    else {
        return -1;
    }
    return freq;
}

uint32_t RCC_GetHClk()
{		
    return RCC_GetSysClk()/AHBpreFactorTable[RCC->CFGR.BITS.HPRE];
}

uint32_t RCC_GetAbp1Clk()
{
    return RCC_GetHClk() / APBpreFactorTable[RCC->CFGR.BITS.PPRE1];
}

uint32_t RCC_GetAbp2Clk()
{
    return RCC_GetHClk() / APBpreFactorTable[RCC->CFGR.BITS.PPRE2];
}