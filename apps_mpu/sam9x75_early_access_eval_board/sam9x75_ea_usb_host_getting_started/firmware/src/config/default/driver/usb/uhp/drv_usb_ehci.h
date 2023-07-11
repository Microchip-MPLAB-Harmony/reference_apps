/******************************************************************************
  USB EHCI Driver Interface Header File.

  Company:
    Microchip Technology Inc.
    
  File Name:
    drv_usb_ehci.h
	
  Summary:
    USB EHCI Driver Interface File.
	
  Description:
    The USB EHCI driver provides a simple interface to manage the EHCI
    controller on SAM microprocessors. This file defines the interface
    definitions and prototypes for the USB driver. The driver interface meets
    the requirements of the MPLAB Harmony USB Host and Device Layer.                                                  
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2012 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to  you  the  right  to  use,  modify,  copy  and  distribute
Software only when embedded on a Microchip  microcontroller  or  digital  signal
controller  that  is  integrated  into  your  product  or  third  party  product
(pursuant to the  sublicense  terms  in  the  accompanying  license  agreement).

You should refer  to  the  license  agreement  accompanying  this  Software  for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS  WITHOUT  WARRANTY  OF  ANY  KIND,
EITHER EXPRESS  OR  IMPLIED,  INCLUDING  WITHOUT  LIMITATION,  ANY  WARRANTY  OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A  PARTICULAR  PURPOSE.
IN NO EVENT SHALL MICROCHIP OR  ITS  LICENSORS  BE  LIABLE  OR  OBLIGATED  UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,  BREACH  OF  WARRANTY,  OR
OTHER LEGAL  EQUITABLE  THEORY  ANY  DIRECT  OR  INDIRECT  DAMAGES  OR  EXPENSES
INCLUDING BUT NOT LIMITED TO ANY  INCIDENTAL,  SPECIAL,  INDIRECT,  PUNITIVE  OR
CONSEQUENTIAL DAMAGES, LOST  PROFITS  OR  LOST  DATA,  COST  OF  PROCUREMENT  OF
SUBSTITUTE  GOODS,  TECHNOLOGY,  SERVICES,  OR  ANY  CLAIMS  BY  THIRD   PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE  THEREOF),  OR  OTHER  SIMILAR  COSTS.
*******************************************************************************/
//DOM-IGNORE-END

#ifndef _DRV_USB_EHCI_H
#define _DRV_USB_EHCI_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files (continued at end of file)
// *****************************************************************************
// *****************************************************************************
/*  This section lists the other files that are included in this file.  Also,
    see the bottom of the file for additional implementation header files that
    are also included
*/

#include <stdint.h>
#include <stdbool.h>
#include "usb/usb_common.h"
#include "usb/usb_chapter_9.h"
#include "driver/driver_common.h"
#include "system/int/sys_int.h"
#include "driver/usb/drv_usb.h"
#include "system/system_module.h"
#include "usb/usb_hub.h"

// *****************************************************************************
// *****************************************************************************
// Section: USB Device Driver Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* USB Driver Host Mode Interface Functions.

  Summary:
    USB Driver Host Mode Interface Functions.

  Description:
    The Host Controller Driver interface in the Host Layer Initialization data
    structure should be set to this value so that Host Layer can access the USB
    Driver Host Mode functions.

  Remarks:
    None.
*/

/*DOM-IGNORE-BEGIN*/extern DRV_USB_HOST_INTERFACE gDrvUSBEHCIInterface;/*DOM-IGNORE-END */
#define DRV_USB_EHCI_INTERFACE /*DOM-IGNORE-BEGIN*/&gDrvUSBEHCIInterface/*DOM-IGNORE-END */

// *****************************************************************************
/* USB Driver Module Index Definition.

  Summary:
    USB Driver Module Index Definition.

  Description:
    This constant defines the values of USB Driver Instance Indexes.  The
    SYS_MODULE_INDEX parameter of the DRV_USB_EHCI_Initialize and
    DRV_USB_EHCI_Open functions should be set to these values to identify an
    instance of the driver. 

  Remarks:
    These constants should be used in place of hard-coded numeric literals and
    should be passed into the DRV_USB_EHCI_Initialize and DRV_USB_EHCI_Open
    functions to identify the driver instance in use. These are not indicative
    of the number of modules that are actually supported by the
    microcontroller.
*/

#define DRV_USB_EHCI_INDEX_0         0
#define DRV_USB_EHCI_INDEX_1         1
#define DRV_USB_EHCI_INDEX_2         2

// *****************************************************************************
// *****************************************************************************
// Section: USB Device Driver Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* USB Driver Host Pipe Handle.

  Summary:
    Defines the USB Driver Host Pipe Handle type.

  Description:
    This type definition defines the type of the USB Driver Host Pipe Handle.

  Remarks:
    None.
*/

typedef uintptr_t DRV_USB_EHCI_PIPE_HANDLE;

// *****************************************************************************
/* USB Driver Invalid Host Pipe Handle.

  Summary:
    Value of an Invalid Host Pipe Handle.

  Description:
    This constant defines the value of an Invalid Host Pipe Handle.

  Remarks:
    None.
*/

#define DRV_USB_EHCI_PIPE_HANDLE_INVALID ((DRV_USB_EHCI_PIPE_HANDLE)(-1))

// *****************************************************************************
/* USB Root hub Application Hooks (Port Overcurrent detection).

  Summary:
     USB Root hub Application Hooks (Port Overcurrent detection).

  Description:
    A function of the type defined here should be provided to the driver root
    hub to check for port over current condition.  This function will be called
    periodically by the root hub driver to check the Overcurrent status of the
    port. It should continue to return true while the Overcurrent condition
    exists on the port. It should return false when the Overcurrent condition
    does not exist. 

  Remarks:
    None.
*/

typedef bool (* DRV_USB_EHCI_PORT_OVER_CURRENT_DETECT)(uint8_t port);

// *****************************************************************************
/* USB Root hub Application Hooks (Port Power Enable/ Disable).

  Summary:
     USB Root hub Application Hooks (Port Power Enable/ Disable).

  Description:
    A function of the type defined here should be provided to the driver root to
    control port power.  The root hub driver will call this function when it
    needs to enable port power. If the application circuit contains a VBUS
    switch, the switch should be accessed and controlled by this function. If
    the enable parameter is true, the switch should be enabled and VBUS should
    be available on the port. If the enable parameter is false, the
    switch should be disabled and VBUS should not be available on the port.  

  Remarks:
    None.
*/

typedef void (* DRV_USB_EHCI_PORT_POWER_ENABLE)
(
    uint8_t port, 
    bool control
);

// *****************************************************************************
/* USB Root hub Application Hooks (Port Indication).

  Summary:
     USB Root hub Application Hooks (Port Indication).

  Description:
    A function of the type defined here should be provided to the driver root to
    implement Port Indication.  The root hub driver calls this function when it
    needs to update the state of the port indication LEDs. The application can
    choose to implement the Amber and Green colors as one LED or two different
    LEDs.  The root hub driver specifies the color and the indicator attribute
    (on, off or blinking) when it calls this function.

  Remarks:
    None.
*/

typedef void(* DRV_USB_EHCI_PORT_INDICATION)
(
    uint8_t port, 
    USB_HUB_PORT_INDICATOR_COLOR color, 
    USB_HUB_PORT_INDICATOR_STATE state
);

// *****************************************************************************
/* USB Device Driver Initialization Data.

  Summary:
    This type definition defines the Driver Initialization Data Structure.

  Description:
    This structure contains all the data necessary to initialize the USB Driver.
    A pointer to a structure of this type, containing the desired initialization
    data, must be passed into the DRV_USB_EHCI_Initialize function.

  Remarks:
    None.
*/

typedef struct
{
    /* System Module Initialization */
    SYS_MODULE_INIT moduleInit;     
    
    /* Identifies the USB peripheral to be used. This should be the USB PLIB
       module instance identifier. */
    uhphs_registers_t * usbID; 
    
    /* Specify the interrupt source for the USB module. This should be the
       interrupt source identifier for the USB module instance specified in
       usbID. */
    INT_SOURCE interruptSource;

    /* Root hub available current in milliamperes. This specifies the amount of
       current that root hub can provide to the attached device. This should be
       specified in mA. This is required when the driver is required to operate
       in host mode. */
    uint32_t rootHubAvailableCurrent;

    /* When operating in Host mode, the application can specify a Root Hub port
       enable function. This parameter should point to Root Hub port enable
       function. If this parameter is NULL, it implies that the Port is always
       enabled. */
    DRV_USB_EHCI_PORT_POWER_ENABLE portPowerEnable;

    /* When operating in Host mode, the application can specify a Root Port
       Indication. This parameter should point to the Root Port Indication
       function. If this parameter is NULL, it implies that Root Port Indication
       is not supported. */
    DRV_USB_EHCI_PORT_INDICATION portIndication;

    /* When  operating is Host mode, the application can specify a Root Port
       Overcurrent detection. This parameter should point to the Root Port
       Indication function. If this parameter is NULL, it implies that
       Overcurrent detection is not supported. */
    DRV_USB_EHCI_PORT_OVER_CURRENT_DETECT portOverCurrentDetect;

    /* The EHCI controller may support multiple ports. This bit map specifies
     * which port should be scanned by the host controller. */
    uint8_t bmPortSelect;

    /* Companion driver index */
    SYS_MODULE_INDEX companionDriverIndex;

} DRV_USB_EHCI_INIT;

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - System Level
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    SYS_MODULE_OBJ DRV_USB_EHCI_Initialize
    ( 
        const SYS_MODULE_INDEX drvIndex,
        const SYS_MODULE_INIT * const init    
    )
    
  Summary:
    Initializes the USB Driver.
	
  Description:
    This function initializes the USB Driver, making it ready for clients to
    open. The driver initialization does not complete when this function
    returns. The DRV_USB_EHCI_Tasks function must called periodically to
    complete the driver initialization. The DRV_USB_EHCI_Open function will fail
    if the driver was not initialized or if initialization has not completed.
	
  Precondition:
    None.
	
  Parameters:
    drvIndex - Ordinal number of driver instance to be initialized. This should
    be set to DRV_USB_EHCI_INDEX_0 if driver instance 0 needs to be initialized.

    init - Pointer to a data structure containing data necessary to
    initialize the driver. This should be a DRV_USB_EHCI_INIT structure reference
    typecast to SYS_MODULE_INIT reference. 
				
  Returns:
    * SYS_MODULE_OBJ_INVALID - The driver initialization failed.
    * A valid System Module Object - The driver initialization was able to
      start. It may have not completed and requires the DRV_USB_EHCI_Tasks
      function to be called periodically. This value will never be the same as
      SYS_MODULE_OBJ_INVALID. 
	
  Example:
    <code>
    
    DRV_USB_EHCI_Initialize(DRV_USB_EHCI_INDEX_0, (SYS_MODULE_INIT *) &usbInitData);
    
    </code>
	
  Remarks:
    This routine must be called before any other USB driver routine is called.
    This routine should only be called once during system initialization unless
    DRV_USB_EHCI_Deinitialize is called to deinitialize the driver instance. 
*/

SYS_MODULE_OBJ DRV_USB_EHCI_Initialize 
(
    const SYS_MODULE_INDEX drvIndex,
    const SYS_MODULE_INIT * const init
);

// *****************************************************************************
/* Function:
    SYS_STATUS DRV_USB_EHCI_Status ( SYS_MODULE_OBJ object )

  Summary:
    Provides the current status of the USB Driver module.

  Description:
    This function provides the current status of the USB Driver module.

  Precondition:
    The DRV_USB_EHCI_Initialize function must have been called before calling this
    function.

  Parameters:
    object - Driver object handle, returned from the DRV_USB_EHCI_Initialize function.

  Returns:
    * SYS_STATUS_READY - Indicates that the driver is ready.
    * SYS_STATUS_UNINITIALIZED - Indicates that the driver has never been
      initialized.

  Example:
    <code>
    
    // The status of the driver can be checked.
    status = DRV_USB_EHCI_Status(object);
    if(SYS_STATUS_READY == status)
    {
        // Driver is ready to be opened.
    }

    </code>

  Remarks:
    None.
*/

SYS_STATUS DRV_USB_EHCI_Status ( SYS_MODULE_OBJ object );

// *****************************************************************************
/* Function:
    void DRV_USB_EHCI_Tasks( SYS_MODULE_OBJ object )

  Summary:
    Maintains the driver's state machine when the driver is configured for 
    Polled mode.

  Description:
    Maintains the driver's Polled state machine. This function should be called
    from the SYS_Tasks function.

  Precondition:
    The DRV_USB_EHCI_Initialize function must have been called for the specified
    USB Driver instance.

  Parameters:
    object - Object handle for the specified driver instance (returned from
    DRV_USB_EHCI_Initialize function).

  Returns:
    None.

  Example:
    <code>
    SYS_MODULE_OBJ      object;     // Returned from DRV_USB_EHCI_Initialize

    while (true)
    {
        DRV_USB_EHCI_Tasks(object);

        // Do other tasks
    }
    </code>

  Remarks:
    This routine is normally not called  directly  by  an  application.   It  is
    called by the system's Tasks routine (SYS_Tasks). This function will never
    block.  
*/

void DRV_USB_EHCI_Tasks(SYS_MODULE_OBJ object);

// *****************************************************************************
/* Function:
    void DRV_USB_EHCI_Tasks_ISR( SYS_MODULE_OBJ object )

  Summary:
    Maintains the driver's Interrupt state machine and implements its ISR.

  Description:
    This function is used to maintain the driver's internal Interrupt state
    machine and implement its ISR for interrupt-driven implementations.

  Precondition:
    The DRV_USB_EHCI_Initialize function must have been called for the specified
    USB Driver instance.

  Parameters:
    object - Object handle for the specified driver instance (returned from
    DRV_USB_EHCI_Initialize).

  Returns:
    None.

  Example:
    <code>
    SYS_MODULE_OBJ object;     // Returned from DRV_USB_EHCI_Initialize

    while (true)
    {
        DRV_USB_EHCI_Tasks_ISR (object);

        // Do other tasks
    }
    </code>

  Remarks:
    This routine should be called from the USB interrupt service routine. In
    case of multiple USB modules, it should be ensured that the correct USB
    driver system module object is passed to this routine.
*/

void DRV_USB_EHCI_Tasks_ISR( SYS_MODULE_OBJ object );

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - Client Level
// *****************************************************************************
// *****************************************************************************

// ****************************************************************************
/* Function:
    DRV_HANDLE DRV_USB_EHCI_Open
    ( 
        const SYS_MODULE_INDEX drvIndex,
        const DRV_IO_INTENT intent
    )
    
  Summary:
    Opens the specified USB Driver instance and returns a handle to it.
	
  Description:
    This function opens the specified USB Driver instance and provides a handle
    that must be provided to all other client-level operations to identify the
    caller and the instance of the driver. The value of the intent flag is
    ignored.  A driver instance can only support one client. Trying to open a
    driver that has an existing client will result in an unsuccessful function
    call.
	
  Precondition:
    Function DRV_USB_EHCI_Initialize must have been called before calling this
    function.
	
  Parameters:
    drvIndex - Identifies the driver instance to be opened. As an example, this
    value can be set to DRV_USB_EHCI_INDEX_0 if instance 0 of the driver has to be
    opened.
    
    intent - Should always be 
    (DRV_IO_INTENT_EXCLUSIVE|DRV_IO_INTENT_READWRITE| DRV_IO_INTENT_NON_BLOCKING).
				
  Returns:
    * DRV_HANDLE_INVALID - The driver could not be opened successfully.This can
      happen if the driver initialization was not complete or if an internal
      error has occurred.  
    * A Valid Driver Handle - This is an arbitrary value and is returned if the
      function was successful. This value will never be the same as
      DRV_HANDLE_INVALID. 
	
  Example:
    <code>

    DRV_HANDLE handle;

    // This code assumes that the driver has been initialized.
    handle = DRV_USB_EHCI_Open(DRV_USB_EHCI_INDEX_0, DRV_IO_INTENT_EXCLUSIVE|
                            DRV_IO_INTENT_READWRITE| DRV_IO_INTENT_NON_BLOCKING);

    if(DRV_HANDLE_INVALID == handle)
    {
        // The application should try opening the driver again.
    }
    
    </code>
	
  Remarks:
    The handle returned is valid until the DRV_USB_EHCI_Close function is called.
    The function will typically return DRV_HANDLE_INVALID if the driver was not
    initialized. In such a case the client should try to open the driver again.
*/

DRV_HANDLE DRV_USB_EHCI_Open
(
    const SYS_MODULE_INDEX drvIndex,
    const DRV_IO_INTENT intent  
);

// *****************************************************************************
/* Function:
    void DRV_USB_EHCI_Close( DRV_HANDLE handle )

  Summary:
    Closes an opened-instance of the  USB Driver.

  Description:
    This function closes an opened-instance of the  USB Driver, invalidating the
    handle.

  Precondition:
    The DRV_USB_EHCI_Initialize function must have been called for the specified
    USB Driver instance. DRV_USB_EHCI_Open function must have been called to obtain
    a valid opened device handle.

  Parameters:
    handle  - Client's driver handle (returned from DRV_USB_EHCI_Open function).

  Returns:
    None.

  Example:
    <code>
    DRV_HANDLE handle;  // Returned from DRV_USB_EHCI_Open

    DRV_USB_EHCI_Close(handle);
    </code>

  Remarks:
    After calling this function, the handle passed in handle parameter must not
    be  used with any of the other driver functions. A new handle must be
    obtained by calling DRV_USB_EHCI_Open function before the caller may use the
    driver again.
*/

void DRV_USB_EHCI_Close( DRV_HANDLE handle );

// ****************************************************************************
/* Function:
    void DRV_USB_EHCI_IRPCancel(USB_HOST_IRP * inputIRP);
    
  Summary:
    Cancels the specified IRP.
	
  Description:
    This function attempts to cancel the specified IRP. If the IRP is queued and
    its processing has not started, it will be cancelled successfully. If the
    IRP in progress, the ongoing transaction will be allowed to complete. 
	
  Precondition:
    None.
	
  Parameters:
    inputIRP - Pointer to the IRP to cancel.
	
  Returns:
    None.
	
  Example:
    <code>

    // This code shows how a submitted IRP can be cancelled.

    USB_HOST_IRP irp;
    
    DRV_USB_EHCI_IRPCancel(&irp);

    </code>
	
  Remarks:
    None.                                                                  
*/

void DRV_USB_EHCI_IRPCancel(USB_HOST_IRP * inputIRP);

// ****************************************************************************
/* Function:
    void DRV_USB_EHCI_PipeClose
    (
        DRV_USB_EHCI_PIPE_HANDLE pipeHandle
    );
    
  Summary:
    Closes an open pipe.
	
  Description:
    This function closes an open pipe. Any IRPs scheduled on the pipe will be
    aborted and IRP callback functions will be called with the status as
    DRV_USB_HOST_IRP_STATE_ABORTED. The pipe handle will become invalid and the
    pipe will not accept IRPs.
	
  Precondition:
    The pipe handle should be valid.
	
  Parameters:
    pipeHandle - Handle to the pipe to close.
	
  Returns:
    None.
	
  Example:
    <code>
    // This code shows how an open Host pipe can be closed.
    
    DRV_HANDLE driverHandle;
    DRV_USB_EHCI_PIPE_HANDLE pipeHandle;

    // Close the pipe.
    DRV_USB_EHCI_PipeClose(pipeHandle);
    </code>
	
  Remarks:
    None.                                                                  
*/

void DRV_USB_EHCI_PipeClose
(
    DRV_USB_EHCI_PIPE_HANDLE pipeHandle
);

// ****************************************************************************
/* Function:
    bool DRV_USB_EHCI_EventsDisable
    (
        DRV_HANDLE handle
    );
    
  Summary:
    Disables Host mode events.
	
  Description:
    This function disables the Host mode events. This function is called by the
    Host Layer when it wants to execute code atomically. 
	
  Precondition:
    The handle should be valid.
	
  Parameters:
    handle - Client's driver handle (returned from DRV_USB_EHCI_Open function).
	
  Returns:
    * true - Driver event generation was enabled when this function was called.
    * false - Driver event generation was not enabled when this function was
      called. 
	
  Example:
    <code>
    // This code shows how the DRV_USB_EHCI_EventsDisable and
    // DRV_USB_EHCI_EventsEnable function can be called to disable and enable
    // events.

    DRV_HANDLE driverHandle;
    bool eventsWereEnabled;

    // Disable the driver events.
    eventsWereEnabled = DRV_USB_EHCI_EventsDisable(driverHandle);

    // Code in this region will not be interrupted by driver events.

    // Enable the driver events.
    DRV_USB_EHCI_EventsEnable(driverHandle, eventsWereEnabled);

    </code>
	
  Remarks:
    None.
*/

bool DRV_USB_EHCI_EventsDisable
(
    DRV_HANDLE handle
);

// ****************************************************************************
/* Function:
    void DRV_USB_EHCI_EventsEnable
    (
        DRV_HANDLE handle
        bool eventRestoreContext
    );
    
  Summary:
    Restores the events to the specified the original value.
	
  Description:
    This function will restore the enable disable state of the events.  The
    eventRestoreContext parameter should be equal to the value returned by the
    DRV_USB_EHCI_EventsDisable function.
	
  Precondition:
    The handle should be valid.
	
  Parameters:
    handle - Handle to the driver (returned from DRV_USB_EHCI_Open function).
    eventRestoreContext - Value returned by the DRV_USB_EHCI_EventsDisable
    function.
	
  Returns:
    None.
	
  Example:
    <code>
    // This code shows how the DRV_USB_EHCI_EventsDisable and
    // DRV_USB_EHCI_EventsEnable function can be called to disable and enable
    // events.

    DRV_HANDLE driverHandle;
    bool eventsWereEnabled;

    // Disable the driver events.
    eventsWereEnabled = DRV_USB_EHCI_EventsDisable(driverHandle);

    // Code in this region will not be interrupted by driver events.

    // Enable the driver events.
    DRV_USB_EHCI_EventsEnable(driverHandle, eventsWereEnabled);

    </code>
	
  Remarks:
    None.
*/

void DRV_USB_EHCI_EventsEnable
(
    DRV_HANDLE handle, 
    bool eventContext
);

// ****************************************************************************
/* Function:
    USB_ERROR DRV_USB_EHCI_IRPSubmit
    (
        DRV_USB_EHCI_PIPE_HANDLE  hPipe,
        USB_HOST_IRP * pInputIRP
    );
    
  Summary:
    Submits an IRP on a pipe.
	
  Description:
    This function submits an IRP on the specified pipe. The IRP will be added to
    the queue and will be processed in turn. The data will be transferred on the
    bus based on the USB bus scheduling rules. When the IRP has been processed,
    the callback function specified in the IRP will be called. The IRP status
    will be updated to reflect the completion status of the IRP. 
	
  Precondition:
    The pipe handle should be valid.
	
  Parameters:
    hPipe - Handle to the pipe to which the IRP has to be submitted.

    pInputIRP - Pointer to the IRP.
	
  Returns:
    * USB_ERROR_NONE - The IRP was submitted successfully.
    * USB_ERROR_PARAMETER_INVALID - The pipe handle is not valid.
    * USB_ERROR_OSAL_FUNCTION - An error occurred in an OSAL function called in
      this function.
	
  Example:
    <code>

    result = DRV_USB_EHCI_IRPSubmit(controlPipeHandle, &irp);

    </code>
	
  Remarks:
    An IRP can also be submitted in an IRP callback function.                                                                  
*/

USB_ERROR DRV_USB_EHCI_IRPSubmit
(
    DRV_USB_EHCI_PIPE_HANDLE  hPipe,
    USB_HOST_IRP * pinputIRP
);

// ****************************************************************************
/* Function:
    DRV_USB_EHCI_PIPE_HANDLE DRV_USB_EHCI_PipeSetup 
    (
        DRV_HANDLE client,
        uint8_t deviceAddress, 
        USB_ENDPOINT endpointAndDirection,
        uint8_t hubAddress,
        uint8_t hubPort,
        USB_TRANSFER_TYPE pipeType, 
        uint8_t bInterval, 
        uint16_t wMaxPacketSize,
        USB_SPEED speed
    );
    
  Summary:
    Open a pipe with the specified attributes.
	
  Description:
    This function opens a communication pipe between the Host and the device
    endpoint. The transfer type and other attributes are specified through the
    function parameters. The driver does not check for available bus bandwidth,
    which should be done by the application (the USB Host Layer in this case)
	
  Precondition:
    The driver handle should be valid.
	
  Parameters:
    client - Handle to the driver (returned from DRV_USB_EHCI_Open function).
    
    deviceAddress - USB Address of the device to connect to.
    
    endpoint - Endpoint on the device to connect to.
    
    hubAddress - Address of the hub to which this device is connected. If not
    connected to a hub, this value should be set to 0. 

    hubPort - Port number of the hub to which this device is connected.

    pipeType - Transfer type of the pipe to open.
    
    bInterval - Polling interval for periodic transfers. This should be
    specified as defined by the USB 2.0 Specification.

    wMaxPacketSize - This should be set to the endpoint size reported by the
    device in its configuration descriptors. This defines the maximum size of
    the transaction in a transfer on this pipe.

    speed - The speed of the pipe. This should match the speed at which the
    device connected to the Host.

  Returns:
    * DRV_USB_EHCI_PIPE_HANDLE_INVALID - The pipe could not be created.
    * A valid Pipe Handle - The pipe was created successfully. This is an
      arbitrary value and will never be the same as
      DRV_USB_EHCI_PIPE_HANDLE_INVALID.
	
  Example:
    <code>
    // This code shows how the DRV_USB_EHCI_PipeSetup function is called for
    // create a communication pipe. In this example, Bulk pipe is created
    // between the Host and a device. The Device address is 2 and the target
    // endpoint on this device is 4 . The direction of the data transfer over
    // this pipe is from the Host to the device. The device is connected to Port
    // 1 of a Hub, whose USB address is 3. The maximum size of a transaction
    // on this pipe is 64 bytes. This is a Bulk Pipe and hence the bInterval
    // field is set to 0. The target device is operating at Full Speed.

    DRV_HANDLE driverHandle;
    DRV_USB_EHCI_PIPE_HANDLE pipeHandle;

    pipeHandle = DRV_USB_EHCI_PipeSetup(driverHandle, 0x02, 0x14, 0x03, 0x01, USB_TRANSFER_TYPE_BULK, 0, 64, USB_SPEED_FULL); 

    if(pipeHandle != DRV_USB_EHCI_PIPE_HANDLE_INVALID)
    {
        // The pipe was created successfully.
    }

    </code>
	
  Remarks:
    None.                                                                  
*/

DRV_USB_EHCI_PIPE_HANDLE DRV_USB_EHCI_PipeSetup 
(
    DRV_HANDLE client,
    uint8_t deviceAddress, 
    USB_ENDPOINT endpointAndDirection,
    uint8_t hubAddress,
    uint8_t hubPort,
    USB_TRANSFER_TYPE pipeType, 
    uint8_t bInterval, 
    uint16_t wMaxPacketSize,
    USB_SPEED speed
);

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - Root Hub
// *****************************************************************************
// *****************************************************************************

// ****************************************************************************
/* Function:
    void DRV_USB_EHCI_PortReset(DRV_HANDLE handle, uint8_t port );
    
  Summary:
    Resets the specified root hub port.
	
  Description:
    This function resets the root hub port. The reset duration is defined by
    DRV_USB_EHCI_RESET_DURATION. The status of the reset signaling can be
    checked using the DRV_USB_EHCI_PortResetIsComplete function.
	
  Precondition:
    None.
	
  Parameters:
    handle - Handle to the driver (returned from DRV_USB_EHCI_Open function).

    port - Port to reset.
	
  Returns:
    None.
	
  Example:
    <code>
    // This code shows how the DRV_USB_EHCI_PortReset and the
    // DRV_USB_EHCI_PortResetIsComplete functions are called to complete a
    // port reset sequence.

    DRV_HANDLE driverHandle;

    // Reset Port 0.
    DRV_USB_EHCI_PortReset(driverHandle, 0);

    // Check if the Reset operation has completed.
    if(DRV_USB_EHCI_PortResetIsComplete(driverHandle, 0) == false)
    {
        // This means that the Port Reset operation has not completed yet. The
        // DRV_USB_EHCI_PortResetIsComplete function should be called
        // again after some time to check the status.
    }

    </code>
	
  Remarks:
    None.
*/

USB_ERROR DRV_USB_EHCI_PortReset(DRV_HANDLE handle, uint8_t port );

// ****************************************************************************
/* Function:
    bool DRV_USB_EHCI_PortResetIsComplete
    (
        DRV_HANDLE handle,
        uint8_t port
    );

  Summary:
    Returns true if the root hub has completed the port reset operation.

  Description:
    This function returns true if the port reset operation has completed. It
    should be called after the DRV_USB_PortReset function to
    check if the reset operation has completed.

  Precondition:
    None.

  Parameters:
    handle - Handle to the driver (returned from DRV_USB_EHCI_Open function).

    port - Port to check

  Returns:
    * true - The reset signaling has completed.
    * false - The reset signaling has not completed.

  Example:
    <code>
    // This code shows how the DRV_USB_PortReset and the
    // DRV_USB_EHCI_PortResetIsComplete functions are called to complete a
    // port reset sequence.

    DRV_HANDLE driverHandle;

    // Reset Port 0.
    DRV_USB_PortReset(driverHandle, 0);

    // Check if the Reset operation has completed.
    if(DRV_USB_EHCI_PortResetIsComplete(driverHandle, 0) == false)
    {
        // This means that the Port Reset operation has not completed yet. The
        // DRV_USB_EHCI_PortResetIsComplete function should be called
        // again after some time to check the status.
    }

    </code>

  Remarks:
    The root hub on this particular hardware only contains one port - port 0.
*/

bool DRV_USB_EHCI_PortResetIsComplete(DRV_HANDLE handle, uint8_t port );

// ****************************************************************************
/* Function:
    USB_ERROR DRV_USB_EHCI_PortResume
    (
        DRV_HANDLE handle, 
        uint8_t port
    );
    
  Summary:
    Resumes the specified root hub port.
	
  Description:
    This function resumes the root hub. The resume duration is defined by
    DRV_USB_EHCI_RESUME_DURATION. The status of the resume signaling can
    be checked using the DRV_USB_EHCI_PortResumeIsComplete function.
	
  Precondition:
    None.
	
  Parameters:
    handle - Handle to the driver (returned from DRV_USB_EHCI_Open function).

    port - Port to resume.
	
  Returns:
    * USB_ERROR_NONE - The function executed successfully.
    * USB_ERROR_PARAMETER_INVALID - The driver handle is not valid or the port
      number does not exist.
	
  Example:
    <code>
    // This code shows how the DRV_USB_EHCI_PortResume function is
    // called to resume the specified port.

    DRV_HANDLE driverHandle;

    // Resume Port 0.
    DRV_USB_EHCI_PortResume(driverHandle, 0);

    </code>
	
  Remarks:
    The root hub on this particular hardware only contains one port - port 0.                                                                  
*/

USB_ERROR DRV_USB_EHCI_PortResume(DRV_HANDLE handle, uint8_t port);

// ****************************************************************************
/* Function:
    USB_ERROR DRV_USB_EHCI_PortSuspend(DRV_HANDLE handle, uint8_t port);
    
  Summary:
    Suspends the specified root hub port.
	
  Description:
    This function suspends the root hub port. 
	
  Precondition:
    None.
	
  Parameters:
    handle - Handle to the driver (returned from DRV_USB_EHCI_Open function).

    port - Port to suspend.
	
  Returns:
    * USB_ERROR_NONE - The function executed successfully.
    * USB_ERROR_PARAMETER_INVALID - The driver handle is not valid or the port
      number does not exist.
	
  Example:
    <code>
    // This code shows how the DRV_USB_EHCI_PortSuspend function is
    // called to suspend the specified port.

    DRV_HANDLE driverHandle;

    // Suspend Port 0.
    DRV_USB_EHCI_PortSuspend(driverHandle, 0);

    </code>
	
  Remarks:
    The root hub on this particular hardware only contains one port - port 0.                                                                  
*/

USB_ERROR DRV_USB_EHCI_PortSuspend(DRV_HANDLE handle, uint8_t port);

// ****************************************************************************
/* Function:
    USB_SPEED DRV_USB_EHCI_PortSpeedGet
    (
        DRV_HANDLE handle, 
        uint8_t port
    );
    
  Summary:
    Returns the speed of at which the port is operating.
	
  Description:
    This function returns the speed at which the port is operating.
	
  Precondition:
    None.
	
  Parameters:
    handle - Handle to the driver (returned from DRV_USB_EHCI_Open function).

    port - Port number of the port to be analyzed..
	
  Returns:
    * USB_SPEED_ERROR - This value is returned  if the driver handle is not
      or if the speed information is not available or if the specified port is
      not valid.
    * USB_SPEED_HIGH - A Full Speed device has been connected to the port.
	
  Example:
    <code>
    // This code shows how the DRV_USB_EHCI_PortSpeedGet function is
    // called to know the operating speed of the port. This also indicates the
    // operating speed of the device connected to this port.

    DRV_HANDLE driverHandle;
    USB_SPEED speed;

    speed = DRV_USB_EHCI_PortSpeedGet(driverHandle, 0);

    </code>
	
  Remarks:
    The root hub on this particular hardware only contains one port - port 0.                                                                  
*/

USB_SPEED DRV_USB_EHCI_PortSpeedGet(DRV_HANDLE handle, uint8_t port);

// ****************************************************************************
/* Function:
    USB_SPEED DRV_USB_EHCI_BusSpeedGet(DRV_HANDLE handle);
    
  Summary:
    This function returns the operating speed of the bus to which this root hub
    is connected.
	
  Description:
    This function returns the operating speed of the bus to which this root hub
    is connected.
 
  Precondition:
    None.
	
  Parameters:
    handle - Handle to the driver (returned from DRV_USB_EHCI_Open function).

  Returns:
    * USB_SPEED_HIGH - The Root hub is connected to a bus that is operating at
      High Speed.
	
  Example:
    <code>
    // This code shows how the DRV_USB_EHCI_BusSpeedGet function is
    // called to know the operating speed of the bus to which this Root hub is
    // connected.

    DRV_HANDLE driverHandle;
    USB_SPEED speed;

    speed = DRV_USB_EHCI_BusSpeedGet(driverHandle);
    </code>
	
  Remarks:
    None.
*/

USB_SPEED DRV_USB_EHCI_BusSpeedGet(DRV_HANDLE handle);

// ****************************************************************************
/* Function:
    uint32_t DRV_USB_EHCI_MaximumCurrentGet(DRV_HANDLE);
    
  Summary:
    Returns the maximum amount of current that this root hub can provide on the
    bus.
	
  Description:
    This function returns the maximum amount of current that this root hub can
    provide on the bus.
	
  Precondition:
    None.
	
  Parameters:
    handle - Handle to the driver (returned from DRV_USB_EHCI_Open function).

  Returns:
    Returns the maximum current (in milliamperes) that the root hub can supply. 
	
  Example:
    <code>
    // This code shows how the DRV_USB_EHCI_MaximumCurrentGet
    // function is called to obtain the maximum VBUS current that the Root hub
    // can supply.

    DRV_HANDLE driverHandle;
    uint32_t currentMilliAmperes;

    currentMilliAmperes = DRV_USB_EHCI_MaximumCurrentGet(driverHandle);
    </code>
	
  Remarks:
    None.
*/

uint32_t DRV_USB_EHCI_MaximumCurrentGet(DRV_HANDLE handle);

// ****************************************************************************
/* Function:
    uint8_t DRV_USB_EHCI_PortNumbersGet(DRV_HANDLE handle);

  Summary:
    Returns the number of ports this root hub contains.

  Description:
    This function returns the number of ports that this root hub contains.

  Precondition:
    None.

  Parameters:
    handle - Handle to the driver (returned from DRV_USB_EHCI_Open function).

  Returns:
    This function will always return 1.

  Example:
    <code>
    // This code shows how DRV_USB_EHCI_PortNumbersGet function can
    // be called to obtain the number of Root hub ports.

    DRV_HANDLE driverHandle;
    uint8_t nPorts;

    nPorts = DRV_USB_EHCI_PortNumbersGet(driverHandle);

    </code>

  Remarks:
    None.
*/

uint8_t DRV_USB_EHCI_PortNumbersGet(DRV_HANDLE handle);

// ****************************************************************************
/* Function:
    void DRV_USB_EHCI_OperationEnable
    (
        DRV_HANDLE handle, 
        bool enable
    );

  Summary:
    This function enables or disables root hub operation.

  Description:
    This function enables or disables root hub operation. When enabled, the root
    hub will detect devices attached to the port and will request the Host Layer
    to enumerate the device. This function is called by the Host Layer when it
    is ready to receive enumeration requests from the Host. If the operation is
    disabled, the root hub will not detect attached devices.

  Precondition:
    None.

  Parameters:
    handle - Handle to the driver (returned from DRV_USB_EHCI_Open function).

    enable - If this is set to true, root hub operation is enabled. If this is
    set to false, root hub operation is disabled.

  Returns:
    None.

  Example:
    <code>
    // This code shows how the DRV_USB_EHCI_OperationEnable and the
    // DRV_USB_EHCI_OperationIsEnabled functions are called to enable
    // the Root hub operation.

    DRV_HANDLE driverHandle;

    // Enable Root hub operation.
    DRV_USB_EHCI_OperationEnable(driverHandle);

    // Wait till the Root hub operation is enabled.  
    if(DRV_USB_EHCI_OperationIsEnabled(driverHandle) == false)
    {
        // The operation has not completed. Call the
        // DRV_USB_EHCI_OperationIsEnabled function again to check if
        // the operation has completed. Note that the DRV_USB_EHCI_Tasks function
        // must be allowed to run at periodic intervals to allow the enable
        // operation to completed.
    }
    </code>

  Remarks:
    None.
*/

void DRV_USB_EHCI_OperationEnable(DRV_HANDLE handle, bool enable);

// ****************************************************************************
/* Function:
    bool DRV_USB_EHCI_OperationIsEnabled(DRV_HANDLE handle);

  Summary:
    Returns the operation enabled status of the root hub.

  Description:
    This function returns true if the DRV_USB_EHCI_OperationEnable
    function has completed enabling the Host.

  Precondition:
    None.

  Parameters:
    handle - Handle to the driver (returned from DRV_USB_EHCI_Open function).

  Returns:
    * true - Root hub operation is enabled.
    * false - Root hub operation is not enabled.

  Example:
    <code>
    // This code shows how the DRV_USB_EHCI_OperationEnable and the
    // DRV_USB_EHCI_OperationIsEnabled functions are called to enable
    // the Root hub operation.

    DRV_HANDLE driverHandle;

    // Enable Root hub operation.
    DRV_USB_EHCI_OperationEnable(driverHandle);

    // Wait till the Root hub operation is enabled.  
    if(DRV_USB_EHCI_OperationIsEnabled(driverHandle) == false)
    {
        // The operation has not completed. Call the
        // DRV_USB_EHCI_OperationIsEnabled function again to check if
        // the operation has completed. Note that the DRV_USB_EHCI_Tasks function
        // must be allowed to run at periodic intervals to allow the enable
        // operation to completed.
    }

    </code>

  Remarks:
    None.
*/

bool DRV_USB_EHCI_OperationIsEnabled(DRV_HANDLE handle);

// ****************************************************************************
/* Function:
    void DRV_USB_EHCI_RootHubInitialize
    (
        DRV_HANDLE handle,
        USB_HOST_DEVICE_OBJ_HANDLE usbHostDeviceInfo,
    )

  Summary:
    This function initializes the root hub driver.

  Description:
    This function initializes the root hub driver. It is called by the Host
    Layer at the time of processing the root hub devices. The Host Layer assigns a
    USB_HOST_DEVICE_INFO reference to this root hub driver. This identifies the
    relationship between the root hub and the Host Layer.

  Precondition:
    None.

  Parameters:
    handle - Handle to the driver.
    usbHostDeviceInfo - Reference provided by the Host.

  Returns:
    None.

  Example:
    <code>

    // This code shows how the USB Host Layer calls the
    // DRV_USB_EHCI_Initialize function. The usbHostDeviceInfo
    // parameter is an arbitrary identifier assigned by the USB Host Layer. Its
    // interpretation is opaque to the Root hub Driver.

    DRV_HANDLE drvHandle;
    USB_HOST_DEVICE_OBJ_HANDLE usbHostDeviceInfo = 0x10003000;

    DRV_USB_EHCI_Initialize(drvHandle, usbHostDeviceInfo);

    </code>

  Remarks:
    None.
*/

void DRV_USB_EHCI_RootHubInitialize
(
    DRV_HANDLE handle,
    USB_HOST_DEVICE_OBJ_HANDLE usbHostDeviceInfo
);


// ****************************************************************************
/* Function:
    void DRV_USB_EHCI_EndpointToggleClear
    (
        DRV_USB_EHCI_PIPE_HANDLE pipeHandle
    )

  Summary:
    Facilitates in resetting of endpoint data toggle to 0 for Non Control
    endpoints.

  Description:
    Facilitates in resetting of endpoint data toggle to 0 for Non Control
    endpoints.
	
  Precondition:
    None.

  Parameters:
    pipeHandle - Handle to the pipe that connects to the device endpoint
    whose data toggle needs to be cleared.

  Example:
    <code>

    // This code shows how the USB Host Layer calls the
    // DRV_USB_EHCI_EndpointToggleClear function. 

    DRV_USB_EHCI_PIPE_HANDLE pipeHandle ;

    DRV_USB_EHCI_EndpointToggleClear(pipeHandle);

    </code>

  Remarks:
    None.
*/

void DRV_USB_EHCI_EndpointToggleClear
(
    DRV_USB_EHCI_PIPE_HANDLE pipeHandle
);

// *****************************************************************************
// *****************************************************************************
// Section: Included Files (continued)
// *****************************************************************************
// *****************************************************************************


#endif
