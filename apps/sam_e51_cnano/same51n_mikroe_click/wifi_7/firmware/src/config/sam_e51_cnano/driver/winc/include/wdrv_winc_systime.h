/*******************************************************************************
  WINC Driver Systime Header File

  Company:
    Microchip Technology Inc.

  File Name:
    wdrv_winc_systime.h

  Summary:
    WINC wireless driver systime header file.

  Description:
    Provides an interface to configure the system time on the WINC.
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

#ifndef _WDRV_WINC_SYSTIME_H
#define _WDRV_WINC_SYSTIME_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>

#include "wdrv_winc_common.h"

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver Systime Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/*  System Time Callback

  Summary:
    Callback returning the system time.

  Description:
    Callback returning the system time. The time is returned as UTC seconds
    since 01/01/1970.

  Remarks:
    None.
*/

typedef void (*WDRV_WINC_SYSTIME_CURRENT_CALLBACK)
(
    DRV_HANDLE handle,
    uint32_t timeUTC
);

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver Systime Routines
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    uint32_t WDRV_WINC_LocalTimeToUTC(const tstrSystemTime *const pSysTime)

  Summary:
    Convert local system time to UTC time.

  Description:
    Converts the local system time structure into a more convenient UTC time.

  Precondition:
    None.

  Parameters:
    pSysTime - Pointer to system time structure.

  Returns:
    UTC time or zero if an error occurs.

  Remarks:
    None.

*/

uint32_t WDRV_WINC_LocalTimeToUTC(const tstrSystemTime *const pSysTime);

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_UTCToLocalTime(uint32_t timeUTC, tstrSystemTime *const pSysTime)

  Summary:
    Convert UTC time to local system time.

  Description:
    Converts UTC time into the local system time structure format.

  Precondition:
    None.

  Parameters:
    timeUTC  - UTC time to convert.
    pSysTime - Pointer to system time structure to write.

  Returns:
    true - Conversion performed.
    false - An error occurred.

  Remarks:
    None.

*/

bool WDRV_WINC_UTCToLocalTime(uint32_t timeUTC, tstrSystemTime *const pSysTime);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_SystemTimeSNTPClientEnable
    (
        DRV_HANDLE handle,
        const char *pServerName,
        bool allowDHCPOverride
    );

  Summary:
    Enable the SNTP client to set system time.

  Description:
    Enables the SNTP client used to set the system time.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle            - Client handle obtained by a call to WDRV_WINC_Open.
    pServerName       - Pointer to the NTP server name
    allowDHCPOverride - Flag indicating if the DHCP setting for NTP server
                          should override the system server name.

  Returns:
    WDRV_WINC_STATUS_OK            - The request has been accepted.
    WDRV_WINC_STATUS_NOT_OPEN      - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG   - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR - The request to the WINC was rejected.

  Remarks:
    pServerName may be NULL to indicate no specified NTP server name will
    be used. If allowDHCPOverride is also true then the server name can still
    be set via DHCP.

    If the first character is an asterisk (*) then it will be treated as a
    server pool, where the asterisk will be replaced with an incrementing value
    from 0 to 3 each time a server fails (example: *.pool.ntp.org)

    Configurable server name and DHCP override control at not available on
    WINC3400 and WINC1500 pre 19.6.0.

*/

WDRV_WINC_STATUS WDRV_WINC_SystemTimeSNTPClientEnable
(
    DRV_HANDLE handle,
    const char *pServerName,
    bool allowDHCPOverride
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_SystemTimeSNTPClientDisable(DRV_HANDLE handle);

  Summary:
    Disable the SNTP client.

  Description:
    Disables the SNTP client used to set the system time.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle  - Client handle obtained by a call to WDRV_WINC_Open.

  Returns:
    WDRV_WINC_STATUS_OK            - The request has been accepted.
    WDRV_WINC_STATUS_NOT_OPEN      - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG   - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR - The request to the WINC was rejected.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_SystemTimeSNTPClientDisable(DRV_HANDLE handle);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_SystemTimeSetCurrent
    (
        DRV_HANDLE handle,
        uint32_t curTime
    )

  Summary:
    Sets the current system time on the WINC.

  Description:
    Configures the system time to the UTC value specified.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle  - Client handle obtained by a call to WDRV_WINC_Open.
    curTime - The current UTC time (epoch 01/01/1970).

  Returns:
    WDRV_WINC_STATUS_OK            - The request has been accepted.
    WDRV_WINC_STATUS_NOT_OPEN      - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG   - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR - The request to the WINC was rejected.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_SystemTimeSetCurrent
(
    DRV_HANDLE handle,
    uint32_t curTime
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_SystemTimeGetCurrent
    (
        DRV_HANDLE handle,
        const WDRV_WINC_SYSTIME_CURRENT_CALLBACK pfGetCurrentCallback
    )

  Summary:
    Requests the current system time from the WINC.

  Description:
    Requests the current system time which is returned via the callback provided.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle               - Client handle obtained by a call to WDRV_WINC_Open.
    pfGetCurrentCallback - Function pointer to callback.

  Returns:
    WDRV_WINC_STATUS_OK            - The request has been accepted.
    WDRV_WINC_STATUS_NOT_OPEN      - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG   - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR - The request to the WINC was rejected.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_SystemTimeGetCurrent
(
    DRV_HANDLE handle,
    const WDRV_WINC_SYSTIME_CURRENT_CALLBACK pfGetCurrentCallback
);

#endif /* _WDRV_WINC_SYSTIME_H */
