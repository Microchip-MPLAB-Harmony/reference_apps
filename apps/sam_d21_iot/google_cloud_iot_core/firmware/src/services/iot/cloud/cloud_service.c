/*
    \file   cloud_service.c

    \brief  Cloud Service Abstraction Layer

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

#include <stdio.h>
#include <string.h>
#include <time.h>

#include "../../../iot_config/cloud_config.h"
#include "cloud_service.h"
#include "../../../iot_config/IoT_Sensor_Node_config.h"
#include "crypto_client/crypto_client.h"
#include "crypto_client/cryptoauthlib_main.h"
#include "../../../debug_print.h"
#include "m2m_wifi.h"
#include "../../../app.h"
#include "bsd_adapter/bsdWINC.h"
#include "socket.h"
#include "../cloud/mqtt_packetPopulation/mqtt_packetPopulate.h"
#include "../../../mqtt/mqtt_core/mqtt_core.h"
#include "wifi_service.h" 
#include "../../../credentials_storage/credentials_storage.h"
#include "../../../mqtt/mqtt_packetTransfer_interface.h"
#include "../../../cryptoauthlib/lib/basic/atca_basic.h"

#define UNIX_OFFSET  946684800

static bool cloudInitialized = false;
static bool waitingForMQTT = false;
   
const char projectId[] = CFG_PROJECT_ID;
const char projectRegion[] = CFG_PROJECT_REGION;
const char registryId[] = CFG_REGISTRY_ID;
char deviceId[CLOUD_MAX_DEVICEID_LENGTH];
char mqttSubscribeTopic[TOPIC_SIZE];

// Scheduler Callback functions
//uint32_t CLOUD_task(void *param);
//uint32_t mqttTimeoutTask(void *payload);
//uint32_t cloudResetTask(void *payload);

//static void dnsHandler(uint8_t * domainName, uint32_t serverIP);
static void updateJWT(uint32_t epoch);

static int8_t connectMQTTSocket(void);
static void connectMQTT();
static uint8_t reInit(void);

bool isResetting = false;
bool cloudResetTimerFlag = false;
bool sendSubscribe = true;
#define CLOUD_TASK_INTERVAL            500L
#define CLOUD_MQTT_TIMEOUT_COUNT	   10000L  // 10 seconds max allowed to establish a connection
#define MQTT_CONN_AGE_TIMEOUT          3600L   // 3600 seconds = 60minutes
#define CLOUD_RESET_TIMEOUT            2000L   // 2 seconds

SYS_TIME_HANDLE cloudResetTaskHandle    = SYS_TIME_HANDLE_INVALID;
SYS_TIME_HANDLE mqttTimeoutTaskHandle   = SYS_TIME_HANDLE_INVALID;

volatile bool mqttTimeoutTaskTmrExpired = false;
volatile bool cloudResetTaskTmrExpired = false;

void mqttTimeoutTask(void);
void cloudResetTask(void);

/** \brief MQTT publish handler call back table.
 *
 * This callback table lists the callback function for to be called on reception 
 * of a PUBLISH message for each topic which the application has subscribed to.
 * For each new topic which is subscribed to by the application, there needs to 
 * be a corresponding publish handler.
 * E.g.: For a particular topic 
 *       mchp/mySubscribedTopic/myDetailedPath
 *       Sample publish handler function  = void handlePublishMessage(uint8_t *topic, uint8_t *payload)
 * 
 */
publishReceptionHandler_t imqtt_publishReceiveCallBackTable[NUM_TOPICS_SUBSCRIBE];

uint32_t mqttGoogleApisComIP;

packetReceptionHandler_t cloud_packetReceiveCallBackTable[CLOUD_PACKET_RECV_TABLE_SIZE];

static char *ateccsn = NULL;

void CLOUD_setdeviceId(char *id)
{
   ateccsn = id;
}

void mqttTimeoutTaskcb(uintptr_t context)
{
    mqttTimeoutTaskTmrExpired = true;
}

void cloudResetTaskcb(uintptr_t context)
{
    cloudResetTaskTmrExpired = true;
}

void CLOUD_reset(void)
{
   debug_printError("CLOUD: Cloud Reset");
	cloudInitialized = false;
}

void mqttTimeoutTask(void)
{
   debug_printError("CLOUD: MQTT Connection Timeout");
   CLOUD_reset();
   waitingForMQTT = false;
}


void cloudResetTask(void)
{
	debug_printError("CLOUD: Reset task");
   cloudInitialized = reInit();  
}

static void connectMQTT()
{
    time_t currentTime;// = time(NULL);
    struct tm sys_time;

    RTC_RTCCTimeGet(&sys_time);
    currentTime = mktime(&sys_time);
    
   debug_print("CLOUD: Current Time = %d", currentTime);
   
   if (currentTime > 0)
   {
      // The JWT takes time in UNIX format (seconds since 1970)
      updateJWT(currentTime + UNIX_OFFSET);	  
	  MQTT_CLIENT_connect();
   }      
   debug_print("CLOUD: MQTT Connect");
   
   // MQTT SUBSCRIBE packet will be sent after the MQTT connection is established.
   sendSubscribe = true;
}

void CLOUD_subscribe(void)
{
	mqttSubscribePacket cloudSubscribePacket;
	uint8_t topicCount = 0;

	// Variable header
	cloudSubscribePacket.packetIdentifierLSB = 1;
	cloudSubscribePacket.packetIdentifierMSB = 0;

	// Payload
	for(topicCount = 0; topicCount < NUM_TOPICS_SUBSCRIBE; topicCount++)
	{
		sprintf(mqttSubscribeTopic, "/devices/%s/config", deviceId);
		cloudSubscribePacket.subscribePayload[topicCount].topic = (uint8_t *)mqttSubscribeTopic;
		cloudSubscribePacket.subscribePayload[topicCount].topicLength = strlen(mqttSubscribeTopic);
		cloudSubscribePacket.subscribePayload[topicCount].requestedQoS = 0;

		imqtt_publishReceiveCallBackTable[0].topic = mqttSubscribeTopic;
		imqtt_publishReceiveCallBackTable[0].mqttHandlePublishDataCallBack = APP_ReceivedFromCloud;
		MQTT_SetPublishReceptionHandlerTable(imqtt_publishReceiveCallBackTable);
	}
	
	if(MQTT_CreateSubscribePacket(&cloudSubscribePacket) == true)
	{
		debug_printInfo("CLOUD: SUBSCRIBE packet created");
		sendSubscribe = false;
	}
}

// This forces a disconnect, which forces a reconnect...
void CLOUD_disconnect(void){
    debug_printError("CLOUD: Disconnect");
    if (MQTT_GetConnectionState() == CONNECTED)
    {
        MQTT_Disconnect(MQTT_GetClientConnectionInfo());
    }
}

// Todo: This declaration supports the hack below
packetReceptionHandler_t* getSocketInfo(uint8_t sock);
static int8_t connectMQTTSocket(void)
{
   int8_t ret = false;
   
   if (mqttGoogleApisComIP > 0)
   {
      struct bsd_sockaddr_in addr;
       
      addr.sin_family = PF_INET;
      addr.sin_port = BSD_htons(443);
      addr.sin_addr.s_addr = mqttGoogleApisComIP;
       
      mqttContext  *context = MQTT_GetClientConnectionInfo();
      socketState_t  socketState = BSD_GetSocketState(*context->tcpClientSocket);
       
      // Todo: Check - Are we supposed to call close on the socket here to ensure we do not leak ?
      if (socketState == NOT_A_SOCKET)
      {
         *context->tcpClientSocket = BSD_socket(PF_INET, BSD_SOCK_STREAM, 1);
         
         if (*context->tcpClientSocket >=0)
         {
            packetReceptionHandler_t*  sockInfo = getSocketInfo(*context->tcpClientSocket);
            if (sockInfo != NULL)
            {
               sockInfo->socketState = SOCKET_CLOSED;
            }
         }
      }
   
      socketState = BSD_GetSocketState(*context->tcpClientSocket);
      if (socketState == SOCKET_CLOSED) {
         debug_print("CLOUD: Connect socket");
         ret = BSD_connect(*context->tcpClientSocket, (struct bsd_sockaddr *)&addr, sizeof(struct bsd_sockaddr_in));

         if (ret != BSD_SUCCESS) {
            debug_printError("CLOUD connect received %d",ret);
            shared_networking_params.haveERROR = 1;
            BSD_close(*context->tcpClientSocket);
         }
      }
   }   
   return ret;
}

void CLOUD_task(void)
{
	mqttContext* mqttConnnectionInfo = MQTT_GetClientConnectionInfo();
	socketState_t socketState;

	if (!cloudInitialized)
	{
      if (!isResetting)
      { 
        isResetting = true;
        debug_printError("CLOUD: Cloud reset timer is set");
        SYS_TIME_TimerStop(mqttTimeoutTaskHandle);
        cloudResetTaskHandle = SYS_TIME_CallbackRegisterMS(cloudResetTaskcb, 0, CLOUD_RESET_TIMEOUT, SYS_TIME_SINGLE);
        cloudResetTimerFlag = true;		 
      }      
	} else {
      if (!waitingForMQTT)
      {
         if((MQTT_GetConnectionState() != CONNECTED) && (cloudResetTimerFlag == false))
         {
            // Start the MQTT connection timeout
			debug_printError("MQTT: MQTT reset timer is created");
            mqttTimeoutTaskHandle = SYS_TIME_CallbackRegisterMS(mqttTimeoutTaskcb, 0, CLOUD_MQTT_TIMEOUT_COUNT, SYS_TIME_SINGLE);
            waitingForMQTT = true;
         }
      }
   }
   
   // If we have lost the AP we need to get the mqttState to disconnected
   if (shared_networking_params.haveAPConnection == 0)
   {
	  //Cleared on Access Point Connection
	  shared_networking_params.haveERROR = 1;
      if (MQTT_GetConnectionState() == CONNECTED)
      {
         MQTT_initialiseState();
      }
   }   
   else
   {
      static int32_t lastAge = -1;
      socketState = BSD_GetSocketState(*mqttConnnectionInfo->tcpClientSocket);

      int32_t thisAge = MQTT_getConnectionAge();
      time_t theTime;// = time(NULL);
      struct tm sys_time;
      RTC_RTCCTimeGet(&sys_time);
      theTime = mktime(&sys_time);

      if(theTime<=0)
      {
         debug_printError("CLOUD: time not ready");
      }
      else
      {
         if(MQTT_GetConnectionState() == CONNECTED)
         {
            if(lastAge != thisAge)
            {
               debug_printInfo("CLOUD: Uptime %lus SocketState (%d) MQTT (%d)", thisAge , socketState, MQTT_GetConnectionState());
               lastAge = thisAge;
            }
         }
      }
      
      switch(socketState)
	   {
         case NOT_A_SOCKET:
		   case SOCKET_CLOSED:
			  // Reinitialize MQTT
			  MQTT_ClientInitialise();			   
		     connectMQTTSocket(); 
		   break;
      
		   case SOCKET_CONNECTED:
            // If MQTT was disconnected but the socket is up we retry the MQTT connection
            if (MQTT_GetConnectionState() == DISCONNECTED)                 
            {
               connectMQTT();
            } 
			else 
			{
               MQTT_ReceptionHandler(mqttConnnectionInfo);
               MQTT_TransmissionHandler(mqttConnnectionInfo);

               // Todo: We already processed the data in place using PEEK, this just flushes the buffer
               BSD_recv(*MQTT_GetClientConnectionInfo()->tcpClientSocket, MQTT_GetClientConnectionInfo()->mqttDataExchangeBuffers.rxbuff.start, MQTT_GetClientConnectionInfo()->mqttDataExchangeBuffers.rxbuff.bufferLength, 0);
              
               if (MQTT_GetConnectionState() == CONNECTED)
               {
                  shared_networking_params.haveERROR = 0;           
                  SYS_TIME_TimerStop(mqttTimeoutTaskHandle);
                  SYS_TIME_TimerStop(cloudResetTaskHandle);
                  isResetting = false;

                  waitingForMQTT = false;      
				  
				  if(sendSubscribe == true)
				  { 
				      CLOUD_subscribe();
				  }				 
				               
                  // The Authorization timeout is set to 3600, so we need to re-connect that often
                  if (MQTT_getConnectionAge() > MQTT_CONN_AGE_TIMEOUT) {
					  debug_printError("MQTT: Connection aged, Uptime %lus SocketState (%d) MQTT (%d)", thisAge , socketState, MQTT_GetConnectionState());
                     MQTT_Disconnect(mqttConnnectionInfo);
                     BSD_close(*mqttConnnectionInfo->tcpClientSocket);
                  }
               } 
            }
		   break;

		   default:
            shared_networking_params.haveERROR = 1; 
		   break;
	   }
   }   
	//return CLOUD_TASK_INTERVAL;
}

bool CLOUD_isConnected(void)
{
   if (MQTT_GetConnectionState() == CONNECTED)
   {
      return true;
   } else {
      return false;
   }
}

void CLOUD_publishData(uint8_t* data, unsigned int len)
{
   MQTT_CLIENT_publish(data, len);
}

void dnsHandler(uint8_t* domainName, uint32_t serverIP)
{
    if(serverIP != 0)
    {
        mqttGoogleApisComIP = serverIP;
        debug_printInfo("CLOUD: mqttGoogleApisComIP = (%lu.%lu.%lu.%lu)",(0x0FF & (serverIP)),(0x0FF & (serverIP>>8)),(0x0FF & (serverIP>>16)),(0x0FF & (serverIP>>24)));
    }
}

char config_gcp_thing_id[20];
static void updateJWT(uint32_t epoch)
{
    uint8_t serial_num[9]; 
    int hex_size;
    uint16_t i;
   
    hex_size = sizeof(config_gcp_thing_id) - 1;
    config_gcp_thing_id[0] = 'd';
	 
	atcab_read_serial_number(serial_num);

	atcab_bin2hex_(serial_num, sizeof(serial_num), &config_gcp_thing_id[1], &hex_size, false);
    sprintf(deviceId, "%s", config_gcp_thing_id);
     
    sprintf(cid, "projects/%s/locations/%s/registries/%s/devices/%s", projectId, projectRegion, registryId, deviceId);
    sprintf(mqttTopic, "/devices/%s/events", deviceId);
    
    debug_printInfo("MQTT: CID=");
    for(i = 0; cid[i] != '\0'; i++)
    {
        debug_print("%c", cid[i]);
    }
       
    debug_printInfo("MQTT: mqttTopic=s");
    for(i = 0; mqttTopic[i] != '\0'; i++)
    {
        debug_print("%c", mqttTopic[i]);
    }


    debug_printInfo("JWT: epoch=%d", (epoch - UNIX_OFFSET));
    uint8_t res = CRYPTO_CLIENT_createJWT((char*)mqttPassword, PASSWORD_SPACE, (epoch - UNIX_OFFSET), projectId);

    time_t t = epoch - UNIX_OFFSET;
    debug_printInfo("JWT: Result(%d) at %s", res==0? 1 : -1, ctime(&t));
}

static uint8_t reInit(void)
{
    debug_printInfo("CLOUD: reinit");
    
    mqttGoogleApisComIP = 0;
    shared_networking_params.haveAPConnection = 0;
    waitingForMQTT = false;
    isResetting = false;
	uint8_t wifi_creds;
		   	
    registerSocketCallback(BSD_SocketHandler, dnsHandler);

    MQTT_ClientInitialise();
    memset(&cloud_packetReceiveCallBackTable, 0, sizeof(cloud_packetReceiveCallBackTable));
    BSD_SetRecvHandlerTable(cloud_packetReceiveCallBackTable);
    
    cloud_packetReceiveCallBackTable[0].socket = MQTT_GetClientConnectionInfo()->tcpClientSocket;
    cloud_packetReceiveCallBackTable[0].recvCallBack = MQTT_CLIENT_receive;

    //When the input comes through cli/.cfg
    if((strcmp(ssid,"") != 0) &&  (strcmp(authType,"") != 0))
    {
      wifi_creds = NEW_CREDENTIALS;
      debug_printInfo("Connecting to AP with new credentials");
    }
    //This works provided the board had connected to the AP successfully	
    else 
    {
      wifi_creds = DEFAULT_CREDENTIALS;
      debug_printInfo("Connecting to AP with the last used credentials");
    }
	
    if(!wifi_connectToAp(wifi_creds))
    {
           return false;
    }
	
    SYS_TIME_TimerStop(cloudResetTaskHandle);
    debug_printInfo("CLOUD: Cloud reset timer is deleted");

    mqttTimeoutTaskHandle = SYS_TIME_CallbackRegisterMS(mqttTimeoutTaskcb, 0, CLOUD_MQTT_TIMEOUT_COUNT, SYS_TIME_SINGLE);
    cloudResetTimerFlag = false;
    waitingForMQTT = true;		

    return true;
}

void CLOUD_sched(void)
{
    if(mqttTimeoutTaskTmrExpired == true) {
        mqttTimeoutTaskTmrExpired = false;
        mqttTimeoutTask();
    }
    
    if(cloudResetTaskTmrExpired == true) {
        cloudResetTaskTmrExpired = false;
        cloudResetTask();
    }
}

