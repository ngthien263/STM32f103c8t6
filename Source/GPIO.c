#include<stdint.h>
#include <C:\Users\Thien\Desktop\STM32f103c8t6\Include\GPIO.h>

static inline void GPIO_SetMode(volatile GPIO_map *GPIOx, GPIO_PIN Pin, GPIO_MODE Mode)
{
    if(Pin < 0x1C)
    {
        GPIOx->CRL.REG &= ~(0xF << (Pin * 4u));
        GPIOx->CRL.REG |= Mode << (Pin * 4u);
    }
    else if(Pin > 0x1C )
    {
        GPIOx->CRH.REG &= ~(0xF << (Pin * 4u));
        GPIOx->CRH.REG |= Mode << (Pin * 4u);
    }
}

static inline void GPIO_GetMode(volatile GPIO_map *GPIOx, GPIO_PIN Pin)
{
    GPIO_MODE mode = -1;
    if(Pin < 0x1C)
    {
        mode = (GPIOx->CRL.REG >> (Pin * 4u)) & 0x0F;
    }
    else if(Pin > 0x1C )
    {
       mode = (GPIOx->CRH.REG >> (Pin * 4u)) & 0x0F;
    }
    return mode;
}

