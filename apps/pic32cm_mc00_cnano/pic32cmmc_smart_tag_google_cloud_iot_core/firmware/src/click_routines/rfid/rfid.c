/*******************************************************************************
  RFID click routine source file

  Company
    Microchip Technology Inc.

  File Name
    rfid.c

  Summary
    RFID click routine Implementation File.

  Description
    This file defines the interface to the RFID click using SPI PLIB.
    This click routine provides to read the RFID tag or RFID card data
    tapped on RFID click.

  Remarks:
    None.
 
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
    (c) 2021 Microchip Technology Inc. and its subsidiaries. You may use this
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
//DOM-IGNORE-END 

#include <string.h>
#include "definitions.h"                           // SYS function prototypes
#include "../click_interface.h"
#include "rfid.h"

// CR95HF Commands Definition
#define    IDN                    0x01
#define    PROTOCOL_SELECT        0x02
#define    SEND_RECV              0x04
#define    IDLE                   0x07
#define    RD_REG                 0x08
#define    WR_REG                 0x09
#define    BAUD_RATE              0x0A
#define    ECHO                   0x55

#define    RFID_BUF_SIZE          256
#define    CR95HF_ID_BUF_SIZE     256

static uint8_t sdata[RFID_BUF_SIZE];
static uint8_t rdata[RFID_BUF_SIZE];
static uint16_t response = 0, dataNum = 0;

volatile bool isTransferDone = false;
/* This function will be called by SPI PLIB when transfer is completed */
void SPIEventHandler(uintptr_t context )
{
    isTransferDone = true;
}

static bool RFID_SPI_Write(void* pTransmitData, size_t txSize)
{
    bool response = CLICK_RFID_SPI_Write(pTransmitData, txSize);
    while(isTransferDone != true);
    isTransferDone = false;
    
    return(response);
}

static bool RFID_SPI_Read(void* pReceiveData, size_t rxSize)
{
    bool response = CLICK_RFID_SPI_Read(pReceiveData, rxSize);
    while(isTransferDone != true);
    isTransferDone = false;
    
    return(response);
}

// Write command to the CR95HF
static void writeCmd(uint16_t cmd, uint16_t dataLen)
{
    uint16_t i = 0;
    uint8_t val;

    CLICK_RFID_CS_Clear();

    val = 0x00;
    RFID_SPI_Write(&val, 1);

    val = cmd;
    RFID_SPI_Write(&val, 1);  

    val = dataLen;  
    RFID_SPI_Write(&val, 1);    

    while (dataLen == 0)
    {
      CLICK_RFID_CS_Set();
      break;
    }
    for(i=0; i<dataLen; i++)
    {
        RFID_SPI_Write(&sdata[i], 1);          
    }
    CLICK_RFID_CS_Set();
}

static void readCmd(void)                       // Poll the CR95HF
{
    uint16_t i = 0;
    uint8_t val;

    while(1)
    {
        CLICK_RFID_CS_Clear();    
        val = 0x03;
        RFID_SPI_Write(&val, 1);          
        RFID_SPI_Read(&response,1);
        CLICK_RFID_CS_Set();

        if((response & 0x08) >> 3)
        {
            CLICK_RFID_CS_Clear();

            val = 0x02;
            RFID_SPI_Write(&val, 1);          
            RFID_SPI_Read(&response,1);
            RFID_SPI_Read(&dataNum,1);

            for(i=0; i<dataNum; i++)
            {
                RFID_SPI_Read(&rdata[i],1);  
            }
            CLICK_RFID_CS_Set();
            break;
        }
        CLICK_RFID_CS_Set();
        CLICK_RFID_DelayMs(10);
      }
}

// Initialize MCU and peripherals
static void Calibration(void)                   // Calibrate CR95HF device
{
    /* Debug Prints */
    /* printf("\n\rCalibrating CR95HF..."); */

    sdata[0] = 0x03;
    sdata[1] = 0xA1;
    sdata[2] = 0x00;
    sdata[3] = 0xF8;
    sdata[4] = 0x01;
    sdata[5] = 0x18;
    sdata[6] = 0x00;
    sdata[7] = 0x20;
    sdata[8] = 0x60;
    sdata[9] = 0x60;
    sdata[10] = 0x00;
    sdata[11] = 0x00;
    sdata[12] = 0x3F;
    sdata[13] = 0x01;
    writeCmd(IDLE, 0x0E);
    readCmd();

    sdata[0] = 0x03;
    sdata[1] = 0xA1;
    sdata[2] = 0x00;
    sdata[3] = 0xF8;
    sdata[4] = 0x01;
    sdata[5] = 0x18;
    sdata[6] = 0x00;
    sdata[7] = 0x20;
    sdata[8] = 0x60;
    sdata[9] = 0x60;
    sdata[10] = 0x00;
    sdata[11] = 0xFC;
    sdata[12] = 0x3F;
    sdata[13] = 0x01;
    writeCmd(IDLE, 0x0E);
    readCmd();

    sdata[0] = 0x03;
    sdata[1] = 0xA1;
    sdata[2] = 0x00;
    sdata[3] = 0xF8;
    sdata[4] = 0x01;
    sdata[5] = 0x18;
    sdata[6] = 0x00;
    sdata[7] = 0x20;
    sdata[8] = 0x60;
    sdata[9] = 0x60;
    sdata[10] = 0x00;
    sdata[11] = 0x7C;
    sdata[12] = 0x3F;
    sdata[13] = 0x01;
    writeCmd(IDLE, 0x0E);
    readCmd();

    sdata[0] = 0x03;
    sdata[1] = 0xA1;
    sdata[2] = 0x00;
    sdata[3] = 0xF8;
    sdata[4] = 0x01;
    sdata[5] = 0x18;
    sdata[6] = 0x00;
    sdata[7] = 0x20;
    sdata[8] = 0x60;
    sdata[9] = 0x60;
    sdata[10] = 0x00;
    sdata[11] = 0x3C;
    sdata[12] = 0x3F;
    sdata[13] = 0x01;
    writeCmd(IDLE, 0x0E);
    readCmd();

    sdata[0] = 0x03;
    sdata[1] = 0xA1;
    sdata[2] = 0x00;
    sdata[3] = 0xF8;
    sdata[4] = 0x01;
    sdata[5] = 0x18;
    sdata[6] = 0x00;
    sdata[7] = 0x20;
    sdata[8] = 0x60;
    sdata[9] = 0x60;
    sdata[10] = 0x00;
    sdata[11] = 0x5C;
    sdata[12] = 0x3F;
    sdata[13] = 0x01;
    writeCmd(IDLE, 0x0E);
    readCmd();

    sdata[0] = 0x03;
    sdata[1] = 0xA1;
    sdata[2] = 0x00;
    sdata[3] = 0xF8;
    sdata[4] = 0x01;
    sdata[5] = 0x18;
    sdata[6] = 0x00;
    sdata[7] = 0x20;
    sdata[8] = 0x60;
    sdata[9] = 0x60;
    sdata[10] = 0x00;
    sdata[11] = 0x6C;
    sdata[12] = 0x3F;
    sdata[13] = 0x01;
    writeCmd(IDLE, 0x0E);
    readCmd();

    sdata[0] = 0x03;
    sdata[1] = 0xA1;
    sdata[2] = 0x00;
    sdata[3] = 0xF8;
    sdata[4] = 0x01;
    sdata[5] = 0x18;
    sdata[6] = 0x00;
    sdata[7] = 0x20;
    sdata[8] = 0x60;
    sdata[9] = 0x60;
    sdata[10] = 0x00;
    sdata[11] = 0x74;
    sdata[12] = 0x3F;
    sdata[13] = 0x01;
    writeCmd(IDLE, 0x0E);
    readCmd();

    sdata[0] = 0x03;
    sdata[1] = 0xA1;
    sdata[2] = 0x00;
    sdata[3] = 0xF8;
    sdata[4] = 0x01;
    sdata[5] = 0x18;
    sdata[6] = 0x00;
    sdata[7] = 0x20;
    sdata[8] = 0x60;
    sdata[9] = 0x60;
    sdata[10] = 0x00;
    sdata[11] = 0x70;
    sdata[12] = 0x3F;
    sdata[13] = 0x01;
    writeCmd(IDLE, 0x0E);
    readCmd();
    /* Debug Prints */
    /* printf("\n\rCompleted.\n\r"); */
}

static void ReadCR95HF_ID(void)                 // Get CR95HF chip ID
{
    char CR95HF_ID[26];
    uint16_t j = 0;

    writeCmd(IDN, 0);
    readCmd();
    for(j=0; j<dataNum; j++)
    {
        CR95HF_ID[j] = rdata[j];
    }
  
    /* Debug Prints */
    /* printf("\n\rCR95HF Device ID:%s", CR95HF_ID); */
    memset(CR95HF_ID, 0x00, 26);
}

static void Select_ISO_IEC_14443_A_Protocol(void)// Select the RF communication protocol (ISO/IEC 14443-A)
{
    uint16_t j = 0;

    sdata[0] = 0x02;
    sdata[1] = 0x00;
    writeCmd(PROTOCOL_SELECT, 2);
    readCmd();

    // Clear read and write buffers
    for(j=0; j<18; j++ )
    {
        rdata[j] = 0;
        sdata[j] = 0;
    }
}

static void Select_ISO_IEC_18092_Protocol(void)  // Select the RF communication protocol (ISO/IEC 18092)
{
    uint16_t j = 0;

    sdata[0] = 0x04;
    sdata[1] = 0x51;
    writeCmd(PROTOCOL_SELECT, 2);
    readCmd();

    // Clear read and write buffers
    for(j=0; j<18; j++ )
    {
        rdata[j] = 0;
        sdata[j] = 0;
    }
}

static void IndexMod_Gain(void)                 // Configure IndexMod & Gain
{
    sdata[0] = 0x09;
    sdata[1] = 0x04;
    sdata[2] = 0x68;
    sdata[3] = 0x01;
    sdata[4] = 0x01;
    sdata[5] = 0x50;
    writeCmd(WR_REG, 6);
    readCmd();
}

static void AutoFDet(void)                      // Configure Auto FDet
{
    sdata[0] = 0x09;
    sdata[1] = 0x04;
    sdata[2] = 0x0A;
    sdata[3] = 0x01;
    sdata[4] = 0x02;
    sdata[5] = 0xA1;
    writeCmd(WR_REG, 6);
    readCmd();
}

bool GetTagID(char *ID)                      // Read the tag ID
{
    char txt_hex[3];
    uint16_t j = 0;
    char flag = 0;

    while(1)
    {
        memset((char*)sdata, 0x00, RFID_BUF_SIZE);
        memset((char*)rdata, 0x00, RFID_BUF_SIZE);
        *ID = 0x00;

        sdata[0] = 0x26;
        sdata[1] = 0x07;
        writeCmd(SEND_RECV , 2);
        readCmd();

        sdata[0] = 0x93;
        sdata[1] = 0x20;
        sdata[2] = 0x08;
        writeCmd(SEND_RECV , 3);
        readCmd();

        if(response == 0x80)
        {
            for(j=1; j<dataNum-3; j++)
            {
                sprintf(txt_hex, "%x", rdata[j]);//ByteToHex
                strcat(ID, txt_hex);
            }
        }
        Select_ISO_IEC_14443_A_Protocol();

        if (ID[0] == 0)
        {                                       // If there is no tag present
            flag++;                             // Increment counter flag
            if(flag > 10)
            {                                   // If counter flag has reached value > 5
                return(false);
            }
            CLICK_RFID_DelayMs(100);
        }
        else 
        {                                       // If tag is present
            return(true);
        }
    }
    
    return(false);
}

bool GetNFCTag(char *ID)                        // Read the NFC Forum tags
{
    char txt_hex[3];
    uint16_t j = 0;
    char flag = 0;

    while(1)
    {
        memset((char*)sdata, 0x00, RFID_BUF_SIZE);
        memset((char*)rdata, 0x00, RFID_BUF_SIZE);
        *ID = 0x00;

        sdata[0] = 0x00;
        sdata[1] = 0xFF;
        sdata[2] = 0xFF;
        sdata[3] = 0x00;
        sdata[4] = 0x00;
        writeCmd(SEND_RECV, 5);
        readCmd();

        if(response == 0x80)
        {
            for(j=0; j<dataNum; j++)
            {
                sprintf(txt_hex, "%x", rdata[j]);   //ByteToHex
                strcat(ID, txt_hex);
            }
        }
        Select_ISO_IEC_18092_Protocol();

        if (ID[0] == 0)
        {                                       // If there is no tag present
            flag++;                             // Increment counter flag
            if(flag > 10)
            {                                   // If counter flag has reached value > 5
                return(false);
            }
            CLICK_RFID_DelayMs(100);
        }
        else 
        {                                       // If tag is present
            return(true);
        }
    }
}


static char EchoResponse(void)                  // Get Echo reponse from CR95HF
{
    uint8_t tmp = 0;
    uint8_t val;

    CLICK_RFID_CS_Clear();
    
    val = 0x00;
    RFID_SPI_Write(&val, 1); 
    CLICK_RFID_DelayMs(1);

    val = ECHO;
    RFID_SPI_Write(&val, 1); 
    CLICK_RFID_DelayMs(1);
    CLICK_RFID_CS_Set();

    while(1)
    {
        tmp = 0;
        CLICK_RFID_CS_Clear();

        val = 0x03;
        RFID_SPI_Write(&val, 1); 
        CLICK_RFID_DelayMs(1);
        RFID_SPI_Read(&tmp,1);
        CLICK_RFID_DelayMs(1);
        CLICK_RFID_CS_Set();

        if((tmp & 0x08) >> 3)
        {
            CLICK_RFID_CS_Clear();

            val = 0x02;
            RFID_SPI_Write(&val, 1);         
            RFID_SPI_Read(&tmp,1);  

            CLICK_RFID_CS_Set();
            if(tmp == ECHO)
            {
                return 1;
            }
            return 0;
        }
    }
}

void rfid_init(void)
{
    CLICK_RFID_SPI_RegisterCallback(SPIEventHandler, (uintptr_t)NULL);
    CLICK_RFID_TimerStart();
    CLICK_RFID_DelayMs(5000);
  // Configure GPIO pins
    CLICK_RFID_RST_Set();
    CLICK_RFID_SSI0_Clear();
    CLICK_RFID_IRQ_IN_Set();
    CLICK_RFID_DelayMs(1);

    CLICK_RFID_IRQ_IN_Clear();  
    CLICK_RFID_DelayMs(1);
    CLICK_RFID_IRQ_IN_Set();
    CLICK_RFID_DelayMs(1);
  
    CLICK_RFID_DelayMs(200);
    while (!EchoResponse())
    {
        // Until CR95HF is detected
        CLICK_RFID_IRQ_IN_Set();
        CLICK_RFID_DelayMs(1);
        CLICK_RFID_IRQ_IN_Clear();
        CLICK_RFID_DelayMs(1);      
    }
    /* Debug Prints */
    /* printf("\n\rCR95HF Device Connected."); */

    ReadCR95HF_ID();
    Calibration();
    IndexMod_Gain();
    AutoFDet();
    Select_ISO_IEC_18092_Protocol();  
}
