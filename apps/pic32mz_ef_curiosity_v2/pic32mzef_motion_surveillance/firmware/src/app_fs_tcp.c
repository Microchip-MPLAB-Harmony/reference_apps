/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_fs_tcp.c

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

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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
//DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app_fs_tcp.h"
#include "sys_tasks.h"

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
    This structure should be initialized by the APP_FS_STATE_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_FS_TCPIP_DATA app_fs_tcpip_Data;
APP_FS_TCPIP_LED_STATE LEDstate = APP_FS_TCPIP_LED_STATE_OFF;


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************


bool APP_FS_SystemIsReady(void) 
{
    return app_fs_tcpip_Data.fs_sys_ready;
}


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_FS_TCPIP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_FS_TCPIP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_fs_tcpip_Data.state        = APP_FS_TCPIP_STATE_MOUNT_DISK; 
    app_fs_tcpip_Data.fs_sys_ready = false;
    
}

/******************************************************************************
  Function:
    void APP_FS_TCPIP_STATE_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_FS_TCPIP_Tasks ( void )
{
    SYS_STATUS          tcpipStat;
    TCPIP_NET_HANDLE    netH;
    int                 nNets;
    static IPV4_ADDR    dwLastIP[2] = { {-1}, {-1} };
    IPV4_ADDR           ipAddr;
    int                 i;
    const char          *netName, *netBiosName;
    static uint32_t     startTick = 0;
    
    /* Check the application's current state. */
    switch ( app_fs_tcpip_Data.state )
    {
        case APP_FS_TCPIP_STATE_MOUNT_DISK:
        {
            if(SYS_FS_Mount(SDCARD_DEV_NAME, SDCARD_MOUNT_NAME, FAT, 0, NULL) != 0)
            {
                /* The disk could not be mounted. Try
                 * mounting again until success. */
                app_fs_tcpip_Data.state = APP_FS_TCPIP_STATE_MOUNT_DISK;
            }
            else
            {
                /* Mount was successful. Unmount the disk, for testing. */
                app_fs_tcpip_Data.state = APP_FS_TCPIP_STATE_UNMOUNT_DISK;
            }
            break;
        }

        case APP_FS_TCPIP_STATE_UNMOUNT_DISK:
        {
            if(SYS_FS_Unmount(SDCARD_MOUNT_NAME) != 0)
            {
                /* The disk could not be un mounted. Try
                 * un mounting again until success. */

                app_fs_tcpip_Data.state = APP_FS_TCPIP_STATE_UNMOUNT_DISK;
            }
            else
            {
                /* UnMount was successful. Mount the disk again */
                app_fs_tcpip_Data.state = APP_FS_TCPIP_STATE_MOUNT_DISK_AGAIN;
            }
            break;
        }

        case APP_FS_TCPIP_STATE_MOUNT_DISK_AGAIN:
        {
            if(SYS_FS_Mount(SDCARD_DEV_NAME, SDCARD_MOUNT_NAME, FAT, 0, NULL) != 0)
            {
                /* The disk could not be mounted. Try
                 * mounting again until success. */
                app_fs_tcpip_Data.state = APP_FS_TCPIP_STATE_MOUNT_DISK_AGAIN;
            }
            else
            {
                SYS_CONSOLE_PRINT("Mount was successful\n\r");  
                /* Mount was successful. Set current drive so that we do not have to use absolute path. */
                app_fs_tcpip_Data.state = APP_FS_TCPIP_STATE_SET_CURRENT_DRIVE;
            }
            break;
        }

        case APP_FS_TCPIP_STATE_SET_CURRENT_DRIVE:
        {
            if(SYS_FS_CurrentDriveSet(SDCARD_MOUNT_NAME) == SYS_FS_RES_FAILURE)
            {
                /* Error while setting current drive */
                app_fs_tcpip_Data.state = APP_FS_TCPIP_STATE_ERROR;
            }
            else
            {
                /* create arducam directory*/
                SYS_FS_DirectoryMake(SDCARD_DIR_NAME);
                
                SYS_CONSOLE_PRINT("FILESYSTEM READY\n\r");  
                /* Setting current drive was successful. */
                app_fs_tcpip_Data.state = APP_FS_TCPIP_STATE_WAIT_INIT;
                app_fs_tcpip_Data.fs_sys_ready = true;
   
            }
            break;
        }
        
        case APP_FS_TCPIP_STATE_WAIT_INIT:
            tcpipStat = TCPIP_STACK_Status(sysObj.tcpip);
            if(tcpipStat < 0)
            {   // some error occurred
                SYS_CONSOLE_MESSAGE("APP: TCP/IP stack initialization failed!\r\n");
                app_fs_tcpip_Data.state = APP_FS_TCPIP_STATE_ERROR;
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
                // register the application HTTP processing
                HTTP_APP_Initialize();
#endif
                app_fs_tcpip_Data.state = APP_FS_TCPIP_STATE_TRANSACT;
            }

            break;

        case APP_FS_TCPIP_STATE_TRANSACT:
            if(SYS_TMR_TickCountGet() - startTick >= SYS_TMR_TickCounterFrequencyGet()/2ul)
            {
                startTick = SYS_TMR_TickCountGet();
                LEDstate ^= APP_FS_TCPIP_LED_STATE_ON;
                if(LEDstate == 1)
                {
                    APP_LED_1StateSet();
                }
                else if(LEDstate == 0)
                {
                    APP_LED_1StateClear();
                }
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
       
        case APP_FS_TCPIP_STATE_IDLE:
        {
            break;
        }

        case APP_FS_TCPIP_STATE_ERROR:
        {
             app_fs_tcpip_Data.fs_sys_ready = false;
             
            SYS_CONSOLE_PRINT("APP_FS_TCPIP_STATE_Task: Error...!\n\r");    
            
            break;
        }

        default:
            break;
    }
}



/*******************************************************************************
 End of File
 */
