/*******************************************************************************
  WM8904 Codec Driver Interface

  Company:
    Microchip Technology Inc.

  File Name:
    drv_wm8904.h

  Summary:
    WM8904 Codec Driver Interface header file

  Description:
    The WM8904 Codec device driver interface provides a simple interface to
    manage the WM8904 16/24/32-Bit Codec that can be interfaced to a
    Microchip microcontroller. This file provides the public interface
    definitions for the WM8904 Codec device driver.
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

/*************************************************************
 * Include files.
 ************************************************************/

#ifndef _DRV_WM8904_H
#define _DRV_WM8904_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************
#include "system/system_module.h"
#include "system/int/sys_int.h"
#include "driver/driver_common.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

#define DRV_I2C_INDEX DRV_WM8904_I2C_INSTANCES_NUMBER

/* Driver WM8904 Module Index

  Summary:
    WM8904 driver index definitions

  Description:
    These constants provide WM8904 driver index definition.

  Remarks:
    These constants should be used in place of hard-coded numeric literals.
    These values should be passed into the DRV_WM8904_Initialize and
    DRV_WM8904_Open routines to identify the driver instance in use.
 */
 
#define      DRV_WM8904_INDEX_0      0
#define      DRV_WM8904_INDEX_1      1
#define      DRV_WM8904_INDEX_2      2
#define      DRV_WM8904_INDEX_3      3
#define      DRV_WM8904_INDEX_4      4
#define      DRV_WM8904_INDEX_5      5


// *****************************************************************************
/* WM8904 Driver Module Count

  Summary:
    Number of valid WM8904 driver indices

  Description:
    This constant identifies the maximum number of WM8904 Driver instances that
    should be defined by the application. Defining more instances than this
    constant will waste RAM memory space.

    This constant can also be used by the application to identify the number of
    WM8904 instances on this microcontroller.

  Remarks:
    This value is part-specific.

 */
#define DRV_WM8904_COUNT /*DOM-IGNORE-BEGIN*/ DRV_WM8904_INSTANCES_NUMBER /*DOM-IGNORE-END*/


// *****************************************************************************
/* WM8904 Driver Buffer Handle

  Summary:
    Handle identifying a write buffer passed to the driver.

  Description:
    A buffer handle value is returned by a call to the DRV_WM8904_BufferAddWrite()
    or DRV_WM8904_BufferAddRead() function. This handle is associated with the 
    buffer passed into the function and it allows the application to track the 
    completion of the data from (or into) that buffer.
 
    The buffer handle value returned from the "buffer add" function is returned 
    back to the client by the "event handler callback" function registered with
    the driver.

    The buffer handle assigned to a client request expires when the client has
    been notified of the completion of the buffer transfer (after event handler
    function that notifies the client returns) or after the buffer has been
    retired by the driver if no event handler callback was set.

  Remarks:
    None
 */
typedef uintptr_t DRV_WM8904_BUFFER_HANDLE;


// *****************************************************************************
/* WM8904 Driver Invalid Buffer Handle

  Summary:
    Definition of an invalid buffer handle.

  Description:
    This is the definition of an invalid buffer handle. An invalid buffer handle
    is returned by DRV_WM8904_BufferAddWrite() and the DRV_WM8904_BufferAddRead()
    function if the buffer add request was not successful.

  Remarks:
    None.
 */
#define DRV_WM8904_BUFFER_HANDLE_INVALID ((DRV_WM8904_BUFFER_HANDLE)(-1))

// *****************************************************************************
/* WM8904 Driver Events

   Summary:
    Identifies the possible events that can result from a buffer add request.

   Description:
    This enumeration identifies the possible events that can result from a
    buffer add request caused by the client calling either the
    DRV_WM8904_BufferAddWrite() or the DRV_WM8904_BufferAddRead() function.

   Remarks:
    One of these values is passed in the "event" parameter of the event
    handling callback function that the client registered with the driver by
    calling the DRV_WM8904_BufferEventHandlerSet function when a buffer
    transfer request is completed.

 */
typedef enum {
    /* Data was transferred successfully. */
    DRV_WM8904_BUFFER_EVENT_COMPLETE,

    /* Error while processing the request */
    DRV_WM8904_BUFFER_EVENT_ERROR,

    /* Data transfer aborted (Applicable in DMA mode) */
    DRV_WM8904_BUFFER_EVENT_ABORT

} DRV_WM8904_BUFFER_EVENT;


typedef enum
{
    DATA_LENGTH_16,
    DATA_LENGTH_24,
    DATA_LENGTH_32,
}DATA_LENGTH; // in bits


// *****************************************************************************
/* WM8904 Driver Buffer Event Handler Function
  Summary:
    Pointer to a WM8904 Driver Buffer Event handler function

  Description:
    This data type defines the required function signature for the WM8904 driver
    buffer event handling callback function. A client must register a pointer
    to a buffer event handling function who's function signature (parameter
    and return value types) match the types specified by this function pointer
    in order to receive buffer related event calls back from the driver.

    The parameters and return values are described here and a partial example
    implementation is provided.

  Parameters:
    event           - Identifies the type of event

    bufferHandle    - Handle identifying the buffer to which the event relates

    context         - Value identifying the context of the application that registered
                      the event handling function.

  Returns:
    None.

  Example:
    <code>
    void APP_MyBufferEventHandler( DRV_WM8904_BUFFER_EVENT event,
                                   DRV_WM8904_BUFFER_HANDLE bufferHandle,
                                   uintptr_t context )
    {
        MY_APP_DATA_STRUCT pAppData = (MY_APP_DATA_STRUCT) context;

        switch(event)
        {
            case DRV_WM8904_BUFFER_EVENT_COMPLETE:
                // Handle the completed buffer.
            break;

            case DRV_WM8904_BUFFER_EVENT_ERROR:
            default:
                // Handle error.
            break;
        }
    }
    </code>

   Remarks:
    If the event is DRV_WM8904_BUFFER_EVENT_COMPLETE, this means that the data
    was transferred successfully.

    If the event is DRV_WM8904_BUFFER_EVENT_ERROR, this means that the data was
    not transferred successfully. The bufferHandle parameter contains the buffer
    handle of the buffer that failed. The DRV_WM8904_BufferProcessedSizeGet()
    function can be called to find out how many bytes were processed.

    The bufferHandle parameter contains the buffer handle of the buffer that
    associated with the event.

    The context parameter contains a handle to the client context,
    provided at the time the event handling function was  registered using the
    DRV_WM8904_BufferEventHandlerSet function.  This context handle value is
    passed back to the client as the "context" parameter.  It can be any value
    necessary to identify the client context or instance (such as a pointer to
    the client's data) instance of the client that made the buffer add request.

    The buffer handle in bufferHandle expires after this event handler exits. In
    that the buffer object that was allocated is deallocated by the driver
    after the event handler exits.

    The event handler function executes in the data driver(i2S) peripheral's
    interrupt context when the driver is configured for interrupt mode operation.
    It is recommended of the application to not perform process intensive or
    blocking operations with in this function.

    DRV_WM8904_BufferAddWrite function can be called in the event handler
    to add a buffer to the driver queue.

 */
typedef void (*DRV_WM8904_BUFFER_EVENT_HANDLER) (DRV_WM8904_BUFFER_EVENT event,
        DRV_WM8904_BUFFER_HANDLE bufferHandle, uintptr_t contextHandle);


// *****************************************************************************
/* WM8904 Driver Command Event Handler Function

  Summary:
    Pointer to a WM8904 Driver Command Event Handler Function

  Description:
    This data type defines the required function signature for the WM8904 driver
    command event handling callback function.

    A command is a control instruction to the WM8904 Codec.
    Example Mute ON/OFF, Zero Detect Enable/Disable etc.

    A client must register a pointer to a command event handling function who's
    function signature (parameter and return value types) match the types
    specified by this function pointer in order to receive command related event
    calls back from the driver.

    The parameters and return values are described here and a partial example
    implementation is provided.

  Parameters:
    context         - Value identifying the context of the application that 
                      registered the event handling function.

  Returns:
    None.

  Example:
    <code>
    void APP_WM8904CommandEventHandler( uintptr_t context )
    {
        MY_APP_DATA_STRUCT pAppData = (MY_APP_DATA_STRUCT) context;

        // Last Submitted command is completed.
        // Perform further processing here
    }
    </code>

   Remarks:

    The occurrence of this call back means that the last control command was
    transferred successfully.

    The context parameter contains a handle to the client context,
    provided at the time the event handling function was  registered using the
    DRV_WM8904_CommandEventHandlerSet function.  This context handle value is
    passed back to the client as the "context" parameter.  It can be any value
    necessary to identify the client context or instance (such as a pointer to
    the client's data) instance of the client that made the buffer add request.

    The event handler function executes in the control data driver
    interrupt context. It is recommended of the application to not perform
    process intensive or blocking operations with in this function.

 */
typedef void (*DRV_WM8904_COMMAND_EVENT_HANDLER) (uintptr_t contextHandle);


// *****************************************************************************
/* WM8904 Audio data format

  Summary:
    Identifies the Serial Audio data interface format.

  Description:
    This enumeration identifies Serial Audio data interface format.

  Remarks:
 
 */
typedef enum {
    DATA_16_BIT_LEFT_JUSTIFIED,
    DATA_16_BIT_I2S,
    DATA_32_BIT_LEFT_JUSTIFIED,
    DATA_32_BIT_I2S

} DRV_WM8904_AUDIO_DATA_FORMAT;

// *****************************************************************************
/* WM8904 Audio Channel

  Summary:
    Identifies Left/Right Audio channel

  Description:
    This enumeration identifies Left/Right Audio channel

  Remarks:
    None.
 */
typedef enum {
    DRV_WM8904_CHANNEL_LEFT,

    DRV_WM8904_CHANNEL_RIGHT,

    DRV_WM8904_CHANNEL_LEFT_RIGHT,

    DRV_WM8904_NUMBER_OF_CHANNELS

} DRV_WM8904_CHANNEL;

/* WM8904 Audio Input

  Summary:
    Identifies the Mic/Audio Input

  Description:
    This enumeration identifies the Microphone/Audio Input of the WM8904

  Remarks:
    The WM8904 has 3 defined audio inputs, which for the standard WM8904 
    Daughterboard are:
       MIC1 - External Microphone
       MIC2 - Line Input
       MIC3 - Unused
 */
typedef enum
{
    MIC_NONE =  0,
    MIC1     =  1,
    MIC2     =  2,
    MIC3     =  3,
    NUMBER_OF_MIC
} DRV_WM8904_MIC;

// *****************************************************************************
/* WM8904 Driver Initialization Data

  Summary:
    Defines the data required to initialize or reinitialize the WM8904 driver

  Description:
    This data type defines the data required to initialize or reinitialize the
    WM8904 Codec driver.

  Remarks:
    None.
 */
typedef struct {
    /* System module initialization */
    SYS_MODULE_INIT moduleInit;

    /* Identifies data module(I2S) driver ID for
       data interface of Codec */
    SYS_MODULE_INDEX i2sDriverModuleIndex;

    /* Identifies data module(I2C) driver ID for
    control interface of Codec */
    SYS_MODULE_INDEX i2cDriverModuleIndex;

    /* Master or slave mode */
    bool masterMode;

    /* Sampling rate */
    uint32_t samplingRate;

    /* Volume */
    uint8_t volume;
    
    /* Identifies the Audio data format */
    DRV_WM8904_AUDIO_DATA_FORMAT audioDataFormat;

    /* true if mic input path enabled */
    bool enableMicInput;

    /* true if mic requires bias (e.g. electret) */
    bool enableMicBias;

    /* Microphone gain */
    uint8_t micGain;

} DRV_WM8904_INIT;


// *****************************************************************************
// *****************************************************************************
// Section: WM8904 Driver Module Interface Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/*   Function:
        SYS_MODULE_OBJ  DRV_WM8904_Initialize
        (
                const SYS_MODULE_INDEX drvIndex,
                const SYS_MODULE_INIT *const init
        );

  Summary:
    Initializes hardware and data for the instance of the WM8904 DAC module

  Description:
    This routine initializes the WM8904 driver instance for the specified driver
    index, making it ready for clients to open and use it. The initialization
    data is specified by the init parameter. The initialization may fail if the
    number of driver objects allocated are insufficient or if the specified
    driver instance is already initialized.

  Precondition:
    DRV_I2S_Initialize must be called before calling this function to initialize
    the data interface of this Codec driver.
    DRV_I2C_Initialize must be called if SPI driver is used for handling
    the control interface of this Codec driver.

  Parameters:
    drvIndex        - Identifier for the driver instance to be initialized
    init            - Pointer to the data structure containing any data
                      necessary to initialize the hardware. This pointer may
                      be null if no data is required and default
                      initialization is to be used.

  Returns:
    If successful, returns a valid handle to a driver instance object.
    Otherwise, it returns SYS_MODULE_OBJ_INVALID.

  Example:
    <code>
    DRV_WM8904_INIT                  init;
    SYS_MODULE_OBJ                  objectHandle;

    init->inUse                           = true;
    init->status                          = SYS_STATUS_BUSY;
    init->numClients                      = 0;
    init->isInInterruptContext            = false;

    init->i2sDriverModuleIndex            = wm8904Init->i2sDriverModuleIndex;
    init->i2cDriverModuleIndex            = wm8904Init->i2cDriverModuleIndex;
    init->masterMode                      = wm8904Init->masterMode;
    init->volume                          = wm8904Init->volume;
    init->samplingRate                    = wm8904Init->samplingRate;
    init->audioDataFormat                 = wm8904Init->audioDataFormat
    init->enableMicInput                  = wm8904Init->enableMicInput;
    init->enableMicBias                   = wm8904Init->enableMicBias;
    init->MicGain                         = wm8904Init->MicGain;
    init->mclk_multiplier = DRV_WM8904_MCLK_SAMPLE_FREQ_MULTPLIER;

    init->commandCompleteCallback = (DRV_WM8904_COMMAND_EVENT_HANDLER)0;
    init->commandContextData = 0;


    objectHandle = DRV_WM8904_Initialize(DRV_WM8904_0, (SYS_MODULE_INIT*)init);
    if (SYS_MODULE_OBJ_INVALID == objectHandle)
    {
        // Handle error
    }
    </code>

  Remarks:
    This routine must be called before any other WM8904 routine is called.

    This routine should only be called once during system initialization
    unless DRV_WM8904_Deinitialize is called to deinitialize the driver
    instance. This routine will NEVER block for hardware access.

 */
SYS_MODULE_OBJ DRV_WM8904_Initialize
(
        const SYS_MODULE_INDEX drvIndex,
        const SYS_MODULE_INIT * const init
);

// *****************************************************************************
/* Function:
    void DRV_WM8904_Deinitialize( SYS_MODULE_OBJ object)

  Summary:
    Deinitializes the specified instance of the WM8904 driver module

  Description:
    Deinitializes the specified instance of the WM8904 driver module, disabling
    its operation (and any hardware).  Invalidates all the internal data.

  Precondition:
    Function DRV_WM8904_Initialize should have been called before calling this
    function.

  Parameters:
    object          - Driver object handle, returned from the
                      DRV_WM8904_Initialize routine

  Returns:
    None.

  Example:
    <code>
    SYS_MODULE_OBJ      object;     //  Returned from DRV_WM8904_Initialize
    SYS_STATUS          status;


    DRV_WM8904_Deinitialize(object);

    status = DRV_WM8904_Status(object);
    if (SYS_MODULE_DEINITIALIZED != status)
    {
        // Check again later if you need to know
        // when the driver is deinitialized.
    }
    </code>

  Remarks:
    Once the Initialize operation has been called, the De-initialize operation
    must be called before the Initialize operation can be called again. This
    routine will NEVER block waiting for hardware.
 */
void DRV_WM8904_Deinitialize(SYS_MODULE_OBJ object);


// *****************************************************************************
/* Function:
    SYS_STATUS DRV_WM8904_Status( SYS_MODULE_OBJ object)

  Summary:
    Gets the current status of the WM8904 driver module.

  Description:
    This routine provides the current status of the WM8904 driver module.

  Precondition:
    Function DRV_WM8904_Initialize should have been called before calling this
    function.

  Parameters:
    object          - Driver object handle, returned from the
                      DRV_WM8904_Initialize routine

  Returns:
    SYS_STATUS_DEINITIALIZED  - Indicates that the driver has been
                                deinitialized

    SYS_STATUS_READY          - Indicates that any previous module operation
                                for the specified module has completed

    SYS_STATUS_BUSY           - Indicates that a previous module operation for
                                the specified module has not yet completed

    SYS_STATUS_ERROR          - Indicates that the specified module is in an
                                error state

  Example:
    <code>
    SYS_MODULE_OBJ      object;     // Returned from DRV_WM8904_Initialize
    SYS_STATUS          WM8904Status;

    WM8904Status = DRV_WM8904_Status(object);
    if (SYS_STATUS_READY == WM8904Status)
    {
        // This means the driver can be opened using the
        // DRV_WM8904_Open() function.
    }
    </code>

  Remarks:
    A driver can opened only when its status is SYS_STATUS_READY.
 */
SYS_STATUS DRV_WM8904_Status(SYS_MODULE_OBJ object);


// *****************************************************************************
/* Function:
    void  DRV_WM8904_Tasks(SYS_MODULE_OBJ object);

  Summary:
    Maintains the driver's control and data interface state machine.

  Description:
    This routine is used to maintain the driver's internal control and data
    interface state machine and implement its control and data interface
    implementations.
    This function should be called from the SYS_Tasks() function.

  Precondition:
    The DRV_WM8904_Initialize routine must have been called for the specified
    WM8904 driver instance.

  Parameters:
    object      - Object handle for the specified driver instance (returned from
                  DRV_WM8904_Initialize)

  Returns:
    None.

  Example:
    <code>
    SYS_MODULE_OBJ      object;     // Returned from DRV_WM8904_Initialize

    while (true)
    {
        DRV_WM8904_Tasks (object);

        // Do other tasks
    }
    </code>

  Remarks:
    This routine is normally not called directly by an application.  It is
    called by the system's Tasks routine (SYS_Tasks).

 */
void DRV_WM8904_Tasks(SYS_MODULE_OBJ object);


// *****************************************************************************
// *****************************************************************************
// Section: WM8904 Codec Driver Client Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    DRV_HANDLE DRV_WM8904_Open
    (
        const SYS_MODULE_INDEX drvIndex,
        const DRV_IO_INTENT ioIntent
    )

  Summary:
    Opens the specified WM8904 driver instance and returns a handle to it

  Description:
    This routine opens the specified WM8904 driver instance and provides a
    handle that must be provided to all other client-level operations to
    identify the caller and the instance of the driver. The ioIntent
    parameter defines how the client interacts with this driver instance.

    The DRV_IO_INTENT_BLOCKING and DRV_IO_INTENT_NONBLOCKING ioIntent
    options are not relevant to this driver. All the data transfer functions
    of this driver are non blocking.

    WM8904 can be opened with DRV_IO_INTENT_WRITE, or DRV_IO_INTENT_READ or
    DRV_IO_INTENT_WRITEREAD io_intent option.  This decides whether the driver
    is used for headphone output, or microphone input or both modes simultaneously.

    Specifying a DRV_IO_INTENT_EXCLUSIVE will cause the driver to provide
    exclusive access to this client. The driver cannot be opened by any
    other client.

  Precondition:
    Function DRV_WM8904_Initialize must have been called before calling this
    function.

  Parameters:
    drvIndex    - Identifier for the object instance to be opened

    ioIntent    - Zero or more of the values from the enumeration
                  DRV_IO_INTENT "ORed" together to indicate the intended use
                  of the driver. See function description for details.

  Returns:
    If successful, the routine returns a valid open-instance handle (a number
    identifying both the caller and the module instance).

    If an error occurs, the return value is DRV_HANDLE_INVALID. Error can occur
    - if the number of client objects allocated via DRV_WM8904_CLIENTS_NUMBER is
      insufficient.
    - if the client is trying to open the driver but driver has been opened 
      exclusively by another client.
    - if the driver hardware instance being opened is not initialized or is invalid.
    - if the ioIntent options passed are not relevant to this driver.

  Example:
    <code>
    DRV_HANDLE handle;

    handle = DRV_WM8904_Open(DRV_WM8904_INDEX_0, DRV_IO_INTENT_WRITEREAD | DRV_IO_INTENT_EXCLUSIVE);
    if (DRV_HANDLE_INVALID == handle)
    {
        // Unable to open the driver
        // May be the driver is not initialized or the initialization
        // is not complete.
    }
    </code>

  Remarks:
    The handle returned is valid until the DRV_WM8904_Close routine is called.
    This routine will NEVER block waiting for hardware.If the requested intent
    flags are not supported, the routine will return DRV_HANDLE_INVALID.  This
    function is thread safe in a RTOS application. It should not be called in an
    ISR.
 */
DRV_HANDLE DRV_WM8904_Open
(
    const SYS_MODULE_INDEX iDriver,
    const DRV_IO_INTENT ioIntent
);

// *****************************************************************************
/* Function:
    void DRV_WM8904_Close( DRV_Handle handle )

  Summary:
    Closes an opened-instance of the WM8904 driver

  Description:
    This routine closes an opened-instance of the WM8904 driver, invalidating the
    handle. Any buffers in the driver queue that were submitted by this client
    will be removed.  After calling this routine, the handle passed in "handle"
    must not be used with any of the remaining driver routines.  A new handle must
    be obtained by calling DRV_WM8904_Open before the caller may use the driver
    again

  Precondition:
    The DRV_WM8904_Initialize routine must have been called for the specified
    WM8904 driver instance.

    DRV_WM8904_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine

  Returns:
                 - None

  Example:
    <code>
    DRV_HANDLE handle;  // Returned from DRV_WM8904_Open

    DRV_WM8904_Close(handle);

    </code>

  Remarks:

    Usually there is no need for the driver client to verify that the Close
    operation has completed.  The driver will abort any ongoing operations
    when this routine is called.
 */
void DRV_WM8904_Close(const DRV_HANDLE handle);


// *****************************************************************************
/*
Function:
        void DRV_WM8904_BufferAddWrite
        (
            const DRV_HANDLE handle,
            DRV_WM8904_BUFFER_HANDLE *bufferHandle,
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
    modified.  The function returns DRV_WM8904_BUFFER_HANDLE_INVALID:
    - if a buffer could not be allocated to the request
    - if the input buffer pointer is NULL
    - if the buffer size is 0.
    - if the queue is full or the queue depth is insufficient
    If the requesting client registered an event callback with the driver,
    the driver will issue a DRV_WM8904_BUFFER_EVENT_COMPLETE event if the buffer
    was processed successfully of DRV_WM8904_BUFFER_EVENT_ERROR event if the
    buffer was not processed successfully.

  Precondition:
    The DRV_WM8904_Initialize routine must have been called for the specified
    WM8904 device instance and the DRV_WM8904_Status must have returned
    SYS_STATUS_READY.

    DRV_WM8904_Open must have been called to obtain a valid opened device handle.

    DRV_IO_INTENT_WRITE must have been specified in the DRV_WM8904_Open call.

  Parameters:
    handle       - Handle of the WM8904 instance as return by the
                   DRV_WM8904_Open function.
    buffer       - Data to be transmitted.
    size         - Buffer size in bytes.
    bufferHandle - Pointer to an argument that will contain the
                   return buffer handle.

  Returns:
    The bufferHandle parameter will contain the return buffer handle. This will be
    DRV_WM8904_BUFFER_HANDLE_INVALID if the function was not successful.

  Example:
    <code>

    MY_APP_OBJ myAppObj;
    uint8_t mybuffer[MY_BUFFER_SIZE];
    DRV_WM8904_BUFFER_HANDLE bufferHandle;

    // myWM8904Handle is the handle returned
    // by the DRV_WM8904_Open function.

    // Client registers an event handler with driver

    DRV_WM8904_BufferEventHandlerSet(myWM8904Handle,
                    APP_WM8904BufferEventHandler, (uintptr_t)&myAppObj);

    DRV_WM8904_BufferAddWrite(myWM8904handle, &bufferHandle
                                        myBuffer, MY_BUFFER_SIZE);

    if(DRV_WM8904_BUFFER_HANDLE_INVALID == bufferHandle)
    {
        // Error handling here
    }

    // Event is received when
    // the buffer is processed.

    void APP_WM8904BufferEventHandler(DRV_WM8904_BUFFER_EVENT event,
            DRV_WM8904_BUFFER_HANDLE bufferHandle, uintptr_t contextHandle)
    {
        // contextHandle points to myAppObj.

        switch(event)
        {
            case DRV_WM8904_BUFFER_EVENT_COMPLETE:

                // This means the data was transferred.
                break;

            case DRV_WM8904_BUFFER_EVENT_ERROR:

                // Error handling here.
                break;

            default:
                break;
        }
    }

    </code>

  Remarks:
    This function is thread safe in a RTOS application. It can be called from
    within the WM8904 Driver Buffer Event Handler that is registered by this
    client. It should not be called in the event handler associated with another
    WM8904 driver instance. It should not otherwise be called directly in an ISR.

 */
void DRV_WM8904_BufferAddWrite
(
    const DRV_HANDLE handle,
    DRV_WM8904_BUFFER_HANDLE *bufferHandle,
    void *buffer, size_t size
);

// *****************************************************************************
/* Function:
    void DRV_WM8904_BufferAddWriteRead
        (
                const DRV_HANDLE handle,
                DRV_WM8904_BUFFER_HANDLE *bufferHandle,
                void *transmitBuffer, 
                void *receiveBuffer,
                size_t size
        )

  Summary:
    Schedule a non-blocking driver write-read operation.

  Description:
    This function schedules a non-blocking write-read operation. The function
    returns with a valid buffer handle in the bufferHandle argument if the
    write-read request was scheduled successfully. The function adds the request
    to the hardware instance queue and returns immediately. While the request is
    in the queue, the application buffer is owned by the driver and should not
    be modified. The function returns DRV_WM8904_BUFFER_EVENT_COMPLETE:
    - if a buffer could not be allocated to the request
    - if the input buffer pointer is NULL
    - if the client opened the driver for read only or write only
    - if the buffer size is 0
    - if the queue is full or the queue depth is insufficient
    If the requesting client registered an event callback with the driver,
    the driver will issue a DRV_WM8904_BUFFER_EVENT_COMPLETE event if the buffer
    was processed successfully of DRV_WM8904_BUFFER_EVENT_ERROR event if the
    buffer was not processed successfully.

  Precondition:
    The DRV_WM8904_Initialize routine must have been called for the specified
    AK4642 device instance and the DRV_WM8904_Status must have returned
    SYS_STATUS_READY.

    DRV_WM8904_Open must have been called to obtain a valid opened device handle.

    DRV_IO_INTENT_READWRITE must have been specified in the DRV_WM8904_Open call.

  Parameters:
    handle         - Handle of the AK4642 instance as returned by the
                     DRV_WM8904_Open function
    bufferHandle   - Pointer to an argument that will contain the
                     return buffer handle
    transmitBuffer - The buffer where the transmit data will be stored
    receiveBuffer  - The buffer where the received data will be stored
    size           - Buffer size in bytes

  Returns:
    The bufferHandle parameter will contain the return buffer handle. This will be
    DRV_WM8904_BUFFER_HANDLE_INVALID if the function was not successful.

  Example:
    <code>

    MY_APP_OBJ myAppObj;
    uint8_t mybufferTx[MY_BUFFER_SIZE];
    uint8_t mybufferRx[MY_BUFFER_SIZE];
    DRV_WM8904_BUFFER_HANDLE bufferHandle;

    // myak4642Handle is the handle returned
    // by the DRV_WM8904_Open function.

    // Client registers an event handler with driver

    DRV_WM8904_BufferEventHandlerSet(myak4642Handle,
                    APP_AK4642BufferEventHandler, (uintptr_t)&myAppObj);

    DRV_WM8904_BufferAddWriteRead(myak4642handle, &bufferHandle,
                                        mybufferTx,mybufferRx,MY_BUFFER_SIZE);

    if(DRV_WM8904_BUFFER_HANDLE_INVALID == bufferHandle)
    {
        // Error handling here
    }

    // Event is received when
    // the buffer is processed.

    void APP_AK4642BufferEventHandler(DRV_WM8904_BUFFER_EVENT event,
            DRV_WM8904_BUFFER_HANDLE bufferHandle, uintptr_t contextHandle)
    {
        // contextHandle points to myAppObj.

        switch(event)
        {
            case DRV_WM8904_BUFFER_EVENT_COMPLETE:

                // This means the data was transferred.
                break;

            case DRV_WM8904_BUFFER_EVENT_ERROR:

                // Error handling here.
                break;

            default:
                break;
        }
    }

    </code>

  Remarks:
    This function is thread safe in a RTOS application. It can be called from
    within the AK4642 Driver Buffer Event Handler that is registered by this
    client. It should not be called in the event handler associated with another
    AK4642 driver instance. It should not otherwise be called directly in an ISR.

    This function is useful when there is valid read expected for every
    AK4642 write. The transmit and receive size must be same.

*/
void DRV_WM8904_BufferAddWriteRead
(
    const DRV_HANDLE handle,
    DRV_WM8904_BUFFER_HANDLE    *bufferHandle,
    void *transmitBuffer, void *receiveBuffer,
    size_t size
);

// *****************************************************************************
/*
Function:
    void DRV_WM8904_BufferAddRead
    (
        const DRV_HANDLE handle,
        DRV_WM8904_BUFFER_HANDLE *bufferHandle,
        void *buffer, size_t size
    )

  Summary:
    Schedule a non-blocking driver read operation.

  Description:
    This function schedules a non-blocking read operation. The function returns
    with a valid buffer handle in the bufferHandle argument if the read request
    was scheduled successfully. The function adds the request to the hardware
    instance receive queue and returns immediately. While the request is in the
    queue, the application buffer is owned by the driver and should not be
    modified.  The function returns DRV_WM8904_BUFFER_HANDLE_INVALID
    - if a buffer could not be allocated to the request
    - if the input buffer pointer is NULL
    - if the buffer size is 0.
    - if the queue is full or the queue depth is insufficient
    If the requesting client registered an event callback with the driver,
    the driver will issue a DRV_WM8904_BUFFER_EVENT_COMPLETE event if the buffer
    was processed successfully of DRV_WM8904_BUFFER_EVENT_ERROR event if the
    buffer was not processed successfully.

  Precondition:
    The DRV_WM8904_Initialize routine must have been called for the specified
    WM8904 device instance and the DRV_WM8904_Status must have returned
    SYS_STATUS_READY.

    DRV_WM8904_Open must have been called to obtain a valid opened device handle.

    DRV_IO_INTENT_READ must have been specified in the DRV_WM8904_Open call.

  Parameters:
    handle       - Handle of the WM8904 instance as return by the
                   DRV_WM8904_Open function.
    buffer       - Data to be transmitted.
    size         - Buffer size in bytes.
    bufferHandle - Pointer to an argument that will contain the
                   return buffer handle.

  Returns:
    The bufferHandle parameter will contain the return buffer handle. This will be
    DRV_WM8904_BUFFER_HANDLE_INVALID if the function was not successful.

   Remarks:
    This function is thread safe in a RTOS application. It can be called from
    within the WM8904 Driver Buffer Event Handler that is registered by this
    client. It should not be called in the event handler associated with another
    WM8904 driver instance. It should not otherwise be called directly in an ISR.

*/
void DRV_WM8904_BufferAddRead
(
    const DRV_HANDLE handle,
    DRV_WM8904_BUFFER_HANDLE *bufferHandle,
    void *buffer, size_t size
);

// *****************************************************************************
/* Function:
    bool DRV_WM8904_WriteQueuePurge( const DRV_HANDLE handle )

  Summary:
    Removes all buffer requests from the write queue.

  Description:
    This function removes all the buffer requests from the write queue.
    The client can use this function to purge the queue on timeout or to remove
    unwanted stalled buffer requests or in any other use case.

  Precondition:
    DRV_WM8904_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle - Handle of the communication channel as returned by the
    DRV_WM8904_Open function.

  Returns:
    True - Write queue purge is successful.
    False - Write queue purge has failed.

  Example:
    <code>
    // myCodecHandle is the handle returned by the DRV_WM8904_Open function.
    // Use DRV_WM8904_BufferAddWrite to queue write requests

    // Application timeout function, where remove queued buffers.
    void APP_TimeOut(void)
    {
        if(false == DRV_WM8904_WriteQueuePurge(myCodecHandle))
        {
            //Couldn't purge the write queue, try again.
        }
        else
        {
            //Queue purge successful.
        }
    }
    </code>

  Remarks:
    This function is thread safe when used in an RTOS environment.
    Avoid this function call from within the callback.
*/

bool DRV_WM8904_WriteQueuePurge(const DRV_HANDLE handle);

// *****************************************************************************
/* Function:
    bool DRV_WM8904_ReadQueuePurge( const DRV_HANDLE handle )

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
    DRV_WM8904_Open function.

  Returns:
    True - Read queue purge is successful.
    False - Read queue purge has failed.

  Example:
    <code>
    // myCodecHandle is the handle returned by the DRV_WM8904_Open function.
    // Use DRV_WM8904_BufferAddRead to queue read requests

    // Application timeout function, where remove queued buffers.
    void APP_TimeOut(void)
    {
        if(false == DRV_WM8904_ReadQueuePurge(myCodecHandle))
        {
            //Couldn't purge the read queue, try again.
        }
        else
        {
            //Queue purge successful.
        }
    }
    </code>

  Remarks:
    This function is thread safe when used in an RTOS environment.
    Avoid this function call from within the callback.
*/

bool DRV_WM8904_ReadQueuePurge(const DRV_HANDLE handle);

// *****************************************************************************
/*
  Function:
        void DRV_WM8904_BufferEventHandlerSet
        (
            DRV_HANDLE handle,
            const DRV_WM8904_BUFFER_EVENT_HANDLER eventHandler,
            const uintptr_t contextHandle
        )

  Summary:
    This function allows a client to identify a buffer event handling function
    for the driver to call back when queued buffer transfers have finished.

  Description:
    This function allows a client to identify a buffer event handling function
    for the driver to call back when queued buffer transfers have finished.
    When a client calls DRV_WM8904_BufferAddWrite function, it is provided with
    a handle identifying  the buffer that was added to the driver's buffer queue.
    The driver will pass this handle back to the client by calling "eventHandler"
    function when the buffer transfer has completed.

    The event handler should be set before the client performs any "buffer add"
    operations that could generate events. The event handler once set, persists
    until the client closes the driver or sets another event handler (which
    could be a "NULL" pointer to indicate no callback).

  Precondition:
    The DRV_WM8904_Initialize routine must have been called for the specified
    WM8904 driver instance.

    DRV_WM8904_Open must have been called to obtain a valid opened device handle.

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

  Example:
    <code>
    MY_APP_OBJ myAppObj;
    uint8_t mybuffer[MY_BUFFER_SIZE];
    DRV_WM8904_BUFFER_HANDLE bufferHandle;

    // myWM8904Handle is the handle returned
    // by the DRV_WM8904_Open function.

    // Client registers an event handler with driver

    DRV_WM8904_BufferEventHandlerSet(myWM8904Handle,
                    APP_WM8904BufferEventHandler, (uintptr_t)&myAppObj);

    DRV_WM8904_BufferAddWrite(myWM8904handle, &bufferHandle
                                        myBuffer, MY_BUFFER_SIZE);

    if(DRV_WM8904_BUFFER_HANDLE_INVALID == bufferHandle)
    {
        // Error handling here
    }

    // Event is received when
    // the buffer is processed.

    void APP_WM8904BufferEventHandler(DRV_WM8904_BUFFER_EVENT event,
            DRV_WM8904_BUFFER_HANDLE bufferHandle, uintptr_t contextHandle)
    {
        // contextHandle points to myAppObj.

        switch(event)
        {
            case DRV_WM8904_BUFFER_EVENT_COMPLETE:

                // This means the data was transferred.
                break;

            case DRV_WM8904_BUFFER_EVENT_ERROR:

                // Error handling here.
                break;

            default:
                break;
        }
    }
    </code>

  Remarks:
    If the client does not want to be notified when the queued buffer transfer
    has completed, it does not need to register a callback.
 */
void DRV_WM8904_BufferEventHandlerSet
(
    DRV_HANDLE handle,
    const DRV_WM8904_BUFFER_EVENT_HANDLER eventHandler,
    const uintptr_t contextHandle
);

// *****************************************************************************
// *****************************************************************************
// Section: WM8904 Codec Specific Client Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/*
  Function:
    void DRV_WM8904_SamplingRateSet(DRV_HANDLE handle, uint32_t samplingRate)

  Summary:
    This function sets the sampling rate of the media stream.

  Description:
    This function sets the media sampling rate for the client handle.

  Precondition:
    The DRV_WM8904_Initialize routine must have been called for the specified
    WM8904 driver instance.

    DRV_WM8904_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine
    samplingRate - Sampling frequency in Hz
  Returns:
    None.

  Example:
    <code>
    // myWM8904Handle is the handle returned
    // by the DRV_WM8904_Open function.

    DRV_WM8904_SamplingRateSet(myWM8904Handle, 48000);    //Sets 48000 media sampling rate

    </code>

  Remarks:
    None.
 */
void DRV_WM8904_SamplingRateSet(DRV_HANDLE handle, uint32_t samplingRate);

// *****************************************************************************
/*
  Function:
    uint32_t DRV_WM8904_SamplingRateGet(DRV_HANDLE handle)

  Summary:
    This function gets the sampling rate set on the WM8904.

  Description:
    This function gets the sampling rate set on the DAC WM8904.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine
  Example:
    <code>
   uint32_t baudRate;

    // myWM8904Handle is the handle returned
    // by the DRV_WM8904_Open function.

    baudRate = DRV_WM8904_SamplingRateGet(myWM8904Handle);

    </code>

  Remarks:
    None.
 */
uint32_t DRV_WM8904_SamplingRateGet(DRV_HANDLE handle);

// *****************************************************************************
/*
  Function:
    void DRV_WM8904_VolumeSet(DRV_HANDLE handle, DRV_WM8904_CHANNEL channel, uint8_t volume);

  Summary:
    This function sets the volume for WM8904 Codec.

  Description:
    This functions sets the volume value from 0-255.
    The codec has DAC value to volume range mapping as :-
    00 H : +12dB
    FF H : -115dB
    In order to make the volume value to dB mapping monotonically increasing from
    00 to FF, re-mapping is introduced which reverses the volume value to dB mapping
    as well as normalizes the volume range to a more audible dB range. 
    The current driver implementation assumes that all dB values under -60 dB are
    inaudible to the human ear. 
    Re-Mapped values 00 H : -60 dB
                     FF H : +12 dB  
    
  Precondition:
    The DRV_WM8904_Initialize routine must have been called for the specified
    WM8904 driver instance.

    DRV_WM8904_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine
    channel      - argument indicating Left or Right or Both channel volume to be modified
    volume       - volume value specified in the range 0-255 (0x00 to 0xFF)

  Returns:
    None

  Example:
    <code>
    // myAppObj is an application specific object.
    MY_APP_OBJ myAppObj;

    uint8_t mybuffer[MY_BUFFER_SIZE];
    DRV_BUFFER_HANDLE bufferHandle;

    // myWM8904Handle is the handle returned
    // by the DRV_WM8904_Open function.

        DRV_WM8904_VolumeSet(myWM8904Handle,DRV_WM8904_CHANNEL_LEFT, 120);    

    </code>

  Remarks:
    None.
 */
void DRV_WM8904_VolumeSet(DRV_HANDLE handle, DRV_WM8904_CHANNEL channel, uint8_t volume);

// *****************************************************************************
/*
  Function:
    uint8_t DRV_WM8904_VolumeGet(DRV_HANDLE handle, DRV_WM8904_CHANNEL channel)

  Summary:
    This function gets the volume for WM8904 Codec.

  Description:
    This functions gets the current volume programmed to the Codec WM8904.

  Precondition:
    The DRV_WM8904_Initialize routine must have been called for the specified
    WM8904 driver instance.

    DRV_WM8904_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine
    channel      - argument indicating Left or Right or Both channel volume to be modified

  Returns:
    None.

  Example:
    <code>
    // myAppObj is an application specific object.
    MY_APP_OBJ myAppObj;
    uint8_t volume;

    // myWM8904Handle is the handle returned
    // by the DRV_WM8904_Open function.

      volume = DRV_WM8904_VolumeGet(myWM8904Handle, DRV_WM8904_CHANNEL_LEFT);
    </code>

  Remarks:
    None.
 */
uint8_t DRV_WM8904_VolumeGet(DRV_HANDLE handle, DRV_WM8904_CHANNEL channel);


// *****************************************************************************
/*
  Function:
    void DRV_WM8904_MuteOn(DRV_HANDLE handle);

  Summary:
    This function allows WM8904 output for soft mute on.

  Description:
    This function Enables WM8904 output for soft mute.

  Precondition:
    The DRV_WM8904_Initialize routine must have been called for the specified
    WM8904 driver instance.

    DRV_WM8904_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine

  Returns:
    None.

  Example:
    <code>
    // myAppObj is an application specific object.
    MY_APP_OBJ myAppObj;

    uint8_t mybuffer[MY_BUFFER_SIZE];
    DRV_BUFFER_HANDLE bufferHandle;

    // myWM8904Handle is the handle returned
    // by the DRV_WM8904_Open function.

    DRV_WM8904_MuteOn(myWM8904Handle);    //WM8904 output soft muted

    </code>

  Remarks:
    None.
 */
void DRV_WM8904_MuteOn(DRV_HANDLE handle);


// *****************************************************************************
/*
  Function:
        void DRV_WM8904_MuteOff(DRV_HANDLE handle)

  Summary:
    This function disables WM8904 output for soft mute.

  Description:
    This function disables WM8904 output for soft mute.

  Precondition:
    The DRV_WM8904_Initialize routine must have been called for the specified
    WM8904 driver instance.

    DRV_WM8904_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine

  Returns:
    None.

  Example:
    <code>
    // myAppObj is an application specific object.
    MY_APP_OBJ myAppObj;

    uint8_t mybuffer[MY_BUFFER_SIZE];
    DRV_BUFFER_HANDLE bufferHandle;

    // myWM8904Handle is the handle returned
    // by the DRV_WM8904_Open function.

        DRV_WM8904_MuteOff(myWM8904Handle);    //WM8904 output soft mute disabled

    </code>

  Remarks:
    None.
 */
void DRV_WM8904_MuteOff(DRV_HANDLE handle);


// *****************************************************************************
/*
  Function:
    void DRV_WM8904_MicGainSet(DRV_HANDLE handle, uint8_t gain)

  Summary:
    This function sets the microphone gain for the WM8904 CODEC.

  Description:
    This functions sets the microphone gain value from 0-31 which can range
    from -1.5 to 28.3 dB

  Precondition:
    The DRV_WM8904_Initialize routine must have been called for the specified
    WM8904 driver instance.

    DRV_WM8904_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine

    gain         - Gain value, in range 0-31

  Returns:
    None.

    <code>
    // myAppObj is an application specific object.
    MY_APP_OBJ myAppObj;

    // myWM8904Handle is the handle returned
    // by the DRV_WM8904_Open function.

        DRV_WM8904_MicGainSet(myWM8904Handle, 15);    //WM8904 mic gain set to 15

    </code>

  Remarks:
    None.
*/
void DRV_WM8904_MicGainSet(DRV_HANDLE handle, uint8_t gain);


// *****************************************************************************
/*
  Function:
    uint8_t DRV_WM8904_MicGainGet(DRV_HANDLE handle)

  Summary:
    This function gets the microphone gain for the WM8904 Codec.

  Description:
    This functions gets the current microphone gain programmed to the Codec WM8904.

  Precondition:
    The DRV_WM8904_Initialize routine must have been called for the specified
    WM8904 driver instance.

    DRV_WM8904_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine

  Returns:
    Microphone gain, in range 0-31.

  Example:
    <code>
    // myAppObj is an application specific object.
    MY_APP_OBJ myAppObj;
    uint8_t gain;

    // myWM8904Handle is the handle returned
    // by the DRV_WM8904_Open function.

      gain = DRV_WM8904_MicGainGet(myWM8904Handle);
    </code>

  Remarks:
    None.
 */
uint8_t DRV_WM8904_MicGainGet(DRV_HANDLE handle);


// *****************************************************************************
/*
  Function:
    void DRV_WM8904_MicMuteOn(DRV_HANDLE handle);

  Summary:
    Mutes the WM8904's microphone input

  Description:
    This function mutes the WM8904's microphone input

  Precondition:
    The DRV_WM8904_Initialize routine must have been called for the specified
    WM8904 driver instance.

    DRV_WM8904_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine

  Returns:
    None.

  Example:
    <code>
    // myAppObj is an application specific object.
    MY_APP_OBJ myAppObj;

    // myWM8904Handle is the handle returned
    // by the DRV_WM8904_Open function.

    DRV_WM8904_MicMuteOn(myWM8904Handle);    //WM8904 microphone muted

    </code>

  Remarks:
    None.
 */
void DRV_WM8904_MicMuteOn(DRV_HANDLE handle);


// *****************************************************************************
/*
  Function:
        void DRV_WM8904_MicMuteOff(DRV_HANDLE handle)

  Summary:
    Umutes th WM8904's microphone input.

  Description:
    This function unmutes the WM8904's microphone input.

  Precondition:
    The DRV_WM8904_Initialize routine must have been called for the specified
    WM8904 driver instance.

    DRV_WM8904_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine

  Returns:
    None.

  Example:
    <code>
    // myAppObj is an application specific object.
    MY_APP_OBJ myAppObj;

    // myWM8904Handle is the handle returned
    // by the DRV_WM8904_Open function.

        DRV_WM8904_MicMuteOff(myWM8904Handle);    //WM8904 microphone unmuted

    </code>

  Remarks:
    None.
 */
void DRV_WM8904_MicMuteOff(DRV_HANDLE handle);

// *****************************************************************************
/* WM8904 Audio Input Selection
 *
  Summary:
     Selects the active input to the input amplifier/ADC of the Codec.

  Description:
     Selects the active input to the input amplifier/ADC of the Codec,
     assuming it is single ended stereo.

    The parameters and return values are described here and a partial example
    implementation is provided.

  Precondition:
    The DRV_WM8904_Initialize routine must have been called for the specified
    WM8904 driver instance.

    DRV_WM8904_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine
    mic          - Mic/audio input being selected


  Returns:
    0 - Error, Unsucessfull execution of function.
    nonzero value - the selected MIC input value 

  Example:
    <code>
        // myWM8904Handle is the handle returned
        // by the DRV_WM8904_Open function.

        DRV_WM8904_StereoMicSelect(myWM8904Handle, MIC1);
    </code>

  Remarks:

 */
uint8_t DRV_WM8904_StereoMicSelect(DRV_HANDLE handle, DRV_WM8904_MIC mic);


// *****************************************************************************
/*
  Function:
    DRV_HANDLE DRV_WM8904_GetI2SDriver(DRV_HANDLE codecHandle)

  Summary:
    Get the handle to the I2S driver for this codec instance.

  Description:
    Returns the appropriate handle to the I2S based on the ioIent member
    of the codec object.
 
  Precondition:
    The DRV_WM8904_Initialize routine must have been called for the specified
    WM8904 driver instance.

    DRV_WM8904_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine

  Returns:       - A handle to the I2S driver for this codec instance
    
  Remarks:
    This allows the caller to directly access portions of the I2S driver that
    might not be available via the codec API.
*/
DRV_HANDLE DRV_WM8904_GetI2SDriver(DRV_HANDLE codecHandle);

// *****************************************************************************
/* Function:
    uint32_t DRV_WM8904_LRCLK_Sync (const DRV_HANDLE handle);
    
  Summary:
    Synchronize to the start of the I2S LRCLK (left/right clock) signal
    
  Description:
    This function waits until low-to high transition of the I2S LRCLK (left/right clock)
    signal (high-low if Left-Justified format, this is determined by the PLIB).
    In the case where this signal is generated from a codec or other external
    source, this allows the caller to synchronize calls to the DMA with the LRCLK signal
    so the left/right channel association is valid.
  
  Precondition:
    None.
  
  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine
  
  Returns:
    true if the function was successful, false if a timeout occurred (no transitions seen)
    
  Example:
    <code>
        // myWM8904Handle is the handle returned
        // by the DRV_WM8904_Open function.

        DRV_WM8904_LRCLK_Sync(myWM8904Handle);
    </code>
    
  Remarks:
    None.                                            
*/
bool DRV_WM8904_LRCLK_Sync (const DRV_HANDLE handle);

// *****************************************************************************
/*
  Function:
        void DRV_WM8904_CommandEventHandlerSet
        (
            DRV_HANDLE handle,
            const DRV_WM8904_COMMAND_EVENT_HANDLER eventHandler,
            const uintptr_t contextHandle
        )

  Summary:
    This function allows a client to identify a command event handling function
    for the driver to call back when the last submitted command have finished.

  Description:
    This function allows a client to identify a command event handling function
    for the driver to call back when the last submitted command have finished.

    The event handler should be set before the client performs any "WM8904 Codec
    Specific Client Routines" operations that could generate events.
    The event handler once set, persists until the client closes the driver or
    sets another event handler (which could be a "NULL" pointer to indicate no
    callback).

  Precondition:
    The DRV_WM8904_Initialize routine must have been called for the specified
    WM8904 driver instance.

    DRV_WM8904_Open must have been called to obtain a valid opened device handle.

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

  Example:
    <code>
    MY_APP_OBJ myAppObj;
    uint8_t mybuffer[MY_BUFFER_SIZE];
    DRV_WM8904_BUFFER_HANDLE bufferHandle;

    // myWM8904Handle is the handle returned
    // by the DRV_WM8904_Open function.

    // Client registers an event handler with driver

    DRV_WM8904_CommandEventHandlerSet(myWM8904Handle,
                    APP_WM8904CommandEventHandler, (uintptr_t)&myAppObj);

    DRV_WM8904_DeEmphasisFilterSet(myWM8904Handle, DRV_WM8904_DEEMPHASIS_FILTER_44_1KHZ)

    // Event is received when
    // the buffer is processed.

    void APP_WM8904CommandEventHandler(uintptr_t contextHandle)
    {
        // contextHandle points to myAppObj.

        switch(event)
        {
                // Last Submitted command is completed.
                // Perform further processing here
        }
    }
    </code>

  Remarks:
    If the client does not want to be notified when the command
    has completed, it does not need to register a callback.
 */
void DRV_WM8904_CommandEventHandlerSet
(
    DRV_HANDLE handle,
    const DRV_WM8904_COMMAND_EVENT_HANDLER eventHandler,
    const uintptr_t contextHandle
);

// *****************************************************************************
// *****************************************************************************
// Section: WM8904 Codec Version Information Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/*
  Function:
    int8_t* DRV_WM8904_VersionStrGet(void)

  Summary:
    This function returns the version of WM8904 driver in string format.

  Description:
    The DRV_WM8904_VersionStrGet function returns a string in the format:
    "<major>.<minor>[.<patch>][<type>]"
    Where:
        <major> is the WM8904 driver's version number.
        <minor> is the WM8904 driver's version number.
        <patch> is an optional "patch" or "dot" release number (which is not
        included in the string if it equals "00").
        <type> is an optional release type ("a" for alpha, "b" for beta ?
        not the entire word spelled out) that is not included if the release
        is a production version (I.e. Not an alpha or beta).

        The String does not contain any spaces. For example, 
        "0.03a"
        "1.00"
    
  Precondition:
    None.

  Parameters:
    None.

  Returns: returns a string containing the version of WM8904 driver.

  Example:
    <code>
        int8_t *WM8904string;
        WM8904string = DRV_WM8904_VersionStrGet();
    </code>

  Remarks:
    None
 */
int8_t* DRV_WM8904_VersionStrGet(void);


// *****************************************************************************
/*
  Function:
    uint32_t DRV_WM8904_VersionGet( void )

  Summary:
    This function returns the version of WM8904 driver

  Description:
    The version number returned from the DRV_WM8904_VersionGet function is an
    unsigned integer in the following decimal format.
    <major> * 10000 + <minor> * 100 + <patch>

    Where the numbers are represented in decimal and the meaning is the same as
    above.  Note that there is no numerical representation of release type.

    Example:
    For version "0.03a", return:  0 * 10000 + 3 * 100 + 0
    For version "1.00", return:  1 * 100000 + 0 * 100 + 0


  Precondition:
    None.

  Parameters:
    None.

  Returns: returns the version of WM8904 driver.

  Example:
    <code>
        uint32_t WM8904version;
        WM8904version = DRV_WM8904_VersionGet();
    </code>

  Remarks:
    None.
 */
uint32_t DRV_WM8904_VersionGet(void);

#endif // #ifndef _DRV_WM8904_H
/*******************************************************************************
 End of File
 */

