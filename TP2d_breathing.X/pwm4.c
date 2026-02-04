//pwm4.c

#include <xc.h>

void config_pwm4(void) {
    PWM4CONbits.PWM4EN = 1;    // Activer PWM4
}

void set_pwm4(int valeur_inter){
    if (valeur_inter < 100)
    {
        int nbr = valeur_inter;
    
        PWM4DCH = nbr*1.25;
        PWM4DCL = 0;
    } else {
        int nbr = 100-(valeur_inter-100);

        PWM4DCH = nbr*1.25;
        PWM4DCL = 0;
    }
}