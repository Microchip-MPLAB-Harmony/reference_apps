/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_sdcard_reader_task.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

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

#include "app_sdcard_reader_task.h"
#include "app_display_task.h"
#include "app.h"

APP_SDCARD_READER_DATA AppSdCardReaderData;

void APP_USBDeviceEventHandler( USB_DEVICE_EVENT event, void * pEventData, uintptr_t context )
{
    APP_SDCARD_READER_DATA *AppSdCardReaderData = (APP_SDCARD_READER_DATA*)context;

    switch( event )
    {
        case USB_DEVICE_EVENT_RESET:
            
        case USB_DEVICE_EVENT_DECONFIGURED:

            /* Device was reset or de-configured. Update LED status */
            
            APP_OFF_RGB_LED();
            
            //RGB_LED_Y_On();
            

        case USB_DEVICE_EVENT_CONFIGURED:
            
            APP_DISPLAY_USB_Configured_State_Set_True();
            
            APP_SDCARD_AUDIO_StopTrack_For_MSD();
            
            app_display_state.msd_attached = true;
            
            APP_OFF_RGB_LED();
            
            RGB_LED_G_On();
      
            break;

        case USB_DEVICE_EVENT_SUSPENDED:
            break;

        case USB_DEVICE_EVENT_POWER_DETECTED:

            /* VBUS is detected. Attach the device. */
            USB_DEVICE_Attach(AppSdCardReaderData->usbDeviceHandle);
 
            APP_OFF_RGB_LED();
            
            //RGB_LED_Y_On();
            
            break;

        case USB_DEVICE_EVENT_POWER_REMOVED:

            /* VBUS is not detected. Detach the device */
            USB_DEVICE_Detach(AppSdCardReaderData->usbDeviceHandle);
            
            APP_DISPLAY_USB_Configured_State_Set_False();
            
            APP_SDCARD_AUDIO_StartTrack_For_MSD();
            
            app_display_state.msd_attached = false;
            
            APP_OFF_RGB_LED();
            
            RGB_LED_R_On();
            
            break;

        case USB_DEVICE_EVENT_RESUMED:
            
        case USB_DEVICE_EVENT_ERROR:
            
        case USB_DEVICE_EVENT_SOF:
            
        default:
            
            break;
    }
}


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void APP_SDCARD_READER_Initialize(void)
{
    AppSdCardReaderData.state = APP_SDCARD_READER_INIT;
    
    AppSdCardReaderData.usbDeviceHandle = USB_DEVICE_HANDLE_INVALID;
}


void APP_SDCARD_READER_Tasks(void)
{
    switch ( AppSdCardReaderData.state )
    {
        
        case APP_SDCARD_READER_INIT:
        {
            AppSdCardReaderData.usbDeviceHandle = USB_DEVICE_Open(USB_DEVICE_INDEX_0, DRV_IO_INTENT_READWRITE);

            if(AppSdCardReaderData.usbDeviceHandle != USB_DEVICE_HANDLE_INVALID)
            {
                USB_DEVICE_EventHandlerSet(AppSdCardReaderData.usbDeviceHandle, APP_USBDeviceEventHandler, (uintptr_t)&AppSdCardReaderData);

                AppSdCardReaderData.state = APP_SDCARD_READER_RUNNING;
            }

            break;
        }

        case APP_SDCARD_READER_RUNNING:
           
            if(USB_DEVICE_StateGet(AppSdCardReaderData.usbDeviceHandle) == USB_DEVICE_STATE_CONFIGURED)
            {
                APP_DISPLAY_USB_Configured_State_Set_True();
                
                APP_SDCARD_AUDIO_StopTrack_For_MSD();
                
                app_display_state.msd_attached = true;
                
                APP_OFF_RGB_LED();
                
                RGB_LED_G_On();
            
            }
            
            break;
            
        default:
            break;
        
    }
}



