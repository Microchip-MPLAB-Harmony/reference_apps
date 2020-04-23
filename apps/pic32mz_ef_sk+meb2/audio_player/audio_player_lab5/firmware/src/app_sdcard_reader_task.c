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
Copyright (c) 2016-2017 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

#include "app_sdcard_reader_task.h"
#include "app.h"


static APP_SDCARD_READER_DATA  AppSDCardrReaderData;


/******************************************************************************
  Function:
    void APP_USBDeviceEventHandler
    (
        USB_DEVICE_EVENTS event
        void * pEventData,
        uintptr_t context
    );

  Remarks:
    Handles the Device Layers Events.
*/

void APP_USBDeviceEventHandler( USB_DEVICE_EVENT event, void * pEventData, uintptr_t context )
{
    /* This is an example of how the context parameter
       in the event handler can be used.*/

    APP_SDCARD_READER_DATA * appData = (APP_SDCARD_READER_DATA*)context;

    switch( event )
    {
        case USB_DEVICE_EVENT_RESET:
        case USB_DEVICE_EVENT_DECONFIGURED:

            /* Device was reset or deconfigured. Update LED status */
            LED1_On();
            LED2_On();
            LED3_On();
            break;

        case USB_DEVICE_EVENT_CONFIGURED:

            /* Device is configured. Update LED status */
            LED1_Off();
            LED2_Off();
            LED3_On();
            break;

        case USB_DEVICE_EVENT_SUSPENDED:

            /* Update LED status */
            LED1_Off();
            LED2_On();
            LED3_On();
            break;

        case USB_DEVICE_EVENT_POWER_DETECTED:

            /* VBUS is detected. Attach the device. */
            USB_DEVICE_Attach(appData->usbDevHandle);
            break;

        case USB_DEVICE_EVENT_POWER_REMOVED:

            /* VBUS is not detected. Detach the device */
            USB_DEVICE_Detach(appData->usbDevHandle);
            break;

        /* These events are not used in this demo */
        case USB_DEVICE_EVENT_RESUMED:
        case USB_DEVICE_EVENT_ERROR:
        case USB_DEVICE_EVENT_SOF:
        default:
            break;
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_SDCARD_READER_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    AppSDCardrReaderData.state = APP_SDCARD_READER_STATE_INIT;
    
    /* Set device layer handle as invalid */
    AppSDCardrReaderData.usbDevHandle = USB_DEVICE_HANDLE_INVALID;
    
    AppSDCardrReaderData.isUsbDetached = false;
}

void APP_SDCARD_READER_ReInitialize ( void )
{
    AppSDCardrReaderData.state = APP_SDCARD_READER_STATE_RUNNING;
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_SDCARD_READER_Tasks ( void )
{
    if (APP_MODE_SD_CARD_READER == APP_GetMode())
    {
        /* Check the application's current state. */
        switch ( AppSDCardrReaderData.state )
        {
            /* Application's initial state. */
            case APP_SDCARD_READER_STATE_INIT:
            {
                 AppSDCardrReaderData.usbDevHandle = USB_DEVICE_Open(USB_DEVICE_INDEX_0, DRV_IO_INTENT_READWRITE);

                if(AppSDCardrReaderData.usbDevHandle != USB_DEVICE_HANDLE_INVALID)
                {
                    /* Set the Event Handler. We will start receving events after
                     * the handler is set */
                    USB_DEVICE_EventHandlerSet(AppSDCardrReaderData.usbDevHandle, APP_USBDeviceEventHandler, (uintptr_t)&AppSDCardrReaderData);

                    /* Move the application to the next state */
                    AppSDCardrReaderData.state = APP_SDCARD_READER_STATE_RUNNING;
                }

                break;
            }

            case APP_SDCARD_READER_STATE_RUNNING:

                /* The MSD Device is maintained completely by the MSD function
                 * driver and does not require application intervention. So there
                 * is nothing related to MSD Device to do here. */
                break;

            /* The default state should never be executed. */
            default:
                break;

        }
    }
}
 
void APP_SDCARD_READER_AttachDevice(void)
{
    if(AppSDCardrReaderData.isUsbDetached)
    {
        APP_SDCARD_READER_ReInitialize();         
        USB_DEVICE_Attach(AppSDCardrReaderData.usbDevHandle);
        AppSDCardrReaderData.isUsbDetached = false;
    }
}

void APP_SDCARD_READER_DetachDevice(void)
{
    USB_DEVICE_Detach(AppSDCardrReaderData.usbDevHandle); 
    AppSDCardrReaderData.isUsbDetached = true;    
}

