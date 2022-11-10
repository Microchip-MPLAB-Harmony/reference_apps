---
grand_parent: Reference Applications
parent: SAM D21 IoT V2 Development Board
title: ATWINC1510 Firmware upgrade
nav_order: 98
---

<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

# ATWINC1510 Firmware upgrade and Root certificate upgrade Guide

## Description:

> The SAM-IoT WZ V2 Development Application uses ATWINC1510-MR210PB IEEE 802.11 b/g/n module to enable cloud connectivity. The application's functioning requires the ATWINC1510 module to have firmware compatible with the WiFi software stack running on the SAM-IoT microcontroller. To enable this compatibility, the  ATWINC1510 module is updated with the firmware compatible with WiFi software running in the latest released demo.  

> The root certificates to identify the IoT node to the Azure cloud platform are programmed in the non-volatile memory of the ATWINC1510 module.  

## <span style="color:blue"> *If you are following readme other than TPDS, please complete below step before proceeding* </span>
[Serial Bridge Application to upgrade ATWINC1510 Firmware](./winc_provisioner/readme.md)


## <span style="color:blue"> *Complete the above highlighted step before proceeding further* </span>

## Running the utility
1. Click on **winc_provisioner.bat**, It automatically downloads WINC firmware package and runs a command using a command prompt.
   <img src = "images/tpds15.png">
   <img src = "images/tpds16.png"> 
2. Select SAM IoT V2 COM PORT from the drop down and click OK 
 
	<img src = "images/tpds17.png">
3. Wait till verify passed message comes up as shown below and then click on enter to close he command prompt, if fails, reconnect the board and try
   <img src = "images/firmware_upg1.png">

### Revision:
- v1.6.0 released utility
