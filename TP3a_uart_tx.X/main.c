#include "configbits.h" // Bits de configuration
#include <xc.h>         // Definition des registres specifiques au uC
#include "config_uart.h"

#define _XTAL_FREQ 8000000

void main(void) {
    /* Code d'initialisation */
    
    config_uart();
    
    while(1){
        /* Code a executer dans une boucle infinie */
        //Appel de la fonction pour afficher le message
        uart_wirte_text("Hello, World !\n\r");
        //Attendre 1s
        __delay_ms(1000);
    }
}
