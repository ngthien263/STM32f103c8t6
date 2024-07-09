#include "stm32f103.h"
#include "GPIO.h"

void GPIO_SetMode(volatile GPIO_Typedef *GPIOx, GPIO_PIN Pin, GPIO_MODE Mode)
{
    if(Pin < 8)
    {
        GPIOx->CRL.REG &= ~(0xF << (Pin * 4u));
        GPIOx->CRL.REG |= Mode << (Pin * 4u);
    }
    else if(Pin >= 8 )
    {
        GPIOx->CRH.REG &= ~(0xF << ((Pin - 8) * 4u));
        GPIOx->CRH.REG |= Mode << ((Pin - 8) * 4u);
    }
}

GPIO_MODE GPIO_GetMode(volatile GPIO_Typedef *GPIOx, GPIO_PIN Pin)
{
    GPIO_MODE mode = -1;
    if(Pin < 8)
    {
        mode = (GPIOx->CRL.REG >> (Pin * 4u)) & 0x0F;
    }
    else if(Pin >= 8)
    {
       mode = (GPIOx->CRH.REG >> (Pin * 4u)) & 0x0F;
    }
    return mode;
}


GPIO_PIN_state GPIO_ReadPin(volatile GPIO_Typedef *GPIOx, GPIO_PIN Pin)
{
    if(GPIOx->IDR.REG & (1<<Pin))
        return GPIO_PIN_SET;
    else if(!(GPIOx->IDR.REG & (1<<Pin)))
        return GPIO_PIN_RS;
}