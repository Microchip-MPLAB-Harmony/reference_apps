/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

/*
    Implementation of a circular buffer, useful especially for interrupt-driven UART communications.
    During development, a Alexa Connect Kit Host MCU will generally need to run two UARTs: one for
    debug prints and one for communication with the Alexa Connect Kit connectivity module. Doing this
    successfully using polling would be difficult of impossible because for example the Alexa Connect Kit
    implementation will want to print debug messages on one UART at the same time as the connectivity module
    may be sending data. Interrupt-driven UART operation is required.
*/

#include "ack_circularbuffer.h"

void ACK_InitializeCircularBuffer(volatile ACKCircularBuffer_t* pCircularBuffer)
{
	pCircularBuffer->tail = 0;
	pCircularBuffer->head = 0;
	pCircularBuffer->bufferState = CircularBuffer_Empty;
}

bool ACK_InsertIntoCircularBuffer(volatile ACKCircularBuffer_t* pCircularBuffer, uint8_t x)
{
    // Comment this block out if overwriting old data is acceptable.
    if (CircularBuffer_Full == pCircularBuffer->bufferState)
    {
        return false;
    }

    pCircularBuffer->buffer[pCircularBuffer->head] = x;
    pCircularBuffer->head = (pCircularBuffer->head + 1) % CIRCULAR_BUFFER_SIZE;

    pCircularBuffer->bufferState = (pCircularBuffer->tail == pCircularBuffer->head)
        ? CircularBuffer_Full
        : CircularBuffer_Partial;

    return true;
}

bool ACK_ReadFromCircularBuffer(volatile ACKCircularBuffer_t* pCircularBuffer, uint8_t* pX)
{
    if (CircularBuffer_Empty == pCircularBuffer->bufferState)
    {
        return false;
    }

    uint8_t x = pCircularBuffer->buffer[pCircularBuffer->tail];
    pCircularBuffer->tail = (pCircularBuffer->tail + 1) % CIRCULAR_BUFFER_SIZE;

    pCircularBuffer->bufferState = (pCircularBuffer->tail == pCircularBuffer->head)
        ? CircularBuffer_Empty
        : CircularBuffer_Partial;

    *pX = x;
    return true;
}
