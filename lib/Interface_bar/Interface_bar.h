#ifndef INTERFACE_BAR
#define INTERFACE_BAR

template <typename T_com, typename T_config>
class Interface_bar: public Interface_sensor
{
    public:
        Interface_bar(T_com* com, T_config* config): com(com), config(config);
        virtual void config() const = 0;
        virtual void init() const = 0;
        virtual void receive_data() const = 0;
        virtual void send_data() const = 0;

    private:
        T_com* com;
        T_config* config;
};

#endif