#include "libmotor/l298n_dc_motor.h"
#include "libpwm/pwm.h"
#include "config.h"

motor_t rear_left_motor;
motor_t rear_right_motor;
uint8_t pwm_value = 0;

void setup(void)
{
    // Init timer
    pwm_clear();
    pwm_init();

    // Setup motors
    rear_left_motor.port_data_register = &PORTB;
    rear_left_motor.port_data_direction_register = &DDRB;
    rear_left_motor.input_pin_1 = PINB4; // D12
    rear_left_motor.input_pin_2 = PINB5; // D13
    rear_left_motor.pwm_pin = PINB2; // D10
    rear_left_motor.pwm_enabler = pwm_enable_channel_b;
    rear_left_motor.pwm_writer = pwm_write_channel_b;
    motor_init(&rear_left_motor);

    rear_right_motor.port_data_register = &PORTB;
    rear_right_motor.port_data_direction_register = &DDRB;
    rear_right_motor.input_pin_1 = PINB0; // D8
    rear_right_motor.input_pin_2 = PINB3; // D11
    rear_right_motor.pwm_pin = PINB1; // D9
    rear_right_motor.pwm_enabler = pwm_enable_channel_a;
    rear_right_motor.pwm_writer = pwm_write_channel_a;
    motor_init(&rear_right_motor);

    // Defaults
    motor_direction_set(&rear_left_motor, true, false);
    motor_direction_set(&rear_right_motor, true, false);
}

void loop(void)
{
    motor_pwm_value_set(&rear_left_motor, pwm_value);
    motor_pwm_value_set(&rear_right_motor, pwm_value);

    pwm_value += 5;
    _delay_ms(100);
}

int main(void)
{
    setup();

    while (1)
    {
        loop();
    }
}