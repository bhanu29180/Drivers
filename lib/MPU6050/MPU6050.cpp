#include "MPU6050.h"

template <typename T_I2C_hal>
MPU6050<T_I2C_hal>::MPU6050(T_I2C_hal* i2c_hal, uint8_t address): i2c_hal(i2c_hal), address(address)
{
}

template <typename T_I2C_hal>
void MPU6050<T_I2C_hal>::init()
{
    uint8_t register_val = i2c_hal->read_register(MPU6050::ADDR::I2C_1, MPU6050::REGISTER::PWR_MGMT_1);
    iiiregister_val = (register_val & SLEEP_LCN_0) | (val << SLEEP_LCN_START);
    i2cdev1.write_register(mpu6050_addr, PWR_MGMT_1, register_val);
}

template <typename T_I2C_hal>
void MPU6050<T_I2C_hal>::config()
{
    set_DLPF_CFG(DLPF_CFG_1);
    set_SMPLRT_DIV(SMPLRT_DIV);
    set_FS_SEL(FS_SEL_1);
    set_AFS_SEL(AFS_SEL_1);
}

template <typename T_I2C_hal>
void MPU6050<T_I2C_hal>::get_acc(int16_t* AC_X, int16_t* AC_Y, int16_t* AC_Z)
{
}

template <typename T_I2C_hal>
void MPU6050<T_I2C_hal>::get_gyro(int16_t* GY_X, int16_t* GY_Y, int16_t* GY_Z)
{
}

template <typename T_I2C_hal>
void MPU6050<T_I2C_hal>::get_temp()
{
}

template <typename T_I2C_hal>
void MPU6050<T_I2C_hal>::get_data(int16_t* AC_X, int16_t* AC_Y, int16_t* AC_Z, int16_t* TEMP, int16_t* GY_X, int16_t* GY_Y, int16_t* GY_Z)
{
}