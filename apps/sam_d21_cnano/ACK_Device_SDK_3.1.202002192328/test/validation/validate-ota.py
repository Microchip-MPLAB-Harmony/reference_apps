# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

ProgramVersion = "0.5"

import argparse
import os.path
import sys

sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "generated-python")))
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "generated-python", "v3avs_capabilities")))
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "generated-python", "v3avs_types")))
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "scripts")))
sys.path.insert(1, os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..", "ota", "utility")))

import Exceptions

from _otafile import *
from Analyzer import *
from enum import Enum
from HumanReadableStrings import *
from Marker import *
from Orchestrator import *
from Program import *
from Util import *

# Human-readable strings.
STR_SCRIPT_STEP_ADVERTISE_OTA = "Advertise Over-the-Air update to HMCU, and wait for HMCU to succeed or fail retrieving and applying it."
STR_SCRIPT_WAIT_FOR_OTA_APPLY = "Wait for the HMCU to apply the Over-the-Air update image, after having retrieved all of it."
STR_OTA_VALIDATOR = "ACK Device SDK Over-the-Air update validator version {0}."
STR_OTA_IMAGE_FILE_ARG_HELP = "Over-the-Air update image file"
STR_ALLOW_ANY_OTA_IMAGE_FILE_ARG_HELP = "suppress checking whether the Over-the-Air update image file appears valid"
STR_CHECK_NEW_VERSION_HELP = "check for new firmware version after HMCU restarts"
STR_INVALID_OTA_FILE = "Over-the-Air update image file '{0}' does not exist, or is inaccessible."
STR_NOT_OTA_FILE = "File '{0}' is not a valid Over-the-Air update image file. "\
                   "Use hex2ota.py elsewhere in this SDK to create one."
STR_NEW_VERSION_APPLIED = "HMCU restarted into new firmware version {0}."
STR_NEW_VERSION_NOT_APPLIED = "HMCU restarted into firmware version {0}; expected version {1}."

PrintBanner(STR_OTA_VALIDATOR, ProgramVersion)
argparser = argparse.ArgumentParser()
AddStandardArguments(argparser, requireDeviceType = True)
argparser.add_argument("ota_image", metavar = "OTA-IMAGE", help = STR_OTA_IMAGE_FILE_ARG_HELP)
argparser.add_argument("-f", "--force", action = "store_true", help = STR_ALLOW_ANY_OTA_IMAGE_FILE_ARG_HELP)
argparser.add_argument("-n", "--new-version", type = int, help = STR_CHECK_NEW_VERSION_HELP)
args = argparser.parse_args()

# Open and read OTA image file. First check that it appears valid.
if not os.path.isfile(args.ota_image):
    print(STR_INVALID_OTA_FILE.format(args.ota_image))
    sys.exit(1)
with open(args.ota_image, "rb") as f:
    try:
        OtaFile.ReadFrom(f)
    except ValueError as ex:
        if args.force:
            print(STR_WARNING, end = " ")
        print(STR_NOT_OTA_FILE.format(args.ota_image))
        if not args.force:
            sys.exit(1)
    f.seek(0)
    otaImage = f.read()

log, debugPort, ackModule = InitializeProgram(args)
orchestrator = Orchestrator(log, ackModule, debugPort)

# Actual validation steps follow.
# First watch progression to connected lifecycle state, then send the directive and watch for the
# expected result.
try:
    orchestrator.StandardStartupProgressionToConnected()

    ackModule.SetOtaImage(otaImage, args.force)
    orchestrator.WaitForMarkers(
        Marker(MarkerKind.HMCU_OTA_COMPLETE),
        timeout = 100,
        description = STR_SCRIPT_STEP_ADVERTISE_OTA)

    orchestrator.WaitForMarkers(
        Marker(MarkerKind.HMCU_OTA_RESTART_DEVICE),
        timeout = 2,
        description = STR_SCRIPT_WAIT_FOR_OTA_APPLY)

    # Optionally, check that the new version was properly installed.
    if args.new_version is not None:
        delay = 5
        orchestrator.Delay(delay, description = STR_STEP_DELAY_X_SECONDS.format(delay))

        orchestrator._ackModule.SetBooted()
        orchestrator.WaitForMarkers(
            Marker(MarkerKind.HMCU_LIFECYCLE_STATE, strings = ["2"]),
            timeout = 5,
            description = STR_STEP_BOOTED)

        # Wait for host config, which is where the HMCU reports its firmware version. We need the marker
        # itself, from which we extract the firmware version reported by the HMCU.
        receivedMarker = orchestrator.WaitForMarkers(
            Marker(MarkerKind.MODULE_RECEIVED_HOST_CONFIG),
            timeout = 5,
            description = STR_STEP_WAIT_HOST_CONFIG)
        assert len(receivedMarker) == 1
        receivedMarker = receivedMarker[0]

        if int(receivedMarker.Strings[0]) != args.new_version:
            raise Exceptions.ValidationFailure(STR_NEW_VERSION_NOT_APPLIED.format(
                receivedMarker.Strings[0],
                str(args.new_version)))
        log.LogLocalString(STR_NEW_VERSION_APPLIED.format(receivedMarker.Strings[0]))

    success = True

except Exceptions.ValidationFailure as ex:
    log.LogLocalString(str(ex))
    success = False

orchestrator.Close()

if success:
    log.LogLocalString(STR_ANALYZING)
    analyzer = Analyzer(log, [CommunicationsErrorsRule(), OtaUpdateRetrievedAndAppliedRule(len(otaImage))])
    analyzer.Analyze()
    success = analyzer.LogResult()
else:
    log.LogLocalString(STR_FAIL)

sys.exit(0 if success else 1)
