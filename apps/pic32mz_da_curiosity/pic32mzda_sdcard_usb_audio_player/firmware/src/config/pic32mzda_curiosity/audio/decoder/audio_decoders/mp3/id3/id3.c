/*******************************************************************************
  MP3 ID3 Tag Parser Source File

  Company:
    Microchip Technology Inc.

  File Name:
    id3.c

  Description:
    Implementation of ID3 parser.
 
*******************************************************************************/
/*******************************************************************************
Copyright (c) 2012 Microchip Technology Inc.  All rights reserved.

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

#include "id3.h"

#define READBLOCKSIZE 512

static ID3_EVENT_HANDLER ID3eventHandler;

static int32_t ID3_Initialize(uint8_t *buffer);
static uint32_t ID3_Parse_Frame(uint8_t *buffer, size_t left, int8_t *ret);
static void ID3_ParseFrameV22 (ID3V22_FRAME *frame, uint32_t frameSize, char *id, uint16_t event);
static void ID3_ParseFrameV23 (ID3V23_FRAME *frame, uint32_t frameSize, char *id, uint16_t event);
static bool ID3_EventHandler (ID3_EVENT event, uint32_t data);

// Read ID3 tag header
void read_ID3Tags(SYS_FS_HANDLE fileHandle, uint8_t *heap, ID3_EVENT_HANDLER eventHandler)
{
    ID3eventHandler = eventHandler; 
    
    uint8_t tagHeader[sizeof(ID3V2_TAG_HEADER)];
    uint32_t currPos = SYS_FS_FileTell( fileHandle );   // remember current position
    SYS_FS_FileSeek(fileHandle, 0, SYS_FS_SEEK_SET);    // go to beg of file
    SYS_FS_FileRead(fileHandle, tagHeader, sizeof(ID3V2_TAG_HEADER));
    int32_t ID3Size = ID3_Initialize (tagHeader);
    if(ID3Size != 0)
    { // ID3 tag found
        uint8_t *id3Frame = heap;
        uint32_t skip=0;
        uint32_t read = 0;
        int8_t ret = 0;
        SYS_FS_FileRead(fileHandle, id3Frame, READBLOCKSIZE);
        do
        {
            // If the id3 frame header fall off the read block
            if (sizeof(ID3V22_FRAME) + skip > READBLOCKSIZE)
            {
                //read more
                memcpy(id3Frame, id3Frame+skip, READBLOCKSIZE - skip);
                if(ID3Size < skip)
                    SYS_FS_FileRead(fileHandle, id3Frame + READBLOCKSIZE - skip, ID3Size);
                else
                    SYS_FS_FileRead(fileHandle, id3Frame + READBLOCKSIZE - skip, skip);

                skip = 0;
            }    
            ret = 1;
            read = ID3_Parse_Frame((uint8_t*)(id3Frame+skip), READBLOCKSIZE - skip, &ret);
            if (ret == -2)
            {
                break;
            }
            // id3 frame content fall off read block
            if (ret == -1)
            {
                // if its too large, just skip this frame
                if (read > READBLOCKSIZE)
                {
                    SYS_FS_FileSeek(fileHandle, read - READBLOCKSIZE + skip, SYS_FS_SEEK_CUR);
                    SYS_FS_FileRead(fileHandle, id3Frame, READBLOCKSIZE);
                    ID3Size -= read;
                    skip = 0;
                    continue;
                }
                // move the left bytes to head of pointer
                memcpy(id3Frame, id3Frame+skip, READBLOCKSIZE - skip);
                // read more
                SYS_FS_FileRead(fileHandle, id3Frame+READBLOCKSIZE-skip, skip);
                skip = 0;
                continue;
            }
            if (read == 0)
            {
                break;
            }
            ID3Size -= read;
            skip += read;
        }
        while(ID3Size > 0);
    }
    SYS_FS_FileSeek(fileHandle, currPos, SYS_FS_SEEK_SET);  // restore pos    
}

static ID3_STATE id3State;
static uint8_t  id3Version;
static uint32_t id3Size;

static int32_t ID3_Initialize(uint8_t *buffer)
{
    id3State = ID3_STATE_INIT;
   
    // Parse ID3 Tag Header
    if (memcmp ( buffer, "ID3", 3 ) == 0)  //ID3 v2.x
    {
        ID3V2_TAG_HEADER *tag = (ID3V2_TAG_HEADER*) buffer;

        id3Version = tag->version;
        id3Size = (((( tag->size[0] * 0x80 ) + tag->size[1] ) * 0x80 + tag->size[2] ) * 0x80 ) + tag->size[3];
        id3State = ID3_STATE_READ_V2_FRAME;
    }
    else
    {
        // TODO: move pointer and check for ID3v1
        id3State = ID3_STATE_FINISHED;
        return (uint32_t)0;
    }
    
    id3State = ID3_STATE_READ_V2_FRAME;
    return id3Size;
}

static inline bool ID3V23_Is_ValidFrame(const uint8_t *id){
    uint8_t size = sizeof(ID3V23_FRAME_ID)/4;
    uint8_t i;
    for(i=0;i<size;i++){
        if(memcmp( id, ID3V23_FRAME_ID[i], 4 ) == 0)
        {
            return true;
        }
    }
    return false;
}
static inline bool ID3V22_Is_ValidFrame(const uint8_t *id){
    uint8_t size = sizeof(ID3V22_FRAME_ID)/3;
    uint8_t i;
    for(i=0;i<size;i++)
    {
        if(memcmp( id, ID3V22_FRAME_ID[i], 4 ) == 0){
            return true;
        }
    }
    return false;
}

static uint32_t ID3_Parse_Frame(uint8_t *buffer, size_t left, int8_t *ret){
    uint32_t frameSize;
    int32_t skip = 0;
    
    switch (id3Version)
    {
        case 2:
        {
            ID3V22_FRAME *frame = (ID3V22_FRAME*) buffer;
            if(!ID3V22_Is_ValidFrame(frame->id)){ // if it is not valid frame
                *ret = -2; // skip parsing ID3 tag
                return skip;
            }
            
            frameSize = (( frame->size[0] * 0x100 ) + frame->size[1] ) * 0x100 + frame->size[2];
            
            if (( memcmp ( frame->id, ID3V22_ZERO, 3 ) == 0 ))
            {
                *ret = 0;
                skip = 0;
                break;
            }
            
            if (frameSize == 0){
                *ret = 0;
                skip = sizeof(ID3V22_FRAME_HEADER);
                break;
            }

            uint32_t completeFrameSize = frameSize + sizeof ( ID3V22_FRAME_HEADER );
            // id3 frame content fall off read block
            if (left < completeFrameSize)
            {
                *ret = -1;
                return completeFrameSize;
            }
            
            ID3_ParseFrameV22 (frame, frameSize,ID3V22_ARTIST, ID3_EVENT_TAG_ARTIST);
            ID3_ParseFrameV22 (frame, frameSize, ID3V22_ALBUM, ID3_EVENT_TAG_ALBUM);
            ID3_ParseFrameV22 (frame, frameSize, ID3V22_TITLE, ID3_EVENT_TAG_TITLE);

            skip = completeFrameSize;//frameSize + sizeof ( ID3V22_FRAME_HEADER );
            break;
        }

        case 3:
        case 4:
        {
            ID3V23_FRAME *frame = (ID3V23_FRAME*) buffer;
            if (!ID3V23_Is_ValidFrame(frame->id))
            { // if it is not valid frame
                *ret = -2; // skip parsing ID3 tag
                return skip;
            }

            if (id3Version == 3)
            {
                frameSize = (((( frame->size[0] * 0x100 ) + frame->size[1] ) * 0x100 + frame->size[2] ) * 0x100 ) + frame->size[3];
            }
            else
            {
                frameSize = (((( frame->size[0] * 0x80 ) + frame->size[1] ) * 0x80 + frame->size[2] ) * 0x80 ) + frame->size[3];
            }

            
            if ((memcmp ( frame->id, ID3V23_ZERO, 4 ) == 0))
            {
                skip = 0;
                *ret = 0;
                break;
            }
            
            if (frameSize == 0)
            {
                *ret = 0;
                skip = sizeof(ID3V23_FRAME_HEADER);
                break;
            }
            
            uint32_t completeFrameSize = frameSize + sizeof ( ID3V23_FRAME_HEADER );
            if (left < completeFrameSize)
            {
                // skip this frame
                *ret = -1;
                return completeFrameSize;
            }

            ID3_ParseFrameV23 ( frame, frameSize, ID3V23_ARTIST, ID3_EVENT_TAG_ARTIST );
            ID3_ParseFrameV23 ( frame, frameSize, ID3V23_ALBUM, ID3_EVENT_TAG_ALBUM );
            ID3_ParseFrameV23 ( frame, frameSize, ID3V23_TITLE, ID3_EVENT_TAG_TITLE );

            skip = completeFrameSize;
            break;
        }
    }    
    return skip;
}

static void ID3_ParseFrameV22 (ID3V22_FRAME *frame, uint32_t frameSize, char *id, uint16_t event)
{
    int8_t str[ID3_STRING_SIZE];

    if (memcmp (frame->id, id, 3) == 0)
    {
        if ( ENCODING_FormatASCII ( frame->encoding, frame->contents, frameSize - 1, str, sizeof ( str ) - 1 ) != 0)
        {
            ID3_EventHandler (event, (uint32_t) str);
        }
    }
}

static void ID3_ParseFrameV23 (ID3V23_FRAME *frame, uint32_t frameSize, char *id, uint16_t event)
{
    int8_t str[ID3_STRING_SIZE];

    if (memcmp (frame->id, id, 4) == 0)
    {
        if (ENCODING_FormatASCII (frame->encoding, frame->contents, frameSize - 1, str, sizeof ( str ) - 1 ) != 0)
        {
            ID3_EventHandler (event, (uint32_t) str);
        }
    }
}

static bool ID3_EventHandler (ID3_EVENT event, uint32_t data)
{
    switch ( event )
    {
        case ID3_EVENT_TAG_ARTIST:
            ID3eventHandler(ID3_EVENT_TAG_ARTIST, data);
            return true;

        case ID3_EVENT_TAG_ALBUM:
            ID3eventHandler(ID3_EVENT_TAG_ALBUM, data);
            return true;

        case ID3_EVENT_TAG_TITLE:
            ID3eventHandler(ID3_EVENT_TAG_TITLE, data);
            return true;
    }
    return false;
}
