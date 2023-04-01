#include "l298n_dc_motor.h"

void motor_init(motor_t *motor)
{
    set_bit(motor->port_data_direction_register, motor->pwm_pin);
    set_bit(motor->port_data_direction_register, motor->input_pin_1);
    set_bit(motor->port_data_direction_register, motor->input_pin_2);

    clear_bit(motor->port_data_register, motor->input_pin_1);
    clear_bit(motor->port_data_register, motor->input_pin_2);
    (*motor->pwm_enabler)();
}

void motor_direction_set(motor_t *motor, bool value_pin_1, bool value_pin_2)
{
    if (value_pin_1)
        set_bit(motor->port_data_register, motor->input_pin_1);
    else
        clear_bit(motor->port_data_register, motor->input_pin_1);

    if (value_pin_2)
        set_bit(motor->port_data_register, motor->input_pin_2);
    else
        clear_bit(motor->port_data_register, motor->input_pin_2);
}

void motor_pwm_value_set(motor_t *motor, uint16_t pwm_value)
{
    (*motor->pwm_writer)(pwm_value);
}