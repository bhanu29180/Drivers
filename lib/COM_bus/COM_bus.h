#ifndef COM_BUS_H
#define COM_BUS_H

#include <stdint.h>

template <typename T_Bus>
class COM_bus
{
    public:
        COM_bus(T_Bus* bus);
        void init();
        void configure(uint32_t freq);
        uint8_t read_register(uint8_t address, uint8_t reg);
        void read_registers(uint8_t address, uint8_t reg, uint8_t* buffer, uint8_t length);
        void write_register(uint8_t address, uint8_t reg, uint8_t value);
        void write_registers(uint8_t address, uint8_t reg, uint8_t* values, uint8_t length);
        void send_data(uint8_t address, uint8_t value);
        void send_data(uint8_t address, uint8_t* buffer, uint8_t length);
        uint8_t receive_data(uint8_t address);
        uint8_t receive_data(uint8_t address, uint8_t* buffer, uint8_t length);

    private:
        T_Bus* bus;
};

#endif