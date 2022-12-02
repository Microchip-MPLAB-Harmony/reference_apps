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

/*******************************************************************************
  MPLAB Harmony LCC Generated Driver Implementation File

  File Name:
    drv_gfx_lcc_generic.c

  Summary:
    Build-time generated implementation for the LCC Driver for PIC32C MCUs.

  Description:
    Build-time generated implementation for the LCC Driver for PIC32C MCUs.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/



#include "gfx/driver/controller/lcc/drv_gfx_lcc.h"
#include "definitions.h"

#include <string.h>

#define MAX_LAYER_COUNT 1
#define BUFFER_COUNT    1
#define DISPLAY_WIDTH   480
#define DISPLAY_HEIGHT  272

#define EBI_CS_INDEX  0


#define EBI_BASE_ADDR __KSEG2_EBI_DATA_MEM_BASE

#define DRV_GFX_LCC_DMA_CHANNEL_INDEX DMAC_CHANNEL_4
#define DRV_GFX_DMA_EVENT_TYPE DMAC_TRANSFER_EVENT

#define FRAMEBUFFER_COLOR_MODE GFX_COLOR_MODE_RGB_565
#define FRAMEBUFFER_TYPE uint16_t
#define FRAMEBUFFER_PIXEL_BYTES 2

#define FRAMEBUFFER_ATTRIBUTE __attribute__((coherent, aligned(FRAMEBUFFER_PIXEL_BYTES*8)))
FRAMEBUFFER_TYPE FRAMEBUFFER_ATTRIBUTE frameBuffer[BUFFER_COUNT][DISPLAY_WIDTH * DISPLAY_HEIGHT];

#ifndef GFX_DISP_INTF_PIN_RESET_Set
#error "GFX_DISP_INTF_PIN_RESET GPIO must be defined in the Pin Settings"
#endif


#ifndef GFX_DISP_INTF_PIN_BACKLIGHT_Set
#warning "GFX_DISP_INTF_PIN_BACKLIGHT GPIO must be defined in the Pin Settings"
#define GFX_DISP_INTF_PIN_BACKLIGHT_Set()
#endif

#ifndef GFX_DISP_INTF_PIN_VSYNC_Set
#error "GFX_DISP_INTF_PIN_VSYNC GPIO must be defined in the Pin Settings"
#endif

#ifndef GFX_DISP_INTF_PIN_DE_Set
#error "GFX_DISP_INTF_PIN_DE GPIO must be defined in the Pin Settings"
#endif

#ifndef GFX_DISP_INTF_PIN_HSYNC_Set
#error "GFX_DISP_INTF_PIN_HSYNC GPIO must be defined in the Pin Settings"
#endif

/**** Hardware Abstraction Interfaces ****/
enum
{
    INIT = 0,
    RUN
};


static int start(void);
static void displayRefresh(void);
static gfxResult lccBacklightBrightnessSet(uint32_t brightness);
void dmaIntHandler (DRV_GFX_DMA_EVENT_TYPE status,
                    uintptr_t contextHandle);

uint16_t HBackPorch;
uint32_t VER_BLANK;

uint32_t DISP_HOR_FRONT_PORCH = 2;
uint32_t DISP_HOR_RESOLUTION = DISPLAY_WIDTH;
uint32_t DISP_HOR_BACK_PORCH = 2;
uint32_t DISP_HOR_PULSE_WIDTH = 41;

uint32_t DISP_VER_FRONT_PORCH = 2;
uint32_t DISP_VER_RESOLUTION = DISPLAY_HEIGHT;
uint32_t DISP_VER_BACK_PORCH = 2;
uint32_t DISP_VER_PULSE_WIDTH = 10;

int16_t line = 0;
uint32_t offset = 0;
uint16_t pixels = 0;
uint32_t hSyncs = 0;
    
uint32_t vsyncPeriod = 0;
uint32_t vsyncPulseDown = 0;
uint32_t vsyncPulseUp = 0;
uint32_t vsyncEnd = 0;

unsigned int vsyncCount = 0;

static uint32_t state;

gfxPixelBuffer pixelBuffer;



gfxResult DRV_LCC_Initialize(void)
{
    state = INIT;

    gfxPixelBufferCreate(DISP_HOR_RESOLUTION,
                        DISP_VER_RESOLUTION,
                        FRAMEBUFFER_COLOR_MODE,
                        frameBuffer,
                        &pixelBuffer);
    
    // driver specific initialization tasks    
    VER_BLANK = DISP_VER_PULSE_WIDTH +
                DISP_VER_BACK_PORCH +
                DISP_VER_FRONT_PORCH - 1;
    
    HBackPorch = DISP_HOR_PULSE_WIDTH +
                 DISP_HOR_BACK_PORCH;
    
    vsyncPeriod = DISP_VER_FRONT_PORCH + DISP_VER_RESOLUTION + DISP_VER_BACK_PORCH;  

    GFX_DISP_INTF_PIN_RESET_Set();

    /*Turn Backlight on*/

    lccBacklightBrightnessSet(100);

    return GFX_SUCCESS;
}

void DRV_LCC_Update(void)
{
    if(state == INIT)
    {
        if(start() != 0)
            return;
        
        memset(frameBuffer, 0x55, DISPLAY_WIDTH * DISPLAY_HEIGHT * FRAMEBUFFER_PIXEL_BYTES);
        
        state = RUN;
    }
}


gfxResult DRV_LCC_BlitBuffer(int32_t x,
                             int32_t y,
                             gfxPixelBuffer* buf)
{
    if (state != RUN)
        return GFX_FAILURE;
    else
    {
        void* srcPtr;
        void* destPtr;
        uint32_t row, rowSize;
    
        rowSize = buf->size.width * gfxColorInfoTable[buf->mode].size;
        
        for(row = 0; row < buf->size.height; row++)
        {
            srcPtr = gfxPixelBufferOffsetGet(buf, 0, row);
            destPtr = gfxPixelBufferOffsetGet(&pixelBuffer, x, y + row);
            
            memcpy(destPtr, srcPtr, rowSize);
        }

        return GFX_SUCCESS;
    }

    return GFX_FAILURE;
}


gfxDriverIOCTLResponse DRV_LCC_IOCTL(gfxDriverIOCTLRequest request,
                                     void* arg)
{
	gfxIOCTLArg_Value* val;
	gfxIOCTLArg_DisplaySize* disp;
	gfxIOCTLArg_LayerRect* rect;
	
	switch(request)
	{
		case GFX_IOCTL_GET_COLOR_MODE:
		{
			val = (gfxIOCTLArg_Value*)arg;
			
			val->value.v_colormode = FRAMEBUFFER_COLOR_MODE;
			
			return GFX_IOCTL_OK;
		}
		case GFX_IOCTL_GET_BUFFER_COUNT:
		{
			val = (gfxIOCTLArg_Value*)arg;
			
			val->value.v_uint = 1;
			
			return GFX_IOCTL_OK;
		}
		case GFX_IOCTL_GET_DISPLAY_SIZE:
		{
			disp = (gfxIOCTLArg_DisplaySize*)arg;			
			
			disp->width = DISP_HOR_RESOLUTION;
			disp->height = DISP_VER_RESOLUTION;
			
			return GFX_IOCTL_OK;
		}
		case GFX_IOCTL_GET_LAYER_COUNT:
		{
			val = (gfxIOCTLArg_Value*)arg;
			
			val->value.v_uint = 1;
			
			return GFX_IOCTL_OK;
		}
		case GFX_IOCTL_GET_ACTIVE_LAYER:
		{
			val = (gfxIOCTLArg_Value*)arg;
			
			val->value.v_uint = 0;
			
			return GFX_IOCTL_OK;
		}
		case GFX_IOCTL_GET_LAYER_RECT:
		{
			rect = (gfxIOCTLArg_LayerRect*)arg;
			
			rect->base.id = 0;
			rect->x = 0;
			rect->y = 0;
			rect->width = DISPLAY_WIDTH;
			rect->height = DISPLAY_HEIGHT;
			
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
			
			val->value.v_pbuffer = &pixelBuffer;
			
			return GFX_IOCTL_OK;
		}
		default:
		{ }
	}
	
	return GFX_IOCTL_UNSUPPORTED;
}

static gfxResult lccBacklightBrightnessSet(uint32_t brightness)
{
    if (brightness == 0)
    {
        GFX_DISP_INTF_PIN_BACKLIGHT_Clear();
    }
    else
    {
        GFX_DISP_INTF_PIN_BACKLIGHT_Set();
    }

    return GFX_SUCCESS;

}


/**** End Hardware Abstraction Interfaces ****/

static void lccDMAStartTransfer(const void *srcAddr, size_t srcSize,
                                       const void *destAddr)
{
    DMAC_ChannelTransfer(DRV_GFX_LCC_DMA_CHANNEL_INDEX,
                         srcAddr,
                         srcSize,
                         destAddr,
                         FRAMEBUFFER_PIXEL_BYTES,
                         srcSize);
}

static int start(void)
{
    DMAC_ChannelCallbackRegister(DRV_GFX_LCC_DMA_CHANNEL_INDEX, dmaIntHandler, 0);

    lccDMAStartTransfer(frameBuffer, 
                        FRAMEBUFFER_PIXEL_BYTES, 
                        (const void*) EBI_BASE_ADDR);

    return 0;
}

static void displayRefresh(void)
{
    gfxPoint drawPoint;
    gfxBuffer* buffer_to_tx = (void*) frameBuffer;

    typedef enum
    {
        HSYNC_FRONT_PORCH,
        HSYNC_PULSE,
        HSYNC_BACK_PORCH,
        HSYNC_DATA_ENABLE,
        HSYNC_DATA_ENABLE_OVERFLOW        
    } HSYNC_STATES;

    typedef enum
    {
        VSYNC_FRONT_PORCH,
        VSYNC_PULSE,
        VSYNC_BACK_PORCH,
        VSYNC_BLANK        
    } VSYNC_STATES;

    static HSYNC_STATES hsyncState = HSYNC_FRONT_PORCH;
    static VSYNC_STATES vsyncState = VSYNC_BLANK;

    switch(vsyncState)
    {
        case VSYNC_FRONT_PORCH:
        {
            if (hSyncs > vsyncPulseDown)
            {
                GFX_DISP_INTF_PIN_VSYNC_Set();

                vsyncPulseUp = hSyncs + DISP_VER_PULSE_WIDTH;
                vsyncState = VSYNC_PULSE;

                line = 0;
            }
            
            break;
        }
        case VSYNC_PULSE:
        {
            if (hSyncs >= vsyncPulseUp)
            {
                GFX_DISP_INTF_PIN_VSYNC_Clear();
                vsyncEnd = hSyncs + DISP_VER_BACK_PORCH;
                vsyncState = VSYNC_BACK_PORCH;

                vsyncCount++;                
            }
            
            break;
        }
        case VSYNC_BACK_PORCH:
        {
            if (hSyncs >= vsyncEnd)
                vsyncState = VSYNC_BLANK;
            
            break;
        }
        case VSYNC_BLANK:
        {
            break;
        }
    }

    switch (hsyncState)
    {
        case HSYNC_FRONT_PORCH:
        {
            GFX_DISP_INTF_PIN_DE_Clear();

            hsyncState = HSYNC_PULSE;

            if (DISP_HOR_FRONT_PORCH > 0)
            {
                pixels = DISP_HOR_FRONT_PORCH;
                break;
            }
        }
        case HSYNC_PULSE:
        {
            GFX_DISP_INTF_PIN_HSYNC_Set();

            if (hSyncs >= vsyncPeriod)
            {
                vsyncPeriod = hSyncs + DISP_VER_PULSE_WIDTH + DISP_VER_FRONT_PORCH + DISP_VER_RESOLUTION + DISP_VER_BACK_PORCH;
                vsyncPulseDown = hSyncs + DISP_VER_FRONT_PORCH;
                vsyncState = VSYNC_FRONT_PORCH;
            }

            hSyncs++; 

            pixels = DISP_HOR_PULSE_WIDTH;
            hsyncState = HSYNC_BACK_PORCH;  

            break;
        }
        case HSYNC_BACK_PORCH:
        {
            GFX_DISP_INTF_PIN_HSYNC_Clear();

            hsyncState = HSYNC_DATA_ENABLE; 

            if (DISP_HOR_BACK_PORCH > 0)
            {
                pixels = DISP_HOR_BACK_PORCH;
                break;
            }
        }
        case HSYNC_DATA_ENABLE:
        {
            if (vsyncState == VSYNC_BLANK)
            {
                GFX_DISP_INTF_PIN_DE_Set();
                drawPoint.x = 0;
                drawPoint.y = line++;

                buffer_to_tx = gfxPixelBufferOffsetGet_Unsafe(&pixelBuffer, drawPoint.x, drawPoint.y);
            }

            pixels = DISP_HOR_RESOLUTION;
            hsyncState = HSYNC_FRONT_PORCH;

            break;
        }
        case HSYNC_DATA_ENABLE_OVERFLOW:
        {
            hsyncState = HSYNC_FRONT_PORCH;
            
            break;
        }
    }

    lccDMAStartTransfer(buffer_to_tx,
                        (pixels << 1), //2 bytes per pixel
                        (uint32_t*) EBI_BASE_ADDR);
}

void dmaIntHandler (DRV_GFX_DMA_EVENT_TYPE status,
                    uintptr_t contextHandle)
{
    displayRefresh();
}


