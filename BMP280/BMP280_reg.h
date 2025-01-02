#ifndef BMP280_REG
#define BMP280_REG

namespace BMP280
{
    enum ADDR
    {
        I2C_1 = 0x76,
        I2C_2 = 0x77,
        I2C_DEFAULT = I2C_1
    };

    enum REGISTER
    {
        CALIB_00   = 0x88,
        CALIB_01   = 0x89,
        CALIB_02   = 0x8A,
        CALIB_03   = 0x8B,
        CALIB_04   = 0x8C,
        CALIB_05   = 0x8D,
        CALIB_06   = 0x8E,
        CALIB_07   = 0x8F,
        CALIB_08   = 0x90,
        CALIB_09   = 0x91,
        CALIB_10   = 0x92,
        CALIB_11   = 0x93,
        CALIB_12   = 0x94,
        CALIB_13   = 0x95,
        CALIB_14   = 0x96,
        CALIB_15   = 0x97,
        CALIB_16   = 0x98,
        CALIB_17   = 0x99,
        CALIB_18   = 0x9A,
        CALIB_19   = 0x9B,
        CALIB_20   = 0x9C,
        CALIB_21   = 0x9D,
        CALIB_22   = 0x9E,
        CALIB_23   = 0x9F,
        CALIB_24   = 0xA0,
        CALIB_25   = 0xA1,
        ID         = 0xD0,
        RESET      = 0xE0,
        STATUS     = 0xF3,
        CTRL_MEAS  = 0xF4,
        CONFIG     = 0xF5,
        PRESS_MSB  = 0xF7,
        PRESS_LSB  = 0xF8,
        PRESS_XLSB = 0xF9,
        TEMP_MSB   = 0xFA,
        TEMP_LSB   = 0xFB,
        TEMP_XLSB  = 0xFC
    };
}

#endif