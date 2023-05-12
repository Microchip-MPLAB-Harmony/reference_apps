---
grand_parent: 32-bit MCU Reference Applications
parent: PIC32CM JH01 Curiosity Pro Development Board
title: Getting Started
nav_order: 1
---

<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

# Getting Started Application on PIC32CM JH01 Curiosity Pro Development Board
<h2 align="center"> <a href="https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/pic32cm_jh01_cpro_getting_started.zip " > Download </a> </h2>

-----
## Description:

> This application demonstrates an LED (LED0) toggle on timeout basis and print the LED
	toggling rate on the serial terminal. The periodicity of the timeout will change from
	500 milliseconds to one second, two seconds, four seconds and back to 500 milliseconds
	every time you press the switch SW0 on the PIC32CM JH01 Curiosity Pro Development Board.

>  The demo application has extended functionality to read and print the current room temperature periodically when the extension header (EXT1) is plugged with the I/O1 Xplained Pro Extension Kit. The temperature reading is displayed on a serial console periodically

## Modules/Technology Used:
- Peripheral Modules
	- EIC
	- RTC
	- GPIO
	- DMAC
	- SERCOM (USART)
    - SERCOM(I2C)

## Hardware Used:

- [PIC32CM JH01 Curiosity Pro Development Board](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV81X90A)
- [I/O1 Xplained Pro Extension Kit](https://www.microchip.com/Developmenttools/ProductDetails/ATIO1-XPRO)

## Software/Tools Used:
<span style="color:blue"> This project has been verified to work with the following versions of software tools:</span>  

Refer [Project Manifest](./firmware/src/config/pic32cm_jh01_cpro/harmony-manifest-success.yml) present in harmony-manifest-success.yml under the project folder *firmware/src/config/pic32cm_jh01_cpro*  
- Refer the [Release Notes](../../../release_notes.md#development-tools) to know the **MPLAB X IDE** and **MCC** Plugin version. Alternatively, [Click Here](https://github.com/Microchip-MPLAB-Harmony/reference_apps/blob/master/release_notes.md#development-tools).
- Any Serial Terminal application like Tera Term/PuTTY terminal application.

<span style="color:blue"> Because Microchip regularly update tools, occasionally issue(s) could be discovered while using the newer versions of the tools. If the project doesn’t seem to work and version incompatibility is suspected, It is recommended to double-check and use the same versions that the project was tested with. </span> To download original version of MPLAB Harmony v3 packages, refer to document [How to Use the MPLAB Harmony v3 Project Manifest Feature](https://ww1.microchip.com/downloads/en/DeviceDoc/How-to-Use-the-MPLAB-Harmony-v3-Project-Manifest-Feature-DS90003305.pdf)

## Hardware Setup 1: <span id="Setup1"><span>
- Connect the PIC32CM JH01 Curiosity Pro Development Board to the Host PC as a USB Device through a Type-A male to micro-B USB cable connected to Micro-B USB (Debug USB) port  
  <img src = "images/hardware_jh01.jpg" align="middle">

## Hardware Setup 2: <span id="Setup2"><span>
- Connect the PIC32CM JH01 Curiosity Pro Development Board to the Host PC as a USB Device through a Type-A male to micro-B USB cable connected to Micro-B USB (Debug USB) port
- To test the extended functionality, connect the [I/O1 Xplained Pro Extension Kit](https://www.microchip.com/Developmenttools/ProductDetails/ATIO1-XPRO) to the extension header EXT1 (J200) on the PIC32CM JH01 Curiosity Pro Development Board.
  <img src = "images/hardware_setup2.jpg" align="middle">

## Programming hex file:
The pre-built hex file can be programmed by following the below steps.  

### Steps to program the hex file
- Open MPLAB X IDE
- Close all existing projects in IDE, if any project is opened.
- Go to File -> Import -> Hex/ELF File
- In the "Import Image File" window, Step 1 - Create Prebuilt Project, Click the "Browse" button to select the prebuilt hex file.
- Select Device has "PIC32CM5164JH01100"
- Ensure the proper tool is selected under "Hardware Tool"
- Click on Next button
- In the "Import Image File" window, Step 2 - Select Project Name and Folder, select appropriate project name and folder
- Click on Finish button
- In MPLAB X IDE, click on "Make and Program Device" Button. The device gets programmed in sometime
- Follow the steps in "Running the Demo" section below


## Programming/Debugging Application Project:
- Open the project (pic32cm_jh01_cpro_getting_started/firmware/pic32cm_jh01_cpro.X) in MPLAB X IDE
- Ensure "PIC32CM JH01 Curiosity Pro" is selected as hardware tool to program/debug the application
- Build the code and program the device by clicking on the "make and program" button in MPLAB X IDE tool bar
- Follow the steps in "Running the Demo" section below

## Running the Demo:
- Open the Tera Term/PuTTY terminal application on your PC (from the Windows® Start menu by pressing the Start button)
- Set the baud rate to 115200
- An LED (LED0) on the PIC32CM JH01 Curiosity Pro Development Board toggles on every timeout basis and the default periodicity of the timeout is 500 milliseconds
- And also, the LED toggling rate is displayed on the serial terminal
- Press the switch SW0 on the PIC32CM JH01 Curiosity Pro Development Board to change the default periodicity of the timeout to one second
- Every subsequent pressing of the switch SW0 on the PIC32CM JH01 Curiosity Pro Development Board changes the periodicity of the timeout to 2 seconds, 4 seconds, 500 milliseconds, and back to 1 second in cyclic order
- See the following figure for the output.  
<img src = "images/result_01.png">

- **To Test the Extended functionality using [I/O1 Xplained Pro Extension Kit](https://www.microchip.com/Developmenttools/ProductDetails/ATIO1-XPRO):**
    - Perform [Hardware Setup 2](#Setup2) steps mentioned above, if not done already.
    - Reset or power cycle the device. LED0 toggles for every 500 milliseconds during power cycle and the LED toggling rate is displayed on the serial terminal.
    - Press any key on your Computer's keyboard to read and print the Temperature from the I/O1 Xplained Pro Extension Kit).
    - The temperature read is displayed on a serial console on a periodical basis.
    - The periodicity of reading temperature will be changed between 500 milliseconds, one second, two seconds, four seconds, and back to 500 milliseconds every time the user presses the switch SW0 on the PIC32CM JH01 Curiosity Pro Development Board.
    - Press any key on the keyboard to start printing the LED Toggling rate
    - The subsequent key press from the keyboard switches between printing the LED Toggling rate or temperature values on the serial terminal.
    - See the following figure for the output.  
	<img src = "images/result_02.png">  
	
## Comments:
- Reference Training Module: [Getting Started with Harmony v3 Peripheral Libraries on SAMC2x MCUs](https://microchipdeveloper.com/harmony3:samc21-getting-started-training-module)
- This application demo builds and works out of box by following the instructions above in "Running the Demo" section. If you need to enhance/customize this application demo, you need to use the MPLAB Harmony v3 Software framework. Refer links below to setup and build your applications using MPLAB Harmony.
	- [How to Setup MPLAB Harmony v3 Software Development Framework](https://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Setup_MPLAB_%20Harmony_v3_Software_Development_Framework_DS90003232C.pdf)
	- [How to Build an Application by Adding a New PLIB, Driver, or Middleware to an Existing MPLAB Harmony v3 Project](http://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Build_Application_Adding_PLIB_%20Driver_or_Middleware%20_to_MPLAB_Harmony_v3Project_DS90003253A.pdf)  
	- <span style="color:blue"> **MPLAB Harmony v3 is also configurable through MPLAB Code Configurator (MCC). Refer to the below links for specific instructions to use MPLAB Harmony v3 with MCC.**</span>
		- [Create a new MPLAB Harmony v3 project using MCC](https://microchipdeveloper.com/harmony3:getting-started-training-module-using-mcc)
		- [Update and Configure an Existing MHC-based MPLAB Harmony v3 Project to MCC-based Project](https://microchipdeveloper.com/harmony3:update-and-configure-existing-mhc-proj-to-mcc-proj)
		- [Getting Started with MPLAB Harmony v3 Using MPLAB Code Configurator](https://www.youtube.com/watch?v=KdhltTWaDp0)
		- [MPLAB Code Configurator Content Manager for MPLAB Harmony v3 Projects](https://www.youtube.com/watch?v=PRewTzrI3iE)	

## Revision:
- v1.6.0 - Released demo application
