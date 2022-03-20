/*
 * File:   main.c
 * Author: SAMEDBASK?N
 *
 * Created on 24 ?ubat 2022 Per?embe, 14:03
 */


// CONFIG
#pragma config FOSC = XT     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#include <xc.h>
#define _XTAL_FREQ 4000000

void main(void) {
    
    OPTION_REG |= (1<<6); //yükselen kenar interrup
    INTCON |= (1 << 7); //global interrup aktif edildi "GIE"
    INTCON |= (1 << 3); // portb kesmesi RBIE aktif edildi
            
    TRISA &= ~(1 << 0); //porta 0.bit +5v led
    PORTA &= ~( 1<<0 ); //kesme ledi hep sönük kals?n
    TRISB = 0xF0; //portb 1.bit +5v led
   
    while(1){
       
        PORTB |=(1 << 1); //led 100 ms yans?n
        __delay_ms(200);
        PORTB &= ~(1 << 1); // led 100 ms sönsün
        __delay_ms(200);
    }
}

void  __interrupt ()KESME(void){
    GIE=0; //ba?ka interrup gelmesin diye 0 lad?k
    if( (INTCON & (0x01)) & ( PORTB & (1<<4)) | (RB5==1) | (RB6==1 )| (RB7==1) ){
        PORTA |=( 1<<0 );
        __delay_ms(2000);
         
    }
     RBIF=0;//RBIF bayrag?n? tekrar 0 yapt?k
     GIE=1; //global interrupt? tekrar açt?k
    
}