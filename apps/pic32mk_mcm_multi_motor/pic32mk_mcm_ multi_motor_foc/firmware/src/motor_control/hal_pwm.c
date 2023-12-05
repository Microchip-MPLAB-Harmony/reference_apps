/*******************************************************************************
 Motor Control Hardware Abstraction interface file

  Company:
    Microchip Technology Inc.

  File Name:
    hal_pwm.c

  Summary:
    PWM module hardware abstraction

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
#include "definitions.h"               
#include "hal_pwm.h"   
#include "hal_board_configure.h" 



void HAL_PwmOutputDisable(HAL_CHANNEL_ID_E id)
{
	  HAL_PWM_CONFIG_T *pPwmConfig;

    pPwmConfig = &(hal_motor_control_channel[id].pwm_config);

    HAL_PWM_OUTPUT_DISABLE(pPwmConfig->u_channel);
    HAL_PWM_OUTPUT_DISABLE(pPwmConfig->v_channel);
    HAL_PWM_OUTPUT_DISABLE(pPwmConfig->w_channel);
}


void HAL_PwmOutputEnable(HAL_CHANNEL_ID_E id)
{
	  HAL_PWM_CONFIG_T *pPwmConfig;

    pPwmConfig = &(hal_motor_control_channel[id].pwm_config);


    HAL_PWM_OUTPUT_ENABLE(pPwmConfig->u_channel);
    HAL_PWM_OUTPUT_ENABLE(pPwmConfig->v_channel);
    HAL_PWM_OUTPUT_ENABLE(pPwmConfig->w_channel);
}


void HAL_PwmDutyUpdate(HAL_CHANNEL_ID_E id, HAL_VECTOR3_T *pPwmData)
{
    HAL_PWM_CONFIG_T *pPwmConfig;   

    pPwmConfig = &(hal_motor_control_channel[id].pwm_config);   
    
    HAL_PWM_DUTY_SET(pPwmConfig->u_channel, pPwmData->a);
    HAL_PWM_DUTY_SET(pPwmConfig->v_channel, pPwmData->b);
    HAL_PWM_DUTY_SET(pPwmConfig->w_channel, pPwmData->c);
}

/*******************************************************************************
 End of File
*/
