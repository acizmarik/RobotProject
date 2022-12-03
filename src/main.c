#include "config.h"
#include "libmotor/l298n_dc_motor.h"

motor_t rear_left_motor;
motor_t rear_right_motor;

void setup(void)
{
    rear_left_motor.port_data_register = &PORTB;
    rear_left_motor.port_data_direction_register = &DDRB;
    rear_left_motor.input_pin_1 = PINB0; // D8
    rear_left_motor.input_pin_2 = PINB3; // D11
    rear_left_motor.pwm_pin = PINB1; // D9
    motor_init(&rear_left_motor);

    rear_right_motor.port_data_register = &PORTB;
    rear_right_motor.port_data_direction_register = &DDRB;
    rear_right_motor.input_pin_1 = PINB4; // D12
    rear_right_motor.input_pin_2 = PINB5; // D13
    rear_right_motor.pwm_pin = PINB2; // D10
    motor_init(&rear_right_motor);
}

int main(void)
{
    setup();
    motor_enable_set(&rear_left_motor, true);
    motor_enable_set(&rear_right_motor, true);
    motor_direction_set(&rear_left_motor, true, false);
    motor_direction_set(&rear_right_motor, true, false);

    while (1)
    {

    }
}