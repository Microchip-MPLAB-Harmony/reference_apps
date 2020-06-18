/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_sdcard_audio_task.h

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
//DOM-IGNORE-END

#ifndef _APP_SDCARD_AUDIO_H
#define _APP_SDCARD_AUDIO_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "definitions.h"

#include "decoder.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END
#define APP_SDCARD_AUDIO_PLAYER_QUEUE_BUFFER_SIZE 2
#define APP_MAKE_BUFFER_DMA_READY  __attribute__((coherent)) __attribute__((aligned(4)))
#define DISK_GetCurrentFilePosition APP_SDCARD_AUDIO_Card_GetCurrentFilePosition
//#define APP_SDCARD_AUDIO_PLAY_LED_ON BSP_LEDOn(BSP_LED_1)
//#define APP_SDCARD_AUDIO_PLAY_LED_OFF BSP_LEDOff(BSP_LED_1)
//#define APP_SDCARD_AUDIO_ERROR_LED_ON BSP_LEDOn(BSP_LED_2)
//#define APP_SDCARD_AUDIO_ERROR_LED_OFF BSP_LEDOff(BSP_LED_2)




// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef uint32_t (*APP_SDCARD_AUDIO_STREAM_SOURCE) (void);

typedef enum
{
    APP_SDCARD_AUDIO_STATE_CODEC_OPEN,
    APP_SDCARD_AUDIO_STATE_CODEC_SET_BUFFER_HANDLER,
    APP_SDCARD_AUDIO_STATE_CODEC_ADD_BUFFER,
    APP_SDCARD_AUDIO_STATE_CODEC_WAIT_FOR_BUFFER_COMPLETE,
    APP_SDCARD_AUDIO_STATE_CODEC_BUFFER_COMPLETE,

    APP_SDCARD_AUDIO_WAIT_FOR_CARD_MOUNT,

	/* The app mounts the disk */
    APP_SDCARD_AUDIO_CARD_MOUNT,
	/* The app unmounts the disk */
    APP_SDCARD_AUDIO_CARD_UNMOUNT,
    /* Set the current drive */
    APP_SDCARD_AUDIO_CARD_CURRENT_DRIVE_SET,

    APP_SDCARD_AUDIO_STATE_RUNNING,
    APP_SDCARD_AUDIO_ERROR

} APP_SDCARD_AUDIO_STATES;

typedef enum
{
    APP_SDCARD_AUDIO_DECODER_MP3,
    APP_SDCARD_AUDIO_DECODER_WAV,
    APP_SDCARD_AUDIO_DECODER_UNKNOWN
} APP_SDCARD_AUDIO_DECODER;

typedef enum
{
    APP_SDCARD_AUDIO_STREAM_MP3,
    APP_SDCARD_AUDIO_STREAM_WAV
} APP_SDCARD_AUDIO_STREAM;

typedef enum
{
    APP_SDCARD_AUDIO_PLAYER_STATE_RUNNING,
    APP_SDCARD_AUDIO_PLAYER_STATE_HALT,
    APP_SDCARD_AUDIO_PLAYER_STATE_NO_MEDIA,
    APP_SDCARD_AUDIO_PLAYER_STATE_NO_FILE,
    APP_SDCARD_AUDIO_PLAYER_STATE_WAITING,
    APP_SDCARD_AUDIO_PLAYER_STATE_SCANNING,
    APP_SDCARD_AUDIO_PLAYER_STATE_SEND_AUDIO_DATA,
    APP_SDCARD_AUDIO_PLAYER_STATE_DECODE_DATA,
    APP_SDCARD_AUDIO_PLAYER_STATE_TRACK_CHANGE,
    APP_SDCARD_AUDIO_PLAYER_STATE_WAIT_FOR_BUFFER_COMPLETION
} APP_SDCARD_AUDIO_PLAYER_STATE;

typedef enum
{
    APP_SDCARD_AUDIO_PLAYER_COMMAND_NONE,
    APP_SDCARD_AUDIO_PLAYER_COMMAND_STOP,
    APP_SDCARD_AUDIO_PLAYER_COMMAND_PLAY,
    APP_SDCARD_AUDIO_PLAYER_COMMAND_PAUSE,
    APP_SDCARD_AUDIO_PLAYER_COMMAND_PLAY_PAUSE,
    APP_SDCARD_AUDIO_PLAYER_COMMAND_NEXT_FILE,
    APP_SDCARD_AUDIO_PLAYER_COMMAND_PREV_FILE

}APP_SDCARD_AUDIO_PLAYER_COMMAND;

typedef struct
{
    int8_t buffer[DECODER_MAX_OUTPUT_BUFFER_SIZE] ;
    volatile bool inUse;
    bool decoded;
    DRV_CODEC_BUFFER_HANDLE writeHandler;
    size_t bufferSize;
}APP_SDCARD_AUDIO_PLAYER_QUEUE_BUFFER;

typedef struct
{
    /* SYS_FS File handle for 1st file */
    SYS_FS_HANDLE fileHandle;
    SYS_FS_FSTAT fileStatus;
    APP_SDCARD_AUDIO_PLAYER_STATE state;
    APP_SDCARD_AUDIO_PLAYER_QUEUE_BUFFER  buffer[APP_SDCARD_AUDIO_PLAYER_QUEUE_BUFFER_SIZE];

    /*Unfolding audio files*/
    uint16_t currentSongIdx;
    uint16_t nextSongIdx;
    uint16_t previousSongIdx;
    uint32_t totalAudioFiles;
    bool isRandomSongSet;
    uint16_t randomSongIdx;
    bool isSongListAvailable;

    /* Number of bytes read */
    uint32_t nBytesRead;
    uint32_t diskCurrentFile;
    int32_t  fileSize;
    int32_t readBytes;
    uint32_t currentFilesize;

    //int8_t readIdx;
    int8_t readIdx;
    uint8_t writeIdx;
    uint16_t decodeDataSize;

    bool nextTrack;
    bool isDiskMounted;
    bool readbyte_flag;
    bool noAudioFiles;

    bool MP3_decoder_enabled;
    bool WAV_decoder_enabled;

    APP_SDCARD_AUDIO_PLAYER_COMMAND pressCMD;
    APP_SDCARD_AUDIO_STREAM currentStreamType;
}APP_SDCARD_AUDIO_PLAYER;

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

} APP_SDCARD_AUDIO_CODEC;

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
    APP_SDCARD_AUDIO_STATES state;
    APP_SDCARD_AUDIO_CODEC codec;
    APP_SDCARD_AUDIO_PLAYER APP_MAKE_BUFFER_DMA_READY player;
    APP_SDCARD_AUDIO_STREAM_SOURCE streamSource;
    bool cardMountFlag;
    bool cardUnMountFlag;
} APP_SDCARD_AUDIO_DATA;

typedef struct{
    int8_t path[64];
} APP_SDCARD_AUDIO_CARD_FILE_PATH;

typedef struct{
    SYS_FS_FSTAT fstat;
    char path[64];
} APP_SDCARD_AUDIO_CARD_FILE_NODE;

typedef enum{
    APP_SDCARD_AUDIO_CARD_EVENT_REMOVED,
    APP_SDCARD_AUDIO_CARD_EVENT_INSERTED,
    APP_SDCARD_AUDIO_CARD_EVENT_SCANNING_STARTED,
    APP_SDCARD_AUDIO_CARD_EVENT_SCANNING_FINISHED,
    APP_SDCARD_AUDIO_CARD_EVENT_TRACK_CHANGED,
    APP_SDCARD_AUDIO_CARD_EVENT_END_OF_FILE,
    APP_SDCARD_AUDIO_CARD_EVENT_FILE_OPEN_ERROR
}APP_SDCARD_AUDIO_CARD_EVENT;

typedef enum
{
    APP_SDCARD_AUDIO_CARD_STATE_INIT,
    APP_SDCARD_AUDIO_CARD_STATE_SCANNING,
    APP_SDCARD_AUDIO_CARD_STATE_RUNNING,
    APP_SDCARD_AUDIO_CARD_STATE_REMOVED,
    APP_SDCARD_AUDIO_CARD_STATE_NO_AUDIO_FILES
}APP_SDCARD_AUDIO_CARD_TASK_STATE;

typedef struct
{
    APP_SDCARD_AUDIO_CARD_TASK_STATE state;
       /* SYS_FS File handle for dir */
    SYS_FS_HANDLE dirHandle;
    /* SYS_FS stat for dir read */
    SYS_FS_FSTAT dirstat;
}APP_SDCARD_AUDIO_CARD_TASK_DATA;


void APP_SDCARD_AUDIO_Tasks(void);

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
    void APP_SDCARD_AUDIO_Initialize(void);

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

void APP_SDCARD_AUDIO_Initialize(void);

/*******************************************************************************
  Function:
    void APP_SDCARD_AUDIO_Tasks ( void )

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
void APP_SDCARD_AUDIO_Tasks( void );
void APP_SDCARD_AUDIO_BufferEventHandler(DRV_CODEC_BUFFER_EVENT event,
        DRV_CODEC_BUFFER_HANDLE handle, uintptr_t context );
bool APP_SDCARD_AUDIO_FillOutputBuffer(void);
bool APP_SDCARD_AUDIO_isOutputBufferFull(void);
bool APP_SDCARD_AUDIO_isNoOutputBufferInUse(void);
bool APP_SDCARD_AUDIO_hasAllBuffersCompleted(void);
void APP_SDCARD_AUDIO_ResetBuffers(void);
void APP_SDCARD_AUDIO_Player_ReInitialize(void);
void APP_SDCARD_AUDIO_Player_Initialize(void);
void APP_SDCARD_AUDIO_Player_Reset(void);
uint8_t APP_SDCARD_AUDIO_GetNextIdxInOutputBuffer(uint8_t idx);
void APP_SDCARD_AUDIO_ClearBufferFlags(DRV_CODEC_BUFFER_HANDLE handle);
int8_t APP_SDCARD_AUDIO_GetCompletedBufferIdx(DRV_CODEC_BUFFER_HANDLE handle);
bool APP_SDCARD_AUDIO_Player_Decode(uint8_t *ptr, int16_t* outputptr);
APP_SDCARD_AUDIO_PLAYER* APP_SDCARD_AUDIO_Player_GetInstance(void);
APP_SDCARD_AUDIO_DECODER APP_SDCARD_AUDIO_Player_GetCurrentFileType(int8_t *ext);
void APP_SDCARD_AUDIO_SuspendStreaming(void);
void APP_SDCARD_AUDIO_RegisterStreamSource(APP_SDCARD_AUDIO_STREAM_SOURCE streamFuncGet);
APP_SDCARD_AUDIO_CARD_FILE_PATH * APP_SDCARD_AUDIO_GetFileTablePointer(void);
void APP_SDCARD_AUDIO_RandomTrackSet(uint16_t trackId);
void APP_SDCARD_AUDIO_NextTrackSet(void);
bool APP_SDCARD_AUDIO_isSonglistAvailable(void);
void APP_SDCARD_AUDIO_MuteOn(void);
void APP_SDCARD_AUDIO_MuteOff(void);
uint8_t APP_SDCARD_AUDIO_VolumeGet(void);
void APP_SDCARD_AUDIO_VolumeSet(uint8_t volume);
uint16_t APP_SDCARD_AUDIO_FileCountGet(void);
uint16_t APP_SDCARD_AUDIO_CurrentTrackIdGet(void);



void APP_SDCARD_AUDIO_Card_Initialize(void);
int32_t APP_SDCARD_AUDIO_Card_GetCurrentFilePosition(void);
uint32_t APP_SDCARD_AUDIO_Card_ReadCurrentFile(uint8_t *ptr, size_t readSize);
bool APP_SDCARD_AUDIO_Card_OpenTrack ( const int8_t *fname );
SYS_FS_HANDLE APP_SDCARD_AUDIO_Card_OpenFile ( const int8_t *fname );
void APP_SDCARD_AUDIO_Card_Tasks(void);
int32_t APP_SDCARD_AUDIO_Card_GetFilePosition (SYS_FS_HANDLE fileHandle );
uint32_t APP_SDCARD_AUDIO_Card_GetFileSize(SYS_FS_HANDLE fileHandle);
bool APP_SDCARD_AUDIO_Card_SetFilePosition (SYS_FS_HANDLE fileHandle, int32_t pos );
bool APP_SDCARD_AUDIO_Card_FillBuffer(uint8_t *ptr);
bool APP_SDCARD_AUDIO_Card_EndOfFile(void);
bool APP_SDCARD_AUDIO_Card_FileStatus(const int8_t* fname);
bool APP_SDCARD_AUDIO_Card_FileNameGet(SYS_FS_HANDLE handle, int8_t* cName);
bool APP_SDCARD_AUDIO_Card_EventHandler ( APP_SDCARD_AUDIO_CARD_EVENT event, uint32_t variable,SYS_FS_HANDLE fileHandle);
bool APP_SDCARD_AUDIO_Card_CloseFile (SYS_FS_HANDLE fileHandle );
bool APP_SDCARD_AUDIO_Card_NextTrack(void);
bool APP_SDCARD_AUDIO_Card_ReopenTrack(void);
bool APP_SDCARD_AUDIO_Card_PreviousTrack();
void APP_SDCARD_AUDIO_Card_TraverseAllFiles(APP_SDCARD_AUDIO_CARD_FILE_NODE node, bool isRoot);
SYS_FS_RESULT APP_SDCARD_AUDIO_Card_FS_ReadDirFlat(const int8_t *fname, uint8_t *dir_count, SYS_FS_FSTAT * dir_table, bool isRoot);
bool APP_SDCARD_AUDIO_Card_isSupportedAudioFile(int8_t *name);


//bool DECODER_EventHandler ( DECODER_EVENT event, uint32_t data );
bool APP_PlayerCommand ( APP_SDCARD_AUDIO_PLAYER_COMMAND cmd );

#endif /* _APP_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

