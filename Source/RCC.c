#include<RCC.h>
#include<GPIO.h>

void RCC_GPIO_CLK_EN(uint32_t GPIO_BASEADDR) {
    if(GPIO_BASEADDR == GPIOA_BASEADDR){
        RCC->APB2ENR.BITS.IOPAEN = 1;
    }
    else if(GPIO_BASEADDR == GPIOB_BASEADDR){
        RCC->APB2ENR.BITS.IOPBEN = 1;
    }
    else if(GPIO_BASEADDR == GPIOC_BASEADDR){
        RCC->APB2ENR.BITS.IOPCEN = 1;
    }
    else if(GPIO_BASEADDR == GPIOD_BASEADDR){
        RCC->APB2ENR.BITS.IOPDEN = 1;
    }
    else if(GPIO_BASEADDR == GPIOE_BASEADDR){
        RCC->APB2ENR.BITS.IOPEEN = 1;
    }
    else if(GPIO_BASEADDR == GPIOF_BASEADDR){
        RCC->APB2ENR.BITS.IOPFEN = 1;
    }
    else if(GPIO_BASEADDR == GPIOG_BASEADDR){
        RCC->APB2ENR.BITS.IOPGEN = 1;
    }
}

int main()
{

}