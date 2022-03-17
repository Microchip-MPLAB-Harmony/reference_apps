/*
    \file   mqtt_comm_layer.h

    \brief  MQTT Communication layer header file.

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

#ifndef MQTT_COMM_LAYER_H
#define MQTT_COMM_LAYER_H

#include <stdint.h>
#include <stdbool.h>
#include "../mqtt_exchange_buffer/mqtt_exchange_buffer.h"

/** \brief MQTT connection information
 *
 * This is used by the application to store TCB, transmit buffer and receive 
 * buffer information. 
 */
typedef struct
{
   // Todo: The MQTTSTATE variable should be in the context. We have one state in the lib now with many buffer contexts.
   mqttBuffers mqttDataExchangeBuffers;
   int8_t* tcpClientSocket;
} mqttContext;


void MQTT_ClientInitialise(void);
mqttContext* MQTT_GetClientConnectionInfo();

bool MQTT_Send(mqttContext *connectionPtr);
bool MQTT_Close(mqttContext *connectionPtr);
void MQTT_GetReceivedData(uint8_t *pData, uint8_t len);
#endif /* MQTT_COMM_LAYER_H */
