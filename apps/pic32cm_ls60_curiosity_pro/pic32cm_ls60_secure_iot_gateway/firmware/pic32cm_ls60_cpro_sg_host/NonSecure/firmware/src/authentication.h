/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Microchip Technology Inc.

  @File Name
    authentication.h

  @Summary
    This header file provides prototypes and definitions for the functions related to symmetric authentication protocols

  @Description
    This files provides the definition of the MAC operation for authenticating the client device.
 */
/* ************************************************************************** */

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.
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
//DOM-IGNORE-END

#ifndef _EXAMPLE_FILE_NAME_H    /* Guard against multiple inclusion */
#define _EXAMPLE_FILE_NAME_H

#include "atca_devtypes.h"
#include "atca_iface.h"
#include <stdint.h>
#include <stdlib.h>
#include "cryptoauthlib.h"


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

#define SYMMETRIC_KEY_SLOT  (0x05)

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__XC32__)
extern ATCAIfaceCfg atecc608_0_init_data;
#endif

ATCAIfaceCfg *cfg;

ATCADeviceType get_device_type_id(uint8_t revision_byte);
ATCA_STATUS check_device_type_in_cfg(ATCAIfaceCfg* cfg, bool overwrite);
ATCA_STATUS RNG(uint8_t *dest, size_t size);
uint8_t slot_write(uint8_t slot_num);
ATCA_STATUS mac_compare(void);
uint8_t calculate_host_mac(void);
uint8_t generate_RNG();

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
