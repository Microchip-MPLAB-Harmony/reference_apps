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
/*******************************************************************************
* Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.
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

#include "app.h"
#include "Game.h"


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
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;

SYS_TIME_HANDLE sys_timer_handle_200ms;

SYS_TIME_HANDLE sys_timer_game_update_handle;

extern leButtonWidget* Game_Level2_ButtonWidget2;

#define OFFSET 10
void event_Menu_ButtonWidget_0_OnPressed(leButtonWidget* btn)
{
	LED_BLUE_On();
	selected_level= LEVEL1;
}

void event_Menu_ButtonWidget_1_OnPressed(leButtonWidget* btn)
{
   LED_BLUE_On();
   selected_level= LEVEL2;
}
leBool appTouchEventReceiver1(leWidget* target, leWidgetEvent* evt, void* data)
{
    leWidgetEvent_TouchMove* touchMoveEvent = (leWidgetEvent_TouchMove*)evt;
	
    
    if (evt->id != LE_EVENT_TOUCH_MOVE)
	{ return LE_FALSE;}
    
    if(touchMoveEvent->x > (touchMoveEvent->prevX + OFFSET)){ final_direction = LEFT;}
	else if(touchMoveEvent->x < (touchMoveEvent->prevX - OFFSET )){ final_direction = RIGHT;}
    else if(touchMoveEvent->y < (touchMoveEvent->prevY - OFFSET)){ final_direction = DOWN;}
	else if(touchMoveEvent->y > (touchMoveEvent->prevY + OFFSET)){ final_direction = UP;}
	

    return LE_TRUE;   
}

leBool appTouchEventReceiver2(leWidget* target, leWidgetEvent* evt, void* data)
{
    leWidgetEvent_TouchMove* touchMoveEvent = (leWidgetEvent_TouchMove*)evt;
    
    if (evt->id != LE_EVENT_TOUCH_MOVE)
        return LE_FALSE;
        
    if(touchMoveEvent->x > (touchMoveEvent->prevX + OFFSET)){ final_direction = LEFT;}
	else if(touchMoveEvent->x < (touchMoveEvent->prevX - OFFSET )){ final_direction = RIGHT;}
    else if(touchMoveEvent->y < (touchMoveEvent->prevY - OFFSET)){ final_direction = DOWN;}
	else if(touchMoveEvent->y > (touchMoveEvent->prevY + OFFSET)){ final_direction = UP;}
   
    
    return LE_TRUE;   
}

static leWidgetEventFilter touchEventReceiver1 =
{
    appTouchEventReceiver1,
    NULL
};

static leWidgetEventFilter touchEventReceiver2 =
{
    appTouchEventReceiver2,
    NULL
};

void Game_Level1_OnShow(void)
{
	 Game_Level1_ButtonWidget1->fn->installEventFilter(Game_Level1_ButtonWidget1, touchEventReceiver1);
}

void Game_Level2_OnShow(void)
{
	 Game_Level2_ButtonWidget2->fn->installEventFilter(Game_Level2_ButtonWidget2, touchEventReceiver2);
}


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
SYS_TIME_HANDLE game_sys_timer_splash_screen_handle;
void APP_Initialize ( void )
{    
    Game_SetUpdatePendingStatus(false);
    
    Game_SetSplashScreenUpdatePendingStatus(false);
    
    //setting the System Timer callback function for polling periodically the user input regarding the menu selection
    sys_timer_menu_selection = SYS_TIME_TimerCreate(1, SYS_TIME_MSToCount(GAME_SYS_TIME_200MS), &Game_SysTimerMenuSelection, (uintptr_t)NULL, SYS_TIME_PERIODIC);
    
    //setting the System Timer callback function for periodically setting the game update flag
    sys_timer_game_update_handle = SYS_TIME_TimerCreate(0, SYS_TIME_MSToCount(GAME_SYS_TIME_200MS), &SysTimer_Game_Update_CallBack, (uintptr_t)NULL, SYS_TIME_PERIODIC);
    
    //setting the System Timer callback function for updating the splash screen
    game_sys_timer_splash_screen_handle = SYS_TIME_TimerCreate(2, SYS_TIME_MSToCount(GAME_SYS_TIME_3000MS), &Game_SysTimerSplashScreenCallBack, (uintptr_t)NULL, SYS_TIME_PERIODIC);
     
    SYS_TIME_TimerStart(game_sys_timer_splash_screen_handle);
    
    
    appData.state = APP_STATE_SPLASH_SCREEN_STATE;
    
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    switch ( appData.state )
    {  
        
        case APP_STATE_SPLASH_SCREEN_STATE:
        {
		   selected_level = LEVEL_NOT_SELECTED;
           Game_SplashScreenTask();
           
           break; 
        }
        
        case APP_STATE_MENU_STATE:
        {	   
           Game_LevelSelectionTask();
           SYS_TIME_TimerStart(sys_timer_menu_selection);
    
           break;
        }
        
        case APP_STATE_GAME_INIT:
        {
		   Game_Init();

           appData.state = APP_STATE_GAME_TASK;
           LED_BLUE_Off();
           break;
        }

        case APP_STATE_GAME_TASK:
        {
           Game_Task();

            break;
        }

        /* TODO: implement your application state machine.*/


        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

void SysTimer_Game_Update_CallBack ( uintptr_t context )
{
    Game_SetUpdatePendingStatus(true);
}



/*******************************************************************************
 End of File
 */
