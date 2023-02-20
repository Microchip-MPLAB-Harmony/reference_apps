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
    app_file_handler_private.h

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

// *****************************************************************************
/* APP_FILE_HANDLER_MEDIA_STATUS

  Summary:
    Defines various statuses of media availability

  Description:
    Enumeration of various media availability statuses

  Remarks:
    None.
 */
typedef enum {
    APP_FILE_HANDLER_MEDIA_UNMOUNTED = 0,
    APP_FILE_HANDLER_MEDIA_MOUNTED,
    APP_FILE_HANDLER_LOADING_MEDIA,
    APP_FILE_HANDLER_MEDIA_LOADED
} APP_FILE_HANDLER_MEDIA_STATUS;

// *****************************************************************************
// *****************************************************************************
// Section: Constant definitions
// *****************************************************************************
// *****************************************************************************

// the start index of the media file list
#define APP_FILE_HANDLER_START_INDEX    0

// maximum numbers of supported folders
#define APP_FILE_HANDLER_MAX_FOLDERS    5

// maximum number of files to hold into the structure
#define APP_FILE_HANDLER_MAX_FILES      30

// Application SYS_FS mount points
// the definitions come from configuration.h file
#define APP_FILE_HANDLER_MEDIA_VOLUME_PATH          SYS_FS_MEDIA_IDX0_DEVICE_NAME_VOLUME_IDX0
#define APP_FILE_HANDLER_MEDIA_MOUNT_POINT          SYS_FS_MEDIA_IDX0_MOUNT_NAME_VOLUME_IDX0
#define APP_FILE_HANDLER_MEDIA_FS_TYPE_STRING      "FATFS"

// folder delimiter
#define APP_FILE_HANDLER_MEDIA_FOLDER_DELIMITER_STRING  "/"
#define APP_FILE_HANDLER_MEDIA_FOLDER_DELIMITER_CHAR    '/'

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* APP_FILE_HANDLER_MEDIA_DATA

  Summary:
    Structure to hold data related to media files on the mounted file system

  Description:
    Structure to hold data related to media files on the mounted file system

  Remarks:
    None.
 */
typedef struct __attribute__ ((coherent , aligned(4)))
{
    // the status of the file system
    APP_FILE_HANDLER_MEDIA_STATUS fileSystemMountStatus;
    
    // total files in the volume
    uint32_t totalFiles;
    
    // number of folders found
    uint8_t dirCount;
    
    // the index for current folder to search for files
    uint8_t dirIndex;

    // a table with folder names
    char dirNameList[APP_FILE_HANDLER_MAX_FOLDERS][SYS_FS_FILE_NAME_LEN + 1];

    // a table with  file names
    APP_FILE_HANDLER_DATA  fileNameList[APP_FILE_HANDLER_MAX_FILES];

} APP_FILE_HANDLER_MEDIA_DATA;

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
    This routine confirms if the files are supported by the application.
    This check is made by file name extension

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    TRUE    - file extension is supported
    FALSE   - file extension is not supported

  Example:
    <code>
    if(APP_FileHandler_IsSupportedFile(tempFileName))
    </code>

  Remarks:
    None.
 */
static bool APP_FileHandler_IsSupportedFile(char* fileName);

/*******************************************************************************
  Function:
    void APP_FileHandler_ResetData()

  Summary:
    Initialize data to default values

  Description:
    Initialize data to default values

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_FileHandler_ResetData(void);();
    </code>

  Remarks:
    None.
 */
static void APP_FileHandler_ResetData(void);

/*******************************************************************************
  Function:
    APP_IMAGE_FILE_TYPE APP_FileHandler_Get_Image_Type(SYS_FS_HANDLE)

  Summary:
    Gets the file type from the file header

  Description:
    Looks into the file header and gets the image type

  Precondition:
    None.

  Parameters:
    fileHandler - valid file handler returned by SYS_FS_FileOpen

  Returns:
    APP_IMAGE_FILE_TYPE - the type of the image

  Example:
    <code>
    APP_IMAGE_FILE_TYPE fileType = APP_FileHandler_Get_Image_Type(fileHandle);
    </code>

  Remarks:
    None.
 */
static APP_FILE_HANDLER_IMAGE_TYPE APP_FileHandler_Get_Image_Type(SYS_FS_HANDLE fileHandler);

/*******************************************************************************
  Function:
    void APP_FileHandler_Get_Image_Dimensions(SYS_FS_HANDLE fileHandler, APP_FILE_HANDLER_IMAGE_DIMENSIONS* dimensions, APP_FILE_HANDLER_IMAGE_TYPE imageType)

  Summary:
    Gets the image dimensions in pixels

  Description:
    Looks into the file and gets the image dimensions

  Precondition:
    None.

  Parameters:
    fileHandler - valid file handler returned by SYS_FS_FileOpen
    dimensions  - pointer to the structure where dimensions will be written to
    imageType   - the type of the image

  Returns:
    None.

  Example:
    <code>
    APP_FILE_HANDLER_IMAGE_DIMENSIONS dimensions;
    fileHandle = SYS_FS_FileOpen(fileName, SYS_FS_FILE_OPEN_READ);
    if (fileHandle != SYS_FS_HANDLE_INVALID) {
        APP_FileHandler_Get_Image_Dimensions(fileHandle, &ptrFileData->dimensions, fileType);
    }
    SYS_FS_FileClose(fileHandle);
    </code>

  Remarks:
    None.
 */
static void APP_FileHandler_Get_Image_Dimensions(SYS_FS_HANDLE fileHandler, APP_FILE_HANDLER_IMAGE_DIMENSIONS* dimensions, APP_FILE_HANDLER_IMAGE_TYPE imageType);

/*******************************************************************************
  Function:
    void APP_FileHandler_Get_JPEG_Dimensions(SYS_FS_HANDLE fileHandler, APP_FILE_HANDLER_IMAGE_DIMENSIONS* dimensions)

  Summary:
    Gets the JPEG image dimensions in pixels

  Description:
    Looks into a JPEG file and gets the image dimensions

  Precondition:
    None.

  Parameters:
    fileHandler - valid file handler returned by SYS_FS_FileOpen
    dimensions  - pointer to the structure where dimensions will be written to

  Returns:
    None.

  Example:
    <code>
    APP_FILE_HANDLER_IMAGE_DIMENSIONS dimensions;
    fileHandle = SYS_FS_FileOpen(fileName, SYS_FS_FILE_OPEN_READ);
    if (fileHandle != SYS_FS_HANDLE_INVALID) {
        APP_FileHandler_Get_JPEG_Dimensions(fileHandle, &dimensions);
    }
    SYS_FS_FileClose(fileHandle);
    </code>

  Remarks:
    None.
 */
static void APP_FileHandler_Get_JPEG_Dimensions(SYS_FS_HANDLE fileHandler, APP_FILE_HANDLER_IMAGE_DIMENSIONS *dimensions);

/*******************************************************************************
  Function:
    void APP_FileHandler_Get_BMP_Dimensions(SYS_FS_HANDLE fileHandler, APP_FILE_HANDLER_IMAGE_DIMENSIONS* dimensions)

  Summary:
    Gets the BMP image dimensions in pixels

  Description:
    Looks into a BMP file and gets the image dimensions

  Precondition:
    None.

  Parameters:
    fileHandler - valid file handler returned by SYS_FS_FileOpen
    dimensions  - pointer to the structure where dimensions will be written to

  Returns:
    None.

  Example:
    <code>
    APP_FILE_HANDLER_IMAGE_DIMENSIONS dimensions;
    fileHandle = SYS_FS_FileOpen(fileName, SYS_FS_FILE_OPEN_READ);
    if (fileHandle != SYS_FS_HANDLE_INVALID) {
        APP_FileHandler_Get_BMP_Dimensions(fileHandle, &dimensions);
    }
    SYS_FS_FileClose(fileHandle);
    </code>

  Remarks:
    None.
 */
static void APP_FileHandler_Get_BMP_Dimensions(SYS_FS_HANDLE fileHandler, APP_FILE_HANDLER_IMAGE_DIMENSIONS *dimensions);

/*******************************************************************************
  Function:
    void APP_FileHandler_Get_PNG_Dimensions(SYS_FS_HANDLE fileHandler, APP_FILE_HANDLER_IMAGE_DIMENSIONS* dimensions)

  Summary:
    Gets the PNG image dimensions in pixels

  Description:
    Looks into a PNG file and gets the image dimensions

  Precondition:
    None.

  Parameters:
    fileHandler - valid file handler returned by SYS_FS_FileOpen
    dimensions  - pointer to the structure where dimensions will be written to

  Returns:
    None.

  Example:
    <code>
    APP_FILE_HANDLER_IMAGE_DIMENSIONS dimensions;
    fileHandle = SYS_FS_FileOpen(fileName, SYS_FS_FILE_OPEN_READ);
    if (fileHandle != SYS_FS_HANDLE_INVALID) {
        APP_FileHandler_Get_PNG_Dimensions(fileHandle, &dimensions);
    }
    SYS_FS_FileClose(fileHandle);
    </code>

  Remarks:
    None.
 */
static void APP_FileHandler_Get_PNG_Dimensions(SYS_FS_HANDLE fileHandler, APP_FILE_HANDLER_IMAGE_DIMENSIONS *dimensions);

/*******************************************************************************
  Function:
    void APP_FileHandler_Get_GIF_Dimensions(SYS_FS_HANDLE fileHandler, APP_FILE_HANDLER_IMAGE_DIMENSIONS* dimensions)

  Summary:
    Gets the GIF image dimensions in pixels

  Description:
    Looks into a GIF file and gets the image dimensions

  Precondition:
    None.

  Parameters:
    fileHandler - valid file handler returned by SYS_FS_FileOpen
    dimensions  - pointer to the structure where dimensions will be written to

  Returns:
    None.

  Example:
    <code>
    APP_FILE_HANDLER_IMAGE_DIMENSIONS dimensions;
    fileHandle = SYS_FS_FileOpen(fileName, SYS_FS_FILE_OPEN_READ);
    if (fileHandle != SYS_FS_HANDLE_INVALID) {
        APP_FileHandler_Get_GIF_Dimensions(fileHandle, &dimensions);
    }
    SYS_FS_FileClose(fileHandle);
    </code>

  Remarks:
    None.
 */
static void APP_FileHandler_Get_GIF_Dimensions(SYS_FS_HANDLE fileHandler, APP_FILE_HANDLER_IMAGE_DIMENSIONS *dimensions);

/* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _APP_FILE_HANDLER_PRIVATE_H */

/* EOF */
