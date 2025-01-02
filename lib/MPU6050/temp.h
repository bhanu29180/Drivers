#ifndef MPU6050_REG
#define MPU6050_REG

#include "stdint.h"

namespace MPU6050
{
    namespace SELF_TEST_X
    {
        uint8_t ADDR = 0x0D;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace SELF_TEST_Y
    {
        uint8_t ADDR = 0x0E;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace SELF_TEST_Z
    {
        uint8_t ADDR = 0x0F;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace SELF_TEST_A
    {
        uint8_t ADDR = 0x10;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace SMPLRT_DIV
    {
        uint8_t ADDR = 0x19;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace CONFIG
    {
        uint8_t ADDR = 0x1A;
        enum Bit_flags : uint8_t
        {
            EXT_SYNC_SET_0 = 0,
            EXT_SYNC_SET_1 = 1,
            EXT_SYNC_SET_2 = 2,
            EXT_SYNC_SET_3 = 3,
            EXT_SYNC_SET_4 = 4,
            EXT_SYNC_SET_5 = 5,
            EXT_SYNC_SET_6 = 6,
            EXT_SYNC_SET_7 = 7,
            DLPF_CFG_0 = 0,
            DLPF_CFG_1 = 1,
            DLPF_CFG_2 = 2,
            DLPF_CFG_3 = 3,
            DLPF_CFG_4 = 4,
            DLPF_CFG_5 = 5,
            DLPF_CFG_6 = 6,
            DLPF_CFG_7 = 7
        };
    }

    namespace GYRO_CONFIG
    {
        uint8_t ADDR = 0x1B;
        enum Bit_flags : uint8_t
        {
            XG_ST_0 = 0,
            XG_ST_1 = 1,
            YG_ST_0 = 0,
            YG_ST_1 = 1,
            ZG_ST_0 = 0,
            ZG_ST_1 = 1,
            FS_SEL_0 = 0,
            FS_SEL_1 = 1,
            FS_SEL_2 = 2,
            FS_SEL_3 = 3
        };
    }

    namespace ACCEL_CONFIG
    {
        uint8_t ADDR = 0x1C;
        enum Bit_flags : uint8_t
        {
            XA_ST_0 = 0,
            XA_ST_1 = 1,
            YA_ST_0 = 0,
            YA_ST_1 = 1,
            ZA_ST_0 = 0,
            ZA_ST_1 = 1,
            FA_SEL_0 = 0,
            AFS_SEL_1 = 1,
            AFS_SEL_2 = 2,
            AFS_SEL_3 = 3
        };
    }

    namespace FIFO_EN
    {
        uint8_t ADDR = 0x23;
        enum Bit_flags : uint8_t
        {
            TEMP_FIFO_EN_0 = 0,
            TEMP_FIFO_EN_1 = 1,
            XG_FIFO_EN_0 = 0,
            XG_FIFO_EN_1 = 1,
            YG_FIFO_EN_0 = 0,
            YG_FIFO_EN_1 = 1,
            ZG_FIFO_EN_0 = 0,
            ZG_FIFO_EN_1 = 1,
            ACCEL_FIFO_EN_0 = 0,
            ACCEL_FIFO_EN_1 = 1,
            SLV2_FIFO_EN_0 = 0,
            SLV2_FIFO_EN_1 = 1,
            SLV1_FIFO_EN_0 = 0,
            SLV1_FIFO_EN_1 = 1,
            SLV0_FIFO_EN_0 = 0,
            SLV0_FIFO_EN_1 = 1
        };
    }

    namespace I2C_MST_CTRL
    {
        uint8_t ADDR = 0x24;
        enum Bit_flags : uint8_t
        {
            MUL_MST_EN_0 = 0,
            MUL_MST_EN_1 = 1,
            WAIT_FOR_ES_0 = 0,
            WAIT_FOR_ES_1 = 1,
            SLV3_FIFO_EN_0 = 0,
            SLV3_FIFO_EN_1 = 1,
            I2C_MST_P_NSR_0 = 0,
            I2C_MST_P_NSR_1 = 1,
            I2C_MST_CLK_0 = 0,
            I2C_MST_CLK_1 = 1,
            I2C_MST_CLK_2 = 2,
            I2C_MST_CLK_3 = 3,
            I2C_MST_CLK_4 = 4,
            I2C_MST_CLK_5 = 5,
            I2C_MST_CLK_6 = 6,
            I2C_MST_CLK_7 = 7,
            I2C_MST_CLK_8 = 8,
            I2C_MST_CLK_9 = 9,
            I2C_MST_CLK_10 = 10,
            I2C_MST_CLK_11 = 11,
            I2C_MST_CLK_12 = 12,
            I2C_MST_CLK_13 = 13,
            I2C_MST_CLK_14 = 14,
            I2C_MST_CLK_15 = 15
        };
    }

    namespace I2C_SLV0_ADDR
    {
        uint8_t ADDR = 0x25;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_SLV0_REG
    {
        uint8_t ADDR = 0x26;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_SLV0_CTRL
    {
        uint8_t ADDR = 0x27;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_SLV1_ADDR
    {
        uint8_t ADDR = 0x28;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_SLV1_REG
    {
        uint8_t ADDR = 0x29;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_SLV1_CTRL
    {
        uint8_t ADDR = 0x2A;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_SLV2_ADD
    {
        uint8_t ADDR = 0x2B;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_SLV2_RE
    {
        uint8_t ADDR = 0x2C;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_SLV2_CTR
    {
        uint8_t ADDR = 0x2D;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_SLV3_ADDR
    {
        uint8_t ADDR = 0x2E;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_SLV3_REG
    {
        uint8_t ADDR = 0x2F;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_SLV3_CTRL
    {
        uint8_t ADDR = 0x30;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_SLV4_ADDR
    {
        uint8_t ADDR = 0x31;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_SLV4_REG
    {
        uint8_t ADDR = 0x32;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_SLV4_DO
    {
        uint8_t ADDR = 0x33;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_SLV4_CTRL
    {
        uint8_t ADDR = 0x34;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_SLV4_DI
    {
        uint8_t ADDR = 0x35;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_MST_STATUS
    {
        uint8_t ADDR = 0x36;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace INT_PIN_CFG
    {
        uint8_t ADDR = 0x37;
        enum Bit_flags : uint8_t
        {
            INT_LEVEL_0 = 0,
            INT_LEVEL_1 = 1,
            INT_OPEN_0 = 0,
            INT_OPEN_1 = 1,
            LATCH_INT_EN_0 = 0,
            LATCH_INT_EN_1 = 1,
            INT_RD_CLEAR_0 = 0,
            INT_RD_CLEAR_1 = 1,
            FSYNC_INT_LEVEL_0 = 0,
            FSYNC_INT_LEVEL_1 = 1,
            FSYNC_INT_EN_0 = 0,
            FSYNC_INT_EN_1 = 1,
            I2C_BYPASS_EN_0 = 0,
            I2C_BYPASS_EN_1 = 1
        };
    }

    namespace INT_ENABLE
    {
        uint8_t ADDR = 0x38;
        enum Bit_flags : uint8_t
        {
            FIFO_OFLOW_EN_0 = 0,
            FIFO_OFLOW_EN_1 = 1,
            I2C_MST_INT_EN_0 = 0,
            I2C_MST_INT_EN_1 = 1,
            DATA_RDY_EN_0 = 0,
            DATA_RDY_EN_1 = 1
        };
    }

    namespace INT_STATUS
    {
        uint8_t ADDR = 0x3A;
        enum Bit_flags : uint8_t
        {
            FIFO_OFLOW_INT_0 = 0,
            FIFO_OFLOW_INT_1 = 1,
            I2C_MST_INT_0 = 0,
            I2C_MST_INT_1 = 1,
            DATA_RDY_INT_0 = 0,
            DATA_RDY_INT_1 = 1
        };
    }

    namespace ACCEL_XOUT_H
    {
        uint8_t ADDR = 0x3B;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace ACCEL_XOUT_L
    {
        uint8_t ADDR = 0x3C;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace ACCEL_YOUT_H
    {
        uint8_t ADDR = 0x3D;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace ACCEL_YOUT_L
    {
        uint8_t ADDR = 0x3E;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace ACCEL_ZOUT_H
    {
        uint8_t ADDR = 0x3F;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace ACCEL_ZOUT_L
    {
        uint8_t ADDR = 0x40;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace TEMP_OUT_H
    {
        uint8_t ADDR = 0x41;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace TEMP_OUT_L
    {
        uint8_t ADDR = 0x42;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace GYRO_XOUT_H
    {
        uint8_t ADDR = 0x43;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace GYRO_XOUT_L
    {
        uint8_t ADDR = 0x44;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace GYRO_YOUT_H
    {
        uint8_t ADDR = 0x45;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace GYRO_YOUT_L
    {
        uint8_t ADDR = 0x46;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace GYRO_ZOUT_H
    {
        uint8_t ADDR = 0x47;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace GYRO_ZOUT_L
    {
        uint8_t ADDR = 0x48;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_00
    {
        uint8_t ADDR = 0x49;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_01
    {
        uint8_t ADDR = 0x4A;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_02
    {
        uint8_t ADDR = 0x4B;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_03
    {
        uint8_t ADDR = 0x4C;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_04
    {
        uint8_t ADDR = 0x4D;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_05
    {
        uint8_t ADDR = 0x4E;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_06
    {
        uint8_t ADDR = 0x4F;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_07
    {
        uint8_t ADDR = 0x50;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_08
    {
        uint8_t ADDR = 0x51;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_09
    {
        uint8_t ADDR = 0x52;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_10
    {
        uint8_t ADDR = 0x53;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_11
    {
        uint8_t ADDR = 0x54;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_12
    {
        uint8_t ADDR = 0x55;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_13
    {
        uint8_t ADDR = 0x56;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_14
    {
        uint8_t ADDR = 0x57;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_15
    {
        uint8_t ADDR = 0x58;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_16
    {
        uint8_t ADDR = 0x59;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_17
    {
        uint8_t ADDR = 0x5A;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_18
    {
        uint8_t ADDR = 0x5B;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_19
    {
        uint8_t ADDR = 0x5C;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_20
    {
        uint8_t ADDR = 0x5D;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_21
    {
        uint8_t ADDR = 0x5E;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_22
    {
        uint8_t ADDR = 0x5F;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace EXT_SENS_DATA_23
    {
        uint8_t ADDR = 0x60;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_SLV0_DO
    {
        uint8_t ADDR = 0x63;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_SLV1_DO
    {
        uint8_t ADDR = 0x64;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_SLV2_DO
    {
        uint8_t ADDR = 0x65;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_SLV3_DO
    {
        uint8_t ADDR = 0x66;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace I2C_MST_DELAY_CTRL
    {
        uint8_t ADDR = 0x67;
        enum Bit_flags : uint8_t
        {
            DELAY_ES_SHADOW_0 = 0,
            DELAY_ES_SHADOW_1 = 1,
            I2C_SLV4_DLY_EN_0 = 0,
            I2C_SLV4_DLY_EN_1 = 1,
            I2C_SLV3_DLY_EN_0 = 0,
            I2C_SLV3_DLY_EN_1 = 1,
            I2C_SLV2_DLY_EN_0 = 0,
            I2C_SLV2_DLY_EN_1 = 1,
            I2C_SLV1_DLY_EN_0 = 0,
            I2C_SLV1_DLY_EN_1 = 1,
            I2C_SLV0_DLY_EN_0 = 0,
            I2C_SLV0_DLY_EN_1 = 1
        };
    }

    namespace SIGNAL_PATH_RESET
    {
        uint8_t ADDR = 0x68;
        enum Bit_flags : uint8_t
        {
            GYRO_RESET_0 = 0,
            GYRO_RESET_1 = 1,
            ACCEL_RESET_0 = 0,
            ACCEL_RESET_1 = 1,
            TEMP_RESET_0 = 0,
            TEMP_RESET_1 = 1
        };
    }

    namespace USER_CTRL
    {
        uint8_t ADDR = 0x6A;
        enum Bit_flags : uint8_t
        {
            FIFO_EN_0 = 0,
            FIFO_EN_1 = 1,
            I2C_MST_EN_0 = 0,
            I2C_MST_EN_1 = 1,
            I2C_IF_DIS_0 = 0,
            I2C_IF_DIS_1 = 1,
            FIFO_RESET_0 = 0,
            FIFO_RESET_1 = 1,
            I2C_MST_RESET_0 = 0,
            I2C_MST_RESET_1 = 1,
            SIG_COND_RESET_0 = 0,
            SIG_COND_RESET_1 = 1
        };
    }

    namespace PWR_MGMT_1
    {
        uint8_t ADDR = 0x6B;
        enum Bit_flags : uint8_t
        {
            DEVICE_RESET_0 = 0,
            DEVICE_RESET_1 = 1,
            SLEEP_0 = 0,
            SLEEP_1 = 1,
            CYCLE_0 = 0,
            CYCLE_1 = 1,
            TEMP_DIS_0 = 0,
            TEMP_DIS_1 = 1,
            CLKSEL_0 = 0,
            CLKSEL_1 = 1,
            CLKSEL_2 = 2,
            CLKSEL_3 = 3,
            CLKSEL_4 = 4,
            CLKSEL_5 = 5,
            CLKSEL_6 = 6,
            CLKSEL_7 = 7
        };
    }

    namespace PWR_MGMT_2
    {
        uint8_t ADDR = 0x6C;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace FIFO_COUNTH
    {
        uint8_t ADDR = 0x72;
        enum Bit_flags : uint8_t
        {
            LP_WAKE_CTRL_0 = 0,
            LP_WAKE_CTRL_1 = 1,
            LP_WAKE_CTRL_2 = 2,
            LP_WAKE_CTRL_3 = 3,
            STBY_XA_0 = 0,
            STBY_XA_1 = 1,
            STBY_YA_0 = 0,
            STBY_YA_1 = 1,
            STBY_ZA_0 = 0,
            STBY_ZA_1 = 1,
            STBY_XG_0 = 0,
            STBY_XG_1 = 1,
            STBY_YG_0 = 0,
            STBY_YG_1 = 1,
            STBY_ZG_0 = 0,
            STBY_ZG_1 = 1
        };
    }

    namespace FIFO_COUNTL
    {
        uint8_t ADDR = 0x73;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace FIFO_R_W
    {
        uint8_t ADDR = 0x74;
        enum Bit_flags : uint8_t
        {
        };
    }

    namespace WHO_AM_I
    {
        uint8_t ADDR = 0x75;
        enum Bit_flags : uint8_t
        {
            bit_0 = 0,
            who_am_i = 0x34,
            bit_7 = 0
        };
    }
}

#endif