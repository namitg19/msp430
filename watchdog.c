#include <msp430g2553.h>

#define LED1 0x01

__attribute__((interrupt(WDT_VECTOR)))
void isr()
{
	P1OUT ^= LED1;
}

//initialize watchdog as interval timer
void watchdog_init()
{
	// clk = smclk/32768, interval timer mode
	// wdt enabled (ie, WDTHOLD = 0)
	WDTCTL = /* write this! */
	IE1 = /* write this! */
}
WDTCTL = WDTPW + WDTHOLD;        // Stop watchdog timer

main()
{
	P1DIR = LED1;
}

