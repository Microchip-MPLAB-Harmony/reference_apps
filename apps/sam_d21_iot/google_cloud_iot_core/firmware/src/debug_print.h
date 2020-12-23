/*
    \file   debug_print.h

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

#ifndef DEBUG_PRINT_H
#define DEBUG_PRINT_H

#include "iot_config/IoT_Sensor_Node_config.h"

#define CSI_RESET   "\33[0m"
#define CSI_BLACK   "\33[30m"
#define CSI_RED     "\33[31m"
#define CSI_GREEN   "\33[32m"
#define CSI_YELLOW  "\33[33m"
#define CSI_BLUE    "\33[34m"
#define CSI_MAGENTA "\33[35m"
#define CSI_CYAN    "\33[36m"
#define CSI_WHITE   "\33[37m"
#define CSI_INVERSE "\33[7m"
#define CSI_NORMAL  "\33[27m"
#define CSI_CLS     "\33[2J"
#define CSI_HOME    "\33[1;1H"

typedef enum 
{
   SEVERITY_NONE,
   SEVERITY_WARNING,
   SEVERITY_NOTICE,
   SEVERITY_INFO,
   SEVERITY_DEBUG
} debug_severity_t;

typedef enum
{
   LEVEL_NORMAL,
   LEVEL_GOOD,
   LEVEL_BAD,
   LEVEL_ERROR
}debug_errorLevel_t;

#define IOT_DEBUG_PRINT CFG_DEBUG_MSG

void debug_printer(debug_severity_t debug_severity, debug_errorLevel_t error_level, const char* format, ...);
void debug_setSeverity(debug_severity_t debug_level);
void debug_setPrefix(const char *prefix);
void debug_init(const char *prefix);
void debug_printf(const char* format, ...);
void debug_NPrintBuff(uint8_t *pBuf, size_t len);

#define debug_print(fmt, ...) \
do { if (IOT_DEBUG_PRINT) debug_printer(SEVERITY_DEBUG, LEVEL_NORMAL, fmt CSI_RESET, ##__VA_ARGS__); } while (0)

#define debug_printGOOD(fmt, ...) \
do { if (IOT_DEBUG_PRINT) debug_printer(SEVERITY_DEBUG,LEVEL_GOOD, fmt CSI_RESET,  ##__VA_ARGS__); } while (0)

#define debug_printError(fmt, ...) \
do { if (IOT_DEBUG_PRINT) debug_printer(SEVERITY_DEBUG,LEVEL_ERROR, fmt CSI_RESET, ##__VA_ARGS__); } while (0)

#define debug_printInfo(fmt, ...) \
do { if (IOT_DEBUG_PRINT) debug_printer(SEVERITY_INFO,LEVEL_NORMAL, fmt CSI_RESET, ##__VA_ARGS__); } while (0)

#endif // DEBUG_PRINT_H
