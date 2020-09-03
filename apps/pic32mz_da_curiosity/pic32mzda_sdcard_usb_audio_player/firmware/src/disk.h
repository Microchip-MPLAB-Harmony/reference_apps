/*******************************************************************************
  Universal Audio Decoders Application Demo

  Company:
    Microchip Technology Inc.

  File Name:
    disk.h

  Summary:
    Contains the file system specific definitions and function prototypes.

  Description:
    This file contains the file system specific definitions and function
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

#ifndef DISK_H
#define	DISK_H

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
extern "C" {
#endif
//DOM-IGNORE-END
    
#include <string.h>
    
#define DISK_MAX_DIRS   10
#define DISK_MAX_FILES  250

typedef enum{
    DISK_EVENT_REMOVED,
    DISK_EVENT_INSERTED,
    DISK_EVENT_SCANNING_STARTED,
    DISK_EVENT_SCANNING_FINISHED,
    DISK_EVENT_TRACK_CHANGED,
    DISK_EVENT_END_OF_FILE,
    DISK_EVENT_FILE_OPEN_ERROR
}DISK_EVENT;

typedef enum
{
    DISK_STATE_HALT,
    DISK_STATE_INIT,
    DISK_STATE_SCAN_FINISHED,
    DISK_STATE_OPEN_FIRST_TRACK,
    DISK_STATE_SCANNING,
    DISK_STATE_RUNNING,
    DISK_STATE_REMOVED,
    //DISK_STATE_ERROR,
    DISK_STATE_NO_AUDIO_FILES
}DISK_TASK_STATE;

typedef enum{
    DISK_SCAN_OPEN_DIR,
    DISK_SCAN_READ_DIR,
   // DISK_SCAN_FILE_SEARCH,
    DISK_SCAN_FILE_SEARCH_COMPLETE,
    DISK_SCAN_ERROR,
}DISK_SCAN_STATE;

typedef struct{
    SYS_FS_FSTAT fstat;
    char path[64];
}DISK_FILE_NODE;

typedef struct{
    char path[64]; // at most 64 bytes long
    bool trackPlayed;
}DISK_FILE_PATH;

typedef struct
{
    DISK_SCAN_STATE scanstate;
    DISK_TASK_STATE state;
       /* SYS_FS File handle for dir */
    SYS_FS_HANDLE dirHandle;
    /* SYS_FS stat for dir read */
    SYS_FS_FSTAT dirstat;
}DISK_TASK_DATA;

void            DISK_Initialize(void);
bool            DISK_EndOfFile(void);
bool            DISK_OpenTrack(const char *fname);
bool            DISK_FileStatus(const char *fname);
SYS_FS_HANDLE   DISK_OpenFile(const char *fname);
bool            DISK_EventHandler ( DISK_EVENT event, uint32_t data ,SYS_FS_HANDLE fileHandle);
void            DISK_Tasks(void);
bool            DISK_CloseFile ( SYS_FS_HANDLE fileHandle );
uint32_t        DISK_GetFileSize(SYS_FS_HANDLE fileHandle);
int32_t         DISK_GetFilePosition ( SYS_FS_HANDLE fileHandle );
void            DISK_SetNextTrack( void );
bool            DISK_AreAllTracksPlayed( void );
void            DISK_ResetPlayedTracks( void );
//bool            DISK_FSeek(SYS_FS_HANDLE fileHandle,int32_t offset);
//bool            DISK_Mount(void);
//bool            DISK_Unmount(void);
//bool            DISK_ScanTask(void);
//bool            DISK_isCurrentPathRoot();
//bool            DISK_ScanFiles(void);
//bool            DISK_NextTrack(void);
//bool            DISK_PreviousTrack(void);

//ListNode*       DISK_Get_FileNameList();
//bool            DISK_FileNameGet(SYS_FS_HANDLE handle, char* cName);
//bool            DISK_FillBuffer(uint8_t *ptr);
//bool            DISK_FirstTrack( void);
//bool            DISK_ReopenTrack(void);
//bool            DISK_SeekStartLocation(SYS_FS_HANDLE fileHandle,int32_t offset);
//bool            DISK_SetFilePosition (SYS_FS_HANDLE fileHandle, int32_t pos );
//uint16_t        DISK_GetTotalFiles ( void );
//uint32_t        DISK_ReadCurrentFile(uint8_t *ptr, size_t readSize);
//uint32_t        DISK_GetCurrentFileSize();
//void            DISK_ReadHeader(uint8_t *ptr,int32_t readsize);
//bool            DISK_SetCurrentFilePositionWithControl(int32_t pos, SYS_FS_FILE_SEEK_CONTROL whence);
//int32_t         DISK_GetCurrentFilePosition();
//bool            DISK_SetCurrentFilePosition(int32_t pos);

#ifdef __cplusplus
}
#endif

#endif	/* DISK_H */

