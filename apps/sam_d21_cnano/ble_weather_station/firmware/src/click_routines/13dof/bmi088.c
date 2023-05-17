/** \mainpage
*
****************************************************************************
* Copyright (C) 2019 MikroElektronika - www.mikroe.com
*
* File : bmi088.c
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
  bmi088 source file

  Company
    Microchip Technology Inc.

  File Name
    bmi088.c

  Summary
    This file contains definitions of all the functions which gives
    functionality to bmi088 sensor

  Description
    This file contains definitions of functions like getting accel data, gyroscopic
    data which should be displayed on the terminal
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
#include "13dof.h"
#include "bmi088.h"
#include "../click_interface.h"
/* This section lists the other files that are included in this file.
 */
static void bmi088_reset_delay ( void );
/* TODO:  Include other files here if needed. */

void bmi088_init( bmi088_t *bmi )
{
    bmi->bmi088Gyro_slave_address = C13DOF_BMI088_GYRO_SLAVE_ADDR;
    bmi->bmi088Accel_slave_address = C13DOF_BMI088_ACCEL_SLAVE_ADDR;
}

void bmi088_gyro_hal_write ( bmi088_t *bmi,  uint8_t reg_address, uint8_t write_data )
{
    uint8_t w_buffer[ 2 ];

    w_buffer[ 0 ]= reg_address;
    w_buffer[ 1 ]= write_data;

    CLICK_13DOF_I2C_Write( C13DOF_BMI088_GYRO_SLAVE_ADDR, w_buffer, 2 );
    while(CLICK_13DOF_I2C_IsBusy() == true);
}

uint8_t bmi088_gyro_hal_read ( uint8_t reg_address )
{
    uint8_t r_buffer[ 1 ];

    CLICK_13DOF_I2C_WriteRead( C13DOF_BMI088_GYRO_SLAVE_ADDR, &reg_address, 1, r_buffer, 1 );
    while(CLICK_13DOF_I2C_IsBusy() == true);

    return r_buffer[ 0 ];
}

int16_t c13dof_bmi088_get_gyro_axis ( uint8_t adr_reg_LSB, uint8_t adr_reg_MSB )
{
    uint16_t result;
    uint8_t temp[ 2 ];

    temp[ 0 ] = bmi088_gyro_hal_read( adr_reg_MSB );
    temp[ 1 ] = bmi088_gyro_hal_read( adr_reg_LSB );

    result = temp[ 0 ];
    result <<= 8;
    result |= temp[ 1 ];

    return result;
}

void c13dof_bmi088_read_gyro ( int16_t *gyro_x, int16_t *gyro_y, int16_t *gyro_z )
{
    *gyro_x = c13dof_bmi088_get_gyro_axis( C13DOF_BMI088_GYRO_X_LSB_REG, C13DOF_BMI088_GYRO_X_MSB_REG );
    *gyro_y = c13dof_bmi088_get_gyro_axis( C13DOF_BMI088_GYRO_Y_LSB_REG, C13DOF_BMI088_GYRO_Y_MSB_REG );
    *gyro_z = c13dof_bmi088_get_gyro_axis( C13DOF_BMI088_GYRO_Z_LSB_REG, C13DOF_BMI088_GYRO_Z_MSB_REG );
}

void bmi088_accel_hal_write ( uint8_t reg_address, uint8_t write_data )
{
    uint8_t w_buffer[ 2 ];

    w_buffer[ 0 ]= reg_address;
    w_buffer[ 1 ]= write_data;

    CLICK_13DOF_I2C_Write( C13DOF_BMI088_ACCEL_SLAVE_ADDR, w_buffer, 2 );
    while(CLICK_13DOF_I2C_IsBusy() == true);
}

uint8_t bmi088_accel_hal_read ( uint8_t reg_address )
{
    uint8_t r_buffer[ 1 ];

    CLICK_13DOF_I2C_WriteRead( C13DOF_BMI088_ACCEL_SLAVE_ADDR, &reg_address, 1, r_buffer,  1 );
    while(CLICK_13DOF_I2C_IsBusy() == true);
    return r_buffer[ 0 ];
}

void c13dof_bmi088_soft_reset_accel ( )
{
    bmi088_accel_hal_write( C13DOF_BMI088_ACCEL_SOFTRESET_REG, 0xB6 );
    bmi088_reset_delay ();
}

void c13dof_bmi088_set_accel_mode ( uint8_t active_mode )
{
    if ( active_mode )
    {
        bmi088_accel_hal_write( C13DOF_BMI088_ACCEL_PWR_CONF_REG, 0x00 );
    }
    else
    {
        bmi088_accel_hal_write( C13DOF_BMI088_ACCEL_PWR_CONF_REG, 0x03 );
    }

}

C13DOF_BMI088_RETVAL_T c13dof_bmi088_enable_accel ( )
{
    uint8_t tmp;

    bmi088_accel_hal_write( C13DOF_BMI088_ACCEL_PWR_CTRL_REG, 0x04 );

    tmp = bmi088_accel_hal_read( C13DOF_BMI088_ACCEL_PWR_CTRL_REG );

    if ( tmp == 0x04 )
    {
        return C13DOF_BMI088_OK;
    }
    else
    {
       return C13DOF_BMI088_ERROR;
    }
}

int16_t c13dof_bmi088_get_accel_axis ( uint8_t adr_reg_LSB, uint8_t adr_reg_MSB )
{
    uint16_t result;
    uint8_t temp[ 2 ];

    temp[ 0 ] = bmi088_accel_hal_read( adr_reg_MSB );
    temp[ 1 ] = bmi088_accel_hal_read( adr_reg_LSB );

    result = temp[ 0 ];
    result <<= 8;
    result |= temp[ 1 ];

    return result;
}

void c13dof_bmi088_read_accel ( int16_t *accel_x, int16_t *accel_y, int16_t *accel_z )
{
    *accel_x = c13dof_bmi088_get_accel_axis( C13DOF_BMI088_ACCEL_X_LSB_REG, C13DOF_BMI088_ACCEL_X_MSB_REG );
    *accel_y = c13dof_bmi088_get_accel_axis( C13DOF_BMI088_ACCEL_Y_LSB_REG, C13DOF_BMI088_ACCEL_Y_MSB_REG );
    *accel_z = c13dof_bmi088_get_accel_axis( C13DOF_BMI088_ACCEL_Y_LSB_REG, C13DOF_BMI088_ACCEL_Z_MSB_REG );
}

void bmi088_reset_delay( )
{
    CLICK_13DOF_DelayMs(10);
}

/* *****************************************************************************
 End of File
 */
