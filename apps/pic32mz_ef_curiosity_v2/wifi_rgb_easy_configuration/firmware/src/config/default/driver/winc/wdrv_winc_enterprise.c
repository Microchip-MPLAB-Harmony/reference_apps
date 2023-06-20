/*******************************************************************************
  WINC Wireless Enterprise Implementation

  File Name:
    wdrv_enterprise.c

  Summary:
    WINC wireless enterprise implementation.

  Description:
    WINC wireless enterprise implementation.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <string.h>

#include "wdrv_winc.h"
#include "wdrv_winc_common.h"
#include "wdrv_winc_enterprise.h"

#ifdef WDRV_WINC_DEVICE_WINC1500
#define tenuTlsCertExpSettings              tenuSslCertExpSettings
#define TLS_CERT_EXP_CHECK_DISABLE          SSL_CERT_EXP_CHECK_DISABLE
#define TLS_CERT_EXP_CHECK_ENABLE           SSL_CERT_EXP_CHECK_ENABLE
#define TLS_CERT_EXP_CHECK_EN_IF_SYS_TIME   SSL_CERT_EXP_CHECK_EN_IF_SYS_TIME
#endif

// *****************************************************************************
// *****************************************************************************
// Section: WINC Enterprise Implementation
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_EntSec802_1XServerAuthSet
    (
        DRV_HANDLE handle,
        bool isEnabled
    );

  Summary:
    Set server authentication condition.

  Description:
    Enable or disable server authentication.

  Remarks:
    See wdrv_winc_enterprise.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_EntSec802_1XServerAuthSet
(
    DRV_HANDLE handle,
    bool isEnabled
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    int optionValue;

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

    if (true == isEnabled)
    {
        optionValue = 0;
    }
    else
    {
        optionValue = 1;
    }

    if (M2M_SUCCESS != m2m_wifi_1x_set_option(WIFI_1X_BYPASS_SERVER_AUTH, &optionValue, sizeof(int)))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_EntSec802_1XServerAuthGet(DRV_HANDLE handle);

  Summary:
    Returns the server authentication state.

  Description:
    Indicates if the server authentication is enabled or disabled.

  Remarks:
    See wdrv_winc_enterprise.h for usage information.

*/

bool WDRV_WINC_EntSec802_1XServerAuthGet(DRV_HANDLE handle)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    int optionValue;
    size_t optionLength;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt))
    {
        return false;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return false;
    }

    optionLength = sizeof(int);

    if (M2M_SUCCESS != m2m_wifi_1x_get_option(WIFI_1X_BYPASS_SERVER_AUTH, &optionValue, &optionLength))
    {
        return false;
    }

    if (0 == optionValue)
    {
        return true;
    }

    return false;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_EntSec802_1XRootCertHashSet
    (
        DRV_HANDLE handle,
        const uint8_t* const pHash
    );

  Summary:
    Set the root certificate SHA1 hash.

  Description:
    Specifies a single root certificate to use for TLS connections. The SHA1
      digest hash is set or cleared through this function.

  Remarks:
    See wdrv_winc_enterprise.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_EntSec802_1XRootCertHashSet
(
    DRV_HANDLE handle,
    const uint8_t* const pHash
)
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

    if (M2M_SUCCESS != m2m_wifi_1x_set_option(WIFI_1X_SPECIFIC_ROOTCERT, pHash, (NULL == pHash) ? 0 : 20))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_EntSec802_1XRootCertHashGet
    (
        DRV_HANDLE handle,
        uint8_t* const pHashBuf,
        size_t hashBufLen
    );

  Summary:
    Retrieves the current root certificate hash.

  Description:
    Returns, in the supplied buffer, the current root certificate hash, if set.

  Remarks:
    See wdrv_winc_enterprise.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_EntSec802_1XRootCertHashGet
(
    DRV_HANDLE handle,
    uint8_t* const pHashBuf,
    size_t hashBufLen
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pHashBuf))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    memset(pHashBuf, 0, hashBufLen);

    if (M2M_SUCCESS != m2m_wifi_1x_get_option(WIFI_1X_SPECIFIC_ROOTCERT, pHashBuf, &hashBufLen))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_EntSec802_1XCertExpCheckSet
    (
        DRV_HANDLE handle,
        WDRV_WINC_TLS_CERT_EXP_CHECK expCheck
    );

  Summary:
    Sets the certificate expiry check mode.

  Description:
    Indicates how certificate expiry should be handled in TLS connections.

  Remarks:
    See wdrv_winc_enterprise.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_EntSec802_1XCertExpCheckSet
(
    DRV_HANDLE handle,
    WDRV_WINC_TLS_CERT_EXP_CHECK expCheck
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    tenuTlsCertExpSettings optionValue;

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

    switch (expCheck)
    {
        case WDRV_WINC_TLS_CERT_EXP_CHECK_OFF:
        {
            optionValue = TLS_CERT_EXP_CHECK_DISABLE;
            break;
        }

        case WDRV_WINC_TLS_CERT_EXP_CHECK_ON:
        {
            optionValue = TLS_CERT_EXP_CHECK_ENABLE;
            break;
        }

        case WDRV_WINC_TLS_CERT_EXP_CHECK_ON_IF_SYS_TIME:
        {
            optionValue = TLS_CERT_EXP_CHECK_EN_IF_SYS_TIME;
            break;
        }

        default:
        {
            return WDRV_WINC_STATUS_INVALID_ARG;
        }
    }

    if (M2M_SUCCESS != m2m_wifi_1x_set_option(WIFI_1X_TIME_VERIF_MODE, &optionValue, sizeof(tenuTlsCertExpSettings)))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_TLS_CERT_EXP_CHECK WDRV_WINC_EntSec802_1XCertExpCheckGet
    (
        DRV_HANDLE handle
    );

  Summary:
    Returns the current certificate expiry check mode.

  Description:
    Returns the current certificate expiry check mode.

  Remarks:
    See wdrv_winc_enterprise.h for usage information.

*/

WDRV_WINC_TLS_CERT_EXP_CHECK WDRV_WINC_EntSec802_1XCertExpCheckGet
(
    DRV_HANDLE handle
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    tenuTlsCertExpSettings optionValue;
    size_t optionLength;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt))
    {
        return WDRV_WINC_TLS_CERT_EXP_CHECK_INVALID;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_TLS_CERT_EXP_CHECK_INVALID;
    }

    optionLength = sizeof(tenuTlsCertExpSettings);

    if (M2M_SUCCESS != m2m_wifi_1x_get_option(WIFI_1X_TIME_VERIF_MODE, &optionValue, &optionLength))
    {
        return WDRV_WINC_TLS_CERT_EXP_CHECK_INVALID;
    }

    switch (optionValue)
    {
        case TLS_CERT_EXP_CHECK_DISABLE:
        {
            return WDRV_WINC_TLS_CERT_EXP_CHECK_OFF;
        }

        case TLS_CERT_EXP_CHECK_ENABLE:
        {
            return WDRV_WINC_TLS_CERT_EXP_CHECK_ON;
        }

        case TLS_CERT_EXP_CHECK_EN_IF_SYS_TIME:
        {
            return WDRV_WINC_TLS_CERT_EXP_CHECK_ON_IF_SYS_TIME;
        }

        default:
        {
            return WDRV_WINC_TLS_CERT_EXP_CHECK_INVALID;
        }
    }
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_EntSec802_1XSessionCacheSet
    (
        DRV_HANDLE handle,
        bool isEnabled
    );

  Summary:
    Sets the TLS session cache strategy.

  Description:
    Indicates if the TLS session cache should be enabled for connections or not.

  Remarks:
    See wdrv_winc_enterprise.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_EntSec802_1XSessionCacheSet
(
    DRV_HANDLE handle,
    bool isEnabled
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    int optionValue;

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

    if (true == isEnabled)
    {
        optionValue = 1;
    }
    else
    {
        optionValue = 0;
    }

    if (M2M_SUCCESS != m2m_wifi_1x_set_option(WIFI_1X_SESSION_CACHING, &optionValue, sizeof(int)))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_EntSec802_1XSessionCache(DRV_HANDLE handle);

  Summary:
    Returns the current TLS session cache strategy.

  Description:
    Indicates if the TLS session will be cached or not for subsequent connections.

  Remarks:
    See wdrv_winc_enterprise.h for usage information.

*/

bool WDRV_WINC_EntSec802_1XSessionCache(DRV_HANDLE handle)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    int optionValue;
    size_t optionLength;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt))
    {
        return false;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return false;
    }

    optionLength = sizeof(int);

    if (M2M_SUCCESS != m2m_wifi_1x_get_option(WIFI_1X_SESSION_CACHING, &optionValue, &optionLength))
    {
        return false;
    }

    if (0 == optionValue)
    {
        return false;
    }

    return true;
}
