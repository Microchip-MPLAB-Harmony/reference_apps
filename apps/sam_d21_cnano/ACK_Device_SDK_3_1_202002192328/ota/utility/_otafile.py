# Copyright 2018-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import binascii
import os

MAX_DEVICE_TYPE_STRING_LENGTH = 16

# Class representing OTA files.
# *** NOTE NOTE NOTE! Keep in sync with the lifecycle code that processes an OTA image!
#
# Format of OTA binary file is
#   [ 4 bytes] Signature 'O' 'T' 'A' '@'
#   [16 bytes] Nul-padded device type string (must be ASCII, and non-empty)
#   [ 4 bytes] Target address
#   [ 4 bytes] Byte count
#   [ 4 bytes] CRC32 checksum of data bytes
#   [ N bytes] Data bytes
#
# Values are little-endian.
class OtaFile(object):

    _signatureBytes = b'OTA@'
    _endian = "little"
    _checksumMask = 0xffffffff

    def __init__(self, *, deviceType, targetAddress, data):
        OtaFile.ValidateDeviceTypeString(deviceType)
        self._deviceType = deviceType

        self._targetAddress = targetAddress
        self._data = data

        self._targetAddressBytes = targetAddress.to_bytes(4, OtaFile._endian)
        self._byteCountBytes = len(data).to_bytes(4, OtaFile._endian)

        self._checksum = binascii.crc32(data)
        self._checksum &= OtaFile._checksumMask

    def Signature(self):
        return OtaFile._signatureBytes.decode("ascii")

    def TargetAddress(self):
        return self._targetAddress

    def Data(self):
        return self._data

    def Checksum(self):
        return self._checksum

    def DeviceType(self):
        return self._deviceType

    def WriteTo(self, f):
        f.write(OtaFile._signatureBytes)

        deviceTypeBytes = self._deviceType.encode("ascii")
        assert len(deviceTypeBytes) <= MAX_DEVICE_TYPE_STRING_LENGTH
        f.write(deviceTypeBytes)
        f.write(b'\x00' * (MAX_DEVICE_TYPE_STRING_LENGTH - len(deviceTypeBytes)))

        f.write(self._targetAddressBytes)
        f.write(self._byteCountBytes)

        f.write(self._checksum.to_bytes(4, OtaFile._endian))

        f.write(self._data)

    @staticmethod
    def ReadFrom(f):
        pos = f.tell()
        f.seek(0, os.SEEK_END)
        size = f.tell() - pos
        f.seek(pos, os.SEEK_SET)

        if size < 4:
            raise ValueError("File too small to contain the signature")
        signatureBytes = f.read(4)
        size -= 4
        if signatureBytes != OtaFile._signatureBytes:
            raise ValueError("Incorrect signature")

        if size < MAX_DEVICE_TYPE_STRING_LENGTH:
            raise ValueError("File too small to contain the Device Type")
        deviceTypeBytes = f.read(MAX_DEVICE_TYPE_STRING_LENGTH)
        try:
            deviceType = deviceTypeBytes.decode("ascii").rstrip('\x00')
        except UnicodeDecodeError:
            raise ValueError("Device Type is not a valid ASCII string")
        # We don't bother validating the device type here because we pass the string to the constructor,
        # which does the validation.

        if size < 4:
            raise ValueError("File too small to contain the target address")
        targetAddressBytes = f.read(4)
        size -= 4
        targetAddress = int.from_bytes(targetAddressBytes, OtaFile._endian)

        if size < 4:
            raise ValueError("File too small to contain the byte count")
        byteCountBytes = f.read(4)
        size -= 4
        byteCount = int.from_bytes(byteCountBytes, OtaFile._endian)

        if size < 4:
            raise ValueError("File too small to contain the checksum")
        checksumBytes = f.read(4)
        size -= 4
        checksum = int.from_bytes(checksumBytes, OtaFile._endian)

        if size < byteCount:
            raise ValueError("File too small to contain {0} data bytes".format(byteCount))
        data = f.read(byteCount)
        size -= byteCount

        # Create the OtaFile object. This also performs more validation on the device type string.
        ota = OtaFile(deviceType = deviceType, targetAddress = targetAddress, data = data)

        # Validate checksum
        if ota._checksum != checksum:
            raise ValueError("Incorrect checksum; expected {0:08X}, actual {1:08X}".format(checksum, ota._checksum))

        return ota

    # Raises a ValueException if a device type string is not valid.
    @staticmethod
    def ValidateDeviceTypeString(deviceType):
        deviceTypeValid = (len(deviceType) > 0) and (len(deviceType) <= MAX_DEVICE_TYPE_STRING_LENGTH)
        if deviceTypeValid:
            try:
                deviceType.encode("ascii")
            except UnicodeEncodeError:
                deviceTypeValid = False
        if not deviceTypeValid:
            raise ValueError("Device Type must be a non-empty ASCII string of no more than {0} characters.".format(
                MAX_DEVICE_TYPE_STRING_LENGTH))
