/****************************************************************************
* Title                 :   HeartRate 3 Click
* Filename              :   heartrate_3_hw.c
* Author                :   Corey Lakey
* Origin Date           :   04/06/2016
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date     Software Version    Initials    Description
* 04/06/2016         1.0            CAL
* 28/01/2020         1.0.1          MK        Modified.    
*****************************************************************************/
/** @file heartrate_3_hw.c
 *  @brief heartrate3 communication driver
 */
/****************************************************************************
* Note: In version 1.0.1, This file has been modified by MK to meet the custom 
* application requirements. Should you need to contact the modifier, Write an 
* Email to mohan.kumar@microchip.com or alternatively, write to 
* Mohan Kumar, Microchip Technology India Pvt Ltd
* Plot No. 1498, EPIP, 1st Phase Industrial Area, Whitefield, Bengaluru, 
* Karnataka 560066
*******************************************************************************/
/*******************************************************************************
 Copyright (C) 2017  Microchip Technology Incorporated and its subsidiaries.

This program is free software; you can redistribute it and/or modify it under 
the terms of the GNU General Public License as published by the Free Software 
Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY 
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A 
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with 
this program; if not, write to the Free Software Foundation, Inc., 
51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*******************************************************************************/
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>
#include "../include/heartrate_3_hal.h"
#include "../include/heartrate_3_hw.h"


/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/
/**
 * Doxygen tag for documenting variables and constants
 */

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/

uint8_t hr3_init( uint8_t address, dynamic_modes_t* dyn_modes )
{
    
//    inm_inn_t inp_inn_setting;
//    inp_inn_setting.short_setting = 1;
//    inp_inn_setting.ext_div =0;
//    inp_inn_setting.pd_setting =0;
//    offdac_settings_t off_setting;
//    off_setting.offdac_pol_led1 = 1;
//    off_setting.offdac_set_led1 = 7;
    
    
    hr3_hal_init( address );
    hr3_set_settings( sw_reset_en,diag_mode_dis,susp_count_dis,reg_read_dis );
    
    hr3_set_led2_start_end( 0, 399 ); //0, 399
    hr3_set_led2_start_end( 0, 399 ); //0, 399
    hr3_set_led2_sample_start_end( 80, 399 ); //80, 399
    hr3_set_adc_reset0_start_end( 401, 407 ); //401, 407
    hr3_set_led2_convert_start_end( 408, 1467 ); //408, 1467
    hr3_set_led3_start_stop( 400, 799 ); //400, 799
    hr3_set_led3_sample_start_end( 480, 799 ); //480, 799
    hr3_set_adc_reset1_start_end( 1469, 1475 ); //1469, 1475
    hr3_set_led3_convert_start_end( 1476, 2535 ); //1476, 2535
    hr3_set_led1_start_end( 800, 1199 ); //800, 1199
    hr3_set_led1_sample_start_end( 880, 1199 );
    hr3_set_adc_reset2_start_end( 2537, 2543 ); //2537, 2543
    hr3_set_led1_convert_start_end( 2544, 3603 ); //2544, 3603
    hr3_set_amb1_sample_start_end( 1279, 1598 ); //1279, 1598
    hr3_set_adc_reset3_start_end( 3605, 3611 ); //3605, 3611
    hr3_set_amb1_convert_start_end( 3612, 4671 ); //3612, 4671
    hr3_set_pdn_cycle_start_end( 5471, 39199 ); //5471, 39199
    hr3_set_prpct_count( 39999 );                              //Clock timing for CLKDIV_PRF  = 1
    hr3_set_prpct_count( 39999 );  

//    hr3_set_led2_start_end( 0, 398 );
//    hr3_set_led2_start_end( 0, 398 );
//    hr3_set_led2_sample_start_end( 100, 398 );
//    hr3_set_adc_reset0_start_end( 5600, 5606 );
//    hr3_set_led2_convert_start_end( 5608, 6067 );
//    hr3_set_led3_start_stop( 400, 798 );
//    hr3_set_led3_sample_start_end( 500, 798 );
//    hr3_set_adc_reset1_start_end( 6069, 6075 );
//    hr3_set_led3_convert_start_end( 6077, 6536 );    
//    hr3_set_led1_start_end( 800, 1198 );
//    hr3_set_led1_sample_start_end( 900, 1198 );
//    hr3_set_adc_reset2_start_end( 6538, 6544 );
//    hr3_set_led1_convert_start_end( 6546, 7006 );
//    hr3_set_amb1_sample_start_end( 1300, 1598 );
//    hr3_set_adc_reset3_start_end( 7008, 7014 );
//    hr3_set_amb1_convert_start_end( 7016, 7475 );
//    hr3_set_prgrmmbl_timing_start_end( 7477, 8277);  //7477, 7577 
//    hr3_set_pdn_cycle_start_end( 9077, 39199 ); //7675, 39199
//    hr3_set_prpct_count( 39999 );                              //Clock timing for CLKDIV_PRF  = 1    
//    hr3_set_prpct_count( 39999 );                              //Clock timing for CLKDIV_PRF  = 1        
    
    //Clock Timing for CLKDIV_PRF = 5
//    hr3_set_led2_start_end( 0, 79 );
//    hr3_set_led2_start_end( 0, 79 );
//    hr3_set_led2_sample_start_end( 16, 79 );
//    hr3_set_adc_reset0_start_end( 80, 81 );
//    hr3_set_led2_convert_start_end( 81, 293 );
//    hr3_set_led3_start_stop( 80, 159 );
//    hr3_set_led3_sample_start_end( 96, 159 );
//    hr3_set_adc_reset1_start_end( 293, 295 );
//    hr3_set_led3_convert_start_end( 295, 507 );
//    hr3_set_led1_start_end( 160, 239 );
//    hr3_set_led1_sample_start_end( 176, 239 );
//    hr3_set_adc_reset2_start_end( 507, 508 );
//    hr3_set_led1_convert_start_end( 508, 720 );
//    hr3_set_amb1_sample_start_end( 255, 319 );
//    hr3_set_adc_reset3_start_end( 721, 722 );
//    hr3_set_amb1_convert_start_end( 722, 934 );
//    hr3_set_pdn_cycle_start_end( 1094, 7839 );
//    hr3_set_prpct_count( 7999 );        
//    hr3_set_prpct_count( 7999 );        
    
    hr3_set_timer_and_average_num( true, 3 ); //true, 3
    hr3_set_seperate_tia_gain( true, 0, 4 ); // true,0,4
    hr3_set_tia_gain( false, 0, 3 ); //false, 0, 3
    hr3_set_led_currents( 15,3,3 ); //15,3,3
    hr3_set_dynamic_settings( dyn_modes );
    hr3_set_clkout_div( false, 2 );
    hr3_set_int_clk_div( 1 );
    hr3_set_int_clk_div( 1 );
    //hr3_set_inp_inn_settings(&inp_inn_setting);
//    hr3_set_offdac_settings(&off_setting);
            

    return 0;
}

uint8_t hr3_set_settings( sw_reset_t sw_reset, diag_mode_t diag_mode,
                          susp_count_t susp_counter, reg_read_t reg_read )
{
    uint8_t reg = DIAGNOSIS;
    uint8_t temp[3] = { 0 };

    temp[2] |= ( sw_reset << DIAG_SW_RST );
    temp[2] |= ( diag_mode << DIAG_EN );
    temp[2] |= ( susp_counter << DIAG_TM_CNT_RST );
    temp[2] |= ( reg_read << DIAG_REG_READ );

    hr3_hal_write( &reg, temp, 3 );
    
    return 0;
}

uint8_t hr3_set_led2_sample_start_end( uint16_t start, uint16_t end )
{
    uint8_t reg_st = SMPL_LED2_ST;
    uint8_t reg_end = SMPL_LED2_END;
    uint8_t temp_st[3] = { 0 };
    uint8_t temp_end[3] = { 0 };

    if( start > 65535 || end > 65535 )
        return -1;

    temp_st[1] = start >> 8;
    temp_st[2] = (uint8_t)start;

    hr3_hal_write( &reg_st, temp_st, 3 );

    temp_end[1] = end >> 8;
    temp_end[2] = (uint8_t)end;

    hr3_hal_write( &reg_end, temp_end, 3 );

    return 0;

}

uint8_t hr3_set_led1_start_end( uint16_t start, uint16_t end )
{
    uint8_t reg_st = LED1_ST;
    uint8_t reg_end = LED1_END;
    uint8_t temp_st[3] = { 0 };
    uint8_t temp_end[3] = { 0 };

    if( start > 65535 || end > 65535 )
        return -1;

    temp_st[1] = start >> 8;
    temp_st[2] = (uint8_t)start;

    hr3_hal_write( &reg_st, temp_st, 3 );

    temp_end[1] = end >> 8;
    temp_end[2] = (uint8_t)end;

    hr3_hal_write( &reg_end, temp_end, 3 );

    return 0;

}

uint8_t hr3_set_led3_sample_start_end( uint16_t start, uint16_t end )
{
    uint8_t reg_st = SMPL_LED3_ST;
    uint8_t reg_end = SMPL_LED3_END;
    uint8_t temp_st[3] = { 0 };
    uint8_t temp_end[3] = { 0 };

    if( start > 65535 || end > 65535 )
        return -1;

    temp_st[1] = start >> 8;
    temp_st[2] = (uint8_t)start;

    hr3_hal_write( &reg_st, temp_st, 3 );

    temp_end[1] = end >> 8;
    temp_end[2] = (uint8_t)end;

    hr3_hal_write( &reg_end, temp_end, 3 );

    return 0;

}

uint8_t hr3_set_led1_sample_start_end( uint16_t start, uint16_t end )
{
    uint8_t reg_st = SMPL_LED1_ST;
    uint8_t reg_end = SMPL_LED1_END;
    uint8_t temp_st[3] = { 0 };
    uint8_t temp_end[3] = { 0 };

    if( start > 65535 || end > 65535 )
        return -1;

    temp_st[1] = start >> 8;
    temp_st[2] = (uint8_t)start;

    hr3_hal_write( &reg_st, temp_st, 3 );

    temp_end[1] = end >> 8;
    temp_end[2] = (uint8_t)end;

    hr3_hal_write( &reg_end, temp_end, 3 );

    return 0;

}

uint8_t hr3_set_led2_start_end( uint16_t start, uint16_t end )
{
    uint8_t reg_st = LED2_ST;
    uint8_t reg_end = LED2_END;
    uint8_t temp_st[3] = { 0 };
    uint8_t temp_end[3] = { 0 };

    if( start > 65535 || end > 65535 )
        return -1;

    temp_st[1] = start >> 8;
    temp_st[2] = (uint8_t)start;

    hr3_hal_write( &reg_st, temp_st, 3 );

    temp_end[1] = end >> 8;
    temp_end[2] = (uint8_t)end;

    hr3_hal_write( &reg_end, temp_end, 3 );

    return 0;

}

uint8_t hr3_set_amb1_sample_start_end( uint16_t start, uint16_t end )
{
    uint8_t reg_st = SMPL_AMB1_ST;
    uint8_t reg_end = SMPL_AMB1_END;
    uint8_t temp_st[3] = { 0 };
    uint8_t temp_end[3] = { 0 };

    if( start > 65535 || end > 65535 )
        return -1;

    temp_st[1] = start >> 8;
    temp_st[2] = (uint8_t)start;

    hr3_hal_write( &reg_st, temp_st, 3 );

    temp_end[1] = end >> 8;
    temp_end[2] = (uint8_t)end;

    hr3_hal_write( &reg_end, temp_end, 3 );

    return 0;

}

uint8_t hr3_set_led2_convert_start_end( uint16_t start, uint16_t end )
{
    uint8_t reg_st = LED2_CONV_ST;
    uint8_t reg_end = LED2_CONV_END;
    uint8_t temp_st[3] = { 0 };
    uint8_t temp_end[3] = { 0 };

    if( start > 65535 || end > 65535 )
        return -1;

    temp_st[1] = start >> 8;
    temp_st[2] = (uint8_t)start;

    hr3_hal_write( &reg_st, temp_st, 3 );

    temp_end[1] = end >> 8;
    temp_end[2] = (uint8_t)end;

    hr3_hal_write( &reg_end, temp_end, 3 );

    return 0;

}

uint8_t hr3_set_led3_convert_start_end( uint16_t start, uint16_t end )
{
    uint8_t reg_st = LED3_CONV_ST;
    uint8_t reg_end = LED3_CONV_END;
    uint8_t temp_st[3] = { 0 };
    uint8_t temp_end[3] = { 0 };

    if( start > 65535 || end > 65535 )
        return -1;

    temp_st[1] = start >> 8;
    temp_st[2] = (uint8_t)start;

    hr3_hal_write( &reg_st, temp_st, 3 );

    temp_end[1] = end >> 8;
    temp_end[2] = (uint8_t)end;

    hr3_hal_write( &reg_end, temp_end, 3 );

    return 0;

}

uint8_t hr3_set_led1_convert_start_end( uint16_t start, uint16_t end )
{
    uint8_t reg_st = LED1_CONV_ST;
    uint8_t reg_end = LED1_CONV_END;
    uint8_t temp_st[3] = { 0 };
    uint8_t temp_end[3] = { 0 };

    if( start > 65535 || end > 65535 )
        return -1;

    temp_st[1] = start >> 8;
    temp_st[2] = (uint8_t)start;

    hr3_hal_write( &reg_st, temp_st, 3 );

    temp_end[1] = end >> 8;
    temp_end[2] = (uint8_t)end;

    hr3_hal_write( &reg_end, temp_end, 3 );

    return 0;

}

uint8_t hr3_set_amb1_convert_start_end( uint16_t start, uint16_t end )
{
    uint8_t reg_st = AMB1_CONV_ST;
    uint8_t reg_end = AMB1_CONV_END;
    uint8_t temp_st[3] = { 0 };
    uint8_t temp_end[3] = { 0 };

    if( start > 65535 || end > 65535 )
        return -1;

    temp_st[1] = start >> 8;
    temp_st[2] = (uint8_t)start;

    hr3_hal_write( &reg_st, temp_st, 3 );

    temp_end[1] = end >> 8;
    temp_end[2] = (uint8_t)end;

    hr3_hal_write( &reg_end, temp_end, 3 );

    return 0;

}

uint8_t hr3_set_adc_reset0_start_end( uint16_t start, uint16_t end )
{
    uint8_t reg_st = ADC_RST_P0_ST;
    uint8_t reg_end = ADC_RST_P0_END;
    uint8_t temp_st[3] = { 0 };
    uint8_t temp_end[3] = { 0 };

    if( start > 65535 || end > 65535 )
        return -1;

    temp_st[1] = start >> 8;
    temp_st[2] = (uint8_t)start;

    hr3_hal_write( &reg_st, temp_st, 3 );

    temp_end[1] = end >> 8;
    temp_end[2] = (uint8_t)end;

    hr3_hal_write( &reg_end, temp_end, 3 );

    return 0;

}

uint8_t hr3_set_adc_reset1_start_end( uint16_t start, uint16_t end )
{
    uint8_t reg_st = ADC_RST_P1_ST;
    uint8_t reg_end = ADC_RST_P1_END;
    uint8_t temp_st[3] = { 0 };
    uint8_t temp_end[3] = { 0 };

    if( start > 65535 || end > 65535 )
        return -1;

    temp_st[1] = start >> 8;
    temp_st[2] = (uint8_t)start;

    hr3_hal_write( &reg_st, temp_st, 3 );

    temp_end[1] = end >> 8;
    temp_end[2] = (uint8_t)end;

    hr3_hal_write( &reg_end, temp_end, 3 );

    return 0;

}

uint8_t hr3_set_adc_reset2_start_end( uint16_t start, uint16_t end )
{
    uint8_t reg_st = ADC_RST_P2_ST;
    uint8_t reg_end = ADC_RST_P2_END;
    uint8_t temp_st[3] = { 0 };
    uint8_t temp_end[3] = { 0 };

    if( start > 65535 || end > 65535  )
        return -1;

    temp_st[1] = start >> 8;
    temp_st[2] = (uint8_t)start;

    hr3_hal_write( &reg_st, temp_st, 3 );

    temp_end[1] = end >> 8;
    temp_end[2] = (uint8_t)end;

    hr3_hal_write( &reg_end, temp_end, 3 );

    return 0;

}

uint8_t hr3_set_adc_reset3_start_end( uint16_t start, uint16_t end )
{
    uint8_t reg_st = ADC_RST_P3_ST;
    uint8_t reg_end = ADC_RST_P3_END;
    uint8_t temp_st[3] = { 0 };
    uint8_t temp_end[3] = { 0 };

    if( start > 65535 || end > 65535 )
        return -1;

    temp_st[1] = start >> 8;
    temp_st[2] = (uint8_t)start;

    hr3_hal_write( &reg_st, temp_st, 3 );

    temp_end[1] = end >> 8;
    temp_end[2] = (uint8_t)end;

    hr3_hal_write( &reg_end, temp_end, 3 );

    return 0;

}

uint8_t hr3_set_prpct_count( uint16_t count )
{
    uint8_t reg = PRPCT;
    uint8_t temp[3] = { 0 };

    if( count > 65535 )
        return -1;

    temp[1] = count >> 8;
    temp[2] = (uint8_t)count;

    hr3_hal_write( &reg, temp, 3 );

    return 0;

}

uint8_t hr3_set_timer_and_average_num( bool enable, uint8_t av_num )
{
    uint8_t reg = TIM_NUMAV;
    uint8_t temp[3] = { 0 };

    if( av_num > 15 || av_num < 0 )
        return -1;

    if( enable )
    {
        temp[1] |= ( 1 << TIMEREN );
        temp[2] |= ( av_num << NUMAV );
        hr3_hal_write( &reg, temp, 3 );
    }
    else
    {
        temp[2] |= ( av_num << NUMAV );
        hr3_hal_write( &reg, temp, 3 );
    }

    return 0;

}

uint8_t hr3_set_seperate_tia_gain( bool seperate, uint8_t cf_setting,
                                   uint8_t gain_setting )
{
    uint8_t reg = TIA_GAINS2;
    uint8_t temp[3] = { 0 };

    if( cf_setting > 7 || gain_setting > 7 )
        return -1;

    if( seperate )
    {
        temp[1] = TIA_ENSEPGAIN;
        temp[2] |= ( cf_setting << TIA_CF_SEP );
        temp[2] |= ( gain_setting << TIA_GAIN_SEP );
        hr3_hal_write( &reg, temp, 3 );
    }
    else
    {
        temp[2] |= ( cf_setting << TIA_CF_SEP );
        temp[2] |= ( gain_setting << TIA_GAIN_SEP );
        hr3_hal_write( &reg, temp, 3 );
    }
    
    return 0;

}

uint8_t hr3_set_tia_gain( bool replace, uint8_t cf_setting,
                             uint8_t gain_setting )
{
    uint8_t reg = TIA_GAINS1;
    uint8_t temp[3] = { 0 };

    if( cf_setting > 7 || gain_setting > 7 )
        return -1;

    if( replace )
    {
        temp[1] = TIA_PROG_TG_EN;
        temp[2] |= ( cf_setting << TIA_CF );
        temp[2] |= ( gain_setting << TIA_GAIN );
        hr3_hal_write( &reg, temp, 3 );
    }
    else
    {
        temp[1] = 0;
        temp[2] |= ( cf_setting << TIA_CF_SEP );
        temp[2] |= ( gain_setting << TIA_GAIN_SEP );
        hr3_hal_write( &reg, temp, 3 );
    }

    return 0;

}

uint8_t hr3_replace_adc( bool replace )
{
    uint8_t reg = TIA_GAINS1;
    uint8_t temp[3] = {0};

    hr3_read_enable();
    hr3_hal_read( &reg, temp, 3 );
    hr3_read_disable();

    if( replace )
    {
        temp[1] |= TIA_PROG_TG_EN;
        hr3_hal_write( &reg, temp, 3 );
    }
    else
    {
        temp[1] &= ~( TIA_PROG_TG_EN );
        hr3_hal_write( &reg, temp, 3 );
    }

    return 0;

}

uint8_t hr3_set_led_currents( uint8_t led1_current, uint8_t led2_current,
                              uint8_t led3_current )
{
    uint8_t reg = LED_CONFIG;
    uint8_t temp[3] = { 0 };
    unsigned long currents = 0;

    if( led1_current > 63 ||
        led2_current > 63 ||
        led3_current > 63 )
        return -1;

    currents |= ( led3_current << 12 );
    currents |= ( led2_current << 6 );
    currents |= led1_current;

    temp[2] |= currents;
    temp[1] |= currents >> 8;
    temp[0] |= currents >> 16;


    hr3_hal_write( &reg, temp, 3 );

    return 0;

}

uint8_t hr3_set_dynamic_settings( dynamic_modes_t* modes )
{
    uint8_t reg = SETTINGS;
    uint8_t temp[3] = { 0 };
    unsigned long buffer = 0;

    buffer |= ( modes->transmit << STT_DYNMC1 );
    buffer |= ( modes->curr_range << STT_ILED_2X );
    buffer |= ( modes->adc_power << STT_DYNMC2 );
    buffer |= ( modes->clk_mode << STT_OSC_EN );
    buffer |= ( modes->tia_power << STT_DYNMC3 );
    buffer |= ( modes->rest_of_adc << STT_DYNMC4 );
    buffer |= ( modes->afe_rx_mode << STT_PDNRX );
    buffer |= ( modes->afe_mode << STT_PDNAFE );

    temp[2] |= buffer;
    temp[1] |= buffer >> 8;
    temp[0] |= buffer >> 16;


    hr3_hal_write( &reg, temp, 3 );

    return 0;
}
uint8_t hr3_set_transmit_enable( transmitter_t transmit )
{
    uint8_t reg = SETTINGS;
    uint8_t temp[3] = {0};
    unsigned long buffer = 0;

    hr3_read_enable();
    hr3_hal_read( &reg, temp, 3 );
    hr3_read_disable();

    buffer |= ( transmit << STT_DYNMC1 );
    temp[2] |= buffer;
    temp[1] |= buffer >> 8;
    temp[0] |= buffer >> 16;

    hr3_hal_write( &reg, temp, 3 );

    return 0;
}

uint8_t hr3_set_current_range( led_current_range_t curr_range )
{
    uint8_t reg = SETTINGS;
    uint8_t temp[3] = {0};
    unsigned long buffer = 0;

    hr3_read_enable();
    hr3_hal_read( &reg, temp, 3 );
    hr3_read_disable();

    buffer |= ( curr_range << STT_ILED_2X );
    temp[2] |= buffer;
    temp[1] |= buffer >> 8;
    temp[0] |= buffer >> 16;

    hr3_hal_write( &reg, temp, 3 );

    return 0;

}

uint8_t hr3_set_adc_power( adc_pwer_t adc_power )
{
    uint8_t reg = SETTINGS;
    uint8_t temp[3] = {0};
    unsigned long buffer = 0;

    hr3_read_enable();
    hr3_hal_read( &reg, temp, 3 );
    hr3_read_disable();

    buffer |= ( adc_power << STT_DYNMC2 );
    temp[2] |= buffer;
    temp[1] |= buffer >> 8;
    temp[0] |= buffer >> 16;

    hr3_hal_write( &reg, temp, 3 );

    return 0;

}

uint8_t hr3_set_clock_mode( clk_mode_t clk_mode )
{
    uint8_t reg = SETTINGS;
    uint8_t temp[3] = {0};
    unsigned long buffer = 0;

    hr3_read_enable();
    hr3_hal_read( &reg, temp, 3 );
    hr3_read_disable();

    buffer |= ( clk_mode << STT_OSC_EN );
    temp[2] |= buffer;
    temp[1] |= buffer >> 8;
    temp[0] |= buffer >> 16;

    hr3_hal_write( &reg, temp, 3 );

    return 0;

}

uint8_t hr3_set_tia_power( tia_pwer_t tia_power )
{
    uint8_t reg = SETTINGS;
    uint8_t temp[3] = {0};
    unsigned long buffer = 0;

    hr3_read_enable();
    hr3_hal_read( &reg, temp, 3 );
    hr3_read_disable();

    buffer |= ( tia_power << STT_DYNMC3 );
    temp[2] |= buffer;
    temp[1] |= buffer >> 8;
    temp[0] |= buffer >> 16;

    hr3_hal_write( &reg, temp, 3 );

    return 0;

}

uint8_t hr3_set_rest_of_adc( rest_of_adc_t rest_of_adc )
{
    uint8_t reg = SETTINGS;
    uint8_t temp[3] = {0};
    unsigned long buffer = 0;

    hr3_read_enable();
    hr3_hal_read( &reg, temp, 3 );
    hr3_read_disable();

    buffer |= ( rest_of_adc << STT_DYNMC4 );
    temp[2] |= buffer;
    temp[1] |= buffer >> 8;
    temp[0] |= buffer >> 16;

    hr3_hal_write( &reg, temp, 3 );

    return 0;

}

uint8_t hr3_set_afe_receive( afe_rx_mode_t afe_rx_mode )
{
    uint8_t reg = SETTINGS;
    uint8_t temp[3] = {0};
    unsigned long buffer = 0;

    hr3_read_enable();
    hr3_hal_read( &reg, temp, 3 );
    hr3_read_disable();

    buffer |= ( afe_rx_mode << STT_PDNRX );
    temp[2] |= buffer;
    temp[1] |= buffer >> 8;
    temp[0] |= buffer >> 16;

    hr3_hal_write( &reg, temp, 3 );

    return 0;

}

uint8_t hr3_set_afe_mode( afe_mode_t afe_mode )
{
    uint8_t reg = SETTINGS;
    uint8_t temp[3] = {0};
    unsigned long buffer = 0;

    hr3_read_enable();
    hr3_hal_read( &reg, temp, 3 );
    hr3_read_disable();

    buffer |= ( afe_mode << STT_PDNAFE );
    temp[2] |= buffer;
    temp[1] |= buffer >> 8;
    temp[0] |= buffer >> 16;

    hr3_hal_write( &reg, temp, 3 );

    return 0;

}

uint8_t hr3_set_clkout_div( bool enable, uint8_t div )
{
    uint8_t reg = CLKOUT;
    uint8_t temp[3] = { 0 };

    if( div > 15 )
        return -1;

    if( enable )
    {
        temp[1] = ( 1 << CLKOUT_EN );
        temp[2] = ( div << CLKOUT_DIV );
        hr3_hal_write( &reg, temp, 3 );
    }
    else
    {
        temp[2] = ( div << CLKOUT_DIV );
        hr3_hal_write( &reg, temp, 3 );
    }

    return 0;

}

uint32_t hr3_get_led1_val( void )
{
    uint8_t reg = LED1VAL;
    uint8_t temp[3] = { 0 };
    uint32_t retval = 0;

    hr3_read_enable();
    hr3_hal_read( &reg, temp, 3 );
    hr3_read_disable();

    retval |= (uint32_t)temp[0] << 16;
    retval |= (uint32_t)temp[1] << 8;
    retval |= (uint32_t)temp[2];

    if (retval & 0x00200000) 	// check if the ADC value is positive or negative
    {
        retval &= 0x003FFFFF;		// convert it to a 22 bit value
        return (retval^0xFFC00000);
    }
    return retval;

}

uint32_t hr3_get_led2_val( void )
{
    uint8_t reg = LED2VAL;
    uint8_t temp[3] = { 0 };
    uint32_t retval = 0;

    hr3_read_enable();
    hr3_hal_read( &reg, temp, 3 );
    hr3_read_disable();
    
    retval |= (uint32_t)temp[0] << 16;
    retval |= (uint32_t)temp[1] << 8;
    retval |= (uint32_t)temp[2];

    return retval;

}

uint32_t hr3_get_led3_val( void )
{
    uint8_t reg = LED3VAL;
    uint8_t temp[3] = { 0 };
    uint32_t retval = 0;
    
    hr3_read_enable();
    hr3_hal_read( &reg, temp, 3 );
    hr3_read_disable();
    
    retval |= (uint32_t)temp[0] << 16;
    retval |= (uint32_t)temp[1] << 8;
    retval |= (uint32_t)temp[2];

    return retval;

}

uint32_t hr3_get_amb1_val( void )
{
    uint8_t reg = ALED1VAL;
    uint8_t temp[3] = { 0 };
    uint32_t retval = 0;

    hr3_read_enable();
    hr3_hal_read( &reg, temp, 3 );
    hr3_read_disable();

    retval |= ( temp[0] << 16 );
    retval |= ( temp[1] << 8 );
    retval |= temp[2];

    return retval;

}

uint32_t hr3_get_led2_amb2_val( void )
{
    uint8_t reg = LED2_ALED2VAL;
    uint8_t temp[3] = { 0 };
    uint32_t retval = 0;

    hr3_read_enable();
    hr3_hal_read( &reg, temp, 3 );
    hr3_read_disable();

    retval |= ( temp[0] << 16 );
    retval |= ( temp[1] << 8 );
    retval |= temp[2];

//    if (retval & 0x800000)  // check if the ADC value is positive or negative
//    {
//      //retval &= 0x007FFFFF;   // convert it to a 22 bit value
//      return ((retval^0x7FFFFF) + 1);
//    }
//    else
//    {
//        return retval;//return ((retval^0x7FFFFF) + 1);
//    }
   
    return retval;
    

    

}

uint32_t hr3_get_led1_amb1_val( void )
{
    uint8_t reg = LED1_ALED1VAL;
    uint8_t temp[3] = { 0 };
    uint32_t retval = 0;

    hr3_read_enable();
    hr3_hal_read( &reg, temp, 3 );
    hr3_read_disable();
    
    retval |= ( temp[0] << 16 );
    retval |= ( temp[1] << 8 );
    retval |= temp[2];

//    if (retval & 0x00200000) 	// check if the ADC value is positive or negative
//    {
//        retval &= 0x003FFFFF;		// convert it to a 22 bit value
//        return (retval^0xFFC00000);
//    }
    
    if (retval & 0x800000)  // check if the ADC value is positive or negative
    {
//      retval &= 0x007FFFFF;   // convert it to a 22 bit value
//      return ((retval^0x7FFFFF) + 1);
      //return 0;
    }
    else
    {
        //return 0;//return ((retval^0x7FFFFF) + 1);
    }
   
    return retval;

}

uint8_t hr3_is_pd_shorted( void )
{
    uint8_t reg = PD_SHORT_FLAG;
    uint8_t temp[3] = { 0 };

    hr3_hal_read( &reg, temp, 3 );

    if( temp[2] == 1 )
        return -1;
    else
        return 0;

}

uint8_t hr3_set_inp_inn_settings( inm_inn_t* inp_inn_setting )
{
    uint8_t reg = PD_INP_EXT;
    uint8_t temp[3] = { 0 };

    if( inp_inn_setting->ext_div > 7 )
        return -1;

    temp[1] = ( inp_inn_setting->pd_setting << PD_DISCONNECT );
    temp[2] |= ( inp_inn_setting->short_setting << ENABLE_INPUT_SHORT );
    temp[2] |= inp_inn_setting->ext_div;
    hr3_hal_write( &reg, temp, 3 );

    return 0;

}

uint8_t hr3_set_pdn_cycle_start_end( uint16_t start, uint16_t end )
{
    uint8_t reg_st = PDNCYCLESTC;
    uint8_t reg_end = PDNCYCLEENDC;
    uint8_t temp_st[3] = { 0 };
    uint8_t temp_end[3] = { 0 };

    if( start > 65535 || end > 65535 )
        return -1;

    temp_st[1] = start >> 8;
    temp_st[2] = (uint8_t)start;

    hr3_hal_write( &reg_st, temp_st, 3 );

    temp_end[1] = end >> 8;
    temp_end[2] = (uint8_t)end;

    hr3_hal_write( &reg_end, temp_end, 3 );

    return 0;


}

uint8_t hr3_set_prgrmmbl_timing_start_end( uint16_t start, uint16_t end )
{
    uint8_t reg_st = PROG_TG_STC;
    uint8_t reg_end = PROG_TG_ENDC;
    uint8_t temp_st[3] = { 0 };
    uint8_t temp_end[3] = { 0 };

    if( start > 65535 || end > 65535 )
        return -1;

    temp_st[1] = start >> 8;
    temp_st[2] = (uint8_t)start;

    hr3_hal_write( &reg_st, temp_st, 3 );

    temp_end[1] = end >> 8;
    temp_end[2] = (uint8_t)end;

    hr3_hal_write( &reg_end, temp_end, 3 );

    return 0;


}

uint8_t hr3_set_led3_start_stop( uint16_t start, uint16_t end )
{
    uint8_t reg_st = LED3LEDSTC;
    uint8_t reg_end = LED3LEDENDC;
    uint8_t temp_st[3] = { 0 };
    uint8_t temp_end[3] = { 0 };

    if( start > 65535 || end > 65535 )
        return -1;

    temp_st[1] = start >> 8;
    temp_st[2] = (uint8_t)start;

    hr3_hal_write( &reg_st, temp_st, 3 );

    temp_end[1] = end >> 8;
    temp_end[2] = (uint8_t)end;

    hr3_hal_write( &reg_end, temp_end, 3 );

    return 0;


}

uint8_t hr3_set_int_clk_div( uint8_t div )
{
    uint8_t reg = CLKDIV_PRF;
    uint8_t temp[3] = { 0 };

    if( div > 7 )
        return -1;

    temp[2] = div;
    hr3_hal_write( &reg, temp, 3 );

    return 0;

}

uint8_t hr3_set_offdac_settings( offdac_settings_t* settings )
{
    uint8_t reg = DAC_SETTING;
    uint8_t temp[3] = { 0 };
    unsigned long buffer = 0;

    buffer |= ( settings->offdac_pol_led2 << POL_OFFDAC_LED2 );
    buffer |= ( settings->offdac_set_led2 << I_OFFDAC_LED2 );
    buffer |= ( settings->offdac_pol_amb1 << POL_OFFDAC_AMB1 );
    buffer |= ( settings->offdac_set_amb1 << I_OFFDAC_AMB1 );
    buffer |= ( settings->offdac_pol_led1 << POL_OFFDAC_LED1 );
    buffer |= ( settings->offdac_set_led1 << I_OFFDAC_LED1 );
    buffer |= ( settings->offdac_pol_amb2 << POL_OFFDAC_LED3 );
    buffer |= ( settings->offdac_set_amb2 << I_OFFDAC_LED3 );

    temp[2] |= buffer;
    temp[1] |= buffer >> 8;
    temp[0] |= buffer >> 16;


    hr3_hal_write( &reg, temp, 3 );

    return 0;

}

uint32_t hr3_calibrate( void )
{
    uint32_t retVal = 0;
//    uint32_t temp_1[10];
//    uint32_t temp_2[10];
//    uint64_t average;
//   
//    uint8_t i = 0;
//    uint8_t j = 0;
//
//    for( i = 0; i < 10; i++ )
//    {
//
//        for( j = 0; j < 10; j++ )
//        {
//            temp_2[j] = hr3_get_led1_val();
//            hr3_hal_delay(10);
//        }
//
//        average = 0;    //Reset average before finding new average
//
//        for( j = 0; j < 10; j++ )
//        {
//            average += temp_2[j];
//        }
//
//        average /= 10;
//
//        temp_1[i] = average;
//
//    }
//
//    average = 0;
//
//    for( i = 0; i < 10; i++ )
//    {
//        average += temp_1[i];
//    }
//
//    average /= 10;
//    retVal = average;

    return retVal;
}

uint8_t hr3_read_enable( void )
{
    uint8_t reg = DIAGNOSIS;
    uint8_t temp[3] = { 0 };

    temp[2] |= ( 1 << DIAG_REG_READ );

    hr3_hal_write( &reg, temp, 3 );

    return 0;

}

uint8_t hr3_read_disable( void )
{
    uint8_t reg = DIAGNOSIS;
    uint8_t temp[3] = { 0 };

    temp[2] &= ~( 1 << DIAG_REG_READ );

    hr3_hal_write( &reg, temp, 3 );

    return 0;

}

/*************** END OF FUNCTIONS ***************************************************************************/