/**
 *
 * Copyright (c) 2019 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#ifndef _SERIAL_BRIDGE_H
#define _SERIAL_BRIDGE_H

#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif

#define SB_CMD_BUFFER_SIZE  2048

typedef enum
{
    SERIAL_BRIDGE_STATE_UNKNOWN,
    SERIAL_BRIDGE_STATE_WAIT_OP_CODE,
    SERIAL_BRIDGE_STATE_WAIT_HEADER,
    SERIAL_BRIDGE_STATE_PROCESS_COMMAND,
    SERIAL_BRIDGE_STATE_WAIT_PAYLOAD,
} SERIAL_BRIDGE_STATE;

typedef struct
{
    SERIAL_BRIDGE_STATE state;
    uint32_t            baudRate;
    uint8_t             dataBuf[SB_CMD_BUFFER_SIZE];
    uint16_t            rxDataLen;
    uint8_t             cmdType;
    uint16_t            cmdSize;
    uint32_t            cmdAddr;
    uint32_t            cmdVal;
    uint16_t            payloadLength;
} SERIAL_BRIDGE_DECODER_STATE;

void SerialBridge_Init(SERIAL_BRIDGE_DECODER_STATE *const pSBDecoderState, uint32_t baudRate);
void SerialBridge_Process(SERIAL_BRIDGE_DECODER_STATE *const pSBDecoderState);

#ifdef __cplusplus
}
#endif

#endif /* _SERIAL_BRIDGE_H */
