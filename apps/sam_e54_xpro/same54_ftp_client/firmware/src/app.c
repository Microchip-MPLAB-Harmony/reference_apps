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
 
 // DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "system_config.h"
#include "system_definitions.h"
#include "bsp/bsp.h"
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
#define SDCARD_MOUNT_NAME    SYS_FS_MEDIA_IDX0_MOUNT_NAME_VOLUME_IDX0
#define SDCARD_DEV_NAME      SYS_FS_MEDIA_IDX0_DEVICE_NAME_VOLUME_IDX0
#define SDCARD_FILE_NAME     "test.bin"
#define SDCARD_DIR_NAME      "Dir1"
#define APP_DATA_LEN         7168              
#define APP_START_ADDRESS    0x80000
#define PAGE_SIZE            FLASH_PAGE_SIZE

    
#define ERASE_BLOCK_SIZE        (8192UL)      //The NVMCTRL_FLASH_BLOCKSIZE = 8192, is not the start address, it defines the size of the array that stores the user variables.

//And it has to be aligned to a block size and the size of this has to be in multiples of a single block size (which is 8192 bytes).

//The SAME54P20A has a flash memory of 1024KB. Out of this, you would have to allocate a minimum of at least

//8192 bytes, for the user variables.

//If you wish to allocate even lesser memory, then you will have to use SMART eeprom as mentioned earlier and have 512 bytes allocated for user values.
#define DATA_SIZE                ERASE_BLOCK_SIZE
#define PAGES_IN_ERASE_BLOCK    (ERASE_BLOCK_SIZE / PAGE_SIZE)
    
#define WORDS(x)                ((uint32_t)((x) / sizeof(uint32_t)))

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


bool bin_downloaded = false;
volatile uint8_t count_down = 5;
extern TCPIP_FTPC_CONN_HANDLE_TYPE ftpcHandle;
/* Application data buffer */
uint32_t CACHE_ALIGN dataBuffer[WORDS(APP_DATA_LEN)];


const SYS_CMD_DESCRIPTOR    appCmdTbl[]=
{
    {"boot",     (SYS_CMD_FNC)APP_Trig_Boot,              ": Starts bootloading of the downloaded binary"},
};


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

static void APP_SysFSEventHandler(SYS_FS_EVENT event,void* eventData,uintptr_t context)
{
    switch(event)
    {
        /* If the event is mount then check if SDCARD media has been mounted */
        case SYS_FS_EVENT_MOUNT:
            if(strcmp((const char *)eventData, SDCARD_MOUNT_NAME) == 0)
            {
                appData.sdCardMountFlag = true;
            }
            break;
        /* If the event is unmount then check if SDCARD media has been unmount */
        case SYS_FS_EVENT_UNMOUNT:
            if(strcmp((const char *)eventData, SDCARD_MOUNT_NAME) == 0)
            {
                appData.sdCardMountFlag = false;
                appData.state = APP_MOUNT_WAIT;
            }
            break;
        case SYS_FS_EVENT_ERROR:
            break;
            
        case SYS_FS_EVENT_MOUNT_WITH_NO_FILESYSTEM: 
            break;
    }
}
// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

void APP_Trig_Boot(void)
{
    bin_downloaded = true;
}

bool APP_Bootloader_Enter(void)
{
    uint32_t app_check_address;
	uint32_t *app_check_address_ptr;
    
    /* Check for Switch press to enter Bootloader */
    if (SWITCH_Get() == 0)
    {
        SYS_CONSOLE_PRINT("Invoking FTP Bootloader...\r\n");
        return true;
    }
    
    else
    {
        app_check_address = APP_START_ADDRESS;
		app_check_address_ptr = (uint32_t *) app_check_address;
		/*
		 * Read the first location of application section
		 * which contains the address of stack pointer.
		 * If it is 0xFFFFFFFF then the application section is empty.
		 */
		if (*app_check_address_ptr == 0xFFFFFFFF) {
          SYS_CONSOLE_PRINT("No application code found. Invoking FTP Bootloader...\r\n");
            return true;
        }
        
    }
    return false;
}
void APP_Run_Application(void)
{
    uint32_t msp            = *(uint32_t *)(APP_START_ADDRESS);
    uint32_t reset_vector   = *(uint32_t *)(APP_START_ADDRESS + 4);
    if (msp == 0xffffffff)
    {
        return;
    }
    __set_MSP(msp);
    
    /* Rebase the vector table base address */
	SCB->VTOR = ((uint32_t) APP_START_ADDRESS & SCB_VTOR_TBLOFF_Msk);
    asm("bx %0"::"r" (reset_vector));
}

__attribute__((section(".ramfunc"), unique_section))
void APP_Flash_Task(void)
{
    uint32_t addr       = APP_START_ADDRESS;
    uint32_t page       = 0;
    uint32_t write_idx  = 0;
    
    //disable the interrupts	
    bool NVIC_INT_Disable();
    
    // Lock region size is always bigger than the row size
    NVMCTRL_RegionUnlock(addr);
    while(NVMCTRL_IsBusy() == true);
    /* Erase the Current sector */
    NVMCTRL_BlockErase(addr);
    /* Receive Next Bytes while waiting for erase to complete */
    while(NVMCTRL_IsBusy() == true);
    for (page = 0; page < PAGES_IN_ERASE_BLOCK; page++)
    {
        NVMCTRL_PageWrite(&dataBuffer[write_idx], addr);
        while(NVMCTRL_IsBusy() == true);
        addr += PAGE_SIZE;
        write_idx += WORDS(PAGE_SIZE);
    }
     NVIC_INT_Restore(true);
}
void APP_Timer(uintptr_t context)
{
    SYS_CONSOLE_PRINT("%d\b", count_down);
    if(count_down!=0)
       count_down --;
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
    /* Place the App state machine in its initial state. */
  appData.state = APP_MOUNT_WAIT;
  
    /* Register the File System Event handler */
    SYS_FS_EventHandlerSet((void const*)APP_SysFSEventHandler,(uintptr_t)NULL);
    
    // create command group
    if (!SYS_CMD_ADDGRP(appCmdTbl, sizeof(appCmdTbl)/sizeof(*appCmdTbl), "Application", ": user commands"))
    {
        SYS_ERROR(SYS_ERROR_ERROR, "Failed to create Application Commands\r\n");
    }
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
    
    TCPIP_FTPC_STATUS_TYPE ftpcStatus;
//    TCPIP_FTPC_DCPT_TYPE* clientDcpt = (TCPIP_FTPC_DCPT_TYPE*)ftpcHandle;

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        
		case APP_MOUNT_WAIT:
            /* Wait for SDCARD to be Auto Mounted */
            if(appData.sdCardMountFlag == true)
            {
                SYS_CONSOLE_PRINT("SYS_Initialize: The %s File System is mounted\r\n", 
                        APP_SYS_FS_TYPE_STRING);
                appData.state = APP_TCPIP_WAIT_INIT;
            }
            break;
        
        case APP_TCPIP_WAIT_INIT:
            tcpipStat = TCPIP_STACK_Status(sysObj.tcpip);
            if(tcpipStat < 0)
            {   // some error occurred
                SYS_CONSOLE_MESSAGE(" APP: TCP/IP stack initialization failed!\r\n");
                appData.state = APP_TCPIP_ERROR;
            }
            else if(tcpipStat == SYS_STATUS_READY)
            {
                // now that the stack is ready we can check the available interfaces and register
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
                #endif  // defined(TCPIP_STACK_USE_NBNS)
                                    (void)netName;          // avoid compiler warning 
                                    (void)netBiosName;      // if SYS_CONSOLE_PRINT is null macro
                }
                appData.state = APP_TCPIP_TRANSACT;
            }
            break;
            
        case APP_TCPIP_TRANSACT:
            // if the IP address of an interface has changed
            // display the new value on the system console
            nNets = TCPIP_STACK_NumberOfNetworksGet();
            for (i = 0; i < nNets; i++)
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
                    SYS_CONSOLE_MESSAGE("Connect to FTP server using ftpc commands\r\nEg: ftpc connect 10.40.32.94 \r\n");
                    appData.state = APP_Connect_FTP;          
                }
            }
            
            break;
            
        case APP_Connect_FTP:
            
            TCPIP_FTPC_Get_Status(ftpcHandle, &ftpcStatus);
            
            if(ftpcStatus.isConnected)
            {
                SYS_CONSOLE_MESSAGE("FTP Client connected \r\n");
                appData.state = APP_Login_FTP;   
                SYS_CONSOLE_MESSAGE("Login with your credentials \r\nEg: ftpc login username psswd\r\n");
            }
            
            break;
            
            
        case APP_Login_FTP:
            
            TCPIP_FTPC_Get_Status(ftpcHandle, &ftpcStatus);
            
            if(ftpcStatus.isLoggedIn)
            {
                SYS_CONSOLE_MESSAGE("FTP Client logged in \r\n");
                appData.state = APP_SET_CURRENT_DRIVE;                
            }
            
            break;
            
            
        case APP_SET_CURRENT_DRIVE:
            if(SYS_FS_CurrentDriveSet(SDCARD_MOUNT_NAME) == SYS_FS_RES_FAILURE)
            {
                /* Error while setting current drive */
                SYS_CONSOLE_MESSAGE("Error while setting current drive\r\n");
                appData.state = APP_ERROR;
            }
            else
            {
                /* Download application binary from server */               
                SYS_CONSOLE_MESSAGE("Use ftpc get command to download binary\r\nEg: ftpc get -a -a test.bin \r\n");
                SYS_CONSOLE_MESSAGE("\r\nEnter command 'boot' after receiving 'Command Success' message\r\n");
                appData.state = APP_DOWNLOAD_BIN;
            }
            break;
            
        case APP_DOWNLOAD_BIN:  
                                    
            if (bin_downloaded == true)
            {
                /* Open a file for reading. */
                SYS_CONSOLE_MESSAGE("Opening file...\r\n");
                appData.state = APP_OPEN_FILE;                
            }                       
            break; 
            
        case APP_OPEN_FILE:
            
            appData.fileHandle = SYS_FS_FileOpen(SDCARD_FILE_NAME,(SYS_FS_FILE_OPEN_READ));
            if(appData.fileHandle == SYS_FS_HANDLE_INVALID)
            {
                /* Could not open the file. Error out*/
                SYS_CONSOLE_MESSAGE("Could not open the file\r\n");
                appData.state = APP_ERROR;
            }
            else
            {
                /* Read the file */
                appData.state = APP_READ_FILE;
            }
            break;
            
        case APP_READ_FILE:
            
            appData.fileSize = SYS_FS_FileSize(appData.fileHandle);
            appData.nBytesRead = SYS_FS_FileRead(appData.fileHandle, (void *)dataBuffer, appData.fileSize);
            
            if (appData.nBytesRead == -1)
            {
                /* There was an error while reading the file.
                 * Close the file and error out. */
                SYS_FS_FileClose(appData.fileHandle);
                SYS_CONSOLE_MESSAGE("There was an error while reading the file\r\n");
                appData.state = APP_ERROR;
            }
            else
            {
                /* The read was successful. Lets bootload. */
                SYS_CONSOLE_MESSAGE("Read was successful. Now bootload\r\n");
                appData.state = APP_BOOTLOAD;
            }
            break;
            
        case APP_BOOTLOAD:
            
            APP_Flash_Task();
            SYS_CONSOLE_MESSAGE("File flashed\r\n");
            appData.state = APP_CLOSE_FILE;
            break;
            
        case APP_CLOSE_FILE:
            /* Close both files */
            SYS_FS_FileClose(appData.fileHandle);
            /* The test was successful. Lets idle. */
            SYS_CONSOLE_MESSAGE("Resetting MCU to run application in ");
	    appData.state = RUN_APPLICATION;
            SYS_TIME_CallbackRegisterMS(
                            APP_Timer, 
                            0, 
                            1000, 
                            SYS_TIME_PERIODIC
                        );
	    
	   
            break;
            
        case RUN_APPLICATION:  
            
            if(count_down == 0)
	    { NVIC_SystemReset(); }
            break;
            
        case APP_ERROR:      
        
		
        default:
            SYS_CONSOLE_MESSAGE("Application Error\r\n");
            break;
            
    }
}
/*******************************************************************************
 End of File
 */