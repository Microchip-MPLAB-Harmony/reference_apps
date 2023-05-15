
/*******************************************************************************
  Touch Library v3.13.1 Release

  Company:
    Microchip Technology Inc.

  File Name:
    touch_api_ptc.h

  Summary:
    QTouch Modular Library

  Description:
    Includes the Module API header files based on the configured modules,
    prototypes for touch.c file and Application helper API functions
*******************************************************************************/

/*******************************************************************************
Copyright (c)  2023 released Microchip Technology Inc.  All rights reserved.

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

#ifndef TOUCH_API_PTC_H
#define TOUCH_API_PTC_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *     include files
 *----------------------------------------------------------------------------*/

#include "qtm_common_components_api.h"
#include "qtm_acq_pic32cm_le_0x0040_api.h"
#include "qtm_touch_key_0x0002_api.h"
#include "qtm_freq_hop_0x0006_api.h"
/*----------------------------------------------------------------------------
 *   prototypes
 *----------------------------------------------------------------------------*/
/* Application Helper API's */
uint16_t get_sensor_node_signal(uint16_t sensor_node);
void     update_sensor_node_signal(uint16_t sensor_node, uint16_t new_signal);
uint16_t get_sensor_node_reference(uint16_t sensor_node);
void     update_sensor_node_reference(uint16_t sensor_node, uint16_t new_reference);
uint16_t get_sensor_cc_val(uint16_t sensor_node);
void     update_sensor_cc_val(uint16_t sensor_node, uint16_t new_cc_value);
uint8_t  get_sensor_state(uint16_t sensor_node);
void     update_sensor_state(uint16_t sensor_node, uint8_t new_state);
void     calibrate_node(uint16_t sensor_node);
uint8_t  get_scroller_state(uint16_t sensor_node);
uint16_t get_scroller_position(uint16_t sensor_node);

void touch_timer_handler(void);
void touch_init(void);
void touch_process(void);

void touch_timer_config(void);

#ifdef __cplusplus
}
#endif

#endif /* TOUCH_API_PTC_H */
