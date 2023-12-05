/*******************************************************************************
 Motor Control Hardware Abstraction interface file

  Company:
    Microchip Technology Inc.

  File Name:
    hal_board_configure.h

  Summary:
    Header file for board config hardware abstraction

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

#ifndef _HAL_BOARD_CONFIGURE_H
#define _HAL_BOARD_CONFIGURE_H



/*******************************************************************************
Headers inclusions
 *******************************************************************************/
#include <stdint.h>
#include "definitions.h"               
#include "hal_configure_common.h"  
#include "hal_analog_feedback.h" 
#include "hal_pwm.h" 
#include "hal_position_sensor.h" 
#include "hal_command_input.h"


#ifdef __cplusplus
extern "C" {
#endif
    

#define NUM_OF_MOTOR        3 
  
/* Select start-up mode: hall_startup or alignment_startup. */    
#define HAL_STARTUP_MODE_1    hall_startup
#define HAL_STARTUP_MODE_2    hall_startup
#define HAL_STARTUP_MODE_3    hall_startup   

/* Select calibration mode for rotor angle: index_cali or no_cali.
 * hall_cali is dedicated to the Hurster motors and is not recommended for any other motor.
 * For alignment_startup: cannot choose hall_cali;
 * For hall startup: cannot choose no_cali. */    
#define ROTOR_ANGLE_CALI_MODE_1    HALL_CALI
#define ROTOR_ANGLE_CALI_MODE_2    HALL_CALI    
#define ROTOR_ANGLE_CALI_MODE_3    HALL_CALI
    
/* index calibration mode:
 * 1: QEI position counter is reset if an index event is detected.
 * 0: QEI position counter is captured if an index event is detected.
 *    For PIC32MK, this mode is not compatible with modulo mode. */
#define INDEX_CALI_MODE         (1u)
    
#define DC_BUS_VOLTAGE_1      ((float)24)        /* Volts */
#define DC_BUS_VOLTAGE_2      ((float)24)        /* Volts */
#define DC_BUS_VOLTAGE_3      ((float)24)        /* Volts */

/************************************ Interrupt *********************************************/

#define HAL_INT_DISABLE(irq)       EVIC_SourceDisable(irq)
#define HAL_INT_ENABLE(irq)        EVIC_SourceEnable(irq)
#define HAL_INT_CLEAR(irq)         EVIC_SourceStatusClear(irq)


#define HAL_FAULT_LED1_SET()       LED_1_Set()
#define HAL_FAULT_LED1_CLEAR()     LED_1_Clear()
#define HAL_FAULT_LED1_TOGGLE()    LED_1_Toggle()

#define HAL_FAULT_LED2_SET()       LED_2_Set()
#define HAL_FAULT_LED2_CLEAR()     LED_2_Clear()
#define HAL_FAULT_LED2_TOGGLE()    LED_2_Toggle()

#define HAL_FAULT_LED3_SET()       LED_3_Set()
#define HAL_FAULT_LED3_CLEAR()     LED_3_Clear()
#define HAL_FAULT_LED3_TOGGLE()    LED_3_Toggle()






typedef struct
{
    HAL_CHANNEL_ID_E         channel_id;

    //current feedback
    HAL_CURRENT_FB_CONFIG_T  current_fb_config;
    HAL_CURRENT_FB_T         current_fb;

    //Voltage feedback
    HAL_VOLTAGE_FB_CONFIG_T  voltage_fb_config;

    //PWM module
    HAL_PWM_CONFIG_T         pwm_config;

    //position  feedback
    HAL_POS_CH_E             position_sensor_config;
    HAL_POS_SENSOR_T         position_sensor;

    //hall sensor 
    HAL_HALL_CONFIG_T        hall_sensor_config;
    HAL_HALL_SENSOR_T        hall_sensor;

    //button and potentiometer input
    HAL_COMMAND_CONFIG_T     command_config;

    //motor object
    HAL_MOTOR_PARAMETERS_T   *pMotor;

    HAL_STARTUP_MODE_E       startup_mode;
    ROTOR_ANGLE_CALI_MODE_E  rotor_angle_cali_mode;    

    float                    V_bus;


}HAL_MOTOR_CONTROL_CHANNEL_T;


extern HAL_MOTOR_CONTROL_CHANNEL_T  hal_motor_control_channel[NUM_OF_MOTOR];

/*******************************************************************************
 * Interface Functions
 *******************************************************************************/
void HAL_MotorControlChannelConfig(HAL_CHANNEL_ID_E id);
void HAL_BoardConfig(void);

#ifdef __cplusplus
}
#endif

#endif /* end of _HAL_BOARD_CONFIGURE_H */

/*******************************************************************************
 End of File
*/
