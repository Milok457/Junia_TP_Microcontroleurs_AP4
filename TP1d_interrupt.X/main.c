#include "configbits.h" // Bits de configuration
#include <xc.h>         // Definition des registres specifiques au uC
#include "leds.h"
#include "timer2.h"
#include "inter_config.h"

int nbr_inter = 0;
int etat_led = 0;

void __interrupt() isr_changement_LED (void){
    if(PIE1bits.TMR2IE && PIR1bits.TMR2IF) {
        PIR1bits.TMR2IF = 0;
        nbr_inter++;
        if (nbr_inter == 125)
        {
            nbr_inter = 0;
            switch (etat_led) {
                case 0:
                    LATB = 0x00;
                    LATD = 0x01;
                    etat_led++;
                    break;
                case 1:
                    LATD = 0x02;
                    etat_led++;
                    break;
                case 2:
                    LATD = 0x04;
                    etat_led++;
                    break;
                case 3:
                    LATD = 0x08;
                    etat_led++;
                    break;
                case 4:
                    LATD = 0x00;
                    LATB = 0x01;
                    etat_led++;
                    break;
                case 5:
                    LATB = 0x02;
                    etat_led++;
                    break;
                case 6:
                    LATB = 0x04;
                    etat_led++;
                    break;
                case 7:
                    LATB = 0x08;
                    etat_led = 0;
                    break;
            } 
        }
    }
    return;
}

void main(void) {
    /* Code d'initialisation */
    init_leds();
    config_timer2();
    config_interrupts();
    
    while(1){
        /* Code a executer dans une boucle infinie */
    }
}
