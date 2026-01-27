#include "configbits.h" // Bits de configuration
#include <xc.h>         // Definition des registres specifiques au uC
#include "leds.h"
#include "pwm4.h"
#include "timer2.h"
#include "config_pps.h"
#include "potentiometre.h"



void main(void) {
    /* Code d'initialisation */
    
    char result;
    
    init_leds();
    config_potentio();
    config_pwm4();
    config_pps();
    config_timer2();
    
    while(1){
        /* Code a executer dans une boucle infinie */
        
        result = read_adc();
        if(result == 0){
            LATB = 0x00;            
        } else {
          set_pwm4(result); 
        } 
    }
}
