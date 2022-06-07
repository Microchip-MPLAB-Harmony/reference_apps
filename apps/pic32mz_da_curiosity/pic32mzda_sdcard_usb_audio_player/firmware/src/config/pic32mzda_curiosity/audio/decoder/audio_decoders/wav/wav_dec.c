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
Copyright (c) 2012,2019 released Microchip Technology Inc.  All rights reserved.

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
    //return (int) wavHeader.dataLen;
    return wavHeader.datachunk_len;
}

unsigned int WAV_GetFileSize(void)
{
    //return (unsigned int) wavHeader.extralen;
    return (unsigned int) wavHeader.filesize+4;
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
    wavDecoder.wavFileBytes   = /*wavHeader.extralen;*/wavHeader.datachunk_len;
    wavDecoder.wavDuration    = wavDecoder.wavFileBytes / wavHeader.bytesPerSec;
	currentWAVFileHandle      = SYS_FS_HANDLE_INVALID;
}

void WAV_Initialize_N(uint8_t *input, SYS_FS_HANDLE wavFilehandle)
{
    memcpy(&wavHeader, input, WAV_HEADER_SIZE);

    wavDecoder.decodeStartPos = WAV_HEADER_SIZE;
    wavDecoder.wavSampleRate  = wavHeader.samplesPerSec;
    wavDecoder.wavBitRate     = wavHeader.bytesPerSec*8/1000;
    wavDecoder.wavFileBytes   = /*wavHeader.extralen;*/wavHeader.datachunk_len;
    wavDecoder.wavDuration    = wavDecoder.wavFileBytes / wavHeader.bytesPerSec;
}

/* Assumption: only the first 8 bytes have been read -- i.e., RIFF, size */
bool WAV_Initialize_SkipOpts(uint8_t *input, SYS_FS_HANDLE wavFilehandle)
{
    dWAVCHNKHEADER chunkHdr = {0};
    int32_t bytesRead;
    bool isSuccess = false;
    const char* const fmt__FourCC = ((const char* const)"fmt "); // trailing space
    const char* const data_FourCC = ((const char* const)"data");
    bool found_fmt__chnk = false;
    int tot_bytes_remain = 0;
    
    // Note:
    // This code processes only "fmt " chunk and "data" chunk of a wave file
    // all other chunks are optional, so they will be skipped from processing
    memcpy(&wavHeader, input, 8); // -- RIFF, -- fileSize
    if(0 == memcmp("RIFF", &wavHeader.format, 4)) 
    {
        if(wavHeader.filesize >= 4) /* filesize copied during memcpy above */
        {
            // Expected type is "WAVE" -- WAVE
            bytesRead = SYS_FS_FileRead(wavFilehandle, &wavHeader.filetype, 4);
            if ((bytesRead)&&(-1!=bytesRead)&&(!SYS_FS_FileEOF(wavFilehandle)))
            {
                tot_bytes_remain = wavHeader.filesize-4; /* Already read W, A, V, E */
                if(0 == memcmp("WAVE", &wavHeader.filetype, 4)) /* indeed a wave file */
                {
                    while(tot_bytes_remain >= 8)
                    { 
                        bytesRead = SYS_FS_FileRead(wavFilehandle, &chunkHdr, 8);
                        if ((0 == bytesRead)||(-1==bytesRead)||(SYS_FS_FileEOF(wavFilehandle)))
                        {
                            break;
                        }
                        //printf("\n\rTag:[%X]\n\r", chunkHdr.tag);
                        tot_bytes_remain -= 8;
                        // There are no restrictions upon the order of 
                        // the chunks within a WAVE file, with the exception 
                        // that the Format chunk must precede the Data chunk. 
                        if(found_fmt__chnk)
                        {
                            if(0 == memcmp(data_FourCC, &chunkHdr.tag, 4))
                            {
                                // found data header too. Always comes after fmt  header
                                wavHeader.datatag = chunkHdr.tag;
                                wavHeader.datachunk_len = chunkHdr.size;
                                isSuccess = true;
                                break;
                            }
                        }
                        else
                        {
                            if(0 == memcmp(fmt__FourCC, &chunkHdr.tag, 4))
                            {
                                found_fmt__chnk = true;
                                wavHeader.frmtchunk_marker = chunkHdr.tag;
                                wavHeader.dataLen = chunkHdr.size;
                                //printf("\n\r[%d]\n\r", chunkHdr.size);
                                // room for improvement: typical Size is 16, other lengths possible
                                if((16 == wavHeader.dataLen)&&(tot_bytes_remain >= 16))
                                {
                                    bytesRead = SYS_FS_FileRead(wavFilehandle, &wavHeader.type_frmt, 16); 
                                    if ((0 == bytesRead)||(-1==bytesRead)||(SYS_FS_FileEOF(wavFilehandle)))
                                    {
                                        break;
                                    }
                                    tot_bytes_remain -= 16;
                                }
                                continue;
                            }
                        }
                        //printf("\n\rSkipping by %d\n\r", chunkHdr.size);
                        //skip this optional tag (something that isn't fmt/data)
                        bytesRead = SYS_FS_FileSeek(wavFilehandle, chunkHdr.size, SYS_FS_SEEK_CUR);
                        if((bytesRead == -1) || (bytesRead != chunkHdr.size) || (SYS_FS_FileEOF(wavFilehandle)))
                        {
                            break;
                        }
                        tot_bytes_remain -= chunkHdr.size;
                    }
                }
            }
        }
    }
 
    if(isSuccess)
    {
        wavDecoder.decodeStartPos = WAV_HEADER_SIZE;
        wavDecoder.wavSampleRate  = wavHeader.samplesPerSec;
        wavDecoder.wavBitRate     = wavHeader.bytesPerSec*8/1000;
        wavDecoder.wavFileBytes   = wavHeader.datachunk_len;
        wavDecoder.wavDuration    = wavDecoder.wavFileBytes / wavHeader.bytesPerSec;
        memcpy(input, &wavHeader, sizeof(wavHeader));
    }
    else
    {
        currentWAVFileHandle = SYS_FS_HANDLE_INVALID;    
    }
    return isSuccess;
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