/*
 * File:   main.c
 * Author: SAMEDBASK?N
 *
 * Created on 09 ?ubat 2022 Çar?amba, 18:08
 */


#include <xc.h>

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define _XTAL_FREQ 4000000

    

void main(void) {
    
    TRISA =0x00; //led trisA portlar?na ba?l? oldugu için bunlar? 0 yapt?k yan? output yapt?k
    PORTA =0x01;//trisA portA lar? kontrol etmektedir RA0 '? aktif ettik sadece
    while(1){
        
    }
}
