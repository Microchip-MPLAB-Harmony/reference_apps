/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_usb.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_USB_Initialize" and "APP_USB_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_USB_STATES" definition).  Both
    are defined here for convenience.
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

#ifndef _APP_USB_H
#define _APP_USB_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "configuration.h"
#include "definitions.h"

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
#define APP_USB_READ_BUFFER_SIZE    512
#define APP_USB_WRITE_BUFFER_SIZE   512

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
    APP_USB_STATE_INIT=0,

    /* Application waits for device configuration*/
    APP_USB_STATE_WAIT_FOR_CONFIGURATION,

    /* Wait for a character receive */
    APP_USB_STATE_SCHEDULE_READ,

    /* A character is received from host */
    APP_USB_STATE_WAIT_FOR_READ_COMPLETE,

    /* Wait for the TX to get completed */
    APP_USB_STATE_SCHEDULE_WRITE,

    /* Wait for the write to complete */
    APP_USB_STATE_WAIT_FOR_WRITE_COMPLETE,

    /* Application Error state*/
    APP_USB_STATE_ERROR
} APP_USB_STATES;


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
    /* Device layer handle returned by device layer open function */
    USB_DEVICE_HANDLE deviceHandle;
    
    /* The application's current state */
    APP_USB_STATES state;

    /* Set Line Coding Data */
    USB_CDC_LINE_CODING setLineCodingData;

    /* Device configured state */
    bool isConfigured;

    /* Get Line Coding Data */
    USB_CDC_LINE_CODING getLineCodingData;

    /* Control Line State */
    USB_CDC_CONTROL_LINE_STATE controlLineStateData;

    /* Read transfer handle */
    USB_DEVICE_CDC_TRANSFER_HANDLE readTransferHandle;

    /* Write transfer handle */
    USB_DEVICE_CDC_TRANSFER_HANDLE writeTransferHandle;

    /* True if a character was read */
    bool isReadComplete;

    /* True if a character was written*/
    bool isWriteComplete;

    /* Flag determines SOF event occurrence */
    bool sofEventHasOccurred;

    /* Break data */
    uint16_t breakData;

    /* Application CDC read buffer */
    uint8_t * cdcReadBuffer;

    /* Application CDC Write buffer */
    uint8_t * cdcWriteBuffer;

    /* Number of bytes read from Host */ 
    uint32_t numBytesRead;
    
    /* Number of bytes to be sent to Host */
    uint32_t numBytesWrite;
    
    /* Command flag */
    bool isCommand;
} APP_USB_DATA;

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
    void APP_USB_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_USB_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_USB_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_USB_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_USB_Tasks ( void )

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
    APP_USB_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_USB_Tasks( void );



#endif /* _APP_USB_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

