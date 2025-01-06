#include "I2C_bus.h"

template <typename T>
I2C_bus<T>::I2C_bus(T* bus) : bus(bus)
{
}

template <typename T>
void I2C_bus<T>::init()
{
	bus->begin();
}

template <typename T>
void I2C_bus<T>::configure(uint32_t freq)
{
	bus->setClock(freq);
}

template <typename T>
uint8_t I2C_bus<T>::read_register(uint8_t address, uint8_t reg) 
{
	bus->beginTransmission(address);
	bus->write(reg);
	bus->endTransmission();
	bus->requestFrom(address, (uint8_t)1);
	while(bus->available() < 1);
	return bus->read();
}

template <typename T>
void I2C_bus<T>::read_registers(uint8_t address, uint8_t reg, uint8_t* buffer, uint8_t length) 
{
	bus->beginTransmission(address);
	bus->write(reg);
	bus->endTransmission();
	bus->requestFrom(address, length);
	while(Wire.available() < length);
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

template <typename T>
void I2C_bus<T>::send_data(uint8_t address, uint8_t value)
{
	bus->beginTransmission(address);
	bus->write(value);
	bus->endTransmission();
}

template <typename T>
void I2C_bus<T>::send_data(uint8_t address, uint8_t* values, uint8_t length)
{
	bus->beginTransmission(address);
	for(uint8_t i=0; i<length; i++)
	{
		bus->write(values[i]);
	}
	bus->endTransmission();
}

template <typename T>
uint8_t I2C_bus<T>::receive_data(uint8_t address)
{
	bus->beginTransmission(address);
	bus->requestFrom(address, (uint8_t)1);
	while(bus->available() < 1);
	uint8_t value = bus->read();
	bus->endTransmission();
	return value;
}

template <typename T>
uint8_t I2C_bus<T>::receive_data(uint8_t address, uint8_t* buffer, uint8_t length)
{
	bus->beginTransmission(address);
	bus->requestFrom(address, length);
	while(Wire.available() < length);
	for (uint8_t i = 0; i < length; i++) 
	{
		buffer[i] = bus->read();
	}
	bus->endTransmission(address);
}