#ifndef INTERFACE_SENSOR
#define INTERFACE_SENSOR

template <typename T_com_bus, typename T_config>
class Interface_sensor: public Interface_dev<T_com_bus, T_config>
{
    public:
        Interface_sensor(T_com_bus* com_bus_, T_config* config_): Interface_dev<T_com_bus, T_config>(com_bus_, config_) {}
        virtual void calibrate() = 0;

    private:
        T_com_bus* com_bus;
        T_config* config;
};

#endif