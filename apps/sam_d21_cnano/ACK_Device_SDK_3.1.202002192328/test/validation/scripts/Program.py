# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import sys
import typing

from AckModule import AckModule
from AcpChannel import AcpChannel
from DebugPort import DebugPort
from HumanReadableStrings import *
from Log import *
from SocketComms import *

def PrintBanner(programBanner, version):
    print(programBanner.format(version))
    print(STR_COPYRIGHT_BANNER)
    print()

def AddStandardArguments(argparser, *, requireDeviceType = False):
    argparser.add_argument("-v", "--verbose", action = "store_true", help = STR_VERBOSE_OUTPUT)

    requiredArgsGroup = argparser.add_argument_group(STR_REQUIRED_ARGUMENTS)
    requiredArgsGroup.add_argument("-pd", "--debug-port", help = STR_HMCU_DEBUG_PORT_ARG_HELP)
    requiredArgsGroup.add_argument("-pm", "--module-port", help = STR_ACK_MODULE_PORT_ARG_HELP)
    requiredArgsGroup.add_argument("-s", "--socket", help = STR_SOCKET_ARG_HELP, metavar = STR_SOCKET_METAVAR)

    if requireDeviceType:
        argsGroup = requiredArgsGroup
    else:
        argsGroup = argparser
    argsGroup.add_argument("-t", "--devicetype", required = requireDeviceType, help = STR_DEVICE_TYPE_ARG_HELP)

# Opens ports, creates common data structures.
def InitializeProgram(args) -> typing.Tuple[Log, DebugPort, AckModule]:
    haveSocket = args.socket is not None
    haveDebugPort = args.debug_port is not None
    haveAcpPort = args.module_port is not None

    if haveSocket:
        if haveDebugPort or haveAcpPort:
            print(STR_BAD_PORT_ARGS)
            sys.exit(1)

        index = args.socket.find(':')
        if (index <= 0):
            print(STR_BAD_SOCKET_ARG)
            sys.exit(1)
        debugPort = SocketComms(args.socket[0:index], int(args.socket[index + 1:]))
        acpChannel = debugPort
        print(STR_SOCKET_WAITING_FOR_CONNECTION)
        if not debugPort.Open():
            print(STR_BAD_SOCKET_SERVER)
            sys.exit(1)
        print(STR_RUNNING_AS_SOCKET_SERVER)

    else:
        if not (haveDebugPort and haveAcpPort):
            print(STR_BAD_PORT_ARGS)
            sys.exit(1)

        try:
            debugPort = DebugPort(args.debug_port)
        except OSError:
            print(STR_INVALID_COM_PORT.format(args.debug_port))
            sys.exit(1)

        try:
            acpChannel = AcpChannel.AcpChannel(args.module_port)
        except OSError as ex:
            print(STR_INVALID_COM_PORT.format(args.module_port))
            sys.exit(1)

    deviceType = args.devicetype if hasattr(args, "devicetype") else None
    return Log(verbose = args.verbose), debugPort, AckModule(acpChannel, deviceType = deviceType)

