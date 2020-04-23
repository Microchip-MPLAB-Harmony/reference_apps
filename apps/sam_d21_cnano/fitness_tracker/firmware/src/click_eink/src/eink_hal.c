/**
 * SPI_hal.c
 *
 * Version : 1.0.1
 *
 * Revision Log :
 * 0.0.1 (Sep/2015) Module created                                Richard Lowe
 * 0.0.2 (Sep/2016) Documentation added                     Milos Vidojevic
 * 1.0.0 (Dec/2016) Major Updates                           Milos Vidojevic
 *                - Pin definitions removed for HAL layer.
 *                - Delay ms function added
 * 1.0.2 (Jan/2020) Modified                                MK
 * To Do List :
 *                 - GPIO HAL needed
 *                 - Delay us
 *
 ******************************************************************************/

/****************************************************************************
* Note: In version 1.0.2, This file has been modified by MK to meet the custom 
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

#include "../include/eink_hal.h"
#include "definitions.h"  
/*                Variables
 ******************************************************************************/
#if defined( __MIKROC_PRO_FOR_ARM__ )   || \
    defined( __MIKROC_PRO_FOR_DSPIC__ )
static void         ( *write_spi_p )            ( unsigned int data_out );
static unsigned int ( *read_spi_p )             ( unsigned int buffer );

#elif defined( __MIKROC_PRO_FOR_AVR__ )     || \
      defined( __MIKROC_PRO_FOR_PIC__ )     || \
      defined( __MIKROC_PRO_FOR_8051__ )
static void         ( *write_spi_p )            ( unsigned char data_out );
static unsigned char( *read_spi_p )             ( unsigned char dummy );

#elif defined( __MIKROC_PRO_FOR_PIC32__ )
static void         ( *write_spi_p )            ( unsigned long data_out );
static unsigned long( *read_spi_p )             ( unsigned long dummy );

#elif defined( __MIKROC_PRO_FOR_FT90x__ )
static void         ( *write_spi_p )            ( unsigned char data_out );
static unsigned char( *read_spi_p )             ( unsigned char dummy );
#endif

/*                Public Function Definitions
 ******************************************************************************/

void hal_eink_delay( uint16_t ms )
{
#if defined(__MIKROC_PRO_FOR_ARM__)     || \
    defined( __MIKROC_PRO_FOR_FT90x__ ) || \
    defined( __MIKROC_PRO_FOR_AVR__ )   || \
    defined( __MIKROC_PRO_FOR_8051__ )  || \
    defined( __MIKROC_PRO_FOR_DSPIC__ ) || \
    defined( __MIKROC_PRO_FOR_PIC32__ ) || \
    defined( __MIKROC_PRO_FOR_PIC__ )
    while( ms-- )
        Delay_1ms();
#endif
    SYSTICK_DelayMs(ms);
    
}

void hal_eink_init()
{
#if defined( __MIKROC_PRO_FOR_ARM__ )   || \
    defined( __MIKROC_PRO_FOR_AVR__ )   || \
    defined( __MIKROC_PRO_FOR_DSPIC__ ) || \
    defined( __MIKROC_PRO_FOR_PIC32__ ) || \
    defined( __MIKROC_PRO_FOR_8051__ )
    write_spi_p                 = SPI_Wr_Ptr;
    read_spi_p                  = SPI_Rd_Ptr;

#elif defined( __MIKROC_PRO_FOR_PIC__ )
    write_spi_p             = SPI1_Write;
    read_spi_p              = SPI1_Read;

#elif defined( __MIKROC_PRO_FOR_FT90x__ )
    write_spi_p             = SPIM_Wr_Ptr;
    read_spi_p              = SPIM_Rd_Ptr;
#endif
}
extern volatile bool isTransferDone;
extern APP_DATA appData;
void hal_eink_write
(
        uint8_t* buffer,
        uint16_t count
)
{
    DRV_SPI_WriteTransferAdd(appData.drvSPIHandle, buffer, count, &appData.transferHandle);
}

void hal_eink_read
(
        uint8_t* buffer,
        uint16_t count
)
{
    DRV_SPI_ReadTransferAdd(appData.drvSPIHandle, buffer, count, &appData.transferHandle);
}

void hal_eink_transfer
(
        uint8_t* input,
        uint8_t* output,
        uint16_t count
)
{
    DRV_SPI_WriteReadTransferAdd(appData.drvSPIHandle,input,count,output,count,&appData.transferHandle);
}

/*                                                              End of File
 ******************************************************************************/