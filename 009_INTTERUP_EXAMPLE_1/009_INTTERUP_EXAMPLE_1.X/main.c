
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)
#define _XTAL_FREQ 4000000
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

void main(void) {
    TRISB &= ~(1 << 7);//led output oldu
    INTCON |= (1 << 4 ); //interrup aktif edildi "INTE"
    OPTION_REG |= (1 << 6 ); //y�kselen kenar interrup ayarland?
    INTCON |= (1 << 7 ); //global interrup aktif edildi "GIE"
    
    while(1){
        PORTB &= ~(1 << 7);//led s�rekli olarak s�n�k halde
        
    }
}

void __interrupt() KESME(void){ // kesme fonksiyonu
    
     GIE=0;// interrupa girdi?imiz i�in ba?ka interrup almamak i�in kapatt?k
    if( INTF==1 ){ // harici kesme al?p almad?g?n? kontrol ediyoruz interrup kontorol� belki ba?ka kesme geldi o y�zden
       
        PORTB |= (1 << 7);
        __delay_ms(1000);
    }
      INTF=0; // interrup bayrag?n? 0 yapt?k intteruptan �?kt?k
      GIE=1;// interruptan �?kt???m?z i�in global interrupu tekrar aktif ettik
} 


