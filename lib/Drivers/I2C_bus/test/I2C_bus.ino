#include "Arduino.h"
#include <Wire.h>
#include "../Drivers/I2C_bus/src/I2C_bus.h"

I2C_bus<TwoWire> i2c_bus(&Wire);

void setup()
{
	Serial.begin(115200);
	i2c_bus.init();
	i2c_bus.config(400000);
}

void loop()
{
	Serial.println("Scanning...");

	int nDevices = 0;
	
	for(uint8_t address = 1; address < 127; address++) 
	{
		Wire.beginTransmission(address);
		uint8_t error = Wire.endTransmission();

		if (error == 0)
		{
			Serial.print("I2C device found at address 0x");
			if (address<16) 
			{
				Serial.print("0");
			}
			Serial.print(address,HEX);
			Serial.println("  !");

			nDevices++;
		}
		else if (error==4) 
		{
			Serial.print("Unknown error at address 0x");
			if (address<16) 
			{
				Serial.print("0");
			}
			Serial.println(address,HEX);
		}    
	}

	if (nDevices == 0)
	{
		Serial.println("No I2C devices found\n");
	}
	else
	{
		Serial.println("done\n");
	}

	delay(5000);
}