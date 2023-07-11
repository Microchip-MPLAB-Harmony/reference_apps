/*******************************************************************************
   USB EHCI Local Header Routines

   Company:
    Microchip Technology Inc.

   File Name:
    drv_usb_ehci_local.h

   Summary:
    USB EHCI Driver Local Header File.

   Description:
    This file contains type definitions, prototypes and constants required
    by the EHCI driver.
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

#ifndef _DRV_USB_EHCI_LOCAL_H
#define _DRV_USB_EHCI_LOCAL_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "configuration.h"
#include "definitions.h"
#include "osal/osal.h"
#include "driver/usb/drv_usb.h"
#include "usb/usb_host.h"
#include "usb/usb_host_client_driver.h"
#include "usb/usb_ehci.h"
#include "driver/usb/uhp/drv_usb_ehci.h"
#include <string.h>

#define _DRV_USB_EHCI_NON_CACHED __attribute__((__section__(".region_nocache")))
#define _DRV_USB_EHCI_POLLING_RATE(x) ((1 << (x-1))/8)
/**********************************************
 * Defines the size of the periodic frame list
 **********************************************/
#define DRV_USB_EHCI_PERIODIC_LIST_SIZE 1024
#define DRV_USB_EHCI_PORT_NUMBERS 3

/************************************************
 * Maximum bytes per qTD. See section 3.5 of
 * of the specification.
 ************************************************/
#define DRV_USB_EHCI_MAX_QTD_NBYTES 20480


/********************************************
 * PORTSC register access between SAMA7G5x,
 * SAM9x and SAMA5D2 are different.
 *******************************************/

#ifdef UHPHS_PORTSC_REG_OFST

    /* This is for SAM9x */
    #define UHPHS_PORTSC_REG        UHPHS_PORTSC_REG_OFST
    #define UHPHS_PORTSC_N_CSC_Msk  UHPHS_PORTSC_CSC_Msk
    #define UHPHS_PORTSC_N_LS_Msk   UHPHS_PORTSC_LS_Msk
    #define UHPHS_PORTSC_N_LS_Pos   UHPHS_PORTSC_LS_Pos
    #define UHPHS_PORTSC_N_CCS_Msk  UHPHS_PORTSC_CCS_Msk
    #define UHPHS_PORTSC_N_PO_Msk   UHPHS_PORTSC_PO_Msk
    #define UHPHS_PORTSC_N_PR_Msk   UHPHS_PORTSC_PR_Msk
    #define UHPHS_PORTSC_N_PP_Msk   UHPHS_PORTSC_PP_Msk
    #define UHPHS_PORTSC_N_PED_Msk  UHPHS_PORTSC_PED_Msk

#ifdef _SAMA7G54_H_
        /* Specific to SAMA7G54 */
        #define PMC_UCKR_UPLLEN() \
            UDPHSA_REGS->UDPHS_CTRL &= ~UDPHS_CTRL_EN_UDPHS_Msk; \
            for(i = 0; i < DRV_USB_EHCI_PORT_NUMBERS; i ++) \
            { \
                if(drvInit->bmPortSelect & (1 << i)) \
                { \
                    RSTC_REGS->RSTC_GRSTR &= ~(1 << (4+i)); \
                } \
            }
        #define IS_LOCKU_ENABLE()  1
#elif defined(_SAM9X60_H_)
        /* Specific to SAM9X60 */
        #define PMC_PCR_GCKCSS_UPLL_CLK  PMC_PCR_GCLKCSS(PMC_PCR_GCLKCSS_UPLL_Val) 

        #define PMC_UCKR_UPLLEN()   \
            PMC_REGS->PMC_PCR = PMC_PCR_PID(hDriver->interruptSource);\
            PMC_REGS->PMC_PCR = PMC_PCR_PID(hDriver->interruptSource) | PMC_PCR_CMD_Msk | PMC_PCR_EN_Msk | PMC_PCR_GCKCSS_UPLL_CLK;\
            while ((PMC_REGS->PMC_PLL_ISR0 & PMC_PLL_ISR0_LOCKU_Msk) != PMC_PLL_ISR0_LOCKU_Msk)

        #define IS_LOCKU_ENABLE()  ((PMC_REGS->PMC_PLL_ISR0 & PMC_PLL_ISR0_LOCKU_Msk) == PMC_PLL_ISR0_LOCKU_Msk)
#elif defined(_SAM9X70_H_) || defined(_SAM9X72_H_) || defined(_SAM9X75_H_)
        /* Specific to SAM9X7 */
        #define PMC_UCKR_UPLLEN()   \
            UDPHS_REGS->UDPHS_CTRL &= ~UDPHS_CTRL_EN_UDPHS_Msk; \
            PMC_REGS->PMC_PLL_ACR = PMC_PLL_ACR_UTMIBG_Msk; \
            for(i = 0; i < 800; i ++) \
            { \
                __NOP(); \
            } \
            PMC_REGS->PMC_PLL_ACR = PMC_PLL_ACR_UTMIVR_Msk; \
            for(i = 0; i < 800; i ++) \
            { \
                __NOP(); \
            } \
            PMC_REGS->PMC_PLL_UPDT = PMC_PLL_UPDT_UPDATE_Msk;
        #define IS_LOCKU_ENABLE()  1
#endif

#endif /* UHPHS_PORTSC_REG_OFST */

#ifdef UHPHS_PORTSC_0_REG_OFST

    /* This is for SAMA5D2 */
    #define UHPHS_PORTSC_REG        UHPHS_PORTSC_0_REG_OFST
    #define UHPHS_PORTSC_N_CSC_Msk  UHPHS_PORTSC_0_CSC_Msk
    #define UHPHS_PORTSC_N_LS_Msk   UHPHS_PORTSC_0_LS_Msk
    #define UHPHS_PORTSC_N_LS_Pos   UHPHS_PORTSC_0_LS_Pos
    #define UHPHS_PORTSC_N_CCS_Msk  UHPHS_PORTSC_0_CCS_Msk
    #define UHPHS_PORTSC_N_PO_Msk   UHPHS_PORTSC_0_PO_Msk
    #define UHPHS_PORTSC_N_PR_Msk   UHPHS_PORTSC_0_PR_Msk
    #define UHPHS_PORTSC_N_PP_Msk   UHPHS_PORTSC_0_PP_Msk
    #define UHPHS_PORTSC_N_PED_Msk  UHPHS_PORTSC_0_PED_Msk

    #define PMC_UCKR_UPLLEN()   \
    PMC_REGS->CKGR_UCKR = CKGR_UCKR_UPLLCOUNT_Msk | CKGR_UCKR_UPLLEN_Msk;\
    PMC_REGS->PMC_PCR = PMC_PCR_PID(hDriver->interruptSource);\
    PMC_REGS->PMC_PCR = PMC_PCR_PID(hDriver->interruptSource) | PMC_PCR_CMD_Msk | PMC_PCR_EN_Msk | PMC_PCR_GCKCSS_UPLL_CLK;\
    while ((PMC_REGS->PMC_SR & PMC_SR_LOCKU_Msk) != PMC_SR_LOCKU_Msk)
      
    #define IS_LOCKU_ENABLE()  ((PMC_REGS->PMC_SR & PMC_SR_LOCKU_Msk) == PMC_SR_LOCKU_Msk)
#endif

/*********************************************
 * These IRP states are used internally by the
 * HCD to track completion of a host IRP. This
 * is not the same as the public IRP status
 *********************************************/
typedef enum DRV_USB_EHCI_IRP_STATE
{
    DRV_USB_EHCI_IRP_STATE_IDLE = 0,
    DRV_USB_EHCI_IRP_STATE_SETUP_STAGE,
    DRV_USB_EHCI_IRP_STATE_SETUP_TOKEN_SENT,
    DRV_USB_EHCI_IRP_STATE_DATA_STAGE,
    DRV_USB_EHCI_IRP_STATE_DATA_STAGE_SENT,
    DRV_USB_EHCI_IRP_STATE_HANDSHAKE,
    DRV_USB_EHCI_IRP_STATE_HANDSHAKE_SENT,
    DRV_USB_EHCI_IRP_STATE_COMPLETE,
    DRV_USB_EHCI_IRP_STATE_ABORTED,
    DRV_USB_EHCI_IRP_STATE_PROCESSING

} DRV_USB_EHCI_IRP_STATE;

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
    DRV_USB_EHCI_IRP_STATE tempState;
    uint32_t completedBytes;
    uint32_t scheduledBytes;
    void * next;
    DRV_USB_EHCI_PIPE_HANDLE  pipe;

} USB_HOST_IRP_LOCAL;

/***********************************************
 * Port Attach State.
 ***********************************************/

typedef enum DRV_USB_EHCI_PORT_ATTACH_STATE
{
    /* Waiting for attach */
    DRV_USB_EHCI_PORT_ATTACH_STATE_WAITING_FOR_ATTACH = 0,

    /* Start Attach Debounce */
    DRV_USB_EHCI_PORT_ATTACH_STATE_START_ATTACH_DEBOUNCE,

    /* Wait for the debounce to complete */
    DRV_USB_EHCI_PORT_ATTACH_STATE_START_WAIT_DEBOUNCE,

    /* Reset the port to find out the port speed */ 
    DRV_USB_EHCI_PORT_ATTACH_STATE_START_RESET,

    /* Wait for reset to complete */
    DRV_USB_EHCI_PORT_ATTACH_STATE_WAIT_RESET,

    /* Wait for port enable */
    DRV_USB_EHCI_PORT_ATTACH_STATE_WAIT_PORT_ENABLE,

    /* Wait for device detach */
    DRV_USB_EHCI_PORT_ATTACH_STATE_WAIT_FOR_DETACH,

    /* Waiting for OHCI Handover */
    DRV_USB_EHCI_PORT_ATTACH_STATE_OHCI_HANDOVER

} DRV_USB_EHCI_PORT_ATTACH_STATE;


/***********************************************
 * Port management data structure
 ***********************************************/

typedef struct DRV_USB_EHCI_PORT_OBJ
{
    /* If true, the EHCI driver will check this port for activity */
    bool selected;

    /* Host Device Object Handle of the device connected to this port */
    USB_HOST_DEVICE_OBJ_HANDLE attachedDeviceObjHandle;

    /* Indicates that an event has occurred on this port */
    volatile bool interruptHasOccurred;

    /* The attach state for this host */
    DRV_USB_EHCI_PORT_ATTACH_STATE portAttachState;

    /* Timer Handle */
    SYS_TIME_HANDLE timerHandle;

    /* Flag is true if port is resetting */
    bool isResetting;


} DRV_USB_EHCI_PORT_OBJ;

/*********************************************
 * The EHCI Driver Transfer Descriptor.
 *********************************************/
typedef struct DRV_USB_EHCI_QTD
{
    /* The EHCI qTD. This should be the first element of the structure as the
     * structure will be aligned on a 32 byte boundary */
    USB_EHCI_QTD qTD;

    /* True if structurre is in use */
    bool inUse;

    /* Pointer to the IRP connected to this qTD */
    USB_HOST_IRP_LOCAL * irp;

    /* Transfer buffer that will be used by this qTD */
    uint8_t * transferBuffer;

    /* Padding bytes. This should be adjusted to get 64 bytes. */
    uint8_t unused[20];

} DRV_USB_EHCI_QTD;

/***********************************************
 * Pipe closing state machine.
 ***********************************************/
typedef enum DRV_USB_EHCI_PIPE_CLOSE_STATE
{
    /* Nothing to here */
    DRV_USB_EHCI_PIPE_CLOSE_IDLE = 0,

    /* Pipe close has been requested */
    DRV_USB_EHCI_PIPE_CLOSE_REQUEST_PENDING,

    /* Waiting for qhead to deactivate */
    DRV_USB_EHCI_PIPE_CLOSE_QHEAD_DEACTIVATE_WAIT,

    /* Remove qHead if possible */
    DRV_USB_EHCI_PIPE_CLOSE_REMOVE_QHEAD,
    
    /* Wait for frame rollover */    
    DRV_USB_EHCI_PIPE_CLOSE_WAIT_FRAME_ROLLOVER,

    /* Wait for Async Advance Interrupt */
    DRV_USB_EHCI_PIPE_CLOSE_WAIT_ASYNC_ADVANCE,

    /* Wait for Async schedule to be disabled */
    DRV_USB_EHCI_PIPE_CLOSE_WAIT_ASYNC_DISABLE,
    
    /* Wait for Async schedule to get enabled */
    DRV_USB_EHCI_PIPE_CLOSE_WAIT_ASYNC_ENABLE
      
} DRV_USB_EHCI_PIPE_CLOSE_STATE;


/***********************************************
 * The EHCI Driver Queue Structure. 
 ***********************************************/
typedef struct _DRV_USB_EHCI_QH 
{
    /* The actual EHCI Queue head. This should be the first member in the
     * structure as this structure will be aligned on an 64 byte boundary */
    USB_EHCI_QH qH;

    /* True if the object has been allocated. We are using this bitmap as we
     * dont want to unnecessarily increase the size of this structure. Doing so
     * would other wise force us to add another 64 bytes to maintain alignment.
     * */
    struct
    {
        unsigned int pipeType:4;
        unsigned int bInterval:4;
        unsigned int inUse:1;
        unsigned int direction:1;
        unsigned int pipeClosingState:3;
        unsigned int pipeInQueue:1;
        unsigned int microFrameIndex:3;
        unsigned int startSlot:10;
        unsigned int speed:2;
        unsigned int :3;
    };

    /* Pipe IRP Queue Head */
    DRV_USB_EHCI_QTD * currentQTD;

    /* Unique Key of the pipe handle */
    uint16_t clientUniqueKey;

    /* Pointer to the queue handling function for this queue */
    void (*queueHandler)(void * pipe); 

} DRV_USB_EHCI_QH;

/************************************************
 * The possible state of the driver task
 ************************************************/

typedef enum
{
    /* Driver is not yet initialized */
    DRV_USB_EHCI_TASK_STATE_UNINITIALIZED = 0,

    /* Waiting for the clock to stablize */
    DRV_USB_EHCI_TASK_STATE_WAIT_FOR_CLOCK,

    /* Driver is running */
    DRV_USB_EHCI_TASK_STATE_RUNNING,

    /* Driver is idle - nothing to do */
    DRV_USB_EHCI_TASK_STATE_IDLE,

    /* Driver is in an error state */
    DRV_USB_EHCI_TASK_STATE_ERROR

} DRV_USB_EHCI_TASK_STATE;

/*************************************************
 * Definition of the multi QTD strcuture needed
 * for control transfers
 *************************************************/

typedef struct DRV_USB_EHCI_CONTROL_TRANSFER_QTD
{
    /* This QTD for the setup stage */
    USB_EHCI_QTD setupQTD;

    /* This QTD needd for the optional data stage */
    USB_EHCI_QTD dataQTD;

    /* This QTD needd for the handshake stage */
    USB_EHCI_QTD handshakeQTD;

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

} DRV_USB_EHCI_CONTROL_TRANSFER_QTD;


/**********************************************
 * States of the operation enable task routine
 **********************************************/
typedef enum DRV_USB_EHCI_OPERATION_ENABLE_STATE
{
    /* HC is in disabled state */
    DRV_USB_EHCI_OPERATION_ENABLE_DISABLE = 0,

    /* Start enabling the HC */
    DRV_USB_EHCI_OPERATION_ENABLE_START,
    
    /* Wait for HC to halt */
    DRV_USB_EHCI_OPERATION_ENABLE_WAIT_FOR_HALT,
    
    /* Reset the HC */
    DRV_USB_EHCI_OPERATION_ENABLE_HC_RESET,

    /* Wait for Reset to complete */
    DRV_USB_EHCI_OPERATION_ENABLE_WAIT_RESET,

    /* Wait for the controller to enter Run state */
    DRV_USB_EHCI_OPERATION_ENABLE_WAIT_RUN,

    /* Operation is enabled. Nothing more to do */
    DRV_USB_EHCI_OPERATION_ENABLE_IDLE

} DRV_USB_EHCI_OPERATION_ENABLE_STATE;


/***********************************************
 * The EHCI Driver Object Structure. 
 ***********************************************/
typedef struct DRV_USB_EHCI_OBJ
{
    /* In Use flag */
    bool inUse;

    /* System Status */
    SYS_STATUS status;

    /* Unique Keys for Handle Identifier */
    uint16_t uniqueKey;

    /* EHCI registers pointer */
    uhphs_registers_t * usbID;

    /* Driver is opened */
    bool isOpened;

    /* Current driver handle identifier */
    uint16_t clientUniqueKey;

    /* Mutex that will be used by this driver instance */
    OSAL_MUTEX_DECLARE (mutex);

    /* Port Power Enable Functions */
    DRV_USB_EHCI_PORT_POWER_ENABLE portPowerEnable;

    /* Port Over Current Detection */
    DRV_USB_EHCI_PORT_INDICATION portIndication;

    /* Port Over Current Detection */
    DRV_USB_EHCI_PORT_OVER_CURRENT_DETECT portOverCurrentDetect;

    /* Port Root Hub Current Capability */
    uint32_t rootHubAvailableCurrent;

    /* Interrupt Source */
    INT_SOURCE interruptSource;

    /* Data structures to manage ports */
    DRV_USB_EHCI_PORT_OBJ ports[DRV_USB_EHCI_PORT_NUMBERS];

    /* Pointer to Periodic Frame List */
    uint32_t * periodicList;

    /* Task State */
    DRV_USB_EHCI_TASK_STATE taskState;

    /* Queue heads that this driver will use */
    DRV_USB_EHCI_QH * queueHeads;

    /* QTD that this driver will use */
    DRV_USB_EHCI_QTD * queueTransferDescriptors;

    /* Control Transfer QTDs */
    DRV_USB_EHCI_CONTROL_TRANSFER_QTD * controlTransferQTD;

    /* The Device Object Handle assigned by the host layer */
    USB_HOST_DEVICE_OBJ_HANDLE usbHostDeviceInfo;

    /* Flag is true if operation is enabled */
    bool operationEnabled;

    /* Operation enable state */
    DRV_USB_EHCI_OPERATION_ENABLE_STATE operationEnableState;

    /* True if driver is in interrupt context */
    bool inInterruptContext;

    /* If true indicates that a pipe is currently being closed */
    bool pipeIsClosing;

    /* Async Schedule Head Queue head */
    USB_EHCI_QH * asyncHeadQH;

    /* Microframe slot usage counter. Array of 8 for eight microframes. Needed
     * for interrupt pipes. */
    uint8_t microFrameUsage[8];

    /* Next periodic slot to use */
    uint32_t nextSlotToUse[16];

    /* Companion controller Index */
    SYS_MODULE_INDEX companionDriverIndex;

} DRV_USB_EHCI_OBJ;


#endif

