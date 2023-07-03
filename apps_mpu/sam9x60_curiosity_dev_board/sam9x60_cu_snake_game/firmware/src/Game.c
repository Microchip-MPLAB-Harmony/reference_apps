/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    Game.c

  Summary:
    This file contains the source code for the MPLAB Harmony Game application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the Game application's state machine.
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

#include "Snake.h"
#include "app.h"
#include "gfx/legato/generated/le_gen_init.h"

uint8_t game_over_flag;

bool game_update_flag;

bool splash_screen_time_update;

leFixedString startStr;
static leChar currTimeStr[15];

struct Hearts hearts;

SYS_TIME_HANDLE sys_timer_menu_selection;

uint8_t selected_level = LEVEL_NOT_SELECTED;


void Game_SelectLabelLevel(leLabelWidget* label)
{
    label->fn->setScheme(label,&Selected_Level_label_scheme);
}

void Game_UnselectLabelLevel(leLabelWidget* label)
{
  label->fn->setScheme(label,&Unselected_Level_label_scheme);
}

void Game_LevelSelectionTask()
{
    switch(selected_level)
    {
        case LEVEL1:
              {
                  ShowGameLevel_1();				  
                  SYS_TIME_TimerStop(sys_timer_menu_selection);
                  appData.state = APP_STATE_GAME_INIT;
                  selected_level = LEVEL_NOT_SELECTED;
                  break;
              }
              
              case LEVEL2:
              {
				  ShowGameLevel_2();
                  SYS_TIME_TimerStop(sys_timer_menu_selection);
                  appData.state = APP_STATE_GAME_INIT;
                  selected_level = LEVEL_NOT_SELECTED;
                  break;
              } 
          default:
              
              break;
    }
}


void Game_SysTimerMenuSelection ( uintptr_t context )
{
  Game_LevelSelectionTask();
}

leWidget* Game_GetCurrentScreenRoot()
{
    uint32_t c_screen;
    
    c_screen = legato_getCurrentScreen();
    
    switch(c_screen)
    {
        case MENU_SCREEN_ID:
            return GetRoot_Menu();
            break;
            
        case LEVEL1_SCREEN_ID:
            return GetRoot_Game_Level1();
            break;
            
        case LEVEL2_SCREEN_ID:
            return GetRoot_Game_Level2();
            break;
            
        default:
            return NULL;
            break;
    }
}


void Game_ScreenInit()
{
  hearts.hearts_lvl1_initialized = false;
  hearts.hearts_lvl2_initialized = false;
  
  hearts.heart1_lvl1_visible = true;
  hearts.heart2_lvl1_visible = true;
  hearts.heart3_lvl1_visible = true;
  
  hearts.heart1_lvl2_visible = true;
  hearts.heart2_lvl2_visible = true;
  hearts.heart3_lvl2_visible = true;
  
  hearts.hearts_lvl1_number = HEARTS_REMAINING_3;
  hearts.hearts_lvl2_number = HEARTS_REMAINING_3;
   
  Game_SetGameStatus(GAME_IN_PRORESS);
}


void Game_HeartIconsInit()
{
    uint32_t c_screen;
    
    c_screen = legato_getCurrentScreen();
    
    if((hearts.hearts_lvl1_initialized == false) || (hearts.hearts_lvl2_initialized == false))
    {
    
        switch(c_screen)
        {
            case LEVEL1_SCREEN_ID:
                
                if(hearts.hearts_lvl1_initialized == false)
                {
                    HEART_1_LVL1->fn->setVisible(HEART_1_LVL1,true);
                    HEART_2_LVL1->fn->setVisible(HEART_2_LVL1,true);
                    HEART_3_LVL1->fn->setVisible(HEART_3_LVL1,true);
                    hearts.hearts_lvl1_initialized = true;
                }
                break;

            case LEVEL2_SCREEN_ID:

                if(hearts.hearts_lvl2_initialized == false)
                {
                    HEART_1_LVL2->fn->setVisible(HEART_1_LVL2,true);
                    HEART_2_LVL2->fn->setVisible(HEART_2_LVL2,true);
                    HEART_3_LVL2->fn->setVisible(HEART_3_LVL2,true);
                    hearts.hearts_lvl2_initialized = true;
                }
                break;

            default:

                break;
        }
   }
}


void Game_LabelWrite(leLabelWidget* label_wgt,unsigned int data)
{
    static char currTimeStr[15];
    
    sprintf( currTimeStr, "%u/%d", data, SNAKE_MAX_SIZE);

    startStr.fn->setFromCStr(&startStr, currTimeStr);
    label_wgt->fn->setString(label_wgt, (leString*)&startStr);
}

void Game_Init()
{
    SYS_TIME_TimerStop(sys_timer_menu_selection);
    
    Game_ScreenInit();

    leFixedString_Constructor(&startStr, currTimeStr, 10);
    startStr.fn->setFont(&startStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              string_Snake_Size_text.index,
                                                              0));

    Snake_Init();

    SYS_TIME_TimerStart(sys_timer_game_update_handle);

}


void Game_Task()
{   
    if(SW1_Get() == SW1_STATE_PRESSED)
    {
        //stop the timer callback that take care of the "game_update_flag"
        SYS_TIME_TimerStop(sys_timer_game_update_handle);
            
        //destroy all the widgets that were dynamic allocating the snake and the food to avoid resets when calling again the malloc creating again new widgets for the snake
        Snake_Destroy();
           
        //show the Menu screen
		selected_level = LEVEL_NOT_SELECTED;

        legato_showScreen(MENU_SCREEN_ID);
        appData.state = APP_STATE_MENU_STATE;
            
        //start the timer callback again
         SYS_TIME_TimerStart(sys_timer_menu_selection);

		// reset the flag       
        Game_SetUpdatePendingStatus(false);
	}  

	else if(Game_GetUpdatePendingStatus() == true)
    {
        if(Game_GetGameStatus() == GAME_IN_PRORESS)
        {
          Snake_Task();
        }
                
        // reset the flag       
        Game_SetUpdatePendingStatus(false);
        
    }
}


void Game_SysTimerSplashScreenCallBack ( uintptr_t context )
{
   
    Game_SetSplashScreenUpdatePendingStatus(true);
    
}



void Game_SplashScreenTask()
{
   
    if(Game_GetSplashScreenUpdatePendingStatus() == true)
    {
      appData.state = APP_STATE_MENU_STATE;
      legato_showScreen(MENU_SCREEN_ID);
    }    
    
}


uint8_t Game_GetGameStatus()
{
    return game_over_flag;
}


void Game_SetGameStatus(uint8_t val)
{
    game_over_flag = val;
}


bool Game_GetUpdatePendingStatus()
{
    return game_update_flag;
}


void Game_SetUpdatePendingStatus(bool val)
{
  game_update_flag = val;
}


bool Game_GetSplashScreenUpdatePendingStatus()
{
    return splash_screen_time_update;
}


void Game_SetSplashScreenUpdatePendingStatus(bool val)
{
   splash_screen_time_update = val;
}


