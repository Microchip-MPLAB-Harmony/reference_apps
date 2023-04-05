/** \mainpage
*
****************************************************************************
* Copyright (C) 2019 MikroElektronika - www.mikroe.com
*
* File : bmm150.h
*
* Date : 2019 Revision : 2.2.2
* Date : 2023/04/13 Revision : 2.2.3
* Usage: Sensor Driver for BMM150 sensor
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
  bmm150 header file

  Company
    Microchip Technology Inc.

  File Name
    bmm150.h

  Summary
    This is the header file which needs to be included in bmi088.c file

  Description
    This file contains prototypes of all the functions which give functionality
    to bmm150 sensor and various Macros which needs to be included in the source file
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

#ifndef _BMM150_H    /* Guard against multiple inclusion */
#define _BMM150_H
#include "click_routines/13dof/13dof.h"

#define C13DOF_BMM150_DEVICE_SLAVE_ADDR                                   0x10
#define C13DOF_BMM150_DUMMY                                               0x00
#define C13DOF_BMM150_ID_REG                                              0x40
#define C13DOF_BMM150_RESERVED1_REG                                       0x41
#define C13DOF_BMM150_DATAX_LSB_REG                                       0x42
#define C13DOF_BMM150_DATAX_MSB_REG                                       0x43
#define C13DOF_BMM150_DATAY_LSB_REG                                       0x44
#define C13DOF_BMM150_DATAY_MSB_REG                                       0x45
#define C13DOF_BMM150_DATAZ_LSB_REG                                       0x46
#define C13DOF_BMM150_DATAZ_MSB_REG                                       0x47
#define C13DOF_BMM150_RHALL_LSB_REG                                       0x48
#define C13DOF_BMM150_RHALL_MSB_REG                                       0x49
#define C13DOF_BMM150_INTERRUPT_STATUS_REG                                0x4A
#define C13DOF_BMM150_POWER_AND_RESET_CON_REG                             0x4B
#define C13DOF_BMM150_DATARATE_AND_OPMODE_CON_REG                         0x4C
#define C13DOF_BMM150_INTERR_AND_AXIS_EN_REG                              0x4D
#define C13DOF_BMM150_INTERR_AND_CHANNEL_EN_REG                           0x4E
#define C13DOF_BMM150_LOW_THRESHOLD_REG                                   0x4F
#define C13DOF_BMM150_HIGH_THRESHOLD_REG                                  0x50
#define C13DOF_BMM150_REPETITION_XY_CON_REG                               0x51
#define C13DOF_BMM150_REPETITION_Z_CON_REG                                0x52
#define C13DOF_BMM150_RESERVED2_REG                                       0x53
#define C13DOF_BMM150_RESERVED3_REG                                       0x54
#define C13DOF_BMM150_RESERVED4_REG                                       0x55
#define C13DOF_BMM150_RESERVED5_REG                                       0x56
#define C13DOF_BMM150_RESERVED6_REG                                       0x57
#define C13DOF_BMM150_RESERVED7_REG                                       0x58
#define C13DOF_BMM150_RESERVED8_REG                                       0x59
#define C13DOF_BMM150_RESERVED9_REG                                       0x5A
#define C13DOF_BMM150_RESERVED10_REG                                      0x5B
#define C13DOF_BMM150_RESERVED11_REG                                      0x5C
#define C13DOF_BMM150_RESERVED12_REG                                      0x5D
#define C13DOF_BMM150_RESERVED13_REG                                      0x5E
#define C13DOF_BMM150_RESERVED14_REG                                      0x5F
#define C13DOF_BMM150_RESERVED15_REG                                      0x60
#define C13DOF_BMM150_RESERVED16_REG                                      0x61
#define C13DOF_BMM150_RESERVED17_REG                                      0x62
#define C13DOF_BMM150_RESERVED18_REG                                      0x63
#define C13DOF_BMM150_RESERVED19_REG                                      0x64
#define C13DOF_BMM150_RESERVED20_REG                                      0x65
#define C13DOF_BMM150_RESERVED21_REG                                      0x66
#define C13DOF_BMM150_RESERVED22_REG                                      0x67
#define C13DOF_BMM150_RESERVED23_REG                                      0x68
#define C13DOF_BMM150_RESERVED24_REG                                      0x69
#define C13DOF_BMM150_RESERVED25_REG                                      0x6A
#define C13DOF_BMM150_RESERVED26_REG                                      0x6B
#define C13DOF_BMM150_RESERVED27_REG                                      0x6C
#define C13DOF_BMM150_RESERVED28_REG                                      0x6D
#define C13DOF_BMM150_RESERVED29_REG                                      0x6E
#define C13DOF_BMM150_RESERVED30_REG                                      0x6F
#define C13DOF_BMM150_RESERVED31_REG                                      0x70
#define C13DOF_BMM150_RESERVED32_REG                                      0x71
#define C13DOF_BMM150_OK                                                  0x00
#define C13DOF_BMM150_ADDR_ERR                                            0x01
#define C13DOF_BMM150_INTERRUPT_OCCURED                                   0x02
#define C13DOF_BMM150_NBYTES_ERR                                          0x03
#define C13DOF_BMM150_DATA_READY                                          0x01
#define C13DOF_BMM150_DATA_NOT_READY                                      0x00
#define C13DOF_BMM150_SUSPEND_MODE_SPI4_EN                                0x00
#define C13DOF_BMM150_SLEEP_MODE                                          0x01
#define C13DOF_BMM150_SOFT_RESET_EN                                       0x82
#define C13DOF_BMM150_SPI3_EN                                             0x04
#define C13DOF_BMM150_NORMAL_OPMODE_DR_10HZ                               0x00
#define C13DOF_BMM150_FORCED_OPMODE                                       0x02
#define C13DOF_BMM150_SLEEP_OPMODE                                        0x06
#define C13DOF_BMM150_DR_2HZ                                              0x08
#define C13DOF_BMM150_DR_6HZ                                              0x10
#define C13DOF_BMM150_DR_8HZ                                              0x18
#define C13DOF_BMM150_DR_15HZ                                             0x20
#define C13DOF_BMM150_DR_20HZ                                             0x28
#define C13DOF_BMM150_DR_25HZ                                             0x30
#define C13DOF_BMM150_DR_30HZ                                             0x38
#define C13DOF_BMM150_INTERR_DISABLED_THRESHOLDS_ENABLED                  0x00
#define C13DOF_BMM150_LOWTHRESHOLD_X_DISABLED                             0x01
#define C13DOF_BMM150_LOWTHRESHOLD_Y_DISABLED                             0x02
#define C13DOF_BMM150_LOWTHRESHOLD_Z_DISABLED                             0x04
#define C13DOF_BMM150_HIGHTHRESHOLD_X_DISABLED                            0x08
#define C13DOF_BMM150_HIGHTHRESHOLD_Y_DISABLED                            0x10
#define C13DOF_BMM150_HIGHTHRESHOLD_Z_DISABLED                            0x20
#define C13DOF_BMM150_OVERFLOW_PIN_IND_EN                                 0x40
#define C13DOF_BMM150_DATAOVERRUN_IND_EN                                  0x80
#define C13DOF_BMM150_CHANNELS_ENABLED_INTERR_DATAREADY_ACTIVE_LOW        0x00
#define C13DOF_BMM150_INTERR_PIN_ACTIVE_HIGH                              0x01
#define C13DOF_BMM150_INTERR_LATCHED                                      0x02
#define C13DOF_BMM150_DATAREADY_ACTIVE_HIGH                               0x04
#define C13DOF_BMM150_CHANNEL_X_DISABLED                                  0x08
#define C13DOF_BMM150_CHANNEL_Y_DISABLED                                  0x10
#define C13DOF_BMM150_CHANNEL_Z_DISABLED                                  0x20
#define C13DOF_BMM150_INTERR_PIN_EN                                       0x40
#define C13DOF_BMM150_DATAREADY_PIN_EN                                    0x80
#define C13DOF_BMM150_RETVAL_T                       uint8_t
/** \} */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

typedef struct
{
    uint8_t bmm150_slave_address;

} bmm150_t;


#ifdef __cplusplus
extern "C" {
#endif

void bmm150_init(  bmm150_t *bmm );

/**
 * @brief Generic BMM150 write the byte of data function
 *
 *
 * @param bmm  Click object.
 *
 * @param reg_address                8-bit BMM150 register address
 *
 * @param write_data                 Byte of data to write
 *
 * Function write the 8-bit of data to the
 * target 8-bit register address of BMM150 sensor on 13DOF Click board.
 */
C13DOF_BMM150_RETVAL_T bmm150_hal_write ( uint8_t reg_address, uint8_t write_data );

/**
 * @brief Generic BMM150 sequential data read function
 *
 *
 * @param bmm  Click object.
 *
 * @param data_out                  pointer to memory location where dataOut data be stored
 *
 * @param reg_address                8-bit BMM150 register address
 *
 * @param n_bytes                    number of bytes to be written
 *
 * @returns status:
 * - 0 : OK;
 * - 1 : ERROR;
 *
 * @description  Function read a sequential data starting from the
 * targeted 8-bit register address of BMM150 sensor on 13DOF Click board.
 */
C13DOF_BMM150_RETVAL_T bmm150_hal_read ( uint8_t *data_out, uint8_t reg_address, uint8_t n_bytes );

/**
 * @brief Check BMM150 data ready status function
 *
 *
 * @param bmm  Click object.
 *
 * @returns status:
 * - 0 : OK;
 * - 1 : ERROR;
 *
 * @description Function check data ready status by read from the
 * targeted 8-bit register address of BMM150 sensor on 13DOF Click board.
 */
C13DOF_BMM150_RETVAL_T c13dof_bmm150_check_ready ( void );

/**
 * @brief Get BMM150 Geomagnetic sensors data function
 *
 *
 * @param bmm  Click object.
 *
 * @param mag_x               pointer to memory location where Mag X-axis data be stored
 *
 * @param mag_y               pointer to memory location where Mag Y-axis data be stored
 *
 * @param mag_z               pointer to memory location where Mag Z-axis data be stored
 *
 * @param res_hall            pointer to memory location where hall resistance data be stored
 *
 * @description Function reads 16-bit X-axis and Y-axis data, 15-bit Z-axis data and 14-bit hall resistance data from the
 * targeted 8-bit register address of BMM150 sensor on 13DOF Click board.
 */
void c13dof_bmm150_read_geo_mag_data ( int16_t *mag_x, int16_t *mag_y, int16_t *mag_z, uint16_t *res_hall );

/**
 * @brief BMM150 power ON reset function
 *
 *
 * @param bmm  Click object.
 *
 * @description Function performs a reset by putting device first to suspend mode and after that to sleep mode.
 * When power on reset is performed, function puts device to normal operation mode
 * of BMM150 sensor on 13DOF Click board.
 */
void c13dof_bmm150_power_on_reset ( );

#ifdef __cplusplus
}
#endif

#endif /* _BMM150_H */

/* *****************************************************************************
 End of File
 */
