/*
    \file   mqtt_core.h

    \brief  MQTT CORE source file.

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

#ifndef MQTT_CORE_H
#define	MQTT_CORE_H

#include <stdint.h>
//#include <time.h>
#include "../mqtt_comm_bsd/mqtt_comm_layer.h"
#include "socket.h"
#include "../../iot_config/mqtt_config.h"


/********************Timeout Driver for MQTT definitions***********************/
#define timerstruct_t                   timerStruct_t
#define htons(a)                        _htons(a)
#define ntohs(a)                        _ntohs(a)

// Timeout is calculated on the basis of clock frequency.
// This macros need to be changed in accordance with the clock frequency.
#define SECONDS (uint32_t)1000

#define WAITFORCONNACK_TIMEOUT              (30 * SECONDS)
#define WAITFORPINGRESP_TIMEOUT             (30 * SECONDS)
#define WAITFORSUBACK_TIMEOUT				(30 * SECONDS)
#define WAITFORUNSUBACK_TIMEOUT				(30 * SECONDS)


/*******************Timeout Driver for MQTT definitions*(END)******************/

/** \brief Basic MQTT states
 *
 * The application uses these states to manage state transitions in the MQTT Tx 
 * and Rx handlers.
 */
typedef enum
{
    DISCONNECTED = 0,
    CONNECTING = 1,
    WAITFORCONNACK = 2,
    CONNECTED = 3 
} mqttCurrentState;

/** \brief MQTT Control Packet types, as dictated by the MQTT standard
 *
 * The application uses these to determine the packet type of MQTT message.
 */
typedef enum 
{
    RESERVED       = 0,
	CONNECT        = 1,
	CONNACK        = 2,
	PUBLISH        = 3,
	PUBACK         = 4,
	SUBSCRIBE      = 8,
	SUBACK         = 9,
	UNSUBSCRIBE    = 10,
	UNSUBACK	   = 11,
	PINGREQ        = 12,
	PINGRESP	   = 13,
	DISCONNECT     = 14
} mqttControlPacketType_t;

// MQTT packet CONNACK return codes. These are defined in the MQTT documentation
// and indicate the success/ failure of establishing a connection with the 
// broker.
typedef enum
{
    CONN_ACCEPTED                     = 0,
    CONN_REFUSED_PROTOCOL_VER         = 1,
    CONN_REFUSED_ID_REJECTED          = 2,
    CONN_REFUSED_SERV_UNAVAILABLE     = 3,
    CONN_REFUSED_USERNAME_OR_PASSWORD = 4,
    CONN_REFUSED_NOT_AUTHORIZED       = 5
} connectReturnCode;

// MQTT SUBACK return codes are defined in MQTT documentation. The return code indicates the success/failure 
// and QoS level in case of success. The order of return codes must match the order of Topic Filters.
typedef enum
{
	SUBSCRIBE_SUCCESS_QoS0 = 0x00,
	SUBSCRIBE_SUCCESS_QoS1 = 0x01,
	SUBSCRIBE_SUCCESS_QoS2 = 0x02,
	SUBSCRIBE_FAILURE      = 0x80,		
} subscribeAckReturnCode;

/** \brief MQTT Fixed header format
 *
 * These are used by the application to handle the fixed header section of MQTT
 * control packet. 
 */
typedef union
{
    uint8_t All;
    struct
    { 
        unsigned retain                             : 1;    // Retain flag              // byte0, bit0
        unsigned qos                                : 2;    // Quality of Service flag  // byte0, bits 1, 2
        unsigned duplicate                          : 1;    // Duplicate delivery flag  // byte0, bit3
        unsigned controlPacketType                  : 4;    // MQTT Control Packet type // byte0, bits 4, 5, 6, 7        
    };
} mqttHeaderFlags;

/** \brief MQTT CONNECT packet
 *
 * This is used by the application to form a CONNECT packet. 
 */
typedef struct
{
    // Fixed header
    mqttHeaderFlags connectFixedHeaderFlags;   
    uint8_t remainingLength[4];                            // Remaining length a part of fixed header
    
    struct
    {
        // Variable header
        uint8_t protocolName[6];
        uint8_t protocolLevel;
        union
        {
            uint8_t All;
            struct
            {  
                uint8_t reserved                           : 1;    // Reserved // bit0
                uint8_t cleanSession                       : 1;    // "0" = Store session, "1" = Start new session // bit1
                uint8_t willFlag                           : 1;    // "0" = Will message absent, "1" = Will message present // bit2 
                uint8_t willQoS                            : 2;    // "00" = Will flag reset (0), QoS = 0 or Will flag set (1), QoS = 0
                                                                    // "01" = Will flag set (1), QoS = 1
                                                                    // "10" = Will flag set (1), QoS = 2 //bits 3, 4 
                uint8_t willRetain                         : 1;    // Retain flag // bit5  
                uint8_t passwordFlag                       : 1;    // "0" = Username absent, "1" = Username present // bit6
                uint8_t usernameFlag                       : 1;    // "0" = Password absent, "1" = Password present // bit7
            };
        } connectFlagsByte;
        uint16_t keepAliveTimer;
    } connectVariableHeader;
    
    // Payload
    uint16_t clientIDLength;
    uint8_t *clientID;
//    uint16_t willTopicLength;
//    uint8_t *willTopic;
//    uint16_t willMessageLength;
//    uint8_t *willMessage;
    uint16_t usernameLength;
    uint8_t *username;
    uint16_t passwordLength;
    uint8_t *password;

    // The variables defined in this section are not defined in the MQTT RFC as 
    // members of CONNECT packet but are required nevertheless for correct 
    // formatting of the CONNECT packet.
    uint16_t totalLength;
} mqttConnectPacket;

/** \brief MQTT CONNACK packet
 *
 * This is used by the application to process a CONNACK packet. 
 */
typedef struct
{
    // Fixed header
    mqttHeaderFlags connackFixedHeader;
    uint8_t remainingLength;
    
    // Variable header
    struct
    {
        union
        {
            uint8_t All;
            struct
            {
                unsigned sessionPresent		: 1;    // "0" = Store session, "1" = Start new session // bit0
                unsigned reserved           : 7;    // Reserved // bits 1-7
            }connackFlagBits;
        }connackAcknowledgeFlags;
        connectReturnCode connackReturnCode;
    } connackVariableHeader;
    
} mqttConnackPacket_t;

/** \brief MQTT PUBLISH packet
 *
 * This is used by the application to form and process a PUBLISH packet. 
 */
typedef struct
{
    // Fixed header
    mqttHeaderFlags publishHeaderFlags;
    uint8_t remainingLength[4];
    
    // Variable header
    // Topic name
    uint16_t topicLength;
    uint8_t *topic;
    // Packet identifier present only when QoS level = 1 or QoS level = 2 
    uint8_t packetIdentifierLSB;
    uint8_t packetIdentifierMSB;
    
    // Payload
    uint8_t payloadLength;
    uint8_t *payload; 
    
    uint16_t totalLength;
} mqttPublishPacket;

/** \brief MQTT PUBACK packet
 *
 * This is used by the application to process a PUBACK packet. 
 */
typedef struct
{
    mqttHeaderFlags pubackFixedHeader;
    uint8_t remainingLength;
    uint8_t packetIdentifierLSB;
    uint8_t packetIdentifierMSB;
}mqttPubackPacket;


/** \brief MQTT PING packet
 *
 * This is used by the application to form and process a PINGREQ/PINGRESP packet. 
 */
typedef struct
{
	// Fixed header
	mqttHeaderFlags pingFixedHeader;
	uint8_t remainingLength;	
} mqttPingPacket;

/** \brief MQTT DISCONNECT packet
 *
 * This is used by the application to form and send a DISCONNECT packet. 
 */

typedef struct
{
    // Fixed Header
    mqttHeaderFlags disconnectFixedHeader;
    uint8_t remainingLength;
} mqttDisconnectPacket;


/** \brief MQTT SUBSCRIBE Payload format
 *
 * These are used by the application to handle the payload section of MQTT
 * subscribe packet. 
 */
typedef struct
{
    // Topic name
    uint16_t topicLength;
    uint8_t *topic;
    // A valid SUBSCRIBE Packet should contain QoS level = 0 or QoS level = 1 or QoS level = 2 
    uint8_t requestedQoS;
} mqttSubscribePayload;

/** \brief MQTT SUBSCRIBE packet
 *
 * This is used by the application to form and send a SUBSCRIBE packet. 
 */
typedef struct
{
    // Fixed header
    mqttHeaderFlags subscribeHeaderFlags;
    uint8_t remainingLength[4];
    
    // Variable header
    uint8_t packetIdentifierLSB;
    uint8_t packetIdentifierMSB;
    
    // Payload
    // The payload of a SUBSCRIBE packet MUST contain at least one Topic Filter / QoS pair.
    mqttSubscribePayload subscribePayload[NUM_TOPICS_SUBSCRIBE];
	
    uint16_t totalLength;
} mqttSubscribePacket;

/** \brief MQTT SUBACK packet
 *
 * This is used by the application to process a SUBACK packet. 
 */
typedef struct
{
	// Fixed header
	mqttHeaderFlags subscribeAckHeaderFlags;
	uint8_t remainingLength[4];
		
	//variable header
	uint8_t packetIdentifierMSB;
	uint8_t packetIdentifierLSB;		
		
	//payload
	subscribeAckReturnCode returnCode[NUM_TOPICS_SUBSCRIBE];
} mqttSubackPacket;



/** \brief MQTT UNSUBSCRIBE Payload format
 *
 * These are used by the application to handle the payload section of MQTT
 * unsubscribe packet. 
 */
typedef struct
{
    // Topic name
    uint16_t topicLength;
    uint8_t *topic;
} mqttUnsubscribePayload;


/** \brief MQTT UNSUBSCRIBE packet
 *
 * This is used by the application to form and send an UNSUBSCRIBE packet. 
 */
typedef struct
{
    // Fixed header
    mqttHeaderFlags unsubscribeHeaderFlags;
    uint8_t remainingLength[4];
    
    // Variable header
    uint8_t packetIdentifierLSB;
    uint8_t packetIdentifierMSB;
    
    // Payload
    // The payload of a UNSUBSCRIBE packet MUST contain at least one Topic Filter / QoS pair.
    mqttUnsubscribePayload unsubscribePayload[NUM_TOPICS_UNSUBSCRIBE];
	
    uint16_t totalLength;
} mqttUnsubscribePacket;


/** \brief MQTT UNSUBACK packet
 *
 * This is used by the application to process a UNSUBACK packet. 
 */
typedef struct
{
	// Fixed header
	mqttHeaderFlags unsubAckHeaderFlags;
	uint8_t remainingLength;
		
	//variable header
	uint8_t packetIdentifierMSB;
	uint8_t packetIdentifierLSB;		
		
} mqttUnsubackPacket;


/***********************MQTT Client definitions*(END)**************************/

int32_t MQTT_getConnectionAge(void);
bool MQTT_CreateConnectPacket(mqttConnectPacket *newConnectPacket);
bool MQTT_CreatePublishPacket(mqttPublishPacket *newPublishPacket);
bool MQTT_CreateSubscribePacket(mqttSubscribePacket *newSubscribePacket);
bool MQTT_CreateUnsubscribePacket(mqttUnsubscribePacket *newUnsubscribePacket);
void MQTT_initialiseState(void);

mqttCurrentState MQTT_Disconnect(mqttContext *mqttContextPtr);
mqttCurrentState MQTT_TransmissionHandler(mqttContext *mqttContextPtr);
mqttCurrentState MQTT_ReceptionHandler(mqttContext *mqttContextPtr);

mqttCurrentState MQTT_GetConnectionState(void);

void MQTT_sched(void);


#endif	/* MQTT_CORE_H */

