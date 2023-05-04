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
/*******************************************************************************************
* Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.

 * Subject to your compliance with these terms, you may use this Microchip software
 * and any derivatives exclusively with Microchip products. You are responsible for
 * complying with third party license terms applicable to your use of third party
 * software (including open source software) that may accompany this Microchip software.

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
 *******************************************************************************************/
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
#include "unsecure_interface.h"
#include "../src/simpleMAP/simpleMAP_HAL.h"
#include "app_secure_ble_manager.h"
#include "../atca_basic.h"

/* typedef for non-secure callback functions */
typedef void (*funcptr_void) (void) __attribute__((cmse_nonsecure_call));
volatile bool PREVIOUS_TIMER_HANDLER_PROCESSING;


//-- Initialize ECC608 and simpleMAP Library
uint32_t flash_addresses[3] = {0x00020000,0x00020100,TZ_START_NS};

uint32_t test_counter = 0;

/* ************************************************************************** */
/** TIMER 0 INTERRUPT HANDLER
 */
void TC0_CH0_TimerInterruptHandler(TC_TIMER_STATUS status, uintptr_t context)
{
    //--- ENSURE ONLY ONE INSTANCE OF TIMER INTERRUPT IS RUNNING AT A TIME
    // Potential race condition when sending open command from cloud. Hence resetting counter and preventing infinite return of function.
    if(PREVIOUS_TIMER_HANDLER_PROCESSING) 
    {
        test_counter++;
       // return;
    }
    if ((test_counter <=4) && (test_counter >= 1))
    {
        return;
    }
    test_counter = 0;
    PREVIOUS_TIMER_HANDLER_PROCESSING = true;
    
    //--- MANGE BLE MODULE
    APP_SECURE_BLE_MANAGER_Task();
    
    //--- MANAGE SIMPLEMAP LIBRARY
    simpleMAP_Task();
    
    //--- ENSURE ONLY ONE INSTANCE OF TIMER INTERRUPT IS RUNNING AT A TIME
    PREVIOUS_TIMER_HANDLER_PROCESSING = false;
}

/* ************************************************************************** */
/** JUMP TO UNSECURE (->start USER APPLICATION)
 */
void jump_to_unsecure(){
    uint32_t msp_ns = *((uint32_t *)(TZ_START_NS));
    volatile funcptr_void NonSecure_ResetHandler;

    
    if (msp_ns != 0xFFFFFFFF)
    {
        //--- Set non-secure main stack (MSP_NS) 
        __TZ_set_MSP_NS(msp_ns);

        //--- Get non-secure reset handler 
        NonSecure_ResetHandler = (funcptr_void)(*((uint32_t *)((TZ_START_NS) + 4U)));

        //--- Start non-secure state software application 
        NonSecure_ResetHandler();
    }
}

//--- BLE COM : DMA TX INTERRUPT
static void ble_transmitted_data(DMAC_TRANSFER_EVENT event, uintptr_t contextHandle)
{
    simpleMAP_TRANSFER_NEXT_IN_TX_QUEUE();
}

//--- BLE COM : DMA RX INTERRUPT
static void ble_received_data(DMAC_TRANSFER_EVENT event, uintptr_t contextHandle)
{
    simpleMAP_INSERT_IN_RX_QUEUE();
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
 
    //-- Initialize simpleMAP Hardware Abstraction Layer
    simpleMAP_HAL_init();
    
    
    //-- Reset BLE  BM70 module
    APP_SECURE_BLE_MANAGER_ModuleReset();
    
    printf("SMART Door Lock v1.3 \r\n");
    
    //-- Initialize timer TC0 and start
    PREVIOUS_TIMER_HANDLER_PROCESSING = false;
    TC0_TimerCallbackRegister(TC0_CH0_TimerInterruptHandler, (uintptr_t)NULL);
    TC0_TimerStart();

    //-- Initialize BLE UART DMA for receiving 16bytes
    DMAC_ChannelCallbackRegister(DMAC_CHANNEL_0, ble_received_data,0);
    MCU_START_RECEIVE_ON_CHANNEL();
    
    //-- Initialize BLE UART DMA for transmitting 16bytes
    DMAC_ChannelCallbackRegister(DMAC_CHANNEL_1, ble_transmitted_data,0);
    

    simpleMAP_ASSERT_BOOL(simpleMAP_Library_init(ECC_I2C_7BIT_ADDRESS,I2C_BAUDRATE_1M,flash_addresses,(uint8_t *)default_IOPROTECTIONKEY,(uint8_t *)ROOTCA_PUBLIC),"INIT FAIL");

 
    PRESENT_FW_VER[0]    = 0x01;
    PRESENT_FW_VER[1]   = 0x01;  
    
    jump_to_unsecure();
    
    while ( true )
    {
    }

    /* Execution should not come here during normal operation */
    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

