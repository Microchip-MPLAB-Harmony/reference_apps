/*******************************************************************************
 Motor Control Hardware Abstraction interface file

  Company:
    Microchip Technology Inc.

  File Name:
    hal_analog_feedback.c

  Summary:
    Ananlog feedback hardware abstraction

  Description:
    This file contains the function mapping and channel mapping to provide
    hardware abstraction layer for motor control algorithm
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


#include "hal_analog_feedback.h"  
#include "hal_board_configure.h" 
#include "mc_control_loop.h"

__INLINE void HAL_PhaseCurrentRead(HAL_MOTOR_CONTROL_CHANNEL_T* const pMotorControlChannel)
{   
    HAL_CURRENT_FB_CONFIG_T *pCurrentConfig;
    HAL_CURRENT_FB_T *pCurrentFB;

    pCurrentConfig = &(pMotorControlChannel->current_fb_config);

    pCurrentFB = &(pMotorControlChannel->current_fb);

    pCurrentFB->a = ADCHS_ChannelResultGet(pCurrentConfig->i_u_adc_channel);
    pCurrentFB->b = ADCHS_ChannelResultGet(pCurrentConfig->i_v_adc_channel);    

}


__INLINE uint16_t HAL_VbusAdcRead(HAL_MOTOR_CONTROL_CHANNEL_T*const pMotorControlChannel)
{
    HAL_VOLTAGE_FB_CONFIG_T *pVoltageConfig;

    pVoltageConfig = &(pMotorControlChannel->voltage_fb_config);

    /* Read DC bus voltage */
    return  ADCHS_ChannelResultGet(pVoltageConfig->vbus_channel);

}

void HAL_CurrentCalc(HAL_CHANNEL_ID_E id, HAL_VECTOR3_T * const pPhaseCurrent)
{   
    HAL_CURRENT_FB_T            *pCurrentFB;
    HAL_MOTOR_CONTROL_CHANNEL_T *pMotorControlChannel;

    pMotorControlChannel = &(hal_motor_control_channel[id]);
     
    HAL_PhaseCurrentRead(pMotorControlChannel);

    pCurrentFB = &(pMotorControlChannel->current_fb); 

    pPhaseCurrent->a = HAL_CURRENT_FULL_SCALE * (pCurrentFB->offset_a - pCurrentFB->a) / CURRENT_RESOLUTION;
    pPhaseCurrent->b = HAL_CURRENT_FULL_SCALE * (pCurrentFB->offset_b - pCurrentFB->b) / CURRENT_RESOLUTION;
    pPhaseCurrent->c = -pPhaseCurrent->a - pPhaseCurrent->b;

}

void HAL_CurrentOffsetInitial(HAL_CURRENT_FB_T * const pCurrentFB)
{  
   
    pCurrentFB->counter = 0;
    pCurrentFB->sum_a = 0;
    pCurrentFB->sum_b = 0;
    pCurrentFB->sum_c = 0;
    pCurrentFB->sum_bus = 0;
    pCurrentFB->offset_calibration_done = 0;
  
}


void HAL_CurrentOffsetCalibration(HAL_CHANNEL_ID_E id)
{
    HAL_CURRENT_FB_T *pCurrentFB;

    HAL_PhaseCurrentRead(&(hal_motor_control_channel[id]));
    
    pCurrentFB = &(hal_motor_control_channel[id].current_fb);   
    
    pCurrentFB->sum_a += pCurrentFB->a;
    pCurrentFB->sum_b += pCurrentFB->b;

    pCurrentFB->counter++;

    if (pCurrentFB->counter >= OFFSET_COUNT_MAX)
    {
        pCurrentFB->offset_a = (int16_t)(pCurrentFB->sum_a >> OFFSET_COUNT_BITS);
        pCurrentFB->offset_b = (int16_t)(pCurrentFB->sum_b >> OFFSET_COUNT_BITS);


        pCurrentFB->counter = 0;
        pCurrentFB->sum_a = 0;
        pCurrentFB->sum_b = 0;

        pCurrentFB->offset_calibration_done = 1;
    }
}

float HAL_VbusRead(HAL_CHANNEL_ID_E id)
{
    float vbus_pu;

    vbus_pu = HAL_VbusAdcRead(&(hal_motor_control_channel[id])) / ADC_RESOLUTION;

    return vbus_pu;
}

/*******************************************************************************
 End of File
*/

