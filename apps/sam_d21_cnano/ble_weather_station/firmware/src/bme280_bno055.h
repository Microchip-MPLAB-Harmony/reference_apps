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


#include "../src/10DOF_click/include/bmp180.h"
#include "../src/10DOF_click/include/bno055.h"

#define MAX_I2C_TX_BUFFER_SIZE                  100
#define MAX_I2C_RX_BUFFER_SIZE                  100

typedef struct bno055_accel_t acc_sensor_t;
typedef struct bno055_gyro_t gyro_sensor_t;
typedef struct bno055_quaternion_t quaternion_sensor_t;
struct bno055_t bno055;
struct bmp180_t bmp180;

void bme_bno_init(void);
void printaccel(acc_sensor_t *acce_data);
void printgyro(gyro_sensor_t *gyro_data);
void printquaternion(quaternion_sensor_t *quat_data);
void Sendenv(uint8_t* pth);
void read_bno055_pth_value(void);

uint8_t* memcpy_inplace_reorder(uint8_t* data, uint16_t len);

