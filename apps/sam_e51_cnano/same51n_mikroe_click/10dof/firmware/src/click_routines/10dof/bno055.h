/*
*
****************************************************************************
* Copyright (C) 2013 - 2014 Bosch Sensortec GmbH
*
* File : bno055.h
*
* Date : 2014/12/12 Revision : 2.0.2 $
* Date : 2021/04/30 Revision : 2.0.3 $
* 
*
* Usage: Sensor Driver file for BNO055 sensor
*
****************************************************************************
* \section License
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*   Redistributions of source code must retain the above copyright
*   notice, this list of conditions and the following disclaimer.
*
*   Redistributions in binary form must reproduce the above copyright
*   notice, this list of conditions and the following disclaimer in the
*   documentation and/or other materials provided with the distribution.
*
*   Neither the name of the copyright holder nor the names of the
*   contributors may be used to endorse or promote products derived from
*   this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDER
* OR CONTRIBUTORS BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
* OR CONSEQUENTIAL DAMAGES(INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
* ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE
*
* The information provided is believed to be accurate and reliable.
* The copyright holder assumes no responsibility
* for the consequences of use
* of such information nor for any infringement of patents or
* other rights of third parties which may result from its use.
* No license is granted by implication or otherwise under any patent or
* patent rights of the copyright holder.
**************************************************************************/
/****************************************************************************
* Note: In version 2.0.3, This file has been modified by MKRP to meet the custom
* application requirements. write to
* Microchip Technology India Pvt Ltd
* Plot No. 1498, EPIP, 1st Phase Industrial Area, Whitefield, Bengaluru,
* Karnataka 560066
*******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
 Copyright (C) 2017  Microchip Technology Incorporated and its subsidiaries.

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*******************************************************************************/
// DOM-IGNORE-END
/*! \file bno055.h
    \brief BNO055 Sensor Driver Support Header File */


#ifndef __BNO055_H__
#define __BNO055_H__

#include <stdint.h>
#include <string.h>
#define WRITE 1
#define READ 0
#define MAX_BUFFER_SIZE 512

/*unsigned integer types*/
typedef uint8_t u8;/**< used for unsigned 8bit */
typedef uint16_t u16;/**< used for unsigned 16bit */
typedef uint32_t u32;/**< used for unsigned 32bit */
typedef uint64_t u64;/**< used for unsigned 64bit */

/*signed integer types*/
typedef int8_t s8;/**< used for signed 8bit */
typedef int16_t s16;/**< used for signed 16bit */
typedef int32_t s32;/**< used for signed 32bit */
typedef int64_t s64;/**< used for signed 64bit */
/***************************************************************/
/**\name    BUS READ AND WRITE FUNCTIONS           */
/***************************************************************/
#define BNO055_WR_FUNC_PTR s8 (*bus_write)\
(u8, u8 , u8 *, u8)

#define BNO055_BUS_WRITE_FUNC(dev_addr, reg_addr, reg_data, wr_len)\
    bus_write(dev_addr, reg_addr, reg_data, wr_len)

#define BNO055_RD_FUNC_PTR s8 \
(*bus_read)(u8, u8 , u8 *, u8)

#define BNO055_BUS_READ_FUNC(dev_addr, reg_addr, reg_data, r_len)\
bus_read(dev_addr, reg_addr, reg_data, r_len)

#define BNO055_DELAY_RETURN_TYPE void

#define BNO055_DELAY_PARAM_TYPES u32

#define BNO055_DELAY_FUNC(delay_in_msec)\
    delay_func(delay_in_msec)

/********************************************************/
/**\name    I2C ADDRESS DEFINITION FOR BNO055           */
/********************************************************/
/* bno055 I2C Address */
#define BNO055_I2C_ADDR1                0x28
#define BNO055_I2C_ADDR2                0x29

/***************************************************/
/**\name    REGISTER ADDRESS DEFINITION  */
/***************************************************/
/* Page id register definition*/
#define BNO055_PAGE_ID_ADDR                 0X07

/* PAGE0 REGISTER DEFINITION START*/
#define BNO055_CHIP_ID_ADDR                 0x00
#define BNO055_ACCEL_REV_ID_ADDR            0x01
#define BNO055_MAG_REV_ID_ADDR              0x02
#define BNO055_GYRO_REV_ID_ADDR             0x03
#define BNO055_SW_REV_ID_LSB_ADDR           0x04
#define BNO055_SW_REV_ID_MSB_ADDR           0x05
#define BNO055_BL_REV_ID_ADDR               0X06

/* Accel data register*/
#define BNO055_ACCEL_DATA_X_LSB_ADDR            0X08
#define BNO055_ACCEL_DATA_X_MSB_ADDR            0X09
#define BNO055_ACCEL_DATA_Y_LSB_ADDR            0X0A
#define BNO055_ACCEL_DATA_Y_MSB_ADDR            0X0B
#define BNO055_ACCEL_DATA_Z_LSB_ADDR            0X0C
#define BNO055_ACCEL_DATA_Z_MSB_ADDR            0X0D

/*Gyro data registers*/
#define BNO055_GYRO_DATA_X_LSB_ADDR         0X14
#define BNO055_GYRO_DATA_X_MSB_ADDR         0X15
#define BNO055_GYRO_DATA_Y_LSB_ADDR         0X16
#define BNO055_GYRO_DATA_Y_MSB_ADDR         0X17
#define BNO055_GYRO_DATA_Z_LSB_ADDR         0X18
#define BNO055_GYRO_DATA_Z_MSB_ADDR         0X19

/*Quaternion data registers*/
#define BNO055_QUATERNION_DATA_W_LSB_ADDR   0X20
#define BNO055_QUATERNION_DATA_W_MSB_ADDR   0X21
#define BNO055_QUATERNION_DATA_X_LSB_ADDR   0X22
#define BNO055_QUATERNION_DATA_X_MSB_ADDR   0X23
#define BNO055_QUATERNION_DATA_Y_LSB_ADDR   0X24
#define BNO055_QUATERNION_DATA_Y_MSB_ADDR   0X25
#define BNO055_QUATERNION_DATA_Z_LSB_ADDR   0X26
#define BNO055_QUATERNION_DATA_Z_MSB_ADDR   0X27

/* Mode registers*/
#define BNO055_OPR_MODE_ADDR                0X3D
#define BNO055_PWR_MODE_ADDR                0X3E

/* Accelerometer Offset registers*/
#define ACCEL_OFFSET_X_LSB_ADDR             0X55
#define ACCEL_OFFSET_X_MSB_ADDR             0X56
#define ACCEL_OFFSET_Y_LSB_ADDR             0X57
#define ACCEL_OFFSET_Y_MSB_ADDR             0X58
#define ACCEL_OFFSET_Z_LSB_ADDR             0X59
#define ACCEL_OFFSET_Z_MSB_ADDR             0X5A

/* Gyroscope Offset registers*/
#define GYRO_OFFSET_X_LSB_ADDR              0X61
#define GYRO_OFFSET_X_MSB_ADDR              0X62
#define GYRO_OFFSET_Y_LSB_ADDR              0X63
#define GYRO_OFFSET_Y_MSB_ADDR              0X64
#define GYRO_OFFSET_Z_LSB_ADDR              0X65
#define GYRO_OFFSET_Z_MSB_ADDR              0X66

/* Radius registers*/
#define ACCEL_RADIUS_LSB_ADDR               0X67
#define ACCEL_RADIUS_MSB_ADDR               0X68
/* PAGE0 REGISTERS DEFINITION END*/

/* PAGE1 REGISTERS DEFINITION START*/
/* Configuration registers*/
#define ACCEL_CONFIG_ADDR                   0X08
#define MAG_CONFIG_ADDR                     0X09
#define GYRO_CONFIG_ADDR                    0X0A
#define GYRO_MODE_CONFIG_ADDR               0X0B
#define ACCEL_SLEEP_CONFIG_ADDR             0X0C
#define GYRO_SLEEP_CONFIG_ADDR              0X0D
#define MAG_SLEEP_CONFIG_ADDR               0x0E

/* Interrupt registers*/
#define INT_MASK_ADDR                       0X0F
#define INT_ADDR                            0X10
#define ACCEL_ANY_MOTION_THRES_ADDR         0X11
#define ACCEL_INTR_SETTINGS_ADDR                0X12
#define ACCEL_HIGH_G_DURN_ADDR              0X13
#define ACCEL_HIGH_G_THRES_ADDR             0X14
#define ACCEL_NO_MOTION_THRES_ADDR          0X15
#define ACCEL_NO_MOTION_SET_ADDR                0X16
#define GYRO_INTR_SETING_ADDR               0X17
#define GYRO_HIGHRATE_X_SET_ADDR            0X18
#define GYRO_DURN_X_ADDR                        0X19
#define GYRO_HIGHRATE_Y_SET_ADDR            0X1A
#define GYRO_DURN_Y_ADDR                        0X1B
#define GYRO_HIGHRATE_Z_SET_ADDR            0X1C
#define GYRO_DURN_Z_ADDR                        0X1D
#define GYRO_ANY_MOTION_THRES_ADDR          0X1E
#define GYRO_ANY_MOTION_SET_ADDR                0X1F
/* PAGE1 REGISTERS DEFINITION END*/


#define BNO055_MDELAY_DATA_TYPE           u32

/*< This refers BNO055 return type as s8 */
#define BNO055_RETURN_FUNCTION_TYPE        s8

/**************************************************************/
/**\name    STRUCTURE DEFINITIONS                         */
/**************************************************************/
/*!
*   @brief bno055 struct
*/
struct bno055_t
{
    u8 chip_id;/**< chip_id of bno055 */
    u16 sw_rev_id;/**< software revision id of bno055 */
    u8 page_id;/**< page_id of bno055 */
    u8 accel_rev_id;/**< accel revision id of bno055 */
    u8 mag_rev_id;/**< mag revision id of bno055 */
    u8 gyro_rev_id;/**< gyro revision id of bno055 */
    u8 bl_rev_id;/**< boot loader revision id of bno055 */
    u8 dev_addr;/**< i2c device address of bno055 */
    BNO055_WR_FUNC_PTR;/**< bus write function pointer */
    BNO055_RD_FUNC_PTR;/**<bus read function pointer */
    void ( *delay_msec )(
        BNO055_MDELAY_DATA_TYPE ); /**< delay function pointer */
};
/*!
* @brief struct for accel data read from registers
*/
struct bno055_accel_t
{
    s16 x;/**< accel x data */
    s16 y;/**< accel y data */
    s16 z;/**< accel z data */
};

/*!
* @brief struct for Gyro data read from registers
*/
struct bno055_gyro_t
{
    s16 x;/**< gyro x data */
    s16 y;/**< gyro y data */
    s16 z;/**< gyro z data */
};
/*!
* @brief struct for Quaternion data read from registers
*/
struct bno055_quaternion_t
{
    s16 w;/**< Quaternion w data */
    s16 x;/**< Quaternion x data */
    s16 y;/**< Quaternion y data */
    s16 z;/**< Quaternion z data */
};
/***************************************************/
/**\name    CONSTANT DEFINITIONS                   */
/***************************************************/
#define         BNO055_ZERO_U8X           ((u8)0)
#define         BNO055_ONE_U8X           ((u8)1)
#define         BNO055_TWO_U8X            ((u8)2)
#define         BNO055_FOUR_U8X           ((u8)4)
#define         BNO055_FIVE_U8X           ((u8)5)
#define         BNO055_SIX_U8X            ((u8)6)
#define         BNO055_SEVEN_U8X          ((u8)7)
#define         BNO055_ELEVEN_U8X         ((u8)11)
#define         BNO055_SIXTEEN_U8X        ((u8)16)
#define         BNO055_EIGHT_U8X          ((u8)8)
#define         BNO055_TWENTY_U8X         ((u8)20)
#define         BNO055_EIGHTEEN_U8X       ((u8)18)


#define         BNO055_SHIFT_8_POSITION    ((u8)8)


/*  BNO055 API error codes */
#define E_NULL_PTR                  ((s8)-127)
#define E_BNO055_OUT_OF_RANGE       ((s8)-2)
#define SUCCESS                     ((u8)0)
#define ERROR                       ((s8)-1)

/* Selection for bit enable and disable */
#define ENABLED     0x01
#define DISABLED    0x00

/* Page ID */
#define PAGE_ZERO       0X00
#define PAGE_ONE        0X01

/* Enable the temperature source */
#define ACCEL_TEMP_EN   0x00
#define GYRO_TEMP_EN    0x01
#define MCU_TEMP_EN     0x03

/*Accel unit*/
#define ACCEL_UNIT_MSQ  0x00
#define ACCEL_UNIT_MG   0x01

/*Gyro unit*/
#define GYRO_UNIT_DPS   0x00
#define GYRO_UNIT_RPS   0x01

/* Euler unit*/
#define EULER_UNIT_DEG  0x00
#define EULER_UNIT_RAD  0x01

/*Temperature unit*/
#define TEMP_UNIT_CELSIUS       0x00
#define TEMP_UNIT_FAHRENHEIT    0x01

/*Accel division factor*/
#define ACCEL_DIV_MSQ   100.0
#define ACCEL_DIV_MG    1

/*Mag division factor*/
#define MAG_DIV_UT  16.0

/*Gyro division factor*/
#define GYRO_DIV_DPS        16.0
#define GYRO_DIV_RPS        900.0

/*Euler division factor*/
#define EULER_DIV_DEG       16.0
#define EULER_DIV_RAD       900.0

/*Linear accel division factor*/
#define LINEAR_ACCEL_DIV_MSQ    100.0

/*Gravity accel division factor*/
#define GRAVITY_DIV_MSQ 100.0

/* Temperature division factor*/
#define TEMP_DIV_FAHRENHEIT 0.5
#define TEMP_DIV_CELSIUS    1

#define BNO055_SIX_HUNDRES_U8X  600



/* Operation mode settings*/
#define OPERATION_MODE_CONFIG           0X00
#define OPERATION_MODE_ACCONLY          0X01
#define OPERATION_MODE_MAGONLY          0X02
#define OPERATION_MODE_GYRONLY          0X03
#define OPERATION_MODE_ACCMAG           0X04
#define OPERATION_MODE_ACCGYRO          0X05
#define OPERATION_MODE_MAGGYRO          0X06
#define OPERATION_MODE_AMG              0X07
#define OPERATION_MODE_IMUPLUS          0X08
#define OPERATION_MODE_COMPASS          0X09
#define OPERATION_MODE_M4G              0X0A
#define OPERATION_MODE_NDOF_FMC_OFF     0X0B
#define OPERATION_MODE_NDOF             0X0C

/* Power mode*/
#define POWER_MODE_NORMAL   0X00
#define POWER_MODE_LOWPOWER 0X01
#define POWER_MODE_SUSPEND  0X02

/* PAGE-1 definitions*/
/* Accel Range */

#define ACCEL_RANGE_2G      0X00
#define ACCEL_RANGE_4G      0X01
#define ACCEL_RANGE_8G      0X02
#define ACCEL_RANGE_16G     0X03

/* Accel Bandwidth*/
#define ACCEL_BW_7_81HZ     0x00
#define ACCEL_BW_15_63HZ    0x01
#define ACCEL_BW_31_25HZ    0x02
#define ACCEL_BW_62_5HZ     0X03
#define ACCEL_BW_125HZ      0X04
#define ACCEL_BW_250HZ      0X05
#define ACCEL_BW_500HZ      0X06
#define ACCEL_BW_1000HZ     0X07

/* Accel Power mode*/
#define ACCEL_NORMAL            0X00
#define ACCEL_SUSPEND           0X01
#define ACCEL_LOWPOWER_1        0X02
#define ACCEL_STANDBY           0X03
#define ACCEL_LOWPOWER_2        0X04
#define ACCEL_DEEPSUSPEND       0X05

/* Gyro range*/
#define GYRO_RANGE_2000DPS      0x00
#define GYRO_RANGE_1000DPS      0x01
#define GYRO_RANGE_500DPS       0x02
#define GYRO_RANGE_250DPS       0x03
#define GYRO_RANGE_125DPS       0x04

/* Gyro Bandwidth*/
#define GYRO_BW_523HZ       0x00
#define GYRO_BW_230HZ       0x01
#define GYRO_BW_116HZ       0x02
#define GYRO_BW_47HZ        0x03
#define GYRO_BW_23HZ        0x04
#define GYRO_BW_12HZ        0x05
#define GYRO_BW_64HZ        0x06
#define GYRO_BW_32HZ        0x07

/* Gyro power mode*/
#define GYRO_POWER_MODE_NORMAL              0X00
#define GYRO_POWER_MODE_FASTPOWERUP         0X01
#define GYRO_POWER_MODE_DEEPSUSPEND         0X02
#define GYRO_POWER_MODE_SUSPEND             0X03
#define GYRO_POWER_MODE_ADVANCE_POWERSAVE   0X04

/* Accel Sleep Duration */
#define BNO055_ACCEL_SLEEP_DURN_0_5MS        0x05
/* sets sleep duration to 0.5 ms  */
#define BNO055_ACCEL_SLEEP_DURN_1MS          0x06
/* sets sleep duration to 1 ms */
#define BNO055_ACCEL_SLEEP_DURN_2MS          0x07
/* sets sleep duration to 2 ms */
#define BNO055_ACCEL_SLEEP_DURN_4MS          0x08
/* sets sleep duration to 4 ms */
#define BNO055_ACCEL_SLEEP_DURN_6MS          0x09
/* sets sleep duration to 6 ms*/
#define BNO055_ACCEL_SLEEP_DURN_10MS         0x0A
/* sets sleep duration to 10 ms */
#define BNO055_ACCEL_SLEEP_DURN_25MS         0x0B
/* sets sleep duration to 25 ms */
#define BNO055_ACCEL_SLEEP_DURN_50MS         0x0C
/* sets sleep duration to 50 ms */
#define BNO055_ACCEL_SLEEP_DURN_100MS        0x0D
/* sets sleep duration to 100 ms */
#define BNO055_ACCEL_SLEEP_DURN_500MS        0x0E
/* sets sleep duration to 500 ms */
#define BNO055_ACCEL_SLEEP_DURN_1S           0x0F
/* sets sleep duration to 1 s */

/* Gyro Auto sleep duration*/
#define BNO055_GYRO_No_AUTOSLPDUR       0x00
#define BNO055_GYRO_4MS_AUTOSLPDUR      0x01
#define BNO055_GYRO_5MS_AUTOSLPDUR      0x02
#define BNO055_GYRO_8MS_AUTOSLPDUR      0x03
#define BNO055_GYRO_10MS_AUTOSLPDUR     0x04
#define BNO055_GYRO_15MS_AUTOSLPDUR     0x05
#define BNO055_GYRO_20MS_AUTOSLPDUR     0x06
#define BNO055_GYRO_40MS_AUTOSLPDUR     0x07

/* Accel Any/No motion axis selection*/
#define BNO055_ACCEL_ANY_MOTION_NO_MOTION_X_AXIS        0
#define BNO055_ACCEL_ANY_MOTION_NO_MOTION_Y_AXIS        1
#define BNO055_ACCEL_ANY_MOTION_NO_MOTION_Z_AXIS        2

/* Accel High g axis selection*/
#define BNO055_ACCEL_HIGH_G_X_AXIS      0
#define BNO055_ACCEL_HIGH_G_Y_AXIS      1
#define BNO055_ACCEL_HIGH_G_Z_AXIS      2

/* Gyro Any motion axis selection*/
#define BNO055_GYRO_ANY_MOTION_X_AXIS       0
#define BNO055_GYRO_ANY_MOTION_Y_AXIS       1
#define BNO055_GYRO_ANY_MOTION_Z_AXIS       2


/* Gyro High rate axis selection*/
#define BNO055_GYRO_HIGHRATE_X_AXIS     0
#define BNO055_GYRO_HIGHRATE_Y_AXIS     1
#define BNO055_GYRO_HIGHRATE_Z_AXIS     2

/* Axis remap values*/
#define REMAP_X_Y           0X21
#define REMAP_Y_Z           0X18
#define REMAP_Z_X           0X06
#define REMAP_X_Y_Z_TYPE0   0X12
#define REMAP_X_Y_Z_TYPE1   0X09
#define DEFAULT_AXIS        0X24

/* Axis remap sign */
#define REMAP_AXIS_POSITIVE 0X00
#define REMAP_AXIS_NEGATIVE 0X01

/* Gyro anymotion and high rate filter configuration */
#define FILTERED    0x00
#define UNFILTERED  0x01

/* mask definitions*/
#define BNO055_SIC_HEX_0_0_F_F_DATA     0x00FF
/****************************************************/
/**\name    ARRAY SIZE DEFINITIONS      */
/***************************************************/
#define ARRAY_SIZE_TWO      2
#define ARRAY_SIZE_THREE    3
#define ARRAY_SIZE_SIX      6
#define ARRAY_SIZE_FIVE     5
#define ARRAY_SIZE_EIGHT    8
#define ARRAY_SIZE_TWELVE   12
#define ARRAY_SIZE_FOURTEEN 14
#define ARRAY_SIZE_EIGHTEEN 18
#define ARRAY_SIZE_TWENTY_SIX   26

#define INDEX_ZERO      0
#define INDEX_ONE       1
#define INDEX_TWO       2
#define INDEX_THREE     3
#define INDEX_FOUR      4
#define INDEX_FIVE      5
#define INDEX_SIX       6
#define INDEX_SEVEN     7
#define INDEX_EIGHT     8
#define INDEX_NINE      9
#define INDEX_TEN       10
#define INDEX_ELEVEN    11
#define INDEX_TWELVE    12
#define INDEX_THIRTEEN  13
#define INDEX_FOURTEEN  14
#define INDEX_FIVETEEN  15
#define INDEX_SIXTEEN   16
#define INDEX_SEVENTEEN 17
#define INDEX_EIGHTEEN  18
#define INDEX_NINETEEN  19
#define INDEX_TWENTY    20
#define INDEX_TWENTY_ONE    21
#define INDEX_TWENTY_TWO    22
#define INDEX_TWENTY_THREE  23
#define INDEX_TWENTY_FIVE   25
/****************************************************/
/**\name    ARRAY PARAMETERS      */
/***************************************************/
#define LSB_ZERO    0
#define MSB_ONE     1
#define LSB_TWO     2
#define MSB_THREE   3
#define LSB_FOUR    4
#define MSB_FIVE    5
#define LSB_SIX     6
#define MSB_SEVEN   7
/*********************************************************/
/**\name PAGE0 DATA REGISTERS DEFINITION */
/*********************************************************/
/* Chip ID */
#define BNO055_CHIP_ID__POS             0
#define BNO055_CHIP_ID__MSK             0xFF
#define BNO055_CHIP_ID__LEN             8
#define BNO055_CHIP_ID__REG             BNO055_CHIP_ID_ADDR

/* Accel revision id*/
#define BNO055_ACCEL_REV_ID__POS             0
#define BNO055_ACCEL_REV_ID__MSK             0xFF
#define BNO055_ACCEL_REV_ID__LEN             8
#define BNO055_ACCEL_REV_ID__REG             BNO055_ACCEL_REV_ID_ADDR

/* Mag revision id*/
#define BNO055_MAG_REV_ID__POS             0
#define BNO055_MAG_REV_ID__MSK             0xFF
#define BNO055_MAG_REV_ID__LEN             8
#define BNO055_MAG_REV_ID__REG             BNO055_MAG_REV_ID_ADDR

/* Gyro revision id*/
#define BNO055_GYRO_REV_ID__POS             0
#define BNO055_GYRO_REV_ID__MSK             0xFF
#define BNO055_GYRO_REV_ID__LEN             8
#define BNO055_GYRO_REV_ID__REG             BNO055_GYRO_REV_ID_ADDR

/*Software revision id LSB*/
#define BNO055_SW_REV_ID_LSB__POS             0
#define BNO055_SW_REV_ID_LSB__MSK             0xFF
#define BNO055_SW_REV_ID_LSB__LEN             8
#define BNO055_SW_REV_ID_LSB__REG             BNO055_SW_REV_ID_LSB_ADDR

/*Software revision id MSB*/
#define BNO055_SW_REV_ID_MSB__POS             0
#define BNO055_SW_REV_ID_MSB__MSK             0xFF
#define BNO055_SW_REV_ID_MSB__LEN             8
#define BNO055_SW_REV_ID_MSB__REG             BNO055_SW_REV_ID_MSB_ADDR

/* BOOTLODER revision id*/
#define BNO055_BL_REV_ID__POS             0
#define BNO055_BL_REV_ID__MSK             0xFF
#define BNO055_BL_REV_ID__LEN             8
#define BNO055_BL_REV_ID__REG             BNO055_BL_REV_ID_ADDR

/*Page id*/
#define BNO055_PAGE_ID__POS             0
#define BNO055_PAGE_ID__MSK             0xFF
#define BNO055_PAGE_ID__LEN             8
#define BNO055_PAGE_ID__REG             BNO055_PAGE_ID_ADDR

/* Accel data X-LSB register*/
#define BNO055_ACCEL_DATA_X_LSB_VALUEX__POS             0
#define BNO055_ACCEL_DATA_X_LSB_VALUEX__MSK             0xFF
#define BNO055_ACCEL_DATA_X_LSB_VALUEX__LEN             8
#define BNO055_ACCEL_DATA_X_LSB_VALUEX__REG             \
BNO055_ACCEL_DATA_X_LSB_ADDR

/* Accel data X-MSB register*/
#define BNO055_ACCEL_DATA_X_MSB_VALUEX__POS             0
#define BNO055_ACCEL_DATA_X_MSB_VALUEX__MSK             0xFF
#define BNO055_ACCEL_DATA_X_MSB_VALUEX__LEN             8
#define BNO055_ACCEL_DATA_X_MSB_VALUEX__REG             \
BNO055_ACCEL_DATA_X_MSB_ADDR

/* Accel data Y-LSB register*/
#define BNO055_ACCEL_DATA_Y_LSB_VALUEY__POS             0
#define BNO055_ACCEL_DATA_Y_LSB_VALUEY__MSK             0xFF
#define BNO055_ACCEL_DATA_Y_LSB_VALUEY__LEN             8
#define BNO055_ACCEL_DATA_Y_LSB_VALUEY__REG             \
BNO055_ACCEL_DATA_Y_LSB_ADDR

/* Accel data Y-MSB register*/
#define BNO055_ACCEL_DATA_Y_MSB_VALUEY__POS             0
#define BNO055_ACCEL_DATA_Y_MSB_VALUEY__MSK             0xFF
#define BNO055_ACCEL_DATA_Y_MSB_VALUEY__LEN             8
#define BNO055_ACCEL_DATA_Y_MSB_VALUEY__REG             \
BNO055_ACCEL_DATA_Y_MSB_ADDR

/* Accel data Z-LSB register*/
#define BNO055_ACCEL_DATA_Z_LSB_VALUEZ__POS     0
#define BNO055_ACCEL_DATA_Z_LSB_VALUEZ__MSK     0xFF
#define BNO055_ACCEL_DATA_Z_LSB_VALUEZ__LEN     8
#define BNO055_ACCEL_DATA_Z_LSB_VALUEZ__REG     \
BNO055_ACCEL_DATA_Z_LSB_ADDR

/* Accel data Z-MSB register*/
#define BNO055_ACCEL_DATA_Z_MSB_VALUEZ__POS     0
#define BNO055_ACCEL_DATA_Z_MSB_VALUEZ__MSK     0xFF
#define BNO055_ACCEL_DATA_Z_MSB_VALUEZ__LEN     8
#define BNO055_ACCEL_DATA_Z_MSB_VALUEZ__REG     \
BNO055_ACCEL_DATA_Z_MSB_ADDR

/* Gyro data X-LSB register*/
#define BNO055_GYRO_DATA_X_LSB_VALUEX__POS  0
#define BNO055_GYRO_DATA_X_LSB_VALUEX__MSK  0xFF
#define BNO055_GYRO_DATA_X_LSB_VALUEX__LEN  8
#define BNO055_GYRO_DATA_X_LSB_VALUEX__REG  BNO055_GYRO_DATA_X_LSB_ADDR

/* Gyro data X-MSB register*/
#define BNO055_GYRO_DATA_X_MSB_VALUEX__POS  0
#define BNO055_GYRO_DATA_X_MSB_VALUEX__MSK  0xFF
#define BNO055_GYRO_DATA_X_MSB_VALUEX__LEN  8
#define BNO055_GYRO_DATA_X_MSB_VALUEX__REG  BNO055_GYRO_DATA_X_MSB_ADDR

/* Gyro data Y-LSB register*/
#define BNO055_GYRO_DATA_Y_LSB_VALUEY__POS  0
#define BNO055_GYRO_DATA_Y_LSB_VALUEY__MSK  0xFF
#define BNO055_GYRO_DATA_Y_LSB_VALUEY__LEN  8
#define BNO055_GYRO_DATA_Y_LSB_VALUEY__REG  BNO055_GYRO_DATA_Y_LSB_ADDR

/* Gyro data Y-MSB register*/
#define BNO055_GYRO_DATA_Y_MSB_VALUEY__POS  0
#define BNO055_GYRO_DATA_Y_MSB_VALUEY__MSK  0xFF
#define BNO055_GYRO_DATA_Y_MSB_VALUEY__LEN  8
#define BNO055_GYRO_DATA_Y_MSB_VALUEY__REG  BNO055_GYRO_DATA_Y_MSB_ADDR

/* Gyro data Z-LSB register*/
#define BNO055_GYRO_DATA_Z_LSB_VALUEZ__POS  0
#define BNO055_GYRO_DATA_Z_LSB_VALUEZ__MSK  0xFF
#define BNO055_GYRO_DATA_Z_LSB_VALUEZ__LEN  8
#define BNO055_GYRO_DATA_Z_LSB_VALUEZ__REG  BNO055_GYRO_DATA_Z_LSB_ADDR

/* Gyro data Z-MSB register*/
#define BNO055_GYRO_DATA_Z_MSB_VALUEZ__POS  0
#define BNO055_GYRO_DATA_Z_MSB_VALUEZ__MSK  0xFF
#define BNO055_GYRO_DATA_Z_MSB_VALUEZ__LEN  8
#define BNO055_GYRO_DATA_Z_MSB_VALUEZ__REG  BNO055_GYRO_DATA_Z_MSB_ADDR

/* Quaternion data W-LSB register*/
#define BNO055_QUATERNION_DATA_W_LSB_VALUEW__POS  0
#define BNO055_QUATERNION_DATA_W_LSB_VALUEW__MSK  0xFF
#define BNO055_QUATERNION_DATA_W_LSB_VALUEW__LEN  8
#define BNO055_QUATERNION_DATA_W_LSB_VALUEW__REG  \
BNO055_QUATERNION_DATA_W_LSB_ADDR

/* Quaternion data W-MSB register*/
#define BNO055_QUATERNION_DATA_W_MSB_VALUEW__POS  0
#define BNO055_QUATERNION_DATA_W_MSB_VALUEW__MSK  0xFF
#define BNO055_QUATERNION_DATA_W_MSB_VALUEW__LEN  8
#define BNO055_QUATERNION_DATA_W_MSB_VALUEW__REG  \
BNO055_QUATERNION_DATA_W_MSB_ADDR

/* Quaternion data X-LSB register*/
#define BNO055_QUATERNION_DATA_X_LSB_VALUEX__POS  0
#define BNO055_QUATERNION_DATA_X_LSB_VALUEX__MSK  0xFF
#define BNO055_QUATERNION_DATA_X_LSB_VALUEX__LEN  8
#define BNO055_QUATERNION_DATA_X_LSB_VALUEX__REG  \
BNO055_QUATERNION_DATA_X_LSB_ADDR

/* Quaternion data X-MSB register*/
#define BNO055_QUATERNION_DATA_X_MSB_VALUEX__POS  0
#define BNO055_QUATERNION_DATA_X_MSB_VALUEX__MSK  0xFF
#define BNO055_QUATERNION_DATA_X_MSB_VALUEX__LEN  8
#define BNO055_QUATERNION_DATA_X_MSB_VALUEX__REG \
BNO055_QUATERNION_DATA_X_MSB_ADDR

/* Quaternion data Y-LSB register*/
#define BNO055_QUATERNION_DATA_Y_LSB_VALUEY__POS  0
#define BNO055_QUATERNION_DATA_Y_LSB_VALUEY__MSK  0xFF
#define BNO055_QUATERNION_DATA_Y_LSB_VALUEY__LEN  8
#define BNO055_QUATERNION_DATA_Y_LSB_VALUEY__REG \
BNO055_QUATERNION_DATA_Y_LSB_ADDR

/* Quaternion data Y-MSB register*/
#define BNO055_QUATERNION_DATA_Y_MSB_VALUEY__POS  0
#define BNO055_QUATERNION_DATA_Y_MSB_VALUEY__MSK  0xFF
#define BNO055_QUATERNION_DATA_Y_MSB_VALUEY__LEN  8
#define BNO055_QUATERNION_DATA_Y_MSB_VALUEY__REG  \
NO055_QUATERNION_DATA_Y_MSB_ADDR

/* Quaternion data Z-LSB register*/
#define BNO055_QUATERNION_DATA_Z_LSB_VALUEZ__POS  0
#define BNO055_QUATERNION_DATA_Z_LSB_VALUEZ__MSK  0xFF
#define BNO055_QUATERNION_DATA_Z_LSB_VALUEZ__LEN  8
#define BNO055_QUATERNION_DATA_Z_LSB_VALUEZ__REG \
BNO055_QUATERNION_DATA_Z_LSB_ADDR

/* Quaternion data Z-MSB register*/
#define BNO055_QUATERNION_DATA_Z_MSB_VALUEZ__POS  0
#define BNO055_QUATERNION_DATA_Z_MSB_VALUEZ__MSK  0xFF
#define BNO055_QUATERNION_DATA_Z_MSB_VALUEZ__LEN  8
#define BNO055_QUATERNION_DATA_Z_MSB_VALUEZ__REG  \
BNO055_QUATERNION_DATA_Z_MSB_ADDR

/* Temperature register*/
#define BNO055_TEMP__POS             0
#define BNO055_TEMP__MSK             0xFF
#define BNO055_TEMP__LEN             8
#define BNO055_TEMP__REG             BNO055_TEMP_ADDR

/*Acc_Calib status register*/
#define BNO055_ACCEL_CALIB_STAT__POS             2
#define BNO055_ACCEL_CALIB_STAT__MSK             0X0C
#define BNO055_ACCEL_CALIB_STAT__LEN             2
#define BNO055_ACCEL_CALIB_STAT__REG             BNO055_CALIB_STAT_ADDR

/*Gyro_Calib status register*/
#define BNO055_GYRO_CALIB_STAT__POS             4
#define BNO055_GYRO_CALIB_STAT__MSK             0X30
#define BNO055_GYRO_CALIB_STAT__LEN             2
#define BNO055_GYRO_CALIB_STAT__REG             BNO055_CALIB_STAT_ADDR

/*Sys_Calib status register*/
#define BNO055_SYS_CALIB_STAT__POS             6
#define BNO055_SYS_CALIB_STAT__MSK             0XC0
#define BNO055_SYS_CALIB_STAT__LEN             2
#define BNO055_SYS_CALIB_STAT__REG             BNO055_CALIB_STAT_ADDR

/*ST_ACCEL register*/
#define BNO055_SELFTEST_ACCEL__POS             0
#define BNO055_SELFTEST_ACCEL__MSK             0X01
#define BNO055_SELFTEST_ACCEL__LEN             1
#define BNO055_SELFTEST_ACCEL__REG             BNO055_SELFTEST_RESULT_ADDR

/*ST_MAG register*/
#define BNO055_SELFTEST_MAG__POS             1
#define BNO055_SELFTEST_MAG__MSK             0X02
#define BNO055_SELFTEST_MAG__LEN             1
#define BNO055_SELFTEST_MAG__REG             BNO055_SELFTEST_RESULT_ADDR

/*ST_GYRO register*/
#define BNO055_SELFTEST_GYRO__POS             2
#define BNO055_SELFTEST_GYRO__MSK             0X04
#define BNO055_SELFTEST_GYRO__LEN             1
#define BNO055_SELFTEST_GYRO__REG             BNO055_SELFTEST_RESULT_ADDR

/*ST_MCU register*/
#define BNO055_SELFTEST_MCU__POS             3
#define BNO055_SELFTEST_MCU__MSK             0X08
#define BNO055_SELFTEST_MCU__LEN             1
#define BNO055_SELFTEST_MCU__REG             BNO055_SELFTEST_RESULT_ADDR

/*Interrupt status registers*/
#define BNO055_INTR_STAT_GYRO_ANY_MOTION__POS       2
#define BNO055_INTR_STAT_GYRO_ANY_MOTION__MSK       0X04
#define BNO055_INTR_STAT_GYRO_ANY_MOTION__LEN       1
#define BNO055_INTR_STAT_GYRO_ANY_MOTION__REG       BNO055_INTR_STAT_ADDR

#define BNO055_INTR_STAT_GYRO_HIGHRATE__POS     3
#define BNO055_INTR_STAT_GYRO_HIGHRATE__MSK     0X08
#define BNO055_INTR_STAT_GYRO_HIGHRATE__LEN     1
#define BNO055_INTR_STAT_GYRO_HIGHRATE__REG     BNO055_INTR_STAT_ADDR

#define BNO055_INTR_STAT_ACCEL_HIGH_G__POS      5
#define BNO055_INTR_STAT_ACCEL_HIGH_G__MSK      0X20
#define BNO055_INTR_STAT_ACCEL_HIGH_G__LEN      1
#define BNO055_INTR_STAT_ACCEL_HIGH_G__REG      BNO055_INTR_STAT_ADDR

#define BNO055_INTR_STAT_ACCEL_ANY_MOTION__POS      6
#define BNO055_INTR_STAT_ACCEL_ANY_MOTION__MSK      0X40
#define BNO055_INTR_STAT_ACCEL_ANY_MOTION__LEN      1
#define BNO055_INTR_STAT_ACCEL_ANY_MOTION__REG      BNO055_INTR_STAT_ADDR

#define BNO055_INTR_STAT_ACCEL_NO_MOTION__POS       7
#define BNO055_INTR_STAT_ACCEL_NO_MOTION__MSK       0X80
#define BNO055_INTR_STAT_ACCEL_NO_MOTION__LEN       1
#define BNO055_INTR_STAT_ACCEL_NO_MOTION__REG       BNO055_INTR_STAT_ADDR

/* system clock status register*/
#define BNO055_SYS_MAIN_CLK__POS        0
#define BNO055_SYS_MAIN_CLK__MSK        0X10
#define BNO055_SYS_MAIN_CLK__LEN        1
#define BNO055_SYS_MAIN_CLK__REG        BNO055_SYS_CLK_STAT_ADDR

/* System registers*/
#define BNO055_SYS_STAT_CODE__POS       0
#define BNO055_SYS_STAT_CODE__MSK       0XFF
#define BNO055_SYS_STAT_CODE__LEN       8
#define BNO055_SYS_STAT_CODE__REG       BNO055_SYS_STAT_ADDR

#define BNO055_SYS_ERROR_CODE__POS          0
#define BNO055_SYS_ERROR_CODE__MSK          0XFF
#define BNO055_SYS_ERROR_CODE__LEN          8
#define BNO055_SYS_ERROR_CODE__REG          BNO055_SYS_ERR_ADDR

/* Accel_Unit register*/
#define BNO055_ACCEL_UNIT__POS             0
#define BNO055_ACCEL_UNIT__MSK             0X01
#define BNO055_ACCEL_UNIT__LEN             1
#define BNO055_ACCEL_UNIT__REG             BNO055_UNIT_SEL_ADDR

/* Gyro_Unit register*/
#define BNO055_GYRO_UNIT__POS             1
#define BNO055_GYRO_UNIT__MSK             0X02
#define BNO055_GYRO_UNIT__LEN             1
#define BNO055_GYRO_UNIT__REG             BNO055_UNIT_SEL_ADDR

/* Euler_Unit register*/
#define BNO055_EULER_UNIT__POS             2
#define BNO055_EULER_UNIT__MSK             0X04
#define BNO055_EULER_UNIT__LEN             1
#define BNO055_EULER_UNIT__REG             BNO055_UNIT_SEL_ADDR

/* Tilt_Unit register*/
#define BNO055_TILT_UNIT__POS             3
#define BNO055_TILT_UNIT__MSK             0X08
#define BNO055_TILT_UNIT__LEN             1
#define BNO055_TILT_UNIT__REG             BNO055_UNIT_SEL_ADDR

/* Temperature_Unit register*/
#define BNO055_TEMP_UNIT__POS             4
#define BNO055_TEMP_UNIT__MSK             0X10
#define BNO055_TEMP_UNIT__LEN             1
#define BNO055_TEMP_UNIT__REG             BNO055_UNIT_SEL_ADDR

/* ORI android-windows register*/
#define BNO055_DATA_OUTPUT_FORMAT__POS             7
#define BNO055_DATA_OUTPUT_FORMAT__MSK             0X80
#define BNO055_DATA_OUTPUT_FORMAT__LEN             1
#define BNO055_DATA_OUTPUT_FORMAT__REG             BNO055_UNIT_SEL_ADDR
/*Operation Mode data register*/
#define BNO055_OPERATION_MODE__POS          0
#define BNO055_OPERATION_MODE__MSK          0X0F
#define BNO055_OPERATION_MODE__LEN          4
#define BNO055_OPERATION_MODE__REG          BNO055_OPR_MODE_ADDR
/* Power Mode register*/
#define BNO055_POWER_MODE__POS             0
#define BNO055_POWER_MODE__MSK             0X03
#define BNO055_POWER_MODE__LEN             2
#define BNO055_POWER_MODE__REG             BNO055_PWR_MODE_ADDR

/*Self Test register*/
#define BNO055_SELFTEST__POS            0
#define BNO055_SELFTEST__MSK            0X01
#define BNO055_SELFTEST__LEN            1
#define BNO055_SELFTEST__REG            BNO055_SYS_TRIGGER_ADDR

/* RST_SYS register*/
#define BNO055_SYS_RST__POS             5
#define BNO055_SYS_RST__MSK             0X20
#define BNO055_SYS_RST__LEN             1
#define BNO055_SYS_RST__REG             BNO055_SYS_TRIGGER_ADDR

/* RST_INT register*/
#define BNO055_INTR_RST__POS             6
#define BNO055_INTR_RST__MSK             0X40
#define BNO055_INTR_RST__LEN             1
#define BNO055_INTR_RST__REG             BNO055_SYS_TRIGGER_ADDR

/* CLK_SRC register*/
#define BNO055_CLK_SRC__POS             7
#define BNO055_CLK_SRC__MSK             0X80
#define BNO055_CLK_SRC__LEN             1
#define BNO055_CLK_SRC__REG             BNO055_SYS_TRIGGER_ADDR

/* Temp source register*/
#define BNO055_TEMP_SOURCE__POS     0
#define BNO055_TEMP_SOURCE__MSK     0X03
#define BNO055_TEMP_SOURCE__LEN     2
#define BNO055_TEMP_SOURCE__REG     BNO055_TEMP_SOURCE_ADDR

/* Axis remap value register*/
#define BNO055_REMAP_AXIS_VALUE__POS        0
#define BNO055_REMAP_AXIS_VALUE__MSK        0X3F
#define BNO055_REMAP_AXIS_VALUE__LEN        6
#define BNO055_REMAP_AXIS_VALUE__REG        BNO055_AXIS_MAP_CONFIG_ADDR

/* Axis sign value register*/
#define BNO055_REMAP_Z_SIGN__POS        0
#define BNO055_REMAP_Z_SIGN__MSK        0X01
#define BNO055_REMAP_Z_SIGN__LEN        1
#define BNO055_REMAP_Z_SIGN__REG        BNO055_AXIS_MAP_SIGN_ADDR

#define BNO055_REMAP_Y_SIGN__POS        1
#define BNO055_REMAP_Y_SIGN__MSK        0X02
#define BNO055_REMAP_Y_SIGN__LEN        1
#define BNO055_REMAP_Y_SIGN__REG        BNO055_AXIS_MAP_SIGN_ADDR

#define BNO055_REMAP_X_SIGN__POS        2
#define BNO055_REMAP_X_SIGN__MSK        0X04
#define BNO055_REMAP_X_SIGN__LEN        1
#define BNO055_REMAP_X_SIGN__REG        BNO055_AXIS_MAP_SIGN_ADDR

/* Soft Iron Calibration matrix register*/
#define BNO055_SIC_MATRIX_0_LSB__POS        0
#define BNO055_SIC_MATRIX_0_LSB__MSK        0XFF
#define BNO055_SIC_MATRIX_0_LSB__LEN        8
#define BNO055_SIC_MATRIX_0_LSB__REG        BNO055_SIC_MATRIX_0_LSB_ADDR

#define BNO055_SIC_MATRIX_0_MSB__POS        0
#define BNO055_SIC_MATRIX_0_MSB__MSK        0XFF
#define BNO055_SIC_MATRIX_0_MSB__LEN        8
#define BNO055_SIC_MATRIX_0_MSB__REG        BNO055_SIC_MATRIX_0_MSB_ADDR

#define BNO055_SIC_MATRIX_1_LSB__POS        0
#define BNO055_SIC_MATRIX_1_LSB__MSK        0XFF
#define BNO055_SIC_MATRIX_1_LSB__LEN        8
#define BNO055_SIC_MATRIX_1_LSB__REG        BNO055_SIC_MATRIX_1_LSB_ADDR

#define BNO055_SIC_MATRIX_1_MSB__POS        0
#define BNO055_SIC_MATRIX_1_MSB__MSK        0XFF
#define BNO055_SIC_MATRIX_1_MSB__LEN        8
#define BNO055_SIC_MATRIX_1_MSB__REG        BNO055_SIC_MATRIX_1_MSB_ADDR

#define BNO055_SIC_MATRIX_2_LSB__POS        0
#define BNO055_SIC_MATRIX_2_LSB__MSK        0XFF
#define BNO055_SIC_MATRIX_2_LSB__LEN        8
#define BNO055_SIC_MATRIX_2_LSB__REG        BNO055_SIC_MATRIX_2_LSB_ADDR

#define BNO055_SIC_MATRIX_2_MSB__POS        0
#define BNO055_SIC_MATRIX_2_MSB__MSK        0XFF
#define BNO055_SIC_MATRIX_2_MSB__LEN        8
#define BNO055_SIC_MATRIX_2_MSB__REG        BNO055_SIC_MATRIX_2_MSB_ADDR

#define BNO055_SIC_MATRIX_3_LSB__POS        0
#define BNO055_SIC_MATRIX_3_LSB__MSK        0XFF
#define BNO055_SIC_MATRIX_3_LSB__LEN        8
#define BNO055_SIC_MATRIX_3_LSB__REG        BNO055_SIC_MATRIX_3_LSB_ADDR

#define BNO055_SIC_MATRIX_3_MSB__POS        0
#define BNO055_SIC_MATRIX_3_MSB__MSK        0XFF
#define BNO055_SIC_MATRIX_3_MSB__LEN        8
#define BNO055_SIC_MATRIX_3_MSB__REG        BNO055_SIC_MATRIX_3_MSB_ADDR

#define BNO055_SIC_MATRIX_4_LSB__POS        0
#define BNO055_SIC_MATRIX_4_LSB__MSK        0XFF
#define BNO055_SIC_MATRIX_4_LSB__LEN        8
#define BNO055_SIC_MATRIX_4_LSB__REG        BNO055_SIC_MATRIX_4_LSB_ADDR

#define BNO055_SIC_MATRIX_4_MSB__POS        0
#define BNO055_SIC_MATRIX_4_MSB__MSK        0XFF
#define BNO055_SIC_MATRIX_4_MSB__LEN        8
#define BNO055_SIC_MATRIX_4_MSB__REG        BNO055_SIC_MATRIX_4_MSB_ADDR

#define BNO055_SIC_MATRIX_5_LSB__POS        0
#define BNO055_SIC_MATRIX_5_LSB__MSK        0XFF
#define BNO055_SIC_MATRIX_5_LSB__LEN        8
#define BNO055_SIC_MATRIX_5_LSB__REG        BNO055_SIC_MATRIX_5_LSB_ADDR

#define BNO055_SIC_MATRIX_5_MSB__POS        0
#define BNO055_SIC_MATRIX_5_MSB__MSK        0XFF
#define BNO055_SIC_MATRIX_5_MSB__LEN        8
#define BNO055_SIC_MATRIX_5_MSB__REG        BNO055_SIC_MATRIX_5_MSB_ADDR

#define BNO055_SIC_MATRIX_6_LSB__POS        0
#define BNO055_SIC_MATRIX_6_LSB__MSK        0XFF
#define BNO055_SIC_MATRIX_6_LSB__LEN        8
#define BNO055_SIC_MATRIX_6_LSB__REG        BNO055_SIC_MATRIX_6_LSB_ADDR

#define BNO055_SIC_MATRIX_6_MSB__POS        0
#define BNO055_SIC_MATRIX_6_MSB__MSK        0XFF
#define BNO055_SIC_MATRIX_6_MSB__LEN        8
#define BNO055_SIC_MATRIX_6_MSB__REG        BNO055_SIC_MATRIX_6_MSB_ADDR

#define BNO055_SIC_MATRIX_7_LSB__POS        0
#define BNO055_SIC_MATRIX_7_LSB__MSK        0XFF
#define BNO055_SIC_MATRIX_7_LSB__LEN        8
#define BNO055_SIC_MATRIX_7_LSB__REG        BNO055_SIC_MATRIX_7_LSB_ADDR

#define BNO055_SIC_MATRIX_7_MSB__POS        0
#define BNO055_SIC_MATRIX_7_MSB__MSK        0XFF
#define BNO055_SIC_MATRIX_7_MSB__LEN        8
#define BNO055_SIC_MATRIX_7_MSB__REG        BNO055_SIC_MATRIX_7_MSB_ADDR

#define BNO055_SIC_MATRIX_8_LSB__POS        0
#define BNO055_SIC_MATRIX_8_LSB__MSK        0XFF
#define BNO055_SIC_MATRIX_8_LSB__LEN        8
#define BNO055_SIC_MATRIX_8_LSB__REG        BNO055_SIC_MATRIX_8_LSB_ADDR

#define BNO055_SIC_MATRIX_8_MSB__POS        0
#define BNO055_SIC_MATRIX_8_MSB__MSK        0XFF
#define BNO055_SIC_MATRIX_8_MSB__LEN        8
#define BNO055_SIC_MATRIX_8_MSB__REG        BNO055_SIC_MATRIX_8_MSB_ADDR

/*Accel Offset registers*/
#define BNO055_ACCEL_OFFSET_X_LSB__POS      0
#define BNO055_ACCEL_OFFSET_X_LSB__MSK      0XFF
#define BNO055_ACCEL_OFFSET_X_LSB__LEN      8
#define BNO055_ACCEL_OFFSET_X_LSB__REG      ACCEL_OFFSET_X_LSB_ADDR

#define BNO055_ACCEL_OFFSET_X_MSB__POS      0
#define BNO055_ACCEL_OFFSET_X_MSB__MSK      0XFF
#define BNO055_ACCEL_OFFSET_X_MSB__LEN      8
#define BNO055_ACCEL_OFFSET_X_MSB__REG      ACCEL_OFFSET_X_MSB_ADDR

#define BNO055_ACCEL_OFFSET_Y_LSB__POS      0
#define BNO055_ACCEL_OFFSET_Y_LSB__MSK      0XFF
#define BNO055_ACCEL_OFFSET_Y_LSB__LEN      8
#define BNO055_ACCEL_OFFSET_Y_LSB__REG      ACCEL_OFFSET_Y_LSB_ADDR

#define BNO055_ACCEL_OFFSET_Y_MSB__POS      0
#define BNO055_ACCEL_OFFSET_Y_MSB__MSK      0XFF
#define BNO055_ACCEL_OFFSET_Y_MSB__LEN      8
#define BNO055_ACCEL_OFFSET_Y_MSB__REG      ACCEL_OFFSET_Y_MSB_ADDR

#define BNO055_ACCEL_OFFSET_Z_LSB__POS      0
#define BNO055_ACCEL_OFFSET_Z_LSB__MSK      0XFF
#define BNO055_ACCEL_OFFSET_Z_LSB__LEN      8
#define BNO055_ACCEL_OFFSET_Z_LSB__REG      ACCEL_OFFSET_Z_LSB_ADDR

#define BNO055_ACCEL_OFFSET_Z_MSB__POS      0
#define BNO055_ACCEL_OFFSET_Z_MSB__MSK      0XFF
#define BNO055_ACCEL_OFFSET_Z_MSB__LEN      8
#define BNO055_ACCEL_OFFSET_Z_MSB__REG      ACCEL_OFFSET_Z_MSB_ADDR

/* Gyro Offset registers*/
#define BNO055_GYRO_OFFSET_X_LSB__POS       0
#define BNO055_GYRO_OFFSET_X_LSB__MSK       0XFF
#define BNO055_GYRO_OFFSET_X_LSB__LEN       8
#define BNO055_GYRO_OFFSET_X_LSB__REG       GYRO_OFFSET_X_LSB_ADDR

#define BNO055_GYRO_OFFSET_X_MSB__POS       0
#define BNO055_GYRO_OFFSET_X_MSB__MSK       0XFF
#define BNO055_GYRO_OFFSET_X_MSB__LEN       8
#define BNO055_GYRO_OFFSET_X_MSB__REG       GYRO_OFFSET_X_MSB_ADDR

#define BNO055_GYRO_OFFSET_Y_LSB__POS       0
#define BNO055_GYRO_OFFSET_Y_LSB__MSK       0XFF
#define BNO055_GYRO_OFFSET_Y_LSB__LEN       8
#define BNO055_GYRO_OFFSET_Y_LSB__REG       GYRO_OFFSET_Y_LSB_ADDR

#define BNO055_GYRO_OFFSET_Y_MSB__POS       0
#define BNO055_GYRO_OFFSET_Y_MSB__MSK       0XFF
#define BNO055_GYRO_OFFSET_Y_MSB__LEN       8
#define BNO055_GYRO_OFFSET_Y_MSB__REG       GYRO_OFFSET_Y_MSB_ADDR

#define BNO055_GYRO_OFFSET_Z_LSB__POS       0
#define BNO055_GYRO_OFFSET_Z_LSB__MSK       0XFF
#define BNO055_GYRO_OFFSET_Z_LSB__LEN       8
#define BNO055_GYRO_OFFSET_Z_LSB__REG       GYRO_OFFSET_Z_LSB_ADDR

#define BNO055_GYRO_OFFSET_Z_MSB__POS       0
#define BNO055_GYRO_OFFSET_Z_MSB__MSK       0XFF
#define BNO055_GYRO_OFFSET_Z_MSB__LEN       8
#define BNO055_GYRO_OFFSET_Z_MSB__REG       GYRO_OFFSET_Z_MSB_ADDR

/* Radius register definition*/
#define BNO055_ACCEL_RADIUS_LSB__POS        0
#define BNO055_ACCEL_RADIUS_LSB__MSK        0XFF
#define BNO055_ACCEL_RADIUS_LSB__LEN        8
#define BNO055_ACCEL_RADIUS_LSB__REG        ACCEL_RADIUS_LSB_ADDR

#define BNO055_ACCEL_RADIUS_MSB__POS        0
#define BNO055_ACCEL_RADIUS_MSB__MSK        0XFF
#define BNO055_ACCEL_RADIUS_MSB__LEN        8
#define BNO055_ACCEL_RADIUS_MSB__REG        ACCEL_RADIUS_MSB_ADDR

#define BNO055_MAG_RADIUS_LSB__POS      0
#define BNO055_MAG_RADIUS_LSB__MSK      0XFF
#define BNO055_MAG_RADIUS_LSB__LEN      8
#define BNO055_MAG_RADIUS_LSB__REG      MAG_RADIUS_LSB_ADDR

#define BNO055_MAG_RADIUS_MSB__POS      0
#define BNO055_MAG_RADIUS_MSB__MSK      0XFF
#define BNO055_MAG_RADIUS_MSB__LEN      8
#define BNO055_MAG_RADIUS_MSB__REG      MAG_RADIUS_MSB_ADDR

/* PAGE0 DATA REGISTERS DEFINITION END*/
/*************************************************/
/**\name PAGE1 DATA REGISTERS DEFINITION   */
/*************************************************/
/* Configuration registers*/
/* Accel range configuration register*/
#define BNO055_ACCEL_RANGE__POS     0
#define BNO055_ACCEL_RANGE__MSK     0X03
#define BNO055_ACCEL_RANGE__LEN     2
#define BNO055_ACCEL_RANGE__REG     ACCEL_CONFIG_ADDR

/* Accel bandwidth configuration register*/
#define BNO055_ACCEL_BW__POS            2
#define BNO055_ACCEL_BW__MSK            0X1C
#define BNO055_ACCEL_BW__LEN            3
#define BNO055_ACCEL_BW__REG            ACCEL_CONFIG_ADDR

/* Accel power mode configuration register*/
#define BNO055_ACCEL_POWER_MODE__POS        5
#define BNO055_ACCEL_POWER_MODE__MSK        0XE0
#define BNO055_ACCEL_POWER_MODE__LEN        3
#define BNO055_ACCEL_POWER_MODE__REG        ACCEL_CONFIG_ADDR

/* Mag data output rate configuration register*/
#define BNO055_MAG_DATA_OUTPUT_RATE__POS        0
#define BNO055_MAG_DATA_OUTPUT_RATE__MSK        0X07
#define BNO055_MAG_DATA_OUTPUT_RATE__LEN        3
#define BNO055_MAG_DATA_OUTPUT_RATE__REG        MAG_CONFIG_ADDR

/* Mag operation mode configuration register*/
#define BNO055_MAG_OPERATION_MODE__POS      3
#define BNO055_MAG_OPERATION_MODE__MSK      0X18
#define BNO055_MAG_OPERATION_MODE__LEN      2
#define BNO055_MAG_OPERATION_MODE__REG      MAG_CONFIG_ADDR

/* Mag power mode configuration register*/
#define BNO055_MAG_POWER_MODE__POS      5
#define BNO055_MAG_POWER_MODE__MSK      0X60
#define BNO055_MAG_POWER_MODE__LEN      2
#define BNO055_MAG_POWER_MODE__REG      MAG_CONFIG_ADDR

/* Gyro range configuration register*/
#define BNO055_GYRO_RANGE__POS      0
#define BNO055_GYRO_RANGE__MSK      0X07
#define BNO055_GYRO_RANGE__LEN      3
#define BNO055_GYRO_RANGE__REG      GYRO_CONFIG_ADDR

/* Gyro bandwidth configuration register*/
#define BNO055_GYRO_BW__POS     3
#define BNO055_GYRO_BW__MSK     0X38
#define BNO055_GYRO_BW__LEN     3
#define BNO055_GYRO_BW__REG     GYRO_CONFIG_ADDR

/* Gyro power mode configuration register*/
#define BNO055_GYRO_POWER_MODE__POS     0
#define BNO055_GYRO_POWER_MODE__MSK     0X07
#define BNO055_GYRO_POWER_MODE__LEN     3
#define BNO055_GYRO_POWER_MODE__REG     GYRO_MODE_CONFIG_ADDR

/* Sleep configuration registers*/
/* Accel sleep mode configuration register*/
#define BNO055_ACCEL_SLEEP_MODE__POS        0
#define BNO055_ACCEL_SLEEP_MODE__MSK        0X01
#define BNO055_ACCEL_SLEEP_MODE__LEN        1
#define BNO055_ACCEL_SLEEP_MODE__REG        ACCEL_SLEEP_CONFIG_ADDR

/* Accel sleep duration configuration register*/
#define BNO055_ACCEL_SLEEP_DURN__POS        1
#define BNO055_ACCEL_SLEEP_DURN__MSK        0X1E
#define BNO055_ACCEL_SLEEP_DURN__LEN        4
#define BNO055_ACCEL_SLEEP_DURN__REG        ACCEL_SLEEP_CONFIG_ADDR

/* Gyro sleep duration configuration register*/
#define BNO055_GYRO_SLEEP_DURN__POS     0
#define BNO055_GYRO_SLEEP_DURN__MSK     0X07
#define BNO055_GYRO_SLEEP_DURN__LEN     3
#define BNO055_GYRO_SLEEP_DURN__REG     GYRO_SLEEP_CONFIG_ADDR

/* Gyro auto sleep duration configuration register*/
#define BNO055_GYRO_AUTO_SLEEP_DURN__POS        3
#define BNO055_GYRO_AUTO_SLEEP_DURN__MSK        0X38
#define BNO055_GYRO_AUTO_SLEEP_DURN__LEN        3
#define BNO055_GYRO_AUTO_SLEEP_DURN__REG        GYRO_SLEEP_CONFIG_ADDR

/* Mag sleep mode configuration register*/
#define BNO055_MAG_SLEEP_MODE__POS      0
#define BNO055_MAG_SLEEP_MODE__MSK      0X01
#define BNO055_MAG_SLEEP_MODE__LEN      1
#define BNO055_MAG_SLEEP_MODE__REG      MAG_SLEEP_CONFIG_ADDR

/* Mag sleep duration configuration register*/
#define BNO055_MAG_SLEEP_DURN__POS      1
#define BNO055_MAG_SLEEP_DURN__MSK      0X1E
#define BNO055_MAG_SLEEP_DURN__LEN      4
#define BNO055_MAG_SLEEP_DURN__REG      MAG_SLEEP_CONFIG_ADDR

/* Interrupt registers*/
/* Gyro any motion interrupt msk register*/
#define BNO055_GYRO_ANY_MOTION_INTR_MASK__POS       2
#define BNO055_GYRO_ANY_MOTION_INTR_MASK__MSK       0X04
#define BNO055_GYRO_ANY_MOTION_INTR_MASK__LEN       1
#define BNO055_GYRO_ANY_MOTION_INTR_MASK__REG       INT_MASK_ADDR

/* Gyro high rate interrupt msk register*/
#define BNO055_GYRO_HIGHRATE_INTR_MASK__POS     3
#define BNO055_GYRO_HIGHRATE_INTR_MASK__MSK     0X08
#define BNO055_GYRO_HIGHRATE_INTR_MASK__LEN     1
#define BNO055_GYRO_HIGHRATE_INTR_MASK__REG     INT_MASK_ADDR

/* Accel high g interrupt msk register*/
#define BNO055_ACCEL_HIGH_G_INTR_MASK__POS      5
#define BNO055_ACCEL_HIGH_G_INTR_MASK__MSK      0X20
#define BNO055_ACCEL_HIGH_G_INTR_MASK__LEN      1
#define BNO055_ACCEL_HIGH_G_INTR_MASK__REG      INT_MASK_ADDR

/* Accel any motion interrupt msk register*/
#define BNO055_ACCEL_ANY_MOTION_INTR_MASK__POS      6
#define BNO055_ACCEL_ANY_MOTION_INTR_MASK__MSK      0X40
#define BNO055_ACCEL_ANY_MOTION_INTR_MASK__LEN      1
#define BNO055_ACCEL_ANY_MOTION_INTR_MASK__REG      INT_MASK_ADDR

/* Accel any motion interrupt msk register*/
#define BNO055_ACCEL_NO_MOTION_INTR_MASK__POS       7
#define BNO055_ACCEL_NO_MOTION_INTR_MASK__MSK       0X80
#define BNO055_ACCEL_NO_MOTION_INTR_MASK__LEN       1
#define BNO055_ACCEL_NO_MOTION_INTR_MASK__REG       INT_MASK_ADDR

/* Gyro any motion interrupt register*/
#define BNO055_GYRO_ANY_MOTION_INTR__POS        2
#define BNO055_GYRO_ANY_MOTION_INTR__MSK        0X04
#define BNO055_GYRO_ANY_MOTION_INTR__LEN        1
#define BNO055_GYRO_ANY_MOTION_INTR__REG        INT_ADDR

/* Gyro high rate interrupt register*/
#define BNO055_GYRO_HIGHRATE_INTR__POS      3
#define BNO055_GYRO_HIGHRATE_INTR__MSK      0X08
#define BNO055_GYRO_HIGHRATE_INTR__LEN      1
#define BNO055_GYRO_HIGHRATE_INTR__REG      INT_ADDR

/* Accel high g interrupt register*/
#define BNO055_ACCEL_HIGH_G_INTR__POS       5
#define BNO055_ACCEL_HIGH_G_INTR__MSK       0X20
#define BNO055_ACCEL_HIGH_G_INTR__LEN       1
#define BNO055_ACCEL_HIGH_G_INTR__REG       INT_ADDR

/* Accel any motion interrupt register*/
#define BNO055_ACCEL_ANY_MOTION_INTR__POS       6
#define BNO055_ACCEL_ANY_MOTION_INTR__MSK       0X40
#define BNO055_ACCEL_ANY_MOTION_INTR__LEN       1
#define BNO055_ACCEL_ANY_MOTION_INTR__REG       INT_ADDR

/*Accel any motion interrupt register*/
#define BNO055_ACCEL_NO_MOTION_INTR__POS        7
#define BNO055_ACCEL_NO_MOTION_INTR__MSK        0X80
#define BNO055_ACCEL_NO_MOTION_INTR__LEN        1
#define BNO055_ACCEL_NO_MOTION_INTR__REG        INT_ADDR

/*Accel any motion threshold setting*/
#define BNO055_ACCEL_ANY_MOTION_THRES__POS  0
#define BNO055_ACCEL_ANY_MOTION_THRES__MSK  0XFF
#define BNO055_ACCEL_ANY_MOTION_THRES__LEN  8
#define BNO055_ACCEL_ANY_MOTION_THRES__REG  ACCEL_ANY_MOTION_THRES_ADDR

/*Accel interrupt setting register*/
#define BNO055_ACCEL_ANY_MOTION_DURN_SET__POS       0
#define BNO055_ACCEL_ANY_MOTION_DURN_SET__MSK       0X03
#define BNO055_ACCEL_ANY_MOTION_DURN_SET__LEN       2
#define BNO055_ACCEL_ANY_MOTION_DURN_SET__REG       ACCEL_INTR_SETTINGS_ADDR

/* Accel AM/NM axis selection register*/
#define BNO055_ACCEL_ANY_MOTION_X_AXIS__POS     2
#define BNO055_ACCEL_ANY_MOTION_X_AXIS__MSK     0X04
#define BNO055_ACCEL_ANY_MOTION_X_AXIS__LEN     1
#define BNO055_ACCEL_ANY_MOTION_X_AXIS__REG     ACCEL_INTR_SETTINGS_ADDR

#define BNO055_ACCEL_ANY_MOTION_Y_AXIS__POS     3
#define BNO055_ACCEL_ANY_MOTION_Y_AXIS__MSK     0X08
#define BNO055_ACCEL_ANY_MOTION_Y_AXIS__LEN     1
#define BNO055_ACCEL_ANY_MOTION_Y_AXIS__REG     ACCEL_INTR_SETTINGS_ADDR

#define BNO055_ACCEL_ANY_MOTION_Z_AXIS__POS     4
#define BNO055_ACCEL_ANY_MOTION_Z_AXIS__MSK     0X10
#define BNO055_ACCEL_ANY_MOTION_Z_AXIS__LEN     1
#define BNO055_ACCEL_ANY_MOTION_Z_AXIS__REG     ACCEL_INTR_SETTINGS_ADDR

/* Accel high g axis selection register*/
#define BNO055_ACCEL_HIGH_G_X_AXIS__POS     5
#define BNO055_ACCEL_HIGH_G_X_AXIS__MSK     0X20
#define BNO055_ACCEL_HIGH_G_X_AXIS__LEN     1
#define BNO055_ACCEL_HIGH_G_X_AXIS__REG     ACCEL_INTR_SETTINGS_ADDR

#define BNO055_ACCEL_HIGH_G_Y_AXIS__POS     6
#define BNO055_ACCEL_HIGH_G_Y_AXIS__MSK     0X40
#define BNO055_ACCEL_HIGH_G_Y_AXIS__LEN     1
#define BNO055_ACCEL_HIGH_G_Y_AXIS__REG     ACCEL_INTR_SETTINGS_ADDR

#define BNO055_ACCEL_HIGH_G_Z_AXIS__POS     7
#define BNO055_ACCEL_HIGH_G_Z_AXIS__MSK     0X80
#define BNO055_ACCEL_HIGH_G_Z_AXIS__LEN     1
#define BNO055_ACCEL_HIGH_G_Z_AXIS__REG     ACCEL_INTR_SETTINGS_ADDR

/* Accel High g duration setting register*/
#define BNO055_ACCEL_HIGH_G_DURN__POS       0
#define BNO055_ACCEL_HIGH_G_DURN__MSK       0XFF
#define BNO055_ACCEL_HIGH_G_DURN__LEN       8
#define BNO055_ACCEL_HIGH_G_DURN__REG       ACCEL_HIGH_G_DURN_ADDR

/* Accel High g threshold setting register*/
#define BNO055_ACCEL_HIGH_G_THRES__POS      0
#define BNO055_ACCEL_HIGH_G_THRES__MSK      0XFF
#define BNO055_ACCEL_HIGH_G_THRES__LEN      8
#define BNO055_ACCEL_HIGH_G_THRES__REG      ACCEL_HIGH_G_THRES_ADDR

/* Accel no/slow motion threshold setting*/
#define BNO055_ACCEL_SLOW_NO_MOTION_THRES__POS      0
#define BNO055_ACCEL_SLOW_NO_MOTION_THRES__MSK      0XFF
#define BNO055_ACCEL_SLOW_NO_MOTION_THRES__LEN      8
#define BNO055_ACCEL_SLOW_NO_MOTION_THRES__REG      \
ACCEL_NO_MOTION_THRES_ADDR

/* Accel no/slow motion enable setting*/
#define BNO055_ACCEL_SLOW_NO_MOTION_ENABLE__POS     0
#define BNO055_ACCEL_SLOW_NO_MOTION_ENABLE__MSK     0X01
#define BNO055_ACCEL_SLOW_NO_MOTION_ENABLE__LEN     1
#define BNO055_ACCEL_SLOW_NO_MOTION_ENABLE__REG     ACCEL_NO_MOTION_SET_ADDR

/* Accel no/slow motion duration setting*/
#define BNO055_ACCEL_SLOW_NO_MOTION_DURN__POS       1
#define BNO055_ACCEL_SLOW_NO_MOTION_DURN__MSK       0X7E
#define BNO055_ACCEL_SLOW_NO_MOTION_DURN__LEN       6
#define BNO055_ACCEL_SLOW_NO_MOTION_DURN__REG       ACCEL_NO_MOTION_SET_ADDR

/*Gyro interrupt setting register*/
/*Gyro any motion axis setting*/
#define BNO055_GYRO_ANY_MOTION_X_AXIS__POS      0
#define BNO055_GYRO_ANY_MOTION_X_AXIS__MSK      0X01
#define BNO055_GYRO_ANY_MOTION_X_AXIS__LEN      1
#define BNO055_GYRO_ANY_MOTION_X_AXIS__REG      GYRO_INTR_SETING_ADDR

#define BNO055_GYRO_ANY_MOTION_Y_AXIS__POS      1
#define BNO055_GYRO_ANY_MOTION_Y_AXIS__MSK      0X02
#define BNO055_GYRO_ANY_MOTION_Y_AXIS__LEN      1
#define BNO055_GYRO_ANY_MOTION_Y_AXIS__REG      GYRO_INTR_SETING_ADDR

#define BNO055_GYRO_ANY_MOTION_Z_AXIS__POS      2
#define BNO055_GYRO_ANY_MOTION_Z_AXIS__MSK      0X04
#define BNO055_GYRO_ANY_MOTION_Z_AXIS__LEN      1
#define BNO055_GYRO_ANY_MOTION_Z_AXIS__REG      GYRO_INTR_SETING_ADDR

/*Gyro high rate axis setting*/
#define BNO055_GYRO_HIGHRATE_X_AXIS__POS        3
#define BNO055_GYRO_HIGHRATE_X_AXIS__MSK        0X08
#define BNO055_GYRO_HIGHRATE_X_AXIS__LEN        1
#define BNO055_GYRO_HIGHRATE_X_AXIS__REG        GYRO_INTR_SETING_ADDR

#define BNO055_GYRO_HIGHRATE_Y_AXIS__POS        4
#define BNO055_GYRO_HIGHRATE_Y_AXIS__MSK        0X10
#define BNO055_GYRO_HIGHRATE_Y_AXIS__LEN        1
#define BNO055_GYRO_HIGHRATE_Y_AXIS__REG        GYRO_INTR_SETING_ADDR

#define BNO055_GYRO_HIGHRATE_Z_AXIS__POS        5
#define BNO055_GYRO_HIGHRATE_Z_AXIS__MSK        0X20
#define BNO055_GYRO_HIGHRATE_Z_AXIS__LEN        1
#define BNO055_GYRO_HIGHRATE_Z_AXIS__REG        GYRO_INTR_SETING_ADDR

/* Gyro filter setting*/
#define BNO055_GYRO_ANY_MOTION_FILTER__POS      6
#define BNO055_GYRO_ANY_MOTION_FILTER__MSK      0X40
#define BNO055_GYRO_ANY_MOTION_FILTER__LEN      1
#define BNO055_GYRO_ANY_MOTION_FILTER__REG      GYRO_INTR_SETING_ADDR

#define BNO055_GYRO_HIGHRATE_FILTER__POS        7
#define BNO055_GYRO_HIGHRATE_FILTER__MSK        0X80
#define BNO055_GYRO_HIGHRATE_FILTER__LEN        1
#define BNO055_GYRO_HIGHRATE_FILTER__REG        GYRO_INTR_SETING_ADDR

/* Gyro high rate X axis settings*/
#define BNO055_GYRO_HIGHRATE_X_THRES__POS       0
#define BNO055_GYRO_HIGHRATE_X_THRES__MSK       0X1F
#define BNO055_GYRO_HIGHRATE_X_THRES__LEN       5
#define BNO055_GYRO_HIGHRATE_X_THRES__REG       GYRO_HIGHRATE_X_SET_ADDR

#define BNO055_GYRO_HIGHRATE_X_HYST__POS        5
#define BNO055_GYRO_HIGHRATE_X_HYST__MSK        0X60
#define BNO055_GYRO_HIGHRATE_X_HYST__LEN        2
#define BNO055_GYRO_HIGHRATE_X_HYST__REG        GYRO_HIGHRATE_X_SET_ADDR

#define BNO055_GYRO_HIGHRATE_X_DURN__POS        0
#define BNO055_GYRO_HIGHRATE_X_DURN__MSK        0XFF
#define BNO055_GYRO_HIGHRATE_X_DURN__LEN        8
#define BNO055_GYRO_HIGHRATE_X_DURN__REG        GYRO_DURN_X_ADDR

/* Gyro high rate Y axis settings*/
#define BNO055_GYRO_HIGHRATE_Y_THRES__POS       0
#define BNO055_GYRO_HIGHRATE_Y_THRES__MSK       0X1F
#define BNO055_GYRO_HIGHRATE_Y_THRES__LEN       5
#define BNO055_GYRO_HIGHRATE_Y_THRES__REG       GYRO_HIGHRATE_Y_SET_ADDR

#define BNO055_GYRO_HIGHRATE_Y_HYST__POS        5
#define BNO055_GYRO_HIGHRATE_Y_HYST__MSK        0X60
#define BNO055_GYRO_HIGHRATE_Y_HYST__LEN        2
#define BNO055_GYRO_HIGHRATE_Y_HYST__REG        GYRO_HIGHRATE_Y_SET_ADDR

#define BNO055_GYRO_HIGHRATE_Y_DURN__POS        0
#define BNO055_GYRO_HIGHRATE_Y_DURN__MSK        0XFF
#define BNO055_GYRO_HIGHRATE_Y_DURN__LEN        8
#define BNO055_GYRO_HIGHRATE_Y_DURN__REG        GYRO_DURN_Y_ADDR

/* Gyro high rate Z axis settings*/
#define BNO055_GYRO_HIGHRATE_Z_THRES__POS       0
#define BNO055_GYRO_HIGHRATE_Z_THRES__MSK       0X1F
#define BNO055_GYRO_HIGHRATE_Z_THRES__LEN       5
#define BNO055_GYRO_HIGHRATE_Z_THRES__REG       GYRO_HIGHRATE_Z_SET_ADDR

#define BNO055_GYRO_HIGHRATE_Z_HYST__POS        5
#define BNO055_GYRO_HIGHRATE_Z_HYST__MSK        0X60
#define BNO055_GYRO_HIGHRATE_Z_HYST__LEN        2
#define BNO055_GYRO_HIGHRATE_Z_HYST__REG        GYRO_HIGHRATE_Z_SET_ADDR

#define BNO055_GYRO_HIGHRATE_Z_DURN__POS        0
#define BNO055_GYRO_HIGHRATE_Z_DURN__MSK        0XFF
#define BNO055_GYRO_HIGHRATE_Z_DURN__LEN        8
#define BNO055_GYRO_HIGHRATE_Z_DURN__REG        GYRO_DURN_Z_ADDR

/*Gyro any motion threshold setting*/
#define BNO055_GYRO_ANY_MOTION_THRES__POS       0
#define BNO055_GYRO_ANY_MOTION_THRES__MSK       0X7F
#define BNO055_GYRO_ANY_MOTION_THRES__LEN       7
#define BNO055_GYRO_ANY_MOTION_THRES__REG       \
GYRO_ANY_MOTION_THRES_ADDR

/* Gyro any motion slope sample setting*/
#define BNO055_GYRO_SLOPE_SAMPLES__POS      0
#define BNO055_GYRO_SLOPE_SAMPLES__MSK      0X03
#define BNO055_GYRO_SLOPE_SAMPLES__LEN      2
#define BNO055_GYRO_SLOPE_SAMPLES__REG      GYRO_ANY_MOTION_SET_ADDR

/* Gyro awake duration setting*/
#define BNO055_GYRO_AWAKE_DURN__POS     2
#define BNO055_GYRO_AWAKE_DURN__MSK     0X0C
#define BNO055_GYRO_AWAKE_DURN__LEN     2
#define BNO055_GYRO_AWAKE_DURN__REG     GYRO_ANY_MOTION_SET_ADDR

/* PAGE1 DATA REGISTERS DEFINITION END*/
/*************************************************/
/**\name GET AND SET BITSLICE FUNCTIONS    */
/*************************************************/
#define BNO055_GET_BITSLICE(regvar, bitname)\
((regvar & bitname##__MSK) >> bitname##__POS)


#define BNO055_SET_BITSLICE(regvar, bitname, val)\
((regvar & ~bitname##__MSK) | ((val<<bitname##__POS)&bitname##__MSK))

BNO055_RETURN_FUNCTION_TYPE bno055_init( struct bno055_t *bno055 );
BNO055_RETURN_FUNCTION_TYPE bno055_write_register( u8 v_addr_u8,
        u8 *p_data_u8, u8 v_len_u8 );
BNO055_RETURN_FUNCTION_TYPE bno055_write_page_id( u8 v_page_id_u8 );
BNO055_RETURN_FUNCTION_TYPE get_bno55_accel_xyz(
    struct bno055_accel_t *accel );
BNO055_RETURN_FUNCTION_TYPE get_bno55_gyro_xyz( struct bno055_gyro_t *gyro );
BNO055_RETURN_FUNCTION_TYPE get_bn055_quaternion_wxyz(
    struct bno055_quaternion_t *quaternion );
BNO055_RETURN_FUNCTION_TYPE bno055_get_operation_mode(
    u8 *v_operation_mode_u8 );
BNO055_RETURN_FUNCTION_TYPE bno055_set_operation_mode( u8
        v_operation_mode_u8 );
BNO055_RETURN_FUNCTION_TYPE bno055_get_accel_range(
    u8 *v_accel_range_u8 );
BNO055_RETURN_FUNCTION_TYPE bno055_set_accel_range(
    u8 v_accel_range_u8 );
BNO055_RETURN_FUNCTION_TYPE bno055_set_gyro_range(
    u8 v_gyro_range_u8 );

#endif

