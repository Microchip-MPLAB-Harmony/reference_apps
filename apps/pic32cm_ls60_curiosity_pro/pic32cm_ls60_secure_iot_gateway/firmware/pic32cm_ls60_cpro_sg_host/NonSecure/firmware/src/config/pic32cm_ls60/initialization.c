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


// *****************************************************************************
// *****************************************************************************
// Section: Driver Initialization Data
// *****************************************************************************
// *****************************************************************************
static const WDRV_WINC_SPI_CFG wdrvWincSpiInitData =
{
    .drvIndex           = DRV_SPI_INDEX_0,
    .baudRateInHz       = 1000000,
    .chipSelect         = SYS_PORT_PIN_NONE
};

static const WDRV_WINC_SYS_INIT wdrvWincInitData = {
    .pSPICfg    = &wdrvWincSpiInitData,
    .intSrc     = EIC_PIN_6
};

// <editor-fold defaultstate="collapsed" desc="DRV_SPI Instance 0 Initialization Data">

/* SPI Client Objects Pool */
static DRV_SPI_CLIENT_OBJ drvSPI0ClientObjPool[DRV_SPI_CLIENTS_NUMBER_IDX0];

/* SPI Transfer Objects Pool */
static DRV_SPI_TRANSFER_OBJ drvSPI0TransferObjPool[DRV_SPI_QUEUE_SIZE_IDX0];

/* SPI PLIB Interface Initialization */
const DRV_SPI_PLIB_INTERFACE drvSPI0PlibAPI = {

    /* SPI PLIB Setup */
    .setup = (DRV_SPI_PLIB_SETUP)SERCOM0_SPI_TransferSetup,

    /* SPI PLIB WriteRead function */
    .writeRead = (DRV_SPI_PLIB_WRITE_READ)SERCOM0_SPI_WriteRead,

    /* SPI PLIB Transfer Status function */
    .isTransmitterBusy = (DRV_SPI_PLIB_TRANSMITTER_IS_BUSY)SERCOM0_SPI_IsTransmitterBusy,

    /* SPI PLIB Callback Register */
    .callbackRegister = (DRV_SPI_PLIB_CALLBACK_REGISTER)SERCOM0_SPI_CallbackRegister,
};

const uint32_t drvSPI0remapDataBits[]= { 0x0, 0x1, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
const uint32_t drvSPI0remapClockPolarity[] = { 0x0, 0x20000000 };
const uint32_t drvSPI0remapClockPhase[] = { 0x10000000, 0x0 };

const DRV_SPI_INTERRUPT_SOURCES drvSPI0InterruptSources =
{
    /* Peripheral has more than one interrupt vectors */
    .isSingleIntSrc                        = false,

    /* Peripheral interrupt lines */
    .intSources.multi.spiTxReadyInt      = SERCOM0_0_IRQn,
    .intSources.multi.spiTxCompleteInt   = SERCOM0_1_IRQn,
    .intSources.multi.spiRxInt           = SERCOM0_2_IRQn,
    /* DMA Tx interrupt line */
    .intSources.multi.dmaTxChannelInt      = DMAC_0_IRQn,
    /* DMA Rx interrupt line */
    .intSources.multi.dmaRxChannelInt      = DMAC_1_IRQn,
};

/* SPI Driver Initialization Data */
const DRV_SPI_INIT drvSPI0InitData =
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
// <editor-fold defaultstate="collapsed" desc="DRV_SPI Instance 1 Initialization Data">

/* SPI Client Objects Pool */
static DRV_SPI_CLIENT_OBJ drvSPI1ClientObjPool[DRV_SPI_CLIENTS_NUMBER_IDX1];

/* SPI Transfer Objects Pool */
static DRV_SPI_TRANSFER_OBJ drvSPI1TransferObjPool[DRV_SPI_QUEUE_SIZE_IDX1];

/* SPI PLIB Interface Initialization */
const DRV_SPI_PLIB_INTERFACE drvSPI1PlibAPI = {

    /* SPI PLIB Setup */
    .setup = (DRV_SPI_PLIB_SETUP)SERCOM3_SPI_TransferSetup,

    /* SPI PLIB WriteRead function */
    .writeRead = (DRV_SPI_PLIB_WRITE_READ)SERCOM3_SPI_WriteRead,

    /* SPI PLIB Transfer Status function */
    .isTransmitterBusy = (DRV_SPI_PLIB_TRANSMITTER_IS_BUSY)SERCOM3_SPI_IsTransmitterBusy,

    /* SPI PLIB Callback Register */
    .callbackRegister = (DRV_SPI_PLIB_CALLBACK_REGISTER)SERCOM3_SPI_CallbackRegister,
};

const uint32_t drvSPI1remapDataBits[]= { 0x0, 0x1, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
const uint32_t drvSPI1remapClockPolarity[] = { 0x0, 0x20000000 };
const uint32_t drvSPI1remapClockPhase[] = { 0x10000000, 0x0 };

const DRV_SPI_INTERRUPT_SOURCES drvSPI1InterruptSources =
{
    /* Peripheral has more than one interrupt vectors */
    .isSingleIntSrc                        = false,

    /* Peripheral interrupt lines */
    .intSources.multi.spiTxReadyInt      = SERCOM3_0_IRQn,
    .intSources.multi.spiTxCompleteInt   = SERCOM3_1_IRQn,
    .intSources.multi.spiRxInt           = SERCOM3_2_IRQn,
};

/* SPI Driver Initialization Data */
const DRV_SPI_INIT drvSPI1InitData =
{
    /* SPI PLIB API */
    .spiPlib = &drvSPI1PlibAPI,

    .remapDataBits = drvSPI1remapDataBits,

    .remapClockPolarity = drvSPI1remapClockPolarity,

    .remapClockPhase = drvSPI1remapClockPhase,

    /* SPI Number of clients */
    .numClients = DRV_SPI_CLIENTS_NUMBER_IDX1,

    /* SPI Client Objects Pool */
    .clientObjPool = (uintptr_t)&drvSPI1ClientObjPool[0],

    /* DMA Channel for Transmit */
    .dmaChannelTransmit = SYS_DMA_CHANNEL_NONE,

    /* DMA Channel for Receive */
    .dmaChannelReceive  = SYS_DMA_CHANNEL_NONE,

    /* SPI Queue Size */
    .transferObjPoolSize = DRV_SPI_QUEUE_SIZE_IDX1,

    /* SPI Transfer Objects Pool */
    .transferObjPool = (uintptr_t)&drvSPI1TransferObjPool[0],

    /* SPI interrupt sources (SPI peripheral and DMA) */
    .interruptSources = &drvSPI1InterruptSources,
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


// *****************************************************************************
// *****************************************************************************
// Section: System Initialization
// *****************************************************************************
// *****************************************************************************
// <editor-fold defaultstate="collapsed" desc="SYS_TIME Initialization Data">

const SYS_TIME_PLIB_INTERFACE sysTimePlibAPI = {
    .timerCallbackSet = (SYS_TIME_PLIB_CALLBACK_REGISTER)TC2_TimerCallbackRegister,
    .timerStart = (SYS_TIME_PLIB_START)TC2_TimerStart,
    .timerStop = (SYS_TIME_PLIB_STOP)TC2_TimerStop,
    .timerFrequencyGet = (SYS_TIME_PLIB_FREQUENCY_GET)TC2_TimerFrequencyGet,
    .timerPeriodSet = (SYS_TIME_PLIB_PERIOD_SET)TC2_Timer16bitPeriodSet,
    .timerCompareSet = (SYS_TIME_PLIB_COMPARE_SET)TC2_Timer16bitCompareSet,
    .timerCounterGet = (SYS_TIME_PLIB_COUNTER_GET)TC2_Timer16bitCounterGet,
};

const SYS_TIME_INIT sysTimeInitData =
{
    .timePlib = &sysTimePlibAPI,
    .hwTimerIntNum = TC2_IRQn,
};

// </editor-fold>
// <editor-fold defaultstate="collapsed" desc="SYS_CONSOLE Instance 0 Initialization Data">


/* Declared in console device implementation (sys_console_uart.c) */
extern const SYS_CONSOLE_DEV_DESC sysConsoleUARTDevDesc;

const SYS_CONSOLE_UART_PLIB_INTERFACE sysConsole0UARTPlibAPI =
{
    .read = (SYS_CONSOLE_UART_PLIB_READ)SERCOM5_USART_Read,
	.readCountGet = (SYS_CONSOLE_UART_PLIB_READ_COUNT_GET)SERCOM5_USART_ReadCountGet,
	.readFreeBufferCountGet = (SYS_CONSOLE_UART_PLIB_READ_FREE_BUFFFER_COUNT_GET)SERCOM5_USART_ReadFreeBufferCountGet,
    .write = (SYS_CONSOLE_UART_PLIB_WRITE)SERCOM5_USART_Write,
	.writeCountGet = (SYS_CONSOLE_UART_PLIB_WRITE_COUNT_GET)SERCOM5_USART_WriteCountGet,
	.writeFreeBufferCountGet = (SYS_CONSOLE_UART_PLIB_WRITE_FREE_BUFFER_COUNT_GET)SERCOM5_USART_WriteFreeBufferCountGet,
};

const SYS_CONSOLE_UART_INIT_DATA sysConsole0UARTInitData =
{
    .uartPLIB = &sysConsole0UARTPlibAPI,    
};

const SYS_CONSOLE_INIT sysConsole0Init =
{
    .deviceInitData = (const void*)&sysConsole0UARTInitData,
    .consDevDesc = &sysConsoleUARTDevDesc,
    .deviceIndex = 0,
};



// </editor-fold>


const SYS_CMD_INIT sysCmdInit =
{
    .moduleInit = {0},
    .consoleCmdIOParam = SYS_CMD_SINGLE_CHARACTER_READ_CONSOLE_IO_PARAM,
	.consoleIndex = 0,
};




// *****************************************************************************
// *****************************************************************************
// Section: Local initialization functions
// *****************************************************************************
// *****************************************************************************



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

  



    RTC_Initialize();

    TC2_TimerInitialize();

    SERCOM3_SPI_Initialize();

    SERCOM2_USART_Initialize();

    SERCOM1_I2C_Initialize();

    SERCOM0_SPI_Initialize();

	SYSTICK_TimerInitialize();
    DMAC_Initialize();

    SERCOM5_USART_Initialize();

	BSP_Initialize();
    EIC_Initialize();


    /* Initialize the WINC Driver */
    sysObj.drvWifiWinc = WDRV_WINC_Initialize(0, (SYS_MODULE_INIT*)&wdrvWincInitData);

    /* Initialize SPI0 Driver Instance */
    sysObj.drvSPI0 = DRV_SPI_Initialize(DRV_SPI_INDEX_0, (SYS_MODULE_INIT *)&drvSPI0InitData);
    /* Initialize SPI1 Driver Instance */
    sysObj.drvSPI1 = DRV_SPI_Initialize(DRV_SPI_INDEX_1, (SYS_MODULE_INIT *)&drvSPI1InitData);
    DRV_SSD1351_Initialize();


    sysObj.sysTime = SYS_TIME_Initialize(SYS_TIME_INDEX_0, (SYS_MODULE_INIT *)&sysTimeInitData);
    sysObj.sysConsole0 = SYS_CONSOLE_Initialize(SYS_CONSOLE_INDEX_0, (SYS_MODULE_INIT *)&sysConsole0Init);

    SYS_CMD_Initialize((SYS_MODULE_INIT*)&sysCmdInit);


    SYS_INP_Init();


    // initialize UI library
    Legato_Initialize();


    APP_Initialize();       
    APP_SEC_Initialize();
    APP_TRANSFER_Initialize(); 

    NVIC_Initialize();  
    

    /* MISRAC 2012 deviation block end */
}


/*******************************************************************************
 End of File
*/
