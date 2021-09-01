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


#include "app.h"
#include "config/default/definitions.h"
#include "grid_eye_click.h"
#include "start_screen.h"


APP_DATA appData;

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */


void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
 
    appData.state = APP_START_SCREEN_TASK;



    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}

static void OLED_C_Click_Display_Refresh()
{
    GFX_DISP_INTF_PIN_EN_Clear();
    GFX_DISP_INTF_PIN_RW_Clear();
    GFX_DISP_INTF_PIN_EN_Set();
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    // OLED_C Click Display Refresh
    OLED_C_Click_Display_Refresh();

    switch ( appData.state )
    {
        case APP_START_SCREEN_TASK:
        {
            if(START_SCREEN_Task() == START_SCREEN_TASK_DONE)
            {
              appData.state = APP_GRID_EYE_INIT;
            }
        
            break;
        }
        
        case APP_GRID_EYE_INIT:
        {
                      
          GRID_EYE_Initialize(&grid_eye_obj);

          appData.state = APP_GRID_EYE_TASK;
            
            break;
        }
        
        case APP_GRID_EYE_TASK:
        {
            GRID_EYE_Sensor_task();
            
            GRID_EYE_Display_task();
            
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
