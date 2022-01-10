#include "apps.h"
#include "bsp/bsp.h"
#include "user.h"
#include "gfx/driver/controller/slcd/drv_gfx_slcd.h"
#include "definitions.h"               
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

#define SDCARD_MOUNT_NAME    "/mnt/mydrive"
#define SDCARD_DEV_NAME      "/dev/mmcblka1"
//#define SDCARD_FILE_NAME     "FILE_TOO_LONG_NAME_EXAMPLE_123.JPG"

#define SDCARD_FILE_NAME     "DATA_LOG.TXT"
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
uint32_t photo_current,light_intensity,Prevphoto_current=99999;
struct tm sys_time;

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

void APPS_Initialize ( void )
{
    
    SUPC_REGS->SUPC_BBPS = SUPC_BBPS_CONF(SUPC_BBPS_CONF_APWS_Val);//Automatic Power Switch(APS)
   // SUPC_REGS->SUPC_BBPS = SUPC_BBPS_WAKEEN(1); //wake after back up mode
    
    
    
    /* Place the App state machine in its initial state. */
    appData.state = APP_START; 
    
    /* Wait for the switch status to return to the default "not pressed" state */
   // while(SWITCH_GET() == SWITCH_STATUS_PRESSED);
    
    
    appDataUSB.USBstate = APP_STATE_INIT;
    
    /* Set device layer handle as invalid */
    appDataUSB.usbDeviceHandle = USB_DEVICE_HANDLE_INVALID;

}

void APP_SLCD_Initialize ( void )
{
    
	slcd_set_contrast(0xf);

    /* turn on backlight */
    SLCD_BACKLIGHT_Set();
    
       
	/* Character map*/
	slcd_character_map_set(SLCD_AUTOMATED_CHAR_START_FROM_BOTTOM_RIGHT, 1);
    
    slcd_enable();
    /*Clearing all pixels*/
    for(uint32_t i = 0; i < 8; i++) {
        
        for(uint32_t j = 0; j < 24; j++)
        {
            slcd_clear_pixel(i,j);
        }
    }
     /*TEXT-T*/  
    slcd_set_pixel(3,17);
    slcd_set_pixel(7,17);
    slcd_set_pixel(5,16);
      /*TEXT-E*/  
    slcd_set_pixel(7,19);
    slcd_set_pixel(7,18);
    slcd_set_pixel(4,18);  
    slcd_set_pixel(4,19);
    slcd_set_pixel(2,18);
    slcd_set_pixel(1,18);
     /*TEXT-M*/ 
    slcd_set_pixel(2,20);
    slcd_set_pixel(7,20);
    slcd_set_pixel(6,20);  
    slcd_set_pixel(5,21);
    slcd_set_pixel(6,21);
    slcd_set_pixel(1,21);
    
    slcd_set_pixel(2,22);
    slcd_set_pixel(7,22);
    slcd_set_pixel(7,23);  
    slcd_set_pixel(6,23);
    slcd_set_pixel(4,23);
    slcd_set_pixel(4,22);
    
    slcd_set_pixel(0,19);
    
    /*TEXT ALS*/
    slcd_set_pixel(7,9);
    slcd_set_pixel(6,9);
    slcd_set_pixel(1,9);  
    slcd_set_pixel(7,8);
    slcd_set_pixel(2,8);
    slcd_set_pixel(4,8);
    slcd_set_pixel(4,9);
    
    slcd_set_pixel(7,10);
    slcd_set_pixel(2,10);
    slcd_set_pixel(1,10); 
    
    slcd_set_pixel(7,13);
    slcd_set_pixel(7,12);
    slcd_set_pixel(4,12);  
    slcd_set_pixel(4,13);
    slcd_set_pixel(1,13);
    slcd_set_pixel(1,12);
    
    
   // slcd_set_pixel(4,14);
  //  slcd_set_pixel(4,15);
    
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
            
               
               // SYS_FS_FilePrintf(appData.fileHandle,"ADC Count = 0x%x, Light Intensity = %d.%03d Lux \r", adc_count, (int)(photo_current/1000), (int)(photo_current%1000));
                 
                 RTC_RTCCTimeGet(&sys_time);
                 SYS_FS_FilePrintf(appData.fileHandle,"\r Time:%02d/%02d/%d - %02d:%02d:%02d     ",sys_time.tm_mday,(sys_time.tm_mon)+1,(sys_time.tm_year)+1900,sys_time.tm_hour, sys_time.tm_min, sys_time.tm_sec); 
                 
                
                 
                 SYS_FS_FilePrintf(appData.fileHandle,"ADC Count = 0x%03x,     Light Intensity = %02d.%03d  Lux     ", adc_count, (int)(photo_current/1000), (int)(photo_current%1000));
                 SYS_FS_FilePrintf(appData.fileHandle,"Temperature = %d C", CurrentTemp);
                 appData.state = APP_CLOSE_FILE;
             
            break;

        case APP_CLOSE_FILE:
           
            SYS_FS_FileClose(appData.fileHandle);
           
            appData.state = APP_IDLE;
            break;

        case APP_IDLE:
            
           //Write to the file once the new temperature is updated//
            if(TempUpdateFlag==ON)
            {
            appData.state = APP_WRITE_TO_FILE;
            TempUpdateFlag=OFF;
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
           // LED_Off();
            break;

        case USB_DEVICE_EVENT_CONFIGURED:

            /* Device is configured. Update LED status */
           // LED_On();
            break;

        case USB_DEVICE_EVENT_SUSPENDED:
		
			//LED_Off();
            break;

        case USB_DEVICE_EVENT_POWER_DETECTED:

            /* VBUS is detected. Attach the device. */
            USB_DEVICE_Attach(appDataObject->usbDeviceHandle);
            break;

        case USB_DEVICE_EVENT_POWER_REMOVED:

            /* VBUS is not detected. Detach the device */
            USB_DEVICE_Detach(appDataObject->usbDeviceHandle);
            //LED_Off();
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
        light_intensity=photo_current/1000; //in LUX
}

void APP_TASKS_DISPLAY_TEMP(unsigned char temperature)
{
    
     for(uint32_t z = 0; z < 8; z++)
        {
            slcd_clear_pixel(z,6); //for temp 
            slcd_clear_pixel(z,7);
        }
    
    unsigned char UnitDigit,TensDigit;
    
    UnitDigit=temperature%10;
    TensDigit=temperature/10;
    
    
    
    Display_Character(TensDigit,6);
    Display_Character(UnitDigit,7);
}

void APP_TASKS_DISPLAY_LSOUT(uint32_t photo_current)
{
     for(uint32_t z = 0; z < 8; z++)
        {
            slcd_clear_pixel(z,1); //for temp 
            slcd_clear_pixel(z,4);
        }
    
    
    unsigned char UnitDigitLS,TensDigitLS;
    
    UnitDigitLS=photo_current%10;
    TensDigitLS=photo_current/10;
    
    
    Display_Character(TensDigitLS,1);
    Display_Character(UnitDigitLS,4);
}



void Display_Character(unsigned char value,unsigned char pos)
{
   
    switch(value)
    {
        
    
    case 0:
     slcd_set_pixel(0,pos);//seg a
     slcd_set_pixel(2,pos);//seg b
     slcd_set_pixel(5,pos);//seg c
     slcd_set_pixel(6,pos);//seg d
     slcd_set_pixel(4,pos);//seg e
     slcd_set_pixel(1,pos);//seg f
    break;
     
     case 1:
     slcd_set_pixel(2,pos);
     slcd_set_pixel(5,pos);
     break;
     
     case 2:
     slcd_set_pixel(0,pos);
     slcd_set_pixel(2,pos);
     slcd_set_pixel(3,pos);
     slcd_set_pixel(4,pos);
     slcd_set_pixel(6,pos);
     break;
     
     case 3:
     slcd_set_pixel(0,pos);
     slcd_set_pixel(2,pos);
     slcd_set_pixel(3,pos);
     slcd_set_pixel(5,pos);
     slcd_set_pixel(6,pos);
     break;
     
     case 4:
     slcd_set_pixel(1,pos);
     slcd_set_pixel(3,pos);
     slcd_set_pixel(2,pos);
     slcd_set_pixel(5,pos);
     break;
     
     case 5:
     slcd_set_pixel(0,pos);
     slcd_set_pixel(1,pos);
     slcd_set_pixel(3,pos);
     slcd_set_pixel(5,pos);
     slcd_set_pixel(6,pos);
     break;
     
     case 6:
     slcd_set_pixel(0,pos);
     slcd_set_pixel(1,pos);
     slcd_set_pixel(3,pos);
     slcd_set_pixel(5,pos);
     slcd_set_pixel(6,pos);
     slcd_set_pixel(4,pos);
     break;
     
     case 7:
     slcd_set_pixel(0,pos);
     slcd_set_pixel(2,pos);
     slcd_set_pixel(5,pos);       
     break;
    
     case 8:
     slcd_set_pixel(0,pos);//seg a
     slcd_set_pixel(2,pos);//seg b
     slcd_set_pixel(5,pos);//seg c
     slcd_set_pixel(6,pos);//seg d
     slcd_set_pixel(4,pos);//seg e
     slcd_set_pixel(1,pos);//seg f
     slcd_set_pixel(3,pos);//seg g
     break;
     
     case 9:
     slcd_set_pixel(0,pos);//seg a
     slcd_set_pixel(2,pos);//seg b
     slcd_set_pixel(5,pos);//seg c
     slcd_set_pixel(6,pos);//seg d
     slcd_set_pixel(1,pos);//seg f
     slcd_set_pixel(3,pos);//seg g
     break;
     //end
    }
}

void SetTime(void)
{
    /*Edit the below parameters to set a proper time*/
    /*Press SW0 on SAM L22 to set the the time*/
if (SWITCH_Get() == SWITCH_STATE_PRESSED)
     { 
           //5-12-2021 15:38:00 Sunday
    sys_time.tm_hour = 15;      /* hour [0,23] */
    sys_time.tm_sec = 00;       /* seconds [0,61] */
    sys_time.tm_min = 38;       /* minutes [0,59] */
    sys_time.tm_mon = 11;        /* month of year [0,11] */
    sys_time.tm_year = 121;     /* years since 1900 */
    sys_time.tm_mday = 5;      /* day of month [1,31] */
    sys_time.tm_wday = 0;       /* day of week [0,6] (Sunday = 0) */
                                /* tm_yday - day of year [0,365] */
                                /* tm_isdst - daylight savings flag */
    
    
    RTC_RTCCTimeSet(&sys_time);
     }
}

void APPS_Tasks(void)
{
     APP_Tasks_SD_FS ( );
     APP_Tasks_ADC();
     if(PrevTemp !=CurrentTemp)
     {
     APP_TASKS_DISPLAY_TEMP(CurrentTemp);
     PrevTemp=CurrentTemp;
     }
     if(Prevphoto_current != light_intensity)
     {
     APP_TASKS_DISPLAY_LSOUT(light_intensity);
     Prevphoto_current = light_intensity;
     }
     
     APP_Tasks_USB ( );
     
     /*Edit this function to with proper time to be Set and Press SW0 */
     SetTime();
}