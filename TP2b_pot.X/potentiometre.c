//potentiometre.c

#include <xc.h>

/* Configuration de l'ADC sur AN0 (potentiometre) et en marche */
void config_potentio(void) {
    ADCON0bits.CHS = 0;
    ADCON0bits.ADON = 1;
    ADCON1bits.ADFM = 0;
}

char read_adc(void) {
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO){}
    return ADRESH;
}