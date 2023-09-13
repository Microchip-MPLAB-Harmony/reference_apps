/*******************************************************************************
  WINC Wireless Driver GPIO Interface

  File Name:
    wdrv_winc_gpio.c

  Summary:
    GPIO interface for WINC wireless driver.

  Description:
    GPIO interface for WINC wireless driver.
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
#include <stdint.h>
#include "configuration.h"
#include "definitions.h"

/****************************************************************************
 * Function:        WDRV_WINC_GPIOResetAssert
 * Summary: Reset the WINC by asserting the reset line.
 *****************************************************************************/
void WDRV_WINC_GPIOResetAssert(void)
{
    WDRV_WINC_RESETN_Clear();
}

/****************************************************************************
 * Function:        WDRV_WINC_GPIOResetDeassert
 * Summary: Deassert the reset line.
 *****************************************************************************/
void WDRV_WINC_GPIOResetDeassert(void)
{
    WDRV_WINC_RESETN_Set();
}

/****************************************************************************
 * Function:        WDRV_WINC_GPIOChipEnableAssert
 * Summary: Asserts the chip enable list.
 *****************************************************************************/
void WDRV_WINC_GPIOChipEnableAssert(void)
{
    WDRV_WINC_CHIP_EN_Set();
}

/****************************************************************************
 * Function:        WDRV_WINC_GPIOChipEnableDeassert
 * Summary: Deassert the chip enable line.
 *****************************************************************************/
void WDRV_WINC_GPIOChipEnableDeassert(void)
{
    WDRV_WINC_CHIP_EN_Clear();
}

//DOM-IGNORE-END
