# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
#
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import glob
import importlib
import os.path
import sys
import unittest

# Runs all tests found in *.py in this directory. This assumes that tests for a module are in the module
# itself. Because some modules import other modules, using unittest.discover would cause some tests to be
# discovered and run twice. Instead, the implementation locates and loads the *.py modules manually, and adds
# only those tests which are explicitly in an imported module (and not in modules imported by a module).
if __name__ == "__main__":
    myDirectory = os.path.abspath(os.path.dirname(__file__))

    sys.path.insert(0, myDirectory)
    sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "generated-python")))

    testLoader = unittest.TestLoader()
    testSuite = unittest.TestSuite()

    for pythonFile in glob.glob(os.path.join(myDirectory, "*.py")):
        moduleName = os.path.splitext(os.path.basename(pythonFile))[0]
        module = importlib.import_module(moduleName)
        for suite in testLoader.loadTestsFromModule(module):
            for test in suite:
                if test.__module__ == moduleName:
                    testSuite.addTest(test)

    testRunner = unittest.TextTestRunner(verbosity = 2)
    testRunner.run(testSuite)
