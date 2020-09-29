/*******************************************************************************
  WINC MAC Driver TCP/IP Interface Implementation

  File Name:
    wdrv_winc_ctrl_itf.c

  Summary:
    Wireless driver PIC32 implementation for WINC support.

  Description:
    Wireless driver PIC32 implementation for WINC support.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include "wdrv_winc_stack_drv.h"

// *****************************************************************************
// *****************************************************************************
// Section: WINC MAC Driver Interface Implementation
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MACBSSCtxGet
    (
        DRV_HANDLE handle,
        WDRV_WINC_BSS_CONTEXT *pBSSCtx
    )

  Summary:
    Obtain a copy of the BSS context.

  Description:
    Obtain a copy of the current BSS context from within the driver.

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_MACBSSCtxGet
(
    DRV_HANDLE handle,
    WDRV_WINC_BSS_CONTEXT *pBSSCtx
)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)handle;

    /* Ensure the driver handle and user pointer is valid. */
    if ((NULL == pDcpt) || (NULL == pBSSCtx))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    OSAL_SEM_Pend(&pDcpt->bssCtxSemaphore, OSAL_WAIT_FOREVER);
    memcpy(pBSSCtx, &pDcpt->bssCtx, sizeof(WDRV_WINC_BSS_CONTEXT));
    OSAL_SEM_Post(&pDcpt->bssCtxSemaphore);

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MACBSSCtxSet
    (
        DRV_HANDLE handle,
        WDRV_WINC_BSS_CONTEXT *pBSSCtx
    )

  Summary:
    Load a new BSS context into the driver.

  Description:
    A new BSS context should be created and initialized before being loaded into
      the MAC driver.

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_MACBSSCtxSet
(
    DRV_HANDLE handle,
    WDRV_WINC_BSS_CONTEXT *pBSSCtx
)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)handle;

    /* Ensure the driver handle and user pointer is valid. */
    if ((NULL == pDcpt) || (NULL == pBSSCtx))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    OSAL_SEM_Pend(&pDcpt->bssCtxSemaphore, OSAL_WAIT_FOREVER);
    memcpy(&pDcpt->bssCtx, pBSSCtx, sizeof(WDRV_WINC_BSS_CONTEXT));
    OSAL_SEM_Post(&pDcpt->bssCtxSemaphore);

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MACAuthCtxGet
    (
        DRV_HANDLE handle,
        WDRV_WINC_AUTH_CONTEXT *pAuthCtx
    )

  Summary:
    Obtain a copy of the authentication context.

  Description:
    Obtain a copy of the current authentication context from within the driver.

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_MACAuthCtxGet
(
    DRV_HANDLE handle,
    WDRV_WINC_AUTH_CONTEXT *pAuthCtx
)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)handle;

    /* Ensure the driver handle and user pointer is valid. */
    if ((NULL == pDcpt) || (NULL == pAuthCtx))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    OSAL_SEM_Pend(&pDcpt->authCtxSemaphore, OSAL_WAIT_FOREVER);
    memcpy(pAuthCtx, &pDcpt->authCtx, sizeof(WDRV_WINC_AUTH_CONTEXT));
    OSAL_SEM_Post(&pDcpt->authCtxSemaphore);

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MACAuthCtxSet
    (
        DRV_HANDLE handle,
        WDRV_WINC_AUTH_CONTEXT *pAuthCtx
    )

  Summary:
    Load a new authentication context into the driver.

  Description:
    A new authentication context should be created and initialized before being
      loaded into the MAC driver.

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_MACAuthCtxSet
(
    DRV_HANDLE handle,
    WDRV_WINC_AUTH_CONTEXT *pAuthCtx
)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)handle;

    /* Ensure the driver handle and user pointer is valid. */
    if ((NULL == pDcpt) || (NULL == pAuthCtx))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    OSAL_SEM_Pend(&pDcpt->authCtxSemaphore, OSAL_WAIT_FOREVER);
    memcpy(&pDcpt->authCtx, pAuthCtx, sizeof(WDRV_WINC_AUTH_CONTEXT));
    OSAL_SEM_Post(&pDcpt->authCtxSemaphore);

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_OP_MODE WDRV_WINC_MACOperatingModeGet(DRV_HANDLE handle)

  Summary:
    Requests the current operation mode.

  Description:
    The driver can operate as either an infrastructure station or Soft-AP.
      This function returns the current mode of operation.

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

WDRV_WINC_OP_MODE WDRV_WINC_MACOperatingModeGet(DRV_HANDLE handle)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if (NULL == pDcpt)
    {
        return WDRV_WINC_OP_MODE_UNKNOWN;
    }

    return pDcpt->operatingMode;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MACOperatingModeSet
    (
        DRV_HANDLE handle,
        WDRV_WINC_OP_MODE operatingMode
    )

  Summary:
    Configures the current operating mode.

  Description:
    The driver can operate as either an infrastructure station or Soft-AP.
      This function configures the current mode of operation.

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_MACOperatingModeSet
(
    DRV_HANDLE handle,
    WDRV_WINC_OP_MODE operatingMode
)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if (NULL == pDcpt)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    pDcpt->operatingMode = operatingMode;

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_MAC_CONN_STATE WDRV_WINC_MACConnectStateGet(DRV_HANDLE handle)

  Summary:
    Requests the current connection state.

  Description:

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

WDRV_WINC_MAC_CONN_STATE WDRV_WINC_MACConnectStateGet(DRV_HANDLE handle)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)handle;

    /* Ensure the driver handle and user pointer is valid. */
    if ((NULL == pDcpt) || (false == pDcpt->isOpen))
    {
        return WDRV_WINC_MAC_CONN_STATE_CLOSED;
    }

    if (true == pDcpt->isLinkActive)
    {
        return WDRV_WINC_MAC_CONN_STATE_CONNECTED;
    }
    else if (WDRV_WINC_DRV_STATE_CONNECTING == pDcpt->wincDrvState)
    {
        return WDRV_WINC_MAC_CONN_STATE_CONNECTING;
    }

    return WDRV_WINC_MAC_CONN_STATE_IDLE;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_MACAutoConnectSet(DRV_HANDLE handle, bool autoConnect)

  Summary:
    Configures the auto-connect functionality.

  Description:
    If auto-connect is enabled then whenever the driver is opened it will
      attempt to connect using the current BSS and authentication contexts.
      If auto-connect is disabled then the driver will not attempt to connect
      when it is opened.

  Remarks:
    See wdrv_winc_stack_drv.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_MACAutoConnectSet(DRV_HANDLE handle, bool autoConnect)
{
    WDRV_WINC_MACDCPT *const pDcpt = (WDRV_WINC_MACDCPT *const)handle;

    /* Ensure the driver handle is valid. */
    if (NULL == pDcpt)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    pDcpt->autoConnect = autoConnect;

    return WDRV_WINC_STATUS_OK;
}
