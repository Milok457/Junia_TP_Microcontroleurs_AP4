#include "configbits.h" // Bits de configuration
#include <xc.h>         // Definition des registres specifiques au uC
#include "config_button.h"
#include "potentiometre.h"
#include "lcd.h"
#include "spi.h"
#include "config_uart.h"
#include "inter_config.h"

char alphabet[] = "0123456789abcdefghijklmnopqrstuvwxyz";
char offset = 1;    //Offset de 1
char mode = 0;      //Mise en mode chiffrement

char char_normalise (char c) {
    if(c >= 'A' && c <= 'Z'){
        c = c + ('a' - 'A');
    }
    
    for (int i=0; i<36; i++){
        if(c == alphabet[i]){
            return c;
        }
    }
    
    return 0;
}

void code_cesar (char data, char offset_choisi, char mode_choisi) {
    char caractere = char_normalise(data);      //On regarde si la data est correcte
    char index;
    char index_cesar;
    
    if(caractere !=0) {
        //Transformation de la selon l'offset et le mode
        if (mode_choisi == 0) {
            for (int i=0; i<36; i++){
                if(caractere == alphabet[i]){
                    index = i;
                }
            }            
        } else {
            for (int i=0; i<36; i++){
                if(caractere == alphabet[i]){
                    index = i;
                }
            }
        }
        index_cesar = (index + offset)%36;
        caractere = alphabet[index_cesar];
        uart_write(caractere);
    }
}

/* Interruption permettant d'afficher ce qui a été saisi par l'utilisateur */
void __interrupt() isr_reception (void) {
    if(PIE1bits.RCIE && PIR1bits.RCIF) {
        PIR1bits.RCIF = 0;
        char data = uart_read();
        code_cesar(data, offset, mode);
    }
}

void main(void) {
    /* Code d'initialisation */
    
    config_interrupts();

    config_uart();
    
    SPI_Initialize();
    LCD_InitializePins();
    
    SPI_InitializePins();
    LCD_Initialize();
    
    LCD_Clear();
    
    LCD_GoTo(0,0);
        
    config_button();
    config_potentio();
    
    uart_wirte_text("Message : \n\r");
    
    while(1){
        /* Code a executer dans une boucle infinie */
        /*  Je n'ai pas fini et le code n'est pas correct voilà pourquoi il est en commentaire
        offset = read_adc();
        
        if(PORTBbits.RB0 == 0 && mode == 0) {
            mode = 1;           //Mise en mode dechiffrement
        } else {
            if(PORTBbits.RB0 == 0 && mode == 1) {
                mode = 0;       //Mise en mode chiffrement
            }
        }
        
        LCD_WriteString(&offset);
        LCD_GoTo(1,0);
        LCD_WriteString(&mode);
         */

    }
}