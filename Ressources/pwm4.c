//pwm4.c

#include <xc.h>

void config_pwm4(void) {
    PWM4CONbits.PWM4EN = 1;    // Activer PWM4
}

/* Mise de la PWM4 à un rapport cyclique de 10% */
void set_pwm4_10(void){
    PWM4DCH = 12;              // Rapport cyclique (poids fort) : 25
    PWM4DCL = 0;               // Rapport cyclique (poids faible) : 0
                               // Soit rapport cyclique = [(12 << 2) + 0] / 4(124+1) = 0.1
}

/* Mise de la PWM4 à un rapport cyclique de 100% */
void set_pwm4_100(void){
    PWM4DCH = 124;              // Rapport cyclique (poids fort) : 124
    PWM4DCL = 0;                // Rapport cyclique (poids faible) : 0
                                // Soit rapport cyclique = [(124 << 2) + 0] / 4(124+1) = 1 
}


