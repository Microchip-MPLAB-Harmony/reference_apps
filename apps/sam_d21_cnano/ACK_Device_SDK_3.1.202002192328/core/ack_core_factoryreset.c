/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#include "acp.pb.h"
#include "ack_core_factoryreset.h"
#include "ack_core_heaplet.h"
#include "ack_core_common.h"

ACKError_t FactoryResetInitiate(void)
{
    ACKError_t retval;

    ACK_DEBUG_PRINT_I("Sending trigger factory reset command");

    retval = CommonAllocAndSendAcpCmdAndGetAcpResponse(acp_cmd_trigger_factory_reset_obj_tag);

    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    if (!CommonCheckGenericResponse())
    {
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    retval = ACK_NO_ERROR;

cleanup0:
    CommonFreeAcpResponse();
    return retval;
}
