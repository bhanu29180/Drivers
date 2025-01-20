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
        void cal_temp();
        void cal_temp_compensated_pressure();
        void second_order_temperature_compensation();
};

template <typename T_I2C_bus>
MS5611<T_I2C_bus>::MS5611(T_I2C_bus* i2c_bus_, uint8_t address_): i2c_bus(i2c_bus_), address(address_)
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
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::reset()
{
    i2c_bus->send_data(address, 0x1E);
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::read_prom()
{
    uint8_t buff[16];
    i2c_bus->read_registers(address, 0xA0, buff, 16);
    C1 = ((uint16_t)buff[2] << 8) | buff[3];
    C2 = ((uint16_t)buff[4] << 8) | buff[5];
    C3 = ((uint16_t)buff[6] << 8) | buff[7];
    C4 = ((uint16_t)buff[8] << 8) | buff[9];
    C5 = ((uint16_t)buff[10] << 8) | buff[11];
    C6 = ((uint16_t)buff[12] << 8) | buff[13];
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::d1_conversion()
{
    i2c_bus->send_data(address, 0x48);
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::d2_conversion()
{
    i2c_bus->send_data(address, 0x58);
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::read_adc()
{
    uint8_t buff[3];
    i2c_bus->read_registers(address, 0x00, buff, 3);

    D12 = ((uint32_t)buff_temp[0])<<16 | ((uint32_t)buff_temp[1])<<8 | buff_temp[2];
    return D12;
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::cal_temp()
{
    dT = D2 - (uint32_t)C5*256;
    TEMP = 2000 + (dT*(int32_t)C6)/8388608.0;
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::cal_temp_compensated_pressure()
{
    OFF  = (double)C2*65536.0 + ((double)C4*dT)/128.0;
    SENS = (double)C1*32768.0 + ((double)C3*dT)/256.0;
    second_order_temperature_compensation();
    P = (D1*SENS/2097152.0 - OFF)/32768.0;
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::second_order_temperature_compensation(){
    double T2 = 0;
    double OFF2 = 0;
    double SENS2 = 0;

    if(TEMP<2000)
    {
        T2 = dT*dT/2147483648.0;
        OFF2 = 5.0*(TEMP-2000.0)*(TEMP-2000.0)/2.0;
        SENS2 = 5.0*(TEMP-2000.0)*(TEMP-2000.0)/4.0;

        if(TEMP<-1500)
        {
            OFF2 = OFF2 + 7.0*(TEMP+1500.0)*(TEMP+1500.0);
            SENS2 = SENS2 + 11.0*((TEMP+1500.0)*(TEMP+1500.0))/2.0;
        }
    }
    else
    {
        T2 = 0;
        OFF2 = 0;
        SENS2 = 0;
    }

    TEMP = TEMP - T2;
    OFF = OFF - OFF2;
    SENS = SENS - SENS2;
}

#endif