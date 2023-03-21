/*******************************************************************************
  USB I2C click routine source file

  Company
    Microchip Technology Inc.

  File Name
    usb_i2c.c

  Summary
    USB I2C click routine implementation file.

  Description
    This file defines the interface to the USB I2C click using I2C PLIB.
    This click routine provides to read and write on USB I2C click.

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

/**
  Section: Included Files
 */

#include <string.h>
#include "definitions.h"                // SYS function prototypes
#include "../click_interface.h"
#include "usb_i2c.h"

/* Register the USB I2C callback */
void USB_I2C_CallbackRegister(USB_I2C_SLAVE_CALLBACK callback, uintptr_t contextHandle)
{
    CLICK_USB_I2C_CallbackRegister((SERCOM_I2C_SLAVE_CALLBACK)callback, (uintptr_t)contextHandle);
}

/* Read the data sent by I2C Master */
uint8_t USB_I2C_MasterRead(void)
{
    return CLICK_USB_I2C_ReadByte();
}

/* Writes a byte to the I2C Master */
void USB_I2C_MasterWrite(uint8_t wrByte)
{
    CLICK_USB_I2C_WriteByte(wrByte);
}

/* Get the USB I2C transfer direction */
USB_I2C_SLAVE_TRANSFER_DIR USB_I2C_TransferDirGet(void)
{
    return ((USB_I2C_SLAVE_TRANSFER_DIR)CLICK_USB_I2C_TransferDirGet());
}
