#include "l298n_dc_motor.h"

void motor_init(motor_t *motor)
{
    // Configure all pins as OUTPUT
    set_bit(motor->port_data_direction_register, motor->pwm_pin);
    set_bit(motor->port_data_direction_register, motor->input_pin_1);
    set_bit(motor->port_data_direction_register, motor->input_pin_2);

    // Set initial values (turned off)
    clear_bit(motor->port_data_register, motor->input_pin_1);
    clear_bit(motor->port_data_register, motor->input_pin_2);
}

void motor_direction_set(motor_t *motor, bool value_pin_1, bool value_pin_2)
{
    // Set input_pin_1 as HIGH/LOW, based on provided arguments
    if (value_pin_1)
        set_bit(motor->port_data_register, motor->input_pin_1);
    else
        clear_bit(motor->port_data_register, motor->input_pin_1);

    // Set input_pin_2 as HIGH/LOW, based on provided arguments
    if (value_pin_2)
        set_bit(motor->port_data_register, motor->input_pin_2);
    else
        clear_bit(motor->port_data_register, motor->input_pin_2);
}

void motor_enable_set(motor_t *motor, bool value)
{
    set_bit(motor->port_data_register, motor->pwm_pin);
}