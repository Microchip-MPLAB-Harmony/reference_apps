/*******************************************************************************
  WINC Driver TLS/SSL Header File

  Company:
    Microchip Technology Inc.

  File Name:
    wdrv_winc_ssl.h

  Summary:
    WINC wireless driver TLS/SSL header file.

  Description:
    Provides an interface to configure TLS/SSL support.
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

#ifndef _WDRV_WINC_SSL_H
#define _WDRV_WINC_SSL_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>

#include "wdrv_winc_common.h"
#ifndef WDRV_WINC_DEVICE_LITE_DRIVER
#include "m2m_ssl.h"
#endif

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver TLS/SSL Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* List of IANA cipher suite IDs

  Summary:
    List of IANA cipher suite IDs.

  Description:
    These defines list the IANA cipher suite IDs.

  Remarks:
    None.

*/

#define WDRV_WINC_TLS_NULL_WITH_NULL_NULL                       0x0000
#define WDRV_WINC_TLS_RSA_WITH_AES_128_CBC_SHA                  0x002f
#define WDRV_WINC_TLS_RSA_WITH_AES_128_CBC_SHA256               0x003c
#define WDRV_WINC_TLS_DHE_RSA_WITH_AES_128_CBC_SHA              0x0033
#define WDRV_WINC_TLS_DHE_RSA_WITH_AES_128_CBC_SHA256           0x0067
#define WDRV_WINC_TLS_RSA_WITH_AES_128_GCM_SHA256               0x009c
#define WDRV_WINC_TLS_DHE_RSA_WITH_AES_128_GCM_SHA256           0x009e
#define WDRV_WINC_TLS_RSA_WITH_AES_256_CBC_SHA                  0x0035
#define WDRV_WINC_TLS_RSA_WITH_AES_256_CBC_SHA256               0x003d
#define WDRV_WINC_TLS_DHE_RSA_WITH_AES_256_CBC_SHA              0x0039
#define WDRV_WINC_TLS_DHE_RSA_WITH_AES_256_CBC_SHA256           0x006b
#define WDRV_WINC_TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA            0xc013
#define WDRV_WINC_TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA            0xc014
#define WDRV_WINC_TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256         0xc027
#define WDRV_WINC_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256       0xc023
#define WDRV_WINC_TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256         0xc02f
#define WDRV_WINC_TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256       0xc02b

// *****************************************************************************
/* The size of the the largest supported EC

  Summary:
    The size of the the largest supported EC. For now, assuming
    the 256-bit EC is the largest supported curve type.

  Description:
    These defines the size of the the largest supported EC.

  Remarks:
    None.

*/

#define WDRV_WINC_ECC_LARGEST_CURVE_SIZE     (32)

// *****************************************************************************
/* Maximum size of one coordinate of an EC point

  Summary:
    Maximum size of one coordinate of an EC point.

  Description:
    These defines the maximum size of one coordinate of an EC point.

  Remarks:
    None.

*/

#define WDRV_WINC_ECC_POINT_MAX_SIZE         WDRV_WINC_ECC_LARGEST_CURVE_SIZE

// *****************************************************************************
/* ECC Request Type

  Summary:
    Enumeration of ECC request types.

  Description:
    Types used for ECC requests from the WINC.

  Remarks:
    None.

*/

typedef enum
{
    WDRV_WINC_ECC_REQ_CLIENT_ECDH = ECC_REQ_CLIENT_ECDH,
    WDRV_WINC_ECC_REQ_SERVER_ECDH = ECC_REQ_SERVER_ECDH,
    WDRV_WINC_ECC_REQ_GEN_KEY = ECC_REQ_GEN_KEY,
    WDRV_WINC_ECC_REQ_SIGN_GEN = ECC_REQ_SIGN_GEN,
    WDRV_WINC_ECC_REQ_SIGN_VERIFY = ECC_REQ_SIGN_VERIFY
} WINC_WDRV_ECC_REQ_TYPE;

// *****************************************************************************
/* ECC Status Type

  Summary:
    Enumeration of ECC status types.

  Description:
    Types used for ECC responses to the WINC.

  Remarks:
    None.

*/

typedef enum
{
    WINC_WDRV_ECC_STATUS_SUCCESS,
    WINC_WDRV_ECC_STATUS_FAILURE,
} WINC_WDRV_ECC_STATUS;

// *****************************************************************************
/*  Elliptic Curve Point Representation

  Summary:
    Elliptic Curve point representation structure.

  Description:
    This structure contains information about Elliptic Curve point representation

  Remarks:
    None.

*/

typedef struct
{
    /* The X-coordinate of the ec point. */
    uint8_t     x[WDRV_WINC_ECC_POINT_MAX_SIZE];

    /* The Y-coordinate of the ec point. */
    uint8_t     y[WDRV_WINC_ECC_POINT_MAX_SIZE];

    /* Point size in bytes (for each of the coordinates). */
    uint16_t    size;

    /* ID for the corresponding private key. */
    uint16_t    privKeyID;
} WDRV_WINC_EC_POINT_REP;

// *****************************************************************************
/*  ECDSA Verify Request Information

  Summary:
    ECDSA Verify Request Information structure.

  Description:
    This structure contains information about ECDSA verify request.

  Remarks:
    None.

*/

typedef struct
{
    uint32_t    nSig;
} WDRV_WINC_ECDSA_VERIFY_REQ_INFO;

// *****************************************************************************
/*  ECDSA Sign Request Information

  Summary:
    ECDSA Sign Request Information structure.

  Description:
    This structure contains information about ECDSA sign request.

  Remarks:
    None.

*/

typedef struct
{
    uint16_t    curveType;
    uint16_t    hashSz;
} WDRV_WINC_ECDSA_SIGN_REQ_INFO;

// *****************************************************************************
/*  ECDH Request Information

  Summary:
    ECDH Request Information structure.

  Description:
    This structure contains information about ECDH request from WINC.

  Remarks:
    None.

*/

typedef struct
{
    WDRV_WINC_EC_POINT_REP  pubKey;
    uint8_t                 key[WDRV_WINC_ECC_POINT_MAX_SIZE];
} WDRV_WINC_ECDH_INFO;

// *****************************************************************************
/*  ECC Information Union

  Summary:
    Union combining possible structures for ECC Request Callback

  Description:
    This union contains possible structure returned to the ECC Request Callback.

  Remarks:
    None.
*/

typedef union
{
    WDRV_WINC_ECDH_INFO             ecdhInfo;
    WDRV_WINC_ECDSA_SIGN_REQ_INFO   ecdsaSignReqInfo;
    WDRV_WINC_ECDSA_VERIFY_REQ_INFO ecdsaVerifyReqInfo;
} WDRV_WINC_ECC_REQ_EX_INFO;

// *****************************************************************************
/*  ECC Handshake Information

  Summary:
    ECC handshake Information structure.

  Description:
    This structure contains information about ECC handshakes with the WINC.

  Remarks:
    None.

*/

typedef struct
{
    uint32_t data[2];
} WDRV_WINC_ECC_HANDSHAKE_INFO;

// *****************************************************************************
/*  Cipher Suite Context

  Summary:
    Cipher suite context structure.

  Description:
    This structure contains information about cipher suites.

  Remarks:
    None.

*/

typedef struct
{
    /* Bit mask of cipher suites. */
    uint32_t ciperSuites;
} WDRV_WINC_CIPHER_SUITE_CONTEXT;

// *****************************************************************************
/*  Set Cipher Suite List Callback

  Summary:
    Callback to report cipher suites.

  Description:
    Called when the cipher suites are changed.

  Parameters:
    handle              - Client handle obtained by a call to WDRV_WINC_Open.
    pSSLCipherSuiteCtx  - Pointer to cipher suite list.

  Returns:
    None.

  Remarks:
    None.

*/

typedef void (*WDRV_WINC_SSL_CIPHERSUITELIST_CALLBACK)
(
    DRV_HANDLE handle,
    WDRV_WINC_CIPHER_SUITE_CONTEXT *pSSLCipherSuiteCtx
);

// *****************************************************************************
/*  SSL Request ECC Info Callback

  Summary:
    Callback to request ECC information.

  Description:
    Called when authentication with ECC Cipher suites.

  Parameters:
    handle          - Client handle obtained by a call to WDRV_WINC_Open.
    reqType         - Request type.
    eccReqInfo      - ECC request info.
    pExtendInfo     - Extra information relevant to the request.

  Returns:
    None.

  Remarks:
    pExtendInfo contains information related to the type of request being made:

    if reqType is WDRV_WINC_ECC_REQ_CLIENT_ECDH or ECC_REQ_SERVER_ECDH the
      information is stored in a WDRV_WINC_ECDH_INFO structure pExtendInfo->ecdhInfo.

    If reqType is WDRV_WINC_ECC_REQ_GEN_KEY pExtendInfo is NULL.

    If reqType is WDRV_WINC_ECC_REQ_SIGN_GEN the information is stored in
      a WDRV_WINC_ECDSA_SIGN_REQ_INFO structure pExtendInfo->ecdsaSignReqInfo.

    If reqType is WDRV_WINC_ECC_REQ_SIGN_VERIFY the information is stored in
      a WDRV_WINC_ECDSA_VERIFY_REQ_INFO structure pExtendInfo->ecdsaVerifyReqInfo.

*/

typedef void (*WDRV_WINC_SSL_REQ_ECC_CALLBACK)
(
    DRV_HANDLE handle,
    WINC_WDRV_ECC_REQ_TYPE reqType,
    const WDRV_WINC_ECC_HANDSHAKE_INFO *const pHandshakeData,
    const WDRV_WINC_ECC_REQ_EX_INFO *const pEccReqExtendInfo
);

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver TLS/SSL Routines
// *****************************************************************************
// *****************************************************************************

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

  Precondition:
    None.

  Parameters:
    pSSLCipherSuiteCtx - Pointer to cipher suite context.

  Returns:
    WDRV_WINC_STATUS_OK          - The operation was performed.
    WDRV_WINC_STATUS_INVALID_ARG - The parameters were incorrect.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_SSLCTXDefault
(
    WDRV_WINC_CIPHER_SUITE_CONTEXT *pSSLCipherSuiteCtx
);

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

  Precondition:
    None.

  Parameters:
    pSSLCipherSuiteCtx  - Pointer to cipher suite context.
    pCipherSuiteList    - Pointer to list of cipher suites to enable.
    numCipherSuites     - Number of cipher suites to enable.

  Returns:
    WDRV_WINC_STATUS_OK          - The operation was performed.
    WDRV_WINC_STATUS_INVALID_ARG - The parameters were incorrect.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_SSLCTXCipherSuitesSet
(
    WDRV_WINC_CIPHER_SUITE_CONTEXT *pSSLCipherSuiteCtx,
    uint16_t *pCipherSuiteList,
    uint8_t numCipherSuites
);

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

  Precondition:
    None.

  Parameters:
    pSSLCipherSuiteCtx  - Pointer to cipher suite context.
    pCipherSuiteList    - Pointer to list of cipher suites to populate.
    maxNumCipherSuites  - Maximum number of cipher suites to populate in list.

  Returns:
    WDRV_WINC_STATUS_OK          - The operation was performed.
    WDRV_WINC_STATUS_INVALID_ARG - The parameters were incorrect.

  Remarks:
    None.

*/

uint8_t WDRV_WINC_SSLCTXCipherSuitesGet
(
    WDRV_WINC_CIPHER_SUITE_CONTEXT *pSSLCipherSuiteCtx,
    uint16_t *pCipherSuiteList,
    uint8_t maxNumCipherSuites
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_SSLActiveCipherSuitesSet
    (
        DRV_HANDLE handle,
        WDRV_WINC_CIPHER_SUITE_CONTEXT *pSSLCipherSuiteCtx,
        WDRV_WINC_SSL_CIPHERSUITELIST_CALLBACK pfSSLListCallback
    )

  Summary:
    Set the active cipher suites.

  Description:
    Passes the active cipher suite list to the WINC.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle             - Client handle obtained by a call to WDRV_WINC_Open.
    pSSLCipherSuiteCtx - Pointer to cipher suite context.
    pfSSLListCallback  - Pointer to callback function to receive updated list of
                           cipher suites.

  Returns:
    WDRV_WINC_STATUS_OK             - The operation was performed.
    WDRV_WINC_STATUS_NOT_OPEN       - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR  - The request to the WINC was rejected.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_SSLActiveCipherSuitesSet
(
    DRV_HANDLE handle,
    WDRV_WINC_CIPHER_SUITE_CONTEXT *pSSLCipherSuiteCtx,
    WDRV_WINC_SSL_CIPHERSUITELIST_CALLBACK pfSSLListCallback
);

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

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle             - Client handle obtained by a call to WDRV_WINC_Open.
    pfECCREQCallback   - Pointer to callback function to receive ECC request information from WINC
                           This value can be NULL if ECC is not required.

  Returns:
    WDRV_WINC_STATUS_OK             - The operation was performed.
    WDRV_WINC_STATUS_NOT_OPEN       - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_SSLECCReqCallbackSet
(
    DRV_HANDLE handle,
    WDRV_WINC_SSL_REQ_ECC_CALLBACK pfECCREQCallback
);

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

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle          - Client handle obtained by a call to WDRV_WINC_Open.
    reqType         - Request type being responded to.
    status          - Status of request operation.
    pHandshakeData  - Pointer to ECC handshake structure.
    pECDHRspInfo    - Pointer to ECDH response structure.
    pRspDataBuff    - Pointer of the response data to be sent.
    rspDataSz       - Response data size.

  Returns:
    WDRV_WINC_STATUS_OK             - The operation was performed.
    WDRV_WINC_STATUS_NOT_OPEN       - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR  - The operation is not success

  Remarks:
    pECDHRspInfo is only required when pEccRspInfo->reqCmd is:
        WDRV_WINC_ECC_REQ_CLIENT_ECDH
        WDRV_WINC_ECC_REQ_SERVER_ECDH
        WDRV_WINC_ECC_REQ_GEN_KEY

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
);

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

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle      - Client handle obtained by a call to WDRV_WINC_Open.
    pCurveType  - Pointer to the certificate curve type.
    pHash       - Pointer to the certificate hash.
    pSig        - Pointer to the certificate signature.
    pKey        - Pointer to the certificate Key.

  Returns:
    WDRV_WINC_STATUS_OK             - The operation was performed.
    WDRV_WINC_STATUS_NOT_OPEN       - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR  - The operation is not success

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_SSLRetrieveCert
(
    DRV_HANDLE handle,
    uint16_t *pCurveType,
    uint8_t *pHash,
    uint8_t *pSig,
    WDRV_WINC_EC_POINT_REP* pKey
);

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

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle  - Client handle obtained by a call to WDRV_WINC_Open.
    pHash   - Pointer to the certificate hash.
    hashSz  - Hash size.


  Returns:
    WDRV_WINC_STATUS_OK             - The operation was performed.
    WDRV_WINC_STATUS_NOT_OPEN       - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR  - The operation is not success

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_SSLRetrieveHash
(
    DRV_HANDLE handle,
    uint8_t *pHash,
    uint16_t hashSz
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_SSLStopRetrieveCert(DRV_HANDLE handle)

  Summary:
    Stop processing the certificate

  Description:
    Stop processing the certificate

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle  - Client handle obtained by a call to WDRV_WINC_Open.

  Returns:
    WDRV_WINC_STATUS_OK             - The operation was performed.
    WDRV_WINC_STATUS_NOT_OPEN       - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_SSLStopRetrieveCert(DRV_HANDLE handle);

#endif /* _WDRV_WINC_SSL_H */
