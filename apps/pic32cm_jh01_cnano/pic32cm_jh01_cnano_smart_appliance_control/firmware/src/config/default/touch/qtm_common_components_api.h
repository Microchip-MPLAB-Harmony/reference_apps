
/*******************************************************************************
  Touch Library

  Company:
    Microchip Technology Inc.

  File Name:
    qtm_common_components_api.h

  Summary:
    QTouch Modular Library

  Description:
    Common API across modules
	
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

#ifndef QTM_API_COMMON_INC__
#define QTM_API_COMMON_INC__

#include <stdint.h>
#include <stddef.h>

/* Acquisition type */
/* Acquisition set config */
#define NODE_SELFCAP 0x80u
#define NODE_SELFCAP_SHIELD 0x81u
#define NODE_MUTUAL 0x40u
#define NODE_MUTUAL_4P 0x41u

/* ---------------------------------------------------------------------------------------- */
/* Touch Library functions return a touch_ret_t */
/* ---------------------------------------------------------------------------------------- */
typedef enum tag_touch_ret_t {
	/* Successful completion of operation. */
	TOUCH_SUCCESS = 0u,

	/* Touch Library is busy with pending previous Touch measurement. */
	TOUCH_ACQ_INCOMPLETE = 1u,

	/* Invalid input parameter. */
	TOUCH_INVALID_INPUT_PARAM = 2u,

	/* Operation not allowed in the current state of the library module. */
	TOUCH_INVALID_LIB_STATE = 3u,

	/* Successful completion of FMEA.*/
	TOUCH_FMEA_SUCCESS = 4u,

	/* Operation not allowed in the current state of the library module. */
	TOUCH_FMEA_ERROR = 5u,

	/* MAGIC number used to Program Counter checking. */
	TOUCH_PC_FUNC_MAGIC_NO_1 = 6u,

	/* MAGIC number used to Program Counter checking. */
	TOUCH_PC_FUNC_MAGIC_NO_2 = 7u,

	/* Error in Logical Program Flow. */
	TOUCH_LOGICAL_PROGRAM_FLOW_ERROR = 8u,

	/* CRC on Touch Configuration failure. */
	TOUCH_LIB_CRC_FAIL = 9u,

	/* Double inverse failure. */
	TOUCH_LIB_DI_FAIL = 10u,

	/* Invalid Pointer argument */
	TOUCH_INVALID_POINTER = 11u,

	/* MAGIC number used to Program Counter checking. */
	TOUCH_PC_FUNC_MAGIC_NO_3 = 12u,

	/* Library Is Unsafe to Use */
	TOUCH_LIB_UNSAFE = 13u,

	/* Library Is Unable t Calibrate Node */
	TOUCH_LIB_NODE_CAL_ERROR = 14u

} touch_ret_t;

/* Touch library state */
typedef enum tag_touch_lib_state_t {
	/* Null - Not initialized */
	TOUCH_STATE_NULL = 0u,

	/* Initialized, no measurements yet */
	TOUCH_STATE_INIT = 1u,

	/* Ready to take a measurement */
	TOUCH_STATE_READY = 2u,

	/* Calibration set for some nodes */
	TOUCH_STATE_CALIBRATE = 3u,

	/* Measurement sequence in progress */
	TOUCH_STATE_BUSY = 4u
} touch_lib_state_t;

/* ---------------------------------------------------------------------------------------- */
/* Acquisition node status byte */
/* ---------------------------------------------------------------------------------------- */
/*
  Bit(s)
  0         Node enabled for measurement (1) / Disabled (0)
  1         Request hardware calibration (1)
  4:2       Node state - 0 = Measure
                         1 = CC Calibration
                         2 = Prescaler calibration
                         3 = Series R calibration
                         4 = Charge Share Delay calibration
  5         Reserved
  6         TAU_CAL_DONE (1) - Flag for 3-stage hardware cal
  7         CAL ERROR - Max comp cap
*/

#define NODE_STATUS_MASK 0x1Cu
#define NODE_STATUS_POS 0x02u

#define NODE_ENABLED    0x01u
#define NODE_CAL_REQ    0x02u
#define CAL_STATE_SET   0x20u
#define TAU_CAL_DONE    0x40u
#define NODE_CAL_ERROR 0x80u

/* Node state - 3 bits */
#define NODE_MEASURE 0u
#define NODE_CC_CAL 1u
#define NODE_PRSC_CAL 2u
#define NODE_RSEL_CAL 3u
#define NODE_CSD_CAL 4u

/* Any CAL bit */
#define NODE_CAL_MASK 0x1Eu

/* ---------------------------------------------------------------------------------------- */
/* Acquisition Node run-time data */
/* ---------------------------------------------------------------------------------------- */
typedef struct {
	uint8_t  node_acq_status;
	uint16_t node_acq_signals;
	uint16_t node_comp_caps;
} qtm_acq_node_data_t;

/* ---------------------------------------------------------------------------------------- */
/* Key sensor status byte */
/* ---------------------------------------------------------------------------------------- */
/* Note: Bit 7 indicates logical 'In Detect' (States 'Detect' and 'Filter Out') */

#define QTM_KEY_STATE_DISABLE 0x00u
#define QTM_KEY_STATE_INIT 0x01u
#define QTM_KEY_STATE_CAL 0x02u
#define QTM_KEY_STATE_NO_DET 0x03u
#define QTM_KEY_STATE_FILT_IN 0x04u
#define QTM_KEY_STATE_DETECT 0x85u
#define QTM_KEY_STATE_FILT_OUT 0x86u
#define QTM_KEY_STATE_ANTI_TCH 0x07u
#define QTM_KEY_STATE_SUSPEND 0x08u
#define QTM_KEY_STATE_CAL_ERR 0x09u
#define KEY_TOUCHED_MASK 0x80u
/* ---------------------------------------------------------------------------------------- */
/* Key sensor run-time data */
/* ---------------------------------------------------------------------------------------- */
typedef struct {
	uint8_t              sensor_state;         /* Disabled, Off, On, Filter, Cal... */
	uint8_t              sensor_state_counter; /* State counter */
	qtm_acq_node_data_t *node_data_struct_ptr; /* Pointer to node data structure */
	uint16_t             channel_reference;    /* Reference signal */
} qtm_touch_key_data_t;

/* ---------------------------------------------------------------------------------------- */
/* Scroller physical / layout types */
/* ---------------------------------------------------------------------------------------- */
#define SCROLLER_TYPE_SLIDER 0u
#define SCROLLER_TYPE_WHEEL 1u
#define SCROLLER_TYPE_WRAPAROUND 2u

#endif /* QTM_QPI_COMMON_*/
