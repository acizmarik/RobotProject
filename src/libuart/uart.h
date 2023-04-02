#ifndef HEADER_GUARD_UART_H
#define HEADER_GUARD_UART_H

#include "config.h"
#include "utils.h"
#include <util/setbaud.h>

void uart_init(void);
void uart_putchar(char c);
void uart_putstring(char* data);

#endif