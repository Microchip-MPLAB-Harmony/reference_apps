/*******************************************************************************
  WINC MAC Driver TCP/IP Interface Header File

  Company:
    Microchip Technology Inc.

  File Name:
    wdrv_winc_stack_drv.h

  Summary:
    WINC wireless driver MAC interface for TCP/IP stack.

  Description:
    Provides a control API for the MAC interface driver.
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

#ifndef _WDRV_WINC_STACK_DRV_H
#define _WDRV_WINC_STACK_DRV_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include "wdrv_winc.h"
#include "wdrv_winc_ethernet.h"
#include "wdrv_winc_powersave.h"
#include "tcpip/src/link_list.h"

// *****************************************************************************
// *****************************************************************************
// Section: WINC MAC Driver Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/*  Multicast Filter Size

  Summary:
    Size of multicast filter

  Description:
    Number of elements in the multicast filter.

  Remarks:
    None.
*/

#define MULTICAST_FILTER_SIZE   16

// *****************************************************************************
/*  WINC MAC Driver State

  Summary:
    WINC MAC driver state.

  Description:

  Remarks:
    None.
*/

typedef enum
{
    /* The driver is initializing. */
    WDRV_WINC_DRV_STATE_INIT,

    /* The driver is ready. */
    WDRV_WINC_DRV_STATE_READY,

    /* The driver has been opened but is not connected. */
    WDRV_WINC_DRV_STATE_OPEN,

    /* The driver is connecting. */
    WDRV_WINC_DRV_STATE_CONNECTING,

    /* The driver has connected. */
    WDRV_WINC_DRV_STATE_CONNECTED
} WDRV_WINC_DRV_STATE;

// *****************************************************************************
/*  WINC MAC Driver Descriptor

  Summary:
    Driver descriptor for the WINC MAC driver.

  Description:
    Structure containing the system level descriptor for the WINC driver.
    This structure is initialized by a call to WDRV_WINC_MACInitialize.

  Remarks:
    None.
*/

typedef struct
{
    /* Flag indicating if the driver has been initialized. */
    bool isInit;

    /* Driver status which can be queried via WDRV_WINC_Status. */
    SYS_STATUS sysStat;

    /* Flag indicating if this instance of the driver has been opened by
        a call to WDRV_WINC_MACOpen. */
    bool isOpen;

    /* Flag indicating if the network link is up and active. */
    bool isLinkActive;

    /* Flag indicating if the driver should automatically connect to a BSS
        when opened. */
    bool autoConnect;

    /* Module object for WINC basic driver. */
    SYS_MODULE_OBJ winc;

    /* Handle to open instance of WINC basic driver. */
    DRV_HANDLE wincDrvH;

    /* State of driver (open/connecting/connected etc). */
    WDRV_WINC_DRV_STATE wincDrvState;

    /* Current operating mode Soft AP or Station. */
    WDRV_WINC_OP_MODE operatingMode;

    /* Linked list of receive Ethernet packets. */
    PROTECTED_SINGLE_LIST ethRxPktList;

    /* BSS context of current association or Soft AP identity. */
    WDRV_WINC_BSS_CONTEXT bssCtx;

    /* Access semaphore to protect access to BSS context. */
    OSAL_SEM_HANDLE_TYPE bssCtxSemaphore;

    /* Authentication context. */
    WDRV_WINC_AUTH_CONTEXT authCtx;

    /* Access semaphore to protect access to authentication context. */
    OSAL_SEM_HANDLE_TYPE authCtxSemaphore;

    /* Multicast filter list. */
    TCPIP_MAC_ADDR multicastFilterList[MULTICAST_FILTER_SIZE];

    /* Access semaphore to protect access to multicast filter list. */
    OSAL_SEM_HANDLE_TYPE multicastFilterListSemaphore;

    /* Event function pointer for signalling TCP/IP stack. */
    TCPIP_MAC_EventF eventF;

    /* Event function parameters to pass to TCP/IP stack. */
    const void *eventParam;

    /* Mask of currently enabled events to signal. */
    TCPIP_MAC_EVENT eventMask;

    /* Current events to be signalled to stack. */
    TCPIP_MAC_EVENT events;

    /* Access semaphore to protect updates to event state. */
    OSAL_SEM_HANDLE_TYPE eventSemaphore;

    /* Current receive Ethernet packet. */
    TCPIP_MAC_PACKET *pCurRxPacket;

    /* Access semaphore to protect updates to current receive Ethernet packet. */
    OSAL_SEM_HANDLE_TYPE curRxPacketSemaphore;
} WDRV_WINC_MACDCPT;

// *****************************************************************************
/*  Connection State

  Summary:
    Defines the MAC connection state.

  Description:
    Includes states for closed, idle, connecting and connected states.

  Remarks:
    None.
*/

typedef enum
{
    WDRV_WINC_MAC_CONN_STATE_CLOSED,
    WDRV_WINC_MAC_CONN_STATE_IDLE,
    WDRV_WINC_MAC_CONN_STATE_CONNECTING,
    WDRV_WINC_MAC_CONN_STATE_CONNECTED
} WDRV_WINC_MAC_CONN_STATE;

/* Map debug register callback to underlying driver function. */
#define WDRV_WINC_MACDebugRegisterCallback WDRV_WINC_DebugRegisterCallbacks

// *****************************************************************************
// *****************************************************************************
// Section: WINC MAC Driver Routines
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    SYS_MODULE_OBJ WDRV_WINC_MACInitialize
    (
        const SYS_MODULE_INDEX index,
        const SYS_MODULE_INIT *const init
    )

  Summary:
    System interface initialization of the WINC MAC driver.

  Description:
    This is the function that initializes the WINC MAC driver. It is called
    by the TCP/IP stack.

  Precondition:
    None.

  Parameters:
    index   - Index for the WINC MAC driver instance to be initialized.
    init    - Pointer to the MAC initialization data.

  Returns:
    Valid handle to a driver object - if successful
    SYS_MODULE_OBJ_INVALID - if initialization failed

  Remarks:
    The returned object must be passed as argument to WDRV_WINC_MACReinitialize,
      WDRV_WINC_MACDeinitialize, WDRV_WINC_MACTasks and
      WDRV_WINC_MACStatus routines.

*/

SYS_MODULE_OBJ WDRV_WINC_MACInitialize
(
    const SYS_MODULE_INDEX index,
    const SYS_MODULE_INIT *const init
);

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_MACDeinitialize(SYS_MODULE_OBJ object)

  Summary:
    WINC MAC driver deinitialization function.

  Description:
    This is the function that deinitializes the WINC MAC.
    It is called by the TCP/IP stack.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.

  Parameters:
    object  - Driver object handle, returned from WDRV_WINC_MACInitialize

  Returns:
    None.

  Remarks:
    None.

*/

void WDRV_WINC_MACDeinitialize(SYS_MODULE_OBJ object);

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_MACReinitialize
    (
        SYS_MODULE_OBJ object,
        const SYS_MODULE_INIT *const init
    )

  Summary:
    WINC MAC driver reinitialization function.

  Description:
    This is the function that re-initializes the WINC MAC.
    It is called by the TCP/IP stack.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.

  Parameters:
    object  - Driver object handle, returned from WDRV_WINC_MACsInitialize
    init    - Pointer to the MAC initialization data.

  Returns:
    None.

  Remarks:
    None.

*/

void WDRV_WINC_MACReinitialize
(
    SYS_MODULE_OBJ object,
    const SYS_MODULE_INIT *const init
);

//*******************************************************************************
/*
  Function:
    SYS_STATUS WDRV_WINC_MACStatus(SYS_MODULE_OBJ object)

  Summary:
    Provides the current status of the WINC MAC driver module.

  Description:
    This function provides the current status of the WINC MAC driver module.

  Precondition:
    WDRV_WINC_MACInitialize must have been called before calling this function.

  Parameters:
    object  - Driver object handle, returned from WDRV_WINC_MACInitialize

  Returns:
    SYS_STATUS_READY  - Indicates that any previous module operation for the
                          specified module has completed
    SYS_STATUS_BUSY   - Indicates that a previous module operation for the
                          specified module has not yet completed
    SYS_STATUS_ERROR  - Indicates that the specified module is in an error state

  Remarks:
    None.

*/

SYS_STATUS WDRV_WINC_MACStatus(SYS_MODULE_OBJ object);

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_MACTasks(SYS_MODULE_OBJ object)

  Summary:
    Maintains the WINC MAC drivers state machine.

  Description:
    This function is used to maintain the driver's internal state machine.

  Precondition:
    WDRV_WINC_MACInitialize must have been called before calling this function.

  Parameters:
    object  - Driver object handle, returned from WDRV_WINC_MACInitialize

  Returns:
    None.

  Remarks:
    This function is normally not called directly by an application. It is
      called by the TCP/IP stack.

*/

void WDRV_WINC_MACTasks(SYS_MODULE_OBJ object);

//*******************************************************************************
/*
  Function:
    DRV_HANDLE WDRV_WINC_MACOpen
    (
        const SYS_MODULE_INDEX index,
        const DRV_IO_INTENT intent
    )

  Summary:
    Opens an instance of the WINC MAC driver.

  Description:
    Opens an instance of the WINC MAC driver and returns a handle which must be
    used when calling other driver functions.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.

  Parameters:
    index   - Identifier for the driver instance to be opened.
    intent  - Zero or more of the values from the enumeration
                DRV_IO_INTENT ORed together to indicate the intended use
                of the driver

  Returns:
    - Valid handle - if the open function succeeded
    - DRV_HANDLE_INVALID - if an error occurs

  Remarks:
    The index and intent parameters are not used in the current implementation
    and are maintained only for compatibility with the generic driver Open
    function signature.

*/

DRV_HANDLE WDRV_WINC_MACOpen
(
    const SYS_MODULE_INDEX index,
    const DRV_IO_INTENT intent
);

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_MACClose(DRV_HANDLE handle)

  Summary:
    Closes an instance of the WINC MAC driver.

  Description:
    This is the function that closes an instance of the MAC.
    All per client data is released and the handle can no longer be used
    after this function is called.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    handle  - Client handle obtained by a call to WDRV_WINC_MACOpen.

  Returns:
    None.

  Remarks:
    None.

*/

void WDRV_WINC_MACClose(DRV_HANDLE handle);

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_MACLinkCheck(DRV_HANDLE hMac)

  Summary:
    Indicates the state of the network link.

  Description:
    Returns a flag indicating if the network link is active or not.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    hMac  - Client handle obtained by a call to WDRV_WINC_MACOpen.

  Returns:
    Flag indicating network active state (true/false).

  Remarks:
    None.

*/

bool WDRV_WINC_MACLinkCheck(DRV_HANDLE hMac);

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_RES WDRV_WINC_MACRxFilterHashTableEntrySet
    (
        DRV_HANDLE hMac,
        const TCPIP_MAC_ADDR* DestMACAddr
    )

  Summary:
    Adds an entry to the receive multicast filter.

  Description:

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    hMac        - Client handle obtained by a call to WDRV_WINC_MACOpen.
    DestMACAddr - Pointer to new MAC address.

  Returns:
    TCPIP_MAC_RES_OK     - Operation performed.
    TCPIP_MAC_RES_OP_ERR - An error occurred.

  Remarks:
    None.

*/

TCPIP_MAC_RES WDRV_WINC_MACRxFilterHashTableEntrySet
(
    DRV_HANDLE hMac,
    const TCPIP_MAC_ADDR* DestMACAddr
);

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_MACPowerMode(DRV_HANDLE hMac, TCPIP_MAC_POWER_MODE pwrMode)

  Summary:
    Change the power mode.

  Description:
    Not currently supported.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    hMac    - Client handle obtained by a call to WDRV_WINC_MACOpen.
    pwrMode - New power mode.

  Returns:
    false - Not supported.

  Remarks:
    None.

*/

bool WDRV_WINC_MACPowerMode(DRV_HANDLE hMac, TCPIP_MAC_POWER_MODE pwrMode);

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_RES WDRV_WINC_MACPacketTx(DRV_HANDLE hMac, TCPIP_MAC_PACKET* ptrPacket)

  Summary:
    Send an Ethernet frame via the WINC.

  Description:
    Takes an Ethernet frame from the TCP/IP stack and schedules it with the
      WINC.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    hMac      - Client handle obtained by a call to WDRV_WINC_MACOpen.
    ptrPacket - Pointer to Ethernet frame to send.

  Returns:
    None.

  Remarks:
    None.

*/

TCPIP_MAC_RES WDRV_WINC_MACPacketTx(DRV_HANDLE hMac, TCPIP_MAC_PACKET* ptrPacket);

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_PACKET* WDRV_WINC_MACPacketRx
    (
        DRV_HANDLE hMac,
        TCPIP_MAC_RES* pRes,
        const TCPIP_MAC_PACKET_RX_STAT** ppPktStat
    )

  Summary:
    Retrieve an Ethernet frame.

  Description:
    Called by the TCP/IP to retrieve the next received Ethernet frame.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    hMac      - Client handle obtained by a call to WDRV_WINC_MACOpen.
    pRes      -
    ppPktStat -

  Returns:
    Pointer to next received Ethernet frame.

  Remarks:
    None.

*/

TCPIP_MAC_PACKET* WDRV_WINC_MACPacketRx
(
    DRV_HANDLE hMac,
    TCPIP_MAC_RES* pRes,
    const TCPIP_MAC_PACKET_RX_STAT** ppPktStat
);

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_RES WDRV_WINC_MACProcess(DRV_HANDLE hMac)

  Summary:
    Regular update to MAC state machine.

  Description:
    Called by the TCP/IP to update the internal state machine.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    hMac - Client handle obtained by a call to WDRV_WINC_MACOpen.

  Returns:
    None.

  Remarks:
    No currently used.

*/

TCPIP_MAC_RES WDRV_WINC_MACProcess(DRV_HANDLE hMac);

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_RES WDRV_WINC_MACStatisticsGet
    (
        DRV_HANDLE hMac,
        TCPIP_MAC_RX_STATISTICS* pRxStatistics,
        TCPIP_MAC_TX_STATISTICS* pTxStatistics
    )

  Summary:
    Return statistics.

  Description:

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    hMac          - Client handle obtained by a call to WDRV_WINC_MACOpen.
    pRxStatistics - Pointer to receive statistics structure.
    pTxStatistics - Pointer to transmit statistics structure.

  Returns:
    TCPIP_MAC_RES_OP_ERR - Not supported.

  Remarks:
    None.

*/

TCPIP_MAC_RES WDRV_WINC_MACStatisticsGet
(
    DRV_HANDLE hMac,
    TCPIP_MAC_RX_STATISTICS* pRxStatistics,
    TCPIP_MAC_TX_STATISTICS* pTxStatistics
);

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_RES WDRV_WINC_MACParametersGet
    (
        DRV_HANDLE hMac,
        TCPIP_MAC_PARAMETERS* pMacParams
    )

  Summary:
    Retrieve MAC parameter.

  Description:

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    hMac       - Client handle obtained by a call to WDRV_WINC_MACOpen.
    pMacParams - Pointer to structure to fill.

  Returns:
    TCPIP_MAC_RES_IS_BUSY - Data is unavailable.
    TCPIP_MAC_RES_OK      - Data is available.

  Remarks:
    None.

*/

TCPIP_MAC_RES WDRV_WINC_MACParametersGet
(
    DRV_HANDLE hMac,
    TCPIP_MAC_PARAMETERS* pMacParams
);

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_RES WDRV_WINC_MACRegisterStatisticsGet
    (
        DRV_HANDLE hMac,
        TCPIP_MAC_STATISTICS_REG_ENTRY* pRegEntries,
        int nEntries,
        int* pHwEntries
    )

  Summary:

  Description:

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    hMac        - Client handle obtained by a call to WDRV_WINC_MACOpen.
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
    DRV_HANDLE hMac,
    TCPIP_MAC_STATISTICS_REG_ENTRY* pRegEntries,
    int nEntries,
    int* pHwEntries
);

//*******************************************************************************
/*
  Function:
    size_t WDRV_WINC_MACConfigGet
    (
        TCPIP_MAC_HANDLE modId,
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
    TCPIP_MAC_HANDLE modId,
    void* configBuff,
    size_t buffSize,
    size_t* pConfigSize
);

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_MACEventMaskSet
    (
        DRV_HANDLE hMac,
        TCPIP_MAC_EVENT macEvents,
        bool enable
    )

  Summary:
    Set or clear the event mask.

  Description:
    Sets or clears particular events within the event mask.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    hMac      - Client handle obtained by a call to WDRV_WINC_MACOpen.
    macEvents - Mask of events to be changed.
    enable    - Flag indicating if the events are added or removed.

  Returns:
    Flag indicating success or failure.

  Remarks:
    None.

*/

bool WDRV_WINC_MACEventMaskSet
(
    DRV_HANDLE hMac,
    TCPIP_MAC_EVENT macEvents,
    bool enable
);

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_MACEventAcknowledge(DRV_HANDLE hMac, TCPIP_MAC_EVENT macEvents)

  Summary:
    Acknowledge an event.

  Description:
    Indicates that certain events are to be acknowledged and cleared.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    hMac      - Client handle obtained by a call to WDRV_WINC_MACOpen.
    macEvents - Mask of events to be changed.

  Returns:
    Flag indicating success or failure.

  Remarks:
    None.

*/

bool WDRV_WINC_MACEventAcknowledge(DRV_HANDLE hMac, TCPIP_MAC_EVENT macEvents);

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_EVENT WDRV_WINC_MACEventPendingGet(DRV_HANDLE hMac)

  Summary:
    Retrieve the current events.

  Description:
    Returns the current event state.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    hMac - Client handle obtained by a call to WDRV_WINC_MACOpen.

  Returns:
    None.

  Remarks:
    None.

*/

TCPIP_MAC_EVENT WDRV_WINC_MACEventPendingGet(DRV_HANDLE hMac);

// *****************************************************************************
// *****************************************************************************
// Section: WINC MAC Driver Interface Routines
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MACBSSCtxGet
    (
        DRV_HANDLE handle,
        WDRV_WINC_BSS_CONTEXT *pBSSCtx
    )

  Summary:
    Obtain a copy of the BSS context.

  Description:
    Obtain a copy of the current BSS context from within the driver.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    handle  - Client handle obtained by a call to WDRV_WINC_MACOpen.
    pBSSCtx - Pointer to structure to receive BSS context.

  Returns:
    WDRV_WINC_STATUS_OK          - The context has been copied.
    WDRV_WINC_STATUS_INVALID_ARG - The parameters were incorrect.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_MACBSSCtxGet
(
    DRV_HANDLE handle,
    WDRV_WINC_BSS_CONTEXT *pBSSCtx
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MACBSSCtxSet
    (
        DRV_HANDLE handle,
        WDRV_WINC_BSS_CONTEXT *pBSSCtx
    )

  Summary:
    Load a new BSS context into the driver.

  Description:
    A new BSS context should be created and initialized before being loaded into
      the MAC driver.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    handle  - Client handle obtained by a call to WDRV_WINC_MACOpen.
    pBSSCtx - Pointer to BSS context structure to copy into driver.

  Returns:
    WDRV_WINC_STATUS_OK          - The context has been copied.
    WDRV_WINC_STATUS_INVALID_ARG - The parameters were incorrect.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_MACBSSCtxSet
(
    DRV_HANDLE handle,
    WDRV_WINC_BSS_CONTEXT *pBSSCtx
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MACAuthCtxGet
    (
        DRV_HANDLE handle,
        WDRV_WINC_AUTH_CONTEXT *pAuthCtx
    )

  Summary:
    Obtain a copy of the authentication context.

  Description:
    Obtain a copy of the current authentication context from within the driver.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    handle   - Client handle obtained by a call to WDRV_WINC_MACOpen.
    pAuthCtx - Pointer to structure to receive authentication context.

  Returns:
    WDRV_WINC_STATUS_OK          - The context has been copied.
    WDRV_WINC_STATUS_INVALID_ARG - The parameters were incorrect.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_MACAuthCtxGet
(
    DRV_HANDLE handle,
    WDRV_WINC_AUTH_CONTEXT *pAuthCtx
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MACAuthCtxSet
    (
        DRV_HANDLE handle,
        WDRV_WINC_AUTH_CONTEXT *pAuthCtx
    )

  Summary:
    Load a new authentication context into the driver.

  Description:
    A new authentication context should be created and initialized before being
      loaded into the MAC driver.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    handle   - Client handle obtained by a call to WDRV_WINC_MACOpen.
    pAuthCtx - Pointer to authentication context structure to copy into driver.

  Returns:
    WDRV_WINC_STATUS_OK          - The context has been copied.
    WDRV_WINC_STATUS_INVALID_ARG - The parameters were incorrect.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_MACAuthCtxSet
(
    DRV_HANDLE handle,
    WDRV_WINC_AUTH_CONTEXT *pAuthCtx
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_OP_MODE WDRV_WINC_MACOperatingModeGet(DRV_HANDLE handle)

  Summary:
    Requests the current operation mode.

  Description:
    The driver can operate as either an infrastructure station or Soft-AP.
      This function returns the current mode of operation.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    handle - Client handle obtained by a call to WDRV_WINC_MACOpen.

  Returns:
    WDRV_WINC_OP_MODE_UNKNOWN for error or current operating mode.

  Remarks:
    None.

*/

WDRV_WINC_OP_MODE WDRV_WINC_MACOperatingModeGet(DRV_HANDLE handle);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MACOperatingModeSet
    (
        DRV_HANDLE handle,
        WDRV_WINC_OP_MODE operatingMode
    )

  Summary:
    Configures the current operating mode.

  Description:
    The driver can operate as either an infrastructure station or Soft-AP.
      This function configures the current mode of operation.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    handle        - Client handle obtained by a call to WDRV_WINC_MACOpen.
    operatingMode - New operating mode.

  Returns:
    WDRV_WINC_STATUS_OK          - The mode was set.
    WDRV_WINC_STATUS_INVALID_ARG - The parameters were incorrect.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_MACOperatingModeSet
(
    DRV_HANDLE handle,
    WDRV_WINC_OP_MODE operatingMode
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_MAC_CONN_STATE WDRV_WINC_MACConnectStateGet(DRV_HANDLE handle)

  Summary:
    Requests the current connection state.

  Description:

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    handle - Client handle obtained by a call to WDRV_WINC_MACOpen.

  Returns:
    One of the values defined by WDRV_WINC_MAC_CONN_STATE

  Remarks:
    None.

*/

WDRV_WINC_MAC_CONN_STATE WDRV_WINC_MACConnectStateGet(DRV_HANDLE handle);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MACAutoConnectSet(DRV_HANDLE handle, bool autoConnect)

  Summary:
    Configures the auto-connect functionality.

  Description:
    If auto-connect is enabled then whenever the driver is opened it will
      attempt to connect using the current BSS and authentication contexts.
      If auto-connect is disabled then the driver will not attempt to connect
      when it is opened.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    handle      - Client handle obtained by a call to WDRV_WINC_MACOpen.
    autoConnect - Flag indicating new value for auto-connect.

  Returns:
    WDRV_WINC_STATUS_OK          - The settings has been updateds.
    WDRV_WINC_STATUS_INVALID_ARG - The parameters were incorrect.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_MACAutoConnectSet(DRV_HANDLE handle, bool autoConnect);

// *****************************************************************************
// *****************************************************************************
// Section: WINC MAC Driver Interface Proxy Routines
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MACBSSFindFirst
    (
        DRV_HANDLE handle,
        uint8_t channel,
        bool active,
        WDRV_WINC_BSSFIND_NOTIFY_CALLBACK pfNotifyCallback
    )

  Summary:
    Request a BSS scan is performed by the WINC.

  Description:
    A scan is requested on the specified channels. An optional callback can
      be provided to receive notification of the first BSS discovered.

  Precondition:
    WDRV_WINC_MACInitialize must have been called.
    WDRV_WINC_MACOpen must have been called to obtain a valid handle.

  Parameters:
    handle           - Client handle obtained by a call to WDRV_WINC_MACOpen.
    channel          - Channel to scan, maybe WDRV_WINC_ALL_CHANNELS in
                         which case all enabled channels are scanned.
    active           - Use active vs passive scanning.
    pfNotifyCallback - Callback to receive notification of first BSS found.

  Returns:
    WDRV_WINC_STATUS_OK               - A scan was initiated.
    WDRV_WINC_STATUS_NOT_OPEN         - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG      - The parameters were incorrect.
    WDRV_WINC_STATUS_SCAN_IN_PROGRESS - A scan is already in progress.

  Remarks:
    If channel is WDRV_WINC_ALL_CHANNELS then all enabled channels are
      scanned. The enabled channels can be configured using
      WDRV_WINC_MACBSSFindSetEnabledChannels. How the scan is performed can
      be configured using WDRV_WINC_MACBSSFindSetScanParameters.

*/

WDRV_WINC_STATUS WDRV_WINC_MACBSSFindFirst
(
    DRV_HANDLE handle,
    uint8_t channel,
    bool active,
    WDRV_WINC_BSSFIND_NOTIFY_CALLBACK pfNotifyCallback
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MACBSSFindNext
    (
        DRV_HANDLE handle,
        WDRV_WINC_BSSFIND_NOTIFY_CALLBACK pfNotifyCallback
    )

  Summary:
    Request the next scan results be provided.

  Description:
    The information structure of the next BSS is requested from the WINC.

  Precondition:
    WDRV_WINC_MACInitialize must have been called.
    WDRV_WINC_MACOpen must have been called to obtain a valid handle.
    WDRV_WINC_MACBSSFindFirst must have been called.

  Parameters:
    handle           - Client handle obtained by a call to WDRV_WINC_MACOpen.
    pfNotifyCallback - Callback to receive notification of next BSS found.

  Returns:
    WDRV_WINC_STATUS_OK               - A scan was initiated.
    WDRV_WINC_STATUS_NOT_OPEN         - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG      - The parameters were incorrect.
    WDRV_WINC_STATUS_SCAN_IN_PROGRESS - A scan is already in progress.
    WDRV_WINC_STATUS_BSS_FIND_END     - No more results are available.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_MACBSSFindNext
(
    DRV_HANDLE handle,
    WDRV_WINC_BSSFIND_NOTIFY_CALLBACK pfNotifyCallback
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MACBSSFindReset
    (
        DRV_HANDLE handle,
        WDRV_WINC_BSSFIND_NOTIFY_CALLBACK pfNotifyCallback
    )

  Summary:
    Request the first scan results be provided.

  Description:
    The information structure of the first BSS is requested from the WINC.

  Precondition:
    WDRV_WINC_MACInitialize must have been called.
    WDRV_WINC_MACOpen must have been called to obtain a valid handle.
    WDRV_WINC_MACBSSFindFirst must have been called.

  Parameters:
    handle           - Client handle obtained by a call to WDRV_WINC_MACOpen.
    pfNotifyCallback - Callback to receive notification of first BSS found.

  Returns:
    WDRV_WINC_STATUS_OK               - A scan was initiated.
    WDRV_WINC_STATUS_NOT_OPEN         - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG      - The parameters were incorrect.
    WDRV_WINC_STATUS_SCAN_IN_PROGRESS - A scan is already in progress.
    WDRV_WINC_STATUS_BSS_FIND_END     - No more results are available.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_MACBSSFindReset
(
    DRV_HANDLE handle,
    WDRV_WINC_BSSFIND_NOTIFY_CALLBACK pfNotifyCallback
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MACBSSFindGetInfo
    (
        DRV_HANDLE handle,
        WDRV_WINC_BSS_INFO* pBSSInfo
    )

  Summary:
    Requests the information structure of the current BSS scan result.

  Description:
    After each call to either WDRV_WINC_MACBSSFindFirst or WDRV_WINC_MACBSSFindNext
      the driver receives a single BSS information structure which it stores.
      This function retrieves that structure.

  Precondition:
    WDRV_WINC_MACInitialize must have been called.
    WDRV_WINC_MACOpen must have been called to obtain a valid handle.
    WDRV_WINC_MACBSSFindFirst must have been called.

  Parameters:
    handle   - Client handle obtained by a call to WDRV_WINC_MACOpen.
    pBSSInfo - Pointer to structure to populate with the current BSS information.

  Returns:
    WDRV_WINC_STATUS_OK          - A scan was initiated.
    WDRV_WINC_STATUS_NOT_OPEN    - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG - The parameters were incorrect.
    WDRV_WINC_STATUS_NO_BSS_INFO - There is no current BBS information available.

  Remarks:
    This function may be polled after calling WDRV_WINC_MACBSSFindFirst or
      WDRV_WINC_MACBSSFindNext until it returns WDRV_WINC_STATUS_OK.

*/

WDRV_WINC_STATUS WDRV_WINC_MACBSSFindGetInfo
(
    DRV_HANDLE handle,
    WDRV_WINC_BSS_INFO* pBSSInfo
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MACBSSFindSetScanParameters
    (
        DRV_HANDLE handle,
        uint8_t numSlots,
        uint8_t slotTime,
        uint8_t numProbes,
        int8_t rssiThreshold
    )

  Summary:
    Configures the scan operation.

  Description:
    The scan consists of a number of slots per channel, each slot can has a
      configurable time period and number of probe requests to send.

  Precondition:
    WDRV_WINC_MACInitialize must have been called.
    WDRV_WINC_MACOpen must have been called to obtain a valid handle.

  Parameters:
    handle        - Client handle obtained by a call to WDRV_WINC_MACOpen.
    numSlots      - Number if slots (minimum is 2).
    slotTime      - Time waiting for responses (10ms <= slotTime <= 250ms).
    numProbes     - Number of probes per slot.
    rssiThreshold - Minimum RSSI for detection.

  Returns:
    WDRV_WINC_STATUS_OK            - A scan was initiated.
    WDRV_WINC_STATUS_NOT_OPEN      - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG   - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR - The WINC was unable to accept these
                                           parameters.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_MACBSSFindSetScanParameters
(
    DRV_HANDLE handle,
    uint8_t numSlots,
    uint8_t slotTime,
    uint8_t numProbes,
    int8_t rssiThreshold
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MACBSSFindSetEnabledChannels
    (
        DRV_HANDLE handle,
        WDRV_WINC_CHANNEL_MASK channelMask
    )

  Summary:
    Configures the channels which can be scanned.

  Description:
    To comply with regulatory domains certain channels must not be scanned.
      This function allows which channels are enabled to be configured.

  Precondition:
    WDRV_WINC_MACInitialize must have been called.
    WDRV_WINC_MACOpen must have been called to obtain a valid handle.

  Parameters:
    handle      - Client handle obtained by a call to WDRV_WINC_MACsOpen.
    channelMask - A channel mask detailing all the enabled channels.

  Returns:
    WDRV_WINC_STATUS_OK            - A scan was initiated.
    WDRV_WINC_STATUS_NOT_OPEN      - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG   - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR - The WINC was unable to accept this
                                           request.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_MACBSSFindSetEnabledChannels
(
    DRV_HANDLE handle,
    WDRV_WINC_CHANNEL_MASK channelMask
);

//*******************************************************************************
/*
  Function:
    uint8_t WDRV_WINC_MACBSSFindGetNumBSSResults(DRV_HANDLE handle)

  Summary:
    Returns the number of BSS scan results found.

  Description:
    Returns the number of BSS scan results found.

  Precondition:
    WDRV_WINC_MACInitialize must have been called.
    WDRV_WINC_MACOpen must have been called to obtain a valid handle.
    WDRV_WINC_MACBSSFindFirst must have been called to start a scan.

  Parameters:
    handle - Client handle obtained by a call to WDRV_WINC_MACOpen.

  Returns:
    Number of BSS scan results available. Zero indicates no results or an
      error occurred.

  Remarks:
    None.

*/

uint8_t WDRV_WINC_MACBSSFindGetNumBSSResults(DRV_HANDLE handle);

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_MACBSSFindInProgress(DRV_HANDLE handle)

  Summary:
    Indicates if a BSS scan is in progress.

  Description:
    Returns a flag indicating if a BSS scan operation is currently running.

  Precondition:
    WDRV_WINC_MACInitialize must have been called.
    WDRV_WINC_MACOpen must have been called to obtain a valid handle.

  Parameters:
    handle - Client handle obtained by a call to WDRV_WINC_MACOpen.

  Returns:
    Flag indicating if a scan is in progress. If an error occurs the result
      is false;

  Remarks:
    None.

*/

bool WDRV_WINC_MACBSSFindInProgress(DRV_HANDLE handle);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MACPowerSaveSetMode
    (
        DRV_HANDLE handle,
        WDRV_WINC_PS_MODE mode
    )

  Summary:
    Sets the power save mode.

  Description:
    Selects the current power save mode the WINC should be using.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    handle - Client handle obtained by a call to WDRV_WINC_MACOpen.
    mode   - Desired new power save mode.

  Returns:
    WDRV_WINC_STATUS_OK             - The power save mode has been accepted.
    WDRV_WINC_STATUS_NOT_OPEN       - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR  - The request to the WINC was rejected.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_MACPowerSaveSetMode
(
    DRV_HANDLE handle,
    WDRV_WINC_PS_MODE mode
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_PS_MODE WDRV_WINC_MACPowerSaveGetMode(DRV_HANDLE handle)

  Summary:
    Returns the current power save mode.

  Description:
    Returns to the caller the current power save mode in use by the WINC.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    handle - Client handle obtained by a call to WDRV_WINC_MACOpen.

  Returns:
    WDRV_WINC_PS_MODE_INVALID - An error occurred.
    Other WDRV_WINC_PS_MODE value - Current power save mode.

  Remarks:
    None.

*/

WDRV_WINC_PS_MODE WDRV_WINC_MACPowerSaveGetMode(DRV_HANDLE handle);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MACPowerSaveSetBeaconInterval
    (
        DRV_HANDLE handle,
        uint16_t numBeaconIntervals
    )

  Summary:
    Configures the beacon listening interval.

  Description:
    The beacon listening interval specifies how many beacon period will occur
      between listening actions when the WINC is in low power mode.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    handle             - Client handle obtained by a call to WDRV_WINC_MACOpen.
    numBeaconIntervals - Number of beacon intervals between listening operations.

  Returns:
    WDRV_WINC_STATUS_OK             - The interval has been accepted.
    WDRV_WINC_STATUS_NOT_OPEN       - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR  - The request to the WINC was rejected.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_MACPowerSaveSetBeaconInterval
(
    DRV_HANDLE handle,
    uint16_t numBeaconIntervals
);

#endif /* _WDRV_WINC_STACK_DRV_H */
