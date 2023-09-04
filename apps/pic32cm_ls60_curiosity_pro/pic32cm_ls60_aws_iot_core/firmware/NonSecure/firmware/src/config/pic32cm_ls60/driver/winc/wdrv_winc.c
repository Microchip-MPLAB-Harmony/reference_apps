/*******************************************************************************
  WINC Wireless Driver

  File Name:
    wdrv_winc.c

  Summary:
    WINC wireless driver.

  Description:
    WINC wireless driver.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*
Copyright (C) 2019-22, Microchip Technology Inc., and its subsidiaries. All rights reserved.

The software and documentation is provided by microchip and its contributors
"as is" and any express, implied or statutory warranties, including, but not
limited to, the implied warranties of merchantability, fitness for a particular
purpose and non-infringement of third party intellectual property rights are
disclaimed to the fullest extent permitted by law. In no event shall microchip
or its contributors be liable for any direct, indirect, incidental, special,
exemplary, or consequential damages (including, but not limited to, procurement
of substitute goods or services; loss of use, data, or profits; or business
interruption) however caused and on any theory of liability, whether in contract,
strict liability, or tort (including negligence or otherwise) arising in any way
out of the use of the software and documentation, even if advised of the
possibility of such damage.

Except as expressly permitted hereunder and subject to the applicable license terms
for any third-party software incorporated in the software and any applicable open
source software license terms, no license or other rights, whether express or
implied, are granted under any patent or other intellectual property rights of
Microchip or any third party.
*/
//DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <string.h>

#include "wdrv_winc.h"
#include "wdrv_winc_common.h"
#include "wdrv_winc_gpio.h"
#include "wdrv_winc_spi.h"
#ifdef WDRV_WINC_DEVICE_LITE_DRIVER
#include "include/winc.h"
#include "driver/winc_asic.h"
#else
#include "m2m_wifi.h"
#ifdef WDRV_WINC_DEVICE_WINC3400
#include "m2m_flash.h"
#endif
#endif
#ifdef WDRV_WINC_NETWORK_MODE_SOCKET
#ifndef WDRV_WINC_DEVICE_LITE_DRIVER
#include "m2m_ota.h"
#include "socket.h"
#include "m2m_ssl.h"
#endif
#include "wdrv_winc_ssl.h"
#endif
#ifdef WDRV_WINC_ENABLE_BLE
#ifdef WDRV_WINC_DEVICE_LITE_DRIVER
#include "winc_ble_platform.h"
#else
#include "platform.h"
#endif
#endif
#ifndef WDRV_WINC_NETWORK_MODE_SOCKET
#include "wdrv_winc_ethernet.h"
#endif
#ifdef WDRV_WINC_NETWORK_USE_HARMONY_TCPIP
#include "wdrv_winc_mac.h"
#include "tcpip/tcpip_mac.h"
#endif

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver Defines
// *****************************************************************************
// *****************************************************************************

#define ETHERNET_HDR_LEN                    14

#define WDRV_WINC_PACKET_POOL_MIN_THRES     4

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************

/* This is user configurable function pointer for printf style output from driver. */
#ifndef WDRV_WINC_DEVICE_USE_SYS_DEBUG
WDRV_WINC_DEBUG_PRINT_CALLBACK pfWINCDebugPrintCb;
#endif

/* This is the driver instance structure. */
static WDRV_WINC_DCPT wincDescriptor[2] =
{
    {
        .isInit  = false,
        .sysStat = SYS_STATUS_UNINITIALIZED,
        .isOpen  = false,
        .pCtrl   = NULL,
#ifdef WDRV_WINC_NETWORK_USE_HARMONY_TCPIP
        .pMac    = NULL,
#endif
    },
    {
        .isInit  = false,
        .sysStat = SYS_STATUS_UNINITIALIZED,
        .isOpen  = false,
        .pCtrl   = NULL,
#ifdef WDRV_WINC_NETWORK_USE_HARMONY_TCPIP
        .pMac    = NULL,
#endif
    }
};

#ifdef WDRV_WINC_NETWORK_USE_HARMONY_TCPIP

const TCPIP_MAC_OBJECT WDRV_WINC_MACObject =
{
    .macId                                  = TCPIP_MODULE_MAC_WINC,
#if TCPIP_STACK_VERSION_MAJOR != 7
    .macType                                = TCPIP_MAC_TYPE_WLAN,
#endif
    .macName                                = "WINC",
    .TCPIP_MAC_Initialize                   = WDRV_WINC_Initialize,
#if (TCPIP_STACK_MAC_DOWN_OPERATION != false)
    .TCPIP_MAC_Deinitialize                 = WDRV_WINC_Deinitialize,
    .TCPIP_MAC_Reinitialize                 = WDRV_WINC_Reinitialize,
#else
    .TCPIP_MAC_Deinitialize                 = 0,
    .TCPIP_MAC_Reinitialize                 = 0,
#endif  // (TCPIP_STACK_DOWN_OPERATION != 0)
    .TCPIP_MAC_Status                       = WDRV_WINC_Status,
    .TCPIP_MAC_Tasks                        = WDRV_WINC_MACTasks,
    .TCPIP_MAC_Open                         = WDRV_WINC_Open,
    .TCPIP_MAC_Close                        = WDRV_WINC_Close,
    .TCPIP_MAC_LinkCheck                    = WDRV_WINC_MACLinkCheck,
    .TCPIP_MAC_RxFilterHashTableEntrySet    = WDRV_WINC_MACRxFilterHashTableEntrySet,
    .TCPIP_MAC_PowerMode                    = WDRV_WINC_MACPowerMode,
    .TCPIP_MAC_PacketTx                     = WDRV_WINC_MACPacketTx,
    .TCPIP_MAC_PacketRx                     = WDRV_WINC_MACPacketRx,
    .TCPIP_MAC_Process                      = WDRV_WINC_MACProcess,
    .TCPIP_MAC_StatisticsGet                = WDRV_WINC_MACStatisticsGet,
    .TCPIP_MAC_ParametersGet                = WDRV_WINC_MACParametersGet,
    .TCPIP_MAC_RegisterStatisticsGet        = WDRV_WINC_MACRegisterStatisticsGet,
    .TCPIP_MAC_ConfigGet                    = WDRV_WINC_MACConfigGet,
    .TCPIP_MAC_EventMaskSet                 = WDRV_WINC_MACEventMaskSet,
    .TCPIP_MAC_EventAcknowledge             = WDRV_WINC_MACEventAcknowledge,
    .TCPIP_MAC_EventPendingGet              = WDRV_WINC_MACEventPendingGet,
};

#define TCPIP_THIS_MODULE_ID TCPIP_MODULE_MAC_WINC

#define PACKET_BUFFER_SIZE 1564
#define MAX_TX_PACKET_SIZE 1518
#define MAX_RX_PACKET_SIZE 1518

static void _WDRV_WINC_MACCheckRecvPacket(WDRV_WINC_DCPT *const pDcpt);
#endif

#ifdef WDRV_WINC_DEVICE_WINC1500
/* Translation table for data rates.*/
static tenuWlanTxRate arRateTranslateTable[] = {
    TX_RATE_LOWEST, TX_RATE_AUTO,   TX_RATE_1,      TX_RATE_2,
    TX_RATE_5_5,    TX_RATE_11,     TX_RATE_6,      TX_RATE_9,
    TX_RATE_12,     TX_RATE_18,     TX_RATE_24,     TX_RATE_36,
    TX_RATE_48,     TX_RATE_54,     TX_RATE_MCS_0,  TX_RATE_MCS_1,
    TX_RATE_MCS_2,  TX_RATE_MCS_3,  TX_RATE_MCS_4,  TX_RATE_MCS_5,
    TX_RATE_MCS_6,  TX_RATE_MCS_7};
#endif

// *****************************************************************************
// *****************************************************************************
// Section: WINC MAC Driver Global Data
// *****************************************************************************
// *****************************************************************************

/* This is the Control driver instance descriptor. */
static WDRV_WINC_CTRLDCPT wincCtrlDescriptor;

#ifdef WDRV_WINC_NETWORK_USE_HARMONY_TCPIP
/* This is the driver instance descriptor. */
static WDRV_WINC_MACDCPT wincMACDescriptor;
#endif

// *****************************************************************************
// *****************************************************************************
// Section: WINC MAC Driver Implementation
// *****************************************************************************
// *****************************************************************************

#ifdef WDRV_WINC_NETWORK_USE_HARMONY_TCPIP

//*******************************************************************************
/*
  Function:
    static bool _WDRV_WINC_PacketQueueInit(WDRV_WINC_PACKET_QUEUE* pPktQueue)

  Summary:
    Packet queue initialization function.

  Description:
    Initializes the packet queue.

  Precondition:
    None.

  Parameters:
    pPktQueue - Pointer to packet queue management structure.

  Returns:
    true or false.

  Remarks:
    None.

*/

static bool _WDRV_WINC_PacketQueueInit(WDRV_WINC_PACKET_QUEUE *pPktQueue)
{
    if (NULL == pPktQueue)
    {
        return false;
    }

    pPktQueue->pHead  = NULL;
    pPktQueue->pTail  = NULL;
    pPktQueue->nNodes = 0;

    if (OSAL_RESULT_TRUE == OSAL_SEM_Create(&pPktQueue->semaphore, OSAL_SEM_TYPE_BINARY, 1, 1))
    {
        pPktQueue->semValid = true;
    }
    else
    {
        pPktQueue->semValid = false;
    }

    return pPktQueue->semValid;
}

//*******************************************************************************
/*
  Function:
    static void _WDRV_WINC_PacketQueueInsert
    (
        WDRV_WINC_PACKET_QUEUE *pPktQueue,
        TCPIP_MAC_PACKET *pN
    )

  Summary:
    Insert a packet into the queue.

  Description:
    Inserts a packet into the queue at the end of a linked list.

  Precondition:
    _WDRV_WINC_PacketQueueInit must have been called.

  Parameters:
    pPktQueue - Pointer to packet queue management structure.
    pN        - Pointer to packet to insert into the queue.

  Returns:
    true or false.

  Remarks:
    None.

*/

static bool _WDRV_WINC_PacketQueueInsert
(
    WDRV_WINC_PACKET_QUEUE *pPktQueue,
    TCPIP_MAC_PACKET *pN
)
{
    if ((NULL == pPktQueue) || (NULL == pN))
    {
        return false;
    }

    if (false == pPktQueue->semValid)
    {
        return false;
    }

    if (OSAL_RESULT_TRUE != OSAL_SEM_Pend(&pPktQueue->semaphore, OSAL_WAIT_FOREVER))
    {
        return false;
    }

    pN->next = NULL;

    if (NULL == pPktQueue->pTail)
    {
        pPktQueue->pHead = pN;
    }
    else
    {
        pPktQueue->pTail->next = pN;
    }

    pPktQueue->pTail = pN;
    pPktQueue->nNodes++;

    OSAL_SEM_Post(&pPktQueue->semaphore);

    return true;
}

//*******************************************************************************
/*
  Function:
static TCPIP_MAC_PACKET* _WDRV_WINC_PacketQueueRemove
(
    WDRV_WINC_PACKET_QUEUE *pPktQueue
)

  Summary:
    Removes a packet from the queue.

  Description:
    Removes a packet from head of the queue linked list.

  Precondition:
    _WDRV_WINC_PacketQueueInit must have been called.

  Parameters:
    pPktQueue - Pointer to packet queue management structure.

  Returns:
    Pointer to packet removed.

  Remarks:
    None.

*/

static TCPIP_MAC_PACKET* _WDRV_WINC_PacketQueueRemove
(
    WDRV_WINC_PACKET_QUEUE *pPktQueue
)
{
    TCPIP_MAC_PACKET *pPacket = NULL;

    if (false == pPktQueue->semValid)
    {
        return NULL;
    }

    if (OSAL_RESULT_TRUE != OSAL_SEM_Pend(&pPktQueue->semaphore, OSAL_WAIT_FOREVER))
    {
        return NULL;
    }

    pPacket = pPktQueue->pHead;

    if (NULL != pPacket)
    {
        if (pPktQueue->pHead == pPktQueue->pTail)
        {
            pPktQueue->pHead = NULL;
            pPktQueue->pTail = NULL;
        }
        else
        {
            pPktQueue->pHead = pPacket->next;
        }

        pPktQueue->nNodes--;

        pPacket->next = NULL;
    }

    OSAL_SEM_Post(&pPktQueue->semaphore);

    return pPacket;
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
    None.

  Remarks:
    None.

*/
static void _WDRV_WINC_MACEthernetMsgStackCallback
(
    TCPIP_MAC_PACKET *ptrPacket,
    const void *ackParam
)
{
    WDRV_WINC_MACDCPT *const pMac = (WDRV_WINC_MACDCPT *)ackParam;

    if ((NULL == ptrPacket) || (NULL == pMac))
    {
        return;
    }

    /* For dynamic packets(non-sticky):
            if NO_SMART_ALLOC flag is set, free the packet else reuse by adding to the list */
    if (0 != (pMac->controlFlags & TCPIP_MAC_CONTROL_NO_SMART_ALLOC))
    {
        if (NULL != pMac->pktFreeF)
        {
            pMac->pktFreeF(ptrPacket);

            if (NULL != pMac->pktAllocF)
            {
                /* Refill the queue to the threshold. */
                while (pMac->packetPoolFreeList.nNodes < WDRV_WINC_PACKET_POOL_MIN_THRES)
                {
                    ptrPacket = pMac->pktAllocF(sizeof(TCPIP_MAC_PACKET), MAX_RX_PACKET_SIZE, 0);

                    if (NULL == ptrPacket)
                    {
                        break;
                    }

                    _WDRV_WINC_PacketQueueInsert(&pMac->packetPoolFreeList, ptrPacket);
                }
            }
        }
    }
    else
    {
        _WDRV_WINC_PacketQueueInsert(&pMac->packetPoolFreeList, ptrPacket);
    }

    return;
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
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

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
    WDRV_WINC_DCPT *const pDcpt = &wincDescriptor[1];
    TCPIP_MAC_PACKET *ptrPacket;
    TCPIP_MAC_EVENT events = 0;

    if ((NULL == pDcpt->pMac) || (NULL == pDcpt->pMac->pCurRxPacket))
    {
        return;
    }

    ptrPacket = pDcpt->pMac->pCurRxPacket;

    if (OSAL_RESULT_TRUE == OSAL_SEM_Pend(&pDcpt->pMac->curRxPacketSemaphore, OSAL_WAIT_FOREVER))
    {
        ptrPacket->ackFunc  = _WDRV_WINC_MACEthernetMsgStackCallback;
        ptrPacket->ackParam = pDcpt->pMac;

        ptrPacket->pDSeg->segLen  = lengthEthMsg - ETHERNET_HDR_LEN;
        ptrPacket->pDSeg->segSize = lengthEthMsg;
        ptrPacket->pktFlags       = TCPIP_MAC_PKT_FLAG_QUEUED;
        ptrPacket->tStamp         = SYS_TMR_TickCountGet();

        _WDRV_WINC_PacketQueueInsert(&pDcpt->pMac->ethRxPktList, ptrPacket);
        pDcpt->pMac->pCurRxPacket = NULL;
        OSAL_SEM_Post(&pDcpt->pMac->curRxPacketSemaphore);

        if (OSAL_RESULT_TRUE == OSAL_SEM_Pend(&pDcpt->pMac->eventSemaphore, OSAL_WAIT_FOREVER))
        {
            events = pDcpt->pMac->events | ~pDcpt->pMac->eventMask;
            pDcpt->pMac->events |= TCPIP_MAC_EV_RX_DONE;
            OSAL_SEM_Post(&pDcpt->pMac->eventSemaphore);

            if (0 == (events & TCPIP_MAC_EV_RX_DONE))
            {
                pDcpt->pMac->eventF(TCPIP_MAC_EV_RX_DONE, pDcpt->pMac->eventParam);
            }
        }
        else
        {
            WDRV_DBG_ERROR_PRINT("MAC receive failed to lock event semaphore\r\n");
        }
    }

    _WDRV_WINC_MACCheckRecvPacket(pDcpt);
}

//*******************************************************************************
/*
  Function:
    void _WDRV_WINC_MACCheckRecvPacket(WDRV_WINC_DCPT *const pDcpt)

  Summary:
    Check if a new Ethernet receive packet is needed.

  Description:
    Ensures that after an Ethernet frames has been passed on that another is
      queued with the WINC for reception.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_PktPoolInitialize must have been called to initialize the packet pool.

  Parameters:
    pDcpt - Pointer to current MAC driver descriptor structure.

  Returns:
    None.

  Remarks:
    None.

*/

static void _WDRV_WINC_MACCheckRecvPacket(WDRV_WINC_DCPT *const pDcpt)
{
    /* Ensure the driver handle is valid. */
    if ((NULL == pDcpt) || (NULL == pDcpt->pMac))
    {
        return;
    }

    if (OSAL_RESULT_TRUE == OSAL_SEM_Pend(&pDcpt->pMac->curRxPacketSemaphore, OSAL_WAIT_FOREVER))
    {
        if (NULL == pDcpt->pMac->pCurRxPacket)
        {
            pDcpt->pMac->pCurRxPacket = _WDRV_WINC_PacketQueueRemove(&pDcpt->pMac->packetPoolFreeList);

            if (NULL != pDcpt->pMac->pCurRxPacket)
            {
                WDRV_WINC_EthernetRecvPacket((DRV_HANDLE)pDcpt,
                                        pDcpt->pMac->pCurRxPacket->pDSeg->segLoad,
                                        PACKET_BUFFER_SIZE,
                                        &_WDRV_WINC_MACEthernetMsgRecvCallback);
            }
        }

        OSAL_SEM_Post(&pDcpt->pMac->curRxPacketSemaphore);
    }
}

#endif


// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver Callback Implementation
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    void _WDRV_WINC_WifiCallback(uint8_t msgType, const void *const pMsgContent)

  Summary:
    WiFi event callback.

  Description:
    Callback to handle:
      M2M_WIFI_RESP_SCAN_DONE
      M2M_WIFI_RESP_SCAN_RESULT
      M2M_WIFI_RESP_CON_STATE_CHANGED
      M2M_WIFI_REQ_DHCP_CONF
      M2M_WIFI_RESP_GET_SYS_TIME
      M2M_WIFI_RESP_PROVISION_INFO
      M2M_WIFI_RESP_CONN_INFO
      M2M_WIFI_RESP_CURRENT_RSSI
      M2M_WIFI_REQ_WPS

  Precondition:
    None.

  Parameters:
    msgType     - Message type.
    pMsgContent - Pointer to message specific data.

  Returns:
    None.

  Remarks:
    None.

*/

static void _WDRV_WINC_WifiCallback(uint8_t msgType, const void *const pMsgContent)
{
    WDRV_WINC_DCPT *const pDcpt = &wincDescriptor[0];

    if ((NULL == pMsgContent) || (NULL == pDcpt->pCtrl))
    {
        return;
    }

    switch (msgType)
    {
        /* Requested BSS scan has completed. */
        case M2M_WIFI_RESP_SCAN_DONE:
        {
            const tstrM2mScanDone *const pScanDoneInfo =
                    (const tstrM2mScanDone *const)pMsgContent;

            /* Check that a scan was requested. */
            if (false == pDcpt->pCtrl->scanInProgress)
            {
                break;
            }

            /* Clear scan in progress flag. */
            pDcpt->pCtrl->scanInProgress = false;

            if (M2M_SUCCESS == pScanDoneInfo->s8ScanState)
            {
                /* Scan completed successfully. */
                pDcpt->pCtrl->scanNumScanResults = pScanDoneInfo->u8NumofCh;

                if (pScanDoneInfo->u8NumofCh > 0U)
                {
                    /* If there are BSS results available, request the first one. */
                    m2m_wifi_req_scan_result(pDcpt->pCtrl->scanIndex);
                }
                else if (NULL != pDcpt->pCtrl->pfBSSFindNotifyCB)
                {
                    /* If no results are available then signal callback. */
                    pDcpt->pCtrl->pfBSSFindNotifyCB((DRV_HANDLE)pDcpt, 0, 0, NULL);
                }
                else
                {
                    /* No results and no callback so do nothing. */
                }
            }
            else
            {
                /* Ensure no results are available if scan fails. */
                pDcpt->pCtrl->scanNumScanResults = 0;
            }

            break;
        }

        /* A set of BSS scan results are available for access. */
        case M2M_WIFI_RESP_SCAN_RESULT:
        {
            const tstrM2mWifiscanResult *const pScanAPInfo =
                    (const tstrM2mWifiscanResult *const)pMsgContent;

#ifdef WDRV_WINC_DEVICE_EXT_CONNECT_PARAMS
            /* Copy BSS scan results from message buffer into driver local cache. */
            memcpy(pDcpt->pCtrl->lastBSSScanInfo.ctx.bssid.addr, pScanAPInfo->au8BSSID, 6);
            pDcpt->pCtrl->lastBSSScanInfo.ctx.bssid.valid = true;
#endif

            memcpy(pDcpt->pCtrl->lastBSSScanInfo.ctx.ssid.name, pScanAPInfo->au8SSID, WDRV_WINC_MAX_SSID_LEN);
            pDcpt->pCtrl->lastBSSScanInfo.ctx.ssid.length = (uint8_t)strnlen((const char*)pScanAPInfo->au8SSID, M2M_MAX_SSID_LEN);

            pDcpt->pCtrl->lastBSSScanInfo.rssi        = pScanAPInfo->s8rssi;
            pDcpt->pCtrl->lastBSSScanInfo.authType    = (WDRV_WINC_AUTH_TYPE)pScanAPInfo->u8AuthType;
            pDcpt->pCtrl->lastBSSScanInfo.ctx.channel = (WDRV_WINC_CHANNEL_ID)pScanAPInfo->u8ch;

            /* Mark BSS scan cache as valid. */
            pDcpt->pCtrl->isBSSScanInfoValid = true;

            if (NULL != pDcpt->pCtrl->pfBSSFindNotifyCB)
            {
                bool findResult;

                /* Notify the user application of the scan results. */
                findResult = pDcpt->pCtrl->pfBSSFindNotifyCB((DRV_HANDLE)pDcpt,
                        pDcpt->pCtrl->scanIndex+1U, pDcpt->pCtrl->scanNumScanResults, &pDcpt->pCtrl->lastBSSScanInfo);

                /* Check if the callback requested the next set of results. */
                if (true == findResult)
                {
                    /* Request the next BSS results, or end operation if no
                       more are available. */
                    pDcpt->pCtrl->scanIndex++;

                    if (pDcpt->pCtrl->scanIndex < m2m_wifi_get_num_ap_found())
                    {
                        m2m_wifi_req_scan_result(pDcpt->pCtrl->scanIndex);
                        pDcpt->pCtrl->isBSSScanInfoValid = false;
                    }
                    else pDcpt->pCtrl->pfBSSFindNotifyCB = NULL;
                }
                else pDcpt->pCtrl->pfBSSFindNotifyCB = NULL;

                /* The user callback is cleared on error or end of scan. */
            }

            break;
        }

        /* The WiFi connection has changed state. */
        case M2M_WIFI_RESP_CON_STATE_CHANGED:
        {
            const tstrM2mWifiStateChanged *const pConnectState =
                    (const tstrM2mWifiStateChanged *const)pMsgContent;

            if (M2M_WIFI_CONNECTED == pConnectState->u8CurrState)
            {
                /* If WiFi has connected update local state. If DHCP is not in
                   use then also signal an IP address is assigned. */
                pDcpt->pCtrl->isConnected = true;

#ifdef WDRV_WINC_NETWORK_MODE_SOCKET
                if ((false == pDcpt->pCtrl->useDHCP) && (0U != pDcpt->pCtrl->ipAddress))
                {
                    pDcpt->pCtrl->haveIPAddress = true;
                }
#endif
            }
            else if (M2M_WIFI_DISCONNECTED == pConnectState->u8CurrState)
            {
                /* If WiFi has disconnect update local state and invalidate any
                   association data held locally in the driver. */
                pDcpt->pCtrl->isConnected    = false;
                pDcpt->pCtrl->assocInfoValid = false;
            }
#ifdef WDRV_WINC_DEVICE_BSS_ROAMING
            else if (M2M_WIFI_ROAMED == pConnectState->u8CurrState)
            {
            }
#endif
            else
            {
                /* No other state should be signalled. */
            }

            if (NULL != pDcpt->pCtrl->pfConnectNotifyCB)
            {
                /* Update user application via callback if set. */
                pDcpt->pCtrl->pfConnectNotifyCB((DRV_HANDLE)pDcpt,
                        (WDRV_WINC_ASSOC_HANDLE)pDcpt,
                        pConnectState->u8CurrState, pConnectState->u8ErrCode);
            }

            break;
        }

        case M2M_WIFI_RESP_DEFAULT_CONNECT:
        /* The default connect attempt failed */
        {
            const tstrM2MDefaultConnResp *const pDefaultConnectRsp =
                    (const tstrM2MDefaultConnResp *const)pMsgContent;

            if (NULL != pDcpt->pCtrl->pfConnectNotifyCB)
            {
                WDRV_WINC_CONN_ERROR errorCode;

                switch (pDefaultConnectRsp->s8ErrorCode)
                {
                    case M2M_DEFAULT_CONN_INPROGRESS:
                    {
                        errorCode = WDRV_WINC_CONN_ERROR_INPROGRESS;
                        break;
                    }

                    case M2M_DEFAULT_CONN_FAIL:
                    {
                        errorCode = WDRV_WINC_CONN_ERROR_AUTH;
                        break;
                    }

                    case M2M_DEFAULT_CONN_SCAN_MISMATCH:
                    {
                        errorCode = WDRV_WINC_CONN_ERROR_SCAN;
                        break;
                    }

                    case M2M_DEFAULT_CONN_EMPTY_LIST:
                    {
                        errorCode = WDRV_WINC_CONN_ERROR_NOCRED;
                        break;
                    }

                    default:
                    {
                        errorCode = WDRV_WINC_CONN_ERROR_UNKNOWN;
                        break;
                    }
                }

                /* Update user application via callback if set. */
                pDcpt->pCtrl->pfConnectNotifyCB((DRV_HANDLE)pDcpt,
                        (WDRV_WINC_ASSOC_HANDLE)pDcpt,
                        M2M_WIFI_DISCONNECTED, errorCode);
            }

            break;
        }

#ifdef WDRV_WINC_NETWORK_MODE_SOCKET
        /* The IP address of the connection has been updated due to DHCP. */
        case M2M_WIFI_REQ_DHCP_CONF:
        {
            const uint8_t *const pIP = (const uint8_t *const)pMsgContent;

            if (false == pDcpt->pCtrl->isAP)
            {
                /* For a STA signal that an IP address has now been assigned. */
                pDcpt->pCtrl->haveIPAddress = true;
            }

            pDcpt->pCtrl->ipAddress = ( (uint32_t)pIP[3] << 24) |
                                      ( (uint32_t)pIP[2] << 16) |
                                      ( (uint32_t)pIP[1] << 8 ) |
                                      ( (uint32_t)pIP[0]);

            if (NULL != pDcpt->pCtrl->pfDHCPAddressEventCB)
            {
                /* Signal IP address to user application via callback. */
                pDcpt->pCtrl->pfDHCPAddressEventCB((DRV_HANDLE)pDcpt, pDcpt->pCtrl->ipAddress);
            }

            break;
        }
#endif

        /* The system time has been updated. */
        case M2M_WIFI_RESP_GET_SYS_TIME:
        {
            const tstrSystemTime *const pSysTime =
                    (const tstrSystemTime *const)pMsgContent;
            uint32_t timeUTC;

            /* Convert from internal M2M time structure to UTC. */
            timeUTC = WDRV_WINC_LocalTimeToUTC(pSysTime);

            if ((0U != timeUTC) && (NULL != pDcpt->pCtrl->pfSystemTimeGetCurrentCB))
            {
                /* Pass time to user application if callback was supplied. */
                pDcpt->pCtrl->pfSystemTimeGetCurrentCB((DRV_HANDLE)pDcpt, timeUTC);
            }

            break;
        }

#ifdef WDRV_WINC_NETWORK_MODE_SOCKET
        /* Provisioning information has been supplied to the WINC via the HTTP
           provision application running on the device. */
        case M2M_WIFI_RESP_PROVISION_INFO:
        {
            /* The information is only useful for the user application. */
            if (NULL != pDcpt->pCtrl->pfProvConnectInfoCB)
            {
                WDRV_WINC_SSID         targetSSID;
                WDRV_WINC_AUTH_CONTEXT authCtx;

                const tstrM2MProvisionInfo *const pProvInfo =
                        (const tstrM2MProvisionInfo *const)pMsgContent;

                /* Check the SSID length. */
                targetSSID.length = (uint8_t)strnlen((const char *)pProvInfo->au8SSID, M2M_MAX_SSID_LEN);
                if (targetSSID.length > WDRV_WINC_MAX_SSID_LEN)
                {
                    break;
                }

                /* Copy SSID to local structure, clear unused space. */
                memset(&targetSSID.name, 0, WDRV_WINC_MAX_SSID_LEN);
                memcpy(&targetSSID.name, pProvInfo->au8SSID, targetSSID.length);

                /* Copy authentication information to local context. Currently
                   only WPA and OPEN are supported. */
                authCtx.authType = (WDRV_WINC_AUTH_TYPE)pProvInfo->u8SecType;

                if (WDRV_WINC_AUTH_TYPE_WPA_PSK == pProvInfo->u8SecType)
                {
                    authCtx.authInfo.WPAPerPSK.size = (uint8_t)strlen((const char*)pProvInfo->au8Password);
                    memset(&authCtx.authInfo.WPAPerPSK.key, 0, M2M_MAX_PSK_LEN-1);
                    memcpy(&authCtx.authInfo.WPAPerPSK.key, &pProvInfo->au8Password, authCtx.authInfo.WPAPerPSK.size);
                }

                /* Pass information to user application via the callback, the
                   callback is cleared after this operation has completed. */
                pDcpt->pCtrl->pfProvConnectInfoCB((DRV_HANDLE)pDcpt, &targetSSID,
                        &authCtx, (M2M_SUCCESS == (int8_t)pProvInfo->u8Status) ? true : false);

                pDcpt->pCtrl->pfProvConnectInfoCB = NULL;
            }

            break;
        }
#endif

        /* Information about the current association has been received. */
        case M2M_WIFI_RESP_CONN_INFO:
        {
            const tstrM2MConnInfo *const pConnInfo =
                    (const tstrM2MConnInfo *const)pMsgContent;

            /* Copy and check the SSID length. */
            pDcpt->pCtrl->assocSSID.length = (uint8_t)strnlen(pConnInfo->acSSID, M2M_MAX_SSID_LEN);
            if (pDcpt->pCtrl->assocSSID.length > WDRV_WINC_MAX_SSID_LEN)
            {
                break;
            }

            /* Copy the SSID, ensuring unused space is cleared. */
            memset(&pDcpt->pCtrl->assocSSID.name, 0, WDRV_WINC_MAX_SSID_LEN);
            memcpy(&pDcpt->pCtrl->assocSSID.name, pConnInfo->acSSID, pDcpt->pCtrl->assocSSID.length);

            /* Copy the authentication type. */
            pDcpt->pCtrl->assocAuthType = (WDRV_WINC_AUTH_TYPE)pConnInfo->u8SecType;

            /* Copy the peer IP and MAC addresses. */
            pDcpt->pCtrl->assocPeerAddress.ipAddress = ( (uint32_t)pConnInfo->au8IPAddr[3] << 24) |
                                                ( (uint32_t)pConnInfo->au8IPAddr[2] << 16) |
                                                ( (uint32_t)pConnInfo->au8IPAddr[1] << 8)  |
                                                ( (uint32_t)pConnInfo->au8IPAddr[0]);

            memcpy(&pDcpt->pCtrl->assocPeerAddress.macAddress.addr, pConnInfo->au8MACAddress, 6);
            pDcpt->pCtrl->assocPeerAddress.macAddress.valid = true;

            /* Mark local store of association as valid. */
            pDcpt->pCtrl->assocInfoValid = true;

            if (NULL != pDcpt->pCtrl->pfAssociationInfoCB)
            {
                /* Pass association information to user application via callback. */
                pDcpt->pCtrl->pfAssociationInfoCB((DRV_HANDLE)pDcpt, (WDRV_WINC_ASSOC_HANDLE)pDcpt,
                        &pDcpt->pCtrl->assocSSID, &pDcpt->pCtrl->assocPeerAddress.macAddress,
                        pDcpt->pCtrl->assocAuthType, pConnInfo->s8RSSI);
            }
            break;
        }

        /* The current RSSI value has been received. */
        case M2M_WIFI_RESP_CURRENT_RSSI:
        {
            const int8_t *const pRSSI = (const int8_t *const)pMsgContent;

            /* Store locally. */
            pDcpt->pCtrl->rssi = *pRSSI;

            if (NULL != pDcpt->pCtrl->pfAssociationRSSICB)
            {
                /* Pass RSSI value to user application if callback supplied.
                   the callback is cleared after this operation has completed. */
                pDcpt->pCtrl->pfAssociationRSSICB((DRV_HANDLE)pDcpt, (WDRV_WINC_ASSOC_HANDLE)pDcpt, pDcpt->pCtrl->rssi);

                pDcpt->pCtrl->pfAssociationRSSICB = NULL;
            }
            break;
        }

        /* The WPS information has been received. */
        case M2M_WIFI_REQ_WPS:
        {
            const tstrM2MWPSInfo *const pWPSInfo =
                    (const tstrM2MWPSInfo *const)pMsgContent;

            /* The information is only useful for the user application. */
            if (NULL != pDcpt->pCtrl->pfWPSDiscoveryCB)
            {
                WDRV_WINC_BSS_CONTEXT bssCtx;
                WDRV_WINC_AUTH_CONTEXT authCtx;

                /* Initialise the BSS context with the received BSS information. */
                WDRV_WINC_BSSCtxSetDefaults(&bssCtx);
                WDRV_WINC_BSSCtxSetSSID(&bssCtx,
                                        (uint8_t *const)pWPSInfo->au8SSID,
                                        (uint8_t)strnlen((const char *)pWPSInfo->au8SSID, M2M_MAX_SSID_LEN));
                WDRV_WINC_BSSCtxSetChannel(&bssCtx, (WDRV_WINC_CHANNEL_ID)pWPSInfo->u8Ch);

                /* Initialise the authentication context. */
                switch (pWPSInfo->u8AuthType)
                {
                    case M2M_WIFI_SEC_OPEN:
                    {
                        WDRV_WINC_AuthCtxSetOpen(&authCtx);
                        break;
                    }

                    case M2M_WIFI_SEC_WPA_PSK:
                    {
                        WDRV_WINC_AuthCtxSetWPA(&authCtx,
                                                (uint8_t *const)pWPSInfo->au8PSK,
                                                (uint8_t)strnlen((const char *)pWPSInfo->au8PSK, M2M_MAX_PSK_LEN));
                        break;
                    }

                    default:
                    {
                        pDcpt->pCtrl->pfWPSDiscoveryCB((DRV_HANDLE)pDcpt, NULL, NULL);
                        return;
                    }
                }

                // Pass the BSS and authentication contexts to the user application. */
                pDcpt->pCtrl->pfWPSDiscoveryCB((DRV_HANDLE)pDcpt, &bssCtx, &authCtx);
            }

            break;
        }

#ifdef WDRV_WINC_DEVICE_WINC3400
        /* A BLE message has been received, pass it on to the BLE application. */
        case M2M_WIFI_RESP_BLE_API_RECV:
        {
            static const uint8_t bleGapMDevReadyMsg[] = {0x05, 0x01, 0x34, 0x3F, 0x00, 0x0D, 0x00, 0x00, 0x00};
            const tstrM2mBleApiMsg *const pBLEMsg = (const tstrM2mBleApiMsg *const)pMsgContent;

            if ((false == pDcpt->isOpen)
                    && (9 == pBLEMsg->u16Len)
                    && (0 == memcmp(pBLEMsg->data, bleGapMDevReadyMsg, 9))
                    )
            {
                pDcpt->sysStat = SYS_STATUS_READY;
                WDRV_DBG_INFORM_PRINT("BLE Init\r\n");
                m2m_wifi_req_restrict_ble();
            }
            else
            {
#ifdef WDRV_WINC_ENABLE_BLE
                platform_interface_callback((uint8_t*)pBLEMsg->data, pBLEMsg->u16Len);
#endif
            }

            break;
        }
#endif

        default:
        {
            break;
        }
    }
}

#ifndef WDRV_WINC_NETWORK_MODE_SOCKET
//*******************************************************************************
/*
  Function:
    void _WDRV_WINC_EthernetCallback
    (
        uint8_t msgType,
        const void *const pMsgContent,
        const void *const pCtrlBuf
    )

  Summary:
    Ethernet callback.

  Description:
    Callback to handle:
      M2M_WIFI_RESP_ETHERNET_RX_PACKET

  Precondition:
    None.

  Parameters:
    msgType     - Message type.
    pMsgContent - Pointer to message specific data.
    pCtrlBuf    - Pointer to control/information structure.

  Returns:
    None.

  Remarks:
    None.

*/

static void _WDRV_WINC_EthernetCallback
(
    uint8_t msgType,
    const void *const pMsgContent,
    const void *const pCtrlBuf
)
{
    WDRV_WINC_DCPT *const pDcpt = &wincDescriptor[0];

    if (NULL == pDcpt->pCtrl)
    {
        return;
    }

    /* Ensure on received Ethernet packets are handled. */
    if (M2M_WIFI_RESP_ETHERNET_RX_PACKET == msgType)
    {
        const tstrM2mIpCtrlBuf *const pEthCtrlBuf =
                (const tstrM2mIpCtrlBuf *const)pCtrlBuf;
        bool isFragmented;

        /* Only process if the callback has been set. */
        if (NULL != pDcpt->pCtrl->pfEthernetMsgRecvCB)
        {
            /* Check for message fragmentation. */
            if ((0 == pEthCtrlBuf->u16RemainingDataSize) && (1 == pDcpt->pCtrl->ethFragNum))
            {
                isFragmented = false;
            }
            else
            {
                isFragmented = true;
            }

            /* Pass Ethernet frame to user application. */
            pDcpt->pCtrl->pfEthernetMsgRecvCB((DRV_HANDLE)pDcpt, pMsgContent,
                    pEthCtrlBuf->u16DataSize, isFragmented, pDcpt->pCtrl->ethFragNum);

            /* Check if the last fragment and reset state for next packet. */
            if (0 == pEthCtrlBuf->u16RemainingDataSize)
            {
                pDcpt->pCtrl->ethFragNum = 1;
            }
            else
            {
                pDcpt->pCtrl->ethFragNum++;
            }
        }
    }
}
#endif

#ifdef WDRV_WINC_NETWORK_MODE_SOCKET
//*******************************************************************************
/*
  Function:
    void _WDRV_WINC_OTAUpdateCallback(uint8_t type, uint8_t status);

  Summary:
    OTA update callback.

  Description:
    Callback to handle:
      DL_STATUS
      SW_STATUS
      RB_STATUS

  Precondition:
    None.

  Parameters:
    type   - Status type.
    status - Status value.

  Returns:
    None.

  Remarks:
    None.

*/

static void _WDRV_WINC_OTAUpdateCallback(uint8_t type, uint8_t status)
{
    WDRV_WINC_DCPT *const pDcpt = &wincDescriptor[0];

    if (NULL == pDcpt->pCtrl)
    {
        return;
    }

    switch (type)
    {
        case DL_STATUS:
        {
            /* If callback supplied update with download status. */
            if (NULL != pDcpt->pCtrl->pfOTADownloadStatusCB)
            {
                pDcpt->pCtrl->pfOTADownloadStatusCB((DRV_HANDLE)pDcpt, status);
            }

            pDcpt->pCtrl->updateInProgress      = false;
            pDcpt->pCtrl->pfOTADownloadStatusCB = NULL;
            break;
        }

        case SW_STATUS:
        case RB_STATUS:
        {
            /* If callback supplied update with switch status. */
            if (NULL != pDcpt->pCtrl->pfSwitchFirmwareStatusCB)
            {
                pDcpt->pCtrl->pfSwitchFirmwareStatusCB((DRV_HANDLE)pDcpt, status);
            }

            pDcpt->pCtrl->pfSwitchFirmwareStatusCB = NULL;
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
    void _WDRV_WINC_SSLCallback(uint8_t msgType, void *pMsgContent)

  Summary:
    SSL event callback.

  Description:
    Callback to handle:
      M2M_SSL_REQ_ECC
      M2M_SSL_RESP_SET_CS_LIST
      M2M_SSL_RESP_WRITE_OWN_CERTS

  Precondition:
    None.

  Parameters:
    msgType     - Message type.
    pMsgContent - Pointer to message specific data.

  Returns:
    None.

  Remarks:
    None.

*/

static void _WDRV_WINC_SSLCallback(uint8_t msgType, void *pMsgContent)
{
    WDRV_WINC_DCPT *const pDcpt = &wincDescriptor[0];

    if ((NULL == pMsgContent) || (NULL == pDcpt->pCtrl))
    {
        return;
    }

    switch (msgType)
    {
        /* Handle set cipher suite list response. */
        case M2M_SSL_RESP_SET_CS_LIST:
        {
            /* List is only of interest to user application via callback. */
            if (NULL != pDcpt->pCtrl->pfSSLCipherSuiteListCB)
            {
                const tstrSslSetActiveCsList *const pSSLCSList = (const tstrSslSetActiveCsList *const)pMsgContent;

                WDRV_WINC_CIPHER_SUITE_CONTEXT cipherSuiteCtx;

                cipherSuiteCtx.ciperSuites = pSSLCSList->u32CsBMP;

                pDcpt->pCtrl->pfSSLCipherSuiteListCB((DRV_HANDLE)pDcpt, &cipherSuiteCtx);
            }
            break;
        }

        case M2M_SSL_REQ_ECC:
        {
            tstrEccReqInfo                  *const pECCReqInfo = (tstrEccReqInfo *const)pMsgContent;
            WINC_WDRV_ECC_REQ_TYPE          reqType;
            WDRV_WINC_ECC_HANDSHAKE_INFO    handshakeData;
            WDRV_WINC_ECC_REQ_EX_INFO       eccReqExInfo;
            WDRV_WINC_ECC_REQ_EX_INFO       *pECCReqExInfo = &eccReqExInfo;

            if (NULL == pDcpt->pCtrl->pfSSLReqECCCB)
            {
                break;
            }

            reqType                 = (WINC_WDRV_ECC_REQ_TYPE)pECCReqInfo->u16REQ;
            handshakeData.data[0]   = pECCReqInfo->u32UserData;
            handshakeData.data[1]   = pECCReqInfo->u32SeqNo;

            memset(&eccReqExInfo, 0, sizeof(WDRV_WINC_ECC_REQ_EX_INFO));

            switch (reqType)
            {
                case ECC_REQ_CLIENT_ECDH:
                case ECC_REQ_SERVER_ECDH:
                {
                    memcpy(&eccReqExInfo.ecdhInfo.pubKey.x, &pECCReqInfo->strEcdhREQ.strPubKey.X, ECC_POINT_MAX_SIZE);
                    memcpy(&eccReqExInfo.ecdhInfo.pubKey.y, &pECCReqInfo->strEcdhREQ.strPubKey.Y, ECC_POINT_MAX_SIZE);
                    eccReqExInfo.ecdhInfo.pubKey.size      = pECCReqInfo->strEcdhREQ.strPubKey.u16Size;
                    eccReqExInfo.ecdhInfo.pubKey.privKeyID = pECCReqInfo->strEcdhREQ.strPubKey.u16PrivKeyID;

                    memcpy(&eccReqExInfo.ecdhInfo.key, &pECCReqInfo->strEcdhREQ.au8Key, ECC_POINT_MAX_SIZE);
                    break;
                }

                case ECC_REQ_GEN_KEY:
                {
                    pECCReqExInfo = NULL;
                    break;
                }

                case ECC_REQ_SIGN_GEN:
                {
                    eccReqExInfo.ecdsaSignReqInfo.curveType = pECCReqInfo->strEcdsaSignREQ.u16CurveType;
                    eccReqExInfo.ecdsaSignReqInfo.hashSz    = pECCReqInfo->strEcdsaSignREQ.u16HashSz;
                    break;
                }

                case ECC_REQ_SIGN_VERIFY:
                {
                    eccReqExInfo.ecdsaVerifyReqInfo.nSig = pECCReqInfo->strEcdsaVerifyREQ.u32nSig;
                    break;
                }

                default:
                {
                    return;
                }
            }

            pDcpt->pCtrl->pfSSLReqECCCB((DRV_HANDLE)pDcpt, reqType, &handshakeData, pECCReqExInfo);
            break;
        }

        default:
        {
            break;
        }
    }
}
#endif

#ifdef WDRV_WINC_DEVICE_HOST_FILE_DOWNLOAD
//*******************************************************************************
/*
  Function:
    void _WDRV_WINC_HostFileGetCallback
    (
        uint8_t status,
        uint8_t handle,
        uint32_t size
    )

  Summary:
    Callback called in response to WDRV_WINC_HostFileDownload.

  Description:
    When WDRV_WINC_HostFileDownload is called to request a file be downloaded
      this function is called when the response is known.

  Precondition:
    WDRV_WINC_HostFileDownload has been called to request a file download.

  Parameters:
    status  - Status of download operation, see tenuOtaUpdateStatus
    handle  - WINC file handle ID if file was downloaded.
    size    - Size of file, in bytes, if file was downloaded.

  Returns:
    None.

  Remarks:
    None.

*/

static void _WDRV_WINC_HostFileGetCallback
(
    uint8_t status,
    uint8_t handle,
    uint32_t size
)
{
    WDRV_WINC_DCPT *const pDcpt = &wincDescriptor[0];
    WDRV_WINC_HOST_FILE_DCPT *pHostFileDcpt;

    if (NULL == pDcpt->pCtrl)
    {
        return;
    }

    pHostFileDcpt = &pDcpt->pCtrl->hostFileDcpt;

    if (OSAL_RESULT_TRUE != OSAL_SEM_Pend(&pHostFileDcpt->hfdSemaphore, OSAL_WAIT_FOREVER))
    {
        return;
    }

    if (OTA_STATUS_SUCCESS == status)
    {
        pHostFileDcpt->handle = handle;
        pHostFileDcpt->size   = size;
    }
    else
    {
        pHostFileDcpt->handle = HFD_INVALID_HANDLER;
        pHostFileDcpt->size   = 0;
    }

    pHostFileDcpt->offset       = 0;
    pHostFileDcpt->remain       = 0;
    pHostFileDcpt->pBuffer      = NULL;
    pHostFileDcpt->bufferSpace  = 0;

    OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);

    if (NULL != pDcpt->pCtrl->pfHostFileCB)
    {
        pDcpt->pCtrl->pfHostFileCB((DRV_HANDLE)pDcpt,
                (WDRV_WINC_HOST_FILE_HANDLE)pHostFileDcpt,
                WDRV_WINC_HOST_FILE_OP_DOWNLOAD, status);
    }
}

//*******************************************************************************
/*
  Function:
    void _WDRV_WINC_HostFileReadHIFCallback
    (
        uint8_t status,
        uint8_t *pBuffer,
        uint32_t size
    )

  Summary:
    Callback called in response to WDRV_WINC_HostFileRead.

  Description:
    When WDRV_WINC_HostFileRead is called to request a file be read
      this function is called when the response is known.

  Precondition:
    WDRV_WINC_HostFileRead has been called to request a file read.

  Parameters:
    status  - Status of read operation, see tenuOtaUpdateStatus
    handle  - Pointer to the data read.
    size    - Size of data read.

  Returns:
    None.

  Remarks:
    None.

*/

static void _WDRV_WINC_HostFileReadHIFCallback
(
    uint8_t status,
    uint8_t *pBuffer,
    uint32_t size
)
{
    WDRV_WINC_DCPT *const pDcpt = &wincDescriptor[0];
    WDRV_WINC_HOST_FILE_DCPT *pHostFileDcpt;

    if (NULL == pDcpt->pCtrl)
    {
        return;
    }

    pHostFileDcpt = &pDcpt->pCtrl->hostFileDcpt;

    if (OTA_STATUS_SUCCESS == status)
    {
        if (OSAL_RESULT_TRUE != OSAL_SEM_Pend(&pHostFileDcpt->hfdSemaphore, OSAL_WAIT_FOREVER))
        {
            return;
        }

        if ((NULL != pHostFileDcpt->pBuffer) && (size <= pHostFileDcpt->remain))
        {
            if (pHostFileDcpt->remain < size)
            {
                size = pHostFileDcpt->remain;
            }

            uint32_t sizeRemain = size;

            while (sizeRemain)
            {
                if (pHostFileDcpt->bufferSpace < sizeRemain)
                {
                    if (pHostFileDcpt->bufferSpace > 0)
                    {
                        memcpy(pHostFileDcpt->pBuffer, pBuffer, pHostFileDcpt->bufferSpace);

                        pBuffer    += pHostFileDcpt->bufferSpace;
                        sizeRemain -= pHostFileDcpt->bufferSpace;
                    }

                    pHostFileDcpt->pBuffer     = NULL;
                    pHostFileDcpt->bufferSpace = 0;

                    if (NULL != pDcpt->pCtrl->pfHostFileCB)
                    {
                        OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);

                        pDcpt->pCtrl->pfHostFileCB((DRV_HANDLE)pDcpt,
                                (WDRV_WINC_HOST_FILE_HANDLE)pHostFileDcpt,
                                WDRV_WINC_HOST_FILE_OP_READ_BUF_FULL, status);

                        if (OSAL_RESULT_TRUE != OSAL_SEM_Pend(&pHostFileDcpt->hfdSemaphore, OSAL_WAIT_FOREVER))
                        {
                            return;
                        }
                    }

                    if ((NULL == pHostFileDcpt->pBuffer) || (0U == pHostFileDcpt->bufferSpace))
                    {
                        pHostFileDcpt->remain = 0;
                        size = 0;

                        break;
                    }
                }
                else
                {
                    memcpy(pHostFileDcpt->pBuffer, pBuffer, sizeRemain);

                    pHostFileDcpt->pBuffer     += sizeRemain;
                    pHostFileDcpt->bufferSpace -= sizeRemain;

                    break;
                }
            }

            pHostFileDcpt->remain  -= size;
            pHostFileDcpt->offset  += size;

            if (pHostFileDcpt->remain > 0U)
            {
                OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);

                WDRV_WINC_HostFileRead((DRV_HANDLE)pDcpt,
                    (WDRV_WINC_HOST_FILE_HANDLE)pHostFileDcpt,
                    NULL, 0, 0, 0, pDcpt->pCtrl->pfHostFileCB);
            }
            else
            {
                OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);

                if (NULL != pDcpt->pCtrl->pfHostFileCB)
                {
                    pDcpt->pCtrl->pfHostFileCB((DRV_HANDLE)pDcpt,
                            (WDRV_WINC_HOST_FILE_HANDLE)pHostFileDcpt,
                            WDRV_WINC_HOST_FILE_OP_READ, status);
                }
            }
        }
        else
        {
            OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);
            status = (uint8_t)OTA_STATUS_FAIL;
        }
    }
    else
    {
        if (NULL != pDcpt->pCtrl->pfHostFileCB)
        {
            pDcpt->pCtrl->pfHostFileCB((DRV_HANDLE)pDcpt,
                    (WDRV_WINC_HOST_FILE_HANDLE)&pDcpt->pCtrl->hostFileDcpt,
                    WDRV_WINC_HOST_FILE_OP_READ, status);
        }
    }
}

//*******************************************************************************
/*
  Function:
    void _WDRV_WINC_HostFileEraseCallback(uint8_t status)

  Summary:
    Callback called in response to WDRV_WINC_HostFileErase.

  Description:
    When WDRV_WINC_HostFileErase is called to request a file be erased
      this function is called when the response is known.

  Precondition:
    WDRV_WINC_HostFileErase has been called to request a file erase.

  Parameters:
    status  - Status of erase operation, see tenuOtaUpdateStatus

  Returns:
    None.

  Remarks:
    None.

*/

static void _WDRV_WINC_HostFileEraseCallback(uint8_t status)
{
    WDRV_WINC_DCPT *const pDcpt = &wincDescriptor[0];
    WDRV_WINC_HOST_FILE_DCPT *pHostFileDcpt;

    if (NULL == pDcpt->pCtrl)
    {
        return;
    }

    pHostFileDcpt = &pDcpt->pCtrl->hostFileDcpt;

    if (NULL != pDcpt->pCtrl->pfHostFileCB)
    {
        pDcpt->pCtrl->pfHostFileCB((DRV_HANDLE)pDcpt,
                (WDRV_WINC_HOST_FILE_HANDLE)pHostFileDcpt,
                WDRV_WINC_HOST_FILE_OP_ERASE, status);

        if (OSAL_RESULT_TRUE != OSAL_SEM_Pend(&pHostFileDcpt->hfdSemaphore, OSAL_WAIT_FOREVER))
        {
            return;
        }

        pHostFileDcpt->handle = HFD_INVALID_HANDLER;
        pHostFileDcpt->size   = 0;

        OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);
    }
}
#endif

//*******************************************************************************
/*
  Function:
    void _WDRV_WINC_ResetCtrlDcpt(WDRV_WINC_CTRLDCPT *pCtrl)

  Summary:
    Reset control descriptor to initial state.

  Description:
    Called upon initialization and opening to reset the initial state.

  Precondition:
    None.

  Parameters:
    pCtrl - Pointer to control descriptor.

  Returns:
    None.

  Remarks:
    None.

*/

static void _WDRV_WINC_ResetCtrlDcpt(WDRV_WINC_CTRLDCPT *pCtrl)
{
    if (NULL == pCtrl)
    {
        return;
    }

    /* Initialise driver state. */
    pCtrl->isAP                     = false;
    pCtrl->isProvisioning           = false;
    pCtrl->isConnected              = false;
    pCtrl->scanInProgress           = false;
    pCtrl->isBSSScanInfoValid       = false;
    pCtrl->scanParamDefault         = true;
    pCtrl->scanNumSlots             = M2M_SCAN_DEFAULT_NUM_SLOTS;
    pCtrl->scanActiveScanTime       = M2M_SCAN_DEFAULT_SLOT_TIME;
    pCtrl->scanNumProbes            = M2M_SCAN_DEFAULT_NUM_PROBE;
    pCtrl->scanRSSIThreshold        = M2M_FASTCONNECT_DEFAULT_RSSI_THRESH;
    pCtrl->scanPassiveScanTime      = M2M_SCAN_DEFAULT_PASSIVE_SLOT_TIME;
    pCtrl->powerSaveDTIMInterval    = 0;
    pCtrl->rssi                     = 0;
    pCtrl->userHandle               = 0;

    pCtrl->assocInfoValid           = false;

    pCtrl->pfBSSFindNotifyCB        = NULL;
    pCtrl->pfConnectNotifyCB        = NULL;
    pCtrl->pfSystemTimeGetCurrentCB = NULL;
    pCtrl->pfAssociationInfoCB      = NULL;
    pCtrl->pfAssociationRSSICB      = NULL;
    pCtrl->pfWPSDiscoveryCB         = NULL;

#ifdef WDRV_WINC_NETWORK_MODE_SOCKET
    pCtrl->updateInProgress         = false;
    pCtrl->haveIPAddress            = false;
    pCtrl->useDHCP                  = true;

    pCtrl->ipAddress                = 0;
    pCtrl->netMask                  = 0;
    pCtrl->dnsServerAddress         = 0;
    pCtrl->gatewayAddress           = 0;
    pCtrl->dhcpServerAddress        = 0x010AA8C0;

    pCtrl->pfDHCPAddressEventCB     = NULL;
    pCtrl->pfICMPEchoResponseCB     = NULL;
    pCtrl->pfProvConnectInfoCB      = NULL;
    pCtrl->pfOTADownloadStatusCB    = NULL;
    pCtrl->pfSwitchFirmwareStatusCB = NULL;
    pCtrl->pfSSLCipherSuiteListCB   = NULL;
#endif
#ifdef WDRV_WINC_ENABLE_BLE
    pCtrl->bleActive                = false;
#endif

#ifdef WDRV_WINC_DEVICE_HOST_FILE_DOWNLOAD
    pCtrl->hostFileDcpt.handle      = HFD_INVALID_HANDLER;
    pCtrl->hostFileDcpt.pBuffer     = NULL;
    pCtrl->hostFileDcpt.getFileCB   = _WDRV_WINC_HostFileGetCallback;
    pCtrl->hostFileDcpt.readFileCB  = _WDRV_WINC_HostFileReadHIFCallback;
    pCtrl->hostFileDcpt.eraseFileCB = _WDRV_WINC_HostFileEraseCallback;

    pCtrl->pfHostFileCB             = NULL;
#endif
}

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver System Implementation
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    SYS_MODULE_OBJ WDRV_WINC_Initialize
    (
        const SYS_MODULE_INDEX index,
        const SYS_MODULE_INIT *const init
    )

  Summary:
    System interface initialization of the WINC driver.

  Description:
    This is the function that initializes the WINC driver. It is called by
    the system.

  Remarks:
    See wdrv_winc_api.h for usage information.

*/

SYS_MODULE_OBJ WDRV_WINC_Initialize
(
    const SYS_MODULE_INDEX index,
    const SYS_MODULE_INIT *const init
)
{
    WDRV_WINC_DCPT *pDcpt;

    if (WDRV_WINC_SYS_IDX_0 == index)
    {
        const WDRV_WINC_SYS_INIT* const pInitData = (const WDRV_WINC_SYS_INIT* const)init;

        pDcpt = &wincDescriptor[0];

        if (true == pDcpt->isInit)
        {
            return (SYS_MODULE_OBJ)pDcpt;
        }

#ifndef WDRV_WINC_DEVICE_USE_SYS_DEBUG
        pfWINCDebugPrintCb = NULL;
#endif

        wincCtrlDescriptor.intent               = DRV_IO_INTENT_READ;
        wincCtrlDescriptor.userHandle           = 0;
        wincCtrlDescriptor.extSysStat           = (WDRV_WINC_SYS_STATUS)SYS_STATUS_UNINITIALIZED;
        wincCtrlDescriptor.drvSemaphoresCreated = false;

        if (NULL != pInitData)
        {
            WDRV_WINC_SPIInitialize(pInitData->pSPICfg);

            wincCtrlDescriptor.intSrc = pInitData->intSrc;
        }

#ifdef WDRV_WINC_DEVICE_LITE_DRIVER
        winc_bsp_init();
#endif
    }
#ifdef WDRV_WINC_NETWORK_USE_HARMONY_TCPIP
    else if (TCPIP_MODULE_MAC_WINC == index)
    {
        uint8_t i;
        const TCPIP_MAC_MODULE_CTRL *pStackInitData;
        TCPIP_MAC_PACKET *ptrPacket;

        if (NULL == init)
        {
            return SYS_MODULE_OBJ_INVALID;
        }

        pStackInitData = ((TCPIP_MAC_INIT *)init)->macControl;

        if (NULL == pStackInitData)
        {
            return SYS_MODULE_OBJ_INVALID;
        }

        pDcpt = &wincDescriptor[1];

        WDRV_DBG_TRACE_PRINT("WDRV_WINC_Initialize(%s)\r\n", (true == pDcpt->isInit) ? "partial" : "full");

        if (true == pDcpt->isInit)
        {
            return (SYS_MODULE_OBJ)pDcpt;
        }

        _WDRV_WINC_PacketQueueInit(&wincMACDescriptor.packetPoolFreeList);

        for (i=0; i<WDRV_WINC_PACKET_POOL_MIN_THRES; i++)
        {
            ptrPacket = pStackInitData->pktAllocF(sizeof(TCPIP_MAC_PACKET), MAX_RX_PACKET_SIZE, 0);

            if (NULL == ptrPacket)
            {
                break;
            }

            _WDRV_WINC_PacketQueueInsert(&wincMACDescriptor.packetPoolFreeList, ptrPacket);
        }

        _WDRV_WINC_PacketQueueInit(&wincMACDescriptor.ethRxPktList);

        for (i=0; i<MULTICAST_FILTER_SIZE; i++)
        {
            memset(&wincMACDescriptor.multicastFilterList[i], 0, sizeof(TCPIP_MAC_ADDR));
        }
        OSAL_SEM_Create(&wincMACDescriptor.multicastFilterListSemaphore, OSAL_SEM_TYPE_BINARY, 1, 1);

        wincMACDescriptor.eventF       = pStackInitData->eventF;
        wincMACDescriptor.pktAllocF    = pStackInitData->pktAllocF;
        wincMACDescriptor.pktFreeF     = pStackInitData->pktFreeF;
        wincMACDescriptor.pktAckF      = pStackInitData->pktAckF;
        wincMACDescriptor.eventParam   = pStackInitData->eventParam;
        wincMACDescriptor.controlFlags = pStackInitData->controlFlags;
        wincMACDescriptor.eventMask    = 0;
        wincMACDescriptor.events       = 0;
        OSAL_SEM_Create(&wincMACDescriptor.eventSemaphore, OSAL_SEM_TYPE_BINARY, 1, 1);

        wincMACDescriptor.pCurRxPacket = NULL;
        OSAL_SEM_Create(&wincMACDescriptor.curRxPacketSemaphore, OSAL_SEM_TYPE_BINARY, 1, 1);
    }
#endif
    else
    {
        return SYS_MODULE_OBJ_INVALID;
    }

    /* Set initial state. */
    pDcpt->isInit  = true;
    pDcpt->isOpen  = false;
    pDcpt->sysStat = SYS_STATUS_BUSY;
    pDcpt->pCtrl   = &wincCtrlDescriptor;
#ifdef WDRV_WINC_NETWORK_USE_HARMONY_TCPIP
    pDcpt->pMac    = &wincMACDescriptor;
#endif

    return (SYS_MODULE_OBJ)pDcpt;
}

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_Deinitialize(SYS_MODULE_OBJ object)

  Summary:
    WINC driver deinitialization function.

  Description:
    This is the function that deinitializes the WINC.
    It is called by the system.

  Remarks:
    See wdrv_winc_api.h for usage information.

*/

void WDRV_WINC_Deinitialize(SYS_MODULE_OBJ object)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)object;

    if ((SYS_MODULE_OBJ_INVALID == object) || (NULL == pDcpt))
    {
        return;
    }

    pDcpt->sysStat = SYS_STATUS_UNINITIALIZED;

    if (pDcpt == &wincDescriptor[0])
    {
        if (true == pDcpt->pCtrl->drvSemaphoresCreated)
        {
            OSAL_SEM_Post(&pDcpt->pCtrl->drvEventSemaphore);
#ifdef WDRV_WINC_DEVICE_HOST_FILE_DOWNLOAD
            OSAL_SEM_Post(&pDcpt->pCtrl->hostFileDcpt.hfdSemaphore);
#endif
        }
    }
#ifdef WDRV_WINC_NETWORK_USE_HARMONY_TCPIP
    else if (pDcpt == &wincDescriptor[1])
    {
        OSAL_SEM_Delete(&wincMACDescriptor.multicastFilterListSemaphore);
        OSAL_SEM_Delete(&wincMACDescriptor.eventSemaphore);
        OSAL_SEM_Delete(&wincMACDescriptor.curRxPacketSemaphore);

        wincMACDescriptor.eventF        = NULL;
        wincMACDescriptor.pktAllocF     = NULL;
        wincMACDescriptor.pktFreeF      = NULL;
        wincMACDescriptor.pktAckF       = NULL;

        while (NULL != _WDRV_WINC_PacketQueueRemove(&wincMACDescriptor.ethRxPktList))
        {
        }

        while (NULL != _WDRV_WINC_PacketQueueRemove(&wincMACDescriptor.packetPoolFreeList))
        {
        }
    }
#endif

    /* Clear internal state. */
    pDcpt->isOpen = false;
}

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_Reinitialize
    (
        SYS_MODULE_OBJ object,
        const SYS_MODULE_INIT *const init
    )

  Summary:
    WINC driver reinitialization function.

  Description:
    This is the function that re-initializes the WINC.
    It is called by the system.

  Remarks:
    See wdrv_winc_api.h for usage information.

*/

void WDRV_WINC_Reinitialize
(
    SYS_MODULE_OBJ object,
    const SYS_MODULE_INIT *const init
)
{
}

//*******************************************************************************
/*
  Function:
    SYS_STATUS WDRV_WINC_Status(SYS_MODULE_OBJ object)

  Summary:
    Provides the current status of the WINC driver module.

  Description:
    This function provides the current status of the WINC driver module.

  Remarks:
    See wdrv_winc_api.h for usage information.

*/

SYS_STATUS WDRV_WINC_Status(SYS_MODULE_OBJ object)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)object;

    if ((SYS_MODULE_OBJ_INVALID == object) || (NULL == pDcpt))
    {
        return SYS_STATUS_ERROR;
    }

    if ((SYS_STATUS_UNINITIALIZED == pDcpt->sysStat) && (true == pDcpt->isInit))
    {
        return SYS_STATUS_BUSY;
    }

    return pDcpt->sysStat;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_SYS_STATUS WDRV_WINC_StatusExt(SYS_MODULE_OBJ object)

  Summary:
    Provides the extended system status of the PIC32MZW driver module.

  Description:
    This function provides the extended system status of the PIC32MZW driver
    module.

  Remarks:
    See wdrv_pic32mzw.h for usage information.

*/

WDRV_WINC_SYS_STATUS WDRV_WINC_StatusExt(SYS_MODULE_OBJ object)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)object;

    if ((SYS_MODULE_OBJ_INVALID == object) || (NULL == pDcpt))
    {
        return (WDRV_WINC_SYS_STATUS)SYS_STATUS_ERROR;
    }

    if (NULL == pDcpt->pCtrl)
    {
        return (WDRV_WINC_SYS_STATUS)SYS_STATUS_ERROR;
    }

    if (pDcpt->pCtrl->extSysStat != (WDRV_WINC_SYS_STATUS)SYS_STATUS_UNINITIALIZED)
    {
        return pDcpt->pCtrl->extSysStat;
    }

    /* If not in extended state, just return normal status. */
    return (WDRV_WINC_SYS_STATUS)pDcpt->sysStat;
}

#ifdef WDRV_WINC_NETWORK_USE_HARMONY_TCPIP
//*******************************************************************************
/*
  Function:
    void WDRV_WINC_MACTasks(SYS_MODULE_OBJ object)

  Summary:
    Maintains the WINC MAC drivers state machine.

  Description:
    This function is used to maintain the driver's internal state machine.

  Remarks:
    See wdrv_winc_api.h for usage information.

*/

void WDRV_WINC_MACTasks(SYS_MODULE_OBJ object)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)object;

    if ((SYS_MODULE_OBJ_INVALID == object) || (NULL == pDcpt))
    {
        return;
    }

    switch (pDcpt->sysStat)
    {
        /* Uninitialised state. */
        case SYS_STATUS_UNINITIALIZED:
        {
            if (true == pDcpt->isInit)
            {
                pDcpt->isInit = false;
            }

            break;
        }

        case SYS_STATUS_BUSY:
        {
            if (SYS_STATUS_READY == wincDescriptor[0].sysStat)
            {
                _WDRV_WINC_MACCheckRecvPacket(pDcpt);

                pDcpt->sysStat = SYS_STATUS_READY;
            }
            break;
        }

        /* Running steady state. */
        case SYS_STATUS_READY:
        {
            break;
        }

        /* Error state.*/
        case SYS_STATUS_ERROR:
        {
            break;
        }

        default:
        {
            pDcpt->sysStat = SYS_STATUS_ERROR;
            break;
        }
    }
}
#endif

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_Tasks(SYS_MODULE_OBJ object)

  Summary:
    Maintains the WINC drivers state machine.

  Description:
    This function is used to maintain the driver's internal state machine.

  Remarks:
    See wdrv_winc_api.h for usage information.

*/

void WDRV_WINC_Tasks(SYS_MODULE_OBJ object)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)object;

    if ((SYS_MODULE_OBJ_INVALID == object) || (NULL == pDcpt))
    {
        return;
    }

    switch (pDcpt->sysStat)
    {
        /* Uninitialised state. */
        case SYS_STATUS_UNINITIALIZED:
        {
            if (true == pDcpt->isInit)
            {
                if (true == pDcpt->pCtrl->drvSemaphoresCreated)
                {
                    /* Destroy M2M HIF semaphore. */
                    OSAL_SEM_Delete(&pDcpt->pCtrl->drvEventSemaphore);
#ifdef WDRV_WINC_DEVICE_HOST_FILE_DOWNLOAD
                    OSAL_SEM_Delete(&pDcpt->pCtrl->hostFileDcpt.hfdSemaphore);
#endif
                    pDcpt->pCtrl->drvSemaphoresCreated = false;
                }

                pDcpt->pCtrl->intent     = DRV_IO_INTENT_READ;
                pDcpt->pCtrl->extSysStat = (WDRV_WINC_SYS_STATUS)SYS_STATUS_UNINITIALIZED;
#ifdef WDRV_WINC_DEVICE_WINC3400
                pDcpt->pCtrl->isBLEInitStarted = false;
#endif
#ifndef WDRV_WINC_DEVICE_NO_GET_WIFI_STATE
                if (WIFI_STATE_START == m2m_wifi_get_state())
#endif
                {
                    m2m_wifi_deinit(NULL);
                }

#ifdef WDRV_WINC_NETWORK_MODE_SOCKET
                socketDeinit();
#endif

                /* De-initialise SPI handling. */
                WDRV_WINC_SPIDeinitialize();

                /* De-initialise the interrupts. */
                WDRV_WINC_INTDeinitialize(pDcpt->pCtrl->intSrc);

                WDRV_WINC_GPIOChipEnableDeassert();
                WDRV_WINC_GPIOResetAssert();

                pDcpt->isInit = false;
            }

            break;
        }

        case SYS_STATUS_BUSY:
        {
            tstrWifiInitParam wifiParam;
            uint32_t chipId;

            if (NULL == pDcpt->pCtrl)
            {
                pDcpt->sysStat = SYS_STATUS_ERROR;
                break;
            }

#ifdef WDRV_WINC_DEVICE_WINC3400
            if (true == pDcpt->pCtrl->isBLEInitStarted)
            {
                if (OSAL_RESULT_TRUE == OSAL_SEM_Pend(&pDcpt->pCtrl->drvEventSemaphore, OSAL_WAIT_FOREVER))
                {
#ifdef WDRV_WINC_DEVICE_LITE_DRIVER
                    if (M2M_SUCCESS != m2m_wifi_handle_events(NULL))
#else
                    if (M2M_SUCCESS != m2m_wifi_handle_events())
#endif
                    {
                        OSAL_SEM_Post(&pDcpt->pCtrl->drvEventSemaphore);
                    }
                }

                break;
            }
#endif
            WDRV_DBG_INFORM_PRINT("WINC: Initializing...\r\n");

            /* Open SPI handling. */
            if (false == WDRV_WINC_SPIOpen())
            {
                pDcpt->sysStat = SYS_STATUS_ERROR;
                break;
            }

#ifndef WDRV_WINC_DEVICE_SPLIT_INIT
            pDcpt->sysStat = SYS_STATUS_READY;
#else
            if (M2M_SUCCESS != m2m_wifi_init_hold())
            {
                WDRV_DBG_ERROR_PRINT("m2m_wifi_init_hold failed\r\n");
                pDcpt->pCtrl->extSysStat = WDRV_WINC_SYS_STATUS_ERROR_DEVICE_NOT_FOUND;
                pDcpt->sysStat = SYS_STATUS_ERROR;
                break;
            }
            else
            {
#ifdef WDRV_WINC_DEVICE_USE_FLASH_INIT
                tstrFlashState  strFlashState;
                m2m_flash_get_state(&strFlashState);
                WDRV_DBG_INFORM_PRINT("FlashAccess:%x:%d%d\r\n", strFlashState.u16LastAccessId, strFlashState.u8Success, strFlashState.u8Changed);

                m2m_flash_init();
#endif
            }
#endif
#ifdef WDRV_WINC_DEVICE_LITE_DRIVER
            chipId = winc_chip_get_id();
#else
            chipId = m2m_wifi_get_chipId();
#endif
            chipId >>= 16;
#ifdef WDRV_WINC_DEVICE_WINC1500
            if (chipId != 0x15U)
#endif
#ifdef WDRV_WINC_DEVICE_WINC3400
            if (chipId != 0x34U)
#endif
            {
                pDcpt->pCtrl->extSysStat = WDRV_WINC_SYS_STATUS_ERROR_DEVICE_NOT_FOUND;
                pDcpt->sysStat = SYS_STATUS_ERROR;
                break;
            }

            /* Create a semaphore for tracking WINC HIF events. */
            if (OSAL_RESULT_TRUE != OSAL_SEM_Create(&pDcpt->pCtrl->drvEventSemaphore,
                                                    OSAL_SEM_TYPE_COUNTING, 10, 0))
            {
                pDcpt->sysStat = SYS_STATUS_ERROR;
                return;
            }

            /* Initialise the interrupts. */
            WDRV_WINC_INTInitialize(object, pDcpt->pCtrl->intSrc);

            memset(&wifiParam, 0, sizeof(tstrWifiInitParam));
            /* Construct M2M WiFi initialisation structure. */
            wifiParam.pfAppWifiCb = _WDRV_WINC_WifiCallback;
#ifndef WDRV_WINC_NETWORK_MODE_SOCKET
            /* Ethernet mode required callback and Ethernet buffers. */
            wifiParam.strEthInitParam.pfAppEthCb = _WDRV_WINC_EthernetCallback;
            wifiParam.strEthInitParam.au8ethRcvBuf = NULL;
            wifiParam.strEthInitParam.u16ethRcvBufSize = 0;
#ifdef WDRV_WINC_DEVICE_DYNAMIC_BYPASS_MODE
#ifdef WDRV_WINC_DEVICE_LITE_DRIVER
            wifiParam.strEthInitParam.u8EthernetEnable = M2M_WIFI_MODE_ETHERNET;
#else
            wifiParam.strEthInitParam.u8EthernetEnable = true;
#endif
#endif
#else
#ifdef WDRV_WINC_DEVICE_DYNAMIC_BYPASS_MODE
            wifiParam.strEthInitParam.u8EthernetEnable = false;
#endif
#endif

            /* Initialise M2M WiFi and thus WINC device. */
#ifndef WDRV_WINC_DEVICE_SPLIT_INIT
            if (M2M_SUCCESS != m2m_wifi_init(&wifiParam))
#else
            if (M2M_SUCCESS != m2m_wifi_init_start(&wifiParam))
#endif
            {
                WDRV_DBG_ERROR_PRINT("m2m_wifi_init_start failed\r\n");
                OSAL_SEM_Delete(&pDcpt->pCtrl->drvEventSemaphore);
                pDcpt->pCtrl->extSysStat = WDRV_WINC_SYS_STATUS_ERROR_DEVICE_FAILURE;
                pDcpt->sysStat = SYS_STATUS_ERROR;
                return;
            }

#ifdef WDRV_WINC_NETWORK_MODE_SOCKET
            /* Socket mode requires the socket interface and SSL be initialised. */
            socketInit();

            m2m_ssl_init(&_WDRV_WINC_SSLCallback);
#endif
            _WDRV_WINC_ResetCtrlDcpt(&wincCtrlDescriptor);

#ifdef WDRV_WINC_NETWORK_MODE_SOCKET
#if defined(WDRV_WINC_DEVICE_WINC1500)
#ifdef WDRV_WINC_DEVICE_HOST_FILE_DOWNLOAD
            m2m_ota_init(_WDRV_WINC_OTAUpdateCallback, NULL, _WDRV_WINC_HostFileGetCallback);

            OSAL_SEM_Create(&wincCtrlDescriptor.hostFileDcpt.hfdSemaphore, OSAL_SEM_TYPE_BINARY, 1, 1);
#else
            m2m_ota_init(&_WDRV_WINC_OTAUpdateCallback, NULL);
#endif // #ifdef WDRV_WINC_DEVICE_HOST_FILE_DOWNLOAD
#elif defined(WDRV_WINC_DEVICE_WINC3400)
#ifndef WDRV_WINC_DEVICE_LITE_DRIVER
            m2m_ota_init(_WDRV_WINC_OTAUpdateCallback);
#else
            m2m_ota_init(_WDRV_WINC_OTAUpdateCallback, NULL);
#endif
#endif
#endif
            pDcpt->pCtrl->drvSemaphoresCreated = true;

            /* Retrieve MAC address from WINC device. */
            m2m_wifi_get_mac_address(pDcpt->pCtrl->ethAddress);

#ifdef WDRV_WINC_DEVICE_WINC3400
            /* Delay moving to READY until BLE core initializes. */
            pDcpt->pCtrl->isBLEInitStarted = true;
#else
            pDcpt->sysStat = SYS_STATUS_READY;
#endif

#ifndef WDRV_WINC_NETWORK_MODE_SOCKET
            pDcpt->pCtrl->isEthBufSet              = false;
            pDcpt->pCtrl->ethFragNum               = 1;
            pDcpt->pCtrl->pfEthernetMsgRecvCB      = NULL;
#endif
            WDRV_DBG_INFORM_PRINT("WINC: Initializing...complete\r\n");
            break;
        }

        /* Running steady state. */
        case SYS_STATUS_READY:
        {
            if (OSAL_RESULT_TRUE == OSAL_SEM_Pend(&pDcpt->pCtrl->drvEventSemaphore, OSAL_WAIT_FOREVER))
            {
                if (SYS_STATUS_READY != pDcpt->sysStat)
                {
                    break;
                }

                if (0 != (pDcpt->pCtrl->intent & DRV_IO_INTENT_EXCLUSIVE))
                {
                    break;
                }

#ifdef WDRV_WINC_DEVICE_LITE_DRIVER
                if (M2M_SUCCESS != m2m_wifi_handle_events(NULL))
#else
                if (M2M_SUCCESS != m2m_wifi_handle_events())
#endif
                {
                    OSAL_SEM_Post(&pDcpt->pCtrl->drvEventSemaphore);
                }
            }

            break;
        }

        /* Error state.*/
        case SYS_STATUS_ERROR:
        {
            break;
        }

        default:
        {
            pDcpt->sysStat = SYS_STATUS_ERROR;
            break;
        }
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver Client Implementation
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_DebugRegisterCallback
    (
        WDRV_WINC_DEBUG_PRINT_CALLBACK const pfDebugPrintCallback
    )

  Summary:
    Register callback for debug serial stream.

  Description:
    The debug serial stream provides a printf-like stream of messages from within
    the WINC driver. The caller can provide a function to be called when
    output is available.

  Remarks:
    See wdrv_winc.h for usage information.

 */

#ifndef WDRV_WINC_DEVICE_USE_SYS_DEBUG
void WDRV_WINC_DebugRegisterCallback
(
    WDRV_WINC_DEBUG_PRINT_CALLBACK const pfDebugPrintCallback
)
{
    pfWINCDebugPrintCb = pfDebugPrintCallback;
}
#endif

//*******************************************************************************
/*
  Function:
    DRV_HANDLE WDRV_WINC_Open(const SYS_MODULE_INDEX index, const DRV_IO_INTENT intent)

  Summary:
    Opens an instance of the WINC driver.

  Description:
    Opens an instance of the WINC driver and returns a handle which must be
    used when calling other driver functions.

  Remarks:
    See wdrv_winc.h for usage information.

*/

DRV_HANDLE WDRV_WINC_Open(const SYS_MODULE_INDEX index, const DRV_IO_INTENT intent)
{
    WDRV_WINC_DCPT *pDcpt = NULL;

    if (WDRV_WINC_SYS_IDX_0 == index)
    {
        pDcpt = &wincDescriptor[0];

        if (NULL == pDcpt->pCtrl)
        {
            return DRV_HANDLE_INVALID;
        }
    }
#ifdef WDRV_WINC_NETWORK_USE_HARMONY_TCPIP
    else if (TCPIP_MODULE_MAC_WINC == index)
    {
        pDcpt = &wincDescriptor[1];

        if (NULL == pDcpt->pMac)
        {
            return DRV_HANDLE_INVALID;
        }
    }
#endif
    else
    {
        return DRV_HANDLE_INVALID;
    }

    /* Check that the driver has been initialised. */
    if (false == pDcpt->isInit)
    {
        return DRV_HANDLE_INVALID;
    }

    /* Check if the driver has already been opened. */
    if (true == pDcpt->isOpen)
    {
        if ((0U == index) && (pDcpt->pCtrl->intent != intent))
        {
            return DRV_HANDLE_INVALID;
        }

        return (DRV_HANDLE)pDcpt;
    }

    if ((false == wincDescriptor[0].isOpen) && (false == wincDescriptor[1].isOpen))
    {
        _WDRV_WINC_ResetCtrlDcpt(pDcpt->pCtrl);
    }

    if (WDRV_WINC_SYS_IDX_0 == index)
    {
        pDcpt->pCtrl->handle    = (DRV_HANDLE)pDcpt;
        pDcpt->pCtrl->intent    = intent;

        /* Check if opening for exclusive access to NVM rather than whole device. */

        if (0 != (pDcpt->pCtrl->intent & DRV_IO_INTENT_EXCLUSIVE))
        {
#ifdef WDRV_WINC_DEVICE_SPLIT_INIT
            m2m_wifi_deinit(NULL);
#endif
            if (M2M_SUCCESS != m2m_wifi_download_mode())
            {
                return DRV_HANDLE_INVALID;
            }

            pDcpt->isOpen = true;

            return (DRV_HANDLE)pDcpt;
        }
    }
#ifdef WDRV_WINC_NETWORK_USE_HARMONY_TCPIP
    else
    {
        pDcpt->pMac->handle = (DRV_HANDLE)pDcpt;
    }
#endif

    pDcpt->isOpen = true;

    return (DRV_HANDLE)pDcpt;
}

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_Close(DRV_HANDLE handle)

  Summary:
    Closes an instance of the WINC driver.

  Description:
    This is the function that closes an instance of the MAC.
    All per client data is released and the handle can no longer be used
    after this function is called.

  Remarks:
    See wdrv_winc.h for usage information.

*/

void WDRV_WINC_Close(DRV_HANDLE handle)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl))
    {
        return;
    }

    if (handle == pDcpt->pCtrl->handle)
    {
        pDcpt->pCtrl->isConnected   = false;
#ifdef WDRV_WINC_NETWORK_MODE_SOCKET
        pDcpt->pCtrl->haveIPAddress = false;
#endif
    }

    pDcpt->isOpen = false;
}

#ifdef WDRV_WINC_NETWORK_USE_HARMONY_TCPIP
// *****************************************************************************
// *****************************************************************************
// Section: WINC MAC Driver Implementation
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

  Remarks:
    See wdrv_winc_mac.h for usage information.

*/

bool WDRV_WINC_MACLinkCheck(DRV_HANDLE handle)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl))
    {
        return false;
    }

    return pDcpt->pCtrl->isConnected;
}

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

  Remarks:
    See wdrv_winc_mac.h for usage information.

*/

TCPIP_MAC_RES WDRV_WINC_MACRxFilterHashTableEntrySet
(
    DRV_HANDLE handle,
    const TCPIP_MAC_ADDR* DestMACAddr
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    TCPIP_MAC_ADDR *pFirstFree;
    uint8_t i;
    uint8_t macHash;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl) || (NULL == pDcpt->pMac) || (NULL == DestMACAddr))
    {
        return TCPIP_MAC_RES_OP_ERR;
    }

    WDRV_DBG_TRACE_PRINT("WDRV_WINC_MACRxFilterHashTableEntrySet %02x:%02x:%02x:%02x:%02x:%02x\r\n",
            DestMACAddr->v[0], DestMACAddr->v[1], DestMACAddr->v[2],
            DestMACAddr->v[3], DestMACAddr->v[4], DestMACAddr->v[5]);

    macHash = 0;

    for (i=0; i<6; i++)
    {
        macHash |= DestMACAddr->v[i];
    }

    if (OSAL_RESULT_TRUE == OSAL_SEM_Pend(&pDcpt->pMac->multicastFilterListSemaphore, OSAL_WAIT_FOREVER))
    {
        if (0 == macHash)
        {
            for (i=0; i<MULTICAST_FILTER_SIZE; i++)
            {
                if (0 != pDcpt->pMac->multicastFilterList[i].v[0])
                {
                    if (WDRV_WINC_STATUS_OK !=
                            WDRV_WINC_MulticastMACFilterRemove((DRV_HANDLE)pDcpt,
                                                                   pDcpt->pMac->multicastFilterList[i].v))
                    {
                        OSAL_SEM_Post(&pDcpt->pMac->multicastFilterListSemaphore);
                        return TCPIP_MAC_RES_OP_ERR;
                    }

                    memset(&pDcpt->pMac->multicastFilterList[i], 0, sizeof(TCPIP_MAC_ADDR));
                }
            }
        }
        else
        {
            pFirstFree = NULL;

            for (i=0; i<MULTICAST_FILTER_SIZE; i++)
            {
                if (0 != pDcpt->pMac->multicastFilterList[i].v[0])
                {
                    if (0 == memcmp(DestMACAddr, &pDcpt->pMac->multicastFilterList[i], sizeof(TCPIP_MAC_ADDR)))
                    {
                        OSAL_SEM_Post(&pDcpt->pMac->multicastFilterListSemaphore);
                        return TCPIP_MAC_RES_OK;
                    }
                }
                else if (NULL == pFirstFree)
                {
                    pFirstFree = &pDcpt->pMac->multicastFilterList[i];
                }
            }

            if (NULL == pFirstFree)
            {
                OSAL_SEM_Post(&pDcpt->pMac->multicastFilterListSemaphore);
                return TCPIP_MAC_RES_OP_ERR;
            }

            if (WDRV_WINC_STATUS_OK != WDRV_WINC_MulticastMACFilterAdd((DRV_HANDLE)pDcpt, DestMACAddr->v))
            {
                OSAL_SEM_Post(&pDcpt->pMac->multicastFilterListSemaphore);
                return TCPIP_MAC_RES_OP_ERR;
            }

            memcpy(pFirstFree, DestMACAddr, sizeof(TCPIP_MAC_ADDR));
        }

        OSAL_SEM_Post(&pDcpt->pMac->multicastFilterListSemaphore);
    }

    return TCPIP_MAC_RES_OK;
}

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_MACPowerMode(DRV_HANDLE handle, TCPIP_MAC_POWER_MODE pwrMode)

  Summary:
    Change the power mode.

  Description:
    Not currently supported.

  Remarks:
    See wdrv_winc_mac.h for usage information.

*/

bool WDRV_WINC_MACPowerMode(DRV_HANDLE handle, TCPIP_MAC_POWER_MODE pwrMode)
{
    WDRV_DBG_TRACE_PRINT("WDRV_WINC_MACPowerMode\r\n");
    return false;
}

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_RES WDRV_WINC_MACPacketTx(DRV_HANDLE handle, TCPIP_MAC_PACKET* ptrPacket)

  Summary:
    Send an Ethernet frame via the WINC.

  Description:
    Takes an Ethernet frame from the TCP/IP stack and schedules it with the
      WINC.

  Remarks:
    See wdrv_winc_mac.h for usage information.

*/

TCPIP_MAC_RES WDRV_WINC_MACPacketTx(DRV_HANDLE handle, TCPIP_MAC_PACKET* ptrPacket)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    uint8_t *payLoadPtr;
    int pktLen = 0;

    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl) || (NULL == pDcpt->pMac))
    {
        return TCPIP_MAC_RES_PACKET_ERR;
    }

    if ((NULL == ptrPacket) || (NULL == ptrPacket->pDSeg))
    {
        return TCPIP_MAC_RES_PACKET_ERR;
    }

    if ((NULL == pDcpt->pMac->pktAllocF) || (NULL == pDcpt->pMac->pktAckF))
    {
        return TCPIP_MAC_RES_PACKET_ERR;
    }

#ifdef WDRV_WINC_MAC_TX_PKT_INSPECT_HOOK
    WDRV_WINC_MAC_TX_PKT_INSPECT_HOOK(ptrPacket);
#endif

    if ((false == pDcpt->pCtrl->isConnected) || (ptrPacket->pDSeg->segLen > MAX_TX_PACKET_SIZE))
    {
        return TCPIP_MAC_RES_PACKET_ERR;
    }

    if (NULL == ptrPacket->pDSeg->next)
    {
        if (WDRV_WINC_STATUS_OK != WDRV_WINC_EthernetSendPacket(
                    (DRV_HANDLE)pDcpt, ptrPacket->pDSeg->segLoad, ptrPacket->pDSeg->segLen))
        {
            return TCPIP_MAC_RES_PACKET_ERR;
        }

        pDcpt->pMac->pktAckF(ptrPacket, TCPIP_MAC_PKT_ACK_TX_OK, TCPIP_THIS_MODULE_ID);
    }
    else
    {
        WDRV_WINC_STATUS status;
        uint8_t *pktbuf;
        TCPIP_MAC_DATA_SEGMENT *pDSeg;

        pDSeg = ptrPacket->pDSeg;

        while (NULL != pDSeg)
        {
            pktLen += pDSeg->segLen;

            pDSeg = pDSeg->next;
        }

        if (pktLen > MAX_RX_PACKET_SIZE)
        {
            return TCPIP_MAC_RES_OP_ERR;
        }

        pktbuf = payLoadPtr = OSAL_Malloc(pktLen);

        if (NULL == pktbuf)
        {
            return TCPIP_MAC_RES_OP_ERR;
        }

        pDSeg = ptrPacket->pDSeg;

        while (NULL != pDSeg)
        {
            memcpy(pktbuf, pDSeg->segLoad, pDSeg->segLen);

            pktbuf += pDSeg->segLen;

            pDSeg = pDSeg->next;
        }

        pDcpt->pMac->pktAckF(ptrPacket, TCPIP_MAC_PKT_ACK_TX_OK, TCPIP_THIS_MODULE_ID);

        status = WDRV_WINC_EthernetSendPacket(handle, payLoadPtr, pktLen);

        OSAL_Free(payLoadPtr);

        if (WDRV_WINC_STATUS_OK != status)
        {
            return TCPIP_MAC_RES_PACKET_ERR;
        }
    }

    return TCPIP_MAC_RES_OK;
}

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_PACKET* WDRV_WINC_MACPacketRx
    (
        DRV_HANDLE handle,
        TCPIP_MAC_RES* pRes,
        TCPIP_MAC_PACKET_RX_STAT* pPktStat
    )

  Summary:
    Retrieve an Ethernet frame.

  Description:
    Called by the TCP/IP to retrieve the next received Ethernet frame.

  Remarks:
    See wdrv_winc_mac.h for usage information.

*/

TCPIP_MAC_PACKET* WDRV_WINC_MACPacketRx
(
    DRV_HANDLE handle,
    TCPIP_MAC_RES* pRes,
    TCPIP_MAC_PACKET_RX_STAT* pPktStat
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    TCPIP_MAC_PACKET* ptrPacket;

    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pMac))
    {
        return NULL;
    }

    ptrPacket = _WDRV_WINC_PacketQueueRemove(&pDcpt->pMac->ethRxPktList);

    if (NULL != ptrPacket)
    {
#ifdef WDRV_WINC_MAC_RX_PKT_INSPECT_HOOK
        WDRV_WINC_MAC_RX_PKT_INSPECT_HOOK(ptrPacket);
#endif
    }

    return ptrPacket;
}

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_RES WDRV_WINC_MACProcess(DRV_HANDLE handle)

  Summary:
    Regular update to MAC state machine.

  Description:
    Called by the TCP/IP to update the internal state machine.

  Remarks:
    See wdrv_winc_mac.h for usage information.

*/

TCPIP_MAC_RES WDRV_WINC_MACProcess(DRV_HANDLE handle)
{
    if (DRV_HANDLE_INVALID == handle)
    {
        return TCPIP_MAC_RES_OP_ERR;
    }

    return TCPIP_MAC_RES_OK;
}

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

  Remarks:
    See wdrv_winc_mac.h for usage information.

*/

TCPIP_MAC_RES WDRV_WINC_MACStatisticsGet
(
    DRV_HANDLE handle,
    TCPIP_MAC_RX_STATISTICS* pRxStatistics,
    TCPIP_MAC_TX_STATISTICS* pTxStatistics
)
{
    if (DRV_HANDLE_INVALID == handle)
    {
        return TCPIP_MAC_RES_OP_ERR;
    }

    if (NULL != pRxStatistics)
    {
        memset(pRxStatistics, 0, sizeof(TCPIP_MAC_RX_STATISTICS));
    }

    if (NULL != pTxStatistics)
    {
        memset(pTxStatistics, 0, sizeof(TCPIP_MAC_TX_STATISTICS));
    }

    return TCPIP_MAC_RES_OK;
}

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

  Remarks:
    See wdrv_winc_mac.h for usage information.

*/

TCPIP_MAC_RES WDRV_WINC_MACParametersGet
(
    DRV_HANDLE handle,
    TCPIP_MAC_PARAMETERS* pMacParams
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle and user pointer is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pMacParams))
    {
        return TCPIP_MAC_RES_IS_BUSY;
    }

    if (SYS_STATUS_READY == pDcpt->sysStat)
    {
        if (NULL != pMacParams)
        {
            WDRV_WINC_EthernetAddressGet(handle, pMacParams->ifPhyAddress.v);

            pMacParams->processFlags = (TCPIP_MAC_PROCESS_FLAG_RX | TCPIP_MAC_PROCESS_FLAG_TX);
            pMacParams->macType = TCPIP_MAC_TYPE_WLAN;
            pMacParams->linkMtu = TCPIP_MAC_LINK_MTU_WLAN;
        }

        return TCPIP_MAC_RES_OK;
    }

    return TCPIP_MAC_RES_IS_BUSY;
}

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

  Remarks:
    See wdrv_winc_mac.h for usage information.

*/

TCPIP_MAC_RES WDRV_WINC_MACRegisterStatisticsGet
(
    DRV_HANDLE handle,
    TCPIP_MAC_STATISTICS_REG_ENTRY* pRegEntries,
    int nEntries,
    int* pHwEntries
)
{
    return TCPIP_MAC_RES_OP_ERR;
}

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

  Remarks:
    See wdrv_winc_mac.h for usage information.

*/

size_t WDRV_WINC_MACConfigGet
(
    DRV_HANDLE handle,
    void* configBuff,
    size_t buffSize,
    size_t* pConfigSize
)
{
    if (NULL != pConfigSize)
    {
        *pConfigSize = sizeof(TCPIP_MODULE_MAC_WINC_CONFIG);
    }

    if ((NULL != configBuff) && (buffSize >= sizeof(TCPIP_MODULE_MAC_WINC_CONFIG)))
    {
        return sizeof(TCPIP_MODULE_MAC_WINC_CONFIG);
    }

    return 0;
}

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

  Remarks:
    See wdrv_winc_mac.h for usage information.

*/

bool WDRV_WINC_MACEventMaskSet
(
    DRV_HANDLE handle,
    TCPIP_MAC_EVENT macEvents,
    bool enable
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pMac))
    {
        return false;
    }

    if (OSAL_RESULT_TRUE == OSAL_SEM_Pend(&pDcpt->pMac->eventSemaphore, OSAL_WAIT_FOREVER))
    {
        if (true == enable)
        {
            pDcpt->pMac->eventMask |= macEvents;
        }
        else
        {
            pDcpt->pMac->eventMask &= ~macEvents;
        }

        OSAL_SEM_Post(&pDcpt->pMac->eventSemaphore);

        return true;
    }
    else
    {
        WDRV_DBG_ERROR_PRINT("Event mask failed to lock event semaphore\r\n");

        return false;
    }
}

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_MACEventAcknowledge(DRV_HANDLE handle, TCPIP_MAC_EVENT macEvents)

  Summary:
    Acknowledge an event.

  Description:
    Indicates that certain events are to be acknowledged and cleared.

  Remarks:
    See wdrv_winc_mac.h for usage information.

*/

bool WDRV_WINC_MACEventAcknowledge(DRV_HANDLE handle, TCPIP_MAC_EVENT macEvents)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pMac))
    {
        return false;
    }

    if (OSAL_RESULT_TRUE == OSAL_SEM_Pend(&pDcpt->pMac->eventSemaphore, OSAL_WAIT_FOREVER))
    {
        pDcpt->pMac->events &= ~macEvents;
        OSAL_SEM_Post(&pDcpt->pMac->eventSemaphore);

        return true;
    }
    else
    {
        WDRV_DBG_ERROR_PRINT("Event ACK failed to lock event semaphore\r\n");

        return false;
    }
}

//*******************************************************************************
/*
  Function:
    TCPIP_MAC_EVENT WDRV_WINC_MACEventPendingGet(DRV_HANDLE handle)

  Summary:
    Retrieve the current events.

  Description:
    Returns the current event state.

  Remarks:
    See wdrv_winc_mac.h for usage information.

*/

TCPIP_MAC_EVENT WDRV_WINC_MACEventPendingGet(DRV_HANDLE handle)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    TCPIP_MAC_EVENT events;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pMac))
    {
        return 0;
    }

    if (OSAL_RESULT_TRUE == OSAL_SEM_Pend(&pDcpt->pMac->eventSemaphore, OSAL_WAIT_FOREVER))
    {
        events = pDcpt->pMac->events;
        OSAL_SEM_Post(&pDcpt->pMac->eventSemaphore);

        return events;
    }
    else
    {
        WDRV_DBG_ERROR_PRINT("Event get failed to lock event semaphore\r\n");

        return TCPIP_MAC_EV_NONE;
    }
}
#endif

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver General Implementation
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MulticastMACFilterAdd
    (
        DRV_HANDLE handle,
        const uint8_t *pEthAddress
    )

  Summary:
    Adds an Ethernet address to the multicast filter.

  Description:
    To receive multicast packets the multicast Ethernet address must be added
    to the receive filter on the WINC.

  Remarks:
    See wdrv_winc.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_MulticastMACFilterAdd
(
    DRV_HANDLE handle,
    const uint8_t *pEthAddress
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle and user pointer is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pEthAddress))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Update multicast in WINC device. */
    if (M2M_SUCCESS != m2m_wifi_enable_mac_mcast((uint8_t*)pEthAddress, 1))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MulticastMACFilterRemove
    (
        DRV_HANDLE handle,
        const uint8_t *pEthAddress
    )

  Summary:
    Removes an Ethernet address from the multicast filter.

  Description:
    To stop receiving multicast packets the multicast Ethernet address must be
    removed from the receive filter on the WINC.

  Remarks:
    See wdrv_winc.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_MulticastMACFilterRemove
(
    DRV_HANDLE handle,
    const uint8_t *pEthAddress
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle and user pointer is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pEthAddress))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Update multicast in WINC device. */
    if (M2M_SUCCESS != m2m_wifi_enable_mac_mcast((uint8_t*)pEthAddress, 0))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_EthernetAddressGet
    (
        DRV_HANDLE handle,
        uint8_t *pEthAddress
    )

  Summary:
    Returns the current Ethernet address assigned to the WINC.

  Description:
    Returns the current Ethernet address assigned to the WINC.

  Remarks:
    See wdrv_winc.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_EthernetAddressGet
(
    DRV_HANDLE handle,
    uint8_t *pEthAddress
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle and user pointer is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl) || (NULL == pEthAddress))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Copy the WINC MAC address to caller buffer. */
    memcpy(pEthAddress, pDcpt->pCtrl->ethAddress, 6);

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_OP_MODE WDRV_WINC_OperatingModeGet(DRV_HANDLE handle)

  Summary:
    Returns the current operating mode of the WINC.

  Description:
    Returns the current operating mode of the WINC.

  Remarks:
    See wdrv_winc.h for usage information.

*/

WDRV_WINC_OP_MODE WDRV_WINC_OperatingModeGet(DRV_HANDLE handle)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl))
    {
        return WDRV_WINC_OP_MODE_UNKNOWN;
    }

    if (false == pDcpt->pCtrl->isAP)
    {
        /* WINC is acting as a STA. */
        return WDRV_WINC_OP_MODE_STA;
    }
    else if (false == pDcpt->pCtrl->isProvisioning)
    {
        /* WINC is acting as an AP. */
        return WDRV_WINC_OP_MODE_AP;
    }
    else
    {
        /* WINC is acting as a provisioning AP. */
        return WDRV_WINC_OP_MODE_PROV_AP;
    }
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_UserHandleSet(DRV_HANDLE handle, uintptr_t userHandle)

  Summary:
    Associates a caller supplied handle with the driver instance.

  Description:
    The caller is able to associate a user supplied handle with this instance of
    the WINC driver which can be later retrieved when any callbacks are called
    by the driver by calling WDRV_WINC_UserHandleGet.

  Remarks:
    See wdrv_winc.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_UserHandleSet(DRV_HANDLE handle, uintptr_t userHandle)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    pDcpt->pCtrl->userHandle = userHandle;

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    uintptr_t WDRV_WINC_UserHandleGet(DRV_HANDLE handle)

  Summary:
    Returns the current user supplied handle associated with the driver.

  Description:
    This function returns the handle previously associated with the driver
    instance by a call to WDRV_WINC_UserHandleSet.

  Remarks:
    See wdrv_winc.h for usage information.

*/

uintptr_t WDRV_WINC_UserHandleGet(DRV_HANDLE handle)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl))
    {
        return 0;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return 0;
    }

    return pDcpt->pCtrl->userHandle;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_InfoDriverVersionGet
    (
        DRV_HANDLE handle,
        WDRV_WINC_DRIVER_VERSION_INFO *const pDriverVersion
    )

  Summary:
    Returns the drivers version information.

  Description:
    Returns information on the drivers version and HIF protocol support.

  Remarks:
    See wdrv_winc.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_InfoDriverVersionGet
(
    DRV_HANDLE handle,
    WDRV_WINC_DRIVER_VERSION_INFO *const pDriverVersion
)
{
    const WDRV_WINC_DCPT *const pDcpt = (const WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle and user pointer is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDriverVersion))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    /* Copy driver version information. */
    memset(pDriverVersion, 0, sizeof(WDRV_WINC_DRIVER_VERSION_INFO));

#if defined(WDRV_WINC_DEVICE_WINC1500)
    pDriverVersion->version.major = M2M_RELEASE_VERSION_MAJOR_NO;
    pDriverVersion->version.minor = M2M_RELEASE_VERSION_MINOR_NO;
    pDriverVersion->version.patch = M2M_RELEASE_VERSION_PATCH_NO;
#elif defined(WDRV_WINC_DEVICE_WINC3400)
    pDriverVersion->version.major = M2M_DRIVER_VERSION_MAJOR_NO;
    pDriverVersion->version.minor = M2M_DRIVER_VERSION_MINOR_NO;
    pDriverVersion->version.patch = M2M_DRIVER_VERSION_PATCH_NO;
    pDriverVersion->hif.major     = M2M_HIF_MAJOR_VALUE;
    pDriverVersion->hif.minor     = M2M_HIF_MINOR_VALUE;
    pDriverVersion->hif.block     = M2M_HIF_BLOCK_VALUE;
#endif

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_InfoDeviceFirmwareVersionGet
    (
        DRV_HANDLE handle,
        bool active,
        WDRV_WINC_FIRMWARE_VERSION_INFO *const pFirmwareVersion
    )

  Summary:
    Returns the WINC firmware version information.

  Description:
    Returns information on the WINC firmware version, HIF protocol support
      and build date/time.

  Remarks:
    See wdrv_winc.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_InfoDeviceFirmwareVersionGet
(
    DRV_HANDLE handle,
    bool active,
    WDRV_WINC_FIRMWARE_VERSION_INFO *const pFirmwareVersion
)
{
    const WDRV_WINC_DCPT *const pDcpt = (const WDRV_WINC_DCPT *const)handle;

    tstrM2mRev info;

    /* Ensure the driver handle and user pointer is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pFirmwareVersion))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    if (true == active)
    {
        /* For active partition retrieve version information. */
        if (M2M_SUCCESS != m2m_wifi_get_firmware_version(&info))
        {
            return WDRV_WINC_STATUS_REQUEST_ERROR;
        }
    }
    else
    {
#ifndef WDRV_WINC_NETWORK_MODE_SOCKET
        /* Non-active partition not supported for Ethernet mode. */
        return WDRV_WINC_STATUS_REQUEST_ERROR;
#else
        /* Retrieve non-active partition information. */
        if (M2M_SUCCESS != m2m_ota_get_firmware_version(&info))
        {
            return WDRV_WINC_STATUS_REQUEST_ERROR;
        }
#endif
    }

    /* Copy firmware version information. */
    memset(pFirmwareVersion, 0, sizeof(WDRV_WINC_FIRMWARE_VERSION_INFO));

    pFirmwareVersion->version.major = info.u8FirmwareMajor;
    pFirmwareVersion->version.minor = info.u8FirmwareMinor;
    pFirmwareVersion->version.patch = info.u8FirmwarePatch;
#if defined(WDRV_WINC_DEVICE_WINC1500)
#elif defined(WDRV_WINC_DEVICE_WINC3400)
    pFirmwareVersion->hif.major     = M2M_GET_HIF_MAJOR(info.u16FirmwareHifInfo);
    pFirmwareVersion->hif.minor     = M2M_GET_HIF_MINOR(info.u16FirmwareHifInfo);
    pFirmwareVersion->hif.block     = M2M_GET_HIF_BLOCK(info.u16FirmwareHifInfo);
#endif
    memcpy(pFirmwareVersion->build.date, info.BuildDate, 12);
    memcpy(pFirmwareVersion->build.time, info.BuildTime, 9);

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    uint32_t WDRV_WINC_InfoDeviceIDGet(DRV_HANDLE handle)

  Summary:
    Returns the device ID.

  Description:
    Returns the device ID assigned to the WINC.

  Remarks:
    See wdrv_winc.h for usage information.

*/

uint32_t WDRV_WINC_InfoDeviceIDGet(DRV_HANDLE handle)
{
    const WDRV_WINC_DCPT *const pDcpt = (const WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt))
    {
        return 0;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return 0;
    }

#ifdef WDRV_WINC_DEVICE_LITE_DRIVER
    return winc_chip_get_id();
#else
    return m2m_wifi_get_chipId();
#endif
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_InfoDeviceMACAddressGet
    (
        DRV_HANDLE handle,
        bool permanent,
        uint8_t *const pMACAddress
    )

  Summary:
    Retrieves the MAC address of the WINC.

  Description:
    Retrieves either the permanent MAC address stored in OTP memory or the current
      working MAC address.

  Remarks:
    See wdrv_winc.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_InfoDeviceMACAddressGet(DRV_HANDLE handle,
                                    bool permanent, uint8_t *const pMACAddress)
{
    const WDRV_WINC_DCPT *const pDcpt = (const WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle and user pointer is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pMACAddress))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    if (true == permanent)
    {
        uint8_t isValid;

        /* Retrieve the permanent MAC address from the WINC device. */
        if (M2M_SUCCESS != m2m_wifi_get_otp_mac_address(pMACAddress, &isValid))
        {
            return WDRV_WINC_STATUS_REQUEST_ERROR;
        }

        if (0U == isValid)
        {
            return WDRV_WINC_STATUS_REQUEST_ERROR;
        }
    }
    else
    {
        /* Retrieve the current MAC address from the WINC device. */
        if (M2M_SUCCESS != m2m_wifi_get_mac_address(pMACAddress))
        {
            return WDRV_WINC_STATUS_REQUEST_ERROR;
        }
    }

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_InfoDeviceNameSet
    (
        DRV_HANDLE handle,
        const char* pDeviceName
    )

  Summary:
    Sets the WiFi Direct Device Name.

  Description:
    Sets the WiFi Direct Device Name.

  Remarks:
    See wdrv_winc.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_InfoDeviceNameSet
(
    DRV_HANDLE handle,
    const char* pDeviceName
)
{
    const WDRV_WINC_DCPT *const pDcpt = (const WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle and user pointer is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDeviceName))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    /* Pass the device name to the WINC device. */
    if (M2M_SUCCESS != m2m_wifi_set_device_name((uint8_t*)pDeviceName, (uint8_t)strnlen(pDeviceName, M2M_DEVICE_NAME_MAX)))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_GainTableIndexSet(DRV_HANDLE handle, uint8_t index)

  Summary:
    Sets the gain table index.

  Description:
    Sets the gain table index.

  Remarks:
    See wdrv_winc.h for usage information.

*/

#ifdef WDRV_WINC_DEVICE_MULTI_GAIN_TABLE
WDRV_WINC_STATUS WDRV_WINC_GainTableIndexSet(DRV_HANDLE handle, uint8_t index)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

#if defined(WDRV_WINC_DEVICE_WINC1500)
    if (M2M_SUCCESS != m2m_wifi_set_gain_table_idx(index))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }
#elif defined(WDRV_WINC_DEVICE_WINC3400)
    if (M2M_SUCCESS != m2m_wifi_ble_set_gain_table(index))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }
#endif

    return WDRV_WINC_STATUS_OK;
}
#endif

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_AutoRateSelectRate
    (
        DRV_HANDLE handle,
        bool autoSel,
        WDRV_WINC_DATA_RATE rate
    )

  Summary:
    Sets the auto rate transmit rate.

  Description:
    Sets the auto rate transmit rate.

  Remarks:
    See wdrv_winc.h for usage information.

*/

#ifdef WDRV_WINC_DEVICE_WINC1500
WDRV_WINC_STATUS WDRV_WINC_AutoRateSelectTransmitRate
(
    DRV_HANDLE handle,
    bool autoSel,
    WDRV_WINC_DATA_RATE rate
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    tstrConfAutoRate confAutoRate;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    if (rate > WDRV_WINC_DATA_RATE_MCS_7)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    confAutoRate.u16ArMaxRecoveryFailThreshold  = 5;
    confAutoRate.u16ArMinRecoveryFailThreshold  = 1;
    confAutoRate.enuWlanTxRate                  = TX_RATE_AUTO;
    confAutoRate.enuArInitialRateSel            = TX_RATE_AUTO;
    confAutoRate.u8ArEnoughTxThreshold          = 10;
    confAutoRate.u8ArSuccessTXThreshold         = 5;
    confAutoRate.u8ArFailTxThreshold            = 3;

    if (true == autoSel)
    {
        confAutoRate.enuWlanTxRate       = TX_RATE_AUTO;
        confAutoRate.enuArInitialRateSel = arRateTranslateTable[rate];
    }
    else if (WDRV_WINC_DATA_RATE_ANY != rate)
    {
        confAutoRate.enuWlanTxRate = arRateTranslateTable[rate];
    }
    else
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    if (M2M_SUCCESS != m2m_wifi_conf_auto_rate(&confAutoRate))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
}

#endif

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_ISR(SYS_MODULE_OBJ object);

  Summary:
    WINC interrupt handler.

  Description:
    This function is called by the interrupt routines to signal an interrupt
      from the WINC.

  Remarks:
    See wdrv_winc_api.h for usage information.

*/

void WDRV_WINC_ISR(SYS_MODULE_OBJ object)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)object;

    if (NULL == pDcpt->pCtrl)
    {
        return;
    }

    if (false == pDcpt->isInit)
    {
        return;
    }

    OSAL_SEM_PostISR(&pDcpt->pCtrl->drvEventSemaphore);
}
