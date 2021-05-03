/*******************************************************************************
  Thumbstick click example source file

  Company:
    Microchip Technology Inc.

  File Name:
    thumbstick_example.c

  Summary:
    Thumbstick click routine example implementation file.

  Description:
    This file contains the usage of Thumbstick click routine APIs. The
    Thumbstick_Example() function get the final direction, push button status
    and prints the status on the terminal.
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

#include "definitions.h"
#include "../click_interface.h"
#include "thumbstick.h"
#include "thumbstick_example.h"


static bool thumbstick_init = false;

void Thumbstick_Example(void){

    uint8_t direction = DEFAULT_POSITION;

    if (thumbstick_init == false)
    {
        Thumbstick_Initialize();
        thumbstick_init = true;
    }
    else
    {
        direction = Thumbstick_GetFinalDirection();
        CLICK_THUMBSTICK_DelayMs(155);

        if(direction == UP)
        {
            LED0_Toggle();
            printf("UP\r\n");

        }else if(direction == DOWN)
        {
            LED0_Toggle();
            printf("DOWN\r\n");
        }else if(direction == LEFT)
        {
            LED0_Toggle();
            printf("LEFT\r\n");

        }else if(direction == RIGHT)
        {
            LED0_Toggle();
            printf("RIGHT\r\n");

        }else if(direction == DEFAULT_POSITION)
        {
            LED0_Clear();
        }

        if (CLICK_THUMBSTICK_PUSH_BUTTON_Get() == THUMBSTICK_PUSH_BUTTON_PRESSED)
        {
            LED0_Toggle();
            printf("Thumbstick Push Button Pressed\r\n");
        }
    }
}
