/*******************************************************************************
  PI Controller Source File

  Company:
    Microchip Technology Inc.

  File Name:
     mc_pid_control.h

  Summary:
   Header file for PI controller functions

  Description:
    This file contains the data structures and function prototypes used by
   PI controller module.

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

#ifndef _MC_PID_CONTROLLER_H
#define _MC_PID_CONTROLLER_H



/*******************************************************************************
Headers inclusions
 *******************************************************************************/
#include <stdint.h>   
#include "device.h"

#ifdef __cplusplus
extern "C" {
#endif




#define     PID_CURRENTR_OUTMAX_MC1          (float)(0.577)  //PU, Must Less than 1/sqrt3, when Don't support Overmodulation;If OverMod is supported, 2/3 is Max;
#define     PID_CURRENTR_OUTMAX_MC2          (float)(0.577)  //PU, Must Less than 1/sqrt3, when Don't support Overmodulation;If OverMod is supported, 2/3 is Max;
#define     PID_CURRENTR_OUTMAX_MC3          (float)(0.577)  //PU, Must Less than 1/sqrt3, when Don't support Overmodulation;If OverMod is supported, 2/3 is Max;


// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
typedef struct
{
    float   dSum;
    float   kp;
    float   ki;
    float   kd;
    float   kc;
    float   outMax;
    float   outMin;
    float   inRef;
    float   inMeas;
    float   out;
} MC_PID_CONTROLLER_T;
 


// *****************************************************************************
// *****************************************************************************
// Section: Function Declarations
// *****************************************************************************
// *****************************************************************************

void MC_PidReset(MC_PID_CONTROLLER_T * const pPID);
void MC_PidSetCoefficients(MC_PID_CONTROLLER_T * const pPID, float Kp, float Ki, float Kc);

__STATIC_INLINE void MC_PidRun( MC_PID_CONTROLLER_T * const pPID)
{
    float err;
    float out;
    float exc;

    err  = pPID->inRef - pPID->inMeas;
    out  = pPID->dSum + pPID->kp * err;

    /* Limit checking for PI output */
    if( out > pPID->outMax )
    {
       pPID->out = pPID->outMax;
    }
    else if( out < pPID->outMin )
    {
       pPID->out = pPID->outMin;
    }
    else
    {
       pPID->out = out;
    }

    exc = out - pPID->out;
    pPID->dSum = pPID->dSum + pPID->ki * err - pPID->kc * exc;
}

__STATIC_INLINE void MC_PidSetLimitation(MC_PID_CONTROLLER_T * const pPID, float Max, float Min)
{

    pPID->outMax = Max;
    pPID->outMin = Min;
}

#ifdef __cplusplus
}
#endif

#endif /* end of _MC_PID_CONTROLLER_H */    

/*******************************************************************************
 End of File
*/
