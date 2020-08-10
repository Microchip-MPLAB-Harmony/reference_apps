This codebase is the Host MCU components of the ACK Device SDK, consisting of the ACK Host MCU Implementation
Core and ACK Host MCU sample applications.

Steps to use this code on Arduino Zero:
* Install the Arduino IDE from https://www.arduino.cc/en/Main/Software.
* In the Arduino IDE, install board "Arduino SAMD Boards (32-bits ARM Cortex-M0+)".
* Install ACK Device ACK Host MCU components into the Arduino IDE. There is a
  Python script to do this in the user\platform\arduino directory (Note:
  Python 3 required). After running the script, you will have ACK Host MCU
  sample applications accessible as example sketches in the Arduino IDE's
  File->Examples->AlexaConnectKit_xxx menus.
* In an Arduino AlexaConnectKit example, add your own business logic to handle
  Alexa capabilities such as PowerController and PercentageController.

For a given MCU, a set of platform-specific functions must be implemented.
The functions are delcared in ack_user_platform.h. The Arduino implementation
is in user\platform\arduino\ack_arduino_platform.cpp. For other MCUs, code in
that file must be ported. Ports for certain ST Microelectronics MCUs are in
user\platform\stm32.

FILE/DIRECTORY STRUCTURE

core directory: ACK Host MCU Implementation Core. Common code for all platforms and
    applications.

applications directory: ACK Host MCU sample applications. Portable code only;
    project files for target MCUs and toolchain combinations are under the
    user\platform directory (see below).

include directory: header files for use by your code.

    ack.h: Main interface to ACK Host MCU Implementation Core.

    ack_user_platform.h: Declares platform-specific functions that must be
        implemented when porting from Arduino to your actual Host MCU.

    ack_user_device.h: Declares functions that you must re-implement,
        to provide information about and change the state of your device.

    other files: Contains spearate headers for optional functionality
        you enable by using #define's in your application's ack_user_config.h.
        These are not automatically included by ack.h.

    details directory: Contains separate headers, which are automatically
        included by ack.h.

user\platform\arduino directory: platform-specific implementation for the
    Arduino MCU. Also scripts to install the ACK Host MCU sample applications
    into the Arduino IDE as example sketches.

External directory: code sourced from outside of Amazon.

PRINTING DEBUG MESSAGES

This codebase has 5 debug print levels (DEBUG, INFO, WARNING, ERROR, CRITICAL)
    as defined in ack_debug_print.h. You can define ACK_DEBUG_PRINT_LEVEL
    to be a number between 0 (CRITICAL) to 4 (DEBUG). Any debug printing at a
    level equal to or below ACK_DEBUG_PRINT_LEVEL will be passed to your
    ACKPlatform_DebugPrint function, and debug printing at a higher level
    becomes a no-op.
