# Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
# 
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

import Exceptions
import google.protobuf.text_format
import Util
import v3avs_capabilities.V3Alexa_pb2 as V3Alexa_pb2
import v3avs_capabilities.V3AVS_pb2 as V3AVS_pb2

from enum import *
from HumanReadableStrings import *
from typing import *

# Every capability supported by the simulator defines in its module exactly one instance of this class,
# which models a capability -- a group of directives, events, and properties, plus some metadata to help
# instantiate and access the associated generated protobuf code (from the protobuf compiler). Not all
# capabilities have each of directives, events, or properties; in particular, most have directives and
# properties, but no events.
# The model for a capability is based the way protobuf schemas for ACK capabilities are authored, e.g.:
#   * There's a single directive class, with submessages for each of the capability's directives.
#   * There's a single event class, with submessages for each of the capability's events.
#   * Individual properties each have their own message.
class Capability:
    # The capability store is maintained as follows:
    #
    #   { namespace, (capability, { category, { name, definition } }) }
    #
    # The namespace is an integer value from the V3AVS.Namespace enum in the generated protobuf code.
    # The capability is an instance of this class.
    # The category is the class name of a definition (to express directive, event, property).
    # The name is an integer value from an enum in the generated protobuf code for the capability.
    # The definition is an instance of one of the classes in this module derived from _Definition.
    _store = {}

    def __init__(
        self,
        protoNamespace,
        *,
        directives = [],
        events = [],
        properties = [],
        protoDirectiveClass = None,             # e.g. V3AlexaPowerController_pb2.V3AlexaPowerController.Directive
        protoDirectiveClassNameField = None,    # name of field in protoDirectiveClass which names the directive
        protoDirectiveNameEnum = None,          # e.g. V3AlexaPowerController_pb2.V3AlexaPowerController.DirectiveName
        protoEventClass = None,                 # e.g. V3Alexa_pb2.V3Alexa.Event
        protoEventClassNameField = None,        # name of field in protoEventClass which names the directive
        protoEventNameEnum = None,              # e.g. V3Alexa_pb2.V3Alexa.EventName
        protoPropertyNameEnum = None):          # V3AlexaPowerController_pb2.V3AlexaPowerController.PropertyName

        self._protoNamespace = protoNamespace
        self._protoEventClass = protoEventClass
        self._protoEventClassNameField = protoEventClassNameField
        self._protoEventNameEnum = protoEventNameEnum
        self._protoDirectiveClass = protoDirectiveClass
        self._protoDirectiveClassNameField = protoDirectiveClassNameField
        self._protoDirectiveNameEnum = protoDirectiveNameEnum
        self._protoPropertyNameEnum = protoPropertyNameEnum

        self._AddDefinitions(protoNamespace, DirectiveDefinition, directives)
        self._AddDefinitions(protoNamespace, EventDefinition, events)
        self._AddDefinitions(protoNamespace, PropertyDefinition, properties)

    # Returns the protobuf namespace for the capability, as an integer.
    @property
    def ProtoNamespace(self) -> int:
        return self._protoNamespace

    # Adds a list of definitions to the capability. This is used (only) by the constructor.
    def _AddDefinitions(self, protoNamespace: int, definitionType: type, definitions) -> None:
        category = definitionType.__name__

        if protoNamespace not in Capability._store:
            Capability._store[protoNamespace] = (self, {})
        categoryMap = Capability._store[protoNamespace][1]

        for definition in definitions:
            definition._SetCapability(self)

            if category not in categoryMap:
                categoryMap[category] = {}
            nameMap = categoryMap[category]

            name = definition.ProtoNameValue

            # A given definition should be made at most once.
            assert(name not in nameMap)
            nameMap[name] = definition

    # Finds the capability for a given namespace.
    # Throws ValidationFailure if the given namespace is not known.
    @staticmethod
    def _LookUp(protoNamespace: int):
        capabilityInfo = Capability._store.get(protoNamespace, None)
        if capabilityInfo is None:
            raise Exceptions.ValidationFailure(STR_UNKNOWN_NAMESPACE.format(
                Util.NameForEnumValue(V3AVS_pb2.V3AVS.Namespace, protoNamespace)))
        return capabilityInfo[0]

    # Finds the definition for a namespace+name pair, e.g. the directive definition for
    # percentage-controller set-percentage.
    @staticmethod
    def _LookUpDefinition(definitionType: type, protoNamespace: int, protoName: int):
        capabilityInfo = Capability._store.get(protoNamespace, None)
        if capabilityInfo is None:
            raise Exceptions.ValidationFailure(STR_UNKNOWN_NAMESPACE.format(
                Util.NameForEnumValue(V3AVS_pb2.V3AVS.Namespace, protoNamespace)))
        capability = capabilityInfo[0]
        categoryMap = capabilityInfo[1]

        category = definitionType.__name__
        nameMap = categoryMap.get(category, None)
        if nameMap is None:
            raise Exceptions.ValidationFailure(STR_UNKNOWN_NAMESPACE_DEFINITION_CATEGORY.format(
                definitionType.FriendlyName(),
                Util.NameForEnumValue(V3AVS_pb2.V3AVS.Namespace, protoNamespace)))

        contentClass = nameMap.get(protoName, None)
        if contentClass is None:
            raise Exceptions.ValidationFailure(STR_UNKNOWN_NAMESPACE_DEFINITION.format(
                definitionType.FriendlyName(),
                protoName,
                Util.NameForEnumValue(V3AVS_pb2.V3AVS.Namespace, protoNamespace)))

        return contentClass

    # Returns a dictionary where keys are a namespace, and values are a list of definitions.
    @staticmethod 
    def _GetAll(definitionType: type) -> dict:
        category = definitionType.__name__

        returnDict = {}

        for namespace, capabilityInfo in Capability._store.items():
            namespaceString = V3AVS_pb2.V3AVS.Namespace.Name(namespace)
            categoryMap = capabilityInfo[1]
            definitions = []
            returnDict[namespaceString] = definitions
            if category in categoryMap:
                for definition in categoryMap[category].values():
                    definitions.append(definition)

        return returnDict

# Base class for definitions in a capability.
# Intended as an abstract base class not to be instantiated directly.
class _Definition:
    def __init__(self, *, protoNameValue: int, payloadSubmessageName: str = None):
        self._protoNameValue = protoNameValue
        self._payloadSubmessageName = payloadSubmessageName

    # Populates a standard argparser with command line arguments specific for the definition, e.g.
    # the percentage for a percentage-controller set-percentage directive, or the power-state boolean
    # for a power-controller.
    # Calls _PopulateCommandLineArguments, which must be implemented by a derived class to do the
    # actual work.
    def PopulateCommandLineArguments(self, argparser):
        self._PopulateCommandLineArguments(argparser)

        # Add a callable to the argparser, which can be called later to instantiate a directive, event,
        # or property without having to know which specific definition to instantiate.
        argparser.set_defaults(Create = self.CreateFromCommandLineArguments)

    # Instantiates a pb2 object based on args parsed from the command line based on
    # PopulateCommandLineArguments.
    def CreateFromCommandLineArguments(self, args):
        protoInstance = self.ProtoClass()
        setattr(protoInstance, self.ProtoClassNameField, self.ProtoNameValue)

        # In the generated protobuf bindings, a submessage is set in its parent whenever a field in it is
        # assigned to. However, the submessage might be empty, which would foil that logic, so we do it here
        # explicitly.
        submessage = getattr(protoInstance, self._payloadSubmessageName)
        submessage.SetInParent()

        # This can throw, such as if trying to assign a negative number to a protobuf unsigned integer field.
        try:
            self._PopulateFromCommandLineArguments(protoInstance, args)
        except ValueError as ex:
            raise Exceptions.ArgumentFailure(str(ex))

        return protoInstance

    # Returns the parent Capability.
    # When a Capability is instantiated, it is given lists of directives, events, and properties.
    # For each of those, Capability._SetCapability is called to establish the parent Capability.
    @property
    def Capability(self):
        return getattr(self, "capability")

    # Returns the name which identifies the directive, event, or property within its capability.
    @property
    def ProtoNameValue(self) -> int:
        return self._protoNameValue

    @property
    def PayloadSubmessageName(self):
        return self._payloadSubmessageName

    def _SetCapability(self, capability):
        setattr(self, "capability", capability)

# Models a directive.
# Derived types must implement these static methods:
#   _PopulateCommandLineArguments
#   _PopulateFromCommandLineArguments
class DirectiveDefinition(_Definition):
    # For example, the percentage controller protobuf schema contains:
    #
    #   enum DirectiveName {
    #       SET_PERCENTAGE = 0;
    #       // ...
    #   }
    #
    #   message Directive {
    #       DirectiveName directive_name = 1;
    #       oneof payload {
    #           SetPercentage set_percentage = 2;
    #           // ...
    #       }
    #   }
    #
    # The protoNameValue is e.g. V3AlexaPercentageController_pb2.V3AlexaPercentageController.DirectiveName.SET_PERCENTAGE.
    # The payloadSubmessageName is "set_percentage".
    def __init__(self, *, protoNameValue, payloadSubmessageName):
        super().__init__(protoNameValue = protoNameValue, payloadSubmessageName = payloadSubmessageName)

    @staticmethod
    def FriendlyName():
        return "directive"

    @property
    def Name(self):
        return Util.NameForEnumValue(self.Capability._protoDirectiveNameEnum, self._protoNameValue)

    # Returns a dictionary where keys are a namespace, and values are a list of definitions.
    @staticmethod
    def GetAll():
        return Capability._GetAll(DirectiveDefinition)

    @property
    def ProtoClass(self):
        return self.Capability._protoDirectiveClass

    @property
    def ProtoClassNameField(self):
        return self.Capability._protoDirectiveClassNameField

# Derived types must implement these static methods:
#   _PopulateCommandLineArguments
#   _PopulateFromCommandLineArguments
#   _Decode
#   _Compare
class EventDefinition(_Definition):
    # For example, the percentage controller protobuf schema contains:
    #
    #   enum EventName {
    #       RESPONSE = 0;
    #       // ...
    #   }
    #
    #   message Event {
    #       EventName name = 1;
    #       oneof payload {
    #           Response response = 2;
    #           // ...
    #       }
    #       // ...
    #   }
    #
    # The protoNameValue is e.g. V3Alexa_pb2.V3Alexa.EventName.RESPONSE.
    # The payloadSubmessageName is "response".
    def __init__(self, *, protoNameValue, payloadSubmessageName):
        super().__init__(protoNameValue = protoNameValue, payloadSubmessageName = payloadSubmessageName)

    @staticmethod
    def FriendlyName():
        return "event"

    @property
    def Name(self):
        return Util.NameForEnumValue(self.Capability._protoEventNameEnum, self._protoNameValue)

    # Returns a dictionary where keys are a namespace, and values are a list of definitions.
    @staticmethod
    def GetAll():
        return Capability._GetAll(EventDefinition)

    @property
    def ProtoClass(self):
        return self.Capability._protoEventClass

    @property
    def ProtoClassNameField(self):
        return self.Capability._protoEventClassNameField

    @staticmethod
    def Decode(log, protoNamespace, encodedEvent):
        capability = Capability._LookUp(protoNamespace)

        protoEvent = capability._protoEventClass()
        protoEvent.ParseFromString(encodedEvent)  # TODO catch exceptions indicating payload corruption

        eventDefinition = capability._LookUpDefinition(
            EventDefinition,
            protoNamespace,
            getattr(protoEvent, capability._protoEventClassNameField))

        eventDefinition._Decode(log, protoEvent)

        return protoEvent

    @staticmethod
    def Compare(log, protoNamespace, expectedProtoEvent, actualProtoEvent):
        capability = Capability._LookUp(protoNamespace)

        expectedEventName = getattr(expectedProtoEvent, capability._protoEventClassNameField)
        actualEventName = getattr(actualProtoEvent, capability._protoEventClassNameField)

        if actualEventName != expectedEventName:
            err = STR_MISMATCHED_EVENT.format(
                Util.NameForEnumValue(V3AVS_pb2.V3AVS.Namespace, capability.ProtoNamespace),
                Util.NameForEnumValue(capability._protoEventNameEnum, expectedEventName),
                Util.NameForEnumValue(capability._protoEventNameEnum, actualEventName))
            raise Exceptions.ValidationFailure(err)

        eventDefinition = Capability._LookUpDefinition(EventDefinition, protoNamespace, actualEventName)
        eventDefinition._Compare(expectedProtoEvent, actualProtoEvent)

        # If we get here, events compared as equal. Otherwise an exception would have been raised.
        log.LogLocalString(STR_EVENT_AS_EXPECTED)

# Derived types must implement these static methods:
#   _PopulateCommandLineArguments
#   _PopulateFromCommandLineArguments
#   _CompareValue
class PropertyDefinition(_Definition):
    # For example, the power controller protobuf schema contains:
    #
    #   enum PropertyName {
    #       POWER_STATE_PROP = 0;
    #   }
    #
    #   message PowerStateProperty {
    #       v3avs_types.V3PowerState power_state = 1;
    #   }
    #
    # The protoNameValue is e.g. V3AlexaPowerController_pb2.V3AlexaPowerController.PropertyName.POWER_STATE_PROP.
    # The protoValueClass is e.g. V3AlexaPowerController_pb2.V3AlexaPowerController.PowerStateProperty.
    def __init__(self, *, protoNameValue, protoValueClass):
        super().__init__(protoNameValue = protoNameValue)
        self._protoValueClass = protoValueClass

    @property
    def Name(self):
        return Util.NameForEnumValue(self.Capability._protoPropertyNameEnum, self._protoNameValue)

    @staticmethod
    def FriendlyName():
        return "property"

    # Returns a dictionary where keys are a namespace, and values are a list of definitions.
    @staticmethod
    def GetAll():
        return Capability._GetAll(PropertyDefinition)

    # Creates a property from given command line arguments.
    def CreateFromCommandLineArguments(self, args):
        capability = self.Capability
        protoNameValue = self.ProtoNameValue

        protoProperty = V3Alexa_pb2.V3Alexa.Property()
        protoProperty.v3_namespace = capability.ProtoNamespace
        protoProperty.name = protoNameValue

        protoValue = self._protoValueClass()

        # This can throw, such as if trying to assign a negative number to a protobuf unsigned integer field.
        try:
            self._PopulateFromCommandLineArguments(protoValue, args)
        except ValueError as ex:
            raise Exceptions.ArgumentFailure(str(ex))

        protoProperty.value = protoValue.SerializeToString()

        return protoProperty

    @staticmethod
    def Decode(log, protoProperty: V3Alexa_pb2.V3Alexa.Property):
        if log is not None:
            logString = STR_DECODING_PROPERTY_STR.format(
                Util.NameForEnumValue(V3AVS_pb2.V3AVS.Namespace, protoProperty.v3_namespace),
                protoProperty.instance,
                Util.EpochToString(protoProperty.time_of_sample),
                protoProperty.uncertainty_in_milliseconds)
            log.LogLocalString(logString)

        propertyDefinition = Capability._LookUpDefinition(
            PropertyDefinition,
            protoProperty.v3_namespace,
            protoProperty.name)

        protoValue = propertyDefinition._protoValueClass()
        protoValue.ParseFromString(protoProperty.value)

        if log is not None:
            capability = Capability._LookUp(protoProperty.v3_namespace)
            logString = STR_DECODING_PROPERTY_VALUE_STR.format(
                Util.NameForEnumValue(V3AVS_pb2.V3AVS.Namespace, protoProperty.v3_namespace),
                Util.NameForEnumValue(capability._protoPropertyNameEnum, protoProperty.name),
                google.protobuf.text_format.MessageToString(protoValue, as_one_line = True))
            log.LogLocalString(logString)

        return protoValue

    @staticmethod
    def Compare(
        expectedProtoProperty: V3Alexa_pb2.V3Alexa.Property,
        actualProtoProperty: V3Alexa_pb2.V3Alexa.Property):

        expectedProtoNamespace = expectedProtoProperty.v3_namespace 
        expectedProtoName = expectedProtoProperty.name

        actualProtoNamespace = actualProtoProperty.v3_namespace 
        actualProtoName = actualProtoProperty.name

        if actualProtoNamespace != expectedProtoNamespace:
            err = STR_MISMATCHED_PROPERTY_NAMESPACE.format(
                Util.NameForEnumValue(V3AVS_pb2.V3AVS.Namespace, expectedProtoNamespace),
                Util.NameForEnumValue(V3AVS_pb2.V3AVS.Namespace, actualProtoNamespace))
            raise Exceptions.ValidationFailure(err)

        expectedCapability = Capability._LookUp(expectedProtoNamespace)
        actualCapability = Capability._LookUp(actualProtoNamespace)

        if actualProtoName != expectedProtoName:
            err = STR_MISMATCHED_PROPERTY_NAME.format(
                Util.NameForEnumValue(V3AVS_pb2.V3AVS.Namespace, actualProtoNamespace),
                Util.NameForEnumValue(expectedCapability._protoPropertyNameEnum, expectedProtoName),
                Util.NameForEnumValue(actualCapability._protoPropertyNameEnum, actualProtoName))
            raise Exceptions.ValidationFailure(err)

        expectedDefinition = Capability._LookUpDefinition(
            PropertyDefinition,
            expectedProtoNamespace,
            expectedProtoName)

        actualDefinition = Capability._LookUpDefinition(
            PropertyDefinition,
            actualProtoNamespace,
            actualProtoName)

        expectedValue = expectedDefinition.Decode(None, expectedProtoProperty)
        actualValue = actualDefinition.Decode(None, actualProtoProperty)

        if not actualDefinition._CompareValue(expectedValue, actualValue):
            err = STR_MISMATCHED_PROPERTY_VALUE.format(
                google.protobuf.text_format.MessageToString(expectedValue, as_one_line = True),
                google.protobuf.text_format.MessageToString(actualValue, as_one_line = True))
            raise Exceptions.ValidationFailure(err)
