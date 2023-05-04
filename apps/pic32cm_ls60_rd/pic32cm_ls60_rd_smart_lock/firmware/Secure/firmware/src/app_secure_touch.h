/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

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

#ifndef _EXAMPLE_FILE_NAME_H    /* Guard against multiple inclusion */
#define _EXAMPLE_FILE_NAME_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

#include "config/default/touch/touch.h"
//#include "config/default/touch/touch_api_ptc.h"

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    /**
      @Function
        uint8_t APP_SECURE_GetMeasurementDoneTouch ( void ) 

      @Summary
     Returns the status of touch measurement
    **/
    uint8_t APP_SECURE_GetMeasurementDoneTouch();


    /**
      @Function
        uint8_t APP_SECURE_SetMeasurementDoneTouch ( uint8_t ) 

      @Summary
     * Sets the measurement_done_touch flag
    **/
    void APP_SECURE_SetMeasurementDoneTouch(uint8_t val);
    
    /**
      @Function
        bool get_low_power_measurement_status ( void ) 

      @Summary
     * Returns status of low_power_measurement flag
    **/
    bool APP_SECURE_GetLowPowerMeasurementStatus(void);
    
    
     // *****************************************************************************
    // *****************************************************************************
    // Section: External Functions
    // *****************************************************************************
    // *****************************************************************************\

    /*============================================================================
    void touch_process(void)
    ------------------------------------------------------------------------------
    Purpose: Main processing function of touch library. This function initiates the
             acquisition, calls post processing after the acquistion complete and
             sets the flag for next measurement based on the sensor status.
    Input  : none
    Output : none
    Notes  :
    ============================================================================*/
   
    extern void touch_process();
    
    /*============================================================================
    void touch_init(void)
    ------------------------------------------------------------------------------
    Purpose: Initialization of touch library. PTC, timer, and
             datastreamer modules are initialized in this function.
    Input  : none
    Output : none
    Notes  :
    ============================================================================*/
    
    extern void touch_init();
    
    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */

