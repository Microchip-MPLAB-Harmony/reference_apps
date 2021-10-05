/*******************************************************************************
  Led control

  Company:
    Microchip Technology Inc.

  File Name:
    led.c

  Summary:

  Description:
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
#include <stdbool.h>
#include "led.h"
#include "click_routines/leddriver3/leddriver3.h"

#define LEDS_TEST_INTERVAL	50L
#define LED_ON_INTERVAL     200L
#define LEDS_HOLD_INTERVAL	2000L

static bool ledForDefaultCredentials = false;
static bool ledHeld = false;

void LED_MSDelay(uint32_t ms);

void yellow_task(void);
void red_task(void);
void defaultCredentials_task(void);
void softAp_task(void);

SYS_TIME_HANDLE yellow_taskHandle   = SYS_TIME_HANDLE_INVALID;
SYS_TIME_HANDLE red_taskHandle      = SYS_TIME_HANDLE_INVALID;
SYS_TIME_HANDLE softAp_taskHandle   = SYS_TIME_HANDLE_INVALID;
SYS_TIME_HANDLE defaultCredentials_taskHandle = SYS_TIME_HANDLE_INVALID;

volatile bool yellow_taskTmrExpired     = false;
volatile bool red_taskTmrExpired        = false;
volatile bool softAp_taskTmrExpired     = false;
volatile bool defaultCredentials_taskTmrExpired = false;

void yellow_taskcb(uintptr_t context)
{
    yellow_taskTmrExpired = true;
}
void red_taskcb(uintptr_t context)
{
    red_taskTmrExpired = true;
}
void defaultCredentials_taskcb(uintptr_t context)
{
    defaultCredentials_taskTmrExpired = true;
}
void softAp_taskcb(uintptr_t context)
{
    softAp_taskTmrExpired = true;
}

void yellow_task(void)
{
    led_driver3_set_color(  LED_DRIVER_3_COLOR_OFF );
   ledHeld = false;
}

void red_task(void)
{
    led_driver3_set_color(  LED_DRIVER_3_COLOR_OFF ); 
}

void softAp_task(void)
{
    LED_BLUE_Toggle();
}

void defaultCredentials_task(void)
{
    LED_GREEN_Toggle();
}

void LED_flashYellow(void)
{
    if (ledHeld == false)
    {
        led_driver3_set_color(  LED_DRIVER_3_COLOR_YELLOW );
        yellow_taskHandle = SYS_TIME_CallbackRegisterMS(yellow_taskcb, 0, 200, SYS_TIME_SINGLE);
    }

}

void LED_holdYellowOn(bool holdHigh)
{
    if (holdHigh == true)
    {
        led_driver3_set_color(  LED_DRIVER_3_COLOR_YELLOW );
    }
    else
    {
        led_driver3_set_color(  LED_DRIVER_3_COLOR_OFF );
    }
    // Re-Use yellow_timer task
    ledHeld = true;
    yellow_taskHandle = SYS_TIME_CallbackRegisterMS(yellow_taskcb, 0, LEDS_HOLD_INTERVAL, SYS_TIME_SINGLE);
}

void LED_flashRed(void)
{
   led_driver3_set_color(  LED_DRIVER_3_COLOR_OFF ); 
   red_taskHandle = SYS_TIME_CallbackRegisterMS(red_taskcb, 0, LED_ON_INTERVAL, SYS_TIME_SINGLE);
}

void LED_blinkingBlue(bool amBlinking)
{
    if (amBlinking == true)
    {
        softAp_taskHandle = SYS_TIME_CallbackRegisterMS(softAp_taskcb, 0, LED_ON_INTERVAL, SYS_TIME_PERIODIC);
    }
    else
    {
        SYS_TIME_TimerStop(softAp_taskHandle);
    }
}

void LED_startBlinkingGreen(void)
{
    defaultCredentials_taskHandle = SYS_TIME_CallbackRegisterMS(defaultCredentials_taskcb, 0, LED_ON_INTERVAL, SYS_TIME_PERIODIC);
    ledForDefaultCredentials = true;
}

void LED_stopBlinkingGreen(void)
{
    if (ledForDefaultCredentials == true)
    {
        SYS_TIME_TimerStop(defaultCredentials_taskHandle);
        ledForDefaultCredentials = false;
    }
}

bool LED_isBlinkingGreen (void)
{
    return ledForDefaultCredentials;
}

void LED_MSDelay(uint32_t ms)
{
    SYS_TIME_HANDLE tmrHandle = SYS_TIME_HANDLE_INVALID;

    if (SYS_TIME_SUCCESS != SYS_TIME_DelayMS(ms, &tmrHandle))
    {
        return;
    }

    while (true != SYS_TIME_DelayIsComplete(tmrHandle))
    {
    }
}

void LED_sched(void)
{
    if(yellow_taskTmrExpired == true) {
       yellow_taskTmrExpired = false;
       yellow_task();
    }
    if(red_taskTmrExpired == true) {
        red_taskTmrExpired = false; 
        red_task();
    }
    if(softAp_taskTmrExpired == true) {
        softAp_taskTmrExpired = false; 
        softAp_task();
    }
    if(defaultCredentials_taskTmrExpired == true) {
        defaultCredentials_taskTmrExpired = false; 
        defaultCredentials_task();
    }        
}