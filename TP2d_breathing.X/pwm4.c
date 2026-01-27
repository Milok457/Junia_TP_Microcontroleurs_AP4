//pwm4.c

#include <xc.h>

void config_pwm4(void) {
    PWM4CONbits.PWM4EN = 1;    // Activer PWM4
}

void set_pwm4(int valeur_inter){
    int nbr = valeur_inter;
    
    PWM4DCH = nbr*31;
    PWM4DCL = 0;
}

