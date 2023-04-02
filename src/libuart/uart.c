#include "uart.h"

void uart_init(void)
{
    // Set baud rate
    // Note: values UBRRH_VALUE, UBRRL_VALUE are precalculated by util/setbaud.h
    // --- the calculation is based on F_CPU and BAUD
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

    // Enable transmitter
    UCSR0B = (1 << TXEN0);

    // Use 8 data bits, 1 stop bit
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_putchar(char data)
{
    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = data;
}

void uart_putstring(char* data)
{
    uint8_t i;
    for (i = 0; data[i] != 0; i++)
        uart_putchar(data[i]);
}