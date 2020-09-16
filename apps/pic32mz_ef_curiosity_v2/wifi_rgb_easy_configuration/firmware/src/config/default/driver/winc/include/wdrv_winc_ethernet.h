/*******************************************************************************
  WINC Driver Ethernet Mode Header File

  Company:
    Microchip Technology Inc.

  File Name:
    wdrv_winc_ethernet.h

  Summary:
    WINC wireless driver (Ethernet mode) header file.

  Description:
    This interface provides extra functionality required for Ethernet mode operation.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#ifndef _WDRV_WINC_ETHERNET_H
#define _WDRV_WINC_ETHERNET_H

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

#include "system_config.h"
#include "system_definitions.h"
#include "wdrv_winc.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus // Provide C++ Compatibility
    extern "C" {
#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: WINC Driver Ethernet Mode Routines
// *****************************************************************************
// *****************************************************************************

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_EthernetRecvPacket
    (
        DRV_HANDLE handle,
        uint8_t *const pEthBuf,
        uint16_t lengthEthBuf,
        const WDRV_WINC_ETH_MSG_RECV_CALLBACK pfEthMsgRecvCB
    )

  Summary:
    Provide a buffer for the next received Ethernet packet.

  Description:
    Provides a buffer and callback to the WINC. When the next Ethernet
      packet is received it will placed into this buffer and the callback
      signalled.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle         - Client handle obtained by a call to WDRV_WINC_Open.
    pEthBuf        - Pointer to buffer to store next packet in.
    lengthEthBuf   - Length of buffer provided.
    pfEthMsgRecvCB - Pointer to function to use as callback.

  Returns:
    WDRV_WINC_STATUS_OK             - The request has been accepted.
    WDRV_WINC_STATUS_NOT_OPEN       - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR  - The request to the WINC was rejected.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_EthernetRecvPacket
(
    DRV_HANDLE handle,
    uint8_t *const pEthBuf,
    uint16_t lengthEthBuf,
    const WDRV_WINC_ETH_MSG_RECV_CALLBACK pfEthMsgRecvCB
);

//*******************************************************************************
/*
  Function:
    WDRV_WINC_STATUS WDRV_WINC_EthernetSendPacket
    (
        DRV_HANDLE handle,
        const uint8_t *const pEthBuf,
        uint16_t lengthEthBuf
    )

  Summary:
    Sends an Ethernet packet.

  Description:
    Sends an Ethernet packet to the WINC for transmission.

  Precondition:
    WDRV_WINC_Initialize should have been called.
    WDRV_WINC_Open should have been called to obtain a valid handle.

  Parameters:
    handle       - Client handle obtained by a call to WDRV_WINC_Open.
    pEthBuf      - Pointer to buffer containing Ethernet packet.
    lengthEthBuf - Length of packet data in buffer provided.

  Returns:
    WDRV_WINC_STATUS_OK             - The request has been accepted.
    WDRV_WINC_STATUS_NOT_OPEN       - The driver instance is not open.
    WDRV_WINC_STATUS_INVALID_ARG    - The parameters were incorrect.
    WDRV_WINC_STATUS_REQUEST_ERROR  - The request to the WINC was rejected.

  Remarks:
    None.

*/

WDRV_WINC_STATUS WDRV_WINC_EthernetSendPacket
(
    DRV_HANDLE handle,
    const uint8_t *const pEthBuf,
    uint16_t lengthEthBuf
);

// DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
// DOM-IGNORE-END

#endif /* _WDRV_WINC_ETHERNET_H */
