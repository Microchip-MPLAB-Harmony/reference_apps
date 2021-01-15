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

// DOM-IGNORE-BEGIN
/*******************************************************************************************
* © [2020] Microchip Technology Inc. and its subsidiaries

 * Subject to your compliance with these terms, you may use this Microchip software
 * and any derivatives exclusively with Microchip products. You are responsible for
 * complying with third party license terms applicable to your use of third party
 * software (including open source software) that may accompany this Microchip software.

 * SOFTWARE IS ?AS IS.? NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO
 * THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT,
 * SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF
 * THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW,
 * MICROCHIP?S TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT EXCEED AMOUNT
 * OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE. ADDITIONALLY, MICROCHIP
 * OFFERS NO SUPPORT FOR THE SOFTWARE. YOU MAY CONTACT YOUR LOCAL MICROCHIP FIELD SALES SUPPORT
 * REPRESENTATIVE TO INQUIRE ABOUT SUPPORT SERVICES AND APPLICABLE FEES, IF ANY. THESE TERMS
 * OVERRIDE ANY OTHER PRIOR OR SUBSEQUENT TERMS OR CONDITIONS THAT MIGHT APPLY TO THIS SOFTWARE
 * AND BY USING THE SOFTWARE, YOU AGREE TO THESE TERMS.
*******************************************************************************************/
// DOM-IGNORE-END

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
