#include <msp430g2553.h>
// Anode (Com takes input from Vcc) seven segment display
// For anode led lights up when a port pin is made zero (probably from there current coming from Vcc goes to ground)
int num[10]={0x77,0x24,0x5d,0x6d,0x2e,0x6b,0x7b,0x25,0x7f,0x6f};

void main(void) {
	int x,i=0;
	WDTCTL = WDTPW + WDTHOLD;        // Stop watchdog timer
	P1DIR = 0xff;
	P1OUT = 0xff;
	TA0CTL = 0x02e0;
#if 1
	while (1) {
		P1OUT = ~num[i];
		while( ((TA0CTL & 0x1)==0))
		;
		P1OUT = 0xff;
		i=(++i)%10;
		TA0CTL &= ~0x01;
	}
#endif
}
