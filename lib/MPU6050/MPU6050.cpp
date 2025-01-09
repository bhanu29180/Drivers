#include "MPU6050.h"

template <typename T_I2C_hal>
MPU6050<T_I2C_hal>::MPU6050(T_I2C_hal* i2c_hal, uint8_t address): i2c_hal(i2c_hal), address(address)
{
}

template <typename T_I2C_HAL>
void MPU6050<T_I2C_HAL>::init()
{
    set_SLEEP(0);
}

template <typename T_I2C_HAL>
void MPU6050<T_I2C_HAL>::config()
{
    set_DLPF_CFG(DLPF_CFG_1);
    set_SMPLRT_DIV(SMPLRT_DIV);
    set_FS_SEL(FS_SEL_1);
    set_AFS_SEL(AFS_SEL_1);
}

template <typename T_I2C_HAL>
void MPU6050<T_I2C_HAL>::get_acc(int16_t* AC_X, int16_t* AC_Y, int16_t* AC_Z)
{
}

template <typename T_I2C_HAL>
void MPU6050<T_I2C_HAL>::get_gyro(int16_t* GY_X, int16_t* GY_Y, int16_t* GY_Z)
{
}

template <typename T_I2C_HAL>
void MPU6050<T_I2C_HAL>::get_temp()
{
}

template <typename T_I2C_HAL>
void MPU6050<T_I2C_HAL>::get_data(int16_t* AC_X, int16_t* AC_Y, int16_t* AC_Z, int16_t* TEMP, int16_t* GY_X, int16_t* GY_Y, int16_t* GY_Z)
{
}