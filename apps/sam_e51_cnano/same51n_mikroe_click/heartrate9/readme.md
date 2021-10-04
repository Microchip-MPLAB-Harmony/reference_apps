---
grand_parent: Reference Applications
parent: SAM E51 Curiosity Nano Evaluation Kit
title: Heart Rate 9 Click Example
nav_order: 8
---

<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

# Heart Rate 9 Click example on SAM E51 Curiosity Nano Evaluation Kit
<h2 align="center"> <a href="https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/heartrate9.zip" > Download </a> </h2>

-----
## Description:

> This example demonstrates the reading of Heart Rate and displays it on a serial terminal on SAM E51 Curiosity Nano Evaluation Kit using Heart Rate 9 Click board.

## Modules/Technology Used:
- Peripheral Modules
	- EIC
	- SYSTICK
	- GPIO
	- SERCOM (USART)

## Hardware Used:

- [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)
- [Curiosity Nano Base for Click Boards](https://www.microchip.com/Developmenttools/ProductDetails/AC164162)
- [MikroElektronika Heart Rate 9 Click](https://www.mikroe.com/heart-rate-9-click)

## Software/Tools Used:
<span style="color:blue"> This project has been verified to work with the following versions of software tools:</span>  

Refer [Project Manifest](./firmware/src/config/sam_e51_cnano/harmony-manifest-success.yml) present in harmony-manifest-success.yml under the project folder *firmware/src/config/sam_e51_cnano*  
- Refer the [Release Notes](../../../../release_notes.md#development-tools) to know the **MPLAB X IDE** and **MHC/MCC** Plugin version.  
- Any Serial Terminal application like Tera Term terminal application.

<span style="color:blue"> Because Microchip regularly update tools, occasionally issue(s) could be discovered while using the newer versions of the tools. If the project doesn’t seem to work and version incompatibility is suspected, It is recommended to double-check and use the same versions that the project was tested with. </span> To download original version of MPLAB Harmony v3 packages, refer to document [How to Use the MPLAB Harmony v3 Project Manifest Feature](https://microchip.com/DS90003305)

## Setup:
- Connect the SAM E51 Curiosity Nano Evaluation Kit to the Host PC as a USB Device through a Type-A male to micro-B USB cable connected to Micro-B USB (Debug USB) port

  <img src = "images/heartrate9_click_demo_setup.png" width="650" height="475" align="middle">

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
- Open the project (sam_e51_cnano/same51n_mikroe_click/heartrate9/firmware/sam_e51_cnano.X) in MPLAB X IDE
- Ensure "PKOB nano" is selected as hardware tool to program/debug the application
- Build the code and program the device by clicking on the "make and program" button in MPLAB X IDE tool bar
- Follow the steps in "Running the Demo" section below

## Running the Demo:
- Open the Tera Term terminal application on your PC (from the Windows® Start menu by pressing the Start button)
- Set the baud rate to 115200
- Keep your finger on Pulse Detection Indicator as shown here.

	<img src = "images/proper_finger_placement.png" width="550" height="320" align="middle">  
	<img src = "images/wrong_way_finger_placement.png" width="550" height="320" align="middle">

	*Note*: Cover the Heart Rate Sensor by placing your finger on Pulse Detection Indicator as shown below  
	<img src = "images/oximeter_heart_rate_sensor.png" width="350" height="350" align="center">
- Now, press the switch SW0 on the SAM E51 Curiosity Nano Evaluation Kit to print the Heart Rate.  
	<img src = "images/heartrate9_click_run.png" width="660" height="340" align="middle">
- For every switch press, the SAM E51 Curiosity Nano Evaluation Kit prints the Heart Rate.  

## Instructions to add Heart Rate functionality to your application:

You could use this demonstration as an example to add Heart Rate functionality to your MPLAB Harmony v3 based application. Follow the below steps.  
1. If you haven't downloaded the Heart Rate 9 demo yet [Click Here](https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/heartrate9.zip) to download, otherwise go to next step
2. Unzip the downloaded .zip file  
3. From the unzipped folder heartrate9/firmware/src, copy the folder **click_routines** to the folder firmware/src under your MPLAB Harmony v3 application project  
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

- The Heart Rate 9 click example header files gets added to your project  
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

 - The Heart Rate 9 click example source files gets added to your project  
 	<img src = "images/source_add5.png">

8. The Heart Rate 9 click example uses the **USART** and **Timer** peripherals. The configuration of these peripherals for your application depends on the 32-bit MCU and development board you are using.

	- **Configure USART**:
 		- Add the USART peripheral block to the MHC project graph  
		- Configure USART Pins using MHC Pin configuration Window  
		The USART configuration depends on
 			- 32-bit MCU
 			- 32-bit MCU development board
 			- The socket on which you have mounted the Heart Rate 9 click board  
 		*Example: The Heart Rate 9 click example on SAM E51 Curiosity Nano Evaluation Kit uses mikroBUS socket #1 on the Curiosity Nano Base for Click boards to mount the Heart Rate 9 click board. The USART lines from MCU coming to this socket are from the SERCOM4 peripheral on the MCU.*  
		*MHC Project Graph - USART configuration*  
		<img src = "images/usart_config.png">  

		*MHC Pin Configurator - USART pin configuration*  
		<img src = "images/usart_pins.png">  

	- **Configure Heart Rate 9 Click Reset Pin**:
 		- Configure Heart Rate 9 Click Reset Pin using MHC Pin configuration Window  
		The Reset Pin configuration depends on
 			- The socket on which you have mounted the Heart Rate 9 click board  
 		*Example: The Heart Rate 9 click example on SAM E51 Curiosity Nano Evaluation Kit uses mikroBUS socket #1 on the Curiosity Nano Base for Click boards to mount the Heart Rate 9 click board. The Reset Pin line from the Heart Rate 9 Click coming to this socket is PA07 on the MCU.*  
		*MHC Pin Configurator - Reset pin configuration*  
		<img src = "images/heartrate9_click_reset_pin.png">  

	- **Configure Timer**:
		- Configure Timer peripheral block in the MHC project graph  
		The Timer configuration depends on
 			- 32-bit MCU  
		*Example: The Heart Rate 9 click example on SAM E51 Curiosity Nano Evaluation Kit uses SysTick timer module on the MCU to implement the time requirement of Heart Rate 9 click routines.*  
		*MHC Project Graph - SysTick configuration*  
		<img src = "images/systick_configure.png">  

	- **Map Generic Macros**:
		- After generating the project, following the above configuration, map the generic macros used in the click routines to the Harmony PLIB APIs of the 32-bit MCU your project is running on
		- The generic macros should be mapped in the header file click_interface.h  

			<img src = "images/click_inter.png">  			
		*Example: The Heart Rate 9 click routines for the example on SAM E51 Curiosity Nano Evaluation Kit uses the following Harmony PLIB APIs*  			
		<img src = "images/map_click.png">

		**Note:** Define the value of **CLICK_HEARTRATE9_USART_READ_BUFFER_SIZE** same as **USART_READ_BUFFER_SIZE** defined in the respective USART PLIB '.c' file

9. The **click_routines** folder contain an example C source file **heartrate9_example.c**. You could use **heartrate9_example.c** as a reference to add Heart Rate 9 functionality to your application.

## Comments:
- Reference Training Module:  
	1. [Getting Started with Harmony v3 Peripheral Libraries on SAM D5x/E5x MCUs](https://microchipdeveloper.com/harmony3:same54-getting-started-training-module)  
	2. [Low Power Application on SAM E54 (Arm® Cortex® M4) MCUs Using MPLAB® Harmony v3 Peripheral Libraries](https://microchipdeveloper.com/harmony3:low-power-application-on-sam-e54)
	3. [Getting Started with Harmony v3 Drivers on SAM E54 MCUs Using FreeRTOS](https://microchipdeveloper.com/harmony3:same54-getting-started-tm-drivers-freertos#Steps_anchor)
- This application demo builds and works out of box by following the instructions above in "Running the Demo" section. If you need to enhance/customize this application demo, you need to use the MPLAB Harmony v3 Software framework. Refer links below to setup and build your applications using MPLAB Harmony.
	- [How to Setup MPLAB Harmony v3 Software Development Framework](https://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en1000821)
	- [How to Build an Application by Adding a New PLIB, Driver, or Middleware to an Existing MPLAB Harmony v3 Project](http://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Build_Application_Adding_PLIB_%20Driver_or_Middleware%20_to_MPLAB_Harmony_v3Project_DS90003253A.pdf)  

## Revision:
- v1.3.0 - Released demo application
