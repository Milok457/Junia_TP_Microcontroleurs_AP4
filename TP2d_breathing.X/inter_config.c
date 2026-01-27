//inter_config.c

#include <xc.h>

/* Configuration de l'interruption sur Timer2 */
void config_interrupts(void) {
    PIE1bits.TMR2IE = 1;
    PIR1bits.TMR2IF = 0;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    return;
}
