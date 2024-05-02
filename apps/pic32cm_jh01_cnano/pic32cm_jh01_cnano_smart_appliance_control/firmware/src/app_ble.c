/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_ble.c

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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************


#include "stdio.h"
#include "string.h"
#include "definitions.h"
#include "app_ble.h"
#include "rnbd/rnbd.h"
#include "config/default/rnbd/rnbd_interface.h"
#include "click_routines/fan/fan.h"
#include "config/default/touch/touch.h"



#define MAX_BUFFER_SIZE                 (80)

void check_touch();

char statusBuffer[MAX_BUFFER_SIZE];
uint8_t unread_bytes = 0;
static bool connected;
static bool RNBDRead = 0;
char resp[10];
uint8_t key_status0=0;
unsigned int ResponseRead=0;
int touch_count;
 
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
    This structure should be initialized by the APP_BLE_Initialize function.

    Application strings and buffers are be defined outside this structure.
 */

APP_BLE_DATA app_bleData;
#define BLE_DEFAULT_MODE BLE_DATA_MODE

char readBuffer[128];
static uint8_t dummyread;


typedef enum 
{
    BLE_CMD_MODE,
    BLE_DATA_MODE,
} BLE_UART_MODE;

// *****************************************************************************
// *****************************************************************************
static bool RNBD_Example_TransparentUart(void);
// *****************************************************************************
// *****************************************************************************


static bool RNBD_Example_TransparentUart(void)
{
   
    RNBD_IsConnected();
    RNBD_IsOTABegin();
    memset(resp, '\0', sizeof(resp));

    while(!RNBD.DataReady())
    {
        RNBD.DelayMs(1);
        check_touch();                  //To check whether touch is pressed to switch back to Temperature Control Mode
        if(touch_count%2 == 0)
        {
           RNBDRead= false;
           return 0;
        }
    }

    //Read Ready data 
    while(RNBD.DataReady())
    {   
        resp[ResponseRead]=(char)RNBD_Read();
        RNBD.DelayMs(1);
        ResponseRead++;  
    }
   
    ResponseRead = 0;
   
    if(!strcmp(resp, "FAN_ON"))
    {        
       fan_switch_on();        
    }
    
    else if(!strcmp(resp, "FAN_LOW"))
    {       
        fan_set_speed(SPEED_LOW);
    }
    
    else if(!strcmp(resp, "FAN_MID"))
    {        
        fan_set_speed(SPEED_MEDIUM);
    }
    
    else if(!strcmp(resp, "FAN_HIGH"))
    {       
        fan_set_speed(SPEED_HIGH);
    }
    
    else if(!strcmp(resp, "FAN_OFF"))
    {
        fan_switch_off(); 
        
    }
    else if(!strcmp(resp, "TEMP_MODE"))
    {          
        touch_count=0;
        RNBDRead = false;
        return false;
    }
    
    else
    {
      
    }
   
    return true;
   
}


void APP_BLE_Initialize(void) 
{
    /* Place the App state machine in its initial state. */
    app_bleData.state = APP_BLE_STATE_INIT;
    
}

/******************************************************************************
  Function:
    void APP_BLE_Tasks ( void )

  @Summary
 The user can control the speed of the DC fan from MBD App and also switch back to Temperature Control mode using the defined commands.
 */

void APP_BLE_Tasks(void) 
{
    check_touch();                          //To check whether touch is pressed to switch back to Temperature Control Mode
    if(touch_count%2 !=0)
    {       
     switch (app_bleData.state) 
      {       
       /* Application's initial state. */
        case APP_BLE_STATE_INIT:
        {
            fan_switch_off(); 
            bool appInitialized = false;
            RNBD_Init();
            appInitialized =  RNBD_SetAsyncMessageHandler(statusBuffer, (uint8_t)sizeof(statusBuffer)); 
            
            if (appInitialized) 
            {                       
                app_bleData.state = APP_START_CONNECTION;
            }
            break;
        }

        case APP_START_CONNECTION:
        {  
           
             if((unread_bytes=RNBD.DataReady())>0)
            {
                 while (RNBD.DataReady())
                    {       
                         dummyread=RNBD.Read();
                    }
                 
             }
            RNBDRead = true;  
            app_bleData.state = APP_BLE_STATE_WRITE_DATA;
            break;
        }
        
        case APP_BLE_STATE_WRITE_DATA:
        {
            while(RNBDRead)
            {               
            if (true == RNBD_Example_TransparentUart())
                {
               
                }
            else
                {
                    app_bleData.state = APP_BLE_STATE_COMPLETE;
                    break;
                }
            }                         
        }
                         
        case APP_BLE_STATE_COMPLETE:
        {
            RNBD_EnterCmdMode();
            RNBD_RebootCmd();
            app_bleData.state = APP_BLE_STATE_INIT;
            break;
        }
      }
    }
}



/*******************************************************************************
 End of File
 */
