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
		delay_ms(100);
		for (j=0;j<=9;j++)
		{
		output_d(~led7[j]);
		delay_ms(100);
		}
	}
}
}