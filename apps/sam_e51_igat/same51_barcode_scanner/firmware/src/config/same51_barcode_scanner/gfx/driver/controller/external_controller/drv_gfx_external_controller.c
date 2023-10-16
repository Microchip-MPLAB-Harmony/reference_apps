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

gfxBlitCallBack drvBlitCallBack = NULL;

typedef enum
{
    INIT = 0,
    IDLE,
    BLIT_COLUMN_CMD,
    BLIT_COLUMN_DATA,
    BLIT_PAGE_CMD,
    BLIT_PAGE_DATA,
    BLIT_WRITE_CMD,
    BLIT_WRITE_DATA,
    BLIT_DONE,
    ERROR,
} DRV_STATE;

typedef struct ILI9488_DRV 
{   
    /* Driver state */
    DRV_STATE state;
        
    /* Port-specific private data */
    void *port_priv;

    struct
    {
        int32_t x;
        int32_t y;
        gfxPixelBuffer* buf;
    } blitParms;
} ILI9488_DRV;

typedef struct 
{
    /* Command */
    uint8_t cmd;
    
    /* Number of command parameters */
    uint8_t parmCount;
    
    /* Command parameters, max of 16 */
    uint8_t parms[16];
    
    /* delay */
    unsigned int delayms;
    
} ILI9488_CMD_PARAM;

ILI9488_DRV drv;

static uint32_t swapCount = 0;

const ILI9488_CMD_PARAM initCmdParm[] =
{
    {0x3a, 1, {0x5,}, 0}, //Pixel Format Set
    {0xe9, 1, {0x1,}, 0}, //Set Image Function
    {0xb0, 1, {0x0,}, 0}, //Interface Mode Control
    {0x36, 1, {0x28,}, 0}, //Memory Access Control
    {0x11, 0, {0x0}, 0}, //Sleep Out
    {0x29, 0, {0x0}, 0}, //Display On
};

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

static int DRV_ILI9488_Configure(ILI9488_DRV *drvPtr,
                                           const ILI9488_CMD_PARAM *initVals,
                                           int numVals)
{
    GFX_Disp_Intf intf = (GFX_Disp_Intf) drvPtr->port_priv;
    unsigned int i, returnValue;

    DRV_ILI9488_NCSAssert(intf);
    
    for (i = 0; i < numVals; i++, initVals++)
    {
        returnValue = GFX_Disp_Intf_WriteCommand(intf, initVals->cmd);
        if (0 != returnValue)
            break;
        
        while (GFX_Disp_Intf_Ready(intf) == false);
        
        if (initVals->parms != NULL &&
            initVals->parmCount > 0)
        {

            returnValue = GFX_Disp_Intf_WriteData(intf, 
                                                 (uint8_t *) initVals->parms,
                                                 initVals->parmCount);
            if (0 != returnValue)
                break;
        
            while (GFX_Disp_Intf_Ready(intf) == false);
        }
        
        if (initVals->delayms > 0)
        {
            DRV_ILI9488_DelayMS(initVals->delayms);
        }
    }

    DRV_ILI9488_NCSDeassert(intf);

    return 0;
}

void DRV_ILI9488_Transfer(GFX_Disp_Intf intf)
{
    static int row;
    uint16_t clr;
    uint16_t* ptr;
    uint8_t parm[4];
    
    switch (drv.state)
    {
        case BLIT_COLUMN_CMD:
        {
            
            DRV_ILI9488_NCSAssert(intf);
                    
            drv.state = BLIT_COLUMN_DATA;
            
            GFX_Disp_Intf_WriteCommand(intf, 0x2a);
                   
            break;
        }
        case BLIT_COLUMN_DATA:
        {
            uint32_t x = drv.blitParms.x;


            drv.state = BLIT_PAGE_CMD;

            //Write X/Column Address
            parm[0] = x>>8;
            parm[1] = x;
            parm[2] = (x + drv.blitParms.buf->size.width - 1)>>8;
            parm[3] = (x + drv.blitParms.buf->size.width - 1);
            GFX_Disp_Intf_WriteData(intf, parm, 4);

            break;
        }
        case BLIT_PAGE_CMD:
        {
                        
            drv.state = BLIT_PAGE_DATA;
            
            GFX_Disp_Intf_WriteCommand(intf, 0x2b);
                   
            break;
        }
        case BLIT_PAGE_DATA:
        {
            uint32_t y = drv.blitParms.y;


            drv.state = BLIT_WRITE_CMD;

            //Write Y/Page Address
            parm[0] = y>>8;
            parm[1] = y;
            parm[2] = (y + drv.blitParms.buf->size.height - 1)>>8;
            parm[3] = (y + drv.blitParms.buf->size.height - 1);
            GFX_Disp_Intf_WriteData(intf, parm, 4);

            break;
        }
        case BLIT_WRITE_CMD:
        {
            
            drv.state = BLIT_WRITE_DATA;
            
            //Start Memory Write
            GFX_Disp_Intf_WriteCommand(intf, 0x2c);

        row = 0;

            break;
        }
        case BLIT_WRITE_DATA:
        {

            if (row < drv.blitParms.buf->size.height)
            {
                int col, dataIdx;
                ptr = gfxPixelBufferOffsetGet_Unsafe(drv.blitParms.buf, 0, row);
                for(col = 0, dataIdx = 0; col < drv.blitParms.buf->size.width; col++)
                {
                    clr = ptr[col];
                    pixelBuffer[dataIdx++] = (uint8_t) (clr >> 8);
                    pixelBuffer[dataIdx++] = (uint8_t) (uint8_t) (clr & 0xff);
                }
                GFX_Disp_Intf_WriteData(intf,
                                        pixelBuffer,
                                        PIXEL_BUFFER_BYTES_PER_PIXEL *
                                        drv.blitParms.buf->size.width);
                row++;
            }
           
            if (row >= drv.blitParms.buf->size.height)
            {
                drv.state = BLIT_DONE;
            }
            
            break;
        }
        case BLIT_DONE:
        {
            DRV_ILI9488_NCSDeassert(intf); 
            gfxPixelBuffer_SetLocked(drv.blitParms.buf, GFX_FALSE);
            drv.state = IDLE;
            if (drvBlitCallBack != NULL) 
            {
                drvBlitCallBack();
            }
            break;
        }
        case IDLE:
        case ERROR:
        default:
        {
            break;
        }        
    }
}

void DRV_ILI9488_Intf_Callback(GFX_Disp_Intf intf, GFX_DISP_INTF_STATUS status, void * param)
{
    if (status == GFX_DISP_INTF_TX_DONE)
    {
        DRV_ILI9488_Transfer((GFX_Disp_Intf) drv.port_priv);
    }
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

        DRV_ILI9488_Configure(&drv,
                              initCmdParm,
                              sizeof(initCmdParm)/sizeof(ILI9488_CMD_PARAM));

        GFX_Disp_Intf_Set_Callback((GFX_Disp_Intf) drv.port_priv,
                                   DRV_ILI9488_Intf_Callback,
                                   NULL);

        drv.state = IDLE;
    }
}


gfxResult DRV_ILI9488_BlitBuffer(int32_t x,
                                int32_t y,
                                gfxPixelBuffer* buf)
{


    if(drv.state != IDLE)
        return GFX_FAILURE;

    drv.blitParms.x = x;
    drv.blitParms.y = y;
    drv.blitParms.buf = buf;
    drv.state = BLIT_COLUMN_CMD;
    
    gfxPixelBuffer_SetLocked(buf, GFX_TRUE);

    DRV_ILI9488_Transfer((GFX_Disp_Intf) drv.port_priv);

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
            
            if (drv.state == IDLE)
                val->value.v_uint = 0;
            else
                val->value.v_uint = 1;
            
            return GFX_IOCTL_OK;
        }
        case GFX_IOCTL_SET_BLIT_CALLBACK:
        {
            val = (gfxIOCTLArg_Value*)arg;
            drvBlitCallBack = (gfxBlitCallBack)val->value.v_pointer;

            return GFX_IOCTL_OK;
        }		
        default:
        {
		    break;
		}
    }
    
    return GFX_IOCTL_UNSUPPORTED;
}

