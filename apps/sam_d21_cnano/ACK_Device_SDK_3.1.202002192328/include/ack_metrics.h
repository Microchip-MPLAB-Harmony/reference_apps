/*
 * Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * You may not use this file except in compliance with the terms and conditions set forth in the
 * accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef __ACK_METRICS_H__
#define __ACK_METRICS_H__

#include "acp.pb.h"
#include "ack_user_config.h"
#include "details/ack_types.h"
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef ACK_METRICS

// Structure for each metric datapoint.
typedef struct _ACKMetricDatapoint_t
{
    const char* Name;
    acp_metric_datapoint_Type Type;

    union
    {
        uint32_t Counter;
        float Gauge;
        const char* Discrete;
    }
    Value;
}
ACKMetricDatapoint_t;

// Call this to send a metric. Each device type can create its own metric definition.
// Metrics are stored in the connectivity module until the module decides to send to the metrics.
ACKError_t ACK_SendMetric(
    acp_cmd_record_dem_metric_Type type,
    size_t datapointCount,
    const ACKMetricDatapoint_t* pDatapoints);

// A set of helper functions that can be used to send common metrics.

// Sends a discrete metric.
ACKError_t ACK_SendDiscreteMetric(
    acp_cmd_record_dem_metric_Type metricType,
    const char* pDatapointName,
    const char* pDatapointValue);

// Sends a counter metric.
ACKError_t ACK_SendCounterMetric(
    acp_cmd_record_dem_metric_Type metricType,
    const char* pDatapointName,
    uint32_t datapointValue);

// Sends a numeric value metric.
ACKError_t ACK_SendNumericValueMetric(
    acp_cmd_record_dem_metric_Type metricType,
    const char* pDatapointName,
    float datapointValue);

// Sends a metric with old and new numeric values.
ACKError_t ACK_SendNumericValueChangedMetric(
    acp_cmd_record_dem_metric_Type metricType,
    const char* pOldDatapointName,
    float oldValue,
    const char* pNewDatapointName,
    float newValue);

// Sends an error metric, with an optional associated numeric value or string value.
ACKError_t ACK_SendErrorMetric(const char* pDataName);
ACKError_t ACK_SendErrorMetricWithNumericValue(const char* pDataName, float value);
ACKError_t ACK_SendErrorMetricWithStringValue(const char* pDataName, const char* pText);

// Sends a user present metric with optional string value.
ACKError_t ACK_SendUserPresentMetric(const char* pDataName);
ACKError_t ACK_SendUserPresentMetricWithStringValue(const char* pDataName, const char* pText);

// Sends a usage report metric with optional numeric or string value.
ACKError_t ACK_SendUsageReportMetric(const char* pDataName);
ACKError_t ACK_SendUsageReportMetricWithNumericValue(const char* pDataName, float value);
ACKError_t ACK_SendUsageReportMetricWithStringValue(const char* pDataName, const char* pText);

// Sends a counter metric to track a particular usage.
ACKError_t ACK_SendUsageReportIncrementMetric(const char* pDataName);
ACKError_t ACK_SendUsageReportCountMetric(const char* pDataName, uint32_t count);

#endif // def ACK_METRICS

#ifdef __cplusplus
}
#endif

#endif // def __ACK_METRICS_H__
