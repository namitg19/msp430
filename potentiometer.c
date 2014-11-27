#include <msp430g2553.h>

//Prog to display numbers on 7 seg display based on inputs of potentiometer
#if 1 
int num[10]={0x77,0x24,0x5d,0x6d,0x2e,0x6b,0x7b,0x25,0x7f,0x6f};
void main(void) {
short int conv = 0;
int i = 0;
WDTCTL = WDTPW + WDTHOLD;        // Stop watchdog timer
P1DIR |= 0x7f;
P1OUT |= 0x7f;
ADC10CTL0 = ADC10CTL0 | ADC10ON; //ADC on
ADC10CTL0 = ADC10CTL0 | SREF_0; //Ref volt, Vcc & Gnd
ADC10CTL0 = ADC10CTL0 | ADC10SHT_2; //Sample & hold delay as 16 times of adc clock
ADC10CTL1 = ADC10CTL1 | INCH_7; //Using channel A7
ADC10CTL1 = ADC10CTL1 | SHS_0; //Using s/w based trigger to start adc not timer based
ADC10CTL1 = ADC10CTL1 | ADC10SSEL_0; //setting ADC clock src is internal 5mhz
ADC10CTL1 = ADC10CTL1 | ADC10DIV_0; //No adc clock division
ADC10CTL1 = ADC10CTL1 | CONSEQ_0; //Setting conversion seq
ADC10AE0 = BIT7; //Enabling analog input on A7
ADC10CTL0 = ADC10CTL0 | ENC; //Enable conversion

while (1) {
	ADC10CTL0 = ADC10CTL0 | ADC10SC; //S/w Trigger a conversation
	while ((ADC10CTL1 & ADC10BUSY) != 1)
		;
	conv = ADC10MEM;
	if (conv < 100)
		P1OUT = ~num[0];
	if ( (conv >= 100) && (conv < 200))
		P1OUT = ~num[1];
	if ( (conv >= 200) && (conv < 300))
		P1OUT = ~num[2];
	if ( (conv >= 300) && (conv < 400))
		P1OUT = ~num[3];
	if ( (conv >= 400) && (conv < 500))
		P1OUT = ~num[4];
	if ( (conv >= 500) && (conv < 600))
		P1OUT = ~num[5];
	if ( (conv >= 600) && (conv < 700))
		P1OUT = ~num[6];
	if ( (conv >= 700) && (conv < 800))
		P1OUT = ~num[7];
	if ( (conv >= 800) && (conv < 900))
		P1OUT = ~num[8];
	if ( (conv >= 900) && (conv < 1050))
		P1OUT = ~num[9];
	for (i=0; i<270; i++); //delay loop not sure why withiout it it doesn't work
	}
}
#endif //End of 7 deg display

//Prog to glow a led based on inputs of potentiometer
#if 0 
void main(void) {
short int conv = 0;
int i = 0;
WDTCTL = WDTPW + WDTHOLD;        // Stop watchdog timer
P1DIR |= 0x40;                   // Set P1.6 (green LED) to output direction, 1 is output
P1OUT |= 0x40;               
ADC10CTL0 = ADC10CTL0 | ADC10ON; //ADC on
ADC10CTL0 = ADC10CTL0 | SREF_0; //Ref volt, Vcc & Gnd
ADC10CTL0 = ADC10CTL0 | ADC10SHT_2; //Sample & hold delay as 16 times of adc clock
ADC10CTL1 = ADC10CTL1 | INCH_7; //Using channel A7
ADC10CTL1 = ADC10CTL1 | SHS_0; //Using s/w based trigger to start adc not timer based
ADC10CTL1 = ADC10CTL1 | ADC10SSEL_0; //setting ADC clock src is internal 5mhz
ADC10CTL1 = ADC10CTL1 | ADC10DIV_0; //No adc clock division
ADC10CTL1 = ADC10CTL1 | CONSEQ_0; //Setting conversion seq
ADC10AE0 = BIT7; //Enabling analog input on A7
ADC10CTL0 = ADC10CTL0 | ENC; //Enable conversion

while (1) {
	ADC10CTL0 = ADC10CTL0 | ADC10SC; //S/w Trigger a conversation
	while ((ADC10CTL1 & ADC10BUSY) != 1)
		;
	conv = ADC10MEM;
	if (conv > 110) {
		P1OUT &= ~0x40;  //off green led on more light
	}
	else
		P1OUT |= 0x40;                 
	for (i=0; i<270; i++); //delay loop not sure why withiout it it doesn't work
	}
}
#endif
