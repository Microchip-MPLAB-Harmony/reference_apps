/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/
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
#ifndef APP_H
#define APP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "configuration.h"
#include "definitions.h"

#include "disk.h"
#include "user.h"
#include "wav_dec.h"


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END 

#define _10ms       10
#define _20ms       2*_10ms
#define _50ms       5*_10ms
#define _100ms      2*_50ms
#define _200ms      2*_100ms
#define _500ms      5*_100ms
#define _1sec       2*_500ms

#define LED_PRD_MIN _50ms
#define LED_PRD_MAX _1sec

#ifdef USE_SDMMC
#define SDCARD_MOUNT_NAME       "/mnt/myDrive1"
#define SDCARD_DEV_NAME         "/dev/mmcblka1" 
#endif


       
// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

#ifdef DATA32_ENABLED
typedef struct 
{
    /* Left channel data */
    int32_t leftData;

    /* Right channel data */
    int32_t rightData;

} DRV_I2S_DATA32m;

extern DRV_I2S_DATA32m __attribute__ ((aligned (32))) App_Audio_Output_Buffer1[NUM_SAMPLES];
extern DRV_I2S_DATA32m __attribute__ ((aligned (32))) App_Audio_Output_Buffer2[NUM_SAMPLES];
#else
extern DRV_I2S_DATA16 __attribute__ ((aligned (32))) App_Audio_Output_Buffer1[NUM_SAMPLES];
extern DRV_I2S_DATA16 __attribute__ ((aligned (32))) App_Audio_Output_Buffer2[NUM_SAMPLES];
#endif
extern DRV_I2S_DATA16 __attribute__ ((aligned (32))) App_Audio_Input_Buffer[NUM_SAMPLES];
extern DRV_I2S_DATA16 __attribute__ ((aligned (32))) App_Audio_Output_TempBuf[NUM_SAMPLES];

// *****************************************************************************
/* Application States

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef enum
{
	/* Application's state machine's initial state. */
	APP_STATE_INIT=0,            
    /* TODO: Define states used by the application state machine. */
    APP_STATE_CODEC_OPEN,
    APP_STATE_CODEC_SET_BUFFER_HANDLER,
	APP_STATE_BUS_ENABLE,
    APP_STATE_WAIT_FOR_BUS_ENABLE_COMPLETE,
	APP_STATE_MOUNT_DISK,            
    APP_STATE_WAIT_FOR_DEVICE_ATTACH,
    APP_STATE_DEVICE_CONNECTED,
    APP_STATE_UNMOUNT_DISK,
    APP_STATE_OPEN_FILE,        // 9
    APP_STATE_INIT_READ_FILE,
    APP_STATE_READ_FILE,                        // these three
    APP_STATE_CODEC_ADD_BUFFER,                 // states must
    APP_STATE_CODEC_WAIT_FOR_BUFFER_COMPLETE,   // be consecutive            
    APP_STATE_CLOSE_FILE,
    APP_STATE_CLOSE_AND_REOPEN_FILE,            
    APP_STATE_IDLE,
    APP_STATE_HALT,
    APP_STATE_NO_MEDIA,
    APP_STATE_NO_FILE,
    APP_STATE_WAITING,
    APP_STATE_RUNNING,
    APP_STATE_READY_TO_SCAN,
    APP_STATE_SCANNING,
    APP_STATE_SEND_AUDIO_DATA,
    APP_STATE_DECODE_DATA,
    APP_STATE_TRACK_CHANGE,
    APP_STATE_WAIT_BUFFERS_COMPLETED,
    APP_STATE_ERROR
} APP_STATES;

typedef enum
{
    BTN_STATE_IDLE,
    BTN_STATE_PRESSED,
    BTN_STATE_BUTTON0_PRESSED,                   
    BTN_STATE_WAIT_FOR_RELEASE    
} BTN_STATES;

typedef enum
{
    LED_STATE_ON,
    LED_STATE_OFF,
    LED_STATE_TOGGLE,
    LED_STATE_BLINK,
} LED_STATES;

typedef enum
{
    GUI_STATE_VOLUME,
    GUI_STATE_BIT_DEPTH,
    GUI_STATE_TRACK_POSITION,
    GUI_STATE_FILENAME,
    GUI_STATE_CHANNELS,
    GUI_STATE_SAMPLE_RATE,
    GUI_STATE_MAX
} GUI_STATES;


// *****************************************************************************
// CODEC Data
//
//  Summary:
//    Holds codec data
//
//  Description:
//    This structure holds the codec's data.
//
//  Remarks:
// *****************************************************************************
typedef struct
{
    DRV_HANDLE handle;
    DRV_CODEC_BUFFER_HANDLE writeBufHandle1, writeBufHandle2;
    DRV_CODEC_BUFFER_EVENT_HANDLER bufferHandler;
    uintptr_t context;
    uint8_t *txbufferObject1;
    uint8_t *txbufferObject2;
    size_t bufferSize1, bufferSize2;
} AUDIO_CODEC_DATA;

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */


typedef enum
{
    PLAYER_CMD_NONE,
    PLAYER_CMD_STOP,
    PLAYER_CMD_PLAY,
    PLAYER_CMD_PAUSE,
    PLAYER_CMD_PLAY_PAUSE,
    PLAYER_CMD_NEXT_FILE,
    PLAYER_CMD_PREV_FILE,
    PLAYER_CMD_FAST_FORWARD,
    PLAYER_CMD_REWIND,
}PLAYER_COMMAND;

typedef enum
{
    PLAYER_EVENT_DISK_REMOVED,
    PLAYER_EVENT_DISK_INSERTED,
    PLAYER_EVENT_SCANNING_STARTED,
    PLAYER_EVENT_SCANNING_FOUND,
    PLAYER_EVENT_SCANNING_FINISHED,
    PLAYER_EVENT_NO_FILES_FOUND,
    PLAYER_EVENT_READY,
    PLAYER_EVENT_TAG_ARTIST,
    PLAYER_EVENT_TAG_ALBUM,
    PLAYER_EVENT_TAG_TITLE,
    PLAYER_EVENT_TRACK_CHANGED,
    PLAYER_EVENT_TIME_CHANGED,
    PLAYER_EVENT_SAMPLERATE,
    PLAYER_EVENT_BITRATE,
    PLAYER_EVENT_TRACK_TOTAL_TIME,
    PLAYER_EVENT_TRACK_PLAY_TIME,
    PLAYER_EVENT_VOLUME_CHANGE,
    PLAYER_EVENT_ERROR_MESSAGE,
    PLAYER_EVENT_GOTO_EXPLORER_WINDOW,
    PLAYER_EVENT_GOTO_PLAYER_WINDOW,
}
PLAYER_EVENT;

typedef enum{
    APP_STREAM_MP3,
    APP_STREAM_WMA,
    APP_STREAM_WAV,
    APP_STREAM_AAC,
    APP_STREAM_SPEEX,
    APP_STREAM_ADPCM,
    APP_STREAM_OPUS,
    APP_STREAM_FLAC,
    APP_STREAM_UNKNOWN,
}PLAYER_STREAM_TYPE;

typedef enum{
    APP_FILE_TYPE_WAV,
    APP_FILE_TYPE_MP3,
    APP_FILE_TYPE_WMA,
    APP_FILE_TYPE_AAC,
    APP_FILE_TYPE_MP4,
    APP_FILE_TYPE_UNKNOWN,
}APP_FILE_TYPE;

typedef enum{
    APP_DECODER_MP3,
    APP_DECODER_AAC,
    APP_DECODER_ADPCM,
    APP_DECODER_WMA,
    APP_DECODER_WAV,
    APP_DECODER_SPEEX,
    APP_DECODER_OPUS,
    APP_DECODER_FLAC,
    APP_DECODER_UNKNOWN,
}APP_DECODER_TYPE;

typedef enum{
    VOL_LVL_MUTE,
    VOL_LVL_LOW,
    VOL_LVL_MED,
    VOL_LVL_HIGH,
    VOL_LVL_MAX,
}VOL_LEVEL;

typedef enum{
    VOL_ADJUST,
    LINEAR_TRACK_CHANGE,
//    RANDOM_TRACK_CHANGE,
    MAX_MODES,
}PLAYER_MODE;

typedef struct{
    char chunkID[4];        // "RIFF"
    uint32_t chunkSize;
    char format[4];         // "WAVE"
    char subChunk1Id[4];    // "fmt "
    uint32_t subChunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    char subChunk2Id[4];    // "data"
    uint32_t subChunk2Size;
}WAV_FILE_HEADER;

typedef struct{
    bool bStereoMode;
}APP_RUNDCPT; // application layer descriptor 

#define AUDIO_QUEUEBUFFER_NUMBER 2

typedef struct{
//    int8_t buffer[DECODER_MAX_OUTPUT_BUFFER_SIZE];
    bool inUse;
    bool decoded;
    uint32_t offset;
    DRV_CODEC_BUFFER_HANDLE writeHandler;
    size_t bufferSize;
}AUDIO_QUEUEBUFFER;

typedef struct
{
    LED_STATES led1State;
    LED_STATES led2State;
    uint32_t led1Delay;
    uint32_t led2Delay;
    uint32_t led1Period;
    uint32_t led2Period;
    uint32_t led1Blinks;        // Number of blinks at _100ms on/off rate
    uint32_t led2Blinks;
    uint32_t led1BlinkCnt;      // Number of remaining blinks before _1sec off
    uint32_t led2BlinkCnt;
    bool led1On;
    bool led2On;
} LED_DATA;

typedef struct {
    /* SYS_FS File handle for 1st file */
    SYS_FS_HANDLE fileHandle;
    SYS_FS_FSTAT fileStatus;

     bool screenShown;
    /* handle to opened timer */
    DRV_HANDLE tmrHandle;
    
    /* Application's current state */
    APP_STATES state;
    GUI_STATES guiState;

    PLAYER_MODE playerBtnMode;
    VOL_LEVEL volLevel;
    /*Unfolding audio files*/
    uint16_t currentSongIdx, nextSongIdx, previousSongIdx, totalAudioFiles, playerDecodeDataSize, volPercent, oldVolPercent;
    
    uint32_t buttonDelay, playbackDelay, bytesRemaining, playbackDuration, guiUpdate;
    uint32_t nBytesRead, diskCurrentFile, fileSize, currPos, readBytes, current_filesize, sampleRate, bitRate, bitDepth; 
    
    AUDIO_CODEC_DATA codecData;
    uint8_t volumeIndex, volume, prevVol, readIdx, writeIdx, numOfChnls;   
    
    bool usbConnect, lrSync, readbyte_flag, pingPong, pause, headphone_out;
    
    bool deviceIsConnected;
    
    PLAYER_STREAM_TYPE currentStreamType;
    AUDIO_QUEUEBUFFER  audioBuffer[AUDIO_QUEUEBUFFER_NUMBER];
    bool trackPlayed[DISK_MAX_FILES], validFile;
    char fileName[64];
    char ext[5];
    
    size_t bufferSize1, bufferSize2;    // input buffer sizes

#ifdef MP3_DECODER_ENABLED    
    uint32_t mp3FirstFrame;
#endif    
}APP_DATA ;

typedef struct
{
    BTN_STATES state;
    uint32_t delay;
} BTN_DATA;

extern APP_DATA appData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/
//APP: API to CODEC Event Handler
void Audio_Codec_BufferEventHandler(DRV_CODEC_BUFFER_EVENT event,
    DRV_CODEC_BUFFER_HANDLE handle, uintptr_t context);
	
// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

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
    APP_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_Tasks ( void )

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
    APP_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void                APP_Tasks( void );
void                BTN_Tasks( void );
void                APP_LED_Tasks( void );
void                LED_Set_Mode( uint8_t led, LED_STATES state, uint32_t prd_blinks);
void                DISK_Tasks( void );
//bool                APP_GetSpiAudioMode( void );
APP_DATA *          APP_GetAppDataInstance( void );
//int32_t             APP_GetReadBytesInAppData( void );
//void                APP_SetSpiAudioMode( bool mode );
//void                APP_SetReadBytesInAppData( int32_t val );
//void                APP_SetReadFlagInAppData( bool b );
//void                APP_SetReadBytesReadFlag( int32_t val, bool b );
bool                APP_IsSupportedAudioFile( char *name );
//bool                APP_PlayerEventHandler ( PLAYER_EVENT event, uint32_t data );
void                APP_Initialize( void );
//bool                APP_PlayerDecode( uint8_t *ptr, int16_t* out );
bool                APP_Decoder( uint8_t *in, uint16_t sz, uint16_t * bytesRd, int16_t* out, uint16_t * wrtn );
//APP_DECODER_TYPE    APP_GetCurrentFileType ( char *ext );
#ifdef GFX_ENABLED
void                APP_Update_GUI_Tasks( void );
#endif

void APP_GUI_Tracklist(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _APP_H */
/*******************************************************************************
 End of File
 */

