/*******************************************************************************
  WINC Private Configuration Support

  File Name:
    wdrv_winc_iwpriv.c

  Summary:
    Configure optional (private) parameters of WINC driver.

  Description:
    Functions in this module support the connection process for the
    WINC.
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

#include <stdint.h>
#include <stdbool.h>

#include "wdrv_winc.h"
#include "wdrv_winc_iwpriv.h"
#include "wdrv_winc_stack_drv.h"
#include "tcpip/src/tcpip_manager_control.h"

#define IWPRIV_MAX_NUM_SCAN_RESULTS     16

static bool             iwprivScanAllowed = false;
static bool             iwprivScanInProgress = false;
static bool             iwprivScanComplete = false;
static uint8_t          iwprivScanNumResults = 0;
static WDRV_SCAN_RESULT iwprivScanResults[IWPRIV_MAX_NUM_SCAN_RESULTS];

static OSAL_SEM_HANDLE_TYPE iwprivScanResultsSem = NULL;
static bool iwprivScanResultsSemValid = false;

static void _IWPRIV_SEM_Pend(void)
{
    if (true == iwprivScanResultsSemValid)
    {
        OSAL_SEM_Pend(&iwprivScanResultsSem, OSAL_WAIT_FOREVER);
    }
}

static void _IWPRIV_SEM_Post(void)
{
    if (true == iwprivScanResultsSemValid)
    {
        OSAL_SEM_Post(&iwprivScanResultsSem);
    }
}

static bool _IWPRIV_FindBSSNotifyCallback(DRV_HANDLE handle, uint8_t index,
                                uint8_t ofTotal, WDRV_WINC_BSS_INFO *pBSSInfo)
{
    _IWPRIV_SEM_Pend();

    if (NULL != pBSSInfo)
    {
        WDRV_DBG_TRACE_PRINT("_IWPRIV_FindBSSNotifyCallback (%d of %d): %s\r\n",
                                            index, ofTotal, pBSSInfo->ssid.name);

        if ((0 != index) && (index < IWPRIV_MAX_NUM_SCAN_RESULTS))
        {
            WDRV_SCAN_RESULT *pScanResult = &iwprivScanResults[index-1];

            memcpy(pScanResult->ssid, pBSSInfo->ssid.name, pBSSInfo->ssid.length);
            pScanResult->ssidLen = pBSSInfo->ssid.length;
            memcpy(pScanResult->bssid, pBSSInfo->bssid, WDRV_BSSID_LENGTH);
            pScanResult->rssi = pBSSInfo->rssi;
            pScanResult->channel = pBSSInfo->channel;
            pScanResult->bssType = WDRV_NETWORK_TYPE_INFRASTRUCTURE;

            pScanResult->apConfig = 0;

            if (pBSSInfo->authType != WDRV_WINC_AUTH_TYPE_OPEN)
            {
                pScanResult->apConfig |= WDRV_APCONFIG_BIT_PRIVACY;
            }

            if (pBSSInfo->authType == WDRV_WINC_AUTH_TYPE_WPA_PSK)
            {
                pScanResult->apConfig |= WDRV_APCONFIG_BIT_WPA;
                pScanResult->apConfig |= WDRV_APCONFIG_BIT_WPA2;
            }
        }
    }

    if (ofTotal > IWPRIV_MAX_NUM_SCAN_RESULTS)
    {
        iwprivScanNumResults = IWPRIV_MAX_NUM_SCAN_RESULTS;
    }
    else
    {
        iwprivScanNumResults = ofTotal;
    }

    if (index == ofTotal)
    {
        iwprivScanComplete = true;
    }

    _IWPRIV_SEM_Post();

    return true;
}

static WDRV_WINC_OP_MODE _IWPRIV_NetworkTypeToOpMode(uint8_t networkType)
{
    if (WDRV_NETWORK_TYPE_SOFT_AP == networkType)
    {
        return WDRV_WINC_OP_MODE_AP;
    }
    else if (WDRV_NETWORK_TYPE_INFRASTRUCTURE == networkType)
    {
        return WDRV_WINC_OP_MODE_STA;
    }

    return WDRV_WINC_OP_MODE_UNKNOWN;
}

static uint8_t _IWPRIV_OpModeToNetworkType(WDRV_WINC_OP_MODE opMode)
{
    if (WDRV_WINC_OP_MODE_AP == opMode)
    {
        return WDRV_NETWORK_TYPE_SOFT_AP;
    }
    else if (WDRV_WINC_OP_MODE_STA == opMode)
    {
        return WDRV_NETWORK_TYPE_INFRASTRUCTURE;
    }

    return 0xff;
}

void IWPRIV_GetParam(TCPIP_STACK_MODULE macId, IWPRIV_CMD cmd, IWPRIV_GET_PARAM *param)
{
    WDRV_WINC_BSS_CONTEXT BSSCtx;
    WDRV_WINC_AUTH_CONTEXT authCtx;

    TCPIP_NET_IF *pNetIf = TCPIP_STACK_MACIdToNet(macId);

    if (NULL == pNetIf)
    {
        return;
    }

    if (false == iwprivScanResultsSemValid)
    {
        iwprivScanResultsSemValid = (OSAL_SEM_Create(&iwprivScanResultsSem,
                                OSAL_SEM_TYPE_BINARY, 1, 1) == OSAL_RESULT_TRUE);
    }

    switch (cmd)
    {
        case PRESCAN_OPTION_GET:
        {
            param->scan.prescanAllowed = iwprivScanAllowed;
            break;
        }

        case PRESCAN_ISFINISHED_GET:
        {
            _IWPRIV_SEM_Pend();

            if ((true == iwprivScanInProgress) && (true == iwprivScanComplete))
            {
                param->scan.prescanFinished = true;
            }
            else
            {
                param->scan.prescanFinished = false;
            }

            _IWPRIV_SEM_Post();
            break;
        }

        case SCANSTATUS_GET:
        {
            if (true == iwprivScanInProgress)
            {
                _IWPRIV_SEM_Pend();

                if (true == iwprivScanComplete)
                {
                    if (0 == iwprivScanNumResults)
                    {
                        param->scan.scanStatus = IWPRIV_SCAN_NO_AP_FOUND;
                    }
                    else
                    {
                        param->scan.scanStatus = IWPRIV_SCAN_SUCCESSFUL;
                    }
                }
                else
                {
                    param->scan.scanStatus = IWPRIV_SCAN_IN_PROGRESS;
                }

                _IWPRIV_SEM_Post();
            }
            else
            {
                param->scan.scanStatus = IWPRIV_SCAN_IDLE;
            }

            break;
        }

        case SCANRESULT_GET:
        {
            if (NULL != param->scan.result)
            {
                memset(param->scan.result, 0, sizeof(WDRV_SCAN_RESULT));
            }

            _IWPRIV_SEM_Pend();

            if (param->scan.index < iwprivScanNumResults)
            {
                memcpy(param->scan.result, &iwprivScanResults[param->scan.index],
                                                        sizeof(WDRV_SCAN_RESULT));
            }

            _IWPRIV_SEM_Post();
            break;
        }

        case SCANRESULTS_COUNT_GET:
        {
            _IWPRIV_SEM_Pend();

            param->scan.numberOfResults = iwprivScanNumResults;

            _IWPRIV_SEM_Post();
            break;
        }

        case CONFIG_GET:
        {
            WDRV_WINC_MACBSSCtxGet(pNetIf->hIfMac, &BSSCtx);

            memcpy(param->cfg.config->ssid, BSSCtx.ssid.name, BSSCtx.ssid.length);
            param->cfg.config->ssid[BSSCtx.ssid.length] = '\0';
            param->cfg.config->ssidLen = BSSCtx.ssid.length;

            param->cfg.config->networkType = _IWPRIV_OpModeToNetworkType(
                            WDRV_WINC_MACOperatingModeGet(pNetIf->hIfMac) );

            WDRV_WINC_MACAuthCtxGet(pNetIf->hIfMac, &authCtx);

            switch (authCtx.authType)
            {
                case WDRV_WINC_AUTH_TYPE_OPEN:
                {
                    param->cfg.config->securityMode = WDRV_SECURITY_OPEN;
                    break;
                }

                case WDRV_WINC_AUTH_TYPE_WPA_PSK:
                {
                    param->cfg.config->securityMode = WDRV_SECURITY_WPA_AUTO_WITH_PASS_PHRASE;
                    break;
                }

                default:
                {
                    param->cfg.config->securityMode = 0xff;
                    break;
                }
            }

            break;
        }

        case SSID_GET:
        {
            WDRV_WINC_MACBSSCtxGet(pNetIf->hIfMac, &BSSCtx);

            memcpy(param->ssid.ssid, BSSCtx.ssid.name, BSSCtx.ssid.length);
            param->ssid.ssid[BSSCtx.ssid.length] = '\0';
            param->ssid.ssidLen = BSSCtx.ssid.length;
            break;
        }

        case NETWORKTYPE_GET:
        {
            param->netType.type = _IWPRIV_OpModeToNetworkType(
                            WDRV_WINC_MACOperatingModeGet(pNetIf->hIfMac) );
            break;
        }

        case CONNSTATUS_GET:
        {
            if (WDRV_WINC_MAC_CONN_STATE_CONNECTED == WDRV_WINC_MACConnectStateGet(pNetIf->hIfMac))
            {
                param->conn.status = IWPRIV_CONNECTION_SUCCESSFUL;
            }
            else
            {
                param->conn.status = IWPRIV_CONNECTION_IDLE;
            }
            break;
        }

        case CLIENTINFO_GET:
        {
            param->clientInfo.updated = false;
            break;
        }

        case DEVICEINFO_GET:
        {
            if (NULL != param->devInfo.info)
                ((WDRV_DEVICE_INFO *)param->devInfo.info)->deviceType = WDRV_ATWINC_DEVICE;
            break;
        }

        case DRVSTATUS_GET:
        {
            if (WDRV_WINC_MAC_CONN_STATE_CLOSED == WDRV_WINC_MACConnectStateGet(pNetIf->hIfMac))
            {
                param->driverStatus.isOpen = false;
            }
            else
            {
                param->driverStatus.isOpen = true;
            }
            break;
        }

        case OPERATIONMODE_GET:
        {
            WDRV_WINC_OP_MODE opMode = WDRV_WINC_MACOperatingModeGet(pNetIf->hIfMac);

            if (WDRV_WINC_OP_MODE_AP == opMode)
            {
                param->opMode.isServer = true;
            }
            else
            {
                param->opMode.isServer = false;
            }
            break;
        }

        default:
        {
            WDRV_DBG_TRACE_PRINT("iwpriv_get: %d\r\n", cmd);
            break;
        }
    }
}

void IWPRIV_SetParam(TCPIP_STACK_MODULE macId, IWPRIV_CMD cmd, IWPRIV_SET_PARAM *param)
{
    WDRV_WINC_BSS_CONTEXT BSSCtx;
    WDRV_WINC_AUTH_CONTEXT authCtx;

    TCPIP_NET_IF *pNetIf = TCPIP_STACK_MACIdToNet(macId);

    if (NULL == pNetIf)
    {
        return;
    }

    if (false == iwprivScanResultsSemValid)
    {
        iwprivScanResultsSemValid = (OSAL_SEM_Create(&iwprivScanResultsSem,
                                OSAL_SEM_TYPE_BINARY, 1, 1) == OSAL_RESULT_TRUE);
    }

    switch (cmd)
    {
        case PRESCAN_OPTION_SET:
        {
            iwprivScanAllowed = param->scan.prescanAllowed;
            break;
        }

        case SSID_SET:
        {
            WDRV_WINC_MACBSSCtxGet(pNetIf->hIfMac, &BSSCtx);
            WDRV_WINC_BSSCtxSetSSID(&BSSCtx, param->ssid.ssid, param->ssid.ssidLen);
            WDRV_WINC_MACBSSCtxSet(pNetIf->hIfMac, &BSSCtx);
            break;
        }

        case CONFIG_SET:
        {
            WDRV_WINC_MACBSSCtxGet(pNetIf->hIfMac, &BSSCtx);
            WDRV_WINC_BSSCtxSetDefaults(&BSSCtx);
            WDRV_WINC_BSSCtxSetSSID(&BSSCtx, param->cfg.config->ssid, param->cfg.config->ssidLen);
            WDRV_WINC_MACBSSCtxSet(pNetIf->hIfMac, &BSSCtx);

            WDRV_WINC_MACAuthCtxGet(pNetIf->hIfMac, &authCtx);

            switch (param->cfg.config->securityMode)
            {
                case WDRV_SECURITY_OPEN:
                {
                    WDRV_WINC_AuthCtxSetOpen(&authCtx);
                    break;
                }

                case WDRV_SECURITY_WPA_AUTO_WITH_PASS_PHRASE:
                {
                    WDRV_WINC_AuthCtxSetWPA(&authCtx,
                        param->cfg.config->securityKey, param->cfg.config->securityKeyLen);
                    break;
                }

                default:
                {
                    break;
                }
            }

            WDRV_WINC_MACAuthCtxSet(pNetIf->hIfMac, &authCtx);

            WDRV_WINC_MACOperatingModeSet(pNetIf->hIfMac,
                    _IWPRIV_NetworkTypeToOpMode(param->cfg.config->networkType));
            break;
        }

        case NETWORKTYPE_SET:
        {
            WDRV_WINC_MACOperatingModeSet(pNetIf->hIfMac,
                    _IWPRIV_NetworkTypeToOpMode(param->netType.type));
            break;
        }

        case INITCONN_OPTION_SET:
        {
            WDRV_WINC_MACAutoConnectSet(pNetIf->hIfMac, param->conn.initConnAllowed);
            break;
        }

        case POWERSAVE_SET:
        {
            if (true == param->powerSave.enabled)
            {
                WDRV_WINC_MACPowerSaveSetMode(pNetIf->hIfMac, WDRV_WINC_PS_MODE_AUTO_LOW_POWER);
                WDRV_WINC_MACPowerSaveSetBeaconInterval(pNetIf->hIfMac, 3);
            }
            else
            {
                WDRV_WINC_MACPowerSaveSetMode(pNetIf->hIfMac, WDRV_WINC_PS_MODE_OFF);
            }
            break;
        }

        case OPCHAN_SET:
        {
            WDRV_WINC_MACBSSCtxGet(pNetIf->hIfMac, &BSSCtx);
            WDRV_WINC_BSSCtxSetChannel(&BSSCtx, param->opChan.channel);
            WDRV_WINC_MACBSSCtxSet(pNetIf->hIfMac, &BSSCtx);
            break;
        }

        case DEBUG_FUNC_SET:
        {
            WDRV_WINC_DebugRegisterCallback(param->debugFunc.debug_cb);
            break;
        }

        default:
        {
            WDRV_DBG_TRACE_PRINT("iwpriv_set: %d\r\n", cmd);
            break;
        }
    }
}

void IWPRIV_Execute(TCPIP_STACK_MODULE macId, IWPRIV_CMD cmd, IWPRIV_EXECUTE_PARAM *param)
{
    TCPIP_NET_IF *pNetIf = TCPIP_STACK_MACIdToNet(TCPIP_MODULE_MAC_WINC);

    if (NULL == pNetIf)
    {
        return;
    }

    if (false == iwprivScanResultsSemValid)
    {
        iwprivScanResultsSemValid = (OSAL_SEM_Create(&iwprivScanResultsSem,
                                    OSAL_SEM_TYPE_BINARY, 1, 1) == OSAL_RESULT_TRUE);
    }

    switch (cmd)
    {
        case SCAN_START:
        {
            if ((true == iwprivScanAllowed) && (false == iwprivScanInProgress))
            {
                if (WDRV_WINC_STATUS_OK == WDRV_WINC_MACBSSFindFirst(
                        pNetIf->hIfMac, WDRV_WINC_ALL_CHANNELS, true, &_IWPRIV_FindBSSNotifyCallback))
                {
                    iwprivScanComplete   = false;
                    iwprivScanInProgress = true;
                }
            }
            break;
        }

        default:
        {
            WDRV_DBG_TRACE_PRINT("iwpriv_execute: %d\r\n", cmd);
            break;
        }
    }
}

// DOM-IGNORE-END
