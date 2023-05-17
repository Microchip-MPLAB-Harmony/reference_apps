/*******************************************************************************
  BLE App Sensor data header file

  Company:
    Microchip Technology Inc.

  File Name:
    ble_app_sensor_data.h

  Summary:
    This file contains the declarations for functions needed to read
    the sensor values.

  Description:
    This file contains the prototypes for functions which prints the values
    on BLE app, this file also contains the typedefinitions for structures
    store the readings of sensor values.
*******************************************************************************/
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
#ifndef BLE_APP_SENSOR_DATA_H
#define BLE_APP_SENSOR_DATA_H
#include "click_routines/13dof/13dof.h"
#include "app.h"

typedef struct
{
    int16_t gyro_x_;
    int16_t gyro_y_;
    int16_t gyro_z_;
}gyro_t;

typedef struct
{
    int16_t accel_x_;
    int16_t accel_y_;
    int16_t accel_z_;
}accel_t;

typedef struct
{
    int16_t mag_x_;
    int16_t mag_y_;
    int16_t mag_z_;
    uint16_t r_hall_;
}mag_t;

void printaccel( accel_t *accel_data );
void printgyro( gyro_t *gyro_data );
void printmagnetic( mag_t *magnetic_data );
void Sendenv(uint8_t* pth);

uint8_t* memcpy_inplace_reorder(uint8_t* data, uint16_t len);
#endif // BLE_APP_SENSOR_DATA_H