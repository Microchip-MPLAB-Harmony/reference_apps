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
     .macId = TCPIP_MODULE_MAC_WINC,
    .macType = TCPIP_MAC_TYPE_WLAN,
    .macName= "WINC",
    .TCPIP_MAC_Initialize = WDRV_WINC_MACInitialize,
    .TCPIP_MAC_Deinitialize = WDRV_WINC_MACDeinitialize,
    .TCPIP_MAC_Reinitialize =WDRV_WINC_MACReinitialize,
   .TCPIP_MAC_Status                   =WDRV_WINC_MACStatus,
    .TCPIP_MAC_Tasks                    =WDRV_WINC_MACTasks,
    .TCPIP_MAC_Open                     =WDRV_WINC_MACOpen,
    .TCPIP_MAC_Close                    =WDRV_WINC_MACClose,
    .TCPIP_MAC_LinkCheck                =WDRV_WINC_MACLinkCheck,
    .TCPIP_MAC_RxFilterHashTableEntrySet =WDRV_WINC_MACRxFilterHashTableEntrySet,
    .TCPIP_MAC_PowerMode                =WDRV_WINC_MACPowerMode,
    .TCPIP_MAC_PacketTx                 =WDRV_WINC_MACPacketTx,
    .TCPIP_MAC_PacketRx                 =WDRV_WINC_MACPacketRx,
    .TCPIP_MAC_Process                  =WDRV_WINC_MACProcess,
    .TCPIP_MAC_StatisticsGet            =WDRV_WINC_MACStatisticsGet,
    .TCPIP_MAC_ParametersGet            =WDRV_WINC_MACParametersGet,
    .TCPIP_MAC_RegisterStatisticsGet    =WDRV_WINC_MACRegisterStatisticsGet,
    .TCPIP_MAC_ConfigGet                =WDRV_WINC_MACConfigGet,
    .TCPIP_MAC_EventMaskSet             =WDRV_WINC_MACEventMaskSet,
    .TCPIP_MAC_EventAcknowledge         =WDRV_WINC_MACEventAcknowledge,
    .TCPIP_MAC_EventPendingGet          =WDRV_WINC_MACEventPendingGet,
};

//DOM-IGNORE-END
