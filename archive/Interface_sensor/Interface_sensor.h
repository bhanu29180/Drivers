#ifndef INTERFACE_SENSOR
#define INTERFACE_SENSOR

#include <stdint.h>
#include "Interface_dev.h"

template <typename T_config, typename T_recv, typename T_send>
class Interface_sensor: public Interface_dev<T_config, T_recv, T_send>
{
    public:
        explicit Interface_sensor(uint8_t ID_): Interface_dev<T_config, T_recv, T_send>(ID_) {}
        virtual ~Interface_sensor() = default;
        virtual void calibrate() = 0;
};

#endif