/*******************************************************************************
  Motor Control Loop Interrupt Handler

  Company:
    Microchip Technology Inc.

  File Name:
    mc_control_loop.h

  Summary:
    Motor control algorithm interface

  Description:
    This file contains the data structures and function prototypes of motor control loop.
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

#ifndef _MC_CONTROL_LOOP_H
#define _MC_CONTROL_LOOP_H



// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stdint.h>
#include "hal_board_configure.h"
#include "mc_foc.h"
#include "mc_svpwm.h"
#include "mc_filter.h"
#include "mc_pid_controller.h"


#ifdef __cplusplus
extern "C" {
#endif
 

#define PWM_FREQUENCY              ((uint16_t)20000)
#define PWM_PERIOD_SEC             (float)(1.0 / (float)PWM_FREQUENCY) 
#define COUNT_MILLISECOND          (uint16_t)(PWM_FREQUENCY/1000) 

/****************Position Loop Parameters***********/
#define POSITION_LOOP_BW_HZ_MC1      ((float)3.0)
#define POSITION_LOOP_BW_HZ_MC2      ((float)3.0)
#define POSITION_LOOP_BW_HZ_MC3      ((float)3.0)


//Position loop forward factor, range: 0~1;
#define POSITION_LOOP_FF_MC1      ((float)0.0)
#define POSITION_LOOP_FF_MC2      ((float)0.0)
#define POSITION_LOOP_FF_MC3      ((float)0.0)

/****************Speed Loop Parameters***********/
#define SPEED_LOOP_BW_HZ_MC1       ((float)30.0)
#define SPEED_LOOP_BW_HZ_MC2       ((float)30.0)
#define SPEED_LOOP_BW_HZ_MC3       ((float)30.0)

/*define speed loop freq division, How many current loop executed per speed loop time*/
#define SPEED_LOOP_SYNC_RATIO_MC1    20u
#define SPEED_LOOP_SYNC_RATIO_MC2    20u
#define SPEED_LOOP_SYNC_RATIO_MC3    20u

/*define speed feedback's filter Tc factor*/
#define SPEED_FB_LPF_TC_MC1         ((float)0.005) // unit: second   
#define SPEED_FB_LPF_TC_MC2         ((float)0.005) // unit: second    
#define SPEED_FB_LPF_TC_MC3         ((float)0.005) // unit: second 

/****************Current Loop Parameters***********/
#define CURRENT_LOOP_BW_HZ_MC1       ((float)600.0)
#define CURRENT_LOOP_BW_HZ_MC2       ((float)600.0)
#define CURRENT_LOOP_BW_HZ_MC3       ((float)600.0)

/*define current loop freq division, How many pwm interrupts per current loop time*/
#define CURRENT_LOOP_SYNC_RATIO_MC1  1u
#define CURRENT_LOOP_SYNC_RATIO_MC2  1u
#define CURRENT_LOOP_SYNC_RATIO_MC3  1u


/****************Potentiometer Input Configuration***********/
/*define speed cmd potentiometer's filter Tc factor*/
#define POT_LPF_TC_MC1              ((float)0.1)   // unit: second   
#define POT_LPF_TC_MC2              ((float)0.1)   // unit: second   
#define POT_LPF_TC_MC3              ((float)0.1)   // unit: second   
#define POT_FILTER_PERIOD           ((float)0.001) // unit: second;     

/****************Vbus Filter Configuration***********/    
#define VBUS_FILTER_PERIOD          ((float)0.001)   // unit: second; 
#define VBUS_LPF_TC                 ((float)(VBUS_FILTER_PERIOD*200.0))    // unit: second 
#define VBUS_LPF_FACTOR             (VBUS_FILTER_PERIOD/(VBUS_FILTER_PERIOD + VBUS_LPF_TC)) 

/****************define alignment parameters in start-up***********/
#define ALIGNMENT_PERIOD_SEC_MC1    ((float)2.0)  // unit: second   
#define ALIGNMENT_PERIOD_SEC_MC2    ((float)2.0)  // unit: second 
#define ALIGNMENT_PERIOD_SEC_MC3    ((float)2.0)  // unit: second 

#define ALIGNMENT_CURRENT_AMP_MC1   ((float)0.4)  // unit: amp
#define ALIGNMENT_CURRENT_AMP_MC2   ((float)0.4)  // unit: amp
#define ALIGNMENT_CURRENT_AMP_MC3   ((float)0.4)  // unit: amp  


    
/* rotor angle calibration constants */    
/* states for hall_cali */
#define HALL_CALI_INI       (0u)
#define HALL_CALI_IDLE      (1u)
#define HALL_CALI_WAITING   (2u)
/* states for index_cali */
#define INDEX_CALI_WAITING      (0u)
#define INDEX_CALI_ANGLE_CALC   (1u)

#define MC_CONTROL_MODE_1            position_mode  
#define MC_CONTROL_MODE_2            position_mode
#define MC_CONTROL_MODE_3            position_mode

#define POS_POT_FULLSACLE            (2u)  // unit round; 
  
#undef  EN_POS_FF_COMPENSATION      
// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
   
typedef enum
{
    mc_initial,
    mc_idle,
    mc_rotor_alignment,          //Lock Rotor  
    mc_open_loop,                 
    mc_closed_loop,    
    mc_fault                     // Motor is in Fault

}MOTOR_CONTROL_STATE_E;

typedef struct 
{
    uint8_t state;
    uint8_t isEnter1stTime;
    uint32_t cnt;
}MC_STATE_MACHINE;


typedef struct 
{
    /* inputs */
    int32_t qei_cnt_read;
    uint32_t index_event_cnt;
    int32_t qei_cap_cnt;
    /* inter-media */
    bool is_index_detected;    
    bool is_ini_finished; /* Is the initialization finished or not? */
    uint8_t hall_value;
    uint8_t hall_value_latch;  
    int32_t cnt_since_index;
    int32_t qei_cap_cnt_correct;    
    /* parameters */
    int32_t index_angle_cnt; /* the rotor angle when index event is detected */  
    float cnt2rad;     
    int32_t cnt_upper_boundary;
    int32_t index_cnt_tolerance;    
    /* outputs */
    int32_t qei_cnt_write;    
    int32_t rotor_angle_cnt;
    float rotor_angle_rad;    
}MC_ROTOR_ANGLE;


typedef struct 
{
    bool      input; /* read value of button input pin */
    uint16_t  state;
    uint32_t  debounce_counter;
} MC_BUTTON_T;

typedef enum
{
    mc_button_ready,
    mc_button_wait
}MC_BUTTON_STATE_E;

typedef enum
{
  disable,
  speed_mode,
  position_mode,
  torque_mode
          
}MC_CONTROL_MODE_E;

typedef struct 
{      
    MOTOR_CONTROL_STATE_E    state;

    MC_BUTTON_T              button;

    uint16_t                 ticks_counter_1ms;
    uint16_t                 ticks_counter_current_loop;
    uint16_t                 ticks_counter_speed_loop;

    uint32_t                 alignment_counter;
    float                    alignment_current;
    uint32_t                 alignment_period;

    uint16_t                 current_loop_sync_ratio;
    float                    current_loop_bandwidth;

    uint16_t                 speed_loop_sync_ratio;
    float                    speed_loop_bandwidth;
    float                    speed_loop_freq_HZ;

    float                    position_loop_bandwidth;
    float                    position_loop_ff;   //forward factor;
    
    bool                     one_ms_flag;

    float                    cmd_lpf_factor;

    MC_FIRST_ODER_FILTER_T   vbus_filter;
    float                    vbus_VOLT; 

    MC_FIRST_ODER_FILTER_T   speed_ref_filter;
    MC_FIRST_ODER_FILTER_T   speed_feedback_filter;
    float                    speed_ref_RPM; 
    float                    speed_ref_PU;             
    float                    speed_feedback_PU;   
    float                    speed_feedback_RPM;   
    float                    speed_feedback_lpf_factor;
    float                    rated_mech_speed_pps; //pulse per second;

    MC_FIRST_ODER_FILTER_T   position_ref_filter;
    MC_FIRST_ODER_FILTER_T   position_forwardfeed_filter;    
    int32_t                  position_ref_cnt;
    int32_t                  position_ref_cnt_pre;
    int32_t                  position_feedback_cnt;
    int32_t                  position_cnt_pre;
    int32_t                  position_cnt_delta;

    HAL_CHANNEL_ID_E         controller_id;  
    MC_FOC_T                 foc;          
    MC_SVPWM_T               svm;
    MC_PID_CONTROLLER_T      speed_pid;
  
    MC_PID_CONTROLLER_T      position_ctrl;

    MC_ROTOR_ANGLE           rotor_angle_data;
    MC_STATE_MACHINE         state_rotor_angle_calc;
    
    HAL_STARTUP_MODE_E       startup_mode;
    ROTOR_ANGLE_CALI_MODE_E  rotor_angle_cali_mode;

    MC_CONTROL_MODE_E        control_mode;
 
} MC_CONTROLLER_T;


extern  MC_CONTROLLER_T                  g_mc_controller[NUM_OF_MOTOR];

// *****************************************************************************
// *****************************************************************************
// Section: Function Declarations
// *****************************************************************************
// *****************************************************************************

void MC_ControllerInitial(void);
void MC_MotorStart(MC_CONTROLLER_T *pMotorControl);
void MC_MotorStop(MC_CONTROLLER_T *pMotorControl);
void MC_AlignmentRun(MC_CONTROLLER_T *pMotorControl);

#ifdef __cplusplus
}
#endif

#endif /* end of _MC_CONTROL_LOOP_H */

/*******************************************************************************
 End of File
*/    

