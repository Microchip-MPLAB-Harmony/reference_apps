/*******************************************************************************
  WINC Driver Socket Mode Header File

  Company:
    Microchip Technology Inc.

  File Name:
    wdrv_winc_socket.h

  Summary:
    WINC wireless driver (Socket mode) header file.

  Description:
    This interface provides extra functionality required for socket mode operation.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

#ifndef _WDRV_WINC_SOCKET_H
#define _WDRV_WINC_SOCKET_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "wdrv_winc.h"
#include "wdrv_winc_httpprovctx.h"
#ifndef WDRV_WINC_DEVICE_LITE_DRIVER
#include "socket.h"
#endif

// DOM-IGNORE-BEGIN
#ifdef __cplusplus // Provide C++ Compatibility
    extern "C" {
#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver Socket Mode Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/*  OTA Update Status

  Summary:
    OTA update statuses.

  Description:
    List of possible OTA update statuses.

  Remarks:
    None.

*/

typedef enum
{
    /* OTA completed successfully. */
    WDRV_WINC_OTA_STATUS_COMPLETE = /*DOM-IGNORE-BEGIN*/ OTA_STATUS_SUCCESS /*DOM-IGNORE-END*/,

    /* OTA failed. */
    WDRV_WINC_OTA_STATUS_FAIL = /*DOM-IGNORE-BEGIN*/ OTA_STATUS_FAIL /*DOM-IGNORE-END*/,

    /* The OTA URL was invalid. */
    WDRV_WINC_OTA_STATUS_INVALID_URL = /*DOM-IGNORE-BEGIN*/ OTA_STATUS_INVALID_ARG /*DOM-IGNORE-END*/,

    /* The rollback image is invalid. */
    WDRV_WINC_OTA_STATUS_INVALID_RB_IMAGE = /*DOM-IGNORE-BEGIN*/ OTA_STATUS_INVALID_RB_IMAGE /*DOM-IGNORE-END*/,

    /* The flash is too small for the update. */
    WDRV_WINC_OTA_STATUS_INSUFFICIENT_FLASH = /*DOM-IGNORE-BEGIN*/ OTA_STATUS_INVALID_FLASH_SIZE /*DOM-IGNORE-END*/,

#ifdef WDRV_WINC_DEVICE_OTA_STATUS_EXTENDED
    /* An OTA operation is already enabled. */
    WDRV_WINC_OTA_STATUS_ALREADY_ENABLED = /*DOM-IGNORE-BEGIN*/ OTA_STATUS_ALREADY_ENABLED /*DOM-IGNORE-END*/,
#endif

    /* An OTA operation is in progress. */
    WDRV_WINC_OTA_STATUS_BUSY = /*DOM-IGNORE-BEGIN*/ OTA_STATUS_UPDATE_INPROGRESS /*DOM-IGNORE-END*/,

    /* Verification of the OTA image failed. */
    WDRV_WINC_OTA_STATUS_VERIFY_FAILED = /*DOM-IGNORE-BEGIN*/ OTA_STATUS_IMAGE_VERIF_FAILED /*DOM-IGNORE-END*/,

    /* An error occurred during the connection. */
    WDRV_WINC_OTA_STATUS_CONN_ERROR = /*DOM-IGNORE-BEGIN*/ OTA_STATUS_CONNECTION_ERROR /*DOM-IGNORE-END*/,

    /* The server returned an error. */
    WDRV_WINC_OTA_STATUS_SERVER_ERROR = /*DOM-IGNORE-BEGIN*/ OTA_STATUS_SERVER_ERROR /*DOM-IGNORE-END*/,

    /* The OTA operation was aborted. */
    WDRV_WINC_OTA_STATUS_ABORTED = /*DOM-IGNORE-BEGIN*/ OTA_STATUS_ABORTED /*DOM-IGNORE-END*/
} WDRV_WINC_OTA_UPDATE_STATUS;

// *****************************************************************************
/*  ICMP Echo Status Codes

  Summary:
    Defines the ICMP echo status codes.

  Description:
    This enumeration defines the ICMP status supplied by the ICMP echo response
    callback.

  Remarks:
    This is only defined for use with the WINC in socket mode.

*/

typedef enum
{
    /* The operation completed successfully. */
    WDRV_WINC_ICMP_ECHO_STATUS_SUCCESS = 0,

    /* ICMP destination unreachable. */
    WDRV_WINC_ICMP_ECHO_STATUS_UNREACH = 1,

    /* The operation timed out. */
    WDRV_WINC_ICMP_ECHO_STATUS_TIMEOUT = 2
} WDRV_WINC_ICMP_ECHO_STATUS;

// *****************************************************************************
/* ICMP Echo Response Event Handler Function Pointer

  Summary:
    Pointer to an ICMP echo response event handler function.

  Description:
    This data type defines a function event handler which is
    called in response to an ICMP echo request response event.

  Parameters:
    handle      - Client handle obtained by a call to WDRV_WINC_Open.
    ipAddress   - IPv4 address.
    rtt         - The round-trip time.
    statusCode  - Status code.

  Returns:
    None.

  Remarks:
    Only supported with the socket mode WINC driver.

    The status code indicates if the ICMP echo request was successful or not.
    It may take the form of either:

        PING_ERR_SUCCESS        - The request was successful.
        PING_ERR_DEST_UNREACH   - The destination was unreachable.
        PING_ERR_TIMEOUT        - The request timed out.

*/

typedef void (*WDRV_WINC_ICMP_ECHO_RSP_EVENT_HANDLER)
(
    DRV_HANDLE handle,
    uint32_t ipAddress,
    uint32_t rtt,
    WDRV_WINC_ICMP_ECHO_STATUS statusCode
);

// *****************************************************************************
/* DHCP Address Event Handler Function Pointer

  Summary:
    Pointer to a DHCP address event handler function.

  Description:
    This data type defines a function event handler to receive notification
    of allocation of IP address via DHCP.

  Parameters:
    handle      - Client handle obtained by a call to WDRV_WINC_Open.
    ipAddress   - IPv4 address.

  Returns:
    None.

  Remarks:
    Only supported with the socket mode WINC driver.

    See WDRV_WINC_IPSetUseDHCP and WDRV_WINC_IPDHCPServerConfigure.

*/

typedef void (*WDRV_WINC_DHCP_ADDRESS_EVENT_HANDLER)
(
    DRV_HANDLE handle,
    uint32_t ipAddress
);

// *****************************************************************************
/* OTA Status Callback Function Pointer

  Summary:
    Pointer to an OTA status callback function.

  Description:
    This defines an OTA status function callback type which can be passed
    into certain OTA functions to receive feedback.

  Parameters:
    handle  - Client handle obtained by a call to WDRV_WINC_Open.
    status  - A status value.

  Returns:
    None.

  Remarks:
    None.

*/

typedef void (*WDRV_WINC_OTA_STATUS_CALLBACK)
(
    DRV_HANDLE handle,
    WDRV_WINC_OTA_UPDATE_STATUS status
);

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver Socket Mode Routines
// *****************************************************************************
// *****************************************************************************

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

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.
    The WINC must not be connected.

  Parameters:
    handle    - Client handle obtained by a call to WDRV_WINC_Open.
    ipAddress - IPv4 address.
    netMask   - IPv4 netmask.

  Returns:
    WDRV_WINC_STATUS_OK             - The address has been accepted.
    WDRV_WINC_STATUS_NOT_OPEN       - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR  - The request to the WINC was rejected.

  Remarks:
    Only applicable when connected in infrastructure station mode.
    The top 8 bits of the IPv4 32 bit representation corresponds to
      the last byte of the IPv4 address, i.e. 192.168.0.1 = 0x0100A8C0

*/

WDRV_WINC_STATUS WDRV_WINC_IPAddressSet
(
    DRV_HANDLE handle,
    uint32_t ipAddress,
    uint32_t netMask
);

//*******************************************************************************
/*
  Function:
    uint32_t WDRV_WINC_IPAddressGet(DRV_HANDLE handle)

  Summary:
    Returns the current IPv4 address.

  Description:
    Returns the current IPv4 address if configured.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle - Client handle obtained by a call to WDRV_WINC_Open.

  Returns:
    IP address or zero for an error conditions.

  Remarks:
    The top 8 bits of the IPv4 32 bit representation corresponds to
      the last byte of the IPv4 address, i.e. 192.168.0.1 = 0x0100A8C0

*/

uint32_t WDRV_WINC_IPAddressGet(DRV_HANDLE handle);

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

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.
    The WINC must not be connected.

  Parameters:
    handle           - Client handle obtained by a call to WDRV_WINC_Open.
    dnsServerAddress - IPv4 address of DNS server.

  Returns:
    WDRV_WINC_STATUS_OK             - The address has been accepted.
    WDRV_WINC_STATUS_NOT_OPEN       - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR  - The request to the WINC was rejected.

  Remarks:
    Only applicable when connected in infrastructure station mode.
    The top 8 bits of the IPv4 32 bit representation corresponds to
      the last byte of the IPv4 address, i.e. 192.168.0.1 = 0x0100A8C0

*/

WDRV_WINC_STATUS WDRV_WINC_IPDNSServerAddressSet
(
    DRV_HANDLE handle,
    uint32_t dnsServerAddress
);

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

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.
    The WINC must not be connected.

  Parameters:
    handle         - Client handle obtained by a call to WDRV_WINC_Open.
    gatewayAddress - IPv4 address of default gateway.

  Returns:
    WDRV_WINC_STATUS_OK             - The address has been accepted.
    WDRV_WINC_STATUS_NOT_OPEN       - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR  - The request to the WINC was rejected.

  Remarks:
    Only applicable when connected in infrastructure station mode.
    The top 8 bits of the IPv4 32 bit representation corresponds to
      the last byte of the IPv4 address, i.e. 192.168.0.1 = 0x0100A8C0

*/

WDRV_WINC_STATUS WDRV_WINC_IPDefaultGatewaySet
(
    DRV_HANDLE handle,
    uint32_t gatewayAddress
);

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

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.
    The WINC must not be connected.

  Parameters:
    handle                     - Client handle obtained by a call to
                                   WDRV_WINC_Open.
    pfDHCPAddressEventCallback - Callback for DHCP address events.

  Returns:
    WDRV_WINC_STATUS_OK             - The request has been accepted.
    WDRV_WINC_STATUS_NOT_OPEN       - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR  - The request to the WINC was rejected.

  Remarks:
    Only applicable when connected in infrastructure station mode.

*/

WDRV_WINC_STATUS WDRV_WINC_IPUseDHCPSet
(
    DRV_HANDLE handle,
    const WDRV_WINC_DHCP_ADDRESS_EVENT_HANDLER pfDHCPAddressEventCallback
);

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_IPUseDHCPGet(DRV_HANDLE handle)

  Summary:
    Determine if DHCP is to be used.

  Description:
     Determines if the WINC will use DHCP for IP address configuration.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.
    The WINC must not be connected.

  Parameters:
    handle - Client handle obtained by a call to WDRV_WINC_Open.

  Returns:
    Flag indicating if DHCP will be used.

  Remarks:
    Only applicable when connected in infrastructure station mode.

*/

bool WDRV_WINC_IPUseDHCPGet(DRV_HANDLE handle);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_IPDHCPServerConfigure
    (
        DRV_HANDLE handle,
        uint32_t ipAddress,
        uint32_t netMask,
        WDRV_WINC_DHCP_ADDRESS_EVENT_HANDLER const pfDHCPAddressEventCallback
    )

  Summary:
    Configures the Soft-AP DHCP server.

  Description:
    Configures the IPv4 address and callback for the DHCP server.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.
    The WINC must not be connected.

  Parameters:
    handle                     - Client handle obtained by a call to
                                   WDRV_WINC_Open.
    ipAddress                  - IPv4 address.
    netMask                    - IPv4 netmask.
    pfDHCPAddressEventCallback - Callback for DHCP address events.

  Returns:
    WDRV_WINC_STATUS_OK          - The request has been accepted.
    WDRV_WINC_STATUS_NOT_OPEN    - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG - The parameters were incorrect.

  Remarks:
    Only applicable when connected in Soft-AP mode. Parameter netMask is
    only applicable for WINC drivers supporting the extended Soft-AP
    API m2m_wifi_enable_ap_ext and m2m_wifi_start_provision_mode_ext.

*/

WDRV_WINC_STATUS WDRV_WINC_IPDHCPServerConfigure
(
    DRV_HANDLE handle,
    uint32_t ipAddress,
    uint32_t netMask,
    const WDRV_WINC_DHCP_ADDRESS_EVENT_HANDLER pfDHCPAddressEventCallback
);

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_IPLinkActive(DRV_HANDLE handle)

  Summary:
    Indicates state of IP link.

  Description:
    Returns a flag indicating if the IP link is active or not.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle - Client handle obtained by a call to WDRV_WINC_Open.

  Returns:
    Flag indicating IP link active state (true/false).

  Remarks:
    None.

*/

bool WDRV_WINC_IPLinkActive(DRV_HANDLE handle);

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

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.
    The WINC must not be connected.

  Parameters:
    handle               - Client handle obtained by a call to WDRV_WINC_Open.
    ipAddress            - IPv4 address.
    ttl                  - The Time-to-live value.
    pfICMPEchoResponseCB - Callback for ICMP address events.

  Returns:
    WDRV_WINC_STATUS_OK            - The request has been accepted.
    WDRV_WINC_STATUS_NOT_OPEN      - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG   - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR - The request to the WINC was rejected.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_ICMPEchoRequest
(
    DRV_HANDLE handle,
    uint32_t ipAddress,
    uint8_t ttl,
    WDRV_WINC_ICMP_ECHO_RSP_EVENT_HANDLER pfICMPEchoResponseCB
);

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

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.
    The WINC must be connected.

  Parameters:
    handle           - Client handle obtained by a call to WDRV_WINC_Open.
    pURL             - Pointer to string containing URL of firmware image.
    pfUpdateStatusCB - Callback to indicate update status.

  Returns:
    WDRV_WINC_STATUS_OK            - The request has been accepted.
    WDRV_WINC_STATUS_NOT_OPEN      - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG   - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR - The request to the WINC was rejected.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_OTAUpdateFromURL
(
    DRV_HANDLE handle,
    char *pURL,
    const WDRV_WINC_OTA_STATUS_CALLBACK pfUpdateStatusCB
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_OTAUpdateAbort(DRV_HANDLE handle)

  Summary:
    Abort an OTA update.

  Description:
    Requests a current OTA update operation be aborted.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.
    The WINC must be connected.

  Parameters:
    handle - Client handle obtained by a call to WDRV_WINC_Open.

  Returns:
    WDRV_WINC_STATUS_OK             - The request has been accepted.
    WDRV_WINC_STATUS_NOT_OPEN       - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR  - The request to the WINC was rejected.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_OTAUpdateAbort(DRV_HANDLE handle);

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

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle  - Client handle obtained by a call to WDRV_WINC_Open.
    enabled - Enables (true) or disables (false) server authentication.

  Returns:
    WDRV_WINC_STATUS_OK             - The request has been accepted.
    WDRV_WINC_STATUS_NOT_OPEN       - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR  - The request to the WINC was rejected.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_OTASSLServerAuthModeSet
(
    DRV_HANDLE handle,
    bool enabled
);

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_OTASSLServerAuthModeIsEnabled(DRV_HANDLE handle);

  Summary:
    Indicates if OTA SSL server authentication is enabled.

  Description:
    Indicates if server authentication is enabled (true) or disabled (false).

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle - Client handle obtained by a call to WDRV_WINC_Open.

  Returns:
    true or false.

  Remarks:
    None.

*/

bool WDRV_WINC_OTASSLServerAuthModeIsEnabled(DRV_HANDLE handle);

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

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle      - Client handle obtained by a call to WDRV_WINC_Open.
    pServerName - Pointer to server name, or NULL to disable SNI.

  Returns:
    WDRV_WINC_STATUS_OK             - The request has been accepted.
    WDRV_WINC_STATUS_NOT_OPEN       - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR  - The request to the WINC was rejected.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_OTASSLSNISet
(
    DRV_HANDLE handle,
    const char *pServerName
);

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_OTASSLSNIIsEnabled(DRV_HANDLE handle);

  Summary:
    Indicates if OTA SSL SNI is enabled.

  Description:
    Indicates if the OTA SSL SNI feature is enabled.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle - Client handle obtained by a call to WDRV_WINC_Open.

  Returns:
    true or false.

  Remarks:
    None.

*/

bool WDRV_WINC_OTASSLSNIIsEnabled(DRV_HANDLE handle);
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

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle                   - Client handle obtained by a call to WDRV_WINC_Open.
    pfSwitchFirmwareStatusCB - Function callback to receive status updates.

  Returns:
    WDRV_WINC_STATUS_OK             - The request has been accepted.
    WDRV_WINC_STATUS_NOT_OPEN       - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR  - The request to the WINC was rejected.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_RollbackActiveFirmwareImage
(
    DRV_HANDLE handle,
    const WDRV_WINC_OTA_STATUS_CALLBACK pfSwitchFirmwareStatusCB
);

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

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle                   - Client handle obtained by a call to WDRV_WINC_Open.
    pfSwitchFirmwareStatusCB - Function callback to receive status updates.

  Returns:
    WDRV_WINC_STATUS_OK             - The request has been accepted.
    WDRV_WINC_STATUS_NOT_OPEN       - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR  - The request to the WINC was rejected.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_SwitchActiveFirmwareImage
(
    DRV_HANDLE handle,
    const WDRV_WINC_OTA_STATUS_CALLBACK pfSwitchFirmwareStatusCB
);

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

  Precondition:
    None.

  Parameters:
    handle        - Client handle obtained by a call to WDRV_WINC_Open.
    pfAppSocketCb - Function pointer to event callback handler.

  Returns:
    WDRV_WINC_STATUS_OK          - Callback registered.
    WDRV_WINC_STATUS_INVALID_ARG - The parameters were incorrect.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_SocketRegisterEventCallback
(
    DRV_HANDLE handle,
    tpfAppSocketCb pfAppSocketCb
);

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

  Precondition:
    None.

  Parameters:
    handle         - Client handle obtained by a call to WDRV_WINC_Open.
    pfAppResolveCb - Function pointer to event callback handler.

  Returns:
    WDRV_WINC_STATUS_OK          - Callback registered.
    WDRV_WINC_STATUS_INVALID_ARG - The parameters were incorrect.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_SocketRegisterResolverCallback
(
    DRV_HANDLE handle,
    tpfAppResolveCb pfAppResolveCb
);

// DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
// DOM-IGNORE-END

#endif /* _WDRV_WINC_SOCKET_H */
