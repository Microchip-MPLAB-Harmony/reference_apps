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

#include "gfx/legato/renderer/legato_renderer.h"

#if LE_STREAMING_ENABLED == 1

#ifndef LE_RASTERFONT_GLYPH_CACHE_SIZE
#define LE_RASTERFONT_GLYPH_CACHE_SIZE  256
#endif

static uint8_t glyphCache[LE_RASTERFONT_GLYPH_CACHE_SIZE];

static struct
{
    leFontStream fontStream;

    leStreamState state;

    leRasterFont* font;
    leFontGlyph info;
    int32_t x;
    int32_t y;
    leColor clr;
    uint32_t a;
} rasterStream;

static void streamDataReady(leStream* stream)
{
    (void)stream; // unused

    leFont_DrawGlyphData((leFont*)rasterStream.font,
                         &rasterStream.info,
                         glyphCache,
                         rasterStream.x,
                         rasterStream.y,
                         rasterStream.clr,
                         rasterStream.a);

    rasterStream.state = LE_STREAM_READY;

    if(rasterStream.fontStream.cb != NULL)
    {
        rasterStream.fontStream.cb(rasterStream.info.codePoint);
    }
}

static leResult drawGlyph(const leFontGlyph* glyph,
                          int32_t x,
                          int32_t y,
                          leColor clr,
                          uint32_t a,
                          leFontStream_DrawCompleteFn cb)
{
    leRect glyphRect;

    if(rasterStream.state == LE_STREAM_WAITING ||
       rasterStream.font == NULL ||
       glyph == NULL)
    {
        return LE_FAILURE;
    }

    glyphRect.x = x;
    glyphRect.y = y;
    glyphRect.width = glyph->width;
    glyphRect.height = glyph->height;

    if(leRenderer_CullDrawRect(&glyphRect) == LE_TRUE)
        return LE_FAILURE;

    rasterStream.info = *glyph;

    if(rasterStream.info.dataRowWidth * rasterStream.info.height >= LE_RASTERFONT_GLYPH_CACHE_SIZE)
        return LE_FAILURE;

    rasterStream.info = *glyph;
    rasterStream.x = x;
    rasterStream.y = y;
    rasterStream.clr = clr;
    rasterStream.a = a;
    rasterStream.fontStream.cb = cb;

    rasterStream.state = LE_STREAM_WAITING;

    leStream_Read(&rasterStream.fontStream.stream,
                  (uint32_t)rasterStream.font->base.header.address + rasterStream.info.dataOffset,
                  rasterStream.info.dataRowWidth * rasterStream.info.height,
                  glyphCache,
                  streamDataReady);

    return LE_SUCCESS;
}

static leResult drawGlyph_blocking(const leFontGlyph* glyph,
                                   int32_t x,
                                   int32_t y,
                                   leColor clr,
                                   uint32_t a,
                                   leFontStream_DrawCompleteFn cb)
{
    leRect glyphRect;

    if(rasterStream.font == NULL || glyph == NULL)
        return LE_FAILURE;

    glyphRect.x = x;
    glyphRect.y = y;
    glyphRect.width = glyph->width;
    glyphRect.height = glyph->height;

    if(leRenderer_CullDrawRect(&glyphRect) == LE_TRUE)
        return LE_FAILURE;

    rasterStream.info = *glyph;

    if(rasterStream.info.dataRowWidth * rasterStream.info.height >= LE_RASTERFONT_GLYPH_CACHE_SIZE)
        return LE_FAILURE;

    rasterStream.info = *glyph;
    rasterStream.x = x;
    rasterStream.y = y;
    rasterStream.clr = clr;
    rasterStream.a = a;
    rasterStream.fontStream.cb = cb;

    leStream_Read(&rasterStream.fontStream.stream,
                  (uint32_t)rasterStream.font->base.header.address + rasterStream.info.dataOffset,
                  rasterStream.info.dataRowWidth * rasterStream.info.height,
                  glyphCache,
                  NULL);

    leFont_DrawGlyphData((leFont*)rasterStream.font,
                         &rasterStream.info,
                         glyphCache,
                         rasterStream.x,
                         rasterStream.y,
                         rasterStream.clr,
                         rasterStream.a);

    if(rasterStream.fontStream.cb != NULL)
    {
        rasterStream.fontStream.cb(rasterStream.info.codePoint);
    }

    return LE_SUCCESS;
}

static leBool isDone()
{
    return rasterStream.state == LE_STREAM_READY;
}

static void close()
{
    if(rasterStream.state != LE_STREAM_CLOSED)
    {
        leStream_Close(&rasterStream.fontStream.stream);
    }

    memset(&rasterStream, 0, sizeof(rasterStream));
}

static leResult open()
{
    if(rasterStream.state != LE_STREAM_CLOSED)
        return LE_FAILURE;

    if(leStream_Open(&rasterStream.fontStream.stream) == LE_FAILURE)
        return LE_FAILURE;

    if(leStream_IsBlocking((leStream*)&rasterStream.fontStream) == LE_TRUE)
    {
        rasterStream.fontStream.drawGlyph = drawGlyph_blocking;
    }
    else
    {
        rasterStream.fontStream.drawGlyph = drawGlyph;
    }

    rasterStream.state = LE_STREAM_READY;

    return LE_SUCCESS;
}

leFontStream* leRasterFontStream_Init(leFont* font)
{
    if(rasterStream.font != NULL)
    {
        close();
    }

    leStream_Init(&rasterStream.fontStream.stream,
                  (leStreamDescriptor*)font,
                  0,
                  NULL,
                  NULL);

    rasterStream.font = (leRasterFont*)font;
    rasterStream.state = LE_STREAM_CLOSED;

    rasterStream.fontStream.open = open;
    rasterStream.fontStream.isDone = isDone;
    rasterStream.fontStream.close = close;

    return (leFontStream*)&rasterStream;
}

#endif