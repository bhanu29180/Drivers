#ifndef INTERFACE_IMU
#define INTERFACE_IMU

#include <stdint.h>
#include "Interface_sensor.h"

struct IMU_data
{
    int16_t ax = 0;
    int16_t ay = 0;
    int16_t az = 0;
    int16_t wx = 0;
    int16_t wy = 0;
    int16_t wz = 0;
};

template <typename T_config, typename T_recv, typename T_send>
class Interface_imu: public Interface_sensor<T_config, T_recv, T_send>
{
    public:
        explicit Interface_imu(uint8_t ID_): Interface_sensor<T_config, T_recv, T_send>(ID_) {}
        ~Interface_imu() = default;
        virtual void get_acc_out(int16_t* ax, int16_t* ay, int16_t* az);
        virtual void get_gyro_out(int16_t* wx, int16_t* wy, int16_t* wz);
        virtual int16_t get_temp();
};

#endif