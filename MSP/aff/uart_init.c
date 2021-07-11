/*
 * uart_init.c
 *
 *  Created on: Jul 11, 2021
 *      Author: noone
 */

#include <msp430g2553.h>
void UARTInit(void){
    P1SEL |= (BIT1 + BIT2);        //P1.1 = RXD P1.2 = TXD
    //P1SEL2 |= (BIT1 + BIT2);       //P1.1 = RXD P1.2 = TXD
    UCA0CTL1 = UCSSEL_2;           // clock source SMCLK
                                   //UCOS16 = 1 icin Baudrate ayarlari
    UCA0BR0 = 52;
    UCA0BR1 = 0;
                                   //Modulator ayari
    UCA0MCTL = 0x11;               //formule gore bkz.

    UCA0CTL1 &= ~UCSWRST;          // USCI islemleri icin UCSWRST registeri temizlendi
    IE2 |= UCA0RXIE;               // RXD kesmesi aktif edildi
}
