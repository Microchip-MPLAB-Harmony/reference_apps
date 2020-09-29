/*******************************************************************************
  WINC MAC Driver Packet Pool Implementation

  Company:
    Microchip Technology Inc.

  File Name:
    wdrv_winc_pktpool.h

  Summary:
    General packet pool.

  Description:
    Provides an interface for managing a pool of packets for the WiFi driver.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include "wdrv_winc.h"
#include "wdrv_winc_pktpool.h"
#include "tcpip/src/tcpip_packet.h"
#include "tcpip/src/link_list.h"

// *****************************************************************************
// *****************************************************************************
// Section: WINC MAC Driver Packet Pool Global Data
// *****************************************************************************
// *****************************************************************************

/* This provides a managed list of packets. */
static PROTECTED_SINGLE_LIST packetPoolFreeList;

// *****************************************************************************
// *****************************************************************************
// Section: WINC MAC Driver Packet Pool Implementation
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

  Remarks:
    See wdrv_winc_pktpool.h for usage information.

*/

bool WDRV_PktPoolInitialize(uint16_t numPackets, uint16_t maxPacketSize)
{
    int8_t i;
    TCPIP_MAC_PACKET *ptrPacket;

    TCPIP_Helper_ProtectedSingleListInitialize(&packetPoolFreeList);

    for (i=0; i<numPackets; i++)
    {
        ptrPacket = _TCPIP_PKT_ALLOC_FNC(sizeof(TCPIP_MAC_PACKET), maxPacketSize, 0);

        if (NULL == ptrPacket)
        {
            return false;
        }

        ptrPacket->next = NULL;

        TCPIP_Helper_ProtectedSingleListTailAdd(&packetPoolFreeList, (SGL_LIST_NODE*)ptrPacket);
    }

    return true;
}

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_PACKET* WDRV_PktPoolRemove(void)

  Summary:
    Removes a packet from the pool.

  Description:
    Removes and returns a single packet from the pool if available.

  Remarks:
    See wdrv_winc_pktpool.h for usage information.

*/

TCPIP_MAC_PACKET* WDRV_PktPoolRemove(void)
{
    TCPIP_MAC_PACKET *ptrPacket;

    ptrPacket = (TCPIP_MAC_PACKET*)TCPIP_Helper_ProtectedSingleListHeadRemove(&packetPoolFreeList);

    return ptrPacket;
}

//*******************************************************************************
/*
  Function:
    bool WDRV_PktPoolAdd(TCPIP_MAC_PACKET *ptrPacket)

  Summary:
    Adds a packet to the pool.

  Description:
    Places a packet passed into the function in the packet pool.

  Remarks:
    See wdrv_winc_pktpool.h for usage information.

*/

bool WDRV_PktPoolAdd(TCPIP_MAC_PACKET *ptrPacket)
{
    if (NULL == ptrPacket)
    {
        return false;
    }

    TCPIP_Helper_ProtectedSingleListTailAdd(&packetPoolFreeList, (SGL_LIST_NODE*)ptrPacket);

    return true;
}
