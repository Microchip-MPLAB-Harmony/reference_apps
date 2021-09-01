/*******************************************************************************
  Grid-EYE click Source File

  Company:
    Microchip Technology Inc.

  File Name:
    grid_eye_click.c

  Summary:
    This file contains the source code for the Grid-EYE click

  Description:
    This file contains the APIs for measuring,processing and displaying the data from Grid-EYE click.
 *******************************************************************************/

#include "grid_eye_click.h"
#include "gfx/legato/common/legato_common.h"
#include "config/default/definitions.h"

#define GRID_EYE_DRAW_SURFACE Screen0_DrawSurfaceWidget0

#define DISPLAY_TABLE_X_START_POS  0
#define DISPLAY_TABLE_Y_START_POS  0

#define GRID_EYE_TEMP_RECTANGLE_SIZE 12

#define BLUE                       0
#define RED                        1
#define ORANGE                     2
#define YELLOW                     3
#define GREEN                      4
#define LIGHT_YELLOW               5

#define BLUE_COLOR                 0x001F
#define RED_COLOR                  0xF800
#define ORANGE_COLOR               0xFC00
#define YELLOW_COLOR               0xFFE0
#define GREEN_COLOR                0x07E0
#define BLACK_COLOR                0x0000
#define LIGHT_YELLOW_COLOR         0xFFF7

#define ALPHA_BLENDING_VALUE       0XFF

#define GRID_EYE_TABLE_64_FIRST_SAMPLE_INDEX (GRID_EYE_SAMPLES_NUMBER - GRID_EYE_SAMPLES_PER_ROW)
#define GRID_EYE_X_Y_SIZE 8

GRID_EYE grid_eye_obj;
uint8_t temp_data_read[128];

SYS_TIME_HANDLE sys_time_handle;

static uint8_t _grid_eye_i2c_tx_buffer[10];

float grid_eye_table_64_temp_data[GRID_EYE_FRAMEBUFFER_SIZE/2];

void GRID_EYE_I2C_TransferEventHandler(DRV_I2C_TRANSFER_EVENT event, DRV_I2C_TRANSFER_HANDLE handle, uintptr_t context)
{
  
    switch(event)
    {
        case DRV_I2C_TRANSFER_EVENT_COMPLETE:
            
            grid_eye_obj.i2c_transaction_done = 1;
            break;

        case DRV_I2C_TRANSFER_EVENT_ERROR:
            
            break;

        default:
            break;
    }
}


void GRID_EYE_EXT_INT_PinEventHandler(EXTERNAL_INT_PIN pin, uintptr_t context)
{
    Nop();
}


void GRID_EYE_Initialize(GRID_EYE* _grid_eye_obj)
{
    
   _grid_eye_obj->state = GRID_EYE_GET_RAW_DATA;
    
   _grid_eye_obj->i2c_handle = DRV_I2C_Open(DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE);
   
        if (_grid_eye_obj->i2c_handle == DRV_HANDLE_INVALID)
        {
            // Unable to open the driver
            // May be the driver is not initialized or the initialization
            // is not complete.
        } 
   
   EVIC_ExternalInterruptCallbackRegister(EXTERNAL_INT_3,GRID_EYE_EXT_INT_PinEventHandler,(uintptr_t)NULL);
   SYS_INT_SourceEnable(INT_SOURCE_EXTERNAL_3);
   
   _grid_eye_obj->grid_eye_slave_addr = GRID_EYE_SLAVE_ADDRESS;
   
   sys_time_handle = SYS_TIME_TimerCreate(0, SYS_TIME_MSToCount(50), &GRID_EYE_Sys_time_callback, (uintptr_t)NULL, SYS_TIME_PERIODIC);
   
    if (sys_time_handle != SYS_TIME_HANDLE_INVALID)
    {
        //timer is created successfully.
    }
    
   DRV_I2C_TransferEventHandlerSet( _grid_eye_obj->i2c_handle, GRID_EYE_I2C_TransferEventHandler, (uintptr_t)NULL );
   
   GRID_EYE_I2c_write_blocking(*_grid_eye_obj,GRID_EYE_POWER_MODE_REG,GRID_EYE_POWER_MODE_NORMAL_MODE_COMMAND,GRID_EYE_I2C_TRANSFER_SIZE);
   GRID_EYE_I2c_write_blocking(*_grid_eye_obj,GRID_EYE_RESET_REG,GRID_EYE_RESET_FLAG_RESET_COMMAND,GRID_EYE_I2C_TRANSFER_SIZE);
   GRID_EYE_I2c_write_blocking(*_grid_eye_obj,GRID_EYE_FRAME_RATE_REG,GRID_EYE_FRAME_RATE_10FPS,GRID_EYE_I2C_TRANSFER_SIZE);
   GRID_EYE_I2c_write_blocking(*_grid_eye_obj,GRID_EYE_INTC_REG,GRID_EYE_INTC_INTMODE_SET,GRID_EYE_I2C_TRANSFER_SIZE);
   
   
   CORETIMER_DelayMs(100);
   
   GRID_EYE_I2c_write_blocking(*_grid_eye_obj,GRID_EYE_INTHL_REG,GRID_EYE_INTHL_VALUE,GRID_EYE_I2C_TRANSFER_SIZE);
   GRID_EYE_I2c_write_blocking(*_grid_eye_obj,GRID_EYE_INTHH_REG,GRID_EYE_INTHH_VALUE,GRID_EYE_I2C_TRANSFER_SIZE);
   
   GRID_EYE_I2c_write_blocking(*_grid_eye_obj,GRID_EYE_INTLL_REG,GRID_EYE_INTLL_VALUE,GRID_EYE_I2C_TRANSFER_SIZE);
   GRID_EYE_I2c_write_blocking(*_grid_eye_obj,GRID_EYE_INTLH_REG,GRID_EYE_INTLH_VALUE,GRID_EYE_I2C_TRANSFER_SIZE);
   
   GRID_EYE_I2c_write_blocking(*_grid_eye_obj,GRID_EYE_INTSL_REG,GRID_EYE_INTSL_VALUE,GRID_EYE_I2C_TRANSFER_SIZE);
   GRID_EYE_I2c_write_blocking(*_grid_eye_obj,GRID_EYE_INTSH_REG,GRID_EYE_INTSH_VALUE,GRID_EYE_I2C_TRANSFER_SIZE);
   
   CORETIMER_DelayMs(100);
   
   SYS_TIME_TimerStart(sys_time_handle);
}


void GRID_EYE_I2c_write_blocking(GRID_EYE _grid_obj, uint8_t grid_eye_reg_addr, uint8_t write_data,uint8_t size )
{
    
   
     _grid_eye_i2c_tx_buffer[0] = grid_eye_reg_addr;
    
   DRV_I2C_WriteTransferAdd(_grid_obj.i2c_handle, _grid_obj.grid_eye_slave_addr, _grid_eye_i2c_tx_buffer, size, &_grid_obj.transferHandle);

    if(_grid_obj.transferHandle == DRV_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
    }
   
   while(DRV_I2C_TransferStatusGet(_grid_obj.transferHandle) != DRV_I2C_TRANSFER_EVENT_COMPLETE);
   

}


void GRID_EYE_I2c_write_read_nonblocking(GRID_EYE _grid_obj,uint8_t grid_eye_reg_addr, void* read_data)
{

    
    _grid_eye_i2c_tx_buffer[0] = grid_eye_reg_addr;
    
    _grid_obj.i2c_transaction_done = 0;
    
    DRV_I2C_WriteReadTransferAdd(_grid_obj.i2c_handle, _grid_obj.grid_eye_slave_addr, _grid_eye_i2c_tx_buffer, 1, read_data, GRID_EYE_FRAMEBUFFER_SIZE, &_grid_obj.transferHandle);

        if(_grid_obj.transferHandle == DRV_I2C_TRANSFER_HANDLE_INVALID)
        {
            // Error handling here
        }

}


void GRID_EYE_Process_temp_raw_data(uint8_t* raw_data,float* temp_table_64_buffer)
{
    uint8_t index_raw_data, index_temp_table;
    
    index_temp_table = 0;
    
    for(index_raw_data = 0; index_raw_data<64; index_raw_data++)
    {
    
      temp_table_64_buffer[index_raw_data] = (float)((uint16_t)raw_data[index_temp_table] + (((uint16_t)raw_data[index_temp_table+1]<<8)&0x00FF));
      temp_table_64_buffer[index_raw_data] = temp_table_64_buffer[index_raw_data] * 0.25;
      
      index_temp_table = index_temp_table + 2 ;
    }
}

leBool event_Screen0_DrawSurfaceWidget0_OnDraw(leDrawSurfaceWidget* sfc, leRect* bounds)
{ 

    GRID_EYE_Display_draw_data();
    
    return 1;
}

void GRID_EYE_Sensor_task()
{
    if(grid_eye_obj.get_data_start == true)
    {
        switch(grid_eye_obj.state)
        {
            case GRID_EYE_GET_RAW_DATA:
            {
              GRID_EYE_I2c_write_read_nonblocking(grid_eye_obj,GRID_EYE_TEMP_REG,temp_data_read);
              grid_eye_obj.state = GRID_EYE_WAIT_TRANSACTION_TO_FINISH;
              
              break;
            }
            
            case GRID_EYE_WAIT_TRANSACTION_TO_FINISH:
            {
                if(grid_eye_obj.i2c_transaction_done == true)
                {
                  grid_eye_obj.i2c_transaction_done = false;
                  grid_eye_obj.state = GRID_EYE_PROCESS_RAW_DATA;
                }
                
                break;
            }
            
            case GRID_EYE_PROCESS_RAW_DATA:
            {
                GRID_EYE_Process_temp_raw_data(temp_data_read,grid_eye_table_64_temp_data);
                grid_eye_obj.state = GRID_EYE_GET_RAW_DATA;
                
                grid_eye_obj.get_data_start = false;
                grid_eye_obj.update_display = true;
                SYS_TIME_TimerStart(sys_time_handle);
                
                break;
            }
        }
    }

}

void GRID_EYE_Display_task()
{
  if(grid_eye_obj.update_display == true)
  {
    grid_eye_obj.update_display = false;
    GRID_EYE_DRAW_SURFACE->fn->invalidate(GRID_EYE_DRAW_SURFACE);
  }
}

void GRID_EYE_Display_draw_data()
{
    leRect rect_temp, rect_fill;
    uint32_t x,y,index,color;
    uint8_t grid_eye_table_64_current_row_addr;
    
    //Fill the all screen white yellow to eliminate the black rectangles
    
    rect_fill.height = 96;
    rect_fill.width =  96;
    rect_fill.x = 0;
    rect_fill.y = 0;
    
    leRenderer_RectFill(&rect_fill,LIGHT_YELLOW_COLOR,ALPHA_BLENDING_VALUE);
    
    
    index = GRID_EYE_TABLE_64_FIRST_SAMPLE_INDEX;
    grid_eye_table_64_current_row_addr = GRID_EYE_TABLE_64_FIRST_SAMPLE_INDEX;
    
    rect_temp.height = GRID_EYE_TEMP_RECTANGLE_SIZE;
    rect_temp.width =  GRID_EYE_TEMP_RECTANGLE_SIZE;
       
    
    for(y = 0; y<GRID_EYE_SAMPLES_PER_COLUMN; y++)
    {
        for(x = 0; x<GRID_EYE_SAMPLES_PER_ROW; x++)
        {
            rect_temp.x = x*GRID_EYE_TEMP_RECTANGLE_SIZE + DISPLAY_TABLE_X_START_POS;
            rect_temp.y = y*GRID_EYE_TEMP_RECTANGLE_SIZE + DISPLAY_TABLE_Y_START_POS;
            
            if(grid_eye_table_64_temp_data[index] > GRID_EYE_RED_COLOR_UPPER_LIMIT)
            {
              color = RED;
              
            }else if((grid_eye_table_64_temp_data[index] < GRID_EYE_RED_COLOR_UPPER_LIMIT)&&(grid_eye_table_64_temp_data[index] > GRID_EYE_ORANGE_COLOR_UPPER_LIMIT))
            {
              color = ORANGE;
              
            }else if((grid_eye_table_64_temp_data[index] < GRID_EYE_ORANGE_COLOR_UPPER_LIMIT)&&(grid_eye_table_64_temp_data[index] > GRID_EYE_YELLOW_COLOR_UPPER_LIMIT))
            {
              color = YELLOW;
              
            }else if((grid_eye_table_64_temp_data[index] < GRID_EYE_YELLOW_COLOR_UPPER_LIMIT)&&(grid_eye_table_64_temp_data[index] > GRID_EYE_BLUE_COLOR_UPPER_LIMIT))
            {
                color = LIGHT_YELLOW;
            
            }else if((grid_eye_table_64_temp_data[index] < GRID_EYE_BLUE_COLOR_UPPER_LIMIT)&&(grid_eye_table_64_temp_data[index] > GRID_EYE_GREEN_COLOR_UPPER_LIMIT))
            {
            
                color = GREEN;
            }
            
            
            switch(color)
            {
                case LIGHT_YELLOW:
                {
                    leRenderer_RectFill(&rect_temp,LIGHT_YELLOW_COLOR,ALPHA_BLENDING_VALUE);
                    break;
                }
                
                case RED:
                {
                    leRenderer_RectFill(&rect_temp,RED_COLOR,ALPHA_BLENDING_VALUE);
                    break;
                }
                
                case ORANGE:
                {
                    leRenderer_RectFill(&rect_temp,ORANGE_COLOR,ALPHA_BLENDING_VALUE);
                    break;
                }
                
                case YELLOW:
                {
                    leRenderer_RectFill(&rect_temp,YELLOW_COLOR,ALPHA_BLENDING_VALUE);
                    break;
                }
                
                case GREEN:
                {
                    leRenderer_RectFill(&rect_temp,GREEN_COLOR,ALPHA_BLENDING_VALUE);
                    break;
                }
            }
            
          
            
            if((index - grid_eye_table_64_current_row_addr + 1) == (GRID_EYE_SAMPLES_PER_ROW))
            {
                index = grid_eye_table_64_current_row_addr - GRID_EYE_SAMPLES_PER_ROW;
                grid_eye_table_64_current_row_addr = index;
                index--;
            }
            
            index++;
        }
    }
  
}

void GRID_EYE_Sys_time_callback(uintptr_t context)
{
   grid_eye_obj.get_data_start = true;
   SYS_TIME_TimerStop(sys_time_handle);
}