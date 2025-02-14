#include "PWM.h"

PWM::PWM()
{
}

void PWM::init()
{
    pinMode(motor_1,OUTPUT);
    pinMode(motor_2,OUTPUT);
    pinMode(motor_3,OUTPUT);
    pinMode(motor_4,OUTPUT);
}

void PWM::config(float pwm_min_us_, float pwm_max_us_, uint32_t resolution_, float freq_)
{
    pwm_min_us = pwm_min_us_;
    pwm_max_us = pwm_max_us_;
    resolution = resolution_;
    freq = freq_;

    analogWriteFrequency(motor_1, freq);
    analogWriteFrequency(motor_2, freq);
    analogWriteFrequency(motor_3, freq);
    analogWriteFrequency(motor_4, freq);

    analogWriteResolution(resolution);

    set_pwm(pwm_min_us, pwm_min_us, pwm_min_us, pwm_min_us);
}

void PWM::set_pwm(float pwm1=1000, float pwm2=1000, float pwm3=1000, float pwm4=1000)
{
    pwm1 = saturate(pwm1, pwm_min_us, pwm_max_us);
    pwm2 = saturate(pwm2, pwm_min_us, pwm_max_us);
    pwm3 = saturate(pwm3, pwm_min_us, pwm_max_us);
    pwm4 = saturate(pwm4, pwm_min_us, pwm_max_us);

    analogWriteResolution(resolution);
    analogWrite(motor_1,pwm_2_bit_val(pwm1));
    analogWrite(motor_2,pwm_2_bit_val(pwm2));
    analogWrite(motor_3,pwm_2_bit_val(pwm3));
    analogWrite(motor_4,pwm_2_bit_val(pwm4));
    analogWriteResolution(resolution);
}

void PWM::set_pwm_1(float pwm1)
{
    pwm1 = saturate(pwm1, pwm_min_us, pwm_max_us);
    analogWriteResolution(resolution);
    analogWrite(motor_1,pwm_2_bit_val(pwm1));
    analogWriteResolution(resolution);
}

void PWM::set_pwm_2(float pwm2)
{
    pwm2 = saturate(pwm2, pwm_min_us, pwm_max_us);
    analogWriteResolution(resolution);
    analogWrite(motor_2,pwm_2_bit_val(pwm2));
    analogWriteResolution(resolution);
}

void PWM::set_pwm_3(float pwm3)
{
    pwm3 = saturate(pwm3, pwm_min_us, pwm_max_us);
    analogWriteResolution(resolution);
    analogWrite(motor_3,pwm_2_bit_val(pwm3));
    analogWriteResolution(resolution);
}

void PWM::set_pwm_4(float pwm4)
{
    pwm4 = saturate(pwm4, pwm_min_us, pwm_max_us);
    analogWriteResolution(resolution);
    analogWrite(motor_4,pwm_2_bit_val(pwm4));
    analogWriteResolution(resolution);
}

int PWM::pwm_2_bit_val(float pwm)
{
    return 13.1072*pwm; //(32768.0/2500.0)*pwm; // ((2^PWM_resolution) / (1,000,000/PWM_frequency)) * pwm
}

float PWM::saturate(float x, float x_min, float x_max)
{
    if(x < x_min)
    {
        return x_min;
    }
    else if (x > x_max)
    {
        return x_max;
    }
    else{
        return x;
    }
    
}