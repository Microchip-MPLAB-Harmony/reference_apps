---
grand_parent: Reference Applications
parent: PIC32CM MC00 Curiosity Pro Development Board
title: Getting Started
nav_order: 1
---

<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

# Getting Started Application on PIC32CM MC00 Curiosity Pro Development Board
<h2 align="center"> <a href="https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/pic32cm_mc_curiosity_getting_started.zip" > Download </a> </h2>

-----
## Description:

The application reads current room temperature from the temperature sensor and light level from light sensor on the I/O1 Xplained Pro Extension and sends it to the console.
The application will utilize below peripherals:
- SERCOM0 (as I²C) PLIB to read the temperature from a temperature sensor.
- SERCOM2 (as Universal Synchronous Asynchronous Receiver Transmitter (USART)) PLIBs and STDIO library to print the temperature values on a COM (serial) port terminal application running on a PC.
- The ADC peripheral library is used to read data from the light sensor

## Modules/Technology Used:
- Peripheral Modules
	- SERCOM2(I2C)
	- ADC       
	- SERCOM0(USART)

## Hardware Used:

- [PIC32CM MC00 Curiosity Pro Development Board](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV15N46A)
- [I/O1 Xplained Pro Extension Kit](https://www.microchip.com/Developmenttools/ProductDetails/ATIO1-XPRO)   

## Software/Tools Used:
<span style="color:blue"> This project has been verified to work with the following versions of software tools:</span>  

Refer [Project Manifest](./firmware/src/config/pic32cm_mc00_curiosity_pro/harmony-manifest-success.yml) present in harmony-manifest-success.yml under the project folder *firmware/src/config/pic32cm_mc00_curiosity_pro*  
- Refer the [Release Notes](../../../release_notes.md#development-tools) to know the **MPLAB X IDE** and **MCC** Plugin version. Alternatively, [Click Here](https://github.com/Microchip-MPLAB-Harmony/reference_apps/blob/master/release_notes.md#development-tools).
- Any Serial Terminal application like Tera Term terminal application.

<span style="color:blue"> Because Microchip regularly update tools, occasionally issue(s) could be discovered while using the newer versions of the tools. If the project doesn’t seem to work and version incompatibility is suspected, It is recommended to double-check and use the same versions that the project was tested with. </span> To download original version of MPLAB Harmony v3 packages, refer to document [How to Use the MPLAB Harmony v3 Project Manifest Feature](https://ww1.microchip.com/downloads/en/DeviceDoc/How-to-Use-the-MPLAB-Harmony-v3-Project-Manifest-Feature-DS90003305.pdf)

## Setup:
- Connect the PIC32CM MC00 Curiosity Pro Development Board to the Host PC as a USB Device through a Type-A male to micro-B USB cable connected to Micro-B USB (Debug USB) port  
<img src = "images/hardware.jpg" align="middle" width="500" height="500">

## Programming hex file:
The pre-built hex file can be programmed by following the below steps.  

### Steps to program the hex file
- Open MPLAB X IDE
- Close all existing projects in IDE, if any project is opened.
- Go to File -> Import -> Hex/ELF File
- In the "Import Image File" window, Step 1 - Create Prebuilt Project, Click the "Browse" button to select the prebuilt hex file.
- Select Device has "PIC32CM1216MC00048"
- Ensure the proper tool is selected under "Hardware Tool"
- Click on Next button
- In the "Import Image File" window, Step 2 - Select Project Name and Folder, select appropriate project name and folder
- Click on Finish button
- In MPLAB X IDE, click on "Make and Program Device" Button. The device gets programmed in sometime
- Follow the steps in "Running the Demo" section below


## Programming/Debugging Application Project:
- Open the project (pic32cm_mc_curiosity_getting_started/firmware/pic32cm_mc00_curiosity_pro.X) in MPLAB X IDE
- Ensure "PIC32CM MC00 Curiosity pro" is selected as hardware tool to program/debug the application
- Build the code and program the device by clicking on the "make and program" button in MPLAB X IDE tool bar
- Follow the steps in "Running the Demo" section below

## Running the Demo:
- Open the Tera Term terminal application on your PC (from the Windows® Start menu by pressing the Start button)
- Set the baud rate to 9600
- Press the Reset switch on the PIC32CM MC00 Curiosity Pro Development Board.
- The application prints temperature and light sensor continuously.  

	<img src = "images/console_message_after_reset.png" align="middle">
- Cover the light sensor on the I/O Xplained Pro board by placing your hand over it (or another element to put the light sensor in a dark environment) to vary the light value. Place the finger on the temperature sensor to vary the temperature.  

	<img src = "images/console_message_after_covering_lightsensor.png" align="middle">

## Comments:
- Reference Training Module: [Getting Started with Harmony v3 Peripheral Libraries on SAMC2x MCUs](https://microchipdeveloper.com/harmony3:samc21-getting-started-training-module)
- This application demo builds and works out of box by following the instructions above in "Running the Demo" section. If you need to enhance/customize this application demo, you need to use the MPLAB Harmony v3 Software framework. Refer links below to setup and build your applications using MPLAB Harmony.
	- [How to Setup MPLAB Harmony v3 Software Development Framework](https://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Setup_MPLAB_%20Harmony_v3_Software_Development_Framework_DS90003232C.pdf)
	- [How to Build an Application by Adding a New PLIB, Driver, or Middleware to an Existing MPLAB Harmony v3 Project](http://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Build_Application_Adding_PLIB_%20Driver_or_Middleware%20_to_MPLAB_Harmony_v3Project_DS90003253A.pdf)  

## Revision:
- v1.5.0 Removed MHC support, Regenerated and tested application.
- v1.4.0 Added MCC support, Regenerated and tested application.
- v1.3.0 Regenerated and tested demo application
- v1.2.0 released demo application
