/*******************************************************************************
 Motor Control Hardware Abstraction interface file

  Company:
    Microchip Technology Inc.

  File Name:
    hal_board_configure.c

  Summary:
    Board config hardware abstraction

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


#include "hal_board_configure.h" 


extern HAL_MOTOR_PARAMETERS_T   hal_motor_obj_1;
extern HAL_MOTOR_PARAMETERS_T   hal_motor_obj_2;
extern HAL_MOTOR_PARAMETERS_T   hal_motor_obj_3;

void HAL_InitialMotorObj_1(HAL_MOTOR_PARAMETERS_T *pMotor);
void HAL_InitialMotorObj_2(HAL_MOTOR_PARAMETERS_T *pMotor);
void HAL_InitialMotorObj_3(HAL_MOTOR_PARAMETERS_T *pMotor);

HAL_MOTOR_CONTROL_CHANNEL_T  hal_motor_control_channel[NUM_OF_MOTOR];

void HAL_BoardConfig(void)
{
    uint8_t id; 
    for (id = channel_id_a; id < (NUM_OF_MOTOR + channel_id_a); id++)
    {
        HAL_MotorControlChannelConfig(id);
    }

}




void HAL_MotorControlChannelConfig(HAL_CHANNEL_ID_E id)
{
    
    HAL_MOTOR_CONTROL_CHANNEL_T *pMotorControlChannel;
    HAL_CURRENT_FB_T            *pCurrentFB;
    HAL_CURRENT_FB_CONFIG_T     *pCurrentConfig;
    HAL_PWM_CONFIG_T            *pPwmConfig;
    HAL_HALL_CONFIG_T           *pHallConfig;
    HAL_COMMAND_CONFIG_T        *PCommandConfig;     
    HAL_VOLTAGE_FB_CONFIG_T     *pVoltageConfig;


    if (id == channel_id_a)
    {
        pMotorControlChannel = &(hal_motor_control_channel[channel_id_a]);
        pMotorControlChannel->channel_id = channel_id_a;

        //Configure start-up mode 
        pMotorControlChannel->startup_mode = HAL_STARTUP_MODE_1;
        pMotorControlChannel->rotor_angle_cali_mode = ROTOR_ANGLE_CALI_MODE_1;

        //Configure Vbus voltage value
        pMotorControlChannel->V_bus = DC_BUS_VOLTAGE_1;

        //Configure ADC channel for Phase current feedback
        pCurrentConfig = &(pMotorControlChannel->current_fb_config);
        pCurrentConfig->i_u_adc_channel = HAL_IU_ADC_CH_1;
        pCurrentConfig->i_v_adc_channel = HAL_IV_ADC_CH_1;

        //Configure Voltage feedback
        pVoltageConfig = &(pMotorControlChannel->voltage_fb_config);
        pVoltageConfig->vbus_channel = HAL_VBUS_ADC_CH_1;
        
        //Initial current offset
        pCurrentFB = &(pMotorControlChannel->current_fb);
        HAL_CurrentOffsetInitial(pCurrentFB);

        //Configure PWM module
        pPwmConfig = &(pMotorControlChannel->pwm_config);
        pPwmConfig->u_channel = HAL_PWM_U_1;
        pPwmConfig->v_channel = HAL_PWM_V_1;
        pPwmConfig->w_channel = HAL_PWM_W_1;

        //Configure position sensor module
        pMotorControlChannel->position_sensor_config = HAL_POS_CH_1;

        //Configure hall sensor module
        pHallConfig = &(pMotorControlChannel->hall_sensor_config);
        pHallConfig->port_a = HAL_HALL_A_1;
        pHallConfig->port_b = HAL_HALL_B_1; 
        pHallConfig->port_c = HAL_HALL_C_1;

        // Configure button and potentiometer input
        PCommandConfig =  &(pMotorControlChannel->command_config);
        PCommandConfig->potentiometer_channel = POTENTIOMETER_1;
        PCommandConfig->button_input = BUTTON_ENABLE_1;

        //configure motor parameters
        pMotorControlChannel->pMotor = &hal_motor_obj_1;
        HAL_InitialMotorObj_1(pMotorControlChannel->pMotor);
    
    /* index calibration in reset mode: adjust boundary values for QEI modulo operation. */ 
    #if (ROTOR_ANGLE_CALI_MODE_1 == INDEX_CALI)
        #if (INDEX_CALI_MODE == 1u) //Index reset;
        /* Suppose encoder_elec_PPR > 1. */
        /* The low-boundary shall be smaller than 0, such as -1; otherwise the modulo counting may be disrupted after an index event occurs. */
        HAL_QeiPositionWindowSet(HAL_POS_CH_1, (uint32_t)(pMotorControlChannel->pMotor->encoder_elec_PPR - 2), (uint32_t)(-1)); 
        /* PIMOD = 7 */
        HAL_QeiIndexModeSet(HAL_POS_CH_1, 0x1c00);
        HAL_QeiIndexCaptureDisable(HAL_POS_CH_1);
        #else //Index capture enable;
        /* PIMOD = 0 */
        HAL_QeiIndexModeSet(HAL_POS_CH_1, 0x0000);
        HAL_QeiIndexCaptureEnable(HAL_POS_CH_1);
        #endif
    #else
        HAL_QeiPositionWindowSet(HAL_POS_CH_1, (uint32_t)(pMotorControlChannel->pMotor->encoder_elec_PPR - 1), (uint32_t)(0));   
        /* PIMOD = 6 */
        HAL_QeiIndexModeSet(HAL_POS_CH_1, 0x1800);    
    #endif
    }
#if(NUM_OF_MOTOR > 1)    
    else if (id == channel_id_b)
    {
        pMotorControlChannel = &(hal_motor_control_channel[channel_id_b]);

        pMotorControlChannel->channel_id = channel_id_b;

        //Configure start-up mode 
        pMotorControlChannel->startup_mode = HAL_STARTUP_MODE_2;
        pMotorControlChannel->rotor_angle_cali_mode = ROTOR_ANGLE_CALI_MODE_2;        

        //Configure Vbus voltage value
        pMotorControlChannel->V_bus = DC_BUS_VOLTAGE_2;

        //Configure ADC channel for Phase current feedback
        pCurrentConfig = &(pMotorControlChannel->current_fb_config);        
        pCurrentConfig->i_u_adc_channel = HAL_IU_ADC_CH_2;
        pCurrentConfig->i_v_adc_channel = HAL_IV_ADC_CH_2;

        //Configure Voltage feedback
        pVoltageConfig = &(pMotorControlChannel->voltage_fb_config);
        pVoltageConfig->vbus_channel = HAL_VBUS_ADC_CH_2;

        //Initial current offset
        pCurrentFB = &(pMotorControlChannel->current_fb);
        HAL_CurrentOffsetInitial(pCurrentFB);

        //Configure PWM module
        pPwmConfig = &(pMotorControlChannel->pwm_config);
        pPwmConfig->u_channel = HAL_PWM_U_2;
        pPwmConfig->v_channel = HAL_PWM_V_2;
        pPwmConfig->w_channel = HAL_PWM_W_2;

        //Configure position sensor module
        pMotorControlChannel->position_sensor_config = HAL_POS_CH_2;

        //Configure hall sensor module
        pHallConfig = &(pMotorControlChannel->hall_sensor_config);
        pHallConfig->port_a = HAL_HALL_A_2;
        pHallConfig->port_b = HAL_HALL_B_2;
        pHallConfig->port_c = HAL_HALL_C_2;

        // Configure button and potentiometer input
        PCommandConfig =  &(pMotorControlChannel->command_config);
        PCommandConfig->potentiometer_channel = POTENTIOMETER_2;
        PCommandConfig->button_input = BUTTON_ENABLE_2;

        //configure motor parameters
        pMotorControlChannel->pMotor = &hal_motor_obj_2;
        HAL_InitialMotorObj_2(pMotorControlChannel->pMotor);

    /* index calibration in reset mode: adjust boundary values for QEI modulo operation. */        
    #if (ROTOR_ANGLE_CALI_MODE_2 == INDEX_CALI)
        #if (INDEX_CALI_MODE == 1u) //Index reset;
        /* Suppose encoder_elec_PPR > 1. */
        /* The low-boundary shall be smaller than 0, such as -1; otherwise the modulo counting may be disrupted after an index event occurs. */
        HAL_QeiPositionWindowSet(HAL_POS_CH_2, (uint32_t)(pMotorControlChannel->pMotor->encoder_elec_PPR - 2), (uint32_t)(-1)); 
        /* PIMOD = 7 */
        HAL_QeiIndexModeSet(HAL_POS_CH_2, 0x1c00);
        HAL_QeiIndexCaptureDisable(HAL_POS_CH_2);
        #else //Index capture enable;
        /* PIMOD = 0 */
        HAL_QeiIndexModeSet(HAL_POS_CH_2, 0x0000); 
        HAL_QeiIndexCaptureEnable(HAL_POS_CH_2);
        #endif
    #else
        HAL_QeiPositionWindowSet(HAL_POS_CH_2, (uint32_t)(pMotorControlChannel->pMotor->encoder_elec_PPR - 1), (uint32_t)(0));   
        /* PIMOD = 6 */
        HAL_QeiIndexModeSet(HAL_POS_CH_2, 0x1800);     
    #endif
    }
#endif
#if(NUM_OF_MOTOR > 2) 
    else if (id == channel_id_c)
    {
        pMotorControlChannel = &(hal_motor_control_channel[channel_id_c]);

        pMotorControlChannel->channel_id = channel_id_c;

        //Configure start-up mode 
        pMotorControlChannel->startup_mode = HAL_STARTUP_MODE_3;
        pMotorControlChannel->rotor_angle_cali_mode = ROTOR_ANGLE_CALI_MODE_3;        
        
        //Configure Vbus voltage value
        pMotorControlChannel->V_bus = DC_BUS_VOLTAGE_3;

        //Configure ADC channel for Phase current feedback
        pCurrentConfig = &(pMotorControlChannel->current_fb_config);        
        pCurrentConfig->i_u_adc_channel = HAL_IU_ADC_CH_3;
        pCurrentConfig->i_v_adc_channel = HAL_IV_ADC_CH_3;
        
        //Configure Voltage feedback
        pVoltageConfig = &(pMotorControlChannel->voltage_fb_config);
        pVoltageConfig->vbus_channel = HAL_VBUS_ADC_CH_3;

        //Initial current offset
        pCurrentFB = &(pMotorControlChannel->current_fb);
        HAL_CurrentOffsetInitial(pCurrentFB);

        //Configure PWM module
        pPwmConfig = &(pMotorControlChannel->pwm_config);
        pPwmConfig->u_channel = HAL_PWM_U_3;
        pPwmConfig->v_channel = HAL_PWM_V_3;
        pPwmConfig->w_channel = HAL_PWM_W_3;

        //Configure position sensor module
        pMotorControlChannel->position_sensor_config = HAL_POS_CH_3;

        //Configure hall sensor module
        pHallConfig = &(pMotorControlChannel->hall_sensor_config);
        pHallConfig->port_a = HAL_HALL_A_3;
        pHallConfig->port_b = HAL_HALL_B_3;
        pHallConfig->port_c = HAL_HALL_C_3;

        // Configure button and potentiometer input
        PCommandConfig =  &(pMotorControlChannel->command_config);
        PCommandConfig->potentiometer_channel = POTENTIOMETER_3;
        PCommandConfig->button_input = BUTTON_ENABLE_3;
       

        //configure motor parameters
        pMotorControlChannel->pMotor = &hal_motor_obj_3;
        HAL_InitialMotorObj_3(pMotorControlChannel->pMotor);

    /* index calibration in reset mode: adjust boundary values for QEI modulo operation. */        
    #if (ROTOR_ANGLE_CALI_MODE_2 == INDEX_CALI)
        #if (INDEX_CALI_MODE == 1u) //Index reset;
        /* Suppose encoder_elec_PPR > 1. */
        /* The low-boundary shall be smaller than 0, such as -1; otherwise the modulo counting may be disrupted after an index event occurs. */
        HAL_QeiPositionWindowSet(HAL_POS_CH_3, (uint32_t)(pMotorControlChannel->pMotor->encoder_elec_PPR - 2), (uint32_t)(-1)); 
        /* PIMOD = 7 */
        HAL_QeiIndexModeSet(HAL_POS_CH_3, 0x1c00);
        HAL_QeiIndexCaptureDisable(HAL_POS_CH_3);
        #else //Index capture enable;
        /* PIMOD = 0 */
        HAL_QeiIndexModeSet(HAL_POS_CH_3, 0x0000);
        HAL_QeiIndexCaptureEnable(HAL_POS_CH_3);        
        #endif
    #else
        HAL_QeiPositionWindowSet(HAL_POS_CH_3, (uint32_t)(pMotorControlChannel->pMotor->encoder_elec_PPR - 1), (uint32_t)(0));   
        /* PIMOD = 6 */
        HAL_QeiIndexModeSet(HAL_POS_CH_3, 0x1800);    
    #endif
    }
#endif
    else {}

}

/*******************************************************************************
 End of File
*/
