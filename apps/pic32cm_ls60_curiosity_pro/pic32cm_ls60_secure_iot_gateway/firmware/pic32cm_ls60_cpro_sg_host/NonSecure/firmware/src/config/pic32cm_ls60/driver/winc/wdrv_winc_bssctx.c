/*******************************************************************************
  WINC Driver BSS Context Implementation

  File Name:
    wdrv_winc_bssctx.c

  Summary:
    WINC wireless driver BSS context implementation.

  Description:
    This interface manages the BSS contexts which 'wrap' the state
      associated with BSSs.
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
//DOM-IGNORE-END

#include <stdint.h>
#include <string.h>

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include "wdrv_winc_common.h"
#include "wdrv_winc_bssctx.h"

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver BSS Context Implementation
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_BSSCtxIsValid
    (
        const WDRV_WINC_BSS_CONTEXT *const pBSSCtx,
        bool ssidValid
    )

  Summary:
    Tests if a BSS context is valid.

  Description:
    Tests the elements of the BSS context to judge if their values are legal.

  Precondition:
    None.

  Parameters:
    pBSSCtx   - Pointer to a BSS context.
    ssidValid - Flag indicating if the SSID within the context must be valid.

  Returns:
    true or false indicating if context is valid.

  Remarks:
    See wdrv_winc_bssctx.h for usage information.

*/

bool WDRV_WINC_BSSCtxIsValid
(
    const WDRV_WINC_BSS_CONTEXT *const pBSSCtx,
    bool ssidValid
)
{
    /* Ensure BSS context is valid. */
    if (NULL == pBSSCtx)
    {
        return false;
    }

    /* Ensure the channels are valid. */
    if ((pBSSCtx->channel > WDRV_WINC_CID_2_4G_CH14) && (pBSSCtx->channel != WDRV_WINC_ALL_CHANNELS))
    {
        return false;
    }

    /* Ensure the SSID length is valid. */
    if (pBSSCtx->ssid.length > WDRV_WINC_MAX_SSID_LEN)
    {
        return false;
    }

#ifdef WDRV_WINC_DEVICE_EXT_CONNECT_PARAMS
    /* Ensure the BSSID is non-zero, if valid. */
    if (true == pBSSCtx->bssid.valid)
    {
        int i;
        uint8_t macAddrChk;

        macAddrChk = 0;
        for (i=0; i<WDRV_WINC_MAC_ADDR_LEN; i++)
        {
            macAddrChk |= pBSSCtx->bssid.addr[i];
        }

        if (0 == macAddrChk)
        {
            return false;
        }
    }
#endif

    if (true == ssidValid)
    {
        /* If requested, check the SSID is present. */
        if (0 == pBSSCtx->ssid.length)
        {
            return false;
        }
    }

    return true;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_BSSCtxSetDefaults
    (
        WDRV_WINC_BSS_CONTEXT *const pBSSCtx
    )

  Summary:
    Configures a BSS context into a default legal state.

  Description:
    Ensures that each element of the structure is configured into a legal state.

  Remarks:
    See wdrv_winc_bssctx.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_BSSCtxSetDefaults
(
    WDRV_WINC_BSS_CONTEXT *const pBSSCtx
)
{
    /* Ensure BSS context is valid. */
    if (NULL == pBSSCtx)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

#ifdef WDRV_WINC_DEVICE_EXT_CONNECT_PARAMS
    memset(pBSSCtx->bssid.addr, 0, WDRV_WINC_MAC_ADDR_LEN);
    pBSSCtx->bssid.valid = false;
#endif

    /* Set context to have no SSID, all channels and not cloaked. */
    pBSSCtx->ssid.length = 0;
    pBSSCtx->channel     = WDRV_WINC_CID_ANY;
    pBSSCtx->cloaked     = false;

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_BSSCtxSetSSID
    (
        WDRV_WINC_BSS_CONTEXT *const pBSSCtx,
        uint8_t *const pSSID,
        uint8_t ssidLength
    )

  Summary:
    Configures the SSID of the BSS context.

  Description:
    The SSID string and length provided the SSID is copied into the BSS
      context.

  Remarks:
    See wdrv_winc_bssctx.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_BSSCtxSetSSID
(
    WDRV_WINC_BSS_CONTEXT *const pBSSCtx,
    uint8_t *const pSSID,
    uint8_t ssidLength
)
{
    /* Ensure BSS context and SSID buffer and length are valid. */
    if ((NULL == pBSSCtx) || (NULL == pSSID) || (ssidLength > WDRV_WINC_MAX_SSID_LEN))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Copy the SSID ensure unused space is zeroed. */
    memset(&pBSSCtx->ssid.name, 0, WDRV_WINC_MAX_SSID_LEN);
    memcpy(&pBSSCtx->ssid.name, pSSID, ssidLength);
    pBSSCtx->ssid.length = ssidLength;

    /* Validate context. */
    if (false == WDRV_WINC_BSSCtxIsValid(pBSSCtx, false))
    {
        return WDRV_WINC_STATUS_INVALID_CONTEXT;
    }

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_BSSCtxSetBSSID
    (
        WDRV_WINC_BSS_CONTEXT *const pBSSCtx,
        uint8_t *const pBSSID
    )

  Summary:
    Configures the BSSID of the BSS context.

  Description:
    The BSSID string is copied into the BSS context.

  Remarks:
    See wdrv_winc_bssctx.h for usage information.

*/

#ifdef WDRV_WINC_DEVICE_EXT_CONNECT_PARAMS
WDRV_WINC_STATUS WDRV_WINC_BSSCtxSetBSSID
(
    WDRV_WINC_BSS_CONTEXT *const pBSSCtx,
    uint8_t *const pBSSID
)
{
    /* Ensure BSS context is valid. */
    if (NULL == pBSSCtx)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    if (NULL != pBSSID)
    {
        /* Copy the BSSID. */
        memcpy(&pBSSCtx->bssid, pBSSID, WDRV_WINC_MAC_ADDR_LEN);
        pBSSCtx->bssid.valid = true;
    }
    else
    {
        memset(&pBSSCtx->bssid, 0, WDRV_WINC_MAC_ADDR_LEN);
        pBSSCtx->bssid.valid = false;
    }

    /* Validate context. */
    if (false == WDRV_WINC_BSSCtxIsValid(pBSSCtx, false))
    {
        return WDRV_WINC_STATUS_INVALID_CONTEXT;
    }

    return WDRV_WINC_STATUS_OK;
}
#endif

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_BSSCtxSetChannel
    (
        WDRV_WINC_BSS_CONTEXT *const pBSSCtx,
        WDRV_WINC_CHANNEL_ID channel
    )

  Summary:
    Configures the channel of the BSS context.

  Description:
    The supplied channel value is copied into the BSS context.

  Remarks:
    See wdrv_winc_bssctx.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_BSSCtxSetChannel
(
    WDRV_WINC_BSS_CONTEXT *const pBSSCtx,
    WDRV_WINC_CHANNEL_ID channel
)
{
    /* Ensure BSS context and channels are valid. */
    if ((NULL == pBSSCtx) || ((channel > WDRV_WINC_CID_2_4G_CH14) && (channel != WDRV_WINC_ALL_CHANNELS)))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Copy channel. */
    pBSSCtx->channel = channel;

    /* Validate context. */
    if (false == WDRV_WINC_BSSCtxIsValid(pBSSCtx, false))
    {
        return WDRV_WINC_STATUS_INVALID_CONTEXT;
    }

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_BSSCtxSetSSIDVisibility
    (
        WDRV_WINC_BSS_CONTEXT *const pBSSCtx,
        bool visible
    )

  Summary:
    Configures the visibility of the BSS context.

  Description:
    Specific to Soft-AP mode this flag defines if the BSS context will create a
      visible presence on air.

  Remarks:
    See wdrv_winc_bssctx.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_BSSCtxSetSSIDVisibility
(
    WDRV_WINC_BSS_CONTEXT *const pBSSCtx,
    bool visible
)
{
    /* Ensure BSS context is valid. */
    if (NULL == pBSSCtx)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Set cloaked state. */
    pBSSCtx->cloaked = visible ? false : true;

    /* Validate context. */
    if (false == WDRV_WINC_BSSCtxIsValid(pBSSCtx, false))
    {
        return WDRV_WINC_STATUS_INVALID_CONTEXT;
    }

    return WDRV_WINC_STATUS_OK;
}
