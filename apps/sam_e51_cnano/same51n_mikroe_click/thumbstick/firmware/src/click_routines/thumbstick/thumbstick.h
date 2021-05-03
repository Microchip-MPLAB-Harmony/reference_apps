/*******************************************************************************
  Thumbstick click header file

  Company:
    Microchip Technology Inc.

  File Name:
    thumbstick.h

  Summary:
    Thumbstick click routine implementation file.

  Description:
    This file defines the interface to the Thumbstick click using the SPI PLIB.
    This click routine gets the final direction of the X and Y axis of the
    Thumbstick.
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

#ifndef THUMBSTICK_H
#define THUMBSTICK_H

#include <stdio.h>

#define THUMBSTICK_PUSH_BUTTON_PRESSED          0
#define THUMBSTICK_PUSH_BUTTON_NOT_PRESSED      1

typedef enum
{
    UP = 0,
    DOWN,
    RIGHT,
    LEFT,
    DEFAULT_POSITION
}THUMBSTICK_POSITION;


/*******************************************************************************
 Function:
    void Thumbstick_Initialize();

  Summary:
    Thumbstick initialization routine.

  Description:
    This function contains the initialization the Thumbstick module.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    None.


  Remarks:
    None.
*/
void Thumbstick_Initialize(void);

/*******************************************************************************
 Function:
    uint8_t Thumbstick_GetFinalDirection();

  Summary:
    Get the final direction of Thumbstick.

  Description:
    This function gets the final direction of Thumbstick.

  Precondition:
    The ("Thumbstick_Initialize") function should be called before calling this function.

  Parameters:
    None.

  Returns:
    Final direction of Thumbstick.

  Remarks:
    This routine should be called periodically in a loop.
*/
uint8_t Thumbstick_GetFinalDirection(void);

#ifdef  __cplusplus
}
#endif

#endif  /* THUMBSTICK_H */

