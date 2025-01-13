#ifndef INTERFACE_DEV
#define INTERFACE_DEV

template <typename T_com_bus, typename T_config>
class Interface_dev
{
    public:
        Interface_dev(T_com_bus* com_bus_, T_config* config_): com_bus(com_bus_), config(config_){};
        virtual void init() = 0;
        virtual void config() = 0;
        virtual void receive_data() = 0;
        virtual void send_data() = 0;
    
    protected:
        T_com_bus* get_com_bus() const { return com_bus; }
        T_config* get_config() const { return config; }

    private:
        T_com_bus* com_bus;
        T_config* config;
};

#endif