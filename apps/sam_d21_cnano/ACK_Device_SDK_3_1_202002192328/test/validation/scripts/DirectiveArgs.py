# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import argparse
import os.path
import unittest
import sys

sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "generated-python")))
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "scripts")))

# These must be here even though they're not used directly, because they instantiate available capability,
# directive, event, and property definitions.
import AlexaNamespace
import AlexaEndpointHealth
import AlexaPercentageController
import AlexaPowerController

import Capability
import Program

from HumanReadableStrings import *
from typing import *

# Breaks a list of strings into groups based on a break string. This is conceptually similar to splitting
# a string.
def _BreakIntoGroups(strings: List[str], breakString: str) -> List[List[str]]:
    groups = []
    group = []
    for string in strings:
        if string == breakString:
            groups.append(group)
            group = []
        else:
            group.append(string)
    groups.append(group)
    return groups

def _PopulateSubArgParser(
    argparser: argparse.ArgumentParser,
    definitionCategoryClass,
    namespaceDestinationVariable,
    nameDestinationVariable,
    *,
    correlationIdHelp = None,   # If not None, correlation ID arg is added
    instanceHelp,
    namespaceDestinationVariableHelp,
    nameDestinationVariableHelp):

    requiredArgsGroup = argparser.add_argument_group(STR_REQUIRED_ARGUMENTS)

    if correlationIdHelp is not None:
        requiredArgsGroup.add_argument("-c", "--correlation-id", type = int, required = True, help = correlationIdHelp)
    argparser.add_argument("-i", "--instance", type = int, default = 0, required = False, help = instanceHelp)

    category = definitionCategoryClass.FriendlyName()

    subparsers = argparser.add_subparsers(
        required = True,
        title = category,
        description = None,
        dest = namespaceDestinationVariable,
        help = namespaceDestinationVariableHelp)

    for namespace, definitions in definitionCategoryClass.GetAll().items():
        if len(definitions) > 0:
            subparser = subparsers.add_parser(
                namespace,
                prog = f"{category} {namespace}",
                allow_abbrev = False)

            subsubparsers = subparser.add_subparsers(
                required = True,
                title = argparse.SUPPRESS,
                dest = nameDestinationVariable,
                help = nameDestinationVariableHelp)

            for definition in definitions:
                subsubparser = subsubparsers.add_parser(
                    definition.Name,
                    prog = f"{category} {namespace} {definition.Name}",
                    allow_abbrev = False)
                definition.PopulateCommandLineArguments(subsubparser)

def _PopulateDirectivesArgParser(argparser) -> None:
    _PopulateSubArgParser(
        argparser,
        Capability.DirectiveDefinition,
        "directive_namespace",
        "directive_name",
        instanceHelp = STR_DIRECTIVE_CAPABILITY_INSTANCE_HELP,
        correlationIdHelp = STR_DIRECTIVE_CORRELATION_ID_HELP,
        namespaceDestinationVariableHelp = STR_DIRECTIVE_NAMESPACE_HELP,
        nameDestinationVariableHelp = STR_DIRECTIVE_NAMES_HELP)

def _PopulateEventsArgParser(argparser) -> None:
    _PopulateSubArgParser(
        argparser,
        Capability.EventDefinition,
        "event_namespace",
        "event_name",
        instanceHelp = STR_EVENT_CAPABILITY_INSTANCE_HELP,
        correlationIdHelp = STR_EVENT_CORRELATION_ID_HELP,
        namespaceDestinationVariableHelp = STR_EVENT_NAMESPACE_HELP,
        nameDestinationVariableHelp = STR_EVENT_NAMES_HELP)

def _PopulatePropertiesArgParser(argparser) -> None:
    _PopulateSubArgParser(
        argparser,
        Capability.PropertyDefinition,
        "property_namespace",
        "property_name",
        instanceHelp = STR_PROPERTY_CAPABILITY_INSTANCE_HELP,
        namespaceDestinationVariableHelp = STR_PROPERTY_NAMESPACE_HELP,
        nameDestinationVariableHelp = STR_PROPERTY_NAMES_HELP)

# Argument parser for sending directives and validating resulting events. The command line is as follows:
#   (1 ) Common arguments for things like the serial ports and verbose mode.
#   (2a) The literal string 'directive' followed by a namespace and name designating the directive to send
#   (2b) Additional arguments for the directive, e.g. the percentage value in a set-percentage directive
#   (3a) Zero or more expected events, structured as
#   (3b)    The literal string 'event' followed by a namespace and name designating the event to expect
#   (4a)    Zero or more expected properties, structured as
#   (4b)        The literal string 'property' followed by a namespace and name designating the property to expect
#
# The standard Python argument parser can't handle repeating groups of arguments, e.g. multiple expected events
# or multiple expected properties within an event. To deal with this, we break up the commmand line using
# certain literal strings, and run separate argparers on the resulting groups. For example:
#
#   Argument group                                  Description
#   --------------                                  -----------
#   -pd com5 -pm com9                               common args
#   directive                                       literal used as split point; not passed to any argparser
#   -c 100 V3_ALEXA_PERCENTAGE_CONTROLLER           namespaces for each capability containing any directives
#       ADJUST_PERCENTAGE --delta 17                all possible directives + args, for designated capability
#   event                                           literal used as split point; not passed to any argparser
#   -c 100 V3_ALEXA RESPONSE                        namespaces for each capability containing any events
#       property                                    literal used as split point; not passed to any argparser
#       V3_ALEXA_POWER_CONTROLLER                   namespaces for each capability containing any properties
#       POWER_STATE_PROP --power-state 1            all possible properties + args, for designated capability
#       property                                    literal used as split point; not passed to any argparser
#       V3_ALEXA_PERCENTAGE_CONTROLLER              namespaces for each capability containing any properties
#       PERCENTAGE_PROP --percentage 100            all possible properties +args, for designated capability
#
def ParseArgs():
    # For now, we deal with exactly one directive.
    directiveArgStringGroups = _BreakIntoGroups(sys.argv[1:], "directive")
    assert len(directiveArgStringGroups) > 0
    commonArgStrings = directiveArgStringGroups[0]
    directiveArgStringGroups = directiveArgStringGroups[1:]

    # Standard args (serial ports to use for debug/module communications, etc.).
    argparser = argparse.ArgumentParser(allow_abbrev = False)

    Program.AddStandardArguments(argparser)
    mainArgs = argparser.parse_args(commonArgStrings)
    mainArgs.Directives = []

    # Parse the directive itself (everything before the first 'event' arg).
    if len(directiveArgStringGroups) == 0:
        print(STR_NO_DIRECTIVE_SPECIFIED)
        sys.exit(1)
    for directiveArgStrings in directiveArgStringGroups:

        eventArgStringGroups = _BreakIntoGroups(directiveArgStrings, "event")
        assert len(eventArgStringGroups) > 0
        directiveArgStrings = eventArgStringGroups[0]
        eventArgStringGroups = eventArgStringGroups[1:]

        argparser = argparse.ArgumentParser(prog = "directive", allow_abbrev = False)
        _PopulateDirectivesArgParser(argparser)
        directiveArgs = argparser.parse_args(directiveArgStrings)
        mainArgs.Directives.append(directiveArgs)
        directiveArgs.Events = []

        # Next groups are expected events. Process one event/group at a time.
        for eventArgStrings in eventArgStringGroups:

            # Inside the event args are property args.
            # The first group is for the event itself.
            propertyArgStringGroups = _BreakIntoGroups(eventArgStrings, "property")
            eventArgStrings = propertyArgStringGroups[0]
            propertyArgStringGroups = propertyArgStringGroups[1:]

            argparser = argparse.ArgumentParser(prog = "event", allow_abbrev = False)
            _PopulateEventsArgParser(argparser)
            eventArgs = argparser.parse_args(eventArgStrings)
            eventArgs.Properties = []

            # Process each specified property against all supported properties.
            for propertyArgStrings in propertyArgStringGroups:
                argparser = argparse.ArgumentParser(prog = "property", allow_abbrev = False)
                _PopulatePropertiesArgParser(argparser)
                eventArgs.Properties.append(argparser.parse_args(propertyArgStrings))

            directiveArgs.Events.append(eventArgs)

    return mainArgs

##########################################################################
# Tests
def setUpModule():
    if sys.version_info < (3, 7):
        raise RuntimeError("ERROR: Python 3.7 or later required")

class Tests(unittest.TestCase):
    
    # Test for BreakIntoGroups.
    def _BreakIntoGroupsTest(self, strings, breakString, expectedGroups):
        actualGroups = _BreakIntoGroups(strings, breakString)
        groupCount = len(actualGroups)
        self.assertEqual(groupCount, len(expectedGroups))
        for groupIndex in range(groupCount):
            self.assertListEqual(actualGroups[groupIndex], expectedGroups[groupIndex], msg = f"group #{groupIndex}")

    def setUp(self):
        self.argparser = argparse.ArgumentParser()

    # Tests _BreaksIntoGroups.
    def testBreakIntoGroups(self):
        self._BreakIntoGroupsTest([], "x", [[]])
        self._BreakIntoGroupsTest(["x"], "x", [[], []])
        self._BreakIntoGroupsTest(["y"], "x", [["y"]])
        self._BreakIntoGroupsTest(["x", "y"], "x", [[], ["y"]])
        self._BreakIntoGroupsTest(["y", "x"], "x", [["y"], []])
        self._BreakIntoGroupsTest(["y", "x", "z"], "x", [["y"], ["z"]])
        self._BreakIntoGroupsTest(["y", "x", "z", "x"], "x", [["y"], ["z"], []])
        self._BreakIntoGroupsTest(["x", "x", "x"], "x", [[], [], [], []])
        self._BreakIntoGroupsTest(["z", "x", "x", "x"], "x", [["z"], [], [], []])

if __name__ == "__main__":
    unittest.main()
