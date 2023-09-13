/*******************************************************************************
  USART Driver Implementation.

  Company:
    Microchip Technology Inc.

  File Name:
    drv_usart.c

  Summary:
    Source code for the USART driver dynamic implementation.

  Description:
    This file contains the source code for the dynamic implementation of the
    USART driver.
*******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "configuration.h"
#include "driver/usart/drv_usart.h"
#include "drv_usart_local.h"


// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************

/* This is the driver instance object array. */
static DRV_USART_OBJ gDrvUSARTObj[DRV_USART_INSTANCES_NUMBER] ;

// *****************************************************************************
// *****************************************************************************
// Section: File scope functions
// *****************************************************************************
// *****************************************************************************

static inline uint32_t  lDRV_USART_MAKE_HANDLE(uint16_t token, uint8_t drvIndex, uint8_t clientIndex)
{
    return (((uint32_t)token << 16) | ((uint32_t)drvIndex << 8) | clientIndex);
}

static inline uint16_t lDRV_USART_UPDATE_TOKEN(uint16_t token)
{
    token++;

    if (token >= DRV_USART_TOKEN_MAX)
    {
        token = 1;
    }

    return token;
}

static void lDRV_USART_TX_PLIB_CallbackHandler( uintptr_t context )
{
    DRV_USART_OBJ *dObj = (DRV_USART_OBJ *)context;

    dObj->txRequestStatus = DRV_USART_REQUEST_STATUS_COMPLETE;

    (void) OSAL_SEM_PostISR(&dObj->txTransferDone);
}

static DRV_USART_ERROR lDRV_USART_GetErrorType(const uint32_t* remapError, uint32_t errorMask)
{
    uint32_t i;
    DRV_USART_ERROR error = DRV_USART_ERROR_NONE;

    for (i = 0U; i < 3U; i++)
    {
        if (remapError[i] == errorMask)
        {
            error = i+1U;
            break;
        }
    }
    return error;
}

static void lDRV_USART_RX_PLIB_CallbackHandler( uintptr_t context )
{
    DRV_USART_OBJ *dObj = (DRV_USART_OBJ *)context;
    DRV_USART_CLIENT_OBJ* clientObj = (DRV_USART_CLIENT_OBJ*)dObj->currentRxClient;
    uint32_t errorMask;

    errorMask = dObj->usartPlib->errorGet();

    if(errorMask == (uint32_t) DRV_USART_ERROR_NONE)
    {
        clientObj->errors = DRV_USART_ERROR_NONE;
        dObj->rxRequestStatus = DRV_USART_REQUEST_STATUS_COMPLETE;
    }
    else
    {
        clientObj->errors = lDRV_USART_GetErrorType(dObj->remapError, errorMask);
        dObj->rxRequestStatus = DRV_USART_REQUEST_STATUS_ERROR;
    }

    (void) OSAL_SEM_PostISR(&dObj->rxTransferDone);
}

static DRV_USART_CLIENT_OBJ* lDRV_USART_DriverHandleValidate(DRV_HANDLE handle)
{
    /* This function returns the pointer to the client object that is
       associated with this handle if the handle is valid. Returns NULL
       otherwise.
    */
    uint32_t drvInstance = 0;
    DRV_USART_CLIENT_OBJ* clientObj = NULL;

    if((handle != DRV_HANDLE_INVALID) && (handle != 0U))
    {
        /* Extract the instance value from the handle */
        drvInstance = ((handle & DRV_USART_INSTANCE_INDEX_MASK) >> 8);
        if (drvInstance >= (uint32_t)DRV_USART_INSTANCES_NUMBER)
        {
            return (NULL);
        }
        if ((handle & DRV_USART_CLIENT_INDEX_MASK) >= gDrvUSARTObj[drvInstance].nClientsMax)
        {
            return (NULL);
        }

        clientObj = &((DRV_USART_CLIENT_OBJ *)gDrvUSARTObj[drvInstance].clientObjPool)[handle & DRV_USART_CLIENT_INDEX_MASK];

        if ((handle != clientObj->clientHandle) || (clientObj->inUse == false))
        {
            return (NULL);
        }
    }

    return(clientObj);
}

// *****************************************************************************
// *****************************************************************************
// Section: USART Driver Common Interface Implementation
// *****************************************************************************
// *****************************************************************************

/* MISRA C-2012 Rule 11.1, 11.3, 11.8 deviated below. Deviation record IDs - H3_MISRAC_2012_R_11_1_DR_1, H3_MISRAC_2012_R_11_3_DR_1, H3_MISRAC_2012_R_11_8_DR_1*/
SYS_MODULE_OBJ DRV_USART_Initialize( const SYS_MODULE_INDEX drvIndex, const SYS_MODULE_INIT * const init )
{
    DRV_USART_OBJ *dObj = NULL;
    DRV_USART_INIT *usartInit = (DRV_USART_INIT *)init ;

    /* Validate the request */
    if(drvIndex >= (uint32_t)DRV_USART_INSTANCES_NUMBER)
    {
        //SYS_DEBUG(SYS_ERROR_ERROR, "Invalid driver instance");
        return SYS_MODULE_OBJ_INVALID;
    }

    if(gDrvUSARTObj[drvIndex].inUse != false)
    {
        //SYS_DEBUG(SYS_ERROR_ERROR, "Instance already in use");
        return SYS_MODULE_OBJ_INVALID;
    }

    /* Allocate the driver object */
    dObj                        = &gDrvUSARTObj[drvIndex];
    dObj->inUse                 = true;
    dObj->usartPlib             = usartInit->usartPlib;
    dObj->clientObjPool         = usartInit->clientObjPool;
    dObj->nClientsMax           = usartInit->numClients;
    dObj->nClients              = 0;
    dObj->currentRxClient       = 0U;
    dObj->currentTxClient       = 0U;
    dObj->isExclusive           = false;
    dObj->usartTokenCount       = 1;
    dObj->remapDataWidth        = usartInit->remapDataWidth;
    dObj->remapParity           = usartInit->remapParity;
    dObj->remapStopBits         = usartInit->remapStopBits;
    dObj->remapError            = usartInit->remapError;
    dObj->dataWidth             = usartInit->dataWidth;

    if (OSAL_MUTEX_Create(&dObj->clientMutex) == OSAL_RESULT_FAIL)
    {
        /*  If the mutex was not created because the memory required to
            hold the mutex could not be allocated then NULL is returned. */
        return SYS_MODULE_OBJ_INVALID;
    }

    if (OSAL_MUTEX_Create(&dObj->txTransferMutex) == OSAL_RESULT_FAIL)
    {
        /*  If the mutex was not created because the memory required to
            hold the mutex could not be allocated then NULL is returned. */
        return SYS_MODULE_OBJ_INVALID;
    }

    if (OSAL_MUTEX_Create(&dObj->rxTransferMutex) == OSAL_RESULT_FAIL)
    {
        /*  If the mutex was not created because the memory required to
            hold the mutex could not be allocated then NULL is returned. */
        return SYS_MODULE_OBJ_INVALID;
    }

    if (OSAL_SEM_Create(&dObj->txTransferDone, OSAL_SEM_TYPE_BINARY, 0, 0) == OSAL_RESULT_FAIL)
    {
        /* There was insufficient memory available for the semaphore to
        be created successfully. */
        return SYS_MODULE_OBJ_INVALID;
    }

    if (OSAL_SEM_Create(&dObj->rxTransferDone, OSAL_SEM_TYPE_BINARY, 0, 0) == OSAL_RESULT_FAIL)
    {
        /* There was insufficient memory available for the semaphore to
        be created successfully. */
        return SYS_MODULE_OBJ_INVALID;
    }

    /* Register a callback with either DMA or USART PLIB based on configuration.
     * dObj is used as a context parameter, that will be used to distinguish the
     * events for different driver instances. */
    (void) dObj->usartPlib->writeCallbackRegister(lDRV_USART_TX_PLIB_CallbackHandler, (uintptr_t)dObj);

    dObj->usartPlib->readCallbackRegister(lDRV_USART_RX_PLIB_CallbackHandler, (uintptr_t)dObj);

    /* Update the status */
    dObj->status = SYS_STATUS_READY;

    /* Return the object structure */
    return ( (SYS_MODULE_OBJ)drvIndex );
}
/* MISRAC 2012 deviation block end */

SYS_STATUS DRV_USART_Status( SYS_MODULE_OBJ object)
{
    /* Validate the request */
    if( (object == SYS_MODULE_OBJ_INVALID) || (object >= (uint32_t)DRV_USART_INSTANCES_NUMBER) )
    {
        //SYS_DEBUG(SYS_ERROR_ERROR, "Invalid system object handle");
        return SYS_STATUS_UNINITIALIZED;
    }

    return (gDrvUSARTObj[object].status);
}

DRV_HANDLE DRV_USART_Open( const SYS_MODULE_INDEX drvIndex, const DRV_IO_INTENT ioIntent )
{
    DRV_USART_OBJ *dObj = NULL;
    DRV_USART_CLIENT_OBJ *clientObj = NULL;
    uint32_t iClient;

    /* Validate the request */
    if (drvIndex >= (uint32_t)DRV_USART_INSTANCES_NUMBER)
    {
        //SYS_DEBUG(SYS_ERROR_ERROR, "Invalid Driver Instance");
        return DRV_HANDLE_INVALID;
    }

    dObj = &gDrvUSARTObj[drvIndex];

    if(dObj->status != SYS_STATUS_READY)
    {
        //SYS_DEBUG(SYS_ERROR_ERROR, "Was the driver initialized?");
        return DRV_HANDLE_INVALID;
    }

    /* Acquire the instance specific mutex to protect the instance specific
     * client pool
     */
    if (OSAL_MUTEX_Lock(&dObj->clientMutex , OSAL_WAIT_FOREVER ) == OSAL_RESULT_FAIL)
    {
        return DRV_HANDLE_INVALID;
    }

    if(dObj->isExclusive)
    {
        /* This means the another client has opened the driver in exclusive
           mode. The driver cannot be opened again */
        (void) OSAL_MUTEX_Unlock( &dObj->clientMutex);
        return DRV_HANDLE_INVALID;
    }

    if((dObj->nClients > 0U) && (((uint32_t)ioIntent & (uint32_t)DRV_IO_INTENT_EXCLUSIVE) != 0U))
    {
        /* This means the driver was already opened and another driver was
           trying to open it exclusively.  We cannot give exclusive access in
           this case */
        (void) OSAL_MUTEX_Unlock( &dObj->clientMutex);
        return(DRV_HANDLE_INVALID);
    }

    /* Enter here only if the lock was obtained */
    for(iClient = 0; iClient != dObj->nClientsMax; iClient++)
    {
        if(false == ((DRV_USART_CLIENT_OBJ *)dObj->clientObjPool)[iClient].inUse)
        {
            /* This means we have a free client object to use */

            clientObj = &((DRV_USART_CLIENT_OBJ *)dObj->clientObjPool)[iClient];

            clientObj->inUse        = true;

            clientObj->hDriver      = dObj;

            clientObj->ioIntent     = ioIntent;

            clientObj->errors       = DRV_USART_ERROR_NONE;

            if(((uint32_t)ioIntent & (uint32_t)DRV_IO_INTENT_EXCLUSIVE) != 0U)
            {
                /* Set the driver exclusive flag */
                dObj->isExclusive = true;
            }

            dObj->nClients ++;

            /* Generate and save client handle in the client object, which will
             * be then used to verify the validity of the client handle.
             */
            clientObj->clientHandle = lDRV_USART_MAKE_HANDLE(dObj->usartTokenCount, (uint8_t)drvIndex, (uint8_t)iClient);

            /* Increment the instance specific token counter */
            dObj->usartTokenCount = lDRV_USART_UPDATE_TOKEN(dObj->usartTokenCount);

            break;
        }
    }

    (void) OSAL_MUTEX_Unlock(&dObj->clientMutex);

    /* Driver index is the handle */
    if(clientObj != NULL)
    {
        return ((DRV_HANDLE)clientObj->clientHandle);
    }
    else
    {
        return DRV_HANDLE_INVALID;
    }
}

bool DRV_USART_SerialSetup( const DRV_HANDLE handle, DRV_USART_SERIAL_SETUP* setup )
{
    DRV_USART_OBJ* dObj;
    DRV_USART_CLIENT_OBJ* clientObj;
    DRV_USART_SERIAL_SETUP setupRemap;
    bool isSuccess = false;

    /* Validate the request */
    clientObj = lDRV_USART_DriverHandleValidate(handle);
    if ((clientObj != NULL) && (setup != NULL))
    {
        dObj = (DRV_USART_OBJ *)clientObj->hDriver;

        setupRemap.dataWidth = (DRV_USART_DATA_BIT)dObj->remapDataWidth[setup->dataWidth];
        setupRemap.parity = (DRV_USART_PARITY)dObj->remapParity[setup->parity];
        setupRemap.stopBits = (DRV_USART_STOP_BIT)dObj->remapStopBits[setup->stopBits];
        setupRemap.baudRate = setup->baudRate;

        if( (setupRemap.dataWidth != DRV_USART_DATA_BIT_INVALID) && (setupRemap.parity != DRV_USART_PARITY_INVALID) && (setupRemap.stopBits != DRV_USART_STOP_BIT_INVALID))
        {
            /* Clock source cannot be modified dynamically, so passing the '0' to pick
             * the configured clock source value */
            isSuccess = dObj->usartPlib->serialSetup(&setupRemap, 0);
            if (isSuccess == true)
            {
                dObj->dataWidth = setup->dataWidth;
            }
        }
    }
    return isSuccess;
}

void DRV_USART_Close( DRV_HANDLE handle )
{
    DRV_USART_CLIENT_OBJ* clientObj;
    DRV_USART_OBJ* dObj;

    /* Validate the handle */
    clientObj = lDRV_USART_DriverHandleValidate(handle);

    if(clientObj != NULL)
    {
        dObj = (DRV_USART_OBJ *)clientObj->hDriver;

        /* Acquire the instance specifc mutex to protect the instance specific
         * client pool
         */
        if (OSAL_MUTEX_Lock(&dObj->clientMutex , OSAL_WAIT_FOREVER ) == OSAL_RESULT_SUCCESS)
        {
            /* Reduce the number of clients */
            dObj->nClients --;

            /* Reset the exclusive flag */
            dObj->isExclusive = false;

            /* De-allocate the object */
            clientObj->inUse = false;

            /* Release the instance specific mutex */
            (void) OSAL_MUTEX_Unlock( &dObj->clientMutex );
        }
    }
}

DRV_USART_ERROR DRV_USART_ErrorGet( const DRV_HANDLE handle )
{
    DRV_USART_CLIENT_OBJ* clientObj;
    DRV_USART_ERROR errors = DRV_USART_ERROR_NONE;

    /* Validate the handle */
    clientObj = lDRV_USART_DriverHandleValidate(handle);

    if(clientObj != NULL)
    {
        errors = clientObj->errors;
    }

    return errors;
}

bool DRV_USART_WriteBuffer
(
    const DRV_HANDLE handle,
    void* buffer,
    const size_t numbytes
)
{
    DRV_USART_CLIENT_OBJ* clientObj = (DRV_USART_CLIENT_OBJ *)NULL;
    DRV_USART_OBJ* dObj = NULL;
    bool isSuccess = false;

    /* Validate the driver handle */
    clientObj = lDRV_USART_DriverHandleValidate(handle);

    if((clientObj != NULL) && (numbytes != 0U) && (buffer != NULL))
    {
        dObj = clientObj->hDriver;

        /* Obtain transmit mutex */
        if (OSAL_MUTEX_Lock(&dObj->txTransferMutex, OSAL_WAIT_FOREVER) == OSAL_RESULT_SUCCESS)
        {
            /* Error is cleared for every new transfer */
            clientObj->errors = DRV_USART_ERROR_NONE;

            dObj->currentTxClient = (uintptr_t)clientObj;

            (void) dObj->usartPlib->write_t(buffer, numbytes);

            /* Wait for transfer to complete */
            if (OSAL_SEM_Pend(&dObj->txTransferDone, OSAL_WAIT_FOREVER) == OSAL_RESULT_SUCCESS)
            {
                if (dObj->txRequestStatus == DRV_USART_REQUEST_STATUS_COMPLETE)
                {
                   isSuccess = true;
                }
            }
            /* Release transmit mutex */
            (void) OSAL_MUTEX_Unlock(&dObj->txTransferMutex);
        }
    }
    return isSuccess;
}

bool DRV_USART_ReadBuffer
(
    const DRV_HANDLE handle,
    void* buffer,
    const size_t numbytes
)
{
    DRV_USART_CLIENT_OBJ* clientObj = (DRV_USART_CLIENT_OBJ *)NULL;
    DRV_USART_OBJ* dObj = NULL;
    bool isSuccess = false;

    /* Validate the driver handle */
    clientObj = lDRV_USART_DriverHandleValidate(handle);

    if((clientObj != NULL) && (numbytes != 0U) && (buffer != NULL))
    {
        dObj = clientObj->hDriver;

        /* Obtain receive mutex */
        if (OSAL_MUTEX_Lock(&dObj->rxTransferMutex, OSAL_WAIT_FOREVER) == OSAL_RESULT_SUCCESS)
        {
            /* Error is cleared for every new transfer */
            clientObj->errors = DRV_USART_ERROR_NONE;

            dObj->currentRxClient = (uintptr_t)clientObj;

            (void) dObj->usartPlib->read_t(buffer, numbytes);
            /* Wait for transfer to complete */
            if (OSAL_SEM_Pend(&dObj->rxTransferDone, OSAL_WAIT_FOREVER) == OSAL_RESULT_SUCCESS)
            {
                /* Check and return status */
                if (dObj->rxRequestStatus == DRV_USART_REQUEST_STATUS_COMPLETE)
                {
                    isSuccess = true;
                }
            }
            /* Release receive mutex */
            (void) OSAL_MUTEX_Unlock(&dObj->rxTransferMutex);
        }
    }
    return isSuccess;
}
