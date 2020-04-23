/*******************************************************************************
  Company:
    Microchip Technology Inc.

  File Name:
    wdrv_winc_iwpriv.h

  Summary:
    IWPRIV interface to control WiFi driver.

  Description:
    Provides a basic and limited interface to the WINC MAC driver.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

#ifndef _WDRV_WINC_IWPRIV_H
#define _WDRV_WINC_IWPRIV_H

// DOM-IGNORE-BEGIN
#ifdef __cplusplus // Provide C++ Compatibility
    extern "C" {
#endif
// DOM-IGNORE-END

#define WDRV_NETWORK_TYPE_INFRASTRUCTURE            1
#define WDRV_NETWORK_TYPE_SOFT_AP                   4

#define WDRV_BSSID_LENGTH                           6
#define WDRV_MAX_SSID_LENGTH                        32

#define WDRV_MAX_SECURITY_KEY_LENGTH                64

#define WDRV_SECURITY_OPEN                          0
#define WDRV_SECURITY_WEP_40                        1
#define WDRV_SECURITY_WEP_104                       2
#define WDRV_SECURITY_WPA_AUTO_WITH_PASS_PHRASE     3

#define WDRV_APCONFIG_BIT_PRIVACY                   0x10
#define WDRV_APCONFIG_BIT_WPA                       0x40
#define WDRV_APCONFIG_BIT_WPA2                      0x80

/*******************************************************************************
  Summary:
    Contains data pertaining to WiFi scan results

  Description:
    WiFi Scan Results

    This structure contains the result of WiFi scan operation.

    apConfig Bit Mask
    <table>
    Bit 7       Bit 6       Bit 5       Bit 4       Bit 3       Bit 2       Bit 1       Bit 0
    -----       -----       -----       -----       -----       -----       -----       -----
    WPA2        WPA         Reserved    Privacy     Reserved    Reserved    Reserved    Reserved
    </table>

    <table>
    Privacy    0 : AP is open (no security) 1: AP using security, if neither WPA
                and WPA2 set then security is WEP.
    WPA        Only valid if Privacy is 1. 0: AP does not support WPA 1: AP supports WPA
    WPA2       Only valid if Privacy is 1. 0: AP does not support WPA2 1: AP supports WPA2
    </table>
*/
typedef struct
{
    /* Network BSSID value */
    uint8_t     bssid[WDRV_BSSID_LENGTH];

    /*  Network SSID value */
    uint8_t     ssid[WDRV_MAX_SSID_LENGTH];

    /* Access Point configuration (see description) */
    uint8_t     apConfig;

    /* Signal strength of received frame beacon or probe response. */
    int8_t      rssi;

    /* WDRV_NETWORK_TYPE_INFRASTRUCTURE */
    uint8_t     bssType;

    /* Channel number */
    uint8_t     channel;

    /* Number of valid characters in SSID */
    uint8_t     ssidLen;
} WDRV_SCAN_RESULT;

// *****************************************************************************
/*  WiFi Configuration Structure

  Summary:
    WiFi configuration structure.

  Description:
    Contains the network type, SSID and authentication parameters on one
      structure for easy storage.

  Remarks:
    None.
*/
typedef struct
{
    /* Network type Soft-AP or Infrastructure Station. */
    uint8_t networkType;

    /* SSID */
    uint8_t ssid[WDRV_MAX_SSID_LENGTH + 1];

    /* Length of SSID */
    uint8_t ssidLen;

    /* Security mode, Open, WEP, WPA */
    uint8_t securityMode;

    /* Security key / pass phrase for WEP or WPA */
    uint8_t securityKey[WDRV_MAX_SECURITY_KEY_LENGTH];

    /* Length of security key. */
    uint8_t securityKeyLen;
} WDRV_CONFIG;

typedef struct
{
    uint8_t deviceType;
    uint8_t romVersion;
    uint8_t patchVersion;
} WDRV_DEVICE_INFO;

typedef enum
{
    WDRV_ATWINC_DEVICE = 4,
} WDRV_DEVICE_TYPE;

typedef enum
{
    IWPRIV_ERROR = -1,
    IWPRIV_READY,
    IWPRIV_IN_PROGRESS
} IWPRIV_STATUS;

typedef enum
{
    IWPRIV_SCAN_SUCCESSFUL,
    IWPRIV_SCAN_IDLE,
    IWPRIV_SCAN_IN_PROGRESS,
    IWPRIV_SCAN_NO_AP_FOUND
} IWPRIV_SCAN_STATUS;

typedef enum
{
    IWPRIV_CONNECTION_FAILED = -1,
    IWPRIV_CONNECTION_SUCCESSFUL,
    IWPRIV_CONNECTION_IDLE,
    IWPRIV_CONNECTION_IN_PROGRESS,
    IWPRIV_CONNECTION_REESTABLISHED
} IWPRIV_CONN_STATUS;

typedef struct
{
    bool prescanAllowed;
    bool prescanFinished;
    IWPRIV_SCAN_STATUS scanStatus;
    uint8_t numberOfResults;
    uint8_t index;
    WDRV_SCAN_RESULT *result;
} IWPRIV_PARAM_SCAN;

typedef struct
{
    uint8_t *ssid;
    uint8_t ssidLen;
} IWPRIV_PARAM_SSID;

typedef struct {
    WDRV_CONFIG *config;
} IWPRIV_PARAM_CONFIG;

typedef struct
{
    uint8_t type;
} IWPRIV_PARAM_NETWORKTYPE;

typedef struct
{
    bool initConnAllowed;
    IWPRIV_CONN_STATUS status;
} IWPRIV_PARAM_CONNECT;

typedef struct
{
    uint8_t *addr; // it usually points to a MAC address, which is an array of 6 uint8_t elements
    bool updated;
} IWPRIV_PARAM_CLIENTINFO;

typedef struct
{
    void *info;
} IWPRIV_PARAM_DEVICEINFO;

typedef struct
{
    bool isOpen;
} IWPRIV_PARAM_DRIVERSTATUS;

typedef struct
{
    bool isServer;
} IWPRIV_PARAM_OPERATIONMODE;

typedef struct
{
    bool enabled;
} IWPRIV_PARAM_POWERSAVE;

typedef struct
{
    uint8_t channel;
} IWPRIV_PARAM_OPCHAN;

typedef struct
{
    void (*debug_cb)(const char*, ...);
} IWPRIV_PARAM_DEBUG_FUNC;

typedef union
{
    IWPRIV_PARAM_SCAN scan;
    IWPRIV_PARAM_CONFIG cfg;
    IWPRIV_PARAM_SSID ssid;
    IWPRIV_PARAM_NETWORKTYPE netType;
    IWPRIV_PARAM_CONNECT conn;
    IWPRIV_PARAM_CLIENTINFO clientInfo;
    IWPRIV_PARAM_DEVICEINFO devInfo;
    IWPRIV_PARAM_DRIVERSTATUS driverStatus;
    IWPRIV_PARAM_OPERATIONMODE opMode;
} IWPRIV_GET_PARAM;

typedef union
{
    IWPRIV_PARAM_SCAN scan;
    IWPRIV_PARAM_CONFIG cfg;
    IWPRIV_PARAM_SSID ssid;
    IWPRIV_PARAM_NETWORKTYPE netType;
    IWPRIV_PARAM_CONNECT conn;
    IWPRIV_PARAM_POWERSAVE powerSave;
    IWPRIV_PARAM_OPCHAN opChan;
    IWPRIV_PARAM_DEBUG_FUNC debugFunc;
} IWPRIV_SET_PARAM;

typedef union
{
    /* So far IWPRIV_EXECUTE command doesn't have any parameter. */
} IWPRIV_EXECUTE_PARAM;

typedef enum
{
    PRESCAN_OPTION_GET,
    PRESCAN_OPTION_SET,
    PRESCAN_ISFINISHED_GET,
    SCAN_START,
    SCANSTATUS_GET,
    SCANRESULT_GET,
    SCANRESULTS_COUNT_GET,
    CONFIG_GET,
    CONFIG_SET,
    SSID_GET,
    SSID_SET,
    NETWORKTYPE_GET,
    NETWORKTYPE_SET,
    CONNSTATUS_GET,
    CLIENTINFO_GET,
    DEVICEINFO_GET,
    DRVSTATUS_GET,
    OPERATIONMODE_GET,
    INITCONN_OPTION_SET,
    POWERSAVE_SET,
    OPCHAN_SET,
    DEBUG_FUNC_SET
} IWPRIV_CMD;

#define PRESCAN_START SCAN_START

void IWPRIV_GetParam(TCPIP_STACK_MODULE macId, IWPRIV_CMD cmd, IWPRIV_GET_PARAM *param);
void IWPRIV_SetParam(TCPIP_STACK_MODULE macId, IWPRIV_CMD cmd, IWPRIV_SET_PARAM *param);
void IWPRIV_Execute(TCPIP_STACK_MODULE macId, IWPRIV_CMD cmd, IWPRIV_EXECUTE_PARAM *param);

#define iwpriv_get(cmd, params)     IWPRIV_GetParam(TCPIP_MODULE_MAC_WINC, cmd, params)
#define iwpriv_set(cmd, params)     IWPRIV_SetParam(TCPIP_MODULE_MAC_WINC, cmd, params)
#define iwpriv_execute(cmd, params) IWPRIV_Execute(TCPIP_MODULE_MAC_WINC, cmd, params)

// DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
// DOM-IGNORE-END

#endif /* _WDRV_WINC_IWPRIV_H */
