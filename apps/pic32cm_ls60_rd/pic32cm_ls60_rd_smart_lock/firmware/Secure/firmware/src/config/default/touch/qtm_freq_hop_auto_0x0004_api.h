
/*******************************************************************************
  Touch Library

  Company:
    Microchip Technology Inc.

  File Name:
    qtm_freq_hop_auto_0x0004_api.h

  Summary:
    QTouch Modular Library

  Description:
    API for Frequnecy Hop auto-tune module
	
*******************************************************************************/

/*******************************************************************************
Copyright (c) Microchip Technology Inc.  All rights reserved.

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

/* QTouch Modular Library Configuration */

#ifndef TOUCH_API_FREQ_HOP_H
#define TOUCH_API_FREQ_HOP_H


/* Include files */
#include <stdint.h>
#include "qtm_common_components_api.h"
  
/*----------------------------------------------------------------------------
 *     Structure Declarations
 *----------------------------------------------------------------------------*/

/* Frequency HOP Module */
/* Configuration */
typedef struct 
{
  uint16_t num_sensors;
  uint8_t num_freqs;
  uint8_t *freq_option_select;
  uint8_t *median_filter_freq;        /* PTC frequencies to be used on the median filter samples */
  uint8_t enable_freq_autotune;
  uint8_t max_variance_limit;
  uint8_t autotune_count_in_limit;
}qtm_freq_hop_autotune_config_t;

/* Status data */
typedef struct 
{
  uint8_t module_status;        /* Obligatory status byte: Bit 7 = Reburst... */
  uint8_t current_freq;         /* PTC Sampling Delay Selection - 0 to 15 PTC CLK cycles */
  uint16_t *filter_buffer;      /* Filter buffer used to store past cycle signal values of sensor */
  qtm_acq_node_data_t *qtm_acq_node_data;
  uint8_t *freq_tune_count_ins;
}qtm_freq_hop_autotune_data_t;

/* Container */
typedef struct 
{
  qtm_freq_hop_autotune_data_t (*qtm_freq_hop_autotune_data);
  qtm_freq_hop_autotune_config_t (*qtm_freq_hop_autotune_config);  
} qtm_freq_hop_autotune_control_t;


/*----------------------------------------------------------------------------
 *   prototypes
 *----------------------------------------------------------------------------*/
/*============================================================================
touch_ret_t qtm_freq_hop_autotune(qtm_freq_hop_autotune_control_t *qtm_freq_hop_autotune_control);
------------------------------------------------------------------------------
Purpose: Runs freq hop auto sequence
Input  : Pointer to container structure
Output : touch_ret_t
Notes  : none
============================================================================*/
touch_ret_t qtm_freq_hop_autotune(qtm_freq_hop_autotune_control_t *qtm_freq_hop_autotune_control);

/*============================================================================
uint16_t qtm_get_freq_auto_module_id(void)
------------------------------------------------------------------------------
Purpose: Returns the module ID
Input  : none
Output : Module ID
Notes  : none
============================================================================*/
uint16_t qtm_get_freq_auto_module_id(void);

/*============================================================================
uint8_t qtm_get_freq_auto_module_ver(void)
------------------------------------------------------------------------------
Purpose: Returns the module Firmware version
Input  : none
Output : Module ID - Upper nibble major / Lower nibble minor 
Notes  : none
============================================================================*/
uint8_t qtm_get_freq_auto_module_ver(void);

#endif    /* TOUCH_API_CM0_FREQ_HOP_H */
