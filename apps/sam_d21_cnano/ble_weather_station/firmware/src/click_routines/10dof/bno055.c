/*
*
****************************************************************************
* Copyright (C) 2013 - 2014 Bosch Sensortec GmbH
*
* File : bno055.c
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
/*********************************************************/
/*              INCLUDES    */
/*******************************************************/
#include "bno055.h"
#include "click_routines/click_interface.h"

static void bno_hal_init()
{
    CLICK_10DOF_TimerStart();
}

static void bno_delay_ms( uint32_t delay_time )
{
    CLICK_10DOF_DelayMs(delay_time);
}

static int8_t bno_hal_read( uint8_t address, uint8_t reg_address, uint8_t *data_out,
                  uint8_t data_size )
{    
     CLICK_10DOF_I2C_WriteRead(address, &reg_address, 1,  data_out, data_size);
     
     while(CLICK_10DOF_I2C_IsBusy() == true); 
     
     return 0;
}

static int8_t bno_hal_write( uint8_t address, uint8_t reg_address, uint8_t *data_in,
                   uint8_t data_size )
{
    uint8_t temp_buff[ MAX_BUFFER_SIZE ];
    uint8_t *temp_ptr = data_in;

    temp_buff[0] = reg_address;
    memcpy( &temp_buff[1], temp_ptr, data_size );
    
    CLICK_10DOF_I2C_Write(address,temp_buff,data_size+1);
    
    while(CLICK_10DOF_I2C_IsBusy() == true);

    return 0;
}

static struct bno055_t *p_bno055;

BNO055_RETURN_FUNCTION_TYPE bno055_init( struct bno055_t *bno055 )
{
    /* Variable used to return value of
    communication routine*/
    BNO055_RETURN_FUNCTION_TYPE com_rslt = ERROR;
    u8 v_data_u8 = BNO055_ZERO_U8X;
    u8 v_page_zero_u8 = PAGE_ZERO;
    /* Array holding the Software revision id
    */
    u8 a_SW_ID_u8[ARRAY_SIZE_TWO] =
    {
        BNO055_ZERO_U8X, BNO055_ZERO_U8X
    };
    /* stuct parameters are assign to bno055*/
    p_bno055 = bno055;

    bno055->bus_read = bno_hal_read;
    bno055->bus_write = bno_hal_write;
    bno055->delay_msec = bno_delay_ms;
    bno_hal_init();
    
    /* Write the default page as zero*/
    com_rslt = p_bno055->BNO055_BUS_WRITE_FUNC
               ( p_bno055->dev_addr,
                 BNO055_PAGE_ID__REG, &v_page_zero_u8, BNO055_ONE_U8X );
    /* Read the chip id of the sensor from page
    zero 0x00 register*/
    com_rslt += p_bno055->BNO055_BUS_READ_FUNC
                ( p_bno055->dev_addr,
                  BNO055_CHIP_ID__REG, &v_data_u8, BNO055_ONE_U8X );
    p_bno055->chip_id = v_data_u8;
    /* Read the accel revision id from page
    zero 0x01 register*/
    com_rslt += p_bno055->BNO055_BUS_READ_FUNC
                ( p_bno055->dev_addr,
                  BNO055_ACCEL_REV_ID__REG, &v_data_u8, BNO055_ONE_U8X );
    p_bno055->accel_rev_id = v_data_u8;
    /* Read the mag revision id from page
    zero 0x02 register*/
    com_rslt += p_bno055->BNO055_BUS_READ_FUNC
                ( p_bno055->dev_addr,
                  BNO055_MAG_REV_ID__REG, &v_data_u8, BNO055_ONE_U8X );
    p_bno055->mag_rev_id = v_data_u8;
    /* Read the gyro revision id from page
    zero 0x02 register*/
    com_rslt += p_bno055->BNO055_BUS_READ_FUNC
                ( p_bno055->dev_addr,
                  BNO055_GYRO_REV_ID__REG, &v_data_u8, BNO055_ONE_U8X );
    p_bno055->gyro_rev_id = v_data_u8;
    /* Read the boot loader revision from page
    zero 0x06 register*/
    com_rslt += p_bno055->BNO055_BUS_READ_FUNC
                ( p_bno055->dev_addr,
                  BNO055_BL_REV_ID__REG, &v_data_u8, BNO055_ONE_U8X );
    p_bno055->bl_rev_id = v_data_u8;
    /* Read the software revision id from page
    zero 0x04 and 0x05 register( 2 bytes of data)*/
    com_rslt += p_bno055->BNO055_BUS_READ_FUNC( p_bno055->dev_addr,
                BNO055_SW_REV_ID_LSB__REG,
                a_SW_ID_u8, BNO055_TWO_U8X );
    a_SW_ID_u8[INDEX_ZERO] = BNO055_GET_BITSLICE(
                                 a_SW_ID_u8[INDEX_ZERO],
                                 BNO055_SW_REV_ID_LSB );
    p_bno055->sw_rev_id = ( u16 )
                          ( ( ( ( u32 )( ( u8 )a_SW_ID_u8[INDEX_ONE] ) ) <<
                              BNO055_SHIFT_8_POSITION ) | ( a_SW_ID_u8[INDEX_ZERO] ) );
    /* Read the page id from the register 0x07*/
    com_rslt += p_bno055->BNO055_BUS_READ_FUNC
                ( p_bno055->dev_addr,
                  BNO055_PAGE_ID__REG, &v_data_u8, BNO055_ONE_U8X );
    p_bno055->page_id = v_data_u8;

    return com_rslt;
}

BNO055_RETURN_FUNCTION_TYPE bno055_write_register( u8 v_addr_u8,
        u8 *p_data_u8, u8 v_len_u8 )
{
    /* Variable used to return value of
    communication routine*/
    BNO055_RETURN_FUNCTION_TYPE com_rslt = ERROR;
    /* Check the struct p_bno055 is empty */
    if (p_bno055 == NULL )
        return E_NULL_PTR;
    else
    {
        /* Write the values of respective given register */
        com_rslt = p_bno055->BNO055_BUS_WRITE_FUNC
                   ( p_bno055->dev_addr, v_addr_u8, p_data_u8, v_len_u8 );
    }
    return com_rslt;
}

BNO055_RETURN_FUNCTION_TYPE bno055_write_page_id( u8 v_page_id_u8 )
{
    /* Variable used to return value of
    communication routine*/
    BNO055_RETURN_FUNCTION_TYPE com_rslt = ERROR;
    u8 v_data_u8r = BNO055_ZERO_U8X;
    /* Check the struct p_bno055 is empty */
    if ( p_bno055 == NULL )
        return E_NULL_PTR;
    else
    {
        /* Read the current page*/
        com_rslt = p_bno055->BNO055_BUS_READ_FUNC
                   ( p_bno055->dev_addr,
                     BNO055_PAGE_ID__REG, &v_data_u8r, BNO055_ONE_U8X );
        /* Check condition for communication success*/
        if ( com_rslt == SUCCESS )
        {
            v_data_u8r = BNO055_SET_BITSLICE( v_data_u8r,
                                              BNO055_PAGE_ID, v_page_id_u8 );
            /* Write the page id*/
            com_rslt += p_bno055->BNO055_BUS_WRITE_FUNC
                        ( p_bno055->dev_addr,
                          BNO055_PAGE_ID__REG,
                          &v_data_u8r, BNO055_ONE_U8X );
            if ( com_rslt == SUCCESS )
                p_bno055->page_id = v_page_id_u8;
        }
        else
            com_rslt = ERROR;
    }
    return com_rslt;
}
/*!
 *  @brief This API reads acceleration data xyz values
 *  from register 0x08 to 0x0D it is a six byte data
 *
 *
 *  @param accel : The value of accel xyz data
 *
 *  Parameter |    result
 *  --------- | -----------------
 *   x        | The accel x data
 *   y        | The accel y data
 *   z        | The accel z data
 *
 *
 *
 *  @return results of bus communication function
 *  @retval 0 -> Success
 *  @retval 1 -> Error
 *
 */
BNO055_RETURN_FUNCTION_TYPE get_bno55_accel_xyz(
    struct bno055_accel_t *accel )
{
    /* Variable used to return value of
    communication routine*/
    BNO055_RETURN_FUNCTION_TYPE com_rslt = ERROR;
    /* Array holding the accel xyz value
    v_data_u8[INDEX_ZERO] - x->LSB
    v_data_u8[INDEX_ONE] - x->MSB
    v_data_u8[2] - y->MSB
    v_data_u8[3] - y->MSB
    v_data_u8[4] - z->MSB
    v_data_u8[5] - z->MSB
    */
    u8 v_data_u8[ARRAY_SIZE_SIX] =
    {
        BNO055_ZERO_U8X, BNO055_ZERO_U8X,
        BNO055_ZERO_U8X, BNO055_ZERO_U8X,
        BNO055_ZERO_U8X, BNO055_ZERO_U8X
    };
    s8 v_stat_s8 = ERROR;
    /* Check the struct p_bno055 is empty */
    if ( p_bno055 == NULL )
        return E_NULL_PTR;
    else
    {
        /*condition check for page, chip id is
        available in the page zero*/
        if ( p_bno055->page_id != PAGE_ZERO )
            /* Write the page zero*/
            v_stat_s8 = bno055_write_page_id( PAGE_ZERO );
        if ( ( v_stat_s8 == SUCCESS ) ||
                ( p_bno055->page_id == PAGE_ZERO ) )
        {
            com_rslt = p_bno055->BNO055_BUS_READ_FUNC
                       ( p_bno055->dev_addr,
                         BNO055_ACCEL_DATA_X_LSB_VALUEX__REG,
                         v_data_u8, BNO055_SIX_U8X );
            /* Data X*/
            v_data_u8[INDEX_ZERO] =
                BNO055_GET_BITSLICE( v_data_u8[INDEX_ZERO],
                                     BNO055_ACCEL_DATA_X_LSB_VALUEX );
            v_data_u8[INDEX_ONE] =
                BNO055_GET_BITSLICE( v_data_u8[INDEX_ONE],
                                     BNO055_ACCEL_DATA_X_MSB_VALUEX );
            accel->x = ( s16 )( ( ( ( s32 )
                                    ( ( s8 )v_data_u8[INDEX_ONE] ) ) <<
                                  BNO055_SHIFT_8_POSITION )
                                | ( v_data_u8[INDEX_ZERO] ) );
            /* Data Y*/
            v_data_u8[INDEX_TWO] =
                BNO055_GET_BITSLICE( v_data_u8[INDEX_TWO],
                                     BNO055_ACCEL_DATA_Y_LSB_VALUEY );
            v_data_u8[INDEX_THREE] =
                BNO055_GET_BITSLICE( v_data_u8[INDEX_THREE],
                                     BNO055_ACCEL_DATA_Y_MSB_VALUEY );
            accel->y = ( s16 )( ( ( ( s32 )
                                    ( ( s8 )v_data_u8[INDEX_THREE] ) ) <<
                                  BNO055_SHIFT_8_POSITION )
                                | ( v_data_u8[INDEX_TWO] ) );
            /* Data Z*/
            v_data_u8[INDEX_FOUR] =
                BNO055_GET_BITSLICE( v_data_u8[INDEX_FOUR],
                                     BNO055_ACCEL_DATA_Z_LSB_VALUEZ );
            v_data_u8[INDEX_FIVE] =
                BNO055_GET_BITSLICE( v_data_u8[INDEX_FIVE],
                                     BNO055_ACCEL_DATA_Z_MSB_VALUEZ );
            accel->z = ( s16 )( ( ( ( s32 )
                                    ( ( s8 )v_data_u8[INDEX_FIVE] ) ) <<
                                  BNO055_SHIFT_8_POSITION )
                                | ( v_data_u8[INDEX_FOUR] ) );
        }
        else
            com_rslt = ERROR;
    }
    return com_rslt;
}
/*!
 *  @brief This API reads gyro data xyz values
 *  from register 0x14 to 0x19 it is a six byte data
 *
 *
 *  @param gyro : The value of gyro xyz data's
 *
 *  Parameter |    result
 *  --------- | -----------------
 *   x        | The gyro x data
 *   y        | The gyro y data
 *   z        | The gyro z data
 *
 *
 *
 *  @return results of bus communication function
 *  @retval 0 -> Success
 *  @retval 1 -> Error
 *
 */
BNO055_RETURN_FUNCTION_TYPE get_bno55_gyro_xyz( struct bno055_gyro_t *gyro )
{
    /* Variable used to return value of
    communication routine*/
    BNO055_RETURN_FUNCTION_TYPE com_rslt = ERROR;
    /* Array holding the accel xyz value
    v_data_u8[INDEX_ZERO] - x->LSB
    v_data_u8[INDEX_ONE] - x->MSB
    v_data_u8[INDEX_TWO] - y->MSB
    v_data_u8[INDEX_THREE] - y->MSB
    v_data_u8[INDEX_FOUR] - z->MSB
    v_data_u8[INDEX_FIVE] - z->MSB
    */
    u8 v_data_u8[ARRAY_SIZE_SIX] =
    {
        BNO055_ZERO_U8X, BNO055_ZERO_U8X,
        BNO055_ZERO_U8X, BNO055_ZERO_U8X,
        BNO055_ZERO_U8X, BNO055_ZERO_U8X
    };
    s8 v_stat_s8 = ERROR;
    /* Check the struct p_bno055 is empty */
    if ( p_bno055 == NULL )
        return E_NULL_PTR;
    else
    {
        /*condition check for page, chip id is
        available in the page zero*/
        if ( p_bno055->page_id != PAGE_ZERO )
            /* Write the page zero*/
            v_stat_s8 = bno055_write_page_id( PAGE_ZERO );
        if ( ( v_stat_s8 == SUCCESS ) ||
                ( p_bno055->page_id == PAGE_ZERO ) )
        {
            /* Read the six bytes data of gyro xyz*/
            com_rslt = p_bno055->BNO055_BUS_READ_FUNC
                       ( p_bno055->dev_addr,
                         BNO055_GYRO_DATA_X_LSB_VALUEX__REG,
                         v_data_u8, BNO055_SIX_U8X );
            /* Data x*/
            v_data_u8[INDEX_ZERO] =
                BNO055_GET_BITSLICE( v_data_u8[INDEX_ZERO],
                                     BNO055_GYRO_DATA_X_LSB_VALUEX );
            v_data_u8[INDEX_ONE] =
                BNO055_GET_BITSLICE( v_data_u8[INDEX_ONE],
                                     BNO055_GYRO_DATA_X_MSB_VALUEX );
            gyro->x = ( s16 )( ( ( ( s32 )
                                   ( ( s8 )v_data_u8[INDEX_ONE] ) ) <<
                                 BNO055_SHIFT_8_POSITION ) |
                               ( v_data_u8[INDEX_ZERO] ) );
            /* Data y*/
            v_data_u8[INDEX_TWO] =
                BNO055_GET_BITSLICE( v_data_u8[INDEX_TWO],
                                     BNO055_GYRO_DATA_Y_LSB_VALUEY );
            v_data_u8[INDEX_THREE] =
                BNO055_GET_BITSLICE( v_data_u8[INDEX_THREE],
                                     BNO055_GYRO_DATA_Y_MSB_VALUEY );
            gyro->y = ( s16 )( ( ( ( s32 )
                                   ( ( s8 )v_data_u8[INDEX_THREE] ) ) <<
                                 BNO055_SHIFT_8_POSITION )
                               | ( v_data_u8[INDEX_TWO] ) );
            /* Data z*/
            v_data_u8[INDEX_FOUR] =
                BNO055_GET_BITSLICE( v_data_u8[INDEX_FOUR],
                                     BNO055_GYRO_DATA_Z_LSB_VALUEZ );
            v_data_u8[INDEX_FIVE] =
                BNO055_GET_BITSLICE( v_data_u8[INDEX_FIVE],
                                     BNO055_GYRO_DATA_Z_MSB_VALUEZ );
            gyro->z = ( s16 )( ( ( ( s32 )
                                   ( ( s8 )v_data_u8[INDEX_FIVE] ) ) <<
                                 BNO055_SHIFT_8_POSITION )
                               | ( v_data_u8[INDEX_FOUR] ) );
        }
        else
            com_rslt = ERROR;
    }
    return com_rslt;
}
/*!
 *  @brief This API reads Quaternion data wxyz values
 *  from register 0x20 to 0x27 it is a six byte data
 *
 *
 *  @param quaternion : The value of quaternion wxyz data's
 *
 *  Parameter |    result
 *  --------- | -----------------
 *   w        | The quaternion w data
 *   x        | The quaternion x data
 *   y        | The quaternion y data
 *   z        | The quaternion z data
 *
 *
 *
 *  @return results of bus communication function
 *  @retval 0 -> Success
 *  @retval 1 -> Error
 *
 */
BNO055_RETURN_FUNCTION_TYPE get_bn055_quaternion_wxyz(
    struct bno055_quaternion_t *quaternion )
{
    /* Variable used to return value of
    communication routine*/
    BNO055_RETURN_FUNCTION_TYPE com_rslt = ERROR;
    /* Array holding the quaternion wxyz value
    v_data_u8[INDEX_ZERO] - w->LSB
    v_data_u8[INDEX_ONE] - w->MSB
    v_data_u8[INDEX_TWO] - x->LSB
    v_data_u8[INDEX_THREE] - x->MSB
    v_data_u8[INDEX_FOUR] - y->MSB
    v_data_u8[INDEX_FIVE] - y->MSB
    v_data_u8[6] - z->MSB
    v_data_u8[7] - z->MSB
    */
    u8 v_data_u8[ARRAY_SIZE_EIGHT] =
    {
        BNO055_ZERO_U8X, BNO055_ZERO_U8X,
        BNO055_ZERO_U8X, BNO055_ZERO_U8X,
        BNO055_ZERO_U8X, BNO055_ZERO_U8X,
        BNO055_ZERO_U8X, BNO055_ZERO_U8X
    };
    s8 v_stat_s8 = ERROR;
    /* Check the struct p_bno055 is empty */
    if ( p_bno055 == NULL )
        return E_NULL_PTR;
    else
    {
        /*condition check for page, chip id is
        available in the page zero*/
        if ( p_bno055->page_id != PAGE_ZERO )
            /* Write the page zero*/
            v_stat_s8 = bno055_write_page_id( PAGE_ZERO );
        if ( ( v_stat_s8 == SUCCESS ) ||
                ( p_bno055->page_id == PAGE_ZERO ) )
        {
            /* Read the eight byte value
            of quaternion wxyz data*/
            com_rslt = p_bno055->BNO055_BUS_READ_FUNC
                       ( p_bno055->dev_addr,
                         BNO055_QUATERNION_DATA_W_LSB_VALUEW__REG,
                         v_data_u8, BNO055_EIGHT_U8X );
            /* Data W*/
            v_data_u8[INDEX_ZERO] =
                BNO055_GET_BITSLICE( v_data_u8[INDEX_ZERO],
                                     BNO055_QUATERNION_DATA_W_LSB_VALUEW );
            v_data_u8[INDEX_ONE] =
                BNO055_GET_BITSLICE( v_data_u8[INDEX_ONE],
                                     BNO055_QUATERNION_DATA_W_MSB_VALUEW );
            quaternion->w = ( s16 )( ( ( ( s32 )
                                         ( ( s8 )v_data_u8[INDEX_ONE] ) ) <<
                                       BNO055_SHIFT_8_POSITION ) |
                                     ( v_data_u8[INDEX_ZERO] ) );
            /* Data X*/
            v_data_u8[INDEX_TWO] =
                BNO055_GET_BITSLICE( v_data_u8[INDEX_TWO],
                                     BNO055_QUATERNION_DATA_X_LSB_VALUEX );
            v_data_u8[INDEX_THREE] =
                BNO055_GET_BITSLICE( v_data_u8[INDEX_THREE],
                                     BNO055_QUATERNION_DATA_X_MSB_VALUEX );
            quaternion->x = ( s16 )( ( ( ( s32 )
                                         ( ( s8 )v_data_u8[INDEX_THREE] ) ) <<
                                       BNO055_SHIFT_8_POSITION ) |
                                     ( v_data_u8[INDEX_TWO] ) );
            /* Data Y*/
            v_data_u8[INDEX_FOUR] =
                BNO055_GET_BITSLICE( v_data_u8[INDEX_FOUR],
                                     BNO055_QUATERNION_DATA_Y_LSB_VALUEY );
            v_data_u8[INDEX_FIVE] =
                BNO055_GET_BITSLICE( v_data_u8[INDEX_FIVE],
                                     BNO055_QUATERNION_DATA_Y_MSB_VALUEY );
            quaternion->y = ( s16 )( ( ( ( s32 )
                                         ( ( s8 )v_data_u8[INDEX_FIVE] ) ) <<
                                       BNO055_SHIFT_8_POSITION ) |
                                     ( v_data_u8[INDEX_FOUR] ) );
            /* Data Z*/
            v_data_u8[INDEX_SIX] =
                BNO055_GET_BITSLICE( v_data_u8[INDEX_SIX],
                                     BNO055_QUATERNION_DATA_Z_LSB_VALUEZ );
            v_data_u8[INDEX_SEVEN] =
                BNO055_GET_BITSLICE( v_data_u8[INDEX_SEVEN],
                                     BNO055_QUATERNION_DATA_Z_MSB_VALUEZ );
            quaternion->z = ( s16 )( ( ( ( s32 )
                                         ( ( s8 )v_data_u8[INDEX_SEVEN] ) ) <<
                                       BNO055_SHIFT_8_POSITION ) |
                                     ( v_data_u8[INDEX_SIX] ) );
        }
        else
            com_rslt = ERROR;
    }
    return com_rslt;
}
BNO055_RETURN_FUNCTION_TYPE bno055_get_operation_mode(
    u8 *v_operation_mode_u8 )
{
    /* Variable used to return value of
    communication routine*/
    BNO055_RETURN_FUNCTION_TYPE com_rslt = ERROR;
    u8 v_data_u8r = BNO055_ZERO_U8X;
    s8 v_stat_s8 = ERROR;
    /* Check the struct p_bno055 is empty */
    if ( p_bno055 == NULL )
        return E_NULL_PTR;
    else
    {
        /*condition check for page, operation mode is
        available in the page zero*/
        if ( p_bno055->page_id != PAGE_ZERO )
            /* Write the page zero*/
            v_stat_s8 = bno055_write_page_id( PAGE_ZERO );
        if ( ( v_stat_s8 == SUCCESS ) ||
                ( p_bno055->page_id == PAGE_ZERO ) )
        {
            /* Read the value of operation mode*/
            com_rslt = p_bno055->BNO055_BUS_READ_FUNC
                       ( p_bno055->dev_addr,
                         BNO055_OPERATION_MODE__REG,
                         &v_data_u8r, BNO055_ONE_U8X );
            *v_operation_mode_u8 =
                BNO055_GET_BITSLICE( v_data_u8r,
                                     BNO055_OPERATION_MODE );
        }
        else
            com_rslt = ERROR;
    }
    return com_rslt;
}
/*! @brief This API used to write the operation mode
 *  from register from 0x3D bit 0 to 3
 *
 *  @param v_operation_mode_u8 : The value of operation mode
 *
 *  v_operation_mode_u8  |      result    | comments
 * ----------|----------------------------|----------------------------
 *  0x00     | OPERATION_MODE_CONFIG      | Configuration mode
 *  0x01     | OPERATION_MODE_ACCONLY     | Reads accel data alone
 *  0x02     | OPERATION_MODE_MAGONLY     | Reads mag data alone
 *  0x03     | OPERATION_MODE_GYRONLY     | Reads gyro data alone
 *  0x04     | OPERATION_MODE_ACCMAG      | Reads accel and mag data
 *  0x05     | OPERATION_MODE_ACCGYRO     | Reads accel and gyro data
 *  0x06     | OPERATION_MODE_MAGGYRO     | Reads accel and mag data
 *  0x07     | OPERATION_MODE_ANY_MOTION  | Reads accel mag and gyro data
 *  0x08     | OPERATION_MODE_IMUPLUS     | Inertial measurement unit
 *   -       |       -                    | Reads accel,gyro and fusion data
 *  0x09     | OPERATION_MODE_COMPASS     | Reads accel, mag data
 *   -       |       -                    | and fusion data
 *  0x0A     | OPERATION_MODE_M4G         | Reads accel, mag data
 *    -      |       -                    | and fusion data
 *  0x0B     | OPERATION_MODE_NDOF_FMC_OFF| Nine degrees of freedom with
 *   -       |       -                    | fast magnetic calibration
 *   -       |       -                    | Reads accel,mag, gyro
 *   -       |       -                    | and fusion data
 *  0x0C     | OPERATION_MODE_NDOF        | Nine degrees of freedom
 *   -       |       -                    | Reads accel,mag, gyro
 *   -       |       -                    | and fusion data
 *
 *  @return results of bus communication function
 *  @retval 0 -> Success
 *  @retval 1 -> Error
 *
 *  @note In the config mode, all sensor and fusion data
 *  becomes zero and it is mainly derived
 *  to configure the various settings of the BNO
 *
 */
BNO055_RETURN_FUNCTION_TYPE bno055_set_operation_mode( u8
        v_operation_mode_u8 )
{
    BNO055_RETURN_FUNCTION_TYPE com_rslt = ERROR;
    u8 v_data_u8r = BNO055_ZERO_U8X;
    u8 v_prev_opmode_u8 = OPERATION_MODE_CONFIG;
    s8 v_stat_s8 = ERROR;
    /* Check the struct p_bno055 is empty */
    if ( p_bno055 == NULL )
        return E_NULL_PTR;
    else
    {
        /* The write operation effective only if the operation
        mode is in config mode, this part of code is checking the
        current operation mode and set the config mode */
        v_stat_s8 = bno055_get_operation_mode( &v_prev_opmode_u8 );
        if ( v_stat_s8 == SUCCESS )
        {
            /* If the previous operation mode is config it is
                directly write the operation mode */
            if ( v_prev_opmode_u8 == OPERATION_MODE_CONFIG )
            {
                com_rslt = p_bno055->BNO055_BUS_READ_FUNC
                           ( p_bno055->dev_addr,
                             BNO055_OPERATION_MODE__REG,
                             &v_data_u8r, BNO055_ONE_U8X );
                if ( com_rslt == SUCCESS )
                {
                    v_data_u8r =
                        BNO055_SET_BITSLICE( v_data_u8r,
                                             BNO055_OPERATION_MODE,
                                             v_operation_mode_u8 );
                    com_rslt +=
                        p_bno055->BNO055_BUS_WRITE_FUNC
                        ( p_bno055->dev_addr,
                          BNO055_OPERATION_MODE__REG,
                          &v_data_u8r, BNO055_ONE_U8X );
                    /* Config mode to other
                    operation mode switching
                    required delay of 600ms*/
                    p_bno055->delay_msec(
                        BNO055_SIX_HUNDRES_U8X );
                }
            }
            else
            {
                /* If the previous operation
                mode is not config it is
                 write the config mode */
                com_rslt = p_bno055->BNO055_BUS_READ_FUNC
                           ( p_bno055->dev_addr,
                             BNO055_OPERATION_MODE__REG,
                             &v_data_u8r, BNO055_ONE_U8X );
                if ( com_rslt == SUCCESS )
                {
                    v_data_u8r =
                        BNO055_SET_BITSLICE( v_data_u8r,
                                             BNO055_OPERATION_MODE,
                                             OPERATION_MODE_CONFIG );
                    com_rslt += bno055_write_register(
                                    BNO055_OPERATION_MODE__REG,
                                    &v_data_u8r, BNO055_ONE_U8X );
                    /* other mode to config mode switching
                    required delay of 20ms*/
                    p_bno055->delay_msec( BNO055_TWENTY_U8X );
                }
                /* Write the operation mode */
                if ( v_operation_mode_u8 !=
                        OPERATION_MODE_CONFIG )
                {
                    com_rslt =
                        p_bno055->BNO055_BUS_READ_FUNC
                        ( p_bno055->dev_addr,
                          BNO055_OPERATION_MODE__REG,
                          &v_data_u8r, BNO055_ONE_U8X );
                    if ( com_rslt == SUCCESS )
                    {
                        v_data_u8r = BNO055_SET_BITSLICE
                                     ( v_data_u8r,
                                       BNO055_OPERATION_MODE,
                                       v_operation_mode_u8 );
                        com_rslt +=
                            p_bno055->BNO055_BUS_WRITE_FUNC
                            ( p_bno055->dev_addr,
                              BNO055_OPERATION_MODE__REG,
                              &v_data_u8r, BNO055_ONE_U8X );
                        /* Config mode to other
                        operation mode switching
                        required delay of 600ms*/
                        p_bno055->delay_msec(
                            BNO055_SIX_HUNDRES_U8X );
                    }
                }
            }
        }
        else
            com_rslt = ERROR;
    }
    return com_rslt;
}
/********************************************************/
/************** PAGE1 Functions *********************/
/********************************************************/
/*!
 *  @brief This API used to read the accel range
 *  from page one register from 0x08 bit 0 and 1
 *
 *  @param v_accel_range_u8 : The value of accel range
 *        v_accel_range_u8 |   result
 *       ----------------- | --------------
 *              0x00       | ACCEL_RANGE_2G
 *              0x01       | ACCEL_RANGE_4G
 *              0x02       | ACCEL_RANGE_8G
 *              0x03       | ACCEL_RANGE_16G
 *
 *  @return results of bus communication function
 *  @retval 0 -> Success
 *  @retval 1 -> Error
 *
 *
 */
BNO055_RETURN_FUNCTION_TYPE bno055_get_accel_range(
    u8 *v_accel_range_u8 )
{
    /* Variable used to return value of
    communication routine*/
    BNO055_RETURN_FUNCTION_TYPE com_rslt = ERROR;
    u8 v_data_u8r = BNO055_ZERO_U8X;
    s8 v_stat_s8 = ERROR;
    /* Check the struct p_bno055 is empty */
    if ( p_bno055 == NULL )
        return E_NULL_PTR;
    else
    {
        /*condition check for page, accel range is
        available in the page one*/
        if ( p_bno055->page_id != PAGE_ONE )
            /* Write page as one */
            v_stat_s8 = bno055_write_page_id( PAGE_ONE );
        if ( ( v_stat_s8 == SUCCESS ) ||
                ( p_bno055->page_id == PAGE_ONE ) )
        {
            /* Read the value of accel g range */
            com_rslt = p_bno055->BNO055_BUS_READ_FUNC
                       ( p_bno055->dev_addr,
                         BNO055_ACCEL_RANGE__REG,
                         &v_data_u8r, BNO055_ONE_U8X );
            *v_accel_range_u8 =
                BNO055_GET_BITSLICE( v_data_u8r,
                                     BNO055_ACCEL_RANGE );
        }
        else
            com_rslt = ERROR;
    }
    return com_rslt;
}
/*!
 *  @brief This API used to write the accel range
 *  from page one register from 0x08 bit 0 and 1
 *
 *  @param v_accel_range_u8 : The value of accel range
 *
 *        v_accel_range_u8 |   result
 *       ----------------- | --------------
 *              0x00       | ACCEL_RANGE_2G
 *              0x01       | ACCEL_RANGE_4G
 *              0x02       | ACCEL_RANGE_8G
 *              0x03       | ACCEL_RANGE_16G
 *
 *  @return results of bus communication function
 *  @retval 0 -> Success
 *  @retval 1 -> Error
 *
 *
 */
BNO055_RETURN_FUNCTION_TYPE bno055_set_accel_range(
    u8 v_accel_range_u8 )
{
    BNO055_RETURN_FUNCTION_TYPE com_rslt = ERROR;
    u8 v_data_u8r = BNO055_ZERO_U8X;
    s8 v_stat_s8 = ERROR;
    u8 v_prev_opmode_u8 = OPERATION_MODE_CONFIG;
    s8 v_pg_stat_s8 = ERROR;
    /* Check the struct p_bno055 is empty */
    if ( p_bno055 == NULL )
        return E_NULL_PTR;
    else
    {
        /* The write operation effective only if the operation
        mode is in config mode, this part of code is checking the
        current operation mode and set the config mode */
        v_stat_s8 = bno055_get_operation_mode( &v_prev_opmode_u8 );
        if ( v_stat_s8 == SUCCESS )
        {
            if ( v_prev_opmode_u8 != OPERATION_MODE_CONFIG )
                v_stat_s8 += bno055_set_operation_mode
                             ( OPERATION_MODE_CONFIG );
            if ( v_stat_s8 == SUCCESS )
            {
                /* Write page as one */
                v_pg_stat_s8 = bno055_write_page_id( PAGE_ONE );
                if ( v_pg_stat_s8 == SUCCESS )
                {
                    if ( v_accel_range_u8 < BNO055_FIVE_U8X )
                    {
                        /* Write the value of accel range*/
                        com_rslt =
                            p_bno055->BNO055_BUS_READ_FUNC
                            ( p_bno055->dev_addr,
                              BNO055_ACCEL_RANGE__REG,
                              &v_data_u8r, BNO055_ONE_U8X );
                        if ( com_rslt == SUCCESS )
                        {
                            v_data_u8r = BNO055_SET_BITSLICE
                                         ( v_data_u8r,
                                           BNO055_ACCEL_RANGE,
                                           v_accel_range_u8 );
                            com_rslt +=
                                p_bno055->BNO055_BUS_WRITE_FUNC
                                ( p_bno055->dev_addr,
                                  BNO055_ACCEL_RANGE__REG,
                                  &v_data_u8r, BNO055_ONE_U8X );
                        }
                    }
                    else
                        com_rslt = E_BNO055_OUT_OF_RANGE;
                }
                else
                    com_rslt = ERROR;
            }
            else
                com_rslt = ERROR;
        }
        else
            com_rslt = ERROR;
    }
    if ( v_prev_opmode_u8 != OPERATION_MODE_CONFIG )
        /* set the operation mode of
        previous operation mode*/
        com_rslt += bno055_set_operation_mode
                    ( v_prev_opmode_u8 );
    return com_rslt;
}

BNO055_RETURN_FUNCTION_TYPE bno055_set_gyro_range(
    u8 v_gyro_range_u8 )
{
    BNO055_RETURN_FUNCTION_TYPE com_rslt = ERROR;
    u8 v_data_u8r = BNO055_ZERO_U8X;
    s8 v_stat_s8 = ERROR;
    s8 v_pg_stat_s8 = ERROR;
    u8 v_prev_opmode_u8 = OPERATION_MODE_CONFIG;
    /* Check the struct p_bno055 is empty */
    if ( p_bno055 == NULL )
        return E_NULL_PTR;
    else
    {
        /* The write operation effective only if the operation
        mode is in config mode, this part of code is checking the
        current operation mode and set the config mode */
        v_stat_s8 = bno055_get_operation_mode( &v_prev_opmode_u8 );
        if ( v_stat_s8 == SUCCESS )
        {
            if ( v_prev_opmode_u8 != OPERATION_MODE_CONFIG )
                v_stat_s8 += bno055_set_operation_mode
                             ( OPERATION_MODE_CONFIG );
            if ( v_stat_s8 == SUCCESS )
            {
                /* Write page as one */
                v_pg_stat_s8 = bno055_write_page_id( PAGE_ONE );
                if ( v_pg_stat_s8 == SUCCESS )
                {
                    if ( v_gyro_range_u8 < BNO055_FIVE_U8X )
                    {
                        /* Write the value of gyro range*/
                        com_rslt =
                            p_bno055->BNO055_BUS_READ_FUNC
                            ( p_bno055->dev_addr,
                              BNO055_GYRO_RANGE__REG,
                              &v_data_u8r, BNO055_ONE_U8X );
                        if ( com_rslt == SUCCESS )
                        {
                            v_data_u8r = BNO055_SET_BITSLICE
                                         ( v_data_u8r,
                                           BNO055_GYRO_RANGE,
                                           v_gyro_range_u8 );
                            com_rslt +=
                                p_bno055->BNO055_BUS_WRITE_FUNC
                                ( p_bno055->dev_addr,
                                  BNO055_GYRO_RANGE__REG,
                                  &v_data_u8r, BNO055_ONE_U8X );
                        }
                    }
                    else
                        com_rslt = E_BNO055_OUT_OF_RANGE;
                }
                else
                    com_rslt = ERROR;
            }
            else
                com_rslt = ERROR;
        }
        else
            com_rslt = ERROR;
    }
    if ( v_prev_opmode_u8 != OPERATION_MODE_CONFIG )
        /* set the operation mode of
        previous operation mode*/
        com_rslt += bno055_set_operation_mode
                    ( v_prev_opmode_u8 );
    return com_rslt;
}
