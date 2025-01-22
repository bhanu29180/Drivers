#ifndef INTERFACE_COMM
#define INTERFACE_COMM

template <typename T_com, typename T_config>
class Interface_comm: public Interface_dev
{
    public:
        Interface_comm(T_com* com, T_config* config): com(com), config(config);
        virtual void config() const = 0;
        virtual void init() const = 0;
        virtual void receive_data() const = 0;
        virtual void send_data() const = 0;

    private:
        T_com* com;
        T_config* config;
};

#endif