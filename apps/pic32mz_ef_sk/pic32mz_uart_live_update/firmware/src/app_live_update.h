/*******************************************************************************
  MPLAB Harmony UART Live Update Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_live_update.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_LIVE_UPDATE_Initialize" and "APP_LIVE_UPDATE_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_LIVE_UPDATE_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

#ifndef _APP_LIVE_UPDATE_H
#define _APP_LIVE_UPDATE_H

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
#include "sys/kmem.h"

/* Compare Value to achieve a 1000Ms Delay */
#define TIMER_COMPARE_VALUE     (CORE_TIMER_FREQUENCY / 10)

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


typedef enum
{
    APP_LIVE_UPDATE_CMD_UNLOCK       = 0xa0,
    APP_LIVE_UPDATE_CMD_DATA         = 0xa1,
    APP_LIVE_UPDATE_CMD_VERIFY       = 0xa2,
    APP_LIVE_UPDATE_CMD_BKSWAP       = 0xa3,
} T_APP_LIVE_UPDATE_CMD;

typedef enum
{
    APP_LIVE_UPDATE_RESP_OK          = 0x50,
    APP_LIVE_UPDATE_RESP_ERROR       = 0x51,
    APP_LIVE_UPDATE_RESP_INVALID     = 0x52,
    APP_LIVE_UPDATE_RESP_CRC_OK      = 0x53,
    APP_LIVE_UPDATE_RESP_CRC_FAIL    = 0x54,
} T_APP_LIVE_UPDATE_RESP;

typedef enum
{
    APP_LIVE_UPDATE_STATUS_ERROR = 0,
    APP_LIVE_UPDATE_STATUS_UNLOCK,
    APP_LIVE_UPDATE_STATUS_READY_FOR_FLASH,
    APP_LIVE_UPDATE_STATUS_FLASH_SUCCESS,
    APP_LIVE_UPDATE_STATUS_VERIFY,
    APP_LIVE_UPDATE_STATUS_SWAP_BANK,
} T_APP_LIVE_UPDATE_STATUS;

/* Structure to validate the Flash serial and its checksum
 * Note: The order of the members should not be changed
 */
typedef struct
{
    uint32_t checksum_start;
    uint32_t serial;
    uint32_t checksum_end;
    uint32_t dummy;
} APP_LIVE_UPDATE_FLASH_SERIAL;

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
    APP_LIVE_UPDATE_STATE_INIT=0,
    APP_LIVE_UPDATE_STATE_SERVICE_TASKS,
    APP_LIVE_UPDATE_STATE_SUCCESS,
    APP_LIVE_UPDATE_STATE_TRIGGER_SYS_RESET,
    APP_LIVE_UPDATE_STATE_ERROR,

} APP_LIVE_UPDATE_STATES;

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
    APP_LIVE_UPDATE_STATES  state;

    volatile bool           error_status;

    volatile bool           guard_byte_check;

    volatile uint8_t        input_command;

    volatile bool           packet_received;

    volatile bool           guard_match;

    volatile bool           guard_received;

} APP_LIVE_UPDATE_DATA;

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
    void APP_LIVE_UPDATE_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_LIVE_UPDATE_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_LIVE_UPDATE_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_LIVE_UPDATE_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_LIVE_UPDATE_Tasks ( void )

  Summary:
    Starts the MPLAB Harmony Live Update execution.

  Description:
    This function can be used to start Live Update execution.

    The function runs only when there is a firmware update request from the HOST-PC via
    selected communication protocol to program into internal flash memory.

    Once the complete application is received, programmed and verified successfully.
    The most recent programmed application runs after the device reset.

    Note: This function never returns.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_LIVE_UPDATE_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_LIVE_UPDATE_Tasks( void );

#endif

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif /* _APP_LIVE_UPDATE_H */
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

