/*
    \file   debug_print.c

    \brief  debug_console printer

    (c) 2018 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip software and any
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party
    license terms applicable to your use of third party software (including open source software) that
    may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS
    FOR A PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS
    SOFTWARE.
*/

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "debug_print.h"
#include "definitions.h"

#define APP_PRINT_BUFFER_SIZ    2048

static char printBuff[APP_PRINT_BUFFER_SIZ] __attribute__((aligned(4)));
static int printBuffPtr;
static OSAL_MUTEX_HANDLE_TYPE consoleMutex;

static const char *severity_strings[] = {
   CSI_WHITE   "   NONE" CSI_WHITE,
   CSI_YELLOW  "WARNING" CSI_WHITE,
   CSI_BLUE    " NOTICE" CSI_WHITE,
   CSI_MAGENTA "   INFO" CSI_WHITE,
   CSI_RED     "  DEBUG" CSI_NORMAL CSI_WHITE
};

static const char *level_strings[] = {
      CSI_WHITE           "NORMAL" CSI_WHITE,
      CSI_GREEN           "  GOOD" CSI_WHITE,
      CSI_RED             "   BAD" CSI_WHITE,
      CSI_RED CSI_INVERSE " ERROR" CSI_NORMAL CSI_WHITE
};
 
static debug_severity_t debug_severity_filter = SEVERITY_NONE;
static char debug_message_prefix[20] = "<PREFIX>";

void debug_init(const char *prefix)
{ 
    debug_setPrefix(prefix);
    debug_setSeverity(SEVERITY_DEBUG);
    printBuffPtr = 0;
    OSAL_MUTEX_Create(&consoleMutex);
    
}

void debug_setSeverity(debug_severity_t debug_level)
{
    debug_severity_filter = debug_level;
}

void debug_setPrefix(const char *prefix)
{
   strncpy(debug_message_prefix,prefix,sizeof(debug_message_prefix));
}

void debug_printer(debug_severity_t debug_severity, debug_errorLevel_t error_level, const char* format, ...)
{
    char tmpBuf[APP_PRINT_BUFFER_SIZ];
    size_t len = 0;
    va_list args = {0};
    
    if(debug_severity >= SEVERITY_NONE && debug_severity <= SEVERITY_DEBUG)
    {
        if(debug_severity <= debug_severity_filter)
        {
            if(error_level < LEVEL_NORMAL) error_level = LEVEL_NORMAL;
            if(error_level > LEVEL_ERROR) error_level = LEVEL_ERROR;

           debug_printf("%s\4 %s %s ",debug_message_prefix, severity_strings[debug_severity], level_strings[error_level]);

            va_start( args, format );
            len = vsnprintf(tmpBuf, APP_PRINT_BUFFER_SIZ, format, args);
            va_end( args );
            debug_NPrintBuff((uint8_t*)tmpBuf, len);;
            debug_printf(CSI_RESET"\r\n");
        }
    }
}

void debug_NPrintBuff(uint8_t *pBuf, size_t len)
{
    if ((len > 0) && (len < APP_PRINT_BUFFER_SIZ))
    {
        if (OSAL_RESULT_TRUE == OSAL_MUTEX_Lock(&consoleMutex, OSAL_WAIT_FOREVER))
        {
            if ((len + printBuffPtr) > APP_PRINT_BUFFER_SIZ)
            {
                printBuffPtr = 0;
            }

            memcpy(&printBuff[printBuffPtr], pBuf, len);
            SYS_CONSOLE_Write(0, &printBuff[printBuffPtr], len);

            printBuffPtr = (printBuffPtr + len + 3) & ~3;

            OSAL_MUTEX_Unlock(&consoleMutex);
        }
    }
}

void debug_printf(const char* format, ...)
{
    char tmpBuf[APP_PRINT_BUFFER_SIZ];
    size_t len = 0;
    va_list args = {0};
    va_start( args, format );

    len = vsnprintf(tmpBuf, APP_PRINT_BUFFER_SIZ, format, args);
    va_end( args );
    debug_NPrintBuff((uint8_t*)tmpBuf, len);
}

