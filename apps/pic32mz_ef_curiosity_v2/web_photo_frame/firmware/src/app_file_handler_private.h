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

/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_file_handler.h

  Summary:
    This header file provides prototypes and definitions for the file manipulation part of the application.

  Description:
    
*******************************************************************************/

#ifndef _APP_FILE_HANDLER_PRIVATE_H    /* Guard against multiple inclusion */
#define _APP_FILE_HANDLER_PRIVATE_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stdint.h>
#include <stdbool.h>
// harmony library files
#include <definitions.h>

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Enumerations
// *****************************************************************************
// *****************************************************************************
// file media status
typedef enum {
    APP_FILE_MEDIA_UNMOUNTED = 0,
    APP_FILE_MEDIA_MOUNTED,
    APP_FILE_LOADING_MEDIA,
    APP_FILE_MEDIA_LOADED
} APP_FILE_MEDIA_STATUS;

// *****************************************************************************
// *****************************************************************************
// Section: Constant definitions
// *****************************************************************************
// *****************************************************************************

// the start index of the media file list
#define APP_FILE_START_INDEX    0

// maximum numbers of supported folders
#define APP_MEDIA_MAX_FOLDERS   5

// maximum number of files to hold into the structure
#define APP_MEDIA_MAX_FILES     30

// Application SYS_FS mount points
// the definitions come from configuration.h file
#define APP_SYS_FS_SD_VOL           SYS_FS_MEDIA_IDX0_DEVICE_NAME_VOLUME_IDX0
#define APP_SYS_FS_MOUNT_POINT      SYS_FS_MEDIA_IDX0_MOUNT_NAME_VOLUME_IDX0
#define APP_SYS_FS_TYPE_STRING      "FATFS"

// folder delimiter
#define APP_SYS_FS_FOLDER_DELIMITER "/"

// Supported Image Definitions
#define APP_SUPPORT_JPEG
//#define APP_SUPPORT_BMP
//#define APP_SUPPORT_PNG
//#define APP_SUPPORT_GIF

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

// structure to hold data related to media files on the mounted file system
typedef struct __attribute__ ((coherent , aligned(4)))
{
    // the status of the file system
    APP_FILE_MEDIA_STATUS fileSystemMountStatus;
    
    // total files in the volume
    uint32_t totalFiles;
    
    // number of folders found
    uint8_t dirCount;
    
    // the index for current folder to search for files
    uint8_t dirIndex;

    // a table with folder names
    APP_FILE_DATA  dirNameList[APP_MEDIA_MAX_FOLDERS];

    // a table with  file names
    APP_FILE_DATA  fileNameList[APP_MEDIA_MAX_FILES];

} APP_MEDIA_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Local Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    bool APP_FileHandler_IsSupportedFile(char *name)

  Summary:
    Function to check if the file is supported by file extension.

  Description:
    This function confirms if the files are supported by the application.
    This is made by file name extension
*/
static bool APP_FileHandler_IsSupportedFile(char* fileName);

/*******************************************************************************
  Function:
    void APP_FileHandler_ResetData()

  Summary:
    Initialize data to startup values

  Description:
    Initialize data to startup values
*/
static void APP_FileHandler_ResetData(void);

/*******************************************************************************
  Function:
    APP_IMAGE_FILE_TYPE APP_FileHandler_Get_Image_Type(SYS_FS_HANDLE)

  Summary:
    Gets the file type

  Description:
    Looks into the file header and gets the image type
*/
static APP_IMAGE_FILE_TYPE APP_FileHandler_Get_Image_Type(SYS_FS_HANDLE fileHandler);

/*******************************************************************************
  Function:
    void APP_FileHandler_Get_Image_Dimensions()

  Summary:
    Gets gets the image dimensions

  Description:
    Looks into the file and gets the image dimensions
*/
static void APP_FileHandler_Get_Image_Dimensions(SYS_FS_HANDLE fileHandler, APP_FILE_IMAGE_DIMENSIONS* dimensions, APP_IMAGE_FILE_TYPE imageType);

/*******************************************************************************
  Function:
    void APP_FileHandler_Get_JPEG_Dimensions(SYS_FS_HANDLE fileHandler, APP_FILE_IMAGE_DIMENSIONS *dimensions)

  Summary:
    Gets gets the image JPEG dimensions

  Description:
    Looks into the JPEG and gets the image dimensions
*/
static void APP_FileHandler_Get_JPEG_Dimensions(SYS_FS_HANDLE fileHandler, APP_FILE_IMAGE_DIMENSIONS *dimensions);

/*******************************************************************************
  Function:
    void APP_FileHandler_Get_BMP_Dimensions(SYS_FS_HANDLE fileHandler, APP_FILE_IMAGE_DIMENSIONS *dimensions)

  Summary:
    Gets gets the image BMP dimensions

  Description:
    Looks into the BMP and gets the image dimensions
*/
static void APP_FileHandler_Get_BMP_Dimensions(SYS_FS_HANDLE fileHandler, APP_FILE_IMAGE_DIMENSIONS *dimensions);

/*******************************************************************************
  Function:
    void APP_FileHandler_Get_PNG_Dimensions(SYS_FS_HANDLE fileHandler, APP_FILE_IMAGE_DIMENSIONS *dimensions)

  Summary:
    Gets gets the image PNG dimensions

  Description:
    Looks into the PNG and gets the image dimensions
*/
static void APP_FileHandler_Get_PNG_Dimensions(SYS_FS_HANDLE fileHandler, APP_FILE_IMAGE_DIMENSIONS *dimensions);

/*******************************************************************************
  Function:
    void APP_FileHandler_Get_GIF_Dimensions(SYS_FS_HANDLE fileHandler, APP_FILE_IMAGE_DIMENSIONS *dimensions)

  Summary:
    Gets gets the image GIF dimensions

  Description:
    Looks into the GIF and gets the image dimensions
*/
static void APP_FileHandler_Get_GIF_Dimensions(SYS_FS_HANDLE fileHandler, APP_FILE_IMAGE_DIMENSIONS *dimensions);

/* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _APP_FILE_HANDLER_PRIVATE_H */

/* EOF */
