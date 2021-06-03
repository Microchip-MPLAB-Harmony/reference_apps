/*******************************************************************************
  MP3 Decoder Source File

  Company:
    Microchip Technology Inc.

  File Name:
    mp3_dec.c

  Summary:
   Contains the functional implementation of MP3 decoder.

  Description:
   This file contains the functional implementation of MP3 decoder.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "mp3_dec.h"

static bool MP3_ParseVBR (uint8_t* data);

static MP3FrameInfo frameInfo;

uint32_t MP3_GetSampleRate(void)
{
    return frameInfo.samprate;
}

uint8_t MP3_GetChannels(void)
{
    return frameInfo.nChans;
}

int MP3_GetBitsPerSample(void)
{
    return frameInfo.bitsPerSample;
}

int32_t MP3_FindSyncWord(HMP3Decoder hMP3Decoder, unsigned char *readPtr, int32_t bytesLeft)
{
    int32_t offset = MP3FindSyncWord(readPtr, bytesLeft);
    if (offset >= 0)
    {
        // fill in frameinfo data
        MP3GetNextFrameInfo(hMP3Decoder, &frameInfo, readPtr+offset);   
    }
    return offset; 
}

int MP3_FillReadBuffer(unsigned char *readBuf, unsigned char *readPtr, int bufSize, int bytesLeft, SYS_FS_HANDLE fileHandle)
{
    // This function will move bytesLeft bytes from readPtr to the top of 
    // readBuf. bufSize is the size of readBuf. It then reads bufSize - bytesLeft
    // bytes from the file and appends these bytes to readBuf.  If readBuf is
    // not full, then remaining bytes are set to zero. The total number of bytes
    // read from the file is returned.
    int nRead;

    // move last, small chunk from end of buffer to start, then fill with new data
    memmove(readBuf, readPtr, bytesLeft);				
    nRead = SYS_FS_FileRead(fileHandle, readBuf + bytesLeft, bufSize - bytesLeft);
    if (nRead > 0)
    {
        /* zero-pad to avoid finding false sync word after last frame (from old data in readBuf) */
        if (nRead < bufSize - bytesLeft)
            memset(readBuf + bytesLeft + nRead, 0, bufSize - bytesLeft - nRead);	
    }
    return nRead;
}

MP3_DEC mp3Decoder;

uint32_t MP3_GetBitRate(SYS_FS_HANDLE fileHandle, uint32_t firstframe, uint8_t *heap)
{
    uint32_t currPos = SYS_FS_FileTell( fileHandle );
    SYS_FS_FileSeek(fileHandle, firstframe, SYS_FS_SEEK_SET);
    // read first frame header and potential XING header if this MP3 is VBR audio
    SYS_FS_FileRead(fileHandle, heap, sizeof(MP3_FRAME_HEADER)+MP3_XING_HEADER_START_STEREO+sizeof(MP3_XING_HEADER));

    mp3Decoder.isVBR = false;
    mp3Decoder.mp3SampleRate = 0;
    mp3Decoder.mp3BitRate = 0;
    mp3Decoder.mp3Duration = 0;
    mp3Decoder.mp3ValidBytes = 0;
    // get sampling rate and bit rate from first frame header.
    bool parse_frameheader = MP3_ParseVBR(heap);
    if (!parse_frameheader)
    {
        return 0;
    }

    mp3Decoder.mp3ValidBytes = (SYS_FS_FileSize(fileHandle) - mp3Decoder.firstFramePos);
    mp3Decoder.mp3Duration = mp3Decoder.mp3ValidBytes / 125 / mp3Decoder.mp3BitRate;
    
    SYS_FS_FileSeek(fileHandle, currPos, SYS_FS_SEEK_SET);  // restore pos   
    return mp3Decoder.mp3BitRate;
}

static bool MP3_ParseVBR (uint8_t* data)
{
    MP3_FRAME_HEADER *frameHeader;
    MP3_XING_HEADER xingHeader[1];
    uint32_t frames, time;
    uint16_t samplerate;

    frameHeader = (MP3_FRAME_HEADER *)data;
    data += 4;
    
    mp3Decoder.stereo = frameHeader->stereo;
    if (( frameHeader->mpeg == 0x03 ) && ( frameHeader->layer == 0x01 ))   //mpeg-1 layer-3
    {
        const uint16_t samplerateList[4] = { 44100, 48000, 32000, 0 };
        
        samplerate = samplerateList[frameHeader->samprate];

        if ( samplerate != 0 )
        {
            mp3Decoder.mp3SampleRate = samplerate;
        }
        else
        {
            return ( false );
        }
        
        if ( (frameHeader->stereo & 0b11) == MP3_HEADER_CHANNELS_MONO )
        {
            memcpy(xingHeader, data + MP3_XING_HEADER_START_MONO, sizeof(MP3_XING_HEADER));
        }
        else
        {
            memcpy(xingHeader, data + MP3_XING_HEADER_START_STEREO, sizeof(MP3_XING_HEADER));
        }
                    
        if (( memcmp ( xingHeader->tag, "Xing", 4 ) == 0 )
        || ( memcmp ( xingHeader->tag, "Info", 4 ) == 0 ))
        {
            mp3Decoder.isVBR = true;
            frames = 0;
            
            
            if ( xingHeader->frameInfo )
            {
                frames = (( xingHeader->frames[0] * 0x100 + xingHeader->frames[1] ) * 0x100 + xingHeader->frames[2] ) * 0x100 + xingHeader->frames[3];
            }

            if ( frames != 0 )
            {
                // time in seconds
                time = ( frames * MP3MPEG1L3_SAMPLES_PER_FRAME + samplerate / 2 ) / samplerate;
                if(time != 0){
                    // kilobits per sec = (bytes / time)*8/1000;
                    mp3Decoder.mp3ValidBytes = (( xingHeader->size[0] * 0x100 + xingHeader->size[1] ) * 0x100 + xingHeader->size[2] ) * 0x100 + xingHeader->size[3];
                    mp3Decoder.mp3BitRate = (mp3Decoder.mp3ValidBytes)/125/time;
                }
                mp3Decoder.mp3Duration = time;
            }
        }
        else
        {
            const uint16_t bitrateList[16] = { 0, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320, 0 };
            uint16_t bitrate = bitrateList[frameHeader->bitrate];

            if ( bitrate != 0 )
            { 
                mp3Decoder.mp3BitRate = bitrate;
            }
            else
            {
                return ( false );
            }
        }

        return ( true );
    }   

    return ( false );
}