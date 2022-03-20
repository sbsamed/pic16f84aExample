/*
 * File:   main.c
 * Author: SAMEDBASK?N
 *
 * Created on 10 ?ubat 2022 Per?embe, 15:57
 */


#include <xc.h>
        
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define _XTAL_FREQ 4000000

void main(void) {
    
    
    TRISA = ( 2 << 0 );//2 bit sola shift et ve oraya 0 yaz;
    TRISB = ( 1 << 1 );//1 bit sola shift et ve oraya 1 yaz;//varsay?lan olarak da 1 ama yine de yazdik
   
    while(1){
        if(RB1==1){
            //butona basildi
            PORTA |= ( 2 << 1 ); //portAn?n 2.bitini yani RA2 1 yap?ld? +5v
            
        }
        else{
            //butondan el çekildi
            PORTA = ( 2 << 0 ); //portBnin 2.bitini yani RA2 0 yap?ld? 0v
        }
    }
}
