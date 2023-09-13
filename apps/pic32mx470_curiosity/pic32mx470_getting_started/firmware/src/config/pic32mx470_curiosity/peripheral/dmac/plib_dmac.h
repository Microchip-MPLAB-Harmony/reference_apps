/*******************************************************************************
  DMAC Peripheral Library Interface Header File

  Company:
    Microchip Technology Inc.

  File Name:
    plib_dmac.h

  Summary:
    DMAC peripheral library interface.

  Description:
    This file defines the interface to the DMAC peripheral library. This
    library provides access to and control of the DMAC controller.

  Remarks:
    None.

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

#ifndef PLIB_DMAC_H    // Guards against multiple inclusion
#define PLIB_DMAC_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <device.h>
#include <string.h>
#include <stdbool.h>
#include <sys/kmem.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: type definitions
// *****************************************************************************
// *****************************************************************************

typedef enum
{
    /* Data was transferred successfully. */
    DMAC_ERROR_NONE = 1,

    /* DMA address error. */
    DMAC_ERROR_ADDRESS_ERROR = 2

} DMAC_ERROR;

typedef enum
{
    /* No events yet. */
    DMAC_TRANSFER_EVENT_NONE = 0,

    /* Data was transferred successfully. */
    DMAC_TRANSFER_EVENT_COMPLETE = 1,

    /* Error while processing the request */
    DMAC_TRANSFER_EVENT_ERROR = 2,

    /* Half Data is transferred */
    DMAC_TRANSFER_EVENT_HALF_COMPLETE = 4

} DMAC_TRANSFER_EVENT;

typedef void (*DMAC_CHANNEL_CALLBACK) (DMAC_TRANSFER_EVENT status, uintptr_t contextHandle);
typedef struct
{
    bool inUse;

    /* Inidcates the error information for
       the last DMA operation on this channel */
    DMAC_ERROR errorInfo;

    /* Call back function for this DMA channel */
    DMAC_CHANNEL_CALLBACK  pEventCallBack;

    /* Client data(Event Context) that will be returned at callback */
    uintptr_t hClientArg;

} DMAC_CHANNEL_OBJECT;


#define     DMAC_CHANNEL_0            (0x0U)

#define     DMAC_CHANNEL_1            (0x1U)

#define     DMAC_CHANNEL_2            (0x2U)

#define     DMAC_CHANNEL_3            (0x3U)

#define     DMAC_NUMBER_OF_CHANNELS    (0x4U)

typedef uint32_t DMAC_CHANNEL;

typedef struct
{
    /* DCRCCON[CRCAPP]: The DMA transfers data from the source into the CRC engine and
     * writes the calculated CRC value to the destination when enabled
    */
    bool append_mode;

    /* DCRCCON[BITO]: The input data is bit reversed (reflected input) when enabled */
    bool reverse_crc_input;

    /* DCRCCON[PLEN]: Determines the length of the polynomial Example: 16, 32 */
    uint8_t polynomial_length;

    /* DCRCXOR: Polynomial for calculating the CRC */
    uint32_t polynomial;

    /* DRCRDATA: Input Non direct Seed for calculating the CRC */
    uint32_t non_direct_seed;

    /* The calculated CRC is bit reversed (reflected output) before final XOR */
    bool reverse_crc_output;

    /* The XOR value used to generate final CRC output */
    uint32_t final_xor_value;
} DMAC_CRC_SETUP;

// *****************************************************************************
// *****************************************************************************
// Section: DMAC API
// *****************************************************************************
// *****************************************************************************

void DMAC_Initialize( void );

void DMAC_ChannelCallbackRegister(DMAC_CHANNEL channel, const DMAC_CHANNEL_CALLBACK eventHandler, const uintptr_t contextHandle );

bool DMAC_ChannelTransfer( DMAC_CHANNEL channel, const void *srcAddr, size_t srcSize, const void *destAddr, size_t destSize, size_t cellSize);

bool DMAC_ChainTransferSetup( DMAC_CHANNEL channel, const void *srcAddr, size_t srcSize, const void *destAddr, size_t destSize, size_t cellSize);

void DMAC_ChannelPatternMatchSetup(DMAC_CHANNEL channel, uint8_t patternMatchData);
void DMAC_ChannelPatternMatchDisable(DMAC_CHANNEL channel);
void DMAC_ChannelDisable(DMAC_CHANNEL channel);

bool DMAC_ChannelIsBusy(DMAC_CHANNEL channel);

DMAC_TRANSFER_EVENT DMAC_ChannelTransferStatusGet(DMAC_CHANNEL channel);

void DMAC_ChannelCRCSetup( DMAC_CHANNEL channel, DMAC_CRC_SETUP CRCSetup );

void DMAC_CRCDisable( void );

uint32_t DMAC_CRCRead( void );

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
// DOM-IGNORE-END

#endif //PLIB_DMAC_H
