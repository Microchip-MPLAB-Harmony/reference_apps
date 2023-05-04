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

#ifndef _UNSECURE_INTERFACE_H    /* Guard against multiple inclusion */
#define _UNSECURE_INTERFACE_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "../src/simpleMAP/simpleMAP_library.h"
#include "config/default/touch/touch.h"


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif
    
// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************    

typedef void (*secure_callback) (uint8_t callbacktype) __attribute__((cmse_nonsecure_call));

typedef enum
{
    BATTERY_UNKNOWN = 0,
            BATTERY_LOW,
            BATTERY_50,
            BATTERY_FULL
}APP_BAT_VOLT_STATUS;

// *****************************************************************************
// *****************************************************************************
// Section: External Variables
// *****************************************************************************
// ***************************************************************************** 

extern secure_callback SMAP_SECURE_CALLBACK;
extern uint8_t SMAP_SETTINGS;
extern struct simpleMAP_message * UNSECURE_RCV_MSG_BUFFER;
extern void touch_process();
extern void touch_init();

// *****************************************************************************
// *****************************************************************************
// Section: Global Variables
// *****************************************************************************
// ***************************************************************************** 



// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void simpleMAP_Register_Callback(uint8_t settings, struct simpleMAP_message * receive_message_buffer, secure_callback cb)

  Summary:  
    Callback after receiving a simpleMAP message 
  Returns:
    None.
 */

void simpleMAP_Register_Callback(uint8_t settings, struct simpleMAP_message * receive_message_buffer, secure_callback cb);

/*******************************************************************************
  Function:
    simpleMAP_Transfer_Application_Callback(uint8_t callbacktype)

  Summary:  
 Transfers the simpleMAP callback to user application
  Returns:
    None.
 */
void simpleMAP_Transfer_Application_Callback(uint8_t callbacktype);


/*******************************************************************************
  Function:
    bool simpleMAP_SendMessage(uint8_t * send_message_buffer, uint16_t bufferlength, bool addhmac, bool requestack)

  Summary:  
    Used to turn on and off the touch keypad's backlight
  Returns:
    True or false based on the success or failure of simplemap msessage send
 */
bool simpleMAP_SendMessage(uint8_t * send_message_buffer, uint16_t bufferlength, bool addhmac, bool requestack);

/*******************************************************************************
  Function:
    void simpleMAP_KeyRotation( void )

  Summary:  
     Updates the simpleMAP key
  Returns:
    None.
 */
void simpleMAP_KeyRotation( void );


/*******************************************************************************
  Function:
    void APP_SECURE_SetMeasurementDoneTouch(uint8_t val)

  Summary:  
     Sets the measurement_done_touch flag
  Returns:
    None.
 */
void APP_SECURE_SetMeasurementDoneTouch(uint8_t val);

/*******************************************************************************
  Function:
    void APP_SECURE_GetMeasurementDoneTouch(uint8_t val)

  Summary:  
      Get the measurement_done_touch flag status
  Returns:
    Value of measurement_done_touch flag
 */
uint8_t APP_SECURE_GetMeasurementDoneTouch();

/*******************************************************************************
  Function:
    bool APP_SECURE_GetLowPowerMeasurementStatus(void)

  Summary:  
    Used to get the status of low power measurement
  Returns:
    Value of low_power_measurement_status.
 */

bool APP_SECURE_GetLowPowerMeasurementStatus(void);

/*******************************************************************************
  Function:
    void APP_SECURE_DelayCycles(void *const hw, uint32_t cycles)

  Summary:  
    Add delay
  Returns:
    None
 */
void APP_SECURE_DelayCycles(void *const hw, uint32_t cycles);

/*******************************************************************************
  Function:
    void APP_SECURE_StandbyModeExit(void)

  Summary:  
    Prepares peripherals for exiting standby sleep
  Returns:
    None
 */
void APP_SECURE_StandbyModeExit(void);

#ifdef __cplusplus
}
#endif

#endif /* _UNSECURE_INTERFACE_H */

/* *****************************************************************************
 End of File
 */
