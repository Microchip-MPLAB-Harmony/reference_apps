/*******************************************************************************
  System Exceptions File

  File Name:
    exceptions.c

  Summary:
    This file contains a function which overrides the default _weak_ exception
    handlers provided by the interrupt.c file.

  Description:
    This file redefines the default _weak_  exception handler with a more debug
    friendly one. If an unexpected exception occurs the code will stop in a
    while(1) loop.
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
#include "interrupts.h"
#include "definitions.h"
#include <stdio.h>


// *****************************************************************************
// *****************************************************************************
// Section: Local functions
// *****************************************************************************
// *****************************************************************************

typedef void(*advanced_handler_t)(uint32_t * fault_args, unsigned int lr_value);


static inline void call_advanced_exception_handler(advanced_handler_t pHandler)
{
    asm volatile (
        "MOVS   R0, #4\n\t"
        "MOV    R1, LR\n\t"
        "TST    R0, R1\n\t"
        "BEQ    stacking_used_MSP\n\t"
        "MRS    R0, PSP\n\t"
        "B      invoke_handler \n\t"
        "stacking_used_MSP: \n"
        "MRS    R0, MSP\n\t"
        "invoke_handler: \n"
        "BX     %0"::"r"(pHandler));
}

/* MISRAC 2012 deviation block start */
/* MISRA C-2012 Rule 21.6 deviated 98 times.  Deviation record ID -  H3_MISRAC_2012_R_21_6_DR_1 */
static void __attribute__((noreturn)) ProcessHardFaultException(uint32_t * fault_args, unsigned int lr_value)
{
    uint32_t stacked_r0;
    uint32_t stacked_r1;
    uint32_t stacked_r2;
    uint32_t stacked_r3;
    uint32_t stacked_r12;
    uint32_t stacked_lr;
    uint32_t stacked_pc;
    uint32_t stacked_psr;

    stacked_r0  = fault_args[0];
    stacked_r1  = fault_args[1];
    stacked_r2  = fault_args[2];
    stacked_r3  = fault_args[3];
    stacked_r12 = fault_args[4];
    stacked_lr  = fault_args[5];  // Link Register
    stacked_pc  = fault_args[6];  // Program Counter
    stacked_psr = fault_args[7];  // Program Status Register

    (void)printf("\r\n");
    (void)printf("[HardFault]\r\n");
    (void)printf("- Stack frame:\r\n");
    (void)printf(" R0  = 0x%08lX\r\n", stacked_r0);
    (void)printf(" R1  = 0x%08lX\r\n", stacked_r1);
    (void)printf(" R2  = 0x%08lX\r\n", stacked_r2);
    (void)printf(" R3  = 0x%08lX\r\n", stacked_r3);
    (void)printf(" R12 = 0x%08lX\r\n", stacked_r12);
    (void)printf(" LR  = 0x%08lX\r\n", stacked_lr);
    (void)printf(" PC  = 0x%08lX\r\n", stacked_pc);
    (void)printf(" PSR = 0x%08lX\r\n", stacked_psr);

    (void)printf("- Misc\r\n");
    (void)printf(" LR/EXC_RETURN = 0x%X, Bit 2: %d\r\n", lr_value, (lr_value & 0x4U) >> 2);

    #if defined(__DEBUG) || defined(__DEBUG_D) && defined(__XC32)
    __builtin_software_breakpoint();
    #endif

    while (true)
    {
        // Do Nothing
    }
}

 

// *****************************************************************************
// *****************************************************************************
// Section: Exception Handling Routine
// *****************************************************************************
// *****************************************************************************

/* Brief default interrupt handlers for core IRQs.*/
void __attribute__((noreturn, weak)) NonMaskableInt_Handler(void)
{
#if defined(__DEBUG) || defined(__DEBUG_D) && defined(__XC32)
    __builtin_software_breakpoint();
#endif
    while (true)
    {
    }
}

void __attribute__((used)) HardFault_Handler(void)
{
    call_advanced_exception_handler(ProcessHardFaultException);
}

 
/*******************************************************************************
 End of File
 */
