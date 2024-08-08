/*******************************************************************************
  Oled c Header file

  Company:
    Microchip Technology Inc.

  File Name:
    oled_c.h

  Summary:
    This file contains the "oled c" function header and constant Definitions 
 * 
  Description:
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
// ----------------------------------------------------------------------------

#ifndef OLED_C_H
#define OLED_C_H
#include <stdio.h>
#include "definitions.h"

void oled_c_initialize(void);
void oled_c_Text_Field_counter(uint8_t counter);
void oled_c_Text_Field_light(uint16_t temp);
void oled_c_Image_mchplogo_visible(void);
void oled_c_Image_mchplogo_invisible(void);
void oled_c_Image_secure_visible(void);
void oled_c_Image_secure_invisible(void);
void oled_c_Image_nonsecure_visible(void);
void oled_c_Image_nonsecure_invisible(void);
void oled_c_dispaly_refresh(void);

#endif  