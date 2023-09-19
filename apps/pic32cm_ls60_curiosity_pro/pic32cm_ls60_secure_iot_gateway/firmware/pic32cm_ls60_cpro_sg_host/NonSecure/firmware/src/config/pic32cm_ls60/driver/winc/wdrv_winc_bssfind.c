/*******************************************************************************
  WINC Wireless Driver

  File Name:
    wdrv_winc_bssfind.c

  Summary:
    WINC wireless driver.

  Description:
    WINC wireless driver.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*
Copyright (C) 2019, Microchip Technology Inc., and its subsidiaries. All rights reserved.

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

#include <stdint.h>
#include <string.h>

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "wdrv_winc.h"
#include "wdrv_winc_common.h"
#include "wdrv_winc_bssfind.h"

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver BSS Find Implementations
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_BSSFindFirst
    (
        DRV_HANDLE handle,
        WDRV_WINC_CHANNEL_ID channel,
        bool active,
        const WDRV_WINC_SSID_LIST *const pSSIDList,
        const WDRV_WINC_BSSFIND_NOTIFY_CALLBACK pfNotifyCallback
    )

  Summary:
    Request a BSS scan is performed by the WINC.

  Description:
    A scan is requested on the specified channels. An optional callback can
      be provided to receive notification of the first BSS discovered.

  Remarks:
    See wdrv_winc_bssfind.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_BSSFindFirst
(
    DRV_HANDLE handle,
    WDRV_WINC_CHANNEL_ID channel,
    bool active,
    const WDRV_WINC_SSID_LIST *const pSSIDList,
    const WDRV_WINC_BSSFIND_NOTIFY_CALLBACK pfNotifyCallback
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    tstrM2MScanOption scanOptions;
    int8_t result;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure request channel is valid. */
    if ((channel > WDRV_WINC_CID_2_4G_CH14) && (WDRV_WINC_ALL_CHANNELS != channel))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

#ifdef WDRV_WINC_DEVICE_SCAN_SSID_LIST
    /* Ensure SSID list is only provided for active scans. */
    if ((false == active) && (NULL != pSSIDList))
#else
    if (NULL != pSSIDList)
#endif
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    /* Convert public API representation of all channels to
       internal representation for the M2M driver. */
    if ((WDRV_WINC_ALL_CHANNELS == channel) || (WDRV_WINC_CID_ANY == channel))
    {
        channel = M2M_WIFI_CH_ALL;
    }

    /* Check if the scan parameters have been updated from
       the defaults. */
    if (false == pDcpt->pCtrl->scanParamDefault)
    {
        scanOptions.u8NumOfSlot         = pDcpt->pCtrl->scanNumSlots;
        scanOptions.u8SlotTime          = pDcpt->pCtrl->scanActiveScanTime;
        scanOptions.u8ProbesPerSlot     = pDcpt->pCtrl->scanNumProbes;
        scanOptions.s8RssiThresh        = pDcpt->pCtrl->scanRSSIThreshold;
#ifdef WDRV_WINC_DEVICE_WINC3400
        scanOptions.u16PassiveScanTime  = pDcpt->pCtrl->scanPassiveScanTime;
#endif

        /* Scan parameters need to be updated in the WINC device. */
        if (M2M_ERR_FAIL == m2m_wifi_set_scan_options(&scanOptions))
        {
            return WDRV_WINC_STATUS_REQUEST_ERROR;
        }
    }

    if (true == active)
    {
        if (NULL == pSSIDList)
        {
            /* Request active scan of selected channel (or all channels). */
            result = m2m_wifi_request_scan(channel);
        }
        else
        {
#ifdef WDRV_WINC_DEVICE_SCAN_SSID_LIST
            const WDRV_WINC_SSID_LIST *pSSIDListEle;

            uint8_t ssidList[(MAX_HIDDEN_SITES * M2M_MAX_SSID_LEN) + 1];
            uint8_t *pSSIDListArrIdx;

            pSSIDListEle = pSSIDList;

            ssidList[0] = 0;
            pSSIDListArrIdx = &ssidList[1];

            /* Construct packed SSID list. */
            while ((NULL != pSSIDListEle) && (ssidList[0] < MAX_HIDDEN_SITES))
            {
                if (pSSIDListEle->ssid.length > (M2M_MAX_SSID_LEN-1))
                {
                    return WDRV_WINC_STATUS_INVALID_ARG;
                }

                *pSSIDListArrIdx++ = pSSIDListEle->ssid.length;
                memcpy(pSSIDListArrIdx, pSSIDListEle->ssid.name, pSSIDListEle->ssid.length);
                pSSIDListArrIdx += pSSIDListEle->ssid.length;

                ssidList[0]++;

                pSSIDListEle = pSSIDListEle->pNext;
            }

            /* Request active scan of specified SSIDs on selected channel (or all channels). */
            result = m2m_wifi_request_scan_ssid_list(channel, ssidList);
#endif
        }
    }
    else
    {
        /* Request passive scan of selected channel (or all channels). */
#if defined(WDRV_WINC_DEVICE_WINC1500)
        result = m2m_wifi_request_scan_passive(channel, pDcpt->pCtrl->scanPassiveScanTime);
#elif defined(WDRV_WINC_DEVICE_WINC3400)
        result = m2m_wifi_request_scan_passive(channel);
#endif
    }

    /* Handle response, from scan request. */
    switch (result)
    {
        case M2M_ERR_INVALID_ARG:
        {
            /* There was a problem with the request channel. */
            return WDRV_WINC_STATUS_INVALID_ARG;
        }

        case M2M_ERR_SCAN_IN_PROGRESS:
        {
            /* A scan is already in progress. */
            return WDRV_WINC_STATUS_SCAN_IN_PROGRESS;
        }

        case M2M_SUCCESS:
        default:
        {
            break;
        }
    }

    /* Update state to reflect a new scan has started. */
    pDcpt->pCtrl->scanInProgress     = true;
    pDcpt->pCtrl->scanIndex          = 0;
    pDcpt->pCtrl->isBSSScanInfoValid = false;
    pDcpt->pCtrl->scanNumScanResults = 0;
    pDcpt->pCtrl->pfBSSFindNotifyCB  = pfNotifyCallback;

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_BSSFindNext
    (
        DRV_HANDLE handle,
        WDRV_WINC_BSSFIND_NOTIFY_CALLBACK pfNotifyCallback
    )

  Summary:
    Request the next scan results be provided.

  Description:
    The information structure of the next BSS is requested from the WINC.

  Remarks:
    See wdrv_winc_bssfind.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_BSSFindNext
(
    DRV_HANDLE handle,
    WDRV_WINC_BSSFIND_NOTIFY_CALLBACK pfNotifyCallback
)
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

    /* Cannot request results while a scan is in progress. */
    if (true == pDcpt->pCtrl->scanInProgress)
    {
        return WDRV_WINC_STATUS_SCAN_IN_PROGRESS;
    }

    /* Check if the request would exceed the number of results
       available, signal find operation end if so. */
    pDcpt->pCtrl->scanIndex++;

    if (pDcpt->pCtrl->scanIndex >= m2m_wifi_get_num_ap_found())
    {
        pDcpt->pCtrl->scanIndex--;

        return WDRV_WINC_STATUS_BSS_FIND_END;
    }

    /* Request the next BBS results from the WINC device. */
    m2m_wifi_req_scan_result(pDcpt->pCtrl->scanIndex);

    /* Invalidate the BSS scan cache and store callback supplied. */
    pDcpt->pCtrl->isBSSScanInfoValid = false;
    pDcpt->pCtrl->pfBSSFindNotifyCB  = pfNotifyCallback;

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_BSSFindReset
    (
        DRV_HANDLE handle,
        WDRV_WINC_BSSFIND_NOTIFY_CALLBACK pfNotifyCallback
    )

  Summary:
    Request the first scan results again

  Description:
    The information structure of the first BSS is requested from the WINC.

  Remarks:
    See wdrv_winc_bssfind.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_BSSFindReset
(
    DRV_HANDLE handle,
    WDRV_WINC_BSSFIND_NOTIFY_CALLBACK pfNotifyCallback
)
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

    /* Cannot reset the find operation while a scan is in progress. */
    if (true == pDcpt->pCtrl->scanInProgress)
    {
        return WDRV_WINC_STATUS_SCAN_IN_PROGRESS;
    }

    /* Check if there are any results available. */
    if (0 == m2m_wifi_get_num_ap_found())
    {
        return WDRV_WINC_STATUS_BSS_FIND_END;
    }

    /* Reset to first BSS results and request them from the WINC device. */
    pDcpt->pCtrl->scanIndex = 0;

    m2m_wifi_req_scan_result(pDcpt->pCtrl->scanIndex);

    /* Invalidate the BSS scan cache and store callback supplied. */
    pDcpt->pCtrl->isBSSScanInfoValid = false;
    pDcpt->pCtrl->pfBSSFindNotifyCB  = pfNotifyCallback;

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_BSSFindGetInfo
    (
        DRV_HANDLE handle,
        WDRV_WINC_BSS_INFO *const pBSSInfo
    )

  Summary:
    Requests the information structure of the current BSS scan result.

  Description:
    After each call to either WDRV_WINC_BSSFindFirst or WDRV_WINC_BSSFindNext
      the driver receives a single BSS information structure which it stores.
      This function retrieves that structure.

  Remarks:
    See wdrv_winc_bssfind.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_BSSFindGetInfo
(
    DRV_HANDLE handle,
    WDRV_WINC_BSS_INFO *const pBSSInfo
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle and user pointer is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl) || (NULL == pBSSInfo))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    // Check if the BSS scan cache is valid. */
    if (false == pDcpt->pCtrl->isBSSScanInfoValid)
    {
        return WDRV_WINC_STATUS_NO_BSS_INFO;
    }

    /* Copy BSS scan cache to user supplied buffer. */
    memcpy(pBSSInfo, &pDcpt->pCtrl->lastBSSScanInfo, sizeof(WDRV_WINC_BSS_INFO));

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_BSSFindSetScanParameters
    (
        DRV_HANDLE handle,
        uint8_t numSlots,
        uint8_t activeSlotTime,
        uint8_t passiveSlotTime,
        uint8_t numProbes
    )

  Summary:
    Configures the scan operation.

  Description:
    The scan consists of a number of slots per channel, each slot can has a
      configurable time period and number of probe requests to send.

  Remarks:
    See wdrv_winc_bssfind.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_BSSFindSetScanParameters
(
    DRV_HANDLE handle,
    uint8_t numSlots,
    uint8_t activeSlotTime,
    uint16_t passiveSlotTime,
    uint8_t numProbes
)
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

    /* Check each scan parameter and mark when they change from the defaults
       so that they can be loaded into the WINC. Passive Scan Time is handled
       differently on WINC1500 vs WINC3400. */

    /* Check for update to Active Scan Time. */
    if ((0 != activeSlotTime) && (pDcpt->pCtrl->scanActiveScanTime != activeSlotTime))
    {
        pDcpt->pCtrl->scanActiveScanTime = activeSlotTime;
        pDcpt->pCtrl->scanParamDefault = false;
    }

    /* Check for update to Passive Scan Time. */
    if ((0 != passiveSlotTime) && (pDcpt->pCtrl->scanPassiveScanTime != passiveSlotTime))
    {
        pDcpt->pCtrl->scanPassiveScanTime = passiveSlotTime;
#ifdef WDRV_WINC_DEVICE_WINC3400
        pDcpt->pCtrl->scanParamDefault = false;
#endif
    }

    /* Check for update to Number of Slots. */
    if ((0 != numSlots) && (pDcpt->pCtrl->scanNumSlots != numSlots))
    {
        pDcpt->pCtrl->scanNumSlots = numSlots;
        pDcpt->pCtrl->scanParamDefault = false;
    }

    /* Check for update to Number of Probes. */
    if ((0 != numProbes) && (pDcpt->pCtrl->scanNumProbes != numProbes))
    {
        pDcpt->pCtrl->scanNumProbes = numProbes;
        pDcpt->pCtrl->scanParamDefault = false;
    }

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_BSSFindSetRSSIThreshold
    (
        DRV_HANDLE handle,
        int8_t rssiThreshold
    )

  Summary:
    Configures the scan RSSI threshold.

  Description:
    The RSSI threshold required for reconnection to an AP without scanning
    all channels first.

  Remarks:
    See wdrv_winc_bssfind.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_BSSFindSetRSSIThreshold
(
    DRV_HANDLE handle,
    int8_t rssiThreshold
)
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

    /* Update RSSI Threshold and tag the defaults have changed to force new
       parameters to be loaded into WINC device. */
    pDcpt->pCtrl->scanRSSIThreshold = rssiThreshold;
    pDcpt->pCtrl->scanParamDefault  = false;

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_BSSFindSetEnabledChannels
    (
        DRV_HANDLE handle,
        WDRV_WINC_CHANNEL_MASK channelMask
    )

  Summary:
    Configures the channels which can be scanned.

  Description:
    To comply with regulatory domains certain channels must not be scanned.
      This function configures which channels are enabled to be used.

  Remarks:
    See wdrv_winc_bssfind.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_BSSFindSetEnabledChannels
(
    DRV_HANDLE handle,
    WDRV_WINC_CHANNEL_MASK channelMask
)
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

    /* Update the selected channel mask. */
    if (M2M_SUCCESS != m2m_wifi_set_scan_region(channelMask))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_BSSFindSetScanMatchMode
    (
        DRV_HANDLE handle,
        WDRV_WINC_SCAN_MATCH_MODE matchMode
    )

  Summary:
    Configures the scan matching mode.

  Description:
    This function configures the matching mode, either stop on first or
      match all, used when scanning for SSIDs.

  Remarks:
    See wdrv_winc_bssfind.h for usage information.

*/

#ifdef WDRV_WINC_DEVICE_SCAN_STOP_ON_FIRST
WDRV_WINC_STATUS WDRV_WINC_BSSFindSetScanMatchMode
(
    DRV_HANDLE handle,
    WDRV_WINC_SCAN_MATCH_MODE matchMode
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    uint8_t stopScanOption;

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

    /* Validate the match mode. */
    if (WDRV_WINC_SCAN_MATCH_MODE_STOP_ON_FIRST == matchMode)
    {
        stopScanOption = 1;
    }
    else if (WDRV_WINC_SCAN_MATCH_MODE_FIND_ALL == matchMode)
    {
        stopScanOption = 0;
    }
    else
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Request a change in scan matching. */
    if (M2M_SUCCESS != m2m_wifi_set_stop_scan_on_first(stopScanOption))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
}
#endif

//*******************************************************************************
/*
  Function:
    uint8_t WDRV_WINC_BSSFindGetNumBSSResults(DRV_HANDLE handle)

  Summary:
    Returns the number of BSS scan results found.

  Description:
    Returns the number of BSS scan results found.

  Remarks:
    See wdrv_winc_bssfind.h for usage information.

*/

uint8_t WDRV_WINC_BSSFindGetNumBSSResults(DRV_HANDLE handle)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle is valid and the instance is open.
       Ensure a scan is not already in progress. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl))
    {
        return 0;
    }

    if ((false == pDcpt->isOpen) || (true == pDcpt->pCtrl->scanInProgress))
    {
        return 0;
    }

    /* Return the number of BSSs found. */
    return m2m_wifi_get_num_ap_found();
}

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_BSSFindInProgress(DRV_HANDLE handle)

  Summary:
    Indicates if a BSS scan is in progress.

  Description:
    Returns a flag indicating if a BSS scan operation is currently running.

  Remarks:
    See wdrv_winc_bssfind.h for usage information.

*/

bool WDRV_WINC_BSSFindInProgress(DRV_HANDLE handle)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle is valid and the instance is open. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl))
    {
        return false;
    }

    if (false == pDcpt->isOpen)
    {
        return false;
    }

    return pDcpt->pCtrl->scanInProgress;
}
