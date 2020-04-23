/*******************************************************************************
  WAV Decoder Source File

  Company:
    Microchip Technology Inc.

  File Name:
    wav_dec.c

  Summary:
   Contains the functional implementation of wav decoder.

  Description:
   This file contains the functional implementation of wav decoder.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2012 released Microchip Technology Inc.  All rights reserved.

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
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "wav_dec.h"


static dWAVHEADER wavHeader;
static WAV_DEC   wavDecoder;
static SYS_FS_HANDLE currentWAVFileHandle;

int WAV_HdrGetFormat (void)
{
    return wavHeader.format;
}

int WAV_HdrGetNumOfChan(void)
{
    return wavHeader.numOfChan;
}
uint8_t WAV_GetChannels()
{
    return WAV_HdrGetNumOfChan();
}


int WAV_HdrGetSamplesPerSec(void)
{
    return wavHeader.samplesPerSec;
}

int WAV_HdrGetBlockAlign(void)
{
   return wavHeader.blockAlign;
}

int WAV_HdrGetBitsPerSample(void)
{
    return wavHeader.bitsPerSample;
}

int WAV_HdrGetBytesPerSec(void)
{
    return wavHeader.bytesPerSec;
}

int WAV_HdrGetDataLen(void)
{
    return (int) wavHeader.dataLen;
}

unsigned int WAV_HdrGetFileSize(void)
{
    return (unsigned int) wavHeader.extralen;
}

uint32_t WAV_GetSampleRate(void){
    return wavDecoder.wavSampleRate;
}

uint32_t WAV_GetBitRate(void){
    return wavDecoder.wavBitRate;
}

uint32_t WAV_GetDuration(void){
    return wavDecoder.wavFileBytes / wavHeader.bytesPerSec;
}
/*
* This function is deprecated,
* Use WAV_Initialize_N() instead.
*/
void WAV_Initialize(uint8_t *input){
	memcpy(&wavHeader, input, WAV_HEADER_SIZE);

    wavDecoder.decodeStartPos = WAV_HEADER_SIZE;
    wavDecoder.wavSampleRate  = wavHeader.samplesPerSec;
    wavDecoder.wavBitRate     = wavHeader.bytesPerSec*8/1000;
    wavDecoder.wavFileBytes   = wavHeader.extralen;
    wavDecoder.wavDuration    = wavDecoder.wavFileBytes / wavHeader.bytesPerSec;
	currentWAVFileHandle      = SYS_FS_HANDLE_INVALID;
}

void WAV_Initialize_N(uint8_t *input, SYS_FS_HANDLE wavFilehandle)
{
    memcpy(&wavHeader, input, WAV_HEADER_SIZE);

    wavDecoder.decodeStartPos = WAV_HEADER_SIZE;
    wavDecoder.wavSampleRate  = wavHeader.samplesPerSec;
    wavDecoder.wavBitRate     = wavHeader.bytesPerSec*8/1000;
    wavDecoder.wavFileBytes   = wavHeader.extralen;
    wavDecoder.wavDuration    = wavDecoder.wavFileBytes / wavHeader.bytesPerSec;

    currentWAVFileHandle = wavFilehandle;
}

uint32_t WAV_UpdatePlaytime(){
    uint32_t playtime;
	if(currentWAVFileHandle == SYS_FS_HANDLE_INVALID){
		return 0;
	}
    playtime = (SYS_FS_FileTell(currentWAVFileHandle) - WAV_HEADER_SIZE);
    if(wavHeader.bytesPerSec !=0 )
    {
        playtime /= wavHeader.bytesPerSec;
        return playtime;
    }
    return 0;
}

uint32_t WAV_GetAudioSize(){
    return wavDecoder.wavFileBytes;
}

bool WAV_Decoder(uint8_t *input, uint16_t inSize, uint16_t *read, int16_t *output, uint16_t *written)
{
    memcpy ( output, input, inSize );

    *read = inSize;
    *written = inSize;
    return true;
}

bool isWAVdecoder_enabled(){
    return true;
}