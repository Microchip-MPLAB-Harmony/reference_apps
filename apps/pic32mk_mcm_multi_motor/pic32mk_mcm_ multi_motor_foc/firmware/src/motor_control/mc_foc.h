/*******************************************************************************
  FOC algorithm file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_foc.h

  Summary:
    Header file for functions of FOC algorithm.

  Description:
    This file contains the data structures and function prototypes of FOC algorithm.

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

#ifndef _MC_FOC_H
#define _MC_FOC_H



/*******************************************************************************
Headers inclusions
 *******************************************************************************/
#include <stdint.h>   
#include "hal_configure_common.h"  
#include "mc_pid_controller.h"
#include "mc_generic_lib.h"
#include "math.h"
#include "device.h"
#include "hal_analog_feedback.h" 
#include "mc_math_define.h"

#ifdef __cplusplus
extern "C" {
#endif

#undef DECOUPLE_DQ

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

typedef struct
{
    float alphaAxis;
    float betaAxis;
}MC_CLARK_TRANSFORM_T;

typedef struct
{
    float directAxis;
    float quadratureAxis;
}MC_PARK_TRANSFORM_T;


typedef struct
{
    float angle;
    float sineAngle;
    float cosAngle;
}MC_ROTOR_POSITION_T;



typedef struct 
{
    float  Id_ref;
    float  Iq_ref;
    float  rotor_velocity;  //elec-rad/s;
    float  d_axis_decouple;
    float  q_axis_decouple;

    float  pid_current_outmax;

    float  vector_voltage_max;

    MC_ROTOR_POSITION_T      rotor_position;

    HAL_VECTOR3_T            i_abc_amp;               /* phase current a,b,c */
    HAL_VECTOR3_T            v_abc_volt;              /* phase voltage a,b,c */
    
    MC_PARK_TRANSFORM_T      i_dq;
    MC_CLARK_TRANSFORM_T     i_AlphaBeta;

    MC_CLARK_TRANSFORM_T     v_AlphaBeta;    
    MC_PARK_TRANSFORM_T      v_dq;

    MC_PID_CONTROLLER_T      Id_pid;
    MC_PID_CONTROLLER_T      Iq_pid;

}MC_FOC_T;


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************
static void MC_FocRun(MC_FOC_T * const pFOC, const HAL_MOTOR_PARAMETERS_T * const pMotorPara);
static void MC_ClarkeTransform(const HAL_VECTOR3_T * const  input, MC_CLARK_TRANSFORM_T * const output);
static void MC_ParkTransform( const MC_CLARK_TRANSFORM_T * const input, const MC_ROTOR_POSITION_T * const position, MC_PARK_TRANSFORM_T * const output);
static void MC_InvParkTransform(const MC_PARK_TRANSFORM_T * const input, const MC_ROTOR_POSITION_T * const position, MC_CLARK_TRANSFORM_T * const output);
static void MC_SetFocAngle(MC_FOC_T *pFOC, float angle);

void MC_SetIdRef(MC_FOC_T *pFOC, float ref);
void MC_SetIqRef(MC_FOC_T *pFOC, float ref);


__STATIC_INLINE void MC_FocRun(MC_FOC_T * const pFOC, const HAL_MOTOR_PARAMETERS_T * const pMotorPara)
{ 
    MC_PID_CONTROLLER_T   *pPID_Id;
    MC_PID_CONTROLLER_T   *pPID_Iq;
    MC_ROTOR_POSITION_T   *pRotorPos; 
    float VqMax;


    pPID_Id = &(pFOC->Id_pid);
    pPID_Iq = &(pFOC->Iq_pid);
    pRotorPos = &(pFOC->rotor_position);

    /* Calculate Sin,Cos from Angle  */
    MCLIB_SinCosCalc(pRotorPos->angle, &(pRotorPos->sineAngle), &(pRotorPos->cosAngle));

    //Clark Transform
    MC_ClarkeTransform(&(pFOC->i_abc_amp), &(pFOC->i_AlphaBeta));
    //Park Transform
    MC_ParkTransform(&(pFOC->i_AlphaBeta), pRotorPos, &((pFOC->i_dq)));



    /* PI control for Id flux control loop */
    pPID_Id->inMeas = (pFOC->i_dq).directAxis;
    pPID_Id->inRef  = pFOC->Id_ref;
    MC_PidRun(pPID_Id);
    (pFOC->v_dq).directAxis = pPID_Id->out;

#ifdef DECOUPLE_DQ
    /*Calculating d-axis coupled component*/
    pFOC->d_axis_decouple = -((pFOC->i_dq).quadratureAxis  * pMotorPara->L_H * (pFOC->rotor_velocity))/(pFOC->vector_voltage_max);

    (pFOC->v_dq).directAxis += pFOC->d_axis_decouple;

    if(((pFOC->v_dq).directAxis) > (pPID_Id->outMax))
    {
        (pFOC->v_dq).directAxis = pPID_Id->outMax;
    }
    else if(((pFOC->v_dq).directAxis) < (pPID_Id->outMin))
    {
        (pFOC->v_dq).directAxis = pPID_Id->outMin;
    }
    else
    {
        ;  //no need to modify;
    }

#endif

    /* Dynamic d-q adjustment with d component priority */
    VqMax = sqrt(pFOC->pid_current_outmax * pFOC->pid_current_outmax - ((pFOC->v_dq).directAxis) * ((pFOC->v_dq).directAxis));

    MC_PidSetLimitation(pPID_Iq, VqMax, (-VqMax));


    /* PI control for Iq torque control loop */
    pPID_Iq->inMeas = (pFOC->i_dq).quadratureAxis;
    pPID_Iq->inRef  = pFOC->Iq_ref;
    MC_PidRun(pPID_Iq);
    (pFOC->v_dq).quadratureAxis = pPID_Iq->out;

 #ifdef DECOUPLE_DQ 
   /*Calculating q-axis coupled component*/
    pFOC->q_axis_decouple = (pFOC->rotor_velocity) * ((pFOC->i_dq).directAxis  * pMotorPara->L_H + pMotorPara->k_bemf/(float)pMotorPara->pole_pairs)/(pFOC->vector_voltage_max);

    (pFOC->v_dq).quadratureAxis += pFOC->q_axis_decouple;

    if(((pFOC->v_dq).quadratureAxis) > VqMax)
    {
        (pFOC->v_dq).quadratureAxis = VqMax;
    }
    else if(((pFOC->v_dq).quadratureAxis) < (-VqMax))
    {
        (pFOC->v_dq).quadratureAxis = -VqMax;
    }
    else
    {
        ;  //no need to modify;
    }

#endif

    //Inverse Park Transform:Calculate Valpha, Vbeta from Sin,Cos,Vd,Vq
    MC_InvParkTransform(&(pFOC->v_dq), pRotorPos, &(pFOC->v_AlphaBeta));

}

__STATIC_INLINE void MC_ClarkeTransform(const HAL_VECTOR3_T * const  input, MC_CLARK_TRANSFORM_T * const output)
{
    output->alphaAxis = input->a;
    output->betaAxis = (input->a * ONE_BY_SQRT3) + (input->b * TWO_BY_SQRT3);
}


__STATIC_INLINE void MC_ParkTransform( const MC_CLARK_TRANSFORM_T * const input, const MC_ROTOR_POSITION_T * const position, MC_PARK_TRANSFORM_T * const output)
{
    output->directAxis =  input->alphaAxis * position->cosAngle
                        + input->betaAxis * position->sineAngle;
    output->quadratureAxis = -input->alphaAxis * position->sineAngle
                        + input->betaAxis * position->cosAngle;
}


__STATIC_INLINE void MC_InvParkTransform(const MC_PARK_TRANSFORM_T * const input, const MC_ROTOR_POSITION_T * const position, MC_CLARK_TRANSFORM_T * const output)
{
    output->alphaAxis =  input->directAxis * position->cosAngle - input->quadratureAxis * position->sineAngle;
    output->betaAxis  =  input->directAxis * position->sineAngle + input->quadratureAxis * position->cosAngle;
}

__STATIC_INLINE void MC_SetFocAngle(MC_FOC_T *pFOC, float angle)
{
    MC_ROTOR_POSITION_T   *pRotorPos;
    pRotorPos = &(pFOC->rotor_position);

    pRotorPos->angle = angle;
}


#ifdef __cplusplus
}
#endif

#endif /* end of _MC_FOC_H */

/*******************************************************************************
 End of File
*/
