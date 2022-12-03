#include "utils.h"

void set_bit(volatile uint8_t *word, uint8_t bit)
{
    *word |= (_BV(bit));
}

void clear_bit(volatile uint8_t *word, uint8_t bit)
{
    *word &= ~(_BV(bit));
}