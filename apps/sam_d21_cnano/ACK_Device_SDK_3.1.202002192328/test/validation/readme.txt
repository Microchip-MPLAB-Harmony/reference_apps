This directory contains Python scripts to perform various kinds of validation on an HMCU application,
and exercise code paths in it, without the use of an ACK module. Instead, you connect your HMCU --
both its debug port and its ACK communications UART -- directly to a PC as described below. You then run
one or more of the Python scripts. No ACK module is used.

Python 3.7 or later is required, with the following optional modules (install with pip): intelhex, protobuf,
pyserial.

To use these scripts, you must do two things.

(1) Add this line:

        #define ACK_VALIDATION
    
    to the ack_user_config.h in any HMCU application, and then recompile and reflash the application.
    Note that you may need to lower the debug print verbosity to enable to application to fit into flash;
    this is controlled by "#define ACK_DEBUG_PRINT_LEVEL" in ack_user_config.h.

(2) Connect your HMCU -- both its debug port and its ACK communications port (the one usually connected to
    the ACK module) to the PC. You do not use an actual ACK module at all.

    For the ACK communications port, you must connect signaling pins in addition the TX and RX pins.
    A USB-TTL adapter such as this one must be used:
    https://www.amazon.com/gp/product/B075N82CDL/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1.

        HMCU pin
        (on its ACK             PC serial port signal
        communications UART)    (on USB-TTL adapter)
        --------------------    ---------------------
        TX                      RX
        RX                      TX
        HOSTINT                 RTS
        RESET                   CTS

    The combination of adapter, device driver, and operating system you use must be capable of controlling
    RTS and CTS as independent signaling lines, separate from typical use of these pins for UART hardware
    flow control. The adapter cited above meets this criteria when used with the standard driver on Windows.
    Other combinations of adapter, device driver, and operating system may work, but have not been tested.

    The way in which you connect the HMCU debug port to the PC depends on whether your HMCU is mounted on
    e.g. a development board which includes serial-over-USB functionality for one of the MCU's UARTs. If so,
    you can typically simply connect the development board's USB port directly to the PC.

    If your HMCU's debug port is instead a bare UART, you will need another USB-TTL adapter as described
    above. Only the TX and RX pins need be connected; there is no other signaling line requirement for the
    HMCU debug port UART.

        HMCU pin            PC serial port signal
        (on its             (on second USB-TTL
        debug port UART)    adapter)
        -----------------   ---------------------
        TX                  RX
        RX                  TX


Some high level information about available scripts follows.

    validate-ota.py: exercises Over-the-Air update of an HMCU. You provide a .ota file created from your
                     HMCU application's .hex file (via ota\utility\hex2ota.py). The script causes your
                     .ota file to be immediately sent to your HMCU application, in the same way as it
                     would be sent from Amazon via the ACK module.

    validate-directive.py: exercises supported directives on your HMCU, and validates events that your HMCU
                     sends as a result of directive processing. This script cases a directive to be sent
                     immediately to your HMCU application, in the same was as it would be sent from Amazon
                     via the ACK module.

                     Example command line, which
                     * Sends a report-state directive, and expects an endpoint health and percentage
                       property value of 0
                     * Sends a percentage controller set-percentage directive to set the percentage to 17
                     * Sends another report-state directive, and expects the percentage property to have
                       changed to 17

                       validate-directive.py -pd com5 -pm com9
                       directive --correlation-id 9 V3_ALEXA REPORT_STATE
                         event --correlation-id 9 V3_ALEXA STATE_REPORT
                           property V3_ALEXA_ENDPOINT_HEALTH CONNECTIVITY_PROP --connectivity 1
                           property V3_ALEXA_PERCENTAGE_CONTROLLER PERCENTAGE_PROP --percentage 0
                       directive --correlation-id 10 V3_ALEXA_PERCENTAGE_CONTROLLER SET_PERCENTAGE --value 17
                         event --correlation-id 10 V3_ALEXA RESPONSE
                           property V3_ALEXA_PERCENTAGE_CONTROLLER PERCENTAGE_PROP --percentage 17
                       directive --correlation-id 11 V3_ALEXA REPORT_STATE
                         event --correlation-id 11 V3_ALEXA STATE_REPORT
                           property V3_ALEXA_ENDPOINT_HEALTH CONNECTIVITY_PROP --connectivity 1
                           property V3_ALEXA_PERCENTAGE_CONTROLLER PERCENTAGE_PROP --percentage 17

Use <script> -h to get more information about how to use a particular script.

