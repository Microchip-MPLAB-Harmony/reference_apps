/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_cam.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_CAM_Initialize" and "APP_CAM_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_CAM_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

#ifndef _APP_CAM_H
#define _APP_CAM_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"
#include "definitions.h" 
#include "arducam.h"
#include "barcode.h"

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

#define CAP_BUF_SIZE    (IMG_ACT_WIDTH * IMAGE_HEIGHT * 2) + 1
#define SCAN_BUF_SIZE   (IMAGE_WIDTH * IMAGE_HEIGHT * 2)
    
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
    APP_CAM_STATE_INIT=0,
    APP_CAM_STATE_CAMERA_RESET,
    APP_CAM_STATE_CHECK_CAMERA,
    APP_CAM_STATE_CAMERA_CONFIG,
    APP_CAM_STATE_SET_BMP_FORMAT,
    APP_CAM_STATE_SET_RESOLUTION,
    APP_CAM_STATE_USER_INPUT_READ,
    APP_CAM_STATE_IMG_CAPTURE,
    APP_CAM_STATE_CAPTURE_WAIT,
    APP_CAM_STATE_IMG_READ,
    APP_CAM_STATE_IDLE,
    APP_CAM_STATE_ERROR

} APP_CAM_STATES;


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
    /* The application's current state */
    APP_CAM_STATES state;
    
    DRV_SPI_TRANSFER_SETUP spiSetup;

    DRV_HANDLE  spiHandle;
    
    DRV_SPI_TRANSFER_HANDLE transferHandle;
    
    volatile bool isTransferComplete;
    volatile bool transferStatus;
    volatile bool status;
    
    char userInput;
    
    uint8_t writeReg[2];
    uint8_t readReg[4];
    
    uint8_t captureBuffer[CAP_BUF_SIZE];
    uint8_t scanBuffer[SCAN_BUF_SIZE];
    
    uint32_t imageSize;

} APP_CAM_DATA;

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
    void APP_CAM_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_CAM_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_CAM_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_CAM_Initialize ( void );

/*******************************************************************************
  Function:
    void APP_CAM_Tasks ( void )

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
    APP_CAM_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_CAM_Tasks( void );

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _APP_CAM_H */

/*******************************************************************************
 End of File
 */

