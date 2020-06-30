#include "Game.h"
#include "app.h"


uint8_t game_over_flag;

bool game_update_flag;

bool splash_screen_time_update;

leDynamicString snake_size_str;

struct Hearts hearts;

SYS_TIME_HANDLE sys_timer_menu_selection;


void Game_SelectLabelLevel(leLabelWidget* label)
{
  static leScheme scheme;
    scheme = *label->fn->getScheme(label);
    scheme.highlightLight = SNAKE_COLOR_YELLOW;
    scheme.shadow = SNAKE_COLOR_YELLOW;
    label->fn->setScheme(label,&scheme);

}

void Game_UnselectLabelLevel(leLabelWidget* label)
{
  label->fn->setScheme(label,&Level_label_scheme);
}

void Game_LevelSelectionTask()
{
  static uint8_t selected_level = LEVEL_NOT_SELECTED;
    
  
  switch (thumbstick.final_direction)
  {
      case DOWN:
      {
          Nop();
          switch(selected_level)
          {
              case LEVEL_NOT_SELECTED:
              {
                  Game_SelectLabelLevel(Level1_label);
                  selected_level = LEVEL1;
                  break;
              }
              
              case LEVEL1:
              {
                  Game_UnselectLabelLevel(Level1_label);
                  Game_SelectLabelLevel(Level2_label);
                  selected_level = LEVEL2;
                  break;
              }
              
              case LEVEL2:
              {
                  Game_UnselectLabelLevel(Level2_label);
                  Game_SelectLabelLevel(Level1_label);
                  selected_level = LEVEL1;
                  break;
              }         
          }
          break;
      }
      
      case UP:
      {
          switch(selected_level)
          {
           case LEVEL_NOT_SELECTED:
              {
                  Game_SelectLabelLevel(Level1_label);
                  selected_level = LEVEL1;
                  break;
              }
              
              case LEVEL1:
              {
                  Game_UnselectLabelLevel(Level1_label);
                  Game_SelectLabelLevel(Level2_label);
                  selected_level = LEVEL2;
                  break;
              }
              
              case LEVEL2:
              {
                  Game_UnselectLabelLevel(Level2_label);
                  Game_SelectLabelLevel(Level1_label);
                  selected_level = LEVEL1;
                  break;
              }  
          }
              break;
      }
      
      default:
          break;
  }
  
  if(THUMBSTICK_INT_Get() == 0)
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
            case MENU_SCREEN_ID:

                break;

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
    char data_char[10];
    
    sprintf(data_char,"%u/%d",data,SNAKE_MAX_SIZE);
   
    leDynamicString_Constructor(&snake_size_str);
    
    snake_size_str.fn->setFont(&snake_size_str,leStringTable_GetStringFont(leGetState()->stringTable, string_Snake_Size_text, 0));
          
    //convert the character string to leFixedString object
    snake_size_str.fn->setFromCStr(&snake_size_str,data_char);
       
    //Set ClockLabel text to object
    label_wgt->fn->setString(label_wgt, (leString*)&snake_size_str);
    
}

void Game_Init()
{
    SYS_TIME_TimerStop(sys_timer_menu_selection);
    
    Game_ScreenInit();
    
    Snake_Init();

    SYS_TIME_TimerStart(sys_timer_game_update_handle);
}


void Game_Task()
{   
    if(Game_GetUpdatePendingStatus() == true)
    {
        if(Game_GetGameStatus() == GAME_IN_PRORESS)
        {
          Snake_Task();
        }
        if(THUMBSTICK_INT_Get() == THUMBSTICK_PRESSED)
        {
            //stop the timer callback that take care of the "game_update_flag"
            SYS_TIME_TimerStop(sys_timer_game_update_handle);
            
            //destroy the "snake_size_str" dynamic string object to prevent a reset if the Constructor for this object is called again
            snake_size_str.fn->destructor(&snake_size_str);
            
            //destroy all the widgets that were dynamic allocating the snake and the food to avoid resets when calling again the malloc creating again new widgets for the snake
            Snake_Destroy();
            
            //show the Menu screen
            legato_showScreen(MENU_SCREEN_ID);
            appData.state = APP_STATE_MENU_STATE;
            
            //start the timer callback again
            SYS_TIME_TimerStart(sys_timer_menu_selection);
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


