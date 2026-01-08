#include "configbits.h" // Bits de configuration
#include <xc.h>         // Definition des registres specifiques au uC


void delai_approx(void) {
    /* Code pour le delai d'allumage entre les differentes LEDS */
    /* Il faut exectuer environ 2 millions de fois une instruction */
    long int i=0;
    while(i<20000)
    {
        i=i+1;
    }
}

void main(void) {
    /* Code d'initialisation */
    TRISB = 0x00;
    TRISD = 0x00;
    
    LATB = 0x00;
    LATD = 0x00;    
    
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