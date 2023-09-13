/*******************************************************************************
  File Name:
    m2m_ssl.h

  Summary:

  Description:
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

/** @defgroup SSLAPI SSL
    @brief
        Provides a description of the SSL Layer.
    @{
        @defgroup SSLCallbacks Callbacks
        @brief
            Provides detail on the available callbacks for the SSL Layer.

        @defgroup SSLEnums Enumerations and Typedefs
        @brief
            Specifies the enums and Data Structures used by the SSL APIs.

        @defgroup SSLFUNCTIONS Functions
        @brief
            Provides detail on the available APIs for the SSL Layer.
    @}
*/

#ifndef __M2M_SSL_H__
#define __M2M_SSL_H__

/*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
INCLUDES
*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*/

#include "nm_common.h"
#include "m2m_types.h"
#include "nmdrv.h"
#include "ecc_types.h"
#include "socket.h"

/*!
@ingroup    SSLCallbacks
@typedef    void (*tpfAppSSLCb)(uint8_t u8MsgType, void* pvMsg);
@brief      A callback to get SSL notifications.
@param[in]  u8MsgType
                The type of the message received.
@param[in]  pvMsg
                A structure to provide notification payload.
*/
typedef void (*tpfAppSSLCb) (uint8_t u8MsgType, void * pvMsg);

/*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
FUNCTION PROTOTYPES
*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*/

/*!
@ingroup    SSLFUNCTIONS
@fn         int8_t m2m_ssl_init(tpfAppSSLCb pfAppSSLCb);
@brief      Initializes the SSL layer.
@param[in]  pfAppSSLCb
                Application SSL callback function.
@return     The function returns @ref M2M_SUCCESS for success and a negative value otherwise.
*/
int8_t m2m_ssl_init(tpfAppSSLCb pfAppSSLCb);

/*!
@ingroup    SSLFUNCTIONS
@fn         int8_t m2m_ssl_handshake_rsp(tstrEccReqInfo* strECCResp, uint8_t* pu8RspDataBuff, uint16_t u16RspDataSz);
@brief      Sends ECC responses to the WINC
@param[in]  strECCResp
                ECC Response struct.
@param[in]  pu8RspDataBuff
                Pointer of the response data to be sent.
@param[in]  u16RspDataSz
                Response data size.
@return     The function returns @ref M2M_SUCCESS for success and a negative value otherwise.
*/
int8_t m2m_ssl_handshake_rsp(tstrEccReqInfo* strECCResp, uint8_t* pu8RspDataBuff, uint16_t u16RspDataSz);

/*!
@ingroup    SSLFUNCTIONS
@fn         int8_t m2m_ssl_send_certs_to_winc(uint8_t* pu8Buffer, uint32_t u32BufferSz);
@brief      Sends certificates to the WINC
@param[in]  pu8Buffer
                Pointer to the certificates.
@param[in]  u32BufferSz
                Size of the certificates.
@return     The function returns @ref M2M_SUCCESS for success and a negative value otherwise.
*/
int8_t m2m_ssl_send_certs_to_winc(uint8_t* pu8Buffer, uint32_t u32BufferSz);

/*!
@ingroup    SSLFUNCTIONS
@fn         int8_t m2m_ssl_retrieve_cert(uint16_t* pu16CurveType, uint8_t* pu8Hash, uint8_t* pu8Sig, tstrECPoint* pu8Key);
@brief      Retrieve the certificate to be verified from the WINC
@param[in]  pu16CurveType
                Pointer to the certificate curve type.
@param[in]  pu8Hash
                Pointer to the certificate hash.
@param[in]  pu8Sig
                Pointer to the certificate signature.
@param[in]  pu8Key
                Pointer to the certificate Key.
@return     The function returns @ref M2M_SUCCESS for success and a negative value otherwise.
*/
int8_t m2m_ssl_retrieve_cert(uint16_t* pu16CurveType, uint8_t* pu8Hash, uint8_t* pu8Sig, tstrECPoint* pu8Key);

/*!
@ingroup    SSLFUNCTIONS
@fn         int8_t m2m_ssl_retrieve_hash(uint8_t* pu8Hash, uint16_t u16HashSz);
@brief      Retrieve the certificate hash.
@param[in]  pu8Hash
                Pointer to the certificate hash.
@param[in]  u16HashSz
                Hash size.
@return     The function returns @ref M2M_SUCCESS for success and a negative value otherwise.
*/
int8_t m2m_ssl_retrieve_hash(uint8_t* pu8Hash, uint16_t u16HashSz);

/*!
@ingroup    SSLFUNCTIONS
@fn         void m2m_ssl_stop_processing_certs(void);
@brief      Allow SSL driver to tidy up in case application does not read all available certificates.
@warning    This API must only be called if some certificates are left unread.
@return     None.
*/
void m2m_ssl_stop_processing_certs(void);

/*!
@ingroup    SSLFUNCTIONS
@fn         void m2m_ssl_ecc_process_done(void);
@brief      Allow SSL driver to tidy up after application has finished processing ECC message.
@warning    This API must be called after receiving a SSL callback with message type @ref M2M_SSL_REQ_ECC.
@return     None.
*/
void m2m_ssl_ecc_process_done(void);

/*!
@ingroup    SSLFUNCTIONS
@fn         int8_t m2m_ssl_set_active_ciphersuites(uint32_t u32SslCsBMP);
@brief      Sets the active ciphersuites.
@details    Override the default Active SSL ciphers in the SSL module with a certain combination selected by
            the caller in the form of a bitmap containing the required ciphers to be on.\n
            There is no need to call this function if the application will not change the default ciphersuites.
@param[in]  u32SslCsBMP
                Bitmap containing the desired ciphers to be enabled for the SSL module. The ciphersuites are defined in
                @ref SSLCipherSuiteID.
                The default ciphersuites are all ciphersuites supported by the firmware with the exception of ECC ciphersuites.
                The caller can override the default with any desired combination, except for combinations involving both RSA
                and ECC; if any RSA ciphersuite is enabled, then firmware will disable all ECC ciphersuites.
                If u32SslCsBMP does not contain any ciphersuites supported by firmware, then the current active list will not
                change.

@return
            - @ref SOCK_ERR_NO_ERROR
            - @ref SOCK_ERR_INVALID_ARG
*/
int8_t m2m_ssl_set_active_ciphersuites(uint32_t u32SslCsBMP);

#endif /* __M2M_SSL_H__ */