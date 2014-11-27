#include <msp430g2553.h>

//Simple blinking a led 

void main(void) {
int x;
WDTCTL = WDTPW + WDTHOLD;        // Stop watchdog timer
   P1DIR |= 0x1;
   P1OUT |= 0x1;
#if 1
while (1) {
for (x=1; x<19000; x+=1);
   P1OUT ^= 0x1;
}
#endif
}
