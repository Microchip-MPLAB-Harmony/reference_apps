/*******************************************************************************
  WINC Driver Debugging Header File

  Company:
    Microchip Technology Inc.

  File Name:
    wdrv_winc_debug.h

  Summary:
    WINC wireless driver debug header file.

  Description:
    Provides methods to send formatted debugging information.
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

#ifndef _WDRV_WINC_DEBUG_H
#define _WDRV_WINC_DEBUG_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

#include "configuration.h"
#include "definitions.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus // Provide C++ Compatibility
    extern "C" {
#endif
// DOM-IGNORE-END

#ifndef WDRV_WINC_DEVICE_USE_SYS_DEBUG
// *****************************************************************************
/*  Debug Callback

  Summary:
    Defines the debug callback.

  Description:
    The function callback provides a printf-like prototype.

  Remarks:
    None.
*/

typedef void (*WDRV_WINC_DEBUG_PRINT_CALLBACK)(const char*, ...);

// *****************************************************************************
/*  Debug Levels

  Summary:
    Defines for debugging verbosity level.

  Description:
    These defines can be assigned to WDRV_WINC_DEBUG_LEVEL to affect the level of
      verbosity provided by the debug output channel.

  Remarks:
    None.
*/

#define WDRV_WINC_DEBUG_TYPE_NONE       0
#define WDRV_WINC_DEBUG_TYPE_ERROR      1
#define WDRV_WINC_DEBUG_TYPE_INFORM     2
#define WDRV_WINC_DEBUG_TYPE_TRACE      3
#define WDRV_WINC_DEBUG_TYPE_VERBOSE    4

// *****************************************************************************
/*  Debug Verbosity

  Summary:
    Defines the chosen level of debugging verbosity supported.

  Description:
    This define set the debugging output verbosity level.

  Remarks:
    None.
*/

#ifndef WDRV_WINC_DEBUG_LEVEL
#define WDRV_WINC_DEBUG_LEVEL   WDRV_WINC_DEBUG_TYPE_TRACE
#endif

// *****************************************************************************
/*  Debugging Macros

  Summary:
    Macros to define debugging output.

  Description:
    Macros are provided for each level of verbosity.

  Remarks:
    None.
*/

#define WDRV_DBG_VERBOSE_PRINT(...)
#define WDRV_DBG_TRACE_PRINT(...)
#define WDRV_DBG_INFORM_PRINT(...)
#define WDRV_DBG_ERROR_PRINT(...)

#if (WDRV_WINC_DEBUG_LEVEL >= WDRV_WINC_DEBUG_TYPE_ERROR)
#undef WDRV_DBG_ERROR_PRINT
#define WDRV_DBG_ERROR_PRINT(...) do { if (NULL != pfWINCDebugPrintCb) { pfWINCDebugPrintCb(__VA_ARGS__); } } while (0)
#if (WDRV_WINC_DEBUG_LEVEL >= WDRV_WINC_DEBUG_TYPE_INFORM)
#undef WDRV_DBG_INFORM_PRINT
#define WDRV_DBG_INFORM_PRINT(...) do { if (NULL != pfWINCDebugPrintCb) { pfWINCDebugPrintCb(__VA_ARGS__); } } while (0)
#if (WDRV_WINC_DEBUG_LEVEL >= WDRV_WINC_DEBUG_TYPE_TRACE)
#undef WDRV_DBG_TRACE_PRINT
#define WDRV_DBG_TRACE_PRINT(...) do { if (NULL != pfWINCDebugPrintCb) { pfWINCDebugPrintCb(__VA_ARGS__); } } while (0)
#if (WDRV_WINC_DEBUG_LEVEL >= WDRV_WINC_DEBUG_TYPE_VERBOSE)
#undef WDRV_DBG_VERBOSE_PRINT
#define WDRV_DBG_VERBOSE_PRINT(...) do { if (NULL != pfWINCDebugPrintCb) { pfWINCDebugPrintCb(__VA_ARGS__); } } while (0)
#endif /* WDRV_WINC_DEBUG_TYPE_VERBOSE */
#endif /* WDRV_WINC_DEBUG_TYPE_TRACE */
#endif /* WDRV_WINC_DEBUG_TYPE_INFORM */
#endif /* WDRV_WINC_DEBUG_TYPE_ERROR */

// Reference debug output channel printf-like function.
extern WDRV_WINC_DEBUG_PRINT_CALLBACK pfWINCDebugPrintCb;
#else
#define WDRV_DBG_VERBOSE_PRINT(...)         do { SYS_DEBUG_PRINT(SYS_ERROR_DEBUG, __VA_ARGS__); } while (0)
#define WDRV_DBG_TRACE_PRINT(...)           do { SYS_DEBUG_PRINT(SYS_ERROR_INFO, __VA_ARGS__); } while (0)
#define WDRV_DBG_INFORM_PRINT(...)          do { SYS_DEBUG_PRINT(SYS_ERROR_WARNING, __VA_ARGS__); } while (0)
#define WDRV_DBG_ERROR_PRINT(...)           do { SYS_DEBUG_PRINT(SYS_ERROR_ERROR, __VA_ARGS__); } while (0)

#endif

// Function to receive MAC RX packets for inspection
//#define WDRV_WINC_MAC_RX_PKT_INSPECT_HOOK

// Function to receive MAC TX packets for inspection
//#define WDRV_WINC_MAC_TX_PKT_INSPECT_HOOK

#ifdef WDRV_WINC_MAC_RX_PKT_INSPECT_HOOK
void WDRV_WINC_MAC_RX_PKT_INSPECT_HOOK(const TCPIP_MAC_PACKET *const ptrPacket);
#endif

#ifdef WDRV_WINC_MAC_TX_PKT_INSPECT_HOOK
void WDRV_WINC_MAC_TX_PKT_INSPECT_HOOK(const TCPIP_MAC_PACKET *const ptrPacket);
#endif

// DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
// DOM-IGNORE-END

#endif /* _WDRV_WINC_DEBUG_H */
