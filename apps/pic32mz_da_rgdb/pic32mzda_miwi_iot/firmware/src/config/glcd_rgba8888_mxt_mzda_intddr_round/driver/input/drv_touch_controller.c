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
  GenericTouchController Display Top-Level Driver Source File

  File Name:
    drv_touch_controller.c

  Summary:
    Top level driver for a generic touch controller.

  Description:
    Build-time generated implementation for a Generic Touch Controller Driver.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/

#include "definitions.h"


#define DRV_TOUCH_I2C_INDEX 0
#define DRV_TOUCH_I2C_SLAVE_ADDRESS 0x55
#define DRV_TOUCH_CONFIG_NUM 0
#define DRV_TOUCH_CONFIG_MAX_PARMS 8
#define DRV_TOUCH_READ_BUFF_SIZE_BYTES 5
#define DRV_TOUCH_READ_TOUCH_DATA_ADDR  0x10
#define DRV_TOUCH_INT_VALUE 0

#define DRV_TOUCH_GESTURE_ENABLED 1
#define DRV_TOUCH_DATA_GESTURE_INDEX 1
#define DRV_TOUCH_DATA_GESTURE_MASK 0xff
#define DRV_TOUCH_DATA_GESTURE_SHIFT 0
#define DRV_TOUCH_DATA_GESTURE_SWIPE_UP_VALUE 0x10
#define DRV_TOUCH_DATA_GESTURE_SWIPE_LEFT_VALUE 0x14
#define DRV_TOUCH_DATA_GESTURE_SWIPE_DOWN_VALUE 0x18
#define DRV_TOUCH_DATA_GESTURE_SWIPE_RIGHT_VALUE 0x1c
#define DRV_TOUCH_DATA_GESTURE_ZOOM_IN_VALUE 0x48
#define DRV_TOUCH_DATA_GESTURE_ZOOM_OUT_VALUE 0x49

#define DRV_TOUCH_DATA_EVENT_INDEX 2
#define DRV_TOUCH_DATA_EVENT_MASK 0x80
#define DRV_TOUCH_DATA_EVENT_SHIFT 7
#define DRV_TOUCH_DATA_EVENT_DOWN_VALUE 0x1
#define DRV_TOUCH_DATA_EVENT_UP_VALUE 0x0
#define DRV_TOUCH_DATA_EVENT_HOLD_VALUE 0x2

#define DRV_TOUCH_DATA_SIZE_BYTES 2

#define DRV_TOUCH_DATA_POSX_BYTE1_INDEX 2
#define DRV_TOUCH_DATA_POSX_BYTE1_MASK 0x70
#define DRV_TOUCH_DATA_POSX_BYTE1_SHIFT 4

#define DRV_TOUCH_DATA_POSY_BYTE1_INDEX 2
#define DRV_TOUCH_DATA_POSY_BYTE1_MASK 0x7
#define DRV_TOUCH_DATA_POSY_BYTE1_SHIFT 0

#define DRV_TOUCH_DATA_POSX_BYTE0_INDEX 3
#define DRV_TOUCH_DATA_POSX_BYTE0_MASK 0xff
#define DRV_TOUCH_DATA_POSX_BYTE0_SHIFT 0

#define DRV_TOUCH_DATA_POSY_BYTE0_INDEX 4
#define DRV_TOUCH_DATA_POSY_BYTE0_MASK 0xff
#define DRV_TOUCH_DATA_POSY_BYTE0_SHIFT 0


#ifndef DRV_TOUCH_PIN_INT_Get
#error "ERROR: DRV_TOUCH_PIN_INT pin is not defined. Please define in Pin Manager."
#endif

typedef enum
{
    DRV_TOUCH_STATE_INIT,
    DRV_TOUCH_STATE_CONFIGURE,
    DRV_TOUCH_STATE_WAIT,
    DRV_TOUCH_STATE_IDLE,
    DRV_TOUCH_STATE_GET_TOUCH_DATA,
    DRV_TOUCH_STATE_PROCESS_TOUCH_DATA,
    DRV_TOUCH_STATE_ERROR,
} DRV_TOUCH_STATE;

typedef enum
{
    TOUCH_RELEASED,
    TOUCH_PRESSED,
} DRV_TOUCH_PRESS_STATE;

typedef enum
{
    DRV_TOUCH_ERROR_NONE,
    DRV_TOUCH_ERROR_I2C,
    DRV_TOUCH_ERROR_I2C_WRITE,
    DRV_TOUCH_ERROR_I2C_INVALID_STATE,
    DRV_TOUCH_ERROR_I2C_INVALID_HANDLE,
} DRV_TOUCH_ERROR;

typedef struct
{
    DRV_TOUCH_STATE state;
    DRV_TOUCH_STATE prev_state;
    DRV_TOUCH_PRESS_STATE press_state;
    DRV_TOUCH_STATE tx_count;
    DRV_HANDLE i2c_handle;
    DRV_I2C_TRANSFER_HANDLE i2c_tx_handle;
    SYS_TIME_HANDLE timer_handle;
    DRV_TOUCH_ERROR error;
    uint8_t cmd_buffer;
    uint8_t read_buffer[DRV_TOUCH_READ_BUFF_SIZE_BYTES];
} DRV_TOUCH_OBJ;

typedef struct
{
    int num_parms;
    int delay_ms;
    uint8_t parms[DRV_TOUCH_CONFIG_MAX_PARMS];
} DRV_TOUCH_CONFIG;


DRV_TOUCH_OBJ drv_touch =
{
    .state = DRV_TOUCH_STATE_INIT,
    .prev_state = DRV_TOUCH_STATE_INIT,
    .press_state = TOUCH_RELEASED,
    .tx_count = 0,
};



void drv_touch_i2c_callback (DRV_I2C_TRANSFER_EVENT  event,
                             DRV_I2C_TRANSFER_HANDLE transferHandle,
                             uintptr_t context)
{
    if (transferHandle != drv_touch.i2c_tx_handle)
    {
        //Invalid handle, throw error
        drv_touch.state = DRV_TOUCH_STATE_ERROR;
        drv_touch.error = DRV_TOUCH_ERROR_I2C_INVALID_HANDLE;

        return;
    }

    switch(event)
    {
        case DRV_I2C_TRANSFER_EVENT_COMPLETE:
        {
            switch(drv_touch.prev_state)
            {
                case DRV_TOUCH_STATE_CONFIGURE:
                {
                    drv_touch.state = drv_touch.prev_state;
                    break;
                }
                case DRV_TOUCH_STATE_GET_TOUCH_DATA:
                {
                    drv_touch.state = DRV_TOUCH_STATE_PROCESS_TOUCH_DATA;
                    break;
                }
                default:
                {
                    //Invalid condition, throw error
                    drv_touch.state = DRV_TOUCH_STATE_ERROR;
                    drv_touch.error = DRV_TOUCH_ERROR_I2C_INVALID_STATE;
                    break;
                }
            }
            break;
        }
        case DRV_I2C_TRANSFER_EVENT_ERROR:
        {
            drv_touch.state = DRV_TOUCH_STATE_ERROR;
            drv_touch.error = DRV_TOUCH_ERROR_I2C_WRITE;
            break;
        }
        default:
            break;
    }
}

void drv_touch_process_data(void)
{
    uint32_t pos_x, pos_y, event;
    uint32_t pos_xh, pos_xl, pos_yh, pos_yl;

    event = (drv_touch.read_buffer[DRV_TOUCH_DATA_EVENT_INDEX] &
            DRV_TOUCH_DATA_EVENT_MASK) >> DRV_TOUCH_DATA_EVENT_SHIFT;

    pos_xh = drv_touch.read_buffer[DRV_TOUCH_DATA_POSX_BYTE1_INDEX] & DRV_TOUCH_DATA_POSX_BYTE1_MASK;
    pos_xh >>= DRV_TOUCH_DATA_POSX_BYTE1_SHIFT;

    pos_xl = drv_touch.read_buffer[DRV_TOUCH_DATA_POSX_BYTE0_INDEX] & DRV_TOUCH_DATA_POSX_BYTE0_MASK;
    pos_xh >>= DRV_TOUCH_DATA_POSX_BYTE0_SHIFT;

    pos_x = ((pos_xh << 8) | pos_xl);

    pos_yh = drv_touch.read_buffer[DRV_TOUCH_DATA_POSY_BYTE1_INDEX] & DRV_TOUCH_DATA_POSY_BYTE1_MASK;
    pos_yh >>= DRV_TOUCH_DATA_POSY_BYTE1_SHIFT;

    pos_yl = drv_touch.read_buffer[DRV_TOUCH_DATA_POSY_BYTE0_INDEX] & DRV_TOUCH_DATA_POSY_BYTE0_MASK;
    pos_yh >>= DRV_TOUCH_DATA_POSY_BYTE0_SHIFT;

    pos_y = ((pos_yh << 8) | pos_yl);

    switch (drv_touch.press_state)
    {
        case TOUCH_RELEASED:
        {
            if (event == DRV_TOUCH_DATA_EVENT_DOWN_VALUE)
            {
                drv_touch.press_state = TOUCH_PRESSED;
                SYS_INP_InjectTouchDown(0, pos_x, pos_y);
            }
            break;
        }
        case TOUCH_PRESSED:
        {
            if (event == DRV_TOUCH_DATA_EVENT_DOWN_VALUE ||
                event == DRV_TOUCH_DATA_EVENT_HOLD_VALUE)
            {
                SYS_INP_InjectTouchMove(0, pos_x, pos_y);
            }
            else if (event == DRV_TOUCH_DATA_EVENT_UP_VALUE)
            {
                drv_touch.press_state = TOUCH_RELEASED;
                SYS_INP_InjectTouchUp(0, pos_x, pos_y);
            }
            break;
        }
        default:
            break;
    }

}

void drv_touch_controller_task(void)
{
    switch(drv_touch.state)
    {
        case DRV_TOUCH_STATE_INIT:
        {
            drv_touch.i2c_handle = DRV_I2C_Open(DRV_TOUCH_I2C_INDEX,
                                                DRV_IO_INTENT_READWRITE);
            if (drv_touch.i2c_handle == DRV_HANDLE_INVALID)
            {
                drv_touch.state = DRV_TOUCH_STATE_ERROR;
                drv_touch.error = DRV_TOUCH_ERROR_I2C;
                break;
            }

            DRV_I2C_TransferEventHandlerSet(drv_touch.i2c_handle,
                                     drv_touch_i2c_callback,
                                     (uintptr_t) &drv_touch);

            drv_touch.prev_state = DRV_TOUCH_STATE_INIT;
			drv_touch.state = DRV_TOUCH_STATE_CONFIGURE;
            break;
        }
        case DRV_TOUCH_STATE_CONFIGURE:
        {
            //Nothing to configure
            drv_touch.state = DRV_TOUCH_STATE_IDLE;
            break;
        }
        case DRV_TOUCH_STATE_WAIT:
        {
            //Do nothing, wait for callback
            break;
        }
        case DRV_TOUCH_STATE_IDLE:
        {
            //Poll notification pin
            if (DRV_TOUCH_PIN_INT_Get() == DRV_TOUCH_INT_VALUE)
            {
                drv_touch.state = DRV_TOUCH_STATE_GET_TOUCH_DATA;
            }
            break;
        }
        case DRV_TOUCH_STATE_GET_TOUCH_DATA:
        {
            drv_touch.prev_state = DRV_TOUCH_STATE_GET_TOUCH_DATA;
            drv_touch.state = DRV_TOUCH_STATE_WAIT;

            drv_touch.cmd_buffer = DRV_TOUCH_READ_TOUCH_DATA_ADDR;
            DRV_I2C_WriteReadTransferAdd(drv_touch.i2c_handle,
                                         DRV_TOUCH_I2C_SLAVE_ADDRESS,
                                         &drv_touch.cmd_buffer,
                                         1,
                                         drv_touch.read_buffer,
                                         DRV_TOUCH_READ_BUFF_SIZE_BYTES,
                                         (DRV_I2C_TRANSFER_HANDLE* const) &drv_touch.i2c_tx_handle);
            break;
        }
        case DRV_TOUCH_STATE_PROCESS_TOUCH_DATA:
        {
            drv_touch_process_data();

            drv_touch.state = DRV_TOUCH_STATE_IDLE;

            break;
        }
        case DRV_TOUCH_STATE_ERROR:
            break;
        default:
            break;
    }
}
