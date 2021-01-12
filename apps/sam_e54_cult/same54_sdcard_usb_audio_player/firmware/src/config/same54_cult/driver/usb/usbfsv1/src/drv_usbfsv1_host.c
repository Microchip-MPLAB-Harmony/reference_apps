/*******************************************************************************
  USB Host Controller Driver

  Company:
    Microchip Technology Inc.

  File Name:
    drv_usbfsv1_host.c

  Summary:
    USB Host Driver Implementation.

  Description:
    This file implements the Host mode operation of the Full Speed USB Driver.
    This file should be included in the application if USB Host mode operation
    is desired.
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

#include "driver/usb/usbfsv1/src/drv_usbfsv1_local.h"
#include "driver/usb/usbfsv1/drv_usbfsv1.h"
/**
 * \name USB SRAM data containing pipe descriptor table
 * The content of the USB SRAM can be :
 * - modified by USB hardware interface to update pipe status.
 *   Thereby, it is read by software.
 * - modified by USB software to control pipe.
 *   Thereby, it is read by hardware.
 * This data section is volatile.
 */

volatile COMPILER_WORD_ALIGNED usb_descriptor_host_registers_t pipeDescriptorTable[DRV_USBFSV1_INSTANCES_NUMBER][7];

/**********************************************************
 * This structure is a set of pointer to the USBFSV1 driver
 * functions. It is provided to the host and device layer
 * as the interface to the driver.
 * *******************************************************/
DRV_USB_HOST_INTERFACE gDrvUSBFSV1HostInterface =
{
    .open = DRV_USBFSV1_Open,
    .close = DRV_USBFSV1_Close,
    .eventHandlerSet = DRV_USBFSV1_ClientEventCallBackSet,
    .hostIRPSubmit = DRV_USBFSV1_HOST_IRPSubmit,
    .hostIRPCancel = DRV_USBFSV1_HOST_IRPCancel,
    .hostPipeSetup = DRV_USBFSV1_HOST_PipeSetup,
    .hostPipeClose = DRV_USBFSV1_HOST_PipeClose,
    .hostEventsDisable = DRV_USBFSV1_HOST_EventsDisable,
	.endpointToggleClear = DRV_USBFSV1_HOST_EndpointToggleClear,
    .hostEventsEnable = DRV_USBFSV1_HOST_EventsEnable,
    .rootHubInterface.rootHubPortInterface.hubPortReset = DRV_USBFSV1_HOST_ROOT_HUB_PortReset,
    .rootHubInterface.rootHubPortInterface.hubPortSpeedGet = DRV_USBFSV1_HOST_ROOT_HUB_PortSpeedGet,
    .rootHubInterface.rootHubPortInterface.hubPortResetIsComplete = DRV_USBFSV1_HOST_ROOT_HUB_PortResetIsComplete,
    .rootHubInterface.rootHubPortInterface.hubPortSuspend = DRV_USBFSV1_HOST_ROOT_HUB_PortSuspend,
    .rootHubInterface.rootHubPortInterface.hubPortResume = DRV_USBFSV1_HOST_ROOT_HUB_PortResume,
    .rootHubInterface.rootHubMaxCurrentGet = DRV_USBFSV1_HOST_ROOT_HUB_MaximumCurrentGet,
    .rootHubInterface.rootHubPortNumbersGet = DRV_USBFSV1_HOST_ROOT_HUB_PortNumbersGet,
    .rootHubInterface.rootHubSpeedGet = DRV_USBFSV1_HOST_ROOT_HUB_BusSpeedGet,
    .rootHubInterface.rootHubInitialize = DRV_USBFSV1_HOST_ROOT_HUB_Initialize,
    .rootHubInterface.rootHubOperationEnable = DRV_USBFSV1_HOST_ROOT_HUB_OperationEnable,
    .rootHubInterface.rootHubOperationIsEnabled = DRV_USBFSV1_HOST_ROOT_HUB_OperationIsEnabled,
};

/*****************************************************
 * Global Variable used as Pool of pipe objects 
 * that is used by all driver instances.
 *****************************************************/
DRV_USBFSV1_HOST_PIPE_OBJ gDrvUSBHostPipeObj[DRV_USBFSV1_HOST_PIPES_NUMBER];

/****************************************
 * The driver object
 ****************************************/
extern DRV_USBFSV1_OBJ gDrvUSBObj[];

/******************************************************************************
 * This matrix provides a mapping of the amount of bandwidth left in a frame for
 * a given transfer size. The number in the matrix is the percentage of
 * bandwidth consumer and the index of each entry is the Log2(N) of data payload
 * size. The first entry is for payload size 1, the second for payload size of
 * 2, the third for payload size of 8 and so on.
 ******************************************************************************/
const unsigned int gDrvUSBFSTableBW[4][11] =
{
    {3, 3, 3, 4, 4, 5, 7, 0, 0,  0,  0},    /* Control Transfers    */
    {1, 1, 1, 1, 2, 3, 5, 0, 0,  0,  0},    /* Interrupt Transfers  */
    {1, 1, 1, 1, 2, 3, 5, 0, 0,  0,  0},    /* Bulk Transfer        */
    {1, 1, 1, 1, 2, 3, 5, 9, 18, 35, 69}    /* Isochronous Transfer */
};      

const unsigned int gDrvUSBLSTableBW[2][4] =
{
    {26, 27, 28,30},    /* Control Transfers    */
    {11, 11, 12, 14}    /* Interrupt Transfers  */
};   

// ****************************************************************************
// ****************************************************************************
// Local Functions
// ****************************************************************************
// ****************************************************************************

void _DRV_USBFSV1_HOST_AttachDetachStateMachine (DRV_USBFSV1_OBJ * hDriver)
{
    usb_host_registers_t * HOST = &hDriver->usbID->HOST;
    _DRV_USBFSV1_DECLARE_BOOL_VARIABLE(interruptState);

    switch(hDriver->attachState)
    {
        case DRV_USBFSV1_HOST_ATTACH_STATE_CHECK_FOR_DEVICE_ATTACH:
            
            /* If no device is attached, then there is nothing to do
             * If device is attached, then move to next state */
            if(hDriver->deviceAttached)
            {
                hDriver->attachState = DRV_USBFSV1_HOST_ATTACH_STATE_DEBOUNCING;
            }

            break;

        case DRV_USBFSV1_HOST_ATTACH_STATE_DEBOUNCING:
            
            /* In this state we start the debouncing timer */
            
            hDriver->timerHandle = SYS_TIME_HANDLE_INVALID;
            if(SYS_TIME_ERROR != SYS_TIME_DelayMS(500, &(hDriver->timerHandle)))
            {
                hDriver->attachState = DRV_USBFSV1_HOST_ATTACH_STATE_DEBOUNCING_WAIT;
            } 

            break;

        case DRV_USBFSV1_HOST_ATTACH_STATE_DEBOUNCING_WAIT:

            /* In this state we check if the de-bouncing timer has expired */
            if(SYS_TIME_DelayIsComplete(hDriver->timerHandle))
            {
                hDriver->timerHandle = SYS_TIME_HANDLE_INVALID;
                
                /* This means the de-bouncing timer has expired. Check if the
                 * device is still attached. We can check the line state to 
                 * see if this is not SE0. If so, then we know that the device
                 * is still attached. */

                if((HOST->USB_STATUS & USB_HOST_STATUS_LINESTATE_Msk) != 0)
                {
                    /* Device is still attached.Clear the detach flag immediately
                     * if it was set because of debounce. Clear the attach flag
                     * as we are servicing the attach. */
                    
                    HOST->USB_INTFLAG = USB_HOST_INTFLAG_DCONN_Msk | USB_HOST_INTFLAG_DDISC_Msk;
                    
                    _DRV_USBFSV1_SYS_INT_SourceDisableSave(interruptState, hDriver->interruptSource,
                            interruptState1, hDriver->interruptSource1,interruptState2, hDriver->interruptSource2,
                            interruptState3, hDriver->interruptSource3)
                    
                    /* Enumerate from root hub port 0 */
                    hDriver->attachedDeviceObjHandle = USB_HOST_DeviceEnumerate(hDriver->usbHostDeviceInfo, 0);
                    
                    /* Enable the Detach Interrupt. Attach interrupt will be enabled 
                     * when a detach has been detected. */
                    HOST->USB_INTENSET = USB_HOST_INTFLAG_DDISC_Msk;
                    
                    /* Enable the global USB Interrupt */
                    _DRV_USBFSV1_SYS_INT_SourceEnableRestore(interruptState, hDriver->interruptSource,
                            interruptState1, hDriver->interruptSource1,interruptState2, hDriver->interruptSource2,
                            interruptState3, hDriver->interruptSource3);
                    
                    hDriver->attachState = DRV_USBFSV1_HOST_ATTACH_STATE_IDLE;
                }
                else
                {
                    /* This means the device is not attached. Because the device
                     * was attached we do not have to bother detaching it. It is 
                     * okay to rest the device attached flag here as none of the 
                     * interrupt that could modify this flag are enabled. */
                    
                    hDriver->deviceAttached = false;
                    
                    /* Clear the attach and detach flags and enable the detach event */
                    HOST->USB_INTFLAG = USB_HOST_INTFLAG_DCONN_Msk | USB_HOST_INTFLAG_DDISC_Msk;
                    
                    /* Enable the Detach Interrupt. Attach interrupt will be enabled 
                     * when a detach has been detected. */
                    HOST->USB_INTENSET = USB_HOST_INTFLAG_DCONN_Msk;
                    
                    /* Change the attach state machine state */
                    hDriver->attachState = DRV_USBFSV1_HOST_ATTACH_STATE_CHECK_FOR_DEVICE_ATTACH;
                }
            }

            break;
            
        case DRV_USBFSV1_HOST_ATTACH_STATE_IDLE:
            
            /* Check if the device has detach and then reset the state machine */
            if(!hDriver->deviceAttached)
            {
                hDriver->attachState = DRV_USBFSV1_HOST_ATTACH_STATE_CHECK_FOR_DEVICE_ATTACH;
            }
            
            break;

        default:
            break;
    }
}

// *****************************************************************************
/* Function:
    void _DRV_USBFSV1_HOST_Initialize
    (
        DRV_USBFSV1_OBJ * const pUSBDrvObj,
        const SYS_MODULE_INDEX index
    )

  Summary:
    This function initializes the driver for host mode operation.

  Description:
    Function performs the following tasks:
      - Informs the USB module with SOF threshold in bit times
      - Enables VBUS power and initializes the module in HOST mode
      - Resets the BDT table data structure with init value
      - Configures EP0 register for the specific USB module
      - Enables the USB attach interrupt

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/
void _DRV_USBFSV1_HOST_Initialize
(
    DRV_USBFSV1_OBJ * drvObj, 
    SYS_MODULE_INDEX index,
    DRV_USBFSV1_INIT * usbInit
)
{
    /* No device attached */
    drvObj->deviceAttached = false;

    /* Initialize the device handle */
    drvObj->attachedDeviceObjHandle = USB_HOST_DEVICE_OBJ_HANDLE_INVALID;

    /* Initialize the host specific members in the driver object */
    drvObj->isResetting     = false;
    drvObj->usbHostDeviceInfo = USB_HOST_DEVICE_OBJ_HANDLE_INVALID;
    drvObj->operationEnabled = false;
    drvObj->timerHandle = SYS_TIME_HANDLE_INVALID;
    drvObj->hostPipeDescTable = (usb_descriptor_host_registers_t *)&pipeDescriptorTable[index][0];
    drvObj->usbID->HOST.USB_DESCADD = (uint32_t)drvObj->hostPipeDescTable;

    /* The root hub information is applicable for host mode operation. */
    drvObj->rootHubInfo.rootHubAvailableCurrent = usbInit->rootHubAvailableCurrent;
    drvObj->rootHubInfo.portIndication = usbInit->portIndication;
    drvObj->rootHubInfo.portOverCurrentDetect = usbInit->portOverCurrentDetect;
    drvObj->rootHubInfo.portPowerEnable = usbInit->portPowerEnable;

    /* Set USB module mode as host */
    drvObj->usbID->HOST.USB_CTRLA |= USB_CTRLA_MODE_HOST;

    /* Prior to device detection the software must set the VBUS is OK
     * bit in CTRLB (CTRLB.VBUSOK) register when the VBUS is available. */
    /* The USB module is notified that the VBUS on the USB line is powered. */
    drvObj->usbID->HOST.USB_CTRLB |= USB_HOST_CTRLB_VBUSOK_Msk;

    /* Clear and enabled the global USB Interrupt here. */
    _DRV_USBFSV1_SYS_INT_SourceStatusClear(usbInit->interruptSource, usbInit->interruptSource1,
            usbInit->interruptSource2, usbInit->interruptSource3);

    _DRV_USBFSV1_SYS_INT_SourceEnable(usbInit->interruptSource, usbInit->interruptSource1,
            usbInit->interruptSource2, usbInit->interruptSource3);
}

// *****************************************************************************
/* Function:
    USB_ERROR DRV_USBFSV1_HOST_IRPSubmit
    (
        DRV_USBFSV1_HOST_PIPE_HANDLE  hPipe,
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
    See drv_usbfs.h for usage information.
*/

USB_ERROR DRV_USBFSV1_HOST_IRPSubmit
(
    DRV_USBFSV1_HOST_PIPE_HANDLE  hPipe,
    USB_HOST_IRP * pInputIRP
)
{
    USB_HOST_IRP_LOCAL * pIRPIterator = (USB_HOST_IRP_LOCAL *)NULL;
    _DRV_USBFSV1_DECLARE_BOOL_VARIABLE(interruptState);
    USB_HOST_IRP_LOCAL * pIRP = (USB_HOST_IRP_LOCAL *)pInputIRP;
    DRV_USBFSV1_HOST_PIPE_OBJ * pPipe = (DRV_USBFSV1_HOST_PIPE_OBJ *)hPipe;
    DRV_USBFSV1_OBJ * pUSBDrvObj = (DRV_USBFSV1_OBJ *)NULL;
    USB_ERROR returnValue = USB_ERROR_NONE;

    if((pPipe != NULL) && (pPipe != (DRV_USBFSV1_HOST_PIPE_OBJ *)DRV_USBFSV1_HOST_PIPE_HANDLE_INVALID))
    {
        pUSBDrvObj = (DRV_USBFSV1_OBJ *)(pPipe->hClient);

        /* Assign owner pipe */
        pIRP->pipe = hPipe;

        /* Clear up any temporary state */
        pIRP->tempState = 0;

        /* Control transfer IRPs have to be implemented in states. These sub states
         * are maintained in the tempState member of the IRP. A control transfer IRP
         * must start with the SETUP stage */

        if(pPipe->pipeType == USB_TRANSFER_TYPE_CONTROL)
        {
            /* Then we setup the IRP for setup stage */
            pIRP->tempState = DRV_USBFSV1_HOST_IRP_STATE_SETUP_STAGE;
        }

        pIRP->status = USB_HOST_IRP_STATUS_PENDING;

        /* Add the IRP to the pipe. We need to disable the USB interrupt here
         * because the USB interrupt updates the pipe structure asynchronously. */

        if(!(pUSBDrvObj->isInInterruptContext))
        {
            /* The mutex protects the interrupt state from manipulation from other
             * thread that want to submit IRPs. If another thread reaches this point
             * it will block waiting on this mutex. Additionally the mutex should be
             * grabbed only if this function is not executing in an interrupt
             * context. A thread can submit an IRP in an event handler is invoked
             * from the ISR. */

            if(OSAL_MUTEX_Lock(&pUSBDrvObj->mutexID, OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
            {
                /* Disable the interrupt */
                _DRV_USBFSV1_SYS_INT_SourceDisableSave(interruptState, pUSBDrvObj->interruptSource,
                        interruptState1, pUSBDrvObj->interruptSource1, interruptState2, pUSBDrvObj->interruptSource2,
                        interruptState3, pUSBDrvObj->interruptSource3);
            }
            else
            {
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nUSBFSV1 Driver: Mutex lock failed");
                returnValue = USB_ERROR_OSAL_FUNCTION;
            }
        }

        if(returnValue == USB_ERROR_NONE)
        {
            /* Add the IRP to the queue */
            if(pPipe->irpQueueHead == NULL)
            {
                /* This means that there are no IRPs on this pipe. We can add this IRP
                 * directly */

                pIRP->next = NULL;
                pPipe->irpQueueHead = pIRP;
            }
            else
            {
                /* The pipe queue is not empty. Add the IRP to the last IRP in the pipe
                 * queue */

                pIRPIterator = pPipe->irpQueueHead;

                /* Find the last IRP in the linked list*/
                while(pIRPIterator->next != NULL)
                {
                    pIRPIterator = pIRPIterator->next;
                }

                /* Add the item to the last irp in the linked list */
                pIRPIterator->next = pIRP;
            }

            /* Initialize the hidden members */
            pIRP->next = NULL;
            pIRP->completedBytes = 0;
            pIRP->tempSize = 0;

            if(!(pUSBDrvObj->isInInterruptContext))
            {
                /* While exiting the routine, restore the interrupt context and then
                 * release the mutex. Any thread that is blocked on this mutex will be
                 * able to now manipulate the interrupt and submit the IRP */

                _DRV_USBFSV1_SYS_INT_SourceEnableRestore(interruptState, pUSBDrvObj->interruptSource,
                        interruptState1, pUSBDrvObj->interruptSource1, interruptState2, pUSBDrvObj->interruptSource2,
                        interruptState3, pUSBDrvObj->interruptSource3);

                OSAL_MUTEX_Unlock(&pUSBDrvObj->mutexID);
            }
        }
    }
    else
    {
        /* Pipe is not valid */
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nUSBFSV1 Driver: NULL pipe");
        returnValue = USB_ERROR_HOST_PIPE_INVALID;
    }

    return (returnValue);
}

// *****************************************************************************
/* Function:
    void DRV_USBFSV1_HOST_IRPCancel(USB_HOST_IRP * pinputIRP)

  Summary:
    Cancels the specified IRP.
    
  Description:
    This function attempts to cancel the specified IRP. If the IRP is queued and
    its processing has not started, it will be cancelled successfully. If the
    IRP in progress, the ongoing transaction will be allowed to complete. 

  Remarks:
    See drv_usbfs.h for usage information.
*/

void DRV_USBFSV1_HOST_IRPCancel
(
    USB_HOST_IRP * inputIRP
)
{
    /* This function cancels an IRP */

    USB_HOST_IRP_LOCAL * irp = (USB_HOST_IRP_LOCAL *) inputIRP;
    USB_HOST_IRP_LOCAL * pIteratorIRP = NULL;
    _DRV_USBFSV1_DECLARE_BOOL_VARIABLE(interruptState);
    DRV_USBFSV1_OBJ * hDriver;
    DRV_USBFSV1_HOST_PIPE_OBJ * pipe;
    bool thereWasAnError = false;
    bool irpCancel = false;
    
    if(inputIRP != NULL)
    {
        /* IRP is not NULL. Continue */
        if((irp->pipe != DRV_USBFSV1_HOST_PIPE_HANDLE_INVALID) && ((DRV_USBFSV1_HOST_PIPE_OBJ *)(irp->pipe))!= NULL)
        {
            /* Pipe appears valid. Lets Continue */

            pipe = (DRV_USBFSV1_HOST_PIPE_OBJ *)(irp->pipe);
            hDriver = (DRV_USBFSV1_OBJ *) pipe->hClient;

            if(!hDriver->isInInterruptContext)
            {
                if(OSAL_MUTEX_Lock(&(hDriver->mutexID), OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
                {
                    _DRV_USBFSV1_SYS_INT_SourceDisableSave(interruptState, hDriver->interruptSource,
                        interruptState1, hDriver->interruptSource1, interruptState2, hDriver->interruptSource2,
                        interruptState3, hDriver->interruptSource3);
                }
                else
                {
                    thereWasAnError = true;
                    SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Mutex lock failed");
                }
            }
            else
            {
                /* Driver is not in interrupt context */
            }

            if(!thereWasAnError)
            {
                if(irp->status > USB_HOST_IRP_STATUS_COMPLETED_SHORT)
                {
                    /* No error so far and IRP is in progress. So we 
                     * can continue with the cancel operation. Check if this the
                     * first IRP in the queue. */
                    pIteratorIRP = pipe->irpQueueHead;
                    
                    if(pIteratorIRP == irp)
                    {
                        pipe->irpQueueHead = irp->next;
                        irpCancel = true;
                    }
                    else
                    {
                        while(pIteratorIRP != NULL)
                        {
                            if(pIteratorIRP->next == irp)
                            {
                                /* We have found the IRP in the linked list.
                                 * Remove the IRP from the list and then
                                 * stop searching. */
                                pIteratorIRP->next = irp->next;
                                irpCancel = true;
                                break;
                            }
                            
                            pIteratorIRP = pIteratorIRP->next;
                        }
                    }
                    
                    if(irpCancel == true)
                    {
                        if(irp->status == USB_HOST_IRP_STATUS_IN_PROGRESS)
                        {
                            /* If the IRP is in progress we update the temp
                             * state and let the acutal IRP cancel happen 
                             * in the transaction interrupt*/
                            irp->tempState = DRV_USBFSV1_HOST_IRP_STATE_ABORTED;
                        }
                        else
                        {
                            /* We can terminate the IRP immediately*/
                            irp->status = USB_HOST_IRP_STATUS_ABORTED;
                            if(irp->callback != NULL)
                            {
                                irp->callback((USB_HOST_IRP *)irp);
                            }
                        }
                    }
                    else
                    {
                        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Could not find IRP in IRP Cancel");
                    }
                }
                else
                {
                    SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: IRP has already retired in IRP Cancel");
                }
            }
            
            if(!hDriver->isInInterruptContext)
            {
                /* Restore the interrupt and release the mutex */
                _DRV_USBFSV1_SYS_INT_SourceEnableRestore(interruptState, hDriver->interruptSource,
                        interruptState1, hDriver->interruptSource1, interruptState2, hDriver->interruptSource2,
                        interruptState3, hDriver->interruptSource3);

                OSAL_MUTEX_Unlock(&(hDriver->mutexID));
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Invalid Pipe in IRP Cancel");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Invalid IRP in IRP Cancel");
    }
}

// *****************************************************************************
/* Function:
     void DRV_USBFSV1_HOST_PipeClose(DRV_USBFSV1_HOST_PIPE_HANDLE pipeHandle)

  Summary:
    Closes an open pipe.
	
  Description:
    This function closes an open pipe. Any IRPs scheduled on the pipe will be
    aborted and IRP callback functions will be called with the status as
    DRV_USB_HOST_IRP_STATE_ABORTED. The pipe handle will become invalid and the
    pipe will not accept IRPs.

  Remarks:
    See drv_usbfs.h for usage information.
*/

void DRV_USBFSV1_HOST_PipeClose
(
    DRV_USBFSV1_HOST_PIPE_HANDLE pipeHandle
)
{
    /* This function closes an open pipe */

    _DRV_USBFSV1_DECLARE_BOOL_VARIABLE(interruptState);

    DRV_USBFSV1_OBJ * hDriver = NULL;
    USB_HOST_IRP_LOCAL * irp = NULL;
    DRV_USBFSV1_HOST_PIPE_OBJ * pipe = NULL;
    DRV_USBFSV1_HOST_PIPE_OBJ * pIteratorPipe = NULL;
    DRV_USBFSV1_HOST_PIPE_GROUP * pipeGroup = NULL;
    bool thereWasAnError = false;

    /* Make sure we have a valid pipe */
    if(( pipeHandle != 0 ) && (pipeHandle != DRV_USBFSV1_HOST_PIPE_HANDLE_INVALID))
    {
        pipe = (DRV_USBFSV1_HOST_PIPE_OBJ*) pipeHandle;

        /* Make sure that we are working with a pipe in use */
        if(pipe->inUse == true)
        {
            hDriver = (DRV_USBFSV1_OBJ *)pipe->hClient;
            
            /* Disable the interrupt. This function could be called from
             * the detach event that is executing in an interrupt context. */
            if(!hDriver->isInInterruptContext)
            {
                if(OSAL_MUTEX_Lock(&hDriver->mutexID, OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
                {
                    _DRV_USBFSV1_SYS_INT_SourceDisableSave(interruptState, hDriver->interruptSource,
                            interruptState1, hDriver->interruptSource1, interruptState2, hDriver->interruptSource2,
                            interruptState3, hDriver->interruptSource3);
                }
                else
                {
                      SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Mutex lock failed");
                      thereWasAnError = true;
                }
            }
            
            if(!thereWasAnError)
            {
                pipeGroup = &hDriver->pipeGroup[pipe->pipeGroupIndex];

                if(pipeGroup->pipe == pipe)
                {
                    /* This is the first pipe in the . Remove the pipe
                     * and reduce the pipe count. */
                    pipeGroup->pipe = pipe->next;
                    pipeGroup->nPipes --;
                }
                else
                {
                    /* Iterate through the pipe group and search for 
                     * pipe till we have reached the end of the pipe. */
                    pIteratorPipe = pipeGroup->pipe;
                    while((pIteratorPipe != NULL) && (pIteratorPipe->next != pipe))
                    {
                        pIteratorPipe = pIteratorPipe->next;
                    }

                    /* Make sure we have a valid pipe */
                    if(pIteratorPipe == NULL)
                    {
                        /* This is a strange case. The pipe is in use but is not
                         * part of transfer group. This would be a orphan pipe. */

                        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nUSBFSV1 Driver: Illegal pipe handle");
                        thereWasAnError = true;
                    }
                    else
                    {
                        /* Remove the pipe from the group*/
                        pIteratorPipe->next = pipe->next;
                        pipeGroup->nPipes --;
                    }
                }

                if (!thereWasAnError)
                {
                    /* Now we invoke the call back for each IRP in this pipe and
                     * say that it is aborted.  If the IRP is in progress, then
                     * that IRP will be actually aborted on the next SOF unless
                     * the device is being detached. If the device is being
                     * detached, then we could potentially land in a situation
                     * where the IRP temp state says aborted, but the pipe
                     * interrupt will never occur and then IRP will never be
                     * aborted. Deferring the IRP abort allows the USB module to
                     * complete any transaction that was in progress. */

                    irp = pipe->irpQueueHead;
                    while(irp != NULL)
                    {
                        irp->pipe = DRV_USBFSV1_HOST_PIPE_HANDLE_INVALID;

                        if((irp->status == USB_HOST_IRP_STATUS_IN_PROGRESS) && (hDriver->isDeviceDeenumerating == false))
                        {
                            /* If the IRP is in progress and device
                             * de-enumeration operation is not in progress, then
                             * we set the temp IRP state.  This will be caught
                             * in the _DRV_USBFS_HOST_NonControlIRPProcess() and
                             * _DRV_USBFS_HOST_ControlXferProcess() functions */

                            irp->tempState = DRV_USBFSV1_HOST_IRP_STATE_ABORTED;
                        }
                        else
                        {
                            /* The IRP is not in progress or the IRP is in
                             * progress or device de-enumeration is also in
                             * progress because of device detach, then the IRP
                             * needs to be aborted. We cannot wait for
                             * transaction interrupt as there will be no
                             * interrupt post device detach */

                            irp->status = USB_HOST_IRP_STATUS_ABORTED;
                            if(irp->callback != NULL)
                            {
                                irp->callback((USB_HOST_IRP*)irp);
                            }
                        }

                        irp = irp->next;
                    }

                    /* Irrespective of whether the pipe is orphan or not, we return
                     * the pipe back to the driver */

                    pipe->inUse = false;

                    /* Restore the interrupts */
                    if(!(hDriver->isInInterruptContext))
                    {
                        _DRV_USBFSV1_SYS_INT_SourceEnableRestore(interruptState, hDriver->interruptSource,
                          interruptState1, hDriver->interruptSource1, interruptState2, hDriver->interruptSource2,
                          interruptState3, hDriver->interruptSource3);

                        OSAL_MUTEX_Unlock(&hDriver->mutexID);
                    }
                }
            }
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Pipe is not in use");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Invalid pipe handle");
    }
}

// *****************************************************************************
/* Function:
    DRV_USBFSV1_HOST_PIPE_HANDLE DRV_USBFSV1_HOST_PipeSetup
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
    See drv_usbfs.h for usage information.
*/

DRV_USBFSV1_HOST_PIPE_HANDLE DRV_USBFSV1_HOST_PipeSetup
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
)
{
    DRV_USBFSV1_HOST_PIPE_OBJ * pPipe = (DRV_USBFSV1_HOST_PIPE_OBJ *)NULL;
    DRV_USBFSV1_HOST_PIPE_OBJ * piteratorPipe = (DRV_USBFSV1_HOST_PIPE_OBJ *)NULL;
    DRV_USBFSV1_OBJ * pUSBDrvObj = (DRV_USBFSV1_OBJ *)client;
    DRV_USBFSV1_HOST_PIPE_HANDLE returnValue = DRV_USBFSV1_HOST_PIPE_HANDLE_INVALID;
    DRV_USBFSV1_HOST_PIPE_GROUP * pPipeGroup = (DRV_USBFSV1_HOST_PIPE_GROUP *)NULL;
    unsigned int pipeGroupIndex = 0;
    unsigned int bandwidthTableIndex = 0;
    uint8_t pipeCount = 0;
    uint8_t bitSetCount = 0;
    bool thereWasAnError = false;
    
    if((client != DRV_HANDLE_INVALID) && (pUSBDrvObj != NULL) && (pUSBDrvObj->isOpened))
    {
        /* Driver handle is valid. We need to grab a mutex as the pipe pool is a
         * global object */
        if(OSAL_MUTEX_Lock(&pUSBDrvObj->mutexID, OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
        {
            /* Search for a free pipe object */
            for(pipeCount = 0; pipeCount < DRV_USBFSV1_HOST_PIPES_NUMBER; pipeCount++)
            {
                /* Check for free pipe object */
                if(gDrvUSBHostPipeObj[pipeCount].inUse == false)
                {
                    /* We found a pipe object that we can use.  Go and grab that
                     * one.  */
                    gDrvUSBHostPipeObj[pipeCount].inUse = true;

                    /* Initialize the pipe object */
                    pPipe = &gDrvUSBHostPipeObj[pipeCount];

                    pPipe->deviceAddress = deviceAddress;
                    pPipe->irpQueueHead = NULL;
                    pPipe->bInterval = bInterval;
                    pPipe->speed = speed;
                    pPipe->pipeType = pipeType;
                    pPipe->hClient = client;
                    pPipe->endpointSize = wMaxPacketSize;
                    pPipe->intervalCounter = bInterval;
                    pPipe->bInterval = bInterval;
                    pPipe->dataToggle = 0;

                    pPipe->endpointAndDirection = endpointAndDirection;

                    /* We need to calculate the bandwidth per transaction and
                     * then assign the pipe to correct pipe group based on the
                     * pipe type. Note that the pipe group index is the same as
                     * the index of the hardware pipe which will be used to
                     * process the pipe. */

                    switch(pPipe->pipeType)
                    {
                        case USB_TRANSFER_TYPE_CONTROL:
                            bandwidthTableIndex = 0 ;
                            pipeGroupIndex = DRV_USBFSV1_HOST_HW_PIPE_CONTROL;
                            
                            /* The pipe max packet size as defined by the hardware */
                            pPipe->pckSize = 3;
                            if(pPipe->speed == USB_SPEED_LOW)
                            {
                                pPipe->pckSize = 0;
                            }
                            
                            break;

                        case USB_TRANSFER_TYPE_ISOCHRONOUS:
                            bandwidthTableIndex = 3;
                            pipeGroupIndex = (endpointAndDirection & 0x80) == 0x80 ? DRV_USBFSV1_HOST_HW_PIPE_ISOC_IN : DRV_USBFSV1_HOST_HW_PIPE_ISOC_OUT;
                            pPipe->pckSize = 0x7;
                            break;

                        case USB_TRANSFER_TYPE_BULK:
                            bandwidthTableIndex = 2;
                            pipeGroupIndex = (endpointAndDirection & 0x80) == 0x80 ? DRV_USBFSV1_HOST_HW_PIPE_BULK_IN : DRV_USBFSV1_HOST_HW_PIPE_BULK_OUT;
                            pPipe->pckSize = 3;
                            break;

                        case USB_TRANSFER_TYPE_INTERRUPT:
                            bandwidthTableIndex = 1;
                            pipeGroupIndex = (endpointAndDirection & 0x80) == 0x80 ? DRV_USBFSV1_HOST_HW_PIPE_INT_IN : DRV_USBFSV1_HOST_HW_PIPE_INT_OUT;
                            
                            /* The pipe max packet size as defined by the hardware */
                            pPipe->pckSize = 3;
                            if(pPipe->speed == USB_SPEED_LOW)
                            {
                                pPipe->pckSize = 0;
                            }
                            break;

                        default:
                            return returnValue;
                    }
                    
                    /* Update the pipe group index in the pipe object. This
                     * simplifies code at the time of pipe close. */
                    pPipe->pipeGroupIndex = pipeGroupIndex;
                    
                    /* In a case where the max packet size is a multiple of 2,
                     * find calculate the log2n. */
                    if((wMaxPacketSize <= 512) && (wMaxPacketSize != 0))
                    {
                        for(bitSetCount = 0; bitSetCount < 10; bitSetCount++)
                        {
                            if((wMaxPacketSize & 0x00000001) == 0x00000001)
                            {
                                break;
                            }
                            wMaxPacketSize = wMaxPacketSize >> 1;
                        }
                    }
                    else if((wMaxPacketSize != 0))
                    {
                        /* This means the max packet size is greater than 512. This
                         * is possible for Isochronous transfers */

                        bitSetCount = 10;
                    }

                    /* The bandwidth required per transaction is calculated up
                     * front so that we dont have to calculate this in the
                     * interrupt context when the transaction is in progress */

                    if(bitSetCount != 10)
                    {
                        if(pPipe->speed == USB_SPEED_LOW)
                        {
                            if((pPipe->pipeType == USB_TRANSFER_TYPE_INTERRUPT) || (pPipe->pipeType == USB_TRANSFER_TYPE_CONTROL))
                            {
                                pPipe->bwPerTransaction = gDrvUSBLSTableBW[bandwidthTableIndex][bitSetCount];
                            }
                            else
                            {
                                /* Only control and interrupt pipe can exist in
                                   low speed */
                                thereWasAnError = true;
                            }
                        }
                        else
                        {
                            pPipe->bwPerTransaction = gDrvUSBFSTableBW[bandwidthTableIndex][bitSetCount];
                        }
                    }
                    else if(bitSetCount == 10 && pPipe->pipeType == USB_TRANSFER_TYPE_ISOCHRONOUS && pPipe->speed == USB_SPEED_FULL)
                    {
                        /* Bandwidth for Isochronous transfers */
                        pPipe->bwPerTransaction = gDrvUSBFSTableBW[bandwidthTableIndex][bitSetCount];
                    }
                    else
                    {
                        /* Error */
                        thereWasAnError = true;
                    }

                    if(!thereWasAnError)
                    {
                        /* This pipe should be added to the respective pipe group */

                        pPipeGroup = &(pUSBDrvObj->pipeGroup[pipeGroupIndex]);

                        if(pPipeGroup->pipe == NULL)
                        {
                            /* This if the first pipe to be setup */
                            pPipeGroup->pipe = pPipe;
                            pPipeGroup->currentPipe = pPipe;
                        }
                        else
                        {
                            /* This is NOT the first pipe. Find the last pipe in the
                             * linked list */
                            piteratorPipe = pPipeGroup->pipe;
                            while(piteratorPipe->next != NULL)
                            {
                                /* This is not the last pipe in this transfer group */
                                piteratorPipe = piteratorPipe->next;
                            }
                            piteratorPipe->next = pPipe;
                        }

                        pPipe->next = NULL;

                        /* Update the pipe count in the transfer group */
                        pPipeGroup->nPipes ++;
                        returnValue = (DRV_USBFSV1_HOST_PIPE_HANDLE)pPipe;
                    }
                    else
                    {
                        /* There was some error. Return the pipe object */
                        gDrvUSBHostPipeObj[pipeCount].inUse = false;
                    }

                    /* We found a pipe and allocated it or found it but were not
                     * able to allocate it due to errors in pipe parameters. In
                     * either case we must break */
                    break;
                }
            } 

            /* If we could not find a pipe, then just put a message saying so */
            if(returnValue == DRV_USBFSV1_HOST_PIPE_HANDLE_INVALID)
            {
                SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nUSBFSV1 Driver: Could not find a free pipe object");
            }

            /* Release the mutex */
            OSAL_MUTEX_Unlock(&pUSBDrvObj->mutexID);
        }
        else
        {
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nUSBFSV1 Driver: Mutex lock failed");
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nUSBFSV1 Driver: Bad Client or client closed");
    }
      
    return(returnValue);
}

// *****************************************************************************
/* Function:
    void _DRV_USBFSV1_HOST_ControlTransferDataStageSend(DRV_USBFSV1_OBJ * hDriver)

  Summary:
    This function will process transfer the data stage of the control transfer.
	
  Description:
    Thsi function will transfer the data stage of the control transfer. It is
    called by the _DRV_USBFSV1_HOST_ControlTransferProcess function. The
    function will look at the status of the IRP at index 0 of the Frame IRP list
    and will schedule the next transaction. There will always be a transaction
    launched on the bus at the end of this function.

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/

void _DRV_USBFSV1_HOST_ControlTransferDataStageSend(DRV_USBFSV1_OBJ * hDriver)
{
    DRV_USBFSV1_HOST_PIPE_GROUP * pipeGroup = &hDriver->pipeGroup[DRV_USBFSV1_HOST_HW_PIPE_CONTROL];
    DRV_USBFSV1_HOST_PIPE_OBJ * pipe = pipeGroup->currentPipe;
    USB_HOST_IRP_LOCAL * pIRP = pipeGroup->currentIRP;
    int size = 0;
    usb_host_registers_t * HOST = &hDriver->usbID->HOST;
    usb_host_desc_bank_registers_t * controlPipeDesc = &hDriver->hostPipeDescTable[DRV_USBFSV1_HOST_HW_PIPE_CONTROL].HOST_DESC_BANK[0];
    usb_host_pipe_registers_t * controlPipe = &HOST->HOST_PIPE[DRV_USBFSV1_HOST_HW_PIPE_CONTROL]; 
    
    /* How much data do we need to send */
    if((pIRP->tempSize - pIRP->completedBytesInThisFrame) >= pipe->endpointSize)
    {
        /* Cap the size in case we have too much to send */
        size = pipe->endpointSize;
    }
    else
    {
        size = pIRP->tempSize - pIRP->completedBytesInThisFrame;
    }
   
    /* Set up the buffer address and the packet size. Prep the token type field
     * and then enable the transfer interrupt. Set the bank 0 ready bit. */
    controlPipeDesc->USB_ADDR = (uint32_t)(hDriver->hostTransactionBuffer);
    controlPipeDesc->USB_CTRL_PIPE &= ~(USB_HOST_CTRL_PIPE_PDADDR_Msk);
    controlPipeDesc->USB_CTRL_PIPE |= (pipe->deviceAddress << USB_HOST_CTRL_PIPE_PDADDR_Pos);
    controlPipeDesc->USB_PCKSIZE = 0;
    controlPipeDesc->USB_PCKSIZE = (USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(0)|USB_HOST_PCKSIZE_BYTE_COUNT(size)
                    |USB_HOST_PCKSIZE_AUTO_ZLP(0)|USB_HOST_PCKSIZE_SIZE(pipe->pckSize));
    controlPipe->USB_PCFG &= ~(USB_HOST_PCFG_PTOKEN_Msk);
    
    /* Clear the interrupt flags and then enable the interrupts. */
    controlPipe->USB_PINTFLAG = USB_HOST_PINTFLAG_Msk;
    controlPipe->USB_PINTENSET = USB_HOST_PINTENSET_PERR_Msk|
                    USB_HOST_PINTENSET_STALL_Msk|USB_HOST_PINTENSET_TRFAIL_Msk|USB_HOST_PINTENSET_TRCPT0_Msk;
    
    /* Update the data toggle */
    if(pipe->dataToggle == 1)
    {
        controlPipe->USB_PSTATUSSET = USB_HOST_PSTATUSSET_DTGL_Msk;
    }
    else
    {
        controlPipe->USB_PSTATUSCLR = USB_HOST_PSTATUSCLR_DTGL_Msk;
    }
    
    /* Check the direction and set the token type */
    if((pipe->endpointAndDirection & 0x80) != 0)
    {
        /* Bank 0 is ready to receive data */
        controlPipe->USB_PSTATUSCLR = USB_HOST_PSTATUSCLR_BK0RDY_Msk;
        controlPipe->USB_PCFG |= DRV_USBFSV1_HOST_PIPE_TOKEN_IN;
    }
    else
    {
        /* Bank 0 contains the data. User data must be copied to the host
         * control transfer data buffer. */
        memcpy(hDriver->hostTransactionBuffer, ( ( uint8_t * )pIRP->data + pIRP->completedBytes), size);
        controlPipe->USB_PSTATUSSET = USB_HOST_PSTATUSSET_BK0RDY_Msk;
        controlPipe->USB_PCFG |= DRV_USBFSV1_HOST_PIPE_TOKEN_OUT;
    }
    
    /* Unfreeze the pipe. This launches the token */
    controlPipe->USB_PSTATUSCLR = USB_HOST_PSTATUSCLR_PFREEZE_Msk;
}

// *****************************************************************************
/* Function:
    bool _DRV_USBFSV1_HOST_ControlTransferProcess
    (
        DRV_USBFSV1_OBJ * hDriver
    )

  Summary:
    Control Transfer Process.
	
  Description:
    This function is called to start and continue the processing of a control
    transfer in the frame IRP list. It is either called from the SOF interrupt
    or from the pipe 0 interrupt.

  Remarks:
    This is a local function and should not be called by the application.
*/

bool _DRV_USBFSV1_HOST_ControlTransferProcess(DRV_USBFSV1_OBJ * hDriver)
{
    /* This function returns true if a token was sent at the time when the
     * function exits. Get the pointer to the control transfer. This is always 
     * at index 0 in the frame IRP list */
    
    USB_HOST_IRP_LOCAL * pIRP = hDriver->frameIRPList[0].pIRP;
    DRV_USBFSV1_HOST_PIPE_GROUP * pipeGroup = &hDriver->pipeGroup[DRV_USBFSV1_HOST_HW_PIPE_CONTROL];
    DRV_USBFSV1_HOST_PIPE_OBJ * pipe = pipeGroup->currentPipe;
    bool tokenSent = false;
    bool endIRP = false;
    int byteCount = 0;
    usb_host_registers_t * HOST = &hDriver->usbID->HOST;
    usb_host_desc_bank_registers_t * controlPipeDesc = &hDriver->hostPipeDescTable[DRV_USBFSV1_HOST_HW_PIPE_CONTROL].HOST_DESC_BANK[0];
    usb_host_pipe_registers_t * controlPipe = &HOST->HOST_PIPE[DRV_USBFSV1_HOST_HW_PIPE_CONTROL]; 
    
    if(pIRP->tempState == DRV_USBFSV1_HOST_IRP_STATE_ABORTED)
    {
        /* Advance the IRP queue head before the call back. This will allow
         * any IRPs that are submitted in the callback to be added to the 
         * IRP queue correctly. */
        pipe->irpQueueHead = pIRP->next;

        /* We must update the pipe to move to the next pipe in the pipe bundle
         * While doing so, check if we have reached the last pipe in the bundle,
         * if so then wrap around to the first pipe in the bundle. */

        if(pipe->next != NULL)
        {
            /* This is not the last PIPE */
            pipeGroup->currentPipe = pipe->next;
        }
        else
        {
            /* This is the last PIPE. Move to the head pipe */
            pipeGroup->currentPipe = pipe;
        }
        
        /* Clear up all the interrupt on the pipe */
        controlPipe->USB_PINTFLAG = USB_HOST_PINTFLAG_Msk;

        pIRP->status = USB_HOST_IRP_STATUS_ABORTED;
        if(pIRP->callback != NULL)
        {
            pIRP->callback((USB_HOST_IRP *)pIRP);
        }
    }
    else
    {
     
        /* Process the temp state of the IRP */
        switch(pIRP->tempState)
        {
            case DRV_USBFSV1_HOST_IRP_STATE_SETUP_STAGE:

                /* This means we are at the first step in the control transfer. We
                 * need to send the Setup Packet. Update the IRP status to indicate
                 * that the IRP processing has started */ 

                pIRP->status = USB_HOST_IRP_STATUS_IN_PROGRESS;
                pIRP->completedBytes = 0;

                /* A control transfer pipe is unique in the sense that the pipe is
                 * bidirectional. Here we obtain the direction of the pipe based on
                 * the direction specified in the setup packet. This is stored in
                 * the pipe object itself. */

                if((((uint8_t *)(pIRP->setup))[0] & 0x80) != 0)
                {
                    /* Data stage direction is from device to host */
                    pipe->endpointAndDirection |= (USB_DATA_DIRECTION_DEVICE_TO_HOST << 7);
                }
                else
                {
                    /* Data stage direction is from host to device */
                    pipe->endpointAndDirection &= 0xF;
                    pipe->endpointAndDirection |= (USB_DATA_DIRECTION_HOST_TO_DEVICE << 7);
                }
                
                /* Keep track of the transaction */
                pIRP->tempState = DRV_USBFSV1_HOST_IRP_STATE_SETUP_TOKEN_SENT;
                
                /* Data packet of Setup stage will always have data toggle 0. 
                 * Set the token type to SETUP Token which is value 0. We are 
                 * sending the setup packet. So byte count is 8. No multi
                 * packet transfer. */
                controlPipe->USB_PSTATUSSET = USB_HOST_PSTATUSCLR_DTGL_Msk;
                controlPipe->USB_PCFG &= (~USB_HOST_PCFG_PTOKEN_Msk);
                controlPipeDesc->USB_CTRL_PIPE &= ~(USB_HOST_CTRL_PIPE_PDADDR_Msk);
                controlPipeDesc->USB_CTRL_PIPE |= (pipe->deviceAddress << USB_HOST_CTRL_PIPE_PDADDR_Pos);
                memcpy(hDriver->hostTransactionBuffer, pIRP->setup, 8);
                controlPipeDesc->USB_ADDR = (uint32_t)hDriver->hostTransactionBuffer;
                controlPipeDesc->USB_PCKSIZE = 0;
                controlPipeDesc->USB_PCKSIZE = (USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(0)|USB_HOST_PCKSIZE_BYTE_COUNT(8)
                        |USB_HOST_PCKSIZE_AUTO_ZLP(0)|USB_HOST_PCKSIZE_SIZE(pipe->pckSize));
                
                /* Clear the interrupts and then enable them. */
                controlPipe->USB_PINTFLAG = USB_HOST_PINTFLAG_Msk;
                controlPipe->USB_PINTENSET = USB_HOST_PINTENSET_PERR_Msk|
                    USB_HOST_PINTENSET_STALL_Msk|USB_HOST_PINTENSET_TRFAIL_Msk|USB_HOST_PINTENSET_TXSTP_Msk;
                                
                /* Let the controller know that Bank 0 is ready and then unfreeze 
                 * the pipe */
                controlPipe->USB_PSTATUSSET = USB_HOST_PSTATUSSET_BK0RDY_Msk;
                controlPipe->USB_PSTATUSCLR = USB_HOST_PSTATUSCLR_PFREEZE_Msk;
                tokenSent = true;
                               
                break;
                
            case DRV_USBFSV1_HOST_IRP_STATE_SETUP_TOKEN_SENT:
                
                /* Code will reach here when the interrupt has occurred after
                 * the setup token has been sent. Check why the interrupt has 
                 * occurred. */
                
                if((controlPipe->USB_PINTFLAG & USB_HOST_PINTFLAG_TXSTP_Msk) == USB_HOST_PINTFLAG_TXSTP_Msk)
                {
                    /* This means that setup packet was transferred. Clear the 
                     * interrupt flag. */
                    
                    controlPipe->USB_PINTFLAG 
                            = USB_HOST_PINTFLAG_TXSTP_Msk;
                    
                    /* Check if a data stage is required */
                    if((pIRP->data == NULL) || (pIRP->size == 0))
                    {
                        /* There is no data stage required. We can send the 
                         * status stage in the next frame. */
                        pIRP->tempState = DRV_USBFSV1_HOST_IRP_STATE_HANDSHAKE;
                        break;
                    }
                    else
                    {
                        /* Control transfer has a data stage. Note that there
                         * is no break statement. So the execution will fall
                         * through to the next state. */
                        pIRP->tempState = DRV_USBFSV1_HOST_IRP_STATE_DATA_STAGE;
                    }
                    
                    /* Irrespective of whether the next stage is a data stage
                     * or a status stage, the pipe data toggle should be 1. 
                     * We reset the pipe NAK counter in anticipation of 
                     * having to count NAKs in the data or handshake stage. */
                    pipe->dataToggle = 1;
                    pipe->nakCounter = 0;
                }
                else
                {
                    /* This means an error occurred while sending the setup packet.
                     * we must end the IRP as there should be no error while
                     * sending the setup packet. Clear up all the interrupt
                     * flags. */
                    
                    controlPipe->USB_PINTFLAG = USB_HOST_PINTFLAG_Msk;
                    pIRP->tempState = DRV_USBFSV1_HOST_IRP_STATE_COMPLETE;
                    pIRP->status = USB_HOST_IRP_STATUS_ERROR_UNKNOWN;
                    endIRP = true;
                    break;
                }
                
            case DRV_USBFSV1_HOST_IRP_STATE_DATA_STAGE:
              
                /* Update the IRP  before launching the token */
                pIRP->tempState = DRV_USBFSV1_HOST_IRP_STATE_DATA_STAGE_SENT;
                
                /* This function will the IRP and launch the token*/
                _DRV_USBFSV1_HOST_ControlTransferDataStageSend(hDriver);
                tokenSent = true;
                break;
                
            case DRV_USBFSV1_HOST_IRP_STATE_DATA_STAGE_SENT:
                
                /* A data stage has been sent. Check the result. The IRP must end
                 * if there was a STALL or a data error. It is possible that both
                 * the TRFAIL and TRCPT0 flag could be set. Hence this must be
                 * handled separately */
                
                if((controlPipe->USB_PINTFLAG & USB_HOST_PINTFLAG_PERR_Msk) == USB_HOST_PINTFLAG_PERR_Msk)
                {
                    /* This means that an error has occurred. We will have to 
                     * end the IRP */
                    
                    controlPipe->USB_PINTFLAG = USB_HOST_PINTFLAG_PERR_Msk;
                    pIRP->status = USB_HOST_IRP_STATUS_ERROR_DATA;
                    pIRP->tempState =  DRV_USBFSV1_HOST_IRP_STATE_COMPLETE;
                    endIRP = true;  
                    break;
                }
                else if((controlPipe->USB_PINTFLAG & USB_HOST_PINTFLAG_STALL_Msk) == USB_HOST_PINTFLAG_STALL_Msk)
                {
                    /* The data stage was stalled. We can end the IRP */
                    controlPipe->USB_PINTFLAG = USB_HOST_PINTFLAG_STALL_Msk;
                    pIRP->status = USB_HOST_IRP_STATUS_ERROR_STALL;
                    pIRP->tempState =  DRV_USBFSV1_HOST_IRP_STATE_COMPLETE;
                    endIRP = true;
                    break;
                }
                else
                {
                    if((controlPipe->USB_PINTFLAG & USB_HOST_PINTFLAG_TRCPT0_Msk) == USB_HOST_PINTFLAG_TRCPT0_Msk)
                    {
                        /* Data was sent successfully. Clear the flag and the TRFAIL
                         * flag as we dont have to process a NAK in case the data has
                         * been received. */
                        
                        controlPipe->USB_PINTFLAG = USB_HOST_PINTFLAG_TRCPT0_Msk|USB_HOST_PINTFLAG_TRFAIL_Msk;

                        /* Clear the pipe NAK counter */
                        pipe->nakCounter = 0;

                        /* Check the amount of data transferred and update the pIRP 
                         * fields.*/ 
                        byteCount = controlPipeDesc->USB_PCKSIZE & USB_HOST_PCKSIZE_BYTE_COUNT_Msk;

                        if((pipe->endpointAndDirection & 0x80) != 0)
                        {
                            /* While reading data from the device, the host uses the host control transfer
                             * buffer to receive the data. The data must then be transferred from this
                             * buffer to the client buffer. This is done in this way to protect the client
                             * buffer from alignment requirements on control transfers. It has been observed
                             * that the USB DMA will write a minimum of 4 bytes. This can prove dangerous at
                             * the client level. */

                            memcpy(( ( uint8_t * )pIRP->data + pIRP->completedBytes), hDriver->hostTransactionBuffer, byteCount);
                            pIRP->completedBytes += byteCount;
                            pIRP->completedBytesInThisFrame += byteCount;

                            /* Data is moving from device to host Check if the data
                             * stage is done */

                            if((byteCount < pipe->endpointSize) ||(pIRP->completedBytes >= pIRP->size))
                            {
                                /* A host control read transfer is done when the host
                                 * has received the amount of data that it was looking
                                 * for or when the host receives a less than
                                 * maxPacketSize data packet. Fall through to the 
                                 * handshake stage. */

                                pIRP->tempState = DRV_USBFSV1_HOST_IRP_STATE_HANDSHAKE;
                            }
                            else if((byteCount == pIRP->tempSize) || (byteCount == pipe->endpointSize))
                            {
                                /* This means the IRP has not completed. We should
                                 * check if more work is need on this IRP in this
                                 * frame. */

                                pIRP->status = USB_HOST_IRP_STATUS_IN_PROGRESS;
                                pipe->dataToggle ^= 0x1;

                                if(pIRP->tempSize > pIRP->completedBytesInThisFrame)
                                {
                                    /* More transactions are required in this frame */
                                    pIRP->tempState = DRV_USBFSV1_HOST_IRP_STATE_DATA_STAGE_SENT;
                                    _DRV_USBFSV1_HOST_ControlTransferDataStageSend(hDriver);
                                    tokenSent = true;
                                }
                                else
                                {
                                    /* Whatever planned for this frame has been done 
                                     * Do not Move the IRP Queue head here Do not end the
                                     * IRP */
                                    pIRP->tempState = DRV_USBFSV1_HOST_IRP_STATE_DATA_STAGE;
                                    endIRP = false;
                                }
                                break; 
                            }
                        }
                        else
                        {
                            /* Update the completedBytes and
                             * completedBytesInThisFrame field of the IRP with the
                             * actual number of bytes sent. */

                            pIRP->completedBytes += byteCount;
                            pIRP->completedBytesInThisFrame += byteCount;

                            /* Data is moving from host to device */
                            if(pIRP->completedBytes >= pIRP->size)
                            {
                                /* The write transfer is complete. Fall through to the
                                 * handshake stage */   
                                pipe->nakCounter = 0;
                                pIRP->tempState = DRV_USBFSV1_HOST_IRP_STATE_HANDSHAKE;
                            }
                            else if((byteCount == pIRP->tempSize) || (byteCount == pipe->endpointSize))
                            {
                                pIRP->status = USB_HOST_IRP_STATUS_IN_PROGRESS;
                                pipe->dataToggle ^= 0x1;

                                if(pIRP->tempSize > pIRP->completedBytesInThisFrame)
                                {
                                    /* More transactions are required in this frame */
                                    pIRP->tempState = DRV_USBFSV1_HOST_IRP_STATE_DATA_STAGE_SENT;
                                   _DRV_USBFSV1_HOST_ControlTransferDataStageSend(hDriver);
                                    tokenSent = true;
                                }
                                else
                                {
                                    /* Whatever planned for this frame has been done */
                                    /* Do not Move the IRP Queue head here */
                                    /* Do not end the IRP */
                                    pIRP->tempState = DRV_USBFSV1_HOST_IRP_STATE_DATA_STAGE;
                                    pIRP->status = USB_HOST_IRP_STATUS_IN_PROGRESS;
                                    pipe->nakCounter = 0;
                                    endIRP = false;
                                }
                                break;
                            }
                        }
                    }
                    else if ((controlPipe->USB_PINTFLAG & USB_HOST_PINTFLAG_TRFAIL_Msk) == USB_HOST_PINTFLAG_TRFAIL_Msk)
                    {
                        /* This means the device has NAKed the transaction. */
                        controlPipe->USB_PINTFLAG = USB_HOST_PINTFLAG_TRFAIL_Msk;
                        pIRP->tempState = DRV_USBFSV1_HOST_IRP_STATE_DATA_STAGE;
                        pipe->nakCounter ++;
                        if(pipe->nakCounter >= DRV_USBFSV1_HOST_NAK_LIMIT)
                        {
                            pIRP->tempState = DRV_USBFSV1_HOST_IRP_STATE_COMPLETE;
                            pIRP->status = USB_HOST_IRP_STATUS_ERROR_NAK_TIMEOUT;
                            endIRP = true;
                        }
                        else
                        {
                            /* Attempt the data stage again */
                            pIRP->tempState = DRV_USBFSV1_HOST_IRP_STATE_DATA_STAGE;
                        }
                        break;
                    }
                }
  
            case DRV_USBFSV1_HOST_IRP_STATE_HANDSHAKE:
                
                /* Send the handshake stage of this control transfer. The data
                 * toggle should DATA 1 */
                pipe->dataToggle = 1;
                pIRP->tempState = DRV_USBFSV1_HOST_IRP_STATE_HANDSHAKE_SENT;
                
                /* Set the packet size to 0. Note that we are not expecting
                 * to accept or send any data in this stage. */
                controlPipe->USB_PSTATUSSET = USB_HOST_PSTATUSSET_DTGL_Msk;
                controlPipeDesc->USB_ADDR = (uint32_t)(pIRP->data);
                controlPipeDesc->USB_CTRL_PIPE &= ~(USB_HOST_CTRL_PIPE_PDADDR_Msk);
                controlPipeDesc->USB_CTRL_PIPE |= (pipe->deviceAddress << USB_HOST_CTRL_PIPE_PDADDR_Pos);
                controlPipeDesc->USB_PCKSIZE = 0;
                controlPipeDesc->USB_PCKSIZE = (USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(0)|USB_HOST_PCKSIZE_BYTE_COUNT(0)
                                |USB_HOST_PCKSIZE_AUTO_ZLP(0)|USB_HOST_PCKSIZE_SIZE(pipe->pckSize));
                controlPipe->USB_PCFG &= ~(USB_HOST_PCFG_PTOKEN_Msk);
                
                /* Clear the interrupt and then enable them */
                controlPipe->USB_PINTFLAG = USB_HOST_PINTFLAG_Msk;
                controlPipe->USB_PINTENSET = USB_HOST_PINTENSET_PERR_Msk|
                    USB_HOST_PINTENSET_STALL_Msk|USB_HOST_PINTENSET_TRFAIL_Msk|USB_HOST_PINTENSET_TRCPT0_Msk;

                /* Check the direction and set the token type */
                if((pipe->endpointAndDirection & 0x80) == 0)
                {
                    /* If the data stage was from host to device, then the status
                     * stage should be an IN token. Bank 0 is ready to receive 
                     * data but we are not expecting any data */
                    controlPipe->USB_PSTATUSCLR = USB_HOST_PSTATUSCLR_BK0RDY_Msk;
                    controlPipe->USB_PCFG |= DRV_USBFSV1_HOST_PIPE_TOKEN_IN;
                }
                else
                {
                    /* If the data stage was from device to hsot, then the status
                     * stage should be an OUT token. Bank 0 is ready to send 
                     * data but we will not send any data.  */
                    controlPipe->USB_PSTATUSSET = USB_HOST_PSTATUSSET_BK0RDY_Msk;
                    controlPipe->USB_PCFG |= DRV_USBFSV1_HOST_PIPE_TOKEN_OUT;
                }

                /* Unfreeze the pipe. This launches the token */
                controlPipe->USB_PSTATUSCLR = USB_HOST_PSTATUSCLR_PFREEZE_Msk;
                tokenSent = true;
                break;
                
            case DRV_USBFSV1_HOST_IRP_STATE_HANDSHAKE_SENT:
                
                if((controlPipe->USB_PINTFLAG & USB_HOST_PINTFLAG_PERR_Msk) == USB_HOST_PINTFLAG_PERR_Msk)
                {
                    /* This means that an error has occurred. We will have to 
                     * end the IRP */
                    
                    controlPipe->USB_PINTFLAG = USB_HOST_PINTFLAG_PERR_Msk;
                    pIRP->status = USB_HOST_IRP_STATUS_ERROR_DATA;
                    pIRP->tempState =  DRV_USBFSV1_HOST_IRP_STATE_COMPLETE;
                    endIRP = true;
                    break;
                }
                else if((controlPipe->USB_PINTFLAG & USB_HOST_PINTFLAG_STALL_Msk) == USB_HOST_PINTFLAG_STALL_Msk)
                {
                    /* The data stage was stalled. We can end the IRP */
                    controlPipe->USB_PINTFLAG = USB_HOST_PINTFLAG_STALL_Msk;
                    pIRP->tempState = DRV_USBFSV1_HOST_IRP_STATE_COMPLETE;
                    pIRP->status = USB_HOST_IRP_STATUS_ERROR_STALL;
                    endIRP = true;
                    break;
                }
                else
                {
                    if((controlPipe->USB_PINTFLAG & USB_HOST_PINTFLAG_TRCPT0_Msk) == USB_HOST_PINTFLAG_TRCPT0_Msk)
                    {
                        /* Status stage was sent successfully. Clear the both the
                         * data received and the NAK flag. */
                        controlPipe->USB_PINTFLAG = USB_HOST_PINTFLAG_TRCPT0_Msk|USB_HOST_PINTFLAG_TRFAIL_Msk;
                        pIRP->tempState = DRV_USBFSV1_HOST_IRP_STATE_COMPLETE;
                        pIRP->status = USB_HOST_IRP_STATUS_COMPLETED;
                        if(((pipe->endpointAndDirection & 0x80) != 0) && (pIRP->size > pIRP->completedBytes))
                        {
                            /* While moving data from device to host, if we received
                             * less data from the device than expected, then indicate a
                             * short packet and set the irp size to to actual size */ 

                            pIRP->status = USB_HOST_IRP_STATUS_COMPLETED_SHORT;
                            pIRP->size = pIRP->completedBytes;
                        }
                        endIRP = true;
                    }
                    else if((controlPipe->USB_PINTFLAG & USB_HOST_PINTFLAG_TRFAIL_Msk) == USB_HOST_PINTFLAG_TRFAIL_Msk)
                    {
                        /* This means the device has NAKed the transaction. */
                        controlPipe->USB_PINTFLAG = USB_HOST_PINTFLAG_TRFAIL_Msk;
                        pIRP->tempState = DRV_USBFSV1_HOST_IRP_STATE_HANDSHAKE;
                        pipe->nakCounter ++;
                        if(pipe->nakCounter > DRV_USBFSV1_HOST_NAK_LIMIT)
                        {
                            pIRP->tempState = DRV_USBFSV1_HOST_IRP_STATE_COMPLETE;
                            pIRP->status = USB_HOST_IRP_STATUS_ERROR_NAK_TIMEOUT;
                            endIRP = true;
                        }
                        else
                        {
                            pIRP->tempState = DRV_USBFSV1_HOST_IRP_STATE_HANDSHAKE;
                        }
                    }
                }
                            
                break;
                
            case DRV_USBFSV1_HOST_IRP_STATE_COMPLETE:
                /* Remove the IRP from the from the SW EP object. */
                endIRP = true;
                break;
                
            default:
                break;
        }
        
        if(endIRP == true)
        {
            /* Reset the pipe NAK counter */
            pipe->nakCounter = 0;
            
            /* Move the IRP out of the queue */
            pipeGroup->currentPipe->irpQueueHead = pIRP->next;
            
            /* Move the current pipe to the next pipe */
            if(pipeGroup->currentPipe->next == NULL)
            {
                /* We have reached the end of the group. */
                pipeGroup->currentPipe = pipeGroup->pipe;
            }
            else
            {
                /* Move to the next pipe. */
                pipeGroup->currentPipe = pipeGroup->currentPipe->next;
            }
            
            /* IRP completed. Call the callback */
            if(pIRP->callback != NULL)
            {
                pIRP->callback((USB_HOST_IRP *)pIRP);
            }
        }
    }
    
    return(tokenSent);
}

// *****************************************************************************
/* Function:
    void _DRV_USBFSV1_HOST_NonControlTransferDataSend(DRV_USBFSV1_OBJ * hDriver)

  Summary:
    This function transfers data for a non control transfer.
	
  Description:
    This function will transfer data for current or the next transfer in the
    frame IRP list. The transfer to be process is pointed to by the
    currentFrameIRPIndex member of the driver object. For interrupt and bulk
    transfer, the data will be transferred to an internal buffer and will be
    copied to the user buffer only when the data is valid. This is done because
    the SAMD21 host controller will update atleast 4 bytes of memory. It is
    possible that the user buffer may be 1 byte.

    For isoc transfers, the application buffer is used. But in this case the
    buffer should be aligned on 4 byte boundary and its size should be a
    multiple of 4 bytes.

  Remarks:
    This is a local function and should not be called by the application.
*/

void _DRV_USBFSV1_HOST_NonControlTransferDataSend(DRV_USBFSV1_OBJ * hDriver)
{
    /* Get the pipe and IRP to be processed. The currentFrameIRPIndex will point
     * to the IRP that needs to be processed */
    DRV_USBFSV1_HOST_FRAME_IRP * frameIRP = &hDriver->frameIRPList[hDriver->currentFrameIRPIndex];
    USB_HOST_IRP_LOCAL * pIRP = frameIRP->pIRP;
    DRV_USBFSV1_HOST_PIPE_OBJ * pipe = (DRV_USBFSV1_HOST_PIPE_OBJ *)pIRP->pipe;
    int hardwarePipeIndex = frameIRP->hardwarePipeType;
    int size = 0;
    usb_host_registers_t * HOST = &hDriver->usbID->HOST;
    usb_host_desc_bank_registers_t * hardwarePipeDesc = &hDriver->hostPipeDescTable[hardwarePipeIndex].HOST_DESC_BANK[0];
    usb_host_pipe_registers_t * hardwarePipe = &HOST->HOST_PIPE[hardwarePipeIndex]; 

    if((pIRP->tempSize - pIRP->completedBytesInThisFrame) >= pipe->endpointSize)
    {
        /* If the pending bytes is more than endpoint size, then cap the size to
         * endpoint size */
        size = pipe->endpointSize;
    }
    else
    {
        /* Else we can request all the pending data */
        size = pIRP->tempSize - pIRP->completedBytesInThisFrame;
    } 

    /* Setup the pipe descriptor entry for this pipe */
    if(pipe->pipeType == USB_TRANSFER_TYPE_ISOCHRONOUS)
    {
        /* For isoc transfers the user application buffer is used */
        hardwarePipeDesc->USB_ADDR = (uint32_t)( ( uint8_t * )pIRP->data + pIRP->completedBytes);
    }
    else
    {
        /* For interrupt and bulk transfers, an internal buffer is used. */
        hardwarePipeDesc->USB_ADDR = (uint32_t)(hDriver->hostTransactionBuffer);
    }

    /* Clear the CTRL Pipe register */
    hardwarePipeDesc->USB_CTRL_PIPE = 0;
    hardwarePipeDesc->USB_CTRL_PIPE = ((pipe->deviceAddress << USB_HOST_CTRL_PIPE_PDADDR_Pos)
            |((pipe->endpointAndDirection & 0xF) << USB_HOST_CTRL_PIPE_PEPNUM_Pos));
    hardwarePipeDesc->USB_PCKSIZE = 0;
    hardwarePipeDesc->USB_PCKSIZE = (USB_HOST_PCKSIZE_MULTI_PACKET_SIZE(0)|USB_HOST_PCKSIZE_BYTE_COUNT(size)
         |USB_HOST_PCKSIZE_AUTO_ZLP(0)|USB_HOST_PCKSIZE_SIZE(pipe->pckSize));
    hardwarePipe->USB_PCFG &= ~(USB_HOST_PCFG_PTOKEN_Msk);

    /* Clear all the pipe interrupts */
    hardwarePipe->USB_PINTFLAG = USB_HOST_PINTFLAG_Msk;

    /* Enable all pipe interrupt except the setup interrupt. That is only for
     * control pipes */
    hardwarePipe->USB_PINTENSET = USB_HOST_PINTENSET_TRCPT0_Msk |
        USB_HOST_PINTENSET_TRFAIL_Msk | USB_HOST_PINTENSET_PERR_Msk | USB_HOST_PINTENSET_STALL_Msk;

    /* Update the data toggle */
    if(pipe->dataToggle == 1)
    {
        hardwarePipe->USB_PSTATUSSET = USB_HOST_PSTATUSSET_DTGL_Msk;
    }
    else
    {
        hardwarePipe->USB_PSTATUSCLR = USB_HOST_PSTATUSCLR_DTGL_Msk;
    }

    /* Check the direction and set the token type */
    if((pipe->endpointAndDirection & 0x80) != 0)
    {
        /* Bank 0 is ready to receive data */
        hardwarePipe->USB_PSTATUSCLR = USB_HOST_PSTATUSCLR_BK0RDY_Msk;
        hardwarePipe->USB_PCFG |= DRV_USBFSV1_HOST_PIPE_TOKEN_IN;
    }
    else
    {
        /* Bank 0 contains the data. If we are sending data to the device, then
         * copy this data from the user buffer to driver buffer (only for bulk
         * and interrupt transfers). */
        
        if(pipe->pipeType != USB_TRANSFER_TYPE_ISOCHRONOUS)
        {
            memcpy(hDriver->hostTransactionBuffer, ( ( uint8_t * )pIRP->data + pIRP->completedBytes), size);
        }

        hardwarePipe->USB_PSTATUSSET = USB_HOST_PSTATUSSET_BK0RDY_Msk;
        hardwarePipe->USB_PCFG |= DRV_USBFSV1_HOST_PIPE_TOKEN_OUT;
    }

    /* Unfreeze the pipe. This launches the token */
    hardwarePipe->USB_PSTATUSCLR = USB_HOST_PSTATUSCLR_PFREEZE_Msk;
}

// *****************************************************************************
/* Function:
    void _DRV_USBFSV1_HOST_NonControlTransferProcess
    (
        DRV_USBFSV1_OBJ * hDriver
        bool checkTransactionResult
    )

  Summary:
    Non Control Transfer Process.
	
  Description:
    This function processes non-zero endpoint transfers which
    could be any of bulk, interrupt and isochronous transfers

  Remarks:
*/

static bool _DRV_USBFSV1_HOST_NonControlTransferProcess
(
    DRV_USBFSV1_OBJ * hDriver,
    bool checkTransactionResult
)
{
   /* This function can be called from two locations. Either from the frame IRP
    * list creation function where the list has been created an new token needs
    * to be launched. In this we dont need to check the transaction result. If
    * the checkTransactionResult flag is true, then this function is being
    * called from the pipe interrupt handler to check the result of an ongoing
    * transfer and to proceed the transfer. */

    DRV_USBFSV1_HOST_FRAME_IRP * frameIRP = &hDriver->frameIRPList[hDriver->currentFrameIRPIndex];
    USB_HOST_IRP_LOCAL * pIRP = frameIRP->pIRP;
    DRV_USBFSV1_HOST_PIPE_OBJ * pipe = (DRV_USBFSV1_HOST_PIPE_OBJ *)pIRP->pipe;
    bool tokenSent = false;
    bool endIRP = false;
    int hardwarePipeIndex = frameIRP->hardwarePipeType;
    int byteCount = 0;
    usb_host_registers_t * HOST = &hDriver->usbID->HOST;
    usb_host_pipe_registers_t * hardwarePipe = &HOST->HOST_PIPE[hardwarePipeIndex]; 

    if(pIRP->tempState == DRV_USBFSV1_HOST_IRP_STATE_ABORTED)
    {
        /* This means that this IRP was aborted by the application while it was
         * in progress. Terminate it now. Remove the IRP from pipe. */ 
        pipe->irpQueueHead = pIRP->next;

        /* Clear up all the hardware interrupts on the pipe */
        hardwarePipe->USB_PINTFLAG = USB_HOST_PINTFLAG_Msk;
        
        /* Notify whoever has submitted the IRP that the IRP has been aborted.
         * */
        pIRP->status = USB_HOST_IRP_STATUS_ABORTED;
        if(pIRP->callback != NULL)
        {
            pIRP->callback((USB_HOST_IRP*)pIRP);
        }
    }
    else
    {
        if(!checkTransactionResult)
        {
           /* This means the first transaction has to be freshly launched.
            * Update the status of the IRP and then set the current IRP of the
            * pipe group to this one. */
            pIRP->status = USB_HOST_IRP_STATUS_IN_PROGRESS;
            hDriver->pipeGroup[hardwarePipeIndex].currentIRP = pIRP;
            tokenSent = true;
            _DRV_USBFSV1_HOST_NonControlTransferDataSend(hDriver);
        }
        else
        {
            /* This function is being called after a transaction was completed
             * What we do next depends on the type of the pipe */
            
            if(pipe->pipeType == USB_TRANSFER_TYPE_ISOCHRONOUS)
            {
            }
            else
            {
                /* The hardware pipe type will have the index of the hardware
                 * pipe which has to be processed. Check the response type and
                 * handle it */
                if((hardwarePipe->USB_PINTFLAG & USB_HOST_PINTFLAG_PERR_Msk) == USB_HOST_PINTFLAG_PERR_Msk)
                {
                    /* This means that an error has occurred. We will have to 
                     * end the IRP */

                    hardwarePipe->USB_PINTFLAG = USB_HOST_PINTFLAG_PERR_Msk;
                    pIRP->status = USB_HOST_IRP_STATUS_ERROR_DATA;
                    pIRP->tempState =  DRV_USBFSV1_HOST_IRP_STATE_COMPLETE;
                    endIRP = true; 
                }
                else if((hardwarePipe->USB_PINTFLAG & USB_HOST_PINTFLAG_STALL_Msk) == USB_HOST_PINTFLAG_STALL_Msk)
                {
                    /* The data stage was stalled. We can end the IRP */
                    hardwarePipe->USB_PINTFLAG = USB_HOST_PINTFLAG_STALL_Msk;
                    pIRP->status = USB_HOST_IRP_STATUS_ERROR_STALL;
                    endIRP = true;
                }
                else 
                {
                    if((hardwarePipe->USB_PINTFLAG & USB_HOST_PINTFLAG_TRCPT0_Msk) == USB_HOST_PINTFLAG_TRCPT0_Msk)
                    {
                        /* Data was transferred successfully. Clear the flag. */
                        hardwarePipe->USB_PINTFLAG = (USB_HOST_PINTFLAG_TRCPT0_Msk|USB_HOST_PINTFLAG_TRFAIL_Msk);
                        byteCount = hDriver->hostPipeDescTable[hardwarePipeIndex].HOST_DESC_BANK[0].USB_PCKSIZE & USB_HOST_PCKSIZE_BYTE_COUNT_Msk;

                        /* If the data was to be received from the device, then
                         * this data is currently in the driver transaction
                         * buffer. Copy this into the application buffer */
                        if((pipe->endpointAndDirection & 0x80) != 0)
                        {
                            /* Data has been received from the device */
                            memcpy(( ( uint8_t * )pIRP->data + pIRP->completedBytes), hDriver->hostTransactionBuffer, byteCount);
                        }

                        /* Now update the byte counters */
                        pIRP->completedBytes += byteCount;
                        pIRP->completedBytesInThisFrame += byteCount;
                        pipe->dataToggle ^= 0x1;
                        if((byteCount < pipe->endpointSize) || (pIRP->size <= pIRP->completedBytes))
                        {
                            /* We received data less than endpoint size.  So we
                             * end the transfer */
                            if(pIRP->size > pIRP->completedBytes)
                            {
                                pIRP->status = USB_HOST_IRP_STATUS_COMPLETED_SHORT;
                            }
                            else
                            {
                                pIRP->status = USB_HOST_IRP_STATUS_COMPLETED;
                            }

                            endIRP = true;
                        }
                        else if((byteCount == pIRP->tempSize) || (byteCount == pipe->endpointSize))
                        {
                            if(pIRP->tempSize > pIRP->completedBytesInThisFrame)
                            {
                                /* Some more transactions are required in this frame */
                                pIRP->status = USB_HOST_IRP_STATUS_IN_PROGRESS;
                                _DRV_USBFSV1_HOST_NonControlTransferDataSend(hDriver);
                                tokenSent = true;
                            }
                            else
                            {
                                /* Whatever planned for this frame has been done */
                                /* Do not Move the IRP Queue head here */

                                /* Do not end the IRP */
                                endIRP = false;
                                tokenSent = false;
                            }
                        }
                    }
                    else if ((hardwarePipe->USB_PINTFLAG & USB_HOST_PINTFLAG_TRFAIL_Msk) == USB_HOST_PINTFLAG_TRFAIL_Msk)
                    {
                        /* This means the device has NAKed the transaction. We do
                         * not do anything with this transfer any more. This will
                         * get deferred to the next SOF. */

                        hardwarePipe->USB_PINTFLAG = USB_HOST_PINTFLAG_TRFAIL_Msk;
                    }
                }
            }
            
            if(endIRP == true)
            {
                /* Move the pipe queue head to next IRP in the queue */
                pipe->irpQueueHead = (USB_HOST_IRP_LOCAL *)pIRP->next;

                /* Update the size field with actual size received\transmitted */
                pIRP->size = pIRP->completedBytes;

                if(pIRP->callback != NULL)
                {
                    pIRP->callback((USB_HOST_IRP *)pIRP);
                }
            }
        }
    }

    return(tokenSent);
}

// *****************************************************************************
/* Function:
    void _DRV_USBFSV1_HOST_ControlTransferBW(DRV_USBFSV1_OBJ * hDriver)
  
  Summary:
    This function calculates the bus bandwidth required for a control transfer.
	
  Description:
    This function calculates the bus bandwidth required for a control transfer.
    The global consumed bandwidth is decremented by the amount of bandwidth
    allocated for the control transfer.

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/

void _DRV_USBFSV1_HOST_ControlTransferBW(DRV_USBFSV1_OBJ * hDriver)
{
    /* If this function is being called, this means we have a valid
     * current pipe and IRP in the control pipe group. */

    int maxControlTransferBW = 0;
    int nTransactions = 0;
    int nPossibleTransactions = 0;
    DRV_USBFSV1_HOST_PIPE_OBJ * currentPipe = hDriver->pipeGroup[DRV_USBFSV1_HOST_HW_PIPE_CONTROL].currentPipe;
    USB_HOST_IRP_LOCAL * currentIRP = hDriver->pipeGroup[DRV_USBFSV1_HOST_HW_PIPE_CONTROL].currentIRP;

    /* Check the speed of this pipe and then figure out what is the maximum
     * bandwidth to be allocated for control transfers. The maximum bandwidth
     * allocated for control transfers is 20/30 percent. */

    maxControlTransferBW = DRV_USBFSV1_MAX_CONTROL_BANDWIDTH_FULL_SPEED;
    if(currentPipe->speed == USB_SPEED_LOW)
    {
        maxControlTransferBW = DRV_USBFSV1_MAX_CONTROL_BANDWIDTH_LOW_SPEED;
    }

    /* We know that at least one transaction should be possible within the alloted
     * bandwidth. We check if more are possible */

    nTransactions = (currentIRP->size - currentIRP->completedBytes)/currentPipe->endpointSize;

    if(nTransactions == 0)
    {
        nTransactions = 1;
    }
    else if((currentIRP->size - currentIRP->completedBytes) % (currentPipe->endpointSize) != 0)
    {
        /* The code will come here only when the HOST is required to send or
         * receive multiple transactions ending with SHORT PACKET */
        nTransactions++;
    }

    /* Figure out how many transactions are possible and then cap if required */
    nPossibleTransactions = maxControlTransferBW/currentPipe->bwPerTransaction;
    if (nPossibleTransactions < nTransactions)
    {
        nTransactions = nPossibleTransactions;
    }

    /* Data size in bytes that will be transferred for this IRP */
    currentIRP->tempSize = nTransactions * currentPipe->endpointSize;

    /* Based on the above calculation, the size of the data to be
     * transmitted\received will be always multiple of endpoint size. This
     * is correct when SHORT PACKET is not there.  But cases where the
     * transfer will end with SHORT PACKET, the calculated size will be more
     * than the actual IRP size remaining.  We should consider the actual
     * data size remaining only.  */

    if((currentIRP->size - currentIRP->completedBytes) < currentIRP->tempSize)
    {
        currentIRP->tempSize = currentIRP->size - currentIRP->completedBytes;
    }

    /* Reset the IRP completed bytes in this frame field */
    currentIRP->completedBytesInThisFrame = 0;

    /* Update the global bandwidth */
    hDriver->globalBWConsumed += (nTransactions * currentPipe->bwPerTransaction);
}

// *****************************************************************************
/* Function:
    USB_HOST_IRP_LOCAL * _DRV_USBFSV1_HOST_PipeGroupGetNextIRP
    (
        DRV_USBFSV1_HOST_PIPE_GROUP * pipeGroup
    )
  
  Summary:
    This function will update the current pipe in the pipe group.
	
  Description:
    This function will update the current pipe in the pipe group to the next
    pipe. If the end of the pipe group is reached, then current pipe will be
    reset to the first pipe in the pipe group. If the current pipe does not have
    an IRP then the next pipe will be scanned. The pointer to the IRP will be
    returned.

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/

USB_HOST_IRP_LOCAL * _DRV_USBFSV1_HOST_PipeGroupGetNextIRP(DRV_USBFSV1_HOST_PIPE_GROUP * pipeGroup)
{
    USB_HOST_IRP_LOCAL * returnValue = NULL;
    int iterator = 0;

    for (iterator = 0; iterator < pipeGroup->nPipes; iterator ++)
    {
        pipeGroup->currentPipe = pipeGroup->currentPipe->next;
        if (pipeGroup->currentPipe == NULL)
        {
            /* This means we have reach the end of the pipe group. 
             * Reset the current pipe to the first pipe. */
            pipeGroup->currentPipe = pipeGroup->pipe;
        }

        /* Check if this pipe has a IRP*/
        if (pipeGroup->currentPipe->irpQueueHead != NULL)
        {
            /* Found an IRP. Return it */
            returnValue = pipeGroup->currentPipe->irpQueueHead;
            break;
        }
    }

    return(returnValue);
}

// *****************************************************************************
/* Function:
    bool _DRV_USBFSV1_HOST_NonControlTransferBW
    (
        DRV_USBFSV1_OBJ * hDriver, USB_HOST_IRP_LOCAL * irp
    )
  
  Summary:
    This function calculates the bus bandwidth required for a non control
    transfer.
	
  Description:
    This function calculates the bus bandwidth required for a non control
    transfer. The global bus bandwidth will be updated based on bandwidth
    allocated for the transaction. The function will return false if there was
    insufficient bandwidth and the transaction could not be scheduled.

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/

bool _DRV_USBFSV1_HOST_NonControlTransferBW(DRV_USBFSV1_OBJ * hDriver, USB_HOST_IRP_LOCAL * irp)
{
    DRV_USBFSV1_HOST_PIPE_OBJ * pipe = (DRV_USBFSV1_HOST_PIPE_OBJ *)irp->pipe;
    bool returnValue = false;
    unsigned int bwPerTransaction = 0;
    unsigned int bwAvailable = 0;
    unsigned int nTransactions = 0;
    unsigned int nPossibleTransactions = 0;
    
    /* Check how much bandwidth is available */
    bwAvailable = (DRV_USBFSV1_MAX_BANDWIDTH_PER_FRAME - hDriver->globalBWConsumed);
    bwPerTransaction = pipe->bwPerTransaction;

    /* Compare the bandwidth available to the bandwidth per transaction */
    if(bwPerTransaction <= bwAvailable)
    {
        /* Transactions are possible. */
        nTransactions = (irp->size - irp->completedBytes)/pipe->endpointSize;

        if (nTransactions == 0)
        {
            /* If the number of pending bytes is less than endpoint size, then
             * we need atleast one transaction. */
            nTransactions = 1;
        }
        else if (((irp->size - irp->completedBytes) % (pipe->endpointSize)) != 0)
        {
            /* In case the pending bytes is not a multiple of endppoint size.
             * We will need one additional transaction */
            nTransactions ++;
        }

        /* Check how many possible transactions we can do */
        nPossibleTransactions = bwAvailable/bwPerTransaction;
        nTransactions = (nTransactions > nPossibleTransactions) ? nPossibleTransactions : nTransactions;

        /* Update the global consumed bandwidth and set the temporary IRP size
         * to what can be processed in this frame. */
        hDriver->globalBWConsumed += (nTransactions * bwPerTransaction);
        irp->tempSize = nTransactions * pipe->endpointSize;

        /* Adjust the temporary size in case this is the last transaction of the
         * transfer */
        if((irp->size - irp->completedBytes) < irp->tempSize)
        {
            irp->tempSize = irp->size - irp->completedBytes;
        }

        /* Reset the number of bytes completed in this frame */
        irp->completedBytesInThisFrame = 0;
        returnValue = true;
    }

    return(returnValue);
}

// *****************************************************************************
/* Function:
    void _DRV_USBFSV1_HOST_CreateFrameIRPList(DRV_USBFSV1_OBJ * hDriver)
  
  Summary:
    This function will create the frame IRP list. 
	
  Description:
    This function will create the frame IRP list. This is a list of all IRPs
    that will processed in the current frame. This function is called from the
    start of frame interrupt. The function will scan the pipe groups and will
    schedule IRP based on available bandwidth and IRP readiness.

    Control transfers will be prioritized first, followed by Isochronous,
    Interrupt and then Bulk transfers. The function will then launch the first
    transaction on the bus. 

  Remarks:
    This is a local function and should not be called directly by the
    application.
*/

void _DRV_USBFSV1_HOST_CreateFrameIRPList(DRV_USBFSV1_OBJ * hDriver)
{
    int iterator = 0;
    int frameIRPListIndex = 0;
    int nBulkOutPipesChecked = 0;
    int nBulkInPipesChecked = 0;
    int nInterruptOutPipesChecked = 0;
    int nInterruptInPipesChecked = 0;
    int nIsocOutPipesChecked = 0;
    int nIsocInPipesChecked = 0;
    bool allBulkInPipesChecked = false;
    bool allBulkOutPipesChecked = false;
    bool allInterruptInPipesChecked = false;
    bool allInterruptOutPipesChecked = false;
    bool allIsocOutPipesChecked = false;
    bool allIsocInPipesChecked = false;
    bool tokenSent = false;
    
    /* Start by checking the control transfer group */
    DRV_USBFSV1_HOST_PIPE_GROUP * controlPipeGroup = &hDriver->pipeGroup[DRV_USBFSV1_HOST_HW_PIPE_CONTROL]; 
    DRV_USBFSV1_HOST_PIPE_GROUP * bulkOutPipeGroup = &hDriver->pipeGroup[DRV_USBFSV1_HOST_HW_PIPE_BULK_OUT]; 
    DRV_USBFSV1_HOST_PIPE_GROUP * bulkInPipeGroup = &hDriver->pipeGroup[DRV_USBFSV1_HOST_HW_PIPE_BULK_IN]; 
    DRV_USBFSV1_HOST_PIPE_GROUP * interruptInPipeGroup = &hDriver->pipeGroup[DRV_USBFSV1_HOST_HW_PIPE_INT_IN]; 
    DRV_USBFSV1_HOST_PIPE_GROUP * interruptOutPipeGroup = &hDriver->pipeGroup[DRV_USBFSV1_HOST_HW_PIPE_INT_OUT]; 
    DRV_USBFSV1_HOST_PIPE_GROUP * isocInPipeGroup = &hDriver->pipeGroup[DRV_USBFSV1_HOST_HW_PIPE_ISOC_IN]; 
    DRV_USBFSV1_HOST_PIPE_GROUP * isocOutPipeGroup = &hDriver->pipeGroup[DRV_USBFSV1_HOST_HW_PIPE_ISOC_OUT]; 
    
    /* Clear the current frame IRP list and reset the current frame IRP list
     * index */
    for(iterator = 0; iterator < DRV_USBFSV1_HOST_IRP_PER_FRAME_NUMBER; iterator ++)
    {
        hDriver->frameIRPList[iterator].pIRP = NULL;
    }

    hDriver->currentFrameIRPIndex = 0;
        
    if(controlPipeGroup->pipe != NULL)
    {
        /* Check if the IRP on the current pipe has completed. If the current pipe 
         * does not have an IRP, we can go to the next pipe in the group. Only one
         * control transfer will be processed in a frame. */

        if (controlPipeGroup->currentPipe->irpQueueHead != NULL)
        {
            /* This means we found an IRP. The IRP could be a new IRP or 
             * or could be an IRP that is already being processed. */
            controlPipeGroup->currentIRP = controlPipeGroup->currentPipe->irpQueueHead;
        }
        else
        {
            /* The current pipe does not contain any transfers. Check if the rest
             * of the pipes in this group have any IRPs. The function update the
             * current pipe if an IRP is found. */
            
            controlPipeGroup->currentIRP = _DRV_USBFSV1_HOST_PipeGroupGetNextIRP(controlPipeGroup);
        }
        
        /* This means we found an IRP to work on. */
        if(controlPipeGroup->currentIRP != NULL)
        {
            /* Update the global consumed BW with the bandwidth required for this
             * control transaction. */
            _DRV_USBFSV1_HOST_ControlTransferBW(hDriver);
            hDriver->frameIRPList[0].pIRP = controlPipeGroup->currentIRP;
        }
        else
        {
            /* No Control transfer in this frame */
            hDriver->frameIRPList[0].pIRP = NULL;
        }
    }

    /* Given that we have allocate the first spot in the frame IRP list to the
     * control transfer, the rest of the transfer start from index 1 */
    frameIRPListIndex = 1;

    /* Check the isochronous pipes and service any IRPs */
    while((hDriver->globalBWConsumed < DRV_USBFSV1_MAX_BANDWIDTH_PER_FRAME) && (frameIRPListIndex < DRV_USBFSV1_HOST_IRP_PER_FRAME_NUMBER) 
            && ((!allIsocInPipesChecked) || (!allIsocOutPipesChecked)))
    {
        /* Check the isochronous out pipes */
        if(isocOutPipeGroup->nPipes != 0)
        {
            if(!allIsocOutPipesChecked)
            {
                /* We have a isoc pipe to check. This is a periodic pipe. So
                 * update the interval count */
                if(isocOutPipeGroup->currentPipe->intervalCounter != 0)
                {
                    isocOutPipeGroup->currentPipe->intervalCounter --;
                }

                /* If the interval is zero, then we should launch a transaction
                 * */
                if(isocOutPipeGroup->currentPipe->intervalCounter == 0)
                {
                    /* The pipe interval counter is zero. Check if we have an
                     * IRP on the pipe */
                    if(isocOutPipeGroup->currentPipe->irpQueueHead != NULL)
                    {
                        /* We do an IRP. Lets see if this can be processed */
                        isocOutPipeGroup->currentIRP = isocOutPipeGroup->currentPipe->irpQueueHead;
                        if(_DRV_USBFSV1_HOST_NonControlTransferBW(hDriver, isocOutPipeGroup->currentIRP) == true)
                        {
                            /* We have bandwidth for this IRP. Update the frame
                             * IRP list */
                            hDriver->frameIRPList[frameIRPListIndex].pIRP = isocOutPipeGroup->currentIRP;
                            hDriver->frameIRPList[frameIRPListIndex].hardwarePipeType = DRV_USBFSV1_HOST_HW_PIPE_ISOC_OUT;
                            frameIRPListIndex ++;
                        }
                        else
                        {
                            /* IRP could not be schedule because of bandwidth
                             * limitation */
                        }
                    }
                    else
                    {
                        /* Interval is not zero. Nothing to do on this pipe for now
                         * */
                    }

                    /* In either case, we have to reset the interval counter. If
                     * the IRP could not be processed in this interval, it will
                     * be picked up in the next interval. */ 
                    isocOutPipeGroup->currentPipe->intervalCounter = isocOutPipeGroup->currentPipe->bInterval;
                }

                /* Update the number of pipes checked and then switch to the
                 * next pipes. If all pipes have been checked, then set the flag
                 * and stop */

                nIsocOutPipesChecked ++;
                allIsocOutPipesChecked = (nIsocOutPipesChecked >= isocOutPipeGroup->nPipes) ? true : false;
                isocOutPipeGroup->currentPipe = (isocOutPipeGroup->currentPipe->next == NULL) ? isocOutPipeGroup->pipe : isocOutPipeGroup->currentPipe->next;
            }
            else
            {
                /* All pipes have been checked */
            }
        }
        else
        {
            /* No pipes to check which is as good as all pipes checked */
            allIsocOutPipesChecked = true;
        }

        /* Now check for ISOC IN pipes */
        if(isocInPipeGroup->nPipes != 0)
        {
            /* We have some ISOC IN pipes to check. Check if we have enough
             * banddwith and slots in the Frame IRP list */
            if(!allIsocInPipesChecked && (frameIRPListIndex < DRV_USBFSV1_HOST_IRP_PER_FRAME_NUMBER) && 
                   (hDriver->globalBWConsumed < DRV_USBFSV1_MAX_BANDWIDTH_PER_FRAME))
            {
                /* We have a isoc pipe to check. This is a periodic pipe. So
                 * update the interval count */
                if(isocInPipeGroup->currentPipe->intervalCounter != 0)
                {
                    isocInPipeGroup->currentPipe->intervalCounter --;
                }

                /* If the interval is zero, then we should launch a transaction
                 * */
                if(isocInPipeGroup->currentPipe->intervalCounter == 0)
                {
                    /* The pipe interval counter is zero. Check if we have an
                     * IRP on the pipe */
                    if(isocInPipeGroup->currentPipe->irpQueueHead != NULL)
                    {
                        /* We do an IRP. Lets see if this can be processed */
                        isocInPipeGroup->currentIRP = isocInPipeGroup->currentPipe->irpQueueHead;
                        if(_DRV_USBFSV1_HOST_NonControlTransferBW(hDriver, isocInPipeGroup->currentIRP) == true)
                        {
                            /* We have bandwidth for this IRP. Update the frame
                             * IRP list */
                            hDriver->frameIRPList[frameIRPListIndex].pIRP = isocInPipeGroup->currentIRP;
                            hDriver->frameIRPList[frameIRPListIndex].hardwarePipeType = DRV_USBFSV1_HOST_HW_PIPE_ISOC_IN;
                            frameIRPListIndex ++;
                        }
                        else
                        {
                            /* IRP could not be schedule because of bandwidth
                             * limitation */
                        }
                    }
                    else
                    {
                        /* Interval is not zero. Nothing to do on this pipe for now
                         * */
                    }

                    /* In either case, we have to reset the interval counter. If
                     * the IRP could not be processed in this interval, it will
                     * be picked up in the next interval. */ 
                    isocInPipeGroup->currentPipe->intervalCounter = isocInPipeGroup->currentPipe->bInterval;
                }

                /* Update the number of pipes checked and then switch to the
                 * next pipes. If all pipes have been checked, then set the flag
                 * and stop */

                nIsocInPipesChecked ++;
                allIsocInPipesChecked = (nIsocInPipesChecked >= isocInPipeGroup->nPipes) ? true : false;
                isocInPipeGroup->currentPipe = (isocInPipeGroup->currentPipe->next == NULL) ? isocInPipeGroup->pipe : isocInPipeGroup->currentPipe->next;
            }
            else
            {
                /* Either all pipes have been checked or frame bandwith is not
                 * available or frame IRP list is full */
            }
        }
        else
        {
            /* No pipes to check which is as good as all pipes checked */
            allIsocInPipesChecked = true;
        }
    }
        
    /* Check the interrupt pipes and service any IRPs */
    while((hDriver->globalBWConsumed < DRV_USBFSV1_MAX_BANDWIDTH_PER_FRAME) && (frameIRPListIndex < DRV_USBFSV1_HOST_IRP_PER_FRAME_NUMBER) 
            && ((!allInterruptInPipesChecked) || (!allInterruptOutPipesChecked)))
    {
        /* Check the interrupt IN pipes first */

        if(interruptInPipeGroup->nPipes != 0)
        {
            if(!allInterruptInPipesChecked)
            {
                /* We have more interrupt IN pipes to check. Stat with the
                 * current pipe. Check if the interval is zero, which means we
                 * have to process the IRP on this pipe. */

                if(interruptInPipeGroup->currentPipe->intervalCounter != 0)
                {
                    interruptInPipeGroup->currentPipe->intervalCounter --;
                }
                
                if(interruptInPipeGroup->currentPipe->intervalCounter == 0)
                {
                    /* The pipe interval counter is zero. Check if we have an
                     * IRP on the pipe */
                    if(interruptInPipeGroup->currentPipe->irpQueueHead != NULL)
                    {
                        /* We do an IRP. Lets see if this can be processed */
                        interruptInPipeGroup->currentIRP = interruptInPipeGroup->currentPipe->irpQueueHead;
                        if(_DRV_USBFSV1_HOST_NonControlTransferBW(hDriver, interruptInPipeGroup->currentIRP) == true)
                        {
                            /* We have bandwidth for this IRP. Update the frame
                             * IRP list */
                            hDriver->frameIRPList[frameIRPListIndex].pIRP = interruptInPipeGroup->currentIRP;
                            hDriver->frameIRPList[frameIRPListIndex].hardwarePipeType = DRV_USBFSV1_HOST_HW_PIPE_INT_IN;
                            frameIRPListIndex ++;
                        }
                        else
                        {
                            /* IRP could not be schedule because of bandwidth
                             * limitation */
                        }
                    }
                    else
                    {
                        /* There is no IRP in this pipe. Nothing to be done */
                    }

                    /* In either case, we have to reset the interval counter. If
                     * the IRP could not be processed in this interval, it will
                     * be picked up in the next interval. */ 
                    interruptInPipeGroup->currentPipe->intervalCounter = interruptInPipeGroup->currentPipe->bInterval;
                }
                else
                {
                    /* Interval is not 0 yet. We dont have to anything on
                     * this pipe */
                }

                /* Update the number of pipes checked and then switch to the
                 * next pipes. If all pipes have been checked, then set the flag
                 * and stop */
                
                nInterruptInPipesChecked ++;
                allInterruptInPipesChecked = (nInterruptInPipesChecked >= interruptInPipeGroup->nPipes) ? true : false;
                interruptInPipeGroup->currentPipe = (interruptInPipeGroup->currentPipe->next == NULL) ? interruptInPipeGroup->pipe : interruptInPipeGroup->currentPipe->next;
            }
            else
            {
                /* All interrupt in pipes have been checked */
            }
        }
        else
        {
            /* There are no interrupt IN pipes. To let the outer while loop know
             * about this, we set the allInterruptInPipesChecked flag */
            allInterruptInPipesChecked = true;
        }

        /* Now check the interrupt OUT pipes.  */

        if(interruptOutPipeGroup->nPipes != 0)
        {
            if(!allInterruptOutPipesChecked && (frameIRPListIndex < DRV_USBFSV1_HOST_IRP_PER_FRAME_NUMBER) && 
                   (hDriver->globalBWConsumed < DRV_USBFSV1_MAX_BANDWIDTH_PER_FRAME))
            {
                /* We have more interrupt OUT pipes to check. Stat with the
                 * current pipe. Check if the interval is zero, which means we
                 * have to process the IRP on this pipe. */

                if(interruptOutPipeGroup->currentPipe->intervalCounter != 0)
                {
                    interruptOutPipeGroup->currentPipe->intervalCounter --;
                }
                
                if(interruptOutPipeGroup->currentPipe->intervalCounter == 0)
                {
                    /* The pipe interval counter is zero. Check if we have an
                     * IRP on the pipe */
                    if(interruptOutPipeGroup->currentPipe->irpQueueHead != NULL)
                    {
                        /* We do an IRP. Lets see if this can be processed */
                        interruptOutPipeGroup->currentIRP = interruptOutPipeGroup->currentPipe->irpQueueHead;
                        if(_DRV_USBFSV1_HOST_NonControlTransferBW(hDriver, interruptOutPipeGroup->currentIRP) == true)
                        {
                            /* We have bandwidth for this IRP. Update the frame
                             * IRP list */
                            hDriver->frameIRPList[frameIRPListIndex].pIRP = interruptOutPipeGroup->currentIRP;
                            hDriver->frameIRPList[frameIRPListIndex].hardwarePipeType = DRV_USBFSV1_HOST_HW_PIPE_INT_OUT;
                            frameIRPListIndex ++;
                        }
                        else
                        {
                            /* IRP could not be schedule because of bandwidth
                             * limitation */
                        }
                    }
                    else
                    {
                        /* There is no IRP in this pipe. Nothing to be done */
                    }

                    /* In either case, we have to reset the interval counter. If
                     * the IRP could not be processed in this interval, it will
                     * be picked up in the next interval. */ 
                    interruptOutPipeGroup->currentPipe->intervalCounter = interruptOutPipeGroup->currentPipe->bInterval;
                }
                else
                {
                    /* Interval is not 0 yet. We dont have to anything on
                     * this pipe */
                }

                /* Update the number of pipes checked and then switch to the
                 * next pipes. If all pipes have been checked, then set the flag
                 * and stop */
                
                nInterruptOutPipesChecked ++;
                allInterruptOutPipesChecked = (nInterruptOutPipesChecked >= interruptOutPipeGroup->nPipes) ? true : false;
                interruptOutPipeGroup->currentPipe = (interruptOutPipeGroup->currentPipe->next == NULL) ? interruptOutPipeGroup->pipe : interruptOutPipeGroup->currentPipe->next;
            }
            else
            {
                /* All interrupt OUT pipes have been checked */
            }
        }
        else
        {
            /* There are no interrupt OUT pipes. To let the outer while loop know
             * about this, we set the allInterruptInPipesChecked flag */
            allInterruptOutPipesChecked = true;
        }
    }

    /* Now check the other pipe groups to see if there are transactions to be
     * scheduled. In each iteration we will check for bulk in IRP and then
     * one bulk out IRP. If all the pipes in the pipe groups have been
     * checked, then we stop. If all global bandwidth has been consumed, then
     * we stop. If the frame IRP list is full, then we stop. */

    while((hDriver->globalBWConsumed < DRV_USBFSV1_MAX_BANDWIDTH_PER_FRAME) && (frameIRPListIndex < DRV_USBFSV1_HOST_IRP_PER_FRAME_NUMBER) 
            && ((!allBulkInPipesChecked) || (!allBulkOutPipesChecked)))
    {
        if(bulkOutPipeGroup->nPipes != 0)
        {
            if(!allBulkOutPipesChecked)
            {
                /* We have not checked all the bulk out pipes. Continue checking from
                 * the last pipe */
                if(bulkOutPipeGroup->currentPipe->irpQueueHead != NULL)
                {
                    /* IRP can be added to Frame IRP list. Update the global
                     * consumed BW and then add the IRP to the list. Update the
                     * pipes checked count and set the flag is all pipes have been
                     * checked. We have to also update the current pipe to point to
                     * the next pipe in the pipe group. If the end of the group has
                     * been reached, then reset to the start of the group */
                    bulkOutPipeGroup->currentIRP = bulkOutPipeGroup->currentPipe->irpQueueHead;
                    
                    if ((_DRV_USBFSV1_HOST_NonControlTransferBW(hDriver, bulkOutPipeGroup->currentIRP)) == true)
                    {
                        /* Bandwidth for this transaction is available and global
                         * bandwidth has been updated. Update the frame IRP list
                         */
                        hDriver->frameIRPList[frameIRPListIndex].pIRP = bulkOutPipeGroup->currentIRP;
                        hDriver->frameIRPList[frameIRPListIndex].hardwarePipeType = DRV_USBFSV1_HOST_HW_PIPE_BULK_OUT;
                        frameIRPListIndex ++;
                    }
                    else
                    {
                        /* We could not add even one bulk transaction. There may be
                         * other pipes in this group whose  */
                    }
                }
                
                /* We have checked one pipe. Check the next one. If we have 
                 * checked all, the set the flag. */
                nBulkOutPipesChecked ++;
                allBulkOutPipesChecked = (nBulkOutPipesChecked >= bulkOutPipeGroup->nPipes) ? true : false;
                bulkOutPipeGroup->currentPipe = (bulkOutPipeGroup->currentPipe->next == NULL) ? bulkOutPipeGroup->pipe : bulkOutPipeGroup->currentPipe->next;
            }
        }
        else
        {
            /* There are no pipes in the groups. So there is nothing to check. */
            allBulkOutPipesChecked = true;
        }

        /* At this point we need to check if we still have any bandwidth left or
         * still have any slots in the frame IRP list or have checked all bulk
         * in pipes. */
        
        if(bulkInPipeGroup->nPipes != 0)
        {
            if((!allBulkInPipesChecked) && (frameIRPListIndex < DRV_USBFSV1_HOST_IRP_PER_FRAME_NUMBER) && 
                   (hDriver->globalBWConsumed < DRV_USBFSV1_MAX_BANDWIDTH_PER_FRAME))
            {
                /* We have not checked all the bulk IN pipes and have space in the
                 * frame IRP list and also have available bandwidth. Continue
                 * checking from the last pipe */
                if(bulkInPipeGroup->currentPipe->irpQueueHead != NULL)
                {
                    /* IRP can be added to Frame IRP list. Update the global
                     * consumed BW and then add the IRP to the list. Update the
                     * pipes checked count and set the flag is all pipes have been
                     * checked. We have to also update the current pipe to point to
                     * the next pipe in the pipe group. If the end of the group has
                     * been reached, then reset to the start of the group */
                    bulkInPipeGroup->currentIRP = bulkInPipeGroup->currentPipe->irpQueueHead;
                    if((_DRV_USBFSV1_HOST_NonControlTransferBW(hDriver, bulkInPipeGroup->currentIRP)) == true)
                    {
                        hDriver->frameIRPList[frameIRPListIndex].pIRP = bulkInPipeGroup->currentIRP;
                        hDriver->frameIRPList[frameIRPListIndex].hardwarePipeType = DRV_USBFSV1_HOST_HW_PIPE_BULK_IN;
                        frameIRPListIndex ++;
                    }
                    else
                    {
                        /* No transaction could be scheduled on this pipe. Skip
                         * to the next pipe */
                    }
                }
            }
            
            nBulkInPipesChecked ++;
            allBulkInPipesChecked = (nBulkInPipesChecked >= bulkInPipeGroup->nPipes) ? true : false;
            bulkInPipeGroup->currentPipe = (bulkInPipeGroup->currentPipe->next == NULL) ? bulkInPipeGroup->pipe : bulkInPipeGroup->currentPipe->next;
        }
        else
        {
            allBulkInPipesChecked = true;
        }
    }
    
    /* Check if there is control transfer and if so then launch it */
    if(hDriver->frameIRPList[0].pIRP != NULL)
    {
        /* Some stage has to be initiated. */
        tokenSent = _DRV_USBFSV1_HOST_ControlTransferProcess(hDriver);
    }

    if(!tokenSent)
    {
        /* We process the next transfer here if a token was not sent. We cycle
         * through the frame IRP list. If any IRP transaction was possible then
         * we send the token and then stop */

        for (iterator = 1; iterator < DRV_USBFSV1_HOST_IRP_PER_FRAME_NUMBER; iterator++ )
        {
            if(hDriver->frameIRPList[iterator].pIRP != NULL)
            {
                /* The following function will attempt to launch a token. If the
                 * token was launched, the current IRP of pipe group will be set
                 * to this IRP. We also update the current frame IRP index. This
                 * will be needed in the pipe interrupt handling to know which 
                 * IRP in the Frame IRP List was being serviced.  */
                
                hDriver->currentFrameIRPIndex = iterator;
                tokenSent = _DRV_USBFSV1_HOST_NonControlTransferProcess(hDriver, false);
                if(tokenSent)
                {
                    /* If a token was sent then stop */
                    break;
                }
            }
        }
    }
}

// *****************************************************************************
/* Function:
    void _DRV_USBFSV1_HOST_Tasks_ISR(DRV_USBFSV1_OBJ * pUSBDrvObj)

  Summary:
    Dynamic implementation of _DRV_USBFSV1_HOST_Tasks_ISR function.

  Description:
    This is the dynamic implementation of _DRV_USBFSV1_HOST_Tasks_ISR internal
    function. Function is an interrupt handler which does necessary processing
    based on the interrupt.

  Remarks:
    This is local function and should not be called directly by the client.

*/

void _DRV_USBFSV1_HOST_Tasks_ISR(DRV_USBFSV1_OBJ * hDriver)
{
    int iterator;
    bool tokenSent = false;

    /* Create a local pointer to the HOST Register set */ 
    usb_host_registers_t * HOST = &hDriver->usbID->HOST;
    usb_host_pipe_registers_t * controlPipe = &HOST->HOST_PIPE[DRV_USBFSV1_HOST_HW_PIPE_CONTROL]; 
    usb_host_pipe_registers_t * isocInPipe = &HOST->HOST_PIPE[DRV_USBFSV1_HOST_HW_PIPE_ISOC_IN]; 
    usb_host_pipe_registers_t * isocOutPipe = &HOST->HOST_PIPE[DRV_USBFSV1_HOST_HW_PIPE_ISOC_OUT]; 
    usb_host_pipe_registers_t * interruptInPipe = &HOST->HOST_PIPE[DRV_USBFSV1_HOST_HW_PIPE_INT_IN]; 
    usb_host_pipe_registers_t * interruptOutPipe = &HOST->HOST_PIPE[DRV_USBFSV1_HOST_HW_PIPE_INT_OUT]; 
    usb_host_pipe_registers_t * bulkInPipe = &HOST->HOST_PIPE[DRV_USBFSV1_HOST_HW_PIPE_BULK_IN]; 
    usb_host_pipe_registers_t * bulkOutPipe = &HOST->HOST_PIPE[DRV_USBFSV1_HOST_HW_PIPE_BULK_OUT]; 

    /* Handle the connect interrupt. */
    if((USB_HOST_INTFLAG_DCONN_Msk == (HOST->USB_INTFLAG & USB_HOST_INTFLAG_DCONN_Msk)) &&
            (USB_HOST_INTENSET_DCONN_Msk == (HOST->USB_INTENSET & USB_HOST_INTENSET_DCONN_Msk)))
    {
        /* A device attach was detected. We disable the attach interrupt and
         * continue the rest of the processing in attach detach state machine.
         * */
        hDriver->deviceAttached = true;
        HOST->USB_INTFLAG = USB_HOST_INTFLAG_DCONN_Msk;
        HOST->USB_INTENCLR = USB_HOST_INTENCLR_DCONN_Msk;
    }

    /* Handle the disconnect interrupt. */
    if((USB_HOST_INTFLAG_DDISC_Msk == (HOST->USB_INTFLAG & USB_HOST_INTFLAG_DDISC_Msk)) &&
            (USB_HOST_INTENSET_DDISC_Msk == (HOST->USB_INTENSET & USB_HOST_INTENSET_DDISC_Msk)))
    {
        /* The device was detached. Disable and clear the SOF and Reset 
         * interrupt. Disable all hardware pipes. Clear all pipe interrupts 
         * and disable the interrupts. Clear the frame IRP list */
        
        hDriver->deviceAttached = false;
        HOST->USB_INTFLAG = USB_HOST_INTFLAG_DDISC_Msk|USB_HOST_INTFLAG_DCONN_Msk;
        HOST->USB_INTENCLR = USB_HOST_INTENCLR_DDISC_Msk;

        for (iterator = 0; iterator < 7; iterator ++)
        {
            /* Freeze the pipe */
            HOST->HOST_PIPE[iterator].USB_PSTATUSSET = USB_HOST_PSTATUSSET_PFREEZE_Msk;
            while((HOST->HOST_PIPE[iterator].USB_PSTATUS & USB_HOST_PSTATUS_PFREEZE_Msk) == 0);
            
            /* Disable the pipe. Clear the interrupts and disable them.
             *  */
            HOST->HOST_PIPE[iterator].USB_PCFG &= (~USB_HOST_PCFG_PTYPE_Msk);
            HOST->HOST_PIPE[iterator].USB_PINTFLAG = USB_HOST_PINTFLAG_Msk;
            HOST->HOST_PIPE[iterator].USB_PINTENCLR = USB_HOST_PINTENCLR_Msk;
            
        }

        /* Clear all the interrupts and disable them */
        HOST->USB_INTENCLR = USB_HOST_INTENCLR_HSOF_Msk|USB_HOST_INTENCLR_RST_Msk;
        HOST->USB_INTFLAG = USB_HOST_INTFLAG_HSOF_Msk|USB_HOST_INTFLAG_RST_Msk;

        /* If the device was enumerated, then denumerate it. */
        if(hDriver->attachedDeviceObjHandle != USB_HOST_DEVICE_OBJ_HANDLE_INVALID)
        {
            /* The driver will need to know if the device is being de-enumerated 
             * This will be required at the time of pipe closing to make sure
             * the IRP on pipe being closed are not left hanging on a pipe 
             * interrupt that will never occur. */
            hDriver->isDeviceDeenumerating = true;

            /* Ask the host layer to de-enumerate this device. The de-enumeration
             * must be done in the interrupt context. */
            USB_HOST_DeviceDenumerate (hDriver->attachedDeviceObjHandle);

            /* Device de-enumeration is complete. */
            hDriver->isDeviceDeenumerating = false;
        }

        hDriver->attachedDeviceObjHandle = USB_HOST_DEVICE_OBJ_HANDLE_INVALID;        
        
        /* Clean up is complete. Get ready for next attach */
        HOST->USB_INTFLAG  = USB_HOST_INTFLAG_DCONN_Msk;
        HOST->USB_INTENSET = USB_HOST_INTENSET_DCONN_Msk;
    }

    /* Handle the reset done interrupt */
    if ((USB_HOST_INTFLAG_RST_Msk == (HOST->USB_INTFLAG & USB_HOST_INTFLAG_RST_Msk)) &&
            (USB_HOST_INTENSET_RST_Msk == (HOST->USB_INTENSET & USB_HOST_INTENSET_RST_Msk)))
    {
        iterator = 0;

        /* Reset signaling complete */
        hDriver->isResetting = false;

        /* Clear the reset flag and disable the interrupt */
        HOST->USB_INTFLAG = USB_HOST_INTFLAG_RST_Msk;
        HOST->USB_INTENCLR = USB_HOST_INTENCLR_RST_Msk;

        /* We can now read the device speed */
        if ((HOST->USB_STATUS & USB_HOST_STATUS_SPEED_Msk) == 0x0)
        {
            hDriver->deviceSpeed = USB_SPEED_FULL;
        }
        else if ((HOST->USB_STATUS & USB_HOST_STATUS_SPEED_Msk) == 0x4)
        {
            hDriver->deviceSpeed = USB_SPEED_LOW;
        }
        else
        {
            hDriver->deviceSpeed = USB_SPEED_ERROR;
        }

        /* Clear up the pipe descriptor table */
        memset(hDriver->hostPipeDescTable, 0, (sizeof(usb_descriptor_host_registers_t) * 7));
        
        /* The pipe configuration gets reset after a Reset signal.
         * Reconfigure the hardware pipes. Start with the control pipe. 
         * The transaction interrupts are enabled when the transaction is
         * scheduled */

        controlPipe->USB_PCFG = (DRV_USBFSV1_HOST_PIPE_TYPE_CONTROL|DRV_USBFSV1_HOST_PIPE_BANK_SINGLE|DRV_USBFSV1_HOST_PIPE_TOKEN_SETUP);
        controlPipe->USB_BINTERVAL = 0; 
        controlPipe->USB_PINTENCLR = USB_HOST_PINTENCLR_Msk;

        /* Pipe 1 is configured for ISOC IN */
        isocInPipe->USB_PCFG = (DRV_USBFSV1_HOST_PIPE_TYPE_ISOC|DRV_USBFSV1_HOST_PIPE_BANK_SINGLE|DRV_USBFSV1_HOST_PIPE_TOKEN_IN);
        isocInPipe->USB_BINTERVAL = 0;
        isocInPipe->USB_PINTENCLR = USB_HOST_PINTENCLR_Msk;

        /* Pipe 2 is configured for ISOC OUT */
        isocOutPipe->USB_PCFG = (DRV_USBFSV1_HOST_PIPE_TYPE_ISOC|DRV_USBFSV1_HOST_PIPE_BANK_SINGLE|DRV_USBFSV1_HOST_PIPE_TOKEN_OUT);
        isocOutPipe->USB_BINTERVAL = 0;
        isocOutPipe->USB_PINTENCLR = USB_HOST_PINTENCLR_Msk;

        /* Pipe 3 is configured for Interrupt IN but we set this to bulk type in
         * the hardware so that we can control the polling interval in software. */
        interruptInPipe->USB_PCFG = (DRV_USBFSV1_HOST_PIPE_TYPE_BULK|DRV_USBFSV1_HOST_PIPE_BANK_SINGLE|DRV_USBFSV1_HOST_PIPE_TOKEN_IN);
        interruptInPipe->USB_BINTERVAL = 0;
        interruptInPipe->USB_PINTENCLR = USB_HOST_PINTENCLR_Msk;

        /* Pipe 4 is configured for Interrupt OUT but we set this to bulk type
         * in the hardware so that we can control the polling interval in
         * software. */
        interruptOutPipe->USB_PCFG = (DRV_USBFSV1_HOST_PIPE_TYPE_BULK|DRV_USBFSV1_HOST_PIPE_BANK_SINGLE|DRV_USBFSV1_HOST_PIPE_TOKEN_OUT);
        interruptOutPipe->USB_BINTERVAL = 0;
        interruptOutPipe->USB_PINTENCLR = USB_HOST_PINTENCLR_Msk;

        /* Pipe 5 is configured for Bulk IN. Disable all pipe interrupts. These
         * will be enabled only when a transaction has been scheduled on the
         * pipe */
        bulkInPipe->USB_PCFG = (DRV_USBFSV1_HOST_PIPE_TYPE_BULK|DRV_USBFSV1_HOST_PIPE_BANK_SINGLE|DRV_USBFSV1_HOST_PIPE_TOKEN_IN);
        bulkInPipe->USB_BINTERVAL = 0;
        bulkInPipe->USB_PINTENCLR = USB_HOST_PINTENCLR_Msk;

        /* Pipe 6 is configured for Bulk OUT. Disable all pipe interrupts. These
         * will be enabled only when a transaction has been scheduled on the
         * pipe. */
        bulkOutPipe->USB_PCFG = (DRV_USBFSV1_HOST_PIPE_TYPE_BULK|DRV_USBFSV1_HOST_PIPE_BANK_SINGLE|DRV_USBFSV1_HOST_PIPE_TOKEN_OUT);
        bulkOutPipe->USB_BINTERVAL = 0;
        bulkOutPipe->USB_PINTENCLR = USB_HOST_PINTENCLR_Msk;

        /* Reset the host pipe group */
        for (iterator = 0; iterator < 7; iterator ++)
        {
            hDriver->pipeGroup[iterator].currentPipe = NULL;
            hDriver->pipeGroup[iterator].nPipes = 0;
            hDriver->pipeGroup[iterator].pipe = NULL;
            hDriver->pipeGroup[iterator].currentIRP = NULL;
        }

        /* Now that the reset is complete, we are ready to receive the SOF 
         * interrupt. */
        HOST->USB_INTENSET = USB_HOST_INTENSET_HSOF_Msk;
    }

    /* Handle the SOF Interrupt */
    if((USB_HOST_INTFLAG_HSOF_Msk == (HOST->USB_INTFLAG & USB_HOST_INTFLAG_HSOF_Msk)) &&
            (USB_HOST_INTENSET_HSOF_Msk ==(HOST->USB_INTENSET & USB_HOST_INTENSET_HSOF_Msk)))
    {
        /* This interrupt occurs every 1 msec. Clear the interrupt flag */
        HOST->USB_INTFLAG = USB_HOST_INTFLAG_HSOF_Msk;

        /* Reset the global consumed BW to 0 because we are at the start of
         * a new frame. */
        hDriver->globalBWConsumed = 0;

        /* The following function will create the list of IRPs to be processed
         * in this frame and will launch the first token */

        _DRV_USBFSV1_HOST_CreateFrameIRPList(hDriver);
    }

    /* Handle Pipe Events */
    if(HOST->USB_PINTSMRY != 0)
    {
        if((HOST->USB_PINTSMRY & (0x1 << DRV_USBFSV1_HOST_HW_PIPE_CONTROL)) != 0)
        {
            /* Freeze the pipe first so that we dont have any more transactions
             * on the bus. Wait till the pipe is frozen. Disable all pipe
             * interrupts. */
           
            controlPipe->USB_PSTATUSSET = USB_HOST_PSTATUSSET_PFREEZE_Msk;
            while((controlPipe->USB_PSTATUS & USB_HOST_PSTATUS_PFREEZE_Msk) != USB_HOST_PSTATUS_PFREEZE_Msk);
            controlPipe->USB_PINTENCLR = USB_HOST_PINTENCLR_Msk;
            
            /* This means a HW pipe 0 event had occurred. This is control 
             * transfer pipe. Handle control transfer events. */
            tokenSent = _DRV_USBFSV1_HOST_ControlTransferProcess(hDriver);
        }
        
        if((HOST->USB_PINTSMRY & (0x1 << DRV_USBFSV1_HOST_HW_PIPE_ISOC_IN)) != 0)
        {
            /* This means we have some activity on the ISOC IN hardware pipe.
             * Stop all interaction on the pipe. Disable all interrupts. While
             * setting the PFREEZE bit, we should wait till it gets set before
             * we proceed with processing the flags. This will ensure that we
             * capture the status of the last transaction on the bus. */
            isocInPipe->USB_PINTENCLR = USB_HOST_PINTENCLR_Msk;
            isocInPipe->USB_PSTATUSSET = USB_HOST_PSTATUSSET_PFREEZE_Msk;
            while((isocInPipe->USB_PSTATUS & USB_HOST_PSTATUS_PFREEZE_Msk) != USB_HOST_PSTATUS_PFREEZE_Msk);

            /* Process the response of this transaction */ 
            tokenSent = _DRV_USBFSV1_HOST_NonControlTransferProcess(hDriver, true);
        }

        if((HOST->USB_PINTSMRY & (0x1 << DRV_USBFSV1_HOST_HW_PIPE_ISOC_OUT)) != 0)
        {
            /* This means we have some activity on the ISOC OUT hardware pipe.
             * Stop all interaction on the pipe. Disable all interrupts. While
             * setting the PFREEZE bit, we should wait till it gets set before
             * we proceed with processing the flags. This will ensure that we
             * capture the status of the last transaction on the bus. */
            isocOutPipe->USB_PINTENCLR = USB_HOST_PINTENCLR_Msk;
            isocOutPipe->USB_PSTATUSSET = USB_HOST_PSTATUSSET_PFREEZE_Msk;
            while((isocOutPipe->USB_PSTATUS & USB_HOST_PSTATUS_PFREEZE_Msk) != USB_HOST_PSTATUS_PFREEZE_Msk);

            /* Process the response of this transaction */ 
            tokenSent = _DRV_USBFSV1_HOST_NonControlTransferProcess(hDriver, true);
        }

        if((HOST->USB_PINTSMRY & (0x1 << DRV_USBFSV1_HOST_HW_PIPE_INT_IN)) != 0)
        {
            /* This means we have some activity on the Interrupt IN hardware pipe.
             * Stop all interaction on the pipe. Disable all interrupts. While
             * setting the PFREEZE bit, we should wait till it gets set before
             * we proceed with processing the flags. This will ensure that we
             * capture the status of the last transaction on the bus. */
            interruptInPipe->USB_PINTENCLR = USB_HOST_PINTENCLR_Msk;
            interruptInPipe->USB_PSTATUSSET = USB_HOST_PSTATUSSET_PFREEZE_Msk;
            while((interruptInPipe->USB_PSTATUS & USB_HOST_PSTATUS_PFREEZE_Msk) != USB_HOST_PSTATUS_PFREEZE_Msk);

            /* Process the response of this transaction */ 
            tokenSent = _DRV_USBFSV1_HOST_NonControlTransferProcess(hDriver, true);
        }
        
        if((HOST->USB_PINTSMRY & (0x1 << DRV_USBFSV1_HOST_HW_PIPE_INT_OUT)) != 0)
        {
            /* This means we have some activity on the Interrupt OUT hardware pipe.
             * Stop all interaction on the pipe. Disable all interrupts. While
             * setting the PFREEZE bit, we should wait till it gets set before
             * we proceed with processing the flags. This will ensure that we
             * capture the status of the last transaction on the bus. */
            interruptOutPipe->USB_PINTENCLR = USB_HOST_PINTENCLR_Msk;
            interruptOutPipe->USB_PSTATUSSET = USB_HOST_PSTATUSSET_PFREEZE_Msk;
            while((interruptOutPipe->USB_PSTATUS & USB_HOST_PSTATUS_PFREEZE_Msk) != USB_HOST_PSTATUS_PFREEZE_Msk);

            /* Process the response of this transaction */ 
            tokenSent = _DRV_USBFSV1_HOST_NonControlTransferProcess(hDriver, true);
        }

        if((HOST->USB_PINTSMRY & (0x1 << DRV_USBFSV1_HOST_HW_PIPE_BULK_OUT)) != 0)
        {
            /* This means we have some activity on the bulk out hardware pipe.
             * Stop all interaction on the pipe. Disable all interrupts. While
             * setting the PFREEZE bit, we should wait till it gets set before
             * we proceed with processing the flags. This will ensure that we
             * capture the status of the last transaction on the bus. */
            bulkOutPipe->USB_PINTENCLR = USB_HOST_PINTENCLR_Msk;
            bulkOutPipe->USB_PSTATUSSET = USB_HOST_PSTATUSSET_PFREEZE_Msk;
            while((bulkOutPipe->USB_PSTATUS & USB_HOST_PSTATUS_PFREEZE_Msk) != USB_HOST_PSTATUS_PFREEZE_Msk);

            /* Process the response of this transaction */ 
            tokenSent = _DRV_USBFSV1_HOST_NonControlTransferProcess(hDriver, true);
        }

        if((HOST->USB_PINTSMRY & (0x1 << DRV_USBFSV1_HOST_HW_PIPE_BULK_IN)) != 0)
        {
            /* This means we have some activity on the bulk out hardware pipe.
             * Stop all interaction on the pipe. Disable all interrupt on the
             * pipe */
            bulkInPipe->USB_PINTENCLR = USB_HOST_PINTENCLR_Msk;
            bulkInPipe->USB_PSTATUSSET = USB_HOST_PSTATUSSET_PFREEZE_Msk;
            while((bulkInPipe->USB_PSTATUS & USB_HOST_PSTATUS_PFREEZE_Msk) != USB_HOST_PSTATUS_PFREEZE_Msk);
            tokenSent = _DRV_USBFSV1_HOST_NonControlTransferProcess(hDriver, true);
        }

        if(!tokenSent)
        {
            /* This means no token was sent after the pipe interrupts was
             * processed. We can process the next transfer in the frame IRP list
             * */

            do
            {
                hDriver->currentFrameIRPIndex ++;
                if(hDriver->currentFrameIRPIndex < DRV_USBFSV1_HOST_IRP_PER_FRAME_NUMBER)
                {
                    if(hDriver->frameIRPList[hDriver->currentFrameIRPIndex].pIRP != NULL)
                    {
                        tokenSent = _DRV_USBFSV1_HOST_NonControlTransferProcess(hDriver, false);
                        if (tokenSent)
                        {
                            /* If a token was sent, then we stop here */
                            break;
                        }
                    }
                }
            } while(hDriver->currentFrameIRPIndex < DRV_USBFSV1_HOST_IRP_PER_FRAME_NUMBER);
        }
    }
}

// *****************************************************************************
/* Function:
    void DRV_USBFSV1_HOST_StartOfFrameControl(DRV_HANDLE client, bool control)

  Summary:
    This function control the Start of Frame signalling on the bus.

  Description:
    This function control the Start of Frame signalling on the bus. On this
    controller, the hardware automatically enables the SOF at the end of reset
    and after resume signalling has been received or completed. Hence the only
    option that is provided to the root hub driver is to disable the SOF.

  Remarks:
    Refer to drv_usbfsv1.h for usage information.
*/

void DRV_USBFSV1_HOST_StartOfFrameControl(DRV_HANDLE client, bool control)
{
    /* At the point this function does not do any thing.
     * The Start of frame signaling in this HCD is controlled
     * automatically by the module. */

    DRV_USBFSV1_OBJ * hDriver = (DRV_USBFSV1_OBJ *)client;
    usb_host_registers_t * HOST;

    if((client != DRV_HANDLE_INVALID) && (hDriver != NULL) && (hDriver->inUse == true))
    {
        HOST = &hDriver->usbID->HOST;
        if(control == false)
        {
            /* Disable the SOF */
            HOST->USB_CTRLB &= ~(USB_HOST_CTRLB_SOFE_Msk);
        }       
        else
        {
            /* Nothing to do here. SOF is automatically enabled by hardware */
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Invalid client");
    }
}

// *****************************************************************************
/* Function:
    USB_SPEED DRV_USBFSV1_HOST_DeviceCurrentSpeedGet(DRV_HANDLE client)

  Summary:
    This function returns the current operating speed of the device.

  Description:
    This function returns the current operating speed of the device.

  Remarks:
    Refer to drv_usbfsv1.h for usage information.
*/

USB_SPEED DRV_USBFSV1_HOST_DeviceCurrentSpeedGet(DRV_HANDLE client)
{
    /* This function returns the current device speed */
    DRV_USBFSV1_OBJ * hDriver = (DRV_USBFSV1_OBJ *)client;
    USB_SPEED returnValue = USB_SPEED_ERROR;

    if((client != DRV_HANDLE_INVALID) && (hDriver != NULL) && (hDriver->inUse == true))
    {
        returnValue = hDriver->deviceSpeed;
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Invalid client");
    }

    return(returnValue);
}

// ****************************************************************************
/* Function:
    bool DRV_USBFSV1_HOST_EventDisable
    (
        DRV_HANDLE handle
    );
    
  Summary:
    Disables host mode events.
    
  Description:
    This function disables the host mode events. This function is called by the
    Host Layer when it wants to execute code atomically. 
    
  Remarks:
    Refer to drv_usbfs.h for usage information.
*/

bool DRV_USBFSV1_HOST_EventsDisable
(
    DRV_HANDLE handle
)
{
    DRV_USBFSV1_OBJ * hDriver = (DRV_USBFSV1_OBJ *)handle;
    bool interruptState = false;

    if((DRV_HANDLE_INVALID != handle) && (0 != handle) && (hDriver->inUse == true))
    {
        /* The ATSAMD21 controller has 1 USB interrupt while the SAME54 has 4
         * interrupts. The function signature allows us to only return the
         * context of one interrupt. So we will return the context of only
         * interrupt. This is okay because we will always enable  and disable
         * all interrupts together. */

        interruptState = SYS_INT_SourceDisable(hDriver->interruptSource); 
#if (DRV_USBFSV1_MULTIPLE_ISR_AVAILABLE == true)
        SYS_INT_SourceDisable(hDriver->interruptSource1);
        SYS_INT_SourceDisable(hDriver->interruptSource2);
        SYS_INT_SourceDisable(hDriver->interruptSource3);
#endif
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Invalid client");
    }

    return(interruptState);
}

// ****************************************************************************
/* Function:
    void DRV_USBFSV1_HOST_EventsEnable
    (
        DRV_HANDLE handle
        bool eventRestoreContext
    );
    
  Summary:
    Restores the events to the specified the original value.
    
  Description:
    This function will restore the enable disable state of the events.
    eventRestoreContext should be equal to the value returned by the
    DRV_USBFSV1_HOST_EventsDisable() function.
    
  Remarks:
    Refer to drv_usbfs.h for usage information.
*/

void DRV_USBFSV1_HOST_EventsEnable
(
    DRV_HANDLE handle, 
    bool eventContext
)
{
    DRV_USBFSV1_OBJ * hDriver = (DRV_USBFSV1_OBJ *)handle;
   
    if((DRV_HANDLE_INVALID != handle) && (0 != handle) && (hDriver->inUse == true))
    {
        /* All interrupts are either enabled or disabled */
        _DRV_USBFSV1_SYS_INT_SourceEnableRestore(eventContext, hDriver->interruptSource,
                eventContext, hDriver->interruptSource1,eventContext, hDriver->interruptSource2,
                eventContext, hDriver->interruptSource3);
    }
}

// *****************************************************************************
// *****************************************************************************
// Root Hub Driver Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void DRV_USBFSV1_HOST_ROOT_HUB_OperationEnable(DRV_HANDLE handle, bool enable)

  Summary:
    Dynamic implementation of DRV_USBFSV1_HOST_ROOT_HUB_OperationEnable() function.

  Description:
    This function enables the Root Hub Operation. When enabled the root hub will
    supply power to the port thus enabling device attach detection.

  Remarks:
    Refer to drv_usbfs.h for usage information.
*/

void DRV_USBFSV1_HOST_ROOT_HUB_OperationEnable(DRV_HANDLE handle, bool enable)
{
    DRV_USBFSV1_OBJ * pUSBDrvObj = (DRV_USBFSV1_OBJ *)handle;
    usb_registers_t * usbID = pUSBDrvObj->usbID;

    /* Check if the handle is valid or opened */
    if((handle == DRV_HANDLE_INVALID) || (!(pUSBDrvObj->isOpened)))
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Bad Client or client closed");
    }
    else
    {
        if(false == enable)
        {	
             /* If the root hub operation is disable, we disable detach and
             * attached event and switch off the port power. */
	
            SYS_INT_SourceStatusClear((INT_SOURCE)pUSBDrvObj->interruptSource);
            /* Let the host layer know that root hub operation is disabled */

            pUSBDrvObj->operationEnabled = false;
			
			/* Disable USB port by turning off VBUS */ 
			if(pUSBDrvObj->rootHubInfo.portPowerEnable != NULL)
            {   
               pUSBDrvObj->rootHubInfo.portPowerEnable(0 /* Port 0 */, false); 
            }

            if(pUSBDrvObj->rootHubInfo.portPowerEnable != NULL)
            {
                /* Disable the power to the device */
                pUSBDrvObj->rootHubInfo.portPowerEnable(0, false);
            }

            /* For now only disable the connection interrupt */
            usbID->HOST.USB_INTENCLR = USB_HOST_INTENSET_DCONN_Msk;
        }
        else
        {
			/* Enable USB port */ 
			if(pUSBDrvObj->rootHubInfo.portPowerEnable != NULL)
			{
				pUSBDrvObj->rootHubInfo.portPowerEnable(0 /* Port 0 */, true);
			}
			
			/* The USB Global interrupt and USB module is already enabled at
             * this point. We enable the attach interrupt to detect attach
             */
            pUSBDrvObj->operationEnabled = true;

            /* Enable Device Connection Interrupt */
            usbID->HOST.USB_INTENSET = USB_HOST_INTENSET_DCONN_Msk;

        }
    }
}

// *****************************************************************************
/* Function:
    bool DRV_USBFSV1_HOST_ROOT_HUB_OperationIsEnabled(DRV_HANDLE handle)

  Summary:
    Dynamic implementation of DRV_USBFSV1_HOST_OperationIsEnabled function.

  Description:
    Function returns true if the root hub enable operation has completed.

  Remarks:
    Refer to drv_usbfs.h for usage information.

*/

bool DRV_USBFSV1_HOST_ROOT_HUB_OperationIsEnabled(DRV_HANDLE handle)
{
    DRV_USBFSV1_OBJ * hDriver;
    if((handle == DRV_HANDLE_INVALID) || (((DRV_USBFSV1_OBJ *)handle) == NULL))
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Invalid client");
    }
    hDriver = (DRV_USBFSV1_OBJ *)handle;
    return(hDriver->operationEnabled);

}

// ****************************************************************************
/* Function:
    void DRV_USBFSV1_HOST_ROOT_HUB_Initialize
    (
        DRV_HANDLE handle,
        USB_HOST_DEVICE_OBJ_HANDLE usbHostDeviceInfo,
    )

  Summary:
    This function instantiates the root hub driver.

  Description:
    This function initializes the root hub driver. It is called by the host
    layer at the time of processing root hub devices. The host layer assigns a
    USB_HOST_DEVICE_OBJ_HANDLE reference to this root hub driver. This
    identifies the relationship between the root hub and the host layer.

  Remarks:
    None.
*/

void DRV_USBFSV1_HOST_ROOT_HUB_Initialize
(
    DRV_HANDLE handle,
    USB_HOST_DEVICE_OBJ_HANDLE usbHostDeviceInfo
)
{
    DRV_USBFSV1_OBJ * pUSBDrvObj = (DRV_USBFSV1_OBJ *)handle;

    memset((uint8_t *)&pipeDescriptorTable[0], 0, sizeof(pipeDescriptorTable[0]));

    if(DRV_HANDLE_INVALID == handle)
    {
        /* Driver handle is not valid */
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Bad Client or client closed");
    }
    else if(!(pUSBDrvObj->isOpened))
    {
        /* Driver has not been opened. Handle could be stale */
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Bad Client or client closed");
    }
    else
    {
        pUSBDrvObj->usbHostDeviceInfo = usbHostDeviceInfo;
    }
}

// ****************************************************************************
/* Function:
    uint8_t DRV_USBFSV1_HOST_ROOT_HUB_PortNumbersGet(DRV_HANDLE handle);

  Summary:
    Returns the number of ports this root hub contains.

  Description:
    This function returns the number of ports that this root hub contains.

  Remarks:
    None.
*/

uint8_t DRV_USBFSV1_HOST_ROOT_HUB_PortNumbersGet(DRV_HANDLE handle)
{
    DRV_USBFSV1_OBJ * pUSBDrvObj = (DRV_USBFSV1_OBJ *)handle;
    uint8_t result = 0;

    if(DRV_HANDLE_INVALID == handle)
    {
        /* Driver handle is not valid */
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Bad Client or client closed");
    }
    else if(!(pUSBDrvObj->isOpened))
    {
        /* Driver has not been opened. Handle could be stale */
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Bad Client or client closed");
    }
    else
    {
        result = 1;
    }

    return(result);
}

// ****************************************************************************
/* Function:
    uint32_t DRV_USBFSV1_HOST_ROOT_HUB_MaximumCurrentGet(DRV_HANDLE);

  Summary:
    Returns the maximum amount of current that this root hub can provide on the
    bus.

  Description:
    This function returns the maximum amount of current that this root hub can
    provide on the bus.

  Remarks:
    Refer to drv_usbfs.h for usage information.
*/

uint32_t DRV_USBFSV1_HOST_ROOT_HUB_MaximumCurrentGet(DRV_HANDLE handle)
{
    DRV_USBFSV1_OBJ * pUSBDrvObj = (DRV_USBFSV1_OBJ *)handle;
    uint32_t result = 0;

    if(DRV_HANDLE_INVALID == handle)
    {
        /* Driver handle is not valid */
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Bad Client or client closed");
    }
    else if(!(pUSBDrvObj->isOpened))
    {
        /* Driver has not been opened. Handle could be stale */
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Bad Client or client closed");
    }
    else
    {
        result = pUSBDrvObj->rootHubInfo.rootHubAvailableCurrent;
    }

    return(result);
}

// ****************************************************************************
/* Function:
    USB_SPEED DRV_USBFSV1_HOST_ROOT_HUB_BusSpeedGet(DRV_HANDLE handle);

  Summary:
    Returns the speed at which the bus to which this root hub is connected is
    operating.

  Description:
    This function returns the speed at which the bus to which this root hub is
    connected is operating.

 Remarks:
    None.
*/

USB_SPEED DRV_USBFSV1_HOST_ROOT_HUB_BusSpeedGet(DRV_HANDLE handle)
{
    DRV_USBFSV1_OBJ * pUSBDrvObj = (DRV_USBFSV1_OBJ *)handle;
    USB_SPEED speed = USB_SPEED_ERROR;

    if(DRV_HANDLE_INVALID == handle)
    {
        /* Driver handle is not valid */
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Bad Client or client closed");

    }
    else if(!(pUSBDrvObj->isOpened))
    {
        /* Driver has not been opened. Handle could be stale */
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Bad Client or client closed");
    }
    else
    {
        /* Return the bus speed. This is speed at which the root hub is
         * operating. */
        speed = pUSBDrvObj->deviceSpeed;
    }

    return(speed);
}

// ****************************************************************************
/* Function:
    void DRV_USBFSV1_ROOT_HUB_PortResume(DRV_HANDLE handle, uint8_t port );

  Summary:
    Resumes the specified root hub port.

  Description:
    This function resumes the root hub. The resume duration is defined by
    DRV_USBFSV1_ROOT_HUB_RESUME_DURATION. The status of the resume signaling can
    be checked using the DRV_USBFSV1_ROOT_HUB_PortResumeIsComplete() function.

  Remarks:
    The root hub on this particular hardware only contains one port - port 0.
*/

USB_ERROR DRV_USBFSV1_HOST_ROOT_HUB_PortResume(DRV_HANDLE handle, uint8_t port)
{
    /* The functionality is yet to be implemented. */
    return(USB_ERROR_NONE);
}

// ****************************************************************************
/* Function:
    void DRV_USBFSV1_ROOT_HUB_PortSuspend(DRV_HANDLE handle, uint8_t port );

  Summary:
    Suspends the specified root hub port.

  Description:
    This function suspends the root hub port.

  Remarks:
    The root hub on this particular hardware only contains one port - port 0.
*/

USB_ERROR DRV_USBFSV1_HOST_ROOT_HUB_PortSuspend(DRV_HANDLE handle, uint8_t port)
{
    /* The functionality is yet to be implemented. */
    return (USB_ERROR_NONE);
}

// ****************************************************************************
/* Function:
    void DRV_USBFSV1_ROOT_HUB_PortResetIsComplete
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
    Refer to drv_usbfs.h for usage information.
 */

bool DRV_USBFSV1_HOST_ROOT_HUB_PortResetIsComplete
(
    DRV_HANDLE handle,
    uint8_t port
)
{
    DRV_USBFSV1_OBJ * pUSBDrvObj = (DRV_USBFSV1_OBJ *)handle;
    bool result = true;

    if(DRV_HANDLE_INVALID == handle)
    {
        /* Driver handle is not valid */
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Bad Client or client closed");
    }
    else if(!(pUSBDrvObj->isOpened))
    {
        /* Driver has not been opened. Handle could be stale */
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Bad Client or client closed");
    }
    else
    {
        /* Return false if the driver is still resetting*/
        result = (pUSBDrvObj->isResetting) ? false : true;
    }

    return(result);
}

// ****************************************************************************
/* Function:
    void DRV_USBFSV1_ROOT_HUB_PortReset(DRV_HANDLE handle, uint8_t port );
    
  Summary:
    Resets the specified root hub port.
    
  Description:
    This function resets the root hub port. The reset duration is defined by
    DRV_USBFSV1_ROOT_HUB_RESET_DURATION. The status of the reset signaling can be
    checked using the DRV_USBFSV1_ROOT_HUB_PortResetIsComplete() function.
    
  Remarks:
    Refer to drv_usbfs.h for usage information.
*/

USB_ERROR DRV_USBFSV1_HOST_ROOT_HUB_PortReset(DRV_HANDLE handle, uint8_t port)
{
    DRV_USBFSV1_OBJ * pUSBDrvObj = (DRV_USBFSV1_OBJ *)handle;
    USB_ERROR result = USB_ERROR_NONE;

    if(DRV_HANDLE_INVALID == handle)
    {
        /* Driver handle is not valid */
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Bad Client or client closed");
        result = USB_ERROR_PARAMETER_INVALID;
    }
    else if(!(pUSBDrvObj->isOpened))
    {
        /* Driver has not been opened. Handle could be stale */
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Bad Client or client closed");
        result = USB_ERROR_PARAMETER_INVALID;
    }
    else if(pUSBDrvObj->isResetting)
    {
        /* This means a reset is already in progress. Lets not do anything. */
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Reset already in progress");
    }
    else
    {
        /* Start the reset signal. Set the driver flag to indicate the reset
         * signal is in progress. Start generating the reset signal.
         */
        pUSBDrvObj->isResetting = true;
        
        /* Clear the reset interrupt flag just to be really sure we don't get
         * a spurious interrupt. */
        pUSBDrvObj->usbID->HOST.USB_INTFLAG = USB_HOST_INTFLAG_RST_Msk;
        
        /* Enable Reset sent interrupt */
        pUSBDrvObj->usbID->HOST.USB_INTENSET = USB_HOST_INTENSET_RST_Msk;
        
        /* Start Reset */
        pUSBDrvObj->usbID->HOST.USB_CTRLB |= USB_HOST_CTRLB_BUSRESET_Msk;
    }

    return(result);
}    

// ****************************************************************************
/* Function:
    USB_SPEED DRV_USBFSV1_HOST_ROOT_HUB_PortSpeedGet
    (
        DRV_HANDLE handle,
        uint8_t port
    );

  Summary:
    Returns the speed of at which the port is operating.

  Description:
    This function returns the speed at which the port is operating.

  Remarks:
    Refer to drv_usbfs.h for usage information.
*/

USB_SPEED DRV_USBFSV1_HOST_ROOT_HUB_PortSpeedGet(DRV_HANDLE handle, uint8_t port)
{
    DRV_USBFSV1_OBJ * pUSBDrvObj = (DRV_USBFSV1_OBJ *)handle;
    USB_SPEED speed = USB_SPEED_ERROR;

   if(DRV_HANDLE_INVALID == handle)
    {
        /* Driver handle is not valid */
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Bad Client or client closed");
    }
    else if(!(pUSBDrvObj->isOpened))
    {
        /* Driver has not been opened. Handle could be stale */
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV USBFSV1: Bad Client or client closed");
    }
    else
    {
        /* The driver will not check if a device is connected. It is assumed
         * that the client has issued a port reset before calling this function
         */
        speed = pUSBDrvObj->deviceSpeed;
    }

    return(speed);
}

// ****************************************************************************
/* Function:
    void DRV_USBFSV1_HOST_EndpointToggleClear
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
    Refer to drv_usbfsv1.h for usage information.
*/

void DRV_USBFSV1_HOST_EndpointToggleClear
(
    DRV_USBFSV1_HOST_PIPE_HANDLE pipeHandle
)
{
    DRV_USBFSV1_HOST_PIPE_OBJ * pipe = NULL;

    if((pipeHandle != 0) && (pipeHandle != DRV_USBFSV1_HOST_PIPE_HANDLE_INVALID))
    {
        pipe = (DRV_USBFSV1_HOST_PIPE_OBJ *) pipeHandle;
        if(pipe->inUse)
        {
            /* Reset the data toggle */
            pipe->dataToggle = 0;
        }
    }
    else
    {
        SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "\r\nDRV_USBHSV1: Invalid Pipe Handle");
    }
} 
