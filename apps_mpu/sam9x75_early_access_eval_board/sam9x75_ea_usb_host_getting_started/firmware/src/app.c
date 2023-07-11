/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app.h"

uint32_t app_state=APP_STATE_INIT; 
USB_HOST_HID_KEYBOARD_DATA data;
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

/* Usage ID to Key map table */
const char *keyValue[] = { 
                          "No event indicated",
                          "ErrorRoll Over",
                          "POSTFail",
                          "Error Undefined",
                          "a",
                          "b",
                          "c",
                          "d",
                          "e",
                          "f",
                          "g",
                          "h",
                          "i",
                          "j",
                          "k",
                          "l",
                          "m",
                          "n",
                          "o",
                          "p",
                          "q",
                          "r",
                          "s",
                          "t",
                          "u",
                          "v",
                          "w",
                          "x",
                          "y",
                          "z",
                          "1",
                          "2",
                          "3",
                          "4",
                          "5",
                          "6",
                          "7",
                          "8",
                          "9",
                          "0",
                          "ENTER",
                          "ESCAPE",
                          "BACKSPACE",
                          "TAB",
                          "SPACEBAR",
                          "-",
                          "=",
                          "[",
                          "]",
                          "\\0",
                          "~",
                          ";",
                          "'",
                          "GRAVE ACCENT",
                          ",",
                          ".",
                          "/",
                          "CAPS LOCK",
                          "F1",
                          "F2",
                          "F3",
                          "F4",
                          "F5",
                          "F6",
                          "F7",
                          "F8",
                          "F9",
                          "F10",
                          "F11",
                          "F12"
                      };


/*******************************************************
 * USB HOST HID Layer Events - Application Event Handler
 *******************************************************/

void APP_USBHostHIDKeyboardEventHandler(USB_HOST_HID_KEYBOARD_HANDLE handle, 
        USB_HOST_HID_KEYBOARD_EVENT event, void * pData)
{   
    switch ( event)
    {
        case USB_HOST_HID_KEYBOARD_EVENT_ATTACH:
            app_state =  APP_STATE_DEVICE_ATTACHED;
			LED_GREEN_On();
            break;

        case USB_HOST_HID_KEYBOARD_EVENT_DETACH:
            app_state = APP_STATE_DEVICE_DETACHED;
			LED_GREEN_Off();
            break;

        case USB_HOST_HID_KEYBOARD_EVENT_REPORT_RECEIVED:
            app_state = APP_STATE_READ_HID;
            /* Keyboard Data from device */
            memcpy(&data, pData, sizeof(data));
            break;

        default:
            break;
    }
    return;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    USB_HOST_HID_KEYBOARD_EventHandlerSet(APP_USBHostHIDKeyboardEventHandler);
    USB_HOST_BusEnable(USB_HOST_BUS_ALL);
    app_state = APP_STATE_WAIT_FOR_HOST_ENABLE;
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    static uint32_t prev_keycode=0;
    /* Check the application's current state. */
    switch ( app_state )
    {
    		
		case APP_STATE_WAIT_FOR_HOST_ENABLE:
            /* Check if the host operation has been enabled */
            if(USB_HOST_BusIsEnabled(USB_HOST_BUS_ALL))
            {
                /* This means host operation is enabled. We can
                 * move on to the next state */
                DBGU_Write("\r\n***Connect Keyboard***\r\n",
                            sizeof("\r\n***Connect Keyboard***\r\n"));
                while(DBGU_WriteIsBusy());
                app_state = APP_STATE_WAIT_FOR_DEVICE_ATTACH;
            }
            break;

        case APP_STATE_DEVICE_ATTACHED:
            DBGU_Write("---Keyboard Connected---\r\n",
                        sizeof("---Keyboard Connected---\r\n"));
            while(DBGU_WriteIsBusy());
            app_state = APP_STATE_READ_HID;
            
            break;

        case APP_STATE_READ_HID:
            if((prev_keycode != data.nonModifierKeysData[0].keyCode)&& (data.nonModifierKeysData[0].event==USB_HID_KEY_PRESSED))
            {
            if(data.nonModifierKeysData[0].keyCode >= USB_HID_KEYBOARD_KEYPAD_KEYBOARD_A &&
                  data.nonModifierKeysData[0].keyCode  <= USB_HID_KEYBOARD_KEYPAD_KEYBOARD_0_AND_CLOSE_PARENTHESIS)

            DBGU_Write((void *)keyValue[data.nonModifierKeysData[0].keyCode],
                            strlen(keyValue[data.nonModifierKeysData[0].keyCode]));
            prev_keycode=data.nonModifierKeysData[0].keyCode;
            }
            break;

        case APP_STATE_DEVICE_DETACHED:
            DBGU_Write("---Keyboard Disconnected---\r\n",
                        sizeof("---Keyboard Disconnected---\r\n"));
            while(DBGU_WriteIsBusy());
            app_state = APP_STATE_WAIT_FOR_DEVICE_ATTACH;
            break;

        default:
            break;
    }

}


/*******************************************************************************
 End of File
 */
