/*******************************************************************************
  microSD source file

  Company:
    Microchip Technology Inc.

  File Name:
    microsd.c

  Summary:
    This file contains the microSD functionality to read and write to another file

  Description:
    This file has the state machine which contains different states of detection
    of microSD card and the functionality to read from 1st file and write to
    another file
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
#include "microsd.h"
#include "../click_interface.h"

MICROSD_HANDLE microsd_file_open(char *fname, MICROSD_OPEN_ATTRIBUTES attributes )
{
    MICROSD_HANDLE fileHandle;
    fileHandle = (MICROSD_HANDLE)CLICK_MICROSD_SYS_FS_FileOpen(fname, attributes);
    return fileHandle;
}

MICROSD_RESULT microsd_create_directory(char* path)
{
    MICROSD_RESULT res;
    res = CLICK_MICROSD_SYS_FS_DirectoryMake(path);
    return res;
}


size_t microsd_file_read(MICROSD_HANDLE handle,void *buffer,size_t nbyte)
{
    return CLICK_MICROSD_SYS_FS_FileRead((SYS_FS_HANDLE)handle, buffer, nbyte);
}

MICROSD_RESULT microsd_file_close(MICROSD_HANDLE handle)
{
    MICROSD_RESULT res;
    res = CLICK_MICROSD_SYS_FS_FileClose((SYS_FS_HANDLE)handle);
    return res;
}

size_t microsd_file_write(MICROSD_HANDLE handle,const void *buffer,size_t nbyte)
{
    return CLICK_MICROSD_SYS_FS_FileWrite((SYS_FS_HANDLE)handle, buffer, nbyte);
}


