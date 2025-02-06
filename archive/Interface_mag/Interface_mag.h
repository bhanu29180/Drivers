#ifndef INTERFACE_MAG
#define INTERFACE_MAG

template <typename T_com, typename T_config>
class Interface_mag: public Interface_sensor
{
    public:
        Interface_mag(T_com* com, T_config* config): com(com), config(config);
        virtual void config() const = 0;
        virtual void init() const = 0;
        virtual void receive_data() const = 0;
        virtual void send_data() const = 0;

    private:
        T_com* com;
        T_config* config;
};

#endif