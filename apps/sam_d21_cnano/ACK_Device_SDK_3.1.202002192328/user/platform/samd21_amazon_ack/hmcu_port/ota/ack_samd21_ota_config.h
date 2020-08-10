/*******************************************************************************
  Header File

  Company:
    Microchip Technology Inc.

  File Name:
    ack_samd21_ota_config.h

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

#ifndef __ACK_SAMD21_OTA_CONFIG_H__
#define __ACK_SAMD21_OTA_CONFIG_H__

#ifdef __cplusplus
extern "C"
{
#endif

// SAMD21G17D Memory size : 128K flash and 16K RAM

#define ACK_SAMD21_OTA_FLASH_BASE 0x00000000U
#define ACK_SAMD21_OTA_FLASH_SIZE 0x20000U
#define ACK_SAMD21_OTA_FLASH_PAGE_SIZE 0x40U
#define ACK_SAMD21_OTA_LOADER_PARTITION_SIZE 0xC00    // 3K 

#ifdef __cplusplus
}
#endif

#endif 
