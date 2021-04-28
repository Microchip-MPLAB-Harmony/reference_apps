/*******************************************************************************
  PIR click source file

  Company:
    Microchip Technology Inc.

  File Name:
    pir.c

  Summary:

  Description:
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
    (c) 2021 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
 */

#include "definitions.h"                // SYS function prototypes
#include "../click_interface.h"
#include "pir.h"

/**
  Section: Macro Declarations
 */

/* Note: With "PIR_MOTION_DETECTED = 6.0" the PIR Sensor is capable of
detecting the motion from distance of nearly 4-5 feet and with
"PIR_MOTION_DETECTED = 7.0" the motion is detected from a distance
nearly 2-3 feet. Configure the value based on the requirement. */
#define PIR_MOTION_DETECTED             (6.0)

#define PIR_OUTPUT_CODE                 4095
#define PIR_OUT_MIN                     0
#define PIR_OUT_MAX                     3303
#define PIR_SENSOR_ADDR                 0x4D
#define PIR_REG_ADDR                    0x00

/**
  Section: Variable Definitions
 */

/**
  Section: Private function prototypes
 */

bool pir_isMotionDetected(void)
{
    float out_val;
    bool motion_detected = false;   
    uint8_t pReadBuffer[1]={0};
    
    CLICK_PIR_I2C_WriteRead(PIR_SENSOR_ADDR, PIR_REG_ADDR, 1, pReadBuffer, 1);
    while(CLICK_PIR_I2C_IsBusy() == true);
    
    out_val  = ( float )( PIR_OUT_MAX - PIR_OUT_MIN );
    out_val *= pReadBuffer[0];
    out_val /= PIR_OUTPUT_CODE;
    out_val += PIR_OUT_MIN;

    if (out_val >= PIR_MOTION_DETECTED)
    {
        motion_detected = true;
    }
    
    return motion_detected;
}

