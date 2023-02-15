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
  Graphics Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_gfx.h

  Summary:
    This header file provides prototypes and definitions for the graphics application.

  Description:
    This header file provides function prototypes and data type definitions for
    the graphics application.
*******************************************************************************/

#ifndef APP_GFX_PRIVATE_H
#define	APP_GFX_PRIVATE_H

#include "app_file_handler.h"
// harmony library files
#include "definitions.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define APP_GFX_SCREEN_WIDTH 480
#define APP_GFX_SCREEN_HEIGHT 272

// sets how many seconds the picture to be displayed
// before going to next picture
#define APP_GFX_SLIDESHOW_DELAY_SECONDS 3ul
    
#define APP_GFX_ERROR_LED_ON()      RGB_LED_R_On()

// graphics application state machine states
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
            
} APP_GFX_STATE;

// image dimensions
typedef struct
{
    uint16_t width;
    uint16_t heigth;

} APP_GFX_IMG_DIMENSIONS;

// the graphics object that will be used with legato
typedef struct
{
    // Legato Image object
    leImage* image;

    // image file handle
    SYS_FS_HANDLE fileHandle;

} APP_GFX_IMG_OBJ;


// graphics application data
typedef struct
{
    /* The application's current state */
    APP_GFX_STATE state;

    // 
    uint32_t currentAppGfxFileIdx;

    // the image file details got from the File Handler
    APP_FILE_DATA* appGfxFileData;
    
    // legato image object
    APP_GFX_IMG_OBJ appGfxResImgObj;

    // current image file handler
    SYS_FS_HANDLE assetFileHandle;
} APP_GFX_DATA;

// gets the text to be displayed on the Start Screen
char* APP_GFX_GetStartMessageString();

// gets the handle for the image
SYS_FS_HANDLE APP_GFX_GetFileHandle(uint32_t dataLocation);

// allocate memory for a new image and initialize the object
leImage* APP_GFX_CreateLegatoImageObject(uint32_t width, uint32_t height, leColorMode colorMode, uint32_t location, leImageFormat format);

// free memory taken by an image
leResult APP_GFX_Image_Free(leImage* img);

// free memory taken by the image related objects
void APP_GFX_ImgObjUnload();

// loads the next image into the Image Widget
bool APP_GFX_Load_Next_Image(void);

// positions the image object on the display based on its dimensions
void APP_GFX_Set_ImageWidgetPosition(leImageWidget* image);

// there are reasons for which the streaming cannot start/continue
bool APP_GFX_CanStream();

// sanity check of the media
void _APP_GFX_CheckMedia();

#ifdef	__cplusplus
}
#endif

#endif	/* APP_GFX_PRIVATE_H */

/* EOF */
