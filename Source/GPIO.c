#include<stdint.h>
#include<GPIO.h>

void GPIO_Init(volatile GPIO_map *GPIOx, GPIO_PIN Pin, GPIO_MODE Mode)
{
    if(Pin < 0x1C)
    {
        GPIOx->CRL.REG &= ~(0xF << (Pin * 4));
        GPIOx->CRL.REG |= Mode << (Pin * 4);
    }
    else if(Pin > 0x1C )
    {
        GPIOx->CRH.REG &= ~(0xF << (Pin * 4));
        GPIOx->CRH.REG |= Mode << (Pin * 4);
    }
}

