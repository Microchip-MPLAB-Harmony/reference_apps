/** \mainpage
*
****************************************************************************
* Copyright (C) 2019 MikroElektronika - www.mikroe.com
*
* File : bmi088.h
*
* Date : 2019 Revision : 2.2.2
* Date : 2023/04/13 Revision : 2.2.3
* Usage: Sensor Driver for BMI088 sensor
*
****************************************************************************
*
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
/*******************************************************************************
  bmi088 header file

  Company
    Microchip Technology Inc.

  File Name
    bmi088.h

  Summary
    This is the header file which needs to be included in bmi088.c file

  Description
    This file contains prototypes of all the functions which give functionality
    to bmi088 sensor and various Macros which needs to be included in the source file
  Remarks:
    None.

 *******************************************************************************/
/****************************************************************************
* Note: In version 2.2.3, This file has been modified by Microchip
* Technology India Pvt Ltd to meet the custom
* application requirements. write to
* Microchip Technology India Pvt Ltd
* Plot No. 1498, EPIP, 1st Phase Industrial Area, Whitefield, Bengaluru,
* Karnataka 560066
*******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
 Copyright (C) 2023  Microchip Technology Incorporated and its subsidiaries.

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

#ifndef _BMI088_H    /* Guard against multiple inclusion */
#define _BMI088_H

#include "13dof.h"

#define C13DOF_BMI088_ACCEL_SLAVE_ADDR                                    0x18
#define C13DOF_BMI088_GYRO_SLAVE_ADDR                                     0x68
#define C13DOF_BMI088_ACCEL_CHIP_ID_REG                                   0x00
#define C13DOF_BMI088_ACCEL_ERR_REG                                       0x02
#define C13DOF_BMI088_ACCEL_STATUS_REG                                    0x03
#define C13DOF_BMI088_ACCEL_X_LSB_REG                                     0x12
#define C13DOF_BMI088_ACCEL_X_MSB_REG                                     0x13
#define C13DOF_BMI088_ACCEL_Y_LSB_REG                                     0x14
#define C13DOF_BMI088_ACCEL_Y_MSB_REG                                     0x15
#define C13DOF_BMI088_ACCEL_Z_LSB_REG                                     0x16
#define C13DOF_BMI088_ACCEL_Z_MSB_REG                                     0x17
#define C13DOF_BMI088_ACCEL_SENSORTIME_0_REG                              0x18
#define C13DOF_BMI088_ACCEL_SENSORTIME_1_REG                              0x19
#define C13DOF_BMI088_ACCEL_SENSORTIME_2_REG                              0x1A
#define C13DOF_BMI088_ACCEL_INT_STAT_0_REG                                0x1C
#define C13DOF_BMI088_ACCEL_INT_STAT_1_REG                                0x1D
#define C13DOF_BMI088_ACCEL_GP_0_REG                                      0x1E
#define C13DOF_BMI088_TEMP_MSB_REG                                        0x22
#define C13DOF_BMI088_TEMP_LSB_REG                                        0x23
#define C13DOF_BMI088_ACCEL_GP_4_REG                                      0x27
#define C13DOF_BMI088_ACCEL_INTERNAL_STAT_REG                             0x2A
#define C13DOF_BMI088_ACCEL_CONF_REG                                      0x40
#define C13DOF_BMI088_ACCEL_RANGE_REG                                     0x41
#define C13DOF_BMI088_ACCEL_INT1_IO_CONF_REG                              0x53
#define C13DOF_BMI088_ACCEL_INT2_IO_CONF_REG                              0x54
#define C13DOF_BMI088_ACCEL_INT_LATCH_CONF_REG                            0x55
#define C13DOF_BMI088_ACCEL_INT1_MAP_REG                                  0x56
#define C13DOF_BMI088_ACCEL_INT2_MAP_REG                                  0x57
#define C13DOF_BMI088_ACCEL_INT1_INT2_MAP_DATA_REG                        0x58
#define C13DOF_BMI088_ACCEL_INIT_CTRL_REG                                 0x59
#define C13DOF_BMI088_ACCEL_SELF_TEST_REG                                 0x6D
#define C13DOF_BMI088_ACCEL_PWR_CONF_REG                                  0x7C
#define C13DOF_BMI088_ACCEL_PWR_CTRL_REG                                  0x7D
#define C13DOF_BMI088_ACCEL_SOFTRESET_REG                                 0x7E
#define C13DOF_BMI088_ACCEL_CHIP_ID                                       0x1E
#define C13DOF_BMI088_ACCEL_I2C_ADDR_PRIMARY                              0x18
#define C13DOF_BMI088_ACCEL_I2C_ADDR_SECONDARY                            0x19
#define C13DOF_BMI088_ACCEL_RESERVED_5B_REG                               0x5B
#define C13DOF_BMI088_ACCEL_RESERVED_5C_REG                               0x5C
#define C13DOF_BMI088_ACCEL_FEATURE_CFG_REG                               0x5E
#define C13DOF_BMI088_ACCEL_DATA_READY_INT                                0x80
#define C13DOF_BMI088_ACCEL_BW_OSR4                                       0x00
#define C13DOF_BMI088_ACCEL_BW_OSR2                                       0x01
#define C13DOF_BMI088_ACCEL_BW_NORMAL                                     0x02
#define C13DOF_BMI088_ACCEL_ODR_12_5_HZ                                   0x05
#define C13DOF_BMI088_ACCEL_ODR_25_HZ                                     0x06
#define C13DOF_BMI088_ACCEL_ODR_50_HZ                                     0x07
#define C13DOF_BMI088_ACCEL_ODR_100_HZ                                    0x08
#define C13DOF_BMI088_ACCEL_ODR_200_HZ                                    0x09
#define C13DOF_BMI088_ACCEL_ODR_400_HZ                                    0x0A
#define C13DOF_BMI088_ACCEL_ODR_800_HZ                                    0x0B
#define C13DOF_BMI088_ACCEL_ODR_1600_HZ                                   0x0C
#define C13DOF_BMI088_ACCEL_SWITCH_OFF_SELF_TEST                          0x00
#define C13DOF_BMI088_ACCEL_POSITIVE_SELF_TEST                            0x0D
#define C13DOF_BMI088_ACCEL_NEGATIVE_SELF_TEST                            0x09
#define C13DOF_BMI088_ACCEL_PM_ACTIVE                                     0x00
#define C13DOF_BMI088_ACCEL_PM_SUSPEND                                    0x03
#define C13DOF_BMI088_ACCEL_POWER_DISABLE                                 0x00
#define C13DOF_BMI088_ACCEL_POWER_ENABLE                                  0x04
#define C13DOF_BMI088_ACCEL_INTA_DISABLE                                  0x00
#define C13DOF_BMI088_ACCEL_INTA_ENABLE                                   0x01
#define C13DOF_BMI088_ACCEL_INTB_DISABLE                                  0x00
#define C13DOF_BMI088_ACCEL_INTB_ENABLE                                   0x02
#define C13DOF_BMI088_ACCEL_SOFTRESET_DELAY_MS                            1
#define C13DOF_BMI088_FATAL_ERR_MASK                                      0x01
#define C13DOF_BMI088_ERR_CODE_MASK                                       0x1C
#define C13DOF_BMI088_CMD_ERR_POS                                         1
#define C13DOF_BMI088_ERR_CODE_POS                                        2
#define C13DOF_BMI088_ACCEL_STATUS_MASK                                   0x80
#define C13DOF_BMI088_ACCEL_STATUS_POS                                    7
#define C13DOF_BMI088_ACCEL_ODR_MASK                                      0x0F
#define C13DOF_BMI088_ACCEL_BW_MASK                                       0x70
#define C13DOF_BMI088_ACCEL_RANGE_MASK                                    0x03
#define C13DOF_BMI088_ACCEL_BW_POS                                        4
#define C13DOF_BMI088_ACCEL_INT_EDGE_MASK                                 0x01
#define C13DOF_BMI088_ACCEL_INT_LVL_MASK                                  0x02
#define C13DOF_BMI088_ACCEL_INT_OD_MASK                                   0x04
#define C13DOF_BMI088_ACCEL_INT_IO_MASK                                   0x08
#define C13DOF_BMI088_ACCEL_INT_IN_MASK                                   0x10
#define C13DOF_BMI088_ACCEL_INT_EDGE_POS                                  0
#define C13DOF_BMI088_ACCEL_INT_LVL_POS                                   1
#define C13DOF_BMI088_ACCEL_INT_OD_POS                                    2
#define C13DOF_BMI088_ACCEL_INT_IO_POS                                    3
#define C13DOF_BMI088_ACCEL_INT_IN_POS                                    4
#define C13DOF_BMI088_ACCEL_MAP_INTA_MASK                                 0x01
#define C13DOF_BMI088_ACCEL_MAP_INTA_POS                                  0x00
#define C13DOF_BMI088_ACCEL_INT1_DRDY_MASK                                0x04
#define C13DOF_BMI088_ACCEL_INT2_DRDY_MASK                                0x40
#define C13DOF_BMI088_ACCEL_INT1_DRDY_POS                                 2
#define C13DOF_BMI088_ACCEL_INT2_DRDY_POS                                 6
#define C13DOF_BMI088_ASIC_INITIALIZED                                    0x01
#define C13DOF_BMI088_GYRO_CHIP_ID_REG                                    0x00
#define C13DOF_BMI088_GYRO_X_LSB_REG                                      0x02
#define C13DOF_BMI088_GYRO_X_MSB_REG                                      0x03
#define C13DOF_BMI088_GYRO_Y_LSB_REG                                      0x04
#define C13DOF_BMI088_GYRO_Y_MSB_REG                                      0x05
#define C13DOF_BMI088_GYRO_Z_LSB_REG                                      0x06
#define C13DOF_BMI088_GYRO_Z_MSB_REG                                      0x07
#define C13DOF_BMI088_GYRO_INT_STAT_1_REG                                 0x0A
#define C13DOF_BMI088_GYRO_RANGE_REG                                      0x0F
#define C13DOF_BMI088_GYRO_BANDWIDTH_REG                                  0x10
#define C13DOF_BMI088_GYRO_LPM1_REG                                       0x11
#define C13DOF_BMI088_GYRO_SOFTRESET_REG                                  0x14
#define C13DOF_BMI088_GYRO_INT_CTRL_REG                                   0x15
#define C13DOF_BMI088_GYRO_INT3_INT4_IO_CONF_REG                          0x16
#define C13DOF_BMI088_GYRO_INT3_INT4_IO_MAP_REG                           0x18
#define C13DOF_BMI088_GYRO_SELF_TEST_REG                                  0x3C
#define C13DOF_BMI088_GYRO_CHIP_ID                                        0x0F
#define C13DOF_BMI088_GYRO_I2C_ADDR_PRIMARY                               0x68
#define C13DOF_BMI088_GYRO_I2C_ADDR_SECONDARY                             0x69
#define C13DOF_BMI088_GYRO_RANGE_2000_DPS                                 0x00
#define C13DOF_BMI088_GYRO_RANGE_1000_DPS                                 0x01
#define C13DOF_BMI088_GYRO_RANGE_500_DPS                                  0x02
#define C13DOF_BMI088_GYRO_RANGE_250_DPS                                  0x03
#define C13DOF_BMI088_GYRO_RANGE_125_DPS                                  0x04
#define C13DOF_BMI088_GYRO_BW_532_ODR_2000_HZ                             0x00
#define C13DOF_BMI088_GYRO_BW_230_ODR_2000_HZ                             0x01
#define C13DOF_BMI088_GYRO_BW_116_ODR_1000_HZ                             0x02
#define C13DOF_BMI088_GYRO_BW_47_ODR_400_HZ                               0x03
#define C13DOF_BMI088_GYRO_BW_23_ODR_200_HZ                               0x04
#define C13DOF_BMI088_GYRO_BW_12_ODR_100_HZ                               0x05
#define C13DOF_BMI088_GYRO_BW_64_ODR_200_HZ                               0x06
#define C13DOF_BMI088_GYRO_BW_32_ODR_100_HZ                               0x07
#define C13DOF_BMI088_GYRO_ODR_RESET_VAL                                  0x80
#define C13DOF_BMI088_GYRO_PM_NORMAL                                      0x00
#define C13DOF_BMI088_GYRO_PM_DEEP_SUSPEND                                0x20
#define C13DOF_BMI088_GYRO_PM_SUSPEND                                     0x80
#define C13DOF_BMI088_GYRO_DRDY_INT_DISABLE_VAL                           0x00
#define C13DOF_BMI088_GYRO_DRDY_INT_ENABLE_VAL                            0x80
#define C13DOF_BMI088_GYRO_MAP_DRDY_TO_INT3                               0x01
#define C13DOF_BMI088_GYRO_MAP_DRDY_TO_INT4                               0x80
#define C13DOF_BMI088_GYRO_MAP_DRDY_TO_BOTH_INT3_INT4                     0x81
#define C13DOF_BMI088_GYRO_SOFTRESET_DELAY                                30
#define C13DOF_BMI088_GYRO_POWER_MODE_CONFIG_DELAY                        30
#define C13DOF_BMI088_GYRO_RANGE_MASK                                     0x07
#define C13DOF_BMI088_GYRO_BW_MASK                                        0x0F
#define C13DOF_BMI088_GYRO_POWER_MASK                                     0xA0
#define C13DOF_BMI088_GYRO_POWER_POS                                      5
#define C13DOF_BMI088_GYRO_DATA_EN_MASK                                   0x80
#define C13DOF_BMI088_GYRO_DATA_EN_POS                                    7
#define C13DOF_BMI088_GYRO_INT3_LVL_MASK                                  0x01
#define C13DOF_BMI088_GYRO_INT3_OD_MASK                                   0x02
#define C13DOF_BMI088_GYRO_INT4_LVL_MASK                                  0x04
#define C13DOF_BMI088_GYRO_INT4_OD_MASK                                   0x08
#define C13DOF_BMI088_GYRO_INT3_OD_POS                                    1
#define C13DOF_BMI088_GYRO_INT4_LVL_POS                                   2
#define C13DOF_BMI088_GYRO_INT4_OD_POS                                    3
#define C13DOF_BMI088_GYRO_INT_EN_MASK                                    0x80
#define C13DOF_BMI088_GYRO_INT_EN_POS                                     7
#define C13DOF_BMI088_GYRO_INT3_MAP_MASK                                  0x01
#define C13DOF_BMI088_GYRO_INT4_MAP_MASK                                  0x80
#define C13DOF_BMI088_GYRO_INT3_MAP_POS                                   0
#define C13DOF_BMI088_GYRO_INT4_MAP_POS                                   7
#define C13DOF_BMI088_OK                                                  0x00
#define C13DOF_BMI088_ERROR                                               0x01
#define C13DOF_BMI088_RETVAL_T                       uint8_t
/** \} */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */

typedef struct
{
    uint8_t bmi088Gyro_slave_address;
    uint8_t bmi088Accel_slave_address;

} bmi088_t;
/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif



void bmi088_init( bmi088_t *bmi );
/**
 * @brief Generic BMI088 Gyro write data function
 *
 *
 * @param bmi  Click object.
 *
 * @param reg_address                8-bit BMI088 Gyro register address
 *
 * @param write_data                 Byte of data to write
 *
 * @description Function write the 8-bit of data to the
 * target 8-bit register address of BMI088 Gyro sensor on 13DOF Click board.
 */
void bmi088_gyro_hal_write ( bmi088_t *bmi,  uint8_t reg_address, uint8_t write_data );

/**
 * @brief Generic BMI088 Gyro read data function
 *
 *
 * @param bmi  Click object.
 *
 * @param reg_address                8-bit BMI088 Gyro register address
 *
 * @returns
 * 8-bit read data
 *
 * @description Function read the 8-bit of data from the
 * target 8-bit register address of BMI088 Gyro sensor on 13DOF Click board.
 */
uint8_t bmi088_gyro_hal_read ( uint8_t reg_address );

/**
 * @brief Get BMI088 Gyro axis data function
 *
 *
 * @param bmi  Click object.
 *
 * @param adr_reg_LSB           least significant bit register address
 *
 * @param adr_reg_MSB           most significant bit register address
 *
 * @returns
 * 16-bit ( signed ) target axis value
 *
 * @description Function get axis data by read two target register address
 * of BMI088 Gyro sensor on 13DOF Click board.
 */
int16_t c13dof_bmi088_get_gyro_axis ( uint8_t adr_reg_LSB, uint8_t adr_reg_MSB );

/**
 * @brief Get BMI088 Gyro X-axis, Y-axis and Z-axis function
 *
 *
 * @param bmi  Click object.
 *
 * @param gyro_x              pointer to memory location where Mag X-axis data be stored
 *
 * @param gyro_y              pointer to memory location where Mag Y-axis data be stored
 *
 * @param gyro_z              pointer to memory location where Mag Z-axis data be stored
 *
 * @description Function reads 16-bit X-axis, Y-axis data and Z-axis data from the
 * targeted starts from _C13DOF_BMI088_GYRO_X_LSB_REG
 * to the _C13DOF_BMI088_GYRO_Z_MSB_REG register address of BMM150 sensor on 13DOF Click board.
 */
void c13dof_bmi088_read_gyro ( int16_t *gyro_x, int16_t *gyro_y, int16_t *gyro_z );

/**
 * @brief Generic BMI088 Accel write data function
 *
 *
 * @param bmi  Click object.
 *
 * @param reg_address                8-bit BMI088 Gyro register address
 *
 * @param write_data                 Byte of data to write
 *
 * @description Function write the 8-bit of data to the
 * target 8-bit register address of BMI088 Accel sensor on 13DOF Click board.
 */
void bmi088_accel_hal_write ( uint8_t reg_address, uint8_t write_data );

/**
 * @brief Generic BMI088 Accel read data function
 *
 *
 * @param bmi  Click object.
 *
 * @param reg_address                8-bit BMI088 Accel register address
 *
 * @returns
 * 8-bit read data
 *
 * @description Function read the 8-bit of data from the
 * target 8-bit register address of BMI088 Accel sensor on 13DOF Click board.
 */
uint8_t bmi088_accel_hal_read ( uint8_t reg_address );

/**
 * @brief Set BMI088 Accel soft reset function
 *
 *
 * @param bmi  Click object.
 *
 * @description Function performs a BMI088 Accel software reset
 * and after that puts device to normal operation mode
 * of BMI088 Accel sensor on 13DOF Click board.
 *
 * @note
 * delay is 1 ms.
 */
void c13dof_bmi088_soft_reset_accel ( );

/**
 * @brief Set BMI088 Accel mode function
 *
 *
 * @param bmi  Click object.
 *
 * @param Filter setting:
 * - 0x00 : Suspend mode;
 * - 0x01 : Active mode;
 *
 *
 * @returns status:
 * - 0 : OK;
 * - 1 : ERROR;
 *
 * @description Function set BMI088 Accel mode by write activeMode data to the
 * targeted _C13DOF_BMI088_ACCEL_PWR_CONF_REG register address
 * of BMI088 Accel sensor on 13DOF Click board.
 *
 * @note
 * delay is 5 ms.
 */
void c13dof_bmi088_set_accel_mode ( uint8_t active_mode );

/**
 * @brief Enable BMI088 Accel function
 *
 *
 * @param bmi  Click object.
 *
 * @returns status:
 * - 0 : OK;
 * - 1 : ERROR;
 *
 * @description Function enable BMI088 Accel by write 0x04 data to the
 * targeted _C13DOF_BMI088_ACCEL_PWR_CTRL_REG register address
 * of BMI088 Accel sensor on 13DOF Click board.
 *
 * @note
 * delay is 5 ms.
 */
C13DOF_BMI088_RETVAL_T c13dof_bmi088_enable_accel ( );

/**
 * @brief Get BMI088 Accel axis data function
 *
 *
 * @param bmi  Click object.
 *
 * @param adr_reg_LSB           least significant bit register address
 *
 * @param adr_reg_MSB           most significant bit register address
 *
 * @returns 16-bit ( signed ) target axis value
 *
 * @description Function get axis data by read two target register address
 * of BMI088 Accel sensor on 13DOF Click board.
 */
int16_t c13dof_bmi088_get_accel_axis ( uint8_t adr_reg_LSB, uint8_t adr_reg_MSB );

/**
 * @brief Get BMI088 Accel X-axis, Y-axis and Z-axis function
 *
 *
 * @param bmi  Click object.
 *
 * @param accel_x              pointer to memory location where Accel X-axis data be stored
 *
 * @param accel_y              pointer to memory location where Accel Y-axis data be stored
 *
 * @param accel_z              pointer to memory location where Accel Z-axis data be stored
 *
 * Function reads 16-bit X-axis, Y-axis data and Z-axis data from the
 * targeted starts from _C13DOF_BMI088_ACCEL_X_LSB_REG
 * to the _C13DOF_BMI088_ACCEL_Z_MSB_REG register address of BMM150 sensor on 13DOF Click board.
 */
void c13dof_bmi088_read_accel ( int16_t *accel_x, int16_t *accel_y, int16_t *accel_z );

#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
