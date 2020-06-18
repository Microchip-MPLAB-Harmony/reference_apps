/*******************************************************************************
  Universal Audio Decoders Demo

  Company:
    Microchip Technology Inc.

  File Name:
    decoder.c

  Summary:
   Contains the functional implementation of decoder functions.

  Description:
   This file contains the functional implementation of decoder functions.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#define DECODER_C
#include "decoder.h"
#include "app.h"
#include "app_sdcard_audio_task.h"

static DECODER_TYPE decoderType;
uint32_t decoderBitrate;
uint32_t decoderSamplerate;
int sampling_frequency;

////////////////////////////////////////////////////////////////////////////////


void DECODER_Initialize ( uint8_t type )
{
    uint8_t frameHeader[WAV_HEADER_SIZE]; // 44 bytes
   
    decoderType = DECODER_TYPE_UNKNOWN;
    APP_SDCARD_AUDIO_PLAYER *AppDataAudioPlayerPtr = (APP_SDCARD_AUDIO_PLAYER *)APP_SDCARD_AUDIO_Player_GetInstance();
    switch ( type )
    {            
        case APP_SDCARD_AUDIO_DECODER_WAV:
            AppDataAudioPlayerPtr->currentStreamType = APP_SDCARD_AUDIO_STREAM_WAV;
            decoderType = DECODER_TYPE_WAV;
            APP_SDCARD_AUDIO_Card_ReadCurrentFile(frameHeader, WAV_HEADER_SIZE);            
            AppDataAudioPlayerPtr->readBytes = WAV_INPUT_BUFFER_SIZE;             
            AppDataAudioPlayerPtr->readbyte_flag = true;
            WAV_Initialize (frameHeader);

            //SYED DECODER_EventHandler ( DECODER_EVENT_TAG_TITLE, (uint32_t)AppDataAudioPlayerPtr->fileStatus.lfname );
            
            // for RW function, move to end of previous song
            DECODER_EventHandler ( DECODER_EVENT_STREAM_START, 0 );
            
            break;            
            
        case APP_SDCARD_AUDIO_DECODER_UNKNOWN:
            break;
    }
}

bool DECODER_Decode ( uint8_t *input, uint16_t inSize, uint16_t *read, int16_t *output, uint16_t *written )
{
    *read = 0;
    *written = 0;
    switch ( decoderType )
    {
        case DECODER_TYPE_WAV:
            if( WAV_Decoder (input,inSize,read,output,written)==true)
            {
                return true;
            }
            else
                return false;
            break;            

        case DECODER_TYPE_UNKNOWN:
            break;
        default:
            break;
    }

    return ( true );
}

// This is the function returns the audio size in file, 
// which means it doesn't contain the header size, etc...
uint32_t DECODER_GetCurrentValidAudioSize(){
    // add other decoder cases later

    uint32_t ret = 0;
    switch(decoderType){
        case DECODER_TYPE_WAV:
            ret = WAV_GetAudioSize();
            break;
        default:
            ret = 0;
            break;
    }
    return ret;
}

void DECODER_Cleanup()
{
    switch ( decoderType )
    {
        default:
            break;
    }
}

/////////////////////////////////////////////////////////////
uint32_t GetDecodeBitRate(void)
{
    return ( (uint32_t) decoderBitrate );
}

/////////////////////////////////////////////////////////////
uint32_t GetDecodeSamplingRate ( void )
{
    return ( (uint32_t) decoderSamplerate );
}