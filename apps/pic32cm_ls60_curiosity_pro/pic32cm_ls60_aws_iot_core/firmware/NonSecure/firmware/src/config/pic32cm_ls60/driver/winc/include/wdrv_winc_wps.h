/*******************************************************************************
  WINC Driver WPS Header File

  Company:
    Microchip Technology Inc.

  File Name:
    wdrv_winc_wps.h

  Summary:
    WINC wireless driver WPS header file.

  Description:
    Provides an interface use WPS for BSS discovery.
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

#ifndef _WDRV_WINC_WPS_H
#define _WDRV_WINC_WPS_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>

#include "wdrv_winc_common.h"

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver WPS Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/*  WPS Discovery Callback

  Summary:
    Callback to report WPS discovery results.

  Description:
    Callback to report WPS discovery results.

  Remarks:
    None.
*/

typedef void (*WDRV_WINC_WPS_DISC_CALLBACK)
(
    DRV_HANDLE handle,
    WDRV_WINC_BSS_CONTEXT *pBSSCtx,
    WDRV_WINC_AUTH_CONTEXT *pAuthCtx
);

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver WPS Routines
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_WPSEnrolleeDiscoveryStartPIN
    (
        DRV_HANDLE handle,
        uint32_t pin,
        const WDRV_WINC_WPS_DISC_CALLBACK pfWPSDiscoveryCallback
    )

  Summary:
    Start WPS discovery (PIN).

  Description:
    Starts the WPS discovery as an enrollee using the PIN method.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle                 - Client handle obtained by a call to WDRV_WINC_Open.
    pin                    - WPS PIN number.
    pfWPSDiscoveryCallback - Callback function to return discovery results to.

  Returns:
    WDRV_WINC_STATUS_OK            - Discovery request accepted.
    WDRV_WINC_STATUS_NOT_OPEN      - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG   - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR - The request to the WINC was rejected.

  Remarks:
    The pin number is an 8-digit number where the least significant digit is
      a checksum as defined by WPS.

*/

WDRV_WINC_STATUS WDRV_WINC_WPSEnrolleeDiscoveryStartPIN
(
    DRV_HANDLE handle,
    uint32_t pin,
    const WDRV_WINC_WPS_DISC_CALLBACK pfWPSDiscoveryCallback
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_WPSEnrolleeDiscoveryStartPBC
    (
        DRV_HANDLE handle,
        const WDRV_WINC_WPS_DISC_CALLBACK pfWPSDiscoveryCallback
    )

  Summary:
    Start WPS discovery (Push Button).

  Description:
    Starts the WPS discovery as an enrollee using the Push Button method.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle                 - Client handle obtained by a call to WDRV_WINC_Open.
    pfWPSDiscoveryCallback - Callback function to return discovery results to.

  Returns:
    WDRV_WINC_STATUS_OK            - Discovery request accepted.
    WDRV_WINC_STATUS_NOT_OPEN      - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG   - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR - The request to the WINC was rejected.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_WPSEnrolleeDiscoveryStartPBC
(
    DRV_HANDLE handle,
    const WDRV_WINC_WPS_DISC_CALLBACK pfWPSDiscoveryCallback
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_WPSEnrolleeDiscoveryStop(DRV_HANDLE handle)

  Summary:
    Stop WPS discovery.

  Description:
    Stops the WPS discovery if it was started.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle                 - Client handle obtained by a call to WDRV_WINC_Open.

  Returns:
    WDRV_WINC_STATUS_OK            - Discovery request accepted.
    WDRV_WINC_STATUS_NOT_OPEN      - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG   - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR - The request to the WINC was rejected.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_WPSEnrolleeDiscoveryStop(DRV_HANDLE handle);

#endif /* _WDRV_WINC_WPS_H */
