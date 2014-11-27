#include <msp430g2553.h>

//Using external button (on P2.0) to blink leds; use 1K ohms resistor with switch
//higher ohms wud not toggle the light ???
#if 0
void main(void) {
int x=0;   //Variable to capture state change of P2.0 pin
WDTCTL = WDTPW + WDTHOLD;        // Stop watchdog timer

   P1DIR |= 0x41;                   // Set P1.6 (green LED) to output direction, 1 is output
   P1OUT &= ~0x40;                  // Set the green LED off
   P1OUT |= 0x01;                  // Set the red LED on
 

   P2DIR = 0x0;                  // 0 is input
   P2REN =  0xff;                  // Enable pull-up/down resistor on P2; default is pull-up (Pxout is 1)
   P2SEL = 0x0;                  // P2 as gpio

        while( 1 ) {

       if( (P2IN & 0x01) == 0) {      // Push button down when bit0 is 0
		if (x == 0) {
          		P1OUT ^= 0x41;     //Toggle green & red leds
			x = 1;
		}      
	}
	else{
		x = 0;
	}

    }
}
#endif //Using external switch

#if 1
void main(void) {
int x=0;   //Variable to capture state change of P1.3 pin
WDTCTL = WDTPW + WDTHOLD;        // Stop watchdog timer

   P1DIR |= 0x41;                   // Set P1.6 (green LED) to output direction, 1 is output
   P1OUT &= ~0x40;                  // Set the green LED off
   P1OUT |= 0x01;                  // Set the red LED on
 

   P1DIR &= ~0x08;                  // Port 1 P1.3 (push button) as input, 0 is input
   P1OUT &= ~0x08;                  // Making resistor pull-down
   P1REN |=  0x08;                  // Enable Port 1 P1.3 (push button) pull-up/down resistor
   P1SEL &= ~0x08;                  // Select Port 1 P1.3 (push button), 0 selects

        while( 1 ) {

       if( (P1IN & 0x08) == 1) {      // Push button down when bit 3 == 0
		if (x == 0) {
          		P1OUT ^= 0x41;     //Toggle green & red leds
			x = 1;
		}      
	}
	else{
		x = 0;
	}

    }
}
#endif
