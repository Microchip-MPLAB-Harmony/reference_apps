/*******************************************************************************
* Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#include "definitions.h"
#include "ble_app_sensor_data.h"
#include <string.h>
#include "../src/ble/non_gui/ble.h"

uint8_t gyro_handle = 0,accel_handle = 0,environment_handle = 0,quaternion_handle = 0;

volatile bool cmd_sent = 0;
extern BLE_DATA bleData;

uint8_t ble_temp = 3;
uint8_t range;
uint8_t buffer_data[1];

volatile bool flag =0 ;

uint8_t* memcpy_inplace_reorder(uint8_t* data, uint16_t len)
{
    uint8_t *a, *b;

    if (!data) return data;
    for (a = data, b = (data + len - 1); b > a; ++a, --b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
    return data;
}

void printgyro( gyro_t *gyro_data )
{
    memcpy_inplace_reorder((uint8_t *)&gyro_data->gyro_x_ , sizeof(gyro_data->gyro_x_));
    memcpy_inplace_reorder((uint8_t *)&gyro_data->gyro_y_, sizeof(gyro_data->gyro_y_));
    memcpy_inplace_reorder((uint8_t *)&gyro_data->gyro_y_, sizeof(gyro_data->gyro_y_));

    DRV_BT_CustomSendDataOverBLE(bleData.bt.handle, (uint8_t*)gyro_data, 6, gyro_handle);

    cmd_sent = 1;
}

void Sendenv(uint8_t* pth)
{

  DRV_BT_CustomSendDataOverBLE(bleData.bt.handle, (uint8_t*)pth,9, environment_handle);

  cmd_sent = 1;
}

void printmagnetic(mag_t *magnetic_data)
{
    uint8_t *p;
    uint8_t command[8];
    uint8_t i,j;

    memcpy_inplace_reorder((uint8_t *)&magnetic_data->mag_x_, sizeof(magnetic_data->mag_x_));
    memcpy_inplace_reorder((uint8_t *)&magnetic_data->mag_x_, sizeof(magnetic_data->mag_x_));
    memcpy_inplace_reorder((uint8_t *)&magnetic_data->mag_x_, sizeof(magnetic_data->mag_x_));
    memcpy_inplace_reorder((uint8_t *)&magnetic_data->r_hall_, sizeof(magnetic_data->r_hall_));

    p = (uint8_t*)magnetic_data;
    for(i = 0; i<6; i++)
    {
        j = 2 + i;
        command[i] = *(p+j);
    }
    command[6] = *p;
    command[7] = *(p+1);
    DRV_BT_CustomSendDataOverBLE(bleData.bt.handle, (uint8_t*)command, 8, quaternion_handle);

    cmd_sent = 1;
}

void printaccel(accel_t *accel_data)
{
    memcpy_inplace_reorder((uint8_t *)&accel_data->accel_x_, sizeof(accel_data->accel_x_));
    memcpy_inplace_reorder((uint8_t *)&accel_data->accel_y_, sizeof(accel_data->accel_y_));
    memcpy_inplace_reorder((uint8_t *)&accel_data->accel_z_, sizeof(accel_data->accel_z_));

    DRV_BT_CustomSendDataOverBLE(bleData.bt.handle, (uint8_t*)accel_data, 6, accel_handle);

    cmd_sent = 1;
}

/*******************************************************************************
 End of File
 */
