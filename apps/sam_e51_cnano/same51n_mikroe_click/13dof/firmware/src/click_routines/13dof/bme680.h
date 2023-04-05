/** \mainpage
*
****************************************************************************
* Copyright (C) 2019 MikroElektronika - www.mikroe.com
*
* File : bme680.h
*
* Date : 2019 Revision : 2.2.2
* Date : 2023/04/13 Revision : 2.2.3
* Usage: Sensor Driver for BME680 sensor
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
  bme680 header file

  Company
    Microchip Technology Inc.

  File Name
    bme680.h

  Summary
    This is the header file which needs to be included in bme680.c file

  Description
    This file contains prototypes of all the functions which give functionality
    to bme680 sensor and various Macros which needs to be included in the source file
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

#ifndef _BME680_H    /* Guard against multiple inclusion */
#define _BME680_H
#include "13dof.h"

/**
 * \defgroup macros BME680
 * \{
 */
#define C13DOF_BME680_DEVICE_SLAVE_ADDR_0                                 0x76
#define C13DOF_BME680_DEVICE_SLAVE_ADDR_1                                 0x77
#define C13DOF_BME680_CHIP_ID                                             0x61
#define C13DOF_BME680_COEFF_SIZE                                          41
#define C13DOF_BME680_COEFF_ADDR1_LEN                                     25
#define C13DOF_BME680_COEFF_ADDR2_LEN                                     16
#define C13DOF_BME680_FIELD_LENGTH                                        15
#define C13DOF_BME680_FIELD_ADDR_OFFSET                                   17
#define C13DOF_BME680_SOFT_RESET_CMD                                      0xB6
#define C13DOF_BME680_DEVICE_OK                                           0
#define C13DOF_BME680_DEVICE_ERROR                                        1
#define C13DOF_BME680_E_NULL_PTR                                          -1
#define C13DOF_BME680_E_COM_FAIL                                          -2
#define C13DOF_BME680_E_DEV_NOT_FOUND                                     -3
#define C13DOF_BME680_E_INVALID_LENGTH                                    -4
#define C13DOF_BME680_W_DEFINE_PWR_MODE                                   1
#define C13DOF_BME680_W_NO_NEW_DATA                                       2
#define C13DOF_BME680_I_MIN_CORRECTION                                    1
#define C13DOF_BME680_I_MAX_CORRECTION                                    2
#define C13DOF_BME680_ADDR_RES_HEAT_VAL_ADDR                              0x00
#define C13DOF_BME680_ADDR_RES_HEAT_RANGE_ADDR                            0x02
#define C13DOF_BME680_ADDR_RANGE_SW_ERR_ADDR                              0x04
#define C13DOF_BME680_ADDR_SENS_CONF_START                                0x5A
#define C13DOF_BME680_ADDR_GAS_CONF_START                                 0x64
#define C13DOF_BME680_FIELD0_ADDR                                         0x1D
#define C13DOF_BME680_RES_HEAT0_ADDR                                      0x5A
#define C13DOF_BME680_GAS_WAIT0_ADDR                                      0x64
#define C13DOF_BME680_CONF_HEAT_CTRL_ADDR                                 0x70
#define C13DOF_BME680_CONF_ODR_RUN_GAS_NBC_ADDR                           0x71
#define C13DOF_BME680_CONF_OS_H_ADDR                                      0x72
#define C13DOF_BME680_MEM_PAGE_ADDR                                       0xf3
#define C13DOF_BME680_CONF_T_P_MODE_ADDR                                  0x74
#define C13DOF_BME680_CONF_ODR_FILT_ADDR                                  0x75
#define C13DOF_BME680_COEFF_ADDR1                                         0x89
#define C13DOF_BME680_COEFF_ADDR2                                         0xe1
#define C13DOF_BME680_CHIP_ID_ADDR                                        0xD0
#define C13DOF_BME680_SOFT_RESET_ADDR                                     0xE0
#define C13DOF_BME680_ENABLE_HEATER                                       0x00
#define C13DOF_BME680_DISABLE_HEATER                                      0x08
#define C13DOF_BME680_DISABLE_GAS_MEAS                                    0x00
#define C13DOF_BME680_ENABLE_GAS_MEAS                                     0x01
#define C13DOF_BME680_OS_NONE                                             0
#define C13DOF_BME680_OS_1X                                               1
#define C13DOF_BME680_OS_2X                                               2
#define C13DOF_BME680_OS_4X                                               3
#define C13DOF_BME680_OS_8X                                               4
#define C13DOF_BME680_OS_16X                                              5
#define C13DOF_BME680_FILTER_SIZE_0                                       0
#define C13DOF_BME680_FILTER_SIZE_1                                       1
#define C13DOF_BME680_FILTER_SIZE_3                                       2
#define C13DOF_BME680_FILTER_SIZE_7                                       3
#define C13DOF_BME680_FILTER_SIZE_15                                      4
#define C13DOF_BME680_FILTER_SIZE_31                                      5
#define C13DOF_BME680_FILTER_SIZE_63                                      6
#define C13DOF_BME680_FILTER_SIZE_127                                     7
#define C13DOF_BME680_SLEEP_MODE                                          0
#define C13DOF_BME680_FORCED_MODE                                         1
#define C13DOF_BME680_RESET_PERIOD                                        10
#define C13DOF_BME680_MEM_PAGE0                                           0x10
#define C13DOF_BME680_MEM_PAGE1                                           0x00
#define C13DOF_BME680_HUM_REG_SHIFT_VAL                                   4
#define C13DOF_BME680_RUN_GAS_DISABLE                                     0
#define C13DOF_BME680_RUN_GAS_ENABLE                                      1
#define C13DOF_BME680_TMP_BUFFER_LENGTH                                   40
#define C13DOF_BME680_REG_BUFFER_LENGTH                                   6
#define C13DOF_BME680_FIELD_DATA_LENGTH                                   3
#define C13DOF_BME680_GAS_REG_BUF_LENGTH                                  20
#define C13DOF_BME680_OST_SEL                                             1
#define C13DOF_BME680_OSP_SEL                                             2
#define C13DOF_BME680_OSH_SEL                                             4
#define C13DOF_BME680_GAS_MEAS_SEL                                        8
#define C13DOF_BME680_FILTER_SEL                                          16
#define C13DOF_BME680_HCNTRL_SEL                                          32
#define C13DOF_BME680_RUN_GAS_SEL                                         64
#define C13DOF_BME680_NBCONV_SEL                                          128
#define C13DOF_BME680_GAS_SENSOR_SEL                                      ( C13DOF_BME680_GAS_MEAS_SEL | \
                                                                                      C13DOF_BME680_RUN_GAS_SEL | \
                                                                                      C13DOF_BME680_NBCONV_SEL )
#define C13DOF_BME680_NBCONV_MIN                                          0
#define C13DOF_BME680_NBCONV_MAX                                          10
#define C13DOF_BME680_GAS_MEAS_MSK                                        0x30
#define C13DOF_BME680_NBCONV_MSK                                          0X0F
#define C13DOF_BME680_FILTER_MSK                                          0X1C
#define C13DOF_BME680_OST_MSK                                             0XE0
#define C13DOF_BME680_OSP_MSK                                             0X1C
#define C13DOF_BME680_OSH_MSK                                             0X07
#define C13DOF_BME680_HCTRL_MSK                                           0x08
#define C13DOF_BME680_RUN_GAS_MSK                                         0x10
#define C13DOF_BME680_MODE_MSK                                            0x03
#define C13DOF_BME680_RHRANGE_MSK                                         0x30
#define C13DOF_BME680_RSERROR_MSK                                         0xf0
#define C13DOF_BME680_NEW_DATA_MSK                                        0x80
#define C13DOF_BME680_GAS_INDEX_MSK                                       0x0f
#define C13DOF_BME680_GAS_RANGE_MSK                                       0x0f
#define C13DOF_BME680_GASM_VALID_MSK                                      0x20
#define C13DOF_BME680_HEAT_STAB_MSK                                       0x10
#define C13DOF_BME680_MEM_PAGE_MSK                                        0x10
#define C13DOF_BME680_SPI_RD_MSK                                          0x80
#define C13DOF_BME680_SPI_WR_MSK                                          0x7f
#define C13DOF_BME680_BIT_H1_DATA_MSK                                     0x0F
#define C13DOF_BME680_GAS_MEAS_POS                                        4
#define C13DOF_BME680_FILTER_POS                                          2
#define C13DOF_BME680_OST_POS                                             5
#define C13DOF_BME680_OSP_POS                                             2
#define C13DOF_BME680_RUN_GAS_POS                                         4
#define C13DOF_BME680_T2_LSB_REG                                          1
#define C13DOF_BME680_T2_MSB_REG                                          2
#define C13DOF_BME680_T3_REG                                              3
#define C13DOF_BME680_P1_LSB_REG                                          5
#define C13DOF_BME680_P1_MSB_REG                                          6
#define C13DOF_BME680_P2_LSB_REG                                          7
#define C13DOF_BME680_P2_MSB_REG                                          8
#define C13DOF_BME680_P3_REG                                              9
#define C13DOF_BME680_P4_LSB_REG                                          11
#define C13DOF_BME680_P4_MSB_REG                                          12
#define C13DOF_BME680_P5_LSB_REG                                          13
#define C13DOF_BME680_P5_MSB_REG                                          14
#define C13DOF_BME680_P7_REG                                              15
#define C13DOF_BME680_P6_REG                                              16
#define C13DOF_BME680_P8_LSB_REG                                          19
#define C13DOF_BME680_P8_MSB_REG                                          20
#define C13DOF_BME680_P9_LSB_REG                                          21
#define C13DOF_BME680_P9_MSB_REG                                          22
#define C13DOF_BME680_P10_REG                                             23
#define C13DOF_BME680_H2_MSB_REG                                          25
#define C13DOF_BME680_H2_LSB_REG                                          26
#define C13DOF_BME680_H1_LSB_REG                                          26
#define C13DOF_BME680_H1_MSB_REG                                          27
#define C13DOF_BME680_H3_REG                                              28
#define C13DOF_BME680_H4_REG                                              29
#define C13DOF_BME680_H5_REG                                              30
#define C13DOF_BME680_H6_REG                                              31
#define C13DOF_BME680_H7_REG                                              32
#define C13DOF_BME680_T1_LSB_REG                                          33
#define C13DOF_BME680_T1_MSB_REG                                          34
#define C13DOF_BME680_GH2_LSB_REG                                         35
#define C13DOF_BME680_GH2_MSB_REG                                         36
#define C13DOF_BME680_GH1_REG                                             37
#define C13DOF_BME680_GH3_REG                                             38
#define C13DOF_BME680_REG_FILTER_INDEX                                    5
#define C13DOF_BME680_REG_TEMP_INDEX                                      4
#define C13DOF_BME680_REG_PRES_INDEX                                      4
#define C13DOF_BME680_REG_HUM_INDEX                                       2
#define C13DOF_BME680_REG_NBCONV_INDEX                                    1
#define C13DOF_BME680_REG_RUN_GAS_INDEX                                   1
#define C13DOF_BME680_REG_HCTRL_INDEX                                     0
#define C13DOF_BME680_MAX_OVERFLOW_VAL                                    0x40000000
#define C13DOF_BME680_DATA_TEMPERATURE                                    0x01
#define C13DOF_BME680_DATA_PRESSURE                                       0x02
#define C13DOF_BME680_DATA_HUMIDITY                                       0x03
#define C13DOF_BME680_OK                                                  0x01
#define C13DOF_BME680_ERROR                                               0x00
#define C13DOF_BME680_RETVAL_T                       uint8_t
/** \} */



typedef struct
{
    uint8_t status;
    uint8_t gas_index;
    uint8_t meas_index;
    int16_t temperature;
    float pressure;
    uint32_t humidity;
    uint32_t gas_resistance;

}T_C13DOF_BME680_FIELD_DATA;

typedef struct
{

    uint16_t par_h1;
    uint16_t par_h2;
    int8_t par_h3;
    int8_t par_h4;
    int8_t par_h5;
    uint8_t par_h6;
    int8_t par_h7;

    int8_t par_gh1;
    int16_t par_gh2;
    int8_t par_gh3;

    uint16_t par_t1;
    int16_t par_t2;
    int8_t par_t3;

    uint16_t par_p1;
    int16_t par_p2;
    int8_t par_p3;
    int16_t par_p4;
    int16_t par_p5;
    int8_t par_p6;
    int8_t par_p7;
    int16_t par_p8;
    int16_t par_p9;
    uint8_t par_p10;

    int32_t t_fine;

    uint8_t res_heat_range;
    int8_t res_heat_val;
    int8_t range_sw_err;

} T_C13DOF_BME680_CALIB_DATA;

typedef struct
{
    uint8_t os_hum;

    uint8_t os_temp;

    uint8_t os_pres;

    uint8_t filter;

}T_C13DOF_BME680_TPH_SETTINGS;


typedef struct
{
    uint8_t nb_conv;

    uint8_t heatr_ctrl;

    uint8_t run_gas;

    uint16_t heatr_temp;

    uint16_t heatr_dur;

}T_C13DOF_BME680_GAS_SETTINGS;

typedef struct
{
    uint8_t bme680_slave_address;

    T_C13DOF_BME680_FIELD_DATA  d_data;
    T_C13DOF_BME680_CALIB_DATA calib;
    T_C13DOF_BME680_TPH_SETTINGS tph_sett;
    T_C13DOF_BME680_GAS_SETTINGS gas_sett;

    uint8_t device_mem_page;
    uint8_t device_power_mode;

} bme680_t;
/** \} */
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

void bme680_init( bme680_t *bme );
/**
 * @brief Generic BME680 write the byte of data function
 *
 *
 * @param bme  Click object.
 *
 * @param reg_address                8-bit BME680 register address
 *
 * @param write_data                 Byte of data to write
 *
 * @description  Function write the 8-bit of data to the
 * target 8-bit register address of BME680 sensor on 13DOF Click board.
 */
void bme680_hal_write ( bme680_t *bme, uint8_t reg_address, uint8_t write_data );

/**
 * @brief Generic BME680 read byte of data function
 *
 *
 * @param bme  Click object.
 *
 * @param reg_address                8-bit BME680 register address
 *
 * @returns
 * 8-bit read data
 *
 * @description Function read the 8-bit of data from the
 * target 8-bit register address of BME680 sensor on 13DOF Click board.
 */
uint8_t bme680_hal_read ( bme680_t *bme, uint8_t reg_address );

/**
 * @brief Check BME680 device ID function
 *
 *
 * @param bme  Click object.
 *
 * @returns status:
 * - 0 : ERROR;
 * - 1 : OK;
 *
 * @description Function check device ID by read ID value from the
 * sensor ID register address of BME680 sensor on 13DOF Click board.
 */
//C13DOF_BME680_RETVAL_T c13dof_bme680_check_id( bme680_t *bme );

/**
 * @brief Get BME680 device ID function
 *
 *
 * @param bme  Click object.
 *
 * @returns
 * 8-bit device ID value
 *
 * @description Function read device ID from the
 * sensor ID register address of BME680 sensor on 13DOF Click board.
 *
 * @note
 * Default device: ID = 0x61.
 */
//uint8_t c13dof_bme680_get_device_id ( bme680_t *bme );

/**
 * @brief Software BME680 reset function
 *
 *
 * @param bme  Click object.
 *
 * @description Function software reset by write value of 0xB6 to the
 * sensor reset register address of BME680 sensor on 13DOF Click board.
 */
void c13dof_bme680_soft_reset ( );

/**
 * @brief Get BME680 factory calibration parameters function
 *
 *
 * @param bme  Click object.
 *
 * Function read factory calibration parameters value from the
 * sensor calibration registers address of BME680 sensor on 13DOF Click board.
 *
 * @note
 * @description This function must be called at least once at the beginning of the program
 * to read and store the calibration parameters in the memory.
 */
void c13dof_bme680_get_calibration_data ( bme680_t *bme );


/**
 * @brief Get BME680 ambient data function
 *
 *
 * @param bme  Click object.
 *
 * @param data_in    Data for reading:
 * - Temperature : _C13DOF_BME680_DATA_TEMPERATURE ( 0x01 );
 * - Pressure    : _C13DOF_BME680_DATA_PRESSURE    ( 0x02 );
 * - Humidity    : _C13DOF_BME680_DATA_HUMIDITY    ( 0x03 );
 *
 * @returns
 * float ambient ( temperature, pressure or humidity ) data
 *
 * @description Function get ambient data by sets device force mode and read data from the
 * sensor temperature,  pressure or humidity register address
 * of BME680 sensor on 13DOF Click board.
 */
float c13dof_bme680_get_ambient_data ( bme680_t *bme, uint8_t data_in );

/**
 * @brief Gets BME680 temperature in degrees Celsius function
 *
 *
 * @param bme  Click object.
 *
 * @returns
 * float value of temperature in degrees Celsius
 *
 *@description Function get temperature value in degrees Celsius [ ?C ] from the
 * sensor temperature register address of BME680 sensor on 13DOF Click board.
 */
float c13dof_bme680_get_temperature ( bme680_t *bme );

/**
 * @brief Gets BME680 humidity in percentage [ % ] function
 *
 *
 * @param bme  Click object.
 *
 * @returns
 * float value of humidity in percentage [ % ]
 *
 *@description Function get humidity value in percentage [ % ] from the
 * sensor humidity register address of BME680 sensor on 13DOF Click board.
 */
float c13dof_bme680_get_humidity ( bme680_t *bme );

/**
 * @brief Gets BME680 pressure in degrees Celsius function
 *
 *
 * @param bme  Click object.
 *
 * @returns
 * float value of pressure in [ mbar ]
 *
 * @description Function get pressure value in [ mbar ] from the
 * sensor pressure register address of BME680 sensor on 13DOF Click board.
 */
float c13dof_bme680_get_pressure ( bme680_t *bme );

/**
 * @brief Gets BME680 gas resistance data function
 *
 *
 * @param bme  Click object.
 *
 * @returns
 * 32-bite gas resistance data
 *
 * @description Function get gas resistance value from the
 * sensor gas resistance register address of BME680 sensor on 13DOF Click board.
 */
uint32_t c13dof_bme680_get_gas_resistance ( bme680_t *bme );


#ifdef __cplusplus
}
#endif

#endif /* _BME680_H */

/* *****************************************************************************
 End of File
 */
