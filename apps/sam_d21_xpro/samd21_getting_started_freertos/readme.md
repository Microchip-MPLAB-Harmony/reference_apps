---
grand_parent: Reference Applications
parent: SAM D21 Xplained Pro Evaluation Kit
title: Getting Started
nav_order: 4
---
<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

# Getting Started with Harmony v3 Drivers on SAM D21 MCU Using FreeRTOS
<h2 style="text-align:center;"> <a href="https://github.com/MicrochipTech/MPLAB-Harmony-Reference-Apps/releases/latest/download/samd21_getting_started_freertos.zip" > Download </a> </h2>

-----
## Description:

> The application reads the current room temperature from the temperature sensor on the I/O1 Xplained Pro Extension Kit.
  The temperature reading is displayed on a serial console periodically every second. Further, the application writes the
  temperature readings to EEPROM. When a character is entered on the console, the last five written temperature values are
  read from the EEPROM and displayed on the console. Also, an LED0 is toggled every time the temperature is displayed on
  the serial console


## Modules/Technology Used:
- Peripheral Modules  
	- PORTS
	- SERCOM(I2C)
	- SERCOM(USART)
- Drivers
	- SERCOM(I2C)
	- USART
- Third Party Libraries
	- FreeRTOS

## Hardware Used:

- [SAM D21 Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/atsamd21-xpro)
- [I/O1 Xplained Pro Extension Kit](https://www.microchip.com/Developmenttools/ProductDetails/ATIO1-XPRO)

## Software/Tools Used:
<span style="color:blue"> *This project has been verified to work with the following versions of software tools:*</span>  

- [MPLAB Harmony v3 "csp" repo v3.8.3](https://github.com/Microchip-MPLAB-Harmony/csp/releases/tag/v3.8.3)  
- [MPLAB Harmony v3 "core" repo v3.8.1](https://github.com/Microchip-MPLAB-Harmony/core/releases/tag/v3.8.1)  
- [MPLAB Harmony v3 "dev_packs" repo v3.8.0](https://github.com/Microchip-MPLAB-Harmony/dev_packs/releases/tag/v3.8.0)  
- [MPLAB Harmony v3 "mhc" repo v3.6.5](https://github.com/Microchip-MPLAB-Harmony/mhc/releases/tag/v3.6.5)  
- [MPLAB Harmony v3 "CMSIS-FreeRTOS" repo v10.3.1](https://github.com/Microchip-MPLAB-Harmony/CMSIS-FreeRTOS/releases/tag/v10.3.1)  
- MPLAB Harmony 3 Launcher Plugin v3.6.2  
- [MPLAB X IDE v5.45](https://www.microchip.com/mplab/mplab-x-ide)  
- [MPLAB XC32 Compiler v2.41](https://www.microchip.com/mplab/compilers)  
- Any Serial Terminal application like Tera Term terminal application.  

<span style="color:blue"> *Because Microchip regularly update tools, occasionally issue(s) could be discovered while using the newer versions of the tools. If the project doesn’t seem to work and version incompatibility is suspected, It is recommended to double-check and use the same versions that the project was tested with.* </span>

## Setup:
- Verify that the temperature sensor (I/O1 Xplained Pro Extension Kit) is connected to Extension Header 1 (EXT1) on the SAM D21 Xplained Pro Evaluation Kit
- The SAM D21 Xplained Pro Evaluation Kit allows using the Embedded Debugger (EDBG) for debugging. Connect the Type-A male to micro-B USB cable to micro-B DEBUG USB port to power and debug the SAM D21 Xplained Pro Evaluation Kit  

  <img src = "images/to_pc.png" width="500" height="425" align="middle">

## Programming hex file:
The pre-built hex file can be programmed by following the below steps

### Steps to program the hex file
- Open MPLAB X IDE
- Close all existing projects in IDE, if any project is opened.
- Go to File -> Import -> Hex/ELF File
- In the "Import Image File" window, Step 1 - Create Prebuilt Project, click the "Browse" button to select the prebuilt hex file.
- Select Device has "ATSAMD21J18A"
- Ensure the proper tool is selected under "Hardware Tool"
- Click on "Next" button
- In the "Import Image File" window, Step 2 - Select Project Name and Folder, select appropriate project name and folder
- Click on "Finish" button
- In MPLAB X IDE, click on "Make and Program Device" Button. The device gets programmed in sometime.
- Follow the steps in "Running the Demo" section below

## Programming/Debugging Application Project:
- Open the project (samd21_getting_started/firmware/drivers_freertos_sam_d21_xpro.X) in MPLAB X IDE
- Ensure "EDBG" is selected as hardware tool to program/debug the application
- Build the code and program the device by clicking on the "make and program" button in MPLAB X IDE tool bar
- Follow the steps in "Running the Demo" section below

## Running the Demo:
- Open the Tera Term terminal application on your PC (from the Windows® Start menu by pressing the Start button)
- Change the baud rate to 115200
- You should see the temperature values (in °F) being displayed on the terminal every second, as shown below  

  <img src = "images/result1.png" width="325" height="185" align="middle">  
- Also, notice the LED0 blinking at one second rate
- You may vary the temperature by placing your finger on the temperature sensor (for a few seconds)  
  <img src = "images/temp_sensor_placement.png" width="500" height="425" align="middle">  
- Press any key to display the last five written temperature values from the EEPROM  
  <img src = "images/result2.png" width="345" height="400" align="middle">  

## Comments:
- Reference Training Module: [Getting Started with Harmony v3 Drivers on SAM D21 MCUs Using FreeRTOS](https://microchipdeveloper.com/harmony3:samd21-getting-started-tm-drivers-freertos)
- This application demo builds and works out of box by following the instructions above in "Running the Demo" section. If you need to enhance/customize this application demo, you need to use the MPLAB Harmony v3 Software framework. Refer links below to setup and build your applications using MPLAB Harmony.
	- [How to Setup MPLAB Harmony v3 Software Development Framework](https://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en1000821)
	- [How to Build an Application by Adding a New PLIB, Driver, or Middleware to an Existing MPLAB Harmony v3 Project](http://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Build_Application_Adding_PLIB_%20Driver_or_Middleware%20_to_MPLAB_Harmony_v3Project_DS90003253A.pdf)  

## Revision:
- v1.2.0 - Released demo application
