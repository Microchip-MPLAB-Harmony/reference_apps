/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

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

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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
//DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "bsp/bsp.h"
#include "user.h"
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

#define SDCARD_MOUNT_NAME    "/mnt/mydrive"
#define SDCARD_DEV_NAME      "/dev/mmcblka1"
//#define SDCARD_FILE_NAME     "FILE_TOO_LONG_NAME_EXAMPLE_123.JPG"

#define SDCARD_FILE_NAME     "LS_LOG.TXT"
#define SDCARD_DIR_NAME      "Dir1"

#define APP_DATA_LEN         512

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;
APP_DATA_USB appDataUSB;

uint16_t adc_count;
uint32_t input_voltage;
uint32_t photo_current;
uint32_t SwitchPressCount;

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
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_START; 
    
    /* Wait for the switch status to return to the default "not pressed" state */
   // while(SWITCH_GET() == SWITCH_STATUS_PRESSED);
    
    
    appDataUSB.USBstate = APP_STATE_INIT;
    
    /* Set device layer handle as invalid */
    appDataUSB.usbDeviceHandle = USB_DEVICE_HANDLE_INVALID;
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks_SD_FS ( void )
{
    /* Check the application's current state. */
    switch ( appData.state )
    {
        case APP_START:
          
                appData.state = APP_MOUNT_DISK;
            
            break;
        case APP_MOUNT_DISK:
       
            if(SYS_FS_Mount(SDCARD_DEV_NAME, SDCARD_MOUNT_NAME, FAT, 0, NULL) != 0)
            {
                /* The disk could not be mounted. Try
                 * mounting again until success. */
                appData.state = APP_MOUNT_DISK;
            }
            else
            {
                /* Mount was successful. Unmount the disk, for testing. */
                appData.state = APP_UNMOUNT_DISK;
            }
            break;

        case APP_UNMOUNT_DISK:
          
            if(SYS_FS_Unmount(SDCARD_MOUNT_NAME) != 0)
            {
                /* The disk could not be un mounted. Try
                 * un mounting again untill success. */

                appData.state = APP_UNMOUNT_DISK;
            }
            else
            {
                /* UnMount was successful. Mount the disk again */
                appData.state = APP_MOUNT_DISK_AGAIN;
            }
            break;

        case APP_MOUNT_DISK_AGAIN:
           
            if(SYS_FS_Mount(SDCARD_DEV_NAME, SDCARD_MOUNT_NAME, FAT, 0, NULL) != 0)
            {
                /* The disk could not be mounted. Try
                 * mounting again until success. */
                appData.state = APP_MOUNT_DISK_AGAIN;
            }
            else
            {
                /* Mount was successful. Set current drive so that we do not have to use absolute path. */
                appData.state = APP_SET_CURRENT_DRIVE;
            }
            break;

        case APP_SET_CURRENT_DRIVE: 
         
            if(SYS_FS_CurrentDriveSet(SDCARD_MOUNT_NAME) == SYS_FS_RES_FAILURE)
            {
                //directly move to APP_CREATE_DIRECTORY case
                appData.state = APP_CREATE_DIRECTORY;
            }
            else
            {
                //directly move to APP_CREATE_DIRECTORY case
                appData.state = APP_CREATE_DIRECTORY;
            }
            break;

        case APP_CREATE_DIRECTORY:
         
            if(SYS_FS_DirectoryMake(SDCARD_DIR_NAME) == SYS_FS_RES_FAILURE)
            {
                
                //if directory already exists Then write to file//
                appData.state = APP_OPEN_THE_FILE;
            }
            else
            {
               //if directory doesn't exists its created and Then write to file//
                appData.state = APP_OPEN_THE_FILE;
            }
            break;

        case APP_OPEN_THE_FILE: //not used state move to next case//

            appData.state = APP_WRITE_TO_FILE;
            break;
            
        case APP_WRITE_TO_FILE: //case used to write data into the file//
            
         
                
                appData.fileHandle=SYS_FS_FileOpen(SDCARD_DIR_NAME"/"SDCARD_FILE_NAME, (SYS_FS_FILE_OPEN_APPEND_PLUS));
                
           
                SYS_FS_FileSeek(appData.fileHandle,0,SYS_FS_SEEK_CUR);
            
               
                SYS_FS_FilePrintf(appData.fileHandle,"ADC Count = 0x%x, Light Intensity = %d.%03d Lux \r", adc_count, (int)(photo_current/1000), (int)(photo_current%1000));
 
                appData.state = APP_CLOSE_FILE;
             
            break;

        case APP_CLOSE_FILE:
           
            SYS_FS_FileClose(appData.fileHandle);
           
            appData.state = APP_IDLE;
            break;

        case APP_IDLE:
            
           //Write to the file again only when the switch is pressed//
            if (SwitchPressCount >=DEBOUNCECOUNT)
            {
            appData.state = APP_WRITE_TO_FILE;
            SwitchPressCount=0;
           
            }
         
            break;

        case APP_ERROR:
          
            /* The application comes here when the demo has failed. */
            break;

        default:
            break;
    }
}


void APP_USBDeviceEventHandler( USB_DEVICE_EVENT event, void * pEventData, uintptr_t context )
{
    /* This is an example of how the context parameter
       in the event handler can be used.*/

    APP_DATA_USB * appDataObject = (APP_DATA_USB*)context;

    switch( event )
    {
        case USB_DEVICE_EVENT_RESET:
        case USB_DEVICE_EVENT_DECONFIGURED:

            /* Device was reset or de-configured. Update LED status */
            LED_Off();
            break;

        case USB_DEVICE_EVENT_CONFIGURED:

            /* Device is configured. Update LED status */
            LED_On();
            break;

        case USB_DEVICE_EVENT_SUSPENDED:
		
			LED_Off();
            break;

        case USB_DEVICE_EVENT_POWER_DETECTED:

            /* VBUS is detected. Attach the device. */
            USB_DEVICE_Attach(appDataObject->usbDeviceHandle);
            break;

        case USB_DEVICE_EVENT_POWER_REMOVED:

            /* VBUS is not detected. Detach the device */
            USB_DEVICE_Detach(appDataObject->usbDeviceHandle);
            LED_Off();
            break;

        /* These events are not used in this demo */
        case USB_DEVICE_EVENT_RESUMED:
        case USB_DEVICE_EVENT_ERROR:
        case USB_DEVICE_EVENT_SOF:
        default:
            break;
    }
}


void APP_Tasks_USB ( void )
{
    /* Check the application's current state. */
    switch ( appDataUSB.USBstate )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
             appDataUSB.usbDeviceHandle = USB_DEVICE_Open(USB_DEVICE_INDEX_0, DRV_IO_INTENT_SHARED);

            if(appDataUSB.usbDeviceHandle != USB_DEVICE_HANDLE_INVALID)
            {
                /* Set the Event Handler. We will start receiving events after
                 * the handler is set */
                USB_DEVICE_EventHandlerSet(appDataUSB.usbDeviceHandle, APP_USBDeviceEventHandler, (uintptr_t)&appDataUSB);

                /* Move the application to the next state */
                appDataUSB.USBstate = APP_STATE_RUNNING;
            }

            break;
        }

        case APP_STATE_RUNNING:

            /* The MSD Device is maintained completely by the MSD function
             * driver and does not require application intervention. So there
             * is nothing related to MSD Device to do here. */
            break;

        /* The default state should never be executed. */
        default:
            break;
        
    }
}

void APP_Tasks_ADC(void)
{
    /* Start ADC conversion */
        ADC_ConversionStart();

        /* Wait till ADC conversion result is available */
       while(!ADC_ConversionStatusGet())
        {

        };

        /* Read the ADC result and converting to Lux */
        adc_count = ADC_ConversionResultGet();
        input_voltage = adc_count * ADC_VREF / 4095U;
        photo_current=(3300 - input_voltage)*20;
}

void CheckKeyPress(void)
{
    
    if (SWITCH_GET() == SWITCH_STATUS_PRESSED)
    SwitchPressCount++;    
}
/*******************************************************************************
 End of File
 */
