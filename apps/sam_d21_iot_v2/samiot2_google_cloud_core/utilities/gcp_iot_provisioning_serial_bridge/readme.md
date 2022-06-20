---
grand_parent: Reference Applications
parent: SAM D21 IoT V2 Development Board
title: Serial Bridge Application
nav_order: 99
---

<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

# Serial Bridge Application to upgrade ATWINC1510 Firmware and Google Cloud IoT Provisioning

## Description:

> This application hex file acts as a serial bridge between the PC utility (gcp_iot_winc_provisioning) and the ATWINC1510 module on SAM IOT board.
The application interfaces with the PC over UART and with the ATWINC1510 module over the SPI lines.  

> The application receives the ATWINC1510 firmware and Google cloud root certificate bundle from the PC, and programs it into the ATWINC1510 module.

## Modules/Technology Used:

## Hardware Used:
  - [SAM-IoT WG Development Board](https://www.microchip.com/Developmenttools/ProductDetails/)

## Software/Tools Used:
<span style="color:blue"> *This project has been verified to work with the following versions of software tools:*</span>  

 - [MPLAB X IDE v5.50](https://www.microchip.com/mplab/mplab-x-ide)  
 - [MPLAB XC32 Compiler v3.01](https://www.microchip.com/mplab/compilers)

 <span style="color:blue"> *Because Microchip regularly update tools, occasionally issue(s) could be discovered while using the newer versions of the tools. If the project doesn’t seem to work and version incompatibility is suspected, It is recommended to double-check and use the same versions that the project was tested with.* </span>  

## Setup:
- Connect a USB cable to the DEBUG USB port for programming  
<img src = "images/hardware1.png" align="middle">

## Programming hex file:
The pre-built hex file can be programmed by following the below steps

### Steps to program the hex file
- Open MPLAB X IDE
- Close all existing projects in IDE, if any project is opened
- Go to File -> Import -> Hex/ELF File
- In the "Import Image File" window, Step 1 - Create Prebuilt Project, click the "Browse" button to select the prebuilt hex file in "gcp_iot_provisioning_serial_bridge/hex" folder
- Select Device has "ATSAMD21G18A"
- Ensure the proper tool is selected under "Hardware Tool"
- Click on "Next" button
- In the "Import Image File" window, Step 2 - Select Project Name and Folder, select appropriate project name and folder
- Click on "Finish" button
- In MPLAB X IDE, click on "Make and Program Device" Button. The device gets programmed in sometime.
- Follow the steps in "Running the Demo" section below


## Running the Demo
- Ensure the board is powered on (a USB cable is connected to the DEBUG USB port)
- Refer the **"Running the utility"** section in the documentation under utilities/[readme](../readme.md) file

## Comments:
- [How to Setup MPLAB Harmony v3 Software Development Framework](https://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en1000821)
- [How to Build an Application by Adding a New PLIB, Driver, or Middleware to an Existing MPLAB Harmony v3 Project](http://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Build_Application_Adding_PLIB_%20Driver_or_Middleware%20_to_MPLAB_Harmony_v3Project_DS90003253A.pdf)  
- <span style="color:blue"> **MPLAB Harmony v3 is also configurable through MPLAB Code Configurator (MCC). Refer to the below links for specific instructions to use MPLAB Harmony v3 with MCC.**</span>
	- [Create a new MPLAB Harmony v3 project using MCC](https://microchipdeveloper.com/harmony3:getting-started-training-module-using-mcc)
	- [Update and Configure an Existing MHC-based MPLAB Harmony v3 Project to MCC-based Project](https://microchipdeveloper.com/harmony3:update-and-configure-existing-mhc-proj-to-mcc-proj)
	- [Getting Started with MPLAB Harmony v3 Using MPLAB Code Configurator](https://www.youtube.com/watch?v=KdhltTWaDp0)
	- [MPLAB Code Configurator Content Manager for MPLAB Harmony v3 Projects](https://www.youtube.com/watch?v=PRewTzrI3iE)

### Revision:
- v1.5.0 released demo application
