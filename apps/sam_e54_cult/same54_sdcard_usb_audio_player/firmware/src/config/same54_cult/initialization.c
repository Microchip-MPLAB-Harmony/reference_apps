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
#pragma config BOD33_DIS = SET
#pragma config BOD33USERLEVEL = 0x1c
#pragma config BOD33_ACTION = RESET
#pragma config BOD33_HYST = 0x2
#pragma config NVMCTRL_BOOTPROT = 0
#pragma config NVMCTRL_SEESBLK = 0x0
#pragma config NVMCTRL_SEEPSZ = 0x0
#pragma config RAMECC_ECCDIS = SET
#pragma config WDT_ENABLE = CLEAR
#pragma config WDT_ALWAYSON = CLEAR
#pragma config WDT_PER = CYC8192
#pragma config WDT_WINDOW = CYC8192
#pragma config WDT_EWOFFSET = CYC8192
#pragma config WDT_WEN = CLEAR
#pragma config NVMCTRL_REGION_LOCKS = 0xffffffff




// *****************************************************************************
// *****************************************************************************
// Section: Driver Initialization Data
// *****************************************************************************
// *****************************************************************************
// <editor-fold defaultstate="collapsed" desc="DRV_I2C Instance 0 Initialization Data">

/* I2C Client Objects Pool */
static DRV_I2C_CLIENT_OBJ drvI2C0ClientObjPool[DRV_I2C_CLIENTS_NUMBER_IDX0];

/* I2C Transfer Objects Pool */
static DRV_I2C_TRANSFER_OBJ drvI2C0TransferObj[DRV_I2C_QUEUE_SIZE_IDX0];

/* I2C PLib Interface Initialization */
const DRV_I2C_PLIB_INTERFACE drvI2C0PLibAPI = {

    /* I2C PLib Transfer Read Add function */
    .read = (DRV_I2C_PLIB_READ)SERCOM4_I2C_Read,

    /* I2C PLib Transfer Write Add function */
    .write = (DRV_I2C_PLIB_WRITE)SERCOM4_I2C_Write,


    /* I2C PLib Transfer Write Read Add function */
    .writeRead = (DRV_I2C_PLIB_WRITE_READ)SERCOM4_I2C_WriteRead,

    /* I2C PLib Transfer Status function */
    .errorGet = (DRV_I2C_PLIB_ERROR_GET)SERCOM4_I2C_ErrorGet,

    /* I2C PLib Transfer Setup function */
    .transferSetup = (DRV_I2C_PLIB_TRANSFER_SETUP)SERCOM4_I2C_TransferSetup,

    /* I2C PLib Callback Register */
    .callbackRegister = (DRV_I2C_PLIB_CALLBACK_REGISTER)SERCOM4_I2C_CallbackRegister,
};


const DRV_I2C_INTERRUPT_SOURCES drvI2C0InterruptSources =
{
    /* Peripheral has more than one interrupt vector */
    .isSingleIntSrc                        = false,

    /* Peripheral interrupt lines */
    .intSources.multi.i2cInt0          = SERCOM4_0_IRQn,
    .intSources.multi.i2cInt1          = SERCOM4_1_IRQn,
    .intSources.multi.i2cInt2          = SERCOM4_2_IRQn,
    .intSources.multi.i2cInt3          = SERCOM4_OTHER_IRQn,
};

/* I2C Driver Initialization Data */
const DRV_I2C_INIT drvI2C0InitData =
{
    /* I2C PLib API */
    .i2cPlib = &drvI2C0PLibAPI,

    /* I2C Number of clients */
    .numClients = DRV_I2C_CLIENTS_NUMBER_IDX0,

    /* I2C Client Objects Pool */
    .clientObjPool = (uintptr_t)&drvI2C0ClientObjPool[0],

    /* I2C TWI Queue Size */
    .transferObjPoolSize = DRV_I2C_QUEUE_SIZE_IDX0,

    /* I2C Transfer Objects */
    .transferObjPool = (uintptr_t)&drvI2C0TransferObj[0],

    /* I2C interrupt sources */
    .interruptSources = &drvI2C0InterruptSources,

    /* I2C Clock Speed */
    .clockSpeed = DRV_I2C_CLOCK_SPEED_IDX0,
};

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="DRV_I2C Instance 1 Initialization Data">

/* I2C Client Objects Pool */
static DRV_I2C_CLIENT_OBJ drvI2C1ClientObjPool[DRV_I2C_CLIENTS_NUMBER_IDX1];

/* I2C Transfer Objects Pool */
static DRV_I2C_TRANSFER_OBJ drvI2C1TransferObj[DRV_I2C_QUEUE_SIZE_IDX1];

/* I2C PLib Interface Initialization */
const DRV_I2C_PLIB_INTERFACE drvI2C1PLibAPI = {

    /* I2C PLib Transfer Read Add function */
    .read = (DRV_I2C_PLIB_READ)SERCOM6_I2C_Read,

    /* I2C PLib Transfer Write Add function */
    .write = (DRV_I2C_PLIB_WRITE)SERCOM6_I2C_Write,


    /* I2C PLib Transfer Write Read Add function */
    .writeRead = (DRV_I2C_PLIB_WRITE_READ)SERCOM6_I2C_WriteRead,

    /* I2C PLib Transfer Status function */
    .errorGet = (DRV_I2C_PLIB_ERROR_GET)SERCOM6_I2C_ErrorGet,

    /* I2C PLib Transfer Setup function */
    .transferSetup = (DRV_I2C_PLIB_TRANSFER_SETUP)SERCOM6_I2C_TransferSetup,

    /* I2C PLib Callback Register */
    .callbackRegister = (DRV_I2C_PLIB_CALLBACK_REGISTER)SERCOM6_I2C_CallbackRegister,
};


const DRV_I2C_INTERRUPT_SOURCES drvI2C1InterruptSources =
{
    /* Peripheral has more than one interrupt vector */
    .isSingleIntSrc                        = false,

    /* Peripheral interrupt lines */
    .intSources.multi.i2cInt0          = SERCOM6_0_IRQn,
    .intSources.multi.i2cInt1          = SERCOM6_1_IRQn,
    .intSources.multi.i2cInt2          = SERCOM6_2_IRQn,
    .intSources.multi.i2cInt3          = SERCOM6_OTHER_IRQn,
};

/* I2C Driver Initialization Data */
const DRV_I2C_INIT drvI2C1InitData =
{
    /* I2C PLib API */
    .i2cPlib = &drvI2C1PLibAPI,

    /* I2C Number of clients */
    .numClients = DRV_I2C_CLIENTS_NUMBER_IDX1,

    /* I2C Client Objects Pool */
    .clientObjPool = (uintptr_t)&drvI2C1ClientObjPool[0],

    /* I2C TWI Queue Size */
    .transferObjPoolSize = DRV_I2C_QUEUE_SIZE_IDX1,

    /* I2C Transfer Objects */
    .transferObjPool = (uintptr_t)&drvI2C1TransferObj[0],

    /* I2C interrupt sources */
    .interruptSources = &drvI2C1InterruptSources,

    /* I2C Clock Speed */
    .clockSpeed = DRV_I2C_CLOCK_SPEED_IDX1,
};

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="DRV_I2S Instance 0 Initialization Data">

/* I2S PLIB Interface Initialization */
DRV_I2S_PLIB_INTERFACE drvI2S0PlibAPI =
{
    .I2S_LRCLK_Get = (DRV_I2S_LRCLK_GET)I2S_LRCLK_Get,  
};

/* I2S Driver Initialization Data */
DRV_I2S_INIT drvI2S0InitData =
{
    /* I2S PLIB API */
    .i2sPlib = &drvI2S0PlibAPI,

    /* I2S IRQ */
    .interruptI2S = DRV_I2S_INT_SRC_IDX0,

    /* I2S Number of clients */
    .numClients = DRV_I2S_CLIENTS_NUMBER_IDX0,

    /* I2S Queue Size */
    .queueSize = DRV_I2S_QUEUE_SIZE_IDX0,  

    .dmaChannelTransmit = DRV_I2S_XMIT_DMA_CH_IDX0,
    .dmaChannelReceive  = DRV_I2S_RCV_DMA_CH_IDX0,
    .i2sTransmitAddress = (void *)&(I2S_REGS->I2S_TXDATA),
    .i2sReceiveAddress = (void *)&(I2S_REGS->I2S_RXDATA),
    .interruptDMA = DMAC_0_IRQn,

    .dmaDataLength = DRV_I2S_DATA_LENGTH_IDX0,
};

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="DRV_INPUT_MXT336T Initialization Data">
/*** MaxTouch Driver Initialization Data ***/
const DRV_MAXTOUCH_INIT drvMAXTOUCHInitData =
{
    .drvOpen                     = DRV_I2C_Open,
    .orientation                 = 0,
    .horizontalResolution        = 480,
    .verticalResolution          = 320,
};

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="DRV_SDMMC Instance 0 Initialization Data">

/* SDMMC Client Objects Pool */
static DRV_SDMMC_CLIENT_OBJ drvSDMMC0ClientObjPool[DRV_SDMMC_CLIENTS_NUMBER_IDX0];

/* SDMMC Transfer Objects Pool */
static DRV_SDMMC_BUFFER_OBJ drvSDMMC0BufferObjPool[DRV_SDMMC_QUEUE_SIZE_IDX0];


const DRV_SDMMC_PLIB_API drvSDMMC0PlibAPI = {
    .sdhostCallbackRegister = (DRV_SDMMC_PLIB_CALLBACK_REGISTER)SDHC1_CallbackRegister,
    .sdhostInitModule = (DRV_SDMMC_PLIB_INIT_MODULE)SDHC1_ModuleInit,
    .sdhostSetClock  = (DRV_SDMMC_PLIB_SET_CLOCK)SDHC1_ClockSet,
    .sdhostIsCmdLineBusy = (DRV_SDMMC_PLIB_IS_CMD_LINE_BUSY)SDHC1_IsCmdLineBusy,
    .sdhostIsDatLineBusy = (DRV_SDMMC_PLIB_IS_DATA_LINE_BUSY)SDHC1_IsDatLineBusy,
    .sdhostSendCommand = (DRV_SDMMC_PLIB_SEND_COMMAND)SDHC1_CommandSend,
    .sdhostReadResponse = (DRV_SDMMC_PLIB_READ_RESPONSE)SDHC1_ResponseRead,
    .sdhostSetBlockCount = (DRV_SDMMC_PLIB_SET_BLOCK_COUNT)SDHC1_BlockCountSet,
    .sdhostSetBlockSize = (DRV_SDMMC_PLIB_SET_BLOCK_SIZE)SDHC1_BlockSizeSet,
    .sdhostSetBusWidth = (DRV_SDMMC_PLIB_SET_BUS_WIDTH)SDHC1_BusWidthSet,
    .sdhostSetSpeedMode = (DRV_SDMMC_PLIB_SET_SPEED_MODE)SDHC1_SpeedModeSet,
    .sdhostSetupDma = (DRV_SDMMC_PLIB_SETUP_DMA)SDHC1_DmaSetup,
    .sdhostGetCommandError = (DRV_SDMMC_PLIB_GET_COMMAND_ERROR)SDHC1_CommandErrorGet,
    .sdhostGetDataError = (DRV_SDMMC_PLIB_GET_DATA_ERROR)SDHC1_DataErrorGet,
    .sdhostClockEnable = (DRV_SDMMC_PLIB_CLOCK_ENABLE)SDHC1_ClockEnable,
    .sdhostResetError = (DRV_SDMMC_PLIB_RESET_ERROR)SDHC1_ErrorReset,
    .sdhostIsCardAttached = (DRV_SDMMC_PLIB_IS_CARD_ATTACHED)SDHC1_IsCardAttached,
    .sdhostIsWriteProtected = (DRV_SDMMC_PLIB_IS_WRITE_PROTECTED)NULL,
};

/*** SDMMC Driver Initialization Data ***/
const DRV_SDMMC_INIT drvSDMMC0InitData =
{
    .sdmmcPlib                      = &drvSDMMC0PlibAPI,
    .bufferObjPool                  = (uintptr_t)&drvSDMMC0BufferObjPool[0],
    .bufferObjPoolSize              = DRV_SDMMC_QUEUE_SIZE_IDX0,
    .clientObjPool                  = (uintptr_t)&drvSDMMC0ClientObjPool[0],
    .numClients                     = DRV_SDMMC_CLIENTS_NUMBER_IDX0,
    .protocol                       = DRV_SDMMC_PROTOCOL_SUPPORT_IDX0,
    .cardDetectionMethod            = DRV_SDMMC_CARD_DETECTION_METHOD_IDX0,
    .cardDetectionPollingIntervalMs = 0,
    .isWriteProtectCheckEnabled     = false,
    .speedMode                      = DRV_SDMMC_CONFIG_SPEED_MODE_IDX0,
    .busWidth                       = DRV_SDMMC_CONFIG_BUS_WIDTH_IDX0,
	.sleepWhenIdle 					= false,
    .isFsEnabled                    = true,
};

// </editor-fold>

/*** CODEC Driver Initialization Data ***/
const DRV_WM8904_INIT drvwm8904Codec0InitData =
{
    .masterMode = DRV_WM8904_MASTER_MODE,
    .samplingRate = DRV_WM8904_AUDIO_SAMPLING_RATE,
    .volume = DRV_WM8904_VOLUME,
    .audioDataFormat = DRV_WM8904_AUDIO_DATA_FORMAT_MACRO,
    .enableMicInput = DRV_WM8904_ENABLE_MIC_INPUT,
    .enableMicBias = DRV_WM8904_ENABLE_MIC_BIAS,
    .micGain = DRV_WM8904_MIC_GAIN
};



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
/******************************************************
 * USB Driver Initialization
 ******************************************************/
 


void _DRV_USB_VBUSPowerEnable(uint8_t port, bool enable)
{
	/* Note: When operating in Host mode, the application can specify a Root 
	   hub port enable function. The USB Host Controller driver initialize data 
	   structure has a member for specifying the root hub enable function. 
	   This parameter should point to Root hub port enable function. If this 
	   parameter is NULL, it implies that the port is always enabled. 
	   
	   This function generated by MHC to let the user enable the root hub. 
	   User must use the MHC pin configuration utility to configure the pin 
	   used for enabling VBUS  */
    if (enable == true)
	{
		/* Enable the VBUS */
		VBUS_PowerEnable();
	}
	else
	{
		/* Disable the VBUS */
		VBUS_PowerDisable();
	}
}

const DRV_USBFSV1_INIT drvUSBInit =
{
	/* Interrupt Source for USB module */
	.interruptSource = USB_OTHER_IRQn,
 
	/* Interrupt Source for USB module */
	.interruptSource1 = USB_SOF_HSOF_IRQn,
 
	/* Interrupt Source for USB module */
	.interruptSource2 = USB_TRCPT0_IRQn,
 
	/* Interrupt Source for USB module */
	.interruptSource3 = USB_TRCPT1_IRQn,

    /* System module initialization */
    .moduleInit = {0},

	/* USB Controller to operate as USB Host */
    .operationMode = DRV_USBFSV1_OPMODE_HOST,

    /* USB Full Speed Operation */
	.operationSpeed = USB_SPEED_FULL,
    
    /* Stop in idle */
    .runInStandby = true,

    /* Suspend in sleep */
    .suspendInSleep = false,

    /* Identifies peripheral (PLIB-level) ID */
    .usbID = USB_REGS,
	
	/* Function to check for VBus */
    .vbusComparator = NULL,
       
    /* USB Host Power Enable. USB Driver uses this function to Enable the VBUS */ 
    .portPowerEnable = _DRV_USB_VBUSPowerEnable,
	
    /* Root hub available current in milliamperes */
    .rootHubAvailableCurrent = 500,
};


// <editor-fold defaultstate="collapsed" desc="File System Initialization Data">

const SYS_FS_MEDIA_MOUNT_DATA sysfsMountTable[SYS_FS_VOLUME_NUMBER] =
{
    {
        .mountName = SYS_FS_MEDIA_IDX0_MOUNT_NAME_VOLUME_IDX0,
        .devName   = SYS_FS_MEDIA_IDX0_DEVICE_NAME_VOLUME_IDX0,
        .mediaType = SYS_FS_MEDIA_TYPE_IDX0,
        .fsType   = SYS_FS_TYPE_IDX0
    },
    {
        .mountName = SYS_FS_MEDIA_IDX1_MOUNT_NAME_VOLUME_IDX0,
        .devName   = SYS_FS_MEDIA_IDX1_DEVICE_NAME_VOLUME_IDX0,
        .mediaType = SYS_FS_MEDIA_TYPE_IDX1,
        .fsType   = SYS_FS_TYPE_IDX1
    },
};


const SYS_FS_FUNCTIONS FatFsFunctions =
{
    .mount             = FATFS_mount,
    .unmount           = FATFS_unmount,
    .open              = FATFS_open,
    .read              = FATFS_read,
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
    .write             = FATFS_write,
    .tell              = FATFS_tell,
    .eof               = FATFS_eof,
    .size              = FATFS_size,
    .mkdir             = FATFS_mkdir,
    .remove            = FATFS_unlink,
    .setlabel          = FATFS_setlabel,
    .truncate          = FATFS_truncate,
    .chmode            = FATFS_chmod,
    .chtime            = FATFS_utime,
    .rename            = FATFS_rename,
    .sync              = FATFS_sync,
    .putchr            = FATFS_putc,
    .putstrn           = FATFS_puts,
    .formattedprint    = FATFS_printf,
    .testerror         = FATFS_error,
    .formatDisk        = (FORMAT_DISK)FATFS_mkfs,
    .partitionDisk     = FATFS_fdisk,
    .getCluster        = FATFS_getclusters
};


const SYS_FS_REGISTRATION_TABLE sysFSInit [ SYS_FS_MAX_FILE_SYSTEM_TYPE ] =
{
    {
        .nativeFileSystemType = FAT,
        .nativeFileSystemFunctions = &FatFsFunctions
    }
};

// </editor-fold>



// *****************************************************************************
// *****************************************************************************
// Section: System Initialization
// *****************************************************************************
// *****************************************************************************
// <editor-fold defaultstate="collapsed" desc="SYS_TIME Initialization Data">

const SYS_TIME_PLIB_INTERFACE sysTimePlibAPI = {
    .timerCallbackSet = (SYS_TIME_PLIB_CALLBACK_REGISTER)TC0_TimerCallbackRegister,
    .timerStart = (SYS_TIME_PLIB_START)TC0_TimerStart,
    .timerStop = (SYS_TIME_PLIB_STOP)TC0_TimerStop,
    .timerFrequencyGet = (SYS_TIME_PLIB_FREQUENCY_GET)TC0_TimerFrequencyGet,
    .timerPeriodSet = (SYS_TIME_PLIB_PERIOD_SET)TC0_Timer16bitPeriodSet,
    .timerCompareSet = (SYS_TIME_PLIB_COMPARE_SET)TC0_Timer16bitCompareSet,
    .timerCounterGet = (SYS_TIME_PLIB_COUNTER_GET)TC0_Timer16bitCounterGet,
};

const SYS_TIME_INIT sysTimeInitData =
{
    .timePlib = &sysTimePlibAPI,
    .hwTimerIntNum = TC0_IRQn,
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

    /* Make stdin unbuffered */
    setbuf(stdin, NULL);

    /* Make stdout unbuffered */
    setbuf(stdout, NULL);
}




/*******************************************************************************
  Function:
    void SYS_Initialize ( void *data )

  Summary:
    Initializes the board, services, drivers, application and other modules.

  Remarks:
 */

void SYS_Initialize ( void* data )
{
    STDIO_BufferModeSet();


  
    PORT_Initialize();

    CLOCK_Initialize();




    TC0_TimerInitialize();

	SDHC1_Initialize();

    TC4_CompareInitialize();

    SERCOM1_USART_Initialize();

    EVSYS_Initialize();

    SERCOM6_I2C_Initialize();

    DMAC_Initialize();

    SERCOM4_I2C_Initialize();

	BSP_Initialize();
    I2S_Initialize();

    /* Initialize I2C0 Driver Instance */
    sysObj.drvI2C0 = DRV_I2C_Initialize(DRV_I2C_INDEX_0, (SYS_MODULE_INIT *)&drvI2C0InitData);
    /* Initialize I2C1 Driver Instance */
    sysObj.drvI2C1 = DRV_I2C_Initialize(DRV_I2C_INDEX_1, (SYS_MODULE_INIT *)&drvI2C1InitData);
    /* Initialize I2S0 Driver Instance */
    sysObj.drvI2S0 = DRV_I2S_Initialize(DRV_I2S_INDEX_0, (SYS_MODULE_INIT *)&drvI2S0InitData);


    sysObj.drvMAXTOUCH = DRV_MAXTOUCH_Initialize(0, (SYS_MODULE_INIT *)&drvMAXTOUCHInitData);

    CCL_Initialize();

    DRV_ILI9488_Initialize();


    sysObj.drvSDMMC0 = DRV_SDMMC_Initialize(DRV_SDMMC_INDEX_0,(SYS_MODULE_INIT *)&drvSDMMC0InitData);

    sysObj.drvwm8904Codec0 = DRV_WM8904_Initialize(DRV_WM8904_INDEX_0, (SYS_MODULE_INIT *)&drvwm8904Codec0InitData);


    sysObj.sysTime = SYS_TIME_Initialize(SYS_TIME_INDEX_0, (SYS_MODULE_INIT *)&sysTimeInitData);

    SYS_INP_Init();


	/* Initialize the USB Host layer */
    sysObj.usbHostObject0 = USB_HOST_Initialize (( SYS_MODULE_INIT *)& usbHostInitData );	

	/* Initialize USB Driver */ 
    sysObj.drvUSBFSV1Object = DRV_USBFSV1_Initialize(DRV_USBFSV1_INDEX_0, (SYS_MODULE_INIT *) &drvUSBInit);	

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END
    // initialize UI library
    Legato_Initialize();

    /*** File System Service Initialization Code ***/
    SYS_FS_Initialize( (const void *) sysFSInit );


    APP_Initialize();


    NVIC_Initialize();

}


/*******************************************************************************
 End of File
*/
