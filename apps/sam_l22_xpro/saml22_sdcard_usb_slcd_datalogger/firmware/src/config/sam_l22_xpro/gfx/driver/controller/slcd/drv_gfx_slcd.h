/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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

/*******************************************************************************
  MPLAB Harmony SLCD Generated Driver Header File

  File Name:
    drv_gfx_slcd.h

  Summary:
    Build-time generated header file
	Interface for the graphics library where the primitives are rendered and 
	sent to the graphics controller either external or internal

  Description:
    This header file contains the function prototypes and definitions of
    the data types and constants that make up the interface to the SLCD
    Segment Controller.

    Created with MPLAB Harmony Version 3.0

    Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>

*******************************************************************************/

/**
 * \file drv_gfx_slcd.h
 * @brief  SAM Segment Liquid Crystal Display(SLCD) Controller Generated Header File
 *
 * @details This header file contains the function prototypes and definitions of the data types and constants that make up the interface to the SLCD Segment Controller.
 *
 * Copyright (c) 2021 Microchip Technology Inc. and its subsidiaries.
 */

#ifndef _DRV_GFX_SLCD_H
#define _DRV_GFX_SLCD_H

#include "gfx/driver/gfx_driver.h"
#include "definitions.h"
#include "device.h"

#ifdef __cplusplus
    extern "C" {
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// Section: Functions
// *****************************************************************************
// *****************************************************************************

/**
 *
 * \brief SAM Segment Liquid Crystal Display(SLCD) Controller.
 *
 * Copyright (c) 2015-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */


#ifndef SLCD_H_INCLUDED
#define SLCD_H_INCLUDED

/**
 * \defgroup asfdoc_sam0_drivers_slcd_group SAM Segment Liquid Crystal Display(SLCD) Controller
 *
 * This driver for Atmel&reg; | SMART ARM&reg;-based microcontrollers provides an interface for the configuration
 * and management of the device's SLCD functionality. The following
 * driver API modes are covered by this manual:
 *
 *  - Polled APIs
 *  - Callback APIs
 *
 *
 * The following peripheral is used by this module:
 *  - Segment Liquid Crystal Display(SLCD)
 *
 * The following devices can use this module:
 *  - Atmel | SMART SAM L22
 *
 * The outline of this documentation is as follows:
 *  - \ref asfdoc_sam0_drivers_slcd_prerequisites
 *  - \ref asfdoc_sam0_drivers_slcd_module_overview
 *  - \ref asfdoc_sam0_drivers_slcd_special_considerations
 *  - \ref asfdoc_sam0_drivers_slcd_extra_info
 *  - \ref asfdoc_sam0_drivers_slcd_examples
 *  - \ref asfdoc_sam0_drivers_slcd_api_overview
 *
 *
 * \section asfdoc_sam0_drivers_slcd_prerequisites Prerequisites
 *
 * There are no prerequisites for this module.
 *
 *
 * \section asfdoc_sam0_drivers_slcd_module_overview Module Overview
 *
 * \subsection asfdoc_sam0_drivers_slcd_module_overview_internal Display Overview
 *
 * A LCD display is made of several segments (pixels or complete symbols)
 * which can be visible or invisible. A segment has two electrodes with liquid
 * crystal between them. These electrodes are the common terminal (COM pin) and
 * the segment terminal (SEG pin). When a voltage above a threshold voltage is applied
 * across the liquid crystal, the segment becomes visible. The voltage must alternate,
 * to avoid an electrophoresis effect in the liquid crystal, which degrades the
 * display.
 *
 * The LCD controller is intended for monochrome passive liquid crystal display (LCD)
 * with up to 8 common terminals and up to 44 segment terminals. A charge pump provides
 * LCD display supply which can be higher than supply voltage of the device.
 * Each LCD pin, segment or common terminals, can be configured as general purpose I/O pins
 * if not driven by LCD controller.
 *
 * \section asfdoc_sam0_drivers_slcd_special_considerations Special Considerations
 *
 * \subsection asfdoc_sam0_drivers_slcd_special_considerations_io I/O Lines
 *
 * The SLCD pins (SEG and COM) are multiplexed with other peripherals. The
 * user application must first configure the I/O controller, to give control of
 * the requisite pins to the SLCD.
 *
 * \subsection asfdoc_sam0_drivers_slcd_special_considerations_power Power Management
 *
 * The SLCD will continue to operate in any sleep mode where the selected source clock
 * is running. The SLCD interrupts can be used to wake up the device from sleep modes.
 * Events connected to the event system can trigger other operations in the system
 * without exiting sleep modes.
 *
 * The power consumption of SLCD itself can be minimized by:
 * - Using the lowest acceptable frame rate (refer to the LCD glass technical
 * characteristics)
 * - Using the low-power waveform (default mode)
 * - Using automated modes of operation
 * - Configuring the lowest possible contrast value
 *
 * \section asfdoc_sam0_drivers_slcd_extra_info Extra Information
 *
 * For extra information, see \ref asfdoc_sam0_drivers_slcd_extra. This includes:
 *  - \ref asfdoc_sam0_drivers_slcd_extra_acronyms
 *  - \ref asfdoc_sam0_drivers_slcd_extra_dependencies
 *  - \ref asfdoc_sam0_drivers_slcd_extra_errata
 *  - \ref asfdoc_sam0_drivers_slcd_extra_history
 *
 * \section asfdoc_sam0_drivers_slcd_examples Examples
 *
 * For a list of examples related to this driver, see
 * \ref asfdoc_sam0_drivers_slcd_exqsg.
 *
 *
 * \section asfdoc_sam0_drivers_slcd_api_overview API Overview
 * @{
 */



enum status_code {
    STATUS_OK,
    STATUS_ERR_INVALID_ARG
};

/**
 * \brief SLCD frame counter definition
 *
 * Enum SLCD frame counter definition.
 */
enum slcd_frame_counter {
        /** SLCD frame counter 0 */
        SLCD_FRAME_COUNTER_0,
        /** SLCD frame counter 1 */
        SLCD_FRAME_COUNTER_1,
        /** SLCD frame counter 2 */
        SLCD_FRAME_COUNTER_2,
};

/**
 * \brief Waveform mode
 *
 * Enum waveform mode.
 */
enum slcd_waveform_mode {
        /** Low power waveform mode */
        SLCD_LOW_POWER_WAVEFORM_MODE = 0,
        /** Standard waveform mode */
        SLCD_STANDARD_WAVEFORM_MODE,
};

/**
 * \brief SLCD configuration structure
 *
 * Basic configuration for SLCDC.
 */
struct slcd_config {
        /** Keep SLCD enabled in standby sleep mode if true */
        bool run_in_standby;
        /** waveform mode selection */
        enum slcd_waveform_mode waveform_mode;

        /** Low resistance network duration */
        uint8_t low_resistance_duration;
        /** Enable Low resistance if true */
        bool enable_low_resistance;
        /** Bias buffer duration */
        uint8_t bias_buffer_duration;
        /** Enable bias buffer if true */
        bool enable_bias_buffer;
};
/**
 * \brief SLCD event enable/disable structure
 *
 * Event flags for the SLCD module. This is used to enable and
 * disable events via \ref slcd_enable_events() and \ref slcd_disable_events().
 */
struct slcd_events {
        /** Enable event generation on frame counter 0 overflow */
        bool generate_event_on_fc0_overflow;
        /** Enable event generation on frame counter 1 overflow */
        bool generate_event_on_fc1_overflow;
        /** Enable event generation on frame counter 2 overflow */
        bool generate_event_on_fc2_overflow;
};

/**
 * \brief SLCD blink configuration
 *
 * SLCD blink configuration.
 */
struct slcd_blink_config {
        /** Frame counter selection for blinking */
        enum slcd_frame_counter fc;
        /** All segments are allowed to blink if true, else only
          Selected segments are allowed to blink */
        bool blink_all_seg;
};

/**
 * \brief SLCD circular shift direction
 *
 * Enum SLCD circular shift direction.
 */
enum slcd_circular_shift_dir {
        /** Circular shift direction is left */
        SLCD_CIRCULAR_SHIFT_LEFT = 0,
        /** Circular shift direction is right */
        SLCD_CIRCULAR_SHIFT_RIGHT,
};

/**
 * \brief SLCD circular shift configuration
 *
 * SLCD circular shift configuration.
 */
struct slcd_circular_shift_config {
        /** Frame counter selection for circular shift */
        enum slcd_frame_counter fc;
        /** Shift direction */
        enum slcd_circular_shift_dir dir;
        /** Size of the circular shift register, MAX. size is 16 */
        uint8_t size;
        /** Circular shift register value */
        uint16_t data;
};

/**
 * \brief Automated char  order
 *
 * Enum automated char order.
 */
enum slcd_automated_char_order {
        /** Segment is starting from bottom right */
        SLCD_AUTOMATED_CHAR_START_FROM_BOTTOM_RIGHT = 0,
        /** Segment is starting from bottom left */
        SLCD_AUTOMATED_CHAR_START_FROM_BOTTOM_LEFT,
};

/**
 * \brief Automated char display mode
 *
 * Enum automated char display mode.
 */
enum slcd_automated_char_mode {
        /** Sequential Display Mode */
        SLCD_AUTOMATED_CHAR_SEQ = 0,
        /** Scrolling Display Mode */
        SLCD_AUTOMATED_CHAR_SCROLL,
};

/**
 * \brief Automated char configuration
 *
 * SLCD automated char configuration.
 */
struct slcd_automated_char_config {
        /** Mapping order in automated char mode */
        enum slcd_automated_char_order order;
        /** Frame counter selection for automated character mapping */
        enum slcd_frame_counter fc;
        /** Display mode */
        enum slcd_automated_char_mode mode;
        /** Define the number of SEG line per digit,
                it equal to number of SEG line - 1 */
        uint8_t seg_line_num;
        /** Define the index of the first segment terminal of the digit to display */
        uint8_t start_seg_line;
        /** Define the number of digit per row */
        uint8_t row_digit_num;
        /** Define the number of digit, it must be greater than 1 */
        uint8_t digit_num;
        /** Define the number of steps in scrolling mode.
                scrolling_step = character string length - digit_num + 1 */
        uint8_t scrolling_step;
        /** Define the number of COM line per row,
                it equal to number of COM line - 1 */
        uint8_t com_line_num;
        /** Segments data mask */
        uint32_t data_mask;

};

/**
 * \name SLCD Basic Operation Functions
 * @{
 */
 /**
  * @brief Initialize driver.
  * @details Initializes the SLCD driver. This routine is typically called
  * by a graphics library or by the application during application initialization.
  * @code
  * gfxResult res = DRV_SLCD_Initialize();
  * @endcode
  * @return GFX_SUCCESS if driver ready to render, otherwise GFX_FAILURE.
  */
 gfxResult DRV_SLCD_Initialize(void);


 /**
  * @brief Execute update task.
  * @details Performs a driver task update.
  * @code
  * DRV_SLCD_Update();
  * @endcode
  * @return void.
  */
 void DRV_SLCD_Update(void);

void slcd_get_config_defaults(void);
void slcd_enable(void);
void slcd_disable(void);
bool slcd_is_enabled(void);
void slcd_reset(void);
enum status_code slcd_set_contrast(uint8_t contrast);

/**
 * \brief Determines if SLCD module is currently synchronizing to the bus
 *
 * Checks to see if the underlying hardware peripheral module(s) are currently
 * synchronizing across multiple clock domains to the hardware bus, This
 * function can be used to delay further operations on a module until such time
 * that it is ready, to prevent blocking delays for synchronization in the
 * user application.
 *
 * \return Synchronization status of the underlying hardware module.
 *
 * \retval true  If the module synchronization is ongoing
 * \retval false If the module has completed synchronization
 */
static inline bool slcd_is_syncing(void)
{

        if (SLCD_REGS->SLCD_SYNCBUSY) {
                return true;
        }

        return false;
}

/**
 * \brief Lock shadow memory
 *
 * It allows update of shadow display memory. If the display memory
 * is modified, the display remains unchanged when locked.
 */
static inline void slcd_lock_shadow_memory(void)
{
        SLCD_REGS->SLCD_CTRLC |= SLCD_CTRLC_LOCK_Msk;
}

/**
 * \brief Unlock shadow memory
 *
 * Unlock the shadow display memory.
 */
static inline void slcd_unlock_shadow_memory(void)
{
        SLCD_REGS->SLCD_CTRLC &= (SLCD_CTRLC_Msk & ( ~SLCD_CTRLC_LOCK_Msk));
}

/**
 * \brief Clear display memory
 *
 * Clears immediately the display memory.
 */
static inline void slcd_clear_display_memory(void)
{
        SLCD_REGS->SLCD_CTRLC |= SLCD_CTRLC_CLEAR_Msk;
}

/**
 * \brief Display enable
 *
 * Enable COM/SEG signal output.
 */
static inline void slcd_enable_display(void)
{
        SLCD_REGS->SLCD_CTRLD |= SLCD_CTRLD_DISPEN_Msk;
        while (slcd_is_syncing()) {
                /* Wait for synchronization */
        }
}

/**
 * \brief Display disable
 *
 * Disable COM/SEG signal output.
 */
static inline void slcd_disable_display(void)
{
        SLCD_REGS->SLCD_CTRLD &= (SLCD_CTRLD_Msk & ( ~SLCD_CTRLD_DISPEN_Msk));
        while (slcd_is_syncing()) {
                /* Wait for synchronization */
        }
}
/**
 * \brief  DMA display memory update frame counter selection
 *
 * It's used to select the frame counter for DMA to update the display memory.
 *
 *  \note It can be called only before the module is enabled.
 *
 *  \param[in] fc Frame coungter index
 */
static inline void slcd_dma_display_memory_update_fc_sel(enum slcd_frame_counter fc)
{
        SLCD_REGS->SLCD_CTRLA |= SLCD_CTRLA_DMFCS(fc);
}

/** @} */

/**
 * \name SLCD Blink Functions
 * @{
 */

/**
 * \brief Blink mode enable
 *
 * Enable blink mode.
 */
static inline void slcd_enable_blink(void)
{
        SLCD_REGS->SLCD_CTRLD |= SLCD_CTRLD_BLINK_Msk;
        while (slcd_is_syncing()) {
                /* Wait for synchronization */
        }
}

/**
 * \brief Blink mode disable
 *
 * Disable blink mode.
 */
static inline void slcd_disable_blink(void)
{
        SLCD_REGS->SLCD_CTRLD &= ~SLCD_CTRLD_BLINK_Msk;
        while (slcd_is_syncing()) {
                /* Wait for synchronization */
        }
}

void slcd_blink_get_config_defaults(struct slcd_blink_config *blink_config);
enum status_code slcd_blink_set_config(struct slcd_blink_config *const blink_config);

void slcd_clear_blink_all_pixel(void);
void slcd_clear_blink_pixel(uint8_t pix_com,uint8_t pix_seg);
void slcd_set_blink_pixel(uint8_t pix_com,uint8_t pix_seg);

/** @} */

/**
 * \name SLCD Blank Functions
 * @{
 */

/**
 * \brief Blank mode enable
 *
 * Enable blank mode.
 */
static inline void slcd_enable_blank(void)
{
        SLCD_REGS->SLCD_CTRLD |= SLCD_CTRLD_BLANK_Msk;
        while (slcd_is_syncing()) {
                /* Wait for synchronization */
        }
}
/**
 * \brief Blank mode disable
 *
 * Disable blank mode.
 */
static inline void slcd_disable_blank(void)
{
        SLCD_REGS->SLCD_CTRLD &= ~SLCD_CTRLD_BLANK_Msk;
        while (slcd_is_syncing()) {
                /* Wait for synchronization */
        }
}
/** @} */

/**
 * \name SLCD Event Functions
 * @{
 */

/**
 * \brief Enables a SLCD event output
 *
 *  Enables one or more output events.
 *
 *  \note Events cannot be altered while the module is enabled.
 *
 *  \param[in] events       Struct containing flags of events to enable
 */
static inline void slcd_enable_events(struct slcd_events *const events)
{

//	Assert(hw);
//	Assert(events);

        uint8_t event_mask = 0;

        if (events->generate_event_on_fc0_overflow) {
                event_mask |= SLCD_EVCTRL_FC0OEO_Msk;
        }

        if (events->generate_event_on_fc1_overflow) {
                event_mask |= SLCD_EVCTRL_FC1OEO_Msk;
        }

        if (events->generate_event_on_fc2_overflow) {
                event_mask |= SLCD_EVCTRL_FC2OEO_Msk;
        }

        SLCD_REGS->SLCD_EVCTRL |= event_mask;
}

/**
 * \brief Disables a SLCD event output
 *
 *  Disables one or more SLCD events output.
 *
 *  \param[in] events Struct containing flags of events to disable
 */
static inline void slcd_disable_events(struct slcd_events *const events)
{

//	Assert(events);

        uint8_t event_mask = 0;

        if (events->generate_event_on_fc0_overflow) {
                event_mask |= SLCD_EVCTRL_FC0OEO_Msk;
        }

        if (events->generate_event_on_fc1_overflow) {
                event_mask |= SLCD_EVCTRL_FC1OEO_Msk;
        }

        if (events->generate_event_on_fc2_overflow) {
                event_mask |= SLCD_EVCTRL_FC2OEO_Msk;
        }

        SLCD_REGS->SLCD_EVCTRL &= ~event_mask;
}

/** @} */

/**
 * \name SLCD Frame Counter Functions
 * @{
 */

/**
 * \brief Frame counter configuration
 *
 *  Config frame counter.
 *
 *  \note Frame counter cannot be set while it is enabled.
 *
 *  \param[in] fc Frame counter index
 *  \param[in] presc_bypass_enable Bypass of the frame counter prescaler
 *  \param[in] overflow_value  Frame counter overflow value. The number of frame
 *		before overflow is ((overflow_value+1)*8) when presc_bypass_enable=0
                else (overflow_value+1). The MAX. overflow value is 0x1FFFF.
 */
static inline void slcd_set_frame_counter(enum slcd_frame_counter fc,
                                                                                   bool  presc_bypass_enable,
                                                                                   uint16_t overflow_value)
{
        *(&(SLCD_REGS->SLCD_FC0) + fc) =  (presc_bypass_enable << SLCD_FC0_PB_Pos)
                                                         | SLCD_FC0_OVF(overflow_value);
}

/**
 * \brief Enables a frame counter
 *
 *  Enables one frame counter.
 *
 *	\param[in] fc Frame counter index
 */
static inline void slcd_enable_frame_counter(enum slcd_frame_counter fc)
{

        switch(fc) {
                case SLCD_FRAME_COUNTER_0:
                        SLCD_REGS->SLCD_CTRLD |= SLCD_CTRLD_FC0EN_Msk;
                        break;
                case SLCD_FRAME_COUNTER_1:
                        SLCD_REGS->SLCD_CTRLD |= SLCD_CTRLD_FC1EN_Msk;
                        break;
                case SLCD_FRAME_COUNTER_2:
                        SLCD_REGS->SLCD_CTRLD |= SLCD_CTRLD_FC2EN_Msk;
                        break;
                default :
                        break;
        }
        while (slcd_is_syncing()) {
                /* Wait for synchronization */
        }
}

/**
 * \brief Disable a frame counter.
 *
 *  Disable one frame counter.
 *
 *	\param[in] fc Frame counter index
 */
static inline void slcd_disable_frame_counter(enum slcd_frame_counter fc)
{
        switch(fc) {
                case SLCD_FRAME_COUNTER_0:
                        SLCD_REGS->SLCD_CTRLD &= ~SLCD_CTRLD_FC0EN_Msk;
                        break;
                case SLCD_FRAME_COUNTER_1:
                        SLCD_REGS->SLCD_CTRLD &= ~SLCD_CTRLD_FC1EN_Msk;
                        break;
                case SLCD_FRAME_COUNTER_2:
                        SLCD_REGS->SLCD_CTRLD &= ~SLCD_CTRLD_FC2EN_Msk;
                        break;
                default :
                        break;
        }
        while (slcd_is_syncing()) {
                /* Wait for synchronization */
        }
}
/** @} */

/**
 * \name Display Memory Functions
 * CPU can access display memory in direct access or in indirect access.
 * @{
 */
void slcd_set_display_memory(void);
void slcd_set_pixel(uint8_t pix_com, uint8_t pix_seg);
void slcd_clear_pixel(uint8_t pix_com, uint8_t pix_seg);

void slcd_set_seg_data(uint8_t seg_data, uint8_t byte_offset, uint8_t seg_mask);
/** @} */

/**
 * \name Character Mapping Functions
 * @{
 */

void slcd_character_map_set(
                enum slcd_automated_char_order order,
                uint8_t seg_line_num);
void slcd_character_write_data(uint8_t com_line_index,
                                                        uint8_t seg_line_index,
                                                        uint32_t seg_data,
                                                        uint32_t data_mask);

/**
 * \brief Enables automated character display
 *
 *  Enables automated character display.
 */
static inline void slcd_enable_automated_character(void)
{
        SLCD_REGS->SLCD_CTRLC |= SLCD_CTRLC_ACMEN_Msk;
}

/**
 * \brief Disables automated character display
 *
 *  Disables automated character display.
 */
static inline void slcd_disable_automated_character(void)
{
        SLCD_REGS->SLCD_CTRLC &= ~SLCD_CTRLC_ACMEN_Msk;
}
void slcd_automated_char_get_config_default(
                struct slcd_automated_char_config *config);
enum status_code slcd_automated_char_set_config(
                struct slcd_automated_char_config *const config);
/** @} */

/**
 * \name Automated Bit Mapping Functions
 * @{
 */

/**
 * \brief Enables automated bit display
 *
 *  Enables automated bit display.
 */
static inline void slcd_enable_automated_bit(void)
{
        SLCD_REGS->SLCD_CTRLC |= SLCD_CTRLC_ABMEN_Msk;
}

/**
 * \brief Disables automated bit display
 *
 *  Disables automated bit display.
 */
static inline void slcd_disable_automated_bit(void)
{
        SLCD_REGS->SLCD_CTRLC &= ~SLCD_CTRLC_ABMEN_Msk;
}

/**
 * \brief Sets automated bit display
 *
 *  Sets automated bit display.
 *
 *  \note Automated bit cannot be set while it is enabled or busy.
 */
static inline void slcd_set_automated_bit(uint8_t size,enum slcd_frame_counter fc)
{
        if(size > 0 && size < 0x3f) {
                SLCD_REGS->SLCD_ABMCFG = SLCD_ABMCFG_SIZE(size) | SLCD_ABMCFG_FCS(fc);
        }
}

/** @} */

/**
 * \name Autonomous Segment Animation
 * @{
 */

/**
 * \brief Enable SLCD circular shift mode
 */
static inline void slcd_enable_circular_shift(void)
{
        SLCD_REGS->SLCD_CTRLD |= SLCD_CTRLD_CSREN_Msk;
        while (slcd_is_syncing()) {
                /* Wait for synchronization */
        }
}
/**
 * \brief Disable SLCD circular shift mode
 */
static inline void slcd_disable_circular_shift(void)
{
        SLCD_REGS->SLCD_CTRLD &= ~SLCD_CTRLD_CSREN_Msk;
        while (slcd_is_syncing()) {
                /* Wait for synchronization */
        }
}
void slcd_circular_shift_get_config_defaults(
                struct slcd_circular_shift_config *const config);

enum status_code slcd_circular_shift_set_config(
                struct slcd_circular_shift_config *const config);

/** @} */

/**
 * \name SLCD Status
 * @{
 */

/**
 * \brief Checks if auto bit mapping state machine is busy
 *
 * Checks if  auto bit mapping state machine is busy or not.
 *
 * \retval true   Auto bit mapping state machine is busy
 * \retval false  Auto bit mapping state machine is idle
 */

static inline bool slcd_get_auto_bit_status(void)
{
        return ((SLCD_REGS->SLCD_STATUS & SLCD_STATUS_ABMBUSY_Msk) == SLCD_STATUS_ABMBUSY_Msk);
}

/**
 * \brief Checks if auto character mapping state machine is busy
 *
 * Checks if  auto character state machine is busy or not.
 *
 * \retval true   Auto character mapping state machine is busy
 * \retval false  Auto character mapping state machine is idle
 */

static inline bool slcd_get_auto_char_status(void)
{
        return ((SLCD_REGS->SLCD_STATUS & SLCD_STATUS_ACMBUSY_Msk) == SLCD_STATUS_ACMBUSY_Msk);
}

/**
 * \brief Checks if character writing function is busy
 *
 * Checks if character writing function is busy or not.
 *
 * \retval true   Character writting function is busy
 * \retval false  Character writting function is ready for use
 */

static inline bool slcd_get_char_writing_status(void)
{
        return ((SLCD_REGS->SLCD_STATUS & SLCD_STATUS_CMWRBUSY_Msk) == SLCD_STATUS_CMWRBUSY_Msk);
}

/**
 * \brief Checks VLCD and VDD33 status
 *
 * Checks VLCD and VDD33 status.
 *
 * \retval true   VDD33 is greater than target VLCD
 * \retval false  Target VLCD is greater than vdd33
 */

static inline bool slcd_get_vlcd_vdd33_status(void)
{
        return ((SLCD_REGS->SLCD_STATUS & SLCD_STATUS_VLCDS_Msk) == SLCD_STATUS_VLCDS_Msk);
}

/**
 * \brief Checks LCD charge pump status
 *
 * Checks LCD Charge Pump Status.
 *
 * \retval true   LCD power charge pump is running
 * \retval false  LCD power charge pump is stopped
 */

static inline bool slcd_get_charge_pump_status(void)
{
        return ((SLCD_REGS->SLCD_STATUS & SLCD_STATUS_PRUN_Msk) == SLCD_STATUS_PRUN_Msk);
}

/**
 * \brief Checks if VLCD  is ready
 *
 * Checks if VLCD is well regulated to the target value.
 *
 * \retval true   VLCD is well regulated to the target value
 * \retval false  VLCD is not well regulated to the target value
 */

static inline bool slcd_get_vlcd_ready_status(void)
{
        return ((SLCD_REGS->SLCD_STATUS & SLCD_STATUS_VLCDR_Msk) == SLCD_STATUS_VLCDR_Msk);
}

static const gfxDisplayDriver gfxDriverInterface =
{
        .update = DRV_SLCD_Update
};

/** @} */

#ifdef __cplusplus
}
#endif

/** @} */

/**
 * \page asfdoc_sam0_drivers_slcd_extra Extra Information for SLCD
 *
 * \section asfdoc_sam0_drivers_slcd_extra_acronyms Acronyms
 * Below is a table listing the acronyms used in this module, along with their
 * intended meanings.
 *
 * <table>
 *  <tr>
 *      <th>Acronym</th>
 *      <th>Definition</th>
 *  </tr>
 *  <tr>
 *      <td>SLCD</td>
 *      <td>Segment Liquid Crystal Display</td>
 * </tr>
 *  <tr>
 *      <td>COM</td>
 *      <td>Common, denotes how many segments are connected to a segment terminal</td>
 * </tr>
 *  <tr>
 *      <td>SEG</td>
 *      <td>Segment, the least viewing element (pixel) which can be on or off</td>
 * </tr>
 *  <tr>
 *      <td>Duty</td>
 *      <td> 1/(Number of common terminals on an actual LCD display)</td>
 * </tr>
 *  <tr>
 *      <td>Bias</td>
 *      <td>1/(Number of voltage levels used driving a LCD display -1)</td>
 * </tr>
 *  <tr>
 *      <td>Frame Rate</td>
 *      <td>Number of times the LCD segments are energized per second</td>
 * </tr>
 * </table>
 *
 *
 * \section asfdoc_sam0_drivers_slcd_extra_dependencies Dependencies
 * This driver has the following dependencies:
 *
 *  - None
 *
 *
 * \section asfdoc_sam0_drivers_slcd_extra_errata Errata
 * There are no errata related to this driver.
 *
 *
 * \section asfdoc_sam0_drivers_slcd_extra_history Module History
 * An overview of the module history is presented in the table below, with
 * details on the enhancements and fixes made to the module since its first
 * release. The current version of this corresponds to the newest version in
 * the table.
 *
 * <table>
 *	<tr>
 *		<th>Changelog</th>
 *	</tr>
 *	<tr>
 *		<td>Initial release</td>
 *	</tr>
 * </table>
 */

/**
 * \page asfdoc_sam0_drivers_slcd_exqsg Examples for SLCD
 *
 * This is a list of the available Quick Start Guides (QSGs) and example
 * applications for \ref asfdoc_sam0_drivers_slcd_group. QSGs are simple examples with
 * step-by-step instructions to configure and use this driver in a selection of
 * use cases. Note that a QSG can be compiled as a standalone application or be
 * added to the user application.
 *
 *  - \subpage asfdoc_sam0_slcd_basic_use_case
 *
 * \page asfdoc_sam0_drivers_slcd_document_revision_history Document Revision History
 *
 * <table>
 *	<tr>
 *		<th>Doc. rev.</th>
 *		<th>Date</th>
 *		<th>Comments</th>
 *	</tr>
 *	<tr>
 *      <td>42605A</td>
 *		<td>12/2015</td>
 *		<td>Initial release</td>
 *	</tr>
 * </table>
 *
 */

#endif  /* SLCD_H_INCLUDED */


#endif
