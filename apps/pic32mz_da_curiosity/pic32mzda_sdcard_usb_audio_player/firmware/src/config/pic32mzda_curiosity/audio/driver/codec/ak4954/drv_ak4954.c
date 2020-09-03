/*******************************************************************************
  AK4954 Codec Driver implemention.

  Company:
    Microchip Technology Inc.

  File Name:
    drv_AK4954.c

  Summary:
    AK4954 Codec Driver implemention.

  Description:
    This file contains the implementation of the AK4954 driver.
*******************************************************************************/
// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

/*************************************************************
 * Include files.
 ************************************************************/
#include "drv_ak4954_local.h"

// *****************************************************************************
/* Driver Hardware instance objects.

  Summary:
    Defines the hardware instances objects for the AK4954 Codec

  Description:
    This data type defines the hardware instance objects that are available for
    AK4954 Codec, so as to capture the hardware state of the instance.

  Remarks:
    Not all modes are available on all micro-controllers.
 */
DRV_AK4954_OBJ gDrvak4954Obj[DRV_AK4954_INSTANCES_NUMBER];


// *****************************************************************************
/* Driver Client instance objects.

  Summary:
    Defines the client instances objects

  Description:
    This data type defines the client instance objects that are available on
    AK4954, so as to capture the client state of the instance.
    It uses the configuration of maximum number of clients which can get
    registered per hardware instance.

  Remarks:
    Not all modes are available on all micro-controllers.
 */
DRV_AK4954_CLIENT_OBJ gDrvak4954ClientObj[DRV_AK4954_CLIENTS_NUMBER];

// *****************************************************************************
/* Driver common data object

  Summary:
    Defines the common data object

  Description:
    This object maintains data that is required by all AK4954
   driver instances

  Remarks:
    None
 */
DRV_AK4954_COMMON_DATA_OBJ gDrvak4954CommonDataObj;

// gDrvCommandBuffer is a queue container for AK4954 commands
AK4954_COMMAND_QUEUE gDrvCommandBuffer;
uint8_t command_array[20];

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

/// *****************************************************************************
 /*
  Function:
        static void AK4954_I2CEventHandler
        (
            DRV_I2C_TRANSFER_EVENT event
            DRV_I2C_TRANSFER_HANDLE transferHandle, 
            uintptr_t context
        )

  Summary:
    Implements the handler for I2C  callback function.

  Description:
    Called when I2c transfer completes.

  Parameters:
    event       -
    transferHandle - 
    context     - Contains index into driver's instance object array

  Remarks:
    None
*/

static void AK4954_I2CEventHandler ( DRV_I2C_TRANSFER_EVENT event,
                           DRV_I2C_TRANSFER_HANDLE transferHandle, 
                           uintptr_t context )
{
    DRV_AK4954_OBJ *drvObj = (DRV_AK4954_OBJ*)context;
    
    /* Checks for valid buffer handle */
    if( transferHandle == DRV_I2C_TRANSFER_HANDLE_INVALID )
    {
        return;
    }
       
    if( transferHandle == drvObj->hWriteTransfer &&
        event == DRV_I2C_TRANSFER_EVENT_COMPLETE )
    {
        /* Codec write operation is complete */
        drvObj->writeComplete = true;
    }
           
    if( transferHandle == drvObj->hReadTransfer &&
        event == DRV_I2C_TRANSFER_EVENT_COMPLETE )
    {
        /* Codec read is complete */
        drvObj->readComplete = true;
    }   
}

// *****************************************************************************
// *****************************************************************************
// Section: AK4954 Codec Driver System Routine Implementations
// *****************************************************************************
// *****************************************************************************
/*   Function:
	SYS_MODULE_OBJ  DRV_AK4954_Initialize
	(
		const SYS_MODULE_INDEX drvIndex,
        const SYS_MODULE_INIT *const init
	);

  Summary:
    Initializes hardware and data for the instance of the AK4954 Codec module

  Description:
    This routine initializes the AK4954 driver instance for the specified driver
    index, making it ready for clients to open and use it. The initialization
    data is specified by the init parameter. The initialization may fail if the
    number of driver objects allocated are insufficient or if the specified
    driver instance is already initialized.

  Remarks:
    This routine must be called before any other AK4954 routine is called.

    This routine should only be called once during system initialization
    unless DRV_AK4954_Deinitialize is called to de-initialize the driver
    instance. This routine will NEVER block for hardware access.

 */

SYS_MODULE_OBJ  DRV_AK4954_Initialize
(
	const SYS_MODULE_INDEX drvIndex,
	const SYS_MODULE_INIT *const init
)
{
    DRV_AK4954_OBJ *drvObj;
    DRV_AK4954_INIT *ak4954Init;
    uint8_t index;

    /* Validate the driver index */
    if (drvIndex >= DRV_AK4954_INSTANCES_NUMBER)
    {
        SYS_DEBUG(0, "Invalid driver index \r\n");
        return SYS_MODULE_OBJ_INVALID;
    }

    if (true == gDrvak4954Obj[drvIndex].inUse)
    {
        /* Cannot initialize an object that is already in use. */
        SYS_DEBUG(0, "Instance already in use \r\n");
        return SYS_MODULE_OBJ_INVALID;
    }

    ak4954Init = (DRV_AK4954_INIT *) init;
    drvObj = (DRV_AK4954_OBJ *)&gDrvak4954Obj[drvIndex];

    /* Populate the driver object with the required data */
    drvObj->inUse                           = true;
    drvObj->status                          = SYS_STATUS_UNINITIALIZED;
    drvObj->numClients                      = 0;
    drvObj->masterMode                      = ak4954Init->masterMode;
    drvObj->i2sDriverModuleIndex            = ak4954Init->i2sDriverModuleIndex;
    drvObj->i2cDriverModuleIndex            = ak4954Init->i2cDriverModuleIndex;
    drvObj->samplingRate                    = DRV_AK4954_AUDIO_SAMPLING_RATE;
    drvObj->audioDataFormat                 = DRV_AK4954_AUDIO_DATA_FORMAT_MACRO;
    drvObj->whichMicInput                   = ak4954Init->whichMicInput;
    drvObj->enableMicBias                   = ak4954Init->enableMicBias;
    drvObj->micGain                         = ak4954Init->micGain;
    drvObj->mclk_multiplier                 = DRV_AK4954_MCLK_SAMPLE_FREQ_MULTPLIER;
    drvObj->bclk_divider                    = DRV_AK4954_BCLK_BIT_CLK_DIVISOR;
    
    drvObj->readComplete = false;
    drvObj->writeComplete = false;    
    
    drvObj->drvI2CMasterHandle              = DRV_I2C_Open(DRV_AK4954_I2C_DRIVER_MODULE_INDEX_IDX0,
                                                            DRV_IO_INTENT_WRITE );
    if(drvObj->drvI2CMasterHandle == DRV_HANDLE_INVALID)
    {
        return SYS_MODULE_OBJ_INVALID;
    }
    
    /* Register the I2C Driver event Handler */
    DRV_I2C_TransferEventHandlerSet( drvObj->drvI2CMasterHandle, 
                                     AK4954_I2CEventHandler, (uintptr_t)drvObj);    

    /*Assigning the init volume to all supported audio channels*/
    for(index=0; index < DRV_AK4954_NUMBER_OF_CHANNELS; index++)
    {
        drvObj->volume[index] = ak4954Init->volume;
    }

    drvObj->commandCompleteCallback = (DRV_AK4954_COMMAND_EVENT_HANDLER)0;
    drvObj->commandContextData = -1;

    drvObj->delayDriverInitialization = ak4954Init->delayDriverInitialization;

    /* Create the hardware instance mutex. */
     if(OSAL_MUTEX_Create(&(drvObj->mutexDriverInstance)) != OSAL_RESULT_TRUE)
     {
        return SYS_MODULE_OBJ_INVALID;
     }

    /* Check if the global mutexes have been created. If not
       then create these. */
     if(!gDrvak4954CommonDataObj.membersAreInitialized)
     {
         /* This means that mutexes where not created. Create them. */
         if((OSAL_MUTEX_Create(&(gDrvak4954CommonDataObj.mutexClientObjects)) != OSAL_RESULT_TRUE))
         {
            return SYS_MODULE_OBJ_INVALID;
         }
         /* Set this flag so that global mutexes get allocated only once */
         gDrvak4954CommonDataObj.membersAreInitialized = true;
     }

    drvObj->status = SYS_STATUS_BUSY;

	// if delayed initialization is enabled, just go into a wait state
	// until application calls EnableInitialization routine
    drvObj->command = (drvObj->delayDriverInitialization) ?
        DRV_AK4954_COMMAND_NONE : DRV_AK4954_COMMAND_INIT_CLK_PDN_SET;
    
    gDrvCommandBuffer.queueIn = 0;
    gDrvCommandBuffer.queueOut = 0;

    /* Return the object structure */
    return ((SYS_MODULE_OBJ) drvObj);

} /* DRV_AK4954_Initialize */

// *****************************************************************************
/* Function:
    void DRV_AK4954_Deinitialize( SYS_MODULE_OBJ object)

  Summary:
    Deinitializes the specified instance of the AK4954 driver module

  Description:
    Deinitializes the specified instance of the AK4954 driver module, disabling
    its operation (and any hardware).  Invalidates all the internal data.

  Precondition:
    Function DRV_AK4954_Initialize should have been called before calling this
    function.

  Parameters:
    object          - Driver object handle, returned from the
                      DRV_AK4954_Initialize routine
  Returns:
    None.

  Remarks:
    Once the Initialize operation has been called, the De-initialize operation
    must be called before the Initialize operation can be called again. This
    routine will NEVER block waiting for hardware.
*/

void DRV_AK4954_Deinitialize( SYS_MODULE_OBJ object)
{
    DRV_AK4954_OBJ *drvObj;

    if (object == SYS_MODULE_OBJ_INVALID || object == (SYS_MODULE_OBJ)NULL)
    {
        /* Invalid object */
        SYS_DEBUG(0, "Invalid object \r\n");
        return;
    }

	drvObj = (DRV_AK4954_OBJ *) object;

    if (false == drvObj->inUse)
    {
        /* Cannot deinitialize an object that is
         * not already in use. */
        SYS_DEBUG(0, "Instance not in use \r\n");
        return;
    }

    /* Deallocate all the mutexes */
     if((OSAL_MUTEX_Delete(&(drvObj->mutexDriverInstance)) != OSAL_RESULT_TRUE))
     {
        SYS_DEBUG(0, "Unable to delete client handle mutex \r\n");
        return;
     }

//    DRV_I2S_Close (drvObj->i2sDriverClientHandleWrite);
//
//    DRV_I2S_Close (drvObj->i2sDriverClientHandleRead);

    /* Indicate that this object is not is use */
    drvObj->inUse = false;

    drvObj->numClients = 0;
    drvObj->status = SYS_STATUS_UNINITIALIZED;
}

// *****************************************************************************
/* Function:
    SYS_STATUS DRV_AK4954_Status( SYS_MODULE_OBJ object)

  Summary:
    Gets the current status of the AK4954 driver module.

  Description:
    This routine provides the current status of the AK4954 driver module.

  Precondition:
    Function DRV_AK4954_Initialize should have been called before calling this
    function.

  Parameters:
    object          - Driver object handle, returned from the
                      DRV_AK4954_Initialize routine

  Returns:
    SYS_STATUS_DEINITIALIZED  - Indicates that the driver has been
                                de-initialized

    SYS_STATUS_READY          - Indicates that any previous module operation
                                for the specified module has completed

    SYS_STATUS_BUSY           - Indicates that a previous module operation for
                                the specified module has not yet completed

    SYS_STATUS_ERROR          - Indicates that the specified module is in an
                                error state

  Remarks:
    A driver can opened only when its status is SYS_STATUS_READY.
*/

SYS_STATUS DRV_AK4954_Status( SYS_MODULE_OBJ object)
{
    DRV_AK4954_OBJ *drvObj;

    if (object == SYS_MODULE_OBJ_INVALID ||
        object < DRV_AK4954_INSTANCES_NUMBER)
    {
        SYS_DEBUG(0, "System Module Object is invalid \r\n");
        return SYS_STATUS_ERROR;
    }
    drvObj = (DRV_AK4954_OBJ *)object;

    /* Return the status of the driver object */
    return drvObj->status;
} /* DRV_AK4954_Status */

// *****************************************************************************
/* Function:
    void DRV_AK4954_EnableInitialization(SYS_MODULE_OBJ object);

  Summary:
   Enable delayed initialization of the driver.

  Description:
   If the AK4954 codec is sharing a RESET line with another peripheral, such as
   a Bluetooth module with its own driver, then the codec driver initialization
   has to be delayed until after the Bluetooth module has toggled its RESET pin.
   Once this has been accomplished, this function should be called to kick-start
   the codec driver initialization.

  Precondition:
    The DRV_AK4954_Initialize routine must have been called for the specified
    AK4954 driver instance.

  Parameters:
    object      - Object handle for the specified driver instance (returned from
                  DRV_AK4954_Initialize)
  Returns:
    None.

  Remarks:
    This is not needed for audio-only applications without a Bluetooth module.
*/

void DRV_AK4954_EnableInitialization(SYS_MODULE_OBJ object)
{
    DRV_AK4954_OBJ *drvObj;
    
    drvObj = (DRV_AK4954_OBJ *)object;

    if((false == drvObj->inUse))
    {
        /* This instance of the driver is not initialized. Don't
         * do anything */
        return;
    }

    if ((true == drvObj->delayDriverInitialization) &&
        (DRV_AK4954_COMMAND_NONE == drvObj->command))
    {
        drvObj->command = DRV_AK4954_COMMAND_INIT_CLK_PDN_SET;
    }
}

// *****************************************************************************
/* Function:
    bool DRV_AK4954_IsInitializationDelayed(SYS_MODULE_OBJ object);

  Summary:
   Checks if delayed initialization of the driver has been requested.

  Description:
   If the AK4954 codec is sharing a RESET line with another peripheral, such as
   a Bluetooth module with its own driver, then the codec driver initialization
   has to be delayed until after the Bluetooth module has toggled its RESET pin.
   This function returns true if that option has been selected in MHC in the
   checkbox: "Delay driver initialization (due to shared RESET pin)"

  Precondition:
    The DRV_AK4954_Initialize routine must have been called for the specified
    AK4954 driver instance.

  Parameters:
    object      - Object handle for the specified driver instance (returned from
                  DRV_AK4954_Initialize)
  Returns:
    true if the delayed initilization option has been enabled

  Remarks:
    This is not needed for audio-only applications without a Bluetooth module.
*/

bool DRV_AK4954_IsInitializationDelayed(SYS_MODULE_OBJ object)
{
    DRV_AK4954_OBJ *drvObj;
    
    drvObj = (DRV_AK4954_OBJ *)object;

    if((false == drvObj->inUse))
    {
        /* This instance of the driver is not initialized. Don't
         * do anything */
        return false;
    }

    return drvObj->delayDriverInitialization;   // return true or false
}

// *****************************************************************************
/* Function:
    void  DRV_AK4954_Tasks(SYS_MODULE_OBJ object);

  Summary:
    Maintains the driver's control and data interface state machine.

  Description:
    This routine is used to maintain the driver's internal control and data
    interface state machine and implement its control and data interface
    implementations.
    This function should be called from the SYS_Tasks() function.

  Precondition:
    The DRV_AK4954_Initialize routine must have been called for the specified
    AK4954 driver instance.

  Parameters:
    object      - Object handle for the specified driver instance (returned from
                  DRV_AK4954_Initialize)

  Returns:
    None.

  Remarks:
    This routine is normally not called directly by an application.  It is
    called by the system's Tasks routine (SYS_Tasks).

*/

void DRV_AK4954_Tasks(SYS_MODULE_OBJ object)
{

    DRV_AK4954_OBJ *drvObj;

    drvObj = (DRV_AK4954_OBJ *)object;

    if((false == drvObj->inUse))
    {
        /* This instance of the driver is not initialized. Don't
         * do anything */
        return;
    }

    _DRV_AK4954_ControlTasks(drvObj);
}

// *****************************************************************************
// *****************************************************************************
// Section: AK4954 Codec Driver Client Routines
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
/* Function:
    DRV_HANDLE DRV_AK4954_Open
    (
		const SYS_MODULE_INDEX drvIndex,
		const DRV_IO_INTENT    ioIntent
	)

  Summary:
    Opens the specified AK4954 driver instance and returns a handle to it

  Description:
    This routine opens the specified AK4954 driver instance and provides a
    handle that must be provided to all other client-level operations to
    identify the caller and the instance of the driver. The ioIntent
    parameter defines how the client interacts with this driver instance.

    The DRV_IO_INTENT_BLOCKING and DRV_IO_INTENT_NONBLOCKING ioIntent
    options are not relevant to this driver. All the data transfer functions
    of this driver are non blocking.

    Only DRV_IO_INTENT_WRITE is a valid ioIntent option as AK4954 is DAC only.

    Specifying a DRV_IO_INTENT_EXCLUSIVE will cause the driver to provide
    exclusive access to this client. The driver cannot be opened by any
    other client.

  Precondition:
    Function DRV_AK4954_Initialize must have been called before calling this
    function.

  Parameters:
    drvIndex    - Identifier for the object instance to be opened

    ioIntent    - Zero or more of the values from the enumeration
                  DRV_IO_INTENT "or'd" together to indicate the intended use
                  of the driver. See function description for details.

  Returns:
    If successful, the routine returns a valid open-instance handle (a number
    identifying both the caller and the module instance).

    If an error occurs, the return value is DRV_HANDLE_INVALID. Error can occur
    - if the number of client objects allocated via DRV_AK4954_CLIENTS_NUMBER is insufficient.
    - if the client is trying to open the driver but driver has been opened exclusively by another client.
    - if the driver hardware instance being opened is not initialized or is invalid.
    - if the ioIntent options passed are not relevant to this driver.

  Remarks:
    The handle returned is valid until the DRV_AK4954_Close routine is called.
    This routine will NEVER block waiting for hardware.If the requested intent
    flags are not supported, the routine will return DRV_HANDLE_INVALID.  This
    function is thread safe in a RTOS application. It should not be called in an
    ISR.
*/

DRV_HANDLE DRV_AK4954_Open
(
	const SYS_MODULE_INDEX iDriver,
	const DRV_IO_INTENT ioIntent
)
{
    DRV_AK4954_CLIENT_OBJ *hClient;
    DRV_AK4954_OBJ *drvObj;
    uint32_t iClient;

    /* The iDriver value should be valid. It should be
     * less the number of driver object instances.
     */
    if (iDriver >= DRV_AK4954_INSTANCES_NUMBER)
    {
        SYS_DEBUG(0, "Bad Driver Index \r\n");
        return DRV_HANDLE_INVALID;
    }
    drvObj = (DRV_AK4954_OBJ *)&gDrvak4954Obj[iDriver];
    if (drvObj->status != SYS_STATUS_READY)
    {
        /* The AK4954  module should be ready */
        SYS_DEBUG(0, "Was the driver initialized? \r\n");
        return DRV_HANDLE_INVALID;
    }

    if ((drvObj->numClients > 0) && (true == drvObj->isExclusive))
    {
        /* Driver already opened in exclusive mode. Cannot open a new client. */
        SYS_DEBUG(0, "Cannot open a new client in exclusive mode \r\n");
        return DRV_HANDLE_INVALID;
    }

    if ((drvObj->numClients > 0) &&
        (DRV_IO_INTENT_EXCLUSIVE == (ioIntent & DRV_IO_INTENT_EXCLUSIVE)))
    {
        /*  A client Instance of driver is open.
            Cannot open the new client in exclusive mode */
            SYS_DEBUG(0, "Cannot open a new client in exclusive mode \r\n");
            return DRV_HANDLE_INVALID;
    }

    iClient = 0;
    hClient = (DRV_AK4954_CLIENT_OBJ *)&gDrvak4954ClientObj[iClient];

    /* Grab client object mutex here */
    if(OSAL_MUTEX_Lock(&(gDrvak4954CommonDataObj.mutexClientObjects), OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
    {
        /* Setup client operations */
        /* Find available slot in array of client objects */
        for (; iClient < DRV_AK4954_CLIENTS_NUMBER; iClient++)
        {
            if (false == hClient->inUse)
            {
                /* Set the exlusive mode for the driver instance */
                if (DRV_IO_INTENT_EXCLUSIVE == (ioIntent & DRV_IO_INTENT_EXCLUSIVE))
                {
                    drvObj->isExclusive = true;
                }

                if(DRV_IO_INTENT_READWRITE == (ioIntent & DRV_IO_INTENT_READWRITE))
                {
                    hClient->ioIntent = DRV_IO_INTENT_READWRITE;
					drvObj->i2sDriverHandle = DRV_I2S_Open(drvObj->i2sDriverModuleIndex,
                        (DRV_IO_INTENT_READWRITE | DRV_IO_INTENT_NONBLOCKING));

                }
                else if(DRV_IO_INTENT_WRITE == (ioIntent & DRV_IO_INTENT_READWRITE))
                {
                    hClient->ioIntent = DRV_IO_INTENT_WRITE;
                    drvObj->i2sDriverClientHandleWrite = DRV_I2S_Open(drvObj->i2sDriverModuleIndex,
                        (DRV_IO_INTENT_WRITE | DRV_IO_INTENT_NONBLOCKING));
                    drvObj->i2sDriverHandle = drvObj->i2sDriverClientHandleWrite;
                }
                else if(DRV_IO_INTENT_READ == (ioIntent & DRV_IO_INTENT_READWRITE))
                {
                    hClient->ioIntent = DRV_IO_INTENT_READ;
                    drvObj->i2sDriverClientHandleRead = DRV_I2S_Open(drvObj->i2sDriverModuleIndex,
                        (DRV_IO_INTENT_READ | DRV_IO_INTENT_NONBLOCKING));
                    drvObj->i2sDriverHandle = drvObj->i2sDriverClientHandleRead;
                }
                else
                {
                    SYS_DEBUG(0, "i2s DRV_I2S_Open Error");
                }

                hClient->ioIntent |= DRV_IO_INTENT_NONBLOCKING;

                DRV_I2S_BaudRateSet(drvObj->i2sDriverHandle, drvObj->samplingRate*drvObj->bclk_divider,
                        drvObj->samplingRate);

                /* Remember which AK4954 driver instance owns me */
                hClient->inUse  = true;
                hClient->hDriver = drvObj;
                hClient->pEventCallBack = NULL;

                drvObj->numClients++;
                /* We have found a client object
                 * Release the mutex and return with
                 * the driver handle */
                /* An operation mode is needed */
                if((OSAL_MUTEX_Unlock(&(gDrvak4954CommonDataObj.mutexClientObjects))) != OSAL_RESULT_TRUE)
                {
                    SYS_DEBUG(0, "Unable to unlock open routine mutex \r\n");
                    return DRV_HANDLE_INVALID;
                }
                /* Return the client object */
                return (DRV_HANDLE) hClient;
            }
            hClient++;
        }
        /* Could not find a client object. Release the mutex and
         * return with an invalid handle. */
        if((OSAL_MUTEX_Unlock(&(gDrvak4954CommonDataObj.mutexClientObjects))) != OSAL_RESULT_TRUE)
        {
            SYS_DEBUG(0, "Unable to unlock open routine mutex \r\n");
        }
    }
    return DRV_HANDLE_INVALID;
}

// *****************************************************************************
/* Function:
    void DRV_AK4954_Close( DRV_Handle handle )

  Summary:
    Closes an opened-instance of the AK4954 driver

  Description:
    This routine closes an opened-instance of the AK4954 driver, invalidating the
    handle. Any buffers in the driver queue that were submitted by this client
    will be removed.  After calling this routine, the handle passed in "handle"
    must not be used with any of the remaining driver routines.  A new handle must
    be obtained by calling DRV_AK4954_Open before the caller may use the driver
    again

  Remarks:

    Usually there is no need for the driver client to verify that the Close
    operation has completed.  The driver will abort any ongoing operations
    when this routine is called.
*/

void DRV_AK4954_Close( const DRV_HANDLE handle)
{
    DRV_AK4954_CLIENT_OBJ *clientObj;
    DRV_AK4954_OBJ *drvObj;

    if(handle == DRV_HANDLE_INVALID || (DRV_HANDLE)NULL == handle)
    {
        SYS_DEBUG(0, "Invalid Driver Handle \r\n");
        return;
    }

    clientObj = (DRV_AK4954_CLIENT_OBJ *) handle;
    if (false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid Driver Handle \r\n");
        return;
    }

    drvObj = (DRV_AK4954_OBJ *) clientObj->hDriver;

    if(DRV_IO_INTENT_READ == (clientObj->ioIntent & DRV_IO_INTENT_READWRITE))
    {
        DRV_I2S_Close (drvObj->i2sDriverClientHandleRead);
    }
    else if(DRV_IO_INTENT_WRITE == (clientObj->ioIntent & DRV_IO_INTENT_READWRITE))
    {
        DRV_I2S_Close (drvObj->i2sDriverClientHandleWrite);

    }
    else if(DRV_IO_INTENT_READWRITE == (clientObj->ioIntent & DRV_IO_INTENT_READWRITE))
    {
		DRV_I2S_Close (drvObj->i2sDriverHandle);

    }

    /* De-allocate the object */
    clientObj->inUse = false;
    /* Reduce the number of clients */
    drvObj->numClients--;
} /* DRV_AK4954_Close */

// *****************************************************************************
/*
Function:
	void DRV_AK4954_BufferAddWrite
	(
		const DRV_HANDLE handle,
		DRV_AK4954_BUFFER_HANDLE *bufferHandle,
		void *buffer, size_t size
	)

  Summary:
    Schedule a non-blocking driver write operation.

  Description:
    This function schedules a non-blocking write operation. The function returns
    with a valid buffer handle in the bufferHandle argument if the write request
    was scheduled successfully. The function adds the request to the hardware
    instance transmit queue and returns immediately. While the request is in the
    queue, the application buffer is owned by the driver and should not be
    modified.  The function returns DRV_AK4954_BUFFER_HANDLE_INVALID
    - if a buffer could not be allocated to the request
    - if the input buffer pointer is NULL
    - if the buffer size is 0.
    - if the queue is full or the queue depth is insufficient
    If the requesting client registered an event callback with the driver,
    the driver will issue a DRV_AK4954_BUFFER_EVENT_COMPLETE event if the buffer
    was processed successfully of DRV_AK4954_BUFFER_EVENT_ERROR event if the
    buffer was not processed successfully.

  Precondition:
    The DRV_AK4954_Initialize routine must have been called for the specified
    AK4954 device instance and the DRV_AK4954_Status must have returned
    SYS_STATUS_READY.

    DRV_AK4954_Open must have been called to obtain a valid opened device handle.

    DRV_IO_INTENT_WRITE ust have been specified in the DRV_AK4954_Open call.

  Parameters:
    handle       - Handle of the AK4954 instance as return by the
                   DRV_AK4954_Open function.
    buffer       - Data to be transmitted.
    size         - Buffer size in bytes.
    bufferHandle - Pointer to an argument that will contain the
                   return buffer handle.

  Returns:
    The bufferHandle parameter will contain the return buffer handle. This will be
    DRV_AK4954_BUFFER_HANDLE_INVALID if the function was not successful.

   Remarks:
    This function is thread safe in a RTOS application. It can be called from
    within the AK4954 Driver Buffer Event Handler that is registered by this
    client. It should not be called in the event handler associated with another
    AK4954 driver instance. It should not otherwise be called directly in an ISR.

*/

void DRV_AK4954_BufferAddWrite
(
	const DRV_HANDLE handle,
	DRV_AK4954_BUFFER_HANDLE *bufferHandle,
	void *buffer, size_t size
)
{
    DRV_AK4954_CLIENT_OBJ *clientObj;
    DRV_AK4954_OBJ *drvObj;

    /* The Client and driver objects from the handle */
    clientObj = (DRV_AK4954_CLIENT_OBJ *) handle;
    drvObj = (DRV_AK4954_OBJ *) clientObj->hDriver;

    /* We first check the arguments and initialize the
     * buffer handle */
    if(bufferHandle != NULL)
    {
        *bufferHandle = DRV_AK4954_BUFFER_HANDLE_INVALID;
    }

    /* See if the handle is still valid */
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid Driver Handle \r\n");
        return;
    }

    /* Grab a mutex. */
    if (OSAL_MUTEX_Lock(&(drvObj->mutexDriverInstance), OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
    {
        ;
    }
    else
    {
        /* The mutex acquisition timed out. Return with an
         * invalid handle. This code will not execute
         * if there is no RTOS. */
        return;
    }

    {
        DRV_I2S_BUFFER_HANDLE i2sBufferHandle = DRV_I2S_BUFFER_HANDLE_INVALID;
        DRV_I2S_WriteBufferAdd(drvObj->i2sDriverClientHandleWrite,
                (uint8_t *) buffer, size, &i2sBufferHandle);          

        if(i2sBufferHandle != DRV_I2S_BUFFER_HANDLE_INVALID)
        {
            *bufferHandle = (DRV_AK4954_BUFFER_HANDLE)i2sBufferHandle;
        }
        else
        {
            *bufferHandle = DRV_AK4954_BUFFER_HANDLE_INVALID;
        }
    }

    if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
    {
        SYS_DEBUG(0, "Unable to DriverInstance mutex \r\n");
    }
} /* DRV_AK4954_BufferAddWrite */

// *****************************************************************************
/* Function:
	void DRV_AK4954_BufferAddWriteRead
        (
                const DRV_HANDLE handle,
                DRV_AK4954_BUFFER_HANDLE *bufferHandle,
                void *transmitBuffer,
                void *receiveBuffer,
                size_t size
        )

  Summary:
    Schedule a non-blocking driver write-read operation.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function schedules a non-blocking write-read operation. The function
    returns with a valid buffer handle in the bufferHandle argument if the
    write-read request was scheduled successfully. The function adds the request
    to the hardware instance queue and returns immediately. While the request is
    in the queue, the application buffer is owned by the driver and should not
    be modified. The function returns DRV_AK4954_BUFFER_EVENT_COMPLETE:
    - if a buffer could not be allocated to the request
    - if the input buffer pointer is NULL
    - if the client opened the driver for read only or write only
    - if the buffer size is 0
    - if the queue is full or the queue depth is insufficient
    If the requesting client registered an event callback with the driver,
    the driver will issue a DRV_AK4954_BUFFER_EVENT_COMPLETE event if the buffer
    was processed successfully of DRV_AK4954_BUFFER_EVENT_ERROR event if the
    buffer was not processed successfully.

  Remarks:
    This function is thread safe in a RTOS application. It can be called from
    within the AK4954 Driver Buffer Event Handler that is registered by this
    client. It should not be called in the event handler associated with another
    AK4954 driver instance. It should not otherwise be called directly in an ISR.

    This function is useful when there is valid read expected for every
    AK4954 write. The transmit and receive size must be same.

*/

void DRV_AK4954_BufferAddWriteRead
(
    const DRV_HANDLE handle,
    DRV_AK4954_BUFFER_HANDLE	*bufferHandle,
    void *transmitBuffer, void *receiveBuffer,
    size_t size
)
{
    DRV_AK4954_CLIENT_OBJ *clientObj;

    DRV_AK4954_OBJ *drvObj;

    /* The Client and driver objects from the handle */
    clientObj = (DRV_AK4954_CLIENT_OBJ *) handle;
    drvObj = (DRV_AK4954_OBJ *) clientObj->hDriver;

    /* We first check the arguments and initialize the
     * buffer handle */
    if(bufferHandle != NULL)
    {
        *bufferHandle = DRV_AK4954_BUFFER_HANDLE_INVALID;
    }

    /* See if the handle is still valid */
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid Driver Handle \r\n");
        return;

    }

    /* Grab a mutex. */
    if (OSAL_MUTEX_Lock(&(drvObj->mutexDriverInstance), OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
    {
        ;
    }
    else
    {
        /* The mutex acquisition timed out. Return with an
         * invalid handle. This code will not execute
         * if there is no RTOS. */
        return;
    }
    {
        DRV_I2S_BUFFER_HANDLE i2sBufferHandle = DRV_I2S_BUFFER_HANDLE_INVALID;
        DRV_I2S_WriteReadBufferAdd(drvObj->i2sDriverHandle,
                (uint8_t *) transmitBuffer, (uint8_t *) receiveBuffer, size, &i2sBufferHandle);         

            if(i2sBufferHandle != DRV_I2S_BUFFER_HANDLE_INVALID)
            {
                *bufferHandle = (DRV_AK4954_BUFFER_HANDLE)i2sBufferHandle;
            }
            else
            {
                *bufferHandle = DRV_AK4954_BUFFER_HANDLE_INVALID;
            }
    }

    /* Release mutex */
    if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
    {
        SYS_DEBUG(0, "Unable to DriverInstance mutex \r\n");
    }
} /* DRV_AK4954_BufferAddWriteRead */

// *****************************************************************************
/*
Function:
	void DRV_AK4954_BufferAddRead
	(
		const DRV_HANDLE handle,
		DRV_AK4954_BUFFER_HANDLE *bufferHandle,
		void *buffer, size_t size
	)

  Summary:
    Schedule a non-blocking driver write operation.

  Description:
    This function schedules a non-blocking write operation. The function returns
    with a valid buffer handle in the bufferHandle argument if the write request
    was scheduled successfully. The function adds the request to the hardware
    instance transmit queue and returns immediately. While the request is in the
    queue, the application buffer is owned by the driver and should not be
    modified.  The function returns DRV_AK4954_BUFFER_HANDLE_INVALID
    - if a buffer could not be allocated to the request
    - if the input buffer pointer is NULL
    - if the buffer size is 0.
    - if the queue is full or the queue depth is insufficient
    If the requesting client registered an event callback with the driver,
    the driver will issue a DRV_AK4954_BUFFER_EVENT_COMPLETE event if the buffer
    was processed successfully of DRV_AK4954_BUFFER_EVENT_ERROR event if the
    buffer was not processed successfully.

  Precondition:
    The DRV_AK4954_Initialize routine must have been called for the specified
    AK4954 device instance and the DRV_AK4954_Status must have returned
    SYS_STATUS_READY.

    DRV_AK4954_Open must have been called to obtain a valid opened device handle.

    DRV_IO_INTENT_WRITE ust have been specified in the DRV_AK4954_Open call.

  Parameters:
    handle       - Handle of the AK4954 instance as return by the
                   DRV_AK4954_Open function.
    buffer       - Data to be transmitted.
    size         - Buffer size in bytes.
    bufferHandle - Pointer to an argument that will contain the
                   return buffer handle.

  Returns:
    The bufferHandle parameter will contain the return buffer handle. This will be
    DRV_AK4954_BUFFER_HANDLE_INVALID if the function was not successful.

   Remarks:
    This function is thread safe in a RTOS application. It can be called from
    within the AK4954 Driver Buffer Event Handler that is registered by this
    client. It should not be called in the event handler associated with another
    AK4954 driver instance. It should not otherwise be called directly in an ISR.

*/

void DRV_AK4954_BufferAddRead
(
	const DRV_HANDLE handle,
	DRV_AK4954_BUFFER_HANDLE *bufferHandle,
	void *buffer, size_t size
)
{
    DRV_AK4954_CLIENT_OBJ *clientObj;

    DRV_AK4954_OBJ *drvObj;

    /* The Client and driver objects from the handle */
    clientObj = (DRV_AK4954_CLIENT_OBJ *) handle;
    drvObj = (DRV_AK4954_OBJ *) clientObj->hDriver;

    /* We first check the arguments and initialize the
     * buffer handle */
    if(bufferHandle != NULL)
    {
        *bufferHandle = DRV_AK4954_BUFFER_HANDLE_INVALID;
    }

    /* See if the handle is still valid */
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid Driver Handle \r\n");
        return;
    }

    /* Grab a mutex. */
    if (OSAL_MUTEX_Lock(&(drvObj->mutexDriverInstance), OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
    {
        ;
    }
    else
    {
        /* The mutex acquisition timed out. Return with an
         * invalid handle. This code will not execute
         * if there is no RTOS. */
        return;
    }

    {
        DRV_I2S_BUFFER_HANDLE i2sBufferHandle = DRV_I2S_BUFFER_HANDLE_INVALID;
        DRV_I2S_ReadBufferAdd(drvObj->i2sDriverClientHandleRead,
                (uint8_t *) buffer, size, &i2sBufferHandle);         

            if(i2sBufferHandle != DRV_I2S_BUFFER_HANDLE_INVALID)
            {
                *bufferHandle = (DRV_AK4954_BUFFER_HANDLE)i2sBufferHandle;
            }
            else
            {
                *bufferHandle = DRV_AK4954_BUFFER_HANDLE_INVALID;
            }
    }

    /* Release mutex */
    if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
    {
        SYS_DEBUG(0, "Unable to DriverInstance mutex \r\n");
    }
} /* DRV_AK4954_BufferAddRead */

// *****************************************************************************
/* Function:
    bool DRV_AK4954_WriteQueuePurge( const DRV_HANDLE handle )

  Summary:
    Removes all buffer requests from the write queue.

  Description:
    This function removes all the buffer requests from the write queue.
    The client can use this function to purge the queue on timeout or to remove
    unwanted stalled buffer requests or in any other use case.

  Precondition:
    DRV_AK4954_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle - Handle of the communication channel as returned by the
    DRV_AK4954_Open function.

  Returns:
    True - Write queue purge is successful.
    False - Write queue purge has failed.

  Remarks:
    This function is thread safe when used in an RTOS environment.
    Avoid this function call from within the callback.
*/

bool DRV_AK4954_WriteQueuePurge(const DRV_HANDLE handle)
{
    DRV_AK4954_CLIENT_OBJ *clientObj;
    DRV_AK4954_OBJ *drvObj;

    /* The Client and driver objects from the handle */
    clientObj = (DRV_AK4954_CLIENT_OBJ *) handle;
    drvObj = (DRV_AK4954_OBJ *) clientObj->hDriver;

    return DRV_I2S_WriteQueuePurge(drvObj->i2sDriverClientHandleWrite);
}

// *****************************************************************************
/* Function:
    bool DRV_AK4954_ReadQueuePurge( const DRV_HANDLE handle )

  Summary:
    Removes all buffer requests from the read queue.

  Description:
    This function removes all the buffer requests from the read queue.
    The client can use this function to purge the queue on timeout or to remove
    unwanted stalled buffer requests or in any other use case.

  Precondition:
    DRV_I2S_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle - Handle of the communication channel as returned by the
    DRV_AK4954_Open function.

  Returns:
    True - Read queue purge is successful.
    False - Read queue purge has failed.

  Remarks:
    This function is thread safe when used in an RTOS environment.
    Avoid this function call from within the callback.
*/

bool DRV_AK4954_ReadQueuePurge(const DRV_HANDLE handle)
{
    DRV_AK4954_CLIENT_OBJ *clientObj;
    DRV_AK4954_OBJ *drvObj;

    /* The Client and driver objects from the handle */
    clientObj = (DRV_AK4954_CLIENT_OBJ *) handle;
    drvObj = (DRV_AK4954_OBJ *) clientObj->hDriver;

    return DRV_I2S_ReadQueuePurge(drvObj->i2sDriverClientHandleRead);
}

// *****************************************************************************
/*
  Function:
	void DRV_AK4954_BufferEventHandlerSet
	(
		DRV_HANDLE handle,
		const DRV_AK4954_BUFFER_EVENT_HANDLER eventHandler,
		const uintptr_t contextHandle
	)

  Summary:
    This function allows a client to identify a buffer event handling function
    for the driver to call back when queued buffer transfers have finished.

  Description:
    This function allows a client to identify a buffer event handling function
    for the driver to call back when queued buffer transfers have finished.
    When a client calls DRV_AK4954_BufferAddWrite function, it is provided with
    a handle identifying  the buffer that was added to the driver's buffer queue.
    The driver will pass this handle back to the client by calling "eventHandler"
    function when the buffer transfer has completed.

    The event handler should be set before the client performs any "buffer add"
    operations that could generate events. The event handler once set, persists
    until the client closes the driver or sets another event handler (which
    could be a "NULL" pointer to indicate no callback).

  Precondition:
    The DRV_AK4954_Initialize routine must have been called for the specified
    AK4954 driver instance.

    DRV_AK4954_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine
    eventHandler - Pointer to the event handler function.
    context      - The value of parameter will be passed back to the client
                   unchanged, when the eventHandler function is called.  It can
                   be used to identify any client specific data object that
                   identifies the instance of the client module (for example,
                   it may be a pointer to the client module's state structure).

  Returns:
    None.
  Remarks:
    If the client does not want to be notified when the queued buffer transfer
    has completed, it does not need to register a callback.
*/

void DRV_AK4954_BufferEventHandlerSet
(
	DRV_HANDLE handle,
	const DRV_AK4954_BUFFER_EVENT_HANDLER eventHandler,
	const uintptr_t contextHandle
)
{
    DRV_AK4954_CLIENT_OBJ *clientObj;
    DRV_AK4954_OBJ *drvObj;

    if((DRV_HANDLE_INVALID == handle) || (0 == handle))
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return;
    }

    /* Assing the event handler and the context */
    clientObj = (DRV_AK4954_CLIENT_OBJ *) handle;
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid driver handle \r\n");
        return;
    }
    drvObj = clientObj->hDriver;
    /* Set the Event Handler and context */
    clientObj->pEventCallBack = eventHandler;
    clientObj->hClientArg = contextHandle;

    if((clientObj->ioIntent & DRV_IO_INTENT_READWRITE) == DRV_IO_INTENT_READWRITE)
    {

        DRV_I2S_BufferEventHandlerSet(drvObj->i2sDriverHandle,
        (DRV_I2S_BUFFER_EVENT_HANDLER) _DRV_AK4954_I2SBufferEventHandler,
        (uintptr_t)(clientObj));
    }
    else if((clientObj->ioIntent & DRV_IO_INTENT_READWRITE) == DRV_IO_INTENT_WRITE)
    {
        DRV_I2S_BufferEventHandlerSet(drvObj->i2sDriverClientHandleWrite,
        (DRV_I2S_BUFFER_EVENT_HANDLER) _DRV_AK4954_I2SBufferEventHandler,
        (uintptr_t)(clientObj));
    }
    else if((clientObj->ioIntent & DRV_IO_INTENT_READWRITE) == DRV_IO_INTENT_READ)
    {
        DRV_I2S_BufferEventHandlerSet(drvObj->i2sDriverClientHandleRead,
        (DRV_I2S_BUFFER_EVENT_HANDLER) _DRV_AK4954_I2SBufferEventHandler,
        (uintptr_t)(clientObj));
    }
} /* DRV_AK4954_BufferWriteEventHandlerSet */

void DRV_AK4954_I2SBufferHandlerSet
(
	DRV_HANDLE handle,
        DRV_I2S_BUFFER_EVENT_HANDLER I2SBufferEventHandler
)
{
    DRV_AK4954_CLIENT_OBJ *clientObj;
    DRV_AK4954_OBJ *drvObj;

    if((DRV_HANDLE_INVALID == handle) || (0 == handle))
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return;
    }

    /* Assing the event handler and the context */
    clientObj = (DRV_AK4954_CLIENT_OBJ *) handle;
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid driver handle \r\n");
        return;
    }
    drvObj = clientObj->hDriver;

    DRV_I2S_BufferEventHandlerSet(drvObj->i2sDriverHandle,
        (DRV_I2S_BUFFER_EVENT_HANDLER) I2SBufferEventHandler,
        (uintptr_t)(drvObj));
}

// *****************************************************************************
// *****************************************************************************
// Section: AK4954 Codec Specific Client Routines
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
/*
  Function:
    void DRV_AK4954_SamplingRateSet(DRV_HANDLE handle, uint32_t samplingRate)

  Summary:
    This function sets the sampling rate of the media stream.

  Description:
    This function sets the media sampling rate for the client handle.

  Precondition:
    The DRV_AK4954_Initialize routine must have been called for the specified
    AK4954 driver instance.

    DRV_AK4954_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine

  Returns:
    None
  Remarks:
    None.
*/

void DRV_AK4954_SamplingRateSet(DRV_HANDLE handle, uint32_t samplingRate)
{
    DRV_AK4954_OBJ *drvObj;
    DRV_AK4954_CLIENT_OBJ *clientObj;
    uint8_t regValue;

    if((DRV_HANDLE_INVALID == handle) || (0 == handle))
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return;
    }

    clientObj = (DRV_AK4954_CLIENT_OBJ *) handle;
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid driver handle \r\n");
        return;
    }
    drvObj = (DRV_AK4954_OBJ *)clientObj->hDriver;
    drvObj->samplingRate = samplingRate;

    DRV_I2S_RefClockSet(drvObj->i2sDriverHandle, SYS_TIME_CPU_CLOCK_FREQUENCY,
            drvObj->samplingRate, drvObj->mclk_multiplier);

    DRV_I2S_BaudRateSet(drvObj->i2sDriverHandle, drvObj->samplingRate*drvObj->bclk_divider,
            drvObj->samplingRate);

    drvObj->command = DRV_AK4954_COMMAND_SEND;

    AK4954_COMMAND *sampleRateSetCmd;
    sampleRateSetCmd = _DRV_AK4954_CommandQueueGetSlot();
    
    if(sampleRateSetCmd == NULL)
    {
        return;
    }
      
    regValue = _DRV_AK4954_CONTROL_REG_BIT_WRITE_Wrapper(drvObj,
               AK4954A_REG_MODE_CTRL2,
               0,
               _getAK4954_samplerate(samplingRate)
               );
    
    sampleRateSetCmd->command = DRV_AK4954_COMMAND_SAMPLING_RATE_SET;
    sampleRateSetCmd->control_data[0] = (uint8_t)(AK4954A_REG_MODE_CTRL2&0xFF);
    sampleRateSetCmd->control_data[1] = (uint8_t)(regValue&0xFF);
    sampleRateSetCmd->array_size = 2;   
}

// *****************************************************************************
/*
  Function:
    uint32_t DRV_AK4954_SamplingRateGet(DRV_HANDLE handle)

  Summary:
    This function gets the sampling rate set on the Ak4954

  Description:
    This function gets the sampling rate set on the Ak4954.

  Remarks:
    None.
 */

uint32_t DRV_AK4954_SamplingRateGet(DRV_HANDLE handle)
{
    DRV_AK4954_OBJ *drvObj;
    DRV_AK4954_CLIENT_OBJ *clientObj;

    if((DRV_HANDLE_INVALID == handle) || (0 == handle))
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return 0; //return invalid value
    }
    
    clientObj = (DRV_AK4954_CLIENT_OBJ *) handle;
    
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid driver handle \r\n");
        return 0;
    }
    
    drvObj = (DRV_AK4954_OBJ *)clientObj->hDriver;

    /* Return the sampling rate */
    return drvObj->samplingRate;
}

// *****************************************************************************
/*
  Function:
    void DRV_AK4954_VolumeSet(DRV_HANDLE handle, DRV_AK4954_CHANNEL channel, uint8_t volume)

  Summary:
    This function sets the volume for AK4954 Codec.

  Description:
    This functions sets the volume value from 0-255 which can attenuate
    from -115dB to +12dB. All decibles below -50dB are inbaudible

  Precondition:
    The DRV_AK4954_Initialize routine must have been called for the specified
    AK4954 driver instance.

    DRV_AK4954_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine

  Returns:
    None
  Remarks:
    None.
*/

void DRV_AK4954_VolumeSet(DRV_HANDLE handle, DRV_AK4954_CHANNEL channel, uint8_t volume)
{
    DRV_AK4954_OBJ *drvObj;
    DRV_AK4954_CLIENT_OBJ *clientObj;

    if((DRV_HANDLE_INVALID == handle) || (0 == handle))
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return;
    }
    
    clientObj = (DRV_AK4954_CLIENT_OBJ *) handle;
    
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid driver handle \r\n");
        return;
    }
    
    drvObj = (DRV_AK4954_OBJ *)clientObj->hDriver;
    drvObj->command = DRV_AK4954_COMMAND_SEND;

    if(!drvObj->isVolumeSetUnderProcess)
    {
        AK4954_COMMAND *volumeSetCmd;
        volumeSetCmd = _DRV_AK4954_CommandQueueGetSlot();
        if(volumeSetCmd == NULL)
        {
            return;
        }
        
        drvObj->isVolumeSetUnderProcess = true;
        if(DRV_AK4954_CHANNEL_LEFT == channel)
        {
            _DRV_AK4954_VolumeReMapping( drvObj, channel, volume);
            
            volumeSetCmd->command = DRV_AK4954_COMMAND_VOLUME_SET_CHANNEL_LEFT_ONLY;
            volumeSetCmd->control_data[0] = (uint8_t)(AK4954A_REG_LDIG_VOL_CTRL&0xFF);
            volumeSetCmd->control_data[1] = (uint8_t)(drvObj->volume[DRV_AK4954_CHANNEL_LEFT]&0xFF);
            volumeSetCmd->array_size = 2;
        }
        else if(DRV_AK4954_CHANNEL_RIGHT == channel)
        {
            _DRV_AK4954_VolumeReMapping( drvObj, channel, volume);

            volumeSetCmd->command = DRV_AK4954_COMMAND_VOLUME_SET_CHANNEL_RIGHT_ONLY;
            volumeSetCmd->control_data[0] = (uint8_t)(AK4954A_REG_RDIG_VOL_CTRL&0xFF);
            volumeSetCmd->control_data[1] = (uint8_t)(drvObj->volume[DRV_AK4954_CHANNEL_RIGHT]&0xFF);
            volumeSetCmd->array_size = 2;
        }
        else
        {
            _DRV_AK4954_VolumeReMapping( drvObj, DRV_AK4954_CHANNEL_LEFT, volume);
            _DRV_AK4954_VolumeReMapping( drvObj, DRV_AK4954_CHANNEL_RIGHT, volume);

            volumeSetCmd->command = DRV_AK4954_COMMAND_VOLUME_SET_CHANNEL_LEFT;
            volumeSetCmd->control_data[0] = (uint8_t)(AK4954A_REG_LDIG_VOL_CTRL&0xFF);
            volumeSetCmd->control_data[1] = (uint8_t)(drvObj->volume[DRV_AK4954_CHANNEL_LEFT]&0xFF);
            volumeSetCmd->control_data[2] = (uint8_t)(drvObj->volume[DRV_AK4954_CHANNEL_RIGHT]&0xFF);
            volumeSetCmd->array_size = 3;
        }
        drvObj->isVolumeSetUnderProcess = false;
    }
    else
    {
        ; // Volume set under process
    }
}

// *****************************************************************************
/*
  Function:
    uint8_t DRV_AK4954_VolumeGet(DRV_HANDLE handle, DRV_AK4954_CHANNEL chan)

  Summary:
    This function gets the volume for AK4954 Codec.

  Description:
    This functions gets the current volume programmed to the DAC AK4954.

  Precondition:
    The DRV_AK4954_Initialize routine must have been called for the specified
    AK4954 driver instance.

    DRV_AK4954_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine

    chan         - Audio channel volume to be set,

  Returns:
    None

  Example:
    <code>
    // myAppObj is an application specific object.
    MY_APP_OBJ myAppObj;
    uint8_t volume;

    // myAK4954Handle is the handle returned
    // by the DRV_AK4954_Open function.

      volume = DRV_AK4954_VolumeGet(myAK4954Handle, DRV_AK4954_CHANNEL_LEFT);
    </code>

  Remarks:
    None.
 */

uint8_t DRV_AK4954_VolumeGet(DRV_HANDLE handle, DRV_AK4954_CHANNEL chan)
{
    DRV_AK4954_OBJ *drvObj;
    DRV_AK4954_CLIENT_OBJ *clientObj;
    
    if((DRV_HANDLE_INVALID == handle) || (0 == handle))
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return 0;
    }

    clientObj = (DRV_AK4954_CLIENT_OBJ *) handle;
    
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid driver handle \r\n");
        return 0;
    }
    
    drvObj = (DRV_AK4954_OBJ *)clientObj->hDriver;

    /* Return the volume */
    return drvObj->volume[chan];
}

// *****************************************************************************
/*
  Function:
    void DRV_AK4954_MuteOn(DRV_HANDLE handle);

  Summary:
    This function allows AK4954 output for soft mute on.

  Description:
    This function Enables AK4954 output for soft mute.

  Remarks:
    None.
*/

void DRV_AK4954_MuteOn(DRV_HANDLE handle)
{
    DRV_AK4954_OBJ *drvObj;
    DRV_AK4954_CLIENT_OBJ *clientObj;
    uint8_t regValue;

    if((DRV_HANDLE_INVALID == handle) || (0 == handle))
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return;
    }
    
    clientObj = (DRV_AK4954_CLIENT_OBJ *) handle;
    
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid driver handle \r\n");
        return;
    }
    
    drvObj = (DRV_AK4954_OBJ *)clientObj->hDriver;
    // Mute on is executed already, no need to send a I2C command
    if((drvObj->lastRegValue[AK4954A_REG_MODE_CTRL3] & 0x20) >> 5 == 0x01){
        return;
    }
    drvObj->command = DRV_AK4954_COMMAND_SEND;

    AK4954_COMMAND *muteOnCmd;
    muteOnCmd = _DRV_AK4954_CommandQueueGetSlot();
    if(muteOnCmd == NULL)
    {
        return;
    }
    regValue = _DRV_AK4954_CONTROL_REG_BIT_WRITE_Wrapper(drvObj,
               AK4954A_REG_MODE_CTRL3,
               5,
               0x1
               );
    
    muteOnCmd->command = DRV_AK4954_COMMAND_MUTE_ON;
    muteOnCmd->control_data[0] = (uint8_t)(AK4954A_REG_MODE_CTRL3&0xFF);
    muteOnCmd->control_data[1] = (uint8_t)(regValue&0xFF);
    muteOnCmd->array_size = 2;
}

// *****************************************************************************
/*
  Function:
    void DRV_AK4954_MuteOff(DRV_HANDLE handle)

  Summary:
    This function disables AK4954 output for soft mute.

  Description:
    This function disables AK4954 output for soft mute.

    Remarks:
    None.
*/

void DRV_AK4954_MuteOff(DRV_HANDLE handle)
{
    DRV_AK4954_OBJ *drvObj;
    DRV_AK4954_CLIENT_OBJ *clientObj;
    uint8_t regValue;

    if((DRV_HANDLE_INVALID == handle) || (0 == handle))
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return;
    }
    
    clientObj       = (DRV_AK4954_CLIENT_OBJ *) handle;
    
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid driver handle \r\n");
        return;
    }
    
    drvObj          = (DRV_AK4954_OBJ *)clientObj->hDriver;
    // Mute off is executed already, no need to send a I2C command
    if((drvObj->lastRegValue[AK4954A_REG_MODE_CTRL3] & 0x20) >> 5 == 0x00){
        return;
    }
    drvObj->command = DRV_AK4954_COMMAND_SEND;

    regValue = _DRV_AK4954_CONTROL_REG_BIT_WRITE_Wrapper(drvObj,
               AK4954A_REG_MODE_CTRL3,
               5,
               0x0
               );
//            DRV_AK4954_CONTROL_REG_BIT_WRITE(
//                    drvObj->lastRegValue[AK4954A_REG_MODE_CTRL3],
//                    5,0x0);

    AK4954_COMMAND *muteOffCmd;
    muteOffCmd = _DRV_AK4954_CommandQueueGetSlot();
    if(muteOffCmd == NULL)
    {
        return;
    }
    
    muteOffCmd->command = DRV_AK4954_COMMAND_MUTE_OFF;
    muteOffCmd->control_data[0] = (uint8_t)(AK4954A_REG_MODE_CTRL3&0xFF);
    muteOffCmd->control_data[1] = (uint8_t)(regValue&0xFF);
    muteOffCmd->array_size = 2;
}

// *****************************************************************************
/*
  Function:
    void DRV_AK4954_DigitalBlockModeSet(DRV_HANDLE handle)

  Summary:
    This function allows function selection amongst Recording, Playback, Both or Loopback provided by the codec

  Description:
     This function allows function selection amongst Recording, Playback, Both or Loopback provided by the codec


  Returns:
    None

  Remarks:
    None.
*/

void DRV_AK4954_DigitalBlockModeSet(DRV_HANDLE handle, DRV_AK4954_DIGITAL_BLOCK_CONTROL digitalblockControl)
{
    DRV_AK4954_OBJ *drvObj;
    DRV_AK4954_CLIENT_OBJ *clientObj;
    uint8_t regValue;

    if((DRV_HANDLE_INVALID == handle) || (0 == handle))
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return;
    }
    
    clientObj       = (DRV_AK4954_CLIENT_OBJ *) handle;
    
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid driver handle \r\n");
        return;
    }
    
    drvObj          = (DRV_AK4954_OBJ *)clientObj->hDriver;
    drvObj->command = DRV_AK4954_COMMAND_SEND;

    switch(digitalblockControl)
    {
        case DRV_AK4954_RECORDING_MODE:
        {
                regValue = DRV_AK4954_CONTROL_REG_FIELD_WRITE(
                    drvObj->lastRegValue[AK4954A_REG_DFLTR_MODE],
                    0x07,0x0,0x03);
        }
        break;

        case DRV_AK4954_PLAYBACK_MODE:
        {
                regValue = DRV_AK4954_CONTROL_REG_FIELD_WRITE(
                    drvObj->lastRegValue[AK4954A_REG_DFLTR_MODE],
                    0x07,0x0,0x04);
        }
        break;

        case DRV_AK4954_RECORDING_PLAYBACK_2_MODE:
        {
                regValue = DRV_AK4954_CONTROL_REG_FIELD_WRITE(
                    drvObj->lastRegValue[AK4954A_REG_DFLTR_MODE],
                    0x03,0x0,0x00);
        }
        case DRV_AK4954_LOOPBACK_MODE :
        {
                regValue = DRV_AK4954_CONTROL_REG_FIELD_WRITE(
                    drvObj->lastRegValue[AK4954A_REG_DFLTR_MODE],
                    0x07,0x0,0x07);
        }
        default:
        {
                regValue = DRV_AK4954_CONTROL_REG_FIELD_WRITE(
                    drvObj->lastRegValue[AK4954A_REG_DFLTR_MODE],
                    0x07,0x0,0x04);
        }
        break;
    }
    
    AK4954_COMMAND *DigitalModeCmd;
    DigitalModeCmd = _DRV_AK4954_CommandQueueGetSlot();
    if(DigitalModeCmd == NULL)
    {
        return;
    }
    
    DigitalModeCmd->command = DRV_AK4954_COMMAND_DIGITAL_BLOCK_CONTROL_SET;
    DigitalModeCmd->control_data[0] = (uint8_t)(AK4954A_REG_DFLTR_MODE&0xFF);
    DigitalModeCmd->control_data[1] = (uint8_t)(regValue&0xFF);
    DigitalModeCmd->array_size = 2;
}

// *****************************************************************************
/*
  Function:
    void DRV_AK4954_IntExtMicSet(DRV_HANDLE handle);

  Summary:
    This function sets up the codec for the internal or the external microphone use.

  Description:
    This function sets up the codec for the internal or the external microphone use.

  Precondition:
    The DRV_AK4954_Initialize routine must have been called for the specified
    AK4954 driver instance.

    DRV_AK4954_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine
    micInput     - Internal vs External mic input
  Returns:
    None

  Remarks:
    None.
*/

void DRV_AK4954_IntExtMicSet(DRV_HANDLE handle, DRV_AK4954_INT_EXT_MIC micInput)
{
    if (micInput == INT_MIC)
    {
        //Internal Mic for AK4954 X32 DB
         DRV_AK4954_MicSet(handle, MIC1);
    }
    else
    {
        //External Mic for AK4954 X32 DB
         DRV_AK4954_MicSet(handle, MIC2);
    }
}

uint8_t _convertGainToMGain(uint8_t gain)
{
    uint8_t ret;
    // convert external gain setting 0-31 to internal MGAIN value
    if (gain << 6)
    {
        ret = SIGSLCT1_MGAIN_0DB;
    }
    else if (gain < 13)
    {
        ret = SIGSLCT1_MGAIN_6DB;
    }
    else if (gain < 20)
    {
        ret = SIGSLCT1_MGAIN_13DB;
    }   
    else if (gain < 26)
    {
        ret = SIGSLCT1_MGAIN_20DB;
    }   
    else
    {
        ret = SIGSLCT1_MGAIN_26DB;
    }
    
    return ret;
}

// *****************************************************************************
/*
  Function: 
    void DRV_AK4954_MicSet(DRV_HANDLE handle, DRV_AK4954_MIC micInput);

  Summary:
    This function select the single-ended AK4954 microphone
    input for the AK4954 Codec 

  Description:
    This function selects the single-ended AK4954 microphone
    input for the AK4954 Codec (Where the MEMS mic is MIC1, and the 
    external Microphone input is MIC2 on the AK4954 XC32 Daughter Board)

  Precondition:
    The DRV_AK4954_Initialize routine must have been called for the specified
    AK4954 driver instance.

    DRV_AK4954_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine
    micInput     - MIC1 or MIC2

  Returns:
    None

  Remarks:
    None.
*/

void DRV_AK4954_MicSet(DRV_HANDLE handle, DRV_AK4954_MIC micInput)
{
    DRV_AK4954_OBJ *drvObj;
    DRV_AK4954_CLIENT_OBJ *clientObj;
    uint8_t regValue0, regValue1, gain;
    
    if((DRV_HANDLE_INVALID == handle) || (0 == handle))
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return;
    }

    clientObj = (DRV_AK4954_CLIENT_OBJ *) handle;
    
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid driver handle \r\n");
        return;
    }
    
    drvObj = (DRV_AK4954_OBJ *)clientObj->hDriver;
    drvObj->command = DRV_AK4954_COMMAND_SEND;
    
    gain = _convertGainToMGain(drvObj->micGain);
    
    switch (micInput)
    {
        case MIC1:
        {
            if(drvObj->lastRegValue[AK4954A_REG_SIG_SLCT1] == 
               (DRV_AK4954_CONTROL_REG_FIELD_WRITE(AK4954A_REG_SIG_SLCT1, 
                                                   0x10, 
                                                   0, 
                                                   0)) && 
               drvObj->lastRegValue[AK4954A_REG_SIG_SLCT2] == 
               (DRV_AK4954_CONTROL_REG_FIELD_WRITE(AK4954A_REG_SIG_SLCT2, 
                                                   0x0F, 
                                                   0, 
                                                   0)))
            {
                return;
            }
            //MPSEL: MPWR Output Select
            regValue0 = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                        AK4954A_REG_SIG_SLCT1,
                        0x10,
                        0, 
                        0x0
                        );
            regValue1 = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                        AK4954A_REG_SIG_SLCT2,
                        0x0F,
                        0, 
                        0x0
                        );
        } //End MIC1
        break;

        case MIC2:
        {   //External Mic
            if(drvObj->lastRegValue[AK4954A_REG_SIG_SLCT1] == 
               (DRV_AK4954_CONTROL_REG_FIELD_WRITE(AK4954A_REG_SIG_SLCT1, 
                                                   0x17, 
                                                   0, 
                                                   SIGSLCT1_MPSEL_UP |
                                                   gain << SIGSLCT1_MGAIN_SHIFT)) && 
               drvObj->lastRegValue[AK4954A_REG_SIG_SLCT2] == 
               (DRV_AK4954_CONTROL_REG_FIELD_WRITE(AK4954A_REG_SIG_SLCT2, 
                                                   0x0F, 
                                                   0, 
                                                   SIGSLCT2_INL0_ON | 
                                                   SIGSLCT2_INR0_ON)))
            {
                return;
            }

            //MPWR2 w/ selected gain
            regValue0 = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(
                                drvObj,
                                AK4954A_REG_SIG_SLCT1,
                                0x17,
                                0, 
                                SIGSLCT1_MPSEL_UP |
                                gain << SIGSLCT1_MGAIN_SHIFT);                
            //MIC2
            regValue1 = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(
                                drvObj,
                                AK4954A_REG_SIG_SLCT2,
                                0x0F,
                                0, 
                                SIGSLCT2_INL0_ON | SIGSLCT2_INR0_ON);
        } //End MIC2
        break;

        case MIC3:
        {
            // selected gain only
            if(drvObj->lastRegValue[AK4954A_REG_SIG_SLCT1] == 
               (DRV_AK4954_CONTROL_REG_FIELD_WRITE(AK4954A_REG_SIG_SLCT1, 
                                                   0x17, 
                                                   0, 
                                                   gain << SIGSLCT1_MGAIN_SHIFT) ) && 

                drvObj->lastRegValue[AK4954A_REG_SIG_SLCT2] == 
                (DRV_AK4954_CONTROL_REG_FIELD_WRITE(AK4954A_REG_SIG_SLCT2, 
                                                    0x0F, 
                                                    0, 
                                                    SIGSLCT2_INL1_ON | 
                                                    SIGSLCT2_INR1_ON))  )
            {
                return;
            }

            //No MPWR, +20dB Gain
            regValue0 = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(
                                drvObj,
                                AK4954A_REG_SIG_SLCT1,
                                0x17,
                                0, 
                                gain << SIGSLCT1_MGAIN_SHIFT);

            //MIC3
            regValue1 = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(
                                drvObj,
                                AK4954A_REG_SIG_SLCT2,
                                0x0F,
                                0, 
                                SIGSLCT2_INL1_ON | SIGSLCT2_INR1_ON);
        }
        break;

        default: //MIC1
        {
            if(drvObj->lastRegValue[AK4954A_REG_SIG_SLCT1] == 
               (DRV_AK4954_CONTROL_REG_FIELD_WRITE(AK4954A_REG_SIG_SLCT1, 
                                                   0x10, 
                                                   0, 
                                                   SIGSLCT1_MPSEL_UP)) && 
               drvObj->lastRegValue[AK4954A_REG_SIG_SLCT2] == 
               (DRV_AK4954_CONTROL_REG_FIELD_WRITE(AK4954A_REG_SIG_SLCT2, 
                                                   0x0F, 
                                                   0, 
                                                   SIGSLCT2_INL0_ON | 
                                                   SIGSLCT2_INR0_ON)))
            {
                return;
            }

            regValue0 = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(
                                drvObj,
                                AK4954A_REG_SIG_SLCT1,
                                0x10,
                                0, 
                                SIGSLCT1_MPSEL_UP);

            regValue1 = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(
                                drvObj,
                                AK4954A_REG_SIG_SLCT2,
                                0x0F,
                                0, 
                                SIGSLCT2_INL0_ON | SIGSLCT2_INR0_ON);
        }
        break;
    } //End default
    
    AK4954_COMMAND *micSetCmd;
    micSetCmd = _DRV_AK4954_CommandQueueGetSlot();
    if(micSetCmd == NULL)
    {
        return;
    }
    
    micSetCmd->command = DRV_AK4954_COMMAND_MIC_SET;
    micSetCmd->control_data[0] = (uint8_t)(AK4954A_REG_SIG_SLCT1&0xFF);
    micSetCmd->control_data[1] = (uint8_t)(regValue0&0xFF);
    micSetCmd->control_data[2] = (uint8_t)(regValue1&0xFF);
    micSetCmd->array_size = 3;
}

// *****************************************************************************
/*
  Function:
    void DRV_AK4954_MonoStereoMicSet(DRV_HANDLE handle);

  Summary:
    This function sets up the codec for the Mono or Stereo microphone mode.

  Description:
    This function sets up the codec for the Mono or Stereo microphone mode.

  Precondition:
    The DRV_AK4954_Initialize routine must have been called for the specified
    AK4954 driver instance.

    DRV_AK4954_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine
  Returns:
    None

  Remarks:
    None.
*/

void DRV_AK4954_MonoStereoMicSet(DRV_HANDLE handle, DRV_AK4954_MONO_STEREO_MIC mono_stereo_mic)
{
    DRV_AK4954_OBJ *drvObj;
    DRV_AK4954_CLIENT_OBJ *clientObj;
    uint8_t regValue;

    if(mono_stereo_mic == ALL_ZEROS){
        return;
    }
    
    if((DRV_HANDLE_INVALID == handle) || (0 == handle))
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return;
    }
    
    clientObj = (DRV_AK4954_CLIENT_OBJ *) handle;
    
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid driver handle \r\n");
        return;
    }
    
    drvObj = (DRV_AK4954_OBJ *)clientObj->hDriver;
    drvObj->command = DRV_AK4954_COMMAND_SEND;

    switch(mono_stereo_mic)
    {
        case MONO_RIGHT_CHANNEL:
            if(drvObj->lastRegValue[AK4954A_REG_PWR_MGMT1] == (DRV_AK4954_CONTROL_REG_FIELD_WRITE(AK4954A_REG_PWR_MGMT1, 0x03, 0, PWRMGMT1_PMADR_UP))){
                return;
            }
            
            regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                        AK4954A_REG_PWR_MGMT1,
                        0x03, 
                        0, 
                        PWRMGMT1_PMADR_UP
                        );
            break;
        case MONO_LEFT_CHANNEL:
            if(drvObj->lastRegValue[AK4954A_REG_PWR_MGMT1] == (DRV_AK4954_CONTROL_REG_FIELD_WRITE(AK4954A_REG_PWR_MGMT1, 0x03, 0, PWRMGMT1_PMADL_UP))){
                return;
            }
            regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                        AK4954A_REG_PWR_MGMT1,
                        0x03, 
                        0, 
                        PWRMGMT1_PMADL_UP
                        );
            break;
        case STEREO:
            if(drvObj->lastRegValue[AK4954A_REG_PWR_MGMT1] == (DRV_AK4954_CONTROL_REG_FIELD_WRITE(AK4954A_REG_PWR_MGMT1, 0x03, 0, PWRMGMT1_PMADL_UP|PWRMGMT1_PMADR_UP))){
                return;
            }
            regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                        AK4954A_REG_PWR_MGMT1,
                        0x03, 
                        0, 
                        PWRMGMT1_PMADL_UP | PWRMGMT1_PMADR_UP
                        );
            break;
        default:
            if(drvObj->lastRegValue[AK4954A_REG_PWR_MGMT1] == (DRV_AK4954_CONTROL_REG_FIELD_WRITE(AK4954A_REG_PWR_MGMT1, 0x03, 0, PWRMGMT1_PMADL_UP))){
                return;
            }
            regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                        AK4954A_REG_PWR_MGMT1,
                        0x03,
                        0,
                        PWRMGMT1_PMADL_UP
                        );
            break;

    }
    
    AK4954_COMMAND *channelSetCmd;
    channelSetCmd = _DRV_AK4954_CommandQueueGetSlot();
    if(channelSetCmd == NULL)
    {
        return;
    }  
    
    channelSetCmd->command = DRV_AK4954_COMMAND_MONO_STEREO_MIC_SET;
    channelSetCmd->control_data[0] = (uint8_t)(AK4954A_REG_PWR_MGMT1&0xFF);
    channelSetCmd->control_data[1] = (uint8_t)(regValue&0xFF);
    channelSetCmd->array_size = 2;
}

// *****************************************************************************
/*
  Function:
	void DRV_AK4954_CommandEventHandlerSet
	(
		DRV_HANDLE handle,
		const DRV_AK4954_COMMAND_EVENT_HANDLER eventHandler,
		const uintptr_t contextHandle
	)

  Summary:
    This function allows a client to identify a command event handling function
    for the driver to call back when the last submitted command have finished.

  Description:
    This function allows a client to identify a command event handling function
    for the driver to call back when the last submitted command have finished.

    When a client calls DRV_AK4954_BufferAddWrite function, it is provided with
    a handle identifying  the buffer that was added to the driver's buffer queue.
    The driver will pass this handle back to the client by calling "eventHandler"
    function when the buffer transfer has completed.

    The event handler should be set before the client performs any "AK4954 CODEC
    Specific Client Routines" operations that could generate events.
    The event handler once set, persists until the client closes the driver or
    sets another event handler (which could be a "NULL" pointer to indicate no callback).

  Remarks:
    If the client does not want to be notified when the command
    has completed, it does not need to register a callback.
*/

void DRV_AK4954_CommandEventHandlerSet
(
	DRV_HANDLE handle,
	const DRV_AK4954_COMMAND_EVENT_HANDLER eventHandler,
	const uintptr_t contextHandle
)
{
    DRV_AK4954_CLIENT_OBJ *clientObj;
    DRV_AK4954_OBJ *drvObj;

    if((DRV_HANDLE_INVALID == handle) || (0 == handle))
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return;
    }

    clientObj = (DRV_AK4954_CLIENT_OBJ *) handle;
    /* Assing the event handler and the context */
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid driver handle \r\n");
        return;
    }

    drvObj = (DRV_AK4954_OBJ *)clientObj->hDriver;
    drvObj->commandCompleteCallback = eventHandler;
    drvObj->commandContextData = contextHandle;
}

// *****************************************************************************
// *****************************************************************************
// Section: AK4954 Codec Version Information Routines
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
/*
  Function:
    int8_t* DRV_AK4954_VersionStrGet(void)

  Summary:
    This function returns the version of AK4954 driver in string format.

  Description:
    The DRV_AK4954_VersionStrGet function returns a string in the format:
    "<major>.<minor>[.<patch>][<type>]"
    Where:
        <major> is the AK4954 driver's version number.
        <minor> is the AK4954 driver's version number.
        <patch> is an optional "patch" or "dot" release number (which is not
        included in the string if it equals "00").
        <type> is an optional release type ("a" for alpha, "b" for beta ?
        not the entire word spelled out) that is not included if the release
        is a production version (I.e. Not an alpha or beta).

        The String does not contain any spaces.

        Example:
        "0.03a"
        "1.00"

  Remarks:
    None
 */
int8_t* DRV_AK4954_VersionStrGet(void)
{
    return (int8_t*) _DRV_AK4954_VERSION_STR;
}

// *****************************************************************************
/*
  Function:
    uint32_t DRV_AK4954_VersionGet( void )

  Summary:
    This function returns the version of AK4954 driver

  Description:
    The version number returned from the DRV_AK4954_VersionGet function is an
    unsigned integer in the following decimal format.
    <major> * 10000 + <minor> * 100 + <patch>

    Where the numbers are represented in decimal and the meaning is the same as
    above.  Note that there is no numerical representation of release type.

    Example:
    For version "0.03a", return:  0 * 10000 + 3 * 100 + 0
    For version "1.00", return:  1 * 100000 + 0 * 100 + 0

  Remarks:
    None
 */
uint32_t DRV_AK4954_VersionGet(void)
{
    return (_DRV_AK4954_VERSION_MAJOR * 10000 +  \
            _DRV_AK4954_VERSION_MINOR * 100 + \
            _DRV_AK4954_VERSION_PATCH);
}

// *****************************************************************************
// *****************************************************************************
// Section: local functions
// *****************************************************************************
// ****************************************************************************
/* Function:
    static void _DRV_AK4954_VolumeReMapping( DRV_AK4954_OBJ* drvObj, uint8_t volume)

  Summary:
    Volume remapping to reverse the codec volume value to dB mapping which currently works reverse

  Description:
    Volume remapping to reverse the codec volume value to dB mapping which currently works reverse
 The ak4954 codec has DAC value to volume range mapping as :-
 00 H : +12dB
 FF H : -115dB
 In order to provide to the user a more intuitive DAC value to dB correspondance, this remapping fucntion reverses the volume value to dB mapping
 so that 00 H : -115 dB
         FF H : +12 dB

  Parameters:
    object          - Driver object handle, returned from the
                      DRV_AK4954_Initialize routine
    volume          - 0 - 255 value supported by the codec for volume adjustment

  Returns:
    None.
  Remarks:
    Note that the allowed range of the codec stretches from +12dB to -115 dB.
    However for most applications, the entire dB range is not audible.
    It might be observed that values 80 and below for the volume input might not have audible dB values.

*/
static void _DRV_AK4954_VolumeReMapping( DRV_AK4954_OBJ* drvObj, DRV_AK4954_CHANNEL channel, uint8_t volume)
{
   //int volCtrl = (255 - volume);

    uint8_t gainValue;
    uint8_t gainDACBits;

    gainValue = ( ((MAX_VOLUME_CODE-MIN_VOLUME_CODE)*((int16_t)volume) )>>8 ) + MIN_VOLUME_CODE;
    gainDACBits = 0xFF - gainValue; // 0x00 = max gain, 0xFF = mute

    int volCtrl = gainDACBits;
   drvObj->volume[channel] =  volCtrl;

}/*DRV_AK4954_VolumeReMapping*/

// *****************************************************************************

/*  Function:
        static void _DRV_AK4954_ConrolRegisterReSet
        (
            DRV_AK4954_OBJ *drvObj,
            DRV_AK4954_CONTROL_REGISTER contRegister,
            uint8_t value
        )

  Summary:
    Writes 00 written to AK4954 register address.
 	Writes 00 written to AK4954 register data.
  Description:
    Writes 00 written to AK4954 register address.
 	Writes 00 written to AK4954 register data.
 	Codec ak4954 needs these dummy values of 00H for address and 00H for data to be written to it to start the codec configuration
  Remarks:
    None
*/

static DRV_HANDLE _DRV_AK4954_ConrolRegisterReSet
(
    DRV_AK4954_OBJ *drvObj,
    uint8_t *controlData,
    uint32_t size
)
{
    DRV_I2C_WriteTransferAdd( drvObj->drvI2CMasterHandle,
                              AK4954_I2C_ADDR,
                              (uint8_t *)controlData, 
                              size,
                              &drvObj->hWriteTransfer );     
    
    drvObj->controlCommandStatus = false;
    return drvObj->hWriteTransfer;
}

// *****************************************************************************
/*  Function:
        static void _DRV_AK4954_ConrolRegisterSet
        (
            DRV_AK4954_OBJ *drvObj,
            uint8_t *controlData,
            uint32_t size
        )

  Summary:
    Writes bytes to AK4954 register .

  Description:
    Writes bytes to AK4954 register .

  Remarks:
    None
*/
static uintptr_t _DRV_AK4954_ConrolRegisterSet
(
    DRV_AK4954_OBJ *drvObj,
    uint8_t *controlData,
    uint32_t size
)
{   
    DRV_I2C_WriteTransferAdd( drvObj->drvI2CMasterHandle,
                              AK4954_I2C_ADDR,
                              (uint8_t *)controlData,
                              size,
                              &drvObj->hWriteTransfer );
    
    drvObj->controlCommandStatus = false;
    return drvObj->hWriteTransfer;
}

// *****************************************************************************
 /*
  Function:
    static void _DRV_AK4954_ControlTasks(DRV_AK4954_OBJ *drvObj)

  Summary:
    Implements the state machine for the Audio control interface of AK4954

  Description:
    Implements the state machine for the Audio control interface of AK4954

  Remarks:
    None
*/
static void _DRV_AK4954_ControlTasks(DRV_AK4954_OBJ *drvObj)
{
    volatile uint8_t regValue;

    switch (drvObj->command)
    {
        case DRV_AK4954_COMMAND_NONE:
        {
            /* Do nothing. No Control Command executed */
            ;
        }
        break;

        case DRV_AK4954_COMMAND_INIT_CLK_PDN_SET:
        {
			/* Generate master clock from REFCLOCK for the given sampling rate */
            DRV_I2S_RefClockSet(drvObj->i2sDriverHandle, SYS_TIME_CPU_CLOCK_FREQUENCY,
                    drvObj->samplingRate, drvObj->mclk_multiplier);

            /* If the delayDriverInitialization option is enabled, we will skip
               toggling the chip's reset pin, since we assume it is tied to a
               common reset line shared with other peripherals such as a
               Bluetooth module, that has already been toggled (which would
               have earlier reset the codec). */
             
            if (drvObj->delayDriverInitialization==false)
            {
               /* Reset Values for Control interface  and power down pins */
              STBYRST_Clear();

               /* Bring power down out of reset */
               STBYRST_Set();
            }
            
            drvObj->writeComplete = false;

            //AK4954 needs a sequence of dummy address 00 and dummy data 00 to get I2C communication started.
            command_array[0] = 0;
            command_array[1] = 0;
            drvObj->drvI2CBuffHandle = _DRV_AK4954_ConrolRegisterReSet(drvObj, command_array, 2);

            drvObj->command = DRV_AK4954_COMMAND_INIT_START;            
        }
        break;
               
        case DRV_AK4954_COMMAND_INIT_START:
        {            
            if (drvObj->writeComplete && (false == drvObj->controlCommandStatus))
            {
                drvObj->controlCommandStatus = true;

                // Write to 0x00~0x12 control address in one operation
                
                // Set PMPFIL bit to enable microphone function
                regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                            AK4954A_REG_PWR_MGMT1,
                            0xFF,
                            0,					
                            PWRMGMT1_PMPFIL_UP | PWRMGMT1_PMVCM_UP | 
                            PWRMGMT1_PMDAC_UP | 
                            PWRMGMT1_PMADL_UP | PWRMGMT1_PMADR_UP   //Stereo Mic selected
                            );
                command_array[0] = (uint8_t)(AK4954A_REG_PWR_MGMT1&0xFF);
                command_array[1] = regValue;

                if (drvObj->masterMode)
                {
                    regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                                AK4954A_REG_PWR_MGMT2,
                                0xFF,
                                0,
                                PWRMGMT2_MS_MASTER | PWRMGMT2_PMHPL_UP | PWRMGMT2_PMHPR_UP
                                );
                }
                else
                {
                    regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                                AK4954A_REG_PWR_MGMT2,
                                0xFF,
                                0,
                                PWRMGMT2_PMHPL_UP | PWRMGMT2_PMHPR_UP       // o.w. slave
                                );
                }
                command_array[2] = regValue;               

                if ((drvObj->whichMicInput == MIC2) && drvObj->enableMicBias)
                {
                    // if external mic selected and mic bias enabled, select MPWR2
                    regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                                AK4954A_REG_SIG_SLCT1,
                                0xFF,
                                0,						
                                SIGSLCT1_SLPSN_UP | SIGSLCT1_MPSEL_UP |
                                SIGSLCT1_PMMP_UP
                                );
                }
                else
                {
                    // else default to MPWR pin (default)
                    regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                                AK4954A_REG_SIG_SLCT1,
                                0xFF,
                                0,						
                                SIGSLCT1_SLPSN_UP |
                                SIGSLCT1_PMMP_UP
                                );
                }
                command_array[3] = regValue;

                regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                            AK4954A_REG_SIG_SLCT2,
                            0xFF,
                            0,						
                            SIGSLCT2_SLG0_ON |
                            drvObj->whichMicInput << SIGSLCT2_INL_SHIFT |   // left channel mic
                            drvObj->whichMicInput << SIGSLCT2_INR_SHIFT     // right channel mic
                            );
                command_array[4] = regValue;
               
                regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                            AK4954A_REG_SIG_SLCT3,
                            0xFF,
                            0,
                            0x30 | SIGSLCT3_PTS0_UP     // bits 4 and 5 always 1
                            );
                command_array[5] = regValue;
               
                regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                            AK4954A_REG_MODE_CTRL1,
                            0xFF,
                            0, 
                            drvObj->audioDataFormat
                            );
                command_array[6] = regValue;

                regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                            AK4954A_REG_MODE_CTRL2,
                            0xFF,
                            0,
                            _getAK4954_samplerate(drvObj->samplingRate)
                            );
                command_array[7] = regValue;

                regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                            AK4954A_REG_MODE_CTRL3,
                            0xFF,
                            0,							
                            MODECTRL3_DVOLC_UP
                            );
                command_array[8] = regValue;

                regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                            AK4954A_REG_DIG_MIC,
                            0xFF,
                            0,
                            0x00    //Digital Mic de-selected
                            );
                command_array[9] = regValue;
                
                regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                            AK4954A_REG_TMR_SLCT,
                            0xFF,
                            0,
                            0x30 | TMRSLCT_DVTM0_UP     // bits 4 and 5 always 1
                            );
                command_array[10] = regValue;

                 regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                            AK4954A_REG_ALC_TMR_SLCT,
                            0xFF,
                            0,
                            0x00
                            );
                command_array[11] = regValue;
                 
                regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                            AK4954A_REG_ALC_MODE_CTRL1,
                            0xFF,
                            0,
                            0x00
                            );
                command_array[12] = regValue;

                regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                            AK4954A_REG_ALC_MODE_CTRL2,
                            0xFF,
                            0,
                            0xE1
                            );
                command_array[13] = regValue;

                regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                            AK4954A_REG_LIN_VOL_CTRL,
                            0xFF,
                            0,
                            0xA1
                            );
                command_array[14] = regValue;

                regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                            AK4954A_REG_RIN_VOL_CTRL,
                            0xFF,
                            0,
                            0xA1
                            );
                command_array[15] = regValue;
                
                drvObj->writeComplete = false;
                drvObj->drvI2CBuffHandle = _DRV_AK4954_ConrolRegisterSet(drvObj, command_array, sizeof(command_array));

                drvObj->command = DRV_AK4954_COMMAND_DFLTR_MODE_SET;                
            }
        }
        break;
        
        case DRV_AK4954_COMMAND_DFLTR_MODE_SET:
        {           
            if (drvObj->writeComplete && (false == drvObj->controlCommandStatus))
            {
                drvObj->controlCommandStatus = true;
                regValue = _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(drvObj,
                            AK4954A_REG_DFLTR_MODE,
                            0x07,
                            0,
                            0x00
                            );  
                command_array[0] = (uint8_t)(AK4954A_REG_DFLTR_MODE&0xFF);
                command_array[1] = (uint8_t)(regValue&0xFF);
                
                drvObj->writeComplete = false;
                drvObj->drvI2CBuffHandle = _DRV_AK4954_ConrolRegisterSet( drvObj, command_array, 2);

                drvObj->command = DRV_AK4954_COMMAND_VOLUME_SET_CHANNELS_INIT;
            }           
        }
        break;
               
        case DRV_AK4954_COMMAND_VOLUME_SET_CHANNELS_INIT:
        {
            
            if (drvObj->writeComplete && (false == drvObj->controlCommandStatus))
            {
                drvObj->controlCommandStatus = true;
                _DRV_AK4954_VolumeReMapping( drvObj, DRV_AK4954_CHANNEL_LEFT, drvObj->volume[DRV_AK4954_CHANNEL_LEFT]);
                _DRV_AK4954_VolumeReMapping( drvObj, DRV_AK4954_CHANNEL_RIGHT, drvObj->volume[DRV_AK4954_CHANNEL_RIGHT]);

//                _DRV_AK4954_ConrolRegisterSet(drvObj,AK4954A_REG_LDIG_VOL_CTRL,drvObj->volume[DRV_AK4954_CHANNEL_LEFT]);
                command_array[0] = (uint8_t)(AK4954A_REG_LDIG_VOL_CTRL&0xFF);
                command_array[1] = (uint8_t)(drvObj->volume[DRV_AK4954_CHANNEL_LEFT]&0xFF);
                command_array[2] = (uint8_t)(drvObj->volume[DRV_AK4954_CHANNEL_RIGHT]&0xFF);
                
                drvObj->writeComplete = false;
                drvObj->drvI2CBuffHandle = _DRV_AK4954_ConrolRegisterSet( drvObj, command_array, 3);

                drvObj->command = DRV_AK4954_COMMAND_INIT_END;
            }
        }
        break;
        
        case DRV_AK4954_COMMAND_INIT_END:
        {
            if (drvObj->writeComplete && (false == drvObj->controlCommandStatus))
            {
                drvObj->controlCommandStatus = true;
                drvObj->status = SYS_STATUS_READY;

                drvObj->command = DRV_AK4954_COMMAND_NONE;
            }
        }
        break;
        
        case DRV_AK4954_COMMAND_SEND:
        {
            AK4954_COMMAND* cmd = _DRV_AK4954_CommandQueueTop();
            // Command Queue is Empty, no need to send control command
            if(cmd == NULL)
            {
                drvObj->command = DRV_AK4954_COMMAND_NONE;
            }
            else
            {
                drvObj->writeComplete = false;
                cmd->drvI2CBufHandle = _DRV_AK4954_ConrolRegisterSet( drvObj, cmd->control_data, cmd->array_size);

                drvObj->command = DRV_AK4954_COMMAND_COMPLETE;
            }
        }
        break;
        
        case DRV_AK4954_COMMAND_COMPLETE:
        {
            AK4954_COMMAND* cmd = _DRV_AK4954_CommandQueueTop();
            // safety check, cmd should never be NULL
            if(cmd == NULL)
            {
                drvObj->command = DRV_AK4954_COMMAND_NONE;
            }
            else
            {
                if (drvObj->writeComplete && (false == drvObj->controlCommandStatus))
                {
                    // Release this command slot
                    _DRV_AK4954_CommandQueuePop();

                    drvObj->command = DRV_AK4954_COMMAND_SEND;
                }
            }
        }
        break;

        case DRV_AK4954_COMMAND_SAMPLING_RATE_SET:
        case DRV_AK4954_COMMAND_MUTE_ON:
        case DRV_AK4954_COMMAND_MUTE_OFF:
        case DRV_AK4954_COMMAND_DIGITAL_BLOCK_CONTROL_SET:
        case DRV_AK4954_COMMAND_VOLUME_SET_CHANNEL_LEFT:
        case DRV_AK4954_COMMAND_VOLUME_SET_CHANNEL_RIGHT:
        case DRV_AK4954_COMMAND_VOLUME_SET_CHANNEL_LEFT_ONLY:
        case DRV_AK4954_COMMAND_VOLUME_SET_CHANNEL_RIGHT_ONLY:
        case DRV_AK4954_COMMAND_MIC_SET:
        case DRV_AK4954_COMMAND_INT_EXT_MIC_SET:
        
        case DRV_AK4954_COMMAND_MONO_STEREO_MIC_SET:
        {
            if (false == drvObj->controlCommandStatus)
            {
                drvObj->controlCommandStatus = true;

                if (drvObj->commandCompleteCallback != (DRV_AK4954_COMMAND_EVENT_HANDLER) 0)
                {
                    drvObj->commandCompleteCallback(drvObj->commandContextData);
                }

                drvObj->command = DRV_AK4954_COMMAND_NONE;
            }
        }
        break;
    }
}

// *****************************************************************************
 /*
  Function:
        static void _DRV_AK4954_I2SBufferEventHandler
        (
            DRV_I2S_BUFFER_EVENT event,
            DRV_I2S_BUFFER_HANDLE bufferHandle,
            uintptr_t contextHandle
        )

  Summary:
    Implements the handler for i2s buffer request completion.

  Description:
    Implements the handler for i2s buffer request completion.

  Remarks:
    None
*/

static void _DRV_AK4954_I2SBufferEventHandler
(
    DRV_I2S_BUFFER_EVENT event,
    DRV_I2S_BUFFER_HANDLE bufferHandle,
    uintptr_t contextHandle
)
{
    DRV_AK4954_CLIENT_OBJ *clientObj;

    if(DRV_I2S_BUFFER_HANDLE_INVALID == bufferHandle ||
            0 == contextHandle )
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return;
    }

    clientObj = (DRV_AK4954_CLIENT_OBJ *)contextHandle;
    if(DRV_I2S_BUFFER_EVENT_COMPLETE == event)
    {
        clientObj->pEventCallBack(DRV_AK4954_BUFFER_EVENT_COMPLETE,
            (DRV_AK4954_BUFFER_HANDLE) bufferHandle, clientObj->hClientArg);
    }
    else if(DRV_I2S_BUFFER_EVENT_ABORT == event)
    {
        clientObj->pEventCallBack(DRV_AK4954_BUFFER_EVENT_ABORT,
            (DRV_AK4954_BUFFER_HANDLE) bufferHandle, clientObj->hClientArg);
    }
    else if(DRV_I2S_BUFFER_EVENT_ERROR == event)
    {
        clientObj->pEventCallBack(DRV_AK4954_BUFFER_EVENT_ERROR,
            (DRV_AK4954_BUFFER_HANDLE) bufferHandle, clientObj->hClientArg);
    }
    else
    {
        ;
    }
}

// helper routine to get value for AK4954A_REG_MODE_CTRL2 register (FS0-3 bits) for AK4954
uint8_t _getAK4954_samplerate(uint32_t samplingRate)
{
    uint8_t ak4954_rate;
    
    ak4954_rate = 9;    // default
    if (samplingRate <= 8000)
    {
        ak4954_rate = 0;
    }
    else if (samplingRate <= 11025)
    {
        ak4954_rate = 1;
    }
     else if (samplingRate <= 12000)
    {
        ak4954_rate = 2;
    }  
     else if (samplingRate <= 16000)
    {
        ak4954_rate = 4;
    }
    else if (samplingRate <= 22050)
    {
        ak4954_rate = 5;
    }
    else if (samplingRate <= 24000)
    {
        ak4954_rate = 6;
    }
        else if (samplingRate <= 32000)
    {
        ak4954_rate = 8;
    }
    else if (samplingRate <= 44100)
    {
        ak4954_rate = 9;
    }
        else if (samplingRate <= 48000)
    {
        ak4954_rate = 10;
    }
    else if (samplingRate <= 64000)
    {
        ak4954_rate = 12;
    }
    else if (samplingRate <= 88200)
    {
        ak4954_rate = 13;
    }
    else if (samplingRate <= 96000)
    {
        ak4954_rate = 14;
    }
    
    return ak4954_rate;
}

// *****************************************************************************
/*
  Function:
    DRV_HANDLE DRV_AK4954_GetI2SDriver(DRV_HANDLE codecHandle)

  Summary:
    Get the handle to the I2S driver for this codec instance.

  Description:
    Returns the appropriate handle to the I2S based on the ioIent member
    of the codec object.

  Remarks:
    This allows the caller to directly access portions of the I2S driver that
    might not be available via the codec API.
*/
DRV_HANDLE DRV_AK4954_GetI2SDriver(DRV_HANDLE codecHandle)
{
    DRV_AK4954_CLIENT_OBJ* clientObj = (DRV_AK4954_CLIENT_OBJ*)codecHandle; 
    DRV_AK4954_OBJ* drvObj = (DRV_AK4954_OBJ*)clientObj->hDriver;

    if(DRV_IO_INTENT_READ == (clientObj->ioIntent & DRV_IO_INTENT_READWRITE))
    {
        return drvObj->i2sDriverClientHandleRead;
    }
    else if(DRV_IO_INTENT_WRITE == (clientObj->ioIntent & DRV_IO_INTENT_READWRITE))
    {
        return drvObj->i2sDriverClientHandleWrite;

    }
    else if(DRV_IO_INTENT_READWRITE == (clientObj->ioIntent & DRV_IO_INTENT_READWRITE))
    {
        return drvObj->i2sDriverHandle;
    }
    return (DRV_HANDLE)NULL;
} 

// *****************************************************************************
/* Function:
    uint32_t DRV_AK4954_LRCLK_Sync (const DRV_HANDLE handle);
    
  Summary:
    Synchronize to the start of the I2S LRCLK (left/right clock) signal
    
  Description:
    This function waits until low-to high transition of the I2S LRCLK (left/right clock)
    signal (high-low if Left-Justified format, this is determined by the PLIB).
    In the case where this signal is generated from a codec or other external
    source, this allows the caller to synchronize calls to the DMA with the LRCLK signal
    so the left/right channel association is valid.
    
  Remarks:
    None.                                            
*/
bool DRV_AK4954_LRCLK_Sync (const DRV_HANDLE handle)
{
    DRV_AK4954_OBJ *drvObj;
    DRV_AK4954_CLIENT_OBJ *clientObj;

    clientObj = (DRV_AK4954_CLIENT_OBJ *) handle;
    drvObj = (DRV_AK4954_OBJ *)clientObj->hDriver;
    
    // if no sampling rate set, pass something reasonable to calculate delay times
    uint32_t samplingRate = (drvObj->samplingRate) ? drvObj->samplingRate : 48000;

    return DRV_I2S_LRCLK_Sync (drvObj->i2sDriverHandle, samplingRate);
}

// *****************************************************************************
// *****************************************************************************
// Section: AK4954 Command Queue Implementations
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
 /*
  Function:
        static void _DRV_AK4954_CommandQueueGetSlot
        (
        )

  Summary:
    Get a free slot from AK4954 command queue.

  Description:
    Get a free slot from AK4954 command queue.

  Remarks:
    None
*/

static AK4954_COMMAND* _DRV_AK4954_CommandQueueGetSlot(){
    
    if(gDrvCommandBuffer.status == 1)
    {
        return NULL;
    }
    AK4954_COMMAND* ret = NULL;
    ret = &gDrvCommandBuffer.commandBuffer[gDrvCommandBuffer.queueIn];
    gDrvCommandBuffer.queueIn++;
    if(gDrvCommandBuffer.queueIn == AK4954_COMMAND_QUEUE_BUFFER){
        gDrvCommandBuffer.queueIn = 0;
    }
    if(gDrvCommandBuffer.queueIn == gDrvCommandBuffer.queueOut)
    {
        // Buffer is Full
        gDrvCommandBuffer.status = 1;
    }else{
        gDrvCommandBuffer.status = 2;
    }
    return ret;
}
 /*
  Function:
        static void _DRV_AK4954_CommandQueuePop
        (
        )

  Summary:
    Pop up the top slot of AK4954 command queue.

  Description:
    Pop up the top slot of AK4954 command queue.

  Remarks:
    None
*/

static AK4954_COMMAND* _DRV_AK4954_CommandQueuePop(){
    if(gDrvCommandBuffer.status == 0)
    {
        return NULL;
    }
    AK4954_COMMAND *ret = &gDrvCommandBuffer.commandBuffer[gDrvCommandBuffer.queueOut];
    gDrvCommandBuffer.queueOut++;
    if(gDrvCommandBuffer.queueOut == AK4954_COMMAND_QUEUE_BUFFER){
        gDrvCommandBuffer.queueOut = 0;
    }
    if(gDrvCommandBuffer.queueOut == gDrvCommandBuffer.queueIn){
        gDrvCommandBuffer.status = 0;
    }else{
        gDrvCommandBuffer.status = 2;
    }
    return ret;
}

 /*
  Function:
        static void _DRV_AK4954_CommandQueueTop
        (
        )

  Summary:
    Return the top slot of AK4954 command queue.

  Description:
    Return the top slot of AK4954 command queue.

  Remarks:
    None
*/

static AK4954_COMMAND* _DRV_AK4954_CommandQueueTop(){
    if(gDrvCommandBuffer.status == 0)
    {
        return NULL;
    }
    AK4954_COMMAND *ret = &gDrvCommandBuffer.commandBuffer[gDrvCommandBuffer.queueOut];
    
    return ret;
}

// *****************************************************************************
 /*
  Function:
        static uint8_t _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper
        (
            DRV_AK4954_OBJ *drvObj, 
            uint8_t reg_addr, 
            uint8_t mask, 
            uint8_t pos, 
            uint8_t val
        )

  Summary:
    A wrapper function of DRV_AK4954_CONTROL_REG_FIELD_WRITE macro.

  Description:
    A wrapper function of DRV_AK4954_CONTROL_REG_FIELD_WRITE macro.

  Remarks:
    None
*/

static uint8_t _DRV_AK4954_CONTROL_REG_FIELD_WRITE_Wrapper(DRV_AK4954_OBJ *drvObj, uint8_t reg_addr, uint8_t mask, uint8_t pos, uint8_t val){
    uint8_t regValue; 
    regValue = DRV_AK4954_CONTROL_REG_FIELD_WRITE(
                                drvObj->lastRegValue[reg_addr],
                                mask,
                                pos,
                                val);
    
    drvObj->lastRegValue[reg_addr] = regValue;
    return regValue;
}

// *****************************************************************************
 /*
  Function:
        static uint8_t _DRV_AK4954_CONTROL_REG_BIT_WRITE_Wrapper
        (
            DRV_AK4954_OBJ *drvObj, 
            uint8_t reg_addr, 
            uint8_t pos, 
            uint8_t val
        )

  Summary:
    A wrapper function of DRV_AK4954_CONTROL_REG_BIT_WRITE macro.

  Description:
    A wrapper function of DRV_AK4954_CONTROL_REG_BIT_WRITE macro.

  Remarks:
    None
*/

static uint8_t _DRV_AK4954_CONTROL_REG_BIT_WRITE_Wrapper(DRV_AK4954_OBJ *drvObj, uint8_t reg_addr, uint8_t pos, uint8_t val)
{
    uint8_t regValue;
    regValue = DRV_AK4954_CONTROL_REG_BIT_WRITE(
                    drvObj->lastRegValue[reg_addr],
                    pos,
                    val);
    drvObj->lastRegValue[reg_addr] = regValue;
    return regValue;
}

/*******************************************************************************
 End of File
*/

