/*******************************************************************************
 Non-secure entry source file for secure project

  Company:
    Microchip Technology Inc.

  File Name:
    nonsecure_entry.c

  Summary:
    Implements hooks for Non-secure application

  Description:
    This file is used to call specific API's in the secure world from the Non-Secure world.

 *******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END
#include <stdio.h>
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <string.h>

extern uint8_t temperatureVal;
extern uint8_t wrIndex;
extern uint8_t *eepromRxBuffer;
extern uint8_t secureUartTxBuffer[];
extern volatile bool isEEPROMRead;
extern volatile bool temperatureStatus;
extern volatile bool eepromTemperatureDataReadStatus;

extern void secureApp(void);


/* Non-secure callable (entry) function */
bool __attribute__((cmse_nonsecure_entry)) readTemperatureData(uint8_t *lcluartTxBuffer)
{
    bool lcltemperatureStatus = temperatureStatus;
    if(lcltemperatureStatus == true)
    {
        memset((char*)lcluartTxBuffer, 0x00, 100);
        memcpy(lcluartTxBuffer, secureUartTxBuffer, strlen((const char *)&secureUartTxBuffer[0]));
        temperatureStatus   = false;
    }
    return (lcltemperatureStatus);
}
void __attribute__((cmse_nonsecure_entry)) readEEPROMTemperatureDataReq(uint8_t *temperatureBuf)
{
    isEEPROMRead   = true;
    eepromRxBuffer = temperatureBuf;
    return ;
}
bool __attribute__((cmse_nonsecure_entry)) getEEPROMTemperatureDataReadStatus(uint8_t *LclWrIndex)
{
    bool lclEEPROMTempDataReadStatus    = eepromTemperatureDataReadStatus;
    eepromTemperatureDataReadStatus     = false;
    *LclWrIndex                         = wrIndex;
    return (lclEEPROMTempDataReadStatus);
}
void __attribute__((cmse_nonsecure_entry)) secureAppEntry(void)
{
    secureApp();
}