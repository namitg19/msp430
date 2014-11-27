#include <msp430g2553.h>

void main(void) {
short int conv = 0;
int i = 0;
WDTCTL = WDTPW + WDTHOLD;        // Stop watchdog timer
P1DIR |= 0x40;                   // Set P1.6 (green LED) to output direction, 1 is output
P1OUT |= 0x40;               
ADC10CTL0 = ADC10CTL0 | ADC10ON; //ADC on
ADC10CTL0 = ADC10CTL0 | SREF_0; //Ref volt, Vcc & Gnd
ADC10CTL0 = ADC10CTL0 | ADC10SHT_2; //Sample & hold delay as 16 times of adc clock
ADC10CTL1 = ADC10CTL1 | INCH_0; //Using channel A0
ADC10CTL1 = ADC10CTL1 | SHS_0; //Using s/w based trigger to start adc not timer based
ADC10CTL1 = ADC10CTL1 | ADC10SSEL_0; //setting ADC clock src is internal 5mhz
ADC10CTL1 = ADC10CTL1 | ADC10DIV_0; //No adc clock division
ADC10CTL1 = ADC10CTL1 | CONSEQ_0; //Setting conversion seq
ADC10AE0 = 0x01; //Enabling analog input on A0
ADC10CTL0 = ADC10CTL0 | ENC; //Enable conversion

while (1) {
	ADC10CTL0 = ADC10CTL0 | ADC10SC; //S/w Trigger a conversation
	while ((ADC10CTL1 & ADC10BUSY) != 1)
		;
	conv = ADC10MEM;
	if (conv > 380) {
		P1OUT &= ~0x40;  //off green led on more light
	}
	else
		P1OUT |= 0x40;                 
	for (i=0; i<270; i++); //delay loop not sure why withiout it it doesn't work
	}
}
