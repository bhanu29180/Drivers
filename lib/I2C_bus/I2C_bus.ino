#include "Arduino.h"
#include "I2C_bus.h"

I2C_bus<TwoWire> i2c(&Wire);
I2C_bus<TwoWire> i2c1(&Wire1);
I2C_bus<TwoWire> i2c2(&Wire2);

void setup()
{
    i2c.init();
    i2c1.init();
    i2c2.init();
}

void loop()
{
}