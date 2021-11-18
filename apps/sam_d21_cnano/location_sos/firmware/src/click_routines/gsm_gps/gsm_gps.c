/****************************************************************************
* Title                 :   GSM GPS
* Filename              :   gsm_gps.c
* Author                :   MSV
* Origin Date           :   10/03/2016
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials   Description
*  10/03/16        1.0.0           MSV      App Created.
*  15/02/18        2.0.0           ST       App Customized.
*  01/01/2020      3.0.0           MK       Custom Application
*  05/07/2021      4.0.0           ST       Custom Application
*****************************************************************************/
/****************************************************************************
* Note: In version 2.00, 3.00, 4.00 This file has been modified to meet the custom
* application requirements. Should you need to contact the modifier write to
* 32-bit Applications group, Microchip Technology India Pvt Ltd
* Plot No. 1498, EPIP, 1st Phase Industrial Area, Whitefield, Bengaluru,
* Karnataka 560066
*******************************************************************************/
//DOM-IGNORE-BEGIN 
/*******************************************************************************
 Copyright (C) 2021  Microchip Technology Incorporated and its subsidiaries.

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
//DOM-IGNORE-END 

/******************************************************************************
* Includes
*******************************************************************************/
#include "definitions.h"                // SYS function prototypes
#include "../click_interface.h"
#include "gsm_gps_dev_hal.h"
#include "gsm_gps.h"


/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/
#define M_CMD_MSG_HEADER        ("AT+CMGS=")
#define M_CRLF                  ("\r\n")
#define M_CR                    ("\r")
#define M_QUOTES                ("\"")
#define M_CMD_MSG_END           (26)

/******************************************************************************
* Module Typedefs
*******************************************************************************/
/* AT parser typedefs
*******************************************************************************/
/**
 * @enum at_ctl_t
 * @brief AT Command Type
 */
typedef enum
{
    /**
     * Unknown command */
    AT_CMD_UNKNOWN                              = 0,
    /**
     * AT Get command */
    AT_CMD_GET                                  = 1,
    /**
     * AT Set command */
    AT_CMD_SET                                  = 2,
    /**
     * AT Test command */
    AT_CMD_TEST                                 = 3,
    /**
     * AT Execute command */
    AT_CMD_EXEC                                 = 4,

}at_type_t;

/**
 * @struct at_cmd_t
 * @brief Parser Structure
 *
 * @par
 * This struct is used for storing the command with timeout and callbacks.
 * Command strings are converted to the hash code for easiest comparision.
 */
typedef struct
{
    /**
     * Command Hash Value */
    uint32_t                hash;
    /**
     * Command Timeout */
    uint32_t                timeout;
    /**
     * Get Callback */
    at_cmd_cb               getter;
    /**
     * Set Callback */
    at_cmd_cb               setter;
    /**
     * Test Callback */
    at_cmd_cb               tester;
    /**
     * Execute Callback */
    at_cmd_cb               executer;

}at_cmd_t;
/******************************************************************************
* Module Variable Definitions
*******************************************************************************/
/* Flags
 ******************************************************************************/
static long latt = -1;
static long lonn = -1;
static long altt = -1;
static char latitude[ 10 ] = { 0 };
static char longitude[ 10 ] = { 0 };
static char altitude[ 9 ] = { 0 };

static bool req_pend_f = false;
static bool loc_update_f = false;


static char _at_command[ 100 ] = { 0 };
static char _at_data[ 700 ] = { 0 };

/* AT engine variable Definitions
*******************************************************************************/
/* TEMPS */
static uint32_t     temp_timer;
static at_cmd_cb    temp_cb;

/* FLAGS */
volatile bool       timeout_f;
volatile bool       exception_f;
volatile bool       response_f;
volatile bool       cue_f;

/* CALLBACKS */
static at_cmd_cb    cb;
static at_cmd_cb    cb_default;

/* BUFFERS */
char                tx_buffer[ AT_TRANSFER_SIZE ];
char                rx_buffer[ AT_TRANSFER_SIZE ];

/* AT parser variable definitions
*******************************************************************************/
static uint8_t              header_size;
static uint8_t              at_cmd_storage_used;
static volatile at_cmd_t    at_cmd_storage      [ AT_STORAGE_SIZE ];

/******************************************************************************
* Function Prototypes
*******************************************************************************/
/* Event handlers
 ******************************************************************************/
static void _gsm_gps_evn_location (char *response );
static void _gsm_gps_evn_default (char *response);
//static void _gsm_ev_ring (char *response);
//static void _gsm_evn_call_id (char *response);
/* Actions
 ******************************************************************************/
//static void _gsm_act_read_info (void);
static void _gsm_act_send_info (void);
static void _gps_act_pwr_control (bool state);

/* AT engine functions
*******************************************************************************/
static void _gsm_gps_engine_init (at_cmd_cb default_callback);
static void _gsm_gps_at_cmd(char *input);
static void _gsm_gps_at_cmd_addition (char *input);
static void _gsm_gps_at_cmd_save ( char *cmd, uint32_t timeout, at_cmd_cb getter,
        at_cmd_cb setter, at_cmd_cb tester, at_cmd_cb executer);
static void _gsm_gps_at_process (void);

/* AT parser functions
*******************************************************************************/
static uint32_t _gsm_gps_at_hash (char *cmd);
static uint16_t _gsm_gps_at_search(char* cmd);
static at_type_t _gsm_gps_at_sub_parse(char *raw_in, char *clean_out);
static char* _gsm_gps_my_strncpy(char* dst, const char* src, size_t n);
static void _gsm_gps_at_parser_init (void);
static void _gsm_gps_at_parser_store (char *command,uint32_t timeout,
        			  at_cmd_cb getter, at_cmd_cb setter,
        			  at_cmd_cb tester, at_cmd_cb execute);
static void _gsm_gps_at_parse ( char *input, at_cmd_cb *cb, uint32_t *timeout);

/******************************************************************************
* Private Function Definitions
*******************************************************************************/
static void _gsm_gps_evn_location (char *response )
{
    char* end;
    end = strchr( response + 66, ',' );

    if(end != NULL)
    {
        if( *( end - 1 ) != ',' )
        {
            _gsm_gps_my_strncpy( latitude, response + 46, 9 );
            _gsm_gps_my_strncpy( longitude, response + 56, 9 );
            _gsm_gps_my_strncpy( altitude, response + 66, end - ( response + 66 ) );
            latt = atol( latitude );
            lonn = atol( longitude );
            altt = atol( altitude );
            if(latt <= 0 ||  lonn <= 0 || altt <= 0)
            {
                loc_update_f = true;
            }
            else
            {
                req_pend_f = true;
                latt = -1;
                lonn = -1;
                altt = -1;
            }
        }
        else
        {
            strcpy( latitude, "NA" );
            strcpy( longitude, "NA" );
            strcpy( altitude, "NA" );
            loc_update_f = true;
        }
    }
    else
    {
        loc_update_f = true;
    }
}

static void _gsm_gps_evn_default (char *response)
{
}

#if 0
static void _gsm_ev_ring (char *response)
{
    ring_f = true;
}

static void _gsm_evn_call_id (char *response)
{
    char *tmp_s = strchr( response, '\"' );
    char *tmp_e = strchr( tmp_s + 1, '\"' );

    strncpy( tmp_num, tmp_s , tmp_e - tmp_s + 1 );

}

static void _gsm_act_read_info (void)
{
    char tmp[ 60 ] = { 0 };
    strcpy( tmp, "AT+CMGR=" );
    _gsm_gps_at_cmd( tmp );
}
#endif


static void _gsm_act_send_info (void)
{
    _gsm_gps_at_cmd( _at_command );
    CLICK_GSM_GPS_DelayMs(10);
    _gsm_gps_at_cmd_addition( _at_data );
}

static void _gps_act_pwr_control (bool state)
{
    if( state )
    {
        _gsm_gps_at_cmd( "AT+CGNSPWR=1" );
    }
    else
        _gsm_gps_at_cmd( "AT+CGNSPWR=0" );
}

/* AT engine functions
*******************************************************************************/
static void _gsm_gps_engine_init (at_cmd_cb default_callback)
{
    dev_timer_init();
    _gsm_gps_at_parser_init();

    cb_default = default_callback;
    _gsm_gps_at_cmd_save( "+CMS ERROR :", AT_DEFAULT_TIMEOUT, default_callback,
                                                  default_callback,
                                                  default_callback,
                                                  default_callback );

    exception_f   = false;
    response_f    = false;
    cue_f         = false;

    memset( ( void* )tx_buffer, 0, AT_TRANSFER_SIZE );
}

static void _gsm_gps_at_cmd(char *input)
{
    char* temp_input = input;

    _gsm_gps_at_parse( temp_input, &temp_cb, &temp_timer );
    dev_timer_load( temp_timer );

    while( cue_f )
        _gsm_gps_at_process();

    while( !dev_tx( *( temp_input++ ) ) );

    dev_adapter_reset();
    dev_timer_start();

}

static void _gsm_gps_at_cmd_addition (char *input)
{
    char* temp_input = input;

    while( !exception_f )
        _gsm_gps_at_process();

    dev_timer_stop();

    while( !dev_tx( *( temp_input++ ) ) );

    dev_adapter_reset();
    dev_timer_restart();
}

static void _gsm_gps_at_cmd_save ( char *cmd, uint32_t timeout, at_cmd_cb getter,
        at_cmd_cb setter, at_cmd_cb tester, at_cmd_cb executer)
{
    if ( !setter )
        setter = cb_default;

    if( !getter )
        getter = cb_default;

    if( !tester )
        tester = cb_default;

    if( !executer )
        executer = cb_default;

    if( !timeout )
        timeout = AT_DEFAULT_TIMEOUT;

    _gsm_gps_at_parser_store( cmd, timeout, getter, setter, tester, executer );
}

static void _gsm_gps_at_process (void)
{
    //response_f = true;
    if( response_f )
    {
        dev_hal_cts_ctl( false );
        dev_timer_stop();
        _gsm_gps_at_parse( rx_buffer, &cb, &temp_timer );
        cb( rx_buffer );
        dev_adapter_reset();

        timeout_f = false;
        exception_f = false;
        response_f = false;
        cue_f = false;
    }

    if( timeout_f )
    {
        dev_hal_cts_ctl( false );
        dev_timer_stop();
        _gsm_gps_at_parse( rx_buffer, &cb, &temp_timer );
        cb( rx_buffer );
        dev_adapter_reset();

        timeout_f = false;
        exception_f = false;
        response_f = true;
        cue_f = false;
    }
}

/* AT parser functions
*******************************************************************************/
static uint32_t _gsm_gps_at_hash (char *cmd)
{
    uint16_t ch     = 0;
    uint32_t hash   = 4321;

    while( ( ch = *( cmd++ ) ) )
        hash = ( ( hash << 5 ) + hash ) + ch;

    return hash;
}

static uint16_t _gsm_gps_at_search (char* cmd)
{
    uint16_t i;
    uint32_t tmp_hash = _gsm_gps_at_hash( cmd );

    for( i = 0; i < at_cmd_storage_used; i++ )
        if( at_cmd_storage[ i ].hash == tmp_hash )
            return i;

    return 0;
}

static at_type_t _gsm_gps_at_sub_parse (char *raw_in, char *clean_out)
{
    uint8_t     c                         = 0;
    uint8_t     end_pos                   = 0;
    uint8_t     set_pos                   = 0;
    uint8_t     get_pos                   = 0;
    uint8_t     start_pos                 = 0;
    char*       tmp_ptr                   = raw_in;
    char        tmp_cmd[ AT_HEADER_SIZE ] = { 0 };

    if( strlen( tmp_ptr ) <= AT_HEAD_SIZE )
        return AT_CMD_UNKNOWN;

    _gsm_gps_my_strncpy( tmp_cmd, tmp_ptr, AT_HEADER_SIZE );

    for( c = 0; c < AT_HEADER_SIZE; c++ )
    {
        if( tmp_cmd[ c ] == '\0' )
        {
            if( !end_pos )
                end_pos = c;
            break;
        }

        if( ( tmp_cmd[ c ] == '+') && !start_pos )
            start_pos = c;

        if( ( tmp_cmd[ c ] == '=' ) && !set_pos )
            set_pos = c;

        if( ( tmp_cmd[ c ] == '?' ) && !get_pos )
            get_pos = c;

        if( ( ( tmp_cmd[ c ] == '\r' )  ||
              ( tmp_cmd[ c ] == '\n' )  ||
              ( tmp_cmd[ c ] == ':' ) ) && !end_pos )
            end_pos = c;
    }

    if( !set_pos && !get_pos )
    {
        _gsm_gps_my_strncpy( clean_out, &tmp_cmd[ start_pos ], end_pos - start_pos );
        return AT_CMD_EXEC;

    } else if( !set_pos && get_pos ) {

        _gsm_gps_my_strncpy( clean_out, &tmp_cmd[ start_pos ], get_pos - start_pos );
        return AT_CMD_TEST;

    } else if( set_pos && !get_pos ) {

        _gsm_gps_my_strncpy( clean_out, &tmp_cmd[ start_pos ], set_pos - start_pos );
        return AT_CMD_SET;

    } else if( set_pos == get_pos - 1 ) {

        _gsm_gps_my_strncpy( clean_out, &tmp_cmd[ start_pos ], set_pos - start_pos );
        return AT_CMD_GET;
    }
    return AT_CMD_UNKNOWN;
}

static char* _gsm_gps_my_strncpy(char* dst, const char* src, size_t n)
{
	if (dst == NULL)
		return NULL;

	char* ptr = dst;

	while (*src && n--)
	{
		*dst = *src;
		dst++;
		src++;
	}

	*dst = '\0';

	return ptr;
}

static void _gsm_gps_at_parser_init ( void)
{
    uint8_t c;

    header_size         = strlen( ( char* )AT_HEAD );
    at_cmd_storage_used = 0;

    for( c = 0; c < AT_STORAGE_SIZE; c++ )
    {
        at_cmd_storage[ c ].hash     = 0;
        at_cmd_storage[ c ].timeout  = 0;
        at_cmd_storage[ c ].getter   = NULL;
        at_cmd_storage[ c ].setter   = NULL;
        at_cmd_storage[ c ].tester   = NULL;
        at_cmd_storage[ c ].executer = NULL;
    }
}

static void _gsm_gps_at_parser_store (
		char *command,
        uint32_t timeout,
        at_cmd_cb getter,
        at_cmd_cb setter,
        at_cmd_cb tester,
        at_cmd_cb executer
)
{
    at_cmd_t cmd;

    cmd.hash        = _gsm_gps_at_hash( command );
    cmd.timeout     = timeout;
    cmd.getter      = getter;
    cmd.setter      = setter;
    cmd.tester      = tester;
    cmd.executer    = executer;

    if( strlen( command ) >= AT_HEADER_SIZE + header_size )
        return;

    if( at_cmd_storage_used == AT_STORAGE_SIZE )
        return;

    if( _gsm_gps_at_search( command ) )
        return;

    at_cmd_storage[ at_cmd_storage_used ] = cmd;
    at_cmd_storage_used++;
}

static void _gsm_gps_at_parse
(
		char *input,
        at_cmd_cb *cb,
        uint32_t *timeout
)
{
    at_type_t   cmd_type                    = 0;
    uint16_t    cmd_idx                     = 0;
    char        cmd_temp[ AT_HEADER_SIZE ]  = { 0 };

    if( !( cmd_type = _gsm_gps_at_sub_parse( input, cmd_temp ) ) )
    {
        *cb = at_cmd_storage[ 0 ].tester;
        *timeout = at_cmd_storage[ 0 ].timeout;
        return;
    }

    if( !( cmd_idx = _gsm_gps_at_search( cmd_temp ) ) )
    {
        *cb = at_cmd_storage[ 0 ].tester;
        *timeout = at_cmd_storage[ 0 ].timeout;
        return;
    }

    switch ( cmd_type )
    {
        case AT_CMD_SET :
            *cb = at_cmd_storage[ cmd_idx ].setter;
            *timeout = at_cmd_storage[ cmd_idx ].timeout;
        break;
        case AT_CMD_GET :
            *cb = at_cmd_storage[ cmd_idx ].getter;
            *timeout = at_cmd_storage[ cmd_idx ].timeout;
        break;
        case AT_CMD_TEST :
            *cb = at_cmd_storage[ cmd_idx ].tester;
            *timeout = at_cmd_storage[ cmd_idx ].timeout;
        break;
        case AT_CMD_EXEC :
            *cb = at_cmd_storage[ cmd_idx ].executer;
            *timeout = at_cmd_storage[ cmd_idx ].timeout;
        break;
        case AT_CMD_UNKNOWN :
            *cb = at_cmd_storage[ 0 ].executer;
            *timeout = at_cmd_storage[ 0 ].timeout;
        break;
    }
    return;
}

volatile char rxChar ; 
static void _APP_UART_ReceiveCallback(uintptr_t context)
{
    CLICK_GSM_GPS_USART_Read((void*)&rxChar,1);
    dev_rx( rxChar);
}

static void _APP_UART_WriteCallback(uintptr_t context)
{
    CLICK_GSM_GPS_USART_Read((void*)&rxChar,1);
    dev_rx( rxChar);
}

/******************************************************************************
* Public Function Definitions
*******************************************************************************/
void gsm_gps_init (void)
{
    CLICK_GSM_GPS_TimerStart();
	CLICK_GSM_GPS_DelayMs(300);
	dev_tick_isr();
	dev_hal_init();
	dev_hal_pwr_ctl(1);
	CLICK_GSM_GPS_DelayMs(1000);
	dev_hal_pwr_ctl(0);
	CLICK_GSM_GPS_DelayMs(5000);
	dev_adapter_init();
    
    CLICK_GSM_GPS_USART_WriteCallbackRegister(&_APP_UART_WriteCallback,(uintptr_t)NULL);
    CLICK_GSM_GPS_USART_ReadCallbackRegister(&_APP_UART_ReceiveCallback,(uintptr_t)NULL);

    _gsm_gps_engine_init( _gsm_gps_evn_default );
    _gsm_gps_at_cmd_save( "+CGNSINF", 1000, NULL, NULL, NULL, _gsm_gps_evn_location );
    _gps_act_pwr_control( true );
    _gsm_gps_at_cmd( "AT+CGNSINF" );
    _gsm_gps_at_cmd( "AT" );
    _gsm_gps_at_cmd( "AT+CSCS=\"GSM\"" );
    _gsm_gps_at_cmd( "AT+CMGF=1" );

    loc_update_f = true;
    req_pend_f = true;

}

bool gsm_gps_get_location_data(char *lat, char *lon, char *alt)
{
	if(req_pend_f)
	{
		strcpy( lat, latitude );
		strcpy( lon, longitude );
		strcpy( alt, altitude );
	}
	return req_pend_f;
}


void gsm_gps_setup_sms_msg(char *mobile_number, char *message)
{
    uint16_t n=0;

    memset(_at_command,0,sizeof(_at_command));
    memset(_at_data,0,sizeof(_at_data));

	strcpy(_at_command, "AT+CMGS=" );
    strcat(_at_command, M_QUOTES );
 	strcat(_at_command, mobile_number );
 	strcat(_at_command, M_QUOTES);
    strcat(_at_command, M_CR);
    printf("%s",message);
	strcpy(_at_data, message);
 	n = strlen(message);
    message[n-1]=26;
}

void gsm_gps_task (void)
{  
    _gsm_gps_at_process();
    if (loc_update_f)
    { 
        _gsm_gps_at_cmd( "AT+CGNSINF" );
    }  
}

void gsm_gps_send_msg(void)
{
    if (req_pend_f)
    {
        CLICK_GSM_GPS_DelayMs(50);
        _gsm_act_send_info();
        loc_update_f = true;
        req_pend_f = false;
        CLICK_GSM_GPS_DelayMs(100);
    }
}







/*************** END OF FUNCTIONS *********************************************/