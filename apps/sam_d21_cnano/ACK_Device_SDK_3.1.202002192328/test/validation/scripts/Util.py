# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import os.path
import sys
import time
import unittest

from HumanReadableStrings import *

def EpochToString(epochMilliseconds: int) -> str:
    if (epochMilliseconds is None) or (epochMilliseconds == 0):
        return "-"
        
    seconds = epochMilliseconds / 1000

    string1 = f"{time.strftime('%Y/%m/%d %H:%M:%S', time.gmtime(seconds))}"
    string2 = f"{seconds - int(seconds):.3} UTC"

    # String2 will start with a zero, which isn't what we want.
    if string2.startswith("0."):
        string2 = string2[1:]

    return string1 + string2

def NameForEnumValue(enum, value):
    try:
        return enum.Name(value)
    except ValueError:
        return str(value)

##########################################################################
# Tests
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "generated-python", "v3avs_capabilities")))
import V3AVS_pb2

def setUpModule():
    if sys.version_info < (3, 7):
        raise RuntimeError("ERROR: Python 3.7 or later required")

class Tests(unittest.TestCase):

    def setUp(self):
        pass

    # Tests EpochToString when there is no epoch given.
    def testEpochToStringNone(self):
        string = EpochToString(None)
        self.assertEqual("-", string)
        string = EpochToString(0)
        self.assertEqual("-", string)

    # Tests EpochToString for a real value.
    def testEpochToString(self):
        string = EpochToString(1)
        self.assertEqual("1970/01/01 00:00:00.001 UTC", string)

    # Tests NameForEnumValue when there is no name for the value.
    def testNameForEnumValueNoName(self):
        name = NameForEnumValue(V3AVS_pb2.V3AVS.Namespace, 1000000)
        self.assertEqual("1000000", name)

    # Tests NameForEnumValue when there is a name for the value.
    def testNameForEnumValueHasName(self):
        name = NameForEnumValue(V3AVS_pb2.V3AVS.Namespace, 0)
        self.assertEqual("V3_ALEXA", name)

if __name__ == "__main__":
    unittest.main()
