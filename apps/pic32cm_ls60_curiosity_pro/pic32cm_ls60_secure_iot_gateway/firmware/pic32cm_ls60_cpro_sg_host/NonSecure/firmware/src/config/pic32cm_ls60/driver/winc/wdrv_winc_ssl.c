/*******************************************************************************
  WINC Driver TLS/SSL Implementation

  File Name:
    wdrv_winc_ssl.c

  Summary:
    WINC wireless driver TLS/SSL implementation.

  Description:
    Provides an interface to configure TLS/SSL support.
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
#include <stdio.h>

#include "wdrv_winc.h"
#include "wdrv_winc_common.h"
#include "wdrv_winc_ssl.h"
#ifndef WDRV_WINC_DEVICE_LITE_DRIVER
#include "socket.h"
#endif

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver TLS/SSL Global Data
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/*  Cipher Suite

  Summary:
    Link cipher suite ID to bit mask.

  Description:
    Associates a cipher suite ID with a bit mask.

  Remarks:
    None.
*/

typedef struct
{
    uint16_t ianaID;
    uint16_t bitMask;
} WDRV_WINC_CIPHER_SUITE_MAP;

/* This table maps all the supported cipher suites to a bit mask. */
#define WDRV_WINC_NUM_CIPHER_SUITES     16
static const WDRV_WINC_CIPHER_SUITE_MAP _cipherSuiteMap[WDRV_WINC_NUM_CIPHER_SUITES] =
{
    {
        .ianaID  = WDRV_WINC_TLS_RSA_WITH_AES_128_CBC_SHA,
        .bitMask = SSL_CIPHER_RSA_WITH_AES_128_CBC_SHA
    },
    {
        .ianaID  = WDRV_WINC_TLS_RSA_WITH_AES_128_CBC_SHA256,
        .bitMask = SSL_CIPHER_RSA_WITH_AES_128_CBC_SHA256
    },
    {
        .ianaID  = WDRV_WINC_TLS_DHE_RSA_WITH_AES_128_CBC_SHA,
        .bitMask = SSL_CIPHER_DHE_RSA_WITH_AES_128_CBC_SHA
    },
    {
        .ianaID  = WDRV_WINC_TLS_DHE_RSA_WITH_AES_128_CBC_SHA256,
        .bitMask = SSL_CIPHER_DHE_RSA_WITH_AES_128_CBC_SHA256
    },
    {
        .ianaID  = WDRV_WINC_TLS_RSA_WITH_AES_128_GCM_SHA256,
        .bitMask = SSL_CIPHER_RSA_WITH_AES_128_GCM_SHA256
    },
    {
        .ianaID  = WDRV_WINC_TLS_DHE_RSA_WITH_AES_128_GCM_SHA256,
        .bitMask = SSL_CIPHER_DHE_RSA_WITH_AES_128_GCM_SHA256
    },
    {
        .ianaID  = WDRV_WINC_TLS_RSA_WITH_AES_256_CBC_SHA,
        .bitMask = SSL_CIPHER_RSA_WITH_AES_256_CBC_SHA
    },
    {
        .ianaID  = WDRV_WINC_TLS_RSA_WITH_AES_256_CBC_SHA256,
        .bitMask = SSL_CIPHER_RSA_WITH_AES_256_CBC_SHA256
    },
    {
        .ianaID  = WDRV_WINC_TLS_DHE_RSA_WITH_AES_256_CBC_SHA,
        .bitMask = SSL_CIPHER_DHE_RSA_WITH_AES_256_CBC_SHA
    },
    {
        .ianaID  = WDRV_WINC_TLS_DHE_RSA_WITH_AES_256_CBC_SHA256,
        .bitMask = SSL_CIPHER_DHE_RSA_WITH_AES_256_CBC_SHA256
    },
    {
        .ianaID  = WDRV_WINC_TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA,
        .bitMask = SSL_CIPHER_ECDHE_RSA_WITH_AES_128_CBC_SHA
    },
    {
        .ianaID  = WDRV_WINC_TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA,
        .bitMask = SSL_CIPHER_ECDHE_RSA_WITH_AES_256_CBC_SHA
    },
    {
        .ianaID  = WDRV_WINC_TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256,
        .bitMask = SSL_CIPHER_ECDHE_RSA_WITH_AES_128_CBC_SHA256
    },
    {
        .ianaID  = WDRV_WINC_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256,
        .bitMask = SSL_CIPHER_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256
    },
    {
        .ianaID  = WDRV_WINC_TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256,
        .bitMask = SSL_CIPHER_ECDHE_RSA_WITH_AES_128_GCM_SHA256
    },
    {
        .ianaID  = WDRV_WINC_TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256,
        .bitMask = SSL_CIPHER_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256
    }
};

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_SSLCTXDefault
    (
        WDRV_WINC_CIPHER_SUITE_CONTEXT *pSSLCipherSuiteCtx
    )

  Summary:
    Initialize an SSL cipher suite context.

  Description:
    Sets the default values for the cipher suite context.

  Remarks:
    See wdrv_winc_ssl.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_SSLCTXDefault
(
    WDRV_WINC_CIPHER_SUITE_CONTEXT *pSSLCipherSuiteCtx
)
{
    /* Ensure the cipher suite context is valid. */
    if (NULL == pSSLCipherSuiteCtx)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Set the default cipher suites. */
#if defined(WDRV_WINC_DEVICE_WINC1500)
    pSSLCipherSuiteCtx->ciperSuites = 0;
#elif defined(WDRV_WINC_DEVICE_WINC3400)
    pSSLCipherSuiteCtx->ciperSuites = SSL_DEFAULT_CIPHERS;
#endif

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_SSLCTXCipherSuitesSet
    (
        WDRV_WINC_CIPHER_SUITE_CONTEXT *pSSLCipherSuiteCtx,
        uint16_t *pCipherSuiteList,
        uint8_t numCipherSuites
    )

  Summary:
    Set the cipher suites enabled in a context.

  Description:
    Sets the list of enabled cipher suites within a cipher suite context using
      IANA defined IDs.

  Remarks:
    See wdrv_winc_ssl.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_SSLCTXCipherSuitesSet
(
    WDRV_WINC_CIPHER_SUITE_CONTEXT *pSSLCipherSuiteCtx,
    uint16_t *pCipherSuiteList,
    uint8_t numCipherSuites
)
{
    uint8_t i;

    /* Ensure the cipher suite context and cipher suite list are valid. */
    if ((NULL == pSSLCipherSuiteCtx) || (NULL == pCipherSuiteList) || (numCipherSuites > 16))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Add each cipher suite in the list to the supported cipher suite bit mask
       by searching the table which maps ID to bit mask. */
    pSSLCipherSuiteCtx->ciperSuites = 0;

    while((numCipherSuites--) && (*pCipherSuiteList != WDRV_WINC_TLS_NULL_WITH_NULL_NULL))
    {
        for (i=0; i<WDRV_WINC_NUM_CIPHER_SUITES; i++)
        {
            if (_cipherSuiteMap[i].ianaID == *pCipherSuiteList)
            {
                pSSLCipherSuiteCtx->ciperSuites |= _cipherSuiteMap[i].bitMask;
            }
        }

        pCipherSuiteList++;
    }

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    uint8_t WDRV_WINC_SSLCTXCipherSuitesGet
    (
        WDRV_WINC_CIPHER_SUITE_CONTEXT *pSSLCipherSuiteCtx,
        uint16_t *pCipherSuiteList,
        uint8_t maxNumCipherSuites
    )

  Summary:
    Returns the enabled cipher suites from a context.

  Description:
    Gets the list of cipher suites from a context as a list of IANA IDs

  Remarks:
    See wdrv_winc_ssl.h for usage information.

*/

uint8_t WDRV_WINC_SSLCTXCipherSuitesGet
(
    WDRV_WINC_CIPHER_SUITE_CONTEXT *pSSLCipherSuiteCtx,
    uint16_t *pCipherSuiteList,
    uint8_t maxNumCipherSuites
)
{
    uint8_t i;
    uint32_t cipherMask;
    uint8_t numCipherSuites;

    /* Ensure the cipher suite context and cipher suite list are valid. */
    if ((NULL == pSSLCipherSuiteCtx) || (NULL == pCipherSuiteList))
    {
        return 0;
    }

    cipherMask = 0x0001;
    numCipherSuites = 0;

    /* Translate the cipher suite bit mask back into a cipher suite list. */
    while ((0 != cipherMask) && (numCipherSuites < maxNumCipherSuites))
    {
        if (0 != (cipherMask & pSSLCipherSuiteCtx->ciperSuites))
        {
            for (i=0; i<WDRV_WINC_NUM_CIPHER_SUITES; i++)
            {
                if (cipherMask == _cipherSuiteMap[i].bitMask)
                {
                    *pCipherSuiteList++ = _cipherSuiteMap[i].ianaID;
                    numCipherSuites++;
                }
            }
        }

        cipherMask <<= 1;
    }

    return numCipherSuites;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_SSLActiveCipherSuitesSet
    (
        DRV_HANDLE handle,
        WDRV_WINC_CIPHER_SUITE_CONTEXT *pSSLCipherSuiteCtx,
        WDRV_WINC_SSL_CIPHERSUITELIST_CALLBACK pfSSLListCallback,
        WDRV_WINC_REQ_ECC_CALLBACK pfECCREQCallback
    )

  Summary:
    Set the active cipher suites.

  Description:
    Passes the active cipher suite list to the WINC.

  Remarks:
    See wdrv_winc_ssl.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_SSLActiveCipherSuitesSet
(
    DRV_HANDLE handle,
    WDRV_WINC_CIPHER_SUITE_CONTEXT *pSSLCipherSuiteCtx,
    WDRV_WINC_SSL_CIPHERSUITELIST_CALLBACK pfSSLListCallback
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const )handle;

    /* Ensure the driver handle and user pointer are valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pDcpt->pCtrl) || (NULL == pSSLCipherSuiteCtx))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    pDcpt->pCtrl->pfSSLCipherSuiteListCB = pfSSLListCallback;

    /* Set the active cipher suite. */
    if (M2M_SUCCESS != m2m_ssl_set_active_ciphersuites(pSSLCipherSuiteCtx->ciperSuites))
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_SSLECCReqCallbackSet
    (
        DRV_HANDLE handle,
        WDRV_WINC_REQ_ECC_CALLBACK pfECCREQCallback
    )

  Summary:
    Set the ECC request callback.

  Description:
    Registers the ECC request callback with the driver.

  Remarks:
    See wdrv_winc_ssl.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_SSLECCReqCallbackSet
(
    DRV_HANDLE handle,
    WDRV_WINC_SSL_REQ_ECC_CALLBACK pfECCREQCallback
)
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

    pDcpt->pCtrl->pfSSLReqECCCB = pfECCREQCallback;

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_SSLECCHandShakeRsp
    (
        DRV_HANDLE handle,
        WINC_WDRV_ECC_REQ_TYPE reqType,
        WINC_WDRV_ECC_STATUS status,
        const WDRV_WINC_ECC_HANDSHAKE_INFO *const pHandshakeData,
        const WDRV_WINC_ECDH_INFO *const pECDHRspInfo,
        const uint8_t *const pRspDataBuff,
        uint16_t rspDataSz
    )

  Summary:
    Handshake Response for ECC cipher suites .

  Description:
    Passes the ECC response data to WINC.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_SSLECCHandShakeRsp
(
    DRV_HANDLE handle,
    WINC_WDRV_ECC_REQ_TYPE reqType,
    WINC_WDRV_ECC_STATUS status,
    const WDRV_WINC_ECC_HANDSHAKE_INFO *const pHandshakeData,
    const WDRV_WINC_ECDH_INFO *const pECDHRspInfo,
    const uint8_t *const pRspDataBuff,
    uint16_t rspDataSz
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const )handle;
    int8_t result;
    tstrEccReqInfo strECCResp;

    /* Ensure the driver handle and user pointers are valid. */
    if ((DRV_HANDLE_INVALID == handle) || (NULL == pDcpt) || (NULL == pHandshakeData))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure both data pointer and size are either both set or not. */
    if (((NULL == pRspDataBuff) || (0 == rspDataSz)) && ((NULL != pRspDataBuff) || (0 != rspDataSz)))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    memset(&strECCResp, 0, sizeof(tstrEccReqInfo));

    strECCResp.u16REQ       = reqType;
    strECCResp.u32UserData  = pHandshakeData->data[0];
    strECCResp.u32SeqNo     = pHandshakeData->data[1];

    if (WINC_WDRV_ECC_STATUS_SUCCESS == status)
    {
        strECCResp.u16Status = 0;
    }
    else
    {
        strECCResp.u16Status = 1;
    }

    switch(reqType)
    {
        case WDRV_WINC_ECC_REQ_CLIENT_ECDH:
        {
            if (NULL == pECDHRspInfo)
            {
                return WDRV_WINC_STATUS_INVALID_ARG;
            }

            memcpy(&strECCResp.strEcdhREQ.strPubKey.X, &pECDHRspInfo->pubKey.x, ECC_POINT_MAX_SIZE);
            memcpy(&strECCResp.strEcdhREQ.strPubKey.Y, &pECDHRspInfo->pubKey.y, ECC_POINT_MAX_SIZE);
            strECCResp.strEcdhREQ.strPubKey.u16Size      = pECDHRspInfo->pubKey.size;
            strECCResp.strEcdhREQ.strPubKey.u16PrivKeyID = pECDHRspInfo->pubKey.privKeyID;

            memcpy(&strECCResp.strEcdhREQ.au8Key, &pECDHRspInfo->key, ECC_POINT_MAX_SIZE);
            break;
        }

        case WDRV_WINC_ECC_REQ_SERVER_ECDH:
        {
            if (NULL == pECDHRspInfo)
            {
                return WDRV_WINC_STATUS_INVALID_ARG;
            }

            memcpy(&strECCResp.strEcdhREQ.au8Key, &pECDHRspInfo->key, ECC_POINT_MAX_SIZE);
            break;
        }

        case WDRV_WINC_ECC_REQ_GEN_KEY:
        {
            if (NULL == pECDHRspInfo)
            {
                return WDRV_WINC_STATUS_INVALID_ARG;
            }

            memcpy(&strECCResp.strEcdhREQ.strPubKey.X, &pECDHRspInfo->pubKey.x, ECC_POINT_MAX_SIZE);
            memcpy(&strECCResp.strEcdhREQ.strPubKey.Y, &pECDHRspInfo->pubKey.y, ECC_POINT_MAX_SIZE);
            strECCResp.strEcdhREQ.strPubKey.u16Size      = pECDHRspInfo->pubKey.size;
            strECCResp.strEcdhREQ.strPubKey.u16PrivKeyID = pECDHRspInfo->pubKey.privKeyID;
            break;
        }

        case WDRV_WINC_ECC_REQ_SIGN_GEN:
        case WDRV_WINC_ECC_REQ_SIGN_VERIFY:
        {
            break;
        }

        default:
        {
            return WDRV_WINC_STATUS_INVALID_ARG;
        }
    }

    m2m_ssl_ecc_process_done();

    result = m2m_ssl_handshake_rsp(&strECCResp, (uint8_t*)pRspDataBuff, rspDataSz);

    if (M2M_SUCCESS == result)
    {
        return WDRV_WINC_STATUS_OK;
    }
    else
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_SSLRetrieveCert
    (
        DRV_HANDLE handle,
        uint16_t *pCurveType,
        uint8_t *pHash,
        uint8_t *pSig,
        WDRV_WINC_EC_POINT_REP *pKey
    )

  Summary:
    Retrieve the certificate to be verified from the WINC

  Description:
    Retrieve the certificate to be verified from the WINC

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_SSLRetrieveCert
(
    DRV_HANDLE handle,
    uint16_t *pCurveType,
    uint8_t *pHash,
    uint8_t *pSig,
    WDRV_WINC_EC_POINT_REP *pKey
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const )handle;
    tstrECPoint wincKey;

    /* Ensure the driver handle and user pointers are valid. */
    if ((NULL == pDcpt) || (NULL == pHash) || (NULL == pSig) || (NULL == pKey))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    if (M2M_SUCCESS == m2m_ssl_retrieve_cert(pCurveType, pHash, pSig, &wincKey))
    {
        memcpy(&pKey->x, &wincKey.X, ECC_POINT_MAX_SIZE);
        memcpy(&pKey->y, &wincKey.Y, ECC_POINT_MAX_SIZE);
        pKey->size      = wincKey.u16Size;
        pKey->privKeyID = wincKey.u16PrivKeyID;

        return WDRV_WINC_STATUS_OK;
    }
    else
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_SSLRetrieveHash
    (
        DRV_HANDLE handle,
        uint8_t *pHash,
        uint16_t hashSz
    )

  Summary:
    Retrieve the certificate hash

  Description:
    Retrieve the certificate hash from the WINC

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_SSLRetrieveHash
(
    DRV_HANDLE handle,
    uint8_t* pHash,
    uint16_t hashSz
)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const )handle;

    /* Ensure the driver handle is valid. */
    if ((NULL == pDcpt) || (NULL == pHash))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    if (M2M_SUCCESS == m2m_ssl_retrieve_hash(pHash, hashSz))
    {
        return WDRV_WINC_STATUS_OK;
    }
    else
    {
        return WDRV_WINC_STATUS_REQUEST_ERROR;
    }
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_SSLStopRetrieveCert(DRV_HANDLE handle)

  Summary:
    Stop processing the certificate

  Description:
    Stop processing the certificate

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_SSLStopRetrieveCert(DRV_HANDLE handle)
{
    WDRV_WINC_DCPT *const pDcpt = (WDRV_WINC_DCPT *const )handle;

    /* Ensure the driver handle is valid. */
    if (NULL == pDcpt)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the driver instance has been opened for use. */
    if (false == pDcpt->isOpen)
    {
        return WDRV_WINC_STATUS_NOT_OPEN;
    }

    m2m_ssl_stop_processing_certs();

    return WDRV_WINC_STATUS_OK;
}