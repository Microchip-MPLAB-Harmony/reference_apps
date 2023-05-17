/** \mainpage
*
****************************************************************************
* Copyright (C) 2019 MikroElektronika - www.mikroe.com
*
* File : bmm150.c
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
  bmm150 source file

  Company
    Microchip Technology Inc.

  File Name
    bmm150.c

  Summary
    This file contains definitions of all the functions which gives
    functionality to bmm150 sensor

  Description
    This file contains definitions of functions like getting geomagnetic data
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
#include "13dof.h"
#include "bmm150.h"
#include "../click_interface.h"

/* This section lists the other files that are included in this file.
 */
static void bmm150_reset_delay ( void );
/* TODO:  Include other files here if needed. */
void bmm150_init(  bmm150_t *bmm )
{
    bmm->bmm150_slave_address = C13DOF_BMM150_DEVICE_SLAVE_ADDR;
}

void c13dof_bmm150_power_on_reset ( )
{
    bmm150_hal_write( C13DOF_BMM150_POWER_AND_RESET_CON_REG, C13DOF_BMM150_SUSPEND_MODE_SPI4_EN );
    bmm150_hal_write( C13DOF_BMM150_POWER_AND_RESET_CON_REG, C13DOF_BMM150_SLEEP_MODE );
    bmm150_reset_delay ( );
    bmm150_hal_write( C13DOF_BMM150_DATARATE_AND_OPMODE_CON_REG, C13DOF_BMM150_NORMAL_OPMODE_DR_10HZ );
}

void c13dof_bmm150_read_geo_mag_data ( int16_t *mag_x, int16_t *mag_y, int16_t *mag_z, uint16_t *res_hall )
{
    
    uint8_t ready_check;
    ready_check = c13dof_bmm150_check_ready( );
    while ( ready_check != C13DOF_BMM150_DATA_READY )
    {
        ready_check = c13dof_bmm150_check_ready( );
    }
    uint8_t r_buffer[ 8 ];
    uint16_t temp;

    bmm150_hal_read( r_buffer, C13DOF_BMM150_DATAX_LSB_REG, 8 );

    temp = r_buffer[ 1 ];
    temp <<= 5;
    temp |= r_buffer[ 0 ] >> 3;

    *mag_x = temp;
    if ( *mag_x & 0x1000 )
    {
        *mag_x |= 0xE000;
    }

    temp = r_buffer[ 3 ];
    temp <<= 5;
    temp |= r_buffer[ 2 ] >> 3;

    *mag_y = temp;
    if ( *mag_y & 0x1000 )
    {
        *mag_y |= 0xE000;
    }

    temp = r_buffer[ 5 ];
    temp <<= 7;
    temp |= r_buffer[ 4 ] >> 1;

    *mag_z = temp;
    if ( *mag_z & 0x4000 )
    {
        *mag_z |= 0x8000;
    }

    temp = r_buffer[ 7 ];
    temp <<= 6;
    temp |= r_buffer[ 6 ] >> 2;
    *res_hall = temp;
}

C13DOF_BMM150_RETVAL_T c13dof_bmm150_check_ready ( )
{
    uint8_t tmp;

    bmm150_hal_read( &tmp, C13DOF_BMM150_RHALL_LSB_REG, 1 );

    tmp &= C13DOF_BMM150_DATA_READY;

    return tmp;
}

C13DOF_BMM150_RETVAL_T bmm150_hal_read ( uint8_t *data_out, uint8_t reg_address, uint8_t n_bytes )
{
    uint8_t w_buffer[ 20 ];

    if ( ( reg_address < 0x40 ) || ( reg_address > 0x52 ) )
    {
        return C13DOF_BMM150_ADDR_ERR;
    }
    if ( n_bytes > 19 )
    {
        return C13DOF_BMM150_NBYTES_ERR;
    }

    w_buffer[ 0 ] = reg_address;

    CLICK_13DOF_I2C_WriteRead( C13DOF_BMM150_DEVICE_SLAVE_ADDR, w_buffer, 1, data_out, n_bytes );

    while(CLICK_13DOF_I2C_IsBusy() == true);

    return C13DOF_BMM150_OK;
}

C13DOF_BMM150_RETVAL_T bmm150_hal_write ( uint8_t reg_address, uint8_t write_data )
{
    uint8_t w_buffer[ 2 ];

    if ( ( reg_address < 0x40 ) || ( reg_address > 0x52 ) )
    {
        return C13DOF_BMM150_ADDR_ERR;
    }

    w_buffer[ 0 ] = reg_address;
    w_buffer[ 1 ] = write_data;

    CLICK_13DOF_I2C_Write( C13DOF_BMM150_DEVICE_SLAVE_ADDR, w_buffer, 2 );

    while(CLICK_13DOF_I2C_IsBusy() == true);

    return C13DOF_BMM150_OK;
}

void bmm150_reset_delay( )
{
    CLICK_13DOF_DelayMs(10);
}
/* *****************************************************************************
 End of File
 */
