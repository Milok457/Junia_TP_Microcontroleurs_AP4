#include "configbits.h" // Bits de configuration
#include <xc.h>         // Definition des registres specifiques au uC
#include "pwm4.h"
#include "timer2.h"
#include "leds.h"
#include "config_button.h"
#include "config_pps.h"


void main(void) {
    /* Code d'initialisation */
    
    init_leds();
    config_timer2();
    config_pwm4();
    config_pps();
    config_button();
    
    while(1){
        /* Code a executer dans une boucle infinie */
        if (PORTBbits.RB0 == 0) {   // Si le bouton S1 est appuyé
            set_pwm4_100();
        } else {
            set_pwm4_10();
        }
    }
}
