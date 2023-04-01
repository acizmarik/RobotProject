#ifndef HEADER_GUARD_L298N_DC_MOTOR_H
#define HEADER_GUARD_L298N_DC_MOTOR_H

#include "config.h"
#include "utils.h"

typedef void (*pwm_enabler)(void);
typedef void (*pwm_writer)(uint8_t);

typedef struct motor_t
{
    volatile uint8_t *port_data_register;
    volatile uint8_t *port_data_direction_register;
    uint8_t input_pin_1;
    uint8_t input_pin_2;
    uint8_t pwm_pin;
    pwm_enabler pwm_enabler;
    pwm_writer pwm_writer;
} motor_t;

void motor_init(motor_t *motor);
void motor_direction_set(motor_t *motor, bool value_pin_1, bool value_pin_2);
void motor_pwm_value_set(motor_t *motor, uint16_t pwm_value);

#endif