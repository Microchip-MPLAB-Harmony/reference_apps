/**
 * \file
 *
 * \brief SSD1306 OLED display controller driver.
 */

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#include "gfx_definitions.h"
#include "gfx_ssd1306.h"
#include "gfx_mono_ug_2832hsweg04.h"

/**
 * \brief Initialize the OLED controller
 *
 * Call this function to initialize the hardware interface and the OLED
 * controller. When initialization is done the display is turned on and ready
 * to receive data.
 */
void ssd1306_init(void) {
    // Initialize the interface
    //	ssd1306_interface_init();    // --> already set by H3

    // Do a hard reset of the OLED display controller
    ssd1306_hard_reset();

    // Set the reset pin to the default state	
    GFX_DISPLAY_RESET_SET();

    // 1/32 Duty (0x0F~0x3F)
    ssd1306_write_command(SSD1306_CMD_SET_MULTIPLEX_RATIO);
    ssd1306_write_command(0x1F);

    // Shift Mapping RAM Counter (0x00~0x3F)
    ssd1306_write_command(SSD1306_CMD_SET_DISPLAY_OFFSET);
    ssd1306_write_command(0x00);

    // Set Mapping RAM Display Start Line (0x00~0x3F)
    ssd1306_write_command(SSD1306_CMD_SET_DISPLAY_START_LINE(0x00));

    // Set Column Address 0 Mapped to SEG0
    ssd1306_write_command(SSD1306_CMD_SET_SEGMENT_RE_MAP_COL127_SEG0);

    // Set COM/Row Scan Scan from COM63 to 0
    ssd1306_write_command(SSD1306_CMD_SET_COM_OUTPUT_SCAN_DOWN);

    // Set COM Pins hardware configuration
    ssd1306_write_command(SSD1306_CMD_SET_COM_PINS);
    ssd1306_write_command(0x02);

    ssd1306_set_contrast(0x8F);

    // Disable Entire display On
    ssd1306_write_command(SSD1306_CMD_ENTIRE_DISPLAY_AND_GDDRAM_ON);

    ssd1306_display_invert_disable();

    // Set Display Clock Divide Ratio / Oscillator Frequency (Default => 0x80)
    ssd1306_write_command(SSD1306_CMD_SET_DISPLAY_CLOCK_DIVIDE_RATIO);
    ssd1306_write_command(0x80);

    // Enable charge pump regulator
    ssd1306_write_command(SSD1306_CMD_SET_CHARGE_PUMP_SETTING);
    ssd1306_write_command(0x14);

    // Set VCOMH Deselect Level
    ssd1306_write_command(SSD1306_CMD_SET_VCOMH_DESELECT_LEVEL);
    ssd1306_write_command(0x40); // Default => 0x20 (0.77*VCC)

    // Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
    ssd1306_write_command(SSD1306_CMD_SET_PRE_CHARGE_PERIOD);
    ssd1306_write_command(0xF1);

    ssd1306_display_on();
}

/**
 * \brief Writes a command to the display controller
 *
 * This functions pull pin D/C# low before writing to the controller. Different
 * data write function is called based on the selected interface.
 *
 * \param command the command to write
 */
void ssd1306_write_command(uint8_t command) {
    GFX_DISPLAY_SS_N_CLEAR();
    GFX_DATA_CMD_SEL_CLEAR();
    GFX_SPI_WRITE_FUNCTION(&command, 1);
    while (GFX_SPI_IS_BUSY());
    GFX_DISPLAY_SS_N_SET();
}

/**
 * \brief Write data to the display controller
 *
 * This functions sets the pin D/C# before writing to the controller. Different
 * data write function is called based on the selected interface.
 *
 * \param data the data to write
 */
void ssd1306_write_data(uint8_t data) {
    GFX_DISPLAY_SS_N_CLEAR();
    GFX_DATA_CMD_SEL_SET();
    GFX_SPI_WRITE_FUNCTION(&data, 1);
    while (GFX_SPI_IS_BUSY());
    GFX_DISPLAY_SS_N_SET();
}
