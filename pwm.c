#include <msp430g2553.h>

void delay(int n)
{
	while(n--);
}

main()
{
	int x=0;
	P1DIR = 0xa;
	while(1) {
		for (x=1; x<900; x+=5) { //increasing brightness gradually
			P1OUT = 0xa;
			delay(x);
			P1OUT = 0;
			delay(1000 - x);
		}
		for (x=900; x>5; x-=5) {//decreasing brightness gradually
			P1OUT = 0xa;
			delay(x);
			P1OUT = 0;
			delay(1000 - x);
		}
	}
}
