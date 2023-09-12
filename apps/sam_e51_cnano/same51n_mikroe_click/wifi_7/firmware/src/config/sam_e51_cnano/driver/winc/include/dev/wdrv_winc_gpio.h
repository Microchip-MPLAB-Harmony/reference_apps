/*******************************************************************************
  Company:
    Microchip Technology Inc.

  File Name:
    wdrv_winc_gpio.h

  Summary:
    WINC wireless driver GPIO APIs.

  Description:
    Provides an interface to control GPIOs used to control the WINC.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

#ifndef _WDRV_WINC_GPIO_H
#define _WDRV_WINC_GPIO_H

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_INTInitialize(SYS_MODULE_OBJ object, int intSrc)

  Summary:
    Initializes interrupts for the WiFi driver.

  Description:
    This function initializes interrupts for the WiFi driver.

  Precondition:
    WDRV_WINC_Initialize must have been called before calling this function.

  Parameters:
    object  - Driver object handle, returned from WDRV_WINC_Initialize
    intSrc  - Interrupt source

  Returns:
    None.

  Remarks:
    None.
 */
void WDRV_WINC_INTInitialize(SYS_MODULE_OBJ object, int intSrc);

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_INTDeinitialize(int intSrc)

  Summary:
    Deinitializes interrupts for WiFi driver.

  Description:
    This function deinitializes interrupts for the WiFi driver.

  Precondition:
    WiFi initialization must be complete.

  Returns:
    intSrc  - Interrupt source

  Remarks:
    None.
 */
void WDRV_WINC_INTDeinitialize(int intSrc);

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_GPIOChipEnableAssert(void)

  Summary:
    Asserts the chip enable list.

  Description:
    Enables the WINC by asserting the chip enable line.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    None.

  Remarks:
    None.
 */
void WDRV_WINC_GPIOChipEnableAssert(void);

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_GPIOChipEnableDeassert(void)

  Summary:
    Deassert the chip enable line.

  Description:
    Disables the WINC by deasserting the chip enable line.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    None.

  Remarks:
    None.
 */
void WDRV_WINC_GPIOChipEnableDeassert(void);

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_GPIOResetAssert(void)

  Summary:
    Assert the reset line.

  Description:
    Reset the WINC by asserting the reset line.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    None.

  Remarks:
    None.
 */
void WDRV_WINC_GPIOResetAssert(void);

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_GPIOResetDeassert(void)

  Summary:
    Deassert the reset line.

  Description:
    Deassert the reset line to take the WINC out of reset.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    None.

  Remarks:
    None.
 */
void WDRV_WINC_GPIOResetDeassert(void);

#endif /* _WDRV_WINC_GPIO_H */
