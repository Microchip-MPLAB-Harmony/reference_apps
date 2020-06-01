/*******************************************************************************
  BM71 Bluetooth Static Driver implementation

  Company:
    Microchip Technology Inc.

  File Name:
    drv_bm71_local.h

  Summary:
   BM71 Bluetooth Static Driver header file for local data.

  Description:
    This file is the header file for the local definitions and data declarations
    that are local to the the BM71 driver (not exposed to the client).
 
*******************************************************************************/

/******************************************************************************
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
********************************************************************/
#ifndef DRV_BM71_LOCAL_H
#define DRV_BM71_LOCAL_H

//#include <stdbool.h>
//#include <stdint.h>

#include "driver/driver_common.h"
#include "configuration.h"
#include "bt/driver/bm71/drv_bm71.h"

/**********************************************
 * Driver Client Obj
 **********************************************/

typedef enum 
{
    DRV_BM71_STATE_INITIALIZE_START = 0,
    DRV_BM71_STATE_INIT_RESET_HIGH,
    DRV_BM71_STATE_INIT_RESET_HIGH_WAIT,
    DRV_BM71_STATE_INIT_BLE_ADV_START,
    DRV_BM71_STATE_SET_BLE_ADV_PARAM,
    DRV_BM71_STATE_SET_BLE_ADV_ENABLE,
    DRV_BM71_STATE_BLE_ADV_WAIT,
    DRV_BM71_STATE_BLE_CONNECTED,
    DRV_BM71_STATE_BLE_TRANSPARENT_MODE,
    DRV_BM71_STATE_BLE_DISCONNECTED,
    DRV_BM71_STATE_BLE_DISCONNECTED_WAIT,
} DRV_BM71_TASKSTATE;   // Bluetooth task state define

typedef union
{
    uint16_t value;
    struct {
        uint16_t linkbackToDevAddr           : 1;     
        uint16_t SPPLinkBackReq              : 1;
        uint16_t DisconnectAllLinksReq       : 1;        //was MMI/DISCONNECT_ALL_LINK
        uint16_t LinkLastDeviceReq           : 1;        //was MMI/LINK_BACK_DEVICE         
    };
} DRV_BM71_NEXTCOMMANDREQ;

// *****************************************************************************
/* BM71 Driver Global Instances Object

  Summary:
    Object used to keep track of data that is common to all instances of the
    BM71 Bluetooth driver.

  Description:
    This object is used to keep track of any data that is common to all
    instances of the  BM71 Bluetooth driver.

  Remarks:
    None.
*/

typedef struct _DRV_BM71_OBJ_STRUCT
{  
    SYS_STATUS status;              // status of this driver instance   
    bool inUse;                     // indicates this object is in use
    bool isExclusive;               // flag to indicate that the hardware instance is used in exclusive access mode */
    uint8_t numClients;             // number of clients possible with the hardware instance
//    SYS_MODULE_INDEX tmrDriverModuleIndex;  // identifies control module timer ID for control interface of CODEC 
    DRV_HANDLE tmrDriverHandle;     // identifies control module(Timer) driver open handle
    bool isInInterruptContext;      // keeps track if the driver is in interrupt context
    OSAL_MUTEX_DECLARE(mutexDriverInstance);    // hardware instance mutex
    uint8_t linkIndex;
    uint8_t request;
//    DRV_BM71_LINKSTATUS linkStatus;
//    uint8_t linkedMode;
//    uint8_t pairedRecordNumber;  
    DRV_BM71_TASKSTATE state;    
//    DRV_BM71_NEXTCOMMANDREQ nextCommandReq;
} DRV_BM71_OBJ;

typedef struct
{
    /* Indicates that this object is in use */
    bool inUse;

    /* Indicate whether the client is open in
     * read,write or read/write mode */
    DRV_IO_INTENT ioIntent;
    
    DRV_BM71_PROTOCOL protocol;

    /* Call back function for this client */
    DRV_BM71_EVENT_HANDLER  pEventCallBack;

    /* Client data(Event Context) that will be
     * returned at callback */
    uintptr_t hClientArg;

} DRV_BM71_CLIENT_OBJ;

typedef struct
{
    /* Set to true if all members of this structure
       have been initialized once */
    bool membersAreInitialized;

    /* Mutex to protect client object pool */
    OSAL_MUTEX_DECLARE(mutexClientObjects);

} DRV_BM71_COMMON_DATA_OBJ;

// decode events (passed between drv_bm71_command_decode.c and drv_bm71.c)
typedef enum 
{
    DRV_BM71_DEC_EVENT_NONE = 0,

    DRV_BM71_DEC_EVENT_SPP_CONNECTED,
    DRV_BM71_DEC_EVENT_SPP_IAP_DISCONNECTED,

    DRV_BM71_DEC_EVENT_SYS_POWER_ON,
    DRV_BM71_DEC_EVENT_SYS_POWER_OFF,
    DRV_BM71_DEC_EVENT_SYS_STANDBY,           
    
    DRV_BM71_DEC_EVENT_LE_STATUS_CHANGED,
    DRV_BM71_DEC_EVENT_LE_ADV_CONTROL_REPORT,
    DRV_BM71_DEC_EVENT_LE_CONNECTION_PARA_REPORT,
    DRV_BM71_DEC_EVENT_LE_CONNECTION_PARA_UPDATE_RSP,
    DRV_BM71_DEC_EVENT_GATT_ATTRIBUTE_DATA,
} DRV_BM71_DEC_EVENT;           // BM71 decoded events

enum {
    DRV_BM71_SYSTEM_INIT,         //init
    DRV_BM71_SYSTEM_POWER_OFF,    //event
    DRV_BM71_SYSTEM_POWER_ON,     //event
    DRV_BM71_SYSTEM_STANDBY,      //event
    DRV_BM71_SYSTEM_CONNECTED,    //event
} DRV_BM71_SystemStatus;        // BT internal system status

/////////////////////////////// new //////////////////////////////////////

#define BM_PKT_LEN_MAX    0x01FF
#define BM_CFG_CMD_SOF_VAL    0xAA

#define BM_APPLICATION_MODE_CMD(x)	(appCmds[x])
#define BM_APPLICATION_MODE_CMD_LEN(x)	(appCmds[x].length)

#define BM_LE_ADV_INTERVAL_UNIT (640)    /* 0.625ms x 1024 */
#define BM_LE_ADV_INTERVAL_VAL(x)   (((uint32_t)x << 10)/BM_LE_ADV_INTERVAL_UNIT)
#define BM_LE_ADV_INTERVAL_MIN  (0x0020)
#define BM_LE_ADV_INTERVAL_MAX  (0x4000)
#define BM_LE_ADV_INTERVAL_MS(x)  (((uint32_t)x * BM_LE_ADV_INTERVAL_UNIT) >> 10)

/* Advertisement report */
#define ADV_REPORT_EVENT_TYPE_START			0
#define ADV_REPORT_EVENT_TYPE_LEN			1
#define ADV_REPORT_ADDRESS_TYPE_START		(ADV_REPORT_EVENT_TYPE_START + ADV_REPORT_EVENT_TYPE_LEN)
#define ADV_REPORT_ADDRESS_TYPE_LEN			1
#define ADV_REPORT_ADDRESS_START			(ADV_REPORT_ADDRESS_TYPE_START + ADV_REPORT_ADDRESS_TYPE_LEN)
#define ADV_REPORT_ADDRESS_LEN				6
#define ADV_REPORT_DATA_LENGTH_START		(ADV_REPORT_ADDRESS_START + ADV_REPORT_ADDRESS_LEN)
#define ADV_REPORT_DATA_LENGTH_LEN			1
#define ADV_REPORT_DATA_START				(ADV_REPORT_DATA_LENGTH_START + ADV_REPORT_DATA_LENGTH_LEN)
#define ADV_REPORT_RSSI_LEN					1

/* Discover specific primary service characteristic response */
#define SERVICE_DISC_CHAR_RESP_CONN_HANDLE_START				0
#define SERVICE_DISC_CHAR_RESP_CONN_HANDLE_LEN					1
#define SERVICE_DISC_CHAR_RESP_LENGTH_START						(SERVICE_DISC_CHAR_RESP_CONN_HANDLE_START + SERVICE_DISC_CHAR_RESP_CONN_HANDLE_LEN)
#define SERVICE_DISC_CHAR_RESP_LENGTH_LEN						1
#define SERVICE_DISC_CHAR_RESP_ATTRIB_DATA_START				(SERVICE_DISC_CHAR_RESP_LENGTH_START + SERVICE_DISC_CHAR_RESP_LENGTH_LEN)
#define SERVICE_DISC_CHAR_RESP_ATTRIB_HANDLE_START				0
#define SERVICE_DISC_CHAR_RESP_ATTRIB_HANDLE_LEN				2
#define SERVICE_DISC_CHAR_RESP_CHAR_PROPERTY_START				(SERVICE_DISC_CHAR_RESP_ATTRIB_HANDLE_START + SERVICE_DISC_CHAR_RESP_ATTRIB_HANDLE_LEN)
#define SERVICE_DISC_CHAR_RESP_CHAR_PROPERTY_LEN				1
#define SERVICE_DISC_CHAR_RESP_CHAR_VAL_ATTRIB_HANDLE_START		(SERVICE_DISC_CHAR_RESP_CHAR_PROPERTY_START + SERVICE_DISC_CHAR_RESP_CHAR_PROPERTY_LEN)
#define SERVICE_DISC_CHAR_RESP_CHAR_VAL_ATTRIB_HANDLE_LEN		2
#define SERVICE_DISC_CHAR_RESP_CHAR_UUID_START					(SERVICE_DISC_CHAR_RESP_CHAR_VAL_ATTRIB_HANDLE_START + SERVICE_DISC_CHAR_RESP_CHAR_VAL_ATTRIB_HANDLE_LEN)
#define SERVICE_DISC_CHAR_RESP_CHAR_UUID_16_LEN					2
#define SERVICE_DISC_CHAR_RESP_CHAR_UUID_128_LEN				16

/* Discover all characteristic descriptor response */
#define DESC_DISC_RESP_CONN_HANDLE_START		0
#define DESC_DISC_RESP_CONN_HANDLE_LEN			1
#define DESC_DISC_RESP_FORMAT_START				(DESC_DISC_RESP_CONN_HANDLE_START + DESC_DISC_RESP_CONN_HANDLE_LEN)
#define DESC_DISC_RESP_FORMAT_LEN				1
#define DESC_DISC_RESP_DATA_START				(DESC_DISC_RESP_FORMAT_START + DESC_DISC_RESP_FORMAT_LEN)
#define DESC_DISC_RESP_ATTRIB_HANDLE_START		0
#define DESC_DISC_RESP_ATTRIB_HANDLE_LEN		2
#define DESC_DISC_RESP_UUID_START				(DESC_DISC_RESP_ATTRIB_HANDLE_START + DESC_DISC_RESP_ATTRIB_HANDLE_LEN)
#define DESC_DISC_RESP_UUID_16B_LEN				2
#define DESC_DISC_RESP_UUID_128B_LEN			16

typedef enum _bm_status
{
    BM_STATUS_POWER_ON       = 0x00,
    BM_STATUS_SCANNING,
    BM_STATUS_CONNECTING,    
    BM_STATUS_STANDBY,
    BM_STATUS_BROADCAST,
    BM_STATUS_TRANSPARENT_UART,
    BM_STATUS_IDLE,
    BM_STATUS_SHUTDOWN,
    BM_STATUS_CONFIGURE,
    BM_STATUS_CONNECTED
} BM_STATUS;

/*! \enum BM_PASSKEY_ACTION_OPTION
 * Enumeration of the passkey entry actions during pairing procedure.
 */
enum BM_PASSKEY_ACTION_OPTION
{
	/*! Passkey digit enter. */
	BM_PASSKEY_DIGIT_ENTER = 1,
	/*! Passkey digit erase. */
	BM_PASSKEY_DIGIT_ERASE,
	/*! Passkey clear. */
	BM_PASSKEY_CLEAR,
	/*! Passkey entry complete. */
	BM_PASSKEY_ENTRY_COMPLETE
};

typedef enum _bm_application_cmd_index
{
	BM_LOCAL_INFORMATION_READ_INDEX = 0x00,
    BM_RESET_INDEX,
    BM_STATUS_READ_INDEX,
    BM_ADC_READ_INDEX,
    BM_SHUTDOWN_INDEX,
	BM_DEBUG_INDEX,
    BM_NAME_READ_INDEX,
    BM_NAME_WRITE_INDEX,
    BM_PDL_ERASE_INDEX,
    BM_PAIR_MODE_READ_INDEX,
    BM_PAIR_MODE_WRITE_INDEX,
    BM_PDL_READ_INDEX,
    BM_DEVICE_ERASE_INDEX,
	BM_DIO_CONTROL_INDEX,
	BM_PWM_CONTROL_INDEX,
    BM_RSSI_READ_INDEX,
	BM_ADV_DATA_WRITE_INDEX,
    BM_SCAN_DATA_WRITE_INDEX,
	BM_ADV_PARAM_SET_INDEX,
	BM_CONN_PARAM_SET_INDEX,
	BM_SCAN_PARAM_SET_INDEX,
	BM_SCAN_ENABLE_SET_INDEX,
	BM_CONNECT_INDEX,
	BM_CONNECT_CANCEL_INDEX,
	BM_CONNECTION_PARAM_UPDATE_INDEX,
    BM_DISCONNECT_INDEX,
	BM_SET_ADV_ENABLE_INDEX,
    BM_REMOTE_NAME_READ_INDEX,
    BM_CLIENT_WRITE_REQUEST_PREPARE_INDEX,
    BM_CLIENT_WRITE_REQUEST_EXECUTE_INDEX,
    BM_CLIENT_BLOB_REQUEST_READ_INDEX,
    BM_CLIENT_HANDLE_VALUE_CONFIRM_INDEX,
	BM_CLIENT_DISCOVER_ALL_SERVICES_INDEX,
	BM_CLIENT_DISCOVER_CHARACTERISTICS_INDEX,
	BM_CLIENT_CHARACTERISTIC_READ_INDEX,
	BM_CLIENT_CHARACTERISTIC_UUID_READ_INDEX,
	BM_CLIENT_CHARACTERISTIC_WRITE_INDEX,
	BM_TRANSPARENT_ENABLE_INDEX,
	BM_SERVER_CREATE_SERVICE_REQUEST_INDEX,
    BM_SERVER_WRITE_RESPONSE_PREPARE_INDEX,
    BM_SERVER_WRITE_RESPONSE_EXECUTE_INDEX,
    BM_SERVER_BLOB_RESPONSE_READ_INDEX,
    BM_SERVER_ERROR_RESPONSE_INDEX,
	BM_SERVER_CHARACTERISTIC_SEND_INDEX,
	BM_SERVER_CHARACTERISTIC_UPDATE_INDEX,
	BM_SERVER_CHARACTERISTIC_READ_INDEX,
	BM_SERVER_ALL_SERVICES_READ_INDEX,
	BM_SERVER_SERVICE_READ_INDEX,
	BM_SERVER_WRITE_RESPONSE_SEND_INDEX,
    BM_SERVER_READ_RESPONSE_SEND_INDEX,
	BM_TRANSPARENT_DATA_SEND_INDEX,
    BM_PASSKEY_ENTRY_INDEX,
    BM_PASSKEY_YESNO_CONFIRM_INDEX,
    BM_PAIRING_REQUEST_INDEX,
	BM_CONFIG_MODE_CLOSE_INDEX,
	BM_RECEIVER_TEST_INDEX,
	BM_TRANSMITTER_TEST_INDEX,
	BM_END_TEST_INDEX,
    BM_PATTERN_SET_INDEX,
} BM_APPLICATION_CMD_INDEX;

typedef enum _bm_application_cmd_opcode
{
	BM_LOCAL_INFORMATION_READ 	= 0x01,
    BM_RESET,
    BM_STATUS_READ,
    BM_ADC_READ,
    BM_SHUTDOWN             	= 0x05,
    BM_DEBUG,
    BM_NAME_READ,
    BM_NAME_WRITE,
    BM_PDL_ERASE,
    BM_PAIR_MODE_READ,
    BM_PAIR_MODE_WRITE,
    BM_PDL_READ,
    BM_DEVICE_ERASE,
    BM_DIO_CONTROL,
    BM_PWM_CONTROL,
    BM_RSSI_READ              	= 0x10,
    BM_ADV_DATA_WRITE,
    BM_SCAN_DATA_WRITE,
	BM_ADV_PARAM_SET            = 0x13,
	BM_CONN_PARAM_SET,
	BM_SCAN_PARAM_SET           = 0x15,
	BM_SCAN_ENABLE_SET,
	BM_CONNECT,
	BM_CONNECT_CANCEL,
	BM_CONNECTION_PARAM_UPDATE,
    BM_DISCONNECT             	= 0x1B,
	BM_SET_ADV_ENABLE           = 0x1C,
	BM_REMOTE_NAME_READ         = 0x1F,
    BM_CLIENT_WRITE_REQUEST_PREPARE = 0x20,
    BM_CLIENT_WRITE_REQUEST_EXECUTE,
    BM_CLIENT_BLOB_REQUEST_READ,
    BM_CLIENT_HANDLE_VALUE_CONFIRM = 0x2D,
	BM_CLIENT_DISCOVER_ALL_SERVICES	= 0x30,
	BM_CLIENT_DISCOVER_CHARACTERISTICS,
	BM_CLIENT_CHARACTERISTIC_READ,
	BM_CLIENT_CHARACTERISTIC_UUID_READ,
	BM_CLIENT_CHARACTERISTIC_WRITE,
	BM_TRANSPARENT_ENABLE,
	BM_SERVER_CREATE_SERVICE_REQUEST = 0x27,
    BM_SERVER_WRITE_RESPONSE_PREPARE = 0x28,
    BM_SERVER_WRITE_RESPONSE_EXECUTE,
    BM_SERVER_BLOB_RESPONSE_READ = 0x2A,
    BM_SERVER_ERROR_RESPONSE = 0x37,
	BM_SERVER_CHARACTERISTIC_SEND = 0x38,
	BM_SERVER_CHARACTERISTIC_UPDATE,
	BM_SERVER_CHARACTERISTIC_READ,
	BM_SERVER_ALL_SERVICES_READ,
	BM_SERVER_SERVICE_READ,
	BM_SERVER_WRITE_RESPONSE_SEND,
    BM_SERVER_READ_RESPONSE_SEND,        
	BM_TRANSPARENT_DATA_SEND 	= 0x3F,
    BM_PASSKEY_ENTRY          	= 0x40,
    BM_PASSKEY_YESNO_CONFIRM,
    BM_PAIRING_REQUEST,		
	BM_CONFIG_MODE_CLOSE		= 0x52,
	BM_RECEIVER_TEST,
	BM_TRANSMITTER_TEST,
	BM_END_TEST,
    BM_PATTERN_SET              = 0x57,
} BM_APPLICATION_CMD_OPCODE;

typedef enum _bm_application_cmd_state
{
	BM_CFG_CMD_SOF = 0x00,
    BM_CFG_CMD_LENH,
    BM_CFG_CMD_LENL,
    BM_CFG_CMD_OPCODE,
    BM_CFG_CMD_DATA,
    BM_CFG_CMD_CHKSUM
} BM_APPLICATION_CMD_STATE;

//////////////////////////////////////////////////////////////////////////

void DRV_BM71_Timer_1ms( uintptr_t context);
void DRV_BM71_Timer1MS_event();
void DRV_BM71_EventHandler(uint8_t event, uint16_t para, uint8_t* para_full);

void DRV_BM71_SPPBuffClear( void );
bool DRV_BM71_AddBytesToSPPBuff(uint8_t* data, uint8_t size);
void DRV_BM71_UpdateClientStatus(DRV_BM71_DRVR_STATUS status);
#endif
