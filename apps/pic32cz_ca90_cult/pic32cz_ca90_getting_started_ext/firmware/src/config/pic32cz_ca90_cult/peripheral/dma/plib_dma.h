/*******************************************************************************
  DMAC Peripheral Library Interface Header File

  Company:
    Microchip Technology Inc.

  File Name:
    plib_dma.h

  Summary:
    DMA peripheral library interface.

  Description:
    This file defines the interface to the DMAC peripheral library. This
    library provides access to and control of the DMAC controller.

  Remarks:
    None.

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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

#ifndef PLIB_DMA_H    // Guards against multiple inclusion
#define PLIB_DMA_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

/*  This section lists the other files that are included in this file.
*/
#include <device.h>
#include <string.h>
#include <stdbool.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

typedef enum
{
    /* DMA Channel 0 */
    DMA_CHANNEL_0 = 0,
} DMA_CHANNEL;

typedef uint32_t DMA_TRANSFER_EVENT;

/* Block was transferred successfully. */
#define DMA_TRANSFER_EVENT_BLOCK_TRANSFER_COMPLETE          (0x01U)

/* Error while processing the request */
#define DMA_TRANSFER_EVENT_ERROR                            (0x02U)

/* An start trigger event has been detected and the block transfer has started */
#define DMA_TRANSFER_EVENT_START_DETECTED                   (0x04U)

/* An abort trigger event has been detected and the DMA transfer has been aborted */
#define DMA_TRANSFER_EVENT_TRANSFER_ABORTED                 (0x08U)

/* A cell transfer has been completed (CSZ bytes has been transferred) */
#define DMA_TRANSFER_EVENT_CELL_TRANSFER_COMPLETE           (0x10U)

/* A half block transfer has been completed */
#define DMA_TRANSFER_EVENT_HALF_BLOCK_TRANSFER_COMPLETE     (0x20U)

/* A link list done event has been completed */
#define DMA_TRANSFER_EVENT_LINKED_LIST_TRANSFER_COMPLETE    (0x40U)

typedef uint32_t DMA_INT;

#define DMA_INT_START_DETECTED								(DMA_CHINTF_SD_Msk)
#define DMA_INT_TRANSFER_ABORT								(DMA_CHINTF_TA_Msk)
#define DMA_INT_CELL_TRANSFER_COMPLETE						(DMA_CHINTF_CC_Msk)
#define DMA_INT_BLOCK_TRANSFER_COMPLETE						(DMA_CHINTF_BC_Msk)
#define DMA_INT_BLOCK_HALF_TRANSFER_COMPLETE				(DMA_CHINTF_BH_Msk)
#define DMA_INT_LINKED_LIST_DONE							(DMA_CHINTF_LL_Msk)
#define DMA_INT_WRITE_ERROR									(DMA_CHINTF_WRE_Msk)
#define DMA_INT_READ_ERROR									(DMA_CHINTF_RDE_Msk)

typedef enum
{
    /* Length of pattern match is 1 byte */
    DMA_PATTERN_MATCH_LEN_1BYTE,

    /* Length of pattern match is 2 bytes */
    DMA_PATTERN_MATCH_LEN_2BYTE,
}DMA_PATTERN_MATCH_LEN;


typedef uint32_t DMA_CHANNEL_CONFIG;

typedef void (*DMA_CHANNEL_CALLBACK) (DMA_TRANSFER_EVENT event, uintptr_t contextHandle);

void DMA_Initialize( void );
bool DMA_ChannelTransfer( DMA_CHANNEL channel, const void *srcAddr, const void *destAddr, size_t blockSize );
void DMA_ChannelCallbackRegister( DMA_CHANNEL channel, const DMA_CHANNEL_CALLBACK callback, const uintptr_t context );
bool DMA_ChannelIsBusy ( DMA_CHANNEL channel );
void DMA_ChannelDisable ( DMA_CHANNEL channel );
void DMA_ChannelEnable ( DMA_CHANNEL channel );
uint32_t DMA_ChannelGetTransferredCount( DMA_CHANNEL channel );
void DMA_ChannelInterruptEnable ( DMA_CHANNEL channel, DMA_INT intSources );
void DMA_ChannelInterruptDisable ( DMA_CHANNEL channel, DMA_INT intSources );
DMA_INT DMA_ChannelInterruptFlagsGet ( DMA_CHANNEL channel );
void DMA_ChannelPatternMatchSetup ( DMA_CHANNEL channel, DMA_PATTERN_MATCH_LEN patternLen, uint16_t matchData );
void DMA_ChannelPatternMatchEnable ( DMA_CHANNEL channel );
void DMA_ChannelPatternMatchDisable ( DMA_CHANNEL channel );
void DMA_ChannelPatternIgnoreByteEnable ( DMA_CHANNEL channel );
void DMA_ChannelPatternIgnoreByteDisable ( DMA_CHANNEL channel );
void DMA_ChannelPatternIgnoreValue ( DMA_CHANNEL channel, uint8_t ignoreValue );
DMA_CHANNEL_CONFIG DMA_ChannelSettingsGet (DMA_CHANNEL channel);
bool DMA_ChannelSettingsSet (DMA_CHANNEL channel, DMA_CHANNEL_CONFIG setting);


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
// DOM-IGNORE-END

#endif //PLIB_DMA_H
