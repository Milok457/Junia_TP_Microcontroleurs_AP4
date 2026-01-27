//timer2.c

#include <xc.h>

//Timer2 Registers Prescaler= 16 - TMR2 PostScaler = 10 - PR2 = 125 - Freq = 100.00 Hz - Period = 0.010000 seconds
void config_timer2(void) {
    T2CON |= 72;        // bits 6-3 Post scaler 1:1 thru 1:16
    T2CON.TMR2ON = 1;  // bit 2 turn timer2 on;
    T2CON.T2CKPS1 = 1; // bits 1-0  Prescaler Rate Select bits
    T2CON.T2CKPS0 = 0;
    PR2 = 125;         // PR2 (Timer2 Match value)
    return;
}

/*
 * //Timer2 Registers Prescaler= 1 - TMR2 PostScaler = 16 - PR2 = 125 - Freq = 1000.00 Hz - Period = 0.001000 seconds
 * T2CON |= 120;        // bits 6-3 Post scaler 1:1 thru 1:16
 * T2CON.TMR2ON = 1;  // bit 2 turn timer2 on;
 * T2CON.T2CKPS1 = 0; // bits 1-0  Prescaler Rate Select bits
 * T2CON.T2CKPS0 = 0;
 * PR2 = 125;         // PR2 (Timer2 Match value) 
*/