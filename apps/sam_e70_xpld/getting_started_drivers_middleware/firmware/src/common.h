/* ************************************************************************** */
/** Descriptive File Name

  Company
    Microchip Technology Inc.

  File Name
    common.h

  Summary
    This header file provides a common interface between applications for 
    exchange of data.

  Description
    This file declares functions that can be used to fetch data between 
    applications.
 */
/* ************************************************************************** */

#ifndef _COMMON_H    /* Guard against multiple inclusion */
#define _COMMON_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "configuration.h"
#include "definitions.h"

// *****************************************************************************
// *****************************************************************************
// Section: Interface Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function
    int8_t COMMON_APP_SENSOR_GetTemperature ( void )

  Summary
    Get current temperature from app_sensor

  Returns
    Temperature in INT

  Example
    <code>
    int8_t temp = COMMON_APP_SENSOR_GetTemperature();
    </code>
 */
int8_t COMMON_APP_SENSOR_GetTemperature(void);

/*******************************************************************************
  Function
    bool COMMON_APP_EEPROM_GetTemperature ( int8_t* pBuff, int8_t size )

  Summary
    Get upto five temperature readings from app_eeprom

  Parameters:
    int8_t* pBuff - accepts a pointer to an array
    int8    size  - size of array

  Returns
    true  - Read OK
    false - Error

  Example
    <code>
    uint8_t temp[5];
    COMMON_APP_EEPROM_GetTemperature(temp, 5);
    </code>
 */
bool COMMON_APP_EEPROM_GetTemperature (int8_t* pBuff, int8_t size);

#endif /* _COMMON_H */

/* *****************************************************************************
 End of File
 */
