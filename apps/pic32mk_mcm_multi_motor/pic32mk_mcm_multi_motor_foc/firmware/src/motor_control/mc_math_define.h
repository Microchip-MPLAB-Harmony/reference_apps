/*******************************************************************************
 Motor Control Generic Library interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_math_define.h

  Summary:
    Motor control generic definitions of constants.

  Description:
    This file contains the generic definitions of constants.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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


#ifndef _MC_MATH_DEFINE_H
#define _MC_MATH_DEFINE_H


#define     M_PI                                    (float)3.14159265358979323846
#define     M_TWO_PI                                (float)6.28318530717958647693
#define     M_PI_OVER_2                             (float)1.57079632679489661923

#define     SQRT3                                   (float)(1.732)
#define     SQRT3_BY2                               (float)(0.866025403788)

#define     ONE_BY_SQRT3                            (float)(0.5773502691)
#define     TWO_BY_SQRT3                            (float)(1.1547005384)

#define     SINGLE_ELEC_ROT_RADS_PER_SEC            ((float)((float)(2.0) * (float)M_PI))


#ifdef __cplusplus
}
#endif

#endif /* end of _MC_MATH_DEFINE_H */

/*******************************************************************************
 End of File
*/
