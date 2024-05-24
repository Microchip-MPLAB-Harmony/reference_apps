/* ************************************************************************** */
/** HTTP Application Source File

  @Company
    Microchip Technology Inc.

  @File Name
    app_http.h

  @Summary
    This header file provides prototypes and definitions for the webserver application.

  @Description
     This header file provides function prototypes and data type definitions for
    the webserver application. **/
/* ************************************************************************** */

/*****************************************************************************
 Copyright (C) 2012-2018 Microchip Technology Inc. and its subsidiaries.

 Microchip Technology Inc. and its subsidiaries.

 Subject to your compliance with these terms, you may use Microchip software
 and any derivatives exclusively with Microchip products. It is your
 responsibility to comply with third party license terms applicable to your
 use of third party software (including open source software) that may
 accompany Microchip software.

 THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
 EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
 WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR
 PURPOSE.
 
 IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
 INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
 BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
 FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
 ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *****************************************************************************/

#ifndef _APP_HTTP_H    /* Guard against multiple inclusion */
#define _APP_HTTP_H

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "definitions.h"

/* This section lists the other files that are included in this file.
 */


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

#if !defined(TCPIP_STACK_USE_HTTP_NET_SERVER)

#define APP_HTTP_Initialize()
#define APP_HTTP_Tasks()

#else

// *****************************************************************************
// *****************************************************************************
// Section: Interface Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_HTTP_Initialize ( void )

  Summary:
     Graphics application initialization routine.

  Description:
    This function initializes the Harmony Graphics application.  It places the
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
    APP_HTTP_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/
void APP_HTTP_Initialize();

/*******************************************************************************
  Function:
    void APP_HTTP_Tasks ( void )

  Summary:
    MPLAB Harmony HTTP application tasks function

  Description:
    This routine is the Harmony HTTP application's tasks function.  
    It defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_HTTP_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */
void APP_HTTP_Tasks();

// *****************************************************************************
// *****************************************************************************
// Section: Callback Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_HTTP_SYS_FS_EventHandler ( void )

  Summary:
    SYS_FS callback function

  Description:
    This routine is set as callback for the File System when the media 
    is mounted or unmounted
    It is usually set in the application initialization function

  Precondition:
    

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    SYS_FS_EventHandlerSet(APP_HTTP_SYS_FS_EventHandler, (uintptr_t)NULL);
    </code>

  Remarks:
    This routine should not be called directly
 */
void APP_HTTP_SYS_FS_EventHandler(SYS_FS_EVENT event, void * eventData, uintptr_t context);

#endif

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _APP_HTTP_H */

/* *****************************************************************************
 End of File
 */
