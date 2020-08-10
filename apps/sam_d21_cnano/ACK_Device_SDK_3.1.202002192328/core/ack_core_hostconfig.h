/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_HOST_CONFIG__
#define __ACK_HOST_CONFIG__

#ifdef __cplusplus
extern "C"
{
#endif

// Writes the host config to the Alexa Connect Kit connectivity module.
// This function should be the first to be called after the a connectkit-booted event.
// The firmware version is any value that is meaningful in the context of version numbers supplied
// when new firmware images are uploaded to Amazon.
ACKError_t HostConfigWrite(uint64_t firmwareVersion);

#ifdef __cplusplus
}
#endif

#endif // def __ACK_HOST_CONFIG__
