/*******************************************************************************
  WINC MAC Driver TCP/IP Interface Implementation

  Company:
    Microchip Technology Inc.

  File Name:
    wdrv_winc_stack_drv.h

  Summary:
    WINC wireless driver MAC interface for TCP/IP stack.

  Description:
    Provides a control API for the MAC interface driver.
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

#include "wdrv_winc_stack_drv.h"
#include "wdrv_winc_pktpool.h"
#include "tcpip/tcpip_mac.h"
#include "tcpip/src/tcpip_manager_control.h"
#include "tcpip/src/tcpip_packet.h"

#define TCPIP_THIS_MODULE_ID TCPIP_MODULE_MAC_WINC

#define ETH_HEADER_SIZE 14
#define PACKET_BUFFER_SIZE 1564
#define MAX_TX_PACKET_SIZE 1518
#define MAX_RX_PACKET_SIZE 1518

static void _WDRV_WINC_MACCheckRecvPacket(WDRV_WINC_MACDCPT *const pDcpt);

// *****************************************************************************
// *****************************************************************************
// Section: WINC MAC Driver Global Data
// *****************************************************************************
// *****************************************************************************

/* This is the driver instance descriptor. */
static WDRV_WINC_MACDCPT wincMACDescriptor =
{
    .isInit = false,
    .isOpen = false,
    .sysStat = SYS_STATUS_UNINITIALIZED,
};

// *****************************************************************************
// *****************************************************************************
// Section: WINC MAC Driver Implementation
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    void _WDRV_WINC_MACConnectNotifyCallback
    (
        DRV_HANDLE handle,
        WDRV_WINC_CONN_STATE currentState,
        uint8_t statusCode
    )

  Summary:
    Connection notification callback.

  Description:
    Callback to receive notification of connection state changes to update link
      state.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.
    Operating mode is station.

  Parameters:
    handle       - Client handle obtained by a call to WDRV_WINC_MACOpen.
    currentState - Current connection state.
    statusCode   - Status code associated with connection state.

  Returns:
    None.

  Remarks:
    Registered by call to WDRV_WINC_BSSConnect.

*/

static void _WDRV_WINC_MACConnectNotifyCallback
(
    DRV_HANDLE handle,
    WDRV_WINC_CONN_STATE currentState,
    WDRV_WINC_CONN_ERROR errorCode
)
{
    WDRV_WINC_MACDCPT *const pDcpt = &wincMACDescriptor;

    WDRV_DBG_TRACE_PRINT("_WDRV_WINC_MACConnectNotifyCallback %d %d\r\n", currentState, errorCode);

    if (WDRV_WINC_CONN_STATE_CONNECTED == currentState)
    {
        pDcpt->isLinkActive = true;
    }
    else
    {
        if (WDRV_WINC_OP_MODE_STA == pDcpt->operatingMode)
        {
            if (0 == errorCode)
            {
                /* For a normal STA disconnect return to the open state. */
                if ((true == pDcpt->isLinkActive) &&
                    (WDRV_WINC_DRV_STATE_CONNECTED == pDcpt->wincDrvState))
                {
                    pDcpt->wincDrvState = WDRV_WINC_DRV_STATE_OPEN;
                }
            }
            else
            {
                /* For a disconnect with error, return to the open state
                 if currently trying to connect. */
                if (WDRV_WINC_DRV_STATE_CONNECTING == pDcpt->wincDrvState)
                {
                    pDcpt->wincDrvState = WDRV_WINC_DRV_STATE_OPEN;
                }
            }
        }

        pDcpt->isLinkActive = false;
    }
}

//*******************************************************************************
/*
  Function:
    bool _WDRV_WINC_MACEthernetMsgStackCallback
    (
        TCPIP_MAC_PACKET *ptrPacket,
        const void *ackParam
    )

  Summary:
    Ethernet receive packet ACK function callback.

  Description:
    This callback is called when the TCP/IP stack wishes to release an Ethernet
      frame which has been past to it.

  Precondition:
    WDRV_PktPoolInitialize must have been called to initialize the packet pool.

  Parameters:
    ptrPacket - Pointer to Ethernet frame being returned.
    ackParam  - Extra parameters.

  Returns:
    false

  Remarks:
    None.

*/

static bool _WDRV_WINC_MACEthernetMsgStackCallback
(
    TCPIP_MAC_PACKET *ptrPacket,
    const void *ackParam
)
{
    if (NULL == ptrPacket)
    {
        return false;
    }

    if (TCPIP_MAC_SEG_FLAG_RX_STICKY == (ptrPacket->pDSeg->segFlags & TCPIP_MAC_SEG_FLAG_RX_STICKY))
    {
        ptrPacket->pktFlags &= ~TCPIP_MAC_PKT_FLAG_QUEUED;
        WDRV_PktPoolAdd(ptrPacket);
    }

    return false;
}

//*******************************************************************************
/*
  Function:
    void _WDRV_WINC_MACEthernetMsgRecvCallback
    (
        DRV_HANDLE handle,
        const uint8_t *const pEthMsg,
        uint16_t lengthEthMsg,
        bool isFragmented,
        uint8_t fragNum
    )

  Summary:
    Ethernet frame receive callback.

  Description:
    This callback is called when an Ethernet frame has been received from the
      WINC via the basic driver.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    handle       - Client handle obtained by a call to WDRV_WINC_Open.
    pEthMsg      - Pointer to received Ethernet frame.
    lengthEthMsg - Length of received Ethernet frame.
    isFragmented - Is this frame part of a larger fragmented Ethernet frame.
    fragNum      - Fragment number if fragmented.

  Returns:
    None.

  Remarks:
    Registered by a call to WDRV_WINC_EthernetRecvPacket.

*/

static void _WDRV_WINC_MACEthernetMsgRecvCallback
(
    DRV_HANDLE handle,
    const uint8_t *const pEthMsg,
    uint16_t lengthEthMsg,
    bool isFragmented,
    uint8_t fragNum
)
{
    WDRV_WINC_MACDCPT *const pDcpt = &wincMACDescriptor;
    TCPIP_MAC_EVENT events;

    OSAL_SEM_Pend(&pDcpt->curRxPacketSemaphore, OSAL_WAIT_FOREVER);
    pDcpt->pCurRxPacket->next = NULL;
    pDcpt->pCurRxPacket->ackFunc = _WDRV_WINC_MACEthernetMsgStackCallback;
    pDcpt->pCurRxPacket->ackParam = NULL;
    pDcpt->pCurRxPacket->pDSeg->segLen = lengthEthMsg - ETH_HEADER_SIZE;
    pDcpt->pCurRxPacket->pDSeg->segFlags |= TCPIP_MAC_SEG_FLAG_RX_STICKY;
    pDcpt->pCurRxPacket->pktFlags = TCPIP_MAC_PKT_FLAG_QUEUED;
    pDcpt->pCurRxPacket->tStamp = SYS_TMR_TickCountGet();

    TCPIP_Helper_ProtectedSingleListTailAdd(&pDcpt->ethRxPktList, (SGL_LIST_NODE*)pDcpt->pCurRxPacket);
    pDcpt->pCurRxPacket = NULL;
    OSAL_SEM_Post(&pDcpt->curRxPacketSemaphore);

    OSAL_SEM_Pend(&pDcpt->eventSemaphore, OSAL_WAIT_FOREVER);
    pDcpt->events |= TCPIP_EV_RX_DONE;
    events = pDcpt->events;
    OSAL_SEM_Post(&pDcpt->eventSemaphore);

    pDcpt->eventF(events, pDcpt->eventParam);

    _WDRV_WINC_MACCheckRecvPacket(pDcpt);
}

//*******************************************************************************
/*
  Function:
    void _WDRV_WINC_MACCheckRecvPacket(WDRV_WINC_MACDCPT *const pDcpt)

  Summary:
    Check if a new Ethernet receive packet is needed.

  Description:
    Ensures that after an Ethernet frames has been passed on that another is
      queued with the WINC for reception.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_PktPoolInitialize must have been called to initialize the packet pool.

  Parameters:
    pDcpt - Pointer to current MAC driver descriptor structure.

  Returns:
    None.

  Remarks:
    None.

*/

static void _WDRV_WINC_MACCheckRecvPacket(WDRV_WINC_MACDCPT *const pDcpt)
{
    /* Ensure the driver handle is valid. */
    if (NULL == pDcpt)
    {
        return;
    }

    OSAL_SEM_Pend(&pDcpt->curRxPacketSemaphore, OSAL_WAIT_FOREVER);
    if (NULL == pDcpt->pCurRxPacket)
    {
        pDcpt->pCurRxPacket = WDRV_PktPoolRemove();

        if (NULL != pDcpt->pCurRxPacket)
        {
            pDcpt->pCurRxPacket->next = NULL;
            WDRV_WINC_EthernetRecvPacket(pDcpt->wincDrvH,
                                    pDcpt->pCurRxPacket->pDSeg->segLoad,
                                    PACKET_BUFFER_SIZE,
                                    &_WDRV_WINC_MACEthernetMsgRecvCallback);
        }
    }
    OSAL_SEM_Post(&pDcpt->curRxPacketSemaphore);
}

//*******************************************************************************
/*
  Function:
    void _WDRV_WINC_MACDrvStateMachine(WDRV_WINC_MACDCPT *const pDcpt)

  Summary:
    State machine for MAC driver.

  Description:
    Updates the state machine controlling the MAC driver.

  Precondition:
    WDRV_WINC_MACInitialize should have been called.
    WDRV_WINC_MACOpen should have been called to obtain a valid handle.

  Parameters:
    pDcpt - Pointer to current MAC driver descriptor structure.

  Returns:
    None.

  Remarks:
    None.

*/

static void _WDRV_WINC_MACDrvStateMachine(WDRV_WINC_MACDCPT *const pDcpt)
{
    switch (pDcpt->wincDrvState)
    {
        case WDRV_WINC_DRV_STATE_INIT:
        {
            if (SYS_STATUS_READY == WDRV_WINC_Status(pDcpt->winc))
            {
                WDRV_DBG_TRACE_PRINT("WINC driver is ready\r\n");

                pDcpt->wincDrvState = WDRV_WINC_DRV_STATE_READY;
            }
            break;
        }

        case WDRV_WINC_DRV_STATE_READY:
        {
            if (true == pDcpt->isOpen)
            {
                pDcpt->wincDrvH = WDRV_WINC_Open(0, 0);

                if (DRV_HANDLE_INVALID != pDcpt->wincDrvH)
                {
                    WDRV_DBG_TRACE_PRINT("WINC driver is open\r\n");
                    pDcpt->sysStat = SYS_STATUS_READY;
                    pDcpt->wincDrvState = WDRV_WINC_DRV_STATE_OPEN;

                    WDRV_WINC_UserHandleSet(pDcpt->wincDrvH, (uintptr_t)pDcpt);
                }
                else
                {
                    pDcpt->sysStat = SYS_STATUS_ERROR;
                }
            }
            break;
        }

        case WDRV_WINC_DRV_STATE_OPEN:
        {
            if (true == pDcpt->autoConnect)
            {
                _WDRV_WINC_MACCheckRecvPacket(pDcpt);

                OSAL_SEM_Pend(&pDcpt->bssCtxSemaphore, OSAL_WAIT_FOREVER);
                OSAL_SEM_Pend(&pDcpt->authCtxSemaphore, OSAL_WAIT_FOREVER);

                if (WDRV_WINC_OP_MODE_AP == pDcpt->operatingMode)
                {
                    if (WDRV_WINC_STATUS_OK == WDRV_WINC_APStart(pDcpt->wincDrvH,
                                    &pDcpt->bssCtx, &pDcpt->authCtx, NULL, NULL))
                    {
                        pDcpt->wincDrvState = WDRV_WINC_DRV_STATE_CONNECTED;
                        pDcpt->isLinkActive = true;
                    }
                }
                else if (WDRV_WINC_OP_MODE_STA == pDcpt->operatingMode)
                {
                    if (WDRV_WINC_STATUS_OK == WDRV_WINC_BSSConnect(
                            pDcpt->wincDrvH, &pDcpt->bssCtx, &pDcpt->authCtx,
                            &_WDRV_WINC_MACConnectNotifyCallback))
                    {
                        pDcpt->wincDrvState = WDRV_WINC_DRV_STATE_CONNECTING;
                    }
                }

                OSAL_SEM_Post(&pDcpt->bssCtxSemaphore);
                OSAL_SEM_Post(&pDcpt->authCtxSemaphore);
            }
            break;
        }

        case WDRV_WINC_DRV_STATE_CONNECTING:
        {
            if (true == pDcpt->isLinkActive)
            {
                pDcpt->wincDrvState = WDRV_WINC_DRV_STATE_CONNECTED;
            }
            break;
        }

        case WDRV_WINC_DRV_STATE_CONNECTED:
        {
            _WDRV_WINC_MACCheckRecvPacket(pDcpt);
            break;
        }

        default:
        {
            break;
        }
    }
}

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

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

SYS_MODULE_OBJ WDRV_WINC_MACInitialize
(
    const SYS_MODULE_INDEX index,
    const SYS_MODULE_INIT *const init
)
{
    WDRV_WINC_MACDCPT *const pDcpt = &wincMACDescriptor;
    const TCPIP_MAC_MODULE_CTRL *const stackData = ((TCPIP_MAC_INIT *)init)->macControl;
    uint8_t i;

    WDRV_DBG_TRACE_PRINT("WDRV_WINC_MACInitialize(%s)\r\n", (true == pDcpt->isInit) ? "partial" : "full");

    if (NULL == stackData)
    {
        return SYS_MODULE_OBJ_INVALID;
    }

    /* Check that the driver has been initialised. */
    if (false == pDcpt->isInit)
    {
        pDcpt->winc         = WDRV_WINC_Initialize(0, NULL);
        pDcpt->wincDrvH     = DRV_HANDLE_INVALID;
        pDcpt->wincDrvState = WDRV_WINC_DRV_STATE_INIT;

        if (SYS_MODULE_OBJ_INVALID == pDcpt->winc)
            return SYS_MODULE_OBJ_INVALID;

        pDcpt->isOpen           = false;
        pDcpt->isLinkActive     = false;
        pDcpt->operatingMode    = WDRV_WINC_OP_MODE_AP;
        pDcpt->autoConnect      = false;

        WDRV_PktPoolInitialize(4, MAX_RX_PACKET_SIZE);

        TCPIP_Helper_ProtectedSingleListInitialize(&pDcpt->ethRxPktList);

        WDRV_WINC_BSSCtxSetDefaults(&pDcpt->bssCtx);
        OSAL_SEM_Create(&pDcpt->bssCtxSemaphore, OSAL_SEM_TYPE_BINARY, 1, 1);

        WDRV_WINC_AuthCtxSetOpen(&pDcpt->authCtx);
        OSAL_SEM_Create(&pDcpt->authCtxSemaphore, OSAL_SEM_TYPE_BINARY, 1, 1);

        for (i=0; i<MULTICAST_FILTER_SIZE; i++)
        {
            memset(&pDcpt->multicastFilterList[i], 0, sizeof(TCPIP_MAC_ADDR));
        }
        OSAL_SEM_Create(&pDcpt->multicastFilterListSemaphore, OSAL_SEM_TYPE_BINARY, 1, 1);

        pDcpt->eventF       = stackData->eventF;
        pDcpt->eventParam   = stackData->eventParam;
        pDcpt->eventMask    = 0;
        pDcpt->events       = 0;
        OSAL_SEM_Create(&pDcpt->eventSemaphore, OSAL_SEM_TYPE_BINARY, 1, 1);

        pDcpt->pCurRxPacket = NULL;
        OSAL_SEM_Create(&pDcpt->curRxPacketSemaphore, OSAL_SEM_TYPE_BINARY, 1, 1);

        pDcpt->sysStat = SYS_STATUS_BUSY;
        pDcpt->isInit  = true;
    }

    return (SYS_MODULE_OBJ)pDcpt;
}

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_MACDeinitialize(SYS_MODULE_OBJ object)

  Summary:
    WINC MAC driver deinitialization function.

  Description:
    This is the function that deinitializes the WINC MAC.
    It is called by the TCP/IP stack.

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

void WDRV_WINC_MACDeinitialize(SYS_MODULE_OBJ object)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)object;

    WDRV_DBG_TRACE_PRINT("WDRV_WINC_MACDeinitialize\r\n");

    if (true == pDcpt->isOpen)
    {
        WDRV_WINC_MACClose((DRV_HANDLE)object);
    }

    pDcpt->isOpen  = false;
}

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

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

void WDRV_WINC_MACReinitialize
(
    SYS_MODULE_OBJ object,
    const SYS_MODULE_INIT *const init
)
{
    WDRV_DBG_TRACE_PRINT("WDRV_WINC_MACReinitialize\r\n");
}

//*******************************************************************************
/*
  Function:
    SYS_STATUS WDRV_WINC_MACStatus(SYS_MODULE_OBJ object)

  Summary:
    Provides the current status of the WINC MAC driver module.

  Description:
    This function provides the current status of the WINC MAC driver module.

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

SYS_STATUS WDRV_WINC_MACStatus(SYS_MODULE_OBJ object)
{
    return ((WDRV_WINC_MACDCPT *const)object)->sysStat;
}

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_MACTasks(SYS_MODULE_OBJ object)

  Summary:
    Maintains the WINC MAC drivers state machine.

  Description:
    This function is used to maintain the driver's internal state machine.

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

void WDRV_WINC_MACTasks(SYS_MODULE_OBJ object)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)object;

    switch (pDcpt->sysStat)
    {
        case SYS_STATUS_UNINITIALIZED:
        {
            break;
        }

        case SYS_STATUS_BUSY:
        case SYS_STATUS_READY:
        case SYS_STATUS_READY_EXTENDED:
        {
            _WDRV_WINC_MACDrvStateMachine(pDcpt);
            break;
        }

        default: // SYS_STATUS_ERROR
        {
            break;
        }
    }
}

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

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

DRV_HANDLE WDRV_WINC_MACOpen
(
    const SYS_MODULE_INDEX index,
    const DRV_IO_INTENT intent
)
{
    WDRV_WINC_MACDCPT *const pDcpt = &wincMACDescriptor;

    WDRV_DBG_TRACE_PRINT("WDRV_WINC_MACOpen\r\n");

    /* Check that the driver has been initialised. */
    if (false == pDcpt->isInit)
    {
        return DRV_HANDLE_INVALID;
    }

    if (true == pDcpt->isOpen)
    {
        return (DRV_HANDLE)pDcpt;
    }

    pDcpt->isOpen = true;

    return (DRV_HANDLE)pDcpt;
}

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

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

void WDRV_WINC_MACClose(DRV_HANDLE handle)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)handle;

    WDRV_DBG_TRACE_PRINT("WDRV_WINC_MACClose\r\n");

    /* Ensure the driver handle is valid. */
    if (NULL == pDcpt)
    {
        return;
    }

    if (WDRV_WINC_OP_MODE_STA == WDRV_WINC_OperatingModeGet(pDcpt->wincDrvH))
    {
        WDRV_WINC_BSSDisconnect(pDcpt->wincDrvH);
    }
    else if (WDRV_WINC_OP_MODE_AP == WDRV_WINC_OperatingModeGet(pDcpt->wincDrvH))
    {
        WDRV_WINC_APStop(pDcpt->wincDrvH);
    }

    pDcpt->wincDrvState = WDRV_WINC_DRV_STATE_OPEN;
    pDcpt->isLinkActive = false;

    pDcpt->isOpen = false;
}

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_MACLinkCheck(DRV_HANDLE hMac)

  Summary:
    Indicates the state of the network link.

  Description:
    Returns a flag indicating if the network link is active or not.

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

bool WDRV_WINC_MACLinkCheck(DRV_HANDLE hMac)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)hMac;

    return pDcpt->isLinkActive;
}

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

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

TCPIP_MAC_RES WDRV_WINC_MACRxFilterHashTableEntrySet
(
    DRV_HANDLE hMac,
    const TCPIP_MAC_ADDR* DestMACAddr
)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)hMac;
    TCPIP_MAC_ADDR *pFirstFree;
    uint8_t i;
    uint8_t macHash;

    WDRV_DBG_TRACE_PRINT("WDRV_WINC_MACRxFilterHashTableEntrySet %02x:%02x:%02x:%02x:%02x:%02x\r\n",
            DestMACAddr->v[0], DestMACAddr->v[1], DestMACAddr->v[2],
            DestMACAddr->v[3], DestMACAddr->v[4], DestMACAddr->v[5]);

    macHash = 0;

    for (i=0; i<6; i++)
    {
        macHash |= DestMACAddr->v[i];
    }

    OSAL_SEM_Pend(&pDcpt->multicastFilterListSemaphore, OSAL_WAIT_FOREVER);

    if (0 == macHash)
    {
        for (i=0; i<MULTICAST_FILTER_SIZE; i++)
        {
            if (0 != pDcpt->multicastFilterList[i].v[0])
            {
                if (WDRV_WINC_STATUS_OK !=
                        WDRV_WINC_MulticastMACFilterRemove(pDcpt->wincDrvH,
                                                               pDcpt->multicastFilterList[i].v))
                {
                    OSAL_SEM_Post(&pDcpt->multicastFilterListSemaphore);
                    return TCPIP_MAC_RES_OP_ERR;
                }

                memset(&pDcpt->multicastFilterList[i], 0, sizeof(TCPIP_MAC_ADDR));
            }
        }
    }
    else
    {
        pFirstFree = NULL;

        for (i=0; i<MULTICAST_FILTER_SIZE; i++)
        {
            if (0 != pDcpt->multicastFilterList[i].v[0])
            {
                if (0 == memcmp(DestMACAddr, &pDcpt->multicastFilterList[i], sizeof(TCPIP_MAC_ADDR)))
                {
                    OSAL_SEM_Post(&pDcpt->multicastFilterListSemaphore);
                    return TCPIP_MAC_RES_OK;
                }
            }
            else if (NULL == pFirstFree)
            {
                pFirstFree = &pDcpt->multicastFilterList[i];
            }
        }

        if (NULL == pFirstFree)
        {
            OSAL_SEM_Post(&pDcpt->multicastFilterListSemaphore);
            return TCPIP_MAC_RES_OP_ERR;
        }

        if (WDRV_WINC_STATUS_OK != WDRV_WINC_MulticastMACFilterAdd(pDcpt->wincDrvH, DestMACAddr->v))
        {
            OSAL_SEM_Post(&pDcpt->multicastFilterListSemaphore);
            return TCPIP_MAC_RES_OP_ERR;
        }

        memcpy(pFirstFree, DestMACAddr, sizeof(TCPIP_MAC_ADDR));
    }

    OSAL_SEM_Post(&pDcpt->multicastFilterListSemaphore);
    return TCPIP_MAC_RES_OK;
}

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_MACPowerMode(DRV_HANDLE hMac, TCPIP_MAC_POWER_MODE pwrMode)

  Summary:
    Change the power mode.

  Description:
    Not currently supported.

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

bool WDRV_WINC_MACPowerMode(DRV_HANDLE hMac, TCPIP_MAC_POWER_MODE pwrMode)
{
    WDRV_DBG_TRACE_PRINT("WDRV_WINC_MACPowerMode\r\n");
    return false;
}

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_RES WDRV_WINC_MACPacketTx(DRV_HANDLE hMac, TCPIP_MAC_PACKET* ptrPacket)

  Summary:
    Send an Ethernet frame via the WINC.

  Description:
    Takes an Ethernet frame from the TCP/IP stack and schedules it with the
      WINC.

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

TCPIP_MAC_RES WDRV_WINC_MACPacketTx(DRV_HANDLE hMac, TCPIP_MAC_PACKET* ptrPacket)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)hMac;

    if ((NULL == pDcpt) || (NULL == ptrPacket) || (NULL == ptrPacket->pDSeg))
    {
        return TCPIP_MAC_RES_PACKET_ERR;
    }

    if ((false == pDcpt->isLinkActive) || (ptrPacket->pDSeg->segLen > MAX_TX_PACKET_SIZE))
    {
        WDRV_DBG_TRACE_PRINT("Link down or packet too large (%d)\r\n", ptrPacket->pDSeg->segLen);

        _TCPIP_PKT_ACK_FNC(ptrPacket, TCPIP_MAC_PKT_ACK_TX_OK, TCPIP_THIS_MODULE_ID);
        return TCPIP_MAC_RES_PACKET_ERR;
    }

    if (NULL == ptrPacket->pDSeg->next)
    {
        if (WDRV_WINC_STATUS_OK != WDRV_WINC_EthernetSendPacket(
                    pDcpt->wincDrvH, ptrPacket->pDSeg->segLoad, ptrPacket->pDSeg->segLen))
        {
            WDRV_DBG_TRACE_PRINT("Error sending single segment packet\r\n");
            return TCPIP_MAC_RES_PACKET_ERR;
        }

        _TCPIP_PKT_ACK_FNC(ptrPacket, TCPIP_MAC_PKT_ACK_TX_OK, TCPIP_THIS_MODULE_ID);
    }
    else
    {
        TCPIP_MAC_PACKET *ptrMultiSegPacket;
        TCPIP_MAC_DATA_SEGMENT *ptrDataSeg;
        uint16_t totalLength = 0;

        ptrDataSeg = ptrPacket->pDSeg;

        while (NULL != ptrDataSeg)
        {
            totalLength += ptrDataSeg->segLen;
            ptrDataSeg = ptrDataSeg->next;
        }

        ptrMultiSegPacket = WDRV_PktPoolRemove();

        if ((NULL != ptrMultiSegPacket) && (totalLength <= ptrMultiSegPacket->pDSeg->segSize))
        {
            ptrDataSeg = ptrPacket->pDSeg;

            ptrMultiSegPacket->pDSeg->segLen = 0;

            while (NULL != ptrDataSeg)
            {
                memcpy(&ptrMultiSegPacket->pDSeg->segLoad[ptrMultiSegPacket->pDSeg->segLen],
                                ptrDataSeg->segLoad, ptrDataSeg->segLen);

                ptrMultiSegPacket->pDSeg->segLen += ptrDataSeg->segLen;

                ptrDataSeg = ptrDataSeg->next;
            }

            if (WDRV_WINC_STATUS_OK != WDRV_WINC_EthernetSendPacket(
                    pDcpt->wincDrvH, ptrMultiSegPacket->pDSeg->segLoad, ptrMultiSegPacket->pDSeg->segLen))
            {
                WDRV_DBG_TRACE_PRINT("Error sending multi-segment packet\r\n");
                WDRV_PktPoolAdd(ptrMultiSegPacket);
                _TCPIP_PKT_ACK_FNC(ptrPacket, TCPIP_MAC_PKT_ACK_TX_OK, TCPIP_THIS_MODULE_ID);
                return TCPIP_MAC_RES_PACKET_ERR;
            }

            WDRV_PktPoolAdd(ptrMultiSegPacket);
        }

        _TCPIP_PKT_ACK_FNC(ptrPacket, TCPIP_MAC_PKT_ACK_TX_OK, TCPIP_THIS_MODULE_ID);
    }

    return TCPIP_MAC_RES_OK;
}

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

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

TCPIP_MAC_PACKET* WDRV_WINC_MACPacketRx
(
    DRV_HANDLE hMac,
    TCPIP_MAC_RES* pRes,
    const TCPIP_MAC_PACKET_RX_STAT** ppPktStat
)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)hMac;
    TCPIP_MAC_PACKET* ptrPacket;

    ptrPacket = (TCPIP_MAC_PACKET*)TCPIP_Helper_ProtectedSingleListHeadRemove(&pDcpt->ethRxPktList);

    if (NULL != ptrPacket)
    {
        ptrPacket->next = NULL;
    }

    return ptrPacket;
}

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_RES WDRV_WINC_MACProcess(DRV_HANDLE hMac)

  Summary:
    Regular update to MAC state machine.

  Description:
    Called by the TCP/IP to update the internal state machine.

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

TCPIP_MAC_RES WDRV_WINC_MACProcess(DRV_HANDLE hMac)
{
    return TCPIP_MAC_RES_OK;
}

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

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

TCPIP_MAC_RES WDRV_WINC_MACStatisticsGet
(
    DRV_HANDLE hMac,
    TCPIP_MAC_RX_STATISTICS* pRxStatistics,
    TCPIP_MAC_TX_STATISTICS* pTxStatistics
)
{
    WDRV_DBG_TRACE_PRINT("WDRV_WINC_MACStatisticsGet\r\n");
    return TCPIP_MAC_RES_OP_ERR;
}

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

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

TCPIP_MAC_RES WDRV_WINC_MACParametersGet
(
    DRV_HANDLE hMac,
    TCPIP_MAC_PARAMETERS* pMacParams
)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)hMac;

    WDRV_DBG_TRACE_PRINT("WDRV_WINC_MACParametersGet\r\n");

    /* Ensure the driver handle and user pointer is valid. */
    if ((NULL == pDcpt) || (NULL == pMacParams))
    {
        return TCPIP_MAC_RES_IS_BUSY;
    }

    if (SYS_STATUS_READY == pDcpt->sysStat)
    {
        WDRV_WINC_EthernetAddressGet(pDcpt->wincDrvH, pMacParams->ifPhyAddress.v);
        pMacParams->processFlags = (TCPIP_MAC_PROCESS_FLAG_RX | TCPIP_MAC_PROCESS_FLAG_TX);
        pMacParams->macType = TCPIP_MAC_TYPE_WLAN;

        return TCPIP_MAC_RES_OK;
    }

    return TCPIP_MAC_RES_IS_BUSY;
}

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

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

TCPIP_MAC_RES WDRV_WINC_MACRegisterStatisticsGet
(
    DRV_HANDLE hMac,
    TCPIP_MAC_STATISTICS_REG_ENTRY* pRegEntries,
    int nEntries,
    int* pHwEntries
)
{
    WDRV_DBG_TRACE_PRINT("WDRV_WINC_MACRegisterStatisticsGet\r\n");
    return TCPIP_MAC_RES_OP_ERR;
}

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

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

size_t WDRV_WINC_MACConfigGet
(
    TCPIP_MAC_HANDLE modId,
    void* configBuff,
    size_t buffSize,
    size_t* pConfigSize
)
{
    WDRV_DBG_TRACE_PRINT("WDRV_WINC_MACConfigGet\r\n");
    return 0;
}

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

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

bool WDRV_WINC_MACEventMaskSet
(
    DRV_HANDLE hMac,
    TCPIP_MAC_EVENT macEvents,
    bool enable
)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)hMac;

    /* Ensure the driver handle is valid. */
    if (NULL == pDcpt)
    {
        return false;
    }

    OSAL_SEM_Pend(&pDcpt->eventSemaphore, OSAL_WAIT_FOREVER);

    if (true == enable)
    {
        pDcpt->eventMask |= macEvents;
    }
    else
    {
        pDcpt->eventMask &= ~macEvents;
    }

    pDcpt->events &= pDcpt->eventMask;

    OSAL_SEM_Post(&pDcpt->eventSemaphore);

    return true;
}

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_MACEventAcknowledge(DRV_HANDLE hMac, TCPIP_MAC_EVENT macEvents)

  Summary:
    Acknowledge an event.

  Description:
    Indicates that certain events are to be acknowledged and cleared.

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

bool WDRV_WINC_MACEventAcknowledge(DRV_HANDLE hMac, TCPIP_MAC_EVENT macEvents)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)hMac;

    /* Ensure the driver handle is valid. */
    if (NULL == pDcpt)
    {
        return false;
    }

    OSAL_SEM_Pend(&pDcpt->eventSemaphore, OSAL_WAIT_FOREVER);
    pDcpt->events &= ~macEvents;
    OSAL_SEM_Post(&pDcpt->eventSemaphore);

    return true;
}

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_EVENT WDRV_WINC_MACEventPendingGet(DRV_HANDLE hMac)

  Summary:
    Retrieve the current events.

  Description:
    Returns the current event state.

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

TCPIP_MAC_EVENT WDRV_WINC_MACEventPendingGet(DRV_HANDLE hMac)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)hMac;
    TCPIP_MAC_EVENT events;

    /* Ensure the driver handle is valid. */
    if (NULL == pDcpt)
    {
        return 0;
    }

    OSAL_SEM_Pend(&pDcpt->eventSemaphore, OSAL_WAIT_FOREVER);
    events = pDcpt->events;
    OSAL_SEM_Post(&pDcpt->eventSemaphore);

    return events;
}
