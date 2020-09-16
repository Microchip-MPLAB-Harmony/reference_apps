/*******************************************************************************
  WINC MAC Driver TCP/IP Interface Proxy Implementation

  File Name:
    wdrv_winc_itf_proxy.c

  Summary:
    Wireless driver PIC32 implementation for WINC support.

  Description:
    Wireless driver PIC32 implementation for WINC support.
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

// *****************************************************************************
// *****************************************************************************
// Section: WINC MAC Driver Interface Proxy Implementation
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

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_MACBSSFindFirst
(
    DRV_HANDLE handle,
    uint8_t channel,
    bool active,
    WDRV_WINC_BSSFIND_NOTIFY_CALLBACK pfNotifyCallback
)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if (NULL == pDcpt)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    return WDRV_WINC_BSSFindFirst(pDcpt->wincDrvH, channel, active, pfNotifyCallback);
}

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

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_MACBSSFindNext
(
    DRV_HANDLE handle,
    WDRV_WINC_BSSFIND_NOTIFY_CALLBACK pfNotifyCallback
)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if (NULL == pDcpt)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    return WDRV_WINC_MACBSSFindNext(pDcpt->wincDrvH, pfNotifyCallback);
}

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

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_MACBSSFindReset
(
    DRV_HANDLE handle,
    WDRV_WINC_BSSFIND_NOTIFY_CALLBACK pfNotifyCallback
)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if (NULL == pDcpt)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    return WDRV_WINC_MACBSSFindReset(pDcpt->wincDrvH, pfNotifyCallback);
}

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

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_MACBSSFindGetInfo
(
    DRV_HANDLE handle,
    WDRV_WINC_BSS_INFO* pBSSInfo
)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if (NULL == pDcpt)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    return WDRV_WINC_BSSFindGetInfo(pDcpt->wincDrvH, pBSSInfo);
}

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

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_MACBSSFindSetScanParameters
(
    DRV_HANDLE handle,
    uint8_t numSlots,
    uint8_t slotTime,
    uint8_t numProbes,
    int8_t rssiThreshold
)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if (NULL == pDcpt)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    return WDRV_WINC_BSSFindSetScanParameters(pDcpt->wincDrvH, numSlots,
                                            slotTime, numProbes, rssiThreshold);
}

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

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_MACBSSFindSetEnabledChannels
(
    DRV_HANDLE handle,
    WDRV_WINC_CHANNEL_MASK channelMask
)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if (NULL == pDcpt)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    return WDRV_WINC_BSSFindSetEnabledChannels(pDcpt->wincDrvH, channelMask);
}

//*******************************************************************************
/*
  Function:
    uint8_t WDRV_WINC_MACBSSFindGetNumBSSResults(DRV_HANDLE handle)

  Summary:
    Returns the number of BSS scan results found.

  Description:
    Returns the number of BSS scan results found.

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

uint8_t WDRV_WINC_MACBSSFindGetNumBSSResults(DRV_HANDLE handle)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if (NULL == pDcpt)
    {
        return 0;
    }

    return WDRV_WINC_BSSFindGetNumBSSResults(pDcpt->wincDrvH);
}

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_MACBSSFindInProgress(DRV_HANDLE handle)

  Summary:
    Indicates if a BSS scan is in progress.

  Description:
    Returns a flag indicating if a BSS scan operation is currently running.

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

bool WDRV_WINC_MACBSSFindInProgress(DRV_HANDLE handle)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if (NULL == pDcpt)
    {
        return false;
    }

    return WDRV_WINC_BSSFindInProgress(pDcpt->wincDrvH);
}

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

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_MACPowerSaveSetMode
(
    DRV_HANDLE handle,
    WDRV_WINC_PS_MODE mode
)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if (NULL == pDcpt)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    return WDRV_WINC_PowerSaveSetMode(pDcpt->wincDrvH, mode);
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_PS_MODE WDRV_WINC_MACPowerSaveGetMode(DRV_HANDLE handle)

  Summary:
    Returns the current power save mode.

  Description:
    Returns to the caller the current power save mode in use by the WINC.

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

WDRV_WINC_PS_MODE WDRV_WINC_MACPowerSaveGetMode(DRV_HANDLE handle)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if (NULL == pDcpt)
    {
        return WDRV_WINC_PS_MODE_INVALID;
    }

    return WDRV_WINC_PowerSaveGetMode(pDcpt->wincDrvH);
}

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

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_MACPowerSaveSetBeaconInterval
(
    DRV_HANDLE handle,
    uint16_t numBeaconIntervals
)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if (NULL == pDcpt)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    return WDRV_WINC_PowerSaveSetBeaconInterval(pDcpt->wincDrvH, numBeaconIntervals);
}
