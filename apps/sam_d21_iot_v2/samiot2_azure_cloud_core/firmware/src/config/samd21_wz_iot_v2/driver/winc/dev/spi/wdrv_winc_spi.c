/*******************************************************************************
  WINC Wireless Driver SPI Communication Support

  File Name:
    wdrv_winc_spi.c

  Summary:
    WINC Wireless Driver SPI Communications Support

  Description:
    Supports SPI communications to the WINC module.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019-22 Microchip Technology Inc. and its subsidiaries.
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

#include "configuration.h"
#include "definitions.h"
#include "osal/osal.h"
#include "driver/spi/drv_spi.h"
#include "wdrv_winc_common.h"
#include "wdrv_winc_spi.h"

#ifdef USE_CACHE_MAINTENANCE
/* Cache Management to be enabled in core & system components of MHC Project Graph*/
#include "system/cache/sys_cache.h"
#include "sys/kmem.h"
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Data Type Definitions
// *****************************************************************************
// *****************************************************************************

#if defined(__PIC32MZ__) && defined(USE_CACHE_MAINTENANCE)
#define SPI_DMA_DCACHE_CLEAN(addr, size) _DataCacheClean(addr, size)
#else
#define SPI_DMA_DCACHE_CLEAN(addr, size) do { } while (0)
#endif

typedef struct
{
    /* This is the SPI configuration. */
    WDRV_WINC_SPI_CFG       cfg;
    DRV_HANDLE              spiHandle;
    DRV_SPI_TRANSFER_HANDLE transferTxHandle;
    DRV_SPI_TRANSFER_HANDLE transferRxHandle;
    OSAL_SEM_HANDLE_TYPE    txSyncSem;
    OSAL_SEM_HANDLE_TYPE    rxSyncSem;
} WDRV_WINC_SPIDCPT;

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************

static WDRV_WINC_SPIDCPT spiDcpt;

#if defined(__PIC32MZ__) && defined(USE_CACHE_MAINTENANCE)
/****************************************************************************
 * Function:        _DataCacheClean
 * Summary: Used in Cache management to clean cache based on address.
 * Cache Management to be enabled in core & system components of MHC.
 *****************************************************************************/
static void _DataCacheClean(unsigned char *address, uint32_t size)
{
    if (IS_KVA0(address))
    {
        uint32_t a = (uint32_t)address & 0xfffffff0;
        uint32_t r = (uint32_t)address & 0x0000000f;
        uint32_t s = ((size + r + 15) >> 4) << 4;

        SYS_CACHE_CleanDCache_by_Addr((uint32_t *)a, s);
    }
}
#endif

// *****************************************************************************
// *****************************************************************************
// Section: File scope functions
// *****************************************************************************
// *****************************************************************************

static void _WDRV_WINC_SPITransferEventHandler(DRV_SPI_TRANSFER_EVENT event,
        DRV_SPI_TRANSFER_HANDLE handle, uintptr_t context)
{
    switch(event)
    {
        case DRV_SPI_TRANSFER_EVENT_COMPLETE:
            // This means the data was transferred.
            if (spiDcpt.transferTxHandle == handle)
            {
                OSAL_SEM_PostISR(&spiDcpt.txSyncSem);
            }
            else if (spiDcpt.transferRxHandle == handle)
            {
                OSAL_SEM_PostISR(&spiDcpt.rxSyncSem);
            }

            break;

        case DRV_SPI_TRANSFER_EVENT_ERROR:
            // Error handling here.
            break;

        default:
            break;
    }
}

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_SPISend(void* pTransmitData, size_t txSize)

  Summary:
    Sends data out to the module through the SPI bus.

  Description:
    This function sends data out to the module through the SPI bus.

  Remarks:
    See wdrv_winc_spi.h for usage information.
 */

bool WDRV_WINC_SPISend(void* pTransmitData, size_t txSize)
{
    SPI_DMA_DCACHE_CLEAN(pTransmitData, txSize);

    DRV_SPI_WriteTransferAdd(spiDcpt.spiHandle, pTransmitData, txSize, &spiDcpt.transferTxHandle);

    if (DRV_SPI_TRANSFER_HANDLE_INVALID == spiDcpt.transferTxHandle)
    {
        return false;
    }

    while (OSAL_RESULT_FALSE == OSAL_SEM_Pend(&spiDcpt.txSyncSem, OSAL_WAIT_FOREVER))
    {
    }

    return true;
}

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_SPIReceive(void* pReceiveData, size_t rxSize)

  Summary:
    Receives data from the module through the SPI bus.

  Description:
    This function receives data from the module through the SPI bus.

  Remarks:
    See wdrv_winc_spi.h for usage information.
 */

bool WDRV_WINC_SPIReceive(void* pReceiveData, size_t rxSize)
{
    static uint8_t dummy = 0;

    SPI_DMA_DCACHE_CLEAN(pReceiveData, rxSize);

    DRV_SPI_WriteReadTransferAdd(spiDcpt.spiHandle, &dummy, 1, pReceiveData, rxSize, &spiDcpt.transferRxHandle);

    if (DRV_SPI_TRANSFER_HANDLE_INVALID == spiDcpt.transferRxHandle)
    {
        return false;
    }

    while (OSAL_RESULT_FALSE == OSAL_SEM_Pend(&spiDcpt.rxSyncSem, OSAL_WAIT_FOREVER))
    {
    }

    return true;
}

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_SPIOpen(void)

  Summary:
    Opens the SPI object for the WiFi driver.

  Description:
    This function opens the SPI object for the WiFi driver.

  Remarks:
    See wdrv_winc_spi.h for usage information.
 */

void WDRV_WINC_SPIOpen(void)
{
    if (OSAL_RESULT_TRUE != OSAL_SEM_Create(&spiDcpt.txSyncSem, OSAL_SEM_TYPE_COUNTING, 10, 0))
    {
        return;
    }

    if (OSAL_RESULT_TRUE != OSAL_SEM_Create(&spiDcpt.rxSyncSem, OSAL_SEM_TYPE_COUNTING, 10, 0))
    {
        return;
    }

    if (DRV_HANDLE_INVALID == spiDcpt.spiHandle)
    {
        spiDcpt.spiHandle = DRV_SPI_Open(spiDcpt.cfg.drvIndex, DRV_IO_INTENT_READWRITE | DRV_IO_INTENT_BLOCKING);

        if (DRV_HANDLE_INVALID == spiDcpt.spiHandle)
        {
            WDRV_DBG_ERROR_PRINT("SPI open failed\r\n");
        }
    }

    DRV_SPI_TransferEventHandlerSet(spiDcpt.spiHandle, _WDRV_WINC_SPITransferEventHandler, 0);
}

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_SPIInitialize(const WDRV_WINC_SPI_CFG *const pInitData)

  Summary:
    Initializes the SPI object for the WiFi driver.

  Description:
    This function initializes the SPI object for the WiFi driver.

  Remarks:
    See wdrv_winc_spi.h for usage information.
 */

void WDRV_WINC_SPIInitialize(const WDRV_WINC_SPI_CFG *const pInitData)
{
    if (NULL == pInitData)
    {
        return;
    }

    memcpy(&spiDcpt.cfg, pInitData, sizeof(WDRV_WINC_SPI_CFG));

    spiDcpt.spiHandle = DRV_HANDLE_INVALID;
}

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_SPIDeinitialize(void)

  Summary:
    Deinitializes the SPI object for the WiFi driver.

  Description:
    This function deinitializes the SPI object for the WiFi driver.

  Remarks:
    See wdrv_winc_spi.h for usage information.
 */

void WDRV_WINC_SPIDeinitialize(void)
{
    OSAL_SEM_Post(&spiDcpt.txSyncSem);
    OSAL_SEM_Delete(&spiDcpt.txSyncSem);

    OSAL_SEM_Post(&spiDcpt.rxSyncSem);
    OSAL_SEM_Delete(&spiDcpt.rxSyncSem);
}

//DOM-IGNORE-END
