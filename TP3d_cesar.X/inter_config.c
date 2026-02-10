//inter_config.c

#include <xc.h>

/* Configuration de l'interruption sur Timer2 */
void config_interrupts(void) {
    PIE1bits.RCIE = 1;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    return;
}
