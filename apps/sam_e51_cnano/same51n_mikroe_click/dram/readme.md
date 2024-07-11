---
grand_parent: 32-bit MCU Reference Applications
parent: SAM E51 Curiosity Nano Evaluation Kit
title: DRAM Click Example
nav_order: 12
---

<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

# DRAM Click example on SAM E51 Curiosity Nano Evaluation Kit
<h2 align="center"> <a href="https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/dram.zip" > Download </a> </h2>

-----
## Description:

> This example demonstrates writing and reading known data to DRAM memory location when the switch is pressed on SAM E51 Curiosity Nano Evaluation Kit. The data read is matched with written data and printed on a serial terminal when the EEPROM test is successful.

## Modules/Technology Used:
- Peripheral Modules
    - EIC
    - GPIO
    - SYSTICK Timer
    - SERCOM (SPI)
    - SERCOM (USART)

## Hardware Used:

- [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)
- [Curiosity Nano Base for Click Boards](https://www.microchip.com/Developmenttools/ProductDetails/AC164162)
- [MikroElektronika DRAM Click](https://www.mikroe.com/dram-click)

## Software/Tools Used:
<span style="color:blue"> This project has been verified to work with the following versions of software tools:</span>

Refer [Project Manifest](./firmware/src/config/default/harmony-manifest-success.yml) present in harmony-manifest-success.yml under the project folder *firmware/src/config/default*
- Refer the [Release Notes](https://github.com/Microchip-MPLAB-Harmony/reference_apps/blob/master/release_notes.md#reference-applications-release-v160-september-2023) to know the **MPLAB X IDE** and **MCC** Plugin version. Alternatively, [Click Here](https://github.com/Microchip-MPLAB-Harmony/reference_apps/blob/master/release_notes.md#reference-applications-release-v160-september-2023).
- Any Serial Terminal application like Tera Term terminal application.

<span style="color:blue"> Because Microchip regularly update tools, occasionally issue(s) could be discovered while using the newer versions of the tools. If the project doesn’t seem to work and version incompatibility is suspected, It is recommended to double-check and use the same versions that the project was tested with. </span> To download original version of MPLAB Harmony v3 packages, refer to document [How to Use the MPLAB Harmony v3 Project Manifest Feature](https://ww1.microchip.com/downloads/en/DeviceDoc/How-to-Use-the-MPLAB-Harmony-v3-Project-Manifest-Feature-DS90003305.pdf)

## Setup:
- Mount SAM E51 Curiosity Nano Evaluation Kit on "CNANO56_HOST_CONN"(U3) connector of Curiosity Nano Base board
- Mount DRAM Click board on mikroBUS click 1 connector of Curiosity Nano Base board
- Connect the SAM E51 Curiosity Nano Evaluation Kit to the Host PC as a USB Device through a Type-A male to micro-B USB cable connected to Micro-B USB (Debug USB) port

  <img src = "images/dram_hardware_setup.jpg" align="middle">

## Programming hex file:
The pre-built hex file can be programmed by following the below steps.

### Steps to program the hex file
- Open MPLAB X IDE
- Close all existing projects in IDE, if any project is opened.
- Go to File -> Import -> Hex/ELF File
- In the "Import Image File" window, Step 1 - Create Prebuilt Project, Click the "Browse" button to select the prebuilt hex file.
- Select Device has "ATSAME51J20A"
- Ensure the proper tool is selected under "Hardware Tool"
- Click on Next button
- In the "Import Image File" window, Step 2 - Select Project Name and Folder, select appropriate project name and folder
- Click on Finish button
- In MPLAB X IDE, click on "Make and Program Device" Button. The device gets programmed in sometime
- Follow the steps in "Running the Demo" section below


## Programming/Debugging Application Project:
- Open the project (dram/firmware/sam_e51_cnano.X) in MPLAB X IDE
- Ensure "PKOB nano" is selected as hardware tool to program/debug the application
- Build the code and program the device by clicking on the "make and program" button in MPLAB X IDE tool bar
- Follow the steps in "Running the Demo" section below

## Running the Demo:
- Open the Tera Term terminal application on your PC (from the Windows® Start menu by pressing the Start button)
- Set the baud rate to 115200
- Press the switch SW0 on the SAM E51 Curiosity Nano Evaluation Kit to test the DRAM by writing and reading know data

    <img src = "images/dram_click_run.png" width="660" height="340" align="middle">
- For every switch press, the SAM E51 Curiosity Nano Evaluation Kit tests the DRAM.

## Instructions to add dram functionality to your application:

You could use this demonstration as an example to add dram functionality to your MPLAB Harmony v3 based application. Follow the below steps.
1. If you haven't downloaded the dram demo yet [Click Here](https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/dram.zip) to download, otherwise go to next step
2. Unzip the downloaded .zip file
3. From the unzipped folder dram/firmware/src, copy the folder **click_routines** to the folder firmware/src under your MPLAB Harmony v3 application project
4. Open MPLAB X IDE
5. Open your application project
6. In the project explorer, Right click on folder **Header Files**
   and add a sub folder **click_routines** by selecting "Add Existing Items from Folders..."
     <img src = "images/header_add.png">

- Click on "Add Folder..." button
    <img src = "images/header_add2.png">

- Select the "click_routines" folder and select "Files of Types" as Header Files
    <img src = "images/header_add3.png">

- Click on "Add" button to add the selected folder
    <img src = "images/header_add4.png">

- The dram click example header files gets added to your project
    <img src = "images/header_add5.png">

7. In the project explorer, Right click on folder **Source Files**
   and add a sub folder **click_routines** by selecting "Add Existing Items from Folders..."
     <img src = "images/source_add.png">

 - Click on "Add Folder..." button
    <img src = "images/source_add2.png">

 - Select the "click_routines" folder and select "Files of Types" as Source Files
    <img src = "images/source_add3.png">

 - Click on "Add" button to add the selected folder
    <img src = "images/source_add4.png">

 - The dram click example source files gets added to your project
    <img src = "images/source_add5.png">

8. The dram click example uses the **SPI** peripheral. The configuration of these peripherals for your application depends on the 32-bit MCU and development board you are using.

    - **Configure SPI**:
        - Add the SPI peripheral block to the MCC project graph
        - Configure SPI Pins using MCC Pin configuration Window
        The SPI configuration depends on
            - 32-bit MCU
            - 32-bit MCU development board
            - The socket on which you have mounted the dram click board
        *Example: The dram click example on SAM E51 Curiosity Nano Evaluation Kit uses mikroBUS socket #1 on the Curiosity Nano Base for Click boards to mount the dram click board. The SPI lines from MCU coming to this socket are from the SERCOM1 peripheral on the MCU.*
        *MCC Project Graph - SPI configuration*
        <img src = "images/spi_config.png">

        *MCC Pin Configurator - SPI Chip select pin configuration*
        <img src = "images/spi_pins.png">


    - **Map Generic Macros**:
        - After generating the project, following the above configuration, map the generic macros used in the click routines to the Harmony PLIB APIs of the 32-bit MCU your project is running on
        - The generic macros should be mapped in the header file click_interface.h

            <img src = "images/click_inter.png">
        *Example: The dram click routines for the example on SAM E51 Curiosity Nano Evaluation Kit uses the following Harmony PLIB APIs*

        <img src = "images/map_click.png">

9. The **click_routines** folder contain an example C source file **dram_example.c**. You could use **dram_example.c** as a reference to add dram functionality in your application.

## Comments:
- Reference Training Module:
    1. [Getting Started with Harmony v3 Peripheral Libraries on SAM D5x/E5x MCUs](https://developerhelp.microchip.com/xwiki/bin/view/software-tools/harmony/same54-getting-started-training-module/)
    2. [Getting Started with Harmony v3 Drivers on SAM E54 MCUs Using FreeRTOS](https://microchipdeveloper.com/harmony3:same54-getting-started-tm-drivers-freertos#Steps_anchor)
    3. [Low Power Application on SAM E54 (Arm® Cortex® M4) MCUs Using MPLAB® Harmony v3 Peripheral Libraries](https://microchipdeveloper.com/harmony3:low-power-application-on-sam-e54)
- This application demo builds and works out of box by following the instructions above in "Running the Demo" section. If you need to enhance/customize this application demo, you need to use the MPLAB Harmony v3 Software framework. Refer links below to setup and build your applications using MPLAB Harmony.
	- [How to Setup MPLAB Harmony v3 Software Development Framework](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU32/ProductDocuments/SupportingCollateral/How-to-Setup-MPLAB-Harmony-v3-Software-Development-Framework-DS90003232.pdf)	
	- [Video - How to Set up the Tools Required to Get Started with MPLAB® Harmony v3 and MCC](https://www.youtube.com/watch?v=0rNFSlsVwVw)	
	- [Create a new MPLAB Harmony v3 project using MCC](https://developerhelp.microchip.com/xwiki/bin/view/software-tools/harmony/getting-started-training-module-using-mcc/)
	- [Update and Configure an Existing MHC-based MPLAB Harmony v3 Project to MCC-based Project](https://developerhelp.microchip.com/xwiki/bin/view/software-tools/harmony/update-and-configure-existing-mhc-proj-to-mcc-proj/)
	- [How to Build an Application by Adding a New PLIB, Driver, or Middleware to an Existing MPLAB Harmony v3 Project](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU32/ProductDocuments/SupportingCollateral/How-to-Build-an-Application-by-Adding-a-New-PLIB-Driver-or-Middleware-to-an-Existing-MPLAB-Harmony-v3-Project-DS90003253.pdf)	

## Revision:
- v1.7.0 - Released the Application Demo

