/* ************************************************************************** */
/**   Graphics Application Private Header File

  @Company
    Microchip Technology Inc.

  @File Name
    app_gfx_private.h

  @Summary
    This header file provides prototypes and definitions for the graphics application.

  @Description
    This header file provides function prototypes and data type definitions for
    the graphics application.
 *//* ************************************************************************** */

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

#ifndef APP_GFX_PRIVATE_H
#define	APP_GFX_PRIVATE_H

// harmony library files
#include "definitions.h"
#include "app_file_handler.h"

#ifdef	__cplusplus
extern "C" {
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Constant definitions
// *****************************************************************************
// *****************************************************************************

// screen dimensions
#define APP_GFX_SCREEN_WIDTH    480
#define APP_GFX_SCREEN_HEIGHT   272

// sets how many seconds the picture to be displayed
// before going to next picture
#define APP_GFX_SLIDESHOW_DELAY_SECONDS     3ul
    
// *****************************************************************************
// *****************************************************************************
// Section: Enumerations
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* APP_GFX_STATES

  Summary:
    graphics application state machine states

  Description:
    graphics application state machine states

  Remarks:
    None.
 */
typedef enum
{
    /* Application's state machine's initial state. */
	APP_GFX_STATE_INIT = 0,
    APP_GFX_STATE_CREATE_START_SCREEN,
    APP_GFX_STATE_START_SCREEN,
    APP_GFX_STATE_SHOW_FULL_SCREEN_BUTTON,
    APP_GFX_STATE_CAN_STREAM,
    APP_GFX_STATE_CREATE_SLIDESHOW_SCREEN,
    APP_GFX_STATE_LOAD_NEXT_IMAGE,
    APP_GFX_STATE_RENDERING_IMAGE,
    APP_GFX_STATE_WAIT_FOR_NEXT,

    APP_GFX_STATE_ERROR,
            
} APP_GFX_STATES;

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* APP_GFX_IMG_DIMENSIONS

  Summary:
    Structure to hold the image dimensions

  Description:
    Structure to hold the image dimensions

  Remarks:
    None.
 */
typedef struct
{
    uint16_t width;
    uint16_t heigth;

} APP_GFX_IMG_DIMENSIONS;


    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    // *****************************************************************************

    /** Descriptive Data Type Name

      @Summary
        Brief one-line summary of the data type.
    
      @Description
        Full description, explaining the purpose and usage of the data type.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Remarks
        Any additional remarks
        <p>
        Describe enumeration elements and structure and union members above each 
        element or member.
     */
typedef struct
{
    // Legato Image object
    leImage* image;

    // image file handle
    SYS_FS_HANDLE fileHandle;

} APP_GFX_IMG_OBJ;

// *****************************************************************************
/* APP_GFX_IMG_OBJ

  Summary:
    Structure to hold the graphics application data

  Description:
    Structure to hold the graphics application data

  Remarks:
    None.
 */
typedef struct
{
    // the application current state
    APP_GFX_STATES state;

    // the index of the current file displayed on the screen
    uint32_t currentAppGfxFileIdx;

    // the image file details got from the File Handler
    APP_FILE_HANDLER_DATA* appGfxFileData;
    
    // legato image object
    APP_GFX_IMG_OBJ appGfxResImgObj;

    // current image file handler
    SYS_FS_HANDLE assetFileHandle;
} APP_GFX_DATA;

/*******************************************************************************
  Function:
    void APP_GFX_Data_Reset ( void )

  Summary:
    Resets appGfxData structure to default values

  Description:
    Resets appGfxData structure to default values

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_GFX_Data_Reset();
    </code>

  Remarks:
    None.
*/// 
static void APP_GFX_Data_Reset(void);

/*******************************************************************************
  Function:
    void APP_GFX_GetStartMessageString ( void )

  Summary:
    Get function gets Start Screen message

  Description:
    Gets the text to be displayed on the Start Screen 
    based on the status of the media loading, like mounted, not mounted, 
    ready or no files to play

  Precondition:
    The Start Screen needs to be rendered first

  Parameters:
    None.

  Returns:
    The string to display

  Example:
    <code>
    char* message = APP_GFX_GetStartMessageString();
    </code>

  Remarks:
    None.
*/// 
static char* APP_GFX_GetStartMessageString();

/*******************************************************************************
  Function:
    void APP_GFX_GetStartMessageString ( void )

  Summary:
    Get the data handler for the image streaming

  Description:
    Returns the data handler for the media streaming
    Currently there is one file handler available,
    however this function can be added with other media locations

  Precondition:
    The media should be loaded first using likes of APP_GFX_Load_Next_Image

  Parameters:
    dataLocation    Legato Asset Memory Location

  Returns:
    SYS_FS_HANDLE

  Example:
    <code>
    appGfxData.assetFileHandle = APP_GFX_GetFileHandle(stream->desc->location);
    </code>

  Remarks:
    None.
*/// 
static SYS_FS_HANDLE APP_GFX_GetFileHandle(uint32_t dataLocation);

/*******************************************************************************
  Function:
    void APP_GFX_GetStartMessageString ( void )

  Summary:
    Creates a leImage object

  Description:
    Allocates memory for a new image and initializes the object structure
  
  Precondition:
    None.

  Parameters:
    width       - image width
    height      - image width
    colorMode   - desired colorMode
    location    - Legato Asset Memory Location
    imageFormat - image format. See leImageFormat enum

  Returns:
    NULL            - if memory allocation failed
    leImage object  - if all is good

  Example:
    <code>
    img = APP_GFX_CreateLegatoImageObject(width, height, LE_COLOR_MODE_RGB_888, LE_STREAM_LOCATION_ID_SD_CARD_FILE, LE_IMAGE_FORMAT_JPEG);
    </code>

  Remarks:
    None.
*/// 
static leImage* APP_GFX_CreateLegatoImageObject(uint32_t width, uint32_t height, leColorMode colorMode, uint32_t location, leImageFormat imageFormat);

/*******************************************************************************
  Function:
    leResult APP_GFX_Image_Free ( leImage* img )

  Summary:
    Destroys a leImage object

  Description:
    Frees the memory taken by an image object

  Precondition:
    None.

  Parameters:
    image           - a leImage object or NULL

  Returns:
    LE_FAILURE      - if memory de-allocation failed
    LE_SUCCESS      - if all is OK

  Example:
    <code>
    if ( APP_GFX_Image_Free(img) == LE_FAILURE ) {
        // treat the failure
        }
    </code>

  Remarks:
    None.
*/// 
static leResult APP_GFX_Image_Free(leImage* img);

/*******************************************************************************
  Function:
    void APP_GFX_ImgObjUnload ( void )

  Summary:
    Destroys an APP_GFX_IMG_OBJ object

  Description:
    Frees the memory taken by the image related objects

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_GFX_ImgObjUnload()
    </code>

  Remarks:
    None.
*/// 
static void APP_GFX_ImgObjUnload();

/*******************************************************************************
  Function:
    bool APP_GFX_Load_Next_Image ( void )

  Summary:
    Loads the next image into the Image Widget

  Description:
    When the streaming of one image ended, and the delay passed, 
    this function will do the needful and loads the image widget with a new image

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    true    - image has been loaded
    false   - image failed to load

  Example:
    <code>
    if (APP_GFX_Load_Next_Image() == true) {
        // change state
        appGfxData.state = APP_GFX_STATE_RENDERING_IMAGE;
    }
    </code>

  Remarks:
    None.
*/// 
static bool APP_GFX_Load_Next_Image(void);

/*******************************************************************************
  Function:
    void APP_GFX_Set_ImageWidgetPosition(leImageWidget* imageWidget)

  Summary:
    Positions the Image widget on the display based on its dimensions

  Description:
    This function positions the Image Widget 
    based the dimensions of the picture that will be displayed

  Precondition:
    Streaming Screen should be loaded
    imageWidget should have the width and height set

  Parameters:
    imageWidget - the widget that needs to be re-positioned

  Returns:
    None.

  Example:
    <code>
    APP_GFX_Set_ImageWidgetPosition(SlideShow_Screen_Images);
    </code>

  Remarks:
    None.
*/// 
static void APP_GFX_Set_ImageWidgetPosition(leImageWidget* imageWidget);

/*******************************************************************************
  Function:
    bool APP_GFX_CanStream()

  Summary:
    Checks if the streaming can continue or not

  Description:
    There are reasons for which the streaming cannot start/continue
    Most common reason is physical Media removal
  
  Precondition:
    None.

  Parameters:
    None.

  Returns:
    True    - the streaming can continue
    False   - the streaming cannot continue

  Example:
    <code>
    if (APP_GFX_CanStream()) {
        // change the status of the state machine into streaming state
        appGfxData.state = APP_GFX_STATE_CREATE_SLIDESHOW_SCREEN;
    }
    </code>

  Remarks:
    None.
*/// 
static bool APP_GFX_CanStream();

#ifdef __cplusplus
}
#endif

#endif /* APP_GFX_PRIVATE_H */

/* *****************************************************************************
 End of File
 */
