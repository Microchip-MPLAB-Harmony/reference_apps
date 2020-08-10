# Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

# Simple Intel .hex file dumper.
# Requires IntelHex module ("pip install IntelHex").

import argparse
import intelhex
import sys

assert sys.version_info >= (3, 0)

parser = argparse.ArgumentParser(description = "Simple Intel .hex file dumper")
parser.add_argument("hexfile")
args = parser.parse_args()

try:
    hex = intelhex.IntelHex(args.hexfile)
except:
    print(sys.exc_info()[1])
    sys.exit(1)

segments = hex.segments()
if segments is not None:
    for segment in hex.segments():
        print("  Data run: {0:08X}-{1:08X} ({2:08X})".format(segment[0], segment[1] - 1, segment[1] - segment[0]))

print("   Min/max: {0:08X}/{1:08X} ({2:08X})".format(hex.minaddr(), hex.maxaddr(), 1 + hex.maxaddr() - hex.minaddr()))

if hex.start_addr is not None:
    for startAddr in hex.start_addr.items():
        if startAddr[0] == "EIP":
            print("Entrypoint: {0:08X}".format(startAddr[1]))
        else:
            print("Entrypoint: {0} = {1:08X}".format(startAddr[0], startAddr[1]))
    