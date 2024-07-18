---
grand_parent: Reference Applications
parent: PIC32CM LS00 Curiosity Nano+ Touch Evaluation Kit
title: RSTC Reset Cause
nav_order: 7
---

<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

# Example of RSTC Reset Cause on PIC32CM LS00 Curiosity Nano+ Touch Evaluation Kit
<h2 align="center"> <a href="https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/rstc_reset_cause.zip" > Download </a> </h2>

-----
## Description:
	
> This application demonstrates how the Reset Controller collects the various reset sources and generates reset for the device. 
- **Power On Reset**: Device contains a power-on-reset (POR) detector, which keeps the system reset until power is stable. This eliminates the need for external reset circuitry to guarantee stable operation when powering up the device.
- **VDDCORE Brown Out Reset**: BOD12 will reset the device if a voltage of 1.2 V or below is observed on the I/O pin supplying power to the MCU core (VDDCORE).
- **VDDANA Brown Out Reset**: BOD33 resets the device if the voltage on the VDDANA pin falls below a value configured by the SYSCTRL.
	
	
## Modules/Technology Used:
- Peripheral Modules
	- EVSYS
	- NVMCTRL
	- PM
	- RSTC
	- EIC
	- PORT
	- SERCOM (UART)
	- SYSTICK
	- WDT

	The MCC Harmony project graph with all the components would look like this: 

    <img src = "images/project_graph.png" width="650" height="430" align="center">

## Hardware Used:

- [PIC32CM LS00 Curiosity Nano+ Touch Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV41C56A)

## Software/Tools Used:
<span style="color:blue"> This project has been verified to work with the following versions of software tools:</span>  

Refer [Project Manifest](./firmware/rstc/src/config/pic32cm_ls00_cnano/harmony-manifest-success.yml) present in harmony-manifest-success.yml under the project folder *firmware\rstc\src\config\pic32cm_ls00_cnano*  
- Refer the [Release Notes](../../../../../release_notes.md#development-tools) to know the **MPLAB X IDE** and **MCC** Plugin version. Alternatively, [Click Here](https://github.com/Microchip-MPLAB-Harmony/reference_apps/blob/master/release_notes.md#development-tools).
- Any Serial Terminal application like Tera Term/PuTTY terminal application.

<span style="color:blue"> Because Microchip regularly update tools, occasionally issue(s) could be discovered while using the newer versions of the tools. If the project doesn’t seem to work and version incompatibility is suspected, It is recommended to double-check and use the same versions that the project was tested with. </span> To download original version of MPLAB Harmony v3 packages, refer to document [How to Use the MPLAB Harmony v3 Project Manifest Feature](https://ww1.microchip.com/downloads/en/DeviceDoc/How-to-Use-the-MPLAB-Harmony-v3-Project-Manifest-Feature-DS90003305.pdf)

## Setup:
- Connect the PIC32CM LS00 Curiosity Nano+ Touch Evaluation Kit to the Host PC as a USB Device through a Type-A male to micro-B USB cable connected to Micro-B USB (Debug USB) port  

  <img src = "images/LS00_cnano_setup.png" width="650" height="200" align="middle">
## Programming hex file:
The pre-built hex file can be programmed by following the below steps.  

### Steps to program the hex file
- Open MPLAB X IDE
- Close all existing projects in IDE, if any project is opened.
- Go to File -> Import -> Hex/ELF File
- In the "Import Image File" window, Step 1 - Create Prebuilt Project, Click the "Browse" button to select the prebuilt hex file.
- Select Device has "PIC32CM5164LS00048"
- Ensure the proper tool is selected under "Hardware Tool"
- Click on Next button
- In the "Import Image File" window, Step 2 - Select Project Name and Folder, select appropriate project name and folder
- Click on Finish button
- In MPLAB X IDE, click on "Make and Program Device" Button. The device gets programmed in sometime
- Follow the steps in "Running the Demo" section below


## Programming/Debugging Application Project:
- Open the project (rstc_reset_cause\firmware\rstc\rstc_reset_causegroup) in MPLAB X IDE
- Ensure "PIC32CM LS00 Curiosity Nano" is selected as hardware tool to program/debug the application
- Build the code and program the device by clicking on the "make and program" button in MPLAB X IDE tool bar
- Follow the steps in "Running the Demo" section below

## Running the Demo:
- Open the Tera Term/PuTTY terminal application on your PC (from the Windows® Start menu by pressing the Start button)
- Set the baud rate to 115200
- An LED1 on the PIC32CM LS00 Curiosity Nano+ Touch Evaluation Kit is toggles continuously using the SysTick Timer
  <img src = "images/LS00_cnano_output.png" width="650" height="210" align="middle">
- To Reset the device, run this command: **ipecmd.exe -P32CM5164LS00048 -TPNEDBG -OK** from the following location: *C:\Program Files\Microchip\MPLABX\v6.20\mplab_platform\mplab_ipe*

  <img src = "images/reset_command.png" width="650" height="240" align="middle">
  
  **NOTE**: *The PIC32CM LS00 Curiosity Nano+ Touch Evaluation Kit does not include a reset button. Therefore, the device can be reset by executing the reset command in the CMD prompt.*
- The following message is displayed on the serial terminal
  <img src = "images/console_output_1.png" width="650" height="250" align="middle">
- Watchdog timer is fed periodically using System Timer (SysTick) to prevent the WDT reset and the LED1 is toggled
- Press the SW1 on the PIC32CM LS00 Curiosity Nano+ Touch Evaluation Kit to put the system in deadlock (LED1 should stop blinking)
- WDT will reset the device in four seconds and the demonstration should restart
 
## Tera Term Output:
- <img src = "images/console_output_2.png" width="650" height="340" align="middle">

## Comments:
- Reference Training Module: [Arm TrustZone Getting Started Application on PIC32CM LS60 (Arm Cortex-M23) MCUs](https://developerhelp.microchip.com/xwiki/bin/view/software-tools/harmony/pic32cm-trustzone-getting-started-training-module/)
- This application demo builds and works out of box by following the instructions above in "Running the Demo" section. If you need to enhance/customize this application demo, you need to use the MPLAB Harmony v3 Software framework. Refer links below to setup and build your applications using MPLAB Harmony.
	- [How to Setup MPLAB Harmony v3 Software Development Framework](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU32/ProductDocuments/SupportingCollateral/How-to-Setup-MPLAB-Harmony-v3-Software-Development-Framework-DS90003232.pdf)	
	- [Video - How to Set up the Tools Required to Get Started with MPLAB® Harmony v3 and MCC](https://www.youtube.com/watch?v=0rNFSlsVwVw)	
	- [Create a new MPLAB Harmony v3 project using MCC](https://developerhelp.microchip.com/xwiki/bin/view/software-tools/harmony/getting-started-training-module-using-mcc/)
	- [Update and Configure an Existing MHC-based MPLAB Harmony v3 Project to MCC-based Project](https://developerhelp.microchip.com/xwiki/bin/view/software-tools/harmony/update-and-configure-existing-mhc-proj-to-mcc-proj/)
	- [How to Build an Application by Adding a New PLIB, Driver, or Middleware to an Existing MPLAB Harmony v3 Project](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU32/ProductDocuments/SupportingCollateral/How-to-Build-an-Application-by-Adding-a-New-PLIB-Driver-or-Middleware-to-an-Existing-MPLAB-Harmony-v3-Project-DS90003253.pdf)	

## Revision:
- v1.7.0 - Released demo application