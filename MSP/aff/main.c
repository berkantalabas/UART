#include <msp430g2553.h>
#include "uart_init.h"

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;            //stop watchdog timer

    BCSCTL1 = CALBC1_8MHZ;
    DCOCTL = CALDCO_8MHZ;

    UARTInit();
    P1DIR = BIT0+BIT6;
    P1OUT &= ~BIT0;
    P1OUT |= BIT6;

    __bis_SR_register(GIE);              //enable interrupts

    while (1)
    {
    }
}
#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
    if (UCA0RXBUF == 't')
    {
        P1OUT |= BIT0;
        P1OUT &= ~BIT6;

        //UCA0TXBUF == 't';
    }
    if (UCA0RXBUF == 'm')
    {
        P1OUT &= ~BIT0;

        P1OUT |= BIT6;
      //  UCA0TXBUF == 'm';
    }
}
