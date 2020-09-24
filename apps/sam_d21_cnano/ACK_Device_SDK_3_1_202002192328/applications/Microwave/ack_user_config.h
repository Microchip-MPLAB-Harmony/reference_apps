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
    Configuration file for Alexa Connect Kit. Contains #defines to control its behavior,
    and to determine which features to include when building it.
*/

#ifndef __ACK_USER_CONFIG_H__
#define __ACK_USER_CONFIG_H__

// Debug print behavior. Leave ACK_DEBUG_PRINT_LEVEL undefined for no debug printing.
#define ACK_DEBUG_PRINT_LEVEL ACK_DEBUG_PRINT_LEVEL_INFO

// Size of buffer from which memory blocks are allocated during processing.
#define ACK_MEMORY_POOL_SIZE 1024

// Turn on to enable asserts in ack functions.
// Recommend leaving off in production to save space.
#define ACK_ENABLE_ASSERT

// Alexa capabilities and other ACK features to support.
#define ACK_LOGGING
#define ACK_MODULE_DIAGNOSTICS
#define ACK_COOKING
#define ACK_COOKING_TIME_CONTROLLER
#define ACK_TIME_HOLD_CONTROLLER

// Enable 64-bit tick counts for timing.
#define ACK_TICK64

// Prevent 'stock' empty implementations of some of the device-specific routine in ack_user_device.c
// so we can supply our own.
#define ACK_NO_ACKUSER_DOESUSERWANT
#define ACK_NO_ACKUSER_ONLIFECYCLESTATECHANGE
#define ACK_NO_ACKUSER_ERASEUSERSETTINGS

#endif // def __ACK_USER_CONFIG_H__
