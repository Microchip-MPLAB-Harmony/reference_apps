# Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import argparse
import sys

from _otafile import OtaFile

parser = argparse.ArgumentParser(description = "Dumps an OTA image.")
parser.add_argument("otafile")
parser.add_argument("--data", "-d", action = "store_true", help = "dump data")
args = parser.parse_args()

try:
    with open(args.otafile, "rb") as f:
        otaFile = OtaFile.ReadFrom(f)
except ValueError as e:
    print("Unable to read OTA file: {0}".format(e))
    sys.exit(1)
except:
    print(sys.exc_info()[1])
    sys.exit(1)

# Dump
print("     Signature: \"{0}\"".format(otaFile.Signature()))
print("   Device Type: \"{0}\"".format(otaFile.DeviceType()))
print("Target address: {0:08X}".format(otaFile.TargetAddress()))
print("     Data size: {0:08X}".format(len(otaFile.Data())))
print("      Checksum: {0:04X}".format(otaFile.Checksum()))

# Dump actual data
if args.data:
    print()

    def PrintLine(data, baseAddress, lineStartAddress, startAddress, count):
        dataOffset = startAddress - baseAddress

        print("{0:08X}: ".format(lineStartAddress), end = "")

        for i in range(lineStartAddress, startAddress):
            print("   ", end = "")
        for i in range(0, count):
            print("{0:02X} ".format(data[dataOffset + i]), end = "")

        print("   ", end = "")

        for i in range(lineStartAddress, startAddress):
            print(" ", end = "")
        for i in range(0, count):
            c = data[dataOffset + i]
            if (c >= 32) and (c <= 127):
                print(chr(c), end = "")
            else:
                print("\xb7", end = "")

        print()

    data = otaFile.Data()
    remaining = len(data)
    baseAddress = otaFile.TargetAddress()

    address = baseAddress
    if (address % 16) != 0:
        lineAddress = address & 0xfffffff0
        count = min(remaining, 16 - (address - lineAddress))
        PrintLine(data, baseAddress, lineAddress, address, count)
        address = lineAddress + 16
        remaining -= count

    while remaining >= 16:
        PrintLine(data, baseAddress, address, address, 16)
        address += 16
        remaining -= 16

    if (remaining > 0):
        PrintLine(data, baseAddress, address, address, remaining)