/*******************************************************************************
 System Tasks File

  File Name:
    tasks.c

  Summary:
    This file contains source code necessary to maintain system's polled tasks.

  Description:
    This file contains source code necessary to maintain system's polled tasks.
    It implements the "SYS_Tasks" function that calls the individual "Tasks"
    functions for all polled MPLAB Harmony modules in the system.

  Remarks:
    This file requires access to the systemObjects global data structure that
    contains the object handles to all MPLAB Harmony module objects executing
    polled in the system.  These handles are passed into the individual module
    "Tasks" functions to identify the instance of the module to maintain.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

#include "configuration.h"
#include "definitions.h"
#include "sys_tasks.h"


// *****************************************************************************
// *****************************************************************************
// Section: RTOS "Tasks" Routine
// *****************************************************************************
// *****************************************************************************
static void lDRV_SDSPI_0_Tasks(  void *pvParameters  )
{
    while(true)
    {
        DRV_SDSPI_Tasks(sysObj.drvSDSPI0);
        vTaskDelay(1U / portTICK_PERIOD_MS);
    }
}

void _SSD1963_Tasks(  void *pvParameters  )
{
    while(1)
    {
        DRV_SSD1963_Update();
        vTaskDelay(1 / portTICK_PERIOD_MS);
    }
}

void _DRV_MAXTOUCH_Tasks(  void *pvParameters  )
{
    while(1)
    {
        DRV_MAXTOUCH_Tasks(sysObj.drvMAXTOUCH);
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

/* Handle for the APP_Tasks. */
TaskHandle_t xAPP_Tasks;

static void lAPP_Tasks(  void *pvParameters  )
{   
    while(true)
    {
        APP_Tasks();
        vTaskDelay(50U / portTICK_PERIOD_MS);
    }
}
/* Handle for the APP_HTTP_Tasks. */
TaskHandle_t xAPP_HTTP_Tasks;

static void lAPP_HTTP_Tasks(  void *pvParameters  )
{   
    while(true)
    {
        APP_HTTP_Tasks();
        vTaskDelay(50U / portTICK_PERIOD_MS);
    }
}
/* Handle for the APP_GFX_Tasks. */
TaskHandle_t xAPP_GFX_Tasks;

static void lAPP_GFX_Tasks(  void *pvParameters  )
{   
    while(true)
    {
        APP_GFX_Tasks();
        vTaskDelay(50U / portTICK_PERIOD_MS);
    }
}


void _TCPIP_STACK_Task(  void *pvParameters  )
{
    while(1)
    {
        TCPIP_STACK_Task(sysObj.tcpip);
        vTaskDelay(1 / portTICK_PERIOD_MS);
    }
}

TaskHandle_t xSYS_CMD_Tasks;
void lSYS_CMD_Tasks(  void *pvParameters  )
{
    while(1)
    {
        SYS_CMD_Tasks();
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}


void _LEGATO_Tasks(  void *pvParameters  )
{
    while(1)
    {
        Legato_Tasks();
        vTaskDelay(1 / portTICK_PERIOD_MS);
    }
}


void _DRV_MIIM_Task(  void *pvParameters  )
{
    while(1)
    {
       
       
       DRV_MIIM_OBJECT_BASE_Default.DRV_MIIM_Tasks(sysObj.drvMiim_0);
       
       
       
        vTaskDelay(50 / portTICK_PERIOD_MS);
       
    }
}

void _SYS_INPUT_Tasks(  void *pvParameters  )
{
    while(1)
    {
        SYS_INP_Tasks();
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}


void _NET_PRES_Tasks(  void *pvParameters  )
{
    while(1)
    {
        NET_PRES_Tasks(sysObj.netPres);
        vTaskDelay(1 / portTICK_PERIOD_MS);
    }
}


static void lSYS_FS_Tasks(  void *pvParameters  )
{
    while(true)
    {
        SYS_FS_Tasks();
        vTaskDelay(1U / portTICK_PERIOD_MS);
    }
}





// *****************************************************************************
// *****************************************************************************
// Section: System "Tasks" Routine
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void SYS_Tasks ( void )

  Remarks:
    See prototype in system/common/sys_module.h.
*/
void SYS_Tasks ( void )
{
    /* Maintain system services */
    

    (void) xTaskCreate( lSYS_CMD_Tasks,
        "SYS_CMD_TASKS",
        SYS_CMD_RTOS_STACK_SIZE,
        (void*)NULL,
        SYS_CMD_RTOS_TASK_PRIORITY,
        &xSYS_CMD_Tasks
    );



    (void) xTaskCreate( lSYS_FS_Tasks,
        "SYS_FS_TASKS",
        SYS_FS_STACK_SIZE,
        (void*)NULL,
        SYS_FS_PRIORITY,
        (TaskHandle_t*)NULL
    );



    /* Maintain Device Drivers */
        (void) xTaskCreate( lDRV_SDSPI_0_Tasks,
        "DRV_SD_0_TASKS",
        DRV_SDSPI_STACK_SIZE_IDX0,
        (void*)NULL,
        DRV_SDSPI_PRIORITY_IDX0,
        (TaskHandle_t*)NULL
    );


    xTaskCreate( _SSD1963_Tasks,
        "SSD1963_Tasks",
        1024,
        (void*)NULL,
        1,
        (TaskHandle_t*)NULL
    );


    xTaskCreate( _DRV_MAXTOUCH_Tasks,
        "DRV_MAXTOUCH_Tasks",
        1024,
        (void*)NULL,
        1,
        (TaskHandle_t*)NULL
    );

    xTaskCreate( _DRV_MIIM_Task,
        "DRV_MIIM_Tasks",
        DRV_MIIM_RTOS_STACK_SIZE,
        (void*)NULL,
        DRV_MIIM_RTOS_TASK_PRIORITY,
        (TaskHandle_t*)NULL
    );




    /* Maintain Middleware & Other Libraries */
    
    xTaskCreate( _TCPIP_STACK_Task,
        "TCPIP_STACK_Tasks",
        TCPIP_RTOS_STACK_SIZE,
        (void*)NULL,
        TCPIP_RTOS_PRIORITY,
        (TaskHandle_t*)NULL
    );



    xTaskCreate( _LEGATO_Tasks,
        "LEGATO_Tasks",
        1024,
        (void*)NULL,
        1,
        (TaskHandle_t*)NULL
    );


    xTaskCreate( _SYS_INPUT_Tasks,
        "SYS_INPUT_Tasks",
        1024,
        (void*)NULL,
        1,
        (TaskHandle_t*)NULL
    );


    xTaskCreate( _NET_PRES_Tasks,
        "NET_PRES_Tasks",
        NET_PRES_RTOS_STACK_SIZE,
        (void*)NULL,
        NET_PRES_RTOS_TASK_PRIORITY,
        (TaskHandle_t*)NULL
    );




    /* Maintain the application's state machine. */
        /* Create OS Thread for APP_Tasks. */
    (void) xTaskCreate((TaskFunction_t) lAPP_Tasks,
                "APP_Tasks",
                1024,
                NULL,
                1,
                &xAPP_Tasks);

    /* Create OS Thread for APP_HTTP_Tasks. */
    (void) xTaskCreate((TaskFunction_t) lAPP_HTTP_Tasks,
                "APP_HTTP_Tasks",
                1024,
                NULL,
                1,
                &xAPP_HTTP_Tasks);

    /* Create OS Thread for APP_GFX_Tasks. */
    (void) xTaskCreate((TaskFunction_t) lAPP_GFX_Tasks,
                "APP_GFX_Tasks",
                1024,
                NULL,
                1,
                &xAPP_GFX_Tasks);




    /* Start RTOS Scheduler. */
    
     /**********************************************************************
     * Create all Threads for APP Tasks before starting FreeRTOS Scheduler *
     ***********************************************************************/
    vTaskStartScheduler(); /* This function never returns. */

}

/*******************************************************************************
 End of File
 */

