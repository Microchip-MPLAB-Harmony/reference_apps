/*******************************************************************************
  Universal Audio Decoders Application Demo

  Company:
    Microchip Technology Inc.

  File Name:
    decoders.h

  Summary:
    decoders interface.

  Description:
    This file contains the decoders specific definitions and function
    prototypes.
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

#ifndef DECODER_H
#define	DECODER_H


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
extern "C" {
#endif
//DOM-IGNORE-END

#include "audio/decoder/audio_decoders_config.h"
#include "audio/decoder/audio_decoders.h"



#define MEDIA_SECTOR_SIZE                512
#define MP3_DECODER_INPUT_FRAME_SIZE        MP3_IN_FRAME_SIZE
#define MP3_DECODER_OUTPUT_FRAME_SIZE       MP3_OUT_FRAME_SIZE
#define MP3_DECODER_HEAP_SIZE               MP3_STATE_SIZE

#define MP3_BUFFER_SIZE     MP3_IN_FRAME_SIZE + MEDIA_SECTOR_SIZE
typedef enum
{
    DECODE_STATUS_NOT_IN_DECODE,
    DECODE_STATUS_DECODE_END,
    DECODE_STATUS_DECODING,
    DECODE_STATUS_PAUSE,
    DECODE_STATUS_DECODE_SYNC,
    DECODE_STATUS_DECODE_ERROR
}
DECODE_STATUS;

typedef enum
{
    DECODER_EVENT_STREAM_START,
    DECODER_EVENT_SAMPLERATE,
    DECODER_EVENT_BITRATE,
    DECODER_EVENT_TRACK_TIME,
    DECODER_EVENT_TAG_ARTIST,
    DECODER_EVENT_TAG_ALBUM,
    DECODER_EVENT_TAG_TITLE,
    DECODER_INITIALIZATION_ERROR
}
DECODER_EVENT;

typedef enum
{
    DECODER_TYPE_MP3,
    DECODER_TYPE_AAC,
    DECODER_TYPE_ADPCM,
    DECODER_TYPE_WMA,
    DECODER_TYPE_WAV,
    DECODER_TYPE_SPEEX,
    DECODER_TYPE_UNKNOWN,
}
DECODER_TYPE;


void DECODER_Initialize ( uint8_t fileType );
bool DECODER_Decode ( uint8_t *input, uint16_t inSize, uint16_t *read, int16_t *output, uint16_t *written );
uint32_t DECODER_GetCurrentValidAudioSize();
void DECODER_Cleanup();
extern bool DECODER_EventHandler ( DECODER_EVENT event, uint32_t data );

#ifdef __cplusplus
}
#endif

#endif

