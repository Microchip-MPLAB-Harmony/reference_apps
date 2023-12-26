/*******************************************************************************
  RNBD451 click routine interface header file

  Company
    Microchip Technology Inc.

  File Name
    click_interface.h

  Summary
    rnbd451 click routine interface implementation File.

  Description
    This file defines the interface to the rnbd451 click routines.

  Remarks:
    None.

 *******************************************************************************/


// DOM-IGNORE-BEGIN
/*
    (c) 2024 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/
// DOM-IGNORE-END

#ifndef _CLICK_INTERFACES_H
#define _CLICK_INTERFACES_H

/**
  Section: Included Files
 */

#include <xc.h>
#include <stdint.h>
#include <rnbd/rnbd.h>
#include "rnbd/rnbd_interface.h"

//RNBD451 API
#define CLICK_RNBD451_Init                             RNBD_Init
#define CLICK_RNBD451_SetAsyncMessageHandler           RNBD_SetAsyncMessageHandler
#define CLICK_RNBD451_IsStreamopen                     RNBD_IsStreamopen
#define CLICK_RNBD451_IsOTABegin                       RNBD_IsOTABegin
#define CLICK_RNBD451_DataReady                        RNBD_DataReady
#define CLICK_RNBD451_Read                             RNBD_Read


#endif // _CLICK_INTERFACES_H
