/*******************************************************************************
  Hi-Speed USB (HS USB) Module Peripheral Library Interface Header

  Company:
    Microchip Technology Inc.

  File Name:
    plib_usbhs.h

  Summary:
    HS USB PLIB Interface Header for definitions common to the Hi-Speed USB
    module.

  Description:
    This header file contains the function prototypes and definitions of
    the data types and constants that make up the interface to the USB
    PLIB for families of Microchip microcontrollers that feature the Hi-Speed
    USB module.

  Notes:
    Required to access the High Speed USB Module registers.
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

#ifndef _PLIB_USBHS_H
#define _PLIB_USBHS_H



#include <stdint.h>
#include <stdbool.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END 

// *****************************************************************************
// *****************************************************************************
// Section: Included Files (continued at end of file)
// *****************************************************************************
// *****************************************************************************
/*  This section lists the other files that are included in this file.  However,
    please see the end of the file for additional implementation header files
    that are also included
*/
#include "driver/usb/usbhs/src/plib_usbhs_header.h"

// *****************************************************************************
// *****************************************************************************
// Section: Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Maximum number of endpoints

  Summary:
    Maximum number of endpoints supported (not including EP0).

  Description:
    This constant defines the maximum number of endpoints supported (not
    including EP0).

  Remarks:
    None.
*/

#define USBHS_MAX_EP_NUMBER 7

// *****************************************************************************
/* Number of DMA Channels

  Summary:
    Number of available DMA Channels.

  Description:
    This constant defines the number of available DMA Channels.

  Remarks:
    None.
*/

#define USBHS_MAX_DMA_CHANNEL_NUMBER 8

// *****************************************************************************
/* USBHS DMA Interrupts Enumeration

  Summary:
    Provides enumeration of interrupts for DMA channels 0-7.

  Description:
    This data type provides the enumeration of interrupts for DMA channels 0-7.

  Remarks:
    None.
*/

typedef enum
{
    USBHS_DMAINT_1   /*DOM-IGNORE-BEGIN*/ =  0x01 /*DOM-IGNORE-END*/ ,
    USBHS_DMAINT_2   /*DOM-IGNORE-BEGIN*/ =  0x02 /*DOM-IGNORE-END*/ ,
    USBHS_DMAINT_3   /*DOM-IGNORE-BEGIN*/ =  0x04 /*DOM-IGNORE-END*/ ,
    USBHS_DMAINT_4   /*DOM-IGNORE-BEGIN*/ =  0x08 /*DOM-IGNORE-END*/ ,
    USBHS_DMAINT_5   /*DOM-IGNORE-BEGIN*/ =  0x10 /*DOM-IGNORE-END*/ ,
    USBHS_DMAINT_6   /*DOM-IGNORE-BEGIN*/ =  0x20 /*DOM-IGNORE-END*/ ,
    USBHS_DMAINT_7   /*DOM-IGNORE-BEGIN*/ =  0x40 /*DOM-IGNORE-END*/ ,
    USBHS_DMAINT_8   /*DOM-IGNORE-BEGIN*/ =  0x80 /*DOM-IGNORE-END*/ ,
    USBHS_DMAINT_ANY /*DOM-IGNORE-BEGIN*/ =  0xFF /*DOM-IGNORE-END*/ ,
    USBHS_DMAINT_ALL /*DOM-IGNORE-BEGIN*/ =  0xFF /*DOM-IGNORE-END*/

} USBHS_DMA_INTERRUPT;

// *****************************************************************************
/* USBHS Link Power Management (LPM) Interrupts Enumeration

  Summary:
    Provides an enumeration of LPM interrupt sources.

  Description:
    This data type provides an enumeration of LPM interrupt sources.

  Remarks:
    None.
*/

typedef enum
{
    // Host: Device responded with STALL.  Peripheral/Device: Sent a STALL.
    USBHS_LPMINT_STALL        /*DOM-IGNORE-BEGIN*/ =  0x01 /*DOM-IGNORE-END*/ ,

    // Host: Device responded with NYET.  Peripheral/Device: Sent a NYET.
    USBHS_LPMINT_NYET         /*DOM-IGNORE-BEGIN*/ =  0x02 /*DOM-IGNORE-END*/ ,

    // Host: Device responded with ACK.  Peripheral/Device: Sent an ACK.
    USBHS_LPMINT_ACK          /*DOM-IGNORE-BEGIN*/ =  0x04 /*DOM-IGNORE-END*/ ,

    // Host: LPM transaction failed to complete.  Peripheral/Device:  NYET sent because data is pending in RX FIFOs.
    USBHS_LPMINT_NOTCOMPLETE  /*DOM-IGNORE-BEGIN*/ =  0x08 /*DOM-IGNORE-END*/ ,

    // USB Module has resumed operation.
    USBHS_LPMINT_RESUMED      /*DOM-IGNORE-BEGIN*/ =  0x10 /*DOM-IGNORE-END*/ ,

    // Host: Received Bit Stuff or PID error.  Peripheral/Device: Unsupported LinkState field received.
    USBHS_LPMINT_ERROR        /*DOM-IGNORE-BEGIN*/ =  0x20 /*DOM-IGNORE-END*/

} USBHS_LPM_INTERRUPT;

// *****************************************************************************
/* USBHS Endpoint Direction Enumeration

  Summary:
    Used as an argument to identify an endpoint direction.

  Description:
    This data type is used as an argument to identify an endpoint direction.
    Valid only for Endpoints 1-7.

  Remarks:
    None.
*/

typedef enum
{
    USBHS_ENDPOINT_RX, // RX endpoint
    USBHS_ENDPOINT_TX  // TX endpoint

} USBHS_ENDPOINT_DIRECTION;

// *****************************************************************************
/* USBHS DMA Request Mode Enumeration

  Summary:
    Used as an argument to set DMA request mode.

  Description:
    THis data type is used as an argument to set DMA request mode.
    Valid only for Endpoints 1-7.

  Remarks:
    Used by PLIB_USBHS_EPnDMARequestModeSet.
*/

typedef enum
{
    USBHS_DMA_MODE0   /*DOM-IGNORE-BEGIN*/ =  0 /*DOM-IGNORE-END*/ ,
    USBHS_DMA_MODE1   /*DOM-IGNORE-BEGIN*/ =  1 /*DOM-IGNORE-END*/

} USBHS_DMA_REQUEST_MODE;

// *****************************************************************************
/* USBHS Test Speeds Enumeration

  Summary:
    Used as an argument for in setting module speeds in Test mode.

  Description:
    This data type is used as an argument for setting module speeds in Test mode.

  Remarks:
    For use with PLIB_USBHS_TestSpeedForce.
*/

typedef enum
{
    USBHS_TEST_LOW_SPEED   /*DOM-IGNORE-BEGIN*/ =  0x00 /*DOM-IGNORE-END*/ ,
    USBHS_TEST_FULL_SPEED  /*DOM-IGNORE-BEGIN*/ =  0x02 /*DOM-IGNORE-END*/ ,
    USBHS_TEST_HIGH_SPEED  /*DOM-IGNORE-BEGIN*/ =  0x01 /*DOM-IGNORE-END*/

} USBHS_TEST_SPEED;

// *****************************************************************************
/* USBHS Endpoint Data Toggle Enumeration

  Summary:
    Provides an enumeration data toggle for a packet.

  Description:
    This data type provides an enumeration data toggle for a packet.

  Remarks:
    None.
*/

typedef enum
{
    USBHS_DATA0 /*DOM-IGNORE-BEGIN*/ =  0 /*DOM-IGNORE-END*/, // DATA0/1 = 0
    USBHS_DATA1 /*DOM-IGNORE-BEGIN*/ =  1 /*DOM-IGNORE-END*/  // DATA0/1 = 1

} USBHS_DATA01;

// *****************************************************************************
/* USBHS Endpoint Speed Enumeration

  Summary:
    Provides enumeration Host endpoint speeds.

  Description:
    This data type provides enumeration Host endpoint speeds.

  Remarks:
    Used by PLIB_USBHS_EPnSpeedSet.
*/

typedef enum
{
    USBHS_LOW_SPEED  /*DOM-IGNORE-BEGIN*/ =  0x03 /*DOM-IGNORE-END*/,
    USBHS_FULL_SPEED /*DOM-IGNORE-BEGIN*/ =  0x02 /*DOM-IGNORE-END*/,
    USBHS_HIGH_SPEED /*DOM-IGNORE-BEGIN*/ =  0x01 /*DOM-IGNORE-END*/

} USBHS_SPEED;

// *****************************************************************************
/* USB Operating Modes Enumeration

  Summary:
    Provides enumeration of operating modes supported by USB.

  Description:
    This data type provides enumeration of the operating modes supported by the 
    USB module.

  Remarks:
    None.
*/

typedef enum
{
    // None
    USBHS_OPMODE_NONE   /*DOM-IGNORE-BEGIN*/ = 0 /*DOM-IGNORE-END*/ ,
    // Device
    USBHS_OPMODE_DEVICE /*DOM-IGNORE-BEGIN*/ = 1 /*DOM-IGNORE-END*/ ,
    // Host
    USBHS_OPMODE_HOST   /*DOM-IGNORE-BEGIN*/ = 2 /*DOM-IGNORE-END*/ ,
    // OTG
    USBHS_OPMODE_OTG    /*DOM-IGNORE-BEGIN*/ = 3 /*DOM-IGNORE-END*/

} USBHS_OPMODES;

// *****************************************************************************
/* USBHS Endpoint Transaction Type Enumeration

  Summary:
    Provides an enumeration of transaction types.

  Description:
    This data type provides an enumeration of transaction types.

  Remarks:
    Used by PLIB_USBHS_EPnTransactionTypeSet
*/

typedef enum
{
    USBHS_TRANSACTION_CONTROL   /*DOM-IGNORE-BEGIN*/ =  0x00 /*DOM-IGNORE-END*/,
    USBHS_TRANSACTION_ISO       /*DOM-IGNORE-BEGIN*/ =  0x01 /*DOM-IGNORE-END*/,
    USBHS_TRANSACTION_BULK      /*DOM-IGNORE-BEGIN*/ =  0x02 /*DOM-IGNORE-END*/,
    USBHS_TRANSACTION_INTERRUPT /*DOM-IGNORE-BEGIN*/ =  0x03 /*DOM-IGNORE-END*/

} USBHS_TRANSACTION_TYPE;

// *****************************************************************************
/* USBHS Hardware Configuration Bits Enumeration

  Summary:
    Provides the enumeration Configuration bits.

  Description:
    This data type provides the enumeration configuration bits returned by
    PLIB_USBHS_ConfigurationBitsGet.

  Remarks:
    See also PLIB_USBHS_ConfigurationBitsGet.
*/

typedef enum
{
    // Soft connect/disconnect supported
    USBHS_CONFIG_SOFTCONN    /*DOM-IGNORE-BEGIN*/ =  0x02 /*DOM-IGNORE-END*/,

    // Dynamic sizing of FIFO buffers supported
    USBHS_CONFIG_DYNFIFOSIZE /*DOM-IGNORE-BEGIN*/ =  0x04 /*DOM-IGNORE-END*/,

    // High bandwidth TX isochronous transfers supported
    USBHS_CONFIG_HBWTXISO    /*DOM-IGNORE-BEGIN*/ =  0x08 /*DOM-IGNORE-END*/,

    // High bandwidth RX isochronous transfers supported
    USBHS_CONFIG_HBWRXISO    /*DOM-IGNORE-BEGIN*/ =  0x10 /*DOM-IGNORE-END*/,

    // Big Endian byte ordering supported instead of Little Endian
    USBHS_CONFIG_BIGENDIAN   /*DOM-IGNORE-BEGIN*/ =  0x20 /*DOM-IGNORE-END*/,

    // Automatic splitting of bulk packets supported
    USBHS_CONFIG_AUTOSPLIT   /*DOM-IGNORE-BEGIN*/ =  0x40 /*DOM-IGNORE-END*/,

    // Automatic combining of bulk packets supported
    USBHS_CONFIG_AUTOJOIN    /*DOM-IGNORE-BEGIN*/ =  0x80 /*DOM-IGNORE-END*/

} USBHS_CONFIGURATION;

// *****************************************************************************
/* USBHS FIFO State Enumeration

  Summary:
    Provides enumeration of receive and transmit FIFO states, as reported by
    status bits.

  Description:
    This data type provides enumeration of receive and transmit FIFO states, as
    reported by status bits.

  Remarks:
    None.
*/

typedef enum
{
     USBHS_TX_FIFO_EMPTY,     // TX FIFO Empty
     USBHS_TX_FIFO_NOT_EMPTY, // TX FIFO NOT Empty
     USBHS_RX_FIFO_FULL,      // RX FIFO Full
     USBHS_RX_FIFO_NOTFULL    // RX FIFO NOT Full

} USBHS_TXRX_FIFO_STATE;

// *****************************************************************************
/* USBHS Iso Packets Per Microframe Enumeration

  Summary:
    Provides an enumeration of the allowable isochronous packets per microframe
    when operating in High-Speed mode.

  Description:
    This data type provides an enumeration of the allowable isochronous packets
    per microframe when operating in High-Speed mode.

  Remarks:
    Used by PLIB_USBHS_EPnPacketsInMicroFrameSet.
*/

typedef enum
{
    USBHS_ONE_PKTS    /*DOM-IGNORE-BEGIN*/ = 0 /*DOM-IGNORE-END*/,
    USBHS_TWO_PKTS    /*DOM-IGNORE-BEGIN*/ = 1 /*DOM-IGNORE-END*/,
    USBHS_THREE_PKTS  /*DOM-IGNORE-BEGIN*/ = 2 /*DOM-IGNORE-END*/,
    USBHS_RSVD_PKTS   /*DOM-IGNORE-BEGIN*/ = 3 /*DOM-IGNORE-END*/,

} USBHS_PKTS_PER_MICROFRAME;

// *****************************************************************************
/* USBHS Dynamic FIFO Size Enumeration

  Summary:
    Provides enumeration of dynamic FIFO sizes.

  Description:
    This data type provides enumeration of dynamic FIFO sizes.

  Remarks:
    FIFO size = 2^(FIFO_Size<3:0> + 3)
*/

typedef enum
{
    USBHS_FIFO_SIZE_8BYTES     /*DOM-IGNORE-BEGIN*/ =  0x0 /*DOM-IGNORE-END*/,
    USBHS_FIFO_SIZE_16BYTES    /*DOM-IGNORE-BEGIN*/ =  0x1 /*DOM-IGNORE-END*/,
    USBHS_FIFO_SIZE_32BYTES    /*DOM-IGNORE-BEGIN*/ =  0x2 /*DOM-IGNORE-END*/,
    USBHS_FIFO_SIZE_64BYTES    /*DOM-IGNORE-BEGIN*/ =  0x3 /*DOM-IGNORE-END*/,
    USBHS_FIFO_SIZE_128BYTES   /*DOM-IGNORE-BEGIN*/ =  0x4 /*DOM-IGNORE-END*/,
    USBHS_FIFO_SIZE_256BYTES   /*DOM-IGNORE-BEGIN*/ =  0x5 /*DOM-IGNORE-END*/,
    USBHS_FIFO_SIZE_512BYTES   /*DOM-IGNORE-BEGIN*/ =  0x6 /*DOM-IGNORE-END*/,
    USBHS_FIFO_SIZE_1024BYTES  /*DOM-IGNORE-BEGIN*/ =  0x7 /*DOM-IGNORE-END*/,
    USBHS_FIFO_SIZE_2048BYTES  /*DOM-IGNORE-BEGIN*/ =  0x8 /*DOM-IGNORE-END*/,
    USBHS_FIFO_SIZE_4096BYTES  /*DOM-IGNORE-BEGIN*/ =  0x9 /*DOM-IGNORE-END*/

} USBHS_DYN_FIFO_SIZE;

// *****************************************************************************
/* USBHS Dynamic FIFO Double Packet versus Single Packet Buffering

  Summary:
    Provides enumeration of dynamic FIFO double-packet versus single-packet
    buffering.

  Description:
    This data type provides enumeration of dynamic FIFO double-packet versus
    single-packet buffering.

  Remarks:
    None.
*/

typedef enum
{
    USBHS_FIFO_SINGLEPKT   /*DOM-IGNORE-BEGIN*/ =  0x0 /*DOM-IGNORE-END*/,
    USBHS_FIFO_DOUBLEPKT   /*DOM-IGNORE-BEGIN*/ =  0x1 /*DOM-IGNORE-END*/

} USBHS_DYN_FIFO_PACKET_BUFFERING;

// *****************************************************************************
/* USBHS DMA Assertion Timing Enumeration

  Summary:
    Provides enumeration DMA assertion timing (early versus late).

  Description:
    This data type provides enumeration DMA assertion timing (early versus late).

  Remarks:
    None.
*/

typedef enum
{
    // Assert DMA 8 bytes before filling FIFO
    USBHS_DMA_ASSERT_EARLY  /*DOM-IGNORE-BEGIN*/ = 1 /*DOM-IGNORE-END*/ ,

    // Assert DMA when FIFO is full
    USBHS_DMA_ASSERT_LATE   /*DOM-IGNORE-BEGIN*/ = 0 /*DOM-IGNORE-END*/ ,

} USBHS_DMA_ASSERT_TIMING;

// *****************************************************************************
/* USBHS DMA Burst Modes Enumeration

  Summary:
    Provides enumeration of all DMA burst modes.

  Description:
    This data type provides enumeration of all DMA burst modes.

  Remarks:
    None.
*/

typedef enum
{
    // Burst Mode 0: Bursts of unspecified length
    USBHS_DMA_BURST_MODE0  /*DOM-IGNORE-BEGIN*/ = 0 /*DOM-IGNORE-END*/,

    // Burst Mode 1: INCR4 or unspecified length
    USBHS_DMA_BURST_MODE1  /*DOM-IGNORE-BEGIN*/ = 1 /*DOM-IGNORE-END*/,

    // Burst Mode 2: INCR8, INCR4 or unspecified length
    USBHS_DMA_BURST_MODE2  /*DOM-IGNORE-BEGIN*/ = 2 /*DOM-IGNORE-END*/,

    // Burst Mode 3: INCR16, INCR8, INCR4 or unspecified length
    USBHS_DMA_BURST_MODE3  /*DOM-IGNORE-BEGIN*/ = 3 /*DOM-IGNORE-END*/

} USBHS_DMA_BURST_MODE;

// *****************************************************************************
/* USBHS DMA Transfer Modes Enumeration

  Summary:
    Provides enumeration of all DMA transfer modes.

  Description:
    This data type provides enumeration of all DMA Transfer modes.

  Remarks:
    None.
*/

typedef enum
{
    USBHS_DMA_TRANSFER_MODE0 /*DOM-IGNORE-BEGIN*/ = 0 /*DOM-IGNORE-END*/,
    USBHS_DMA_TRANSFER_MODE1 /*DOM-IGNORE-BEGIN*/ = 1 /*DOM-IGNORE-END*/

} USBHS_DMA_TRANSFER_MODE;

// *****************************************************************************
/* USBHS Link Power Management (LPM) Mode Enumeration

  Summary:
    Provides enumeration of Link Power Management (LPM) modes.

  Description:
    This data type provides enumeration of Link Power Management (LPM) modes.

  Remarks:
    Used by PLIB_USBHS_LPMModeSet.
*/

typedef enum
{
    // LPM and Extended transactions not supported and will time-out
    USBHS_LPM_DISABLED       /*DOM-IGNORE-BEGIN*/ = 0 /*DOM-IGNORE-END*/,

    // Extended transactions supported but LPM transactions not supported and produce STALLs
    USBHS_LPM_EXTENDEDNOLPM  /*DOM-IGNORE-BEGIN*/ = 1 /*DOM-IGNORE-END*/,

    // LPM and Extended transactions not supported and will timeout
    USBHS_LPM_DISABLED2      /*DOM-IGNORE-BEGIN*/ = 2 /*DOM-IGNORE-END*/,

    // LPM and Extended transactions are supported
    USBHS_LPM_LPMEXTENDED    /*DOM-IGNORE-BEGIN*/ = 3 /*DOM-IGNORE-END*/

} USBHS_LPM_MODE;

// *****************************************************************************
/* USBHS Link Power Management Requested State Enumeration

  Summary:
    Provides enumeration requested device state after accepting an LPM
    transaction.

  Description:
    This data type provides enumeration requested device state after accepting
    an LPM transaction.

  Remarks:
    Used by PLIB_USBHS_LPMRequestedLinkStateGet and
    PLIB_USBHS_LPMRequestedLinkStateSet.
*/

typedef enum
{
    USBHS_LPM_RESERVED_0 /*DOM-IGNORE-BEGIN*/ = 0x0 /*DOM-IGNORE-END*/,
    USBHS_LPM_L1_STATE   /*DOM-IGNORE-BEGIN*/ = 0x1 /*DOM-IGNORE-END*/,
    USBHS_LPM_RESERVED_2 /*DOM-IGNORE-BEGIN*/ = 0x2 /*DOM-IGNORE-END*/,
    USBHS_LPM_RESERVED_3 /*DOM-IGNORE-BEGIN*/ = 0x3 /*DOM-IGNORE-END*/,
    USBHS_LPM_RESERVED_4 /*DOM-IGNORE-BEGIN*/ = 0x4 /*DOM-IGNORE-END*/,
    USBHS_LPM_RESERVED_5 /*DOM-IGNORE-BEGIN*/ = 0x5 /*DOM-IGNORE-END*/,
    USBHS_LPM_RESERVED_6 /*DOM-IGNORE-BEGIN*/ = 0x6 /*DOM-IGNORE-END*/,
    USBHS_LPM_RESERVED_7 /*DOM-IGNORE-BEGIN*/ = 0x7 /*DOM-IGNORE-END*/,
    USBHS_LPM_RESERVED_8 /*DOM-IGNORE-BEGIN*/ = 0x8 /*DOM-IGNORE-END*/,
    USBHS_LPM_RESERVED_9 /*DOM-IGNORE-BEGIN*/ = 0x9 /*DOM-IGNORE-END*/,
    USBHS_LPM_RESERVED_A /*DOM-IGNORE-BEGIN*/ = 0xA /*DOM-IGNORE-END*/,
    USBHS_LPM_RESERVED_B /*DOM-IGNORE-BEGIN*/ = 0xB /*DOM-IGNORE-END*/,
    USBHS_LPM_RESERVED_C /*DOM-IGNORE-BEGIN*/ = 0xC /*DOM-IGNORE-END*/,
    USBHS_LPM_RESERVED_D /*DOM-IGNORE-BEGIN*/ = 0xD /*DOM-IGNORE-END*/,
    USBHS_LPM_RESERVED_E /*DOM-IGNORE-BEGIN*/ = 0xE /*DOM-IGNORE-END*/,
    USBHS_LPM_RESERVED_F /*DOM-IGNORE-BEGIN*/ = 0xF /*DOM-IGNORE-END*/,

} USBHS_LPM_LINK_STATE;

// ****************************************************************************
// ****************************************************************************
// Section: Processor Include Files
// ****************************************************************************
// ****************************************************************************
/*DOM-IGNORE-BEGIN*/
// todo #include "./processor/usbhs_processor.h"
/*DOM-IGNORE-END*/

// *****************************************************************************
// *****************************************************************************
// Section: Helper Macros
// *****************************************************************************
// *****************************************************************************

// None

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif//ndef _PLIB_USBHS_H

/*******************************************************************************
 End of File
*/
