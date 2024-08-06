/**
 * \file rnbd.h
 * \brief This file contains APIs to access features support by RNBD series devices.
 */
/*
    (c) 2023 Microchip Technology Inc. and its subsidiaries.
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/
#ifndef RNBD_H
#define	RNBD_H

#include <stdbool.h>
#include <stdint.h>
   

/**
 * \ingroup RNBD
 * \brief This macro defines the time needed to place RNBD device in reset.
 */
#define RNBD_RESET_DELAY_TIME         (1)

/**
 * \ingroup RNBD
 * \brief This macro defines the RNBD boot time.
 */
#define RNBD_STARTUP_DELAY            (200)

//Convert nibble to ASCII
#define NIBBLE2ASCII(nibble) ((((nibble) < (uint8_t)0x0A) ? ((nibble) + (uint8_t)'0') : ((nibble) + (uint8_t)0x57)))

/**
  Section: Data Type Definitions
*/
typedef enum
{
    SET_IO_CAP_0,    //No input no output with bonding
    SET_IO_CAP_1,    //Display YesNo
    SET_IO_CAP_2,    //No input no output
    SET_IO_CAP_3,    //Key board only
    SET_IO_CAP_4,    //Display only
    SET_IO_CAP_5,    //Keyboard display
}RNBD_SET_IO_CAPABILITY_t;

typedef enum
{
    BR_921600,
    BR_460800,
    BR_230400,
    BR_115200,
    BR_57600,
    BR_38400,
    BR_28800,
    BR_19200,
    BR_14400,
    BR_9600,
    BR_4800,
    BR_2400,
}RNBD_BAUDRATE_t;

typedef enum
{
    RND_ENABLE_FLOW_CONTROL = 0x8000,
    RND_NO_PROMPT = 0x4000,
    RND_FAST_MODE = 0x2000,
    RND_NO_BEACON_SCAN = 0x1000,
    RND_NO_CONNECT_SCAN = 0x0800,
    RND_NO_DUPLICATE_SCAN_RESULT_FILTER = 0x0400,
    RND_PASSIVE_SCAN = 0x0200,
    RND_UART_TRANSPARENT_WITHOUT_ACK = 0x0100,
    RND_REBOOT_AFTER_DISCONNECTION = 0x0080,
    RND_RUNNING_SCRIPT_AFTER_POWER_ON = 0x0040,
    RND_SUPPORT_RN4020_MLDP_STREAMING_SERVICE = 0x0020,
    RND_DATA_LENGTH_EXTENSION = 0x0010,
    RND_COMMAND_MODE_GUARD = 0x0008,
}RNBD_FEATURES_BITMAP_t;

typedef enum
{
    SF_1 = 1,   //Reset to factory default
    //SF_2 = 2,   //Reset to factory default including private services and script
}RNBD_FACTORY_RESET_MODE_t;

typedef enum
{
    SS_DEVICE_INFO = 0X80,
    SS_UART_TRANSPARENT = 0x40,
    SS_BEACON = 0x20,
    SS_RESERVED = 0x10,
}RNBD_DEFAULT_SERVICE_BITMAP_t;

/**
 * \ingroup RNBD
 * Union of RNBD gpio BEHAVIOR state (Input/Output)
 * Bits (pins) set as (1) are considered OUTPUTS
 */
typedef union
{
    uint8_t gpioBitMap;
    struct
    {
        unsigned p2_2 : 1;          // 01
        unsigned p2_4 : 1;          // 02
        unsigned p3_5 : 1;          // 04
        unsigned p1_2 : 1;          // 08
        unsigned p1_3 : 1;          // 10
        unsigned reserved : 3;
    };
}RNBD_gpio_ioBitMap_t;

/**
 * \ingroup RNBD
 * Union of RNBD gpio OUTPUT state (High/Low)
 * Bits (states) set as (1) are considered HIGH
 */
typedef union
{
    uint8_t gpioStateBitMap;
    struct
    {
        unsigned p2_2_state : 1;
        unsigned p2_4_state : 1;
        unsigned p3_5_state : 1;
        unsigned p1_2_state : 1;
        unsigned p1_3_state : 1;
        unsigned reserved : 3;
    };
}RNBD_gpio_stateBitMap_t;

/**
 * \ingroup RNBD
 * Union of RNBD gpio state & configuration
 * Used for I/O (|) related commands
 */
typedef union 
{
    uint16_t gpioMap;
    struct
    {
        RNBD_gpio_ioBitMap_t ioBitMap;
        RNBD_gpio_stateBitMap_t ioStateBitMap;
    };
}RNBD_gpio_bitmap_t;

 /**
  * \ingroup RNBD
  * \brief Initializes RNBD Device
  * 
  * This API initializes RNBD Device.
  * 
  * \return Initialization Status.
  * \retval true - Success
  * \retval false - Failure.
  */
bool RNBD_Init(void);

 /**
  * \ingroup RNBD
  * \brief Sends out command to RNBD.
  *
  * This API takes command and its length as input and sends that command 
  * to RNBD.
  * 
  * \param cmd RNBD command
  * \param cmdLen RNBD command length
  * \return Nothing
  */
void RNBD_SendCmd(const char *cmd, uint8_t cmdLen);

/**
 * \ingroup RNBD
 * \brief Gets config value from RNBD by sending get command
 * 
 * This API gets the config value from RNBD by sending get command.
 * For more details, refer GET COMMANDS in RNBD user guide.
 * 
 * \param getCmd Get command to send
 * \param getCmdLen Get command length
 * \param getCmdResp Buffer to store get command response
 * 
 * \return Length of get command response.
 * \retval index - tracked command response length.
 */
uint8_t RNBD_GetCmd(const char *getCmd, uint8_t getCmdLen);

 /**
  * \ingroup RNBD
  * \brief Reads specific message from RNBD.
  * 
  * This API takes input from application on the expected response/status 
  * message. It starts read RNBD host interface immediately and look for 
  * expected message.
  * 
  * \param expectedMsg Expected response/status message from RNBD
  * \param msgLen Expected response/status message length.
  * \return Message Match Status
  * \retval true - Expected Message Received
  * \retval false - Otherwise
  */
bool RNBD_ReadMsg(const char *expectedMsg, uint8_t msgLen);

 /**
  * \ingroup RNBD
  * \brief Reads default response from RNBD.
  * 
  * This API reads RNBD interface for default response which is AOK or ERR.
  * 
  * \return Response Status
  * \retval true - Default Response Received
  * \retval false - Otherwise
  */
bool RNBD_ReadDefaultResponse(void);

 /**
  * \ingroup RNBD
  * \brief Puts the RNBD in user defined mode (Command Mode/Data Mode/ Set commands etc..).
  * 
  * This API puts the RNBD in user defined mode (Command Mode/Data Mode/ Set commands etc..). 
  * 
  * \return User Defined Mode Status
  * \retval true - Success
  * \retval false - Failure

  * Paramater 1 - Command to be sent
  * Parameter 2 - Length of Command to be sent
  * Parameter 3 - Expected Response message 
  * Parameter 4 - Expected Response length 
  */
bool RNBD_SendCommand_ReceiveResponse(const char *cmdMsg, uint8_t cmdLen, const char *responsemsg, uint8_t responseLen);
/**
  * \ingroup RNBD
  * \brief Puts the RNBD in command mode.
  * 
  * This API puts the RNBD in command mode. 
  * 
  * \return Command Mode Status
  * \retval true - Success
  * \retval false - Failure
  */
bool RNBD_EnterCmdMode(void);
 /**
  * \ingroup RNBD
  * \brief Puts the RNBD in data mode.
  * 
  * This API puts the RNBD in data mode.
  * 
  * \return Data Mode Status
  * \retval true - Success
  * \retval false - Failure
  */
bool RNBD_EnterDataMode(void);

 /**
  * \ingroup RNBD
  * \brief Resets RNBD.
  * 
  * This API resets RNBD. For more details, refer R command in 
  * RNBD user guide.
  * 
  * \return Reboot Status
  * \retval true - Success
  * \retval false - Failure
  */
bool RNBD_RebootCmd(void);

 /**
  * \ingroup RNBD
  * \brief Restores Factory Settings of RNBD module.
  * 
  * This API will issue a Factory Reset on the Module.
  * Restores all original module settings
  * For more details, refer R command in RNBD user guide.
  * 
  * \return Reboot Status
  * \retval true - Success
  * \retval false - Failure
  */
bool RNBD_FactoryReset(RNBD_FACTORY_RESET_MODE_t resetMode);

 /**
  * \ingroup RNBD
  * \brief Disconnects the BLE link between RNBD and remote device.
  * 
  * This API disconnects the BLE link between RNBD and remote device. 
  * For more details, refer K command in RN_BLE user guide.
  * \return Disconnect Status
  * \retval true - Success
  * \retval false - Failure
  */
bool RNBD_Disconnect(void);

 /**
  * \ingroup RNBD
  * \brief Sets up the Buffer and Buffer Size for Aysnc Message Handler
  * 
  * This API sets up the Buffer and the Buffer size to be used by the Async
  * Message Handler.
  * \param pBuffer Passed buffer
  * \param len Size of passed buffer 
  * \return Set Status
  * \retval true - Success
  * \retval false - Failure
  */
bool RNBD_SetAsyncMessageHandler(char* pBuffer, uint8_t len);

 /**
  * \ingroup RNBD
  * \brief Checks to see if there is Data Ready using Async Message Handling
  * 
  * This API checks to see if there is Data ready on the line using Async Message Handling.
  * This API follows the standard UART form.
  * \return Data Ready Status
  * \retval true - Data is ready
  * \retval false - Data is not ready
  */
bool RNBD_DataReady(void);

 /**
  * \ingroup RNBD
  * \brief Read incoming Data using Async Message Handling
  * 
  * This API reads incoming data using Async Message Handling.
  * This API follows the standard UART form.
  * \return Data Read
  */
uint8_t RNBD_Read(void);

/**
  * \ingroup RNBD

  * \brief Sets device name.
  * 
  * This routine sets the RNBD device name. For more details, refer SN
  * RNBD should be in command mode. 
  * 
  * \param name - Device name [20 alphanumeric characters max]
  * \param name - nameLen - Device name length
  * \return bool Status Result
  * \retval true - Sets device name
  * \retval false - Failure
  */
bool RNBD_SetName(const char *name, uint8_t nameLen);

 /**
  * \ingroup RNBD
  * \brief Sets Modules communication Baud Rate.
  * 
  * This routine sets the RNBD device Baud Rate. 
  * For more details, refer SN RNBD should be in command mode.
  * 
  * \param name - (2) character hex value coordinate to Command options 2.4.5
  * \return bool Status Result
  * \retval true - Sets device name
  * \retval false - Failure
  */
bool RNBD_SetBaudRate(uint8_t baudRate);

 /**
  * \ingroup RNBD
  * \Sets the default supported services in RNBD.
  * 
  * This routine sets the supported services bitmap in RNBD. 
  * The service flag values can be found in RNBD_DEFAULT_SERVICE_BITMAP_t. 
  * For more details, refer SS command in RNBD user guide.
  * 
  * \preconditions RNBD should be in command mode.
  * \param serviceBitmap - Supported services bitmap in RNBD 
  * \param name - nameLen - Device name length
  * \return bool Status Result
  * \retval true - Sets service bitmap
  * \retval false - Failure
  */
bool RNBD_SetServiceBitmap(uint8_t serviceBitmap);

 /**
  * \ingroup RNBD
  * \Sets the supported features of RNBD.
  * 
  * This routine sets the supported features bitmap of RNBD. 
  * The features list can be found in RNBD_FEATURES_BITMAP_t. 
  * For more details, refer SR command in RNBD user guide.
  * 
  * \preconditions RNBD should be in command mode.
  * \param featuresBitmap - Supported features bitmap in RNBD 
  * \return bool Status Result
  * \retval true - Sets features bitmap
  * \retval false - Failure
  */
bool RNBD_SetFeaturesBitmap(uint16_t featuresBitmap);

 /**
  * \ingroup RNBD
  * \Sets the IO capability of RNBD and the system.
  * 
  * This routine sets the IO capability of RNBD and the system. This will be 
  * used to determine BLE authentication method. The possible IO capabilities 
  * can be found in RND_SET_IO_CAPABILITY_t. For more details, refer SA 
  * command in RNBD user guide.
  * 
  * \preconditions RNBD should be in command mode.
  * \param ioCapability - IO capability of RNBD 
  * \return bool Status Result
  * \retval true - Sets IO capability
  * \retval false - Failure
  */
bool RNBD_SetIOCapability(uint8_t ioCapability);

 /**
  * \ingroup RNBD
  * \Sets the security pin code on RNBD.
  * 
  * This routine sets the security pin code on RNBD. It can be 4 bytes or 6 bytes 
  * in length. For more details, refer SP and SA command in RNBD user guide.
  * can be found in RND_SET_IO_CAPABILITY_t. For more details, refer SA 
  * command in RNBD user guide.
  * 
  * \preconditions RNBD should be in command mode.
  * \param pinCode - Security pin code
  * \param pinCodeLen - Security pin code length (4 or 6) 
  * \return bool Status Result
  * \retval true - Sets security pin code
  * \retval false - Failure
  */
bool RNBD_SetPinCode(const char *pinCode, uint8_t pinCodeLen);

 /**
  * \ingroup RNBD
  * \Sets status message delimiter on RNBD.
  * 
  * This routine sets the status message pre and post delimiters on RNBD.
  * Though the pre and post delimiters can be upto four ASCII characters, 
  * this API supports only single character pre and post delimiter.
  * For more details, refer S% command in RN_BLE user guide.
  * 
  * \preconditions RNBD should be in command mode.
  * \param preDelimiter - Character to be use for Pre-delimiter
  * \param postDelimiter - Character to be use for Post-delimiter
  * \return bool Status Result
  * \retval true - Delimiters are Set to new characters
  * \retval false - Failure
  */
bool RNBD_SetStatusMsgDelimiter(char preDelimiter, char postDelimiter);

 /**
  * \ingroup RNBD
  * \brief Configures RNBD GPIO pins as output, and sets state
  * 
  * This API configures the GPIO pins of the RNBD module as Outputs
  * This API configures the High/Low state of pins set as outputs
  * \param bitMap RNBD GPIO Output I/O & Low/High State
  * \return Set Output Status
  * \retval true - Success
  * \retval false - Failure
  */
bool RNBD_SetOutputs(RNBD_gpio_bitmap_t bitMap);

 /**
  * \ingroup RNBD
  * \brief Get RNBD GPIO pins input state status (high/low)
  * 
  * This API request the GPIO pins state from the RNBD module Inputs
  * This API reads specified GPIO pins current (high/low) state
  * 
  * \param getGPIOs RNBD pins to read state status from
  * \return GPIO State values
  * \retval RND_gpio_stateBitMap_t - 8bit value coordinated to possible pin options
  */
RNBD_gpio_stateBitMap_t RNBD_GetInputsValues(RNBD_gpio_ioBitMap_t getGPIOs);

 /**
  * \ingroup RNBD
  * \brief Gets Latest RSSI value.
  * 
  * This API gets the Latest RSSI value from RNBD. 
  * For more details, refer M command in RN_BLE user guide.
  * 
  * \return RSSI command response
  * \retval <RSSI>
  * \retval ERR - Not Connected to RNBD
  */
char * RNBD_GetRSSIValue(void);
 /**
  * \ingroup RNBD
  * \brief Sets StatusDelimter value.
  * 
  * This variable sets the RNBD devices PRE/POST status message delimiter. 
  * 
  * \return Nothing
  */
void RNBD_set_StatusDelimter(char Delimter_Character);
/**
  * \ingroup RNBD
  * \brief Get StatusDelimter value.
  * 
  * This variable gets the RNBD devices PRE/POST status message delimiter. 
  * 
  * \returns the current StatusDelimter value
  */
char RNBD_get_StatusDelimter(void);
/**
  * \ingroup RNBD
  * \brief Sets the No Delimter check during HOST OTA Update.
  * 
  * This variable is used to set and not setting the Delimter check . 
  * 
  * \returns Nothing
  */
void RNBD_set_NoDelimter(bool value);
/**
  * \ingroup RNBD
  * \brief Returns the current status No Delimter status.
  * 
  * This variable return true or false current status No Delimter status. 
  * 
  * \returns true or false 
  */
bool RNBD_get_NoDelimter(void);
#endif	/* RNBD_H */