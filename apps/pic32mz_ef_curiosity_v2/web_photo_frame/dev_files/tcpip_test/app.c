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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "system_config.h"
#include "system_definitions.h"
#include "bsp/bsp.h"
#include "user.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

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

APP_LED_STATE LEDstate = APP_LED_STATE_OFF;
// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/
void APP_FileHandler_SYS_FS_EventHandler(SYS_FS_EVENT event, void * eventData, uintptr_t context)
{
    static char sdCardMountName[32] = APP_SYS_FS_MOUNT_POINT;
    static char nvmMountName[32] = APP_SYS_FS_NVM_MOUNT_POINT;
    
    switch(event)
    {
        case SYS_FS_EVENT_MOUNT:
            if ( !memcmp((void*)eventData, (const void*)sdCardMountName, strlen((char*)sdCardMountName)) ) {
                SYS_CONSOLE_PRINT("SYS_Initialize: The %s File System is mounted from %s to %s\r\n", APP_SYS_FS_TYPE_STRING, APP_SYS_FS_SD_VOL, APP_SYS_FS_MOUNT_POINT);
                appData.sdCardMounted = true;
            }
			if ( !memcmp((void*)eventData, (const void*)nvmMountName, strlen((char*)nvmMountName)) ) {
                SYS_CONSOLE_PRINT("SYS_Initialize: The %s File System is mounted from %s to %s\r\n", APP_SYS_FS_NVM_TYPE_STRING, APP_SYS_FS_NVM_VOL, APP_SYS_FS_NVM_MOUNT_POINT);
                appData.nvmMounted = true;
            }
            if (appData.nvmMounted == true) {
                appData.state = APP_STATE_MEDIA_MOUNTED;    
            }
            break;
            
        case SYS_FS_EVENT_UNMOUNT:
            if ( !memcmp((void*)eventData, (const void*)sdCardMountName, strlen((char*)sdCardMountName)) ) {
                SYS_CONSOLE_PRINT("SYS_Initialize: The %s File System is unmounted\r\n", APP_SYS_FS_TYPE_STRING);
            }
			if ( !memcmp((void*)eventData, (const void*)nvmMountName, strlen((char*)nvmMountName)) ) {
                SYS_CONSOLE_PRINT("SYS_Initialize: The %s File System is mounted from %s to %s\r\n", APP_SYS_FS_NVM_TYPE_STRING, APP_SYS_FS_NVM_VOL, APP_SYS_FS_NVM_MOUNT_POINT);
            }
            break;
            
        default:
            break;
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */
void APP_Initialize ( void )
{
    /* Intialize the app state to wait for media attach. */
    appData.state = APP_STATE_MEDIA_UNMOUNTED;
    
    appData.httpServerInitialized = false;
    
    // add callback for mount and unmount of the sd card
    SYS_FS_EventHandlerSet(APP_FileHandler_SYS_FS_EventHandler, (uintptr_t)NULL);
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
    TCPIP_NET_HANDLE    netH = NULL;
    int                 nNets;
    static IPV4_ADDR    dwLastIP[2] = { {-1}, {-1} };
    IPV4_ADDR           ipAddr = {0};
    int                 i;
    const char          *netName, *netBiosName;
    static uint32_t     startTick = 0;
    
    switch(appData.state)
    {
        case APP_STATE_IDLE:
            if(SYS_TMR_TickCountGet() - startTick >= SYS_TMR_TickCounterFrequencyGet()/2ul)
            {
                LED1_Toggle();
                LED2_Toggle();
                LED3_Toggle();
                startTick = SYS_TMR_TickCountGet();
            }
            break;
        
        case APP_STATE_MEDIA_UNMOUNTED:

            appData.sdCardMounted = APP_CARD_UNMOUNT;

            LED1_On();
            LED2_Off();
            LED3_Off();
            
            break;

            
        case APP_STATE_MEDIA_MOUNTED:
            
            appData.sdCardMounted = APP_CARD_MOUNT;

            LED1_Off();
            LED2_On();
            LED3_Off();
            
            appData.sdCardMounted = APP_CARD_SCANNED;
                
            appData.state = APP_TCPIP_WAIT_INIT;
            
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

                nNets = TCPIP_STACK_NumberOfNetworksGet();

                for(i = 0; i < nNets; i++)
                {
                    netH = TCPIP_STACK_IndexToNet(i);
                    netName = TCPIP_STACK_NetNameGet(netH);
                    netBiosName = TCPIP_STACK_NetBIOSName(netH);

#if defined(TCPIP_STACK_USE_NBNS)
                    SYS_CONSOLE_PRINT("    Interface %s on host %s - NBNS enabled\r\n", netName, netBiosName);
#else
                    SYS_CONSOLE_PRINT("    Interface %s on host %s - NBNS disabled\r\n", netName, netBiosName);
#endif
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
#endif
                }

#if defined(TCPIP_STACK_USE_HTTP_NET_SERVER)
                if (appData.httpServerInitialized == false) {
                    // register the application HTTP processing
                    HTTP_APP_Initialize();
                    
                    appData.httpServerInitialized = true;
                }
#endif
                SYS_CONSOLE_MESSAGE(TCPIP_STACK_NetNameGet(netH));
                SYS_CONSOLE_MESSAGE(" IP Address: ");
                SYS_CONSOLE_PRINT("%d.%d.%d.%d \r\n", ipAddr.v[0], ipAddr.v[1], ipAddr.v[2], ipAddr.v[3]);

                appData.state = APP_GOING_ON;
            }

            break;


        case APP_GOING_ON:
            LED1_Off();
            LED2_On();            
            if(SYS_TMR_TickCountGet() - startTick >= SYS_TMR_TickCounterFrequencyGet()/2ul)
            {
                LED3_Toggle();
                startTick = SYS_TMR_TickCountGet();
            }

            // if the IP address of an interface has changed
            // display the new value on the system console
            nNets = TCPIP_STACK_NumberOfNetworksGet();

            for(i = 0; i < nNets; i++)
            {
                netH = TCPIP_STACK_IndexToNet(i);
                if(!TCPIP_STACK_NetIsReady(netH))
                {
                    return;    // interface not ready yet!
                }
                ipAddr.Val = TCPIP_STACK_NetAddress(netH);
                if(dwLastIP[i].Val != ipAddr.Val)
                {
                    dwLastIP[i].Val = ipAddr.Val;

                    SYS_CONSOLE_MESSAGE(TCPIP_STACK_NetNameGet(netH));
                    SYS_CONSOLE_MESSAGE(" IP Address: ");
                    SYS_CONSOLE_PRINT("%d.%d.%d.%d \r\n", ipAddr.v[0], ipAddr.v[1], ipAddr.v[2], ipAddr.v[3]);
                }
            }
            
            break;
        
        case APP_TCPIP_ERROR:
            break;
        
        
        default:
            break;
    }

}

void APP_SetState(APP_STATES state)
{
    appData.state = state;
}

/*******************************************************************************
 End of File
 */
