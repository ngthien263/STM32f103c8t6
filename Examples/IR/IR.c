#include <stm32f103.h>
#include <cortex-m3.h>
typedef enum
{
    IDLE                   = 0,
    START_TRIGGER          = 1,
    WAIT_FALL              = 2,
    WAIT_RISE              = 3,
    WAIT_DATA_FALL         = 4,
    WAIT_DATA_RISE         = 5,
    STANDBY                = 6,   
    ERROR                  = 7             
}IRstate;

typedef struct {
  IRstate State;
  unsigned char Logic;
  unsigned char Count;
} IR_Typedef;

IR_Typedef IR = {IDLE, 0, 0};

// SysTick interrupt handler
void Systick_Handler() {
    if(IR.State != GPIOA->IDR.BITS.IDR5)
    {
        IR.State = GPIOA->IDR.BITS.IDR5;
        switch(IR.State)
        {
            case IDLE:

                break;
        }
    } else
    {
        IR.Count++;
        if(IR.Count > 200)
        {
            if(IR.Logic)
                IR.State = IDLE;
            else
                IR.State = ERROR;
        }
    }
}
// Main function
void main() {
    RCC_GPIO_CLK_EN(GPIOA);
    GPIOA->ODR.BITS.ODR5 = 1;
    GPIO_SetMode(GPIOA, 5, GPIO_INPUT_MODE_PuPd);
    IR.Logic = GPIOA->IDR.BITS.IDR5;
    while (1) {

    }
}
