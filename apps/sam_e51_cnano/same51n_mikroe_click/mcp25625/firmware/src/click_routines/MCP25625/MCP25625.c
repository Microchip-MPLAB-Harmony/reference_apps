/*******************************************************************************
  MCP25625 click routine source file

  Company
    Microchip Technology Inc.

  File Name
    MCP25625.c

  Summary
    MCP25625 click routine implementation file.

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

/**
  Section: Included Files
 */

#include <string.h>
#include "definitions.h"                // SYS function prototypes
#include "../click_interface.h"
#include "MCP25625.h"

/**
Local Function Prototypes
*/  
uint32_t convertReg2ExtendedCANid(uint8_t tempRXBn_EIDH, uint8_t tempRXBn_EIDL, uint8_t tempRXBn_SIDH, uint8_t tempRXBn_SIDL);
uint32_t convertReg2StandardCANid(uint8_t tempRXBn_SIDH, uint8_t tempRXBn_SIDL) ;
void convertCANid2Reg(uint32_t tempPassedInID, uint8_t canIdType, id_reg_t *passedIdReg);

/**
Local Variables
*/ 
ctrl_status_t ctrlStatus;
ctrl_error_status_t errorStatus;
id_reg_t idReg;

bool MCP25625_SPI_Write(uint8_t lclTransmitData)
{
    return CLICK_MCP25625_Write(&lclTransmitData, 1);
}

bool MCP25625_SPI_Read(uint8_t* lclReceiveData)
{
    return CLICK_MCP25625_Read(lclReceiveData, 1);
}

/**
Initialize CAN controller
*/
static void MCP25625_Controller_Initialize(void)
{
    CLICK_MCP25625_CS_Set();        /* set MCP25625_nCS output high */
    CLICK_MCP25625_RST_Set();       /* set MCP25625_nRST output high */
}

/**
Set CAN contoller to config mode
*/
static void MCP25625_SetTo_ConfigMode(void)
{
    MCP25625_Write_Byte(MCP25625_CANCTRL, 0x80);
    while(0x80 != (MCP25625_Read_Byte(MCP25625_CANSTAT) & 0xE0)); // Wait until MCP25625 is in config mode
}

/**
Set CAN controller to normal mode
*/
static void MCP25625_SetTo_NormalMode(void)
{
    CLICK_MCP25625_STB_Clear();     /* set MCP25625_STBY output low */
    MCP25625_Write_Byte(MCP25625_CANCTRL, 0x00);
    while(0x00 != (MCP25625_Read_Byte(MCP25625_CANSTAT) & 0xE0)); // Wait until MCP25625  is in normal mode
}

/**
Set CAN controller to sleep mode
*/
static void MCP25625_SetTo_Sleep_Mode(void)
{
    MCP25625_Write_Byte(MCP25625_CANCTRL, 0x20);
    while(0x20 != (MCP25625_Read_Byte(MCP25625_CANSTAT) & 0xE0)); // Wait until MCP25625  is in normal mode
}

/**
Checks if the controller is awake from sleep
*/
bool MCP25625_is_Awake(void)
{
    uint8_t canintReg;
    
    canintReg = MCP25625_Read_Byte(MCP25625_CANINTF);
    canintReg &= 0x40;
    if (canintReg == 0x40)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
Reset CAN controller
*/
void MCP25625_Reset(void)
{
    CLICK_MCP25625_CS_Clear();      /* set MCP25625_nCS output low */
    MCP25625_SPI_Write(MCP25625_RESET);
    CLICK_MCP25625_CS_Set();        /* set MCP25625_nCS output high */
}

/**
Read one byte from given CAN controller address
*/
uint8_t MCP25625_Read_Byte (uint8_t readAddress)
{
    uint8_t addressData;
    
    CLICK_MCP25625_CS_Clear();      /* set MCP25625_nCS output low */
    MCP25625_SPI_Write(MCP25625_READ);
    MCP25625_SPI_Write(readAddress);
    MCP25625_SPI_Read(&addressData);
    CLICK_MCP25625_CS_Set();        /* set MCP25625_nCS output high */
    
    return addressData;
}

/**
Read RX buffer using Read Rx Buffer instruction
*/
uint8_t MCP25625_Read_RxBuffer(uint8_t readRxBuffInst)
{
    uint8_t rxBufferData;
    
    CLICK_MCP25625_CS_Clear();      /* set MCP25625_nCS output low */
    MCP25625_SPI_Write(readRxBuffInst);
    MCP25625_SPI_Read(&rxBufferData);
    CLICK_MCP25625_CS_Set();        /* set MCP25625_nCS output high */
    
    return rxBufferData;
}

/**
readRxBuffInst = instruction for the first Rx buffer to read
rxLength = number of byte addresses to read from the set rx buffer to RXBnD7
*rxData = pointer to the first rx buffer to read
*/
void MCP25625_Read_RxbSequence(uint8_t readRxBuffInst, uint8_t rxLength, uint8_t *rxData)
{
    CLICK_MCP25625_CS_Clear();      /* set MCP25625_nCS output low */
    MCP25625_SPI_Write(readRxBuffInst);
    for(uint8_t i = 0; i < rxLength; i++)
    {
        MCP25625_SPI_Read(rxData);
        rxData++;
//        *(rxData++) = spiMaster[MCP25625].exchangeByte(writeDummy);
    }
    CLICK_MCP25625_CS_Set();        /* set MCP25625_nCS output high */
}

/**
Write a single byte to the given register address
writeAddress = address where the data will be written
writeData = data to write to writeAddress
*/
void MCP25625_Write_Byte (uint8_t writeAddress, uint8_t writeData)
{
    CLICK_MCP25625_CS_Clear();      /* set MCP25625_nCS output low */
    MCP25625_SPI_Write(MCP25625_WRITE);
    MCP25625_SPI_Write(writeAddress);
    MCP25625_SPI_Write(writeData);
    CLICK_MCP25625_CS_Set();        /* set MCP25625_nCS output high */
}

/**
Write a sequence of bytes from the given startAddress to the endAddress
startAddress = first address to write
endAddress = last address to write
*data = pointer to the starting address
*/
void MCP25625_Write_ByteSequence (uint8_t startAddress, uint8_t endAddress, uint8_t *data)
{
    CLICK_MCP25625_CS_Clear();      /* set MCP25625_nCS output low */
    MCP25625_SPI_Write(MCP25625_WRITE);
    MCP25625_SPI_Write(startAddress);
    do
    {
        MCP25625_SPI_Write(*(data++));
    }while(startAddress++ != endAddress);
    CLICK_MCP25625_CS_Set();        /* set MCP25625_nCS output high */
}

/**
Write messages starting from the given txBnSIDH up to TXBnD7
loadtxBnSidhInst = instruction to load to a TXBnSIDH buffer
*idReg = pointer to the address of data to load to the four tx id buffers
dlc = data length
*txData = pointer to the address of data to load to the 8 tx data buffers
*/
void MCP25625_Load_TxSequence(uint8_t loadtxBnSidhInst, uint8_t *idReg, uint8_t dlc, uint8_t *txData)
{
    CLICK_MCP25625_CS_Clear();      /* set MCP25625_nCS output low */
    MCP25625_SPI_Write(loadtxBnSidhInst);
    for(uint8_t i = 0; i < 4; i++)
    {
        MCP25625_SPI_Write(*(idReg++));      // Write id from the four id registers
    }
    MCP25625_SPI_Write(dlc);
    for(uint8_t i = 0; i < 8; i++)
    {
        MCP25625_SPI_Write(*(txData++));     // Write 8 data bytes
    }
    CLICK_MCP25625_CS_Set();        /* set MCP25625_nCS output high */
}

/**
Write one byte to a tx buffer
loadTxBuffInst = instruction to load to a TXBnSIDH or TXBnD0 buffer
loadTxData = data to load to the given buffer
*/
void MCP25625_Load_TxBuffer (uint8_t loadTxBuffInst, uint8_t txBufferData)
{
    CLICK_MCP25625_CS_Clear();      /* set MCP25625_nCS output low */
    MCP25625_SPI_Write(loadTxBuffInst);
    MCP25625_SPI_Write(txBufferData);
    CLICK_MCP25625_CS_Set();        /* set MCP25625_nCS output high */
}

/**
Message request to send using the RTS instruction for a TX buffer
*/
void MCP25625_RequestToSend (uint8_t rtsTxBuffInst)
{
    CLICK_MCP25625_CS_Clear();      /* set MCP25625_nCS output low */
    MCP25625_SPI_Write(rtsTxBuffInst);
    CLICK_MCP25625_CS_Set();        /* set MCP25625_nCS output high */
}

/**
Returns the controller status using the READ STATUS instruction
*/
static uint8_t MCP25625_Read_Status (void)
{
    uint8_t ctrlStat;
    
    CLICK_MCP25625_CS_Clear();      /* set MCP25625_nCS output low */
    MCP25625_SPI_Write(MCP25625_READ_STATUS);
    MCP25625_SPI_Read(&ctrlStat);
    CLICK_MCP25625_CS_Set();        /* set MCP25625_nCS output high */

    return ctrlStat;
}

/**
Returns the controller RX status using the RX STATUS instruction
*/
static uint8_t MCP25625_Get_RxStatus (void)
{
    uint8_t rxStatus;
    
    CLICK_MCP25625_CS_Clear();      /* set MCP25625_nCS output low */
    MCP25625_SPI_Write(MCP25625_RX_STATUS);
    MCP25625_SPI_Read(&rxStatus);
    CLICK_MCP25625_CS_Set();        /* set MCP25625_nCS output high */
    
    return rxStatus;
}

/**
Modify one bit from the given register
regAddress = address of the register that contains the bit to modify
*/
void MCP25625_Bit_Modify (uint8_t regAddress, uint8_t maskByte, uint8_t dataByte)
{
    CLICK_MCP25625_CS_Clear();      /* set MCP25625_nCS output low */
    MCP25625_SPI_Write(MCP25625_BIT_MOD);
    MCP25625_SPI_Write(regAddress);
    MCP25625_SPI_Write(maskByte);
    MCP25625_SPI_Write(dataByte);
    CLICK_MCP25625_CS_Set();        /* set MCP25625_nCS output high */
}

void MCP25625_Sleep(void)
{
    MCP25625_Bit_Modify(MCP25625_CANINTF, 0x40, 0x00);        //clear CAN bus wakeup interrupt
    MCP25625_Bit_Modify(MCP25625_CANINTE, 0x40, 0x40);        //enable CAN bus activity wakeup
    MCP25625_SetTo_Sleep_Mode();
}

void MCP25625_Initialize(void)
{
    RXF0 RXF0reg;
    RXF1 RXF1reg;
    RXF2 RXF2reg;
    RXF3 RXF3reg;
    RXF4 RXF4reg;
    RXF5 RXF5reg;
    RXM0 RXM0reg;
    RXM1 RXM1reg;

    /**
	Mask and Filter definitions
	.............................................................
	CAN ID		Mask					Filter		Buffer
	.............................................................
	0x444		Acceptance Mask 0		Filter 0	RXB0
	0x555		Acceptance Mask 0		Filter 1	RXB0
	0x666		Acceptance Mask 1		Filter 2	RXB1
	.............................................................
	*/

    // Initialize Rx Mask values
    RXM0reg.RXM0SIDH = 0xFF;
    RXM0reg.RXM0SIDL = 0xF0;
    RXM0reg.RXM0EID8 = 0x00;
    RXM0reg.RXM0EID0 = 0x00;
    
    RXM1reg.RXM1SIDH = 0xFF;
    RXM1reg.RXM1SIDL = 0xF0;
    RXM1reg.RXM1EID8 = 0x00;
    RXM1reg.RXM1EID0 = 0x00;
    
    // Initialize Rx Filter values
    RXF0reg.RXF0SIDH = 0x88;
    RXF0reg.RXF0SIDL = 0x80;
    RXF0reg.RXF0EID8 = 0x00;
    RXF0reg.RXF0EID0 = 0x00;
    
    RXF1reg.RXF1SIDH = 0xAA;
    RXF1reg.RXF1SIDL = 0xA0;
    RXF1reg.RXF1EID8 = 0x00;
    RXF1reg.RXF1EID0 = 0x00;
    
    RXF2reg.RXF2SIDH = 0xCC;
    RXF2reg.RXF2SIDL = 0xC0;
    RXF2reg.RXF2EID8 = 0x00;
    RXF2reg.RXF2EID0 = 0x00;
       
    RXF3reg.RXF3SIDH = 0x00;
    RXF3reg.RXF3SIDL = 0x00;
    RXF3reg.RXF3EID8 = 0x00;
    RXF3reg.RXF3EID0 = 0x00;
    
    RXF4reg.RXF4SIDH = 0x00;
    RXF4reg.RXF4SIDL = 0x00;
    RXF4reg.RXF4EID8 = 0x00;
    RXF4reg.RXF4EID0 = 0x00;
        
    RXF5reg.RXF5SIDH = 0x00;
    RXF5reg.RXF5SIDL = 0x00;
    RXF5reg.RXF5EID8 = 0x00;
    RXF5reg.RXF5EID0 = 0x00;
   
    MCP25625_Controller_Initialize();
    MCP25625_SetTo_ConfigMode();
    
    // Write Filter and Mask values to CAN controller
    MCP25625_Write_ByteSequence(MCP25625_RXM0SIDH, MCP25625_RXM0EID0, &(RXM0reg.RXM0SIDH));
    MCP25625_Write_ByteSequence(MCP25625_RXM1SIDH, MCP25625_RXM1EID0, &(RXM1reg.RXM1SIDH));
    MCP25625_Write_ByteSequence(MCP25625_RXF0SIDH, MCP25625_RXF0EID0, &(RXF0reg.RXF0SIDH));
    MCP25625_Write_ByteSequence(MCP25625_RXF1SIDH, MCP25625_RXF1EID0, &(RXF1reg.RXF1SIDH));
    MCP25625_Write_ByteSequence(MCP25625_RXF2SIDH, MCP25625_RXF2EID0, &(RXF2reg.RXF2SIDH));
    MCP25625_Write_ByteSequence(MCP25625_RXF3SIDH, MCP25625_RXF3EID0, &(RXF3reg.RXF3SIDH));
    MCP25625_Write_ByteSequence(MCP25625_RXF4SIDH, MCP25625_RXF4EID0, &(RXF4reg.RXF4SIDH));
    MCP25625_Write_ByteSequence(MCP25625_RXF5SIDH, MCP25625_RXF5EID0, &(RXF5reg.RXF5SIDH));
    
    // Initialize CAN Timings 

    /**
	Baud rate: 125kbps
	Clock frequency: 20MHz
	Time quanta: 8
	Sample point: 1-4-1-2
	Sample point: 75.00%
	*/

    MCP25625_Write_Byte(MCP25625_CNF1, 0x09);
    MCP25625_Write_Byte(MCP25625_CNF2, 0x83);
    MCP25625_Write_Byte(MCP25625_CNF3, 0x01);
    
    MCP25625_SetTo_NormalMode();
}

uint8_t MCP25625_CANTransmit(uCAN_MSG *tempCanMsg)
{
    uint8_t returnValue = 0;
       
    idReg.tempSIDH = 0;
    idReg.tempSIDL = 0;
    idReg.tempEID8 = 0;
    idReg.tempEID0 = 0;
    
    ctrlStatus.ctrl_status = MCP25625_Read_Status();

    if (ctrlStatus.TXB0REQ != 1)
    {
        convertCANid2Reg(tempCanMsg->frame.id, tempCanMsg->frame.idType, &idReg);
        
        MCP25625_Load_TxSequence(MCP25625_LOAD_TXB0SIDH, &(idReg.tempSIDH), tempCanMsg->frame.dlc, &(tempCanMsg->frame.data0));
        MCP25625_RequestToSend(MCP25625_RTS_TX0);
 
        returnValue = 1;
    }
    else if (ctrlStatus.TXB1REQ != 1)
    {
        convertCANid2Reg(tempCanMsg->frame.id, tempCanMsg->frame.idType, &idReg);

        MCP25625_Load_TxSequence(MCP25625_LOAD_TXB1SIDH, &(idReg.tempSIDH), tempCanMsg->frame.dlc, &(tempCanMsg->frame.data0));
        MCP25625_RequestToSend(MCP25625_RTS_TX1);
        
        returnValue = 1;
    }
    else if (ctrlStatus.TXB2REQ != 1)
    {
        convertCANid2Reg(tempCanMsg->frame.id, tempCanMsg->frame.idType, &idReg);

        MCP25625_Load_TxSequence(MCP25625_LOAD_TXB2SIDH, &(idReg.tempSIDH), tempCanMsg->frame.dlc, &(tempCanMsg->frame.data0));
        MCP25625_RequestToSend(MCP25625_RTS_TX2);
        
        returnValue = 1;
    }
    
    return (returnValue);
}

uint8_t MCP25625_CANReceive(uCAN_MSG *tempCanMsg)
{
    uint8_t returnValue = 0;
    rx_reg_t rxReg;
    ctrl_rx_status_t rxStatus;

    rxStatus.ctrl_rx_status = MCP25625_Get_RxStatus();
    
    //check to see if we received a CAN message
    if (rxStatus.rxBuffer != 0)
    {
            //check which buffer the CAN message is in
            if ((rxStatus.rxBuffer == MSG_IN_RXB0)||(rxStatus.rxBuffer == MSG_IN_BOTH_BUFFERS))
            {
                MCP25625_Read_RxbSequence(MCP25625_READ_RXB0SIDH, sizeof(rxReg.rx_reg_array), rxReg.rx_reg_array);
            }
            else if (rxStatus.rxBuffer == MSG_IN_RXB1)
            {
                MCP25625_Read_RxbSequence(MCP25625_READ_RXB1SIDH, sizeof(rxReg.rx_reg_array), rxReg.rx_reg_array);
            }
            
            if (rxStatus.msgType == dEXTENDED_CAN_MSG_ID_2_0B)
            {
                tempCanMsg->frame.idType = (uint8_t) dEXTENDED_CAN_MSG_ID_2_0B;
                tempCanMsg->frame.id = convertReg2ExtendedCANid(rxReg.RXBnEID8, rxReg.RXBnEID0, rxReg.RXBnSIDH, rxReg.RXBnSIDL);
            }
            else
            {
                tempCanMsg->frame.idType = (uint8_t) dSTANDARD_CAN_MSG_ID_2_0B;
                tempCanMsg->frame.id = convertReg2StandardCANid(rxReg.RXBnSIDH, rxReg.RXBnSIDL);
            }

            tempCanMsg->frame.dlc   = rxReg.RXBnDLC;
            tempCanMsg->frame.data0 = rxReg.RXBnD0;
            tempCanMsg->frame.data1 = rxReg.RXBnD1;
            tempCanMsg->frame.data2 = rxReg.RXBnD2;
            tempCanMsg->frame.data3 = rxReg.RXBnD3;
            tempCanMsg->frame.data4 = rxReg.RXBnD4;
            tempCanMsg->frame.data5 = rxReg.RXBnD5;
            tempCanMsg->frame.data6 = rxReg.RXBnD6;
            tempCanMsg->frame.data7 = rxReg.RXBnD7;
            
            returnValue = 1;
    }
    return (returnValue);
}

uint8_t MCP25625_messagesInBuffer(void)
{
    uint8_t messageCount = 0;
   
    ctrlStatus.ctrl_status = MCP25625_Read_Status();
    if(ctrlStatus.RX0IF != 0)
    {
        messageCount++;
    }
    if(ctrlStatus.RX1IF != 0)
    {
        messageCount++;
    }
    
    return (messageCount);
}

uint8_t MCP25625_isBussOff(void)
{
    uint8_t returnValue = 0;
    
    errorStatus.error_flag_reg = MCP25625_Read_Byte(MCP25625_EFLG);
    
    if(errorStatus.TXBO == 1)
    {
        returnValue = 1;
    }
    
    return (returnValue);
}

uint8_t MCP25625_isRxErrorPassive(void)
{
    uint8_t returnValue = 0;
    
    errorStatus.error_flag_reg = MCP25625_Read_Byte(MCP25625_EFLG);
    
    if(errorStatus.RXEP == 1)
    {
        returnValue = 1;
    }
    
    return (returnValue);
}

uint8_t MCP25625_isTxErrorPassive(void)
{
    uint8_t returnValue = 0;
    
    errorStatus.error_flag_reg = MCP25625_Read_Byte(MCP25625_EFLG);
    
    if(errorStatus.TXEP == 1)
    {
        returnValue = 1;
    }
    
    return (returnValue);
}

uint32_t convertReg2ExtendedCANid(uint8_t tempRXBn_EIDH, uint8_t tempRXBn_EIDL, uint8_t tempRXBn_SIDH, uint8_t tempRXBn_SIDL) {
    uint32_t returnValue = 0;
    uint32_t ConvertedID = 0;
    uint8_t CAN_standardLo_ID_lo2bits;
    uint8_t CAN_standardLo_ID_hi3bits;

    CAN_standardLo_ID_lo2bits = (tempRXBn_SIDL & 0x03);
    CAN_standardLo_ID_hi3bits = (tempRXBn_SIDL >> 5);
    ConvertedID = (tempRXBn_SIDH << 3);
    ConvertedID = ConvertedID + CAN_standardLo_ID_hi3bits;
    ConvertedID = (ConvertedID << 2);
    ConvertedID = ConvertedID + CAN_standardLo_ID_lo2bits;
    ConvertedID = (ConvertedID << 8);
    ConvertedID = ConvertedID + tempRXBn_EIDH;
    ConvertedID = (ConvertedID << 8);
    ConvertedID = ConvertedID + tempRXBn_EIDL;
    returnValue = ConvertedID;    
    return (returnValue);
}

uint32_t convertReg2StandardCANid(uint8_t tempRXBn_SIDH, uint8_t tempRXBn_SIDL)
{
    uint32_t returnValue = 0;
    uint32_t ConvertedID;

    ConvertedID = (tempRXBn_SIDH << 3);
    ConvertedID = ConvertedID + (tempRXBn_SIDL >> 5);
    returnValue = ConvertedID;
    
    return (returnValue);
}


void convertCANid2Reg(uint32_t tempPassedInID, uint8_t canIdType, id_reg_t *passedIdReg)
{
    uint8_t wipSIDL = 0;

    if (canIdType == dEXTENDED_CAN_MSG_ID_2_0B)
    {
        //EID0
        passedIdReg->tempEID0 = 0xFF & tempPassedInID;
        tempPassedInID = tempPassedInID >> 8;

        //EID8
        passedIdReg->tempEID8 = 0xFF & tempPassedInID;
        tempPassedInID = tempPassedInID >> 8;

        //SIDL
        wipSIDL = 0x03 & tempPassedInID;
        tempPassedInID = tempPassedInID << 3;
        wipSIDL = (0xE0 & tempPassedInID) + wipSIDL;
        wipSIDL = wipSIDL + 0x08;
        passedIdReg->tempSIDL = 0xEB & wipSIDL;

        //SIDH
        tempPassedInID = tempPassedInID >> 8;
        passedIdReg->tempSIDH = 0xFF & tempPassedInID;
    }
    else
    {
        passedIdReg->tempEID8 = 0;
        passedIdReg->tempEID0 = 0;
        tempPassedInID = tempPassedInID << 5;
        passedIdReg->tempSIDL = 0xFF & tempPassedInID;
        tempPassedInID = tempPassedInID >> 8;
        passedIdReg->tempSIDH = 0xFF & tempPassedInID;
    }
}
