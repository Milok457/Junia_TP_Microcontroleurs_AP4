//config_button.c

#include <xc.h>

/* Configuration du button S1 en entrée */
void config_button(void) {
    ANSELBbits.ANSB0 = 0b0;     //Mise en mode numerique
    TRISBbits.TRISB0 = 0b1;     //Mise en mode entree
}
