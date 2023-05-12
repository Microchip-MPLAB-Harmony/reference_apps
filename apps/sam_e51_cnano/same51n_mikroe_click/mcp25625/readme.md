---
grand_parent: 32-bit MCU Reference Applications
parent: SAM E51 Curiosity Nano Evaluation Kit
title: MCP25625 Click Example
nav_order: 20
---

<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

# MCP25625 Click example on SAM E51 Curiosity Nano Evaluation Kit
<h2 align="center"> <a href="https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/mcp25625.zip" > Download </a> </h2>

-----
## Description:

> This example demonstrates the transmitting and receiving of CAN data using the MCP25625 CAN click board and displays the transmit/receive CAN message on a serial terminal on SAM E51 Curiosity Nano Evaluation Kit using the MCP25625 Click board.

## Modules/Technology Used:
- Peripheral Modules
	- PORT
	- SERCOM (SPI)
	- SYSTICK

## Hardware Used:

- [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A) - **2 Units**
- [Curiosity Nano Base for Click Boards](https://www.microchip.com/Developmenttools/ProductDetails/AC164162) - **2 Units**
- [MikroElektronika MCP25625 Click](https://www.mikroe.com/mcp25625-click) - **2 Units**
 **Note:** One of the two hardware setups is required for the CAN message transmission (**Setup-1**) and the other for reception(**Setup-2**). Parallelly both the setups demonstrate CAN data transmission and reception.

## Software/Tools Used:
<span style="color:blue"> This project has been verified to work with the following versions of software tools:</span>

Refer [Project Manifest](./firmware/src/config/sam_e51_cnano/harmony-manifest-success.yml) present in harmony-manifest-success.yml under the project folder *firmware/src/config/sam_e51_cnano*
- Refer the [Release Notes](../../../../release_notes.md#development-tools) to know the **MPLAB X IDE** and **MCC** Plugin version. Alternatively, [Click Here](https://github.com/Microchip-MPLAB-Harmony/reference_apps/blob/master/release_notes.md#development-tools).

<span style="color:blue"> Because Microchip regularly update tools, occasionally issue(s) could be discovered while using the newer versions of the tools. If the project doesn’t seem to work and version incompatibility is suspected, It is recommended to double-check and use the same versions that the project was tested with. </span> To download the original version of MPLAB Harmony v3 packages, refer to the document [How to Use the MPLAB Harmony v3 Project Manifest Feature](https://ww1.microchip.com/downloads/en/DeviceDoc/How-to-Use-the-MPLAB-Harmony-v3-Project-Manifest-Feature-DS90003305.pdf)

## Setup:
- Connect the [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A) to the Host PC as a USB Device through a Type-A male to micro-B USB cable connected to Micro-B USB (Debug USB) port
- Mount [MikroElektronika MCP25625 Click](https://www.mikroe.com/mcp25625-click) over mikroBUS socket #1 on the [SAM E51 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV76S68A) (**Setup-1**).
- Repeat the above  steps with the other hardware units (**Setup-2**).
- Short the CANH and CANL lines of one DB9 connector with the CANH and CANL line of another DB9 connector using jumper wires as shown below image.
  - CANH - Pin 7 of the DB9 connector
  - CANL - Pin 2 of the DB9 connector

  <img src = "images/mcp25625_click_demo_setup.png" align="middle">

### <a name="ProgrammingHexFile"></a>
## Programming hex file:
The pre-built hex file can be programmed by following the below steps.  

### Steps to program the hex file
- Open MPLAB X IDE
- Close all existing projects in IDE, if any project is opened.
- Go to File -> Import -> Hex/ELF File
- In the "Import Image File" window, Step 1 - Create Prebuilt Project, Click the "Browse" button to select the prebuilt hex file.
- Select Device has "ATSAME51J20A"
- Ensure the proper tool is selected under "Hardware Tool"
- Click on the Next button
- In the "Import Image File" window, Step 2 - Select Project Name and Folder, select the appropriate project name and folder
- Click on the Finish button
- In MPLAB X IDE, click on the "Make and Program Device" button. The device gets programmed in sometime
- Follow the steps in the "Running the Demo" section below


### <a name="Programming_DebuggingApplicationProject"></a>
## Programming/Debugging Application Project:
- Open the project (apps/sam_e51_cnano/same51n_mikroe_click/mcp25625/firmware/sam_e51_cnano.X) in MPLAB X IDE
- Ensure "SAM E51 Curiosity Nano Evaluation Kit" is selected as hardware tool to program/debug the application
- Build the code and program the device by clicking on the "make and program" button in MPLAB X IDE tool bar
- Follow the steps in "Running the Demo" section below

 **Note:** Repeat the above [Setup](#Setup), [Programming Hex File](#ProgrammingHexFile), [Programming/Debugging Application Project](#Programming_DebuggingApplicationProject) on the second hardware setup (**Setup-2**).

## Running the Demo:
- Open the Tera Term terminal application on your PC (from the Windows® Start menu by pressing the Start button)
- Set the baud rate to 115200
- Repeat the above two steps for the second hardware setup (**Setup-2**).
	 <img src = "images/output_screen1.png">  
- Enter a character **'a'** on one Tera terminal application to initiate the CAN Message Transmit.
- Also, enter a character **'b'** on another Tera terminal application to wait for the CAN Message Receive.
	 <img src = "images/output_screen2.png">  
- Now, in both the Tera terminal windows, you will see the CAN message transmission and reception continuously.

## Instructions to add MCP25625 functionality to your application:

You could use this demonstration as an example to add MCP25625 functionality to your MPLAB Harmony v3-based application. Follow the below steps.  
1. If you haven't downloaded the MCP25625 demo yet [Click Here](https://github.com/Microchip-MPLAB-Harmony/reference_apps/releases/latest/download/mcp25625.zip) to download, otherwise go to the next step
2. Unzip the downloaded .zip file  
3. From the unzipped folder mcp25625/firmware/src, copy the folder **click_routines** to the folder firmware/src under your MPLAB Harmony v3 application project  
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

- The MCP25625 click example header files gets added to your project  
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

 - The MCP25625 click example source files gets added to your project  
 	<img src = "images/source_add5.png">

8. The MCP25625 click example uses the **SPI** peripheral. The configuration of this peripheral for your application depends on the 32-bit MCU and development board you are using.

	- **Configure SPI**:
 		- Add the SPI peripheral block to the MCC project graph  
		- Configure SPI Pins using MCC Pin configuration Window  
		The SPI configuration depends on
 			- 32-bit MCU
 			- 32-bit MCU development board
 			- The socket on which you have mounted the MCP25625 click board  
 		*Example: The MCP25625 click example on SAM E51 Curiosity Nano Evaluation Kit uses mikroBUS socket #1 on the Curiosity Nano Base for Click boards to mount the MCP25625 click board. The SPI lines from MCU coming to this socket are from the SERCOM1 peripheral on the MCU.*  
		*MCC Project Graph - SPI configuration*  
		<img src = "images/spi_config.png">  

		*MCC Pin Configurator - SPI pin configuration*  
		<img src = "images/spi_pins.png">  

	- **Configure PORT Pins**:
		- The MCP25625 click needs three additional pins for configuration and data exchange. These parent
			- Standby pin
			- Reset pin		
		- Configure PORT pins needed by MCP25625 click in the MCC Pin Configurator  
		The PORT pin configuration depends on
			- 32-bit MCU
			- 32-bit MCU development board
			- The socket on which you have mounted the MCP25625 click board   
		*Example: The PORT pin configuration for the MCP25625 click example on SAM E51 Curiosity Nano Evaluation Kit is below.*  
		*MCC Pin Configurator - PORT pin configuration*  
		<img src = "images/port_pins_configure.png">  

	- **Map Generic Macros**:
		- After generating the project, following the above configuration, map the generic macros used in the click routines to the Harmony PLIB APIs of the 32-bit MCU your project is running on
		- The generic macros should be mapped in the header file click_interface.h  

			<img src = "images/click_inter.png">  			
		*Example: The MCP25625 click routines for the example on SAM E51 Curiosity Nano Evaluation Kit uses the following Harmony PLIB APIs*  			
		<img src = "images/map_click.png">

9. The **click_routines** folder contain an example C source file **mcp25625_example.c**. You could use **mcp25625_example.c** as a reference to add MCP25625 functionality to your application.

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
- v1.6.0 - Released demo application
