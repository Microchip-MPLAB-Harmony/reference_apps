/*******************************************************************************
  Company:
    Microchip Technology Inc.

  File Name:
    wdrv_winc_spi.h

  Summary:
    WINC wireless driver SPI APIs.

  Description:
    Provides interface for using the SPI bus.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
Copyright (C) 2019-22, Microchip Technology Inc., and its subsidiaries. All rights reserved.

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

#ifndef _WDRV_WINC_SPI_H
#define _WDRV_WINC_SPI_H

#include "system/ports/sys_ports.h"

// *****************************************************************************
/*  SPI Speed Modes

  Summary:
    A list of SPI speed modes.

  Description:
    A list of values for high and low SPI speed modes.

  Remarks:
    None.

*/

typedef enum
{
    /* Low speed SPI mode. */
    WDRV_WINC_SPI_SPEED_MODE_LOW,

    /* High speed SPI mode. */
    WDRV_WINC_SPI_SPEED_MODE_HIGH
} WDRV_WINC_SPI_SPEED_MODE;

// *****************************************************************************
/*  SPI Configuration Structure

  Summary:
    Structure containing SPI configuration parameters.

  Description:
    Structure containing SPI configuration parameters.

  Remarks:
    None.

*/

typedef struct
{
    /* SPI driver index. */
    SYS_MODULE_INDEX drvIndex;

    /* SPI baud rate. */
    uint32_t baudRateInHz;

    /* Chip select pin, or SYS_PORT_PIN_NONE. */
    SYS_PORT_PIN chipSelect;
} WDRV_WINC_SPI_CFG;

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_SPISend(void* pTransmitData, size_t txSize)

  Summary:
    Sends data out to the module through the SPI bus.

  Description:
    This function sends data out to the module through the SPI bus.

  Precondition:
    WDRV_WINC_SPIInitialize must have been called.

  Parameters:
    pTransmitData - buffer pointer of output data
    txSize        - the output data size

  Returns:
    true  - Indicates success
    false - Indicates failure

  Remarks:
    None.
 */

bool WDRV_WINC_SPISend(void* pTransmitData, size_t txSize);

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_SPIReceive(void* pReceiveData, size_t rxSize)

  Summary:
    Receives data from the module through the SPI bus.

  Description:
    This function receives data from the module through the SPI bus.

  Precondition:
    WDRV_WINC_SPIInitialize must have been called.

  Parameters:
    pReceiveData - buffer pointer of input data
    rxSize       - the input data size

  Returns:
    true  - Indicates success
    false - Indicates failure

  Remarks:
    None.
 */

bool WDRV_WINC_SPIReceive(void* pReceiveData, size_t rxSize);

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_SPIOpen(void)

  Summary:
    Opens the SPI object for the WiFi driver.

  Description:
    This function opens the SPI object for the WiFi driver.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    true of false indicating success of operation.

  Remarks:
    None.
 */

bool WDRV_WINC_SPIOpen(void);

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_SPIInitialize(const WDRV_WINC_SPI_CFG *const pInitData)

  Summary:
    Initializes the SPI object for the WiFi driver.

  Description:
    This function initializes the SPI object for the WiFi driver.

  Precondition:
    None.

  Parameters:
    pInitData - Pointer to initialization data

  Returns:
    None.

  Remarks:
    None.
 */

void WDRV_WINC_SPIInitialize(const WDRV_WINC_SPI_CFG *const pInitData);

//*******************************************************************************
/*
  Function:
    void WDRV_WINC_SPIDeinitialize(void)

  Summary:
    Deinitializes the SPI object for the WiFi driver.

  Description:
    This function deinitializes the SPI object for the WiFi driver.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    None.

  Remarks:
    None.
 */

void WDRV_WINC_SPIDeinitialize(void);

#endif /* _WDRV_WINC_SPI_H */
