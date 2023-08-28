/* ************************************************************************** */
/** Descriptive File Name

  @Company
  Microchip Technology Inc

  @File Name
    security.h

  @Summary
  This header file provides prototypes and definitions for functions related to symmetric authentication protocols

  @Description
  This file includes the functions to initialize the crypto element and MAC calculation for the symmetric authentication.
 */
/* ************************************************************************** */

// DOM-IGNORE-BEGIN
/*
    (c) 2021 Microchip Technology Inc. and its subsidiaries. You may use this
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

#ifndef _EXAMPLE_FILE_NAME_H    /* Guard against multiple inclusion */
#define _EXAMPLE_FILE_NAME_H

#include "atca_iface.h"
#include "atca_status.h"


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__XC32__)
extern ATCAIfaceCfg atecc608_0_init_data;
#endif

ATCADeviceType get_device_type_id(uint8_t revision_byte);
ATCA_STATUS check_device_type_in_cfg(ATCAIfaceCfg* cfg, bool overwrite);
uint8_t generate_device_mac(void);
void RNG(uint8_t *dest, size_t size);
uint8_t calculate_host_mac(void);
uint8_t slot_write(uint8_t slot_num);

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
