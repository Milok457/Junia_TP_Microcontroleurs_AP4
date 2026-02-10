#include "configbits.h" // Bits de configuration
#include <xc.h>         // Definition des registres specifiques au uC
#include "config_uart.h"
#include "inter_config.h"

#define _XTAL_FREQ 8000000


void __interrupt() isr_reception (void) {
    if(PIE1bits.RCIE && PIR1bits.RCIF) {
        PIR1bits.RCIF = 0;
        uart_read();
    }
}

void main(void) {
    /* Code d'initialisation */

    config_interrupts();
    config_uart();
    
    while(1){
        /* Code a executer dans une boucle infinie */
    }
}
