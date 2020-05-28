---
title: Getting Started
grand_parent: Reference Applications
parent: PIC32MK General Purpose (GP) Development Board
nav_order: 1
---
<img src = "images/microchip_logo.png">
<img src = "images/microchip_mplab_harmony_logo_small.png">

# Getting Started Application on PIC32MK General Purpose (GP) Development Board
-----
## Description

>  The application reads the current room temperature from the temperature sensor on the MikroElectronika Weather click board.
	The temperature reading is displayed on a serial console periodically every 500 milliseconds. The periodicity of the temperature
	values displayed on the serial console is changed to one second, two seconds, four seconds, and back to 500 milliseconds every
	time you press the switch S1 on the PIC32MK GP Development Board. Also, an LED (LED1) is toggled every time the temperature is
	displayed on the serial console.

## Modules/Technology Used:

- Peripheral Modules      
	- SPI
	- Timer
	- Core Timer
	- GPIO
	- UART
	- DMA

## Hardware Used:

- [PIC32MK General Purpose (GP) Development Board](http://www.microchip.com/DevelopmentTools/ProductDetails.aspx?PartNO=DM320106)   
- [MikroElectronika Weather click board](https://www.mikroe.com/weather-click)


## Software/Tools Used:
<span style="color:blue"> *This project has been verified to work with the following versions of software tools:*</span>  

 - [MPLAB Harmony v3 "csp" repo v3.7.1](https://github.com/Microchip-MPLAB-Harmony/csp/releases/tag/v3.7.1)
 - [MPLAB Harmony v3 "dev_packs" repo v3.7.0](https://github.com/Microchip-MPLAB-Harmony/dev_packs/releases/tag/v3.7.0)
 - [MPLAB Harmony v3 "mhc" repo v3.4.0](https://github.com/Microchip-MPLAB-Harmony/mhc/releases/tag/v3.4.0)
 - MPLAB Harmony Configurator Plugin v3.5.0
 - [MPLAB X IDE v5.40](https://www.microchip.com/mplab/mplab-x-ide)
 - [MPLAB XC32 Compiler v2.41](https://www.microchip.com/mplab/compilers)
 - Any Serial Terminal application like Tera Term terminal application.

 <span style="color:blue"> *Because Microchip regularly update tools, occasionally issue(s) could be discovered while using the newer versions of the tools. If the project doesn’t seem to work and version incompatibility is suspected, It is recommended to double-check and use the same versions that the project was tested with.* </span>  

## Setup:  
- 	Connect the Type-A male to Micro-B USB cable to the Micro-B Serial USB port (J25) on the PIC32MK GP Development Board for logs
-Connect the Type-A male to Micro-B USB cable to Micro-B DEBUG USB port (J12) to power and debug the PIC32MK GP Development Board
- Connect the MikroElectronika Weather click board on the mikroBUS interface J29. Ensure the
  following hardware modification before connecting the Weather click board  
  <img src = "images/hardware_setup.jpg" width="525" height="590" align="middle">  

### Hardware Modification:  

- The MikroElectronika Weather click board supports both I²C and SPI protocols to communicate with the BME280 temperature sensor.
	  It provides jumpers (resistors) to choose a communication interface between I²C and SPI. By default, I²C is selected as the
	  communication interface. The PIC32MK1024GPE100 device does not have an I²C peripheral module; therefore, SPI is
	  chosen as the communication interface to communicate with the temperature sensor
	  The hardware modification to be done on the MikroElectronika Weather click board is shown in the figure below
    <img src = "images/hardware_modification.png" width="290" height="290" align="middle">		  

## Programming hex file:
The pre-built hex file can be programmed by following the below steps

### Steps to program the hex file
- Open MPLAB X IDE
- Close all existing projects in IDE, if any project is opened.
- Go to File -> Import -> Hex/ELF File
- In the "Import Image File" window, Step 1 - Create Prebuilt Project, click the "Browse" button to select the prebuilt hex file.
- Select Device has "PIC32MK1024GPE100"
- Ensure the proper tool is selected under "Hardware Tool"
- Click on "Next" button
- In the "Import Image File" window, Step 2 - Select Project Name and Folder, select appropriate project name and folder
- Click on "Finish" button
- In MPLAB X IDE, click on "Make and Program Device" Button. The device gets programmed in sometime.
- Follow the steps in "Running the Demo" section below

## Programming/Debugging Application Project:
- Open the project (pic32mk_getting_started\firmware\pic32mk_gp_db.X) in MPLAB X IDE
- Ensure "PKOB4" is selected as hardware tool to program/debug the application
- Build the code and program the device by clicking on the "make and program" button in MPLAB X IDE tool bar
- Follow the steps in "Running the Demo" section below

## Running the Demo:
- Open the Tera Term terminal application on your PC (from the Windows® Start menu by pressing the Start button)
- Change the baud rate to 115200
- You should see the temperature values (in °F) being displayed on the terminal every 500 milliseconds, as shown below  
<img src = "images/result1.png" width="425" height="235" align="middle">  
- Also, notice LED1 blinking at a 500 millisecond rate
- You may vary the temperature by placing your finger on the temperature sensor (for a few seconds)  
<img src = "images/temp_sensor_placement.png" width="525" height="590" align="middle">  
- Press the S1 switch on the PIC32MK General Purpose (GP) Development Board to change the default sampling rate to one second
<img src = "images/user_button_placement.png" width="525" height="590" align="middle">  
<img src = "images/result2.png" width="345" height="165" align="middle">  
- Every subsequent press of switch S1 on the PIC32MK General Purpose (GP) Development Board changes the default sampling rate to two seconds, four seconds, 500 milliseconds and back to one second in cyclic order as shown below  
<img src = "images/result3.png" width="315" height="440" align="middle">  

- While the temperature sampling rate changes on every switch S1 press, notice LED1 toggling at the same sampling rate

## Comments:
- Reference Training Module: [Getting Started with Harmony v3 Peripheral Libraries on PIC32MK GP MCUs](https://microchipdeveloper.com/harmony3:pic32mk-gp-db-getting-started-training-module)
- This application demo builds and works out of box by following the instructions above in "Running the Demo" section. If you need to enhance/customize this application demo, you need to use the MPLAB Harmony v3 Software framework. Refer links below to setup and build your applications using MPLAB Harmony.
	- [How to Setup MPLAB Harmony v3 Software Development Framework](https://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en1000821)
	- [How to Build an Application by Adding a New PLIB, Driver, or Middleware to an Existing MPLAB Harmony v3 Project](http://ww1.microchip.com/downloads/en/DeviceDoc/How_to_Build_Application_Adding_PLIB_%20Driver_or_Middleware%20_to_MPLAB_Harmony_v3Project_DS90003253A.pdf)

## Revision:
- v1.0 released demo application
