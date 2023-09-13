/*******************************************************************************
  WINC Driver Enterprise Header File

  Company:
    Microchip Technology Inc.

  File Name:
    wdrv_winc_common.h

  Summary:
    WINC wireless enterprise header file.

  Description:
    This file provides enterprise elements of the WINC driver API.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
Copyright (C) 2022, Microchip Technology Inc., and its subsidiaries. All rights reserved.

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
// DOM-IGNORE-END

#ifndef _WDRV_WINC_ENTERPRISE_H
#define _WDRV_WINC_ENTERPRISE_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

// DOM-IGNORE-BEGIN
#ifdef __cplusplus // Provide C++ Compatibility
    extern "C" {
#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver Common Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/*  TLS Certificate Expiry Check Type.

  Summary:
    Defines each certificate expiry check type value.

  Description:
    Declares the different expiry check tpye values, invalid, on and off. On
      can be conditional on the system time being valid.

  Remarks:
    None.

*/

typedef enum
{
    /* The value is invalid. */
    WDRV_WINC_TLS_CERT_EXP_CHECK_INVALID,

    /* Ignore certificate expiration date validation. If a certificate is expired
       or there is no configured system time, the TLS connection will continue. */
    WDRV_WINC_TLS_CERT_EXP_CHECK_OFF,

    /* Validate certificate expiration date. If a certificate is expired or
       there is no configured system time, the TLS connection will fail. */
    WDRV_WINC_TLS_CERT_EXP_CHECK_ON,

    /* Validate the certificate expiration date only if there is a configured
       system time. If there is no configured system time, the certificate
       expiration is bypassed and the TLS connection continues. */
    WDRV_WINC_TLS_CERT_EXP_CHECK_ON_IF_SYS_TIME,
} WDRV_WINC_TLS_CERT_EXP_CHECK;

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

  Precondition:
    WDRV_WINC_Initialize must have been called.
    WDRV_WINC_Open must have been called to obtain a valid handle.

  Parameters:
    handle      - Client handle obtained by a call to WDRV_WINC_Open.
    isEnabled   - Flag indicating if authentication is enabled or disabled.

  Returns:
    WDRV_WINC_STATUS_OK               - A scan was initiated.
    WDRV_WINC_STATUS_NOT_OPEN         - The driver instance is not open.
    WDRV_WINC_STATUS_REQUEST_ERROR    - The request to the WINC was rejected.
    WDRV_WINC_STATUS_INVALID_ARG      - The parameters were incorrect.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_EntSec802_1XServerAuthSet
(
    DRV_HANDLE handle,
    bool isEnabled
);

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_EntSec802_1XServerAuthGet(DRV_HANDLE handle);

  Summary:
    Returns the server authentication state.

  Description:
    Indicates if the server authentication is enabled or disabled.

  Precondition:
    WDRV_WINC_Initialize must have been called.
    WDRV_WINC_Open must have been called to obtain a valid handle.

  Parameters:
    handle - Client handle obtained by a call to WDRV_WINC_Open.

  Returns:
    Flag indicating if authentication is enabled or disabled.

  Remarks:
    None.

*/

bool WDRV_WINC_EntSec802_1XServerAuthGet(DRV_HANDLE handle);

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

  Precondition:
    WDRV_WINC_Initialize must have been called.
    WDRV_WINC_Open must have been called to obtain a valid handle.

  Parameters:
    handle  - Client handle obtained by a call to WDRV_WINC_Open.
    pHash   - Pointer to 20 byte SHA1 digest hash, or NULL to clear.

  Returns:
    WDRV_WINC_STATUS_OK               - A scan was initiated.
    WDRV_WINC_STATUS_NOT_OPEN         - The driver instance is not open.
    WDRV_WINC_STATUS_REQUEST_ERROR    - The request to the WINC was rejected.
    WDRV_WINC_STATUS_INVALID_ARG      - The parameters were incorrect.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_EntSec802_1XRootCertHashSet
(
    DRV_HANDLE handle,
    const uint8_t* const pHash
);

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

  Precondition:
    WDRV_WINC_Initialize must have been called.
    WDRV_WINC_Open must have been called to obtain a valid handle.

  Parameters:
    handle      - Client handle obtained by a call to WDRV_WINC_Open.
    pHashBuf    - Pointer to buffer to receive hash.
    hashBufLen  - Length of buffer pHashBuf, must be at least 20 bytes.

  Returns:
    WDRV_WINC_STATUS_OK               - A scan was initiated.
    WDRV_WINC_STATUS_NOT_OPEN         - The driver instance is not open.
    WDRV_WINC_STATUS_REQUEST_ERROR    - The request to the WINC was rejected.
    WDRV_WINC_STATUS_INVALID_ARG      - The parameters were incorrect.

  Remarks:
    If no root certificate is currently set the buffer will be all zeros.

*/

WDRV_WINC_STATUS WDRV_WINC_EntSec802_1XRootCertHashGet
(
    DRV_HANDLE handle,
    uint8_t* const pHashBuf,
    size_t hashBufLen
);

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

  Precondition:
    WDRV_WINC_Initialize must have been called.
    WDRV_WINC_Open must have been called to obtain a valid handle.

  Parameters:
    handle      - Client handle obtained by a call to WDRV_WINC_Open.
    expCheck    - Certificate expiry check mode.

  Returns:
    WDRV_WINC_STATUS_OK               - A scan was initiated.
    WDRV_WINC_STATUS_NOT_OPEN         - The driver instance is not open.
    WDRV_WINC_STATUS_REQUEST_ERROR    - The request to the WINC was rejected.
    WDRV_WINC_STATUS_INVALID_ARG      - The parameters were incorrect.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_EntSec802_1XCertExpCheckSet
(
    DRV_HANDLE handle,
    WDRV_WINC_TLS_CERT_EXP_CHECK expCheck
);

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

  Precondition:
    WDRV_WINC_Initialize must have been called.
    WDRV_WINC_Open must have been called to obtain a valid handle.

  Parameters:
    handle      - Client handle obtained by a call to WDRV_WINC_Open.

  Returns:
    WDRV_WINC_STATUS_OK               - A scan was initiated.
    WDRV_WINC_STATUS_NOT_OPEN         - The driver instance is not open.
    WDRV_WINC_STATUS_REQUEST_ERROR    - The request to the WINC was rejected.
    WDRV_WINC_STATUS_INVALID_ARG      - The parameters were incorrect.

  Remarks:
    None.

*/

WDRV_WINC_TLS_CERT_EXP_CHECK WDRV_WINC_EntSec802_1XCertExpCheckGet
(
    DRV_HANDLE handle
);

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

  Precondition:
    WDRV_WINC_Initialize must have been called.
    WDRV_WINC_Open must have been called to obtain a valid handle.

  Parameters:
    handle      - Client handle obtained by a call to WDRV_WINC_Open.
    isEnabled   - Flag indicating if session caching is enabled or disabled.

  Returns:
    WDRV_WINC_STATUS_OK               - A scan was initiated.
    WDRV_WINC_STATUS_NOT_OPEN         - The driver instance is not open.
    WDRV_WINC_STATUS_REQUEST_ERROR    - The request to the WINC was rejected.
    WDRV_WINC_STATUS_INVALID_ARG      - The parameters were incorrect.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_EntSec802_1XSessionCacheSet
(
    DRV_HANDLE handle,
    bool isEnabled
);

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_EntSec802_1XSessionCache(DRV_HANDLE handle);

  Summary:
    Returns the current TLS session cache strategy.

  Description:
    Indicates if the TLS session will be cached or not for subsequent connections.

  Precondition:
    WDRV_WINC_Initialize must have been called.
    WDRV_WINC_Open must have been called to obtain a valid handle.

  Parameters:
    handle      - Client handle obtained by a call to WDRV_WINC_Open.

  Returns:
    WDRV_WINC_STATUS_OK               - A scan was initiated.
    WDRV_WINC_STATUS_NOT_OPEN         - The driver instance is not open.
    WDRV_WINC_STATUS_REQUEST_ERROR    - The request to the WINC was rejected.
    WDRV_WINC_STATUS_INVALID_ARG      - The parameters were incorrect.

  Remarks:
    None.

*/

bool WDRV_WINC_EntSec802_1XSessionCache(DRV_HANDLE handle);

// DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
// DOM-IGNORE-END

#endif /* _WDRV_WINC_COMMON_H */
