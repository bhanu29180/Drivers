#ifndef QMC5883_REG
#define QMC5883_REG

namespace QMC5883
{
    enum class ADDR
    {
        I2C = 0x0D,
        I2C_DEFAULT = I2C
    };

    enum class REGISTER
    {
        DATA_OUT_X_LSB   = 0x00,
        DATA_OUT_X_MSB   = 0x01,
        DATA_OUT_Y_LSB   = 0x02,
        DATA_OUT_Y_MSB   = 0x03,
        DATA_OUT_Z_LSB   = 0x04,
        DATA_OUT_Z_MSB   = 0x05,
        STATUS_1         = 0x06,
        TEMP_OUT_LSB     = 0x07,
        TEMP_OUT_MSB     = 0x08,
        CONTROL_REG_1    = 0x09,
        CONTROL_REG_1    = 0x0A,
        SET_RESET_PERIOD = 0x0B,
        STATUS_2         = 0x0C,
        CHIP_ID          = 0x0D
    };
}

#endif