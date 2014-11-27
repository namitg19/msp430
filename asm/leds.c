#include <msp430g2553.h>
void main(void) {
P1DIR = 0x1;
P1OUT = 0x1;
while (1);
}
