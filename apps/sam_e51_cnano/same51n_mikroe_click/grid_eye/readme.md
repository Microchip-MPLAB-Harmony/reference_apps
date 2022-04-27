---
grand_parent: Reference Applications
parent: SAM E51 Curiosity Nano Evaluation Kit
title: GRID EYE Click Example
nav_order: 19
---

<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

# GRID EYE Click example on SAM E51 Curiosity Nano Evaluation Kit
<h2 align="center"> <a href="https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/grid_eye.zip" > Download </a> </h2>

-----
## Description:

> The application senses the absolute surface temperature without any contact or can be used to detect the movement of people and objects, renders it in real-time, and prints the decoded colors on a serial terminal on PC in an 8x8 heat map matrix. The sensor detecting distance is 5m, and the viewing angle is 60 degrees.

> The application has two major tasks: acquiring and processing the data from the Grid-EYE click and printing the frame of colors based on the temperature values measured at the previous task.


## Modules/Technology Used:
- Peripheral Modules
	- SYSTICK
	- GPIO
	- SERCOM (USART)
	- SERCOM (I2C)

## Hardware Used:

- [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A)
- [Curiosity Nano Base for Click Boards](https://www.microchip.com/Developmenttools/ProductDetails/AC164162)
- [MikroElektronika GRID-EYE Click](https://www.mikroe.com/grid-eye-click)

## Software/Tools Used:
<span style="color:blue"> This project has been verified to work with the following versions of software tools:</span>  

Refer [Project Manifest](./firmware/src/config/sam_e51_cnano/harmony-manifest-success.yml) present in harmony-manifest-success.yml under the project folder *firmware/src/config/sam_e51_cnano*  
- Refer the [Release Notes](../../../../release_notes.md#development-tools) to know the **MPLAB X IDE** and **MHC/MCC** Plugin version. Alternatively, [Click Here](https://github.com/Microchip-MPLAB-Harmony/reference_apps/blob/master/release_notes.md#development-tools).
- Any Serial Terminal application like Tera Term terminal application.

<span style="color:blue"> Because Microchip regularly update tools, occasionally issue(s) could be discovered while using the newer versions of the tools. If the project doesn’t seem to work and version incompatibility is suspected, It is recommended to double-check and use the same versions that the project was tested with. </span> To download original version of MPLAB Harmony v3 packages, refer to document [How to Use the MPLAB Harmony v3 Project Manifest Feature](https://ww1.microchip.com/downloads/en/DeviceDoc/How-to-Use-the-MPLAB-Harmony-v3-Project-Manifest-Feature-DS90003305.pdf)

## Setup:
- Mount [GRID-EYE Click](https://www.mikroe.com/grid-eye-click) to mikroBUS connector 1 of the [Curiosity Nano Base for Click Board](https://www.microchip.com/Developmenttools/ProductDetails/AC164162).
- Connect the SAM E51 Curiosity Nano Evaluation Kit to the Host PC as a USB Device through a Type-A male to micro-B USB cable connected to Micro-B USB (Debug USB) port

  <img src = "images/grid_eye_click_demo_setup.png" width="750" height="562" align="middle">

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
- Open the project (sam_e51_cnano/same51n_mikroe_click/grid_eye/firmware/sam_e51_cnano.X) in MPLAB X IDE
- Ensure "SAM E51 Curiosity Nano" is selected as hardware tool to program/debug the application
- Build the code and program the device by clicking on the "Make and Program Device" button in MPLAB X IDE tool bar
- Follow the steps in "Running the Demo" section below

## Running the Demo:
- Open the Tera Term terminal application on your PC (from the Windows® Start menu by pressing the Start button)
- Set the baud rate to 115200
- The application starts printing the GRID-EYE values on the terminal for every 500 milliseconds. The code converts the grid array sensor data to temperature in Celsius(°C) and fills the 8x8 grid array matrix by the appropriate color, depending on the temperature detected.
- The GRID-EYE values changes when an object or a hand is moved over the sensor or  when touching the fingure on the sensor. The following table shows the Color representation based on the temperature(T) range.

    | Color Code                   | Color Name             | Temperature Range     |
    | ---------------------------- | ---------------------- | --------------------- |
    | <center> R                   | <center> Red           | <center> Above 30°C   |
    | <center> O                   | <center> Orange        | <center> 28°C - 30°C  |
    | <center> Y                   | <center> Yellow        | <center> 26°C - 28°C  |
    | <center> y                   | <center> Light Yellow  | <center> 24°C - 26°C  |
    | <center> G                   | <center> Green         | <center> 22°C - 24°C  |
    | <center> <code>&#124</code>  | <center> No Color      | <center> Bellow 22°C  |

- See the following image for the output.
    <img src = "images/grid_eye_running.png">


## Instructions to add GRID EYE functionality to your application:

You could use this demonstration as an example to add GRID EYE functionality to your MPLAB Harmony v3 based application. Follow the below steps.  
1. If you haven't downloaded the GRID EYE demo yet [Click Here](https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/grid_eye.zip) to download, otherwise go to next step
2. Unzip the downloaded .zip file  
3. From the unzipped folder grid_eye/firmware/src, copy the folder **click_routines** to the folder firmware/src under your MPLAB Harmony v3 application project  
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

- The GRID EYE click example header files gets added to your project  
	<img src = "images/click_inter.png">

7. In the project explorer, Right click on folder **Source Files**  
   and add a sub folder **click_routines** by selecting "Add Existing Items from Folders..."   
	 <img src = "images/source_add.png">  

 - Click on "Add Folder..." button  
 	<img src = "images/source_add2.png">  

 - Select the "click_routines" folder and select "Files of Types" as Source Files  
 	<img src = "images/source_add3.png">

 - Click on "Add" button to add the selected folder  
 	<img src = "images/source_add4.png">

 - The GRID EYE click example source files gets added to your project  
 	<img src = "images/click_routines.png">

8. The GRID EYE click example uses the **I2C** and  **Timer** peripherals. The configuration of these peripherals for your application depends on the 32-bit MCU and development board you are using.
	- **Configure I2C**:
 		- Add the I2C peripheral block to the MHC project graph  
		- Configure I2C Pins using MHC Pin configuration Window  
		The I2C configuration depends on
 			- 32-bit MCU
 			- 32-bit MCU development board
 			- The socket on which you have mounted the GRID EYE click board  
 		*Example: The GRID EYE click example on SAM E51 Curiosity Nano Evaluation Kit uses mikroBUS socket #1 on the Curiosity Nano Base for Click boards to mount the GRID EYE click board. The I2C lines from MCU coming to this socket are from the SERCOM2 peripheral on the MCU.*  
		*MHC Project Graph - I2C configuration*  
		<img src = "images/grid_eye_i2c_config.png" >

		*MHC Pin Configurator - I2C pin configuration*  
		<img src = "images/grid_eye_i2c_pins_config.png">

	- **Configure Timer**:
		- Configure Timer peripheral block in the MHC project graph  
		The Timer configuration depends on
 			- 32-bit MCU  
		*Example: The GRID EYE click example on SAM E51 Curiosity Nano Evaluation Kit uses SysTick timer module on the MCU to implement the time requirement of GRID EYE click routines.*  
		*MHC Project Graph - SysTick configuration*  
		<img src = "images/grid_eye_systick_configure.png" width="528" height="333" align="middle">  

	- **Map Generic Macros**:
		- After generating the project, following the above configuration, map the generic macros used in the click routines to the Harmony PLIB APIs of the 32-bit MCU your project is running on
		- The generic macros should be mapped in the header file click_interface.h  

			<img src = "images/click_inter.png">  			
		*Example: The GRID EYE click routines for the example on SAM E51 Curiosity Nano Evaluation Kit uses the following Harmony PLIB APIs*  			
		<img src = "images/map_click.png">

9. The **click_routines** folder contain an example C source file **grid_eye_example.c**. You could use **grid_eye_example.c** as a reference to add GRID EYE functionality to your application.

## Comments:
- Reference Training Module:  
	1. [Getting Started with Harmony v3 Peripheral Libraries on SAM D5x/E5x MCUs](https://microchipdeveloper.com/harmony3:same54-getting-started-training-module)
	2. [Low Power Application on SAM E54 (Arm® Cortex® M4) MCUs Using MPLAB® Harmony v3 Peripheral Libraries](https://microchipdeveloper.com/harmony3:low-power-application-on-sam-e54)
	3. [Getting Started with Harmony v3 Drivers on SAM E54 MCUs Using FreeRTOS](https://microchipdeveloper.com/harmony3:same54-getting-started-tm-drivers-freertos)

- This application demo builds and works out of box by following the instructions above in "Running the Demo" section. If you need to enhance/customize this application demo, you need to use the MPLAB Harmony v3 Software framework. Refer links below to setup and build your applications using MPLAB Harmony.
	- [How to Setup MPLAB Harmony v3 Software Development Framework](https://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en1000821)
	- [How to Build an Application by Adding a New PLIB, Driver, or Middleware to an Existing MPLAB Harmony v3 Project](http://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Build_Application_Adding_PLIB_%20Driver_or_Middleware%20_to_MPLAB_Harmony_v3Project_DS90003253A.pdf)

## Revision:
- v1.5.0 - Created application example
