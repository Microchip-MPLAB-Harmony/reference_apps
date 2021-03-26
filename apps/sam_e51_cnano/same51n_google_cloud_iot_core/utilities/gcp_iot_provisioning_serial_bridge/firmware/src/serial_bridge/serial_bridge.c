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

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "serial_bridge.h"
#include "platform/platform.h"
#include "nmdrv.h"
#include "nmbus.h"
#if defined(WDRV_WINC_DEVICE_WINC1500)
#include "m2m_wifi.h"
#endif

#define SB_HEADER_SIZE      12

typedef enum
{
    SB_COMMAND_READ_REG_WITH_RET = 0,
    SB_COMMAND_WRITE_REG         = 1,
    SB_COMMAND_READ_BLOCK        = 2,
    SB_COMMAND_WRITE_BLOCK       = 3,
    SB_COMMAND_RECONFIGURE       = 5
} SB_COMMAND;

typedef enum
{
    SB_RESPONSE_NACK        = 0x5a,
    SB_RESPONSE_ID_VAR_BR   = 0x5b,
    SB_RESPONSE_ID_FIXED_BR = 0x5c,
    SB_RESPONSE_ACK         = 0xac
} SB_RESPONSE;

static bool _ProcessHeader(SERIAL_BRIDGE_DECODER_STATE *const pSBDecoderState, uint8_t *pHeader)
{
    uint8_t checksum;
    uint8_t i;

    if ((NULL == pSBDecoderState) || (NULL == pHeader))
    {
        return false;
    }

    checksum = 0;

    for (i=0; i<SB_HEADER_SIZE; i++)
    {
        checksum ^= pHeader[i];
    }

    if (0 != checksum)
    {
        return false;
    }

    pSBDecoderState->cmdType = pHeader[0];
    pSBDecoderState->cmdSize = (((uint16_t)pHeader[3]) << 8) | pHeader[2];
    pSBDecoderState->cmdAddr = (((uint32_t)pHeader[7]) << 24) | (((uint32_t)pHeader[6]) << 16) | (((uint32_t)pHeader[5]) << 8) | pHeader[4];
    pSBDecoderState->cmdVal  = (((uint32_t)pHeader[11]) << 24) | (((uint32_t)pHeader[10]) << 16) | (((uint32_t)pHeader[9]) << 8) | pHeader[8];

    if (pSBDecoderState->cmdType == SB_COMMAND_WRITE_BLOCK)
    {
        pSBDecoderState->payloadLength = pSBDecoderState->cmdSize;

        if (pSBDecoderState->payloadLength > SB_CMD_BUFFER_SIZE)
        {
            return false;
        }
    }
    else
    {
        pSBDecoderState->payloadLength = 0;
    }

    return true;
}

static bool _ProcessCommand(SERIAL_BRIDGE_DECODER_STATE *const pSBDecoderState)
{
    uint_fast16_t cnt;

    if (NULL == pSBDecoderState)
    {
        return false;
    }

    switch (pSBDecoderState->cmdType)
    {
        case SB_COMMAND_READ_REG_WITH_RET:
        {
            uint32_t regVal;

            regVal = nm_read_reg(pSBDecoderState->cmdAddr);

            pSBDecoderState->dataBuf[0] = (regVal >> 24) & 0xff;
            pSBDecoderState->dataBuf[1] = (regVal >> 16) & 0xff;
            pSBDecoderState->dataBuf[2] = (regVal >> 8) & 0xff;
            pSBDecoderState->dataBuf[3] = (regVal) & 0xff;

            if (false == SerialBridge_PlatformUARTWritePutBuffer(pSBDecoderState->dataBuf, 4))
            {
                return false;
            }

            return true;
        }

        case SB_COMMAND_WRITE_REG:
        {
            nm_write_reg(pSBDecoderState->cmdAddr, pSBDecoderState->cmdVal);

            return true;
        }

        case SB_COMMAND_READ_BLOCK:
        {
            cnt = pSBDecoderState->cmdSize;

            while (cnt >= SB_CMD_BUFFER_SIZE)
            {
                if (M2M_SUCCESS != nm_read_block(pSBDecoderState->cmdAddr, pSBDecoderState->dataBuf, SB_CMD_BUFFER_SIZE))
                    return false;

                if (false == SerialBridge_PlatformUARTWritePutBuffer(pSBDecoderState->dataBuf, SB_CMD_BUFFER_SIZE))
                    return false;
            }

            if (cnt)
            {
                if (M2M_SUCCESS != nm_read_block(pSBDecoderState->cmdAddr, pSBDecoderState->dataBuf, cnt))
                    return false;

                if (false == SerialBridge_PlatformUARTWritePutBuffer(pSBDecoderState->dataBuf, pSBDecoderState->cmdSize))
                    return false;
            }

            return true;
        }

        case SB_COMMAND_WRITE_BLOCK:
        {
            if (M2M_SUCCESS == nm_write_block(pSBDecoderState->cmdAddr, pSBDecoderState->dataBuf, pSBDecoderState->cmdSize))
            {
                pSBDecoderState->dataBuf[0] = SB_RESPONSE_ACK;
            }
            else
            {
                pSBDecoderState->dataBuf[0] = SB_RESPONSE_NACK;
            }

            return SerialBridge_PlatformUARTWritePutBuffer(pSBDecoderState->dataBuf, 1);
        }

        case SB_COMMAND_RECONFIGURE:
        {
            SerialBridge_PlatformUARTSetBaudRate(pSBDecoderState->cmdVal);

            pSBDecoderState->baudRate = pSBDecoderState->cmdVal;
            return true;
        }

        default:
        {
        }
    }

    return true;
}

void SerialBridge_Init(SERIAL_BRIDGE_DECODER_STATE *const pSBDecoderState, uint32_t baudRate)
{
    if (NULL == pSBDecoderState)
    {
        return;
    }

    pSBDecoderState->state = SERIAL_BRIDGE_STATE_WAIT_OP_CODE;
    pSBDecoderState->baudRate = baudRate;

    SerialBridge_PlatformUARTSetBaudRate(baudRate);

#if defined(WDRV_WINC_DEVICE_WINC1500)
    m2m_wifi_download_mode();
#elif defined(WDRV_WINC_DEVICE_WINC3400)
    nm_cpu_start();
#endif
}

void SerialBridge_Process(SERIAL_BRIDGE_DECODER_STATE *const pSBDecoderState)
{
    if (NULL == pSBDecoderState)
    {
        return;
    }

    switch (pSBDecoderState->state)
    {
        case SERIAL_BRIDGE_STATE_WAIT_OP_CODE:
        {
            uint8_t opCode;

            if (0 == SerialBridge_PlatformUARTReadGetBuffer(&opCode, 1))
            {
                break;
            }

            switch (opCode)
            {
                case 0x12:
                {
                    SerialBridge_PlatformUARTWritePutByte(SB_RESPONSE_ID_VAR_BR);
                    break;
                }

                case 0x13:
                {
                    break;
                }

                case 0xa5:
                {
                    pSBDecoderState->state = SERIAL_BRIDGE_STATE_WAIT_HEADER;
                    pSBDecoderState->rxDataLen = 0;
                    break;
                }

                default:
                {
                    break;
                }
            }

            break;
        }

        case SERIAL_BRIDGE_STATE_WAIT_HEADER:
        {
            pSBDecoderState->rxDataLen += SerialBridge_PlatformUARTReadGetBuffer(&pSBDecoderState->dataBuf[pSBDecoderState->rxDataLen], SB_HEADER_SIZE - pSBDecoderState->rxDataLen);

            if (SB_HEADER_SIZE != pSBDecoderState->rxDataLen)
            {
                break;
            }

            if (true == _ProcessHeader(pSBDecoderState, pSBDecoderState->dataBuf))
            {
                SerialBridge_PlatformUARTWritePutByte(SB_RESPONSE_ACK);

                if (pSBDecoderState->payloadLength > 0)
                {
                    pSBDecoderState->state = SERIAL_BRIDGE_STATE_WAIT_PAYLOAD;
                    pSBDecoderState->rxDataLen = 0;
                }
                else
                {
                    pSBDecoderState->state = SERIAL_BRIDGE_STATE_PROCESS_COMMAND;
                }
            }
            else
            {
                pSBDecoderState->state = SERIAL_BRIDGE_STATE_WAIT_OP_CODE;

                SerialBridge_PlatformUARTWritePutByte(SB_RESPONSE_NACK);
            }

            break;
        }

        case SERIAL_BRIDGE_STATE_PROCESS_COMMAND:
        {
            _ProcessCommand(pSBDecoderState);

            pSBDecoderState->state = SERIAL_BRIDGE_STATE_WAIT_OP_CODE;
            break;
        }

        case SERIAL_BRIDGE_STATE_WAIT_PAYLOAD:
        {
            pSBDecoderState->rxDataLen += SerialBridge_PlatformUARTReadGetBuffer(&pSBDecoderState->dataBuf[pSBDecoderState->rxDataLen], pSBDecoderState->payloadLength - pSBDecoderState->rxDataLen);

            if (pSBDecoderState->payloadLength == pSBDecoderState->rxDataLen)
            {
                _ProcessCommand(pSBDecoderState);

                pSBDecoderState->state = SERIAL_BRIDGE_STATE_WAIT_OP_CODE;
            }
            break;
        }

        default:
        {
            break;
        }
    }

    return;
}
