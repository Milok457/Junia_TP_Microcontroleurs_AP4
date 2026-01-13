#include "configbits.h" // Bits de configuration
#include <xc.h>         // Definition des registres specifiques au uC
#include "leds.h"


void delai_approx(void) {
    /* Code pour le delai d'allumage entre les differentes LEDS */
    long int i=0;
    while(i<20000)
    {
        i=i+1;
    }
}

void main(void) {
    
    init_leds();
    
    while(1){
        /* Code a executer dans une boucle infinie */
        delai_approx();
        LATB = 0x0F;
        LATD = 0x00;

        delai_approx();
        LATB = 0x00;
        LATD = 0x0F;
    }
}