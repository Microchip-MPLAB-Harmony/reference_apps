/*******************************************************************************
  WINC Driver Custom IE Implementation

  File Name:
    wdrv_winc_custie.c

  Summary:
    WINC wireless driver custom IE implementation.

  Description:
    This file provides an interface for manipulating the custom information
      element store. Custom IE's can be included in the Soft-AP beacons.
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

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <string.h>

#include "wdrv_winc_common.h"
#include "wdrv_winc_custie.h"

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver Custom IE Implementation
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    WDRV_WINC_CUST_IE_STORE_CONTEXT* WDRV_WINC_CustIEStoreCtxSetStorage
    (
        uint8_t *const pStorage,
        uint16_t lenStorage
    )

  Summary:
    Initialize the custom IE store.

  Description:
    The caller provides storage for the custom IE store, this will be initialized
      and a pointer provided which can be passed to WDRV_WINC_APSetCustIE after
      custom IEs are added by WDRV_WINC_CustIEStoreCtxAddIE.

  Remarks:
    See wdrv_winc_custie.h for usage information.

*/

WDRV_WINC_CUST_IE_STORE_CONTEXT* WDRV_WINC_CustIEStoreCtxSetStorage
(
    uint8_t *const pStorage,
    uint16_t lenStorage
)
{
    WDRV_WINC_CUST_IE_STORE_CONTEXT *pCustIECtx;

    /* Ensure user application provided storage is valid. */
    if ((NULL == pStorage) || (lenStorage < 2))
    {
        return NULL;
    }

    /* Initialise the storage area. */

    pCustIECtx = (WDRV_WINC_CUST_IE_STORE_CONTEXT*)pStorage;

    memset(pStorage, 0, lenStorage);

    pCustIECtx->maxLength = (lenStorage > (255+2)) ? 255 : (lenStorage - 2);

    return pCustIECtx;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_CustIEStoreCtxAddIE
    (
        WDRV_WINC_CUST_IE_STORE_CONTEXT *const pCustIECtx,
        uint8_t id,
        const uint8_t *const pData,
        uint8_t dataLength
    )

  Summary:
    Add data to the custom IE store.

  Description:
    The data and ID provided are copied into the custom IE store.

  Remarks:
    See wdrv_winc_custie.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_CustIEStoreCtxAddIE
(
    WDRV_WINC_CUST_IE_STORE_CONTEXT *const pCustIECtx,
    uint8_t id,
    const uint8_t *const pData,
    uint8_t dataLength
)
{
    WDRV_WINC_CUST_IE *pIE;
    uint8_t dataOffset;

    /* Ensure the storage context is valid. */
    if ((NULL == pCustIECtx) || (NULL == pData))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the new IE will fit. */
    if ((pCustIECtx->maxLength - pCustIECtx->curLength) < (dataLength + 2))
    {
        return WDRV_WINC_STATUS_NO_SPACE;
    }

    /* Walk the IEs until the end is found. */
    dataOffset = 0;
    pIE = (WDRV_WINC_CUST_IE*)&pCustIECtx->ieData[dataOffset];

    while((0 != pIE->id) && (dataOffset < pCustIECtx->curLength))
    {
        dataOffset += (2+pIE->length);
        pIE = (WDRV_WINC_CUST_IE*)&pCustIECtx->ieData[dataOffset];
    }

    /* Copy in new IE. */
    pIE->id = id;
    pIE->length = dataLength;
    memcpy(&pIE->data, pData, dataLength);

    pCustIECtx->curLength += (dataLength + 2);

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_CustIEStoreCtxRemoveIE
    (
        WDRV_WINC_CUST_IE_STORE_CONTEXT *const pCustIECtx,
        uint8_t id
    )

  Summary:
    Removes data from the custom IE store.

  Description:
    This function removes a custom IE from the store which matches the ID provided.

  Remarks:
    See wdrv_winc_custie.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_CustIEStoreCtxRemoveIE
(
    WDRV_WINC_CUST_IE_STORE_CONTEXT *const pCustIECtx,
    uint8_t id
)
{
    WDRV_WINC_CUST_IE *pIE;
    uint8_t dataOffset;

    /* Ensure the storage context and ID are valid. */
    if ((NULL == pCustIECtx) || (0 == id))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Walk the IEs looking for the supplied ID. */
    dataOffset = 0;
    pIE = (WDRV_WINC_CUST_IE*)&pCustIECtx->ieData[dataOffset];

    while((0 != pIE->id) && (dataOffset < pCustIECtx->curLength))
    {
        if (pIE->id == id)
        {
            /* The ID has been found, copy remaining IEs over the top to remove it. */
            pCustIECtx->curLength -= (2+pIE->length);

            memcpy(&pCustIECtx->ieData[dataOffset],
                    &pCustIECtx->ieData[dataOffset+(2+pIE->length)],
                    pCustIECtx->maxLength - dataOffset - (2+pIE->length));

            pIE = (WDRV_WINC_CUST_IE*)&pCustIECtx->ieData[pCustIECtx->curLength];

            pIE->id = 0;
            pIE->length = 0;
            break;
        }

        dataOffset += (2+pIE->length);
        pIE = (WDRV_WINC_CUST_IE*)&pCustIECtx->ieData[dataOffset];
    }

    return WDRV_WINC_STATUS_OK;
}
