#ifndef I2C_BUS_H
#define I2C_BUS_H

#include <Wire.h>

template <typename T>
class I2C_bus {
	public:
		I2C_bus(T* bus);
		void init(uint32_t freq);
		void configure();
		uint8_t read_register(uint8_t address, uint8_t reg);
		void read_registers(uint8_t address, uint8_t reg, uint8_t* buffer, uint8_t length);
		void write_register(uint8_t address, uint8_t reg, uint8_t value);
		void write_registers(uint8_t address, uint8_t reg, uint8_t* values, uint8_t length);

	private:
		T* bus;
};

#endif