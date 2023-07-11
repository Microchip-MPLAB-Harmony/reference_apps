/********************************************************************************
  USB EHCI Types and Definitions

  Company:
    Microchip Technology Inc.

  File Name:
    usb_ehci.h

  Summary:
    USB EHCI Interface Header

  Description:
    This header file contains the data types and defintions of data structures
    contained in the EHCI specification.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
#ifndef _USB_EHCI_H_
#define _USB_EHCI_H_

#include <stdint.h>

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* EHCI Queue Transfer Descriptor Type

  Summary:
    Defines a EHCI Queue Transfer Descriptor Type.

  Description:
    This data type defines a EHCI Transfer Queue Descriptor. This is as 
    described in section 3.5 of the EHCI specification.

  Remarks:
    None.
*/

typedef struct __attribute__((packed)) USB_EHCI_QTD 
{
    union 
    {
        /* Organize this as 8 32 bit words */
        volatile uint32_t value32[8];

        struct 
        {
            union
            {
                volatile struct USB_EHCI_QTD * pointer;
                struct
                {
                    volatile unsigned int terminate:1;
                    volatile unsigned int :31;
                };

            } nextQtd;
            
            union
            {
                volatile struct USB_EHCI_QTD * pointer;
                struct
                {
                    volatile unsigned int terminate:1;
                    volatile unsigned int :31;
                };
                
            } altNextQtd;
            
            union
            {
                struct 
                {
                    volatile unsigned int flags:8;
                    volatile unsigned int pid:2;
                    volatile unsigned int cErr:2;
                    volatile unsigned int cPage:3;
                    volatile unsigned int ioc:1;
                    volatile unsigned int bytesToTransfer:15;
                    volatile unsigned int dt:1;

                };
                
                struct
                { 
                    volatile unsigned int pingStateErr:1;
                    volatile unsigned int splitXState:1;
                    volatile unsigned int missedMicroFrame:1;
                    volatile unsigned int xactErr:1;
                    volatile unsigned int babble:1;
                    volatile unsigned int dataBufferErr:1;
                    volatile unsigned int halted:1;
                    volatile unsigned int active:1; 
                    volatile unsigned int :24;
                };

            } qTDToken;

            volatile uint32_t bufferPointer[5];
        };
    };

} USB_EHCI_QTD;

// *****************************************************************************
/* EHCI Queue Head Type

  Summary:
    Defines a EHCI Queue Head Type.

  Description:
    This data type defines a EHCI Queue Head Type. This is as 
    described in section 3.6 of the EHCI specification.

  Remarks:
    None.
*/

typedef struct __attribute__((packed)) USB_EHCI_QH
{
    union
    {
        volatile uint32_t value32[12];
   
        struct
        {
            union
            {
                volatile uint32_t value32;
                volatile struct USB_EHCI_QH * pointer;
                struct
                {
                    volatile unsigned int terminate:1;
                    volatile unsigned int type:2;
                    volatile unsigned int :29;
                };
            } horizontalQH;

            struct
            {
                volatile unsigned int deviceAddress:7;
                volatile unsigned int i:1;
                volatile unsigned int endpt:4;
                volatile unsigned int eps:2;
                volatile unsigned int dtc:1;
                volatile unsigned int h:1;
                volatile unsigned int maxPacketSize:11;
                volatile unsigned int c:1;
                volatile unsigned int rl:4;
                volatile unsigned int sMask:8;
                volatile unsigned int cMask:8;
                volatile unsigned int hubAddress:7;
                volatile unsigned int port:7;
                volatile unsigned int mult:2;
            };

            volatile USB_EHCI_QTD * currentQTD;
            union
            {
                volatile uint32_t value32;
                volatile struct USB_EHCI_QTD * pointer;
                struct
                {
                    volatile unsigned int terminate:1;
                    volatile unsigned int :31;
                };
            } nextQTD;

            union
            {
                volatile uint32_t value32;
                volatile struct USB_EHCI_QTD * pointer;
                struct
                {
                    volatile unsigned int terminate:1;
                    volatile unsigned int nakCnt:4;
                    volatile unsigned int :27;
                };
            } alternateNextQtd;

            union
            {
                volatile uint32_t value32;

                struct 
                {
                    volatile unsigned int flags:8;
                    volatile unsigned int pid:2;
                    volatile unsigned int cErr:2;
                    volatile unsigned int cPage:3;
                    volatile unsigned int ioc:1;
                    volatile unsigned int bytesToTransfer:15;
                    volatile unsigned int dt:1;

                };

                struct
                { 
                    volatile unsigned int pingStateErr:1;
                    volatile unsigned int splitXState:1;
                    volatile unsigned int missedMicroFrame:1;
                    volatile unsigned int xactErr:1;
                    volatile unsigned int babble:1;
                    volatile unsigned int dataBufferErr:1;
                    volatile unsigned int halted:1;
                    volatile unsigned int active:1; 
                    volatile unsigned int :24;
                };

            } qTDToken;

            volatile uint32_t bufferPointer[5];
        };
    };
    
} USB_EHCI_QH;

// *****************************************************************************
/* EHCI Queue Head Queue

  Summary:
    Defines a EHCI Queue Head Queue constants.

  Description:
    These constants define the EHCI Queue Head Queue Types. This is as 
    described in table 3-18 of the EHCI specification.

  Remarks:
    None.
*/

#define USB_EHCI_QH_TYPE_ITD 0x0
#define USB_EHCI_QH_TYPE_QH  0x1
#define USB_EHCI_QH_TYPE_SITD 0x2
#define USB_EHCI_QH_TYPE_FSTN 0x3

// *****************************************************************************
/* EHCI Token Type

  Summary:
    Defines a EHCI Token Type constants.

  Description:
    These constants define the EHCI Token Types. This is as 
    described in table 3-16 of the EHCI specification.

  Remarks:
    None.
*/

#define USB_EHCI_TOKEN_TYPE_OUT 0
#define USB_EHCI_TOKEN_TYPE_IN  1
#define USB_EHCI_TOKEN_TYPE_SETUP 2

// *****************************************************************************
/* EHCI Queue Head Endpoint Speed Type

  Summary:
    Defines a EHCI Queue Head Endpoint Speed Type.

  Description:
    These constants define a EHCI Queue Head Speed options. This is as 
    described in table 3-19 of the EHCI specification.

  Remarks:
    None.
*/

#define USB_EHCI_QH_SPEED_FULL 0x0
#define USB_EHCI_QH_SPEED_LOW 0x1
#define USB_EHCI_QH_SPEED_HIGH 0x2
#define USB_EHCI_QH_SPEED_UNDEFINED 0x3

// *****************************************************************************
/* EHCI End of List Marker

  Summary:
    Defines a EHCI End of List Marker.

  Description:
    This constant defines the EHCI end of list marker.

  Remarks:
    None.
*/

#define USB_EHCI_END_OF_LIST 0x1

#define USB_EHCI_PERIODIC_LIST_ENTRY(pipe,type) ((uint32_t)(pipe)|(type << 1))
#define USB_EHCI_PERIODIC_LIST_QH(x) ((USB_EHCI_QH *)(x & 0xFFFFFFE0))
#endif
