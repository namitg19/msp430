#include <msp430g2553.h>

void main(void) {
	WDTCTL = WDTPW + WDTHOLD;        // Stop watchdog timer
   P1DIR |= 0x41;                   // Set P1.6 (green LED) to output direction, 1 is output
   P1OUT |= 0x41;                  // Set the red LED on


// Continous mode, 8 divider, smclk clock source & while loop checking for Timer1/0_A3 interrupt flag
// Blinking two leds using two timers
#if 0
	TA0CTL = 0x0220;
	TA1CTL = 0x02e0;
	while(1) {
		while( ((TA0CTL & 0x1)==0) && ((TA1CTL & 0x1)==0))
		;
		if((TA0CTL & 0x1)!=0) { //Red led timer arrived
		TA0CTL &= ~0x01;
		P1OUT ^= 0x01;
		}
		if((TA1CTL & 0x1)!=0) { //Green led timer arrived
		TA1CTL &= ~0x01;
		P1OUT ^= 0x40;
		}
	}
#endif	

// Blink red led using up AND up/down mode (till TA0CCR)
#if 1
	TA0CTL = 0x02d0; // up mode, 8 div
//	TA0CTL = 0x02f0; // up/down mode, 8 div
	TA0CCR0 = 0xffff;
	while(1) {
		while( ((TA0CTL & 0x1)==0))
		;
		TA0CTL &= ~0x01;
		P1OUT ^= 0x01;
	}
#endif	
}
