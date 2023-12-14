/*******************************************************************************
  Motor Control Loop Interrupt Handler

  Company:
    Microchip Technology Inc.

  File Name:
    mc_control_loop.c

  Summary:
    This file contains the state machine and control loop of the motor control
   algorithm.

  Description:
    This file contains the control loop.
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

#include "definitions.h"                // SYS function prototypes
#include "device.h"
#include "hal_analog_feedback.h"  
#include "hal_board_configure.h" 
#include "hal_pwm.h" 
#include "mc_svpwm.h"
#include "mc_control_loop.h"
#include "mc_filter.h"
#include "mc_pid_controller.h"
#include "mc_pos_speed_calc.h"



static void MC_1msTickerRun(MC_CONTROLLER_T *pMotorControl);
static void MC_SpeedLoopRun(MC_CONTROLLER_T *pMotorControl);
static void MC_StateMachineRun(MC_CONTROLLER_T *pMotorControl);
static void MC_CurrentControl(MC_CONTROLLER_T *pMotorControl);
static void MC_MotorControl(MC_CONTROLLER_T *pMotorControl);
static void MC_PositionLoopRun(MC_CONTROLLER_T * pMotorControl);
static int32_t MC_RoundPositionCnt(int32_t position_cnt_delta, int32_t overflow_value, int32_t overflow_compensation);
/******************************************************************************/
/*                   Global Variables                                         */
/******************************************************************************/

MC_CONTROLLER_T        g_mc_controller[NUM_OF_MOTOR];

/*position loop parameters*/
float     g_mc_PositionLoop_BandWidth[] = {POSITION_LOOP_BW_HZ_MC1, POSITION_LOOP_BW_HZ_MC2, POSITION_LOOP_BW_HZ_MC3};
float     g_mc_PositionLoop_ff[] = {POSITION_LOOP_FF_MC1, POSITION_LOOP_FF_MC2, POSITION_LOOP_FF_MC3};

/*speed loop parameters*/
uint16_t  g_mc_SpeedLoop_SyncRatio[] = {SPEED_LOOP_SYNC_RATIO_MC1, SPEED_LOOP_SYNC_RATIO_MC2, SPEED_LOOP_SYNC_RATIO_MC3};
float     g_mc_SpeedLoop_BandWidth[] = {SPEED_LOOP_BW_HZ_MC1, SPEED_LOOP_BW_HZ_MC2, SPEED_LOOP_BW_HZ_MC3};

/*current loop parameters*/
uint16_t  g_mc_CurrentLoop_SyncRatio[] = {CURRENT_LOOP_SYNC_RATIO_MC1, CURRENT_LOOP_SYNC_RATIO_MC2, CURRENT_LOOP_SYNC_RATIO_MC3};
float     g_mc_CurrentLoop_BandWidth[] = {CURRENT_LOOP_BW_HZ_MC1, CURRENT_LOOP_BW_HZ_MC2, CURRENT_LOOP_BW_HZ_MC3};

/*potentiometer filter time constant*/
float     g_mc_pot_lpf_tc[] = {POT_LPF_TC_MC1, POT_LPF_TC_MC2, POT_LPF_TC_MC3};

/*speed feedback filter time constant*/
float     g_mc_speed_feedback_lpf_tc[] = {SPEED_FB_LPF_TC_MC1, SPEED_FB_LPF_TC_MC2, SPEED_FB_LPF_TC_MC3};

/*alignment parameters*/
float     g_mc_alignment_time[] = {ALIGNMENT_PERIOD_SEC_MC1, ALIGNMENT_PERIOD_SEC_MC2, ALIGNMENT_PERIOD_SEC_MC3}; 
float     g_mc_alignment_current[] = {ALIGNMENT_CURRENT_AMP_MC1, ALIGNMENT_CURRENT_AMP_MC2, ALIGNMENT_CURRENT_AMP_MC3};

/*current pid controller out max value*/
float     g_pid_current_outmax[] = {PID_CURRENTR_OUTMAX_MC1, PID_CURRENTR_OUTMAX_MC2, PID_CURRENTR_OUTMAX_MC3};

uint16_t g_mc_control_mode[] = {MC_CONTROL_MODE_1, MC_CONTROL_MODE_2, MC_CONTROL_MODE_3};


/*initial motor controller and matching drive hardware, motor parameters*/
void MC_ControllerConfig(MC_CONTROLLER_T *pMotorControl,  HAL_MOTOR_CONTROL_CHANNEL_T *pMotorControlChannel)
{
    HAL_MOTOR_PARAMETERS_T      *pMotorPara;
    MC_FOC_T                    *pFOC; 
    MC_ROTOR_POSITION_T         *pRotorPos;
    //match hardware channel
    pMotorControl->controller_id = pMotorControlChannel->channel_id;
    pMotorPara = pMotorControlChannel->pMotor;
    pFOC = &(pMotorControl->foc);
    pRotorPos = &(pFOC->rotor_position);

    pMotorControl->state = mc_initial;

    pMotorControl->one_ms_flag = false;
    pMotorControl->ticks_counter_1ms = 0;
    
    pMotorControl->ticks_counter_current_loop = pMotorControl->current_loop_sync_ratio;
    pMotorControl->ticks_counter_speed_loop = pMotorControl->speed_loop_sync_ratio;

    pMotorControl->rated_mech_speed_pps = pMotorPara->rated_speed_mech_HZ * pMotorPara->encoder_PPR;

    //configure start-up mode
    pMotorControl->startup_mode = pMotorControlChannel->startup_mode; 
    
    /* configure rotor angle calibration mode */
    pMotorControl->rotor_angle_cali_mode = pMotorControlChannel->rotor_angle_cali_mode;
    if(index_cali == pMotorControl->rotor_angle_cali_mode){
        pMotorControl->state_rotor_angle_calc.state = INDEX_CALI_WAITING;
    }else if(hall_cali == pMotorControl->rotor_angle_cali_mode){
        pMotorControl->state_rotor_angle_calc.state = HALL_CALI_INI;
    }else{}
    
    //alignment control parameters
    pMotorControl->alignment_counter = 0;
    pRotorPos->angle = 0;


    //filter initial
    MC_FirstOrderLPFInitial(&(pMotorControl->speed_ref_filter), pMotorControl->cmd_lpf_factor);
    MC_FirstOrderLPFInitial(&(pMotorControl->speed_feedback_filter), pMotorControl->speed_feedback_lpf_factor);
    MC_FirstOrderLPFInitial(&(pMotorControl->vbus_filter), VBUS_LPF_FACTOR);

    MC_FirstOrderLPFInitial(&(pMotorControl->position_ref_filter), pMotorControl->cmd_lpf_factor);
    MC_FirstOrderLPFInitial(&(pMotorControl->position_forwardfeed_filter), pMotorControl->speed_feedback_lpf_factor);

    pMotorControl->position_ref_cnt = 0;
    pMotorControl->position_ref_cnt_pre = 0;
    pMotorControl->position_feedback_cnt = 0;
    pMotorControl->position_cnt_pre = 0;
    //Space Vector Modulization initial
    MC_SvpwmInitial(&(pMotorControl->svm));

    //speed loop initial
    pMotorControl->speed_feedback_PU = 0;

    //reset pid controller
    MC_PidReset(&(pMotorControl->speed_pid));
    MC_PidReset(&(pFOC->Id_pid));
    MC_PidReset(&(pFOC->Iq_pid));

    //set coefficients of PID controller
    float Kp,Ki,Kc;

    Kc = 0.5;
    //PID for Id, Iq   
    Kp = pMotorControl->current_loop_bandwidth * M_PI*2 * (pMotorPara->L_H) / (pFOC->vector_voltage_max);
    Ki = (pMotorPara->R_Ohm) * pMotorControl->current_loop_bandwidth * M_PI*2* PWM_PERIOD_SEC * pMotorControl->current_loop_sync_ratio / (pFOC->vector_voltage_max);

    MC_PidSetCoefficients(&(pFOC->Iq_pid), Kp, Ki, Kc);
    MC_PidSetCoefficients(&(pFOC->Id_pid), Kp, Ki, Kc);

    //PID for Speed loop
    Kp = pMotorControl->speed_loop_bandwidth * M_PI*2 * pMotorPara->inertia * (pMotorPara->rated_speed_mech_rad_s) / (1.5 * pMotorPara->k_bemf);
    Ki = Kp * pMotorControl->speed_loop_bandwidth * M_PI*2 * PWM_PERIOD_SEC * pMotorControl->current_loop_sync_ratio * pMotorControl->speed_loop_sync_ratio / (pMotorControl->current_loop_bandwidth/pMotorControl->speed_loop_bandwidth);

    MC_PidSetCoefficients(&(pMotorControl->speed_pid), Kp, Ki, Kc);

    //PID for Position loop
    Kp = M_PI*2 * pMotorControl->position_loop_bandwidth /(pMotorPara->encoder_elec_PPR * pMotorPara->rated_speed_elec_HZ) ;
    /*Position Loop no need integration*/
    Ki = 0;
    Kc = 0;
    MC_PidSetCoefficients(&(pMotorControl->position_ctrl), Kp, Ki, Kc);

    //set limitation of PID controller
    MC_PidSetLimitation(&(pMotorControl->speed_pid), pMotorPara->max_current_Amp, -(pMotorPara->max_current_Amp));
    MC_PidSetLimitation(&(pFOC->Id_pid), pFOC->pid_current_outmax, -(pFOC->pid_current_outmax));
    MC_PidSetLimitation(&(pFOC->Iq_pid), pFOC->pid_current_outmax, -(pFOC->pid_current_outmax));

    MC_PidSetLimitation(&(pMotorControl->position_ctrl), pMotorPara->max_speed_RPM / pMotorPara->rated_speed_RPM, -pMotorPara->max_speed_RPM / pMotorPara->rated_speed_RPM);

    //Start Position Sensor Peripheral
    MC_PositionSensorStart(pMotorControl->controller_id);

}


void MC_CurrentLoopIsr(ADCHS_CHANNEL_NUM channel, uintptr_t context)
{
    uint8_t id;

    
    for (id = channel_id_a; id < (NUM_OF_MOTOR + channel_id_a); id++)
    {         
        MC_MotorControl(&g_mc_controller[id]);       
    }    


    X2CScope_Update();
  

}

void MC_AdcIsr(ADCHS_CHANNEL_NUM channel, uintptr_t context)
{
     
    if(hal_motor_control_channel[channel_id_a].current_fb.offset_calibration_done == 0U)
    {
        uint8_t id; 
        for (id = channel_id_a; id < (NUM_OF_MOTOR + channel_id_a); id++)
        {
            HAL_CurrentOffsetCalibration(id);
        }
        
    }
    else
    {
        HAL_AdcCallbackRegister(HAL_IU_ADC_CH_1, MC_CurrentLoopIsr, (uintptr_t)NULL);
    }

}

void MC_FaultIsr_Motor_1(uint32_t status, uintptr_t context)
{

    /*Stop motor running*/
    HAL_PwmOutputDisable(channel_id_a);
    /* Indicate the failure status by lighting LED */
    HAL_FAULT_LED1_SET();
    g_mc_controller[context].state = mc_fault;

}

void MC_FaultIsr_Motor_2(uint32_t status, uintptr_t context)
{
    /*Stop motor running*/
    HAL_PwmOutputDisable(channel_id_b);
    /* Indicate the failure status by lighting LED */
    HAL_FAULT_LED2_SET(); 
    g_mc_controller[context].state = mc_fault;

}

void MC_FaultIsr_Motor_3(uint32_t status, uintptr_t context)
{
    /*Stop motor running*/
    HAL_PwmOutputDisable(channel_id_c);
    /* Indicate the failure status by lighting LED */
    HAL_FAULT_LED3_SET();
    g_mc_controller[context].state = mc_fault;

}


void MC_InterruptInitial(void)
{
    uint8_t i;
    
    HAL_INT_DISABLE(HAL_ADC_IRQ);
    HAL_INT_CLEAR(HAL_ADC_IRQ);

    HAL_AdcCallbackRegister(HAL_IU_ADC_CH_1, MC_AdcIsr, (uintptr_t)NULL);

    HAL_INT_ENABLE(HAL_ADC_IRQ);    
    
    
    /* Enables PWM module. */
    HAL_PWM_START();

    /* Disable PWM output */
    for (i = 0; i < (NUM_OF_MOTOR); i++)
    {
        HAL_PwmOutputDisable(i);

        /* Enable interrupt for fault detection */
        switch(g_mc_controller[i].controller_id)
        {   case channel_id_c:
                HAL_INT_DISABLE(HAL_FAULT_IRQ_3);
                HAL_PWM_CALLBACK_REGISTER(HAL_PWM_U_3, MC_FaultIsr_Motor_3, (uintptr_t)i);
                HAL_INT_CLEAR(HAL_FAULT_IRQ_3);
                HAL_INT_ENABLE(HAL_FAULT_IRQ_3);
            break;
            case channel_id_b:
                HAL_INT_DISABLE(HAL_FAULT_IRQ_2);
                HAL_PWM_CALLBACK_REGISTER(HAL_PWM_U_2, MC_FaultIsr_Motor_2, (uintptr_t)i);
                HAL_INT_CLEAR(HAL_FAULT_IRQ_2);
                HAL_INT_ENABLE(HAL_FAULT_IRQ_2);
            break;
            case channel_id_a:
                HAL_INT_DISABLE(HAL_FAULT_IRQ_1);
                HAL_PWM_CALLBACK_REGISTER(HAL_PWM_U_1, MC_FaultIsr_Motor_1, (uintptr_t)i);
                HAL_INT_CLEAR(HAL_FAULT_IRQ_1);
                HAL_INT_ENABLE(HAL_FAULT_IRQ_1);
            break;    

            default:

            break;
        }
    }

}


void MC_ControllerInitial(void)
{
    uint8_t id;    
      
    HAL_BoardConfig();
    
    for (id = channel_id_a; id < (NUM_OF_MOTOR + channel_id_a); id++)
    {
        g_mc_controller[id].control_mode  = g_mc_control_mode[id];
        
        /*Set controller's current loop parameters*/
        g_mc_controller[id].current_loop_sync_ratio = g_mc_CurrentLoop_SyncRatio[id];
        g_mc_controller[id].current_loop_bandwidth = g_mc_CurrentLoop_BandWidth[id]; 

        /*Set controller's speed loop parameters*/
        g_mc_controller[id].speed_loop_bandwidth = g_mc_SpeedLoop_BandWidth[id]; 
        g_mc_controller[id].speed_loop_sync_ratio = g_mc_SpeedLoop_SyncRatio[id];
        g_mc_controller[id].speed_loop_freq_HZ = (float)PWM_FREQUENCY/(float)g_mc_controller[id].speed_loop_sync_ratio/(float)g_mc_controller[id].current_loop_sync_ratio;

        /*Set controller's cmd potentiometer low-pass filter parameters*/
        /* CMD_LPF_FACTOR = (float)(FILTER_PERIOD/(FILTER_PERIOD + POT_LPF_TC)) */ 
        g_mc_controller[id].cmd_lpf_factor = (float)POT_FILTER_PERIOD/(POT_FILTER_PERIOD + g_mc_pot_lpf_tc[id]);
    
        /*Set controller's position loop parameters*/
        g_mc_controller[id].position_loop_bandwidth = g_mc_PositionLoop_BandWidth[id];

        g_mc_controller[id].position_loop_ff = g_mc_PositionLoop_ff[id];

        /*Set controller's speed feedback low-pass filter parameters*/
        g_mc_controller[id].speed_feedback_lpf_factor = 1.0/(1.0 + g_mc_controller[id].speed_loop_freq_HZ * g_mc_speed_feedback_lpf_tc[id]);
        
        
        /*Set pre-alignment parameters*/
        g_mc_controller[id].alignment_period = PWM_FREQUENCY * g_mc_alignment_time[id]/(float)g_mc_controller[id].current_loop_sync_ratio;
        g_mc_controller[id].alignment_current = g_mc_alignment_current[id];

        /*set svpwm out vector max value*/
        g_mc_controller[id].foc.pid_current_outmax = g_pid_current_outmax[id];
        g_mc_controller[id].foc.vector_voltage_max = g_pid_current_outmax[id] * hal_motor_control_channel[id].V_bus;

        MC_ControllerConfig(&g_mc_controller[id], &hal_motor_control_channel[id]);

        g_mc_controller[id].state = mc_idle;


    }
    
    MC_InterruptInitial();


}


void MC_MotorStart(MC_CONTROLLER_T *pMotorControl)
{
    MC_FOC_T        *pFOC;

    HAL_CHANNEL_ID_E channel_id = pMotorControl->controller_id;
    pFOC = &(pMotorControl->foc);

    //Reset global variables for next run
    MC_FirstOrderLPFInitial(&(pMotorControl->speed_ref_filter), pMotorControl->cmd_lpf_factor);
    MC_FirstOrderLPFInitial(&(pMotorControl->speed_feedback_filter), pMotorControl->speed_feedback_lpf_factor);

    MC_FirstOrderLPFInitial(&(pMotorControl->position_ref_filter), pMotorControl->cmd_lpf_factor);
    MC_FirstOrderLPFInitial(&(pMotorControl->position_forwardfeed_filter), pMotorControl->speed_feedback_lpf_factor);

    //reset pid controller
    MC_PidReset(&(pMotorControl->speed_pid));
    MC_PidReset(&(pFOC->Id_pid));
    MC_PidReset(&(pFOC->Iq_pid));

    // Initial and Enable PWM output 
    MC_SvpwmInitial(&(pMotorControl->svm));

    HAL_VECTOR3_T PwmData;
    PwmData.a = (pMotorControl->svm).dPwm1;
    PwmData.b = (pMotorControl->svm).dPwm2;
    PwmData.c = (pMotorControl->svm).dPwm3;
   
    if(pMotorControl->startup_mode == hall_startup)
    {            
        MC_MotorVelocitySet(channel_id, 0);   // to clear the result of speed register before run speed-loop.
        pMotorControl->state = mc_closed_loop;        
    } 
    else
    {
        pMotorControl->state = mc_rotor_alignment;
    }
    
    if(pMotorControl->rotor_angle_cali_mode == hall_cali)
    {
        /* HALL calibration is done for one time when the motor is started. */
        pMotorControl->state_rotor_angle_calc.state = HALL_CALI_INI;
    }
        
    HAL_PwmDutyUpdate(channel_id,&PwmData);
    HAL_PwmOutputEnable(channel_id);

}


void MC_MotorStop(MC_CONTROLLER_T *pMotorControl)
{
    HAL_CHANNEL_ID_E channel_id = pMotorControl->controller_id;

    pMotorControl->state = mc_idle;
    
    /*Clear speed ref and feedback value*/
    pMotorControl->speed_feedback_PU = 0;
    pMotorControl->speed_feedback_RPM = 0;
    pMotorControl->speed_ref_PU = 0;
    pMotorControl->speed_ref_RPM = 0;

    pMotorControl->position_ref_cnt = 0;
    pMotorControl->position_ref_cnt_pre = 0;
    pMotorControl->position_feedback_cnt = 0;

    HAL_PwmOutputDisable(channel_id);

}


__STATIC_INLINE void MC_MotorControl(MC_CONTROLLER_T * const pMotorControl)
{
    HAL_CHANNEL_ID_E channel_id = pMotorControl->controller_id;

    MC_1msTickerRun(pMotorControl);

    (pMotorControl->ticks_counter_current_loop)++;

    if(pMotorControl->ticks_counter_current_loop >= pMotorControl->current_loop_sync_ratio)
    {
        pMotorControl->ticks_counter_current_loop = 0;

        //input motor current feedback to FOC module
        HAL_CurrentCalc(channel_id, &((pMotorControl->foc).i_abc_amp));

        //input rotor position to FOC module
        MC_RotorPositionCalc(pMotorControl);
        
        //depending on control state to set current reference
        MC_StateMachineRun(pMotorControl);       
        

    }
}

__STATIC_INLINE void MC_1msTickerRun(MC_CONTROLLER_T * const pMotorControl)
{
    (pMotorControl->ticks_counter_1ms)++;

    if( (pMotorControl->ticks_counter_1ms) >= COUNT_MILLISECOND)
    {
        pMotorControl->one_ms_flag = true;
        pMotorControl->ticks_counter_1ms = 0;
    }
    else
        ;
}


__STATIC_INLINE void MC_PositionLoopRun(MC_CONTROLLER_T * const pMotorControl) 
{
    MC_PID_CONTROLLER_T *pCtrl_pos;
    pCtrl_pos = &(pMotorControl->position_ctrl);
    
#ifdef EN_POS_FF_COMPENSATION
    MC_FIRST_ODER_FILTER_T      *pPositionForwardFilter;
    float forward_compensation;

    pPositionForwardFilter = &(pMotorControl->position_forwardfeed_filter);

    forward_compensation = pMotorControl->position_loop_ff*(pMotorControl->position_ref_cnt - pMotorControl->position_ref_cnt_pre)/(POT_FILTER_PERIOD*pMotorControl->rated_mech_speed_pps);

    pPositionForwardFilter->input = forward_compensation;
    MC_FirstOrderLPFRun(pPositionForwardFilter);
    

   pCtrl_pos->out = (pMotorControl->position_ref_cnt - pMotorControl->position_feedback_cnt)*(pCtrl_pos->kp) + pPositionForwardFilter->output;

#else
        
    pCtrl_pos->out = (pMotorControl->position_ref_cnt - pMotorControl->position_feedback_cnt)*(pCtrl_pos->kp);
        
#endif
    
    pMotorControl->speed_ref_PU = pCtrl_pos->out;
}

__STATIC_INLINE void MC_SpeedLoopRun(MC_CONTROLLER_T * const pMotorControl)
{        
    MC_PID_CONTROLLER_T   *pPID_speed;

    pPID_speed = &(pMotorControl->speed_pid);  
    pPID_speed->inMeas = pMotorControl->speed_feedback_PU; 
    pPID_speed->inRef  = pMotorControl->speed_ref_PU;
    MC_PidRun(pPID_speed);
    MC_SetIqRef(&(pMotorControl->foc), pPID_speed->out);
}

__STATIC_INLINE void MC_CurrentControl(MC_CONTROLLER_T * const pMotorControl)
{   
    MC_FOC_T *pFOC;
    HAL_MOTOR_PARAMETERS_T      *pMotorPara; 
    HAL_CHANNEL_ID_E channel_id = pMotorControl->controller_id;

    pFOC = &(pMotorControl->foc);
    pMotorPara = hal_motor_control_channel[channel_id].pMotor;

#ifdef DECOUPLE_DQ
    pFOC->rotor_velocity = pMotorControl->speed_feedback_PU*(pMotorPara->rated_speed_elec_HZ)*(M_TWO_PI);
#endif

    MC_FocRun(pFOC, pMotorPara);

    //Run SVM 
    MC_SvpwmGenerate(&(pFOC->v_AlphaBeta), &(pMotorControl->svm));

    HAL_VECTOR3_T PwmData;

    PwmData.a = (pMotorControl->svm).dPwm1;
    PwmData.b = (pMotorControl->svm).dPwm2;
    PwmData.c = (pMotorControl->svm).dPwm3;
    HAL_PwmDutyUpdate(channel_id, &PwmData);
}



__STATIC_INLINE void MC_StateMachineRun(MC_CONTROLLER_T * const pMotorControl)
{
    HAL_CHANNEL_ID_E channel_id = pMotorControl->controller_id;
    HAL_MOTOR_CONTROL_CHANNEL_T* pMotorControlChannel = &hal_motor_control_channel[channel_id];
    
    switch(pMotorControl->state)
    {             
        case mc_idle:// waiting start button pressed;
        break;
        case mc_rotor_alignment:
        {
            MC_AlignmentRun(pMotorControl);
            
            MC_CurrentControl(pMotorControl);
        }
        break;
        case mc_closed_loop:          
        {   
            (pMotorControl->ticks_counter_speed_loop)++;
            // check whether run speed loop
            if( pMotorControl->ticks_counter_speed_loop >= pMotorControl->speed_loop_sync_ratio)
            {
                pMotorControl->ticks_counter_speed_loop = 0;                    
                
                switch (pMotorControl->control_mode) 
                {
                    case position_mode:
                    {           
                        
                        HAL_MOTOR_PARAMETERS_T *pMotorPara;
                        pMotorPara = pMotorControlChannel->pMotor;
    
                        int32_t pos_cnt_current, overflow_value, overflow_compensation;
                        pos_cnt_current = (int32_t) HAL_PositionGet(pMotorControlChannel->position_sensor_config);                      
                               
                        overflow_value = pMotorPara->encoder_elec_PPR >> 1;
                        overflow_compensation = pMotorPara->encoder_elec_PPR;

                        pMotorControl->position_cnt_delta = MC_RoundPositionCnt((pos_cnt_current - pMotorControl->position_cnt_pre), overflow_value, overflow_compensation);

                        pMotorControl->position_feedback_cnt += pMotorControl->position_cnt_delta;

                        pMotorControl->position_cnt_pre = pos_cnt_current;

                        /*Position loop*/
                        MC_PositionLoopRun(pMotorControl);
                        
                    }
                    case speed_mode:
                    {
                        //get speed feedback
                        (pMotorControl->speed_feedback_filter).input = MC_SpeedCalc_PU(channel_id);
                                     
                        //LPF speed feedback;
                        MC_FirstOrderLPFRun(&(pMotorControl->speed_feedback_filter));
                        pMotorControl->speed_feedback_PU = (pMotorControl->speed_feedback_filter).output;      

                        //run speed closed loop
                        MC_SpeedLoopRun(pMotorControl);  
                    }
                    break;
                    default:
                    ;
                
                }
            }
            
            MC_CurrentControl(pMotorControl);
        
        }
        break;
        case mc_fault: 
        {
            // need reset or restart to recover from fault;
        }
        break;
        default:
        {
            /* Undefined state: Should never come here */
        }

    }
}

void MC_AlignmentRun(MC_CONTROLLER_T * const pMotorControl)
{
    HAL_CHANNEL_ID_E channel_id = pMotorControl->controller_id;
#if INDEX_CALI_MODE == 1u
    MC_ROTOR_ANGLE * ptRotorAngle = &(pMotorControl->rotor_angle_data);
    uint32_t tmp32;
    int32_t bound = ptRotorAngle->cnt_upper_boundary;
#endif
    
    if(pMotorControl->alignment_counter < ((pMotorControl->alignment_period) >>1))
    {
        MC_SetIdRef(&(pMotorControl->foc), 0);
        MC_SetIqRef(&(pMotorControl->foc), pMotorControl->alignment_current);
        MC_SetFocAngle(&(pMotorControl->foc), M_PI);
        (pMotorControl->alignment_counter)++;       
    }
    else if(pMotorControl->alignment_counter < pMotorControl->alignment_period)
    {      
        MC_SetFocAngle(&(pMotorControl->foc), (3.0f * M_PI_OVER_2));               
        (pMotorControl->alignment_counter)++; // comment this line to stay in alignment for testing.        
    }
    else if(pMotorControl->alignment_counter == pMotorControl->alignment_period)
    {        
        #if INDEX_CALI_MODE == 1u /* QEI position counter is reset if an index event is detected. */
        if(pMotorControl->rotor_angle_cali_mode == index_cali)
        {
            tmp32 = bound - (ptRotorAngle->index_angle_cnt);       
        }else  
        {
            tmp32 = 0u;
        }  
        MC_RotorPositionSet(channel_id, tmp32);
        pMotorControl->position_cnt_pre = tmp32;
        #else  /* QEI position coutner is captured if an index event is detected. */
        MC_RotorPositionSet(channel_id, 0u);
        /* Clear index event of the QEI, reset calibration state. */
        HAL_IndexEventClear(hal_motor_control_channel[channel_id].position_sensor_config);
        pMotorControl->state_rotor_angle_calc.state = INDEX_CALI_WAITING;
        #endif
 
        (pMotorControl->alignment_counter)++;
    }
    else
    {
        MC_MotorVelocitySet(channel_id, 0);   // to clear the result of speed register before run speed-loop.  
        pMotorControl->state  = mc_closed_loop; 
        // pMotorControl->alignment_counter = 0;  //uncomment this line to enable alignment everytime when start motor.
    }
}


__STATIC_INLINE int32_t MC_RoundPositionCnt(int32_t position_cnt_delta, int32_t overflow_value, int32_t overflow_compensation)
{
    if (position_cnt_delta > (overflow_value)) 
    {
        position_cnt_delta -= overflow_compensation;

    } 
    else if (position_cnt_delta < -(overflow_value))
    {
        position_cnt_delta += overflow_compensation;

    } 
    else
        ;  

    return position_cnt_delta;
} 

/*******************************************************************************
 End of File
*/

