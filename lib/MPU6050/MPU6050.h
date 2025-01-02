#ifndef MPU6050_DRIVER
#define MPU6050_DRIVER

#include <stdint.h>
#include "MPU6050_reg.h"

class MPU6050
{
    public:
        MPU6050();
        void init();
        void test_connection();
        
        void set_SMPLRT_DIV(uint8_t val);
        uint8_t get_SMPLRT_DIV();

        uint8_t get_ext_FSYNC();
    void set_ext_FSYNC(uint8_t sync);
    uint8_t get_DLPF_CFG();
    void set_DLPF_CFG(uint8_t val);
        

    private:
};

#endif