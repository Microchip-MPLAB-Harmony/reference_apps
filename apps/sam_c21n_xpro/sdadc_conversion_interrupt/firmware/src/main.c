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


#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include <string.h>


#define SDADC_RESULT_SIGNED_BIT_MSK     (~(0x01 << 15))


float g_input_voltage=0.0;

float SDADC_VREF=4.096;                      // SDADC reference voltage is set to 1.024 initially.

uint16_t g_result_reg=0;                       // Data read from result register
uint16_t g_ref=4096;                         // SDADC reference voltage in mV.
uint16_t g_osr=64;

bool g_result=false;


void App_SDADC_Menu(void);


/******************************************************************************
Function:     App_SDADC_Menu
Description:  Displaying app features for getting input from user
Input:        nothing 
Output:       nothing 
******************************************************************************/
void App_SDADC_Menu(void)
{

    printf("\r\nConversion range: %d mV\r\n",g_ref);
    printf("Oversampling Ratio: %d\r\n",g_osr);

    printf("\r\nPress r to read the result\r\n");

}


void Handler(SDADC_STATUS status, uintptr_t context)
{
    g_result=true;
}

int main(void)
{
    char menu_input=0;
   

    /* Initialize all modules */
    SYS_Initialize ( NULL );
    SDADC_REGS->SDADC_REFCTRL |= SDADC_REFCTRL_ONREFBUF(0x01);
    SDADC_CallbackRegister(Handler,(uintptr_t)NULL);                             //Registering the callback function for RESRDY interrupt
                                                    

    App_SDADC_Menu();
    while ( true )
    {

        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );

        scanf("%c",&menu_input);

        if(menu_input=='r') {

   
            while(!g_result);
            g_result=false;
            g_result_reg=SDADC_ConversionResultGet();                                                                 //Getting raw result from register
            g_input_voltage = (float)(g_result_reg & SDADC_RESULT_SIGNED_BIT_MSK) * SDADC_VREF / 32767;                 //Converting raw result into voltage
            printf("\n\r SDADC I/P voltage = %d.%02d V \n\r",(int)g_input_voltage,(int)((g_input_voltage - (int)g_input_voltage)*100.0));

         


        }

    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}



