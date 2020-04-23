/****************************************************************************
* Title                 :   AT PARSER
* Filename              :   at_parser.c
* Author                :   MSV
* Origin Date           :   10/03/2016
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials   Description
*  10/03/16        1.0.0           MSV      Interface Created.
*  15/02/18        2.0.0           ST       Custom Application 
* 01/01/2020      3.0.0           MK       Custom Application
*****************************************************************************/
/****************************************************************************
* Note: In version 3.00, This file has been modified by MK to meet the custom 
* application requirements. Should you need to contact the modifier, Write an 
* Email to mohan.kumar@microchip.com or alternatively, write to 
* Mohan Kumar, Microchip Technology India Pvt Ltd
* Plot No. 1498, EPIP, 1st Phase Industrial Area, Whitefield, Bengaluru, 
* Karnataka 560066
* Note: In version 2.00, This file has been modified by ST to meet the custom 
* application requirements. Should you need to contact the modifier, Write an 
* Email to syed.thaseemuddin@microchip.com or alternatively, write to 
* Syed Thaseemuddin, Microchip Technology India Pvt Ltd
* Plot No. 1498, EPIP, 1st Phase Industrial Area, Whitefield, Bengaluru, 
* Karnataka 560066
*******************************************************************************/
/**
 * @file at_parser.c
 * @brief AT Parser
 */
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

#include "at_parser.h"
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
* Module Variable Definitions
*******************************************************************************/

static uint8_t              header_size;
static uint8_t              at_cmd_storage_used;
static volatile at_cmd_t    at_cmd_storage      [ AT_STORAGE_SIZE ];

/******************************************************************************
* Function Prototypes
*******************************************************************************/

static uint32_t _at_hash
(
		char *cmd
);

static uint16_t _at_search
(
		char* cmd
);

static at_type_t _at_sub_parse
(
		char *raw_in,
		char *clean_out
);

/******************************************************************************
* Private Function Definitions
*******************************************************************************/

static uint32_t _at_hash
(
		char *cmd
)
{
    uint16_t ch     = 0;
    uint32_t hash   = 4321;

    while( ( ch = *( cmd++ ) ) )
        hash = ( ( hash << 5 ) + hash ) + ch;

    return hash;
}

static uint16_t _at_search
(
		char* cmd
)
{
    uint16_t i;
    uint32_t tmp_hash = _at_hash( cmd );

    for( i = 0; i < at_cmd_storage_used; i++ )
        if( at_cmd_storage[ i ].hash == tmp_hash )
            return i;

    return 0;
}

static at_type_t _at_sub_parse
(
		char *raw_in,
        char *clean_out
)
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

    my_strncpy( tmp_cmd, tmp_ptr, AT_HEADER_SIZE );

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
        my_strncpy( clean_out, &tmp_cmd[ start_pos ], end_pos - start_pos );
        return AT_CMD_EXEC;

    } else if( !set_pos && get_pos ) {

        my_strncpy( clean_out, &tmp_cmd[ start_pos ], get_pos - start_pos );
        return AT_CMD_TEST;

    } else if( set_pos && !get_pos ) {

        my_strncpy( clean_out, &tmp_cmd[ start_pos ], set_pos - start_pos );
        return AT_CMD_SET;

    } else if( set_pos == get_pos - 1 ) {

        my_strncpy( clean_out, &tmp_cmd[ start_pos ], set_pos - start_pos );
        return AT_CMD_GET;
    }
    return AT_CMD_UNKNOWN;
}

char* my_strncpy(char* dst, const char* src, size_t n)
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
/******************************************************************************
* Public Function Definitions
*******************************************************************************/

void at_parser_init
(
		void
)
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

void at_parser_store
(
		char *command,
        uint32_t timeout,
        at_cmd_cb getter,
        at_cmd_cb setter,
        at_cmd_cb tester,
        at_cmd_cb executer
)
{
    at_cmd_t cmd;

    cmd.hash        = _at_hash( command );
    cmd.timeout     = timeout;
    cmd.getter      = getter;
    cmd.setter      = setter;
    cmd.tester      = tester;
    cmd.executer    = executer;

    if( strlen( command ) >= AT_HEADER_SIZE + header_size )
        return;
    
    if( at_cmd_storage_used == AT_STORAGE_SIZE )
        return;

    if( _at_search( command ) )
        return;

    at_cmd_storage[ at_cmd_storage_used ] = cmd;
    at_cmd_storage_used++;
}

void at_parse
(
		char *input,
        at_cmd_cb *cb,
        uint32_t *timeout
)
{
    at_type_t   cmd_type                    = 0;
    uint16_t    cmd_idx                     = 0;
    char        cmd_temp[ AT_HEADER_SIZE ]  = { 0 };

    if( !( cmd_type = _at_sub_parse( input, cmd_temp ) ) )
    {
        *cb = at_cmd_storage[ 0 ].tester;
        *timeout = at_cmd_storage[ 0 ].timeout;
        return;
    }

    if( !( cmd_idx = _at_search( cmd_temp ) ) )
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

/*************** END OF FUNCTIONS *********************************************/
