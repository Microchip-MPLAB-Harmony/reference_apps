/*******************************************************************************

  Rotor Position & Speed Source File

  Company:
    Microchip Technology Inc.

  File Name:
    mc_pos_speed_calc.c

  Summary:
    This file contains functions to get the rotor position & Speed  of a motor

  Description:
    This file contains functions to get the rotor position & Speed  of a motor
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

#include "mc_pos_speed_calc.h"
#include "hal_configure_common.h"



void MC_RotorPositionSet(HAL_CHANNEL_ID_E id, uint32_t position_count)
{   
    /* Count value should fall in the range from the low-side compare value to the high-side compare value. */
    HAL_PositionCountSet(position_count, hal_motor_control_channel[id].position_sensor_config);
}

void MC_MotorVelocitySet(HAL_CHANNEL_ID_E id, uint32_t vel_count)
{
   HAL_VelocityCountSet(vel_count,hal_motor_control_channel[id].position_sensor_config); 
}

void MC_PositionSensorStart(HAL_CHANNEL_ID_E id)
{
    HAL_QeiStart(hal_motor_control_channel[id].position_sensor_config);
}


static inline int32_t rotorAngleCnt2QeiCnt(int32_t rotorAngle, int32_t offset, int32_t bound)
{
    int32_t tmp32;
      
    tmp32 = rotorAngle - offset;
    
    if(0 > tmp32){
        tmp32 += bound + 1;
    }
    
    return tmp32;
}

static inline int32_t QeiCnt2RotorAngleCnt(int32_t qeiCnt, int32_t offset, int32_t bound)
{
    int32_t tmp32;
    
    tmp32 = qeiCnt + offset;
    
    if(bound < tmp32){
        tmp32 = tmp32 - bound - 1;
    }
    
    return tmp32;
}

static inline void MC_HallAngleIni(MC_CONTROLLER_T * const pMotorControl)
{
    HAL_CHANNEL_ID_E id = pMotorControl->controller_id; 
    HAL_HALL_SENSOR_T * pHall = &(hal_motor_control_channel[id].hall_sensor); 
    MC_ROTOR_ANGLE * ptRotorAngle = &(pMotorControl->rotor_angle_data);
    int32_t tmp32;
    int32_t bound = ptRotorAngle->cnt_upper_boundary;
                
    HAL_HallStatusRead(id);    
  
    if((pMotorControl->rotor_angle_cali_mode == index_cali) && (INDEX_CALI_MODE == 1u)) /* index calibration with reset mode */
    {
        tmp32 = rotorAngleCnt2QeiCnt(pHall->hall_angle_counter, ptRotorAngle->index_angle_cnt, bound);       
    }else  
    {
        tmp32 = pHall->hall_angle_counter;
    }   
 
    ptRotorAngle->qei_cnt_write = tmp32;
    
    if((pHall->hall_value != 0u) && (pHall->hall_value != 7u))
    {
        /* Read Hall sensor value and set QEI counter value accordingly */
        MC_RotorPositionSet(id, (uint32_t)tmp32); 
        pMotorControl->position_cnt_pre = tmp32; 
        ptRotorAngle->hall_value = pHall->hall_value;
        ptRotorAngle->hall_value_latch = ptRotorAngle->hall_value;
    }else
    {
        /* Stop motor */
        HAL_PwmOutputDisable(id);
        pMotorControl->state = mc_fault;
    }    
}

static inline void MC_RotorAngleHallCali(MC_CONTROLLER_T * const pMotorControl)
{
    HAL_CHANNEL_ID_E id = pMotorControl->controller_id; 
    HAL_HALL_SENSOR_T * pHall = &(hal_motor_control_channel[id].hall_sensor); 
    MC_ROTOR_ANGLE * ptRotorAngle = &(pMotorControl->rotor_angle_data);
    MC_STATE_MACHINE * ptStt = &(pMotorControl->state_rotor_angle_calc);
    uint32_t calib_value;
    uint8_t * hall = &(ptRotorAngle->hall_value);
    uint8_t * hallLth = &(ptRotorAngle->hall_value_latch);
    
    switch(ptStt->state)
    {
        case HALL_CALI_IDLE:
            break;
        case HALL_CALI_INI:
            HAL_HallStatusRead(id);
            *hall = pHall->hall_value;
            ptStt->state = HALL_CALI_WAITING;
            break;
        case HALL_CALI_WAITING:
            HAL_HallStatusRead(id);
            if((pHall->hall_value != 0) && (pHall->hall_value != 7)){
                *hallLth = *hall;
                *hall = pHall->hall_value;
            }
            if(*hallLth != *hall){
                /* HALL jump calibration is done for one time when motor is started. */
                calib_value =  HAL_LookupCalibrateQeiCnt(*hallLth, *hall, id);
                MC_RotorPositionSet(id, calib_value);
                pMotorControl->position_cnt_pre = calib_value;
                ptRotorAngle->rotor_angle_cnt = calib_value;
                ptStt->state = HALL_CALI_IDLE;
            }
            break;
        default:
            break;
    }   
}

/* In C89, % operator is implementation defined: it can be a remainder operator or a modulo operator.
 * In C99 & C11, % operator is a remainder operator.
 * An example of remainder operation is: -5 % 4 = -1.
 * An example of modulo operation is: -5 % 4 = 3.
 * This function makes it certain to be a modulo operation. */
static inline int32_t MC_Modulus(int32_t divident, int32_t divisor)
{
    int32_t ret;
    
    /* The divisor shall be positive. */
    if(0 >= divisor){
        ret = 0;
    } else{
        ret = divident % divisor;
    }
        
    if(0 >= ret){
        ret += divisor;
    }
    
    return ret;
}

#if INDEX_CALI_MODE == 0u

static inline void MC_RotorAngleIndexCali(MC_CONTROLLER_T * const pMotorControl)
{
    HAL_CHANNEL_ID_E id = pMotorControl->controller_id; 
    MC_ROTOR_ANGLE * ptRotorAngle = &(pMotorControl->rotor_angle_data);
    MC_STATE_MACHINE * ptStt = &(pMotorControl->state_rotor_angle_calc);
    HAL_POS_CH_E qei_channel = hal_motor_control_channel[id].position_sensor_config;
    int32_t elePPR = hal_motor_control_channel[id].pMotor->encoder_elec_PPR;
    int32_t mechPPR = hal_motor_control_channel[id].pMotor->encoder_PPR;
    int32_t tmp32, capDiff;
    
    switch(ptStt->state)
    {
        case INDEX_CALI_WAITING:   
            /* Suppose qei_cnt_read does not 32-bit signed overflow, otherwise the result can be incorrect. 
             * This assumption is reasonable because an index event shall be detected BEFORE qei_cnt_read gets signed overflow.
             * After that, the signed overflow of qei_cnt_read becomes insignificant. */
            ptRotorAngle->rotor_angle_cnt = MC_Modulus(ptRotorAngle->qei_cnt_read, elePPR);
            /* Read the flag of QEI event. */
            ptRotorAngle->is_index_detected = HAL_IndexEventCheck(qei_channel);
            if(true == ptRotorAngle->is_index_detected){
                /* Read the captured QEI counter value. */
                ptRotorAngle->qei_cap_cnt = HAL_CapturedPositionGet(qei_channel);
                ptRotorAngle->qei_cap_cnt_correct = ptRotorAngle->qei_cap_cnt;
                ptStt->state = INDEX_CALI_ANGLE_CALC;
            }            
            break;
        case INDEX_CALI_ANGLE_CALC:
            /* Read the captured QEI counter value. */
            ptRotorAngle->qei_cap_cnt = HAL_CapturedPositionGet(qei_channel);  
            /* Scrutinize the captured counter value. */
            capDiff = ptRotorAngle->qei_cap_cnt_correct - ptRotorAngle->qei_cap_cnt;
            tmp32 = MC_Modulus(capDiff, mechPPR);
            if((tmp32 < ptRotorAngle->index_cnt_tolerance) || (tmp32 > (mechPPR - ptRotorAngle->index_cnt_tolerance))){
                ptRotorAngle->qei_cap_cnt_correct = ptRotorAngle->qei_cap_cnt;
            }
            /* Calculate rotor angle in counter number. */
            tmp32 = ptRotorAngle->qei_cnt_read - ptRotorAngle->qei_cap_cnt_correct;
            ptRotorAngle->cnt_since_index = tmp32;
            /* Suppose cnt_since_index does not 32-bit signed overflow, otherwise the result can be incorrect.
             * This assumption is reasonable because it is hard to imagine abs(cnt_since_index) is bigger than 0x7FFFFFFF. */
            tmp32 += ptRotorAngle->index_angle_cnt;
            ptRotorAngle->rotor_angle_cnt = MC_Modulus(tmp32, elePPR); 
            break;
        default:
            break;
    }    
}

#endif


void MC_RotorPositionCalc(MC_CONTROLLER_T * const pMotorControl)
{    
    /* Alignment start: no_cali or index_cali. */   
    /* HALL start: hall_cali or index_cali. */ 
    HAL_CHANNEL_ID_E id = pMotorControl->controller_id; 
    MC_ROTOR_ANGLE * ptRotorAngle = &(pMotorControl->rotor_angle_data);
    HAL_MOTOR_PARAMETERS_T * pMotorPara = hal_motor_control_channel[id].pMotor;
    HAL_HALL_SENSOR_T * pHall = &(hal_motor_control_channel[id].hall_sensor);
    #if (INDEX_CALI_MODE == 1u)  /* reset mode */
    int32_t bound = ptRotorAngle->cnt_upper_boundary;
    #endif
    HAL_POS_CH_E qei_channel = hal_motor_control_channel[id].position_sensor_config;
    int32_t ppr = pMotorPara->encoder_elec_PPR;
    
    /* Initialization */
    if(ptRotorAngle->is_ini_finished == false)
    {  
        /* Initialize parameters. */
        ptRotorAngle->cnt2rad = M_TWO_PI / ppr;
        ptRotorAngle->index_angle_cnt = hal_motor_control_channel[id].pMotor->index_angle_cnt;
        ptRotorAngle->cnt_upper_boundary = ppr - 1; /* Suppose encoder_elec_PPR > 1. */   
        ptRotorAngle->index_cnt_tolerance = hal_motor_control_channel[id].pMotor->index_cnt_tolerance;
        /* Initialize hall-angle. */
        if(pMotorControl->startup_mode == hall_startup)
        {
            MC_HallAngleIni(pMotorControl);
        }       
        ptRotorAngle->is_ini_finished = true;
    }
    
    /* Read QEI counter value. */
    if((pMotorControl->rotor_angle_cali_mode == index_cali) && (INDEX_CALI_MODE == 1u)){  /* index calibration in reset mode */
        /* Here '+1' is because the low-boundary of the QEI counter is -1. */
        ptRotorAngle->qei_cnt_read = (int32_t)(HAL_PositionGet(qei_channel) + 1);    
    } else{
        ptRotorAngle->qei_cnt_read = (int32_t)(HAL_PositionGet(qei_channel));
    }

    ptRotorAngle->index_event_cnt = HAL_RevolutionsGet(qei_channel);  /* for reference */ 
    
    /* Calculate rotor angle under each calibration mode. */
    if(pMotorControl->rotor_angle_cali_mode == hall_cali){
        ptRotorAngle->rotor_angle_cnt = ptRotorAngle->qei_cnt_read;
        MC_RotorAngleHallCali(pMotorControl);
    }else if(pMotorControl->rotor_angle_cali_mode == index_cali){
    #if (INDEX_CALI_MODE == 1u)  /* reset mode */
        ptRotorAngle->rotor_angle_cnt = QeiCnt2RotorAngleCnt(ptRotorAngle->qei_cnt_read, ptRotorAngle->index_angle_cnt, bound);
    #else  /* capture mode */
        MC_RotorAngleIndexCali(pMotorControl);
    #endif
    }else { /* no calibration for rotor angle */
        ptRotorAngle->rotor_angle_cnt = ptRotorAngle->qei_cnt_read;
        /* Read HALL value, index event flag, index counter, as the reference for tuning. */     
        ptRotorAngle->index_event_cnt = HAL_RevolutionsGet(qei_channel);    
        ptRotorAngle->is_index_detected = HAL_IndexEventCheck(qei_channel);
        if(true == ptRotorAngle->is_index_detected){
            /* Clear the index event flag */
            HAL_IndexEventClear(qei_channel);
        }
        HAL_HallStatusRead(id);
        ptRotorAngle->hall_value = pHall->hall_value;
    }
        
    /* Transfer from counter number to radian. */
    ptRotorAngle->rotor_angle_rad = (float)(ptRotorAngle->rotor_angle_cnt) * ptRotorAngle->cnt2rad;
    /* Assign rotor angle to FOC controller. 
     * The FOC angle shall be overridden in open-alignment-start mode. */
    pMotorControl->foc.rotor_position.angle = ptRotorAngle->rotor_angle_rad;
}


/*******************************************************************************
 End of File
*/
