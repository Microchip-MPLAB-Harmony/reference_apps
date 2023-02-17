/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    Snake.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the Snake game application.
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

#ifndef SNAKE_H
#define	SNAKE_H

#ifdef	__cplusplus
extern "C" {
#endif

//#include "gfx/legato/generated/screen/le_gen_screen_Game_Level1.h"
//#include "gfx/legato/generated/screen/le_gen_screen_Menu.h"  
#include "Game.h"
#include <xc.h>
#include "app.h"

    
#define SNAKE_INITIAL_POSITION_X 400
#define SNAKE_INITIAL_POSITION_Y 240
#define SNAKE_MAX_SIZE           8
#define SNAKE_INITIAL_SIZE       1    
#define SNAKE_STEP_SIZE          10
#define SNAKE_PART_SIZE          20
    
#define SNAKE_COLOR_RED          0xE124
#define SNAKE_COLOR_BLUE         0x215C
#define SNAKE_COLOR_GREEN        0x2709
#define SNAKE_COLOR_YELLOW       0xDF04
#define SNAKE_COLOR_ORANGE       0xE344
#define SNAKE_COLOR_PURPLE       0xA13C
    
#define RESTRICTION_RESPECTED    1
#define RESTRICTION_VIOLATED     0


#define FOOD    FOOD_RectangleWidget
#define FOOD_INITIAL_X_POSITION  550
 
    
#define SNAKE_SCHEME SnakePart_sheme

    
//positions for horizontal barriers
#define BARRIER_UPPER_LEFT_HOR_X_POS     140
#define BARRIER_UPPER_LEFT_HOR_Y_POS     140    
    
   
#define BARRIER_UPPER_RIGHT_HOR_X_POS    440
#define BARRIER_UPPER_RIGHT_HOR_Y_POS    140    
    

#define BARRIER_LOWER_LEFT_HOR_X_POS     140
#define BARRIER_LOWER_LEFT_HOR_Y_POS     420
     
    
#define BARRIER_LOWER_RIGHT_HOR_X_POS    440
#define BARRIER_LOWER_RIGHT_HOR_Y_POS    420   
    
    
//positions for vertical barriers   
#define BARRIER_UPPER_LEFT_VERT_X_POS    140    
#define BARRIER_UPPER_LEFT_VERT_Y_POS    160
    
    
#define BARRIER_LOWER_LEFT_VERT_X_POS    140
#define BARRIER_LOWER_LEFT_VERT_Y_POS    320
    
    
#define BARRIER_LOWER_RIGHT_VERT_X_POS   520
#define BARRIER_LOWER_RIGHT_VERT_Y_POS   320
    
    
#define BARRIER_UPPER_RIGHT_VERT_X_POS   520
#define BARRIER_UPPER_RIGHT_VERT_Y_POS   160    
    
    
#define BARRIER_SIZE                      80
    
extern leRectangleWidget* FOOD_RectangleWidget;      

extern uint16_t snake_current_size;

extern bool snake_initializtion_done;


//create the stucture for a double-chained list
struct Snake
{
   leRectangleWidget*   SnakePart;
   struct Snake*        next;
   struct Snake*        previous;
   leScheme             SnakePart_scheme;
  
};

//define the pointers to the Snake structure HEAD = head of the list, TAIL = bottom of the list; part = the reference that will be pars the list; CurrentHead = the current head of the snake
extern struct Snake* HEAD;

extern struct Snake* TAIL;

extern struct Snake* part;

extern struct Snake* CurrentHead;

/*******************************************************************************
 Function:
    void Snake_Init();

  Summary:
    Snake initialization routine.

  Description:
    This function initializes and create the snake.

  Precondition:
   

  Parameters:
    None.

  Returns:
    None.


  Remarks:
    
*/

void Snake_Init();


/*******************************************************************************
 Function:
    void Snake_Task();

  Summary:
    Snake task routine.

  Description:
    This function contains the state machine for the snake.

  Precondition:
    The ("Snake_Init") function should be called before calling this function.
   

  Parameters:
    None.

  Returns:
    None.


  Remarks:
    
*/

void Snake_Task();


/*******************************************************************************
 Function:
    void Snake_AddAtHead(leWidget* c_root);

  Summary:
    The routine that adds a new element at the beginning of the list that represent the snake.

  Description:
    This function add a new rectangle widget at the start of the list that represent the snake. This functions
 shouldn't be called by the user as it is used by the ("Snake_Init") function.

  Precondition:
    
   
  Parameters:
    
   c_root - a pointer to the root widget of the current active screen.

  Returns:
    None.


  Remarks:
    
*/

void Snake_AddAtHead(leWidget* c_root);


/*******************************************************************************
 Function:
    void Snake_AddAtTail(leWidget* c_root);

  Summary:
    The routine that adds a new element at the end of the list that represent the snake.

  Description:
    This function add a new rectangle widget at the start of the list that represent the snake. This functions
 shouldn't be called by the user as it is used by the ("Snake_Init") function.

  Precondition:
    
   
  Parameters:
    
   c_root - a pointer to the root widget of the current active screen.

  Returns:
    None.


  Remarks:
    
*/

void Snake_AddAtTail(leWidget* c_root);


/*******************************************************************************
 Function:
    void Snake_DirectionTask(uint16_t Current_Head_X, uint16_t Current_Head_Y);

  Summary:
    Snake direction task routine.

  Description:
    This function contains the state machine for the snake direction. This function 
 shouldn't be used by the user as it is used by the ("Snake_Task") routine.

  Precondition:
    

  Parameters:
    
   Current_Head_X - the X coordinate of the head of the snake
 
   Current_Head_Y - the Y coordinate of the head of the snake

  Returns:
    None.


  Remarks:
    
*/

void Snake_DirectionTask(uint16_t Current_Head_X, uint16_t Current_Head_Y);


/*******************************************************************************
 Function:
    void Snake_EatingTask();

  Summary:
    Snake task routine for eating.

  Description:
    This function contains the state machine for the snake eating functionality. This function 
 shouldn't be used by the user as it is used by the ("Snake_Task") routine.

  Precondition:
    

  Parameters:
    

  Returns:
    None.


  Remarks:
    
*/

void Snake_EatingTask();

/*******************************************************************************
 Function:
    void Snake_RandomColorSet(struct Snake* sn_part);

  Summary:
   The routine for coloring a specific part of the snake with a radom color.

  Description:
    This function set the color of a specific part of the snake using a radom color.

  Precondition:
    

  Parameters:
    
   sn_part - pointer to the Snake structure that represent a snake part
  
  Returns:
    None.


  Remarks:
    
*/

void Snake_RandomColorSet(struct Snake* sn_part);


/*******************************************************************************
 Function:
    leRectangleWidget* Snake_CreateSnakePart();

  Summary:
   The routine that create a new snake part.

  Description:
    This function create a new rectangle widget that represent a snake part.

  Precondition:
    

  Parameters:
    None.
  
  Returns: 
 
    A pointer to the newly created snake part.


  Remarks:
    None.
*/

leRectangleWidget* Snake_CreateSnakePart();


/*******************************************************************************
 Function:
    void Snake_FoodRespawn();

  Summary:
   The routine that respawn the food.

  Description:
    This function will move the food to another random location to the screen.

  Precondition:
    

  Parameters:
    None.
  
  Returns: 
    None.


  Remarks:
    None.
*/

void Snake_FoodRespawn();


/*******************************************************************************
 Function:
    void Snake_FoodInit(leWidget* c_root);

  Summary:
   The routine that initialize the food.

  Description:
    This function will create a rectangle widget that represents the food.

  Precondition:
    

  Parameters:
    
    c_root - a pointer to the root widget of the current active screen. 
  
  Returns: 
    None.


  Remarks:
    None.
*/

void Snake_FoodInit(leWidget* c_root);


/*******************************************************************************
 Function:
    void Snake_Destroy();

  Summary:
   The routine that destroy the snake.

  Description:
    This function will destroy the snake along with the food.

  Precondition:
    

  Parameters:
    None.
  
  Returns: 
    None.


  Remarks:
    None.
*/

void Snake_Destroy();
    

/*******************************************************************************
 Function:
    bool Snake_CheckRestictions(struct Snake* c_head);

  Summary:
   The routine that check restrictions for the snake.

  Description:
    This function will check if the snake have crossed a barrier or the edges of the screen.

  Precondition:
    

  Parameters:
    
    c_head - pointer to the head of the snake 
  
  Returns: 
    
     RESTRICTION_VIOLATED  - the snake has crossed a barrier or one of the screen edges.

     RESTRICTION_RESPECTED - the snake has respected the restrictions.

  Remarks:
    None.
*/

bool Snake_CheckRestictions(struct Snake* c_head);


/*******************************************************************************
 Function:
    void Snake_HeartsTask();

  Summary:
   The routine contain the state machine for the heart icons.

  Description:
    This function will maintain the state machine for the heart icons.

  Precondition:
    

  Parameters:
    None. 
  
  Returns: 
    None.

  Remarks:
    None.
*/

void Snake_HeartsTask();


/*******************************************************************************
 Function:
    bool Snake_Level1RestrictionsCheck(struct Snake* c_head);

  Summary:
   The routine that will check the restriction for the Level 1 stage.

  Description:
    This function will check the restriction for the Level 1 stage. The restriction for the snake is to not cross the screen edge.

  Precondition:
    

  Parameters:
    
    c_head - pointer to the head of the snake  
  
  Returns: 
    
   RESTRICTION_VIOLATED  - the snake has crossed one of the screen edges.

   RESTRICTION_RESPECTED - the snake has respected the restriction.

  Remarks:
    None.
*/

bool Snake_Level1RestrictionsCheck(struct Snake* c_head);



/*******************************************************************************
 Function:
    bool Snake_Level2RestrictionsCheck(struct Snake* c_head);

  Summary:
   The routine that will check the restriction for the Level 2 stage.

  Description:
    This function will check the restriction for the Level 2 stage. The restriction for the snake is to not cross a barrier or one of the screen edges.

  Precondition:
    

  Parameters:
    
    c_head - pointer to the head of the snake  
  
  Returns: 
    
   RESTRICTION_VIOLATED  - the snake has crossed a barrier or one of the screen edges.

   RESTRICTION_RESPECTED - the snake has respected the restrictions.

  Remarks:
    None.
*/

bool Snake_Level2RestrictionsCheck(struct Snake* c_head);



/*******************************************************************************
 Function:
    bool Snake_GetInitializationStatus();

  Summary:
    The routine that will get the initialization status of the snake.

  Description:
    This function will return the initialization status of the snake.

  Precondition:
    

  Parameters:
    None. 
  
  Returns: 
    
    true  - the snake is initialized.
    
  
    false - the snake is not initialized

  Remarks:
    None.
*/

bool Snake_GetInitializationStatus();


/*******************************************************************************
 Function:
    void Snake_SetInitializationStatus(bool val);

  Summary:
    The routine that will set the initialization status of the snake.

  Description:
    This function will set the initialization status of the snake.

  Precondition:
    

  Parameters:
 
    true  - set the state status as initialized
    
    false - set the state status as uninitialized
  
  Returns: 
    
    

  Remarks:
    None.
*/

void Snake_SetInitializationStatus(bool val);


/*******************************************************************************
 Function:
    uint16_t Snake_GetCurrentSize();

  Summary:
    The routine will get the Snake current size

  Description:
    This function will return the Snake current size

  Precondition:
    

  Parameters:
 
    None.
  
  Returns: 
    
    A unit8_t value that represents the snake current size

  Remarks:
    None.
*/

uint16_t Snake_GetCurrentSize();


/*******************************************************************************
 Function:
    void Snake_SetCurrentSize(uint16_t val);
val
  Summary:
    The routine will set the Snake size variable.

  Description:
    This function will set a variable that will contain the snake current size. The value can be read by using theSnake_GetCurrentSize(). 
 It doesn't actually set the size of the snake.
 
  Precondition:
    

  Parameters:
 
    val - a uint16_t variable that represents the snake size
  
  Returns: 
    
    None.

  Remarks:
    None.
*/

void Snake_SetCurrentSize(uint16_t val);


/*******************************************************************************
 Function:
    void Snake_IncrementSize();

  Summary:
    The routine will increment the size variable of the snake

  Description:
    The routine will increment the size variable of the snake

  Precondition:
    

  Parameters:
 
    None.
  
  Returns: 
    
    None.

  Remarks:
    None.
*/

void Snake_IncrementSize();


/*******************************************************************************
 Function:
    void Snake_SetInvisible();

  Summary:
    The routine will make the snake invisible.

  Description:
    The routine will make the snake invisible.

  Precondition:
    

  Parameters:
 
    None.
  
  Returns: 
    
    None.

  Remarks:
    None.
*/

void Snake_SetInvisible();
    
#ifdef	__cplusplus
}
#endif

#endif	/* SNAKE_H */

