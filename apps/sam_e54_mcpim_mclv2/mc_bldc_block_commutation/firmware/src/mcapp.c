/*******************************************************************************
 Motor Control Application Source file

  Company:
    Microchip Technology Inc.

  File Name:
    mcapp.c

  Summary:
    This file contains all the functions related to motor control application

  Description:
    This file contains implementation of the application state machine

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


/*******************************************************************************
Headers inclusions
*******************************************************************************/
#include "device.h"
#include "definitions.h"
#include <sys/attribs.h>
#include "mcapp.h"


/*******************************************************************************
Variables
*******************************************************************************/
MOTOR_BC_PARAMS         Motor_BCParams;
MOTOR_HALL_PARAMS       Motor_HallParams;
MOTOR_STATE_PARAMS      Motor_StateParams;
PI_CONTROL_TYPE         Motor_Speed_PIParams;


/* Hall Pattern
 * first 8 entries are for clockwise direction and later 8 for anti-clockwise direction
 */
const uint16_t HALL_ARRAY[16] = { 0, 5, 3, 1, 6, 4, 2, 0, 0, 3, 6, 2, 5, 1, 4, 0 };


/* Commutation Pattern as per Hall Pattern
 * first 8 entries are for clockwise direction and later 8 for anti-clockwise direction*/
const uint16_t COMMUTATION_ARRAY[16] =
{
    0,
    /* to achieve B+ C-, put the following in Pattern register H1H2H3: 001 */
    0x4075, //0x4075, HS ; 0x0237U, LS
    /* to achieve A+ B-, put the following in Pattern register H1H2H3: 010 */
    0x2076, //0x2076, HS ; 0x0157U, LS
    /* to achieve A+ C-, put the following in Pattern register H1H2H3: 011 */
    0x4076, //0x4076, HS ; 0x0137U, LS
    /* to achieve C+ A-, put the following in Pattern register H1H2H3: 100 */
    0x1073, //0x1073, HS ; 0x0467U, LS
    /* to achieve B+ A-, put the following in Pattern register H1H2H3: 101 */
    0x1075, //0x1075, HS ; 0x0267U, LS
    /* to achieve C+ B-, put the following in Pattern register H1H2H3: 110 */
    0x2073, //0x2073, HS ; 0x0457U, LS
    /* Not a valid pattern */
    0,
    0,
    0x2073,
    0x1075,
    0x1073,
    0x4076,
    0x2076,
    0x4075,
    0
};


/*******************************************************************************
Function Prototypes
*******************************************************************************/
void EIC_START_STOP_InterruptHandler(uintptr_t context);
void EIC_FORWARD_REVERSE_InterruptHandler(uintptr_t context);
void ADC0_InterruptHandler(ADC_STATUS status, uintptr_t context);
void TC0_1ms_InterruptHandler(TC_TIMER_STATUS status, uintptr_t context);
void PDEC_VLC_InterruptHandler(PDEC_HALL_STATUS status, uintptr_t context);


/*******************************************************************************
Functions
*******************************************************************************/

/******************************************************************************
Function:     MCAPP_MotorControlVarsInit
Description:  motor control variable initialization
Input:        nothing (uses some global variables)
Output:       nothing (modifies some global variables)
Note:         to be called once before starting the control functions
******************************************************************************/
void MCAPP_MotorControlVarsInit(void)
{
    /* Initialize all the parameters to default value*/
    Motor_StateParams.stateRun = 0;
    Motor_StateParams.motorStopSource = NO_START_CMD;
    Motor_StateParams.directionOffset = 0;
    Motor_StateParams.switchState = 0;
    Motor_StateParams.direction = 0;

    Motor_HallParams.currentHallPattern = 1;
    Motor_HallParams.nextPattern = 3;

    Motor_Speed_PIParams.error = 0;
    Motor_Speed_PIParams.kp = (int32_t)SPEED_KP_DEFAULT;
    Motor_Speed_PIParams.ki = (int32_t)SPEED_KI_DEFAULT;
    Motor_Speed_PIParams.maxLimit = SPEED_MAX_LIMIT;
    Motor_Speed_PIParams.minLimit = SPEED_MIN_LIMIT;
    Motor_Speed_PIParams.outputValue = 0;
    Motor_Speed_PIParams.integratorBuf = 0;

    Motor_BCParams.speedConstant = (TC1_TimerFrequencyGet() * 10) / MOTOR_POLE_PAIRS;
    Motor_BCParams.speedPiEnable = 0;

}

/******************************************************************************
Function:     MCAPP_Start
Description:  motor control initialization function
Input:        nothing (uses some global variables)
Output:       nothing (modifies some global variables)
Note:         to be called once at application startup
******************************************************************************/
void MCAPP_Start(void)
{

    /* Hall decoder interrupt handler */
    PDEC_HALLCallbackRegister(PDEC_VLC_InterruptHandler ,(uintptr_t) NULL );

    /* ADC result ready interrupt handler to read Potentiometer value */
    ADC0_CallbackRegister(ADC0_InterruptHandler ,(uintptr_t) NULL );

    /* Start/Stop button interrupt handler */
    EIC_CallbackRegister(EIC_PIN_4, EIC_START_STOP_InterruptHandler ,(uintptr_t) NULL);

    /* Forward/Reverse button interrupt handler */
    EIC_CallbackRegister(EIC_PIN_5, EIC_FORWARD_REVERSE_InterruptHandler ,(uintptr_t) NULL);

    /* 1mS timer interrupt handler for speed calculation */
    TC0_TimerCallbackRegister(TC0_1ms_InterruptHandler, (uintptr_t)NULL);

    /* Initialize all the motor control parameters */
    MCAPP_MotorControlVarsInit();

    ADC0_Enable();

    PDEC_HALLStart();

    TCC0_PWMStart();

    /* Start 1 mS timer */
    TC0_TimerStart();

    /* Disable all PWM outputs */
    TCC0_PWMPatternSet(TCC_PWM_MASK, 0x0);
}

/******************************************************************************
Function:     Motor_Start
Description:  motor control start function
Input:        nothing (uses some global variables)
Output:       nothing (modifies some global variables)
Note:         called when start button is pressed
******************************************************************************/
void Motor_Start(void)
{
    Motor_Speed_PIParams.integratorBuf = 0;
    Motor_Speed_PIParams.outputValue = 0;

    Motor_BCParams.actualSpeed = 0;
    Motor_BCParams.avgTimeStorage = 0;
    Motor_BCParams.avgCycleTime = 0;
    Motor_BCParams.avgCtr = (uint16_t) MOTOR_SPEED_CALCFACTOR;
    Motor_BCParams.actualSpeedTarget = 0;
    Motor_BCParams.speedPiEnable = 0;

    /* Initialize duty cycle */
    TCC0_PWM24bitDutySet(TCC0_CHANNEL0, DEFAULT_DUTY);
    Motor_BCParams.speedReferenceTarget = DEFAULT_SPEED_TARGET;


    /* Read the current hall pattern */
    Motor_HallParams.currentHall1 = PORT_PinRead(PORT_PIN_PC16);     // HALL A
    Motor_HallParams.currentHall2 = PORT_PinRead(PORT_PIN_PC17);     // HALL B
    Motor_HallParams.currentHall3 = PORT_PinRead(PORT_PIN_PC18);     // HALL C

    Motor_HallParams.currentHallPattern = ((Motor_HallParams.currentHall3 << HALL_3_MASK) |
                                           (Motor_HallParams.currentHall2 << HALL_2_MASK) |
                                           (Motor_HallParams.currentHall1 << HALL_1_MASK)
                                          );
    /* Check the Hall pattern is a valid pattern */
    if ((Motor_HallParams.currentHallPattern != INVALID_HALL_0) && (Motor_HallParams.currentHallPattern != INVALID_HALL_7))
    {
        /* Load the next pattern commutation to the Pattern Generator */
        Motor_HallParams.patternCommutation = COMMUTATION_ARRAY[Motor_HallParams.currentHallPattern + Motor_StateParams.directionOffset];
        Motor_HallParams.pattEnable = (uint8_t)(Motor_HallParams.patternCommutation & PATT_MASK);
        Motor_HallParams.pattValue  = (uint8_t)((Motor_HallParams.patternCommutation >> PATT_MASK_POSITION ) & PATT_MASK);

        TCC0_PWMPatternSet(Motor_HallParams.pattEnable, Motor_HallParams.pattValue);

        /* Update the next pattern in the pattern array */
        Motor_HallParams.nextPattern = HALL_ARRAY[Motor_HallParams.currentHallPattern+ Motor_StateParams.directionOffset];

    }

    /* Start the timer used for Speed calculation */
    TC1_TimerStart();
}


/******************************************************************************
Function:     Motor_Stop
Description:  motor control stop function
Input:        nothing (uses some global variables)
Output:       nothing (modifies some global variables)
Note:         called when stop button is pressed
******************************************************************************/
void Motor_Stop(void)
{
    /* Disable all PWM outputs */

    TCC0_PWMPatternSet(TCC_PWM_MASK, 0x0);
    TCC0_PWM24bitDutySet(TCC0_CHANNEL0, 0);

    /* Set all speed control parameters to default value */
    Motor_BCParams.setSpeedTarget = 0;
    Motor_BCParams.speedReferenceRPM= 0;
    Motor_BCParams.actualSpeed = 0;
    Motor_BCParams.actualSpeedTarget = 0;
    Motor_BCParams.speedPiEnable = 0;
    Motor_Speed_PIParams.integratorBuf = 0;

    /* Stop the timer used for Speed calculation */
    TC1_TimerStop();
    Motor_StateParams.motorStopSource = STOP_CMD;
}


/******************************************************************************
Function:     EIC_START_STOP_InterruptHandler
Description:  Start/Stop button ISR
Input:        nothing (uses some global variables)
Output:       nothing (modifies some global variables)
Note:         called when Start/Stop switch is pressed
******************************************************************************/
void EIC_START_STOP_InterruptHandler(uintptr_t context)
{
   /* Motor state (Start/Stop) toggled for every event on switch (S2) */
   Motor_StateParams.switchState ^= 1;

    if(1U == Motor_StateParams.switchState)
    {
        Motor_StateParams.stateRun = 1;
        Motor_Start();
    }

    else
    {
        Motor_StateParams.stateRun = 0;
        Motor_Stop();
    }

   /* Indicates the motor start */
   LED0_Toggle();
 }

/******************************************************************************
Function:     EIC_FORWARD_REVERSE_InterruptHandler
Description:  Forward/Reverse button ISR
Input:        nothing (uses some global variables)
Output:       nothing (modifies some global variables)
Note:         called when Forward/Reverse switch is pressed
******************************************************************************/
void EIC_FORWARD_REVERSE_InterruptHandler(uintptr_t context)
{

    /* Direction can be changed only when motor is stopped*/
    if(!Motor_StateParams.stateRun)
    {
        /* Motor direction (Forward/ Reverse) is changed for every event on switch (S3) */
        Motor_StateParams.direction ^= 1;

        if(!Motor_StateParams.direction)
        {
            Motor_StateParams.directionOffset = 0;
        }
        else
        {
            Motor_StateParams.directionOffset = 8;
        }

        /* Indicates the motor reverse direction */
        LED1_Toggle();
    }


}

/******************************************************************************
Function:     ADC0_InterruptHandler
Description:  ADC result ready interrupt.
 This reads potentiometer voltage (Speed Reference).
Input:        nothing (uses some global variables)
Output:       nothing (modifies some global variables)
Note:         called when ADC0 measurement is finished.
******************************************************************************/
void ADC0_InterruptHandler(ADC_STATUS status, uintptr_t context)
{
    /* Read the ADC result */
    Motor_BCParams.speedRefPot = ADC0_ConversionResultGet();
}

/******************************************************************************
Function:    PDEC_VLC_InterruptHandler
Description:  PDEC VLC interrupt.
 Next commutation pattern is updated in buffer register. And speed is calculated based on
 time captured by the timer TC1.
Input:        nothing (uses some global variables)
Output:       nothing (modifies some global variables)
Note:         called when a new hall pattern is detected
******************************************************************************/
void PDEC_VLC_InterruptHandler(PDEC_HALL_STATUS status, uintptr_t context)
{
    uint16_t timeElapsed;

    if(Motor_StateParams.stateRun)
    {
        /* Confirm the interrupt is a PDEC_VLC interrupt */
        if ((status & PDEC_INTFLAG_VLC_Msk) == PDEC_INTFLAG_VLC_Msk)
        {
           /* Read the Hall pattern from the Hall sensor*/
           Motor_HallParams.currentHallPattern = PDEC_HALLPatternGet();

           /* Check the Hall pattern is a valid pattern */
           if ((Motor_HallParams.nextPattern == Motor_HallParams.currentHallPattern) &&
               (Motor_HallParams.currentHallPattern !=  INVALID_HALL_0) &&
               (Motor_HallParams.currentHallPattern !=  INVALID_HALL_7)
              )

            {
                /* Load the next pattern commutation to the Pattern Generator */
                Motor_HallParams.patternCommutation = COMMUTATION_ARRAY[Motor_HallParams.currentHallPattern + Motor_StateParams.directionOffset];
                Motor_HallParams.pattEnable = (uint8_t)(Motor_HallParams.patternCommutation & PATT_MASK);
                Motor_HallParams.pattValue  = (uint8_t)((Motor_HallParams.patternCommutation >>PATT_MASK_POSITION ) & PATT_MASK);

                TCC0_PWMPatternSet(Motor_HallParams.pattEnable, Motor_HallParams.pattValue);

                /* Update the next pattern in the pattern array */
                Motor_HallParams.nextPattern = HALL_ARRAY[Motor_HallParams.currentHallPattern+(Motor_StateParams.directionOffset)];

            }

                /* Read the time elapsed from last hall pattern */
                timeElapsed = TC1_Timer16bitCounterGet();
                TC1_TimerStop();
                TC1_TimerStart();

                /* Use the Moving Average method to eliminate the spikes in speed calculation */
                if (Motor_BCParams.avgCtr == 0)
                {

                    Motor_BCParams.avgCycleTime = (Motor_BCParams.avgTimeStorage / MOTOR_SPEED_CALCFACTOR);
                    Motor_BCParams.avgTimeStorage -= Motor_BCParams.avgCycleTime;
                    Motor_BCParams.speedPiEnable = 1;

                }
                else
                {
                    Motor_BCParams.avgCtr--;
                    Motor_BCParams.speedReferenceTarget = DEFAULT_SPEED_TARGET;
                    Motor_Speed_PIParams.integratorBuf = PI_BUF_INIT;

                }

                Motor_BCParams.avgTimeStorage += timeElapsed;

                if(Motor_BCParams.speedPiEnable)
                {
                    if (Motor_BCParams.avgCycleTime != 0)
                    {
                        Motor_BCParams.actualSpeed = (Motor_BCParams.speedConstant / (Motor_BCParams.avgCycleTime));
                    }
                }

                /* Use the Q14 format to represent the real-time physical quantities */
                Motor_BCParams.actualSpeedTarget = ((Motor_BCParams.actualSpeed << 14) / MAX_MOTOR_SPEED);


        }

    }
}

/******************************************************************************
Function:     TC0_1ms_InterruptHandler
Description:  1 mS interrupt handler Speed Control loop
Input:        nothing (uses some global variables)
Output:       nothing (modifies some global variables)
Note:         called every 1 mS
******************************************************************************/

void TC0_1ms_InterruptHandler(TC_TIMER_STATUS status, uintptr_t context)
{
    uint16_t dutyPwm;
    uint16_t speedTarget;

    if (Motor_BCParams.speedPiEnable == 1U)
    {
        /* Use the Q14 format to represent the real-time physical quantities */
        speedTarget = ((Motor_BCParams.speedRefPot << 14) / MAX_POT_REF);

        /* Check the speed is inside the boundary */
        if(speedTarget < SPEED_MIN_TARGET)
        {
            Motor_BCParams.setSpeedTarget = SPEED_MIN_TARGET;
        }
        else
        {
            Motor_BCParams.setSpeedTarget = speedTarget;
        }

        /* Speed ramp up process */
        if (MOTOR_RAMPUP_SPEED_PER_MS == 0U)
        {
            Motor_BCParams.speedReferenceTarget = Motor_BCParams.setSpeedTarget;
        }
        else
        {
            if(Motor_BCParams.setSpeedTarget > (Motor_BCParams.speedReferenceTarget + MOTOR_RAMPUP_SPEED_PER_MS) )
            {
                Motor_BCParams.speedReferenceTarget += MOTOR_RAMPUP_SPEED_PER_MS;
            }
            else if(Motor_BCParams.setSpeedTarget < (Motor_BCParams.speedReferenceTarget - MOTOR_RAMPUP_SPEED_PER_MS))
            {
                Motor_BCParams.speedReferenceTarget -= MOTOR_RAMPUP_SPEED_PER_MS;
            }
            else
            {
                Motor_BCParams.speedReferenceTarget = Motor_BCParams.setSpeedTarget;
            }
        }

        /* Use the Q14 format to represent the real-time physical quantities */
        Motor_BCParams.speedReferenceRPM = (Motor_BCParams.speedReferenceTarget * MAX_MOTOR_SPEED) >> 14;

        /* Error Calculation   Error = Reference - Actual */
        Motor_Speed_PIParams.error = (int32_t)Motor_BCParams.speedReferenceTarget - (int32_t)Motor_BCParams.actualSpeedTarget;

        /* Calculate the duty cycle using PI controller  */
        dutyPwm = pi_lib_calculate(&Motor_Speed_PIParams);

        /* Update the PWM duty cycle */
        TCC0_PWM24bitDutySet(TCC0_CHANNEL0, dutyPwm);

    }
}


/*******************************************************************************
 End of File
*/