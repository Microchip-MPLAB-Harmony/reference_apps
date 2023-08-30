/*******************************************************************************
 Header file for the wolfSSL glue functions to work with Harmony


  Summary:


  Description:

*******************************************************************************/

/*
Copyright (C) 2013-2023, Microchip Technology Inc., and its subsidiaries. All rights reserved.

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


#ifndef _NET_TLS_WOLFSSL_GLUE_H_
#define _NET_TLS_WOLFSSL_GLUE_H_

#include "configuration.h"
#include "net_pres/pres/net_pres.h"
#include "net_pres/pres/net_pres_encryptionproviderapi.h"
#ifdef __CPLUSPLUS
extern "C" {
#endif
extern NET_PRES_EncProviderObject net_pres_EncProviderStreamServer0;
extern NET_PRES_EncProviderObject net_pres_EncProviderStreamClient0;
bool NET_PRES_EncProviderStreamServerInit0(struct _NET_PRES_TransportObject * transObject);
bool NET_PRES_EncProviderStreamServerDeinit0(void);
bool NET_PRES_EncProviderStreamServerOpen0(uintptr_t transHandle, void * providerData);
bool NET_PRES_EncProviderStreamServerIsInited0(void);
bool NET_PRES_EncProviderStreamClientInit0(struct _NET_PRES_TransportObject * transObject);
bool NET_PRES_EncProviderStreamClientDeinit0(void);
bool NET_PRES_EncProviderStreamClientOpen0(uintptr_t transHandle, void * providerData);
bool NET_PRES_EncProviderStreamClientIsInited0(void);
NET_PRES_EncSessionStatus NET_PRES_EncProviderServerAccept0(void * providerData);
NET_PRES_EncSessionStatus NET_PRES_EncProviderClientConnect0(void * providerData);
NET_PRES_EncSessionStatus NET_PRES_EncProviderConnectionClose0(void * providerData);
int32_t NET_PRES_EncProviderWrite0(void * providerData, const uint8_t * buffer, uint16_t size);
uint16_t  NET_PRES_EncProviderWriteReady0(void * providerData, uint16_t reqSize, uint16_t minSize);
int32_t NET_PRES_EncProviderRead0(void * providerData, uint8_t * buffer, uint16_t size);
int32_t NET_PRES_EncProviderReadReady0(void * providerData);
int32_t NET_PRES_EncProviderPeek0(void * providerData, uint8_t * buffer, uint16_t size);
int32_t NET_PRES_EncProviderOutputSize0(void * providerData, int32_t inSize);
int32_t NET_PRES_EncProviderMaxOutputSize0(void * providerData);
#ifdef __CPLUSPLUS
}
#endif
#endif //_NET_TLS_WOLFSSL_GLUE_H_
