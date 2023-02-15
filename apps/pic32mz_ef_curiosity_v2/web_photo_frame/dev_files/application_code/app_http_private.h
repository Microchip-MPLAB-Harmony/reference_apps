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

#ifndef _APP_HTTP_PRIVATE_H    /* Guard against multiple inclusion */
#define _APP_HTTP_PRIVATE_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "definitions.h"

// application dependencies
#include "app_file_handler.h"

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


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

#define APP_SYS_FS_NVM_VOL                  SYS_FS_MEDIA_IDX1_DEVICE_NAME_VOLUME_IDX0
#define APP_SYS_FS_NVM_MOUNT_POINT          SYS_FS_MEDIA_IDX1_MOUNT_NAME_VOLUME_IDX0
#define APP_SYS_FS_NVM_TYPE                 MPFS2
#define APP_SYS_FS_NVM_TYPE_STRING          "MPFS"

// responses to the http client
#define APP_HTTP_RESPONSE_MEDIA_UNMOUNTED   "unmounted"
#define APP_HTTP_RESPONSE_MEDIA_NOT_FOUND   "not_found"
#define APP_HTTP_RESPONSE_MEDIA_LOADED      "loaded"
// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

// application state machine states
typedef enum
{
    // application init state
    APP_HTTP_TCPIP_INIT = 0,
            
    // step to init the HTTP Server
    APP_HTTP_START_WEB_SERVER,
    
    // all is set in the stack to run the http server
    APP_HTTP_GOING_ON,

    // error state
    APP_HTTP_TCPIP_ERROR,

} APP_HTTP_STATES;

// application data
typedef struct {
    // state machine states
    APP_HTTP_STATES state;

    // mark the fact the web file system is mounted
    bool webFSMounted;
    
    // HTTP server initialized status
    bool httpServerInitialized;
    
    // current file index
    uint32_t currentAppHttpFileIdx;
} APP_HTTP_DATA;

// structure saved into the http connection to manage the file transfer
typedef struct {
    // the number of bytes sent to the http connection
    uint32_t sentBytes;
    
    // received seed, used to differentiate between different file requests
    uint32_t seed;
    
    // pointer to the file to serve
    APP_FILE_DATA* appHttpFileData;
} HTTP_CONN_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Interface Functions
// *****************************************************************************
// *****************************************************************************

static void _APP_HTTP_GetPictureToShow(APP_FILE_NEXT_PREV nextPrev);

// *****************************************************************************
// *****************************************************************************
// Section: External Declarations
// *****************************************************************************
// *****************************************************************************

// HTTP application processing
#if defined(TCPIP_STACK_USE_HTTP_NET_SERVER)
extern void HTTP_APP_Initialize(void);
#endif // defined(TCPIP_STACK_USE_HTTP_NET_SERVER)

#endif

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _APP_HTTP_PRIVATE_H */

/* EOF */
