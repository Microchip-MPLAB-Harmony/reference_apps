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
#include "wav_dec.h"


static dWAVHEADER wavHeader;
static WAV_DEC   wavDecoder;
static SYS_FS_HANDLE currentWAVFileHandle;

int WAV_GetFormat (void)
{
    return wavHeader.format;
}

uint8_t WAV_GetChannels()
{
    return wavHeader.numOfChan;
}

int WAV_GetSamplesPerSec(void)
{
    return wavHeader.samplesPerSec;
}

int WAV_GetBlockAlign(void)
{
   return wavHeader.blockAlign;
}

int WAV_GetBitsPerSample(void)
{
    return wavHeader.bitsPerSample;
}

int WAV_GetBytesPerSec(void)
{
    return wavHeader.bytesPerSec;
}

int WAV_GetDataLen(void)
{
    return (int) wavHeader.dataLen;
}

unsigned int WAV_GetFileSize(void)
{
    return (unsigned int) wavHeader.extralen;
}

uint32_t WAV_GetSampleRate(void)
{
    return wavDecoder.wavSampleRate;
}

uint32_t WAV_GetBitRate(void)
{
    return wavDecoder.wavBitRate;
}

uint32_t WAV_GetDuration(void)
{
    return wavDecoder.wavFileBytes / wavHeader.bytesPerSec;
}
/*
* This function is deprecated,
* Use WAV_Initialize_N() instead.
*/
void WAV_Initialize(uint8_t *input)
{
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

uint32_t WAV_UpdatePlaytime()
{
    uint32_t playtime;
	if(currentWAVFileHandle == SYS_FS_HANDLE_INVALID)
    {
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

uint32_t WAV_GetAudioSize()
{
    return wavDecoder.wavFileBytes;
}

bool WAV_Decoder(uint8_t *input, uint16_t inSize, uint16_t *read, int16_t *output, uint16_t *written)
{
    memcpy ( output, input, inSize );

    *read = inSize;
    *written = inSize;
    return true;
}

bool isWAVdecoder_enabled()
{
    return true;
}