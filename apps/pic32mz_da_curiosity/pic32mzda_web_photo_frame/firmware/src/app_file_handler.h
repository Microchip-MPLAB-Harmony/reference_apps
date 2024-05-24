/* ************************************************************************** */
/**  MPLAB Harmony Application Header File

  @Company
     Microchip Technology Inc.

  @File Name
    app_file_handler.h

  @Summary
    This header file provides prototypes and definitions for the 
    file manipulation part of the application.

  @Description
    This is the interface between the application and the media where the files are stored.
 */
/* ************************************************************************** */

/*****************************************************************************
 Copyright (C) 2012-2018 Microchip Technology Inc. and its subsidiaries.

 Microchip Technology Inc. and its subsidiaries.

 Subject to your compliance with these terms, you may use Microchip software
 and any derivatives exclusively with Microchip products. It is your
 responsibility to comply with third party license terms applicable to your
 use of third party software (including open source software) that may
 accompany Microchip software.

 THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
 EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
 WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR
 PURPOSE.
 
 IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
 INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
 BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
 FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
 ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *****************************************************************************/

#ifndef _APP_FILE_HANDLER_H    /* Guard against multiple inclusion */
#define _APP_FILE_HANDLER_H

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
// Section: Constant definitions
// *****************************************************************************
// *****************************************************************************

// Supported Image Type Definitions
// uncomment the supported formats defines
#define APP_SUPPORT_JPEG
// #define APP_SUPPORT_BMP
// #define APP_SUPPORT_PNG
// #define APP_SUPPORT_GIF

// *****************************************************************************
// *****************************************************************************
// Section: Enumerations
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* APP_FILE_HANDLER_IMAGE_TYPE

  Summary:
    Defines various types of media files

  Description:
    Enumeration of various image types

  Remarks:
    None.
 */
typedef enum {
    APP_FILE_HANDLER_IMAGE_TYPE_UNKNOWN = 0,
    APP_FILE_HANDLER_IMAGE_TYPE_BMP,
    APP_FILE_HANDLER_IMAGE_TYPE_JPEG,
    APP_FILE_HANDLER_IMAGE_TYPE_PNG,
    APP_FILE_HANDLER_IMAGE_TYPE_GIF
}APP_FILE_HANDLER_IMAGE_TYPE;

// *****************************************************************************
/* APP_FILE_HANDLER_GET_DIRECTION

  Summary:
    Direction to look for next media file

  Description:
    Enumerates the direction to get the next media file from the list

  Remarks:
    None.
 */
typedef enum{
    APP_FILE_HANDLER_GET_CURRENT = 1,
    APP_FILE_HANDLER_GET_PREVIOUS,
    APP_FILE_HANDLER_GET_NEXT
}APP_FILE_HANDLER_GET_DIRECTION;

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* APP_FILE_HANDLER_IMAGE_DIMENSIONS

  Summary:
    Structure to hold the media file dimensions in pixels

  Description:
    Structure to hold the media file dimensions in pixels

  Remarks:
    None.
 */
typedef struct __attribute__ ((coherent , aligned(4)))
{
    uint32_t width;
    uint32_t height;
} APP_FILE_HANDLER_IMAGE_DIMENSIONS;

// *****************************************************************************
/* APP_FILE_HANDLER_DATA

  Summary:
    Structure to hold data related to one media file

  Description:
    The data about media file is kept in a structure. 
    It defines various parameters of the file

  Remarks:
    None.
 */
typedef struct __attribute__ ((coherent , aligned(4)))
{
    // tracks the current image to show
    uint32_t mediaFileIdx;
    
    // full path to the file
    char mediaFullPath[SYS_FS_FILE_NAME_LEN + 1];
    
    // relative path to the file for web URL
    char* mediaWebPath;
    
    // the type of the image: jpeg etc...
    APP_FILE_HANDLER_IMAGE_TYPE fileType;

    // image dimensions in pixels
    APP_FILE_HANDLER_IMAGE_DIMENSIONS dimensions;
} APP_FILE_HANDLER_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Callback Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_FileHandler_SYS_FS_EventHandler ( void )

  Summary:
    SYS_FS callback function

  Description:
    This routine is set as callback for the File System when the media 
    is mounted or unmounted
    It is usually set in the application initialization function

  Precondition:
    

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    SYS_FS_EventHandlerSet(APP_FileHandler_SYS_FS_EventHandler, (uintptr_t)NULL);
    </code>

  Remarks:
    This routine should not be called directly
 */
void APP_FileHandler_SYS_FS_EventHandler(SYS_FS_EVENT event, void* eventData, uintptr_t context);

// *****************************************************************************
// *****************************************************************************
// Section: Interface Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
     bool APP_FileHandler_IsMediaMounted( void )

  Summary:
    Says if the Media is mounted or not

  Description:
    This function is a getter of the private flag that says if the media is mounted or not

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    TRUE    - media is mounted
    FALSE   - media is not mounted

  Example:
    <code>
    // check for the media if it is mounted
    if (APP_FileHandler_IsMediaMounted() == false) {
        // change state
        appData.state = APP_STATE_MEDIA_UNMOUNTED;
    }
    </code>

  Remarks:
    None.
 */
bool APP_FileHandler_IsMediaMounted();

/*******************************************************************************
  Function:
     bool APP_FileHandler_IsMediaLoaded( void )

  Summary:
    Says if the Media finished to be parsed and loaded into the media data

  Description:
    The time to look through the files on the mounted Media takes some time
    and it is possible to check if all media is loaded or not before starting the slide show

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    TRUE    - media is loaded
    FALSE   - media is not loaded

  Example:
    <code>
    // check for the media if it is mounted
    if (APP_FileHandler_IsMediaLoaded() == true) {
        // change state
        appData.state = APP_STATE_MEDIA_LOADED;
    }
    </code>

  Remarks:
    None
 */
bool APP_FileHandler_IsMediaLoaded(void);

/*******************************************************************************
  Function:
     uint32_t APP_FileHandler_GetMaxNumberOfFiles( void )

  Summary:
    Gets the maximum number of files the app can handle

  Description:
    Gets the maximum number of files the app can handle. 
    This is defined into the APP_MEDIA_MAX_FILES
    Used to set the first index before starting to fetch files from the list

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    number of files that can be loaded

  Example:
    <code>
    // Image file index into the file list.
    appGfxData.currentAppGfxFileIdx = APP_FileHandler_GetMaxNumberOfFiles();
    </code>

  Remarks:
    None
 */
uint32_t APP_FileHandler_GetMaxNumberOfFiles(void);

/*******************************************************************************
  Function:
    bool APP_FileHandler_GatherAvailableMedia( void )

  Summary:
    Traverse a folder structure and get supported media files

  Description:
    This function looks on the media and gathers all available media
    Returns FALSE if all folders are traversed
    Returns TRUE when all done
    It also populates the available file list with the files that are supported by the app
    The function is called more than one time, to allow other things to happen 

  Precondition:
    Media must be mounted on the file system

  Parameters:
    None.

  Returns:
    TRUE    - all files have been looked for
    FALSE   - the function needs to be called again

  Example:
    <code>
    // gather the media from the SD Card
    // the function should be called till it returns true            
    if (APP_FileHandler_GatherAvailableMedia() == true) {
        // change state
        appData.state = APP_GOING_ON;
    }
    </code>

  Remarks:
    When RTOS is available, the function can be called into a while loop
 */
bool APP_FileHandler_GatherAvailableMedia(void);

/*******************************************************************************
  Function:
    uint32_t APP_FileHandler_GetNumberOfMediaFiles( void )

  Summary:
    Returns the number of indexed media files

  Description:
    This is used to decide if at least one media file has been indexed, 
    so the streaming can start

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    number of files indexed.

  Example:
    <code>
    if (APP_FileHandler_GetNumberOfMediaFiles() == 0) {
        // no media to stream
        return false;
    }
    </code>

  Remarks:
    None.
 */
uint32_t APP_FileHandler_GetNumberOfMediaFiles(void);

/*******************************************************************************
  Function:
    void APP_FileHandler_Initialize( void )

  Summary:
    Initialize data to startup values

  Description:
    Initialize data to startup values

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_FileHandler_Initialize();
    </code>

  Remarks:
    None.
 */
void APP_FileHandler_Initialize(void);

/*******************************************************************************
  Function:
    APP_FILE_HANDLER_DATA*  APP_FileHandler_GetPictureToShow(uint32_t fileIndex, APP_FILE_HANDLER_GET_DIRECTION next_prev)

  Summary:
    Gets the next file to show by into index in the file list

  Description:
    Gets the index of the file to show forward, backwards of current

  Precondition:
    Media should be loaded into the file list

  Parameters:
    fileIndex   - any integer value, the file handler handles a bad value
    direction   - next, previous or current

  Returns:
    APP_FILE_DATA*  - if there is a file to return
    NULL            - no file available

  Example:
    <code>
    // ask the file handler for the next picture to show
    appGfxData.appGfxFileData = APP_FileHandler_GetPictureToShow(appGfxData.currentAppGfxFileIdx, APP_FILE_HANDLER_GET_NEXT);
    </code>

  Remarks:
    None.
 */
APP_FILE_HANDLER_DATA*  APP_FileHandler_GetPictureToShow(uint32_t fileIndex, APP_FILE_HANDLER_GET_DIRECTION next_prev);

/*******************************************************************************
  Function:
    APP_FILE_DATA* APP_FileHandler_GetPictureByWebName(char* webFileName)

  Summary:
    Gets the file to show by web file name

  Description:
    Gets the details of the file to show, by web file path

  Precondition:
    Media should be loaded into the file list

  Parameters:
    webFileName   - a file name

  Returns:
    APP_FILE_DATA*  - if there is a file to return
    NULL            - no file available

  Example:
    <code>
    // gets the picture by received file name
    appFileData = APP_FileHandler_GetPictureByWebName((char*)ptrFileName);
    </code>

  Remarks:
    None.
 */
APP_FILE_HANDLER_DATA* APP_FileHandler_GetPictureByWebName(char* webFileName);


/* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _APP_FILE_HANDLER_H */

/******************************************************************************
 End of File
 */
