/*******************************************************************************
Rotor Position & Speed interface file

 Company:
   Microchip Technology Inc.

 File Name:
   mc_pos_speed_calc.h

 Summary:
   Header file for mc_pos_speed_calc

 Description:
   This file contains the data structures and function prototypes of rotor position & Speed.
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

#ifndef _MC_POS_SPEED_CALC_H
#define _MC_POS_SPEED_CALC_H



/*******************************************************************************
Headers inclusions
 *******************************************************************************/
#include <stdint.h>   
#include "hal_configure_common.h"  
#include "hal_board_configure.h" 
#include "mc_control_loop.h"

#ifdef __cplusplus
extern "C" {
#endif


// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************




// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

void MC_RotorPositionSet(HAL_CHANNEL_ID_E id, uint32_t position_count);//Count value should fall in the range from 1 to pulse per electrical round;
void MC_PositionSensorStart(HAL_CHANNEL_ID_E id);
void MC_MotorVelocitySet(HAL_CHANNEL_ID_E id, uint32_t vel_count);
void MC_RotorPositionCalc(MC_CONTROLLER_T * const pMotorControl);

__STATIC_INLINE float MC_RotorPositionCalc_PU(HAL_CHANNEL_ID_E id)
{
    uint32_t pos_count;
    float   rotor_pos_pu;

    HAL_MOTOR_PARAMETERS_T      *pMotorPara; 

    pMotorPara = hal_motor_control_channel[id].pMotor;

    pos_count = HAL_PositionGet(hal_motor_control_channel[id].position_sensor_config); 

    rotor_pos_pu = (float)pos_count / (float)(pMotorPara->encoder_elec_PPR);

    return rotor_pos_pu;
}

__STATIC_INLINE float MC_SpeedCalc_PU(HAL_CHANNEL_ID_E id)
{
    int32_t vel_count;
    float   speed_feedback_pu;

    HAL_MOTOR_PARAMETERS_T      *pMotorPara; 

    pMotorPara = hal_motor_control_channel[id].pMotor;

    vel_count = HAL_VelocityGet(hal_motor_control_channel[id].position_sensor_config); 

    speed_feedback_pu = vel_count * g_mc_controller[id].speed_loop_freq_HZ /(float)(pMotorPara->encoder_elec_PPR)/(pMotorPara->rated_speed_elec_HZ);

    return speed_feedback_pu;
}


#ifdef __cplusplus
}
#endif

#endif /* end of _MC_POS_SPEED_CALC_H */

/*******************************************************************************
 End of File
*/
