# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import acp_pb2
import concurrent.futures
import google.protobuf.text_format
import queue
import sys
import time
import typing
import v3avs_capabilities.V3AVS_pb2 as V3AVS_pb2

from AcpChannel import AcpChannel
from AcpServer import AcpServer
from enum import Enum
from HumanReadableStrings import *
from Marker import *

if sys.version_info < (3, 7):
    print(STR_PYTHON_VERSION_REQUIRED.format(3, 7))
    sys.exit(1)

# Module provisioning state. Used with the provisioning ACP command.
class ProvisioningState(Enum):
    UNKNOWN = acp_pb2.response.provisioning.provisioning_state.unknown
    NOT_LOCKED = acp_pb2.response.provisioning.provisioning_state.not_locked
    LOCKED = acp_pb2.response.provisioning.provisioning_state.locked

# Module provisioning info. Used with the provisioning ACP command.
class ProvisioningInfo:
    DefaultState = ProvisioningState.LOCKED
    DefaultDeviceType = "TESTDEVTYPE"

    def __init__(self):
        self.State = ProvisioningInfo.DefaultState
        self.DeviceType = ProvisioningInfo.DefaultDeviceType

# Module hardware info. Used with the get_ack_hardware_info ACP command.
class HardwareInfo:
    DefaultDeviceSerialNumber = "GWXXXX9876543210"

    def __init__(self):
        self.DeviceSerialNumber = HardwareInfo.DefaultDeviceSerialNumber

# Setup state. Used with the get_ack_status ACP command.
class SetupStage(Enum):
    NONE = acp_pb2.setup_stages.none
    DISCOVERABLE = acp_pb2.setup_stages.discoverable
    SETUP_IN_PROGRESS = acp_pb2.setup_stages.setup_in_progress
    REGISTERED = acp_pb2.setup_stages.registered
    TIMEOUT = acp_pb2.setup_stages.timeout

# Setup types. Used with the get_ack_status ACP command.
class SetupTypes:
    _notrunning = acp_pb2.setup_types.notrunning
    _ugsBit = acp_pb2.setup_types.ugs
    _bcsBit = acp_pb2.setup_types.bcs
    _ztsBit = acp_pb2.setup_types.zts

    def __init__(self):
        self._x = SetupTypes._notrunning

    @property
    def UGS(self):
        return self._Get(SetupTypes._ugsBit)

    @UGS.setter
    def SetUGS(self, ugs: bool):
        self._Set(ugs, SetupTypes._ugsBit)

    @property
    def BCS(self):
        return self._Get(SetupTypes._bcsBit)

    @BCS.setter
    def SetBCS(self, bcs: bool):
        self._Set(bcs, SetupTypes._bcsBit)

    @property
    def ZTS(self):
        return self._Get(SetupTypes._ztsBit)

    @ZTS.setter
    def SetZTS(self, zts: bool):
        self._Set(zts, SetupTypes._ztsBit)

    def AsInteger(self):
        return self._x

    def _Get(self, bit):
        return (self._x & bit) != 0

    def _Set(self, state, bit):
        if state:
            self._x = self._x | bit
        else:
            self._x = self._x & ~bit

# Firmware version info. Used with the get_firmware_version ACP command.
class FirmwareVersion:
    _DefaultProtocolNumber = 1
    _DefaultBuildNumber = 100
    _DefaultIncrementalVersion = "1000"

    def __init__(self):
        self.ProtocolNumber = FirmwareVersion._DefaultProtocolNumber
        self.BuildNumber = FirmwareVersion._DefaultBuildNumber
        self.IncrementalVersion = FirmwareVersion._DefaultIncrementalVersion

# Maintains state associated with an ACK module.
# Processes ACP requests, responding with local state information. A caller can change that state info
# using various methods on this class provided for that purpose.
class AckModule:

    def __init__(self, acpChannel: AcpChannel, deviceType: str = None):
        self._acpChannel = acpChannel
        self._acpServer = AcpServer(acpChannel)
        self._moduleStarted = False

        # HMCU-facing state.
        #   Time
        #   Connectivity
        #   Factory reset
        #   Setup
        #   Host config info
        #   OTA
        #   Provisioning
        #   Hardware info
        #   Firmware version
        #   Event queue for get-next-event ACP command
        self._isLocalTimeOK = True
        self._isEpochTimeOK = True
        self._isConnected = False
        self._isInFactoryReset = False
        self._setupTypes = SetupTypes()
        self._setupStage = SetupStage.NONE
        self._hostConfigInfo = None
        self._otaImage = None
        self._provisioning = ProvisioningInfo()
        self._hardwareInfo = HardwareInfo()
        self._firmwareVersion = FirmwareVersion()
        self._getNextEventCommandQueue = queue.Queue()

        if deviceType is not None:
            self._provisioning.DeviceType = deviceType

        # Maps the items in the type oneof to a handler.
        self._commandDispatch = dict([
            [ "get_ack_hardware_info_obj", self._ProcessGetHardwareInfoAcpCommand ],
            [ "get_ack_status_obj", self._ProcessGetStatusAcpCommand ],
            [ "get_firmware_version_obj", self._ProcessGetFirmwareVersionAcpCommand ],
            [ "get_next_event_obj", self._ProcessGetNextEventAcpCommand ],
            [ "provisioning_obj", self._ProcessProvisioningAcpCommand ],
            [ "read_host_fw_update_bytes_obj", self._ProcessReadHostFwUpdateBytesAcpCommand ],
            [ "send_alexa_event_obj", self._ProcessSendAlexaEventAcpCommand ],
            [ "write_host_config_obj", self._ProcessWriteHostConfigAcpCommand ] ])

    def IsResetAsserted(self) -> bool:
        return self._acpChannel.IsResetAsserted()

    def Close(self):
        self._acpChannel.Close()

    # Sets the state of local time, used to return a response to the get_ack_status ACP command.
    def SetLocalTimeOK(self, ok: bool):
        self._isLocalTimeOK = ok

    # Sets the state of epoch time, used to return a response to the ACP get_ack_status command.
    def SetEpochTimeOK(self, ok: bool):
        self._isEpochTimeOK = ok

    # Sets connected state, used to return a response to the ACP get_ack_status command.
    def SetIsConnected(self, isConnected: bool):
        self._isConnected = isConnected

    # Sets factory reset state. If transitioning from false to true, causes a factory-reset-requested
    # event to be queued for sending to the HMCU.
    def SetIsInFactoryReset(self, isInFactoryReset: bool):
        wasInReset = self._isInFactoryReset
        self._isInFactoryReset = isInFactoryReset
        if (not wasInReset) and isInFactoryReset:
            factoryReset = acp_pb2.response()
            factoryReset.factory_reset_requested_obj.SetInParent()
            self._QueueEventForHMCU(factoryReset)

    # Sets setup state, used to return a response to the ACP get_ack_status command.
    def SetSetupState(self, setupTypes: SetupTypes, setupStage: SetupStage):
        self._setupTypes = setupTypes
        self._setupStage = setupStage

    # Sets OTA image. If image is not None, causes a host-fw-update-received event to be queued for
    # sending to the HMCU.
    def SetOtaImage(self, image: bytes, force: bool):
        self._otaImage = image
        if self._otaImage is not None:
            otaAvailable = acp_pb2.response()
            otaAvailable.host_fw_update_received_obj.size = len(image)
            otaAvailable.host_fw_update_received_obj.force = force
            otaAvailable.host_fw_update_received_obj.version = "" # unused
            otaAvailable.host_fw_update_received_obj.signature = "" # unused
            self._QueueEventForHMCU(otaAvailable)

    def SetProvisioningInfo(self, provisioningInfo: ProvisioningInfo):
        self._provisioning = provisioningInfo

    def SetHardwareInfo(self, hardwareInfo: HardwareInfo):
        self._hardwareInfo = hardwareInfo

    def SetFirmwareVersion(self, firmwareVersion: FirmwareVersion):
        self.firmwareVersion = firmwareVersion

    def SetBooted(self):
        booted = acp_pb2.response()
        booted.ack_booted_obj.SetInParent()
        self._QueueEventForHMCU(booted)

    def SyncToCommandRequestAsync(self) -> concurrent.futures.Future:
        return self._acpServer.SyncToRequestFromHmcuAsync()

    # Returns a list of markers, if any.
    def ProcessRequest(self) -> typing.List[Marker]:
        self._markers = []
        command = self._acpServer.ProcessRequestFromHmcu()
        if command is not None:
            # _ProcessCommand can return None, which we deliberately pass to the ACP server.
            response = self._ProcessCommand(command)
            self._acpServer.SetResponseForHmcu(response)
        markers = self._markers
        self._markers = None
        return markers

    # Adds a directive to the queue of directives to be sent to the HMCU in response to a
    # get-next-event ACP command.
    def SendDirective(self, *, directive, namespace: int, correlationId: int, instance: int = 0):
        directiveAcpResponse = acp_pb2.response()
        directiveAcpResponse.alexa_directive_received_obj.directive.v3_namespace = namespace
        directiveAcpResponse.alexa_directive_received_obj.directive.correlation_id = correlationId
        directiveAcpResponse.alexa_directive_received_obj.directive.instance = instance
        directiveAcpResponse.alexa_directive_received_obj.directive.payload = directive.SerializeToString()
        self._QueueEventForHMCU(directiveAcpResponse)
    
    def _ProcessCommand(self, acpCmd: acp_pb2.cmd):
        which = acpCmd.WhichOneof("type")
        if which not in self._commandDispatch:
            return self._CreateGenericErrorResponse(acp_pb2.response.generic.error.unknown_command)

        return self._commandDispatch[which](getattr(acpCmd, which))

    # ACP CMD: get_next_event.
    def _ProcessGetNextEventAcpCommand(self, getNextEventObj):
        if self._getNextEventCommandQueue.empty():
            return self._CreateGenericErrorResponse(acp_pb2.response.generic.error.no_pending_event)

        return self._DequeueEventForHMCU()

    # ACP CMD: get_ack_status.
    def _ProcessGetStatusAcpCommand(self, getStatusObj):
        response = acp_pb2.response()
        response.get_ack_status_obj.SetInParent()

        if self._isLocalTimeOK:
            now = time.localtime()
            response.get_ack_status_obj.current_time.hh = now.tm_hour
            response.get_ack_status_obj.current_time.mm = now.tm_min
            response.get_ack_status_obj.current_time.ss = now.tm_sec
        else:
            response.get_ack_status_obj.current_time.hh = -1
            response.get_ack_status_obj.current_time.mm = -1
            response.get_ack_status_obj.current_time.ss = -1

        response.get_ack_status_obj.epoch_seconds = int(time.time()) if self._isEpochTimeOK else 0

        response.get_ack_status_obj.wifi_mode \
            = acp_pb2.wifi_mode.connected if self._isConnected else acp_pb2.wifi_mode.disconnected

        response.get_ack_status_obj.setup_mode = (self._setupStage != SetupStage.NONE)
        response.get_ack_status_obj.setup_types = self._setupTypes.AsInteger()
        response.get_ack_status_obj.setup_stage = self._setupStage.value

        response.get_ack_status_obj.error_code = acp_pb2.response.error_codes.no_error

        return response

    # ACP CMD: get_firmware_version.
    def _ProcessGetFirmwareVersionAcpCommand(self, getFirmwareVersionObj):
        response = acp_pb2.response()

        response.get_firmware_version_obj.protocol_number = self._firmwareVersion.ProtocolNumber
        response.get_firmware_version_obj.build_number = self._firmwareVersion.BuildNumber
        response.get_firmware_version_obj.incremental_version = self._firmwareVersion.IncrementalVersion

        return response

    # ACP CMD: get_hardware_info.
    def _ProcessGetHardwareInfoAcpCommand(self, getHardwareInfoObj):
        response = acp_pb2.response()
        response.get_ack_hardware_info_obj.dsn = self._hardwareInfo.DeviceSerialNumber
        return response
        
    # ACP CMD: send_alexa_event.
    def _ProcessSendAlexaEventAcpCommand(self, sendAlexaEventObj):
        avsEvent = sendAlexaEventObj.event
        self._markers.append(ReceivedEventMarker.FromAvsEvent(avsEvent))
        return self._CreateGenericErrorResponse(acp_pb2.response.generic.error.no_error)

    # ACP CMD: write_host_config.
    def _ProcessWriteHostConfigAcpCommand(self, writeHostConfigObj):
        self._hostConfigVersion = writeHostConfigObj.firmware_version
        self._hostConfigHostInfo = writeHostConfigObj.host_info

        self._markers.append(Marker(MarkerKind.MODULE_RECEIVED_HOST_CONFIG, strings = [str(self._hostConfigVersion)]))

        return self._CreateGenericErrorResponse(acp_pb2.response.generic.error.no_error)

    # ACP CMD: read_host_fw_update_bytes.
    def _ProcessReadHostFwUpdateBytesAcpCommand(self, readHostFwUpdateBytesObj):
        if self._otaImage is None:
            return self._CreateGenericErrorResponse(acp_pb2.response.generic.error.other)

        offset = readHostFwUpdateBytesObj.offset
        length = readHostFwUpdateBytesObj.length

        if (offset + length) > len(self._otaImage):
            return self._CreateGenericErrorResponse(acp_pb2.response.generic.error.host_fw_update_invalid_size)

        otaChunk = acp_pb2.response()
        otaChunk.read_host_fw_update_bytes_obj.bytes = self._otaImage[offset : offset + length]
        return otaChunk

    # ACP CMD: provisioning.
    def _ProcessProvisioningAcpCommand(self, provisioningObj):
        which = provisioningObj.WhichOneof("command")
        response = acp_pb2.response()

        if which == "get_device_type_obj":
            response.provisioning_obj.device_type_obj.device_type = self._provisioning.DeviceType

        elif which == "get_provisioning_state_obj":
            response.provisioning_obj.provisioning_info_obj.state = self._provisioning.State.value

        else:
            response = self._CreateGenericErrorResponse(acp_pb2.response.generic.error.other)
        
        return response

    # Enqueues an event to be sent to the HMCU. The host interrupt pin is set indicating that there is
    # at least one message.
    def _QueueEventForHMCU(self, response: acp_pb2.response):
        self._getNextEventCommandQueue.put(response)
        self._acpChannel.SetHostInterrupt(True)

    # Dequeues an event for sending to the HMCU. Clears the host interrupt pin if the dequeued event was
    # the only one on the queue.
    def _DequeueEventForHMCU(self):
        try:
            response = self._getNextEventCommandQueue.get()
        except queue.Empty:
            return None
        if self._getNextEventCommandQueue.empty():
            self._acpChannel.SetHostInterrupt(False)
        return response

    def _CreateGenericErrorResponse(self, errorCode):
        response = acp_pb2.response()
        response.generic_obj.code = errorCode
        return response
