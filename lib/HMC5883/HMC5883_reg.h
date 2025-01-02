#ifndef HMC5883_REG
#define HMC5883_REG

namespace HMC5883
{
    enum ADDR
    {
        I2C = 0x1E,
        I2C_DEFAULT = I2C
    };

    enum REGISTER
    {
        CONFIG_A         = 0x00,
        CONFIG_B         = 0x01,
        MODE             = 0x02,
        DATA_OUT_X_MSB   = 0x03,
        DATA_OUT_X_LSB   = 0x04,
        DATA_OUT_Z_MSB   = 0x05,
        DATA_OUT_Z_LSB   = 0x06,
        DATA_OUT_Y_MSB   = 0x07,
        DATA_OUT_Y_LSB   = 0x08,
        STATUS           = 0x09,
        IDENTIFICATION_A = 0x0A,
        IDENTIFICATION_B = 0x0B,
        IDENTIFICATION_C = 0x0C
    };
}

#endif