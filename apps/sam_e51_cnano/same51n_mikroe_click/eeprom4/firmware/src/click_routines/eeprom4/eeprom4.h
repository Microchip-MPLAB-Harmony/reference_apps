/*******************************************************************************
  EEPROM 4 Header file

  Company:
    Microchip Technology Inc.

  File Name:
    eeprom4.h

  Summary:
  This file contains the "eeprom 4" function definitions
 
  Description:
 *******************************************************************************/
// DOM-IGNORE-BEGIN
/*
    (c) 2021 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/
// DOM-IGNORE-END
// ----------------------------------------------------------------------------

#ifndef EEPROM4_H
#define EEPROM4_H

#include "definitions.h"

#define EEPROM_CMD_WREN                     0x06
#define EEPROM_CMD_WRITE                    0x02
#define EEPROM_CMD_RDSR                     0x05
#define EEPROM_CMD_READ                     0x03

void eeprom4_Initialize(void);
uint8_t eeprom4_read_status(void);
void eeprom4_write_to_memory(uint32_t eepromMemAddr,uint8_t *eepromData, uint8_t eepromDatalen);
void eeprom4_read_from_memory(uint32_t eepromMemAddr,uint8_t *eepromDataOutput, uint8_t eepromDatalen);
#endif  