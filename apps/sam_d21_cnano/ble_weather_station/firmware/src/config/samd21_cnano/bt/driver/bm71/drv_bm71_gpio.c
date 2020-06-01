/*******************************************************************************
  BM71 Bluetooth Static Driver implementation

  Company:
    Microchip Technology Inc.

  File Name:
    drv_bm71_gpio.c

  Summary:
   BM71 Bluetooth Static Driver source file for GPIO functions.

  Description:
    This file is the implementation of the internal functions of the BM71
    driver related to the GPIO pins controlling the BM71.
 
*******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "bt/driver/bm71/drv_bm71_gpio.h"
#include "definitions.h"

// STBYRST must be defined in the Pin Manager as connected to the RST_N pin of the BM71,
// as an output normally high

void DRV_BM71_RESET_SetHigh(void)
{
    STBYRST_Set();
}

void DRV_BM71_RESET_SetLow(void)
{   
    STBYRST_Clear();    
}

void DRV_BM71_RESET_Toggle(void)
{
    STBYRST_Toggle();   
}

uint32_t DRV_BM71_RESET_GetValue(void)
{
    return STBYRST_Get();
}
