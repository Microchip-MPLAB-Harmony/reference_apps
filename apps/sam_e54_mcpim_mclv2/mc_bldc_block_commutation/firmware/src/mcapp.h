/*******************************************************************************
  System Definitions

  File Name:
    mcapp.h

  Summary:
    Header file which shares global variables and function prototypes.

  Description:
    This file contains the global variables and function prototypes for a motor control project.

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

#ifndef MCAPP_H
#define MCAPP_H

#include <stdbool.h>
#include "userparams.h"
#include "q14.h"

/*******************************************************************************
Public typedefs
*******************************************************************************/


typedef enum
{
  NO_START_CMD,
  STOP_CMD,
  OC_FAULT_STOP

} STOP_SOURCE;


typedef struct
{
  uint16_t speedRefPot;
  uint16_t setSpeedTarget;
  uint16_t speedReferenceTarget;
  uint16_t speedReferenceRPM;
  uint32_t avgTimeStorage;
  uint32_t avgCycleTime;
  uint16_t actualSpeed;
  uint16_t actualSpeedTarget;
  uint16_t avgCtr;
  uint16_t motorCurrent;
  uint32_t speedConstant;
  uint8_t  speedPiEnable;

}MOTOR_BC_PARAMS;


typedef struct
{
  STOP_SOURCE motorStopSource;
  uint8_t  stateRun;
  uint8_t  switchState;
  uint8_t  direction;
  uint8_t  directionOffset;
  uint8_t  varTime10MS;
  uint8_t  varCnt10MS;

}MOTOR_STATE_PARAMS;



typedef struct
{
  uint8_t   currentHallPattern;
  uint16_t  nextPattern;
  uint8_t   pattEnable;
  uint8_t   pattValue;
  uint16_t  patternCommutation;
  uint8_t   currentHall1;
  uint8_t   currentHall2;
  uint8_t   currentHall3;

}MOTOR_HALL_PARAMS;


extern PI_CONTROL_TYPE  speedPi;

/*******************************************************************************
Public functions prototypes
*******************************************************************************/

void MCAPP_MotorControlVarsInit(void);
void Motor_Start(void);
void Motor_Stop(void);
void MCAPP_Start(void);



#endif  // MCAPP_H


/*******************************************************************************
 End of File
*/