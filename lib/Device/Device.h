#ifndef DEVICE_H
#define DEVICE_H

template <typename T>
class Device
{
    public:
        void init();
        void configure();
		void read_data(uint8_t address, uint8_t reg, uint8_t* buffer, uint8_t length);
		void write_data(uint8_t address, uint8_t reg, uint8_t* values, uint8_t length);

    private:
        T* comm_bus;
};

#endif