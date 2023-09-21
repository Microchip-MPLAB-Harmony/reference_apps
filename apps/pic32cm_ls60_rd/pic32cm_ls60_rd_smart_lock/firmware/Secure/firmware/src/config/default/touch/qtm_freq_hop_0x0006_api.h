
/*******************************************************************************
  Touch Library

  Company:
    Microchip Technology Inc.

  File Name:
    qtm_freq_hop_0x0006_api.h

  Summary:
    QTouch Modular Library

  Description:
    API for Frequnecy Hop module
	
*******************************************************************************/

/*******************************************************************************
Copyright (C) [2023], Microchip Technology Inc., and its subsidiaries. All rights reserved.

The software and documentation is provided by microchip and its contributors
"as is" and any express, implied or statutory warranties, including, but not
limited to, the implied warranties of merchantability, fitness for a particular
purpose and non-infringement of third party intellectual property rights are
disclaimed to the fullest extent permitted by law. In no event shall microchip
or its contributors be liable for any direct, indirect, incidental, special,
exemplary, or consequential damages (including, but not limited to, procurement
of substitute goods or services; loss of use, data, or profits; or business
interruption) however caused and on any theory of liability, whether in contract,
strict liability, or tort (including negligence or otherwise) arising in any way
out of the use of the software and documentation, even if advised of the
possibility of such damage.

Except as expressly permitted hereunder and subject to the applicable license terms
for any third-party software incorporated in the software and any applicable open
source software license terms, no license or other rights, whether express or
implied, are granted under any patent or other intellectual property rights of
Microchip or any third party.
************************************************************************************/

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

}qtm_freq_hop_config_t;

/* Status data */
typedef struct 
{
  uint8_t module_status;        /* Obligatory status byte: Bit 7 = Reburst... */  
  uint8_t current_freq;         /* PTC Sampling Delay Selection - 0 to 15 PTC CLK cycles */
  uint16_t *filter_buffer;      /* Filter buffer used to store past cycle signal values of sensor */
  qtm_acq_node_data_t *qtm_acq_node_data;
  
}qtm_freq_hop_data_t;

/* Container */
typedef struct 
{
	qtm_freq_hop_data_t (*qtm_freq_hop_data);
	qtm_freq_hop_config_t (*qtm_freq_hop_config);
} qtm_freq_hop_control_t;


/*----------------------------------------------------------------------------
 *   prototypes
 *----------------------------------------------------------------------------*/
/*============================================================================
touch_ret_t qtm_freq_hop(qtm_freq_hop_control_t *qtm_freq_hop_control);
------------------------------------------------------------------------------
Purpose: Runs freq hop process
Input  : Pointer to container structure
Output : touch_ret_t
Notes  : none
============================================================================*/
touch_ret_t qtm_freq_hop(qtm_freq_hop_control_t *qtm_freq_hop_control);

/*============================================================================
uint16_t qtm_get_freq_hop_module_id(void)
------------------------------------------------------------------------------
Purpose: Returns the module ID
Input  : none
Output : Module ID
Notes  : none
============================================================================*/
uint16_t qtm_get_freq_hop_module_id(void);


/*============================================================================
uint8_t qtm_get_freq_hop_module_ver(void)
------------------------------------------------------------------------------
Purpose: Returns the module Firmware version
Input  : none
Output : Module ID - Upper nibble major / Lower nibble minor 
Notes  : none
============================================================================*/
uint8_t qtm_get_freq_hop_module_ver(void);


#endif    /* TOUCH_API_FREQ_HOP_H */
