/*******************************************************************************
 Motor Control Hardware Abstraction interface file

  Company:
    Microchip Technology Inc.

  File Name:
    hal_command_input.c

  Summary:
    Command input hardware abstraction

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

#include <stdbool.h>
#include "hal_board_configure.h" 
#include "hal_command_input.h"
#include "hal_analog_feedback.h" 



uint16_t HAL_PotentiometerRead(HAL_MOTOR_CONTROL_CHANNEL_T* pMotorControlChannel)
{    
    HAL_COMMAND_CONFIG_T *pCommandConfig;

    pCommandConfig = &(pMotorControlChannel->command_config);

    return ADCHS_ChannelResultGet(pCommandConfig->potentiometer_channel);
 
}

float HAL_PotRefRead(HAL_CHANNEL_ID_E id)
{
    float speed_ref_pu;

    //covert command range to -1.0 ~ +1.0
    speed_ref_pu = ((HAL_PotentiometerRead(&(hal_motor_control_channel[id])) / ADC_RESOLUTION)-0.5f)*2.0f;

    return speed_ref_pu;
}



bool HAL_ButtonRead(HAL_CHANNEL_ID_E id)
{
    HAL_COMMAND_CONFIG_T *pCommandConfig;

    pCommandConfig = &(hal_motor_control_channel[id].command_config);

    return GPIO_PinRead(pCommandConfig->button_input);

}

/*******************************************************************************
 End of File
*/

