// leds.c

#include <xc.h>

/* Initialisation des LEDS en sortie et eteintes */
void init_leds(void){
    TRISB = 0x00;
    TRISD = 0x00;
    
    LATB = 0x00;
    LATD = 0x00;
}
