/*******************************************************************************
  BM71 Bluetooth Static Driver implementation

  Company:
    Microchip Technology Inc.

  File Name:
    drv_bm71.h

  Summary:
    BM71 Bluetooth Static Driver main header file

  Description:
    This file is the header file for the external (public) API of the static 
    implementation of the BM71 driver.

    The BM71 is a Bluetooth 4.2 Stereo Module that supports classic A2DP, AVRCP,
    HFP, HSP, and SPP protocols as well as BLE (Bluetooth Low Energy).
    
    The BM71 streams I2S audio at up to 24-bit, 96 kHz.  It uses a UART to 
    receive commands from the host microcontroller (PIC32) and and send events
    back.
 
    All functions and constants in this file are named with the format
    DRV_BM71_xxx, where xxx is a function name or constant.  These names are
    redefined in the appropriate configuration?s system_config.h file to the
    format DRV_BT_xxx using #defines so that Bluetooth code in the application
    can be written as generically as possible (e.g. by writing DRV_BT_Open
    instead of DRV_BM71_Open etc.).

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2019 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
// DOM-IGNORE-END

#ifndef DRV_BM71_H
#define DRV_BM71_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>     // for typedef __SIZE_TYPE__ size_t needed in  osal_impl_basic.h
#include "system/system_module.h"
#include "driver/driver_common.h"
#include "configuration.h"
#include "osal/osal.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END 

// *****************************************************************************
// *****************************************************************************
// Section: Constants
// *****************************************************************************
// *****************************************************************************

#define DRV_BM71_MAXBDNAMESIZE    32            
    
// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

typedef enum 
{
    DRV_BM71_STATUS_NONE,
    DRV_BM71_STATUS_OFF,
    DRV_BM71_STATUS_ON,
    DRV_BM71_STATUS_READY
} DRV_BM71_DRVR_STATUS;         // BM64 driver status

typedef enum
{
    DRV_BM71_PROTOCOL_BLE = 16  // only protocol supported by BM71
} DRV_BM71_PROTOCOL;            // BM71 protocols

typedef enum 
{
    DRV_BM71_EVENT_NONE = 0,              
    DRV_BM71_EVENT_BLESPP_MSG_RECEIVED,
    DRV_BM71_EVENT_BLE_STATUS_CHANGED,
            
} DRV_BM71_EVENT;       // events that can be returned to a client via callback

typedef enum
{
    DRV_BM71_BLE_STATUS_STANDBY,
    DRV_BM71_BLE_STATUS_ADVERTISING,
    DRV_BM71_BLE_STATUS_SCANNING,
    DRV_BM71_BLE_STATUS_CONNECTED
} DRV_BM71_BLE_STATUS;

////////////////////////////////////////////// new //////////////////////////////

/** DEFINES  ******************************************************/
#define BLE_CCCD_UUID			0x2902
#define BLE_CCCD_NOTIFICATION_ENABLED	0x0001
#define BLE_CCCD_INDICATION_ENABLED		0x0002

#define BLE_ADDR_LEN			6

#define BM77_BLUETOOTH_DEVICE	0
#define BM78_BLUETOOTH_DEVICE	1
#define BM70_BLUETOOTH_DEVICE	2

#define BMXX_DEVICE (BM70_BLUETOOTH_DEVICE)

/* Advertisement parameter */
#define ADV_PARAM_INTERVAL_INDEX_HIGH		0
#define ADV_PARAM_INTERVAL_INDEX_LOW		1
#define ADV_PARAM_TYPE_INDEX				2
#define ADV_PARAM_DIRECT_ADDR_TYPE_INDEX	3
#define ADV_PARAM_DIRECT_ADDR_INDEX			4

/* Advertisement interval */
#define ADV_INTERVAL_1_S					1600	/* (1600 * 625 us) */
#define ADV_INTERVAL_100_MS					160

/* GAP Advertising interval max. and min. */
#define AT_BLE_ADV_INTERVAL_MIN        0x0020 /**< Minimum Advertising interval in 625 us units, i.e. 20 ms. */
#define AT_BLE_ADV_INTERVAL_MAX        0x4000 /**< Maximum Advertising interval in 625 us units, i.e. 10.24 s. */

/* Scan parameters */
#define MIN_SCAN_INTERVAL		0x0004
#define MAX_SCAN_INTERVAL		0x4000
#define MIN_SCAN_WINDOW			0x0004
#define MAX_SCAN_WINDOW			0x4000

/* Connection parameters */
#define MIN_CONN_INTERVAL		0x0006
#define MAX_CONN_INTERVAL		0x0C80
#define MIN_SLAVE_LATENCY		0x0000
#define MAX_SLAVE_LATENCY		0x01F4
#define MIN_SV_TIMEOUT			0x000A
#define MAX_SV_TIMEOUT			0x0C80

#define BLE_PAIR_CONFIRM_YES true
#define BLE_PAIR_CONFIRM_NO false

#define BLE_UUID_128B_LEN	(1 << BLE_UUID_128B)
#define BLE_UUID_16B_LEN	(1 << BLE_UUID_16B)

#define MAX_CHAR_WRITE_VALUE	20

/* BLE Attribute UUID lengths */
/**< 16-bit Bluetooth UUID. */
#define BLE_ATTRIB_UUID_LENGTH_2		2
/**< 32-bit Bluetooth UUID. */
#define BLE_ATTRIB_UUID_LENGTH_4		4
/**< 128-bit Bluetooth UUID. */
#define BLE_ATTRIB_UUID_LENGTH_16		16

/**< Characteristic properties */
#define BLE_CHAR_BROADCST				(0x01 << 0)
#define BLE_CHAR_READ					(0x01 << 1)
#define BLE_CHAR_WRITE_WITHOUT_RESPONSE (0x01 << 2)
#define BLE_CHAR_WRITE					(0x01 << 3)
#define BLE_CHAR_NOTIFY					(0x01 << 4)
#define BLE_CHAR_INDICATE				(0x01 << 5)
#define BLE_CHAR_SIGNED_WRITE			(0x01 << 6)
#define BLE_CHAR_EXT_PROPERTIES			(0x01 << 7)

/**< Characteristic extended properties */
#define BLE_CHAR_EXT_PROP_RELIABLE_WRITE	(0x0001 << 0)
#define BLE_CHAR_EXT_PROP_WRITABLE_AUX		(0x0001 << 1)

/* The following values inherited from BLEDK3. This needs to be updated whenever BLEDK3 update these values */

/**< Attribute Permissions. All attributes are readable as default. */
#define BLE_PM_WRITABLE					0x02	/**< Access Permission: Writeable.*/
#define BLE_PM_SECURITY_READ_ENABLE		0x04	/**< Encryption/Authentication Permission on READ property attribute. If enabled, it requires pairing to device to access the attribute. Note that Encryption or Authentication permission is based on IO capability of device. */
#define BLE_PM_SECURITY_WRITE_ENABLE	0x08	/**< Encryption/Authentication Permission on WRITE property attribute. If enabled, it requires pairing to device to access the attribute. Note that Encryption or Authentication permission is based on IO capability of device. */
#define BLE_PM_MANUAL_WRITE_RESP		0x40	/**< Authorization Permission: Manual sending write response configuration. Application can send write response manually. */
#define BLE_PM_MANUAL_READ_RESP			0x80	/**< Authorization Permission: Manual sending read response configuration. Application can send read response with data manually. */

#define BLE_ATT_ATTRIBUTE_VALUE_LEN			23		/**< The Maximum Length of Attribute Value. Refer to ATT default MTU size. */
#define BLE_ATT_DEFAULT_MTU_LENGTH			23		/**< ATT default MTU size. */

#define BLE_MAX_SERVICE_BUF_LEN    			0x01FF

/****************************************************************************************
*										Enumerations									*
****************************************************************************************/
/* BLE Host SDK status messages
*/
typedef enum 
{
	BLE_SUCCESS  = 0x00,
	BLE_UNKNOWN_COMMAND,
	BLE_UNKNOWN_CONNECTION_ID,
	BLE_HARDWARE_FAILURE,
	BLE_AUTHENTICATION_FAILURE = 0x05,
	BLE_PIN_KEY_MISSING,
	BLE_MEMORY_CAPACITY_EXCEEDED,
	BLE_CONNECTION_TIMEOUT,
	BLE_CONNECTION_LIMIT_EXCEEDED,
	BLE_ACL_CONNECTION_ALREADY_EXISTS = 0x0B,
	BLE_COMMAND_DISALLOWED,
	BLE_CONNECTION_REJECTED_DUE_TO_LIMITED_RESOURCES,
	BLE_CONNECTION_REJECTED_DUE_TO_SECURITY_REASONS,
	BLE_CONNECTION_REJECTED_DUE_TO_UNACCEPTABLE_BD_ADDR,
	BLE_CONNECTION_ACCEPT_TIMEOUT_EXCEEDED,
	BLE_UNSUPPORTED_FEATURE_OR_PARAMETER_VALUE,
	BLE_INVALID_COMMAND_PARAMETERS,
	BLE_REMOTE_USER_TERMINATED_CONNECTION,
	BLE_REMOTE_USER_TERMINATED_CONNECTION_DUE_TO_LOW_RESOURCES,
	BLE_REMOTE_USER_TERMINATED_CONNECTION_DUE_TO_POWER_OFF,
	BLE_CONNECTION_TERMINATED_BY_LOCAL_HOST,
	BLE_PAIRING_NOT_ALLOWED = 0x18,
	BLE_UNSPECIFIED_ERROR = 0x1F,
	BLE_INSTANT_PASSED = 0x28,
	BLE_PAIRING_WITH_UINT_KEY_NOT_SUPPORTED = 0x29,
	BLE_INSUFFICIENT_SECURITY = 0x2F,
	BLE_CONNECTION_REJECTED_DUE_TO_NO_SUITABLE_CHANNEL_FOUND = 0x39,
	BLE_CONTROLLER_BUSY,
	BLE_UNACCEPTABLE_CONNECTION_INTERVAL,
	BLE_DIRECTED_ADVERTISING_TIMEOUT,
	BLE_CONNECTION_TERMINATED_DUE_TO_MIC_FAILURE,
	BLE_CONNECTION_FAILED_TO_BE_ESTABLISHED,
	BLE_INVALID_HANDLE = 0x81,
	BLE_READ_NOT_PERMITTED,
	BLE_WRITE_NOT_PERMITTED,
	BLE_INVALID_PDU,
	BLE_INSUFFICIENT_AUTHENTICATION,
	BLE_REQUEST_NOT_SUPPORTED,
	BLE_INVALID_OFFSET,
	BLE_INSUFFICIENT_AUTHORIZATION = 0x88,
	BLE_PREPARE_QUEUE_FULL,
	BLE_ATTRIBUTE_NOT_FOUND,
	BLE_ATTRIBUTE_NOT_LONG,
	BLE_INSUFFICIENT_ENCRYPTION_KEY_SIZE,
	BLE_INVALID_ATTRIBUTE_VALUE_LENGTH,
	BLE_UNLIKELY_ERROR,
	BLE_INSUFFICIENT_ENCRYPTION,
	BLE_UNSUPPORTED_GROUT_TYPE,
	BLE_INSUFFICIENT_RESOURCES,
	BLE_APPLICATION_DEFINED_ERROR = 0xF0,
	BLE_FAILURE,
	BLE_UART_TIMEOUT,
	BLE_UART_CRC_ERROR = 0xFF,
} ble_status_t;

/* Advertising Types
*/
typedef enum
{
	BLE_ADV_TYPE_UNDIRECTED    = 0x00,   /**< Connectable undirected. */
	BLE_ADV_TYPE_DIRECTED,               /**< Connectable high duty cycle directed advertising. */
	BLE_ADV_TYPE_SCANNABLE_UNDIRECTED,   /**< Scannable undirected. */
	BLE_ADV_TYPE_NONCONN_UNDIRECTED,     /**< Non connectable undirected. */
	BLE_ADV_TYPE_DIRECTED_LDC,           /**< Connectable low duty cycle directed advertising. */
	BLE_ADV_TYPE_SCAN_RESPONSE           /** only used in @ref BLE_SCAN_INFO event to signify a scan response*/
} ble_adv_type_t;

/* Advertising Mode
*/
typedef enum
{
	/* Mode in non-discoverable */
	BLE_ADV_NON_DISCOVERABLE,
	/* Mode in general discoverable, AD type general flag in Flags set to 1. */
	BLE_ADV_GEN_DISCOVERABLE,
	/* Mode in limited discoverable, AD type limited flag in Flags set to 1 (This mode is automatically stopped after 180 sec of activity) */
	BLE_ADV_LIM_DISCOVERABLE,
	/* Broadcaster mode which is a non discoverable and non connectable mode. */
	BLE_ADV_BROADCASTER_MODE
} ble_adv_mode_t;

/* BLE can accept to kinds of addresses, either public or random addresses
*/
typedef enum
{
	/** a public static address */
	BLE_ADDRESS_PUBLIC,
	/** a random static address */
	BLE_ADDRESS_RANDOM_STATIC,
	/** resolvable private random address */
	BLE_ADDRESS_RANDOM_PRIVATE_RESOLVABLE,
	/** non-resolvable private random address */
	BLE_ADDRESS_RANDOM_PRIVATE_NON_RESOLVABLE ,

} ble_addr_type_t;

/* Event Types
*/
typedef enum
{
	GAP_EVENT_HANDLERS,
	GATT_SERVER_EVENT_HANDLERS,
	GATT_CLIENT_EVENT_HANDLERS,
	COMMON_EVENT_HANDLERS,
	TRANSPARENT_EVENT_HANDLERS
}ble_event_types_t;

/* BLEDK3 events
*/
enum
{
	PASSKEY_ENTRY_REQ			= 0x60,
	PAIRING_COMPLETE,
	PASSKEY_CONFIRM_REQ,
	ADV_REPORT					= 0x70,
	CONNECTION_COMPLETE,
	DISCONNECTION_COMPLETE,
	CONN_PARAM_UPDATE_NOTIFY,
	COMMAND_COMPLETE			= 0x80,
	STATUS_REPORT,
	CONFIG_MODE_STATUS,
	DISCOVER_ALL_PRIMARY_SERVICE_RESP = 0x90,
	DISCOVER_SPECIFIC_PRIMARY_SERVICE_CHAR_RESP,
	DISCOVER_ALL_CHAR_DESCRIPTOR_RESP,
	CHAR_VALUE_RECEIVED,
	CLIENT_WRITE_CHAR_VALUE		= 0x98,
	RECEIVED_TRANSPARENT_DATA	= 0x9A,
};

/* BLEDK3 status
*/
typedef enum
{
	SCANNING_MODE = 0x01,
	CONNECTING_MODE,
	STANDBY_MODE,
	BROADCAST_MODE = 0x05,
	TRANSPARENT_SERVICE_ENABLED_MODE = 0x08,
	IDLE_MODE,
	SHUTDOWN_MODE,
	CONFIGURE_MODE,
	BLE_CONNECTED_MODE,
} bledk3_status_t;

/* Scan types used at ble_scan_param_set
*/
typedef enum
{
	/* No SCAN_REQ packets shall be sent */
	BLE_SCAN_PASSIVE,
	/* SCAN_REQ packets may be sent */
	BLE_SCAN_ACTIVE
} ble_scan_type_t;

/* Scan enable used at ble_scan_start
*/
typedef enum
{
	BLE_SCAN_DISABLED,
	BLE_SCAN_ENABLED,
} ble_scan_enable_t;

/* Scan filter duplicate used at ble_scan_start
*/
typedef enum
{
	BLE_SCAN_DUPLICATE_FILTER_DISABLED,
	BLE_SCAN_DUPLICATE_FILTER_ENABLED,
} ble_scan_duplicate_filter_t;

/* Connection filter used at ble_create_connection
*/
typedef enum
{
	BLE_CONN_WHITELIST_FILTER_DISABLED,
	BLE_CONN_WHITELIST_FILTER_ENABLED,
} ble_connection_filter_t;

/* BLEDK3 advertisement event type used at ble_adv_report_event_t
*/
typedef enum
{
	ADV_IND,
	ADV_DIRECT_IND,
	ADV_SCAN_IND,
	ADV_NONCONN_IND,
	SCAN_RESP,
} ble_adv_event_type_t;

typedef enum
{
	CONFIG_MODE_DISABLED,
	CONFIG_MODE_ENABLED,
} ble_config_mode_status_t;

typedef enum
{
	BLE_UUID_16B = 1,
	BLE_UUID_128B = 4,
	BLE_UUID_INVALID
} ble_uuid_type_t;

/* GATT UUIDs defined by SIG
*/
typedef enum
{
/**< Primary Service Declaration.*/
UUID_PRIMARY_SERVICE = 0x2800,
/**< Secondary Service Declaration.*/
UUID_SECONDARY_SERVICE,
/**< Include Declaration.*/
UUID_INCLUDE,
/**< Characteristic Declaration.*/
UUID_CHARACTERISTIC
}ble_public_uuids_t;

/* GATT Descriptor UUID defined by SIG
*/
typedef enum
{
	CHAR_EXTENDED_PROPERTIES = 0x2900,
	CHAR_USER_DESCRIPTION,
	CLIENT_CHAR_CONFIGURATION,
	SERVER_CHAR_CONFIGURATION,
	CHAR_PRESENTATION_FORMAT,
	CHAR_AGGREGATE_FORMAT,
	VALID_RANGE,
	EXTERNAL_REPORT_REFERENCE,
	REPORT_REFERENCE,
	NUMBER_OF_DIGITALS,
	VALUE_TRIGGER_SETTING,
	ENVIRONMENTAL_SENSING_CONFIGURATION,
	ENVIRONMENTAL_SENSING_MEASUREMENT,
	ENVIRONMENTAL_SENSING_TRIGGER_SETTING,
	TIME_TRIGGER_SETTING
} gatt_descriptors_uuid_t;

/* Characteristic presentation format used at ble_char_presentation_format_t
*/
typedef enum
{
	BLE_PRES_FORMAT_BOOLEAN = 0x01,
	BLE_PRES_FORMAT_2BIT = 0x02,
	BLE_PRES_FORMAT_NIBBLE = 0x03,
	BLE_PRES_FORMAT_UINT8 = 0x04,
	BLE_PRES_FORMAT_UINT12 = 0x05,
	BLE_PRES_FORMAT_UINT16 = 0x06,
	BLE_PRES_FORMAT_UINT24 = 0x07,
	BLE_PRES_FORMAT_UINT32 = 0x08,
	BLE_PRES_FORMAT_UINT48 = 0x09,
	BLE_PRES_FORMAT_UINT64 = 0x0A,
	BLE_PRES_FORMAT_UINT128 = 0x0B,
	BLE_PRES_FORMAT_SINT8 = 0x0C,
	BLE_PRES_FORMAT_SINT12 = 0x0D,
	BLE_PRES_FORMAT_SINT16 = 0x0E,
	BLE_PRES_FORMAT_SINT24 = 0x0F,
	BLE_PRES_FORMAT_SINT32 = 0x10,
	BLE_PRES_FORMAT_SINT48 = 0x11,
	BLE_PRES_FORMAT_SINT64 = 0x12,
	BLE_PRES_FORMAT_SINT128 = 0x13,
	BLE_PRES_FORMAT_FLOAT32 = 0x14,
	BLE_PRES_FORMAT_FLOAT64 = 0x15,
	BLE_PRES_FORMAT_SFLOAT = 0x16,
	BLE_PRES_FORMAT_FLOAT = 0x17,
	BLE_PRES_FORMAT_DUINT16 = 0x18,
	BLE_PRES_FORMAT_UTF8S = 0x19,
	BLE_PRES_FORMAT_UTF16S = 0x1A,
	BLE_PRES_FORMAT_STRUCT = 0x1B,
} ble_char_pres_format_t;

/* Characteristic extended properties used at ble_char_ext_properties_t
*/
typedef enum
{
	BLE_EXT_PROP_RELIABLE_WRITE = 0x0001,
	BLE_EXT_PROP_WRITABLE_AUX,
} ble_char_ext_prop_t;

/* Service type used at ble_service_t
*/
typedef enum
{
	SECONDARY_SERVICE,
	PRIMARY_SERVICE
} ble_service_type_t;

/* BLE advertisement data types. */
typedef enum Advertisement_Data_Type
{
	ADV_FLAGS = 0x01,
	ADV_INCOMPLETE_128B_SERVICE_UUIDS = 0x06,
	ADV_COMPLETE_128B_SERVICE_UUIDS,
	ADV_SHORT_NAME,
	ADV_COMPLETE_NAME,
	ADV_TX_POWER_LEVEL,
	ADV_CLASS_OF_DEVICE = 0x0D,
	ADV_SERVICE_DATA = 0x16,
	ADV_ADVERTISING_INTERVAL = 0x1A,
	ADV_MANUFATURER_SPECIFIC_DATA = 0xFF,
} ble_mgr_adv_data_type;

/////////////////////////////////////////////////////////////////////////////////

// prototype for callback for DRV_BM71_EventHandlerSet
typedef void (*DRV_BM71_EVENT_HANDLER) (DRV_BM71_EVENT event, uint32_t param, uintptr_t contextHandle);

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function DRV_BM71_Initialize:

        void DRV_BM71_Initialize( void );

  Summary:
    Initializes hardware and data for the instance of the BM71 Bluetooth module

  Description:
    This routine initializes the BM71 driver instance for the specified driver
    index, making it ready for clients to open and use it. The initialization
    data is specified by the init parameter. The initialization may fail if the
    number of driver objects allocated are insufficient or if the specified
    driver instance is already initialized.
 
  Precondition:
    None.

  Parameters:
    None. 

  Returns:
    None.

  Example:
    <code>
    // (in SYS_Initialize, system_init.c)* 
 
 	DRV_BM71_Initialize(); 
    </code>

  Remarks:
    This routine must be called before any other BM71 driver routine is called.
    This routine should only be called once during system initialization.
    This routine will never block for hardware access.

*/

void DRV_BM71_Initialize( void );

// *****************************************************************************
/* Function DRV_BM71_Tasks:
 
        void  DRV_BM71_Tasks( void );

  Summary:
    Maintains the driver's control and data interface state machine.

  Description:
    This routine is used to maintain the driver's internal control and data
    interface state machine and implement its control and data interface
    implementations.  
 
    This function should be called from the SYS_Tasks() function.
  
  Precondition:
    None.

  Parameters:
    None. 

  Returns:
    None.

  Example:
    <code>
    // (in SYS_Tasks, system_tasks.c)
 
    // Maintain Device Drivers
	DRV_BM71_Tasks(); 
    </code>

  Remarks:
    This routine is not normally called directly by an application.  Instead it
    is called by the system's Tasks routine (SYS_Tasks).
*/

void DRV_BM71_Tasks( void );

// *****************************************************************************
/* Function DRV_BM71_Status:
 
        SYS_STATUS DRV_BM71_Status( void );

  Summary:
    Gets the current system status of the BM71 Bluetooth driver module.

  Description:
    This routine provides the current status of the BM71 Bluetooth driver module,
    passed back as type SYS_STATUS.
 
  Precondition:
    None.

  Parameters:
    None. 

  Returns:
    Driver status, encoded as type SYS_STATUS enum:

    SYS_STATUS_DEINITIALIZED  - Indicates that the driver has been
                                deinitialized
    SYS_STATUS_READY          - Indicates that any previous module operation
                                for the specified module has completed
    SYS_STATUS_BUSY           - Indicates that a previous module operation for
                                the specified module has not yet completed
    SYS_STATUS_ERROR          - Indicates that the specified module is in an
                                error state
 * 
  Example:
    <code>
 * // note generic version of call (DRV_BT instead of DRV_BM71) is used
    if (SYS_STATUS_READY == DRV_BT_Status())
    {
        // This means the driver can be opened using the
        // DRV_BT_Open() function.
    }
    </code> 

  Remarks:
    A driver can opened only when its status is SYS_STATUS_READY.
*/

SYS_STATUS DRV_BM71_Status( void );

// *****************************************************************************
/* Function DRV_BM71_GetPowerStatus:

        DRV_BM71_DRVR_STATUS DRV_BM71_GetPowerStatus( void );

  Summary:
    Gets the current status of the BM71 Bluetooth driver module (BM71-specific).

  Description:
    This routine provides the current status (power on/off/ready) of the BM71
    Bluetooth driver module passed back as type DRV_BM71_DRVR_STATUS enum.

  Precondition:
    DRV_BM71_Initialize must have been called to initialize the driver instance.

  Parameters:
    None. 

  Returns:
    Driver status, encoded as type DRV_BM71_DRVR_STATUS enum.

  Example:
    <code>    
    case APP_STATE_WAIT_INIT:
    {
       // note generic version of call (DRV_BT instead of DRV_BM71) is used
       if (DRV_BT_STATUS_READY == DRV_BT_GetPowerStatus())
       {           
           appData.state=APP_STATE_IDLE;
           // start can processing audio
       }
    }
    break;
    </code>

  Remarks:
    A status of DRV_BT_STATUS_READY means the drivers state machine has finished
    initialization and is ready to stream audio.
*/

DRV_BM71_DRVR_STATUS DRV_BM71_GetPowerStatus( void );

// *****************************************************************************
/* Function DRV_BM71_TaskReq:

        void DRV_BM71_TaskReq(DRV_BM71_REQUEST request);

  Summary:
    Make a power on/power off task request.

  Description:
    Make a power on/power off task request using the DRV_BM71_REQUEST enum.
  
  Precondition:
    DRV_BM71_Initialize must have been called to initialize the driver instance.

  Parameters:
    request        - power on/off request of type DRV_BM71_REQUEST

  Returns:
    None.

  Example:
    <code>
    // note generic version of call (DRV_BT instead of DRV_BM71) is used
    DRV_BT_TaskReq(DRV_BM71_REQ_SYSTEM_ON);
    </code>

  Remarks:
    None.
*/

//void DRV_BM71_TaskReq(DRV_BM71_REQUEST request);

// *****************************************************************************
/* Function DRV_BM71_Open: 

        DRV_HANDLE DRV_BM71_Open(const DRV_IO_INTENT ioIntent,
                          const DRV_BM71_PROTOCOL protocol);

  Summary:
    Open the specified BM71 driver instance and returns a handle to it

  Description:
    This routine opens the specified BM71 Bluetooth driver instance and provides
    a handle that must be provided to all other client-level operations to
    identify the caller and the instance of the driver. The ioIntent
    parameter defines how the client interacts with this driver instance.

    Only DRV_IO_INTENT_READ is a valid ioIntent option as the BM71 Bluetooth
    driver audio stream is read-only.

    Specifying a DRV_IO_INTENT_EXCLUSIVE will cause the driver to provide
    exclusive access to this client. The driver cannot be opened by any
    other client.
  
  Precondition:
    DRV_BM71_Initialize must have been called to initialize the driver instance.

  Parameters:
    ioIntent        - valid handle to an opened BM71 device driver unique to client
    protocol        - specifies which protocol(s) the client intends to use
                      with this driver.  One of the various DRV_BM71_PROTOCOL 
                      enum values, including DRV_BM71_PROTOCOL_ALL.

  Returns:
    valid handle to an opened BM71 device driver unique to client

  Example:
    <code>
    case APP_STATE_OPEN:
    {
        if (SYS_STATUS_READY == DRV_BT_Status())
        { 
            // open BT module, including RX audio stream
            // note generic version of call (DRV_BT instead of DRV_BM71) is used
            appData.bt.handle = DRV_BT_Open(DRV_IO_INTENT_READ, DRV_BT_PROTOCOL_ALL);

            if(appData.bt.handle != DRV_HANDLE_INVALID)
            {
                appData.state = APP_STATE_SET_BT_BUFFER_HANDLER;
            }
            else
            {
                // Got an Invalid Handle.  Wait for BT module to Initialize
            }
        }
    }
    break;
    </code>

  Remarks:
    The handle returned is valid until the DRV_BM71_Close routine is called.
    This routine will never block waiting for hardware.  If the requested intent
    flags are not supported, the routine will return DRV_HANDLE_INVALID.  This
    function is thread safe in a RTOS application. It should not be called in an
    ISR.
 
    Currently only one client is allowed at a time.
*/

DRV_HANDLE DRV_BM71_Open(const DRV_IO_INTENT ioIntent, const DRV_BM71_PROTOCOL protocol);

// *****************************************************************************
/* Function DRV_BM71_Close: 

        void DRV_BM71_Close(DRV_HANDLE handle);

  Summary:
    Close an opened-instance of the BM71 Bluetooth driver.

  Description:
    This routine closes an opened-instance of the BM71 driver, invalidating the
    handle. Any buffers in the driver queue that were submitted by this client
    will be removed.  After calling this routine, the handle passed in "handle"
    must not be used with any of the remaining driver routines.  A new handle must
    be obtained by calling DRV_BM71_Open before the caller may use the driver
    again
 
  Precondition:
    DRV_BM71_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle          - valid handle to an opened BM71 device driver unique to client

  Returns:
    None.
 
   Example:
    <code>
    // note generic version of call (DRV_BT instead of DRV_BM71) is used
    DRV_BT_Close(appData.bt.handle);
    </code>* 

  Remarks:
    Usually there is no need for the driver client to verify that the Close
    operation has completed.  The driver will abort any ongoing operations
    when this routine is called.
*/

void DRV_BM71_Close(const DRV_HANDLE handle);

// *****************************************************************************
/* Function DRV_BM71_EventHandlerSet:

        void DRV_BM71_EventHandlerSet(DRV_HANDLE handle,
            const DRV_BM71_EVENT_HANDLER eventHandler,
            const uintptr_t contextHandle);

  Summary:
    This function allows a client to identify an event handling function
    for the driver to call back.

  Description:
    This function allows a client to identify a command event handling function
    for the driver to call back when an event has been received from the BM71.
 
   The context parameter contains a handle to the client context,
    provided at the time the event handling function is registered using the
    DRV_BM71_BufferEventHandlerSet function.  This context handle value is
    passed back to the client as the "context" parameter.  It can be any value
    necessary to identify the client context or instance (such as a pointer to
    the client's data) instance of the client.* 

    The event handler should be set before the client performs any "BM71 Bluetooth
    Specific Client Routines" operations that could generate events.
    The event handler once set, persists until the client closes the driver or
    sets another event handler (which could be a "NULL" pointer to indicate no callback).
 
  Precondition:
    DRV_BM71_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle          - valid handle to an opened BM71 device driver unique to client
    eventHandler    - pointer to a function to be called back (prototype defined
                      by DRV_BM71_EVENT_HANDLER)
    contextHandle   - handle to the client context

  Returns:
    None.

  Example:
    <code>
    case APP_STATE_SET_BT_BUFFER_HANDLER:
    {
        DRV_BT_BufferEventHandlerSet(appData.bt.handle,
                                      appData.bt.bufferHandler,
                                      appData.bt.context); 

        // note generic version of call (DRV_BT instead of DRV_BM71) is used
        DRV_BT_EventHandlerSet(appData.bt.handle,
                                      appData.bt.eventHandler,
                                      (uintptr_t)0);                                  

        appData.state = APP_STATE_CODEC_OPEN;            
    }
    break; 
    </code>

  Remarks:
    If the client does not want to be notified when an event has occurred, it
    does not need to register a callback.
*/

void DRV_BM71_EventHandlerSet(DRV_HANDLE handle,
        const DRV_BM71_EVENT_HANDLER eventHandler, const uintptr_t contextHandle);

// *****************************************************************************
/* Function DRV_BM71_ClearBLEData:

        void DRV_BM71_ClearBLEData( const DRV_HANDLE handle );

  Summary:
    Clear the BLE receive buffer.

  Description:
    Clears the buffer used when receiving characters via the 
    DRV_BM71_ReadByteFromBLE and DRV_BM71_ReadDataFromBLE calls.
 
  Precondition:
    DRV_BM71_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle      - valid handle to an opened BM71 device driver unique to client

  Returns:
    None.

  Example:
    <code>
    uint8_t byte;
    
    // note generic versions of calls (DRV_BT instead of DRV_BM71) is used
    DRV_BT_ClearBLEData(appData.bt.handle);

    // wait for byte to arrive
    while (!DRV_BT_ReadByteFromBLE(appData.bt.handle, &byte))
    {
        // should have some sort of way to break out of here if byte never arrives
    }
    </code>

  Remarks:
 None.
*/

void DRV_BM71_ClearBLEData( const DRV_HANDLE handle );

// *****************************************************************************
/* Function DRV_BM71_ReadByteFromBLE:

        bool DRV_BM71_ReadByteFromBLE(const DRV_HANDLE handle, uint8_t* byte);

  Summary:
    Read a byte over BLE.

  Description:
    Read one byte over BLE using the BM71's "Transparent Service" feature.
 
  Precondition:
    DRV_BM71_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle      - valid handle to an opened BM71 device driver unique to client
    byte        - pointer to a uint8_t to receive the data

  Returns:
    bool        - true if a byte was returned, false if receive buffer empty

  Example:
    <code>
    uint8_t byte;
 
    // note generic version of call (DRV_BT instead of DRV_BM71) is used
    if (DRV_BT_ReadByteFromBLE(appData.bt.handle, &byte))  // if byte received
    {
        // do something
    } 
    </code>

  Remarks:
    None.
*/

bool DRV_BM71_ReadByteFromBLE(const DRV_HANDLE handle, uint8_t* byte);

// *****************************************************************************
/* Function DRV_BM71_ReadDataFromBLE:

        bool DRV_BM71_ReadDataFromBLE(const DRV_HANDLE handle, uint8_t* bytes, 
                uint16_t size );

  Summary:
    Read data over BLE.

  Description:
    Read data over BLE using the BM71's "Transparent Service" feature.
 
  Precondition:
    DRV_BM71_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle      - valid handle to an opened BM71 device driver unique to client
    bytes       - pointer to a uint8_t buffer at least size bytes long
    size        - length of buffer (including

  Returns:
    bool        - true if data was returned, false if receive buffer empty

  Example:
    <code>
    #define BUFSIZE  100
    uint8_t buf [BUFSIZE];

    // note generic version of call (DRV_BT instead of DRV_BM71) is used
    if (DRV_BT_ReadDataFromBLE(appData.bt.handle, buf, BUFSIZE))  // if data received
    {
        // do something
    } 
    </code>

  Remarks:
    No more than size bytes will be returned, even if more are available.
*/

bool DRV_BM71_ReadDataFromBLE(const DRV_HANDLE handle, uint8_t* byte, uint16_t size );

// *****************************************************************************
/* Function DRV_BM71_SendByteOverBLE:

        void DRV_BM71_SendByteOverBLE(const DRV_HANDLE handle, uint8_t byte); 

  Summary:
    Send a byte over BLE.

  Description:
    Send one byte over BLE using the BM71's "Transparent Service" feature.
 
  Precondition:
    DRV_BM71_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle      - valid handle to an opened BM71 device driver unique to client
    byte        - uint8_t of data to be sent

  Returns:
    None.

  Example:
    <code>
    uint8_t byte;
 
    byte = 10;     // set to some value

    // note generic version of call (DRV_BT instead of DRV_BM71) is used
    DRV_BT_SendByteOverBLE(appData.bt.handle, byte);
    </code>

  Remarks:
    None.
*/

void DRV_BM71_SendByteOverBLE(const DRV_HANDLE handle, uint8_t byte);

// *****************************************************************************
/* Function DRV_BM71_SendDataOverBLE:

        void DRV_BM71_SendDataOverBLE(const DRV_HANDLE handle, uint8_t* bytes,
                uint16_t size);

  Summary:
    Send data over BLE.

  Description:
    Send data over BLE using the BM71's "Transparent Service" feature.
 
  Precondition:
    DRV_BM71_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle      - valid handle to an opened BM71 device driver unique to client
    bytes       - pointer to a uint8_t buffer at least size bytes long
    size        - length of buffer (including

  Returns:
    None.

  Example:
    <code>
    #define BUFSIZE    100
    uint8_t buf [BUFSIZE];
 
    // (code to fill in buffer with data)

    // note generic version of call (DRV_BT instead of DRV_BM71) is used
    DRV_BT_SendDataOverBLE(appData.bt.handle, buf, BUFSIZE);
    </code>

  Remarks:
    None.
*/

void DRV_BM71_SendDataOverBLE(const DRV_HANDLE handle, uint8_t* bytes, uint16_t size);

// *****************************************************************************
/* Function DRV_BM71_BLE_QueryStatus:

        void DRV_BM71_BLE_QueryStatus(const DRV_HANDLE handle);

  Summary:
    Query BM71 LE status.

  Description:
    Queries the BM71 to respond with a DRV_BM71_EVENT_BLE_STATUS_CHANGED event,
    which will indicate if the BM71 BLE status is standby, advertising,
    scanning or connected.

  Precondition:
    DRV_BM71_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle      - valid handle to an opened BM71 device driver unique to client

  Returns:
    None.

  Example:
    <code>
    // note generic version of call (DRV_BT instead of DRV_BM71) is used
    DRV_BT_BLE_QueryStatus(appData.bt.handle);
 
    . . .
 
    // later, a call will come back to the event handler callback function
    // (previously set up via a call to DRV_BM71_EventHandlerSet)
    static void _BLEEventHandler(DRV_BT_EVENT event, uint32_t param, uintptr_t context)
    {
        switch(event)
        {
            case DRV_BT_EVENT_BLE_STATUS_CHANGED:
            {           
                // do case switch based on param variable
            }
       }
    }    
    </code>

  Remarks:
    RV_BM71_BLE_QueryStatus is non-blocking; it returns right away and sometime
    later (perhaps tens or hundreds of ms) the event handler callback will be
    called.
*/

void DRV_BM71_BLE_QueryStatus(const DRV_HANDLE handle);

// *****************************************************************************
/* Function DRV_BM71_BLE_EnableAdvertising:

        void DRV_BM71_BLE_EnableAdvertising(const DRV_HANDLE handle, bool enable);

  Summary:
    Enable or disable advertising.

  Description:
    Enable or disable BLE advertising.
 
  Precondition:
    DRV_BM71_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle      - valid handle to an opened BM71 device driver unique to client
    enable      - true to enable advertising, false to disable advertising

  Returns:
    None.

  Example:
    <code>
    // note generic version of call (DRV_BT instead of DRV_BM71) is used
    DRV_BM71_BLE_EnableAdvertising(appData.bt.handle, true);
    </code>

  Remarks:
    None.
*/

void DRV_BM71_BLE_EnableAdvertising(const DRV_HANDLE handle, bool enable);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif
