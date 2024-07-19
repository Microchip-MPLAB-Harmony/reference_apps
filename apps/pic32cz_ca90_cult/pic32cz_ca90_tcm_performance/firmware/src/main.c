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

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2024 Microchip Technology Inc. and its subsidiaries.
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

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

#define LOCK_ACCESS_KEY         0xC5ACCE55
#define BUFF_SIZE               0x1000

/* 
 The following buffers and function/APIs are placed in the Flash Memory 
 */

const char *pBuffer = "The ARM architecture is defined in a hierarchical manner, where the features are described in Chapter A2\
                       Application Level Programmers?Model at the application level, with underlying system support. What\
                       features are available and how they are supported is defined in the architecture profiles, making the system\
                       level support profile specific. Deprecated features can be found in an appendix to this manual. See\
                       page AppxD-1.\
                       As stated in Privileged execution on page A2-13, programs can execute in a privileged or unprivileged\
                       manner. System level support requires privileged access, allowing it the access permissions to configure and\
                       control the resources. This is typically supported by an operating system, which provides system services\
                       to the applications, either transparently, or through application initiated service calls. The operating system\
                       is also responsible for servicing interrupts and other system events, making exceptions a key component of\
                       the system level programmers?model.";

const void Flash_memcpy(uint8_t *pDest, uint8_t *pSrc, uint16_t len)
{
    uint32_t i;

    __NOP();

    for(i=0u; i<len; i++) 
    {
      pSrc[i] = 0u;
    }

    for(i=0u; i<len; i++) 
    {
      pDest[i] = 0u;
    } 

    for(i=0u; i<len; i++) 
    {
      pSrc[i] = pBuffer[i];
    }

    __DSB();
    __ISB();
    __DMB();  

    for(i=0u; i<len; i++) 
    {
      pDest[i] = pSrc[i];
    }
    
    __DSB();
    __ISB();

}

/* 
 The following buffers and function/APIs are placed in the Tightly Coupled Memory 
 */

static uint8_t __attribute__((tcm)) TCM_SrcBuff[BUFF_SIZE], TCM_DestBuff[BUFF_SIZE];

static void  __attribute__((tcm)) TCM_memcpy(uint8_t *pDest, uint8_t *pSrc, uint16_t len)
{
    uint32_t i;

    for(i=0u; i<len; i++) 
    {
        pSrc[i] = 0u;
    }

    for(i=0u; i<len; i++) 
    {
        pDest[i] = 0u;
    } 

    for(i=0u; i<len; i++) 
    {
        pSrc[i] = pBuffer[i];
    }

    __DSB();
    __ISB();
    __DMB();  

    for(i=0u; i<len; i++) 
    {
        pDest[i] = pSrc[i];
    }
    
    __DSB();
    __ISB();

}

/* 
 The following buffers and function/APIs are placed in the SRAM 
 */

uint8_t SrcBuff[BUFF_SIZE], DestBuff[BUFF_SIZE];

void  __attribute__ ((ramfunc,long_call)) SRAM_memcpy(uint8_t *pDest, uint8_t *pSrc, uint16_t len)
{
    uint32_t i;

    for(i=0u; i<len; i++) 
    {
        pSrc[i] = 0u;
    }

    for(i=0u; i<len; i++) 
    {
        pDest[i] = 0u;
    } 

    for(i=0u; i<len; i++) 
    {
        pSrc[i] = pBuffer[i];
    }

    __DSB();
    __ISB();
    __DMB();  

    for(i=0u; i<len; i++) 
    {
        pDest[i] = pSrc[i];
    }
    
    __DSB();
    __ISB();

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
    
    /* Serial Console Message */
    printf("\n\r---------------------------------------------------------");
    printf("\n\r                 TCM Performance Demo                    ");
    printf("\n\r---------------------------------------------------------\n\r");

    CoreDebug->DEMCR = CoreDebug_DEMCR_TRCENA_Msk;
    __DSB();

    DWT->LAR = LOCK_ACCESS_KEY;
    __DSB();    
    
    printf("\n\r\n\r Disabled Instruction & Data Cache \n\r\n\r");

    printf(" Code/Buffer - Cycles");

    printf("\n\r Flash/SRAM - ");
    DWT_CounterReset();
    Flash_memcpy(DestBuff, SrcBuff, BUFF_SIZE);
    printf(" %ld ",DWT_CounterGet());
    
    printf("\n\r Flash/DTCM - ");
    DWT_CounterReset();
    Flash_memcpy(TCM_DestBuff, TCM_SrcBuff, BUFF_SIZE);
    printf(" %ld ",DWT_CounterGet());

    printf("\n\r SRAM/SRAM  - ");
    DWT_CounterReset();
    SRAM_memcpy(DestBuff, SrcBuff, BUFF_SIZE);
    printf(" %ld ",DWT_CounterGet());
    
    printf("\n\r SRAM/DTCM  - ");
    DWT_CounterReset();
    SRAM_memcpy(TCM_DestBuff, TCM_SrcBuff, BUFF_SIZE);
    printf(" %ld ",DWT_CounterGet());
    
    printf("\n\r ITCM/SRAM  - ");
    DWT_CounterReset();
    TCM_memcpy(DestBuff, SrcBuff, BUFF_SIZE);  
    printf(" %ld ",DWT_CounterGet());
    
    printf("\n\r ITCM/DTCM  - ");
    DWT_CounterReset();
    TCM_memcpy(TCM_DestBuff, TCM_SrcBuff, BUFF_SIZE); 
    printf(" %ld ",DWT_CounterGet());
    
    
    printf("\n\r\n\r Enabled Instruction Cache \n\r\n\r");
    SCB_EnableICache();
    
    printf(" Code/Buffer - Cycles");
    
    printf("\n\r Flash/SRAM - ");
    DWT_CounterReset();
    Flash_memcpy(DestBuff, SrcBuff, BUFF_SIZE);
    printf(" %ld ",DWT_CounterGet());
    
    printf("\n\r Flash/DTCM - ");
    DWT_CounterReset();
    Flash_memcpy(TCM_DestBuff, TCM_SrcBuff, BUFF_SIZE);
    printf(" %ld ",DWT_CounterGet());

    printf("\n\r SRAM/SRAM  - ");
    DWT_CounterReset();
    SRAM_memcpy(DestBuff, SrcBuff, BUFF_SIZE);
    printf(" %ld ",DWT_CounterGet());
    
    printf("\n\r SRAM/DTCM  - ");
    DWT_CounterReset();
    SRAM_memcpy(TCM_DestBuff, TCM_SrcBuff, BUFF_SIZE);
    printf(" %ld ",DWT_CounterGet());
    
    printf("\n\r ITCM/SRAM  - ");
    DWT_CounterReset();
    TCM_memcpy(DestBuff, SrcBuff, BUFF_SIZE);  
    printf(" %ld ",DWT_CounterGet());
    
    printf("\n\r ITCM/DTCM  - ");
    DWT_CounterReset();
    TCM_memcpy(TCM_DestBuff, TCM_SrcBuff, BUFF_SIZE); 
    printf(" %ld ",DWT_CounterGet());


    printf("\n\r\n\r Enabled Instruction & Data Cache \n\r\n\r");
    SCB_EnableDCache();
    
    printf(" Code/Buffer - Cycles");

    printf("\n\r Flash/SRAM - ");
    DWT_CounterReset();
    Flash_memcpy(DestBuff, SrcBuff, BUFF_SIZE);
    printf(" %ld ",DWT_CounterGet());
    
    printf("\n\r Flash/DTCM - ");
    DWT_CounterReset();
    Flash_memcpy(TCM_DestBuff, TCM_SrcBuff, BUFF_SIZE);
    printf(" %ld ",DWT_CounterGet());

    printf("\n\r SRAM/SRAM  - ");
    DWT_CounterReset();
    SRAM_memcpy(DestBuff, SrcBuff, BUFF_SIZE);
    printf(" %ld ",DWT_CounterGet());
    
    printf("\n\r SRAM/DTCM  - ");
    DWT_CounterReset();
    SRAM_memcpy(TCM_DestBuff, TCM_SrcBuff, BUFF_SIZE);
    printf(" %ld ",DWT_CounterGet());
    
    printf("\n\r ITCM/SRAM  - ");
    DWT_CounterReset();
    TCM_memcpy(DestBuff, SrcBuff, BUFF_SIZE);  
    printf(" %ld ",DWT_CounterGet());
    
    printf("\n\r ITCM/DTCM  - ");
    DWT_CounterReset();
    TCM_memcpy(TCM_DestBuff, TCM_SrcBuff, BUFF_SIZE); 
    printf(" %ld ",DWT_CounterGet());

    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

