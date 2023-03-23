/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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
  Graphics Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the graphics application.

  Description:
    This file contains the source code for the graphics application.  It
    implements the logic of the graphics application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.
    It is also dependent on the application file handler that is providing the 
    keeping the file list on the sdcard and validates them
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdio.h>
// application header files
#include "app_gfx.h"
#include "app_gfx_private.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global and Local Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// character buffer - char
#define START_SCREEN_MESSAGE_LENGTH 64
static char cMediaInitializing[START_SCREEN_MESSAGE_LENGTH] = "Initializing... Please wait!";
static char cCardNotFound[START_SCREEN_MESSAGE_LENGTH] = "Please insert an SD Card!";
static char cCardNoMediaFound[START_SCREEN_MESSAGE_LENGTH] = "No Media found on the SD Card!";
static char cCardStatusOK[START_SCREEN_MESSAGE_LENGTH] = "Touch Screen To Start!";

// Legato Char buffer
static leChar legatoCharBuffer[START_SCREEN_MESSAGE_LENGTH] = {0};

// Legato string object
static leFixedString messageString;

// the graphics object used to keep the information for the graphics application
static APP_GFX_DATA CACHE_ALIGN appGfxData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

// Streaming Functions
// Streaming implementation of Legato Application - Media Open
leResult leApplication_MediaOpenRequest(leStream* stream)
{
    bool error = false;

    if (APP_GFX_CanStream() == false)
    {
        error = true;
    }

    // set the image file handler
    appGfxData.assetFileHandle = APP_GFX_GetFileHandle(stream->desc->location);

    // check the file handler
    if (appGfxData.assetFileHandle == SYS_FS_HANDLE_INVALID)
    {
        error = true;
    }

    // in case of error...
    if (error == true)
    {
        Nop();
    }

    leStream_DataReady(stream);

    return LE_SUCCESS;
}

// Streaming implementation of Legato Application - fill the streaming buffer
leResult leApplication_MediaReadRequest(leStream* stream, // stream reader
                                        uint32_t address, // address
                                        uint32_t readSize, // dest size
                                        uint8_t* destBuffer)
{
    bool error = false;

    if (APP_GFX_CanStream() == false)
    {
        error = true;
    }

    // this if sequence does not look nice
    if (appGfxData.assetFileHandle != SYS_FS_HANDLE_INVALID)
    {
        if (SYS_FS_FileSeek(appGfxData.assetFileHandle, (int32_t)address, SYS_FS_SEEK_SET) != -1)
        {
            if (SYS_FS_FileRead(appGfxData.assetFileHandle, (void*)destBuffer, readSize) < (size_t)0)
            {
                error = true;
            }
        }
        else
        {
            error = true;
        }
    }
    else
    {
        error = true;
    }


    if (error == true)
    {
        // fill the data with 0
        memset(destBuffer, 0x00, readSize);
    }

    // inform the stream is ready to be used
    leStream_DataReady(stream);

    // success tells the decoder to keep going
    return LE_SUCCESS;
}

// Streaming implementation of Legato Application - close Streaming
void leApplication_MediaCloseRequest(leStream* stream)
{
    return;
}

// Callback functions
// callback function for when the full screen invisible button will be released
void event_Start_Screen_FullScreenButton_OnReleased(leButtonWidget* btn)
{
    if (APP_GFX_CanStream())
    {
        // change the status of the state machine into streaming state
        appGfxData.state = APP_GFX_STATE_CREATE_SLIDESHOW_SCREEN;
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Global Functions
// *****************************************************************************
// *****************************************************************************
void APP_GFX_Initialize()
{
    // put the state machine in its init phase
    appGfxData.state = APP_GFX_STATE_INIT;

    APP_GFX_Data_Reset();

    legato_showScreen(screenID_Start_Screen);
}

void APP_GFX_Tasks()
{
    // a tick to use for the delays to get and load a new state
    static uint32_t delayTick = 0;

    leResult setResult;
    
    // check for the media mount status
    // if media is unmounted and in streaming screen, 
    // switch to start screen
    if (APP_FileHandler_IsMediaMounted() == false
        && legato_getCurrentScreen() == screenID_SlideShow_Screen) 
    {
        APP_GFX_Data_Reset();
        
        // change to the start of screen
        appGfxData.state = APP_GFX_STATE_CREATE_START_SCREEN;
    }

    switch (appGfxData.state)
    {
        case APP_GFX_STATE_INIT:
        {
            appGfxData.state = APP_GFX_STATE_CREATE_START_SCREEN;

            break;
        }

        case APP_GFX_STATE_CREATE_START_SCREEN:
        {
            APP_GFX_ImgObjUnload();

            // switch to the start screen
            if (legato_getCurrentScreen() != screenID_Start_Screen)
            {
                legato_showScreen(screenID_Start_Screen);
            }

            appGfxData.state = APP_GFX_STATE_START_SCREEN;

            break;
        }

        case APP_GFX_STATE_START_SCREEN:
        {
            // make sure the start screen is created
            if (legato_getCurrentScreen() != screenID_Start_Screen)
            {
                appGfxData.state = APP_GFX_STATE_CREATE_START_SCREEN;

                break;
            }

            // wait for the screen to be rendered
            if (!leRenderer_IsIdle())
            {
                break;
            }

            // prepare the message to be put on the label
            memset(&messageString, 0, sizeof (messageString));
            memset(&legatoCharBuffer, 0, sizeof (legatoCharBuffer));

            // hide the message
            setResult = Start_Screen_StartScreenLabel->fn->setVisible(Start_Screen_StartScreenLabel, LE_FALSE);
            if (setResult == LE_FAILURE)
            {
                SYS_DEBUG_PRINT(SYS_ERROR_ERROR, "!!! ERROR: Failed hide the Start Screen Message");
            }

            // Create and initialize a legato string object
            // this string object will be used to construct the string
            // that will be used by the label object for showing on the screen
            leFixedString_Constructor(&messageString, legatoCharBuffer, START_SCREEN_MESSAGE_LENGTH);

            // Assign a font to the string object. 
            // The font must contain all the glyphs/characters 
            // that will be used in the dynamic string. 
            setResult = messageString.fn->setFont(&messageString,
                                                  leStringTable_GetStringFont(leGetState()->stringTable,
                                                                              stringID_Start_Screen_Text,
                                                                              0));
            if (setResult == LE_FAILURE)
            {
                SYS_DEBUG_PRINT(SYS_ERROR_ERROR, "!!! ERROR: Failed set the font");
            }

            // Convert the character string to leFixedString object
            setResult = messageString.fn->setFromCStr(&messageString, APP_GFX_GetStartMessageString());
            if (setResult == LE_FAILURE)
            {
                SYS_DEBUG_PRINT(SYS_ERROR_ERROR, "!!! ERROR: Failed to convert the text");
            }

            // Set counterString string to label
            setResult = Start_Screen_StartScreenLabel->fn->setString(Start_Screen_StartScreenLabel, (leString*) & messageString);
            if (setResult == LE_FAILURE)
            {
                SYS_DEBUG_PRINT(SYS_ERROR_ERROR, "!!! ERROR: Failed to setString to StartScreenLabel");
            }

            // set the label visible
            setResult = Start_Screen_StartScreenLabel->fn->setVisible(Start_Screen_StartScreenLabel, LE_TRUE);
            if (setResult == LE_FAILURE)
            {
                SYS_DEBUG_PRINT(SYS_ERROR_ERROR, "!!! ERROR: Failed show the Start Screen Message");
            }

            // if the streaming can start, move on
            if (APP_GFX_CanStream() == true)
            {
                appGfxData.state = APP_GFX_STATE_SHOW_FULL_SCREEN_BUTTON;
            }

            break;
        }

        case APP_GFX_STATE_SHOW_FULL_SCREEN_BUTTON:
        {
            // wait for the screen to be rendered
            if (!leRenderer_IsIdle())
            {
                break;
            }

            setResult = Start_Screen_FullScreenButton->fn->setVisible(Start_Screen_FullScreenButton, LE_TRUE);
            if (setResult == LE_FAILURE)
            {
                SYS_DEBUG_PRINT(SYS_ERROR_ERROR, "!!! ERROR: Failed to show the full screen button");
            }

            appGfxData.state = APP_GFX_STATE_CAN_STREAM;

            break;
        }

        case APP_GFX_STATE_CAN_STREAM:
        {
            // wait for the screen to be rendered
            if (!leRenderer_IsIdle())
            {
                break;
            }

            if (APP_GFX_CanStream() == false)
            {
                setResult = Start_Screen_FullScreenButton->fn->setVisible(Start_Screen_FullScreenButton, LE_FALSE);
                if (setResult == LE_FAILURE)
                {
                    SYS_DEBUG_PRINT(SYS_ERROR_ERROR, "!!! ERROR: Failed to hide the full screen button");
                }

                appGfxData.state = APP_GFX_STATE_START_SCREEN;
            }

            break;
        }

        case APP_GFX_STATE_CREATE_SLIDESHOW_SCREEN:
        {
            // switch to the streaming screen
            if (legato_getCurrentScreen() != screenID_SlideShow_Screen)
            {
                legato_showScreen(screenID_SlideShow_Screen);

                break;
            }

            appGfxData.state = APP_GFX_STATE_LOAD_NEXT_IMAGE;

            break;
        }

        case APP_GFX_STATE_LOAD_NEXT_IMAGE:
        {
            // wait for the screen to be created
            if (legato_getCurrentScreen() != screenID_SlideShow_Screen)
            {

                appGfxData.state = APP_GFX_STATE_CREATE_SLIDESHOW_SCREEN;

                break;
            }

            // wait for the renderer to finish
            if (!leRenderer_IsIdle())
            {
                break;
            }

            // load the next image from the media
            if (APP_GFX_Load_Next_Image() == true)
            {
                // change state
                appGfxData.state = APP_GFX_STATE_RENDERING_IMAGE;
            }

            break;
        }

        case APP_GFX_STATE_RENDERING_IMAGE:
        {
            // wait for the renderer to finish before going to next state
            if (leRenderer_IsIdle())
            {
                appGfxData.state = APP_GFX_STATE_WAIT_FOR_NEXT;

                // reset the tick to start counting again
                delayTick = SYS_TMR_TickCountGet();
            }
            break;
        }

        case APP_GFX_STATE_WAIT_FOR_NEXT:
        {
            // if the delay passed
            if (SYS_TMR_TickCountGet() - delayTick >= APP_GFX_SLIDESHOW_DELAY_SECONDS * SYS_TMR_TickCounterFrequencyGet())
            {
                // go to the state that loads the next image
                appGfxData.state = APP_GFX_STATE_LOAD_NEXT_IMAGE;
            }

            break;
        }

        case APP_GFX_STATE_ERROR:
        {
            // do nothing - there was an error
            break;
        }

            // no default needed
            // the compiler should complain if a new value is added into the enum
    }

#if defined (APP_DEBUG_MEMORY)
    static uint32_t debugDelayTick = 0;
    leMemoryStatusReport rpt;
    if (SYS_TMR_TickCountGet() - debugDelayTick >= SYS_TMR_TickCounterFrequencyGet() * APP_DEBUG_MEMORY_DELAY_SEC)
    {
        leMemoryGetUsageReport(&rpt);

        SYS_CONSOLE_PRINT("    HEAP DEBUG: Legato minimum heap remained: %d\r\n", (rpt.variableHeapReport.size - rpt.variableHeapReport.maxUsage));

        debugDelayTick = SYS_TMR_TickCountGet();
    }
#endif

}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

// reset data values to default
static void APP_GFX_Data_Reset()
{
    // Image file index into the file list.
    appGfxData.currentAppGfxFileIdx = APP_FileHandler_GetMaxNumberOfFiles();
    
    // clear object data
    APP_GFX_ImgObjUnload();

    return;
}

// function on the status of the media, 
// returns a string to be shown on the main screen
static char* APP_GFX_GetStartMessageString()
{
    if (APP_FileHandler_IsMediaMounted() == false)
    {
        return &cCardNotFound[0];
    }

    if (APP_FileHandler_IsMediaLoaded() == false)
    {
        return &cMediaInitializing[0];
    }

    if (APP_FileHandler_GetNumberOfMediaFiles() == 0)
    {
        return &cCardNoMediaFound[0];
    }

    return &cCardStatusOK[0];
}

// gets the handle for the image
// for this particular application this is always the SD Card
// but it could be extended to other locations, if necessary
static SYS_FS_HANDLE APP_GFX_GetFileHandle(uint32_t dataLocation)
{
    SYS_FS_HANDLE handle = SYS_FS_HANDLE_INVALID;

    switch (dataLocation)
    {
            // location is on the SD Card
        case LE_STREAM_LOCATION_ID_SD_CARD_FILE:
        {
            // handler is the image objects file handler
            handle = appGfxData.appGfxResImgObj.fileHandle;

            break;
        }

            // no default needed
            // the compiler should complain if a new value is added into the enum
    }

    return handle;
}

// there are reasons for which the streaming cannot start/continue
// catch them here
static bool APP_GFX_CanStream()
{
    // there is no SD Card inside
    if (APP_FileHandler_IsMediaLoaded() != true)
    {
        return false;
    }

    // no media to stream
    if (APP_FileHandler_GetNumberOfMediaFiles() == 0)
    {
        return false;
    }

    // the state machine is in ERROR state
    if (appGfxData.state == APP_GFX_STATE_ERROR)
    {
        return false;
    }

    return true;
}

// Unloads application graphics object
// Frees memory taken by the Legato Image object
// closes the file in case it is open
static void APP_GFX_ImgObjUnload()
{
    // free the legato Image
    while (appGfxData.appGfxResImgObj.image != NULL)
    {
        if (APP_GFX_Image_Free(appGfxData.appGfxResImgObj.image) == LE_FAILURE)
        {
            SYS_DEBUG_PRINT(SYS_ERROR_ERROR, "!!! ERROR: Failed to free the graphics object image.");
        }

        appGfxData.appGfxResImgObj.image = NULL;
    }

    // if there was an image open
    if (appGfxData.appGfxResImgObj.fileHandle != (SYS_FS_HANDLE)NULL)
    {
        if (appGfxData.appGfxResImgObj.fileHandle != SYS_FS_HANDLE_INVALID)
        {
            SYS_FS_FileClose(appGfxData.appGfxResImgObj.fileHandle);

            appGfxData.appGfxResImgObj.fileHandle = SYS_FS_HANDLE_INVALID;
        }
    }
}

// loads the next image into the Image Widget
static bool APP_GFX_Load_Next_Image(void)
{
    // Free memory used by the previous image
    APP_GFX_ImgObjUnload();

    if (APP_GFX_CanStream() == false)
    {
        return false;
    }

    // ask the file handler for the next picture to show
    appGfxData.appGfxFileData = APP_FileHandler_GetPictureToShow(appGfxData.currentAppGfxFileIdx, APP_FILE_HANDLER_GET_NEXT);
    
    // set the current file index
    appGfxData.currentAppGfxFileIdx = appGfxData.appGfxFileData->mediaFileIdx;

    // information message
    SYS_CONSOLE_PRINT("APP_GFX: Loading image %s\r\n", appGfxData.appGfxFileData->mediaFullPath);
    // SYS_CONSOLE_PRINT("APP_GFX: Image Dimensions:\r\n    width %d\r\n    Height: %d\r\n", appGfxData.appGfxFileData->dimensions.width, appGfxData.appGfxFileData->dimensions.height);

    // open the stream in the right format
    leImageFormat imageFormat = LE_IMAGE_FORMAT_JPEG;
    switch (appGfxData.appGfxFileData->fileType)
    {
        case APP_FILE_HANDLER_IMAGE_TYPE_JPEG:
        {
            imageFormat = LE_IMAGE_FORMAT_JPEG;

            break;
        }

        case APP_FILE_HANDLER_IMAGE_TYPE_BMP:
        {
            imageFormat = LE_IMAGE_FORMAT_RAW;

            break;
        }

        case APP_FILE_HANDLER_IMAGE_TYPE_PNG:
        {
            imageFormat = LE_IMAGE_FORMAT_PNG;

            break;
        }

        case APP_FILE_HANDLER_IMAGE_TYPE_GIF:
        {
            // when gif is supported, uncomment this line and remove the return
            // imageFormat = LE_IMAGE_FORMAT_GIF;
            SYS_DEBUG_PRINT(SYS_ERROR_ERROR, "!!! ERROR: GIF Images are not implemented - not currently supported %s\r\n", appGfxData.appGfxFileData->mediaFullPath);

            return false;

            break;
        }

        case APP_FILE_HANDLER_IMAGE_TYPE_UNKNOWN:
        {
            SYS_DEBUG_PRINT(SYS_ERROR_ERROR, "!!! ERROR: Image type unknown. Should not be here. %s\r\n", appGfxData.appGfxFileData->mediaFullPath);

            return false;

            break;
        }

        // no default needed
        // the compiler should complain if a new value is added into the enum
    }

    // allocate memory for the new image
    appGfxData.appGfxResImgObj.image = APP_GFX_CreateLegatoImageObject(appGfxData.appGfxFileData->dimensions.width, appGfxData.appGfxFileData->dimensions.height, LE_COLOR_MODE_RGB_888, LE_STREAM_LOCATION_ID_SD_CARD_FILE, imageFormat);
    if (appGfxData.appGfxResImgObj.image == NULL)
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_ERROR, "!!! ERROR: Could not create leImage.\r\n");

        return false;
    }

    // Open the file for reading
    // TODO - maybe move the file open in leApplication_MediaOpenRequest
    appGfxData.appGfxResImgObj.fileHandle = SYS_FS_FileOpen(appGfxData.appGfxFileData->mediaFullPath, SYS_FS_FILE_OPEN_READ);
    if (appGfxData.appGfxResImgObj.fileHandle == SYS_FS_HANDLE_INVALID)
    {
        SYS_DEBUG_PRINT(SYS_ERROR_ERROR, "!!! ERROR: Cannot open image %s\r\n", appGfxData.appGfxFileData->mediaFullPath);

        return false;
    }

    // set the image to the image widget
    SlideShow_Screen_Images->fn->setImage(SlideShow_Screen_Images, appGfxData.appGfxResImgObj.image);

    // set the dimensions of the Image Widget for the new picture
    SlideShow_Screen_Images->fn->setWidth(SlideShow_Screen_Images, (uint32_t)appGfxData.appGfxFileData->dimensions.width);
    SlideShow_Screen_Images->fn->setHeight(SlideShow_Screen_Images, (uint32_t)appGfxData.appGfxFileData->dimensions.height);

    // set position according with the widget dimensions
    APP_GFX_Set_ImageWidgetPosition(SlideShow_Screen_Images);

    return true;
}

// allocate memory for a new image 
// and initialize the object properties
static leImage* APP_GFX_CreateLegatoImageObject(uint32_t width,
                                                uint32_t height,
                                                leColorMode colorMode,
                                                uint32_t location,
                                                leImageFormat format)
{
    leImage* img;

    // sanity check
    if (width == 0 || height == 0)
    {
        SYS_CONSOLE_PRINT("ERROR: Image %s has invalid dimensions. Skip! \r\n", appGfxData.appGfxFileData->mediaFullPath);

        return NULL;
    }

    // try to allocate memory
    img = LE_MALLOC(sizeof (leImage));
    if (img == NULL)
    {
        SYS_CONSOLE_PRINT("ERROR: Cannot allocate memory for the image. Skip! \r\n", appGfxData.appGfxFileData->mediaFullPath);

        return NULL;
    }

    // size
    img->header.size = width * height * leColorInfoTable[colorMode].size;
    // address in the media is 0
    img->header.address = (void*)0;
    // location if media
    img->header.location = location;
    // image format
    img->format = format;
    // width
    img->buffer.size.width = width;
    // height
    img->buffer.size.height = height;
    // buffer length
    img->buffer.buffer_length = img->header.size;
    // buffer color mode
    img->buffer.mode = colorMode;
    // pixels fetched
    img->buffer.pixels = img->header.address;
    // number of pixels
    img->buffer.pixel_count = width * height;
    // clear flags
    img->flags = LE_IMAGE_INTERNAL_ALLOC;
    // clear masks
    img->mask.color = 0;
    // no alpha blending
    img->alphaMap = NULL;
    // no pallete
    img->palette = NULL;

    return img;
}

// free memory taken by an image
static leResult APP_GFX_Image_Free(leImage* img)
{
    if (img == NULL || (img->flags & LE_IMAGE_INTERNAL_ALLOC) == 0)
    {
        return LE_FAILURE;
    }

    LE_FREE(img);

    return LE_SUCCESS;
}

// positions the image widget on the display based on its dimensions
static void APP_GFX_Set_ImageWidgetPosition(leImageWidget* imageWidget)
{
    uint16_t posX = 0;
    uint16_t poxY = 0;
    uint32_t width = imageWidget->fn->getWidth(imageWidget);
    uint32_t heigth = imageWidget->fn->getHeight(imageWidget);

    // if the picture width is smaller than the screen width, center on horizontal
    if (width < APP_GFX_SCREEN_WIDTH)
    {
        // search for a centered position
        posX = APP_GFX_SCREEN_WIDTH / 2 - width / 2;
    }
    // if the picture height is smaller than the screen height, center on vertical
    if (heigth < APP_GFX_SCREEN_HEIGHT)
    {
        // search for a centered position
        poxY = APP_GFX_SCREEN_HEIGHT / 2 - heigth / 2;
    }

    // set X position
    imageWidget->fn->setX(imageWidget, (uint32_t)posX);
    // set Y position
    imageWidget->fn->setY(imageWidget, (uint32_t)poxY);
}

/* EOF */
