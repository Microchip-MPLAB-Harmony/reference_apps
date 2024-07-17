/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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

/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "trustZone/nonsecure_entry.h"

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

enum
{
  ADD = 'a',
  MULTIPLY = 'b',
}MATH_OPERATIONS;

uint8_t cmd = 0;

void display_menu (void)
{
    printf("\n\n\n\rSelect the Math Operation");
    printf("\n\ra) Add");
    printf("\n\rb) Multiply"); 
    printf("\n\rEnter your choice");    
    scanf("%c", &cmd);
}
int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    printf("\n\r-------------------------------------------------------------");
    printf("\n\r\t\t TrustZone DEMO\t\t");
    printf("\n\r-------------------------------------------------------------");
    display_menu();
    
    uint32_t x = 0;
    uint32_t y = 0;
    uint32_t result = 0;
    while(1)
    {
        switch(cmd)
        {
            case ADD:
            {
                printf("\n\rEnter the first 16 bit unsigned number:- \t");
                scanf("%lu", &x);
                printf("\n\rEnter the second 16 bit unsigned number:- \t");
                scanf("%lu", &y);
                result = secure_add((uint16_t)x, (uint16_t)y);

                printf("\n\rThe first 16 bit unsigned number is:- %lu\t", x);
                printf("\n\rThe first 16 bit unsigned number is:- %lu\t", y);
                printf("\n\rThe result is:- \t%lu", result);

                display_menu();
                break;
            }
            case MULTIPLY:
            {
                printf("\n\rEnter the first 16 bit unsigned number:- \t");
                scanf("%lu", &x);
                printf("\n\rEnter the second 16 bit unsigned number:- \t");
                scanf("%lu", &y);
                result = secure_multiply((uint16_t)x, (uint16_t)y);
                
                printf("\n\rThe first 16 bit unsigned number is:- %lu\t", x);
                printf("\n\rThe first 16 bit unsigned number is:- %lu\t", y);
                printf("\n\rThe result is:- \t%lu", result);
                display_menu();
                break;
            }
            default:
            {
                if ((int)(cmd) != 13)
                {
                    printf("\n\rInvalid choice:- %c", cmd);
                    display_menu();
                }
                else
                {
                    scanf("%c", &cmd);
                }
                
                break;
            }
        } 
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

