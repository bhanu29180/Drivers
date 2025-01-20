#ifndef MS5611_H
#define MS5611_H

#include <stdint.h>
#include "utility.h"
#include "MS5611_reg.h"
#include "Arduino.h"

template <typename T_I2C_bus>
class MS5611
{
    public:
        MS5611(T_I2C_bus* i2c_bus_, uint8_t address_);
        void init();
        void config();

        void get_data(int32_t* press, int32_t* temp);

    private:
        T_I2C_bus* i2c_bus;
        uint8_t address;
        uint8_t sample_time = 2;
        uint8_t max_time = 10;
        uint8_t current_time = 0;

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

        bool strt = false;

        void reset();
        void read_prom();
        void d1_conversion();
        void d2_conversion();
        uint32_t read_adc();
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
    reset();
    // wait 100 ms
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::config()
{
    read_prom();
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::get_data(int32_t* press, int32_t* temp)
{
    d1_conversion();
    delay(10);
    D1 = read_adc();
    d2_conversion();
    delay(10);
    D2 = read_adc();
    cal_temp();
    cal_temp_compensated_pressure();

    *press = P;
    *temp = TEMP;

    Serial.print(C1); Serial.print('\t');
    Serial.print(C2); Serial.print('\t');
    Serial.print(C3); Serial.print('\t');
    Serial.print(C4); Serial.print('\t');
    Serial.print(C5); Serial.print('\t');
    Serial.print(C6); Serial.print('\t'); Serial.print("|\t");
    Serial.print(P); Serial.print('\t');
    Serial.print(TEMP); Serial.print('\t'); Serial.print("|\t");
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::reset()
{
    i2c_bus->send_data(address, (uint8_t)MS5611_INFO::COMMAND::RESET);
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::read_prom()
{
    uint8_t buff[2];
    i2c_bus->read_registers(address, (uint8_t)MS5611_INFO::COMMAND::PROM_READ_1, buff, 2);
    C1 = ((uint16_t)buff[0] << 8) | buff[1];
    i2c_bus->read_registers(address, (uint8_t)MS5611_INFO::COMMAND::PROM_READ_2, buff, 2);
    C2 = ((uint16_t)buff[0] << 8) | buff[1];
    i2c_bus->read_registers(address, (uint8_t)MS5611_INFO::COMMAND::PROM_READ_3, buff, 2);
    C3 = ((uint16_t)buff[0] << 8) | buff[1];
    i2c_bus->read_registers(address, (uint8_t)MS5611_INFO::COMMAND::PROM_READ_4, buff, 2);
    C4 = ((uint16_t)buff[0] << 8) | buff[1];
    i2c_bus->read_registers(address, (uint8_t)MS5611_INFO::COMMAND::PROM_READ_5, buff, 2);
    C5 = ((uint16_t)buff[0] << 8) | buff[1];
    i2c_bus->read_registers(address, (uint8_t)MS5611_INFO::COMMAND::PROM_READ_6, buff, 2);
    C6 = ((uint16_t)buff[0] << 8) | buff[1];
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::d1_conversion()
{
    i2c_bus->send_data(address, (uint8_t)MS5611_INFO::COMMAND::CONVERT_D1_OSR_4096);
}

template <typename T_I2C_bus>
void MS5611<T_I2C_bus>::d2_conversion()
{
    i2c_bus->send_data(address, (uint8_t)MS5611_INFO::COMMAND::CONVERT_D2_OSR_4096);
}

template <typename T_I2C_bus>
uint32_t MS5611<T_I2C_bus>::read_adc()
{
    uint8_t buff[3];
    i2c_bus->read_registers(address, (uint8_t)(uint8_t)MS5611_INFO::COMMAND::ADC_READ, buff, 3);
    uint32_t D12 = ((uint32_t)buff[0])<<16 | ((uint32_t)buff[1])<<8 | buff[2];
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