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
// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

#include "click_routines/eink_bundle/eink_bundle.h"
#include "click_routines/eink_bundle/eink_bundle_image.h"
#include "click_routines/eink_bundle/eink_bundle_font.h"
#include "click_routines/heartrate9/heartrate9.h"

static volatile bool switchPressEvent       = false;
static char lcl_buffer[20]                  = {0};
static int8_t   heartrate_data              = -1;

static void Switch_Press_Handler(uintptr_t context)
{
    CNANO_LED_Clear();
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
    EIC_CallbackRegister(EIC_PIN_11, Switch_Press_Handler, 0);
    
    eink_init();
    eink_image_bmp(mchp_logo);
    eink_set_font( guiFont_Tahoma_14_Regular, EINK_COLOR_BLACK, FO_HORIZONTAL);
    
    while ( true )
    {
        if(switchPressEvent == true)
        {
            if(true == is_heartrate9_byte_ready())  // Checking the Heartrate sensor data ready Status
            {
                heartrate_data      = -1;
                while(-1 == heartrate_data)
                {
                    heartrate_data = heartrate9_read_byte();
                }
                CNANO_LED_Set();
                printf("Heartrate = %d bpm \t\r\n", (uint8_t)heartrate_data);
                sprintf(lcl_buffer, "%dbpm", (uint8_t)heartrate_data);
                eink_image_bmp(heartrate_image);
                eink_set_font( guiFont_Tahoma_14_Regular, EINK_COLOR_BLACK, FO_HORIZONTAL);                
                eink_text(lcl_buffer, 0, 118 );                
            }
            switchPressEvent        = false;
        }
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

