#include "configbits.h" // Bits de configuration
#include <xc.h>         // Definition des registres specifiques au uC
#include "leds.h"
#include "potentiometre.h"

void allume_led(char valeur_adc){
    char nbr = valeur_adc/32;
    
    LATB = 0x00;
    LATD = 0x00;
    
    if (nbr < 4) {
        LATD = ((char)1 << nbr);
    } else {
        LATB = ((char)1 << (nbr - 4));
    }
}

void main(void) {
    /* Code d'initialisation */
    
    char result;
    
    init_leds();
    config_potentio();

    while(1){
        /* Code a executer dans une boucle infinie */
        result = read_adc();
        allume_led(result);
    }
}