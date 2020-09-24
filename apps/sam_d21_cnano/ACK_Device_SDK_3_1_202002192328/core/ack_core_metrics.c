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
#include "ack_core_heaplet.h"
#include "ack_metrics.h"
#include "ack_core_protobuf_utilities.h"
#include "ack_user_config.h"
#include "acp.pb.h"

#ifdef ACK_METRICS

// There is a MQTT limit to the size of packets we can send, so the encoded packet must be limited.
#define METRICS_MAX_ENCODED_SIZE 768

// Note carefully that this routine uses "AltHeapletBlocks" common routines to send the write-log ACP command
// and receive the response. This is a set of heaplet tags that when used will not move or overwrite
// existing blocks that may be in use when the user call ACK_WriteLog/ACK_WriteLogFormatted. Because of this,
// it is safe to call those routines when in a handler callback (ACKUser_Onxxx).
ACKError_t ACK_SendMetric(
    acp_cmd_record_dem_metric_Type type,
    size_t datapointCount,
    const ACKMetricDatapoint_t* pDatapoints)
{
    acp_cmd* pCmd;
    acp_metric_datapoint* pAcpDatapoints = NULL;
    ProtobufCallbackField_t* pTextValues = NULL;
    ACKError_t retval;
    ProtobufEncodeArrayCallbackData_t* pEncodeData;
    size_t size;
    size_t i;

    // NOTE: no reentry check. We use the alt heap blocks for sending out the ACP command and reading and
    // processing the result.

    ACK_DEBUG_PRINT_I("Sending metric.");

    // Allocate a single heaplet block to store a ProtobufEncodeArrayCallbackData_t, one acp_metric_datapoint
    // for each datapoint, and one ProtobufCallbackField_t for each discrete/textual metric -- in that order
    // within the block. First calculate the required size, then allocate the block and set up pointers.
    size = sizeof(ProtobufEncodeArrayCallbackData_t) + (sizeof(acp_metric_datapoint) * datapointCount);

    for (i = 0; i < datapointCount; ++i)
    {
        if ((acp_metric_datapoint_Type_DISCRETE == pDatapoints[i].Type)
            && (NULL != pDatapoints[i].Value.Discrete))
        {
            size += sizeof(ProtobufCallbackField_t);
        }
    }

    pEncodeData = (ProtobufEncodeArrayCallbackData_t*)HeapletSetSize(MEM_OUTBOUND_LOG_AND_METRICS_DATA, size);
    if (NULL == pEncodeData)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    memset(pEncodeData, 0, size);

    pAcpDatapoints = (acp_metric_datapoint*)(pEncodeData + 1);
    pTextValues = (ProtobufCallbackField_t*)(pAcpDatapoints + datapointCount);

    // Memory for the command to be sent
    pCmd = (acp_cmd*)HeapletSetSize(MEM_ALT_OUTBOUND_ACP_CMD, sizeof(*pCmd));
    if (NULL == pCmd)
    {
        retval = ACK_ERR_OUT_OF_MEMORY;
        goto cleanup0;
    }

    memset(pCmd, 0, sizeof(*pCmd));

    // Context.properties field.
    pEncodeData->Data = pAcpDatapoints;
    pEncodeData->ElementCount = datapointCount;
    pEncodeData->ElementSize = sizeof(acp_metric_datapoint);

    pCmd->which_type = acp_cmd_record_dem_metric_obj_tag;
    pCmd->type.record_dem_metric_obj.metric_type = type;
    pCmd->type.record_dem_metric_obj.datapoints.arg = pEncodeData;
    pCmd->type.record_dem_metric_obj.datapoints.funcs.encode = ProtobufEncodeArrayCallback;

    for (i = 0; i < datapointCount; i++)
    {
        pAcpDatapoints->data_type = pDatapoints->Type;

        ACK_SAFE_COPY_STRING(pAcpDatapoints->name, pDatapoints->Name);

        switch (pDatapoints->Type)
        {
        case acp_metric_datapoint_Type_GAUGE:
            pAcpDatapoints->number = pDatapoints->Value.Gauge;
            break;

        case acp_metric_datapoint_Type_DISCRETE:
            if (pDatapoints->Value.Discrete != NULL)
            {
                pTextValues->Value = (uint8_t*)pDatapoints->Value.Discrete;
                pTextValues->Length = strlen(pDatapoints->Value.Discrete);

                pAcpDatapoints->text.arg = pTextValues;
                pAcpDatapoints->text.funcs.encode = ProtobufEncodeCallbackField;

                ++pTextValues;
            }

            break;

        // The only legal remaining type is COUNTER. If something else is specified, trigger an
        // assertion failure to call attention to the programming error.
        // Use counter as the default for this because interpreting the union as an integer is safe,
        // whereas interpreting a string would be unsafe (if we made discrete the default).
        case acp_metric_datapoint_Type_COUNTER:
        default:
            ACK_ASSERT(acp_metric_datapoint_Type_COUNTER == pDatapoints->Type);
            pAcpDatapoints->counter = pDatapoints->Value.Counter;
            break;
        }

        ++pAcpDatapoints;
        ++pDatapoints;
    }

    // Calculate the encoded size. If the encoded size is too big (more than METRICS_MAX_ENCODED_SIZE bytes),
    // we should spit out an error. There is a MQTT limit to the size of packets we can send, so the encoded
    // packet cannot be too large.
    // TODO: Inside the CommonSendAcpCmdAndGetResponse we calculate ProtobufGetEncodedSize again, we should
    // figure out a way to make only one calculation
    size = ProtobufGetEncodedSize(acp_cmd_fields, pCmd);

    if (size > METRICS_MAX_ENCODED_SIZE)
    {
        ACK_DEBUG_PRINT_E(
            "Encoded metrics size (%u bytes) exceeds %u bytes.",
            (unsigned)size, // case because data types might be different sizes
            METRICS_MAX_ENCODED_SIZE);
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    retval = CommonSendAcpCmdAndGetResponseAltHeapletBlocks();

    if (ACK_NO_ERROR != retval)
    {
        ACK_DEBUG_PRINT_E("Error encoding and sending command, err %u", retval);
        goto cleanup0;
    }

    if (!CommonCheckGenericResponseAltHeapletBlocks())
    {
        ACK_DEBUG_PRINT_E("Unexpected response to command.");
        retval = ACK_ERR_PROTOCOL;
        goto cleanup0;
    }

    retval = ACK_NO_ERROR;

cleanup0:
    HeapletFree(MEM_ALT_OUTBOUND_ACP_CMD);
    HeapletFree(MEM_OUTBOUND_LOG_AND_METRICS_DATA);
    CommonFreeAcpResponseAltHeapletBlocks();
    return retval;
}

ACKError_t ACK_SendDiscreteMetric(
    acp_cmd_record_dem_metric_Type metricType,
    const char* pDatapointName,
    const char* pDatapointValue)
{
    ACKMetricDatapoint_t datapoint;
    datapoint.Name = pDatapointName;
    datapoint.Type = acp_metric_datapoint_Type_DISCRETE;
    datapoint.Value.Discrete = pDatapointValue;

    return ACK_SendMetric(metricType, 1, &datapoint);
}

ACKError_t ACK_SendCounterMetric(
    acp_cmd_record_dem_metric_Type metricType,
    const char* pDatapointName,
    uint32_t datapointValue)
{
    ACKMetricDatapoint_t datapoint;
    datapoint.Name = pDatapointName;
    datapoint.Type = acp_metric_datapoint_Type_COUNTER;
    datapoint.Value.Counter = datapointValue;

    return ACK_SendMetric(metricType, 1, &datapoint);
}

ACKError_t ACK_SendNumericValueMetric(
    acp_cmd_record_dem_metric_Type metricType,
    const char* pDatapointName,
    float datapointValue)
{
    ACKMetricDatapoint_t datapoint;
    datapoint.Name = pDatapointName;
    datapoint.Type = acp_metric_datapoint_Type_GAUGE;
    datapoint.Value.Gauge = datapointValue;

    return ACK_SendMetric(metricType, 1, &datapoint);
}

ACKError_t ACK_SendNumericValueChangedMetric(
    acp_cmd_record_dem_metric_Type metricType,
    const char* pOldDatapointName,
    float oldValue,
    const char* pNewDatapointName,
    float newValue)
{
    ACKMetricDatapoint_t datapoint[2];
    datapoint[0].Name = pOldDatapointName;
    datapoint[0].Type = acp_metric_datapoint_Type_GAUGE;
    datapoint[0].Value.Gauge = oldValue;

    datapoint[1].Name = pNewDatapointName;
    datapoint[1].Type = acp_metric_datapoint_Type_GAUGE;
    datapoint[1].Value.Gauge = newValue;

    return ACK_SendMetric(metricType, 2, datapoint);
}

ACKError_t ACK_SendErrorMetricWithNumericValue(const char* pDataName, float value)
{
    return ACK_SendNumericValueMetric(acp_cmd_record_dem_metric_Type_DEVICE_ERROR, pDataName, value);
}

ACKError_t ACK_SendErrorMetricWithStringValue(const char* pDataName, const char* pText)
{
    return ACK_SendDiscreteMetric(acp_cmd_record_dem_metric_Type_DEVICE_ERROR, pDataName, pText);
}

ACKError_t ACK_SendErrorMetric(const char* pDataName)
{
    return ACK_SendDiscreteMetric(acp_cmd_record_dem_metric_Type_DEVICE_ERROR, pDataName, NULL);
}

ACKError_t ACK_SendUserPresentMetricWithStringValue(const char* pDataName, const char* pText)
{
    return ACK_SendDiscreteMetric(acp_cmd_record_dem_metric_Type_USER_PRESENT, pDataName, pText);
}

ACKError_t ACK_SendUserPresentMetric(const char* pDataName)
{
    return ACK_SendDiscreteMetric(acp_cmd_record_dem_metric_Type_USER_PRESENT, pDataName, NULL);
}

ACKError_t ACK_SendUsageReportMetricWithStringValue(const char* pDataName, const char* pText)
{
    return ACK_SendDiscreteMetric(acp_cmd_record_dem_metric_Type_USAGE_REPORT, pDataName, pText);
}

ACKError_t ACK_SendUsageReportMetricWithNumericValue(const char* pDataName, float value)
{
    return ACK_SendNumericValueMetric(acp_cmd_record_dem_metric_Type_USAGE_REPORT, pDataName, value);
}

ACKError_t ACK_SendUsageReportMetric(const char* pDataName)
{
    return ACK_SendDiscreteMetric(acp_cmd_record_dem_metric_Type_USAGE_REPORT, pDataName, NULL);
}

ACKError_t ACK_SendUsageReportIncrementMetric(const char* pDataName)
{
    return ACK_SendCounterMetric(acp_cmd_record_dem_metric_Type_USAGE_REPORT, pDataName, 1);
}

ACKError_t ACK_SendUsageReportCountMetric(const char* pDataName, uint32_t count)
{
    return ACK_SendCounterMetric(acp_cmd_record_dem_metric_Type_USAGE_REPORT, pDataName, count);
}

#endif // def ACK_METRICS
