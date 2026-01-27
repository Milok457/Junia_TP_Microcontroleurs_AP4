#include <xc.h>

//config_pps.c

/* Configurer le PPS sur PWM4OUT */
void config_pps(void) {
    RD0PPS = 15;
}