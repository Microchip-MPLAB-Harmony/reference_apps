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

#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/common/legato_math.h"
#include "gfx/legato/core/legato_state.h"
#include "gfx/legato/renderer/legato_renderer.h"
#include "gfx/legato/renderer/legato_gpu.h"

/* renderer function use only */
extern leRenderState _rendererState;

typedef leResult (*PixelPutFn)(int32_t, int32_t, leColor, uint32_t);

static leResult putPixel(int32_t x,
                         int32_t y,
                         leColor clr,
                         uint32_t);

#if LE_ALPHA_BLENDING_ENABLED == 1
static leResult blendPixel(int32_t x,
                           int32_t y,
                           leColor clr,
                           uint32_t a);
#endif

leColor leRenderer_GetPixel(int32_t x,
                            int32_t y)
{
    // adjust for rectangle position
    x -= _rendererState.layerStates[_rendererState.layerIdx].frameRectList.rects[_rendererState.frameRectIdx].x;
    y -= _rendererState.layerStates[_rendererState.layerIdx].frameRectList.rects[_rendererState.frameRectIdx].y;

#if LE_RENDER_ORIENTATION != 0
    leUtils_PointLogicalToScratch((int16_t*)&x, (int16_t*)&y);
#endif

    return lePixelBufferGet_Unsafe(leGetRenderBuffer(),
                                   x,
                                   y);
}

leResult leRenderer_GetPixel_Safe(int32_t x,
                                  int32_t y,
                                  leColor* clr)
{
    if(leRenderer_CullDrawXY(x, y) == LE_TRUE)
        return LE_FAILURE;

    // adjust for rectangle position
    x -= _rendererState.layerStates[_rendererState.layerIdx].frameRectList.rects[_rendererState.frameRectIdx].x;
    y -= _rendererState.layerStates[_rendererState.layerIdx].frameRectList.rects[_rendererState.frameRectIdx].y;

#if LE_RENDER_ORIENTATION != 0
    leUtils_PointLogicalToScratch((int16_t*)&x, (int16_t*)&y);
#endif

    *clr = lePixelBufferGet_Unsafe(leGetRenderBuffer(),
                                   x,
                                   y);

    return LE_SUCCESS;
}

static PixelPutFn pixelPutFn = putPixel;

leResult leRenderer_PutPixel(int32_t x,
                             int32_t y,
                             leColor clr)
{
    // adjust for rectangle position
    x -= _rendererState.layerStates[_rendererState.layerIdx].frameRectList.rects[_rendererState.frameRectIdx].x;
    y -= _rendererState.layerStates[_rendererState.layerIdx].frameRectList.rects[_rendererState.frameRectIdx].y;
    
    return pixelPutFn(x, y, clr, 0);
}

leResult leRenderer_PutPixel_Safe(int32_t x,
                                  int32_t y,
                                  leColor clr)
{
    if(leRenderer_CullDrawXY(x, y) == LE_TRUE)
        return LE_FAILURE;

    // adjust for rectangle position
    x -= _rendererState.layerStates[_rendererState.layerIdx].frameRectList.rects[_rendererState.frameRectIdx].x;
    y -= _rendererState.layerStates[_rendererState.layerIdx].frameRectList.rects[_rendererState.frameRectIdx].y;

    return pixelPutFn(x, y, clr, 0);
}

leResult leRenderer_BlendPixel(int32_t x,
                               int32_t y,
                               leColor clr,
                               uint32_t a)
{
    // adjust for rectangle position
    x -= _rendererState.layerStates[_rendererState.layerIdx].frameRectList.rects[_rendererState.frameRectIdx].x;
    y -= _rendererState.layerStates[_rendererState.layerIdx].frameRectList.rects[_rendererState.frameRectIdx].y;
    
#if LE_ALPHA_BLENDING_ENABLED == 1
    return blendPixel(x, y, clr, a);
#else
    return putPixel(x, y, clr, a);
#endif
}

leResult leRenderer_BlendPixel_Safe(int32_t x,
                                    int32_t y,
                                    leColor clr,
                                    uint32_t a)
{
    if(leRenderer_CullDrawXY(x, y) == LE_TRUE)
        return LE_FAILURE;

    // adjust for rectangle position
    x -= _rendererState.layerStates[_rendererState.layerIdx].frameRectList.rects[_rendererState.frameRectIdx].x;
    y -= _rendererState.layerStates[_rendererState.layerIdx].frameRectList.rects[_rendererState.frameRectIdx].y;

#if LE_ALPHA_BLENDING_ENABLED == 1
    return blendPixel(x, y, clr, a);
#else
    return putPixel(x, y, clr, a);
#endif
}

#if LE_ALPHA_BLENDING_ENABLED == 1
void leRenderer_SetAlphaEnabled(leBool enabled, uint8_t amt)
{    
    if(_rendererState.alphaEnable == enabled)
        return;
        
    _rendererState.alphaEnable = enabled;
    _rendererState.alpha = amt;
    
    if(enabled == LE_TRUE)
    {
        pixelPutFn = blendPixel;
    }
    else
    {
        pixelPutFn = putPixel;
    }
}
#endif

leResult putPixel(int32_t x,
                  int32_t y,
                  leColor clr,
                  uint32_t a)
{
    (void)a; // unused

#if LE_RENDER_ORIENTATION != 0
    leUtils_PointLogicalToScratch((int16_t*)&x, (int16_t*)&y);
#endif

    lePixelBufferSet_Unsafe(leGetRenderBuffer(),
                            x,
                            y,
                            clr);
                            
    return LE_SUCCESS;
}

#if LE_ALPHA_BLENDING_ENABLED == 1
leResult blendPixel(int32_t x, int32_t y, leColor clr, uint32_t a)
{
    leColor nativeSource;
    leColor rgbaSource;
    leColor rgbaDest;
    leColor resultClr;
    uint32_t currentAlpha;
    uint32_t alphaPercent;

#if LE_RENDER_ORIENTATION != 0
    leUtils_PointLogicalToScratch((int16_t*)&x, (int16_t*)&y);
#endif

    // upscale to alpha channel type
    nativeSource = lePixelBufferGet_Unsafe(leGetRenderBuffer(), x, y);

    rgbaDest = leColorConvert(leRenderer_CurrentColorMode(),
                              LE_COLOR_MODE_RGBA_8888,
                              nativeSource);

    rgbaSource = leColorConvert(leRenderer_CurrentColorMode(),
                                LE_COLOR_MODE_RGBA_8888,
                                clr);
    
    // blend existing alpha channel value with alpha argument value
    switch(leRenderer_CurrentColorMode())
    {
        case LE_COLOR_MODE_ARGB_8888:
        case LE_COLOR_MODE_RGBA_8888:
        case LE_COLOR_MODE_RGBA_5551:
        {

            currentAlpha = rgbaSource & 0xFF;
            alphaPercent = lePercentWholeRounded(a, 255);
            currentAlpha = lePercentOf(currentAlpha, alphaPercent);

            rgbaSource &= ~(RGBA_8888_ALPHA_MASK);
            rgbaSource |= currentAlpha;

            break;
        }
        default:
        {
            rgbaSource &= ~(RGBA_8888_ALPHA_MASK);
            rgbaSource |= a;
        }
    }

    if((rgbaSource & RGBA_8888_ALPHA_MASK) == 0)
        return LE_SUCCESS;

    resultClr = leColorBlend_RGBA_8888(rgbaSource, rgbaDest);

    // convert to destination format
    clr = leColorConvert(LE_COLOR_MODE_RGBA_8888,
                         leRenderer_CurrentColorMode(),
                         resultClr);
    
    lePixelBufferSet_Unsafe(leGetRenderBuffer(),
                            x,
                            y,
                            clr);
                            
    return LE_SUCCESS;
}
#endif

leResult leRenderer_FillArea(int32_t x,
                             int32_t y,
                             uint32_t width,
                             uint32_t height,
                             leColor clr,
                             uint32_t a)
{
#if LE_ALPHA_BLENDING_ENABLED == 1	
    uint32_t w, h;
#endif

    lePoint pnt;
    leRect fillRect;

    // adjust for rectangle position
    pnt.x = x - _rendererState.layerStates[_rendererState.layerIdx].frameRectList.rects[_rendererState.frameRectIdx].x;
    pnt.y = y - _rendererState.layerStates[_rendererState.layerIdx].frameRectList.rects[_rendererState.frameRectIdx].y;

    if(a == 0)
        return LE_SUCCESS;

    fillRect.x = pnt.x;
    fillRect.y = pnt.y;
    fillRect.width = width;
    fillRect.height = height;

    if(leGPU_FillRect(&fillRect, clr, a) == LE_SUCCESS)
        return LE_SUCCESS;

#if LE_ALPHA_BLENDING_ENABLED == 1
    if(a < 255) // also test global alpha value
    {
        for(h = 0; h < height; h++)
        {
            for(w = 0; w < width; w++)
            {
                // blend pixel will adjust for the rectangle
                leRenderer_BlendPixel_Safe(x + w, y + h, clr, a);
            }
        }
    }
    else
    {
#endif

#if LE_RENDER_ORIENTATION != 0
        leRect rotRect;
        rotRect.x = pnt.x;
        rotRect.y = pnt.y;
        rotRect.width = width;
        rotRect.height = height;

        leUtils_RectLogicalToScratch(&rotRect);

        pnt.x = rotRect.x;
        pnt.y = rotRect.y;
        width = rotRect.width;
        height = rotRect.height;
#endif

        lePixelBufferAreaFill_Unsafe(leGetRenderBuffer(),
                                     pnt.x,
                                     pnt.y,
                                     width,
                                     height,
                                     clr);
#if LE_ALPHA_BLENDING_ENABLED == 1
    }
#endif

    return LE_SUCCESS;
}

leResult leRenderer_FillArea_Safe(int32_t x,
                                  int32_t y,
                                  uint32_t width,
                                  uint32_t height,
                                  leColor clr,
                                  uint32_t a)
{
#if LE_ALPHA_BLENDING_ENABLED == 1	
    uint32_t w, h;
#endif
    lePoint pnt;
    leRect fillRect;

    // adjust for rectangle position
    pnt.x = x - _rendererState.layerStates[_rendererState.layerIdx].frameRectList.rects[_rendererState.frameRectIdx].x;
    pnt.y = y - _rendererState.layerStates[_rendererState.layerIdx].frameRectList.rects[_rendererState.frameRectIdx].y;

    if(a == 0)
        return LE_SUCCESS;

    fillRect.x = pnt.x;
    fillRect.y = pnt.y;
    fillRect.width = width;
    fillRect.height = height;

    if(a == 0)
        return LE_SUCCESS;

    fillRect.x = pnt.x;
    fillRect.y = pnt.y;
    fillRect.width = width;
    fillRect.height = height;

    if(leGPU_FillRect(&fillRect, clr, a) == LE_SUCCESS)
        return LE_SUCCESS;

#if LE_ALPHA_BLENDING_ENABLED == 1
    if(a < 255) // also test global alpha value
    {
        for(h = 0; h < height; h++)
        {
            for(w = 0; w < width; w++)
            {
                // blend pixel will adjust for the rectangle position
                leRenderer_BlendPixel(x + w, y + h, clr, a);
            }
        }
    }
    else
    {
#endif

#if LE_RENDER_ORIENTATION > 0
        leRect rotRect;
        rotRect.x = pnt.x;
        rotRect.y = pnt.y;
        rotRect.width = width;
        rotRect.height = height;

        leUtils_RectLogicalToScratch(&rotRect);

        pnt.x = rotRect.x;
        pnt.y = rotRect.y;
        width = rotRect.width;
        height = rotRect.height;
#endif

        lePixelBufferAreaFill(leGetRenderBuffer(),
                              pnt.x,
                              pnt.y,
                              width,
                              height,
                              clr);
#if LE_ALPHA_BLENDING_ENABLED == 1
    }
#endif

    return LE_SUCCESS;
}