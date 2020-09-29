/*******************************************************************************
  WINC MAC Driver Packet Pool Header File

  Company:
    Microchip Technology Inc.

  File Name:
    wdrv_winc_pktpool.h

  Summary:
    General packet pool.

  Description:
    Provides an interface for managing a pool of packets for the WiFi driver.
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

#ifndef _WDRV_WINC_PKTPOOL_H
#define _WDRV_WINC_PKTPOOL_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include "tcpip/src/tcpip_packet.h"

// *****************************************************************************
// *****************************************************************************
// Section: WINC MAC Driver Packet Pool Routines
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    bool WDRV_PktPoolInitialize(uint16_t numPackets, uint16_t maxPacketSize)

  Summary:
    Initializes the packet pool.

  Description:
    Creates and initializes the packet pool based on the number and maximum
      size of packets.

  Precondition:
    None.

  Parameters:
    numPackets    - Number of packets in the pool.
    maxPacketSize - Maximum size of each packet in the pool.

  Returns:
    true  - Pool created and initialized.
    false - An error occurred.

  Remarks:
    None.

*/

bool WDRV_PktPoolInitialize(uint16_t numPackets, uint16_t maxPacketSize);

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_PACKET* WDRV_PktPoolRemove(void)

  Summary:
    Removes a packet from the pool.

  Description:
    Removes and returns a single packet from the pool if available.

  Precondition:
    WDRV_PktPoolInitialize must have been called to initialize the pool.

  Parameters:
    None.

  Returns:
    NULL for an error or no packets available, otherwise a pointer to the
      removed packet.

  Remarks:
    None.

*/

TCPIP_MAC_PACKET* WDRV_PktPoolRemove(void);

//*******************************************************************************
/*
  Function:
    bool WDRV_PktPoolAdd(TCPIP_MAC_PACKET *ptrPacket)

  Summary:
    Adds a packet to the pool.

  Description:
    Places a packet passed into the function in the packet pool.

  Precondition:
    WDRV_PktPoolInitialize must have been called to initialize the pool.

  Parameters:
    ptrPacket - Pointer to packet to add to the pool.

  Returns:
    true  - Packet added.
    false - An error occurred.

  Remarks:
    None.

*/

bool WDRV_PktPoolAdd(TCPIP_MAC_PACKET *ptrPacket);

#endif /* _WDRV_WINC_PKTPOOL_H */

// DOM-IGNORE-END

