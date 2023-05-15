
/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_secure_touch.c

  Summary:
    Source code for touch.

  Description:
    This file contains the source code for processing the touch sensors securely.
    It provides APIs to initiate touch measurement and handle the touch state machine 
    securely.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************************
* Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.

 * Subject to your compliance with these terms, you may use this Microchip software
 * and any derivatives exclusively with Microchip products. You are responsible for
 * complying with third party license terms applicable to your use of third party
 * software (including open source software) that may accompany this Microchip software.

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
 *******************************************************************************************/
// DOM-IGNORE-END

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */
#include "definitions.h"
#include "device.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: External Variables                                                */
/* ************************************************************************** */
/* ************************************************************************** */

extern volatile uint8_t measurement_done_touch;
extern volatile bool low_power_measurement;

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Application Local Function                                        */
/* ************************************************************************** */
/* ************************************************************************** */

/** 
  @Function
    uint8_t APP_SECURE_GetMeasurementDoneTouch ( void ) 

  @Remarks
    Refer to the app_secure_touch.h interface header for function usage details.
 */

uint8_t APP_SECURE_GetMeasurementDoneTouch()
{
    return measurement_done_touch;
}

/** 
  @Function
    void APP_SECURE_SetMeasurementDoneTouch ( uint8_t ) 

  @Remarks
    Refer to the app_secure_touch.h interface header for function usage details.
 */
void APP_SECURE_SetMeasurementDoneTouch(uint8_t val)
{
    measurement_done_touch = val;
}

/** 
  @Function
    bool APP_SECURE_GetLowPowerMeasurementStatus (void) 

  @Remarks
    Refer to the app_secure_touch.h interface header for function usage details.
 */
bool APP_SECURE_GetLowPowerMeasurementStatus (void)
{
    return low_power_measurement;
}

/* *****************************************************************************
 End of File
 */
