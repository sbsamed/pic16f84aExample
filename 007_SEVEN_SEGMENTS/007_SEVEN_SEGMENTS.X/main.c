/*
 * File:   main.c
 * Author: SAMEDBASK?N
 *
 * Created on 21 ?ubat 2022 Pazartesi, 13:58
 */

// PIC16F84 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ 4000000
#include <xc.h>

unsigned char sevenSegNumbers[10]={0x3F,0x06,0x5B,0x4F,0x66,
                                   0x6D,0x7C,0x07,0x7F,0x6F};
void main(void) {
    TRISB=0x00;
    while(1){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                RA0=1;
                RA1=0;
                PORTB=sevenSegNumbers[j];
                __delay_ms(100);
                 RA0=0;
                 RA1=1;
                 PORTB=sevenSegNumbers[i];
                  __delay_ms(100);
            }
        }
    }
}
