/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#include "ack.h"
#include "ack_core_common.h"
#include "ack_core_cooking_common.h"
#include "ack_core_directives.h"
#include "ack_core_event_builder.h"
#include "ack_core_heaplet.h"
#include "ack_core_protobuf_utilities.h"
#include "ack_user_config.h"
#include "ack_cooking.h"
#include "v3avs_capabilities/V3AlexaCookingPresetController.pb.h"
#include "v3avs_capabilities/V3AVS.pb.h"

#ifdef ACK_COOKING_PRESET_CONTROLLER

// Forward declarations.
static ACKError_t HandleCookByPresetDirective_(
    v3avs_capabilities_V3AlexaCookingPresetController_CookByPreset* pDirective);

// Calls user-supplied routine to process the directive.
ACKError_t HandleCookingPresetControllerDirective(void)
{
    v3avs_capabilities_V3AlexaCookingPresetController_Directive* pDirective;
    ACKError_t retval;
    bool protoResult;

    pDirective = (v3avs_capabilities_V3AlexaCookingPresetController_Directive*)HeapletSetSize(
        MEM_RECEIVED_DIRECTIVE_PAYLOAD,
        sizeof(v3avs_capabilities_V3AlexaCookingPresetController_Directive));
    if (NULL == pDirective)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    protoResult = ProtobufDecode(
        HeapletAccess(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        HeapletGetSize(MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD),
        v3avs_capabilities_V3AlexaCookingPresetController_Directive_fields,
        pDirective);

    if (!protoResult)
    {
        ACK_DEBUG_PRINT_E("Unable to decode cooking preset controller directive payload.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    ACK_REENTRY_SHIELDS_UP;

    switch (pDirective->which_payload)
    {
    case v3avs_capabilities_V3AlexaCookingPresetController_Directive_cook_by_preset_tag:
        ACK_DEBUG_PRINT_I("Processing cooking preset cook-by-preset directive");
        retval = HandleCookByPresetDirective_(&pDirective->payload.cook_by_preset);
        break;

    default:
        ACK_DEBUG_PRINT_W(
            "Unhandled cooking preset controller directive payload %u",
            pDirective->which_payload);
        retval = ACK_ERR_PROTOCOL;
        break;
    }

    ACK_REENTRY_SHIELDS_DOWN;

    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    // NOTE! pDirective is now invalid, as processing above can be assumed to have resulted in
    // HeapletSetSize operations.

    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_RECEIVED_DIRECTIVE_PAYLOAD);
    return retval;
}

static ACKError_t HandleCookByPresetDirective_(
    v3avs_capabilities_V3AlexaCookingPresetController_CookByPreset* pDirective)
{
    ACKError_t retval;
    ACKCookingDirectiveParams_t* pParams;

    retval = CookingDecodeDirectiveCommon(
        pDirective,
        &pDirective->cooking_mode,
        &pDirective->food_item,
        &pDirective->preset_name,
        v3avs_capabilities_V3AlexaCookingPresetController_Directive_cook_by_preset_tag,
        v3avs_capabilities_V3AlexaCookingPresetController_CookByPreset_fields,
        NULL,   // No explicit encoded data, decode from MEM_RECEIVED_ENCODED_DIRECTIVE_PAYLOAD
        0,      // No explicit encoded data
        NULL);  // No pre-allocated ACKCookingDirectiveParams_t
    if (ACK_NO_ERROR != retval)
    {
        goto cleanup0;
    }

    pParams = (ACKCookingDirectiveParams_t*)HeapletAccess(MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA);

    // Call the user-supplied handler.
    ACKUser_OnCookingPresetControllerCookByPresetDirective(
        ((V3AVS_AvsDirective*)HeapletAccess(MEM_RECEIVED_AVS_DIRECTIVE_ENVELOPE))->correlation_id,
        pParams);

    // Success.
    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_RECEIVED_DECODED_VARIABLE_LENGTH_DATA);
    return retval;
}

ACKError_t ACK_AddCookingPresetControllerPresetNameProperty(
    const ACKStateCommon_t* pCommon,
    const char* pPresetName)
{
    ProtobufCallbackField_t presetNameField = {0};
    v3avs_capabilities_V3AlexaCookingPresetController_PresetNameProperty property;

    if (pPresetName)
    {
        presetNameField.Value = (const uint8_t*)pPresetName;
        presetNameField.Length = strlen(pPresetName);
    }
    else
    {
        ACK_DEBUG_PRINT_W("Sending back empty preset name property.");
    }

    property.preset_name.value.funcs.encode = ProtobufEncodeCallbackField;
    property.preset_name.value.arg = &presetNameField;

    ACK_REENTRY_CHECK;

    return CommonEncodeContextProperty(
        V3AVS_Namespace_V3_ALEXA_COOKING_PRESET_CONTROLLER,
        v3avs_capabilities_V3AlexaCookingPresetController_PropertyName_PRESET_NAME_PROP,
        0, // instance not used for this controller
        pCommon,
        v3avs_capabilities_V3AlexaCookingPresetController_PresetNameProperty_fields,
        &property);
}

#endif // def ACK_COOKING_PRESET_CONTROLLER
