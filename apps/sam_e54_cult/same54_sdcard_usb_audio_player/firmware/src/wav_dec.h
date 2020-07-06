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

typedef struct
{
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

typedef struct
{
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

int WAV_GetFormat (void);
uint8_t WAV_GetChannels(void);
int WAV_GetSamplesPerSec(void);
int WAV_GetBlockAlign(void);
int WAV_GetBitsPerSample(void);
int WAV_GetBytesPerSec(void);
int WAV_GetDataLen(void);
unsigned int WAV_GetFileSize(void);

uint32_t WAV_GetSampleRate(void);
uint32_t WAV_GetBitRate(void);
uint32_t WAV_GetDuration(void);

bool isWAVdecoder_enabled(void);
uint32_t WAV_UpdatePlaytime(void);
uint8_t WAV_GetChannels(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END
#endif	/* WAV_DEC_H */

