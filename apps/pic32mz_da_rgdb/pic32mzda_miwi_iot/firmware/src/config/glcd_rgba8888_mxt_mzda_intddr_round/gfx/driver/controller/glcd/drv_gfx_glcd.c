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
/********************************************************************************
  GFX GLCD Driver Functions for Static Single Instance Driver

  Company:
    Microchip Technology Inc.

  File Name:
    drv_gfx_glcd.c.ftl

  Summary:
    Source code for the GFX GLCD driver static implementation.

  Description:
    This file contains the source code for the static implementation of the
    GFX GLCD driver.
*******************************************************************************/






// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "peripheral/evic/plib_evic.h"
#include "gfx/driver/gfx_driver.h"
#include "gfx/driver/controller/glcd/plib_glcd.h"
#include "gfx/driver/controller/glcd/drv_gfx_glcd.h"
#include "definitions.h"
#include "gfx/driver/processor/2dgpu/libnano2d.h"
// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************

#define BUFFER_PER_LAYER    1

#define DISPLAY_WIDTH  432
#define DISPLAY_HEIGHT 432
#define GFX_GLCD_LAYERS 1
#define GFX_GLCD_BACKGROUND_COLOR 0xFFFFFF00
#define GFX_GLCD_CONFIG_CONTROL 0x80000000
#define GFX_GLCD_CONFIG_CLK_DIVIDER 10
#define GFX_GLCD_GLOBAL_PALETTE_COLOR_COUNT 256

#define SYNC_RECT_COUNT 200

/*** GLCD Layer 0 Configuration ***/
#define  GFX_GLCD_LAYER0_BASEADDR                      0xA8000000
#define  GFX_GLCD_LAYER0_DBL_BASEADDR                  0xA8465000

#define LCDC_DEFAULT_GFX_COLOR_MODE GLCD_LAYER_COLOR_MODE_RGBA8888
#define FRAMEBUFFER_PTR_TYPE    uint32_t*
#define FRAMEBUFFER_PIXEL_TYPE    uint32_t

typedef enum
{
    LAYER_UNLOCKED,
    LAYER_LOCKED,
    LAYER_LOCKED_PENDING,
} LAYER_LOCK_STATUS;

/**** Hardware Abstraction Interfaces ****/
typedef enum
{
    INIT = 0,
    DRAW,
    SWAP,
    SYNC,
} DRV_STATE;

const char* DRIVER_NAME = "GLCD";
//static uint32_t supported_color_format = (GFX_COLOR_MASK_GS_8 |
//                                          GFX_COLOR_MASK_RGB_565 |
//                                          GFX_COLOR_MASK_RGBA_8888);


static volatile DRV_STATE state;
static gfxRect srcRect, destRect;
static unsigned int vsyncCount = 0;
static unsigned int activeLayer = 0;
static bool vblankSync = true;

volatile int32_t waitForAlphaSetting[GFX_GLCD_LAYERS] = {0};

//Layer Parameters
//--------------------------------------------------------------------------
typedef struct __display_layer {
    FRAMEBUFFER_PTR_TYPE  baseaddr[BUFFER_PER_LAYER];
    int        draw;
    int        frame;
    uint32_t   resx;
    uint32_t   resy;
    uint32_t   buscfg;
    uint32_t   format;
    uint32_t   stride;
    uint32_t   startx;
    uint32_t   starty;
    uint32_t   sizex;
    uint32_t   sizey;
    uint32_t   alpha;
    uint32_t   dblend;
    uint32_t   sblend;
    uint32_t   colorspace;
    uint16_t   color;
    bool enabled;
    volatile LAYER_LOCK_STATUS updateLock;
    gfxPixelBuffer pixelBuffer[BUFFER_PER_LAYER];
    volatile unsigned int frontBufferIdx;
    volatile unsigned int backBufferIdx;
} DISPLAY_LAYER;
static DISPLAY_LAYER drvLayer[GFX_GLCD_LAYERS];

static gfxResult DRV_GLCD_UpdateLayer(unsigned int layer);

static gfxResult DRV_GLCD_BufferBlit(const gfxPixelBuffer* source,
                            const gfxRect* rectSrc,
                            const gfxPixelBuffer* dest,
                            const gfxRect* rectDest)
{
    void* srcPtr;
    void* destPtr;
    uint32_t row, rowSize;
    unsigned int width, height;
    gfxResult res;
	
	res = gfxGPUInterface.blitBuffer(source,
                                     rectSrc,
                                     dest,
                                     rectDest);
    if (res != GFX_SUCCESS)
    {
        width = (rectSrc->width < rectDest->width) ? 
                 rectSrc->width : rectDest->width;
        height = (rectSrc->height < rectDest->height) ? 
                 rectSrc->height : rectDest->height;
        rowSize = width * gfxColorInfoTable[dest->mode].size;

        for(row = 0; row < height; row++)
        {
            srcPtr = gfxPixelBufferOffsetGet(source, rectSrc->x, rectSrc->y + row);
            destPtr = gfxPixelBufferOffsetGet(dest, rectDest->x, rectDest->y + row);

            memcpy(destPtr, srcPtr, rowSize);
        }        
    }

    return GFX_SUCCESS;
}

void DRV_GLCD_Update()
{
    switch(state)
    {
        case INIT:
        {
            state = DRAW;
            break;
        }
        case DRAW:
        case SWAP:
        default:
            break;
    }
}

static uint32_t getColorModeStrideSize(GLCD_LAYER_COLOR_MODE mode)
{
    switch(mode)
    {
        case GLCD_LAYER_COLOR_MODE_LUT8:
            return sizeof(uint8_t);
            break;
        case GLCD_LAYER_COLOR_MODE_RGB332:
            return sizeof(uint8_t);
            break;
        case GLCD_LAYER_COLOR_MODE_RGB565:
            return sizeof(uint16_t);
            break;
        case GLCD_LAYER_COLOR_MODE_RGB888:
            return sizeof(uint32_t);
            break;
        case GLCD_LAYER_COLOR_MODE_RGBA8888:
            return sizeof(uint32_t);
            break;
        case GLCD_LAYER_COLOR_MODE_ARGB8888:
            return sizeof(uint32_t);
            break;
        case GLCD_LAYER_COLOR_MODE_L1:
            return sizeof(uint8_t);
            break;
        case GLCD_LAYER_COLOR_MODE_L4:
            return sizeof(uint8_t);
            break;
        case GLCD_LAYER_COLOR_MODE_L8:
            return sizeof(uint8_t);
            break;
        default:
            return sizeof(uint32_t);
            break;
    }
}

static GLCD_LAYER_COLOR_MODE getGLCDColorModeFromGFXColorMode(gfxColorMode mode)
{
    switch(mode)
    {
        case GFX_COLOR_MODE_GS_8:
            return GLCD_LAYER_COLOR_MODE_LUT8;
        case GFX_COLOR_MODE_RGB_332:
            return GLCD_LAYER_COLOR_MODE_RGB332;
        case GFX_COLOR_MODE_RGB_565:
            return GLCD_LAYER_COLOR_MODE_RGB565;
        case GFX_COLOR_MODE_RGBA_5551:
            return GLCD_LAYER_COLOR_MODE_RGBA5551;
        case GFX_COLOR_MODE_RGB_888:
            return GLCD_LAYER_COLOR_MODE_RGB888;
        case GFX_COLOR_MODE_ARGB_8888:
            return GLCD_LAYER_COLOR_MODE_ARGB8888;
        case GFX_COLOR_MODE_INDEX_1:
            return GLCD_LAYER_COLOR_MODE_L1;
        case GFX_COLOR_MODE_INDEX_4:
            return GLCD_LAYER_COLOR_MODE_L4;
        case GFX_COLOR_MODE_INDEX_8:
            return GLCD_LAYER_COLOR_MODE_L8;
        case GFX_COLOR_MODE_RGBA_8888:
        default:
            return GLCD_LAYER_COLOR_MODE_RGBA8888;
    }
}

static gfxColorMode getGFXColorModeFromGLCD(GLCD_LAYER_COLOR_MODE mode)
{
    switch(mode)
    {
        case GLCD_LAYER_COLOR_MODE_LUT8:
            return GFX_COLOR_MODE_GS_8;
        case GLCD_LAYER_COLOR_MODE_RGB332:
            return GFX_COLOR_MODE_RGB_332;
        case GLCD_LAYER_COLOR_MODE_RGB565:
            return GFX_COLOR_MODE_RGB_565;
        case GLCD_LAYER_COLOR_MODE_RGBA5551:
            return GFX_COLOR_MODE_RGBA_5551;
        case GLCD_LAYER_COLOR_MODE_RGB888:
            return GFX_COLOR_MODE_RGB_888;
        case GLCD_LAYER_COLOR_MODE_ARGB8888:
            return GFX_COLOR_MODE_ARGB_8888;
        case GLCD_LAYER_COLOR_MODE_L1:
            return GFX_COLOR_MODE_INDEX_1;
        case GLCD_LAYER_COLOR_MODE_L4:
            return GFX_COLOR_MODE_INDEX_4;
        case GLCD_LAYER_COLOR_MODE_L8:
            return GFX_COLOR_MODE_INDEX_8;
        default:
            return GFX_COLOR_MODE_RGBA_8888;
    }
}

void DRV_GLCD_Initialize()
{
    uint32_t      xResolution;
    uint32_t      yResolution;
    uint32_t      rightMargin;
    uint32_t      lowerMargin;
    uint32_t      hsyncLength;
    uint32_t      vsyncLength;
    uint32_t      leftMargin;
    uint32_t      upperMargin;
    uint32_t      stride;
    uint32_t      layerCount;
    uint32_t      bufferCount;

    /* set temporary information */
    xResolution     = 432;
    yResolution     = 432;
    rightMargin     = 5;
    leftMargin      = 5;
    hsyncLength     = 5;
    vsyncLength     = 5;
    upperMargin     = 5;
    lowerMargin     = 5;


    /* glcd initialization */
    PLIB_GLCD_Disable();
    PLIB_GLCD_BackgroundColorSet(GFX_GLCD_BACKGROUND_COLOR);
    PLIB_GLCD_VSyncInterruptDisable();
    PLIB_GLCD_HSyncInterruptDisable();
    PLIB_GLCD_RGBSequentialModeSet(1<<31);

    PLIB_GLCD_FrontPorchXYSet(xResolution + rightMargin, yResolution + lowerMargin);
    PLIB_GLCD_BlankingXYSet(xResolution + rightMargin + hsyncLength, yResolution + lowerMargin + vsyncLength);
    PLIB_GLCD_BackPorchXYSet(xResolution + rightMargin + hsyncLength + leftMargin, yResolution + lowerMargin + vsyncLength + upperMargin);

    PLIB_GLCD_ClockDividerSet(GFX_GLCD_CONFIG_CLK_DIVIDER);
    PLIB_GLCD_ResolutionXYSet(xResolution, yResolution);

    PLIB_GLCD_SignalPolaritySet( GLCD_VSYNC_POLARITY_NEGATIVE | GLCD_HSYNC_POLARITY_NEGATIVE );

    PLIB_GLCD_PaletteGammaRampDisable();

    PLIB_GLCD_Enable();

    drvLayer[0].baseaddr[0] = (FRAMEBUFFER_PTR_TYPE)GFX_GLCD_LAYER0_BASEADDR;

    for (layerCount = 0; layerCount < GFX_GLCD_LAYERS; layerCount++)
    {
        drvLayer[layerCount].resx       = xResolution;
        drvLayer[layerCount].resy       = yResolution;
        drvLayer[layerCount].startx     = 0;
        drvLayer[layerCount].starty     = 0;
        drvLayer[layerCount].sizex      = drvLayer[layerCount].resx;
        drvLayer[layerCount].sizey      = drvLayer[layerCount].resy;
        drvLayer[layerCount].alpha      = 255;
        drvLayer[layerCount].dblend     = GLCD_LAYER_DEST_BLEND_INV_SRCGBL;
        drvLayer[layerCount].sblend     = GLCD_LAYER_SRC_BLEND_ALPHA_SRCGBL;
        drvLayer[layerCount].colorspace = LCDC_DEFAULT_GFX_COLOR_MODE;
        drvLayer[layerCount].enabled    = true;
        drvLayer[layerCount].updateLock = LAYER_LOCKED;
        //Clear frame buffer
        for(bufferCount = 0; bufferCount < BUFFER_PER_LAYER; ++bufferCount)
        {
            memset(drvLayer[layerCount].baseaddr[bufferCount], 0, sizeof(FRAMEBUFFER_PIXEL_TYPE) * DISPLAY_WIDTH * DISPLAY_HEIGHT);
        }
        stride = getColorModeStrideSize(drvLayer[layerCount].colorspace);

        PLIB_GLCD_LayerBaseAddressSet(layerCount, (uint32_t)drvLayer[layerCount].baseaddr[0]);
        PLIB_GLCD_LayerStrideSet(layerCount, drvLayer[layerCount].resx * stride );
        PLIB_GLCD_LayerResXYSet(layerCount, drvLayer[layerCount].resx, drvLayer[layerCount].resy );
        PLIB_GLCD_LayerStartXYSet(layerCount, drvLayer[layerCount].startx, drvLayer[layerCount].starty );
        PLIB_GLCD_LayerSizeXYSet(layerCount, drvLayer[layerCount].sizex, drvLayer[layerCount].sizey);
        PLIB_GLCD_LayerGlobalAlphaSet(layerCount, drvLayer[layerCount].alpha);
        PLIB_GLCD_LayerDestBlendFuncSet(layerCount, drvLayer[layerCount].dblend );
        PLIB_GLCD_LayerSrcBlendFuncSet(layerCount, drvLayer[layerCount].sblend );
        PLIB_GLCD_LayerColorModeSet(layerCount, drvLayer[layerCount].colorspace );

        PLIB_GLCD_LayerEnable(layerCount);

        drvLayer[layerCount].frontBufferIdx = 0;
        drvLayer[layerCount].backBufferIdx = 0;
        drvLayer[layerCount].updateLock = LAYER_UNLOCKED;

        gfxPixelBufferCreate(xResolution,
                             yResolution,
                             getGFXColorModeFromGLCD(LCDC_DEFAULT_GFX_COLOR_MODE),
                             drvLayer[layerCount].baseaddr[0],
                             &drvLayer[layerCount].pixelBuffer[drvLayer[layerCount].frontBufferIdx]);


    }

    EVIC_SourceStatusClear(INT_SOURCE_GLCD);
    EVIC_SourceEnable(INT_SOURCE_GLCD);

}



void GLCD_Interrupt_Handler(void)
{
    unsigned int i = 0;
    
    EVIC_SourceStatusClear(INT_SOURCE_GLCD);
	
    //Sync on vblank?
    if (vblankSync && PLIB_GLCD_IsVerticalBlankingActive() == true)
        return;    	

    PLIB_GLCD_VSyncInterruptDisable();

    
    //Update GLCD during blanking period
    for (i = 0; i < GFX_GLCD_LAYERS; i++)
    {

        if (drvLayer[i].updateLock == LAYER_LOCKED_PENDING)
        {
            DRV_GLCD_UpdateLayer(i);
            drvLayer[i].updateLock = LAYER_UNLOCKED;
        }
    }

}

/**** End Hardware Abstraction Interfaces ****/

gfxResult DRV_GLCD_BlitBuffer(int32_t x,
                             int32_t y,
                             gfxPixelBuffer* buf)
{
    if (state != DRAW)
        return GFX_FAILURE;
		
    gfxPixelBuffer_SetLocked(buf, GFX_TRUE);		


    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.height = buf->size.height;
    srcRect.width = buf->size.width;

    destRect.x = x;
    destRect.y = y;
    destRect.height = buf->size.height;
    destRect.width = buf->size.width;

   	DRV_GLCD_BufferBlit(buf, &srcRect, &drvLayer[activeLayer].pixelBuffer[drvLayer[activeLayer].backBufferIdx], &destRect);
	
	gfxPixelBuffer_SetLocked(buf, GFX_FALSE);

    return GFX_SUCCESS;
}

static gfxResult DRV_GLCD_UpdateLayer(unsigned int layer)
{
    PLIB_GLCD_LayerStrideSet(layer,
                             drvLayer[layer].resx *
                             getColorModeStrideSize(drvLayer[layer].colorspace));
        
    PLIB_GLCD_LayerBaseAddressSet(layer,
                                 (uint32_t)drvLayer[layer].baseaddr[0]);
                
    PLIB_GLCD_LayerStartXYSet(layer,
                              drvLayer[layer].startx,
                              drvLayer[layer].starty );
        
        //Set layer size
    PLIB_GLCD_LayerSizeXYSet(layer,
                             drvLayer[layer].sizex,
                             drvLayer[layer].sizey);
            
    PLIB_GLCD_LayerResXYSet(layer,
                            drvLayer[layer].sizex,
                            drvLayer[layer].sizey);
            
    PLIB_GLCD_LayerGlobalAlphaSet(layer,
                            drvLayer[layer].alpha);
        
    PLIB_GLCD_LayerColorModeSet(layer,
                            drvLayer[layer].colorspace);   
    
    if (drvLayer[layer].enabled == true)
        PLIB_GLCD_LayerEnable(layer);
    else
        PLIB_GLCD_LayerDisable(layer);
    
    return GFX_SUCCESS;
}

static gfxDriverIOCTLResponse DRV_GLCD_LayerConfig(gfxDriverIOCTLRequest request,
                                                   gfxIOCTLArg_LayerArg* arg)
{
    gfxIOCTLArg_LayerValue* val;
    gfxIOCTLArg_LayerPosition* pos;
    gfxIOCTLArg_LayerSize* sz;
    
    // make sure layer is locked before accepting changes
    if(arg->id >= GFX_GLCD_LAYERS)
        return GFX_IOCTL_ERROR_UNKNOWN;
    
    // attempt to lock
    if(request == GFX_IOCTL_SET_LAYER_LOCK)
    {
        PLIB_GLCD_VSyncInterruptDisable();
        
        drvLayer[arg->id].updateLock = LAYER_LOCKED;
        
        return GFX_IOCTL_OK;
    }
    
    // layer should be locked 
    if(drvLayer[arg->id].updateLock != LAYER_LOCKED)
        return GFX_IOCTL_ERROR_UNKNOWN;
    
    if(request == GFX_IOCTL_SET_LAYER_UNLOCK)
    {
        drvLayer[arg->id].updateLock = LAYER_LOCKED_PENDING;
        
        PLIB_GLCD_VSyncInterruptEnable();
        
        return GFX_IOCTL_OK;
    }
    
    switch(request)
    {
        case GFX_IOCTL_SET_LAYER_ALPHA:
        {
            val = (gfxIOCTLArg_LayerValue*)arg;
            
            drvLayer[arg->id].alpha = val->value.v_uint;
            
            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_SET_LAYER_SIZE:
        {
            sz = (gfxIOCTLArg_LayerSize*)arg;
            
            drvLayer[arg->id].resx = sz->width;
            drvLayer[arg->id].resy = sz->height;
            
            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_SET_LAYER_POSITION:
        {
            pos = (gfxIOCTLArg_LayerPosition*)arg;
            
            drvLayer[arg->id].startx = pos->x;
            drvLayer[arg->id].starty = pos->y;
            
            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_SET_LAYER_WINDOW_SIZE:
        {
            sz = (gfxIOCTLArg_LayerSize*)arg;
            
            drvLayer[arg->id].sizex = sz->width;
            drvLayer[arg->id].sizey = sz->height;
            
            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_SET_LAYER_BASE_ADDRESS:
        {
            val = (gfxIOCTLArg_LayerValue*)arg;
            
            drvLayer[arg->id].baseaddr[0] = val->value.v_pointer;
            
            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_SET_LAYER_COLOR_MODE:
        {
            val = (gfxIOCTLArg_LayerValue*)arg;
            
            drvLayer[arg->id].colorspace = getGLCDColorModeFromGFXColorMode(val->value.v_colormode);
            
            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_GET_LAYER_ENABLED:
        {
            val = (gfxIOCTLArg_LayerValue*)arg;
            
            val->value.v_bool = drvLayer[arg->id].enabled;
            
            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_SET_LAYER_ENABLED:
        {
            val = (gfxIOCTLArg_LayerValue*)arg;
            
            drvLayer[arg->id].enabled = val->value.v_bool;
            
            return GFX_IOCTL_OK;
        }
        default:
            break;
    }
    
    return GFX_IOCTL_UNSUPPORTED;
}

gfxDriverIOCTLResponse DRV_GLCD_SetPalette(gfxIOCTLArg_Palette* pal)
{
    return GFX_IOCTL_UNSUPPORTED;
}

gfxDriverIOCTLResponse DRV_GLCD_IOCTL(gfxDriverIOCTLRequest request,
                                      void* arg)
{
    gfxIOCTLArg_Value* val;
    gfxIOCTLArg_DisplaySize* disp;
    gfxIOCTLArg_LayerRect* rect;
    
    switch(request)
    {
        case GFX_IOCTL_LAYER_SWAP:
        {
            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_FRAME_END:
        {
            
            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_GET_BUFFER_COUNT:
        {
            val = (gfxIOCTLArg_Value*)arg;
            
            val->value.v_uint = BUFFER_PER_LAYER;
            
            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_GET_DISPLAY_SIZE:
        {
            disp = (gfxIOCTLArg_DisplaySize*)arg;            
            
            disp->width = DISPLAY_WIDTH;
            disp->height = DISPLAY_HEIGHT;
            
            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_GET_LAYER_COUNT:
        {
            val = (gfxIOCTLArg_Value*)arg;
            
            val->value.v_uint = GFX_GLCD_LAYERS;
            
            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_GET_ACTIVE_LAYER:
        {
            val = (gfxIOCTLArg_Value*)arg;
            
            val->value.v_uint = activeLayer;
            
            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_SET_ACTIVE_LAYER:
        {
            val = (gfxIOCTLArg_Value*)arg;
            
            if(val->value.v_uint >= GFX_GLCD_LAYERS)
            {
                return GFX_IOCTL_ERROR_UNKNOWN;
            }
            else
            {
                activeLayer = val->value.v_uint;
                
                return GFX_IOCTL_OK;
            }
        }
        case GFX_IOCTL_GET_LAYER_RECT:
        {
            rect = (gfxIOCTLArg_LayerRect*)arg;
            
            if(rect->base.id >= GFX_GLCD_LAYERS)        
                return GFX_IOCTL_ERROR_UNKNOWN;
            
            rect->x = drvLayer[rect->base.id].startx;
            rect->y = drvLayer[rect->base.id].starty;
            rect->width = drvLayer[rect->base.id].sizex;
            rect->height = drvLayer[rect->base.id].sizey;
            
            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_GET_VSYNC_COUNT:
        {
            val = (gfxIOCTLArg_Value*)arg;
            
            val->value.v_uint = vsyncCount;
            
            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_GET_FRAMEBUFFER:
        {
            val = (gfxIOCTLArg_Value*)arg;
            
            val->value.v_pbuffer = &drvLayer[activeLayer].pixelBuffer[drvLayer[activeLayer].frontBufferIdx];

            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_SET_PALETTE:
        {
            return DRV_GLCD_SetPalette((gfxIOCTLArg_Palette*)arg);
        }
        case GFX_IOCTL_SET_VBLANK_SYNC:
        {
            vblankSync = ((gfxIOCTLArg_Value*)arg)->value.v_bool;
            
            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_GET_STATUS:
        {
            unsigned int i;
            val = (gfxIOCTLArg_Value*)arg;
            
            val->value.v_uint = 0;
            
            for (i = 0; i < GFX_GLCD_LAYERS; i++)
            {
                if (drvLayer[i].updateLock != LAYER_UNLOCKED)
                {
                    val->value.v_uint = 1;

                    break;
                }
            }

            return GFX_IOCTL_OK;
        }		
        default:
        {
            if (request >= GFX_IOCTL_LAYER_REQ_START && 
                request <= GFX_IOCTL_LAYER_REQ_END)
            {
                return DRV_GLCD_LayerConfig(request, (gfxIOCTLArg_LayerArg*)arg);
            }
        }
    }
    
    return GFX_IOCTL_UNSUPPORTED;
}

/*******************************************************************************
 End of File
*/
