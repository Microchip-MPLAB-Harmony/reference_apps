/*******************************************************************************
  Motor Control Hardware Abstraction interface file

  Company:
    Microchip Technology Inc.

  File Name:
    hal_configure_common.h

  Summary:
    Motor control config parameters 

  Description:
    This file contains the data structures of motor control.
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

#ifndef _HAL_CONFIGURE_COMMON_H
#define _HAL_CONFIGURE_COMMON_H

#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif

        
        


typedef enum
{
    channel_id_a = 0,         
    channel_id_b,          
    channel_id_c,
    channel_id_d 

}HAL_CHANNEL_ID_E;


typedef enum
{
    qei_ch_1 = 0,
    qei_ch_2,
    qei_ch_3,
    qei_ch_4,
    qei_ch_5

} HAL_POS_CH_E;

typedef enum
{
    hall_startup,
    alignment_startup
}HAL_STARTUP_MODE_E;

#define INDEX_CALI 0
#define NO_CALI 1
#define HALL_CALI 2

typedef enum
{
    index_cali = INDEX_CALI,
    no_cali = NO_CALI,
    hall_cali = HALL_CALI
}ROTOR_ANGLE_CALI_MODE_E;    

typedef struct 
{
    // Phase A component 
    float a;
    
    // Phase B component
    float b;
    
    // Phase C component
    float c;
} HAL_VECTOR3_T;


typedef struct
{
    float    R_Ohm;
    float    L_H;
    float    inertia;
    float    k_bemf;
    float    max_current_Amp;
    int16_t  pole_pairs;
    int16_t  max_speed_RPM;
    int16_t  rated_speed_RPM;
    float    rated_speed_mech_HZ;
    float    rated_speed_mech_rad_s;
    float    rated_speed_elec_HZ;
    int32_t  encoder_PPR;
    int32_t  encoder_elec_PPR;
    float    *pHall_sensor_table;
    int32_t  index_angle_cnt;
    int32_t  index_cnt_tolerance;
    float    hall_offset;

}HAL_MOTOR_PARAMETERS_T;



#ifdef __cplusplus  // Provide C++ Compatibility
    }
#endif


#endif // _HAL_CONFIGURE_COMMON_H

/*******************************************************************************
 End of File
*/     