/*******************************************************************************
  USB I2C click routine header file

  Company
    Microchip Technology Inc.

  File Name
    usb_i2c.h

  Summary
    USB I2C click routine header file.

  Description
    This file defines the interface to the USB I2C click using I2C PLIB.
    This click routine provides to read and write interfaces on USB I2C click.

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
// DOM-IGNORE-END

#ifndef _USB_I2C_H
#define _USB_I2C_H

/**
  Section: Included Files
 */

#include <xc.h>
#include <stdint.h>

#define USB_I2C_EMULATED_EEPROM_START_ADDR             0x00
#define USB_I2C_EMULATED_EEPROM_PAGE_SIZE_BYTES        256
#define USB_I2C_EMULATED_EEPROM_PAGE_SIZE_MASK         0xFF
#define USB_I2C_EMULATED_EEPROM_SIZE_BYTES             512

typedef enum
{
    USB_I2C_CMD_WRITE,
    USB_I2C_CMD_IDLE,
}USB_I2C_CMD;

typedef struct
{
    /* writeAddrPtr - write address */
    uint16_t                    writeAddrPtr;
    /* readAddrPtr - read address */
    uint16_t                    readAddrPtr;
    /* addrIndex - used to copy 2 bytes of emulated EEPROM memory address */
    uint8_t                     addrIndex;
    /* wrBuffer - holds the incoming data from the I2C master */
    uint8_t                     wrBuffer[USB_I2C_EMULATED_EEPROM_PAGE_SIZE_BYTES];
    /* wrBufferIndex - Index into the wrBuffer[] */
    uint16_t                    wrBufferIndex;
    /* wrAddr - indicates the starting address of the emulated EEPROM memory to write to */
    volatile uint16_t           wrAddr;
    /* nWrBytes - indicates the number of bytes to write to emulated EEPROM buffer */
    volatile uint16_t           nWrBytes;
    /* internalWriteInProgress - indicates that emulated EEPROM is busy with internal writes */
    bool                        internalWriteInProgress;
}USB_I2C_EMULATED_EEPROM_DATA;

USB_I2C_CMD USB_I2C_GetCommand(void);
void USB_I2C_Initialize(void);
void USB_I2C_EmulatedEepromWrite(void);

#endif // _USB_I2C_H
