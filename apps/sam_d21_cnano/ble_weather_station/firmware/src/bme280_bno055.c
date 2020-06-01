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
#include "bme280_bno055.h"
#include <string.h>
#include "../src/ble/non_gui/ble.h"
#include "../src/weather_click/include/bme280_definitions.h"
#include "../src/weather_click/include/bme280_driver.h"

typedef struct
{
    volatile bool                   isBufferCompleteEvent;
    uint8_t                         slaveID;
    int16_t                         temperature;
    uint8_t                         txBuffer[MAX_I2C_TX_BUFFER_SIZE];
    uint8_t                         rxBuffer[MAX_I2C_RX_BUFFER_SIZE];
}BME_SENSOR_DATA;    
 BME_SENSOR_DATA BME280SensorData;

typedef struct
{
    int16_t temperature;
    uint16_t pressure;
    float humidity;
    
}BME_SENSOR_MEAS_DATA;

BME_SENSOR_MEAS_DATA                measData;

uint8_t gyro_handle = 0,accel_handle = 0,environment_handle = 0,quaternion_handle = 0;

volatile bool cmd_sent = 0;
extern BLE_DATA bleData;

uint8_t temp = 3;
uint8_t range;
uint8_t buffer[1];

volatile bool flag =0 ;
void APP_I2CCallback(uintptr_t context )
{
    if(SERCOM2_I2C_ErrorGet() == SERCOM_I2C_ERROR_NONE)
    {
        flag = 1;
        BME280SensorData.isBufferCompleteEvent = true;
    }
    else
    {

    }
}

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
	//printf("\r\nGyro data x = %d || y = %d || z = %d\r\n", gyro_data->x, gyro_data->y, gyro_data->z);
    
    DRV_BT_CustomSendDataOverBLE(bleData.bt.handle, (uint8_t*)gyro_data, 6, gyro_handle);
    
    cmd_sent = 1;
}

void Sendenv(uint8_t* pth)
{
    //uint8_t env[9] = {0x00,0x14,0x3c,0x00,0x00,0x00,0x00,0x00,0x0a}; 
    
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
      //  printf("\r\nAcce data x = %d || y = %d || z = %d || w = %d\r\n", quat_data->x, quat_data->y, quat_data->z,quat_data->w);

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
       // printf("\r\nAcce data x = %d || y = %d || z = %d\r\n", acce_data->x, acce_data->y, acce_data->z);
      
        DRV_BT_CustomSendDataOverBLE(bleData.bt.handle, (uint8_t*)acce_data, 6, accel_handle);
        
        cmd_sent = 1;

}

static bool BME280Sensor_WriteReg(uint8_t wrAddr, uint8_t wrData) 
{    
    BME280SensorData.txBuffer[0]            = wrAddr;
    BME280SensorData.txBuffer[1]            = wrData;
    BME280SensorData.isBufferCompleteEvent  = false;
    
    SERCOM2_I2C_Write(BME280SensorData.slaveID, BME280SensorData.txBuffer, 2);
    
    while(false == BME280SensorData.isBufferCompleteEvent);
    
    return true;
}

static uint8_t BME280Sensor_ReadReg(uint8_t rAddr) 
{
    BME280SensorData.txBuffer[0]            = rAddr;
    BME280SensorData.isBufferCompleteEvent  = false;
    
    SERCOM2_I2C_WriteRead(BME280SensorData.slaveID, BME280SensorData.txBuffer, 1, BME280SensorData.rxBuffer, 1);
    
    while(false == BME280SensorData.isBufferCompleteEvent);
            
    return BME280SensorData.rxBuffer[0];    
}

static bool BME280Sensor_Read(uint8_t rAddr, uint8_t* const pReadBuffer, uint8_t nBytes) 
{
    BME280SensorData.txBuffer[0]            = rAddr;
    BME280SensorData.isBufferCompleteEvent  = false;
    
    SERCOM2_I2C_WriteRead(BME280SensorData.slaveID, BME280SensorData.txBuffer, 1, pReadBuffer, nBytes);
    
    while(false == BME280SensorData.isBufferCompleteEvent);
            
    return true;
}

void BME280Sensor_Initialize(void)
{
    BME280SensorData.temperature   = 0;
    BME280SensorData.slaveID        = BME280_I2C_ADDRESS;
    BME280SensorData.isBufferCompleteEvent = false;
    
    /* Register with BME280 sensor */        
    BME280_RegisterDrvWriteReg(BME280Sensor_WriteReg);
    BME280_RegisterDrvReadReg(BME280Sensor_ReadReg);        
    BME280_RegisterDrvRead(BME280Sensor_Read);

    BME280_SoftReset();
    /* 100 m.sec delay */
     SYSTICK_DelayMs(100);

    if (BME280_CHIP_ID != BME280_ID_Get())
    {
        while(1);       /* Error Occurred */
    }
    BME280_CalibParams_Get();
    BME280_SetOversampling(BME280_PARAM_TEMP, BME280_OVERSAMPLING_1X);
    BME280_PowerMode_Set(BME280_NORMAL_MODE);
}

void bme_bno_init(void)
{  
    SERCOM2_I2C_CallbackRegister( APP_I2CCallback, (uintptr_t)NULL);
    SYSTICK_TimerStart();
    SYSTICK_DelayMs(2000);
    
    bno055.dev_addr = BNO055_I2C_ADDR1;
    bmp180.dev_addr = BMP180_I2C_ADDR;
    
    bmp180_init( &bmp180 ); 

    temp =  bno055_init( &bno055 );
    
    BME280Sensor_Initialize();
    
    bno055_set_operation_mode( 0x0C );
    bno055_set_accel_range( 0x01 );
    bno055_get_accel_range( &range );
    bno055_get_operation_mode(&buffer[0] );
    bno055_get_accel_unit( &temp );
    bno055_set_gyro_range( 0x04 );
    bno055_get_gyro_range( &range );
}

void read_bno055_pth_value(void)
{
    uint8_t tempBuffer[21] = {0};
    
    BME280_ReadRawWeatherData();

    measData.temperature = BME280_GetTempReading();
    measData.humidity = BME280_GetHumReading();
    measData.pressure = BME280_GetPressReading();
    
    tempBuffer[0] = ((uint8_t*)&measData.temperature)[0];
    tempBuffer[1] = ((uint8_t*)&measData.temperature)[1];
    tempBuffer[2] = ((uint8_t*)&measData.pressure)[0];
    tempBuffer[3] = ((uint8_t*)&measData.pressure)[1];
    tempBuffer[4] = 0;      /* Light Sensor Not supported */ 
    tempBuffer[5] = 0;      /* Light Sensor Not supported */
    tempBuffer[6] = 0;      /* Light Sensor Not supported */
    tempBuffer[7] = 0;      /* Light Sensor Not supported */
    tempBuffer[8] = (uint8_t)measData.humidity;
    tempBuffer[9] = '\r';
    tempBuffer[10] = '\n';  
    Sendenv(tempBuffer);
    
    bno055_set_operation_mode( 0x0C );
    bno055_set_accel_range( 0x01 );
    bno055_get_accel_range( &range );
    bno055_get_operation_mode(&buffer[0] );
    bno055_get_accel_unit( &temp );
    bno055_set_gyro_range( 0x04 );
    bno055_get_gyro_range( &range );

}