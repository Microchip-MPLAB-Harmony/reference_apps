/*******************************************************************************
 Source file for the Net Pres Certificate Store functions to work with Harmony


  Summary:


  Description:

*******************************************************************************/

/*
Copyright (C) 2015-2023, Microchip Technology Inc., and its subsidiaries. All rights reserved.

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

#include "net_pres/pres/net_pres_certstore.h"
#define USE_CERT_BUFFERS_2048
#include "wolfssl/certs_test.h"
#define USE_CERT_BUFFERS_2048
#include "wolfssl/certs_test.h"
#include "wolfssl/certs_test.h"

bool NET_PRES_CertStoreGetCACerts(const uint8_t ** certPtr, int32_t * certSize, uint8_t certIndex)
{
    *certPtr = client_cert_der_2048;
    *certSize = sizeof_client_cert_der_2048;
    return true;
}
bool NET_PRES_CertStoreGetServerCert(const uint8_t ** serverCertPtr, int32_t * serverCertSize, const uint8_t ** serverKeyPtr, int32_t * serverKeySize, uint8_t certIndex)
{
    *serverCertPtr = server_cert_der_2048;
    *serverCertSize = sizeof_server_cert_der_2048;
    *serverKeyPtr = server_key_der_2048;
    *serverKeySize = sizeof_server_key_der_2048;
    return true;
}
