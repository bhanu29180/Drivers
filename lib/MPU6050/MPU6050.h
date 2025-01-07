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

        // Register Name: SMPRT_DIV (Sample Rate Divider)
        uint8_t get_SMPLRT_DIV();
        void set_SMPLRT_DIV(uint8_t val);

        // Register Name: CONFIG
        uint8_t get_ext_FSYNC();
        void set_ext_FSYNC(uint8_t sync);
        uint8_t get_DLPF_CFG();
        void set_DLPF_CFG(uint8_t val);

        // Register Name: GYRO_CONFIG (Gyroscope Configuration)
        uint8_t get_XG_ST();
        void set_XG_ST(uint8_t val);
        uint8_t get_YG_ST();
        void set_YG_ST(uint8_t val);
        uint8_t get_ZG_ST();
        void set_ZG_ST(uint8_t val);
        uint8_t get_FS_SEL();
        void set_FS_SEL(uint8_t val);

        // Register Name: ACCEL_CONFIG (Accelerometer Configuration)
        uint8_t get_XA_ST();
        void set_XA_ST(uint8_t val);
        uint8_t get_YA_ST();
        void set_YA_ST(uint8_t val);
        uint8_t get_ZA_ST();
        void set_ZA_ST(uint8_t val);
        uint8_t get_AFS_SEL();
        void set_AFS_SEL(uint8_t val);

        // Register Name: PWR_MGMT_1 (Power Management 1)
        uint8_t get_DEVICE_RESET();
        void set_DEVICE_RESET(uint8_t val);
        uint8_t get_SLEEP();
        void set_SLEEP(uint8_t val);
        uint8_t get_CYCLE();
        void set_CYCLE(uint8_t val);
        uint8_t get_TEMP_DIS();
        void set_TEMP_DIS(uint8_t val);
        uint8_t get_CLKSEL();
        void set_CLKSEL(uint8_t val);

        // Register Name: PWR_MGMT_2 (Power Management 2)
        uint8_t get_LP_WAKE_CTRL();
        void set_LP_WAKE_CTRL(uint8_t val);
        uint8_t get_STBY_XA();
        void set_STBY_XA(uint8_t val);
        uint8_t get_STBY_YA();
        void set_STBY_YA(uint8_t val);
        uint8_t get_STBY_ZA();
        void set_STBY_ZA(uint8_t val);
        uint8_t get_STBY_XG();
        void set_STBY_XG(uint8_t val);
        uint8_t get_STBY_YG();
        void set_STBY_YG(uint8_t val);
        uint8_t get_STBY_ZG();
        void set_STBY_ZG(uint8_t val);

        // Register Name: WHO_AM_I (Who Am I)
        uint8_t get_WHO_AM_I();

        // Reading sensor data register
        uint8_t get_ACCEL_XOUT_H();
        uint8_t get_ACCEL_XOUT_L();
        uint8_t get_ACCEL_YOUT_H();
        uint8_t get_ACCEL_YOUT_L();
        uint8_t get_ACCEL_ZOUT_H();
        uint8_t get_ACCEL_ZOUT_L();
        int16_t get_ACCEL_XOUT();
        int16_t get_ACCEL_YOUT();
        int16_t get_ACCEL_ZOUT();
        uint8_t get_TEMP_OUT_H();
        uint8_t get_TEMP_OUT_L();
        int16_t get_TEMP_OUT();
        uint8_t get_GYRO_XOUT_H();
        uint8_t get_GYRO_XOUT_L();
        uint8_t get_GYRO_YOUT_H();
        uint8_t get_GYRO_YOUT_L();
        uint8_t get_GYRO_ZOUT_H();
        uint8_t get_GYRO_ZOUT_L();
        int16_t get_GYRO_XOUT();
        int16_t get_GYRO_YOUT();
        int16_t get_GYRO_ZOUT();
        void get_ACCEL_OUT(int16_t* AC_X, int16_t* AC_Y, int16_t* AC_Z);
        void get_GYRO_OUT(int16_t* GY_X, int16_t* GY_Y, int16_t* GY_Z);
        void get_MPU6050_OUT(int16_t* AC_X, int16_t* AC_Y, int16_t* AC_Z, int16_t* TEMP, int16_t* GY_X, int16_t* GY_Y, int16_t* GY_Z);

    private:
        I2C_bus<TwoWire>* i2c_bus;
        uint8_t mpu6050_addr;
        uint8_t register_val;
        uint8_t buff[14];
};

#endif