/*******************************************************************************
  Microchip TCP/IP Stack Include File

  Company:
    Microchip Technology Inc.
    
  File Name:
    tcpip_private.h.ftl

  Summary:
   Private include file for the TCPIP stack

  Description:
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*
Copyright (C) 2016-2023, Microchip Technology Inc., and its subsidiaries. All rights reserved.

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

#ifndef __TCPIP_STACK_PRIVATE_H__
#define __TCPIP_STACK_PRIVATE_H__

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
        
#include "device.h"
#include "system_config.h"
#include "system/debug/sys_debug.h"
#include "system/sys_random_h2_adapter.h"
#include "system/sys_time_h2_adapter.h"

#include "osal/osal.h"

#include "tcpip/src/common/helpers.h"



// Internal adjustments - dependencies
// change signaling depends on the IPv4
#if defined(TCPIP_STACK_USE_IPV4) && (TCPIP_STACK_INTERFACE_CHANGE_SIGNALING != 0)
#define _TCPIP_STACK_INTERFACE_CHANGE_SIGNALING     1
#else
#define _TCPIP_STACK_INTERFACE_CHANGE_SIGNALING     0
#endif  // defined(TCPIP_STACK_USE_IPV4)

// alias interface support depends on IPv4
#if defined(TCPIP_STACK_USE_IPV4) && (TCPIP_STACK_ALIAS_INTERFACE_SUPPORT != 0)
#define _TCPIP_STACK_ALIAS_INTERFACE_SUPPORT     1
#else
#define _TCPIP_STACK_ALIAS_INTERFACE_SUPPORT     0
#endif  // defined(TCPIP_STACK_USE_IPV4) && (TCPIP_STACK_ALIAS_INTERFACE_SUPPORT != 0)

// debug symbols

#define _TCPIP_STACK_DEBUG_MASK_BASIC       0x01    // enable the _TCPIPStack_Assert and _TCPIPStack_Condition calls
#define _TCPIP_STACK_ENABLE_ASSERT_LOOP     0       // if !0, then an assert call will loop forever 
                                                    // should be 0 for a release build
#define _TCPIP_STACK_ENABLE_COND_LOOP       0       // if !0, then an condition call will loop forever 
                                                    // should be 0 for a release build

// enabled debugging masks 
#define _TCPIP_STACK_DEBUG_LEVEL            (_TCPIP_STACK_DEBUG_MASK_BASIC)  // usually the basic debugging is enabled so asserts are not ignored


// assert and condition functions that all stack modules could use
#if ((_TCPIP_STACK_DEBUG_LEVEL & _TCPIP_STACK_DEBUG_MASK_BASIC) != 0)
void _TCPIPStack_Assert(bool cond, const char* fileName, const char* funcName, int lineNo);
void _TCPIPStack_Condition(bool cond, const char* fileName, const char* funcName, int lineNo);
#else
#define _TCPIPStack_Assert(cond, fileName, funcName, lineNo)
#define _TCPIPStack_Condition(cond, fileName, funcName, lineNo)
#endif  // ((_TCPIP_STACK_DEBUG_LEVEL & _TCPIP_STACK_DEBUG_MASK_BASIC) != 0)


// public module interface
#include "tcpip/tcpip.h"

#include "tcpip/src/tcpip_types.h"
#include "tcpip/src/link_list.h"
#include "tcpip/src/tcpip_heap_alloc.h"

#include "tcpip/tcpip_mac_object.h"

// private stack manager interface
#include "tcpip/src/tcpip_manager_control.h"

#include "tcpip/src/tcpip_announce_manager.h"
#include "tcpip/src/ndp_manager.h"
#include "tcpip/src/ipv4_manager.h"
#include "tcpip/src/ipv6_manager.h"
#include "tcpip/src/icmpv6_manager.h"
#include "tcpip/src/dhcpv6_manager.h"
#include "tcpip/src/icmp_manager.h"
#include "tcpip/src/dhcp_manager.h"
#include "tcpip/src/arp_manager.h"
#include "tcpip/src/dns_manager.h"
#include "tcpip/src/tcp_manager.h"
#include "tcpip/src/nbns_manager.h"
#include "tcpip/src/http_net_manager.h"
#include "tcpip/src/tcpip_commands_manager.h"
#include "tcpip/src/udp_manager.h"
#include "tcpip/src/sntp_manager.h"
#include "tcpip/src/lldp_manager.h"
#include "tcpip/src/smtpc_manager.h"
#include "tcpip/src/tcpip_packet.h"
#include "tcpip/src/tcpip_helpers_private.h"
#include "tcpip/src/oahash.h"
#include "tcpip/src/hash_fnv.h"
#include "tcpip/src/tcpip_notify.h"

#endif  // __TCPIP_STACK_PRIVATE_H__
