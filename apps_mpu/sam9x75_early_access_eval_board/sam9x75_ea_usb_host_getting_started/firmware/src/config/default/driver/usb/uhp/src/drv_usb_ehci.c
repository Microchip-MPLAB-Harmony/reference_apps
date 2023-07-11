/*******************************************************************************
   USB EHCI Driver Routines

   Company:
    Microchip Technology Inc.

   File Name:
    drv_usb_ehci.c

   Summary:
    USB EHCI Driver Routines.

   Description:
    This file contains the implementation of the EHCI driver. It should be 
    included in the project is EHCI support is required.
*******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Include Files
// *****************************************************************************
// *****************************************************************************

#include "driver/usb/uhp/src/drv_usb_ehci_local.h"

// *****************************************************************************
// *****************************************************************************
// Section: EHCI Driver Variables and data structures
// *****************************************************************************
// *****************************************************************************

/*****************************************
 *  The Driver Hardware Instance Object.
 *****************************************/
DRV_USB_EHCI_OBJ gDrvUSBEHCIObj[DRV_USB_EHCI_INSTANCES_NUMBER];

/********************************************************
 * The EHCI Driver Required Array. The one additional
 * queue head in the gDrvUSBEHCIQueueHead array
 * will be used as the head of reclamation queue head 
 * in the async list.
 ********************************************************/
__ALIGNED(4096) _DRV_USB_EHCI_NON_CACHED uint32_t gDrvUSBEHCIPeriodicFrameList[DRV_USB_EHCI_INSTANCES_NUMBER][DRV_USB_EHCI_PERIODIC_LIST_SIZE];
__ALIGNED(64) _DRV_USB_EHCI_NON_CACHED DRV_USB_EHCI_QH gDrvUSBEHCIQueueHead[DRV_USB_EHCI_INSTANCES_NUMBER][USB_HOST_PIPES_NUMBER + 1];
__ALIGNED(64) _DRV_USB_EHCI_NON_CACHED DRV_USB_EHCI_QTD gDrvUSBEHCIQueueTransferDescriptor[DRV_USB_EHCI_INSTANCES_NUMBER][USB_HOST_TRANSFERS_NUMBER];
__ALIGNED(64) _DRV_USB_EHCI_NON_CACHED DRV_USB_EHCI_CONTROL_TRANSFER_QTD gDrvUSBEHCIControlTransferQTD[DRV_USB_EHCI_INSTANCES_NUMBER][USB_HOST_TRANSFERS_NUMBER];
_DRV_USB_EHCI_NON_CACHED uint8_t gDrvUSBEHCITransferBuffer[DRV_USB_EHCI_INSTANCES_NUMBER][USB_HOST_TRANSFERS_NUMBER][DRV_USB_EHCI_TRANSFER_BUFFER_SIZE];
_DRV_USB_EHCI_NON_CACHED uint8_t gDrvUSBEHCIControlTransferBuffer[DRV_USB_EHCI_INSTANCES_NUMBER][USB_HOST_TRANSFERS_NUMBER][DRV_USB_EHCI_CONTROL_TRANSFER_BUFFER_SIZE];

/***********************************
 * Driver Host Common Interface
 ***********************************/

DRV_USB_HOST_INTERFACE gDrvUSBEHCIInterface =
{
    .open = DRV_USB_EHCI_Open,
    .close = DRV_USB_EHCI_Close,
    .eventHandlerSet = NULL,
    .hostIRPSubmit = DRV_USB_EHCI_IRPSubmit,
    .hostIRPCancel = DRV_USB_EHCI_IRPCancel,
    .hostPipeSetup = DRV_USB_EHCI_PipeSetup,
    .hostPipeClose = DRV_USB_EHCI_PipeClose,
    .endpointToggleClear = DRV_USB_EHCI_EndpointToggleClear,
    .hostEventsDisable = DRV_USB_EHCI_EventsDisable,
    .hostEventsEnable = DRV_USB_EHCI_EventsEnable,
    .rootHubInterface.rootHubPortInterface.hubPortReset = DRV_USB_EHCI_PortReset,
    .rootHubInterface.rootHubPortInterface.hubPortSpeedGet = DRV_USB_EHCI_PortSpeedGet,
    .rootHubInterface.rootHubPortInterface.hubPortResetIsComplete = DRV_USB_EHCI_PortResetIsComplete,
    .rootHubInterface.rootHubPortInterface.hubPortSuspend = DRV_USB_EHCI_PortSuspend,
    .rootHubInterface.rootHubPortInterface.hubPortResume = DRV_USB_EHCI_PortResume,
    .rootHubInterface.rootHubMaxCurrentGet = DRV_USB_EHCI_MaximumCurrentGet,
    .rootHubInterface.rootHubPortNumbersGet = DRV_USB_EHCI_PortNumbersGet,
    .rootHubInterface.rootHubSpeedGet = DRV_USB_EHCI_BusSpeedGet,
    .rootHubInterface.rootHubInitialize = DRV_USB_EHCI_RootHubInitialize,
    .rootHubInterface.rootHubOperationEnable = DRV_USB_EHCI_OperationEnable,
    .rootHubInterface.rootHubOperationIsEnabled = DRV_USB_EHCI_OperationIsEnabled,

};

// *****************************************************************************
// *****************************************************************************
// Section: EHCI Driver Local Function Implementations
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    uint16_t _DRV_USB_EHCI_GetUniqueKey (DRV_USB_EHCI_OBJ * hDriver)

  Summary:
    Returns a unique key that is used to create driver and pipe handles.
    
  Description:
    Returns a unique key that is used to create driver and pipe handles.
    Function should be called from an thread safe context.

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/

uint16_t _DRV_USB_EHCI_GetUniqueKey (DRV_USB_EHCI_OBJ * hDriver)
{
    /* This function creates a unique key. It should be called
     * from a thread safe scope. It should not be called in
     * an interrupt context. The value 0xFFFF and 0x0 cannot be
     * a unique key. */
    
    if((hDriver->uniqueKey == 0xFFFF) || (hDriver->uniqueKey == 0x0))
    {
        hDriver->uniqueKey = 1;
    }
    else
    {
        hDriver->uniqueKey ++;
    }
    
    return(hDriver->uniqueKey);
}

// *****************************************************************************
/* Function:
    size_t _DRV_USB_EHCI_QTDBufferPointerSetup
    (
        USB_EHCI_QTD * transfer,
        uint8_t * transferBuffer,
        size_t nBytes
    )

  Summary:
    Sets up the qTD buffer pointers and returns the number of bytes to be
    transferred.
    
  Description:
    Sets up the qTD buffer pointers and returns the number of bytes to be
    transferred. 

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/

size_t _DRV_USB_EHCI_QTDBufferPointerSetup
(
    USB_EHCI_QTD * qTD,
    uint8_t * transferBuffer,
    size_t nBytes
)
{
    uint32_t startAddress = (uint32_t)(transferBuffer);
    uint32_t endAddress = 0;
    uint32_t pageBoundary = 0;
    uint32_t nPages = 0;
    int i = 0;

    nBytes = (nBytes > DRV_USB_EHCI_MAX_QTD_NBYTES) ? DRV_USB_EHCI_MAX_QTD_NBYTES : nBytes;
    endAddress = startAddress + nBytes;

    /* This function loads the Buffer pointer in the qTD */
    qTD->bufferPointer[0] = (uint32_t)(transferBuffer);

    /* Shifting by 12 bits gets us the 4096 page address. Finding the difference
     * between the start and end address should give us the total number of
     * pages. */
    nPages = (endAddress >> 12) - (startAddress >> 12);
    pageBoundary = startAddress >> 12;
    for(i = 0; ((i < nPages) && (i < 4)); i ++)
    {
        pageBoundary ++;
        qTD->bufferPointer[1 + i] = (pageBoundary << 12);
    }

    return nBytes;
}

// *****************************************************************************
/* Function:
    size_t _DRV_USB_EHCI_ControlTransferQTD
    (
        DRV_USB_EHCI_CONTROL_TRANSFER_QTD * transfer
        USB_SPEED speed
    )

  Summary:
    Sets up the setup, data and handshake stage QTDs of the control transfer.
    
  Description:
    Sets up the setup, data and handshake stage QTDs of the control transfer.

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/

size_t _DRV_USB_EHCI_ControlTransferQTD
(
    DRV_USB_EHCI_CONTROL_TRANSFER_QTD * transfer,
    USB_SPEED speed
)
{
    /* Get pointers to the QTDs */
    USB_EHCI_QTD * setupQTD = &transfer->setupQTD;
    USB_EHCI_QTD * dataQTD = &transfer->dataQTD;
    USB_EHCI_QTD * handshakeQTD = &transfer->handshakeQTD;
    USB_HOST_IRP_LOCAL * irp = transfer->irp;
    USB_DATA_DIRECTION direction = USB_DATA_DIRECTION_DEVICE_TO_HOST;
    size_t nBytes = 0;

    /* Get the direction of the control transfer */
    direction = ((((uint8_t*)irp->setup)[0] & 0x80) == 0) ? USB_DATA_DIRECTION_HOST_TO_DEVICE: direction; 
    
    /* Clear up the QTDs */
    memset(setupQTD, 0, sizeof(USB_EHCI_QTD));
    memset(dataQTD, 0, sizeof(USB_EHCI_QTD));
    memset(handshakeQTD, 0, sizeof(USB_EHCI_QTD));

    /* Transfer data from user to driver buffer */
    memcpy(transfer->setupBuffer, irp->setup, 8);
        
    /* Prepare the setup QTD */
    setupQTD->altNextQtd.terminate = 1;
    setupQTD->qTDToken.bytesToTransfer = _DRV_USB_EHCI_QTDBufferPointerSetup(setupQTD, transfer->setupBuffer, 8);
    setupQTD->qTDToken.ioc = 0;
    setupQTD->qTDToken.dt = 0;
    setupQTD->qTDToken.cErr = 3;
    setupQTD->qTDToken.pid = USB_EHCI_TOKEN_TYPE_SETUP;
    setupQTD->qTDToken.active = 1;

    if((irp->data != NULL) && (irp->size != 0))
    {
        /* If data is moving from device to host, then use the alternate QTD to
         * move to handshake stage in case of short packet */
        dataQTD->qTDToken.pid = USB_EHCI_TOKEN_TYPE_IN;
        dataQTD->altNextQtd.pointer = handshakeQTD;
        dataQTD->nextQtd.pointer = handshakeQTD;
        
        /* Cap the buffer size if required. */ 
        nBytes = (irp->size > DRV_USB_EHCI_CONTROL_TRANSFER_BUFFER_SIZE) ?  DRV_USB_EHCI_CONTROL_TRANSFER_BUFFER_SIZE : irp->size;

        /* This means a data stage is required */
        if(direction == USB_DATA_DIRECTION_HOST_TO_DEVICE) 
        {
            /* If data is moving from host to device, then copy it to the transfer
             * buffer. No alternate QTD in case of
             * OUT direction. */
           
            memcpy(transfer->dataBuffer, irp->data, nBytes);
            dataQTD->qTDToken.pid = USB_EHCI_TOKEN_TYPE_OUT;
            dataQTD->altNextQtd.terminate = 1;
        }

        dataQTD->qTDToken.bytesToTransfer = _DRV_USB_EHCI_QTDBufferPointerSetup(dataQTD, transfer->dataBuffer, nBytes);
        dataQTD->qTDToken.ioc = 0;
        dataQTD->qTDToken.dt = 1;
        dataQTD->qTDToken.cErr = 3;
        dataQTD->qTDToken.active = 1;
        setupQTD->nextQtd.pointer = dataQTD;
    }
    else
    {
        /* If there is no data stage, then move from setup to handshake */
        setupQTD->nextQtd.pointer = handshakeQTD;
    }

    handshakeQTD->nextQtd.terminate = 1;
    handshakeQTD->altNextQtd.terminate = 1;
    handshakeQTD->qTDToken.ioc = 1;
    handshakeQTD->qTDToken.dt = 1;
    handshakeQTD->qTDToken.cErr = 3;

    /* Data stage is not needed */
    handshakeQTD->qTDToken.bytesToTransfer = 0;
    handshakeQTD->qTDToken.pid = USB_EHCI_TOKEN_TYPE_OUT;

    /* Check the transfer direction */
    if(direction == USB_DATA_DIRECTION_HOST_TO_DEVICE)
    {
        /* Data moves host to device. So handshake
         * moves from device to host. */
        handshakeQTD->qTDToken.pid = USB_EHCI_TOKEN_TYPE_IN;
    }
    
    handshakeQTD->qTDToken.active = 1;

    return(nBytes); 
}

// *****************************************************************************
/* Function:
    void _DRV_USB_EHCI_PortsTask(DRV_USB_EHCI_OBJ * hDriver)

  Summary:
    This function checks each for status change and handles these changes.
    
  Description:
    This function checks each for status change and handles these changes. The
    function is called from the driver tasks routine.

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/

void _DRV_USB_EHCI_PortsTask(DRV_USB_EHCI_OBJ * hDriver)
{
    /* This function checks the status of ports registers */

    uhphs_registers_t * usbID = hDriver->usbID;
    DRV_USB_EHCI_PORT_OBJ * port = NULL;
    volatile uint32_t * portSC = NULL;
    int i = 0;

    portSC = (volatile uint32_t *)((uint32_t)usbID + UHPHS_PORTSC_REG);
    
    /* This routine maintains the states of each port */
    for (i = 0; i < DRV_USB_EHCI_PORT_NUMBERS; i ++)
    {
        port = &hDriver->ports[i];

        if(port->selected)
        {
            /* Port needs to be processed */

            switch(port->portAttachState)
            {
                case DRV_USB_EHCI_PORT_ATTACH_STATE_WAITING_FOR_ATTACH:
                    
                    /* Check if we have attach. The interruptHasOccurred flag
                     * allows the state machine to synchronize with the
                     * interrupt. */

                    if ((port->interruptHasOccurred) && ((portSC[i] & UHPHS_PORTSC_N_CSC_Msk) != 0)
                        && ((portSC[i] & UHPHS_PORTSC_N_CCS_Msk) != 0))
                    {
                        /* This means that an device attach interrupt has
                         * occurred. The port change interrupt is presently
                         * disabled. We will enable it after completing the
                         * device reset. We clear the change status bit so that
                         * the port can continue to track changes. */

                        port->interruptHasOccurred = false;
                        port->portAttachState = DRV_USB_EHCI_PORT_ATTACH_STATE_START_ATTACH_DEBOUNCE;
                        portSC[i] |= UHPHS_PORTSC_N_CSC_Msk;
                    }
                    break;

                case DRV_USB_EHCI_PORT_ATTACH_STATE_START_ATTACH_DEBOUNCE:

                    /* Start the debounce timer. If the debounce timer fails we
                     * try again. */
                    if((SYS_TIME_DelayMS(DRV_USB_EHCI_ATTACH_DEBOUNCE_DURATION,  &port->timerHandle)) == SYS_TIME_SUCCESS)
                    {
                        port->portAttachState = DRV_USB_EHCI_PORT_ATTACH_STATE_START_WAIT_DEBOUNCE;
                    }
                    break;

                case DRV_USB_EHCI_PORT_ATTACH_STATE_START_WAIT_DEBOUNCE:

                    /* Check if the debounce has completed */
                    if(SYS_TIME_DelayIsComplete(port->timerHandle))
                    {
                        /* Debounce timer done. Check if the device is still
                         * connected. */
                        
                        port->timerHandle = SYS_TIME_HANDLE_INVALID;

                        if(portSC[i] & UHPHS_PORTSC_N_CCS_Msk)
                        {
                            /* Device is still connected. Check the line state */
                            if(((portSC[i] & UHPHS_PORTSC_N_LS_Msk) >> UHPHS_PORTSC_N_LS_Pos) == USB_EHCI_QH_SPEED_LOW)
                            {
                                /* We cannot handle low speed device in EHCI.
                                 * Handover this device to the companion
                                 * controller. Set the port owner bit and this
                                 * changes the port owner. Refer to section
                                 * 4.2.2 of the specification for details. */
                                if(hDriver->companionDriverIndex != (SYS_MODULE_INDEX)(-1))
                                {
                                    port->portAttachState = DRV_USB_EHCI_PORT_ATTACH_STATE_OHCI_HANDOVER;
                                    usbID->UHPHS_USBINTR |= (UHPHS_USBINTR_PCIE_Msk);
                                }
                                else
                                {
                                    /* If the companion driver index is -1, this indicates
                                     * there is no companion driver in the project. We should
                                     * go to a state where this the device must be detached and
                                     * we will wait for attach. */
                                    port->portAttachState = DRV_USB_EHCI_PORT_ATTACH_STATE_WAITING_FOR_ATTACH;
                                }
                            }
                            else
                            {
                                port->portAttachState = DRV_USB_EHCI_PORT_ATTACH_STATE_START_RESET;
                            }
                        }
                        else
                        {
                            /* Device is not connected. Reset the state and
                             * reenable the Port change detect interrupt.  */
                            port->portAttachState = DRV_USB_EHCI_PORT_ATTACH_STATE_WAITING_FOR_ATTACH;
                            usbID->UHPHS_USBINTR |= (UHPHS_USBINTR_PCIE_Msk);
                        }
                    }

                    break;

                case DRV_USB_EHCI_PORT_ATTACH_STATE_START_RESET:
                   
                   /* Perform a port reset to check if this device supports high
                    * speed operation */

                    if((SYS_TIME_DelayMS(DRV_USB_EHCI_RESET_DURATION, &port->timerHandle)) == SYS_TIME_SUCCESS)
                    {
                        portSC[i] |= UHPHS_PORTSC_N_PR_Msk;
                        port->portAttachState = DRV_USB_EHCI_PORT_ATTACH_STATE_WAIT_RESET;
                    }

                    break;

                case DRV_USB_EHCI_PORT_ATTACH_STATE_WAIT_RESET:

                    if(SYS_TIME_DelayIsComplete(port->timerHandle))
                    {
                        /* Reset duration is complete. Release the reset */
                        portSC[i] &= (~UHPHS_PORTSC_N_PR_Msk);

                        /* Now check if the port is enabled */
                        port->portAttachState = DRV_USB_EHCI_PORT_ATTACH_STATE_WAIT_PORT_ENABLE;
                    }

                    break;

                case DRV_USB_EHCI_PORT_ATTACH_STATE_WAIT_PORT_ENABLE:

                    /* Here we wait for the port reset bit to read 0 and then
                     * check if the port enable bit is set. */
                    if((portSC[i] & UHPHS_PORTSC_N_PR_Msk) == 0)
                    {
                        /* Reset bit is clear. If the port is enabled, then this
                         * is a high speed device */
                        if((portSC[i] & UHPHS_PORTSC_N_PED_Msk) != 0)
                        {
                            /* Port is enabled. We can enumerate the device with
                             * the EHCI controller. */
                            port->portAttachState = DRV_USB_EHCI_PORT_ATTACH_STATE_WAIT_FOR_DETACH;

                            /* We can reach this point from two flows. One is
                             * when a device has been just attached and other
                             * is when a port reset was requested. If the
                             * device was attached, then the
                             * attachedDeviceObjHandle will be invalid and
                             * hence the device needs to enumerated. If a port
                             * reset was requested, the the
                             * attachedDeviceObjHandle will not be invalid and
                             * hence the device should not be enumerated.*/
                            if(port->attachedDeviceObjHandle == USB_HOST_DEVICE_OBJ_HANDLE_INVALID)
                            {
                                port->attachedDeviceObjHandle = USB_HOST_DeviceEnumerate(hDriver->usbHostDeviceInfo, i);
                            }
                            
                            port->isResetting = false;
                        }
                        else
                        {
                            /* This is a full speed device. Release ownership of
                             * the device. */
                            if(hDriver->companionDriverIndex != (SYS_MODULE_INDEX)(-1))
                            {
                                port->portAttachState = DRV_USB_EHCI_PORT_ATTACH_STATE_OHCI_HANDOVER;
                            }
                            else
                            {
                                /* If there are no OHCI drivers, then just wait for the device to be
                                 * detached and wait for the next attach */
                                port->portAttachState = DRV_USB_EHCI_PORT_ATTACH_STATE_WAITING_FOR_ATTACH;
                            }
                        }

                        /* We are now ready to handle other port change
                         * interrupts */
                        usbID->UHPHS_USBINTR |= (UHPHS_USBINTR_PCIE_Msk);
                    }

                    break;

                case DRV_USB_EHCI_PORT_ATTACH_STATE_OHCI_HANDOVER:

                    if(DRV_USB_OHCI_IsCompanionControllerReady(hDriver->companionDriverIndex))
                    {
                        port->portAttachState = DRV_USB_EHCI_PORT_ATTACH_STATE_WAITING_FOR_ATTACH;
                        portSC[i] |= UHPHS_PORTSC_N_PO_Msk;
                        
                    }
                    break;


                case DRV_USB_EHCI_PORT_ATTACH_STATE_WAIT_FOR_DETACH:

                    /* In this state we wait for detach */
                    if(port->interruptHasOccurred && ((portSC[i] & UHPHS_PORTSC_N_CCS_Msk) == 0))
                    {
                       /* We have a device disconnect. Reset the state machine
                        * to wait for the device attach.  */

                        port->interruptHasOccurred = false;
                        port->portAttachState = DRV_USB_EHCI_PORT_ATTACH_STATE_WAITING_FOR_ATTACH;
                        usbID->UHPHS_USBINTR |= (UHPHS_USBINTR_PCIE_Msk);
                    } 
                    else
                    {
                        if(port->isResetting)
                        {
                            /* This means a port reset has been requested. Move
                             * the port attach state back port reset */
                            usbID->UHPHS_USBINTR &= (~UHPHS_USBINTR_PCIE_Msk);
                            port->portAttachState = DRV_USB_EHCI_PORT_ATTACH_STATE_START_RESET;
                        }
                    }

                    break;
                default:
                    break;
            }
        }
    }
}

// *****************************************************************************
/* Function:
    bool _DRV_USB_EHCI_CheckQHForError
    (
        USB_EHCI_QH * qH, 
        USB_HOST_IRP_STATUS * status
    )

  Summary:
    This function will check if there were errors in the qH.
    
  Description:
    This function will check if there were errors in the qH. It will return
    true if errors were found. The status return parameter will contain the IRP
    status to be used.

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/

bool _DRV_USB_EHCI_CheckQHForError
(
    USB_EHCI_QH * qH, 
    USB_HOST_IRP_STATUS * status
)
{
    bool returnValue = false;

    if(qH->qTDToken.halted == 1)
    {
        if((qH->qTDToken.cErr == 0) || (qH->qTDToken.babble == 1))
        {
            /* An error has occurred on the bus */
            *status = USB_HOST_IRP_STATUS_ERROR_DATA; 
        }
        else
        {
            /* This token was stalled */
            *status = USB_HOST_IRP_STATUS_ERROR_STALL;
        }

        returnValue = true;
    }

    return(returnValue);
}

// *****************************************************************************
/* Function:
    bool _DRV_USB_EHCI_CheckQTDForError
    (
        USB_EHCI_QTD * qTD, 
        USB_HOST_IRP_STATUS * status
    );

  Summary:
    This function will check if there were errors in the qTD.
    
  Description:
    This function will check if there were errors in the qTD. It will return
    true if errors were found. The status return parameter will contain the IRP
    status to be used.

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/

bool _DRV_USB_EHCI_CheckQTDForError
(
    USB_EHCI_QTD * qTD, 
    USB_HOST_IRP_STATUS * status
)
{
    bool returnValue = false;

    if(qTD->qTDToken.halted == 1)
    {
        if((qTD->qTDToken.cErr == 0) || (qTD->qTDToken.babble == 1))
        {
            /* An error has occurred on the bus */
            *status = USB_HOST_IRP_STATUS_ERROR_DATA; 
        }
        else
        {
            /* This token was stalled */
            *status = USB_HOST_IRP_STATUS_ERROR_STALL;
        }

        returnValue = true;
    }

    return(returnValue);
}

// *****************************************************************************
/* Function:
    size_t _DRV_USB_EHCI_DataQTD
    (
        DRV_USB_EHCI_QTD * transfer,
        USB_DATA_DIRECTION direction
    )

  Summary:
    Prepares a data qTD.
    
  Description:
    Prepares a data qTD. The direction flag is the data stage direction. Returns
    the actual amount of data scheduled. 

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/

size_t _DRV_USB_EHCI_DataQTD
(
    DRV_USB_EHCI_QTD * transfer,
    USB_DATA_DIRECTION direction
)
{ 
    USB_EHCI_QTD * qTD = &transfer->qTD;
    USB_HOST_IRP_LOCAL * irp = transfer->irp;

    memset(qTD, 0, sizeof(USB_EHCI_QTD));
    qTD->nextQtd.terminate = 1;
    qTD->altNextQtd.terminate = 1;
    qTD->qTDToken.ioc = 1;
    qTD->qTDToken.dt = 0;
    qTD->qTDToken.cErr = 3;

    qTD->qTDToken.bytesToTransfer = _DRV_USB_EHCI_QTDBufferPointerSetup(qTD, transfer->transferBuffer, (irp->size - irp->completedBytes));
        
    /* Check the transfer direction */
    if(direction == USB_DATA_DIRECTION_DEVICE_TO_HOST)
    {
        qTD->qTDToken.pid = USB_EHCI_TOKEN_TYPE_IN;
    }
    else
    {
        qTD->qTDToken.pid = USB_EHCI_TOKEN_TYPE_OUT;
        memcpy(transfer->transferBuffer, ((uint8_t *)(irp->data) + irp->completedBytes), qTD->qTDToken.bytesToTransfer); 
    }

    qTD->qTDToken.active = 1;
    return(qTD->qTDToken.bytesToTransfer);
}

// *****************************************************************************
/* Function:
    void _DRV_USB_EHCI_BulkTransferProcess(DRV_USB_EHCI_OBJ * hDriver)

  Summary:
    This function processes Bulk transfers.
    
  Description:
    This function processes Bulk transfers. It should be called when an
    interrupt has occurred.

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/

void _DRV_USB_EHCI_BulkTransferProcess(void * hPipe)
{

    /* This function is called when a transaction or transfer interrupt has
     * occurred. The function will specifically process Bulk transfers. It will
     * check if the IRP associated with the qTD has completed and will retired
     * the IRP if required.*/

    DRV_USB_EHCI_QH * pipe = (DRV_USB_EHCI_QH *)hPipe;
    DRV_USB_EHCI_QTD * transfer = NULL;
    USB_HOST_IRP_LOCAL * irp = NULL;
    bool endIRP = false;
    USB_EHCI_QTD * qTD = NULL;
    bool pipeWasEmpty = false;

    if(pipe->inUse)
    {
        /* Get the transfer at the head of the queue */
        transfer = pipe->currentQTD;

        qTD = &transfer->qTD;
        irp = transfer->irp;

        if(irp->tempState == DRV_USB_EHCI_IRP_STATE_ABORTED)
        {
            /* This means that an abort was requested on the IRP */
            irp->status = USB_HOST_IRP_STATUS_ABORTED;
            endIRP = true;
        }
        else
        {
            if(_DRV_USB_EHCI_CheckQTDForError(qTD, &irp->status) == true)
            {
                /* There was an error while executing this qTD.  We must end the
                 * IRP. Clear the halted bit on the pipe. */
                pipe->qH.qTDToken.halted = 0;
                endIRP = true;
            }
            else
            {
                if(pipe->direction == USB_DATA_DIRECTION_DEVICE_TO_HOST)
                {
                    /* If we have received data from the device, this needs to
                     * copied from the transfer buffer to the application
                     * buffer. */
                    memcpy(((uint8_t *)irp->data + irp->completedBytes), transfer->transferBuffer, (irp->scheduledBytes - qTD->qTDToken.bytesToTransfer));
                }

                /* Update the complete byte count */
                irp->completedBytes += (irp->scheduledBytes - qTD->qTDToken.bytesToTransfer);

                if(irp->completedBytes >= irp->size)
                {
                    /* This means that required amount of data was transferred.
                     * We can end the transfer.  */
                    irp->status = USB_HOST_IRP_STATUS_COMPLETED;
                    endIRP = true;
                }
                else
                {
                    /* Requested transfer amount is less  than the completed
                     * amount. This can happen under two cases. Either we need
                     * to continue sending more data or we received a short
                     * packet. */

                    if(qTD->qTDToken.bytesToTransfer == 0)
                    {
                        /* This means we have more data to send Form the qTD and
                         * add it to the pipe */

                        irp->scheduledBytes = _DRV_USB_EHCI_DataQTD(transfer, (USB_DATA_DIRECTION)pipe->direction);
                        pipe->qH.nextQTD.pointer = qTD; 
                    }
                    else if ((pipe->direction == USB_DATA_DIRECTION_DEVICE_TO_HOST) && 
                            (irp->scheduledBytes > qTD->qTDToken.bytesToTransfer))
                    {
                        /* This means we got less data than we asked for, which
                         * means we have received a short packet. This situation
                         * can only occur when data is moving from device to
                         * host. This means we should end the transfer. */
                        irp->status = USB_HOST_IRP_STATUS_COMPLETED_SHORT;
                        endIRP = true;
                    }
                }
            }
        }

        /* Check if the IRP has to be completed. */
        if(endIRP)
        {
            /* Get to the next transfer in the queue */
            pipe->currentQTD = irp->next;

            /* We need to remember if the pipe was empty before the IRP
             * callback */
            if(pipe->currentQTD == NULL)
            {
                pipeWasEmpty = true;
            }

            /* Update the size field with the actual amount of data transferred.
             * */
            irp->size = irp->completedBytes;

            /* Perform the IRP callback */
            if(irp->callback != NULL)
            {
                irp->callback((USB_HOST_IRP *)irp);
            }

            /* Release the transfer object */
            transfer->inUse = false;

            if(!pipeWasEmpty)
            {
                /* If the pipe was not empty before the IRP callback, then we
                 * know that any IRP submitted in the IRP callback will be at
                 * the tail of last IRP in the queue. We will need to process
                 * the current queue. */

                transfer = pipe->currentQTD;
                irp = transfer->irp;
                irp->status = USB_HOST_IRP_STATUS_IN_PROGRESS;
                irp->scheduledBytes = _DRV_USB_EHCI_DataQTD(transfer, (USB_DATA_DIRECTION)pipe->direction);
                irp->tempState = DRV_USB_EHCI_IRP_STATE_IDLE;
                pipe->qH.nextQTD.pointer = &transfer->qTD;
            }
            else
            {
                /* Pipe was empty prior to IRP callback. If there was any
                 * IRP submitted in the IRP callback function, the IRPSubmit
                 * function would have detected the empty queue and would have
                 * triggered the IRP. So we do not have to do anything. */
            }
        }
    }
}

// *****************************************************************************
/* Function:
    void _DRV_USB_EHCI_ControlTransferProcess
    (
        DRV_USB_EHCI_QH * transfer
    )

  Summary:
    This function processes control transfers.
    
  Description:
    This function processes control transfers. It should be called when an
    interrupt has occurred.

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/

void _DRV_USB_EHCI_ControlTransferProcess(void * pPipe)
{
    /* This function is called when a transaction or transfer interrupt has
     * occurred. The function will specifically process control transfers. It
     * will advance the state of the control transfer. If control transfer has
     * completed, the IRP will be retired. */

    DRV_USB_EHCI_QH * pipe = (DRV_USB_EHCI_QH *)pPipe;
    DRV_USB_EHCI_CONTROL_TRANSFER_QTD * transfer = NULL;
    USB_HOST_IRP_LOCAL * irp = NULL;
    USB_DATA_DIRECTION direction = USB_DATA_DIRECTION_HOST_TO_DEVICE;
    bool pipeWasEmpty = false;

    if(pipe->inUse)
    {

        /* Get the transfer at the head of the queue */
        transfer = (DRV_USB_EHCI_CONTROL_TRANSFER_QTD *)pipe->currentQTD;

        /* The pipe head can be NULL if this interrupt occurred after the pipe was closed */
        if(transfer != NULL)
        {
            /* This function is called only if the qH is not active any more. 
             * This means that qTD has completed. This a control transfer.
             * Get the current state of the control transfer.  */
            irp = transfer->irp;
            direction = ((((uint8_t *)(irp->setup))[0] & 0x80) == 0x80) ? USB_DATA_DIRECTION_DEVICE_TO_HOST: USB_DATA_DIRECTION_HOST_TO_DEVICE;

            if(irp->tempState == DRV_USB_EHCI_IRP_STATE_ABORTED)
            {

                /* This means the application has cancelled this IRP. We
                 * simply end the IRP */
                irp->status = USB_HOST_IRP_STATUS_ABORTED;
            }
            else
            {
                /* This means that the setup token was sent. Check if there
                 * was any error. We can check the halted bit */
                if(_DRV_USB_EHCI_CheckQHForError(&pipe->qH, &irp->status) == 0)
                { 
                    if (irp->size > 0)
                    {
                        if(direction == USB_DATA_DIRECTION_DEVICE_TO_HOST)
                        {
                            /* Data received from the device is in the transfer
                             * buffer. Copy this to the user buffer. */
                            memcpy(((uint8_t *)irp->data + irp->completedBytes), transfer->dataBuffer, (irp->scheduledBytes - transfer->dataQTD.qTDToken.bytesToTransfer));
                        }

                        /* Update the complete byte count */
                        irp->completedBytes += (irp->scheduledBytes - transfer->dataQTD.qTDToken.bytesToTransfer);
                    }

                    /* Update the completion status of the IRP */
                    irp->status = USB_HOST_IRP_STATUS_COMPLETED;
                    irp->tempState = DRV_USB_EHCI_IRP_STATE_COMPLETE;

                    if((direction == USB_DATA_DIRECTION_DEVICE_TO_HOST) && (irp->size > irp->completedBytes))
                    {
                        /* This means this was a short packet */
                        irp->status = USB_HOST_IRP_STATUS_COMPLETED_SHORT;
                    }
                }
                else
                {
                    /* There was an error.*/
                    pipe->qH.qTDToken.flags = 0;

                }
            }

            /* Get to the next transfer in the queue */
            pipe->currentQTD = irp->next;

            if(pipe->currentQTD == NULL)
            {
                pipeWasEmpty = true;
            }

            /* Update the size field with the actual amount of data
             * transferred. */
            irp->size = irp->completedBytes;

            /* Perform the IRP callback */
            if(irp->callback != NULL)
            {
                irp->callback((USB_HOST_IRP *)irp);
            }

            /* Release the transfer object */
            transfer->inUse = false;

            if(!pipeWasEmpty)
            {
                /* This means we have transfer in the queue. Submit the
                 * Setup stage QTD. */
                transfer = (DRV_USB_EHCI_CONTROL_TRANSFER_QTD *)pipe->currentQTD;
                irp = transfer->irp;
                irp->status = USB_HOST_IRP_STATUS_IN_PROGRESS;
                irp->scheduledBytes = _DRV_USB_EHCI_ControlTransferQTD(transfer, (USB_SPEED)pipe->speed);
                pipe->qH.nextQTD.pointer = &transfer->setupQTD;
            }
        }
    }
}

// *****************************************************************************
/* Function:
    void _DRV_USB_EHCI_PeriodicListRemove
    (
        DRV_USB_EHCI_OBJ * hDriver,
        int slotindex,
        DRV_USB_EHCI_QH * pipe
    )

  Summary:
    This function removes a pipe from the a periodic list slot
   
  Description:
    This function removes a pipe from the a periodic list slot
  
  Remarks:
    This is a local function and should not be called directly by the 
    application.
*/

void _DRV_USB_EHCI_PeriodicListRemove
(
    DRV_USB_EHCI_OBJ * hDriver,
    int slotindex,
    DRV_USB_EHCI_QH * pipe
)
{
    USB_EHCI_QH * currentQH = NULL;
  
    if(hDriver->periodicList[slotindex] != USB_EHCI_END_OF_LIST)
    {
        if(hDriver->periodicList[slotindex] == USB_EHCI_PERIODIC_LIST_ENTRY(pipe, USB_EHCI_QH_TYPE_QH))
        {
            /* This qH is at the start of the list */
            hDriver->periodicList[slotindex] = pipe->qH.horizontalQH.value32;
        }
        else
        {
            /* The qH is not at the start of the list. Traverse the list */
            currentQH = USB_EHCI_PERIODIC_LIST_QH(hDriver->periodicList[slotindex]);
            while(1)
            {
                if(currentQH->horizontalQH.value32 == USB_EHCI_END_OF_LIST)
                {
                    /* End of list reached. */
                    break;
                }
                else
                {
                    if(currentQH->horizontalQH.value32 == USB_EHCI_PERIODIC_LIST_ENTRY(pipe, USB_EHCI_QH_TYPE_QH))
                    {
                        /* We found the position in the list from the pipe should be removed.
                         * currentQH horizontal pointer is pointing to this pipe. We should
                         * update this pointer. */
                        currentQH->horizontalQH.value32 = pipe->qH.horizontalQH.value32;
                        break;
                    }
                }
            }
        }
    }
}

// *****************************************************************************
/* Function:
    void _DRV_USB_EHCI_PipeCloseTask(DRV_USB_EHCI_OBJ * hDriver);

  Summary:
    This function handles pipe closures. 
   
  Description:
    This function handles pipe closures. It is called from the main driver task 
    routine.
  
  Remarks:
    This is a local function and should not be called directly by the 
    application.
*/

void _DRV_USB_EHCI_PipeCloseTask(DRV_USB_EHCI_OBJ * hDriver)
{
    DRV_USB_EHCI_QH * pipe;
    uhphs_registers_t * usbID = hDriver->usbID;
    USB_EHCI_QH * pQHeadNext = NULL;
    USB_EHCI_QH * pQHeadPrevious = NULL;
    int pollingRate = 0;
    int i = 0;
    int j = 0;

    pipe = hDriver->queueHeads;
    for(i = 0; i < USB_HOST_PIPES_NUMBER; i ++)
    {
        if(pipe->inUse)
        {
            switch(pipe->pipeClosingState)
            {
                case DRV_USB_EHCI_PIPE_CLOSE_IDLE:
                    
                    /* Nothing to do here */
                    break;

                case DRV_USB_EHCI_PIPE_CLOSE_REQUEST_PENDING:

                    /* Pipe closure has been requested. Check if another pipe 
                     * is already closing. If no, then we can continue closing
                     * the pipe else we will have to wait. */
                    if(hDriver->pipeIsClosing == false)
                    {
                        /* This means we can proceed with closing the pipe */
                       hDriver->pipeIsClosing = true;
                       pipe->pipeClosingState = DRV_USB_EHCI_PIPE_CLOSE_QHEAD_DEACTIVATE_WAIT; 
                    }

                    break;

                case DRV_USB_EHCI_PIPE_CLOSE_QHEAD_DEACTIVATE_WAIT:

                    /* In this state check if the qhead active bit has cleared
                     * */
                    if(pipe->qH.qTDToken.active == 0)
                    {
                        /* qhead is deactivated. Proceed to remove queue head */
                        pipe->pipeClosingState = DRV_USB_EHCI_PIPE_CLOSE_REMOVE_QHEAD;
                    }

                    break;

                case DRV_USB_EHCI_PIPE_CLOSE_REMOVE_QHEAD:

                    if(pipe->pipeType == USB_TRANSFER_TYPE_INTERRUPT)
                    {
                        /* Check if this is a 1 millisecond interval pipe. Then
                         * we must always start from slot 0 */
                        pollingRate = _DRV_USB_EHCI_POLLING_RATE(pipe->bInterval);
                        if(pollingRate == 1)
                        {
                            for(j = 0; j < DRV_USB_EHCI_PERIODIC_LIST_SIZE; j ++)
                            {
                                _DRV_USB_EHCI_PeriodicListRemove(hDriver, j, pipe);
                            }

                            /* As we are modifying the hDriver object from one thread
                             * and the pipe open function can be called from another
                             * thread, we must ensure that the below access is atomic */
                            if(OSAL_MUTEX_Lock(&hDriver->mutex, OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
                            {
                                /* Decrement the polling rate 1 count */
                                if(hDriver->nextSlotToUse[pipe->bInterval] != 0)
                                {
                                    hDriver->nextSlotToUse[pipe->bInterval] --;
                                }
                             
                                /* Decrement the micro frame usage count */
                                hDriver->microFrameUsage[pipe->microFrameIndex] --;
                                OSAL_MUTEX_Unlock(&hDriver->mutex);
                            }
                            else
                            {
                                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Could not grab mutex in EHCI Pipe Close Task");
                            }
                        }
                        else
                        {
                            /* In a case where this is not a 1 millisecond polling rate pipe, the
                             * starting slot where the pipe was inserted is where we should 
                             * start looking from */
                            for(j = pipe->startSlot; j < DRV_USB_EHCI_PERIODIC_LIST_SIZE; j += pollingRate)
                            {
                                _DRV_USB_EHCI_PeriodicListRemove(hDriver, j, pipe);
                            }
                           
                            if(OSAL_MUTEX_Lock(&hDriver->mutex, OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
                            {
                                /* We do not change the nextSlotToUse counts for these intervals.
                                 * These counts will increment and then roll over to 0 */

                                /* Decrement the micro frame usage count */
                                hDriver->microFrameUsage[pipe->microFrameIndex] --;
                                OSAL_MUTEX_Unlock(&hDriver->mutex);
                            }
                            else
                            {
                                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Could not grab mutex in EHCI driver Initialize");
                            }
                        }

                        /* Clear the Frame rollover interrupt and then wait for
                         * this interrupt before we release the pipe back  */
                        usbID->UHPHS_USBSTS = UHPHS_USBSTS_FLR_Msk;
                        pipe->pipeClosingState = DRV_USB_EHCI_PIPE_CLOSE_WAIT_FRAME_ROLLOVER;
                    }
                    else
                    {
                        /* For Async schedule, we will disable the schedule first */
                        usbID->UHPHS_USBCMD &= (~UHPHS_USBCMD_ASE_Msk);
                        pipe->pipeClosingState = DRV_USB_EHCI_PIPE_CLOSE_WAIT_ASYNC_DISABLE;
                    }
                    
                    break;

                case DRV_USB_EHCI_PIPE_CLOSE_WAIT_ASYNC_DISABLE:

                    if((usbID->UHPHS_USBCMD & UHPHS_USBCMD_ASE_Msk) == 0)
                    {
                        /* Async schedule is disabled. Remove the pipe from the schedule */

                        pQHeadNext = (USB_EHCI_QH *)((uint32_t)(pipe->qH.horizontalQH.pointer) & 0xFFFFFFE0);

                        /* To find the previous qHead, we start with this
                         * qhead and traverse the async schedule. Start with
                         * the next qH continue till we find a qH whose
                         * horizontal pointer points to this qH. */

                        pQHeadPrevious = (USB_EHCI_QH *)((uint32_t)(pipe->qH.horizontalQH.pointer) & 0xFFFFFFE0);
                        while((USB_EHCI_QH *)((uint32_t)pQHeadPrevious->horizontalQH.pointer & 0xFFFFFFE0) != &(pipe->qH))
                        {
                            pQHeadPrevious = (USB_EHCI_QH*)((uint32_t)pQHeadPrevious->horizontalQH.pointer & 0xFFFFFFE0);
                        }

                        /* Update the horizontal pointers. Set the Interrupt
                         * on Async. Advance Doorbell. */ 
                        pQHeadPrevious->horizontalQH.pointer = pipe->qH.horizontalQH.pointer;
                        pipe->qH.horizontalQH.pointer = pQHeadNext->horizontalQH.pointer;
                        usbID->UHPHS_USBCMD |= UHPHS_USBCMD_ASE_Msk;
                        pipe->pipeClosingState = DRV_USB_EHCI_PIPE_CLOSE_WAIT_ASYNC_ENABLE;
                    }

                    break;

                case DRV_USB_EHCI_PIPE_CLOSE_WAIT_FRAME_ROLLOVER:

                    if((usbID->UHPHS_USBSTS & UHPHS_USBSTS_FLR_Msk) != 0)
                    {
                        /* We have frame rollover. Release the pipe */
                        hDriver->pipeIsClosing = false;
                        pipe->pipeClosingState = DRV_USB_EHCI_PIPE_CLOSE_IDLE;
                        pipe->clientUniqueKey = 0xFFFF;
                        pipe->pipeInQueue = 0;
                        pipe->inUse = false;
                    }
                    break;

                case DRV_USB_EHCI_PIPE_CLOSE_WAIT_ASYNC_ENABLE:

                    /* Check if the Async Schedule has advanced. If so then we
                     * know that the pipe close is complete. */
                    if((usbID->UHPHS_USBSTS & UHPHS_USBSTS_ASS_Msk) != 0)
                    {
                        /* Async schedule is enabled. Pipe closing is complete.
                         * Release the pipe object and driver level flag */
                        hDriver->pipeIsClosing = false;
                        pipe->pipeClosingState = DRV_USB_EHCI_PIPE_CLOSE_IDLE;
                        pipe->clientUniqueKey = 0xFFFF;
                        pipe->pipeInQueue = 0;
                        pipe->inUse = false;
                    }

                    break;
                default:
                    break;
            }
        }
        
        pipe ++;
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: EHCI Driver Interface Implementations
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    SYS_MODULE_OBJ DRV_USB_EHCI_Initialize
    ( 
        const SYS_MODULE_INDEX index,
        const SYS_MODULE_INIT * const init
    )

  Summary:
    Initializes the USB Driver.
   
  Description:
    This function initializes the USB Driver, making it ready for clients to
    open. The driver initialization does not complete when this function
    returns. The DRV_USB_EHCI_Tasks function must called periodically to complete
    the driver initialization. The DRV_USB_EHCI_Open function will fail if the
    driver was not initialized or if initialization has not completed.
  
  Remarks:
    See drv_usb_ehci.h for usage information.
*/

SYS_MODULE_OBJ DRV_USB_EHCI_Initialize
(
    const SYS_MODULE_INDEX drvIndex,
    const SYS_MODULE_INIT * const init
)
{
    SYS_MODULE_OBJ returnValue = SYS_MODULE_OBJ_INVALID;
    DRV_USB_EHCI_OBJ * hDriver = NULL;
    DRV_USB_EHCI_INIT * drvInit = (DRV_USB_EHCI_INIT *)init;
    int i;

    if(drvIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBEHCIObj[drvIndex];

        if((!hDriver->inUse))
        {
            if(OSAL_MUTEX_Create(&hDriver->mutex) == OSAL_RESULT_TRUE)
            {
                /* Grab the driver instance and get the data from the init
                 * data structure. */

                hDriver->inUse = true;
                hDriver->uniqueKey = 0x0;
                hDriver->clientUniqueKey = 0xFFFF;
                hDriver->isOpened = false;
                hDriver->status = SYS_STATUS_BUSY;
                hDriver->usbHostDeviceInfo = USB_HOST_DEVICE_OBJ_HANDLE_INVALID;
                hDriver->inInterruptContext = false;
                hDriver->pipeIsClosing = false;

                hDriver->companionDriverIndex = drvInit->companionDriverIndex;
                
                /* Get data from the init data structure */
                hDriver->interruptSource = drvInit->interruptSource;
                hDriver->usbID = drvInit->usbID;
                hDriver->portPowerEnable = drvInit->portPowerEnable;
                hDriver->portIndication = drvInit->portIndication;
                hDriver->portOverCurrentDetect = drvInit->portOverCurrentDetect;
                hDriver->rootHubAvailableCurrent = drvInit->rootHubAvailableCurrent;
                
                /* Enable the module clock */
                PMC_UCKR_UPLLEN();

                /* Assign the frame list to this instance */
                hDriver->periodicList = &gDrvUSBEHCIPeriodicFrameList[drvIndex][0];
                hDriver->queueHeads = &gDrvUSBEHCIQueueHead[drvIndex][0];
                hDriver->queueTransferDescriptors = &gDrvUSBEHCIQueueTransferDescriptor[drvIndex][0];
                hDriver->controlTransferQTD = & gDrvUSBEHCIControlTransferQTD[drvIndex][0];

                /* Deallocate queue head and queue transfer descriptors */
                for(i = 0; i < USB_HOST_TRANSFERS_NUMBER; i ++)
                {
                    hDriver->queueTransferDescriptors[i].inUse = false;
                    hDriver->queueTransferDescriptors[i].transferBuffer = &gDrvUSBEHCITransferBuffer[drvIndex][i][0];
                    hDriver->controlTransferQTD[i].inUse = false;
                    hDriver->controlTransferQTD[i].dataBuffer = &gDrvUSBEHCIControlTransferBuffer[drvIndex][i][0];
                }

                for(i = 0; i < USB_HOST_PIPES_NUMBER; i ++)
                {
                    hDriver->queueHeads[i].inUse = false;
                    hDriver->queueHeads[i].clientUniqueKey = 0xFFFF;
                }

                /* Initialize the micro frame usage counter. This will be used
                 * for periodic transfers. */
                for(i = 0; i < 8; i ++)
                {
                    hDriver->microFrameUsage[i] = 0;
                }

                /* Set the next periodic lot to use for all bInterval to be slot 0 */
                for(i = 0; i < 16; i ++)
                {
                    hDriver->nextSlotToUse[i] = 0;
                }

                /* Check the port bit map and mark these ports
                 * as selected in the port data structures */
                for(i = 0; i < DRV_USB_EHCI_PORT_NUMBERS; i ++)
                {
                    hDriver->ports[i].attachedDeviceObjHandle = USB_HOST_DEVICE_OBJ_HANDLE_INVALID;
                    hDriver->ports[i].selected = false;
                    hDriver->ports[i].isResetting = false;
                    hDriver->ports[i].portAttachState = DRV_USB_EHCI_PORT_ATTACH_STATE_WAITING_FOR_ATTACH;
                    if(drvInit->bmPortSelect & (1 << i))
                    {
                        hDriver->ports[i].selected = true;
                    }

                    hDriver->ports[i].interruptHasOccurred = false;
                    hDriver->ports[i].timerHandle = SYS_TIME_HANDLE_INVALID;
                }

                /* Initialize the Async Schedule Head Queue Head. This simplifies
                 * head of reclamation management. This queue head will always
                 * be the head of reclamation. It is the last queue head in the
                 * gDrvUSBEHCIQueueHead array and will not be used by the
                 * application. */
                hDriver->asyncHeadQH = (USB_EHCI_QH *) &gDrvUSBEHCIQueueHead[drvIndex][USB_HOST_PIPES_NUMBER];
                memset(hDriver->asyncHeadQH, 0, sizeof(USB_EHCI_QH));
                hDriver->asyncHeadQH->horizontalQH.pointer = (USB_EHCI_QH *)(hDriver->asyncHeadQH);
                hDriver->asyncHeadQH->horizontalQH.type = USB_EHCI_QH_TYPE_QH;
                hDriver->asyncHeadQH->mult = 1;
                hDriver->asyncHeadQH->eps = USB_EHCI_QH_SPEED_HIGH;
                hDriver->asyncHeadQH->h = 1;
                hDriver->asyncHeadQH->nextQTD.terminate = 1;
                hDriver->asyncHeadQH->alternateNextQtd.terminate = 1;

                /* Configure the clock and setup the driver task to wait for the
                 * PLL Lock to complete. */
                hDriver->status = SYS_STATUS_READY;
                hDriver->taskState = DRV_USB_EHCI_TASK_STATE_RUNNING;
                hDriver->operationEnableState = DRV_USB_EHCI_OPERATION_ENABLE_DISABLE;
                returnValue = (SYS_MODULE_OBJ)drvIndex;
            }
            else
            {
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Could not create mutex in EHCI driver Initialize");
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: EHCI driver instance is in use");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid Instance in EHCI driver Initialize");
    }

    return(returnValue);
}

// *****************************************************************************
/* Function:
    void DRV_USB_EHCI_Deinitialize( const SYS_MODULE_OBJ object )

  Summary:
    This function deinitializes the USB EHCI driver instance. 

  Description:
    This function deinitializes the USB EHCI driver instance. 

  Remarks:
    A typical USB application may not to called this function.
*/

void DRV_USB_EHCI_Deinitialize
(
    const SYS_MODULE_OBJ object
)
{
    /* Deinitializing the module will cause all current transaction to stop.
     * This function will not delete pipes or cancel IRPs. This should be done
     * prior to deinitialize. */
    
    uint32_t driverIndex = (uint32_t)(object);
    uhphs_registers_t * usbID = NULL;
    DRV_USB_EHCI_OBJ * hDriver = NULL;

    if(driverIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBEHCIObj[driverIndex];

        if(hDriver->inUse)
        {
            usbID = hDriver->usbID;

            /* Disable the Async and Periodic schedule */
            usbID->UHPHS_USBCMD &= (~UHPHS_USBCMD_ASE_Msk);
            usbID->UHPHS_USBCMD &= (~UHPHS_USBCMD_PSE_Msk);

            while(((usbID->UHPHS_USBSTS & UHPHS_USBSTS_ASS_Msk) == UHPHS_USBSTS_ASS_Msk)
                    && ((usbID->UHPHS_USBSTS & UHPHS_USBSTS_PSS_Msk)) == UHPHS_USBSTS_PSS_Msk)
            {
                /* Wait till the schedules disable */
            }

            /* Stop the HC and wait the Halt status bit gets set */
            usbID->UHPHS_USBCMD &= (~UHPHS_USBCMD_RS_Msk);
            while((usbID->UHPHS_USBSTS & UHPHS_USBSTS_HCHLT_Msk) != UHPHS_USBSTS_HCHLT_Msk);

            /* Disable the interrupts and clear the interrupt flag */
            SYS_INT_SourceDisable(hDriver->interruptSource);

            /* Clear all the module interrupts */
            usbID->UHPHS_USBSTS = UHPHS_USBSTS_Msk;

            /* Finally clear the interrupt status flag and return the
             * hardware instance object */
            SYS_INT_SourceStatusClear(hDriver->interruptSource);
            hDriver->status = SYS_STATUS_UNINITIALIZED;
            hDriver->clientUniqueKey = 0xFFFF;
            hDriver->inUse = false;
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid instance in Deinitialize Function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid instance in Deinitialize Function");
    }
}

// *****************************************************************************
/* Function:
    SYS_STATUS DRV_USB_EHCI_Status( const SYS_MODULE_OBJ object )

  Summary:
    Provides the current status of the USB Driver module.

  Description:
    This function provides the current status of the USB Driver module.

  Remarks:
    See drv_usb_ehci.h for usage information.
*/

SYS_STATUS DRV_USB_EHCI_Status
(
    const SYS_MODULE_OBJ object
)
{
    SYS_STATUS returnValue = SYS_STATUS_UNINITIALIZED;
    uint32_t driverIndex = (uint32_t)(object);

    if(driverIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
    {
        if(gDrvUSBEHCIObj[driverIndex].inUse)
        {
            returnValue = gDrvUSBEHCIObj[driverIndex].status;
        }
    }

    return(returnValue);
}

// *****************************************************************************
/* Function:
    DRV_HANDLE DRV_USB_EHCI_Open
    (
        const SYS_MODULE_INDEX drvIndex,
        const DRV_IO_INTENT ioIntent 
    )

  Summary:
    Opens the specified USB Driver instance and returns a handle to it.
   
  Description:
    This function opens the specified USB Driver instance and provides a handle
    that must be provided to all other client-level operations to identify the
    caller and the instance of the driver. The intent flag is ignored.  Any
    other setting of the intent flag will return a invalid driver handle. A
    driver instance can only support one client. Trying to open a driver that
    has an existing client will result in an unsuccessful function call.

  Remarks:
    See drv_usb_ehci.h for usage information.
*/

DRV_HANDLE DRV_USB_EHCI_Open
(
    const SYS_MODULE_INDEX drvIndex,
    const DRV_IO_INTENT ioIntent
)
{
    DRV_HANDLE handle = DRV_HANDLE_INVALID;
    DRV_USB_EHCI_OBJ * hDriver = NULL;

    if(drvIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBEHCIObj[drvIndex];
        if((hDriver->inUse) && (hDriver->status == SYS_STATUS_READY))
        {
            if(!hDriver->isOpened)
            {
                if(OSAL_MUTEX_Lock(&hDriver->mutex, OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
                {
                    /* The driver is ready to opened. The driver handle is a combination
                     * of a unique key and the driver instance object index. Obtain the
                     * unique key. The upper 16 bits of the handle are the 16 bit 
                     * unique key and the lower 16 bits are the driver object instance 
                     * index. */

                    hDriver->clientUniqueKey = _DRV_USB_EHCI_GetUniqueKey(hDriver);
                    handle = (DRV_HANDLE)(((hDriver->uniqueKey << 16) & 0xFFFF0000) | (drvIndex & 0xFFFF));
                    hDriver->isOpened = true;
                    OSAL_MUTEX_Unlock(&hDriver->mutex);
                }
                else
                {
                    SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Mutex Lock failed in open function");
                }
            }
            else
            {
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Driver is already opened");
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Instance is not ready to be opened");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid instance in Open Function");
    }
    
    return(handle);
}

// *****************************************************************************
/* Function:
    void DRV_USB_EHCI_Close( DRV_HANDLE client )

  Summary:
    Closes an opened-instance of the  USB Driver.

  Description:
    This function closes an opened-instance of the  USB Driver, invalidating the
    handle.

  Remarks:
    See drv_usb_ehci.h for usage information.
*/

void DRV_USB_EHCI_Close
(
    DRV_HANDLE handle
)
{
    DRV_USB_EHCI_OBJ * hDriver = NULL;
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);

    if (drvIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBEHCIObj[drvIndex];
        if(hDriver->clientUniqueKey == clientUniqueKey)
        {
            /* Close the driver and invalidate the client unique key */
            hDriver->isOpened = false;
            hDriver->clientUniqueKey = 0xFFFF;
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid instance in Close Function");
    }
}

// *****************************************************************************
/* Function:
    void DRV_USB_EHCI_Tasks( SYS_MODULE_OBJ object )

  Summary:
    Maintains the driver's polled state machine.

  Description:
    Maintains the driver's polled state machine. This function should be called 
    from the system tasks routine.

  Remarks:
    Refer to drv_usb_ehci.h for usage information.
*/

void DRV_USB_EHCI_Tasks(SYS_MODULE_OBJ object)
{
    uint32_t drvIndex = (uint32_t)object;
    DRV_USB_EHCI_OBJ * hDriver = NULL;

    if(drvIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBEHCIObj[drvIndex];
        if((hDriver->inUse) && (hDriver->status > SYS_STATUS_UNINITIALIZED))
        {
            switch(hDriver->taskState)
            {
                case DRV_USB_EHCI_TASK_STATE_UNINITIALIZED:

                    /* Nothing to do here */
                    break;
                
                case DRV_USB_EHCI_TASK_STATE_WAIT_FOR_CLOCK:

                    /* Wait for PLLA,UPLL stabilization LOCK bit in PMC_SR     */
                    if(IS_LOCKU_ENABLE())
                    {
                        hDriver->status = SYS_STATUS_READY;
                        hDriver->taskState = DRV_USB_EHCI_TASK_STATE_RUNNING;
                    }

                    break;

                case DRV_USB_EHCI_TASK_STATE_RUNNING:

                    _DRV_USB_EHCI_PipeCloseTask(hDriver);
                    _DRV_USB_EHCI_PortsTask(hDriver);
                    break;

                   
                case DRV_USB_EHCI_TASK_STATE_IDLE:
                case DRV_USB_EHCI_TASK_STATE_ERROR:
                default:
                    /* Current operation, execution should not land here
                     * This is added for future expansion */
                    break;
            }
        }
        else
        {
            /* Driver object is not ready */ 
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid instance in Tasks Function");
    }
}

// *****************************************************************************
/* Function:
    USB_ERROR DRV_USB_EHCI_IRPSubmit
    (
        DRV_USB_EHCI_PIPE_HANDLE  hPipe,
        USB_HOST_IRP * pinputIRP
    )

  Summary:
    Submits an IRP on a pipe.
    
  Description:
    This function submits an IRP on the specified pipe. The IRP will be added to
    the queue and will be processed in turn. The data will be transferred on the
    bus based on the USB bus scheduling rules. When the IRP has been processed,
    the callback function specified in the IRP will be called. The IRP status
    will be updated to reflect the completion status of the IRP. 

  Remarks:
    See drv_usb_ehci.h for usage information.
*/

USB_ERROR DRV_USB_EHCI_IRPSubmit
(
    DRV_USB_EHCI_PIPE_HANDLE  hPipe,
    USB_HOST_IRP * pInputIRP
)
{
    USB_ERROR returnValue = USB_ERROR_NONE;
    uint16_t clientUniqueKey = (uint16_t)((hPipe & 0xFFFF0000) >> 16);
    uint16_t pipeObjIndex = (uint16_t)(hPipe & 0xFF);
    int drvIndex = (int)((hPipe & 0xFF00) >> 8);
    DRV_USB_EHCI_QH * pipe = NULL;
    USB_EHCI_QH * currentQH = NULL;
    bool slotFound = false;
    DRV_USB_EHCI_QTD * transfer = NULL;
    DRV_USB_EHCI_QTD * currentQTD = NULL;
    USB_HOST_IRP_LOCAL * pIRP = (USB_HOST_IRP_LOCAL *)pInputIRP;
    DRV_USB_EHCI_OBJ * hDriver = NULL;
    bool interruptWasEnabled = false;
    DRV_USB_EHCI_CONTROL_TRANSFER_QTD * controlTransfer;
    uhphs_registers_t * usbID  = NULL;
    int i = 0;
    int nextListIndex = 0;
    uint8_t bInterval = 0;
    uint32_t pollingRate = 0;
    USB_EHCI_QH * previousQH = NULL;

    returnValue = USB_ERROR_HOST_PIPE_INVALID;

    if(pipeObjIndex < USB_HOST_PIPES_NUMBER)
    {
        returnValue = USB_ERROR_HOST_DEVICE_INSTANCE_INVALID;

        if(drvIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
        {
            /* Get the pointer to the pipe object from the driver instance
             * object. */

            hDriver = &gDrvUSBEHCIObj[drvIndex];
            pipe = &hDriver->queueHeads[pipeObjIndex];
            returnValue = USB_ERROR_HOST_PIPE_INVALID;
            usbID = hDriver->usbID;

            if((pipe->clientUniqueKey == clientUniqueKey) && (pipe->pipeClosingState == DRV_USB_EHCI_PIPE_CLOSE_IDLE))
            {
                returnValue = USB_ERROR_HOST_ARGUMENTS_INVALID;
                if(pIRP != NULL) 
                {
                    /* Pipe Handle and IRP is valid. The next set of operation
                     * should be thread and interrupt safe.  Disable the
                     * interrupt if enabled and grab the mutex */

                    returnValue = USB_ERROR_NONE;

                    if(hDriver->inInterruptContext == false)
                    {
                        /* This means we are not executed within an interrupt
                         * context. Disable the interrupt and grab the mutex. */
                        if(OSAL_MUTEX_Lock(&hDriver->mutex, OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
                        {
                            interruptWasEnabled = SYS_INT_SourceDisable(hDriver->interruptSource);
                        }
                        else
                        {
                            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Mutex Lock failed in IRP Submit");
                            returnValue = USB_ERROR_OSAL_FUNCTION;
                        }
                    }
                    else
                    {
                        /* This means we are executed within an interrupt
                         * context. So we know we will not be preempted by a
                         * thread or another USB interrupt. */
                    }

                    if(returnValue == USB_ERROR_NONE)
                    {
                        /* Update the IRP */
                        pIRP->pipe = hPipe;
                        pIRP->tempState = DRV_USB_EHCI_IRP_STATE_IDLE;
                        pIRP->completedBytes = 0;
                        pIRP->scheduledBytes = 0;
                        pIRP->next = NULL;

                        /* IRP status is pending till it reaches the head of
                         * queue. */
                        pIRP->status = USB_HOST_IRP_STATUS_PENDING;

                        if(pipe->pipeType == USB_TRANSFER_TYPE_CONTROL)
                        {
                            controlTransfer = NULL;

                            /* For control transfers, look for control transfer qTDs */
                            for (i = 0; i < USB_HOST_TRANSFERS_NUMBER; i++)
                            {
                                if(hDriver->controlTransferQTD[i].inUse == false)
                                {
                                    controlTransfer = &hDriver->controlTransferQTD[i];
                                    controlTransfer->inUse = true;
                                    break;
                                }
                            }

                            if(controlTransfer != NULL)
                            { 
                                /* Connect the IRP to the control transfer object */ 
                                controlTransfer->irp = pIRP;

                                /* Check if the pipe queue is empty */
                                if(pipe->currentQTD == NULL)
                                {
                                    pIRP->scheduledBytes = _DRV_USB_EHCI_ControlTransferQTD(controlTransfer, (USB_SPEED)pipe->speed);
                                    pIRP->status = USB_HOST_IRP_STATUS_IN_PROGRESS;
                                    pipe->currentQTD = (DRV_USB_EHCI_QTD *)controlTransfer;
                                    pipe->qH.nextQTD.pointer = &controlTransfer->setupQTD;
                                    if(pipe->pipeInQueue == 0)
                                    {
                                        /* This means pipe is not in async schedule. Add it */
                                        currentQH = (USB_EHCI_QH *)usbID->UHPHS_ASYNCLISTADDR;
                                        pipe->qH.horizontalQH.pointer = currentQH->horizontalQH.pointer;
                                        currentQH->horizontalQH.pointer = (USB_EHCI_QH *)((uint32_t)&pipe->qH | ((USB_EHCI_QH_TYPE_QH) << 1));
                                        pipe->pipeInQueue = 1;
                                    }
                                }
                                else
                                {
                                    /* Add this IRP to the queue */
                                    currentQTD = pipe->currentQTD;
                                    while(currentQTD->irp->next != NULL)
                                    {
                                        currentQTD = currentQTD->irp->next;
                                    }

                                    /* At this point currentQTD should point to the
                                     * last QTD in the pipe */
                                    currentQTD->irp->next = controlTransfer;
                                }
                            }
                            else
                            {
                                returnValue = USB_ERROR_HOST_BUSY;
                                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Could not find free transfer object");
                            }
                        }
                        else
                        {
                            /* Non control transfer handling */
                            for (i = 0; i < USB_HOST_TRANSFERS_NUMBER; i++)
                            {
                                if(hDriver->queueTransferDescriptors[i].inUse == false)
                                {
                                    transfer = &hDriver->queueTransferDescriptors[i];
                                    transfer->inUse = true;
                                    break;
                                }
                            }

                            if(transfer != NULL)
                            {
                                /* We found a transfer object. Start populating
                                 * it. Link the IRP to the transfer descriptor
                                 * object */
                                transfer->irp = pIRP;

                                /* The tempState field for non-control transfers
                                 * only tracks if the IRP is to be aborted. We
                                 * simply set this to idle. */
                                pIRP->tempState = DRV_USB_EHCI_IRP_STATE_IDLE;

                                /* If the pipe queue is empty, we can immediately
                                 * start processing the transfer. */

                                if(pipe->currentQTD == NULL)
                                {
                                    /* This means the pipe queue is empty. We can
                                     * start the processing of the IRP immediately.
                                     * Assign this transfer to the head of the
                                     * queue. */ 

                                    pipe->currentQTD = transfer;
                                    pIRP->status = USB_HOST_IRP_STATUS_IN_PROGRESS;
                                    pIRP->scheduledBytes = _DRV_USB_EHCI_DataQTD(transfer, (USB_DATA_DIRECTION)pipe->direction);
                                    pipe->qH.nextQTD.pointer = &transfer->qTD;
                                    
                                    /* Check if the pipe is inserted into the schedule */
                                    if(pipe->pipeInQueue == 0)
                                    {
                                        /* Pipe should be added to the schedule. If this is a bulk pipe
                                         * then it should be added to the async schedule. */
                                        if(pipe->pipeType == USB_TRANSFER_TYPE_BULK)
                                        {
                                            /* This means pipe is not in async schedule. Add it */
                                            currentQH = (USB_EHCI_QH *)usbID->UHPHS_ASYNCLISTADDR;
                                            pipe->qH.horizontalQH.pointer = currentQH->horizontalQH.pointer;
                                            currentQH->horizontalQH.pointer = (USB_EHCI_QH *)((uint32_t)&pipe->qH | ((USB_EHCI_QH_TYPE_QH) << 1));
                                            pipe->pipeInQueue = 1; 
                                        }
                                        else
                                        {
                                            /* For interrupt pipe, the pipe should be inserted into the periodic list */

                                            nextListIndex = 0;
                                            slotFound = false;
                                            bInterval = pipe->bInterval;
                                            pollingRate = (1 << (bInterval - 1))/8;

                                            /* Now we scan the periodic frame list to find  a place where we can insert
                                             * the queue head. The trivial case is when the list is empty and the queue
                                             * head can be inserted into the very first slot. This means the list is 
                                             * completely empty */

                                            if(hDriver->periodicList[0] == USB_EHCI_END_OF_LIST)
                                            {
                                                slotFound = true;
                                                pipe->startSlot = hDriver->nextSlotToUse[pipe->bInterval]; 
                                                hDriver->nextSlotToUse[bInterval] ++;

                                                for(i = 0; i < DRV_USB_EHCI_PERIODIC_LIST_SIZE; i ++)
                                                {
                                                    /* This means this pipe is the first pipe in this slot.*/
                                                    pipe->qH.horizontalQH.pointer = (USB_EHCI_QH *)(USB_EHCI_END_OF_LIST);
                                                    hDriver->periodicList[nextListIndex] = USB_EHCI_PERIODIC_LIST_ENTRY(pipe, USB_EHCI_QH_TYPE_QH) ;

                                                    /* Insert the qH at the next polling interval */
                                                    nextListIndex += pollingRate;
                                                    if (nextListIndex >= DRV_USB_EHCI_PERIODIC_LIST_SIZE)
                                                    { 
                                                        break;
                                                    }
                                                }
                                            }

                                            if(!slotFound)
                                            {
                                                if(bInterval == 4)
                                                {
                                                    /* A 1 millisecond poll rate qH will always start at slot 0 */
                                                    pipe->startSlot = 0; 
                                                    pipe->qH.horizontalQH.value32 = USB_EHCI_END_OF_LIST;

                                                    /* Pipe with polling rate of 1 millisecond requires special handling. 
                                                     * They have to be inserted into every slot and to the end of the list. 
                                                     * A pipe with 1 millisecond polling will be always the last one in 
                                                     * the queue. If the list already contains a 1 millisecond qH then 
                                                     * this should come to the right of this qH. */

                                                    if(hDriver->nextSlotToUse[bInterval] > 0)
                                                    {
                                                        /* The list already contains a 1 millisecond pipe. Insert this pipe to 
                                                         * the right side of the pipe. */

                                                        currentQH = USB_EHCI_PERIODIC_LIST_QH(hDriver->periodicList[0]);
                                                        while(currentQH->horizontalQH.value32 != USB_EHCI_END_OF_LIST)
                                                        {
                                                            currentQH = USB_EHCI_PERIODIC_LIST_QH(currentQH->horizontalQH.value32);
                                                        }

                                                        /* Current qH has to point to the last 1 millisecond qH in the list. Add
                                                         * this qH to the right. */
                                                        currentQH->horizontalQH.value32 = USB_EHCI_PERIODIC_LIST_ENTRY(pipe, USB_EHCI_QH_TYPE_QH);
                                                    }
                                                    else
                                                    {
                                                        /* This is the first 1 millisecond pipe */
                                                        for(i = 0; i < DRV_USB_EHCI_PERIODIC_LIST_SIZE; i ++)
                                                        {
                                                            /* There may be some entries in the middle of the list
                                                             * which could be empty. We know that this point the pipe
                                                             * horizontal pointer will be have the end of list marker. */
                                                            if(hDriver->periodicList[i] == USB_EHCI_END_OF_LIST)
                                                            {
                                                                hDriver->periodicList[i] = USB_EHCI_PERIODIC_LIST_ENTRY(pipe, USB_EHCI_QH_TYPE_QH) ;
                                                            }
                                                            else
                                                            {
                                                                /* The entry is not empty. We traverse the list till we 
                                                                 * reach the end of the list. While traversing, we may
                                                                 * encounter the same pipe as this may have already 
                                                                 * been inserted in the previous pass. */
                                                                currentQH = USB_EHCI_PERIODIC_LIST_QH(hDriver->periodicList[i]);
                                                                while(currentQH->horizontalQH.value32 != USB_EHCI_END_OF_LIST) 
                                                                {
                                                                    if(currentQH->horizontalQH.value32 == USB_EHCI_PERIODIC_LIST_ENTRY(pipe, USB_EHCI_QH_TYPE_QH))
                                                                    {
                                                                        /* This means qH is already in the list */
                                                                        break;
                                                                    }

                                                                    /* Traverse the list */
                                                                    currentQH = USB_EHCI_PERIODIC_LIST_QH(currentQH->horizontalQH.value32);
                                                                }

                                                                if(currentQH->horizontalQH.value32 != USB_EHCI_PERIODIC_LIST_ENTRY(pipe, USB_EHCI_QH_TYPE_QH))
                                                                {
                                                                    /* At this point, current QH should point to last QH in the list */ 
                                                                    currentQH->horizontalQH.value32 = USB_EHCI_PERIODIC_LIST_ENTRY(pipe, USB_EHCI_QH_TYPE_QH);
                                                                }
                                                                else
                                                                {
                                                                    /* qH is already in the list */
                                                                }
                                                            }
                                                        }

                                                        /* For 1 millisecond qHead the nextSlotToUse is keeps track
                                                         * of the number of such qH in the periodic schedule. The 
                                                         * count is decremented when the pipe is closed. */

                                                        hDriver->nextSlotToUse[bInterval] ++;
                                                        slotFound = true;
                                                    }
                                                }
                                                else
                                                {
                                                    /* Frame list is not empty and we must insert a pipe with a 
                                                     * polling rate greater than 1. To this we must find the 
                                                     * first slot. The first slot must be within the first polling rate
                                                     * slots on the list. For example, with a polling rate of 8, the
                                                     * first slot should in slots 0 to 7. Additionally, we should 
                                                     * find a slot that preferably does not have another qH with
                                                     * the same polling rate. This allows for spreading of the 
                                                     * interrupt queues as mentioned on page 93 of the specification.
                                                     * So we scan till we find a slot that has the least number of
                                                     * pipe with the same polling rate and then insert the qH into 
                                                     * that slot. */

                                                    /* The nextSlotToUse array in the driver object provides information 
                                                     * on the next slot to be used for a specific bInterval. Increment the
                                                     * nextSlotToUse counter and if we have reached the end of the 
                                                     * polling rate window */

                                                    pipe->startSlot = hDriver->nextSlotToUse[bInterval];
                                                    hDriver->nextSlotToUse[bInterval] ++;
                                                    hDriver->nextSlotToUse[bInterval] = (hDriver->nextSlotToUse[bInterval] >= pollingRate) ? 0 : hDriver->nextSlotToUse[bInterval];

                                                    for(i = pipe->startSlot; i < DRV_USB_EHCI_PERIODIC_LIST_SIZE; (i += pollingRate))
                                                    {
                                                        currentQH = USB_EHCI_PERIODIC_LIST_QH(hDriver->periodicList[i]);

                                                        if(hDriver->periodicList[i] == USB_EHCI_END_OF_LIST)
                                                        {
                                                            /* This slot is empty */
                                                            pipe->qH.horizontalQH.value32 = USB_EHCI_END_OF_LIST;
                                                            hDriver->periodicList[i] = USB_EHCI_PERIODIC_LIST_ENTRY(pipe, USB_EHCI_QH_TYPE_QH);
                                                        }
                                                        else if(pollingRate >= _DRV_USB_EHCI_POLLING_RATE(((DRV_USB_EHCI_QH *)currentQH)->bInterval))
                                                        {
                                                            /* This qH should be placed at the beginning of the list */
                                                            pipe->qH.horizontalQH.value32 = USB_EHCI_PERIODIC_LIST_ENTRY(currentQH, USB_EHCI_QH_TYPE_QH);
                                                            hDriver->periodicList[i] = USB_EHCI_PERIODIC_LIST_ENTRY(pipe, USB_EHCI_QH_TYPE_QH);
                                                        }
                                                        else
                                                        {
                                                            /* Slot is not empty and there is more than one qH in the list */
                                                            previousQH = currentQH;
                                                            while(currentQH->horizontalQH.value32 != USB_EHCI_END_OF_LIST)
                                                            {
                                                                previousQH = currentQH;
                                                                currentQH = USB_EHCI_PERIODIC_LIST_QH(currentQH->horizontalQH.value32);
                                                                
                                                                if(currentQH == (USB_EHCI_QH *)(pipe))
                                                                {
                                                                    /* Pipe is already in this list */
                                                                    break;
                                                                }

                                                                if(pollingRate >= _DRV_USB_EHCI_POLLING_RATE(((DRV_USB_EHCI_QH *)currentQH)->bInterval))
                                                                {
                                                                    /* We have found the place to insert the qH */
                                                                    pipe->qH.horizontalQH.value32 = USB_EHCI_PERIODIC_LIST_ENTRY(currentQH, USB_EHCI_QH_TYPE_QH);
                                                                    previousQH->horizontalQH.value32 = USB_EHCI_PERIODIC_LIST_ENTRY(pipe, USB_EHCI_QH_TYPE_QH);
                                                                    break;
                                                                }
                                                            }
                                                        } 
                                                    }
                                                }
                                            }

                                            /* Pipe has been added to the queue */
                                            pipe->pipeInQueue = 1;
                                        }
                                    }
                                    else
                                    {
                                        /* Pipe is already in the queue */
                                    }
                                }
                                else
                                {
                                    /* Add this IRP to the queue */

                                    currentQTD = pipe->currentQTD;
                                    while(currentQTD->irp->next != NULL)
                                    {
                                        currentQTD = currentQTD->irp->next;
                                    }

                                    /* At this point currentQTD should point to the
                                     * last QTD in the pipe */
                                    currentQTD->irp->next = transfer;
                                }
                            }
                            else
                            {
                                returnValue = USB_ERROR_HOST_BUSY;
                                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Could not find free transfer object");
                            }
                        }

                        /* All processing done. Restore the interrupt status and
                         * release the mutex */

                        if(hDriver->inInterruptContext == false)
                        {
                            if(interruptWasEnabled)
                            {
                                SYS_INT_SourceEnable(hDriver->interruptSource);
                            }

                            OSAL_MUTEX_Unlock(&hDriver->mutex);
                        }
                        else
                        {
                            /* Drive is in interrupt context */
                        }
                    }
                    else
                    {
                        /* There was some error while grabbing the mutex */
                    }
                }
                else
                {
                    SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: IRP is no valid submit");
                }
            }
            else
            {
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid pipe handle in IRP Submit");
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid driver Index in IRP Submit");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid Pipe Object Index in IRP Submit");
    }

    return(returnValue);
}

// *****************************************************************************
/* Function:
    void DRV_USB_EHCI_IRPCancel(USB_HOST_IRP * pinputIRP)

  Summary:
    Cancels the specified IRP.
    
  Description:
    This function attempts to cancel the specified IRP. If the IRP is queued and
    its processing has not started, it will be cancelled successfully. If the
    IRP in progress, the ongoing transaction will be allowed to complete. 

  Remarks:
    See drv_usb_ehci.h for usage information.
*/
 
void DRV_USB_EHCI_IRPCancel(USB_HOST_IRP * pInputIRP)
{
    USB_HOST_IRP_LOCAL * irp = (USB_HOST_IRP_LOCAL *)pInputIRP;
    DRV_USB_EHCI_PIPE_HANDLE hPipe = DRV_USB_EHCI_PIPE_HANDLE_INVALID;
    DRV_USB_EHCI_OBJ * hDriver = NULL;
    DRV_USB_EHCI_QH * pipe = NULL;
    bool interruptWasEnabled = false;
    uint16_t clientUniqueKey = 0;
    uint16_t pipeObjIndex = 0;
    int drvIndex = 0;
    DRV_USB_EHCI_QTD * currentQTD = NULL;
    DRV_USB_EHCI_CONTROL_TRANSFER_QTD * controlQTD = NULL;
    DRV_USB_EHCI_QTD * qTD = NULL;
  

    if(irp != NULL)
    {
        /* Get the pipe to which IRP belongs */
        hPipe = irp->pipe;
        clientUniqueKey = (uint16_t)((hPipe & 0xFFFF0000) >> 16);
        pipeObjIndex = (uint16_t)(hPipe & 0xFF);
        drvIndex = (int)((hPipe & 0xFF00) >> 8);

        if(pipeObjIndex < USB_HOST_PIPES_NUMBER)
        {
            if(drvIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
            {
                hDriver = &gDrvUSBEHCIObj[drvIndex];
                pipe = &hDriver->queueHeads[pipeObjIndex];

                if((pipe->clientUniqueKey == clientUniqueKey) && (pipe->pipeClosingState == DRV_USB_EHCI_PIPE_CLOSE_IDLE))
                {
                    if(hDriver->inInterruptContext == false)
                    {
                        /* This means we are not executed within an interrupt
                         * context. Disable the interrupt and grab the mutex. */
                        if(OSAL_MUTEX_Lock(&hDriver->mutex, OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
                        {
                            interruptWasEnabled = SYS_INT_SourceDisable(hDriver->interruptSource);
                        }
                        else
                        {
                            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Mutex Lock failed in IRP Submit");
                        }
                    }

                    /* Check if the IRP is in progress. If so then this will cancelled in the 
                     * the interrupt. */

                    if(irp->status == USB_HOST_IRP_STATUS_IN_PROGRESS)
                    {
                        /* This means this qTD is at the head of the queue.
                         * We will track this in the interrupt. */
                        qTD->irp->tempState = DRV_USB_EHCI_IRP_STATE_ABORTED;
                    }
                    else
                    {
                        /* Else we have to find the IRP in the queue. We have
                         * the pipe that this is IRP is associated with.
                         * Find the IRP in this pipe. */

                        if(pipe->pipeType == USB_TRANSFER_TYPE_CONTROL)
                        {
                            /* If this is a control transfer pipe, then we have to deal
                             * with control QTDs */

                            controlQTD = (DRV_USB_EHCI_CONTROL_TRANSFER_QTD *)pipe->currentQTD;
                            while(controlQTD != NULL)
                            {
                                if(((DRV_USB_EHCI_CONTROL_TRANSFER_QTD *)controlQTD->irp->next) != NULL)
                                {
                                    if((((DRV_USB_EHCI_CONTROL_TRANSFER_QTD *)controlQTD->irp->next)->irp == irp))
                                    {
                                        /* We have found the irp. Update the queue to skip this
                                         * this IRP. */
                                        controlQTD->irp->next = ((DRV_USB_EHCI_CONTROL_TRANSFER_QTD *)controlQTD->irp->next)->irp->next;

                                        /* Terminate the IRP */
                                        irp->status = USB_HOST_IRP_STATUS_ABORTED;
                                        if(irp->callback != NULL)
                                        {
                                            irp->callback((USB_HOST_IRP *)irp);
                                        }
                                        break;
                                    }
                                }

                                /* Goto the next QTD */
                                controlQTD = controlQTD->irp->next;
                            }
                        }
                        else
                        {
                          /* For interrupt and bulk pipes */
                            currentQTD = pipe->currentQTD;
                            while(currentQTD != NULL)
                            {
                                if(currentQTD->irp->next != NULL)
                                {
                                    if(((DRV_USB_EHCI_QTD *)currentQTD->irp->next)->irp == irp)
                                    {
                                        /* We have found the irp. Update the queue to skip this
                                         * this IRP. */
                                        currentQTD->irp->next = ((DRV_USB_EHCI_QTD *)currentQTD->irp->next)->irp->next;

                                        /* Terminate the IRP */
                                        irp->status = USB_HOST_IRP_STATUS_ABORTED;
                                        if(irp->callback != NULL)
                                        {
                                            irp->callback((USB_HOST_IRP *)irp);
                                        }
                                        break;
                                    }
                                }

                                /* Goto the next QTD */
                                currentQTD = currentQTD->irp->next;
                            }
                        }
                    }

                    /* Release the mutex */
                    if(hDriver->inInterruptContext == false)
                    {
                        if(interruptWasEnabled)
                        {
                            SYS_INT_SourceEnable(hDriver->interruptSource);
                        }

                        OSAL_MUTEX_Unlock(&hDriver->mutex);
                    }
                    else
                    {
                        /* Drive is in interrupt context */
                    }
                }
            }
            else
            {
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid Driver Instance in IRP Cancel");
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid Pipe in IRP Cancel");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid IRP in IRP Cancel");
    }
}

// *****************************************************************************
/* Function:
    void DRV_USB_EHCI_PipeClose(DRV_USB_EHCI_PIPE_HANDLE pipeHandle)

  Summary:
    Closes an open pipe.
	
  Description:
    This function closes an open pipe. Any IRPs scheduled on the pipe will be
    aborted and IRP callback functions will be called with the status as
    DRV_USB_HOST_IRP_STATE_ABORTED. The pipe handle will become invalid and the
    pipe will not accept IRPs.

  Remarks:
    See drv_usb_ehci.h for usage information.
*/

void DRV_USB_EHCI_PipeClose
(
    DRV_USB_EHCI_PIPE_HANDLE hPipe
)
{
    uint16_t clientUniqueKey = (uint16_t)((hPipe & 0xFFFF0000) >> 16);
    uint16_t pipeObjIndex = (uint16_t)(hPipe & 0xFF);
    int drvIndex = (int)((hPipe & 0xFF00) >> 8);
    DRV_USB_EHCI_QH * pipe = NULL;
    DRV_USB_EHCI_OBJ * hDriver = NULL;
    bool thereWasAnError = false; 
    bool interruptWasEnabled = false;
    DRV_USB_EHCI_QTD * transfer = NULL;
      

    if(pipeObjIndex < USB_HOST_PIPES_NUMBER)
    {
        if(drvIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
        {
            /* Get the pointer to the pipe object from the driver instance
             * object. */

            hDriver = &gDrvUSBEHCIObj[drvIndex];
            pipe = &hDriver->queueHeads[pipeObjIndex];

            if(pipe->clientUniqueKey == clientUniqueKey)
            {
                /* Pipe handle and driver client is valid. */

                if(hDriver->inInterruptContext == false)
                {
                    if(OSAL_MUTEX_Lock(&hDriver->mutex, OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
                    {
                        interruptWasEnabled = SYS_INT_SourceDisable(hDriver->interruptSource);
                    }
                    else
                    {
                        thereWasAnError = true;
                        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Mutex lock failed in Pipe Close");
                    }
                }

                if(!thereWasAnError)
                {

                    if(pipe->pipeType == USB_TRANSFER_TYPE_INTERRUPT)
                    {
                        /* Check if the QH head is active, if so then set the
                         * inactivate bit */

                        if(pipe->qH.qTDToken.active == 1)
                        {
                            pipe->qH.i = 1;
                        }
                    }

                    /* Section 4.8.2 of the specification provides the
                     * procedure for removing queue heads from the async
                     * schedule. In addition to following this procedure, we
                     * will do the following. We will set the pipe queue
                     * head to NULL. This will ensure that if any pending
                     * transaction that causes any interrupt on the pipe
                     * will be handled. We will also also release any
                     * transfer objects that were pending on this pipe. */ 

                    transfer = pipe->currentQTD;
                    while(transfer != NULL)
                    {
                        /* For each QTD scheduled on pipe, clear the active bit, issue the
                         * IRP callback and then release the transfer object. */

                        transfer = pipe->currentQTD;
                        transfer->qTD.qTDToken.active = 0;
                        if(transfer->irp->callback != NULL)
                        {
                            transfer->irp->status = USB_HOST_IRP_STATUS_ABORTED;
                            transfer->irp->callback((USB_HOST_IRP *)transfer->irp); 
                        }

                        transfer->inUse = false;
                        transfer = transfer->irp->next;
                    }

                    /* Mark the head as empty */
                    pipe->currentQTD = NULL;

                    /* We should first check if the pipe was inserted into 
                     * schedule. Pipe are inserted into the schedule only 
                     * when at least one transaction was submitted on the pipe
                     * If the pipe was added to schedule, then we let the pipe
                     * close tasks handle this. */

                    if(!pipe->pipeInQueue)
                    {
                        pipe->pipeClosingState = DRV_USB_EHCI_PIPE_CLOSE_IDLE;
                        pipe->clientUniqueKey = 0xFFFF;
                        pipe->pipeInQueue = 0;
                        hDriver->microFrameUsage[pipe->microFrameIndex]--;
                        pipe->inUse = false;
                    }
                    else
                    {
                        /* The rest of the pipe closure will have to happen in the task routine. */
                        pipe->pipeClosingState = DRV_USB_EHCI_PIPE_CLOSE_REQUEST_PENDING;
                    }
                }

                /* Reenable interrupt and release mutex */
                if(hDriver->inInterruptContext == false)
                {
                    if(interruptWasEnabled)
                    {
                        SYS_INT_SourceEnable(hDriver->interruptSource);
                    }

                    OSAL_MUTEX_Unlock(&hDriver->mutex);
                }
            }
            else
            {
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid Pipe in Pipe Close");
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid Driver Instance Index in Pipe Close");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid Pipe Object Index in Pipe Close");
    }
}

// *****************************************************************************
/* Function:
    DRV_USB_EHCI_PIPE_HANDLE DRV_USB_EHCI_PipeSetup
    (
        DRV_HANDLE handle,
        uint8_t deviceAddress,
        USB_ENDPOINT endpointAndDirection,
        uint8_t hubAddress,
        uint8_t hubPort,
        USB_TRANSFER_TYPE pipeType,
        uint8_t bInterval,
        uint16_t wMaxPacketSize,
        USB_SPEED speed
    )

  Summary:
    Open a pipe with the specified attributes.
	
  Description:
    This function opens a communication pipe between the Host and the device
    endpoint. The transfer type and other attributes are specified through the
    function parameters. The driver does not check for available bus bandwidth,
    which should be done by the application (the USB Host Layer in this case)

  Remarks:
    See drv_usb_ehci.h for usage information.
*/

DRV_USB_EHCI_PIPE_HANDLE DRV_USB_EHCI_PipeSetup 
(
    DRV_HANDLE handle,
    uint8_t deviceAddress, 
    USB_ENDPOINT endpointAndDirection,
    uint8_t hubAddress,
    uint8_t hubPort,
    USB_TRANSFER_TYPE pipeType, 
    uint8_t bInterval, 
    uint16_t wMaxPacketSize,
    USB_SPEED speed
)
{
    DRV_USB_EHCI_PIPE_HANDLE pipeHandle = DRV_USB_EHCI_PIPE_HANDLE_INVALID;
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);
    DRV_USB_EHCI_OBJ * hDriver = NULL;
    DRV_USB_EHCI_QH * pipe = NULL;
    int i = 0;
    uint8_t microFrameIndex = 0;
    int interval = 0;
    int pollingRate = 0;
    int minUsageValue = 0;
    int minUsageIndex = 0;
      
    
    if(drvIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBEHCIObj[drvIndex];
        
        if(hDriver->clientUniqueKey == clientUniqueKey)
        {
            if(speed != USB_SPEED_ERROR)
            {
                /* wMaxPacketSize can be less than 8 for Non control endpoints.
                 * E.g.  Interrupt IN endpoints can be 4 bytes for HID Mouse
                 * device. This USB module requires minimum 2 to the power 3
                 * i.e. 8 bytes as the wMaxPacketSize. For Control endpoints the
                 * minimum has to be 8 bytes.  */
                if(pipeType != USB_TRANSFER_TYPE_CONTROL)
                {
                    if(wMaxPacketSize < 8)
                    {
                        wMaxPacketSize = 8;
                    }
                }

                if((wMaxPacketSize >= 8) && (wMaxPacketSize <= 1024))
                {
                    if(OSAL_MUTEX_Lock(&hDriver->mutex, OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
                    {
                        /* Look for a free driver pipe object */
                        for(i = 0; i < USB_HOST_PIPES_NUMBER; i ++)
                        {
                            if(hDriver->queueHeads[i].inUse == false)
                            {
                                /* We found a free queue head. Allocate this */
                                hDriver->queueHeads[i].inUse = true;
                                pipe = &hDriver->queueHeads[i];
                                pipe->pipeType = pipeType;
                                pipe->clientUniqueKey = _DRV_USB_EHCI_GetUniqueKey(hDriver);
                                pipe->currentQTD = NULL;
                                pipe->pipeClosingState = DRV_USB_EHCI_PIPE_CLOSE_IDLE;
                                pipe->speed = speed;

                                /* The pipe handle is a composite value. The
                                 * first byte is an index into the pipe object
                                 * array. The second byte in an index into the
                                 * hardware instance object array and third and
                                 * fourth bytes are the client unique key. */
                                pipeHandle = (DRV_USB_EHCI_PIPE_HANDLE)(((pipe->clientUniqueKey << 16) & 0xFFFF0000) | ((drvIndex & 0xFF) << 8) | (i & 0xFF));

                                /* Clear up the qHead structure */
                                memset(&pipe->qH, 0, sizeof(USB_EHCI_QH));

                                /* Configure the qH data structure. Refer to
                                 * section 3.6 of the specification. */
                                pipe->qH.horizontalQH.terminate = 1;
                                pipe->qH.deviceAddress = deviceAddress;
                                pipe->qH.i = 0;
                                pipe->qH.endpt = endpointAndDirection & 0xF;
                                pipe->qH.mult = 1;
                                pipe->qH.nextQTD.terminate = 1;
                                pipe->qH.alternateNextQtd.terminate = 1;
                                pipe->qH.maxPacketSize = wMaxPacketSize;
                                pipe->qH.eps = USB_EHCI_QH_SPEED_HIGH;
                                pipe->qH.hubAddress = hubAddress;
                                pipe->qH.port = (hubAddress != 0) ? hubPort : 0;
                                pipe->qH.rl = 0;

                                if(speed == USB_SPEED_FULL)
                                {
                                    pipe->qH.eps = USB_EHCI_QH_SPEED_FULL;
                                }
                                else if(speed == USB_SPEED_LOW)
                                {
                                    pipe->qH.eps = USB_EHCI_QH_SPEED_LOW;
                                }

                                if(pipe->pipeType == USB_TRANSFER_TYPE_CONTROL)
                                {
                                    /* In case of a control transfer, we let
                                     * the qTD decide the datatoggle. The queue
                                     * handling function is the function that
                                     * is called when the interrupt occurs. For
                                     * this pipe it will be the
                                     * _DRV_USB_EHCI_ControlTransferProcess
                                     * function. Pipe direction is obtained
                                     * from the IRP setup packet. */

                                    pipe->qH.dtc = 1;
                                    pipe->queueHandler = _DRV_USB_EHCI_ControlTransferProcess;

                                    if(speed != USB_SPEED_HIGH)
                                    {
                                        pipe->qH.c = 1;
                                    }
                                }
                                else
                                {
                                    /* In case of bulk, we let the queuehead
                                     * maintain the data toggle. We also store
                                     * the pipe direction in the direction
                                     * field. */

                                    pipe->queueHandler = _DRV_USB_EHCI_BulkTransferProcess;
                                    pipe->qH.dtc = 0;
                                    if((endpointAndDirection & 0x80) != 0)
                                    {
                                        pipe->direction = USB_DATA_DIRECTION_DEVICE_TO_HOST;
                                    }
                                    else
                                    {
                                        pipe->direction = USB_DATA_DIRECTION_HOST_TO_DEVICE;
                                    }
                                }

                                if(pipeType == USB_TRANSFER_TYPE_INTERRUPT)
                                {
                                    if(speed == USB_SPEED_HIGH)
                                    {
                                       /* We can only handle polling rates between 1 and 1024 milliseconds */
                                        pipe->bInterval = bInterval;

                                        if(bInterval < 4)
                                        {
                                            pipe->bInterval = 4;
                                        }
                                        else if(bInterval > 14)
                                        {
                                            pipe->bInterval = 14;
                                        }

                                        /* We will use the 6 and 7th microframe
                                         * for high speed Interrupt transfers.
                                         * The microframe to be used is based
                                         * on the current loading tracked in
                                         * the microFrameUsage array. The index
                                         * in the array corresponds to the
                                         * microFrameUsage*/

                                        microFrameIndex = (hDriver->microFrameUsage[6] <= hDriver->microFrameUsage[7]) ? 6 : 7;
                                        pipe->qH.sMask = (1 << microFrameIndex);
                                        pipe->microFrameIndex = microFrameIndex;
                                        hDriver->microFrameUsage[microFrameIndex] ++;
                                    }
                                    else
                                    {
                                        /* The full speed interval is in millisecond. We have to calculate the nearest
                                         * 2^n polling rate less than the polling rate. Starting with interval 4 gives
                                         * us a value of 1 millisecond. */

                                        interval = 4;
                                        pollingRate = _DRV_USB_EHCI_POLLING_RATE(interval);
                                        while(pollingRate < bInterval)
                                        {
                                            interval ++;
                                            pollingRate = _DRV_USB_EHCI_POLLING_RATE(interval);
                                            if(interval == 14)
                                            {
                                                /* We support pollingRate of upto 1.024 seconds */
                                                break;
                                            }
                                        }

                                        /* At this point we may have a polling rate that is greater than desired. If so,
                                         * adjust this polling rate. */
                                        if(pollingRate > bInterval)
                                        {
                                            interval --;
                                        }

                                        /* Save the interval in the pipe object */
                                        pipe->bInterval = interval;

                                        /* For low and full speed pipes, we have to set the S and C masks. Find the
                                         * a slot with lowest usage */
                                        minUsageValue = hDriver->microFrameUsage[0];
                                        minUsageIndex = 0;
                                        for(i = 0; i < 3; i ++)
                                        {
                                            if(hDriver->microFrameUsage[i] < minUsageValue)
                                            {
                                                minUsageValue = hDriver->microFrameUsage[i];
                                                minUsageIndex = i;
                                            }
                                        }

                                        /* We now have the microframe with the lowest usage.
                                         * Set up the S mask and the C mask. For example if
                                         * S mask is in microframe 0, then C mask should be
                                         * microframes 1,2 and 3. */

                                        hDriver->microFrameUsage[minUsageIndex] ++;
                                        pipe->microFrameIndex = minUsageIndex;
                                        pipe->qH.sMask = (1 << minUsageIndex);
                                        pipe->qH.cMask = (7 << (minUsageIndex + 1));
                                    }
                                }

                                /* The pipe will be added to the async or periodic schedule in the IRP submit */
                                pipe->pipeInQueue = 0;

                                break;
                            }
                        }

                        if(pipeHandle == DRV_USB_EHCI_PIPE_HANDLE_INVALID)
                        {
                            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Could not find free pipe object");
                        }

                        /* Release the mutex */
                        OSAL_MUTEX_Unlock(&hDriver->mutex);
                    }
                    else
                    {
                        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Mutex Error in pipe setup function");
                    }
                }
                else
                {
                    SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid pipe endpoint size in pipe setup function");
                }
            }
            else
            {
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid Speed in Pipe Setup function");
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid handle in Pipe Setup function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid instance in Pipe Setup function");
    }

    return(pipeHandle);
}

// ****************************************************************************
/* Function:
    bool DRV_USB_EHCI_EventDisable
    (
        DRV_HANDLE handle
    );
   
  Summary:
    Disables host mode events.
    
  Description:
    This function disables the host mode events. This function is called by the
    Host Layer when it wants to execute code atomically. 
    
  Remarks:
    Refer to drv_usb_ehci.h for usage information.
*/

bool DRV_USB_EHCI_EventsDisable
(
    DRV_HANDLE handle
)
{
    bool result = false;
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);

    if(drvIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
    {
        if(gDrvUSBEHCIObj[drvIndex].clientUniqueKey == clientUniqueKey)
        {
            result = SYS_INT_SourceDisable(gDrvUSBEHCIObj[drvIndex].interruptSource);
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid handle in Events Disable function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid instance in Events Disable function");
    }

    return(result);
}

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
    This function will restore the enable disable state of the events.
    eventRestoreContext should be equal to the value returned by the
    DRV_USB_EHCI_EventsDisable() function.
    
  Remarks:
    Refer to drv_usb_ehci.h for usage information.
*/

void DRV_USB_EHCI_EventsEnable
(
    DRV_HANDLE handle, 
    bool eventContext
)
{
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);

    if(drvIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
    {
        if(gDrvUSBEHCIObj[drvIndex].clientUniqueKey == clientUniqueKey)
        {
            if(eventContext == true)
            {
                SYS_INT_SourceEnable(gDrvUSBEHCIObj[drvIndex].interruptSource);
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid handle in Events Disable function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid instance in Events Disable function");
    }
}

// *****************************************************************************
/* Function:
    void DRV_USB_EHCI_OperationEnable(DRV_HANDLE handle, bool enable)

  Summary:
    Enables Root Hub Operation.

  Description:
    This function enables the Root Hub Operation. When enabled the root hub will
    supply power to the port thus enabling device attach detection.

  Remarks:
    Refer to drv_usb_ehci.h for usage information.
*/

void DRV_USB_EHCI_OperationEnable(DRV_HANDLE handle, bool enable)
{
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);
    DRV_USB_EHCI_OBJ * hDriver = NULL;
    uhphs_registers_t * usbID = NULL;

    if(drvIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBEHCIObj[drvIndex];
        if(hDriver->clientUniqueKey == clientUniqueKey)
        {
            usbID = hDriver->usbID;

            /* Driver handle is valid */
            if(enable == true)
            {
                /* Enable the controller. This will be done in state machine as
                 * there are several steps required. The state machine will be
                 * driven by the OperationIsEnabled function which is called
                 * periodically by the host layer till the operation is enabled. */

                hDriver->operationEnableState = DRV_USB_EHCI_OPERATION_ENABLE_START;
            }
            else
            {
                /* Disable the controller.Then disable the interrupts and clear
                 * the flags.  Clear the run bit and then wait till
                 * the halted bit is set. We don't bother clearing the interrupt
                 * flags as these will be cleared on the controller reset in the
                 * enable operation.  */

                usbID->UHPHS_USBINTR = 0;
                usbID->UHPHS_USBCMD &= ~(UHPHS_USBCMD_RS_Msk);
                
                /* We have to wait here till the halted bit is set. This while
                 * loop should not block for more than 2 milliseconds as per the
                 * description of the RS bit in table 2-9 of the specification.
                 * The alternative to blocking would be to have a state machine
                 * in the driver tasks. But given that the likely hood of the
                 * bus disable function being called is low and the adding the
                 * state machine increase complexity, the while loop is used in
                 * the current implementation. */

                while(usbID->UHPHS_USBSTS & UHPHS_USBSTS_HCHLT_Msk);
                hDriver->operationEnabled = false;
                hDriver->operationEnableState = DRV_USB_EHCI_OPERATION_ENABLE_DISABLE;
                SYS_INT_SourceDisable(hDriver->interruptSource);
                SYS_INT_SourceStatusClear(hDriver->interruptSource);
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid handle in OperationEnable function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid instance in OperationEnable function");
    }
}

// *****************************************************************************
/* Function:
    bool DRV_USB_EHCI_OperationIsEnabled(DRV_HANDLE handle)

  Summary:
    Returns true if root hub operation has been enabled.

  Description:
    Function returns true if the root hub enable operation has completed.

  Remarks:
    Refer to drv_usb_ehci.h for usage information.

*/

bool DRV_USB_EHCI_OperationIsEnabled(DRV_HANDLE handle)
{
    bool returnValue = false;
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);
    DRV_USB_EHCI_OBJ * hDriver = NULL;
    uhphs_registers_t * usbID = NULL;
    int i;

    if(drvIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBEHCIObj[drvIndex];
        if(hDriver->clientUniqueKey == clientUniqueKey)
        {
            usbID = hDriver->usbID;
            if(hDriver->operationEnabled != true)
            {
                /* This operation enable has not completed. Advance the state
                 * machine. */
                switch(hDriver->operationEnableState)
                {
                    case DRV_USB_EHCI_OPERATION_ENABLE_DISABLE:
                        
                        /* Nothing to be done here. Operation enable has not
                         * been called yet */
                        break;

                    case DRV_USB_EHCI_OPERATION_ENABLE_START:

                        /* The state is entered when the OperationEnable
                         * function is called with enable set to true. Initialize
                         * the periodic frame list. Set all queue head pointers
                         * to the end of list marker */
                        for (i = 0; i < DRV_USB_EHCI_PERIODIC_LIST_SIZE; i ++)
                        {
                            hDriver->periodicList[i] = USB_EHCI_END_OF_LIST; 
                        }

                        /* As per table 2-9 of the specification, to reset the
                         * HC controller we have to first make sure that the 
                         * controller is halted. */

                        if((usbID->UHPHS_USBSTS & UHPHS_USBSTS_HCHLT_Msk) != UHPHS_USBSTS_HCHLT_Msk)
                        {
                            /* Clear the Run bit to stop the controller */
                            usbID->UHPHS_USBCMD &= (~UHPHS_USBCMD_RS_Msk);
                            hDriver->operationEnableState = DRV_USB_EHCI_OPERATION_ENABLE_WAIT_FOR_HALT;
                        }
                        else
                        {
                            /* Halted bit is already set. */
                            hDriver->operationEnableState = DRV_USB_EHCI_OPERATION_ENABLE_HC_RESET;
                        }

                        break;

                    case DRV_USB_EHCI_OPERATION_ENABLE_WAIT_FOR_HALT:

                        /* Check here if the halt bit has been set */
                        if((usbID->UHPHS_USBSTS & UHPHS_USBSTS_HCHLT_Msk) == UHPHS_USBSTS_HCHLT_Msk)
                        {
                            hDriver->operationEnableState = DRV_USB_EHCI_OPERATION_ENABLE_HC_RESET;
                        }

                        break;

                    case DRV_USB_EHCI_OPERATION_ENABLE_HC_RESET:

                        /* The HC has halted. Now reset it */
                        usbID->UHPHS_USBCMD |= UHPHS_USBCMD_HCRESET_Msk;
                        hDriver->operationEnableState = DRV_USB_EHCI_OPERATION_ENABLE_WAIT_RESET;
                        break;

                    case DRV_USB_EHCI_OPERATION_ENABLE_WAIT_RESET:

                        /* Check if the reset has completed */
                        if((usbID->UHPHS_USBCMD & UHPHS_USBCMD_HCRESET_Msk) == 0)
                        {
                            /* Reset has completed. Enable interrupts. Set the
                             * periodic and async schedule base addresses. Set
                             * the async to an invalid QH. Enable required
                             * interrupts.
                             * */

                            usbID->UHPHS_PERIODICLISTBASE = (uint32_t)hDriver->periodicList;
                            usbID->UHPHS_ASYNCLISTADDR = (uint32_t)hDriver->asyncHeadQH;
                            usbID->UHPHS_USBCMD &= (~UHPHS_USBCMD_ITC_Msk);
                            usbID->UHPHS_USBCMD &= (~UHPHS_USBCMD_FLS_Msk);
                            usbID->UHPHS_USBCMD &= (~UHPHS_USBCMD_ASPME_Msk);
                            usbID->UHPHS_USBCMD |= (UHPHS_USBCMD_ITC(8) | UHPHS_USBCMD_FLS(0));
                            usbID->UHPHS_USBINTR = (UHPHS_USBINTR_USBIE_Msk|UHPHS_USBINTR_USBEIE_Msk|
                                    UHPHS_USBINTR_PCIE_Msk|UHPHS_USBINTR_HSEE_Msk);

                            /* All registers are configured. Set the the run bit
                             * */

                            usbID->UHPHS_USBCMD |= (UHPHS_USBCMD_RS_Msk);
                            hDriver->operationEnableState = DRV_USB_EHCI_OPERATION_ENABLE_WAIT_RUN;
                        }

                        break;

                    case DRV_USB_EHCI_OPERATION_ENABLE_WAIT_RUN:

                        /* Check if the HC has moved out of Halted State */
                        if((usbID->UHPHS_USBSTS & UHPHS_USBSTS_HCHLT_Msk) == 0)
                        {
                            /* HC is running.Make HC the owner of all ports and
                             * then enable the port power. We
                             * should check. */
                            volatile uint32_t * portSC = (volatile uint32_t *)((uint32_t)usbID + UHPHS_PORTSC_REG);

                            /* Assign ownership to EHCI first */
                            usbID->UHPHS_CONFIGFLAG = UHPHS_CONFIGFLAG_CF_Msk;
                            
                            /* Enable power on all selected ports. */
                            for (i = 0; i < DRV_USB_EHCI_PORT_NUMBERS; i ++)
                            {
                                if(hDriver->ports[i].selected)
                                {
                                    /* The application intends to use this port.
                                     * Enable it */
                                    portSC[i] = UHPHS_PORTSC_N_PP_Msk;
                                    if (hDriver->portPowerEnable != NULL)
                                    {
                                        /* Call the application provided power
                                         * enable function */
                                        hDriver->portPowerEnable((uint8_t)i, true);
                                    }
                                }
                            }

                            SYS_INT_SourceStatusClear(hDriver->interruptSource);
                            SYS_INT_SourceEnable(hDriver->interruptSource);

                            /* We can also start the asynch schedule at this
                             * point. The Asynch List address points to the head
                             * queue */
                            usbID->UHPHS_USBCMD |= UHPHS_USBCMD_ASE_Msk;

                            /* Enable the periodic schedule */
                            usbID->UHPHS_USBCMD |= UHPHS_USBCMD_PSE_Msk;

                            hDriver->operationEnabled = true;
                            hDriver->operationEnableState = DRV_USB_EHCI_OPERATION_ENABLE_IDLE;
                            returnValue = true;
                        }

                        break;

                    case DRV_USB_EHCI_OPERATION_ENABLE_IDLE:
                        /* Operation has been enabled */
                    default:
                        break;
                }
            }
            else
            {
                /* HC is already enabled */
                returnValue = true;
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid handle in OperationEnable function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid instance in OperationEnable function");
    }

    return(returnValue);
}

// ****************************************************************************
/* Function:
    void DRV_USB_EHCI_PortReset(DRV_HANDLE handle, uint8_t port );
    
  Summary:
    Resets the specified root hub port.
    
  Description:
    This function resets the root hub port. The reset duration is defined by
    DRV_USB_EHCI_PORT_RESET_DURATION. The status of the reset signaling can be
    checked using the DRV_USB_EHCI_PortResetIsComplete() function.
    
  Remarks:
    Refer to drv_usb_ehci.h for usage information.
*/

USB_ERROR DRV_USB_EHCI_PortReset(DRV_HANDLE handle, uint8_t nPort)
{
    USB_ERROR returnValue = USB_ERROR_PARAMETER_INVALID;
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);
    DRV_USB_EHCI_OBJ * hDriver = NULL;
    
    if(drvIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBEHCIObj[drvIndex];
        if(hDriver->clientUniqueKey == clientUniqueKey)
        {
            if((nPort < DRV_USB_EHCI_PORT_NUMBERS) && (hDriver->ports[nPort].selected))
            {
                returnValue = USB_ERROR_NONE;

                if(!hDriver->ports[nPort].isResetting)
                {
                    /* Start port resetting only if the port is not already
                     * being reset. The actual reset takes place in the
                     * _DRV_USB_EHCI_PortsTask function. */
                    hDriver->ports[nPort].isResetting = true;
                }
                else
                {
                    SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Reset already in progress");
                }
            }
            else
            {
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid port number or port number not selected");
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid handle in PortReset function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid Driver Instance in PortReset function");
    }

    return(returnValue);
}

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

  Remarks:
    Refer to drv_usb_ehci.h for usage information.
*/

USB_SPEED DRV_USB_EHCI_PortSpeedGet(DRV_HANDLE handle, uint8_t nPort)
{
    USB_SPEED returnValue = USB_SPEED_ERROR;
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);
    volatile uint32_t * portSC = NULL;
    DRV_USB_EHCI_OBJ * hDriver = NULL;
    
    DRV_USB_EHCI_PORT_OBJ * ports = NULL;

    if(drvIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBEHCIObj[drvIndex];
        portSC = (volatile uint32_t *)((uint32_t)hDriver->usbID + UHPHS_PORTSC_REG);
        ports = &hDriver->ports[0];

        if(hDriver->clientUniqueKey == clientUniqueKey)
        {
            if((nPort < DRV_USB_EHCI_PORT_NUMBERS) && (ports[nPort].selected))
            {
                if((portSC[nPort] & UHPHS_PORTSC_N_PED_Msk) != 0)
                {
                    /* This indicates that port is enabled and that can happen
                     * only when a high speed device is connected. */
                    returnValue = USB_SPEED_HIGH;
                }
            }
            else
            {
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid port number or port number not selected");
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid handle in Port Speed Get function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid Driver Instance in Port Speed Get function");
    }

    return(returnValue);
}

// ****************************************************************************
/* Function:
    void DRV_USB_EHCI_PortResetIsComplete
    (
        DRV_HANDLE handle,
        uint8_t port
    );

  Summary:
    Returns true if the root hub has completed the port reset operation.

  Description:
    This function returns true if the port reset operation has completed. It
    should be called after the DRV_USB_HOST_ROOT_HUB_PortReset() function to
    check if the reset operation has completed.

  Remarks:
    Refer to drv_usb_ehci.h for usage information.
 */
bool DRV_USB_EHCI_PortResetIsComplete
(
    DRV_HANDLE handle,
    uint8_t nPort
)
{
    bool returnValue = false;
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);
    DRV_USB_EHCI_OBJ * hDriver = NULL;

    if(drvIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBEHCIObj[drvIndex];

        if(hDriver->clientUniqueKey == clientUniqueKey)
        {
            if((nPort < DRV_USB_EHCI_PORT_NUMBERS) && (hDriver->ports[nPort].selected))
            {
                /* The isResetting flag is updated in the
                 * _DRV_USB_EHCI_PortsTask() function. That function will clear
                 * this flag when the reset is complete. */
                if(!hDriver->ports[nPort].isResetting)
                {
                    returnValue = true;
                }
            }
            else
            {
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid port number or port number not selected");
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid handle in PortReset function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid Driver Instance in PortReset function");
    }

    return(returnValue);
}

// ****************************************************************************
/* Function:
    USB_ERROR DRV_USB_EHCI_PortResume(DRV_HANDLE handle, uint8_t port );

  Summary:
    Resumes the specified root hub port.

  Description:
    This function resumes the root hub. The resume duration is defined by
    DRV_USB_EHCI_RESUME_DURATION. The status of the resume signaling can
    be checked using the DRV_USB_EHCI_PortResumeIsComplete() function.

  Remarks:
    None.
*/

USB_ERROR DRV_USB_EHCI_PortResume(DRV_HANDLE handle, uint8_t port)
{
    /* The functionality is yet to be implemented. */
    return(USB_ERROR_NONE);
}

// ****************************************************************************
/* Function:
    void DRV_USB_EHCI_PortSuspend(DRV_HANDLE handle, uint8_t port );

  Summary:
    Suspends the specified root hub port.

  Description:
    This function suspends the root hub port.

  Remarks:
    None.
*/

USB_ERROR DRV_USB_EHCI_PortSuspend(DRV_HANDLE handle, uint8_t port)
{
    /* The functionality is yet to be implemented. */
    return (USB_ERROR_NONE);
}

// ****************************************************************************
/* Function:
    USB_SPEED DRV_USB_EHCI_BusSpeedGet(DRV_HANDLE handle);

  Summary:
    Returns the speed at which the bus to which this root hub is connected is
    operating.

  Description:
    This function returns the speed at which the bus to which this root hub is
    connected is operating.

 Remarks:
    None.
*/

USB_SPEED DRV_USB_EHCI_BusSpeedGet(DRV_HANDLE handle)
{
    /* Validate the handle */
    USB_SPEED returnValue = USB_SPEED_ERROR;
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);

    if(drvIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
    {
        if(gDrvUSBEHCIObj[drvIndex].clientUniqueKey == clientUniqueKey)
        {
            /* The EHCI bus speed will always be high */
            returnValue = USB_SPEED_HIGH;
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid handle in BusSpeedGet function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid instance in BusSpeedGet function");
    }

    return(returnValue);
}

// ****************************************************************************
/* Function:
    uint32_t DRV_USB_EHCI_MaximumCurrentGet(DRV_HANDLE);

  Summary:
    Returns the maximum amount of current that this root hub can provide on the
    bus.

  Description:
    This function returns the maximum amount of current that this root hub can
    provide on the bus.

  Remarks:
    Refer to drv_usb_ehci.h for usage information.
*/

uint32_t DRV_USB_EHCI_MaximumCurrentGet(DRV_HANDLE handle)
{
    uint32_t returnValue = 0;
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);

    if(drvIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
    {
        if(gDrvUSBEHCIObj[drvIndex].clientUniqueKey == clientUniqueKey)
        {
            returnValue = gDrvUSBEHCIObj[drvIndex].rootHubAvailableCurrent;
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid handle in MaximumCurrentGet function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid instance in MaximumCurrentGet function");
    }

    return(returnValue);
}

// ****************************************************************************
/* Function:
    uint8_t DRV_USB_EHCI_PortNumbersGet(DRV_HANDLE handle);

  Summary:
    Returns the number of ports this root hub contains.

  Description:
    This function returns the number of ports that this root hub contains.

  Remarks:
    None.
*/

uint8_t DRV_USB_EHCI_PortNumbersGet(DRV_HANDLE handle)
{
    uint8_t returnValue = 0;
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);

    if(drvIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
    {
        if(gDrvUSBEHCIObj[drvIndex].clientUniqueKey == clientUniqueKey)
        {
            /* The number of ports in the controller is contained in the N_CC of
             * the HCSPARAMS register. */

            returnValue = (uint8_t)((gDrvUSBEHCIObj[drvIndex].usbID->UHPHS_HCSPARAMS & UHPHS_HCSPARAMS_N_PCC_Msk) >> UHPHS_HCSPARAMS_N_PCC_Pos);
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid handle in PortNumbersGet function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid instance in PortNumbersGet function");
    }

    return(returnValue);
}

// ****************************************************************************
/* Function:
    void DRV_USB_EHCI_RootHubInitialize
    (
        DRV_HANDLE handle,
        USB_HOST_DEVICE_INFO usbHostDeviceInfo,
    )

  Summary:
    This function instantiates the root hub driver.

  Description:
    This function initializes the root hub driver. It is called by the host
    layer at the time of processing root hub devices. The host layer assigns a
    USB_HOST_DEVICE_INFO reference to this root hub driver. This identifies the
    relationship between the root hub and the host layer.

  Remarks:
    None.
*/

void DRV_USB_EHCI_RootHubInitialize
(
    DRV_HANDLE handle,
    USB_HOST_DEVICE_OBJ_HANDLE usbHostDeviceInfo
)
{
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);

    if(drvIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
    {
        if(gDrvUSBEHCIObj[drvIndex].clientUniqueKey == clientUniqueKey)
        {
            /* Save the reference assigned by the host layer */
            gDrvUSBEHCIObj[drvIndex].usbHostDeviceInfo = usbHostDeviceInfo;
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid handle in RootHubInitialize function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid instance in RootHubInitialize function");
    }
}

// ****************************************************************************
/* Function:
    void DRV_USB_EHCI_EndpointToggleClear
    (
        DRV_HANDLE client,
        USB_ENDPOINT endpointAndDirection
    )

  Summary:
    Facilitates in resetting of endpoint data toggle to 0 for Non Control
    endpoints.

  Description:
    Facilitates in resetting of endpoint data toggle to 0 for Non Control
    endpoints.

  Remarks:
    Refer to drv_usb_ehci.h for usage information.
*/

void DRV_USB_EHCI_EndpointToggleClear
(
    DRV_USB_EHCI_PIPE_HANDLE hPipe
)
{
    uint16_t clientUniqueKey = (uint16_t)((hPipe & 0xFFFF0000) >> 16);
    uint16_t pipeObjIndex = (uint16_t)(hPipe & 0xFF);
    int drvIndex = (int)((hPipe & 0xFF00) >> 8);
    DRV_USB_EHCI_QH * pipe = NULL;
    DRV_USB_EHCI_OBJ * hDriver = NULL;

    if(pipeObjIndex < USB_HOST_PIPES_NUMBER)
    {
        if(drvIndex < DRV_USB_EHCI_INSTANCES_NUMBER)
        {
            /* Get the pointer to the pipe object from the driver instance
             * object. */
            hDriver = &gDrvUSBEHCIObj[drvIndex];
            pipe = &hDriver->queueHeads[pipeObjIndex];
            
            if((pipe->clientUniqueKey == clientUniqueKey) && (pipe->pipeClosingState == DRV_USB_EHCI_PIPE_CLOSE_IDLE))
            {
                pipe->qH.qTDToken.dt = 0;
            }
            else
            {
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid pipe handle in Endpoint Toggle Clear");
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid driver index in Endpoint Toggle Clear");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nEHCI Driver: Invalid Pipe index in Endpoint Toggle Clear");
    }
}

// ****************************************************************************
/* Function:
    void DRV_USB_EHCI_Tasks_ISR(SYS_MODULE_OBJ moduleObj);

  Summary:
    Interrupt handler for the EHCI controller.

  Description:
    Interrupt handler for the EHCI controller.

  Remarks:
    This is a local function and should not be called directly by the
    applications.
*/

void DRV_USB_EHCI_Tasks_ISR(SYS_MODULE_OBJ moduleObj)
{
    /* EHCI Driver Interrupt routine */

    DRV_USB_EHCI_OBJ * hDriver = NULL;
    uint32_t index = (uint32_t)(moduleObj);
    hDriver = &gDrvUSBEHCIObj[index];
    volatile uhphs_registers_t * usbID = NULL;

    /* Set the Interrupt Context flag to let the downstream functions know that
     * driver is currently in an interrupt context. */
    hDriver->inInterruptContext = true;
    usbID = hDriver->usbID;

    /* Read the status register and then clear it. Writing a 1 will clear the
     * status bit. */
    uint32_t usbsts = usbID->UHPHS_USBSTS;
    usbID->UHPHS_USBSTS = usbsts;
    usbsts &= (usbID->UHPHS_USBINTR & 0x3F);

    if((usbsts & UHPHS_USBSTS_IAA_Msk) == UHPHS_USBSTS_IAA_Msk) 
    {
        /* Handle the Interrupt on Async Advance Interrupt here */
    }

    if((usbsts & UHPHS_USBSTS_HSE_Msk) == UHPHS_USBSTS_HSE_Msk) 
    {
        /* Handle the Host Error */

    }

    if((usbsts & UHPHS_USBSTS_PCD_Msk) == UHPHS_USBSTS_PCD_Msk) 
    {
        /* Handle the Port Change Detect Interrupt. Check which port has the change
         * detected. */

        volatile uint32_t * portSC = (volatile uint32_t *)((uint32_t)usbID + UHPHS_PORTSC_REG);
        int i = 0;

        for (i = 0; i < DRV_USB_EHCI_PORT_NUMBERS; i ++)
        {
            if(hDriver->ports[i].selected)
            {
                /* This means this port must be processed */
                if((portSC[i] & UHPHS_PORTSC_N_CSC_Msk) == UHPHS_PORTSC_N_CSC_Msk)
                {
                    /* There has been a change in the connection status. Check
                     * current status. */

                    if((portSC[i] & UHPHS_PORTSC_N_CCS_Msk) == 0)
                    {
                        /* Device is not present */
                        if (hDriver->ports[i].portAttachState == DRV_USB_EHCI_PORT_ATTACH_STATE_WAITING_FOR_ATTACH)
                        {
                            /* We could have got the detach because the
                             * companion controller returned the device back to
                             * the EHCI controller, or if a device was detached
                             * during debounce in which case the port attach
                             * state machine will simply ignore the detach event
                             * */
                        }
                        else if (hDriver->ports[i].portAttachState == DRV_USB_EHCI_PORT_ATTACH_STATE_WAIT_FOR_DETACH)
                        {
                            /* The device was detach and we are ready to handle
                             * detach. Interrupt is disabled here and renabled
                             * in the port tasks routine */
                            USB_HOST_DeviceDenumerate(hDriver->ports[i].attachedDeviceObjHandle);
                            hDriver->ports[i].attachedDeviceObjHandle = USB_HOST_DEVICE_OBJ_HANDLE_INVALID;
                            hDriver->ports[i].interruptHasOccurred = true;
                            usbID->UHPHS_USBINTR &= (~UHPHS_USBINTR_PCIE_Msk);
                        }
                        
                        /* Clear the connect change status detect bit */
                        portSC[i] |= UHPHS_PORTSC_N_CSC_Msk;
                    }
                    else
                    {
                        /* Device is present. Let the port task routine handle
                         * the rest of the of the processing. Disable the port
                         * change detect event. This will enable again from the
                         * port tasks routine. */
                        hDriver->ports[i].interruptHasOccurred = true;
                        usbID->UHPHS_USBINTR &= (~UHPHS_USBINTR_PCIE_Msk);
                    }
                }
            }
        }
    }

    if((usbsts & UHPHS_USBSTS_USBERRINT_Msk) == UHPHS_USBSTS_USBERRINT_Msk) 
    {
        /* Handle the Error interrupt. All handling is performed in the
         * transaction interrupt. */
    }

    if((usbsts & UHPHS_USBSTS_USBINT_Msk) == UHPHS_USBSTS_USBINT_Msk) 
    {
        /* This is the USB Transaction Interrupt. Find out which the pipe on the
         * transaction has completed. We iterate through each pipe. If the qTD
         * active bit is clear, then we know that we have a transaction
         * complete. */
        DRV_USB_EHCI_QH * pipe = NULL;
        int i = 0;

        for(i = 0; i < USB_HOST_PIPES_NUMBER; i ++)
        {
            pipe = &hDriver->queueHeads[i];

            if((pipe->inUse) && (pipe->currentQTD != NULL))
            {
                if(pipe->pipeType == USB_TRANSFER_TYPE_CONTROL)
                {
                    /* Control transfers use a multi control transfer QTD. */
                    DRV_USB_EHCI_CONTROL_TRANSFER_QTD * currentQTD = (DRV_USB_EHCI_CONTROL_TRANSFER_QTD *)pipe->currentQTD;
                    if(currentQTD->handshakeQTD.qTDToken.active == 0)
                    {
                        pipe->queueHandler(pipe);
                    }
                }
                else
                {
                    /* Bulk and Interrupt transfers */
                    DRV_USB_EHCI_QTD * currentQTD = pipe->currentQTD;
                    if(currentQTD->qTD.qTDToken.active == 0)
                    {
                        pipe->queueHandler(pipe);
                    }
                }
            }
        }
    }

    hDriver->inInterruptContext = false;
}


// ****************************************************************************
/* Function:
    void UHPHS_Handler(void);

  Summary:
    General UHPHS Interrupt Handler.

  Description:
    The function is called when there is a UHPHS Interrupt.

  Remarks:
    This is a local function and should not be called directly by the
    applications.
*/

void UHPHS_Handler(void)
{
    DRV_USB_EHCI_Tasks_ISR(sysObj.drvUSBEHCIObject);
    DRV_USB_OHCI_Tasks_ISR(sysObj.drvUSBOHCIObject);
}





