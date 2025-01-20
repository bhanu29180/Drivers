#include "Arduino.h"
#include "I2C_bus.h"
#include "MS5611.h"
#include "Wire.h"
#include <stdint.h>

I2C_bus<TwoWire> i2c_bus(&Wire);
MS5611<I2C_bus<TwoWire>> bar(&i2c_bus, (uint8_t)MS5611_INFO::ADDR::I2C_DEFAULT);

void setup()
{
}

void loop()
{
}