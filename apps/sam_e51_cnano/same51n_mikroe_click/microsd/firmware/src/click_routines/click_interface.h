/*******************************************************************************
  microSD click routine interface header file

  Company
    Microchip Technology Inc.

  File Name
    click_interface.h

  Summary
    microSD click routine interface implementation File.

  Description
    This file defines the interface to the microSD click routines and File System APIs.

  Remarks:
    None.

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

#ifndef _CLICK_INTERFACES_H
#define _CLICK_INTERFACES_H

/**
  Section: Included Files
 */

#include <xc.h>
#include <stdint.h>

/** microSD click uses the file system APIs to perform various file operations.
 *  These macros can be used as interfaces to these file system functions
 */

#define CLICK_MICROSD_SYS_FS_Mount                  SYS_FS_Mount
#define CLICK_MICROSD_SYS_FS_Unmount                SYS_FS_Unmount
#define CLICK_MICROSD_SYS_FS_CurrentDriveSet        SYS_FS_CurrentDriveSet
#define CLICK_MICROSD_SYS_FS_FileOpen               SYS_FS_FileOpen
#define CLICK_MICROSD_SYS_FS_DirectoryMake          SYS_FS_DirectoryMake
#define CLICK_MICROSD_SYS_FS_FileRead               SYS_FS_FileRead
#define CLICK_MICROSD_SYS_FS_FileWrite              SYS_FS_FileWrite
#define CLICK_MICROSD_SYS_FS_FileClose              SYS_FS_FileClose
#define CLICK_MICROSD_SYS_FS_FileOpenWrite          SYS_FS_FileOpenWrite
#define CLICK_MICROSD_SYS_FS_FileEOF                SYS_FS_FileEOF

#endif // _CLICK_INTERFACES_H
