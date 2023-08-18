/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_usb.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.

 * Subject to your compliance with these terms, you may use this Microchip software
 * and any derivatives exclusively with Microchip products. You are responsible for
 * complying with third party license terms applicable to your use of third party
 * software (including open source software) that may accompany this Microchip software.

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
 *******************************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app_usb.h"
#include "common.h"

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <string.h>
#include "peripheral/systick/plib_systick.h"
#include "user.h"
#include "definitions.h"                // SYS function prototypes

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_CAN_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

/* Variable to save Tx/Rx transfer status and context */

bool app_can_config_flag=0,rx_character=0; 
volatile uint8_t app_buffer_read[10],app_buffer_index=0,app_temp=0, app_boot_buffer_read[60];


#define APP_IMAGE_START_ADDR        0x2000UL  

/* Definitions */
#define APP_IMAGE_END_ADDR                          (APP_IMAGE_START_ADDR + app_size)
#define APP_PROTOCOL_HEADER_MAX_SIZE                4
#define LED_ON()                                    LED_On() 
#define LED_OFF()                                   LED_Off()
#define SWITCH_GET()                                SWITCH_Get()
#define SWITCH_PRESSED                              0

#define CAN_DATA_FRAME_SIZE                         (64UL)
#define APP_CAN_BOOT_SIZE CAN_DATA_FRAME_SIZE-APP_PROTOCOL_HEADER_MAX_SIZE 
#define APP_CRC_SIZE 10
#define MESSAGE_BUFFER_SIZE 1024

static char message_buffer[MESSAGE_BUFFER_SIZE];

/* Standard identifier id[28:18]*/
#define WRITE_ID(id) (id << 18)
#define READ_ID(id)  (id >> 18)

enum
{
    BL_RESP_OK          = 0x50,
    BL_RESP_ERROR       = 0x51,
    BL_RESP_INVALID     = 0x52,
    BL_RESP_CRC_OK      = 0x53,
    BL_RESP_CRC_FAIL    = 0x54,
    BL_RESP_SEQ_ERROR   = 0x55
};

typedef enum
{
    APP_BL_COMMAND_UNLOCK = 0xA0,
    APP_BL_COMMAND_DATA = 0xA1,
    APP_BL_COMMAND_VERIFY = 0xA2,
    APP_BL_COMMAND_RESET = 0xA3
}APP_BL_COMMAND;

typedef enum
{
    APP_STATE_INIT,
    APP_STATE_WAIT_SW_PRESS,
    APP_STATE_SEND_UNLOCK_COMMAND,
    APP_STATE_WAIT_UNLOCK_COMMAND_TRANSFER_COMPLETE,
    APP_STATE_SEND_DATA_COMMAND,
    APP_STATE_WAIT_DATA_COMMAND_TRANSFER_COMPLETE,
    APP_STATE_SEND_VERIFY_COMMAND,
    APP_STATE_WAIT_VERIFY_COMMAND_TRANSFER_COMPLETE,
    APP_STATE_SEND_RESET_COMMAND,
    APP_STATE_WAIT_RESET_COMMAND_TRANSFER_COMPLETE,
    APP_STATE_SUCCESSFUL,
    APP_STATE_ERROR,
    APP_STATE_IDLE

} APP_STATES;

typedef enum
{
    APP_TRANSFER_STATUS_IN_PROGRESS,
    APP_TRANSFER_STATUS_SUCCESS,
    APP_TRANSFER_STATUS_ERROR,
    APP_TRANSFER_STATUS_IDLE,

} APP_TRANSFER_STATUS;

typedef struct
{
    APP_STATES                      state;
    volatile APP_TRANSFER_STATUS    trasnferStatus;
    uint32_t                        appMemStartAddr;
    uint32_t                        nBytesWritten;
    uint32_t                        nBytesSent;
    uint32_t                        nPendingBytes;
    uint8_t                         wrBuffer[CAN_DATA_FRAME_SIZE];
} APP_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions related to CAN NVM Host
// *****************************************************************************
// *****************************************************************************
APP_DATA                            appBootData;
static uint8_t CACHE_ALIGN          can1MessageRAM[CAN1_MESSAGE_RAM_CONFIG_SIZE];

bool app_boot_can_dataframe=0,app_boot_can_protocolheader=0,app_boot_crc_check=0;
static uint32_t status = 0;
static uint8_t loop_count = 0;
static volatile uint32_t nTxBytes,app_size=0,crc=0,can_id=0;
static CAN_TX_BUFFER *txBuffer = NULL;
uint8_t* can_transmit_buffer;
CAN_BIT_TIMING_SETUP newsetup;
CAN_BIT_TIMING newbitTiming;
static uint8_t txFiFo[CAN1_TX_FIFO_BUFFER_SIZE];
bool app_boot_program_initialize =0,app_boot_programming_enable=0,app_boot_read=0,app_boot_select_id=1;

 
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions to USB CDC
// *****************************************************************************
// *****************************************************************************

uint8_t CACHE_ALIGN cdcReadBuffer[APP_USB_READ_BUFFER_SIZE];
uint8_t CACHE_ALIGN cdcWriteBuffer[APP_USB_WRITE_BUFFER_SIZE];

APP_USB_DATA app_usbData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************
 * USB CDC Device Events - Application Event Handler
 *******************************************************/

USB_DEVICE_CDC_EVENT_RESPONSE APP_USB_USBDeviceCDCEventHandler
(
        USB_DEVICE_CDC_INDEX index,
        USB_DEVICE_CDC_EVENT event,
        void * pData,
        uintptr_t userData
        ) {
    APP_USB_DATA * appDataObject;
    USB_CDC_CONTROL_LINE_STATE * controlLineStateData;
    USB_DEVICE_CDC_EVENT_DATA_READ_COMPLETE * eventDataRead;

    appDataObject = (APP_USB_DATA *) userData;

    switch (event) {
        case USB_DEVICE_CDC_EVENT_GET_LINE_CODING:

            /* This means the host wants to know the current line
             * coding. This is a control transfer request. Use the
             * USB_DEVICE_ControlSend() function to send the data to
             * host.  
             */

            USB_DEVICE_ControlSend(appDataObject->deviceHandle,
                    &appDataObject->getLineCodingData,
                    sizeof (USB_CDC_LINE_CODING));

            break;

        case USB_DEVICE_CDC_EVENT_SET_LINE_CODING:

            /* This means the host wants to set the line coding.
             * This is a control transfer request. Use the
             * USB_DEVICE_ControlReceive() function to receive the
             * data from the host 
             */

            USB_DEVICE_ControlReceive(appDataObject->deviceHandle,
                    &appDataObject->setLineCodingData,
                    sizeof (USB_CDC_LINE_CODING));

            break;

        case USB_DEVICE_CDC_EVENT_SET_CONTROL_LINE_STATE:

            /* This means the host is setting the control line state.
             * Read the control line state. We will accept this request
             * for now. 
             */

            controlLineStateData = (USB_CDC_CONTROL_LINE_STATE *) pData;
            appDataObject->controlLineStateData.dtr = controlLineStateData->dtr;
            appDataObject->controlLineStateData.carrier =
                    controlLineStateData->carrier;

            USB_DEVICE_ControlStatus(appDataObject->deviceHandle,
                    USB_DEVICE_CONTROL_STATUS_OK);

            break;

        case USB_DEVICE_CDC_EVENT_SEND_BREAK:

            /* This means that the host is requesting that a break of the
             * specified duration be sent. Read the break duration 
             */

            appDataObject->breakData = ((USB_DEVICE_CDC_EVENT_DATA_SEND_BREAK *)
                    pData)->breakDuration;

            /* Complete the control transfer by sending a ZLP  */
            USB_DEVICE_ControlStatus(appDataObject->deviceHandle,
                    USB_DEVICE_CONTROL_STATUS_OK);

            break;

        case USB_DEVICE_CDC_EVENT_READ_COMPLETE:

            /* This means that the host has sent some data, store the same */
            eventDataRead = (USB_DEVICE_CDC_EVENT_DATA_READ_COMPLETE *) pData;

            /* Notify state machine that a read was completed */
            appDataObject->isReadComplete = true;
            
            /* Update the number of bytes read */
            appDataObject->numBytesRead = eventDataRead->length;

            break;

        case USB_DEVICE_CDC_EVENT_CONTROL_TRANSFER_DATA_RECEIVED:

            /* The data stage of the last control transfer is
             * complete. For now we accept all the data 
             */

            USB_DEVICE_ControlStatus(appDataObject->deviceHandle,
                    USB_DEVICE_CONTROL_STATUS_OK);

            break;

        case USB_DEVICE_CDC_EVENT_CONTROL_TRANSFER_DATA_SENT:

            /* This means the GET LINE CODING function data is valid. We don't
             * do much with this data in this demo.
             */

            break;

        case USB_DEVICE_CDC_EVENT_WRITE_COMPLETE:

            /* This means that the data write got completed and we can schedule
             * the next read. Notify the state machine by setting a flag. 
             */

            /* Notify state machine that a write was completed */
            appDataObject->isWriteComplete = true;
            break;

        default:
            break;
    }

    return USB_DEVICE_CDC_EVENT_RESPONSE_NONE;
}

/***********************************************
 * Application USB Device Layer Event Handler.
 ***********************************************/
void APP_USB_USBDeviceEventHandler
(
        USB_DEVICE_EVENT event,
        void * eventData,
        uintptr_t context
        ) {
    USB_DEVICE_EVENT_DATA_CONFIGURED *configuredEventData;

    switch (event) {
        case USB_DEVICE_EVENT_SOF:

            app_usbData.sofEventHasOccurred = true;

            break;

        case USB_DEVICE_EVENT_RESET:

            /* Update LED to show reset state */
            LED_Off();

            app_usbData.isConfigured = false;

            break;

        case USB_DEVICE_EVENT_CONFIGURED:

            /* Check the configuration. We only support configuration 1 */
            configuredEventData = (USB_DEVICE_EVENT_DATA_CONFIGURED*) eventData;

            if (configuredEventData->configurationValue == 1) {
                /* Mark that the device is now configured */
                app_usbData.isConfigured = true;

                /* Update LED to show configured state */
                LED_On();

                /* Register the CDC Device application event handler here.
                 * Note how the appData object pointer is passed as the
                 * user data 
                 */
                USB_DEVICE_CDC_EventHandlerSet(USB_DEVICE_CDC_INDEX_0,
                        APP_USB_USBDeviceCDCEventHandler,
                        (uintptr_t) & app_usbData);

            }

            break;

        case USB_DEVICE_EVENT_POWER_DETECTED:

            /* VBUS was detected. We can attach the device */
            USB_DEVICE_Attach(app_usbData.deviceHandle);

            break;

        case USB_DEVICE_EVENT_POWER_REMOVED:

            /* VBUS is not available any more. Detach the device. */
            USB_DEVICE_Detach(app_usbData.deviceHandle);

            LED_Off();

            break;

        case USB_DEVICE_EVENT_SUSPENDED:

            LED_Off();

            break;

        case USB_DEVICE_EVENT_RESUMED:
        case USB_DEVICE_EVENT_ERROR:
        default:

            break;
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
/* Write message via USB CDC

   Summary:
        Sends the Data according to USB CDC

   Description:
        Pass the message to write the content in USB CDC.

   Remarks:
    None.
*/
void APP_USB_WriteMessage(const char* message) 
{
    app_usbData.numBytesWrite = sprintf((char*)app_usbData.cdcWriteBuffer,"%s", message);
    USB_DEVICE_CDC_Write(USB_DEVICE_CDC_INDEX_0,
                            &app_usbData.writeTransferHandle,
                            app_usbData.cdcWriteBuffer,
                            app_usbData.numBytesWrite,
                            USB_DEVICE_CDC_TRANSFER_FLAGS_DATA_COMPLETE);
    app_usbData.state = APP_USB_STATE_WAIT_FOR_WRITE_COMPLETE;
}

void usb_send_data_C()
{
    app_usbData.numBytesWrite =  sprintf((char*)app_usbData.cdcWriteBuffer,"C");
                 USB_DEVICE_CDC_Write(USB_DEVICE_CDC_INDEX_0,
                        &app_usbData.writeTransferHandle,
                        app_usbData.cdcWriteBuffer, app_usbData.numBytesWrite,
                        USB_DEVICE_CDC_TRANSFER_FLAGS_DATA_COMPLETE);
                    
                    app_usbData.state = APP_USB_STATE_WAIT_FOR_WRITE_COMPLETE;
}

void usb_send_data_X()
{
    app_usbData.numBytesWrite =  sprintf((char*)app_usbData.cdcWriteBuffer,"X");
                 USB_DEVICE_CDC_Write(USB_DEVICE_CDC_INDEX_0,
                        &app_usbData.writeTransferHandle,
                        app_usbData.cdcWriteBuffer, app_usbData.numBytesWrite,
                        USB_DEVICE_CDC_TRANSFER_FLAGS_DATA_COMPLETE);
                    
                    app_usbData.state = APP_USB_STATE_WAIT_FOR_WRITE_COMPLETE;
}

/*Delay for USB data processing during programming mode*/
void synchronization_delay()
{
   
   for(uint32_t k =0; k<262140;k++)
   __NOP(); 
    
}

/* CAN DLC To data Length

   Summary:
    Holds length of the data according to CAN protocol 

   Description:
    From the DLC field, get the length of the data.

   Remarks:
    None.
*/
/* Data length code to Message Length */
static uint8_t APP_CANDlcToLengthGet(uint8_t dlc)
{
    uint8_t msgLength[] = {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 12U, 16U, 20U, 24U, 32U, 48U, 64U};
    return msgLength[dlc];
}
/* Data Length CAN DLC 

   Summary:
    changes length of the data according to CAN protocol 

   Description:
    From the message length, get the  CAN DLC field.

   Remarks:
    None.
*/

/* Message Length to Data length code */
static uint8_t APP_CANLengthToDlcGet(uint8_t length)
{
    uint8_t dlc = 0;

    if (length <= 8U)
    {
        dlc = length;
    }
    else if (length <= 12U)
    {
        dlc = 0x9U;
    }
    else if (length <= 16U)
    {
        dlc = 0xAU;
    }
    else if (length <= 20U)
    {
        dlc = 0xBU;
    }
    else if (length <= 24U)
    {
        dlc = 0xCU;
    }
    else if (length <= 32U)
    {
        dlc = 0xDU;
    }
    else if (length <= 48U)
    {
        dlc = 0xEU;
    }
    else
    {
        dlc = 0xFU;
    }
    return dlc;
}

/* Change the bit rates of CAN and reinitialize

   Summary:
        Changes the CAN bit rate and Reinitializes the CAN protocol

   Description:
        Modify CAN bit rate and reinitialize 

   Remarks:
    None.
*/

void APP_CAN_bitrates_reinitialize(uint32_t nominal, uint32_t data)
{
    
    newsetup.nominalBitTimingSet = true;
    newsetup.nominalBitRate= nominal; 
    newsetup.nominalPrescaler=5;
    newsetup.nominalSamplePoint =75; 
    
    newsetup.dataBitTimingSet = true; 
    newsetup.dataBitRate= data;
    newsetup.dataPrescaler = 0; 
    if(data == 1000000)
        newsetup.dataPrescaler=5; 
    newsetup.dataSamplePoint = 75; 
    
    if(CAN1_BitTimingCalculationGet(&newsetup,&newbitTiming))
    {
    if(CAN1_BitTimingSet(&newbitTiming)) 
    strcpy(message_buffer,"\r\n CAN configuration updated. \r\n");
    APP_USB_WriteMessage(message_buffer);
    }
    else
    {
    strcpy(message_buffer,"\r\n CAN configuration not updated correctly. Please reconfigure \r\n");
    APP_USB_WriteMessage(message_buffer);
    } 
}

/* Get the CAN bit rates according to options

   Summary:
    changes CAN bit rate according to user input

   Description:
    From the user input, get the CAN bit rates.

   Remarks:
    None.
*/


void APP_USB_CAN_reconfiguration()
{
    
  
    if(app_temp==0x31 && app_buffer_read[6] == 0x31)
        {
            APP_CAN_bitrates_reinitialize(250000, 1000000);
            app_buffer_read[5]='\0'; app_buffer_read[6]='\0';
            app_buffer_index=0;
            return;
        }
    if(app_temp==0x31 && app_buffer_read[6] == 0x32)
        {
            APP_CAN_bitrates_reinitialize(250000, 2000000);
            app_buffer_read[5]='\0'; app_buffer_read[6]='\0';
            app_buffer_index=0;
            return;
        }
    if(app_temp==0x31 && app_buffer_read[6] == 0x33)
        {
            APP_CAN_bitrates_reinitialize(250000, 3000000);
            app_buffer_read[5]='\0'; app_buffer_read[6]='\0';
            app_buffer_index=0;
            return; 
        }
    if(app_temp==0x31 && app_buffer_read[6] == 0x34)
        {
            APP_CAN_bitrates_reinitialize(250000, 4000000);
            app_buffer_read[5]='\0'; app_buffer_read[6]='\0';
            app_buffer_index=0;
            return;
        }
    if(app_temp==0x32 && app_buffer_read[6] == 0x31)
        {
            APP_CAN_bitrates_reinitialize(500000, 1000000);
            app_buffer_read[5]='\0'; app_buffer_read[6]='\0';
            app_buffer_index=0;
            return;
        }
    if(app_temp==0x32 && app_buffer_read[6] == 0x32)
        {
            APP_CAN_bitrates_reinitialize(500000, 2000000);
            app_buffer_read[5]='\0'; app_buffer_read[6]='\0';
            app_buffer_index=0;
            return;
        }
    if(app_temp==0x32 && app_buffer_read[6] == 0x33)
        {
            APP_CAN_bitrates_reinitialize(500000, 3000000);
            app_buffer_read[5]='\0'; app_buffer_read[6]='\0';
            app_buffer_index=0;
            return;
        }
    if(app_temp==0x32 && app_buffer_read[6] == 0x34)
        {
            APP_CAN_bitrates_reinitialize(500000, 4000000);
            app_buffer_read[5]='\0'; app_buffer_read[6]='\0';
            app_buffer_index=0;
            return; 
        }
    
}


/* Logs the CAN data to USB CDC
 
 * Summary:
    Send the CAN data to USB CDC

   Description:
    If the CAN data is received from node it will send to USB CDC

   Remarks:
    None.
*/


void APP_CAN_data_logging()
{
    app_usbData.isWriteComplete = false;
    app_usbData.writeTransferHandle =
                        USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;
                

        uint8_t msgLength = 0;
        uint32_t id = 0;
        uint8_t numberOfMessage =1; 
        for (uint8_t count = 0; count < numberOfMessage; count++)
        {
            id = ((CAN_RX_BUFFER *)COMMON_APP_CAN_GetData())->xtd ? ((CAN_RX_BUFFER *)COMMON_APP_CAN_GetData())->id : (((((CAN_RX_BUFFER *)COMMON_APP_CAN_GetData())->id))>>18);
            msgLength = APP_CANDlcToLengthGet(((CAN_RX_BUFFER *)COMMON_APP_CAN_GetData())->dlc);
            app_usbData.numBytesWrite =  sprintf((char*)app_usbData.cdcWriteBuffer, "\r\n\n New Message Received \r\n ID :" "0x%x" " \r\n Length :" "0x%x bytes" "\r\n Data : " , (unsigned int)id, (unsigned int)msgLength);
            uint8_t temp= 0; 
            for(int k=0;k< msgLength ;k++)   
                {
                temp = sprintf((char*)(app_usbData.cdcWriteBuffer + app_usbData.numBytesWrite), "0x%d ", ((CAN_RX_BUFFER *)COMMON_APP_CAN_GetData())->data[k] );
                app_usbData.numBytesWrite = app_usbData.numBytesWrite +  temp ; 
                }
        }
            /* Schedule write */
            USB_DEVICE_CDC_Write(USB_DEVICE_CDC_INDEX_0,
                        &app_usbData.writeTransferHandle,
                        app_usbData.cdcWriteBuffer,
                        app_usbData.numBytesWrite,
                        USB_DEVICE_CDC_TRANSFER_FLAGS_DATA_COMPLETE);

            app_usbData.state = APP_USB_STATE_WAIT_FOR_WRITE_COMPLETE;
                
            COMMON_APP_CAN_Rx_DataStatus(false);
}


// *****************************************************************************
// *****************************************************************************
// Section: CAN NVM HOST RELATED FUNCTIONS
// *****************************************************************************
// *****************************************************************************
static void APP_Boot_Initialize(void)
{
    appBootData.appMemStartAddr = APP_IMAGE_START_ADDR;
    appBootData.nBytesWritten = 0;
    nTxBytes=0;
    appBootData.nPendingBytes=0;
    appBootData.nBytesSent=0;
    appBootData.state = APP_STATE_INIT;
    LED_OFF();
}

static uint32_t APP_Boot_ImageDataWrite(uint32_t memAddr, uint32_t nBytes)
{
    uint32_t k;
    volatile uint32_t nTxBytes = 0;
    static uint8_t sequence = 0;

    appBootData.wrBuffer[nTxBytes++] = APP_BL_COMMAND_DATA;
    appBootData.wrBuffer[nTxBytes++] = sequence++;
    appBootData.wrBuffer[nTxBytes++] = 0xE2;
    appBootData.wrBuffer[nTxBytes++] = nBytes & 0xFF;

    for (k = 0; k < nBytes; k++, nTxBytes++)
    {
        appBootData.wrBuffer[nTxBytes] = app_usbData.cdcReadBuffer[k];
    }

    return nTxBytes;
}

static uint32_t APP_Boot_UnlockCommandSend(uint32_t appStartAddr, uint32_t appSize)
{
    uint32_t nTxBytes = 0;

    appBootData.wrBuffer[nTxBytes++] = APP_BL_COMMAND_UNLOCK;
    appBootData.wrBuffer[nTxBytes++] = 0;
    appBootData.wrBuffer[nTxBytes++] = 0xE2;
    appBootData.wrBuffer[nTxBytes++] = 8;
    appBootData.wrBuffer[nTxBytes++] = appStartAddr;
    appBootData.wrBuffer[nTxBytes++] = (appStartAddr >> 8);
    appBootData.wrBuffer[nTxBytes++] = (appStartAddr >> 16);
    appBootData.wrBuffer[nTxBytes++] = (appStartAddr >> 24);
    appBootData.wrBuffer[nTxBytes++] = appSize;
    appBootData.wrBuffer[nTxBytes++] = (appSize >> 8);
    appBootData.wrBuffer[nTxBytes++] = (appSize >> 16);
    appBootData.wrBuffer[nTxBytes++] = (appSize >> 24);

    return nTxBytes;
}

static uint32_t APP_Boot_VerifyCommandSend(volatile uint32_t crc)
{
    uint32_t nTxBytes = 0;

    appBootData.wrBuffer[nTxBytes++] = APP_BL_COMMAND_VERIFY;
    appBootData.wrBuffer[nTxBytes++] = 0;
    appBootData.wrBuffer[nTxBytes++] = 0xE2;
    appBootData.wrBuffer[nTxBytes++] = 4;
    appBootData.wrBuffer[nTxBytes++] = crc;
    appBootData.wrBuffer[nTxBytes++] = (crc >> 8);
    appBootData.wrBuffer[nTxBytes++] = (crc >> 16);
    appBootData.wrBuffer[nTxBytes++] = (crc >> 24);

    return nTxBytes;
}

static uint32_t APP_Boot_ResetCommandSend(void)
{
    uint32_t nTxBytes = 0;

    appBootData.wrBuffer[nTxBytes++] = APP_BL_COMMAND_RESET;
    appBootData.wrBuffer[nTxBytes++] = 0;
    appBootData.wrBuffer[nTxBytes++] = 0xE2;
    appBootData.wrBuffer[nTxBytes++] = 0;

    return nTxBytes;
}

void APP_Boot_CheckBTLResponse(void)
{
    uint8_t numberOfMessage = 0;
    uint8_t msgLength = 0;
    uint32_t id = 0;
    COMMON_APP_CAN_Rx_DataStatus(false);
        /* Check CAN1 Status */
        status = CAN1_ErrorGet();
        if (((status & CAN_PSR_LEC_Msk) == CAN_ERROR_NONE) || ((status & CAN_PSR_LEC_Msk) == CAN_ERROR_LEC_NC))
        {
            numberOfMessage = COMMON_APP_CAN_message_count();
            if (numberOfMessage != 0)
            {
                
              for (uint8_t count = 0; count < numberOfMessage; count++)
                {
                id=  ((CAN_RX_BUFFER *)COMMON_APP_CAN_GetData())->xtd ? ((CAN_RX_BUFFER *)COMMON_APP_CAN_GetData())->id : (((((CAN_RX_BUFFER *)COMMON_APP_CAN_GetData())->id))>>18);
                msgLength = APP_CANDlcToLengthGet(((CAN_RX_BUFFER *)COMMON_APP_CAN_GetData())->dlc);
                if ((id == can_id) && (msgLength == 1))   
                    {
                    if ((((CAN_RX_BUFFER *)COMMON_APP_CAN_GetData())->data[0] == BL_RESP_OK) || (((CAN_RX_BUFFER *)COMMON_APP_CAN_GetData())->data[0] == BL_RESP_CRC_OK))
                        {
                        appBootData.trasnferStatus = APP_TRANSFER_STATUS_SUCCESS;
                        }
                    else
                        {   
                        appBootData.trasnferStatus = APP_TRANSFER_STATUS_ERROR;
                        }
                    break;
                    }
                }  
            }
        }
    }

/* Transfer .bin file from python to CAN
 
 * Summary:
    Send the .bin file(packets of data) from USB to CAN bootloader

   Description:
    Programming the .bin file from python and send to attached node with Bootloader

   Remarks:
    None.
*/


void APP_USB_CAN_Programming()
{
    switch (appBootData.state)
                {
            case APP_STATE_INIT:
                appBootData.state = APP_STATE_WAIT_SW_PRESS;
                break;

            case APP_STATE_WAIT_SW_PRESS:
                if (SWITCH_GET() == SWITCH_PRESSED)
                { 
                    for(int i = 0; i < app_usbData.numBytesRead; i++)
                    {
                    if((app_usbData.cdcReadBuffer[i] != 0x0A) && (app_usbData.cdcReadBuffer[i] != 0x0D)) //
                    {
                        if(app_boot_programming_enable == 1)
                        {
                        app_boot_buffer_read[i] = app_usbData.cdcReadBuffer[i];
                        }
                    }
                    }
                    
                    for(int i=0;i<app_usbData.numBytesRead;i++)
                    {
                        app_size = (app_size *10) + (app_boot_buffer_read[i]-0x30); 
                    }
                    
                   
                    appBootData.state = APP_STATE_SEND_UNLOCK_COMMAND;
                     
                }
                break;

            case APP_STATE_SEND_UNLOCK_COMMAND:
            {
                nTxBytes = APP_Boot_UnlockCommandSend(APP_IMAGE_START_ADDR,app_size);
                appBootData.trasnferStatus = APP_TRANSFER_STATUS_IN_PROGRESS;
                app_boot_can_dataframe=1;

                memset(txFiFo, 0x00, CAN1_TX_FIFO_BUFFER_ELEMENT_SIZE);
                txBuffer = (CAN_TX_BUFFER *)txFiFo;
                txBuffer->id = WRITE_ID(can_id);
                txBuffer->dlc = APP_CANLengthToDlcGet(nTxBytes);
                txBuffer->fdf = 1;
                txBuffer->brs = 1;
                for (loop_count = 0; loop_count < nTxBytes; loop_count++){
                    txBuffer->data[loop_count] = appBootData.wrBuffer[loop_count];
                }        
                 
                can_transmit_buffer =(uint8_t*)txBuffer;
               
                if(COMMON_APP_CAN_SendData(1,can_transmit_buffer) == true )
                {
                    appBootData.state = APP_STATE_WAIT_UNLOCK_COMMAND_TRANSFER_COMPLETE;
                }
                else
                {
                    appBootData.state = APP_STATE_ERROR;
                }
                break;
            }
            case APP_STATE_SEND_DATA_COMMAND:
            {
                if(app_boot_read == 1)
                {
                appBootData.nPendingBytes = app_size - appBootData.nBytesWritten;
                if (appBootData.nPendingBytes >= CAN_DATA_FRAME_SIZE)
                {
                    appBootData.nBytesSent = CAN_DATA_FRAME_SIZE - APP_PROTOCOL_HEADER_MAX_SIZE;
                }
                else if (appBootData.nPendingBytes >= APP_PROTOCOL_HEADER_MAX_SIZE)
                {   
                    app_boot_can_dataframe=0;
                    app_boot_can_protocolheader= 1;
                
                    appBootData.nBytesSent = APP_PROTOCOL_HEADER_MAX_SIZE;
                }
                else
                {
                    appBootData.nBytesSent = appBootData.nPendingBytes;
                }
                synchronization_delay();
                
                nTxBytes = APP_Boot_ImageDataWrite((appBootData.appMemStartAddr + appBootData.nBytesWritten), appBootData.nBytesSent);
               
                
                appBootData.trasnferStatus = APP_TRANSFER_STATUS_IN_PROGRESS;

                memset(txFiFo, 0x00, CAN1_TX_FIFO_BUFFER_ELEMENT_SIZE);
                txBuffer = (CAN_TX_BUFFER *)txFiFo;
                txBuffer->id =WRITE_ID(can_id);
                txBuffer->dlc = APP_CANLengthToDlcGet(nTxBytes);
                txBuffer->fdf = 1;
                txBuffer->brs = 1;
                for (loop_count = 0; loop_count < nTxBytes; loop_count++){
                    txBuffer->data[loop_count] = appBootData.wrBuffer[loop_count];
                }        
              
                can_transmit_buffer =(uint8_t*)txBuffer;
               
                if(COMMON_APP_CAN_SendData(1,can_transmit_buffer) == true )
                {
                    appBootData.state = APP_STATE_WAIT_DATA_COMMAND_TRANSFER_COMPLETE;
                }
                else
                {
                    appBootData.state = APP_STATE_ERROR;
                }
                app_usbData.numBytesRead=0;
                app_boot_read = 0; 
                }
               break; 
            }
            case APP_STATE_SEND_VERIFY_COMMAND:
            {
                if(app_boot_read == 1)
                {
                   synchronization_delay();
                    
                for(int i = 0; i < app_usbData.numBytesRead; i++)
                    {
                    if((app_usbData.cdcReadBuffer[i] != 0x0A) && (app_usbData.cdcReadBuffer[i] != 0x0D)) 
                    {
                        if(app_boot_programming_enable == 1)
                        {
                        app_boot_buffer_read[i] = app_usbData.cdcReadBuffer[i];
                        }
                    }
                    }
                
                
                   for(int i=0;i<app_usbData.numBytesRead;i++)
                  app_boot_buffer_read[i]= (app_usbData.cdcReadBuffer[i])-0x30;   
                
                for(int i=0;i<app_usbData.numBytesRead;i++)
                    {
                        crc= (crc *10) + (app_boot_buffer_read[i]); 
                    }
            
                nTxBytes = APP_Boot_VerifyCommandSend(crc);
                appBootData.trasnferStatus = APP_TRANSFER_STATUS_IN_PROGRESS;

                memset(txFiFo, 0x00, CAN1_TX_FIFO_BUFFER_ELEMENT_SIZE);
                txBuffer = (CAN_TX_BUFFER *)txFiFo;
                txBuffer->id = WRITE_ID(can_id);
                txBuffer->dlc = APP_CANLengthToDlcGet(nTxBytes);
                txBuffer->fdf = 1;
                txBuffer->brs = 1;
                for (loop_count = 0; loop_count < nTxBytes; loop_count++){
                    txBuffer->data[loop_count] = appBootData.wrBuffer[loop_count];
                }                
                can_transmit_buffer =(uint8_t*)txBuffer;
               
                if(COMMON_APP_CAN_SendData(1,can_transmit_buffer) == true )
                {
                    appBootData.state = APP_STATE_WAIT_VERIFY_COMMAND_TRANSFER_COMPLETE;
                }
                else
                {
                    appBootData.state = APP_STATE_ERROR;
                }
                app_usbData.numBytesRead=0;
                app_boot_read = 0; 
                }
            }
                break;

            case APP_STATE_SEND_RESET_COMMAND:
                nTxBytes = APP_Boot_ResetCommandSend();
                appBootData.trasnferStatus = APP_TRANSFER_STATUS_IN_PROGRESS;

                memset(txFiFo, 0x00, CAN1_TX_FIFO_BUFFER_ELEMENT_SIZE);
                txBuffer = (CAN_TX_BUFFER *)txFiFo;
                txBuffer->id =  WRITE_ID(can_id);
                txBuffer->dlc = APP_CANLengthToDlcGet(nTxBytes);
                txBuffer->fdf = 1;
                txBuffer->brs = 1;
                for (loop_count = 0; loop_count < nTxBytes; loop_count++){
                    txBuffer->data[loop_count] = appBootData.wrBuffer[loop_count];
                }                
                can_transmit_buffer =(uint8_t*)txBuffer;
               
                if(COMMON_APP_CAN_SendData(1,can_transmit_buffer) == true )
                {
                    appBootData.state = APP_STATE_WAIT_RESET_COMMAND_TRANSFER_COMPLETE;
                }
                else
                {
                    appBootData.state = APP_STATE_ERROR;
                }
                break;

            case APP_STATE_WAIT_UNLOCK_COMMAND_TRANSFER_COMPLETE:
            case APP_STATE_WAIT_DATA_COMMAND_TRANSFER_COMPLETE:
            case APP_STATE_WAIT_VERIFY_COMMAND_TRANSFER_COMPLETE:
            case APP_STATE_WAIT_RESET_COMMAND_TRANSFER_COMPLETE:
            {
               if(COMMON_APP_CAN_Rx_DataIsReady()==false)
                   break;    
               else
                    {
                   APP_Boot_CheckBTLResponse();
                
                if (appBootData.trasnferStatus == APP_TRANSFER_STATUS_SUCCESS)
                {
                    if (appBootData.state == APP_STATE_WAIT_UNLOCK_COMMAND_TRANSFER_COMPLETE)
                    {
                        appBootData.state = APP_STATE_SEND_DATA_COMMAND;
                        usb_send_data_X();   
                    }
                    else if (appBootData.state == APP_STATE_WAIT_DATA_COMMAND_TRANSFER_COMPLETE)
                    {
                        appBootData.nBytesWritten += appBootData.nBytesSent;
                        if (appBootData.nBytesWritten < app_size)
                        {
                            appBootData.state = APP_STATE_SEND_DATA_COMMAND;
                            usb_send_data_X();    
                        }
                        else
                        {
                            appBootData.state = APP_STATE_SEND_VERIFY_COMMAND; 
                            app_boot_can_protocolheader=0;
                            app_boot_crc_check=1;
                            usb_send_data_C();
                        }
                    }
                    else if(appBootData.state == APP_STATE_WAIT_VERIFY_COMMAND_TRANSFER_COMPLETE)
                    {
                        appBootData.state = APP_STATE_SEND_RESET_COMMAND;
                    }
                    else if(appBootData.state == APP_STATE_WAIT_RESET_COMMAND_TRANSFER_COMPLETE)
                    {
                        appBootData.state = APP_STATE_SUCCESSFUL;
                    }
                }
                else if (appBootData.trasnferStatus == APP_TRANSFER_STATUS_ERROR)
                {
                    appBootData.state = APP_STATE_ERROR;
                }
                break;
               }
            }
            case APP_STATE_SUCCESSFUL:
                  LED_ON();
                  app_usbData.numBytesRead =0; 
                 app_buffer_index=0;
                 app_boot_crc_check=0;
                 for(int i=0;i<10;i++)
                 app_buffer_read[i]='\0';
                 app_boot_programming_enable=0; 
                 app_boot_select_id=1;
                 app_size=0;crc=0;
                appBootData.state = APP_STATE_IDLE;
                break;

            case APP_STATE_ERROR:

                LED_OFF();
                appBootData.state = APP_STATE_INIT;
                break;

            case APP_STATE_IDLE:
                break;

            default:
                break;
        }
}
				  
/*
 ****************************************************
 * This function is called in every step of the     *
 * application state machine.                       *
 ****************************************************
 */

bool APP_USB_StateReset(void) {
    /* This function returns true if the device was reset */

    bool retVal;

    if (app_usbData.isConfigured == false) {
        app_usbData.state = APP_USB_STATE_WAIT_FOR_CONFIGURATION;
        app_usbData.readTransferHandle = USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;
        app_usbData.writeTransferHandle =
                USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;
        app_usbData.isReadComplete = true;
        app_usbData.isWriteComplete = true;
        retVal = true;
    } else {
        retVal = false;
    }

    return (retVal);
}


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_USB_Initialize ( void )

  Remarks:
    See prototype in app_usb.h.
 */

void APP_USB_Initialize(void) {
    /* Place the state machine in its initial state. */
    app_usbData.state = APP_USB_STATE_INIT;

    /* Device Layer Handle  */
    app_usbData.deviceHandle = USB_DEVICE_HANDLE_INVALID;

    /* Device configured status */
    app_usbData.isConfigured = false;

    /* Initial get line coding state */
    app_usbData.getLineCodingData.dwDTERate = 115200;
    app_usbData.getLineCodingData.bParityType = 0;
    app_usbData.getLineCodingData.bParityType = 0;
    app_usbData.getLineCodingData.bDataBits = 8;

    /* Read Transfer Handle */
    app_usbData.readTransferHandle = USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;

    /* Write Transfer Handle */
    app_usbData.writeTransferHandle = USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;

    /* Initialize the read complete flag */
    app_usbData.isReadComplete = true;

    /*Initialize the write complete flag*/
    app_usbData.isWriteComplete = true;

    /* Reset other flags */
    app_usbData.sofEventHasOccurred = false;

    /* Set up the read buffer */
    app_usbData.cdcReadBuffer = &cdcReadBuffer[0];

    /* Set up the write buffer */
    app_usbData.cdcWriteBuffer = &cdcWriteBuffer[0];
    
  
}


/*******************************************************************************
  Function:
    void APP_USB_Tasks ( void )

  Remarks:
    See prototype in app_usb.h.
 ******************************************************************************/


void APP_USB_Tasks(void) {
    /* Update the application state machine based
     * on the current state 
     */

    switch (app_usbData.state) {
        case APP_USB_STATE_INIT:

            /* Open the device layer */
            app_usbData.deviceHandle = USB_DEVICE_Open(USB_DEVICE_INDEX_0,
                    DRV_IO_INTENT_READWRITE);

            if (app_usbData.deviceHandle != USB_DEVICE_HANDLE_INVALID) {
                /* Register a callback with device layer to get event 
                 * notification (for end point 0) 
                 */
                USB_DEVICE_EventHandlerSet(app_usbData.deviceHandle,
                        APP_USB_USBDeviceEventHandler, 0);

                app_usbData.state = APP_USB_STATE_WAIT_FOR_CONFIGURATION;
            } else {
                /* The Device Layer is not ready to be opened. We should try
                 * again later. 
                 */
            }

            break;

        case APP_USB_STATE_WAIT_FOR_CONFIGURATION:

            /* Check if the device was configured */
            if (app_usbData.isConfigured) {
                /* If the device is configured then lets start reading */
                app_usbData.state = APP_USB_STATE_IDLE;
            }

            break;
		 case APP_USB_STATE_SCHEDULE_READ:

            if(APP_USB_StateReset())
            {
                break;
            }
            /* If a read is complete, then schedule a read
             * else wait for the current read to complete */

            app_usbData.state = APP_USB_STATE_WAIT_FOR_READ_COMPLETE;
            if(app_usbData.isReadComplete == true)
            {
                app_usbData.isReadComplete = false;
                rx_character =1; 
                app_usbData.readTransferHandle =  USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;

                USB_DEVICE_CDC_Read (USB_DEVICE_CDC_INDEX_0,
                        &app_usbData.readTransferHandle, app_usbData.cdcReadBuffer,
                        APP_USB_READ_BUFFER_SIZE);
                
                if(app_usbData.readTransferHandle == USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID)
                {
                    appBootData.state = APP_STATE_ERROR;
                    break;
                }
            }

            break;

        case APP_USB_STATE_WAIT_FOR_READ_COMPLETE:
            
             if(APP_USB_StateReset())
            {
                break;
            }
             if(app_boot_programming_enable ==1 )
             {
                 if(app_boot_can_dataframe==1||app_boot_can_protocolheader ==1)
                 {
                     if(app_usbData.numBytesRead==(APP_CAN_BOOT_SIZE))
                     {
                        app_boot_read=1;
                     }
                     else if(app_usbData.numBytesRead==APP_PROTOCOL_HEADER_MAX_SIZE)
                    {
                        app_boot_read=1;
                    }
                  
                  else
                      break;
                 }
                 else
                 {
                  if(app_boot_crc_check == 1 )
                  {
                  if(app_usbData.numBytesRead == APP_CRC_SIZE)
                  {
                      app_boot_read=1;  
                  }
                  else
                      break;
                  }
                 }
             }
            
            /* Check if a character was received or a switch was pressed.
             * The isReadComplete flag gets updated in the CDC event handler. */

                app_usbData.state = APP_USB_STATE_IDLE;

            break;								 

        case APP_USB_STATE_SCHEDULE_WRITE:

            if( rx_character)
            {   
            if (APP_USB_StateReset()) {
                break;
            }
         
            app_usbData.isWriteComplete = false;
                app_usbData.writeTransferHandle =
                        USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;
             rx_character =0;
             if(app_boot_programming_enable == 0)
             {
                for(int i = 0; i < app_usbData.numBytesRead; i++)
                {
                    if((app_usbData.cdcReadBuffer[i] != 0x0A) && (app_usbData.cdcReadBuffer[i] != 0x0D))
                    {
                        
                        app_buffer_read[app_buffer_index] = app_usbData.cdcReadBuffer[i];
                        app_buffer_index++;
                         
                    }
                }
             }
             
             if((app_buffer_read[0] != 0x43 && app_buffer_read[0] != 0x63 && app_buffer_read[0] != '\0') || (app_buffer_read[1] != 0x4F && app_buffer_read[1] != 0x6F && app_buffer_read[1] != '\0')  || (app_buffer_read[2] != 0x4E && app_buffer_read[2] != 0x6E && app_buffer_read[2] != '\0') || (app_buffer_read[3] != 0x46 && app_buffer_read[3] != 0x66 && app_buffer_read[3] != '\0'))    
             {
                strcpy(message_buffer,"\r\n Invalid command. Use CONF or conf for Configuration mode \r\n");
                 APP_USB_WriteMessage(message_buffer); 
                 app_buffer_index=0; app_buffer_read[0]='\0'; app_buffer_read[1]='\0'; app_buffer_read[2]='\0'; app_buffer_read[3]='\0';
             }
             
            if((app_buffer_read[0] == 0x43 && app_buffer_read[1] == 0x4F && app_buffer_read[2] == 0x4E && app_buffer_read[3] == 0x46)|| (app_buffer_read[0] == 0x63 && app_buffer_read[1] == 0x6F && app_buffer_read[2] == 0x6E && app_buffer_read[3] == 0x66))
             {
                 strcpy(message_buffer,"\n\n\n\r Configuration Menu \r\n\r\n1. Change CAN bit rates \r\n2. Programming mode \r\n");
                 APP_USB_WriteMessage(message_buffer);
                 app_buffer_read[0]='\0'; app_buffer_read[1]='\0'; app_buffer_read[2]='\0'; app_buffer_read[3]='\0';                 
             }
             if(app_buffer_read[4] == 0x31)//CAN configuration mode
             {
                 app_can_config_flag=1;
                 strcpy(message_buffer,"\r\n\r\n Select the nominal bit rate(in kbps): \r\n1.250 \r\n2.500\r\n");
                 APP_USB_WriteMessage(message_buffer);
                app_buffer_read[4]='\0';   
             }
             
             if(app_buffer_read[5] == 0x31 || app_buffer_read[5] == 0x32)
             {
                 if(app_can_config_flag)
                 {
                 strcpy(message_buffer,"\r\n Select the data bit rate(in kbps): \r\n1.1000 \r\n2.2000 \r\n3.3000 \r\n4.4000\r\n");
                 APP_USB_WriteMessage(message_buffer);
                 app_temp=app_buffer_read[5];
                 app_buffer_read[5]='\0';
                app_can_config_flag=0;
                 }
                
             }
			 
			 if(app_buffer_read[6])
             {
                 APP_USB_CAN_reconfiguration();
				 
			 }
            
            }
            
            
            if(app_buffer_read[4] == 0x32)//Programming mode
            {
                
                if(app_boot_select_id)
                {
                    strcpy(message_buffer,"\r\n\r\n Programming mode is selected.\r\n Select the node ID in the below options. Once ID is selected, LED will be off. \r\n\r\n ***Make sure particular node is programmed with bootloader with this selected ID.*** \r\n \r\n *** IMPORTANT: After selecting node ID, disconnect Terminal and run the python script for programming bin file.***  \r\n\r\n Select the node ID for bootloader: \r\n1.0x45A \r\n2.0x45B \r\n");
                 APP_USB_WriteMessage(message_buffer);
                app_boot_select_id=0;
                }
                
                 if(app_buffer_read[5] == 0x31 || app_buffer_read[5] == 0x32)
                 {
                     app_boot_program_initialize=1;  
                     if(app_buffer_read[5]==0x31)
                     {
                         can_id=1114;
                      
                     }
                     if(app_buffer_read[5]==0x32)
                     {
                         can_id=1115;
                     
                     }
                     app_buffer_read[5] ='\0';         
                 }
                
                if(app_boot_program_initialize)
                {        
                APP_Boot_Initialize();
                /* Set CAN1 Message RAM Configuration */
                CAN1_MessageRAMConfigSet(can1MessageRAM);
                app_boot_programming_enable =1;
                app_boot_program_initialize =0; 
                }
                break;
                }
            
            if(app_boot_programming_enable == 0 )
            {
            /* Schedule write only if a valid CAN data was processed */
            if (COMMON_APP_CAN_Rx_DataIsReady()) {
              
                if (APP_USB_StateReset()) {
                break;
            }
            APP_CAN_data_logging();   
                break;     
            }
            }
        
        case APP_USB_STATE_WAIT_FOR_WRITE_COMPLETE:

            if (APP_USB_StateReset()) {
                break;
            }
            app_usbData.state = APP_USB_STATE_IDLE;

            break;

        case APP_USB_STATE_IDLE:
     
            if (COMMON_APP_CAN_Rx_DataIsReady()|| (rx_character ==1)||(app_boot_read == 1))
            {
                app_usbData.state = APP_USB_STATE_SCHEDULE_WRITE;
                break;
            }
           
            app_usbData.state = APP_USB_STATE_SCHEDULE_READ;
           
            break;
            
        case APP_USB_STATE_ERROR:
        default:

            break;
    }
}

/*******************************************************************************
 End of File
 */
