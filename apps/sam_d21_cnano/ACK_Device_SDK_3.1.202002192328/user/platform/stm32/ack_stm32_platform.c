/*
 * Copyright 2018-2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#include "ack.h"
#include "ack_circularbuffer.h"
#include "ack_stm32_ota.h"
#include "ack_user_platform.h"
#include <inttypes.h>
#include "main.h"
#include <stdarg.h>

// Values in the array MUST be in the same order as the ACKHardwarePin_t enum.
static struct
{
    GPIO_TypeDef* Port;
    uint16_t Pin;
}
sg_stm32DigitalPins[] =
{
    { ACK_HOST_INTERRUPT_GPIO_Port, ACK_HOST_INTERRUPT_Pin },
    { ACK_MODULE_RESET_GPIO_Port, ACK_MODULE_RESET_Pin }
#ifdef ACK_SAMPLE_APPLICATIONS_LED_PIN
    ,{ ACK_SAMPLE_APPLICATIONS_LED_GPIO_Port, ACK_SAMPLE_APPLICATIONS_LED_Pin }
#endif
#ifdef ACK_SAMPLE_APPLICATIONS_GPIO_PIN_1
    ,{ ACK_SAMPLE_APPLICATIONS_GPIO_1_GPIO_Port, ACK_SAMPLE_APPLICATIONS_GPIO_1_Pin }
#endif
#ifdef ACK_SAMPLE_APPLICATIONS_GPIO_PIN_2
    ,{ ACK_SAMPLE_APPLICATIONS_GPIO_2_GPIO_Port, ACK_SAMPLE_APPLICATIONS_GPIO_2_Pin }
#endif    
#ifdef ACK_SAMPLE_APPLICATIONS_GPIO_PIN_3
    ,{ ACK_SAMPLE_APPLICATIONS_GPIO_3_GPIO_Port, ACK_SAMPLE_APPLICATIONS_GPIO_3_Pin }
#endif    
};

// uart1 is ack module communication channel
// uart2 is debug port
#define ACK_MODULE_UART huart1
#define ACK_DEBUG_UART huart2

extern UART_HandleTypeDef ACK_MODULE_UART;
extern UART_HandleTypeDef ACK_DEBUG_UART;

static volatile ITStatus sg_debugUartTxReady = RESET;
static volatile ITStatus sg_commsUartTxReady = RESET;
static ACKCircularBuffer_t sg_commsRxBuffer;
static uint8_t sg_commsRxByte;

static volatile ITStatus sg_debugUartError = RESET;
static volatile ITStatus sg_commsUartError = RESET;

static bool _StartCommsRead(void);

void ACKPlatform_Initialize(void)
{
#ifdef ACK_SAMPLE_APPLICATIONS_LED_PIN
    // Make sure the LED starts in an off state.
    ACKPlatform_WriteDigitalPin(ACK_HW_PIN_SAMPLE_APPLICATIONS_LED, false);
#endif
#ifdef ACK_SAMPLE_APPLICATIONS_GPIO_PIN_1
    ACKPlatform_WriteDigitalPin(ACK_HW_PIN_SAMPLE_APPLICATIONS_GPIO_1, false);
#endif
#ifdef ACK_SAMPLE_APPLICATIONS_GPIO_PIN_2
    ACKPlatform_WriteDigitalPin(ACK_HW_PIN_SAMPLE_APPLICATIONS_GPIO_2, false);
#endif    
#ifdef ACK_SAMPLE_APPLICATIONS_GPIO_PIN_3
    ACKPlatform_WriteDigitalPin(ACK_HW_PIN_SAMPLE_APPLICATIONS_GPIO_3, false);
#endif    

    ACK_InitializeCircularBuffer(&sg_commsRxBuffer);

    _StartCommsRead();
}

uint32_t ACKPlatform_TickCount(void)
{
    return HAL_GetTick();
}

void ACKPlatform_Delay(uint32_t milliseconds)
{
    HAL_Delay(milliseconds);
}

void ACKPlatform_WriteDigitalPin(ACKHardwarePin_t pin, bool state)
{
    HAL_GPIO_WritePin(
        sg_stm32DigitalPins[pin].Port,
        sg_stm32DigitalPins[pin].Pin,
        state ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

bool ACKPlatform_ReadDigitalPin(ACKHardwarePin_t pin)
{
    return GPIO_PIN_RESET != HAL_GPIO_ReadPin(sg_stm32DigitalPins[pin].Port, sg_stm32DigitalPins[pin].Pin);
}

void ACKPlatform_SetDigitalPinPWMLevel(ACKHardwarePin_t pin, uint8_t val)
{
    // This is a temporary solution to make code compile.
    // If val >= 128, the pin will be set, otherwise it will be reset.
    // Need to replace with an actual PWM implementation.
    HAL_GPIO_WritePin(
        sg_stm32DigitalPins[pin].Port,
        sg_stm32DigitalPins[pin].Pin,
        val >= 128 ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

bool ACKPlatform_Send(const void* pBuffer, size_t length, uint32_t timeoutMilliseconds)
{
    uint32_t t0;
    HAL_StatusTypeDef err;

    t0 = HAL_GetTick();

    err = HAL_UART_Transmit_IT(&ACK_MODULE_UART, (uint8_t*)pBuffer, length);
    if (HAL_OK != err)
    {
        ACK_DEBUG_PRINT_E("Unable to initiate transmit on comms uart (err=%u)", err);
        return false;
    }

    while ((sg_commsUartTxReady != SET) && (sg_commsUartError != SET))
    {
        if ((HAL_GetTick() - t0) >= timeoutMilliseconds)
        {
            ACK_DEBUG_PRINT_E("Timeout on comms uart (write)");
            return false;
        }
    }

    ITStatus errStatus = sg_commsUartError;
    sg_commsUartTxReady = RESET;
    sg_commsUartError = RESET;

    if (SET == errStatus)
    {
        ACK_DEBUG_PRINT_E("Error on comms uart (write)");
        return false;
    }

    return true;
}

bool ACKPlatform_Receive(void* pBuffer, size_t length, uint32_t timeoutMilliseconds)
{
    uint32_t t0;

    t0 = HAL_GetTick();

    while ((length > 0)
        && (RESET == sg_commsUartError)
        && ((HAL_GetTick() - t0) < timeoutMilliseconds))
    {
        uint8_t byte;
        if (!ACK_ReadFromCircularBuffer(&sg_commsRxBuffer, &byte))
        {
            continue;
        }

        *(uint8_t*)pBuffer = byte;
        pBuffer = (uint8_t*)pBuffer + 1;
        --length;
    }

    ITStatus errStatus = sg_commsUartError;
    sg_commsUartError = RESET;

    if (SET == errStatus)
    {
        ACK_DEBUG_PRINT_E("Error on comms uart (read)");
        return false;
    }

    if (length > 0)
    {
        ACK_DEBUG_PRINT_E("Timeout on comms uart (read)");
        return false;
    }

    return true;
}

static bool _StartCommsRead(void)
{
    HAL_StatusTypeDef err;

    err = HAL_UART_Receive_IT(&ACK_MODULE_UART, &sg_commsRxByte, 1);
    if (HAL_OK != err)
    {
        ACK_DEBUG_PRINT_E("Unable to initiate receive on comms UART (err=%u)", err)
        return false;
    }

    return true;
}

void ACKPlatform_DrainRead(void)
{
    uint8_t ignoredByte;

    while (ACK_ReadFromCircularBuffer(&sg_commsRxBuffer, &ignoredByte))
    {
        ;
    }
}

uint32_t ACKPlatform_CalculateCrc32(const void* pInput, size_t length)
{
    extern CRC_HandleTypeDef hcrc;

    HAL_CRCEx_Input_Data_Reverse(&hcrc, CRC_INPUTDATA_INVERSION_BYTE);
    HAL_CRCEx_Output_Data_Reverse(&hcrc, CRC_OUTPUTDATA_INVERSION_ENABLE);

    return HAL_CRC_Calculate(&hcrc, (uint32_t*)pInput, length) ^ 0xffffffff;
}

void ACKPlatform_DebugPrint(const char* pMessage, ...)
{
    char buffer[250];

    va_list argptr;
    va_start(argptr, pMessage);
    int count = vsnprintf(buffer, sizeof(buffer) - 2, pMessage, argptr);
    va_end(argptr);

    if (count >= 0)
    {
        buffer[count] = '\r';
        buffer[count + 1] = '\n';
        count += 2;

        if (HAL_OK == HAL_UART_Transmit_IT(&ACK_DEBUG_UART, (uint8_t*)buffer, count))
        {
            while ((sg_debugUartTxReady != SET) && (sg_debugUartError != SET))
            {
            }

            sg_debugUartTxReady = RESET;
            sg_debugUartError = RESET;
        }
    }
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *uartHandle)
{
    if (uartHandle == &ACK_MODULE_UART)
    {
        sg_commsUartTxReady = SET;
    }

    if (uartHandle == &ACK_DEBUG_UART)
    {
        sg_debugUartTxReady = SET;
    }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *uartHandle)
{
    if (uartHandle == &ACK_MODULE_UART)
    {
        ACK_InsertIntoCircularBuffer(&sg_commsRxBuffer, sg_commsRxByte);
        _StartCommsRead();
    }
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *uartHandle)
{
    if (uartHandle == &ACK_MODULE_UART)
    {
        sg_commsUartError = SET;
    }

    if (uartHandle == &ACK_DEBUG_UART)
    {
        sg_debugUartError = SET;
    }
}

#ifdef ACK_HOST_FIRMWARE_UPDATE

static uint32_t sg_otaSize;
static uint32_t sg_otaCrc32;

static void CheckFlashInErasedState(uint32_t address, uint32_t size, const char* pWhich);

bool ACKPlatform_StartHostFirmwareUpdate(uint32_t size, uint32_t targetAddress, uint32_t crc32)
{
    unsigned status;
    uint32_t errorAddress;

    sg_otaSize = size;
    sg_otaCrc32 = crc32;

    if (ACK_STM32_OTA_PRIMARY_PARTITION_START != targetAddress)
    {
        ACK_DEBUG_PRINT_E(
            "Host firmware update targets address %"PRIx32" but primary partition is at %"PRIx32".",
            targetAddress,
            ACK_STM32_OTA_PRIMARY_PARTITION_START);

        return false;
    }

    ACK_ASSERT(ACK_STM32_OTA_STAGING_PARTITION_SIZE == ACK_STM32_OTA_PRIMARY_PARTITION_SIZE);
    if (sg_otaSize > ACK_STM32_OTA_STAGING_PARTITION_SIZE)
    {
        ACK_DEBUG_PRINT_E(
            "Host firmware update of %"PRIu32" bytes is too large for partitions of %"PRIu32" bytes.",
            sg_otaSize,
            ACK_STM32_OTA_STAGING_PARTITION_SIZE);

        return false;
    }

    ACKStm32Ota_FlashBegin();

    status = ACKStm32Ota_FlashErase(
        ACK_STM32_OTA_STAGING_PARTITION_START / ACK_STM32_OTA_FLASH_PAGE_SIZE,
        ACK_STM32_OTA_STAGING_PARTITION_SIZE,
        &errorAddress);

    ACKStm32Ota_FlashEnd();

    if (0 != status)
    {
        ACK_DEBUG_PRINT_E(
            "Erasing Staging Partition (%"PRIu32" bytes at 0x%"PRIx32") failed at 0x%"PRIx32"; err %u.",
            ACK_STM32_OTA_STAGING_PARTITION_SIZE,
            ACK_STM32_OTA_STAGING_PARTITION_START,
            errorAddress,
            status);
        return false;
    }

    CheckFlashInErasedState(
        ACK_STM32_OTA_STAGING_PARTITION_START,
        ACK_STM32_OTA_STAGING_PARTITION_SIZE,
        "Erase staging partition");
    return true;
}

bool ACKPlatform_SaveHostFirmwareUpdateChunk(uint32_t startOffset, const uint8_t* pData, uint32_t size)
{
    uint32_t targetAddress;
    uint32_t unitCount;
    unsigned status;
    uint32_t errorAddress;

    ACKStm32Ota_FlashBegin();

    targetAddress = ACK_STM32_OTA_STAGING_PARTITION_START + startOffset;

    // The routine to write to flash takes a count of 16-bit words, not a byte count.
    unitCount = (size % 1) ? ((size + 1) / 2) : (size / 2);

    CheckFlashInErasedState(targetAddress, 2 * unitCount, "Save chunk");

    status = ACKStm32Ota_FlashWrite(targetAddress, pData, unitCount, &errorAddress);

    ACKStm32Ota_FlashEnd();

    if (0 != status)
    {
        ACK_DEBUG_PRINT_E(
            "Writing Staging Partition (%"PRIu32" bytes at 0x%"PRIx32") failed near 0x%"PRIx32"; err %u.",
            unitCount * 2,
            targetAddress,
            errorAddress,
            status);
        return false;
    }

    return true;
}

bool ACKPlatform_HostFirmwareUpdateSuccessfullyRetrieved(void)
{
    uint32_t crc32;
    ACKStm32OtaStatusPartition_t statusPartition;
    unsigned status;
    uint32_t errorAddress;

    // Check CRC.
    crc32 = ACKPlatform_CalculateCrc32((const void*)ACK_STM32_OTA_STAGING_PARTITION_START, sg_otaSize);
    if (crc32 != sg_otaCrc32)
    {
        ACK_DEBUG_PRINT_E(
            "Calculated OTA image CRC 0x%"PRIx32" does not match expected CRC 0x%"PRIx32".",
            crc32,
            sg_otaCrc32);

        return false;
    }

    // CRC is OK. Update the status partition to indicate that an update image is present.
    memset(&statusPartition, 0, sizeof(statusPartition));
    statusPartition.Signature1 = ACK_STM32_OTA_STATUS_PARTITION_SIGNATURE1;
    statusPartition.Signature2 = ACK_STM32_OTA_STATUS_PARTITION_SIGNATURE2;
    statusPartition.State = ACK_STM32_OTA_STATUS_PARTITION_STATE_UNAPPLIED_IMAGE;
    statusPartition.Crc32 = sg_otaCrc32;
    statusPartition.ImageStartAddress = ACK_STM32_OTA_PRIMARY_PARTITION_START;
    statusPartition.ImageSize = sg_otaSize;

    ACKStm32Ota_FlashBegin();

    status = ACKStm32Ota_FlashErase(
        ACK_STM32_OTA_STATUS_PARTITION_START / ACK_STM32_OTA_FLASH_PAGE_SIZE,
        ACK_STM32_OTA_STATUS_PARTITION_SIZE,
        &errorAddress);
    if (0 == status)
    {
        CheckFlashInErasedState(
            ACK_STM32_OTA_STATUS_PARTITION_START,
            ACK_STM32_OTA_STATUS_PARTITION_SIZE,
            "Erase status partition");

        ACK_STATIC_ASSERT(0 == (sizeof(ACKStm32OtaStatusPartition_t) % 1));
        status = ACKStm32Ota_FlashWrite(
            ACK_STM32_OTA_STATUS_PARTITION_START,
            &statusPartition,
            sizeof(ACKStm32OtaStatusPartition_t) / 2,
            &errorAddress);
        if (0 != status)
        {
            ACK_DEBUG_PRINT_E(
                "Writing Status Partition (%"PRIu32" bytes at 0x%"PRIx32") failed near 0x%"PRIx32"; err %u.",
                sizeof(ACKStm32OtaStatusPartition_t),
                ACK_STM32_OTA_STATUS_PARTITION_START,
                errorAddress,
                status);
        }
    }
    else
    {
        ACK_DEBUG_PRINT_E(
            "Erasing Status Partition (%"PRIu32" bytes at 0x%"PRIx32") failed at 0x%"PRIx32"; err %u.",
            ACK_STM32_OTA_STATUS_PARTITION_SIZE,
            ACK_STM32_OTA_STATUS_PARTITION_START,
            errorAddress,
            status);
    }

    ACKStm32Ota_FlashEnd();

    return 0 == status;
}

void ACKPlatform_HostFirmwareUpdateFailed(void)
{
    // No-op on this platform.
}

void ACKPlatform_ApplyHostFirmwareUpdate(void)
{
    // Does not return.
    HAL_NVIC_SystemReset();
}

static void CheckFlashInErasedState(uint32_t address, uint32_t size, const char* pWhich)
{
#if defined(ACK_DEBUG_PRINT_LEVEL) && (ACK_DEBUG_PRINT_LEVEL >= ACK_DEBUG_PRINT_LEVEL_WARNING)
    uint32_t i;
    volatile uint8_t* p;
    volatile uint8_t x;

    p = (volatile uint8_t*)address;

    for (i = 0; i < size; ++i)
    {
        x = p[i];
        if (0xff != x)
        {
            ACK_DEBUG_PRINT_C(
                "%s: flash at 0x%"PRIx32" is not in erased state; expected 0xff, got 0x%x.",
                pWhich,
                p + i,
                x);
            return;
        }
    }
#endif
}

#endif // def ACK_HOST_FIRMWARE_UPDATE
