#ifndef MPU6050_H
#define MPU6050_H

#include <stdint.h>
#include "MPU6050_reg.h"

template <typename T_I2C_hal>
class MPU6050
{
    public:
        MPU6050(T_I2C_hal* i2c_hal, uint8_t address): i2c_hal(i2c_hal), address(address);
        void init();
        void config();

        void get_acc(int16_t* AC_X, int16_t* AC_Y, int16_t* AC_Z);
        void get_gyro(int16_t* GY_X, int16_t* GY_Y, int16_t* GY_Z);
        void get_temp();
        void get_data(int16_t* AC_X, int16_t* AC_Y, int16_t* AC_Z, int16_t* TEMP, int16_t* GY_X, int16_t* GY_Y, int16_t* GY_Z);

    private:
        T_I2C_hal* i2c_hal;
        uint8_t address;
};

#endif