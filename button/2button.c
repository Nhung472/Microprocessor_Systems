#include<16f887.h>
#device *=16 ADC=10
#FUSES HS, NOWDT, NOPUT, NOLVP
#use delay(clock=16M)

void Button1();
void Button2();

void main()
{
    set_tris_b(0b00000000);
    set_tris_a(0b11111111);
    set_tris_d(0b00000000);
    output_b(0x00); 
    output_low(pin_b0);
    output_low(pin_b1); 

    while(1)
    {
        if(input(pin_a3) == 0)
        {
            Button1();
        }
        if(input(pin_a4) == 0) 
        {
            Button2();
        }
    }
}

void Button1()
{
    delay_ms(50); 
    while(input(pin_a3) == 0)
    {
    }
    output_high(pin_b0);
    output_low(pin_b1); 
    delay_ms(500);
}

void Button2()
{
    delay_ms(50); 
    while(input(pin_a4) == 0)
    {
    }
    output_low(pin_b0); 
    output_high(pin_b1);
    delay_ms(500);
}
