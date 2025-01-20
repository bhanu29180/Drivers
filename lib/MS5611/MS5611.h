#ifndef MS5611_H
#define MS5611_H

#include <stdint.h>
#include "utility.h"
#include "MS5611_reg.h"

template <typename T_I2C_bus>
class MS5611
{
    public:
        MS5611(T_I2C_bus* i2c_bus_, uint8_t address_);
        void init();
        void config();

        void get_bar(int16_t* press, int16_t* temp);
        void get_data(int16_t* press, int16_t* temp);

    private:
        T_I2C_bus* i2c_bus;
        uint8_t address;

        uint16_t C1 = 0;
        uint16_t C2 = 0;
        uint16_t C3 = 0;
        uint16_t C4 = 0;
        uint16_t C5 = 0;
        uint16_t C6 = 0;

        uint32_t D1 = 0;
        uint32_t D2 = 0;

        int32_t dT = 0;
        int32_t TEMP = 0;

        int64_t OFF = 0;
        int64_t SENS = 0;
        int32_t P = 0;

        void reset();
        void read_prom();
        void d1_conversion();
        void d2_conversion();
        void read_adc();

        void set_bit_val(uint8_t reg, uint8_t bit_mask, uint8_t bit_lcn_0, uint8_t bit_val);
        uint8_t get_bit_val(uint8_t reg, uint8_t bit_mask, uint8_t bit_lcn_0);
};

template <typename T_I2C_bus>
MS5611<T_I2C_bus>::MS5611(T_I2C_bus* i2c_bus_, uint8_t address_): i2c_bus(i2c_bus_), address(address_)
{
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::reset()
{
    i2c_bus->send_data(address, 0x1E);
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::read_prom()
{
    uint8_t buff[12];
    i2c_bus->read_registers(address, 0xA2, buff, 12);
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::d1_conversion()
{
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::d2_conversion()
{
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::read_adc()
{
}










template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::init()
{
    i2c_bus->send_data(address, 0x1E);
    // wait 100 ms
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::config()
{
    set_bit_val((uint8_t)MS5611::REGISTER::MODE, (uint8_t)BIT::MASK8::BITM2_0,(uint8_t)ZERO,(uint8_t)0); // continuous mode
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::set_bit_val(uint8_t reg, uint8_t bit_mask, uint8_t bit_lcn_0, uint8_t bit_val)
{
    uint8_t register_val = i2c_bus->read_register(address, reg);
    register_val = (register_val & (~bit_mask)) | (bit_val<<bit_lcn_0);
    i2c_bus->write_register(address, reg, register_val);
}

template <typename T_I2C_bus>
uint8_t MS5611<T_I2C_bus>::get_bit_val(uint8_t reg, uint8_t bit_mask, uint8_t bit_lcn_0)
{
    return ((i2c_bus->read_register(address, reg)) & bit_mask) >> bit_lcn_0;
}

#endif