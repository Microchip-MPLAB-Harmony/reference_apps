/*******************************************************************************
 Motor Control Hardware Abstraction interface file

  Company:
    Microchip Technology Inc.

  File Name:
    hal_analog_feedback.h

  Summary:
    Header file for ananlog feedback hardware abstraction

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

#ifndef _HAL_ANALOG_FEEDBACK_H
#define _HAL_ANALOG_FEEDBACK_H



// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stdint.h>
#include "hal_configure_common.h" 



#ifdef __cplusplus
extern "C" {
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Macro Defines
// *****************************************************************************
// *****************************************************************************
#define OFFSET_COUNT_BITS        (uint16_t)10
#define OFFSET_COUNT_MAX         (uint16_t)(1 << OFFSET_COUNT_BITS)

#define ADC_RESOLUTION_BIT       (uint16_t)12     /*  ADC Resolution Bit*/
#define ADC_RESOLUTION           (float)(1<<ADC_RESOLUTION_BIT)     
#define CURRENT_RESOLUTION       (float)(1<<(ADC_RESOLUTION_BIT-1))     
#define MAX_ADC_INPUT_VOLTAGE    (float)3.3       /* volts */

#define DCBUS_SENSE_RATIO        (float)0.0625    /* Voltage divider ratio R2/(R2 + R1) */



#define HAL_CURRENT_FULL_SCALE   (float)(5.94)//(unit: A)
#define HAL_VBUS_FULL_SCALE      (float)(MAX_ADC_INPUT_VOLTAGE / DCBUS_SENSE_RATIO)

/*Configure Motor1 drive related definations*/
/*Configre current feedback channel*/
#define HAL_IU_ADC_CH_1    ADCHS_CH0
#define HAL_IV_ADC_CH_1    ADCHS_CH3

#define HAL_VBUS_ADC_CH_1  ADCHS_CH21

/*Configure Motor2 drive related definations*/
/*Configre current feedback channel*/
#define HAL_IU_ADC_CH_2    ADCHS_CH1
#define HAL_IV_ADC_CH_2    ADCHS_CH4

 
#define HAL_VBUS_ADC_CH_2  ADCHS_CH16

/*Configure Motor3 drive related definations*/
/*Configre current feedback channel*/
#define HAL_IU_ADC_CH_3    ADCHS_CH2
#define HAL_IV_ADC_CH_3    ADCHS_CH5

#define HAL_VBUS_ADC_CH_3  ADCHS_CH22

#define HAL_AdcCallbackRegister(ch, fn, context)       ADCHS_CallbackRegister(ch, fn, context)

#define HAL_ADC_IRQ               (INT_SOURCE_ADC_DATA0)

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

typedef struct
{
    //Configure ADC channel of Motor.

    uint8_t i_u_adc_channel;
    
    uint8_t i_v_adc_channel;

    uint8_t i_w_adc_channel;

    uint8_t ibus_adc_channel;
    
}HAL_CURRENT_FB_CONFIG_T;



typedef struct
{
    int16_t        offset_a;       // A phase current offset 
    int16_t        offset_b;       // B phase current offset 
    int16_t        offset_c;       // C phase current offset 
    int16_t        offset_bus;     // BUS current offset 
    int16_t        a;             // A phase Current Feedback
    int16_t        b;             // B phase Current Feedback
    int16_t        c;             // C phase Current Feedback
    int16_t        bus;           // BUS current Feedback 
    int16_t        counter;        // counter 
    int16_t        offset_calibration_done;      // flag to indicate offset measurement completion

    int32_t        sum_a;          // Accumulation of Ia 
    int32_t        sum_b;          // Accumulation of Ib 
    int32_t        sum_c;          // Accumulation of Ic 
    int32_t        sum_bus;        // Accumulation of Ibus

} HAL_CURRENT_FB_T;


typedef struct
{
    uint8_t vbus_channel;

}HAL_VOLTAGE_FB_CONFIG_T;




// *****************************************************************************
// *****************************************************************************
// Section: Function Declarations
// *****************************************************************************
// *****************************************************************************

void HAL_CurrentOffsetCalibration(HAL_CHANNEL_ID_E id);
void HAL_CurrentCalc(HAL_CHANNEL_ID_E id, HAL_VECTOR3_T * const pPhaseCurrent);
void HAL_CurrentOffsetInitial(HAL_CURRENT_FB_T * const pCurrentFB);
float HAL_VbusRead(HAL_CHANNEL_ID_E id);


#ifdef __cplusplus
}
#endif

#endif /* end of _HAL_ANALOG_FEEDBACK_H */

/*******************************************************************************
 End of File
*/
