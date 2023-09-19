/*******************************************************************************
  WINC Driver Host File Download Implementation

  File Name:
    wdrv_winc_host_file.c

  Summary:
    WINC wireless driver host file download implementation.

  Description:
    This file provides an interface for downloading files into the WINCs
      internal flash memory for later retrieval by the host MCU.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*
Copyright (C) 2019, Microchip Technology Inc., and its subsidiaries. All rights reserved.

The software and documentation is provided by microchip and its contributors
"as is" and any express, implied or statutory warranties, including, but not
limited to, the implied warranties of merchantability, fitness for a particular
purpose and non-infringement of third party intellectual property rights are
disclaimed to the fullest extent permitted by law. In no event shall microchip
or its contributors be liable for any direct, indirect, incidental, special,
exemplary, or consequential damages (including, but not limited to, procurement
of substitute goods or services; loss of use, data, or profits; or business
interruption) however caused and on any theory of liability, whether in contract,
strict liability, or tort (including negligence or otherwise) arising in any way
out of the use of the software and documentation, even if advised of the
possibility of such damage.

Except as expressly permitted hereunder and subject to the applicable license terms
for any third-party software incorporated in the software and any applicable open
source software license terms, no license or other rights, whether express or
implied, are granted under any patent or other intellectual property rights of
Microchip or any third party.
*/
//DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>

#include "wdrv_winc.h"
#include "wdrv_winc_common.h"
#include "wdrv_winc_host_file.h"
#ifdef WDRV_WINC_DEVICE_LITE_DRIVER
#include "include/winc.h"
#else
#include "spi_flash.h"
#ifdef WDRV_WINC_DEVICE_FLEXIBLE_FLASH_MAP
#include "flexible_flash.h"
#endif
#include "spi_flash_map.h"
#endif

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver Host File Download Implementations
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_HostFileDownload
    (
        DRV_HANDLE handle,
        const char *pFileURL,
        const WDRV_WINC_HOST_FILE_STATUS_CALLBACK pfHostFileGetCB
    );

  Summary:
    Request the WINC downloads a file to it's internal flash memory.

  Description:
    Makes a request to the WINC device to begin downloading the specified
      file from the URL provided to the internal flash memory of the WINC device.

  Remarks:
    See wdrv_winc_host_flle.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_HostFileDownload
(
    DRV_HANDLE handle,
    const char *pFileURL,
    const WDRV_WINC_HOST_FILE_STATUS_CALLBACK pfHostFileGetCB
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    WDRV_WINC_HOST_FILE_DCPT *pHostFileDcpt;

    /* Ensure the driver handle and file URL are valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl)
        || (NULL == pFileURL) || (NULL == pfHostFileGetCB))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    /* Ensure WINC is connected. */
    if (false == pDcpt->pCtrl->isConnected)
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    pHostFileDcpt = &pDcpt->pCtrl->hostFileDcpt;

    if (OSAL_RESULT_TRUE != OSAL_SEM_Pend(&pHostFileDcpt->hfdSemaphore, OSAL_WAIT_FOREVER))
    {
        return WDRV_WINC_STATUS_RESOURCE_LOCK_ERROR;
    }

    pHostFileDcpt->handle = HFD_INVALID_HANDLER;
    pHostFileDcpt->size   = 0;

    if (M2M_ERR_FAIL == m2m_ota_host_file_get((char*)pFileURL, pHostFileDcpt->getFileCB))
    {
        OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    pDcpt->pCtrl->pfHostFileCB = pfHostFileGetCB;

    OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_HostFileRead
    (
        DRV_HANDLE handle,
        WDRV_WINC_HOST_FILE_HANDLE fileHandle,
        void *pBuffer,
        uint32_t bufferSize,
        uint32_t offset,
        uint32_t size,
        const WDRV_WINC_HOST_FILE_STATUS_CALLBACK pfHostFileReadStatusCB
    );

  Summary:
    Requests to read the data from a downloaded file.

  Description:
    Makes a request to the WINC device to provide the data from a file
      previously downloaded into internal flash memory.

  Remarks:
    See wdrv_winc_host_flle.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_HostFileRead
(
    DRV_HANDLE handle,
    WDRV_WINC_HOST_FILE_HANDLE fileHandle,
    void *pBuffer,
    uint32_t bufferSize,
    uint32_t offset,
    uint32_t size,
    const WDRV_WINC_HOST_FILE_STATUS_CALLBACK pfHostFileReadStatusCB
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    WDRV_WINC_HOST_FILE_DCPT *const pHostFileDcpt
                                    = (WDRV_WINC_HOST_FILE_DCPT *const)fileHandle;
    uint32_t hifSize;

    /* Ensure the driver handle and file handle are valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl) || (NULL == pHostFileDcpt))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    if (OSAL_RESULT_TRUE != OSAL_SEM_Pend(&pHostFileDcpt->hfdSemaphore, OSAL_WAIT_FOREVER))
    {
        return WDRV_WINC_STATUS_RESOURCE_LOCK_ERROR;
    }

    /* Ensure the file handle is valid. */
    if ((pHostFileDcpt != &pDcpt->pCtrl->hostFileDcpt) ||
                                (HFD_INVALID_HANDLER == pHostFileDcpt->handle))
    {
        OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    pDcpt->pCtrl->pfHostFileCB = NULL;

    if (NULL != pBuffer)
    {
        pHostFileDcpt->pBuffer      = pBuffer;
        pHostFileDcpt->bufferSpace  = bufferSize;
        pHostFileDcpt->offset       = offset;
        pHostFileDcpt->remain       = size;
    }

    if ((0 != pHostFileDcpt->size) && (pHostFileDcpt->offset >= pHostFileDcpt->size))
    {
        OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    if (0 != (pDcpt->pCtrl->intent & DRV_IO_INTENT_EXCLUSIVE))
    {
            WDRV_WINC_STATUS status;

#ifdef WDRV_WINC_DEVICE_WINC1500
            /* Ensure flash is out of power save mode. */
            if (M2M_SUCCESS != spi_flash_enable(1))
            {
                OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);
                return WDRV_WINC_STATUS_REQUEST_ERROR;
            }
#endif
            status = m2m_ota_host_file_read_spi(pHostFileDcpt->handle, pBuffer, offset, size);

#ifdef WDRV_WINC_DEVICE_WINC1500
            /* Return flash to power save mode. */
            if (M2M_SUCCESS != spi_flash_enable(0))
            {
                OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);
                return WDRV_WINC_STATUS_REQUEST_ERROR;
            }
#endif
            if (M2M_SUCCESS != status)
            {
                OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);
                return WDRV_WINC_STATUS_REQUEST_ERROR;
            }
    }
    else
    {
        hifSize = pHostFileDcpt->remain;
        if (hifSize > 128)
        {
            hifSize = 128;
        }

        if (M2M_SUCCESS != m2m_ota_host_file_read_hif(pHostFileDcpt->handle,
                    pHostFileDcpt->offset, hifSize, pHostFileDcpt->readFileCB))
        {
            OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);
            return WDRV_WINC_STATUS_REQUEST_ERROR;
        }

        pDcpt->pCtrl->pfHostFileCB = pfHostFileReadStatusCB;
    }

    OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_HostFileErase
    (
        DRV_HANDLE handle,
        WDRV_WINC_HOST_FILE_HANDLE fileHandle,
        const WDRV_WINC_HOST_FILE_STATUS_CALLBACK pfHostFileEraseStatusCB
    );

  Summary:
    Requests to erase a downloaded file.

  Description:
    Makes a request to the WINC device to erase the specified file from it's
      internal flash memory.

  Remarks:
    See wdrv_winc_host_flle.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_HostFileErase
(
    DRV_HANDLE handle,
    WDRV_WINC_HOST_FILE_HANDLE fileHandle,
    const WDRV_WINC_HOST_FILE_STATUS_CALLBACK pfHostFileEraseStatusCB
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    WDRV_WINC_HOST_FILE_DCPT *const pHostFileDcpt
                                = (WDRV_WINC_HOST_FILE_DCPT *const)fileHandle;

    /* Ensure the driver handle and file handle are valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl) || (NULL == pHostFileDcpt))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    if (OSAL_RESULT_TRUE != OSAL_SEM_Pend(&pHostFileDcpt->hfdSemaphore, OSAL_WAIT_FOREVER))
    {
        return WDRV_WINC_STATUS_RESOURCE_LOCK_ERROR;
    }

    if (0 != (pDcpt->pCtrl->intent & DRV_IO_INTENT_EXCLUSIVE))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }
    else
    {
        /* Ensure the file handle is valid. */
        if ((pHostFileDcpt != &pDcpt->pCtrl->hostFileDcpt) ||
                                    (HFD_INVALID_HANDLER == pHostFileDcpt->handle))
        {
            OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);
            return WDRV_WINC_STATUS_INVALID_ARG;
        }

        if (M2M_ERR_FAIL == m2m_ota_host_file_erase(pHostFileDcpt->handle,
                                                        pHostFileDcpt->eraseFileCB))
        {
            OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);
            return WDRV_WINC_STATUS_REQUEST_ERROR;
        }
    }

    pDcpt->pCtrl->pfHostFileCB = pfHostFileEraseStatusCB;

    OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_HOST_FILE_HANDLE WDRV_WINC_HostFileFindByID
    (
        DRV_HANDLE handle,
        uint8_t id
    );

  Summary:
    Maps a file ID to a driver file handle.

  Description:
    The WINC uses a file handle ID to refer to files, this function maps
      that ID to a file handle object which can be used with the WINC driver API.

  Remarks:
    See wdrv_winc_host_flle.h for usage information.

*/

WDRV_WINC_HOST_FILE_HANDLE WDRV_WINC_HostFileFindByID
(
    DRV_HANDLE handle,
    uint8_t id
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)handle;
    WDRV_WINC_HOST_FILE_DCPT *pHostFileDcpt;
    uint8_t currentId;

    /* Ensure the driver handle and file handle are valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl) || (HFD_INVALID_HANDLER == id))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    pHostFileDcpt = &pDcpt->pCtrl->hostFileDcpt;

    if (OSAL_RESULT_TRUE != OSAL_SEM_Pend(&pHostFileDcpt->hfdSemaphore, OSAL_WAIT_FOREVER))
    {
        return WDRV_WINC_STATUS_RESOURCE_LOCK_ERROR;
    }

    if (HFD_INVALID_HANDLER == pHostFileDcpt->handle)
    {
        if (0 != (pDcpt->pCtrl->intent & DRV_IO_INTENT_EXCLUSIVE))
        {
            uint8_t flashBuffer[8];
            uint32_t flashStart = 0;
            uint32_t flashSize  = 0;

            pHostFileDcpt->handle = HFD_INVALID_HANDLER;
            pHostFileDcpt->size   = 0;

#ifdef WDRV_WINC_DEVICE_WINC1500
            /* Ensure flash is out of power save mode. */
            if (M2M_SUCCESS != spi_flash_enable(1))
            {
                OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);
                return WDRV_WINC_STATUS_REQUEST_ERROR;
            }
#endif
            if (M2M_SUCCESS == spi_flexible_flash_find_section(ENTRY_ID_HOSTFILE, &flashStart, &flashSize))
            {
                spi_flash_read(flashBuffer, flashStart, 8);

                pHostFileDcpt->handle = flashBuffer[0];
                pHostFileDcpt->size   = *(uint32_t*)&flashBuffer[4];
            }

#ifdef WDRV_WINC_DEVICE_WINC1500
            /* Return flash to power save mode. */
            if (M2M_SUCCESS != spi_flash_enable(0))
            {
                OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);
                return WDRV_WINC_STATUS_REQUEST_ERROR;
            }
#endif
        }
        else
        {
            pHostFileDcpt->handle = m2m_ota_host_file_get_id();
        }
    }

    currentId = pHostFileDcpt->handle;

    OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);

    if (id == currentId)
    {
        return (WDRV_WINC_HOST_FILE_HANDLE)pHostFileDcpt;
    }

    return WDRV_WINC_HOST_FILE_INVALID_HANDLE;
}

//*******************************************************************************
/*
  Function:
    uint32_t WDRV_WINC_HostFileGetSize(const WDRV_WINC_HOST_FILE_HANDLE fileHandle);

  Summary:
    Retrieves the file size from a file handle.

  Description:
    Given a driver file handle this function will retrieve the file size in bytes.

  Remarks:
    See wdrv_winc_host_flle.h for usage information.

*/

uint32_t WDRV_WINC_HostFileGetSize(const WDRV_WINC_HOST_FILE_HANDLE fileHandle)
{
    uint32_t size = 0;
    WDRV_WINC_HOST_FILE_DCPT *const pHostFileDcpt
                                = (WDRV_WINC_HOST_FILE_DCPT *const)fileHandle;

    if (NULL == pHostFileDcpt)
    {
        return 0;
    }

    if (OSAL_RESULT_TRUE != OSAL_SEM_Pend(&pHostFileDcpt->hfdSemaphore, OSAL_WAIT_FOREVER))
    {
        return 0;
    }

    if (HFD_INVALID_HANDLER != pHostFileDcpt->handle)
    {
        size = pHostFileDcpt->size;
    }

    OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);

    return size;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_HostFileUpdateReadBuffer
    (
        const WDRV_WINC_HOST_FILE_HANDLE fileHandle,
        void *pBuffer,
        uint32_t bufferSize
    );

  Summary:
    Update the read buffer.

  Description:
    Update the buffer associated with a read file operation.

  Remarks:
    See wdrv_winc_host_flle.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_HostFileUpdateReadBuffer
(
    const WDRV_WINC_HOST_FILE_HANDLE fileHandle,
    void *pBuffer,
    uint32_t bufferSize
)
{
    WDRV_WINC_HOST_FILE_DCPT *const pHostFileDcpt
                                = (WDRV_WINC_HOST_FILE_DCPT *const)fileHandle;

    if ((NULL == pHostFileDcpt) || (NULL == pBuffer) || (0 == bufferSize))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    if (OSAL_RESULT_TRUE != OSAL_SEM_Pend(&pHostFileDcpt->hfdSemaphore, OSAL_WAIT_FOREVER))
    {
        return WDRV_WINC_STATUS_RESOURCE_LOCK_ERROR;
    }

    if (HFD_INVALID_HANDLER != pHostFileDcpt->handle)
    {
        pHostFileDcpt->pBuffer      = pBuffer;
        pHostFileDcpt->bufferSpace  = bufferSize;
    }

    OSAL_SEM_Post(&pHostFileDcpt->hfdSemaphore);

    return WDRV_WINC_STATUS_OK;
}
