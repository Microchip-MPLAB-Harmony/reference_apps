/*
    \file   mqtt_comm_layer.c

    \brief  MQTT Communication layer source file.

    (c) 2018 Microchip Technology Inc. and its subsidiaries.

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
#include <stdio.h>
#include "mqtt_comm_layer.h"
#include "../../iot_config/IoT_Sensor_Node_config.h"
#include "../mqtt_core/mqtt_core.h"
#include "../../services/iot/cloud/bsd_adapter/bsdWINC.h"
#include "../../debug_print.h"

#define TX_BUFF_SIZE 400
#define RX_BUFF_SIZE 100
#define USER_LENGTH 0
#define MQTT_KEEP_ALIVE_TIME 120

static mqttContext mqttConn;
static uint8_t mqttTxBuff[TX_BUFF_SIZE];
static uint8_t mqttRxBuff[RX_BUFF_SIZE];
static int8_t  mqqtSocket = -1;

void MQTT_ClientInitialise(void)
{
	MQTT_initialiseState();
	memset(mqttTxBuff, 0 , sizeof(TX_BUFF_SIZE));
	memset(mqttRxBuff, 0 , sizeof(RX_BUFF_SIZE));
	mqttConn.mqttDataExchangeBuffers.txbuff.start = mqttTxBuff;
	mqttConn.mqttDataExchangeBuffers.txbuff.bufferLength = TX_BUFF_SIZE;
	mqttConn.mqttDataExchangeBuffers.txbuff.currentLocation = mqttConn.mqttDataExchangeBuffers.txbuff.start;
	mqttConn.mqttDataExchangeBuffers.txbuff.dataLength = 0;
	mqttConn.mqttDataExchangeBuffers.rxbuff.start = mqttRxBuff;
	mqttConn.mqttDataExchangeBuffers.rxbuff.bufferLength = RX_BUFF_SIZE;
	mqttConn.mqttDataExchangeBuffers.rxbuff.currentLocation = mqttConn.mqttDataExchangeBuffers.rxbuff.start;
	mqttConn.mqttDataExchangeBuffers.rxbuff.dataLength = 0;
   
   mqttConn.tcpClientSocket = &mqqtSocket;
}

mqttContext* MQTT_GetClientConnectionInfo()
{
	return &mqttConn;
}


bool MQTT_Send(mqttContext *connectionPtr)
{
	bool ret = false;
	int sendRet;
	if((sendRet = BSD_send(*connectionPtr->tcpClientSocket, connectionPtr->mqttDataExchangeBuffers.txbuff.start, connectionPtr->mqttDataExchangeBuffers.txbuff.dataLength, 0)) > BSD_SUCCESS)
	{
		ret = true;
	}
	
	debug_print("MQTT: sendresult (%d)", sendRet);
	return ret;
}

bool MQTT_Close(mqttContext *connectionPtr)
{
	bool ret = false;
	if(BSD_close(*connectionPtr->tcpClientSocket) == BSD_SUCCESS)
	{
		ret = true;
	}
	return ret;
}

void MQTT_GetReceivedData(uint8_t *pData, uint8_t len)
{
	MQTT_ExchangeBufferInit(&mqttConn.mqttDataExchangeBuffers.rxbuff);
	MQTT_ExchangeBufferWrite(&mqttConn.mqttDataExchangeBuffers.rxbuff, pData, len);
}
