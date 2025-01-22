#ifndef UART_BUS_H
#define UART_BUS_H

#include <stdint.h>

template <typename T_UART_bus>
class UART_bus {
	public:
		UART_bus(T_UART_bus* bus);
		void init();
		void config(uint32_t baud_rate=9600);
		int16_t available();
		void send_data(uint8_t value);
		void send_data(uint8_t* buffer, uint8_t length);
		uint8_t receive_data();
		void receive_data(uint8_t* buffer, uint8_t length);

	private:
		T_UART_bus* bus;
};

template <typename T_UART_bus>
UART_bus<T_UART_bus>::UART_bus(T_UART_bus* bus) : bus(bus)
{ 
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::init()
{
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::config(uint32_t baud_rate)
{
	bus->begin(baud_rate);
}

template <typename T_UART_bus>
int16_t UART_bus<T_UART_bus>::available()
{
	return bus->available();
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::send_data(uint8_t value)
{
	bus->write(value);
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::send_data(uint8_t* values, uint8_t length)
{
	for(uint8_t i=0; i<length; i++)
	{
		bus->write(values[i]);
	}
}

template <typename T_UART_bus>
uint8_t UART_bus<T_UART_bus>::receive_data()
{
	return value = bus->read();
}

template <typename T_UART_bus>
void UART_bus<T_UART_bus>::receive_data(uint8_t* buffer, uint8_t length)
{
	while(bus->available() < length);
	for (uint8_t i = 0; i < length; i++) 
	{
		buffer[i] = bus->read();
	}
}

#endif