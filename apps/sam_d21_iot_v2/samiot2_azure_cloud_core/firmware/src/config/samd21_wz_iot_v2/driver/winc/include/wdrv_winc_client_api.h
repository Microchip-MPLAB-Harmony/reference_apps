/*******************************************************************************
  WINC Driver Client API Header File

  Company:
    Microchip Technology Inc.

  File Name:
    wdrv_winc_client_api.h

  Summary:
    WINC wireless driver client API header file.

  Description:
    This file pulls together the elements which make up the client API
      assoc       - Current association.
      bssfind     - BSS scan functionality.
      custie      - Custom IE management for Soft-AP.
      nvm         - Off line access the WINC SPI flash.
      powersave   - Power save control.
      socket      - TCP/IP sockets.
      softap      - Soft-AP mode.
      sta         - Infrastructure stations mode.
      systtime    - System time.
      ssl         - SSL configuration and management.
      ble         - BLE control (WINC3400)

 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
Copyright (C) 2019-22, Microchip Technology Inc., and its subsidiaries. All rights reserved.

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

#ifndef _WDRV_WINC_CLIENT_API_H
#define _WDRV_WINC_CLIENT_API_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include "configuration.h"

#include "wdrv_winc.h"
#include "wdrv_winc_bssfind.h"
#include "wdrv_winc_powersave.h"
#include "wdrv_winc_assoc.h"
#include "wdrv_winc_systime.h"
#include "wdrv_winc_softap.h"
#include "wdrv_winc_sta.h"
#include "wdrv_winc_common.h"
#include "wdrv_winc_custie.h"
#ifdef WDRV_WINC_NETWORK_MODE_SOCKET
#include "wdrv_winc_socket.h"
#include "wdrv_winc_ssl.h"
#endif
#ifdef WDRV_WINC_DEVICE_HOST_FILE_DOWNLOAD
#include "wdrv_winc_host_file.h"
#endif
#ifdef WDRV_WINC_ENABLE_BLE
#include "wdrv_winc_ble.h"
#endif
#include "wdrv_winc_nvm.h"
#ifdef WDRV_WINC_DEVICE_ENTERPRISE_CONNECT
#include "wdrv_winc_enterprise.h"
#endif

#endif /* _WDRV_WINC_CLIENT_API_H */
