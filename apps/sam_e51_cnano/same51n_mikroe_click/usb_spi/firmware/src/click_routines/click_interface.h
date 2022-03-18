/*******************************************************************************
  Click interface header file

  Company
    Microchip Technology Inc.

  File Name
    click_interface.h

  Summary:
    USB SPI click routine interface header file.

  Description
    This file defines the interface to the USB SPI click routines and MHC
    PLIB APIs.

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

#ifndef _CLICK_INTERFACE_H
#define _CLICK_INTERFACE_H

/**
  Section: Included Files
 */

/** Click routine interfaces/resources Macro Declarations
 *
 *  1. SPI
 *  The USB SPI click example on SAM E51 Curiosity Nano uses
 *  mikroBUS socket #1 on the Curiosity Nano Base for Click boards
 *  to mount USB SPI click board. The SPI lines from MCU coming to
 *  this socket are from SERCOM1 peripheral on the MCU.
 *
 */

// SERCOM SPI Definitions
#define CLICK_USB_SPI_CallbackRegister              SERCOM1_SPI_CallbackRegister
#define CLICK_USB_SPI_Read                          SERCOM1_SPI_Read
#define CLICK_USB_SPI_Write                         SERCOM1_SPI_Write
#define CLICK_USB_SPI_ErrorGet                      SERCOM1_SPI_ErrorGet
#define CLICK_USB_SPI_ReadCountGet                  SERCOM1_SPI_ReadCountGet


#endif // _CLICK_INTERFACE_H
