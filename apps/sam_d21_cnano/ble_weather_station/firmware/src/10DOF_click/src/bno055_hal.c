/*******************************************************************************
* Title                 :   Hal I2C
* Filename              :   hal_i2c.c
* Author                :   MSV
* Origin Date           :   02/11/2015
* Notes                 :   None
*******************************************************************************/
/*************** MODULE REVISION LOG ******************************************
*
*    Date    Software Version    Initials   Description
*  02/11/15    XXXXXXXXXXX         MSV      Module Created.
*  22/05/2020    1.0.0               MK       Modified.
*******************************************************************************/

/****************************************************************************
* Note: In version 1.0.1, This file has been modified by MK to meet the custom 
* application requirements. Should you need to contact the modifier, Write an 
* Email to mohan.kumar@microchip.com or alternatively, write to 
* Mohan Kumar, Microchip Technology India Pvt Ltd
* Plot No. 1498, EPIP, 1st Phase Industrial Area, Whitefield, Bengaluru, 
* Karnataka 560066
*******************************************************************************/
/**
 * @file bno055_hal.c
 *
 * @brief I2C template.
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>
#include <string.h>
#include "../include/bno055_hal.h"
#include "definitions.h"
/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Static Variable Definitions
*******************************************************************************/
//static uint8_t _i2c_hw_address;

extern volatile bool flag;
#if defined( __MIKROC_PRO_FOR_ARM__ )
#if defined( STM32F030C6 ) || defined( STM32F107VC ) || defined( STM32F407VG )
static unsigned int( *start_i2c_p )( void );
static unsigned int( *write_i2c_p )( unsigned char slave_address,
                                     unsigned char *buffer,
                                     unsigned long count,
                                     unsigned long end_mode );
static void( *read_i2c_p )( unsigned char slave_address,
                            unsigned char *buffer,
                            unsigned long count,
                            unsigned long end_mode );

#elif defined( LM3S1165 ) || defined( TM4C129ENCZAD )
static void( *enable_i2c_p )( void );
static void( *disable_i2c_p )( void );
static void( *set_slave_address_i2c_p )( unsigned char slave_address,
        unsigned char dir );
static void( *write_i2c_p )( unsigned char data_out,
                             unsigned char mode );
static void( *read_i2c_p )( unsigned char *data,
                            unsigned char mode );
#endif

#elif  defined( __MIKROC_PRO_FOR_AVR__ )
static unsigned char( *busy_i2c_p )( void );
static unsigned char( *status_i2c_p )( void );
static unsigned char( *start_i2c_p )( void );
static void( *stop_i2c_p )( void );
static void( *close_i2c_p )( void );
static void( *write_i2c_p )( unsigned char data_out );
static unsigned char( *read_i2c_p )( unsigned char ack );

#elif  defined( __MIKROC_PRO_FOR_PIC__ )
static unsigned char( *is_idle_i2c_p )( void );
static unsigned char( *start_i2c_p )( void );
static void( *stop_i2c_p )( void );
static void( *restart_i2c_p )( void );
static unsigned char( *write_i2c_p )( unsigned char data_out );
static unsigned char( *read_i2c_p )( unsigned char ack );

#elif defined( __MIKROC_PRO_FOR_PIC32__ )
static unsigned int( *is_idle_i2c_p )( void );
static unsigned int( *start_i2c_p )( void );
static void( *stop_i2c_p )( void );
static unsigned int( *restart_i2c_p )( void );
static unsigned int( *write_i2c_p )( unsigned char data_out );
static unsigned char( *read_i2c_p )( unsigned int ack );

#elif defined( __MIKROC_PRO_FOR_DSPIC__ )
static unsigned int( *is_idle_i2c_p )( void );
static unsigned int( *start_i2c_p )( void );
static void( *stop_i2c_p )( void );
static void( *restart_i2c_p )( void );
static unsigned int( *write_i2c_p )( unsigned char data_out );
static unsigned char( *read_i2c_p )( unsigned int ack );

#elif defined( __MIKROC_PRO_FOR_8051__ )
static unsigned char ( *status_i2c_p )( void );
static unsigned char( *start_i2c_p )( void );
static void( *stop_i2c_p )( void );
static void( *close_i2c_p )( void );
static void( *write_i2c_p )( unsigned char data_out );
static unsigned char( *read_i2c_p )( unsigned char ack );

#elif defined( __MIKROC_PRO_FOR_FT90x__ )
static void( *soft_reset_i2c_p )( void );
static void( *set_slave_address_i2c_p )( unsigned char slave_address );
static unsigned char( *write_i2c_p )( unsigned char data_out );
static unsigned char( *read_i2c_p )( unsigned char *data_in );
static unsigned char( *write_bytes_i2c_p )( unsigned char *buffer,
        unsigned int count );
static unsigned char( *read_bytes_i2c_p )( unsigned char *buffer,
        unsigned int count );
static unsigned char( *write_10bit_i2c_p )( unsigned char data_out,
        unsigned int address_10bit );
static unsigned char( *read_10bit_i2c_p )( unsigned char *data_in,
        unsigned int address_10bit );
#endif



/******************************************************************************
* Module Variable Definitions
*******************************************************************************/
#if   defined( __MIKROC_PRO_FOR_ARM__ )
#elif defined( __MIKROC_PRO_FOR_AVR__ )
#elif defined( __MIKROC_PRO_FOR_PIC__ )
#elif defined( __MIKROC_PRO_FOR_PIC32__ )
#elif defined( __MIKROC_PRO_FOR_DSPIC__ )
#elif defined( __MIKROC_PRO_FOR_8051__ )
#elif defined( __MIKROC_PRO_FOR_FT90x__ )
extern sfr sbit CLICK_PIN_1;
#endif
/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
void bno_hal_init()
{
#if defined( __MIKROC_PRO_FOR_ARM__ )
#if defined( STM32F030C6 ) || defined( STM32F107VC ) || defined( STM32F407VG )
    start_i2c_p = I2C_Start_Ptr;
    write_i2c_p = I2C_Write_Ptr;
    read_i2c_p = I2C_Read_Ptr;

#elif defined( LM3S1165 ) || defined( TM4C129ENCZAD )
    enable_i2c_p = I2C_Enable_Ptr;
    disable_i2c_p = I2C_Disable_Ptr;
    set_slave_address_i2c_p = I2C_Master_Slave_Addr_Set_Ptr;
    write_i2c_p = I2C_Write_Ptr;
    read_i2c_p = I2C_Read_Ptr;
#endif

#elif defined( __MIKROC_PRO_FOR_AVR__ )
#if defined( ATMEGA32 )
    busy_i2c_p = TWI_Busy;
    status_i2c_p = TWI_Status;
    close_i2c_p = TWI_Close;
    start_i2c_p = TWI_Start;
    stop_i2c_p = TWI_Stop;
    write_i2c_p = TWI_Write;
    read_i2c_p = TWI_Read;
#elif defined( ATXMEGA32A4 )
    busy_i2c_p = TWIC_Busy;
    status_i2c_p = TWIC_Status;
    close_i2c_p = TWIC_Close;
    start_i2c_p = TWIC_Start;
    stop_i2c_p = TWIC_Stop;
    write_i2c_p = TWIC_Write;
    read_i2c_p = TWIC_Read;
#endif

#elif defined( __MIKROC_PRO_FOR_PIC__ )
    is_idle_i2c_p = I2C1_Is_Idle;
    start_i2c_p = I2C1_Start;
    stop_i2c_p = I2C1_Stop;
    restart_i2c_p = I2C1_Repeated_Start;
    write_i2c_p = I2C1_Wr;
    read_i2c_p = I2C1_Rd;

#elif defined( __MIKROC_PRO_FOR_PIC32__ )
    is_idle_i2c_p = I2C_Is_Idle_Ptr;
    start_i2c_p = I2C_Start_Ptr;
    stop_i2c_p = I2C_Stop_Ptr;
    restart_i2c_p = I2C_Restart_Ptr;
    write_i2c_p = I2C_Write_Ptr;
    read_i2c_p = I2C_Read_Ptr;

#elif defined( __MIKROC_PRO_FOR_DSPIC__ )
    is_idle_i2c_p = I2C1_Is_Idle;
    start_i2c_p = I2C1_Start;
    stop_i2c_p = I2C1_Stop;
    restart_i2c_p = I2C1_Restart;
    write_i2c_p = I2C1_Write;
    read_i2c_p = I2C1_Read;

#elif defined( __MIKROC_PRO_FOR_8051__ )
    status_i2c_p = TWI_Status;
    close_i2c_p = TWI_Close;
    start_i2c_p = TWI_Start;
    stop_i2c_p = TWI_Stop;
    write_i2c_p = TWI_Write;
    read_i2c_p = TWI_Read;

#elif defined( __MIKROC_PRO_FOR_FT90x__ )
    soft_reset_i2c_p = I2CM_Soft_Reset_Ptr;
    set_slave_address_i2c_p = I2CM_Set_Slave_Address_Ptr;
    write_i2c_p = I2CM_Write_Ptr;
    read_i2c_p = I2CM_Read_Ptr;
    write_bytes_i2c_p = I2CM_Write_Bytes_Ptr;
    read_bytes_i2c_p = I2CM_Read_Bytes_Ptr;
    write_10bit_i2c_p = I2CM_Write_10Bit_Ptr;
    read_10bit_i2c_p = I2CM_Read_10Bit_Ptr;
#endif

}


void bno_delay_ms( uint32_t delay_time )
{
   while( delay_time-- )
       SYSTICK_DelayMs(1);
//#if defined( __GNUC__ )
//    printf( "Delay" );
//#else
//      // Delay_1ms(); 
//       SYSTICK_DelayMs(1);
//#endif
}

int8_t bno_hal_read( uint8_t address, uint8_t reg_address, uint8_t *data_out,
                  uint8_t data_size )
{    
     SERCOM2_I2C_WriteRead(address, &reg_address, 1,  data_out, data_size);
     
     while(flag != 1);
     
     flag = 0;

#if defined(__MIKROC_PRO_FOR_ARM__)
#if defined( STM32F030C6 ) || defined( STM32F107VC ) || defined( STM32F407VG )
    start_i2c_p();
    write_i2c_p( address, buffer, 1, END_MODE_RESTART );
    read_i2c_p( address, data_out, data_size, END_MODE_STOP );

#elif defined( LM3S1165 ) || defined( TM4C129ENCZAD )
    set_slave_address_i2c_p( _i2c_hw_address, _I2C_DIR_MASTER_TRANSMIT );
    write_i2c_p( address, _I2C_MASTER_MODE_SINGLE_SEND );

    set_slave_address_i2c_p( _i2c_hw_address, _I2C_DIR_MASTER_RECEIVE );
    if( count == 1 )
        read_i2c_p( buffer, _I2C_MASTER_MODE_BURST_SINGLE_RECEIVE );

    else
    {

        read_i2c_p( buffer++ , _I2C_MASTER_MODE_BURST_RECEIVE_START ) )
        count--;

        while( count > 1 )
    {
        read_i2c_p( buffer++ , _I2C_MASTER_MODE_BURST_SEND_CONT );
            count--;
        }

        read_i2c_p( buffer ), _I2C_MASTER_MODE_BURST_SEND_FINISH );
    }
#endif

#elif defined(__MIKROC_PRO_FOR_FT90x__)
    set_slave_address_i2c_p( address );
    write_i2c_p( reg_address );
    read_bytes_i2c_p( data_out, data_size );

#elif defined( __MIKROC_PRO_FOR_AVR__ )    || \
      defined( __MIKROC_PRO_FOR_PIC32__ )  || \
      defined( __MIKROC_PRO_FOR_8051__ )

    start_i2c_p();
    write_i2c_p( _i2c_hw_address | WRITE );
    write_i2c_p( address );
    stop_i2c_p();
    start_i2c_p();
    write_i2c_p( _i2c_hw_address | READ );

    if( data_size == 1 )
    {
        *bfr_ptr = read_i2c_p( 0 );
        stop_i2c_p();

    }
    else
    {

        while( data_size > 1 )
        {
            *( bfr_ptr++ ) = read_i2c_p( 1 );
            data_size--;
        }

        *bfr_ptr = read_i2c_p( 0 );
        stop_i2c_p();
    }

#elif defined(__MIKROC_PRO_FOR_PIC__)  || \
      defined(__MIKROC_PRO_FOR_DSPIC__)
    start_i2c_p();
    write_i2c_p( _i2c_hw_address | WRITE );
    write_i2c_p( address );
    restart_i2c_p();
    write_i2c_p( _i2c_hw_address | READ );

    if( count == 1 )
    {
        *buffer = read_i2c_p( 0 );
        stop_i2c_p();

    }
    else
    {

        while( count > 1 )
        {
            *( buffer++ ) = read_i2c_p( 1 );
            count--;
        }

        *buffer = read_i2c_p( 0 );
        stop_i2c_p();
    }
#endif
      return 0;
}

int8_t bno_hal_write( uint8_t address, uint8_t reg_address, uint8_t *data_in,
                   uint8_t data_size )
{
    uint8_t temp_buff[ MAX_BUFFER_SIZE ];
    uint8_t *temp_ptr = data_in;

    temp_buff[0] = reg_address;
    memcpy( &temp_buff[1], temp_ptr, data_size );
    
    SERCOM2_I2C_Write(address,temp_buff,data_size+1);
    
    while(flag != 1);
     
    flag = 0;

#if defined(__MIKROC_PRO_FOR_ARM__)
#if defined( STM32F030C6 ) || defined( STM32F107VC ) || defined( STM32F407VG )
    start_i2c_p();
    write_i2c_p( address, temp_buff, data_size + 1, END_MODE_STOP );

#elif defined( LM3S1165 ) || defined( TM4C129ENCZAD )
    set_slave_address_i2c_p( _i2c_hw_address, _I2C_DIR_MASTER_TRANSMIT );
    write_i2c_p( * ( temp_buff++ ),  _I2C_MASTER_MODE_BURST_SEND_START );

    if( count = 1 )
        write_i2c_p( *temp_buff , _I2C_MASTER_MODE_BURST_SEND_FINISH );

    else
    {

        while( count > 1 )
        {
            write_i2c_p( *( temp_buff++ ), _I2C_MASTER_MODE_BURST_SEND_CONT );
            count--;
        }
        write_i2c_p( *temp_buff , _I2C_MASTER_MODE_BURST_SEND_FINISH );
    }
#endif

#elif defined(__MIKROC_PRO_FOR_FT90x__)
    set_slave_address_i2c_p( address );
    write_bytes_i2c_p( temp_buff, data_size + 1 );

#elif defined(__MIKROC_PRO_FOR_AVR__)   || \
      defined(__MIKROC_PRO_FOR_8051__)  || \
      defined(__MIKROC_PRO_FOR_DSPIC__) || \
      defined(__MIKROC_PRO_FOR_PIC32__) || \
      defined(__MIKROC_PRO_FOR_PIC__)

    data_size += 1;

    start_i2c_p();
    write_i2c_p( _i2c_hw_address | WRITE );

    while( data_size-- )
        write_i2c_p( *( temp_buff_ptr++ ) );

    stop_i2c_p();
#endif
    return 0;
}
/*************** END OF FUNCTIONS *********************************************/