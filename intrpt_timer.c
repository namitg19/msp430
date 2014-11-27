#include <msp430g2553.h>

__attribute((interrupt(TIMER0_A1_VECTOR))) nam_tim(void) {
	P1OUT ^= 0x01;
	TA0CTL &= ~TAIFG;
}

void main(void) {
__enable_interrupt(); //start global intrpt processing
	WDTCTL = WDTPW + WDTHOLD;   
   P1DIR |= 0x01;                  
   P1OUT |= 0x01;                 

// Timer firing interrupt in continous mode, 8 divider, smclk clock source 
#if 1
	TA0CTL = 0x02e0;
	TA0CTL |= TAIE;
	while(1) ;
#endif	
}
