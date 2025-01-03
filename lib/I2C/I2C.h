#ifndef I2C_H
#define I2C_H

#include  <Arduino.h>
#include <Wire.h>

class I2C
{
	public:
		I2C();
		void init(TwoWire* wire);
		uint8_t read_register(uint8_t dev_addr, uint8_t reg_addr);
		void read_registers(uint8_t dev_addr, uint8_t reg_addr, uint8_t num_bytes, uint8_t buff_[], uint8_t buff_i);
		void write_register(uint8_t dev_addr, uint8_t reg_addr, uint8_t register_val);
		void sendCommand(uint8_t dev_addr, uint8_t cmd);
	private:
		TwoWire* _wire;
};

#endif
