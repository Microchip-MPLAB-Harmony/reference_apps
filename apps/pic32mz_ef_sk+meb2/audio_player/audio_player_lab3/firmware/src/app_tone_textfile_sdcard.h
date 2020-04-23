/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_tone_textfile_sdcard.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
//DOM-IGNORE-END

#ifndef _APP_TONE_TEXTFILE_SDCARD_H
#define _APP_TONE_TEXTFILE_SDCARD_H

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
#include "audio/driver/codec/ak4953/drv_ak4953.h"
#include "audio/driver/i2s/drv_i2s_definitions.h"
#include "system/fs/sys_fs_media_manager.h"

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

#define APP_TONE_TEXTFILE_SDCARD_CODEC_WRITE_QUEUE_SIZE    DRV_I2S_QUEUE_SIZE_IDX0
    
#define MAX_SD_CARD_READ_BUFFER_SIZE    200    

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
    APP_TONE_TEXTFILE_SDCARD_STATE_CODEC_OPEN,
    APP_TONE_TEXTFILE_SDCARD_STATE_CODEC_SET_BUFFER_HANDLER,
    APP_TONE_TEXTFILE_SDCARD_STATE_CODEC_ADD_BUFFER,
    APP_TONE_TEXTFILE_SDCARD_STATE_CODEC_WAIT_FOR_BUFFER_COMPLETE,
    APP_TONE_TEXTFILE_SDCARD_STATE_CODEC_BUFFER_COMPLETE,  
    APP_TONE_TEXTFILE_SDCARD_STATE_CARD_MOUNT,
    APP_TONE_TEXTFILE_SDCARD_STATE_CARD_CURRENT_DRIVE_SET,
    APP_TONE_TEXTFILE_SDCARD_STATE_READ_FILE_SIZE,
    APP_TONE_TEXTFILE_SDCARD_STATE_CARD_READ,            
    APP_TONE_TEXTFILE_SDCARD_STATE_ERROR            

            
            
} APP_TONE_TEXTFILE_SDCARD_STATES;


// *****************************************************************************
/* Codec

  Summary:
    Application Codec data

  Description:
*/
typedef struct
{
    DRV_HANDLE handle;
    DRV_CODEC_BUFFER_HANDLE writeBufHandle;
    DRV_CODEC_BUFFER_EVENT_HANDLER bufferHandler;
    uintptr_t context;
    uint8_t *txbufferObject;
    size_t bufferSize;

} APP_TONE_TEXTFILE_SDCARD_CODEC;

typedef struct
{
    uint8_t buffer[MAX_SD_CARD_READ_BUFFER_SIZE];
    uint16_t nElements;       
    
}APP_TONE_TEXTFILE_AUDIO_DATA_PARSER;

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
    APP_TONE_TEXTFILE_SDCARD_STATES state;
    /* Codec Data */
    APP_TONE_TEXTFILE_SDCARD_CODEC codec;
    /* Audio data text parser */
    APP_TONE_TEXTFILE_AUDIO_DATA_PARSER textParser;
    /* File Handle for tone.txt */
    SYS_FS_HANDLE fileHandle;
    /* File Size*/
    int32_t fileSize;
    /* Current file position or number of bytes read from file */
    int32_t currentFilePosition;

} APP_TONE_TEXTFILE_SDCARD_DATA;



void APP_TONE_TEXTFILE_SDCARD_Tasks(void);

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
    void APP_TONE_TEXTFILE_SDCARD_Initialize(void);

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
    APP_SDCARD_AUDIO_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_TONE_TEXTFILE_SDCARD_Initialize(void); 

/*******************************************************************************
  Function:
    void APP_TONE_TEXTFILE_SDCARD_Tasks ( void )

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
    APP_SDCARD_AUDIO_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_TONE_TEXTFILE_SDCARD_Tasks( void );


static void APP_TONE_TEXTFILE_SDCARD_BufferEventHandler(DRV_CODEC_BUFFER_EVENT event,
        DRV_CODEC_BUFFER_HANDLE handle, uintptr_t context );
static bool APP_TONE_TEXTFILE_SDCARD_Read_SDCard( 
    const DRV_HANDLE handle,
    uint8_t* const pBuffer,
    const uint16_t requestedBytes,
    uint16_t* const pNumBytesRead );
static uint16_t APP_TONE_TEXTFILE_SDCARD_Parse_Audio_Text_Data(
    const uint8_t* const pInBuffer, 
    int16_t* const pOutBuffer,
    const uint16_t nInputBytes, 
    uint16_t* const pNumBytesParsed);
void APP_TONE_TEXTFILE_SDCARD_SuspendStreaming(void);

#endif /* _APP_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

