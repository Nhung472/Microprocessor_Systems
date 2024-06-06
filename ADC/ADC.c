#include <16f887.h>
#device *=16 ADC=10
#FUSES HS, NOWDT, NOPUT, NOLVP
#use delay(clock=8M)
#include <lcd.h>

unsigned int16 GIA_TRI = 0;

void main()
{
    set_tris_a(0b001111); // Set RA3, RA2, RA1 as output
    set_tris_d(0); // Set all RD pins as output
    set_tris_e(0xff); // Set all RE pins as input

    lcd_init();
    lcd_putc('\f');
    lcd_gotoxy(1, 1);
    printf(lcd_putc, "Value of ADC");

    SETUP_ADC(ADC_CLOCK_INTERNAL);
    SETUP_ADC_PORTS(ALL_ANALOG);

    while (TRUE)
    {
        set_adc_channel(0); 
        delay_ms(1); 
        GIA_TRI = read_adc();

        lcd_gotoxy(1, 2);
        printf(lcd_putc, "Value ADC:%04lu", GIA_TRI);

        delay_ms(500);
    }
}
