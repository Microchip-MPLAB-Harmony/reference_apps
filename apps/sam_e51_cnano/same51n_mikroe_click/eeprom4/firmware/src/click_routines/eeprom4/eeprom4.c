/*******************************************************************************
  EEPROM 4 source file

  Company:
    Microchip Technology Inc.

  File Name:
    eeprom4.c

  Summary:
  This file contains the "eeprom 4" functions

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
#include "eeprom4.h"
#include "click_routines/click_interface.h"
#include "string.h"

volatile bool isTransferDone = false;
/* This function will be called by SPI PLIB when transfer is completed */
void SPIEventHandler(uintptr_t context )
{
    /* De-assert the chip select */
    CLICK_EEPROM4_CS_Set();

    isTransferDone = true;
}

void eeprom4_Initialize (void)
{
    CLICK_EEPROM4_HOLD_Set();
    CLICK_EEPROM4_WP_Set();
    CLICK_EEPROM4_CS_Set();
    CLICK_EEPROM4_SPI_RegisterCallback(SPIEventHandler, (uintptr_t)NULL);
}

uint8_t eeprom4_read_status(void)
{
    uint8_t rx_data[2];
    uint8_t tx_data;
    
    /* Read the status of the internal write operation  */
    tx_data = EEPROM_CMD_RDSR;
    CLICK_EEPROM4_CS_Clear();
    CLICK_EEPROM4_SPI_WriteRead(&tx_data, 1, rx_data, 2);
    
    while(isTransferDone != true);
       
    isTransferDone = false;

    return rx_data[1];
}

void eeprom4_write_to_memory(uint32_t eepromMemAddr,uint8_t *eepromData, uint8_t eepromDatalen)
{
    uint8_t txData[ (4 + eepromDatalen)];
        
    txData[0] = EEPROM_CMD_WREN;
    CLICK_EEPROM4_CS_Clear();
    CLICK_EEPROM4_SPI_Write(txData, 1);
    
    while(isTransferDone != true);
       
    isTransferDone = false;
    
    //Copy the write command and the memory address to write to
    txData[0] = EEPROM_CMD_WRITE;
    txData[1] = (uint8_t)(eepromMemAddr>>16);
    txData[2] = (uint8_t)(eepromMemAddr>>8);
    txData[3] = (uint8_t)(eepromMemAddr);

    CLICK_EEPROM4_CS_Clear();
    
    memcpy(&txData[4], eepromData, eepromDatalen);
    CLICK_EEPROM4_SPI_Write(txData,4+eepromDatalen);

    while(isTransferDone != true);
       
    isTransferDone = false;
    
}

void eeprom4_read_from_memory(uint32_t eepromMemAddr,uint8_t *eepromDataOutput, uint8_t eepromDatalen)
{
    uint8_t txData[ 4 ];

    txData[0] = EEPROM_CMD_READ;
    txData[1] = (uint8_t)(eepromMemAddr>>16);
    txData[2] = (uint8_t)(eepromMemAddr>>8);
    txData[3] = (uint8_t)(eepromMemAddr);

    CLICK_EEPROM4_CS_Clear();
    CLICK_EEPROM4_SPI_WriteRead(txData, 4, eepromDataOutput, (4 + eepromDatalen));

    while(isTransferDone != true);
       
    isTransferDone = false;
}
// ------------------------------------------------------------------------- END

