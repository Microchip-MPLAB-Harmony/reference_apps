 /*******************************************************************************
  DRAM Example Source file

  Company:
    Microchip Technology Inc.

  File Name:
   dram_example.c

  Summary:
  This file contains the "dram" example
 *
  Description:
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
// ----------------------------------------------------------------------------

#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <device.h>
#include "../click_interface.h"
#include "dram.h"
#include "definitions.h"

#define DEMO_TEXT_MESSAGE            "Microchip"
#define STARTING_ADDRESS             0x012345
#define DRAM_DATA_LEN                sizeof(DEMO_TEXT_MESSAGE)


// DRAM CMD (1) + DRAM ADDR (3) + DRAM_DATA_LEN
uint8_t  txData[4 + DRAM_DATA_LEN];
uint8_t  rxData[4 + DRAM_DATA_LEN];

void dram_example_init ( void )
{
    uint8_t device_ID [4] = {DRAM_MANUFACTURER_ID};
    dram_init( );

    dram_reset_cmd ( );
    if ( false == dram_reset_cmd ( ) )
    {
        printf("Reset device - Failed\r\n");         //if failed
        while(true);
    }
    CLICK_DRAM_DelayMs  ( 100 );

    dram_read_id (device_ID);
    if ( false == dram_read_id (device_ID) )
    {
        printf("Check device ID - Failed.\r\n");      //if failed
        while (true);
    }

    dram_check_communication ( );
    if ( false == dram_check_communication ( ) )
    {
        printf("Check communication - Failed.\r\n");   //if failed
        while (true);
    }
    CLICK_DRAM_DelayMs  ( 100 );
}

void dram_example_task ( void )
{
    uint32_t dramMemAddr = STARTING_ADDRESS;

    printf ("\r\n Memory address: %.6lX\r\n", ( uint32_t ) STARTING_ADDRESS );

    //Copy the write command and the memory address to write to specified address
    //Write CMD Set
    txData[0] = DRAM_CMD_WRITE;
    txData[1] = (uint8_t) ( ( dramMemAddr >> 16 ) & 0xFF );
    txData[2] = (uint8_t) ( ( dramMemAddr >> 8) & 0xFF );
    txData[3] = (uint8_t) (dramMemAddr & 0xFF );

    memcpy ( &txData[4], DEMO_TEXT_MESSAGE, DRAM_DATA_LEN);
    dram_mem_write( txData, (4 + DRAM_DATA_LEN ));

    printf (" Write data: %s\r\n", &txData[4] );
    CLICK_DRAM_DelayMs  ( 100 );

    //Read CMD set
    txData[0] = DRAM_CMD_READ;
    txData[1] = (uint8_t) ( ( dramMemAddr >>16 ) & 0xFF );
    txData[2] = (uint8_t) ( ( dramMemAddr >>8) & 0xFF );
    txData[3] = (uint8_t) ( dramMemAddr & 0xFF );

    memset ( &rxData[4], 0, sizeof ( DRAM_DATA_LEN ) );
    dram_mem_write_read( txData, 4, rxData, (4 + DRAM_DATA_LEN));

    printf(" Read data: %s\r\n\n", &rxData[4] );
    CLICK_DRAM_DelayMs  ( 100 );

    if(memcmp(&txData[4], &rxData[4], DRAM_DATA_LEN) != 0)
    {
        printf("\r\nDRAM TEST Failed\r\n");
    }else{
        printf("\r\nDRAM TEST Passed\r\n");
    }
}

void dram_example ( void )
{
    dram_example_init( );
    dram_example_task( );
}

// ------------------------------------------------------------------------ END