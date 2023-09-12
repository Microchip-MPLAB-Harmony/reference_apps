/*******************************************************************************
  WINC Wireless Driver External Interrupt Handler

  File Name:
    wdrv_winc_eint.c

  Summary:
    External interrupt handler for WINC wireless driver.

  Description:
    External interrupt handler for WINC wireless driver.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*
Copyright (C) 2019, Microchip Technology Inc., and its subsidiaries. All rights reserved.

The software and documentation is provided by microchip and its contributors
"as is" and any express, implied or statutory warranties, including, but not
limited to, the implied warranties of merchantability, fitness for a particular
purpose and non-infringement of third party intellectual property rights are
disclaimed to the fullest extent permitted by law. In no event shall microchip
or its contributors be liable for any direct, indirect, incidental, special,
exemplary, or consequential damages (including, but not limited to, procurement
of substitute goods or services; loss of use, data, or profits; or business
interruption) however caused and on any theory of liability, whether in contract,
strict liability, or tort (including negligence or otherwise) arising in any way
out of the use of the software and documentation, even if advised of the
possibility of such damage.

Except as expressly permitted hereunder and subject to the applicable license terms
for any third-party software incorporated in the software and any applicable open
source software license terms, no license or other rights, whether express or
implied, are granted under any patent or other intellectual property rights of
Microchip or any third party.
*/

#include <stdlib.h>
#include <stdbool.h>
#include "configuration.h"
#include "definitions.h"

#if defined(INT_SOURCE_CHANGE_NOTICE) && (WDRV_WINC_INT_SOURCE == INT_SOURCE_CHANGE_NOTICE)
#ifdef PLIB_PORTS_ExistsPinChangeNoticePerPort
#define WDRV_INT_SOURCE WDRV_WINC_INT_SOURCE_CN_PORT
#else
#define WDRV_INT_SOURCE INT_SOURCE_CHANGE_NOTICE
#endif
#elif defined(WDRV_WINC_INT_SOURCE)
#define WDRV_INT_SOURCE WDRV_WINC_INT_SOURCE
#elif defined WDRV_WINC_GPIO_SOURCE
static void WDRV_WINC_GPIOCallback(GPIO_PIN pin, uintptr_t context)
{
    WDRV_WINC_ISR(context);
}
#elif defined WDRV_WINC_PIO_SOURCE
static void WDRV_WINC_PIOCallback(PIO_PIN pin, uintptr_t context)
{
    WDRV_WINC_ISR(context);
}
#endif

/****************************************************************************
 * Function:        WDRV_WINC_INTInitialize
 * Summary: Initializes interrupts for the WiFi driver.
 *****************************************************************************/
void WDRV_WINC_INTInitialize(SYS_MODULE_OBJ object, int intSrc)
{
#ifdef WDRV_WINC_EIC_SOURCE
    EIC_CallbackRegister(intSrc, WDRV_WINC_ISR, object);
    EIC_InterruptEnable(intSrc);
#elif defined WDRV_WINC_GPIO_SOURCE
    GPIO_PinInterruptCallbackRegister(intSrc, WDRV_WINC_GPIOCallback, object);
    GPIO_PinInterruptEnable(intSrc);
    GPIO_PinIntEnable(intSrc, GPIO_INTERRUPT_ON_FALLING_EDGE);
#elif defined WDRV_WINC_PIO_SOURCE
    PIO_PinInterruptCallbackRegister(intSrc, WDRV_WINC_PIOCallback, object);
    PIO_PinInterruptEnable(intSrc);
#else
    /* disable the external interrupt */
    SYS_INT_SourceDisable(WDRV_INT_SOURCE);

    /* clear and enable the interrupt */
    SYS_INT_SourceStatusClear(WDRV_INT_SOURCE);

    /* enable the external interrupt */
    SYS_INT_SourceEnable(WDRV_INT_SOURCE);
#endif
}

/****************************************************************************
 * Function:        WDRV_WINC_INTDeinitialize
 * Summary: Deinitializes interrupts for WiFi driver.
 *****************************************************************************/
void WDRV_WINC_INTDeinitialize(int intSrc)
{
#ifdef WDRV_WINC_EIC_SOURCE
    EIC_InterruptDisable(intSrc);
#elif defined WDRV_WINC_GPIO_SOURCE
    GPIO_PinInterruptDisable(intSrc);
#elif defined WDRV_WINC_PIO_SOURCE
    PIO_PinInterruptDisable(intSrc);
#else
    SYS_INT_SourceDisable(WDRV_INT_SOURCE);
#endif
}

//DOM-IGNORE-END
