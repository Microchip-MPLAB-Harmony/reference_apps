/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app2_user_input_thread.c

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

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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

#include "app_user_input_thread.h"

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
    See prototype in app2_user_input_thread.h.
 */

void APP_USER_INPUT_THREAD_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app_user_inputData.isInitDone = false;

    eventQueue = xQueueCreate( 3, sizeof(EVENT_INFO) );
    if (eventQueue == NULL)
    {
        /* Handle error condition. Not sufficient memory to create Queue */
    } 
}


/******************************************************************************
  Function:
    void APP_USER_INPUT_THREAD_Tasks ( void )

  Remarks:
    See prototype in app2_user_input_thread.h.
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
      }
}    
           
       

/*******************************************************************************
 End of File
 */
