/*******************************************************************************
  Heart Rate 9 click routine source file

  Company
    Microchip Technology Inc.

  File Name
    heartrate9.c

  Summary
    Heart Rate 9 click routine Implementation File.

  Description
    This file defines the interface to the Heart Rate 9 click using USART PLIB.
    This click routine provides to read the sensor data on Heart Rate 9 click.

  Remarks:
    None.
 
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*
    (c) 2021 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/
// DOM-IGNORE-END

/**
  Section: Included Files
 */

#include <string.h>
#include "definitions.h"                // SYS function prototypes
#include "../click_interface.h"
#include "heartrate9.h"

/**
  Section: Macro Declarations
 */
#define RECEIVE_BUFFER_SIZE     (CLICK_HEARTRATE9_USART_READ_BUFFER_SIZE * 10)

typedef enum
{
    HEADER_BYTE1 = 0,
    HEADER_BYTE2,
    HEADER_BYTE3,
    HEART_RATE_BYTE_POS_FIND,
    HEART_RATE_READ,
}HEART_RATE_DATA_BUF_PROCESS_STATE;

/**
  Section: Variable Definitions
 */
static HEART_RATE_DATA_BUF_PROCESS_STATE    heartrate9_read_byte_state = HEADER_BYTE1;

static volatile char rx_data[CLICK_HEARTRATE9_USART_READ_BUFFER_SIZE]   = {0};
static volatile char rx_buff[RECEIVE_BUFFER_SIZE]   = {0};
static volatile uint16_t rx_buff_in_index           = 0;
static          uint16_t rx_buff_out_index          = 0;
static          bool hr9_click_intrfce_initialized  = false;
static          bool hr9_rx_data_buf_clr_state      = false;
static          uint16_t heartrate_pross_cnt        = 0;
static volatile bool hr9_data_rx_flag               = false;
static volatile uint32_t no_of_bytes_rcvd = 0;

/**
  Section: Private function prototypes
 */

static void heartrate9_click_initialize(void);
static void heartrate9_set_rst(uint8_t state);
static void heartrate9_click_initialize(void);
static void hr9_rx_buff_update(void);

/**
  Section: Driver APIs
 */

static void hr9_rx_buff_update(void)
{
    if(true == hr9_data_rx_flag)
    {
        hr9_data_rx_flag = false;
        if((rx_buff_in_index + no_of_bytes_rcvd) >= RECEIVE_BUFFER_SIZE)
        {
            memcpy((char *)&rx_buff[rx_buff_in_index], (char *)rx_data, (RECEIVE_BUFFER_SIZE - rx_buff_in_index));
            memcpy((char *)rx_buff, (char *)&rx_data[RECEIVE_BUFFER_SIZE - rx_buff_in_index], (rx_buff_in_index + no_of_bytes_rcvd - RECEIVE_BUFFER_SIZE));
        }
        else
        {
            memcpy((char *)&rx_buff[rx_buff_in_index], (char *)rx_data, no_of_bytes_rcvd);
        }
        
        rx_buff_in_index += no_of_bytes_rcvd;
        if(rx_buff_in_index >= RECEIVE_BUFFER_SIZE)
        {
            rx_buff_in_index = rx_buff_in_index - RECEIVE_BUFFER_SIZE;
        }
    }
}
static void heartrate9_ReadCallback(SERCOM_USART_EVENT event, uintptr_t context)
{
    uint32_t nBytesAvailable = 0;
    
    if (event == CLICK_HEARTRATE9_USART_EVENT_READ_THRESHOLD_REACHED)
    {
        /* Receiver should atleast have the thershold number of bytes in the ring buffer */
        nBytesAvailable = CLICK_HEARTRATE9_USART_ReadCountGet();
        
        no_of_bytes_rcvd = CLICK_HEARTRATE9_USART_Read((uint8_t*)&rx_data[0], nBytesAvailable);
        hr9_data_rx_flag = true;
    }
}

static void heartrate9_set_rst(uint8_t state)
{
    if ( state > 0 )
        CLICK_HEARTRATE9_RST_Set();
    else
        CLICK_HEARTRATE9_RST_Clear();
}

static void heartrate9_click_initialize(void)
{
    /* Register callback functions and send start message */
    CLICK_HEARTRATE9_USART_ReadCallbackRegister(heartrate9_ReadCallback, 0);
    CLICK_HEARTRATE9_USART_Read((uint8_t*)rx_buff, RECEIVE_BUFFER_SIZE);
    CLICK_HEARTRATE9_USART_ReadThresholdSet(10);
    CLICK_HEARTRATE9_USART_ReadNotificationEnable(true, false);
    CLICK_HEARTRATE9_TimerStart();
    heartrate9_set_rst(0);
    CLICK_HEARTRATE9_DelayMs(1);
    heartrate9_set_rst(1);
}

bool is_heartrate9_byte_ready(void)
{
    if (false == hr9_click_intrfce_initialized)
    {
        heartrate9_click_initialize();
        hr9_click_intrfce_initialized  = true;
    }
    if (false == hr9_rx_data_buf_clr_state)
    {
        CLICK_HEARTRATE9_DelayMs(5000);
        memset((char*)rx_buff, 0x00, RECEIVE_BUFFER_SIZE);
        hr9_rx_data_buf_clr_state  = true;
        rx_buff_in_index     = 0;
        rx_buff_out_index    = 0;
        hr9_data_rx_flag     = false;
    }
    while((rx_buff_in_index == rx_buff_out_index) && (false == hr9_data_rx_flag));

    return true;
}

int8_t heartrate9_read_byte(void)
{
    static uint8_t current_heartrate = 0;
    static uint8_t semicoln_cnt = 0;
    uint16_t lcl_rx_buff_in_index = rx_buff_in_index;

    hr9_rx_buff_update();
    if(rx_buff_out_index > lcl_rx_buff_in_index)
    {
        lcl_rx_buff_in_index    = RECEIVE_BUFFER_SIZE;
    }
    while(rx_buff_out_index < lcl_rx_buff_in_index)
    {
        switch(heartrate9_read_byte_state)
        {
            case HEADER_BYTE1:
                for(; rx_buff_out_index < lcl_rx_buff_in_index; rx_buff_out_index++)
                {
                    if(rx_buff[rx_buff_out_index] == '1')
                    {
                        heartrate9_read_byte_state  = HEADER_BYTE2;
                        rx_buff_out_index++;
                        break;
                    }
                }
                break;
            case HEADER_BYTE2:
                if(rx_buff[rx_buff_out_index] == '5')
                {
                    heartrate9_read_byte_state  = HEADER_BYTE3;
                }
                else
                {
                    heartrate9_read_byte_state  = HEADER_BYTE1;
                }
                rx_buff_out_index++;
                break;
            case HEADER_BYTE3:
                if(rx_buff[rx_buff_out_index] == ';')
                {
                    heartrate9_read_byte_state  = HEART_RATE_BYTE_POS_FIND;
                }
                else
                {
                    heartrate9_read_byte_state  = HEADER_BYTE1;
                }
                rx_buff_out_index++;
                break;
            case HEART_RATE_BYTE_POS_FIND:
                for(; rx_buff_out_index < lcl_rx_buff_in_index; rx_buff_out_index++)
                {
                    if(rx_buff[rx_buff_out_index] == ';')
                    {
                        semicoln_cnt++;
                        if(semicoln_cnt == 3)
                        {
                            semicoln_cnt                = 0;
                            rx_buff_out_index++;
                            current_heartrate           = 0;
                            heartrate9_read_byte_state  = HEART_RATE_READ;
                            break;
                        }
                    }
                }
                break;
            case HEART_RATE_READ:
                for(; rx_buff_out_index < lcl_rx_buff_in_index; rx_buff_out_index++)
                {
                    if(rx_buff[rx_buff_out_index] != ';')
                    {
                        current_heartrate   = (current_heartrate * 10) + (rx_buff[rx_buff_out_index] - 0x30);
                    }
                    else
                    {
                        heartrate9_read_byte_state  = HEADER_BYTE1;
                        heartrate_pross_cnt++;
                        if(heartrate_pross_cnt == 100)
                        {
                            heartrate_pross_cnt         = 0;
                            hr9_rx_data_buf_clr_state   = false;
                            return((int8_t)current_heartrate);
                        }
                        break;
                    }
                }
                break;
            default:
                break;
        }
    }
    if(rx_buff_out_index == RECEIVE_BUFFER_SIZE)
    {
        rx_buff_out_index = 0;
    }

    return(-1);
}
