/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_tone_textfile_sdcard.c

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
Copyright (c) 2015-2016 released Microchip Technology Inc.  All rights reserved.

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
// DOM-IGNORE-END

#include "app.h"
#include "app_tone_textfile_sdcard.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Variable Definitions
// *****************************************************************************
// *****************************************************************************
DRV_I2S_DATA16 __attribute__((coherent)) __attribute__((aligned(16)))  appToneTextFileSdcardToneBuffer[120];
APP_TONE_TEXTFILE_SDCARD_DATA appToneTextfileSdcardData; 
uint32_t appSdCardAudioContext;

/* This is initialization function */

void APP_TONE_TEXTFILE_SDCARD_Initialize(void)
{
    appToneTextfileSdcardData.state = APP_TONE_TEXTFILE_SDCARD_STATE_CODEC_OPEN;    
    appToneTextfileSdcardData.currentFilePosition = 0;
    appToneTextfileSdcardData.codec.context = (uintptr_t)&appSdCardAudioContext;
    appToneTextfileSdcardData.codec.bufferHandler = (DRV_CODEC_BUFFER_EVENT_HANDLER) APP_TONE_TEXTFILE_SDCARD_BufferEventHandler;
    appToneTextfileSdcardData.codec.txbufferObject = (uint8_t *) appToneTextFileSdcardToneBuffer;
    appToneTextfileSdcardData.codec.bufferSize = 0;            
    appToneTextfileSdcardData.textParser.nElements = 0;    
}

static bool APP_TONE_TEXTFILE_SDCARD_Read_SDCard( 
    const DRV_HANDLE handle,
    uint8_t* const pBuffer,
    const uint16_t requestedBytes,
    uint16_t* const pNumBytesRead 
)
{    
    uint32_t nBytesRead = 0;
    bool isSuccess = true;        
    
    /* Read audio text data from SD card*/
    nBytesRead = SYS_FS_FileRead( handle, (void*)pBuffer, requestedBytes );	
        
    if (-1 == (int32_t)nBytesRead)
    {                        
        if ( false == SYS_FS_FileEOF(handle))
        {
            /* We have encountered a file read error */
            isSuccess = false;         
        }                            
    }               
        
    *pNumBytesRead = (uint16_t)nBytesRead;
    
    return isSuccess;
}

static uint16_t APP_TONE_TEXTFILE_SDCARD_Parse_Audio_Text_Data(
    const uint8_t* const pInBuffer, 
    int16_t* const pOutBuffer,
    const uint16_t nInputBytes, 
    uint16_t* const pNumBytesParsed)
{
    uint16_t inBufferIndex = 0;
	uint16_t outBufferIndex = 0;
	uint16_t nBytesParsed = 0;		
	int8_t asciiStr[7] = {0};
	uint8_t asciiStrIndex = 0;

	while (inBufferIndex < nInputBytes)
	{
		if ((pInBuffer[inBufferIndex] >= '0' && pInBuffer[inBufferIndex] <= '9') || ('-' == pInBuffer[inBufferIndex]))
		{			
			/* Allow for 5 characters - for 16-bit audio data, plus '-' sign, making it a total of maximum 6 characters*/
			if (asciiStrIndex < 6)
			{
				asciiStr[asciiStrIndex++] = pInBuffer[inBufferIndex];
			}			
		}
		else
		{
			if (',' == pInBuffer[inBufferIndex])
			{
				nBytesParsed = inBufferIndex + 1;

				/* process only valid strings. Valid strings are less than equal to 6 characters */
				if (6 >= asciiStrIndex)
				{
					asciiStr[asciiStrIndex] = '\0';
					pOutBuffer[outBufferIndex++] = atoi((const char*)asciiStr);
					asciiStrIndex = 0;
				}
				else
				{
					/* discard */
					asciiStrIndex = 0;
				}
			}			
		}
		inBufferIndex++;
	}
	
	/* Return number of bytes actually decoded from the input buffer*/
	*pNumBytesParsed = nBytesParsed;

	/* Return total number of audio data bytes in the output buffer*/
	return (outBufferIndex * 2);
}

/* This is the task routine for this lab */

void APP_TONE_TEXTFILE_SDCARD_Tasks(void)
{
    if (APP_MODE_SD_CARD_PLAYBACK == APP_GetMode())
    {
        switch(appToneTextfileSdcardData.state)
        {
            case APP_TONE_TEXTFILE_SDCARD_STATE_CODEC_OPEN:
            {
                /* A client opens the driver object to get an Handle */
                appToneTextfileSdcardData.codec.handle = DRV_CODEC_Open(DRV_CODEC_INDEX_0, 
                        DRV_IO_INTENT_WRITE | DRV_IO_INTENT_EXCLUSIVE);
                if(appToneTextfileSdcardData.codec.handle != DRV_HANDLE_INVALID)
                {
                    appToneTextfileSdcardData.state = APP_TONE_TEXTFILE_SDCARD_STATE_CODEC_SET_BUFFER_HANDLER;
                }
                else
                {
                    /* Got an Invalid Handle.  Wait for AK4384 to Initialize */
                    ;
                }
            }
            break;

            /* Set a handler for the audio buffer completion event */
            case APP_TONE_TEXTFILE_SDCARD_STATE_CODEC_SET_BUFFER_HANDLER:
            {
                DRV_CODEC_BufferEventHandlerSet(appToneTextfileSdcardData.codec.handle,
                        appToneTextfileSdcardData.codec.bufferHandler,
                        appToneTextfileSdcardData.codec.context);
                appToneTextfileSdcardData.state = APP_TONE_TEXTFILE_SDCARD_STATE_CARD_MOUNT;
            }
            break;

            case APP_TONE_TEXTFILE_SDCARD_STATE_CARD_MOUNT:
                if(SYS_FS_Mount("/dev/mmcblka1", "/mnt/myDrive", FAT, 0, NULL) != 0)
                {
                    /* The disk could not be mounted. Try mounting again until success. */
                    appToneTextfileSdcardData.state = APP_TONE_TEXTFILE_SDCARD_STATE_CARD_MOUNT;
                }
                else
                {
                    /* Mount was successful. Unmount the disk, for testing. */
                    appToneTextfileSdcardData.state = APP_TONE_TEXTFILE_SDCARD_STATE_CARD_CURRENT_DRIVE_SET;
                }
                break;
        
        
                case APP_TONE_TEXTFILE_SDCARD_STATE_CARD_CURRENT_DRIVE_SET:
                {
                    if(SYS_FS_CurrentDriveSet("/mnt/myDrive") == SYS_FS_RES_FAILURE)
                    {
                        /* Error while setting current drive */
                        appToneTextfileSdcardData.state = APP_TONE_TEXTFILE_SDCARD_STATE_ERROR;
                    }
                    else
                    {     
                        appToneTextfileSdcardData.fileHandle = SYS_FS_FileOpen("tone.txt", (SYS_FS_FILE_OPEN_READ));
                        if(appToneTextfileSdcardData.fileHandle == SYS_FS_HANDLE_INVALID)
                        {
                            /* Could not open the file. Error out*/
                            appToneTextfileSdcardData.state = APP_TONE_TEXTFILE_SDCARD_STATE_ERROR;
                        }
                        else
                        {
                            /* Read the file size */
                            appToneTextfileSdcardData.state = APP_TONE_TEXTFILE_SDCARD_STATE_READ_FILE_SIZE;
                        }
                    
                    
                    }    
                }    
                break;
            
                case APP_TONE_TEXTFILE_SDCARD_STATE_READ_FILE_SIZE:
                
                    appToneTextfileSdcardData.fileSize = SYS_FS_FileSize( appToneTextfileSdcardData.fileHandle);
                
                    if (appToneTextfileSdcardData.fileSize == -1)
                    {
                        /* Could not read file size. Error out*/
                        appToneTextfileSdcardData.state = APP_TONE_TEXTFILE_SDCARD_STATE_ERROR;
                    }
                    else
                    {
                        appToneTextfileSdcardData.state = APP_TONE_TEXTFILE_SDCARD_STATE_CARD_READ;
                    }
                
                    break;

                case APP_TONE_TEXTFILE_SDCARD_STATE_CARD_READ:
                {
                    uint16_t nBytesRead = 0;
                    uint16_t nBytesParsed = 0;                
                    uint16_t nRequestedBytes = 0;
                
                    if (appToneTextfileSdcardData.currentFilePosition < appToneTextfileSdcardData.fileSize)
                    {
                        /* Read audio text data from SD card*/
                    
                        nRequestedBytes = 
                           sizeof(appToneTextfileSdcardData.textParser.buffer) - appToneTextfileSdcardData.textParser.nElements;
                    
                        if (true == APP_TONE_TEXTFILE_SDCARD_Read_SDCard(
                                appToneTextfileSdcardData.fileHandle,
                                &appToneTextfileSdcardData.textParser.buffer[appToneTextfileSdcardData.textParser.nElements],
                                nRequestedBytes,
                                &nBytesRead )
                            )
                        {
                            appToneTextfileSdcardData.textParser.nElements += nBytesRead;
                        
                            /* Progress the file position */
                            appToneTextfileSdcardData.currentFilePosition += nBytesRead;
                        
                            /* Parse the read audio text data */
                            appToneTextfileSdcardData.codec.bufferSize += 
                                APP_TONE_TEXTFILE_SDCARD_Parse_Audio_Text_Data(
                                    appToneTextfileSdcardData.textParser.buffer,
                                    (int16_t* const)(&((uint8_t*)appToneTextfileSdcardData.codec.txbufferObject)[appToneTextfileSdcardData.codec.bufferSize]),                                
                                    appToneTextfileSdcardData.textParser.nElements,
                                    &nBytesParsed
                                );
                        
                            /* Copy the left over (not parsed) data to the start of the textParser input buffer */
                            memcpy(
                                appToneTextfileSdcardData.textParser.buffer, 
                                &appToneTextfileSdcardData.textParser.buffer[nBytesParsed], 
                                (appToneTextfileSdcardData.textParser.nElements - nBytesParsed)
                            );	

                            /* Set the index into the textDataBufferSize to reflect the copied left over data */
                            appToneTextfileSdcardData.textParser.nElements -= nBytesParsed;
                        
                            if (nBytesRead != nRequestedBytes)
                            {
                                /* We have reached End of File. Close it and submit the buffer for playing */
                                SYS_FS_FileClose(appToneTextfileSdcardData.fileHandle); 
                                appToneTextfileSdcardData.state = APP_TONE_TEXTFILE_SDCARD_STATE_CODEC_ADD_BUFFER;
                            }
                        }
                        else
                        {
                            /* We have a file read error. Close the file */
                            SYS_FS_FileClose(appToneTextfileSdcardData.fileHandle); 
                            appToneTextfileSdcardData.state = APP_TONE_TEXTFILE_SDCARD_STATE_ERROR;
                        }                    	                                        
                    }                                
                    else
                    {
                        /* The file is read. Close it and submit the buffer for playing */
                        SYS_FS_FileClose(appToneTextfileSdcardData.fileHandle);                    
                        appToneTextfileSdcardData.state = APP_TONE_TEXTFILE_SDCARD_STATE_CODEC_ADD_BUFFER;                    
                    }
                
                }    
            
                break;             
            
        
            /* Add an audio buffer to the codec driver queue to be transmitted */
            case APP_TONE_TEXTFILE_SDCARD_STATE_CODEC_ADD_BUFFER:
            {
                uint8_t index;
                bool isInvalidHandle;

                isInvalidHandle = false;
                /* Queuing buffers (Queue Size - 1) items */
                /* Note: Here we are queuing the same buffer (Queue Size - 1) times. */
                for(index=0; index < (APP_TONE_TEXTFILE_SDCARD_CODEC_WRITE_QUEUE_SIZE - 1); index++)
                {
                    DRV_CODEC_BufferAddWrite(appToneTextfileSdcardData.codec.handle, &appToneTextfileSdcardData.codec.writeBufHandle,
                    appToneTextfileSdcardData.codec.txbufferObject, appToneTextfileSdcardData.codec.bufferSize);
                    if(appToneTextfileSdcardData.codec.writeBufHandle != DRV_CODEC_BUFFER_HANDLE_INVALID)
                    {
                        ;
                    }
                    else
                    {
                        isInvalidHandle = true;
                    }
                }

                if(false == isInvalidHandle)
                {
                    /* Queuing Done. Transmission has begun. */
                        appToneTextfileSdcardData.state = APP_TONE_TEXTFILE_SDCARD_STATE_CODEC_WAIT_FOR_BUFFER_COMPLETE;
                }
            }
            break;

            /* Audio data Transmission under process */
            case APP_TONE_TEXTFILE_SDCARD_STATE_CODEC_WAIT_FOR_BUFFER_COMPLETE:
            {
            }
            break;

            /* Audio data Transmission complete */
            case APP_TONE_TEXTFILE_SDCARD_STATE_CODEC_BUFFER_COMPLETE:
            {
                DRV_CODEC_BufferAddWrite(appToneTextfileSdcardData.codec.handle, &appToneTextfileSdcardData.codec.writeBufHandle,
                appToneTextfileSdcardData.codec.txbufferObject, appToneTextfileSdcardData.codec.bufferSize);
                if(appToneTextfileSdcardData.codec.writeBufHandle != DRV_CODEC_BUFFER_HANDLE_INVALID)
                {
                    appToneTextfileSdcardData.state = APP_TONE_TEXTFILE_SDCARD_STATE_CODEC_WAIT_FOR_BUFFER_COMPLETE;
                }
                else
                {
                    // Something is wrong
                }
            }
            break;

            default:
            {
            }
            break;
        }
    }
}




/**********************************************************
 * Application CODEC buffer Event handler.
 ***********************************************************/
static void APP_TONE_TEXTFILE_SDCARD_BufferEventHandler(DRV_CODEC_BUFFER_EVENT event,
        DRV_CODEC_BUFFER_HANDLE handle, uintptr_t context )
{              
    switch(event)
    {
        case DRV_CODEC_BUFFER_EVENT_COMPLETE:
        {
            appToneTextfileSdcardData.state = APP_TONE_TEXTFILE_SDCARD_STATE_CODEC_BUFFER_COMPLETE;
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

////////////////////////////////////////////////////////////////////////////////
 bool APP_TONE_TEXTFILE_SDCARD_CloseFile (SYS_FS_HANDLE fileHandle )
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

///////////////////////////////////////////////////////////////////////////////
void APP_TONE_TEXTFILE_SDCARD_SuspendStreaming(void)
{  
    DRV_CODEC_Close(appToneTextfileSdcardData.codec.handle);     
    APP_TONE_TEXTFILE_SDCARD_CloseFile(appToneTextfileSdcardData.fileHandle);
    
    if(SYS_FS_Unmount("/mnt/myDrive") != 0)
    {
    }
    else
    {

    }    
      
}
