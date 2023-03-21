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

typedef enum
{
    USB_I2C_CMD_WRITE,
    USB_I2C_CMD_IDLE,
} USB_I2C_CMD;

typedef enum
{
    /* I2C Master is writing to slave */
    USB_I2C_SLAVE_TRANSFER_DIR_WRITE = 0,

    /* I2C Master is reading from slave */
    USB_I2C_SLAVE_TRANSFER_DIR_READ  = 1,
} USB_I2C_SLAVE_TRANSFER_DIR;

typedef enum
{
    USB_I2C_SLAVE_TRANSFER_EVENT_NONE = 0,
    USB_I2C_SLAVE_TRANSFER_EVENT_ADDR_MATCH,

    /* Data sent by I2C Master is available */
    USB_I2C_SLAVE_TRANSFER_EVENT_RX_READY,

    /* I2C slave can respond to data read request from I2C Master */
    USB_I2C_SLAVE_TRANSFER_EVENT_TX_READY,

    USB_I2C_SLAVE_TRANSFER_EVENT_STOP_BIT_RECEIVED,
    USB_I2C_SLAVE_TRANSFER_EVENT_ERROR,
} USB_I2C_SLAVE_TRANSFER_EVENT;

// *****************************************************************************
/* USB I2C Callback

   Summary:
    USB I2C Callback Function Pointer.

   Description:
    This data type defines the USB I2C Callback Function Pointer.

   Remarks:
    None.
*/
typedef bool (*USB_I2C_SLAVE_CALLBACK) ( USB_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t contextHandle );

void USB_I2C_CallbackRegister(USB_I2C_SLAVE_CALLBACK callback, uintptr_t contextHandle);
void USB_I2C_MasterWrite(uint8_t wrByte);
uint8_t USB_I2C_MasterRead(void);
USB_I2C_SLAVE_TRANSFER_DIR USB_I2C_TransferDirGet(void);

#endif // _USB_I2C_H
