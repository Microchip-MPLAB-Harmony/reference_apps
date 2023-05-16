/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_eeprom.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_EEPROM_Initialize" and "APP_EEPROM_Tasks" prototypes) and some of them 
    are only used internally by the application (such as the "APP_EEPROM_STATES"
    definition).  Both are defined here for convenience.
*******************************************************************************/

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

#ifndef _APP_EEPROM_H
#define _APP_EEPROM_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"
#include "driver/i2c/drv_i2c.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef enum
{
    /* Application's state machine's initial state. */
    APP_EEPROM_STATE_INIT,                
    APP_EEPROM_STATE_WRITE_TEMP_TO_EEPROM,                        
    APP_EEPROM_STATE_IDLE,                                                
    APP_EEPROM_STATE_ERROR
} APP_EEPROM_STATES;

typedef enum
{
    APP_EEPROM_REQ_STATUS_DONE,            
    APP_EEPROM_REQ_STATUS_ERROR,
    APP_EEPROM_REQ_STATUS_IN_PROGRESS,      
} APP_EEPROM_REQ_STATUS;

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    APP_EEPROM_STATES state;
    DRV_I2C_TRANSFER_SETUP i2cSetup;
    DRV_HANDLE i2cHandle;
    DRV_I2C_TRANSFER_HANDLE transferHandle;
    uint8_t i2cTxBuffer[2];
    uint8_t i2cRxBuffer[5];
    int8_t temperature;
    uint8_t wrIndex;
    bool isEEPROMTempWriteReq;
    volatile APP_EEPROM_REQ_STATUS reqStatus;
} APP_EEPROM_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_EEPROM_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_EEPROM_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_EEPROM_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_EEPROM_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_EEPROM_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_EEPROM_Tasks( void );

/*******************************************************************************
  Function:
    void APP_EEPROM_SetTempWriteRequest ( int8_t )

  Summary:
    This routine is called by the sensor task to inform the EEPROM task of the 
    new temperature value.

  Description:
    This routine is called by the sensor task to inform the EEPROM task of the 
    new temperature value.

  Precondition:
    None.

  Parameters:
    Temperature value.

  Returns:
    None.

  Example:
    <code>
    APP_EEPROM_SetTempWriteRequest(temperature);
    </code>

  Remarks:
    None.
 */
void APP_EEPROM_SetTempWriteRequest(int8_t temperature);


#endif

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif /* _APP_EEPROM_H */
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

