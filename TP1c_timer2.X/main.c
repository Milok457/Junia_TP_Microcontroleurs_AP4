#include "configbits.h" // Bits de configuration
#include <xc.h>         // Definition des registres specifiques au uC
#include "leds.h"
#include "timer2.h"

/* Attente d'environ 125ms */
void wait125ms(void) {
    int i =0;
    do {
        while(!PIR1bits.TMR2IF){}
        PIR1bits.TMR2IF = 0;
        i++;
    } while(i<125);       
}

void main(void) {
    /* Code d'initialisation */
    init_leds();
    config_timer2();
    while(1){
        /* Code a executer dans une boucle infinie */
        LATB = 0x00;
        LATD = 0x01;
        wait125ms();
        LATD = 0x02;
        wait125ms();
        LATD = 0x04;
        wait125ms();
        LATD = 0x08;
        wait125ms();
        LATD = 0x00;
        LATB = 0x01;
        wait125ms();
        LATB = 0x02;
        wait125ms();
        LATB = 0x04;
        wait125ms();
        LATB = 0x08;
        wait125ms();
    }
}
