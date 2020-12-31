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
  Custom SSD1351Display Top-Level Driver Source File

  File Name:
    drv_gfx_custom_external.c

  Summary:
    Top level driver for SSD1351.

  Description:
    Build-time generated implementation for the SSD1351Driver.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/




#include "definitions.h"

#include "gfx/interface/drv_gfx_disp_intf.h"
#include "drv_gfx_external_controller.h"

#include "system/time/sys_time.h"

// Default max width/height of SSD1351frame
#define DISPLAY_DEFAULT_WIDTH   480
#define DISPLAY_DEFAULT_HEIGHT  800

#define DISPLAY_WIDTH   96
#define DISPLAY_HEIGHT  96

#define PIXEL_BUFFER_COLOR_MODE GFX_COLOR_MODE_RGB_565
#define SCREEN_WIDTH DISPLAY_WIDTH
#define SCREEN_HEIGHT DISPLAY_HEIGHT

#ifdef GFX_DISP_INTF_PIN_RESET_Clear
#define DRV_SSD1351_Reset_Assert()      GFX_DISP_INTF_PIN_RESET_Clear()
#define DRV_SSD1351_Reset_Deassert()    GFX_DISP_INTF_PIN_RESET_Set()
#else
#error "ERROR: GFX_DISP_INTF_PIN_RESET not defined. Please define in Pin Manager."
#define DRV_SSD1351_Reset_Assert()
#define DRV_SSD1351_Reset_Deassert()
#endif

#define DRV_SSD1351_NCSAssert(intf)   GFX_Disp_Intf_PinControl(intf, \
                                    GFX_DISP_INTF_PIN_CS, \
                                    GFX_DISP_INTF_PIN_CLEAR)

#define DRV_SSD1351_NCSDeassert(intf) GFX_Disp_Intf_PinControl(intf, \
                                    GFX_DISP_INTF_PIN_CS, \
                                    GFX_DISP_INTF_PIN_SET)
#define PIXEL_BUFFER_BYTES_PER_PIXEL 2
static uint8_t pixelBuffer[SCREEN_WIDTH * PIXEL_BUFFER_BYTES_PER_PIXEL];

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

typedef struct SSD1351_DRV 
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
} SSD1351_DRV;

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
    
} SSD1351_CMD_PARAM;

SSD1351_DRV drv;

static uint32_t swapCount = 0;

const SSD1351_CMD_PARAM initCmdParm[] =
{
    {0xaf, 0, {0x0}, 200}, //Make display ON
    {0xa0, 1, {0x32,}, 0}, //SET_REMAP_DUAL_COM_LINE_COMMAND
    {0xa1, 1, {0x20,}, 0}, //SET_DISPLAY_START_LINE_COMMAND
};

/* ************************************************************************** */

/**
  Function:
    static void DRV_SSD1351_DelayMS(int ms)

  Summary:
    Delay helper function.

  Description:
    This is a helper function for delay using the system tick timer.

  Parameters:
    ms      - Delay in milliseconds

  Returns:
    None.

*/

static inline void DRV_SSD1351_DelayMS(int ms)
{
    SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;

    if (SYS_TIME_DelayMS(ms, &timer) != SYS_TIME_SUCCESS)
        return;
    while (SYS_TIME_DelayIsComplete(timer) == false);
}

/**
  Function:
    static void DRV_SSD1351_Reset(void)

  Summary:
    Toggles the hardware reset to the SSD1351.

  Description:
    This function toggles the GPIO pin for asserting reset to the SSD1351.

  Parameters:
    None

  Returns:
    None

*/
static void DRV_SSD1351_Reset(void)
{
    GFX_DISP_INTF_PIN_EN_Clear();
    GFX_DISP_INTF_PIN_RESET_Set();
    GFX_DISP_INTF_PIN_RW_Clear();
    
    DRV_SSD1351_DelayMS(1);
    
    GFX_DISP_INTF_PIN_RESET_Clear();
    
    DRV_SSD1351_DelayMS(2);
    
    GFX_DISP_INTF_PIN_RESET_Set();
    
    GFX_DISP_INTF_PIN_EN_Set();
}

int DRV_SSD1351_Initialize(void)
{
    drv.state = INIT;

    return 0;
}

static int DRV_SSD1351_Configure(SSD1351_DRV *drv,
                                           const SSD1351_CMD_PARAM *initVals,
                                           int numVals)
{
    GFX_Disp_Intf intf = (GFX_Disp_Intf) drv->port_priv;
    unsigned int i, returnValue;

    DRV_SSD1351_NCSAssert(intf);
    
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
            DRV_SSD1351_DelayMS(initVals->delayms);
        }
    }

    DRV_SSD1351_NCSDeassert(intf);

    return 0;
}

void DRV_SSD1351_Transfer(GFX_Disp_Intf intf)
{
    static int row;
    uint16_t clr;
    uint16_t* ptr;
    uint8_t parm[4];
    
    switch (drv.state)
    {
        case BLIT_COLUMN_CMD:
        {
            if (GFX_Disp_Intf_Ready(intf) == false)
                break;
            
            DRV_SSD1351_NCSAssert(intf);
                    
            drv.state = BLIT_COLUMN_DATA;
            
            GFX_Disp_Intf_WriteCommand(intf, 0x15);
                   
            break;
        }
        case BLIT_COLUMN_DATA:
        {
            uint32_t x = drv.blitParms.x;

            if (GFX_Disp_Intf_Ready(intf) == false)
                break;

            drv.state = BLIT_PAGE_CMD;

            //Add X offset
            x += 16;

            //Write X/Column Address
            parm[0] = x;
            parm[1] = (x + drv.blitParms.buf->size.width - 1);
            GFX_Disp_Intf_WriteData(intf, parm, 2);

            break;
        }
        case BLIT_PAGE_CMD:
        {
            if (GFX_Disp_Intf_Ready(intf) == false)
                break;
                        
            drv.state = BLIT_PAGE_DATA;
            
            GFX_Disp_Intf_WriteCommand(intf, 0x75);
                   
            break;
        }
        case BLIT_PAGE_DATA:
        {
            uint32_t y = drv.blitParms.y;

            if (GFX_Disp_Intf_Ready(intf) == false)
                break;

            drv.state = BLIT_WRITE_CMD;

            //Write Y/Page Address
            parm[0] = y;
            parm[1] = (y + drv.blitParms.buf->size.height - 1);
            GFX_Disp_Intf_WriteData(intf, parm, 2);

            break;
        }
        case BLIT_WRITE_CMD:
        {
            if (GFX_Disp_Intf_Ready(intf) == false)
                break;
            
            drv.state = BLIT_WRITE_DATA;
            
            //Start Memory Write
            GFX_Disp_Intf_WriteCommand(intf, 0x5c);

        row = 0;

            break;
        }
        case BLIT_WRITE_DATA:
        {
            if (GFX_Disp_Intf_Ready(intf) == false)
                break;

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
            if (GFX_Disp_Intf_Ready(intf) == false)
                break;

            DRV_SSD1351_NCSDeassert(intf); 
            gfxPixelBuffer_SetLocked(drv.blitParms.buf, GFX_FALSE);
            drv.state = IDLE;
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


/**
  Function:
    static void DRV_SSD1351_Update(void)

  Summary:
    Driver-specific implementation of GFX HAL update function.

  Description:
    On GFX update, this function flushes any pending pixels to the SSD1351.

  Parameters:
    None.

  Returns:
    * GFX_SUCCESS       - Operation successful
    * GFX_FAILURE       - Operation failed

*/
void DRV_SSD1351_Update(void)
{
    if(drv.state == INIT)
    {
        drv.port_priv = (void *) GFX_Disp_Intf_Open();
        if (drv.port_priv == 0)
        {
            drv.state = ERROR;
            return;
        }

        DRV_SSD1351_Reset();

        DRV_SSD1351_Configure(&drv,
                              initCmdParm,
                              sizeof(initCmdParm)/sizeof(SSD1351_CMD_PARAM));


        drv.state = IDLE;
    }
    else if (drv.state != IDLE)
    {
        DRV_SSD1351_Transfer((GFX_Disp_Intf) drv.port_priv);
    }
}

gfxColorMode DRV_SSD1351_GetColorMode(void)
{
    return PIXEL_BUFFER_COLOR_MODE;
}

uint32_t DRV_SSD1351_GetBufferCount(void)
{
    return 1;
}

uint32_t DRV_SSD1351_GetDisplayWidth(void)
{
    return SCREEN_WIDTH;
}

uint32_t DRV_SSD1351_GetDisplayHeight(void)
{
    return SCREEN_HEIGHT;
}

uint32_t DRV_SSD1351_GetLayerCount()
{
    return 1;
}

uint32_t DRV_SSD1351_GetActiveLayer()
{
    return 0;
}

gfxLayerState DRV_SSD1351_GetLayerState(uint32_t idx)
{
    gfxLayerState state;

    state.rect.x = 0;
    state.rect.y = 0;
    state.rect.width = SCREEN_WIDTH;
    state.rect.height = SCREEN_HEIGHT;
    state.enabled = GFX_TRUE;

    return state;
}

gfxResult DRV_SSD1351_SetActiveLayer(uint32_t idx)
{
    return GFX_SUCCESS;
}

gfxResult DRV_SSD1351_BlitBuffer(int32_t x,
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


    return GFX_SUCCESS;
}

void DRV_SSD1351_Swap(void)
{
    swapCount++;
}

uint32_t DRV_SSD1351_GetSwapCount(void)
{
    return swapCount;
}

gfxResult DRV_SSD1351_SetPalette(gfxBuffer* palette,
                                           gfxColorMode mode,
                                           uint32_t colorCount)
{
    return GFX_FAILURE;
}

