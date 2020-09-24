/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

/*
    Declares functions that must be implemented on every platform, in a platform-specific way.
    Actual definitions are in platform-specific directories under the user directory.

    Functions declared in this file are not typically called directly. The rest of the code in the
    Alexa Connect Kit itself calls these functions, which you implement in order to provide platform-specific
    functionality for your device's Host MCU.
*/

#ifndef __ACK_USER_PLATFORM_H__
#define __ACK_USER_PLATFORM_H__

#include "ack_user_config.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// Represents the piece of hardware to use when reading or writing a pin with ACKPlatform_ReadDigitalPin
// and ACKPlatform_WriteDigitalPin.
typedef enum _ACKHardwarePin_t
{
    ACK_HW_PIN_HOST_INTERRUPT,
    ACK_HW_PIN_MODULE_RESET

    // Hardware used in the sample applications.
    // Use #define in ack_user_config.h to include support.
#ifdef ACK_SAMPLE_APPLICATIONS_LED_PIN
    // For MCUs on boards that have a built-in LED, this GPIO pin should control that.
    // For bare MCUs or boards that don't have a built-in LED, the user will have to connect an LED
    // to this pin.
    ,ACK_HW_PIN_SAMPLE_APPLICATIONS_LED
#endif
#ifdef ACK_SAMPLE_APPLICATIONS_GPIO_PIN_1
    ,ACK_HW_PIN_SAMPLE_APPLICATIONS_GPIO_1
#endif
#ifdef ACK_SAMPLE_APPLICATIONS_GPIO_PIN_2
    ,ACK_HW_PIN_SAMPLE_APPLICATIONS_GPIO_2
#endif
#ifdef ACK_SAMPLE_APPLICATIONS_GPIO_PIN_3
    ,ACK_HW_PIN_SAMPLE_APPLICATIONS_GPIO_3
#endif
}
ACKHardwarePin_t;

// Initializes the Alexa Connect Kit platform-specific implementation.
// Your implementation should set up UARTs, GPIO pins, and similar resources needed by the
// implementations of rest of the ACKPlatform_Xxx functions.
void ACKPlatform_Initialize(void);

// Retrieves a tick count in milliseconds that can be used for timing.
uint32_t ACKPlatform_TickCount(void);

// Delays by a number of milliseconds.
void ACKPlatform_Delay(uint32_t milliseconds);

// Changes the state of a GPIO pin.
void ACKPlatform_WriteDigitalPin(ACKHardwarePin_t pin, bool state);

// Reads the state of a GPIO pin.
bool ACKPlatform_ReadDigitalPin(ACKHardwarePin_t pin);

// Set PWM level of digital pin.
void ACKPlatform_SetDigitalPinPWMLevel(ACKHardwarePin_t pin, uint8_t val);

// Writes data to the Alexa Connect Kit connectivity module.
// Your implementation should send the given data on the UART connected to the Alexa Connect Kit
// connectivity module.
// Returns a Boolean value indicating whether all the data was sent successfully.
bool ACKPlatform_Send(const void* pBuffer, size_t length, uint32_t timeoutMilliseconds);

// Reads data from the Alexa Connect Kit connectivity module.
// Your implementation should read data from the UART connected to the Alexa Connect Kit connectivity module.
// Returns a Boolean value indicating whether all the data was sent successfully within the given
// timeout period.
bool ACKPlatform_Receive(void* pBuffer, size_t length, uint32_t timeoutMilliseconds);

// Throws away data waiting to be received from the Alexa Connect Kit connectivity module.
// Your implementation should read data from the UART connected to the Alexa Connect Kit connectivity module,
// until there is no more such data remaining.
void ACKPlatform_DrainRead(void);

// Calculates a 32-bit CRC.
// This is a platform-specific function because some MCUs have hardware assist for CRC calculation,
// but note that your implementation must use the same CRC algorithm as is used by the Alexa Connect Kit
// connectivity module itself. See the implementation in ack_arduino_platform.cpp for more information.
uint32_t ACKPlatform_CalculateCrc32(const void* pInput, size_t length);

// Writes messages to a platform-specific debug output.
// Your implementation should format the message and send it to a platform-specific output,
// for example a debug port or UART to which a serial monitor is attached.
void ACKPlatform_DebugPrint(const char* pMessage, ...);

#ifdef ACK_HOST_FIRMWARE_UPDATE

#define ACK_HOST_FIRMWARE_UPDATE_MAX_DEVICE_TYPE_STRING_LENGTH 16

// Value for ACKHostUpdateImageHeader_t Signature. Represents ASCII 'OTA@' in hex.
#define ACK_HOST_FIRMWARE_UPDATE_IMAGE_HEADER_SIGNATURE 0x4041544f

// Header used in the stock Over-the-Air update solution. This header is created by hex2ota.py.
typedef struct _ACKHostFirmwareUpdateImageHeader_t
{
    // Must match ACK_HOST_UPDATE_IMAGE_HEADER_SIGNATURE.
    uint32_t Signature;

    // Device type. This is used to ensure that a host update image is actually targeting the right product.
    // NOTE: not nul-terminated.
    char DeviceType[ACK_HOST_FIRMWARE_UPDATE_MAX_DEVICE_TYPE_STRING_LENGTH];

    // The address in flash memory where the host update image is to be installed. This can be used as a
    // sanity check in your implementation, i.e., if this address doesn't match the base flash address
    // in your MCU, then the image won't possibly be able to run successfully.
    uint32_t TargetAddress;

    // Size in bytes of the host update image (not including this header).
    uint32_t Size;

    // CRC32 of the host update image (not including this header).
    uint32_t Crc32;
}
ACKHostFirmwareUpdateImageHeader_t;

// Prepare to receive and save a firmware update.
// Return a boolean indicating success or failure.
bool ACKPlatform_StartHostFirmwareUpdate(uint32_t size, uint32_t targetAddress, uint32_t crc32);

// Save a chunk of the firmware update.
// Return a boolean indicating success or failure.
bool ACKPlatform_SaveHostFirmwareUpdateChunk(uint32_t startOffset, const uint8_t* pData, uint32_t size);

// Finish successful reception of a firmware update. Your implementation should perform a CRC check.
// Return a boolean indicating success or failure. Do not reboot the MCU here; in the success case,
// ACKPlatform_ApplyHostFirmwareUpdate is called on a future pass through the main loop, when the device is
// not in use.
bool ACKPlatform_HostFirmwareUpdateSuccessfullyRetrieved(void);

// Clean up after a failed host firmware update download.
void ACKPlatform_HostFirmwareUpdateFailed(void);

// Apply the update, such as by rebooting the MCU.
void ACKPlatform_ApplyHostFirmwareUpdate(void);

#endif // def ACK_HOST_FIRMWARE_UPDATE

#ifdef __cplusplus
}
#endif

#endif // def __ACK_USER_PLATFORM_H__
