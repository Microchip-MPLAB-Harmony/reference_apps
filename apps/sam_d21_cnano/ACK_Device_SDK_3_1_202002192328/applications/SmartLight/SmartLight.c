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
 *   ACK Host MCU sample application showing implementation of a Smart Light.
 *   The usage of the following capabilities is demonstrated:
 *    * Power - powers the light on/off.
 *    * Brightness - controls the brightness of the LED using PWM output.
 *    * Mode (Shutoff time) - shuts the light of after the specified time.
 *    * Mode (Blinking Speed) - sets the light blinking speed.
*/

#include "ack.h"
#include "ack_brightness_controller.h"
#include "ack_user_device.h"
#include "ack_logging.h"
#include "ack_mode_controller.h"
#include "ack_power_controller.h"
#include <inttypes.h>
#include <stdint.h>

// Component name used for logs originated from this file.
#define LOG_COMPONENT_NAME "SmartLightApplication"

// Forward declarations.
bool AddPowerProperty(uint32_t propertyOrdinal, unsigned propertyFlags);
bool AddLightBrightnessProperty(uint32_t propertyOrdinal, unsigned propertyFlags);
bool AddLightTimerProperty(uint32_t propertyOrdinal, unsigned propertyFlags);
bool AddLightBlinkingProperty(uint32_t propertyOrdinal, unsigned propertyFlags);
ACKPropertiesBits_t ResetBlinkingMode(void);
ACKPropertiesBits_t ResetShutdownTimeMode(void);
void ProcessSetSpeedModeDirective(int32_t correlationId, bool isDelta, int32_t value);
void ProcessSetTimerModeDirective(int32_t correlationId, bool isDelta, int32_t value);
ACKPropertiesBits_t SetLightToOnIfOff(void);
void CheckShutoffTimer(void);
void CheckBlinkingMode(void);
void Hardware_TurnLightOn(void);
void Hardware_TurnLightOff(void);

// Application-specific property ordinals.
#define PROPERTY_POWER_STATE 0 // Power controller ordinal.
#define PROPERTY_BRIGHTNESS 1  // Brightness controller ordinal.
#define PROPERTY_TIMER_MODE 2  // Timer (mode) controller ordinal.
#define PROPERTY_SPEED_MODE 3  // Blinking (mode) controller ordinal.

// Maps an Alexa capability in this application to a routine used to add the capability's properties
// when an outbound event is being built.
ACKPropertyTableEntry_t ACKUser_PropertyTable[] =
{
    { PROPERTY_POWER_STATE, AddPowerProperty },
    { PROPERTY_BRIGHTNESS, AddLightBrightnessProperty },
    { PROPERTY_TIMER_MODE, AddLightTimerProperty },
    { PROPERTY_SPEED_MODE, AddLightBlinkingProperty },
    { 0, NULL }
};

// All Light related properties.
static const ACKPropertiesBits_t c_lightPropertiesBits =
    ACK_PROPERTY_BIT(PROPERTY_POWER_STATE)
    | ACK_PROPERTY_BIT(PROPERTY_BRIGHTNESS)
    | ACK_PROPERTY_BIT(PROPERTY_TIMER_MODE)
    | ACK_PROPERTY_BIT(PROPERTY_SPEED_MODE);

// Mode controller instance ids.
// When multiple mode controllers are registered, each is assigned with a unique instance id.
// DO NOT CHANGE the instance ids, since they must match the device type configuration.
#define MODE_INSTANCE_TIMER 12
#define MODE_INSTANCE_BLINKING 13

// Timer modes.
// Same as with the instance ids, these values must match the device type configuration.
#define TIMER_MODE_NONE 0
#define TIMER_MODE_5_MIN 1
#define TIMER_MODE_10_MIN 2
#define TIMER_MODE_60_MIN 3

// Blinking modes.
// Same as with the instance ids, these values must match the device type configuration.
#define SPEED_MODE_NONE 0
#define SPEED_MODE_LOW 1
#define SPEED_MODE_MEDIUM 2
#define SPEED_MODE_HIGH 3

#define MAXIMUM_BRIGHTNESS 100
#define MINIMUM_BRIGHTNESS 0

// Global variables.
uint32_t g_previousTick = 0;   // Previous Tick (used by timers logic).
uint8_t g_brightness = MAXIMUM_BRIGHTNESS; // Brightness.
uint8_t g_blinkingMode = SPEED_MODE_NONE;    // Blinking mode.
uint8_t g_timerMode = TIMER_MODE_NONE;   // Timer mode.
bool g_power = false;           // Light power.
int32_t g_timerModeCountdown = 0;  // Timer countdown.
int32_t g_blinkingCountdown = 0; // Blinking countdown.
bool g_blinkingPower = false;     // Indicates power for blinking mode.

// Called once, for one-time initialization.
void setup()
{
    // Initialize ACK Host MCU Implementation Core.
    ACK_Initialize();

    // Initialize the previous tick.
    g_previousTick = ACKPlatform_TickCount();
}

// Called over and over, for main processing.
void loop()
{
    ACK_Process();

    // Timers are checked every loop iteration.
    CheckShutoffTimer();
    CheckBlinkingMode();

    // In order to work with timers, we save time of the last time timers were called.
    // This line must be after all timer logic is called.
    g_previousTick = ACKPlatform_TickCount();
}

// We designate the device "in use" if (simulated) power is on.
bool ACKUser_IsDeviceInUse(void)
{
    return g_power;
}

// Power Controller directive callback, turns on a small LED.
void ACKUser_OnPowerControllerDirective(int32_t correlationId, bool powerOn)
{
    ACKPropertiesBits_t changedPropertiesBits = 0;
    bool changed;

#ifdef ACK_LOGGING
    ACK_WriteLogFormatted(
        acp_log_level_info,
        LOG_COMPONENT_NAME,
        "Handling power directive: %s",
        powerOn ? "ON" : "OFF");
#endif

    ACK_DEBUG_PRINT_I("Controlling LED with power controller directive; light %s", powerOn ? "ON" : "OFF");

    changed = (0 == g_power) != (0 == powerOn);
    if (changed)
    {
        // In case of power mode change, the logic stops blinking and the timer is stopped.
        changedPropertiesBits |= ResetShutdownTimeMode();
        changedPropertiesBits |= ResetBlinkingMode();
        changedPropertiesBits |= ACK_PROPERTY_BIT(PROPERTY_POWER_STATE);
        if (powerOn)
        {
            Hardware_TurnLightOn();
            g_power = true;
        }
        else
        {
            Hardware_TurnLightOff();
            g_power = false;
        }
    }

    // Indicate that processing the directive completed successfully,
    // including a change report if and only if the power state actually changed.
    ACK_CompleteDirectiveWithSuccess(
        correlationId,
        c_lightPropertiesBits,
        changedPropertiesBits);
}


ACKPropertiesBits_t ResetShutdownTimeMode(void)
{
    if (g_timerMode != TIMER_MODE_NONE)
    {
        g_timerMode = TIMER_MODE_NONE;
        return ACK_PROPERTY_BIT(PROPERTY_TIMER_MODE);
    }

    return 0;
}

ACKPropertiesBits_t ResetBlinkingMode(void)
{
    if (g_blinkingMode != SPEED_MODE_NONE)
    {
        g_blinkingMode = SPEED_MODE_NONE;
        g_blinkingCountdown = 0;
        return ACK_PROPERTY_BIT(PROPERTY_SPEED_MODE);
    }

    return 0;
}

void ACKUser_OnBrightnessControllerDirective(int32_t correlationId, bool isDelta, int32_t value)
{
    ACKPropertiesBits_t changedPropertiesBits = 0;

#ifdef ACK_LOGGING
    ACK_WriteLogFormatted(
        acp_log_level_info,
        LOG_COMPONENT_NAME,
        "Handling Set Brightness directive: %d %"PRIi32,
        isDelta,
        value);
#endif

    // isDelta means that user asked to increase or decrease the brightness.
    if (isDelta)
    {
        if (g_brightness + value > MAXIMUM_BRIGHTNESS)
        {
            if (g_brightness != MAXIMUM_BRIGHTNESS)
            {
                g_brightness = MAXIMUM_BRIGHTNESS;
                changedPropertiesBits |= ACK_PROPERTY_BIT(PROPERTY_BRIGHTNESS);
            }
        }
        else if (g_brightness + value < MINIMUM_BRIGHTNESS)
        {
            if (g_brightness != MINIMUM_BRIGHTNESS)
            {
                g_brightness = MINIMUM_BRIGHTNESS;
                changedPropertiesBits |= ACK_PROPERTY_BIT(PROPERTY_BRIGHTNESS);
            }
        }
        else
        {
            g_brightness += value;
            changedPropertiesBits |= ACK_PROPERTY_BIT(PROPERTY_BRIGHTNESS);
        }
    }
    else
    {
        if ((value > MAXIMUM_BRIGHTNESS) || (value < MINIMUM_BRIGHTNESS))
        {
            ACK_CompleteDirectiveWithOutOfRangeError(
                correlationId,
                MINIMUM_BRIGHTNESS,
                MAXIMUM_BRIGHTNESS,
                NULL);

            return;
        }

        if (g_brightness != value)
        {
            g_brightness = value;
            changedPropertiesBits |= ACK_PROPERTY_BIT(PROPERTY_BRIGHTNESS);
        }
    }

    if (changedPropertiesBits)
    {
        // If power was off, turn it on.
        if (!g_power)
        {
            g_power = true;
            changedPropertiesBits |= ACK_PROPERTY_BIT(PROPERTY_POWER_STATE);
        }

        Hardware_TurnLightOn();
    }


    // Indicate that processing the directive completed successfully,
    // including a change report if and only if the brightness state actually changed.
    ACK_CompleteDirectiveWithSuccess(
        correlationId,
        c_lightPropertiesBits,
        changedPropertiesBits);
}

ACKPropertiesBits_t SetLightToOnIfOff(void)
{
    if (!g_power)
    {
        g_power = true;
        Hardware_TurnLightOn();
        return ACK_PROPERTY_BIT(PROPERTY_POWER_STATE);
    }

    return 0;
}

// Example: Mode Controller.
// In this example two instances are supported:
//   12 to control light timer
//   13 to control light blinking mode
void ACKUser_OnModeControllerDirective(int32_t correlationId, uint32_t instance, bool isDelta, int32_t value)
{
#ifdef ACK_LOGGING
    ACK_WriteLogFormatted(
        acp_log_level_info,
        LOG_COMPONENT_NAME,
        "Handling Mode directive: %"PRIu32" isDelta: %u value: %d",
        instance,
        isDelta,
        value);
#endif

    switch (instance)
    {
    case MODE_INSTANCE_TIMER:
        ProcessSetTimerModeDirective(correlationId, isDelta, value);
        break;
    case MODE_INSTANCE_BLINKING:
        ProcessSetSpeedModeDirective(correlationId, isDelta, value);
        break;
    default:
        ACK_DEBUG_PRINT_E("Mode controller - not supported instance id: %u", instance);
        break;
    }
}

void ProcessSetTimerModeDirective(int32_t correlationId, bool isDelta, int32_t value)
{
    ACKPropertiesBits_t changedPropertiesBits = 0;

    if (isDelta)
    {
        if ((g_timerMode + value > TIMER_MODE_60_MIN) || (g_timerMode + value < TIMER_MODE_NONE))
        {
            // The user tries to get value out of supported range.
            // Complete directive with an error.
            ACK_CompleteDirectiveWithOutOfRangeError(
                correlationId,
                TIMER_MODE_NONE,
                TIMER_MODE_60_MIN,
                NULL);

            return;
        }

        g_timerMode += value;
        changedPropertiesBits |= ACK_PROPERTY_BIT(PROPERTY_TIMER_MODE);
    }
    else
    {
        if (g_timerMode != value)
        {
            g_timerMode = value;
            changedPropertiesBits |= ACK_PROPERTY_BIT(PROPERTY_TIMER_MODE);
        }
    }

    if (changedPropertiesBits)
    {
        // If power was off, turn it on.
        changedPropertiesBits |= SetLightToOnIfOff();

        // Set timer countdown
        switch (g_timerMode)
        {
        case TIMER_MODE_5_MIN:
            g_timerModeCountdown = 300000;
            break;
        case TIMER_MODE_10_MIN:
            g_timerModeCountdown = 600000;
            break;
        case TIMER_MODE_60_MIN:
            g_timerModeCountdown = 3600000;
            break;
        default:
            g_timerModeCountdown = 0;
            break;
        }
    }

    ACK_CompleteDirectiveWithSuccess(
        correlationId,
        c_lightPropertiesBits,
        changedPropertiesBits);
}

void ProcessSetSpeedModeDirective(int32_t correlationId, bool isDelta, int32_t value)
{
    ACKPropertiesBits_t changedPropertiesBits = 0;

    if (isDelta)
    {
        if ((g_blinkingMode + value > SPEED_MODE_HIGH) || (g_blinkingMode + value < SPEED_MODE_NONE))
        {
            // The user tries to get value out of supported range.
            // Complete directive with an error.
            ACK_CompleteDirectiveWithOutOfRangeError(
                correlationId,
                SPEED_MODE_NONE,
                SPEED_MODE_HIGH,
                NULL);

            return;
        }

        g_blinkingMode += value;
        changedPropertiesBits |= ACK_PROPERTY_BIT(PROPERTY_SPEED_MODE);
    }
    else
    {
        if (g_blinkingMode != value)
        {
            g_blinkingMode = value;
            changedPropertiesBits |= ACK_PROPERTY_BIT(PROPERTY_SPEED_MODE);
        }
    }

    if (changedPropertiesBits)
    {
        // If power was off, turn it on.
        changedPropertiesBits |= SetLightToOnIfOff();
        g_blinkingPower = true;
    }

    ACK_CompleteDirectiveWithSuccess(
        correlationId,
        c_lightPropertiesBits,
        changedPropertiesBits);
}

// Returns milliseconds since the last loop.
// The returned value is used to decrease the countdowns.
uint32_t TimerGap(void)
{
    return ACKPlatform_TickCount() - g_previousTick;
}

// Shutoff timer will shut the device off, when timer is elapsed.
void CheckShutoffTimer(void)
{
    ACKPropertiesBits_t changedPropertiesBits = 0;

    if (g_timerMode == TIMER_MODE_NONE)
    {
        // Timer is off.
        return;
    }

    if (g_timerModeCountdown <= 0)
    {
        // Timer elapsed.
        g_timerModeCountdown = 0;
        g_timerMode = TIMER_MODE_NONE;
        g_power = false;
        changedPropertiesBits |= ACK_PROPERTY_BIT(PROPERTY_TIMER_MODE);
        changedPropertiesBits |= ACK_PROPERTY_BIT(PROPERTY_POWER_STATE);
        changedPropertiesBits |= ResetBlinkingMode();
        Hardware_TurnLightOff();

        ACK_SendChangeReport(
            v3avs_capabilities_V3Alexa_Cause_CauseType_RULE_TRIGGER,
            c_lightPropertiesBits,
            changedPropertiesBits);
    }
    else
    {
        g_timerModeCountdown -= TimerGap();
    }
}

// Blinking timer powers the LED on/off each time the countdown is reached.
// Once reached, countdown is reset.
void CheckBlinkingMode(void)
{
    if (g_blinkingMode == SPEED_MODE_NONE)
    {
        // Blinking mode is off.
        return;
    }

    if (g_blinkingCountdown <= 0)
    {
        if (g_blinkingPower)
        {
            Hardware_TurnLightOff();
            g_blinkingPower = false;
        }
        else
        {
            Hardware_TurnLightOn();
            g_blinkingPower = true;
        }

        switch (g_blinkingMode) {
        case SPEED_MODE_LOW:
            g_blinkingCountdown = 1500;
            break;
        case SPEED_MODE_MEDIUM:
            g_blinkingCountdown = 700;
            break;
        case SPEED_MODE_HIGH:
            g_blinkingCountdown = 300;
            break;
        default:
            if (g_power)
            {
                Hardware_TurnLightOn();
            }

            g_blinkingCountdown = 0;
            g_blinkingMode = SPEED_MODE_NONE;
            break;
        }
    }
    else
    {
        g_blinkingCountdown -= TimerGap();
    }
}

// State-report callback.
void ACKUser_OnReportStateDirective(int32_t correlationId)
{
    // This sends all properties demonstrated in this application.
    ACK_CompleteStateReportWithSuccess(correlationId);
}

bool AddPowerProperty(uint32_t propertyOrdinal, unsigned propertyFlags)
{
    // Populate metadata about the property. 
    // Leave the time-of-sample-field 0 to cause the current time to be sent. 
    // Set the error margin to 10 milliseconds for illustrative purposes.
    ACKStateCommon_t common = { 0, 10, propertyFlags };
    ACKError_t error;

    error = ACK_AddPowerControllerProperty(&common, g_power);

    if (ACK_NO_ERROR != error)
    {
        ACK_DEBUG_PRINT_E("Error %u adding power property to event", error);
        return false;
    }

    return true;
}

bool AddLightBrightnessProperty(uint32_t propertyOrdinal, unsigned propertyFlags)
{
    // Populate metadata about the property. 
    // Leave the time-of-sample-field 0 to cause the current time to be sent. 
    // Set the error margin to 10 milliseconds for illustrative purposes.
    ACKStateCommon_t common = { 0, 10, propertyFlags };
    ACKError_t error;

    error = ACK_AddBrightnessControllerProperty(&common, g_brightness);

    if (ACK_NO_ERROR != error)
    {
        ACK_DEBUG_PRINT_E("Error %u adding brightness property to event", error);
        return false;
    }

    return true;
}

bool AddLightTimerProperty(uint32_t propertyOrdinal, unsigned propertyFlags)
{
    // Populate metadata about the property. 
    // Leave the time-of-sample-field 0 to cause the current time to be sent. 
    // Set the error margin to 10 milliseconds for illustrative purposes.
    ACKStateCommon_t common = { 0, 10, propertyFlags };
    ACKError_t error;

    error = ACK_AddModeControllerProperty(MODE_INSTANCE_TIMER, &common, g_timerMode);

    if (ACK_NO_ERROR != error)
    {
        ACK_DEBUG_PRINT_E("Error %u adding timer mode property to event", error);
        return false;
    }

    return true;
}

bool AddLightBlinkingProperty(uint32_t propertyOrdinal, unsigned propertyFlags)
{
    // Populate metadata about the property. 
    // Leave the time-of-sample-field 0 to cause the current time to be sent. 
    // Set the error margin to 10 milliseconds for illustrative purposes.
    ACKStateCommon_t common = { 0, 10, propertyFlags };
    ACKError_t error;

    error = ACK_AddModeControllerProperty(MODE_INSTANCE_BLINKING, &common, g_blinkingMode);

    if (ACK_NO_ERROR != error)
    {
        ACK_DEBUG_PRINT_E("Error %u adding blinking mode property to event", error);
        return false;
    }

    return true;
}

// Turns light on.
// This function is hardware specific. In the current implementation it assumes PWM pin
// with 0 as off and 255 as maximum value.
void Hardware_TurnLightOn(void)
{
    uint8_t brightness = (uint8_t)(255 * (uint16_t)g_brightness / 100);
    ACKPlatform_SetDigitalPinPWMLevel(ACK_HW_PIN_SAMPLE_APPLICATIONS_LED, brightness);
}

// Turns light off.
// This function is hardware specific. In the current implementation it assumes PWM pin
// with 0 as off and 255 as maximum value.
void Hardware_TurnLightOff(void)
{
    ACKPlatform_SetDigitalPinPWMLevel(ACK_HW_PIN_SAMPLE_APPLICATIONS_LED, 0);
}
