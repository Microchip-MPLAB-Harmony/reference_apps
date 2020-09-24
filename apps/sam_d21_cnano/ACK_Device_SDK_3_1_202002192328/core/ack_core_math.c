/*
 * Copyright 2019-2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#include "ack_core_math.h"
#include <stdarg.h>
#include <stdbool.h>

bool MathSafeAddSizeT(size_t* pResult, unsigned count, ...)
{
    size_t accumulatedSum = 0;
    size_t value;
    size_t sum;
    unsigned i;
    bool ok;

    va_list arglist;

    va_start(arglist, count);

    for (ok = true, i = 0; ok && (i < count); ++i)
    {
        value = va_arg(arglist, size_t);

        sum = accumulatedSum + value;
        if (sum < accumulatedSum)
        {
            // Overflow detected.
            ok = false;
        }

        accumulatedSum = sum;
    }

    va_end(arglist);

    *pResult = accumulatedSum;
    return ok;
}

