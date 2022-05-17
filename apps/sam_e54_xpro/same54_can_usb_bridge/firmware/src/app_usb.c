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

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

uint8_t CACHE_ALIGN cdcReadBuffer[APP_USB_READ_BUFFER_SIZE];
uint8_t CACHE_ALIGN cdcWriteBuffer[APP_USB_WRITE_BUFFER_SIZE];

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_USB_Initialize function.

    Application strings and buffers are be defined outside this structure.
 */

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
/* CAN DLC To data Length

   Summary:
    Holds length of the data according to CAN protocol 

   Description:
    From the DLC field, get the length of the data.

   Remarks:
    None.
*/

static uint8_t CANDlcToLengthGet(uint8_t dlc)
{
    uint8_t msgLength[] = {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 12U, 16U, 20U, 24U, 32U, 48U, 64U};
    return msgLength[dlc];
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
    app_usbData.getLineCodingData.dwDTERate = 9600;
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

    /* Set up the read buffer */
    app_usbData.cdcWriteBuffer = &cdcWriteBuffer[0];
}

/*******************************************************************************
  Function:
    void APP_USB_Tasks ( void )

  Remarks:
    See prototype in app_usb.h.
 */

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

#ifdef read //Remove if you need to read USB input from user
        case APP_USB_STATE_SCHEDULE_READ:

            if (APP_USB_StateReset()) {
                break;
            }

            /* If a read is complete, then schedule a read
             * else wait for the current read to complete 
             */
            app_usbData.state = APP_USB_STATE_WAIT_FOR_READ_COMPLETE;

            if (app_usbData.isReadComplete == true) {
                app_usbData.isReadComplete = false;
                app_usbData.readTransferHandle =
                        USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;

                /* Schedule read */
                USB_DEVICE_CDC_Read(USB_DEVICE_CDC_INDEX_0,
                        &app_usbData.readTransferHandle,
                        app_usbData.cdcReadBuffer,
                        APP_USB_READ_BUFFER_SIZE);

                if (app_usbData.readTransferHandle ==
                        USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID) {
                    app_usbData.state = APP_USB_STATE_ERROR;
                    break;
                }
            }

            break;

        case APP_USB_STATE_WAIT_FOR_READ_COMPLETE:

            if (APP_USB_StateReset()) {
                break;
            }

            /* Check if a character was received, The isReadComplete flag gets 
             * updated in the CDC event handler. 
             */
            if (app_usbData.isReadComplete) {
                app_usbData.state = APP_USB_STATE_IDLE;
            }
            
            /* To do something with read data, check this buffer's contents:
             * app_usbData.cdcReadBuffer
             */

            break;
#endif //Remove if you need to read USB input from user

        case APP_USB_STATE_SCHEDULE_WRITE:

            if (APP_USB_StateReset()) {
                break;
            }

            /* Schedule write only if a valid CAN data was processed */
            if (COMMON_APP_CAN_DataIsReady()) {
              
                
                app_usbData.isWriteComplete = false;
                app_usbData.writeTransferHandle =
                        USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;
                

                uint8_t msgLength = 0;
                uint32_t id = 0;
                uint8_t numberOfMessage =1; 
                for (uint8_t count = 0; count < numberOfMessage; count++)
                {
                id = ((CAN_RX_BUFFER *)COMMON_APP_CAN_GetData())->xtd ? ((CAN_RX_BUFFER *)COMMON_APP_CAN_GetData())->id : (((((CAN_RX_BUFFER *)COMMON_APP_CAN_GetData())->id))>>18);
                msgLength = CANDlcToLengthGet(((CAN_RX_BUFFER *)COMMON_APP_CAN_GetData())->dlc);
                app_usbData.numBytesWrite =  sprintf((char*)app_usbData.cdcWriteBuffer, "\r\n\n New Message Received \r\n ID :" "0x%x" " \r\n Length :" "0x%x bytes" "\r\n Data : " , (unsigned int)id, (unsigned int)msgLength);
                uint8_t temp= 0; 
                    for(int j=0;j< msgLength ;j++)   
                    {
                    temp = sprintf((char*)(app_usbData.cdcWriteBuffer + app_usbData.numBytesWrite), "0x%d ", ((CAN_RX_BUFFER *)COMMON_APP_CAN_GetData())->data[j] );
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
                
                COMMON_APP_CAN_DataStatus(false);
            } else {
                app_usbData.state = APP_USB_STATE_IDLE;
            }

            break;

        case APP_USB_STATE_WAIT_FOR_WRITE_COMPLETE:

            if (APP_USB_StateReset()) {
                break;
            }

            /* Check if a character was sent. The isWriteComplete
             * flag gets updated in the CDC event handler 
             */

            if (app_usbData.isWriteComplete == true) {
                app_usbData.state = APP_USB_STATE_IDLE;
            }

            break;

        case APP_USB_STATE_IDLE:
            /* Schedule something here based on conditions
             * For e.g.
             */
            app_usbData.state = APP_USB_STATE_SCHEDULE_WRITE;
            
            break;
            
        case APP_USB_STATE_ERROR:
        default:

            break;
    }
}

/*******************************************************************************
 End of File
 */
