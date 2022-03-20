/*
 * File:   main.c
 * Author: SAMEDBASK?N
 *
 * Created on 09 ?ubat 2022 Çar?amba, 18:17
 */

#include <xc.h>

#pragma config FOSC = HS      // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF     // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF    // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF       // Code Protection bit (Code protection disabled)

#define _XTAL_FREQ 4000000   //harici kristal osilatör 4mhz



void main(void) {
 
    TRISB=0x00; //trisb tüm pinler output ayarland?
    
   while(1){
     
     PORTB=0x01;      //portb0 aktif oldu,ledi yak
     __delay_ms(500);
     PORTB=0x00;      //portb0 inaktif oldu,ledi söndür
     __delay_ms(500); 
    
   }
    
}
