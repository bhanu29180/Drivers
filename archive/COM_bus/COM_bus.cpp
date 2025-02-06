#include "COM_bus.h"

template <typename T_Bus>
COM_bus<T_Bus>::COM_bus(T_Bus *bus) : bus(bus)
{
}

template <typename T_Bus>
void COM_bus<T_Bus>::init()
{
    bus->init();
}

template <typename T_Bus>
void COM_bus<T_Bus>::configure(uint32_t freq)
{
    bus->configure(freq);
}

template <typename T_Bus>
uint8_t COM_bus<T_Bus>::read_register(uint8_t address, uint8_t reg)
{
    return bus->read_register(address, reg);
}

template <typename T_Bus>
void COM_bus<T_Bus>::read_registers(uint8_t address, uint8_t reg, uint8_t *buffer, uint8_t length)
{
    bus->read_registers(address, reg, buffer, length);
}

template <typename T_Bus>
void COM_bus<T_Bus>::write_register(uint8_t address, uint8_t reg, uint8_t value)
{
    bus->write_register(address, reg, value);
}

template <typename T_Bus>
void COM_bus<T_Bus>::write_registers(uint8_t address, uint8_t reg, uint8_t *values, uint8_t length)
{
    bus->write_registers(address, reg, values, length);
}

template <typename T_Bus>
void COM_bus<T_Bus>::send_data(uint8_t address, uint8_t value)
{
    bus->send_data(address, value);
}

template <typename T_Bus>
void COM_bus<T_Bus>::send_data(uint8_t address, uint8_t *buffer, uint8_t length)
{
    bus->send_data(address, buffer, length);
}

template <typename T_Bus>
uint8_t COM_bus<T_Bus>::receive_data(uint8_t address)
{
    return bus->receive_data(address);
}

template <typename T_Bus>
uint8_t COM_bus<T_Bus>::receive_data(uint8_t address, uint8_t *buffer, uint8_t length)
{
    return bus->receive_data(address, buffer, length);
}