/*******************************************************************************
  Touch Library v3.14.0 Release

  Company:
    Microchip Technology Inc.

  File Name:
    touch.h

  Summary:
    QTouch Modular Library

  Description:
    Configuration macros for touch library

*******************************************************************************/

/*******************************************************************************
Copyright (c) 2023 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS  WITHOUT  WARRANTY  OF  ANY  KIND,
EITHER EXPRESS  OR  IMPLIED,  INCLUDING  WITHOUT  LIMITATION,  ANY  WARRANTY  OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A  PARTICULAR  PURPOSE.
IN NO EVENT SHALL MICROCHIP OR  ITS  LICENSORS  BE  LIABLE  OR  OBLIGATED  UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,  BREACH  OF  WARRANTY,  OR
OTHER LEGAL  EQUITABLE  THEORY  ANY  DIRECT  OR  INDIRECT  DAMAGES  OR  EXPENSES
INCLUDING BUT NOT LIMITED TO ANY  INCIDENTAL,  SPECIAL,  INDIRECT,  PUNITIVE  OR
CONSEQUENTIAL DAMAGES, LOST  PROFITS  OR  LOST  DATA,  COST  OF  PROCUREMENT  OF
SUBSTITUTE  GOODS,  TECHNOLOGY,  SERVICES,  OR  ANY  CLAIMS  BY  THIRD   PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE  THEREOF),  OR  OTHER  SIMILAR  COSTS.
*******************************************************************************/
#ifndef TOUCH_H
#define TOUCH_H
#include "device.h"


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END
//SAME51

/*----------------------------------------------------------------------------
 *     include files
 *----------------------------------------------------------------------------*/

#include "touch_api_ptc.h"

/**********************************************************/
/******************* Acquisition controls *****************/
/**********************************************************/
/* Defines the Measurement Time in milli seconds.
 * Range: 1 to 255.
 * Default value: 20.
 */
#define DEF_TOUCH_MEASUREMENT_PERIOD_MS 1u

/* Defines the Type of sensor
 * Default value: NODE_MUTUAL.
 */
#define DEF_SENSOR_TYPE NODE_MUTUAL

/* Set sensor calibration mode for charge share delay ,Prescaler or series resistor.
 * Range: CAL_AUTO_TUNE_NONE / CAL_AUTO_TUNE_RSEL / CAL_AUTO_TUNE_PRSC / CAL_AUTO_TUNE_CSD
 * Default value: CAL_AUTO_TUNE_NONE.
 */

#define DEF_PTC_CAL_OPTION   CAL_AUTO_TUNE_NONE

/* Calibration option to ensure full charge transfer */
/* Bits 7:0 = XX | TT SELECT_TAU | X | CAL_OPTION */
#define DEF_PTC_TAU_TARGET CAL_CHRG_5TAU
#define DEF_PTC_CAL_AUTO_TUNE (uint8_t)((DEF_PTC_TAU_TARGET << CAL_CHRG_TIME_POS) | DEF_PTC_CAL_OPTION)

/* Defines the interrupt priority for the PTC. Set low priority to PTC interrupt for applications having interrupt time
 * constraints.
 */
#define DEF_PTC_INTERRUPT_PRIORITY 7u

/* Set default bootup acquisition frequency.
 * Range: FREQ_SEL_0 - FREQ_SEL_15 , FREQ_SEL_SPREAD
 * Default value: FREQ_SEL_0.
 */
#define DEF_SEL_FREQ_INIT FREQ_SEL_0


/*----------------------------------------------------------------------------
 *     defines
 *----------------------------------------------------------------------------*/

/**********************************************************/
/***************** Node Params   ******************/
/**********************************************************/
/* Acquisition Set 1 */
/* Defines the number of sensor nodes in the acquisition set
 * Range: 1 to 65535.
 * Default value: 1
 */
#define DEF_NUM_CHANNELS (12u)


/* Defines node parameter setting
 * {X-line, Y-line, Charge Share Delay (CSD), NODE_RSEL_PRSC(series resistor, prescaler), NODE_G(Analog Gain , Digital Gain),
 * filter level}
 */


#define NODE_0_PARAMS                                                                                               \
{                                                                                                                  \
  X(25)|X(24)|X(21)|X(31)|X(30)|X(18)|X(17), Y(16), 3,NODE_RSEL_PRSC(RSEL_VAL_6, (uint8_t)PRSC_DIV_SEL_64), NODE_GAIN(GAIN_1, GAIN_1), (uint8_t)FILTER_LEVEL_64                   \
}
#define NODE_1_PARAMS                                                                                               \
{                                                                                                                  \
  X(25)|X(24)|X(21)|X(31)|X(30)|X(18)|X(17), Y(15), 3,NODE_RSEL_PRSC(RSEL_VAL_6, (uint8_t)PRSC_DIV_SEL_64), NODE_GAIN(GAIN_1, GAIN_1), (uint8_t)FILTER_LEVEL_64                   \
}
#define NODE_2_PARAMS                                                                                               \
{                                                                                                                  \
  X(25)|X(24)|X(21)|X(31)|X(30)|X(18)|X(17), Y(14), 3,NODE_RSEL_PRSC(RSEL_VAL_6, (uint8_t)PRSC_DIV_SEL_64), NODE_GAIN(GAIN_1, GAIN_1), (uint8_t)FILTER_LEVEL_64                   \
}
#define NODE_3_PARAMS                                                                                               \
{                                                                                                                  \
  X(25)|X(24)|X(21)|X(31)|X(30)|X(18)|X(17), Y(29), 3,NODE_RSEL_PRSC(RSEL_VAL_6, (uint8_t)PRSC_DIV_SEL_64), NODE_GAIN(GAIN_1, GAIN_1), (uint8_t)FILTER_LEVEL_64                   \
}
#define NODE_4_PARAMS                                                                                               \
{                                                                                                                  \
  X(25)|X(24)|X(21)|X(31)|X(30)|X(18)|X(17), Y(28), 3,NODE_RSEL_PRSC(RSEL_VAL_6, (uint8_t)PRSC_DIV_SEL_64), NODE_GAIN(GAIN_1, GAIN_1), (uint8_t)FILTER_LEVEL_64                   \
}
#define NODE_5_PARAMS                                                                                               \
{                                                                                                                  \
  X(25), Y(16)|Y(15)|Y(14)|Y(29)|Y(28), 2,NODE_RSEL_PRSC(RSEL_VAL_6, (uint8_t)PRSC_DIV_SEL_64), NODE_GAIN(GAIN_1, GAIN_1), (uint8_t)FILTER_LEVEL_64                   \
}
#define NODE_6_PARAMS                                                                                               \
{                                                                                                                  \
  X(24), Y(16)|Y(15)|Y(14)|Y(29)|Y(28), 2,NODE_RSEL_PRSC(RSEL_VAL_6, (uint8_t)PRSC_DIV_SEL_64), NODE_GAIN(GAIN_1, GAIN_1), (uint8_t)FILTER_LEVEL_64                   \
}
#define NODE_7_PARAMS                                                                                               \
{                                                                                                                  \
  X(21), Y(16)|Y(15)|Y(14)|Y(29)|Y(28), 2,NODE_RSEL_PRSC(RSEL_VAL_6, (uint8_t)PRSC_DIV_SEL_64), NODE_GAIN(GAIN_1, GAIN_1), (uint8_t)FILTER_LEVEL_64                   \
}
#define NODE_8_PARAMS                                                                                               \
{                                                                                                                  \
  X(31), Y(16)|Y(15)|Y(14)|Y(29)|Y(28), 2,NODE_RSEL_PRSC(RSEL_VAL_6, (uint8_t)PRSC_DIV_SEL_64), NODE_GAIN(GAIN_1, GAIN_1), (uint8_t)FILTER_LEVEL_64                   \
}
#define NODE_9_PARAMS                                                                                               \
{                                                                                                                  \
  X(30), Y(16)|Y(15)|Y(14)|Y(29)|Y(28), 2,NODE_RSEL_PRSC(RSEL_VAL_6, (uint8_t)PRSC_DIV_SEL_64), NODE_GAIN(GAIN_1, GAIN_1), (uint8_t)FILTER_LEVEL_64                   \
}
#define NODE_10_PARAMS                                                                                               \
{                                                                                                                  \
  X(18), Y(16)|Y(15)|Y(14)|Y(29)|Y(28), 2,NODE_RSEL_PRSC(RSEL_VAL_6, (uint8_t)PRSC_DIV_SEL_64), NODE_GAIN(GAIN_1, GAIN_1), (uint8_t)FILTER_LEVEL_64                   \
}
#define NODE_11_PARAMS                                                                                               \
{                                                                                                                  \
  X(17), Y(16)|Y(15)|Y(14)|Y(29)|Y(28), 2,NODE_RSEL_PRSC(RSEL_VAL_6, (uint8_t)PRSC_DIV_SEL_64), NODE_GAIN(GAIN_1, GAIN_1), (uint8_t)FILTER_LEVEL_64                   \
}

/**********************************************************/
/***************** Key Params   ******************/
/**********************************************************/
/* Defines the number of key sensors
 * Range: 1 to 65535.
 * Default value: 1
 */
#define DEF_NUM_SENSORS (12u)

/* Defines Key Sensor setting
 * {Sensor Threshold, Sensor Hysterisis, Sensor AKS}
 */

#define KEY_0_PARAMS                                                                                            \
{                                                                                                              \
    20u, (uint8_t)HYST_25, (uint8_t)AKS_GROUP_1                       \
}


#define KEY_1_PARAMS                                                                                            \
{                                                                                                              \
    20u, (uint8_t)HYST_25, (uint8_t)AKS_GROUP_1                       \
}


#define KEY_2_PARAMS                                                                                            \
{                                                                                                              \
    20u, (uint8_t)HYST_25, (uint8_t)AKS_GROUP_1                       \
}


#define KEY_3_PARAMS                                                                                            \
{                                                                                                              \
    20u, (uint8_t)HYST_25, (uint8_t)AKS_GROUP_1                       \
}


#define KEY_4_PARAMS                                                                                            \
{                                                                                                              \
    20u, (uint8_t)HYST_25, (uint8_t)AKS_GROUP_1                       \
}


#define KEY_5_PARAMS                                                                                            \
{                                                                                                              \
    20u, (uint8_t)HYST_25, (uint8_t)AKS_GROUP_1                       \
}


#define KEY_6_PARAMS                                                                                            \
{                                                                                                              \
    20u, (uint8_t)HYST_25, (uint8_t)AKS_GROUP_1                       \
}


#define KEY_7_PARAMS                                                                                            \
{                                                                                                              \
    20u, (uint8_t)HYST_25, (uint8_t)AKS_GROUP_1                       \
}


#define KEY_8_PARAMS                                                                                            \
{                                                                                                              \
    20u, (uint8_t)HYST_25, (uint8_t)AKS_GROUP_1                       \
}


#define KEY_9_PARAMS                                                                                            \
{                                                                                                              \
    20u, (uint8_t)HYST_25, (uint8_t)AKS_GROUP_1                       \
}


#define KEY_10_PARAMS                                                                                            \
{                                                                                                              \
    20u, (uint8_t)HYST_25, (uint8_t)AKS_GROUP_1                       \
}


#define KEY_11_PARAMS                                                                                            \
{                                                                                                              \
    20u, (uint8_t)HYST_25, (uint8_t)AKS_GROUP_1                       \
}


/* De-bounce counter for additional measurements to confirm touch detection
 * Range: 0 to 255.
 * Default value: 4.
 */
#define DEF_TOUCH_DET_INT 2u

/* De-bounce counter for additional measurements to confirm away from touch signal
 * to initiate Away from touch re-calibration.
 * Range: 0 to 255.
 * Default value: 5.
 */
#define DEF_ANTI_TCH_DET_INT 3u

/* Threshold beyond with automatic sensor recalibration is initiated.
 * Range: RECAL_100/ RECAL_50 / RECAL_25 / RECAL_12_5 / RECAL_6_25 / MAX_RECAL
 * Default value: RECAL_100.
 */
#define DEF_ANTI_TCH_RECAL_THRSHLD (uint8_t)RECAL_100

/* Rate at which sensor reference value is adjusted towards sensor signal value
 * when signal value is greater than reference.
 * Units: 200ms
 * Range: 0-255
 * Default value: 20u = 4 seconds.
 */
#define DEF_TCH_DRIFT_RATE 20u

/* Rate at which sensor reference value is adjusted towards sensor signal value
 * when signal value is less than reference.
 * Units: 200ms
 * Range: 0-255
 * Default value: 5u = 1 second.
 */
#define DEF_ANTI_TCH_DRIFT_RATE 20u

/* Time to restrict drift on all sensor when one or more sensors are activated.
 * Units: 200ms
 * Range: 0-255
 * Default value: 20u = 4 seconds.
 */
#define DEF_DRIFT_HOLD_TIME 40u

/* Set mode for additional sensor measurements based on touch activity.
 * Range: REBURST_NONE / REBURST_UNRESOLVED / REBURST_ALL
 * Default value: REBURST_UNRESOLVED
 */
#define DEF_REBURST_MODE (uint8_t)REBURST_UNRESOLVED

/* Sensor maximum ON duration upon touch.
 * Range: 0-255
 * Default value: 0
 */
#define DEF_MAX_ON_DURATION 254u


/**********************************************************/
/***************** Surface Parameters ****************/
/**********************************************************/

/* Horizontal Start Key <0-65534>
 * Start key of horizontal axis
 * Range: 0 to 65534
 */
#define SURFACE_CS_START_KEY_H 5u
/* Horizontal Number of Channel <0-255>
 * Number of Channels forming horizontal axis
 * Range: 0 to 255
 */
#define SURFACE_CS_NUM_KEYS_H 7u
/* Vertical Start Key <0-65534>
 * Start key of vertical axis
 * Range: 0 to 65534
 */
#define SURFACE_CS_START_KEY_V 0u
/* Vertical Number of Channel <0-255>
 * Number of Channels forming vertical axis
 * Range: 0 to 255
 */
#define SURFACE_CS_NUM_KEYS_V 5u
/*  Position Resolution and Deadband Percentage
 *  Full scale position resolution reported for the axis and the deadband Percentage
 *  RESOL_2_BIT - RESOL_12_BIT
 *  DB_NONE - DB_15_PERCENT
 */
#define SURFACE_CS_RESOL_DB SCR_RESOL_DEADBAND((uint8_t)RESOL_8_BIT, (uint8_t)DB_NONE)
/* Median filter enable and  IIR filter Config
 * Median Filter <0-1>
 * Enable or Disable Median Filter
 * enable - 1
 * disable - 0
 * IIR filter <0-3>
 * Configure IIR filter
 *  0 - None
 *  1 - 25%
 *  2 - 50%
 *  3 - 75%
 */
#define SURFACE_CS_FILT_CFG SCR_MEDIAN_IIR(1u, 3u)
/* Position Hystersis <0-255>
 * The minimum travel distance to be reported after contact or direction change
 * Applicable to Horizontal and Vertical directions
 */
#define SURFACE_CS_POS_HYST 3u
/* Minimum Contact <0-65534>
 * The minimum contact size measurement for persistent contact tracking.
 * Contact size is the sum of neighbouring keys' touch deltas forming the touch contact.
 */
#define SURFACE_CS_MIN_CONTACT 25u


/**********************************************************/
/********* Frequency Hop Module ****************/
/**********************************************************/

/* sets the frequency steps for hop.
 * Range: 3 to 7.
 * Default value: 3
 */
#define NUM_FREQ_STEPS 3u

/* PTC Sampling Delay Selection - 0 to 15 PTC CLK cycles */

#define DEF_MEDIAN_FILTER_FREQUENCIES (uint8_t)FREQ_SEL_0,(uint8_t)FREQ_SEL_3,(uint8_t)FREQ_SEL_7

/* Enable / Disable the frequency hop auto tune
 * Range: 0 / 1
 * Default value: 1
 */
#define DEF_FREQ_AUTOTUNE_ENABLE 1u

/* sets the maximum variance for Frequency Hop Auto tune.
 * Range: 1 to 255.
 * Default value: 15
 */
#define FREQ_AUTOTUNE_MAX_VARIANCE 25u

/* sets the Tune in count for Frequency Hop Auto tune.
 * Range: 1 to 255.
 * Default value: 6
 */
#define FREQ_AUTOTUNE_COUNT_IN 6u

/**********************************************************/
/***************** Communication - Data Streamer ******************/
/**********************************************************/
#define DEF_TOUCH_DATA_STREAMER_ENABLE 0u



/**********************************************************/



/* Acquisition variables */
extern qtm_acq_node_data_t ptc_qtlib_node_stat1[DEF_NUM_CHANNELS];
extern qtm_acq_same51_node_config_t ptc_seq_node_cfg1[DEF_NUM_CHANNELS];


/* Keys variables */
extern qtm_touch_key_group_config_t qtlib_key_grp_config_set1;
extern qtm_touch_key_data_t qtlib_key_data_set1[DEF_NUM_SENSORS];
extern qtm_touch_key_config_t qtlib_key_configs_set1[DEF_NUM_SENSORS];
/* Frequency Hop Autotune variables */
extern qtm_freq_hop_autotune_config_t qtm_freq_hop_autotune_config1;
/* Surface variables */
extern qtm_surface_cs_config_t  qtm_surface_cs_config1;
extern qtm_surface_contact_data_t qtm_surface_cs_data1;
extern uint8_t module_error_code;


extern volatile uint8_t measurement_done_touch;

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
// DOM-IGNORE-END
#endif // TOUCH_H
