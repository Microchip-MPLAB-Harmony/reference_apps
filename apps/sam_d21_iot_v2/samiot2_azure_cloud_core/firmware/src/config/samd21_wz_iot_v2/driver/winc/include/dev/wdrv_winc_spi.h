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
/*******************************************************************************
* Copyright (C) 2019-22 Microchip Technology Inc. and its subsidiaries.
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

#ifndef _WDRV_WINC_SPI_H
#define _WDRV_WINC_SPI_H

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
    void WDRV_WINC_SPIOpen(void)

  Summary:
    Opens the SPI object for the WiFi driver.

  Description:
    This function opens the SPI object for the WiFi driver.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    None.

  Remarks:
    None.
 */

void WDRV_WINC_SPIOpen(void);

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
