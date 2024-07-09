#include "RCC.h"

void RCC_GPIO_CLK_EN(volatile GPIO_Typedef *GPIOx) {
    uint32_t io_port = ((uint32_t)GPIOx - (uint32_t)GPIOA_BASEADDR) / (uint32_t)GPIO_offset;
    RCC->APB2ENR.REG |= (1 << (io_port + 2));
}
