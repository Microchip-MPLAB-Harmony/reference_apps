/*******************************************************************************
 Motor Control Hardware Abstraction interface file

  Company:
    Microchip Technology Inc.

  File Name:
    hal_position_sensor.c

  Summary:
    Position feedback hardware abstraction

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
              
#include "hal_position_sensor.h"   
#include "hal_board_configure.h" 


float HallSensorTable[7u] = {
    0,              /* 0: dummy */
    DEGREE_90_PU,   /* 1 */
    DEGREE_210_PU,  /* 2 */
    DEGREE_150_PU,  /* 3 */
    DEGREE_330_PU,  /* 4 */
    DEGREE_30_PU,   /* 5 */
    DEGREE_270_PU,  /* 6 */
};



void HAL_QeiStart(HAL_POS_CH_E channel)
{
    /* Enable QEI channel */
    (*(&QEI1CON + (0x80 * (channel)))) |= _QEI1CON_QEIEN_MASK;
}

void HAL_QeiStop(HAL_POS_CH_E channel)
{
    /* Disable QEI channel */
    (*(&QEI1CON + (0x80 * (channel)))) &= ~_QEI1CON_QEIEN_MASK;
}

void HAL_QeiIndexModeSet(HAL_POS_CH_E channel, uint32_t index_mode)
{
    (*(&QEI1CON + (0x80 * (channel)))) = index_mode;  

}

void HAL_QeiIndexCaptureEnable(HAL_POS_CH_E channel)
{
    (*(&QEI1IOC + (0x80 * (channel)))) |= _QEI1IOC_QCAPEN_MASK;
}

void HAL_QeiIndexCaptureDisable(HAL_POS_CH_E channel)
{
    (*(&QEI1IOC + (0x80 * (channel)))) &= ~_QEI1IOC_QCAPEN_MASK;
}
uint32_t HAL_PulseIntervalGet(HAL_POS_CH_E channel)
{
    return (*(&INT1HLD + (0x80 * (channel))));
}

void HAL_QeiPositionWindowSet(HAL_POS_CH_E channel, uint32_t high_threshold, uint32_t low_threshold)
{
    (*(&QEI1ICC + (0x80 * (channel)))) = high_threshold;
    (*(&QEI1CMPL + (0x80 * (channel)))) = low_threshold;
}

uint32_t HAL_HallStatusRead(HAL_CHANNEL_ID_E id)
{
    HAL_HALL_SENSOR_T      *pHall;
    HAL_HALL_CONFIG_T      *pHallConfig;    
    HAL_MOTOR_PARAMETERS_T *pMotorPara; 
    int32_t ppr;
    float tmpFlt;
    uint32_t tmp32;

    pMotorPara = hal_motor_control_channel[id].pMotor;
    pHallConfig = &(hal_motor_control_channel[id].hall_sensor_config);
    pHall = &(hal_motor_control_channel[id].hall_sensor);
    ppr = pMotorPara->encoder_elec_PPR;

    pHall->hall_a =  GPIO_PinRead(pHallConfig->port_a);
    pHall->hall_b =  GPIO_PinRead(pHallConfig->port_b);
    pHall->hall_c =  GPIO_PinRead(pHallConfig->port_c);

    pHall->hall_value = (pHall->hall_c <<2) | (pHall->hall_b <<1) |(pHall->hall_a); 


    tmpFlt = (*(pMotorPara->pHall_sensor_table + pHall->hall_value) + pMotorPara->hall_offset) * (float)ppr;
    tmp32 = (uint32_t)(tmpFlt + 0.5f);
    if(tmp32 >= ppr)
    {
        pHall->hall_angle_counter = tmp32 - ppr;
    }
    else
    {
        pHall->hall_angle_counter = tmp32;
    }
    
    return pHall->hall_angle_counter;
}

uint32_t HAL_LookupCalibrateQeiCnt(uint8_t hall_value_pre, uint8_t hall_value_now, HAL_CHANNEL_ID_E id)
{
    HAL_MOTOR_PARAMETERS_T *pMotorPara; 
    pMotorPara = hal_motor_control_channel[id].pMotor;
    int32_t ppr = pMotorPara->encoder_elec_PPR;
    float tmpFlt;
    uint32_t tmp32;
    float qeiCntCrtVal=0.0f;
    
    /* Look for the QEI counter correction value. */
    if(((hall_value_pre == HALL_SECTOR_1) && (hall_value_now == HALL_SECTOR_2)) || ((hall_value_pre == HALL_SECTOR_2) && (hall_value_now == HALL_SECTOR_1)))
    {
        qeiCntCrtVal = DEGREE_60_PU;
    } 
    else if(((hall_value_pre == HALL_SECTOR_2) && (hall_value_now == HALL_SECTOR_3)) || ((hall_value_pre == HALL_SECTOR_3) && (hall_value_now == HALL_SECTOR_2)))
    {
        qeiCntCrtVal = DEGREE_120_PU;    
    } 
    else if(((hall_value_pre == HALL_SECTOR_3) && (hall_value_now == HALL_SECTOR_4)) || ((hall_value_pre == HALL_SECTOR_4) && (hall_value_now == HALL_SECTOR_3)))
    {
        qeiCntCrtVal = DEGREE_180_PU;    
    } 
    else if(((hall_value_pre == HALL_SECTOR_4) && (hall_value_now == HALL_SECTOR_5)) || ((hall_value_pre == HALL_SECTOR_5) && (hall_value_now == HALL_SECTOR_4)))
    {
        qeiCntCrtVal = DEGREE_240_PU;    
    } 
    else if(((hall_value_pre == HALL_SECTOR_5) && (hall_value_now == HALL_SECTOR_6)) || ((hall_value_pre == HALL_SECTOR_6) && (hall_value_now == HALL_SECTOR_5)))
    {
        qeiCntCrtVal = DEGREE_300_PU;    
    } 
    else if(((hall_value_pre == HALL_SECTOR_6) && (hall_value_now == HALL_SECTOR_1)) || ((hall_value_pre == HALL_SECTOR_1) && (hall_value_now == HALL_SECTOR_6)))
    {
        qeiCntCrtVal = DEGREE_360_PU;    
    } 
    else
    {
    }    


    tmpFlt = (qeiCntCrtVal+pMotorPara->hall_offset) * (float)ppr;
    tmp32 = (uint32_t)(tmpFlt + 0.5f);
    if(tmp32 >= ppr)
    {
        tmp32 = tmp32 - ppr;
    }

    return tmp32;    

}


/*******************************************************************************
 End of File
*/    
