/** \file rnbd.c
 *  \brief This file contains APIs to access features support by RNBD series devices.
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

#include "rnbd.h"
#include "rnbd/rnbd_interface.h"
#include "definitions.h" 
#include <string.h>
#include <stddef.h>
#include <stdlib.h> 

/* This value depends upon the System Clock Frequency, Baudrate value and Error percentage of Baudrate*/
#define RESPONSE_TIMEOUT 65U 
/**
 * \def STATUS_MESSAGE_DELIMITER
 * This Variable provide a definition of the RNBD devices PRE/POST status message delimiter.
 */
static char STATUS_MESSAGE_DELIMITER = '%';

static bool skip_Delimter = false;
static char cmdBuf[64];                                /**< Command TX Buffer */
static uint8_t dummyread;

static char *asyncBuffer;                           /**< Async Message Buffer */
static uint8_t asyncBufferSize;                     /**< Size of the Async Message Buffer */
static char *pHead;                                 /**< Pointer to the Head of the Async Message Buffer */
static uint8_t peek = 0;                            /**< Recieved Non-Status Message Data */
static bool dataReady = false;                      /**< Flag which indicates whether Non-Status Message Data is ready */
static char resp[100];

/**
 * \brief This function filters status messages from RNBD data.
 * \param void This function takes no params.
 * \return a boolean value
 * \retval dataReady Returns true if data is ready; false otherwise.
 */
static bool RNBD_FilterData(void);

bool RNBD_Init(void)
{
    //Enter reset
    RNBD.ResetModule(true);
    //Wait for Reset
    RNBD.DelayMs(RNBD_RESET_DELAY_TIME);
    //Exit reset
    RNBD.ResetModule(false);

    //Wait while RN Device is booting up
    RNBD.DelayMs(RNBD_STARTUP_DELAY);

    //Remove unread data sent by RNBD, if any
    while (RNBD.DataReady())
    {
        dummyread=RNBD.Read();
    }
    
    return true;
}

void RNBD_SendCmd(const char *cmd, uint8_t cmdLen)
{
    uint8_t index = 0;

	do{
        if (RNBD.TransmitDone())
        {
            RNBD.Write(cmd[index]);
            index++;
        }
    }
    while(index < cmdLen);
    while(!RNBD.TransmitDone()){}
}

uint8_t RNBD_GetCmd(const char *getCmd, uint8_t getCmdLen)
{
    uint8_t index = 0, ResponseTime=0;

    RNBD_SendCmd(getCmd, getCmdLen);

	//Wait for the response time
    while(!RNBD.DataReady() && ResponseTime<=RESPONSE_TIMEOUT)
    {
        RNBD.DelayMs(1);
        ResponseTime++;
    }
    do
    {
        //Read Ready data 
        if(RNBD.DataReady())
        {
            resp[index]=(char)RNBD.Read();
            if(resp[index] != '>')
            {
                index++;
            }
            else
            {
                return index;
            }
        } 
    }
    while ((index!=0U) && (index<255U));

    return index;
}

bool RNBD_ReadMsg(const char *expectedMsg, uint8_t msgLen)
{
	unsigned int ResponseRead=0,ResponseTime=0,ResponseCheck=0;
	//Wait for the response time
    while(!RNBD.DataReady() || ResponseTime<=RESPONSE_TIMEOUT)
    {
        RNBD.DelayMs(1);
        ResponseTime++;
    }
    
    //Read Ready data 
    while(RNBD.DataReady())
    {
        resp[ResponseRead]=(char)RNBD.Read();
		UART_CDC_write((uint8_t)resp[ResponseRead]);
        ResponseRead++;
    }
	//Comparing length of response expected
    if (ResponseRead != msgLen)
    {
        return false;
    }
    //Comparing the Response with expected result
    for(ResponseCheck=0;ResponseCheck<ResponseRead;ResponseCheck++)
    {
        if (resp[ResponseCheck] != expectedMsg[ResponseCheck])
        {
            return false;
        }
    }

    return true;
}

bool RNBD_ReadDefaultResponse(void)
{
    char DefaultResponse[30];
    bool status = false;
    unsigned int ResponseWait=0,DataReadcount=0;
    while(!RNBD.DataReady() || ResponseWait<=RESPONSE_TIMEOUT)
    {
        RNBD.DelayMs(1);
        ResponseWait++;
    }
    while(RNBD.DataReady())
    {
        DefaultResponse[DataReadcount]=(char)RNBD.Read();
		UART_CDC_write((uint8_t)DefaultResponse[DataReadcount]);
        DataReadcount++;
    }
    switch (DefaultResponse[0])
    {
        case 'A':
        {
            if ((DefaultResponse[1] == 'O') && (DefaultResponse[2] == 'K'))
            {
                status = true;
            }

            break;
        }
        case 'E':
        {
            if ((DefaultResponse[1] == 'r') && (DefaultResponse[2] == 'r'))
            {
                status = false;
            }

            break;
        }
        default:
        {
			//Returns the status as default case
            break;
        }
    }


  
    return status;
}
bool RNBD_SendCommand_ReceiveResponse(const char *cmdMsg, uint8_t cmdLen, const char *responsemsg, uint8_t responseLen)
{
    unsigned int ResponseRead=0,ResponseTime=0,ResponseCheck=0;
    //Flush out any unread data
    while (RNBD.DataReady())
    {
        (void)RNBD.Read();
    }
    //Sending Command to UART
    RNBD_SendCmd(cmdMsg, cmdLen);
    //Wait for the response time
    while(!RNBD.DataReady() || ResponseTime<=RESPONSE_TIMEOUT)
    {
        RNBD.DelayMs(1);
        ResponseTime++;
    }
    //Read Ready data 
    while(RNBD.DataReady())
    {
        resp[ResponseRead]=(char)RNBD.Read();
		UART_CDC_write((uint8_t)resp[ResponseRead]);
        ResponseRead++;
    }
	//Comparing length of response expected
    if (ResponseRead != responseLen)
    {
        return false;
    }
    //Comparing the Response with expected result
    for(ResponseCheck=0;ResponseCheck<ResponseRead;ResponseCheck++)
    {
        if (resp[ResponseCheck] != responsemsg[ResponseCheck])
        {
            return false;
        }
    }
    return true;
}
bool RNBD_EnterCmdMode(void)
{
    const char cmdModeResponse[] = {'C', 'M', 'D', '>', ' '};
	cmdBuf[0] = '$';
    cmdBuf[1] = '$';
    cmdBuf[2] = '$';
    return RNBD_SendCommand_ReceiveResponse(cmdBuf, 3U, cmdModeResponse,5U);
}
bool RNBD_EnterDataMode(void)
{
    const char dataModeResponse[] = {'E', 'N', 'D', '\r', '\n'};
	cmdBuf[0] = '-';
    cmdBuf[1] = '-';
    cmdBuf[2] = '-';
    cmdBuf[3] = '\r';
    cmdBuf[4] = '\n';
    return RNBD_SendCommand_ReceiveResponse(cmdBuf, 5U, dataModeResponse,5U);
}




bool RNBD_SetName(const char *name, uint8_t nameLen)
{
    uint8_t index;
	const char cmdPrompt[] = {'A', 'O', 'K', '\r', '\n', 'C', 'M', 'D', '>', ' '};

    cmdBuf[0] = 'S';
    cmdBuf[1] = 'N';
    cmdBuf[2] = ',';

    for (index = 0; index < nameLen; index++)
    {
        cmdBuf[3U + index] = name[index];
    }
    index = index + 3U;

    cmdBuf[index++] = '\r';
    cmdBuf[index] = '\n';

    return RNBD_SendCommand_ReceiveResponse(cmdBuf, nameLen + 5U, cmdPrompt, 10U);

}

bool RNBD_SetBaudRate(uint8_t baudRate)
{
	uint8_t temp = (baudRate >> 4U);
	const char cmdPrompt[] = {'A', 'O', 'K', '\r', '\n', 'C', 'M', 'D', '>', ' '};
    cmdBuf[0] = 'S';
    cmdBuf[1] = 'B';
    cmdBuf[2] = ',';
	temp=NIBBLE2ASCII(temp);
    cmdBuf[3] = (char)temp;
	temp = (baudRate & (uint8_t)0x0F);
    temp=NIBBLE2ASCII(temp);
    cmdBuf[4] = (char)temp;
    cmdBuf[5] = '\r';
    cmdBuf[6] = '\n';


	return RNBD_SendCommand_ReceiveResponse(cmdBuf, 7U, cmdPrompt, 10);
}

bool RNBD_SetServiceBitmap(uint8_t serviceBitmap)
{
	const char cmdPrompt[] = {'A', 'O', 'K', '\r', '\n', 'C', 'M', 'D', '>', ' '};
    uint8_t temp = (serviceBitmap >> 4);

    cmdBuf[0] = 'S';
    cmdBuf[1] = 'S';
    cmdBuf[2] = ',';
	temp=(NIBBLE2ASCII(temp));
    cmdBuf[3] = (char)temp;
    temp = (serviceBitmap & (uint8_t)0x0F);
    temp=(NIBBLE2ASCII(temp));
    cmdBuf[4] = (char)temp;
    cmdBuf[5] = '\r';
    cmdBuf[6] = '\n';


	return RNBD_SendCommand_ReceiveResponse(cmdBuf, 7U, cmdPrompt, 10U);
}

bool RNBD_SetFeaturesBitmap(uint16_t featuresBitmap)
{
	const char cmdPrompt[] = {'A', 'O', 'K', '\r', '\n', 'C', 'M', 'D', '>', ' '};
    uint8_t temp = (uint8_t) (featuresBitmap >> 12U);

    cmdBuf[0] = 'S';
    cmdBuf[1] = 'R';
    cmdBuf[2] = ',';
    temp = temp & (uint8_t)0x0F;
    temp=(NIBBLE2ASCII(temp));
    cmdBuf[3] = (char)temp;
    temp = (uint8_t) (featuresBitmap >> 8U);
    temp = temp & (uint8_t)0x0F;
    temp=(NIBBLE2ASCII(temp));
    cmdBuf[4] = (char)temp;
    temp = (uint8_t) (featuresBitmap >> 4U);
    temp = temp & (uint8_t)0x0F;
    temp=(NIBBLE2ASCII(temp));
    cmdBuf[5] = (char)temp;
    temp = (uint8_t) featuresBitmap;
    temp = temp & (uint8_t)0x0F;
    temp=(NIBBLE2ASCII(temp));
    cmdBuf[6] = (char)temp;
    cmdBuf[7] = '\r';
    cmdBuf[8] = '\n';


	return RNBD_SendCommand_ReceiveResponse(cmdBuf, 9U, cmdPrompt, 10U);
}

bool RNBD_SetIOCapability(uint8_t ioCapability)
{
	uint8_t temp=0;
	const char cmdPrompt[] = {'A', 'O', 'K', '\r', '\n', 'C', 'M', 'D', '>', ' '};
    cmdBuf[0] = 'S';
    cmdBuf[1] = 'A';
    cmdBuf[2] = ',';
    temp=(NIBBLE2ASCII(ioCapability));
    cmdBuf[3] = (char)temp;
    cmdBuf[4] = '\r';
    cmdBuf[5] = '\n';


	return RNBD_SendCommand_ReceiveResponse(cmdBuf, 6U, cmdPrompt, 10U);
}

bool RNBD_SetPinCode(const char *pinCode, uint8_t pinCodeLen)
{
	const char cmdPrompt[] = {'A', 'O', 'K', '\r', '\n', 'C', 'M', 'D', '>', ' '};
    uint8_t index;

    cmdBuf[0] = 'S';
    cmdBuf[1] = 'P';
    cmdBuf[2] = ',';

    for (index = 0; index < pinCodeLen; index++)
    {
        cmdBuf[3U + index] = pinCode[index];
    }
    index = index + 3U;
    cmdBuf[index++] = '\r';
    cmdBuf[index++] = '\n';


	return RNBD_SendCommand_ReceiveResponse(cmdBuf, index, cmdPrompt, 10U);
}

bool RNBD_SetStatusMsgDelimiter(char preDelimiter, char postDelimiter)
{
	const char cmdPrompt[] = {'A', 'O', 'K', '\r', '\n', 'C', 'M', 'D', '>', ' '};
    cmdBuf[0] = 'S';
    cmdBuf[1] = '%';
    cmdBuf[2] = ',';
    cmdBuf[3] = preDelimiter;
    cmdBuf[4] = ',';
    cmdBuf[5] = postDelimiter;
    cmdBuf[6] = '\r';
    cmdBuf[7] = '\n';

	return RNBD_SendCommand_ReceiveResponse(cmdBuf, 8, cmdPrompt, 10U);

    }



bool RNBD_SetOutputs(RNBD_gpio_bitmap_t bitMap)
{
	const char cmdPrompt[] = {'A', 'O', 'K', '\r', '\n', 'C', 'M', 'D', '>', ' '};
    char ioHighNibble = '0';
    char ioLowNibble = '0';
    char stateHighNibble = '0';
    char stateLowNibble = '0';
    
    // Output pins configurations
    if (bitMap.ioBitMap.p1_3!=0U)
    {
        ioHighNibble = '1';
    }
    else
    {
        ioHighNibble = '0';
    }
    ioLowNibble = ( ((uint8_t)0x0F & bitMap.ioBitMap.gpioBitMap) + '0');
    
    // High/Low Output settings
    if (bitMap.ioStateBitMap.p1_3_state!=0U)
    {
        stateHighNibble = '1';
    }
    else
    {
        stateHighNibble = '0';
    }
    stateLowNibble = ( ((uint8_t)0x0F & bitMap.ioStateBitMap.gpioStateBitMap) + '0');

    cmdBuf[0] = '|';    // I/O
    cmdBuf[1] = 'O';    // Output
    cmdBuf[2] = ',';
    cmdBuf[3] = ioHighNibble;       // - | - | - | P1_3
    cmdBuf[4] = ioLowNibble;        // P1_2 | P3_5 | P2_4 | P2_2
    cmdBuf[5] = ',';
    cmdBuf[6] = stateHighNibble;    // - | - | - | P1_3
    cmdBuf[7] = stateLowNibble;     // P1_2 | P3_5 | P2_4 | P2_2
    cmdBuf[8] = '\r';
    cmdBuf[9] = '\n';

	return RNBD_SendCommand_ReceiveResponse(cmdBuf, 10U, cmdPrompt, 10U);
}

RNBD_gpio_stateBitMap_t RNBD_GetInputsValues(RNBD_gpio_ioBitMap_t getGPIOs)
{
	uint8_t temp=0;
    char ioHighNibble = '0';
    char ioLowNibble = '0';
    char ioValue[] = {'0', '0'};
    RNBD_gpio_stateBitMap_t ioBitMapValue;
    ioBitMapValue.gpioStateBitMap = 0x00;
    
    // Output pins configurations
    if (getGPIOs.p1_3!=0U)
    {
        ioHighNibble = '1';
    }
    else
    {
        ioHighNibble = '0';
    }
    temp=(((uint8_t)0x0F & getGPIOs.gpioBitMap) + (uint8_t)'0');
    ioLowNibble = (char)temp;

    cmdBuf[0] = '|';    // I/O
    cmdBuf[1] = 'I';    // Output
    cmdBuf[2] = ',';
    cmdBuf[3] = ioHighNibble;       // - | - | - | P1_3
    cmdBuf[4] = ioLowNibble;        // P1_2 | P3_5 | P2_4 | P2_2
    cmdBuf[5] = '\r';
    cmdBuf[6] = '\n';

	(void)RNBD_SendCommand_ReceiveResponse(cmdBuf, 7U, ioValue, (uint8_t)sizeof(ioValue));
    ioBitMapValue.gpioStateBitMap = ( ((((uint8_t)ioValue[0] - (uint8_t)'0') & (uint8_t)0x0F) << 4U) | (((uint8_t)ioValue[1] - (uint8_t)'0') & (uint8_t)0x0F) );
    return ioBitMapValue;
}

char * RNBD_GetRSSIValue(void)
{
    static char rssiResp[20];
    unsigned int ResponseRead=0,ResponseTime=0;

    cmdBuf[0] = 'M';
    cmdBuf[1] = '\r';
    cmdBuf[2] = '\n';

    RNBD_SendCmd(cmdBuf, 3U);

	//Wait for the response time
    while(!RNBD.DataReady() || ResponseTime<=RESPONSE_TIMEOUT)
    {
        RNBD.DelayMs(1);
        ResponseTime++;
    }
    //Read Ready data 
    while(RNBD.DataReady())
    {
        resp[ResponseRead]=(char)RNBD.Read();
        ResponseRead++;
    }
    rssiResp[0]=resp[0];
    rssiResp[1]=resp[1];
    rssiResp[2]=resp[2];
    return rssiResp;
}


bool RNBD_RebootCmd(void)
{
	bool RebootStatus = false;
    const char rebootResponse[] = {'R', 'e', 'b', 'o', 'o', 't', 'i', 'n', 'g', '\r', '\n'};
	cmdBuf[0] = 'R';
    cmdBuf[1] = ',';
    cmdBuf[2] = '1';
    cmdBuf[4] = '\r';
    cmdBuf[5] = '\n';

    RebootStatus = RNBD_SendCommand_ReceiveResponse(cmdBuf, 5U, rebootResponse, 11U);

	RNBD.DelayMs(250);

	return RebootStatus;
}

bool RNBD_FactoryReset(RNBD_FACTORY_RESET_MODE_t resetMode)
{
	bool FactoryResetStatus = false;
    const char reboot[] = {'R', 'e', 'b', 'o', 'o', 't', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'F', 'a', 'c', 't', 'o', 'r', 'y', ' ', 'R', 'e', 's', 'e', 't', '\r', '\n'};
    cmdBuf[0] = 'S';
    cmdBuf[1] = 'F';
    cmdBuf[2] = ',';
    cmdBuf[4] = (char)resetMode;
    cmdBuf[5] = '\r';
    cmdBuf[6] = '\n';
    FactoryResetStatus = RNBD_SendCommand_ReceiveResponse(cmdBuf, 6U, reboot, 28U);

	RNBD.DelayMs(250);

	return FactoryResetStatus;
}

bool RNBD_Disconnect(void)
{
    cmdBuf[0] = 'K';
    cmdBuf[1] = ',';
    cmdBuf[2] = '1';
    cmdBuf[3] = '\r';
    cmdBuf[4] = '\n';

    RNBD_SendCmd(cmdBuf, 5U);

    return RNBD_ReadDefaultResponse();
}
void RNBD_set_StatusDelimter(char Delimter_Character)
{
	STATUS_MESSAGE_DELIMITER = Delimter_Character;
}
char RNBD_get_StatusDelimter(void)
{
	return STATUS_MESSAGE_DELIMITER;
}
void RNBD_set_NoDelimter(bool value)
{
    skip_Delimter=value;
}
bool RNBD_get_NoDelimter(void)
{
    return skip_Delimter;
}

bool RNBD_SetAsyncMessageHandler(char* pBuffer, uint8_t len)
{
    if ((pBuffer != NULL) && (len > 1U))
    {
      asyncBuffer = pBuffer;
      asyncBufferSize = len - 1U;
      return true;
    }
    else
    {
        return false;
    }
}

bool RNBD_DataReady(void)
{
    if (dataReady)
    {
        return true;
    }
    
    if (RNBD.DataReady())
    {
        return RNBD_FilterData();
    }
    return false;
}

uint8_t RNBD_Read(void)
{
    while(RNBD_DataReady() == false){}; // Wait
    dataReady = false;
    return peek;
}

static bool RNBD_FilterData(void)
{
    static bool asyncBuffering = false;
    
    uint8_t readChar = RNBD.Read();
    
    if(asyncBuffering == true)
    {
        if(readChar == (uint8_t)STATUS_MESSAGE_DELIMITER)
        {
            asyncBuffering = false;
            *pHead = '\0';
            RNBD.AsyncHandler(asyncBuffer);
        }
        else if (pHead < asyncBuffer + asyncBufferSize)
        {
            *pHead++ = (char)readChar;
        }
        else
        {
            //do nothing
        }
    }
    else
    {
		if((readChar != (uint8_t)STATUS_MESSAGE_DELIMITER ) && ((RNBD_IsOTABegin() == false)) && ((RNBD_IsStreamopen() == false)))
        {        
            asyncBuffering = true;
            pHead = asyncBuffer;
            *pHead++ = (char)readChar;
        }
        else if ((readChar == (uint8_t)STATUS_MESSAGE_DELIMITER && (skip_Delimter == false)) && (RNBD_IsOTABegin() == false))
        {
            asyncBuffering = true;
            pHead = asyncBuffer;
        }
        else 
        {
    	    skip_Delimter = true;
            dataReady = true;
            peek = readChar;
        }
    }
    return dataReady;
}
