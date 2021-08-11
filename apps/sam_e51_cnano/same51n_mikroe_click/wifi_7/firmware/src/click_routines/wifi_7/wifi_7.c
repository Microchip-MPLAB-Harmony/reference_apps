/*******************************************************************************
  wifi 7 source file

  Company:
    Microchip Technology Inc.

  File Name:
    wifi_7.c

  Summary:
  This file contains the "wifi 7" function 

  Description:
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
    (c) 2021 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/
// DOM-IGNORE-END
#include "wifi_7.h"
#include "wdrv_winc_client_api.h"

extern APP_DATA appData;

typedef enum
{
    /* Example's state machine's initial state. */
    WIFI7_STATE_INIT=0,
    WIFI7_STATE_SCANNING,
    WIFI7_STATE_SCAN_GET_RESULTS,
    WIFI7_STATE_SCAN_DONE,
    WIFI7_STATE_CONNECTING,
    WIFI7_STATE_CONNECTED,
    WIFI7_STATE_DISCONNECTED,
    WIFI7_STATE_ERROR,
} WIFI7_STATES;

static WIFI7_STATES state;
static bool foundBSS;

DRV_HANDLE wdrvHandle;

bool WIFI7_Initialize(void)
{
    bool status = false;
    
    if (SYS_STATUS_READY == WDRV_WINC_Status(sysObj.drvWifiWinc))
    {
            wdrvHandle = WDRV_WINC_Open(0, 0);

            if (DRV_HANDLE_INVALID != wdrvHandle)
            {
                state = WIFI7_STATE_INIT;
                return status;
            }
    }
    return status;

}

static void WIFI7_DHCPAddressEventCallback(DRV_HANDLE handle, uint32_t ipAddress)
{
    char s[20];

    SYS_CONSOLE_Print(appData.consoleHandle, "IP address is %s\r\n", inet_ntop(AF_INET, &ipAddress, s, sizeof(s)));
}

static void WIFI7_ExampleConnectNotifyCallback(DRV_HANDLE handle, WDRV_WINC_ASSOC_HANDLE assocHandle, WDRV_WINC_CONN_STATE currentState, WDRV_WINC_CONN_ERROR errorCode)
{
    if (WDRV_WINC_CONN_STATE_CONNECTED == currentState)
    {
        /* When connected reset the ICMP echo request counter and state. */
        SYS_CONSOLE_Print(appData.consoleHandle, "Connected\r\n");

        state = WIFI7_STATE_CONNECTED;
    }
    else if (WDRV_WINC_CONN_STATE_DISCONNECTED == currentState)
    {
        SYS_CONSOLE_Print(appData.consoleHandle, "Disconnected\r\n");

        state = WIFI7_STATE_DISCONNECTED;
    }
}

void WIFI7_Tasks()
{
    WDRV_WINC_STATUS status;

    switch (state)
    {
        case WIFI7_STATE_INIT:
        {
            /* Enable use of DHCP for network configuration, DHCP is the default
             but this also registers the callback for notifications. */

            WDRV_WINC_IPUseDHCPSet(wdrvHandle, &WIFI7_DHCPAddressEventCallback);

            /* Start a BSS find operation on all channels. */

            if (WDRV_WINC_STATUS_OK == WDRV_WINC_BSSFindFirst(wdrvHandle, WDRV_WINC_ALL_CHANNELS, true, NULL, NULL))
            {
                state = WIFI7_STATE_SCANNING;
                foundBSS = false;
            }
            break;
        }

        case WIFI7_STATE_SCANNING:
        {
            /* Wait for BSS find operation to complete, then report the number
             of results found. */

            if (false == WDRV_WINC_BSSFindInProgress(wdrvHandle))
            {
                SYS_CONSOLE_Print(appData.consoleHandle, "Scan complete, %d AP(s) found\r\n", WDRV_WINC_BSSFindGetNumBSSResults(wdrvHandle));
                state = WIFI7_STATE_SCAN_GET_RESULTS;
            }
            break;
        }

        case WIFI7_STATE_SCAN_GET_RESULTS:
        {
            WDRV_WINC_BSS_INFO BSSInfo;

            /* Request the current BSS find results. */

            if (WDRV_WINC_STATUS_OK == WDRV_WINC_BSSFindGetInfo(wdrvHandle, &BSSInfo))
            {
                SYS_CONSOLE_Print(appData.consoleHandle, "AP found: RSSI: %d %s\r\n", BSSInfo.rssi, BSSInfo.ctx.ssid.name);

                /* Check if this SSID matches the search target SSID. */

                if (((sizeof(WLAN_SSID)-1) == BSSInfo.ctx.ssid.length) && (0 == memcmp(BSSInfo.ctx.ssid.name, WLAN_SSID, BSSInfo.ctx.ssid.length)))
                {
                    foundBSS = true;
                }

                /* Request the next set of BSS find results. */

                status = WDRV_WINC_BSSFindNext(wdrvHandle, NULL);

                if (WDRV_WINC_STATUS_BSS_FIND_END == status)
                {
                    /* If there are no more results available check if the target
                     SSID has been found. */

                    if (true == foundBSS)
                    {
                        SYS_CONSOLE_Print(appData.consoleHandle, "Target AP found, trying to connect\r\n");
                        state = WIFI7_STATE_SCAN_DONE;
                    }
                    else
                    {
                        SYS_CONSOLE_Print(appData.consoleHandle, "Target AP not found\r\n");
                        state = WIFI7_STATE_ERROR;
                    }
                }
                else if ((WDRV_WINC_STATUS_NOT_OPEN == status) || (WDRV_WINC_STATUS_INVALID_ARG == status))
                {
                    /* An error occurred requesting results. */

                    state = WIFI7_STATE_ERROR;
                }
            }
            break;
        }

        case WIFI7_STATE_SCAN_DONE:
        {
            WDRV_WINC_AUTH_CONTEXT authCtx;
            WDRV_WINC_BSS_CONTEXT  bssCtx;

            /* Preset the error state incase any following operations fail. */

            state = WIFI7_STATE_ERROR;

            /* Initialize the BSS context to use default values. */

            if (WDRV_WINC_STATUS_OK != WDRV_WINC_BSSCtxSetDefaults(&bssCtx))
            {
                break;
            }

            /* Update BSS context with target SSID for connection. */

            if (WDRV_WINC_STATUS_OK != WDRV_WINC_BSSCtxSetSSID(&bssCtx, (uint8_t*)WLAN_SSID, strlen(WLAN_SSID)))
            {
                break;
            }

#if defined(WLAN_AUTH_OPEN)
            /* Initialize the authentication context for open mode. */

            if (WDRV_WINC_STATUS_OK != WDRV_WINC_AuthCtxSetOpen(&authCtx))
            {
                break;
            }
#elif defined(WLAN_AUTH_WPA_PSK)
            /* Initialize the authentication context for WPA. */

            if (WDRV_WINC_STATUS_OK != WDRV_WINC_AuthCtxSetWPA(&authCtx, (uint8_t*)WLAN_PSK, strlen(WLAN_PSK)))
            {
                break;
            }
#endif

            /* Connect to the target BSS with the chosen authentication. */

            if (WDRV_WINC_STATUS_OK == WDRV_WINC_BSSConnect(wdrvHandle, &bssCtx, &authCtx, &WIFI7_ExampleConnectNotifyCallback))
            {
                state = WIFI7_STATE_CONNECTING;
            }
            break;
        }

        case WIFI7_STATE_CONNECTING:
        {
            /* Wait for the BSS connect to trigger the callback and update
             the connection state. */
            break;
        }

        case WIFI7_STATE_CONNECTED:
        {
            /* Wait for the IP link to become active. */

            if (false == WDRV_WINC_IPLinkActive(wdrvHandle))
            {
                break;
            }
            break;
        }


        case WIFI7_STATE_DISCONNECTED:
        {
            /* If we become disconnected, trigger a reconnection. */

            if (WDRV_WINC_STATUS_OK == WDRV_WINC_BSSReconnect(wdrvHandle, &WIFI7_ExampleConnectNotifyCallback))
            {
                state = WIFI7_STATE_CONNECTING;
            }
            break;
        }

        case WIFI7_STATE_ERROR:
        {
            break;
        }

        default:
        {
            break;
        }
    }
}

// ------------------------------------------------------------------------- END

