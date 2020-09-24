# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

# Strings common to the 'library' part of the validator.

STR_PYTHON_VERSION_REQUIRED = "Python {0}.{1} or greater required"
STR_COPYRIGHT_BANNER = "Copyright (c) 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved."
STR_WARNING = "Warning"
STR_VERBOSE_OUTPUT = "verobse output"
STR_INVALID_COM_PORT = "Port '{0}' is invalid or inaccessible."

# Standard steps.
STR_STEP_BOOTED = "Send Module Booted message to HMCU and wait for HMCU to enter Booted lifecycle state"
STR_STEP_WAIT_HOST_CONFIG = "Wait for HMCU to send host config, and enter Not Connected lifecycle state"
STR_STEP_CONNECTED = "Set ACK module connected state to true, and wait for HMCU to enter Connected lifecycle state"
STR_STEP_DELAY_X_SECONDS = "Delay by {0} second(s)"

# Help text for argparser.
STR_REQUIRED_ARGUMENTS = "required arguments"
STR_HMCU_DEBUG_PORT_ARG_HELP = "HMCU debug port (required in absence of socket server)"
STR_ACK_MODULE_PORT_ARG_HELP = "ACK module UART port (required in absence of socket server)"
STR_SOCKET_ARG_HELP = "Socket to listen on (required in absence of HMCU debug port and ACK module UART port)"
STR_SOCKET_METAVAR = "SERVER-ADDRESS:PORT"
STR_BAD_PORT_ARGS = "Either a socket server-address:port, or both HMCU debug port and ACK module port, must be specified"
STR_BAD_SOCKET_ARG = "Socket server must be in the form server-address:port, e.g. '127.0.0.1:8085'"
STR_SOCKET_WAITING_FOR_CONNECTION = "Socket server waiting for client to connect..."
STR_BAD_SOCKET_SERVER = "Unable to listen on given address and port."
STR_RUNNING_AS_SOCKET_SERVER = "Client connected to socket server."
STR_DEVICE_TYPE_ARG_HELP = "provisioned device type"
STR_DIRECTIVE_CORRELATION_ID_HELP = "directive correlation ID"
STR_DIRECTIVE_CAPABILITY_INSTANCE_HELP = "directive capability instance"
STR_DIRECTIVE_NAMESPACE_HELP = "directive namespace"
STR_DIRECTIVE_NAMES_HELP = "directive names"
STR_EVENT_CORRELATION_ID_HELP = "event correlation ID"
STR_EVENT_CAPABILITY_INSTANCE_HELP = "event capability instance"
STR_EVENT_NAMESPACE_HELP = "event namespace"
STR_EVENT_NAMES_HELP = "event names"
STR_PROPERTY_NAMESPACE_HELP = "property namespace"
STR_PROPERTY_NAMES_HELP = "property names"
STR_PROPERTY_CAPABILITY_INSTANCE_HELP = "property capability instance"
STR_THEN_SPECIFY_DIRECTIVE = "Following the above, you must specify a directive. Use xxx directive "
STR_NO_DIRECTIVE_SPECIFIED = "No directive was specified."

# Analyzer/rules text.
STR_ANALYZING = "Analyzing..."
STR_PASS = "PASS"
STR_FAIL = "FAIL"
STR_NO_ANALYSIS_RULES = "No analysis rules provided."
STR_UNSTABLE_UART_COMMS = "UART communication with the ACK module does not appear stable. "\
                          "Ensure that your ACKPlatform_Receive implementation does not use polling I/O, "\
                          "and that your circular buffer for interrupt or DMA-based operation is at least "\
                          "32 bytes in size. Baud rate should be 115200, 1 stop bit, no parity. Also check "\
                          "for sources of interference with UART operation on your HMCU."
STR_STABLE_UART_COMMS = "UART communication with the ACK module appears stable."
STR_OTA_NOT_RETRIEVED = "The HMCU did not retrieve any of the Over-the-Air update image from the ACK module."
STR_OTA_CHUNK_RETRIES = "{0} chunk(s) had to be retried when downloading the Over-the-Air "\
                        "update image from the ACK module. Your UART communications may be unreliable."
STR_OTA_NOT_APPLIED = "The HMCU did not download and apply the entire {0}-byte Over-the-Air update image."
STR_OTA_APPLIED = "No errors were encountered downloading and applying the Over-the-Air update image "\
                  "from the ACK module."

# Logger messages.
STR_CORRUPT_OR_MISSING_MARKERS = "Approximately {0} markers missing or corrupt."

# Orchestrator.
STR_WAITING_FOR_HMCU = "Waiting for HMCU to be (re-)started."
STR_HMCU_STARTED = "HMCU started."
STR_MARKERS_FULFILLED = "Completed successfully: '{0}'."
STR_MARKERS_TIMEOUT = "Timeout: '{0}' did not complete within {1} seconds."

# Capability-related messages.
STR_UNKNOWN_NAMESPACE = "Unknown namespace {0}."
STR_UNKNOWN_NAMESPACE_DEFINITION_CATEGORY = "No {0} decoder exists for namespace {1}."
STR_UNKNOWN_NAMESPACE_DEFINITION = "Unknown {0} {1} in namespace {2}."
STR_DECODING_AVS_EVENT = "HMCU sent event: correlation id {0}; namespace {1}; instance {2}; timestamp {3}."
STR_DECODING_PROPERTY_STR = "Property: namespace {0}; instance {1}; time of sample {2}; uncertainly milliseconds {3}"
STR_DECODING_EVENT_IN_NAMESPACE = "Event is {0} {1}, with {2} propertie(s)."
STR_DECODING_PROPERTY_VALUE_STR = "{0} {1}: {2}."
STR_MISMATCHED_CORRELATION_ID = "Expected correlation ID {0}; got {1}."
STR_MISMATCHED_NAMESPACE = "Expected namespace {0}; got {1}."
STR_MISMATCHED_INSTANCE_ID = "Expected instance {0}; got {1}."
STR_MISMATCHED_EVENT = "Expected {0} {1} event; got {2} event."
STR_MISMATCHED_PROPERTY_COUNT = "Expected {0} propertie(s); got {1}."
STR_MISMATCHED_PROPERTY_NAMESPACE = "Expected property in namespace {0}; got {1}."
STR_MISMATCHED_PROPERTY_NAME = "Expected {0} {1} property; got {2}."
STR_MISMATCHED_PROPERTY_VALUE = "Expected {0}; got {1}."
STR_EVENT_AS_EXPECTED = "Actual event sent by HMCU matches expected event."