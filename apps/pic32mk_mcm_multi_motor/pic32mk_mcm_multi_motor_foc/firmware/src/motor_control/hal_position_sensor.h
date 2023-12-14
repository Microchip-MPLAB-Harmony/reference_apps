/*******************************************************************************
 Motor Control Hardware Abstraction interface file

  Company:
    Microchip Technology Inc.

  File Name:
    hal_position_sensor.h

  Summary:
    Header file for position feedback hardware abstraction

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

#ifndef _HAL_POSITON_SENSOR_H
#define _HAL_POSITON_SENSOR_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stdint.h>
#include "hal_configure_common.h"  
#include "definitions.h" 

#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif



// *****************************************************************************
// *****************************************************************************
// Section: Macro Defines
// *****************************************************************************
// *****************************************************************************
#define HAL_POS_CH_1                qei_ch_1
#define HAL_POS_CH_2                qei_ch_2
#define HAL_POS_CH_3                qei_ch_3

#define HAL_HALL_A_1                HALL_A_1_PIN
#define HAL_HALL_B_1                HALL_B_1_PIN
#define HAL_HALL_C_1                HALL_C_1_PIN

#define HAL_HALL_A_2                HALL_A_2_PIN
#define HAL_HALL_B_2                HALL_B_2_PIN
#define HAL_HALL_C_2                HALL_C_2_PIN

#define HAL_HALL_A_3                HALL_A_3_PIN
#define HAL_HALL_B_3                HALL_B_3_PIN
#define HAL_HALL_C_3                HALL_C_3_PIN


/* HALL angle definitions */
#define     DEGREE_60_PU   (float)(0.16667)  /* 60 = 360* 1/6 */
#define     DEGREE_120_PU  (float)(0.33333)  /* 120 = 360* 1/3 */
#define     DEGREE_180_PU  (float)(0.5)      /* 180 = 360* 1/2 */
#define     DEGREE_240_PU  (float)(0.66667)  /* 240 = 360* 2/3 */
#define     DEGREE_300_PU  (float)(0.83333)  /* 300 = 360* 5/6 */
#define     DEGREE_360_PU  (float)(1.0)  

#define     DEGREE_30_PU   (float)(0.08333)  /* 30 = 360* 1/12 */
#define     DEGREE_90_PU   (float)(0.25)  /* 90 = 360* 1/4 */
#define     DEGREE_150_PU  (float)(0.41667)  /* 150 = 360* 5/12 */
#define     DEGREE_210_PU  (float)(0.58333)  /* 210 = 360* 7/12 */
#define     DEGREE_270_PU  (float)(0.75)  /* 270 = 360* 3/4 */
#define     DEGREE_330_PU  (float)(0.91667)  /* 330 = 360* 11/12 */

/*HALL signal value relation with angle*/
#define HALL_SECTOR_1    (uint8_t)0x05    //HALL value  0x05 (A:1,B:0,C:1) stand for range:30-90 degree;
#define HALL_SECTOR_2    (uint8_t)0x01    //HALL value  0x01 (A:1,B:0,C:0) stand for range:90-150 degree;
#define HALL_SECTOR_3    (uint8_t)0x03    //HALL value  0x03 (A:1,B:1,C:0) stand for range:150-210 degree;
#define HALL_SECTOR_4    (uint8_t)0x02    //HALL value  0x02 (A:0,B:1,C:0) stand for range:210-270 degree;
#define HALL_SECTOR_5    (uint8_t)0x06    //HALL value  0x06 (A:0,B:1,C:1) stand for range:270-330 degree;
#define HALL_SECTOR_6    (uint8_t)0x04    //HALL value  0x04 (A:0,B:0,C:1) stand for range:330-30 degree;



// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
typedef struct
{   

    uint32_t     position_count;
    uint32_t     velocity_count;
    

}HAL_POS_SENSOR_T;

typedef struct
{   

    uint8_t     hall_a;
    uint8_t     hall_b;
    uint8_t     hall_c;
    uint8_t     hall_value;
    uint32_t    hall_angle_counter;

}HAL_HALL_SENSOR_T;


typedef struct
{   

    uint8_t     port_a;
    uint8_t     port_b;
    uint8_t     port_c;

}HAL_HALL_CONFIG_T;


extern float HallSensorTable[7u];
// *****************************************************************************
// *****************************************************************************
// Section: Function Declarations
// *****************************************************************************


uint32_t HAL_HallStatusRead(HAL_CHANNEL_ID_E id);
void HAL_QeiStart(HAL_POS_CH_E channel);
uint32_t HAL_LookupCalibrateQeiCnt(uint8_t hall_value_pre, uint8_t hall_value_now, HAL_CHANNEL_ID_E id);
void HAL_QeiPositionWindowSet(HAL_POS_CH_E channel, uint32_t high_threshold, uint32_t low_threshold);
void HAL_QeiIndexModeSet(HAL_POS_CH_E channel, uint32_t index_mode);
void HAL_QeiIndexCaptureEnable(HAL_POS_CH_E channel);
void HAL_QeiIndexCaptureDisable(HAL_POS_CH_E channel);

__STATIC_INLINE void HAL_PositionCountSet(uint32_t position_count, HAL_POS_CH_E channel)
{
    (*(&POS1CNT + (0x80 * (channel)))) = position_count;
}

__STATIC_INLINE void HAL_VelocityCountSet(uint32_t velocity_count, HAL_POS_CH_E channel)
{
    (*(&VEL1CNT + (0x80 * (channel)))) = velocity_count;
}

__STATIC_INLINE uint32_t HAL_PositionGet(HAL_POS_CH_E channel)
{
    return (*(&POS1CNT + (0x80 * (channel))));
}

__STATIC_INLINE uint32_t HAL_CapturedPositionGet(HAL_POS_CH_E channel)
{
    return (*(&QEI1ICC + (0x80 * (channel))));
}

__STATIC_INLINE uint32_t HAL_VelocityGet(HAL_POS_CH_E channel)
{
    return (*(&VEL1CNT + (0x80 * (channel))));
}

__STATIC_INLINE uint32_t HAL_RevolutionsGet(HAL_POS_CH_E channel)
{
    return (*(&INDX1CNT + (0x80 * (channel))));
}

__STATIC_INLINE uint32_t HAL_QeiStatusGet(HAL_POS_CH_E channel)
{
    return (*(&QEI1STAT + (0x80 * (channel))));
}

__STATIC_INLINE bool HAL_IndexEventCheck(HAL_POS_CH_E channel)
{
    bool isIndexDetected;
    volatile __QEI1STATbits_t * addr;
    
    addr = &QEI1STATbits + (0x80 * (channel));
    
    if(1 == (addr->IDXIRQ)){
        isIndexDetected = true;
    }else{
        isIndexDetected = false;
    }
    return (isIndexDetected);
}

__STATIC_INLINE void HAL_IndexEventClear(HAL_POS_CH_E channel)
{
    (*(&QEI1STATCLR + (0x80 * (channel)))) = 0x0002;
}

#ifdef __cplusplus  // Provide C++ Compatibility
    }
#endif


#endif // _HAL_POSITON_SENSOR_H

/*******************************************************************************
 End of File
*/    
    