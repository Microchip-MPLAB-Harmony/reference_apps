---
grand_parent: Reference Applications
parent: SAM E51 Curiosity Nano Evaluation Kit
title: OLED C Click display Example
nav_order: 14
---

<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

# OLED C Click board example on SAM E51 Curiosity Nano Evaluation Kit
<h2 align="center"> <a href="https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/oled_c.zip" > Download </a> </h2>

-----
## Description:

> This example demonstrates the display capability of OLED C Click board on SAM E51 Curiosity Nano Evaluation Kit.


## Modules/Technology Used:
- Peripheral Modules
	- GPIO
	- SERCOM (SPI)
	- Core
	- SPI Driver
	- Legato graphics
	- LE external controller
	- LE SPI 4-line display driver
	- Timer system service
	- GFX core
	- TC0
	- Input system service
  - Systick

## Hardware Used:

- [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)
- [Curiosity Nano Base for Click Boards](https://www.microchip.com/Developmenttools/ProductDetails/AC164162)
- [MikroElektronika OLED C CLICK](https://www.mikroe.com/oled-c-click)

## Software/Tools Used:
<span style="color:blue"> This project has been verified to work with the following versions of software tools:</span>  

Refer [Project Manifest](./firmware/src/config/sam_e51_cnano/harmony-manifest-success.yml) present in harmony-manifest-success.yml under the project folder *firmware/src/config/sam_e51_cnano*  
- Refer the [Release Notes](../../../../release_notes.md#development-tools) to know the {}MPLAB X IDE{} and {}MCC{} Plugin version. Alternatively, [Click Here](https://github.com/Microchip-MPLAB-Harmony/reference_apps/blob/master/release_notes.md#development-tools) 
- Any Serial Terminal application like Tera Term terminal application.

<span style="color:blue"> Because Microchip regularly update tools, occasionally issue(s) could be discovered while using the newer versions of the tools. If the project doesn’t seem to work and version incompatibility is suspected, It is recommended to double-check and use the same versions that the project was tested with. </span> To download original version of MPLAB Harmony v3 packages, refer to document [How to Use the MPLAB Harmony v3 Project Manifest Feature](https://ww1.microchip.com/downloads/en/DeviceDoc/How-to-Use-the-MPLAB-Harmony-v3-Project-Manifest-Feature-DS90003305.pdf)

## Setup:
- Connect the SAM E51 Curiosity Nano Evaluation Kit to the Host PC as a USB Device through a Type-A male to micro-B USB cable connected to Micro-B USB (Debug USB) port
- Mount the OLED C Click board on mikroBUS connector 1 of Curiosity Nano Base

  <img src = "images/oled_c_click_demosetup.jpg" width="700" height="525" align="middle">

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
- Open the project (oled_c/firmware/sam_e51_cnano.X) in MPLAB X IDE
- Ensure "SAM E51 Curiosity Nano" is selected as hardware tool to program/debug the application
- Build the code and program the device by clicking on the "make and program" button in MPLAB X IDE tool bar
- Follow the steps in "Running the Demo" section below

## Running the Demo:
- After power up, when the demo is running, The OLED C Click display shows as below  
<img src = "images/oled_c_click_run.jpg" align="middle">

## Instructions to add OLED C Click display functionality to your application:

The MPLAB Harmony v3 supports adding custom display to your application using Legato (LE) External Display Controller drivers. The LE External Controller driver allows user to configure custom commands necessary for the external display.

Below are Harmony configuration for the OLED C Click
- Connect the display components as shown in the below figure
	<img src = "images/oled_c_click_config.png">  
- Change Configuration of components as shown in the below figures
 - SERCOM Configuration
	<img src = "images/oled_c_sercom.png">
 - LE External configuration
	<img src = "images/oled_c_le_external_controller.png">

	**Note :** : Other components' configurations will be default
- Change the width and height settings to 96 x 96 in GFX core LE block
 	<img src = "images/oled_c_gfx_core.png">
- Enable timer system service and core service as needed by the LE External Controller driver
	<img src = "images/timer_service.png">
	<img src = "images/core_service.png">  

	**Note :** Configuration for TIME System service, Harmony core service and TC0 remains default
- Design graphics using MPLAB Harmony "Legato Graphics Composer". Launch it using **"Project Graph > Plugins > Legato Graphics Composer"**
	<img src = "images/legato_config.png" align="middle">
- Use **Object Editor** to edit the configuration for **Input Widgets** and **Dispaly Widgets**
	<img src = "images/image_1.png">
-  You could use this demonstration as an example to add OLED C Click functionality to your MPLAB Harmony v3 based application. Follow the below steps.  
	**Note:** This demonstration uses a Text Field Input widget and an Image Display widget. Therefore the configurations in the **Legato Graphics Composer** (shown above) routines and examples (in oled_c.c and oled_c_example.c) are also based on these widgets. Users can configure and use other widgets and objects supported under **Legato Graphics Composer** by using this demonstration as a reference.

    1. If you haven't downloaded the OLED C Click demo yet [Click Here](https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/oled_c.zip) to download, otherwise go to next step
  
	2. Unzip the downloaded .zip file  
    
	3. From the unzipped folder oled_c/firmware/src, copy the folder **click_routines** to the folder firmware/src under your MPLAB Harmony v3 application project  
    
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

	- The OLED C lick header files gets added to your project  
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

	 - The OLED C Click source files gets added to your project  
		<img src = "images/source_add5.png">

- The **click_routines** folder contain an example C source file **oled_c_example.c**. You could use **oled_c_example.c** as a reference to add OLED C display functionality to your application.

## Comments:
- Reference Training Module:  
	1. [Getting Started with Harmony v3 Peripheral Libraries on SAM D5x/E5x MCUs](https://microchipdeveloper.com/harmony3:same54-getting-started-training-module)  
	2. [Low Power Application on SAM E54 (Arm® Cortex® M4) MCUs Using MPLAB® Harmony v3 Peripheral Libraries](https://microchipdeveloper.com/harmony3:low-power-application-on-sam-e54)
	3. [Getting Started with Harmony v3 Drivers on SAM E54 MCUs Using FreeRTOS](https://microchipdeveloper.com/harmony3:same54-getting-started-tm-drivers-freertos#Steps_anchor)
- This application demo builds and works out of box by following the instructions above in "Running the Demo" section. If you need to enhance/customize this application demo, you need to use the MPLAB Harmony v3 Software framework. Refer links below to setup and build your applications using MPLAB Harmony.
	- [How to Setup MPLAB Harmony v3 Software Development Framework](https://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Setup_MPLAB_%20Harmony_v3_Software_Development_Framework_DS90003232C.pdf)
	- [How to Build an Application by Adding a New PLIB, Driver, or Middleware to an Existing MPLAB Harmony v3 Project](http://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Build_Application_Adding_PLIB_%20Driver_or_Middleware%20_to_MPLAB_Harmony_v3Project_DS90003253A.pdf)  
	- <span style="color:blue"> **MPLAB Harmony v3 is also configurable through MPLAB Code Configurator (MCC). Refer to the below links for specific instructions to use MPLAB Harmony v3 with MCC.**</span>
		- [Create a new MPLAB Harmony v3 project using MCC](https://microchipdeveloper.com/harmony3:getting-started-training-module-using-mcc)
		- [Update and Configure an Existing MHC-based MPLAB Harmony v3 Project to MCC-based Project](https://microchipdeveloper.com/harmony3:update-and-configure-existing-mhc-proj-to-mcc-proj)
		- [Getting Started with MPLAB Harmony v3 Using MPLAB Code Configurator](https://www.youtube.com/watch?v=KdhltTWaDp0)
		- [MPLAB Code Configurator Content Manager for MPLAB Harmony v3 Projects](https://www.youtube.com/watch?v=PRewTzrI3iE)	

## Revision:
- v1.5.0 - Removed MHC support, regenerated and tested application.
- v1.4.0 - Released demo application
