/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#include "acp.pb.h"
#include "ack_core_common.h"
#include "ack_core_heaplet.h"
#include "ack_core_userguidedsetup.h"

ACKError_t UserGuidedSetupInitiate(void)
{
    acp_cmd* pCmd;
    ACKError_t retval;

    ACK_DEBUG_PRINT_I("Sending initiate user-guided setup command to the module.");

    pCmd = (acp_cmd*)HeapletSetSize(MEM_OUTBOUND_ACP_CMD, sizeof(*pCmd));
    if (NULL == pCmd)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    memset(pCmd, 0, sizeof(*pCmd));

    pCmd->which_type = acp_cmd_enter_setup_mode_obj_tag;

    // For now the only supported type is Frustration-Free Setup.
    pCmd->type.enter_setup_mode_obj.mode = acp_cmd_enter_setup_mode_registration_type_ffs;
    pCmd->type.enter_setup_mode_obj.security = acp_cmd_enter_setup_mode_security_type_insecure;

    retval = CommonSendAcpCmdAndGetResponse();

    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Error encoding and sending initiate user-guided setup command, err %u", retval);
        goto cleanup0;
    }

    if (!CommonCheckGenericResponse())
    {
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_OUTBOUND_ACP_CMD);
    CommonFreeAcpResponse();
    return retval;
}
