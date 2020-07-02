/****************************************************************************
* Title                 :   Heart Rate 3 Application Layer
* Filename              :   heartrate_3.h
* Author                :   CAL
* Origin Date           :   05/11/2016
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date     Software Version     Initials      Description
*  05/11/2016    XXXXXXXXXXX         CAL      Interface Created.
*  28/01/2020    1.0.1               MK       Modified.
*****************************************************************************/
/** @file heartrate_3.h
 *  @brief This is the application layer for the Heart Rate 3 click board.
 *
 *  @date 11 Apr 2016
 *  @author Corey Lakey
 *  @copyright GNU Public License
 *
 */
/****************************************************************************
* Note: In version 1.0.1, This file has been modified by MK to meet the custom 
* application requirements. Should you need to contact the modifier, Write an 
* Email to mohan.kumar@microchip.com or alternatively, write to 
* Mohan Kumar, Microchip Technology India Pvt Ltd
* Plot No. 1498, EPIP, 1st Phase Industrial Area, Whitefield, Bengaluru, 
* Karnataka 560066
*******************************************************************************/
/*******************************************************************************
 Copyright (C) 2017  Microchip Technology Incorporated and its subsidiaries.

This program is free software; you can redistribute it and/or modify it under 
the terms of the GNU General Public License as published by the Free Software 
Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY 
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A 
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with 
this program; if not, write to the Free Software Foundation, Inc., 
51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*******************************************************************************/
#ifndef HEARTRATE_3_H_
#define HEARTRATE_3_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "heartrate_3_hw.h"

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Configuration Constants
*******************************************************************************/


/******************************************************************************
* Macros
*******************************************************************************/


        
/******************************************************************************
* Typedefs
*******************************************************************************/
typedef struct
{
    uint32_t led1_val;
    uint32_t led2_val;
    uint32_t led3_val;
}led_values_t;

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief <h3> Get Values </h3>
 *
 * @par
 *  Gets all three values from the ADC ( LED1, LED2, LED3 ) and puts
 * them into a struct.
 *
 *
 * @retval LED Values
 *
 */
led_values_t* hr3_get_values( void );

/**
 * @brief <h3> Get HeartRate </h3>
 *
 * @par
 *  Uses heartrate monitor functions to produce a bpm for user to use.
 *
 *
 * @retval Heart rate
 *
 */
uint8_t hr3_get_heartrate( void );

//*******************TI HRM Library
/**
 * @brief initStatHRM
 */
void initStatHRM (void);
/**
 * @brief statHRMAlgo
 * @param ppgData
 */
void statHRMAlgo (unsigned long ppgData);
/**
 * @brief updateWindow
 * @param peakWindow
 * @param Y
 * @param n
 */
void updateWindow(unsigned long *peakWindow, unsigned long Y, unsigned char n);
/**
 * @brief chooseRate
 * @param rate
 * @return
 */
unsigned char chooseRate(unsigned char *rate);
/**
 * @brief updateHeartRate
 * @param rate
 * @param freq
 * @param last
 */
void updateHeartRate(unsigned char *rate, unsigned int freq, unsigned int last);
/**
 * @brief findMax
 * @param X
 * @return
 */
unsigned long findMax(unsigned long *X);
/**
 * @brief findMin
 * @param X
 * @return
 */
unsigned long findMin(unsigned long *X);

/**********************************/



#ifdef __cplusplus
} // extern "C"
#endif

#endif /*HEARTRATE_3_H_*/

/*** End of File **************************************************************/