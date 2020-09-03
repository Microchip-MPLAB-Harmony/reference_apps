/*******************************************************************************
  WAV Decoder Source File

  Company:
    Microchip Technology Inc.

  File Name:
    mp3_dec.h

  Summary:
    Contains the wav decoder specific defintions and function prototypes.

  Description:
    This file contains the wav decoder specific defintions and function
    prototypes.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
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
 //DOM-IGNORE-END
 
#ifndef MP3_DEC_H
#define	MP3_DEC_H

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
extern "C" {
#endif
//DOM-IGNORE-END

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "system/fs/sys_fs.h"
#include "configuration.h"

#include "audio/decoder/audio_decoders/mp3/fixpnt/pub/mp3common.h"
#include "audio/decoder/audio_decoders/mp3/fixpnt/pub/mp3dec.h"
#include "audio/decoder/audio_decoders/mp3/fixpnt/pub/mpadecobjfixpt.h"
#include "audio/decoder/audio_decoders/mp3/fixpnt/pub/statname.h"
#include "audio/decoder/audio_decoders/mp3/fixpnt/real/assembly.h"
#include "audio/decoder/audio_decoders/mp3/fixpnt/real/coder.h"

#include "audio/decoder/audio_decoders/mp3/id3/id3.h"

#define MP3_HEADER_SAMPLERATE_44100         0b00
#define MP3_HEADER_SAMPLERATE_48000         0b01
#define MP3_HEADER_SAMPLERATE_32000         0b10
#define MP3_HEADER_SAMPLERATE_RESV          0b11

#define MP3_HEADER_CHANNELS_STEREO          0b00
#define MP3_HEADER_CHANNELS_JOINT           0b01
#define MP3_HEADER_CHANNELS_DUAL            0b10
#define MP3_HEADER_CHANNELS_MONO            0b11

#define MP3_XING_HEADER_START_MONO          17
#define MP3_XING_HEADER_START_STEREO        32
    
#define MP3MPEG1L3_SAMPLES_PER_FRAME        1152 // MPEG1 LayerIII, samples per frame
#define MP3MPEG2L3_SAMPLES_PER_FRAME        576  // MPEG2/2.5 LayerIII, samples per frame
    
typedef union
{
    uint32_t data;
    struct
    {
        uint8_t sync0      : 8;

        uint8_t CRC       : 1;
        uint8_t layer     : 2;
        uint8_t mpeg      : 2;
        uint8_t sync1      : 3;

        uint8_t private   : 1;
        uint8_t padding   : 1;
        uint8_t samprate  : 2;
        uint8_t bitrate   : 4;

        uint8_t nc        : 4;
        uint8_t extend    : 2;
        uint8_t stereo   : 2;
    };
}
MP3_FRAME_HEADER;

typedef struct
{
    int8_t tag[4];
    union
    {
        uint32_t flags;
        struct
        {
            uint32_t              :24;
            uint32_t frameInfo    :1;
            uint32_t sizeInfo     :1;
            uint32_t tocInfo      :1;
            uint32_t qualityInfo  :1;
            uint32_t              :4;
        };
    };

    uint8_t frames[4];
    uint8_t size[4];
    uint8_t toc[100];
    uint8_t quality;
}
MP3_XING_HEADER;

//CBR VBR enum defination
enum {
    STREAM_CBR,
    STREAM_VBR
};

typedef enum
{
    MP3_STATE_STREAM
}
MP3_STATE;

typedef struct{
    uint16_t mp3SampleRate;
    uint32_t mp3BitRate;
    uint32_t mp3Duration;
    
    // first frame position in file
    
    uint32_t firstFramePos;
    bool     isVBR;
    
    // for VBR MP3, mp3ValidBytes is the number of bytes in file is given by XING header,
    // for CBR MP3, mp3ValidBytes is MP3 audio file size - first frame position
    uint32_t mp3ValidBytes;
    uint8_t stereo;
}MP3_DEC;  
    
#define MP3_HEAP_SIZE               1024
#define MP3_INPUT_BUFFER_SIZE       (DECODER_MAX_OUTPUT_BUFFER_SIZE>DECODER_MAX_INPUT_BUFFER_SIZE?DECODER_MAX_INPUT_BUFFER_SIZE:DECODER_MAX_OUTPUT_BUFFER_SIZE)
#define MP3_OUTPUT_BUFFER_SIZE      (MP3_INPUT_BUFFER_SIZE)

void MP3_Initialize(uint8_t *input);
void MP3_Initialize_N(uint8_t *input, SYS_FS_HANDLE wavFilehandle);
uint32_t MP3_GetAudioSize();
bool MP3_Decoder(uint8_t *input, uint16_t inSize, uint16_t *read, int16_t *output, uint16_t *written);
int MP3_HdrGetSamplesPerSec(void);
int MP3_HdrGetBytesPerSec(void);
int MP3_HdrGetDataLen(void);
unsigned int MP3_HdrGetFileSize(void);

uint32_t MP3_GetDuration(void);

bool isMP3decoder_enabled();
uint32_t MP3_UpdatePlaytime();

uint32_t MP3_GetSampleRate(void);
uint8_t MP3_GetChannels(void);
int MP3_GetBitsPerSample(void);

int32_t MP3_FindSyncWord(HMP3Decoder hMP3Decoder, unsigned char *readPtr, int32_t bytesLeft);

int MP3_FillReadBuffer(unsigned char *readBuf, unsigned char *readPtr, int bufSize, int bytesLeft, SYS_FS_HANDLE fileHandle);

uint32_t MP3_GetBitRate(SYS_FS_HANDLE fileHandle, uint32_t firstframe, uint8_t *heap);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END
#endif	/* MP3_DEC_H */

