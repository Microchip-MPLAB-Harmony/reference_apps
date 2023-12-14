/*******************************************************************************
  Motor Control Hardware Abstraction interface file

  Company:
    Microchip Technology Inc.

  File Name:
    hal_motor_channel_3.h

  Summary:
    Header file for motor parameters initialization.

  Description:
    Header file for motor parameters initialization.
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
#ifndef _HAL_MOTOR_CHANNEL_3_H
#define _HAL_MOTOR_CHANNEL_3_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "hal_configure_common.h" 
#include "mc_math_define.h"

#ifdef __cplusplus
extern "C" {
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Macro Defines
// *****************************************************************************
// *****************************************************************************
/***********************************************************************************************/
/* Motor Parameters */
/***********************************************************************************************/
#define MOTOR_PER_PHASE_RESISTANCE                          ((float)0.285)
#define MOTOR_PER_PHASE_INDUCTANCE                          ((float)0.00032)
#define MOTOR_INERTIA                                       ((float)0.000018f)  /* Kg.m^2 */  
#define MOTOR_BEMF_CONST_V_PEAK_LL_KRPM_MECH                ((float)6.2)
#define NUM_POLE_PAIRS                                      ((float)5)
#define RATED_SPEED_RPM                                     ((float)2804)
#define MAX_SPEED_RPM                                       ((float)3500)
#define MAX_MOTOR_CURRENT                                   ((float)4)
#define ENCODER_PULSES_PER_REV                              ((float)250)
#define INDEX_ANGLE_CNT                                     (0) /* the rotor angle when index event is detected */
#define INDEX_CNT_TOLERANCE                                 (20) /* the allowed difference between successive QEI counter value captured at index pulses */
#define HALL_OFFSET_PU                                      ((float)(0.08333)) //30 degree; 
    
/*Derived parameter, NO need input manually*/
#define MOTOR_BEMF_CONST_V_PEAK_PHASE_PER_RAD_S_MECH          (float)((MOTOR_BEMF_CONST_V_PEAK_LL_KRPM_MECH)/SQRT3 * 60/(M_PI*2)/1000.0f)



// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
extern HAL_MOTOR_PARAMETERS_T   hal_motor_obj_3;


// *****************************************************************************
// *****************************************************************************
// Section: Function Declarations
// *****************************************************************************
// *****************************************************************************

void HAL_InitialMotorObj_3(HAL_MOTOR_PARAMETERS_T *pMotor);


#ifdef __cplusplus
}
#endif

#endif /* end of _HAL_MOTOR_CHANNEL_3_H */

/*******************************************************************************
 End of File
*/    
