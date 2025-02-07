#include "PWM.h"

PWM::PWM()
{
}

void PWM::init(float pwm1=1000, float pwm2=1000, float pwm3=1000, float pwm4=1000)
{
    pinMode(motor_1,OUTPUT);
    pinMode(motor_2,OUTPUT);
    pinMode(motor_3,OUTPUT);
    pinMode(motor_4,OUTPUT);
}

void PWM::config()
{
    analogWriteFrequency(motor_1, freq);
    analogWriteFrequency(motor_2, freq);
    analogWriteFrequency(motor_3, freq);
    analogWriteFrequency(motor_4, freq);

    analogWriteResolution(resolution);

    set_pwm(1000.0,1000.0,1000.0,1000.0);
}

void PWM::set_pwm(float pwm1=1000, float pwm2=1000, float pwm3=1000, float pwm4=1000)
{
    analogWriteResolution(resolution);
    analogWrite(motor_1,pwm_2_bit_val(pwm1));
    analogWrite(motor_2,pwm_2_bit_val(pwm2));
    analogWrite(motor_3,pwm_2_bit_val(pwm3));
    analogWrite(motor_4,pwm_2_bit_val(pwm4));
    analogWriteResolution(resolution);
}

void PWM::set_pwm_1(float pwm1)
{
    analogWriteResolution(resolution);
    analogWrite(motor_1,pwm_2_bit_val(pwm1));
    analogWriteResolution(resolution);
}

void PWM::set_pwm_2(float pwm2)
{
    analogWriteResolution(resolution);
    analogWrite(motor_2,pwm_2_bit_val(pwm2));
    analogWriteResolution(resolution);
}

void PWM::set_pwm_3(float pwm3)
{
    analogWriteResolution(resolution);
    analogWrite(motor_3,pwm_2_bit_val(pwm3));
    analogWriteResolution(resolution);
}

void PWM::set_pwm_4(float pwm4)
{
    analogWriteResolution(resolution);
    analogWrite(motor_4,pwm_2_bit_val(pwm4));
    analogWriteResolution(resolution);
}

int PWM::pwm_2_bit_val(float pwm)
{
    return 13.1072*pwm; //(32768.0/2500.0)*pwm; // ((2^PWM_resolution) / (1,000,000/PWM_frequency)) * pwm
}