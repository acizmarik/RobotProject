#ifndef HEADER_GUARD_PWM_H
#define HEADER_GUARD_PWM_H

#include "config.h"
#include "utils.h"

void pwm_init(void);
void pwm_clear(void);
void pwm_enable_channel_a(void);
void pwm_enable_channel_b(void);
void pwm_write_channel_a(uint8_t value);
void pwm_write_channel_b(uint8_t value);

#endif