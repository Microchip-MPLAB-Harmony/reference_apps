/*******************************************************************************
  WINC Driver HTTP Provision Context Header File

  Company:
    Microchip Technology Inc.

  File Name:
    wdrv_winc_httpprovctx.h

  Summary:
    WINC wireless driver HTTP provisioning context header file.

  Description:
    This interface manages the HTTP provisioning context which is used to
      define the behaviour of the HTTP provisioning provided by Soft-AP mode.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

#ifndef _WDRV_WINC_HTTPPROVCTX_H
#define _WDRV_WINC_HTTPPROVCTX_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>

#include "wdrv_winc_common.h"
#include "wdrv_winc_authctx.h"
#include "wdrv_winc_bssctx.h"

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver HTTP Provisioning Context Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/*  Provisioning Callback

  Summary:
    HTTP provisioning callback for connect information.

  Description:
    This callback is used to signal the desired SSID and authentication
      contexts selected via provisioning.

  Parameters:
    handle      - Client handle obtained by a call to WDRV_WINC_Open.
    pSSID       - Pointer to selected SSID.
    pAuthCtx    - Pointer to selected authentication context.
    provisioned - Flag indicating provision success.

  Returns:
    None.

  Remarks:
    None.
*/

typedef void (*WDRV_WINC_HTTPPROV_INFO_CALLBACK)
(
    DRV_HANDLE handle,
    WDRV_WINC_SSID *pSSID,
    WDRV_WINC_AUTH_CONTEXT *pAuthCtx,
    bool provisioned
);

// *****************************************************************************
/*  HTTP Provisioning Context

  Summary:
    HTTP provisioning context definition.

  Description:
 This structure contains the provisioning information needed when creating
 a Soft-AP via WDRV_WINC_APStart.

  Remarks:
    None.
*/

typedef struct
{
    /* Flag indicating if any URL is mapped to the provisioning server. */
    bool wildcardURL;

    /* Domain name of provisioning server. */
    char domainName[64+1];

    /* Pointer to callback to signal provisioning information. */
    WDRV_WINC_HTTPPROV_INFO_CALLBACK pfProvConnectInfoCB;
} WDRV_WINC_HTTP_PROV_CONTEXT;

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver HTTP Provisioning Context Routines
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_HTTPProvCtxSetDefaults
    (
        WDRV_WINC_HTTP_PROV_CONTEXT *const pHTTPProvCtx
    )

  Summary:
    Initialize provisioning store.

  Description:
    Ensure the provisioning store is initialized to appropriate defaults.

  Precondition:
    None.

  Parameters:
    pHTTPProvCtx - Pointer to provisioning store structure.

  Returns:
    WDRV_WINC_STATUS_OK             - Store initialized.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_HTTPProvCtxSetDefaults
(
    WDRV_WINC_HTTP_PROV_CONTEXT *const pHTTPProvCtx
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_HTTPProvCtxSetDomainName
    (
        WDRV_WINC_HTTP_PROV_CONTEXT *const pHTTPProvCtx,
        const char *const pname
    )

  Summary:
    Define the DNS domain name for the provisioning server.

  Description:
    This defines the DNS domain name associated with the Soft-AP instance web server.

  Precondition:
    WDRV_WINC_HTTPProvCtxSetDefaults must have been called.

  Parameters:
    pHTTPProvCtx - Pointer to provisioning store structure.
    pname        - Pointer to domain name string.

  Returns:
    WDRV_WINC_STATUS_OK             - The domain name is set.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_HTTPProvCtxSetDomainName
(
    WDRV_WINC_HTTP_PROV_CONTEXT *const pHTTPProvCtx,
    const char *const pname
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_HTTPProvCtxSetURLWildcard
    (
        WDRV_WINC_HTTP_PROV_CONTEXT *const pHTTPProvCtx,
        bool wildcardURL
    )

  Summary:
    Define the use of a wildcard URL check.

  Description:
    Indicates if the Soft-AP should map all DNS domain names to the server to
      capture the clients device.

  Precondition:
    WDRV_WINC_HTTPProvCtxSetDefaults must have been called.

  Parameters:
    pHTTPProvCtx - Pointer to provisioning store structure.

  Returns:
    WDRV_WINC_STATUS_OK             - The flag is set.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_HTTPProvCtxSetURLWildcard
(
    WDRV_WINC_HTTP_PROV_CONTEXT *const pHTTPProvCtx,
    bool wildcardURL
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_HTTPProvCtxSetConnectCallback
    (
        WDRV_WINC_HTTP_PROV_CONTEXT *const pHTTPProvCtx,
        const WDRV_WINC_HTTPPROV_INFO_CALLBACK pfProvConnectInfoCB
    )

  Summary:
    Defines the connection information callback.

  Description:
    Associates the function provided with the provisioning context. The callback
      will be used once the client has provided credentials to be used.

  Precondition:
    WDRV_WINC_HTTPProvCtxSetDefaults must have been called.

  Parameters:
    pHTTPProvCtx        - Pointer to provisioning store structure.
    pfProvConnectInfoCB - Function pointer for callback function.

  Returns:
    WDRV_WINC_STATUS_OK             - The callback is set.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_HTTPProvCtxSetConnectCallback
(
    WDRV_WINC_HTTP_PROV_CONTEXT *const pHTTPProvCtx,
    const WDRV_WINC_HTTPPROV_INFO_CALLBACK pfProvConnectInfoCB
);

#endif /* _WDRV_WINC_HTTPPROVCTX_H */
