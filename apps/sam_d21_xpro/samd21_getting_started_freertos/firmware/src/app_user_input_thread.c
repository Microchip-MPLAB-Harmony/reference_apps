/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_user_input_thread.c

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
* © [2020] Microchip Technology Inc. and its subsidiaries
 
 * Subject to your compliance with these terms, you may use this Microchip software
 * and any derivatives exclusively with Microchip products. You are responsible for
 * complying with third party license terms applicable to your use of third party
 * software (including open source software) that may accompany this Microchip software.
 
 * SOFTWARE IS ?AS IS.? NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO
 * THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT,
 * SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF
 * THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW,
 * MICROCHIP?S TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT EXCEED AMOUNT
 * OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE. ADDITIONALLY, MICROCHIP
 * OFFERS NO SUPPORT FOR THE SOFTWARE. YOU MAY CONTACT YOUR LOCAL MICROCHIP FIELD SALES SUPPORT
 * REPRESENTATIVE TO INQUIRE ABOUT SUPPORT SERVICES AND APPLICABLE FEES, IF ANY. THESE TERMS
 * OVERRIDE ANY OTHER PRIOR OR SUBSEQUENT TERMS OR CONDITIONS THAT MIGHT APPLY TO THIS SOFTWARE
 * AND BY USING THE SOFTWARE, YOU AGREE TO THESE TERMS.
*******************************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app_user_input_thread.h"
#include "config/sam_d21_xpro/peripheral/sercom/usart/plib_sercom3_usart.h"
//#include "peripheral/sercom/usart/plib_sercom_usart_common.h"

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
    This structure should be initialized by the APP_USER_INPUT_THREAD_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_USER_INPUT_THREAD_DATA app_user_inputData;
QueueHandle_t eventQueue;
// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

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
    void APP_USER_INPUT_THREAD_Initialize ( void )

  Remarks:
    See prototype in app_user_input_thread.h.
 */

void APP_USER_INPUT_THREAD_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_user_inputData.isInitDone = false;

    eventQueue = xQueueCreate( 3, sizeof(EVENT_INFO) );
    if (eventQueue == NULL)
    {
        uint8_t Queue_error[] = "Queue is empty\r\n";
        /* Handle error condition. Not sufficient memory to create Queue */
        SERCOM3_USART_Write((char*)Queue_error,sizeof(Queue_error));
    }      
}


/******************************************************************************
  Function:
    void APP_USER_INPUT_THREAD_Tasks ( void )

  Remarks:
    See prototype in app_user_input_thread.h.
 */

void APP_USER_INPUT_THREAD_Tasks ( void )
{
    uint8_t usartData;   
    
    /* Open the drivers if not already opened */
    if (app_user_inputData.isInitDone == false)
    {
        /* Open the USART driver to read user key press */
        app_user_inputData.usartHandle = DRV_USART_Open(DRV_USART_INDEX_0, 0);
        
        if (app_user_inputData.usartHandle == DRV_HANDLE_INVALID)
        {
            /* Handle Error */
            uint8_t usart_input_error[] = "USART Input Handle Failed\r\n";
            SERCOM3_USART_Write((char*)usart_input_error,sizeof(usart_input_error));
            vTaskSuspend(NULL);
        }    
        else
        {
            /* All drivers opened successfully */
            app_user_inputData.isInitDone = true;
        }
    }
                        
    /* Submit a blocking USART read request (user input). */    
    if (DRV_USART_ReadBuffer(app_user_inputData.usartHandle, &usartData, 1 ) == true)
    {
        app_user_inputData.eventInfo.eventType = EVENT_TYPE_TEMP_READ_REQ;
        app_user_inputData.eventInfo.eventData = usartData;

        /* Use FreeRTOS queue to notify the EEPROM task to print the logged temperature values */
        xQueueSend( eventQueue, &app_user_inputData.eventInfo, portMAX_DELAY );
    }
    else
    {
        /* Handle error condition */
        uint8_t usart_read_failed[] = "USART Read Request Submit Failed\r\n";
        SERCOM3_USART_Write((char*)usart_read_failed,sizeof(usart_read_failed));
        vTaskSuspend(NULL);
    }
}

/*******************************************************************************
 End of File
 */
