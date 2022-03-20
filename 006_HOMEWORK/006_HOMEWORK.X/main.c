/*
 * File:   main.c
 * Author: Samed
 *
 * Created on 20 ?ubat 2022 Pazar, 18:40
 */


// PIC16F84 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define _XTAL_FREQ 4000000
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

unsigned char sevenSegmentNumber[10]={0x3F,0x06,0x5B,0x4F,0x66,
                                      0x6D,0x7C,0x07,0x7F,0x6F};

void main(void) {
    TRISB=0x00;
    TRISA |= ( 1<<3 ); 
    unsigned char counter=0;
    while(1){
        if( RB3==1 ){
            if(counter==9){
                counter=0;
                PORTB=sevenSegmentNumber[counter];
                 counter=0;
            }
         PORTB=sevenSegmentNumber[counter];
         counter++;
           
        }
    }
}
