/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_can.c

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
/*******************************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.

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

#include "app_can.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_CAN_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

/* Variable to save Tx/Rx transfer status and context */
static uint32_t status = 0;
/*Rx FIFO 0 */
static uint8_t rxFiFo0[CAN1_RX_FIFO0_SIZE];


APP_CAN_DATA app_canData;

uint8_t Can1MessageRAM[CAN1_MESSAGE_RAM_CONFIG_SIZE] __attribute__((aligned (32)));

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

/* This function will be called by CAN PLIB when Message received in Rx FIFO0 */
void APP_CAN_RxFifo0Callback(uint8_t numberOfMessage, uintptr_t context)
{

    /* Check CAN Status */
    status = CAN1_ErrorGet();

    if (((status & CAN_PSR_LEC_Msk) == CAN_ERROR_NONE) || ((status & CAN_PSR_LEC_Msk) == CAN_ERROR_LEC_NC))
    {

                memset(rxFiFo0, 0x00, (numberOfMessage * CAN1_RX_FIFO0_ELEMENT_SIZE));
                if (CAN1_MessageReceiveFifo(CAN_RX_FIFO_0, numberOfMessage, (CAN_RX_BUFFER *)rxFiFo0) == true)
                {
                    app_canData.state = APP_CAN_STATE_READ_COMPLETE;
                }
                else
                {
                    app_canData.state = APP_CAN_STATE_ERROR;
                }
    }
    else
    {
        state = APP_CAN_STATE_ERROR;
    }
}



// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_CAN_Initialize ( void )

  Remarks:
    See prototype in app_can.h.
 */

void APP_CAN_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_canData.state = APP_CAN_STATE_INIT;



    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}

/*******************************************************************************
  Function
    int8_t COMMON_APP_CAN_DataIsReady ( void )

  Summary
    Check if data from CAN task is ready

  Returns
    1 - if data is available

  Example
    <code>
    int8_t temp = COMMON_APP_CAN_DataIsReady();
    </code>
 */
int8_t COMMON_APP_CAN_DataIsReady(void)
{
    return app_canData.isDataReady;
}

/*******************************************************************************
  Function
    Summary
    Gets CAN data

  Returns
    unsigned int

  Example
    <code>
    uint32_t temp = COMMON_APP_CAN_GetData();
    </code>
 */
uint8_t * COMMON_APP_CAN_GetData(void)
{
    return app_canData.can_data;
}
/*******************************************************************************
  Function
    void COMMON_APP_CAN_DataStatus(bool);

  Summary
    set the status of CAN Data 

  Example
    <code>
    COMMON_APP_CAN_DataStatus(true); 
    COMMON_APP_CAN_DataStatus(false);
    </code>
 */

void COMMON_APP_CAN_DataStatus(bool flag)
{
    app_canData.isDataReady = flag;  
}
/******************************************************************************
  Function:
    void APP_CAN_Tasks ( void )

  Remarks:
    See prototype in app_can.h.
 */

void APP_CAN_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( app_canData.state )
    {
        /* Application's initial state. */
        case APP_CAN_STATE_INIT:
           /* Set Message RAM Configuration */
            CAN1_MessageRAMConfigSet(Can1MessageRAM);
            CAN1_RxFifoCallbackRegister(CAN_RX_FIFO_0, APP_CAN_RxFifo0Callback, APP_CAN_STATE_READ_COMPLETE);
            app_canData.state = APP_CAN_STATE_IDLE;
            
            break;
                
        case APP_CAN_STATE_READ_COMPLETE:
            app_canData.can_data= rxFiFo0;
            COMMON_APP_CAN_DataStatus(true);
            app_canData.state = APP_CAN_STATE_IDLE;
            
            break;
        
        case APP_CAN_STATE_SCHEDULE_WRITE:
            /* Do something here*/
            //currently not implemented
            app_canData.state = APP_CAN_STATE_WAIT_FOR_WRITE_COMPLETE;
            
            break;
        
        case APP_CAN_STATE_WAIT_FOR_WRITE_COMPLETE:
            /* Do something here*/
            //currently not implemented
            app_canData.state = APP_CAN_STATE_IDLE;
            
            break;
        
        case APP_CAN_STATE_IDLE:
            /* Schedule something here based on conditions*/
             
            
            break;

        case APP_CAN_STATE_ERROR:
        default:
            
            break; 
    }
}


/*******************************************************************************
 End of File
 */
