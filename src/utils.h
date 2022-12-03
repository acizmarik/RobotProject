#ifndef HEADER_GUARD_UTILS_H
#define HEADER_GUARD_UTILS_H

#include "config.h"

void set_bit(volatile uint8_t *word, uint8_t bit);
void clear_bit(volatile uint8_t *word, uint8_t bit);

#endif