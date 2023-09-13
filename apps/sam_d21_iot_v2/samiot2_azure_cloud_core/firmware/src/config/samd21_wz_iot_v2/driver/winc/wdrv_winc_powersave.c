/*******************************************************************************
  WINC Driver Power Save Implementation

  File Name:
    wdrv_winc_powersave.c

  Summary:
    WINC wireless driver power save implementation.

  Description:
    Provides an interface to control the power states of the WINC.
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

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <string.h>

#include "wdrv_winc.h"
#include "wdrv_winc_powersave.h"
#include "wdrv_winc_common.h"

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver Power Save Implementation
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_PowerSaveSetMode
    (
        DRV_HANDLE handle,
        WDRV_WINC_PS_MODE mode
    )

  Summary:
    Sets the power save mode.

  Description:
    Selects the current power save mode the WINC should be using.

  Remarks:
    See wdrv_winc_powersave.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_PowerSaveSetMode
(
    DRV_HANDLE handle,
    WDRV_WINC_PS_MODE mode
)
{
    WDRV_WINC_DCPT *pDcpt = (WDRV_WINC_DCPT *)handle;

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

    /* Set the sleep mode. */
    if (M2M_SUCCESS != m2m_wifi_set_sleep_mode(mode, pDcpt->pCtrl->powerSaveDTIMInterval ? 1 : 0))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_PS_MODE WDRV_WINC_PowerSaveGetMode(DRV_HANDLE handle)

  Summary:
    Returns the current power save mode.

  Description:
    Returns to the caller the current power save mode in use by the WINC.

  Remarks:
    See wdrv_winc_powersave.h for usage information.

*/

WDRV_WINC_PS_MODE WDRV_WINC_PowerSaveGetMode(DRV_HANDLE handle)
{
    WDRV_WINC_DCPT *pDcpt = (WDRV_WINC_DCPT *)handle;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt))
    {
        return WDRV_WINC_PS_MODE_INVALID;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_PS_MODE_INVALID;
    }

    /* Retrieve the sleep mode. */
    return m2m_wifi_get_sleep_mode();
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_PowerSaveSetBeaconInterval
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
    See wdrv_winc_powersave.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_PowerSaveSetBeaconInterval
(
    DRV_HANDLE handle,
    uint16_t numBeaconIntervals
)
{
    WDRV_WINC_DCPT *pDcpt = (WDRV_WINC_DCPT *)handle;
    tstrM2mLsnInt listenIntervalOpt;

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

    /* Don't update WINC if interval hasn't changed. */
    if (pDcpt->pCtrl->powerSaveDTIMInterval == numBeaconIntervals)
    {
        return WDRV_WINC_STATUS_OK;
    }

    /* Set the listen period. */
    listenIntervalOpt.u16LsnInt = numBeaconIntervals;

    if (M2M_SUCCESS != m2m_wifi_set_lsn_int(&listenIntervalOpt))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    /* If DTIM has changed from/to zero, update sleep mode to enable/disable broadcast tracking. */
    if ((0 != numBeaconIntervals) || (0 != pDcpt->pCtrl->powerSaveDTIMInterval))
    {
        if (M2M_SUCCESS != m2m_wifi_set_sleep_mode(m2m_wifi_get_sleep_mode(), pDcpt->pCtrl->powerSaveDTIMInterval ? 1 : 0))
        {
            return WDRV_WINC_STATUS_REQUEST_ERROR;
        }
    }

    pDcpt->pCtrl->powerSaveDTIMInterval = numBeaconIntervals;

    return WDRV_WINC_STATUS_OK;
}

#ifdef WDRV_WINC_DEVICE_WINC1500
//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_PowerSaveManualSleep
    (
        DRV_HANDLE handle,
        uint32_t sleepTime
    )

  Summary:
    Manual sleep power save operation.

  Description:
    If the current power save mode is WDRV_WINC_PS_MODE_MANUAL the WINC
      can be placed into low power mode by requesting sleep.

  Remarks:
    See wdrv_winc_powersave.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_PowerSaveManualSleep
(
    DRV_HANDLE handle,
    uint32_t sleepTime
)
{
    WDRV_WINC_DCPT *pDcpt = (WDRV_WINC_DCPT *)handle;

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

    /* Request sleep. */
    if (M2M_SUCCESS != m2m_wifi_request_sleep(sleepTime))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
}
#endif
