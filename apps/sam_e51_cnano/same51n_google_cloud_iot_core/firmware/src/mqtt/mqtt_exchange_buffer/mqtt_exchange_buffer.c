/*
    \file   mqtt_exchange_buffer.c

    \brief  MQTT buffer handling source file.

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

#include "mqtt_exchange_buffer.h"

void MQTT_ExchangeBufferInit(exchangeBuffer *buffer)
{
	buffer->currentLocation = buffer->start;
	buffer->dataLength = 0;
}

uint16_t MQTT_ExchangeBufferWrite(exchangeBuffer *buffer, uint8_t *data, uint16_t length)
{
	uint8_t *bend = buffer->start + buffer->bufferLength - 1;
	uint8_t *dend = (buffer->currentLocation - buffer->start + buffer->dataLength) % buffer->bufferLength + buffer->start;
    uint16_t i = 0;

	for (i = length; i > 0; i--) 
	{
		if (dend > bend)
		{
			dend = buffer->start;
		}
		if (buffer->dataLength != 0 && dend == buffer->currentLocation)
		{
			break;
		}
		*dend = *data;
		dend++;
		data++;
		buffer->dataLength++;
	}
    
	return length; 
}

uint16_t MQTT_ExchangeBufferPeek(exchangeBuffer *buffer, uint8_t *data, uint16_t length)
{
	uint8_t *ptr = buffer->currentLocation;
	uint8_t *bend = buffer->start + buffer->bufferLength - 1;
	uint16_t i = 0;

	for (i = 0; i < length && i < buffer->dataLength; i++) 
    {
		data[i] = ptr[i];
		if (ptr > bend)
        {
			ptr = buffer->start;
        }
	}

	return i;
}

uint16_t MQTT_ExchangeBufferRead(exchangeBuffer *buffer, uint8_t *data, uint16_t length)
{
	uint8_t *bend = buffer->start + buffer->bufferLength - 1;
	uint16_t i = 0;

	for (i = 0; i < length && buffer->dataLength > 0; i++) 
    {
		data[i] = *buffer->currentLocation;
		buffer->currentLocation++;
		buffer->dataLength--;
		if (buffer->currentLocation > bend)
        {
			buffer->currentLocation = buffer->start;
        }
	}
	return i; 
}
