#include<stdint.h>
#include <C:\Users\Thien\Desktop\STM32f103c8t6\Include\GPIO.h>

typedef enum {
    PIN0 , PIN1 ,PIN2 , PIN3 , PIN4 , PIN5 , PIN6 , PIN7 ,PIN8 , PIN9 , PIN10, PIN11, PIN12, PIN13, PIN14, PIN15
} GPIO_PIN;
typedef enum
{
    GPIO_PIN_RS,
    GPIO_PIN_SET
}GPIO_PIN_state;
static inline void GPIO_SetMode(volatile GPIO_map *GPIOx, GPIO_PIN Pin, GPIO_MODE Mode)
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

static inline GPIO_MODE GPIO_GetMode(volatile GPIO_map *GPIOx, GPIO_PIN Pin)
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

static inline void GPIO_SetPin(volatile GPIO_map *GPIOx, GPIO_PIN Pin)
{
    GPIOx->BSRR.REG |= (1<<Pin);
}

static inline void GPIO_ResetPin(volatile GPIO_map *GPIOx, GPIO_PIN Pin)
{
    GPIOx->BSRR.REG &= ~(1<<(Pin + 16);
}

static inline void GPIO_TogglePin(volatile GPIO_map *GPIOx, GPIO_PIN Pin)
{
    GPIOx->ODR.REG ^= (1<<Pin);              
}

GPIO_PIN_state GPIO_ReadPin(volatile GPIO_map *GPIOx, GPIO_PIN Pin)
{
    GPIO_PIN_state state = GPIO_PIN_RS;
    if(GPIOx->IDR.REG & (1<<Pin))
        state = GPIO_PIN_SET;
    return state;
}