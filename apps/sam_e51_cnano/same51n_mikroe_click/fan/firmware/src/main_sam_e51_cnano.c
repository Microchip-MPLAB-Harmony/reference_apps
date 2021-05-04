/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main_sam_e51_cnano.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

//DOM-IGNORE-BEGIN 
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
//DOM-IGNORE-END 

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdio.h>
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <string.h>
#include "definitions.h"                // SYS function prototypes

#include "click_routines/fan/fan.h"
#include "click_routines/fan/fan_example.h"
#include "click_routines/click_interface.h"

volatile bool switchPressEvent = false;
uint8_t speed_count = 0;

static void Switch_Press_Handler(uintptr_t context)
{
    switchPressEvent = true;
}

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );    
    EIC_CallbackRegister(EIC_PIN_15,Switch_Press_Handler, 0);
    
    fan_example();           
    printf("\r\nPress Switch to Turn ON or Set speed of the Fan\r\n");    
    while ( true )
    {
        if(switchPressEvent == true)
        {
            ++speed_count;
            if(speed_count == 1) 
            {
                fan_switch_on(); // Switch on sets fan to medium speed
                printf("\r\nFan turned ON at medium speed\r\n");
            }
            else if(speed_count == 2)
            {
                fan_set_speed(SPEED_LOW);
                printf("\r\nFan running at low speed\r\n");
            }            
            else if(speed_count == 3)
            {
                fan_set_speed(SPEED_MEDIUM);
                printf("\r\nFan running at medium speed\r\n");                
            }
            else if(speed_count == 4)
            {
                speed_count = 0;
                fan_switch_off();
                printf("\r\nFan is turned OFF\r\n");                
            }      
            switchPressEvent = false;
        }
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}
/*******************************************************************************
 End of File
*/

