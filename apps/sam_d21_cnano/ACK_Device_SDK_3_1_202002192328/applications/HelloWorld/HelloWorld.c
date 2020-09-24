/*
 * Copyright 2018-2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

/*
    Note: this application is a sample only. It may omit functionality that would be required in a
    real device. The application’s source code is structured to maximize illustrative utility, and not
    to suggest a reference design for any category of device or to provide a definitive framework for
    a device’s firmware.
*/

/*
    Models a simple smart plug, which has the following hardware:
    * A button for local control of the plug. Pressing and releasing toggles the plug power.
    * A button for user-initiated ACK lifecycle actions -- factory reset and entering user-guided setup.
      If pressed for less than 20 seconds and then released, enters user-guided setup. If pressed for
      20 seconds or more, initiates factory reset.
    * The plug itself.
    * An LED to indicate connectivity state.
 
    The plug responds to Alexa.PowerController directives to turn the power on/off.
*/

#include "ack_user_platform.h" // Just to get ACKPlatform_TickCount.
#include "HelloWorld_Alexa.h"
#include "HelloWorld_Hardware.h"
#include <stdint.h>

typedef enum _PowerButtonAction
{
    POWER_BUTTON_ACTION_NONE,
    POWER_BUTTON_ACTION_RELEASED
}
PowerButtonAction;

// Represents actions performed on the lifecycle button.
typedef enum _LifecycleLifecycleButtonAction
{
    LIFECYCLE_BUTTON_ACTION_NONE,
    LIFECYCLE_BUTTON_ACTION_RELEASED,
    LIFECYCLE_BUTTON_ACTION_LONG_PRESSED
}
LifecycleButtonAction;

static PowerButtonAction GetPowerButtonAction(void);
static LifecycleButtonAction GetLifecycleButtonAction(void);

// Duration in milliseconds that the lifecycle button has to be pressed to register as a long-press.
// Used to initiate factory reset.
#define LONG_PRESS_DURATION_MILLISECONDS (20 * 1000)

// Application setup. Called once.
void setup(void)
{
    // Initialize ACK functionality.
    Alexa_Setup();
}

// Application main loop. Called repeatedly.
void loop(void)
{
    PowerButtonAction powerButtonAction;
    LifecycleButtonAction lifecycleButtonAction;
    
    powerButtonAction = GetPowerButtonAction();
    if (POWER_BUTTON_ACTION_RELEASED == powerButtonAction)
    {
        // Toggle power state, and tell Alexa about the state change.
        Hardware_SetPowerState(!Hardware_IsPowerOn());
        Alexa_SendChangeReportDueToLocalControl();
    }

    lifecycleButtonAction = GetLifecycleButtonAction();
    if (LIFECYCLE_BUTTON_ACTION_LONG_PRESSED == lifecycleButtonAction)
    {
        // This call returns, but when Alexa_Loop is called below, factory reset will be initiated.
        Alexa_InitiateFactoryReset();
    }
    else if (LIFECYCLE_BUTTON_ACTION_RELEASED == lifecycleButtonAction)
    {
        // This call returns, but when Alexa_Loop is called below, user-guided setup will be entered.
        Alexa_InitiateUserGuidedSetup();
    }

    // ACK processing.
    Alexa_Loop();
}

static PowerButtonAction GetPowerButtonAction(void)
{
    static bool s_wasButtonPressed = false;
    bool isButtonPressed;
    PowerButtonAction action = POWER_BUTTON_ACTION_NONE;

    isButtonPressed = Hardware_IsPowerToggleButtonDown();
    if (s_wasButtonPressed && !isButtonPressed)
    {
        action = POWER_BUTTON_ACTION_RELEASED;
    }

    s_wasButtonPressed = isButtonPressed;
    return action;
}

static LifecycleButtonAction GetLifecycleButtonAction(void)
{   
    static bool s_wasButtonPressed = false;
    static uint32_t s_wasButtonPressedTick = 0;
    bool isButtonPressed;
    uint32_t now;

    isButtonPressed = Hardware_IsLifecycleButtonDown();
    now = ACKPlatform_TickCount();

    if (isButtonPressed)
    {
        if (s_wasButtonPressed)
        {
            // Button was already pressed, and continues to be pressed. This is either a long-press,
            // or a no-op.
            if ((now - s_wasButtonPressedTick) >= LONG_PRESS_DURATION_MILLISECONDS)
            {
                // Behave as if the button was released.
                s_wasButtonPressed = false;
                return LIFECYCLE_BUTTON_ACTION_LONG_PRESSED;
            }

            return LIFECYCLE_BUTTON_ACTION_NONE;
        }

        // Button transitioned from released to pressed.
        s_wasButtonPressedTick = ACKPlatform_TickCount();
        s_wasButtonPressed = true;
        return LIFECYCLE_BUTTON_ACTION_NONE;
    }

    if (s_wasButtonPressed)
    {
        // Button transitioned from pressed to released.
        s_wasButtonPressed = false;
        return LIFECYCLE_BUTTON_ACTION_RELEASED;
    }

    // Button wasn't pressed and still isn't.
    return LIFECYCLE_BUTTON_ACTION_NONE;
}
