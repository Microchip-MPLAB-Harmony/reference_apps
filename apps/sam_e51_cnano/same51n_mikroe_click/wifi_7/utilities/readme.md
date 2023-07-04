---
grand_parent: 32-bit MCU Reference Applications
parent: SAM E51 Curiosity Nano Evaluation Kit
title: ATWINC1510 Firmware upgrade
nav_order: 98
---

<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

# ATWINC1510 Firmware upgrade Guide

## Description:

> This Application uses the WiFi 7 click board (containing Microchip's  ATWINC1510-MR210PB IEEE 802.11 b/g/n module) to enable cloud connectivity. The application's functioning requires the ATWINC1510 module to have firmware compatible with the WiFi software stack running on the ATSAME51 microcontroller(on SAM E51 Curiosity Nano Development Kit). To enable this compatibility, the ATWINC1510 module is updated with the firmware compatible with WiFi software running in the latest released demo.  

[Serial Bridge Application to upgrade ATWINC1510 Firmware](./winc1510_firmware_upgrade_serial_bridge/readme.md)


## <span style="color:blue"> *Complete the above highlighted step before proceeding further* </span>

## Running the utility
- Navigate to **"<Your_Harmony_Framework_Path>\wireless_wifi\utilities\wifi\winc"** and open command prompt.
- The following command line will create and program a firmware image.

  **winc_flash_tool.cmd /p COM3 /d WINC1500/v 19.7.7 /e /x /i prog /w**

    **NOTE** : Respective device COM PORT should be selected in above command and all other serial terminal application should be closed
- Wait till **verify passed** message comes up as shown below  
<img src = "images/firmware_upg.png" align="middle">

### Revision:
- v1.6.0 - Updated steps to upgrade ATWINC1510 firmware. Regenerated and Tested the application. 
- v1.5.0 - Regenerated and tested application.
- v1.4.0 - Released utility.
