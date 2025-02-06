#ifndef INTERFACE_DEV
#define INTERFACE_DEV

#include <stdint.h>

template <typename T_config, typename T_recv, typename T_send>
class Interface_dev
{
    public:
        Interface_dev(uint8_t ID_): ID(ID_){};
        virtual ~Interface_dev() = default;
        virtual void init() = 0;
        virtual void config(T_config* config_) = 0;
        virtual void receive_data(T_recv* recv_data) = 0;
        virtual void send_data(T_send* send_data) = 0;
    
    protected:
        uint8_t get_ID()
        {
            return ID;
        }
        
        void set_ID(uint8_t ID_)
        {
            ID = ID_;
        }

    private:
        uint8_t ID = 0;
};

#endif