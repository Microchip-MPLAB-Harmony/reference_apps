 /*******************************************************************************
  USB HOST HID class definitions

  Company:
    Microchip Technology Inc.

  File Name:
    usb_host_hid_local.h

  Summary:
    USB HID class definitions

  Description:
    This file describes the HID class specific definitions.
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
// DOM-IGNORE-END

#ifndef _USB_HOST_HID_LOCAL_H
#define _USB_HOST_HID_LOCAL_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "usb/usb_host_hid.h"
#include "usb/src/usb_host_local.h"
/*
 * Macro defines the value to be shifted to obtain item type.
 */
#define USB_HOST_HID_ITEM_TYPE_SHIFT                           2

/*
 * Macro defines the value to be shifted to obtain item tag.
 */
#define USB_HOST_HID_ITEM_TAG_SHIFT                            4

/*
 * Macro defines the value to be masked with to obtain item type.
 */
#define USB_HOST_HID_ITEM_TYPE_MASK                            3

/*
 * Macro defines the value to be masked with to obtain item tag.
 */
#define USB_HOST_HID_ITEM_TAG_MASK                             15
/*
 * Macro defines the tag value for Long items.
 */
#define USB_HOST_HID_ITEM_TAG_LONG                             15

/*
 * Macro defines the value to be masked with to obtain item size.
 */
#define USB_HOST_HID_ITEM_SIZE_MASK                            3

/*
 * Macro defines the value to be shifted to represent
 * Usage Page and Usage ID together in 32 bits.
 */
#define USB_HOST_HID_USAGE_PAGE_SHIFT                          16

/*
 * Macro defines field size in bits format for field size of 8 bits.
 */
#define USB_HOST_HID_FIELD_SIZE_1_BYTE                         8

/*
 * Macro defines field size in bits format for field size of 16 bits.
 */
#define USB_HOST_HID_FIELD_SIZE_2_BYTE                         16

/*
 * Macro defines field size in bits format for field size of 32 bits.
 */
#define USB_HOST_HID_FIELD_SIZE_4_BYTE                         32

/*
 * Macro defines optional data size of 1 byte.
 */
#define USB_HOST_HID_SHORT_ITEM_DATA_SIZE_1_BYTE               1

/*
 * Macro defines optional data size of 2 byte.
 */
#define USB_HOST_HID_SHORT_ITEM_DATA_SIZE_2_BYTE               2

/*
 * Macro defines optional data size of 4 byte.
 */
#define USB_HOST_HID_SHORT_ITEM_DATA_SIZE_4_BYTE               4

/*
 * Macro defines the value to be shifted to represent
 * Usage Page and Usage ID together in 32 bits.
 */
#define USB_HOST_HID_USAGE_PAGE_SHIFT                          16

/***********************************************
 * Read\Write Data buffers needed by for the HID function driver instance.
 ***********************************************/
volatile uint8_t gUSBHostHIDReadBuffer[USB_HOST_HID_INSTANCES_NUMBER][64] USB_ALIGN;
volatile uint8_t gUSBHostHIDWriteBuffer[USB_HOST_HID_INSTANCES_NUMBER][64] USB_ALIGN;

// *****************************************************************************
/* USB HOST HID command request object

  Summary:
    USB HOST HID command request object.

  Description:
    USB HOST HID command request object.
  
  Remarks:
    None.
 */

typedef struct
{
    /* Set up packet for this command request */
    USB_SETUP_PACKET setupPacket;

    /* A callback to be called when the request is complete */
    void * callback;
    
    /* Flag to track control request completion */
    bool controlRequestDone;
    
    /* Flag to track usage driver requests */
    bool usageDriverRequest;
    
    /* Holds the usage driver table index. This is valid only if
    usageDriverRequest = true */
    int8_t usageDriverTableIndex;
    
    /* Holds the handle of the usage driver requesting the transfer. Valid
    only if usageDriverRequest = true */
    USB_HOST_HID_OBJ_HANDLE handle;
    
    /* Result of the control transfer */
    USB_HOST_RESULT result;
    
    /* The number of bytes to process */
    size_t size;

} USB_HOST_HID_REQUEST;

// *****************************************************************************
/*  USB Host HID Class Driver Index

  Summary:
     USB Host HID Class Driver Index

  Description:
    This uniquely identifies a HID Class Driver instance.

  Remarks:
    None.
*/

typedef uintptr_t USB_HOST_HID_INDEX;


// *****************************************************************************
/* USB HOST HID driver state

  Summary:
    Identifies the different HID instance states.

  Description:
    These macros are useful to identify  USB HOST HID driver status.
  
  Remarks:
    None.
 */

typedef enum
{
    USB_HOST_HID_STATE_ATTACHED                      = 1,
    USB_HOST_HID_STATE_DETACHED,
    USB_HOST_HID_STATE_SET_IDLE_SEND,
	USB_HOST_HID_STATE_WAITING_SET_IDLE,
    USB_HOST_HID_STATE_SEND_SET_PROTOCOL,
    USB_HOST_HID_STATE_SET_PROTOCOL_SEND,
	USB_HOST_HID_STATE_WAITING_SET_PROTOCOL,
    USB_HOST_HID_STATE_WAITING_SET_REPORT,
	USB_HOST_HID_STATE_REPORT_DESCRIPTOR_GET,
	USB_HOST_HID_STATE_WAITING_REPORT_DESCRIPTOR_GET,
	USB_HOST_HID_STATE_REPORT_DESCRIPTOR_PARSE,
    USB_HOST_HID_STATE_READY,
    USB_HOST_HID_STATE_WAIT,
    USB_HOST_HID_STATE_INTERRUPT_IN_ENDPOINT_CLEAR,
    USB_HOST_HID_STATE_INTERRUPT_OUT_ENDPOINT_CLEAR

} USB_HOST_HID_TASK_STATE;


// *****************************************************************************
/* USB HOST HID driver Query types

  Summary:
    Identifies the different Query types.

  Description:
    These macros are useful to identify query type.

  Remarks:
    None.
 */

typedef enum
{
    USB_HOST_HID_QUERY_ERROR                      = 0,
    USB_HOST_HID_QUERY_USAGE                      = 1,
    USB_HOST_HID_QUERY_STRING,
    USB_HOST_HID_QUERY_DESIGNATOR

} USB_HOST_HID_QUERY_TYPE;

// *****************************************************************************
/*  USB Host HID Item Optional data information

  Summary:
    USB Host HID Item Optional data information

  Description:
    Union holds the item optional data information.
    Used during report descriptor parsing.
 
  Remarks:
    None.
*/

typedef union _USB_HOST_HID_ITEM_DATA_OPTIONAL_
{
    uint8_t unsignedData8; /* 1 byte unsigned data */
    int8_t  signedData8; /* 1 byte signed data */
    uint16_t unsignedData16; /* 2 bytes unsigned data */
    int16_t signedData16; /* 2 bytes signed data */
    uint32_t unsignedData32; /* 4 bytes unsigned data */
    int32_t signedData32; /* 4 bytes signed data */

}USB_HOST_HID_ITEM_DATA_OPTIONAL;

// *****************************************************************************
/*  USB Host HID Item information

  Summary:
    USB Host HID Item information

  Description:
    Structure holds the item information. Used during report descriptor parsing.
 
  Remarks:
    None.
*/

typedef struct _USB_HOST_HID_ITEM_
{
    /* Item optional data */
    USB_HOST_HID_ITEM_DATA_OPTIONAL optionalItemData;
    /* Item size */
    uint8_t size;
    /* Item type */
    uint8_t type;
    /* Item tag */
    uint8_t tag;

}USB_HOST_HID_ITEM;

// *****************************************************************************
/*  USB Host HID Handle information

  Summary:
    USB Host HID Handle information

  Description:
    Structure holds the information about the unique handle assigned
 
  Remarks:
    None.
*/

typedef struct _USB_HOST_HID_HANDLE_POOL_
{
    /* Structure is in use */
    bool inUse;    
    /* Usage driver registration table index that this usage belongs to. */
    int8_t usageInstanceIndex;
    /* Collection usage for the usage driver */
    uint32_t usage;
    /* Index of the HID client driver */
    USB_HOST_HID_INDEX  hidInstanceIndex;

} USB_HOST_HID_OBJECT_HANDLE_POOL;

// *****************************************************************************
/*  USB Host HID device information

  Summary:
    USB Host HID device information

  Description:
    USB Host HID device information

  Remarks:
    None.
*/

typedef struct _USB_HOST_HID_DEVICE_INFO_
{
    /* Determines if the HID device has BOOT interface */
    bool isBootInterfaceClass;
    /* Determines whether the attached device is Keyboard or mouse. This field
     is valid only if the device has boot interface */
    bool isKeyboardDevice;
    /* Country code of the attached device */
    uint8_t countryCode;
    
} USB_HOST_HID_DEVICE_INFO;

// *****************************************************************************
/* USB HOST HID Client Driver data structure

  Summary:
    USB HOST HID Client Driver information

  Description:
    This structure holds all information on per HID Client driver instance level.
    Contains information like driver state, pipe information with which this HID
    is interacting. Structure is used as part of enumeration and also during
    report descriptor parsing as part of usage driver query.

  Remarks:
    None.
 */

typedef struct
{
    /* use or not*/
    bool assigned;
    /* interface number owned by this instance */
    uint8_t bInterfaceNumber;
	/* Length of the report Descriptor in bytes */
	uint16_t reportDescLength;
    /* Holds the task routine state of this HID instance */
    USB_HOST_HID_TASK_STATE state;
    /* The HID Request object */
    USB_HOST_HID_REQUEST requestObj;
    /*Pipes for each endpoint */
    USB_HOST_PIPE_HANDLE controlPipeHandle;
    USB_HOST_PIPE_HANDLE interruptInPipeHandle[USB_HOST_HID_INTERRUPT_IN_ENDPOINTS_NUMBER];
    USB_HOST_PIPE_HANDLE interruptOutPipeHandle;
    /* Interrupt IN endpoint MaxPacketSize */
    uint8_t  interruptInEndpointSize[USB_HOST_HID_INTERRUPT_IN_ENDPOINTS_NUMBER];
	/* Interrupt OUT endpoint MaxPacketSize */
    uint8_t  interruptOutEndpointSize;
    /* Flag determines if HID has been attached */
    bool isHIDDriverAttached;
    /* Holds the collection nesting level value */
    uint8_t collectionNestingLevel;
    /* Flag determines if currently scanning for top level usages */
    bool topLevelUsageProcessing;
    /* Key repeat Delay */
    uint16_t hidKeyRepeatDelay;
    /* Device object handle */
    USB_HOST_DEVICE_OBJ_HANDLE deviceObjHandle;
    /* Interface object handle */    
    USB_HOST_DEVICE_INTERFACE_HANDLE interfaceHandle;
    /* Holds information about the device */
    USB_HOST_HID_DEVICE_INFO hidDeviceInfo;
	/* Report Descriptor Buffer Pointer */
	void *reportDescBuffer;
    /* Read buffer for Report through Interrupt endpoint */
    void * getReportInterruptBuffer;
    /* Write Buffer */
    void * outputReportData;
    /* Read buffer for Report through Control endpoint */
    void * getReportControlBuffer;
    /* Determines if field processing is ongoing for this HID instance */
    bool isFieldProcessing;
    /* Determines if there is any error in Device Report Descriptor */
    bool reportDescError;
    /* Number of top level usages that will be considered for this HID instance*/
    uint8_t nTopLevelUsages;
    /* Array of top level usages. */
    uint32_t topLevelUsages[USB_HOST_HID_USAGE_DRIVER_SUPPORT_NUMBER];
	/* Place holder for Main Item Data */
	USB_HOST_HID_MAIN_ITEM *mainItemData;
    /* Number of usage tags count */
	uint32_t usageTagsCount;
    /* Number of Designator index count */
    uint32_t designatorIndexCount;
    /* Number of String ID count */
    uint32_t stringDescriptorIndexCount;
    /* Number of elements that has been stacked in the global Stack */
	uint32_t globalStackIndex;
    /* Push-Pop stack */
	USB_HOST_HID_GLOBAL_ITEM globalStack[USB_HID_GLOBAL_PUSH_POP_STACK_SIZE];

} USB_HOST_HID_INSTANCE;

USB_HOST_HID_RESULT _USB_HOST_HID_ItemGet
(
    uint8_t hidInstanceIndex,
    uint8_t index,
    bool flag,
    uint32_t fieldIndex,
    uint32_t * buffer,
    USB_HOST_HID_QUERY_TYPE query
);
#endif

/********************** END OF FILE ***************************/