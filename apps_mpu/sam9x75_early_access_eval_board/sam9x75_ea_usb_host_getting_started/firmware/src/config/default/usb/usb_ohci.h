/********************************************************************************
  USB OHCI Types and Definitions

  Company:
    Microchip Technology Inc.

  File Name:
    usb_ehci.h

  Summary:
    USB OHCI Interface Header

  Description:
    This header file contains the data types and defintions of data structures
    contained in the OHCI specification.
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
#ifndef _USB_OHCI_H_
#define _USB_OHCI_H_

#include <stdint.h>

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* OHCI Endpoint Descriptor Type

  Summary:
    Defines a OHCI Endpoint Descriptor Type.

  Description:
    This data type defines a OHCI Endpoint Descriptor. This is as 
    described in section 4.2.1 of the OHCI specification.

  Remarks:
    None.
*/

typedef struct __attribute__((packed)) USB_OHCI_ED 
{
    union
    {
        volatile uint32_t dWord[4];

        struct
        {
            volatile unsigned int fa:7;
            volatile unsigned int en:4;
            volatile unsigned int d:2;
            volatile unsigned int s:1;
            volatile unsigned int k:1;
            volatile unsigned int f:1;
            volatile unsigned int mps:11;
            volatile unsigned int :5; 
            volatile unsigned int tailP:32;
            volatile unsigned int h:1;
            volatile unsigned int c:1;
            volatile unsigned int :2; 
            volatile unsigned int headP:28;
            volatile unsigned int nextED:32; 
        };
    };

} USB_OHCI_ED;
 
// *****************************************************************************
/* OHCI Transfer Descriptor Type

  Summary:
    Defines a OHCI Transfer Descriptor Type.

  Description:
    This data type defines a OHCI Transfer Descriptor. This is as 
    described in section 4.3 of the OHCI specification.

  Remarks:
    None.
*/

typedef struct __attribute__((packed)) USB_OHCI_TD 
{
    union
    {
        volatile uint32_t dWord[4];

        struct
        {
            volatile unsigned int :18;
            volatile unsigned int r:1;
            volatile unsigned int dp:2;
            volatile unsigned int di:3;
            volatile unsigned int t:2;
            volatile unsigned int ec:2;
            volatile unsigned int cc:4;
            volatile unsigned int cbp:32;
            volatile unsigned int nextTD:32;
            volatile unsigned int be:32;
        };
    };

} USB_OHCI_TD;

// *****************************************************************************
/* HCCA Type

  Summary:
    Defines a OHCI HCCA Type.

  Description:
    This data type defines a OHCI HCCA Type. This is as described in section
    4.4.1 of the OHCI specification.

  Remarks:
    None.
*/

typedef struct __attribute__((packed)) USB_OHCI_HCCA
{
    volatile uint32_t hccaInterruptTable[32];
    volatile uint16_t hccaFrameNumber;
    volatile uint16_t hccaPad1;
    volatile uint32_t hccaDoneHead;
    volatile uint8_t  reserved[116];

} USB_OHCI_HCCA;

// *****************************************************************************
/* OHCI Completeion Codes

  Summary:
    Defines a OHCI Completion Codes.

  Description:
    These constants define a OHCI Complete code. This is as 
    described in section 4.3.3 of the OHCI specification.

  Remarks:
    None.
*/

#define USB_OHCI_CC_NO_ERROR                0
#define USB_OHCI_CC_CRC                     1
#define USB_OHCI_CC_BIT_STUFFING            2
#define USB_OHCI_CC_DATA_TOGGLE_MISMATCH    3
#define USB_OHCI_CC_STALL                   4
#define USB_OHCI_CC_DEVICE_NOT_RESPONDING   5
#define USB_OHCI_CC_PID_CHECK_FAILURE       6
#define USB_OHCI_CC_UNEXPECTED_PID          7
#define USB_OHCI_CC_DATA_OVERRUN            8
#define USB_OHCI_CC_DATA_UNDERRUN           9
#define USB_OHCI_CC_BUFFER_OVERRUN          0xC
#define USB_OHCI_CC_BUFFER_UNDERRUN         0xD
#define USB_OHCI_CC_NOT_ACCESSED            0xF

// *****************************************************************************
/* OHCI Operational State

  Summary:
    Define the OHCI Operations States.

  Description:
    These constants define the OHCI Operational state. This is as 
    described in section 7.1.2 of the OHCI specification.

  Remarks:
    None.
*/

#define USB_OHCI_FUNCTIONAL_STATE_RESET 0
#define USB_OHCI_FUNCTIONAL_STATE_RESUME 1
#define USB_OHCI_FUNCTIONAL_STATE_OPERATIONAL 2
#define USB_OHCI_FUNCTIONAL_STATE_SUSPEND 3

// *****************************************************************************
/* OHCI Endpoint Descriptor Direction Constants

  Summary:
    Define the OHCI Endpoint Descriptor Constants.

  Description:
    These constants define the OHCI Endpoint Descriptor Direction Constants.

  Remarks
    None.
*/

#define USB_OHCI_ED_DIRECTION_OUT       1
#define USB_OHCI_ED_DIRECTION_IN        2
#define USB_OHCI_ED_DIRECTION_FROM_TD   3  

// *****************************************************************************
/* OHCI Endpoint Descriptor Speed Constants

  Summary:
    Define the OHCI Endpoint Descriptor Speed Constants.

  Description:
    These constants define the OHCI Endpoint Descriptor Speed Constants.

  Remarks
    None.
*/

#define USB_OHCI_ED_SPEED_FULL  0
#define USB_OHCI_ED_SPEED_LOW   1

// *****************************************************************************
/* OHCI Endpoint Descriptor Format Constants

  Summary:
    Define the OHCI Endpoint Descriptor Format Constants.

  Description:
    These constants define the OHCI Endpoint Descriptor Format Constants.

  Remarks
    None.
*/

#define USB_OHCI_ED_FORMAT_GENERAL  0
#define USB_OHCI_ED_FORMAT_ISOC  1

// *****************************************************************************
/* OHCI Transfer Descriptor Token Type Constants

  Summary:
    Define the OHCI Tranfer Descriptor Token Type Constants.

  Description:
    These constants define the OHCI Tranfer Descriptor Token Type. 

  Remarks
    None.
*/

#define USB_OHCI_TD_PID_TYPE_SETUP  0
#define USB_OHCI_TD_PID_TYPE_OUT  1
#define USB_OHCI_TD_PID_TYPE_IN  2

// *****************************************************************************
/* OHCI Transfer Descriptor Delay Interrupt Constants

  Summary:
    Define the OHCI Tranfer Descriptor Delay Interrupt Constants.

  Description:
    These constants define the OHCI Tranfer Descriptor Delay Interrupt Type. 

  Remarks
    None.
*/

#define USB_OHCI_TD_DELAY_INTERRUPT_0  0
#define USB_OHCI_TD_DELAY_INTERRUPT_NEVER 7

// *****************************************************************************
/* OHCI Transfer Descriptor Data Toggle Constants

  Summary:
    Define the OHCI Tranfer Descriptor Data Toggle Constants.

  Description:
    These constants define the OHCI Tranfer Descriptor Data Toggle Constants. 

  Remarks
    None.
*/

#define USB_OHCI_TD_USE_ED_TOGGLE_VALUE  0
#define USB_OHCI_TD_USE_TD_TOGGLE_VALUE  2
#define USB_OHCI_TD_TOGGLE_VALUE(x) (x)






#endif


