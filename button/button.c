/*include<16f887.h>    //QUOC
#device *=16 ADC=8
#FUSES HS, NOWDT, NOPUT, NOPROTECT, NOBROWNOUT, NOLVP
#use delay(clock=8000000)
#byte PORTB = 0x06

#define BUTTON_PIN PIN_A3
 
void main(){
    set_tris_b(0b00000000);
    set_tris_a(0b00001000); 
 
    while(true){
        if(input(BUTTON_PIN)) {
            PORTB = 0xFF;
        } else {
            PORTB = 0x00;
        }
    }
}*/


/*#include<16f887.h>      //THAY LAM
#device *=16 ADC=10
#FUSES HS, NOWDT, NOPUT, NOLVP
#use delay(clock=16M)
#include <luutinh.h>

void Button1();
void main()
{
	set_tris_b(0b00000000);
    set_tris_a(0b11111111); 
	set_tris_d(0b00000000);
	output_b(0x00);
	while(1)
	{
		if(input(pin_a3)==0){Button1();}
	}
}
void Button1()
{
	while(input(pin_a3)==0)
	{}
		output_high(pin_b0);
		output_low(pin_b1);
		delay_ms(500);
}*/
