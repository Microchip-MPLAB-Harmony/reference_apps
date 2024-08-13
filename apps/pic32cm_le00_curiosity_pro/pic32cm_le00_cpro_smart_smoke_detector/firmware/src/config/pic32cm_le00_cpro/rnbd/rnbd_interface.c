/**
 * \file rnbd_interface.c
 * \brief This file provides and interface between the RNBD and the hardware.
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
#include <string.h>
#include<stdio.h>
#include "rnbd_interface.h"
#include "definitions.h"

static bool connected = false,OTABegin = false, stream_open = false;//**< RNBD connection state */
static uint32_t delay_ms_cycles = CPU_CLOCK_FREQUENCY/1000; 
static uint8_t readbuffer[1];
static size_t dummyread=0;
static uint8_t cdcreadbuffer[1];

static char ReadData[100];

/* RNBD Packet Size = RN_PAYLOAD_SIZE + 19 (Header Size) */
static unsigned int decimalnumber=RN_PAYLOAD_SIZE + 19U;
static unsigned int temp;
static char hexa_Number[4]={'0','0','0','0'};
static unsigned long num = 0;
static unsigned int RN_Payload_Size=RN_PAYLOAD_SIZE;
static struct OTA_REQ_PARAMETER RNBD_OTA_Parameter;
    
/**
 * \ingroup RNBD_INTERFACE
 * \brief Converting the RNBD DATA Buffer Interger Value in to Hex Value of RNBD
 * 
 * This API is used to Convert RNBD Data Buffer Integer Value to Hexadecimal value to the RNBD.
 *
 * 
 * \param value Nothing
 * \return Nothing
 */
static void RNBD_Convert_DataBufferValue_Integer_to_Hexadecimal(void);

/**
 * \ingroup RNBD_INTERFACE
 * \brief Converting the RNBD DATA Buffer Interger Value in to Hex Value of RNBD
 * 
 * This API is used to Convert RNBD Data Buffer Integer Value to Hexadecimal value to the RNBD.
 *
 * 
 * \param1 Buffer received from RNBD message handler
 * \param2 Setting up the start point of Buffer
 * \param3 Number of bytes to read
 * \return long value
 */
static unsigned long RNBD_Split_OTA_REQ_Parameter(char buffer[],unsigned int arrayindex, unsigned int length);

/**
 * \ingroup RNBD_INTERFACE
 * \brief Initiate Hardware Reset of RNBD
 * 
 * This API is used to issue a hardware Reset to the RNBD.
 *
 * 
 * \param value true - Reset State false - Normal State
 * \return Nothing
 */
static void RNBD_Reset(bool value);

/**
 * \ingroup RNBD_INTERFACE
 * \brief Notify RNBD to expect incoming data
 * 
 * This API notifies the RNBD Device to expect incoming Data.
 * 
 * \param value true - RX Incoming false - No Data Incoming
 * \return Nothing
 * 
 */
static void RNBD_IndicateRx(bool value);

/**
 * \ingroup RNBD_INTERFACE
 * \brief Set the RNBD System Configuration Mode
 * 
 * This API sets the System Configuration Mode to Either Normal application Mode 
 * or Test Mode/Flash Update/EEPROM configuration
 * 
 * \param mode APPLICATION_MODE - Normal Application Mode TEST_MODE - Test Mode/Flash Update/EEPROM Configuration
 * \return Nothing
 */
static void RNBD_SetSystemMode(RNBD_SYSTEM_MODES_t mode);

/**
 * \ingroup RNBD_INTERFACE
 * \brief Handle RNBD Status Message
 * 
 * This API is used to handle incoming status messages.
 * It prints all status messages, If DISCONNECT or STREAM_OPEN is received it manages
 * the state of bool connected.
 * 
 * \param message Passed status message
 * \return Nothing
 */
static void RNBD_MessageHandler(char* message);

/**
 * \ingroup RNBD_INTERFACE
 * \brief Write API transmitting to RNBD module
 * 
 * This API is used to send data bytes to the RNBD module
 *
 * HINT: This API is in place to give compile time memory allocation.
 *       Functionality exist locally within file.
 *       Use of IN LINE to prevent additional stack depth requirement. 
 *       APIs can be injected in place if suitable to save (1) stack depth level
 * 
 * \param txData - data byte to send
 * \return Nothing
 */
static inline void RNBD_Write(uint8_t txData);

/**
 * \ingroup RNBD_INTERFACE
 * \brief Read API to capture data bytes from RNBD module
 * 
 * This API is used to receive data bytes to the RNBD module
 *
 * HINT: This API is in place to give compile time memory allocation.
 *       Functionality exist locally within file.
 *       Use of IN LINE to prevent additional stack depth requirement. 
 *       APIs can be injected in place if suitable to save (1) stack depth level
 * 
 * \param N/A
 * \return uint8_t readDataByte - Byte captured from RNBD module
 */
static inline uint8_t RNBD_read(void);

/**
 * \ingroup RNBD_INTERFACE
 * \brief Returns if Write to RNBD module was completed
 * 
 * This API is used to receive status of communication with RNBD module
 *
 * HINT: This API is in place to give compile time memory allocation.
 *       Functionality exist locally within file.
 *       Use of IN LINE to prevent additional stack depth requirement. 
 *       APIs can be injected in place if suitable to save (1) stack depth level
 * 
 * \param N/A
 * \return bool status - RNBD is ready for another data byte
 */
static inline bool RNBD_is_tx_done(void);

/**
 * \ingroup RNBD_INTERFACE
 * \brief Returns if Read from RNBD module is ready
 * 
 * This API is used to receive status of communication with RNBD module
 *
 * HINT: This API is in place to give compile time memory allocation.
 *       Functionality exist locally within file.
 *       Use of IN LINE to prevent additional stack depth requirement. 
 *       APIs can be injected in place if suitable to save (1) stack depth level
 * 
 * \param N/A
 * \return bool status - RNBD is ready to provide another byte
 */
static inline bool RNBD_is_rx_ready(void);

/**
 * \ingroup RNBD_INTERFACE
 * \brief Returns if Read from RNBD module is ready
 * 
 * This API is used to receive status of communication with RNBD module
 *
 * HINT: This API is in place to give compile time memory allocation.
 *       Functionality exist locally within file.
 *       Use of IN LINE to prevent additional stack depth requirement. 
 *       APIs can be injected in place if suitable to save (1) stack depth level
 * 
 * \param N/A
 * \return bool status - RNBD is ready to provide another byte
 */
static inline void RNBD_Delay(uint32_t delayCount);
/*****************************************************
*   *OPTIONAL* APPLICATION MESSAGE FORMATTING API(s)
******************************************************/  
/**
 * \ingroup RNBD_MESSAGE_TYPE
 * Enum of the MESSAGE TYPES supported in Driver Example(s)
 */
typedef enum 
{
    DISCONNECT_MSG  = 0,
    STREAM_OPEN_MSG = 1,
    GENERAL_MSG     = 2,
}RNBD_MESSAGE_TYPE;
/**
 * \def GENERAL_PRINT_SIZE_LIMIT
 * This macro provide a definition used to process 
 */
#define GENERAL_PRINT_SIZE_LIMIT        (100)
/**
 * \ingroup RNBD_MESSAGE
 * \brief Prints the START Message "<<< " for UART_CDC
 * 
 * This API prints *Optional Application* Messages
 *
 * \param N/A
 * \return N/A
 */
static inline void RNBD_PrintMessageStart(void);
/**
 * \ingroup RNBD_MESSAGE
 * \brief Prints the END Message ">>>\r\n" for UART_CDC
 * 
 * This API prints *Optional Application* Messages
 *
 * \param N/A
 * \return N/A
 */
static inline void RNBD_PrintMessageEnd(void);
/**
 * \ingroup RNBD_MESSAGE
 * \brief Prints the Indicator [ or ] to UART_CDC
 *        [ - Disconnected | ] - Connected
 * 
 * This API prints *Optional Application* Messages
 *
 * \param N/A
 * \return N/A
 */
static inline void RNBD_PrintIndicatorCharacters(RNBD_MESSAGE_TYPE msgType);
/**
 * \ingroup RNBD_MESSAGE
 * 
 * This API prints *Optional Application* Messages
 *
 * \param N/A
 * \return N/A
 */
static inline void RNBD_PrintMessage(char* passedMessage);
/*****************************************************
*   Driver Instance Declaration(s) API(s)
******************************************************/  

const iRNBD_FunctionPtrs_t RNBD = {
    .Write = RNBD_Write,
    .Read = RNBD_read,
    .TransmitDone = RNBD_is_tx_done,
    .DataReady = RNBD_is_rx_ready,
    .IndicateRx = RNBD_IndicateRx,
    .ResetModule = RNBD_Reset,
    .SetSystemMode = RNBD_SetSystemMode,
    .DelayMs = RNBD_Delay,
    .AsyncHandler = RNBD_MessageHandler
};


/*****************************************************
*   Driver Public API
******************************************************/  

static void RNBD_Convert_DataBufferValue_Integer_to_Hexadecimal(void)
{
	uint8_t hex_incr=0;
	while (decimalnumber != 0U) {
        temp = decimalnumber / 16U;
		unsigned int r = temp * 16U;
        temp = decimalnumber - r;
        
        // converting decimal number in to a hexa decimal number
        if (temp < 10U)
		{
            temp = temp + 48U;
		}
        else
		{
            temp = temp + 55U;
		}
        hexa_Number[hex_incr++] = (char)temp;
        decimalnumber = decimalnumber / 16U;
    }
}

static unsigned long RNBD_Split_OTA_REQ_Parameter(char buffer[],unsigned int arrayindex, unsigned int length)
{
    unsigned int j=0,ota_req_incr=0;
    ota_req_incr=arrayindex;
	
    while(j<length)
    {
         num <<=8U;  // shift by a complete byte, equal to num *= 256
        num |= (unsigned char)buffer[ota_req_incr++];  // write the respective byte
        j++;
    }
	return num;
}

bool RNBD_IsConnected(void)
{
    return connected;
}

bool RNBD_IsOTABegin(void)
{
    return OTABegin;
}

bool RNBD_IsStreamopen(void)
{
    return stream_open;
}

/*****************************************************
*   Driver Implementation Private API(s)
******************************************************/  

static inline void RNBD_Write(uint8_t txData)
{
    UART_BLE_write(txData);
}

static inline uint8_t RNBD_read(void)
{
    return UART_BLE_Read();
     
}

static inline bool RNBD_is_tx_done(void)
{
    return (UART_BLE_TransmitDone());
}

static inline bool RNBD_is_rx_ready(void)
{
    return UART_BLE_DataReady()!=0U;
}


uint8_t UART_CDC_Read(void)
{    
    return *(uint8_t*)cdcreadbuffer;
}
void UART_CDC_write(uint8_t buffer)
{
}
size_t UART_CDC_DataReady(void)
{
}
uint8_t UART_BLE_Read(void)
{
    dummyread=SERCOM2_USART_Read(readbuffer,1);
    return *(uint8_t*)readbuffer;
}

void UART_BLE_write(uint8_t buffer)
{
    dummyread=SERCOM2_USART_Write(&buffer, 1);
}

size_t UART_BLE_DataReady(void)
{
    return SERCOM2_USART_ReadCountGet();
}

bool UART_BLE_TransmitDone(void)
{
    return SERCOM2_USART_WriteCountGet()!=0U? false:true;
}

static inline void RNBD_Delay(uint32_t delayCount)
{
    if(delayCount > 0U)
    {
        delayCount *= delay_ms_cycles;
        while(delayCount > 0U)
        {
			delayCount--;
            __NOP();
        }
    }
}

static void RNBD_Reset(bool value)
{
    if (true == value)
    {
        BT_RST_Clear();
    }
    else
    {
        BT_RST_Set();
    }
}

static void RNBD_IndicateRx(bool value)
{
    // Implement desired support code for RX Indicator
}

static void RNBD_SetSystemMode(RNBD_SYSTEM_MODES_t mode)
{
    // Implement desired support code for system Mode
}

/*****************************************************
*   *Optional* Message Formatting Private API(s)
******************************************************/  
static inline void RNBD_PrintMessageStart(void)
{
    UART_CDC_write((uint8_t)'<');
    UART_CDC_write((uint8_t)'<');
    UART_CDC_write((uint8_t)'<');
    UART_CDC_write((uint8_t)' ');
}
static inline void RNBD_PrintMessageEnd(void)
{
    UART_CDC_write((uint8_t)' ');
    UART_CDC_write((uint8_t)'>');
    UART_CDC_write((uint8_t)'>');
    UART_CDC_write((uint8_t)'>');
    UART_CDC_write((uint8_t)' ');
    UART_CDC_write((uint8_t)'\r');
    UART_CDC_write((uint8_t)'\n');
}
static inline void RNBD_PrintIndicatorCharacters(RNBD_MESSAGE_TYPE msgType)
{
    if (DISCONNECT_MSG == msgType)
    {
        UART_CDC_write((uint8_t)'[');
    }
    else if (STREAM_OPEN_MSG == msgType)
    {
        UART_CDC_write((uint8_t)']');
    }
    else
    {
		// Left Intentionally Blank: For General Messages
    }
}
static inline void RNBD_PrintMessage(char* passedMessage)
{
    char printCharacter [GENERAL_PRINT_SIZE_LIMIT];
    (void)strcpy(printCharacter, passedMessage);
    for (uint8_t messageIndex = 0; messageIndex < strlen(passedMessage); messageIndex++)
    {
       UART_CDC_write((uint8_t)printCharacter[messageIndex]);  
    }
}

static void RNBD_MessageHandler(char* message)
{
	RNBD_Convert_DataBufferValue_Integer_to_Hexadecimal();
	
    RNBD_MESSAGE_TYPE messageType = GENERAL_MSG;
    RNBD_PrintMessageStart();



    if (strstr(message, "DISCONNECT")!= NULL)
    {
        messageType = DISCONNECT_MSG;
        connected = false;
        OTABegin = false;
        stream_open = false;
    }
    else if (strstr(message, "STREAM_OPEN")!= NULL)
    {
        messageType = STREAM_OPEN_MSG;
        stream_open = true;
    }
    else if (strstr(message, "OTA_REQ")!= NULL)
    {		
		stream_open = false;
		for(uint8_t read_data_incr=0;read_data_incr<49U;read_data_incr++)
        {
            ReadData[read_data_incr]=*message;
            message++;
        }
		
		RNBD_OTA_Parameter.connection_handle = RNBD_Split_OTA_REQ_Parameter(ReadData,8,4);
        RNBD_OTA_Parameter.total_image_size = RNBD_Split_OTA_REQ_Parameter(ReadData,13,8);
        RNBD_OTA_Parameter.image_ID = RNBD_Split_OTA_REQ_Parameter(ReadData,22,8);
        RNBD_OTA_Parameter.image_version = (unsigned int)RNBD_Split_OTA_REQ_Parameter(ReadData,31,8);
        RNBD_OTA_Parameter.fwimage_checksum = (unsigned int)RNBD_Split_OTA_REQ_Parameter(ReadData,40,4);
        RNBD_OTA_Parameter.fwimage_crc16 = (unsigned int)RNBD_Split_OTA_REQ_Parameter(ReadData,45,4);
		
		if(RN_Payload_Size == 237U)
		{
			RNBD.Write('O');
			RNBD.Write('T');
			RNBD.Write('A');
			RNBD.Write('A');
			RNBD.Write(',');
			RNBD.Write('0');
			RNBD.Write('1');
			RNBD.Write('\r');
			RNBD.Write('\n');
		}
		else{
			RNBD.Write('O');
			RNBD.Write('T');
			RNBD.Write('A');
			RNBD.Write('A');
			RNBD.Write(',');
			RNBD.Write('0');
			RNBD.Write('1');
			RNBD.Write(',');
			RNBD.Write('0');
			RNBD.Write(hexa_Number[2]);
			RNBD.Write(hexa_Number[1]);
			RNBD.Write(hexa_Number[0]);
			RNBD.Write('\r');
			RNBD.Write('\n');  
		}
		
          
    }
	else if (strstr(message, "OTA_START")!= NULL)
    {
        OTABegin = true;
		stream_open = false;
    }
	else if (strstr(message, "CONNECT")!= NULL)
    {
        connected = true;
    }
    else
    {
        messageType = GENERAL_MSG;
    }
    RNBD_PrintMessage(message);
    RNBD_PrintMessageEnd();
    RNBD_PrintIndicatorCharacters(messageType);
}
