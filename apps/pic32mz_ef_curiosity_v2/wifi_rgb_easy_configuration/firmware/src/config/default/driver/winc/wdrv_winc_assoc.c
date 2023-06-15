/*******************************************************************************
  WINC Driver Association Implementation

  File Name:
    wdrv_winc_assoc.c

  Summary:
    WINC wireless driver association implementation.

  Description:
    This interface provides information about the current association with a
    peer device.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <string.h>

#include "wdrv_winc.h"
#include "wdrv_winc_common.h"
#include "wdrv_winc_assoc.h"

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver Association Implementation
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_AssocSSIDGet
    (
        DRV_HANDLE handle,
        WDRV_WINC_SSID *const pSSID,
        WDRV_WINC_ASSOC_CALLBACK const pfAssociationInfoCB
    )

  Summary:
    Retrieve the current association SSID.

  Description:
    Attempts to retrieve the SSID of the current association.

  Remarks:
    See wdrv_winc_assoc.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_AssocSSIDGet
(
    WDRV_WINC_ASSOC_HANDLE assocHandle,
    WDRV_WINC_SSID *const pSSID,
    WDRV_WINC_ASSOC_CALLBACK const pfAssociationInfoCB
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)assocHandle;

    /* Ensure the driver handle is valid. */
    if ((WDRV_WINC_ASSOC_HANDLE_INVALID == assocHandle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    /* Store the callback for use later. */
    pDcpt->pCtrl->pfAssociationInfoCB = pfAssociationInfoCB;

    if ((true == pDcpt->pCtrl->assocInfoValid) && (NULL != pSSID))
    {
        /* If association information store in driver and user application
           supplied a buffer, copy the SSID to the buffer. */

        memcpy(pSSID, &pDcpt->pCtrl->assocSSID, sizeof(WDRV_WINC_SSID));

        return WDRV_WINC_STATUS_OK;
    }
    else if (true == pDcpt->pCtrl->isConnected)
    {
        /* If the WINC is currently connected and either the association
           information isn't currently cached or the user application didn't
           supply a buffer, request new information from the WINC device. */

        if (M2M_SUCCESS != m2m_wifi_get_connection_info())
        {
            return WDRV_WINC_STATUS_REQUEST_ERROR;
        }

        /* Request was successful so indicate the user application needs to
           retry request, or rely on callback for information. */

        return WDRV_WINC_STATUS_RETRY_REQUEST;
    }
    else
    {
        /* No local cached association information and not connected. */
    }

    return WDRV_WINC_STATUS_REQUEST_ERROR;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_AssocPeerAddressGet
    (
        WDRV_WINC_ASSOC_HANDLE assocHandle,
        WDRV_WINC_NETWORK_ADDRESS *const pPeerAddress,
        WDRV_WINC_ASSOC_CALLBACK const pfAssociationInfoCB
    )

  Summary:
    Retrieve the current association peer device network address.

  Description:
    Attempts to retrieve the network address of the peer device in the
      current association.

  Remarks:
    See wdrv_winc_assoc.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_AssocPeerAddressGet
(
    WDRV_WINC_ASSOC_HANDLE assocHandle,
    WDRV_WINC_MAC_ADDR *const pPeerAddress,
    WDRV_WINC_ASSOC_CALLBACK const pfAssociationInfoCB
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)assocHandle;

    /* Ensure the driver handle is valid. */
    if ((WDRV_WINC_ASSOC_HANDLE_INVALID == assocHandle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    /* Store the callback for use later. */
    pDcpt->pCtrl->pfAssociationInfoCB = pfAssociationInfoCB;

    if ((true == pDcpt->pCtrl->assocInfoValid) && (NULL != pPeerAddress))
    {
        /* If association information store in driver and user application
           supplied a buffer, copy the peer address to the buffer. */

        memcpy(pPeerAddress, &pDcpt->pCtrl->assocPeerAddress.macAddress, sizeof(WDRV_WINC_MAC_ADDR));

        return WDRV_WINC_STATUS_OK;
    }
    else if (true == pDcpt->pCtrl->isConnected)
    {
        /* If the WINC is currently connected and either the association
           information isn't currently cached or the user application didn't
           supply a buffer, request new information from the WINC device. */

        if (M2M_SUCCESS != m2m_wifi_get_connection_info())
        {
            return WDRV_WINC_STATUS_REQUEST_ERROR;
        }

        /* Request was successful so indicate the user application needs to
           retry request, or rely on callback for information. */

        return WDRV_WINC_STATUS_RETRY_REQUEST;
    }
    else
    {
        /* No local cached association information and not connected. */
    }

    return WDRV_WINC_STATUS_REQUEST_ERROR;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_AssocAuthTypeGet
    (
        DRV_HANDLE handle,
        WDRV_WINC_AUTH_TYPE *const pAuthType,
        WDRV_WINC_ASSOC_CALLBACK const pfAssociationInfoCB
    )

  Summary:
    Retrieve the current association authentication type.

  Description:
    Attempts to retrieve the authentication type of the current association.

  Remarks:
    See wdrv_winc_assoc.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_AssocAuthTypeGet
(
    WDRV_WINC_ASSOC_HANDLE assocHandle,
    WDRV_WINC_AUTH_TYPE *const pAuthType,
    WDRV_WINC_ASSOC_CALLBACK const pfAssociationInfoCB
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)assocHandle;

    /* Ensure the driver handle is valid. */
    if ((WDRV_WINC_ASSOC_HANDLE_INVALID == assocHandle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    /* Store the callback for use later. */
    pDcpt->pCtrl->pfAssociationInfoCB = pfAssociationInfoCB;

    if ((true == pDcpt->pCtrl->assocInfoValid) && (NULL != pAuthType))
    {
        /* If association information store in driver and user application
           supplied a buffer, copy the authentication type to the buffer. */

        *pAuthType = pDcpt->pCtrl->assocAuthType;

        return WDRV_WINC_STATUS_OK;
    }
    else if (true == pDcpt->pCtrl->isConnected)
    {
        /* If the WINC is currently connected and either the association
           information isn't currently cached or the user application didn't
           supply a buffer, request new information from the WINC device. */

        if (M2M_SUCCESS != m2m_wifi_get_connection_info())
        {
            return WDRV_WINC_STATUS_REQUEST_ERROR;
        }

        /* Request was successful so indicate the user application needs to
           retry request, or rely on callback for information. */

        return WDRV_WINC_STATUS_RETRY_REQUEST;
    }
    else
    {
        /* No local cached association information and not connected. */
    }

    return WDRV_WINC_STATUS_REQUEST_ERROR;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_AssocRSSIGet
    (
        DRV_HANDLE handle,
        int8_t *const pRSSI,
        WDRV_WINC_ASSOC_RSSI_CALLBACK const pfAssociationRSSICB
    )

  Summary:
    Retrieve the current association RSSI.

  Description:
    Attempts to retrieve the RSSI of the current association.

  Remarks:
    See wdrv_winc_assoc.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_AssocRSSIGet
(
    WDRV_WINC_ASSOC_HANDLE assocHandle,
    int8_t *const pRSSI,
    WDRV_WINC_ASSOC_RSSI_CALLBACK const pfAssociationRSSICB
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)assocHandle;

    /* Ensure the driver handle is valid. */
    if ((WDRV_WINC_ASSOC_HANDLE_INVALID == assocHandle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    /* Store the callback for use later. */
    pDcpt->pCtrl->pfAssociationRSSICB = pfAssociationRSSICB;

    if (true == pDcpt->pCtrl->isConnected)
    {
        /* WINC is currently connected. */

        if (NULL == pfAssociationRSSICB)
        {
            /* No callback has been provided. */

            if ((0 != pDcpt->pCtrl->rssi) && (NULL != pRSSI))
            {
                /* A current RSSI value exists and the user application provided
                   a buffer to receive it, copy the information. */

                *pRSSI = pDcpt->pCtrl->rssi;

                return WDRV_WINC_STATUS_OK;
            }
        }
        else
        {
            /* A callback has been provided, request the current RSSI from the
               WINC device. */

            if (M2M_SUCCESS != m2m_wifi_req_curr_rssi())
            {
                return WDRV_WINC_STATUS_REQUEST_ERROR;
            }

            /* Request was successful so indicate the user application needs to
               retry request, or rely on callback for information. */

            return WDRV_WINC_STATUS_RETRY_REQUEST;
        }
    }
    else
    {
        /* WINC is currently disconnected. */
    }

    return WDRV_WINC_STATUS_REQUEST_ERROR;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_AssocDisconnect(WDRV_WINC_ASSOC_HANDLE assocHandle)

  Summary:
    Disconnects an association.

  Description:
    Disconnects the STA associated with AP referred by the input association handle.

  Remarks:
    See wdrv_winc_softap.h for usage information.
*/

WDRV_WINC_STATUS WDRV_WINC_AssocDisconnect(WDRV_WINC_ASSOC_HANDLE assocHandle)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const)assocHandle;

    if ((WDRV_WINC_ASSOC_HANDLE_INVALID == assocHandle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl))
    {
        return WDRV_WINC_STATUS_NOT_CONNECTED;
    }

    /* Check operation mode is Soft-AP or STA. */
    if (true == pDcpt->pCtrl->isAP)
    {
        return WDRV_WINC_STATUS_OPERATION_NOT_SUPPORTED;
    }
    else
    {
        return WDRV_WINC_BSSDisconnect((DRV_HANDLE)pDcpt);
    }

    return WDRV_WINC_STATUS_OK;
}
