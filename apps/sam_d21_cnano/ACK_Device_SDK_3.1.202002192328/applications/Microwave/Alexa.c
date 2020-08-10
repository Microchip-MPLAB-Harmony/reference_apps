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
    This file contains support for integrating ACK into the microwave. This includes handling for
    Alexa directives, and sending various events such as directive responses, errors, state reports,
    and change reports. The strategy is generally to tap into the existing microwave application's
    state machine (see Microwave.c).
*/

#include "ack.h"
#include "ack_cooking.h"
#include "ack_time_hold_controller.h"
#include "ack_user_device.h"
#include "Alexa.h"
#include "Microwave.h"

#define __STDC_FORMAT_MACROS // Ensure inttypes.h is functional even when compiled as C++.
#include <inttypes.h>

// Property ordinals. Used to maps from a property or a set of properties to a routine in our code
// that adds the property or properties to an outgoing event (directive response, state report, or
// change report).
// The actual values here can be anything in the range [0-31].
// For this sample, we treat all cooking properties as a single unit.
#define COOKING_PROPERTY_GROUP  1

// Routine that adds cooking-related properties to an outgoing event.
static bool AddCookingProperties(uint32_t propertyOrdinal, unsigned propertyFlags);

// Worker routines for AddCookingProperties.
static bool AddCookingModeProperties(const ACKStateCommon_t* pPropertyState);
static bool AddCookingTimeProperties(const ACKStateCommon_t* pPropertyState);
static bool AddCookingPowerLevelProperties(const ACKStateCommon_t* pPropertyState);
static bool AddCookingFoodProperties(const ACKStateCommon_t* pPropertyState);

static void ProcessStartCookingDirective(int32_t correlationId, const ACKCookingDirectiveParams_t* pParams);

static void CompleteDirective(int32_t correlationId, MicrowaveError error);

static bool AlexaPowerLevelToHardwarePowerLevel(
    int32_t correlationId,
    const ACKCookingDirectiveParams_t* pParams,
    HardwarePowerLevel* pHardwarePowerLevel);

static bool AlexaFoodQuantityToOuncesTimesTen(
    int32_t correlationId,
    const ACKItemQuantity_t* pQuantity, 
    uint32_t* pOuncesTimesTen);

// Required table that maps properties to routines in our code that populate an outgoing event such as
// a directive response, state report, or change report.
ACKPropertyTableEntry_t ACKUser_PropertyTable[] = 
{
    { COOKING_PROPERTY_GROUP, AddCookingProperties },

    // An entry with a NULL callback function terminates the table.
    { 0, NULL }
};

void Alexa_Setup(void)
{
    // Initialize Host MCU Implementation Core.
    ACK_Initialize();
}

void Alexa_Loop(void)
{
    // Process incoming ACK events. If there is such an event available, it will have been dispatched
    // to your corresponding handler callback, before ACK_Process returns. If your handler callback
    // calls one of the ACK_Complete* routines, then the response to the event will have also been sent
    // before ACK_Process returns.
    ACK_Process();
}

// Sends an Alexa change report indicating that cooking properties changed due to local control
// of the device (e.g. from the keypad).
void Alexa_SendChangeReportDueToLocalControl(void)
{
    ACK_SendChangeReport(
        v3avs_capabilities_V3Alexa_Cause_CauseType_PHYSICAL_INTERACTION,
        ACK_PROPERTY_BIT(COOKING_PROPERTY_GROUP),
        0);
}

// Returns a value to HMCU Core indicating whether the device is in use.
bool ACKUser_IsDeviceInUse(void)
{
    // This relies on internal microwave application state; delegate to the microwave application.
    return Microwave_IsDeviceInUse();
}

// Handler callback for incoming Alexa.Cooking set-mode directives.
// ACK_Process dispatches to this routine if such an incoming event is available from the
// ACK connectivity module when ACK_Process is called.
void ACKUser_OnCookingSetModeDirective(int32_t correlationId, const ACKCookingDirectiveParams_t* pParams)
{
    ACK_DEBUG_PRINT_I("Received set-cooking-mode directive; mode %u.", pParams->CookingMode);

    ProcessStartCookingDirective(correlationId, pParams);
}

// Handler callback for incoming Alexa.Cooking.TimeController cook-by-time directives.
// ACK_Process dispatches to this routine if such an incoming event is available from the
// ACK connectivity module when ACK_Process is called.
void ACKUser_OnCookingTimeControllerCookByTimeDirective(
    int32_t correlationId,
    const ACKCookingDirectiveParams_t* pParams)
{
    ACK_DEBUG_PRINT_I("Received cook-by-time directive; mode %u.", pParams->CookingMode);

    ProcessStartCookingDirective(correlationId, pParams);
}

// Handler callback for incoming Alexa Alexa.Cooking.TimeController adjust-cook-time directives.
// ACK_Process dispatches to this routine if such an incoming event is available from the
// ACK connectivity module when ACK_Process is called.
void ACKUser_OnCookingTimeControllerAdjustCookTimeDirective(
    int32_t correlationId,
    int64_t timeDeltaMilliseconds)
{
    ACK_DEBUG_PRINT_I(
        "Received adjust-cook-time directive; delta %"PRId64" ms.",
        timeDeltaMilliseconds);

    CompleteDirective(
        correlationId,
        Microwave_AdjustCookTime((int32_t)((timeDeltaMilliseconds + 500) / 1000)));
}

// Handler callback for incoming Alexa.TimeHoldController hold directives.
// ACK_Process dispatches to this routine if such an incoming event is available from the
// ACK connectivity module when ACK_Process is called.
void ACKUser_OnTimeHoldControllerHoldDirective(int32_t correlationId)
{
    ACK_DEBUG_PRINT_I("Received hold directive.");

    CompleteDirective(correlationId, Microwave_PauseCooking());
}

// Handler callback for incoming Alexa.TimeHoldController resume directives.
// ACK_Process dispatches to this routine if such an incoming event is available from the
// ACK connectivity module when ACK_Process is called.
void ACKUser_OnTimeHoldControllerResumeDirective(int32_t correlationId)
{
    ACK_DEBUG_PRINT_I("Received resume directive.");

    CompleteDirective(correlationId, Microwave_ResumeCooking());
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
    return Microwave_DidUserInitiateFactoryReset();
}

// Returns a value to HMCU Reference Implementation Core indicating whether the user has performed the
// magic keypress to initiate setup.
bool ACKUser_DoesUserWantUserGuidedSetup(void)
{
    return Microwave_DidUserInitiateAckSetup();
}

// Returns a value to HMCU Reference Implementation Core indicating whether the user has performed the
// magic keypress to submit logs.
bool ACKUser_DoesUserWantToSubmitLogs(void)
{
    return Microwave_DidUserInitiateAckSubmitLogs();
}

// Updates user-facing connectivity display.
void ACKUser_OnLifecycleStateChange(void)
{
    MicrowaveConnectivityState state;

    ACK_DEBUG_PRINT_I("ACK lifecycle state changed to %u", ACK_LifecycleState);

    switch (ACK_LifecycleState)
    {
    case ACK_LIFECYCLE_FACTORY_RESET_IN_PROGRESS:
        state = MICROWAVE_CONNECTIVITY_FACTORY_RESET;
        break;
    case ACK_LIFECYCLE_IN_SETUP_MODE:
        state = MICROWAVE_CONNECTIVITY_ACK_SETUP;
        break;
    case ACK_LIFECYCLE_NOT_REGISTERED:
    case ACK_LIFECYCLE_NOT_CONNECTED_TO_ALEXA:
        state = MICROWAVE_CONNECTIVITY_NOT_CONNECTED;
        break;
    case ACK_LIFECYCLE_CONNECTED_TO_ALEXA:
        state = MICROWAVE_CONNECTIVITY_CONNECTED;
        break;
    default:
        state = MICROWAVE_CONNECTIVITY_OTHER;
        break;
    }

    Microwave_UpdateConnectivityState(state);
}

// Erases user settings during a factory reset.
void ACKUser_EraseUserSettings(void)
{
    Microwave_FactoryReset();
}

// Checks the current state to determine whether a cooking directive is valid. If the directive is not
// allowed in the current state, the directive is completed with an error and false is returned.
// Otherwise true is returned.
static void ProcessStartCookingDirective(int32_t correlationId, const ACKCookingDirectiveParams_t* pParams)
{
    MicrowaveError error;
    HardwarePowerLevel hardwarePowerLevel = HARDWARE_POWER_LEVEL_HIGH;
    uint32_t ouncesTimesTen = 0;

    switch (pParams->CookingMode)
    {
    case v3avs_types_V3CookingMode_Value_TIMECOOK:

        if ((pParams->Flags & ACK_COOKING_DIRECTIVE_POWER_LEVEL_VALID)
            && !AlexaPowerLevelToHardwarePowerLevel(correlationId, pParams, &hardwarePowerLevel))
        {
            // Directive already completed with error.
            return;
        }

        // Just assume that the duration is valid for time cook. Otherwise, time cook doesn't make sense.
        error = Microwave_StartCookingByTime((uint32_t)(pParams->Duration / 1000), hardwarePowerLevel);
        break;

    case v3avs_types_V3CookingMode_Value_DEFROST:
        if ((pParams->Flags & ACK_COOKING_DIRECTIVE_FOOD_QUANTITY_VALID)
            && !AlexaFoodQuantityToOuncesTimesTen(correlationId, &pParams->FoodQuantity, &ouncesTimesTen))
        {
            // Directive already completed with error.
            return;
        }

        error = Microwave_StartDefrostingByWeight(ouncesTimesTen);
        break;

    default:
        // Unknown mode. This shouldn't happen, because the device type indicates which modes we support.
        error = MICROWAVE_NO_ERROR;
        break;
    }

    CompleteDirective(correlationId, error);
}

// Completes a directive based on an error condition (or no error) returned by Device Manager.
static void CompleteDirective(int32_t correlationId, MicrowaveError error)
{
    switch (error)
    {
    case MICROWAVE_ERROR_DOOR_OPEN:
        ACK_CompleteDirectiveWithCookingError(
            correlationId,
            v3avs_capabilities_V3AlexaCooking_ErrorResponse_ErrorType_DOOR_OPEN,
            NULL);
        break;

    case MICROWAVE_ERROR_CHILD_LOCK_ENGAGED:
        ACK_CompleteDirectiveWithCookingError(
            correlationId,
            v3avs_capabilities_V3AlexaCooking_ErrorResponse_ErrorType_REMOTE_START_DISABLED,
            NULL);
        break;

    case MICROWAVE_ERROR_DOOR_CLOSED_TOO_LONG:
        ACK_CompleteDirectiveWithCookingError(
            correlationId,
            v3avs_capabilities_V3AlexaCooking_ErrorResponse_ErrorType_DOOR_CLOSED_TOO_LONG,
            NULL);
        break;

    case MICROWAVE_ERROR_NOT_COOKING:
        ACK_CompleteDirectiveWithSimpleError(
            correlationId,
            v3avs_capabilities_V3Alexa_ErrorResponse_ErrorType_NOT_IN_OPERATION,
            NULL);
        break;

    case MICROWAVE_ERROR_ALREADY_COOKING:
        ACK_CompleteDirectiveWithSimpleError(
            correlationId,
            v3avs_capabilities_V3Alexa_ErrorResponse_ErrorType_ALREADY_IN_OPERATION,
            NULL);
        break;

    case MICROWAVE_ERROR_NOT_SUPPORTED_IN_CURRENT_MODE:
        ACK_CompleteDirectiveWithNotSupportedInCurrentModeError(
            correlationId,
            v3avs_capabilities_V3Alexa_NotSupportedInCurrentMode_DeviceMode_OTHER,
            NULL);
        break;

    case MICROWAVE_ERROR_COOK_TIME_TOO_LONG:
        ACK_CompleteDirectiveWithCookingDurationTooLongError(
            correlationId,
            1000 * (uint64_t)MAX_COOK_DURATION_SECONDS,
            NULL);
        break;

    default:
        // Assume no error; complete the directive with success. We assume that at least one cooking property
        // must have changed; send all of them both in the directive reply and in a change report.
        ACK_CompleteDirectiveWithSuccess(
            correlationId,
            ACK_PROPERTY_BIT(COOKING_PROPERTY_GROUP),
            ACK_PROPERTY_BIT(COOKING_PROPERTY_GROUP));
        break;
    }
}

// ACK_Process calls this to add cooking properties when it's constructing an outgoing event such as
// a directive response, state report, or change report.
static bool AddCookingProperties(uint32_t propertyOrdinal, unsigned propertyFlags)
{
    ACKStateCommon_t propertyState = { 0, 0, propertyFlags };

    return AddCookingModeProperties(&propertyState)
        && AddCookingTimeProperties(&propertyState)
        && AddCookingPowerLevelProperties(&propertyState)
        && AddCookingFoodProperties(&propertyState);
}

static bool AddCookingModeProperties(const ACKStateCommon_t* pPropertyState)
{
    MicrowaveCookingMode deviceCookingMode;
    v3avs_types_V3CookingMode_Value alexaCookingMode;
    ACKError_t error;

    deviceCookingMode = Microwave_GetCookingMode();
    switch (deviceCookingMode)
    {
    case MICROWAVE_COOKING_MODE_TIME_COOK:
        alexaCookingMode = v3avs_types_V3CookingMode_Value_TIMECOOK;
        break;

    case MICROWAVE_COOKING_MODE_DEFROST_BY_WEIGHT:
        alexaCookingMode = v3avs_types_V3CookingMode_Value_DEFROST;
        break;

    default:
        alexaCookingMode = v3avs_types_V3CookingMode_Value_OFF;
        break;
    }

    error = ACK_AddCookingModeProperty(pPropertyState, alexaCookingMode, NULL);
    if (ACK_NO_ERROR != error)
    {
        return false;
    }

    return true;
}

static bool AddCookingTimeProperties(const ACKStateCommon_t* pPropertyState)
{
    uint32_t remainingTimeSeconds;
    uint32_t requestedDurationSeconds;
    uint64_t nowEpoch;
    uint32_t remainingTimeMilliseconds;
    ACKError_t error;

    if (Microwave_GetCookTimeInfo(&remainingTimeSeconds, &requestedDurationSeconds))
    {
        remainingTimeMilliseconds = 1000 * (uint64_t)remainingTimeSeconds;

        // Calculate end time epoch.
        nowEpoch = ACK_GetApproximateTime();
        if (nowEpoch)
        {
            error = ACK_AddCookingTimeIntervalProperty(
                pPropertyState,
                0,
                nowEpoch + remainingTimeMilliseconds,
                remainingTimeMilliseconds);

            if (ACK_NO_ERROR != error)
            {
                return false;
            }
        }

        error = ACK_AddCookingTimeControllerRequestedCookTimeProperty(
            pPropertyState,
            1000 * (uint64_t)requestedDurationSeconds);

        if (ACK_NO_ERROR != error)
        {
            return false;
        }
    }

    return true; 
}

static bool AddCookingPowerLevelProperties(const ACKStateCommon_t* pPropertyState)
{
    HardwarePowerLevel hardwarePowerLevel;
    v3avs_types_V3EnumeratedPowerLevel_Value alexaPowerLevel;
    ACKError_t error;

    if (Microwave_GetCookingPowerLevelInfo(&hardwarePowerLevel))
    {
        // Convert hardware power level to Alexa power level.
        switch (hardwarePowerLevel)
        {
        case HARDWARE_POWER_LEVEL_LOW:
            alexaPowerLevel = v3avs_types_V3EnumeratedPowerLevel_Value_LOW;
            break;

        case HARDWARE_POWER_LEVEL_MEDIUM:
            alexaPowerLevel = v3avs_types_V3EnumeratedPowerLevel_Value_MEDIUM;
            break;

        case HARDWARE_POWER_LEVEL_HIGH:
            alexaPowerLevel = v3avs_types_V3EnumeratedPowerLevel_Value_HIGH;
            break;

        default:
            alexaPowerLevel = v3avs_types_V3EnumeratedPowerLevel_Value_NA;
            break;
        }

        error = ACK_AddCookingTimeControllerCookingPowerLevelProperty(
            pPropertyState,
            ACK_COOKING_POWER_LEVEL_ENUMERATED,
            0,
            alexaPowerLevel);

        if (ACK_NO_ERROR != error)
        {
            return false;
        }
    }

    return true; 
}

static bool AddCookingFoodProperties(const ACKStateCommon_t* pPropertyState)
{
    uint32_t ouncesTimesTen;
    ACKItemQuantity_t alexaQuantity;
    ACKError_t error;

    // If there's no weight info, don't send this property.
    if (Microwave_GetCookingWeightInfo(&ouncesTimesTen))
    {
        alexaQuantity.UnitType = ACK_ITEM_QUANTITY_WEIGHT;
        alexaQuantity.Unit.WeightUnit = v3avs_types_V3Weight_Unit_OUNCE;
        alexaQuantity.Quantity = (float)ouncesTimesTen / 10.0f;

        error = ACK_AddFoodItemProperty(pPropertyState, NULL, &alexaQuantity);
        if (ACK_NO_ERROR != error)
        {
            return false;
        }
    }

    return true;
}

// Converts a power level from Alexa into a power level that can be consumed by the hardware.
// If power level is invalid, completes a directive with an appropriate error.
static bool AlexaPowerLevelToHardwarePowerLevel(
    int32_t correlationId,
    const ACKCookingDirectiveParams_t* pParams,
    HardwarePowerLevel* pHardwarePowerLevel)
{
    ACK_ASSERT(pParams->Flags & ACK_COOKING_DIRECTIVE_DURATION_VALID);

    if (ACK_COOKING_POWER_LEVEL_INTEGRAL == pParams->PowerLevelKind)
    {
        // Our product definition specifies 5 integral power levels: 1, 2, 3, 4, 5.
        switch (pParams->PowerLevel.Integral)
        {
        case 1:
        case 2:
            *pHardwarePowerLevel = HARDWARE_POWER_LEVEL_LOW;
            break;

        case 3:
        case 4:
            *pHardwarePowerLevel = HARDWARE_POWER_LEVEL_MEDIUM;
            break;

        case 5:
            *pHardwarePowerLevel = HARDWARE_POWER_LEVEL_HIGH;
            break;

        default:
            ACK_CompleteDirectiveWithOutOfRangeError(correlationId, 1.0f, 5.0f, NULL);
            return false;
        }

        return true;
    }

    if (ACK_COOKING_POWER_LEVEL_ENUMERATED == pParams->PowerLevelKind)
    {
        // Our product definition specifies 3 enumerated power levels: low, medium, high.
        switch (pParams->PowerLevel.Enumerated)
        {
        case v3avs_types_V3EnumeratedPowerLevel_Value_LOW:
            *pHardwarePowerLevel = HARDWARE_POWER_LEVEL_LOW;
            break;

        case v3avs_types_V3EnumeratedPowerLevel_Value_MEDIUM:
            *pHardwarePowerLevel = HARDWARE_POWER_LEVEL_MEDIUM;
            break;

        case v3avs_types_V3EnumeratedPowerLevel_Value_HIGH:
            *pHardwarePowerLevel = HARDWARE_POWER_LEVEL_HIGH;
            break;

        default:
            ACK_CompleteDirectiveWithSimpleError(
                correlationId,
                v3avs_capabilities_V3Alexa_ErrorResponse_ErrorType_INVALID_VALUE,
                NULL);
            return false;
        }

        return true;
    }

    // Should never be here.
    return false;
}

// Extracts and converts a weight quantity from Alexa into a value representing 10x a count of ounces.
// If the quantity is not weight, or not in a unit we understand, completes a directive with an
// appropriate error.
static bool AlexaFoodQuantityToOuncesTimesTen(
    int32_t correlationId,
    const ACKItemQuantity_t* pQuantity, 
    uint32_t* pOuncesTimesTen)
{
    bool error = false;

    if (ACK_ITEM_QUANTITY_WEIGHT == pQuantity->UnitType)
    {
        #define _GRAMS_PER_OUNCE 28.35f

        // Note: there are no checks for overflow in here.
        switch (pQuantity->Unit.WeightUnit)
        {
        case v3avs_types_V3Weight_Unit_GRAM:
            *pOuncesTimesTen = (uint32_t)(10.0f * pQuantity->Quantity / _GRAMS_PER_OUNCE);
            break;

        case v3avs_types_V3Weight_Unit_KILOGRAM:
            *pOuncesTimesTen = (uint32_t)(10.0f * pQuantity->Quantity * 1000.0f / _GRAMS_PER_OUNCE);
            break;

        case v3avs_types_V3Weight_Unit_OUNCE:
            *pOuncesTimesTen = (uint32_t)(10.0f * pQuantity->Quantity);
            break;

        case v3avs_types_V3Weight_Unit_POUND:
            *pOuncesTimesTen = (uint32_t)(10.0f * pQuantity->Quantity * 16.0f);
            break;

        default:
            // We don't handle this weight unit.
            error = true;
            break;
        }
    }
    else
    {
        error = true;
    }

    if (error)
    {
        ACK_CompleteDirectiveWithSimpleError(
            correlationId,
            v3avs_capabilities_V3Alexa_ErrorResponse_ErrorType_INVALID_VALUE,
            NULL);
        return false;
    }

    return true;
}
