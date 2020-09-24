# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import acp_pb2
import binascii
import concurrent.futures
import google.protobuf.message
import sys
import threading

from AcpChannel import AcpChannel
from DebugPort import DebugPort
from enum import *
from HumanReadableStrings import *

if sys.version_info < (3, 7):
    print(STR_PYTHON_VERSION_REQUIRED.format(3, 7))
    sys.exit(1)

# Runs the ACP protocol, which is used on the UART between the ACK module and the HMCU.
# This class assumes single-threaded operation and is not safe to call from more than one thread
# simultaneously.
class AcpServer:
    ACP_PROTOCOL_MAJOR_VERSION = 1
    ACP_PROTOCOL_MINOR_VERSION = 0

    class AcpRequestKind(Enum):
        COMMAND = 0
        RESPONSE_HEADER = 1
        RESPONSE_BODY = 2

    class AcpRequestError(Enum):
        NONE = 0
        DECODE = 1
        ENCODE = 2
        NO_PENDING_EVENT = 3
        EXCEEDED_MAX_MESSAGE_SIZE = 4
        NO_RESPONSE = 5
        INVALID_REQUEST = 6
        INVALID_CHECKSUM = 7
        INTERNAL_ERROR = 8

    # HMCU sends
    #   5-byte header {'~', 0xD4, '*', 0x94, 'J'}
    #   2-byte version 1, 0
    #   1-byte kind: COMMAND, RESPONSE_HEADER, RESPONSE_BODY (0/1/2)
    #   2-byte data length 
    #   2-byte offset (not used)
    #   4-byte crc32
    #   8-byte reserved (0)
    class AcpRequest:
        BodyWireLength = 19 # Does not include the header, which is handled by AcpChannel.

        # Returns None in case of error, which means the AcpRequest appears corrupt.
        @staticmethod
        def Deserialize(rawData: bytes):
            return AcpServer.AcpRequest(
                rawData[2],
                AcpServer.AcpRequest._RawToInt(rawData[3:5]),    # data length
                AcpServer.AcpRequest._RawToInt(rawData[7:11]))   # crc32

        def __init__(self, rawKind, dataLength, crc32):
            self._rawKind = rawKind
            self._dataLength = dataLength
            self._crc32 = crc32

        def IsKindValid(self) -> bool:
            return self._Kind() is not None
            
        @property
        def Kind(self):
            return self._Kind()

        @property
        def DataLength(self) -> int:
            return self._dataLength

        @property
        def Crc32(self) -> int:
            return self._crc32

        def _Kind(self):
            try:
                return AcpServer.AcpRequestKind(self._rawKind)
            except ValueError:
                return None

        @staticmethod
        def _RawToInt(raw: bytes) -> int:
            value = 0
            for i in raw[::-1]:
                value = (256 * value) + i
            return value

        def __str__(self) -> str:
            return f"Kind = {self._rawKind} ({self._Kind().name}); data length {self.DataLength}, crc32 {self.Crc32:x}"

    # ACK back to HMCU is
    #   1-byte error code (AcpValue_t)
    #   2-byte version (HMCU ignores)
    #   5-byte reserved (0)
    class AcpAck:
        _WireLength = 8

        def __init__(self, error):
            self._error  = error

        @property
        def Error(self):
            return self._error

        def Serialize(self) -> bytearray:
            raw = bytearray(AcpServer.AcpAck._WireLength)
            raw[0] = self._error.value
            raw[1] = AcpServer.ACP_PROTOCOL_MAJOR_VERSION
            raw[2] = AcpServer.ACP_PROTOCOL_MINOR_VERSION
            return raw

    # Response header to HMCU is
    #   2-byte length
    #   4-byte crc32
    #   6-byte reserved
    class AcpResponse:
        _HeaderWireLength = 12

        def __init__(self, body: bytearray):
            self._body = body
            self._length = 0 if (body is None) else len(body)
            self._crc32 = 0 if (body is None) else binascii.crc32(body)

        @property
        def Body(self) -> bytearray:
            return self._body

        @property
        def Length(self) -> int:
            return self._length

        @property
        def Crc32(self) -> int:
            return self._crc32

        def SerializeHeader(self) -> bytearray:
            raw = bytearray(AcpServer.AcpResponse._HeaderWireLength)
            raw[0] = int(self._length % 256)
            raw[1] = int(self._length / 256)
            raw[2] = int(self._crc32 % 256)
            raw[3] = int(self._crc32 / 256) % 256
            raw[4] = int(self._crc32 / 65536) % 256
            raw[5] = int(self._crc32 / 16777216) % 256
            return raw

    def __init__(self, acpChannel: AcpChannel):
        self._acpChannel = acpChannel
        self._responseForHmcu = None

    # Initiates an asynchronous operation which blocks until the ACP wire sync pattern is received.
    # The resulting Future completes only when the pattern has been received. It returns True if the
    # pattern was observed, or False in case of error or shutdown.
    def SyncToRequestFromHmcuAsync(self) -> concurrent.futures.Future:
        return self._acpChannel.SyncAsync()

    # Reads a request from HMCU. The read blocks until a timeout occurs or the request has been received.
    # Call this after the Future from SyncToRequestFromHmcuAsync has completed with result True. It returns
    # an acp_pb2.cmd object if the ACP request was a command. If the ACP request was to read the
    # response header or body, None is returned.
    def ProcessRequestFromHmcu(self):
        requestKind, acpCmd = self._ReceiveRequestFromHmcu()

        if requestKind is None:
            assert acpCmd is None
            # TODO: log protocol error
            self._acpChannel.DrainRead()
            return None

        if requestKind == AcpServer.AcpRequestKind.COMMAND:
            self._responseForHmcu = None
            assert acpCmd is not None
            return acpCmd

        # For reading the response header and body, there should be no acp cmd object. Also we shouldn't
        # be here if there's no response available because _ReceiveRequestFromHmcu should have taken care
        # of that case by sending a nack to the HMCU and returning an error that caused us to return above.
        assert acpCmd is None
        assert self._responseForHmcu is not None

        if requestKind == AcpServer.AcpRequestKind.RESPONSE_HEADER:
            self._acpChannel.Write(self._responseForHmcu.SerializeHeader())
        else:
            assert requestKind == AcpServer.AcpRequestKind.RESPONSE_BODY
            self._acpChannel.Write(self._responseForHmcu.Body)

        return None

    def SetResponseForHmcu(self, response):
        self._responseForHmcu = None
        if response is not None:
            self._responseForHmcu = AcpServer.AcpResponse(response.SerializeToString())

    # Performs one part of an ACP protocol conversation, which includes receiving an ACP request from
    # the HMCU, and sending an ack back to the HMCU.
    # Returns a (request-kind, cmd) tuple. If request-kind is None, then an I/O or protocol error occurred.
    def _ReceiveRequestFromHmcu(self):
        errorReturn = None, None

        # Read and deserialize the request.
        rawRequest = self._acpChannel.Read(AcpServer.AcpRequest.BodyWireLength)
        if rawRequest is None:
            # TODO log I/O error
            return errorReturn

        request = AcpServer.AcpRequest.Deserialize(rawRequest)
        if request is None:
            # TODO log protocol error
            return errorReturn

        # Validate the request.
        error = AcpServer.AcpRequestError.NONE

        if not request.IsKindValid():
            # TODO log invalid request kind
            error = AcpServer.AcpRequestError.INVALID_REQUEST

        elif request.Kind == AcpServer.AcpRequestKind.COMMAND:
            if request.DataLength == 0:
                # TODO log data length zero for COMMAND AcpRequest
                error = AcpServer.AcpRequestError.INVALID_REQUEST

        elif (request.Kind == AcpServer.AcpRequestKind.RESPONSE_HEADER) \
            or (request.Kind == AcpServer.AcpRequestKind.RESPONSE_BODY):
            if request.DataLength == 0:
                if self._responseForHmcu is None:
                    error = AcpServer.AcpRequestError.NO_RESPONSE
            else:
                # TODO log data length non-zero for non-COMMAND AcpRequest
                error = AcpServer.AcpRequestError.INVALID_REQUEST

        else:
            # TODO log invalid request kind.
            error = AcpServer.AcpRequestError.INVALID_REQUEST

        # Send the ACK for the request before trying to read the associated data.
        self._SendAckToHmcu(error)

        if error == AcpServer.AcpRequestError.NONE:
            if request.DataLength > 0:
                data = self._acpChannel.Read(request.DataLength)
                if data is None:
                    # TODO: log I/O error
                    # We don't try to send an ACK to the HMCU in the case of an I/O error,
                    # as the attempt is likely to hang.
                    return errorReturn

                # Validate the data via CRC32.
                if error == AcpServer.AcpRequestError.NONE:
                    crc32 = binascii.crc32(data)
                    if crc32 != request.Crc32:
                        # TODO: log checksum mismatch
                        error = AcpServer.AcpRequestError.INVALID_CHECKSUM

                if error == AcpServer.AcpRequestError.NONE:
                    acpCmd = acp_pb2.cmd()
                    try:
                        acpCmd.ParseFromString(data)
                    except google.protobuf.message.DecodeError:
                        # TODO: log decode error
                        error = AcpServer.AcpRequestError.DECODE

                # Send the ACK for the data.
                self._SendAckToHmcu(error)
            else:
                acpCmd = None

        if error != AcpServer.AcpRequestError.NONE:
            return errorReturn

        return request.Kind, acpCmd

    # Sends a request acknowledgement to the HMCU. Do this in response to having received a request.
    def _SendAckToHmcu(self, error: AcpRequestError):
        self._acpChannel.Write(AcpServer.AcpAck(error).Serialize())
