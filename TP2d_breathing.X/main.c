#include "configbits.h" // Bits de configuration
#include <xc.h>         // Definition des registres specifiques au uC
#include "leds.h"
#include "pwm4.h"
#include "config_pps.h"
#include "inter_config.h"
#include "timer2.h"

int nbr_inter = 0;

void __interrupt() isr_allume_led (void){
    if(PIE1bits.TMR2IE && PIR1bits.TMR2IF) {
        PIR1bits.TMR2IF = 0;
        nbr_inter++;
        
        if (nbr_inter == 200) {
            nbr_inter = 0;
        }
    }
}

void main(void) {
    /* Code d'initialisation */

    init_leds();
    config_timer2();
    config_interrupts();
    config_pwm4();
    config_pps();
    
    while(1){
        /* Code a executer dans une boucle infinie */
    }
}
