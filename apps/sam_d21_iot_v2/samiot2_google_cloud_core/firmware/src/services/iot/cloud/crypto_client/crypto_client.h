/*
    \file   crypto_client.h

    \brief  Crypto Client header file.

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

#ifndef CRYPTO_CLIENT_H
#define CRYPTO_CLIENT_H

#define ERROR 1
#define NO_ERROR 0

#include <stdint.h>
#include "cryptoauthlib.h"

extern ATCAIfaceCfg cfg_ateccx08a_i2c_custom;
extern uint8_t cryptoDeviceInitialized;

uint8_t CRYPTO_CLIENT_createJWT(char* buf, size_t buflen, uint32_t ts, const char* projectId);
uint8_t CRYPTO_CLIENT_printPublicKey(char *s);
uint8_t CRYPTO_CLIENT_printSerialNumber(char *s);


#endif /* CRYPTO_CLIENT_H */
