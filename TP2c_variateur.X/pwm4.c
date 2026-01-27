//pwm4.c

#include <xc.h>

void config_pwm4(void) {
    PWM4CONbits.PWM4EN = 1;    // Activer PWM4
}

void set_pwm4(char valeur_adc){
    char nbr = valeur_adc/32;
    
    PWM4DCH = 15*nbr;
    PWM4DCL = 0;
}