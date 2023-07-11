 /*******************************************************************************
  USB HOST HID Keyboard local definitions

  Company:
    Microchip Technology Inc.

  File Name:
    usb_host_hid_keyboard_local.h

  Summary:
    USB HOST HID Keyboard local definitions

  Description:
    This file describes the local HID Keyboard usage definitions.
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
// DOM-IGNORE-END

#ifndef _USB_HOST_HID_KEYBOARD_LOCAL_H
#define _USB_HOST_HID_KEYBOARD_LOCAL_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "usb/usb_host_hid_keyboard.h"

#define _USB_HOST_HID_KEYBOARD_BUFFER_QUEUE_SIZE 15

// *****************************************************************************
/* USB HOST HID Keyboard Driver State

  Summary:
    USB HOST HID Keyboard Driver State.

  Description:
    This enumeration defines the possible task state of USB HOST HID Keyboard
    driver.

  Remarks:
    None.
*/

typedef enum
{
    USB_HOST_HID_KEYBOARD_DETACHED = 0,
    USB_HOST_HID_KEYBOARD_ATTACHED,
    USB_HOST_HID_KEYBOARD_REPORT_PROCESS
    
}USB_HOST_HID_KEYBOARD_STATE;

// *****************************************************************************
/* USB HOST HID Keyboard Driver buffer data structure

  Summary:
    USB HOST HID Keyboard Driver buffer information

  Description:
    This structure holds the keyboard buffer data structure. Structure gets
    updated on every INTERRUPT IN data from HID keyboard. 

  Remarks:
    None.
 */

typedef struct
{
    bool tobeDone;
    int8_t data[64];
    
} USB_HOST_HID_KEYBOARD_DATA_BUFFER;

// *****************************************************************************
/* USB HOST HID Keyboard Driver data structure

  Summary:
    USB HOST HID Keyboard Driver information

  Description:
    This structure holds all information on per HID Keyboard driver instance level.
    Contains information like driver state, buffer information, ping pong states.
    Structure is used as part of parsing once report is received from keyboard.

  Remarks:
    None.
 */

typedef struct
{
    bool inUse;
    uint8_t index;
    uint8_t counter;
    uint8_t outputReportID;
    USB_HOST_HID_KEYBOARD_DATA_BUFFER buffer[_USB_HOST_HID_KEYBOARD_BUFFER_QUEUE_SIZE];
    USB_HID_KEYBOARD_KEYPAD lastKeyCode[6];
    USB_HOST_HID_KEYBOARD_STATE state;
    USB_HOST_HID_OBJ_HANDLE handle;
    USB_HOST_HID_KEYBOARD_DATA appData;
    uint8_t outputReport;
    
} USB_HOST_HID_KEYBOARD_DATA_OBJ;


#endif

