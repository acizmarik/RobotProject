#ifndef HEADER_GUARD_CONFIGURATION_H
#define HEADER_GUARD_CONFIGURATION_H

#include <inttypes.h>
#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define NULL ((void*)0)

// DDRB
//    - maps to D8 - D13 (the two high bits 6,7 are not usable)
//    - data direction register (WRITE)
//    - pinMode
// PORTB
//    - port data register (WRITE)
//    - digitalWrite
// PINB
//    - port data register (READ)
//    - digitalRead

// DDRC
//    - maps to A0 - A5 (pins 6,7 are not accessible)
//    - data direction register (WRITE)
//    - pinMode
// PORTC
//    - port data register R/W
//    - digitalWrite
// PINC
//    - port data register (READ)
//    - digitalRead

// DDRD
//    - maps to D0 - D7
//    - data direction register (WRITE)
//    - pinMode
// PORTD
//    - port data register (WRITE)
//    - digitalWrite
// PIND
//    - port data register (READ)
//    - digitalRead

#endif