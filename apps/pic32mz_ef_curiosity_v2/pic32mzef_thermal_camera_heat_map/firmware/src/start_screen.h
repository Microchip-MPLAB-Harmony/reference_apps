/*******************************************************************************
  Start screen Header File

  Company:
    Microchip Technology Inc.

  File Name:
    start_screen.h

  Summary:
    This header file provides prototypes and definitions for start_screen.

  Description:
    This header file provides function prototypes and data type definitions for
    the start_screen.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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
//DOM-IGNORE-END

#ifndef START_SCREEN_H
#define START_SCREEN_H

#ifdef  __cplusplus
extern "C" {
#endif

#include "config/default/definitions.h"

#define START_SCREEN_LOGO_DISPLAY_DELAY_MS                   100
#define START_SCREEN_WAIT_DELAY                             2000

#define GRID_EYE_SCREEN_ID                      screenID_Screen0

#define START_SCREEN_LOGO_IMAGE_WIDGET Start_screen_ImageWidget0


typedef enum
{
    START_SCREEN_INITIALIZE = 0,
    START_SCREEN_DISPLAY_LOGO,
    START_SCREEN_WAIT,
    START_SCREEN_SWITCH_SCREENS,
    START_SCREEN_TASK_DONE,
}START_SCREEN_STATES;

/* Function:
    uint8_t START_SCREEN_Task();

  Summary:
    The task function for displaying the start-up screen.

  Description:
    The task function for displaying the start-up screen.

  Precondition:
  The SYS_Initialize() function needs to be called once and SYS_Tasks() needs to be called periodically.

  Parameters:
   None.


  Returns:
    - START_SCREEN_INITIALIZE
    - START_SCREEN_DISPLAY_LOGO
    - START_SCREEN_WAIT
    - START_SCREEN_SWITCH_SCREENS
    - START_SCREEN_TASK_DONE

  Example:


  Remarks:

*/

uint8_t START_SCREEN_Task();

/* Function:
    bool START_SCREEN_Time_elapsed();

  Summary:
    Function that indicate if the time has elapsed for the created timer object.

  Description:
    Function that indicate if the time has elapsed for the created timer object.

  Precondition:
  The SYS_Initialize() function needs to be called once and SYS_Tasks() needs to be called periodically.

  Parameters:
   None.

  Returns:
   true - if the time has elapsed
   false - if the time has not elapsed

  Example:


  Remarks:

*/

bool START_SCREEN_Time_elapsed();

/* Function:
    void START_SCREEN_Reset_time_elapsed_flag();

  Summary:
    Function that resets the variable that is used for marking that the time has elapsed.

  Description:
    Function that resets the variable that is used for marking that the time has elapsed.

  Precondition:
  The SYS_Initialize() function needs to be called once and SYS_Tasks() needs to be called periodically.

  Parameters:
   None.

  Returns:
   None.

  Example:


  Remarks:

*/

void START_SCREEN_Reset_time_elapsed_flag();

/* Function:
    void START_SCREEN_Sys_time_callback(uintptr_t context);

  Summary:
    Timer callback used for the START_SCREEN_Task().

  Description:
    Timer callback used for the START_SCREEN_Task().

  Precondition:
  The SYS_Initialize() function needs to be called once and SYS_Tasks() needs to be called periodically.

  Parameters:
    context - not used in this application

  Returns:
   None.

  Example:


  Remarks:

*/

void START_SCREEN_Sys_time_callback(uintptr_t context);

/* Function:
    uint8_t START_SCREEN_Increase_alpha_level();

  Summary:
    Function that increase the alpha level of the start-up screen image.

  Description:
    Function that increase the alpha level of the start-up screen image.

  Precondition:
  The SYS_Initialize() function needs to be called once and SYS_Tasks() needs to be called periodically.

  Parameters:
    None.

  Returns:
   The alpha level value after it was increased.

  Example:


  Remarks:

*/

uint8_t START_SCREEN_Increase_alpha_level();


#ifdef  __cplusplus
}
#endif

#endif  /* START_SCREEN_H */

