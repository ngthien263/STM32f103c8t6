#include "ST7735.h"
#include "cm3.h"
#include "gpio.h"
#include "SPI.h"
#define DATA_MODE()    (GPIOA->ODR.REG |= 1 << PIN_DC)      // DC High
#define COMMAND_MODE() (GPIOA->ODR.REG &= ~(1 << PIN_DC))   // DC Low
#define RESET_HIGH()   (GPIOA->ODR.REG |= 1 << PIN_RESET)
#define RESET_LOW()    (GPIOA->ODR.REG &= ~(1 << PIN_RESET))
#ifndef ST7735_NO_CS
    #define START_WRITE() (GPIOC-> |= 1 << PIN_CS)   // CS Low
    #define END_WRITE()   (GPIOC-> |= 1 << PIN_CS)  // CS High
#else
    #define START_WRITE()
    #define END_WRITE()
#endif
void write_command(CommandList cmd)
{
	COMMAND_MODE();
	SPI_Transmit8(SPI1, (uint8_t)cmd);
}
void write_data8(uint8_t cmd)
{
	DATA_MODE();
	SPI_Transmit8(SPI1, cmd);
}
void write_data16(uint16_t cmd)
{
	DATA_MODE();
	SPI_Transmit16(SPI1, cmd);
}
void ST7735_Init()
{
	SPIInit_TypeDef SPIInit = {
		.CPha = SPI_CPHA_FIRST_TRANS,
		.CPol = SPI_CPOL_LOW,
		.Mode = SPI_OPERATE_MODE_MASTER,
		.BRDiv= SPI_BR_DIV2,
		.BitOrder = SPI_LSB_FIRST,
		.NSSMode = SPI_NSS_SOFT,
		.DataWidth = SPI_DATAWIDTH_8BIT,
		.Trans_Mode = SPI_TRANSFER_MODE_HALF_DUPLEX_TX,
	};
	SPI_Init(SPI1, &SPIInit);
	write_command(SWRESET);
	Delay_ms(150);
	write_command(SLP_OUT);
	Delay_ms(500);
  write_command(FRMCTR1);
 	write_data8(0x01);
	write_data8(0x2C);
	write_data8(0x2D);
  write_command(FRMCTR2);
 	write_data8(0x01);
	write_data8(0x2C);
	write_data8(0x2D);
	write_command(FRMCTR3);
 	write_data8(0x01);
	write_data8(0x2C);
	write_data8(0x2D);
	write_data8(0x01);
	write_data8(0x2C);
	write_data8(0x2D);
	write_command(INVCTR);
	write_data8(0x07);
	write_command(PWCTR1);
	write_data8(0xA2);
	write_data8(0x02);
	write_data8(0x84);
	write_command(PWCTR2);
	write_data8(0xC5);
	write_command(PWCTR3);
	write_data8(0x0A);
	write_data8(0x00);
	write_command(PWCTR4);
	write_data8(0x8A);
	write_data8(0x2A);
	write_command(PWCTR5);
	write_data8(0x8A);
	write_data8(0xEE);	
	write_command(VMCTR1);
	write_data8(0x0E);
	write_command(INV_OFF);
	write_command(NOR_ON);
	write_command(DISP_ON);	
	write_command(MADCTL);
	write_data8(MADCTL_MX | MADCTL_MY | MADCTL_BGR);
	write_command(COLMOD);
	write_data8(0x05);
}

void SetCursor(int x, int y)
{
	write_command(CASET);
	write_data8(0x00);
	write_data8(x + ST7735_XSTART);
	write_data8(0x00);
	write_data8(x + ST7735_XSTART + 1);
	write_command(RASET);
	write_data8(0x00);
	write_data8(y + ST7735_YSTART);
	write_data8(0x00);
	write_data8(y + ST7735_YSTART + 1);
}

