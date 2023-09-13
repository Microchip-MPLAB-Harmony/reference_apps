/*******************************************************************************
  System Initialization File

  File Name:
    initialization.c

  Summary:
    This file contains source code necessary to initialize the system.

  Description:
    This file contains source code necessary to initialize the system.  It
    implements the "SYS_Initialize" function, defines the configuration bits,
    and allocates any necessary global system resources,
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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
#include "configuration.h"
#include "definitions.h"
#include "device.h"


// ****************************************************************************
// ****************************************************************************
// Section: Configuration Bits
// ****************************************************************************
// ****************************************************************************
#pragma config NVMCTRL_BOOTPROT = SIZE_0BYTES
#pragma config NVMCTRL_EEPROM_SIZE = SIZE_0BYTES
#pragma config BOD33USERLEVEL = 0x7U // Enter Hexadecimal value
#pragma config BOD33_EN = ENABLED
#pragma config BOD33_ACTION = RESET

#pragma config BOD33_HYST = DISABLED
#pragma config NVMCTRL_REGION_LOCKS = 0xffffU // Enter Hexadecimal value

#pragma config WDT_ENABLE = DISABLED
#pragma config WDT_ALWAYSON = DISABLED
#pragma config WDT_PER = CYC16384

#pragma config WDT_WINDOW_0 = SET
#pragma config WDT_WINDOW_1 = 0x4U // Enter Hexadecimal value
#pragma config WDT_EWOFFSET = CYC16384
#pragma config WDT_WEN = DISABLED




// *****************************************************************************
// *****************************************************************************
// Section: Driver Initialization Data
// *****************************************************************************
// *****************************************************************************
/* Following MISRA-C rules are deviated in the below code block */
/* MISRA C-2012 Rule 11.1 */
/* MISRA C-2012 Rule 11.3 */
/* MISRA C-2012 Rule 11.8 */
// <editor-fold defaultstate="collapsed" desc="DRV_SDSPI Instance 0 Initialization Data">

/* SDSPI Client Objects Pool */
static DRV_SDSPI_CLIENT_OBJ drvSDSPI0ClientObjPool[DRV_SDSPI_CLIENTS_NUMBER_IDX0];

/* SDSPI Transfer Objects Pool */
static DRV_SDSPI_BUFFER_OBJ drvSDSPI0TransferObjPool[DRV_SDSPI_QUEUE_SIZE_IDX0];


/* SDSPI Driver Initialization Data */
static const DRV_SDSPI_INIT drvSDSPI0InitData =
{
    .spiDrvIndex            = 0,

    /* SDSPI Number of clients */
    .numClients             = DRV_SDSPI_CLIENTS_NUMBER_IDX0,

    /* SDSPI Client Objects Pool */
    .clientObjPool          = (uintptr_t)&drvSDSPI0ClientObjPool[0],

    /* SDSPI Transfer Objects Pool */
    .bufferObjPool          = (uintptr_t)&drvSDSPI0TransferObjPool[0],

    /* SDSPI Transfer Objects Queue Size */
    .bufferObjPoolSize      = DRV_SDSPI_QUEUE_SIZE_IDX0,

    .chipSelectPin          = DRV_SDSPI_CHIP_SELECT_PIN_IDX0,

    .sdcardSpeedHz          = DRV_SDSPI_SPEED_HZ_IDX0,

    .pollingIntervalMs      = DRV_SDSPI_POLLING_INTERVAL_MS_IDX0,

    .writeProtectPin        = SYS_PORT_PIN_NONE,

    .isFsEnabled            = true,

};
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="DRV_SPI Instance 0 Initialization Data">

/* SPI Client Objects Pool */
static DRV_SPI_CLIENT_OBJ drvSPI0ClientObjPool[DRV_SPI_CLIENTS_NUMBER_IDX0];

/* SPI Transfer Objects Pool */
static DRV_SPI_TRANSFER_OBJ drvSPI0TransferObjPool[DRV_SPI_QUEUE_SIZE_IDX0];

/* SPI PLIB Interface Initialization */
static const DRV_SPI_PLIB_INTERFACE drvSPI0PlibAPI = {

    /* SPI PLIB Setup */
    .setup = (DRV_SPI_PLIB_SETUP)SERCOM0_SPI_TransferSetup,

    /* SPI PLIB WriteRead function */
    .writeRead = (DRV_SPI_PLIB_WRITE_READ)SERCOM0_SPI_WriteRead,

    /* SPI PLIB Transfer Status function */
    .isTransmitterBusy = (DRV_SPI_PLIB_TRANSMITTER_IS_BUSY)SERCOM0_SPI_IsTransmitterBusy,

    /* SPI PLIB Callback Register */
    .callbackRegister = (DRV_SPI_PLIB_CALLBACK_REGISTER)SERCOM0_SPI_CallbackRegister,
};

static const uint32_t drvSPI0remapDataBits[]= { 0x0, 0x1, 0xFFFFFFFFU, 0xFFFFFFFFU, 0xFFFFFFFFU, 0xFFFFFFFFU, 0xFFFFFFFFU, 0xFFFFFFFFU, 0xFFFFFFFFU, 0xFFFFFFFFU };
static const uint32_t drvSPI0remapClockPolarity[] = { 0x0, 0x20000000 };
static const uint32_t drvSPI0remapClockPhase[] = { 0x10000000, 0x0 };

static const DRV_SPI_INTERRUPT_SOURCES drvSPI0InterruptSources =
{
    /* Peripheral has single interrupt vector */
    .isSingleIntSrc                        = true,

    /* Peripheral interrupt line */
    .intSources.spiInterrupt             = (int32_t)SERCOM0_IRQn,
    /* DMA interrupt line */
    .intSources.dmaInterrupt               = (int32_t)DMAC_IRQn,
};

/* SPI Driver Initialization Data */
static const DRV_SPI_INIT drvSPI0InitData =
{
    /* SPI PLIB API */
    .spiPlib = &drvSPI0PlibAPI,

    .remapDataBits = drvSPI0remapDataBits,

    .remapClockPolarity = drvSPI0remapClockPolarity,

    .remapClockPhase = drvSPI0remapClockPhase,

    /* SPI Number of clients */
    .numClients = DRV_SPI_CLIENTS_NUMBER_IDX0,

    /* SPI Client Objects Pool */
    .clientObjPool = (uintptr_t)&drvSPI0ClientObjPool[0],

    /* DMA Channel for Transmit */
    .dmaChannelTransmit = DRV_SPI_XMIT_DMA_CH_IDX0,

    /* DMA Channel for Receive */
    .dmaChannelReceive  = DRV_SPI_RCV_DMA_CH_IDX0,

    /* SPI Transmit Register */
    .spiTransmitAddress =  (void *)&(SERCOM0_REGS->SPIM.SERCOM_DATA),

    /* SPI Receive Register */
    .spiReceiveAddress  = (void *)&(SERCOM0_REGS->SPIM.SERCOM_DATA),

    /* SPI Queue Size */
    .transferObjPoolSize = DRV_SPI_QUEUE_SIZE_IDX0,

    /* SPI Transfer Objects Pool */
    .transferObjPool = (uintptr_t)&drvSPI0TransferObjPool[0],

    /* SPI interrupt sources (SPI peripheral and DMA) */
    .interruptSources = &drvSPI0InterruptSources,
};
// </editor-fold>



// *****************************************************************************
// *****************************************************************************
// Section: System Data
// *****************************************************************************
// *****************************************************************************
/* Structure to hold the object handles for the modules in the system. */
SYSTEM_OBJECTS sysObj;

// *****************************************************************************
// *****************************************************************************
// Section: Library/Stack Initialization Data
// *****************************************************************************
// *****************************************************************************
// <editor-fold defaultstate="collapsed" desc="File System Initialization Data">


const SYS_FS_MEDIA_MOUNT_DATA sysfsMountTable[SYS_FS_VOLUME_NUMBER] =
{
    {NULL}
};

static const SYS_FS_FUNCTIONS FatFsFunctions =
{
    .mount             = FATFS_mount,
    .unmount           = FATFS_unmount,
    .open              = FATFS_open,
    .read_t              = FATFS_read,
    .close             = FATFS_close,
    .seek              = FATFS_lseek,
    .fstat             = FATFS_stat,
    .getlabel          = FATFS_getlabel,
    .currWD            = FATFS_getcwd,
    .getstrn           = FATFS_gets,
    .openDir           = FATFS_opendir,
    .readDir           = FATFS_readdir,
    .closeDir          = FATFS_closedir,
    .chdir             = FATFS_chdir,
    .chdrive           = FATFS_chdrive,
    .write_t             = FATFS_write,
    .tell              = FATFS_tell,
    .eof               = FATFS_eof,
    .size              = FATFS_size,
    .mkdir             = FATFS_mkdir,
    .remove_t            = FATFS_unlink,
    .setlabel          = FATFS_setlabel,
    .truncate          = FATFS_truncate,
    .chmode            = FATFS_chmod,
    .chtime            = FATFS_utime,
    .rename_t            = FATFS_rename,
    .sync              = FATFS_sync,
    .putchr            = FATFS_putc,
    .putstrn           = FATFS_puts,
    .formattedprint    = FATFS_printf,
    .testerror         = FATFS_error,
    .formatDisk        = (FORMAT_DISK)FATFS_mkfs,
    .partitionDisk     = FATFS_fdisk,
    .getCluster        = FATFS_getclusters
};




static const SYS_FS_REGISTRATION_TABLE sysFSInit [ SYS_FS_MAX_FILE_SYSTEM_TYPE ] =
{
    {
        .nativeFileSystemType = FAT,
        .nativeFileSystemFunctions = &FatFsFunctions
    }
};
// </editor-fold>

/******************************************************
 * USB Driver Initialization
 ******************************************************/
 
/*  When designing a Self-powered USB Device, the application should make sure
    that USB_DEVICE_Attach() function is called only when VBUS is actively powered.
    Therefore, the firmware needs some means to detect when the Host is powering 
    the VBUS. A 5V tolerant I/O pin can be connected to VBUS (through a resistor)
    and can be used to detect when VBUS is high or low. The application can specify
    a VBUS Detect function through the USB Driver Initialize data structure. 
    The USB device stack will periodically call this function. If the VBUS is 
    detected, the USB_DEVICE_EVENT_POWER_DETECTED event is generated. If the VBUS 
    is removed (i.e., the device is physically detached from Host), the USB stack 
    will generate the event USB_DEVICE_EVENT_POWER_REMOVED. The application should 
    call USB_DEVICE_Detach() when VBUS is removed. 
    
    The following are the steps to generate the VBUS_SENSE Function through MHC     
        1) Navigate to MHC->Tools->Pin Configuration and Configure the pin used 
           as VBUS_SENSE. Set this pin Function as "GPIO" and set as "Input". 
           Provide a custom name to the pin.
        2) Select the USB Driver Component in MHC Project Graph and enable the  
           "Enable VBUS Sense" Check-box.     
        3) Specify the custom name of the VBUS SENSE pin in the "VBUS SENSE Pin Name" box.  */ 
static DRV_USB_VBUS_LEVEL DRV_USBFSV1_VBUS_Comparator(void)
{
    DRV_USB_VBUS_LEVEL retVal = DRV_USB_VBUS_LEVEL_INVALID;
    
    if(true == USB_VBUS_SENSE_Get())
    {
        retVal = DRV_USB_VBUS_LEVEL_VALID;
    }
    return (retVal);

}

const DRV_USBFSV1_INIT drvUSBInit =
{
    /* Interrupt Source for USB module */ 
    .interruptSource = USB_IRQn,

    /* System module initialization */
    .moduleInit = {0},

    /* USB Controller to operate as USB Device */
    .operationMode = DRV_USBFSV1_OPMODE_DEVICE,

    /* USB Full Speed Operation */
    .operationSpeed = USB_SPEED_FULL,
    
    /* Stop in idle */
    .runInStandby = true,

    /* Suspend in sleep */
    .suspendInSleep = false,

    /* Identifies peripheral (PLIB-level) ID */
    .usbID = USB_REGS,

    /* Function to check for VBus */
    .vbusComparator = DRV_USBFSV1_VBUS_Comparator

};




// *****************************************************************************
// *****************************************************************************
// Section: System Initialization
// *****************************************************************************
// *****************************************************************************
// <editor-fold defaultstate="collapsed" desc="SYS_TIME Initialization Data">

static const SYS_TIME_PLIB_INTERFACE sysTimePlibAPI = {
    .timerCallbackSet = (SYS_TIME_PLIB_CALLBACK_REGISTER)TC3_TimerCallbackRegister,
    .timerStart = (SYS_TIME_PLIB_START)TC3_TimerStart,
    .timerStop = (SYS_TIME_PLIB_STOP)TC3_TimerStop,
    .timerFrequencyGet = (SYS_TIME_PLIB_FREQUENCY_GET)TC3_TimerFrequencyGet,
    .timerPeriodSet = (SYS_TIME_PLIB_PERIOD_SET)TC3_Timer16bitPeriodSet,
    .timerCompareSet = (SYS_TIME_PLIB_COMPARE_SET)TC3_Timer16bitCompareSet,
    .timerCounterGet = (SYS_TIME_PLIB_COUNTER_GET)TC3_Timer16bitCounterGet,
};

static const SYS_TIME_INIT sysTimeInitData =
{
    .timePlib = &sysTimePlibAPI,
    .hwTimerIntNum = TC3_IRQn,
};

// </editor-fold>



// *****************************************************************************
// *****************************************************************************
// Section: Local initialization functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void STDIO_BufferModeSet ( void )

  Summary:
    Sets the buffering mode for stdin and stdout

  Remarks:
 ********************************************************************************/
static void STDIO_BufferModeSet(void)
{
    /* MISRAC 2012 deviation block start */
    /* MISRA C-2012 Rule 21.6 deviated 2 times in this file.  Deviation record ID -  H3_MISRAC_2012_R_21_6_DR_3 */

    /* Make stdin unbuffered */
    setbuf(stdin, NULL);

    /* Make stdout unbuffered */
    setbuf(stdout, NULL);
}


/* MISRAC 2012 deviation block end */

/*******************************************************************************
  Function:
    void SYS_Initialize ( void *data )

  Summary:
    Initializes the board, services, drivers, application and other modules.

  Remarks:
 */

void SYS_Initialize ( void* data )
{

    /* MISRAC 2012 deviation block start */
    /* MISRA C-2012 Rule 2.2 deviated in this file.  Deviation record ID -  H3_MISRAC_2012_R_2_2_DR_1 */

    NVMCTRL_REGS->NVMCTRL_CTRLB = NVMCTRL_CTRLB_RWS(3UL);

    STDIO_BufferModeSet();


  
    PORT_Initialize();

    CLOCK_Initialize();




    SERCOM3_USART_Initialize();

    NVMCTRL_Initialize( );


    SERCOM0_SPI_Initialize();

    DMAC_Initialize();

    ADC_Initialize();
    TC3_TimerInitialize();

	BSP_Initialize();


    /* MISRAC 2012 deviation block start */
    /* Following MISRA-C rules deviated in this block  */
    /* MISRA C-2012 Rule 11.3 - Deviation record ID - H3_MISRAC_2012_R_11_3_DR_1 */
    /* MISRA C-2012 Rule 11.8 - Deviation record ID - H3_MISRAC_2012_R_11_8_DR_1 */

    /* Initialize SDSPI0 Driver Instance */
    sysObj.drvSDSPI0 = DRV_SDSPI_Initialize(DRV_SDSPI_INDEX_0, (SYS_MODULE_INIT *)&drvSDSPI0InitData);

    /* Initialize SPI0 Driver Instance */
    sysObj.drvSPI0 = DRV_SPI_Initialize(DRV_SPI_INDEX_0, (SYS_MODULE_INIT *)&drvSPI0InitData);


    /* MISRA C-2012 Rule 11.3, 11.8 deviated below. Deviation record ID -  
    H3_MISRAC_2012_R_11_3_DR_1 & H3_MISRAC_2012_R_11_8_DR_1*/
        
    sysObj.sysTime = SYS_TIME_Initialize(SYS_TIME_INDEX_0, (SYS_MODULE_INIT *)&sysTimeInitData);
    
    /* MISRAC 2012 deviation block end */


    /* Initialize the USB device layer */
    sysObj.usbDevObject0 = USB_DEVICE_Initialize (USB_DEVICE_INDEX_0 , ( SYS_MODULE_INIT* ) & usbDevInitData);


    /*** File System Service Initialization Code ***/
    (void) SYS_FS_Initialize( (const void *) sysFSInit );

    /* Initialize USB Driver */ 
    sysObj.drvUSBFSV1Object = DRV_USBFSV1_Initialize(DRV_USBFSV1_INDEX_0, (SYS_MODULE_INIT *) &drvUSBInit);


    /* MISRAC 2012 deviation block end */
    APP_Initialize();


    NVIC_Initialize();


    /* MISRAC 2012 deviation block end */
}

/*******************************************************************************
 End of File
*/
