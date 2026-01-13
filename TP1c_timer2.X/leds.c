// leds.c

#include <xc.h>

/* Initialisation des LEDS en sortie et éteintes */
void init_leds(void){
    TRISB = 0x00;
    TRISD = 0x00;
    
    LATB = 0x01;
    LATD = 0x00;
}
