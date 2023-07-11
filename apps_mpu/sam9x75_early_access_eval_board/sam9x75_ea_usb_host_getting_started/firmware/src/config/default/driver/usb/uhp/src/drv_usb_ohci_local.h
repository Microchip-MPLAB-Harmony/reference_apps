/*******************************************************************************
   USB OHCI Local Header Routines

   Company:
    Microchip Technology Inc.

   File Name:
    drv_usb_ehci_local.h

   Summary:
    USB OHCI Driver Local Header File.

   Description:
    This file contains type definitions, prototypes and constants required
    by the OHCI driver.
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

#ifndef _DRV_USB_OHCI_LOCAL_H
#define _DRV_USB_OHCI_LOCAL_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "configuration.h"
#include "definitions.h"
#include "osal/osal.h"
#include "driver/usb/drv_usb.h"
#include "usb/usb_host.h"
#include "usb/usb_host_client_driver.h"
#include "usb/usb_ohci.h"
#include "driver/usb/uhp/drv_usb_ohci.h"
#include <string.h>

#define DRV_USB_OHCI_PORTS_NUMBER 3
/*************************************
 * Driver non cached memory
 ************************************/
#define DRV_USB_OHCI_MAXIMUM_OVERHEAD 210
#define DRV_USB_OHCI_PRDSTRT (12000 * 90/100)
#define _DRV_USB_OHCI_NON_CACHED __attribute__((__section__(".region_nocache")))
#define _DRV_USB_OHCI_DRV_TO_ED_HEADP(x) ((uint32_t)(x) >> 4)
#define _DRV_USB_OHCI_ED_TO_DRV_HEADP(x) ((uint32_t)(x) << 4)
#define DRV_USB_OHCI_POST_PORT_ENABLE_DELAY 10
#define DRV_USB_OHCI_TRANSFERS_NUMBER (USB_HOST_TRANSFERS_NUMBER + USB_HOST_PIPES_NUMBER)

/*********************************************
 * These IRP states are used internally by the
 * HCD to track completion of a host IRP. This
 * is not the same as the public IRP status
 *********************************************/
typedef enum DRV_USB_OHCI_IRP_STATE
{
    DRV_USB_OHCI_IRP_STATE_IDLE = 0,
    DRV_USB_OHCI_IRP_STATE_COMPLETE,
    DRV_USB_OHCI_IRP_STATE_PROCESSING,
    DRV_USB_OHCI_IRP_STATE_ABORTED

} DRV_USB_OHCI_IRP_STATE;

/***********************************************
 * Pipe Closing State.
 ***********************************************/
typedef enum DRV_USB_OHCI_PIPE_CLOSING_STATE
{
    /* Pipe is not closing */
    DRV_USB_OHCI_PIPE_CLOSING_STATE_IDLE = 0,

    /* Pipe is marked for closing */
    DRV_USB_OHCI_PIPE_CLOSING_STATE_CLOSE_REQUESTED,

    /* Wait for the SOF to complete */
    DRV_USB_OHCI_PIPE_CLOSING_STATE_WAIT_SOF

} DRV_USB_OHCI_PIPE_CLOSING_STATE;

/***********************************************
 * Port Attach State.
 ***********************************************/

typedef enum DRV_USB_OHCI_PORT_ATTACH_STATE
{
    /* Waiting for attach */
    DRV_USB_OHCI_PORT_ATTACH_STATE_WAITING_FOR_ATTACH = 0,

    /* Start Attach debounce */
    DRV_USB_OHCI_PORT_ATTACH_STATE_START_ATTACH_DEBOUNCE,

    /* Wait for the debounce to complete */
    DRV_USB_OHCI_PORT_ATTACH_STATE_WAIT_DEBOUNCE,

    /* Wait for port enable */
    DRV_USB_OHCI_PORT_ATTACH_STATE_WAIT_PORT_ENABLE,
    
    /* After the port has been enabled, wait for some time */
    DRV_USB_OHCI_PORT_ATTACH_STATE_POST_ENABLE_DELAY,

    /* Wait for the delay to complete */
    DRV_USB_OHCI_PORT_ATTACH_STATE_POST_ENABLE_DELAY_WAIT,

    /* Wait for device detach */
    DRV_USB_OHCI_PORT_ATTACH_STATE_WAIT_FOR_DETACH

} DRV_USB_OHCI_PORT_ATTACH_STATE;

/***********************************************
 * Driver Operation enable state
 ***********************************************/

typedef enum
{
    /* Nothing to do in the operation enable */
    DRV_USB_OHCI_OPERATION_ENABLE_IDLE = 0,

    /* Start the Power On to Power Good Delay */
    DRV_USB_OHCI_OPERATION_ENABLE_START_PO2PGT_DELAY,

    /* Check if delay is completed */
    DRV_USB_OHCI_OPERATION_ENABLE_PO2PGT_DELAY_WAIT

} DRV_USB_OHCI_OPERATION_ENABLE_STATE;

/***********************************************
 * Port management data structure
 ***********************************************/

typedef struct DRV_USB_OHCI_PORT_OBJ
{
    /* If true, the OHCI driver will check this port for activity */
    bool selected;

    /* Host Device Object Handle of the device connected to this port */
    USB_HOST_DEVICE_OBJ_HANDLE attachedDeviceObjHandle;

    /* The attach state for this host */
    DRV_USB_OHCI_PORT_ATTACH_STATE portAttachState;

    /* Timer handle is used for attach debouncing*/
    SYS_TIME_HANDLE timerHandle;

    /* Flag is true if port is resetting */
    bool isResetting;

    /* If true, then port should be disabled */
    bool disableThisPort;

    /* Port speed */
    USB_SPEED portSpeed;

} DRV_USB_OHCI_PORT_OBJ;

/*********************************************
 * This is the local USB Host IRP object
 ********************************************/
typedef struct USB_HOST_IRP_LOCAL
{
    /* Points to the 8 byte setup command
     * packet in case this is a IRP is 
     * scheduled on a CONTROL pipe. Should
     * be NULL otherwise */
    void * setup;

    /* Pointer to data buffer */
    void * data;
    
    /* Size of the data buffer */
    unsigned int size;
    
    /* Status of the IRP */ 
    USB_HOST_IRP_STATUS status;

    /* Request specific flags */
    USB_HOST_IRP_FLAG flags;

    /* User data */
    uintptr_t userData;

    /* Pointer to function to be called
     * when IRP is terminated. Can be 
     * NULL, in which case the function
     * will not be called. */
    void (*callback)(struct _USB_HOST_IRP * irp);

    /****************************************
     * These members of the IRP should not be
     * modified by client
     ****************************************/

    uint32_t tempSize;
    DRV_USB_OHCI_IRP_STATE tempState;
    uint32_t completedBytes;
    uint32_t scheduledBytes;
    void * next;
    DRV_USB_OHCI_PIPE_HANDLE  pipe;

} USB_HOST_IRP_LOCAL;

/*********************************************
 * The OHCI Driver Transfer Descriptor.
 *********************************************/

typedef struct 
{
    /* The EHCI qTD. This should be the first element of the structure as the
     * structure will be aligned on a 32 byte boundary */
    USB_OHCI_TD td;

    /* True if structure is in use */
    bool inUse;

    /* Pointer to the IRP connected to this qTD */
    USB_HOST_IRP_LOCAL * irp;

    /* Transfer buffer that will be used by this qTD */
    uint8_t * transferBuffer;

    /* Padding bytes. This should be adjusted to get 64 bytes. */
    uint8_t unused[4];

} DRV_USB_OHCI_TD;

/***********************************************
 * The OHCI Driver Endpoint Structure. 
 ***********************************************/

typedef struct  
{
    /* The actual OHCI Endpoint Descriptor. This should be the first member in the
     * structure as this structure will be aligned on an 16 byte boundary */
    USB_OHCI_ED ed;

    /* We are using this bitmap as we don t want to unnecessarily increase the
     * size of this structure. Doing so would other wise force us to add
     * additional padding bytes to maintain alignment.  */
    struct
    {
        unsigned int pipeType:4;
        unsigned int bInterval:4;
        unsigned int inUse:1;
        unsigned int direction:1;
        unsigned int pipeClosingState:4;
        unsigned int pollingRate:8;
        unsigned int speed:2;
        unsigned int startSlot:8;
    };

    /* Pipe IRP Queue Head */
    DRV_USB_OHCI_TD * currentTD;

    /* Unique Key of the pipe handle */
    uint32_t clientUniqueKey;

    /* Pointer to the queue handling function for this queue */
    void (*queueHandler)(void * pipe, void * hDriver); 

} DRV_USB_OHCI_ED;

/*************************************************
 * Definition of the multi TD structure needed
 * for control transfers
 *************************************************/

typedef struct DRV_USB_OHCI_CONTROL_TD
{
    /* This QTD for the setup stage */
    USB_OHCI_TD setupTD;

    /* This QTD need for the optional data stage */
    USB_OHCI_TD dataTD;

    /* This QTD need for the handshake stage */
    USB_OHCI_TD handshakeTD;

    /* The driver setup buffer */
    uint8_t setupBuffer[8];

    /* The driver control transfer data buffer */
    uint8_t * dataBuffer;

    /* True if the object is currently allocated. */
    bool inUse;

    /* Pointer to the IRP associated with this object */
    USB_HOST_IRP_LOCAL * irp;

    /* Padding required for alignment */
    uint8_t padding[12];

} DRV_USB_OHCI_CONTROL_TD;

/**************************************
 * Driver Hardware Instance Object
 **************************************/
typedef struct DRV_USB_OHCI_OBJ
{
    /* True if this object is in use */
    bool inUse;

    /* Harmony System Status */
    SYS_STATUS status;

    /* Pointer to the OHCI register set */
    volatile UhpOhci * usbID;

    /* Driver is opened */
    bool isOpened;

    /* True is pipe is closing */
    bool pipeIsClosing;

    /* Current driver handle identifier */
    uint16_t clientUniqueKey;
    
    /* Interrupt Source */
    INT_SOURCE interruptSource;

    /* Data structure to manage ports */
    DRV_USB_OHCI_PORT_OBJ ports[DRV_USB_OHCI_PORTS_NUMBER];

    /* Identifier assigned by the host layer */
    USB_HOST_DEVICE_OBJ_HANDLE usbHostDeviceInfo;

    /* Mutex for shared data structures */
    OSAL_MUTEX_DECLARE(mutex);

    /* Port Power Enable Functions */
    DRV_USB_OHCI_PORT_POWER_ENABLE portPowerEnable;

    /* Port Over Current Detection */
    DRV_USB_OHCI_PORT_INDICATION portIndication;

    /* Port Over Current Detection */
    DRV_USB_OHCI_PORT_OVER_CURRENT_DETECT portOverCurrentDetect;

    /* Port Root Hub Current Capability */
    uint32_t rootHubAvailableCurrent;

    /* Flag is true if operation is enabled */
    bool operationEnabled;

    /* True if driver is in interrupt context */
    bool inInterruptContext;

    /* Handle unique key count */
    uint16_t uniqueKey;

    /* Periodic list next slot to use. Counter for each polling index */
    uint8_t nextSlotToUse[6];

    /* The endpoint descriptors that this instance will use */
    DRV_USB_OHCI_ED * endpointDescriptors;

    /* The transfer descriptors that this instance will use */
    DRV_USB_OHCI_TD * transferDescriptors;

    /* The control transfer descriptors that this instance will use */
    DRV_USB_OHCI_CONTROL_TD * controlTransferDescriptors; 

    /* The OHCI HCCA area for this instance */
    USB_OHCI_HCCA * hcHCCA;

    /* Timer handle for driver level timer delay operations */
    SYS_TIME_HANDLE timerHandle;

    /* Operation Enable State */
    DRV_USB_OHCI_OPERATION_ENABLE_STATE operationEnableState;

    /* SOF Count tracker */
    int sofCount;

} DRV_USB_OHCI_OBJ;

#endif


