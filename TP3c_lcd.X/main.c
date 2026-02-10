#include "configbits.h" // Bits de configuration
#include <xc.h>         // Definition des registres specifiques au uC
#include "lcd.h"
#include "spi.h"

void main(void) {
    /* Code d'initialisation */

    SPI_Initialize();
    LCD_InitializePins();
    
    SPI_InitializePins();
    LCD_Initialize();
    
    LCD_Clear();
    
    LCD_GoTo(0,0);
    
    LCD_WriteString("Hello, World !");
    
    while(1){
        /* Code a executer dans une boucle infinie */
    }
}
