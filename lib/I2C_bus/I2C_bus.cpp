#include "I2C_bus.h"

template <typename T>
I2C_bus<T>::I2C_bus(T* bus) : bus(bus)
{
}

template <typename T>
void I2C_bus<T>::init(uint32_t freq)
{
	bus->begin();
	bus->setClock(freq);
}

template <typename T>
uint8_t I2C_bus<T>::read_register(uint8_t address, uint8_t reg) 
{
	bus->beginTransmission(address);
	bus->write(reg);
	bus->endTransmission();
	bus->requestFrom(address, (uint8_t)1);
	return bus->read();
}

template <typename T>
void I2C_bus<T>::read_registers(uint8_t address, uint8_t reg, uint8_t* buffer, uint8_t length) 
{
	bus->beginTransmission(address);
	bus->write(reg);
	bus->endTransmission();
	bus->requestFrom(address, length);
	for (uint8_t i = 0; i < length; i++) 
	{
		buffer[i] = bus->read();
	}
}

template <typename T>
void I2C_bus<T>::write_register(uint8_t address, uint8_t reg, uint8_t value) 
{
	bus->beginTransmission(address);
	bus->write(reg);
	bus->write(value);
	bus->endTransmission();
}

template <typename T>
void I2C_bus<T>::write_registers(uint8_t address, uint8_t reg, uint8_t* values, uint8_t length) 
{
	bus->beginTransmission(address);
	bus->write(reg);
	for (uint8_t i = 0; i < length; i++) 
	{
		bus->write(values[i]);
	}
	bus->endTransmission();
}