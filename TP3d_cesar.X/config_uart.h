/* 
 * File:   config_uart.h
 * Author: dibla
 *
 * Created on February 4, 2026, 2:55 PM
 */

#ifndef CONFIG_UART_H
#define	CONFIG_UART_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "xc.h"

void config_uart(void);
void uart_write (char data);
void uart_wirte_text(const char *text);
char uart_read (void);

#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_UART_H */

