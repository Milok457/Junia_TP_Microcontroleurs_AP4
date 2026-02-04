//config_uart.c

#include <xc.h>

void config_uart() {
    /* Configuration des pins de reception et de transmission */
    RC6PPS = 0b10100;
    RXPPS = 0b10111;
    
    /* Configuration des pins via des registres */
    TRISCbits.TRISC6 = 0;   //Sortie
    TRISCbits.TRISC7 = 1;   //Entree
    ANSELCbits.ANSC6 = 0;   //Numerique
    ANSELCbits.ANSC7 = 0;   //Numerique
    LATCbits.LATC6 = 1;     //Initialisation etat haut
    LATCbits.LATC7 = 1;     //Initialisation etat haut
    
    /* Configuration de la vitesse de transmission à 9600 bauds */
    TX1STAbits.SYNC = 0;
    TX1STAbits.BRGH = 0;
    BAUD1CONbits.BRG16 = 0;
    SP1BRGH = 0;
    SP1BRGL = 12;
    
    /* Activation du module EUSART */
    RC1STAbits.SPEN = 1;
    TX1STAbits.TXEN = 1;
    RC1STAbits.CREN = 1;
}

/* Fonction envoyant 1 seul caractere */
void uart_write (char data) {
    while(!TX1STAbits.TRMT);
    TX1REG = data;
}

void uart_wirte_text(const char *text) {
    while(*text) {
        uart_write(*text++);
    }
}