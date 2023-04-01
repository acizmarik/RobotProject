#include "pwm.h"

void pwm_init(void)
{
    // Configure Timer1 for Fast PWM mode with a prescaler of 8
    TCCR1A |= (1 << WGM10) | (1 << WGM11) | (1 << COM1A1) | (1 << COM1B1);
    TCCR1B |= (1 << WGM12) | (1 << CS10) | (1 << CS11);
}

void pwm_clear(void)
{
    TCCR1A = 0;
    TCCR1B = 0;
    TIMSK1 = 0;
}

void pwm_enable_channel_a(void)
{
    set_bit(&DDRB, PB1);
}

void pwm_enable_channel_b(void)
{
    set_bit(&DDRB, PB2);
}

void pwm_write_channel_a(uint8_t value)
{
    OCR1A = value;
}

void pwm_write_channel_b(uint8_t value)
{
    OCR1B = value;
}