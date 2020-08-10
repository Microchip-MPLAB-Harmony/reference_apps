/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

/*
    Functionality for test automation. Because this code may be running on an MCU during integration tests,
    we cannot directly observe its internals. Instead, the functionality in this header can be used to emit
    data into the debug spew using the platform-specific debug print mechanism.

    Unlike the normal debug spew, messages associated with test automation are not necessarily human-readable.
    It's only important that the test(s) expecting to find the test automation messages can process them.
*/

#ifndef __ACK_TESTAUTOMATION_H__
#define __ACK_TESTAUTOMATION_H__

#include <stdint.h>
#include "ack_user_config.h"
#include "ack_user_platform.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef ACK_TESTAUTOMATION

#define TA_PREFIX "[TA]"
#define TA_TEST_START "test-start"
#define TA_TEST_PASS "test-pass"
#define TA_TEST_FAIL "test-fail"
#define TA_TEST_UNKNOWN "test-unknown"
#define TA_TEST_MESSAGE "test-message"

#define TA_EMIT_TEST_START(testName) _TA_EMIT(TA_TEST_START, "%s", testName)
#define TA_EMIT_TEST_PASS(testName) _TA_EMIT(TA_TEST_PASS, "%s", testName)
#define TA_EMIT_TEST_FAIL(testName) _TA_EMIT(TA_TEST_FAIL, "%s", testName)
#define TA_EMIT_TEST_UNKNOWN(testName) _TA_EMIT(TA_TEST_UNKNOWN, "%s", testName)
#define TA_EMIT_TEST_MESSAGE(format, ...) _TA_EMIT(TA_TEST_MESSAGE, format, ##__VA_ARGS__)

// Format is
//    [TA][head]...
// [TA] is a hard-coded string present as the first 5 chars of any test automation emission.
// head is a caller-supplied string
// The rest is standard printf-style format.
#define _TA_EMIT(head, format, ...)  \
    ACKPlatform_DebugPrint(TA_PREFIX "[" head "]" format, ##__VA_ARGS__)

#else

#define TA_EMIT_TEST_START(testName)
#define TA_EMIT_TEST_PASS(testName)
#define TA_EMIT_TEST_FAIL(testName)
#define TA_EMIT_TEST_UNKNOWN(testName)
#define TA_EMIT_TEST_MESSAGE(format, ...)

#endif

#ifdef __cplusplus
}
#endif

#endif // def __ACK_TESTAUTOMATION_H__
