/** \mainpage
*
****************************************************************************
* Copyright (C) 2019 MikroElektronika - www.mikroe.com
*
* File : bme680.c
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
  bme680 source file

  Company
    Microchip Technology Inc.

  File Name
    bme680.c

  Summary
    This file contains definitions of all the functions which gives
    functionality to bme680 sensor

  Description
    This file contains definitions of functions like getting temperature , pressure
    which should be displayed on the terminal
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

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */
#include "13dof.h"
#include "bme680.h"
#include "../click_interface.h"

/* TODO:  Include other files here if needed. */
// ----------------------------------------------------------------- CONSTANTS
static const float lookup_k1_range[16] =
{
    0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, -0.8,
    0.0, 0.0, -0.2, -0.5, 0.0, -1.0, 0.0, 0.0
};
static const float lookup_k2_range[16] =
{
    0.0, 0.0, 0.0, 0.0, 0.1, 0.7, 0.0, -0.8,
    -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

static const int8_t device_amb_temp = 25;
// Macro to combine two 8 bit data's to form a 16 bit data
#define BME680_CONCAT_BYTES(msb, lsb)        ( ( ( uint16_t )msb << 8) | ( uint16_t )lsb)

// Macro to SET and GET BITS of a register
#define BME680_SET_BITS( reg_data, bitname, data) \
                ( ( reg_data & ~(bitname##_MSK ) ) | \
                ( (data << bitname##_POS) & bitname##_MSK ) )


// Macro variant to handle the bitname position if it is zero
#define BME680_SET_BITS_POS_0( reg_data, bitname, data) \
                                ( ( reg_data & ~(bitname##_MSK ) ) | \
                                (data & bitname##_MSK ) )

static int8_t user_read_data( uint8_t reg_addr, uint8_t *reg_data, uint16_t len );

static int8_t user_write_data( uint8_t reg_addr, uint8_t *reg_data, uint16_t len );

static int8_t bme680_get_regs( uint8_t reg_addr, uint8_t *reg_data, uint16_t len );

static int8_t bme680_set_regs( uint8_t *reg_addr, uint8_t *reg_data, uint8_t len );

static int8_t bme680_set_sensor_settings( bme680_t *bme, uint16_t desired_settings ) ;

static int8_t bme680_set_sensor_mode( bme680_t *bme );

static int8_t bme680_set_gas_config( bme680_t *bme );

static int16_t bme680_calc_temperature( bme680_t *bme, uint32_t temp_adc );

static uint32_t bme680_calc_humidity( bme680_t *bme, uint16_t hum_adc );

static uint8_t bme680_calc_heater_res( bme680_t *bme, uint16_t ble_temp );

static float bme680_calc_pressure( bme680_t *bme, uint32_t pres_adc );

static float bme680_calc_gas_resistance( bme680_t *bme, uint16_t gas_res_adc, uint8_t gas_range );

static uint8_t bme680_calc_heater_dur( bme680_t *bme, uint16_t dur );

static int8_t bme680_read_field_data( bme680_t *bme, T_C13DOF_BME680_FIELD_DATA *d_data );

static int8_t bme680_boundary_check( bme680_t *bme, uint8_t *value, uint8_t min, uint8_t max);

// ------------------------------------------------ PUBLIC FUNCTION DEFINITIONS
void bme680_init( bme680_t *bme )
{
    bme->bme680_slave_address = C13DOF_BME680_DEVICE_SLAVE_ADDR_0;
    bme->tph_sett.os_hum = C13DOF_BME680_OS_2X;
    bme->tph_sett.os_pres = C13DOF_BME680_OS_4X;
    bme->tph_sett.os_temp = C13DOF_BME680_OS_8X;
    bme->tph_sett.filter = C13DOF_BME680_FILTER_SIZE_3;

    bme->gas_sett.run_gas = C13DOF_BME680_ENABLE_GAS_MEAS;

    bme->gas_sett.heatr_temp = 320;
    bme->gas_sett.heatr_dur = 150;

    bme->device_power_mode = C13DOF_BME680_FORCED_MODE;

}

void bme680_hal_write( bme680_t *bme, uint8_t reg_address, uint8_t write_data )
{
    uint8_t w_buffer[ 2 ];

    w_buffer[ 0 ] = reg_address;
    w_buffer[ 1 ] = write_data;

    CLICK_13DOF_I2C_Write( C13DOF_BME680_DEVICE_SLAVE_ADDR_0, w_buffer, 2 );
    while(CLICK_13DOF_I2C_IsBusy() == true);
}

uint8_t bme680_hal_read( bme680_t *bme, uint8_t reg_address )
{
    uint8_t r_buffer[ 1 ];

    CLICK_13DOF_I2C_WriteRead( C13DOF_BME680_DEVICE_SLAVE_ADDR_0, &reg_address, 1, r_buffer, 1 );
    while(CLICK_13DOF_I2C_IsBusy() == true);
    return r_buffer[ 0 ];
}

void c13dof_bme680_soft_reset ( )
{
    uint8_t reg_addr;
    uint8_t soft_rst_cmd;

    reg_addr = C13DOF_BME680_SOFT_RESET_ADDR;
    soft_rst_cmd = C13DOF_BME680_SOFT_RESET_CMD;

    bme680_set_regs( &reg_addr, &soft_rst_cmd, 1 );
    CLICK_13DOF_DelayMs(10);
}

void c13dof_bme680_get_calibration_data ( bme680_t *bme )
{
    uint8_t coeff_array[ C13DOF_BME680_COEFF_SIZE ] = { 0 };
    uint8_t temp_var = 0;

    bme680_get_regs( C13DOF_BME680_COEFF_ADDR1, coeff_array,  C13DOF_BME680_COEFF_ADDR1_LEN );
    bme680_get_regs( C13DOF_BME680_COEFF_ADDR2, &coeff_array[ C13DOF_BME680_COEFF_ADDR1_LEN ], C13DOF_BME680_COEFF_ADDR2_LEN );

    bme->calib.par_t1 = ( uint16_t ) ( BME680_CONCAT_BYTES( coeff_array[ C13DOF_BME680_T1_MSB_REG ], coeff_array[ C13DOF_BME680_T1_LSB_REG ] ) );
    bme->calib.par_t2 = ( int16_t ) ( BME680_CONCAT_BYTES( coeff_array[ C13DOF_BME680_T2_MSB_REG ], coeff_array[ C13DOF_BME680_T2_LSB_REG ] ) );
    bme->calib.par_t3 = ( int8_t ) ( coeff_array[ C13DOF_BME680_T3_REG ]);

    bme->calib.par_p1 = ( uint16_t ) ( BME680_CONCAT_BYTES( coeff_array[ C13DOF_BME680_P1_MSB_REG ], coeff_array[ C13DOF_BME680_P1_LSB_REG ] ) );
    bme->calib.par_p2 = ( int16_t ) ( BME680_CONCAT_BYTES( coeff_array[ C13DOF_BME680_P2_MSB_REG ], coeff_array[ C13DOF_BME680_P2_LSB_REG ] ) );
    bme->calib.par_p3 = ( int8_t ) coeff_array[ C13DOF_BME680_P3_REG ];
    bme->calib.par_p4 = ( int16_t ) ( BME680_CONCAT_BYTES( coeff_array[ C13DOF_BME680_P4_MSB_REG ], coeff_array[ C13DOF_BME680_P4_LSB_REG ] ) );
    bme->calib.par_p5 = ( int16_t ) ( BME680_CONCAT_BYTES( coeff_array[ C13DOF_BME680_P5_MSB_REG ], coeff_array[ C13DOF_BME680_P5_LSB_REG ] ) );
    bme->calib.par_p6 = ( int8_t ) ( coeff_array[ C13DOF_BME680_P6_REG ]);
    bme->calib.par_p7 = ( int8_t ) ( coeff_array[ C13DOF_BME680_P7_REG ]);
    bme->calib.par_p8 = ( int16_t ) ( BME680_CONCAT_BYTES( coeff_array[ C13DOF_BME680_P8_MSB_REG ], coeff_array[ C13DOF_BME680_P8_LSB_REG ] ) );
    bme->calib.par_p9 = ( int16_t ) ( BME680_CONCAT_BYTES( coeff_array[ C13DOF_BME680_P9_MSB_REG ], coeff_array[ C13DOF_BME680_P9_LSB_REG ] ) );
    bme->calib.par_p10 = ( uint8_t ) ( coeff_array[ C13DOF_BME680_P10_REG ]);

    bme->calib.par_h1 = ( uint16_t ) ( ( ( uint16_t ) coeff_array[ C13DOF_BME680_H1_MSB_REG ] << C13DOF_BME680_HUM_REG_SHIFT_VAL)
       | ( coeff_array[ C13DOF_BME680_H1_LSB_REG ] & C13DOF_BME680_BIT_H1_DATA_MSK ) );
    bme->calib.par_h2 = ( uint16_t ) ( ( ( uint16_t ) coeff_array[ C13DOF_BME680_H2_MSB_REG ] << C13DOF_BME680_HUM_REG_SHIFT_VAL)
       | ( ( coeff_array[ C13DOF_BME680_H2_LSB_REG ]) >> C13DOF_BME680_HUM_REG_SHIFT_VAL ) );
    bme->calib.par_h3 = ( int8_t ) coeff_array[ C13DOF_BME680_H3_REG ];
    bme->calib.par_h4 = ( int8_t ) coeff_array[ C13DOF_BME680_H4_REG ];
    bme->calib.par_h5 = ( int8_t ) coeff_array[ C13DOF_BME680_H5_REG ];
    bme->calib.par_h6 = ( uint8_t ) coeff_array[ C13DOF_BME680_H6_REG ];
    bme->calib.par_h7 = ( int8_t ) coeff_array[ C13DOF_BME680_H7_REG ];

    bme->calib.par_gh1 = ( int8_t ) coeff_array[ C13DOF_BME680_GH1_REG ];
    bme->calib.par_gh2 = ( int16_t ) ( BME680_CONCAT_BYTES( coeff_array[ C13DOF_BME680_GH2_MSB_REG ], coeff_array[ C13DOF_BME680_GH2_LSB_REG ] ) );
    bme->calib.par_gh3 = ( int8_t ) coeff_array[ C13DOF_BME680_GH3_REG ];

    bme680_get_regs( C13DOF_BME680_ADDR_RES_HEAT_RANGE_ADDR, &temp_var, 1 );
    bme->calib.res_heat_range = ( ( temp_var & C13DOF_BME680_RHRANGE_MSK) / 16 );

    bme680_get_regs( C13DOF_BME680_ADDR_RES_HEAT_VAL_ADDR, &temp_var, 1 );
    bme->calib.res_heat_val = ( int8_t ) temp_var;

    bme680_get_regs( C13DOF_BME680_ADDR_RANGE_SW_ERR_ADDR, &temp_var, 1 );
    bme->calib.range_sw_err = ( ( int8_t ) temp_var & ( int8_t ) C13DOF_BME680_RSERROR_MSK ) / 16;
    bme680_set_sensor_settings( bme,  C13DOF_BME680_OST_SEL |
                               C13DOF_BME680_OSP_SEL |
                               C13DOF_BME680_OSH_SEL |
                               C13DOF_BME680_FILTER_SEL |
                               C13DOF_BME680_GAS_SENSOR_SEL );
    bme680_set_sensor_mode( bme );
}


float c13dof_bme680_get_ambient_data ( bme680_t *bme, uint8_t data_in )
{
    bme680_read_field_data( bme, &bme->d_data );

    if ( bme->device_power_mode == C13DOF_BME680_FORCED_MODE )
    {
        bme680_set_sensor_mode( bme );
    }

    if ( data_in == C13DOF_BME680_DATA_TEMPERATURE )
    {
        return ( float )bme->d_data.temperature / 100.0;
    }
    else if ( data_in == C13DOF_BME680_DATA_PRESSURE )
    {
        return ( float )bme->d_data.pressure / 100.0;
    }
    else if ( data_in == C13DOF_BME680_DATA_HUMIDITY )
    {
        return ( float )bme->d_data.humidity / 1000.0;
    }
    else
    {
        return 1;
    }
}

float c13dof_bme680_get_temperature ( bme680_t *bme )
{
    float temperature;

    temperature = c13dof_bme680_get_ambient_data( bme, C13DOF_BME680_DATA_TEMPERATURE );

    return temperature;
}

float c13dof_bme680_get_humidity ( bme680_t *bme )
{
    float humidity;

    humidity = c13dof_bme680_get_ambient_data( bme, C13DOF_BME680_DATA_HUMIDITY );

    return humidity;
}

float c13dof_bme680_get_pressure ( bme680_t *bme )
{
    float pressure;

    pressure = c13dof_bme680_get_ambient_data( bme, C13DOF_BME680_DATA_PRESSURE );

    return pressure;
}

uint32_t c13dof_bme680_get_gas_resistance ( bme680_t *bme )
{
    uint32_t gas_resistance = 0;

    bme680_read_field_data( bme, &bme->d_data );

    if ( bme->d_data.status & C13DOF_BME680_GASM_VALID_MSK )
    {
        gas_resistance = bme->d_data.gas_resistance;
    }

    if ( bme->device_power_mode == C13DOF_BME680_FORCED_MODE )
    {
        bme680_set_sensor_mode( bme );
    }

    return gas_resistance;
}
// ---------------------------------------------- PRIVATE FUNCTION DECLARATIONS

static int8_t user_read_data ( uint8_t reg_addr, uint8_t *reg_data, uint16_t len )
{
    uint8_t tx_buf[ 1 ];

    tx_buf [ 0 ] = reg_addr;

    CLICK_13DOF_I2C_WriteRead( C13DOF_BME680_DEVICE_SLAVE_ADDR_0, tx_buf, 1, reg_data, len);
    while(CLICK_13DOF_I2C_IsBusy() == true);
    return 0;
}

static int8_t user_write_data ( uint8_t reg_addr, uint8_t *reg_data, uint16_t len )
{
    int16_t i;
    uint8_t tx_buf[ 100 ];

    tx_buf[ 0 ] = reg_addr;

    for ( i = 0; i < len; i++ )
    {
        tx_buf[ i+1 ] = reg_data[ i ];
    }

    CLICK_13DOF_I2C_Write( C13DOF_BME680_DEVICE_SLAVE_ADDR_0, tx_buf, len + 1 );
    while(CLICK_13DOF_I2C_IsBusy() == true);
    return 0;
}

static int8_t bme680_get_regs ( uint8_t reg_addr, uint8_t *reg_data, uint16_t len )
{
    int8_t rslt = 0;
    int8_t com_rslt;

    com_rslt = user_read_data( reg_addr, reg_data, len );

    if ( com_rslt != 0)
    {
        rslt = C13DOF_BME680_E_COM_FAIL;
    }

    return rslt;
}

static int8_t bme680_set_regs ( uint8_t *reg_addr, uint8_t *reg_data, uint8_t len )
{
    int8_t rslt = 0;
    int8_t com_rslt;

    uint8_t tmp_buff[ C13DOF_BME680_TMP_BUFFER_LENGTH ] = { 0 };
    uint16_t index;

    if ( ( len > 0 ) && ( len < C13DOF_BME680_TMP_BUFFER_LENGTH / 2 ) )
    {

        for ( index = 0; index < len; index++ )
        {
            tmp_buff[ ( 2 * index ) ] = reg_addr[ index ];

            tmp_buff[ ( 2 * index ) + 1 ] = reg_data[ index ];
        }

        if ( rslt == C13DOF_BME680_DEVICE_OK )
        {
            com_rslt = user_write_data( tmp_buff[ 0 ], &tmp_buff[ 1 ], ( 2 * len ) - 1 );
            if ( com_rslt != 0 )
            {
                rslt = C13DOF_BME680_E_COM_FAIL;
            }
        }
    }
    else
    {
        rslt = C13DOF_BME680_E_INVALID_LENGTH;
    }

    return rslt;
}

static int8_t bme680_set_sensor_settings ( bme680_t *bme, uint16_t desired_settings )
{
    int8_t rslt = 0;
    uint8_t reg_addr;
    uint8_t d_data = 0;
    uint8_t count = 0;
    uint8_t reg_array[ C13DOF_BME680_REG_BUFFER_LENGTH ] = { 0 };
    uint8_t data_array[ C13DOF_BME680_REG_BUFFER_LENGTH ] = { 0 };
    uint8_t intended_power_mode = bme->device_power_mode;

    if ( desired_settings & C13DOF_BME680_GAS_MEAS_SEL )
    {
        rslt = bme680_set_gas_config( bme );
    }

    bme->device_power_mode = C13DOF_BME680_SLEEP_MODE;

    if ( rslt == C13DOF_BME680_DEVICE_OK )
    {
        rslt = bme680_set_sensor_mode( bme );
    }

    if ( desired_settings & C13DOF_BME680_FILTER_SEL )
    {
        rslt = bme680_boundary_check( bme, &bme->tph_sett.filter, C13DOF_BME680_FILTER_SIZE_0, C13DOF_BME680_FILTER_SIZE_127 );
        reg_addr = C13DOF_BME680_CONF_ODR_FILT_ADDR;

        if ( rslt == C13DOF_BME680_DEVICE_OK )
        {
            rslt = bme680_get_regs( reg_addr, &d_data, 1 );
        }
        if ( desired_settings & C13DOF_BME680_FILTER_SEL )
        {
            d_data = BME680_SET_BITS( d_data, C13DOF_BME680_FILTER, bme-> tph_sett.filter );
        }
        reg_array[ count ] = reg_addr;
        data_array[ count ] = d_data;
        count++;
    }

    if ( desired_settings & C13DOF_BME680_HCNTRL_SEL )
    {
        rslt = bme680_boundary_check( bme, &bme->gas_sett.heatr_ctrl, C13DOF_BME680_ENABLE_HEATER,
                C13DOF_BME680_DISABLE_HEATER );
        reg_addr = C13DOF_BME680_CONF_HEAT_CTRL_ADDR;

        if ( rslt == C13DOF_BME680_DEVICE_OK )
        {
                rslt = bme680_get_regs( reg_addr, &d_data, 1 );
        }
        d_data = BME680_SET_BITS_POS_0( d_data, C13DOF_BME680_HCTRL, bme->gas_sett.heatr_ctrl );

        reg_array[ count ] = reg_addr;
        data_array[ count ] = d_data;
        count++;
    }

    if ( desired_settings & ( C13DOF_BME680_OST_SEL | C13DOF_BME680_OSP_SEL ) )
    {
        rslt = bme680_boundary_check( bme, &bme->tph_sett.os_temp, C13DOF_BME680_OS_NONE, C13DOF_BME680_OS_16X );
        reg_addr = C13DOF_BME680_CONF_T_P_MODE_ADDR;

        if ( rslt == C13DOF_BME680_DEVICE_OK )
        {
            rslt = bme680_get_regs( reg_addr, &d_data, 1 );
        }
        if ( desired_settings & C13DOF_BME680_OST_SEL )
        {
            d_data = BME680_SET_BITS( d_data, C13DOF_BME680_OST, bme->tph_sett.os_temp );
        }
        if ( desired_settings & C13DOF_BME680_OSP_SEL )
        {
            d_data = BME680_SET_BITS( d_data, C13DOF_BME680_OSP, bme->tph_sett.os_pres );
        }
        reg_array[ count ] = reg_addr;
        data_array[ count ] = d_data;
        count++;
    }

    if ( desired_settings & C13DOF_BME680_OSH_SEL )
    {
        rslt = bme680_boundary_check( bme,  &bme->tph_sett.os_hum, C13DOF_BME680_OS_NONE, C13DOF_BME680_OS_16X );
        reg_addr = C13DOF_BME680_CONF_OS_H_ADDR;

        if ( rslt == C13DOF_BME680_DEVICE_OK )
        {
            rslt = bme680_get_regs( reg_addr, &d_data, 1 );
        }
        d_data = BME680_SET_BITS_POS_0( d_data, C13DOF_BME680_OSH, bme->tph_sett.os_hum );

        reg_array[ count ] = reg_addr;
        data_array[ count ] = d_data;
        count++;
    }

    if ( desired_settings & ( C13DOF_BME680_RUN_GAS_SEL | C13DOF_BME680_NBCONV_SEL ) )
    {
        rslt = bme680_boundary_check( bme, &bme->gas_sett.run_gas, C13DOF_BME680_RUN_GAS_DISABLE, C13DOF_BME680_RUN_GAS_ENABLE );
        if ( rslt == C13DOF_BME680_DEVICE_OK )
        {
            rslt = bme680_boundary_check( bme, &bme->gas_sett.nb_conv, C13DOF_BME680_NBCONV_MIN, C13DOF_BME680_NBCONV_MAX );
        }

        reg_addr = C13DOF_BME680_CONF_ODR_RUN_GAS_NBC_ADDR;

        if ( rslt == C13DOF_BME680_DEVICE_OK )
        {
            rslt = bme680_get_regs( reg_addr, &d_data, 1 );
        }
        if ( desired_settings & C13DOF_BME680_RUN_GAS_SEL )
        {
            d_data = BME680_SET_BITS( d_data, C13DOF_BME680_RUN_GAS, bme->gas_sett.run_gas );
        }
        if ( desired_settings & C13DOF_BME680_NBCONV_SEL )
        {
            d_data = BME680_SET_BITS_POS_0( d_data, C13DOF_BME680_NBCONV, bme->gas_sett.nb_conv );
        }
        reg_array[ count ] = reg_addr;
        data_array[ count ] = d_data;
        count++;
    }

    if ( rslt == C13DOF_BME680_DEVICE_OK )
    {
        rslt = bme680_set_regs( reg_array, data_array, count );
    }

    bme->device_power_mode = intended_power_mode;

    return rslt;
}

static int8_t bme680_set_sensor_mode ( bme680_t *bme )
{
    int8_t rslt = 0;
    uint8_t tmp_pow_mode;
    uint8_t pow_mode = 0;
    uint8_t reg_addr = C13DOF_BME680_CONF_T_P_MODE_ADDR;

    do
    {
        rslt = bme680_get_regs( C13DOF_BME680_CONF_T_P_MODE_ADDR, &tmp_pow_mode, 1 );
        if ( rslt == C13DOF_BME680_DEVICE_OK )
        {
            pow_mode = ( tmp_pow_mode & C13DOF_BME680_MODE_MSK );

            if ( pow_mode != C13DOF_BME680_SLEEP_MODE )
            {
                tmp_pow_mode = tmp_pow_mode & ( ~C13DOF_BME680_MODE_MSK );
                rslt = bme680_set_regs( &reg_addr, &tmp_pow_mode, 1 );
                CLICK_13DOF_DelayMs(10);
            }
        }
    } while ( pow_mode != C13DOF_BME680_SLEEP_MODE );

    if ( bme->device_power_mode != C13DOF_BME680_SLEEP_MODE )
    {
        tmp_pow_mode = ( tmp_pow_mode & ~C13DOF_BME680_MODE_MSK ) | ( bme->device_power_mode & C13DOF_BME680_MODE_MSK );
        if ( rslt == C13DOF_BME680_DEVICE_OK )
        {
             rslt = bme680_set_regs( &reg_addr, &tmp_pow_mode, 1 );
        }
    }

    return rslt;
}

static int8_t bme680_set_gas_config ( bme680_t *bme )
{
    int8_t rslt = 0;
    uint8_t reg_addr[ 2 ] = { 0 };
    uint8_t reg_data[ 2 ] = { 0 };

    if ( bme->device_power_mode == C13DOF_BME680_FORCED_MODE )
    {
        reg_addr[ 0 ] = C13DOF_BME680_RES_HEAT0_ADDR;
        reg_data[ 0 ] = bme680_calc_heater_res( bme, bme->gas_sett.heatr_temp );
        reg_addr[ 1 ] = C13DOF_BME680_GAS_WAIT0_ADDR;
        reg_data[ 1 ] = bme680_calc_heater_dur( bme, bme->gas_sett.heatr_dur );
        bme->gas_sett.nb_conv = 0;
    }
    else
    {
        rslt = C13DOF_BME680_W_DEFINE_PWR_MODE;
    }
    if ( rslt == C13DOF_BME680_DEVICE_OK )
    {
        rslt = bme680_set_regs( reg_addr, reg_data, 2 );
    }

    return rslt;
}

static int16_t bme680_calc_temperature ( bme680_t *bme, uint32_t temp_adc )
{
    int32_t var1;
    int32_t var2;
    int32_t var3;
    int32_t calc_temp;

    var1 = ( ( int32_t )temp_adc >> 3 ) - ( ( int32_t ) bme->calib.par_t1 << 1 );
    var2 = ( var1 * ( int32_t ) bme->calib.par_t2 ) >> 11;
    var3 = ( ( var1 >> 1 ) * ( var1 >> 1 ) ) >> 12;
    var3 = ( ( var3 ) * ( ( int32_t ) bme->calib.par_t3 << 4 ) ) >> 14;
    bme->calib.t_fine = ( int32_t ) ( var2 + var3 );
    calc_temp = ( int16_t ) ( ( ( bme->calib.t_fine * 5 ) + 128 ) >> 8 );

    return calc_temp;
}

static uint32_t bme680_calc_humidity ( bme680_t *bme, uint16_t hum_adc )
{
    int32_t var1;
    int32_t var2;
    int32_t var3;
    int32_t var4;
    int32_t var5;
    int32_t var6;
    int32_t temp_scaled;
    int32_t calc_hum;

    temp_scaled = ( ( ( int32_t ) bme->calib.t_fine * 5 ) + 128 ) >> 8;
    var1 = ( int32_t ) ( hum_adc - ( ( int32_t ) ( ( int32_t ) bme->calib.par_h1 * 16 ) ) ) - ( ( ( temp_scaled * ( int32_t ) bme->calib.par_h3 ) / ( ( int32_t ) 100 ) ) >> 1 );
    var2 = ( ( int32_t ) bme->calib.par_h2
            * ( ( ( temp_scaled * ( int32_t ) bme->calib.par_h4 ) / ( ( int32_t ) 100 ) )
                    + ( ( ( temp_scaled * ( ( temp_scaled * ( int32_t ) bme->calib.par_h5 ) / ( ( int32_t ) 100 ) ) ) >> 6 )
                            / ( ( int32_t ) 100 ) ) + ( int32_t ) ( 1 << 14 ) ) ) >> 10;
    var3 = var1 * var2;
    var4 = ( int32_t ) bme->calib.par_h6 << 7;
    var4 = ( ( var4 ) + ( ( temp_scaled * ( int32_t ) bme->calib.par_h7 ) / ( ( int32_t ) 100 ) ) ) >> 4;
    var5 = ( ( var3 >> 14 ) * ( var3 >> 14 ) ) >> 10;
    var6 = ( var4 * var5 ) >> 1;
    calc_hum = ( ( ( var3 + var6 ) >> 10 ) * ( ( int32_t ) 1000 ) ) >> 12;

    if ( calc_hum > 100000 )
    {
        calc_hum = 100000;
    }
    else if ( calc_hum < 0 )
    {
        calc_hum = 0;
    }
    return ( uint32_t ) calc_hum;
}

static uint8_t bme680_calc_heater_res ( bme680_t *bme, uint16_t ble_temp )
{
    int32_t var1;
    int32_t var2;
    int32_t var3;
    int32_t var4;
    int32_t var5;
    int32_t heatr_res_x100;
    uint8_t heatr_res;

    if ( ble_temp > 400)
    {
        ble_temp = 400;
    }

    var1 = ( ( ( int32_t ) device_amb_temp * bme->calib.par_gh3 ) / 1000 ) * 256;
    var2 = ( bme->calib.par_gh1 + 784 ) * ( ( ( ( ( bme->calib.par_gh2 + 154009 ) * ble_temp * 5 ) / 100 ) + 3276800 ) / 10 );
    var3 = var1 + ( var2 / 2 );
    var4 = ( var3 / ( bme->calib.res_heat_range + 4 ) );
    var5 = ( 131 * bme->calib.res_heat_val ) + 65536;

    heatr_res_x100 = ( int32_t ) ( ( ( var4 / var5) - 250 ) * 34 );
    heatr_res = ( uint8_t ) ( ( heatr_res_x100 + 50) / 100 );

    return heatr_res;
}

static float bme680_calc_pressure ( bme680_t *bme, uint32_t pres_adc )
{
    float var1 = 0;
    float var2 = 0;
    float var3 = 0;
    float calc_pres = 0;

    var1 = ( float )( bme->calib.t_fine ) / 2.0f;
    var1 -= 64000.0f;

    var2 =( float )( bme->calib.par_p6 ) / 131072.0f;
    var2 *= var1 * var1;
    var2 += ( var1 * ( ( float )bme->calib.par_p5 ) * 2.0f );
    var2 = ( var2 / 4.0f ) + ( ( ( float )bme->calib.par_p4 ) * 65536.0f );

    var1 = ( ( ( ( ( float )bme->calib.par_p3 * var1 * var1 ) / 16384.0f) + ( ( float )bme->calib.par_p2 * var1 ) ) / 524288.0f );
    var1 = ( ( 1.0f + ( var1 / 32768.0f ) ) * ( ( float )bme->calib.par_p1 ) );
    calc_pres = ( 1048576.0f - ( ( float )pres_adc ) );

    if ( (int)var1 != 0)
    {
        calc_pres = ( ( ( calc_pres - ( var2 / 4096.0f ) ) * 6250.0f ) / var1 );
        var1 = ( ( ( float )bme->calib.par_p9 ) * calc_pres * calc_pres) / 2147483648.0f;
        var2 = calc_pres * ( ( ( float )bme->calib.par_p8 ) / 32768.0f );
        var3 = ( ( calc_pres / 256.0f ) * ( calc_pres / 256.0f ) * ( calc_pres / 256.0f ) * ( bme->calib.par_p10 / 131072.0f ) );
        calc_pres = ( calc_pres + ( var1 + var2 + var3 + ( ( float )bme->calib.par_p7 * 128.0f ) ) / 16.0f );
    }
    else
    {
        calc_pres = 0;
    }

    return calc_pres;
}

static float bme680_calc_gas_resistance ( bme680_t *bme, uint16_t gas_res_adc, uint8_t gas_range )
{
    float calc_gas_res;
    float var1 = 0;
    float var2 = 0;
    float var3 = 0;

    var1 = 5.0f * bme->calib.range_sw_err;
    var1 += 1340.0f;

    var2 = lookup_k1_range[ gas_range ] / 100.0f;
    var2 += 1.0f;
    var2 *= var1;

    var3 = lookup_k2_range[ gas_range ] / 100.0f;
    var3 += 1.0f ;

    calc_gas_res = 1.0f / ( float )( var3 * ( 0.000000125f ) * ( float )( 1 << gas_range ) * ( ( ( ( ( float )gas_res_adc ) - 512.0f )/var2 ) + 1.0f ) );

    return calc_gas_res;
}

static uint8_t bme680_calc_heater_dur ( bme680_t *bme, uint16_t dur )
{
    uint8_t factor = 0;
    uint8_t durval;

    if ( dur >= 0xfc0 )
    {
        durval = 0xff;
    }
    else
    {
        while ( dur > 0x3F )
        {
            dur = dur / 4;
            factor += 1;
        }
        durval = ( uint8_t ) ( dur + ( factor * 64 ) );
    }

    return durval;
}

static int8_t bme680_read_field_data ( bme680_t *bme, T_C13DOF_BME680_FIELD_DATA *d_data )
{
    int8_t rslt = 0;
    uint8_t buff[ C13DOF_BME680_FIELD_LENGTH ] = { 0 };
    uint8_t gas_range;
    uint32_t adc_temp;
    uint32_t adc_pres;
    uint16_t adc_hum;
    uint16_t adc_gas_res;
    uint8_t tries = 10;

    do
    {
        if ( rslt == C13DOF_BME680_DEVICE_OK)
        {
            rslt = bme680_get_regs( ( ( uint8_t ) ( C13DOF_BME680_FIELD0_ADDR ) ), buff, ( uint16_t ) C13DOF_BME680_FIELD_LENGTH );

            d_data->status = buff[ 0 ] & C13DOF_BME680_NEW_DATA_MSK;
            d_data->gas_index = buff[ 0 ] & C13DOF_BME680_GAS_INDEX_MSK;
            d_data->meas_index = buff[ 1 ];

            adc_pres = ( uint32_t ) ( ( ( uint32_t ) buff[ 2 ] * 4096 ) | ( ( uint32_t ) buff[ 3 ] * 16 )
                    | ( ( uint32_t ) buff[ 4 ] / 16 ) );
            adc_temp = ( uint32_t ) ( ( ( uint32_t ) buff[ 5 ] * 4096 ) | ( ( uint32_t ) buff[ 6 ] * 16 )
                    | ( ( uint32_t ) buff[ 7 ] / 16 ) );
            adc_hum = ( uint16_t ) ( ( ( uint32_t ) buff[ 8 ] * 256 ) | ( uint32_t ) buff[ 9 ] );
            adc_gas_res = ( uint16_t ) ( ( uint32_t ) buff[ 13 ] * 4 | ( ( ( uint32_t ) buff[ 14 ] ) / 64 ) );
            gas_range = buff[ 14 ] & C13DOF_BME680_GAS_RANGE_MSK;

            d_data->status |= buff[ 14 ] & C13DOF_BME680_GASM_VALID_MSK;
            d_data->status |= buff[ 14 ] & C13DOF_BME680_HEAT_STAB_MSK;

            if ( d_data->status & C13DOF_BME680_NEW_DATA_MSK )
            {
                d_data->temperature = bme680_calc_temperature( bme, adc_temp );
                d_data->pressure = bme680_calc_pressure( bme, adc_pres );
                d_data->humidity = bme680_calc_humidity( bme, adc_hum );
                d_data->gas_resistance = bme680_calc_gas_resistance( bme, adc_gas_res, gas_range );
                break;
            }

            CLICK_13DOF_DelayMs(10);
        }
        tries--;
    } while ( tries );

    if ( !tries )
    {
        rslt = C13DOF_BME680_W_NO_NEW_DATA;
    }
    return rslt;
}

static int8_t bme680_boundary_check ( bme680_t *bme, uint8_t *value, uint8_t min, uint8_t max )
{
    int8_t rslt = C13DOF_BME680_DEVICE_OK;

    if ( value != 0 )
    {
        if ( *value < min )
        {
            *value = min;
        }
        if ( *value > max )
        {
            *value = max;
        }
    }
    else
    {
        rslt = C13DOF_BME680_E_NULL_PTR;
    }

    return rslt;
}
