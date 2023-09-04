/*******************************************************************************
  WINC Driver HTTP Provision Context Implementation

  File Name:
    wdrv_winc_httpprovctx.c

  Summary:
    WINC wireless driver HTTP provisioning context implementation.

  Description:
    This interface manages the HTTP provisioning context which is used to
      define the behaviour of the HTTP provisioning provided by Soft-AP mode.
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

#include "wdrv_winc_common.h"
#include "wdrv_winc_httpprovctx.h"

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver HTTP Provisioning Context Implementation
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

  Remarks:
    See wdrv_winc_httpprovctx.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_HTTPProvCtxSetDefaults
(
    WDRV_WINC_HTTP_PROV_CONTEXT *const pHTTPProvCtx
)
{
    /* Ensure provisioning context is valid. */
    if (NULL == pHTTPProvCtx)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Set the context to no domain, with wild card URL mapping and no callback. */
    pHTTPProvCtx->wildcardURL         = true;
    pHTTPProvCtx->domainName[0]       = '\0';
    pHTTPProvCtx->pfProvConnectInfoCB = NULL;

    return WDRV_WINC_STATUS_OK;
}

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

  Remarks:
    See wdrv_winc_httpprovctx.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_HTTPProvCtxSetDomainName
(
    WDRV_WINC_HTTP_PROV_CONTEXT *const pHTTPProvCtx,
    const char *const pname
)
{
    size_t nameLength;

    /* Ensure provisioning context is valid. */
    if (NULL == pHTTPProvCtx)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Check length of domain name. */
    nameLength = strlen(pname);

    if (nameLength > 64)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Copy domain name into context ensuring unused space is zeroed. */
    memset(&pHTTPProvCtx->domainName, 0, 64+1);
    memcpy(pHTTPProvCtx->domainName, pname, nameLength);

    return WDRV_WINC_STATUS_OK;
}

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

  Remarks:
    See wdrv_winc_httpprovctx.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_HTTPProvCtxSetURLWildcard
(
    WDRV_WINC_HTTP_PROV_CONTEXT *const pHTTPProvCtx,
    bool wildcardURL
)
{
    /* Ensure provisioning context is valid. */
    if (NULL == pHTTPProvCtx)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Set wild card flag. */
    pHTTPProvCtx->wildcardURL = wildcardURL;

    return WDRV_WINC_STATUS_OK;
}

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

  Remarks:
    See wdrv_winc_httpprovctx.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_HTTPProvCtxSetConnectCallback
(
    WDRV_WINC_HTTP_PROV_CONTEXT *const pHTTPProvCtx,
    const WDRV_WINC_HTTPPROV_INFO_CALLBACK pfProvConnectInfoCB
)
{
    /* Ensure provisioning context is valid. */
    if (NULL == pHTTPProvCtx)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Set the provision callback. */
    pHTTPProvCtx->pfProvConnectInfoCB = pfProvConnectInfoCB;

    return WDRV_WINC_STATUS_OK;
}
