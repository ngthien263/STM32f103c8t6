#include<RCC.h>
#include<GPIO.h>

#define GPIOA_BASEADDR (ABP2_BASEADDR | 0x0800)
#define GPIOB_BASEADDR (ABP2_BASEADDR | 0x0C00)
#define GPIOC_BASEADDR (ABP2_BASEADDR | 0x1000)
#define GPIOD_BASEADDR (ABP2_BASEADDR | 0x1400)
#define GPIOE_BASEADDR (ABP2_BASEADDR | 0x1800)
#define GPIOF_BASEADDR (ABP2_BASEADDR | 0x1C00)
#define GPIOG_BASEADDR (ABP2_BASEADDR | 0x2000)
#define GPIO_offset     0x0400

#define GPIOA ((GPIO_map*)GPIOA_BASEADDR)
#define GPIOB ((GPIO_map*)GPIOB_BASEADDR)
#define GPIOC ((GPIO_map*)GPIOC_BASEADDR)
#define GPIOD ((GPIO_map*)GPIOD_BASEADDR)
#define GPIOE ((GPIO_map*)GPIOE_BASEADDR)
#define GPIOF ((GPIO_map*)GPIOF_BASEADDR)
#define GPIOG ((GPIO_map*)GPIOG_BASEADDR)

void RCC_GPIO_CLK_EN(volatile GPIO_map *GPIOx) {
    uint32_t io_port = ((uint32_t)GPIOx - (uint32_t)GPIOA_BASEADDR) / GPIO_offset;
    RCC->APB2ENR |= (1 << (io_port + 2);
}

int main()
{

}