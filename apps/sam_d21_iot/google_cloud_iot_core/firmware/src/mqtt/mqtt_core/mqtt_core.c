/********************************************************************
 *
(c) [2018] Microchip Technology Inc. and its subsidiaries.

Subject to your compliance with these terms, you may use Microchip software
 * and any derivatives exclusively with Microchip products. It is your
 * responsibility to comply with third party license terms applicable to your
 * use of third party software (including open source software) that may
 * accompany Microchip software.
THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR
 * PURPOSE.
 *
IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
 * ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *************************************************************************
 *
 *                           mqtt_core.c
 *
 * About:
 *  MQTT client implementation. This is the core of the MQTT client protocol
 *  implementation. The aim of this file is to implement a hardware-independent
 *  subsystem that complies with [mqtt-v3.1.1-plus-errata01].
 *
 *
 ******************************************************************************/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "mqtt_core.h"
#include "../mqtt_packetTransfer_interface.h"
#include "../../iot_config/mqtt_config.h"
#include "../../iot_config/IoT_Sensor_Node_config.h"
#include "../../debug_print.h"

/***********************MQTT Client definitions********************************/

#define MQTT_TX_PACKET_DECISION_CONSTANT    0x01
#define KEEP_ALIVE_CALCULATION_CONSTANT     0x01
#define CONNECT_CLEAN_SESSION_MASK          0x02


// MQTT packet transmission flags. The creation and transmission processes of
// MQTT control packets uses a set of flags to indicate that a new packet is
// created and available for transmission. These flags are defined here.

typedef union {
   uint8_t All;

   struct {
      unsigned newTxConnectPacket : 1; // Indicates new CONNECT packet available for transmission
      unsigned newTxDisconnectPacket : 1; // Indicates new DISCONNECT packet available for transmission
      unsigned newTxPublishPacket : 1; // Indicates new PUBLISH packet available for transmission
      unsigned newTxSubscribePacket : 1; // Indicates new SUBSCRIBE packet available for transmission
      unsigned newTxUnsubscribePacket : 1; // Indicates new UNSUBSCRIBE packet available for transmission
      unsigned newTxPingreqPacket : 1; // Indicates new PINGREQ packet available for transmission
      unsigned : 2; // Reserved
   };
} newTxDataFlags;

// MQTT packet reception flags. The reception processes of MQTT control packets
// uses a set of flags to identify the received packet type in order to
// correctly process it. These flags are defined here.

typedef union {
   uint8_t All;

   struct {
      unsigned newRxConnackPacket : 1; // Indicates new CONNACK packet has been received
      unsigned newRxPublishPacket : 1; // Indicates new PUBLISH packet has been received
      unsigned newRxSubackPacket : 1; // Indicates new SUBACK packet has been received
      unsigned newRxUnsubackPacket : 1; // Indicates new UNSUBACK packet has been received
      unsigned newRxPingrespPacket : 1; // Indicates new PINGRESP packet has been received
      unsigned newRxPubackPacket : 1; // Indicates new PUBACK packet has been received
      unsigned : 2; // Reserved
   };
} newRxDataFlags;

// MQTT packet transmission states. The transmission of MQTT control packets is
// performed inside the CONNECTED state. The Tx state machine states are defined
// here. These need to correspond to the respective flags in the union
// newTxDataFlags.

typedef enum {
   SENDDISCONNECT = 2,
   SENDPUBLISH = 4,
   SENDSUBSCRIBE = 8,
   SENDUNSUBSCRIBE = 16,
   SENDPINGREQ = 32,
} mqttConnectCurrentTxSubstate;

// Function pointer for handling QoS levels.
typedef void (*qosLevelHandler)(uint8_t);

// The QoS levels in PUBLISH message are 0, 1 and 2 with quality of service
// increasing from QoS level 0 to 2. QoS level processing needs information
// about the QoS level and the appropriate callback function. The call back
// table type for determining whether the correct callback function for the QoS
// level under consideration is defined here.

typedef struct {
   uint8_t qosLevel;
   qosLevelHandler qosLevelHandlerFunction;
} qosLevelHandler_t;

/***********************MQTT Client definitions*(END)**************************/


/***********************MQTT Client variables**********************************/

/** \brief MQTT packet transmission flags. */
static newTxDataFlags mqttTxFlags;

/** \brief MQTT packet reception flags. */
static newRxDataFlags mqttRxFlags;

/** \brief CONNECT packet to be transmitted. */
static mqttConnectPacket txConnectPacket;

/** \brief PUBLISH packet to be transmitted. */
static mqttPublishPacket txPublishPacket;

/** \brief SUBSCRIBE packet to be transmitted. */
static mqttSubscribePacket txSubscribePacket;

/** \brief UNSUBSCRIBE packet to be transmitted. */
static mqttUnsubscribePacket txUnsubscribePacket;

/** \brief CONNACK packet timeout indicator. */
static volatile bool connackTimeoutOccured = false;

/** \brief PINGREQ packet timeout indicator. */
static volatile bool pingreqTimeoutOccured = false;

/** \brief PINGRESP packet timeout indicator. */
static volatile bool pingrespTimeoutOccured = false;

/** \brief SUBACK packet timeout indicator. */
static volatile bool subackTimeoutOccured = false;

/** \brief SUBACK packet timeout indicator. */
static volatile bool unsubackTimeoutOccured = false;

/** \brief Store the timestamp at the last CONNACK. */
time_t connectTime = 0;

/** \brief QoS level call back table.
 *
 * This callback table lists the callback functions for 3 different QoS levels
 * of the MQTT PUBLISH message. For each QoS level there needs to be a
 * corresponding callback function.
 * Currently only QoS level 0 is supported.
 *
 */
//static const qosLevelHandler_t mqtt_qosLevelCallBackTable[] = {
   //    {0x00, handleQoSLevel0}
//};

/** \brief Current state of MQTT Client state machine. */
static mqttCurrentState mqttState = DISCONNECTED;

/** \brief Tx substate for the state machine inside the CONNECTED state. */
static mqttConnectCurrentTxSubstate mqttConnectTxSubstate;

/***********************MQTT Client variables*(END)****************************/


/**********************Local function definitions******************************/

/** \brief Encode the MQTT packet length.
 *
 * This function encodes the MQTT packet length.
 *
 * @param length
 * @param *output
 *
 * @return
 *  - The number of bytes encoded
 */
static uint8_t mqttEncodeLength(uint16_t length, uint8_t *output);

/** \brief Decode the MQTT packet length.
 *
 * This function decodes the MQTT packet length available in the remainingLength
 * field of the received packet.
 *
 * @param *data
 *
 * @return
 *  - The number of bytes decoded
 */
static uint32_t mqttDecodeLength(uint8_t *encodedData);

/** \brief Send the MQTT CONNECT packet.
 *
 * This function sends the MQTT CONNECT packet using the underlying
TCP layer.
 *
 * @param mqttConnectionPtr
 *
 * @return
 *  - The return code indicating success/failure of CONNECT packet
transmission.
 */
static bool mqttSendConnect(mqttContext *mqttConnectionPtr);

/** \brief Send the MQTT PUBLISH packet.
 *
 * This function sends the MQTT PUBLISH packet using the underlying
TCP layer.
 *
 * @param mqttConnectionPtr
 *
 * @return
 *  - The return code indicating success/failure of PUBLISH packet
transmission.
 */
static bool mqttSendPublish(mqttContext *mqttConnectionPtr);

/** \brief Send the MQTT SUBSCRIBE packet.
 *
 * This function sends the MQTT SUBSCRIBE packet using the underlying
TCP layer.
 *
 * @param mqttConnectionPtr
 *
 * @return
 *  - The return code indicating success/failure of SUBSCRIBE packet
transmission.
 */
static bool mqttSendSubscribe(mqttContext *mqttConnectionPtr);


/** \brief Send the MQTT UNSUBSCRIBE packet.
 *
 * This function sends the MQTT UNSUBSCRIBE packet using the underlying
TCP layer.
 *
 * @param mqttConnectionPtr
 *
 * @return
 *  - The return code indicating success/failure of UNSUBSCRIBE packet
transmission.
 */
static bool mqttSendUnsubscribe(mqttContext *mqttConnectionPtr);


/** \brief Send the MQTT PINGREQ packet.
 *
 * This function sends the MQTT PINGREQ packet using the underlying
TCP layer.
 *
 * @param mqttConnectionPtr
 *
 * @return
 *  - The return code indicating success/failure of PINGREQ packet
transmission.
 */
static bool mqttSendPingreq(mqttContext *mqttConnectionPtr);

/** \brief Send the MQTT DISCONNECT packet.
 *
 * This function sends the MQTT DISCONNECT packet using the underlying
TCP layer.
 *
 * @param mqttConnectionPtr
 *
 * @return
 *  - The return code indicating success/failure of DISCONNECT packet
transmission.
 */
static bool mqttSendDisconnect(mqttContext *mqttConnectionPtr);

/** \brief Process the MQTT CONNACK packet.
 *
 * This function processes the CONNACK packet received from the
broker.
 *
 * @param mqttConnectionPtr
 *
 * @return
 *  - The state of MQTT Tx and Rx handlers depending on whether the CONNACK
packet was received and processed correctly.
 */
static mqttCurrentState mqttProcessConnack(mqttContext *mqttConnectionPtr);

/** \brief Process the MQTT PINGRESP packet.
 *
 * This function processes the PINGRESP packet received from the
broker.
 *
 * @param mqttConnectionPtr
 *
 */
static void mqttProcessPingresp(mqttContext *mqttConnectionPtr);

/** \brief Process the MQTT SUBACK packet.
 *
 * This function processes the SUBACK packet received from the
broker.
 *
 * @param mqttConnectionPtr
 *
 * @return
 *  - The state of MQTT Tx and Rx handlers depending on whether the mqttProcessSuback
packet was received and processed correctly.
 */
static mqttCurrentState mqttProcessSuback(mqttContext *mqttConnectionPtr);


/** \brief Process the MQTT UNSUBACK packet.
 *
 * This function processes the UNSUBACK packet received from the
broker.
 *
 * @param mqttConnectionPtr
 *
 * @return
 *  - The state of MQTT Tx and Rx handlers depending on whether the mqttProcessUnsuback
packet was received and processed correctly.
 */
static mqttCurrentState mqttProcessUnsuback(mqttContext *mqttConnectionPtr);


/** \brief Process the MQTT PUBLISH packet.
 *
 * This function processes the PUBLISH packet received from the
broker.
 *
 * @param mqttConnectionPtr
 *
 */
static mqttCurrentState mqttProcessPublish(mqttContext *mqttConnectionPtr);

/** \brief Check whether timeout has occurred after sending CONNECT
packet.
 *
 * This function checks whether a timeout (30s) has occurred after sending
CONNECT packet, since a CONNACK packet is expected from the broker
within 30s.
 *
 * @param none
 *
 * @return
 *  - The number of ticks till the connackTimer expires.
 */
//static uint32_t checkConnackTimeoutState();
void checkConnackTimeoutState(void);
//timerstruct_t connackTimer = {checkConnackTimeoutState, NULL};
SYS_TIME_HANDLE checkConnackTimeoutStateHandle      = SYS_TIME_HANDLE_INVALID;
volatile bool checkConnackTimeoutStateTmrExpired    = false;

/** \brief Check whether timeout has occurred after receiving CONNACK
or PINGRESP packet.
 *
 * This function checks whether a timeout of (keepAliveTime)s has occurred after
receiving CONNACK or PINGRESP packet, since a client is expected to send some
packet to the broker within (keepAliveTime)s time period.
 *
 * @param none
 *
 * @return
 *  - The number of ticks till the connackTimer or pingrespTimer expires.
 */
//static uint32_t checkPingreqTimeoutState();
void checkPingreqTimeoutState(void);
//timerstruct_t pingreqTimer = {checkPingreqTimeoutState, NULL};
SYS_TIME_HANDLE checkPingreqTimeoutStateHandle      = SYS_TIME_HANDLE_INVALID;
volatile bool checkPingreqTimeoutStateTmrExpired    = false;

/** \brief Check whether timeout has occurred after sending PINGREQ
packet.
 *
 * This function checks whether a timeout (30s) has occurred after sending
PINGREQ packet. In the current MQTT client implementation, the client
waits for 30s after transmission of PINGREQ packet to receive a PINGRESP
packet.
 *
 * @param none
 *
 * @return
 *  - The number of ticks till the pingreq expires.
 */
//static uint32_t checkPingrespTimeoutState();
void checkPingrespTimeoutState(void);
//timerstruct_t pingrespTimer = {checkPingrespTimeoutState, NULL};
SYS_TIME_HANDLE checkPingrespTimeoutStateHandle     = SYS_TIME_HANDLE_INVALID;
volatile bool checkPingrespTimeoutStateTmrExpired   = false;

/** \brief Check whether timeout has occurred after sending SUBSCRIBE
packet.
 *
 * This function checks whether a timeout (30s) has occurred after sending
SUBSCRIBE packet. In the current MQTT client implementation, the client
waits for 30s after transmission of SUBSCRIBE packet to receive a SUBACK
packet.
* If the client does not receive a SUBACK packet from the server in a 
reasonable period of time (currently set to 30s), it is treated as a 
protocol violation. The client therefore will close the Network 
Connection by checking subackTimeoutOccured flag (MQTT RFC, section 4.8).
 *
 * @param none
 *
 * @return
 *  - The number of ticks till the suback expires.
 */
//static uint32_t checkSubackTimeoutState();
void checkSubackTimeoutState(void);
//timerstruct_t subackTimer = {checkSubackTimeoutState, NULL};
SYS_TIME_HANDLE checkSubackTimeoutStateHandle   = SYS_TIME_HANDLE_INVALID;	
volatile bool checkSubackTimeoutStateTmrExpired = false;

/** \brief Check whether timeout has occurred after sending UNSUBSCRIBE
packet.
 *
 * This function checks whether a timeout (30s) has occurred after sending
UNSUBSCRIBE packet. In the current MQTT client implementation, the client
waits for 30s after transmission of UNSUBSCRIBE packet to receive a UNSUBACK
packet.
* If the client does not receive a UNSUBACK packet from the server in a 
reasonable period of time (currently set to 30s), it is treated as a 
protocol violation. The client therefore will close the Network 
Connection by checking unsubackTimeoutOccured flag (MQTT RFC, section 4.8).
 *
 * @param none
 *
 * @return
 *  - The number of ticks till the unsuback expires.
 */
//static uint32_t checkUnsubackTimeoutState();
void checkUnsubackTimeoutState(void);
//timerstruct_t unsubackTimer = {checkUnsubackTimeoutState, NULL};
SYS_TIME_HANDLE checkUnsubackTimeoutStateHandle     = SYS_TIME_HANDLE_INVALID;
volatile bool checkUnsubackTimeoutStateTmrExpired   = false;

/**********************Local function definitions*(END)************************/

/**********************Function implementations********************************/
void checkConnackTimeoutStatecb(uintptr_t context)
{
    checkConnackTimeoutStateTmrExpired = true;
}
void checkPingreqTimeoutStatecb(uintptr_t context)
{
    checkPingreqTimeoutStateTmrExpired = true;
}
void checkSubackTimeoutStatecb(uintptr_t context)
{
    checkSubackTimeoutStateTmrExpired = true;
}
void checkUnsubackTimeoutStatecb(uintptr_t context)
{
    checkUnsubackTimeoutStateTmrExpired = true;
}
void checkPingrespTimeoutStatecb(uintptr_t context)
{
    checkPingrespTimeoutStateTmrExpired = true;
}


int32_t MQTT_getConnectionAge()
{
   int32_t age = 0;
   if (connectTime > 0) {
       struct tm sys_time;
       RTC_RTCCTimeGet(&sys_time);
       age = difftime(mktime(&sys_time), connectTime);
       //age = difftime(time(NULL), connectTime);
   }
   return age;
}

void checkConnackTimeoutState(void)
{
   connackTimeoutOccured = true; // Mark that timer has executed
}

void checkPingreqTimeoutState(void)
{
   pingreqTimeoutOccured = true; // Mark that timer has executed
   //return ((ntohs(txConnectPacket.connectVariableHeader.keepAliveTimer) - KEEP_ALIVE_CALCULATION_CONSTANT) * SECONDS);
   //SYS_TIME_TimerReload(checkPingreqTimeoutStateHandle, 0, ((ntohs(txConnectPacket.connectVariableHeader.keepAliveTimer) - KEEP_ALIVE_CALCULATION_CONSTANT) * SECONDS), checkPingreqTimeoutStatecb, 0, SYS_TIME_PERIODIC);
   checkPingreqTimeoutStateHandle = SYS_TIME_CallbackRegisterMS(checkPingreqTimeoutStatecb, 0, 
           ((ntohs(txConnectPacket.connectVariableHeader.keepAliveTimer) - KEEP_ALIVE_CALCULATION_CONSTANT) * SECONDS),
           SYS_TIME_SINGLE);
}

void checkPingrespTimeoutState(void)
{
   pingrespTimeoutOccured = true; // Mark that timer has executed
}

void checkSubackTimeoutState(void) 
{
	subackTimeoutOccured = true; // Mark that timer has executed
}

void checkUnsubackTimeoutState(void)
{
	unsubackTimeoutOccured = true; // Mark that timer has executed
}

void MQTT_initialiseState(void){
	mqttState = DISCONNECTED;
    //Ensure you stop any SINGLE SHOT timer since this 
    //function can be called asynchronously while already connected
    // to the CLOUD!
    SYS_TIME_TimerDestroy(checkPingreqTimeoutStateHandle);
    SYS_TIME_TimerDestroy(checkSubackTimeoutStateHandle);
}

mqttCurrentState MQTT_GetConnectionState(void) {
   return mqttState;
}

bool MQTT_CreateConnectPacket(mqttConnectPacket *newConnectPacket) {
   uint16_t payloadLength = 0;
   memset(&txConnectPacket, 0, sizeof (txConnectPacket));

   // Fixed header
   txConnectPacket.connectFixedHeaderFlags.controlPacketType = CONNECT;
   txConnectPacket.connectFixedHeaderFlags.duplicate = 0;
   txConnectPacket.connectFixedHeaderFlags.qos = 0;
   txConnectPacket.connectFixedHeaderFlags.retain = 0;

   // Variable header
   txConnectPacket.connectVariableHeader.protocolName[0] = 0x00;
   txConnectPacket.connectVariableHeader.protocolName[1] = 0x04;
   txConnectPacket.connectVariableHeader.protocolName[2] = 'M';
   txConnectPacket.connectVariableHeader.protocolName[3] = 'Q';
   txConnectPacket.connectVariableHeader.protocolName[4] = 'T';
   txConnectPacket.connectVariableHeader.protocolName[5] = 'T';
   txConnectPacket.connectVariableHeader.protocolLevel = 0x04;
   if ((newConnectPacket->passwordLength > 0) || (newConnectPacket->usernameLength > 0)) {
      txConnectPacket.connectVariableHeader.connectFlagsByte.All = 0xC2;
   } else {
      txConnectPacket.connectVariableHeader.connectFlagsByte.All = 0x02;
   }
   txConnectPacket.connectVariableHeader.keepAliveTimer = htons(newConnectPacket->connectVariableHeader.keepAliveTimer);
  
   // Payload
   txConnectPacket.clientID = newConnectPacket->clientID;
   txConnectPacket.clientIDLength = strlen((char*) txConnectPacket.clientID);
   if (txConnectPacket.connectVariableHeader.connectFlagsByte.passwordFlag == 1) {
      txConnectPacket.password = newConnectPacket->password;
      txConnectPacket.passwordLength = newConnectPacket->passwordLength;
   }
   if (txConnectPacket.connectVariableHeader.connectFlagsByte.usernameFlag == 1) {
      txConnectPacket.username = newConnectPacket->username;
      txConnectPacket.usernameLength = newConnectPacket->usernameLength;
   }
   if (txConnectPacket.connectVariableHeader.connectFlagsByte.usernameFlag == 0) {
      payloadLength = txConnectPacket.clientIDLength;
   } else {
      payloadLength = txConnectPacket.clientIDLength + txConnectPacket.passwordLength + txConnectPacket.usernameLength + 4;
   }
   txConnectPacket.totalLength = sizeof (txConnectPacket.connectVariableHeader) + sizeof (payloadLength) + payloadLength;
   if (txConnectPacket.connectVariableHeader.connectFlagsByte.usernameFlag == 1 || txConnectPacket.connectVariableHeader.connectFlagsByte.passwordFlag == 1) {
      txConnectPacket.passwordLength = htons(txConnectPacket.passwordLength);
      txConnectPacket.usernameLength = htons(txConnectPacket.usernameLength);
   }
   txConnectPacket.clientIDLength = htons(txConnectPacket.clientIDLength);
   
   // Clear all pending transmissions first
   mqttTxFlags.All = 0;
   
   // Now mark the Connect for sending
   mqttTxFlags.newTxConnectPacket = 1;
   mqttState = CONNECTING;

#if CFG_DEBUG_MSG
    debug_printInfo("MQTT: Connect Pckt content:");
    debug_printInfo("MQTT: Connect Pckt Client ID: %s", (uint8_t*)txConnectPacket.clientID);
    debug_printInfo("MQTT: Connect Pckt Client ID Len: %d", txConnectPacket.clientIDLength);
    debug_printInfo("MQTT: Connect Pckt Password: %s", (uint8_t*)txConnectPacket.password);
    debug_printInfo("MQTT: Connect Pckt Password Len: %d", txConnectPacket.passwordLength);
    
    int i;
    for (i=0; i<4; i++)
    {
        debug_printInfo("MQTT: Connect Pckt Remaining Len[%d]: %d", i, txConnectPacket.remainingLength[i]);
    }
        
    
    debug_printInfo("MQTT: Connect Pckt Total Len: %d", txConnectPacket.totalLength);
    debug_printInfo("MQTT: Connect Pckt Username: %s", (uint8_t*)txConnectPacket.username);
    debug_printInfo("MQTT: Connect Pckt Username Len: %d", txConnectPacket.usernameLength);
    debug_printInfo("MQTT: Connect Pckt Header Flag: %d", txConnectPacket.connectFixedHeaderFlags.All);
    debug_printInfo("MQTT: Connect Pckt KeepAliveTimer: %d", txConnectPacket.connectVariableHeader.keepAliveTimer);
    debug_printInfo("MQTT: Connect Pckt Protocol Lvl: %d", txConnectPacket.connectVariableHeader.protocolLevel);
    for (i=0; i<2; i++)
    {
        debug_printInfo("MQTT: Connect Pckt Protocol Name [%d]: %d", i, txConnectPacket.connectVariableHeader.protocolName[i]);   
    }

    for (i=2; i<6; i++)
    {
        debug_printInfo("MQTT: Connect Pckt Protocol Name [%d]: %c", i, txConnectPacket.connectVariableHeader.protocolName[i]);   
    }
#endif    
   return true;
}

bool MQTT_CreatePublishPacket(mqttPublishPacket *newPublishPacket) {
   bool ret;

   ret = false;

   memset(&txPublishPacket, 0, sizeof (txPublishPacket));

   if (mqttState == CONNECTED) {
      debug_printInfo("MQTT: PublishBuild");
      // Fixed header
      txPublishPacket.publishHeaderFlags.controlPacketType = PUBLISH;
      txPublishPacket.publishHeaderFlags.duplicate = newPublishPacket->publishHeaderFlags.duplicate;
      txPublishPacket.publishHeaderFlags.qos = newPublishPacket->publishHeaderFlags.qos;
      if ((txPublishPacket.publishHeaderFlags.qos == 0) && (txPublishPacket.publishHeaderFlags.duplicate != 0)) {
         txPublishPacket.publishHeaderFlags.duplicate = 0;
      }
      txPublishPacket.publishHeaderFlags.retain = newPublishPacket->publishHeaderFlags.retain;

      // Variable header
      txPublishPacket.topic = newPublishPacket->topic;
      txPublishPacket.topicLength = strlen((char*) newPublishPacket->topic);
      if (newPublishPacket->publishHeaderFlags.qos > 0) {
         txPublishPacket.packetIdentifierLSB = newPublishPacket->packetIdentifierLSB;
         txPublishPacket.packetIdentifierMSB = newPublishPacket->packetIdentifierMSB;
         txPublishPacket.totalLength += sizeof (txPublishPacket.packetIdentifierLSB) + sizeof (txPublishPacket.packetIdentifierMSB);
      }

      // Payload
      txPublishPacket.payload = newPublishPacket->payload;
      txPublishPacket.payloadLength = newPublishPacket->payloadLength;
      txPublishPacket.totalLength += sizeof (txPublishPacket.topicLength) + txPublishPacket.topicLength + txPublishPacket.payloadLength;
      txPublishPacket.topicLength = htons(txPublishPacket.topicLength);

      mqttTxFlags.newTxPublishPacket = 1;
      ret = true;
   }
   return ret;
}

bool MQTT_CreateSubscribePacket(mqttSubscribePacket *newSubscribePacket) {
   bool ret;
   uint8_t topicCount = 0;

   ret = false;

    // The library is capable of handling only one SUBSCRIBE request at a time.
    // A new SUBSCRIBE packet can be created only after reception of SUBACK for
    // the previous SUBSCRIBE packet has been received. This condition is
    // checked by checking the value of newRxSubackPacket flag.
    if (mqttState == CONNECTED && mqttRxFlags.newRxSubackPacket == 0) {
      memset(&txSubscribePacket, 0, sizeof (txSubscribePacket));

      // Fixed header
      // MQTT-3.8.1-1: Bits 3,2,1,0 of fixed header MUST be set as 0010, else Server MUST treat as malformed
      txSubscribePacket.subscribeHeaderFlags.controlPacketType = SUBSCRIBE;
      txSubscribePacket.subscribeHeaderFlags.duplicate = 0;
      txSubscribePacket.subscribeHeaderFlags.qos = 1;
      txSubscribePacket.subscribeHeaderFlags.retain = 0;

      // Variable header
      txSubscribePacket.packetIdentifierLSB = newSubscribePacket->packetIdentifierLSB;
      txSubscribePacket.packetIdentifierMSB = newSubscribePacket->packetIdentifierMSB;

      // Payload
      for (topicCount = 0; topicCount < NUM_TOPICS_SUBSCRIBE; topicCount++) {
         txSubscribePacket.subscribePayload[topicCount].topicLength = htons(newSubscribePacket->subscribePayload[topicCount].topicLength);
         txSubscribePacket.subscribePayload[topicCount].topic = newSubscribePacket->subscribePayload[topicCount].topic;
         txSubscribePacket.subscribePayload[topicCount].requestedQoS = newSubscribePacket->subscribePayload[topicCount].requestedQoS;
         txSubscribePacket.totalLength += sizeof (txSubscribePacket.subscribePayload[topicCount].topicLength) + ntohs(txSubscribePacket.subscribePayload[topicCount].topicLength)
                 + sizeof (txSubscribePacket.subscribePayload[topicCount].requestedQoS);
      }

      // The totalLength field is not essentially a part of the SUBSCRIBE
      // packet. It is used for calculation of the remaining length field.
      txSubscribePacket.totalLength += sizeof (txSubscribePacket.packetIdentifierLSB) + sizeof (txSubscribePacket.packetIdentifierMSB);

      mqttTxFlags.newTxSubscribePacket = 1;
      ret = true;
   }
   return ret;
}


bool MQTT_CreateUnsubscribePacket(mqttUnsubscribePacket *newUnsubscribePacket) 
{
    bool ret;
	uint8_t topicCount = 0;

	ret = false;
	
	// The library is capable of handling only one UNSUBSCRIBE request at a time.
	// A new UNSUBSCRIBE packet can be created only after reception of UNSUBACK for
	// the previous UNSUBSCRIBE packet has been received. This condition is
	// checked by checking the value of newRxUnubackPacket flag.
	if (mqttState == CONNECTED && mqttRxFlags.newRxUnsubackPacket == 0) 
    {
        memset(&txUnsubscribePacket, 0, sizeof (txUnsubscribePacket));

		// Fixed header
		// MQTT-3.8.1-1: Bits 3,2,1,0 of fixed header MUST be set as 0010, else Server MUST treat as malformed
		txUnsubscribePacket.unsubscribeHeaderFlags.controlPacketType = UNSUBSCRIBE;
		txUnsubscribePacket.unsubscribeHeaderFlags.duplicate = 0;
		txUnsubscribePacket.unsubscribeHeaderFlags.qos = 1;
		txUnsubscribePacket.unsubscribeHeaderFlags.retain = 0;

		// Variable header
		txUnsubscribePacket.packetIdentifierLSB = newUnsubscribePacket->packetIdentifierLSB;
		txUnsubscribePacket.packetIdentifierMSB = newUnsubscribePacket->packetIdentifierMSB;

		// Payload
		for (topicCount = 0; topicCount < NUM_TOPICS_UNSUBSCRIBE; topicCount++) 
		{
			txUnsubscribePacket.unsubscribePayload[topicCount].topicLength = htons(newUnsubscribePacket->unsubscribePayload[topicCount].topicLength);
			txUnsubscribePacket.unsubscribePayload[topicCount].topic = newUnsubscribePacket->unsubscribePayload[topicCount].topic;
			txUnsubscribePacket.totalLength += sizeof (txUnsubscribePacket.unsubscribePayload[topicCount].topicLength) + ntohs(txUnsubscribePacket.unsubscribePayload[topicCount].topicLength);
		}

		// The totalLength field is not essentially a part of the UNSUBSCRIBE
		// packet. It is used for calculation of the remaining length field.
		txUnsubscribePacket.totalLength += sizeof (txUnsubscribePacket.packetIdentifierLSB) + sizeof (txUnsubscribePacket.packetIdentifierMSB);

		mqttTxFlags.newTxUnsubscribePacket = 1;
		ret = true;
	}
	return ret;
}


static bool mqttSendConnect(mqttContext *mqttConnectionPtr) {
   bool ret = false;

   MQTT_ExchangeBufferInit(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff);
   MQTT_ExchangeBufferInit(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff);

   MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, (uint8_t*) & txConnectPacket.connectFixedHeaderFlags.All, sizeof (txConnectPacket.connectFixedHeaderFlags.All));
   MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, (uint8_t*) txConnectPacket.remainingLength, mqttEncodeLength(txConnectPacket.totalLength, txConnectPacket.remainingLength));
   MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, (uint8_t*) & txConnectPacket.connectVariableHeader, sizeof (txConnectPacket.connectVariableHeader));
   MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, (uint8_t*) & txConnectPacket.clientIDLength, sizeof (txConnectPacket.clientIDLength));
   MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, (uint8_t*) txConnectPacket.clientID, strlen((char*) txConnectPacket.clientID));

   if ((txConnectPacket.passwordLength > 0) || (txConnectPacket.usernameLength > 0)) {
      MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, (uint8_t*) & txConnectPacket.usernameLength, sizeof (txConnectPacket.usernameLength));
      MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, (uint8_t*) txConnectPacket.username, ntohs(txConnectPacket.usernameLength));
      MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, (uint8_t*) & txConnectPacket.passwordLength, sizeof (txConnectPacket.passwordLength));
      MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, (uint8_t*) txConnectPacket.password, ntohs(txConnectPacket.passwordLength));
   }

   ret = MQTT_Send(mqttConnectionPtr);
   
   if (ret == true) {
      mqttTxFlags.newTxConnectPacket = 0;
   } else {
      debug_printError("MQTT: Send Error");
   }
   return ret;
}

static bool mqttSendPublish(mqttContext *mqttConnectionPtr) {
   bool ret = false;

   MQTT_ExchangeBufferInit(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff);
   MQTT_ExchangeBufferInit(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff);

   // Copy the txPublishPacket data in TCP Tx buffer
   MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, &txPublishPacket.publishHeaderFlags.All, sizeof (txPublishPacket.publishHeaderFlags.All));
   MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, txPublishPacket.remainingLength, mqttEncodeLength(txPublishPacket.totalLength, txPublishPacket.remainingLength));
   MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, (uint8_t*) & txPublishPacket.topicLength, sizeof (txPublishPacket.topicLength));
   MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, txPublishPacket.topic, ntohs(txPublishPacket.topicLength));

   if (txPublishPacket.publishHeaderFlags.qos == 1) {
      MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, &txPublishPacket.packetIdentifierMSB, sizeof (txPublishPacket.packetIdentifierMSB));
      MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, &txPublishPacket.packetIdentifierLSB, sizeof (txPublishPacket.packetIdentifierLSB));
   }
   MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, txPublishPacket.payload, txPublishPacket.payloadLength);

   // Function call to TCP_Send() is abstracted
   if (mqttTxFlags.newTxPublishPacket == 1 || txPublishPacket.publishHeaderFlags.duplicate == 1) {
      ret = MQTT_Send(mqttConnectionPtr);
      if (ret == true) {
         mqttTxFlags.newTxPublishPacket = 0;
         if (txPublishPacket.publishHeaderFlags.qos == 1) {
            mqttRxFlags.newRxPubackPacket = 1;
         }
      }
   }
   return ret;
}

static uint8_t mqttEncodeLength(uint16_t length, uint8_t *output) {
   uint8_t encodedByte;
   uint8_t i = 0;

   do {
      encodedByte = length % 128;
      length /= 128;
      // if there are more data to encode, set the top bit of this byte
      if (length > 0) {
         encodedByte |= 0x80;
      }
      output[i] = encodedByte;
      i++;
   } while (length);

   return i; /* Return the amount of bytes used */
}

static uint32_t mqttDecodeLength(uint8_t *encodedData) {
   uint32_t multiplier;
   uint32_t value;
   uint32_t i;

   multiplier = 1;
   value = 0;

   for (i = 0; i == 0 || (encodedData[i - 1] & 0x80); i++) {
      value += (encodedData[i] & 0x7f) * multiplier;
      multiplier *= 0x80;
   }

   return value;
}


mqttCurrentState MQTT_Disconnect(mqttContext* connectionInfo) {
   if ((mqttState == CONNECTED) || (mqttState == WAITFORCONNACK)) {
      SYS_TIME_TimerDestroy(checkPingreqTimeoutStateHandle);
      mqttSendDisconnect(connectionInfo);
      mqttState = DISCONNECTED;
   }

   return mqttState;

}

static void mqttProcessPingresp(mqttContext *mqttConnectionPtr) {
   mqttPingPacket txPingrespPacket;

   memset(&txPingrespPacket, 0, sizeof (txPingrespPacket));

   MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, &txPingrespPacket.pingFixedHeader.All, sizeof (txPingrespPacket.pingFixedHeader.All));
   // Reload timeout for keepAliveTimer
   // The timeout should be reloaded only if the keepAliveTimer is set
   // to a non-zero value.
   if (ntohs(txConnectPacket.connectVariableHeader.keepAliveTimer) != 0) {
      mqttTxFlags.newTxPingreqPacket = 1;
   }
   // Re-initialise the RX exchange buffer to be able to process the
   // next incoming MQTT packet
   MQTT_ExchangeBufferInit(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff);
}

static mqttCurrentState mqttProcessSuback(mqttContext *mqttConnectionPtr) {
   mqttCurrentState ret;
   mqttSubackPacket rxSubackPacket;
   uint8_t topicNumbers = 0;
   uint8_t topicCount = 0;

   memset(&rxSubackPacket, 0, sizeof (rxSubackPacket));

   ret = CONNECTED;

   MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, &rxSubackPacket.subscribeAckHeaderFlags.All, sizeof (rxSubackPacket.subscribeAckHeaderFlags.All));
   MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, &rxSubackPacket.remainingLength[0], sizeof (rxSubackPacket.remainingLength[0]));
   MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, &rxSubackPacket.packetIdentifierMSB, sizeof (rxSubackPacket.packetIdentifierMSB));
   MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, &rxSubackPacket.packetIdentifierLSB, sizeof (rxSubackPacket.packetIdentifierLSB));
   // The packetIdentifier of the SUBACK packet must match the
   // packetIdentifier of the SUBSCRIBE packet. Since the library allows
   // the application to create only one SUBSCRIBE packet at a time,
   // checking this condition becomes simple.
   if ((rxSubackPacket.packetIdentifierLSB != txSubscribePacket.packetIdentifierLSB) || (rxSubackPacket.packetIdentifierMSB != txSubscribePacket.packetIdentifierMSB)) {
      // Change state appropriately
      ret = DISCONNECTED;
   } else {
      // ToDo remove hardcoding
      MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, rxSubackPacket.returnCode, 1);
      // ToDo This calculation needs to be modified after removing
      // hardcoding
      topicNumbers = (sizeof (rxSubackPacket.returnCode) / sizeof (rxSubackPacket.returnCode[0]));
      for (topicCount = 0; topicCount < topicNumbers; topicCount++) {
         if (rxSubackPacket.returnCode[topicCount] == SUBSCRIBE_FAILURE) {
            // Change state appropriately
            ret = DISCONNECTED;
            break;
         } else {
            //The Server might grant a lower maximum QoS than the subscriber requested.
            if (rxSubackPacket.returnCode[topicCount] <= txSubscribePacket.subscribePayload[topicCount].requestedQoS) {
               ret = CONNECTED;
            } else {
               // Change state appropriately
               ret = DISCONNECTED;
               break;
            }
         }
      }
   }

   mqttRxFlags.newRxSubackPacket = 0;
   // Re-initialize the RX exchange buffer to be able to process the
   // next incoming MQTT packet
   MQTT_ExchangeBufferInit(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff);
   return ret;
}

static mqttCurrentState mqttProcessUnsuback(mqttContext *mqttConnectionPtr) 
{
	mqttCurrentState ret;
	mqttUnsubackPacket rxUnsubackPacket;

	memset(&rxUnsubackPacket, 0, sizeof (rxUnsubackPacket));
	
	ret = CONNECTED;

	MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, &rxUnsubackPacket.unsubAckHeaderFlags.All, sizeof (rxUnsubackPacket.unsubAckHeaderFlags.All));
	MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, &rxUnsubackPacket.remainingLength, sizeof (rxUnsubackPacket.remainingLength));
	if(rxUnsubackPacket.remainingLength != 2)
	{
		// The length of the variable header for UNSUBACK Packet has to be 2 
        // according to MQTT RFC, section 3.11.1.
		ret = DISCONNECTED;
	}
    else
    {	
        MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, &rxUnsubackPacket.packetIdentifierMSB, sizeof (rxUnsubackPacket.packetIdentifierMSB));
        MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, &rxUnsubackPacket.packetIdentifierLSB, sizeof (rxUnsubackPacket.packetIdentifierLSB));
        // The packetIdentifier of the UNSUBACK packet must match the
        // packetIdentifier of the UNSUBSCRIBE packet. Since the library allows
        // the application to create only one UNSUBSCRIBE packet at a time,
        // checking this condition becomes simple.
        if ((rxUnsubackPacket.packetIdentifierLSB != txUnsubscribePacket.packetIdentifierLSB) || (rxUnsubackPacket.packetIdentifierMSB != txUnsubscribePacket.packetIdentifierMSB)) 
        {
            // Change state appropriately
            ret = DISCONNECTED;
        } 
    }
    
	mqttRxFlags.newRxUnsubackPacket = 0;
	// Re-initialize the RX exchange buffer to be able to process the
	// next incoming MQTT packet
	MQTT_ExchangeBufferInit(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff);
	return ret;
}

static mqttCurrentState mqttProcessPublish(mqttContext *mqttConnectionPtr) {
   mqttCurrentState ret;
   uint32_t decodedLength;
   mqttPublishPacket rxPublishPacket;
   const publishReceptionHandler_t *publishRecvHandlerInfo;
   uint8_t i;

   uint8_t mqttTopic[TOPIC_SIZE];
   uint8_t mqttPayload[PAYLOAD_SIZE];

   decodedLength = 0;

   memset(&rxPublishPacket, 0, sizeof (rxPublishPacket));
   memset(mqttTopic, 0, sizeof (mqttTopic));
   memset(mqttPayload, 0, sizeof (mqttPayload));

   // Fixed header
   MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, &rxPublishPacket.publishHeaderFlags.All, sizeof (rxPublishPacket.publishHeaderFlags.All));
   MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, &rxPublishPacket.remainingLength[0], sizeof (rxPublishPacket.remainingLength[0]));
   for (i = 2; rxPublishPacket.remainingLength[i - 1] & 0x80 && i < sizeof (rxPublishPacket.remainingLength); i++) {
      MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, &rxPublishPacket.remainingLength[i], 1);
   }
   decodedLength = mqttDecodeLength(&rxPublishPacket.remainingLength[0]);

   // Variable header
   MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, (uint8_t*) & rxPublishPacket.topicLength, sizeof (rxPublishPacket.topicLength));
   decodedLength -= sizeof (rxPublishPacket.topicLength);
   rxPublishPacket.topic = (uint8_t*) mqttTopic;
   MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, rxPublishPacket.topic, ntohs(rxPublishPacket.topicLength));
   decodedLength -= ntohs(rxPublishPacket.topicLength);

   // Payload
   rxPublishPacket.payload = (uint8_t*) mqttPayload;
   MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, rxPublishPacket.payload, decodedLength);

   // Send payload information to the application
   publishRecvHandlerInfo = MQTT_GetPublishReceptionHandlerTable();
   for (i = 0; i < NUM_TOPICS_SUBSCRIBE; i++) {
      if (publishRecvHandlerInfo) {
         if (memcmp((void*) publishRecvHandlerInfo->topic, (void*) rxPublishPacket.topic, ntohs(rxPublishPacket.topicLength)) == 0) {
            publishRecvHandlerInfo->mqttHandlePublishDataCallBack(rxPublishPacket.topic, rxPublishPacket.payload);
            break;
         }
      }
      publishRecvHandlerInfo++;
   }

   // Re-initialize the RX exchange buffer to be able to process the
   // next incoming MQTT packet
   MQTT_ExchangeBufferInit(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff);
   ret = CONNECTED;
   return ret;
}

static void mqttProcessPuback(mqttContext *mqttConnectionPtr) {
   mqttPubackPacket rxPubackPacket;
   memset(&rxPubackPacket, 0, sizeof (rxPubackPacket));
   MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, (uint8_t*) & rxPubackPacket.pubackFixedHeader, sizeof (rxPubackPacket.pubackFixedHeader));
   MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, &rxPubackPacket.remainingLength, sizeof (rxPubackPacket.remainingLength));
   MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, &rxPubackPacket.packetIdentifierMSB, sizeof (rxPubackPacket.packetIdentifierMSB));
   MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, &rxPubackPacket.packetIdentifierLSB, sizeof (rxPubackPacket.packetIdentifierLSB));
   if (rxPubackPacket.packetIdentifierLSB == txPublishPacket.packetIdentifierLSB && rxPubackPacket.packetIdentifierMSB == txPublishPacket.packetIdentifierMSB) {
      mqttRxFlags.newRxPubackPacket = 0;
   }
}

mqttCurrentState MQTT_TransmissionHandler(mqttContext *mqttConnectionPtr) {
   uint16_t keepAliveTimeout = 0;
   bool packetSent = false;
   uint8_t getSetFlag = 0;

   switch (mqttState) {
      case CONNECTING:
      case DISCONNECTED:
         if (mqttTxFlags.newTxConnectPacket == 1) {
            packetSent = mqttSendConnect(mqttConnectionPtr);
         }
         if (packetSent == true) {
            // The timeout API names are different in MCC foundation
            // services timeout driver and START timeout driver
            checkConnackTimeoutStateHandle = SYS_TIME_CallbackRegisterMS(checkConnackTimeoutStatecb, 0, WAITFORCONNACK_TIMEOUT, SYS_TIME_SINGLE);
            mqttState = WAITFORCONNACK;
            connackTimeoutOccured = false;
         }
         break;

      case CONNECTED:
         // ToDo Find out ways to improve this logic
         if (mqttTxFlags.All > 0) {
            while ((mqttTxFlags.All & (MQTT_TX_PACKET_DECISION_CONSTANT << getSetFlag)) == 0) {
               getSetFlag++;
            }
            mqttConnectTxSubstate = (MQTT_TX_PACKET_DECISION_CONSTANT << getSetFlag);
            switch (mqttConnectTxSubstate) {
               case SENDPINGREQ:
                  if (pingreqTimeoutOccured == true) {
                     // Change state for the next timeout to occur correctly
                     pingreqTimeoutOccured = false;
                     // Periodic sending of PINGREQ packet
                     mqttSendPingreq(mqttConnectionPtr);
                  }
                  break;
               case SENDPUBLISH:
                  SYS_TIME_TimerDestroy(checkPingreqTimeoutStateHandle);
                  packetSent = mqttSendPublish(mqttConnectionPtr);

                     keepAliveTimeout = ntohs(txConnectPacket.connectVariableHeader.keepAliveTimer);
                     if (txConnectPacket.connectVariableHeader.keepAliveTimer > 0) {
                        checkPingreqTimeoutStateHandle = SYS_TIME_CallbackRegisterMS(checkPingreqTimeoutStatecb, 0, ((keepAliveTimeout - KEEP_ALIVE_CALCULATION_CONSTANT) * SECONDS), SYS_TIME_SINGLE);
                     }
                  break;
               case SENDSUBSCRIBE:
                  SYS_TIME_TimerDestroy(checkPingreqTimeoutStateHandle);
                  mqttSendSubscribe(mqttConnectionPtr);
                  keepAliveTimeout = ntohs(txConnectPacket.connectVariableHeader.keepAliveTimer);
				  if (txConnectPacket.connectVariableHeader.keepAliveTimer > 0) {
                    checkPingreqTimeoutStateHandle = SYS_TIME_CallbackRegisterMS(checkPingreqTimeoutStatecb, 0, ((keepAliveTimeout - KEEP_ALIVE_CALCULATION_CONSTANT) * SECONDS), SYS_TIME_SINGLE);
				  }
                  break;
               case SENDUNSUBSCRIBE:
                  SYS_TIME_TimerDestroy(checkPingreqTimeoutStateHandle);
                  mqttSendUnsubscribe(mqttConnectionPtr);
                  keepAliveTimeout = ntohs(txConnectPacket.connectVariableHeader.keepAliveTimer);
                  if (txConnectPacket.connectVariableHeader.keepAliveTimer > 0) {
                    checkPingreqTimeoutStateHandle = SYS_TIME_CallbackRegisterMS(checkPingreqTimeoutStatecb, 0, ((keepAliveTimeout - KEEP_ALIVE_CALCULATION_CONSTANT) * SECONDS), SYS_TIME_SINGLE);
				  }
                  break;
               default:
                  break;
            }
         }
         break;
      default:
         // Go to DISCONNECTED?
         break;
   }
   return mqttState;
}

mqttCurrentState MQTT_ReceptionHandler(mqttContext *mqttConnectionPtr) {
   uint16_t keepAliveTimeout;
   mqttHeaderFlags receivedPacketHeader;

   keepAliveTimeout = 0;
   receivedPacketHeader.All = 0;

   if(pingrespTimeoutOccured == true || subackTimeoutOccured == true || unsubackTimeoutOccured == true)
   {
	  // This implies that expected response has not been received from  
	  // the server in a reasonable period of time (currently set to 30s).
	  // This is treated as a protocol violation. The client therefore
	  // will close the Network Connection (MQTT RFC, section 4.8).
	  mqttState = DISCONNECTED;
      MQTT_Close(mqttConnectionPtr);
   }
   // If nothing to process
   if (mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff.dataLength == 0)
      return mqttState;

   switch (mqttState) {
      case WAITFORCONNACK:
         keepAliveTimeout = ntohs(txConnectPacket.connectVariableHeader.keepAliveTimer);
         if (connackTimeoutOccured == false) {
            // The timeout API names are different in MCC foundation
            // services timeout driver and START timeout driver
            SYS_TIME_TimerDestroy(checkConnackTimeoutStateHandle);
            // Check the type of packet
            uint16_t len = MQTT_ExchangeBufferPeek(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, &receivedPacketHeader.All, sizeof (receivedPacketHeader.All));

            if (receivedPacketHeader.controlPacketType == CONNACK) 
            {
               mqttState = mqttProcessConnack(mqttConnectionPtr);
               if (mqttState == CONNECTED) {
                  if (keepAliveTimeout != 0) {
                     // Send a PINGREQ packet after (keepAliveTimer - KEEP_ALIVE_CALCULATION_CONSTANT)s
                     // if keepAliveTime is non-zero
                     mqttTxFlags.newTxPingreqPacket = 1;
                     // The timeout API names are different in MCC foundation
                     // services timeout driver and START timeout driver
                     checkPingreqTimeoutStateHandle = SYS_TIME_CallbackRegisterMS(checkPingreqTimeoutStatecb, 0, ((keepAliveTimeout - KEEP_ALIVE_CALCULATION_CONSTANT) * SECONDS), SYS_TIME_SINGLE);
                  }
                    struct tm sys_time;
                    RTC_RTCCTimeGet(&sys_time);
                    connectTime = mktime(&sys_time);
                    //connectTime = time(NULL);
                    debug_printGOOD("MQTT: CONNACK CONNECTED at %s", ctime(&connectTime));
               } else {
                  debug_printError("MQTT: CONNACK DISCONNECTED :(");
               }
            } else {
               debug_printError("MQTT: DISCONNECT (%d) from (%d)", receivedPacketHeader.controlPacketType, len);
               //If the Client does not receive a CONNACK Packet from the Server within a reasonable amount of time,
               //the Client SHOULD close the Network Connection.
               mqttState = DISCONNECTED;
               MQTT_Close(mqttConnectionPtr);
            }
         } else {
            mqttState = DISCONNECTED;
            MQTT_Close(mqttConnectionPtr);
            debug_printError("MQTT: CONNACK TIMEOUT");
         }
         break;

      case CONNECTED:
         // Check the type of packet
         MQTT_ExchangeBufferPeek(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, &receivedPacketHeader.All, sizeof (receivedPacketHeader.All));

         switch (receivedPacketHeader.controlPacketType) {
            case PINGRESP:
               // PINGRESP received
               if ((mqttRxFlags.newRxPingrespPacket == 1) && (pingrespTimeoutOccured == false)) {
                  SYS_TIME_TimerDestroy(checkPingrespTimeoutStateHandle);
                  mqttProcessPingresp(mqttConnectionPtr);
               }
               break;
            case SUBACK:
               // SUBACK received
               if ((mqttRxFlags.newRxSubackPacket == 1) && (subackTimeoutOccured == false)) {
                  SYS_TIME_TimerDestroy(checkSubackTimeoutStateHandle);
                  mqttState = mqttProcessSuback(mqttConnectionPtr);
               }
               break;
               case UNSUBACK:
               // UNSUBACK received
               if ((mqttRxFlags.newRxUnsubackPacket == 1) && (unsubackTimeoutOccured == false)) 
			   {
                   SYS_TIME_TimerDestroy(checkUnsubackTimeoutStateHandle);
	               mqttState = mqttProcessUnsuback(mqttConnectionPtr);
	           } 
               break;
            case PUBLISH:
               // PUBLISH received
               mqttProcessPublish(mqttConnectionPtr);
               break;
            case PUBACK:
               mqttProcessPuback(mqttConnectionPtr);
               break;
            default:
               break;
         }
         break;
         
      case CONNECTING:
         break;
         
      default:
         debug_printError("MQTT: mqttState=%d", mqttState);
         break;
   }

   return mqttState;
}


static bool mqttSendSubscribe(mqttContext *mqttConnectionPtr) {
   bool ret = false;
   uint8_t topicCount = 0;

   MQTT_ExchangeBufferInit(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff);
   MQTT_ExchangeBufferInit(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff);

   // Copy the txSubscribePacket data in TCP Tx buffer
   MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, &txSubscribePacket.subscribeHeaderFlags.All, sizeof (txSubscribePacket.subscribeHeaderFlags.All));
   MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, txSubscribePacket.remainingLength, mqttEncodeLength(txSubscribePacket.totalLength, txSubscribePacket.remainingLength));
   MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, &txSubscribePacket.packetIdentifierMSB, sizeof (txSubscribePacket.packetIdentifierMSB));
   MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, &txSubscribePacket.packetIdentifierLSB, sizeof (txSubscribePacket.packetIdentifierLSB));

   for (topicCount = 0; topicCount < NUM_TOPICS_SUBSCRIBE; topicCount++) {
      MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, (uint8_t*) & txSubscribePacket.subscribePayload[topicCount].topicLength, sizeof (txSubscribePacket.subscribePayload[topicCount].topicLength));
      MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, txSubscribePacket.subscribePayload[topicCount].topic, ntohs(txSubscribePacket.subscribePayload[topicCount].topicLength));
      MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, &txSubscribePacket.subscribePayload[topicCount].requestedQoS, sizeof (txSubscribePacket.subscribePayload[topicCount].requestedQoS));
   }
   
   ret = MQTT_Send(mqttConnectionPtr);
   if (ret == true) {
       mqttTxFlags.newTxSubscribePacket = 0;
       mqttRxFlags.newRxSubackPacket = 1;
	   
	   //The timeout API names are different in MCC foundation
	   //services timeout driver and START timeout driver
	   subackTimeoutOccured = false;
       checkSubackTimeoutStateHandle = SYS_TIME_CallbackRegisterMS(checkSubackTimeoutStatecb, 0, WAITFORSUBACK_TIMEOUT, SYS_TIME_SINGLE);
   }
   
   return ret;
}


static bool mqttSendUnsubscribe(mqttContext *mqttConnectionPtr) 
{
    bool ret = false;
	uint8_t topicCount = 0;
    
    MQTT_ExchangeBufferInit(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff);
    MQTT_ExchangeBufferInit(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff);
    
    // Copy the txUnsubscribePacket data in TCP Tx buffer
    MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, &txUnsubscribePacket.unsubscribeHeaderFlags.All, sizeof(txUnsubscribePacket.unsubscribeHeaderFlags.All));
    MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, txUnsubscribePacket.remainingLength, mqttEncodeLength(txUnsubscribePacket.totalLength, txUnsubscribePacket.remainingLength));
    MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, &txUnsubscribePacket.packetIdentifierMSB, sizeof(txUnsubscribePacket.packetIdentifierMSB));
    MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, &txUnsubscribePacket.packetIdentifierLSB, sizeof(txUnsubscribePacket.packetIdentifierLSB));
    
    for (topicCount = 0; topicCount < NUM_TOPICS_UNSUBSCRIBE; topicCount++) 
    {
        MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, (uint8_t*)&txUnsubscribePacket.unsubscribePayload[topicCount].topicLength, sizeof(txUnsubscribePacket.unsubscribePayload[topicCount].topicLength));
        MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, txUnsubscribePacket.unsubscribePayload[topicCount].topic, ntohs(txUnsubscribePacket.unsubscribePayload[topicCount].topicLength));
    }
    
        ret = MQTT_Send(mqttConnectionPtr);
        if (ret == true) 
        {
            mqttTxFlags.newTxUnsubscribePacket = 0;
            mqttRxFlags.newRxUnsubackPacket = 1;

        //The timeout API names are different in MCC foundation
        //services timeout driver and START timeout driver
        unsubackTimeoutOccured = false;
        checkUnsubackTimeoutStateHandle = SYS_TIME_CallbackRegisterMS(checkUnsubackTimeoutStatecb, 0, WAITFORUNSUBACK_TIMEOUT, SYS_TIME_SINGLE);
        }
    
    return ret;
}


static bool mqttSendPingreq(mqttContext *mqttConnectionPtr) {
   bool ret;
   mqttPingPacket txPingreqPacket;

   ret = false;
   memset(&txPingreqPacket, 0, sizeof (txPingreqPacket));
   MQTT_ExchangeBufferInit(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff);
   MQTT_ExchangeBufferInit(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff);

   // Send a PINGREQ packet here
   txPingreqPacket.pingFixedHeader.controlPacketType = PINGREQ;
   txPingreqPacket.pingFixedHeader.duplicate = 0;
   txPingreqPacket.pingFixedHeader.qos = 0;
   txPingreqPacket.pingFixedHeader.retain = 0;
   txPingreqPacket.remainingLength = 0;

   MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, &txPingreqPacket.pingFixedHeader.All, sizeof (txPingreqPacket.pingFixedHeader.All));
   MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, &txPingreqPacket.remainingLength, sizeof (txPingreqPacket.remainingLength));

   ret = MQTT_Send(mqttConnectionPtr);
   if (ret == true) {
       mqttTxFlags.newTxPingreqPacket = 0;
       // Expect a PINGRESP packet
       mqttRxFlags.newRxPingrespPacket = 1;
       // The client expects the server to send a PINGRESP within
       // keepAliveTimer value.
       
       //The timeout API names are different in MCC foundation
       //services timeout driver and START timeout driver
       checkPingrespTimeoutStateHandle = SYS_TIME_CallbackRegisterMS(checkPingrespTimeoutStatecb, 0, WAITFORPINGRESP_TIMEOUT, SYS_TIME_PERIODIC);
   }
   
   return ret;
}

static bool mqttSendDisconnect(mqttContext *mqttConnectionPtr) {
   bool ret = false;
   mqttDisconnectPacket txDisconnectPacket;

   memset(&txDisconnectPacket, 0, sizeof (txDisconnectPacket));
   MQTT_ExchangeBufferInit(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff);
   MQTT_ExchangeBufferInit(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff);

   txDisconnectPacket.disconnectFixedHeader.controlPacketType = DISCONNECT;
   txDisconnectPacket.disconnectFixedHeader.retain = 0;
   txDisconnectPacket.disconnectFixedHeader.qos = 0;
   txDisconnectPacket.disconnectFixedHeader.duplicate = 0;

   MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, &txDisconnectPacket.disconnectFixedHeader.All, sizeof (txDisconnectPacket.disconnectFixedHeader.All));
   MQTT_ExchangeBufferWrite(&mqttConnectionPtr->mqttDataExchangeBuffers.txbuff, &txDisconnectPacket.remainingLength, sizeof (txDisconnectPacket.remainingLength));

   ret = MQTT_Send(mqttConnectionPtr);

   if (ret == true) {
      mqttTxFlags.All = 0;
   }
   return ret;
}

static mqttCurrentState mqttProcessConnack(mqttContext *mqttConnectionPtr) {
   mqttConnackPacket_t mqttConnackPacket;

   memset(&mqttConnackPacket, 0, sizeof (mqttConnackPacket));

   // Check 1st (4) bytes in Rx MQTT Packet
   MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, &mqttConnackPacket.connackFixedHeader.All, sizeof (mqttConnackPacket.connackFixedHeader.All));
   MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, &mqttConnackPacket.remainingLength, sizeof (mqttConnackPacket.remainingLength));
   MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, &mqttConnackPacket.connackVariableHeader.connackAcknowledgeFlags.All, sizeof (mqttConnackPacket.connackVariableHeader.connackAcknowledgeFlags.All));
   MQTT_ExchangeBufferRead(&mqttConnectionPtr->mqttDataExchangeBuffers.rxbuff, &mqttConnackPacket.connackVariableHeader.connackReturnCode, sizeof (mqttConnackPacket.connackVariableHeader.connackReturnCode));

   if (mqttConnackPacket.connackVariableHeader.connackReturnCode == CONN_ACCEPTED) {
      return CONNECTED;
      } else {
      return DISCONNECTED;
   }
}

void MQTT_sched(void)
{
    if(checkConnackTimeoutStateTmrExpired == true) {
        checkConnackTimeoutStateTmrExpired = false;
        checkConnackTimeoutState();
    }
    
    if(checkPingreqTimeoutStateTmrExpired == true) {
        checkPingreqTimeoutStateTmrExpired = false;
        checkPingreqTimeoutState();
    }

    if(checkSubackTimeoutStateTmrExpired == true) {
        checkSubackTimeoutStateTmrExpired = false;
        checkSubackTimeoutState();
    }

    if(checkUnsubackTimeoutStateTmrExpired == true) {
        checkUnsubackTimeoutStateTmrExpired = false;
        checkUnsubackTimeoutState();
    }

    if(checkPingrespTimeoutStateTmrExpired == true) {
        checkPingrespTimeoutStateTmrExpired = false;
        checkPingrespTimeoutState();	
    }
}    