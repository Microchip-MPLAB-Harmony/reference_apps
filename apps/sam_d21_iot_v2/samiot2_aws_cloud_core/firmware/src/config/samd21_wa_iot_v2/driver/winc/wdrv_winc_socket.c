
/*******************************************************************************
  WINC Driver Socket Mode Implementation

  File Name:
    wdrv_winc_socket.c

  Summary:
    WINC wireless driver (Socket mode) implementation.

  Description:
    This interface provides extra functionality required for socket mode operation.
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
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include "wdrv_winc.h"
#include "wdrv_winc_common.h"
#include "wdrv_winc_socket.h"
#ifndef WDRV_WINC_DEVICE_LITE_DRIVER
#include "m2m_ota.h"
#endif

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver Socket Mode Callback Implementation
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    void _WDRV_WINC_ICMPEchoResponseCallback
    (
        uint32_t ipAddress,
        uint32_t rtt,
        uint8_t errorCode
    )

  Summary:
    ICMP echo response event callback.

  Description:

  Precondition:
    None.

  Parameters:
    ipAddress - IP address of echo request target.
    rtt       - Round trip time in milliseconds.
    errorCode - Error code if echo request failed.

  Returns:
    None.

  Remarks:
    None.

*/

static void _WDRV_WINC_ICMPEchoResponseCallback
(
    uint32_t ipAddress,
    uint32_t rtt,
    uint8_t errorCode
)
{
    /* Open driver to obtain handle. */
    DRV_HANDLE handle = WDRV_WINC_Open(0, 0);

    /* Ensure handle is valid. */
    if (DRV_HANDLE_INVALID != handle)
    {
        WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;

        if (NULL != pDcpt->pCtrl->pfICMPEchoResponseCB)
        {
            /* Call ICMP echo response callback if present. */
            pDcpt->pCtrl->pfICMPEchoResponseCB(handle, ipAddress, rtt, errorCode);
        }
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver Socket Mode Implementation
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    static WDRV_WINC_STATUS _WDRV_WINC_OTAInProgress(WDRV_WINC_DCPT *const pDcpt)

  Summary:
    Check if OTA is in progress.

  Description:
    Checks if an OTA is in progress and other handle/pointer validation.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    pDcpt   - Descriptor pointer obtained from WDRV_WINC_Open handle.

  Returns:
    WDRV_WINC_STATUS_OK            - The request has been accepted.
    WDRV_WINC_STATUS_NOT_OPEN      - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG   - The parameters were incorrect.

  Remarks:
    None.

*/

static WDRV_WINC_STATUS _WDRV_WINC_OTAInProgress(WDRV_WINC_DCPT *const pDcpt)
{
    /* Ensure the driver handle and user pointer is valid. */
    if ((DRV_HANDLE_INVALID == (DRV_HANDLE)pDcpt) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    /* Ensure an update isn't in progress. */
    if (true == pDcpt->pCtrl->updateInProgress)
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_IPAddressSet
    (
        DRV_HANDLE handle,
        uint32_t ipAddress,
        uint32_t netMask
    )

  Summary:
    Configures an IPv4 address.

  Description:
    Disables DHCP on the WINC and assigns a static IPv4 address. The address
      isn't applied to the WINC until a connection is formed.

  Remarks:
    See wdrv_winc_socket.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_IPAddressSet
(
    DRV_HANDLE handle,
    uint32_t ipAddress,
    uint32_t netMask
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

    /* Ensure WINC is not connected. */
    if (true == pDcpt->pCtrl->isConnected)
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    /* Set IP address details. */
    pDcpt->pCtrl->ipAddress = ipAddress;
    pDcpt->pCtrl->netMask   = netMask;
    pDcpt->pCtrl->useDHCP   = false;

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    uint32_t WDRV_WINC_IPAddressGet(DRV_HANDLE handle)

  Summary:
    Returns the current IPv4 address.

  Description:
    Returns the current IPv4 address if configured.

  Remarks:
    See wdrv_winc_socket.h for usage information.

*/

uint32_t WDRV_WINC_IPAddressGet(DRV_HANDLE handle)
{
    const WDRV_WINC_DCPT *const pDcpt = (const WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl))
    {
        return 0;
    }

    /* Ensure driver is open and has obtained an IP address. */
    if ((false == pDcpt->isOpen) || (false == pDcpt->pCtrl->haveIPAddress))
    {
        return 0;
    }

    return pDcpt->pCtrl->ipAddress;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_IPDNSServerAddressSet
    (
        DRV_HANDLE handle,
        uint32_t dnsServerAddress
    )

  Summary:
    Configures the DNS server address.

  Description:
    Disables DHCP on the WINC and assigns a static DNS address. The address
      isn't applied to the WINC until a connection is formed.

  Remarks:
    See wdrv_winc_socket.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_IPDNSServerAddressSet
(
    DRV_HANDLE handle,
    uint32_t dnsServerAddress
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

    /* Ensure WINC is not connected. */
    if (true == pDcpt->pCtrl->isConnected)
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    /* Set DNS server address and turn off DHCP. */
    pDcpt->pCtrl->dnsServerAddress = dnsServerAddress;
    pDcpt->pCtrl->useDHCP = false;

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_IPDefaultGatewaySet
    (
        DRV_HANDLE handle,
        uint32_t gatewayAddress
    )

  Summary:
    Configures the default gateway used by the WINC.

  Description:
    Disables DHCP on the WINC and assigns a static default gateway address.
      The address isn't applied to the WINC until a connection is formed.

  Remarks:
    See wdrv_winc_socket.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_IPDefaultGatewaySet
(
    DRV_HANDLE handle,
    uint32_t gatewayAddress
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

    /* Ensure WINC is not connected. */
    if (true == pDcpt->pCtrl->isConnected)
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    /* Set default gateway address and turn off DHCP. */
    pDcpt->pCtrl->gatewayAddress = gatewayAddress;
    pDcpt->pCtrl->useDHCP = false;

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_IPUseDHCPSet
    (
        DRV_HANDLE handle,
        const WDRV_WINC_DHCP_ADDRESS_EVENT_HANDLER pfDHCPAddressEventCallback
    )

  Summary:
    Enables DHCP.

  Description:
    Enables the use of DHCP by the WINC. This removes any static IP
      configuration. The use of DHCP isn't applied to the WINC until a
      connection is formed.

  Remarks:
    See wdrv_winc_socket.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_IPUseDHCPSet
(
    DRV_HANDLE handle,
    const WDRV_WINC_DHCP_ADDRESS_EVENT_HANDLER pfDHCPAddressEventCallback
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

    /* Ensure WINC is not connected. */
    if (true == pDcpt->pCtrl->isConnected)
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    /* Enable DHCP and set callback. */
    pDcpt->pCtrl->useDHCP = true;
    pDcpt->pCtrl->pfDHCPAddressEventCB = pfDHCPAddressEventCallback;

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_IPUseDHCPGet(DRV_HANDLE handle)

  Summary:
    Determine if DHCP is to be used.

  Description:
     Determines if the WINC will use DHCP for IP address configuration.

  Remarks:
    See wdrv_winc_socket.h for usage information.

*/

bool WDRV_WINC_IPUseDHCPGet(DRV_HANDLE handle)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl))
    {
        return false;
    }

    return ((true == pDcpt->pCtrl->useDHCP) || (0 == pDcpt->pCtrl->ipAddress));
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_IPDHCPServerConfigure
    (
        DRV_HANDLE handle,
        uint32_t ipAddress,
        WDRV_WINC_DHCP_ADDRESS_EVENT_HANDLER const pfDHCPAddressEventCallback
    )

  Summary:
    Configures the Soft-AP DHCP server.

  Description:
    Configures the IPv4 address and callback for the DHCP server.

  Remarks:
    See wdrv_winc_socket.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_IPDHCPServerConfigure
(
    DRV_HANDLE handle,
    uint32_t ipAddress,
    uint32_t netMask,
    const WDRV_WINC_DHCP_ADDRESS_EVENT_HANDLER pfDHCPAddressEventCallback
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

    /* Set DHCP server address and event callback. */
    pDcpt->pCtrl->dhcpServerAddress = ipAddress;
    pDcpt->pCtrl->pfDHCPAddressEventCB = pfDHCPAddressEventCallback;
#ifdef WDRV_WINC_DEVICE_SOFT_AP_EXT
    pDcpt->pCtrl->netMask = netMask;
#endif

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_IPLinkActive(DRV_HANDLE handle)

  Summary:
    Indicates state of IP link.

  Description:
    Returns a flag indicating if the IP link is active or not.

  Remarks:
    See wdrv_winc_socket.h for usage information.

*/

bool WDRV_WINC_IPLinkActive(DRV_HANDLE handle)
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
        return false;
    }

    return pDcpt->pCtrl->haveIPAddress;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_ICMPEchoRequest
    (
        DRV_HANDLE handle,
        uint32_t ipAddress,
        uint8_t ttl,
        const WDRV_WINC_ICMP_ECHO_RSP_EVENT_HANDLER pfICMPEchoResponseCB
    )

  Summary:
    Sends an ICMP echo request.

  Description:
    Sends an ICMP echo request packet to the IP specified.

  Remarks:
    See wdrv_winc_socket.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_ICMPEchoRequest
(
    DRV_HANDLE handle,
    uint32_t ipAddress,
    uint8_t ttl,
    const WDRV_WINC_ICMP_ECHO_RSP_EVENT_HANDLER pfICMPEchoResponseCB
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;

    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl) || (0 == ipAddress))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    /* Send ICMP echo request. */
    if (M2M_SUCCESS != m2m_ping_req(ipAddress, ttl, &_WDRV_WINC_ICMPEchoResponseCallback))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    pDcpt->pCtrl->pfICMPEchoResponseCB = pfICMPEchoResponseCB;

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_OTAUpdateFromURL
    (
        DRV_HANDLE handle,
        char *pURL,
        const WDRV_WINC_OTA_STATUS_CALLBACK pfUpdateStatusCB
    )

  Summary:
    Perform OTA from URL provided.

  Description:
    Using the URL provided the WINC will attempt to download and store the
      updated firmware image.

  Remarks:
    See wdrv_winc_socket.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_OTAUpdateFromURL
(
    DRV_HANDLE handle,
    char *pURL,
    const WDRV_WINC_OTA_STATUS_CALLBACK pfUpdateStatusCB
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    WDRV_WINC_STATUS status;

    /* Ensure the driver is open and no OTA is in progress. */
    status = _WDRV_WINC_OTAInProgress(pDcpt);

    if (WDRV_WINC_STATUS_OK != status)
    {
        return status;
    }

    /* Ensure the user pointer is valid. */
    if (NULL == pURL)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    /* Ensure an update isn't in progress. */
    if (true == pDcpt->pCtrl->updateInProgress)
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    /* Start an OTA update. */
    if (M2M_SUCCESS != m2m_ota_start_update((WDRV_WINC_DEVICE_URL_TYPE*)pURL))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    /* Set in progress flag and callback. */
    pDcpt->pCtrl->updateInProgress      = true;
    pDcpt->pCtrl->pfOTADownloadStatusCB = pfUpdateStatusCB;

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_OTAUpdateAbort(DRV_HANDLE handle)

  Summary:
    Abort an OTA update.

  Description:
    Requests a current OTA update operation be aborted.

  Remarks:
    See wdrv_winc_socket.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_OTAUpdateAbort(DRV_HANDLE handle)
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

    /* Ensure an update isn't in progress. */
    if (false == pDcpt->pCtrl->updateInProgress)
    {
        return WDRV_WINC_STATUS_OK;
    }

    /* Abort the OTA. */
    if (M2M_SUCCESS != m2m_ota_abort())
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
}

#ifdef WDRV_WINC_DEVICE_OTA_SSL_OPTIONS
//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_OTASSLServerAuthModeSet
    (
        DRV_HANDLE handle,
        bool enabled
    );

  Summary:
    Set OTA SSL server authentication mode.

  Description:
    Sets if the OTA should authenticate the SSL server being connected to.

  Remarks:
    See wdrv_winc_socket.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_OTASSLServerAuthModeSet
(
    DRV_HANDLE handle,
    bool enabled
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    WDRV_WINC_STATUS status;
    int optValue;

    /* Ensure the driver is open and no OTA is in progress. */
    status = _WDRV_WINC_OTAInProgress(pDcpt);

    if (WDRV_WINC_STATUS_OK != status)
    {
        return status;
    }

    optValue = (true == enabled) ? 0 : 1;

    if (M2M_SUCCESS != m2m_ota_set_ssl_option(WIFI_OTA_SSL_OPT_BYPASS_SERVER_AUTH, &optValue, sizeof(int)))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    WDRV_DBG_VERBOSE_PRINT("OTA Server Bypass Mode = %d\r\n", optValue);

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_OTASSLServerAuthModeIsEnabled(DRV_HANDLE handle);

  Summary:
    Indicates if OTA SSL server authentication is enabled.

  Description:
    Indicates if server authentication is enabled (true) or disabled (false).

  Remarks:
    See wdrv_winc_socket.h for usage information.

*/

bool WDRV_WINC_OTASSLServerAuthModeIsEnabled(DRV_HANDLE handle)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    WDRV_WINC_STATUS status;
    int optValue;
    size_t optLength;

    /* Ensure the driver is open and no OTA is in progress. */
    status = _WDRV_WINC_OTAInProgress(pDcpt);

    if (WDRV_WINC_STATUS_OK != status)
    {
        return false;
    }

    optLength = sizeof(optValue);

    if (M2M_SUCCESS != m2m_ota_get_ssl_option(WIFI_OTA_SSL_OPT_BYPASS_SERVER_AUTH, &optValue, &optLength))
    {
        return false;
    }

    if (optLength != sizeof(int))
    {
        return false;
    }

    return (1 == optValue) ? false : true;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_OTASSLSNISet
    (
        DRV_HANDLE handle,
        const char *pServerName
    );

  Summary:
    Configures OTA SSL SNI.

  Description:
    Sets the server name to be used for SSL SNI during OTA operations.

  Remarks:
    See wdrv_winc_socket.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_OTASSLSNISet
(
    DRV_HANDLE handle,
    const char *pServerName
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    WDRV_WINC_STATUS status;
    int optSNIEn;
    size_t optSNINameLen;
    static const char optSNINameBlank = '\0';
    const char *pOptSNIName;

    /* Ensure the driver is open and no OTA is in progress. */
    status = _WDRV_WINC_OTAInProgress(pDcpt);

    if (WDRV_WINC_STATUS_OK != status)
    {
        return status;
    }

    if (NULL != pServerName)
    {
        optSNIEn      = 1;
        optSNINameLen = strlen(pServerName)+1;
        pOptSNIName   = pServerName;
    }
    else
    {
        optSNIEn      = 0;
        optSNINameLen = 1;
        pOptSNIName   = &optSNINameBlank;
    }

    if (M2M_SUCCESS != m2m_ota_set_ssl_option(WIFI_OTA_SSL_OPT_SNI_VALIDATION, &optSNIEn, sizeof(int)))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    if (M2M_SUCCESS != m2m_ota_set_ssl_option(WIFI_OTA_SSL_OPT_SNI_SERVERNAME, pOptSNIName, optSNINameLen))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    WDRV_DBG_VERBOSE_PRINT("OTA SNI = '%s',%d\r\n", pOptSNIName, optSNIEn);

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_OTASSLSNIIsEnabled(DRV_HANDLE handle);

  Summary:
    Indicates if OTA SSL SNI is enabled.

  Description:
    Indicates if the OTA SSL SNI feature is enabled.

  Remarks:
    See wdrv_winc_socket.h for usage information.

*/

bool WDRV_WINC_OTASSLSNIIsEnabled(DRV_HANDLE handle)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    WDRV_WINC_STATUS status;
    int optValue;
    size_t optLength;

    /* Ensure the driver is open and no OTA is in progress. */
    status = _WDRV_WINC_OTAInProgress(pDcpt);

    if (WDRV_WINC_STATUS_OK != status)
    {
        return false;
    }

    optLength = sizeof(optValue);

    if (M2M_SUCCESS != m2m_ota_get_ssl_option(WIFI_OTA_SSL_OPT_SNI_VALIDATION, &optValue, &optLength))
    {
        return false;
    }

    if (optLength != sizeof(int))
    {
        return false;
    }

    return (1 == optValue) ? true : false;
}
#endif /* WDRV_WINC_DEVICE_OTA_SSL_OPTIONS */

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_RollbackActiveFirmwareImage
    (
        DRV_HANDLE handle,
        const WDRV_WINC_OTA_STATUS_CALLBACK pfSwitchFirmwareStatusCB
    );

  Summary:
    Rolls back to a previous version.

  Description:
    Requests that the firmware be rolled back to a previous version.

  Remarks:
    See wdrv_winc_socket.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_RollbackActiveFirmwareImage
(
    DRV_HANDLE handle,
    const WDRV_WINC_OTA_STATUS_CALLBACK pfSwitchFirmwareStatusCB
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

    /* Rollback the OTA. */
    if (M2M_SUCCESS != m2m_ota_rollback())
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    /* Store callback. */
    pDcpt->pCtrl->pfSwitchFirmwareStatusCB = pfSwitchFirmwareStatusCB;

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_SwitchActiveFirmwareImage
    (
        DRV_HANDLE handle,
        const WDRV_WINC_OTA_STATUS_CALLBACK pfSwitchFirmwareStatusCB
    )

  Summary:
    Switch active firmware image to inactive partition.

  Description:
    If there is an inactive firmware partition, either from an OTA update of from
      a previously disabled firmware image this function switches the WINC to
      use it. A reset of the WINC is required before the image becomes active.

  Remarks:
    See wdrv_winc_socket.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_SwitchActiveFirmwareImage
(
    DRV_HANDLE handle,
    const WDRV_WINC_OTA_STATUS_CALLBACK pfSwitchFirmwareStatusCB
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

    /* Switch active firmware partitions. */
    if (M2M_SUCCESS != m2m_ota_switch_firmware())
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    /* Store callback. */
    pDcpt->pCtrl->pfSwitchFirmwareStatusCB = pfSwitchFirmwareStatusCB;

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_SocketRegisterEventCallback
    (
        DRV_HANDLE handle,
        tpfAppSocketCb pfAppSocketCb
    )

  Summary:
    Register an event callback for socket events.

  Description:
    Socket events are dispatched to the application via this callback.

  Remarks:
    See wdrv_winc_socket.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_SocketRegisterEventCallback
(
    DRV_HANDLE handle,
    tpfAppSocketCb pfAppSocketCb
)
{
    if (DRV_HANDLE_INVALID == handle)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    registerSocketEventCallback(pfAppSocketCb);

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_SocketRegisterResolverCallback
    (
        DRV_HANDLE handle,
        tpfAppResolveCb pfAppResolveCb
    )

  Summary:
    Register an event callback for DNS resolver events.

  Description:
    DNS resolver events are dispatched to the application via this callback.

  Remarks:
    See wdrv_winc_socket.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_SocketRegisterResolverCallback
(
    DRV_HANDLE handle,
    tpfAppResolveCb pfAppResolveCb
)
{
    if (DRV_HANDLE_INVALID == handle)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    registerSocketResolveCallback(pfAppResolveCb);

    return WDRV_WINC_STATUS_OK;
}
