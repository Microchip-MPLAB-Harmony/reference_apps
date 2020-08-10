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

// TODO:
// When we're in setup mode, should the device be able to cook via local control?
// Currently we just update the connectivity lamp but don't wire setup into the state machine.

/*
    Models an over-simplified, pre-existing hypothetical microwave oven to which Alexa functionality is
    added via the ACK Device SDK.
    
    The microwave has a keypad consisting of digits 0-9, a start button for time cooking, a defrost button
    for weight-based defrosting, and a pause/stop button. There is a clock display capable of displaying
    6 characters, used for the time and the countdown when cooking.

    When the start button is pressed, digits the user has entered are taken as HH:MM:SS and used as the
    cook time. For simplicity, there is no way to set the power level from the keypad for time cooking.

    When the defrost button is pressed, digits the user has entered are taken as a count of ounces.
    Defrosting occurs for 50 seconds per ounce at medium-low power level.

    When the stop button is pressed while cooking, cooking pauses. If the stop button is pressed while
    cooking is paused, cooking stops. If the stop button is pressed while entering digits, entered digits
    are forgotten.

    The user can hold down pause/stop+0 for 4 seconds to toggle a child lock, when the microwave is idle with
    the door closed. When idle, the microwave also watches for the door being closed for 10 minutes, and
    locks the user out until the door is opened.

    Key presses are recognized only when the door is closed.

    Certain real-world microwave functionality is not provided in this simple example:
    * Beeps as keys are pressed
    * Indication that cooking has completed via beeps or flashing the clock
    * Setting the power level from the keypad

    The implementation assumes that underlying hardware is idempotent, i.e. we the hardware routine
    to start or stop cooking becomes a no-op if already cooking or not cooking respectively; and persisting
    the child lock state becomes a no-op if the new state matches the already-persisted state.

    Implementation is by a state machine as shown below. The begin state is either IDLE or CHILD_LOCKED
    depending on the state of the child lock hardware.

    States
    ------
        IDLE                    
        CHILD_LOCKED
        DOOR_CLOSED_TOO_LONG
        ACCUMULATED_DIGITS
        COOKING
        COOKING_PAUSED

    Inputs
    ------
        Door open/closed
        Digit keypress
        Start keypress
        Defrost keypress
        Pause/stop keypress
        Child lock keypress

    Transitions
    -----------
    IDLE:
        door closed & non-0 digit keypress -> ACCUMULATED_DIGITS
        door closed & child lock keypress -> CHILD_LOCKED
        door closed too long -> DOOR_CLOSED_TOO_LONG

    CHILD_LOCKED:
        door closed & child lock keypress -> IDLE

    DOOR_CLOSED_TOO_LONG:
        door open -> IDLE
        door closed & child lock keypress -> CHILD_LOCKED

    ACCUMULATED_DIGITS:
        door open -> IDLE
        door closed & digit keypress -> ACCUMULATED_DIGITS
        door closed & start keypress -> COOKING
        door closed & defrost keypress -> COOKING
        door closed & pause/stop keypress -> IDLE
        door closed too long -> DOOR_CLOSED_TOO_LONG

    COOKING:
        door closed & pause/stop keypress -> COOKING_PAUSED
        door open -> COOKING_PAUSED

    COOKING_PAUSED:
        door closed & start keypress -> COOKING
        door closed & pause/stop keypress -> IDLE
        door closed too long -> DOOR_CLOSED_TOO_LONG
*/

#include "ack_tick64.h" // This is here only to get a 64-bit tick count.
#include "details/ack_debug_print.h"

#include "Alexa.h"
#include "Hardware.h"
#include <inttypes.h>
#include "Microwave.h"
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Leave this defined to suppress the logic that determines whether the door has been closed too long.
// The default implementation of Hardware_IsDoorOpen just returns false, which causes the state machine
// to start out in "door closed too long" state, and no Alexa directives can be issued. This is inconvenient
// when trying to debug this code.
// IN A REAL DEVICE, THIS #define MUST BE REMOVED.
#define IGNORE_DOOR_CLOSED_TOO_LONG

// Portable static assertion mechanism to enforce compile-time invariants.
#define _STATIC_ASSERT(x) switch(0){case 0: case (x):;}

// An action the microwave can perform based on input at the keypad.
typedef enum _Action
{
    ACTION_NONE,

    // These MUST be in the same order as the HardwareAction enum (in Hardware.h).
    ACTION_ACCUMULATE_0,
    ACTION_ACCUMULATE_1,
    ACTION_ACCUMULATE_2,
    ACTION_ACCUMULATE_3,
    ACTION_ACCUMULATE_4,
    ACTION_ACCUMULATE_5,
    ACTION_ACCUMULATE_6,
    ACTION_ACCUMULATE_7,
    ACTION_ACCUMULATE_8,
    ACTION_ACCUMULATE_9,
    ACTION_START,
    ACTION_DEFROST_WEIGHT,
    ACTION_PAUSE_STOP,

    // Additional actions based on chords.
    ACTION_CHILD_LOCK,
    ACTION_FACTORY_RESET,

    // Additional features for ACK.
    ACTION_INITIATE_SETUP,
    ACTION_SUBMIT_LOGS
}
Action;

// Reads an action from the keypad.
static Action ReadKeypad(void);

// Duration of a long-process of a keypad key.
#define KEYPAD_LONGPRESS_MILLISECONDS 4000

// Convenience function to determine whether an action from the keypad represents a digit 0-9.
static bool IsAccumulateDigitAction(Action key);
static void AccumulateDigit(Action key);
static uint32_t AccumulatedDigitsToCookTimeSeconds(void);
static uint32_t AccumulatedDigitsToNumber(void);

// States for state machine.
static enum _State
{
    STATE_IDLE,
    STATE_CHILD_LOCKED,
    STATE_DOOR_CLOSED_TOO_LONG,
    STATE_ACCUMULATED_DIGITS,
    STATE_COOKING,
    STATE_COOKING_PAUSED,
    STATE_MAX
}
sg_state;

// Input for state machine transitions. These are sampled at the start of every pass through the
// main loop, and passed to the routine that processes the current state.
typedef struct _StateMachineInput
{
    Action UserInput : 8;
    unsigned DoorOpen : 1;
}
StateMachineInput;

// State machine functions. On each pass through the main loop, the routine corresponding to the
// current state is called. The routine examines input given to it in StateMachineInput, and determines
// whether to move to a new state.
typedef void (*StateRoutine)(const StateMachineInput* pData);

static void State_Idle(const StateMachineInput* pData);
static void State_ChildLocked(const StateMachineInput* pData);
static void State_AccumulatedDigits(const StateMachineInput* pData);
static void State_DoorClosedTooLong(const StateMachineInput* pData);
static void State_Cooking(const StateMachineInput* pData);
static void State_CookingPaused(const StateMachineInput* pData);

// Information about each state in the state machine. To eliminate the need for each state routine
// to replicate common functionality, flags in this table are used to automate some of the processing.
static struct _StateTableEntry
{
    StateRoutine ProcessStateRoutine;
    HardwareClockMode ClockMode : 2;
    bool ShouldHardwareBeCooking : 1;
    bool ShouldChildLockBeEngaged : 1;
    bool AckUserInitiatedOperationsAllowed : 1;
}
sg_stateTable[STATE_MAX] =
{
    //                                                  Turn cooking hardware on or off
    //                                                  |  Turn child lock on or off
    //                                                  |  |  Whether ACK user-initiated operations allowed
    //                                                  |  |  |
    //                                                  v  v  v
    { State_Idle             , HARDWARE_CLOCK_TIME    , 0, 0, 1 },
    { State_ChildLocked      , HARDWARE_CLOCK_TIME    , 0, 1, 0 },
    { State_DoorClosedTooLong, HARDWARE_CLOCK_TIME    , 0, 0, 1 },
    { State_AccumulatedDigits, HARDWARE_CLOCK_MESSAGE , 0, 0, 1 },
    { State_Cooking          , HARDWARE_CLOCK_MESSAGE , 1, 0, 0 },
    { State_CookingPaused    , HARDWARE_CLOCK_MESSAGE , 0, 0, 1 }
};

static void EnterCookingState(
    uint32_t requestedCookTimeSeconds,
    HardwarePowerLevel powerLevel,
    MicrowaveCookingMode cookingMode);

static void EnterDefrostingState(uint32_t ouncesTimesTen);
static void EnterPausedState(void);
static void EnterResumedState(void);

static void DisplayRemainingTime(uint32_t remainingSeconds);

// Digits accumulated on the keypad as the user enters a time or weight.
// There are exactly 6 of them, representing a time or countdown as HH:MM:SS.
static union
{
    // Used when accumulating user input from the keypad.
    struct
    {
        // Values 0-9.
        uint8_t Numbers[6];
        unsigned Count;
    }
    Accumulated;

    // Formatted for display on the clock.
    HardwareClockDisplay ClockDisplay;
}
sg_digits;

// A count of seconds in the cook time the user entered via the keypad.
static uint32_t sg_requestedCookTimeSeconds;

static MicrowaveCookingMode sg_cookingMode = MICROWAVE_COOKING_NONE;
static uint32_t sg_defrostOuncesTimesTen;

// Tracks cooking end time.
static uint64_t sg_cookEndTick;

// Tracks when cooking was paused. This is part of the mechanism that adjusts the end time when
// the user resumed cooking.
static uint64_t sg_pauseStartTick;

// Power level to use for cooking.
static HardwarePowerLevel sg_cookingPowerLevel;

// Tracks when the door was closed. Used to determine whether the door has been closed too long
// and so cooking can't be resumed or initiated.
static uint64_t sg_doorClosedStartTick;

// Call this only when the door is known to be closed.
static bool HasDoorBeenClosedTooLong(void);

// Pending factory reset, setup initiation, or ACK log submission.
typedef enum _UserInitiatedLifecycleOperation
{
    USER_INITIATED_LIFECYCLE_OPERATION_NONE,
    USER_INITIATED_LIFECYCLE_FACTORY_RESET,
    USER_INITIATED_LIFECYCLE_SUBMIT_LOGS,
    USER_INITIATED_LIFECYCLE_INITIATE_SETUP
}
UserInitiatedLifecycleOperation;

// This tracks the most recently user-initiated ACK operations -- factory reset, initiating setup,
// submitting logs. At most one such operation can be pending at any given time.
UserInitiatedLifecycleOperation sg_pendingUserInitiatedLifecycleOperation
    = USER_INITIATED_LIFECYCLE_OPERATION_NONE;

//
void setup(void)
{
    Hardware_SetClockDisplay(HARDWARE_CLOCK_OFF, NULL);

    // Start off in the right state.
    sg_state = Hardware_GetPersistedChildLock()
        ? STATE_CHILD_LOCKED
        : (Hardware_IsDoorOpen() ? STATE_IDLE : STATE_DOOR_CLOSED_TOO_LONG);
#ifdef IGNORE_DOOR_CLOSED_TOO_LONG
    if (STATE_DOOR_CLOSED_TOO_LONG == sg_state)
    {
        sg_state = STATE_IDLE;
    }
#endif

    // Initialize ACK functionality.
    Alexa_Setup();
}

//
void loop(void)
{
    StateMachineInput stateMachineInput;

    // This is used to track whether on this pass through the loop, an Alexa change report should be sent.
    // This happens only for state changes that are initiated via local control. Changes that are initiated
    // by Alexa directives are handled when calling ACK_CompleteDirectiveWithSuccess.
    enum _State oldState = sg_state;

    // Get inputs for state machine processing.
    stateMachineInput.DoorOpen = Hardware_IsDoorOpen();
    stateMachineInput.UserInput = ReadKeypad();

    if (stateMachineInput.DoorOpen)
    {
        sg_doorClosedStartTick = 0;
    }
    else if (0 == sg_doorClosedStartTick)
    {
        // Guard against somehow getting here so quickly after boot that the tick count is still 0.
        sg_doorClosedStartTick = ACK_GetTickCount64() + 1;
    }

    // Transition to new state based in input, if warranted.
    sg_stateTable[sg_state].ProcessStateRoutine(&stateMachineInput);

    // Process the outputs from the current state, assuming that the hardware is idempotent.
    Hardware_SetClockDisplay(sg_stateTable[sg_state].ClockMode, &sg_digits.ClockDisplay);

    if (sg_stateTable[sg_state].ShouldHardwareBeCooking)
    {
        Hardware_StartCooking(sg_cookingPowerLevel);
    }
    else
    {
        Hardware_StopCooking();
    }

    Hardware_PersistChildLock(sg_stateTable[sg_state].ShouldChildLockBeEngaged);

    // ACK processing.
    // Treat any transition to/from cooking state above as a local state change that needs a corresponding
    // Alexa change report to be sent.
    if ((sg_state != oldState) && ((STATE_COOKING == oldState) || (STATE_COOKING == sg_state)))
    {
        Alexa_SendChangeReportDueToLocalControl();
    }

    Alexa_Loop();
}

//
static void State_Idle(const StateMachineInput* pData)
{
    if (!pData->DoorOpen)
    {
        if (IsAccumulateDigitAction(pData->UserInput) && (ACTION_ACCUMULATE_0 != pData->UserInput))
        {
            sg_digits.Accumulated.Count = 0;
            AccumulateDigit(pData->UserInput);
            sg_state = STATE_ACCUMULATED_DIGITS;
        }
        else if (ACTION_CHILD_LOCK == pData->UserInput)
        {
            sg_state = STATE_CHILD_LOCKED;
        }
        else if (HasDoorBeenClosedTooLong())
        {
            sg_state = STATE_DOOR_CLOSED_TOO_LONG;
        }
    }
}

//
static void State_ChildLocked(const StateMachineInput* pData)
{
    if (!pData->DoorOpen && (ACTION_CHILD_LOCK == pData->UserInput))
    {
        sg_state = STATE_IDLE;
    }
}

static void State_DoorClosedTooLong(const StateMachineInput* pData)
{
    if (pData->DoorOpen)
    {
        sg_state = STATE_IDLE;
    }
    else if (ACTION_CHILD_LOCK == pData->UserInput)
    {
        sg_state = STATE_CHILD_LOCKED;
    }
}

//
static void State_AccumulatedDigits(const StateMachineInput* pData)
{
    if (pData->DoorOpen)
    {
        sg_state = STATE_IDLE;
    }
    else if (HasDoorBeenClosedTooLong())
    {
        sg_state = STATE_DOOR_CLOSED_TOO_LONG;
    }
    else if (IsAccumulateDigitAction(pData->UserInput))
    {
        AccumulateDigit(pData->UserInput);
    }
    else if (ACTION_START == pData->UserInput)
    {
        // We don't have a way to indicate desired power level from the keypad.
        EnterCookingState(
            AccumulatedDigitsToCookTimeSeconds(),
            HARDWARE_POWER_LEVEL_HIGH,
            MICROWAVE_COOKING_MODE_TIME_COOK);
    }
    else if (ACTION_DEFROST_WEIGHT == pData->UserInput)
    {
        // Need to pass ounces times ten, so multiply the value entered on the keypad by 10.
        EnterDefrostingState(10 * AccumulatedDigitsToNumber());
    }
    else if (ACTION_PAUSE_STOP == pData->UserInput)
    {
        sg_state = STATE_IDLE;
    }
}

static void EnterCookingState(
    uint32_t requestedCookTimeSeconds,
    HardwarePowerLevel powerLevel,
    MicrowaveCookingMode cookingMode)
{
    uint64_t now;

    sg_requestedCookTimeSeconds = requestedCookTimeSeconds;
    sg_cookingPowerLevel = powerLevel;
    sg_state = STATE_COOKING;
    sg_cookingMode = cookingMode;

    now = ACK_GetTickCount64();
    sg_cookEndTick = now + (1000 * (uint64_t)sg_requestedCookTimeSeconds);

    ACK_DEBUG_PRINT_I(
        "Entered cooking state; requested cook time %"PRIu32" seconds; "
        "now %"PRIu64" ticks; end %"PRIu64" ticks.",
        requestedCookTimeSeconds,
        now,
        sg_cookEndTick);
}

static void EnterDefrostingState(uint32_t ouncesTimesTen)
{
    // Defrosting means cooking for 25 seconds per ounce at medium power.
    EnterCookingState(
        25 * ouncesTimesTen / 10,
        HARDWARE_POWER_LEVEL_MEDIUM,
        MICROWAVE_COOKING_MODE_DEFROST_BY_WEIGHT);

    sg_defrostOuncesTimesTen = ouncesTimesTen;

    ACK_DEBUG_PRINT_I("Entered defrosting state; %"PRIu32" ounces times ten.", sg_defrostOuncesTimesTen);
}

static void EnterPausedState(void)
{
    sg_pauseStartTick = ACK_GetTickCount64();

    sg_state = STATE_COOKING_PAUSED;

    ACK_DEBUG_PRINT_I("Entered paused state; now %"PRIu64" ticks.", sg_pauseStartTick);
}

static void EnterResumedState(void)
{
    uint64_t now;

    now = ACK_GetTickCount64();

    // Adjust the cooking end time by the amount of time we were paused.
    sg_cookEndTick += now - sg_pauseStartTick;

    sg_state = STATE_COOKING;

    ACK_DEBUG_PRINT_I("Resumed cooking; now %"PRIu64" ticks; new end %"PRIu64" ticks.", now, sg_cookEndTick);
}

//
static void State_Cooking(const StateMachineInput* pData)
{
    uint64_t now = ACK_GetTickCount64();

    // Display remaining time.
    DisplayRemainingTime((uint32_t)((sg_cookEndTick - now) / 1000));

    // See whether cooking is finished.
    if (now >= sg_cookEndTick)
    {
        ACK_DEBUG_PRINT_I("Cooking completed; now %"PRIu64" ticks.", now);

        sg_state = STATE_IDLE;
        return;
    }

    if ((ACTION_PAUSE_STOP == pData->UserInput) || pData->DoorOpen)
    {
        EnterPausedState();
        return;
    }
}

//
static void State_CookingPaused(const StateMachineInput* pData)
{
    // Display remaining time.
    DisplayRemainingTime((uint32_t)((sg_cookEndTick - sg_pauseStartTick) / 1000));

    if (!pData->DoorOpen)
    {
        if (HasDoorBeenClosedTooLong())
        {
            sg_state = STATE_DOOR_CLOSED_TOO_LONG;
            return;
        }

        if (ACTION_START == pData->UserInput)
        {
            // Resume cooking.
            EnterResumedState();
            return;
        }

        if (ACTION_PAUSE_STOP == pData->UserInput)
        {
            sg_state = STATE_IDLE;
            return;
        }
    }
}

static void DisplayRemainingTime(uint32_t remainingSeconds)
{
    unsigned hours;
    unsigned minutes;
    unsigned seconds;
    unsigned i;

    hours = remainingSeconds / 3600;
    remainingSeconds %= 3600;

    minutes = remainingSeconds / 60;
    seconds = remainingSeconds % 60;

    _STATIC_ASSERT(sizeof(sg_digits.ClockDisplay.Chars) == 6);
    sg_digits.ClockDisplay.Chars[0] = '0' + (hours / 10);
    sg_digits.ClockDisplay.Chars[1] = '0' + (hours % 10);
    sg_digits.ClockDisplay.Chars[2] = '0' + (minutes / 10);
    sg_digits.ClockDisplay.Chars[3] = '0' + (minutes % 10);
    sg_digits.ClockDisplay.Chars[4] = '0' + (seconds / 10);
    sg_digits.ClockDisplay.Chars[5] = '0' + (seconds % 10);

    // Remove leading zeros.
    for (i = 0; i < 5; ++i)
    {
        if ('0' != sg_digits.ClockDisplay.Chars[i])
        {
            break;
        }

        sg_digits.ClockDisplay.Chars[i] = ' ';
    }

}

// Keystrokes are treated individually in all cases, except that the pause/stop key can act as
// a shift key for a chord, when both are held for 4 seconds.
//  pause/stop + 9 --> factory reset
//  pause/stop + 6 --> initiate setup
//  pause/stop + 3 --> submit logs
//  pause/stop + 0 --> child lock toggle
static Action ReadKeypad(void)
{
    static uint16_t s_previousKeypadState = 0;
    uint16_t keypadState;
    uint64_t s_keypadStateStartTick = 0;
    unsigned i;
    uint16_t bit;
    Action action = ACTION_NONE;

    keypadState = Hardware_GetKeypadState();

    if (keypadState == s_previousKeypadState)
    {
        if (keypadState)
        {
            // See whether the keypad state indicates a chord long-press.
            // If so, determine whether it's one of the chords we care about.
            if ((ACK_GetTickCount64() - s_keypadStateStartTick) >= KEYPAD_LONGPRESS_MILLISECONDS)
            {
                UserInitiatedLifecycleOperation ackOperation = USER_INITIATED_LIFECYCLE_OPERATION_NONE;

                switch (keypadState)
                {
                case HARDWARE_KEYPAD_KEY_PAUSE_STOP + HARDWARE_KEYPAD_KEY_0:
                    action = ACTION_CHILD_LOCK;
                    break;

                case HARDWARE_KEYPAD_KEY_PAUSE_STOP + HARDWARE_KEYPAD_KEY_3:
                    ackOperation = USER_INITIATED_LIFECYCLE_SUBMIT_LOGS;
                    break;

                case HARDWARE_KEYPAD_KEY_PAUSE_STOP + HARDWARE_KEYPAD_KEY_6:
                    ackOperation = USER_INITIATED_LIFECYCLE_INITIATE_SETUP;
                    break;

                case HARDWARE_KEYPAD_KEY_PAUSE_STOP + HARDWARE_KEYPAD_KEY_9:
                    ackOperation = USER_INITIATED_LIFECYCLE_FACTORY_RESET;
                    break;
                }

                // Only one user-initiated ACK operation can be pending at any given time, and they're
                // only allowed in certain states.
                if (sg_stateTable[sg_state].AckUserInitiatedOperationsAllowed
                    && (USER_INITIATED_LIFECYCLE_OPERATION_NONE == sg_pendingUserInitiatedLifecycleOperation))
                {
                    sg_pendingUserInitiatedLifecycleOperation = ackOperation;
                }

                // Reset keypad.
                s_previousKeypadState = 0;
            }
        }
    }
    else
    {
        // Something changed, such as a key going up or down. We act only on keys going down.
        bit = 1;

        _STATIC_ASSERT(sizeof(bit) == sizeof(keypadState));
        for (i = 0; i < (8 * sizeof(keypadState)); ++i)
        {
            if ((keypadState & bit) && !(s_previousKeypadState & bit))
            {
                // Found a key going down.
                _STATIC_ASSERT((HARDWARE_KEYPAD_KEY_0 == (1 << (ACTION_ACCUMULATE_0 - 1)))
                    && (HARDWARE_KEYPAD_KEY_9 == (1 << (ACTION_ACCUMULATE_9 - 1)))
                    && (HARDWARE_KEYPAD_KEY_START == (1 << (ACTION_START - 1)))
                    && (HARDWARE_KEYPAD_KEY_DEFROST_BY_WEIGHT == (1 << (ACTION_DEFROST_WEIGHT - 1)))
                    && (HARDWARE_KEYPAD_KEY_PAUSE_STOP == (1 << (ACTION_PAUSE_STOP - 1))));
                action = (Action)(i + 1);
                break;
            }

            bit <<= 1;
        }

        s_keypadStateStartTick = ACK_GetTickCount64();
        s_previousKeypadState = keypadState;
    }

    return action;
}

static bool IsAccumulateDigitAction(Action action)
{
    return (action >= ACTION_ACCUMULATE_0) && (action <= ACTION_ACCUMULATE_9);
}

static void AccumulateDigit(Action key)
{
    if (sg_digits.Accumulated.Count < sizeof(sg_digits.Accumulated.Numbers))
    {
        sg_digits.Accumulated.Numbers[sg_digits.Accumulated.Count++] = key - ACTION_ACCUMULATE_0;
    }
}

static uint32_t AccumulatedDigitsToCookTimeSeconds(void)
{
    unsigned hours = 0;
    unsigned minutes = 0;
    unsigned seconds = 0;

    _STATIC_ASSERT(sizeof(sg_digits.Accumulated.Numbers) == 6);
    switch (sg_digits.Accumulated.Count)
    {
    case 1:
        seconds = sg_digits.Accumulated.Numbers[0];
        break;
    case 2:
        seconds = (10 * sg_digits.Accumulated.Numbers[0]) + sg_digits.Accumulated.Numbers[1];
        break;
    case 3:
        minutes = sg_digits.Accumulated.Numbers[0];
        seconds = (10 * sg_digits.Accumulated.Numbers[1]) + sg_digits.Accumulated.Numbers[2];
        break;
    case 4:
        minutes = (10 * sg_digits.Accumulated.Numbers[0]) + sg_digits.Accumulated.Numbers[1];
        seconds = (10 * sg_digits.Accumulated.Numbers[2]) + sg_digits.Accumulated.Numbers[3];
        break;
    case 5:
        hours = sg_digits.Accumulated.Numbers[0];
        minutes = (10 * sg_digits.Accumulated.Numbers[1]) + sg_digits.Accumulated.Numbers[2];
        seconds = (10 * sg_digits.Accumulated.Numbers[3]) + sg_digits.Accumulated.Numbers[4];
        break;
    case 6:
        hours = (10 * sg_digits.Accumulated.Numbers[0]) + sg_digits.Accumulated.Numbers[1];
        minutes = (10 * sg_digits.Accumulated.Numbers[2]) + sg_digits.Accumulated.Numbers[3];
        seconds = (10 * sg_digits.Accumulated.Numbers[4]) + sg_digits.Accumulated.Numbers[5];
        break;
    }

    return (60 * 60 * (uint32_t)hours) + (60 * minutes) + seconds;
}

static uint32_t AccumulatedDigitsToNumber(void)
{
    uint32_t number = 0;
    unsigned i;

    for (i = 0; i < sg_digits.Accumulated.Count; ++i)
    {
        number = (10 * number) + sg_digits.Accumulated.Numbers[i];
    }

    return number;
}

static bool HasDoorBeenClosedTooLong(void)
{
    bool closedTooLong;

    // 10 minutes.
    closedTooLong = (ACK_GetTickCount64() - sg_doorClosedStartTick) >= (10 * 60 * 1000);
#ifdef IGNORE_DOOR_CLOSED_TOO_LONG
    closedTooLong = false;
#endif    

    return closedTooLong;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

// Code below here is added to tap into the existing microwave application to integrate ACK functionality.
// Code in Alexa.c calls these routines.
static bool IsUserInitiatedLifecycleOperationPending(UserInitiatedLifecycleOperation operation);
static MicrowaveError CanStartCooking(void);
static bool HaveCookingInfo(void);

// Returns a value indicating whether the device is "in use". We deem the device in use if cooking
// or paused.
bool Microwave_IsDeviceInUse(void)
{
    return (STATE_COOKING == sg_state) || (STATE_COOKING_PAUSED == sg_state);
}

// Erases user settings during a factory reset.
void Microwave_FactoryReset(void)
{
    static const HardwareClockDisplay c_resetDisplay = { { ' ', 'R', 'E', 'S', 'E', 'T' } };

    // Assume erasing user settings is synchronous.
    Hardware_SetClockDisplay(HARDWARE_CLOCK_FLASHING, &c_resetDisplay);
    Hardware_EraseUserSettings();
}

bool Microwave_DidUserInitiateFactoryReset(void)
{
    return IsUserInitiatedLifecycleOperationPending(USER_INITIATED_LIFECYCLE_FACTORY_RESET);
}

bool Microwave_DidUserInitiateAckSetup(void)
{
    return IsUserInitiatedLifecycleOperationPending(USER_INITIATED_LIFECYCLE_INITIATE_SETUP);
}

bool Microwave_DidUserInitiateAckSubmitLogs(void)
{
    return IsUserInitiatedLifecycleOperationPending(USER_INITIATED_LIFECYCLE_SUBMIT_LOGS);
}

static bool IsUserInitiatedLifecycleOperationPending(UserInitiatedLifecycleOperation operation)
{
    if (operation == sg_pendingUserInitiatedLifecycleOperation)
    {
        sg_pendingUserInitiatedLifecycleOperation = USER_INITIATED_LIFECYCLE_OPERATION_NONE;
        return true;
    }

    return false;
}

// Updates the connectivity LED and the clock based on ACK connectivity state.
void Microwave_UpdateConnectivityState(MicrowaveConnectivityState connectivityState)
{
    switch (connectivityState)
    {
    case MICROWAVE_CONNECTIVITY_CONNECTED:
        Hardware_SetConnectivityLamp(HARDWARE_CONNECTIVITY_SOLID);
        break;
    case MICROWAVE_CONNECTIVITY_NOT_CONNECTED:
        Hardware_SetConnectivityLamp(HARDWARE_CONNECTIVITY_OFF);
        break;
    case MICROWAVE_CONNECTIVITY_FACTORY_RESET:
    case MICROWAVE_CONNECTIVITY_ACK_SETUP:
    default:
        Hardware_SetConnectivityLamp(HARDWARE_CONNECTIVITY_BLINKING);
        break;
    }
}

MicrowaveError Microwave_StartCookingByTime(uint32_t timeSeconds, HardwarePowerLevel powerLevel)
{
    MicrowaveError error = CanStartCooking();
    if (MICROWAVE_NO_ERROR != error)
    {
        return error;
    }

    if (timeSeconds > MAX_COOK_DURATION_SECONDS)
    {
        return MICROWAVE_ERROR_COOK_TIME_TOO_LONG;
    }

    // This starts cooking by adjusting the state machine. The cooking state will be processed in the
    // next pass through the main loop. That will actually start cooking, and update the clock display
    // to reflect remaining cook time.
    EnterCookingState(timeSeconds, powerLevel, MICROWAVE_COOKING_MODE_TIME_COOK);

    return MICROWAVE_NO_ERROR;
}

// Starts defrosting by weight.
MicrowaveError Microwave_StartDefrostingByWeight(uint32_t ouncesTimesTen)
{
    MicrowaveError error = CanStartCooking();
    if (MICROWAVE_NO_ERROR != error)
    {
        return error;
    }

    if (ouncesTimesTen > (10 * MAX_WEIGHT_OUNCES))
    {
        return MICROWAVE_ERROR_COOK_TIME_TOO_LONG;
    }

    // This starts cooking by adjusting the state machine. The cooking state will be processed in the
    // next pass through the main loop. That will actually start cooking, and update the clock display
    // to reflect remaining cook time.
    EnterDefrostingState(ouncesTimesTen);

    return MICROWAVE_NO_ERROR;
}

MicrowaveError Microwave_PauseCooking(void)
{
    if (STATE_COOKING != sg_state)
    {
        return MICROWAVE_ERROR_NOT_COOKING;
    }

    EnterPausedState();

    return MICROWAVE_NO_ERROR;
}

MicrowaveError Microwave_ResumeCooking(void)
{
    if (STATE_COOKING_PAUSED != sg_state)
    {
        if (STATE_COOKING == sg_state)
        {
            return MICROWAVE_ERROR_ALREADY_COOKING;
        }

        if (STATE_DOOR_CLOSED_TOO_LONG == sg_state)
        {
            return MICROWAVE_ERROR_DOOR_CLOSED_TOO_LONG;
        }

        return MICROWAVE_ERROR_NOT_COOKING;
    }

    // We're actually paused, and resuming is allowed.
    EnterResumedState();

    return MICROWAVE_NO_ERROR;
}

MicrowaveError Microwave_AdjustCookTime(int32_t timeDeltaSeconds)
{
    uint64_t now;
    uint64_t newEndTick;

    // Allowed only if cooking or paused, and not in defrosting mode.
    if (!HaveCookingInfo())
    {
        return MICROWAVE_ERROR_NOT_COOKING;
    }

    if (MICROWAVE_COOKING_MODE_TIME_COOK != sg_cookingMode)
    {
        return MICROWAVE_ERROR_NOT_SUPPORTED_IN_CURRENT_MODE;
    }

    now = ACK_GetTickCount64();

    // Note: end result of this calculation is an unsigned value.
    newEndTick = sg_cookEndTick + (1000 * (uint64_t)timeDeltaSeconds);

    if (timeDeltaSeconds > 0)
    {
        // Lengthening cook time. Check for a value greater than the max cook time, taking into account
        // that theoretically, the adjusted end tick could overflow 64 bits.
        if ((newEndTick < sg_cookEndTick)
            || ((newEndTick - now) > (1000 * MAX_COOK_DURATION_SECONDS)))
        {
            return MICROWAVE_ERROR_COOK_TIME_TOO_LONG;
        }
    }
    else if (timeDeltaSeconds < 0)
    {
        // Adding a negative delta to the (always positive) end tick; no arithmetic overflow/underflow
        // is possible in this scenario (although we might have a negative number). Ensure that the
        // new end time is at least one second from now.
        if (((int64_t)newEndTick < 0) || (newEndTick < (now + 1000)))
        {
            newEndTick = now + 1000;
        }
    }

    sg_cookEndTick = newEndTick;

    return MICROWAVE_NO_ERROR;
}

bool Microwave_GetCookTimeInfo(uint32_t* pRemainingTimeSeconds, uint32_t* pRequestedDurationSeconds)
{
    uint64_t now;

    // Might not have cooking info (such as if we're not cooking and not paused).
    if (!HaveCookingInfo())
    {
        return false;
    }

    now = ACK_GetTickCount64();
    *pRemainingTimeSeconds = (sg_cookEndTick - now) / 1000;
    *pRequestedDurationSeconds = sg_requestedCookTimeSeconds;

    return true;
}

bool Microwave_GetCookingPowerLevelInfo(HardwarePowerLevel *pPowerLevel)
{
    // Might not have cooking info (such as if we're not cooking and not paused).
    if (!HaveCookingInfo())
    {
        return false;
    }

    *pPowerLevel = sg_cookingPowerLevel;
    return true;
}

bool Microwave_GetCookingWeightInfo(uint32_t* pOuncesTimesTen)
{
    // Might not have weight info, such as if we're not cooking and not paused, or not in
    // defrost-by-weight mode.
    if (!HaveCookingInfo() || (MICROWAVE_COOKING_MODE_DEFROST_BY_WEIGHT != sg_cookingMode))
    {
        return false;
    }

    *pOuncesTimesTen = sg_defrostOuncesTimesTen;
    return true;
}

MicrowaveCookingMode Microwave_GetCookingMode(void)
{
    return HaveCookingInfo() ? sg_cookingMode : MICROWAVE_COOKING_NONE;
}

// Determines whether cooking can start, based on the current state of the state machine.
// Returns an appropriate error code indicating why not, which can be used to send a reply to an
// Alexa start-cooking directive.
static MicrowaveError CanStartCooking(void)
{
    switch (sg_state)
    {
    case STATE_COOKING:
    case STATE_COOKING_PAUSED:
        return MICROWAVE_ERROR_ALREADY_COOKING;

    case STATE_DOOR_CLOSED_TOO_LONG:
        return MICROWAVE_ERROR_DOOR_CLOSED_TOO_LONG;

    case STATE_CHILD_LOCKED:
        return MICROWAVE_ERROR_CHILD_LOCK_ENGAGED;

    default:
        break;
    }

    if (Hardware_IsDoorOpen())
    {
        return MICROWAVE_ERROR_DOOR_OPEN;
    }

    return MICROWAVE_NO_ERROR;
}

static bool HaveCookingInfo(void)
{
    return (STATE_COOKING == sg_state) || (STATE_COOKING_PAUSED == sg_state);
}
