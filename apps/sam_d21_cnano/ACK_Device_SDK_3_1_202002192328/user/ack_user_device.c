/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

/*
    Default implementations for ACK_UserXxx routines.

    All implementations are surrounded by #ifndef ACK_NO_ACKUSER_xxx. This allows Amazon-supplied
    ACK Host MCU sample applications to selectively replace implementations on a per-application basis.

    You can directly replace the implementations in this file, or #define ACK_NO_ACKUSER_xxx in
    ack_user_config.h and put your implementations in a different source file.
 */

#include "ack.h"
#include "ack_user_config.h"
#include "ack_user_device.h"
#include "ack_logging.h"
#include <stdbool.h>

#ifndef ACK_NO_ACKUSER_GETFIRMWAREVERSION

// Returns the version of your firmware. This can be any 64-bit value meaningful for your firmware
// versioning scheme.
uint64_t ACKUser_GetFirmwareVersion(void)
{
    // Use a simple number for illustrative purposes. This can be any value that makes sense for your
    // firmware versioning scheme.
    return 1;
}

#endif // ndef ACK_NO_ACKUSER_GETFIRMWAREVERSION

#ifndef ACK_NO_ACKUSER_DOESUSERWANT

// The manner in which a user initiates factory reset is highly device-specific. For your product to
// support factory reset, change this placeholder to return a value based on your device-specific
// factory reset initiation mechanism (such as the user entering a certain keystroke on the device's
// front panel keypad, etc.).
bool ACKUser_DoesUserWantFactoryReset(void)
{
    return false;
}

// The manner in which a user initiates user-guided setup is highly device-specific. For your product to
// support user-guided setup, change this placeholder to return a value based on your device-specific
// user-guided setup initiation mechanism (the user presses and holds a specific button, or enters a
// certain keystroke on a keypad, etc.).
bool ACKUser_DoesUserWantUserGuidedSetup(void)
{
    return false;
}

// The manner in which a user initiates log submission is highly device-specific. For your product to
// support submitting logs, change this placeholder to return a value based on your device-specific
// log submission initiation mechanism (the user presses and holds a specific button, or enters a
// certain keystroke on a keypad, etc.).
bool ACKUser_DoesUserWantToSubmitLogs(void)
{
    return false;
}

#endif // ndef ACK_NO_ACKUSER_DOESUSERWANT

#ifndef ACK_NO_ACKUSER_ERASEUSERSETTINGS

// Erase persisted user settings.
// In a production device, replace this function with your own implementation.
void ACKUser_EraseUserSettings(void)
{
    ACK_DEBUG_PRINT_I("Erasing user data.");

    // Erase all persisted user settings stored on the device.
}

#endif // ndef ACK_NO_ACKUSER_ERASEUSERSETTINGS

#ifndef ACK_NO_ACKUSER_ONLIFECYCLESTATECHANGE

// Placeholder for user-supplied routine that in production would update user-facing display elements
// relating to lifecycle and connectivity state. For example, lighting a "connected to Alexa" LED,
// or flashing an LED during factory reset, or flashing a clock when in setup mode.
void ACKUser_OnLifecycleStateChange(void)
{
#if defined(ACK_DEBUG_PRINT_LEVEL) && (ACK_DEBUG_PRINT_LEVEL >= ACK_DEBUG_PRINT_LEVEL_INFO)
    const char* pStateName = NULL;
    bool anyActive = false;

    // Setup is handled specially because it has substates.
    if (ACK_LIFECYCLE_IN_SETUP_MODE == ACK_LifecycleState)
    {
        ACK_DEBUG_PRINT_I("ACK lifecycle state: SETUP MODE");

        // Display setup type messages.
        // If you have a simple display like a blinking LED, you should present the mode by priority
        // in the order shown here.
        if (ACK_LifecycleSubStateInfo.InSetupMode.IsUserGuidedSetupActive)
        {
            ACK_DEBUG_PRINT_I("   USER GUIDED SETUP");
            anyActive = true;
        }

        if (ACK_LifecycleSubStateInfo.InSetupMode.IsBarcodeScanSetupActive)
        {
            ACK_DEBUG_PRINT_I("   BARCODE SCAN");
            anyActive = true;
        }

        if (ACK_LifecycleSubStateInfo.InSetupMode.IsZeroTouchSetupActive)
        {
            ACK_DEBUG_PRINT_I("   ZERO TOUCH SETUP");
            anyActive = true;
        }

        if (!anyActive)
        {
            ACK_DEBUG_PRINT_I("   NO SETUP MODES ACTIVE");
        }

        switch (ACK_LifecycleSubStateInfo.InSetupMode.SetupStage)
        {
        case acp_setup_stages_discoverable:
            ACK_DEBUG_PRINT_I("ACK FFS Stage: DISCOVERABLE");
            break;
        case acp_setup_stages_setup_in_progress:
            ACK_DEBUG_PRINT_I("ACK FFS Stage: SETUP IN PROGRESS");
            break;
        case acp_setup_stages_registered:
            ACK_DEBUG_PRINT_I("ACK FFS Stage: REGISTERED");
            break;
        default:
            ACK_DEBUG_PRINT_I("ACK FFS Stage: UNKNOWN");
            break;
        }

        return;
    }

    // Update user-facing elements based on the lifecycle state (other than setup, which was handled above).
    switch (ACK_LifecycleState)
    {
    case ACK_LIFECYCLE_UNAVAILABLE:
        pStateName = "UNAVAILABLE";
        break;

    case ACK_LIFECYCLE_BOOTED:
        pStateName = "BOOTED";
        break;

    case ACK_LIFECYCLE_FACTORY_RESET_IN_PROGRESS:
        pStateName = "FACTORY RESET IN PROGRESS";
        break;

    case ACK_LIFECYCLE_NOT_REGISTERED:
        pStateName = "MODULE NOT REGISTERED";
        break;

    case ACK_LIFECYCLE_NOT_CONNECTED_TO_ALEXA:
        pStateName = "NOT CONNECTED TO ALEXA";
        break;

    case ACK_LIFECYCLE_CONNECTED_TO_ALEXA:
        pStateName = "CONNECTED TO ALEXA";
        break;

    default:
        pStateName = "UNKNOWN";
        break;
    }

    ACK_DEBUG_PRINT_I("ACK lifecycle state: %s", pStateName);

#endif // def ACK_DEBUG_PRINT_LEVEL
}

#endif // ndef ACK_NO_ACKUSER_ONLIFECYCLESTATECHANGE
