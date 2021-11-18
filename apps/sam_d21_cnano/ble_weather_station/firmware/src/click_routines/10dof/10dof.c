 /*******************************************************************************
  10DOF click routine source file

  Company
    Microchip Technology Inc.

  File Name
    10dof.c

  Summary
  *
  Description

  Remarks:
    None.

 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
    (c) 2021 Microchip Technology Inc. and its subsidiaries. You may use this
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
#include "10dof.h"
#include "definitions.h"

static void tenDof_bno55_init(void)
{  
    bno055.dev_addr = BNO055_I2C_ADDR1;
    bno055_init( &bno055 );
    bno055_set_operation_mode( 0x0C );
    bno055_set_accel_range( 0x01 );
    bno055_set_gyro_range( 0x04 );
}

static void tenDof_bmp180_init(void)
{  
    bmp180.dev_addr = BMP180_I2C_ADDR;
    bmp180_init( &bmp180 );
}


void tenDof_init(void)
{
    tenDof_bno55_init();
    tenDof_bmp180_init ();    
}

void tenDof_get_bno55_gyro_xyz(struct bno055_gyro_t *gyro_data)
{
    get_bno55_gyro_xyz(gyro_data);    
}

void tenDof_get_bno55_accel_xyz(struct bno055_accel_t *accel_data)
{
    get_bno55_accel_xyz(accel_data);
}

void tenDof_get_bno55_quaternion_wxyz(struct bno055_quaternion_t *quaternion_data)
{
    get_bn055_quaternion_wxyz(quaternion_data);
}

int32_t tenDof_get_bmp180_pressure(void)
{
    int32_t pressure;
    uint32_t temp_press;
    
    temp_press = bmp180_get_uncomp_pressure();
    pressure = bmp180_get_pressure(temp_press);

    return pressure;    
}

float tenDof_get_bmp180_temperature(void)
{
    uint16_t temp;
    float temperature;
    int32_t temperature_int;
    
    temp = bmp180_get_uncomp_temperature();
    temperature_int = bmp180_get_temperature(temp);
    temperature = (float) temperature_int;
    temperature *= 0.1f;
    return temperature; 
}