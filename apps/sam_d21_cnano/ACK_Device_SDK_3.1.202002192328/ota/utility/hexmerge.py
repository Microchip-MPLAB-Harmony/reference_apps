# Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

# Merges two Intel Hex files. This is useful for e.g. combining the ACK Custom Loader application
# with the HMCU application, for use in the factory.
# DO NOT USE this script as part of the workflow that creates OTA images. OTA images MUST NOT contain
# the Custom Loader application.

import argparse
import intelhex
import sys

assert sys.version_info >= (3, 0)

parser = argparse.ArgumentParser(description = "Merges .hex files.")
parser.add_argument("inputfile", nargs = "+", help = "A .hex file to merge")
parser.add_argument("-o", "--outputfile", required = True, help = "The merged .hex file")

parser.add_argument(
    "-f", "--fill",
    action = "store_true",
    help = "Fill gaps with ff (without this, gaps result in multiple runs)")

args = parser.parse_args()

try:
    hexfile = intelhex.IntelHex(args.inputfile[0])

    for other in args.inputfile[1:]:
        otherhexfile = intelhex.IntelHex(other)
        otherhexfile.start_addr = hexfile.start_addr

        try:
            hexfile.merge(otherhexfile, overlap = "error")
        except:
            print("Merging '{0}': {1}".format(other, sys.exc_info()[1]))
            sys.exit(1)

    if args.fill:
        segments = hexfile.segments()
        if segments is not None:
            for i in range(1, len(segments)):
                end = segments[i - 1][1]
                start = segments[i][0]
                if (start > end):
                    hexfile.puts(end, '\xff' * (start - end))

    hexfile.tofile(args.outputfile, format = "hex")
except:
    print(sys.exc_info()[1])
    sys.exit(1)
