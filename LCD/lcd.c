#include <16F887.h>
#DEVICE *=16 ADC=10
#FUSES HS,NOWDT,NOPUT,NOLVP
#USE DELAY(CLOCK=16M)
#include "lcd.h"

unsigned int8 i = 0;

void main(void) {
  	set_tris_a(0b10001); // RA3, RA2, RA1 is output
  	set_tris_d(0b00000000); // RD0, RD1, RD2, RD3 is output
  	set_tris_b(0b00000000); // port0 is output
  	delay_ms(20);

  	LCD_INIT();
  	delay_ms(20);

  	lcd_gotoxy(0, 0);
  	//lcd_putc(" Le Thi Nhung"); // Print name


	while(TRUE) 
	{
        for(i = 16; i > 0; i--) 
		{
            LCD_gotoxy(i, 1); 
            LCD_putc("LE THI NHUNG");
            delay_ms(500);          
            LCD_putc("\f");         
        }
    }
}