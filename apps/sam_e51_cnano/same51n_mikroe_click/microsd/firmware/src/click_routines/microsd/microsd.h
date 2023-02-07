/*******************************************************************************
  microSD Header file

  Company:
    Microchip Technology Inc.

  File Name:
    microsd.h

  Summary:
    This file contains prototypes/declarations of functions used in microsd.c

  Description:
    This file has declarations for functions which take care of various file
    operations and also has the structures and enums used by the microsd.c source
    file
 *******************************************************************************/
// DOM-IGNORE-BEGIN
/*
    (c) 2023 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/
// DOM-IGNORE-END
// ----------------------------------------------------------------------------

#ifndef MICROSD_H
#define MICROSD_H

#include "definitions.h"

typedef uintptr_t MICROSD_HANDLE;

#define MICROSD_HANDLE_INVALID   ((MICROSD_HANDLE)(-1))

typedef enum
{
    /*
    reading the file    =   possible, if file exists.
    reading the file    =   file open returns error, if file does not exist.
    writing to the file =   not possible. Write operation returns error
    */
    MICROSD_OPEN_READ    =  0,

    /*
    reading the file    =  not possible. Read operation returns error.
    writing to the file =  possible. If file exists, write happens from the
                           beginning of the file, overwriting the existing
                           content of the file.
    writing to the file =  If file does not exist, a new file will be created
                           and data will be written into the newly created file.
    */
    MICROSD_OPEN_WRITE,

    /*
    reading the file    =  not possible. Read operation returns error
    writing to the file =  possible. If file exists, write happens from
                           the end of the file, preserving the existing
                           content of the file.
    writing to the file =  If file does not exist, a new file will be created
                           and data will be written into the newly created file.
    */
    MICROSD_OPEN_APPEND,

    /*
    reading the file    =   possible, if file exists.
    reading the file    =   file open returns error, if file does not exist.
    writing to the file =   possible, if file exists, staring from the beginning
                            of the file (overwriting).
    writing to the file =   file open returns error, if file does not exist.
    */
    MICROSD_OPEN_READ_PLUS,

    /*
    reading the file    =  possible, if file exists.
    reading the file    =  If file does not exist, a new file will be created.
    writing to the file =  possible. If file exists, write happens from
                           the beginning of the file, overwriting the existing
                           content of the file.
    writing to the file =  If file does not exist, a new file will be created
                           and data will be written into the newly created file.
    */
    MICROSD_OPEN_WRITE_PLUS,

    /*
    reading the file    =  possible, if file exists. File read pointer
                           will be moved to end of the file in this mode.
    reading the file    =  If file does not exist, a new file will be created.
    writing to the file =  possible. If file exists, write happens from
                           the end of the file, preserving the existing
                           content of the file.
    writing to the file =  If file does not exist, a new file will be created
                           and data will be written into the newly created file.
    */
    MICROSD_OPEN_APPEND_PLUS

} MICROSD_OPEN_ATTRIBUTES;

typedef enum
{
    /* Operation succeeded */
    MICROSD_RES_SUCCESS    =  0,
    /* Operation failed */
    MICROSD_RES_FAILURE    = -1

} MICROSD_RESULT;

typedef enum
{
    /* Unsupported File System */
    SD_UNSUPPORTED_FS = 0,

    /* FAT FS native File system */
    SD_FAT,

    /* MPFS2 native File system */
    SD_MPFS2,

    /*  LittleFS native File system */
    SD_LITTLEFS

} MICROSD_FILE_SYSTEM_TYPE;

/* Function:
  MICROSD_HANDLE microsd_file_open(char *fname, MICROSD_OPEN_ATTRIBUTES attributes);

  Summary:
    This function opens a file for file operations

  Description:
    This function opens the file in read/write mode and stores the information in
    fileHandle

  Remarks:

*/
MICROSD_HANDLE microsd_file_open(char *fname, MICROSD_OPEN_ATTRIBUTES attributes);

/* Function:
  MICROSD_RESULT microsd_file_close(MICROSD_HANDLE handle);

  Summary:
    This function closes a file

  Description:
    This function closes a specific file based upon the fileHandle

  Remarks:

*/
MICROSD_RESULT microsd_file_close(MICROSD_HANDLE handle);

/* Function:
  size_t microsd_file_read(MICROSD_HANDLE handle,void *buffer,size_t nbyte);

  Summary:
    This function reads the content of a file based on fileHandle

  Description:
    This function reads the content of a file when it is opened in read mode

  Remarks:

*/
size_t microsd_file_read(MICROSD_HANDLE handle,void *buffer,size_t nbyte);

/* Function:
  size_t microsd_file_write(MICROSD_HANDLE handle,const void *buffer,size_t nbyte);

  Summary:
    This function writes the content of a file based on fileHandle

  Description:
    This function writes the content of a file when it is opened in write mode

  Remarks:

*/
size_t microsd_file_write(MICROSD_HANDLE handle,const void *buffer,size_t nbyte);

/* Function:
 MICROSD_RESULT microsd_create_directory(char *dirName);

  Summary:
    This function creates a directory

  Description:
    This function creates a directory by taking directory name as a parameter

  Remarks:

*/
MICROSD_RESULT microsd_create_directory(char *dirName);

#endif //MICROSD_H