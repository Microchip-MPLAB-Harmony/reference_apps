/*******************************************************************************
  WINC Wireless Driver

  File Name:
    wdrv_winc_wps.c

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

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>

#include "wdrv_winc.h"
#include "wdrv_winc_common.h"
#include "wdrv_winc_wps.h"

static bool _ValidateChecksum(uint32_t pin)
{
    uint32_t accum = 0;

    accum += 3 * ((pin / 10000000) % 10);
    accum += 1 * ((pin / 1000000) % 10);
    accum += 3 * ((pin / 100000) % 10);
    accum += 1 * ((pin / 10000) % 10);
    accum += 3 * ((pin / 1000) % 10);
    accum += 1 * ((pin / 100) % 10);
    accum += 3 * ((pin / 10) % 10);
    accum += 1 * ((pin / 1) % 10);

    return (0 == (accum % 10));
}

/****************************************************************************
 * Function:        WDRV_WINC_WPSEnrolleeDiscoveryStartPIN
 * Summary: Start WPS discovery (PIN).
 *****************************************************************************/
WDRV_WINC_STATUS WDRV_WINC_WPSEnrolleeDiscoveryStartPIN(DRV_HANDLE handle, uint32_t pin, const WDRV_WINC_WPS_DISC_CALLBACK pfWPSDiscoveryCallback)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const )handle;
    char pinStr[9];

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

    if (false == _ValidateChecksum(pin))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    sprintf(pinStr, "%08" PRIu32, pin);

    pDcpt->pCtrl->pfWPSDiscoveryCB = pfWPSDiscoveryCallback;

    if (M2M_SUCCESS != m2m_wifi_wps(WPS_PIN_TRIGGER, pinStr))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
}

/****************************************************************************
 * Function:        WDRV_WINC_WPSEnrolleeDiscoveryStartPBC
 * Summary: Start WPS discovery (Push Button).
 *****************************************************************************/
WDRV_WINC_STATUS WDRV_WINC_WPSEnrolleeDiscoveryStartPBC(DRV_HANDLE handle, const WDRV_WINC_WPS_DISC_CALLBACK pfWPSDiscoveryCallback)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const )handle;

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

    pDcpt->pCtrl->pfWPSDiscoveryCB = pfWPSDiscoveryCallback;

    if (M2M_SUCCESS != m2m_wifi_wps(WPS_PBC_TRIGGER, NULL))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
}

/****************************************************************************
 * Function:        WDRV_WINC_WPSEnrolleeDiscoveryStop
 * Summary: Stop WPS discovery.
 *****************************************************************************/
WDRV_WINC_STATUS WDRV_WINC_WPSEnrolleeDiscoveryStop(DRV_HANDLE handle)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const )handle;

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

    if (M2M_SUCCESS != m2m_wifi_wps_disable())
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
}

//DOM-IGNORE-END
