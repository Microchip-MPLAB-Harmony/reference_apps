/*******************************************************************************
  DRAM click Source file

  Company
    Microchip Technology Inc.

  File Name
    dram.c

  Summary
    This file contains the "dram" functions

  Description

 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
    (c) 2024 Microchip Technology Inc. and its subsidiaries. You may use this
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

#include "dram.h"
#include "definitions.h"
#include <string.h>
#include "click_routines/click_interface.h"

/**
 * @brief Dummy data.
 * @details Definition of dummy data.
 */
#define DUMMY  0x00

uint8_t  dramTxData[4];

volatile bool isTransferDone = false;

/* This function will be called by SPI PLIB when transfer is completed */
void dram_spi_event_handler(uintptr_t context )
{
    CLICK_DRAM_CS_Set();
    isTransferDone = true;
}

void dram_init (void)
{
    CLICK_DRAM_CS_Set();
    CLICK_DRAM_SPI_RegisterCallback(dram_spi_event_handler, (uintptr_t)NULL);
}

void dram_mem_write (uint8_t *dramDataIn, uint8_t dramDatalen)
{
    if ( ( NULL == dramDataIn ) || ( dramDatalen  > DRAM_MAX_ADDRESS ) )
    {
        return ;
    }

    CLICK_DRAM_CS_Clear();
    CLICK_DRAM_SPI_Write ( dramDataIn, dramDatalen );

    while(isTransferDone != true);
    isTransferDone = false;
}

void dram_mem_write_read ( uint8_t *pTxData, uint8_t txSize, uint8_t *pRxData, uint8_t rxSize )
{
    if ( ( NULL == pTxData ) || ( NULL == pRxData ) || ( txSize > DRAM_MAX_ADDRESS ) )
    {
        return ;
    }

    CLICK_DRAM_CS_Clear();
    CLICK_DRAM_SPI_WriteRead(pTxData, txSize, pRxData, rxSize);

    while(isTransferDone != true);
    isTransferDone = false;
}

bool dram_read_id ( uint8_t *device_id )
{
    if ( NULL == device_id )
    {
        return DRAM_ERROR;
    }
    uint8_t data_buf[ 4 ] = { 0 };
    data_buf[ 0 ] = DRAM_CMD_READ_ID;
    data_buf[ 1 ] = DUMMY;
    data_buf[ 2 ] = DUMMY;
    data_buf[ 3 ] = DUMMY;

    CLICK_DRAM_CS_Clear();
    bool error_flag = CLICK_DRAM_SPI_WriteRead(data_buf, 4, device_id, 8);

    while(isTransferDone != true);
    isTransferDone = false;

    return error_flag;
}

bool dram_check_communication (  )
{
    uint8_t device_id[ 8 ] = { 0 };

    if ( DRAM_OK == dram_read_id ( device_id ) )
    {
        if ( DRAM_MANUFACTURER_ID == device_id[ 4 ] )
        {
            return DRAM_OK;
        }
    }
    return DRAM_ERROR;
}

bool dram_reset_cmd (  )
{
    dramTxData [0] = DRAM_CMD_RESET_ENABLE;

    CLICK_DRAM_CS_Clear();
    bool error_flag = CLICK_DRAM_SPI_Write( dramTxData, 1 );

    while(isTransferDone != true);
    isTransferDone = false;

    dramTxData [0] = DRAM_CMD_RESET;

    error_flag |=  CLICK_DRAM_SPI_Write( dramTxData, 1 );

    while(isTransferDone != true);
    isTransferDone = false;

    return error_flag;
}
// ------------------------------------------------------------------------- END