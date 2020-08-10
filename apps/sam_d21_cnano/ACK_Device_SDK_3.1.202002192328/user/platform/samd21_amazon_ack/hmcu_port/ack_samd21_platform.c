/*******************************************************************************
  Source File

  Company:
    Microchip Technology Inc.

  File Name:
    ack_samd21_platform.c

  Summary:

  Description:

 *******************************************************************************/
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#include "ack.h"
#include "ack_circularbuffer.h"
#include "ack_crc32.h"
#include "ack_samd21_ota.h"
#include "ack_user_platform.h"
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include "definitions.h" 
#define HIGH 1
#define LOW 0

volatile bool txThresholdEventReceived = false;

uint8_t rxBuffer[512];
volatile uint32_t nBytesRead = 0;

extern SYSTICK_OBJECT systick;

uint32_t SYSTICK_TickCounterGet ( void )
{
    return systick.tickCounter;
}

void usartReadEventHandler(SERCOM_USART_EVENT event, uintptr_t context )
{
    uint32_t nBytesAvailable = 0;
    
    if (event == SERCOM_USART_EVENT_READ_THRESHOLD_REACHED)
    {
        /* Receiver should atleast have the thershold number of bytes in the ring buffer */
        nBytesAvailable = SERCOM3_USART_ReadCountGet();

       nBytesRead += SERCOM3_USART_Read((uint8_t*)&rxBuffer[nBytesRead],nBytesAvailable); 
    }
}

void usartWriteEventHandler(SERCOM_USART_EVENT event, uintptr_t context )
{
    txThresholdEventReceived = true;
}

static uint32_t sg_samd21DigitalPins[] =
{
    SAMD_HOST_INTERRUPT_PIN,
    SAMD_MODULE_RESET_PIN
#ifdef ACK_SAMPLE_APPLICATIONS_LED_PIN
    ,SAMD_SAMPLE_APPLICATIONS_LED_PIN          //On board LED PB10
#endif
#ifdef ACK_SAMPLE_APPLICATIONS_GPIO_PIN_1
    ,SAMD_SAMPLE_APPLICATIONS_GPIO_PIN_1_PIN  //SAMD21 GPIO PA23
#endif
#ifdef ACK_SAMPLE_APPLICATIONS_GPIO_PIN_2
    ,SAMD_SAMPLE_APPLICATIONS_GPIO_PIN_2_PIN  //SAMD21 GPIO PA25
#endif    
#ifdef ACK_SAMPLE_APPLICATIONS_GPIO_PIN_3
    ,SAMD_SAMPLE_APPLICATIONS_GPIO_PIN_3_PIN  //SAMD21 GPIO PA24
#endif    
};

void ACKPlatform_Initialize(void)
{
#ifdef ACK_SAMPLE_APPLICATIONS_LED_PIN
    // Make sure the LED starts in an off state.
    ACKPlatform_WriteDigitalPin(ACK_HW_PIN_SAMPLE_APPLICATIONS_LED, LOW); 
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
    
    /* Register a callback for write events */
    SERCOM3_USART_WriteCallbackRegister(usartWriteEventHandler, (uintptr_t) NULL);
    
    SERCOM3_USART_WriteThresholdSet(127);
    
    SERCOM3_USART_WriteNotificationEnable(true, true);
    
    /* Register a callback for read events */
    SERCOM3_USART_ReadCallbackRegister(usartReadEventHandler, (uintptr_t) NULL); 
     
    SERCOM3_USART_ReadThresholdSet(1);
    
    memset(rxBuffer,0,512);
    
    SERCOM3_USART_ReadNotificationEnable(true, true);
}

uint32_t ACKPlatform_TickCount(void)
{
    return (1000 * SYSTICK_TickCounterGet())/SYSTICK_INTERRUPT_PERIOD_IN_US;
}

void ACKPlatform_Delay(uint32_t milliseconds)
{
    SYSTICK_DelayMs(milliseconds);
}

void ACKPlatform_WriteDigitalPin(ACKHardwarePin_t pin, bool state)
{
#ifdef ACK_SAMPLE_APPLICATIONS_LED_PIN
    if(pin == ACK_HW_PIN_SAMPLE_APPLICATIONS_LED)
        PORT_PinWrite(sg_samd21DigitalPins[pin],state ? LOW : HIGH);
    else
        PORT_PinWrite(sg_samd21DigitalPins[pin],state ? HIGH : LOW);
#else
    PORT_PinWrite(sg_samd21DigitalPins[pin],state ? HIGH : LOW);
#endif    
}

bool ACKPlatform_ReadDigitalPin(ACKHardwarePin_t pin)
{
#ifdef ACK_SAMPLE_APPLICATIONS_LED_PIN
    if(pin == ACK_HW_PIN_SAMPLE_APPLICATIONS_LED)
        //PORT_PinLatchRead is used to read pins configured as Output
        return HIGH != PORT_PinLatchRead(sg_samd21DigitalPins[pin]);    
    else 
        //PORT_PinRead is used to read pins configured as Input
        return LOW != PORT_PinRead(sg_samd21DigitalPins[pin]);
#else    
    return LOW != PORT_PinRead(sg_samd21DigitalPins[pin]);
#endif    
}

void ACKPlatform_SetDigitalPinPWMLevel(ACKHardwarePin_t pin, uint8_t val)
{
    // Need to replace with PWM
#ifdef ACK_SAMPLE_APPLICATIONS_LED_PIN    
    if(pin == ACK_HW_PIN_SAMPLE_APPLICATIONS_LED)
        PORT_PinWrite(sg_samd21DigitalPins[pin],val >= 128 ? LOW : HIGH);
    else
        PORT_PinWrite(sg_samd21DigitalPins[pin],val >= 128 ? HIGH : LOW);
#else
    PORT_PinWrite(sg_samd21DigitalPins[pin],val >= 128 ? HIGH : LOW);
#endif    
}

bool ACKPlatform_Send(const void* pBuffer, size_t length, uint32_t timeoutMilliseconds)
{
    uint32_t delayTicks = 0;
    uint32_t startTime = SYSTICK_TickCounterGet();     
    
    delayTicks=(1000 * timeoutMilliseconds)/SYSTICK_INTERRUPT_PERIOD_IN_US;
    
    SERCOM3_USART_Write((uint8_t*)pBuffer, length);
    
    while(txThresholdEventReceived != true){
        if ((SYSTICK_TickCounterGet() - startTime) >= delayTicks)
        {
            ACK_DEBUG_PRINT_D("\r\nH-TX ERROR");
            return false;
        }
    }
    
    txThresholdEventReceived = false;
    return true;
}

uint32_t lastreadbyte = 0;
bool ACKPlatform_Receive(void* pBuffer, size_t length, uint32_t timeoutMilliseconds)
{
    uint32_t delayTicks = 0;
    uint32_t startTime = SYSTICK_TickCounterGet();
    delayTicks=(1000 * timeoutMilliseconds)/SYSTICK_INTERRUPT_PERIOD_IN_US;
    
    while(nBytesRead < (length))
    {
        if ((SYSTICK_TickCounterGet() - startTime) >= delayTicks)
        {
            ACK_DEBUG_PRINT_D("H-RX ERROR");
            nBytesRead = 0;
            return false;
        }
    }   
    
    if(lastreadbyte != 0)
        memcpy((uint8_t*)pBuffer,(uint8_t*)&rxBuffer[lastreadbyte],length);
    else
       memcpy((uint8_t*)pBuffer,(uint8_t*)&rxBuffer[0],length); 
    
    while(SERCOM3_USART_ReadCountGet() != 0);
    
    ACKPlatform_Delay(50);
    if(nBytesRead > length){
        nBytesRead = nBytesRead - length;
        lastreadbyte = length;
    }else{

        nBytesRead = 0;  
        lastreadbyte = 0;
    }
    return true;
}

void ACKPlatform_DrainRead(void)
{
    while(SERCOM3_USART_ReadCountGet() > 0)
    {

    }
    nBytesRead = 0;
}

uint32_t ACKPlatform_CalculateCrc32(const void* pInput, size_t length)
{   
    return ACK_CalculateCrc32(pInput,length);
}
 
void ACKPlatform_DebugPrint(const char* pMessage, ...)
{
   
    char print_buffer[250];

    va_list argumentptr;
    va_start(argumentptr, pMessage);
    int count = vsnprintf(print_buffer, sizeof(print_buffer) - 2, pMessage, argumentptr);
    va_end(argumentptr);
    
    if (count >= 0)
    {
        print_buffer[count] = '\r';
        print_buffer[count + 1] = '\n';
        count += 2;

        SERCOM5_USART_Write((uint8_t*)print_buffer, count);
    }
  
}

#ifdef ACK_HOST_FIRMWARE_UPDATE

static uint32_t otaFirmwareSize;
static uint32_t otaFirmwareCrc32;

bool ACKPlatform_StartHostFirmwareUpdate(uint32_t size, uint32_t targetAddress, uint32_t crc32)
{
    unsigned status;

    otaFirmwareSize = size;
    otaFirmwareCrc32 = crc32;

    if (ACK_SAMD21_OTA_PRIMARY_PARTITION_START != targetAddress)
    {
        ACK_DEBUG_PRINT_E(
            "Host firmware update targets address %"PRIx32" but primary partition is at %"PRIx32".",
            targetAddress,
            ACK_SAMD21_OTA_PRIMARY_PARTITION_START);

        return false;
    }

    ACK_ASSERT(ACK_SAMD21_OTA_STAGING_PARTITION_SIZE == ACK_SAMD21_OTA_PRIMARY_PARTITION_SIZE);
    
    if (otaFirmwareSize > ACK_SAMD21_OTA_STAGING_PARTITION_SIZE)
    {
        ACK_DEBUG_PRINT_E(
            "Host firmware update of %"PRIu32" bytes is too large for partitions of %"PRIu32" bytes.",
            otaFirmwareSize,
            ACK_SAMD21_OTA_STAGING_PARTITION_SIZE);

        return false;
    }


    status = Samd21Ota_FlashErase(ACK_SAMD21_OTA_STAGING_PARTITION_START,ACK_SAMD21_OTA_STAGING_PARTITION_SIZE);


    if (0 != status)
    {
        ACK_DEBUG_PRINT_E(
            "Erasing Staging Partition (%"PRIu32" bytes at 0x%"PRIx32") failed at 0x%"PRIx32"; err %u.",
            ACK_SAMD21_OTA_STAGING_PARTITION_SIZE,
            ACK_SAMD21_OTA_STAGING_PARTITION_START,
            status);
        return false;
    }
    
    return true;
}

bool ACKPlatform_SaveHostFirmwareUpdateChunk(uint32_t startOffset, const uint8_t* pData, uint32_t size)
{
    uint32_t targetAddress;
    unsigned status;

    targetAddress = ACK_SAMD21_OTA_STAGING_PARTITION_START + startOffset;

    status = Samd21Ota_FlashWrite(targetAddress, pData, size);

    if (0 != status)
    {
        ACK_DEBUG_PRINT_E(
            "Writing Staging Partition (%"PRIu32" bytes at 0x%"PRIx32") failed near 0x%"PRIx32"; err %u.",
            size,
            targetAddress,
            status);
        return false;
    }

    return true;
}

bool ACKPlatform_HostFirmwareUpdateSuccessfullyRetrieved(void)
{
    uint32_t crc32;
    ACKSamd21OtaStatusPrtion statusPrtion;
    unsigned status;

    // Checking for  CRC.
    crc32 = ACKPlatform_CalculateCrc32((const void*)ACK_SAMD21_OTA_STAGING_PARTITION_START, otaFirmwareSize);
    if (crc32 != otaFirmwareCrc32)
    {
        ACK_DEBUG_PRINT_E(
            "Calculated OTA image CRC 0x%"PRIx32" does not match expected CRC 0x%"PRIx32".",
            crc32,
            otaFirmwareCrc32);
        return false;
    }

    // CRC is OK. Updating the status memory
    memset(&statusPrtion, 0, sizeof(statusPrtion));
    statusPrtion.ota_guardBytes = ACK_SAMD21_OTA_GUARD_BYTES;
    statusPrtion.ota_flashCmd = ACK_SAMD21_OTA_FLASH_CMD;
    statusPrtion.ota_status= ACK_SAMD21_OTA_RECEIVED_PENDING;
    statusPrtion.ota_firmwarCrc32 = otaFirmwareCrc32;
    statusPrtion.ota_firmwareStartAddress = ACK_SAMD21_OTA_PRIMARY_PARTITION_START;
    statusPrtion.ota_firmwarSize = otaFirmwareSize;

    status = Samd21Ota_FlashErase(ACK_SAMD21_OTA_STATUS_PARTITION_START ,
        ACK_SAMD21_OTA_STATUS_PARTITION_SIZE);
    if (0 == status)
    {
        ACK_STATIC_ASSERT(0 == (sizeof(ACKSamd21OtaStatusPrtion) % 1));
        
        status = Samd21Ota_FlashWrite(
            ACK_SAMD21_OTA_STATUS_PARTITION_START,
            &statusPrtion,
            sizeof(ACKSamd21OtaStatusPrtion));

        if (0 != status)
        {
            ACK_DEBUG_PRINT_E(
                "Writing Status Partition (%"PRIu32" bytes at 0x%"PRIx32") failed near 0x%"PRIx32"; err %u.",
                sizeof(ACKSamd21OtaStatusPrtion),
                ACK_SAMD21_OTA_STATUS_PARTITION_START,
                status);
        }
    }
    else
    {
        ACK_DEBUG_PRINT_E(
            "Erasing Status Partition (%"PRIu32" bytes at 0x%"PRIx32") failed at 0x%"PRIx32"; err %u.",
            ACK_SAMD21_OTA_STATUS_PARTITION_SIZE,
            ACK_SAMD21_OTA_STATUS_PARTITION_START,
            status);
    }

    return 0 == status;
}

void ACKPlatform_HostFirmwareUpdateFailed(void)
{
    
}

void ACKPlatform_ApplyHostFirmwareUpdate(void)
{
    ACK_DEBUG_PRINT_I("RESET ISSUED\r\n");
    NVIC_SystemReset();
}

#endif // def ACK_HOST_FIRMWARE_UPDATE
