/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_usb_thread.c

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


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "app_usb_thread.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_USB_THREAD_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_USB_THREAD_DATA app_usb_threadData USB_ALIGN;

/* This is the string that will written to the file */
USB_ALIGN uint8_t writeData[30] = "Hello World \r\n";

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

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
    void APP_USB_THREAD_Initialize ( void )

  Remarks:
    See prototype in app_usb_thread.h.
 */

void APP_USB_THREAD_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_usb_threadData.state = APP_STATE_BUS_ENABLE;
    app_usb_threadData.deviceIsConnected = false;

    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}

USB_HOST_EVENT_RESPONSE APP_USBHostEventHandler (USB_HOST_EVENT event, void * eventData, uintptr_t context)
{
    switch (event)
    {
        case USB_HOST_EVENT_DEVICE_UNSUPPORTED:
            break;
        default:
            break;
                    
    }
    
    return(USB_HOST_EVENT_RESPONSE_NONE);
}

void APP_SYSFSEventHandler(SYS_FS_EVENT event, void * eventData, uintptr_t context)
{
    switch(event)
    {
        case SYS_FS_EVENT_MOUNT:
            app_usb_threadData.deviceIsConnected = true;
            
            break;
            
        case SYS_FS_EVENT_UNMOUNT:
            app_usb_threadData.deviceIsConnected = false;
            LED2_Off();
            break;
            
        default:
            break;
    }
}
/******************************************************************************
  Function:
    void APP_USB_THREAD_Tasks ( void )

  Remarks:
    See prototype in app_usb_thread.h.
 */

void APP_USB_THREAD_Tasks ( void )
{
    uint8_t strlen;                        

    /* Check the application's current state. */
    switch ( app_usb_threadData.state )
    {
        /* Application's initial state. */
        case APP_STATE_BUS_ENABLE:
                      
           /* Set the event handler and enable the bus */
            SYS_FS_EventHandlerSet((void *)APP_SYSFSEventHandler, (uintptr_t)NULL);
            USB_HOST_EventHandlerSet(APP_USBHostEventHandler, 0);
            USB_HOST_BusEnable(0);
            app_usb_threadData.state = APP_STATE_WAIT_FOR_BUS_ENABLE_COMPLETE;
            break;
            
        case APP_STATE_WAIT_FOR_BUS_ENABLE_COMPLETE:
            if(USB_HOST_BusIsEnabled(0))
            {
                app_usb_threadData.state = APP_STATE_WAIT_FOR_DEVICE_ATTACH;
            }
            break;
       
        case APP_STATE_WAIT_FOR_DEVICE_ATTACH:

            /* Wait for device attach. The state machine will move
             * to the next state when the attach event
             * is received.  */
            if(app_usb_threadData.deviceIsConnected)
            {
                app_usb_threadData.state = APP_STATE_IDLE;
            }

            break;

        case APP_STATE_DEVICE_CONNECTED:

            /* Device was connected. We can try mounting the disk */
            app_usb_threadData.state = APP_STATE_OPEN_FILE;
            break;

        case APP_STATE_OPEN_FILE:

            /* Try opening the file for append */
            app_usb_threadData.fileHandle = SYS_FS_FileOpen("/mnt/myDrive1/Temperature_Sensor_Data.txt", (SYS_FS_FILE_OPEN_APPEND_PLUS));
            if(app_usb_threadData.fileHandle == SYS_FS_HANDLE_INVALID)
            {
                /* Could not open the file. Error out*/
                app_usb_threadData.state = APP_STATE_ERROR;

            }
            else
            {
                /* File opened successfully. Write to file */
                app_usb_threadData.state = APP_STATE_WRITE_TO_FILE;

            }
            break;

        case APP_STATE_WRITE_TO_FILE:

            /* Try writing to the file */
            strlen = sprintf((char*)writeData, "Temperature = %d F\r\n", (uint8_t)app_usb_threadData.eventInfo.eventData);  
            if (SYS_FS_FileWrite( app_usb_threadData.fileHandle, (const void *) writeData, strlen) == -1)
            {
                /* Write was not successful. Close the file
                 * and error out.*/
                SYS_FS_FileClose(app_usb_threadData.fileHandle);
                app_usb_threadData.state = APP_STATE_ERROR;

            }
            else
            {
                /* We are done writing. Close the file */
                app_usb_threadData.state = APP_STATE_CLOSE_FILE;
            }

            break;

        case APP_STATE_CLOSE_FILE:

            /* Close the file */
            SYS_FS_FileClose(app_usb_threadData.fileHandle);
            
            /* Indicate User that File operation has been completed */
            LED2_On(); 
            /* The test was successful. Lets idle. */
            app_usb_threadData.state = APP_STATE_IDLE;
            break;

        case APP_STATE_IDLE:

            /* Wait for the temperature write request */    
            xQueueReceive( eventQueue, &app_usb_threadData.eventInfo, portMAX_DELAY );
            if (app_usb_threadData.eventInfo.eventType == EVENT_TYPE_TEMP_WRITE_REQ)
            {
                app_usb_threadData.state = APP_STATE_OPEN_FILE;
            }
            /* The application comes here when the demo has completed
             * successfully. Provide LED indication. Wait for device detach
             * and if detached, wait for attach. */

            if(app_usb_threadData.deviceIsConnected == false)
            {
                app_usb_threadData.state = APP_STATE_WAIT_FOR_DEVICE_ATTACH;
            }
            
            break;

        case APP_STATE_ERROR:

            /* The application comes here when the demo
             * has failed. Provide LED indication .*/

            if(SYS_FS_Unmount("/mnt/myDrive1") != 0)
            {
                /* The disk could not be un mounted. Try
                 * un mounting again untill success. */

                app_usb_threadData.state = APP_STATE_ERROR;
            }
            else
            {
                /* UnMount was successful. Wait for device attach */
                app_usb_threadData.state =  APP_STATE_WAIT_FOR_DEVICE_ATTACH;
                app_usb_threadData.deviceIsConnected = false; 

            }
            break;

        default:
            break;

    }
}


/*******************************************************************************
 End of File
 */
