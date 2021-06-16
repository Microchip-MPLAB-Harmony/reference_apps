/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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
// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "wdrv_winc.h"
#include "tcpip/src/tcpip_manager_control.h"
extern void LEDinit(void);
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

/* TODO: Set Wireless AP Info below */
#if 1
#define WLAN_SSID           "MCHPSoftAP" /* WINC1500's SSID */
#define WLAN_CHANNEL        1 /* WINC1500's Working Channel e.g. 1, 6, 11 or WDRV_WINC_ALL_CHANNELS*/    
#define WLAN_AUTH           WDRV_WINC_AUTH_TYPE_OPEN// WDRV_WINC_AUTH_TYPE_WPA_PSK /* WINC1500's Security, e.g. WDRV_WINC_AUTH_TYPE_OPEN, WDRV_WINC_AUTH_TYPE_WPA_PSK or WDRV_WINC_AUTH_TYPE_WEP */
#define WLAN_WEP_KEY        "1234567890" /* Key for WEP Security */
#define WLAN_WEP_KEY_INDEX  1 /* Key Index for WEP Security */
#define WLAN_WPA_PASSPHRASE "1234567890" /* target AP's passphrase */
#endif

#if 0
#define WDRV_DEFAULT_NETWORK_TYPE WDRV_NETWORK_TYPE_SOFT_AP
#define WLAN_CHANNEL WDRV_WINC_ALL_CHANNELS
#define WLAN_SSID "MCHPSoftAP"

#define WLAN_AUTH WDRV_WINC_AUTH_TYPE_OPEN
#define WLAN_WEP_KEY        "1234567890" /* Key for WEP Security */
#define WLAN_WEP_KEY_INDEX  1 /* Key Index for WEP Security */
#define WLAN_WPA_PASSPHRASE "1234567890" /* target AP's passphrase */
#endif
// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

static DRV_HANDLE wdrvHandle;
// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

APP_LED_STATE LEDstate = APP_LED_STATE_OFF;

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************
static void _APP_ConnectNotifyCallback(DRV_HANDLE handle, WDRV_WINC_ASSOC_HANDLE assocHandle, WDRV_WINC_CONN_STATE currentState, WDRV_WINC_CONN_ERROR errorCode)
{
    if (WDRV_WINC_CONN_STATE_CONNECTED == currentState)
    {
        SYS_CONSOLE_PRINT("\r\nAP Connected\r\n");
    }
    else if (WDRV_WINC_CONN_STATE_DISCONNECTED == currentState)
    {
        SYS_CONSOLE_PRINT("\r\nAP Disconnected\r\n");
    }
}
/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    
    /* Place the application state machine in its initial state. */
    appData.state = APP_STATE_INIT;         
    
    LEDinit();
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */


void APP_Tasks ( void )
{
  SYS_STATUS          tcpipStat;
    TCPIP_NET_HANDLE    netH;
    int                 nNets;
    static IPV4_ADDR    dwLastIP[2] = { {-1}, {-1} };
    IPV4_ADDR           ipAddr;
    int                 i;
    const char          *netName, *netBiosName;
    static TCPIP_NET_HANDLE netHandleWiFi = NULL;

    switch(appData.state)
    {
         case APP_STATE_INIT:
        {
            if (SYS_STATUS_READY == WDRV_WINC_Status(sysObj.drvWifiWinc))
            {
                appData.state = APP_STATE_WDRV_INIT_READY;
            }
            break;
        }

        case APP_STATE_WDRV_INIT_READY:
        {
            wdrvHandle = WDRV_WINC_Open(0, 0);

            if (DRV_HANDLE_INVALID != wdrvHandle)
            {
                WDRV_WINC_AUTH_CONTEXT authCtx;
                WDRV_WINC_BSS_CONTEXT  bssCtx;

                /* Reset the internal BSS context */
                WDRV_WINC_BSSCtxSetDefaults(&bssCtx);

                /* Prepare the BSS context with desired AP's parameters */
                WDRV_WINC_BSSCtxSetChannel(&bssCtx, WLAN_CHANNEL);
                WDRV_WINC_BSSCtxSetSSID(&bssCtx, (uint8_t*)WLAN_SSID, strlen(WLAN_SSID));

                /* Reset the internal Auth context */
                WDRV_WINC_AuthCtxSetDefaults(&authCtx);

                /* Prepare the Auth context with desired AP's Security settings */
                if (WDRV_WINC_AUTH_TYPE_OPEN == WLAN_AUTH)
                {
                    WDRV_WINC_AuthCtxSetOpen(&authCtx);
                }
                else if (WDRV_WINC_AUTH_TYPE_WPA_PSK == WLAN_AUTH)
                {
                    WDRV_WINC_AuthCtxSetWPA(&authCtx, (uint8_t*)WLAN_WPA_PASSPHRASE, strlen(WLAN_WPA_PASSPHRASE));
                }
                else if (WDRV_WINC_AUTH_TYPE_WEP == WLAN_AUTH)
                {
                    WDRV_WINC_AuthCtxSetWEP(&authCtx, WLAN_WEP_KEY_INDEX, (uint8_t*)WLAN_WEP_KEY, strlen(WLAN_WEP_KEY));
                }
                else
                {
                    // other type not considered for this demo. default to open.
                    WDRV_WINC_AuthCtxSetOpen(&authCtx);
                }

                if (WDRV_WINC_STATUS_OK == WDRV_WINC_APStart(wdrvHandle, &bssCtx, &authCtx, NULL,&_APP_ConnectNotifyCallback))
                {
                    appData.state = APP_MOUNT_DISK;
                }
            }
            break;
        }
        case APP_MOUNT_DISK:
            if(SYS_FS_Mount(APP_SYS_FS_NVM_VOL, APP_SYS_FS_MOUNT_POINT, APP_SYS_FS_TYPE, 0, NULL) == 0)
            {
                SYS_CONSOLE_PRINT("SYS_Initialize: The %s File System is mounted\r\n", APP_SYS_FS_TYPE_STRING);
                appData.state = APP_TCPIP_WAIT_INIT;
            }
            break;

        case APP_TCPIP_WAIT_INIT:
            tcpipStat = TCPIP_STACK_Status(sysObj.tcpip);
            if(tcpipStat < 0)
            {   // some error occurred
                SYS_CONSOLE_MESSAGE("APP: TCP/IP stack initialization failed!\r\n");
                appData.state = APP_TCPIP_ERROR;
            }
            else if(tcpipStat == SYS_STATUS_READY)
            {
                // now that the stack is ready we can check the
                // available interfaces and register
                // a Bonjour service
    
                netHandleWiFi = TCPIP_STACK_NetHandleGet("WINC");
    
                TCPIP_DHCP_Disable(netHandleWiFi); // must stop DHCP client first
                TCPIP_DHCPS_Enable(netHandleWiFi); // start DHCP server
    

                nNets = TCPIP_STACK_NumberOfNetworksGet();

                for(i = 0; i < nNets; i++)
                {
                    netH = TCPIP_STACK_IndexToNet(i);
                    netName = TCPIP_STACK_NetNameGet(netH);
                    netBiosName = TCPIP_STACK_NetBIOSName(netH);

#if defined(TCPIP_STACK_USE_NBNS)
                  //  SYS_CONSOLE_PRINT("    Interface %s on host %s - NBNS enabled\r\n", netName, netBiosName);
#else
                    SYS_CONSOLE_PRINT("    Interface %s on host %s - NBNS disabled\r\n", netName, netBiosName);
#endif // defined(TCPIP_STACK_USE_NBNS)
                    (void)netName;          // avoid compiler warning 
                    (void)netBiosName;      // if SYS_CONSOLE_PRINT is null macro

#if defined(TCPIP_STACK_USE_ZEROCONF_MDNS_SD)
                    // base name of the service Must not exceed 16 bytes long
                    // the last digit will be incremented by interface
                    char mDNSServiceName[] = "MyWebServiceNameX ";

                    mDNSServiceName[sizeof(mDNSServiceName) - 2] = '1' + i;
                    TCPIP_MDNS_ServiceRegister(netH
                            , mDNSServiceName                     // name of the service
                            ,"_http._tcp.local"                   // type of the service
                            ,80                                   // TCP or UDP port, at which this service is available
                            ,((const uint8_t *)"path=/index.htm") // TXT info
                            ,1                                    // auto rename the service when if needed
                            ,NULL                                 // no callback function
                            ,NULL);                               // no application context
#endif // defined(TCPIP_STACK_USE_ZEROCONF_MDNS_SD)
                }

                appData.state = APP_TCPIP_TRANSACT;
            }

            break;

        case APP_TCPIP_TRANSACT:
            // if the IP address of an interface has changed
            // display the new value on the system console
            nNets = TCPIP_STACK_NumberOfNetworksGet();

            for(i = 0; i < nNets; i++)
            {
                netH = TCPIP_STACK_IndexToNet(i);
                ipAddr.Val = TCPIP_STACK_NetAddress(netH);
                if(dwLastIP[i].Val != ipAddr.Val)
                {
                    dwLastIP[i].Val = ipAddr.Val;
                    
                    SYS_CONSOLE_PRINT("%s IP Address: %d.%d.%d.%d \r\n",
                            TCPIP_STACK_NetNameGet(netH),
                            ipAddr.v[0], ipAddr.v[1], ipAddr.v[2], ipAddr.v[3]);
                }
            }

            break;

        default:
            break;
    }    
}


/*******************************************************************************
 End of File
 */
