/*******************************************************************************
  System Definitions

  File Name:
    userparams.h

  Summary:
    Header file which defines Motor Specific and Board Specific constants

  Description:
    This file contains the motor and board specific constants. It also defines
 * switches which allows algorithm to be run in debug modes like Open Loop Mode,
 * Torque mode, etc.

 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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
// DOM-IGNORE-END


#ifndef USERPARAMS_H
#define USERPARAMS_H


/*******************************************************************************
Control Parameters
*******************************************************************************/
#define MC_FREQ_HZ                 (120000000.0f)     //CPU frequency

#define PWM_FREQUENCY              (25)               //in kHz

#define PWM_PERIOD                 (2400U)

/*******************************************************************************
Motor definitions
*******************************************************************************/
/* motor and application related parameters */

#define MOTOR_POLE_PAIRS            (5U)

#define MAX_MOTOR_SPEED             (3000U)

#define SPEED_KP_DEFAULT            (30U)

#define SPEED_KI_DEFAULT            (5U)

#define DEFAULT_DUTY                (uint16_t) ( 0.025 * PWM_PERIOD)

#define PI_BUF_INIT                 (DEFAULT_DUTY << 15)



#define MOTOR_RAMPUP_SPEED_PER_MS   (5U)

#define DEFAULT_SPEED_TARGET        ((DEFAULT_DUTY << 14)/PWM_PERIOD)

/*[Min speed in internal units range 0 - 10 Max; Typically less than 0% -10% of 2^14]*/
#define SPEED_MIN_LOW               (5U)

#define SPEED_MIN_TARGET            (uint16_t)(( 1 << 14) * SPEED_MIN_LOW / 100)

#define SPEED_MIN_LIMIT             (0U)

#define SPEED_MAX_LIMIT             (PWM_PERIOD)


/*******************************************************************************
 * Calculated macros
*******************************************************************************/
#define COUNT_10_MS                 (uint16_t)(PWM_FREQUENCY * 10)      //As PWM_FREQUENCY is given in KHz

/* Average Speed calculation factor */
#define MOTOR_SPEED_CALCFACTOR       6                                  // (MOTOR_POLE_PAIRS * 6U)

#define MAX_POT_REF                 (4095U)


/*******************************************************************************
 * Hall Parameters
*******************************************************************************/



#define HALL_1_MASK                 (0U)

#define HALL_2_MASK                 (1U)

#define HALL_3_MASK                 (2U)

/* if the Hall sensor reads 0x0 or 0x7 that means either one of the hall sensor is damaged or disconnected*/
#define INVALID_HALL_0              (0U)

#define INVALID_HALL_7              (7U)

#define PATT_MASK                   (0x00FF)

#define PATT_MASK_POSITION          (8U)

#define TCC_PWM_MASK                (0x77)

#endif  // USERPARAMS_H


/*******************************************************************************
 End of File
*/

