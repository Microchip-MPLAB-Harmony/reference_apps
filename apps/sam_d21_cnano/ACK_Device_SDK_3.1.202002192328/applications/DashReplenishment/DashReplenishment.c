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
    ACK Host MCU sample application showing inventory reporting for Dash Replenishment Service.

    The sample application models a printer with the following consumable items:

    * Cyan, magenta, and yellow ink cartridges. The amount of ink remaining in an ink cartridge is reported
      by hardware as a percentage value.

      Each of the three cartridges corresponds to its own instance of Alexa.InventoryLevelSensor. When
      a change in any cartridge's ink level is detected, this application sends a Change Report event,
      including a Level property for each cartridge whose level changed. This application also reports
      the level of all cartridges in response to a State Report request.

    * Cyan, magenta, and yellow disposable print heads. These have a finite lifetime, whose absolute span
      is not known by the hardware, which can only report consumption of part of that span, as a percentage
      value. The hardware also knows when print heads have been replaced. (For this sample application the
      print heads are all replaced as a single unit.)

      Each of the three print heads corresponds to its own instance of Alexa.InventoryLevelUsageSensor. When
      incremental wear on a print head is detected, this application sends a consumption event for the
      corresponding instance of Alexa.InventoryLevelUsageSensor. When print heads are replaced, this
      application sends a replacement event for all instances of Alexa.InventoryLevelUsageSensor.

    * Paper. The hardware does not know and cannot report or respond to queries for the number of sheets
      of paper remaining. The printer does know when it consumes sheets and how many it has consumed.

      This corresponds to an instance of Alexa.InventoryUsageSensor. As paper is consumed, this application
      sends an inventory consumption event.

    This application also shows sending a Usage Report Metric. Metrics are sent when the application detects
    that ink has been consumed.

    Other Alexa capabilities are incidental to this sample application, but for illustrative purposes the
    application supports Power Controller.

    Power state and printer hardware is simulated by global variables. No physical hardware is required.
*/

#include "ack.h"
#include "ack_user_device.h"
#include "ack_dash_replenishment.h"
#include "ack_metrics.h"
#include "ack_power_controller.h"

// Indices for cartridge ink levels and print heads. Used in several data structures that are organized with
// one element per each of the three ink cartridges or print heads.
#define INDEX_CYAN 0
#define INDEX_MAGENTA 1
#define INDEX_YELLOW 2
#define INDEX_COLOR_COUNT 3

// Capability instance IDs. These are the values you used as the instance IDs when you configured
// the Alexa.InventoryLevelSensor, Alexa.InventoryUsageSensor, and Alexa.InventoryLevelUsageSensor
// capabilities for your device, on the ACK portal.
// There is no requirement that these be sequential. However for simplicity in this sample application
// we do model them that way.
#define INSTANCE_BASE 10
#define INSTANCE_INK_LEVEL_SENSOR_BASE (INSTANCE_BASE)
#define INSTANCE_PRINT_HEAD_LIFESPAN_SENSOR_BASE (2 * INSTANCE_BASE)
#define INSTANCE_OTHER_SENSOR_BASE (3 * INSTANCE_BASE)

#define INSTANCE_CYAN_INK_LEVEL_SENSOR (INSTANCE_INK_LEVEL_SENSOR_BASE + INDEX_CYAN)
#define INSTANCE_MAGENTA_INK_LEVEL_SENSOR (INSTANCE_INK_LEVEL_SENSOR_BASE + INDEX_MAGENTA)
#define INSTANCE_YELLOW_INK_LEVEL_SENSOR (INSTANCE_INK_LEVEL_SENSOR_BASE + INDEX_YELLOW)

#define INSTANCE_CYAN_PRINT_HEAD_LIFESPAN_SENSOR ((INSTANCE_PRINT_HEAD_LIFESPAN_SENSOR_BASE + INDEX_CYAN)
#define INSTANCE_MAGENTA_PRINT_HEAD_LIFESPAN_SENSOR (INSTANCE_PRINT_HEAD_LIFESPAN_SENSOR_BASE + INDEX_MAGENTA)
#define INSTANCE_YELLOW_PRINT_HEAD_LIFESPAN_SENSOR (INSTANCE_PRINT_HEAD_LIFESPAN_SENSOR_BASE + INDEX_YELLOW)

#define INSTANCE_PAPER_SENSOR (INSTANCE_OTHER_SENSOR_BASE)

// Application-specific property ordinals. These identify properties to the mechanism for creating
// outbound events.
// Note that these apply only for the power state, and ink level sensors. The print head and paper sensors
// don't know their absolute levels; incremental changes are reported as consumption events instead of
// properties.
#define PROPERTY_ORDINAL_POWER_STATE 0
#define PROPERTY_ORDINAL_INK_LEVEL_BASE 1
#define PROPERTY_ORDINAL_CYAN_INK_LEVEL (PROPERTY_ORDINAL_INK_LEVEL_BASE + INDEX_CYAN)
#define PROPERTY_ORDINAL_MAGENTA_INK_LEVEL (PROPERTY_ORDINAL_INK_LEVEL_BASE + INDEX_MAGENTA)
#define PROPERTY_ORDINAL_YELLOW_INK_LEVEL (PROPERTY_ORDINAL_INK_LEVEL_BASE + INDEX_YELLOW)

// Ink cartridge levels.
unsigned g_inkCartridgePercentagesRemaining[INDEX_COLOR_COUNT];

// Note: these *must* be in the order of INDEX_xxx.
const char* g_inkCartridgeLevelChangeMetrics[INDEX_COLOR_COUNT] =
{
    "CyanInkLevelChanged",
    "MagentaInkLevelChanged",
    "YellowInkLevelChanged"
};

// Represents the device's power on/off state, controlled via Power Controller.
bool g_powerState;

// Forward declarations.
void SendChangeReportIfInkLevelsChanged(void);
void SendEventsIfPrintHeadLifespansChanged(void);
void SendEventIfPaperConsumed(void);

bool AddPowerStateProperty(uint32_t propertyOrdinal, unsigned propertyFlags);
bool AddInkLevelProperty(uint32_t propertyOrdinal, unsigned propertyFlags);

// Simulated hardware.
void InitializeStateFromHardware(void);
void GetInkLevelsFromHardware(unsigned* pRemainingPercentages);
void GetPrintHeadConsumptionFromHardware(bool* pWasReplaced, unsigned* pPercentages);
unsigned GetPaperConsumptionFromHardware(void);

// Maps an Alexa capability in this application to a routine used to add the capability's properties
// when an outbound event is being built.
ACKPropertyTableEntry_t ACKUser_PropertyTable[] =
{
    { PROPERTY_ORDINAL_POWER_STATE, AddPowerStateProperty },
    { PROPERTY_ORDINAL_CYAN_INK_LEVEL, AddInkLevelProperty },
    { PROPERTY_ORDINAL_MAGENTA_INK_LEVEL, AddInkLevelProperty },
    { PROPERTY_ORDINAL_YELLOW_INK_LEVEL, AddInkLevelProperty },
    { 0, NULL }
};

// Called once, for one-time initialization.
void setup(void)
{
    // Initialize the ACK Host MCU Implementation Core.
    ACK_Initialize();

    // Application-specific initialization. For this sample application, read the state of the ink cartridges
    // from the hardware.
    InitializeStateFromHardware();
}

// Called over and over, for main processing.
void loop(void)
{
    // Process ACK-related events.
    ACK_Process();

    // Check for ink consumption by examining the ink cartridge sensor hardware. If any changed, send a
    // Change Report event.
    SendChangeReportIfInkLevelsChanged();

    // Check for consumption or replacement of the print head lifespans. Send events if consumption or
    // replacement occurred.
    SendEventsIfPrintHeadLifespansChanged();

    // Check for paper consumption. Send an event if paper has been consumed.
    SendEventIfPaperConsumed();
}

// We designate the device "in use" if power is on (such as from the most recent Power Controller
// directive, or the user having used a local power switch).
bool ACKUser_IsDeviceInUse(void)
{
    return g_powerState;
}

// Checks ink cartridge levels. If any ink levels have changed, sends Usage Report Metrics,
// and a Change Report.
void SendChangeReportIfInkLevelsChanged(void)
{
    unsigned newRemainingPercentages[INDEX_COLOR_COUNT];
    unsigned i;
    ACKPropertiesBits_t changedPropertiesBits = 0;

    // Retrieve current cartridge ink levels from hardware.
    GetInkLevelsFromHardware(newRemainingPercentages);

    // Compare ink cartridge levels retrieved from hardware against previously retrieved levels.
    // For each ink cartridge whose ink level changed:
    // (a) Send a usage metric.
    // (b) Track that we will need to add a property for it to a subsequent Change Report.
    // (c) Overwrite the previous level we're tracking, with the new level.
    for (i = 0; i < INDEX_COLOR_COUNT; ++i)
    {
        if (newRemainingPercentages[i] != g_inkCartridgePercentagesRemaining[i])
        {
            ACK_SendUsageReportCountMetric(
                g_inkCartridgeLevelChangeMetrics[i],
                g_inkCartridgePercentagesRemaining[i] - newRemainingPercentages[i]);

            changedPropertiesBits |= ACK_PROPERTY_BIT(PROPERTY_ORDINAL_INK_LEVEL_BASE + i);

            g_inkCartridgePercentagesRemaining[i] = newRemainingPercentages[i];
        }
    }

    // If any ink levels changed, send a Change Report now.
    if (changedPropertiesBits)
    {
        ACK_SendChangeReport(
            v3avs_capabilities_V3Alexa_Cause_CauseType_PERIODIC_POLL,
            changedPropertiesBits,
            0);
    }
}

// Checks print head lifespan consumption and replacement. If print heads were replaced, send inventory
// replaced events for all print head lifespan sensors. Otherwise, send consumption events for any print head
// whose lifespan has been incrementally consumed.
void SendEventsIfPrintHeadLifespansChanged(void)
{
#ifdef _DRS_LATER
    unsigned percentages[INDEX_COLOR_COUNT];
    bool printHeadsReplaced;
    unsigned i;
    ACKInventoryLevel_t inventoryLevel;

    GetPrintHeadConsumptionFromHardware(&printHeadsReplaced, percentages);

    inventoryLevel.Kind = ACK_INVENTORY_LEVEL_PERCENTAGE;
    inventoryLevel.Level.Percentage = percentages[i];

    for (i = 0; i < INDEX_COLOR_COUNT; ++i)
    {
        if (printHeadsReplaced)
        {
            // Print heads were replaced. Send replaced events for all print head lifespan sensors.
            ACK_SendDashReplenishmentLevelUsageReplacedEvent(
                INSTANCE_PRINT_HEAD_LIFESPAN_SENSOR_BASE + i,
                &inventoryLevel,
                0);
        }
        else
        {
            // Print heads not replaced. Send a consumption event for this sensor if some of its lifespan
            // was consumed.
            if (percentages[i])
            {
                ACK_SendDashReplenishmentLevelUsageConsumedEvent(
                    INSTANCE_PRINT_HEAD_LIFESPAN_SENSOR_BASE + i,
                    &inventoryLevel);

                send = true;
            }
        }
    }
#endif
}

// Checks whether sheets of paper have been consumed. If so, sends a consumption event.
void SendEventIfPaperConsumed(void)
{
#ifdef _DRS_LATER
    unsigned consumedSheetsCount;
    ACKInventoryLevel_t inventoryLevel;

    consumedSheetsCount = GetPaperConsumptionFromHardware();

    if (consumedSheetsCount)
    {
        inventoryLevel.Kind = ACK_INVENTORY_LEVEL_COUNT;
        inventoryLevel.Level.Count = consumedSheetsCount;

        ACK_SendDashReplenishmentUsageConsumedEvent(INSTANCE_PAPER_SENSOR, &inventoryLevel);
    }
#endif
}

// Updates our power on/off state. If the power state changed, causes a change report to be sent
// in addition to the directive response.
void ACKUser_OnPowerControllerDirective(int32_t correlationId, bool powerOn)
{
    bool changed;

    ACK_DEBUG_PRINT_I("Power controller directive: power %s", powerOn ? "ON" : "OFF");

    changed = (false == g_powerState) != (false == powerOn);

    g_powerState = powerOn;

    // If the power state actually changed, ensure that an Alexa change report is sent. In this application,
    // power controller directives are the only way the power state can change, and so this is the only
    // place where we worry about change reports. In a real-world device, a change report must be sent
    // whenever the state of the device changes *for any reason*, such as if the user interacts with
    // the device using physical controls on the device (switches, keypads, etc.).
    ACK_CompleteDirectiveWithSuccess(
        correlationId,
        ACK_PROPERTY_BIT(PROPERTY_ORDINAL_POWER_STATE),
        changed ? ACK_PROPERTY_BIT(PROPERTY_ORDINAL_POWER_STATE) : 0);
}

// State-report callback.
void ACKUser_OnReportStateDirective(int32_t correlationId)
{
    // This sends all properties demonstrated in this application.
    ACK_CompleteStateReportWithSuccess(correlationId);
}

// Routine to add an ink cartridge level to an outbound directive reply or state report. This is called
// from within ACK_Process().
bool AddInkLevelProperty(uint32_t propertyOrdinal, unsigned propertyFlags)
{
    // The time-of-sample field represents a Linux UTC time value. This is optional (and applicable
    // only in MCUs with a real-time clock).
    // The uncertainty field represents an error margin in milliseconds. We don't use this for the
    // ink sensors.
    ACKStateCommon_t common = { 0, 0, propertyFlags };
    ACKError_t error;
    ACKInventoryLevel_t inventoryLevel;
    unsigned inkCartridgeIndex;

    if ((propertyOrdinal < PROPERTY_ORDINAL_INK_LEVEL_BASE)
        || (propertyOrdinal >= (PROPERTY_ORDINAL_INK_LEVEL_BASE + INDEX_COLOR_COUNT)))
    {
        ACK_DEBUG_PRINT_E("Unknown ink level property, ordinal %u.", propertyOrdinal);
        return false;
    }

    inkCartridgeIndex = propertyOrdinal - PROPERTY_ORDINAL_INK_LEVEL_BASE;

    // Add a property for the ink cartridge level to the event.
    inventoryLevel.Kind = ACK_INVENTORY_LEVEL_PERCENTAGE;
    inventoryLevel.Level.Percentage = g_inkCartridgePercentagesRemaining[inkCartridgeIndex];

    error = ACK_AddInventoryLevelProperty(
        INSTANCE_INK_LEVEL_SENSOR_BASE + inkCartridgeIndex,
        &common,
        &inventoryLevel);

    if (ACK_NO_ERROR != error)
    {
        ACK_DEBUG_PRINT_E("Error %u adding ink level property to event.", error);
        return false;
    }

    return true;
}

// Routine to add the power state property to an outbound directive reply or state report event.
// This is called by ACK_Process().
bool AddPowerStateProperty(uint32_t propertyOrdinal, unsigned propertyFlags)
{
    // The time-of-sample field represents a Linux UTC time value. This is optional (and applicable
    // only in MCUs with a real-time clock). Leave as 0.
    // The uncertainty field represents an error margin in milliseconds. Set to 10 for
    // illustrative purposes.
    ACKStateCommon_t common = { 0, 10, propertyFlags };
    ACKError_t error;

    // Add power controller hardware state to the event.
    error = ACK_AddPowerControllerProperty(&common, g_powerState);

    if (ACK_NO_ERROR != error)
    {
        ACK_DEBUG_PRINT_E("Error %u adding power state property to event.", error);
        return false;
    }

    return true;
}

// For this sample application, the state of the (simulated) hardware is that each ink cartridge starts out
// at 100% remaining, and the device's power is off. In a real device, this would talk to real hardware
// to retrieve initial state.
void InitializeStateFromHardware(void)
{
    unsigned i;

    for (i = 0; i < INDEX_COLOR_COUNT; ++i)
    {
        g_inkCartridgePercentagesRemaining[i] = 100;
    }

    g_powerState = false;
}

// In a real device, ink consumption would be determined by sampling your actual level sensor hardware.
// Here, for illustrative purposes we deem 1% of cyan ink consumed every 10 seconds, 1% of magenta ink
// consumed every 20 seconds, and 1% of yellow ink consumed every 30 seconds.
void GetInkLevelsFromHardware(unsigned* pRemainingPercentages)
{
    static uint32_t previousTicks[INDEX_COLOR_COUNT] = {0};
    uint32_t currentTicks;
    uint32_t elapsedTicks;
    unsigned i;

    for (i = 0; i < INDEX_COLOR_COUNT; ++i)
    {
        pRemainingPercentages[i] = g_inkCartridgePercentagesRemaining[i];
    }

    currentTicks = ACKPlatform_TickCount();

    for (i = 0; i < INDEX_COLOR_COUNT; ++i)
    {
        if (0 == previousTicks[i])
        {
            previousTicks[i] = currentTicks;
        }
        else
        {
            elapsedTicks = currentTicks - previousTicks[i];

            if (elapsedTicks >= ((i + 1) * 10000))
            {
                if (pRemainingPercentages[i] > 0)
                {
                    ACK_DEBUG_PRINT_I(
                        "Ink #%u level decreasing from %u%% to %u%%.",
                        i,
                        pRemainingPercentages[i],
                        pRemainingPercentages[i] - 1);

                    --pRemainingPercentages[i];
                }
                else
                {
                    ACK_DEBUG_PRINT_I("Ink #%u is depleted.", i);
                }

                previousTicks[i] = currentTicks;
            }
        }
    }
}

// In a real device, print head lifespan consumption would be determined by sampling your actual usage sensor
// hardware. Here, for illustrative purposes we deem 1% of the cyan print head's lifespan consumed every
// 15 seconds, 1% of the magenta print head's lifespan consumed every 35 seconds, and and 1% of the
// yellow print head's lifespan consumed every 55 seconds.
// We deem all the print heads to have been replaced every 25 seconds.
void GetPrintHeadConsumptionFromHardware(bool* pWasReplaced, unsigned* pPercentages)
{
    static uint32_t previousTicksForConsumption[INDEX_COLOR_COUNT] = {0};
    static uint32_t previousTicksForReplacement = 0;
    uint32_t currentTicks;
    uint32_t elapsedTicks;
    unsigned i;

    *pWasReplaced = false;

    currentTicks = ACKPlatform_TickCount();

    // Check for consumption.
    for (i = 0; i < INDEX_COLOR_COUNT; ++i)
    {
        pPercentages[i] = 0;

        if (0 == previousTicksForConsumption[i])
        {
            previousTicksForConsumption[i] = currentTicks;
        }
        else
        {
            elapsedTicks = currentTicks - previousTicksForConsumption[i];

            if (elapsedTicks >= (15000 + (i * 20000)))
            {
                ACK_DEBUG_PRINT_I("One more percent of print head #%u consumed.", i);

                pPercentages[i] = 1;

                previousTicksForConsumption[i] = currentTicks;
            }
        }
    }

    // Check for replacement.
    if (0 == previousTicksForReplacement)
    {
        previousTicksForReplacement = currentTicks;
    }
    else
    {
        elapsedTicks = currentTicks - previousTicksForReplacement;

        if (elapsedTicks >= (25000))
        {
            ACK_DEBUG_PRINT_I("Print heads replaced.");

            *pWasReplaced = true;

            for (i = 0; i < INDEX_COLOR_COUNT; ++i)
            {
                pPercentages[i] = 100;
            }

            previousTicksForReplacement = currentTicks;
        }
    }
}

// In a real device, paper consumption would be tracked by watching print jobs. For this sample application,
// we deem 5 sheets of paper consumed every 45 seconds.
unsigned GetPaperConsumptionFromHardware(void)
{
    static uint32_t previousTicks = 0;
    uint32_t currentTicks;
    uint32_t elapsedTicks;
    unsigned sheetsConsumed = 0;

    currentTicks = ACKPlatform_TickCount();

    if (0 == previousTicks)
    {
        previousTicks = currentTicks;
    }
    else
    {
        elapsedTicks = currentTicks - previousTicks;

        if (elapsedTicks >= 45000)
        {
            sheetsConsumed = 5;

            previousTicks = currentTicks;
        }
    }

    return sheetsConsumed;
}
