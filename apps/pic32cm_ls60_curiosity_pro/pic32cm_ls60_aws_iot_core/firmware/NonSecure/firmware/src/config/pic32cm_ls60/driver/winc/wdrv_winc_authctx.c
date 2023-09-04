/*******************************************************************************
  WINC Driver Authentication Context Implementation

  File Name:
    wdrv_winc_authctx.c

  Summary:
    WINC wireless driver authentication context implementation.

  Description:
    This interface manages the authentication contexts which 'wrap' the state
      associated with authentication schemes.
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
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <string.h>

#include "wdrv_winc_common.h"
#include "wdrv_winc_authctx.h"

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver Authentication Context Global Data
// *****************************************************************************
// *****************************************************************************

/* ASN.1 tag IDs. */
#define ASN1_TAG_SEQUENCE   (0x30)
#define ASN1_TAG_INTEGER    (0x02)

// *****************************************************************************
/*  Address and length structure

  Summary:
    Holds an address and length.

  Description:
    Structure used to maintain an address and length to some data.

  Remarks:
    None.
*/

typedef struct
{
    const uint8_t *pAddress;
    uint32_t length;
} ADDR_LENGTH;

// *****************************************************************************
/*  PKCS#1 RSA Private Key

  Summary:
    Elements of a parsed RSA private key.

  Description:
    A series of pointer/length of each element of an RSA private key.

  Remarks:
    None.
*/

typedef struct
{
    ADDR_LENGTH version;
    ADDR_LENGTH modulus;
    ADDR_LENGTH publicExponent;
    ADDR_LENGTH privateExponent;
    ADDR_LENGTH prime1;
    ADDR_LENGTH prime2;
    ADDR_LENGTH exponent1;
    ADDR_LENGTH exponent2;
    ADDR_LENGTH coefficient;
} PKCS1_RSA_PRIVATE_KEY;

// *****************************************************************************
/*  Map RSA private key indexes to offsets

  Summary:
    Table to map index of key elements to offsets within structure.

  Description:
    Table to map index of key elements to offsets within structure.

  Remarks:
    None.
*/

#ifdef WDRV_WINC_DEVICE_ENTERPRISE_CONNECT
static const int rsaPriKeyMap[] = {
    offsetof(PKCS1_RSA_PRIVATE_KEY, version),
    offsetof(PKCS1_RSA_PRIVATE_KEY, modulus),
    offsetof(PKCS1_RSA_PRIVATE_KEY, publicExponent),
    offsetof(PKCS1_RSA_PRIVATE_KEY, privateExponent),
    offsetof(PKCS1_RSA_PRIVATE_KEY, prime1),
    offsetof(PKCS1_RSA_PRIVATE_KEY, prime2),
    offsetof(PKCS1_RSA_PRIVATE_KEY, exponent1),
    offsetof(PKCS1_RSA_PRIVATE_KEY, exponent2),
    offsetof(PKCS1_RSA_PRIVATE_KEY, coefficient),
    -1
};
#endif

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver Authentication Context Implementation
// *****************************************************************************
// *****************************************************************************

#ifdef WDRV_WINC_DEVICE_ENTERPRISE_CONNECT
static int asn1DecodeTag(const uint8_t *pASN1, uint8_t *pTag, uint32_t *pLength,
                                                    const uint8_t **pContents)
{
    int numTagBytes;
    uint32_t localLength;

    if (NULL == pASN1)
    {
        return 0;
    }

    if (NULL == pLength)
    {
        pLength = &localLength;
    }

    if (NULL != pTag)
    {
        *pTag = *pASN1;
    }

    pASN1++;
    numTagBytes = 1;

    if (*pASN1 & 0x80)
    {
        int numLenBytes;

        numLenBytes = (*pASN1 & 0x7f);

        pASN1++;
        numTagBytes += (1+numLenBytes);

        *pLength = 0;
        while(numLenBytes--)
        {
            *pLength = (*pLength << 8) | *pASN1++;
        }
    }
    else
    {
        numTagBytes++;
        *pLength = *pASN1++;
    }

    numTagBytes += *pLength;

    if (NULL != pContents)
    {
        *pContents = pASN1;
    }

    return numTagBytes;
}

static bool PKCS1_ParseRSAPrivateKeyDER(const uint8_t *pKey, size_t keyLength,
                                        PKCS1_RSA_PRIVATE_KEY * const pPrivateKey)
{
    uint8_t tagID;
    uint32_t tagLength;
    const uint8_t *pTagContents;
    int numTagBytes;
    const int *pAddrOffset;
    ADDR_LENGTH *pPriKeyTag;

/*
    RSAPrivateKey ::= SEQUENCE {
        version           Version,
        modulus           INTEGER,  -- n
        publicExponent    INTEGER,  -- e
        privateExponent   INTEGER,  -- d
        prime1            INTEGER,  -- p
        prime2            INTEGER,  -- q
        exponent1         INTEGER,  -- d mod (p-1)
        exponent2         INTEGER,  -- d mod (q-1)
        coefficient       INTEGER,  -- (inverse of q) mod p
        otherPrimeInfos   OtherPrimeInfos OPTIONAL
    }
*/

    if ((NULL == pKey) || (NULL == pPrivateKey))
    {
        return false;
    }

    memset(pPrivateKey, 0, sizeof(PKCS1_RSA_PRIVATE_KEY));

    numTagBytes = asn1DecodeTag(pKey, &tagID, &tagLength, &pTagContents);

    if (ASN1_TAG_SEQUENCE != tagID)
    {
        // Not SEQUENCE
        return false;
    }

    if ((int)keyLength < numTagBytes)
    {
        return false;
    }

    pKey = pTagContents;
    keyLength = tagLength;
    pAddrOffset = rsaPriKeyMap;

    do
    {
        numTagBytes = asn1DecodeTag(pKey, &tagID, &tagLength, &pTagContents);

        if (ASN1_TAG_INTEGER == tagID)
        {
            if ((tagLength > 1)
                && (0x00 == pTagContents[0]) && (0x00 != (pTagContents[1] & 0x80)))
            {
                pTagContents++;
                tagLength--;
            }

            if (*pAddrOffset >= 0)
            {
                pPriKeyTag = (ADDR_LENGTH*)&((uint8_t*)pPrivateKey)[*pAddrOffset];
                pAddrOffset++;

                pPriKeyTag->pAddress  = pTagContents;
                pPriKeyTag->length    = tagLength;
            }
        }

        pKey += numTagBytes;
        keyLength -= numTagBytes;
    }
    while(keyLength);

    return true;
}
#endif

//*******************************************************************************
/*
  Function:
    bool _DRV_WINC_WEPKeyIsValid
    (
        uint8_t idx,
        uint8_t *const pKey,
        uint8_t size
    )

  Summary:
    Checks if WEP key is valid.

  Description:
    Determines if the WEP key, index and size are valid.

  Precondition:
    None.

  Parameters:
    idx  - Key index.
    pKey - Pointer to key.
    size - Size of key.

  Returns:
    true or false indicating if WEP key information is valid.

*/
#ifndef WDRV_WINC_DEVICE_DEPRECATE_WEP
static bool _DRV_WINC_WEPKeyIsValid
(
    uint8_t idx,
    uint8_t *const pKey,
    uint8_t size
)
{
    /* Check index. Index values 1-4 is only allowed*/
    if ((idx < 1) || (idx > 4))
    {
        return false;
    }
    /* Check key. */
    if (NULL == pKey)
    {
        return false;
    }
    /* Check size. */
    if (
            (WDRV_WINC_WEP_40_KEY_STRING_SIZE != size)
        &&  (WDRV_WINC_WEP_104_KEY_STRING_SIZE != size)
    )
    {
        return false;
    }
    return true;
}
#endif
//*******************************************************************************
/*
  Function:
    bool WDRV_WINC_AuthCtxIsValid(const WDRV_WINC_AUTH_CONTEXT *const pAuthCtx)

  Summary:
    Tests if an authentication context is valid.

  Description:
    Tests the elements of the authentication context to judge if their values are legal.

  Remarks:
    See wdrv_winc_authctx.h for usage information.

*/

bool WDRV_WINC_AuthCtxIsValid(const WDRV_WINC_AUTH_CONTEXT *const pAuthCtx)
{
    /* Ensure authentication context is valid. */
    if (NULL == pAuthCtx)
    {
        return false;
    }

    switch (pAuthCtx->authType)
    {
        /* Nothing to check for Open authentication. */
        case WDRV_WINC_AUTH_TYPE_OPEN:
        {
            break;
        }

        /* Check WPA authentication. */
        case WDRV_WINC_AUTH_TYPE_WPA_PSK:
        {
            break;
        }
#ifndef WDRV_WINC_DEVICE_DEPRECATE_WEP
        /* Check WEP authentication. */
        case WDRV_WINC_AUTH_TYPE_WEP:
        {
            if (false == _DRV_WINC_WEPKeyIsValid(
                    pAuthCtx->authInfo.WEP.idx,
                    (uint8_t *const)(pAuthCtx->authInfo.WEP.key),
                    pAuthCtx->authInfo.WEP.size
            ))
            {
                return false;
            }
            break;
        }
#endif
        /* Check Enterprise authentication. */
        case WDRV_WINC_AUTH_TYPE_802_1X:
        {
            break;
        }

        default:
        {
            /* Unknown authentication scheme. */
            return false;
        }
    }

    return true;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_AuthCtxSetDefaults
    (
        WDRV_WINC_AUTH_CONTEXT *const pAuthCtx
    )

  Summary:
    Configures an authentication context into a default state.

  Description:
    Ensures that each element of the structure is configured into a default state.

  Remarks:
    See wdrv_winc_authctx.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_AuthCtxSetDefaults
(
    WDRV_WINC_AUTH_CONTEXT *const pAuthCtx
)
{
    /* Ensure authentication context is valid. */
    if (NULL == pAuthCtx)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure authentication type is a known invalid type. */
    pAuthCtx->authType = WDRV_WINC_AUTH_TYPE_INVALID;

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_AuthCtxSetOpen
    (
        WDRV_WINC_AUTH_CONTEXT *const pAuthCtx
    )

  Summary:
    Configure an authentication context for Open authentication.

  Description:
    The type and state information are configured appropriately for Open
      authentication.

  Remarks:
    See wdrv_winc_authctx.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_AuthCtxSetOpen
(
    WDRV_WINC_AUTH_CONTEXT *const pAuthCtx
)
{
    /* Ensure authentication context is valid. */
    if (NULL == pAuthCtx)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Set authentication type to Open. */
    pAuthCtx->authType = WDRV_WINC_AUTH_TYPE_OPEN;

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_AuthCtxSetWEP
    (
        WDRV_WINC_AUTH_CONTEXT *const pAuthCtx,
        uint8_t idx,
        uint8_t *pKey,
        uint8_t size
    )

  Summary:
    Configure an authentication context for WEP authentication.

  Description:
    The type and state information are configured appropriately for WEP
      authentication.

  Remarks:
    See wdrv_winc_authctx.h for usage information.

*/
#ifndef WDRV_WINC_DEVICE_DEPRECATE_WEP
WDRV_WINC_STATUS WDRV_WINC_AuthCtxSetWEP
(
    WDRV_WINC_AUTH_CONTEXT *const pAuthCtx,
    uint8_t idx,
    uint8_t *const pKey,
    uint8_t size
)
{
    /* Ensure authentication context is valid. */
    if ((NULL == pAuthCtx) || (NULL == pKey))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the index and key are valid. */
    if (false == _DRV_WINC_WEPKeyIsValid(idx, pKey, size))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Set authentication type to WEP. */
    pAuthCtx->authType = WDRV_WINC_AUTH_TYPE_WEP;

    /* Set key index and size. */
    pAuthCtx->authInfo.WEP.idx  = idx;
    pAuthCtx->authInfo.WEP.size = size;

    /* Copy WEP key and ensure zero terminated. */
    memcpy(&pAuthCtx->authInfo.WEP.key, pKey, size);
    pAuthCtx->authInfo.WEP.key[size] = '\0';

    return WDRV_WINC_STATUS_OK;
}
#endif
//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_AuthCtxSetWPA
    (
        WDRV_WINC_AUTH_CONTEXT *const pAuthCtx,
        uint8_t *const pPSK,
        uint8_t size
    )

  Summary:
    Configure an authentication context for WPA-PSK authentication.

  Description:
    The type and state information are configured appropriately for WPA-PSK
      authentication.

  Remarks:
    See wdrv_winc_authctx.h for usage information.

*/

WDRV_WINC_STATUS WDRV_WINC_AuthCtxSetWPA
(
    WDRV_WINC_AUTH_CONTEXT *const pAuthCtx,
    uint8_t *const pPSK,
    uint8_t size
)
{
    /* Ensure authentication context is valid. */
    if (NULL == pAuthCtx)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Ensure the key size is correct and the key was provided. */
    if ((size > WDRV_WINC_PSK_LEN) || (NULL == pPSK))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Set authentication type to WPA. */
    pAuthCtx->authType = WDRV_WINC_AUTH_TYPE_WPA_PSK;

    /* Copy the key and zero out unused parts of the buffer. */
    memset(&pAuthCtx->authInfo.WPAPerPSK.key, 0, WDRV_WINC_PSK_LEN+1);
    memcpy(&pAuthCtx->authInfo.WPAPerPSK.key, pPSK, size);
    pAuthCtx->authInfo.WPAPerPSK.size = size;

    return WDRV_WINC_STATUS_OK;
}

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_AuthCtxSetWPAEnterpriseMSCHAPv2
    (
        WDRV_WINC_AUTH_CONTEXT *const pAuthCtx,
        const char *const pUserDomain,
        const uint8_t *const pPassword,
        const uint16_t passwordLength,
        const bool visibleUserName
    )

  Summary:
    Configure an authentication context for WPA(2)-Enterprise authentication
    using MS-CHAPv2.

  Description:
    The type and state information are configured appropriately for WPA-Enterprise
      authentication.

  Remarks:
    See wdrv_winc_authctx.h for usage information.

*/

#ifdef WDRV_WINC_DEVICE_ENTERPRISE_CONNECT
WDRV_WINC_STATUS WDRV_WINC_AuthCtxSetWPAEnterpriseMSCHAPv2
(
    WDRV_WINC_AUTH_CONTEXT *const pAuthCtx,
    const char *const pUserDomain,
    const uint8_t *const pPassword,
    const uint16_t passwordLength,
    const bool visibleUserName
)
{
    /* Ensure authentication context is valid. */
    if (NULL == pAuthCtx)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    if ((NULL == pPassword) || (NULL == pUserDomain))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    if ((passwordLength > M2M_AUTH_1X_PASSWORD_LEN_MAX) ||
                                (strlen(pUserDomain) > M2M_AUTH_1X_USER_LEN_MAX))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Set authentication type to WPA. */
    pAuthCtx->authType = WDRV_WINC_AUTH_TYPE_802_1X_MSCHAPV2;

    memset(&pAuthCtx->authInfo.WPAEntMSCHAPv2.domainUserName, 0, M2M_AUTH_1X_USER_LEN_MAX+1);
    memcpy(&pAuthCtx->authInfo.WPAEntMSCHAPv2.domainUserName, pUserDomain, strlen(pUserDomain));
    memset(&pAuthCtx->authInfo.WPAEntMSCHAPv2.password, 0, M2M_AUTH_1X_PASSWORD_LEN_MAX);
    memcpy(&pAuthCtx->authInfo.WPAEntMSCHAPv2.password, pPassword, passwordLength);

    pAuthCtx->authInfo.WPAEntMSCHAPv2.passwordLength = passwordLength;

    if (NULL != strchr(pUserDomain, '\\'))
    {
        pAuthCtx->authInfo.WPAEntMSCHAPv2.domainIsFirst = true;
    }
    else
    {
        pAuthCtx->authInfo.WPAEntMSCHAPv2.domainIsFirst = false;
    }

    pAuthCtx->authInfo.WPAEntMSCHAPv2.visibleUserName = visibleUserName;

    return WDRV_WINC_STATUS_OK;
}
#endif

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_AuthCtxSetWPAEnterpriseTLS
    (
        WDRV_WINC_AUTH_CONTEXT *const pAuthCtx,
        const char *const pUserDomain,
        const uint8_t *const pPrivateKey,
        const uint16_t privateKeyLength,
        const uint8_t *const pCert,
        const uint16_t certLength,
        const bool visibleUserName
    )

  Summary:
    Configure an authentication context for WPA(2)-Enterprise authentication
    using TLS.

  Description:
    The type and state information are configured appropriately for WPA-Enterprise
      authentication.

  Remarks:
    See wdrv_winc_authctx.h for usage information.

*/

#ifdef WDRV_WINC_DEVICE_ENTERPRISE_CONNECT
WDRV_WINC_STATUS WDRV_WINC_AuthCtxSetWPAEnterpriseTLS
(
    WDRV_WINC_AUTH_CONTEXT *const pAuthCtx,
    const char *const pUserDomain,
    const uint8_t *const pPrivateKey,
    const uint16_t privateKeyLength,
    const uint8_t *const pCert,
    const uint16_t certLength,
    const bool visibleUserName
)
{
    PKCS1_RSA_PRIVATE_KEY privateKey;

    /* Ensure authentication context is valid. */
    if (NULL == pAuthCtx)
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    if ((NULL == pPrivateKey) || (NULL == pCert) || (NULL == pUserDomain))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    if (false == PKCS1_ParseRSAPrivateKeyDER(pPrivateKey, privateKeyLength, &privateKey))
    {
        return WDRV_WINC_STATUS_INVALID_ARG;
    }

    /* Set authentication type to WPA. */
    pAuthCtx->authType = WDRV_WINC_AUTH_TYPE_802_1X_TLS;

    memset(&pAuthCtx->authInfo.WPAEntTLS.domainUserName, 0, M2M_AUTH_1X_USER_LEN_MAX+1);
    memcpy(&pAuthCtx->authInfo.WPAEntTLS.domainUserName, pUserDomain, strlen(pUserDomain));

    pAuthCtx->authInfo.WPAEntTLS.pRSAPrivateKeyModulus      = privateKey.modulus.pAddress;
    pAuthCtx->authInfo.WPAEntTLS.RSAPrivateKeyModulusLength = privateKey.modulus.length;

    pAuthCtx->authInfo.WPAEntTLS.pRSAPrivateKeyExponent = privateKey.privateExponent.pAddress;

    pAuthCtx->authInfo.WPAEntTLS.pRSACertificate      = pCert;
    pAuthCtx->authInfo.WPAEntTLS.RSACertificateLength = certLength;

    if (NULL != strchr(pUserDomain, '\\'))
    {
        pAuthCtx->authInfo.WPAEntTLS.domainIsFirst = true;
    }
    else
    {
        pAuthCtx->authInfo.WPAEntTLS.domainIsFirst = false;
    }

    pAuthCtx->authInfo.WPAEntTLS.visibleUserName = visibleUserName;

    return WDRV_WINC_STATUS_OK;
}
#endif