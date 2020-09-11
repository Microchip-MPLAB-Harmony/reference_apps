/**
 * \file
 *
 * \brief Font and text drawing routines
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

#include "stddef.h"
#include "assert.h"

#include "gfx_definitions.h"
#include "gfx_mono.h"
#include "gfx_mono_text.h"

#ifndef CONFIG_FONT_PIXELS_PER_BYTE
#define CONFIG_FONT_PIXELS_PER_BYTE    8
#endif

#define EXTMEM_BUF_SIZE                 20

#if defined(CONFIG_HUGEMEM) || defined(__DOXYGEN__)

/**
 * \internal
 * \brief Helper function that draws a character from a font in hugemem
 *        to the display
 *
 * This function will first calculate the start offset in the font character
 * data before iterating over the specific character data.
 *
 * Only pixels in the character that should be enabled are done so, the caller
 * is required to prepare the drawing area before printing a character to it.
 * This is done by the gfx_mono_draw_string() and
 * gfx_mono_draw_progmem_string() functions.
 *
 * \param[in] ch       Character to be drawn
 * \param[in] x        X coordinate on screen.
 * \param[in] y        Y coordinate on screen.
 * \param[in] font     Font to draw character in
 */
static void gfx_mono_draw_char_hugemem(const char ch, const gfx_coord_t x,
        const gfx_coord_t y, const struct font *font) {
    uint8_t i;
    uint8_t char_row_size;
    uint8_t glyph_size;
    uint16_t glyph_data_offset;
    uint8_t char_buff[EXTMEM_BUF_SIZE];
    uint8_t buffer_pos;
    uint8_t rows_left;

    /* Sanity check on parameters, assert if font is NULL. */
    Assert(font != NULL);

    gfx_coord_t inc_x = x;
    gfx_coord_t inc_y = y;

    char_row_size = font->width / CONFIG_FONT_PIXELS_PER_BYTE;
    if (font->width % CONFIG_FONT_PIXELS_PER_BYTE) {
        char_row_size++;
    }

    glyph_size = char_row_size * font->height;
    glyph_data_offset = glyph_size * ((uint8_t) ch - font->first_char);
    buffer_pos = EXTMEM_BUF_SIZE;
    rows_left = font->height;

    do {
        static uint8_t glyph_byte = 0;
        uint8_t pixelsToDraw = font->width;

        for (i = 0; i < pixelsToDraw; i++) {
            if (i % CONFIG_FONT_PIXELS_PER_BYTE == 0) {
                /* Read another byte from hugemem */
                if (buffer_pos >= EXTMEM_BUF_SIZE) {
                    hugemem_ptr_t source
                            = font->data.hugemem;
                    source = (hugemem_ptr_t)
                            ((uint32_t) source +
                            glyph_data_offset);

                    hugemem_read_block(char_buff, source,
                            EXTMEM_BUF_SIZE);

                    glyph_data_offset += EXTMEM_BUF_SIZE;
                    buffer_pos = 0;
                }

                glyph_byte = char_buff[buffer_pos];
                buffer_pos++;
            }

            /* Draw bit of glyph to screen */
            if ((glyph_byte & 0x80)) {
                gfx_mono_draw_pixel(inc_x, inc_y,
                        GFX_PIXEL_SET);
            }

            inc_x += 1;
            glyph_byte <<= 1;
        }

        inc_y += 1;
        inc_x = x;
    } while (--rows_left > 0);
}

#endif

/**
 * \internal
 * \brief Helper function that draws a character from a font in progmem
 *        to the display
 *
 * This function will first calculate the start offset in the font character
 * data before iterating over the specific character data.
 *
 * Only pixels in the character that should be enabled are done so, the caller
 * is required to prepare the drawing area before printing a character to it.
 * This is done by the gfx_mono_draw_string() and
 * gfx_mono_draw_progmem_string() functions.
 *
 * \param[in] ch       Character to be drawn
 * \param[in] x        X coordinate on screen.
 * \param[in] y        Y coordinate on screen.
 * \param[in] font     Font to draw character in
 */
static void gfx_mono_draw_char_progmem(const char ch, const gfx_coord_t x,
        const gfx_coord_t y, const struct font *font) {
    uint8_t PROGMEM_PTR_T glyph_data;
    uint16_t glyph_data_offset;
    uint8_t char_row_size;
    uint8_t rows_left;
    uint8_t i;

    /* Sanity check on parameters, assert if font is NULL. */
    assert(font != NULL);

    gfx_coord_t inc_x = x;
    gfx_coord_t inc_y = y;

    char_row_size = font->width / CONFIG_FONT_PIXELS_PER_BYTE;
    if (font->width % CONFIG_FONT_PIXELS_PER_BYTE) {
        char_row_size++;
    }

    glyph_data_offset = char_row_size * font->height *
            ((uint8_t) ch - font->first_char);
    glyph_data = font->data.progmem + glyph_data_offset;
    rows_left = font->height;

    do {
        uint8_t glyph_byte = 0;
        uint8_t pixelsToDraw = font->width;

        for (i = 0; i < pixelsToDraw; i++) {
            if (i % CONFIG_FONT_PIXELS_PER_BYTE == 0) {
                glyph_byte = PROGMEM_READ_BYTE(glyph_data);
                glyph_data++;
            }

            if ((glyph_byte & 0x80)) {
                gfx_mono_draw_pixel(inc_x, inc_y,
                        GFX_PIXEL_SET);
            }

            inc_x += 1;
            glyph_byte <<= 1;
        }

        inc_y += 1;
        inc_x = x;
        rows_left--;
    } while (rows_left > 0);
}

/**
 * \brief Draws a character to the display
 *
 * \param[in] c        Character to be drawn
 * \param[in] x        X coordinate on screen.
 * \param[in] y        Y coordinate on screen.
 * \param[in] font     Font to draw character in
 */
void gfx_mono_draw_char(const char c, const gfx_coord_t x, const gfx_coord_t y,
        const struct font *font) {
    gfx_mono_draw_filled_rect(x, y, font->width, font->height,
            GFX_PIXEL_CLR);

    switch (font->type) {
        case FONT_LOC_PROGMEM:
            gfx_mono_draw_char_progmem(c, x, y, font);
            break;

#ifdef CONFIG_HUGEMEM
        case FONT_LOC_HUGEMEM:
            gfx_mono_draw_char_hugemem(c, x, y, font);
            break;

#endif
        default:
            /* Unsupported mode, call assert */
            assert(false);
            break;
    }
}

/**
 * \brief Draws a string to the display
 *
 * This function will draw a string located in memory to the display.
 *
 * \param[in] str       Pointer to string
 * \param[in] x         X coordinate on screen.
 * \param[in] y         Y coordinate on screen.
 * \param[in] font      Font to draw string in
 */
void gfx_mono_draw_string(const char *str, gfx_coord_t x, gfx_coord_t y,
        const struct font *font) {
    /* Save X in order to know where to return to on CR. */
    const gfx_coord_t start_of_string_position_x = x;

    /* Sanity check on parameters, assert if str or font is NULL. */
    assert(str != NULL);
    assert(font != NULL);

    /* Draw characters until trailing null byte */
    do {
        /* Handle '\n' as newline, draw normal characters. */
        if (*str == '\n') {
            x = start_of_string_position_x;
            y += font->height;
        } else if (*str == '\r') {
            /* Skip '\r' characters. */
        } else {
            gfx_mono_draw_char(*str, x, y, font);
            x += font->width;
        }
    } while (*(++str));
}

/**
 * \brief Draws a string located in program memory to the display
 *
 * This function will draw a string located in program memory to the display,
 * this differs from gfx_mono_draw_string() by using constant string data from
 * the program memory instead of string data in RAM.
 *
 * Using program memory for constant strings will reduce the applications need
 * for RAM, and thus lower the overall size footprint.
 *
 * \param[in] str       Pointer to string located in program memory
 * \param[in] x         X coordinate on screen.
 * \param[in] y         Y coordinate on screen.
 * \param[in] font      Font to draw string in
 */
void gfx_mono_draw_progmem_string(char PROGMEM_PTR_T str, gfx_coord_t x,
        gfx_coord_t y, const struct font *font) {
    char temp_char;

    /* Sanity check on parameters, assert if str or font is NULL. */
    assert(str != NULL);
    assert(font != NULL);

    /* Save X in order to know where to return to on CR. */
    const gfx_coord_t start_of_string_position_x = x;

    /* Draw characters until trailing null byte */
    temp_char = PROGMEM_READ_BYTE((uint8_t PROGMEM_PTR_T) str);

    while (temp_char) {
        /* Handle '\n' as newline, draw normal characters. */
        if (temp_char == '\n') {
            x = start_of_string_position_x;
            y += font->height;
        } else if (temp_char == '\r') {
            /* Skip '\r' characters. */
        } else {
            gfx_mono_draw_char(temp_char, x, y, font);
            x += font->width;
        }

        temp_char = PROGMEM_READ_BYTE((uint8_t PROGMEM_PTR_T) (++str));
    }
}

/**
 * \brief Computes the bounding box of a string
 *
 * \note If string is empty the returned width will be 1 pixel and the height
 * equal to the font height.
 *
 * \param[in] str      String to calculate bounding box for
 * \param[in] font     Font used
 * \param[in] width    Pointer to width result
 * \param[in] height   Pointer to height result
 */
void gfx_mono_get_string_bounding_box(const char *str, const struct font *font,
        gfx_coord_t *width, gfx_coord_t *height) {
    gfx_coord_t font_width = font->width;
    gfx_coord_t font_height = font->height;

    gfx_coord_t max_width = 1;
    gfx_coord_t max_height = font_height;
    gfx_coord_t x = 0;

    /* Sanity check on parameters, assert if str or font is NULL. */
    assert(str != NULL);
    assert(font != NULL);

    /* Handle each character until trailing null byte */
    do {
        /* Handle '\n' as newline, draw normal characters. */
        if (*str == '\n') {
            x = 0;
            max_height += font_height;
        } else if (*str == '\r') {
            /* Skip '\r' characters. */
        } else {
            x += font_width;
            if (x > max_width) {
                max_width = x;
            }
        }
    } while (*(++str));

    /* Return values through references */
    *width = max_width;
    *height = max_height;
}

/**
 * \brief Computes the bounding box of a string located in program memory
 *
 * \note If string is empty the returned width will be 1 pixel and the height
 * equal to the font height.
 *
 * \param[in] str      String in program memory to calculate bounding box for
 * \param[in] font     Font used
 * \param[in] width    Pointer to width result
 * \param[in] height   Pointer to height result
 */
void gfx_mono_get_progmem_string_bounding_box(char PROGMEM_PTR_T str,
        const struct font *font, gfx_coord_t *width,
        gfx_coord_t *height) {
    gfx_coord_t font_width = font->width;
    gfx_coord_t font_height = font->height;

    char temp_char;
    gfx_coord_t max_width = 1;
    gfx_coord_t max_height = font_height;
    gfx_coord_t x = 0;

    /* Sanity check on parameters, assert if str or font is NULL. */
    assert(str != NULL);
    assert(font != NULL);

    /* Handle each character until trailing null byte */
    temp_char = PROGMEM_READ_BYTE((uint8_t PROGMEM_PTR_T) str);

    while (temp_char) {
        /* Handle '\n' as newline, draw normal characters. */
        if (temp_char == '\n') {
            x = 0;
            max_height += font_height;
        } else if (*str == '\r') {
            /* Skip '\r' characters. */
        } else {
            x += font_width;
            if (x > max_width) {
                max_width = x;
            }
        }

        temp_char = PROGMEM_READ_BYTE((uint8_t PROGMEM_PTR_T) (++str));
    }

    /* Return values through references */
    *width = max_width;
    *height = max_height;
}
