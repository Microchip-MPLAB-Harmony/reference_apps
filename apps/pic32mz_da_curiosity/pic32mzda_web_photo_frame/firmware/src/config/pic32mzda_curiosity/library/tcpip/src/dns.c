/*******************************************************************************
  Domain Name System (DNS) Client 
  Module for Microchip TCP/IP Stack

  Summary:
    DNS client implementation file
    
  Description:
    This source file contains the functions of the 
    DNS client routines
    
    Provides  hostname to IP address translation
    Reference: RFC 1035
*******************************************************************************/

/*
Copyright (C) 2012-2023, Microchip Technology Inc., and its subsidiaries. All rights reserved.

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

#include "tcpip/src/tcpip_private.h"

bool TCPIP_DNS_IsEnabled(TCPIP_NET_HANDLE hNet){return false;}
bool TCPIP_DNS_Enable(TCPIP_NET_HANDLE hNet, TCPIP_DNS_ENABLE_FLAGS flags){return false;}
bool TCPIP_DNS_Disable(TCPIP_NET_HANDLE hNet, bool clearCache){return false;}

TCPIP_DNS_RESULT  TCPIP_DNS_Resolve(const char* HostName, TCPIP_DNS_RESOLVE_TYPE Type)
{
    return TCPIP_DNS_RES_NO_SERVICE; 
}

TCPIP_DNS_RESULT  TCPIP_DNS_IsResolved(const char* hostName, IP_MULTI_ADDRESS* hostIP, IP_ADDRESS_TYPE type)
{
    return TCPIP_DNS_RES_NO_SERVICE; 
}

TCPIP_DNS_RESULT  TCPIP_DNS_IsNameResolved(const char* hostName, IPV4_ADDR* hostIPv4, IPV6_ADDR* hostIPv6)
{
    return TCPIP_DNS_RES_NO_SERVICE; 
}

TCPIP_DNS_RESULT TCPIP_DNS_RemoveEntry(const char *hostName)
{
    return TCPIP_DNS_RES_NO_SERVICE;
}

TCPIP_DNS_RESULT TCPIP_DNS_RemoveAll(void)
{
    return TCPIP_DNS_RES_NO_SERVICE;
}

TCPIP_DNS_RESULT TCPIP_DNS_ClientInfoGet(TCPIP_DNS_CLIENT_INFO* pClientInfo)
{
    return TCPIP_DNS_RES_NO_SERVICE;
}

TCPIP_DNS_RESULT TCPIP_DNS_EntryQuery(TCPIP_DNS_ENTRY_QUERY *pDnsQuery, int queryIndex)
{
    return TCPIP_DNS_RES_NO_SERVICE;
}


