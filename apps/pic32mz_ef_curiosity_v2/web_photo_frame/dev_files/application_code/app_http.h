/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

/*******************************************************************************
  HTTP Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the graphics application.

  Description:
    This file contains the source code for the graphics application.  It
    implements the logic of the graphics application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.
    It is also dependent on the application file handler that is providing the 
    keeping the file list on the sdcard and validates them
 *******************************************************************************/

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

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Constants                                                         */
/* ************************************************************************** */
/* ************************************************************************** */

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// Section: Interface Functions
// *****************************************************************************
// *****************************************************************************

void APP_HTTP_Initialize();
void APP_HTTP_Tasks();
void APP_HTTP_SYS_FS_EventHandler(SYS_FS_EVENT event, void * eventData, uintptr_t context);

// *****************************************************************************
// *****************************************************************************
// Section: External Declarations
// *****************************************************************************
// *****************************************************************************

#endif

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _APP_HTTP_H */

/* EOF */
