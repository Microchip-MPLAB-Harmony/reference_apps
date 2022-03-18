/*******************************************************************************
  USB SPI click routine header file

  Company
    Microchip Technology Inc.

  File Name
    usb_spi.h

  Summary
    USB SPI click routine header file.

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

#ifndef _USB_SPI_H
#define _USB_SPI_H

#define RX_BUFFER_SIZE                      256
#define TX_BUFFER_SIZE                      256

/**
  Section: Included Files
 */

void     USB_SPI_Initialize(void);
bool     USB_SPI_IsCommandToProcess(void);
uint8_t  USB_SPI_GetReadDataCount(void);
size_t   USB_SPI_DataWrite(uint8_t *dataBlock, int blockSize);
void     USB_SPI_DataRead(uint8_t *dataBlock, int blockSize);

#endif // _USB_SPI_H
