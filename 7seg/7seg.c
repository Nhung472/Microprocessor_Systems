/*turn on number 1
#include <16F887.h>
#DEVICE *= 16 ADC = 10
#FUSES HS, NOWDT, NOPUT, NOLVP
#USE DELAY(CLOCK = 8M)

void main() {
    set_tris_b(0b00000000);
    output_a(0b00000000);
    output_b(0b11111001); 
}*/

/*turn on number 0
#include <16F887.h>
#DEVICE *= 16 ADC = 10
#FUSES HS, NOWDT, NOPUT, NOLVP
#USE DELAY(CLOCK = 8M)

void main() {
    set_tris_b(0b00000000);
    output_a(0b00000000);
    output_b(0b11000000); 
}*/

/*turn on from 9-1
#include <16F887.h>
#DEVICE *=16 ADC=10
#FUSES HS,NOWDT,NOPUT,NOLVP
#USE DELAY(CLOCK=8M)

const char led7[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void main()
{		
	int i;
    set_tris_b(0b00000000);
    set_tris_a(0b00000000);
    output_a(0b00000111);
 	
	while(true){
		 for(i = 9; i >= 1;)
        {
            output_a(0b00001000); 
            output_b(~led7[i]);   
            delay_ms(500);
            i = i - 1;
        }
	}
}*/

#include <16f887.h>
#DEVICE *=16 ADC=8
#FUSES NOWDT, HS, NOPUT, NOBROWNOUT, NOPROTECT, NOLVP
#USE delay(clock=8000000)
char led7[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void main()
{
	int i;
	int j;
	set_tris_b(0b00000000);
	set_tris_d(0b00000000);
	set_tris_a(0b00000000);
	output_a(0b00001000);
	output_d(0b00001000);
	while(1)
	{
		for (i = 0; i <= 9; i++){
			output_b(~led7[i]);
			delay_ms(250);
			for (j=0;j<=9;j++)
			{
			output_d(~led7[j]);
			delay_ms(250);
			}
		}
	}
}