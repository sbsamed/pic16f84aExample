/*
 * File:   main.c
 * Author: SAMEDBASK?N
 *
 * Created on 11 ?ubat 2022 Cuma, 14:42
 */


#include <xc.h>

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)


#define _XTAL_FREQ 4000000

void main(void) {
    TRISB=0x00;
    PORTB=0x00;
   unsigned char counter=0;
    while(1){
    
      while(counter<8){
       PORTB = ( 1<<counter );  
      __delay_ms(500);
      counter++;
         
      }
                         
       if(counter>7){
          while(counter<0){
                PORTB = ( 1<<counter );  
                  counter--;
                  __delay_ms(500);
          }
         
      }
    }
}
