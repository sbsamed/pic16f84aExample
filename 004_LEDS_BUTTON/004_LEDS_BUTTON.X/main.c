/*
 * File:   main.c
 * Author: SAMEDBASK?N
 *
 * Created on 10 ?ubat 2022 Per?embe, 18:04
 */


#include <xc.h>

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define _XTAL_FREQ 4000000

void main(void) {
    TRISA |= (2 << 1);  //a portunun 3.biti 1 oldu(input) varsayilanda 1 öylesine yazdim
    TRISB=0x00;        //b portunun hepsi output oldu (ledler yani)
    unsigned char counter=0;
    
    while(1){
        if(RA2==1 && counter<8){
            PORTB |= (1<<counter);
            counter++;
             __delay_ms(250);
    
        }
        else if(RA2==1 && counter>7){
            
            while(counter){
                PORTB &= ~( 1 << counter);
                __delay_ms(100);
                counter--;
            }
        }
    }
}
