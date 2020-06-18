/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    bme280_driver.h

  Summary:
    This header file provides prototypes and definitions for the BME280 sensor
    driver.

  Description:
    This header file provides function prototypes and data type definitions for
    the BLE280 sensor driver. The APIs that are needed by other task routines are
    defined here. Please refer to BME280 sensor data-sheet for more information.
*******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#ifndef BME280_DRIVER_H
#define	BME280_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
typedef uint8_t (*READ_REG)(uint8_t addr);
typedef bool (*WRITE_REG)(uint8_t addr, uint8_t data);
typedef bool (*READ)(uint8_t addr, uint8_t* const pBuffer, uint8_t nBytes);

typedef struct 
{
  uint16_t      dig_T1;
  int16_t       dig_T2;
  int16_t       dig_T3;
  uint16_t      dig_P1;
  int16_t       dig_P2;
  int16_t       dig_P3;
  int16_t       dig_P4;
  int16_t       dig_P5;
  int16_t       dig_P6;
  int16_t       dig_P7;
  int16_t       dig_P8;
  int16_t       dig_P9;
  uint8_t       dig_H1;
  int16_t       dig_H2;
  uint8_t       dig_H3;
  int16_t       dig_H4;
  int16_t       dig_H5;
  int8_t        dig_H6;
  
}BME280_CALIBRATION_PARAM;
    
    
typedef struct
{
    /* calibration parameters */
    BME280_CALIBRATION_PARAM    calib_val;
    /* raw ADC values */
    int32_t     adc_t;
    int32_t     adc_p;
    int32_t     adc_h;
    int32_t     t_fine;
    /* Driver related call-backs */    
    READ_REG    readRegister;
    WRITE_REG   writeRegister;
    READ        read;
    
}BME280_DRIVER_DATA;

/* Drive call-backs registration*/
void BME280_RegisterDrvReadReg(READ_REG   readReg);
void BME280_RegisterDrvWriteReg(WRITE_REG  writeReg);
void BME280_RegisterDrvRead(READ   read);

uint8_t BME280_ID_Get();
void BME280_SoftReset();
void BME280_ReadRawWeatherData();
void BME280_CalibParams_Get();
void BME280_SetOversampling(uint8_t param, uint8_t val);
void BME280_PowerMode_Set(uint8_t Value);
int16_t BME280_GetTempReading();
uint16_t BME280_GetPressReading();
float BME280_GetHumReading();

#ifdef	__cplusplus
}
#endif

#endif	/* BME280_DRIVER_H */

