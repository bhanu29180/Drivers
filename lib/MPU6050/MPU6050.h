#ifndef MPU6050_H
#define MPU6050_H

#include <stdint.h>
#include "MPU6050_reg.h"
#include "I2C_bus.h"

class MPU6050
{
    public:
        MPU6050(I2C_bus<TwoWire>* i2c_bus, uint8_t address);
        void config();
        void init();
        void test_connection();
        void set_SMPLRT_DIV(uint8_t val);
        uint8_t get_SMPLRT_DIV();
        uint8_t get_ext_FSYNC();
        void set_ext_FSYNC(uint8_t sync);
        uint8_t get_DLPF_CFG();
        void set_DLPF_CFG(uint8_t val);
        void read_accel(int16_t* ax, int16_t* ay, int16_t* az);
        void read_gyro(int16_t* gx, int16_t* gy, int16_t* gz);

    private:
        I2C_bus<TwoWire>* i2c_bus;
};

#endif