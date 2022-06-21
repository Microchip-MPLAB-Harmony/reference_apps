---
grand_parent: Reference Applications
parent: PIC32MK MCM Curiosity Pro Development Board
title: Getting Started Extended
nav_order: 1
---
<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

# Getting Started Extended Application on PIC32MK MCM Curiosity Pro Development Board
<h2 align="center"> <a href="https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/pic32mk_mcm_curiosity_getting_started_ext.zip" > Download </a> </h2>

-----
## Description

>  This application demonstrates an LED toggle (LED1 toggles when the switch SW1 is pressed and LED3 toggles when switch SW3 is pressed) on a timeout basis and prints the LED toggling rate on the serial terminal. The periodicity of the timeout will change from 500 milliseconds to one second, two seconds, four seconds, and back to 500 milliseconds every time you press the switch SW1 or SW3 on the PIC32MK MCM Curiosity Pro Development Board. The periodicity will not change while switching between SW1 to SW3 or vice versa.

>  The demo application has extended functionality to print the current room temperature periodically when the MikroBus socket is plugged with MikroElectronika Weather Click Board.


## Modules/Technology Used:

- Peripheral Modules
    - SPI
    - Timer
    - Core Timer
    - GPIO
    - UART
    - DMA

## Hardware Used:

- [PIC32MK MCM Curiosity Pro Development Board](https://www.microchip.com/en-us/development-tool/EV31E34A)
- [MikroElectronika Weather Click Board](https://www.mikroe.com/weather-click)

## Software/Tools Used:
<span style="color:blue"> This project has been verified to work with the following versions of software tools:</span>

Refer [Project Manifest](./firmware/src/config/pic32mk_mcm_curiosity_pro/harmony-manifest-success.yml) present in harmony-manifest-success.yml under the project folder *firmware/src/config/pic32mk_mcm_curiosity_pro*
- Refer the [Release Notes](../../../release_notes.md#development-tools) to know the **MPLAB X IDE** and **MCC** Plugin version. Alternatively, [Click Here](https://github.com/Microchip-MPLAB-Harmony/reference_apps/blob/master/release_notes.md#development-tools).
- Any Serial Terminal application like Tera Term terminal application.

<span style="color:blue"> Because Microchip regularly update tools, occasionally issue(s) could be discovered while using the newer versions of the tools. If the project doesn’t seem to work and version incompatibility is suspected, It is recommended to double-check and use the same versions that the project was tested with. </span> To download original version of MPLAB Harmony v3 packages, refer to document [How to Use the MPLAB Harmony v3 Project Manifest Feature](https://ww1.microchip.com/downloads/en/DeviceDoc/How-to-Use-the-MPLAB-Harmony-v3-Project-Manifest-Feature-DS90003305.pdf)

## Hardware Setup 1: <span id="Setup1"><span>
- Connect the Type-A male to Micro-B USB cable to the Micro-B USB to UART port (J400) on the PIC32MK MCM Curiosity Pro Development Board for logs
- Connect the Type-A male to Micro-B USB cable to Micro-B USB DEBUG port (J500) to power and debug the PIC32MK MCM Curiosity Pro Development Board  
  <img src = "images/hardware_setup1.png" align="middle">

### Hardware Modification: <span id="Hardware_Modification"><span>
- The MikroElectronika Weather click board supports both I²C and SPI protocols to communicate with the BME280 temperature sensor. It provides jumpers (resistors) to choose a communication interface between I²C and SPI. By default, I²C is selected as the communication interface. The PIC32MK MCM Curiosity Pro Development Board does not have I²C lines routed to the MikroBus socket; therefore, SPI is chosen as the communication interface to communicate with the temperature sensor. The hardware modification on the MikroElectronika Weather click board is shown in the figure below.

  <img src = "images/hardware_modification.png" width="290" height="290" align="middle">

## Hardware Setup 2: <span id="Setup2"><span>
- Connect the Type-A male to Micro-B USB cable to the Micro-B USB to UART port (J400) on the PIC32MK MCM Curiosity Pro Development Board for logs
- Connect the Type-A male to Micro-B USB cable to Micro-B USB DEBUG port (J500) to power and debug the PIC32MK MCM Curiosity Pro Development Board
- To test the extended functionality, connect the MikroElectronika Weather click board to the MikroBus socket (J300) on the PIC32MK MCM Curiosity Pro Development Board. Ensure the
  above hardware modification before connecting the Weather click board <img src = "images/hardware_setup2.png" align="middle">

## Programming hex file:
The pre-built hex file can be programmed by following the below steps

### Steps to program the hex file
- Open MPLAB X IDE
- Close all existing projects in IDE, if any project is opened.
- Go to File -> Import -> Hex/ELF File
- In the "Import Image File" window, Step 1 - Create Prebuilt Project, click the "Browse" button to select the prebuilt hex file.
- Select Device has "PIC32MK1024MCM100"
- Ensure the proper tool is selected under "Hardware Tool"
- Click on "Next" button
- In the "Import Image File" window, Step 2 - Select Project Name and Folder, select appropriate project name and folder
- Click on "Finish" button
- In MPLAB X IDE, click on "Make and Program Device" Button. The device gets programmed in sometime.
- Follow the steps in "Running the Demo" section below

## Programming/Debugging Application Project:
- Open the project (pic32mk_mcm_curiosity_getting_started_ext/firmware/pic32mk_mcm_curiosity_pro.X) in MPLAB X IDE
- Ensure "Curiosity/Starter Kits (PKOB4)" is selected as hardware tool to program/debug the application
- Build the code and program the device by clicking on the "Make and Program Device" button in MPLAB X IDE tool bar
- Follow the steps in "Running the Demo" section below

## Running the Demo:
- Perform [Hardware Setup 1](#Setup1) steps mentioned above, if not done already.
- Open the Tera Term terminal application on your PC (from the Windows® Start menu by pressing the Start button).
- Set the baud rate to 115200.
- Reset or power cycle the device. LED1 toggles for every 500 milliseconds during power cycle.
- An LED (LED1) on the PIC32MK MCM Curiosity Pro Development Board toggles on every timeout basis and the default periodicity of the timeout is 500 milliseconds.
- And also, the LED toggling rate is displayed on the serial terminal.
- Press the switch SW1 on the PIC32MK MCM Curiosity Pro Development Board to change the periodicity of the timeout to one second.
- Every subsequent pressing of the switch SW1 on the PIC32MK MCM Curiosity Pro Development Board changes the periodicity of the timeout to 2 seconds, 4 seconds, 500 milliseconds, and back to 1 second in cyclic order.
- Press the switch SW3 on the PIC32MK MCM Curiosity Pro Development Board to switch the toggling LED from LED1 to LED3.
- Every subsequent pressing of the switch SW3 on the PIC32MK MCM Curiosity Pro Development Board changes the periodicity of the timeout to 2 seconds, 4 seconds, 500 milliseconds, and back to 1 second in cyclic order.
- Press the switch SW1 on the PIC32MK MCM Curiosity Pro Development Board to switch back the toggling LED from LED3 to LED1.
- See the following figure for the output.  
<img src = "images/result7.png">

- **To Test the Extended functionality using MikroElectronika Weather Click Board:**
    - First perform the [Hardware Modification](#Hardware_Modification) shown above, if not done already.
    - Then perform [Hardware Setup 2](#Setup2) steps mentioned above, if not done already.
    - Reset or power cycle the device. LED1 toggles for every 500 milliseconds during power cycle.
    - The switch SW2 is used to switch between the printing of LED toggling rate or the temperature.
    - Press the switch SW2 on the PIC32MK MCM Curiosity Pro Development Board to read and print the Temperature from the MikroElectronika Weather click board.
    - The temperature read is displayed on a serial console on a periodical basis.
    - Press the switch SW1 (toggles LED1) on the PIC32MK MCM Curiosity Pro Development Board to change the periodicity of the temperature values displayed on the serial console. The periodicity will be changed between 500 milliseconds, one second, two seconds, four seconds, and back to 500 milliseconds every time the user presses the switch SW1 on the PIC32MK MCM Curiosity Pro Development Board.
    - Press the switch SW3 (toggles LED3) on the PIC32MK MCM Curiosity Pro Development Board to change the periodicity of the temperature values displayed on the serial console. The periodicity will be changed between 500 milliseconds, one second, two seconds, four seconds, and back to 500 milliseconds every time the user presses the switch SW3 on the PIC32MK MCM Curiosity Pro Development Board.
    - Finally, Press the switch SW2 on the PIC32MK MCM Curiosity Pro Development Board to switch back to print the LED toggling rate.
    - See the following figure for the output.  
    <img src = "images/result7_extended.png">
-  Note:
    - The periodicity will not change while switching between SW1 to SW3 or vice versa.

## Comments:
- Reference Training Module: [Getting Started with Harmony v3 Peripheral Libraries on PIC32MK GP MCUs](https://microchipdeveloper.com/harmony3:pic32mk-gp-db-getting-started-training-module)
- This application demo builds and works out of box by following the instructions above in "Running the Demo" section. If you need to enhance/customize this application demo, you need to use the MPLAB Harmony v3 Software framework. Refer links below to setup and build your applications using MPLAB Harmony.
	- [How to Setup MPLAB Harmony v3 Software Development Framework](https://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Setup_MPLAB_%20Harmony_v3_Software_Development_Framework_DS90003232C.pdf)
	- [How to Build an Application by Adding a New PLIB, Driver, or Middleware to an Existing MPLAB Harmony v3 Project](http://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Build_Application_Adding_PLIB_%20Driver_or_Middleware%20_to_MPLAB_Harmony_v3Project_DS90003253A.pdf)
	- <span style="color:blue"> **MPLAB Harmony v3 is also configurable through MPLAB Code Configurator (MCC). Refer to the below links for specific instructions to use MPLAB Harmony v3 with MCC.**</span>
		- [Create a new MPLAB Harmony v3 project using MCC](https://microchipdeveloper.com/harmony3:getting-started-training-module-using-mcc)
		- [Update and Configure an Existing MHC-based MPLAB Harmony v3 Project to MCC-based Project](https://microchipdeveloper.com/harmony3:update-and-configure-existing-mhc-proj-to-mcc-proj)
		- [Getting Started with MPLAB Harmony v3 Using MPLAB Code Configurator](https://www.youtube.com/watch?v=KdhltTWaDp0)
		- [MPLAB Code Configurator Content Manager for MPLAB Harmony v3 Projects](https://www.youtube.com/watch?v=PRewTzrI3iE)    

## Revision:
- v1.5.0 - Released demo application
