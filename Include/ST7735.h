#ifndef __ST7735_H__
#define __ST7735_H__

typedef enum{
	 NOP         = 0x00,
	 SWRESET     = 0x01,
	 RDD_ID      = 0x04,
	 RDD_ST      = 0x09,
	 RDD_PM      = 0x0A,
	 RDD_MADCTL  = 0x0B,
	 RDD_COLMOD  = 0x0C,
	 RDD_IM      = 0x0D,
	 RDD_SM      = 0x0E,
	
	 SPL_IN			 = 0x10,
	 SLP_OUT 		 = 0x11,
	 PTL_ON  		 = 0x12,
	 NOR_ON	     = 0x13,
	 INV_OFF 		 = 0x20,
	 INV_ON    	 = 0x21,
	 GAMSET	 		 = 0x26,
	 DISP_OFF  	 = 0x28,
	 DISP_ON 		 = 0x29,
	 CASET 			 = 0x2A,
	 RASET 			 = 0x2B,
	 RAMWR 			 = 0x2C,
	 RAMRD			 = 0x2E,
	 
   PTLAR   		 = 0x30,
   COLMOD  		 = 0x3A,
   MADCTL  		 = 0x36,
   FRMCTR1 		 = 0xB1,
   FRMCTR2 		 = 0xB2,
   FRMCTR3 		 = 0xB3,
   INVCTR  		 = 0xB4,
   DISSET5 		 = 0xB6,
   PWCTR1  		 = 0xC0,
   PWCTR2  		 = 0xC1,
   PWCTR3  		 = 0xC2,
   PWCTR4  		 = 0xC3,
   PWCTR5  		 = 0xC4,
   VMCTR1  		 = 0xC5,
   RDID1   		 = 0xDA,
   RDID2   		 = 0xDB,
   RDID3   		 = 0xDC,
} CommandList;

#define	MADCTL_MH_LtoR		 			 0x04
#define	MADCTL_MH_RtoL	   			 0x00
#define	MADCTL_RGB				 			 0x00
#define	MADCTL_BGR				 			 0x08
#define	MADCTL_ML_TtoB		 			 0x00
#define	MADCTL_ML_BtoT		 			 0x10
#define	MADCTL_MV					 			 0x20
#define	MADCTL_MX					 			 0x40
#define	MADCTL_MY					 			 0x80
			 
#define ST7735_XSTART 		 			 26
#define ST7735_YSTART 		 			 1
#define ST7735_WIDTH 			 			 80
#define ST7735_HEIGHT 		 			 160
#define ST7735_DATA_ROTATION 	   (MADCTL_MX | MADCTL_MY | MADCTL_BGR)

#define	ST7735_BLACK   0x0000
#define	ST7735_BLUE    0x001F
#define	ST7735_RED     0xF800
#define	ST7735_GREEN   0x07E0
#define ST7735_CYAN    0x07FF
#define ST7735_MAGENTA 0xF81F
#define ST7735_YELLOW  0xFFE0  
#define ST7735_WHITE   0xFFFF

#define PIN_RESET 2 
#define PIN_DC    3 
#ifndef ST7735_NO_CS
    #define PIN_CS 4
#endif
#define SPI_SCLK 5  
#define SPI_MISO 6
#define SPI_MOSI 7  



void ST7735_Init();

#endif // __ST7735_H__