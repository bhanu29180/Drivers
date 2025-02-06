#ifndef INTERFACE_GYRO
#define INTERFACE_GYRO

template <typename T_com, typename T_config>
class Interface_gyro: public Interface_sensor
{
    public:
        Interface_gyro(T_com* com, T_config* config): com(com), config(config);
        virtual void config() const = 0;
        virtual void init() const = 0;
        virtual void receive_data() const = 0;
        virtual void send_data() const = 0;

    private:
        T_com* com;
        T_config* config;
};

#endif