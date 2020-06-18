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

#include "definitions.h"
static bool mFlagOC1On;
static bool mFlagOC2On;
static bool mFlagOC3On;
static void LEDColorDutySet(int Red, int Green, int Blue);

void LEDinit(void)
{
    /* Configure Timer2 in 16-bit mode, Set period of time base */
    TMR3_PeriodSet(0x550);

    /* Enable Timer2. */
    TMR3_Start();
    /* Enable the Output Compare module */
    OCMP5_Enable();
    OCMP6_Enable();
    OCMP8_Enable();
}

void LEDColorSet(int Red, int Green, int Blue)
{
    int NewRed,NewGreen,NewBlue;

    NewRed = ((Red*100)/255);
    NewGreen = ((Green*100)/255);
    NewBlue = ((Blue*100)/255);

   LEDColorDutySet( NewRed,  NewGreen,  NewBlue);
}

static void LEDColorDutySet(int Red, int Green, int Blue)
{
    float TimerVal;
    float Psteps ;
    float NewRed,NewGreen,NewBlue;
//    float Temp= 0;
    int OcRed = mFlagOC1On;
    int OcGreen = mFlagOC2On;
    int OcBlue = mFlagOC3On;

    /* PWM cannot exceed Period, Dynamic PWM steps per code */
    TimerVal = TMR3_PeriodGet();
    Psteps = TimerVal/100;

    Red = Red<100? Red:(Red-1);
    Green = Green<100? Green:(Green-1);
    Blue = Blue<100? Blue:(Blue-1);    
    
    /* takes values and turns them into a %*/
    NewRed  = ((100-Red) * Psteps);
    NewGreen  = ((100-Green) * Psteps);
    NewBlue  = ((100-Blue) * Psteps);

#if 1 
    if (NewRed < 0x03)
    {
        /*turn off PWM if to low or below 0*/
        OCMP5_Disable();
        mFlagOC1On = 0;
    }

    else
#endif
    {

        if(OcRed == 0)
        {
            /* If PWM is off tun it back on*/
            OCMP5_Enable();
            mFlagOC1On = 1;
        }
        if (NewRed > TimerVal)
        {
            /*if the new vaule exceeds the Period set to period (max)*/
            NewRed = TimerVal;
        }
        /*LED is active LOW, correct for postive value*/
//        Temp = ((100-Red) * Psteps);
        /* update PWM register */
        OCMP5_CompareSecondaryValueSet(NewRed);
    }
    
#if 1
    if (NewGreen < 0x03)
    {
        OCMP8_Disable();
        mFlagOC2On = 0;
    }
    else
#endif
    {
        if(OcGreen == 0)
        {
            OCMP8_Enable();
            mFlagOC2On = 1;
        }
        if (NewGreen > TimerVal)
        {
            NewGreen = TimerVal;
        }
        OCMP8_CompareSecondaryValueSet(NewGreen);
    }
#if 1
    if (NewBlue < 0x03)
    {
        OCMP6_Disable();
        mFlagOC3On = 0;
    }
    else
#endif
    {
        if(OcBlue == 0)
        {
            OCMP6_Enable();
            mFlagOC3On = 1;
        }
        if(NewBlue > TimerVal)
        {
            NewBlue = TimerVal;
        }
        OCMP6_CompareSecondaryValueSet(NewBlue);
    }

}