/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_H__
#define __ACK_H__

#include "ack_user_config.h"
#include "ack_user_platform.h"
#include "acp.pb.h"
#include "details/ack_debug_print.h"
#include "details/ack_types.h"
#include <stdbool.h>
#include <stdint.h>
#include "v3avs_capabilities/V3Alexa.pb.h"
#include "v3avs_types/V3Temperature.pb.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Represents the state of connectivity to Alexa, in the return value from ACK_GetStatus.
typedef enum _ACKAlexaConnectivityState_t
{
    ACK_CONNECTIVITY_UNKNOWN,
    ACK_NOT_REGISTERED,
    ACK_IN_SETUP_MODE,
    ACK_NOT_CONNECTED_TO_ALEXA,
    ACK_CONNECTED_TO_ALEXA
}
ACKAlexaConnectivityState_t;

// Typedef for additional information if current state is in setup mode.
typedef struct _ACKSetupModeInfo_t
{
    acp_setup_stages SetupStage;

    // These fields are all a single bit to save space.
    unsigned IsUserGuidedSetupActive: 1;
    unsigned IsBarcodeScanSetupActive: 1;
    unsigned IsZeroTouchSetupActive: 1;
}
ACKSetupModeInfo_t;

// Type for ACK_GetStatus.
typedef struct _ACKStatus_t
{
    // Local time. Values are -1 if time on the Connectivity Module is not valid.
    int HH;
    int MM;
    int SS;

    // Posix epoch, seconds. Zero if time on the Connectivity Module is not valid.
    uint32_t EpochSeconds;

    // Connectivity status.
    ACKAlexaConnectivityState_t ConnectivityState;

    // Extra connectivity state information.
    // This union should be interpreted based on the value of ConnectivityState.
    union
    {
        ACKSetupModeInfo_t InSetupMode;
    }
    SubStateInfo;

    // Connectivity-related error code, e.g. to display on a device's LEDs, etc.
    acp_response_error_codes ErrorCode;
}
ACKStatus_t;

// Call this before calling any other core routines.
void ACK_Initialize(void);

// Retrieves the status of the connectivity module.
// Status includes the current time, connectivity state, and an error code e.g. to display on a device's
// front panel.
void ACK_GetStatus(ACKStatus_t* pStatus);

// Retrieves an approximate Posix epoch time, which is the number of elapsed milliseconds since 1 Jan 1970
// at midnight UTC. Calling this does not cause traffic to/from the Connectivity Module; this value is
// calculated locally based on information periodically received from the Connectivity Module during your
// calls to ACK_Process.
// This value is approximate but is accurate enough for use as the sample time for properties being added
// to an outbound event. The default behavior if you don't set a time for those is to use the value from
// this routine.
uint64_t ACK_GetApproximateTime(void);

// You must implement this routine.
void ACKUser_OnReportStateDirective(int32_t correlationId);

// Routines to interact with the ACK Connectivity Module hardware.
bool ACK_IsHostInterruptAsserted(void);
void ACK_ResetConnectivityModule(void);

// Main routine for processing ACK events and lifecycle.
void ACK_Process(void);

// ACK connectivity module lifecycle states. Besides being used to guide logic flows in this app, this
// can be used to display info to the user, e.g. light a wifi icon when connected to Alexa, flash "setup"
// when in setup mode, etc.
typedef enum _ACKLifecycleState_t
{
    // Initial lifecycle when the HMCU application starts up. There's an immediate transition to UNAVAILABLE
    // while the HMCU and ACK Connectivity Module finish booting and initializing.
    ACK_LIFECYCLE_INITIAL,

    // The ACK Connectivity Module is not available. This is the state after we've rebooted
    // the ACK Connectivity Module (and at startup, since the first thing we do is reboot it).
    // In this state we can (and must) still call ProcessEventIfAvailable, because transitioning
    // out of this state requires us receiving the module-booted event. However we cannot successfully call
    // ACK_GetStatus() in this state.
    ACK_LIFECYCLE_UNAVAILABLE,

    // The ACK Connectivity Module finished booting (or rebooting). This results in this code sending
    // host configuration info to the ACK Connectivity Module, if it hasn't already been sent since entering
    // this state.
    ACK_LIFECYCLE_BOOTED,

    // We successfully initiated a factory reset, which is in progress.
    ACK_LIFECYCLE_FACTORY_RESET_IN_PROGRESS,

    // The ACK Module is not registered but the setup process has timed out or is not running.
    ACK_LIFECYCLE_NOT_REGISTERED,

    // The ACK Module is in setup mode.
    ACK_LIFECYCLE_IN_SETUP_MODE,

    // This state can exist in a few scenarios:
    // (1) The ACK Module is fully configured but not connected to Alexa, for example because wifi is down.
    // (2) The device didn't finish a factory reset cycle before power was lost. In this case the user can
    //     try factory reset again.
    ACK_LIFECYCLE_NOT_CONNECTED_TO_ALEXA,

    // The ACK module is fully configured and is connected to Alexa.
    ACK_LIFECYCLE_CONNECTED_TO_ALEXA
}
ACKLifecycleState_t;

// Union of extra state information. Interpretation depends on the current life cycle state.
typedef union _ACKLifecycleSubStateInfo_t
{
    // For lifecycle state ACK_LIFECYCLE_IN_SETUP_MODE.
    ACKSetupModeInfo_t InSetupMode;
}
ACKLifecycleSubStateInfo_t;

extern ACKLifecycleState_t ACK_LifecycleState;
extern ACKLifecycleSubStateInfo_t ACK_LifecycleSubStateInfo;

// Converts a property ordinal to a bit.
#define ACK_PROPERTY_BIT(x) (1 << (x))

// Type for bitfield to represent multiple properties.
typedef uint32_t ACKPropertiesBits_t;

// Predefined value for 'all properties'.
#define ACK_EVENT_ALL_PROPERTIES ((ACKPropertiesBits_t)(-1))

// Entry in an array that maps Alexa capabilities to a routine in an ACK HMCU application that adds
// properties to an outbound event being constructed.
typedef struct _ACKPropertyTableEntry_t
{
    // An application-specific value. Passed to the AddProperties routine.
    uint32_t PropertyOrdinal;

    // NULL terminates the map.
    // propertyFlags is a combination of ACK_PROPERTY_xxx flags from ack_types.h.
    bool (*AddPropertiesRoutine)(uint32_t propertyOrdinal, unsigned propertyFlags);
}
ACKPropertyTableEntry_t;

// You must have a variable in your application with this name. An entry with a NULL AddPropertiesRoutine
// terminates the array.
extern ACKPropertyTableEntry_t ACKUser_PropertyTable[];

// ACK_CompleteDirectiveWith* routines are used to supply a response to a directive. You typically call these
// from within an ACKUser_On* handler callback routine, in which case the directive response is sent before
// ACK_Process returns to you. If your ACKUser_On* handler callback routine doesn't immediately know the
// outcome of processing a directive, you can call an ACK_CompleteDirectiveWith* routine later, after
// ACK_Process has returned. In that case, the directive response is sent immediately.
// Every directive requires exactly one response. If you don't call an ACK_CompleteDirectiveWith* routine for
// a given directive, Alexa will inform the end user of an error. Calling ACK_CompleteDirectiveWith* more
// than once for a given directive will produce undefined behavior.

// Tells Alexa that you completed processing a directive successfully, by sending a directive response
// containing the properties identified by responsePropertiesBits. If changeReportPropertiesBits is non-0,
// an Alexa change report is sent indicating that the properties designated in changeReportPropertiesBits
// changed as a result of processing the directive. (For convenience a property can appear in both
// responsePropertiesBits and changeReportPropertiesBits, but is effectively removed from
// responsePropertiesBits for the purposes of creating the change report.)
ACKError_t ACK_CompleteDirectiveWithSuccess(
    int32_t correlationId,
    ACKPropertiesBits_t responsePropertiesBits,
    ACKPropertiesBits_t changeReportPropertiesBits);

// Tells Alexa that you could not complete processing a directive.
// If there is a more specific routine for the error you want to send (see below) you must use that routine
// instead of this one.
ACKError_t ACK_CompleteDirectiveWithSimpleError(
    int32_t correlationId,
    v3avs_capabilities_V3Alexa_ErrorResponse_ErrorType type,
    const char* pOptionalMessage);

// Tells Alexa that you could not complete processing a directive because a value was out of range.
ACKError_t ACK_CompleteDirectiveWithOutOfRangeError(
    int32_t correlationId,
    float minimum,
    float maximum,
    const char* pOptionalMessage);

// Tells Alexa that you could not complete processing a directive because a temperature value was
// out of range.
ACKError_t ACK_CompleteDirectiveWithTemperatureOutOfRangeError(
    int32_t correlationId,
    v3avs_types_V3Temperature_Scale scale,
    float minimum,
    float maximum,
    const char* pOptionalMessage);

// Tells Alexa that you could not complete processing a directive due to the current device mode.
ACKError_t ACK_CompleteDirectiveWithNotSupportedInCurrentModeError(
    int32_t correlationId,
    v3avs_capabilities_V3Alexa_NotSupportedInCurrentMode_DeviceMode mode,
    const char* pOptionalMessage);

// Sends the state of all of your device properties to Alexa.
ACKError_t ACK_CompleteStateReportWithSuccess(int32_t correlationId);

// Sends an Alexa change report, indicating that the state of one or more of your properties changed.
// The changedPropertiesBits value tells Alexa which propoerties actually changed. The otherPropertiesBits
// value tells Alexa the state of properties that didn't themselves change, but which are related to
// properties that did change.
ACKError_t ACK_SendChangeReport(
    v3avs_capabilities_V3Alexa_Cause_CauseType cause,
    ACKPropertiesBits_t changedProperiesBits,
    ACKPropertiesBits_t otherPropertiesBits);

#ifdef __cplusplus
}
#endif

#endif // def __ACK_H__
