/*******************************************************************************
  SVPWM algorithm file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_svpwm.h

  Summary:
    Header file for functions of SVPWM algorithm.

  Description:
    This file contains the data structures and function prototypes of SVPWM.

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
#ifndef _MC_SVPWM_H
#define _MC_SVPWM_H



/*******************************************************************************
Headers inclusions
 *******************************************************************************/
#include <stdint.h>   
#include "mc_foc.h"
#include <stdbool.h>
#include "hal_pwm.h" 
#include "mc_foc.h"
#include "mc_math_define.h"

#ifdef __cplusplus
extern "C" {
#endif




// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
typedef struct
{
    uint32_t    period;
    uint32_t    neutralPWM;
    uint32_t    dPwm1;
    uint32_t    dPwm2;
    uint32_t    dPwm3;
    bool        enableSVPWM;
} MC_SVPWM_T;




void MC_SvpwmInitial(MC_SVPWM_T * const svm);



/* All voltage unit is PU based on Vdc, time unis is PU based on pwm period */
__STATIC_INLINE void MC_SvpwmGenerate( const MC_CLARK_TRANSFORM_T * const vAlphaBeta, MC_SVPWM_T * const svm )
{
    float Va, Vb, Vc;
    float Vmax, Vmin, T_offset, T_effective;

    
    Va = vAlphaBeta->alphaAxis;
    Vb = -vAlphaBeta->alphaAxis/2 + vAlphaBeta->betaAxis*SQRT3_BY2;
    Vc = -Va - Vb;
  
    
    if (Va > Vb)      
    {
      Vmax = Va;
      Vmin = Vb;
    }
    else
    {
      Vmax = Vb;
      Vmin = Va;
    }

    if (Vc > Vmax)
    {
      Vmax = Vc;
    }
    else if (Vc < Vmin)
    {
      Vmin = Vc;
    }
    else
      ;

    T_effective = Vmax - Vmin;

    T_offset = (1.0 - T_effective)/2 - Vmin;

    if(T_effective > 1.0)  // Overmodulation Situation;
    {
      Va /= T_effective; 
      Vb /= T_effective; 
      Vc /= T_effective;

      //Due to T0 is zero; 
      T_offset = -Vmin/T_effective;
    }

    svm->dPwm1 = (uint32_t)(svm->period * (Va +T_offset));
    svm->dPwm2 = (uint32_t)(svm->period * (Vb +T_offset));
    svm->dPwm3 = (uint32_t)(svm->period * (Vc +T_offset));



}

#ifdef __cplusplus
}
#endif

#endif /* end of _MC_SVPWM_H */

/*******************************************************************************
 End of File
*/
