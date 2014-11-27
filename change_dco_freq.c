/* demonstrates configuration of the DCO by showing changing LED

 * flash frequency.  The LED flash uses the same delay loop, but the speed at

 * which the loop runs depends on the DCO frequency running MCLK.

 */



#include <msp430g2553.h>



#define LED1   BIT0

#define BTN1   BIT3



void delay(void);



void main(void) {

	unsigned int i;

	

	WDTCTL = WDTPW + WDTHOLD;

	

	P1OUT = 0;

	P1DIR = LED1;
P1DIR &= ~0x08;                  // Port 1 P1.3 (push button) as input, 0 is input
   P1REN |=  0x08;                  // Enable Port 1 P1.3 (push button) pull-up resistor
   P1SEL &= ~0x08;                  // Select Port 1 P1.3 (push button), 0 selects


	

	for (;;) {

		BCSCTL1 &= ~BIT3;                 // set to DCO(7,3)

		BCSCTL1 |= BIT0 + BIT1 + BIT2;

		DCOCTL &= ~BIT7;

		DCOCTL |= BIT5 + BIT6;

		

		for (i=0; i<5; i++) {             // Flash LED 5 times.

			P1OUT |= LED1;

			delay();

			P1OUT &= ~LED1;

			delay();

		}

		

		while ((P1IN&BTN1) == BTN1);      // wait for button

		

		BCSCTL1 &= ~(BIT1 + BIT2);                 // set to DCO(9,5)

		BCSCTL1 |= BIT0 + BIT3;

		DCOCTL &= ~BIT6;

		DCOCTL |= BIT5 + BIT7;

		

		for (i=0; i<5; i++) {             // Flash LED 5 times.

			P1OUT |= LED1;

			delay();

			P1OUT &= ~LED1;

			delay();

		}

		

		while ((P1IN&BTN1) == BTN1);      // wait for button



		BCSCTL1 &= ~(BIT0 + BIT2 + BIT3);                 // set to DCO(2,6)

		BCSCTL1 |= BIT1;

		DCOCTL &= ~BIT5;

		DCOCTL |= BIT6 + BIT7;

		

		for (i=0; i<5; i++) {             // Flash LED 5 times.

			P1OUT |= LED1;

			delay();

			P1OUT &= ~LED1;

			delay();

		}

		

		while ((P1IN&BTN1) == BTN1);      // wait for button

	}

} // main



void delay(void) {

	unsigned int n;

	for (n=0; n<60000; n++);

} // delay
