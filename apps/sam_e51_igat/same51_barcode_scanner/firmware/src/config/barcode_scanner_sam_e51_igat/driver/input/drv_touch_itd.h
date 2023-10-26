// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

/*******************************************************************************
 Input driver for the Integrated Touch Controller Library

  File Name:
    drv_touch_itd.h

  Summary:
    Header file for the integrated touch library input driver

  Description:
    This header file describes the macros, data structure and prototypes of the 
    input driver for the integrated touch library (QTouch).
 ******************************************************************************/

// DOM-IGNORE-BEGIN

#ifndef DRV_TOUCH_ITD_H
#define DRV_TOUCH_ITD_H

#ifdef __cplusplus
    extern "C" {
#endif
//DOM-IGNORE-END

#define TOUCH_SCREEN_WIDTH 480
#define TOUCH_SCREEN_HEIGHT 320

#define TOUCH_SCREEN_WIDTH_EDGE_ADJUST 0
#define TOUCH_SCREEN_HEIGHT_EDGE_ADJUST 0

#define TOUCH_SCREEN_ACTIVE_WIDTH (TOUCH_SCREEN_WIDTH - TOUCH_SCREEN_WIDTH_EDGE_ADJUST)
#define TOUCH_SCREEN_ACTIVE_HEIGHT (TOUCH_SCREEN_HEIGHT - TOUCH_SCREEN_HEIGHT_EDGE_ADJUST)

#define TOUCH_POINTS_COUNT 1

#define ITD_SURFACE_CS_RESOLUTION_BITS 8

#define FLIP_Y  1



typedef enum
{
    ITD_TOUCH_ID,
} ITD_TOUCH_IDS;

typedef enum
{
  DRV_TOUCH_ITD_INIT,
  DRV_TOUCH_ITD_CHECK, //checking status
  DRV_TOUCH_ITD_PROCESS, //processing positions
  
} DRV_TOUCH_ITD_STATE;

typedef enum
{
    DRV_TOUCH_ITD_TOUCH_RELEASED,
    DRV_TOUCH_ITD_TOUCH_PRESSED,            
} DRV_TOUCH_ITD_TOUCH_STATE;


void drv_touch_itd_init (void);
void drv_touch_itd_task (void);

#ifdef __cplusplus
    }
#endif

#endif //DRV_TOUCH_ITD_H