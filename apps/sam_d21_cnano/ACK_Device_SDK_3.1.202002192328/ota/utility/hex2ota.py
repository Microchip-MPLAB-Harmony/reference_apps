# Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

# Converts an Intel .hex file to a binary file suitable as an ACK OTA image.
# Requires IntelHex module ("pip install IntelHex").
#
# See _otafile.py for the format of OTA binary file.

import argparse
import intelhex
import sys

from _otafile import OtaFile

assert sys.version_info >= (3, 0)

parser = argparse.ArgumentParser(description = "Converts a .hex file to an OTA image.")
parser.add_argument("hexfile")
parser.add_argument("otafile")
parser.add_argument("--device-type", "-t", help = "ACK Device Type")
args = parser.parse_args()

# Ensure the device type is an acceptable length.
try:
    OtaFile.ValidateDeviceTypeString(args.device_type)
except ValueError as e:
    print(e)
    sys.exit(1)

try:
    hex = intelhex.IntelHex(args.hexfile)
except:
    print(sys.exc_info()[1])
    sys.exit(1)

byteCount = 1 + hex.maxaddr() - hex.minaddr()
dataBytes = hex.tobinarray()
assert len(dataBytes) == byteCount

with open(args.otafile, "wb") as f:
    ota = OtaFile(deviceType = args.device_type, targetAddress = hex.minaddr(), data = dataBytes)
    ota.WriteTo(f)

