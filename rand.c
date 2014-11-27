#include <msp430g2553.h>

// Rand led blink using fibbonacy LFSR (linear feedback shift register)
main()
{
    unsigned short int start_state = 0xACE1u;  /* Any nonzero start state will work. */
    unsigned short int lfsr = start_state;
    unsigned bit;
    unsigned period = 0;
    P1DIR=0x01;
    while (1) {
            do
            {
                /* taps: 16 14 13 11; feedback polynomial: x^16 + x^14 + x^13 + x^11 + 1 */
                bit  = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
                lfsr =  (lfsr >> 1) | (bit << 15);
                ++period;
            } while (lfsr != start_state);
		P1OUT ^= 0x1;
    }

#if 0
int i=0;
unsigned int op,red,lfsr = 0xACE1;
unsigned bit;
        for(;;)
        {
                P1DIR=0x01;
                do{
                        bit=((lfsr>>0)^(lfsr>>2)^(lfsr>>3)^(lfsr>>5))&1;
                        lfsr=(lfsr>>1)|(bit<<15);
                        red=lfsr&0x0002;
                        red=red>>1;
                        op=red;
                        P1OUT=op;
                        for(i=60000;i!=0;i--);
                }while(lfsr!=0xACE1);
        }
#endif
}
