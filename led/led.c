#include<16f887.h>
#device *=16 ADC=8
#FUSES HS, NOWDT, NOPUT, NOPROTECT, NOBROWNOUT, NOLVP
#use delay(clock=8000000)
#byte PORTB = 0x06
 
void main(){
	set_tris_b(0b10101010);
	PORTB = 0x00;
	while(true){
		PORTB = 0xff;
		delay_ms(250);
		PORTB = 0x00;
		delay_ms(250);
	}

}