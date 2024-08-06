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
// DOM-IGNORE-BEGIN
/*
    (c) 2021 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/
// DOM-IGNORE-END
// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stdio.h>
#include "app.h"
#include "click_routines/oled_c/oled_c_example.h"
#include "click_routines/oled_c/oled_c.h"
#include "rnbd/rnbd_interface.h"
#include "time.h"
#include <stdbool.h>
#include "definitions.h"                
#include "string.h"
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/** MACRO used to configure the application used buffer sizes.
 *  This is used by the application for communication buffers.
 */
#define MAX_BUFFER_SIZE                 (80)

/**< Status Buffer instance passed to RNBD drive used for Asynchronous Message Handling (see *asyncBuffer in rnbd.c) */
static char statusBuffer[MAX_BUFFER_SIZE];  

#define SDCARD_MOUNT_NAME              "/mnt/"
#define SDCARD_DEV_NAME                "/dev/mmcblka1"
#define SDCARD_FILE_NAME               "DATA_LOG.TXT"
#define SDCARD_DIR_NAME                "Dir1"

#define SWITCH_STATE_PRESSED           0

#define APP_DATA_LEN         512

#define ADC_VREF                       (3.3f)
#define FLAME_THRESHOLD_VOLTAGE        (2.75f)

uint16_t adc_count;

volatile float input_voltage;

volatile bool flame_detect_flag = false,sdcard_write_flag=0;

struct tm sys_time;

APP_SD_CARD_DATA appDataSDCard;
APP_RTC_DATA appDataRTC;
uint8_t counter;
uint16_t adc_val;

uint32_t error_status;

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


/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/


void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;
}

/*******************************************************************************
  Function:
    APP_Tasks_RNBD ( void )

  Remarks:
    *Sends the flame sensor values via UART for RNBD module.   
 */



void APP_Tasks_RNBD (void)
{

bool IsInitialize = false;
    
    IsInitialize = RNBD_SetAsyncMessageHandler(statusBuffer, (uint8_t)sizeof(statusBuffer));
    
    if (IsInitialize == true)
    {
        if (true == APP_RNBD_uart())
        {
            // Connected
        }
        else
        {
            // Not Connected
        }   
    }
    
    
}

static bool APP_RNBD_uart(void)
{
    bool isStreamOpen,isOTABegin;
   isStreamOpen = RNBD_IsConnected();
   isOTABegin = RNBD_IsOTABegin();
   char dataString[20] ;
   uint8_t index = 0;
   uint8_t dataLen = 0,send_data=0;
  uint8_t adc_mapping=0; 

   
   adc_mapping = ((float)adc_count / 0xFFF) * 100;
    
   send_data = (int)adc_mapping;
   
   sprintf(dataString, "%d", send_data);
   
   if (true == isStreamOpen && false == isOTABegin)
   {   
        RNBD.DelayMs(200);
        dataLen = strlen(dataString);
        while (index < dataLen) {
            if (RNBD.TransmitDone()) {
                RNBD.Write(dataString[index]);
                index++;
            }

        }

       while (RNBD_DataReady())
       {
           UART_CDC_write(RNBD_Read());
       }
       
   }
   else
       
    {
        
        while (RNBD_DataReady())
       {
           UART_CDC_write(RNBD_Read());
       }
        
       
        while (UART_CDC_DataReady()!=0U)
        {
        }
       
 
    }

    return isStreamOpen;
}

/******************************************************************************
  Function:
    void APP_UPDATE_callback(uintptr_t context)

  Remarks:
    *Call back function for updating the values in sdcard and OLED
 */



void APP_UPDATE_callback(uintptr_t context)
{
    sdcard_write_flag=1; 
    
    oled_c_dispaly_refresh();    
    
    oled_c_example();
    
}

/******************************************************************************
  Function:
    void APP_Tasks_Set_Time( void )

  Remarks:
    *Edit the below parameters to set a proper time.
    *Pressing SW0 on PIC32CM LE00 Curiosity Pro board will reset the RTC 
    *Time and Date!
 */
void APP_Tasks_Set_Time( void )
{
    /*Check RTC Application's Current State*/
    switch(appDataRTC.state)
    {
        /* RTC Application's initial state. */
        case APP_RTC_STATE_INIT:
        {
            bool appRTCInitialized = true;
            
            if (appRTCInitialized)
            {
                appDataRTC.state = APP_RTC_RESET_TIME_DATE;
            }
            break;
        }
        
        /* RTC App Reset Time and Data */
        case APP_RTC_RESET_TIME_DATE:
        {
            /* Set Time and Date: DD-MM-YYYY 20-12-2023 Wednesday */
            
            sys_time.tm_hour    = 12;   /* hour [0,23] */
            sys_time.tm_min     = 00;   /* minutes [0,59] */
            sys_time.tm_sec     = 00;   /* seconds [0,61] */
            sys_time.tm_mday    = 16;   /* day of month [1,31] */
            sys_time.tm_mon     = 02;   /* month of year [0,11] */
            sys_time.tm_year    = 124;  /* years since 1900 */
            sys_time.tm_wday    = 5;    /* day of week [0,6] (Sunday = 0) */
            
            appDataRTC.state = APP_RTC_START_TIME_DATE;                    
            break;
        }
        
        /* RTC App Start */
        case APP_RTC_START_TIME_DATE:
        {
            RTC_RTCCTimeSet(&sys_time);
            
            appDataRTC.state = APP_RTC_IDLE;          
            break;
        }
        
        /* The RTC app idle state */
        case APP_RTC_IDLE:
        {
            if(SW0_Get()==SWITCH_STATE_PRESSED)
            {
                appDataRTC.state = APP_RTC_RESET_TIME_DATE;
            }           
            else
            {
                appDataRTC.state = APP_RTC_IDLE;
            }            
            break;
        }
        
        /* An RTC app error has occurred */
        case APP_RTC_ERROR:
        {
            break;
        }
        
        default:
        {
            /* TODO: Handle error in RTC application's state machine. */            
            appDataRTC.state = APP_RTC_STATE_INIT;            
            break;
        }
    }          
}

/******************************************************************************
  Function:
    APP_Tasks_SD_Card ( void )

  Remarks:
    *Periodically logs the Timestamp and Date on the SD Card.
    *Periodically checks flame detection status and logs the Warning message 
    *accordingly.
 */
void APP_Tasks_SD_Card ( void )
{
    /* Check the SD Card application's current state. */
    switch ( appDataSDCard.state )
    {
        /* SD Card Application's initial state. */
        case APP_SD_FS_STATE_INIT:
        {
            bool appSDCardInitialized = true;

            if (appSDCardInitialized)
            {
                appDataSDCard.state = APP_SD_FS_MOUNT_DISK;
            }
            break;
        }
        
        /* SD Card Mounting State */
        case APP_SD_FS_MOUNT_DISK:
        {
            if(SYS_FS_Mount(SDCARD_DEV_NAME, SDCARD_MOUNT_NAME, FAT, 0, NULL) != 0)
            {
                /* Testing Mount: May be not mounted, Try again Mounting! */
                appDataSDCard.state = APP_SD_FS_MOUNT_DISK;          
            }            
            else
            {
                /* Executed if the mount was successful.
                 * As a best practice, unmount the disk for testing purposes
                 */
                appDataSDCard.state = APP_SD_FS_UNMOUNT_DISK;
            }
            break;
        }
        
        /* SD Card Un-mounting State */
        case APP_SD_FS_UNMOUNT_DISK:
        {
            if(SYS_FS_Unmount(SDCARD_MOUNT_NAME) != 0)
            {
                /* Testing Unmount: May be not unmounted, Try again un-mounting! */
                appDataSDCard.state = APP_SD_FS_UNMOUNT_DISK;
            }
            
            else
            {
                /* Executed if the un-mount was successful.
                 * Mount the disk again for read/write purposes
                 */
                appDataSDCard.state = APP_SD_FS_MOUNT_DISK_AGAIN;
            }
            break;
        }
        
        /* SD Card Re-mounting State */
        case APP_SD_FS_MOUNT_DISK_AGAIN:
        {
            if(SYS_FS_Mount(SDCARD_DEV_NAME, SDCARD_MOUNT_NAME, FAT, 0, NULL) != 0)
            {
                /* Testing Re-Mount: May be not Re-mounted, Try again Re-Mounting! */
                appDataSDCard.state = APP_SD_FS_MOUNT_DISK_AGAIN;          
            }
            
            /* Executed if the re-mount was successful.
            * Set current drive so that we do not have 
            * to use absolute path.
            */
            else 
            {
                appDataSDCard.state = APP_SD_FS_SET_CURRENT_DRIVE;
            }
            break;
        }
        
        /* SD Card Set Current Drive State */
        case APP_SD_FS_SET_CURRENT_DRIVE:
        {
            /* Proceed to create Directory */
            if(SYS_FS_CurrentDriveSet(SDCARD_MOUNT_NAME) == SYS_FS_RES_FAILURE)
            {
                appDataSDCard.state = APP_SD_FS_CREATE_DIRECTORY;
            }
            
            /* Proceed to create Directory */
            else
            {
                appDataSDCard.state = APP_SD_FS_CREATE_DIRECTORY;
            }
            break;
        }
        
        /* SD Card Directory creating State */
        case APP_SD_FS_CREATE_DIRECTORY:
        {
            /* Checks if the directory exists and opens the file */
            if(SYS_FS_DirectoryMake(SDCARD_DIR_NAME) == SYS_FS_RES_FAILURE)
            {
                appDataSDCard.state = APP_SD_FS_OPEN_THE_FILE;
            }
            
            /* Checks if the directory doesn't exists, which has created, and
             * then it will open file
             */
            else
            {
                appDataSDCard.state = APP_SD_FS_OPEN_THE_FILE;
            }
            break;
        }
        
        /* SD Card open file state */
        case APP_SD_FS_OPEN_THE_FILE:
        {
            /* Move on to modifying the file */
            appDataSDCard.state = APP_SD_FS_WRITE_TO_FILE;
            break;
        }
        
        /* SD Card write data state*/
        case APP_SD_FS_WRITE_TO_FILE:
        {
            {
            
            RTC_RTCCTimeGet(&sys_time);
            
            appDataSDCard.fileHandle=SYS_FS_FileOpen(SDCARD_DIR_NAME"/"SDCARD_FILE_NAME, (SYS_FS_FILE_OPEN_APPEND_PLUS));
                
            SYS_FS_FileSeek(appDataSDCard.fileHandle,0,SYS_FS_SEEK_CUR);
            
            if(sdcard_write_flag)
                
            {
                    
            SYS_FS_FilePrintf(appDataSDCard.fileHandle,"\r Time :%02d/%02d/%d - %02d:%02d:%02d",sys_time.tm_mday,(sys_time.tm_mon)+1,(sys_time.tm_year)+1900,sys_time.tm_hour, sys_time.tm_min, sys_time.tm_sec); 
            
            if(flame_detect_flag)
            {
                SYS_FS_FilePrintf(appDataSDCard.fileHandle,"\n Smoke Detected");
            }
            
            else
            {
                SYS_FS_FilePrintf(appDataSDCard.fileHandle,"\n No Smoke");
            }
            sdcard_write_flag=0;
            }
            
            /* Closing the file in the SD Card */
            appDataSDCard.state = APP_SD_FS_CLOSE_FILE;  
            
            break;
          }
        }
        
        /* SD Card Close File State */
        case APP_SD_FS_CLOSE_FILE:
        {
            /* Closing the SD Card file*/
            SYS_FS_FileClose(appDataSDCard.fileHandle);
            
            /* Moving the SD Card tasks to IDLE*/
            {
                appDataSDCard.state = APP_SD_FS_IDLE;
            }
            break;
        }
        
        /* SD Card IDLE state Definition */
        case APP_SD_FS_IDLE:
        {
            appDataSDCard.state = APP_SD_FS_WRITE_TO_FILE;
            break;
        }

        /* The default state should never be executed. */
        case APP_SD_FS_ERROR:
        {
            break;
        }
        
        default:
        {
            /* TODO: Handle error in application's state machine. */
            appDataSDCard.state = APP_SD_FS_STATE_INIT;
            break;
        }
    }
}

/*******************************************************************************
  Function:
    APP_Tasks_Flame_Detector ( void )

  Remarks:
    *Periodical ADC Conversion.
    *Periodical ADC Result read.
    *Updates Flame Detection Warning Message by comparing ADC Value.  
 */
void APP_Tasks_Flame_Detector( void )
{
    /* Start ADC conversion */
    ADC_ConversionStart();

    /* Wait till ADC conversion result is available */
    while(!ADC_ConversionStatusGet())
    {
        /* Do nothing */
    };

    /* Read the ADC result */
    adc_count = ADC_ConversionResultGet();
    input_voltage = (float)adc_count * ADC_VREF / 4095U;
                   
    /* ADC Compare Flame Threshold*/
    if(input_voltage >= FLAME_THRESHOLD_VOLTAGE)
    {
        flame_detect_flag = true; /* Flame Detected! */
    }
    
    else
    {
        flame_detect_flag = false;
    }
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 *****************************************************************************/

void APP_Tasks ( void )
{    
    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;
                
                 ADC_Enable();
                 oled_c_example_initialize();

            if (appInitialized)
            {              
                
                SYS_TIME_CallbackRegisterMS (APP_UPDATE_callback , 0, 3000, SYS_TIME_PERIODIC );
                
                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            
            APP_Tasks_Set_Time();
    
            APP_Tasks_Flame_Detector();
    
            APP_Tasks_SD_Card();

            APP_Tasks_RNBD();
            
            break;
        }

        default:
        {
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
