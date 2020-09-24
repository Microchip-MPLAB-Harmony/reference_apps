# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import unittest

# Exception thrown when creating args from command line fails.
class ArgumentFailure(Exception):
    pass

# Exception thrown when waiting for markers to be fulfilled times out.
class ValidationFailure(Exception):
    pass

##########################################################################
# Tests
class Tests(unittest.TestCase):

    def testArgumentFailure(self):
        e = ArgumentFailure("test string 1")
        self.assertIsInstance(e, Exception)
        self.assertEqual("test string 1", str(e))

    def testValidationFailure(self):
        e = ValidationFailure("test string 2")
        self.assertIsInstance(e, Exception)
        self.assertEqual("test string 2", str(e))

if __name__ == "__main__":
    unittest.main()
