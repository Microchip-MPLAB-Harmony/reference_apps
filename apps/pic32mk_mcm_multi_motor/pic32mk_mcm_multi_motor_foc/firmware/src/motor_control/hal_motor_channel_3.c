/*******************************************************************************
  Motor Control Hardware Abstraction interface file

  Company:
    Microchip Technology Inc.

  File Name:
    hal_motor_channel_3.c

  Summary:
    Motor parameters initialization.

  Description:
    Motor parameters initialization.
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

#include "hal_motor_channel_3.h"
#include "hal_position_sensor.h"  

HAL_MOTOR_PARAMETERS_T   hal_motor_obj_3;


void HAL_InitialMotorObj_3(HAL_MOTOR_PARAMETERS_T *pMotor)
{
    pMotor->R_Ohm = MOTOR_PER_PHASE_RESISTANCE;
    pMotor->L_H = MOTOR_PER_PHASE_INDUCTANCE;
    pMotor->inertia = MOTOR_INERTIA;
    pMotor->k_bemf = MOTOR_BEMF_CONST_V_PEAK_PHASE_PER_RAD_S_MECH;
    pMotor->max_current_Amp = MAX_MOTOR_CURRENT;
    pMotor->pole_pairs = NUM_POLE_PAIRS;
    pMotor->max_speed_RPM = MAX_SPEED_RPM;
    pMotor->rated_speed_RPM = RATED_SPEED_RPM;
    pMotor->encoder_PPR = ENCODER_PULSES_PER_REV*4;
    pMotor->encoder_elec_PPR = (float)pMotor->encoder_PPR / (float)NUM_POLE_PAIRS;
    pMotor->rated_speed_mech_HZ = (float)RATED_SPEED_RPM / 60.0f;
    pMotor->rated_speed_elec_HZ = pMotor->rated_speed_mech_HZ *(float)NUM_POLE_PAIRS;
    pMotor->rated_speed_mech_rad_s = pMotor->rated_speed_mech_HZ * M_TWO_PI;
    pMotor->pHall_sensor_table = HallSensorTable;
    pMotor->index_angle_cnt = INDEX_ANGLE_CNT;
    pMotor->index_cnt_tolerance = INDEX_CNT_TOLERANCE;
    pMotor->hall_offset = HALL_OFFSET_PU;
}

/*******************************************************************************
 End of File
*/    
