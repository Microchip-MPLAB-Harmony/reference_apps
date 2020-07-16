// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

#include "gfx/legato/font/legato_font.h"

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_math.h"
#include "gfx/legato/common/legato_rect.h"
#include "gfx/legato/renderer/legato_renderer.h"

int32_t getGlyphRowDataSize1bpp(int32_t width)
{
    int32_t offset;
    
    offset = width >> 3;
    offset += (width % 8) > 0 ? 1 : 0;
    
    return offset;
}
                            
int32_t getGlyphRowDataSize8bpp(int32_t width)
{
    return width;
} 

typedef int32_t (*getGlyphRowDataSize_FnPtr)(int32_t);
                                         
getGlyphRowDataSize_FnPtr glyphRowDataSizeFn[] =
{
    &getGlyphRowDataSize1bpp,
    &getGlyphRowDataSize8bpp
};

typedef void (*drawGlyphRow_FnPtr)(const uint8_t*,
                                   //int32_t,
                                   int32_t,
                                   int32_t,
                                   int32_t,
                                   int32_t,
                                   leColor,
                                   uint32_t a);

void drawGlyphRow1bpp(const uint8_t* data,
                      //int32_t width,
                      int32_t x,
                      int32_t y,
                      int32_t colStart,
                      int32_t colEnd,
                      leColor clr,
                      uint32_t a)
{
    int32_t i;
    uint32_t offs;
    uint8_t val;
    
    a = leClampi(0, 255, a);
    
    if(a < 255)
    {
        for(i = colStart; i < colEnd; i++)
        {
            offs = (i % 8);
            
            val = data[i >> 3] & (0x80 >> offs);
            
            if(val > 0)
            {
                leRenderer_BlendPixel(x + i, y, clr, a);
            }
        }
    }
    else
    {
        for(i = colStart; i < colEnd; i++)
        {
            offs = (i % 8);
            
            val = data[i >> 3] & (0x80 >> offs);
            
            if(val > 0)
            {
                leRenderer_PutPixel(x + i, y, clr);
            }
        }
    }
}
                            
void drawGlyphRow8bpp(const uint8_t* data,
                      //int32_t width,
                      int32_t x,
                      int32_t y,
                      int32_t colStart,
                      int32_t colEnd,
                      leColor clr,
                      uint32_t a)
{
    int32_t i;
    uint32_t valPercent;
    uint32_t aPercent;
    
    a = leClampi(0, 255, a);
    
    if(a < 255)
    {
        aPercent = lePercentWholeRounded(a, 255);
        
        for(i = colStart; i < colEnd; i++)
        {
            if(data[i] > 0)
            {
                valPercent = lePercentWholeRounded(data[i], 255);
                valPercent = lePercentOf(aPercent, valPercent);
                valPercent = lePercentOf(valPercent, 255);
            
                leRenderer_BlendPixel(x + i, y, clr, valPercent);
            }
        }
    }
    else
    {
        for(i = colStart; i < colEnd; i++)
        {
            if(data[i] > 0)
            {
                leRenderer_BlendPixel(x + i, y, clr, data[i]);
            }
        }
    }
} 
                                         
drawGlyphRow_FnPtr drawGlyphRowFn[] =
{
    &drawGlyphRow1bpp,
    &drawGlyphRow8bpp
};

void leFont_DrawGlyphRow(leFontBPP bpp,
                         const uint8_t* data,
                         int32_t x,
                         int32_t y,
                         int32_t colStart,
                         int32_t colEnd,
                         leColor clr,
                         uint32_t a)
{
    drawGlyphRowFn[bpp](data, x, y, colStart, colEnd, clr, a);
}

leResult leFont_GetGlyphInfo(const leFont* fnt,
                             uint32_t codepoint,
                             leFontGlyph* glyph)
{
    uint32_t idx = 0;
    uint32_t glyphCount;
    leFontGlyph* glyphTable;
    leRasterFont* rasFont = (leRasterFont*)fnt;
    
    LE_ASSERT(fnt != NULL && rasFont->glyphTable != NULL);
        
    glyphCount = ((uint32_t*)rasFont->glyphTable)[0];
    glyphTable = (leFontGlyph*)(rasFont->glyphTable + sizeof(uint32_t));
    
    // attempt to find the glyph in the range lookup tables
    for(idx = 0; idx < glyphCount; idx++)
    {
        
        /* O1 linear search, faster searches could be implemented but would require more 
           memory */
        if(codepoint == glyphTable[idx].codePoint)
        {
            *glyph = glyphTable[idx];
            
            return LE_SUCCESS;
        }
    }
    
    if(codepoint == 0x20)
    {
        // return space glyph
        glyph->codePoint = 0x20;
        glyph->width = glyph->width;
        glyph->height = 0; 
        glyph->advance = glyph->width;
        glyph->bearingX = 0;
        glyph->bearingY = 0;
        glyph->dataOffset = 0;
        glyph->dataRowWidth = 0;
    }
    else
    {
        // return unknown glyph
        glyph->codePoint = -1;
        glyph->width = rasFont->height >> 1;
        glyph->height = rasFont->height;
        glyph->advance = glyph->width;
        glyph->bearingX = 0;
        glyph->bearingY = rasFont->height;
        glyph->dataOffset = 0;
        glyph->dataRowWidth = 0;
    }
    
    return LE_FAILURE;
}

leResult leFont_GetGlyphRect(const leFontGlyph* glyph,
                             leRect* rect)
{   
    if(glyph == NULL || rect == NULL)
        return LE_FAILURE;

    rect->x = 0;
    rect->y = 0;
    rect->width = glyph->width;
    rect->height = glyph->height;
    
    return LE_SUCCESS;
}

void leFont_DrawUnknownGlyph(int32_t x,
                             int32_t y,
                             const leFontGlyph* glyph,
                             leColor clr,
                             uint32_t a)
{
    leRect glyphRect;
    
    glyphRect.x = x;
    glyphRect.y = y;
    glyphRect.width = glyph->width - 1;
    glyphRect.height = glyph->height - 1;
    
    /*leRenderer_RectFill(&glyphRect,
                        leColorValue(LE_COLOR_MODE_RGB_565, LE_COLOR_RED),
                        255);*/
    
    if(leRenderer_CullDrawRect(&glyphRect) == LE_TRUE)
        return;
    
    // left line
    leRenderer_VertLine(x,
                        y,
                        glyph->height - 1,
                        clr,
                        a);
    
    // right line
    leRenderer_VertLine(x + glyph->width - 1,
                        y,
                        glyph->height - 1,
                        clr,
                        a);     
    
    // top line
    leRenderer_HorzLine(x,
                        y,
                        glyph->width - 1,
                        clr,
                        a);     
    
    // bottom line
    leRenderer_HorzLine(x,
                        y + glyph->height - 1,
                        glyph->width - 1,
                        clr,
                        a);     
}

leResult leFont_DrawGlyphData(const leFont* fnt,
                              const leFontGlyph* glyph,
                              const uint8_t* data,
                              int32_t x,
                              int32_t y,
                              leColor clr,
                              uint32_t a)
{
    int32_t row;
    leRect glyphRect;
    leRect clippedGlyph;
    int32_t colStart, colEnd;
    leRasterFont* rasFnt = (leRasterFont*)fnt;
    
    //x += glyph->bearingX;
    //y += (fnt->baseline - glyph->bearingY);
    
    glyphRect.x = x;
    glyphRect.y = y;
    glyphRect.width = glyph->width;
    glyphRect.height = glyph->height;
    
    if(leRenderer_CullDrawRect(&glyphRect) == LE_TRUE)
        return LE_SUCCESS;
    
    leRenderer_ClipDrawRect(&glyphRect, &clippedGlyph);
    
    if(x >= clippedGlyph.x)
    {
        colStart = 0;
    }
    else
    {
        colStart = clippedGlyph.x - x;
    }
        
    if(x + (int32_t)glyph->width <= clippedGlyph.x + clippedGlyph.width)
    {
        colEnd = glyph->width;
    }
    else
    {
        colEnd = glyph->width + ((clippedGlyph.x + clippedGlyph.width) - (x + (int32_t)glyph->width));
    }
    
    for(row = clippedGlyph.y - glyphRect.y; row < (clippedGlyph.y - glyphRect.y) + (clippedGlyph.height); row++)
    {
        drawGlyphRowFn[rasFnt->bpp](data + (row * glyph->dataRowWidth),
                                    x,
                                    y + row,
                                    colStart,
                                    colEnd,
                                    clr,
                                    a);
    }

    return LE_SUCCESS;
}

leResult leFont_DrawGlyph(const leFont* fnt,
                          const leFontGlyph* glyph,
                          int32_t x,
                          int32_t y,
                          leColor clr,
                          uint32_t a)
{
    uint8_t* addr;

    if(fnt == NULL || glyph == NULL)
        return LE_FAILURE;
    
    // attempt to find the glyph raster data
    // if no data found then draw empty rectangle
    if(glyph->codePoint == LE_UNKNOWN_GLYPH)
    {
        leFont_DrawUnknownGlyph(x, y, glyph, clr, a);

        return LE_SUCCESS;
    }
    else
    {
        if(fnt->header.location == LE_STREAM_LOCATION_ID_INTERNAL)
        {
            addr = ((uint8_t*)fnt->header.address);
            addr += glyph->dataOffset;

            return leFont_DrawGlyphData(fnt, glyph, addr, x, y, clr, a);
        }
    }

    return LE_FAILURE;
}

#if LE_STREAMING_ENABLED == 1
leStreamManager* leRasterFontStream_Init(const leRasterFont* font);

leFontStream* leFont_GetStream(const leFont* fnt)
{
    if(fnt == NULL)
        return NULL;

    if(fnt->type == LE_RASTER_FONT)
    {
        return (leFontStream*)leRasterFontStream_Init((const leRasterFont*)fnt);
    }

    return NULL;
}
#endif




