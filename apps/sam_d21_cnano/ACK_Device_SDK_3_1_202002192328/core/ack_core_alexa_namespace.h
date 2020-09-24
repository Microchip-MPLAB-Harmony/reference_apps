/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#include "ack.h"
#include "pb.h"
#include "V3Alexa.pb.h"

#ifdef __cplusplus
extern "C"
{
#endif

// For use in the outbound event processor, to send automatic change reports.
ACKError_t AlexaNamespaceStartChangeReportEvent(v3avs_capabilities_V3Alexa_Cause_CauseType cause);

// Below here are exposed for testing purposes only.

ACKError_t AlexaNamespaceStartBuildDirectiveSuccessEvent(
    int32_t correlationId,
    ACKPropertiesBits_t responsePropertiesBits,
    ACKPropertiesBits_t changeReportPropertiesBits);

ACKError_t AlexaNamespaceStartBuildStateReportSuccessEvent(int32_t correlationId);

ACKError_t AlexaNamespaceStartBuildDirectiveOutOfRangeErrorEvent(
    int32_t correlationId,
    float minimum,
    float maximum,
    const char* pOptionalMessage);

ACKError_t AlexaNamespaceStartBuildDirectiveTemperatureOutOfRangeErrorEvent(
    int32_t correlationId,
    v3avs_types_V3Temperature_Scale scale,
    float minimum,
    float maximum,
    const char* pOptionalMessage);

ACKError_t AlexaNamespaceStartBuildDirectiveNotSupportedInCurrentModeErrorEvent(
    int32_t correlationId,
    v3avs_capabilities_V3Alexa_NotSupportedInCurrentMode_DeviceMode mode,
    const char* pOptionalMessage);

ACKError_t AlexaNamespaceStartBuildDirectiveErrorEvent(
    int32_t correlationId,
    v3avs_capabilities_V3Alexa_ErrorResponse_ErrorType type,
    const char* pLogMessage,
    const pb_field_t* pPayloadFields);

ACKError_t AlexaNamespaceEncodeEventPayload(void);

#ifdef __cplusplus
}
#endif
