/*******************************************************************************
  13DOF click routine source file

  Company
    Microchip Technology Inc.

  File Name
    13dof.c

  Summary
    13dof click Implementation file
    
  Description
    This file has funtction calls for initialization of the three
    integrated sensors,i.e, initialization of various parameters like
    accel mode settings, calibration data etc
  Remarks:
    None.

 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
    (c) 2023 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/
// DOM-IGNORE-END
#include "13dof.h"
#include "bmi088.h"
#include "bmm150.h"
#include "bme680.h"
#include "definitions.h"
#include "../click_interface.h"

void thirteenDof_bme680_init( bme680_t *bme )
{
    bme680_init( bme );
    c13dof_bme680_soft_reset( );
    c13dof_bme680_get_calibration_data( bme );

    c13dof_bme680_get_temperature( bme );//dummy read
}
void thirteenDof_bmm150_init( bmm150_t *bmm )
{
    bmm150_init( bmm );
    c13dof_bmm150_power_on_reset( );
    bmm150_hal_write( C13DOF_BMM150_DATAREADY_ACTIVE_HIGH, C13DOF_BMM150_INTERR_AND_CHANNEL_EN_REG );
}
void thirteenDof_bmi088_init( bmi088_t *bmi )
{
    bmi088_init( bmi );
    c13dof_bmi088_soft_reset_accel( );
    c13dof_bmi088_set_accel_mode( 1 );
    c13dof_bmi088_enable_accel( );
}

float thirteenDof_get_temperature( bme680_t *bme )
{
    return c13dof_bme680_get_temperature( bme );
}

float thirteenDof_get_humidity( bme680_t *bme )
{
    return c13dof_bme680_get_humidity( bme );
}

float thirteenDof_get_pressure( bme680_t *bme )
{
    return c13dof_bme680_get_pressure( bme );
}

uint32_t thirteenDof_get_gas_resistance( bme680_t *bme )
{
    return c13dof_bme680_get_gas_resistance( bme );
}

void thirteenDof_read_accel( int16_t *accel_x, int16_t *accel_y, int16_t *accel_z )
{
    return c13dof_bmi088_read_accel( accel_x, accel_y, accel_z );
}

void thirteenDof_read_gyro( int16_t *gyro_x, int16_t *gyro_y, int16_t *gyro_z )
{
    return c13dof_bmi088_read_gyro( gyro_x, gyro_y, gyro_z );
}

void thirteenDof_read_geo_mag_data( int16_t *mag_x, int16_t *mag_y, int16_t *mag_z, uint16_t *res_hall )
{
    return c13dof_bmm150_read_geo_mag_data( mag_x, mag_y, mag_z, res_hall );
}



