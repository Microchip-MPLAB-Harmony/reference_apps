/*******************************************************************************
  WINC Driver Common Header File

  Company:
    Microchip Technology Inc.

  File Name:
    wdrv_winc_common.h

  Summary:
    WINC wireless driver common header file.

  Description:
    This file provides common elements of the WINC driver API.
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

#ifndef _WDRV_WINC_COMMON_H
#define _WDRV_WINC_COMMON_H

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

#include "configuration.h"
#include "definitions.h"
#include "driver/driver.h"
#include "osal/osal.h"
#include "wdrv_winc_debug.h"
#ifdef WDRV_WINC_DEVICE_LITE_DRIVER
#include "include/winc.h"
#else
#include "m2m_wifi.h"
#include "m2m_types.h"
#endif

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

/* Maximum length of an SSID. */
#define WDRV_WINC_MAX_SSID_LEN              32U

/* Address of a MAC address. */
#define WDRV_WINC_MAC_ADDR_LEN              6

#ifndef WDRV_WINC_DEVICE_DEPRECATE_WEP
/* Length of 40 bit WEP key. */
#define WDRV_WINC_WEP_40_KEY_STRING_SIZE    10

/* Length of 104 bit WEP key. */
#define WDRV_WINC_WEP_104_KEY_STRING_SIZE   26
#endif

/* Length of PSK (ASCII encoded binary). */
#define WDRV_WINC_PSK_LEN                   64

// *****************************************************************************
/*  WiFi Channels

  Summary:
    A list of supported WiFi channels.

  Description:
    A list of supported WiFi channels.

  Remarks:
    None.

*/

typedef enum _WDRV_WINCCHANNEL_ID
{
    /* Any valid channel. */
    WDRV_WINC_CID_ANY,

    /* 2.4 GHz channel 1 - 2412 MHz. */
    WDRV_WINC_CID_2_4G_CH1,

    /* 2.4 GHz channel 2 - 2417 MHz. */
    WDRV_WINC_CID_2_4G_CH2,

    /* 2.4 GHz channel 3 - 2422 MHz. */
    WDRV_WINC_CID_2_4G_CH3,

    /* 2.4 GHz channel 4 - 2427 MHz. */
    WDRV_WINC_CID_2_4G_CH4,

    /* 2.4 GHz channel 5 - 2432 MHz. */
    WDRV_WINC_CID_2_4G_CH5,

    /* 2.4 GHz channel 6 - 2437 MHz. */
    WDRV_WINC_CID_2_4G_CH6,

    /* 2.4 GHz channel 7 - 2442 MHz. */
    WDRV_WINC_CID_2_4G_CH7,

    /* 2.4 GHz channel 8 - 2447 MHz. */
    WDRV_WINC_CID_2_4G_CH8,

    /* 2.4 GHz channel 9 - 2452 MHz. */
    WDRV_WINC_CID_2_4G_CH9,

    /* 2.4 GHz channel 10 - 2457 MHz. */
    WDRV_WINC_CID_2_4G_CH10,

    /* 2.4 GHz channel 11 - 2462 MHz. */
    WDRV_WINC_CID_2_4G_CH11,

    /* 2.4 GHz channel 12 - 2467 MHz. */
    WDRV_WINC_CID_2_4G_CH12,

    /* 2.4 GHz channel 13 - 2472 MHz. */
    WDRV_WINC_CID_2_4G_CH13,

    /* 2.4 GHz channel 14 - 2484 MHz. */
    WDRV_WINC_CID_2_4G_CH14
} WDRV_WINC_CHANNEL_ID;

// *****************************************************************************
/* WINC Driver All Channels

  Summary:
    WINC Driver All Channels.

  Description:
    This constant is used to represent all WiFi channels.

  Remarks:
    None.

*/

#define WDRV_WINC_ALL_CHANNELS      0xff

// *****************************************************************************
/*  Common API Return Status Code

  Summary:
    API return status codes.

  Description:
    All API functions which return a status code will use one of these to be
      consistent.

  Remarks:
    None.

*/

typedef enum _WDRV_WINC_STATUS
{
    /* Operation was successful. */
    WDRV_WINC_STATUS_OK = 0,

    /* Driver instance has not been opened. */
    WDRV_WINC_STATUS_NOT_OPEN,

    /* The arguments supplied are not valid. */
    WDRV_WINC_STATUS_INVALID_ARG,

    /* A scan operation is currently in progress. */
    WDRV_WINC_STATUS_SCAN_IN_PROGRESS,

    /* No BSS information is available. */
    WDRV_WINC_STATUS_NO_BSS_INFO,

    /* No more BSS scan results are available. */
    WDRV_WINC_STATUS_BSS_FIND_END,

    /* The connection attempt has failed. */
    WDRV_WINC_STATUS_CONNECT_FAIL,

    /* The disconnection attempt has failed. */
    WDRV_WINC_STATUS_DISCONNECT_FAIL,

    /* The requested operation could not be completed. */
    WDRV_WINC_STATUS_REQUEST_ERROR,

    /* The context being referenced is invalid. */
    WDRV_WINC_STATUS_INVALID_CONTEXT,

    /* Request could not complete, but may if tried again. */
    WDRV_WINC_STATUS_RETRY_REQUEST,

    /* Out of space in resource. */
    WDRV_WINC_STATUS_NO_SPACE,

    /* No Ethernet buffer was available. */
    WDRV_WINC_STATUS_NO_ETH_BUFFER,

    /* Unable to lock the request resource. */
    WDRV_WINC_STATUS_RESOURCE_LOCK_ERROR,

    /* Not currently connected. */
    WDRV_WINC_STATUS_NOT_CONNECTED,

    /* The requested operation is not supported. */
    WDRV_WINC_STATUS_OPERATION_NOT_SUPPORTED
} WDRV_WINC_STATUS;

// *****************************************************************************
/*  Extended system status

  Summary:
    Defines extended system status.

  Description:
    An extended status

  Remarks:
    None.

*/

typedef enum
{
    WDRV_WINC_SYS_STATUS_ERROR_DEVICE_NOT_FOUND = (SYS_STATUS_ERROR_EXTENDED-1),

    WDRV_WINC_SYS_STATUS_ERROR_DEVICE_FAILURE   = (SYS_STATUS_ERROR_EXTENDED-2)
} WDRV_WINC_SYS_STATUS;

// *****************************************************************************
/*  Connection State

  Summary:
    Defines possible connection states.

  Description:
    A connection can currently either be connected or disconnect.

  Remarks:
    None.

*/

typedef enum
{
    /* Association state is disconnected. */
    WDRV_WINC_CONN_STATE_DISCONNECTED /*DOM-IGNORE-BEGIN*/ = M2M_WIFI_DISCONNECTED /*DOM-IGNORE-END*/,

    /* Association state is connected. */
    WDRV_WINC_CONN_STATE_CONNECTED /*DOM-IGNORE-BEGIN*/ = M2M_WIFI_CONNECTED /*DOM-IGNORE-END*/,

#ifdef WDRV_WINC_DEVICE_BSS_ROAMING
    /* Association state has been updated due to roaming. */
    WDRV_WINC_CONN_STATE_ROAMED /*DOM-IGNORE-BEGIN*/ = M2M_WIFI_ROAMED /*DOM-IGNORE-END*/
#endif
} WDRV_WINC_CONN_STATE;

// *****************************************************************************
/*  Transmit Data Rates

  Summary:
    Defines possible data rates.

  Description:
    Possible data rates.

  Remarks:
    None.

*/

typedef enum
{
    /* The lowest possible data rate. */
    WDRV_WINC_DATA_RATE_LOWEST,
    /* Any data rate. */
    WDRV_WINC_DATA_RATE_ANY,
    /* 1 Mbps  */
    WDRV_WINC_DATA_RATE_1,
    /* 2 Mbps  */
    WDRV_WINC_DATA_RATE_2,
    /* 5 Mbps  */
    WDRV_WINC_DATA_RATE_5_5,
    /* 11 Mbps */
    WDRV_WINC_DATA_RATE_11,
    /* 6 Mbps  */
    WDRV_WINC_DATA_RATE_6,
    /* 9 Mbps  */
    WDRV_WINC_DATA_RATE_9,
    /* 12 Mbps */
    WDRV_WINC_DATA_RATE_12,
    /* 18 Mbps */
    WDRV_WINC_DATA_RATE_18,
    /* 24 Mbps */
    WDRV_WINC_DATA_RATE_24,
    /* 36 Mbps */
    WDRV_WINC_DATA_RATE_36,
    /* 48 Mbps */
    WDRV_WINC_DATA_RATE_48,
    /* 54 Mbps */
    WDRV_WINC_DATA_RATE_54,
    /* MCS-0: 6.5 Mbps */
    WDRV_WINC_DATA_RATE_MCS_0,
    /* MCS-1: 13 Mbps */
    WDRV_WINC_DATA_RATE_MCS_1,
    /* MCS-2: 19.5 Mbps */
    WDRV_WINC_DATA_RATE_MCS_2,
    /* MCS-3: 26 Mbps */
    WDRV_WINC_DATA_RATE_MCS_3,
    /* MCS-4: 39 Mbps */
    WDRV_WINC_DATA_RATE_MCS_4,
    /* MCS-5: 52 Mbps */
    WDRV_WINC_DATA_RATE_MCS_5,
    /* MCS-6: 58.5 Mbps */
    WDRV_WINC_DATA_RATE_MCS_6,
    /* MCS-7: 65 Mbps */
    WDRV_WINC_DATA_RATE_MCS_7
} WDRV_WINC_DATA_RATE;

// *****************************************************************************
/*  Connection Error

  Summary:
    Defines possible connection errors.

  Description:
    A connection (and default connection) can result in one of these errors.

  Remarks:
    None.

*/

typedef enum
{
    WDRV_WINC_CONN_ERROR_SCAN /*DOM-IGNORE-BEGIN*/ = M2M_ERR_SCAN_FAIL /*DOM-IGNORE-END*/,
    WDRV_WINC_CONN_ERROR_AUTH /*DOM-IGNORE-BEGIN*/ = M2M_ERR_AUTH_FAIL /*DOM-IGNORE-END*/,
    WDRV_WINC_CONN_ERROR_ASSOC /*DOM-IGNORE-BEGIN*/ = M2M_ERR_ASSOC_FAIL /*DOM-IGNORE-END*/,
    WDRV_WINC_CONN_ERROR_INPROGRESS /*DOM-IGNORE-BEGIN*/ = M2M_ERR_CONN_INPROGRESS /*DOM-IGNORE-END*/,
    WDRV_WINC_CONN_ERROR_NOCRED,
    WDRV_WINC_CONN_ERROR_UNKNOWN
} WDRV_WINC_CONN_ERROR;

// *****************************************************************************
/*  SSID

  Summary:
    Structure to hold an SSID.

  Description:
    The SSID consist of a buffer and a length field.

  Remarks:
    None.

*/

typedef struct _WDRV_WINC_SSID
{
    /* SSID name, up to WDRV_WINC_MAX_SSID_LEN characters long. */
    uint8_t name[WDRV_WINC_MAX_SSID_LEN];

    /* Length of SSID name. */
    uint8_t length;
} WDRV_WINC_SSID;

// *****************************************************************************
/*  SSID Linked List

  Summary:
    Structure to hold an SSID linked list element.

  Description:
    An element structure which can form part of an SSID linked list.

  Remarks:
    None.

*/

typedef struct _WDRV_WINC_SSID_LIST
{
    /* Pointer to next SSID element in list. */
    struct _WDRV_WINC_SSID_LIST *pNext;

    /* SSID structure. */
    WDRV_WINC_SSID ssid;
} WDRV_WINC_SSID_LIST;

// *****************************************************************************
/*  MAC Address

  Summary:
    Structure to hold a MAC address.

  Description:
    The MAC address consist of a buffer and a valid flag.

  Remarks:
    None.

*/

typedef struct _WDRV_WINC_MAC_ADDR
{
    /* MAC address, must be WDRV_WINC_MAC_ADDR_LEN characters long. */
    uint8_t addr[WDRV_WINC_MAC_ADDR_LEN];

    /* Is the address valid? */
    bool valid;
} WDRV_WINC_MAC_ADDR;

// *****************************************************************************
/*  Association Handle

  Summary:
    A handle representing an association instance.

  Description:
    An association handle references a single association instance between AP and STA.

  Remarks:
    None.

*/

typedef uintptr_t WDRV_WINC_ASSOC_HANDLE;

// *****************************************************************************
/* Invalid Association Handle

 Summary:
    Invalid association handle.

 Description:
    Defines a value for an association handle which isn't yet valid.

 Remarks:
    None.
*/

#define WDRV_WINC_ASSOC_HANDLE_INVALID  (((WDRV_WINC_ASSOC_HANDLE) -1))

// *****************************************************************************
/*  Connection Notify Callback

  Summary:
    Callback to notify the user of a change in connection state.

  Description:
    When the connection state changes this callback enable the driver to signal
      the user about that event and reason.

  Parameters:
    handle          - Client handle obtained by a call to WDRV_WINC_Open.
    assocHandle     - Association handle.
    currentState    - Current connection state.
    errorCode       - Error code.

  Returns:
    None.

  Remarks:
    None.

*/

typedef void (*WDRV_WINC_BSSCON_NOTIFY_CALLBACK)
(
    DRV_HANDLE handle,
    WDRV_WINC_ASSOC_HANDLE assocHandle,
    WDRV_WINC_CONN_STATE currentState,
    WDRV_WINC_CONN_ERROR errorCode
);

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver Common Routines
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    void WDRV_MSDelay(uint32_t ms)

  Summary:
    Performs a delay specified in milli-seconds.

  Description:
    Will block for the number of milli-seconds specified.

  Precondition:
    None.

  Parameters:
    ms - Number of milli-seconds to block.

  Returns:
    None.

  Remarks:
    None.

*/

void WDRV_MSDelay(uint32_t ms);

// DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
// DOM-IGNORE-END

#endif /* _WDRV_WINC_COMMON_H */
