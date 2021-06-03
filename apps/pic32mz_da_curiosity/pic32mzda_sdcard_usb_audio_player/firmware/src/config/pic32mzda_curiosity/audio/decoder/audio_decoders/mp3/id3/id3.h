/*******************************************************************************
 MP3 ID3 Tag Parser Header File

  Company:
    Microchip Technology Inc.

  File Name:
    id3.h

  Summary:
    MP3 Decoder ID3 parser header API.
  
  Description:
    This file provides MP3 Decoder ID3 parser header APIs.
 
*******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2014 Microchip Technology Inc.  All rights reserved.

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
// DOM-IGNORE-END

#ifndef ID3_H
#define ID3_H

//// DOM-IGNORE-BEGIN
#ifdef __cplusplus
extern "C" {
#endif
// DOM-IGNORE-END

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h> 
#include "utils.h"
#include "system/fs/sys_fs.h"   // for SYS_FS_HANDLE
    
typedef void (*ID3_EVENT_HANDLER)(int event, uint32_t data);    
    
void read_ID3Tags(SYS_FS_HANDLE fileHandle, uint8_t *heap, ID3_EVENT_HANDLER eventHandler);

#define ID3_STRING_SIZE 128

typedef struct
{
    uint8_t tag[3];
    int8_t  title[30];
    int8_t  artist[30];
    int8_t  album[30];
    int8_t  year[4];
    union
    {
        int8_t  comment[30];
        struct
        {
            int8_t  commentShort[28];
            uint8_t zero;
            uint8_t track;
        };
    };
    uint8_t genre;
}
ID3V1_TAG;

typedef struct
{
    uint8_t tag[4];
    int8_t  title[60];
    int8_t  artist[60];
    int8_t  album[60];
    uint8_t speed;
    int8_t  genre[30];
    int8_t  startTime[6];
    int8_t  endTime[6];
}
ID3V1_EXTENDED_TAG;

typedef struct
{
    uint8_t   tag[3];
    uint8_t   version;
    uint8_t   empty;
    uint8_t   flag;
    uint8_t   size[4];
}
ID3V2_TAG_HEADER;

typedef struct
{
    uint8_t id[3];
    uint8_t size[3];
}
ID3V22_FRAME_HEADER;

typedef struct
{
    uint8_t   id[3];
    uint8_t   size[3];
    uint8_t   encoding;
    uint8_t   contents[1];
}
ID3V22_FRAME;

typedef struct
{
    uint8_t   id[4];
    uint8_t   size[4];
    uint8_t   flags[2];
}
ID3V23_FRAME_HEADER;

typedef struct
{
    uint8_t   id[4];
    uint8_t   size[4];
    uint8_t   flags[2];
    uint8_t   encoding;
    uint8_t   contents[1];
}
ID3V23_FRAME;

typedef enum
{
    ID3_STATE_INIT,
    ID3_STATE_READ_V1,
    ID3_STATE_READ_V2_HEADER,
    ID3_STATE_READ_V2_FRAME,
    ID3_STATE_FINISHED,
}
ID3_STATE;

#define     ID3V22_ZERO     "\0\0\0"
#define     ID3V22_TITLE    "TT2"
#define     ID3V22_ARTIST   "TP1"
#define     ID3V22_ALBUM    "TAL"
#define     ID3V23_ZERO     "\0\0\0\0"
#define     ID3V23_TITLE    "TIT2"
#define     ID3V23_ARTIST   "TPE1"
#define     ID3V23_ALBUM    "TALB"

// <editor-fold defaultstate="collapsed" desc="ID3v2 Frame ID String">
//4.20    AENC    [[#sec4.20|Audio encryption]]
//4.15    APIC    [#sec4.15 Attached picture]
//4.11    COMM    [#sec4.11 Comments]
//4.25    COMR    [#sec4.25 Commercial frame]
//4.26    ENCR    [#sec4.26 Encryption method registration]
//4.13    EQUA    [#sec4.13 Equalization]
//4.6     ETCO    [#sec4.6 Event timing codes]
//4.16    GEOB    [#sec4.16 General encapsulated object]
//4.27    GRID    [#sec4.27 Group identification registration]
//4.4     IPLS    [#sec4.4 Involved people list]
//4.21    LINK    [#sec4.21 Linked information]
//4.5     MCDI    [#sec4.5 Music CD identifier]
//4.7     MLLT    [#sec4.7 MPEG location lookup table]
//4.24    OWNE    [#sec4.24 Ownership frame]
//4.28    PRIV    [#sec4.28 Private frame]
//4.17    PCNT    [#sec4.17 Play counter]
//4.18    POPM    [#sec4.18 Popularimeter]
//4.22    POSS    [#sec4.22 Position synchronisation frame]
//4.19    RBUF    [#sec4.19 Recommended buffer size]
//4.12    RVAD    [#sec4.12 Relative volume adjustment]
//4.14    RVRB    [#sec4.14 Reverb]
//4.10    SYLT    [#sec4.10 Synchronized lyric/text]
//4.8     SYTC    [#sec4.8 Synchronized tempo codes]
//4.2.1   TALB    [#TALB Album/Movie/Show title]
//4.2.1   TBPM    [#TBPM BPM (beats per minute)]
//4.2.1   TCOM    [#TCOM Composer]
//4.2.1   TCON    [#TCON Content type]
//4.2.1   TCOP    [#TCOP Copyright message]
//4.2.1   TDAT    [#TDAT Date]
//4.2.1   TDLY    [#TDLY Playlist delay]
//4.2.1   TENC    [#TENC Encoded by]
//4.2.1   TEXT    [#TEXT Lyricist/Text writer]
//4.2.1   TFLT    [#TFLT File type]
//4.2.1   TIME    [#TIME Time]
//4.2.1   TIT1    [#TIT1 Content group description]
//4.2.1   TIT2    [#TIT2 Title/songname/content description]
//4.2.1   TIT3    [#TIT3 Subtitle/Description refinement]
//4.2.1   TKEY    [#TKEY Initial key]
//4.2.1   TLAN    [#TLAN Language(s)]
//4.2.1   TLEN    [#TLEN Length]
//4.2.1   TMED    [#TMED Media type]
//4.2.1   TOAL    [#TOAL Original album/movie/show title]
//4.2.1   TOFN    [#TOFN Original filename]
//4.2.1   TOLY    [#TOLY Original lyricist(s)/text writer(s)]
//4.2.1   TOPE    [#TOPE Original artist(s)/performer(s)]
//4.2.1   TORY    [#TORY Original release year]
//4.2.1   TOWN    [#TOWN File owner/licensee]
//4.2.1   TPE1    [#TPE1 Lead performer(s)/Soloist(s)]
//4.2.1   TPE2    [#TPE2 Band/orchestra/accompaniment]
//4.2.1   TPE3    [#TPE3 Conductor/performer refinement]
//4.2.1   TPE4    [#TPE4 Interpreted, remixed, or otherwise modified by]
//4.2.1   TPOS    [#TPOS Part of a set]
//4.2.1   TPUB    [#TPUB Publisher]
//4.2.1   TRCK    [#TRCK Track number/Position in set]
//4.2.1   TRDA    [#TRDA Recording dates]
//4.2.1   TRSN    [#TRSN Internet radio station name]
//4.2.1   TRSO    [#TRSO Internet radio station owner]
//4.2.1   TSIZ    [#TSIZ Size]
//4.2.1   TSRC    [#TSRC ISRC (international standard recording code)]
//4.2.1   TSSE    [#TSEE Software/Hardware and settings used for encoding]
//4.2.1   TYER    [#TYER Year]
//4.2.2   TXXX    [#TXXX User defined text information frame]
//4.1     UFID    [#sec4.1 Unique file identifier]
//4.23    USER    [#sec4.23 Terms of use]
//4.9     USLT    [#sec4.9 Unsychronized lyric/text transcription]
//4.3.1   WCOM    [#WCOM Commercial information]
//4.3.1   WCOP    [#WCOP Copyright/Legal information]
//4.3.1   WOAF    [#WOAF Official audio file webpage]
//4.3.1   WOAR    [#WOAR Official artist/performer webpage]
//4.3.1   WOAS    [#WOAS Official audio source webpage]
//4.3.1   WORS    [#WORS Official internet radio station homepage]
//4.3.1   WPAY    [#WPAY Payment]
//4.3.1   WPUB    [#WPUB Publishers official webpage]
//4.3.2   WXXX    [#WXXX User defined URL link frame]
// </editor-fold>
static char __attribute__((unused))ID3V23_FRAME_ID[74][4]={"AENC", "APIC", "COMM", "COMR", "ENCR", "EQUA", 

        "ETCO", "GEOB", "GRID", "IPLS", "LINK", "MCDI", 

        "MLLT", "OWNE", "PRIV", "PCNT", "POPM", "POSS", 

        "RBUF", "RVAD", "RVRB", "SYLT", "SYTC", "TALB", 

        "TBPM", "TCOM", "TCON", "TCOP", "TDAT", "TDLY", 

        "TENC", "TEXT", "TFLT", "TIME", "TIT1", "TIT2", 

        "TIT3", "TKEY", "TLAN", "TLEN", "TMED", "TOAL", 

        "TOFN", "TOLY", "TOPE", "TORY", "TOWN", "TPE1", 

        "TPE2", "TPE3", "TPE4", "TPOS", "TPUB", "TRCK", 

        "TRDA", "TRSN", "TRSO", "TSIZ", "TSRC", "TSSE", 

        "TYER", "TXXX", "UFID", "USER", "USLT", "WCOM", 

        "WCOP", "WOAF", "WOAR", "WOAS", "WORS", "WPAY", 

        "WPUB", "WXXX"};

static char __attribute__((unused))ID3V22_FRAME_ID[63][3] = {"BUF", "CNT", "COM", "CRA", "CRM", "ETC", 

"EQU", "GEO", "IPL", "LNK", "MCI", "MLL", 

"PIC", "POP", "REV", "RVA", "SLT", "STC", 

"TAL", "TBP", "TCM", "TCO", "TCR", "TDA", 

"TDY", "TEN", "TFT", "TIM", "TKE", "TLA", 

"TLE", "TMT", "TOA", "TOF", "TOL", "TOR", 

"TOT", "TP1", "TP2", "TP3", "TP4", "TPA", 

"TPB", "TRC", "TRD", "TRK", "TSI", "TSS", 

"TT1", "TT2", "TT3", "TXT", "TXX", "TYE", 

"UFI", "ULT", "WAF", "WAR", "WAS", "WCM", 

"WCP", "WPB", "WXX"
};
typedef enum
{
    ID3_EVENT_TAG_ARTIST,
    ID3_EVENT_TAG_ALBUM,
    ID3_EVENT_TAG_TITLE
}
ID3_EVENT;

#ifdef __cplusplus
}
#endif

#endif
