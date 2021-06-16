/*******************************************************************************
  WINC MAC Driver TCP/IP Interface Header File

  Company:
    Microchip Technology Inc.

  File Name:
    wdrv_winc_mac.h

  Summary:
    WINC wireless driver MAC interface for TCP/IP stack.

  Description:
    Provides a control API for the MAC interface driver.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (C) 2020 released Microchip Technology Inc. All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END

#ifndef _WDRV_WINC_MAC_H
#define _WDRV_WINC_MAC_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include "wdrv_winc.h"

// *****************************************************************************
// *****************************************************************************
// Section: WINC MAC Driver Routines
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_MACLinkCheck(DRV_HANDLE handle)

  Summary:
    Indicates the state of the network link.

  Description:
    Returns a flag indicating if the network link is active or not.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle  - Client handle obtained by a call to WDRV_WINC_Open.

  Returns:
    Flag indicating network active state (true/false).

  Remarks:
    None.

*/

bool WDRV_WINC_MACLinkCheck(DRV_HANDLE handle);

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_RES WDRV_WINC_MACRxFilterHashTableEntrySet
    (
        DRV_HANDLE handle,
        const TCPIP_MAC_ADDR* DestMACAddr
    )

  Summary:
    Adds an entry to the receive multicast filter.

  Description:

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle        - Client handle obtained by a call to WDRV_WINC_Open.
    DestMACAddr - Pointer to new MAC address.

  Returns:
    TCPIP_MAC_RES_OK     - Operation performed.
    TCPIP_MAC_RES_OP_ERR - An error occurred.

  Remarks:
    None.

*/

TCPIP_MAC_RES WDRV_WINC_MACRxFilterHashTableEntrySet
(
    DRV_HANDLE handle,
    const TCPIP_MAC_ADDR* DestMACAddr
);

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_MACPowerMode(DRV_HANDLE handle, TCPIP_MAC_POWER_MODE pwrMode)

  Summary:
    Change the power mode.

  Description:
    Not currently supported.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle    - Client handle obtained by a call to WDRV_WINC_Open.
    pwrMode - New power mode.

  Returns:
    false - Not supported.

  Remarks:
    None.

*/

bool WDRV_WINC_MACPowerMode(DRV_HANDLE handle, TCPIP_MAC_POWER_MODE pwrMode);

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_RES WDRV_WINC_MACPacketTx(DRV_HANDLE handle, TCPIP_MAC_PACKET* ptrPacket)

  Summary:
    Send an Ethernet frame via the WINC.

  Description:
    Takes an Ethernet frame from the TCP/IP stack and schedules it with the
      WINC.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle      - Client handle obtained by a call to WDRV_WINC_Open.
    ptrPacket - Pointer to Ethernet frame to send.

  Returns:
    None.

  Remarks:
    None.

*/

TCPIP_MAC_RES WDRV_WINC_MACPacketTx(DRV_HANDLE handle, TCPIP_MAC_PACKET* ptrPacket);

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_PACKET* WDRV_WINC_MACPacketRx
    (
        DRV_HANDLE handle,
        TCPIP_MAC_RES* pRes,
        const TCPIP_MAC_PACKET_RX_STAT** ppPktStat
    )

  Summary:
    Retrieve an Ethernet frame.

  Description:
    Called by the TCP/IP to retrieve the next received Ethernet frame.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle      - Client handle obtained by a call to WDRV_WINC_Open.
    pRes      -
    ppPktStat -

  Returns:
    Pointer to next received Ethernet frame.

  Remarks:
    None.

*/

TCPIP_MAC_PACKET* WDRV_WINC_MACPacketRx
(
    DRV_HANDLE handle,
    TCPIP_MAC_RES* pRes,
    const TCPIP_MAC_PACKET_RX_STAT** ppPktStat
);

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_RES WDRV_WINC_MACProcess(DRV_HANDLE handle)

  Summary:
    Regular update to MAC state machine.

  Description:
    Called by the TCP/IP to update the internal state machine.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle - Client handle obtained by a call to WDRV_WINC_Open.

  Returns:
    None.

  Remarks:
    No currently used.

*/

TCPIP_MAC_RES WDRV_WINC_MACProcess(DRV_HANDLE handle);

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_RES WDRV_WINC_MACStatisticsGet
    (
        DRV_HANDLE handle,
        TCPIP_MAC_RX_STATISTICS* pRxStatistics,
        TCPIP_MAC_TX_STATISTICS* pTxStatistics
    )

  Summary:
    Return statistics.

  Description:

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle          - Client handle obtained by a call to WDRV_WINC_Open.
    pRxStatistics - Pointer to receive statistics structure.
    pTxStatistics - Pointer to transmit statistics structure.

  Returns:
    TCPIP_MAC_RES_OP_ERR - Not supported.

  Remarks:
    None.

*/

TCPIP_MAC_RES WDRV_WINC_MACStatisticsGet
(
    DRV_HANDLE handle,
    TCPIP_MAC_RX_STATISTICS* pRxStatistics,
    TCPIP_MAC_TX_STATISTICS* pTxStatistics
);

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_RES WDRV_WINC_MACParametersGet
    (
        DRV_HANDLE handle,
        TCPIP_MAC_PARAMETERS* pMacParams
    )

  Summary:
    Retrieve MAC parameter.

  Description:

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle     - Client handle obtained by a call to WDRV_WINC_Open.
    pMacParams - Pointer to structure to fill.

  Returns:
    TCPIP_MAC_RES_IS_BUSY - Data is unavailable.
    TCPIP_MAC_RES_OK      - Data is available.

  Remarks:
    None.

*/

TCPIP_MAC_RES WDRV_WINC_MACParametersGet
(
    DRV_HANDLE handle,
    TCPIP_MAC_PARAMETERS* pMacParams
);

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_RES WDRV_WINC_MACRegisterStatisticsGet
    (
        DRV_HANDLE handle,
        TCPIP_MAC_STATISTICS_REG_ENTRY* pRegEntries,
        int nEntries,
        int* pHwEntries
    )

  Summary:

  Description:

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle        - Client handle obtained by a call to WDRV_WINC_Open.
    pRegEntries -
    nEntries    -
    pHwEntries  -

  Returns:
    None.

  Remarks:
    None.

*/

TCPIP_MAC_RES WDRV_WINC_MACRegisterStatisticsGet
(
    DRV_HANDLE handle,
    TCPIP_MAC_STATISTICS_REG_ENTRY* pRegEntries,
    int nEntries,
    int* pHwEntries
);

//*******************************************************************************
/*
  Function:
    size_t WDRV_WINC_MACConfigGet
    (
        DRV_HANDLE handle,
        void* configBuff,
        size_t buffSize,
        size_t* pConfigSize
    )

  Summary:

  Description:

  Precondition:
    None.

  Parameters:
    modId       -
    configBuff  -
    buffSize    -
    pConfigSize -

  Returns:
    0

  Remarks:
    None.

*/

size_t WDRV_WINC_MACConfigGet
(
    DRV_HANDLE handle,
    void* configBuff,
    size_t buffSize,
    size_t* pConfigSize
);

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_MACEventMaskSet
    (
        DRV_HANDLE handle,
        TCPIP_MAC_EVENT macEvents,
        bool enable
    )

  Summary:
    Set or clear the event mask.

  Description:
    Sets or clears particular events within the event mask.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle      - Client handle obtained by a call to WDRV_WINC_Open.
    macEvents - Mask of events to be changed.
    enable    - Flag indicating if the events are added or removed.

  Returns:
    Flag indicating success or failure.

  Remarks:
    None.

*/

bool WDRV_WINC_MACEventMaskSet
(
    DRV_HANDLE handle,
    TCPIP_MAC_EVENT macEvents,
    bool enable
);

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_MACEventAcknowledge(DRV_HANDLE handle, TCPIP_MAC_EVENT macEvents)

  Summary:
    Acknowledge an event.

  Description:
    Indicates that certain events are to be acknowledged and cleared.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle      - Client handle obtained by a call to WDRV_WINC_Open.
    macEvents - Mask of events to be changed.

  Returns:
    Flag indicating success or failure.

  Remarks:
    None.

*/

bool WDRV_WINC_MACEventAcknowledge(DRV_HANDLE handle, TCPIP_MAC_EVENT macEvents);

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_EVENT WDRV_WINC_MACEventPendingGet(DRV_HANDLE handle)

  Summary:
    Retrieve the current events.

  Description:
    Returns the current event state.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle - Client handle obtained by a call to WDRV_WINC_Open.

  Returns:
    None.

  Remarks:
    None.

*/

TCPIP_MAC_EVENT WDRV_WINC_MACEventPendingGet(DRV_HANDLE handle);

#endif /* _WDRV_WINC_MAC_H */
