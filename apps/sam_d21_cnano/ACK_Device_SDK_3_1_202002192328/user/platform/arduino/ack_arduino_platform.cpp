/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

// Implementations of all platform-specific routines (declared in ack_user_platform.h) for Arduino.

#include "ack.h"
#include <Arduino.h>
#include "ack_crc32.h"
#include <stdarg.h>

// Arduino pins when the Alexa Connect Kit shield is attached to an Arduino Zero.
// Pins 0/1 are used implicitly by Arduino Serial1.
// We use pins 2 and 3 for host interrupt and reset, respectively.
#define ARDUINO_PIN_HOST_INTERRUPT 2
#define ARDUINO_PIN_RESET 3

// Pins for sample applications.
#ifdef ACK_SAMPLE_APPLICATIONS_LED_PIN
#define ARDUINO_PIN_SAMPLE_APPLICATIONS_LED 8
#endif
#ifdef ACK_SAMPLE_APPLICATIONS_GPIO_PIN_1
#define ARDUINO_PIN_SAMPLE_APPLICATIONS_GPIO_1 9
#endif
#ifdef ACK_SAMPLE_APPLICATIONS_GPIO_PIN_2
#define ARDUINO_PIN_SAMPLE_APPLICATIONS_GPIO_2 10
#endif    
#ifdef ACK_SAMPLE_APPLICATIONS_GPIO_PIN_3
#define ARDUINO_PIN_SAMPLE_APPLICATIONS_GPIO_3 11
#endif    

// Info we need to manage GPIO pins for the ACK Host MCU sample applications.
// Values in the array MUST be in the same order as the ACKHardwareKind_t enum.
static uint32_t sg_arduinoDigitalPins[] =
{
    ARDUINO_PIN_HOST_INTERRUPT,
    ARDUINO_PIN_RESET

#ifdef ACK_SAMPLE_APPLICATIONS_LED_PIN
    ,ARDUINO_PIN_SAMPLE_APPLICATIONS_LED
#endif    
#ifdef ACK_SAMPLE_APPLICATIONS_GPIO_PIN_1
    ,ARDUINO_PIN_SAMPLE_APPLICATIONS_GPIO_1
#endif
#ifdef ACK_SAMPLE_APPLICATIONS_GPIO_PIN_2
    ,ARDUINO_PIN_SAMPLE_APPLICATIONS_GPIO_2
#endif
#ifdef ACK_SAMPLE_APPLICATIONS_GPIO_PIN_3
    ,ARDUINO_PIN_SAMPLE_APPLICATIONS_GPIO_3
#endif
};

void ACKPlatform_Initialize()
{
    Serial.begin(115200);
    Serial1.begin(115200);

    pinMode(ARDUINO_PIN_HOST_INTERRUPT, INPUT_PULLUP);
    pinMode(ARDUINO_PIN_RESET, OUTPUT);

#ifdef ACK_SAMPLE_APPLICATIONS_LED_PIN
    pinMode(ARDUINO_PIN_SAMPLE_APPLICATIONS_LED, OUTPUT);
    digitalWrite(ARDUINO_PIN_SAMPLE_APPLICATIONS_LED, LOW);
#endif
#ifdef ACK_SAMPLE_APPLICATIONS_GPIO_PIN_1
    pinMode(ARDUINO_PIN_SAMPLE_APPLICATIONS_GPIO_1, OUTPUT);
    digitalWrite(ARDUINO_PIN_SAMPLE_APPLICATIONS_GPIO_1, LOW);
#endif
#ifdef ACK_SAMPLE_APPLICATIONS_GPIO_PIN_2
    pinMode(ARDUINO_PIN_SAMPLE_APPLICATIONS_GPIO_2, OUTPUT);
    digitalWrite(ARDUINO_PIN_SAMPLE_APPLICATIONS_GPIO_2, LOW);
#endif
#ifdef ACK_SAMPLE_APPLICATIONS_GPIO_PIN_3
    pinMode(ARDUINO_PIN_SAMPLE_APPLICATIONS_GPIO_3, OUTPUT);
    digitalWrite(ARDUINO_PIN_SAMPLE_APPLICATIONS_GPIO_3, LOW);
#endif
}

uint32_t ACKPlatform_TickCount(void)
{
    return millis();
}

void ACKPlatform_Delay(uint32_t milliseconds)
{
    delay(milliseconds);
}

void ACKPlatform_WriteDigitalPin(ACKHardwarePin_t pin, bool state)
{
    digitalWrite(sg_arduinoDigitalPins[pin], state ? HIGH : LOW);
}

bool ACKPlatform_ReadDigitalPin(ACKHardwarePin_t pin)
{
    return LOW != digitalRead(sg_arduinoDigitalPins[pin]);
}

void ACKPlatform_SetDigitalPinPWMLevel(ACKHardwarePin_t pin, uint8_t val)
{
    // Despite the name, analogWrite isn't about digital-to-analog conversion; it's used for PWM.
    analogWrite(sg_arduinoDigitalPins[pin], val);
}

bool ACKPlatform_Send(const void* buffer, size_t length, uint32_t timeoutMilliseconds)
{
    size_t i = 0;
    uint32_t startTime = millis();

    for (i = 0; i < length; ++i)
    {
        if ((millis() - startTime) >= timeoutMilliseconds)
        {
            return false;
        }

        Serial1.write(((const uint8_t*)buffer)[i]);
    }

    return true;
}

bool ACKPlatform_Receive(void* pBuffer, size_t length, uint32_t timeoutMilliseconds)
{
    size_t bytesRead = 0;
    uint32_t startTime = millis();

    // Note that the timeout check is carefully constructed to work even if millis() wraps.
    while ((bytesRead < length) && ((millis() - startTime) < timeoutMilliseconds))
    {
        if (Serial1.available())
        {
            ((uint8_t*)pBuffer)[bytesRead] = Serial1.read();
            bytesRead++;
        }
    }

    return bytesRead == length;
}

void ACKPlatform_DrainRead()
{
    while (Serial1.available())
    {
        Serial1.read();
    }
}

uint32_t ACKPlatform_CalculateCrc32(const void* pInput, size_t length)
{
    return ACK_CalculateCrc32(pInput, length);
}

void ACKPlatform_DebugPrint(const char* pMessage, ...)
{
    char buffer[512];

    va_list argptr;
    va_start(argptr, pMessage);
    vsnprintf(buffer, sizeof(buffer), pMessage, argptr);
    va_end(argptr);

    Serial.println(buffer);
}

#ifdef ACK_HOST_FIRMWARE_UPDATE

bool ACKPlatform_StartHostFirmwareUpdate(uint32_t size, uint32_t targetAddress, uint32_t crc32)
{
    return false;
}

bool ACKPlatform_SaveHostFirmwareUpdateChunk(uint32_t startOffset, const uint8_t* pData, uint32_t size)
{
    return false;
}

bool ACKPlatform_HostFirmwareUpdateSuccessfullyRetrieved(void)
{
    return false;
}

void ACKPlatform_HostFirmwareUpdateFailed(void)
{
}

void ACKPlatform_ApplyHostFirmwareUpdate(void)
{
}

#endif // def ACK_HOST_FIRMWARE_UPDATE
