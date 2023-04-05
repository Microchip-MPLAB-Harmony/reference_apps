/*******************************************************************************
  13dof_example Source File

  Company:
    Microchip Technology Inc.

  File Name:
    13dof_example.c

  Summary:
    This file contains the function calls for collecting
    and printing data on serial terminal

  Description:
    This file collects various parameters like temperature, pressure
    from various sensors and stores these values in variables.The value of these variables
    is then displayed on serial terminal when the switch is pressed
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
#include "13dof_example.h"
#include "definitions.h"
#include "13dof.h"
#include "../click_interface.h"
#include "bmi088.h"
#include "bmm150.h"
#include "bme680.h"

float temperature;
float pressure;
float humidity;
int32_t gas_res;
int16_t accel_x;
int16_t accel_y;
int16_t accel_z;
int16_t gyro_x;
int16_t gyro_y;
int16_t gyro_z;
int16_t mag_x;
int16_t mag_y;
int16_t mag_z;
uint16_t r_hall;

bme680_t bme680;
bmm150_t bmm150;
bmi088_t bmi088;

void thirteenDof_example()
{
    CLICK_13DOF_TimerStart();
    
    //Initialize the three Integrated sensors
    thirteenDof_bme680_init( &bme680 );
    thirteenDof_bmm150_init( &bmm150 );
    thirteenDof_bmi088_init( &bmi088 );
    
    //Read temperature from bme680 and print the value on terminal
    temperature = thirteenDof_get_temperature( &bme680 );
    printf( "Temperature : %.2f C \r\n", temperature );
    
    //Read humidity from bme680 and print the value on terminal
    humidity = thirteenDof_get_humidity( &bme680 );
    printf( "Humidity : %.2f %% \r\n", humidity );
    
    //Read pressure from bme680 and print the value on terminal
    pressure = thirteenDof_get_pressure( &bme680 );
    printf( "Pressure : %.2f mbar \r\n", pressure );
    
    //Read gas resistance from bme680 and print the value on terminal
    gas_res = thirteenDof_get_gas_resistance( &bme680 );
    printf( "Gas Resistance : %ld \r\n", gas_res );
    
    /*Read accelerometer and gyroscopic data in X, Y and Z axes from bmi088
    sensor*/  
    thirteenDof_read_accel( &accel_x, &accel_y, &accel_z );
    thirteenDof_read_gyro( &gyro_x, &gyro_y, &gyro_z );
    
    //Read Geomagnetic data from bmm150 sensor
    thirteenDof_read_geo_mag_data( &mag_x, &mag_y, &mag_z, &r_hall );
    
    //Print Accel data values in X, Y and Z axes
    printf( "Accel X : %d ", accel_x );
    printf( " Y : %d ", accel_y );
    printf( " Z : %d \r\n", accel_z );
    
    //Print Gyroscopic data in X, Y and Z axes
    printf( "Gyro X : %d ", gyro_x );
    printf( " Y : %d ", gyro_y );
    printf( " Z : %d \r\n", gyro_z );
    
    //Print Geomagnetic data in X, Y and Z axes
    printf( "Mag X : %d ", mag_x );
    printf( " Y : %d ", mag_y );
    printf( " Z : %d \r\n", mag_z );

    CLICK_13DOF_DelayMs ( 1000 );
}