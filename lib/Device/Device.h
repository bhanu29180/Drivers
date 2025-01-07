#ifndef DEVICE_H
#define DEVICE_H

template <typename T_comm_bus, typename T_param>
class Device
{
    public:
        Device();
        virtual void configure();
        virtual void init();
		virtual void receive();
		virtual void transmit();

    private:
        T_comm_bus* comm_bus;
        T_param* param;
};

#endif