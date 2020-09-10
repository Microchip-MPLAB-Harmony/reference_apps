/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    Game.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides prototypes and definitions for the Game screens.
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

#ifndef GAME_SCREENS_H
#define	GAME_SCREENS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "config\default\gfx\legato\generated\screen\le_gen_screen_Menu.h"  
#include "gfx/legato/generated/screen/le_gen_screen_Game_Level1.h"
#include "Thumbstick.h"
#include "config\default\gfx\legato\widget\label\legato_widget_label.h"
#include "custom_colors.h"
#include "config\default\system\time\sys_time.h"
#include <stdio.h>

    
#define ShowMenuScreen() legato_showScreen(MENU_SCREEN_ID);
#define GetRoot_Menu() screenGetRoot_Menu(0);    
    
#define ShowGameLevel_1() legato_showScreen(LEVEL1_SCREEN_ID);
#define GetRoot_Game_Level1() screenGetRoot_Game_Level1(0);
    
#define ShowGameLevel_2() legato_showScreen(LEVEL2_SCREEN_ID);
#define GetRoot_Game_Level2() screenGetRoot_Game_Level2(0);
    
#define GAME_OVER_LEVEL1 Game_Over_level1
#define GAME_OVER_LEVEL2 Game_Over_level2
    
#define GAME_WON_LEVEL1  Game_Won_level1
#define GAME_WON_LEVEL2  Game_Won_level2
    
#define GAME_OVER_TRUE true
#define GAME_OVER_FALSE false

#define LEVEL_NOT_SELECTED 0
#define LEVEL1 1
#define LEVEL2 2
#define LEVEL3 3
    
    
#define MENU_SCREEN_ID screenID_Menu
#define LEVEL1_SCREEN_ID screenID_Game_Level1
#define LEVEL2_SCREEN_ID screenID_Game_Level2
    

#define HEART_1_LVL1 HeartImage1_level1
#define HEART_2_LVL1 HeartImage2_level1
#define HEART_3_LVL1 HeartImage3_level1

#define HEART_1_LVL2 HeartImage1_level2
#define HEART_2_LVL2 HeartImage2_level2
#define HEART_3_LVL2 HeartImage3_level2
    
    
#define SNAKE_SIZE_VALUE_LVL1 Snake_size_value_level1
#define SNAKE_SIZE_VALUE_LVL2 Snake_size_value_level2
    
    
#define SCREEN_UPPER_LIMIT 100
#define SCREEN_LOWER_LIMIT 479
#define SCREEN_LEFT_LIMIT  0
#define SCREEN_RIGHT_LIMIT 699
    
    
#define GAME_SYS_TIME_150MS 150
#define GAME_SYS_TIME_300MS 300
#define GAME_SYS_TIME_2000MS 2000
    
    
typedef enum{
    GAME_IN_PRORESS = 0,
    GAME_WON,
    GAME_OVER
    
}GAME_STATUS;
    
    
SYS_TIME_HANDLE game_sys_timer_splash_screen_handle;
    
struct Hearts
{
    bool hearts_lvl1_initialized;
    bool hearts_lvl2_initialized;
    
    bool heart1_lvl1_visible;
    bool heart2_lvl1_visible;
    bool heart3_lvl1_visible;
    
    bool heart1_lvl2_visible;
    bool heart2_lvl2_visible;
    bool heart3_lvl2_visible;
    
    uint8_t hearts_lvl1_number;
    uint8_t hearts_lvl2_number;
};


typedef enum
{
    BAR_TASK = 0,
    LOGO_TASK,

} GAME_SPLASHSCREEN_STATES;


typedef enum 
{
    HEARTS_REMAINING_0 = 0,
    HEARTS_REMAINING_1,
    HEARTS_REMAINING_2,
    HEARTS_REMAINING_3
}
HEARTS_NUMBER_STATUS;


extern uint8_t game_over_flag;

extern bool game_update_flag;

extern bool splash_screen_time_update;

extern leDynamicString snake_size_str;

extern struct Hearts hearts;

extern SYS_TIME_HANDLE sys_timer_menu_selection;


/*******************************************************************************
 Function:
    void Game_Init();

  Summary:
    The game initialization routine.

  Description:
    This function will initialize the game.

  Precondition:
    
   

  Parameters:
    None.

  Returns:
    None.


  Remarks:
    
*/

void Game_Init();

/*******************************************************************************
 Function:
    void Game_Task();

  Summary:
    The game task routine.

  Description:
    This function contains the state machine for the game.

  Precondition:
    The Game_Init() function should be called before calling this function.
   

  Parameters:
    None.

  Returns:
    None.


  Remarks:
    
*/

void Game_Task();


/*******************************************************************************
 Function:
    void Game_LevelSelectionTask();

  Summary:
    The level selection task for the game.

  Description:
    This function contains the state machine for the level selection of the game.

  Precondition:
   

  Parameters:
    None.

  Returns:
    None.


  Remarks:
    
*/

/*The task function for Level selection*/
void Game_LevelSelectionTask();



/*******************************************************************************
 Function:
    void Game_LevelSelectionTask();

  Summary:
    System timer callback function that periodically calls the task function for the level selection.

  Description:
    This function is a YStem timer callback function that periodically calls ("Game_LevelSelectionTask") task routine.

  Precondition:
   

  Parameters:
    
    context - not used.

  Returns:
    None.


  Remarks:
    
*/

void Game_SysTimerMenuSelection ( uintptr_t context );


/*******************************************************************************
 Function:
    leWidget* Game_GetCurrentScreenRoot();

  Summary:
    The routine that gets the current screen root.

  Description:
    This function returns the current screen root widget.

  Precondition:
   

  Parameters:
    None.

  Returns:
    
    A pointer to the current screen root widget.


  Remarks:
    
*/

leWidget* Game_GetCurrentScreenRoot();



/*******************************************************************************
 Function:
    void Game_ScreenInit();

  Summary:
    The routine that initialize the game screens.

  Description:
    This function will initialize variables for Game module.

  Precondition:
   

  Parameters:
    None.

  Returns:
    None.


  Remarks:
    
*/

void Game_ScreenInit();



/*******************************************************************************
 Function:
    void Game_HeartIconsInit();

  Summary:
    The routine that initialize the heart icons.

  Description:
    This function will initialize the heart icons.

  Precondition:
   

  Parameters:
    None.

  Returns:
    None.


  Remarks:
    
*/

void Game_HeartIconsInit();



/*******************************************************************************
 Function:
    void Game_LabelWrite(leLabelWidget* label_wgt,unsigned int data);

  Summary:
    The routine that writes a string to a specific label widget.

  Description:
    This function will write a string to a specific label widget.

  Precondition:
   

  Parameters:
 
    label_wgt - pinter to the label widget where the string will be written.
 
    data      - int value to be written to the "label_wgt" label widget.

  Returns:
    None.


  Remarks:
    
*/

void Game_LabelWrite(leLabelWidget* label_wgt,unsigned int data);


/*The System Timer callback function that update the */
void Game_SysTimerSplashScreenCallBack ( uintptr_t context );


/*******************************************************************************
 Function:
    void Game_SplashScreenTask();

  Summary:
    The task routine for the game splash screen.

  Description:
    This function contains the state machine for the game splash screen.

  Precondition:
   

  Parameters:
    None.

  Returns:
    None.


  Remarks:
    
*/

void Game_SplashScreenTask();



/*******************************************************************************
 Function:
    bool Game_GetGametStatus();

  Summary:
    The routine that return the game status.

  Description:
    This function return the game status.

  Precondition:
   

  Parameters:
    None.

  Returns: 
 
    GAME_OVER  - the game has been lost
 
    GAME_IN_PRORESS - the game is still running

    GAME_WON - the game has been won
 * 
  Remarks:
    
*/

uint8_t Game_GetGameStatus();



/*******************************************************************************
 Function:
    void Game_SetGameStatus(uint8_t val)

  Summary:
    The routine that set the game status.

  Description:
    This function set the game status.

  Precondition:
   

  Parameters:
    
    GAME_OVER  - the game has been lost
 
    GAME_IN_PRORESS - the game is still running

    GAME_WON - the game has been won

  Returns: 
 

  Remarks:
    
*/

void Game_SetGameStatus(uint8_t val);



/*******************************************************************************
 Function:
    bool Game_GetUpdatePendingStatus();

  Summary:
    The routine gets the pending status for the game updates.

  Description:
    This function return the pending status for the game updates.

  Precondition:
   

  Parameters:


  Returns: 
 
     true - the game needs to be updated 

     false - the game doesn't need to be updated
 

  Remarks:
    
*/

bool Game_GetUpdatePendingStatus();



/*******************************************************************************
 Function:
    void Game_SetUpdatePendingStatus(bool val);

  Summary:
    The routine sets the pending status for the game updates.

  Description:
    This function sets the pending status for the game updates.

  Precondition:
   

  Parameters:

     true  - the game needs to be updated 

     false - the game doesn't need to be updated

  Returns: 


  Remarks:
    
*/

void Game_SetUpdatePendingStatus(bool val);


/*******************************************************************************
 Function:
    bool Game_GetSplashScreenUpdatePendingStatus();

  Summary:
    The routine gets the pending status for the splash screen update.

  Description:
    This function return  the pending status for the splash screen update.

  Precondition:
   

  Parameters:


  Returns: 
  
     true  - the splash screen needs to be updated 

     false - the splash screen doesn't need to be updated


  Remarks:
    
*/

bool Game_GetSplashScreenUpdatePendingStatus();


/*******************************************************************************
 Function:
    void Game_SetSplashScreenUpdatePendingStatus(bool val);

  Summary:
    The routine sets the pending status for the splash screen update.

  Description:
    This function sets  the pending status for the splash screen update.

  Precondition:
   

  Parameters:
 
     true  - the splash screen needs to be updated 

     false - the splash screen doesn't need to be updated


  Returns: 
  

  Remarks:
    
*/

void Game_SetSplashScreenUpdatePendingStatus(bool val);

#ifdef	__cplusplus
}
#endif

#endif	/* GAME_SCREENS_H */

