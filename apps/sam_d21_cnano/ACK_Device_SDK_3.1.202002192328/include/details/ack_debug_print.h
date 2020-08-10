/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_DEBUG_PRINT_H__
#define __ACK_DEBUG_PRINT_H__

#include "ack_user_platform.h"
#include "ack_user_config.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// Debug print levels. #define ACK_DEBUG_PRINT_LEVEL to one of these in ack_user_config.h to enable
// debug output at that level and lower. Leave ACK_DEBUG_PRINT_LEVEL undefined to disable debug printing.
#define ACK_DEBUG_PRINT_LEVEL_CRITICAL 0
#define ACK_DEBUG_PRINT_LEVEL_ERROR 1
#define ACK_DEBUG_PRINT_LEVEL_WARNING 2
#define ACK_DEBUG_PRINT_LEVEL_INFO 3
#define ACK_DEBUG_PRINT_LEVEL_DEBUG 4

#define ACK_DEBUG_PRINT_BASE(_lvlstring,  _message, ...) \
{\
    ACKPlatform_DebugPrint("[%s: %s:%d] " _message, _lvlstring, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
}

#ifdef ACK_DEBUG_PRINT_LEVEL

#if ACK_DEBUG_PRINT_LEVEL >= ACK_DEBUG_PRINT_LEVEL_DEBUG
#define ACK_DEBUG_PRINT_D(_message, ...) \
    ACK_DEBUG_PRINT_BASE("DBG", _message, ##__VA_ARGS__)
#else
#define ACK_DEBUG_PRINT_D(_message, ...)
#endif

#if ACK_DEBUG_PRINT_LEVEL >= ACK_DEBUG_PRINT_LEVEL_INFO
#define ACK_DEBUG_PRINT_I(_message, ...) \
    ACK_DEBUG_PRINT_BASE("INF", _message, ##__VA_ARGS__)
#else
#define ACK_DEBUG_PRINT_I(_message, ...)
#endif

#if ACK_DEBUG_PRINT_LEVEL >= ACK_DEBUG_PRINT_LEVEL_WARNING
#define ACK_DEBUG_PRINT_W(_message, ...) \
    ACK_DEBUG_PRINT_BASE("WRN", _message, ##__VA_ARGS__)
#else
#define ACK_DEBUG_PRINT_W(_message, ...)
#endif

#if ACK_DEBUG_PRINT_LEVEL >= ACK_DEBUG_PRINT_LEVEL_ERROR
#define ACK_DEBUG_PRINT_E(_message, ...) \
    ACK_DEBUG_PRINT_BASE("ERR", _message, ##__VA_ARGS__)
#else
#define ACK_DEBUG_PRINT_E(_message, ...)
#endif

#if ACK_DEBUG_PRINT_LEVEL >= ACK_DEBUG_PRINT_LEVEL_CRITICAL
#define ACK_DEBUG_PRINT_C(_message, ...) \
    ACK_DEBUG_PRINT_BASE("CRT", _message, ##__VA_ARGS__)
#else
#define ACK_DEBUG_PRINT_C(_message, ...)
#endif

#else

#define ACK_DEBUG_PRINT_D(_message, ...)
#define ACK_DEBUG_PRINT_I(_message, ...)
#define ACK_DEBUG_PRINT_W(_message, ...)
#define ACK_DEBUG_PRINT_E(_message, ...)
#define ACK_DEBUG_PRINT_C(_message, ...)

#endif

#ifdef __cplusplus
}
#endif

#endif // def __ACK_DEBUG_PRINT_H__
