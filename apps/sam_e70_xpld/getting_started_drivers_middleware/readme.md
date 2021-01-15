---
grand_parent: Reference Applications
parent: SAM E70 Xplained Evaluation Kit
title: Getting Started with Drivers and Middleware
nav_order: 1
---
<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

# Getting Started with Drivers and Middleware (USB) on SAM MCUs using MPLAB® Harmony v3
-----
## Description:

> This application reads the current room temperature from the [AT30TSE758A](https://www.microchip.com/wwwproducts/en/AT30TSE758A) temperature sensor chip on the I/O1 Xplained Pro every second using I2C. This is indicated by a blinking orange LED on the I/O1 Xplained Pro. Further, it also writes these temperature values into the sensor chip's own integrated EEPROM using the same I2C peripheral instance. The application also uses an ADC channel to read the output voltage of the [TEMT6000](https://www.vishay.com/docs/81579/temt6000.pdf) ambient light sensor on the I/O1 Xplained Pro Extension Kit and displays it as a percentage of the sensor's full-scale output when requested through the serial terminal menu. This serial terminal menu is made available through the SAM E70 Xplained Evaluation Kit's Target USB port by configuring it as a USB CDC class device. This menu allows you to fetch temperature, light sensor data and even toggle the LED on the SAME70 Xplained Evaluation Kit.

## Modules/Technology Used:
- Peripheral Modules  
	- PORTS
	- Timer
- Drivers
	- TWIHS(I2C)
	- USART
	- USB CDC
- System Services
	- Timer
- Middleware
	- USB Device Stack (USBHS)

## Hardware Used:

- [SAM E70 Xplained Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/ATSAME70-XPLD)
- [I/O1 Xplained Pro Extension Kit](https://www.microchip.com/Developmenttools/ProductDetails/ATIO1-XPRO)

## Software/Tools Used:
<span style="color:blue"> *This project has been verified to work with the following versions of software tools:*</span>  

 - [MPLAB Harmony v3 "csp" repo v3.8.3](https://github.com/Microchip-MPLAB-Harmony/csp/releases/tag/v3.8.3)
 - [MPLAB Harmony v3 "core" repo v3.8.1](https://github.com/Microchip-MPLAB-Harmony/core/releases/tag/v3.8.1)
 - [MPLAB Harmony v3 "dev_packs" repo v3.8.0](https://github.com/Microchip-MPLAB-Harmony/dev_packs/releases/tag/v3.8.0)
 - [MPLAB Harmony v3 "mhc" repo v3.6.5](https://github.com/Microchip-MPLAB-Harmony/mhc/releases/tag/v3.6.5)
 - MPLAB Harmony 3 Launcher Plugin v3.6.2
 - [MPLAB X IDE v5.45](https://www.microchip.com/mplab/mplab-x-ide)
 - [MPLAB XC32 Compiler v2.41](https://www.microchip.com/mplab/compilers)
 - Any Serial Terminal application like Tera Term terminal application.

<span style="color:blue"> *Because Microchip regularly update tools, occasionally issue(s) could be discovered while using the newer versions of the tools. If the project doesn’t seem to work and version incompatibility is suspected, It is recommended to double-check and use the same versions that the project was tested with.* </span>

## Setup:
- Verify that the temperature sensor (I/O1 Xplained Pro Extension Kit) is connected to Extension Header 1 (EXT1) on the SAM E70 Xplained Evaluation Kit
- The SAM E70 Xplained Evaluation Kit allows the Embedded Debugger (EDBG) to be used for debugging. Connect the Type-A male to micro-B USB cable to the
  micro-B DEBUG USB port to power and debug the SAM E70 Xplained Evaluation Kit.  

	<img src = "images/hardware_setup.png" width="425" height="370" align="middle">

## Programming hex file:
The pre-built hex file can be programmed by following the below steps

### Steps to program the hex file
- Open MPLAB X IDE
- Close all existing projects in IDE, if any project is opened.
- Go to File -> Import -> Hex/ELF File
- In the "Import Image File" window, Step 1 - Create Prebuilt Project, click the "Browse" button to select the prebuilt hex file.
- Select Device has "ATSAME70Q21B"
- Ensure the proper tool is selected under "Hardware Tool"
- Click on "Next" button
- In the "Import Image File" window, Step 2 - Select Project Name and Folder, select appropriate project name and folder
- Click on "Finish" button
- In MPLAB X IDE, click on "Make and Program Device" Button. The device gets programmed in sometime.
- Follow the steps in "Running the Demo" section below

## Programming/Debugging Application Project:
- Open the project (getting_started_drivers_middleware/firmware/sam_e70_xult.X) in MPLAB X IDE
- Ensure "EDBG" is selected as hardware tool to program/debug the application
- Build the code and program the device by clicking on the "make and program" button in MPLAB X IDE tool bar
- Follow the steps in "Running the Demo" section below

## Running the Demo:
- Open the Tera Term terminal application on your PC (from the Windows® Start menu by pressing the Start button)
<img src = "images/result1.png" width="425" height="235" align="middle">  



## Comments:
- Reference Training Module: [Getting Started with Harmony v3 Drivers and System Services on SAM E70/S70/V70/V71 MCUs](https://microchipdeveloper.com/harmony3:same70-getting-started-training-module-drivers)
- This application demo builds and works out of box by following the instructions above in "Running the Demo" section. If you need to enhance/customize this application demo, you need to use the MPLAB Harmony v3 Software framework. Refer links below to setup and build your applications using MPLAB Harmony.
	- [How to Setup MPLAB Harmony v3 Software Development Framework](https://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en1000821)
	- [How to Build an Application by Adding a New PLIB, Driver, or Middleware to an Existing MPLAB Harmony v3 Project](http://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Build_Application_Adding_PLIB_%20Driver_or_Middleware%20_to_MPLAB_Harmony_v3Project_DS90003253A.pdf)  


## Revision:
- v1.2.0 - Created demo application
