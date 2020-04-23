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
Copyright (c) 2016-2017 released Microchip Technology Inc.  All rights reserved.

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

