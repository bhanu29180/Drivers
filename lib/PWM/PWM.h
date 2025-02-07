#ifndef PWM_H
#define PWM_H

#include <stdint.h>
#include <Arduino.h>

class PWM
{
    public:
        PWM();
        void init();
        void config(float pwm_min_=1000.0, float pwm_max_=2000.0, uint32_t resolution_=15, float freq_=400.0);
        void set_pwm(float pwm1=1000, float pwm2=1000, float pwm3=1000, float pwm4=1000);
        void set_pwm_1(float pwm1);
        void set_pwm_2(float pwm2);
        void set_pwm_3(float pwm3);
        void set_pwm_4(float pwm4);

    private:
        uint8_t motor_1 = 2;
        uint8_t motor_2 = 3;
        uint8_t motor_3 = 5;
        uint8_t motor_4 = 6;
        float freq = 400; // in Hz (i.e. T = 2500 us)
        uint32_t resolution = 15; // 32768
        float pwm_min_us = 1000.0;
        float pwm_max_us = 2000.0;

        int pwm_2_bit_val(float pwm);
        float saturate(float x, float x_min, float x_max);
};

#endif