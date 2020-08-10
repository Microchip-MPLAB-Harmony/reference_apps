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
    This file contains support for integrating ACK into the smart plug. This includes handling for
    Alexa directives, and sending various events such as directive responses, errors, state reports,
    and change reports.
*/

#include "ack.h"
#include "ack_power_controller.h"
#include "ack_user_device.h"
#include "HelloWorld_Alexa.h"
#include "HelloWorld_Hardware.h"

#define __STDC_FORMAT_MACROS // Ensure inttypes.h is functional even when compiled as C++.
#include <inttypes.h>

// Adds the power state property to an outgoing event.
static bool AddPowerStateProperty(uint32_t propertyOrdinal, unsigned propertyFlags);

// Property ordinals. Used to map from a property or a set of properties to a routine in our code
// that adds the property or properties to an outgoing event (directive response, state report, or
// change report).
// The actual values here can be anything in the range [0-31].
// For this sample, there's only one property, for the power state.
#define POWER_STATE_PROPERTY 1

// Required table that maps properties to routines in our code that populate an outgoing event such as
// a directive response, state report, or change report.
ACKPropertyTableEntry_t ACKUser_PropertyTable[] = 
{
    { POWER_STATE_PROPERTY, AddPowerStateProperty },

    // An entry with a NULL callback function terminates the table.
    { 0, NULL }
};

// Tracks whether the user requested factory reset by long-pressing the lifecycle button, or entering
// user-guided setup by (short-)pressing and then releasing the lifecycle button.
// Factory reset takes precedence.
#define USER_INITIATED_USER_GUIDED_SETUP 1
#define USER_INITIATED_FACTORY_RESET 2
static uint8_t sg_lifecyclePending = 0;
static bool DoesUserWantLifecycleAction(unsigned userInitiated);

//
void Alexa_Setup(void)
{
    // Initialize Host MCU Implementation Core.
    ACK_Initialize();
}

//
void Alexa_Loop(void)
{
    // Process incoming ACK events. If there is such an event available, it will have been dispatched
    // to your corresponding handler callback, before ACK_Process returns. If your handler callback
    // calls one of the ACK_Complete* routines, then the response to the event will have also been sent
    // before ACK_Process returns.
    ACK_Process();
}

// Sends an Alexa change report indicating that the power state property changed due to local control
// of the device (e.g. from the keypad).
void Alexa_SendChangeReportDueToLocalControl(void)
{
    // A change report has both changed properties and "related" properties. Since we have only the one
    // property (power state), and we're here to report that it changed, there are never any "related"
    // properties.
    ACK_SendChangeReport(
        v3avs_capabilities_V3Alexa_Cause_CauseType_PHYSICAL_INTERACTION,
        ACK_PROPERTY_BIT(POWER_STATE_PROPERTY),
        0);
}

void Alexa_InitiateFactoryReset(void)
{
    sg_lifecyclePending = USER_INITIATED_FACTORY_RESET;
}

void Alexa_InitiateUserGuidedSetup(void)
{
    // Factory reset takes precedence.
    ACK_STATIC_ASSERT(USER_INITIATED_USER_GUIDED_SETUP < USER_INITIATED_FACTORY_RESET);
    if (sg_lifecyclePending < USER_INITIATED_USER_GUIDED_SETUP)
    {
        sg_lifecyclePending = USER_INITIATED_USER_GUIDED_SETUP;
    }
}

// Returns a value to HMCU ImplCore indicating whether the device is in use.
bool ACKUser_IsDeviceInUse(void)
{
    return Hardware_IsPowerOn();
}

// Handler callback for incoming Alexa.PowerController directives.
// ACK_Process dispatches to this routine if such an incoming event is available from the
// ACK connectivity module when ACK_Process is called.
void ACKUser_OnPowerControllerDirective(int32_t correlationId, bool powerOn)
{
    bool powerStateChanged;

    ACK_DEBUG_PRINT_I("Received power controller directive; power %u.", powerOn);

    // Track whether the power state is actually changing. If so, we want to indicate this when completing
    // the directive, so an Alexa change report will be sent automatically.
    powerStateChanged = (0 == Hardware_IsPowerOn()) != (0 == powerOn);

    Hardware_SetPowerState(powerOn);

    ACK_CompleteDirectiveWithSuccess(
        correlationId,
        ACK_PROPERTY_BIT(POWER_STATE_PROPERTY),
        powerStateChanged ? ACK_PROPERTY_BIT(POWER_STATE_PROPERTY) : 0);
}

// Handler callback for state report requests.
void ACKUser_OnReportStateDirective(int32_t correlationId)
{
    // Complete the request with success. This causes all properties to be sent.
    ACK_CompleteStateReportWithSuccess(correlationId);
}

// Returns a value to HMCU Reference Implementation Core indicating whether the user has performed the
// magic keypress to initiate factory reset.
bool ACKUser_DoesUserWantFactoryReset(void)
{
    return DoesUserWantLifecycleAction(USER_INITIATED_FACTORY_RESET);
}

// Returns a value to HMCU Reference Implementation Core indicating whether the user has performed the
// magic keypress to initiate setup.
bool ACKUser_DoesUserWantUserGuidedSetup(void)
{
    return DoesUserWantLifecycleAction(USER_INITIATED_USER_GUIDED_SETUP);
}

// Returns a value to HMCU Reference Implementation Core indicating whether the user has performed the
// magic keypress to submit logs. The smart plug has no such keypress, so just return false.
bool ACKUser_DoesUserWantToSubmitLogs(void)
{
    return false;
}

// Updates user-facing connectivity display.
void ACKUser_OnLifecycleStateChange(void)
{
    HardwareConnectivityLedState ledState;

    ACK_DEBUG_PRINT_I("ACK lifecycle state changed to %u", ACK_LifecycleState);

    switch (ACK_LifecycleState)
    {
    case ACK_LIFECYCLE_CONNECTED_TO_ALEXA:
        ledState = HARDWARE_CONNECTIVITY_LED_SOLID;
        break;

    case ACK_LIFECYCLE_FACTORY_RESET_IN_PROGRESS:
    case ACK_LIFECYCLE_NOT_REGISTERED:
    case ACK_LIFECYCLE_IN_SETUP_MODE:
        ledState = HARDWARE_CONNECTIVITY_LED_BLINKING;
        break;

    case ACK_LIFECYCLE_INITIAL:
    case ACK_LIFECYCLE_UNAVAILABLE:
    case ACK_LIFECYCLE_BOOTED:
    case ACK_LIFECYCLE_NOT_CONNECTED_TO_ALEXA:
    default:
        ledState = HARDWARE_CONNECTIVITY_LED_OFF;
        break;

    }

    Hardware_SetConnectivityLedState(ledState);
}

// ACK_Process calls this to add properties when it's constructing an outgoing event such as a directive
// response, state report, or change report. The property ordinal is unused because the Power Controller
// capability is single-instance; there can be a maximum of one of them on any device.
static bool AddPowerStateProperty(uint32_t propertyOrdinal, unsigned propertyFlags)
{
    ACKStateCommon_t propertyState = { 0, 0, propertyFlags };
    ACKError_t error;

    error = ACK_AddPowerControllerProperty(&propertyState, Hardware_IsPowerOn());
    if (ACK_NO_ERROR != error)
    {
        ACK_DEBUG_PRINT_E("Error %u adding power state property.", error);
        return false;
    }

    return true;
}

static bool DoesUserWantLifecycleAction(unsigned userInitiated)
{
    bool userWants;

    userWants = (sg_lifecyclePending == userInitiated);

    if (userWants)
    {
        sg_lifecyclePending = 0;
    }

    return userWants;
}
