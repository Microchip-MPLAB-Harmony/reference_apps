/*******************************************************************************
  MCP25625 click routine header file

  Company
    Microchip Technology Inc.

  File Name
    MCP25625.h

  Summary
    MCP25625 click routine header file.

  Description
    This file defines the interface to the MCP25625 click using SPI PLIB.
    This click routine provides MCU as SPI master device to communicate with 
    MCP25625 click.

  Remarks:
    None.

 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
    (c) 2022 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/
// DOM-IGNORE-END

#ifndef _MCP25625_H
#define _MCP25625_H

#include <stdint.h>
#include <stdbool.h>

/**
MCP25625 SPI Instruction Set
*/
#define MCP25625_RESET           0xC0

#define MCP25625_READ            0x03
#define MCP25625_READ_RXB0SIDH   0x90
#define MCP25625_READ_RXB0D0     0x92
#define MCP25625_READ_RXB1SIDH   0x94
#define MCP25625_READ_RXB1D0     0x96

#define MCP25625_WRITE           0x02
#define MCP25625_LOAD_TXB0SIDH   0x40
#define MCP25625_LOAD_TXB0D0     0x41
#define MCP25625_LOAD_TXB1SIDH   0x42
#define MCP25625_LOAD_TXB1D0     0x43
#define MCP25625_LOAD_TXB2SIDH   0x44
#define MCP25625_LOAD_TXB2D0     0x45

#define MCP25625_RTS_TX0         0x81
#define MCP25625_RTS_TX1         0x82
#define MCP25625_RTS_TX2         0x84
#define MCP25625_RTS_ALL         0x87
#define MCP25625_READ_STATUS     0xA0
#define MCP25625_RX_STATUS       0xB0
#define MCP25625_BIT_MOD         0x05

/**
MCP25625 Register Adresses
*/
#define MCP25625_RXF0SIDH	0x00
#define MCP25625_RXF0SIDL	0x01
#define MCP25625_RXF0EID8	0x02
#define MCP25625_RXF0EID0	0x03
#define MCP25625_RXF1SIDH	0x04
#define MCP25625_RXF1SIDL	0x05
#define MCP25625_RXF1EID8	0x06
#define MCP25625_RXF1EID0	0x07
#define MCP25625_RXF2SIDH	0x08
#define MCP25625_RXF2SIDL	0x09
#define MCP25625_RXF2EID8	0x0A
#define MCP25625_RXF2EID0	0x0B
#define MCP25625_CANSTAT	0x0E
#define MCP25625_CANCTRL	0x0F

#define MCP25625_RXF3SIDH	0x10
#define MCP25625_RXF3SIDL	0x11
#define MCP25625_RXF3EID8	0x12
#define MCP25625_RXF3EID0	0x13
#define MCP25625_RXF4SIDH	0x14
#define MCP25625_RXF4SIDL	0x15
#define MCP25625_RXF4EID8	0x16
#define MCP25625_RXF4EID0	0x17
#define MCP25625_RXF5SIDH	0x18
#define MCP25625_RXF5SIDL	0x19
#define MCP25625_RXF5EID8	0x1A
#define MCP25625_RXF5EID0	0x1B
#define MCP25625_TEC		0x1C
#define MCP25625_REC		0x1D	

#define MCP25625_RXM0SIDH	0x20
#define MCP25625_RXM0SIDL	0x21
#define MCP25625_RXM0EID8	0x22
#define MCP25625_RXM0EID0	0x23
#define MCP25625_RXM1SIDH	0x24
#define MCP25625_RXM1SIDL	0x25
#define MCP25625_RXM1EID8	0x26
#define MCP25625_RXM1EID0	0x27
#define MCP25625_CNF3		0x28
#define MCP25625_CNF2		0x29
#define MCP25625_CNF1		0x2A
#define MCP25625_CANINTE	0x2B
#define MCP25625_CANINTF	0x2C
#define MCP25625_EFLG		0x2D

#define MCP25625_TXB0CTRL	0x30
#define MCP25625_TXB1CTRL	0x40
#define MCP25625_TXB2CTRL	0x50
#define MCP25625_RXB0CTRL	0x60
#define MCP25625_RXB0SIDH	0x61
#define MCP25625_RXB1CTRL	0x70
#define MCP25625_RXB1SIDH	0x71

/**
Defines for Rx Status
*/
#define MSG_IN_RXB0             0x01
#define MSG_IN_RXB1             0x02
#define MSG_IN_BOTH_BUFFERS     0x03

#define dSTANDARD_CAN_MSG_ID_2_0B 1
#define dEXTENDED_CAN_MSG_ID_2_0B 2

typedef union{
    struct{
        unsigned RX0IF      : 1;
        unsigned RX1IF      : 1;
        unsigned TXB0REQ    : 1;
        unsigned TX0IF      : 1;
        unsigned TXB1REQ    : 1;
        unsigned TX1IF      : 1;
        unsigned TXB2REQ    : 1;
        unsigned TX2IF      : 1;
    };
    uint8_t ctrl_status;  
}ctrl_status_t;

typedef union{
    struct{
        unsigned filter     : 3;
        unsigned msgType    : 2;
        unsigned unusedBit  : 1;
        unsigned rxBuffer   : 2;
    };
    uint8_t ctrl_rx_status;
}ctrl_rx_status_t;

typedef union{
    struct{
        unsigned EWARN      :1;
        unsigned RXWAR      :1;
        unsigned TXWAR      :1;
        unsigned RXEP       :1;
        unsigned TXEP       :1;
        unsigned TXBO       :1;
        unsigned RX0OVR     :1;
        unsigned RX1OVR     :1;  
    };
    uint8_t error_flag_reg;
}ctrl_error_status_t;

typedef union{
    struct{
        uint8_t RXBnSIDH;
        uint8_t RXBnSIDL;
        uint8_t RXBnEID8;
        uint8_t RXBnEID0;
        uint8_t RXBnDLC;
        uint8_t RXBnD0;
        uint8_t RXBnD1;
        uint8_t RXBnD2;
        uint8_t RXBnD3;
        uint8_t RXBnD4;
        uint8_t RXBnD5;
        uint8_t RXBnD6;
        uint8_t RXBnD7;
    };
    uint8_t rx_reg_array[13];
}rx_reg_t;

/**
MCP25625 Registers
*/
typedef struct{
    uint8_t RXF0SIDH;
    uint8_t RXF0SIDL;
    uint8_t RXF0EID8;
    uint8_t RXF0EID0;
}RXF0;

typedef struct{
    uint8_t RXF1SIDH;
    uint8_t RXF1SIDL;
    uint8_t RXF1EID8;
    uint8_t RXF1EID0;
}RXF1;

typedef struct{
    uint8_t RXF2SIDH;
    uint8_t RXF2SIDL;
    uint8_t RXF2EID8;
    uint8_t RXF2EID0;
}RXF2;

typedef struct{
    uint8_t RXF3SIDH;
    uint8_t RXF3SIDL;
    uint8_t RXF3EID8;
    uint8_t RXF3EID0;
}RXF3;

typedef struct{
    uint8_t RXF4SIDH;
    uint8_t RXF4SIDL;
    uint8_t RXF4EID8;
    uint8_t RXF4EID0;
}RXF4;

typedef struct{
    uint8_t RXF5SIDH;
    uint8_t RXF5SIDL;
    uint8_t RXF5EID8;
    uint8_t RXF5EID0;
}RXF5;

typedef struct{
    uint8_t RXM0SIDH;
    uint8_t RXM0SIDL;
    uint8_t RXM0EID8;
    uint8_t RXM0EID0;
}RXM0;

typedef struct{
    uint8_t RXM1SIDH;
    uint8_t RXM1SIDL;
    uint8_t RXM1EID8;
    uint8_t RXM1EID0;
}RXM1;

typedef struct{
        uint8_t tempSIDH;
        uint8_t tempSIDL;
        uint8_t tempEID8;
        uint8_t tempEID0;
}id_reg_t;


typedef union {
    struct {
        uint8_t idType;
        uint32_t id;
        uint8_t dlc;
        uint8_t data0;
        uint8_t data1;
        uint8_t data2;
        uint8_t data3;
        uint8_t data4;
        uint8_t data5;
        uint8_t data6;
        uint8_t data7;
    } frame;
    uint8_t array[14];
} uCAN_MSG;

bool MCP25625_is_Awake(void);
void MCP25625_Reset(void);
void MCP25625_Read_RxbSequence(uint8_t readRxBuffInst, uint8_t rxLength, uint8_t *rxData);
void MCP25625_Write_Byte (uint8_t writeAddress, uint8_t writeData);
void MCP25625_Write_ByteSequence (uint8_t startAddress, uint8_t endAddress, uint8_t *data);
void MCP25625_Load_TxSequence (uint8_t txBuffInst, uint8_t* idReg, uint8_t dlc, uint8_t* txData);
void MCP25625_Load_TxBuffer (uint8_t loadTxBuffInst, uint8_t txBufferData);
void MCP25625_RequestToSend (uint8_t rtsTxBuffInst);
void MCP25625_Bit_Modify (uint8_t regAddress, uint8_t maskByte, uint8_t dataByte);
void MCP25625_Initialize(void);
void MCP25625_Sleep(void);
uint8_t MCP25625_Read_Byte (uint8_t readAddress);
uint8_t MCP25625_Read_RxBuffer(uint8_t readRxBuffInst);
uint8_t MCP25625_CANTransmit(uCAN_MSG *tempCanMsg);
uint8_t MCP25625_CANReceive(uCAN_MSG *tempCanMsg);
uint8_t MCP25625_messagesInBuffer(void);
uint8_t MCP25625_isBussOff(void);
uint8_t MCP25625_isRxErrorPassive(void);
uint8_t MCP25625_isTxErrorPassive(void);

#endif	/* MCP25625_H */
