/*******************************************************************************
  Start screen Source File

  Company:
    Microchip Technology Inc.

  File Name:
    start_screen.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for displaying the start-up screen.
 *******************************************************************************/
// DOM-IGNORE-BEGIN
/*
    (c) 2021 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/
// DOM-IGNORE-END
#include "start_screen.h"

uint8_t start_screen_state = START_SCREEN_INITIALIZE;

SYS_TIME_HANDLE start_screen_sys_time_handle;

bool start_screen_timer_overflow_flag;

uint8_t start_screen_logo_alpha_level = 0;

uint8_t START_SCREEN_Task()
{
    switch(start_screen_state)
    {
        case START_SCREEN_INITIALIZE:
        {
            START_SCREEN_Reset_time_elapsed_flag();
            start_screen_sys_time_handle = SYS_TIME_TimerCreate(0, SYS_TIME_MSToCount(START_SCREEN_LOGO_DISPLAY_DELAY_MS), &START_SCREEN_Sys_time_callback, (uintptr_t)NULL, SYS_TIME_PERIODIC);
            SYS_TIME_TimerStart(start_screen_sys_time_handle);
            start_screen_state = START_SCREEN_DISPLAY_LOGO;
        }

        case START_SCREEN_DISPLAY_LOGO:
        {
            if(START_SCREEN_Time_elapsed() == true)
            {
                if(START_SCREEN_Increase_alpha_level() == 255)
                {
                    START_SCREEN_Reset_time_elapsed_flag();
                    SYS_TIME_TimerStop(start_screen_sys_time_handle);
                    SYS_TIME_TimerDestroy(start_screen_sys_time_handle);
                    start_screen_sys_time_handle = SYS_TIME_TimerCreate(0, SYS_TIME_MSToCount(START_SCREEN_WAIT_DELAY), &START_SCREEN_Sys_time_callback, (uintptr_t)NULL, SYS_TIME_SINGLE);
                    SYS_TIME_TimerStart(start_screen_sys_time_handle);
                    start_screen_state = START_SCREEN_WAIT;
                }

                START_SCREEN_Reset_time_elapsed_flag();
            }

            break;
        }

        case START_SCREEN_WAIT:
        {
            if(START_SCREEN_Time_elapsed() == true)
            {
                start_screen_state = START_SCREEN_SWITCH_SCREENS;
            }

            break;
        }

        case START_SCREEN_SWITCH_SCREENS:
        {
            legato_showScreen(GRID_EYE_SCREEN_ID);
            start_screen_state = START_SCREEN_TASK_DONE;
            break;
        }

        case START_SCREEN_TASK_DONE:
        {

            break;
        }

        default:
        {
            break;
        }
    }

    return start_screen_state;
}

bool START_SCREEN_Time_elapsed()
{
    return start_screen_timer_overflow_flag;
}

void START_SCREEN_Reset_time_elapsed_flag()
{
    start_screen_timer_overflow_flag = false;
}


void START_SCREEN_Sys_time_callback(uintptr_t context)
{
    start_screen_timer_overflow_flag = true;

}

uint8_t START_SCREEN_Increase_alpha_level()
{
   uint8_t alpha_level;

   alpha_level = START_SCREEN_LOGO_IMAGE_WIDGET->fn->getAlphaAmount(START_SCREEN_LOGO_IMAGE_WIDGET);

   alpha_level = alpha_level + 17;

   START_SCREEN_LOGO_IMAGE_WIDGET->fn->setAlphaAmount(START_SCREEN_LOGO_IMAGE_WIDGET,alpha_level);

   return alpha_level;
}

