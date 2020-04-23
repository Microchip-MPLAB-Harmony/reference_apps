/*******************************************************************************
  WAV Decoder Source File

  Company:
    Microchip Technology Inc.

  File Name:
    wav_dec.h

  Summary:
    Contains the wav decoder specific defintions and function prototypes.

  Description:
    This file contains the wav decoder specific defintions and function
    prototypes.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2011-2012 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
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
 
#ifndef WAV_DEC_H
#define	WAV_DEC_H

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "system/fs/sys_fs.h"
#include "configuration.h"


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
extern "C" {
#endif
//DOM-IGNORE-END

    
    
#define WAVE_FORMAT_PCM             0x0001
#define WAVE_FORMAT_ALAW            0x0006
#define WAVE_FORMAT_MULAW           0x0007
#define WAV_HEADER_SIZE             44
#define WAV_HEAP_SIZE               1024
#define WAV_INPUT_BUFFER_SIZE       (DECODER_MAX_OUTPUT_BUFFER_SIZE>DECODER_MAX_INPUT_BUFFER_SIZE?DECODER_MAX_INPUT_BUFFER_SIZE:DECODER_MAX_OUTPUT_BUFFER_SIZE)
#define WAV_OUTPUT_BUFFER_SIZE      (WAV_INPUT_BUFFER_SIZE)

typedef struct {
    int format;
    int filesize;
    int filetype;
    int frmtchunk_marker;
    int dataLen;
    short type_frmt;
    short numOfChan;
    int samplesPerSec;
    int bytesPerSec;
    short blockAlign;
    short bitsPerSample;
    int *extra;
    unsigned int extralen;        
} dWAVHEADER; 

typedef struct{
    // Common attributes for every decoder
    uint32_t wavSampleRate;
    uint32_t wavBitRate;
    uint32_t wavDuration;
    // start point for decoder to decode
    uint32_t decodeStartPos;
    uint32_t wavFileBytes;
}WAV_DEC;

void WAV_Initialize(uint8_t *input);
void WAV_Initialize_N(uint8_t *input, SYS_FS_HANDLE wavFilehandle);
uint32_t WAV_GetAudioSize();
bool WAV_Decoder(uint8_t *input, uint16_t inSize, uint16_t *read, int16_t *output, uint16_t *written);
int WAV_HdrGetSamplesPerSec(void);
int WAV_HdrGetBytesPerSec(void);
int WAV_HdrGetDataLen(void);
unsigned int WAV_HdrGetFileSize(void);
uint32_t WAV_GetSampleRate(void);
uint32_t WAV_GetBitRate(void);
uint32_t WAV_GetDuration(void);

bool isWAVdecoder_enabled();
uint32_t WAV_UpdatePlaytime();
uint8_t WAV_GetChannels();

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END
#endif	/* WAV_DEC_H */

