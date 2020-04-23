/*******************************************************************************
  WINC Wireless Driver

  File Name:
    wdrv_winc_stack_itf.c

  Summary:
    Stack interface to link MAC driver to TCP/IP stack.

  Description:
    Stack interface to link MAC driver to TCP/IP stack.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
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

#include "wdrv_winc_stack_drv.h"

const TCPIP_MAC_OBJECT WDRV_WINC_MACObject =
{
    TCPIP_MODULE_MAC_WINC,
    "WINC",
    WDRV_WINC_MACInitialize,
    WDRV_WINC_MACDeinitialize,
    WDRV_WINC_MACReinitialize,
    WDRV_WINC_MACStatus,
    WDRV_WINC_MACTasks,
    WDRV_WINC_MACOpen,
    WDRV_WINC_MACClose,
    WDRV_WINC_MACLinkCheck,
    WDRV_WINC_MACRxFilterHashTableEntrySet,
    WDRV_WINC_MACPowerMode,
    WDRV_WINC_MACPacketTx,
    WDRV_WINC_MACPacketRx,
    WDRV_WINC_MACProcess,
    WDRV_WINC_MACStatisticsGet,
    WDRV_WINC_MACParametersGet,
    WDRV_WINC_MACRegisterStatisticsGet,
    WDRV_WINC_MACConfigGet,
    WDRV_WINC_MACEventMaskSet,
    WDRV_WINC_MACEventAcknowledge,
    WDRV_WINC_MACEventPendingGet,
};

//DOM-IGNORE-END
