#include <C:\Users\Thien\Desktop\STM32f103c8t6\Include\cortex-m3.h>

void NVIC_EnableIRQ(IRQn_Type IRQn)
{
    NVIC->ISER[(uint32_t)IRQn >> 5ul] |= (1ul<<(IRQn & 0x1F));
}

void NVIC_DisableIRQ(IRQn_Type IRQn)
{
    NVIC->ICER[(uint32_t)IRQn >> 5ul] |= (1ul<<(IRQn & 0x1F));
}