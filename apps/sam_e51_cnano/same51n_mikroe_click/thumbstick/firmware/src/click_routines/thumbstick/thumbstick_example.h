/*******************************************************************************
  Thumbstick click example source file

  Company:
    Microchip Technology Inc.

  File Name:
    thumbstick_example.h

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

#ifndef THUMBSTICK_EXAMPLE_H
#define THUMBSTICK_EXAMPLE_H

/*******************************************************************************
 Function:
    void Thumbstick_Example();

  Summary:
    Thumbstick Example routine.

  Description:
    This function initializes the variables and the SPI driver used to communicate with the Thumbstick.

  Precondition:


  Parameters:
    None.

  Returns:
    None.


  Remarks:
    This routine must be called once.
*/

void Thumbstick_Example(void);

#endif // THUMBSTICK_EXAMPLE_H