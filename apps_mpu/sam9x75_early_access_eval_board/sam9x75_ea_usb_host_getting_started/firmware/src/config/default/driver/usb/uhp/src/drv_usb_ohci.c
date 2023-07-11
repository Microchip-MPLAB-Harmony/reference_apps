/*******************************************************************************
   USB OHCI Driver Routines

   Company:
    Microchip Technology Inc.

   File Name:
    drv_usb_ohci.c

   Summary:
    USB OHCI Driver Routines.

   Description:
    This file contains the implementation of the OHCI driver. It should be 
    included in the project is OHCI support is required.
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

#include "driver/usb/uhp/src/drv_usb_ohci_local.h"

// *****************************************************************************
// *****************************************************************************
// Section: OHCI Driver Variables and data structures
// *****************************************************************************
// *****************************************************************************

/*****************************************
 *  The Driver Hardware Instance Object.
 *****************************************/
DRV_USB_OHCI_OBJ gDrvUSBOHCIObj[DRV_USB_OHCI_INSTANCES_NUMBER];

/********************************************************
 * Arrays required by the OHCI driver. Endpoint
 * descriptors serve both control and non-control
 * endpoints. There is a seperate set of transfer
 * descriptors and transfer buffers for control
 * and non control transfers.
 ********************************************************/
__ALIGNED(256) _DRV_USB_OHCI_NON_CACHED USB_OHCI_HCCA gDrvUSBOHCIHCCA[DRV_USB_OHCI_INSTANCES_NUMBER];
__ALIGNED(16) _DRV_USB_OHCI_NON_CACHED DRV_USB_OHCI_ED gDrvUSBOHCIEndpointDescriptors[DRV_USB_OHCI_INSTANCES_NUMBER][USB_HOST_PIPES_NUMBER];
__ALIGNED(16) _DRV_USB_OHCI_NON_CACHED DRV_USB_OHCI_TD gDrvUSBOHCITransferDescriptor[DRV_USB_OHCI_INSTANCES_NUMBER][DRV_USB_OHCI_TRANSFERS_NUMBER];
__ALIGNED(64) _DRV_USB_OHCI_NON_CACHED DRV_USB_OHCI_CONTROL_TD gDrvUSBOHCIControlTransferDescriptor[DRV_USB_OHCI_INSTANCES_NUMBER][DRV_USB_OHCI_TRANSFERS_NUMBER];
_DRV_USB_OHCI_NON_CACHED uint8_t gDrvUSBOHCITransferBuffer[DRV_USB_OHCI_INSTANCES_NUMBER][DRV_USB_OHCI_TRANSFERS_NUMBER][DRV_USB_OHCI_TRANSFER_BUFFER_SIZE];
_DRV_USB_OHCI_NON_CACHED uint8_t gDrvUSBOHCIControlTransferBuffer[DRV_USB_OHCI_INSTANCES_NUMBER][DRV_USB_OHCI_TRANSFERS_NUMBER][DRV_USB_OHCI_CONTROL_TRANSFER_BUFFER_SIZE];

/***********************************
 * Driver Host Common Interface
 ***********************************/

DRV_USB_HOST_INTERFACE gDrvUSBOHCIInterface =
{
    .open = DRV_USB_OHCI_Open,
    .close = DRV_USB_OHCI_Close,
    .eventHandlerSet = NULL,
    .hostIRPSubmit = DRV_USB_OHCI_IRPSubmit,
    .hostIRPCancel = DRV_USB_OHCI_IRPCancel,
    .hostPipeSetup = DRV_USB_OHCI_PipeSetup,
    .hostPipeClose = DRV_USB_OHCI_PipeClose,
    .endpointToggleClear = DRV_USB_OHCI_EndpointToggleClear,
    .hostEventsDisable = DRV_USB_OHCI_EventsDisable,
    .hostEventsEnable = DRV_USB_OHCI_EventsEnable,
    .rootHubInterface.rootHubPortInterface.hubPortReset = DRV_USB_OHCI_PortReset,
    .rootHubInterface.rootHubPortInterface.hubPortSpeedGet = DRV_USB_OHCI_PortSpeedGet,
    .rootHubInterface.rootHubPortInterface.hubPortResetIsComplete = DRV_USB_OHCI_PortResetIsComplete,
    .rootHubInterface.rootHubPortInterface.hubPortSuspend = DRV_USB_OHCI_PortSuspend,
    .rootHubInterface.rootHubPortInterface.hubPortResume = DRV_USB_OHCI_PortResume,
    .rootHubInterface.rootHubMaxCurrentGet = DRV_USB_OHCI_MaximumCurrentGet,
    .rootHubInterface.rootHubPortNumbersGet = DRV_USB_OHCI_PortNumbersGet,
    .rootHubInterface.rootHubSpeedGet = DRV_USB_OHCI_BusSpeedGet,
    .rootHubInterface.rootHubInitialize = DRV_USB_OHCI_RootHubInitialize,
    .rootHubInterface.rootHubOperationEnable = DRV_USB_OHCI_OperationEnable,
    .rootHubInterface.rootHubOperationIsEnabled = DRV_USB_OHCI_OperationIsEnabled,

};

// *****************************************************************************
// *****************************************************************************
// Section: OHCI Driver Local Function Implementations
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void _DRV_USB_OHCI_PeriodicListRemove 
    (
        DRV_USB_OHCI_OBJ * hDriver,
        int slotIndex,
        DRV_USB_OHCI_ED * ED
    )

  Summary:
    This function removes a pipe from the a periodic list slot
   
  Description:
    This function removes a pipe from the a periodic list slot
  
  Remarks:
    This is a local function and should not be called directly by the 
    application.
*/

void _DRV_USB_OHCI_PeriodicListRemove 
(
    DRV_USB_OHCI_OBJ * hDriver,
    int slotIndex,
    DRV_USB_OHCI_ED * edToRemove
)
{
    USB_OHCI_ED * ed = &edToRemove->ed;
    USB_OHCI_ED * currentED = NULL;
    volatile uint32_t * interruptList = hDriver->hcHCCA->hccaInterruptTable;

    if(interruptList[slotIndex] != 0)
    {
        if(interruptList[slotIndex] == (uint32_t)ed)
        {
            /* This means the ED is at the head of the list */
            interruptList[slotIndex] = ed->nextED;
        } 
        else
        {
            /* The ed is not at the head of the list. We have to traverse
             * the list */
            currentED = (USB_OHCI_ED *)(interruptList[slotIndex]);
            while(1)
            {
                if(currentED->nextED == 0)
                {
                    /* We have reached the end of the list */
                    break;
                }
                else if(currentED->nextED == (uint32_t)ed)
                {
                    /* Remove the ed by updating the next pointing */
                    currentED->nextED = ed->nextED;
                    break;
                }
            }
        }
    }
}

// *****************************************************************************
/* Function:
    uint8_t _DRV_USB_OHCI_GetPollingIndex (uint8_t pollingRate)

  Summary:
    Returns the binary exponent corresponding to the specified polling rate.
    
  Description:
    Returns the binary exponent corresponding to the specified polling rate.

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/

uint8_t _DRV_USB_OHCI_GetPollingIndex (uint8_t pollingRate)
{
    uint8_t returnValue = 0;

    if(pollingRate == 1)
    {
        returnValue = 0;
    }
    else
    {
        while ((1 << returnValue) < pollingRate)
        {
            returnValue ++;
        }
    }

    return(returnValue);
}

// *****************************************************************************
/* Function:
    uint16_t _DRV_USB_OHCI_GetUniqueKey (DRV_USB_OHCI_OBJ * hDriver)

  Summary:
    Returns a unique key that is used to create driver and pipe handles.
    
  Description:
    Returns a unique key that is used to create driver and pipe handles.
    Function should be called from an thread safe context.

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/

uint16_t _DRV_USB_OHCI_GetUniqueKey (DRV_USB_OHCI_OBJ * hDriver)
{
    /* This function creates a unique key. It shoudl be called
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
    void _DRV_USB_OHCI_PipeCloseTask(DRV_USB_OHCI_OBJ * hDriver);

  Summary:
    This function handles pipe closures. 
   
  Description:
    This function handles pipe closures. It is called from the main driver task 
    routine.
  
  Remarks:
    This is a local function and should not be called directly by the 
    application.
*/

void _DRV_USB_OHCI_PipeCloseTask(DRV_USB_OHCI_OBJ * hDriver)
{
    DRV_USB_OHCI_ED * pipe = NULL;
    USB_OHCI_ED * ed = NULL;
    USB_OHCI_ED * currentED = NULL;
    DRV_USB_OHCI_TD * td = NULL;
    DRV_USB_OHCI_CONTROL_TD * controlTD = NULL;
    uint8_t pollingRate = 0;
    uint8_t pollingIndex = 0;

    volatile UhpOhci * usbID = hDriver->usbID;
    int i = 0;
    int j = 0;

    pipe = hDriver->endpointDescriptors;

    for(i = 0; i < USB_HOST_PIPES_NUMBER; i++)
    {
        ed = &pipe->ed;
        if(pipe->inUse)
        {
            switch(pipe->pipeClosingState)
            {
                case DRV_USB_OHCI_PIPE_CLOSING_STATE_IDLE:

                    /* Nothing to do in this state */
                    break;

                case DRV_USB_OHCI_PIPE_CLOSING_STATE_CLOSE_REQUESTED:

                    /* Pipe closing has been requested. If another pipe
                     * is already closing, then we should wait for that 
                     * pipe to close */ 
                    if(hDriver->pipeIsClosing == false)
                    {
                        /* This means we can proceed with the pipe closing */
                        hDriver->pipeIsClosing = true;
                        hDriver->sofCount = 0;

                        if((pipe->pipeType == USB_TRANSFER_TYPE_CONTROL) || (pipe->pipeType == USB_TRANSFER_TYPE_BULK))
                        {
                            if(pipe->pipeType == USB_TRANSFER_TYPE_CONTROL)
                            {
                                /* Disable the control list */
                                usbID->UHP_OHCI_HCCONTROL &= (~UHP_OHCI_HCCONTROL_CLE_Msk);
                            }
                            else if(pipe->pipeType == USB_TRANSFER_TYPE_BULK)
                            {
                                /* Disable the bulk list */
                                usbID->UHP_OHCI_HCCONTROL &= (~UHP_OHCI_HCCONTROL_BLE_Msk);
                            }

                        }
                        else if(pipe->pipeType == USB_TRANSFER_TYPE_INTERRUPT)
                        {
                            /* There is no need to disable the Periodic list
                             * while removing an interrupt pipe. The pipe
                             * was already skipped in the pipe close function. */
                            pollingRate = pipe->pollingRate;
                            pollingIndex = _DRV_USB_OHCI_GetPollingIndex(pollingRate);
                            if(pollingRate == 1)
                            {
                                /* Scan through every periodic slot and remove
                                 * the pipe. */
                                for(j = 0; j < 32; j ++)
                                {
                                    _DRV_USB_OHCI_PeriodicListRemove(hDriver, j, pipe);
                                }

                                /* As we are modifying the hDriver object from one thread
                                 * and the pipe open function can be called from another
                                 * thread, we must ensure that the below access is atomic */
                                if(OSAL_MUTEX_Lock(&hDriver->mutex, OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
                                {
                                    /* Decrement the polling rate 1 count. This keeps
                                     * track of the number of polling rate 1 pipes in the 
                                     * periodic list. */
                                    if(hDriver->nextSlotToUse[pollingIndex] != 0)
                                    {
                                        hDriver->nextSlotToUse[pollingIndex] --;
                                    }

                                    OSAL_MUTEX_Unlock(&hDriver->mutex);
                                }
                                else
                                {
                                    SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Could not grab mutex in OHCI Pipe Close Task");
                                }
                            }
                            else
                            {
                                /* In a case where this is not a 1 millisecond polling rate pipe, the
                                 * starting slot where the pipe was inserted is where we should 
                                 * start looking from */
                                for(j = pipe->startSlot; j < 32; j += pollingRate)
                                {
                                    _DRV_USB_OHCI_PeriodicListRemove(hDriver, j, pipe);
                                }

                                /* We do not change the nextSlotToUse counts for these intervals.
                                 * These counts will increment and then roll over to 0 */
                            }
                        }

                        /* Wait for the next SOF */
                        pipe->pipeClosingState = DRV_USB_OHCI_PIPE_CLOSING_STATE_WAIT_SOF;
                        usbID->UHP_OHCI_HCINTERRUPTSTATUS = UHP_OHCI_HCINTERRUPTSTATUS_SF_Msk;
                        usbID->UHP_OHCI_HCINTERRUPTENABLE = UHP_OHCI_HCINTERRUPTENABLE_SF_Msk;
                    }
                    
                    break;

                case DRV_USB_OHCI_PIPE_CLOSING_STATE_WAIT_SOF:

                    /* The sofCount is incremented in the SOF interrupt */
                    if(hDriver->sofCount > 1)
                    {
                        /* Disable the SOF interrupt */
                        usbID->UHP_OHCI_HCINTERRUPTDISABLE = UHP_OHCI_HCINTERRUPTDISABLE_SF_Msk;

                        if(pipe->pipeType == USB_TRANSFER_TYPE_CONTROL)
                        {
                            /* We can now remove this ED from the list */
                            if(usbID->UHP_OHCI_HCCONTROLHEADED == (uint32_t)(ed))
                            {
                                /* This means the pipe is at the head of the list
                                 * Update the list head to point to the  */
                                usbID->UHP_OHCI_HCCONTROLHEADED = ed->nextED;
                            }
                            else
                            {
                                /* We have to look for the ED in the list. Start with 
                                 * the head. We know the head ed is not the ed because
                                 * that would have been handled in the if clause 
                                 * of this condition */
                                currentED = (USB_OHCI_ED *)(usbID->UHP_OHCI_HCCONTROLHEADED);
                                while(currentED != NULL)
                                {
                                    if(currentED->nextED == (uint32_t)ed)
                                    {
                                        /* We have found our ED. Set the current
                                         * ed next field to the next ED of our ED */
                                        currentED->nextED = (uint32_t)ed->nextED;
                                    } 
                                    else
                                    {
                                        /* Advance the current ED pointer */
                                        currentED = (USB_OHCI_ED *)(currentED->nextED);
                                    }
                                }
                            }

                            /* At this point, ED has been removed from the list. We can 
                             * reenable the control list. As specified in section 5.2.7.1.2
                             * of the specification, we should set the HcControlCurrentED
                             * to 0 before re-enabling the list */

                            usbID->UHP_OHCI_HCCONTROLCURRENTED = 0;
                            usbID->UHP_OHCI_HCCONTROL |= UHP_OHCI_HCCONTROL_CLE_Msk;

                            /* Release the allocate place QH for this ED */
                            controlTD = (DRV_USB_OHCI_CONTROL_TD *)(ed->tailP);
                            controlTD->inUse = false;
                        }
                        else if(pipe->pipeType == USB_TRANSFER_TYPE_BULK)
                        {
                            /* We can now remove the ED from the bulk list */
                            if(usbID->UHP_OHCI_HCBULKHEADED == (uint32_t)ed)
                            {
                                /* This means the pipe is at the head of the list
                                 * Update the list head to point to the next ED */
                                usbID->UHP_OHCI_HCBULKHEADED = ed->nextED;
                            }
                            else
                            {
                                /* We have to look for the ED in the list. Start with 
                                 * the head. We know the head ed is not the ed because
                                 * that would have been handled in the if clause 
                                 * of this condition */
                                currentED = (USB_OHCI_ED *)(usbID->UHP_OHCI_HCBULKHEADED);
                                while(currentED != NULL)
                                {
                                    if(currentED->nextED == (uint32_t)ed)
                                    {
                                        /* We have found our ED. Set the current
                                         * ed next field to the next ED of our ED */
                                        currentED->nextED = (uint32_t)ed->nextED;
                                    } 
                                    else
                                    {
                                        /* Advance the current ED pointer */
                                        currentED = (USB_OHCI_ED *)(currentED->nextED);
                                    }
                                }
                            }

                            /* At this point, ED has been removed from the list. We can 
                             * reenable the control list. As specified in section 5.2.7.1.2
                             * of the specification, we should set the HcBulkCurrentED
                             * to 0 before re-enabling the list */

                            usbID->UHP_OHCI_HCBULKCURRENTED = 0;
                            usbID->UHP_OHCI_HCCONTROL |= UHP_OHCI_HCCONTROL_BLE_Msk;

                            /* Release the allocate place QH for this ED */
                            td = (DRV_USB_OHCI_TD *)(ed->tailP);
                            td->inUse = false;
                            pipe->currentTD->inUse = false;
                        }
                        else if (pipe->pipeType == USB_TRANSFER_TYPE_INTERRUPT)
                        {
                            /* For interrupt pipes we dont have to do anything.
                             * The pipe at this stage has alread been removed 
                             * from the periodic list. We only need to release 
                             * the tail pipe TD */

                            /* Release the allocate place QH for this ED */
                            td = (DRV_USB_OHCI_TD *)(ed->tailP);
                            td->inUse = false;
                            pipe->currentTD->inUse = false;
                        }

                        /* Finally realease the pipe object */
                        pipe->inUse = false;

                        /* Driver has closed the pipe */
                        hDriver->pipeIsClosing = false;
                    }

                    break;

                default:
                    break;
            }
        }

        /* Move on to the next pipe */
        pipe ++;
    }
}

// *****************************************************************************
/* Function:
    void _DRV_USB_OHCI_PortsTask(DRV_USB_OHCI_OBJ * hDriver)

  Summary:
    This function checks each for status change and handles these changes.
    
  Description:
    This function checks each for status change and handles these changes. The
    function is called from the driver tasks routine.

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/

void _DRV_USB_OHCI_PortsTask(DRV_USB_OHCI_OBJ * hDriver)
{
    /* This function checks the status of ports registers */

    volatile UhpOhci * usbID = hDriver->usbID;
    DRV_USB_OHCI_PORT_OBJ * port = NULL;
    volatile uint32_t * ohciPort = &usbID->UHP_OHCI_HCRHPORTSTATUS0;
    int i = 0;
    bool interruptWasEnabled = false;

    for(i = 0; i < DRV_USB_OHCI_PORTS_NUMBER; i ++)
    {
        port = &hDriver->ports[i];

        /* Process the port if the port has been selected */
        if(port->selected)
        {
            if(port->disableThisPort)
            {
                /* The disableThisPort flag is set in the ISR
                 * if the root hub has disable the port or if 
                 * an over current condition was detected on
                 * the port. */

                port->disableThisPort = false;
                port->portSpeed = USB_SPEED_ERROR;

                if(port->timerHandle != SYS_TIME_HANDLE_INVALID)
                {
                    /* Stop any ongoing delay delay */
                    SYS_TIME_TimerDestroy(port[i].timerHandle);
                    port->timerHandle = SYS_TIME_HANDLE_INVALID;
                }

                if (OSAL_MUTEX_Lock(&hDriver->mutex, OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
                {
                    /* We have to disable the interrupt before changing state as
                     * state variable is updated in the ISR */
                    interruptWasEnabled = SYS_INT_SourceDisable(hDriver->interruptSource);
                    port->portAttachState = DRV_USB_OHCI_PORT_ATTACH_STATE_WAITING_FOR_ATTACH;
                    
                    if(interruptWasEnabled)
                    {
                        SYS_INT_SourceEnable(hDriver->interruptSource);
                    }

                    OSAL_MUTEX_Unlock(&hDriver->mutex);
                }
            }

            switch(port->portAttachState)
            {
                case DRV_USB_OHCI_PORT_ATTACH_STATE_WAITING_FOR_ATTACH:

                    /* Nothing to do in this state. If a device is attached, 
                     * this will be tracked in the ISR and the state will 
                     * move to the next state in the interrupt. */
                    break;

                case DRV_USB_OHCI_PORT_ATTACH_STATE_START_ATTACH_DEBOUNCE:

                    /* Device has been attached. Start the debounce */
                    if(SYS_TIME_DelayMS(DRV_USB_OHCI_ATTACH_DEBOUNCE_DURATION, &port->timerHandle) == SYS_TIME_SUCCESS)
                    {
                        port->portAttachState = DRV_USB_OHCI_PORT_ATTACH_STATE_WAIT_DEBOUNCE;
                    }

                    break;

                case DRV_USB_OHCI_PORT_ATTACH_STATE_WAIT_DEBOUNCE:

                    /* Check if the deboucen time has completed */
                    if(SYS_TIME_DelayIsComplete(port->timerHandle))
                    {
                        port->timerHandle = SYS_TIME_HANDLE_INVALID;

                        /* Check if the device is still attached */
                        if(ohciPort[i] & UHP_OHCI_HCRHPORTSTATUS2_CCS_Msk)
                        {
                            /* Device is still attached. Get the device speed,
                             * and enable the port. Then we enumerate the 
                             * device. */
                            
                            port->portSpeed = USB_SPEED_FULL;
                            if(ohciPort[i] & UHP_OHCI_HCRHPORTSTATUS2_LSDA_Msk)
                            {
                                port->portSpeed = USB_SPEED_LOW;
                            }

                            /* Enabled the port */
                            ohciPort[i] = UHP_OHCI_HCRHPORTSTATUS2_PES_Msk;
                            port->portAttachState = DRV_USB_OHCI_PORT_ATTACH_STATE_POST_ENABLE_DELAY;
                        }
                        else
                        {
                            /* Device is not attached */
                            port->portAttachState = DRV_USB_OHCI_PORT_ATTACH_STATE_WAITING_FOR_ATTACH;
                        }
                    }

                    break;

                case DRV_USB_OHCI_PORT_ATTACH_STATE_POST_ENABLE_DELAY:

                    /* Wait for some time after the port has been enabled */
                    if(SYS_TIME_DelayMS(DRV_USB_OHCI_POST_PORT_ENABLE_DELAY, &port->timerHandle) == SYS_TIME_SUCCESS)
                    {
                        port->portAttachState = DRV_USB_OHCI_PORT_ATTACH_STATE_POST_ENABLE_DELAY_WAIT;
                    }
                    break;

                case DRV_USB_OHCI_PORT_ATTACH_STATE_POST_ENABLE_DELAY_WAIT:

                    if(SYS_TIME_DelayIsComplete(port->timerHandle))
                    {
                            /* Enumerate the device */
                            port->attachedDeviceObjHandle = USB_HOST_DeviceEnumerate(hDriver->usbHostDeviceInfo, i);

                            /* We are now waiting for a device detach */
                            port->portAttachState = DRV_USB_OHCI_PORT_ATTACH_STATE_WAIT_FOR_DETACH;
                    }

                    break;

                case DRV_USB_OHCI_PORT_ATTACH_STATE_WAIT_FOR_DETACH:

                    /* Nothing to in this state. The ISR will detach the device
                     * if the port is in this state and a detach is detected. */

                    break;

                default:
                    break;
            }
        }        
    }
}

// *****************************************************************************
/* Function:
    size_t _DRV_USB_OHCI_DataTransferTD
    (
        DRV_USB_OHCI_CONTROL_TD * transfer
    )

  Summary:
    Sets up the setup, data and handshake stage TDs of the control transfer.
    
  Description:
    Sets up the setup, data and handshake stage TDs of the control transfer.

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/

size_t _DRV_USB_OHCI_DataTransferTD
(
    DRV_USB_OHCI_TD * transfer,
    USB_DATA_DIRECTION direction
)
{
    USB_OHCI_TD * td = &transfer->td;
    USB_HOST_IRP_LOCAL * irp = transfer->irp;
    uint32_t nBytes = 0;
    uint8_t * startAddress = NULL;
    
    memset(td, 0, sizeof(USB_OHCI_TD));

    /* Configure the TD */
    td->r = 1;

    /* We will not configure the TD direction as the direction is defined 
     * the ED */

    td->di = USB_OHCI_TD_DELAY_INTERRUPT_0;
    td->t = USB_OHCI_TD_USE_ED_TOGGLE_VALUE|USB_OHCI_TD_TOGGLE_VALUE(0);
    
    /* Check the amount of pending data */
    nBytes = irp->size - irp->completedBytes;

    /* cap the mount of data that we can send */
    nBytes = (nBytes >= DRV_USB_OHCI_TRANSFER_BUFFER_SIZE) ? DRV_USB_OHCI_TRANSFER_BUFFER_SIZE : (nBytes);
    startAddress = (uint8_t *)(irp->data) + irp->completedBytes;

    if(direction == USB_DATA_DIRECTION_HOST_TO_DEVICE)
    {
        /* Move data from the user buffer to the driver buffer */
        memcpy(transfer->transferBuffer, startAddress, nBytes);
    }

    td->cbp = (uint32_t)(transfer->transferBuffer);
    td->be = td->cbp + nBytes - 1;

    return(nBytes);
}

// *****************************************************************************
/* Function:
    size_t _DRV_USB_OHCI_ControlTransferTD
    (
        DRV_USB_OHCI_CONTROL_TD * transfer
    )

  Summary:
    Sets up the setup, data and handshake stage TDs of the control transfer.
    
  Description:
    Sets up the setup, data and handshake stage TDs of the control transfer.

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/

size_t _DRV_USB_OHCI_ControlTransferTD
(
    DRV_USB_OHCI_CONTROL_TD * transfer
)
{
    /* Get pointers to the TDs */
    USB_OHCI_TD * setupTD = &transfer->setupTD;
    USB_OHCI_TD * dataTD = &transfer->dataTD;
    USB_OHCI_TD * handshakeTD = &transfer->handshakeTD;
    USB_HOST_IRP_LOCAL * irp = transfer->irp;
    USB_DATA_DIRECTION direction = USB_DATA_DIRECTION_DEVICE_TO_HOST;
    size_t nBytes = 0;

    /* Get the direction of the control transfer */
    direction = ((((uint8_t*)irp->setup)[0] & 0x80) == 0) ? USB_DATA_DIRECTION_HOST_TO_DEVICE: direction;

    memset(setupTD, 0, sizeof(USB_OHCI_TD));
    memset(dataTD, 0, sizeof(USB_OHCI_TD));
    memset(handshakeTD, 0, sizeof(USB_OHCI_TD));

    /* Transfer setup data from user to driver buffer */
    memcpy(transfer->setupBuffer, irp->setup, 8);

    /* Prepare the setup transfer descriptor. We dont need to be
     * interrupt for a setup stage. */
    setupTD->r = 1;
    setupTD->dp = USB_OHCI_TD_PID_TYPE_SETUP; 
    setupTD->di = USB_OHCI_TD_DELAY_INTERRUPT_NEVER;
    setupTD->t = USB_OHCI_TD_USE_TD_TOGGLE_VALUE|USB_OHCI_TD_TOGGLE_VALUE(0);
    setupTD->cbp = (uint32_t)&transfer->setupBuffer;
    setupTD->be = setupTD->cbp + 7;

    /* Check if a data stage is required and if so prepare the data TD */
    if((irp->data != NULL) && (irp->size != 0))
    {
        /* We have to cap control transfer length to the configured buffer size */
        nBytes = (irp->size > DRV_USB_OHCI_CONTROL_TRANSFER_BUFFER_SIZE) ?  DRV_USB_OHCI_CONTROL_TRANSFER_BUFFER_SIZE : irp->size;

        dataTD->r = 0;
        dataTD->dp = USB_OHCI_TD_PID_TYPE_IN;
        if(direction == USB_DATA_DIRECTION_HOST_TO_DEVICE)
        {
            /* This is a control write transfer. Copy data from
             * the user buffer to the driver buffer */
            memcpy(transfer->dataBuffer, irp->data, nBytes);
            dataTD->dp = USB_OHCI_TD_PID_TYPE_OUT;
        }
        
        dataTD->di = USB_OHCI_TD_DELAY_INTERRUPT_NEVER;
        dataTD->t = USB_OHCI_TD_USE_TD_TOGGLE_VALUE|USB_OHCI_TD_TOGGLE_VALUE(1);
        dataTD->cbp = (uint32_t)transfer->dataBuffer;
        dataTD->be = dataTD->cbp + nBytes - 1;

        /* Setup the next pointers. After setup should be data
         * and after data should be handshake */
        dataTD->nextTD = (uint32_t)&transfer->handshakeTD;
        setupTD->nextTD = (uint32_t)&transfer->dataTD;
    }
    else
    {
        /* No data stage required. Jump directly to handshake 
         * after setup */
        setupTD->nextTD = (uint32_t)&transfer->handshakeTD;
    }

    handshakeTD->r = 0;
    handshakeTD->dp = USB_OHCI_TD_PID_TYPE_OUT;

    /* Check the transfer direction */
    if(direction == USB_DATA_DIRECTION_HOST_TO_DEVICE)
    {
        /* Data moves host to device. So handshake
         * moves from device to host. */
        handshakeTD->dp = USB_OHCI_TD_PID_TYPE_IN;
    }

    handshakeTD->di = USB_OHCI_TD_DELAY_INTERRUPT_0;
    handshakeTD->t = USB_OHCI_TD_USE_TD_TOGGLE_VALUE|USB_OHCI_TD_TOGGLE_VALUE(1);
    handshakeTD->cbp = 0;
    handshakeTD->be = 0;

    return(nBytes);
}

// *****************************************************************************
/* Function:
    void _DRV_USB_OHCI_DataTransferProcess(void * pipeObj, void * driver)

  Summary:
    This function is called when a pipe has completed some work.
    
  Description:
    This function is called when a pipe has completed some work.

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/

void _DRV_USB_OHCI_DataTransferProcess(void * pipeObj, void * driver)
{
    DRV_USB_OHCI_ED * pipe = (DRV_USB_OHCI_ED *)pipeObj;
    DRV_USB_OHCI_OBJ * hDriver = (DRV_USB_OHCI_OBJ *)driver;
    DRV_USB_OHCI_TD * currentTD = (DRV_USB_OHCI_TD *)pipe->currentTD;
    DRV_USB_OHCI_TD * placeHolderTD = NULL;
    DRV_USB_OHCI_TD * transfer = NULL;
    USB_OHCI_TD * td = &currentTD->td;
    USB_HOST_IRP_LOCAL * irp = currentTD->irp;
    USB_OHCI_ED * ed = &pipe->ed;
    uint32_t bytesTransferred = 0;
    bool pipeWasEmpty = false;
    volatile UhpOhci * usbID = ((DRV_USB_OHCI_OBJ *)hDriver)->usbID;
    bool endIRP = false;

    if(irp->tempState == DRV_USB_OHCI_IRP_STATE_ABORTED)
    {
        /* This means the application has cancelled this IRP. We
         * simply end the IRP */
        irp->status = USB_HOST_IRP_STATUS_ABORTED;
    }
    else
    {
        irp->status = USB_HOST_IRP_STATUS_COMPLETED;

        /* If the ED has an error, then check each TD in the IRP
         * for the error */
        if(ed->h == 1)
        {
            /* Start by checking the SETUP packet and then work 
             * our way through the rest of the control transfer
             * TDs */

            if((td->cc != USB_OHCI_CC_NO_ERROR) && (td->cc != USB_OHCI_CC_DATA_UNDERRUN))
            {
                /* Generally a data error unless these was a stall */
                irp->status = USB_HOST_IRP_STATUS_ERROR_DATA;

                /* Wsa the packet stalled */
                if(td->cc == USB_OHCI_CC_STALL)
                {
                    irp->status = USB_HOST_IRP_STATUS_ERROR_STALL;
                }
            }

            ed->h = 0;
            endIRP = true;
        }
        else
        {
            /* There was no error. Calculate the actual transfer size */
            bytesTransferred = (td->cbp == 0) ? irp->scheduledBytes : (td->cbp - (uint32_t)(currentTD->transferBuffer));

            if(pipe->direction  == USB_DATA_DIRECTION_DEVICE_TO_HOST)
            {
                /* We have received data from the device. Copy this data
                 * from the driver buffer to the user buffer */

                memcpy((uint8_t *)irp->data + irp->completedBytes, currentTD->transferBuffer, bytesTransferred);
            }

            /* Update the completed byte count */
            irp->completedBytes += bytesTransferred;

            if(irp->completedBytes >= irp->size)
            {
                /* We have transferred the requested number of bytes */
                irp->status = USB_HOST_IRP_STATUS_COMPLETED;
                endIRP = true;
            }
            else
            {
                /* We either have more data to send or have received
                 * a short packet */

                if(irp->scheduledBytes == bytesTransferred)
                {
                    /* If here means we have more data to send in the IRP.
                     * We hvae to use the current tailP ED and then make
                     * the current ED as the tailP. */
                    placeHolderTD = (DRV_USB_OHCI_TD *)pipe->currentTD;
                    transfer = (DRV_USB_OHCI_TD *)pipe->ed.tailP;
                    transfer->irp = irp;
                    irp->scheduledBytes = _DRV_USB_OHCI_DataTransferTD(transfer, (USB_DATA_DIRECTION)pipe->direction);
                    irp->status = USB_HOST_IRP_STATUS_IN_PROGRESS;
                    pipe->currentTD = (DRV_USB_OHCI_TD *)transfer;

                    transfer->td.nextTD = (uint32_t)placeHolderTD;
                    pipe->ed.tailP = (uint32_t)placeHolderTD;

                    if(pipe->pipeType == USB_TRANSFER_TYPE_BULK)
                    {
                        /* Set the list filled bit and enable the control */
                        usbID->UHP_OHCI_HCCOMMANDSTATUS |= UHP_OHCI_HCCOMMANDSTATUS_BLF_Msk;
                    }
                }
                else if((pipe->direction == USB_DATA_DIRECTION_DEVICE_TO_HOST) &&
                        (irp->scheduledBytes > bytesTransferred))
                {
                    /* This means we received a short packet */
                    irp->status = USB_HOST_IRP_STATUS_COMPLETED_SHORT;
                    endIRP = true;
                }
            }
        }
    }

    if(endIRP)
    {
        /* Get the next IRP in the queue */
        placeHolderTD = (DRV_USB_OHCI_TD *)pipe->currentTD;

        /* Check if we have an IRP in the queue */
        if(irp->next == NULL)
        {
            pipe->currentTD = NULL;
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

        /* An IRP could have been submitted in the callback function.
         * If that happens and if the the currentTD is NULL, then
         * IRP processing would have started in the IRP Submit function
         * and we dont have to anything specifically here. But if
         * if current TD is not NULL at the time of IRP submit,
         * then the IRP is added to the end of the IRP queue.
         * We have to process the next IRP here. */

        if(!pipeWasEmpty)
        {
            transfer = (DRV_USB_OHCI_TD *)pipe->ed.tailP;
            irp = irp->next;
            transfer->irp = irp;
            irp->scheduledBytes = _DRV_USB_OHCI_DataTransferTD(transfer, (USB_DATA_DIRECTION)pipe->direction);
            irp->status = USB_HOST_IRP_STATUS_IN_PROGRESS;
            pipe->currentTD = (DRV_USB_OHCI_TD *)transfer;

            transfer->td.nextTD = (uint32_t)placeHolderTD;
            pipe->ed.tailP = (uint32_t)placeHolderTD;

            if(pipe->pipeType == USB_TRANSFER_TYPE_BULK)
            {
                /* Set the list filled bit and enable the control */
                usbID->UHP_OHCI_HCCOMMANDSTATUS |= UHP_OHCI_HCCOMMANDSTATUS_BLF_Msk;
            }
        }
        else
        {
            /* There is no transfer pending. Return the place holder TD t
             * to the pool */
            placeHolderTD->inUse = false;
        }
    }
}

// *****************************************************************************
/* Function:
    void _DRV_USB_OHCI_ControlTransferProcess(void * pipeObj, void * driver)

  Summary:
    This function is called when a pipe has completed some work.
    
  Description:
    This function is called when a pipe has completed some work.

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/

void _DRV_USB_OHCI_ControlTransferProcess(void * pipeObj, void * driver)
{
    /* If this function is called, we already know that the
     * pipe has a TD and that this will be control transfer
     * TD. */

    DRV_USB_OHCI_ED * pipe = (DRV_USB_OHCI_ED *)pipeObj;
    DRV_USB_OHCI_OBJ * hDriver = (DRV_USB_OHCI_OBJ *)driver;
    DRV_USB_OHCI_CONTROL_TD * td = (DRV_USB_OHCI_CONTROL_TD *)pipe->currentTD;
    DRV_USB_OHCI_CONTROL_TD * placeHolderTD = NULL;
    USB_HOST_IRP_LOCAL * irp = td->irp;
    USB_OHCI_ED * ed = &pipe->ed;
    USB_OHCI_TD * setupTD = &td->setupTD;
    USB_OHCI_TD * dataTD = &td->dataTD;
    USB_OHCI_TD * handshakeTD = &td->handshakeTD;
    uint32_t bytesTransferred = 0;
    bool pipeWasEmpty = false;
    DRV_USB_OHCI_CONTROL_TD * controlTransfer = NULL;
    volatile UhpOhci * usbID = ((DRV_USB_OHCI_OBJ *)hDriver)->usbID;

    USB_DATA_DIRECTION direction = USB_DATA_DIRECTION_HOST_TO_DEVICE;
    direction = ((((uint8_t *)(irp->setup))[0] & 0x80) == 0x80) ? USB_DATA_DIRECTION_DEVICE_TO_HOST: USB_DATA_DIRECTION_HOST_TO_DEVICE;

    if(irp->tempState == DRV_USB_OHCI_IRP_STATE_ABORTED)
    {
        /* This means the application has cancelled this IRP. We
         * simply end the IRP */
        irp->status = USB_HOST_IRP_STATUS_ABORTED;
    }
    else
    {
        irp->status = USB_HOST_IRP_STATUS_COMPLETED;

        /* If the ED has an error, then check each TD in the IRP
         * for the error */
        if(ed->h == 1)
        {
            /* Start by checking the SETUP packet and then work 
             * our way through the rest of the control transfer
             * TDs */

            if(setupTD->cc != USB_OHCI_CC_NO_ERROR)
            {
                /* Generally a data error unless there was a stall */
                irp->status = USB_HOST_IRP_STATUS_ERROR_DATA;

                /* Was the setup packet stalled */
                if(setupTD->cc == USB_OHCI_CC_STALL)
                {
                    irp->status = USB_HOST_IRP_STATUS_ERROR_STALL;
                }
            } 

            /* If no error at this point, check if the control 
             * transfer involved a data stage and if so then 
             * check the status of the data stage. */
            if(((irp->data != NULL) && (irp->size != 0)) && (irp->status == USB_HOST_IRP_STATUS_COMPLETED))
            {
                /* There was a data stage. Check if there was an 
                 * error. Underrun error should not be treated as
                 * error as this will be treated as a short packet. */
                if((dataTD->cc != USB_OHCI_CC_NO_ERROR) && (dataTD->cc != USB_OHCI_CC_BUFFER_UNDERRUN))
                {
                    /* Generally a data error unless there was a stall */
                    irp->status = USB_HOST_IRP_STATUS_ERROR_DATA;

                    if(dataTD->cc == USB_OHCI_CC_STALL)
                    {
                        irp->status = USB_HOST_IRP_STATUS_ERROR_STALL;
                    }
                }
            }

            /* If still no error till this point then check the 
             * handshake stage */

            if((handshakeTD->cc != USB_OHCI_CC_NO_ERROR) && (irp->status != USB_HOST_IRP_STATUS_COMPLETED))
            {
                /* Generally a data error unless there was a stall */
                irp->status = USB_HOST_IRP_STATUS_ERROR_DATA;

                if(dataTD->cc == USB_OHCI_CC_STALL)
                {
                    irp->status = USB_HOST_IRP_STATUS_ERROR_STALL;
                }
            }

            /* Clear the halt condition on the pipe */
            ed->h = 0;
        }
        else
        {
            /* No issues with this transfer. Process it. */
            if(irp->size > 0)
            {
                /* As per section 4.3.1.3.5 of the specification, if the cbp is 0, this
                 * means all bytes were transferred. Else cbp will point to the location
                 * after the last location */
                bytesTransferred = (dataTD->cbp == 0) ? irp->scheduledBytes : (dataTD->cbp - (uint32_t)td->dataBuffer);
                if(direction == USB_DATA_DIRECTION_DEVICE_TO_HOST)
                {
                    /* Copy the data from the driver buffer to the user buffer */
                    memcpy(((uint8_t *)irp->data + irp->completedBytes), td->dataBuffer, bytesTransferred);
                }

                /* Update the completed byte count */
                irp->completedBytes += bytesTransferred;
            }

            /* Segmented control transfer are not implemented in this 
             * driver. We must end the IRP */

            irp->tempState = DRV_USB_OHCI_IRP_STATE_COMPLETE;
            if((direction == USB_DATA_DIRECTION_DEVICE_TO_HOST) && (irp->size > irp->completedBytes))
            {
                /* This means this was a short packet */
                irp->status = USB_HOST_IRP_STATUS_COMPLETED_SHORT;
            }
        }
    }

    /* Keep track of which control transfer TD was used 
     * by this IRP. We can use this as a place holder TD
     * if a IRP is queued. */
    placeHolderTD = (DRV_USB_OHCI_CONTROL_TD *)pipe->currentTD;

    /* If there is an IRP in the queue. If not then  */
    if(irp->next == NULL)
    {
        pipe->currentTD = NULL; 
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

    /* An IRP could have been submitted in the callback function.
     * If that happens and if the the currentTD is NULL, then
     * IRP processing would have started in the IRP Submit function
     * and we dont have to anything specifically here. But if
     * if current TD is not NULL at the time of IRP submit,
     * then the IRP is added to the end of the IRP queue.
     * We have to process the next IRP here. */
    
    if(!pipeWasEmpty)
    {
        /* Which means we have another IRP in the queue.
         * This IRP can use the current tailP object
         * and then use the placeholder as tail. */
        controlTransfer = (DRV_USB_OHCI_CONTROL_TD *)pipe->ed.tailP;
        irp = irp->next;
        controlTransfer->irp = irp;

        irp->scheduledBytes = _DRV_USB_OHCI_ControlTransferTD(controlTransfer);
        irp->status = USB_HOST_IRP_STATUS_IN_PROGRESS;
        pipe->currentTD = (DRV_USB_OHCI_TD *)controlTransfer;

        /* Procedure to add a TD to the ED is described in section 5.2.8.2 
         * of the specification. */
        controlTransfer->handshakeTD.nextTD = (uint32_t)placeHolderTD;
        pipe->ed.tailP = (uint32_t)placeHolderTD;

        /* Set the control list filled bit and enable the control */
        usbID->UHP_OHCI_HCCOMMANDSTATUS |= UHP_OHCI_HCCOMMANDSTATUS_CLF_Msk;
    }
    else
    {
        /* We can release the placeHolderTD back to the pool */
        placeHolderTD->inUse = false;
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: OHCI Driver Interface Implementations
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    SYS_MODULE_OBJ DRV_USB_OHCI_Initialize
    ( 
        const SYS_MODULE_INDEX index,
        const SYS_MODULE_INIT * const init
    )

  Summary:
    Initializes the USB Driver.
   
  Description:
    This function initializes the USB Driver, making it ready for clients to
    open. The driver initialization does not complete when this function
    returns. The DRV_USB_OHCI_Tasks function must called periodically to complete
    the driver initialization. The DRV_USB_OHCI_Open function will fail if the
    driver was not initialized or if initialization has not completed.
  
  Remarks:
    See drv_usb_ohci.h for usage information.
*/

SYS_MODULE_OBJ DRV_USB_OHCI_Initialize
(
    const SYS_MODULE_INDEX drvIndex,
    const SYS_MODULE_INIT * const init
)
{
    SYS_MODULE_OBJ retVal = SYS_MODULE_OBJ_INVALID;
    DRV_USB_OHCI_OBJ * hDriver = NULL;
    DRV_USB_OHCI_INIT * drvInit = (DRV_USB_OHCI_INIT *) init;
    int i = 0;

    if(drvIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBOHCIObj[drvIndex];

        if(!hDriver->inUse)
        {
            if(OSAL_MUTEX_Create(&hDriver->mutex) == OSAL_RESULT_TRUE)
            {
                /* Allocate the driver object and update the driver instance
                 * object from the the init data structure */

                hDriver->inUse = true;
                hDriver->uniqueKey = 0x0;
                hDriver->clientUniqueKey = 0xFFFF;
                hDriver->isOpened = false;
                hDriver->status = SYS_STATUS_BUSY;
                hDriver->usbHostDeviceInfo = USB_HOST_DEVICE_OBJ_HANDLE_INVALID;
                hDriver->inInterruptContext = false;
                hDriver->pipeIsClosing = false;

                /* Get data from the init data structure */
                hDriver->interruptSource = drvInit->interruptSource;
                hDriver->usbID = drvInit->usbID;
                hDriver->portPowerEnable = drvInit->portPowerEnable;
                hDriver->portIndication = drvInit->portIndication;
                hDriver->portOverCurrentDetect = drvInit->portOverCurrentDetect;
                hDriver->rootHubAvailableCurrent = drvInit->rootHubAvailableCurrent;

                /* Allocate the endpoint and transfer descriptors for this instance */
                hDriver->endpointDescriptors = &gDrvUSBOHCIEndpointDescriptors[drvIndex][0];
                hDriver->transferDescriptors = &gDrvUSBOHCITransferDescriptor[drvIndex][0];
                hDriver->controlTransferDescriptors = &gDrvUSBOHCIControlTransferDescriptor[drvIndex][0];

                /* Clear the endpoint descriptors */
                memset(hDriver->endpointDescriptors, 0, (sizeof(DRV_USB_OHCI_ED) * USB_HOST_PIPES_NUMBER));

                /* Allocate the Host Controller Communications Area for this instance */
                hDriver->hcHCCA = &gDrvUSBOHCIHCCA[drvIndex];

                /* Check the port bit map and mark these ports as selected 
                 * in the port data structures */
                for(i = 0; i < DRV_USB_OHCI_PORTS_NUMBER; i ++)
                {
                    hDriver->ports[i].selected = false;
                    if(drvInit->bmPortSelect & (1 << i))
                    {
                        /* Driver should process this port */
                        hDriver->ports[i].selected = true;
                    }
                }
                
                hDriver->operationEnabled = false;
                hDriver->operationEnableState = DRV_USB_OHCI_OPERATION_ENABLE_IDLE;
                hDriver->status = SYS_STATUS_READY;;
                retVal = (SYS_MODULE_OBJ)drvIndex;
            }
            else
            {
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Could not create mutex in OHCI driver Initialize");
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: OHCI driver instance is in use");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid Instance in OHCI driver Initialize");
    }

    return(retVal);
}

// *****************************************************************************
/* Function:
    void DRV_USB_OHCI_Deinitialize( const SYS_MODULE_OBJ object )

  Summary:
    This function deinitializes the USB OHCI driver instance. 

  Description:

  Remarks:
    A typicall USB application may not to called this function.
*/

void DRV_USB_OHCI_Deinitialize
(
    const SYS_MODULE_OBJ object
)
{
    uint32_t driverIndex = (uint32_t)(object);
    volatile UhpOhci * usbID = NULL;
    DRV_USB_OHCI_OBJ * hDriver = NULL;

    if(driverIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBOHCIObj[driverIndex];

        if(hDriver->inUse)
        {
            usbID = hDriver->usbID;

            /* Disable the OHCI controller. Start by disabling the lists */
            usbID->UHP_OHCI_HCCONTROL &= (~UHP_OHCI_HCCONTROL_CLE_Msk);
            usbID->UHP_OHCI_HCCONTROL &= (~UHP_OHCI_HCCONTROL_BLE_Msk);
            usbID->UHP_OHCI_HCCONTROL &= (~UHP_OHCI_HCCONTROL_PLE_Msk);

            /* Disable all the interrupts */
            usbID->UHP_OHCI_HCINTERRUPTDISABLE = (UHP_OHCI_HCINTERRUPTENABLE_MIE_Msk | UHP_OHCI_HCINTERRUPTENABLE_RHSC_Msk | 
                    UHP_OHCI_HCINTERRUPTENABLE_UE_Msk | UHP_OHCI_HCINTERRUPTENABLE_WDH_Msk);

            /* Clear all the interrupt flags */
            usbID->UHP_OHCI_HCINTERRUPTSTATUS = (UHP_OHCI_HCINTERRUPTSTATUS_RHSC_Msk | UHP_OHCI_HCINTERRUPTSTATUS_UE_Msk | 
                    UHP_OHCI_HCINTERRUPTSTATUS_WDH_Msk);

            /* Place the module in Reset mode */
            usbID->UHP_OHCI_HCCONTROL = (usbID->UHP_OHCI_HCCONTROL & ~UHP_OHCI_HCCONTROL_HCFS_Msk) | UHP_OHCI_HCCONTROL_HCFS(USB_OHCI_FUNCTIONAL_STATE_RESET);
            hDriver->operationEnabled = false;

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
    SYS_STATUS DRV_USB_OHCI_Status( const SYS_MODULE_OBJ object )

  Summary:
    Provides the current status of the USB Driver module.

  Description:
    This function provides the current status of the USB Driver module.

  Remarks:
    See drv_usb_ohci.h for usage information.
*/

SYS_STATUS DRV_USB_OHCI_Status
(
    const SYS_MODULE_OBJ object
)
{
    SYS_STATUS returnValue = SYS_STATUS_UNINITIALIZED;
    uint32_t driverIndex = (uint32_t)(object);

    if(driverIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
    {
        if(gDrvUSBOHCIObj[driverIndex].inUse)
        {
            returnValue = gDrvUSBOHCIObj[driverIndex].status;
        }
    }

    return(returnValue);
}

// *****************************************************************************
/* Function:
    DRV_HANDLE DRV_USB_OHCI_Open
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
    See drv_usb_ohci.h for usage information.
*/

DRV_HANDLE DRV_USB_OHCI_Open
(
    const SYS_MODULE_INDEX drvIndex,
    const DRV_IO_INTENT ioIntent
)
{
    DRV_HANDLE handle = DRV_HANDLE_INVALID;
    DRV_USB_OHCI_OBJ * hDriver = NULL;

    if(drvIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBOHCIObj[drvIndex];
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

                    hDriver->clientUniqueKey = _DRV_USB_OHCI_GetUniqueKey(hDriver);
                    handle = (DRV_HANDLE)(((hDriver->uniqueKey << 16) & 0xFFFF0000) | (drvIndex & 0xFFFF));
                    hDriver->isOpened = true;
                    OSAL_MUTEX_Unlock(&hDriver->mutex);
                }
                else
                {
                    SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Mutex Lock failed in open function");
                }
            }
            else
            {
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Driver is already opened");
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Instance is not ready to be opened");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid instance in Open Function");
    }

    return(handle);
}

// *****************************************************************************
/* Function:
    void DRV_USB_OHCI_Close( DRV_HANDLE client )

  Summary:
    Closes an opened-instance of the  USB Driver.

  Description:
    This function closes an opened-instance of the  USB Driver, invalidating the
    handle.

  Remarks:
    See drv_usb_ohci.h for usage information.
*/

void DRV_USB_OHCI_Close
(
    DRV_HANDLE handle
)
{
    DRV_USB_OHCI_OBJ * hDriver = NULL;
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);

    if (drvIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBOHCIObj[drvIndex];
        if(hDriver->clientUniqueKey == clientUniqueKey)
        {
            /* Close the driver and invalidate the client unique key */
            hDriver->isOpened = false;
            hDriver->clientUniqueKey = 0xFFFF;
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid handle in Close Function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid instance in Close Function");
    }
} 

// *****************************************************************************
/* Function:
    void DRV_USB_OHCI_Tasks( SYS_MODULE_OBJ object )

  Summary:
    Maintains the driver's polled state machine.

  Description:
    Maintains the driver's polled state machine. This function should be called 
    from the system tasks routine.

  Remarks:
    Refer to drv_usb_ohci.h for usage information.
*/

void DRV_USB_OHCI_Tasks(SYS_MODULE_OBJ object)
{
    uint32_t drvIndex = (uint32_t)object;
    DRV_USB_OHCI_OBJ * hDriver = NULL;

    if(drvIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBOHCIObj[drvIndex];
        if((hDriver->inUse) && (hDriver->status == SYS_STATUS_READY))
        {
            _DRV_USB_OHCI_PortsTask(hDriver);
            _DRV_USB_OHCI_PipeCloseTask(hDriver);
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid instance in Tasks Function");
    }

} 

// *****************************************************************************
/* Function:
    USB_ERROR DRV_USB_OHCI_IRPSubmit
    (
        DRV_USB_OHCI_PIPE_HANDLE  hPipe,
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
    See drv_usb_ohci.h for usage information.
*/

USB_ERROR DRV_USB_OHCI_IRPSubmit
(
    DRV_USB_OHCI_PIPE_HANDLE  hPipe,
    USB_HOST_IRP * pInputIRP
)
{
    USB_ERROR returnValue = USB_ERROR_NONE;
    uint16_t clientUniqueKey = (uint16_t)((hPipe & 0xFFFF0000) >> 16);
    uint16_t pipeObjIndex = (uint16_t)(hPipe & 0xFF);
    int drvIndex = (int)((hPipe & 0xFF00) >> 8);
    DRV_USB_OHCI_CONTROL_TD * controlTransfer = NULL;
    void * placeHolderTD = NULL;
    volatile UhpOhci * usbID = NULL;
    bool interruptWasEnabled = false;
    DRV_USB_OHCI_OBJ * hDriver = NULL;
    DRV_USB_OHCI_ED * pipe = NULL;
    DRV_USB_OHCI_TD * transfer = NULL;
    USB_HOST_IRP_LOCAL * pIRP = (USB_HOST_IRP_LOCAL *)pInputIRP;
    USB_HOST_IRP_LOCAL * currentIRP = NULL;
    int i = 0;
  
    returnValue = USB_ERROR_HOST_PIPE_INVALID;

    if(pipeObjIndex < USB_HOST_PIPES_NUMBER)
    {
        returnValue = USB_ERROR_HOST_DEVICE_INSTANCE_INVALID;

        if(drvIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
        {
            /* Get the pointer to the pipe object from the driver instance
             * object. */

            hDriver = &gDrvUSBOHCIObj[drvIndex];
            pipe = &hDriver->endpointDescriptors[pipeObjIndex];
            returnValue = USB_ERROR_HOST_PIPE_INVALID;
            usbID = hDriver->usbID;

            if((pipe->clientUniqueKey == clientUniqueKey) && (pipe->pipeClosingState == DRV_USB_OHCI_PIPE_CLOSING_STATE_IDLE))
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
                         * context. Disable the interrup and grab the mutex. */
                        if(OSAL_MUTEX_Lock(&hDriver->mutex, OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
                        {
                            interruptWasEnabled = SYS_INT_SourceDisable(hDriver->interruptSource);
                        }
                        else
                        {
                            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Mutex Lock failed in IRP Submit");
                            returnValue = USB_ERROR_OSAL_FUNCTION;
                        }
                    }
                    else
                    {
                        /* This means we are executed withing an interrupt
                         * context. So we know we will not be preempted by a
                         * thread or another USB interrupt. */
                    }

                    /* An IRP will require a place holder transfer object.
                     * If we cannot find one, then we cannot proceed. */

                    if(pipe->pipeType == USB_TRANSFER_TYPE_CONTROL)
                    {
                        /* For control transfers, look for control transfer qTDs */
                        for (i = 0;i < DRV_USB_OHCI_TRANSFERS_NUMBER; i++)
                        {
                            if(hDriver->controlTransferDescriptors[i].inUse == false)
                            {
                                hDriver->controlTransferDescriptors[i].inUse = true;

                                /* Allocate the data buffer for this control transfer from 
                                 * the control transfer pool. */
                                hDriver->controlTransferDescriptors[i].dataBuffer = &gDrvUSBOHCIControlTransferBuffer[drvIndex][i][0];
                                placeHolderTD = &hDriver->controlTransferDescriptors[i];
                                break;
                            }
                        }
                    }
                    else if((pipe->pipeType == USB_TRANSFER_TYPE_BULK) || (pipe->pipeType == USB_TRANSFER_TYPE_INTERRUPT))
                    {
                        /* For non-control transfers, look for bulk interrupt transfer qTDs */
                        for (i = 0;i < DRV_USB_OHCI_TRANSFERS_NUMBER; i++)
                        {
                            if(hDriver->transferDescriptors[i].inUse == false)
                            {
                                hDriver->transferDescriptors[i].inUse = true;

                                /* Allocate the data buffer for this control transfer from 
                                 * the control transfer pool. */
                                hDriver->transferDescriptors[i].transferBuffer = &gDrvUSBOHCITransferBuffer[drvIndex][i][0];
                                placeHolderTD = &hDriver->transferDescriptors[i];
                                break;
                            }
                        }
                    }

                    if(placeHolderTD == NULL)
                    {
                        /* We need the place holder TD else we cannot proceed */
                        returnValue = USB_ERROR_HOST_BUSY;
                        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Could not find free transfer object");
                    }

                    if(returnValue == USB_ERROR_NONE)
                    {
                        /* Update the IRP */
                        pIRP->pipe = hPipe;
                        pIRP->tempState = DRV_USB_OHCI_IRP_STATE_IDLE;
                        pIRP->completedBytes = 0;
                        pIRP->scheduledBytes = 0;
                        pIRP->next = NULL;

                        /* IRP status is pending till it reaches the head of
                         * queue. */
                        pIRP->status = USB_HOST_IRP_STATUS_PENDING;

                        if(pipe->pipeType == USB_TRANSFER_TYPE_CONTROL)
                        {
                            /* Check if the pipe queue is empty */
                            if(pipe->currentTD == NULL)
                            {
                                /* If the pipe is empty, this means we can use the TD 
                                 * that the ED tailP is pointing to. */

                                controlTransfer = (DRV_USB_OHCI_CONTROL_TD *)pipe->ed.tailP;
                                controlTransfer->irp = pIRP;

                                pIRP->scheduledBytes = _DRV_USB_OHCI_ControlTransferTD(controlTransfer);
                                pIRP->status = USB_HOST_IRP_STATUS_IN_PROGRESS;
                                pipe->currentTD = (DRV_USB_OHCI_TD *)controlTransfer;

                                /* Procedure to add a TD to the ED is described in section 5.2.8.2 
                                 * of the specification. */
                                controlTransfer->handshakeTD.nextTD = (uint32_t)placeHolderTD;
                                pipe->ed.tailP = (uint32_t)placeHolderTD;

                                /* Set the control list filled bit and enable the control */
                                usbID->UHP_OHCI_HCCOMMANDSTATUS |= UHP_OHCI_HCCOMMANDSTATUS_CLF_Msk;
                            }
                            else
                            {
                                /* When queing, we will queue the IRP and not 
                                 * the transfer object itself/ */

                                currentIRP = ((DRV_USB_OHCI_CONTROL_TD *)(pipe->currentTD))->irp;
                                while(currentIRP->next != NULL)
                                {
                                    currentIRP = currentIRP->next;
                                }

                                /* At this point, current IRP will point to the last IRP in the queue */
                                currentIRP->next = pIRP;
                            }
                        }
                        else if((pipe->pipeType == USB_TRANSFER_TYPE_BULK) || (pipe->pipeType == USB_TRANSFER_TYPE_INTERRUPT))
                        {
                            /* Non Control Transfer handling */
                            if(pipe->currentTD == NULL)
                            {
                                transfer = (DRV_USB_OHCI_TD *)pipe->ed.tailP;
                                transfer->irp = pIRP;

                                pIRP->scheduledBytes = _DRV_USB_OHCI_DataTransferTD(transfer, (USB_DATA_DIRECTION)(pipe->direction));
                                pIRP->status = USB_HOST_IRP_STATUS_IN_PROGRESS;
                                pipe->currentTD = (DRV_USB_OHCI_TD *)transfer;

                                /* Now add the TD to the ED */
                                transfer->td.nextTD = (uint32_t)placeHolderTD;
                                pipe->ed.tailP = (uint32_t)placeHolderTD;
                                
                                if(pipe->pipeType == USB_TRANSFER_TYPE_BULK)
                                {
                                    /* Set the bulk list filled bit and enable the control */
                                    usbID->UHP_OHCI_HCCOMMANDSTATUS |= UHP_OHCI_HCCOMMANDSTATUS_BLF_Msk;
                                }
                            }
                            else
                            {
                                /* When queing, we will queue the IRP and not 
                                 * the transfer object itself/ */

                                currentIRP = ((DRV_USB_OHCI_TD *)(pipe->currentTD))->irp;
                                while(currentIRP->next != NULL)
                                {
                                    currentIRP = currentIRP->next;
                                }

                                /* At this point, current IRP will point to the last IRP in the queue */
                                currentIRP->next = pIRP;
                            }
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
                    SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: IRP is no valid in IRP submit");
                }
            }
            else
            {
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid pipe handle in IRP Submit");
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid driver Index in IRP Submit");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid Pipe Object Index in IRP Submit");
    }

    return(returnValue);
}

// *****************************************************************************
/* Function:
    void DRV_USB_OHCI_IRPCancel(USB_HOST_IRP * pinputIRP)

  Summary:
    Cancels the specified IRP.
    
  Description:
    This function attempts to cancel the specified IRP. If the IRP is queued and
    its processing has not started, it will be cancelled successfully. If the
    IRP in progress, the ongoing transaction will be allowed to complete. 

  Remarks:
    See drv_usb_ohci.h for usage information.
*/
 
void DRV_USB_OHCI_IRPCancel(USB_HOST_IRP * pInputIRP)
{
    USB_HOST_IRP_LOCAL * irp = (USB_HOST_IRP_LOCAL *)pInputIRP;
    DRV_USB_OHCI_PIPE_HANDLE hPipe = DRV_USB_OHCI_PIPE_HANDLE_INVALID;
    DRV_USB_OHCI_OBJ * hDriver = NULL;
    DRV_USB_OHCI_ED * pipe = NULL;
    bool interruptWasEnabled = false;
    uint16_t clientUniqueKey = 0;
    uint16_t pipeObjIndex = 0;
    int drvIndex = 0;
    DRV_USB_OHCI_TD * currentTD = NULL;
    DRV_USB_OHCI_CONTROL_TD * controlTD = NULL;
    USB_HOST_IRP_LOCAL * currentIRP = NULL;

    if(irp != NULL)
    {
        /* Get the pipe to which IRP belongs */
        hPipe = irp->pipe;
        clientUniqueKey = (uint16_t)((hPipe & 0xFFFF0000) >> 16);
        pipeObjIndex = (uint16_t)(hPipe & 0xFF);
        drvIndex = (int)((hPipe & 0xFF00) >> 8);

        if(pipeObjIndex < USB_HOST_PIPES_NUMBER)
        {
            if(drvIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
            {
                hDriver = &gDrvUSBOHCIObj[drvIndex];
                pipe = &hDriver->endpointDescriptors[pipeObjIndex];

                if((pipe->clientUniqueKey == clientUniqueKey) && (pipe->pipeClosingState == DRV_USB_OHCI_PIPE_CLOSING_STATE_IDLE))
                {
                    if(hDriver->inInterruptContext == false)
                    {
                        /* This means we are not executed within an interrupt
                         * context. Disable the interrup and grab the mutex. */
                        if(OSAL_MUTEX_Lock(&hDriver->mutex, OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
                        {
                            interruptWasEnabled = SYS_INT_SourceDisable(hDriver->interruptSource);
                        }
                        else
                        {
                            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Mutex Lock failed in IRP Submit");
                        }
                    }

                    if(irp->status == USB_HOST_IRP_STATUS_IN_PROGRESS)
                    {
                        /* This means this qTD is at the head of the queue.
                         * We will track this in the interrupt. */

                        irp->tempState = DRV_USB_OHCI_IRP_STATE_ABORTED;
                    }
                    else
                    {
                        /* Else we have to find the IRP in the queue. */

                        if(pipe->pipeType == USB_TRANSFER_TYPE_CONTROL)
                        {
                            /* If this is a control transfer pipe, then we have to deal
                             * with control QTDs */
                            controlTD = (DRV_USB_OHCI_CONTROL_TD *)pipe->currentTD;
                            currentIRP = controlTD->irp;
                            while(currentIRP->next != NULL)
                            {
                                if(currentIRP->next == irp)
                                {
                                    /* Found our IRP. Remove it from the queue
                                     * and then abort it. */
                                    currentIRP->next = irp->next;
                                    irp->status = USB_HOST_IRP_STATUS_ABORTED;
                                    if(irp->callback != NULL)
                                    {
                                        irp->callback((USB_HOST_IRP *)irp);
                                    }
                                    break;
                                }

                                /* Continue searching. */
                                currentIRP = currentIRP->next;
                            }
                        }
                        else
                        {
                            currentTD = (DRV_USB_OHCI_TD *)pipe->currentTD;
                            currentIRP = currentTD->irp;
                            while(currentIRP->next != NULL)
                            {
                                if(currentIRP->next == irp)
                                {
                                    /* Found our IRP. Remove it from the queue
                                     * and then abort it. */
                                    currentIRP->next = irp->next;
                                    irp->status = USB_HOST_IRP_STATUS_ABORTED;
                                    if(irp->callback != NULL)
                                    {
                                        irp->callback((USB_HOST_IRP *)irp);
                                    }
                                    break;
                                }

                                /* Continue searching. */
                                currentIRP = currentIRP->next;
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
                else
                {
                    SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid Pipe Handle in IRP Cancel");
                }
            }
            else
            {
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid Driver Instance in IRP Cancel");
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid Pipe in IRP Cancel");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid IRP in IRP Cancel");
    }
}

// *****************************************************************************
/* Function:
    void DRV_USB_OHCI_PipeClose(DRV_USB_OHCI_PIPE_HANDLE pipeHandle)

  Summary:
    Closes an open pipe.
	
  Description:
    This function closes an open pipe. Any IRPs scheduled on the pipe will be
    aborted and IRP callback functions will be called with the status as
    DRV_USB_HOST_IRP_STATE_ABORTED. The pipe handle will become invalid and the
    pipe will not accept IRPs.

  Remarks:
    See drv_usb_ohci.h for usage information.
*/

void DRV_USB_OHCI_PipeClose
(
    DRV_USB_OHCI_PIPE_HANDLE hPipe
)
{
    uint16_t clientUniqueKey = (uint16_t)((hPipe & 0xFFFF0000) >> 16);
    uint16_t pipeObjIndex = (uint16_t)(hPipe & 0xFF);
    int drvIndex = (int)((hPipe & 0xFF00) >> 8);
    DRV_USB_OHCI_ED * pipe = NULL;
    DRV_USB_OHCI_OBJ * hDriver = NULL;
    bool thereWasAnError = false; 
    bool interruptWasEnabled = false;
    USB_HOST_IRP_LOCAL * irp = NULL;
      
    if(pipeObjIndex < USB_HOST_PIPES_NUMBER)
    {
        if(drvIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
        {
            /* Get the pointer to the pipe object from the driver instance
             * object. */

            hDriver = &gDrvUSBOHCIObj[drvIndex];
            pipe = &hDriver->endpointDescriptors[pipeObjIndex];

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
                    /* Update the pipe state to let everyone know that this pipe 
                     * should not be used */
                    pipe->pipeClosingState = DRV_USB_OHCI_PIPE_CLOSING_STATE_CLOSE_REQUESTED;

                    /* Set the skip bit on this ED */
                    pipe->ed.k = 1;

                    if(pipe->currentTD != NULL)
                    {
                        irp = pipe->currentTD->irp;

                        while(irp != NULL)
                        {
                            /* Abort each IRP on this pipe */
                            if(irp->callback != NULL)
                            {
                                irp->status = USB_HOST_IRP_STATUS_ABORTED;
                                irp->callback((USB_HOST_IRP *)irp);
                            }

                            /* Go to the next IRP in the list */
                            irp = irp->next;
                        }
                    }

                    /* The rest of the pipe closing process will take place in 
                     * the pipe close task. */
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
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid Pipe in Pipe Close");
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid Driver Instance Index in Pipe Close");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid Pipe Object Index in Pipe Close");
    }
}

// *****************************************************************************
/* Function:
    DRV_USB_OHCI_PIPE_HANDLE DRV_USB_OHCI_PipeSetup
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
    See drv_usb_ohci.h for usage information.
*/

DRV_USB_OHCI_PIPE_HANDLE DRV_USB_OHCI_PipeSetup 
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
    DRV_USB_OHCI_PIPE_HANDLE pipeHandle = DRV_USB_OHCI_PIPE_HANDLE_INVALID;
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);
    DRV_USB_OHCI_OBJ * hDriver = NULL;
    DRV_USB_OHCI_ED * pipe = NULL;
    USB_OHCI_ED * ed = NULL;
    volatile UhpOhci * usbID = NULL;
    bool interruptWasEnabled = false;
    void * placeHolderTD = NULL;
    int i = 0;
    uint32_t * interruptList = NULL;
    USB_OHCI_ED * currentED = NULL;
    USB_OHCI_ED * previousED = NULL;
    int pipeObjIndex = 0;
 
    if(drvIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBOHCIObj[drvIndex];
        usbID = hDriver->usbID;
        
        if(hDriver->clientUniqueKey == clientUniqueKey)
        {
            if((speed != USB_SPEED_ERROR) && (speed != USB_SPEED_HIGH))
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
                        for(i = 0;i < USB_HOST_PIPES_NUMBER; i ++)
                        {
                            if(hDriver->endpointDescriptors[i].inUse == false)
                            {
                                /* We found a free endpoint descriptor. Allocate this */
                                hDriver->endpointDescriptors[i].inUse = true;
                                pipe = &hDriver->endpointDescriptors[i];
                                pipeObjIndex = i;
                                break;
                            }
                        }

                        if(pipe != NULL)
                        {
                            /* We have found a free pipe object. Now find a free transfer object 
                             * that we can use as place holder TD. Transfer descriptors pool can
                             * be accessed from an interrupt as well. Hence we need to first 
                             * disable the interrupt. */

                            interruptWasEnabled = SYS_INT_SourceDisable(hDriver->interruptSource);
                            if(pipeType == USB_TRANSFER_TYPE_CONTROL)
                            {
                                /* Look for control transfer objects to use */
                                for(i = 0; i < DRV_USB_OHCI_TRANSFERS_NUMBER; i ++)
                                {
                                    if(hDriver->controlTransferDescriptors[i].inUse == false)
                                    {
                                        hDriver->controlTransferDescriptors[i].inUse = true;
                                        hDriver->controlTransferDescriptors[i].dataBuffer = &gDrvUSBOHCIControlTransferBuffer[drvIndex][i][0];
                                        placeHolderTD = &hDriver->controlTransferDescriptors[i];

                                        break;
                                    }
                                }
                            }
                            else if((pipeType == USB_TRANSFER_TYPE_BULK) || (pipeType == USB_TRANSFER_TYPE_INTERRUPT))
                            {
                                /* Look for non control transfer objects to use */
                                for(i = 0; i < DRV_USB_OHCI_TRANSFERS_NUMBER; i ++)
                                {
                                    if(hDriver->transferDescriptors[i].inUse == false)
                                    {
                                        hDriver->transferDescriptors[i].inUse = true;
                                        hDriver->transferDescriptors[i].transferBuffer = &gDrvUSBOHCITransferBuffer[drvIndex][i][0];
                                        placeHolderTD = &hDriver->transferDescriptors[i];
                                        break;
                                    }
                                }
                            }

                            /* Restore the interrupt status */
                            if(interruptWasEnabled)
                            {
                                SYS_INT_SourceEnable(hDriver->interruptSource);
                            }
                        }

                        if((pipe != NULL) && (placeHolderTD != NULL))
                        {

                            /* Set up the OHCI Endpoint Descriptor */
                            ed = &pipe->ed;

                            /* We have found a pipe and a place holder TD */
                            pipe->pipeType = pipeType;
                            pipe->clientUniqueKey = _DRV_USB_OHCI_GetUniqueKey(hDriver);
                            pipe->currentTD = NULL;
                            pipe->pipeClosingState = DRV_USB_OHCI_PIPE_CLOSING_STATE_IDLE;
                            pipe->speed = speed;

                            /* The pipe handle is a composite value. The
                             * first byte is an index into the pipe object
                             * array. The second byte in an index into the
                             * hardware instance object array and third and
                             * fourth byteare the client unique key. */
                            pipeHandle = (DRV_USB_OHCI_PIPE_HANDLE)(((pipe->clientUniqueKey << 16) & 0xFFFF0000) | ((drvIndex & 0xFF) << 8) | (pipeObjIndex & 0xFF));

                            /* Clear up the endpoint descriptor structure */
                            memset(ed, 0, sizeof(USB_OHCI_ED));

                            ed->fa = deviceAddress;
                            ed->en = endpointAndDirection & 0xF;

                            ed->d = (endpointAndDirection & 0x80) ? USB_OHCI_ED_DIRECTION_IN : USB_OHCI_ED_DIRECTION_OUT; 

                            /* Pipe direction is ignored for control pipe where it 
                             * is obtained from the setup packet */
                            pipe->direction = (endpointAndDirection & 0x80) >> 7;

                            if(pipeType == USB_TRANSFER_TYPE_CONTROL)
                            {
                                /* Direction should come from the Transfer descriptor
                                 * for control endpoints */
                                ed->d = USB_OHCI_ED_DIRECTION_FROM_TD;
                            }

                            /* Setup the endpoint descriptor speed */
                            ed->s = (speed == USB_SPEED_FULL) ? USB_OHCI_ED_SPEED_FULL : USB_OHCI_ED_SPEED_LOW;

                            /* Do not skip this endpoint */
                            ed->k = 0;

                            /* ED format is general for control, bulk and interrupt endpoints */
                            ed->f = USB_OHCI_ED_FORMAT_GENERAL;
                            if(pipeType == USB_TRANSFER_TYPE_ISOCHRONOUS)
                            {
                                ed->f = USB_OHCI_ED_FORMAT_ISOC;
                            }

                            /* Endpoint Size */
                            ed->mps = wMaxPacketSize;

                            /* Initial state of the ed, we have the headP and tailP pointing
                             * to the TD that is reserved for this ED. */
                            ed->tailP = (uint32_t)placeHolderTD; 
                            ed->headP = _DRV_USB_OHCI_DRV_TO_ED_HEADP(placeHolderTD); 

                            /* Next ED pointer is set to 0 to indicate no downstream ED */
                            ed->nextED = 0;

                            /* Set toggle carry to 0 */
                            ed->c = 0;

                            if(pipeType == USB_TRANSFER_TYPE_CONTROL)
                            {
                                /* Adding the queue handling function to the pipe. */
                                pipe->queueHandler = _DRV_USB_OHCI_ControlTransferProcess;

                                if(usbID->UHP_OHCI_HCCONTROLHEADED == 0)
                                {
                                    /* This is the first control endpoint */
                                    usbID->UHP_OHCI_HCCONTROLHEADED = (uint32_t)ed;
                                    usbID->UHP_OHCI_HCCONTROL |= UHP_OHCI_HCCONTROL_CLE_Msk;
                                }
                                else
                                {
                                    /* Start with the head ED and then reach the end of the ED list */
                                    currentED = (USB_OHCI_ED *)usbID->UHP_OHCI_HCCONTROLHEADED;
                                    while(currentED->nextED != 0)
                                    {
                                        currentED = (USB_OHCI_ED *)(currentED->nextED);
                                    }

                                    /* currentED at this time will point to the last ED */
                                    currentED->nextED = (uint32_t)ed;
                                }
                            }
                            else if(pipeType == USB_TRANSFER_TYPE_BULK)
                            {
                                /* Assign the queue handling function */
                                pipe->queueHandler = _DRV_USB_OHCI_DataTransferProcess;
                                if(usbID->UHP_OHCI_HCBULKHEADED == 0)
                                {
                                    /* This is the first bulk endpoint */
                                    usbID->UHP_OHCI_HCBULKHEADED = (uint32_t)ed;
                                    usbID->UHP_OHCI_HCCONTROL |= UHP_OHCI_HCCONTROL_BLE_Msk;
                                }
                                else
                                {
                                    /* Start with the head ED and then reach the end of the ED list */
                                    currentED = (USB_OHCI_ED *)usbID->UHP_OHCI_HCBULKHEADED;
                                    while(currentED->nextED != 0)
                                    {
                                        currentED = (USB_OHCI_ED *)(currentED->nextED);
                                    }

                                    /* currentED at this time will point to the last ED */
                                    currentED->nextED = (uint32_t)ed;
                                }
                            }
                            else if(pipeType == USB_TRANSFER_TYPE_INTERRUPT)
                            {
                                /* For interrupt pipes, we need to quantize the 
                                 * requested interval in available interval slots */

                                pipe->queueHandler = _DRV_USB_OHCI_DataTransferProcess;

                                uint8_t pollingIndex = 0;
                                bool slotFound = false;
                                int nextListIndex = 0;

                                interruptList = (uint32_t *)hDriver->hcHCCA->hccaInterruptTable;
                                pipe->pollingRate = 1;

                                if(bInterval >= 32)
                                {
                                    /* Maximum polling rate is 32 */
                                    pipe->pollingRate = 32;
                                    pollingIndex = 5;
                                }
                                else
                                {
                                    while(pipe->pollingRate <= 16)
                                    {
                                        if(pipe->pollingRate >= bInterval)
                                        {
                                            /* We have the polling rate */
                                            break;
                                        }
                                        else
                                        {
                                            /* Try the next polling rate */
                                            pollingIndex ++;
                                            pipe->pollingRate = pipe->pollingRate << pollingIndex;
                                        }
                                    }

                                    /* Adjust the polling rate in case it is greater than bInterval. */
                                    pollingIndex = (pipe->pollingRate > bInterval) ? (pollingIndex - 1) : pollingIndex;
                                    pipe->pollingRate = (pipe->pollingRate > bInterval) ? (pipe->pollingRate >> 1) : pipe->pollingRate;
                                }

                                /* Now we scan the periodic frame list to find  a place where we can insert
                                 * the queue head. The trivial case is when the list is empty and the queue
                                 * head can be inserted into the very first slot. This means the list is 
                                 * completely empty */

                                if(interruptList[0] == 0)
                                {
                                    /* This means this is the first pipe in the list */
                                    slotFound = true;
                                    nextListIndex = 0;
                                    pipe->startSlot = 0;

                                    /* The next pipe for this polling rate should use the next slot */
                                    hDriver->nextSlotToUse[pollingIndex] ++;

                                    for(i = 0; i < 32; i ++)
                                    {
                                        interruptList[nextListIndex] = (uint32_t)ed;
                                        nextListIndex += pipe->pollingRate;
                                        if(nextListIndex >= 32)
                                        {
                                            break;
                                        }
                                    }
                                }

                                if(!slotFound)
                                {
                                    if(pipe->pollingRate == 1)
                                    {
                                        /* Pipe with polling rate of 1 millisecond requires special handling. 
                                         * They have to be inserted into every slot and to the end of the list. 
                                         * A pipe with 1 millisecond polling will be always the last one in 
                                         * the queue. If the list already contains a 1 millisecond qH then 
                                         * this should come to the right of this qH. */

                                        pipe->startSlot = 0;

                                        if(hDriver->nextSlotToUse[pollingIndex] > 0)
                                        {
                                            /* This means the list already contains a 1 millisecond pipe.
                                             * This 1 millisecond will be the at slot 0 and will be the
                                             * last pipe in this slot. We have to insert our pipe to the
                                             * right of the pipe. */
                                            currentED = (USB_OHCI_ED *)interruptList[0];
                                            while(currentED->nextED != 0)
                                            {
                                                /* Get to the next ED */
                                                currentED = (USB_OHCI_ED*)currentED->nextED;
                                            }

                                            /* currentED is pointing to the last ED in this slot
                                             * Set the nextED of currentED to the ED we want to insert */
                                            currentED->nextED = (uint32_t)ed;
                                        }
                                        else
                                        {
                                            /* This is the first 1 millisecond pipe in the list */
                                            for(i = 0; i < 32; i ++)
                                            {
                                                if(interruptList[i] == 0)
                                                {
                                                    /* This slot is empty */
                                                    interruptList[i] = (uint32_t)ed;
                                                }
                                                else
                                                {
                                                    currentED = (USB_OHCI_ED *)interruptList[i];
                                                    while(currentED->nextED != 0)
                                                    {
                                                        if(currentED->nextED == (uint32_t)ed)
                                                        {
                                                            /* This can happen if the current ED was updated previously
                                                             * to point to our ED and we have encountered this ED. */
                                                            break;
                                                        }

                                                        /* Continue to traverse the list */
                                                        currentED = (USB_OHCI_ED *)currentED->nextED;
                                                    }

                                                    if(currentED->nextED != (uint32_t)ed)
                                                    {
                                                        /* We have exited the search list at the last ED is not pointing
                                                         * to our ED. So set the last to ED to point to our ED */
                                                        currentED->nextED = (uint32_t)ed;
                                                    }
                                                    else
                                                    {
                                                        /* Nothing to do. Our ED is already on the slot */
                                                    }
                                                }
                                            }

                                        }

                                        /* For 1 millisecond polling interval, the nextSlotToUse counter
                                         * counts the number of 1 millisecond pipes */
                                        slotFound = true;
                                        hDriver->nextSlotToUse[pollingIndex] ++;
                                    }
                                    else
                                    {
                                        /* Frame list is not empty and we must insert a pipe with a 
                                         * polling rate greater than 1. To this we must find the 
                                         * first slot. The first slot must be within the first polling rate
                                         * slots on the list. For example, with a polling rate of 8, the
                                         * first slot should in slots 0 tp 7. Additonally, we should 
                                         * find a slot that preferrably does not have another qH with
                                         * the same polling rate. This allows for spreading of the 
                                         * interupt queues.
                                         * So we scan till we find a slot that has the least number of
                                         * pipe with the same polling rate and then insert the qH into 
                                         * that slot. */

                                        /* The nextSlotToUse array in the driver object provides information 
                                         * on the next slot to be used for a specific bInterval. Increment the
                                         * nextSlotToUse counter and if we have reached the end of the 
                                         * polling rate window */

                                        pipe->startSlot = hDriver->nextSlotToUse[pollingIndex];
                                        hDriver->nextSlotToUse[pollingIndex] ++;
                                        hDriver->nextSlotToUse[pollingIndex] = (hDriver->nextSlotToUse[pollingIndex] >= pipe->pollingRate) ? 0 : hDriver->nextSlotToUse[pollingIndex];

                                        for(i = pipe->startSlot; i < 32; (i += pipe->pollingRate))
                                        {
                                            if(interruptList[i] == 0)
                                            {
                                                /* Trivial case. Simply set this to point to our pipe */
                                                interruptList[i] = (uint32_t)ed;
                                            }
                                            else if(pipe->pollingRate >= ((DRV_USB_OHCI_ED *)interruptList[i])->pollingRate)
                                            {
                                                /* The polling rate of our pipe is greater the first pipe in this slot.
                                                 * We must insert of our pipe before the current first pipe. */
                                                
                                                ed->nextED = interruptList[i];
                                                interruptList[i] = (uint32_t)ed;
                                            } 
                                            else
                                            {
                                                /* We have to insert the pipe in between existing pipe list */
                                                currentED = (USB_OHCI_ED *)interruptList[i];
                                                while(currentED->nextED != 0)
                                                {
                                                    previousED = currentED;
                                                    currentED = (USB_OHCI_ED *)(currentED->nextED);

                                                    if(currentED == ed)
                                                    {
                                                        /* ED is already in this list */
                                                        break;
                                                    }

                                                    if(pipe->pollingRate >= ((DRV_USB_OHCI_ED *)currentED)->pollingRate)
                                                    {
                                                        /* We have found a place between the previous and the current
                                                         * ED to insert our ED */
                                                        ed->nextED = (uint32_t)currentED;
                                                        previousED->nextED = (uint32_t)ed;
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }

                                /* Enable the periodic list */
                                usbID->UHP_OHCI_HCCONTROL |= UHP_OHCI_HCCONTROL_PLE_Msk;
                            }
                        }

                        if(pipeHandle == DRV_USB_OHCI_PIPE_HANDLE_INVALID)
                        {
                            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Could not find free pipe object");
                        }

                        /* Release the mutex */
                        OSAL_MUTEX_Unlock(&hDriver->mutex);
                    }
                    else
                    {
                        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Mutex Error in pipe setup function");
                    }
                }
                else
                {
                    SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid pipe endpoint size in pipe setup function");
                }
            }
            else
            {
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid Speed in Pipe Setup function");
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid handle in Pipe Setup function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid instance in Pipe Setup function");
    }
 
    return(pipeHandle);
}

// ****************************************************************************
/* Function:
    bool DRV_USB_OHCI_EventDisable
    (
        DRV_HANDLE handle
    );
   
  Summary:
    Disables host mode events.
    
  Description:
    This function disables the host mode events. This function is called by the
    Host Layer when it wants to execute code atomically. 
    
  Remarks:
    Refer to drv_usb_ohci.h for usage information.
*/

bool DRV_USB_OHCI_EventsDisable
(
    DRV_HANDLE handle
)
{
    bool result = false;
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);

    if(drvIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
    {
        if(gDrvUSBOHCIObj[drvIndex].clientUniqueKey == clientUniqueKey)
        {
            result = SYS_INT_SourceDisable(gDrvUSBOHCIObj[drvIndex].interruptSource);
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid handle in Events Disable function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid instance in Events Disable function");
    }

    return(result);
}

// ****************************************************************************
/* Function:
    void DRV_USB_OHCI_EventsEnable
    (
        DRV_HANDLE handle
        bool eventRestoreContext
    );
    
  Summary:
    Restores the events to the specified the original value.
    
  Description:
    This function will restore the enable disable state of the events.
    eventRestoreContext should be equal to the value returned by the
    DRV_USB_OHCI_EventsDisable() function.
    
  Remarks:
    Refer to drv_usb_ohci.h for usage information.
*/

void DRV_USB_OHCI_EventsEnable
(
    DRV_HANDLE handle, 
    bool eventContext
)
{
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);

    if(drvIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
    {
        if(gDrvUSBOHCIObj[drvIndex].clientUniqueKey == clientUniqueKey)
        {
            if(eventContext == true)
            {
                SYS_INT_SourceEnable(gDrvUSBOHCIObj[drvIndex].interruptSource);
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
    void DRV_USB_OHCI_OperationEnable(DRV_HANDLE handle, bool enable)

  Summary:
    Enables Root Hub Operation.

  Description:
    This function enables the Root Hub Operation. When enabled the root hub will
    supply power to the port thus enablling device attach detection.

  Remarks:
    Refer to drv_usb_ohci.h for usage information.
*/

void DRV_USB_OHCI_OperationEnable(DRV_HANDLE handle, bool enable)
{
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);
    DRV_USB_OHCI_OBJ * hDriver = NULL;
    volatile UhpOhci * usbID = NULL;
    uint32_t interval = 0;
    int nPorts = 0;
    int i = 0;
    volatile uint32_t * port = NULL;
    
    if(drvIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBOHCIObj[drvIndex];
        if(hDriver->clientUniqueKey == clientUniqueKey)
        {
            usbID = hDriver->usbID;

            /* Driver handle is valid */
            if(enable == true)
            {
                /* Start by setting the HCCA structures to zero */
                memset(hDriver->hcHCCA, 0, sizeof(USB_OHCI_HCCA));
                memset(hDriver->transferDescriptors, 0, (sizeof(DRV_USB_OHCI_TD) * DRV_USB_OHCI_TRANSFERS_NUMBER));
                memset(hDriver->endpointDescriptors, 0, (sizeof(DRV_USB_OHCI_ED) * USB_HOST_PIPES_NUMBER));
                memset(hDriver->controlTransferDescriptors, 0, (sizeof(DRV_USB_OHCI_CONTROL_TD) * DRV_USB_OHCI_TRANSFERS_NUMBER));
                memset(hDriver->nextSlotToUse, 0, (sizeof(uint8_t) * 6));

                /* Perform a software reset of the OHCI module and wait till the reset is complete */
                usbID->UHP_OHCI_HCCOMMANDSTATUS |= UHP_OHCI_HCCOMMANDSTATUS_HCR_Msk;

                /* Wait till the reset complete. Should take about 10 useconds */
                while((usbID->UHP_OHCI_HCCOMMANDSTATUS & UHP_OHCI_HCCOMMANDSTATUS_HCR_Msk) == UHP_OHCI_HCCOMMANDSTATUS_HCR_Msk);

                /* At this point the OHCI module will be in suspend state.Assign 
                 * the HCCA to the OCHI module */
                usbID->UHP_OHCI_HCHCCA = (uint32_t)hDriver->hcHCCA;

                /* Refer to page 86 of the specification for the following piece of code */
                interval = usbID->UHP_OHCI_HCFMINTERVAL & 0x3FFF;
                interval |= (((interval - DRV_USB_OHCI_MAXIMUM_OVERHEAD) * 6) / 7) << 16;
                interval |= 0x80000000 & (0x80000000 ^ (usbID->UHP_OHCI_HCFMREMAINING));
                usbID->UHP_OHCI_HCFMINTERVAL = interval;
                usbID->UHP_OHCI_HCPERIODICSTART = DRV_USB_OHCI_PRDSTRT;

                /* Now place the HC in Operational state */
                usbID->UHP_OHCI_HCCONTROL = (usbID->UHP_OHCI_HCCONTROL & ~UHP_OHCI_HCCONTROL_HCFS_Msk) | UHP_OHCI_HCCONTROL_HCFS(USB_OHCI_FUNCTIONAL_STATE_OPERATIONAL);

                /* Now power up each selected port */
                if((usbID->UHP_OHCI_HCRHDESCRIPTORA & UHP_OHCI_HCRHDESCRIPTORA_PSM_Msk) == UHP_OHCI_HCRHDESCRIPTORA_PSM_Msk)
                {
                    /* This means each port is powered independantly. Get the number of ports
                     * and adjust this against the number of provisioned ports */
                    nPorts = usbID->UHP_OHCI_HCRHDESCRIPTORA & UHP_OHCI_HCRHDESCRIPTORA_NDP_Msk;
                    nPorts = (nPorts > DRV_USB_OHCI_PORTS_NUMBER) ? DRV_USB_OHCI_PORTS_NUMBER : nPorts;
                    port = &usbID->UHP_OHCI_HCRHPORTSTATUS0;
                    for(i = 0; i < nPorts; i ++)
                    {
                        if(hDriver->ports[i].selected)
                        {
                            /* If the port is selected in this application, then power it up.
                             * Also take this opportunity to initialize the port data strucuture. */
                            hDriver->ports[i].portAttachState = DRV_USB_OHCI_PORT_ATTACH_STATE_WAITING_FOR_ATTACH;
                            hDriver->ports[i].attachedDeviceObjHandle = USB_HOST_DEVICE_OBJ_HANDLE_INVALID;
                            hDriver->ports[i].timerHandle = SYS_TIME_HANDLE_INVALID;
                            hDriver->ports[i].isResetting = false;
                            hDriver->ports[i].disableThisPort = false;
                            hDriver->ports[i].portSpeed = USB_SPEED_ERROR;

                            port[i] |= UHP_OHCI_HCRHPORTSTATUS0_PPS_Msk;
                        }
                    }
                }
                else
                {
                    /* Power switch is global. Enable global power in HcRhStatus Register */
                    usbID->UHP_OHCI_HCRHSTATUS |= UHP_OHCI_HCRHSTATUS_LPSC_Msk;
                }

                /* All ports are powered up. Now we implemetn the PO2PGT delaY. This delay is implemented
                 * in the operationIsEnabled function. */
                hDriver->operationEnableState = DRV_USB_OHCI_OPERATION_ENABLE_START_PO2PGT_DELAY;
            }
            else
            {
                /* Disable the OHCI controller. Start by disabling the lists */
                usbID->UHP_OHCI_HCCONTROL &= (~UHP_OHCI_HCCONTROL_CLE_Msk);
                usbID->UHP_OHCI_HCCONTROL &= (~UHP_OHCI_HCCONTROL_BLE_Msk);
                usbID->UHP_OHCI_HCCONTROL &= (~UHP_OHCI_HCCONTROL_PLE_Msk);

                /* Disable all the interrupts */
                usbID->UHP_OHCI_HCINTERRUPTDISABLE = (UHP_OHCI_HCINTERRUPTENABLE_MIE_Msk | UHP_OHCI_HCINTERRUPTENABLE_RHSC_Msk | 
                        UHP_OHCI_HCINTERRUPTENABLE_UE_Msk | UHP_OHCI_HCINTERRUPTENABLE_WDH_Msk);

                /* Clear all the interrupt flags */
                usbID->UHP_OHCI_HCINTERRUPTSTATUS = (UHP_OHCI_HCINTERRUPTSTATUS_RHSC_Msk | UHP_OHCI_HCINTERRUPTSTATUS_UE_Msk | 
                        UHP_OHCI_HCINTERRUPTSTATUS_WDH_Msk);

                /* Place the module in Reset mode */
                usbID->UHP_OHCI_HCCONTROL = (usbID->UHP_OHCI_HCCONTROL & ~UHP_OHCI_HCCONTROL_HCFS_Msk) | UHP_OHCI_HCCONTROL_HCFS(USB_OHCI_FUNCTIONAL_STATE_RESET);
                hDriver->operationEnabled = false;
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid handle in OperationEnable function");
        }
    }            
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid instance in OperationEnable function");
    }
} 

// *****************************************************************************
/* Function:
    bool DRV_USB_OHCI_OperationIsEnabled(DRV_HANDLE handle)

  Summary:
    Returns true if root hub operation has been enabled.

  Description:
    Function returns true if the root hub enable operation has completed.

  Remarks:
    Refer to drv_usb_ohci.h for usage information.

*/

bool DRV_USB_OHCI_OperationIsEnabled(DRV_HANDLE handle)
{
    bool returnValue = false;
     uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);
    DRV_USB_OHCI_OBJ * hDriver = NULL;
    volatile UhpOhci * usbID = NULL;
    int pg2pgtDelay = 0;

    if(drvIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBOHCIObj[drvIndex];
        if(hDriver->clientUniqueKey == clientUniqueKey)
        {
            usbID = hDriver->usbID;
            if(hDriver->operationEnabled == false)
            {
                /* This operation enable has not completed. Advance the state
                 * machine. */
                switch(hDriver->operationEnableState)
                {
                    case DRV_USB_OHCI_OPERATION_ENABLE_IDLE:

                      /* Nothing to do here */
                      break;

                    case DRV_USB_OHCI_OPERATION_ENABLE_START_PO2PGT_DELAY:

                        /* Check if the delay can be started and then wait for the delay to complete */
                        pg2pgtDelay = (usbID->UHP_OHCI_HCRHDESCRIPTORA & UHP_OHCI_HCRHDESCRIPTORA_POTPGT_Msk) >> 24;
                        hDriver->timerHandle = SYS_TIME_HANDLE_INVALID;
                        if(SYS_TIME_DelayMS((pg2pgtDelay * 2), &hDriver->timerHandle) == SYS_TIME_SUCCESS)
                        {
                            hDriver->operationEnableState = DRV_USB_OHCI_OPERATION_ENABLE_PO2PGT_DELAY_WAIT;
                        }

                        break;

                    case DRV_USB_OHCI_OPERATION_ENABLE_PO2PGT_DELAY_WAIT:

                        if(SYS_TIME_DelayIsComplete(hDriver->timerHandle))
                        {
                            /* The time delay is complete. Enable the required interrupts */
                            hDriver->operationEnabled = true;
                            hDriver->operationEnableState = DRV_USB_OHCI_OPERATION_ENABLE_IDLE;
                            usbID->UHP_OHCI_HCINTERRUPTENABLE |= (UHP_OHCI_HCINTERRUPTENABLE_MIE_Msk | UHP_OHCI_HCINTERRUPTENABLE_RHSC_Msk | 
                                    UHP_OHCI_HCINTERRUPTENABLE_UE_Msk | UHP_OHCI_HCINTERRUPTENABLE_WDH_Msk);
                            returnValue = true;
                        }

                    default:
                        break;
                }
            }
            else
            {
                /* OHCI is already enabled */
                returnValue = true;
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid handle in OperationEnable function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid instance in OperationEnable function");
    }
    
    return(returnValue);
}
 
// ****************************************************************************
/* Function:
    void DRV_USB_OHCI_PortReset(DRV_HANDLE handle, uint8_t port );
    
  Summary:
    Resets the specified root hub port.
    
  Description:
    This function resets the root hub port. The reset duration is defined by
    DRV_USB_OHCI_PORT_RESET_DURATION. The status of the reset signalling can be
    checked using the DRV_USB_OHCI_PortResetIsComplete() function.
    
  Remarks:
    Refer to drv_usb_ohci.h for usage information.
*/

USB_ERROR DRV_USB_OHCI_PortReset(DRV_HANDLE handle, uint8_t nPort)
{
    USB_ERROR returnValue = USB_ERROR_PARAMETER_INVALID;
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);
    DRV_USB_OHCI_OBJ * hDriver = NULL;
    volatile uint32_t * ohciPort = NULL;
    volatile UhpOhci * usbID = NULL; 
    
    if(drvIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBOHCIObj[drvIndex];
        if(hDriver->clientUniqueKey == clientUniqueKey)
        {
            if((nPort < DRV_USB_OHCI_PORTS_NUMBER) && (hDriver->ports[nPort].selected))
            {
                if(!hDriver->ports[nPort].isResetting)
                {
                    /* Reset the port only if a device is connected */
                    usbID = hDriver->usbID;
                    ohciPort = &usbID->UHP_OHCI_HCRHPORTSTATUS0;
                    if(ohciPort[nPort] & UHP_OHCI_HCRHPORTSTATUS0_CCS_Msk)
                    {
                        /* A device is connected on the port */
                        returnValue = USB_ERROR_NONE;
                        hDriver->ports[nPort].isResetting = true;
                        ohciPort[nPort] = UHP_OHCI_HCRHPORTSTATUS0_PRS_Msk;
                    }
                }
                else
                {
                    SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Reset already in progress");
                }
            }
            else
            {
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid port number or port number not selected");
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid handle in PortReset function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid Driver Instance in PortReset function");
    }

    return(returnValue);
}

// ****************************************************************************
/* Function:
    USB_SPEED DRV_USB_OHCI_PortSpeedGet
    (
        DRV_HANDLE handle,
        uint8_t port
    );

  Summary:
    Returns the speed of at which the port is operating.

  Description:
    This function returns the speed at which the port is operating.

  Remarks:
    Refer to drv_usb_ohci.h for usage information.
*/

USB_SPEED DRV_USB_OHCI_PortSpeedGet(DRV_HANDLE handle, uint8_t nPort)
{
    USB_SPEED returnValue = USB_SPEED_ERROR;
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);
    volatile UhpOhci * usbID = NULL;
    volatile uint32_t * ohciPort = NULL;
    DRV_USB_OHCI_OBJ * hDriver = NULL;
    
    DRV_USB_OHCI_PORT_OBJ * ports = NULL;

    if(drvIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBOHCIObj[drvIndex];
        usbID = hDriver->usbID;
        ohciPort = &usbID->UHP_OHCI_HCRHPORTSTATUS0;
        ports = &hDriver->ports[0];

        if(hDriver->clientUniqueKey == clientUniqueKey)
        {
            if((nPort < DRV_USB_OHCI_PORTS_NUMBER) && (ports[nPort].selected))
            {
                if((ohciPort[nPort] & UHP_OHCI_HCRHPORTSTATUS0_PES_Msk) != 0)
                {
                    /* This indicates that port is enabled and that can happen
                     * only when a high speed device is connected. */
                    returnValue = ports[nPort].portSpeed;
                }
            }
            else
            {
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid port number or port number not selected");
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid handle in PortReset function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid Driver Instance in PortReset function");
    }

    return(returnValue);
}

// ****************************************************************************
/* Function:
    bool DRV_USB_OHCI_PortResetIsComplete
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
    Refer to drv_usb_ohci.h for usage information.
*/

bool DRV_USB_OHCI_PortResetIsComplete
(
    DRV_HANDLE handle,
    uint8_t nPort
)
{
    bool returnValue = false;
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);
    DRV_USB_OHCI_OBJ * hDriver = NULL;

    if(drvIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBOHCIObj[drvIndex];

        if(hDriver->clientUniqueKey == clientUniqueKey)
        {
            if((nPort < DRV_USB_OHCI_PORTS_NUMBER) && (hDriver->ports[nPort].selected))
            {
                /* The isResetting flag is updated in the ISR function. That
                 * function will clear this flag when the reset is complete.
                 * */
                if(!hDriver->ports[nPort].isResetting)
                {
                    returnValue = true;
                }
            }
            else
            {
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid port number or port number not selected");
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid handle in PortReset function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid Driver Instance in PortReset function");
    }

    return(returnValue);

}

// ****************************************************************************
/* Function:
    void DRV_USB_OHCI_PortSuspend(DRV_HANDLE handle, uint8_t port );

  Summary:
    Suspends the specified root hub port.

  Description:
    This function suspends the root hub port.

  Remarks:
    Refer to drv_usb_ohci.h for more details.
*/

USB_ERROR DRV_USB_OHCI_PortSuspend(DRV_HANDLE handle, uint8_t port)
{
    /* The functionality is yet to be implemented. */
    return (USB_ERROR_NONE);
}

// ****************************************************************************
/* Function:
    void DRV_USB_OHCI_PortResume(DRV_HANDLE handle, uint8_t port );

  Summary:
    Resumes the specified root hub port.

  Description:
    This function resumes the root hub port.

  Remarks:
    Refer to drv_usb_ohci.h for more details.
*/

USB_ERROR DRV_USB_OHCI_PortResume(DRV_HANDLE handle, uint8_t port)
{
    /* The functionality is yet to be implemented. */
    return (USB_ERROR_NONE);
}


// ****************************************************************************
/* Function:
    USB_SPEED DRV_USB_OHCI_BusSpeedGet(DRV_HANDLE handle);

  Summary:
    Returns the speed at which the bus to which this root hub is connected is
    operating.

  Description:
    This function returns the speed at which the bus to which this root hub is
    connected is operating.

 Remarks:
    None.
*/

USB_SPEED DRV_USB_OHCI_BusSpeedGet(DRV_HANDLE handle)
{
    /* Validate the handle */
    USB_SPEED returnValue = USB_SPEED_ERROR;
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);

    if(drvIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
    {
        if(gDrvUSBOHCIObj[drvIndex].clientUniqueKey == clientUniqueKey)
        {
            /* The OHCI bus speed will always be high */
            returnValue = USB_SPEED_FULL;
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid handle in BusSpeedGet function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid instance in BusSpeedGet function");
    }

    return(returnValue);

} 

// ****************************************************************************
/* Function:
    uint32_t DRV_USB_OHCI_MaximumCurrentGet(DRV_HANDLE);

  Summary:
    Returns the maximum amount of current that this root hub can provide on the
    bus.

  Description:
    This function returns the maximum amount of current that this root hubn can
    provide on the bus.

  Remarks:
    Refer to drv_usb_ohci.h for usage information.
*/

uint32_t DRV_USB_OHCI_MaximumCurrentGet(DRV_HANDLE handle)
{
    uint32_t returnValue = 0;
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);

    if(drvIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
    {
        if(gDrvUSBOHCIObj[drvIndex].clientUniqueKey == clientUniqueKey)
        {
            returnValue = gDrvUSBOHCIObj[drvIndex].rootHubAvailableCurrent;
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid handle in MaximumCurrentGet function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid instance in MaximumCurrentGet function");
    }

    return(returnValue);
}

// ****************************************************************************
/* Function:
    uint8_t DRV_USB_OHCI_PortNumbersGet(DRV_HANDLE handle);

  Summary:
    Returns the number of ports this root hub contains.

  Description:
    This function returns the number of ports that this root hub contains.

  Remarks:
    None.
*/

uint8_t DRV_USB_OHCI_PortNumbersGet(DRV_HANDLE handle)
{
    uint8_t returnValue = 0;
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);

    if(drvIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
    {
        if(gDrvUSBOHCIObj[drvIndex].clientUniqueKey == clientUniqueKey)
        {
            /* Number of ports is contained in the NDP field of the 
             * HcRhDescriptorA register */

            returnValue = (uint8_t)((gDrvUSBOHCIObj[drvIndex].usbID->UHP_OHCI_HCRHDESCRIPTORA & UHP_OHCI_HCRHDESCRIPTORA_NDP_Msk));
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid handle in PortNumbersGet function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid instance in PortNumbersGet function");
    }

    return(returnValue);

}

// ****************************************************************************
/* Function:
    void DRV_USB_OHCI_RootHubInitialize
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

void DRV_USB_OHCI_RootHubInitialize
(
    DRV_HANDLE handle,
    USB_HOST_DEVICE_OBJ_HANDLE usbHostDeviceInfo
)
{
    uint16_t drvIndex = (uint16_t)(handle & 0xFFFF);
    uint16_t clientUniqueKey = (uint16_t)((handle & 0xFFFF0000) >> 16);

    if(drvIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
    {
        if(gDrvUSBOHCIObj[drvIndex].clientUniqueKey == clientUniqueKey)
        {
            /* Save the reference assigned by the host layer */
            gDrvUSBOHCIObj[drvIndex].usbHostDeviceInfo = usbHostDeviceInfo;
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid handle in RootHubInitialize function");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid instance in RootHubInitialize function");
    }

} 

// ****************************************************************************
/* Function:
    void DRV_USB_OHCI_EndpointToggleClear
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
    Refer to drv_usb_ohci.h for usage information.
*/

void DRV_USB_OHCI_EndpointToggleClear
(
    DRV_USB_OHCI_PIPE_HANDLE hPipe
)
{
    uint16_t clientUniqueKey = (uint16_t)((hPipe & 0xFFFF0000) >> 16);
    uint16_t pipeObjIndex = (uint16_t)(hPipe & 0xFF);
    int drvIndex = (int)((hPipe & 0xFF00) >> 8);
    DRV_USB_OHCI_ED * pipe = NULL;
    DRV_USB_OHCI_OBJ * hDriver = NULL;

    if(pipeObjIndex < USB_HOST_PIPES_NUMBER)
    {
        if(drvIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
        {
            /* Get the pointer to the pipe object from the driver instance
             * object. */
            hDriver = &gDrvUSBOHCIObj[drvIndex];
            pipe = &hDriver->endpointDescriptors[pipeObjIndex];
            
            if((pipe->clientUniqueKey == clientUniqueKey) && (pipe->pipeClosingState == DRV_USB_OHCI_PIPE_CLOSING_STATE_IDLE))
            {
                pipe->ed.c = 0;
            }
            else
            {
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid pipe handle in Endpoint Toggle Clear");
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid driver index in Endpoint Toggle Clear");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid Pipe index in Endpoint Toggle Clear");
    }


}

// ****************************************************************************
/* Function:
    bool DRV_USB_OHCI_IsCompanionControllerReady
    (
        SYS_MODULE_INDEX drvIndex
    )

  Summary:
    This function is called by the EHCI driver to check if the companion OHCI
    controller is ready to accept ownership of a port.

  Description:
    This function is called by the EHCI driver to check if the companion OHCI
    controller is ready to accept ownership of a port.
	
  Remarks:
    Refer to drv_usb_ohci.h for usage information.
*/

bool DRV_USB_OHCI_IsCompanionControllerReady
(
    SYS_MODULE_INDEX drvIndex
)
{
    bool returnValue = false;
    DRV_USB_OHCI_OBJ * hDriver = NULL;

    if(drvIndex < DRV_USB_OHCI_INSTANCES_NUMBER)
    {
        hDriver = &gDrvUSBOHCIObj[drvIndex];
        if((hDriver->inUse) && (hDriver->isOpened) && (hDriver->status == SYS_STATUS_READY) && (hDriver->operationEnabled))
        {
            /* Driver is ready to accept device */
            returnValue = true;
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nOHCI Driver: Invalid instance in IsCompanionControllerReady function");
    }
    
    return(returnValue);
}

// ****************************************************************************
/* Function:
    void DRV_USB_OHCI_Tasks_ISR(SYS_MODULE_OBJ moduleObj);

  Summary:
    Interrupt handler for the OHCI controller.

  Description:
    Interrupt handler for the OHCI controller.

  Remarks:
    This is a local function and should not be called directly by the
    applciations.
*/

void DRV_USB_OHCI_Tasks_ISR(SYS_MODULE_OBJ moduleObj)
{
    /* OHCI Driver Interrupt routine */

    DRV_USB_OHCI_OBJ * hDriver = NULL;
    uint32_t index = (uint32_t)(moduleObj);
    hDriver = &gDrvUSBOHCIObj[index];
    volatile UhpOhci * usbID = NULL;
    DRV_USB_OHCI_PORT_OBJ * port = NULL;
    uint32_t status = 0;
    int i = 0;
    DRV_USB_OHCI_ED * pipe = NULL;
    USB_OHCI_ED * ed = NULL;

    /* Set the Interrupt Context flag to let the downstream functions know that
     * driver is currently in an interrupt context. */
    hDriver->inInterruptContext = true;
    usbID = hDriver->usbID;
    volatile uint32_t * ohciPort = NULL;

    /* We need to check if the module master interrup is enabled. We need to 
     * check this because the ISR function will be called even there is an
     * EHCI interrupt */

    if((usbID->UHP_OHCI_HCINTERRUPTENABLE & UHP_OHCI_HCINTERRUPTENABLE_MIE_Msk) == UHP_OHCI_HCINTERRUPTENABLE_MIE_Msk)
    {
        /* Master Interrupt is enabled */

        status = usbID->UHP_OHCI_HCINTERRUPTSTATUS;
        usbID->UHP_OHCI_HCINTERRUPTSTATUS = status;
        status &= usbID->UHP_OHCI_HCINTERRUPTENABLE;

        ohciPort = &usbID->UHP_OHCI_HCRHPORTSTATUS0;

        if(status != 0)
        {
            /* We have a valid interrupt */

            if((status & UHP_OHCI_HCINTERRUPTSTATUS_SF_Msk) == UHP_OHCI_HCINTERRUPTSTATUS_SF_Msk)
            {
                /* This interrupt get enabled to keep track of the 
                 * SOF count during pipe closure. It is not enabled
                 * other wise. */

                hDriver->sofCount ++;
            }
            
            if((status & UHP_OHCI_HCINTERRUPTSTATUS_RHSC_Msk) == UHP_OHCI_HCINTERRUPTSTATUS_RHSC_Msk)
            {
                /* Root hub status has changed */
                ohciPort = &usbID->UHP_OHCI_HCRHPORTSTATUS0;

                /* There is a change in the root hub status */
                for(i = 0; i < DRV_USB_OHCI_PORTS_NUMBER; i ++)
                {
                    port = &hDriver->ports[i];

                    /* Check the status of each selected port */
                    if(port->selected == true)
                    {
                        if(ohciPort[i] & UHP_OHCI_HCRHPORTSTATUS1_CSC_Msk)
                        {
                            /* There was a change in the connection status. First clear the status change bit */
                            ohciPort[i] = UHP_OHCI_HCRHPORTSTATUS1_CSC_Msk;

                            if(ohciPort[i] & UHP_OHCI_HCRHPORTSTATUS1_CCS_Msk)
                            {
                                /* This means a device is connected. If the driver port state is 
                                 * waiting for attach, then lets start the attach process. */
                                if(port->portAttachState == DRV_USB_OHCI_PORT_ATTACH_STATE_WAITING_FOR_ATTACH)
                                {
                                    /* Start the attach debounce timer */
                                    port->portAttachState = DRV_USB_OHCI_PORT_ATTACH_STATE_START_ATTACH_DEBOUNCE;
                                }
                                else
                                {
                                    /* Getting an attach at any other point in the state leads nowhere */
                                }
                            }
                            else
                            {
                                /* There was a device disconnect */
                                if(port->portAttachState == DRV_USB_OHCI_PORT_ATTACH_STATE_WAIT_FOR_DETACH)
                                {
                                    /* This means that we should detach the device */
                                    if(port->attachedDeviceObjHandle != USB_HOST_DEVICE_OBJ_HANDLE_INVALID)
                                    {
                                        USB_HOST_DeviceDenumerate(port->attachedDeviceObjHandle);
                                        port->attachedDeviceObjHandle = USB_HOST_DEVICE_OBJ_HANDLE_INVALID;
                                    }

                                    port->portAttachState = DRV_USB_OHCI_PORT_ATTACH_STATE_WAITING_FOR_ATTACH;
                                    port->portSpeed = USB_SPEED_ERROR;
                                }
                                else
                                {
                                    /* Detaches in any other state will be handled in port tasks routine */
                                }
                            }
                        }

                        if(ohciPort[i] & UHP_OHCI_HCRHPORTSTATUS1_PRSC_Msk)
                        {
                            /* There was change in the Port Reset Status. Clear the
                             * status change bit. We have reached here because a port
                             * reset was requested. We clear the reset indicator in 
                             * port structure letting the caller know that reset is
                             * complete. */
                            ohciPort[i] = UHP_OHCI_HCRHPORTSTATUS1_PRSC_Msk;
                            port->isResetting = false;
                        }

                        if(ohciPort[i] & UHP_OHCI_HCRHPORTSTATUS0_PESC_Msk)
                        {
                            /* There was a change in the Port Enable Status.
                             * If the port was enabled and has been now disabled
                             * we should detach the device attached on the port
                             * and then move the port to waiting for attach state. */
                            ohciPort[i] = UHP_OHCI_HCRHPORTSTATUS1_PESC_Msk;
                            if((ohciPort[i] & UHP_OHCI_HCRHPORTSTATUS1_PES_Msk) != UHP_OHCI_HCRHPORTSTATUS1_PES_Msk)
                            {
                                /* We will let the port task routine complete rest of the disable */
                                port->disableThisPort = true;
                                if(port->attachedDeviceObjHandle != USB_HOST_DEVICE_OBJ_HANDLE_INVALID)
                                {
                                    USB_HOST_DeviceDenumerate(port->attachedDeviceObjHandle);
                                }
                            }
                        }

                        if(ohciPort[i] & UHP_OHCI_HCRHPORTSTATUS2_OCIC_Msk)
                        {
                            /* There is a change  in the over current indicator. 
                             * Check the port over current indicator. Clear the indicator. */
                            ohciPort[i] = UHP_OHCI_HCRHPORTSTATUS2_OCIC_Msk;
                            if((ohciPort[i] & UHP_OHCI_HCRHPORTSTATUS1_POCI_Msk) == UHP_OHCI_HCRHPORTSTATUS1_POCI_Msk)
                            {
                                port->disableThisPort = true;
                                if(port->attachedDeviceObjHandle != USB_HOST_DEVICE_OBJ_HANDLE_INVALID)
                                {
                                    USB_HOST_DeviceDenumerate(port->attachedDeviceObjHandle);
                                }
                            }
                        }
                    }
                }
            }

            if((status & UHP_OHCI_HCINTERRUPTSTATUS_WDH_Msk) == UHP_OHCI_HCINTERRUPTSTATUS_WDH_Msk)
            {
                /* This means some work got done. Check all the pipes */
                for(i = 0; i < USB_HOST_PIPES_NUMBER; i ++)
                {
                    pipe = &hDriver->endpointDescriptors[i];
                    if((pipe->inUse) && (pipe->pipeClosingState == DRV_USB_OHCI_PIPE_CLOSING_STATE_IDLE))
                    {
                        ed = &pipe->ed;
                        if(((ed->tailP == _DRV_USB_OHCI_ED_TO_DRV_HEADP(ed->headP)) || (ed->h == 1)) && (pipe->currentTD != NULL))
                        {
                            /* This means that something was scheduled on this pipe
                             * and the head and tail pointer are matching which 
                             * means that some activity was completed or 
                             * the halted bit is set which indicatees there is 
                             * some issue with pipe */

                            /* The queue handler function is the function that process the head
                             * TD of this pipe */

                            pipe->queueHandler(pipe, hDriver);
                        }
                    } 
                }
            }
        }
    }

    hDriver->inInterruptContext = false;
}

// ****************************************************************************
/* Function:
    void UHPHS_Handler(void)

  Summary:
    Interrupt handler for the OHCI controller.

  Description:
    Interrupt handler for the OHCI controller.

  Remarks:
    This is a local function and should not be called directly by the
    applciations. This function will compile in the OHCI driver only 
    if there is no EHCI controller driver included in the project.
*/

#ifdef DRV_USB_EHCI_INSTANCES_NUMBER
    #if (DRV_USB_EHCI_INSTANCES_NUMBER == 0)
    void UHP_Handler(void)
    {
        DRV_USB_OHCI_Tasks_ISR(sysObj.drvUSBOHCIObject);
    }
    #endif
#endif
