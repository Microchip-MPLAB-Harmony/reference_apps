---
grand_parent: Reference Applications
parent: SAM E51 Curiosity Nano Evaluation Kit
title: ATWINC1510 Firmware upgrade
nav_order: 98
---

<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

# ATWINC1510 Firmware upgrade and Google Cloud IoT Provisioning (Root certificate upgrade) Guide

## Description:

> The Google Cloud IoT Core Application uses the WiFi 7 click board (containing Microchip's  ATWINC1510-MR210PB IEEE 802.11 b/g/n module) to enable cloud connectivity. The application's functioning requires the ATWINC1510 module to have firmware compatible with the WiFi software stack running on the ATSAME51 microcontroller(on SAM E51 Curiosity Nano Development Kit). To enable this compatibility, the  ATWINC1510 module is updated with the firmware compatible with WiFi software running in the latest released demo.  

> The root certificates to identify the IoT node to the Google cloud platform are programmed in the non-volatile memory of the ATWINC1510 module.  

[Serial Bridge Application to upgrade ATWINC1510 Firmware and Google Cloud IoT Provisioning](./gcp_iot_provisioning_serial_bridge/readme.md)


## <span style="color:blue"> *Complete the above highlighted step before proceeding further* </span>

## Running the utility
- Download and extract [same51_gcp_iot_winc_provisioning](https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/same51_gcp_iot_winc_provisioning.zip
) into utilities folder
- Open command prompt and navigate to **"utilities/same51_gcp_iot_winc_provisioning"**
- The following command line will generate a device programming file winc1500_19.7.6.prog.

  **image_tool.exe -c winc1500_19.7.6\config.txt -o winc1500_19.7.6.prog -of prog**  

- The file produced can be used to upgrade a WINC1500 to version 19.6.1 including the firmware, HTTP files and root
certificates.
- The following command line will program a WINC1500 device via the serial port   
    **winc_programmer -p COM29 -d winc1500 -i winc1500_19.7.6.prog -if prog -w -r -pfw winc1500_19.7.6\firmware\programmer_firmware.bin**

    **NOTE** : Respective device COM PORT should be selected in above command and all other serial terminal application should be closed
- Wait till **verify passed** message comes up as shown below  
<img src = "images/firmware_upgrade.png" align="middle">

### Revision:
- v1.4.0 Added MCC support and updated winc firmware with v19.7.6, Regenerated and tested application.
- v1.3.0 released utility
