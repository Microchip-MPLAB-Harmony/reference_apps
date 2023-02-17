/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    Snake.c

  Summary:
    This file contains the source code for the MPLAB Harmony Snake game
    application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the Snake game application's state machine.
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
#include "gfx/legato/widget/legato_widget.h"
#include <xc.h>
#include "gfx\legato\generated\le_gen_init.h"
#include "gfx\legato\memory\legato_memory.h"

leRectangleWidget* FOOD_RectangleWidget;      

uint16_t snake_current_size;

bool snake_initializtion_done;

struct Snake* HEAD;

struct Snake* TAIL;

struct Snake* part;

struct Snake* CurrentHead;

uint8_t final_direction = RIGHT;

enum {
    
    SNAKE_RED_STATE = 0,
    SNAKE_BLUE_STATE,
    SNAKE_GREEN_STATE,
    SNAKE_YELLOW_STATE,
    SNAKE_ORANGE_STATE,
    SNAKE_PURPLE_STATE   
}SNAKE_COLOR_STATES;

void Snake_AddAtHead(leWidget* c_root)
{
   struct Snake* part_s;
    
   part_s = (struct Snake*) LE_MALLOC(sizeof(struct Snake));
   
   //create a rectangle widget and link it to the part_s->SnakePart to be part of the snake
   part_s->SnakePart = Snake_CreateSnakePart(c_root);
   
   //set a random color for the linked rectangle
   Snake_RandomColorSet(part_s);
     
   //add the newly created rectangle to be the next element after the HEAD in the list 
   part_s->next = HEAD->next;
   part_s->previous = HEAD->next->previous;
   HEAD->next->previous = part_s;
   HEAD->next = part_s;
}



void Snake_AddAtTail(leWidget* c_root)
{
  struct Snake* part_s;

  //dynamically allocate memory space 
  part_s = (struct Snake*) LE_MALLOC(sizeof(struct Snake));
  
  //create a rectangle widget and link it to the part_s->SnakePart to be part of the snake
  part_s->SnakePart = Snake_CreateSnakePart(c_root);
  part_s->SnakePart->fn->setSize(part_s->SnakePart,SNAKE_PART_SIZE,SNAKE_PART_SIZE);
  
  //set a random color for the linked rectangle
  Snake_RandomColorSet(part_s);
  
  //add the newly created rectangle to be the previous element before the TAIL in the list
  part_s->previous = TAIL->previous;
  part_s->next = TAIL;
  TAIL->previous->next = part_s;
  TAIL->previous = part_s;      
  
}

void Snake_Init()
{
    uint32_t index;
    uint32_t X_coord = SNAKE_INITIAL_POSITION_X;
    leWidget* c_root;
    uint32_t c_screen;
    
    c_screen = legato_getCurrentScreen();
    c_root = Game_GetCurrentScreenRoot();
    
    Game_HeartIconsInit();
     
    Snake_SetCurrentSize(SNAKE_INITIAL_SIZE);
    
    Snake_SetInitializationStatus(false);

    HEAD = (struct Snake*) LE_MALLOC(sizeof(struct Snake));
    TAIL = (struct Snake*) LE_MALLOC(sizeof(struct Snake));
    
    /*create an empty list(snake)*/
    HEAD->next = TAIL;
    TAIL->previous = HEAD;
       
    Snake_FoodInit(c_root);
        
   for(index = 0; index < Snake_GetCurrentSize() ;index++)
   {
     //add the first "snake_current_size" rectangles in the list through HEAD
     Snake_AddAtHead(c_root);       
     part = HEAD->next;
     part->SnakePart->fn->setSize(part->SnakePart,SNAKE_PART_SIZE,SNAKE_PART_SIZE);  
     part->SnakePart->fn->setPosition(part->SnakePart, ((SNAKE_PART_SIZE * index)+ X_coord) , SNAKE_INITIAL_POSITION_Y);      
   }
        
    part = TAIL->previous;
    CurrentHead = HEAD->next;
    
    // write a dummy 1 to the Labels in order for the PIC to not reset when the user is trying to go back to the menu if the snake didn't eat any food
      switch(c_screen)
      {
        
          case LEVEL1_SCREEN_ID:
              
             Game_LabelWrite(SNAKE_SIZE_VALUE_LVL1,(unsigned int)1);
             
              break;
              
              
          case LEVEL2_SCREEN_ID:
              
              Game_LabelWrite(SNAKE_SIZE_VALUE_LVL2,(unsigned int)1);
              
              break;
              
          default:
              
              break;
         
      }
 
    Snake_SetInitializationStatus(true);      
}


void Snake_Task()
{
   uint16_t X_tail_head;
   uint16_t Y_tail_head;
   
   leWidget* c_root;
    
   c_root = Game_GetCurrentScreenRoot();
   
    X_tail_head = CurrentHead->SnakePart->fn->getX(CurrentHead->SnakePart);
    
    Y_tail_head = CurrentHead->SnakePart->fn->getY(CurrentHead->SnakePart);
   

   Snake_DirectionTask(X_tail_head,Y_tail_head);
   
   if(Snake_CheckRestictions(CurrentHead) == RESTRICTION_RESPECTED)
   {
       CurrentHead = part;
       Snake_EatingTask(c_root);
       part = part->previous;

       if(part == HEAD)
       {
           part = TAIL->previous;
           CurrentHead = HEAD->next; 
       }  
   }
   else
    {

    }  
}

void Snake_DirectionTask(uint16_t Current_Head_X, uint16_t Current_Head_Y)
{
   
    static uint8_t snake_direction = LEFT;
    static uint8_t snake_previous_direction = LEFT;
    
     snake_direction = final_direction;
    
    switch(snake_direction)
    {
        case LEFT:
            
            part->SnakePart->fn->setPosition(part->SnakePart,(Current_Head_X + SNAKE_PART_SIZE),Current_Head_Y);
            snake_previous_direction = LEFT;
            
            break;
            
        case RIGHT:
            
            part->SnakePart->fn->setPosition(part->SnakePart,(Current_Head_X - SNAKE_PART_SIZE),Current_Head_Y);
            snake_previous_direction = RIGHT;
            
            break;
        
        case UP:
            
            part->SnakePart->fn->setPosition(part->SnakePart,(Current_Head_X),(Current_Head_Y + SNAKE_PART_SIZE ));
            snake_previous_direction = UP;
            break;
            
        case DOWN:
            
            part->SnakePart->fn->setPosition(part->SnakePart,(Current_Head_X),(Current_Head_Y - SNAKE_PART_SIZE ));
            snake_previous_direction = DOWN;
            
            break;
            
            
        default:
            
            switch(snake_previous_direction)
            {
                case LEFT:
                
                    part->SnakePart->fn->setPosition(part->SnakePart,(Current_Head_X + SNAKE_PART_SIZE),Current_Head_Y);
                    snake_previous_direction = LEFT;

                    break;

                case RIGHT:

                    part->SnakePart->fn->setPosition(part->SnakePart,(Current_Head_X - SNAKE_PART_SIZE),Current_Head_Y);
                    snake_previous_direction = RIGHT;

                    break;

                case UP:

                    part->SnakePart->fn->setPosition(part->SnakePart,(Current_Head_X),(Current_Head_Y + SNAKE_PART_SIZE ));
                    snake_previous_direction = UP;
                    break;

                case DOWN:

                    part->SnakePart->fn->setPosition(part->SnakePart,(Current_Head_X),(Current_Head_Y - SNAKE_PART_SIZE ));
                    snake_previous_direction = DOWN;

                    break;
                    
                default:
                    
                        break;    
                    }
                                   
            break;
    }
  
}

void Snake_EatingTask()
{
    leWidget* c_root;
    uint32_t c_screen;

    c_screen = legato_getCurrentScreen();
    
    c_root = Game_GetCurrentScreenRoot();
    
    //check if the snake has eaten the food
    if(((CurrentHead->SnakePart->fn->getX(CurrentHead->SnakePart))==(FOOD->fn->getX(FOOD)))&&((CurrentHead->SnakePart->fn->getY(CurrentHead->SnakePart))==(FOOD->fn->getY(FOOD))))
    {
      
      Snake_AddAtTail(c_root);

      Snake_FoodRespawn();

      Snake_IncrementSize();

      //update the label that specify the snake size
      switch(c_screen)
      {
        
          case LEVEL1_SCREEN_ID:
              
             Game_LabelWrite(SNAKE_SIZE_VALUE_LVL1,(unsigned int)Snake_GetCurrentSize());
             
              break;
              
              
          case LEVEL2_SCREEN_ID:
              
              Game_LabelWrite(SNAKE_SIZE_VALUE_LVL2,(unsigned int)Snake_GetCurrentSize());
              
              break;
              
          default:
              
              break;
         
      }
      
    }
}

//set a radom color to the specified snake part
void Snake_RandomColorSet(struct Snake* sn_part)
{
    static leColor color_count = SNAKE_BLUE_STATE;

    switch(color_count)
    {
        case SNAKE_RED_STATE:
        {
          sn_part->SnakePart->fn->setScheme(sn_part->SnakePart,&SnakePart_Scheme_RED);
        }
          break;
          
        case SNAKE_BLUE_STATE:
        {
          sn_part->SnakePart->fn->setScheme(sn_part->SnakePart,&SnakePart_Scheme_BLUE);
        }
          break;
          
        case SNAKE_GREEN_STATE:
        {
          sn_part->SnakePart->fn->setScheme(sn_part->SnakePart,&SnakePart_Scheme_GREEN);
        }
          break;
          
        case SNAKE_YELLOW_STATE:
        {
          sn_part->SnakePart->fn->setScheme(sn_part->SnakePart,&SnakePart_Scheme_YELLOW);
        }
          break;
          
        case SNAKE_ORANGE_STATE:
        {
          sn_part->SnakePart->fn->setScheme(sn_part->SnakePart,&SnakePart_Scheme_ORANGE);
        }
          break;
          
        case SNAKE_PURPLE_STATE:
        {
          sn_part->SnakePart->fn->setScheme(sn_part->SnakePart,&SnakePart_Scheme_PURPLE);
        }
          break;
          
        default:
            sn_part->SnakePart->fn->setScheme(sn_part->SnakePart,&SnakePart_Scheme_RED);
            color_count = SNAKE_RED_STATE;
          break;
    
    }
    
    color_count++;
}

leRectangleWidget* Snake_CreateSnakePart()
{
    leRectangleWidget* sn_part;
    leWidget* root_p;
    uint16_t x_coord = 0;
    uint16_t y_coord = 0;
    
    leWidget* c_root;
    
    c_root = Game_GetCurrentScreenRoot();
    
    if(Snake_GetInitializationStatus() == true)
    {
        x_coord = TAIL->previous->SnakePart->fn->getX(TAIL->previous->SnakePart);
        y_coord = TAIL->previous->SnakePart->fn->getY(TAIL->previous->SnakePart);
    }

    root_p = c_root;
    
    sn_part = leRectangleWidget_New();
    
    if(Snake_GetInitializationStatus() == false)
    {
       sn_part->fn->setPosition(sn_part, 0, 0);
    }else
    {
       sn_part->fn->setPosition(sn_part, x_coord, y_coord);
    }
       sn_part->fn->setSize(sn_part, SNAKE_PART_SIZE, SNAKE_PART_SIZE);
       sn_part->fn->setScheme(sn_part, &SNAKE_SCHEME);
    
    root_p->fn->addChild(root_p, (leWidget*)sn_part);
    
    return sn_part;
}

//move the food at a pseudo-random position
void Snake_FoodRespawn()
{
   static uint8_t food_count = 0;
    
    switch(food_count)
    {
        case 0:
            
            FOOD->fn->setPosition(FOOD,300,300);
                    
            break;
            
        case 1:
            
            FOOD->fn->setPosition(FOOD,100,200);
            
            break;
            
        case 2:
            
            FOOD->fn->setPosition(FOOD,620,400);
            
            break;
            
        case 3:
            
            FOOD->fn->setPosition(FOOD,540,300);
            
            break;
            
        case 4:
            
            FOOD->fn->setPosition(FOOD,80,200);
            
            break;
            
        case 5:
            
            FOOD->fn->setPosition(FOOD,620,340);
            
            break;
            
        case 6:
            
            FOOD->fn->setPosition(FOOD,160,220);
            
            break;
            
        case 7:
            
            FOOD->fn->setPosition(FOOD,100,120);
            
            break;    
            
        default:
            
            FOOD->fn->setPosition(FOOD,500,120);
            food_count = 0;
            break;
    }
    
    food_count++;
}

void Snake_FoodInit(leWidget* c_root)
{
    leWidget* level_root;
    
    level_root = c_root;
    
    FOOD = leRectangleWidget_New();
    FOOD->fn->setPosition(FOOD,100,340);
    FOOD->fn->setSize(FOOD,SNAKE_PART_SIZE,SNAKE_PART_SIZE);
    FOOD->fn->setScheme(FOOD, &SNAKE_SCHEME);
    level_root->fn->addChild(level_root, (leWidget*)FOOD);
}


void Snake_Destroy()
{   
    
    struct Snake* sn_part;
    
    leWidget* c_root;
    
    c_root = Game_GetCurrentScreenRoot();
    
    sn_part = HEAD->next;
    while(sn_part != TAIL)
    {
      sn_part->SnakePart->fn->setVisible(sn_part->SnakePart,0);
      c_root->fn->removeChild(c_root,(leWidget*)sn_part->SnakePart);
      leWidget_Delete((leWidget*) sn_part->SnakePart);
 
      sn_part = sn_part->next;
      LE_FREE(sn_part->previous);
    }

    LE_FREE(HEAD);
    LE_FREE(TAIL);
    
    FOOD->fn->setVisible(FOOD,0);
    c_root->fn->removeChild(c_root,(leWidget*)FOOD);
    leWidget_Delete((leWidget*) FOOD);
   
}


bool Snake_CheckRestictions(struct Snake* c_head)
{
    
    uint32_t c_screen;
    
    c_screen = legato_getCurrentScreen();
    
    switch(c_screen)
    {            
        case LEVEL1_SCREEN_ID:
  
              if(Snake_Level1RestrictionsCheck(c_head) == RESTRICTION_VIOLATED)
                {
                   Snake_HeartsTask();
                   Snake_SetInvisible();
				   if(Game_GetGameStatus() == GAME_OVER)
				   {
					  GAME_OVER_LEVEL1->fn->setVisible(GAME_OVER_LEVEL1,true);
                   }
				   else
				   {
				   Snake_Destroy();
                   Snake_Init();
				   }

                   return RESTRICTION_VIOLATED;
                }
              
              if(Snake_GetCurrentSize() >= SNAKE_MAX_SIZE)
               {
                  Game_SetGameStatus(GAME_WON);
                  Snake_SetInvisible();
                  GAME_WON_LEVEL1->fn->setVisible(GAME_WON_LEVEL1,true);
               }
   
            break;
            
        case LEVEL2_SCREEN_ID:
            
            if(Snake_Level2RestrictionsCheck(c_head) == RESTRICTION_VIOLATED)
            {
                   Snake_HeartsTask();
                   Snake_SetInvisible();
                   if(Game_GetGameStatus() == GAME_OVER)
				   {
					  GAME_OVER_LEVEL2->fn->setVisible(GAME_OVER_LEVEL2,true);
                   }
				   else
				   {
                        Snake_Destroy();
                        Snake_Init();
				   }                                   
                   return RESTRICTION_VIOLATED;
            }
            
            if(Snake_GetCurrentSize() >= SNAKE_MAX_SIZE)
               {
                  Game_SetGameStatus(GAME_WON);
                  Snake_SetInvisible();
                  GAME_WON_LEVEL2->fn->setVisible(GAME_WON_LEVEL2,true);
               }
            
            break;
            
        default:
            
            break;
    }

    return RESTRICTION_RESPECTED;
  
}

void Snake_HeartsTask()
{
    
    uint32_t c_screen;
    
    c_screen = legato_getCurrentScreen();
    
    switch(c_screen)
        {
            case LEVEL1_SCREEN_ID:

                    switch(hearts.hearts_lvl1_number)
                    {
                        case HEARTS_REMAINING_3:

                            HEART_3_LVL1->fn->setVisible(HEART_3_LVL1,false);
                            hearts.hearts_lvl1_number--;

                            break;


                         case HEARTS_REMAINING_2:

                            HEART_2_LVL1->fn->setVisible(HEART_2_LVL1,false);
                            hearts.hearts_lvl1_number--;

                            break;


                         case HEARTS_REMAINING_1:

                            HEART_1_LVL1->fn->setVisible(HEART_1_LVL1,false);
                            hearts.hearts_lvl1_number--;

                            break;
                            
                        case HEARTS_REMAINING_0:
						
                            Game_SetGameStatus(GAME_OVER);
                            
                            break;       
                    }  
                break;

            case LEVEL2_SCREEN_ID:

                    switch(hearts.hearts_lvl2_number)
                    {
                        case HEARTS_REMAINING_3:

                            HEART_3_LVL2->fn->setVisible(HEART_3_LVL2,false);
                            hearts.hearts_lvl2_number--;

                            break;

                         case HEARTS_REMAINING_2:

                            HEART_2_LVL2->fn->setVisible(HEART_2_LVL2,false);
                            hearts.hearts_lvl2_number--;

                            break;

                         case HEARTS_REMAINING_1:

                            HEART_1_LVL2->fn->setVisible(HEART_1_LVL2,false);
                            hearts.hearts_lvl2_number--;

                            break;  
                            
                        case HEARTS_REMAINING_0:

                            Game_SetGameStatus(GAME_OVER);
                            
                            break;
                    }
 
                break;

            default:

                break;
        }
   
}

bool Snake_Level1RestrictionsCheck(struct Snake* c_head)
{
   if((c_head->SnakePart->fn->getX(c_head->SnakePart) < SCREEN_LEFT_LIMIT)||(c_head->SnakePart->fn->getX(c_head->SnakePart) > SCREEN_RIGHT_LIMIT) || (c_head->SnakePart->fn->getY(c_head->SnakePart) < SCREEN_UPPER_LIMIT) || (c_head->SnakePart->fn->getY(c_head->SnakePart) > SCREEN_LOWER_LIMIT))
    {
     return RESTRICTION_VIOLATED;
    }
   
   return RESTRICTION_RESPECTED;
}


bool Snake_Level2RestrictionsCheck(struct Snake* c_head)
{
  
   if((c_head->SnakePart->fn->getX(c_head->SnakePart) < SCREEN_LEFT_LIMIT)||(c_head->SnakePart->fn->getX(c_head->SnakePart) > SCREEN_RIGHT_LIMIT) || (c_head->SnakePart->fn->getY(c_head->SnakePart) < SCREEN_UPPER_LIMIT) || (c_head->SnakePart->fn->getY(c_head->SnakePart) > SCREEN_LOWER_LIMIT))
    {
     return RESTRICTION_VIOLATED;
    }
   
   //check the horizontal barriers 
    
   if((c_head->SnakePart->fn->getX(c_head->SnakePart) >= BARRIER_UPPER_LEFT_HOR_X_POS) && (c_head->SnakePart->fn->getX(c_head->SnakePart) <= (BARRIER_UPPER_LEFT_HOR_X_POS + BARRIER_SIZE)) && (c_head->SnakePart->fn->getY(c_head->SnakePart) == BARRIER_UPPER_LEFT_HOR_Y_POS))
   {
       return RESTRICTION_VIOLATED;
   }
   
   if((c_head->SnakePart->fn->getX(c_head->SnakePart) >= BARRIER_UPPER_RIGHT_HOR_X_POS) && (c_head->SnakePart->fn->getX(c_head->SnakePart) <= (BARRIER_UPPER_RIGHT_HOR_X_POS + BARRIER_SIZE)) && (c_head->SnakePart->fn->getY(c_head->SnakePart) == BARRIER_UPPER_RIGHT_HOR_Y_POS))
   {
       return RESTRICTION_VIOLATED;
   }
   
   
   if((c_head->SnakePart->fn->getX(c_head->SnakePart) >= BARRIER_LOWER_LEFT_HOR_X_POS) && (c_head->SnakePart->fn->getX(c_head->SnakePart) <= (BARRIER_LOWER_LEFT_HOR_X_POS + BARRIER_SIZE)) && (c_head->SnakePart->fn->getY(c_head->SnakePart) == BARRIER_LOWER_LEFT_HOR_Y_POS))
   {
       return RESTRICTION_VIOLATED;
   }
   
   if((c_head->SnakePart->fn->getX(c_head->SnakePart) >= BARRIER_LOWER_RIGHT_HOR_X_POS) && (c_head->SnakePart->fn->getX(c_head->SnakePart) <= (BARRIER_LOWER_RIGHT_HOR_X_POS + BARRIER_SIZE)) && (c_head->SnakePart->fn->getY(c_head->SnakePart) == BARRIER_LOWER_RIGHT_HOR_Y_POS))
   {
       return RESTRICTION_VIOLATED;
   }
   
   
    //check the vertical barriers  
 
   if((c_head->SnakePart->fn->getX(c_head->SnakePart) == BARRIER_UPPER_LEFT_VERT_X_POS) && (c_head->SnakePart->fn->getY(c_head->SnakePart) >= BARRIER_UPPER_LEFT_VERT_Y_POS) && (c_head->SnakePart->fn->getY(c_head->SnakePart) <= (BARRIER_UPPER_LEFT_VERT_Y_POS + BARRIER_SIZE)))
   {
       return RESTRICTION_VIOLATED;
   }
   
   if((c_head->SnakePart->fn->getX(c_head->SnakePart) == BARRIER_LOWER_LEFT_VERT_X_POS) && (c_head->SnakePart->fn->getY(c_head->SnakePart) >= BARRIER_LOWER_LEFT_VERT_Y_POS) && (c_head->SnakePart->fn->getY(c_head->SnakePart) <= (BARRIER_LOWER_LEFT_VERT_Y_POS + BARRIER_SIZE)))
   {
       return RESTRICTION_VIOLATED;
   }
   
   if((c_head->SnakePart->fn->getX(c_head->SnakePart) == BARRIER_UPPER_RIGHT_VERT_X_POS) && (c_head->SnakePart->fn->getY(c_head->SnakePart) >= BARRIER_UPPER_RIGHT_VERT_Y_POS) && (c_head->SnakePart->fn->getY(c_head->SnakePart) <= (BARRIER_UPPER_RIGHT_VERT_Y_POS + BARRIER_SIZE)))
   {
       return RESTRICTION_VIOLATED;
   }
   
   if((c_head->SnakePart->fn->getX(c_head->SnakePart) == BARRIER_LOWER_RIGHT_VERT_X_POS) && (c_head->SnakePart->fn->getY(c_head->SnakePart) >= BARRIER_LOWER_RIGHT_VERT_Y_POS) && (c_head->SnakePart->fn->getY(c_head->SnakePart) <= (BARRIER_LOWER_RIGHT_VERT_Y_POS + BARRIER_SIZE)))
   {
       return RESTRICTION_VIOLATED;
   }
   
   return RESTRICTION_RESPECTED;
}


bool Snake_GetInitializationStatus()
{
    return snake_initializtion_done;
}

void Snake_SetInitializationStatus(bool val)
{
   snake_initializtion_done = val;
}

uint16_t Snake_GetCurrentSize()
{
    return snake_current_size;
}

void Snake_SetCurrentSize(uint16_t val)
{
   snake_current_size = val;
}

void Snake_IncrementSize()
{
  snake_current_size++;
}


void Snake_SetInvisible()
{
    struct Snake* sn_part;
    
    sn_part = HEAD->next;
    while(sn_part != TAIL)
    {
        sn_part->SnakePart->fn->setVisible(sn_part->SnakePart,false);
        sn_part = sn_part->next;
    }
    
    FOOD->fn->setVisible(FOOD,false);
}



