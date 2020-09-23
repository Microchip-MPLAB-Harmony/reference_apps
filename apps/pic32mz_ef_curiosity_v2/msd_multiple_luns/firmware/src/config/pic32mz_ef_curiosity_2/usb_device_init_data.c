/*******************************************************************************
  System Initialization File

  File Name:
    usb_device_init_data.c

  Summary:
    This file contains source code necessary to initialize the system.

  Description:
    This file contains source code necessary to initialize the system.  It
    implements the "SYS_Initialize" function, defines the configuration bits,
    and allocates any necessary global system resources,
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "configuration.h"
#include "definitions.h"
/**************************************************
 * USB Device Function Driver Init Data
 **************************************************/
	/***********************************************
 * Sector buffer needed by for the MSD LUN.
 ***********************************************/
uint8_t sectorBuffer[512 * USB_DEVICE_MSD_NUM_SECTOR_BUFFERS] USB_ALIGN;

/***********************************************
 * CBW and CSW structure needed by for the MSD
 * function driver instance.
 ***********************************************/
USB_MSD_CBW msdCBW0 USB_ALIGN;
USB_MSD_CSW msdCSW0 USB_ALIGN;
/***********************************************
 * Because the PIC32MZ flash row size if 2048
 * and the media sector size if 512 bytes, we
 * have to allocate a buffer of size 2048
 * to backup the row. A pointer to this row
 * is passed in the media initialization data
 * structure.
 ***********************************************/
uint8_t flashRowBackupBuffer [DRV_MEMORY_DEVICE_PROGRAM_SIZE] USB_ALIGN;


/*******************************************
 * MSD Function Driver initialization
 *******************************************/
USB_DEVICE_MSD_MEDIA_INIT_DATA USB_ALIGN  msdMediaInit0[2] =
{
    /* LUN 0 */ 
    {
        DRV_SDSPI_INDEX_0,
        512,
        sectorBuffer,
        flashRowBackupBuffer,
        0,
        {
            0x00,    // peripheral device is connected, direct access block device
            0x80,   // removable
            0x04,    // version = 00=> does not conform to any standard, 4=> SPC-2
            0x02,    // response is in format specified by SPC-2
            0x1F,    // additional length
            0x00,    // sccs etc.
            0x00,    // bque=1 and cmdque=0,indicates simple queueing 00 is obsolete,
                     // but as in case of other device, we are just using 00
            0x00,    // 00 obsolete, 0x80 for basic task queueing
            {
                'M','i','c','r','o','c','h','p'
            },
            {
                'M','a','s','s',' ','S','t','o','r','a','g','e',' ',' ',' ',' '
            },
            {
                '0','0','0','1'
            }
        },
        {
            DRV_SDSPI_IsAttached,
            DRV_SDSPI_Open,
            DRV_SDSPI_Close,
            DRV_SDSPI_GeometryGet,
            DRV_SDSPI_AsyncRead,
            DRV_SDSPI_AsyncWrite,
            DRV_SDSPI_IsWriteProtected,
            DRV_SDSPI_EventHandlerSet,
            NULL
        }
    },
    /* LUN 1 */ 
    {
        DRV_MEMORY_INDEX_0,
        512,
        sectorBuffer,
        flashRowBackupBuffer,
        0,
        {
            0x00,    // peripheral device is connected, direct access block device
            0x80,   // removable
            0x04,    // version = 00=> does not conform to any standard, 4=> SPC-2
            0x02,    // response is in format specified by SPC-2
            0x1F,    // additional length
            0x00,    // sccs etc.
            0x00,    // bque=1 and cmdque=0,indicates simple queueing 00 is obsolete,
                     // but as in case of other device, we are just using 00
            0x00,    // 00 obsolete, 0x80 for basic task queueing
            {
                'M','i','c','r','o','c','h','p'
            },
            {
                'M','a','s','s',' ','S','t','o','r','a','g','e',' ',' ',' ',' '
            },
            {
                '0','0','0','1'
            }
        },
        {
            DRV_MEMORY_IsAttached,
            DRV_MEMORY_Open,
            DRV_MEMORY_Close,
            DRV_MEMORY_GeometryGet,
            DRV_MEMORY_AsyncRead,
            DRV_MEMORY_AsyncEraseWrite,
            DRV_MEMORY_IsWriteProtected,
            DRV_MEMORY_TransferHandlerSet,
            NULL
        }
    },
};
  
/**************************************************
 * USB Device Function Driver Init Data
 **************************************************/
const USB_DEVICE_MSD_INIT msdInit0 =
{
    .numberOfLogicalUnits = 2,
    .msdCBW = &msdCBW0,
    .msdCSW = &msdCSW0,
    .mediaInit = &msdMediaInit0[0]
};


/**************************************************
 * USB Device Layer Function Driver Registration 
 * Table
 **************************************************/
const USB_DEVICE_FUNCTION_REGISTRATION_TABLE funcRegistrationTable[1] =
{
    
	/* MSD Function 0 */
    { 
        .configurationValue = 1,    /* Configuration value */ 
        .interfaceNumber = 0,       /* First interfaceNumber of this function */ 
        .speed = USB_SPEED_HIGH|USB_SPEED_FULL,    /* Function Speed */ 
        .numberOfInterfaces = 1,    /* Number of interfaces */
        .funcDriverIndex = 0,  /* Index of MSD Function Driver */
        .driver = (void*)USB_DEVICE_MSD_FUNCTION_DRIVER,    /* USB MSD function data exposed to device layer */
        .funcDriverInit = (void*)&msdInit0    /* Function driver init data */
    },



};

/*******************************************
 * USB Device Layer Descriptors
 *******************************************/
/*******************************************
 *  USB Device Descriptor 
 *******************************************/

const USB_DEVICE_DESCRIPTOR deviceDescriptor =
{
    0x12,                                                   // Size of this descriptor in bytes
    USB_DESCRIPTOR_DEVICE,                                  // DEVICE descriptor type
    0x0200,                                                 // USB Spec Release Number in BCD format
        0x00,                                    // Class Code
    0x00,                                    // Subclass code
    0x00,                                    // Protocol code


    USB_DEVICE_EP0_BUFFER_SIZE,                             // Max packet size for EP0, see configuration.h
    0x04D8,                                                 // Vendor ID
    0x0009,                                                 // Product ID				
    0x0100,                                                 // Device release number in BCD format
    0x01,                                                   // Manufacturer string index
    0x02,                                                   // Product string index
    0x03,                                                   // Device serial number string index
    0x01                                                    // Number of possible configurations
};

/*******************************************
 *  USB Device Qualifier Descriptor for this
 *  demo.
 *******************************************/
const USB_DEVICE_QUALIFIER deviceQualifierDescriptor1 =
{
    0x0A,                                                   // Size of this descriptor in bytes
    USB_DESCRIPTOR_DEVICE_QUALIFIER,                        // Device Qualifier Type
    0x0200,                                                 // USB Specification Release number
	    0x00,                                    // Class Code
    0x00,                                    // Subclass code
    0x00,                                    // Protocol code


    USB_DEVICE_EP0_BUFFER_SIZE,                             // Maximum packet size for endpoint 0
    0x01,                                                   // Number of possible configurations
    0x00                                                    // Reserved for future use.
};


/*******************************************
 *  USB High Speed Configuration Descriptor
 *******************************************/
 
const uint8_t highSpeedConfigurationDescriptor[]=
{
	/* Configuration Descriptor */

    0x09,                                                   // Size of this descriptor in bytes
    USB_DESCRIPTOR_CONFIGURATION,                           // Descriptor Type
    USB_DEVICE_16bitTo8bitArrange(32),                      //(32 Bytes)Size of the Configuration descriptor
    1,                                                      // Number of interfaces in this configuration
    0x01,                                               // Index value of this configuration
    0x00,                                               // Configuration string index
    USB_ATTRIBUTE_DEFAULT | USB_ATTRIBUTE_SELF_POWERED, // Attributes
    50,
	

		/* Descriptor for Function 1 - MSD     */ 
    
    /* Interface Descriptor */

    9,                              // Size of this descriptor in bytes
    USB_DESCRIPTOR_INTERFACE,       // INTERFACE descriptor type
    0,                              // Interface Number
    0,                              // Alternate Setting Number
    2,                              // Number of endpoints in this intf
    USB_MSD_CLASS_CODE,             // Class code
    USB_MSD_SUBCLASS_CODE_SCSI_TRANSPARENT_COMMAND_SET, // Subclass code
    USB_MSD_PROTOCOL,               // Protocol code
    0,                              // Interface string index

    /* Endpoint Descriptor */

    7,                          // Size of this descriptor in bytes
    USB_DESCRIPTOR_ENDPOINT,    // Endpoint Descriptor
    1  | USB_EP_DIRECTION_IN,    // EndpointAddress ( EP1 IN )
    USB_TRANSFER_TYPE_BULK,     // Attributes type of EP (BULK)
    0x00,0x02,                  // Max packet size of this EP
    0x00,                       // Interval (in ms)


    7,                          // Size of this descriptor in bytes
    USB_DESCRIPTOR_ENDPOINT,    // Endpoint Descriptor
    1  | USB_EP_DIRECTION_OUT,   // EndpointAddress ( EP2 OUT )
    USB_TRANSFER_TYPE_BULK,     // Attributes type of EP (BULK)
    0x00,0x02,                  // Max packet size of this EP
    0x00,                       // Interval (in ms)
    
    



};

/*******************************************
 * Array of High speed config descriptors
 *******************************************/
USB_DEVICE_CONFIGURATION_DESCRIPTORS_TABLE highSpeedConfigDescSet[1] =
{
    highSpeedConfigurationDescriptor
};

/*******************************************
 *  USB Full Speed Configuration Descriptor
 *******************************************/
const uint8_t fullSpeedConfigurationDescriptor[]=
{
	/* Configuration Descriptor */

    0x09,                                                   // Size of this descriptor in bytes
    USB_DESCRIPTOR_CONFIGURATION,                           // Descriptor Type
    USB_DEVICE_16bitTo8bitArrange(32),                      //(32 Bytes)Size of the Configuration descriptor
    1,                                                      // Number of interfaces in this configuration
    0x01,                                                   // Index value of this configuration
    0x00,                                                   // Configuration string index
    USB_ATTRIBUTE_DEFAULT | USB_ATTRIBUTE_SELF_POWERED, // Attributes
    50,
	
	/* Descriptor for Function 1 - MSD     */ 
    
    /* Interface Descriptor */

    9,                              // Size of this descriptor in bytes
    USB_DESCRIPTOR_INTERFACE,       // INTERFACE descriptor type
    0,                              // Interface Number
    0,                              // Alternate Setting Number
    2,                              // Number of endpoints in this intf
    USB_MSD_CLASS_CODE,             // Class code
    USB_MSD_SUBCLASS_CODE_SCSI_TRANSPARENT_COMMAND_SET, // Subclass code
    USB_MSD_PROTOCOL,               // Protocol code
    0,                              // Interface string index

    /* Endpoint Descriptor */

    7,                          // Size of this descriptor in bytes
    USB_DESCRIPTOR_ENDPOINT,    // Endpoint Descriptor
    1  | USB_EP_DIRECTION_IN,    // EndpointAddress ( EP1 IN )
    USB_TRANSFER_TYPE_BULK,     // Attributes type of EP (BULK)
    0x40,0x00,                  // Max packet size of this EP
    0x00,                       // Interval (in ms)


    7,                          // Size of this descriptor in bytes
    USB_DESCRIPTOR_ENDPOINT,    // Endpoint Descriptor
    1  | USB_EP_DIRECTION_OUT,   // EndpointAddress ( EP2 OUT )
    USB_TRANSFER_TYPE_BULK,     // Attributes type of EP (BULK)
    0x40,0x00,                  // Max packet size of this EP
    0x00,                       // Interval (in ms)


};

/*******************************************
 * Array of Full speed Configuration 
 * descriptors
 *******************************************/
USB_DEVICE_CONFIGURATION_DESCRIPTORS_TABLE fullSpeedConfigDescSet[1] =
{
    fullSpeedConfigurationDescriptor
};


/**************************************
 *  String descriptors.
 *************************************/
 /*******************************************
 *  Language code string descriptor
 *******************************************/
    const struct
    {
        uint8_t bLength;
        uint8_t bDscType;
        uint16_t string[1];
    }
    sd000 =
    {
        sizeof(sd000),                                      // Size of this descriptor in bytes
        USB_DESCRIPTOR_STRING,                              // STRING descriptor type
        {0x0409}                                            // Language ID
    };
/*******************************************
 *  Manufacturer string descriptor
 *******************************************/
    const struct
    {
        uint8_t bLength;                                    // Size of this descriptor in bytes
        uint8_t bDscType;                                   // STRING descriptor type
        uint16_t string[25];                                // String
    }
    sd001 =
    {
        sizeof(sd001),
        USB_DESCRIPTOR_STRING,
        {'M','i','c','r','o','c','h','i','p',' ','T','e','c','h','n','o','l','o','g','y',' ','I','n','c','.'}
		
    };

/*******************************************
 *  Product string descriptor
 *******************************************/
	const struct
    {
        uint8_t bLength;                                    // Size of this descriptor in bytes
        uint8_t bDscType;                                   // STRING descriptor type
        uint16_t string[21];                                // String
    }
    sd002 =
    {
        sizeof(sd002),
        USB_DESCRIPTOR_STRING,
		{'M','u','l','t','i','p','l','e',' ','L','U','N',' ','M','S','D',' ','D','e','m','o'}
    }; 
/******************************************************************************
 * Serial number string descriptor.  Note: This should be unique for each unit
 * built on the assembly line.  Plugging in two units simultaneously with the
 * same serial number into a single machine can cause problems.  Additionally,
 * not all hosts support all character values in the serial number string.  The
 * MSD Bulk Only Transport (BOT) specs v1.0 restrict the serial number to
 * consist only of ASCII characters "0" through "9" and capital letters "A"
 * through "F".
 ******************************************************************************/
    const struct
    {
        uint8_t bLength;                                    // Size of this descriptor in bytes
        uint8_t bDscType;                                   // STRING descriptor type
        uint16_t string[12];                                // String
    }
    serialNumberStringDescriptor =
    {
        sizeof(serialNumberStringDescriptor),
        USB_DESCRIPTOR_STRING,
        {'1','2','3','4','5','6','7','8','9','9','9','9'}
		
    };

/***************************************
 * Array of string descriptors
 ***************************************/
USB_DEVICE_STRING_DESCRIPTORS_TABLE stringDescriptors[4]=
{
    (const uint8_t *const)&sd000,
    (const uint8_t *const)&sd001,
    (const uint8_t *const)&sd002,
    (const uint8_t *const)&serialNumberStringDescriptor,
};

/*******************************************
 * USB Device Layer Master Descriptor Table 
 *******************************************/
 
const USB_DEVICE_MASTER_DESCRIPTOR usbMasterDescriptor =
{
    &deviceDescriptor,                                      // Full speed descriptor
    1,                                                      // Total number of full speed configurations available
    fullSpeedConfigDescSet,                                 // Pointer to array of full speed configurations descriptors
    &deviceDescriptor,                                      // High speed device descriptor
    1,                                                      // Total number of high speed configurations available
    highSpeedConfigDescSet,                                 // Pointer to array of high speed configurations descriptors
	4,  													// Total number of string descriptors available.
    stringDescriptors,                                      // Pointer to array of string descriptors.
    &deviceQualifierDescriptor1,                            // Pointer to full speed dev qualifier.
    &deviceQualifierDescriptor1                             // Pointer to high speed dev qualifier.
};


/****************************************************
 * USB Device Layer Initialization Data
 ****************************************************/

const USB_DEVICE_INIT usbDevInitData =
{
    /* Number of function drivers registered to this instance of the
       USB device layer */
    .registeredFuncCount = 1,
	
    /* Function driver table registered to this instance of the USB device layer*/
    .registeredFunctions = (USB_DEVICE_FUNCTION_REGISTRATION_TABLE*)funcRegistrationTable,

    /* Pointer to USB Descriptor structure */
    .usbMasterDescriptor = (USB_DEVICE_MASTER_DESCRIPTOR*)&usbMasterDescriptor,

    /* USB Device Speed */
    .deviceSpeed =  USB_SPEED_HIGH,   
	
	/* Index of the USB Driver to be used by this Device Layer Instance */
    .driverIndex = DRV_USBHS_INDEX_0,

    /* Pointer to the USB Driver Functions. */
    .usbDriverInterface = DRV_USBHS_DEVICE_INTERFACE,
	
};
// </editor-fold>
