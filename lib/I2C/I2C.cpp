#include "I2C.h"

I2C::I2C()
{
}

void I2C::init(TwoWire* wire)
{
	_wire->begin();
	_wire->setClock(400000);
}

uint8_t I2C::read_register(uint8_t dev_addr, uint8_t reg_addr)
{
	_wire->beginTransmission(dev_addr);
	_wire->write(reg_addr);
	_wire->endTransmission(false);
	_wire->requestFrom(dev_addr,1,true);
	while(_wire->available() < 1);
	return _wire->read();
}

void I2C::read_registers(uint8_t dev_addr, uint8_t reg_addr, uint8_t n_bytes, uint8_t buff_[], uint8_t buff_i)
{
	_wire->beginTransmission(dev_addr);
	_wire->write(reg_addr);
	_wire->endTransmission();
	_wire->requestFrom(dev_addr,n_bytes);
	while(_wire->available() < n_bytes);
	for(int i=buff_i;i<buff_i+n_bytes;i++)
	{
		buff_[i] = _wire->read();
	}
}

void I2C::write_register(uint8_t dev_addr, uint8_t reg_addr, uint8_t register_val)
{
	_wire->beginTransmission(dev_addr);
	_wire->write(reg_addr);
	_wire->write(register_val);
	_wire->endTransmission();
}

void I2C::sendCommand(uint8_t dev_addr, uint8_t cmd)
{
	_wire->beginTransmission(dev_addr);
	_wire->write(cmd);
	_wire->endTransmission();
}
