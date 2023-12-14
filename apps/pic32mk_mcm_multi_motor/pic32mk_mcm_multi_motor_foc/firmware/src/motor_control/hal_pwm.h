/*******************************************************************************
 Motor Control Hardware Abstraction interface file

  Company:
    Microchip Technology Inc.

  File Name:
    hal_pwm.h

  Summary:
    Header file for PWM module hardware abstraction

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

#ifndef _HAL_PWM_H
#define _HAL_PWM_H



// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "hal_configure_common.h" 
#include "definitions.h"

#ifdef __cplusplus
extern "C" {
#endif
    
// *****************************************************************************
// *****************************************************************************
// Section: Macro Defines
// *****************************************************************************
// *****************************************************************************

#define HAL_PWM_U_1                           MCPWM_CH_1
#define HAL_PWM_V_1                           MCPWM_CH_2
#define HAL_PWM_W_1                           MCPWM_CH_3

#define HAL_PWM_U_2                           MCPWM_CH_7
#define HAL_PWM_V_2                           MCPWM_CH_8
#define HAL_PWM_W_2                           MCPWM_CH_9

#define HAL_PWM_U_3                           MCPWM_CH_10
#define HAL_PWM_V_3                           MCPWM_CH_11
#define HAL_PWM_W_3                           MCPWM_CH_12


#define HAL_PWM_MASK_1                        0xe

#define HAL_PWM_STOP()                              MCPWM_Stop()
#define HAL_PWM_START()                             MCPWM_Start()
#define HAL_PWM_PRIMARY_PERIOD_GET()                MCPWM_PrimaryPeriodGet()
#define HAL_PWM_DUTY_SET(ch, duty)                  MCPWM_ChannelPrimaryDutySet(ch, duty)
#define HAL_PWM_OUTPUT_DISABLE(ch)                  MCPWM_ChannelPinsOwnershipDisable(ch)
#define HAL_PWM_OUTPUT_ENABLE(ch)                   MCPWM_ChannelPinsOwnershipEnable(ch)
#define HAL_PWM_CALLBACK_REGISTER(ch, fn, context)  MCPWM_CallbackRegister(ch, fn, context)

#define HAL_FAULT_IRQ_1             (INT_SOURCE_PWM1)
#define HAL_FAULT_IRQ_2             (INT_SOURCE_PWM7)
#define HAL_FAULT_IRQ_3             (INT_SOURCE_PWM10)
	
// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************    
    
typedef struct
{
    //Configure PWM channel of Motor Drive.

    uint8_t u_channel;
    
    uint8_t v_channel;

    uint8_t w_channel;
    
}HAL_PWM_CONFIG_T;


// *****************************************************************************
// *****************************************************************************
// Section: Function Declarations
// *****************************************************************************
// *****************************************************************************
void HAL_PwmOutputDisable(HAL_CHANNEL_ID_E id);
void HAL_PwmOutputEnable(HAL_CHANNEL_ID_E id);
void HAL_PwmDutyUpdate(HAL_CHANNEL_ID_E id, HAL_VECTOR3_T *pPwmData);
    
    
#ifdef __cplusplus
}
#endif

#endif /* end of _HAL_PWM_H */  
    
/*******************************************************************************
 End of File
*/    
    