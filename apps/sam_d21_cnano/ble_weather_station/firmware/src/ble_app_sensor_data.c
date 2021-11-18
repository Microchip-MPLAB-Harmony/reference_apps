/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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

uint8_t temp = 3;
uint8_t range;
uint8_t buffer[1];

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

void printgyro(gyro_sensor_t *gyro_data)
{
	memcpy_inplace_reorder((uint8_t *)&gyro_data->x, sizeof(gyro_data->x));
	memcpy_inplace_reorder((uint8_t *)&gyro_data->y, sizeof(gyro_data->y));
	memcpy_inplace_reorder((uint8_t *)&gyro_data->z, sizeof(gyro_data->z));

    DRV_BT_CustomSendDataOverBLE(bleData.bt.handle, (uint8_t*)gyro_data, 6, gyro_handle);
    
    cmd_sent = 1;
}

void Sendenv(uint8_t* pth)
{
    
  DRV_BT_CustomSendDataOverBLE(bleData.bt.handle, (uint8_t*)pth,9, environment_handle);
   
  cmd_sent = 1;
}
void printquaternion(quaternion_sensor_t *quat_data)
{   
     uint8_t *p;
     uint8_t command[8];
     uint8_t i,j;
        memcpy_inplace_reorder((uint8_t *)&quat_data->x, sizeof(quat_data->x));
        memcpy_inplace_reorder((uint8_t *)&quat_data->y, sizeof(quat_data->y));
        memcpy_inplace_reorder((uint8_t *)&quat_data->z, sizeof(quat_data->z));
        memcpy_inplace_reorder((uint8_t *)&quat_data->w, sizeof(quat_data->w));
        
        p = (uint8_t*)quat_data;
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
void printaccel(acc_sensor_t *acce_data)
{
        memcpy_inplace_reorder((uint8_t *)&acce_data->x, sizeof(acce_data->x));
        memcpy_inplace_reorder((uint8_t *)&acce_data->y, sizeof(acce_data->y));
        memcpy_inplace_reorder((uint8_t *)&acce_data->z, sizeof(acce_data->z));
      
        DRV_BT_CustomSendDataOverBLE(bleData.bt.handle, (uint8_t*)acce_data, 6, accel_handle);
        
        cmd_sent = 1;

}


