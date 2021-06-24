/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_sdcard_audio_task.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
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

#include "app_sdcard_audio_task.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Variable Definitions
// *****************************************************************************
// *****************************************************************************

uint32_t AppSdCardAudioContext;
int8_t AppSdCardAudioCardCurrentLFN[255];
static uint32_t AppDataAudioCardTotalBytesRead = 0;

APP_SDCARD_AUDIO_DATA AppSdCardAudioData;
APP_SDCARD_AUDIO_PLAYER *AppDataAudioPlayerPtr;
APP_SDCARD_AUDIO_CARD_TASK_DATA AppDataAudioCardData;
static APP_SDCARD_AUDIO_CARD_FILE_PATH 
    AppSdCardAudioCardFilesTable[APP_SDCARD_AUDIO_CARD_MAX_FILES];
static APP_SDCARD_AUDIO_CARD_FILE_NODE AppDataAudioCardRootNode;

uint32_t   playerFileStreamStart = 0;
uint32_t playerFileAdvanceStep;
static bool playerMoveToEnd;
static uint16_t playerBitrate;
static uint16_t playerTrackTotalTime;
static uint16_t playerTrackPlayTime;
uint16_t playerDiskDataSize=0;
bool   playerStreaming;
volatile bool playerPlay = false;


static void APP_SysFSEventHandler(SYS_FS_EVENT event,void* mountName, uintptr_t context)
{
    switch (event) 
    {
        case SYS_FS_EVENT_MOUNT:
                AppSdCardAudioData.state = APP_SDCARD_AUDIO_CARD_MOUNT;   
                AppSdCardAudioData.cardMountFlag  = true;              
            break;

        case SYS_FS_EVENT_UNMOUNT:
                AppSdCardAudioData.state = APP_SDCARD_AUDIO_CARD_UNMOUNT; 
                AppSdCardAudioData.cardUnMountFlag  = true;                               
            break;
        case SYS_FS_EVENT_ERROR:
            break;
         case SYS_FS_EVENT_MOUNT_WITH_NO_FILESYSTEM:
            break;    
            
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************
void APP_SDCARD_AUDIO_Initialize(void)
{
    AppSdCardAudioData.codec.handle = DRV_HANDLE_INVALID;     
    AppSdCardAudioData.state = APP_SDCARD_AUDIO_CARD_MOUNT;    
    AppSdCardAudioData.codec.context = (uintptr_t)&AppSdCardAudioContext;
    AppSdCardAudioData.codec.bufferHandler = 
            (DRV_CODEC_BUFFER_EVENT_HANDLER) APP_SDCARD_AUDIO_BufferEventHandler;          
    AppSdCardAudioData.cardMountFlag = false;
    AppSdCardAudioData.cardUnMountFlag = false;    
    SYS_FS_EventHandlerSet(APP_SysFSEventHandler, (uintptr_t)NULL);    
    
    APP_SDCARD_AUDIO_Player_Initialize();         
}

////////////////////////////////////////////////////////////////////////////////
void APP_SDCARD_AUDIO_RegisterStreamSource(APP_SDCARD_AUDIO_STREAM_SOURCE streamFunction)
{
    AppSdCardAudioData.streamSource = streamFunction;
}

///////////////////////////////////////////////////////////////////////////////
void APP_SDCARD_AUDIO_Player_Initialize(void)
{
    AppSdCardAudioData.player.state = APP_SDCARD_AUDIO_PLAYER_STATE_SEND_AUDIO_DATA;
    AppSdCardAudioData.player.fileHandle = SYS_FS_HANDLE_INVALID;
    AppSdCardAudioData.player.fileStatus.lfname = (char*)AppSdCardAudioCardCurrentLFN;
    AppSdCardAudioData.player.fileStatus.lfsize = 255;
    AppSdCardAudioData.player.nextTrack = true;
    AppSdCardAudioData.player.readBytes = 0;
    AppSdCardAudioData.player.currentFilesize = 0;
    AppSdCardAudioData.player.pressCMD = APP_SDCARD_AUDIO_PLAYER_COMMAND_NONE;        
    APP_SDCARD_AUDIO_ResetBuffers();      
    AppSdCardAudioData.player.WAV_decoder_enabled  = isWAVdecoder_enabled();    
    APP_SDCARD_AUDIO_Player_ReInitialize();     
    AppDataAudioPlayerPtr = APP_SDCARD_AUDIO_Player_GetInstance();
}

///////////////////////////////////////////////////////////////////////////////
void APP_SDCARD_AUDIO_Player_ReInitialize(void)
{
    AppSdCardAudioData.player.fileSize = 0;
    AppSdCardAudioData.player.decodeDataSize = 0;    
    playerTrackPlayTime = 0;
    playerTrackTotalTime = 0;
    playerFileStreamStart = 0;
    playerBitrate = 0;
    playerStreaming = false;    
    APP_SDCARD_AUDIO_ResetBuffers();
    DECODER_Cleanup();
}

///////////////////////////////////////////////////////////////////////////////
void APP_SDCARD_AUDIO_Player_Reset(void)
{
    uint8_t i=0;    
    uint8_t decoderType;
    AppSdCardAudioData.player.decodeDataSize = 0;
    playerTrackPlayTime = 0;
    playerTrackTotalTime = 0;
    playerFileStreamStart = 0;
    playerBitrate = 0;
    playerStreaming = false;    
    APP_SDCARD_AUDIO_ResetBuffers();
    DECODER_Cleanup();    
    do
    {
       i++;
    } while(AppSdCardAudioData.player.fileStatus.fname[i]!= '.');    
    decoderType = APP_SDCARD_AUDIO_Player_GetCurrentFileType 
            ((int8_t*)(&(AppSdCardAudioData.player.fileStatus.fname[i+1])));
    DECODER_Initialize (decoderType);
}


///////////////////////////////////////////////////////////////////////////////
void APP_SDCARD_AUDIO_Tasks(void)
{
    if(AppSdCardAudioData.streamSource() == 0)
    {        
        switch(AppSdCardAudioData.state)
        {
            case APP_SDCARD_AUDIO_CARD_MOUNT:
            {
                    if(!AppSdCardAudioData.cardMountFlag)                
                    {
                        /* The disk could not be mounted. Try
                        * mounting again untill success. */
                        AppSdCardAudioData.state = APP_SDCARD_AUDIO_CARD_MOUNT;
                    }
                    else
                    {
                        AppSdCardAudioData.cardMountFlag = false;      
                        AppSdCardAudioData.state = APP_SDCARD_AUDIO_STATE_CODEC_OPEN;                                        
                    }             
            }
            break;            
                       
            case APP_SDCARD_AUDIO_STATE_CODEC_OPEN:
            {
                /* A client opens the driver object to get an Handle */
                AppSdCardAudioData.codec.handle = DRV_CODEC_Open(DRV_CODEC_INDEX_0, 
                        DRV_IO_INTENT_WRITE);
                if(AppSdCardAudioData.codec.handle != DRV_HANDLE_INVALID)
                {
                    AppSdCardAudioData.state = 
                            APP_SDCARD_AUDIO_STATE_CODEC_SET_BUFFER_HANDLER;
                }
                else
                {
                    /* Got an Invalid Handle.  Wait for AK4384 to Initialize */
                    ;
                }
            }
            break;

            /* Set a handler for the audio buffer completion event */
            case APP_SDCARD_AUDIO_STATE_CODEC_SET_BUFFER_HANDLER:
            {
                DRV_CODEC_BufferEventHandlerSet(AppSdCardAudioData.codec.handle,
                        AppSdCardAudioData.codec.bufferHandler,
                        AppSdCardAudioData.codec.context);                                                
                
                AppSdCardAudioData.state = APP_SDCARD_AUDIO_CARD_CURRENT_DRIVE_SET;                
            }
            break;           
        
            case APP_SDCARD_AUDIO_CARD_UNMOUNT:
            {
                if(AppSdCardAudioData.codec.handle != DRV_HANDLE_INVALID)
                {    
                    DRV_CODEC_Close(AppSdCardAudioData.codec.handle);
                }

                if(SYS_FS_HANDLE_INVALID!= AppSdCardAudioData.player.fileHandle)
                {    
                    APP_SDCARD_AUDIO_Card_CloseFile(AppSdCardAudioData.player.fileHandle);
                }
                
                AppSdCardAudioData.cardUnMountFlag  = false;
                AppSdCardAudioData.state = APP_SDCARD_AUDIO_CARD_MOUNT;                
            }                                  
            break;
            
            
            case APP_SDCARD_AUDIO_CARD_CURRENT_DRIVE_SET:
            {
                if(SYS_FS_CurrentDriveSet(APP_SDCARD_AUDIO_CARD_MOUNT_NAME) == SYS_FS_RES_FAILURE)
                {
                    /* Error while setting current drive */
                    AppSdCardAudioData.state = APP_SDCARD_AUDIO_ERROR;
                }
                else
                {
                    APP_SDCARD_AUDIO_Card_Initialize();                              
                    /* Open a file for reading. */
                    AppSdCardAudioData.state = APP_SDCARD_AUDIO_STATE_RUNNING;
                }    
            }

            case APP_SDCARD_AUDIO_STATE_RUNNING: 
            {
                APP_SDCARD_AUDIO_Card_Tasks();
                switch(AppSdCardAudioData.player.state)
                {
                    case APP_SDCARD_AUDIO_PLAYER_STATE_RUNNING:
                    {            
                        bool ret = true;
                        ret = APP_SDCARD_AUDIO_FillOutputBuffer();                
                        if(true == ret)
                        {
                            APP_SDCARD_AUDIO_SRC_ON();
                        }
                        else
                        {
                            APP_SDCARD_AUDIO_SRC_OFF();                            
                        }
                    }
                    break;


                    case APP_SDCARD_AUDIO_PLAYER_STATE_TRACK_CHANGE:
                    {
                        playerTrackPlayTime = 0;
                        // Goto next state, wait for all previous buffers complete.
                        AppSdCardAudioData.player.state = 
                                APP_SDCARD_AUDIO_PLAYER_STATE_WAIT_FOR_BUFFER_COMPLETION;
                    }
                     break;            


                    case APP_SDCARD_AUDIO_PLAYER_STATE_WAIT_FOR_BUFFER_COMPLETION:
                    // wait the buffers in I2S are all played
                    if(APP_SDCARD_AUDIO_hasAllBuffersCompleted())
                    {
                        if(AppSdCardAudioData.player.nextTrack)
                        {
                            APP_PlayerCommand(APP_SDCARD_AUDIO_PLAYER_COMMAND_NEXT_FILE);
                        }
                        else
                        {
                            AppSdCardAudioData.player.nextTrack = true;
                            APP_PlayerCommand(APP_SDCARD_AUDIO_PLAYER_COMMAND_PREV_FILE);
                        }
                    }
                    break;                     
                    default:
                        break;
                }  
            }
            break;

            case APP_SDCARD_AUDIO_ERROR:
            {
//                APP_SDCARD_AUDIO_PLAY_LED_OFF;
//                APP_SDCARD_AUDIO_ERROR_LED_ON;
            }
            break;
            
            default:
                break;
        }
    }
    else
    {
    }
}

///////////////////////////////////////////////////////////////////////////////
void APP_SDCARD_AUDIO_SuspendStreaming(void)
{  
    DRV_CODEC_Close(AppSdCardAudioData.codec.handle);     
    if(APP_SDCARD_AUDIO_Card_CloseFile(AppSdCardAudioData.player.fileHandle))
    {
        if(SYS_FS_Unmount(APP_SDCARD_AUDIO_CARD_MOUNT_NAME) != 0)
        {
        }
        else
        {
//            APP_SDCARD_AUDIO_PLAY_LED_OFF;                
//            APP_SDCARD_AUDIO_ERROR_LED_OFF;                               
        }    
    }  
}

uint32_t flag_enter2=0;
uint32_t flag_enter3=0;
uint32_t flag_enter4=0;
uint32_t flag_enter5=0;
bool check_flag=0;
////////////////////////////////////////////////////////////////////////////////
bool APP_SDCARD_AUDIO_FillOutputBuffer(void)
{
    uint8_t audioInput[DECODER_MAX_INPUT_BUFFER_SIZE];
    int8_t *outputptr = NULL;


    while( !APP_SDCARD_AUDIO_isOutputBufferFull() )
    {
        outputptr = AppSdCardAudioData.player.buffer
                    [AppSdCardAudioData.player.writeIdx].buffer;
        if(APP_SDCARD_AUDIO_Card_FillBuffer(audioInput)==true)
        {          
            if(APP_SDCARD_AUDIO_Player_Decode (audioInput, (int16_t*) outputptr)==true)//
            {

                if(AppSdCardAudioData.player.decodeDataSize != 0)
                {
                    check_flag = 1;    
                            flag_enter3++;
                    AppSdCardAudioData.player.buffer
                            [AppSdCardAudioData.player.writeIdx].decoded = true;
                    AppSdCardAudioData.player.buffer
                            [AppSdCardAudioData.player.writeIdx].bufferSize = 
                            AppSdCardAudioData.player.decodeDataSize;                    
                    AppSdCardAudioData.player.writeIdx = 
                            APP_SDCARD_AUDIO_GetNextIdxInOutputBuffer(AppSdCardAudioData.player.writeIdx);
                    AppSdCardAudioData.player.decodeDataSize = 0;
                }
                else
                {                    
                    return false;
                }
                AppSdCardAudioData.player.state = APP_SDCARD_AUDIO_PLAYER_STATE_RUNNING;
            }
            else
             {
                 AppSdCardAudioData.player.nextTrack = true;
                 AppSdCardAudioData.player.state = 
                         APP_SDCARD_AUDIO_PLAYER_STATE_TRACK_CHANGE;
                 return false;
             }
        }
        else
        {

            AppSdCardAudioData.player.nextTrack = true;
            AppSdCardAudioData.player.state = APP_SDCARD_AUDIO_PLAYER_STATE_TRACK_CHANGE;
            return false;
        }
    }    
    playerStreaming = true;
    if(APP_SDCARD_AUDIO_isNoOutputBufferInUse())
    {
        flag_enter4++;  
            int8_t readIdx = AppSdCardAudioData.player.readIdx;   
            
            DRV_CODEC_BufferAddWrite(AppSdCardAudioData.codec.handle, 
                    &AppSdCardAudioData.codec.writeBufHandle,
                    AppSdCardAudioData.player.buffer[readIdx].buffer,
                    AppSdCardAudioData.player.buffer[readIdx].bufferSize);                                                    
            if(AppSdCardAudioData.codec.writeBufHandle != DRV_CODEC_BUFFER_HANDLE_INVALID)
            {
                AppSdCardAudioData.player.buffer[readIdx].writeHandler = 
                        AppSdCardAudioData.codec.writeBufHandle;
                AppSdCardAudioData.player.buffer[readIdx].inUse = true;
                AppSdCardAudioData.player.readIdx = APP_SDCARD_AUDIO_GetNextIdxInOutputBuffer(readIdx);             
            }            
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
bool APP_SDCARD_AUDIO_isOutputBufferFull(void)
{
    int i;
    for(i = 0; i < APP_SDCARD_AUDIO_PLAYER_QUEUE_BUFFER_SIZE; i++)
    {
        if(!AppSdCardAudioData.player.buffer[i].decoded)
            return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
bool APP_SDCARD_AUDIO_isNoOutputBufferInUse(void)
{
    int i;
    for(i = 0; i < APP_SDCARD_AUDIO_PLAYER_QUEUE_BUFFER_SIZE;i++)
    {
        if(AppSdCardAudioData.player.buffer[i].inUse)
            return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
bool APP_SDCARD_AUDIO_hasAllBuffersCompleted(void)
{
    int i;
    for(i = 0; i < APP_SDCARD_AUDIO_PLAYER_QUEUE_BUFFER_SIZE; i++)
    {
        if(AppSdCardAudioData.player.buffer[i].writeHandler != DRV_CODEC_BUFFER_HANDLE_INVALID)
            return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
void APP_SDCARD_AUDIO_ResetBuffers(void)
{
    int i = 0;
    for(i=0; i < APP_SDCARD_AUDIO_PLAYER_QUEUE_BUFFER_SIZE; i++)
    {
        AppSdCardAudioData.player.buffer[i].inUse = false;
        AppSdCardAudioData.player.buffer[i].decoded = false;
        AppSdCardAudioData.player.readIdx = 0;
        AppSdCardAudioData.player.writeIdx = 0;
    }
}

////////////////////////////////////////////////////////////////////////////////
uint8_t APP_SDCARD_AUDIO_GetNextIdxInOutputBuffer(uint8_t idx)
{
    return (uint8_t)((idx+1) % APP_SDCARD_AUDIO_PLAYER_QUEUE_BUFFER_SIZE);
}

////////////////////////////////////////////////////////////////////////////////
void APP_SDCARD_AUDIO_ClearBufferFlags(DRV_CODEC_BUFFER_HANDLE handle)
{
    int8_t releaseIdx = APP_SDCARD_AUDIO_GetCompletedBufferIdx(handle);
    if(releaseIdx == -1)
    {
        return;
    }
    APP_SDCARD_AUDIO_PLAYER *AppDataAudioPlayerPtr = APP_SDCARD_AUDIO_Player_GetInstance();
    AppDataAudioPlayerPtr->buffer[releaseIdx].inUse = false;
    AppDataAudioPlayerPtr->buffer[releaseIdx].bufferSize = 0;
    AppDataAudioPlayerPtr->buffer[releaseIdx].decoded = false;
    AppDataAudioPlayerPtr->buffer[releaseIdx].writeHandler = DRV_CODEC_BUFFER_HANDLE_INVALID;
}

////////////////////////////////////////////////////////////////////////////////
int8_t APP_SDCARD_AUDIO_GetCompletedBufferIdx(DRV_CODEC_BUFFER_HANDLE handle)
{
    int8_t i;
    APP_SDCARD_AUDIO_PLAYER *AppDataAudioPlayerPtr = APP_SDCARD_AUDIO_Player_GetInstance();
    for(i = 0; i < APP_SDCARD_AUDIO_PLAYER_QUEUE_BUFFER_SIZE; i++)
    {
        if(AppDataAudioPlayerPtr->buffer[i].writeHandler == handle)
        {
            return i;
        }
    }
    // something wrong
    return -1;
}

////////////////////////////////////////////////////////////////////////////////
APP_SDCARD_AUDIO_PLAYER* APP_SDCARD_AUDIO_Player_GetInstance(void)
{
    return &AppSdCardAudioData.player;
}

////////////////////////////////////////////////////////////////////////////////
bool APP_SDCARD_AUDIO_Player_Decode(uint8_t *ptr, int16_t* outputptr) 
{
    uint16_t read;
    if (AppSdCardAudioData.player.decodeDataSize == 0) 
    {          
        if (DECODER_Decode(ptr, playerDiskDataSize, &read, outputptr, 
                &AppSdCardAudioData.player.decodeDataSize) == true) 
        {                      
            if (read != 0) 
            {
                playerDiskDataSize -= read;
            }
            return true;
        } 
        else 
        {
            return false;
        }
    } 
    else 
    {
        AppSdCardAudioData.player.nextTrack = true;
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
APP_SDCARD_AUDIO_DECODER APP_SDCARD_AUDIO_Player_GetCurrentFileType(int8_t *ext)
{      
    if (( ext[0] == 'M' && ext[1] == 'P' && ext[2] == '3' )||
        ( ext[0] == 'm' && ext[1] == 'p' && ext[2] == '3' ))
    {
        return APP_SDCARD_AUDIO_DECODER_MP3;
    }
    if (( ext[0] == 'W' && ext[1] == 'A' && ext[2] == 'V' )||
        ( ext[0] == 'w' && ext[1] == 'a' && ext[2] == 'v' ))
    {
        return APP_SDCARD_AUDIO_DECODER_WAV;
    } 
    return APP_SDCARD_AUDIO_DECODER_UNKNOWN;
}

////////////////////////////////////////////////////////////////////////////////
bool DECODER_EventHandler ( DECODER_EVENT event, uint32_t data )
{
    switch ( event )
    {
        case DECODER_EVENT_TAG_ARTIST:
          //APP_PlayerEventHandler ( PLAYER_EVENT_TAG_ARTIST, data );
            return ( true );

        case DECODER_EVENT_TAG_ALBUM:
           //APP_PlayerEventHandler ( PLAYER_EVENT_TAG_ALBUM, data );
            return ( true );

        case DECODER_EVENT_TAG_TITLE:
          // APP_PlayerEventHandler ( PLAYER_EVENT_TAG_TITLE, data );
            return ( true );

        case DECODER_EVENT_STREAM_START:          
//            playerStreaming = true;
            playerFileStreamStart = APP_SDCARD_AUDIO_Card_GetFilePosition (AppSdCardAudioData.player.fileHandle);
            if ( playerMoveToEnd )
            {
                int position;                  
                position = APP_SDCARD_AUDIO_Card_GetFileSize (AppSdCardAudioData.player.fileHandle) - playerFileAdvanceStep;
                APP_SDCARD_AUDIO_Card_SetFilePosition (AppSdCardAudioData.player.fileHandle,  position);
                
                playerMoveToEnd = false;
            }
            //MP3 total time and bit rate calculation 
//            if(appData.currentStreamType == APP_STREAM_MP3){
//                uint32_t filesize = APP_SDCARD_AUDIO_Card_GetFileSize (appData.fileHandle);
//                if (( playerTrackTotalTime == 0 ) && ( playerBitrate != 0 ))
//                {
//                    // playerBitrate in Kb/s, file size in bytes.
//                    // thus, track length = file_size/byterate = (TotalFileSize - MP3HeaderSize)/(playerBitrate*1000/8)
//                    // = ( filesize - playerFileStreamStart ) / 125 / playerBitrate; 
//                    playerTrackTotalTime = ( filesize - playerFileStreamStart ) / 125 / playerBitrate; 
//                }
//                if (( playerBitrate == 0 ) && ( playerTrackTotalTime != 0 ))
//                {
//                    playerBitrate = ( filesize - playerFileStreamStart ) / 125 / playerTrackTotalTime;
//                }
//                APP_PlayerEventHandler ( PLAYER_EVENT_BITRATE, playerBitrate );
//                APP_PlayerEventHandler ( PLAYER_EVENT_TRACK_TOTAL_TIME, playerTrackTotalTime );
            
//            }
            return ( true );

        case DECODER_EVENT_SAMPLERATE:
            if(AppSdCardAudioData.codec.handle != DRV_HANDLE_INVALID)
            {
                DRV_CODEC_SamplingRateSet(AppSdCardAudioData.codec.handle, data);
            }          
            //Player_SetSamplingRate(data);
            //APP_PlayerEventHandler ( PLAYER_EVENT_SAMPLERATE, data );
            return ( true );
        
        case DECODER_EVENT_BITRATE:
            playerBitrate = data;
            //APP_PlayerEventHandler ( PLAYER_EVENT_BITRATE, data );
            return ( true );

        case DECODER_EVENT_TRACK_TIME:
            playerTrackTotalTime = data;          
            //APP_PlayerEventHandler ( PLAYER_EVENT_TRACK_TOTAL_TIME, playerTrackTotalTime );
            return ( true );

        case DECODER_INITIALIZATION_ERROR:
            // Todo: show error messages
            APP_PlayerCommand(APP_SDCARD_AUDIO_PLAYER_COMMAND_NEXT_FILE);
            break;
    }
    return ( false );
}

////////////////////////////////////////////////////////////////////////////////
bool APP_PlayerCommand ( APP_SDCARD_AUDIO_PLAYER_COMMAND cmd )
{       
    // If there is no audio files, return
    if(AppSdCardAudioData.player.state == APP_SDCARD_AUDIO_PLAYER_STATE_NO_FILE)
        return true;

    switch ( cmd )
    {

#if 0        
        case APP_SDCARD_AUDIO_PLAYER_COMMAND_STOP:
            APP_SDCARD_AUDIO_Card_ReopenTrack ();
            playerPlay = false;
            break;

        case APP_SDCARD_AUDIO_PLAYER_COMMAND_PLAY:
            playerPlay = true;
            Player_MuteOff();

            break;

        case APP_SDCARD_AUDIO_PLAYER_COMMAND_PAUSE:
            playerPlay = false;
            Player_MuteOn();
            break;

        case APP_SDCARD_AUDIO_PLAYER_COMMAND_PLAY_PAUSE:
            if ( playerPlay == false )
            {
                playerPlay = true;
                Player_MuteOff();
            }
            else
            {
                playerPlay = false;
                Player_MuteOn();
            }
            break;
#endif
        case APP_SDCARD_AUDIO_PLAYER_COMMAND_NEXT_FILE:
            AppSdCardAudioData.player.nextTrack = true;            
            
            APP_SDCARD_AUDIO_Card_CloseFile(AppSdCardAudioData.player.fileHandle);
            AppSdCardAudioData.player.state = APP_SDCARD_AUDIO_PLAYER_STATE_RUNNING;
            
            APP_SDCARD_AUDIO_Card_NextTrack ();
            break;

        case APP_SDCARD_AUDIO_PLAYER_COMMAND_PREV_FILE:
            AppSdCardAudioData.player.nextTrack = false;            

            AppSdCardAudioData.player.state = APP_SDCARD_AUDIO_PLAYER_STATE_RUNNING;

            if ( playerTrackPlayTime < 5 )
            {
                APP_SDCARD_AUDIO_Card_CloseFile(AppSdCardAudioData.player.fileHandle);                
                APP_SDCARD_AUDIO_Card_PreviousTrack();
            }
            else
            {
                APP_SDCARD_AUDIO_Card_CloseFile(AppSdCardAudioData.player.fileHandle);                
                APP_SDCARD_AUDIO_Card_ReopenTrack ();
            }
            break;

        case APP_SDCARD_AUDIO_PLAYER_COMMAND_NONE:
        default:
            break;

    }
    return ( true );
}

uint32_t flag_enter1=0;
/**********************************************************
 * Application CODEC buffer Event handler.
 ***********************************************************/
void APP_SDCARD_AUDIO_BufferEventHandler(DRV_CODEC_BUFFER_EVENT event,
        DRV_CODEC_BUFFER_HANDLE handle, uintptr_t context )
{              
    switch(event)
    {
        case DRV_CODEC_BUFFER_EVENT_COMPLETE:
        {                
            
            if(AppDataAudioPlayerPtr->state == APP_SDCARD_AUDIO_PLAYER_STATE_RUNNING)
            {
                int8_t readIdx = AppDataAudioPlayerPtr->readIdx;
                if(AppDataAudioPlayerPtr->buffer[readIdx].decoded && !AppDataAudioPlayerPtr->buffer[readIdx].inUse)
                {  
                    flag_enter1++;
                    DRV_CODEC_BufferAddWrite(AppSdCardAudioData.codec.handle, 
                        &AppSdCardAudioData.codec.writeBufHandle,
                        AppDataAudioPlayerPtr->buffer[readIdx].buffer,
                        AppDataAudioPlayerPtr->buffer[readIdx].bufferSize);                    
                    
                    if(AppSdCardAudioData.codec.writeBufHandle != DRV_CODEC_BUFFER_HANDLE_INVALID)
                    {                        
                        AppDataAudioPlayerPtr->buffer[readIdx].writeHandler = AppSdCardAudioData.codec.writeBufHandle;
                        AppDataAudioPlayerPtr->buffer[readIdx].inUse = true;
                        AppDataAudioPlayerPtr->readIdx = APP_SDCARD_AUDIO_GetNextIdxInOutputBuffer(readIdx);            
                    }                    
                }
                /*else
                {
                    // underrun
                    Nop();
                }*/

            }
            APP_SDCARD_AUDIO_ClearBufferFlags(handle);                                                                    
            
        }
        break;
        case DRV_CODEC_BUFFER_EVENT_ERROR:
        {
        } break;

        case DRV_CODEC_BUFFER_EVENT_ABORT:
        {
        } break;
    }
}





/*******************************************************************************
 * Application SD CARD Functions
 ******************************************************************************/

void APP_SDCARD_AUDIO_Card_Initialize ( void )
{
    AppDataAudioCardRootNode.fstat.fattrib = SYS_FS_ATTR_DIR;
    strcpy(AppDataAudioCardRootNode.path, APP_SDCARD_AUDIO_CARD_MOUNT_NAME);
    AppDataAudioCardData.state = APP_SDCARD_AUDIO_CARD_STATE_INIT;                                        
}

////////////////////////////////////////////////////////////////////////////////
int32_t APP_SDCARD_AUDIO_Card_GetCurrentFilePosition(void)
{
    return SYS_FS_FileTell(AppDataAudioPlayerPtr->fileHandle);
}

////////////////////////////////////////////////////////////////////////////////
uint32_t APP_SDCARD_AUDIO_Card_ReadCurrentFile(uint8_t *ptr, size_t readSize)
{
    uint32_t ret = 0;
    AppDataAudioPlayerPtr->nBytesRead = 
            SYS_FS_FileRead(AppDataAudioPlayerPtr->fileHandle,ptr,readSize);
    if ((AppDataAudioPlayerPtr->nBytesRead != readSize))
    {
        ret = 0;
        AppDataAudioCardTotalBytesRead = 0;
    }
    else
    {
        AppDataAudioPlayerPtr->nBytesRead =0;
        return readSize;
    }    
    return ret;
}

////////////////////////////////////////////////////////////////////////////////
int32_t APP_SDCARD_AUDIO_Card_GetFilePosition (SYS_FS_HANDLE fileHandle )
{
    int32_t tell;
    tell = SYS_FS_FileTell(fileHandle);
    return ( tell );
}

////////////////////////////////////////////////////////////////////////////////
uint32_t APP_SDCARD_AUDIO_Card_GetFileSize(SYS_FS_HANDLE fileHandle)
{
    AppDataAudioPlayerPtr->fileSize = SYS_FS_FileSize( fileHandle );

    if(AppDataAudioPlayerPtr->fileSize == -1)
    {
        /* Reading file size was a failure */
        return (uint32_t) SYS_FS_HANDLE_INVALID;
    }
    else
    {
        return (uint32_t)AppDataAudioPlayerPtr->fileSize;
    }
}

////////////////////////////////////////////////////////////////////////////////
bool APP_SDCARD_AUDIO_Card_SetFilePosition (SYS_FS_HANDLE fileHandle, int32_t pos )
{
    int status;
    status = SYS_FS_FileSeek(fileHandle, pos, SYS_FS_SEEK_SET);
    if( status == pos )
    {
        return true;
    }
    return false;
}

uint32_t loop_count;
////////////////////////////////////////////////////////////////////////////////
bool APP_SDCARD_AUDIO_Card_FillBuffer(uint8_t *ptr)
{
    if ((AppDataAudioCardTotalBytesRead < AppDataAudioPlayerPtr->currentFilesize)) 
    {
        if ((AppDataAudioPlayerPtr->readbyte_flag)) 
        {
            //bool FileEnd = false;            
            AppDataAudioPlayerPtr->nBytesRead = 
                SYS_FS_FileRead(AppDataAudioPlayerPtr->fileHandle, ptr, 
                AppDataAudioPlayerPtr->readBytes);              
            //FileEnd = APP_SDCARD_AUDIO_Card_EndOfFile();
            if ((AppDataAudioPlayerPtr->nBytesRead == -1) /* || ( FileEnd == true) */) 
            {
                AppDataAudioCardTotalBytesRead = 0;
                SYS_FS_FileClose(AppDataAudioPlayerPtr->fileHandle);
                return false;
            }
            else if (APP_SDCARD_AUDIO_Card_EndOfFile() == true)
            {
                if(AppDataAudioPlayerPtr->nBytesRead > 0 && 
                        AppDataAudioPlayerPtr->nBytesRead < AppDataAudioPlayerPtr->readBytes)
                {
                    AppDataAudioCardTotalBytesRead += AppDataAudioPlayerPtr->nBytesRead;
                    playerDiskDataSize += AppDataAudioPlayerPtr->nBytesRead;
                    AppDataAudioPlayerPtr->nBytesRead = 0;                    
                }
                else
                {
                    AppDataAudioCardTotalBytesRead = 0;
                    SYS_FS_FileClose(AppDataAudioPlayerPtr->fileHandle);
                    return false;                    
                }
            }
            else 
            {
                AppDataAudioCardTotalBytesRead += AppDataAudioPlayerPtr->nBytesRead;
                playerDiskDataSize += AppDataAudioPlayerPtr->nBytesRead;
                AppDataAudioPlayerPtr->nBytesRead = 0;
            }
        }
    } 
    else 
    {
        AppDataAudioCardTotalBytesRead = 0;
        return false;
    }
    return true;
}


////////////////////////////////////////////////////////////////////////////////
bool APP_SDCARD_AUDIO_Card_OpenTrack ( const int8_t *fname )
{
    AppDataAudioPlayerPtr->fileHandle = APP_SDCARD_AUDIO_Card_OpenFile(fname);

    if ( AppDataAudioPlayerPtr->fileHandle != SYS_FS_HANDLE_INVALID )
    {        
        if(APP_SDCARD_AUDIO_Card_FileStatus(fname) == true)
        {
            AppDataAudioPlayerPtr->currentFilesize = 
                APP_SDCARD_AUDIO_Card_GetFileSize(AppDataAudioPlayerPtr->fileHandle);
            APP_SDCARD_AUDIO_Card_EventHandler ( APP_SDCARD_AUDIO_CARD_EVENT_TRACK_CHANGED, 
                    AppDataAudioPlayerPtr->diskCurrentFile, AppDataAudioPlayerPtr->fileHandle );            
            AppDataAudioCardTotalBytesRead = 
                    APP_SDCARD_AUDIO_Card_GetFilePosition(AppDataAudioPlayerPtr->fileHandle);
            return true;
        }else
        {
              return false;
        }        
    }
    else
    {
        APP_SDCARD_AUDIO_Card_EventHandler ( APP_SDCARD_AUDIO_CARD_EVENT_FILE_OPEN_ERROR, 
                AppDataAudioPlayerPtr->diskCurrentFile,AppDataAudioPlayerPtr->fileHandle );        
        return ( false );
    }    
    return true;
}

////////////////////////////////////////////////////////////////////////////////
bool APP_SDCARD_AUDIO_Card_FileStatus(const int8_t* fname)
{
     if( SYS_FS_FileStat((const char*)fname, &(AppDataAudioPlayerPtr->fileStatus)) == SYS_FS_RES_FAILURE )
     {
             return false;
     }
     else
     {
         // Read name
         bool stat = APP_SDCARD_AUDIO_Card_FileNameGet(AppDataAudioPlayerPtr->fileHandle, 
                 (int8_t*)AppDataAudioPlayerPtr->fileStatus.lfname);
        /* Read file size */
         return stat;
     }
     return true;
}

////////////////////////////////////////////////////////////////////////////////
bool APP_SDCARD_AUDIO_Card_FileNameGet(SYS_FS_HANDLE handle, int8_t* cName)
{
   bool stat = SYS_FS_FileNameGet(handle, (uint8_t*) cName, 255);
   return stat;
}

bool APP_SDCARD_AUDIO_Card_EndOfFile(void)
{    
    if(SYS_FS_FileEOF( AppDataAudioPlayerPtr->fileHandle ) == false )
    {
        return false;
    }
    else
    {
        return true;
    }
}

////////////////////////////////////////////////////////////////////////////////
SYS_FS_HANDLE APP_SDCARD_AUDIO_Card_OpenFile ( const int8_t *fname )
{
    SYS_FS_HANDLE fileHandle;
    if ( AppDataAudioCardData.state != APP_SDCARD_AUDIO_CARD_STATE_RUNNING && 
            AppDataAudioCardData.state != APP_SDCARD_AUDIO_CARD_STATE_NO_AUDIO_FILES 
            && AppDataAudioCardData.state != APP_SDCARD_AUDIO_CARD_STATE_SCANNING)
    {
        return ( SYS_FS_HANDLE_INVALID );
    }

    AppDataAudioCardTotalBytesRead = 0;
    playerDiskDataSize=0;

    fileHandle = SYS_FS_FileOpen((const char*)fname, (SYS_FS_FILE_OPEN_READ_PLUS));
    if(fileHandle == SYS_FS_HANDLE_INVALID)     
    {
        return SYS_FS_HANDLE_INVALID; 
    }
    else
    {
        return fileHandle;
    }
}


bool FileListAvailable;
////////////////////////////////////////////////////////////////////////////////
void APP_SDCARD_AUDIO_Card_Tasks(void)
{    
    
#if 0    
    if(appDataPtr->state==APP_STATE_DEVICE_CONNECTED)
    {
        if (AppDataAudioCardData.state == APP_SDCARD_AUDIO_CARD_STATE_REMOVED )
        {
            AppDataAudioCardData.state = APP_SDCARD_AUDIO_CARD_STATE_INIT;
            APP_SDCARD_AUDIO_Card_EventHandler ( APP_SDCARD_AUDIO_CARD_EVENT_INSERTED, 
                    0 ,appDataPtr->fileHandle);
        }
    }
    else
    {
        if ( AppDataAudioCardData.state != APP_SDCARD_AUDIO_CARD_STATE_REMOVED )
        {
            AppDataAudioCardData.state = APP_SDCARD_AUDIO_CARD_STATE_REMOVED;
            APP_SDCARD_AUDIO_Card_EventHandler ( APP_SDCARD_AUDIO_CARD_EVENT_REMOVED, 
                    0 ,appDataPtr->fileHandle);
        }    
    }
#endif    
    switch ( AppDataAudioCardData.state )
    {
        //SYED case DISK_STATE_HALT:
        //    break;

        //SYED case APP_SDCARD_AUDIO_CARD_STATE_REMOVED:
        //    appDataPtr->isDiskMounted = false;
        //    break;

        case APP_SDCARD_AUDIO_CARD_STATE_INIT:
            {
                AppDataAudioCardData.state = APP_SDCARD_AUDIO_CARD_STATE_SCANNING;

                AppDataAudioPlayerPtr->totalAudioFiles = 0;
                AppDataAudioPlayerPtr->currentSongIdx  = 0;
                AppDataAudioPlayerPtr->nextSongIdx     = 0;
                AppDataAudioPlayerPtr->previousSongIdx = 0;
                
                AppDataAudioPlayerPtr->isDiskMounted = true;
                APP_SDCARD_AUDIO_Card_EventHandler ( APP_SDCARD_AUDIO_CARD_EVENT_SCANNING_STARTED, 
                        0, AppDataAudioPlayerPtr->fileHandle);                
                

                APP_SDCARD_AUDIO_Card_TraverseAllFiles(AppDataAudioCardRootNode, true);
                if(AppDataAudioPlayerPtr->totalAudioFiles == 0){
                    // No Audio File
                    AppDataAudioCardData.state = APP_SDCARD_AUDIO_CARD_STATE_NO_AUDIO_FILES;
                    AppDataAudioPlayerPtr->isSongListAvailable = false;
                }
                else
                {
                    AppDataAudioPlayerPtr->isSongListAvailable = true;
                    AppDataAudioPlayerPtr->currentSongIdx = 0;
                    AppDataAudioPlayerPtr->state = APP_SDCARD_AUDIO_PLAYER_STATE_RUNNING;
                    
                    if(APP_SDCARD_AUDIO_Card_OpenTrack(AppSdCardAudioCardFilesTable[0].path))
                    {
                        //APP_PlayerEventHandler ( PLAYER_EVENT_READY, appDataPtr->totalAudioFiles );
                        playerPlay = true;
                        DRV_CODEC_MuteOff(AppSdCardAudioData.codec.handle);                                                     
                    }
                }
            }
            break;

        case APP_SDCARD_AUDIO_CARD_STATE_SCANNING:
            break;
           
        case APP_SDCARD_AUDIO_CARD_STATE_RUNNING:
            break;

        case APP_SDCARD_AUDIO_CARD_STATE_NO_AUDIO_FILES:
            AppDataAudioPlayerPtr->noAudioFiles = true;
            AppDataAudioPlayerPtr->state = APP_SDCARD_AUDIO_PLAYER_STATE_NO_FILE;            
            //APP_PlayerEventHandler(PLAYER_EVENT_TAG_TITLE, (uint32_t)"No Available Audio Files" );
            break;
        default:
            break;
    }
}

////////////////////////////////////////////////////////////////////////////////
bool APP_SDCARD_AUDIO_Card_EventHandler ( APP_SDCARD_AUDIO_CARD_EVENT event, 
        uint32_t variable,SYS_FS_HANDLE fileHandle)
{
    switch ( event )
    {
        case APP_SDCARD_AUDIO_CARD_EVENT_REMOVED:
        {
            APP_SDCARD_AUDIO_Player_ReInitialize();
            AppDataAudioPlayerPtr->state = APP_SDCARD_AUDIO_PLAYER_STATE_NO_MEDIA;
            //APP_PlayerEventHandler ( PLAYER_EVENT_DISK_REMOVED, 0 );
            return ( true );
        }

        case APP_SDCARD_AUDIO_CARD_EVENT_INSERTED:
        {
            AppDataAudioPlayerPtr->state = APP_SDCARD_AUDIO_PLAYER_STATE_WAITING;
            //APP_PlayerEventHandler ( PLAYER_EVENT_DISK_INSERTED, 0 );
            return ( true );
        }

        case APP_SDCARD_AUDIO_CARD_EVENT_SCANNING_STARTED:
        {
            AppDataAudioPlayerPtr->state = APP_SDCARD_AUDIO_PLAYER_STATE_SCANNING;
            //APP_PlayerEventHandler ( PLAYER_EVENT_SCANNING_STARTED, 0 );
            return ( true );
        }

        case APP_SDCARD_AUDIO_CARD_EVENT_SCANNING_FINISHED:
        {
            
//            if (( appData.diskTotalFiles > 0 )) //&&(appData.diskTotalDirs>0)
//            {
//               APP_PlayerEventHandler ( PLAYER_EVENT_SCANNING_FINISHED, 0 );
//               
//               APP_SDCARD_AUDIO_Card_FirstTrack ();
//               appData.state = APP_SDCARD_AUDIO_PLAYER_STATE_RUNNING;
//            }
//            else
//            {
//                APP_PlayerEventHandler ( PLAYER_EVENT_NO_FILES_FOUND, 0 );
//                appData.state = APP_SDCARD_AUDIO_PLAYER_STATE_HALT;
//            }

            return ( true );
        }

        case APP_SDCARD_AUDIO_CARD_EVENT_TRACK_CHANGED:
        {
            //APP_PlayerEventHandler ( PLAYER_EVENT_TRACK_CHANGED, appData.currentSongIdx+1);
            APP_SDCARD_AUDIO_Player_Reset();
            AppDataAudioPlayerPtr->state = APP_SDCARD_AUDIO_PLAYER_STATE_RUNNING;
            return ( true );
        }

        case APP_SDCARD_AUDIO_CARD_EVENT_FILE_OPEN_ERROR:
        case APP_SDCARD_AUDIO_CARD_EVENT_END_OF_FILE:
        {            
            APP_SDCARD_AUDIO_Card_CloseFile(AppDataAudioPlayerPtr->fileHandle);            
            APP_SDCARD_AUDIO_Card_NextTrack();
            return ( true );
        }
    }
    return ( false );
}

////////////////////////////////////////////////////////////////////////////////
 bool APP_SDCARD_AUDIO_Card_CloseFile (SYS_FS_HANDLE fileHandle )
{
    SYS_FS_RESULT ret;
    if ( fileHandle != SYS_FS_HANDLE_INVALID )
    {
        ret = SYS_FS_FileClose ( fileHandle );
        if(ret == SYS_FS_RES_SUCCESS)
        {
            return true;
        }
    }
    return false;
}

//////////////////////////////////////////////////////////////////////////////// 
bool APP_SDCARD_AUDIO_Card_NextTrack(void)
{
    if(AppDataAudioPlayerPtr->currentSongIdx == AppDataAudioPlayerPtr->totalAudioFiles-1)
    {
        AppDataAudioPlayerPtr->nextSongIdx = 0;
    }
    else
    {
        if(AppDataAudioPlayerPtr->isRandomSongSet == true)
        {
            AppDataAudioPlayerPtr->isRandomSongSet = false;
            AppDataAudioPlayerPtr->nextSongIdx = AppDataAudioPlayerPtr->randomSongIdx;                         
        }
        else
        {
            AppDataAudioPlayerPtr->nextSongIdx = AppDataAudioPlayerPtr->currentSongIdx + 1;            
        }
    }
    
    AppDataAudioPlayerPtr->currentSongIdx = AppDataAudioPlayerPtr->nextSongIdx;

    if (APP_SDCARD_AUDIO_Card_OpenTrack(AppSdCardAudioCardFilesTable
            [AppDataAudioPlayerPtr->currentSongIdx].path) == true)
    {
        return true;
    }
    else
        return false;
} 
 
//////////////////////////////////////////////////////////////////////////////// 
bool APP_SDCARD_AUDIO_Card_PreviousTrack(void)
{
    AppDataAudioPlayerPtr->previousSongIdx = (AppDataAudioPlayerPtr->currentSongIdx ? 
        (AppDataAudioPlayerPtr->currentSongIdx - 1):(AppDataAudioPlayerPtr->totalAudioFiles - 1));
    
    AppDataAudioPlayerPtr->currentSongIdx = AppDataAudioPlayerPtr->previousSongIdx;
    if (APP_SDCARD_AUDIO_Card_OpenTrack(AppSdCardAudioCardFilesTable
            [AppDataAudioPlayerPtr->currentSongIdx].path) == true)
    {
        return true;
    }
    else
        return false;
}

////////////////////////////////////////////////////////////////////////////////
bool APP_SDCARD_AUDIO_Card_ReopenTrack(void)
{
    if (APP_SDCARD_AUDIO_Card_OpenTrack(AppSdCardAudioCardFilesTable
            [AppDataAudioPlayerPtr->currentSongIdx].path) == true)
    {
        return true;
    }
    else
        return false;
}

////////////////////////////////////////////////////////////////////////////////
void APP_SDCARD_AUDIO_Card_TraverseAllFiles(APP_SDCARD_AUDIO_CARD_FILE_NODE node, 
        bool isRoot)
{
     int i;
     SYS_FS_RESULT ret;
     uint8_t totalDir = 0;
     SYS_FS_FSTAT dirTable[APP_SDCARD_AUDIO_CARD_MAX_DIRS];
     
     ret = APP_SDCARD_AUDIO_Card_FS_ReadDirFlat((const int8_t*)node.path, &totalDir, dirTable, isRoot);

     if(ret == SYS_FS_RES_FAILURE)
     {
         return;
     }

     APP_SDCARD_AUDIO_CARD_FILE_NODE child_node;     
     for(i = 0; i < totalDir; i++)
     {
         
         child_node.fstat = dirTable[i];         
         strcpy(child_node.path, node.path);
         if(!isRoot)
         {
             strcat(child_node.path, "/");
         }
         strcat(child_node.path, child_node.fstat.fname);
         APP_SDCARD_AUDIO_Card_TraverseAllFiles(child_node, false);         
     }     
     return;
 }

////////////////////////////////////////////////////////////////////////////////
SYS_FS_RESULT APP_SDCARD_AUDIO_Card_FS_ReadDirFlat(const int8_t *fname, 
        uint8_t *dir_count, SYS_FS_FSTAT * dir_table, bool isRoot)
{
    SYS_FS_RESULT ret;
    AppDataAudioCardData.dirHandle = SYS_FS_DirOpen((const char*)fname);
    if(AppDataAudioCardData.dirHandle == SYS_FS_HANDLE_INVALID)
    {
        return SYS_FS_RES_FAILURE;
    }
    *dir_count = 0;
    
    do
     {
         if(AppDataAudioPlayerPtr->totalAudioFiles < APP_SDCARD_AUDIO_CARD_MAX_FILES)
         {
             ret = SYS_FS_DirRead(AppDataAudioCardData.dirHandle,&AppDataAudioCardData.dirstat);             
             // End of this directory
             if(AppDataAudioCardData.dirstat.fname[0] == '\0')
             {
                 break;
             }
             if(ret!= SYS_FS_RES_FAILURE)
             {
                //if(AppDataAudioCardData.dirstat.fattrib == SYS_FS_ATTR_ARC )                 
                 if(AppDataAudioCardData.dirstat.fattrib != SYS_FS_ATTR_DIR)  
                 {                     
                    if(APP_SDCARD_AUDIO_Card_isSupportedAudioFile((int8_t*)AppDataAudioCardData.dirstat.fname))
                    {
                        strcpy((char*)AppSdCardAudioCardFilesTable
                                [AppDataAudioPlayerPtr->totalAudioFiles].path, (const char*)fname);
                        if(!isRoot)
                        {
                            strcat((char*)AppSdCardAudioCardFilesTable
                                    [AppDataAudioPlayerPtr->totalAudioFiles].path, "/");
                        }
                        strcat((char*)AppSdCardAudioCardFilesTable
                                [AppDataAudioPlayerPtr->totalAudioFiles].path,
                                AppDataAudioCardData.dirstat.fname);
                        
                        (AppDataAudioPlayerPtr->totalAudioFiles)++;
                    }
                     
                 }else if(AppDataAudioCardData.dirstat.fattrib == SYS_FS_ATTR_DIR 
                         && AppDataAudioCardData.dirstat.fname[0] != '.') // Skip ".\" and "..\" directories
                 {
                     if(*dir_count < APP_SDCARD_AUDIO_CARD_MAX_DIRS)
                     {
                         dir_table[*dir_count]=AppDataAudioCardData.dirstat;
                         (*dir_count)++;
                     }
                 }
             }
         }
         else
         {
             ret = SYS_FS_RES_FAILURE;
             break;
         }
     }while(ret==SYS_FS_RES_SUCCESS);
     
     SYS_FS_DirClose(AppDataAudioCardData.dirHandle);
     return ret;
}

////////////////////////////////////////////////////////////////////////////////
bool APP_SDCARD_AUDIO_Card_isSupportedAudioFile(int8_t *name)
{
    int i = 0;
    do
    {
       i++;
    }while(name[i]!= '.' && name[i] != '\0');
    
    if(name[i] == '\0')
        return false;
    
    if(AppSdCardAudioData.player.MP3_decoder_enabled)
    {
        if((name[i+1] == 'm' && name[i+2] == 'p' && name[i+3] == '3') || 
          (name[i+1] == 'M' && name[i+2] == 'P' && name[i+3] == '3'))
            return true;
    }
    
    if(AppSdCardAudioData.player.WAV_decoder_enabled){
        if((name[i+1] == 'w' && name[i+2] == 'a' && name[i+3] == 'v') || 
           (name[i+1] == 'W' && name[i+2] == 'A' && name[i+3] == 'V'))
            return true;
    }

    return false;
}


APP_SDCARD_AUDIO_CARD_FILE_PATH *APP_SDCARD_AUDIO_GetFileTablePointer(void)
{
    return &AppSdCardAudioCardFilesTable[0];
}


void APP_SDCARD_AUDIO_RandomTrackSet(uint16_t trackId)
{
    if(AppSdCardAudioData.player.currentSongIdx != trackId)
    {
        AppSdCardAudioData.player.isRandomSongSet = true;
        AppSdCardAudioData.player.randomSongIdx = trackId;
        AppSdCardAudioData.player.nextTrack = true;
        AppSdCardAudioData.player.state = APP_SDCARD_AUDIO_PLAYER_STATE_TRACK_CHANGE;        
    }
}


void APP_SDCARD_AUDIO_NextTrackSet(void)
{
    AppSdCardAudioData.player.nextTrack = true;
    AppSdCardAudioData.player.state = APP_SDCARD_AUDIO_PLAYER_STATE_TRACK_CHANGE;     
}


bool APP_SDCARD_AUDIO_isSonglistAvailable(void)
{
    return AppSdCardAudioData.player.isSongListAvailable;
}

void APP_SDCARD_AUDIO_MuteOn(void)
{
    DRV_CODEC_MuteOn(AppSdCardAudioData.codec.handle);    
}

void APP_SDCARD_AUDIO_MuteOff(void)
{
    DRV_CODEC_MuteOff(AppSdCardAudioData.codec.handle);        
}

uint8_t APP_SDCARD_AUDIO_VolumeGet(void)
{
    return DRV_CODEC_VolumeGet(AppSdCardAudioData.codec.handle, DRV_CODEC_CHANNEL_LEFT_RIGHT);         
}

void APP_SDCARD_AUDIO_VolumeSet(uint8_t volume)
{
    DRV_CODEC_VolumeSet(AppSdCardAudioData.codec.handle, DRV_CODEC_CHANNEL_LEFT_RIGHT, volume);         
}

uint16_t APP_SDCARD_AUDIO_FileCountGet(void)
{
    return AppDataAudioPlayerPtr->totalAudioFiles;
}

uint16_t APP_SDCARD_AUDIO_CurrentTrackIdGet(void)
{
    return AppSdCardAudioData.player.currentSongIdx;
}

// Event Processing Technique. Event is received when operation is done.

