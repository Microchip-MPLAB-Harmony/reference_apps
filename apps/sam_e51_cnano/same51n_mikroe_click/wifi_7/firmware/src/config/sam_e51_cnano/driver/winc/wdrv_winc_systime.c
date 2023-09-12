/*******************************************************************************
  WINC Wireless Driver

  File Name:
    wdrv_winc_systime.c

  Summary:
    WINC wireless driver.

  Description:
    WINC wireless driver.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
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

#include <stdint.h>
#include <string.h>
#include <time.h>

#include "wdrv_winc.h"
#include "wdrv_winc_common.h"
#include "wdrv_winc_systime.h"

/****************************************************************************
 * Function:        WDRV_WINC_LocalTimeToUTC
 * Summary: Convert local system time to UTC time.
 *****************************************************************************/
uint32_t WDRV_WINC_LocalTimeToUTC(const tstrSystemTime *const pSysTime)
{
    time_t timeUTC;
    struct tm t;

    if (NULL == pSysTime)
    {
        return 0;
    }

    if ((pSysTime->u8Second > 59) ||
        (pSysTime->u8Minute > 59) ||
        (pSysTime->u8Hour > 23)   ||
        (pSysTime->u8Day > 31)    ||
        ((0 == pSysTime->u8Month) || (pSysTime->u8Month > 12)) ||
        (pSysTime->u16Year < 1900))
    {
        return 0;
    }
    
    memset(&t, 0, sizeof(struct tm));

    t.tm_sec  = pSysTime->u8Second;
    t.tm_min  = pSysTime->u8Minute;
    t.tm_hour = pSysTime->u8Hour;
    t.tm_mday = pSysTime->u8Day;
    t.tm_mon  = pSysTime->u8Month-1;
    t.tm_year = pSysTime->u16Year-1900;

    timeUTC = mktime(&t);

    if (-1 == timeUTC)
    {
        return 0;
    }

    return (uint32_t)timeUTC;
}

/****************************************************************************
 * Function:        WDRV_WINC_UTCToLocalTime
 * Summary: Convert UTC time to local system time.
 *****************************************************************************/
bool WDRV_WINC_UTCToLocalTime(uint32_t timeUTC, tstrSystemTime *const pSysTime)
{
    struct tm *ptm;
    time_t utc;

    if (NULL == pSysTime)
    {
        return false;
    }

    utc = timeUTC;

    ptm = gmtime(&utc);

    pSysTime->u8Second = ptm->tm_sec;
    pSysTime->u8Minute = ptm->tm_min;
    pSysTime->u8Hour   = ptm->tm_hour;
    pSysTime->u8Day    = ptm->tm_mday;
    pSysTime->u8Month  = ptm->tm_mon+1;
    pSysTime->u16Year  = ptm->tm_year+1900;

    return true;
}

/****************************************************************************
 * Function:        WDRV_WINC_SystemTimeSNTPClientEnable
 * Summary: Enable the SNTP client to set system time.
 *****************************************************************************/
WDRV_WINC_STATUS WDRV_WINC_SystemTimeSNTPClientEnable(DRV_HANDLE handle,
                                const char *pServerName, bool allowDHCPOverride)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const )handle;
#if defined(WDRV_WINC_DEVICE_CONF_NTP_SERVER) && defined(WDRV_WINC_NETWORK_MODE_SOCKET)
    tenuSNTPUseDHCP useDHCP;
#endif

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

#ifdef WDRV_WINC_NETWORK_MODE_SOCKET
    if (M2M_SUCCESS != m2m_wifi_enable_sntp(1))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

#ifdef WDRV_WINC_DEVICE_CONF_NTP_SERVER
    if (true == allowDHCPOverride)
    {
        useDHCP = SNTP_ENABLE_DHCP;
    }
    else
    {
        useDHCP = SNTP_DISABLE_DHCP;
    }

    if (NULL != pServerName)
    {
        if (M2M_SUCCESS != m2m_wifi_configure_sntp((uint8_t*)pServerName,
                                                strlen(pServerName), useDHCP))
        {
            return WDRV_WINC_STATUS_REQUEST_ERROR;
        }
    }
    else
    {
        uint8_t noNTPSever[1];

        if (M2M_SUCCESS != m2m_wifi_configure_sntp(noNTPSever, 0, useDHCP))
        {
            return WDRV_WINC_STATUS_REQUEST_ERROR;
        }
    }
#endif

    return WDRV_WINC_STATUS_OK;
#else
    return WDRV_WINC_STATUS_REQUEST_ERROR;
#endif
}

/****************************************************************************
 * Function:        WDRV_WINC_SystemTimeSNTPClientDisable
 * Summary: Disable the SNTP client.
 *****************************************************************************/
WDRV_WINC_STATUS WDRV_WINC_SystemTimeSNTPClientDisable(DRV_HANDLE handle)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const )handle;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

#ifdef WDRV_WINC_NETWORK_MODE_SOCKET
    if (M2M_SUCCESS != m2m_wifi_enable_sntp(0))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
#else
    return WDRV_WINC_STATUS_REQUEST_ERROR;
#endif
}

/****************************************************************************
 * Function:        WDRV_WINC_SystemTimeSetCurrent
 * Summary: Sets the current system time on the WINC.
 *****************************************************************************/
WDRV_WINC_STATUS WDRV_WINC_SystemTimeSetCurrent(DRV_HANDLE handle, uint32_t curTime)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const )handle;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    if (M2M_SUCCESS != m2m_wifi_set_system_time(curTime + 2208988800UL))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
}

/****************************************************************************
 * Function:        WDRV_WINC_SystemTimeGetCurrent
 * Summary: Requests the current system time from the WINC.
 *****************************************************************************/
WDRV_WINC_STATUS WDRV_WINC_SystemTimeGetCurrent(DRV_HANDLE handle,
                            const WDRV_WINC_SYSTIME_CURRENT_CALLBACK pfGetCurrentCallback)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const )handle;

    /* Ensure the driver handle is valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    pDcpt->pCtrl->pfSystemTimeGetCurrentCB = pfGetCurrentCallback;

    if (M2M_SUCCESS != m2m_wifi_get_system_time())
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
}

//DOM-IGNORE-END
