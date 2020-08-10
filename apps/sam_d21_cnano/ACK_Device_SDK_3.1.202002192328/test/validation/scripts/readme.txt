This directory contains the core implementation for the validation tool. Each program (Python script) in
the parent directory consumes modules in this directory, in order to run a simulation that will drive the
HMCU through desired code paths, and to examine and validate the results.

Each such program runs through a relatively fixed set of stages.

    * PARSE command line arguments designating things like the serial ports for debug port and ACP channel,
      plus additional program-specific validation. For example, a program wanting to drive the HMCU through
      its OTA update code paths would likely require the user to specify a .ota file on the command line,
      in addition to the standard arguments. A program wanting to drive the HMCU through its processing
      of Alexa Percentage Controller directives would likely require the user to specify the percentage
      or percentage delta to send in the directive.

    * INITIALIZE by instantiating DebugPort, AcpChannel, Orchestrator, and other objects required to run
      a simulation.

    * PERFORM the actual steps required for the simulation. This is a pattern of calls to set state on the
      AckModule, and then wait (timeout-limited) for Markers to appear in reaction. The steps can also
      optionally include AVS event decoding and validation, and additional rule-based analysis.

      For convenience, the routines used by a program in this stage are architected to throw a special
      exception when validation fails. This allows programs to simply perform their steps without having to
      constantly check return values.

    * ANALYZE using a set of rules. Some kinds of validation can be performed without a separate analysis
      stage, but other kinds are better handled by examining the Log for patterns that may not be obvious or
      even available while the PERFORM part of the program is running.

    * INFORM the user of whether the validation passed or failed. This is not strictly required, but this
      codebase considers it good practice to print a PASS or FAIL as the final logged output from a program.

      Programs also should return a 0 exit code for a PASS final result, or non-0 for FAIL.

The major modules in this directory are as follows.

    AckModule -- simulates an ACK connectivity module's functionality, and manages state such as (simulated)
        connectivity status, setup stage, availability of an OTA update, and events to deliver to the HMCU.
        This component provides functionality to query and set that state, which is exchanged with the
        HMCU as the HMCU sends ACP commands and requests incoming events.

    AcpChannel -- provides ACP message-oriented read/write support over a serial port. The serial port
        must provide TX/RX with the HMCU, and have its RTS and CTS pins connected to the HMCU pins
        for module HOSTINT and RESET. This requires a USB-TTL adapter.

    AcpServer -- provides high-level support for the ACP protocol, and sending and receiving ACP messages
        over an AcpChannel.

    Analyzer -- provides rule-based analysis using information in the Log.

    Avs, AlexaNamespace, AlexaPercentageController, et al -- provide support for encoding, decoding, logging,
        and comparing directives and events in their respective Alexa namespaces.

    DebugPort -- provides line-oriented read support over a serial port to which the debug port
        of an HMCU is connected.

    HumanReadableStrings -- contains all messages intended to be presented to the end user via the Log.
        This is in support of eventually providing translations. Strings in here are intended to be used
        with Python's str.format, and so have {0}, {1}, etc. embedded in them for substitution at runtime
        with actual values.

    Log -- acts as a sink for all user-facing messages. This includes debug print messages from the HMCU,
        as well as local messages about the state of validation in progress. All user-oriented output
        occurs via the Log. The log also tracks raw data associated with log messages, for use by Analyzer
        rules.

    Marker -- represents an interesting condition on either the HMCU or the AckModule. Fundamentally,
        a Marker is simply a list of strings that can be matched to determine when the interesting conditions
        have actually occurred.
        
        Markers from the HMCU are sent over the debug port using a special format that is recognized and
        acted on by the Orchestrator. The HMCU sends Markers only when the ACK Device SDK is compiled with
        #define ACK_VALIDATION in ack_user_config.h.

    Orchestrator -- manages the state machine associated with running the AcpServer and DebugPort,
        which involves some concurrent programming constructs to enable traffic with both of those
        connections simultaneously. Provides a mechanism for callers to specify Markers to watch for,
        within given timeout constraints.
