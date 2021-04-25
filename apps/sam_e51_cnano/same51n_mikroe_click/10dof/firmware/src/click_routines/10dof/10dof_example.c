 /*******************************************************************************
  10DOF click routine example source file

  Company
    Microchip Technology Inc.

  File Name
    10dof_example.c

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
#include "click_routines/10dof/10dof_example.h"
#include "definitions.h"

void tenDof_example(){
    
    struct bno055_gyro_t gyro_data;
    struct bno055_accel_t accel_data;    
    struct bno055_quaternion_t quaternion_data;
    
    tenDof_init();
    
    tenDof_get_bno55_gyro_xyz(&gyro_data);
    printf("\r\nGyro x = %d || y = %d || z = %d\r\n", gyro_data.x, gyro_data.y, gyro_data.z);
    
    tenDof_get_bno55_accel_xyz(&accel_data);
    printf("\r\nAccelerometer x = %d || y = %d || z = %d\r\n", accel_data.x, accel_data.y, accel_data.z);
    
    tenDof_get_bno55_quaternion_wxyz(&quaternion_data);
    printf("\r\nQuaternion x = %d || y = %d || z = %d || w = %d\r\n", quaternion_data.x, quaternion_data.y, quaternion_data.z,quaternion_data.w);
    
    printf("\r\nPressure = %ld kpa\r\n",(uint32_t) tenDof_get_bmp180_pressure());
    
    printf("\r\nTemperature = %ld C\r\n",(uint32_t) tenDof_get_bmp180_temperature());
    
}