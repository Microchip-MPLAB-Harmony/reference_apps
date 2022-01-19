/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    bme280_definitions.h

  Summary:
    This header file provides register definitions for the BME280 sensor.

  Description:
    This header file provides register definitions for the BME280 sensor. Please
    refer to BME280 sensor data-sheet for more information.
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

#ifndef BME280_DEFINITIONS_H
#define	BME280_DEFINITIONS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#define BME280_PARAM_TEMP                                       0
#define BME280_PARAM_PRESS                                      1
#define BME280_PARAM_HUM                                        2
    
#define BME280_CHIP_ID                                          0x60
/* SPI Address definition */
#define BME280_SPI_ADDRESS                                      0x76

#define BME280_SLEEP_MODE                                       0x00
#define BME280_FORCED_MODE                                      0x01
#define BME280_NORMAL_MODE                                      0x03
#define BME280_SOFT_RESET                                       0xB6
#define BME280_OVERSAMPLING_1X                                  0x01

/* Temperature Calibration Register Addresses */
#define BME280_CALIB_TEMP_DIG_T1_LSB_REG                        0x88
#define BME280_CALIB_TEMP_DIG_T1_MSB_REG                        0x89
#define BME280_CALIB_TEMP_DIG_T2_LSB_REG                        0x8A
#define BME280_CALIB_TEMP_DIG_T2_MSB_REG                        0x8B
#define BME280_CALIB_TEMP_DIG_T3_LSB_REG                        0x8C
#define BME280_CALIB_TEMP_DIG_T3_MSB_REG                        0x8D
/* Pressure Calibration Register Addresses */
#define BME280_CALIB_PRESS_DIG_P1_LSB_REG                       0x8E
#define BME280_CALIB_PRESS_DIG_P1_MSB_REG                       0x8F
#define BME280_CALIB_PRESS_DIG_P2_LSB_REG                       0x90
#define BME280_CALIB_PRESS_DIG_P2_MSB_REG                       0x91
#define BME280_CALIB_PRESS_DIG_P3_LSB_REG                       0x92
#define BME280_CALIB_PRESS_DIG_P3_MSB_REG                       0x93
#define BME280_CALIB_PRESS_DIG_P4_LSB_REG                       0x94
#define BME280_CALIB_PRESS_DIG_P4_MSB_REG                       0x95
#define BME280_CALIB_PRESS_DIG_P5_LSB_REG                       0x96
#define BME280_CALIB_PRESS_DIG_P5_MSB_REG                       0x97
#define BME280_CALIB_PRESS_DIG_P6_LSB_REG                       0x98
#define BME280_CALIB_PRESS_DIG_P6_MSB_REG                       0x99
#define BME280_CALIB_PRESS_DIG_P7_LSB_REG                       0x9A
#define BME280_CALIB_PRESS_DIG_P7_MSB_REG                       0x9B
#define BME280_CALIB_PRESS_DIG_P8_LSB_REG                       0x9C
#define BME280_CALIB_PRESS_DIG_P8_MSB_REG                       0x9D
#define BME280_CALIB_PRESS_DIG_P9_LSB_REG                       0x9E
#define BME280_CALIB_PRESS_DIG_P9_MSB_REG                       0x9F
/* Humidity Calibration Register Addresses */    
#define BME280_CALIB_HUM_DIG_H1_REG                             0xA1
#define BME280_CALIB_HUM_DIG_H2_LSB_REG                         0xE1
#define BME280_CALIB_HUM_DIG_H2_MSB_REG                         0xE2
#define BME280_CALIB_HUM_DIG_H3_REG                             0xE3
#define BME280_CALIB_HUM_DIG_H4_MSB_REG                         0xE4
#define BME280_CALIB_HUM_DIG_H4_LSB_REG                         0xE5
#define BME280_CALIB_HUM_DIG_H5_MSB_REG                         0xE6
#define BME280_CALIB_HUM_DIG_H6_REG                             0xE7
/* Register Memory Map */    
#define BME280_REG_CHIP_ID                                      0xD0  
#define BME280_REG_RESET                                        0xE0  
#define BME280_REG_STATUS                                       0xF3  
#define BME280_REG_CTRL_MEAS                                    0xF4  
#define BME280_REG_CTRL_HUMIDITY                                0xF2  
#define BME280_REG_CONFIG                                       0xF5  
#define BME280_REG_PRESSURE_MSB                                 0xF7  
#define BME280_REG_PRESSURE_LSB                                 0xF8  
#define BME280_REG_PRESSURE_XLSB                                0xF9  
#define BME280_REG_TEMPERATURE_MSB                              0xFA  
#define BME280_REG_TEMPERATURE_LSB                              0xFB  
#define BME280_REG_TEMPERATURE_XLSB                             0xFC  
#define BME280_REG_HUMIDITY_MSB                                 0xFD  
#define BME280_REG_HUMIDITY_LSB                                 0xFE               

#ifdef	__cplusplus
}
#endif

#endif	/* BME280_DEFINITIONS_H */

