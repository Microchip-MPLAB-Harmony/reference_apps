/*
    \file   crypto_client.c

    \brief  Crypto Client source file.

    (c) 2018 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip software and any
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party
    license terms applicable to your use of third party software (including open source software) that
    may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS
    FOR A PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS
    SOFTWARE.
*/
#include <stdio.h>
#include "../../../../cryptoauthlib/config/cryptoauthlib_config.h"
#include "../../../../cryptoauthlib/lib/jwt/atca_jwt.h"
#include "../../../../cryptoauthlib/lib/tls/atcatls.h"
#include "crypto_client.h"
#include "../cloud_service.h"

#ifndef ATCA_NO_HEAP
#error : This project uses CryptoAuthLibrary V2. Please add "ATCA_NO_HEAP" to toolchain symbols.
#endif

#ifndef ATCA_NO_POLL
#error : This project uses ATCA_NO_POLL option. Please add "ATCA_NO_POLL" to toolchain symbols.
#endif

#ifndef ATCA_HAL_I2C
#error : This project uses I2C interface. Please add "ATCA_HAL_I2C" to toolchain symbols.
#endif

#ifndef ATCA_PRINTF
#error : This project uses ATCA_debug_print. Please add "ATCA_PRINTF" to toolchain symbols.
#endif

const uint8_t public_key_x509_header[] = { 0x30, 0x59, 0x30, 0x13, 0x06, 0x07, 0x2A, 0x86,
    0x48, 0xCE, 0x3D, 0x02, 0x01, 0x06, 0x08, 0x2A,
    0x86, 0x48, 0xCE, 0x3D, 0x03, 0x01, 0x07, 0x03,
0x42, 0x00, 0x04 };

uint8_t g_serial_number[ATCA_SERIAL_NUM_SIZE];

/** \brief custom configuration for an ECCx08A device */
ATCAIfaceCfg cfg_ateccx08a_i2c_custom = {
    .iface_type             = ATCA_I2C_IFACE,
    .devtype                = ATECC608A,
    .atcai2c.slave_address  = 0xB0,
    .atcai2c.bus            = 2,
    .atcai2c.baud           = 100000,
    .wake_delay             = 1500,
    .rx_retries             = 20
};

uint8_t cryptoDeviceInitialized = false;
	
uint8_t CRYPTO_CLIENT_createJWT(char* buf, size_t buflen, uint32_t ts, const char* projectId)
{
    atca_jwt_t jwt;

   if (!cryptoDeviceInitialized)
   {
      return ERROR;
   }

    if(buf && buflen)
    {
        /* Build the JWT */
        if (ATCA_SUCCESS != atca_jwt_init(&jwt, buf, buflen))
        {
            return ERROR;
        }

        if (ATCA_SUCCESS != atca_jwt_add_claim_numeric(&jwt, "iat", ts))
        {
            return ERROR;
        }

        if (ATCA_SUCCESS != atca_jwt_add_claim_numeric(&jwt, "exp", ts +60*60)) // 1 hour
        {
            return ERROR;
        }

        if (ATCA_SUCCESS != atca_jwt_add_claim_string(&jwt, "aud", projectId))
        {
            return ERROR;
        }

        if (ATCA_SUCCESS != atca_jwt_finalize(&jwt, 0))
        {
            return ERROR;
        }
    }
    return NO_ERROR;
}

uint8_t CRYPTO_CLIENT_printPublicKey(char *s)
{
    char buf[128];
    uint8_t *tmp;
    size_t bufferLen = sizeof(buf);
    ATCA_STATUS retVal;
    
    if (ATCA_SUCCESS != atcab_init(&cfg_ateccx08a_i2c_custom))
    {
        return ERROR;
    }
    
    /* Calculate where the raw data will fit into the buffer */
    tmp = (uint8_t*)buf + sizeof(buf) - ATCA_PUB_KEY_SIZE - sizeof(public_key_x509_header);
    
    /* Copy the header */
    memcpy(tmp, public_key_x509_header, sizeof(public_key_x509_header));
    
    /* Get public key without private key generation */
    retVal = atcab_get_pubkey(0, tmp + sizeof(public_key_x509_header));
    
    if (ATCA_SUCCESS != retVal )
    {
        return ERROR;
    }
    
    /* Convert to base 64 */
    retVal = atcab_base64encode(tmp, ATCA_PUB_KEY_SIZE + sizeof(public_key_x509_header), buf, &bufferLen);
    
    if(ATCA_SUCCESS != retVal)
    {
        return ERROR;
    }
    
    /* Add a null terminator */
    buf[bufferLen] = 0;
    
    /* Print out the key */
    sprintf(s, "-----BEGIN PUBLIC KEY-----\r\n%s\r\n-----END PUBLIC KEY-----\r\n\4", buf);
    
    return NO_ERROR;
}

uint8_t CRYPTO_CLIENT_printSerialNumber(char *s)
{
    ATCA_STATUS status = ATCA_SUCCESS;
	uint8_t i = 0;

    ATCA_STATUS retVal = atcab_init(&cfg_ateccx08a_i2c_custom);

    if (ATCA_SUCCESS != retVal)
    {
        return retVal;
    }

    status = atcatls_get_sn(g_serial_number);

    if (status == ATCA_SUCCESS)
    {
        for (i = 0; i < ATCA_SERIAL_NUM_SIZE; i++)
        {
            sprintf(s, "%02X", g_serial_number[i]);
            s += 2;
        }
    }
    else{
        return ERROR;
    }

    return NO_ERROR;
}
