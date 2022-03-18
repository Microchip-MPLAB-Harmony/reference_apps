/*******************************************************************************
  USB SPI click routine source file

  Company
    Microchip Technology Inc.

  File Name
    usb_spi.c

  Summary
    USB SPI click routine implementation file.

  Description
    This file defines the interface to the USB SPI click using SPI PLIB.
    This click routine provides MCU as SPI slave device to read and write 
    using USB SPI click.

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
#include "usb_spi.h"

static uint8_t USB_SPI_RxData[RX_BUFFER_SIZE];
static uint8_t USB_SPI_nBytesRead;

void USB_SPI_EventHandler(uintptr_t context )
{
    if (CLICK_USB_SPI_ErrorGet() == SPI_SLAVE_ERROR_NONE)
    {
        USB_SPI_nBytesRead = CLICK_USB_SPI_Read(USB_SPI_RxData, CLICK_USB_SPI_ReadCountGet());
    }
}
void USB_SPI_Initialize(void)
{
    CLICK_USB_SPI_CallbackRegister(USB_SPI_EventHandler, (uintptr_t) 0);
}
bool USB_SPI_IsCommandToProcess(void)
{
    if(USB_SPI_nBytesRead != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
uint8_t USB_SPI_GetReadDataCount(void)
{
    return (USB_SPI_nBytesRead);
}
static void USB_SPI_GetServerRxData(uint8_t *dataBlock, int blockSize)
{
    memcpy(dataBlock, USB_SPI_RxData, blockSize);
    USB_SPI_nBytesRead  = 0;
}
size_t USB_SPI_DataWrite(uint8_t *dataBlock, int blockSize)
{
    return CLICK_USB_SPI_Write(dataBlock, blockSize);
}
void USB_SPI_DataRead(uint8_t *dataBlock, int blockSize)
{
    return USB_SPI_GetServerRxData(dataBlock, blockSize);
}
