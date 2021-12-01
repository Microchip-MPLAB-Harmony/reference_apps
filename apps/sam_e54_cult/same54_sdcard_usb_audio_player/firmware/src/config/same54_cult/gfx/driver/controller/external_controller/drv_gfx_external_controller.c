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

/*******************************************************************************
  Custom ILI9488Display Top-Level Driver Source File

  File Name:
    drv_gfx_custom_external.c

  Summary:
    Top level driver for ILI9488.

  Description:
    Build-time generated implementation for the ILI9488Driver.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/




#include "definitions.h"

#include "gfx/interface/drv_gfx_disp_intf.h"
#include "drv_gfx_external_controller.h"

#include "system/time/sys_time.h"

// Default max width/height of ILI9488frame
#define DISPLAY_DEFAULT_WIDTH   480
#define DISPLAY_DEFAULT_HEIGHT  800

#define DISPLAY_WIDTH   480
#define DISPLAY_HEIGHT  320

#define PIXEL_BUFFER_COLOR_MODE GFX_COLOR_MODE_RGB_565
#define SCREEN_WIDTH DISPLAY_WIDTH
#define SCREEN_HEIGHT DISPLAY_HEIGHT

#ifdef GFX_DISP_INTF_PIN_RESET_Clear
#define DRV_ILI9488_Reset_Assert()      GFX_DISP_INTF_PIN_RESET_Clear()
#define DRV_ILI9488_Reset_Deassert()    GFX_DISP_INTF_PIN_RESET_Set()
#else
#error "ERROR: GFX_DISP_INTF_PIN_RESET not defined. Please define in Pin Manager."
#define DRV_ILI9488_Reset_Assert()
#define DRV_ILI9488_Reset_Deassert()
#endif

#define DRV_ILI9488_NCSAssert(intf)   GFX_Disp_Intf_PinControl(intf, \
                                    GFX_DISP_INTF_PIN_CS, \
                                    GFX_DISP_INTF_PIN_CLEAR)

#define DRV_ILI9488_NCSDeassert(intf) GFX_Disp_Intf_PinControl(intf, \
                                    GFX_DISP_INTF_PIN_CS, \
                                    GFX_DISP_INTF_PIN_SET)
									

									
#define PIXEL_BUFFER_BYTES_PER_PIXEL 2
static uint8_t pixelBuffer[SCREEN_WIDTH * PIXEL_BUFFER_BYTES_PER_PIXEL];

typedef enum
{
    INIT = 0,
    RUN,
    ERROR,
} DRV_STATE;

typedef struct ILI9488_DRV 
{   
    /* Driver state */
    DRV_STATE state;
        
    /* Port-specific private data */
    void *port_priv;
} ILI9488_DRV;

ILI9488_DRV drv;

static uint32_t swapCount = 0;


/* ************************************************************************** */

/**
  Function:
    static void DRV_ILI9488_DelayMS(int ms)

  Summary:
    Delay helper function.

  Description:
    This is a helper function for delay using the system tick timer.

  Parameters:
    ms      - Delay in milliseconds

  Returns:
    None.

*/

static inline void DRV_ILI9488_DelayMS(int ms)
{
    SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;

    if (SYS_TIME_DelayMS(ms, &timer) != SYS_TIME_SUCCESS)
        return;
    while (SYS_TIME_DelayIsComplete(timer) == false);
}

/**
  Function:
    static void DRV_ILI9488_Reset(void)

  Summary:
    Toggles the hardware reset to the ILI9488.

  Description:
    This function toggles the GPIO pin for asserting reset to the ILI9488.

  Parameters:
    None

  Returns:
    None

*/
static void DRV_ILI9488_Reset(void)
{
    DRV_ILI9488_Reset_Assert();
    DRV_ILI9488_DelayMS(10);
    DRV_ILI9488_Reset_Deassert();
    DRV_ILI9488_DelayMS(30);
}

int DRV_ILI9488_Initialize(void)
{
    drv.state = INIT;

    return 0;
}

static int DRV_ILI9488_Configure(ILI9488_DRV *drvPtr)
{
    GFX_Disp_Intf intf = (GFX_Disp_Intf) drvPtr->port_priv;
    uint8_t cmd;
    uint8_t parms[16];

    DRV_ILI9488_NCSAssert(intf);

    //Pixel Format Set
    cmd = 0x3a;
    parms[0] = 0x5;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    //Set Image Function
    cmd = 0xe9;
    parms[0] = 0x1;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    //Interface Mode Control
    cmd = 0xb0;
    parms[0] = 0x0;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    //Memory Access Control
    cmd = 0x36;
    parms[0] = 0x28;
    GFX_Disp_Intf_WriteCommand(intf, cmd);
    GFX_Disp_Intf_WriteData(intf, parms, 1);

    //Sleep Out
    cmd = 0x11;
    GFX_Disp_Intf_WriteCommand(intf, cmd);

    //Display On
    cmd = 0x29;
    GFX_Disp_Intf_WriteCommand(intf, cmd);

    DRV_ILI9488_NCSDeassert(intf);

    return 0;
}


/**
  Function:
    static void DRV_ILI9488_Update(void)

  Summary:
    Driver-specific implementation of GFX HAL update function.

  Description:
    On GFX update, this function flushes any pending pixels to the ILI9488.

  Parameters:
    None.

  Returns:
    * GFX_SUCCESS       - Operation successful
    * GFX_FAILURE       - Operation failed

*/
void DRV_ILI9488_Update(void)
{
    uint32_t openVal;
    
    if(drv.state == INIT)
    {
        openVal = GFX_Disp_Intf_Open();
        
        drv.port_priv = (void *)openVal;
        
        if (drv.port_priv == 0)
        {
            drv.state = ERROR;
            return;
        }

        DRV_ILI9488_Reset();

        DRV_ILI9488_Configure(&drv);

        drv.state = RUN;
    }
}



gfxResult DRV_ILI9488_BlitBuffer(int32_t x,
                                           int32_t y,
                                           gfxPixelBuffer* buf)
{

    int row;
    uint16_t clr;
    uint16_t* ptr;
    uint8_t parm[4];

    GFX_Disp_Intf intf;
    
    if (drv.state != RUN)
        return GFX_FAILURE;
    
    intf = (GFX_Disp_Intf) drv.port_priv;


    DRV_ILI9488_NCSAssert(intf);

    //Write X/Column Address
    parm[0] = x>>8;
    parm[1] = x;
    parm[2] = (x + buf->size.width - 1) >>8;
    parm[3] = (x + buf->size.width - 1);
    GFX_Disp_Intf_WriteCommand(intf, 0x2a);
    GFX_Disp_Intf_WriteData(intf, parm, 4);
    
    //Write Y/Page Address
    parm[0] = y>>8;
    parm[1] = y;
    parm[2] = (y + buf->size.height - 1)>>8;
    parm[3] = (y + buf->size.height - 1);
    GFX_Disp_Intf_WriteCommand(intf, 0x2b);
    GFX_Disp_Intf_WriteData(intf, parm, 4);

    //Start Memory Write
    GFX_Disp_Intf_WriteCommand(intf, 0x2c);


    for(row = 0; row < buf->size.height; row++)
    {
        int col, dataIdx;
        ptr = gfxPixelBufferOffsetGet_Unsafe(buf, 0, row);
        for(col = 0, dataIdx = 0; col < buf->size.width; col++)
        {
            clr = ptr[col];
            pixelBuffer[dataIdx++] = (uint8_t) (clr >> 8);
            pixelBuffer[dataIdx++] = (uint8_t) (uint8_t) (clr & 0xff);
        }
        GFX_Disp_Intf_WriteData(intf,
                                pixelBuffer,
                                PIXEL_BUFFER_BYTES_PER_PIXEL *
                                buf->size.width);
    }
    DRV_ILI9488_NCSDeassert(intf);

    return GFX_SUCCESS;
}

gfxDriverIOCTLResponse DRV_ILI9488_IOCTL(gfxDriverIOCTLRequest request,
                                     void* arg)
{
    gfxIOCTLArg_Value* val;
    gfxIOCTLArg_DisplaySize* disp;
    gfxIOCTLArg_LayerRect* rect;
    
    switch(request)
    {
        case GFX_IOCTL_FRAME_END:
        {
            return GFX_IOCTL_OK;
        }	
        case GFX_IOCTL_GET_COLOR_MODE:
        {
            val = (gfxIOCTLArg_Value*)arg;
            
            val->value.v_colormode = PIXEL_BUFFER_COLOR_MODE;
            
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
            
            disp->width = DISPLAY_WIDTH;
            disp->height = DISPLAY_HEIGHT;
            
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
            
            val->value.v_uint = swapCount;
            
            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_GET_STATUS:
		{
            val = (gfxIOCTLArg_Value*)arg;
            
            if (drv.state == RUN)
                val->value.v_uint = 0;
            else
                val->value.v_uint = 1;
            
            return GFX_IOCTL_OK;
	    }
        default:
        { }
    }
    
    return GFX_IOCTL_UNSUPPORTED;
}

