Sample microwave oven application, which demonstrates use of Alexa Cooking functionality in ACK Device SDK.

Note: this application is a sample only. It may omit functionality that would be required in a
real device. The application’s source code is structured to maximize illustrative utility, and not
to suggest a reference design for any category of device or to provide a definitive framework for
a device’s firmware.

Models a hypothetical simple microwave oven, to which Alexa functionality is added via ACK Device SDK.

The source code is structured into three components:

(1) In Microwave.*: a purely hypothetical, over-simplified microwave oven application, which is assumed
    to run a pre-existing device that does not work with Alexa. 

(2) In Alexa.*: code that integrates the ACK Device SDK into the microwave.

(3) In Hardware.*: a hardware abstraction to which the code in microwave.c delegates in order to actually
    control the microwave's hardware. Because as a sample this code neither assumes nor requires any
    actual microwave hardware, the routines in this file are empty/no-op implementations. The hardware
    abstraction is merely for illustrative purposes, and does not intend to model any specific real-world
    device.

See comments in each file for more information.
