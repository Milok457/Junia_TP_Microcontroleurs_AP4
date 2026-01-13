//timer2.c

#include <xc.h>

/* Configuration du timer2 avec une période de 1 ms */
void config_timer2(void) {
    PR2 = 124;
    T2CONbits.T2CKPS  = 00;
    T2CONbits.T2OUTPS = 0b1111;
    T2CONbits.TMR2ON  = 1;
    return;
}
